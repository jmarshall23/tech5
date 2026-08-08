
// ========================================================================
// ?SetPusher@idPhysics_ParametricMM@@QAAXPAVidPush@@H@Z
// EA  : 0x82748870
// RVA : 0x00748870
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetPusher(idPhysics_ParametricMM *this, idPush *push, int flags)
{
  this->pusher = push;
  this->pushFlags = flags;
  this->isPusher = true;
}


// ========================================================================
// ?GetSpline@idPhysics_ParametricMM@@QBAPAV?$idCurve_Spline@VidVec3@@@@XZ
// EA  : 0x82748888
// RVA : 0x00748888
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idCurve_Spline<idVec3> *__fastcall idPhysics_ParametricMM::GetSpline(idPhysics_ParametricMM *this)
{
  return this->current.spline;
}


// ========================================================================
// ?SetUseSplineAngles@idPhysics_ParametricMM@@QAAX_N@Z
// EA  : 0x82748890
// RVA : 0x00748890
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetUseSplineAngles(idPhysics_ParametricMM *this, bool newUseSplineAngles)
{
  this->current.useSplineAngles = newUseSplineAngles;
}


// ========================================================================
// ?GetNumClipModels@idPhysics_ParametricMM@@UBAHXZ
// EA  : 0x82748898
// RVA : 0x00748898
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

BOOL __fastcall idPhysics_ParametricMM::GetNumClipModels(idPhysics_ParametricMM *this)
{
  return this->clipModel != nullptr;
}


// ========================================================================
// ?SetContents@idPhysics_ParametricMM@@UAAXHH@Z
// EA  : 0x827488A8
// RVA : 0x007488A8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetContents(idPhysics_ParametricMM *this, int contents, int id)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::SetContents(this: clipModel, newContents: contents);
}


// ========================================================================
// ?Activate@idPhysics_ParametricMM@@UAAXXZ
// EA  : 0x827488C0
// RVA : 0x007488C0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::Activate(idPhysics_ParametricMM *this)
{
  this->current.atRest = -1;
}


// ========================================================================
// ?PutToRest@idPhysics_ParametricMM@@UAAXXZ
// EA  : 0x827488D0
// RVA : 0x007488D0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::PutToRest(idPhysics_ParametricMM *this)
{
  this->current.atRest = 1;
}


// ========================================================================
// ?IsAtRest@idPhysics_ParametricMM@@UBA_NXZ
// EA  : 0x827488E0
// RVA : 0x007488E0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

BOOL __fastcall idPhysics_ParametricMM::IsAtRest(idPhysics_ParametricMM *this)
{
  return this->current.atRest >= 0;
}


// ========================================================================
// ?GetGravityAxis@idPhysics_Actor@@UBAABVidMat3@@XZ
// EA  : 0x827488F0
// RVA : 0x007488F0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_Actor::GetGravityAxis(idPhysics_Actor *this)
{
  return &this->clipModelAxis;
}


// ========================================================================
// ?GetAxis@idPhysics_ParametricMM@@UBAABVidMat3@@H@Z
// EA  : 0x827488F8
// RVA : 0x007488F8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_ParametricMM::GetAxis(idPhysics_ParametricMM *this, int id)
{
  return &this->current.worldAxis;
}


// ========================================================================
// ?GetLinearVelocity@idPhysics_ParametricMM@@UBA?AVidVec3@@H@Z
// EA  : 0x82748900
// RVA : 0x00748900
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idPhysics_ParametricMM *__fastcall idPhysics_ParametricMM::GetLinearVelocity(
        idPhysics_ParametricMM *this,
        idVec3 *result,
        int id)
{
  float z; // r10
  float x; // r9

  z = result[31].z;
  x = result[32].x;
  this->__vftable = (idPhysics_ParametricMM_vtbl *)LODWORD(result[31].y);
  *((float *)&this->__vftable + 1) = z;
  *(float *)&this->type = x;
  return this;
}


// ========================================================================
// ?GetAngularVelocity@idPhysics_ParametricMM@@UBA?AVidVec3@@H@Z
// EA  : 0x82748920
// RVA : 0x00748920
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idPhysics_ParametricMM *__fastcall idPhysics_ParametricMM::GetAngularVelocity(
        idPhysics_ParametricMM *this,
        idVec3 *result,
        int id)
{
  float z; // r10
  float x; // r9

  z = result[32].z;
  x = result[33].x;
  this->__vftable = (idPhysics_ParametricMM_vtbl *)LODWORD(result[32].y);
  *((float *)&this->__vftable + 1) = z;
  *(float *)&this->type = x;
  return this;
}


// ========================================================================
// ?UnlinkClip@idPhysics_ParametricMM@@UAAXXZ
// EA  : 0x82748940
// RVA : 0x00748940
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::UnlinkClip(idPhysics_ParametricMM *this)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Unlink(this: clipModel);
}


// ========================================================================
// ?PauseParametricUntil@idPhysics_ParametricMM@@QAAXH@Z
// EA  : 0x82748958
// RVA : 0x00748958
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::PauseParametricUntil(idPhysics_ParametricMM *this, int resumeTime)
{
  idPhysics_ParametricMM_vtbl *v2; // r11

  v2 = this->__vftable;
  this->current.pauseTime = resumeTime;
  ((void (*)(void))v2->UpdateTime)();
}


