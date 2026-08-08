
// ========================================================================
// ??1idPresentableArmorPiece@@UAA@XZ
// EA  : 0x82B6BC38
// RVA : 0x00B6BC38
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void __fastcall idPresentableArmorPiece::~idPresentableArmorPiece(idPresentableArmorPiece *this)
{
  this->__vftable = (idPresentableArmorPiece_vtbl *)&idPresentableArmorPiece::`vftable';
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->physicsObj);
  idPresentable::~idPresentable(this);
}


// ========================================================================
// __unwind$487532
// EA  : 0x82B6BC8C
// RVA : 0x00B6BC8C
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void _unwind_487532()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetName@idArmorPiecePhysicsCallback@@UAAPBDXZ
// EA  : 0x82B6BCB8
// RVA : 0x00B6BCB8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

const char *__fastcall idArmorPiecePhysicsCallback::GetName(idArmorPiecePhysicsCallback *this)
{
  return "Client Armor piece physics";
}


// ========================================================================
// ?InitArmorDefaults@idPresentableArmorPiece@@QAAXXZ
// EA  : 0x82B6BD28
// RVA : 0x00B6BD28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void __fastcall idPresentableArmorPiece::InitArmorDefaults(idPresentableArmorPiece *this)
{
  int entityNumber; // r6
  idPhysics_RigidBody *p_physicsObj; // r30
  const char *v4; // r7
  idClipModel *MoveableClipModel; // r3
  int GameMs; // r3
  idVec3 v7; // [sp+50h] [-50h] BYREF

  this->physicsCallback.self = this;
  entityNumber = this->entityNumber;
  this->removeWhenAtRest = false;
  p_physicsObj = &this->physicsObj;
  this->fadeTime = 0.0;
  idPhysics::InitPhysics(
    this: &this->physicsObj,
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallback,
    entityNumber_: entityNumber);
  idPhysics_RigidBody::SetBouncyness(this: p_physicsObj, b: 0.60000002);
  idPhysics_RigidBody::SetFriction(this: p_physicsObj, linear: 0.60000002, angular: 0.60000002, contact: 0.050000001);
  this->physicsObj.SetGravity(this: p_physicsObj, a2: &gameLocal->clientGame.gravity);
  v7.x = 1.0;
  v7.y = 1.0;
  v7.z = 1.0;
  idPhysics_RigidBody::SetInertiaScale(this: p_physicsObj, v: &v7);
  MoveableClipModel = idPresentable::CreateMoveableClipModel(
                        clipModelInfo: &this->clipModelInfo,
                        renderModel: this->model,
                        renderModelScale: &vec3_unit,
                        barrelCollision: false,
                        overrideRadius: -1.0,
                        debugName: v4,
                        a7: "Armor Piece Collision");
  ((void (__fastcall *)(idPhysics_RigidBody *, idClipModel *, double))this->physicsObj.SetClipModel)(
    a1: p_physicsObj,
    a2: MoveableClipModel,
    a3: 0.0020000001);
  this->physicsObj.SetOrigin(this: p_physicsObj, a2: &this->origin, a3: -1);
  this->physicsObj.SetAxis(this: p_physicsObj, a2: &this->axis, a3: -1);
  this->physicsObj.SetContents(this: p_physicsObj, a2: 0, a3: -1);
  this->physicsObj.SetClipMask(this: p_physicsObj, a2: 1, a3: -1);
  this->physicsObj.ClearContacts(this: p_physicsObj);
  this->physicsObj.Activate(this: p_physicsObj);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->physicsObj.UpdateTime(this: p_physicsObj, a2: GameMs);
  this->physicsObj.PutToRest(this: p_physicsObj);
  *((_BYTE *)&this->physicsObj.fl + 4) |= 0x20u;
  this->fade.fadeFrom = 0.0;
  this->fade.fadeTo = 0.0;
  this->fade.fadeStartTime = 0;
  this->fade.fadeEndTime = 0;
  this->fade.noStippleFade = false;
}


// ========================================================================
// ?ApplyImpulse@idArmorPiecePhysicsCallback@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82B6BF40
// RVA : 0x00B6BF40
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void __fastcall idArmorPiecePhysicsCallback::ApplyImpulse(
        idArmorPiecePhysicsCallback *this,
        const int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  this->self->physicsObj.ApplyImpulse(this: &this->self->physicsObj, a2: bodyId, a3: point, a4: impulse);
}


// ========================================================================
// ?ApplyForce@idArmorPiecePhysicsCallback@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82B6BF68
// RVA : 0x00B6BF68
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void __fastcall idArmorPiecePhysicsCallback::ApplyForce(
        idArmorPiecePhysicsCallback *this,
        const int physId,
        int bodyId,
        const idVec3 *point,
        const idVec3 *force)
{
  this->self->physicsObj.ApplyForce(this: &this->self->physicsObj, a2: bodyId, a3: point, a4: force);
}


// ========================================================================
// ?ActivatePhysics@idArmorPiecePhysicsCallback@@UAAXH@Z
// EA  : 0x82B6BF90
// RVA : 0x00B6BF90
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void __fastcall idArmorPiecePhysicsCallback::ActivatePhysics(idArmorPiecePhysicsCallback *this, int physId)
{
  ((void (__fastcall *)(idPhysics_RigidBody *, int))this->self->physicsObj.Activate)(
    a1: &this->self->physicsObj,
    a2: physId);
}


// ========================================================================
// ?DeactivatePhysics@idArmorPiecePhysicsCallback@@UAAXH@Z
// EA  : 0x82B6BFA8
// RVA : 0x00B6BFA8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void __fastcall idArmorPiecePhysicsCallback::DeactivatePhysics(idArmorPiecePhysicsCallback *this, int physId)
{
  ((void (__fastcall *)(idPhysics_RigidBody *, int))this->self->physicsObj.PutToRest)(
    a1: &this->self->physicsObj,
    a2: physId);
}


// ========================================================================
// ??0idPresentableArmorPiece@@QAA@PAVidRenderModel@@VidVec3@@VidMat3@@H@Z
// EA  : 0x82B6BFC8
// RVA : 0x00B6BFC8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idPresentableArmorPiece *__fastcall idPresentableArmorPiece::idPresentableArmorPiece(
        idPresentableArmorPiece *this,
        __int64 origin_,
        __int64 entityNumber_,
        unsigned int a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
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
        int a28,
        int a29,
        int a30,
        int a31,
        float a32,
        int a33,
        int a34,
        int a35)
{
  float v30; // [sp+98h] [+28h]
  __int64 v32; // [sp+A8h] [+38h]
  __int64 v33; // [sp+B0h] [+40h]

  v30 = *(float *)&origin_;
  v32 = a4;
  v33 = *(__int64 *)((char *)&a5 + 4);
  idPresentable::idPresentable(
    this,
    e: nullptr,
    renderModel_: (idTreeAnimator *)HIDWORD(origin_),
    entityNumber_: a35,
    fxDecl_: nullptr);
  this->__vftable = (idPresentableArmorPiece_vtbl *)&idPresentableArmorPiece::`vftable';
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  this->physicsCallback.self = nullptr;
  this->physicsCallback.__vftable = (idArmorPiecePhysicsCallback_vtbl *)&idArmorPiecePhysicsCallback::`vftable';
  this->fade.fadeStartTime = 0;
  this->fade.fadeEndTime = 0;
  this->fade.fadeFrom = 0.0;
  this->fade.noStippleFade = false;
  this->fade.fadeTo = 0.0;
  *(_QWORD *)&this->origin.x = origin_;
  this->origin.z = v30;
  this->axis.mat[0].x = *(float *)&entityNumber_;
  this->axis.mat[1].x = *((float *)&v32 + 1);
  this->axis.mat[0].y = *((float *)&entityNumber_ + 1);
  this->axis.mat[0].z = *(float *)&v32;
  *(_QWORD *)&this->axis.mat[1].y = v33;
  *(_QWORD *)&this->axis.mat[2].x = a5;
  this->axis.mat[2].z = a32;
  idPresentableArmorPiece::InitArmorDefaults(this);
  return this;
}


// ========================================================================
// __unwind$487955
// EA  : 0x82B6C108
// RVA : 0x00B6C108
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void _unwind_487955()
{
  int v0; // r12

  idPresentable::~idPresentable(this: *(idPresentable **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487956
// EA  : 0x82B6C130
// RVA : 0x00B6C130
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void _unwind_487956()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 112 + 132) + 1200));
}


// ========================================================================
// ?ClientThink@idPresentableArmorPiece@@UAAXHM_N@Z
// EA  : 0x82B6C160
// RVA : 0x00B6C160
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void __fastcall idPresentableArmorPiece::ClientThink(
        idPresentableArmorPiece *this,
        int curTime,
        double fraction,
        bool predict)
{
  int GameMs; // r29
  int GameMsPerFrame; // r3
  const idVec3 *v7; // r3
  float *v8; // r3
  int fadeEndTime; // r11
  double fadeTime; // fp13
  idRenderModel *model; // r9
  int v12; // [sp+50h] [-40h] BYREF
  int v13; // [sp+54h] [-3Ch]
  float v14; // [sp+58h] [-38h] BYREF
  float v15; // [sp+5Ch] [-34h] BYREF

  if ( this->fade.fadeEndTime > 0 )
    idFadeHelper::Update(this: &this->fade, presentable: this);
  this->physicsCallback.self = this;
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->physicsObj.Evaluate(this: &this->physicsObj, a2: GameMsPerFrame, a3: GameMs);
  v7 = this->physicsObj.GetOrigin(this: &this->physicsObj, a2: 0);
  this->origin.x = v7->x;
  this->origin.y = v7->y;
  this->origin.z = v7->z;
  v8 = (float *)this->physicsObj.GetAxis(this: &this->physicsObj, a2: 0);
  this->axis.mat[0].x = *v8;
  this->axis.mat[0].y = v8[1];
  this->axis.mat[0].z = v8[2];
  this->axis.mat[1].x = v8[3];
  this->axis.mat[1].y = v8[4];
  this->axis.mat[1].z = v8[5];
  this->axis.mat[2].x = v8[6];
  this->axis.mat[2].y = v8[7];
  this->axis.mat[2].z = v8[8];
  if ( armor_test.valueInteger != 0 )
    clientGame->renderWorld->DebugAxis_2(
      this: clientGame->renderWorld,
      a2: &this->origin,
      a3: &this->axis,
      a4: 0,
      a5: false);
  if ( this->removeWhenAtRest )
  {
    fadeEndTime = this->fade.fadeEndTime;
    if ( fadeEndTime <= 0 )
    {
      if ( fadeEndTime == -1 )
      {
        this->queueForDelete = true;
      }
      else if ( this->physicsObj.IsAtRest(this: &this->physicsObj) )
      {
        fadeTime = this->fadeTime;
        if ( fadeTime > 0.0 )
        {
          v14 = 0.0;
          model = this->model;
          v15 = 1.0;
          v13 = (int)(float)((float)fadeTime * (float)1000.0);
          v12 = v13;
          if ( model != nullptr )
            idFadeHelper::Fade(this: &this->fade, from: &v15, to: &v14, time: &v12, _noStippleFade: false);
          else
            idLib::Warning(fmt: "idPresentableArmorPiece::Fade() called on '%s' with no render model!", MEMORY[0x10]);
        }
      }
    }
    else
    {
      idFadeHelper::Update(this: &this->fade, presentable: this);
    }
  }
  this->Present(this);
}


// ========================================================================
// `dynamic initializer for 'armor_test''
// EA  : 0x8336D9F8
// RVA : 0x0136D9F8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentablearmorpiece.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__armor_test__()
{
  idCVar::idCVar(
    this: &armor_test,
    name: "armor_test",
    value: "0",
    flags: 1,
    description: "vehicle dust time",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__armor_test__);
}

