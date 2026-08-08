
// ========================================================================
// ??1idPresentablePusher@@UAA@XZ
// EA  : 0x82B8E0C8
// RVA : 0x00B8E0C8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepusher.cpp
// ========================================================================

void __fastcall idPresentablePusher::~idPresentablePusher(idPresentablePusher *this)
{
  this->__vftable = (idPresentablePusher_vtbl *)&idPresentablePusher::`vftable';
  idPhysics_Parametric::~idPhysics_Parametric(this: &this->physicsObj);
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$487560
// EA  : 0x82B8E11C
// RVA : 0x00B8E11C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepusher.cpp
// ========================================================================

void _unwind_487560()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// ?DisableClip@idPresentablePusher@@QAAX_N@Z
// EA  : 0x82B8E148
// RVA : 0x00B8E148
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepusher.cpp
// ========================================================================

void __fastcall idPresentablePusher::DisableClip(idPresentablePusher *this, bool disable)
{
  idPhysics_Parametric_vtbl *v2; // r11

  if ( this->physicsInit )
  {
    v2 = this->physicsObj.__vftable;
    if ( disable )
      ((void (*)(void))v2->DisableClip)();
    else
      ((void (*)(void))v2->EnableClip)();
  }
}


// ========================================================================
// ??0idPresentablePusher@@QAA@PAVidEntity@@PAVidRenderModel@@@Z
// EA  : 0x82B8E1F8
// RVA : 0x00B8E1F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepusher.cpp
// ========================================================================

idPresentablePusher *__fastcall idPresentablePusher::idPresentablePusher(
        idPresentablePusher *this,
        idEntity *owner,
        idTreeAnimator *renderModel_)
{
  idPresentable::idPresentable(this, e: owner, renderModel_, entityNumber_: owner->entityNumber, fxDecl_: nullptr);
  this->__vftable = (idPresentablePusher_vtbl *)&idPresentablePusher::`vftable';
  idPhysics_Parametric::idPhysics_Parametric(this: &this->physicsObj);
  this->pushEnabled = false;
  return this;
}


// ========================================================================
// __unwind$487856
// EA  : 0x82B8E25C
// RVA : 0x00B8E25C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepusher.cpp
// ========================================================================

void _unwind_487856()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// ?InitPhysics@idPresentablePusher@@AAAXPAVidPhysicsCallbacks@@_N@Z
// EA  : 0x82B8E288
// RVA : 0x00B8E288
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepusher.cpp
// ========================================================================

void __fastcall idPresentablePusher::InitPhysics(
        idPresentablePusher *this,
        idPhysicsCallbacks *callbacks,
        bool isObstacle)
{
  idPhysics_Parametric *p_physicsObj; // r30
  int v6; // r6
  int physicsId; // r11
  idRenderModel *model; // r11

  p_physicsObj = &this->physicsObj;
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &clientGame->clip,
    callbacks_: callbacks,
    entityNumber_: this->entityNumber);
  ((void (__fastcall *)(idPhysics_Parametric *, idClipModel *, double))this->physicsObj.SetClipModel)(
    a1: p_physicsObj,
    a2: this->clipModel,
    a3: 1.0);
  if ( this->clipModelContents > 0 )
  {
    p_physicsObj->SetClipMask(this: p_physicsObj, a2: 4194305, a3: -1);
    ((void (__fastcall *)(idPhysics_Parametric *, int, int, int, int))p_physicsObj->SetContents)(
      a1: p_physicsObj,
      a2: (!isObstacle ? 0 : 0x20000) | 1,
      a3: -1,
      a4: v6,
      a5: -isObstacle);
  }
  physicsId = this->physicsObj.physicsId;
  this->physicsInit = true;
  this->clipModelPhysID = physicsId;
  if ( common->IsClient(this: common) )
  {
    model = this->model;
    if ( model != nullptr )
      model->useDeferredPosition = true;
  }
}


// ========================================================================
// ?Serialize@idPresentablePusher@@UAAXAAVidSerializer@@@Z
// EA  : 0x82B8E390
// RVA : 0x00B8E390
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepusher.cpp
// ========================================================================

void __fastcall idPresentablePusher::Serialize(idPresentablePusher *this, idSerializer *ser)
{
  idBitMsg *msg; // r3
  bool pushEnabled; // r29

  idPresentable::Serialize(this, ser);
  msg = ser->msg;
  pushEnabled = this->pushEnabled;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: this->pushEnabled, numBits: 1);
  else
    pushEnabled = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
  this->pushEnabled = pushEnabled;
  if ( !ser->writing && !this->physicsInit )
  {
    idPresentablePusher::InitPhysics(this, callbacks: &fakeCB_2, isObstacle: false);
    this->Present(this);
  }
}