// ========================================================================
// ??1idPhysics_Parametric@@UAA@XZ
// EA  : 0x82748978
// RVA : 0x00748978
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::~idPhysics_Parametric(idPhysics_Parametric *this)
{
  idClipModel *clipModel; // r3
  idCurve_Spline<idVec3> *spline; // r3
  idCurve_Spline<idAngles> *angularSpline; // r3

  this->__vftable = (idPhysics_Parametric_vtbl *)&idPhysics_Parametric::`vftable';
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    idClipModel::Delete(this: clipModel);
    this->clipModel = nullptr;
  }
  spline = this->current.spline;
  if ( spline != nullptr )
  {
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))spline->dtr_idCurve<idVec3>)(a1: spline, a2: 1);
    this->current.spline = nullptr;
  }
  angularSpline = this->current.angularSpline;
  if ( angularSpline != nullptr )
  {
    ((void (__fastcall *)(idCurve_Spline<idAngles> *, int))angularSpline->dtr_idCurve<idAngles>)(
      a1: angularSpline,
      a2: 1);
    this->current.angularSpline = nullptr;
  }
  idPhysics_DynamicBase::~idPhysics_DynamicBase(this);
}


// ========================================================================
// __unwind$251005
// EA  : 0x82748A14
// RVA : 0x00748A14
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void _unwind_251005()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 128 + 148));
}


// ========================================================================
// ?SetPusher@idPhysics_Parametric@@QAAXPAVidPush@@H@Z
// EA  : 0x82748A40
// RVA : 0x00748A40
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetPusher(idPhysics_Parametric *this, idPush *push, int flags)
{
  this->pusher = push;
  this->pushFlags = flags;
  this->isPusher = true;
}


// ========================================================================
// ?IsPusher@idPhysics_Parametric@@QBA_NXZ
// EA  : 0x82748A58
// RVA : 0x00748A58
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

BOOL __fastcall idPhysics_Parametric::IsPusher(idPhysics_Parametric *this)
{
  return this->isPusher;
}


// ========================================================================
// ?GetSpline@idPhysics_Parametric@@QBAPAV?$idCurve_Spline@VidVec3@@@@XZ
// EA  : 0x82748A60
// RVA : 0x00748A60
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idCurve_Spline<idVec3> *__fastcall idPhysics_Parametric::GetSpline(idPhysics_Parametric *this)
{
  return this->current.spline;
}


// ========================================================================
// ?GetLocalOrigin@idPhysics_Parametric@@QBAABVidVec3@@XZ
// EA  : 0x82748A68
// RVA : 0x00748A68
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

const idVec3 *__fastcall idPhysics_Parametric::GetLocalOrigin(idPhysics_Parametric *this)
{
  return &this->current.localOrigin;
}


// ========================================================================
// ?GetLocalAngles@idPhysics_Parametric@@QBAABVidAngles@@XZ
// EA  : 0x82748A70
// RVA : 0x00748A70
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

const idAngles *__fastcall idPhysics_Parametric::GetLocalAngles(idPhysics_Parametric *this)
{
  return &this->current.localAngles;
}


// ========================================================================
// ?GetNumClipModels@idPhysics_Parametric@@UBAHXZ
// EA  : 0x82748A78
// RVA : 0x00748A78
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

BOOL __fastcall idPhysics_Parametric::GetNumClipModels(idPhysics_Parametric *this)
{
  return this->clipModel != nullptr;
}


// ========================================================================
// ?SetContents@idPhysics_Parametric@@UAAXHH@Z
// EA  : 0x82748A88
// RVA : 0x00748A88
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetContents(idPhysics_Parametric *this, int contents, int id)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::SetContents(this: clipModel, newContents: contents);
}


// ========================================================================
// ?IsAtRest@idPhysics_Parametric@@UBA_NXZ
// EA  : 0x82748AA0
// RVA : 0x00748AA0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

BOOL __fastcall idPhysics_Parametric::IsAtRest(idPhysics_Parametric *this)
{
  return this->current.atRest >= 0;
}


// ========================================================================
// ?GetOrigin@idPhysics_Parametric@@UBAABVidVec3@@H@Z
// EA  : 0x82748AB0
// RVA : 0x00748AB0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

XGRAPHICS::_AS_CONST_INFO *__fastcall idPhysics_Parametric::GetOrigin(char *hSSMDev)
{
  return (XGRAPHICS::_AS_CONST_INFO *)(hSSMDev + 128);
}


// ========================================================================
// ?GetAxis@idPhysics_Parametric@@UBAABVidMat3@@H@Z
// EA  : 0x82748AB8
// RVA : 0x00748AB8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_Parametric::GetAxis(idPhysics_Parametric *this, int id)
{
  return &this->current.worldAxis;
}


// ========================================================================
// ?UnlinkClip@idPhysics_Parametric@@UAAXXZ
// EA  : 0x82748AC0
// RVA : 0x00748AC0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::UnlinkClip(idPhysics_Parametric *this)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Unlink(this: clipModel);
}


// ========================================================================
// ?TestIfAtRest@idPhysics_ParametricMM@@ABA_NXZ
// EA  : 0x82748D00
// RVA : 0x00748D00
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_ParametricMM::TestIfAtRest(
        idPhysics_ParametricMM *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  extrapolation_t extrapolationType; // r11
  char v8; // r11
  int result; // r3
  char v10; // r11
  double v11; // fp0
  double length; // fp0
  double totalLength; // fp13

  extrapolationType = this->current.linearExtrapolation.extrapolationType;
  if ( (extrapolationType & 0xFFFFFFBF) == 1 )
  {
    HIDWORD(a7) = this->current.angularExtrapolation.extrapolationType & 0xFFFFFFBF;
    if ( HIDWORD(a7) == 1
      && (float)((float)(this->current.linearInterpolation.decelTime + this->current.linearInterpolation.linearTime)
               + this->current.linearInterpolation.accelTime) == 0.0
      && (float)((float)(this->current.angularInterpolation.decelTime + this->current.angularInterpolation.linearTime)
               + this->current.angularInterpolation.accelTime) == 0.0
      && this->current.spline == nullptr )
    {
      return 1;
    }
  }
  if ( (extrapolationType & 0x40) != 0
    || (LODWORD(a7) = this->current.time,
        v8 = 1,
        (float)a7 < (double)(float)(this->current.linearExtrapolation.duration
                                  + this->current.linearExtrapolation.startTime)) )
  {
    v8 = 0;
  }
  if ( v8 == 0 )
    return 0;
  if ( (this->current.angularExtrapolation.extrapolationType & 0x40) != 0
    || (LODWORD(a7) = this->current.time,
        v10 = 1,
        (float)a7 < (double)(float)(this->current.angularExtrapolation.duration
                                  + this->current.angularExtrapolation.startTime)) )
  {
    v10 = 0;
  }
  if ( v10 == 0 )
    return 0;
  LODWORD(a7) = this->current.time;
  v11 = (float)a7;
  if ( v11 < (float)((float)((float)(this->current.linearInterpolation.decelTime
                                   + this->current.linearInterpolation.linearTime)
                           + this->current.linearInterpolation.accelTime)
                   + this->current.linearInterpolation.startTime)
    || v11 < (float)((float)((float)(this->current.angularInterpolation.decelTime
                                   + this->current.angularInterpolation.linearTime)
                           + this->current.angularInterpolation.accelTime)
                   + this->current.angularInterpolation.startTime) )
  {
    return 0;
  }
  if ( this->current.spline == nullptr )
    return 1;
  length = this->current.length;
  totalLength = this->current.totalLength;
  result = 0;
  if ( length > totalLength )
    return 1;
  return result;
}


// ========================================================================
// ?SetAngularExtrapolation@idPhysics_ParametricMM@@QAAXW4extrapolation_t@@HHHABVidMat3@@ABVidVec3@@M@Z
// EA  : 0x82748F68
// RVA : 0x00748F68
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetAngularExtrapolation(
        idPhysics_ParametricMM *this,
        extrapolation_t type,
        int currentTime,
        unsigned int time,
        unsigned int duration,
        const idMat3 *base,
        __int64 vec,
        double speed)
{
  this->current.time = currentTime;
  LODWORD(vec) = duration;
  this->current.angularExtrapolation.speed = speed;
  this->current.angularExtrapolation.extrapolationType = type;
  this->current.angularExtrapolation.startValue = 0.0;
  this->current.angularExtrapolation.baseSpeed = 0.0;
  this->current.angularExtrapolation.currentValue = 0.0;
  this->current.angularExtrapolation.duration = (float)vec;
  this->current.angularExtrapolation.currentTime = -1.0;
  this->current.angularExtrapolation.startTime = (float)__SPAIR64__(duration, time);
  this->current.angularExtrapolationRotVec = *(idVec3 *)HIDWORD(vec);
  this->current.angularExtrapolationStartAxis = *base;
  this->current.localAxis = *base;
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?GetAngularExtrapolationType@idPhysics_ParametricMM@@QBA?AW4extrapolation_t@@XZ
// EA  : 0x827490B8
// RVA : 0x007490B8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

extrapolation_t __fastcall idPhysics_ParametricMM::GetAngularExtrapolationType(idPhysics_ParametricMM *this)
{
  return this->current.angularExtrapolation.extrapolationType;
}


// ========================================================================
// ?ForceSplineRest@idPhysics_ParametricMM@@QAAXXZ
// EA  : 0x827490C0
// RVA : 0x007490C0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::ForceSplineRest(idPhysics_ParametricMM *this)
{
  double startValue; // fp0

  this->current.splineInterpolate.duration = 0.0;
  this->current.splineInterpolate.startTime = 0.0;
  this->current.splineInterpolate.startValue = 0.0;
  startValue = this->current.splineInterpolate.startValue;
  this->current.splineInterpolate.endValue = this->current.splineInterpolate.startValue;
  this->current.splineInterpolate.startSpeed = startValue;
  this->current.splineInterpolate.endSpeed = startValue;
}


// ========================================================================
// ?GetSplineAtRest@idPhysics_ParametricMM@@QBA_NXZ
// EA  : 0x827490F8
// RVA : 0x007490F8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_ParametricMM::GetSplineAtRest(idPhysics_ParametricMM *this)
{
  __int64 v1; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  LODWORD(v1) = this->current.time;
  HIDWORD(v1) = this->current.pauseTime;
  if ( SHIDWORD(v1) >= (int)v1 )
    return 0;
  v3 = (float)v1 >= (double)(float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime);
  v2 = 1;
  if ( !v3 )
    return 0;
  return v2;
}


// ========================================================================
// ?SetClipModel@idPhysics_ParametricMM@@UAAXPAVidClipModel@@MH_N@Z
// EA  : 0x82749158
// RVA : 0x00749158
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetClipModel(
        idPhysics_ParametricMM *this,
        idClipModel *model,
        double density,
        int id,
        bool freeOld,
        char a6)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr && clipModel != model && a6 != 0 )
    idClipModel::Delete(this: clipModel);
  if ( model != nullptr )
  {
    this->clipModel = model;
    idClipModel::Link(
      this: model,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
  }
}


// ========================================================================
// ?GetClipModel@idPhysics_ParametricMM@@UBAPAVidClipModel@@H@Z
// EA  : 0x827491D8
// RVA : 0x007491D8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idClipModel *__fastcall idPhysics_ParametricMM::GetClipModel(idPhysics_ParametricMM *this, int id)
{
  idClipModel *result; // r3

  result = this->clipModel;
  if ( result == nullptr )
    return this->clip->defaultClipModel;
  return result;
}


// ========================================================================
// ?GetContents@idPhysics_ParametricMM@@UBAHH@Z
// EA  : 0x827491F8
// RVA : 0x007491F8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_ParametricMM::GetContents(idPhysics_ParametricMM *this, int id)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return clipModel->contents;
  else
    return 0;
}


// ========================================================================
// ?GetBounds@idPhysics_ParametricMM@@UBAABVidBounds@@H@Z
// EA  : 0x82749218
// RVA : 0x00749218
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_ParametricMM::GetBounds(idPhysics_ParametricMM *this, int id)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return &clipModel->bounds;
  else
    return &bounds_zero;
}


// ========================================================================
// ?GetAbsBounds@idPhysics_ParametricMM@@UBAABVidBounds@@H@Z
// EA  : 0x82749238
// RVA : 0x00749238
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_ParametricMM::GetAbsBounds(idPhysics_ParametricMM *this, int id)
{
  idClipModel *clipModel; // r10
  double x; // fp0

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return &clipModel->absBounds;
  x = this->current.worldOrigin.x;
  this->absBounds.b[1] = this->current.worldOrigin;
  this->absBounds.b[0].x = x;
  this->absBounds.b[0].y = this->absBounds.b[1].y;
  this->absBounds.b[0].z = this->absBounds.b[1].z;
  return &this->absBounds;
}


// ========================================================================
// ?DisableClip@idPhysics_ParametricMM@@UAAXXZ
// EA  : 0x82749290
// RVA : 0x00749290
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::DisableClip(idPhysics_ParametricMM *this)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    clipModel->enabled = false;
}


// ========================================================================
// ?EnableClip@idPhysics_ParametricMM@@UAAXXZ
// EA  : 0x827492A8
// RVA : 0x007492A8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::EnableClip(idPhysics_ParametricMM *this)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    clipModel->enabled = true;
}


// ========================================================================
// ?LinkClip@idPhysics_ParametricMM@@UAAXXZ
// EA  : 0x827492C0
// RVA : 0x007492C0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::LinkClip(idPhysics_ParametricMM *this)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ?GetBlockingEntityNum@idPhysics_ParametricMM@@UBAHXZ
// EA  : 0x827492F0
// RVA : 0x007492F0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_ParametricMM::GetBlockingEntityNum(idPhysics_ParametricMM *this)
{
  int blockingPhysicsId; // r3
  idPhysics *PhysicsForId; // r3

  blockingPhysicsId = this->blockingPhysicsId;
  if ( blockingPhysicsId == -1 )
    return 0x1FFF;
  PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: blockingPhysicsId);
  if ( PhysicsForId == nullptr )
    return 0x1FFF;
  else
    return PhysicsForId->entityNumber;
}


// ========================================================================
// ?GetAngularEndTime@idPhysics_ParametricMM@@UBAHXZ
// EA  : 0x82749340
// RVA : 0x00749340
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_ParametricMM::GetAngularEndTime(idPhysics_ParametricMM *this)
{
  double v1; // fp0

  v1 = 0.0;
  if ( (float)((float)(this->current.angularInterpolation.decelTime + this->current.angularInterpolation.linearTime)
             + this->current.angularInterpolation.accelTime) != 0.0 )
    return (int)(float)((float)((float)(this->current.angularInterpolation.decelTime
                                      + this->current.angularInterpolation.linearTime)
                              + this->current.angularInterpolation.accelTime)
                      + this->current.angularInterpolation.startTime);
  if ( (this->current.angularExtrapolation.extrapolationType & 0x40) == 0
    && this->current.angularExtrapolation.duration > 0.0 )
  {
    return (int)(float)(this->current.angularExtrapolation.startTime + this->current.angularExtrapolation.duration);
  }
  return (int)v1;
}


// ========================================================================
// ?PrintDebugSplineInterpolationDebug@idPhysics_ParametricMM@@QAAXXZ
// EA  : 0x827493B0
// RVA : 0x007493B0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::PrintDebugSplineInterpolationDebug(idPhysics_ParametricMM *this)
{
  idLib::Printf(
    fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->current.splineInterpolate.startSpeed)),
    (unsigned int)COERCE_UNSIGNED_INT64(this->current.splineInterpolate.startSpeed),
    (unsigned int)COERCE_UNSIGNED_INT64(this->current.splineInterpolate.endSpeed),
    (unsigned int)COERCE_UNSIGNED_INT64(this->current.splineInterpolate.duration),
    (unsigned int)COERCE_UNSIGNED_INT64((float)(this->current.splineInterpolate.duration
                                              + this->current.splineInterpolate.startTime)),
    (unsigned int)COERCE_UNSIGNED_INT64(this->current.splineInterpolate.startValue),
    (unsigned int)COERCE_UNSIGNED_INT64(this->current.splineInterpolate.endValue));
}


// ========================================================================
// ?TestIfAtRest@idPhysics_Parametric@@ABA_NXZ
// EA  : 0x82749430
// RVA : 0x00749430
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_Parametric::TestIfAtRest(
        idPhysics_Parametric *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  extrapolation_t extrapolationType; // r11
  char v8; // r11
  int result; // r3
  char v10; // r11
  double v11; // fp1
  idCurve_Spline<idVec3> *spline; // r11
  bool v13; // zf

  extrapolationType = this->current.linearExtrapolation.extrapolationType;
  if ( (extrapolationType & 0xFFFFFFBF) == 1 )
  {
    HIDWORD(a7) = this->current.angularExtrapolation.extrapolationType & 0xFFFFFFBF;
    if ( HIDWORD(a7) == 1
      && (float)((float)(this->current.linearInterpolation.decelTime + this->current.linearInterpolation.linearTime)
               + this->current.linearInterpolation.accelTime) == 0.0
      && (float)((float)(this->current.angularInterpolation.decelTime + this->current.angularInterpolation.linearTime)
               + this->current.angularInterpolation.accelTime) == 0.0
      && this->current.spline == nullptr )
    {
      return 1;
    }
  }
  if ( (extrapolationType & 0x40) != 0
    || (LODWORD(a7) = this->current.time,
        v8 = 1,
        (float)a7 < (double)(float)(this->current.linearExtrapolation.duration
                                  + this->current.linearExtrapolation.startTime)) )
  {
    v8 = 0;
  }
  if ( v8 == 0 )
    return 0;
  if ( (this->current.angularExtrapolation.extrapolationType & 0x40) != 0
    || (LODWORD(a7) = this->current.time,
        v10 = 1,
        (float)a7 < (double)(float)(this->current.angularExtrapolation.duration
                                  + this->current.angularExtrapolation.startTime)) )
  {
    v10 = 0;
  }
  if ( v10 == 0 )
    return 0;
  LODWORD(a7) = this->current.time;
  v11 = (float)a7;
  if ( v11 < (float)((float)((float)(this->current.linearInterpolation.decelTime
                                   + this->current.linearInterpolation.linearTime)
                           + this->current.linearInterpolation.accelTime)
                   + this->current.linearInterpolation.startTime)
    || v11 < (float)((float)((float)(this->current.angularInterpolation.decelTime
                                   + this->current.angularInterpolation.linearTime)
                           + this->current.angularInterpolation.accelTime)
                   + this->current.angularInterpolation.startTime) )
  {
    return 0;
  }
  spline = this->current.spline;
  if ( spline == nullptr )
    return 1;
  v13 = ((unsigned __int8 (*)(void))spline->IsDone)() == 0;
  result = 0;
  if ( !v13 )
    return 1;
  return result;
}


// ========================================================================
// ?GetAngularExtrapolationType@idPhysics_Parametric@@QBA?AW4extrapolation_t@@XZ
// EA  : 0x82749768
// RVA : 0x00749768
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

extrapolation_t __fastcall idPhysics_Parametric::GetAngularExtrapolationType(idPhysics_Parametric *this)
{
  return this->current.angularExtrapolation.extrapolationType;
}


// ========================================================================
// ?SetClipModel@idPhysics_Parametric@@UAAXPAVidClipModel@@MH_N@Z
// EA  : 0x82749770
// RVA : 0x00749770
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetClipModel(
        idPhysics_Parametric *this,
        idClipModel *model,
        double density,
        int id,
        bool freeOld,
        char a6)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr && clipModel != model && a6 != 0 )
    idClipModel::Delete(this: clipModel);
  if ( model != nullptr )
  {
    this->clipModel = model;
    idClipModel::Link(
      this: model,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
  }
}


// ========================================================================
// ?GetClipModel@idPhysics_Parametric@@UBAPAVidClipModel@@H@Z
// EA  : 0x827497F0
// RVA : 0x007497F0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idClipModel *__fastcall idPhysics_Parametric::GetClipModel(idPhysics_Parametric *this, int id)
{
  idClipModel *result; // r3

  result = this->clipModel;
  if ( result == nullptr )
    return this->clip->defaultClipModel;
  return result;
}


// ========================================================================
// ?GetContents@idPhysics_Parametric@@UBAHH@Z
// EA  : 0x82749810
// RVA : 0x00749810
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_Parametric::GetContents(idPhysics_Parametric *this, int id)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return clipModel->contents;
  else
    return 0;
}


// ========================================================================
// ?GetBounds@idPhysics_Parametric@@UBAABVidBounds@@H@Z
// EA  : 0x82749830
// RVA : 0x00749830
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_Parametric::GetBounds(idPhysics_Parametric *this, int id)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return &clipModel->bounds;
  else
    return &bounds_zero;
}


// ========================================================================
// ?GetAbsBounds@idPhysics_Parametric@@UBAABVidBounds@@H@Z
// EA  : 0x82749850
// RVA : 0x00749850
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_Parametric::GetAbsBounds(idPhysics_Parametric *this, int id)
{
  idClipModel *clipModel; // r10
  double x; // fp0

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    return &clipModel->absBounds;
  x = this->current.worldOrigin.x;
  this->absBounds.b[1] = this->current.worldOrigin;
  this->absBounds.b[0].x = x;
  this->absBounds.b[0].y = this->absBounds.b[1].y;
  this->absBounds.b[0].z = this->absBounds.b[1].z;
  return &this->absBounds;
}


// ========================================================================
// ?ForceUpdateSpatialVelocity@idPhysics_Parametric@@QAAXABVidVec3@@ABVidMat3@@01H@Z
// EA  : 0x827498A8
// RVA : 0x007498A8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::ForceUpdateSpatialVelocity(
        idPhysics_Parametric *this,
        const idVec3 *worldOrigin,
        idMat3 *worldAxis,
        const idVec3 *oldOrigin,
        const idMat3 *oldAxis,
        unsigned int timeStepMSec)
{
  double x; // fp10
  double y; // fp7
  double v8; // fp5
  double v10; // fp3
  double v11; // fp9
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  double v15; // fp5
  double v16; // fp4
  double z; // fp3
  double v18; // fp2
  double v19; // fp30
  idMat3 *v20; // r3
  idVec3 *v21; // r3
  double v22; // fp13
  double v23; // fp12
  idMat3 v24; // [sp+50h] [-90h] BYREF
  float v25; // [sp+74h] [-6Ch]
  float v26; // [sp+78h] [-68h]
  float v27; // [sp+7Ch] [-64h]
  float v28; // [sp+80h] [-60h]
  idMat3 v29; // [sp+90h] [-50h] BYREF

  x = oldOrigin->x;
  y = oldOrigin->y;
  *(_QWORD *)&v24.mat[0].x = __PAIR64__(&unk_82390000, timeStepMSec);
  v8 = (float)(worldOrigin->y - (float)y);
  v10 = (float)(worldOrigin->z - oldOrigin->z);
  this->spatialVelocity.p[0] = (float)(worldOrigin->x - (float)x)
                             * (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001));
  this->spatialVelocity.p[1] = (float)v8
                             * (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001));
  this->spatialVelocity.p[2] = (float)v10
                             * (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001));
  v11 = oldAxis->mat[2].y;
  v12 = oldAxis->mat[1].y;
  v13 = oldAxis->mat[0].y;
  v14 = oldAxis->mat[2].x;
  v15 = oldAxis->mat[1].x;
  v16 = oldAxis->mat[0].x;
  z = oldAxis->mat[2].z;
  v18 = oldAxis->mat[1].z;
  v26 = oldAxis->mat[0].z;
  v27 = v18;
  v19 = (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001);
  v28 = z;
  v25 = v11;
  v24.mat[2].z = v12;
  v24.mat[2].y = v13;
  v24.mat[2].x = v14;
  v24.mat[1].z = v15;
  v24.mat[1].y = v16;
  v20 = idMat3::operator*(this: &v29, result: worldAxis, a: (idMat3 *)&v24.mat[1].y);
  v21 = idMat3::ToAngularVelocity(this: &v24, result: v20->mat);
  v22 = v21->y;
  v23 = v21->z;
  this->spatialVelocity.p[3] = (float)((float)1.0 / (float)v19) * v21->x;
  this->spatialVelocity.p[4] = (float)v22 * (float)((float)1.0 / (float)v19);
  this->spatialVelocity.p[5] = (float)v23 * (float)((float)1.0 / (float)v19);
}


// ========================================================================
// ?GetImpactInfo@idPhysics_Parametric@@UBAXHABVidVec3@@AAUimpactInfo_t@@@Z
// EA  : 0x827499E0
// RVA : 0x007499E0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::GetImpactInfo(
        idPhysics_Parametric *this,
        const int id,
        const idVec3 *point,
        impactInfo_t *info)
{
  double v7; // fp2
  double v8; // fp1
  double v9; // fp8
  double v10; // fp7

  memset(Dst: info, Val: 0, Size: sizeof(impactInfo_t));
  v7 = this->spatialVelocity.p[0];
  v8 = this->spatialVelocity.p[1];
  v9 = (float)((float)(this->spatialVelocity.p[4] * (float)(point->z - this->current.worldOrigin.z))
             - (float)(this->spatialVelocity.p[5] * (float)(point->y - this->current.worldOrigin.y)));
  v10 = (float)((float)(this->spatialVelocity.p[5] * (float)(point->x - this->current.worldOrigin.x))
              - (float)(this->spatialVelocity.p[3] * (float)(point->z - this->current.worldOrigin.z)));
  info->velocity.z = this->spatialVelocity.p[2]
                   + (float)((float)(this->spatialVelocity.p[3] * (float)(point->y - this->current.worldOrigin.y))
                           - (float)(this->spatialVelocity.p[4] * (float)(point->x - this->current.worldOrigin.x)));
  info->velocity.x = (float)v7 + (float)v9;
  info->velocity.y = (float)v8 + (float)v10;
}


// ========================================================================
// ?DisableClip@idPhysics_Parametric@@UAAXXZ
// EA  : 0x82749A80
// RVA : 0x00749A80
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::DisableClip(idPhysics_Parametric *this)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    clipModel->enabled = false;
}


// ========================================================================
// ?EnableClip@idPhysics_Parametric@@UAAXXZ
// EA  : 0x82749A98
// RVA : 0x00749A98
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::EnableClip(idPhysics_Parametric *this)
{
  idClipModel *clipModel; // r11

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    clipModel->enabled = true;
}


// ========================================================================
// ?LinkClip@idPhysics_Parametric@@UAAXXZ
// EA  : 0x82749AB0
// RVA : 0x00749AB0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::LinkClip(idPhysics_Parametric *this)
{
  idClipModel *clipModel; // r3

  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ?GetBlockingEntityNum@idPhysics_Parametric@@UBAHXZ
// EA  : 0x82749AE0
// RVA : 0x00749AE0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_Parametric::GetBlockingEntityNum(idPhysics_Parametric *this)
{
  int blockingPhysicsId; // r3
  idPhysics *PhysicsForId; // r3

  blockingPhysicsId = this->blockingPhysicsId;
  if ( blockingPhysicsId == -1 )
    return 0x1FFF;
  PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: blockingPhysicsId);
  if ( PhysicsForId == nullptr )
    return 0x1FFF;
  else
    return PhysicsForId->entityNumber;
}


// ========================================================================
// ?GetAngularEndTime@idPhysics_Parametric@@UBAHXZ
// EA  : 0x82749B30
// RVA : 0x00749B30
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_Parametric::GetAngularEndTime(idPhysics_Parametric *this)
{
  double v1; // fp0

  v1 = 0.0;
  if ( (float)((float)(this->current.angularInterpolation.decelTime + this->current.angularInterpolation.linearTime)
             + this->current.angularInterpolation.accelTime) != 0.0 )
    return (int)(float)((float)((float)(this->current.angularInterpolation.decelTime
                                      + this->current.angularInterpolation.linearTime)
                              + this->current.angularInterpolation.accelTime)
                      + this->current.angularInterpolation.startTime);
  if ( (this->current.angularExtrapolation.extrapolationType & 0x40) == 0
    && this->current.angularExtrapolation.duration > 0.0 )
  {
    return (int)(float)(this->current.angularExtrapolation.startTime + this->current.angularExtrapolation.duration);
  }
  return (int)v1;
}


// ========================================================================
// ?SetLinearExtrapolation@idPhysics_ParametricMM@@QAAXW4extrapolation_t@@HHHABVidVec3@@11@Z
// EA  : 0x8274B488
// RVA : 0x0074B488
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetLinearExtrapolation(
        idPhysics_ParametricMM *this,
        extrapolation_t type,
        int currentTime,
        __int64 duration,
        const idVec3 *base,
        const idVec3 *speed)
{
  __int64 baseSpeed; // r11

  LODWORD(baseSpeed) = duration;
  this->current.time = currentTime;
  LODWORD(duration) = HIDWORD(duration);
  this->current.linearExtrapolation.extrapolationType = type;
  this->current.linearExtrapolation.duration = (float)baseSpeed;
  this->current.linearExtrapolation.startTime = (float)duration;
  this->current.linearExtrapolation.startValue = *base;
  this->current.linearExtrapolation.baseSpeed = *(idVec3 *)HIDWORD(baseSpeed);
  this->current.linearExtrapolation.speed = *speed;
  this->current.linearExtrapolation.currentTime = -1.0;
  this->current.linearExtrapolation.currentValue = *base;
  this->current.localOrigin = *base;
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetSplineAngularInterpolation@idPhysics_ParametricMM@@QAAXABVidQuat@@0M@Z
// EA  : 0x8274B580
// RVA : 0x0074B580
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetSplineAngularInterpolation(
        idPhysics_ParametricMM *this,
        idMat3 *startQuat,
        const idQuat *endQuat,
        double endPos,
        int a5,
        int a6,
        __int64 a7)
{
  double x; // fp31
  double y; // fp30
  double z; // fp29
  double w; // fp28
  double v14; // fp1
  double CurrentValue; // fp1
  idQuat v16; // [sp+60h] [-70h] BYREF

  if ( (float)((float)(startQuat->mat[0].x * endQuat->x)
             + (float)((float)(endQuat->w * startQuat->mat[1].x)
                     + (float)((float)(startQuat->mat[0].y * endQuat->y) + (float)(startQuat->mat[0].z * endQuat->z)))) >= 0.0 )
  {
    x = endQuat->x;
    y = endQuat->y;
    z = endQuat->z;
    w = endQuat->w;
  }
  else
  {
    x = -endQuat->x;
    y = -endQuat->y;
    z = -endQuat->z;
    w = -endQuat->w;
  }
  LODWORD(a7) = this->current.time;
  v14 = (float)a7;
  if ( v14 < (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime) )
  {
    CurrentValue = idExtrapolate<float>::GetCurrentValue(this: &this->current.splineInterpolate.extrapolate, time: v14);
  }
  else if ( this->current.splineInterpolate.startSpeed == this->current.splineInterpolate.endSpeed )
  {
    CurrentValue = this->current.splineInterpolate.endValue;
  }
  else
  {
    CurrentValue = (float)((float)((float)((float)((float)a7
                                                 - (float)(this->current.splineInterpolate.duration
                                                         + this->current.splineInterpolate.startTime))
                                         * this->current.splineInterpolate.endSpeed)
                                 * (float)0.001)
                         + this->current.splineInterpolate.endValue);
  }
  this->current.splineAngleInterpolate.duration = (float)endPos - (float)CurrentValue;
  this->current.splineAngleInterpolate.startTime = CurrentValue;
  this->current.splineAngleInterpolate.startValue.x = startQuat->mat[0].x;
  this->current.splineAngleInterpolate.startValue.y = startQuat->mat[0].y;
  this->current.splineAngleInterpolate.startValue.z = startQuat->mat[0].z;
  this->current.splineAngleInterpolate.startValue.w = startQuat->mat[1].x;
  this->current.splineAngleInterpolate.endValue.x = x;
  this->current.splineAngleInterpolate.endValue.y = y;
  this->current.splineAngleInterpolate.endValue.z = z;
  this->current.splineAngleInterpolate.endValue.w = w;
  this->current.splineAngleInterpolate.currentTime = (float)CurrentValue - (float)1.0;
  this->current.splineAngleInterpolate.currentValue.x = startQuat->mat[0].x;
  this->current.splineAngleInterpolate.currentValue.y = startQuat->mat[0].y;
  this->current.splineAngleInterpolate.currentValue.z = startQuat->mat[0].z;
  this->current.splineAngleInterpolate.currentValue.w = startQuat->mat[1].x;
  this->current.localAxis = *idQuat::ToMat3(this: &v16, result: startQuat);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetSpline@idPhysics_ParametricMM@@QAAXPAV?$idCurve_Spline@VidVec3@@@@HM_N1M@Z
// EA  : 0x8274B790
// RVA : 0x0074B790
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetSpline(
        idPhysics_ParametricMM *this,
        idCurve_Spline<idVec3> *spline,
        int startTime,
        double totalTime,
        bool useSplineAngles,
        bool startAtEnd,
        double startSplineTime,
        char a8)
{
  idCurve_Spline<idVec3> *v9; // r3
  idPhysics_ParametricMM_vtbl *v16; // r26
  const idVec3 *v17; // r3
  idPhysics_ParametricMM_vtbl *v18; // r26
  const idMat3 *v19; // r3
  __int64 v20; // r11
  const float *v21; // r5
  const float *v22; // r4
  double v23; // fp1
  int v24; // r6
  __int64 v25; // fp0
  float *p_totalLength; // r8
  float v27[2]; // [sp+50h] [-70h] BYREF
  _QWORD v28[3]; // [sp+58h] [-68h] BYREF

  v9 = this->current.spline;
  if ( v9 != nullptr )
  {
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))v9->dtr_idCurve<idVec3>)(a1: v9, a2: 1);
    this->current.spline = nullptr;
    v16 = this->__vftable;
    v17 = this->GetOrigin(this, a2: 0);
    v16->SetOrigin(this, a2: v17, a3: -1);
    v18 = this->__vftable;
    v19 = this->GetAxis(this, a2: 0);
    v18->SetAxis(this, a2: v19, a3: -1);
  }
  this->current.spline = spline;
  if ( spline != nullptr )
  {
    v23 = ((double (__fastcall *)(idCurve_Spline<idVec3> *, double))spline->GetLengthForTime)(
            a1: spline,
            a2: spline->times.list[spline->values.num - 1]);
    v24 = 0x82000000;
    this->current.totalLength = v23;
    if ( a8 != 0 )
      v27[0] = v23;
    else
      v27[0] = 0.0;
    if ( startSplineTime >= 0.0 )
      v27[0] = this->current.spline->GetLengthForTime(this: this->current.spline, a2: startSplineTime);
    LODWORD(v20) = startTime;
    if ( a8 != 0 )
    {
      v28[1] = v20;
      v25 = v20;
      *(float *)v28 = 0.0;
      p_totalLength = (float *)v28;
    }
    else
    {
      v28[0] = v20;
      v25 = v20;
      p_totalLength = &this->current.totalLength;
    }
    idInterpolateAccelLinearEx<float>::InitDuration(
      this: &this->current.splineInterpolate,
      startTime: (float)v25,
      startSpeed: 0.0,
      duration: totalTime,
      startValue: v22,
      endValue: v21,
      a7: v24,
      a8: v27,
      a9: p_totalLength);
  }
  this->current.useSplineAngles = startAtEnd;
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?Evaluate_Oscillation@idPhysics_ParametricMM@@AAAXHH@Z
// EA  : 0x8274B948
// RVA : 0x0074B948
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::Evaluate_Oscillation(
        idPhysics_ParametricMM *this,
        int timeStepMSec,
        int endTimeMSec)
{
  double v5; // fp10
  double v6; // fp5
  double v7; // fp3
  float z; // r7
  float x; // r6
  double v10; // fp31
  double y; // fp30
  double v12; // fp29
  double v15; // fp1
  double v16; // fp1
  double v17; // fp12
  double v18; // fp11
  double v19; // fp10
  double v20; // fp1
  double v21; // fp25
  double v22; // fp24
  double v23; // fp23
  double v24; // fp11
  double v25; // fp10
  double v26; // fp9
  double v29; // fp1
  double v30; // fp4
  double v31; // fp1
  double v32; // fp28
  double v33; // fp27
  double v34; // fp26
  idVec3 *v35; // r30
  idExtrapolate<float> *oscillationExtrapolation; // r31
  int v37; // r29
  __int64 v38; // r11
  double startTime; // fp22
  double duration; // fp21
  double CurrentValue; // fp20
  double v42; // fp7
  double v43; // fp6
  double v44; // fp1
  double v45; // fp0
  idVec3 v46; // [sp+58h] [-A8h] BYREF

  if ( this->current.oscillationZRelative )
  {
    v5 = -this->current.localOrigin.y;
    v6 = -this->current.localOrigin.z;
    v7 = -this->current.localOrigin.x;
    z = this->current.localAxis.mat[0].z;
    x = this->current.localAxis.mat[0].x;
    v46.y = this->current.localAxis.mat[0].y;
    v46.z = z;
    v46.x = x;
    v10 = x;
    y = v46.y;
    v12 = z;
    _FP11 = (float)((float)((float)((float)v7 * (float)v7)
                          + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f11, f12, f13 }
    v15 = __frsqrte(_FP2);
    v16 = (float)((float)-(float)((float)((float)((float)v15
                                                * (float)((float)((float)((float)v7 * (float)v7)
                                                                + (float)((float)((float)v6 * (float)v6)
                                                                        + (float)((float)v5 * (float)v5)))
                                                        * (float)0.5))
                                        * (float)v15)
                                - (float)1.5)
                * (float)v15);
    v17 = (float)((float)v6
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                                * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5))
                                                                                        * (float)v16)
                                                                                - (float)1.5)
                                                                * (float)v16)
                                                        * (float)((float)((float)((float)v7 * (float)v7)
                                                                        + (float)((float)((float)v6 * (float)v6)
                                                                                + (float)((float)v5 * (float)v5)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v16
                                                                                        * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                                * (float)0.5))
                                                                                * (float)v16)
                                                                        - (float)1.5)
                                                        * (float)v16))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v16
                                                                * (float)((float)((float)((float)v7 * (float)v7)
                                                                                + (float)((float)((float)v6 * (float)v6)
                                                                                        + (float)((float)v5 * (float)v5)))
                                                                        * (float)0.5))
                                                        * (float)v16)
                                                - (float)1.5)
                                * (float)v16)));
    v18 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                                * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5))
                                                                                        * (float)v16)
                                                                                - (float)1.5)
                                                                * (float)v16)
                                                        * (float)((float)((float)((float)v7 * (float)v7)
                                                                        + (float)((float)((float)v6 * (float)v6)
                                                                                + (float)((float)v5 * (float)v5)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v16
                                                                                        * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                                * (float)0.5))
                                                                                * (float)v16)
                                                                        - (float)1.5)
                                                        * (float)v16))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v16
                                                                * (float)((float)((float)((float)v7 * (float)v7)
                                                                                + (float)((float)((float)v6 * (float)v6)
                                                                                        + (float)((float)v5 * (float)v5)))
                                                                        * (float)0.5))
                                                        * (float)v16)
                                                - (float)1.5)
                                * (float)v16))
                * (float)v7);
    v19 = (float)((float)v5
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v16
                                                                                                * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) * (float)0.5))
                                                                                        * (float)v16)
                                                                                - (float)1.5)
                                                                * (float)v16)
                                                        * (float)((float)((float)((float)v7 * (float)v7)
                                                                        + (float)((float)((float)v6 * (float)v6)
                                                                                + (float)((float)v5 * (float)v5)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v16
                                                                                        * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))
                                                                                                * (float)0.5))
                                                                                * (float)v16)
                                                                        - (float)1.5)
                                                        * (float)v16))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v16
                                                                * (float)((float)((float)((float)v7 * (float)v7)
                                                                                + (float)((float)((float)v6 * (float)v6)
                                                                                        + (float)((float)v5 * (float)v5)))
                                                                        * (float)0.5))
                                                        * (float)v16)
                                                - (float)1.5)
                                * (float)v16)));
    v20 = (float)(z * (float)v19);
    v21 = v18;
    v22 = v19;
    v23 = v17;
    v25 = (float)((float)((float)v19 * x) - (float)(v46.y * (float)v18));
    v24 = (float)((float)(z * (float)v18) - (float)((float)v17 * x));
    v26 = (float)((float)(v46.y * (float)v17) - (float)v20);
    _FP4 = (float)((float)((float)((float)v26 * (float)v26)
                         + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f5, f13 }
    v29 = __frsqrte(_FP2);
    v30 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29
                                                                                        * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                                * (float)0.5))
                                                                                * (float)v29)
                                                                        - (float)1.5)
                                                        * (float)v29)
                                                * (float)((float)((float)((float)v26 * (float)v26)
                                                                + (float)((float)((float)v25 * (float)v25)
                                                                        + (float)((float)v24 * (float)v24)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v29
                                                                                * (float)((float)((float)((float)v26 * (float)v26)
                                                                                                + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                        * (float)0.5))
                                                                        * (float)v29)
                                                                - (float)1.5)
                                                * (float)v29))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v29
                                                        * (float)((float)((float)((float)v26 * (float)v26)
                                                                        + (float)((float)((float)v25 * (float)v25)
                                                                                + (float)((float)v24 * (float)v24)))
                                                                * (float)0.5))
                                                * (float)v29)
                                        - (float)1.5)
                        * (float)v29));
    v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29) - (float)1.5)
                                                                                                * (float)v29)
                                                                                        * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v29 * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v29) - (float)1.5)
                                                                                        * (float)v29))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v29
                                                                                                * (float)((float)((float)((float)v26 * (float)v26) + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                        * (float)v29)
                                                                                - (float)1.5)
                                                                * (float)v29))
                                                * (float)((float)((float)((float)v26 * (float)v26)
                                                                + (float)((float)((float)v25 * (float)v25)
                                                                        + (float)((float)v24 * (float)v24)))
                                                        * (float)0.5))
                                        * (float)v30)
                                - (float)1.5)
                * (float)v30);
    v32 = (float)((float)v26 * (float)v31);
    v33 = (float)((float)v24 * (float)v31);
    v34 = (float)((float)v25 * (float)v31);
  }
  else
  {
    v10 = this->current.localAxis.mat[0].x;
    y = this->current.localAxis.mat[0].y;
    v12 = this->current.localAxis.mat[0].z;
    v32 = this->current.localAxis.mat[1].x;
    v33 = this->current.localAxis.mat[1].y;
    v34 = this->current.localAxis.mat[1].z;
    v21 = this->current.localAxis.mat[2].x;
    v22 = this->current.localAxis.mat[2].y;
    v23 = this->current.localAxis.mat[2].z;
  }
  v35 = &v46;
  oscillationExtrapolation = this->current.oscillationExtrapolation;
  v37 = 3;
  v46 = vec3_origin;
  do
  {
    HIDWORD(v38) = oscillationExtrapolation->extrapolationType & 0xFFFFFFBF;
    if ( HIDWORD(v38) != 1 )
    {
      LODWORD(v38) = endTimeMSec;
      startTime = oscillationExtrapolation->startTime;
      duration = oscillationExtrapolation->duration;
      CurrentValue = idExtrapolate<float>::GetCurrentValue(this: oscillationExtrapolation, time: (float)v38);
      v35->x = (float)CurrentValue
             - idExtrapolate<float>::GetCurrentValue(
                 this: oscillationExtrapolation,
                 time: (float)((float)duration + (float)startTime));
    }
    --v37;
    ++oscillationExtrapolation;
    v35 = (idVec3 *)((char *)v35 + 4);
  }
  while ( v37 != 0 );
  v42 = this->current.localOrigin.y;
  v43 = this->current.localOrigin.z;
  v44 = (float)((float)((float)y * v46.x) + (float)((float)((float)v33 * v46.y) + (float)((float)v22 * v46.z)));
  v45 = (float)((float)((float)v12 * v46.x) + (float)((float)((float)v34 * v46.y) + (float)((float)v23 * v46.z)));
  this->current.localOrigin.x = this->current.localOrigin.x
                              + (float)((float)((float)v10 * v46.x)
                                      + (float)((float)((float)v32 * v46.y) + (float)((float)v21 * v46.z)));
  this->current.localOrigin.y = (float)v44 + (float)v42;
  this->current.localOrigin.z = (float)v45 + (float)v43;
}


// ========================================================================
// ?SetOscillation@idPhysics_ParametricMM@@QAAXVidVec3@@00_N@Z
// EA  : 0x8274BBB0
// RVA : 0x0074BBB0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysics_ParametricMM::SetOscillation(
        idPhysics_ParametricMM *this,
        idVec3 *range,
        idVec3 *period,
        idVec3 *phaseShift,
        __int64 zAxisPointsToLocalOrigin,
        int a6,
        bool a7)
{
  double v7; // fp11
  int time; // r7
  double v9; // fp10
  double v10; // fp12
  __int64 v11; // r7
  int v12; // r7
  double v13; // fp6
  double v14; // fp12
  __int64 v15; // r5 OVERLAPPED
  __int64 v16; // r7
  int v17; // r11
  int v18; // r6
  __int64 v21; // [sp+50h] [+40h]

  v7 = *(float *)&this;
  HIDWORD(zAxisPointsToLocalOrigin) = 0x82000000;
  v21 = zAxisPointsToLocalOrigin;
  if ( *(float *)&this != 0.0 && (float)(*(float *)&period * (float)0.25) > 0.0 )
    v7 = (float)((float)(*(float *)&this / (float)(*(float *)&period * (float)0.25)) * (float)((float)1.0 / 0.70710677));
  time = this->current.time;
  v9 = *(float *)&range;
  this->current.oscillationExtrapolation[0].extrapolationType = EXTRAPOLATION_ACCELSINE|EXTRAPOLATION_NOSTOP;
  this->current.oscillationExtrapolation[0].speed = v7;
  v10 = (float)(*(float *)&phaseShift * (float)0.25);
  this->current.oscillationExtrapolation[0].startValue = 0.0;
  this->current.oscillationExtrapolation[0].baseSpeed = 0.0;
  this->current.oscillationExtrapolation[0].currentTime = -1.0;
  this->current.oscillationExtrapolation[0].currentValue = 0.0;
  HIDWORD(v11) = (int)(float)((float)1000.0 * (float)(*(float *)&period * (float)0.25));
  LODWORD(v11) = time - (int)(float)((float)1000.0 * *(float *)&v21);
  this->current.oscillationExtrapolation[0].startTime = (float)v11;
  this->current.oscillationExtrapolation[0].duration = (float)__SPAIR64__(v11, HIDWORD(v11));
  if ( *(float *)&range != 0.0 && v10 > 0.0 )
    v9 = (float)((float)(*(float *)&range / (float)v10) * (float)((float)1.0 / 0.70710677));
  v12 = this->current.time;
  v13 = (float)(1000.0 * (float)v10);
  this->current.oscillationExtrapolation[1].extrapolationType = EXTRAPOLATION_ACCELSINE|EXTRAPOLATION_NOSTOP;
  v14 = *(float *)&range;
  LODWORD(v15) = (int)(float)(1000.0 * *((float *)&v21 + 1));
  HIDWORD(v15) = v12 - v15;
  HIDWORD(v16) = v12 - v15;
  LODWORD(v16) = (int)v13;
  this->current.oscillationExtrapolation[1].startTime = (float)*(__int64 *)((char *)&v15 - 4);
  this->current.oscillationExtrapolation[1].duration = (float)v16;
  this->current.oscillationExtrapolation[1].startValue = 0.0;
  this->current.oscillationExtrapolation[1].baseSpeed = 0.0;
  this->current.oscillationExtrapolation[1].speed = v9;
  this->current.oscillationExtrapolation[1].currentTime = -1.0;
  this->current.oscillationExtrapolation[1].currentValue = 0.0;
  if ( *(float *)&range != 0.0 && (float)(*(float *)&phaseShift * (float)0.25) > 0.0 )
    v14 = (float)((float)(*(float *)&range / (float)(*(float *)&phaseShift * (float)0.25))
                * (float)((float)1.0 / 0.70710677));
  v17 = this->current.time;
  this->current.oscillationExtrapolation[2].extrapolationType = EXTRAPOLATION_ACCELSINE|EXTRAPOLATION_NOSTOP;
  v18 = (int)(float)(1000.0 * (float)(*(float *)&phaseShift * (float)0.25));
  LODWORD(v15) = v17 - (int)(float)(1000.0 * COERCE_FLOAT(&unk_82390000));
  this->current.oscillationExtrapolation[2].startTime = (float)v15;
  this->current.oscillationExtrapolation[2].duration = (float)*(__int64 *)((char *)&v15 - 4);
  this->current.oscillationExtrapolation[2].startValue = 0.0;
  this->current.oscillationExtrapolation[2].baseSpeed = 0.0;
  this->current.oscillationExtrapolation[2].speed = v14;
  this->current.oscillationExtrapolation[2].currentTime = -1.0;
  this->current.oscillationExtrapolation[2].currentValue = 0.0;
  this->current.oscillationZRelative = a7;
}


// ========================================================================
// ?SetLocalScale@idPhysics_ParametricMM@@QAAXVidVec3@@MM@Z
// EA  : 0x8274BDF0
// RVA : 0x0074BDF0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetLocalScale(
        idPhysics_ParametricMM *this,
        idVec3 *newScale,
        double startTime,
        double duration,
        int a5,
        int a6,
        int a7,
        int a8,
        __int64 a9)
{
  double v9; // fp29
  double v10; // fp28
  double v12; // fp27
  double v15; // fp0
  double v16; // fp13
  double x; // fp12
  idPhysics_ParametricMM *splineMaster; // r11
  double length; // fp1
  idInterpolate<idVec3> *CurrentValue; // r3
  idInterpolate<idVec3> v21; // [sp+50h] [-50h] BYREF

  v9 = *(float *)&newScale;
  v10 = *(float *)&newScale;
  v12 = *(float *)&this;
  if ( duration == 0.0 )
  {
    v15 = *(float *)&this;
    v16 = *(float *)&newScale;
    x = *(float *)&newScale;
  }
  else
  {
    splineMaster = this->current.splineMaster;
    if ( splineMaster != nullptr && splineMaster->current.spline != nullptr )
    {
      length = splineMaster->current.length;
    }
    else if ( this->current.spline != nullptr )
    {
      length = this->current.length;
    }
    else
    {
      LODWORD(a9) = this->current.time;
      *(_QWORD *)&v21.startTime = a9;
      length = (float)a9;
    }
    CurrentValue = idInterpolate<idVec3>::GetCurrentValue(
                     this: &v21,
                     result: (idVec3 *)&this->current.localOriginScaleInterpolation,
                     time: length);
    v15 = CurrentValue->startTime;
    v16 = CurrentValue->duration;
    x = CurrentValue->startValue.x;
  }
  this->current.localOriginScaleInterpolation.startTime = startTime;
  this->current.localOriginScaleInterpolation.duration = duration;
  this->current.localOriginScaleInterpolation.startValue.x = v15;
  this->current.localOriginScaleInterpolation.startValue.y = v16;
  this->current.localOriginScaleInterpolation.startValue.z = x;
  this->current.localOriginScaleInterpolation.endValue.x = v12;
  this->current.localOriginScaleInterpolation.endValue.y = v10;
  this->current.localOriginScaleInterpolation.endValue.z = v9;
  this->current.localOriginScaleInterpolation.currentTime = (float)startTime - (float)1.0;
  this->current.localOriginScaleInterpolation.currentValue.x = v15;
  this->current.localOriginScaleInterpolation.currentValue.y = v16;
  this->current.localOriginScaleInterpolation.currentValue.z = x;
}


// ========================================================================
// ?SetLocalOffset@idPhysics_ParametricMM@@QAAXVidVec3@@MM@Z
// EA  : 0x8274BF08
// RVA : 0x0074BF08
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetLocalOffset(
        idPhysics_ParametricMM *this,
        idVec3 *newOffset,
        double startTime,
        double duration,
        int a5,
        int a6,
        int a7,
        int a8,
        __int64 a9)
{
  double v9; // fp29
  double v10; // fp28
  double v12; // fp27
  double v15; // fp0
  double v16; // fp13
  double x; // fp12
  idPhysics_ParametricMM *splineMaster; // r11
  double length; // fp1
  idInterpolate<idVec3> *CurrentValue; // r3
  idInterpolate<idVec3> v21; // [sp+50h] [-50h] BYREF

  v9 = *(float *)&newOffset;
  v10 = *(float *)&newOffset;
  v12 = *(float *)&this;
  if ( duration == 0.0 )
  {
    v15 = *(float *)&this;
    v16 = *(float *)&newOffset;
    x = *(float *)&newOffset;
  }
  else
  {
    splineMaster = this->current.splineMaster;
    if ( splineMaster != nullptr && splineMaster->current.spline != nullptr )
    {
      length = splineMaster->current.length;
    }
    else if ( this->current.spline != nullptr )
    {
      length = this->current.length;
    }
    else
    {
      LODWORD(a9) = this->current.time;
      *(_QWORD *)&v21.startTime = a9;
      length = (float)a9;
    }
    CurrentValue = idInterpolate<idVec3>::GetCurrentValue(
                     this: &v21,
                     result: (idVec3 *)&this->current.localOffsetInterpolation,
                     time: length);
    v15 = CurrentValue->startTime;
    v16 = CurrentValue->duration;
    x = CurrentValue->startValue.x;
  }
  this->current.localOffsetInterpolation.startTime = startTime;
  this->current.localOffsetInterpolation.duration = duration;
  this->current.localOffsetInterpolation.startValue.x = v15;
  this->current.localOffsetInterpolation.startValue.y = v16;
  this->current.localOffsetInterpolation.startValue.z = x;
  this->current.localOffsetInterpolation.endValue.x = v12;
  this->current.localOffsetInterpolation.endValue.y = v10;
  this->current.localOffsetInterpolation.endValue.z = v9;
  this->current.localOffsetInterpolation.currentTime = (float)startTime - (float)1.0;
  this->current.localOffsetInterpolation.currentValue.x = v15;
  this->current.localOffsetInterpolation.currentValue.y = v16;
  this->current.localOffsetInterpolation.currentValue.z = x;
}


// ========================================================================
// ?SetLinearVelocity@idPhysics_ParametricMM@@UAAXABVidVec3@@H@Z
// EA  : 0x8274C020
// RVA : 0x0074C020
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetLinearVelocity(
        idPhysics_ParametricMM *this,
        const idVec3 *newLinearVelocity,
        int id)
{
  int v4; // r7
  int v5; // r6
  const idAngles *v6; // r5
  const idAngles *v7; // r4

  idPhysics_ParametricMM::SetLinearExtrapolation(
    this,
    type: EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP,
    currentTime: this->current.time,
    duration: (unsigned int)&this->current.worldOrigin,
    base: newLinearVelocity,
    speed: &vec3_origin);
  idInterpolateAccelDecelLinear<idAngles>::Init(
    this: (idInterpolateAccelDecelLinear<idAngles> *)&this->current.linearInterpolation,
    startTime: 0.0,
    accelTime: 0.0,
    decelTime: 0.0,
    duration: 0.0,
    startValue: v7,
    endValue: v6,
    a8: v5,
    a9: v4,
    a10: (idAngles *)&vec3_origin,
    a11: (idAngles *)&vec3_origin);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetMaster@idPhysics_ParametricMM@@UAAX_NABVidVec3@@ABVidMat3@@W4bindFlags_t@@@Z
// EA  : 0x8274C0B8
// RVA : 0x0074C0B8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetMaster(
        idPhysics_ParametricMM *this,
        bool enable,
        const idVec3 *masterOrigin,
        const idMat3 *masterAxis,
        const bindFlags_t bflags)
{
  bool v6; // r29
  idVec3 *p_localOrigin; // r30
  double v8; // fp2
  double x; // fp7
  double v10; // fp5
  double v11; // fp1
  double v12; // fp0
  double z; // fp13
  double v14; // fp12
  double y; // fp11
  double v16; // fp10
  double v17; // fp9
  double v18; // fp8
  double v19; // fp7
  double v20; // fp6
  __int64 v21; // r10
  idMat3 v22; // [sp+50h] [-80h] BYREF
  idMat3 v23[2]; // [sp+80h] [-50h] BYREF

  if ( enable )
  {
    if ( !this->hasMaster )
    {
      v6 = bflags & 1;
      p_localOrigin = &this->current.localOrigin;
      v8 = (float)(this->current.worldOrigin.x - masterOrigin->x);
      x = masterAxis->mat[2].x;
      v10 = masterAxis->mat[1].x;
      v11 = (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y) * masterAxis->mat[1].y)
                  + (float)((float)(this->current.worldOrigin.z - masterOrigin->z) * masterAxis->mat[1].z));
      v12 = (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y) * masterAxis->mat[2].y)
                  + (float)((float)(this->current.worldOrigin.z - masterOrigin->z) * masterAxis->mat[2].z));
      this->current.localOrigin.x = (float)((float)(this->current.worldOrigin.x - masterOrigin->x) * masterAxis->mat[0].x)
                                  + (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y)
                                                  * masterAxis->mat[0].y)
                                          + (float)((float)(this->current.worldOrigin.z - masterOrigin->z)
                                                  * masterAxis->mat[0].z));
      this->current.localOrigin.y = (float)((float)v8 * (float)v10) + (float)v11;
      this->current.localOrigin.z = (float)((float)v8 * (float)x) + (float)v12;
      if ( (bflags & 1) != 0 )
      {
        z = masterAxis->mat[1].z;
        v14 = masterAxis->mat[0].z;
        y = masterAxis->mat[2].y;
        v16 = masterAxis->mat[1].y;
        v17 = masterAxis->mat[0].y;
        v18 = masterAxis->mat[2].x;
        v19 = masterAxis->mat[1].x;
        v20 = masterAxis->mat[0].x;
        v22.mat[2].z = masterAxis->mat[2].z;
        v22.mat[2].y = z;
        v22.mat[2].x = v14;
        v22.mat[1].z = y;
        v22.mat[1].y = v16;
        v22.mat[1].x = v17;
        v22.mat[0].z = v18;
        v22.mat[0].y = v19;
        v22.mat[0].x = v20;
        this->current.localAxis = *idMat3::operator*(this: v23, result: &this->current.worldAxis, a: &v22);
      }
      else
      {
        this->current.localAxis = this->current.worldAxis;
      }
      this->current.linearExtrapolation.startValue.x = p_localOrigin->x;
      this->current.linearExtrapolation.startValue.y = p_localOrigin->y;
      this->current.linearExtrapolation.startValue.z = p_localOrigin->z;
      this->current.linearExtrapolation.currentTime = -1.0;
      this->current.angularExtrapolationStartAxis.mat[0].x = this->current.localAxis.mat[0].x;
      this->current.angularExtrapolationStartAxis.mat[0].y = this->current.localAxis.mat[0].y;
      this->current.angularExtrapolationStartAxis.mat[0].z = this->current.localAxis.mat[0].z;
      this->current.angularExtrapolationStartAxis.mat[1].x = this->current.localAxis.mat[1].x;
      this->current.angularExtrapolationStartAxis.mat[1].y = this->current.localAxis.mat[1].y;
      this->current.angularExtrapolationStartAxis.mat[1].z = this->current.localAxis.mat[1].z;
      this->current.angularExtrapolationStartAxis.mat[2].x = this->current.localAxis.mat[2].x;
      this->current.angularExtrapolationStartAxis.mat[2].y = this->current.localAxis.mat[2].y;
      this->current.angularExtrapolationStartAxis.mat[2].z = this->current.localAxis.mat[2].z;
      this->hasMaster = true;
      this->isOrientated = v6;
    }
  }
  else if ( this->hasMaster )
  {
    this->current.localOrigin = this->current.worldOrigin;
    this->current.localAxis = this->current.worldAxis;
    idPhysics_ParametricMM::SetLinearExtrapolation(
      this,
      type: EXTRAPOLATION_NONE,
      currentTime: this->current.time,
      duration: (unsigned int)&this->current.worldOrigin,
      base: &vec3_origin,
      speed: &vec3_origin);
    LODWORD(v21) = 0x82000000;
    HIDWORD(v21) = &vec3_origin;
    idPhysics_ParametricMM::SetAngularExtrapolation(
      this,
      type: EXTRAPOLATION_NONE,
      currentTime: this->current.time,
      time: 0,
      duration: 0,
      base: &this->current.worldAxis,
      vec: v21,
      speed: 0.0);
    this->hasMaster = false;
  }
}


// ========================================================================
// ?SetLinearExtrapolation@idPhysics_Parametric@@QAAXW4extrapolation_t@@HHHABVidVec3@@11@Z
// EA  : 0x8274C748
// RVA : 0x0074C748
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetLinearExtrapolation(
        idPhysics_Parametric *this,
        extrapolation_t type,
        int currentTime,
        __int64 duration,
        const idVec3 *base,
        const idVec3 *speed)
{
  __int64 baseSpeed; // r11

  LODWORD(baseSpeed) = duration;
  this->current.time = currentTime;
  LODWORD(duration) = HIDWORD(duration);
  this->current.linearExtrapolation.extrapolationType = type;
  this->current.linearExtrapolation.duration = (float)baseSpeed;
  this->current.linearExtrapolation.startTime = (float)duration;
  this->current.linearExtrapolation.startValue = *base;
  this->current.linearExtrapolation.baseSpeed = *(idVec3 *)HIDWORD(baseSpeed);
  this->current.linearExtrapolation.speed = *speed;
  this->current.linearExtrapolation.currentTime = -1.0;
  this->current.linearExtrapolation.currentValue = *base;
  this->current.localOrigin = *base;
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetAngularExtrapolation@idPhysics_Parametric@@QAAXW4extrapolation_t@@HHHABVidAngles@@11@Z
// EA  : 0x8274C840
// RVA : 0x0074C840
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetAngularExtrapolation(
        idPhysics_Parametric *this,
        extrapolation_t type,
        int currentTime,
        __int64 duration,
        const idAngles *base,
        const idAngles *speed)
{
  __int64 baseSpeed; // r11

  LODWORD(baseSpeed) = duration;
  this->current.time = currentTime;
  LODWORD(duration) = HIDWORD(duration);
  this->current.angularExtrapolation.extrapolationType = type;
  this->current.angularExtrapolation.duration = (float)baseSpeed;
  this->current.angularExtrapolation.startTime = (float)duration;
  this->current.angularExtrapolation.startValue = *base;
  this->current.angularExtrapolation.baseSpeed = *(idAngles *)HIDWORD(baseSpeed);
  this->current.angularExtrapolation.speed = *speed;
  this->current.angularExtrapolation.currentTime = -1.0;
  this->current.angularExtrapolation.currentValue = *base;
  this->current.localAngles = *base;
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?GetCurrentAngularExtrapolationAngles@idPhysics_Parametric@@QBA?AVidAngles@@H@Z
// EA  : 0x8274C938
// RVA : 0x0074C938
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idPhysics_Parametric *__fastcall idPhysics_Parametric::GetCurrentAngularExtrapolationAngles(
        idPhysics_Parametric *this,
        idAngles *result,
        const int time)
{
  __int64 v3; // r11

  LODWORD(v3) = time;
  idExtrapolate<idAngles>::GetCurrentValue((idExtrapolate<idAngles> *)this, result: result + 23, time: (float)v3);
  return this;
}


// ========================================================================
// ?SetLinearInterpolation@idPhysics_Parametric@@QAAXHHHHHABVidVec3@@0@Z
// EA  : 0x8274C980
// RVA : 0x0074C980
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysics_Parametric::SetLinearInterpolation(
        idPhysics_Parametric *this,
        const idAngles *currentTime,
        __int64 accelTime,
        int decelTime,
        __int64 startPos)
{
  __int64 endPos; // r11
  idAngles *v6; // r30
  int v7; // r7

  LODWORD(endPos) = decelTime;
  this->current.time = (int)currentTime;
  v6 = (idAngles *)startPos;
  v7 = HIDWORD(accelTime);
  LODWORD(startPos) = accelTime;
  LODWORD(accelTime) = HIDWORD(startPos);
  idInterpolateAccelDecelLinear<idAngles>::Init(
    this: (idInterpolateAccelDecelLinear<idAngles> *)&this->current.linearInterpolation,
    startTime: (float)*(__int64 *)((char *)&accelTime - 4),
    accelTime: (float)startPos,
    decelTime: (float)endPos,
    duration: (float)accelTime,
    startValue: currentTime,
    endValue: (const idAngles *)HIDWORD(accelTime),
    a8: SHIDWORD(startPos),
    a9: SHIDWORD(accelTime),
    a10: v6,
    a11: (idAngles *)HIDWORD(endPos));
  this->current.localOrigin = *(idVec3 *)v6;
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetAngularInterpolation@idPhysics_Parametric@@QAAXHHHHHABVidAngles@@0@Z
// EA  : 0x8274CA48
// RVA : 0x0074CA48
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysics_Parametric::SetAngularInterpolation(
        idPhysics_Parametric *this,
        const idAngles *currentTime,
        __int64 accelTime,
        int decelTime,
        __int64 startAng)
{
  __int64 endAng; // r11
  idAngles *v6; // r30
  int v7; // r7

  LODWORD(endAng) = decelTime;
  this->current.time = (int)currentTime;
  v6 = (idAngles *)startAng;
  v7 = HIDWORD(accelTime);
  LODWORD(startAng) = accelTime;
  LODWORD(accelTime) = HIDWORD(startAng);
  idInterpolateAccelDecelLinear<idAngles>::Init(
    this: &this->current.angularInterpolation,
    startTime: (float)*(__int64 *)((char *)&accelTime - 4),
    accelTime: (float)startAng,
    decelTime: (float)endAng,
    duration: (float)accelTime,
    startValue: currentTime,
    endValue: (const idAngles *)HIDWORD(accelTime),
    a8: SHIDWORD(startAng),
    a9: SHIDWORD(accelTime),
    a10: v6,
    a11: (idAngles *)HIDWORD(endAng));
  this->current.localAngles = *v6;
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetSpline@idPhysics_Parametric@@QAAXPAV?$idCurve_Spline@VidVec3@@@@HH_NPAV?$idCurve_Spline@VidAngles@@@@@Z
// EA  : 0x8274CB10
// RVA : 0x0074CB10
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetSpline(
        idPhysics_Parametric *this,
        idCurve_Spline<idVec3> *spline,
        unsigned int accelTime,
        const float *decelTime,
        bool useSplineAngles,
        idCurve_Spline<idAngles> *angularSpline)
{
  idCurve_Spline<idVec3> *v7; // r3
  float *list; // r11
  double v14; // fp31
  double v15; // fp30
  __int64 v16; // r4
  int v17; // r7
  float v18[2]; // [sp+50h] [-60h] BYREF
  float v19[4]; // [sp+58h] [-58h] BYREF

  v7 = this->current.spline;
  if ( v7 != nullptr )
  {
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))v7->dtr_idCurve<idVec3>)(a1: v7, a2: 1);
    this->current.spline = nullptr;
  }
  this->current.spline = spline;
  this->current.angularSpline = angularSpline;
  if ( spline != nullptr )
  {
    list = spline->times.list;
    v14 = *list;
    v15 = list[spline->values.num - 1];
    v18[0] = spline->GetLengthForTime(this: spline, a2: v15);
    LODWORD(v16) = decelTime;
    LODWORD(v19[1]) = decelTime;
    v19[0] = 0.0;
    idInterpolateAccelDecelLinear<float>::Init(
      this: &this->current.splineInterpolate,
      startTime: v14,
      accelTime: (float)__SPAIR64__(0x82000000, accelTime),
      decelTime: (float)v16,
      duration: (float)((float)v15 - (float)v14),
      startValue: decelTime,
      endValue: (const float *)0x82000000,
      a8: accelTime,
      a9: v17,
      a10: v19,
      a11: v18);
  }
  this->current.useSplineAngles = useSplineAngles;
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SaveState@idPhysics_Parametric@@UAAXXZ
// EA  : 0x8274CC20
// RVA : 0x0074CC20
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SaveState(idPhysics_Parametric *this)
{
  parametricPState_t::operator=(this: &this->saved, __that: &this->current);
}


// ========================================================================
// ?RestoreState@idPhysics_Parametric@@UAAXXZ
// EA  : 0x8274CC30
// RVA : 0x0074CC30
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::RestoreState(idPhysics_Parametric *this)
{
  idClipModel *clipModel; // r3

  parametricPState_t::operator=(this: &this->current, __that: &this->saved);
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ?SetLinearVelocity@idPhysics_Parametric@@UAAXABVidVec3@@H@Z
// EA  : 0x8274CC88
// RVA : 0x0074CC88
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetLinearVelocity(
        idPhysics_Parametric *this,
        const idVec3 *newLinearVelocity,
        int id)
{
  int v4; // r7
  int v5; // r6
  const idAngles *v6; // r5
  const idAngles *v7; // r4

  idPhysics_Parametric::SetLinearExtrapolation(
    this,
    type: EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP,
    currentTime: this->current.time,
    duration: (unsigned int)&this->current.worldOrigin,
    base: newLinearVelocity,
    speed: &vec3_origin);
  idInterpolateAccelDecelLinear<idAngles>::Init(
    this: (idInterpolateAccelDecelLinear<idAngles> *)&this->current.linearInterpolation,
    startTime: 0.0,
    accelTime: 0.0,
    decelTime: 0.0,
    duration: 0.0,
    startValue: v7,
    endValue: v6,
    a8: v5,
    a9: v4,
    a10: (idAngles *)&vec3_origin,
    a11: (idAngles *)&vec3_origin);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetAngularVelocity@idPhysics_Parametric@@UAAXABVidVec3@@H@Z
// EA  : 0x8274CD20
// RVA : 0x0074CD20
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetAngularVelocity(
        idPhysics_Parametric *this,
        const idVec3 *newAngularVelocity,
        int id)
{
  float x; // r6
  int time; // r30
  double v8; // fp4
  double v9; // fp4
  const idAngles *v10; // r3
  int v11; // r7
  const idAngles *v12; // r5
  const idAngles *v13; // r4
  float y; // [sp+54h] [-8Ch]
  float z; // [sp+58h] [-88h]
  idRotation v16; // [sp+60h] [-80h] BYREF
  float v17; // [sp+A4h] [-3Ch]
  float v18; // [sp+A8h] [-38h]
  float v19; // [sp+ACh] [-34h]
  char v20; // [sp+B0h] [-30h]

  x = newAngularVelocity->x;
  time = this->current.time;
  y = newAngularVelocity->y;
  z = newAngularVelocity->z;
  v16.vec.y = vec3_origin.x;
  v16.vec.z = vec3_origin.y;
  v16.axis.mat[1].y = mat3_identity.mat[0].x;
  v16.angle = vec3_origin.z;
  v20 = 0;
  v16.axis.mat[2].x = mat3_identity.mat[0].z;
  v16.axis.mat[1].z = mat3_identity.mat[0].y;
  v16.axis.mat[2].y = mat3_identity.mat[1].x;
  v16.axis.mat[2].z = mat3_identity.mat[1].y;
  v17 = mat3_identity.mat[2].x;
  v18 = mat3_identity.mat[2].y;
  v19 = mat3_identity.mat[2].z;
  *(float *)&v16.axisValid = mat3_identity.mat[1].z;
  _FP7 = (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y))) - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f5, f7, f8, f13 }
  v8 = __frsqrte(_FP5);
  v9 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v8
                                                                                     * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y)))
                                                                                             * (float)0.5))
                                                                             * (float)v8)
                                                                     - (float)1.5)
                                                     * (float)v8)
                                             * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y)))
                                                     * (float)0.5))
                                     * (float)((float)-(float)((float)((float)((float)v8
                                                                             * (float)((float)((float)(x * x)
                                                                                             + (float)((float)(z * z) + (float)(y * y)))
                                                                                     * (float)0.5))
                                                                     * (float)v8)
                                                             - (float)1.5)
                                             * (float)v8))
                             - (float)1.5)
             * (float)((float)-(float)((float)((float)((float)v8
                                                     * (float)((float)((float)(x * x)
                                                                     + (float)((float)(z * z) + (float)(y * y)))
                                                             * (float)0.5))
                                             * (float)v8)
                                     - (float)1.5)
                     * (float)v8));
  v16.axis.mat[0].x = x
                    * (float)((float)-(float)((float)((float)((float)v9
                                                            * (float)((float)((float)(x * x)
                                                                            + (float)((float)(z * z) + (float)(y * y)))
                                                                    * (float)0.5))
                                                    * (float)v9)
                                            - (float)1.5)
                            * (float)v9);
  v16.axis.mat[0].y = y
                    * (float)((float)-(float)((float)((float)((float)v9
                                                            * (float)((float)((float)(x * x)
                                                                            + (float)((float)(z * z) + (float)(y * y)))
                                                                    * (float)0.5))
                                                    * (float)v9)
                                            - (float)1.5)
                            * (float)v9);
  v16.axis.mat[0].z = z
                    * (float)((float)-(float)((float)((float)((float)v9
                                                            * (float)((float)((float)(x * x)
                                                                            + (float)((float)(z * z) + (float)(y * y)))
                                                                    * (float)0.5))
                                                    * (float)v9)
                                            - (float)1.5)
                            * (float)v9);
  v16.axis.mat[1].x = (float)((float)((float)-(float)((float)((float)((float)v9
                                                                    * (float)((float)((float)(x * x)
                                                                                    + (float)((float)(z * z)
                                                                                            + (float)(y * y)))
                                                                            * (float)0.5))
                                                            * (float)v9)
                                                    - (float)1.5)
                                    * (float)v9)
                            * (float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y))))
                    * idMath::M_RAD2DEG;
  v10 = idRotation::ToAngles(this: &v16, result: (idAngles *)&v16.vec.y);
  idPhysics_Parametric::SetAngularExtrapolation(
    this,
    type: EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP,
    currentTime: time,
    duration: (unsigned int)&this->current.worldAngles,
    base: v10,
    speed: &ang_zero);
  idInterpolateAccelDecelLinear<idAngles>::Init(
    this: &this->current.angularInterpolation,
    startTime: 0.0,
    accelTime: 0.0,
    decelTime: 0.0,
    duration: 0.0,
    startValue: v13,
    endValue: v12,
    a8: 0x82000000,
    a9: v11,
    a10: &ang_zero,
    a11: &ang_zero);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?GetLinearVelocity@idPhysics_Parametric@@UBA?AVidVec3@@H@Z
// EA  : 0x8274CEE0
// RVA : 0x0074CEE0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idPhysics_Parametric *__fastcall idPhysics_Parametric::GetLinearVelocity(
        idPhysics_Parametric *this,
        idVec3 *result,
        int id,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  LODWORD(a7) = LODWORD(result[10].x);
  idExtrapolate<idVec3>::GetCurrentSpeed(
    (idExtrapolate<idAngles> *)this,
    result: (idAngles *)&result[17].z,
    time: (float)a7);
  return this;
}


// ========================================================================
// ?GetAngularVelocity@idPhysics_Parametric@@UBA?AVidVec3@@H@Z
// EA  : 0x8274CF30
// RVA : 0x0074CF30
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idPhysics_Parametric *__fastcall idPhysics_Parametric::GetAngularVelocity(
        idPhysics_Parametric *this,
        idVec3 *result,
        int id,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  idVec3 v9; // [sp+50h] [-20h] BYREF

  LODWORD(a7) = LODWORD(result[10].x);
  *(_QWORD *)&v9.x = a7;
  idExtrapolate<idVec3>::GetCurrentSpeed(
    this: (idExtrapolate<idAngles> *)&v9,
    result: (idAngles *)&result[23],
    time: (float)a7);
  idAngles::ToAngularVelocity((idAngles *)this, result: &v9);
  return this;
}


// ========================================================================
// ?SetMaster@idPhysics_Parametric@@UAAX_NABVidVec3@@ABVidMat3@@W4bindFlags_t@@@Z
// EA  : 0x8274CF90
// RVA : 0x0074CF90
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetMaster(
        idPhysics_Parametric *this,
        bool enable,
        const idVec3 *masterOrigin,
        const idMat3 *masterAxis,
        const bindFlags_t bflags)
{
  bool v6; // r29
  idVec3 *p_localOrigin; // r30
  idMat3 *p_worldAxis; // r4
  double v9; // fp2
  double x; // fp7
  double v11; // fp5
  double v12; // fp1
  double v13; // fp0
  double z; // fp13
  double v15; // fp12
  double y; // fp11
  double v17; // fp10
  double v18; // fp9
  double v19; // fp8
  double v20; // fp7
  double v21; // fp6
  idAngles *v22; // r3
  idAngles *v23; // r3
  idMat3 v24; // [sp+50h] [-90h] BYREF
  float v25; // [sp+74h] [-6Ch]
  float v26; // [sp+78h] [-68h]
  float v27; // [sp+7Ch] [-64h]
  float v28; // [sp+80h] [-60h]
  idMat3 v29[2]; // [sp+90h] [-50h] BYREF

  if ( enable )
  {
    if ( !this->hasMaster )
    {
      v6 = bflags & 1;
      p_localOrigin = &this->current.localOrigin;
      p_worldAxis = &this->current.worldAxis;
      v9 = (float)(this->current.worldOrigin.x - masterOrigin->x);
      x = masterAxis->mat[2].x;
      v11 = masterAxis->mat[1].x;
      v12 = (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y) * masterAxis->mat[1].y)
                  + (float)((float)(this->current.worldOrigin.z - masterOrigin->z) * masterAxis->mat[1].z));
      v13 = (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y) * masterAxis->mat[2].y)
                  + (float)((float)(this->current.worldOrigin.z - masterOrigin->z) * masterAxis->mat[2].z));
      this->current.localOrigin.x = (float)((float)(this->current.worldOrigin.x - masterOrigin->x) * masterAxis->mat[0].x)
                                  + (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y)
                                                  * masterAxis->mat[0].y)
                                          + (float)((float)(this->current.worldOrigin.z - masterOrigin->z)
                                                  * masterAxis->mat[0].z));
      this->current.localOrigin.y = (float)((float)v9 * (float)v11) + (float)v12;
      this->current.localOrigin.z = (float)((float)v9 * (float)x) + (float)v13;
      if ( (bflags & 1) != 0 )
      {
        z = masterAxis->mat[1].z;
        v15 = masterAxis->mat[0].z;
        y = masterAxis->mat[2].y;
        v17 = masterAxis->mat[1].y;
        v18 = masterAxis->mat[0].y;
        v19 = masterAxis->mat[2].x;
        v20 = masterAxis->mat[1].x;
        v21 = masterAxis->mat[0].x;
        v28 = masterAxis->mat[2].z;
        v27 = z;
        v26 = v15;
        v25 = y;
        v24.mat[2].z = v17;
        v24.mat[2].y = v18;
        v24.mat[2].x = v19;
        v24.mat[1].z = v20;
        v24.mat[1].y = v21;
        v22 = (idAngles *)idMat3::operator*(this: v29, result: p_worldAxis, a: (idMat3 *)&v24.mat[1].y);
        v23 = idMat3::ToAngles(this: &v24, result: v22);
      }
      else
      {
        v23 = idMat3::ToAngles(this: &v24, result: (idAngles *)p_worldAxis);
      }
      this->current.localAngles.pitch = v23->pitch;
      this->current.localAngles.yaw = v23->yaw;
      this->current.localAngles.roll = v23->roll;
      this->current.linearExtrapolation.startValue.x = p_localOrigin->x;
      this->current.linearExtrapolation.startValue.y = p_localOrigin->y;
      this->current.linearExtrapolation.startValue.z = p_localOrigin->z;
      this->current.linearExtrapolation.currentTime = -1.0;
      this->current.angularExtrapolation.startValue.pitch = this->current.localAngles.pitch;
      this->current.angularExtrapolation.startValue.yaw = this->current.localAngles.yaw;
      this->current.angularExtrapolation.startValue.roll = this->current.localAngles.roll;
      this->current.angularExtrapolation.currentTime = -1.0;
      this->hasMaster = true;
      this->isOrientated = v6;
    }
  }
  else if ( this->hasMaster )
  {
    this->current.localOrigin = this->current.worldOrigin;
    this->current.localAngles = this->current.worldAngles;
    idPhysics_Parametric::SetLinearExtrapolation(
      this,
      type: EXTRAPOLATION_NONE,
      currentTime: this->current.time,
      duration: (unsigned int)&this->current.worldOrigin,
      base: &vec3_origin,
      speed: &vec3_origin);
    idPhysics_Parametric::SetAngularExtrapolation(
      this,
      type: EXTRAPOLATION_NONE,
      currentTime: this->current.time,
      duration: (unsigned int)&this->current.worldAngles,
      base: &ang_zero,
      speed: &ang_zero);
    this->hasMaster = false;
  }
}


// ========================================================================
// ?GetLinearEndTime@idPhysics_Parametric@@UBAHXZ
// EA  : 0x8274D1E0
// RVA : 0x0074D1E0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_Parametric::GetLinearEndTime(idPhysics_Parametric *this)
{
  idCurve_Spline<idVec3> *spline; // r11
  double v4; // fp0

  spline = this->current.spline;
  if ( spline != nullptr )
  {
    if ( ((int (*)(void))spline->GetBoundaryType)() == 2 )
      return 0;
    else
      return (int)this->current.spline->times.list[this->current.spline->values.num - 1];
  }
  else
  {
    v4 = 0.0;
    if ( (float)((float)(this->current.linearInterpolation.decelTime + this->current.linearInterpolation.linearTime)
               + this->current.linearInterpolation.accelTime) == 0.0 )
    {
      if ( (this->current.linearExtrapolation.extrapolationType & 0x40) == 0
        && this->current.linearExtrapolation.duration > 0.0 )
      {
        return (int)(float)(this->current.linearExtrapolation.startTime + this->current.linearExtrapolation.duration);
      }
      return (int)v4;
    }
    else
    {
      return (int)(float)(this->current.linearInterpolation.startTime
                        + (float)((float)(this->current.linearInterpolation.decelTime
                                        + this->current.linearInterpolation.linearTime)
                                + this->current.linearInterpolation.accelTime));
    }
  }
}


// ========================================================================
// ?ClearWorldOrientation@idPhysics_Parametric@@QAAXXZ
// EA  : 0x8274D300
// RVA : 0x0074D300
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::ClearWorldOrientation(idPhysics_Parametric *this)
{
  int time; // r5

  time = this->current.time;
  this->hasWorldOrientation = false;
  idPhysics_Parametric::SetLinearExtrapolation(
    this,
    type: EXTRAPOLATION_NONE,
    currentTime: time,
    duration: (unsigned int)&this->current.worldOrigin,
    base: &vec3_origin,
    speed: &vec3_origin);
  idPhysics_Parametric::SetAngularExtrapolation(
    this,
    type: EXTRAPOLATION_NONE,
    currentTime: this->current.time,
    duration: (unsigned int)&this->current.worldAngles,
    base: &ang_zero,
    speed: &ang_zero);
}


// ========================================================================
// ??1idPhysics_ParametricMM@@UAA@XZ
// EA  : 0x8274E078
// RVA : 0x0074E078
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::~idPhysics_ParametricMM(idPhysics_ParametricMM *this)
{
  idClipModel *clipModel; // r3
  idCurve_Spline<idVec3> *spline; // r3

  this->__vftable = (idPhysics_ParametricMM_vtbl *)&idPhysics_ParametricMM::`vftable';
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
  {
    idClipModel::Delete(this: clipModel);
    this->clipModel = nullptr;
  }
  spline = this->current.spline;
  if ( spline != nullptr )
  {
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))spline->dtr_idCurve<idVec3>)(a1: spline, a2: 1);
    this->current.spline = nullptr;
  }
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->saved.splineChilds);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->current.splineChilds);
  idPhysics_DynamicBase::~idPhysics_DynamicBase(this);
}


// ========================================================================
// __unwind$259897
// EA  : 0x8274E104
// RVA : 0x0074E104
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void _unwind_259897()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$259898
// EA  : 0x8274E12C
// RVA : 0x0074E12C
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void _unwind_259898()
{
  int v0; // r12

  parametricPState_tMM::~parametricPState_tMM(this: (parametricPState_tMM *)(*(_DWORD *)(v0 - 128 + 148) + 120));
}


// ========================================================================
// __unwind$259899
// EA  : 0x8274E158
// RVA : 0x0074E158
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void _unwind_259899()
{
  int v0; // r12

  parametricPState_tMM::~parametricPState_tMM(this: (parametricPState_tMM *)(*(_DWORD *)(v0 - 128 + 148) + 992));
}


// ========================================================================
// ?SetSplineTimes@idPhysics_ParametricMM@@QAAXHM@Z
// EA  : 0x8274E188
// RVA : 0x0074E188
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetSplineTimes(
        idPhysics_ParametricMM *this,
        const float *time,
        double endPos,
        const float *a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        int a13,
        __int64 a14,
        float a15,
        float a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22)
{
  idCurve_Spline<idVec3> *spline; // r11
  double totalLength; // fp27
  __int64 v26; // r11
  double v27; // fp0
  double v28; // fp31
  double v29; // fp1
  double CurrentSpeed; // fp29
  double CurrentValue; // fp30
  double v32; // fp1
  double v33; // fp31
  const char *v34; // r3
  _QWORD v35[8]; // [sp+50h] [-60h] BYREF

  spline = this->current.spline;
  a22 = endPos;
  totalLength = endPos;
  if ( spline == nullptr )
    idLib::Warning(fmt: "idPhysics_Parametric::SetSplineTimes called when no valid spline is present!");
  HIDWORD(v26) = 0x82000000;
  LODWORD(a14) = this->current.time;
  v27 = (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime);
  v35[0] = a14;
  v28 = (float)a14;
  if ( v28 >= 0.0 )
  {
    if ( v28 <= v27 )
      v29 = (float)a14;
    else
      v29 = v27;
  }
  else
  {
    v29 = 0.0;
  }
  if ( v29 < v27 )
    CurrentSpeed = idExtrapolate<float>::GetCurrentSpeed(this: &this->current.splineInterpolate.extrapolate, time: v29);
  else
    CurrentSpeed = this->current.splineInterpolate.endSpeed;
  if ( v28 < (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime) )
  {
    CurrentValue = idExtrapolate<float>::GetCurrentValue(this: &this->current.splineInterpolate.extrapolate, time: v28);
  }
  else if ( this->current.splineInterpolate.startSpeed == this->current.splineInterpolate.endSpeed )
  {
    CurrentValue = this->current.splineInterpolate.endValue;
  }
  else
  {
    CurrentValue = (float)((float)((float)((float)((float)v28
                                                 - (float)(this->current.splineInterpolate.duration
                                                         + this->current.splineInterpolate.startTime))
                                         * this->current.splineInterpolate.endSpeed)
                                 * (float)0.001)
                         + this->current.splineInterpolate.endValue);
  }
  *(float *)v35 = CurrentValue;
  if ( totalLength <= 0.0 )
  {
    totalLength = this->current.totalLength;
    a22 = this->current.totalLength;
  }
  if ( CurrentValue > totalLength )
    CurrentSpeed = __fnabs(CurrentSpeed);
  LODWORD(v26) = time;
  v32 = v28;
  v35[1] = v26;
  v33 = (float)v26;
  idInterpolateAccelLinearEx<float>::InitDuration(
    this: &this->current.splineInterpolate,
    startTime: v32,
    startSpeed: CurrentSpeed,
    duration: v33,
    startValue: time,
    endValue: a4,
    a7: a5,
    a8: (float *)v35,
    a9: &a22);
  if ( this->current.splineInterpolate.endSpeed < 0.0 )
  {
    idLib::Warning(fmt: "===================================");
    v34 = this->callbacks->GetName(this: this->callbacks);
    idLib::Warning(fmt: "Unobtainable MoveTime set on %s ", v34);
    idLib::Warning(
      fmt: (const char *)HIDWORD(CurrentSpeed),
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v33 * (float)0.001))),
      (unsigned int)COERCE_UNSIGNED_INT64((float)((float)v33 * (float)0.001)),
      (unsigned int)COERCE_UNSIGNED_INT64((float)((float)totalLength - (float)CurrentValue)),
      CurrentSpeed);
    idLib::Warning(fmt: "Without snapping our speed, we cannot travel the given distance in the given time!");
    idLib::Warning(fmt: "Increase MoveTime or slow down the current speed. ");
    idLib::Warning(fmt: "===================================");
  }
}