// ========================================================================
// ?UpdateClientCollision@idPresentablePusher@@MAAXABVidVec3@@ABVidMat3@@01@Z
// EA  : 0x82B8E430
// RVA : 0x00B8E430
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepusher.cpp
// ========================================================================

void __fastcall idPresentablePusher::UpdateClientCollision(
        idPresentablePusher *this,
        const idVec3 *oldOrigin,
        idMat3 *oldAxis,
        const idVec3 *newOrigin,
        idMat3 *newAxis)
{
  int ServerGameTime; // r28
  unsigned int v11; // r24
  char v12; // r11
  float y; // r7
  char *v14; // r10
  float z; // r6
  _DWORD *p_z; // r11
  int v17; // ctr
  idMat3 *p_axis; // r8
  idPhysics_Parametric *p_physicsObj; // r31
  idVec3 v20; // [sp+50h] [-110h] BYREF
  char v21; // [sp+5Ch] [-104h] BYREF
  idMat3 v22; // [sp+60h] [-100h] BYREF
  trace_t v23; // [sp+90h] [-D0h] BYREF

  ServerGameTime = idClientGame::GetServerGameTime(this: clientGame);
  v11 = ServerGameTime - idClientGame::GetPreviousServerGameTime(this: clientGame);
  if ( pp_disablePush.valueInteger != 0
    || !this->pushEnabled
    || !this->physicsInit
    || this->clipModel == nullptr
    || !this->clipModelDynamic )
  {
    goto LABEL_19;
  }
  if ( oldOrigin->x != newOrigin->x || oldOrigin->y != newOrigin->y || (v12 = 1, oldOrigin->z != newOrigin->z) )
    v12 = 0;
  if ( v12 == 0 )
  {
    idPush::InitSavingPushedPhysicsObjectState(this: &clientGame->push);
    idClientGame::ClientDisablePresentablePushers(this: clientGame, disable: true);
    if ( this->physicsInit )
      this->physicsObj.EnableClip(this: &this->physicsObj);
    y = newOrigin->y;
    v14 = &v21;
    z = newOrigin->z;
    p_z = (_DWORD *)&newAxis[-1].mat[2].z;
    v20.x = newOrigin->x;
    v17 = 9;
    v20.y = y;
    v20.z = z;
    do
    {
      ++p_z;
      v14 += 4;
      *(_DWORD *)v14 = *p_z;
      --v17;
    }
    while ( v17 != 0 );
    idPush::ClipPush(
      this: &clientGame->push,
      results: &v23,
      pusher: &this->physicsObj,
      flags: 0,
      oldOrigin,
      oldAxis,
      newOrigin: &v20,
      newAxis: &v22);
    p_axis = &this->axis;
    if ( !this->clipModelDynamicAxis )
      p_axis = newAxis;
    idClipModel::Link(
      this: this->clipModel,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->clipModelPhysID,
      newBodyId: 0,
      newOrigin,
      newAxis: p_axis);
    idClientGame::ClientDisablePresentablePushers(this: clientGame, disable: false);
    idPush::SetPushedOnPushedPhysicsObjects(this: &clientGame->push, deltaTime: v11);
    if ( v11 != 0 )
      idPhysics_Parametric::ForceUpdateSpatialVelocity(
        this: &this->physicsObj,
        worldOrigin: newOrigin,
        worldAxis: newAxis,
        oldOrigin,
        oldAxis,
        timeStepMSec: v11);
  }
  else
  {
LABEL_19:
    idPresentable::UpdateClientCollision(this, oldOrigin, oldAxis, newOrigin, newAxis);
  }
  p_physicsObj = &this->physicsObj;
  p_physicsObj->SetOrigin(this: p_physicsObj, a2: newOrigin, a3: -1);
  p_physicsObj->SetAxis(this: p_physicsObj, a2: newAxis, a3: -1);
}


// ========================================================================
// `dynamic initializer for 'pp_disablePush''
// EA  : 0x8336E958
// RVA : 0x0136E958
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablepusher.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pp_disablePush__()
{
  idCVar::idCVar(
    this: &pp_disablePush,
    name: "pp_disablePush",
    value: "0",
    flags: 1,
    description: "Disable presentable pusher on clients",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pp_disablePush__);
}