// ========================================================================
// ?GetSplineSpeed@idPhysics_ParametricMM@@QBAMXZ
// EA  : 0x8274E3B0
// RVA : 0x0074E3B0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

float __fastcall idPhysics_ParametricMM::GetSplineSpeed(
        idPhysics_ParametricMM *this,
        int a2,
        int a3,
        int a4,
        int a5,
        __int64 a6)
{
  double v6; // fp1
  double v7; // fp1

  LODWORD(a6) = this->current.time;
  v6 = (float)a6;
  if ( v6 < (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime) )
    v7 = __fabs(idExtrapolate<float>::GetCurrentSpeed(this: &this->current.splineInterpolate.extrapolate, time: v6));
  else
    v7 = __fabs(this->current.splineInterpolate.endSpeed);
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?TimeToLength@idPhysics_ParametricMM@@QBAMM@Z
// EA  : 0x8274E438
// RVA : 0x0074E438
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

float __fastcall idPhysics_ParametricMM::TimeToLength(
        idPhysics_ParametricMM *this,
        double length,
        int a3,
        int a4,
        int a5,
        int a6,
        __int64 a7)
{
  double v7; // fp1

  if ( (float)((float)(this->current.splineInterpolate.startSpeed * (float)2.0)
             + (float)(this->current.splineInterpolate.endSpeed - this->current.splineInterpolate.startSpeed)) == 0.0 )
  {
    v7 = 0.0;
  }
  else
  {
    LODWORD(a7) = (int)(float)((float)((float)((float)((float)length - this->current.splineInterpolate.startValue)
                                             / (float)((float)(this->current.splineInterpolate.startSpeed * (float)2.0)
                                                     + (float)(this->current.splineInterpolate.endSpeed
                                                             - this->current.splineInterpolate.startSpeed)))
                                     * (float)1000.0)
                             * (float)2.0);
    v7 = (float)a7;
  }
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?Evaluate_SplineAngles@idPhysics_ParametricMM@@AAAXHH@Z
// EA  : 0x8274E4A8
// RVA : 0x0074E4A8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::Evaluate_SplineAngles(
        idPhysics_ParametricMM *this,
        int timeStepMSec,
        int endTimeMSec)
{
  idMat3 *v4; // r3
  const idMat3 *v5; // r3
  idMat3 v6[3]; // [sp+50h] [-70h] BYREF

  if ( this->current.useSplineAngles )
    this->current.localAxis = *idVec3::ToMat3(
                                 this: (idVec3 *)&v6[0].mat[2].z,
                                 result: (idMat3 *)&this->current.splineDerivative);
  if ( this->current.splineAngleInterpolate.duration != 0.0 )
  {
    idInterpolate<idQuat>::GetCurrentValue(
      this: (idInterpolate<idQuat> *)&v6[0].mat[1].y,
      result: (idQuat *)&this->current.splineAngleInterpolate,
      time: this->current.length);
    v4 = (idMat3 *)idQuat::Normalize(this: (idQuat *)&v6[0].mat[1].y);
    v5 = idQuat::ToMat3(this: (idQuat *)&v6[0].mat[2].z, result: v4);
    idMat3::operator*=(this: &this->current.localAxis, a: v5);
    if ( g_debugParametricSplineAngles.valueInteger == 0 )
      return;
    idLib::Printf(
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(this->current.splineAngleInterpolate.startTime)),
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64((float)(this->current.splineAngleInterpolate.duration
                                                  + this->current.splineAngleInterpolate.startTime))),
      (float)((float)(this->current.length - this->current.splineAngleInterpolate.startTime)
            / this->current.splineAngleInterpolate.duration));
  }
  if ( g_debugParametricSplineAngles.valueInteger != 0 )
  {
    idMat3::ToAngles(this: v6, result: (idAngles *)&this->current.localAxis);
    idLib::Printf(fmt: "localAngles= <%.2f, %.2f, %.2f>\n", v6[0].mat[0].x, v6[0].mat[0].y, v6[0].mat[0].z);
  }
}


// ========================================================================
// ?SaveState@idPhysics_ParametricMM@@UAAXXZ
// EA  : 0x8274E610
// RVA : 0x0074E610
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SaveState(idPhysics_ParametricMM *this)
{
  parametricPState_tMM::operator=(this: &this->saved, __that: &this->current);
}


// ========================================================================
// ?RestoreState@idPhysics_ParametricMM@@UAAXXZ
// EA  : 0x8274E620
// RVA : 0x0074E620
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::RestoreState(idPhysics_ParametricMM *this)
{
  idClipModel *clipModel; // r3

  parametricPState_tMM::operator=(this: &this->current, __that: &this->saved);
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
}


// ========================================================================
// ?SetOrigin@idPhysics_ParametricMM@@UAAXABVidVec3@@H@Z
// EA  : 0x8274E678
// RVA : 0x0074E678
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetOrigin(idPhysics_ParametricMM *this, const idVec3 *newOrigin, int id)
{
  double v5; // fp1
  double roll; // fp6
  double v7; // fp2
  double yaw; // fp4
  double v9; // fp12
  double v10; // fp0
  double v11; // fp12
  __int64 v12; // r7
  float *CurrentValue; // r3
  double v14; // fp4
  double v15; // fp3
  idVec3 *p_worldOrigin; // r7
  double v17; // fp9
  double v18; // fp7
  double v19; // fp10
  double v20; // fp8
  double v21; // fp6
  double v22; // fp11
  double v23; // fp10
  double v24; // fp13
  double pitch; // fp12
  idInterpolateAccelDecelLinear<idVec3> *p_linearInterpolation; // r3
  double v27; // fp10
  double v28; // fp8
  double z; // fp9
  double x; // fp3
  double v31; // fp1
  double v32; // fp12
  double v33; // fp0
  double v34; // fp12
  __int64 v35; // r8
  float *v36; // r3
  double v37; // fp9
  double v38; // fp5
  double v39; // fp12
  double y; // fp10
  double v41; // fp4
  double v42; // fp0
  double v43; // fp1
  double v44; // fp2
  double v45; // fp8
  float v46; // r8
  float v47; // r11
  double v48; // fp12
  __int64 v49; // r6
  float *v50; // r3
  double v51; // fp8
  idClipModel *clipModel; // r3
  idExtrapolate<idAngles> v53; // [sp+50h] [-70h] BYREF
  float v54; // [sp+90h] [-30h]

  if ( this->hasMaster )
  {
    this->callbacks->GetMasterPosition(
      this: this->callbacks,
      a2: (idVec3 *)&v53.startValue.yaw,
      a3: (idMat3 *)&v53.baseSpeed.roll);
    v5 = (float)(newOrigin->x - v53.startValue.yaw);
    roll = v53.speed.roll;
    v7 = (float)((float)(v53.currentTime * (float)(newOrigin->y - v53.startValue.roll))
               + (float)(v53.currentValue.pitch * (float)(newOrigin->z - v53.baseSpeed.pitch)));
    yaw = v53.currentValue.yaw;
    v9 = (float)((float)(v53.currentValue.roll * (float)(newOrigin->y - v53.startValue.roll))
               + (float)(v54 * (float)(newOrigin->z - v53.baseSpeed.pitch)));
    v10 = (float)((float)(v53.baseSpeed.roll * (float)(newOrigin->x - v53.startValue.yaw))
                + (float)((float)(v53.speed.pitch * (float)(newOrigin->y - v53.startValue.roll))
                        + (float)(v53.speed.yaw * (float)(newOrigin->z - v53.baseSpeed.pitch))));
    this->current.linearExtrapolation.startValue.x = (float)(v53.baseSpeed.roll
                                                           * (float)(newOrigin->x - v53.startValue.yaw))
                                                   + (float)((float)(v53.speed.pitch
                                                                   * (float)(newOrigin->y - v53.startValue.roll))
                                                           + (float)(v53.speed.yaw
                                                                   * (float)(newOrigin->z - v53.baseSpeed.pitch)));
    this->current.linearExtrapolation.startValue.y = (float)((float)roll * (float)v5) + (float)v7;
    v11 = (float)((float)((float)yaw * (float)v5) + (float)v9);
    this->current.linearExtrapolation.startValue.z = v11;
    *(float *)&v53.extrapolationType = v10;
    v53.startTime = (float)((float)roll * (float)v5) + (float)v7;
    v53.duration = v11;
    this->current.linearExtrapolation.currentTime = -1.0;
    idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
      this: (idInterpolateAccelDecelLinear<idAngles> *)&this->current.linearInterpolation,
      startValue: (const idAngles *)&v53);
    LODWORD(v12) = this->current.time;
    *(_QWORD *)&v53.extrapolationType = v12;
    CurrentValue = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                              this: &v53,
                              result: (idAngles *)&this->current.linearExtrapolation,
                              time: (float)v12);
    v14 = *CurrentValue;
    this->current.localOrigin.x = *CurrentValue;
    v15 = CurrentValue[1];
    p_worldOrigin = &this->current.worldOrigin;
    this->current.localOrigin.y = CurrentValue[1];
    v17 = (float)(v54 * CurrentValue[2]);
    v18 = (float)((float)(v53.speed.pitch * (float)v14) + (float)(v53.currentValue.roll * CurrentValue[2]));
    v19 = v53.speed.yaw;
    v20 = (float)((float)(v53.currentValue.yaw * CurrentValue[2]) + (float)(v53.speed.roll * (float)v15));
    v21 = v53.baseSpeed.roll;
    this->current.localOrigin.z = CurrentValue[2];
    v22 = (float)((float)(v53.currentTime * (float)v15) + (float)v18);
    v23 = (float)((float)(v53.currentValue.pitch * (float)v15) + (float)((float)((float)v19 * (float)v14) + (float)v17));
    v24 = v53.startValue.roll;
    pitch = v53.baseSpeed.pitch;
    this->current.worldOrigin.x = (float)((float)((float)v14 * (float)v21) + (float)v20) + v53.startValue.yaw;
    this->current.worldOrigin.y = (float)v22 + (float)v24;
    this->current.worldOrigin.z = (float)v23 + (float)pitch;
  }
  else
  {
    p_linearInterpolation = &this->current.linearInterpolation;
    if ( this->hasWorldOrientation )
    {
      v27 = (float)(newOrigin->x - this->worldOrigin.x);
      v28 = (float)(newOrigin->z - this->worldOrigin.z);
      z = this->worldAxis.mat[2].z;
      x = this->worldAxis.mat[0].x;
      v31 = (float)((float)((float)(newOrigin->y - this->worldOrigin.y) * this->worldAxis.mat[2].y)
                  + (float)((float)(newOrigin->x - this->worldOrigin.x) * this->worldAxis.mat[2].x));
      v32 = (float)((float)((float)(newOrigin->y - this->worldOrigin.y) * this->worldAxis.mat[0].y)
                  + (float)((float)(newOrigin->z - this->worldOrigin.z) * this->worldAxis.mat[0].z));
      v33 = (float)((float)((float)(newOrigin->z - this->worldOrigin.z) * this->worldAxis.mat[1].z)
                  + (float)((float)((float)(newOrigin->y - this->worldOrigin.y) * this->worldAxis.mat[1].y)
                          + (float)((float)(newOrigin->x - this->worldOrigin.x) * this->worldAxis.mat[1].x)));
      this->current.linearExtrapolation.startValue.y = (float)((float)(newOrigin->z - this->worldOrigin.z)
                                                             * this->worldAxis.mat[1].z)
                                                     + (float)((float)((float)(newOrigin->y - this->worldOrigin.y)
                                                                     * this->worldAxis.mat[1].y)
                                                             + (float)((float)(newOrigin->x - this->worldOrigin.x)
                                                                     * this->worldAxis.mat[1].x));
      this->current.linearExtrapolation.startValue.z = (float)((float)v28 * (float)z) + (float)v31;
      v34 = (float)((float)((float)v27 * (float)x) + (float)v32);
      this->current.linearExtrapolation.startValue.x = v34;
      v53.startTime = v33;
      v53.duration = (float)((float)v28 * (float)z) + (float)v31;
      *(float *)&v53.extrapolationType = v34;
      this->current.linearExtrapolation.currentTime = -1.0;
      idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
        this: (idInterpolateAccelDecelLinear<idAngles> *)p_linearInterpolation,
        startValue: (const idAngles *)&v53);
      LODWORD(v35) = this->current.time;
      *(_QWORD *)&v53.extrapolationType = v35;
      v36 = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                       this: &v53,
                       result: (idAngles *)&this->current.linearExtrapolation,
                       time: (float)v35);
      v37 = *v36;
      this->current.localOrigin.x = *v36;
      v38 = v36[1];
      this->current.localOrigin.y = v36[1];
      p_worldOrigin = &this->current.worldOrigin;
      v39 = v36[2];
      this->current.localOrigin.z = v36[2];
      y = this->worldOrigin.y;
      v41 = (float)((float)((float)v39 * this->worldAxis.mat[2].y) + (float)(this->worldAxis.mat[0].y * (float)v37));
      v42 = this->worldAxis.mat[0].z;
      v43 = this->worldAxis.mat[1].y;
      v44 = (float)((float)((float)v38 * this->worldAxis.mat[1].z) + (float)((float)v39 * this->worldAxis.mat[2].z));
      v45 = this->worldOrigin.z;
      this->current.worldOrigin.x = (float)((float)(this->worldAxis.mat[0].x * (float)v37)
                                          + (float)((float)((float)v38 * this->worldAxis.mat[1].x)
                                                  + (float)(this->worldAxis.mat[2].x * (float)v39)))
                                  + this->worldOrigin.x;
      this->current.worldOrigin.y = (float)y + (float)((float)((float)v43 * (float)v38) + (float)v41);
      this->current.worldOrigin.z = (float)v45 + (float)((float)((float)v42 * (float)v37) + (float)v44);
    }
    else
    {
      v46 = newOrigin->y;
      v47 = newOrigin->z;
      v53.extrapolationType = LODWORD(newOrigin->x);
      v48 = *(float *)&v53.extrapolationType;
      v53.startTime = v46;
      v53.duration = v47;
      this->current.linearExtrapolation.startValue.z = v47;
      this->current.linearExtrapolation.startValue.y = v46;
      this->current.linearExtrapolation.startValue.x = v48;
      this->current.linearExtrapolation.currentTime = -1.0;
      idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
        this: (idInterpolateAccelDecelLinear<idAngles> *)p_linearInterpolation,
        startValue: (const idAngles *)&v53);
      LODWORD(v49) = this->current.time;
      *(_QWORD *)&v53.extrapolationType = v49;
      v50 = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                       this: &v53,
                       result: (idAngles *)&this->current.linearExtrapolation,
                       time: (float)v49);
      v51 = *v50;
      this->current.localOrigin.x = *v50;
      p_worldOrigin = &this->current.worldOrigin;
      this->current.localOrigin.y = v50[1];
      this->current.localOrigin.z = v50[2];
      this->current.worldOrigin.x = v51;
      this->current.worldOrigin.y = this->current.localOrigin.y;
      this->current.worldOrigin.z = this->current.localOrigin.z;
    }
  }
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: p_worldOrigin,
      newAxis: &this->current.worldAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetAngularVelocity@idPhysics_ParametricMM@@UAAXABVidVec3@@H@Z
// EA  : 0x8274EA60
// RVA : 0x0074EA60
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetAngularVelocity(
        idPhysics_ParametricMM *this,
        const idVec3 *newAngularVelocity,
        int id)
{
  __int64 v3; // r10
  float x; // r9
  float y; // r6
  int time; // r30
  double v8; // fp6
  double v11; // fp2
  double v12; // fp2
  int v13; // r7
  int v14; // r6
  const idQuat *v15; // r5
  const idQuat *v16; // r4
  float v17[2]; // [sp+50h] [-30h] BYREF
  float z; // [sp+58h] [-28h]

  LODWORD(v3) = &si_vector_decode_cat_0[184];
  x = newAngularVelocity->x;
  y = newAngularVelocity->y;
  time = this->current.time;
  z = newAngularVelocity->z;
  v8 = (float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y)));
  _FP5 = (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y))) - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v11 = __frsqrte(_FP3);
  v12 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v11
                                                                                      * (float)((float)v8 * (float)0.5))
                                                                              * (float)v11)
                                                                      - (float)1.5)
                                                      * (float)v11)
                                              * (float)((float)v8 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v11
                                                                              * (float)((float)v8 * (float)0.5))
                                                                      * (float)v11)
                                                              - (float)1.5)
                                              * (float)v11))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v11 * (float)((float)v8 * (float)0.5)) * (float)v11)
                                      - (float)1.5)
                      * (float)v11));
  v17[0] = x
         * (float)((float)-(float)((float)((float)((float)v12
                                                 * (float)((float)((float)(x * x)
                                                                 + (float)((float)(z * z) + (float)(y * y)))
                                                         * (float)0.5))
                                         * (float)v12)
                                 - (float)1.5)
                 * (float)v12);
  v17[1] = y
         * (float)((float)-(float)((float)((float)((float)v12
                                                 * (float)((float)((float)(x * x)
                                                                 + (float)((float)(z * z) + (float)(y * y)))
                                                         * (float)0.5))
                                         * (float)v12)
                                 - (float)1.5)
                 * (float)v12);
  z = z
    * (float)((float)-(float)((float)((float)((float)v12
                                            * (float)((float)((float)(x * x) + (float)((float)(z * z) + (float)(y * y)))
                                                    * (float)0.5))
                                    * (float)v12)
                            - (float)1.5)
            * (float)v12);
  HIDWORD(v3) = v17;
  idPhysics_ParametricMM::SetAngularExtrapolation(
    this,
    type: EXTRAPOLATION_LINEAR|EXTRAPOLATION_NOSTOP,
    currentTime: time,
    time,
    duration: 0,
    base: &this->current.worldAxis,
    vec: v3,
    speed: (float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)((float)v8 * (float)0.5)) * (float)v12)
                                          - (float)1.5)
                          * (float)v12)
                  * (float)v8)
          * idMath::M_RAD2DEG));
  idInterpolateAccelDecelLinear<idQuat>::Init(
    this: &this->current.angularInterpolation,
    startTime: 0.0,
    accelTime: 0.0,
    decelTime: 0.0,
    duration: 0.0,
    startValue: v16,
    endValue: v15,
    a8: v14,
    a9: v13,
    a10: &quat_identity,
    a11: &quat_identity);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetLocalOrigin@idPhysics_ParametricMM@@UAAXABVidVec3@@H@Z
// EA  : 0x8274EB98
// RVA : 0x0074EB98
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetLocalOrigin(idPhysics_ParametricMM *this, const idVec3 *newOrigin, int id)
{
  idAngles *p_linearExtrapolation; // r30
  __int64 v5; // r9
  float *CurrentValue; // r3
  double roll; // fp9
  double pitch; // fp5
  double v9; // fp2
  double v10; // fp1
  double v11; // fp12
  double y; // fp10
  double z; // fp8
  double v14; // fp6
  double v15; // fp5
  idClipModel *clipModel; // r3
  idExtrapolate<idAngles> v17; // [sp+50h] [-60h] BYREF
  float v18; // [sp+90h] [-20h]

  this->current.linearExtrapolation.startValue = *newOrigin;
  p_linearExtrapolation = (idAngles *)&this->current.linearExtrapolation;
  this->current.linearExtrapolation.currentTime = -1.0;
  idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
    this: (idInterpolateAccelDecelLinear<idAngles> *)&this->current.linearInterpolation,
    startValue: (const idAngles *)newOrigin);
  LODWORD(v5) = this->current.time;
  *(_QWORD *)&v17.extrapolationType = v5;
  CurrentValue = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                            this: &v17,
                            result: p_linearExtrapolation,
                            time: (float)v5);
  this->current.localOrigin.x = *CurrentValue;
  this->current.localOrigin.y = CurrentValue[1];
  this->current.localOrigin.z = CurrentValue[2];
  if ( this->hasMaster )
  {
    this->callbacks->GetMasterPosition(
      this: this->callbacks,
      a2: (idVec3 *)&v17.startValue.yaw,
      a3: (idMat3 *)&v17.baseSpeed.roll);
    roll = v17.startValue.roll;
    pitch = v17.baseSpeed.pitch;
    v9 = (float)((float)(this->current.localOrigin.y * v17.currentTime)
               + (float)((float)(this->current.localOrigin.x * v17.speed.pitch)
                       + (float)(this->current.localOrigin.z * v17.currentValue.roll)));
    v10 = (float)((float)(this->current.localOrigin.y * v17.currentValue.pitch)
                + (float)((float)(this->current.localOrigin.x * v17.speed.yaw)
                        + (float)(this->current.localOrigin.z * v18)));
    this->current.worldOrigin.x = (float)((float)(this->current.localOrigin.x * v17.baseSpeed.roll)
                                        + (float)((float)(this->current.localOrigin.z * v17.currentValue.yaw)
                                                + (float)(this->current.localOrigin.y * v17.speed.roll)))
                                + v17.startValue.yaw;
    this->current.worldOrigin.y = (float)roll + (float)v9;
    v11 = (float)((float)pitch + (float)v10);
  }
  else
  {
    if ( this->hasWorldOrientation )
    {
      y = this->worldOrigin.y;
      z = this->worldOrigin.z;
      v14 = (float)((float)(this->worldAxis.mat[0].y * this->current.localOrigin.x)
                  + (float)((float)(this->worldAxis.mat[1].y * this->current.localOrigin.y)
                          + (float)(this->worldAxis.mat[2].y * this->current.localOrigin.z)));
      v15 = (float)((float)(this->worldAxis.mat[0].z * this->current.localOrigin.x)
                  + (float)((float)(this->worldAxis.mat[1].z * this->current.localOrigin.y)
                          + (float)(this->worldAxis.mat[2].z * this->current.localOrigin.z)));
      this->current.worldOrigin.x = this->worldOrigin.x
                                  + (float)((float)(this->current.localOrigin.x * this->worldAxis.mat[0].x)
                                          + (float)((float)(this->worldAxis.mat[1].x * this->current.localOrigin.y)
                                                  + (float)(this->worldAxis.mat[2].x * this->current.localOrigin.z)));
      this->current.worldOrigin.y = (float)y + (float)v14;
      this->current.worldOrigin.z = (float)z + (float)v15;
      goto LABEL_7;
    }
    this->current.worldOrigin.x = this->current.localOrigin.x;
    this->current.worldOrigin.y = this->current.localOrigin.y;
    v11 = this->current.localOrigin.z;
  }
  this->current.worldOrigin.z = v11;
LABEL_7:
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?GetLinearEndTime@idPhysics_ParametricMM@@UBAHXZ
// EA  : 0x8274EDB8
// RVA : 0x0074EDB8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_ParametricMM::GetLinearEndTime(idPhysics_ParametricMM *this)
{
  idCurve_Spline<idVec3> *spline; // r11
  __int64 v3; // r10
  double v4; // fp1
  double CurrentSpeed; // fp1
  double v7; // fp0

  spline = this->current.spline;
  if ( spline != nullptr )
  {
    if ( ((int (*)(void))spline->GetBoundaryType)() != 2 )
    {
      LODWORD(v3) = this->current.time;
      v4 = (float)v3;
      if ( v4 < (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime) )
        CurrentSpeed = idExtrapolate<float>::GetCurrentSpeed(
                         this: &this->current.splineInterpolate.extrapolate,
                         time: v4);
      else
        CurrentSpeed = this->current.splineInterpolate.endSpeed;
      if ( CurrentSpeed <= 0.0 )
      {
        if ( CurrentSpeed < 0.0 && this->current.splineInterpolate.endValue <= 0.0 )
          return (int)(float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime);
      }
      else if ( this->current.splineInterpolate.endValue >= (double)this->current.totalLength )
      {
        return (int)(float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime);
      }
    }
    return 0;
  }
  else
  {
    v7 = 0.0;
    if ( (float)((float)(this->current.linearInterpolation.decelTime + this->current.linearInterpolation.linearTime)
               + this->current.linearInterpolation.accelTime) == 0.0 )
    {
      if ( (this->current.linearExtrapolation.extrapolationType & 0x40) == 0
        && this->current.linearExtrapolation.duration > 0.0 )
      {
        return (int)(float)(this->current.linearExtrapolation.startTime + this->current.linearExtrapolation.duration);
      }
      return (int)v7;
    }
    else
    {
      return (int)(float)((float)((float)(this->current.linearInterpolation.decelTime
                                        + this->current.linearInterpolation.linearTime)
                                + this->current.linearInterpolation.accelTime)
                        + this->current.linearInterpolation.startTime);
    }
  }
}


// ========================================================================
// ??0idPhysics_Parametric@@QAA@XZ
// EA  : 0x8274EF48
// RVA : 0x0074EF48
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idPhysics_Parametric *__fastcall idPhysics_Parametric::idPhysics_Parametric(idPhysics_Parametric *this)
{
  int v2; // r7
  int v3; // r6
  const idAngles *v4; // r5
  const idAngles *v5; // r4
  int v6; // r7
  int v7; // r6
  const float *v8; // r5
  const float *v9; // r4
  float v11; // [sp+50h] [-50h] BYREF
  float v12; // [sp+54h] [-4Ch] BYREF

  idPhysics_DynamicBase::idPhysics_DynamicBase(this);
  this->__vftable = (idPhysics_Parametric_vtbl *)&idPhysics_Parametric::`vftable';
  parametricPState_t::parametricPState_t(this: &this->current);
  parametricPState_t::parametricPState_t(this: &this->saved);
  this->current.time = 0;
  this->type = PHYSICS_PARAMETRIC;
  this->current.atRest = -1;
  this->current.useSplineAngles = false;
  this->current.worldOrigin.z = 0.0;
  this->current.worldOrigin.y = 0.0;
  this->current.worldOrigin.x = 0.0;
  this->current.worldAngles.roll = 0.0;
  this->current.worldAngles.yaw = 0.0;
  this->current.worldAngles.pitch = 0.0;
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
  this->current.localAngles.roll = 0.0;
  this->current.localAngles.yaw = 0.0;
  this->current.localAngles.pitch = 0.0;
  this->current.linearExtrapolation.extrapolationType = EXTRAPOLATION_NONE;
  this->current.linearExtrapolation.startTime = 0.0;
  this->current.linearExtrapolation.duration = 0.0;
  this->current.linearExtrapolation.startValue = vec3_origin;
  this->current.linearExtrapolation.baseSpeed = vec3_origin;
  this->current.linearExtrapolation.speed = vec3_origin;
  this->current.linearExtrapolation.currentTime = -1.0;
  this->current.linearExtrapolation.currentValue = vec3_origin;
  this->current.angularExtrapolation.startTime = 0.0;
  this->current.angularExtrapolation.extrapolationType = EXTRAPOLATION_NONE;
  this->current.angularExtrapolation.duration = 0.0;
  this->current.angularExtrapolation.startValue = ang_zero;
  this->current.angularExtrapolation.baseSpeed = ang_zero;
  this->current.angularExtrapolation.speed = ang_zero;
  this->current.angularExtrapolation.currentTime = -1.0;
  this->current.angularExtrapolation.currentValue = ang_zero;
  idInterpolateAccelDecelLinear<idAngles>::Init(
    this: (idInterpolateAccelDecelLinear<idAngles> *)&this->current.linearInterpolation,
    startTime: 0.0,
    accelTime: 0.0,
    decelTime: 0.0,
    duration: 0.0,
    startValue: (const idAngles *)allocationCurrent[242],
    endValue: (const idAngles *)0x82000000,
    a8: (int)allocationCurrent[242],
    a9: 0x82000000,
    a10: (idAngles *)&vec3_origin,
    a11: (idAngles *)&vec3_origin);
  idInterpolateAccelDecelLinear<idAngles>::Init(
    this: &this->current.angularInterpolation,
    startTime: 0.0,
    accelTime: 0.0,
    decelTime: 0.0,
    duration: 0.0,
    startValue: v5,
    endValue: v4,
    a8: v3,
    a9: v2,
    a10: &ang_zero,
    a11: &ang_zero);
  v11 = 0.0;
  this->current.spline = nullptr;
  v12 = 0.0;
  this->current.angularSpline = nullptr;
  idInterpolateAccelDecelLinear<float>::Init(
    this: &this->current.splineInterpolate,
    startTime: 0.0,
    accelTime: 1.0,
    decelTime: 1.0,
    duration: 2.0,
    startValue: v9,
    endValue: v8,
    a8: v7,
    a9: v6,
    a10: &v12,
    a11: &v11);
  parametricPState_t::operator=(this: &this->saved, __that: &this->current);
  this->spatialVelocity.p[5] = 0.0;
  this->spatialVelocity.p[4] = 0.0;
  this->spatialVelocity.p[3] = 0.0;
  this->spatialVelocity.p[2] = 0.0;
  this->spatialVelocity.p[1] = 0.0;
  this->spatialVelocity.p[0] = 0.0;
  this->blockingPhysicsId = -1;
  this->absBounds.b[1].z = 0.0;
  this->absBounds.b[1].y = 0.0;
  this->absBounds.b[1].x = 0.0;
  this->absBounds.b[0].z = 0.0;
  this->absBounds.b[0].y = 0.0;
  this->absBounds.b[0].x = 0.0;
  this->pusher = nullptr;
  this->isPusher = false;
  this->pushFlags = 0;
  this->clipModel = nullptr;
  this->hasMaster = false;
  this->isOrientated = false;
  this->hasWorldOrientation = false;
  this->worldAxis.mat[2].z = 1.0;
  this->worldAxis.mat[1].y = 1.0;
  this->worldAxis.mat[0].x = 1.0;
  this->worldAxis.mat[1].z = 0.0;
  this->worldAxis.mat[0].z = 0.0;
  this->worldAxis.mat[0].y = 0.0;
  this->worldAxis.mat[2].y = 0.0;
  this->worldAxis.mat[2].x = 0.0;
  this->worldAxis.mat[1].x = 0.0;
  this->worldOrigin.z = 0.0;
  this->worldOrigin.y = 0.0;
  this->worldOrigin.x = 0.0;
  return this;
}


// ========================================================================
// ?UpdateTime@idPhysics_Parametric@@UAAXH@Z
// EA  : 0x8274F220
// RVA : 0x0074F220
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::UpdateTime(idPhysics_Parametric *this, int endTimeMSec, __int64 a3)
{
  int time; // r11
  double startTime; // fp11
  idCurve_Spline<idVec3> *spline; // r11
  int v6; // r9
  int v7; // r10
  float *v8; // r8
  double startValue; // fp6
  idCurve_Spline<idAngles> *angularSpline; // r11
  int v11; // r9
  int v12; // r10
  float *v13; // r8

  time = this->current.time;
  this->current.time = endTimeMSec;
  startTime = this->current.linearExtrapolation.startTime;
  LODWORD(a3) = endTimeMSec - time;
  this->current.linearExtrapolation.currentTime = -1.0;
  this->current.linearExtrapolation.startTime = (float)startTime + (float)a3;
  this->current.angularExtrapolation.startTime = this->current.angularExtrapolation.startTime + (float)a3;
  this->current.angularExtrapolation.currentTime = -1.0;
  this->current.linearInterpolation.startTime = (float)a3 + this->current.linearInterpolation.startTime;
  this->current.linearInterpolation.extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->current.linearInterpolation.extrapolate.startTime = 0.0;
  this->current.linearInterpolation.extrapolate.duration = 0.0;
  this->current.linearInterpolation.extrapolate.startValue = this->current.linearInterpolation.extrapolate.startValue;
  this->current.linearInterpolation.extrapolate.baseSpeed = this->current.linearInterpolation.extrapolate.baseSpeed;
  this->current.linearInterpolation.extrapolate.speed = this->current.linearInterpolation.extrapolate.speed;
  this->current.linearInterpolation.extrapolate.currentTime = -1.0;
  this->current.linearInterpolation.extrapolate.currentValue = this->current.linearInterpolation.extrapolate.startValue;
  this->current.angularInterpolation.startTime = this->current.angularInterpolation.startTime + (float)a3;
  this->current.angularInterpolation.extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->current.angularInterpolation.extrapolate.startTime = 0.0;
  this->current.angularInterpolation.extrapolate.duration = 0.0;
  this->current.angularInterpolation.extrapolate.startValue = this->current.angularInterpolation.extrapolate.startValue;
  this->current.angularInterpolation.extrapolate.baseSpeed = this->current.angularInterpolation.extrapolate.baseSpeed;
  this->current.angularInterpolation.extrapolate.speed = this->current.angularInterpolation.extrapolate.speed;
  this->current.angularInterpolation.extrapolate.currentTime = -1.0;
  this->current.angularInterpolation.extrapolate.currentValue = this->current.angularInterpolation.extrapolate.startValue;
  spline = this->current.spline;
  if ( spline != nullptr )
  {
    v6 = 0;
    if ( spline->times.num > 0 )
    {
      v7 = 0;
      do
      {
        ++v6;
        v8 = &spline->times.list[v7++];
        *v8 = *v8 + (float)a3;
      }
      while ( v6 < spline->times.num );
    }
    spline->changed = true;
    this->current.splineInterpolate.startTime = (float)a3 + this->current.splineInterpolate.startTime;
    this->current.splineInterpolate.extrapolate.duration = 0.0;
    this->current.splineInterpolate.extrapolate.extrapolationType = EXTRAPOLATION_NONE;
    this->current.splineInterpolate.extrapolate.startTime = 0.0;
    startValue = this->current.splineInterpolate.extrapolate.startValue;
    this->current.splineInterpolate.extrapolate.startValue = this->current.splineInterpolate.extrapolate.startValue;
    this->current.splineInterpolate.extrapolate.baseSpeed = this->current.splineInterpolate.extrapolate.baseSpeed;
    this->current.splineInterpolate.extrapolate.speed = this->current.splineInterpolate.extrapolate.speed;
    this->current.splineInterpolate.extrapolate.currentTime = -1.0;
    this->current.splineInterpolate.extrapolate.currentValue = startValue;
    angularSpline = this->current.angularSpline;
    if ( angularSpline != nullptr )
    {
      v11 = 0;
      if ( angularSpline->times.num > 0 )
      {
        v12 = 0;
        do
        {
          ++v11;
          v13 = &angularSpline->times.list[v12++];
          *v13 = *v13 + (float)a3;
        }
        while ( v11 < angularSpline->times.num );
      }
      angularSpline->changed = true;
    }
  }
}


// ========================================================================
// ?SetOrigin@idPhysics_Parametric@@UAAXABVidVec3@@H@Z
// EA  : 0x8274F460
// RVA : 0x0074F460
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetOrigin(idPhysics_Parametric *this, const idVec3 *newOrigin, int id)
{
  double v5; // fp1
  double roll; // fp6
  double v7; // fp2
  double yaw; // fp4
  double v9; // fp12
  double v10; // fp0
  double v11; // fp12
  __int64 v12; // r7
  float *CurrentValue; // r3
  double v14; // fp4
  double v15; // fp3
  idVec3 *p_worldOrigin; // r7
  double v17; // fp9
  double v18; // fp7
  double v19; // fp10
  double v20; // fp8
  double v21; // fp6
  double v22; // fp11
  double v23; // fp10
  double v24; // fp13
  double pitch; // fp12
  idInterpolateAccelDecelLinear<idVec3> *p_linearInterpolation; // r3
  double v27; // fp10
  double v28; // fp8
  double z; // fp9
  double x; // fp3
  double v31; // fp1
  double v32; // fp12
  double v33; // fp0
  double v34; // fp12
  __int64 v35; // r8
  float *v36; // r3
  double v37; // fp9
  double v38; // fp5
  double v39; // fp12
  double y; // fp10
  double v41; // fp4
  double v42; // fp0
  double v43; // fp1
  double v44; // fp2
  double v45; // fp8
  float v46; // r8
  float v47; // r11
  double v48; // fp12
  __int64 v49; // r6
  float *v50; // r3
  double v51; // fp8
  idClipModel *clipModel; // r3
  idExtrapolate<idAngles> v53; // [sp+50h] [-70h] BYREF
  float v54; // [sp+90h] [-30h]

  if ( this->hasMaster )
  {
    this->callbacks->GetMasterPosition(
      this: this->callbacks,
      a2: (idVec3 *)&v53.startValue.yaw,
      a3: (idMat3 *)&v53.baseSpeed.roll);
    v5 = (float)(newOrigin->x - v53.startValue.yaw);
    roll = v53.speed.roll;
    v7 = (float)((float)(v53.currentTime * (float)(newOrigin->y - v53.startValue.roll))
               + (float)(v53.currentValue.pitch * (float)(newOrigin->z - v53.baseSpeed.pitch)));
    yaw = v53.currentValue.yaw;
    v9 = (float)((float)(v53.currentValue.roll * (float)(newOrigin->y - v53.startValue.roll))
               + (float)(v54 * (float)(newOrigin->z - v53.baseSpeed.pitch)));
    v10 = (float)((float)(v53.baseSpeed.roll * (float)(newOrigin->x - v53.startValue.yaw))
                + (float)((float)(v53.speed.pitch * (float)(newOrigin->y - v53.startValue.roll))
                        + (float)(v53.speed.yaw * (float)(newOrigin->z - v53.baseSpeed.pitch))));
    this->current.linearExtrapolation.startValue.x = (float)(v53.baseSpeed.roll
                                                           * (float)(newOrigin->x - v53.startValue.yaw))
                                                   + (float)((float)(v53.speed.pitch
                                                                   * (float)(newOrigin->y - v53.startValue.roll))
                                                           + (float)(v53.speed.yaw
                                                                   * (float)(newOrigin->z - v53.baseSpeed.pitch)));
    this->current.linearExtrapolation.startValue.y = (float)((float)roll * (float)v5) + (float)v7;
    v11 = (float)((float)((float)yaw * (float)v5) + (float)v9);
    this->current.linearExtrapolation.startValue.z = v11;
    *(float *)&v53.extrapolationType = v10;
    v53.startTime = (float)((float)roll * (float)v5) + (float)v7;
    v53.duration = v11;
    this->current.linearExtrapolation.currentTime = -1.0;
    idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
      this: (idInterpolateAccelDecelLinear<idAngles> *)&this->current.linearInterpolation,
      startValue: (const idAngles *)&v53);
    LODWORD(v12) = this->current.time;
    *(_QWORD *)&v53.extrapolationType = v12;
    CurrentValue = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                              this: &v53,
                              result: (idAngles *)&this->current.linearExtrapolation,
                              time: (float)v12);
    v14 = *CurrentValue;
    this->current.localOrigin.x = *CurrentValue;
    v15 = CurrentValue[1];
    p_worldOrigin = &this->current.worldOrigin;
    this->current.localOrigin.y = CurrentValue[1];
    v17 = (float)(v54 * CurrentValue[2]);
    v18 = (float)((float)(v53.speed.pitch * (float)v14) + (float)(v53.currentValue.roll * CurrentValue[2]));
    v19 = v53.speed.yaw;
    v20 = (float)((float)(v53.currentValue.yaw * CurrentValue[2]) + (float)(v53.speed.roll * (float)v15));
    v21 = v53.baseSpeed.roll;
    this->current.localOrigin.z = CurrentValue[2];
    v22 = (float)((float)(v53.currentTime * (float)v15) + (float)v18);
    v23 = (float)((float)(v53.currentValue.pitch * (float)v15) + (float)((float)((float)v19 * (float)v14) + (float)v17));
    v24 = v53.startValue.roll;
    pitch = v53.baseSpeed.pitch;
    this->current.worldOrigin.x = (float)((float)((float)v14 * (float)v21) + (float)v20) + v53.startValue.yaw;
    this->current.worldOrigin.y = (float)v22 + (float)v24;
    this->current.worldOrigin.z = (float)v23 + (float)pitch;
  }
  else
  {
    p_linearInterpolation = &this->current.linearInterpolation;
    if ( this->hasWorldOrientation )
    {
      v27 = (float)(newOrigin->x - this->worldOrigin.x);
      v28 = (float)(newOrigin->z - this->worldOrigin.z);
      z = this->worldAxis.mat[2].z;
      x = this->worldAxis.mat[0].x;
      v31 = (float)((float)((float)(newOrigin->y - this->worldOrigin.y) * this->worldAxis.mat[2].y)
                  + (float)((float)(newOrigin->x - this->worldOrigin.x) * this->worldAxis.mat[2].x));
      v32 = (float)((float)((float)(newOrigin->y - this->worldOrigin.y) * this->worldAxis.mat[0].y)
                  + (float)((float)(newOrigin->z - this->worldOrigin.z) * this->worldAxis.mat[0].z));
      v33 = (float)((float)((float)(newOrigin->z - this->worldOrigin.z) * this->worldAxis.mat[1].z)
                  + (float)((float)((float)(newOrigin->y - this->worldOrigin.y) * this->worldAxis.mat[1].y)
                          + (float)((float)(newOrigin->x - this->worldOrigin.x) * this->worldAxis.mat[1].x)));
      this->current.linearExtrapolation.startValue.y = (float)((float)(newOrigin->z - this->worldOrigin.z)
                                                             * this->worldAxis.mat[1].z)
                                                     + (float)((float)((float)(newOrigin->y - this->worldOrigin.y)
                                                                     * this->worldAxis.mat[1].y)
                                                             + (float)((float)(newOrigin->x - this->worldOrigin.x)
                                                                     * this->worldAxis.mat[1].x));
      this->current.linearExtrapolation.startValue.z = (float)((float)v28 * (float)z) + (float)v31;
      v34 = (float)((float)((float)v27 * (float)x) + (float)v32);
      this->current.linearExtrapolation.startValue.x = v34;
      v53.startTime = v33;
      v53.duration = (float)((float)v28 * (float)z) + (float)v31;
      *(float *)&v53.extrapolationType = v34;
      this->current.linearExtrapolation.currentTime = -1.0;
      idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
        this: (idInterpolateAccelDecelLinear<idAngles> *)p_linearInterpolation,
        startValue: (const idAngles *)&v53);
      LODWORD(v35) = this->current.time;
      *(_QWORD *)&v53.extrapolationType = v35;
      v36 = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                       this: &v53,
                       result: (idAngles *)&this->current.linearExtrapolation,
                       time: (float)v35);
      v37 = *v36;
      this->current.localOrigin.x = *v36;
      v38 = v36[1];
      this->current.localOrigin.y = v36[1];
      p_worldOrigin = &this->current.worldOrigin;
      v39 = v36[2];
      this->current.localOrigin.z = v36[2];
      y = this->worldOrigin.y;
      v41 = (float)((float)((float)v39 * this->worldAxis.mat[2].y) + (float)(this->worldAxis.mat[0].y * (float)v37));
      v42 = this->worldAxis.mat[0].z;
      v43 = this->worldAxis.mat[1].y;
      v44 = (float)((float)((float)v38 * this->worldAxis.mat[1].z) + (float)((float)v39 * this->worldAxis.mat[2].z));
      v45 = this->worldOrigin.z;
      this->current.worldOrigin.x = (float)((float)(this->worldAxis.mat[0].x * (float)v37)
                                          + (float)((float)((float)v38 * this->worldAxis.mat[1].x)
                                                  + (float)(this->worldAxis.mat[2].x * (float)v39)))
                                  + this->worldOrigin.x;
      this->current.worldOrigin.y = (float)y + (float)((float)((float)v43 * (float)v38) + (float)v41);
      this->current.worldOrigin.z = (float)v45 + (float)((float)((float)v42 * (float)v37) + (float)v44);
    }
    else
    {
      v46 = newOrigin->y;
      v47 = newOrigin->z;
      v53.extrapolationType = LODWORD(newOrigin->x);
      v48 = *(float *)&v53.extrapolationType;
      v53.startTime = v46;
      v53.duration = v47;
      this->current.linearExtrapolation.startValue.z = v47;
      this->current.linearExtrapolation.startValue.y = v46;
      this->current.linearExtrapolation.startValue.x = v48;
      this->current.linearExtrapolation.currentTime = -1.0;
      idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
        this: (idInterpolateAccelDecelLinear<idAngles> *)p_linearInterpolation,
        startValue: (const idAngles *)&v53);
      LODWORD(v49) = this->current.time;
      *(_QWORD *)&v53.extrapolationType = v49;
      v50 = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                       this: &v53,
                       result: (idAngles *)&this->current.linearExtrapolation,
                       time: (float)v49);
      v51 = *v50;
      this->current.localOrigin.x = *v50;
      p_worldOrigin = &this->current.worldOrigin;
      this->current.localOrigin.y = v50[1];
      this->current.localOrigin.z = v50[2];
      this->current.worldOrigin.x = v51;
      this->current.worldOrigin.y = this->current.localOrigin.y;
      this->current.worldOrigin.z = this->current.localOrigin.z;
    }
  }
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: p_worldOrigin,
      newAxis: &this->current.worldAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetAxis@idPhysics_Parametric@@UAAXABVidMat3@@H@Z
// EA  : 0x8274F848
// RVA : 0x0074F848
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetAxis(idPhysics_Parametric *this, idMat3 *newAxis, int id)
{
  idAngles *v5; // r3
  double z; // fp4
  double x; // fp3
  __int64 v8; // r7
  float *CurrentValue; // r3
  idMat3 *v10; // r3
  idMat3 *p_worldAxis; // r30
  double v12; // fp13
  double v13; // fp12
  double y; // fp11
  double v15; // fp10
  double v16; // fp9
  double v17; // fp8
  double v18; // fp7
  double v19; // fp6
  idAngles *v20; // r3
  double v21; // fp4
  double v22; // fp3
  __int64 v23; // r9
  float *v24; // r3
  idMat3 *v25; // r3
  double roll; // fp12
  double v27; // fp11
  __int64 v28; // r9
  float *v29; // r3
  idClipModel *clipModel; // r3
  idExtrapolate<idAngles> v31; // [sp+50h] [-100h] BYREF
  float v32; // [sp+90h] [-C0h]
  idMat3 v33; // [sp+98h] [-B8h] BYREF
  idMat3 v34; // [sp+C0h] [-90h] BYREF
  idMat3 v35; // [sp+F0h] [-60h] BYREF
  char v36; // [sp+118h] [-38h] BYREF

  if ( this->hasMaster && this->isOrientated )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v36, a3: &v34);
    v31.startValue.yaw = v34.mat[0].x;
    v31.startValue.roll = v34.mat[1].x;
    v31.baseSpeed.pitch = v34.mat[2].x;
    v31.baseSpeed.yaw = v34.mat[0].y;
    v31.baseSpeed.roll = v34.mat[1].y;
    v31.speed.pitch = v34.mat[2].y;
    v31.speed.yaw = v34.mat[0].z;
    v31.speed.roll = v34.mat[1].z;
    v31.currentTime = v34.mat[2].z;
    v5 = (idAngles *)idMat3::operator*(this: &v35, result: newAxis, a: (const idMat3 *)&v31.startValue.yaw);
    idMat3::ToAngles(this: (idMat3 *)&v33.mat[1].y, result: v5);
    z = v33.mat[1].z;
    x = v33.mat[2].x;
    this->current.angularExtrapolation.startValue.pitch = v33.mat[1].y;
    this->current.angularExtrapolation.startValue.yaw = z;
    this->current.angularExtrapolation.startValue.roll = x;
    this->current.angularExtrapolation.currentTime = -1.0;
    idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
      this: &this->current.angularInterpolation,
      startValue: (const idAngles *)&v33.mat[1].y);
    LODWORD(v8) = this->current.time;
    *(_QWORD *)&v31.extrapolationType = v8;
    CurrentValue = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                              this: &v31,
                              result: (idAngles *)&this->current.angularExtrapolation,
                              time: (float)v8);
    this->current.localAngles.pitch = *CurrentValue;
    this->current.localAngles.yaw = CurrentValue[1];
    this->current.localAngles.roll = CurrentValue[2];
    v10 = idAngles::ToMat3(this: (idAngles *)&v35, result: (idMat3 *)&this->current.localAngles);
    this->current.worldAxis = *idMat3::operator*(this: (idMat3 *)&v31.startValue.yaw, result: v10, a: &v34);
    p_worldAxis = &this->current.worldAxis;
    this->current.worldAngles = *idMat3::ToAngles(this: (idMat3 *)&v31, result: (idAngles *)&this->current.worldAxis);
  }
  else if ( this->hasWorldOrientation )
  {
    v12 = this->worldAxis.mat[1].z;
    v13 = this->worldAxis.mat[0].z;
    y = this->worldAxis.mat[2].y;
    v15 = this->worldAxis.mat[1].y;
    v16 = this->worldAxis.mat[0].y;
    v17 = this->worldAxis.mat[2].x;
    v18 = this->worldAxis.mat[1].x;
    v19 = this->worldAxis.mat[0].x;
    v31.currentTime = this->worldAxis.mat[2].z;
    v31.speed.roll = v12;
    v31.speed.yaw = v13;
    v31.speed.pitch = y;
    v31.baseSpeed.roll = v15;
    v31.baseSpeed.yaw = v16;
    v31.baseSpeed.pitch = v17;
    v31.startValue.roll = v18;
    v31.startValue.yaw = v19;
    v20 = (idAngles *)idMat3::operator*(this: &v35, result: newAxis, a: (const idMat3 *)&v31.startValue.yaw);
    idMat3::ToAngles(this: &v33, result: v20);
    v21 = v33.mat[0].y;
    v22 = v33.mat[0].z;
    this->current.angularExtrapolation.startValue.pitch = v33.mat[0].x;
    this->current.angularExtrapolation.startValue.yaw = v21;
    this->current.angularExtrapolation.startValue.roll = v22;
    this->current.angularExtrapolation.currentTime = -1.0;
    idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
      this: &this->current.angularInterpolation,
      startValue: (const idAngles *)&v33);
    LODWORD(v23) = this->current.time;
    *(_QWORD *)&v31.extrapolationType = v23;
    v24 = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                     this: &v31,
                     result: (idAngles *)&this->current.angularExtrapolation,
                     time: (float)v23);
    this->current.localAngles.pitch = *v24;
    this->current.localAngles.yaw = v24[1];
    this->current.localAngles.roll = v24[2];
    v25 = idAngles::ToMat3(this: (idAngles *)&v35, result: (idMat3 *)&this->current.localAngles);
    this->current.worldAxis = *idMat3::operator*(this: (idMat3 *)&v31.startValue.yaw, result: v25, a: &this->worldAxis);
    p_worldAxis = &this->current.worldAxis;
    this->current.worldAngles = *idMat3::ToAngles(this: (idMat3 *)&v31, result: (idAngles *)&this->current.worldAxis);
  }
  else
  {
    idMat3::ToAngles(this: (idMat3 *)&v31.currentValue.yaw, result: (idAngles *)newAxis);
    roll = v31.currentValue.roll;
    v27 = v32;
    this->current.angularExtrapolation.startValue.pitch = v31.currentValue.yaw;
    this->current.angularExtrapolation.startValue.yaw = roll;
    this->current.angularExtrapolation.startValue.roll = v27;
    this->current.angularExtrapolation.currentTime = -1.0;
    idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
      this: &this->current.angularInterpolation,
      startValue: (const idAngles *)&v31.currentValue.yaw);
    LODWORD(v28) = this->current.time;
    *(_QWORD *)&v31.extrapolationType = v28;
    v29 = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                     this: &v31,
                     result: (idAngles *)&this->current.angularExtrapolation,
                     time: (float)v28);
    this->current.localAngles.pitch = *v29;
    this->current.localAngles.yaw = v29[1];
    this->current.localAngles.roll = v29[2];
    this->current.worldAxis = *idAngles::ToMat3(this: (idAngles *)&v35, result: (idMat3 *)&this->current.localAngles);
    p_worldAxis = &this->current.worldAxis;
    this->current.worldAngles.pitch = this->current.localAngles.pitch;
    this->current.worldAngles.yaw = this->current.localAngles.yaw;
    this->current.worldAngles.roll = this->current.localAngles.roll;
  }
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: p_worldAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetLocalOrigin@idPhysics_Parametric@@UAAXABVidVec3@@H@Z
// EA  : 0x8274FCB0
// RVA : 0x0074FCB0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetLocalOrigin(idPhysics_Parametric *this, const idVec3 *newOrigin, int id)
{
  idAngles *p_linearExtrapolation; // r30
  __int64 v5; // r9
  float *CurrentValue; // r3
  double roll; // fp9
  double pitch; // fp5
  double v9; // fp2
  double v10; // fp1
  double v11; // fp12
  double y; // fp10
  double z; // fp8
  double v14; // fp6
  double v15; // fp5
  idClipModel *clipModel; // r3
  idExtrapolate<idAngles> v17; // [sp+50h] [-60h] BYREF
  float v18; // [sp+90h] [-20h]

  this->current.linearExtrapolation.startValue = *newOrigin;
  p_linearExtrapolation = (idAngles *)&this->current.linearExtrapolation;
  this->current.linearExtrapolation.currentTime = -1.0;
  idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
    this: (idInterpolateAccelDecelLinear<idAngles> *)&this->current.linearInterpolation,
    startValue: (const idAngles *)newOrigin);
  LODWORD(v5) = this->current.time;
  *(_QWORD *)&v17.extrapolationType = v5;
  CurrentValue = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                            this: &v17,
                            result: p_linearExtrapolation,
                            time: (float)v5);
  this->current.localOrigin.x = *CurrentValue;
  this->current.localOrigin.y = CurrentValue[1];
  this->current.localOrigin.z = CurrentValue[2];
  if ( this->hasMaster )
  {
    this->callbacks->GetMasterPosition(
      this: this->callbacks,
      a2: (idVec3 *)&v17.startValue.yaw,
      a3: (idMat3 *)&v17.baseSpeed.roll);
    roll = v17.startValue.roll;
    pitch = v17.baseSpeed.pitch;
    v9 = (float)((float)(this->current.localOrigin.y * v17.currentTime)
               + (float)((float)(this->current.localOrigin.x * v17.speed.pitch)
                       + (float)(this->current.localOrigin.z * v17.currentValue.roll)));
    v10 = (float)((float)(this->current.localOrigin.y * v17.currentValue.pitch)
                + (float)((float)(this->current.localOrigin.x * v17.speed.yaw)
                        + (float)(this->current.localOrigin.z * v18)));
    this->current.worldOrigin.x = (float)((float)(this->current.localOrigin.x * v17.baseSpeed.roll)
                                        + (float)((float)(this->current.localOrigin.z * v17.currentValue.yaw)
                                                + (float)(this->current.localOrigin.y * v17.speed.roll)))
                                + v17.startValue.yaw;
    this->current.worldOrigin.y = (float)roll + (float)v9;
    v11 = (float)((float)pitch + (float)v10);
  }
  else
  {
    if ( this->hasWorldOrientation )
    {
      y = this->worldOrigin.y;
      z = this->worldOrigin.z;
      v14 = (float)((float)(this->worldAxis.mat[0].y * this->current.localOrigin.x)
                  + (float)((float)(this->worldAxis.mat[1].y * this->current.localOrigin.y)
                          + (float)(this->worldAxis.mat[2].y * this->current.localOrigin.z)));
      v15 = (float)((float)(this->worldAxis.mat[0].z * this->current.localOrigin.x)
                  + (float)((float)(this->worldAxis.mat[1].z * this->current.localOrigin.y)
                          + (float)(this->worldAxis.mat[2].z * this->current.localOrigin.z)));
      this->current.worldOrigin.x = this->worldOrigin.x
                                  + (float)((float)(this->current.localOrigin.x * this->worldAxis.mat[0].x)
                                          + (float)((float)(this->worldAxis.mat[1].x * this->current.localOrigin.y)
                                                  + (float)(this->worldAxis.mat[2].x * this->current.localOrigin.z)));
      this->current.worldOrigin.y = (float)y + (float)v14;
      this->current.worldOrigin.z = (float)z + (float)v15;
      goto LABEL_7;
    }
    this->current.worldOrigin.x = this->current.localOrigin.x;
    this->current.worldOrigin.y = this->current.localOrigin.y;
    v11 = this->current.localOrigin.z;
  }
  this->current.worldOrigin.z = v11;
LABEL_7:
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->current.worldAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetLocalAxis@idPhysics_Parametric@@UAAXABVidMat3@@H@Z
// EA  : 0x8274FED0
// RVA : 0x0074FED0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetLocalAxis(idPhysics_Parametric *this, idAngles *newAxis, int id)
{
  double roll; // fp12
  double pitch; // fp11
  __int64 v6; // r9
  float *CurrentValue; // r3
  idMat3 *v8; // r3
  idMat3 *p_worldAxis; // r31
  idAngles *v10; // r3
  double v11; // fp3
  idMat3 *p_localAngles; // r4
  idMat3 *v13; // r3
  idAngles *v14; // r3
  idClipModel *clipModel; // r3
  idExtrapolate<idAngles> v16; // [sp+50h] [-E0h] BYREF
  idMat3 v17; // [sp+B0h] [-80h] BYREF
  idMat3 v18[2]; // [sp+E0h] [-50h] BYREF

  idMat3::ToAngles(this: (idMat3 *)&v16.startValue.yaw, result: newAxis);
  roll = v16.startValue.roll;
  pitch = v16.baseSpeed.pitch;
  this->current.angularExtrapolation.startValue.pitch = v16.startValue.yaw;
  this->current.angularExtrapolation.startValue.yaw = roll;
  this->current.angularExtrapolation.startValue.roll = pitch;
  this->current.angularExtrapolation.currentTime = -1.0;
  idInterpolateAccelDecelLinear<idVec3>::SetStartValue(
    this: &this->current.angularInterpolation,
    startValue: (const idAngles *)&v16.startValue.yaw);
  LODWORD(v6) = this->current.time;
  *(_QWORD *)&v16.extrapolationType = v6;
  CurrentValue = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                            this: &v16,
                            result: (idAngles *)&this->current.angularExtrapolation,
                            time: (float)v6);
  this->current.localAngles.pitch = *CurrentValue;
  this->current.localAngles.yaw = CurrentValue[1];
  this->current.localAngles.roll = CurrentValue[2];
  if ( this->hasMaster && this->isOrientated )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v16.baseSpeed.roll, a3: v18);
    v8 = idAngles::ToMat3(this: (idAngles *)&v17, result: (idMat3 *)&this->current.localAngles);
    p_worldAxis = &this->current.worldAxis;
    this->current.worldAxis = *idMat3::operator*(this: (idMat3 *)&v16.currentTime, result: v8, a: v18);
    v10 = idMat3::ToAngles(this: (idMat3 *)&v16, result: (idAngles *)&this->current.worldAxis);
    this->current.worldAngles.pitch = v10->pitch;
    this->current.worldAngles.yaw = v10->yaw;
    v11 = v10->roll;
  }
  else
  {
    p_localAngles = (idMat3 *)&this->current.localAngles;
    if ( this->hasWorldOrientation )
    {
      v13 = idAngles::ToMat3(this: (idAngles *)&v16.currentTime, result: p_localAngles);
      p_worldAxis = &this->current.worldAxis;
      this->current.worldAxis = *idMat3::operator*(this: &v17, result: v13, a: &this->worldAxis);
      v14 = idMat3::ToAngles(this: (idMat3 *)&v16, result: (idAngles *)&this->current.worldAxis);
      this->current.worldAngles.pitch = v14->pitch;
      this->current.worldAngles.yaw = v14->yaw;
      v11 = v14->roll;
    }
    else
    {
      this->current.worldAxis = *idAngles::ToMat3(this: (idAngles *)&v16.currentTime, result: p_localAngles);
      p_worldAxis = &this->current.worldAxis;
      this->current.worldAngles.pitch = this->current.localAngles.pitch;
      this->current.worldAngles.yaw = this->current.localAngles.yaw;
      v11 = this->current.localAngles.roll;
    }
  }
  this->current.worldAngles.roll = v11;
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: p_worldAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetWorldOrientation@idPhysics_Parametric@@QAAXABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82750168
// RVA : 0x00750168
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_Parametric::SetWorldOrientation(
        idPhysics_Parametric *this,
        const idVec3 *_worldOrigin,
        const idMat3 *_worldAxis)
{
  double x; // fp5
  double v7; // fp4
  double v8; // fp12
  double v9; // fp10
  double v10; // fp9
  double v11; // fp4
  double v12; // fp3
  double y; // fp2
  double v14; // fp1
  double z; // fp13
  double v16; // fp12
  double v17; // fp11
  double v18; // fp0
  idMat3 v19; // [sp+50h] [-60h] BYREF
  float v20; // [sp+74h] [-3Ch]
  float v21; // [sp+78h] [-38h]
  float v22; // [sp+7Ch] [-34h]
  float v23; // [sp+80h] [-30h]

  if ( this->hasWorldOrientation )
    idPhysics_Parametric::ClearWorldOrientation(this);
  this->worldOrigin.x = _worldOrigin->x;
  this->worldOrigin.y = _worldOrigin->y;
  this->worldOrigin.z = _worldOrigin->z;
  this->worldAxis.mat[0].x = _worldAxis->mat[0].x;
  this->worldAxis.mat[0].y = _worldAxis->mat[0].y;
  this->worldAxis.mat[0].z = _worldAxis->mat[0].z;
  this->worldAxis.mat[1].x = _worldAxis->mat[1].x;
  this->worldAxis.mat[1].y = _worldAxis->mat[1].y;
  this->worldAxis.mat[1].z = _worldAxis->mat[1].z;
  this->worldAxis.mat[2].x = _worldAxis->mat[2].x;
  this->worldAxis.mat[2].y = _worldAxis->mat[2].y;
  this->worldAxis.mat[2].z = _worldAxis->mat[2].z;
  this->hasWorldOrientation = true;
  x = this->worldAxis.mat[1].x;
  v7 = this->worldAxis.mat[0].x;
  v8 = (float)(this->current.worldOrigin.x - this->worldOrigin.x);
  v9 = (float)((float)((float)(this->current.worldOrigin.y - this->worldOrigin.y) * this->worldAxis.mat[1].y)
             + (float)((float)(this->current.worldOrigin.z - this->worldOrigin.z) * this->worldAxis.mat[1].z));
  v10 = (float)((float)((float)(this->current.worldOrigin.y - this->worldOrigin.y) * this->worldAxis.mat[0].y)
              + (float)((float)(this->current.worldOrigin.z - this->worldOrigin.z) * this->worldAxis.mat[0].z));
  this->current.worldOrigin.z = (float)((float)(this->current.worldOrigin.x - this->worldOrigin.x)
                                      * this->worldAxis.mat[2].x)
                              + (float)((float)((float)(this->current.worldOrigin.y - this->worldOrigin.y)
                                              * this->worldAxis.mat[2].y)
                                      + (float)((float)(this->current.worldOrigin.z - this->worldOrigin.z)
                                              * this->worldAxis.mat[2].z));
  this->current.worldOrigin.y = (float)((float)v8 * (float)x) + (float)v9;
  this->current.worldOrigin.x = (float)((float)v8 * (float)v7) + (float)v10;
  v11 = this->worldAxis.mat[1].x;
  v12 = this->worldAxis.mat[0].x;
  y = this->worldAxis.mat[1].y;
  v14 = this->worldAxis.mat[0].y;
  z = this->worldAxis.mat[1].z;
  v16 = this->worldAxis.mat[0].z;
  v17 = this->worldAxis.mat[2].y;
  v18 = this->worldAxis.mat[2].z;
  v19.mat[2].x = this->worldAxis.mat[2].x;
  v19.mat[2].y = v14;
  v19.mat[2].z = y;
  v19.mat[1].z = v11;
  v19.mat[1].y = v12;
  v20 = v17;
  v21 = v16;
  v22 = z;
  v23 = v18;
  idMat3::operator*=(this: &this->current.worldAxis, a: (idMat3 *)&v19.mat[1].y);
  this->current.worldAngles = *idMat3::ToAngles(this: &v19, result: (idAngles *)&this->current.worldAxis);
  this->current.linearExtrapolation.startValue.x = this->current.worldOrigin.x;
  this->current.linearExtrapolation.startValue.y = this->current.worldOrigin.y;
  this->current.linearExtrapolation.startValue.z = this->current.worldOrigin.z;
  this->current.linearExtrapolation.currentTime = -1.0;
  this->current.angularExtrapolation.startValue.pitch = this->current.worldAngles.pitch;
  this->current.angularExtrapolation.startValue.yaw = this->current.worldAngles.yaw;
  this->current.angularExtrapolation.startValue.roll = this->current.worldAngles.roll;
  this->current.angularExtrapolation.currentTime = -1.0;
}


// ========================================================================
// ??0idPhysics_ParametricMM@@QAA@XZ
// EA  : 0x82750C60
// RVA : 0x00750C60
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idPhysics_ParametricMM *__fastcall idPhysics_ParametricMM::idPhysics_ParametricMM(idPhysics_ParametricMM *this)
{
  int v2; // r7
  int v3; // r6
  const idQuat *v4; // r5
  const idQuat *v5; // r4
  double startValue; // fp0

  idPhysics_DynamicBase::idPhysics_DynamicBase(this);
  this->__vftable = (idPhysics_ParametricMM_vtbl *)&idPhysics_ParametricMM::`vftable';
  parametricPState_tMM::parametricPState_tMM(this: &this->current);
  parametricPState_tMM::parametricPState_tMM(this: &this->saved);
  this->type = PHYSICS_PARAMETRIC;
  this->current.time = 0;
  this->current.atRest = -1;
  this->current.useSplineAngles = false;
  this->current.worldOrigin.z = 0.0;
  this->current.worldOrigin.y = 0.0;
  this->current.worldOrigin.x = 0.0;
  this->current.worldAxis.mat[1].z = 0.0;
  this->current.worldAxis.mat[0].z = 0.0;
  this->current.worldAxis.mat[0].y = 0.0;
  this->current.worldAxis.mat[2].y = 0.0;
  this->current.worldAxis.mat[2].x = 0.0;
  this->current.worldAxis.mat[1].x = 0.0;
  this->current.worldAxis.mat[2].z = 1.0;
  this->current.worldAxis.mat[1].y = 1.0;
  this->current.worldAxis.mat[0].x = 1.0;
  this->current.localOrigin.z = 0.0;
  this->current.localOrigin.y = 0.0;
  this->current.localOrigin.x = 0.0;
  this->current.localAxis.mat[1].z = 0.0;
  this->current.localAxis.mat[0].z = 0.0;
  this->current.localAxis.mat[0].y = 0.0;
  this->current.localAxis.mat[2].y = 0.0;
  this->current.localAxis.mat[2].x = 0.0;
  this->current.localAxis.mat[1].x = 0.0;
  this->current.localAxis.mat[2].z = 1.0;
  this->current.localAxis.mat[1].y = 1.0;
  this->current.localAxis.mat[0].x = 1.0;
  this->current.linearExtrapolation.extrapolationType = EXTRAPOLATION_NONE;
  this->current.linearExtrapolation.startTime = 0.0;
  this->current.linearExtrapolation.duration = 0.0;
  this->current.linearExtrapolation.startValue = vec3_origin;
  this->current.linearExtrapolation.baseSpeed = vec3_origin;
  this->current.linearExtrapolation.speed = vec3_origin;
  this->current.linearExtrapolation.currentTime = -1.0;
  this->current.linearExtrapolation.currentValue = vec3_origin;
  this->current.angularExtrapolation.extrapolationType = EXTRAPOLATION_NONE;
  this->current.angularExtrapolation.startTime = 0.0;
  this->current.angularExtrapolation.duration = 0.0;
  this->current.angularExtrapolation.startValue = 0.0;
  this->current.angularExtrapolation.baseSpeed = 0.0;
  this->current.angularExtrapolation.speed = 0.0;
  this->current.angularExtrapolation.currentTime = -1.0;
  this->current.angularExtrapolation.currentValue = 0.0;
  idInterpolateAccelDecelLinear<idAngles>::Init(
    this: (idInterpolateAccelDecelLinear<idAngles> *)&this->current.linearInterpolation,
    startTime: 0.0,
    accelTime: 0.0,
    decelTime: 0.0,
    duration: 0.0,
    startValue: (const idAngles *)&this->current.localOrigin,
    endValue: (const idAngles *)&this->current.worldAxis,
    a8: (int)&this->current.worldOrigin,
    a9: (int)&this->current.linearExtrapolation.currentValue,
    a10: (idAngles *)&vec3_origin,
    a11: (idAngles *)&vec3_origin);
  idInterpolateAccelDecelLinear<idQuat>::Init(
    this: &this->current.angularInterpolation,
    startTime: 0.0,
    accelTime: 0.0,
    decelTime: 0.0,
    duration: 0.0,
    startValue: v5,
    endValue: v4,
    a8: v3,
    a9: v2,
    a10: &quat_identity,
    a11: &quat_identity);
  this->current.splineAngleInterpolate.startTime = 0.0;
  this->current.splineAngleInterpolate.duration = 0.0;
  this->current.splineAngleInterpolate.startValue = quat_identity;
  this->current.splineAngleInterpolate.endValue = quat_identity;
  this->current.splineAngleInterpolate.currentTime = -1.0;
  this->current.splineAngleInterpolate.currentValue = quat_identity;
  this->current.angularExtrapolationStartAxis.mat[2].z = 1.0;
  this->current.angularExtrapolationStartAxis.mat[1].y = 1.0;
  this->current.angularExtrapolationStartAxis.mat[0].x = 1.0;
  this->current.angularExtrapolationStartAxis.mat[1].z = 0.0;
  this->current.angularExtrapolationStartAxis.mat[0].z = 0.0;
  this->current.angularExtrapolationStartAxis.mat[0].y = 0.0;
  this->current.angularExtrapolationStartAxis.mat[2].y = 0.0;
  this->current.angularExtrapolationStartAxis.mat[2].x = 0.0;
  this->current.angularExtrapolationStartAxis.mat[1].x = 0.0;
  this->current.angularExtrapolationRotVec.z = 0.0;
  this->current.angularExtrapolationRotVec.y = 0.0;
  this->current.angularExtrapolationRotVec.x = 0.0;
  this->current.spline = nullptr;
  this->current.splineInterpolate.duration = 0.0;
  this->current.splineInterpolate.startTime = 0.0;
  this->current.splineInterpolate.startValue = 0.0;
  startValue = this->current.splineInterpolate.startValue;
  this->current.splineInterpolate.endValue = this->current.splineInterpolate.startValue;
  this->current.splineInterpolate.startSpeed = startValue;
  this->current.splineInterpolate.endSpeed = startValue;
  this->current.pauseTime = 0;
  this->current.length = 0.0;
  this->current.totalLength = 0.0;
  this->current.splineDerivative.z = 0.0;
  this->current.splineDerivative.y = 0.0;
  this->current.splineDerivative.x = 0.0;
  this->current.linearVelocity = vec3_origin;
  this->current.angularVelocity = vec3_origin;
  this->current.oscillationZRelative = false;
  this->current.localOriginScaleInterpolation.startTime = 0.0;
  this->current.localOriginScaleInterpolation.duration = 0.0;
  this->current.localOriginScaleInterpolation.startValue.x = 1.0;
  this->current.localOriginScaleInterpolation.startValue.y = 1.0;
  this->current.localOriginScaleInterpolation.startValue.z = 1.0;
  this->current.localOriginScaleInterpolation.endValue.x = 1.0;
  this->current.localOriginScaleInterpolation.endValue.y = 1.0;
  this->current.localOriginScaleInterpolation.endValue.z = 1.0;
  this->current.localOriginScaleInterpolation.currentTime = -1.0;
  this->current.localOriginScaleInterpolation.currentValue.y = 1.0;
  this->current.localOriginScaleInterpolation.currentValue.x = 1.0;
  this->current.localOriginScaleInterpolation.currentValue.z = 1.0;
  this->current.localOffsetInterpolation.startTime = 0.0;
  this->current.localOffsetInterpolation.duration = 0.0;
  this->current.localOffsetInterpolation.startValue = vec3_origin;
  this->current.localOffsetInterpolation.endValue = vec3_origin;
  this->current.localOffsetInterpolation.currentTime = -1.0;
  this->current.localOffsetInterpolation.currentValue = vec3_origin;
  this->current.oscillationExtrapolation[0].extrapolationType = EXTRAPOLATION_NONE;
  this->current.oscillationExtrapolation[1].extrapolationType = EXTRAPOLATION_NONE;
  this->current.oscillationExtrapolation[0].startTime = 0.0;
  this->current.oscillationExtrapolation[0].duration = 0.0;
  this->current.oscillationExtrapolation[0].startValue = 0.0;
  this->current.oscillationExtrapolation[0].baseSpeed = 0.0;
  this->current.oscillationExtrapolation[0].speed = 0.0;
  this->current.oscillationExtrapolation[0].currentTime = -1.0;
  this->current.oscillationExtrapolation[0].currentValue = 0.0;
  this->current.oscillationExtrapolation[1].startTime = 0.0;
  this->current.oscillationExtrapolation[1].duration = 0.0;
  this->current.oscillationExtrapolation[1].startValue = 0.0;
  this->current.oscillationExtrapolation[1].baseSpeed = 0.0;
  this->current.oscillationExtrapolation[1].speed = 0.0;
  this->current.oscillationExtrapolation[1].currentTime = -1.0;
  this->current.oscillationExtrapolation[1].currentValue = 0.0;
  this->current.oscillationExtrapolation[2].extrapolationType = EXTRAPOLATION_NONE;
  this->current.oscillationExtrapolation[2].startTime = 0.0;
  this->current.oscillationExtrapolation[2].duration = 0.0;
  this->current.oscillationExtrapolation[2].startValue = 0.0;
  this->current.oscillationExtrapolation[2].baseSpeed = 0.0;
  this->current.oscillationExtrapolation[2].speed = 0.0;
  this->current.oscillationExtrapolation[2].currentTime = -1.0;
  this->current.oscillationExtrapolation[2].currentValue = 0.0;
  parametricPState_tMM::operator=(this: &this->saved, __that: &this->current);
  this->blockingPhysicsId = -1;
  this->absBounds.b[1].z = 0.0;
  this->absBounds.b[1].y = 0.0;
  this->absBounds.b[1].x = 0.0;
  this->absBounds.b[0].z = 0.0;
  this->absBounds.b[0].y = 0.0;
  this->absBounds.b[0].x = 0.0;
  this->pusher = nullptr;
  this->isPusher = false;
  this->pushFlags = 0;
  this->clipModel = nullptr;
  this->hasMaster = false;
  this->isOrientated = false;
  this->collideCallbackEnabled = false;
  this->collideClipMask = 0;
  this->hasWorldOrientation = false;
  this->worldAxis.mat[2].z = 1.0;
  this->worldAxis.mat[1].y = 1.0;
  this->worldAxis.mat[0].x = 1.0;
  this->worldAxis.mat[1].z = 0.0;
  this->worldAxis.mat[0].z = 0.0;
  this->worldAxis.mat[0].y = 0.0;
  this->worldAxis.mat[2].y = 0.0;
  this->worldAxis.mat[2].x = 0.0;
  this->worldAxis.mat[1].x = 0.0;
  this->worldOrigin.z = 0.0;
  this->worldOrigin.y = 0.0;
  this->worldOrigin.x = 0.0;
  return this;
}


// ========================================================================
// __unwind$264248
// EA  : 0x827511A4
// RVA : 0x007511A4
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void _unwind_264248()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 224 + 244));
}


// ========================================================================
// __unwind$264249
// EA  : 0x827511CC
// RVA : 0x007511CC
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void _unwind_264249()
{
  int v0; // r12

  parametricPState_tMM::~parametricPState_tMM(this: (parametricPState_tMM *)(*(_DWORD *)(v0 - 224 + 244) + 120));
}


// ========================================================================
// __unwind$264250
// EA  : 0x827511F8
// RVA : 0x007511F8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void _unwind_264250()
{
  int v0; // r12

  parametricPState_tMM::~parametricPState_tMM(this: (parametricPState_tMM *)(*(_DWORD *)(v0 - 224 + 244) + 992));
}


// ========================================================================
// ?SetSplineExplicitSpeed@idPhysics_ParametricMM@@QAAMMMM@Z
// EA  : 0x82751288
// RVA : 0x00751288
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

float __fastcall idPhysics_ParametricMM::SetSplineExplicitSpeed(
        idPhysics_ParametricMM *this,
        double startSpeed,
        double endSpeed,
        double endPos,
        const float *a5,
        const float *a6,
        int a7,
        int a8,
        int a9,
        __int64 a10)
{
  double v11; // fp0
  idInterpolateAccelLinearEx<float> *p_splineInterpolate; // r31
  double v14; // fp31
  double CurrentValue; // fp1
  double inited; // fp1
  __int64 v19[6]; // [sp+50h] [-40h] BYREF

  LODWORD(a10) = this->current.time;
  v11 = (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime);
  v19[0] = a10;
  p_splineInterpolate = &this->current.splineInterpolate;
  v14 = (float)a10;
  if ( v14 < v11 )
  {
    CurrentValue = idExtrapolate<float>::GetCurrentValue(
                     this: &this->current.splineInterpolate.extrapolate,
                     time: (float)a10);
  }
  else if ( this->current.splineInterpolate.startSpeed == this->current.splineInterpolate.endSpeed )
  {
    CurrentValue = this->current.splineInterpolate.endValue;
  }
  else
  {
    CurrentValue = (float)((float)((float)((float)((float)a10 - (float)v11) * this->current.splineInterpolate.endSpeed)
                                 * (float)0.001)
                         + this->current.splineInterpolate.endValue);
  }
  *(float *)v19 = CurrentValue;
  if ( CurrentValue > endPos )
  {
    startSpeed = __fnabs(startSpeed);
    endSpeed = __fnabs(endSpeed);
  }
  inited = idInterpolateAccelLinearEx<float>::InitEndSpeed(
             this: p_splineInterpolate,
             startTime: v14,
             startSpeed,
             endSpeed,
             startValue: a5,
             endValue: a6,
             a7,
             a8: (float *)v19,
             a9: a10);
  return *((float *)&inited + 1);
}


// ========================================================================
// ?SetSplineContinue@idPhysics_ParametricMM@@QAAMM@Z
// EA  : 0x82751380
// RVA : 0x00751380
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idPhysics_ParametricMM::SetSplineContinue(
        idPhysics_ParametricMM *this,
        double endPos,
        const float *a3,
        const float *a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  idInterpolateAccelLinearEx<float> *p_splineInterpolate; // r31
  double v10; // fp30
  double v11; // fp10
  double CurrentSpeed; // fp31
  double CurrentValue; // fp0
  double inited; // fp1
  __int64 v16; // [sp+50h] [-30h] BYREF

  LODWORD(a8) = this->current.time;
  this->current.pauseTime = 0;
  HIDWORD(a8) = a8;
  p_splineInterpolate = &this->current.splineInterpolate;
  v10 = (float)*(__int64 *)((char *)&a8 + 4);
  v11 = (float)(this->current.splineInterpolate.startTime + this->current.splineInterpolate.duration);
  v16 = *(__int64 *)((char *)&a8 + 4);
  if ( v10 < v11 )
    CurrentSpeed = idExtrapolate<float>::GetCurrentSpeed(
                     this: &this->current.splineInterpolate.extrapolate,
                     time: (float)*(__int64 *)((char *)&a8 + 4));
  else
    CurrentSpeed = this->current.splineInterpolate.endSpeed;
  if ( v10 < (float)(p_splineInterpolate->startTime + p_splineInterpolate->duration) )
  {
    CurrentValue = idExtrapolate<float>::GetCurrentValue(this: &p_splineInterpolate->extrapolate, time: v10);
  }
  else if ( p_splineInterpolate->startSpeed == p_splineInterpolate->endSpeed )
  {
    CurrentValue = p_splineInterpolate->endValue;
  }
  else
  {
    CurrentValue = (float)((float)((float)((float)((float)v10
                                                 - (float)(p_splineInterpolate->startTime + p_splineInterpolate->duration))
                                         * p_splineInterpolate->endSpeed)
                                 * (float)0.001)
                         + p_splineInterpolate->endValue);
  }
  *(float *)&v16 = CurrentValue;
  inited = 0.0;
  if ( CurrentSpeed != 0.0 )
  {
    if ( endPos < CurrentValue && CurrentSpeed > 0.0 || endPos > CurrentValue && CurrentSpeed < 0.0 )
      CurrentSpeed = (float)((float)CurrentSpeed * (float)-1.0);
    inited = idInterpolateAccelLinearEx<float>::InitEndSpeed(
               this: p_splineInterpolate,
               startTime: v10,
               startSpeed: CurrentSpeed,
               endSpeed: CurrentSpeed,
               startValue: a3,
               endValue: a4,
               a7: a5,
               a8: (float *)&v16,
               a9: a8);
  }
  return *((float *)&inited + 1);
}


// ========================================================================
// ?SetSplineStartSpeed@idPhysics_ParametricMM@@QAAXM@Z
// EA  : 0x827514F0
// RVA : 0x007514F0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

double __fastcall idPhysics_ParametricMM::SetSplineStartSpeed(
        idPhysics_ParametricMM *this,
        double speed,
        const float *a3,
        const float *a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  return idPhysics_ParametricMM::SetSplineExplicitSpeed(
           this,
           startSpeed: speed,
           endSpeed: this->current.splineInterpolate.endSpeed,
           endPos: this->current.splineInterpolate.endValue,
           a5: a3,
           a6: a4,
           a7: a5,
           a8: a6,
           a9: a7,
           a10: a8);
}


// ========================================================================
// ?GetSplineCurrentTime@idPhysics_ParametricMM@@QBAHH@Z
// EA  : 0x82751500
// RVA : 0x00751500
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_ParametricMM::GetSplineCurrentTime(idPhysics_ParametricMM *this, int time)
{
  __int64 v2; // r11
  double v4; // fp1
  double CurrentValue; // fp1

  LODWORD(v2) = time;
  v4 = (float)v2;
  if ( v4 < (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime) )
  {
    CurrentValue = idExtrapolate<float>::GetCurrentValue(this: &this->current.splineInterpolate.extrapolate, time: v4);
  }
  else if ( this->current.splineInterpolate.startSpeed == this->current.splineInterpolate.endSpeed )
  {
    CurrentValue = this->current.splineInterpolate.endValue;
  }
  else
  {
    CurrentValue = (float)((float)((float)((float)((float)v2
                                                 - (float)(this->current.splineInterpolate.duration
                                                         + this->current.splineInterpolate.startTime))
                                         * this->current.splineInterpolate.endSpeed)
                                 * (float)0.001)
                         + this->current.splineInterpolate.endValue);
  }
  return (int)idCurve<idVec3>::GetTimeForLength(this: this->current.spline, length: CurrentValue, epsilon: 0.0099999998);
}


// ========================================================================
// ?Evaluate_SplineBatch@idPhysics_ParametricMM@@AAAXHH@Z
// EA  : 0x827515C0
// RVA : 0x007515C0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::Evaluate_SplineBatch(
        idPhysics_ParametricMM *this,
        int timeStepMSec,
        unsigned int endTimeMSec)
{
  int v5; // r29
  int v7; // r3
  int v8; // r12
  idVec3 *v9; // r27
  int v10; // r12
  double duration; // fp0
  double startTime; // fp11
  double v13; // fp1
  int v14; // r12
  double v15; // fp0
  double CurrentValue; // fp1
  int num; // r11
  int v18; // r10
  int v19; // r11
  float *v20; // r9
  int v23; // r24
  int v24; // r29
  idVec3 *v25; // r26
  float *p_z; // r28
  idPhysics_ParametricMM *PhysObj; // r3
  idPhysics_ParametricMM *v28; // r11
  idPhysics_ParametricMM *v29; // r3
  idVec3 *v30; // r11
  idVec3 *v31; // r11
  _DWORD back_chain[19]; // [sp+0h] [-C0h]
  int v33; // [sp+4Ch] [-74h] BYREF
  idVec3 v34; // [sp+50h] [-70h] BYREF

  v5 = this->current.splineChilds.num + 1;
  v7 = ((int (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)back_chain + v8) = back_chain[0];
  v9 = &v34;
  ((void (__fastcall *)(int))RtlCheckStack12)(a1: v7);
  *(_DWORD *)((char *)back_chain + v10) = back_chain[0];
  ((void (*)(void))RtlCheckStack12)();
  duration = this->current.splineInterpolate.duration;
  *(_QWORD *)&v34.x = __PAIR64__(back_chain[0], endTimeMSec);
  startTime = this->current.splineInterpolate.startTime;
  v13 = (float)__SPAIR64__(back_chain[0], endTimeMSec);
  *(_DWORD *)((char *)back_chain + v14) = back_chain[0];
  v15 = (float)((float)duration + (float)startTime);
  if ( v13 < v15 )
  {
    CurrentValue = idExtrapolate<float>::GetCurrentValue(this: &this->current.splineInterpolate.extrapolate, time: v13);
  }
  else if ( this->current.splineInterpolate.startSpeed == this->current.splineInterpolate.endSpeed )
  {
    CurrentValue = this->current.splineInterpolate.endValue;
  }
  else
  {
    CurrentValue = (float)((float)((float)((float)((float)__SPAIR64__(back_chain[0], endTimeMSec) - (float)v15)
                                         * this->current.splineInterpolate.endSpeed)
                                 * (float)0.001)
                         + this->current.splineInterpolate.endValue);
  }
  num = this->current.splineChilds.num;
  this->current.length = CurrentValue;
  v18 = 0;
  if ( num > 0 )
  {
    v19 = 0;
    v20 = (float *)&v33;
    do
    {
      ++v18;
      _FP11 = (float)(this->current.length - this->current.splineChilds.list[v19++].DistanceFromMe);
      __asm { fsel      f10, f11, f11, f0 }
      *++v20 = _FP10;
    }
    while ( v18 < this->current.splineChilds.num );
  }
  *(&v34.x + this->current.splineChilds.num) = this->current.length;
  idCurve<idVec3>::GetBatchValues(
    this: this->current.spline,
    lengths: &v34.x,
    origins: &v34,
    derivatives: &v34,
    num: v5);
  v23 = 0;
  if ( this->current.splineChilds.num > 0 )
  {
    v24 = 0;
    v25 = &v34;
    p_z = &v34.z;
    do
    {
      PhysObj = this->current.splineChilds.list[v24].PhysObj;
      if ( PhysObj != nullptr )
      {
        PhysObj->SetOrigin(this: PhysObj, a2: v25, a3: -1);
        this->current.splineChilds.list[v24].PhysObj->current.length = v9->x;
        v28 = this->current.splineChilds.list[v24].PhysObj;
        v28->current.splineDerivative.x = *(p_z - 2);
        v28->current.splineDerivative.y = *(p_z - 1);
        v28->current.splineDerivative.z = *p_z;
        v29 = this->current.splineChilds.list[v24].PhysObj;
        v29->Evaluate(this: v29, a2: timeStepMSec, a3: endTimeMSec);
      }
      ++v23;
      v9 = (idVec3 *)((char *)v9 + 4);
      ++v25;
      p_z += 3;
      ++v24;
    }
    while ( v23 < this->current.splineChilds.num );
  }
  v30 = &v34 + this->current.splineChilds.num;
  this->current.localOrigin.x = v30->x;
  this->current.localOrigin.y = v30->y;
  this->current.localOrigin.z = v30->z;
  v31 = &v34 + this->current.splineChilds.num;
  this->current.splineDerivative.x = v31->x;
  this->current.splineDerivative.y = v31->y;
  this->current.splineDerivative.z = v31->z;
}


// ========================================================================
// ?UpdateTime@idPhysics_ParametricMM@@UAAXH@Z
// EA  : 0x82751888
// RVA : 0x00751888
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::UpdateTime(idPhysics_ParametricMM *this, int endTimeMSec, int a3, __int64 a4)
{
  int time; // r11
  double startTime; // fp11
  double v6; // fp11
  double duration; // fp8
  double v8; // fp7

  time = this->current.time;
  this->current.time = endTimeMSec;
  startTime = this->current.linearExtrapolation.startTime;
  LODWORD(a4) = endTimeMSec - time;
  this->current.linearExtrapolation.currentTime = -1.0;
  this->current.linearExtrapolation.startTime = (float)startTime + (float)a4;
  this->current.angularExtrapolation.startTime = this->current.angularExtrapolation.startTime + (float)a4;
  this->current.angularExtrapolation.currentTime = -1.0;
  this->current.linearInterpolation.startTime = (float)a4 + this->current.linearInterpolation.startTime;
  this->current.linearInterpolation.extrapolate.extrapolationType = EXTRAPOLATION_NONE;
  this->current.linearInterpolation.extrapolate.startTime = 0.0;
  this->current.linearInterpolation.extrapolate.duration = 0.0;
  this->current.linearInterpolation.extrapolate.startValue = this->current.linearInterpolation.extrapolate.startValue;
  this->current.linearInterpolation.extrapolate.baseSpeed = this->current.linearInterpolation.extrapolate.baseSpeed;
  this->current.linearInterpolation.extrapolate.speed = this->current.linearInterpolation.extrapolate.speed;
  this->current.linearInterpolation.extrapolate.currentTime = -1.0;
  this->current.linearInterpolation.extrapolate.currentValue = this->current.linearInterpolation.extrapolate.startValue;
  this->current.oscillationExtrapolation[0].startTime = this->current.oscillationExtrapolation[0].startTime + (float)a4;
  this->current.oscillationExtrapolation[0].currentTime = -1.0;
  this->current.oscillationExtrapolation[1].startTime = this->current.oscillationExtrapolation[1].startTime + (float)a4;
  this->current.oscillationExtrapolation[1].currentTime = -1.0;
  this->current.oscillationExtrapolation[2].startTime = this->current.oscillationExtrapolation[2].startTime + (float)a4;
  this->current.oscillationExtrapolation[2].currentTime = -1.0;
  if ( this->current.spline != nullptr )
  {
    v6 = (float)((float)a4 + this->current.splineInterpolate.startTime);
    duration = this->current.splineInterpolate.duration;
    v8 = (float)(this->current.splineInterpolate.endSpeed - this->current.splineInterpolate.startSpeed);
    this->current.splineInterpolate.startTime = (float)a4 + this->current.splineInterpolate.startTime;
    this->current.splineInterpolate.extrapolate.extrapolationType = EXTRAPOLATION_ACCELLINEAR;
    this->current.splineInterpolate.extrapolate.startTime = v6;
    this->current.splineInterpolate.extrapolate.duration = duration;
    this->current.splineInterpolate.extrapolate.startValue = this->current.splineInterpolate.startValue;
    this->current.splineInterpolate.extrapolate.baseSpeed = this->current.splineInterpolate.startSpeed;
    this->current.splineInterpolate.extrapolate.speed = v8;
    this->current.splineInterpolate.extrapolate.currentTime = -1.0;
    this->current.splineInterpolate.extrapolate.currentValue = this->current.splineInterpolate.startValue;
  }
  else
  {
    this->current.angularInterpolation.startTime = (float)a4 + this->current.angularInterpolation.startTime;
    this->current.angularInterpolation.extrapolate.startTime = 0.0;
    this->current.angularInterpolation.extrapolate.extrapolationType = EXTRAPOLATION_NONE;
    this->current.angularInterpolation.extrapolate.duration = 0.0;
    this->current.angularInterpolation.extrapolate.startValue = this->current.angularInterpolation.extrapolate.startValue;
    this->current.angularInterpolation.extrapolate.baseSpeed = this->current.angularInterpolation.extrapolate.baseSpeed;
    this->current.angularInterpolation.extrapolate.speed = this->current.angularInterpolation.extrapolate.speed;
    this->current.angularInterpolation.extrapolate.currentTime = -1.0;
    this->current.angularInterpolation.extrapolate.currentValue = this->current.angularInterpolation.extrapolate.startValue;
  }
}


// ========================================================================
// ?SetAxis@idPhysics_ParametricMM@@UAAXABVidMat3@@H@Z
// EA  : 0x82751AA0
// RVA : 0x00751AA0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::SetAxis(idPhysics_ParametricMM *this, idMat3 *newAxis, int id)
{
  double y; // fp3
  double z; // fp2
  double v7; // fp1
  double v8; // fp0
  double x; // fp13
  double v10; // fp12
  double v11; // fp11
  double v12; // fp5
  double v13; // fp4
  double v14; // fp3
  double v15; // fp2
  double v16; // fp1
  double v17; // fp0
  double v18; // fp13
  double v19; // fp12
  idMat3 *p_worldAxis; // r8
  double v21; // fp13
  double v22; // fp12
  double v23; // fp11
  double v24; // fp10
  double v25; // fp9
  double v26; // fp8
  double v27; // fp7
  double v28; // fp6
  double v29; // fp3
  double v30; // fp2
  double v31; // fp1
  double v32; // fp0
  double v33; // fp13
  double v34; // fp12
  double v35; // fp11
  double v36; // fp4
  double v37; // fp3
  double v38; // fp2
  double v39; // fp1
  double v40; // fp0
  double v41; // fp13
  double v42; // fp12
  char *v43; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  double v46; // fp12
  double v47; // fp11
  double v48; // fp10
  double v49; // fp9
  double v50; // fp8
  double v51; // fp7
  double v52; // fp6
  double v53; // fp13
  double v54; // fp12
  idClipModel *clipModel; // r3
  idMat3 v56; // [sp+50h] [-130h] BYREF
  idMat3 v57; // [sp+80h] [-100h] BYREF
  char v58; // [sp+ACh] [-D4h] BYREF
  idQuat v59; // [sp+B0h] [-D0h] BYREF
  float v60; // [sp+C0h] [-C0h]
  float v61; // [sp+C4h] [-BCh]
  float v62; // [sp+C8h] [-B8h]
  float v63; // [sp+CCh] [-B4h]
  float v64; // [sp+D0h] [-B0h]
  idMat3 v65; // [sp+E0h] [-A0h] BYREF
  idMat3 v66; // [sp+110h] [-70h] BYREF
  idMat3 v67; // [sp+140h] [-40h] BYREF

  if ( this->hasMaster && this->isOrientated )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v67.mat[1].y, a3: &v66);
    v56.mat[0].x = v66.mat[0].x;
    v56.mat[0].y = v66.mat[1].x;
    v56.mat[0].z = v66.mat[2].x;
    v56.mat[1].x = v66.mat[0].y;
    v56.mat[1].y = v66.mat[1].y;
    v56.mat[1].z = v66.mat[2].y;
    v56.mat[2].x = v66.mat[0].z;
    v56.mat[2].y = v66.mat[1].z;
    v56.mat[2].z = v66.mat[2].z;
    idMat3::operator*(this: &v65, result: newAxis, a: &v56);
    this->current.angularExtrapolationStartAxis.mat[0].x = v65.mat[0].x;
    y = v65.mat[0].y;
    z = v65.mat[0].z;
    this->current.angularExtrapolationStartAxis.mat[1].x = v65.mat[1].x;
    v7 = v65.mat[1].y;
    this->current.angularExtrapolationStartAxis.mat[0].y = y;
    this->current.angularExtrapolationStartAxis.mat[0].z = z;
    v8 = v65.mat[1].z;
    this->current.angularExtrapolationStartAxis.mat[1].y = v7;
    x = v65.mat[2].x;
    this->current.angularExtrapolationStartAxis.mat[1].z = v8;
    v10 = v65.mat[2].y;
    this->current.angularExtrapolationStartAxis.mat[2].x = x;
    v11 = v65.mat[2].z;
    this->current.angularExtrapolationStartAxis.mat[2].y = v10;
    this->current.angularExtrapolationStartAxis.mat[2].z = v11;
    this->current.angularInterpolation.startValue = *idMat3::ToQuat(this: &v67, result: (idQuat *)&v65);
    idInterpolateAccelDecelLinear<idQuat>::Invalidate(this: &this->current.angularInterpolation);
    v12 = v65.mat[1].x;
    v13 = v65.mat[0].y;
    v14 = v65.mat[0].z;
    this->current.localAxis.mat[0].x = v65.mat[0].x;
    v15 = v65.mat[1].y;
    this->current.localAxis.mat[1].x = v12;
    this->current.localAxis.mat[0].y = v13;
    this->current.localAxis.mat[0].z = v14;
    v16 = v65.mat[1].z;
    this->current.localAxis.mat[1].y = v15;
    v17 = v65.mat[2].x;
    this->current.localAxis.mat[1].z = v16;
    v18 = v65.mat[2].y;
    v19 = v65.mat[2].z;
    this->current.localAxis.mat[2].x = v17;
    this->current.localAxis.mat[2].y = v18;
    this->current.localAxis.mat[2].z = v19;
    this->current.worldAxis = *idMat3::operator*(this: &v56, result: &v66, a: &this->current.localAxis);
    p_worldAxis = &this->current.worldAxis;
  }
  else if ( this->hasWorldOrientation )
  {
    v21 = this->worldAxis.mat[1].z;
    v22 = this->worldAxis.mat[0].z;
    v23 = this->worldAxis.mat[2].y;
    v24 = this->worldAxis.mat[1].y;
    v25 = this->worldAxis.mat[0].y;
    v26 = this->worldAxis.mat[2].x;
    v27 = this->worldAxis.mat[1].x;
    v28 = this->worldAxis.mat[0].x;
    v56.mat[2].z = this->worldAxis.mat[2].z;
    v56.mat[2].y = v21;
    v56.mat[2].x = v22;
    v56.mat[1].z = v23;
    v56.mat[1].y = v24;
    v56.mat[1].x = v25;
    v56.mat[0].z = v26;
    v56.mat[0].y = v27;
    v56.mat[0].x = v28;
    idMat3::operator*(this: &v57, result: newAxis, a: &v56);
    this->current.angularExtrapolationStartAxis.mat[0].x = v57.mat[0].x;
    v29 = v57.mat[0].y;
    v30 = v57.mat[0].z;
    this->current.angularExtrapolationStartAxis.mat[1].x = v57.mat[1].x;
    v31 = v57.mat[1].y;
    this->current.angularExtrapolationStartAxis.mat[0].y = v29;
    this->current.angularExtrapolationStartAxis.mat[0].z = v30;
    v32 = v57.mat[1].z;
    this->current.angularExtrapolationStartAxis.mat[1].y = v31;
    v33 = v57.mat[2].x;
    this->current.angularExtrapolationStartAxis.mat[1].z = v32;
    v34 = v57.mat[2].y;
    this->current.angularExtrapolationStartAxis.mat[2].x = v33;
    v35 = v57.mat[2].z;
    this->current.angularExtrapolationStartAxis.mat[2].y = v34;
    this->current.angularExtrapolationStartAxis.mat[2].z = v35;
    this->current.angularInterpolation.startValue = *idMat3::ToQuat(this: &v67, result: (idQuat *)&v57);
    idInterpolateAccelDecelLinear<idQuat>::Invalidate(this: &this->current.angularInterpolation);
    this->current.localAxis.mat[0].x = v57.mat[0].x;
    v36 = v57.mat[0].y;
    v37 = v57.mat[0].z;
    this->current.localAxis.mat[1].x = v57.mat[1].x;
    v38 = v57.mat[1].y;
    this->current.localAxis.mat[0].y = v36;
    this->current.localAxis.mat[0].z = v37;
    v39 = v57.mat[1].z;
    this->current.localAxis.mat[1].y = v38;
    v40 = v57.mat[2].x;
    this->current.localAxis.mat[1].z = v39;
    v41 = v57.mat[2].y;
    this->current.localAxis.mat[2].x = v40;
    v42 = v57.mat[2].z;
    this->current.localAxis.mat[2].y = v41;
    this->current.localAxis.mat[2].z = v42;
    this->current.worldAxis = *idMat3::operator*(this: &v56, result: &this->current.localAxis, a: &this->worldAxis);
    p_worldAxis = &this->current.worldAxis;
  }
  else
  {
    v43 = &v58;
    p_z = (_DWORD *)&newAxis[-1].mat[2].z;
    for ( i = 9; i != 0; --i )
    {
      ++p_z;
      v43 += 4;
      *(_DWORD *)v43 = *p_z;
    }
    this->current.angularExtrapolationStartAxis.mat[0].x = v59.x;
    v46 = v59.y;
    v47 = v59.z;
    this->current.angularExtrapolationStartAxis.mat[1].x = v59.w;
    v48 = v60;
    this->current.angularExtrapolationStartAxis.mat[0].y = v46;
    this->current.angularExtrapolationStartAxis.mat[0].z = v47;
    v49 = v61;
    this->current.angularExtrapolationStartAxis.mat[1].y = v48;
    v50 = v62;
    this->current.angularExtrapolationStartAxis.mat[1].z = v49;
    v51 = v63;
    this->current.angularExtrapolationStartAxis.mat[2].x = v50;
    v52 = v64;
    this->current.angularExtrapolationStartAxis.mat[2].y = v51;
    this->current.angularExtrapolationStartAxis.mat[2].z = v52;
    this->current.angularInterpolation.startValue = *idMat3::ToQuat(this: &v67, result: &v59);
    idInterpolateAccelDecelLinear<idQuat>::Invalidate(this: &this->current.angularInterpolation);
    this->current.localAxis.mat[0].x = v59.x;
    p_worldAxis = &this->current.worldAxis;
    v53 = v59.y;
    v54 = v59.z;
    this->current.localAxis.mat[1].x = v59.w;
    this->current.localAxis.mat[0].y = v53;
    this->current.localAxis.mat[0].z = v54;
    this->current.localAxis.mat[1].y = v60;
    this->current.localAxis.mat[1].z = v61;
    this->current.localAxis.mat[2].x = v62;
    this->current.localAxis.mat[2].y = v63;
    this->current.localAxis.mat[2].z = v64;
    this->current.worldAxis.mat[0].x = this->current.localAxis.mat[0].x;
    this->current.worldAxis.mat[0].y = this->current.localAxis.mat[0].y;
    this->current.worldAxis.mat[0].z = this->current.localAxis.mat[0].z;
    this->current.worldAxis.mat[1].x = this->current.localAxis.mat[1].x;
    this->current.worldAxis.mat[1].y = this->current.localAxis.mat[1].y;
    this->current.worldAxis.mat[1].z = this->current.localAxis.mat[1].z;
    this->current.worldAxis.mat[2].x = this->current.localAxis.mat[2].x;
    this->current.worldAxis.mat[2].y = this->current.localAxis.mat[2].y;
    this->current.worldAxis.mat[2].z = this->current.localAxis.mat[2].z;
  }
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: p_worldAxis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?Evaluate@idPhysics_Parametric@@UAA_NHH@Z
// EA  : 0x82751F90
// RVA : 0x00751F90
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

int __fastcall idPhysics_Parametric::Evaluate(idPhysics_Parametric *this, unsigned int timeStepMSec, int endTimeMSec)
{
  double x; // fp13
  double y; // fp12
  double z; // fp11
  double v8; // fp10
  double v10; // fp9
  idVec3 *p_worldOrigin; // r30
  double v12; // fp8
  idAngles *p_worldAxis; // r29
  double v14; // fp7
  idVec3 *p_localOrigin; // r28
  double v16; // fp6
  idAngles *p_localAngles; // r26
  double v18; // fp5
  idAngles *p_worldAngles; // r27
  double v20; // fp4
  double v21; // fp3
  __int64 v22; // r11
  double v23; // fp0
  double v24; // fp28
  double v25; // fp27
  double v26; // fp26
  double pitch; // fp25
  double yaw; // fp24
  double roll; // fp23
  double v30; // fp22
  double v31; // fp21
  double v32; // fp20
  idInterpolateAccelDecelLinear<float> *p_splineInterpolate; // r25
  double v34; // fp30
  double CurrentValue; // fp1
  double TimeForLength; // fp29
  float *v37; // r3
  idAngles *v38; // r3
  idAngles *v39; // r3
  idCurve_Spline<idAngles> *angularSpline; // r4
  int v41; // r3
  float *v42; // r3
  double v43; // fp12
  float *v44; // r3
  idQuat *v45; // r3
  double v46; // fp0
  double v47; // fp9
  double v48; // fp4
  double v49; // fp3
  double v50; // fp2
  double v51; // fp1
  idQuat *v52; // r3
  double v53; // fp0
  double v54; // fp7
  double v55; // fp2
  double v56; // fp1
  double v57; // fp11
  double v58; // fp10
  idAngles *v59; // r3
  double v60; // fp9
  char v61; // r11
  double v62; // fp6
  double v63; // fp30
  double v64; // fp3
  double v65; // fp2
  double v66; // fp7
  double v67; // fp6
  double v68; // fp10
  double v69; // fp8
  double v70; // fp6
  double v71; // fp5
  double v72; // fp6
  double v73; // fp9
  double v74; // fp7
  idMat3 *v75; // r3
  int v76; // r8
  int v77; // r7
  int v78; // r6
  int v79; // r5
  int v80; // r4
  idVec3 *v81; // r3
  double v82; // fp10
  double v83; // fp9
  __int64 v84; // r10
  idPush *pusher; // r3
  int physicsId; // r11
  double v88; // fp13
  double v89; // fp12
  double v90; // fp9
  double v91; // fp8
  double v92; // fp5
  double v93; // fp4
  double v94; // fp3
  idClipModel *clipModel; // r3
  char v96; // r11
  char v97; // r3
  unsigned __int8 v98; // r11
  idVec3 v99; // [sp+50h] [-280h] BYREF
  idMat3 v100; // [sp+60h] [-270h] BYREF
  float v101; // [sp+84h] [-24Ch]
  float v102; // [sp+88h] [-248h]
  float v103; // [sp+8Ch] [-244h]
  float v104; // [sp+90h] [-240h]
  float v105; // [sp+94h] [-23Ch]
  float v106; // [sp+98h] [-238h]
  float v107; // [sp+9Ch] [-234h]
  float v108; // [sp+A0h] [-230h]
  idInterpolateAccelDecelLinear<idVec3> v109; // [sp+B0h] [-220h] BYREF
  float v110; // [sp+118h] [-1B8h]
  float v111; // [sp+11Ch] [-1B4h]
  float v112; // [sp+120h] [-1B0h]
  idMat3 v113; // [sp+130h] [-1A0h] BYREF
  idMat3 v114; // [sp+160h] [-170h] BYREF
  trace_t v115; // [sp+190h] [-140h] BYREF

  HIDWORD(v22) = this->current.spline;
  this->blockingPhysicsId = -1;
  x = this->current.worldAxis.mat[0].x;
  y = this->current.worldAxis.mat[0].y;
  z = this->current.worldAxis.mat[0].z;
  v8 = this->current.worldAxis.mat[1].x;
  v10 = this->current.worldAxis.mat[1].y;
  p_worldOrigin = &this->current.worldOrigin;
  v12 = this->current.worldAxis.mat[1].z;
  p_worldAxis = (idAngles *)&this->current.worldAxis;
  v14 = this->current.worldAxis.mat[2].x;
  p_localOrigin = &this->current.localOrigin;
  v16 = this->current.worldAxis.mat[2].y;
  p_localAngles = &this->current.localAngles;
  v18 = this->current.worldAxis.mat[2].z;
  p_worldAngles = &this->current.worldAngles;
  v20 = this->current.worldOrigin.x;
  v21 = this->current.worldOrigin.y;
  LODWORD(v22) = endTimeMSec;
  v23 = this->current.worldOrigin.z;
  v24 = this->current.localOrigin.x;
  v25 = this->current.localOrigin.y;
  v26 = this->current.localOrigin.z;
  pitch = this->current.localAngles.pitch;
  yaw = this->current.localAngles.yaw;
  roll = this->current.localAngles.roll;
  v30 = this->current.worldAngles.pitch;
  v31 = this->current.worldAngles.yaw;
  v32 = this->current.worldAngles.roll;
  v109.startValue.z = 0.0;
  v109.startValue.y = 0.0;
  v109.startValue.x = 0.0;
  *(float *)&v109.extrapolate.extrapolationType = 0.0;
  v109.endValue.z = 0.0;
  v109.endValue.y = 0.0;
  v99.z = v23;
  v99.y = v21;
  v99.x = v20;
  v100.mat[2].z = x;
  v101 = y;
  v102 = z;
  v103 = v8;
  v104 = v10;
  v105 = v12;
  v106 = v14;
  v107 = v16;
  v108 = v18;
  if ( HIDWORD(v22) != 0 )
  {
    *(_QWORD *)&v100.mat[1].y = v22;
    p_splineInterpolate = &this->current.splineInterpolate;
    v34 = (float)v22;
    idInterpolateAccelDecelLinear<float>::SetPhase(this: &this->current.splineInterpolate, time: v34);
    CurrentValue = idExtrapolate<float>::GetCurrentValue(this: &p_splineInterpolate->extrapolate, time: v34);
    TimeForLength = idCurve<idVec3>::GetTimeForLength(
                      this: this->current.spline,
                      length: CurrentValue,
                      epsilon: 0.0099999998);
    v37 = (float *)((int (__fastcall *)(float *))this->current.spline->GetCurrentValue)(a1: &v100.mat[1].y);
    p_localOrigin->x = *v37;
    p_localOrigin->y = v37[1];
    p_localOrigin->z = v37[2];
    if ( this->current.useSplineAngles )
    {
      v38 = (idAngles *)((int (__fastcall *)(float *, double))this->current.spline->GetCurrentFirstDerivative)(
                          a1: &v100.mat[1].y,
                          a2: TimeForLength);
      v39 = idVec3::ToAngles(this: (idVec3 *)&v109, result: v38);
      v109.startValue.x = v39->pitch;
      v109.startValue.y = v39->yaw;
      v109.startValue.z = v39->roll;
    }
    angularSpline = this->current.angularSpline;
    if ( angularSpline != nullptr )
    {
      v41 = ((int (__fastcall *)(idInterpolateAccelDecelLinear<idVec3> *, double))angularSpline->GetCurrentValue)(
              a1: &v109,
              a2: TimeForLength);
      v109.endValue.y = *(float *)v41;
      v109.endValue.z = *(float *)(v41 + 4);
      v109.extrapolate.extrapolationType = *(extrapolation_t *)(v41 + 8);
    }
  }
  else
  {
    if ( (float)((float)(this->current.linearInterpolation.decelTime + this->current.linearInterpolation.linearTime)
               + this->current.linearInterpolation.accelTime) == 0.0 )
    {
      *(_QWORD *)&v100.mat[1].y = v22;
      v34 = (float)v22;
      v42 = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                       this: (idExtrapolate<idAngles> *)&v109,
                       result: (idAngles *)&this->current.linearExtrapolation,
                       time: v34);
    }
    else
    {
      *(_QWORD *)&v100.mat[1].y = v22;
      v34 = (float)v22;
      v42 = (float *)idInterpolateAccelDecelLinear<idVec3>::GetCurrentValue(
                       this: &v109,
                       result: (idInterpolateAccelDecelLinear<idAngles> *)&this->current.linearInterpolation,
                       time: v34);
    }
    p_localOrigin->x = *v42;
    p_localOrigin->y = v42[1];
    p_localOrigin->z = v42[2];
  }
  if ( (float)((float)(this->current.angularInterpolation.decelTime + this->current.angularInterpolation.linearTime)
             + this->current.angularInterpolation.accelTime) == 0.0 )
  {
    v44 = (float *)idExtrapolate<idAngles>::GetCurrentValue(
                     this: (idExtrapolate<idAngles> *)&v109,
                     result: (idAngles *)&this->current.angularExtrapolation,
                     time: v34);
    v109.extrapolate.duration = *v44;
    v109.extrapolate.startValue.x = v44[1];
    v43 = v44[2];
  }
  else
  {
    idInterpolateAccelDecelLinear<idVec3>::SetPhase(this: &this->current.angularInterpolation, time: v34);
    idExtrapolate<idAngles>::GetCurrentValue(
      this: (idExtrapolate<idAngles> *)&v100.mat[1].y,
      result: (idAngles *)&this->current.angularInterpolation.extrapolate,
      time: v34);
    v43 = v100.mat[2].x;
    v109.extrapolate.duration = v100.mat[1].y;
    v109.extrapolate.startValue.x = v100.mat[1].z;
  }
  v109.extrapolate.startValue.y = v43;
  idAngles::ToQuat(this: (idAngles *)&v100, result: (idQuat *)&v109.extrapolate.duration);
  v45 = idAngles::ToQuat(this: (idAngles *)&v109, result: (idQuat *)&v109.endValue.y);
  v46 = v100.mat[0].z;
  v47 = v45->z;
  v48 = v45->y;
  v49 = (float)((float)(v45->w * v100.mat[0].x)
              + (float)((float)(v100.mat[1].x * v45->x) + (float)(v100.mat[0].y * v45->z)));
  v50 = (float)((float)(v100.mat[0].y * v45->w)
              + (float)((float)(v100.mat[1].x * v45->y) + (float)(v100.mat[0].z * v45->x)));
  v51 = (float)-(float)((float)(v100.mat[0].y * v45->y)
                      - (float)((float)(v100.mat[1].x * v45->w) - (float)(v45->x * v100.mat[0].x)));
  v100.mat[0].z = -(float)((float)(v100.mat[0].y * v45->x)
                         - (float)((float)(v45->y * v100.mat[0].x)
                                 + (float)((float)(v100.mat[1].x * v45->z) + (float)(v100.mat[0].z * v45->w))));
  v100.mat[0].y = -(float)((float)((float)v47 * v100.mat[0].x) - (float)v50);
  v100.mat[0].x = -(float)((float)((float)v46 * (float)v48) - (float)v49);
  v100.mat[1].x = -(float)((float)((float)v46 * (float)v47) - (float)v51);
  v52 = idAngles::ToQuat(this: (idAngles *)&v100.mat[1].y, result: (idQuat *)&v109.startValue);
  v53 = v100.mat[0].z;
  v54 = v52->z;
  v55 = v52->y;
  v56 = (float)((float)(v52->w * v100.mat[0].x)
              + (float)((float)(v100.mat[1].x * v52->x) + (float)(v100.mat[0].y * v52->z)));
  v57 = (float)((float)(v100.mat[0].y * v52->w)
              + (float)((float)(v100.mat[1].x * v52->y) + (float)(v100.mat[0].z * v52->x)));
  v58 = (float)-(float)((float)(v100.mat[0].y * v52->y)
                      - (float)((float)(v100.mat[1].x * v52->w) - (float)(v52->x * v100.mat[0].x)));
  v100.mat[0].z = -(float)((float)(v100.mat[0].y * v52->x)
                         - (float)((float)(v52->y * v100.mat[0].x)
                                 + (float)((float)(v100.mat[1].x * v52->z) + (float)(v100.mat[0].z * v52->w))));
  v100.mat[0].y = -(float)((float)((float)v54 * v100.mat[0].x) - (float)v57);
  v100.mat[0].x = -(float)((float)((float)v53 * (float)v55) - (float)v56);
  v100.mat[1].x = -(float)((float)((float)v53 * (float)v54) - (float)v58);
  *(idMat3 *)&p_worldAxis->pitch = *idQuat::ToMat3(this: (idQuat *)&v113, result: &v100);
  v59 = idMat3::ToAngles(this: (idMat3 *)&v109, result: p_worldAxis);
  v60 = v59->pitch;
  *p_localAngles = *v59;
  p_worldAngles->pitch = v60;
  p_worldAngles->yaw = p_localAngles->yaw;
  p_worldAngles->roll = p_localAngles->roll;
  p_worldOrigin->x = p_localOrigin->x;
  p_worldOrigin->y = p_localOrigin->y;
  p_worldOrigin->z = p_localOrigin->z;
  if ( this->hasMaster )
  {
    this->callbacks->GetMasterPosition(
      this: this->callbacks,
      a2: &v109.extrapolate.baseSpeed,
      a3: (idMat3 *)&v109.extrapolate.speed.y);
    if ( v109.extrapolate.speed.y != 1.0 || v109.extrapolate.currentValue.y != 1.0 || (v61 = 0, v112 != 1.0) )
      v61 = 1;
    if ( v61 != 0 )
    {
      v62 = v109.extrapolate.baseSpeed.y;
      v63 = v109.extrapolate.baseSpeed.z;
      v64 = (float)((float)(v109.extrapolate.speed.z * p_worldOrigin->x)
                  + (float)((float)(v111 * p_worldOrigin->z)
                          + (float)(v109.extrapolate.currentValue.y * p_worldOrigin->y)));
      v65 = (float)((float)(v109.extrapolate.currentTime * p_worldOrigin->x)
                  + (float)((float)(v112 * p_worldOrigin->z)
                          + (float)(v109.extrapolate.currentValue.z * p_worldOrigin->y)));
      p_worldOrigin->x = (float)((float)(v109.extrapolate.currentValue.x * p_worldOrigin->y)
                               + (float)((float)(v109.extrapolate.speed.y * p_worldOrigin->x)
                                       + (float)(v110 * p_worldOrigin->z)))
                       + v109.extrapolate.baseSpeed.x;
      p_worldOrigin->y = (float)v62 + (float)v64;
      p_worldOrigin->z = (float)v63 + (float)v65;
      if ( this->isOrientated )
      {
        idMat3::operator*=(this: (idMat3 *)p_worldAxis, a: (const idMat3 *)&v109.extrapolate.speed.y);
        *p_worldAngles = *idMat3::ToAngles(this: (idMat3 *)&v109, result: p_worldAxis);
      }
    }
    else
    {
      v66 = (float)(v109.extrapolate.baseSpeed.y + p_worldOrigin->y);
      v67 = (float)(p_worldOrigin->z + v109.extrapolate.baseSpeed.z);
      p_worldOrigin->x = p_worldOrigin->x + v109.extrapolate.baseSpeed.x;
      p_worldOrigin->y = v66;
      p_worldOrigin->z = v67;
    }
  }
  else if ( this->hasWorldOrientation )
  {
    v68 = this->worldOrigin.y;
    v69 = this->worldOrigin.z;
    v70 = (float)((float)(this->worldAxis.mat[0].y * p_worldOrigin->x)
                + (float)((float)(this->worldAxis.mat[1].y * p_worldOrigin->y)
                        + (float)(this->worldAxis.mat[2].y * p_worldOrigin->z)));
    v71 = (float)((float)(this->worldAxis.mat[0].z * p_worldOrigin->x)
                + (float)((float)(this->worldAxis.mat[1].z * p_worldOrigin->y)
                        + (float)(this->worldAxis.mat[2].z * p_worldOrigin->z)));
    p_worldOrigin->x = this->worldOrigin.x
                     + (float)((float)(this->worldAxis.mat[0].x * p_worldOrigin->x)
                             + (float)((float)(this->worldAxis.mat[1].x * p_worldOrigin->y)
                                     + (float)(this->worldAxis.mat[2].x * p_worldOrigin->z)));
    p_worldOrigin->y = (float)v68 + (float)v70;
    p_worldOrigin->z = (float)v69 + (float)v71;
    idMat3::operator*=(this: (idMat3 *)p_worldAxis, a: &this->worldAxis);
    *p_worldAngles = *idMat3::ToAngles(this: (idMat3 *)&v109, result: p_worldAxis);
  }
  v72 = (float)(p_worldOrigin->z - v99.z);
  *(_QWORD *)&v100.mat[1].y = __PAIR64__(&unk_82390000, timeStepMSec);
  v113.mat[0].x = v100.mat[2].z;
  v113.mat[0].y = v103;
  v73 = (float)(p_worldOrigin->x - v99.x);
  v113.mat[0].z = v106;
  v113.mat[1].x = v101;
  v74 = (float)(p_worldOrigin->y - v99.y);
  v113.mat[1].z = v107;
  v113.mat[1].y = v104;
  v113.mat[2].x = v102;
  v113.mat[2].y = v105;
  v113.mat[2].z = v108;
  this->spatialVelocity.p[2] = (float)v72
                             * (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001));
  this->spatialVelocity.p[1] = (float)v74
                             * (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001));
  this->spatialVelocity.p[0] = (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001))
                             * (float)v73;
  v75 = idMat3::operator*(this: &v114, result: (idMat3 *)p_worldAxis, a: &v113);
  v81 = idMat3::ToAngularVelocity(this: (idMat3 *)&v109, result: v75->mat);
  v82 = v81->y;
  v83 = v81->z;
  this->spatialVelocity.p[3] = v81->x
                             * (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001));
  this->spatialVelocity.p[4] = (float)v82
                             * (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001));
  this->spatialVelocity.p[5] = (float)v83
                             * (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001));
  HIDWORD(v84) = this->isPusher;
  if ( this->isPusher && this->clipModel != nullptr )
  {
    pusher = this->pusher;
    if ( pusher != nullptr )
    {
      idPush::ClipPush(
        this: pusher,
        results: &v115,
        pusher: this,
        flags: this->pushFlags,
        oldOrigin: &v99,
        oldAxis: (idMat3 *)&v100.mat[2].z,
        newOrigin: p_worldOrigin,
        newAxis: (idMat3 *)p_worldAxis);
      if ( v115.fraction < 1.0 )
      {
        idClipModel::Link(
          this: this->clipModel,
          newEntityNumber: this->entityNumber,
          newPhysicsId: this->physicsId,
          newBodyId: 0,
          newOrigin: &v99,
          newAxis: (idMat3 *)&v100.mat[2].z);
        p_localOrigin->x = v24;
        p_localOrigin->y = v25;
        physicsId = v115.c.physicsId;
        p_localOrigin->z = v26;
        v88 = v99.y;
        v89 = v99.z;
        p_worldOrigin->x = v99.x;
        p_worldOrigin->y = v88;
        p_worldOrigin->z = v89;
        p_localAngles->pitch = pitch;
        p_localAngles->yaw = yaw;
        p_localAngles->roll = roll;
        p_worldAngles->pitch = v30;
        p_worldAngles->yaw = v31;
        p_worldAngles->roll = v32;
        p_worldAxis->pitch = v100.mat[2].z;
        v90 = v101;
        v91 = v102;
        p_worldAxis[1].pitch = v103;
        p_worldAxis->yaw = v90;
        p_worldAxis->roll = v91;
        p_worldAxis[1].yaw = v104;
        v92 = v106;
        p_worldAxis[1].roll = v105;
        v93 = v107;
        p_worldAxis[2].pitch = v92;
        v94 = v108;
        p_worldAxis[2].yaw = v93;
        p_worldAxis[2].roll = v94;
        this->blockingPhysicsId = physicsId;
        return 0;
      }
      *p_worldAngles = *idMat3::ToAngles(this: (idMat3 *)&v109, result: p_worldAxis);
    }
  }
  clipModel = this->clipModel;
  if ( clipModel != nullptr )
    idClipModel::Link(
      this: clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: p_worldOrigin,
      newAxis: (const idMat3 *)p_worldAxis);
  this->current.time = endTimeMSec;
  if ( (unsigned __int8)idPhysics_Parametric::TestIfAtRest(this, a2: v80, a3: v79, a4: v78, a5: v77, a6: v76, a7: v84) != 0 )
    this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
  if ( p_worldOrigin->x != v99.x || p_worldOrigin->y != v99.y || (v96 = 1, p_worldOrigin->z != v99.z) )
    v96 = 0;
  if ( v96 == 0 )
    return 1;
  v97 = idMat3::Compare(this: (idMat3 *)p_worldAxis, a: (idMat3 *)&v100.mat[2].z);
  v98 = 0;
  if ( v97 == 0 )
    return 1;
  return v98;
}


// ========================================================================
// ?SetSplineSpeed@idPhysics_ParametricMM@@QAAMMM@Z
// EA  : 0x82752918
// RVA : 0x00752918
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idPhysics_ParametricMM::SetSplineSpeed(
        idPhysics_ParametricMM *this,
        double speed,
        double endPos,
        const float *a4,
        const float *a5,
        int a6,
        int a7,
        int a8,
        __int64 a9)
{
  double v12; // fp1
  double CurrentSpeed; // fp1
  double v14; // fp1

  HIDWORD(a9) = this->current.time;
  v12 = (float)*(__int64 *)((char *)&a9 + 4);
  LODWORD(a9) = v12 >= (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime);
  if ( v12 < (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime) )
    CurrentSpeed = idExtrapolate<float>::GetCurrentSpeed(this: &this->current.splineInterpolate.extrapolate, time: v12);
  else
    CurrentSpeed = this->current.splineInterpolate.endSpeed;
  v14 = idPhysics_ParametricMM::SetSplineExplicitSpeed(
          this,
          startSpeed: CurrentSpeed,
          endSpeed: speed,
          endPos,
          a5: a4,
          a6: a5,
          a7: a6,
          a8: a7,
          a9: a8,
          a10: a9);
  return *((float *)&v14 + 1);
}


// ========================================================================
// ?GetSplineDirection@idPhysics_ParametricMM@@QBA?AVidVec3@@H@Z
// EA  : 0x827529C0
// RVA : 0x007529C0
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

idPhysics_ParametricMM *__fastcall idPhysics_ParametricMM::GetSplineDirection(
        idPhysics_ParametricMM *this,
        idPhysics_ParametricMM *result,
        int time)
{
  double startValue; // fp31
  double endValue; // fp30
  __int64 v7; // r11
  idPhysics_ParametricMM *v8; // r3
  float v9; // r10
  physicsType_t v10; // r9
  double v11; // fp10
  double v12; // fp9
  idPhysics_ParametricMM_vtbl *v13; // [sp+58h] [-38h] BYREF
  float v14; // [sp+5Ch] [-34h]
  float v15; // [sp+60h] [-30h]

  startValue = result->current.splineInterpolate.startValue;
  endValue = result->current.splineInterpolate.endValue;
  LODWORD(v7) = idPhysics_ParametricMM::GetSplineCurrentTime(this: result, time);
  ((void (__fastcall *)(idPhysics_ParametricMM_vtbl **, double))result->current.spline->GetCurrentFirstDerivative)(
    a1: &v13,
    a2: (float)v7);
  v8 = this;
  if ( startValue >= endValue )
  {
    v11 = -v14;
    v12 = -v15;
    *(float *)&this->__vftable = -*(float *)&v13;
    *((float *)&this->__vftable + 1) = v11;
    *(float *)&this->type = v12;
  }
  else
  {
    v9 = v14;
    v10 = LODWORD(v15);
    this->__vftable = v13;
    *((float *)&this->__vftable + 1) = v9;
    this->type = v10;
  }
  return v8;
}


// ========================================================================
// ?Evaluate_Spline@idPhysics_ParametricMM@@AAAXHH@Z
// EA  : 0x82752A90
// RVA : 0x00752A90
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __fastcall idPhysics_ParametricMM::Evaluate_Spline(
        idPhysics_ParametricMM *this,
        int timeStepMSec,
        unsigned int endTimeMSec)
{
  __int64 v3; // r11
  idInterpolateAccelLinearEx<float> *p_splineInterpolate; // r30
  double v8; // fp31
  double CurrentValue; // fp1
  double TimeForLength; // fp29
  float *v11; // r3
  double CurrentSpeed; // fp1
  double v13; // fp0
  double z; // fp12
  double v15; // fp13
  double v16; // fp12
  double v17; // fp30
  double endSpeed; // fp2
  float *v19; // r3
  idVec3 v20; // [sp+50h] [-60h] BYREF
  _BYTE v21[16]; // [sp+60h] [-50h] BYREF

  if ( this->current.splineChilds.num <= 0 )
  {
    if ( !this->current.splineDummy )
    {
      LODWORD(v3) = endTimeMSec;
      p_splineInterpolate = &this->current.splineInterpolate;
      *(_QWORD *)&v20.x = v3;
      v8 = (float)v3;
      CurrentValue = idInterpolateAccelLinearEx<float>::GetCurrentValue(
                       this: &this->current.splineInterpolate,
                       time: v8);
      this->current.length = CurrentValue;
      TimeForLength = idCurve<idVec3>::GetTimeForLength(
                        this: this->current.spline,
                        length: CurrentValue,
                        epsilon: 0.0099999998);
      v11 = (float *)((int (__fastcall *)(_BYTE *))this->current.spline->GetCurrentValue)(a1: v21);
      this->current.localOrigin.x = *v11;
      this->current.localOrigin.y = v11[1];
      this->current.localOrigin.z = v11[2];
      ((void (__fastcall *)(idVec3 *, double))this->current.spline->GetCurrentFirstDerivative)(
        a1: &v20,
        a2: TimeForLength);
      idVec3::NormalizeFast(this: &v20);
      if ( v8 < (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime) )
        CurrentSpeed = idExtrapolate<float>::GetCurrentSpeed(
                         this: &this->current.splineInterpolate.extrapolate,
                         time: v8);
      else
        CurrentSpeed = this->current.splineInterpolate.endSpeed;
      v13 = (float)(v20.x * (float)CurrentSpeed);
      z = v20.z;
      v15 = (float)(v20.y * (float)CurrentSpeed);
      this->current.linearVelocity.x = v20.x * (float)CurrentSpeed;
      v16 = (float)((float)z * (float)CurrentSpeed);
      this->current.linearVelocity.y = v15;
      this->current.linearVelocity.z = v16;
      v20.x = v13;
      v20.y = v15;
      v20.z = v16;
      if ( g_debugParametricSplineMovement.valueInteger != 0 )
      {
        v17 = (float)((float)((float)v8 - p_splineInterpolate->startTime) * (float)0.001);
        if ( v8 < (float)(this->current.splineInterpolate.duration + this->current.splineInterpolate.startTime) )
          endSpeed = idExtrapolate<float>::GetCurrentSpeed(this: &this->current.splineInterpolate.extrapolate, time: v8);
        else
          endSpeed = this->current.splineInterpolate.endSpeed;
        idLib::Printf(fmt: "Length: %f Speed: %f Time: %f \n", this->current.length, endSpeed, v17);
      }
      v19 = (float *)((int (__fastcall *)(_BYTE *, double))this->current.spline->GetCurrentFirstDerivative)(
                       a1: v21,
                       a2: TimeForLength);
      this->current.splineDerivative.x = *v19;
      this->current.splineDerivative.y = v19[1];
      this->current.splineDerivative.z = v19[2];
    }
  }
  else
  {
    idPhysics_ParametricMM::Evaluate_SplineBatch(this, timeStepMSec, endTimeMSec);
  }
  idPhysics_ParametricMM::Evaluate_SplineAngles(this, timeStepMSec, endTimeMSec);
}


// ========================================================================
// `dynamic initializer for 'g_debugParametricSplineMovement''
// EA  : 0x83340D60
// RVA : 0x01340D60
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugParametricSplineMovement__()
{
  idCVar::idCVar(
    this: &g_debugParametricSplineMovement,
    name: "g_debugParametricSplineMovement",
    value: "0",
    flags: 1,
    description: "Debug spline movement",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugParametricSplineMovement__);
}


// ========================================================================
// `dynamic initializer for 'g_debugParametricSplineAngles''
// EA  : 0x83340DB8
// RVA : 0x01340DB8
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugParametricSplineAngles__()
{
  idCVar::idCVar(
    this: &g_debugParametricSplineAngles,
    name: "g_debugParametricSplineAngles",
    value: "0",
    flags: 1,
    description: "Debug spline angular movement",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugParametricSplineAngles__);
}


// ========================================================================
// `dynamic initializer for 'g_debugParametricSplineVelocity''
// EA  : 0x83340E10
// RVA : 0x01340E10
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_debugParametricSplineVelocity__()
{
  idCVar::idCVar(
    this: &g_debugParametricSplineVelocity,
    name: "g_debugParametricSplineVelocity",
    value: "0",
    flags: 1,
    description: "Debug spline angular movement",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_debugParametricSplineVelocity__);
}


// ========================================================================
// `dynamic initializer for 'g_splinePause''
// EA  : 0x83340E68
// RVA : 0x01340E68
// PDB : w:\tech5\engine\gamelib\physics\physics_parametric.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_splinePause__()
{
  idCVar::idCVar(
    this: &g_splinePause,
    name: "g_splinePause",
    value: "0",
    flags: 1,
    description: "Debug spline angular movement",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_splinePause__);
}

