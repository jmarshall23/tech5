
// ========================================================================
// ??1idPhysics_Player@@UAA@XZ
// EA  : 0x82753770
// RVA : 0x00753770
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::~idPhysics_Player(idPhysics_Player *this)
{
  idClipModel *clipModel_standing; // r3
  idClipModel *clipModel_crouched; // r3
  idClipModel *clipModel_sprintSlide; // r3
  idClipModel *clipModel_dead; // r3

  this->__vftable = (idPhysics_Player_vtbl *)&idPhysics_Player::`vftable';
  clipModel_standing = this->clipModel_standing;
  if ( clipModel_standing != nullptr )
    idClipModel::Delete(this: clipModel_standing);
  clipModel_crouched = this->clipModel_crouched;
  if ( clipModel_crouched != nullptr )
    idClipModel::Delete(this: clipModel_crouched);
  clipModel_sprintSlide = this->clipModel_sprintSlide;
  if ( clipModel_sprintSlide != nullptr )
    idClipModel::Delete(this: clipModel_sprintSlide);
  clipModel_dead = this->clipModel_dead;
  if ( clipModel_dead != nullptr )
    idClipModel::Delete(this: clipModel_dead);
  this->clipModels[0] = nullptr;
  idPhysics_Actor::~idPhysics_Actor(this);
}


// ========================================================================
// __unwind$247813
// EA  : 0x82753804
// RVA : 0x00753804
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void _unwind_247813()
{
  int v0; // r12

  idPhysics_Actor::~idPhysics_Actor(this: *(idPhysics_Actor **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetSlideFriction@idPhysics_Player@@QAAXM@Z
// EA  : 0x82753830
// RVA : 0x00753830
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetSlideFriction(idPhysics_Player *this, double friction)
{
  this->slideFriction = friction;
}


// ========================================================================
// ?HasJumped@idPhysics_Player@@QBA_NXZ
// EA  : 0x82753838
// RVA : 0x00753838
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

BOOL __fastcall idPhysics_Player::HasJumped(idPhysics_Player *this)
{
  return (this->current.movementFlags & 2) != 0;
}


// ========================================================================
// ?HasCrouched@idPhysics_Player@@QBA_NXZ
// EA  : 0x82753848
// RVA : 0x00753848
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

int __fastcall idPhysics_Player::HasCrouched(idPhysics_Player *this)
{
  unsigned __int8 v1; // r11

  if ( (this->current.movementFlags & 1) == 0 )
    return 0;
  v1 = 1;
  if ( (this->saved.movementFlags & 1) != 0 )
    return 0;
  return v1;
}


// ========================================================================
// ?HasStoodUp@idPhysics_Player@@QBA_NXZ
// EA  : 0x82753878
// RVA : 0x00753878
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

int __fastcall idPhysics_Player::HasStoodUp(idPhysics_Player *this)
{
  unsigned __int8 v1; // r11

  if ( (this->current.movementFlags & 1) != 0 )
    return 0;
  v1 = 1;
  if ( (this->saved.movementFlags & 1) == 0 )
    return 0;
  return v1;
}


// ========================================================================
// ?HasSteppedUp@idPhysics_Player@@QBA_NXZ
// EA  : 0x827538A8
// RVA : 0x007538A8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

BOOL __fastcall idPhysics_Player::HasSteppedUp(idPhysics_Player *this)
{
  return (this->current.movementFlags & 0xC) != 0;
}


// ========================================================================
// ?GetStepUp@idPhysics_Player@@QBAMXZ
// EA  : 0x827538C0
// RVA : 0x007538C0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

float __fastcall idPhysics_Player::GetStepUp(idPhysics_Player *this)
{
  double stepUp; // fp1

  stepUp = this->current.stepUp;
  return *((float *)&stepUp + 1);
}


// ========================================================================
// ?IsCrouching@idPhysics_Player@@QBA_NXZ
// EA  : 0x827538C8
// RVA : 0x007538C8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

int __fastcall idPhysics_Player::IsCrouching(idPhysics_Player *this)
{
  return this->current.movementFlags & 1;
}


// ========================================================================
// ?SetClientCrouch@idPhysics_Player@@QAAX_N@Z
// EA  : 0x827538D8
// RVA : 0x007538D8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetClientCrouch(idPhysics_Player *this, bool crouch)
{
  int movementFlags; // r11
  int v3; // r9

  movementFlags = this->current.movementFlags;
  this->forcedClientCrouchState = true;
  v3 = movementFlags | 1;
  if ( !crouch )
    v3 = movementFlags & 0xFFFFFFFE;
  this->current.movementFlags = v3;
}


// ========================================================================
// ?SetSprintSliding@idPhysics_Player@@QAAX_N@Z
// EA  : 0x82753900
// RVA : 0x00753900
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetSprintSliding(idPhysics_Player *this, bool sprintSliding)
{
  int movementFlags; // r11
  int v3; // r10

  movementFlags = this->current.movementFlags;
  v3 = movementFlags | 0x200;
  if ( !sprintSliding )
    v3 = movementFlags & 0xFFFFFDFF;
  this->current.movementFlags = v3;
}


// ========================================================================
// ?SetClipModelStanding@idPhysics_Player@@QAAXPAVidClipModel@@@Z
// EA  : 0x82753920
// RVA : 0x00753920
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetClipModelStanding(idPhysics_Player *this, idClipModel *clipModel)
{
  idClipModel *clipModel_standing; // r3

  clipModel_standing = this->clipModel_standing;
  if ( clipModel_standing != nullptr )
  {
    idClipModel::Delete(this: clipModel_standing);
    this->clipModel_standing = nullptr;
  }
  this->clipModel_standing = clipModel;
}


// ========================================================================
// ?SetWalkFriction@idPhysics_Player@@QAAXM@Z
// EA  : 0x82753970
// RVA : 0x00753970
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetWalkFriction(idPhysics_Player *this, double friction)
{
  this->walkFriction = friction;
}


// ========================================================================
// ?SetSpeed@idPhysics_Player@@QAAXMM@Z
// EA  : 0x82753978
// RVA : 0x00753978
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetSpeed(idPhysics_Player *this, double newWalkSpeed, double newCrouchSpeed)
{
  this->walkSpeed = newWalkSpeed;
  this->crouchSpeed = newCrouchSpeed;
}


// ========================================================================
// ?SetMaxStepHeight@idPhysics_Player@@QAAXM@Z
// EA  : 0x82753988
// RVA : 0x00753988
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetMaxStepHeight(idPhysics_Player *this, double newMaxStepHeight)
{
  this->maxStepHeight = newMaxStepHeight;
}


// ========================================================================
// ?SetMaxJumpHeight@idPhysics_Player@@QAAXM@Z
// EA  : 0x82753990
// RVA : 0x00753990
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetMaxJumpHeight(idPhysics_Player *this, double newMaxJumpHeight)
{
  this->maxJumpHeight = newMaxJumpHeight;
}


// ========================================================================
// ?SetMovementType@idPhysics_Player@@QAAXW4pmtype_t@@@Z
// EA  : 0x82753998
// RVA : 0x00753998
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetMovementType(idPhysics_Player *this, pmtype_t type)
{
  this->current.movementType = type;
}


// ========================================================================
// ?SetKnockBack@idPhysics_Player@@QAAXH_N@Z
// EA  : 0x827539A0
// RVA : 0x007539A0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetKnockBack(idPhysics_Player *this, int knockBackTime, const bool absoluteKnockBack)
{
  int v3; // r11

  if ( this->current.movementTime == 0 && knockBackTime > 0 )
  {
    v3 = this->current.movementFlags | 0x40;
    this->current.movementFlags = v3;
    if ( absoluteKnockBack )
      this->current.movementFlags = v3 | 0x800;
    this->current.movementTime = knockBackTime;
  }
}


// ========================================================================
// ?SetDebugLevel@idPhysics_Player@@QAAX_N@Z
// EA  : 0x827539E0
// RVA : 0x007539E0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetDebugLevel(idPhysics_Player *this, bool set)
{
  this->debugLevel = set;
}


// ========================================================================
// ?RestoreState@idPhysics_Player@@UAAXXZ
// EA  : 0x827539F0
// RVA : 0x007539F0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::RestoreState(idPhysics_Player *this)
{
  this->RestoreStateFromState(this, a2: &this->saved);
}


// ========================================================================
// ?GetLinearVelocity@idPhysics_Player@@UBA?AVidVec3@@H@Z
// EA  : 0x82753A08
// RVA : 0x00753A08
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

idPhysics_Player *__fastcall idPhysics_Player::GetLinearVelocity(idPhysics_Player *this, idVec3 *result, int id)
{
  float y; // r10
  float z; // r9

  y = result[46].y;
  z = result[46].z;
  this->__vftable = (idPhysics_Player_vtbl *)LODWORD(result[46].x);
  *((float *)&this->__vftable + 1) = y;
  *(float *)&this->type = z;
  return this;
}


// ========================================================================
// ?GetPushedLinearVelocity@idPhysics_Player@@UBA?AVidVec3@@H@Z
// EA  : 0x82753A28
// RVA : 0x00753A28
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

idPhysics_Player *__fastcall idPhysics_Player::GetPushedLinearVelocity(
        idPhysics_Player *this,
        idVec3 *result,
        const int id)
{
  float y; // r10
  float z; // r9

  y = result[47].y;
  z = result[47].z;
  this->__vftable = (idPhysics_Player_vtbl *)LODWORD(result[47].x);
  *((float *)&this->__vftable + 1) = y;
  *(float *)&this->type = z;
  return this;
}


// ========================================================================
// ?CmdScale@idPhysics_Player@@ABAMABVusercmd_t@@@Z
// EA  : 0x82753B68
// RVA : 0x00753B68
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idPhysics_Player::CmdScale(idPhysics_Player *this, __int64 cmd)
{
  char v2; // r10
  __int64 v3; // r8 OVERLAPPED
  int v4; // r9
  int v5; // r11
  int v6; // r10
  signed int v7; // r10
  double v8; // fp1
  int v9; // r6
  int v10; // r9
  double v11; // fp6
  double v14; // fp1
  double v15; // fp8
  double v16; // fp6

  v2 = *(_BYTE *)(HIDWORD(cmd) + 7);
  HIDWORD(v3) = *(char *)(HIDWORD(cmd) + 6);
  LODWORD(v3) = v2;
  if ( this->walking && *(unsigned __int8 *)(HIDWORD(cmd) + 8) >= 0x80u )
    v4 = 0;
  else
    v4 = *(char *)(HIDWORD(cmd) + 8);
  v5 = abs8(*(_BYTE *)(HIDWORD(cmd) + 6));
  v6 = abs8(v2);
  if ( v6 > v5 )
    v5 = v6;
  v7 = abs32(v4);
  if ( v7 > v5 )
    v5 = v7;
  if ( v5 > 0 )
  {
    LODWORD(v3) = v3 * v3;
    v9 = v4 * v4;
    LODWORD(cmd) = v4 * v4;
    v10 = v5;
    v11 = (float)((float)cmd + (float)v3);
    _FP4 = (float)((float)((float)((float)*(__int64 *)((char *)&v3 + 4) * (float)*(__int64 *)((char *)&v3 + 4))
                         + (float)((float)cmd + (float)v3))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f5, f13 }
    v14 = __frsqrte(_FP2);
    v15 = (float)((float)-(float)((float)((float)((float)v14
                                                * (float)((float)((float)((float)*(__int64 *)((char *)&v3 + 4)
                                                                        * (float)*(__int64 *)((char *)&v3 + 4))
                                                                + (float)((float)cmd + (float)v3))
                                                        * (float)0.5))
                                        * (float)v14)
                                - (float)1.5)
                * (float)v14);
    v16 = (float)((float)((float)-(float)((float)((float)((float)v14
                                                        * (float)((float)((float)((float)*(__int64 *)((char *)&v3 + 4)
                                                                                * (float)*(__int64 *)((char *)&v3 + 4))
                                                                        + (float)v11)
                                                                * (float)0.5))
                                                * (float)v14)
                                        - (float)1.5)
                        * (float)v14)
                * (float)((float)((float)((float)*(__int64 *)((char *)&v3 + 4) * (float)*(__int64 *)((char *)&v3 + 4))
                                + (float)v11)
                        * (float)0.5));
    v8 = (float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v16 * (float)v15)
                                                                                               - (float)1.5)
                                                                               * (float)v15)
                                                                       * (float)((float)((float)((float)*(__int64 *)((char *)&v3 + 4)
                                                                                               * (float)*(__int64 *)((char *)&v3 + 4))
                                                                                       + (float)((float)cmd + (float)v3))
                                                                               * (float)0.5))
                                                               * (float)((float)-(float)((float)((float)v16 * (float)v15)
                                                                                       - (float)1.5)
                                                                       * (float)v15))
                                                       - (float)1.5)
                                       * (float)((float)-(float)((float)((float)v16 * (float)v15) - (float)1.5)
                                               * (float)v15))
                               * this->playerSpeed)
                       * (float)*(__int64 *)((char *)&v3 - 4))
               * (float)0.0078740157);
  }
  else
  {
    v8 = 0.0;
  }
  return *((float *)&v8 + 1);
}


// ========================================================================
// ?Accelerate@idPhysics_Player@@AAAXABVidVec3@@MM@Z
// EA  : 0x82753CC0
// RVA : 0x00753CC0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::Accelerate(
        idPhysics_Player *this,
        const idVec3 *wishdir,
        double wishspeed,
        double accel)
{
  double y; // fp12
  double z; // fp10
  double v6; // fp13
  double v7; // fp0
  double v8; // fp8
  double v9; // fp6

  y = wishdir->y;
  z = wishdir->z;
  v6 = (float)((float)wishspeed
             - (float)((float)(this->current.velocity.z * wishdir->z)
                     + (float)((float)(wishdir->x * this->current.velocity.x)
                             + (float)(wishdir->y * this->current.velocity.y))));
  if ( v6 > 0.0 )
  {
    v7 = (float)((float)(this->frametime * (float)wishspeed) * (float)accel);
    if ( g_pm_deferredSlideMove )
      v7 = (float)(g_pm_deferredSlideMoveAccelScale * (float)((float)(this->frametime * (float)wishspeed) * (float)accel));
    if ( v7 > v6 )
      v7 = (float)((float)wishspeed
                 - (float)((float)(this->current.velocity.z * wishdir->z)
                         + (float)((float)(wishdir->x * this->current.velocity.x)
                                 + (float)(wishdir->y * this->current.velocity.y))));
    v8 = this->current.velocity.y;
    v9 = this->current.velocity.z;
    this->current.velocity.x = (float)(wishdir->x * (float)v7) + this->current.velocity.x;
    this->current.velocity.y = (float)((float)y * (float)v7) + (float)v8;
    this->current.velocity.z = (float)v9 + (float)((float)z * (float)v7);
  }
}


// ========================================================================
// ?UpdateExternalVelocity@idPhysics_Player@@AAAXXZ
// EA  : 0x82753D68
// RVA : 0x00753D68
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::UpdateExternalVelocity(idPhysics_Player *this)
{
  idVec3 *p_externalVelocity; // r11
  double x; // fp12
  double y; // fp13
  double z; // fp0
  double v5; // fp0
  double v6; // fp11
  double v7; // fp10
  double v8; // fp4
  pmtype_t movementType; // r10
  double v10; // fp13
  double v11; // fp13
  double v12; // fp13
  double v13; // fp0
  double v14; // fp12
  double v15; // fp11
  idVec3 back_chain; // 0:^0.12

  p_externalVelocity = &this->externalVelocity;
  back_chain = this->externalVelocity;
  if ( this->walking )
  {
    x = (float)((float)(this->gravityNormal.x
                      * (float)((float)(this->gravityNormal.x * back_chain.x)
                              + (float)((float)(this->gravityNormal.z * back_chain.z)
                                      + (float)(this->gravityNormal.y * back_chain.y))))
              + back_chain.x);
    y = (float)((float)(this->gravityNormal.y
                      * (float)((float)(this->gravityNormal.x * back_chain.x)
                              + (float)((float)(this->gravityNormal.z * back_chain.z)
                                      + (float)(this->gravityNormal.y * back_chain.y))))
              + back_chain.y);
    z = (float)((float)(this->gravityNormal.z
                      * (float)((float)(this->gravityNormal.x * back_chain.x)
                              + (float)((float)(this->gravityNormal.z * back_chain.z)
                                      + (float)(this->gravityNormal.y * back_chain.y))))
              + back_chain.z);
  }
  else
  {
    z = back_chain.z;
    y = back_chain.y;
    x = back_chain.x;
  }
  v5 = __fsqrts((float)((float)((float)x * (float)x)
                      + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))));
  if ( v5 >= 1.0 )
  {
    movementType = this->current.movementType;
    v10 = 0.0;
    if ( movementType == PM_SPECTATOR )
    {
      v10 = (float)((float)(this->frametime * this->flyFriction) * (float)v5);
    }
    else if ( movementType == PM_SLIDE )
    {
      v10 = (float)((float)(this->frametime * this->slideFriction) * (float)v5);
    }
    else if ( (this->groundSurfaceFlags & 0x20) == 0 && (this->current.movementFlags & 0x40) == 0 )
    {
      v11 = 100.0;
      if ( v5 >= 100.0 )
        v11 = v5;
      v10 = (float)((float)(this->frametime * this->walkFriction) * (float)v11);
    }
    v12 = (float)((float)v5 - (float)v10);
    if ( v12 < 0.0 )
      v12 = 0.0;
    v13 = (float)((float)v12 / (float)v5);
    v14 = this->externalVelocity.y;
    v15 = this->externalVelocity.z;
    p_externalVelocity->x = (float)v13 * p_externalVelocity->x;
    this->externalVelocity.y = (float)v14 * (float)v13;
    this->externalVelocity.z = (float)v15 * (float)v13;
  }
  else
  {
    v6 = this->gravityNormal.y;
    v7 = this->gravityNormal.z;
    if ( __fabs((float)((float)((float)(this->externalVelocity.z * this->gravityNormal.z)
                              + (float)(this->externalVelocity.y * this->gravityNormal.y))
                      + (float)(this->gravityNormal.x * this->externalVelocity.x))) >= 0.0000099999997 )
    {
      v8 = (float)((float)((float)(this->gravityNormal.y * this->externalVelocity.y)
                         + (float)(this->gravityNormal.z * this->externalVelocity.z))
                 + (float)(this->gravityNormal.x * this->externalVelocity.x));
      this->externalVelocity.x = this->gravityNormal.x
                               * (float)((float)((float)(this->gravityNormal.y * this->externalVelocity.y)
                                               + (float)(this->gravityNormal.z * this->externalVelocity.z))
                                       + (float)(this->gravityNormal.x * this->externalVelocity.x));
      this->externalVelocity.y = (float)v6 * (float)v8;
      this->externalVelocity.z = (float)v7 * (float)v8;
    }
    else
    {
      this->externalVelocity.z = 0.0;
      this->externalVelocity.y = 0.0;
      p_externalVelocity->x = 0.0;
    }
  }
}


// ========================================================================
// ?SlideMoveDeferred@idPhysics_Player@@AAAX_N00H@Z
// EA  : 0x82753F50
// RVA : 0x00753F50
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SlideMoveDeferred(
        idPhysics_Player *this,
        bool gravity,
        bool stepUp,
        bool stepDown,
        __int16 ignoreEntityNum)
{
  int v7; // ctr
  idVec3 *p_velocity; // r11
  double v9; // fp13
  idClipModel *v10; // r28
  char v11; // r11
  double maxStepHeight; // fp1
  double frametime; // fp0
  double v14; // fp2
  double v15; // fp8
  double v16; // fp7
  idVec3 *p_gravityNormal; // r30
  idVec3 *v18; // r11
  double z; // fp5
  double v20; // fp3
  double v21; // fp0
  double v22; // fp13
  float y; // r3
  const idClipModel *x_low; // r10
  float v25; // r11
  const idBounds *clipMask; // r24
  idClip *clip; // r4
  unsigned __int64 v28; // r10
  double v29; // fp13
  double v30; // fp12
  double x; // fp11
  double v32; // fp4
  double v33; // fp3
  double v34; // fp2
  double v37; // fp10
  double v38; // fp9
  double v39; // fp6
  double v40; // fp10
  double v41; // fp9
  double v42; // fp8
  double v43; // fp0
  double v44; // fp7
  int v45; // r10
  unsigned __int64 index; // r5
  unsigned __int64 v47; // r11
  idClipModel *clipModel_crouched; // r8
  double v49; // fp6
  unsigned __int64 v50; // r5
  const idMat3 *v51; // [sp+8h] [-138h]
  int v52; // [sp+8h] [-138h]
  int v53; // [sp+8h] [-138h]
  int v54; // [sp+Ch] [-134h]
  bool v55; // [sp+Fh] [-131h]
  bool v56; // [sp+Fh] [-131h]
  int v57; // [sp+10h] [-130h]
  const char *v58; // [sp+10h] [-130h]
  const char *v59; // [sp+10h] [-130h]
  int v60; // [sp+14h] [-12Ch]
  int v61; // [sp+14h] [-12Ch]
  bool v62; // [sp+17h] [-129h]
  const char *v63; // [sp+18h] [-128h]
  int v64; // [sp+18h] [-128h]
  int v65; // [sp+18h] [-128h]
  int v66; // [sp+1Ch] [-124h]
  int v67; // [sp+1Ch] [-124h]
  int v68; // [sp+1Ch] [-124h]
  int v69; // [sp+20h] [-120h]
  int v70; // [sp+20h] [-120h]
  int v71; // [sp+20h] [-120h]
  int v72; // [sp+24h] [-11Ch]
  int v73; // [sp+24h] [-11Ch]
  int v74; // [sp+24h] [-11Ch]
  int v75; // [sp+28h] [-118h]
  int v76; // [sp+28h] [-118h]
  int v77; // [sp+28h] [-118h]
  int v78; // [sp+2Ch] [-114h]
  int v79; // [sp+2Ch] [-114h]
  int v80; // [sp+2Ch] [-114h]
  int v81; // [sp+30h] [-110h]
  int v82; // [sp+30h] [-110h]
  int v83; // [sp+30h] [-110h]
  int v84; // [sp+34h] [-10Ch]
  int v85; // [sp+34h] [-10Ch]
  int v86; // [sp+34h] [-10Ch]
  int v87; // [sp+38h] [-108h]
  int v88; // [sp+38h] [-108h]
  int v89; // [sp+38h] [-108h]
  int v90; // [sp+3Ch] [-104h]
  int v91; // [sp+3Ch] [-104h]
  int v92; // [sp+3Ch] [-104h]
  int v93; // [sp+40h] [-100h]
  int v94; // [sp+40h] [-100h]
  int v95; // [sp+40h] [-100h]
  int v96; // [sp+44h] [-FCh]
  int v97; // [sp+44h] [-FCh]
  int v98; // [sp+44h] [-FCh]
  int v99; // [sp+48h] [-F8h]
  int v100; // [sp+48h] [-F8h]
  int v101; // [sp+48h] [-F8h]
  int v102; // [sp+4Ch] [-F4h]
  int v103; // [sp+4Ch] [-F4h]
  int v104; // [sp+4Ch] [-F4h]
  int v105; // [sp+50h] [-F0h]
  int v106; // [sp+50h] [-F0h]
  int v107; // [sp+50h] [-F0h]
  int v108; // [sp+54h] [-ECh]
  int v109; // [sp+58h] [-E8h]
  int v110; // [sp+58h] [-E8h]
  int v111; // [sp+58h] [-E8h]
  int v112; // [sp+60h] [-E0h]
  int v113; // [sp+60h] [-E0h]
  int v114; // [sp+60h] [-E0h]
  int v115; // [sp+68h] [-D8h]
  int v116; // [sp+70h] [-D0h]
  int v117; // [sp+78h] [-C8h]
  int v118; // [sp+80h] [-C0h]
  _BYTE v119[8]; // [sp+90h] [-B0h] BYREF
  idVec3 v120; // [sp+98h] [-A8h] BYREF
  idVec3 v121; // [sp+A8h] [-98h] BYREF
  idVec3 v122; // [sp+B8h] [-88h] BYREF
  idBounds v123; // [sp+C8h] [-78h] BYREF
  float v124; // [sp+E0h] [-60h]

  v7 = 3;
  p_velocity = &this->current.velocity;
  v9 = 0.0;
  do
  {
    if ( __fabs(p_velocity->x) < 0.0099999998 )
      p_velocity->x = 0.0;
    p_velocity = (idVec3 *)((char *)p_velocity + 4);
    --v7;
  }
  while ( v7 != 0 );
  v10 = this->clipModels[0];
  if ( this->groundPlane || (v11 = 0, this->ladder) )
    v11 = 1;
  if ( stepUp && v11 != 0 )
    maxStepHeight = this->maxStepHeight;
  else
    maxStepHeight = 0.0;
  if ( stepDown )
    v9 = this->maxStepHeight;
  frametime = this->frametime;
  v14 = (float)((float)v9 + (float)maxStepHeight);
  v15 = (float)(this->current.velocity.y * this->frametime);
  v16 = (float)(this->current.velocity.z * this->frametime);
  v122.x = this->current.velocity.x * this->frametime;
  v122.y = v15;
  v122.z = v16;
  p_gravityNormal = &this->gravityNormal;
  if ( gravity )
  {
    v18 = &v121;
    z = this->gravityNormal.z;
    v20 = (float)((float)(this->gravityVector.y * (float)frametime) * (float)frametime);
    v22 = (float)((float)((float)(this->gravityVector.x * (float)frametime) * (float)frametime) + this->gravityNormal.x);
    v21 = (float)((float)(this->gravityVector.z * (float)frametime) * (float)frametime);
    v121.y = this->gravityNormal.y + (float)v20;
    v121.x = v22;
    v121.z = (float)z + (float)v21;
  }
  else
  {
    v18 = &this->gravityNormal;
  }
  y = v18->y;
  x_low = (const idClipModel *)LODWORD(v18->x);
  v25 = v18->z;
  clipMask = (const idBounds *)this->clipMask;
  clip = this->clip;
  v123.b[0].y = y;
  LODWORD(v123.b[0].x) = x_low;
  v123.b[0].z = v25;
  v28 = *(_QWORD *)&idClip::SlideMoveContacts(
                      this: (idClip *)v119,
                      result: clip,
                      a3: nullptr,
                      contacts: nullptr,
                      start: &this->current.worldOrigin,
                      velocity: &v122,
                      gravityVector: &v123,
                      stepUp: maxStepHeight,
                      stepDown: v14,
                      clipModel: x_low,
                      startAxis: v51,
                      clipMask: v54,
                      passEntityNumber: v57,
                      moveClipModel: v62,
                      userName: v63,
                      a16: v66,
                      a17: v69,
                      a18: v72,
                      a19: v75,
                      a20: v78,
                      a21: v81,
                      a22: v84,
                      a23: v87,
                      a24: v90,
                      a25: v93,
                      a26: v96,
                      a27: v99,
                      a28: v102,
                      a29: v105,
                      a30: v108,
                      a31: v109,
                      a32: v10,
                      a33: v112,
                      a34: (int)&v10->axis,
                      a35: v115,
                      a36: clipMask,
                      a37: v116,
                      a38: ignoreEntityNum,
                      a39: v117,
                      clipModel_0_3: true,
                      a41: v118,
                      startAxisa: (const idTraceModel **)"w:\\tech5\\engine\\gamelib\\physics\\Physics_Player.cpp(356) : SlideMoveContacts")->world;
  HIDWORD(v28) = this->canLadder;
  this->slideMoveQuery.index = v28;
  if ( HIDWORD(v28) != 0 )
  {
    v29 = this->gravityNormal.y;
    v30 = this->gravityNormal.z;
    x = p_gravityNormal->x;
    v32 = (float)(this->viewForward.y
                - (float)(this->gravityNormal.y
                        * (float)((float)(this->viewForward.x * this->gravityNormal.x)
                                + (float)((float)(this->viewForward.z * this->gravityNormal.z)
                                        + (float)(this->viewForward.y * this->gravityNormal.y)))));
    v33 = (float)(this->viewForward.z
                - (float)(this->gravityNormal.z
                        * (float)((float)(this->viewForward.x * this->gravityNormal.x)
                                + (float)((float)(this->viewForward.z * this->gravityNormal.z)
                                        + (float)(this->viewForward.y * this->gravityNormal.y)))));
    v34 = (float)(this->viewForward.x
                - (float)(this->gravityNormal.x
                        * (float)((float)(this->viewForward.x * this->gravityNormal.x)
                                + (float)((float)(this->viewForward.z * this->gravityNormal.z)
                                        + (float)(this->viewForward.y * this->gravityNormal.y)))));
    _FP6 = (float)((float)((float)((float)v34 * (float)v34)
                         + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f1, f6, f7, f10 }
    v37 = __frsqrte(_FP1);
    v38 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37
                                                                                        * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                                                                                                * (float)0.5))
                                                                                * (float)v37)
                                                                        - (float)1.5)
                                                        * (float)v37)
                                                * (float)((float)((float)((float)v34 * (float)v34)
                                                                + (float)((float)((float)v33 * (float)v33)
                                                                        + (float)((float)v32 * (float)v32)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v37
                                                                                * (float)((float)((float)((float)v34 * (float)v34)
                                                                                                + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                                                                                        * (float)0.5))
                                                                        * (float)v37)
                                                                - (float)1.5)
                                                * (float)v37))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v37
                                                        * (float)((float)((float)((float)v34 * (float)v34)
                                                                        + (float)((float)((float)v33 * (float)v33)
                                                                                + (float)((float)v32 * (float)v32)))
                                                                * (float)0.5))
                                                * (float)v37)
                                        - (float)1.5)
                        * (float)v37));
    v39 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37 * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v37) - (float)1.5)
                                                                                                * (float)v37)
                                                                                        * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v37 * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v37) - (float)1.5)
                                                                                        * (float)v37))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v37
                                                                                                * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5))
                                                                                        * (float)v37)
                                                                                - (float)1.5)
                                                                * (float)v37))
                                                * (float)((float)((float)((float)v34 * (float)v34)
                                                                + (float)((float)((float)v33 * (float)v33)
                                                                        + (float)((float)v32 * (float)v32)))
                                                        * (float)0.5))
                                        * (float)v38)
                                - (float)1.5)
                * (float)v38);
    v40 = (float)((float)v34
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37 * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v37) - (float)1.5) * (float)v37)
                                                                                                * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v37 * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5)) * (float)v37) - (float)1.5)
                                                                                                * (float)v37))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v37 * (float)((float)((float)((float)v34 * (float)v34) + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))) * (float)0.5))
                                                                                                * (float)v37)
                                                                                        - (float)1.5)
                                                                        * (float)v37))
                                                        * (float)((float)((float)((float)v34 * (float)v34)
                                                                        + (float)((float)((float)v33 * (float)v33)
                                                                                + (float)((float)v32 * (float)v32)))
                                                                * (float)0.5))
                                                * (float)v38)
                                        - (float)1.5)
                        * (float)v38));
    v41 = (float)((float)(this->viewForward.y
                        - (float)(this->gravityNormal.y
                                * (float)((float)(this->viewForward.x * this->gravityNormal.x)
                                        + (float)((float)(this->viewForward.z * this->gravityNormal.z)
                                                + (float)(this->viewForward.y * this->gravityNormal.y)))))
                * (float)v39);
    v42 = (float)((float)(this->viewForward.z
                        - (float)(this->gravityNormal.z
                                * (float)((float)(this->viewForward.x * this->gravityNormal.x)
                                        + (float)((float)(this->viewForward.z * this->gravityNormal.z)
                                                + (float)(this->viewForward.y * this->gravityNormal.y)))))
                * (float)v39);
    if ( this->walking )
      v43 = 1.0;
    else
      v43 = 48.0;
    v44 = this->maxStepHeight;
    v45 = this->clipMask;
    index = this->slideMoveQuery.index;
    v120.x = (float)v40 * (float)v43;
    v120.y = (float)v41 * (float)v43;
    v120.z = (float)v42 * (float)v43;
    v121.x = (float)x * (float)(v44 * -0.75);
    v121.y = (float)v29 * (float)(v44 * -0.75);
    v121.z = (float)v30 * (float)(v44 * -0.75);
    v47 = *(_QWORD *)&idClip::LocalTranslation(
                        this: (idClip *)v119,
                        result: (idClipQuery *)HIDWORD(index),
                        localSpace: (idClipQuery *)index,
                        start: &vec3_origin,
                        end: &v120,
                        clipModel: v10,
                        startAxis: &v10->axis,
                        clipMask: v45,
                        passEntityNumber: v52,
                        moveClipModel: v55,
                        userName: v58,
                        a12: v60,
                        a13: v64,
                        a14: v67,
                        a15: v70,
                        a16: v73,
                        a17: v76,
                        a18: v79,
                        a19: v82,
                        a20: v85,
                        a21: v88,
                        a22: v91,
                        a23: v94,
                        a24: v97,
                        a25: v100,
                        a26: v103,
                        a27: v106,
                        a28: ignoreEntityNum,
                        a29: v110,
                        a30: 0,
                        a31: v113,
                        a32: (int)"w:\\tech5\\engine\\gamelib\\physics\\Physics_Player.cpp(369) : LocalTranslation")->world;
    clipModel_crouched = this->clipModel_crouched;
    HIDWORD(v47) = this->clipMask;
    v49 = (float)(v121.z + v120.z);
    v50 = this->slideMoveQuery.index;
    v123.b[1].y = v121.x + v120.x;
    v123.b[1].z = v121.y + v120.y;
    this->ladderQuery1.index = v47;
    v124 = v49;
    this->ladderQuery2.index = *(_QWORD *)&idClip::LocalTranslation(
                                             this: (idClip *)v119,
                                             result: (idClipQuery *)HIDWORD(v50),
                                             localSpace: (idClipQuery *)v50,
                                             start: &v121,
                                             end: (const idVec3 *)&v123.b[1].y,
                                             clipModel: clipModel_crouched,
                                             startAxis: &clipModel_crouched->axis,
                                             clipMask: SHIDWORD(v47),
                                             passEntityNumber: v53,
                                             moveClipModel: v56,
                                             userName: v59,
                                             a12: v61,
                                             a13: v65,
                                             a14: v68,
                                             a15: v71,
                                             a16: v74,
                                             a17: v77,
                                             a18: v80,
                                             a19: v83,
                                             a20: v86,
                                             a21: v89,
                                             a22: v92,
                                             a23: v95,
                                             a24: v98,
                                             a25: v101,
                                             a26: v104,
                                             a27: v107,
                                             a28: ignoreEntityNum,
                                             a29: v111,
                                             a30: 0,
                                             a31: v114,
                                             a32: (int)"w:\\tech5\\engine\\gamelib\\physics\\Physics_Player.cpp(370) : LocalTranslation")->world;
  }
}


// ========================================================================
// ?Friction@idPhysics_Player@@AAAXXZ
// EA  : 0x827542C8
// RVA : 0x007542C8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::Friction(idPhysics_Player *this)
{
  idVec3 *p_velocity; // r30
  double x; // fp12
  double y; // fp13
  double z; // fp0
  double v5; // fp31
  double v6; // fp11
  double v7; // fp10
  double v8; // fp4
  pmtype_t movementType; // r11
  double v10; // fp0
  double flyFriction; // fp13
  double v12; // fp0
  double v13; // fp0
  double v14; // fp0
  double v15; // fp12
  double v16; // fp11
  idVec3 velocity; // 0:^50.12

  p_velocity = &this->current.velocity;
  velocity = this->current.velocity;
  if ( this->walking )
  {
    x = (float)((float)(this->gravityNormal.x
                      * (float)((float)(this->gravityNormal.x * velocity.x)
                              + (float)((float)(this->gravityNormal.z * velocity.z)
                                      + (float)(this->gravityNormal.y * velocity.y))))
              + velocity.x);
    y = (float)((float)(this->gravityNormal.y
                      * (float)((float)(this->gravityNormal.x * velocity.x)
                              + (float)((float)(this->gravityNormal.z * velocity.z)
                                      + (float)(this->gravityNormal.y * velocity.y))))
              + velocity.y);
    z = (float)((float)(this->gravityNormal.z
                      * (float)((float)(this->gravityNormal.x * velocity.x)
                              + (float)((float)(this->gravityNormal.z * velocity.z)
                                      + (float)(this->gravityNormal.y * velocity.y))))
              + velocity.z);
  }
  else
  {
    z = velocity.z;
    y = velocity.y;
    x = velocity.x;
  }
  v5 = __fsqrts((float)((float)((float)x * (float)x)
                      + (float)((float)((float)z * (float)z) + (float)((float)y * (float)y))));
  if ( v5 < 1.0 )
  {
    v6 = this->gravityNormal.y;
    v7 = this->gravityNormal.z;
    if ( __fabs((float)((float)((float)(this->current.velocity.z * this->gravityNormal.z)
                              + (float)(this->current.velocity.y * this->gravityNormal.y))
                      + (float)(this->gravityNormal.x * this->current.velocity.x))) >= 0.0000099999997 )
    {
      v8 = (float)((float)((float)(this->gravityNormal.y * this->current.velocity.y)
                         + (float)(this->gravityNormal.z * this->current.velocity.z))
                 + (float)(this->gravityNormal.x * this->current.velocity.x));
      this->current.velocity.x = this->gravityNormal.x
                               * (float)((float)((float)(this->gravityNormal.y * this->current.velocity.y)
                                               + (float)(this->gravityNormal.z * this->current.velocity.z))
                                       + (float)(this->gravityNormal.x * this->current.velocity.x));
      this->current.velocity.y = (float)v6 * (float)v8;
      this->current.velocity.z = (float)v7 * (float)v8;
    }
    else
    {
      this->current.velocity.z = 0.0;
      this->current.velocity.y = 0.0;
      p_velocity->x = 0.0;
    }
    return;
  }
  movementType = this->current.movementType;
  v10 = 0.0;
  if ( movementType == PM_SPECTATOR )
  {
    flyFriction = this->flyFriction;
LABEL_22:
    v10 = (float)((float)(this->frametime * (float)flyFriction) * (float)v5);
    goto LABEL_23;
  }
  if ( movementType == PM_SLIDE )
  {
    flyFriction = this->slideFriction;
    goto LABEL_22;
  }
  if ( this->walking && this->waterLevel <= (double)pm_waterlevel_knees.valueFloat )
  {
    if ( (this->groundSurfaceFlags & 0x20) == 0 && (this->current.movementFlags & 0x40) == 0 )
    {
      v12 = 100.0;
      if ( v5 >= 100.0 )
        v12 = v5;
      v10 = (float)((float)(this->frametime * this->walkFriction) * (float)v12);
    }
    goto LABEL_23;
  }
  if ( this->currentSwimDepthState == SWIMDEPTH_STATE_NONE )
  {
    flyFriction = this->airFriction;
    goto LABEL_22;
  }
  v10 = (float)((float)((float)(this->GetWaterViscosity(this, a2: 0) * this->frametime) * this->waterFriction)
              * (float)v5);
LABEL_23:
  v13 = (float)((float)v5 - (float)v10);
  if ( v13 < 0.0 )
    v13 = 0.0;
  v14 = (float)((float)v13 / (float)v5);
  v15 = p_velocity->y;
  v16 = p_velocity->z;
  p_velocity->x = (float)v14 * p_velocity->x;
  p_velocity->y = (float)v15 * (float)v14;
  p_velocity->z = (float)v16 * (float)v14;
}


// ========================================================================
// ?SetSwimStroke@idPhysics_Player@@QAAXABVidVec3@@H_N1@Z
// EA  : 0x82754540
// RVA : 0x00754540
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetSwimStroke(
        idPhysics_Player *this,
        const idVec3 *vel,
        int duration,
        bool backABit,
        bool ignoreInput)
{
  double y; // fp12
  double z; // fp9

  this->swimStrokeVelocity = *vel;
  if ( this->currentSwimDepthState == SWIMDEPTH_STATE_ON_SURFACE )
  {
    y = this->swimStrokeVelocity.y;
    z = this->swimStrokeVelocity.z;
    this->swimStrokeVelocity.x = this->swimStrokeVelocity.x * (float)0.60000002;
    this->swimStrokeVelocity.y = (float)y * (float)0.60000002;
    this->swimStrokeVelocity.z = (float)z * (float)0.60000002;
    duration = (int)(float)((float)__SPAIR64__(&unk_821F0000, duration) * (float)0.60000002);
  }
  this->swimStrokeTimeLeft = duration;
  this->swimStrokeTime = duration;
  this->swimStrokeAltCurve = backABit;
  this->swimStrokeIgnoreInput = ignoreInput;
}


// ========================================================================
// ?GetIsUnderWater@idPhysics_Player@@QBA_NXZ
// EA  : 0x827545D0
// RVA : 0x007545D0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

BOOL __fastcall idPhysics_Player::GetIsUnderWater(idPhysics_Player *this)
{
  return (_cntlzw(this->currentSwimDepthState - 2) & 0x20) != 0;
}


// ========================================================================
// ?StartPerfectOrigin@idPhysics_Player@@QAAXABVidVec3@@H@Z
// EA  : 0x827545E8
// RVA : 0x007545E8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::StartPerfectOrigin(idPhysics_Player *this, const idVec3 *idealPos, int lerpTimeMs)
{
  if ( this->current.movementType != PM_NOCLIP )
  {
    this->perfectOriginDuration = lerpTimeMs;
    this->current.movementType = PM_PERFECTORIGIN;
    this->perfectOriginTime = 0;
    this->perfectOriginPosition = *idealPos;
  }
}


// ========================================================================
// ?NoclipMove@idPhysics_Player@@AAAXXZ
// EA  : 0x82754628
// RVA : 0x00754628
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::NoclipMove(idPhysics_Player *this, int a2, __int64 a3)
{
  idVec3 *p_velocity; // r30
  double v5; // fp0
  double v6; // fp13
  double v7; // fp0
  double y; // fp12
  double z; // fp11
  double v10; // fp1
  __int64 v11; // r11
  double v12; // fp11
  __int128 v13; // r6
  double v14; // fp10
  double walkAccelerate; // fp2
  double v16; // fp11
  double v17; // fp10
  double v18; // fp9
  double v21; // fp13
  double v22; // fp12
  double v23; // fp7
  double v24; // fp6
  double v25; // fp4
  double v26; // fp3
  idVec3 v27; // [sp+50h] [-40h] BYREF

  p_velocity = &this->current.velocity;
  v5 = __fsqrts((float)((float)(this->current.velocity.z * this->current.velocity.z)
                      + (float)((float)(this->current.velocity.x * this->current.velocity.x)
                              + (float)(this->current.velocity.y * this->current.velocity.y))));
  if ( v5 >= 20.0 )
  {
    if ( v5 < (float)(this->playerSpeed * (float)0.30000001) )
      v5 = (float)(this->playerSpeed * (float)0.30000001);
    v6 = (float)-(float)((float)((float)(this->frametime * (float)v5) * (float)12.0) - (float)v5);
    if ( v6 < 0.0 )
      v6 = 0.0;
    v7 = (float)((float)v6 / (float)v5);
    y = this->current.velocity.y;
    z = this->current.velocity.z;
    p_velocity->x = (float)v7 * p_velocity->x;
    this->current.velocity.y = (float)y * (float)v7;
    this->current.velocity.z = (float)z * (float)v7;
  }
  else
  {
    this->current.velocity.z = 0.0;
    this->current.velocity.y = 0.0;
    p_velocity->x = 0.0;
  }
  v10 = idPhysics_Player::CmdScale(this, cmd: a3);
  HIDWORD(v11) = (unsigned __int8)this->command.upmove;
  v12 = this->viewRight.y;
  LODWORD(v13) = this->command.forwardmove;
  DWORD2(v13) = SBYTE3(v11);
  v14 = this->viewForward.y;
  LODWORD(v11) = this->command.rightmove;
  *(_QWORD *)&v27.x = v11;
  walkAccelerate = this->walkAccelerate;
  v16 = (float)((float)((float)((float)((float)v14 * (float)(__int64)v13) + (float)((float)v12 * (float)v11))
                      * (float)v10)
              - (float)((float)(this->gravityNormal.y * (float)v10) * (float)*(__int64 *)((char *)&v13 + 4)));
  v17 = (float)((float)((float)((float)(this->viewForward.z * (float)(__int64)v13)
                              + (float)(this->viewRight.z * (float)v11))
                      * (float)v10)
              - (float)((float)(this->gravityNormal.z * (float)v10) * (float)*(__int64 *)((char *)&v13 + 4)));
  v18 = (float)((float)((float)((float)(this->viewForward.x * (float)(__int64)v13)
                              + (float)(this->viewRight.x * (float)v11))
                      * (float)v10)
              - (float)((float)(this->gravityNormal.x * (float)v10) * (float)*(__int64 *)((char *)&v13 + 4)));
  _FP5 = (float)((float)((float)((float)v18 * (float)v18)
                       + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f13 }
  v21 = __frsqrte(_FP3);
  v22 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21
                                                                                      * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                                                                                              * (float)0.5))
                                                                              * (float)v21)
                                                                      - (float)1.5)
                                                      * (float)v21)
                                              * (float)((float)((float)((float)v18 * (float)v18)
                                                              + (float)((float)((float)v17 * (float)v17)
                                                                      + (float)((float)v16 * (float)v16)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v21
                                                                              * (float)((float)((float)((float)v18 * (float)v18)
                                                                                              + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                                                                                      * (float)0.5))
                                                                      * (float)v21)
                                                              - (float)1.5)
                                              * (float)v21))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v21
                                                      * (float)((float)((float)((float)v18 * (float)v18)
                                                                      + (float)((float)((float)v17 * (float)v17)
                                                                              + (float)((float)v16 * (float)v16)))
                                                              * (float)0.5))
                                              * (float)v21)
                                      - (float)1.5)
                      * (float)v21));
  v27.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                                * (float)v21)
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                        * (float)v21))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v21
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                        * (float)v21)
                                                                                - (float)1.5)
                                                                * (float)v21))
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)v16 * (float)v16)))
                                                        * (float)0.5))
                                        * (float)v22)
                                - (float)1.5)
                * (float)v22)
        * (float)v18;
  v27.y = (float)v16
        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                                * (float)v21)
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                        * (float)v21))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v21
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                        * (float)v21)
                                                                                - (float)1.5)
                                                                * (float)v21))
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)v16 * (float)v16)))
                                                        * (float)0.5))
                                        * (float)v22)
                                - (float)1.5)
                * (float)v22);
  v27.z = (float)v17
        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                                * (float)v21)
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                        * (float)v21))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v21
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                        * (float)v21)
                                                                                - (float)1.5)
                                                                * (float)v21))
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)v16 * (float)v16)))
                                                        * (float)0.5))
                                        * (float)v22)
                                - (float)1.5)
                * (float)v22);
  idPhysics_Player::Accelerate(
    this,
    wishdir: &v27,
    wishspeed: (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5) * (float)v21)
                                                                                                  * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5)) * (float)v21) - (float)1.5)
                                                                                                  * (float)v21))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v21 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))) * (float)0.5))
                                                                                                  * (float)v21)
                                                                                          - (float)1.5)
                                                                          * (float)v21))
                                                          * (float)((float)((float)((float)v18 * (float)v18)
                                                                          + (float)((float)((float)v17 * (float)v17)
                                                                                  + (float)((float)v16 * (float)v16)))
                                                                  * (float)0.5))
                                                  * (float)v22)
                                          - (float)1.5)
                          * (float)v22)
                  * (float)((float)((float)v18 * (float)v18)
                          + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))))
          * (float)v10),
    accel: walkAccelerate);
  v23 = (float)(p_velocity->y * this->frametime);
  v24 = (float)(p_velocity->z * this->frametime);
  v25 = this->current.worldOrigin.y;
  v26 = this->current.worldOrigin.z;
  this->current.worldOrigin.x = (float)(this->frametime * p_velocity->x) + this->current.worldOrigin.x;
  this->current.worldOrigin.y = (float)v25 + (float)v23;
  this->current.worldOrigin.z = (float)v26 + (float)v24;
  ((void (*)(void))this->ClearContacts)();
}


// ========================================================================
// ?CorrectAllSolid@idPhysics_Player@@AAAXAAUtrace_t@@H@Z
// EA  : 0x827548D0
// RVA : 0x007548D0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::CorrectAllSolid(idPhysics_Player *this, trace_t *trace, int contents)
{
  if ( trace->fraction >= 1.0 )
  {
    memset(Dst: trace, Val: 0, Size: sizeof(trace_t));
    trace->endpos.x = this->current.worldOrigin.x;
    trace->endpos.y = this->current.worldOrigin.y;
    trace->endpos.z = this->current.worldOrigin.z;
    trace->endAxis.mat[0].x = this->clipModelAxis.mat[0].x;
    trace->endAxis.mat[0].y = this->clipModelAxis.mat[0].y;
    trace->endAxis.mat[0].z = this->clipModelAxis.mat[0].z;
    trace->endAxis.mat[1].x = this->clipModelAxis.mat[1].x;
    trace->endAxis.mat[1].y = this->clipModelAxis.mat[1].y;
    trace->endAxis.mat[1].z = this->clipModelAxis.mat[1].z;
    trace->endAxis.mat[2].x = this->clipModelAxis.mat[2].x;
    trace->endAxis.mat[2].y = this->clipModelAxis.mat[2].y;
    trace->endAxis.mat[2].z = this->clipModelAxis.mat[2].z;
    trace->fraction = 0.0;
    trace->c.dist = this->current.worldOrigin.z;
    trace->c.normal.x = 0.0;
    trace->c.normal.y = 0.0;
    trace->c.normal.z = 1.0;
    trace->c.point.x = this->current.worldOrigin.x;
    trace->c.point.y = this->current.worldOrigin.y;
    trace->c.point.z = this->current.worldOrigin.z;
    trace->c.entityNum = 8190;
    trace->c.physicsId = -1;
    trace->c.bodyId = 0;
    trace->c.type = CONTACT_TRMVERTEX;
    trace->c.contentFlags = contents;
    trace->c.surfaceFlags = 0;
    trace->c.surfaceType = 0;
  }
}


// ========================================================================
// ?CheckJump@idPhysics_Player@@AAA_NXZ
// EA  : 0x827549E8
// RVA : 0x007549E8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

int __fastcall idPhysics_Player::CheckJump(idPhysics_Player *this)
{
  int movementFlags; // r11
  bool (__fastcall *ownerJumpHandler)(int, const idVec3 *, const idVec3 *, const idVec3 *, const idVec3 *, const usercmd_t *); // r9
  double v4; // fp8
  double v5; // fp7
  double v6; // fp5
  double v7; // fp3
  double y; // fp12
  double z; // fp11
  double v11; // fp9
  double v12; // fp8
  idVec3 v13; // [sp+50h] [-40h] BYREF
  idVec3 v14; // [sp+60h] [-30h] BYREF
  idVec3 v15; // [sp+70h] [-20h] BYREF

  if ( this->command.upmove < 10 )
    return 0;
  movementFlags = this->current.movementFlags;
  if ( (movementFlags & 0x10) != 0 )
    return 0;
  if ( (movementFlags & 1) != 0 )
    return 0;
  if ( this->inhibitJump )
    return 0;
  ownerJumpHandler = this->ownerJumpHandler;
  this->groundPlane = false;
  this->walking = false;
  this->current.movementFlags = movementFlags | 0x12;
  if ( ownerJumpHandler != nullptr )
  {
    idAngles::ToVectors(this: &this->viewAngles, forward: &v15, right: &v14, up: &v13);
    if ( this->ownerJumpHandler(
           a1: this->entityNumber,
           a2: &this->current.worldOrigin,
           a3: &v15,
           a4: &v14,
           a5: &v13,
           a6: &this->command) )
    {
      return 0;
    }
  }
  v4 = -this->gravityVector.z;
  v5 = (float)(this->maxJumpHeight * (float)2.0);
  v6 = (float)((float)-this->gravityVector.y * (float)(this->maxJumpHeight * (float)2.0));
  v13.x = (float)-this->gravityVector.x * (float)(this->maxJumpHeight * (float)2.0);
  v13.y = v6;
  v13.z = (float)v4 * (float)v5;
  v7 = __fsqrts(idVec3::NormalizeFast(this: &v13));
  y = this->current.velocity.y;
  z = this->current.velocity.z;
  v11 = (float)(v13.y * (float)v7);
  v12 = (float)(v13.z * (float)v7);
  this->current.velocity.x = this->current.velocity.x + (float)(v13.x * (float)v7);
  this->current.velocity.y = (float)v11 + (float)y;
  this->current.velocity.z = (float)v12 + (float)z;
  return 1;
}


// ========================================================================
// ?SetWaterLevel@idPhysics_Player@@UAAXMH@Z
// EA  : 0x82754B50
// RVA : 0x00754B50
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetWaterLevel(idPhysics_Player *this, double level, int id)
{
  int v4; // r30

  v4 = ((int (__fastcall *)(idPhysics_Player *, int, double))this->GetBounds)(a1: this, a2: -1, a3: level);
  _FP10 = (float)((float)(this->GetWaterSurfaceWrldHeight(this) - this->current.worldOrigin.z) / *(float *)(v4 + 20));
  __asm { fsel      f9, f10, f10, f13 }
  _FP8 = (float)((float)_FP9 - (float)1.0);
  __asm { fsel      f7, f8, f0, f9 }
  this->waterLevel = _FP7;
}


// ========================================================================
// ?SetClientDeferredOrigin@idPhysics_Player@@QAAXABVidVec3@@@Z
// EA  : 0x82754BE0
// RVA : 0x00754BE0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetClientDeferredOrigin(idPhysics_Player *this, const idVec3 *nextOrigin)
{
  this->clientOriginSet = true;
  this->nextClientOrigin = *nextOrigin;
}


// ========================================================================
// ?SetClipModel@idPhysics_Player@@UAAXPAVidClipModel@@MH_N@Z
// EA  : 0x82754C10
// RVA : 0x00754C10
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetClipModel(
        idPhysics_Player *this,
        idClipModel *model,
        double density,
        int id,
        unsigned int freeOld,
        char a6)
{
  idClipModel *clipModel_standing; // r3
  idClipModel *clipModel_crouched; // r3
  idClipModel *clipModel_sprintSlide; // r3
  idClipModel *clipModel_dead; // r3
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v18; // fp10
  double v19; // fp9
  idClipModel *v20; // r3
  idClipModel *v21; // r3
  idClipModel *v22; // r3
  idClipModel *v23; // r3
  idClipModel *v24; // r3
  idClipModel *v25; // r3
  double v26; // fp29
  double Radius; // fp1
  idClipModel *v28; // r3
  idClipModel *v29; // r3
  int v30; // r4
  idClipModel *v31; // r3
  idClipModel *v32; // r3
  idClipModel *v33; // r3
  idClipModel *v34; // r3
  idClipModel *v35; // r3
  idClipModel *v36; // r3
  idClipModel *v37; // r3
  idClipModel *v38; // r3
  int v39; // r5
  idBounds v40; // [sp+60h] [-30A0h] BYREF
  idTraceModel v41; // [sp+80h] [-3080h] BYREF
  idTraceModel v42; // [sp+680h] [-2A80h] BYREF
  idTraceModel v43; // [sp+C80h] [-2480h] BYREF
  idTraceModel v44; // [sp+1280h] [-1E80h] BYREF
  idTraceModel v45; // [sp+1880h] [-1880h] BYREF
  idTraceModel v46; // [sp+1E80h] [-1280h] BYREF
  idTraceModel v47; // [sp+2480h] [-C80h] BYREF
  idTraceModel v48; // [sp+2A80h] [-680h] BYREF

  clipModel_standing = this->clipModel_standing;
  if ( clipModel_standing != nullptr )
  {
    idClipModel::Delete(this: clipModel_standing);
    this->clipModel_standing = nullptr;
  }
  clipModel_crouched = this->clipModel_crouched;
  if ( clipModel_crouched != nullptr )
  {
    idClipModel::Delete(this: clipModel_crouched);
    this->clipModel_crouched = nullptr;
  }
  clipModel_sprintSlide = this->clipModel_sprintSlide;
  if ( clipModel_sprintSlide != nullptr )
  {
    idClipModel::Delete(this: clipModel_sprintSlide);
    this->clipModel_sprintSlide = nullptr;
  }
  clipModel_dead = this->clipModel_dead;
  if ( clipModel_dead != nullptr )
  {
    idClipModel::Delete(this: clipModel_dead);
    this->clipModel_dead = nullptr;
  }
  this->clipModels[0] = nullptr;
  if ( model != nullptr )
  {
    y = model->bounds.b[0].y;
    z = model->bounds.b[0].z;
    x = model->bounds.b[1].x;
    v18 = model->bounds.b[1].y;
    v19 = model->bounds.b[1].z;
    v40.b[0].x = model->bounds.b[0].x;
    v40.b[0].y = y;
    v40.b[0].z = z;
    v40.b[1].x = x;
    v40.b[1].y = v18;
    v40.b[1].z = v19;
    idClipModel::Delete(this: model);
  }
  else
  {
    v40.b[0].x = pm_bboxwidth.valueFloat * (float)-0.5;
    v40.b[0].y = v40.b[0].x;
    v40.b[0].z = 0.0;
    v40.b[1].x = pm_bboxwidth.valueFloat * (float)0.5;
    v40.b[1].y = v40.b[1].x;
  }
  v40.b[1].z = pm_normalheight.valueFloat;
  if ( pm_usecylinder.valueInteger != 0 )
  {
    idTraceModel::SetupCylinder(this: &v42, cylBounds: &v40, numSides: 8);
    v20 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v20 != nullptr )
      v21 = idClipModel::idClipModel(
              this: v20,
              clip: this->clip,
              trm: &v42,
              numTraceModels: 1,
              material: this->overrideClipMaterial);
    else
      v21 = nullptr;
    this->clipModel_standing = v21;
    idClipModel::SetContents(this: v21, newContents: 0x8000);
    idClipModel::Translate(this: this->clipModel_standing, translation: &this->current.worldOrigin);
    v40.b[1].z = pm_crouchheight.valueFloat;
    idTraceModel::SetupCylinder(this: &v44, cylBounds: &v40, numSides: 8);
    v22 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v22 != nullptr )
      v23 = idClipModel::idClipModel(
              this: v22,
              clip: this->clip,
              trm: &v44,
              numTraceModels: 1,
              material: this->overrideClipMaterial);
    else
      v23 = nullptr;
    this->clipModel_crouched = v23;
    idClipModel::SetContents(this: v23, newContents: 0x8000);
    idClipModel::Translate(this: this->clipModel_crouched, translation: &this->current.worldOrigin);
    v40.b[1].z = pm_sprintslideheight.valueFloat;
    idTraceModel::SetupCylinder(this: &v46, cylBounds: &v40, numSides: 8);
    v24 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v24 != nullptr )
      v25 = idClipModel::idClipModel(
              this: v24,
              clip: this->clip,
              trm: &v46,
              numTraceModels: 1,
              material: this->overrideClipMaterial);
    else
      v25 = nullptr;
    this->clipModel_sprintSlide = v25;
    idClipModel::SetContents(this: v25, newContents: 0x8000);
    idClipModel::Translate(this: this->clipModel_sprintSlide, translation: &this->current.worldOrigin);
    if ( common->IsMultiplayer(this: common) )
    {
      v26 = (float)(idBounds::GetRadius(this: &v40) * (float)0.5);
      Radius = idBounds::GetRadius(this: &v40);
      v40.b[0].y = v40.b[0].y - (float)v26;
      v40.b[1].y = v40.b[1].y + (float)v26;
      v40.b[0].x = v40.b[0].x - (float)((float)Radius * (float)0.5);
      v40.b[1].x = v40.b[1].x + (float)((float)Radius * (float)0.5);
      v40.b[1].z = pm_crouchheight.valueFloat * 1.5;
    }
    else
    {
      v40.b[1].z = pm_deadheight.valueFloat;
    }
    idTraceModel::SetupCylinder(this: &v48, cylBounds: &v40, numSides: 8);
    v28 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v28 != nullptr )
      v29 = idClipModel::idClipModel(
              this: v28,
              clip: this->clip,
              trm: &v48,
              numTraceModels: 1,
              material: this->overrideClipMaterial);
    else
      v29 = nullptr;
    this->clipModel_dead = v29;
    if ( !common->IsMultiplayer(this: common) || (v30 = 0x200000, pm_deadClipModel_mp.valueInteger == 0) )
      v30 = 0x8000;
  }
  else
  {
    idTraceModel::InitBox(this: &v47);
    idTraceModel::SetupBox(this: &v47, boxBounds: &v40);
    v31 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v31 != nullptr )
      v32 = idClipModel::idClipModel(
              this: v31,
              clip: this->clip,
              trm: &v47,
              numTraceModels: 1,
              material: this->overrideClipMaterial);
    else
      v32 = nullptr;
    this->clipModel_standing = v32;
    idClipModel::SetContents(this: v32, newContents: 0x8000);
    idClipModel::Translate(this: this->clipModel_standing, translation: &this->current.worldOrigin);
    v40.b[1].z = pm_crouchheight.valueFloat;
    idTraceModel::InitBox(this: &v43);
    idTraceModel::SetupBox(this: &v43, boxBounds: &v40);
    v33 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v33 != nullptr )
      v34 = idClipModel::idClipModel(
              this: v33,
              clip: this->clip,
              trm: &v43,
              numTraceModels: 1,
              material: this->overrideClipMaterial);
    else
      v34 = nullptr;
    this->clipModel_crouched = v34;
    idClipModel::SetContents(this: v34, newContents: 0x8000);
    idClipModel::Translate(this: this->clipModel_crouched, translation: &this->current.worldOrigin);
    v40.b[1].z = pm_sprintslideheight.valueFloat;
    idTraceModel::InitBox(this: &v41);
    idTraceModel::SetupBox(this: &v41, boxBounds: &v40);
    v35 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v35 != nullptr )
      v36 = idClipModel::idClipModel(
              this: v35,
              clip: this->clip,
              trm: &v41,
              numTraceModels: 1,
              material: this->overrideClipMaterial);
    else
      v36 = nullptr;
    this->clipModel_sprintSlide = v36;
    idClipModel::SetContents(this: v36, newContents: 0x8000);
    idClipModel::Translate(this: this->clipModel_sprintSlide, translation: &this->current.worldOrigin);
    v40.b[1].z = pm_deadheight.valueFloat;
    idTraceModel::InitBox(this: &v45);
    idTraceModel::SetupBox(this: &v45, boxBounds: &v40);
    v37 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v37 != nullptr )
      v38 = idClipModel::idClipModel(
              this: v37,
              clip: this->clip,
              trm: &v45,
              numTraceModels: 1,
              material: this->overrideClipMaterial);
    else
      v38 = nullptr;
    this->clipModel_dead = v38;
    idClipModel::SetContents(this: v38, newContents: 0x8000);
    if ( !common->IsMultiplayer(this: common) || (v30 = 0x200000, pm_deadClipModel_mp.valueInteger == 0) )
      v30 = 0x8000;
  }
  idClipModel::SetContents(this: this->clipModel_dead, newContents: v30);
  idClipModel::Translate(this: this->clipModel_dead, translation: &this->current.worldOrigin);
  idPhysics_Actor::SetClipModel(this, model: this->clipModel_standing, density, id: v39, freeOld, a6);
}


// ========================================================================
// __unwind$249804_0
// EA  : 0x827552C8
// RVA : 0x007552C8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void _unwind_249804_0()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12544 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$249805
// EA  : 0x827552F4
// RVA : 0x007552F4
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void _unwind_249805()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12544 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$249806
// EA  : 0x82755320
// RVA : 0x00755320
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void _unwind_249806()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12544 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$249807
// EA  : 0x8275534C
// RVA : 0x0075534C
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void _unwind_249807()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12544 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$249808
// EA  : 0x82755378
// RVA : 0x00755378
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void _unwind_249808()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12544 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$249809
// EA  : 0x827553A4
// RVA : 0x007553A4
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void _unwind_249809()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12544 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$249810
// EA  : 0x827553D0
// RVA : 0x007553D0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void _unwind_249810()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12544 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// __unwind$249811
// EA  : 0x827553FC
// RVA : 0x007553FC
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void _unwind_249811()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 12544 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?SetPlayerInput@idPhysics_Player@@QAAXABVusercmd_t@@0ABVidAngles@@@Z
// EA  : 0x82755428
// RVA : 0x00755428
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetPlayerInput(
        idPhysics_Player *this,
        const usercmd_t *_prevcmd,
        const usercmd_t *cmd,
        const idAngles *newViewAngles)
{
  memcpy(Dst: &this->prevcmd, Src: _prevcmd, Size: sizeof(this->prevcmd));
  memcpy(Dst: &this->command, Src: cmd, Size: sizeof(this->command));
  this->viewAngles = *newViewAngles;
}


// ========================================================================
// ?GetImpactInfo@idPhysics_Player@@UBAXHABVidVec3@@AAUimpactInfo_t@@@Z
// EA  : 0x82755480
// RVA : 0x00755480
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::GetImpactInfo(
        idPhysics_Player *this,
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
  info->velocity = this->current.velocity;
}


// ========================================================================
// ?ApplyImpulse@idPhysics_Player@@UAAXHABVidVec3@@0@Z
// EA  : 0x827554F0
// RVA : 0x007554F0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::ApplyImpulse(
        idPhysics_Player *this,
        const int id,
        const idVec3 *point,
        const idVec3 *impulse)
{
  double v4; // fp9
  double v5; // fp8
  double y; // fp6
  double z; // fp5

  if ( this->current.movementType != PM_NOCLIP )
  {
    v4 = (float)(impulse->y * this->invMass);
    v5 = (float)(impulse->z * this->invMass);
    y = this->externalVelocity.y;
    z = this->externalVelocity.z;
    this->externalVelocity.x = this->externalVelocity.x + (float)(impulse->x * this->invMass);
    this->externalVelocity.y = (float)y + (float)v4;
    this->externalVelocity.z = (float)z + (float)v5;
  }
}


// ========================================================================
// ?RestoreStateFromState@idPhysics_Player@@UAAXAAUplayerPState_t@@@Z
// EA  : 0x82755548
// RVA : 0x00755548
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::RestoreStateFromState(idPhysics_Player *this, playerPState_t *state_)
{
  this->current = *state_;
  idClipModel::Link(
    this: this->clipModels[0],
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin: &this->current.worldOrigin,
    newAxis: &this->clipModels[0]->axis);
  this->EvaluateContacts(this);
}


// ========================================================================
// ?SaveState@idPhysics_Player@@UAAXXZ
// EA  : 0x82755640
// RVA : 0x00755640
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SaveState(idPhysics_Player *this)
{
  this->saved = this->current;
}


// ========================================================================
// ?SetOrigin@idPhysics_Player@@UAAXABVidVec3@@H@Z
// EA  : 0x827556E8
// RVA : 0x007556E8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysics_Player::SetOrigin(idPhysics_Player *this, const idVec3 *newOrigin, int id)
{
  idClip *clip; // r11
  unsigned __int64 index; // r10
  unsigned __int64 v7; // r6
  __int64 v8; // r8
  idClip *v9; // r11
  unsigned __int64 v10; // r10
  __int64 v11; // r8 OVERLAPPED
  idClip *v12; // r11
  unsigned __int64 v13; // r10 OVERLAPPED
  double v14; // fp2
  double v15; // fp11
  double v16; // fp7
  double v17; // fp4
  double v18; // fp3
  float v19; // [sp+50h] [-50h] BYREF
  float v20; // [sp+54h] [-4Ch]
  float v21; // [sp+58h] [-48h]
  float v22[10]; // [sp+60h] [-40h] BYREF

  clip = this->clip;
  index = this->slideMoveQuery.index;
  v7 = *(_QWORD *)((char *)&clip->world + (HIDWORD(index) | 0xC178));
  if ( (unsigned int)index >= (unsigned int)v7 )
  {
    v8 = *(_QWORD *)((char *)&clip->world + HIDWORD(v7));
    if ( (unsigned int)index <= (unsigned int)v8 )
      clip->collisionQueries[index & 0xFFF].type = HIDWORD(v8);
  }
  LODWORD(v7) = 0;
  this->slideMoveQuery.index = v7;
  v9 = this->clip;
  v10 = this->ladderQuery1.index;
  v11 = *(_QWORD *)((char *)&v9->world + HIDWORD(v10));
  if ( (unsigned int)v10 >= (unsigned int)v11 )
  {
    v11 = *(_QWORD *)((char *)&v9->world + HIDWORD(v7));
    if ( (unsigned int)v10 <= (unsigned int)v11 )
      v9->collisionQueries[v10 & 0xFFF].type = HIDWORD(v11);
  }
  this->ladderQuery1.index = v7;
  v12 = this->clip;
  v13 = this->ladderQuery2.index;
  *(__int64 *)((char *)&v11 - 4) = *(_QWORD *)((char *)&v12->world + HIDWORD(v13));
  if ( (unsigned int)v13 >= HIDWORD(v13) )
  {
    *(__int64 *)((char *)&v11 - 4) = *(_QWORD *)((char *)&v12->world + HIDWORD(v7));
    if ( (unsigned int)v13 <= HIDWORD(v13) )
      v12->collisionQueries[v13 & 0xFFF].type = HIDWORD(v11);
  }
  this->ladderQuery2.index = v7;
  this->clientOriginSet = false;
  this->current.worldOrigin = *newOrigin;
  if ( this->hasMaster )
  {
    ((void (__fastcall *)(idPhysicsCallbacks *, float *, float *, _DWORD, _DWORD, _DWORD))this->callbacks->GetMasterPosition)(
      a1: this->callbacks,
      a2: &v19,
      a3: v22,
      a4: 0,
      a5: HIDWORD(v11),
      a6: v11);
    v14 = (float)(newOrigin->z - v21);
    v15 = v22[5];
    v16 = v22[8];
    v17 = (float)((float)(v22[4] * (float)(newOrigin->y - v20)) + (float)(v22[3] * (float)(newOrigin->x - v19)));
    v18 = (float)((float)(v22[6] * (float)(newOrigin->x - v19)) + (float)(v22[7] * (float)(newOrigin->y - v20)));
    this->current.localOrigin.x = (float)(v22[2] * (float)(newOrigin->z - v21))
                                + (float)((float)(v22[1] * (float)(newOrigin->y - v20))
                                        + (float)(v22[0] * (float)(newOrigin->x - v19)));
    this->current.localOrigin.y = (float)((float)v15 * (float)v14) + (float)v17;
    this->current.localOrigin.z = (float)((float)v16 * (float)v14) + (float)v18;
  }
  else
  {
    this->current.localOrigin = *newOrigin;
  }
  idClipModel::Link(
    this: this->clipModels[0],
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin,
    newAxis: &this->clipModels[0]->axis);
}


// ========================================================================
// ?SetAxis@idPhysics_Player@@UAAXABVidMat3@@H@Z
// EA  : 0x827558E0
// RVA : 0x007558E0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysics_Player::SetAxis(idPhysics_Player *this, const idMat3 *newAxis, int id)
{
  idClip *clip; // r10
  unsigned __int64 index; // r9
  unsigned __int64 collisionQueryFirstSubmittedIndex; // r5 OVERLAPPED
  idClip *v6; // r10
  unsigned __int64 v7; // r9
  unsigned int v8; // r6
  unsigned int v9; // r6
  idClip *v10; // r10
  unsigned __int64 v11; // r9

  clip = this->clip;
  index = this->slideMoveQuery.index;
  collisionQueryFirstSubmittedIndex = clip->collisionQueryFirstSubmittedIndex;
  if ( (unsigned int)index >= (unsigned int)collisionQueryFirstSubmittedIndex
    && (unsigned int)index <= LODWORD(clip->collisionQueryLastAllocedIndex) )
  {
    clip->collisionQueries[index & 0xFFF].type = QUERY_CANCELED;
  }
  LODWORD(collisionQueryFirstSubmittedIndex) = 0;
  this->slideMoveQuery.index = collisionQueryFirstSubmittedIndex;
  v6 = this->clip;
  v7 = this->ladderQuery1.index;
  *(unsigned __int64 *)((char *)&collisionQueryFirstSubmittedIndex - 4) = v6->collisionQueryFirstSubmittedIndex;
  if ( (unsigned int)v7 >= v8 )
  {
    *(unsigned __int64 *)((char *)&collisionQueryFirstSubmittedIndex - 4) = v6->collisionQueryLastAllocedIndex;
    if ( (unsigned int)v7 <= v9 )
      v6->collisionQueries[v7 & 0xFFF].type = QUERY_CANCELED;
  }
  this->ladderQuery1.index = collisionQueryFirstSubmittedIndex;
  v10 = this->clip;
  v11 = this->ladderQuery2.index;
  if ( (unsigned int)v11 >= LODWORD(v10->collisionQueryFirstSubmittedIndex)
    && (unsigned int)v11 <= LODWORD(v10->collisionQueryLastAllocedIndex) )
  {
    v10->collisionQueries[v11 & 0xFFF].type = QUERY_CANCELED;
  }
  this->ladderQuery2.index = collisionQueryFirstSubmittedIndex;
  HIDWORD(collisionQueryFirstSubmittedIndex) = this->entityNumber;
  this->clientOriginSet = collisionQueryFirstSubmittedIndex;
  idClipModel::Link(
    this: this->clipModels[0],
    newEntityNumber: SHIDWORD(collisionQueryFirstSubmittedIndex),
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin: &this->clipModels[0]->origin,
    newAxis: (const idMat3 *)HIDWORD(v11));
}


// ========================================================================
// ?SetLinearVelocity@idPhysics_Player@@UAAXABVidVec3@@H@Z
// EA  : 0x827559F8
// RVA : 0x007559F8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetLinearVelocity(idPhysics_Player *this, const idVec3 *newLinearVelocity, int id)
{
  this->current.velocity = *newLinearVelocity;
  this->current.movementFlags |= 0x100u;
}


// ========================================================================
// ?SetPushed@idPhysics_Player@@UAAXH@Z
// EA  : 0x82755A20
// RVA : 0x00755A20
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetPushed(idPhysics_Player *this, unsigned int deltaTime)
{
  double v2; // fp8
  double v3; // fp3
  double v4; // fp5

  v2 = (float)(this->current.worldOrigin.x - this->saved.worldOrigin.x);
  v3 = (float)(this->current.worldOrigin.z - this->saved.worldOrigin.z);
  v4 = (float)(this->current.worldOrigin.y - this->saved.worldOrigin.y);
  this->pushDeltaZ = this->current.worldOrigin.z - this->saved.worldOrigin.z;
  this->current.pushVelocity.x = (float)((float)1.0
                                       / (float)((float)__SPAIR64__(&unk_82390000, deltaTime) * (float)0.001))
                               * (float)v2;
  this->current.pushVelocity.y = (float)((float)1.0
                                       / (float)((float)__SPAIR64__(&unk_82390000, deltaTime) * (float)0.001))
                               * (float)v4;
  this->current.pushVelocity.z = (float)((float)1.0
                                       / (float)((float)__SPAIR64__(&unk_82390000, deltaTime) * (float)0.001))
                               * (float)v3;
}


// ========================================================================
// ?ClearPushedVelocity@idPhysics_Player@@UAAXXZ
// EA  : 0x82755AA0
// RVA : 0x00755AA0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::ClearPushedVelocity(idPhysics_Player *this)
{
  this->current.pushVelocity.z = 0.0;
  this->current.pushVelocity.y = 0.0;
  this->current.pushVelocity.x = 0.0;
  this->pushDeltaZ = 0.0;
}


// ========================================================================
// ?ClientPusherLocked@idPhysics_Player@@QAA_NAA_N@Z
// EA  : 0x82755AC0
// RVA : 0x00755AC0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

BOOL __fastcall idPhysics_Player::ClientPusherLocked(idPhysics_Player *this, bool *justBecameUnlocked)
{
  char v5; // r26
  char v6; // r27
  int v7; // r28
  idVec3 *p_gravityNormal; // r29
  int v9; // r30
  idPhysics *PhysicsForId; // r3
  physicsType_t type; // r11

  if ( (this->lastContents & 1) != 0 )
  {
    *justBecameUnlocked = false;
    return false;
  }
  else
  {
    v5 = 0;
    v6 = 0;
    v7 = 0;
    if ( this->contacts.num > 0 )
    {
      p_gravityNormal = &this->gravityNormal;
      v9 = 0;
      do
      {
        PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: this->contacts.list[v9].physicsId);
        if ( PhysicsForId != nullptr )
        {
          type = PhysicsForId->type;
          if ( type != PHYSICS_STATIC && type != PHYSICS_STATICMULTI )
          {
            v5 = 1;
            this->clientPusherLocked = true;
          }
        }
        if ( (float)((float)(this->contacts.list[v9].normal.x * (float)-p_gravityNormal->x)
                   + (float)((float)(this->contacts.list[v9].normal.z * (float)-this->gravityNormal.z)
                           + (float)(this->contacts.list[v9].normal.y * (float)-this->gravityNormal.y))) > 0.0 )
          v6 = 1;
        ++v7;
        ++v9;
      }
      while ( v7 < this->contacts.num );
    }
    *justBecameUnlocked = false;
    if ( v6 != 0 && v5 == 0 )
    {
      if ( this->clientPusherLocked )
        *justBecameUnlocked = true;
      this->clientPusherLocked = false;
    }
    return this->clientPusherLocked;
  }
}


// ========================================================================
// ?SetMaster@idPhysics_Player@@UAAX_NABVidVec3@@ABVidMat3@@W4bindFlags_t@@@Z
// EA  : 0x82755C00
// RVA : 0x00755C00
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetMaster(
        idPhysics_Player *this,
        bool enable,
        const idVec3 *masterOrigin,
        const idMat3 *masterAxis,
        bindFlags_t bflags)
{
  double v6; // fp2
  double x; // fp11
  double v8; // fp7
  double v9; // fp1
  double v10; // fp0

  if ( enable )
  {
    if ( !this->hasMaster )
    {
      v6 = (float)(this->current.worldOrigin.x - masterOrigin->x);
      x = masterAxis->mat[2].x;
      v8 = masterAxis->mat[1].x;
      v9 = (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y) * masterAxis->mat[1].y)
                 + (float)((float)(this->current.worldOrigin.z - masterOrigin->z) * masterAxis->mat[1].z));
      v10 = (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y) * masterAxis->mat[2].y)
                  + (float)((float)(this->current.worldOrigin.z - masterOrigin->z) * masterAxis->mat[2].z));
      this->current.localOrigin.x = (float)((float)(this->current.worldOrigin.x - masterOrigin->x) * masterAxis->mat[0].x)
                                  + (float)((float)((float)(this->current.worldOrigin.y - masterOrigin->y)
                                                  * masterAxis->mat[0].y)
                                          + (float)((float)(this->current.worldOrigin.z - masterOrigin->z)
                                                  * masterAxis->mat[0].z));
      this->current.localOrigin.y = (float)((float)v6 * (float)v8) + (float)v9;
      this->current.localOrigin.z = (float)((float)v6 * (float)x) + (float)v10;
      this->hasMaster = true;
      this->masterYaw = idVec3::ToYaw(this: masterAxis->mat);
    }
    ((void (__fastcall *)(idPhysics_Player *, bool, const idVec3 *, const idMat3 *, bindFlags_t))this->ClearContacts)(
      a1: this,
      a2: enable,
      a3: masterOrigin,
      a4: masterAxis,
      a5: bflags);
  }
  else if ( this->hasMaster )
  {
    this->hasMaster = false;
  }
}


// ========================================================================
// ?SetLocalOrigin@idPhysics_Player@@UAAXABVidVec3@@H@Z
// EA  : 0x82755D08
// RVA : 0x00755D08
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetLocalOrigin(idPhysics_Player *this, const idVec3 *newOrigin, int id)
{
  double v5; // fp10
  double v6; // fp8
  double v7; // fp6
  double v8; // fp5
  float v9[4]; // [sp+50h] [-50h] BYREF
  float v10[10]; // [sp+60h] [-40h] BYREF

  this->current.localOrigin = *newOrigin;
  if ( this->hasMaster )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v9, a3: (idMat3 *)v10);
    v5 = v9[1];
    v6 = v9[2];
    v7 = (float)((float)(newOrigin->x * v10[1])
               + (float)((float)(newOrigin->z * v10[7]) + (float)(newOrigin->y * v10[4])));
    v8 = (float)((float)(newOrigin->x * v10[2])
               + (float)((float)(newOrigin->z * v10[8]) + (float)(newOrigin->y * v10[5])));
    this->current.worldOrigin.x = (float)((float)(newOrigin->x * v10[0])
                                        + (float)((float)(newOrigin->z * v10[6]) + (float)(newOrigin->y * v10[3])))
                                + v9[0];
    this->current.worldOrigin.y = (float)v5 + (float)v7;
    this->current.worldOrigin.z = (float)v6 + (float)v8;
  }
  else
  {
    this->current.worldOrigin = *newOrigin;
  }
  idClipModel::Link(
    this: this->clipModels[0],
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin,
    newAxis: &this->clipModels[0]->axis);
}


// ========================================================================
// ?SetLocalAxis@idPhysics_Player@@UAAXABVidMat3@@H@Z
// EA  : 0x82755E30
// RVA : 0x00755E30
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetLocalAxis(idPhysics_Player *this, idMat3 *newAxis, int id)
{
  idMat3 *v5; // r4
  idVec3 *p_origin; // r30
  int physicsId; // r29
  int entityNumber; // r28
  const idMat3 *v9; // r3
  _BYTE v10[16]; // [sp+50h] [-90h] BYREF
  idMat3 v11; // [sp+60h] [-80h] BYREF
  idMat3 v12[2]; // [sp+90h] [-50h] BYREF

  if ( this->hasMaster )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v10, a3: &v11);
    v5 = newAxis;
    p_origin = &this->clipModels[0]->origin;
    physicsId = this->physicsId;
    entityNumber = this->entityNumber;
    v9 = idMat3::operator*(this: v12, result: v5, a: &v11);
    idClipModel::Link(
      this: this->clipModels[0],
      newEntityNumber: entityNumber,
      newPhysicsId: physicsId,
      newBodyId: 0,
      newOrigin: p_origin,
      newAxis: v9);
  }
  else
  {
    idClipModel::Link(
      this: this->clipModels[0],
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->clipModels[0]->origin,
      newAxis);
  }
}


// ========================================================================
// ?UpdateNonPredictiveClip@idPhysics_Player@@QAAXXZ
// EA  : 0x82755ED8
// RVA : 0x00755ED8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::UpdateNonPredictiveClip(idPhysics_Player *this)
{
  idClipModel *clipModel_crouched; // r11
  idClipModel *clipModel_dead; // r3

  idClipModel::Unlink(this: this->clipModels[0]);
  if ( this->current.movementType == PM_DEAD && pm_deadClipModel.valueInteger != 0 )
  {
    if ( pm_deadClipModel_mp.valueInteger != 0 && common->IsMultiplayer(this: common) )
      clipModel_crouched = this->clipModel_crouched;
    else
      clipModel_crouched = this->clipModel_dead;
  }
  else if ( (this->current.movementFlags & 1) != 0 )
  {
    clipModel_crouched = this->clipModel_crouched;
    this->playerSpeed = this->crouchSpeed;
  }
  else
  {
    clipModel_crouched = this->clipModel_standing;
  }
  this->clipModels[0] = clipModel_crouched;
  idClipModel::Link(
    this: clipModel_crouched,
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin: &this->current.worldOrigin,
    newAxis: &clipModel_crouched->axis);
  if ( common->IsMultiplayer(this: common) && pm_deadClipModel_mp.valueInteger != 0 )
  {
    clipModel_dead = this->clipModel_dead;
    if ( this->current.movementType == PM_DEAD )
    {
      idClipModel::Link(
        this: clipModel_dead,
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: 0,
        newOrigin: &this->current.worldOrigin,
        newAxis: &this->clipModels[0]->axis);
    }
    else if ( clipModel_dead->clipLinks != nullptr )
    {
      idClipModel::Unlink(this: clipModel_dead);
    }
  }
}


// ========================================================================
// ?SlideMoveNonDeferred@idPhysics_Player@@AAAX_N000H@Z
// EA  : 0x82756018
// RVA : 0x00756018
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SlideMoveNonDeferred(
        idPhysics_Player *this,
        bool gravity,
        bool stepUp,
        bool stepDown,
        bool push,
        int ignoreEntityNum)
{
  BOOL v8; // r15
  idVec3 *p_velocity; // r28
  double v13; // fp8
  double y; // fp6
  double z; // fp5
  double x; // fp26
  double v17; // fp24
  double v18; // fp23
  double frametime; // fp20
  int v20; // r10
  double v21; // fp13
  double v22; // fp12
  double v23; // fp9
  double v24; // fp10
  double v25; // fp0
  double v26; // fp8
  idPush *pusher; // r3
  int v28; // r25
  float *v29; // r11
  double v30; // fp6
  double v32; // fp3
  double v34; // fp1
  double v35; // fp11
  double v36; // fp6
  double v37; // fp3
  float *v38; // r22
  double v39; // fp16
  idVec3 *p_worldOrigin; // r29
  int v41; // r20
  idClipModel *v42; // r8
  double v43; // fp10
  double v44; // fp9
  double v45; // fp7
  double v46; // fp6
  int clipMask; // r10
  idClip *clip; // r4
  bool v49; // mr_fpscr48
  double v50; // fp1
  double v51; // fp0
  char v52; // r27
  idVec3 *p_gravityNormal; // r30
  double v54; // fp13
  double v55; // fp0
  double v56; // fp12
  bool v57; // r11
  idClipModel *v58; // r8
  double v59; // fp11
  double v60; // fp8
  double v61; // fp9
  int v62; // r10
  idClip *v63; // r4
  double v64; // fp9
  double v65; // fp8
  idClipModel *v66; // r8
  double v67; // fp6
  double v68; // fp5
  int v69; // r10
  idClip *v70; // r4
  double v71; // fp11
  double v72; // fp10
  idClipModel *v73; // r8
  int v74; // r10
  idClip *v75; // r4
  idClipModel *v76; // r8
  int v77; // r10
  double v78; // fp12
  double v79; // fp10
  idClip *v80; // r4
  double v81; // fp0
  double v82; // fp13
  double v83; // fp12
  idPush *v84; // r3
  double v85; // fp7
  double v86; // fp6
  double v87; // fp1
  double v88; // fp0
  double v89; // fp13
  double v90; // fp11
  double v91; // fp9
  double v92; // fp8
  double v93; // fp11
  bool v94; // mr_fpscr48
  double v95; // fp10
  char v96; // r9
  int v97; // r11
  float *v98; // r10
  double v99; // fp10
  double v100; // fp9
  double v101; // fp8
  double v102; // fp11
  int v103; // r8
  double v104; // fp30
  float *v105; // r11
  double v106; // fp29
  double v107; // fp28
  float v108; // r7
  float v109; // r9
  float *v110; // r11
  double v111; // fp3
  double v112; // fp2
  double v113; // fp1
  double v114; // fp0
  double v115; // fp11
  double v116; // fp10
  double v117; // fp9
  double v118; // fp0
  int v119; // r9
  float *v120; // r7
  double v121; // fp6
  double v122; // fp8
  double v123; // fp7
  double v124; // fp4
  double v125; // fp4
  double v126; // fp4
  int v127; // r11
  float *v128; // r10
  double v129; // fp8
  double v130; // fp7
  double v131; // fp6
  double v136; // fp10
  double v137; // fp9
  double v138; // fp12
  double v139; // fp11
  double v140; // fp12
  double v141; // fp11
  double v142; // fp10
  double v143; // fp9
  double v144; // fp4
  double v145; // fp0
  double v146; // fp11
  double v147; // fp13
  double v148; // fp7
  double v149; // fp12
  double v150; // fp0
  double v151; // fp13
  idClipModel *v152; // r8
  double v153; // fp7
  double v154; // fp6
  int v155; // r10
  idClip *v156; // r4
  double v157; // fp3
  double v158; // fp0
  double v159; // fp13
  double v160; // fp12
  double v161; // fp0
  double v162; // fp13
  double v163; // fp12
  int v164; // [sp+8h] [-3F8h]
  int v165; // [sp+8h] [-3F8h]
  int v166; // [sp+8h] [-3F8h]
  bool v167; // [sp+Fh] [-3F1h]
  bool v168; // [sp+Fh] [-3F1h]
  bool v169; // [sp+Fh] [-3F1h]
  const char *v170; // [sp+10h] [-3F0h]
  const char *v171; // [sp+10h] [-3F0h]
  const char *v172; // [sp+10h] [-3F0h]
  int v173; // [sp+14h] [-3ECh]
  int v174; // [sp+14h] [-3ECh]
  int v175; // [sp+14h] [-3ECh]
  int v176; // [sp+18h] [-3E8h]
  int v177; // [sp+18h] [-3E8h]
  int v178; // [sp+18h] [-3E8h]
  int v179; // [sp+1Ch] [-3E4h]
  int v180; // [sp+1Ch] [-3E4h]
  int v181; // [sp+1Ch] [-3E4h]
  int v182; // [sp+20h] [-3E0h]
  int v183; // [sp+20h] [-3E0h]
  int v184; // [sp+20h] [-3E0h]
  int v185; // [sp+24h] [-3DCh]
  int v186; // [sp+24h] [-3DCh]
  int v187; // [sp+24h] [-3DCh]
  int v188; // [sp+28h] [-3D8h]
  int v189; // [sp+28h] [-3D8h]
  int v190; // [sp+28h] [-3D8h]
  int v191; // [sp+2Ch] [-3D4h]
  int v192; // [sp+2Ch] [-3D4h]
  int v193; // [sp+2Ch] [-3D4h]
  int v194; // [sp+30h] [-3D0h]
  int v195; // [sp+30h] [-3D0h]
  int v196; // [sp+30h] [-3D0h]
  int v197; // [sp+34h] [-3CCh]
  int v198; // [sp+34h] [-3CCh]
  int v199; // [sp+34h] [-3CCh]
  int v200; // [sp+38h] [-3C8h]
  int v201; // [sp+38h] [-3C8h]
  int v202; // [sp+38h] [-3C8h]
  int v203; // [sp+3Ch] [-3C4h]
  int v204; // [sp+3Ch] [-3C4h]
  int v205; // [sp+3Ch] [-3C4h]
  int v206; // [sp+40h] [-3C0h]
  int v207; // [sp+40h] [-3C0h]
  int v208; // [sp+40h] [-3C0h]
  int v209; // [sp+44h] [-3BCh]
  int v210; // [sp+44h] [-3BCh]
  int v211; // [sp+44h] [-3BCh]
  int v212; // [sp+48h] [-3B8h]
  int v213; // [sp+48h] [-3B8h]
  int v214; // [sp+48h] [-3B8h]
  int v215; // [sp+4Ch] [-3B4h]
  int v216; // [sp+4Ch] [-3B4h]
  int v217; // [sp+4Ch] [-3B4h]
  int v218; // [sp+50h] [-3B0h]
  int v219; // [sp+50h] [-3B0h]
  int v220; // [sp+50h] [-3B0h]
  int v221; // [sp+58h] [-3A8h]
  int v222; // [sp+58h] [-3A8h]
  int v223; // [sp+58h] [-3A8h]
  int v224; // [sp+60h] [-3A0h]
  int v225; // [sp+60h] [-3A0h]
  int v226; // [sp+60h] [-3A0h]
  idVec3 velocity; // [sp+70h] [-390h]
  idVec3 v228; // [sp+80h] [-380h] BYREF
  idVec3 v229; // [sp+90h] [-370h] BYREF
  float v230; // [sp+A0h] [-360h]
  float v231; // [sp+A4h] [-35Ch]
  float v232; // [sp+A8h] [-358h]
  float v233; // [sp+ACh] [-354h]
  float v234; // [sp+B0h] [-350h]
  idVec3 v235; // [sp+B8h] [-348h]
  idVec3 v236; // [sp+C8h] [-338h] BYREF
  idVec3 v237; // [sp+D8h] [-328h] BYREF
  idVec3 v238; // [sp+E8h] [-318h] BYREF
  _BYTE v239[8]; // [sp+F8h] [-308h] BYREF
  trace_t v240; // [sp+100h] [-300h] BYREF
  float v241; // [sp+180h] [-280h] BYREF
  float v242; // [sp+184h] [-27Ch] BYREF
  float v243[14]; // [sp+188h] [-278h] BYREF
  trace_t v244; // [sp+1C0h] [-240h] BYREF
  char v245; // [sp+240h] [-1C0h] BYREF
  char v246; // [sp+248h] [-1B8h] BYREF
  char v247; // [sp+250h] [-1B0h] BYREF
  char v248; // [sp+258h] [-1A8h] BYREF
  trace_t v249[2]; // [sp+260h] [-1A0h] BYREF

  v8 = gravity;
  velocity = this->current.velocity;
  p_velocity = &this->current.velocity;
  if ( gravity )
  {
    v13 = (float)(this->gravityVector.z * this->frametime);
    y = this->current.velocity.y;
    z = this->current.velocity.z;
    velocity.y = (float)(this->gravityVector.y * this->frametime) + this->current.velocity.y;
    velocity.x = (float)(this->gravityVector.x * this->frametime) + p_velocity->x;
    velocity.z = (float)(this->gravityVector.z * this->frametime) + this->current.velocity.z;
    x = velocity.x;
    v17 = velocity.y;
    v18 = velocity.z;
    p_velocity->x = (float)(velocity.x + p_velocity->x) * (float)0.5;
    this->current.velocity.y = (float)(velocity.y + (float)y) * (float)0.5;
    this->current.velocity.z = (float)((float)((float)v13 + (float)z) + (float)z) * (float)0.5;
    if ( this->groundPlane )
      idVec3::ProjectOntoPlane(this: &this->current.velocity, normal: &this->groundTrace.c.normal, overBounce: 1.001);
  }
  else
  {
    v18 = velocity.z;
    v17 = velocity.y;
    x = velocity.x;
  }
  frametime = this->frametime;
  if ( this->groundPlane )
  {
    v20 = 1;
    v21 = this->groundTrace.c.normal.y;
    v22 = this->groundTrace.c.normal.z;
    v241 = this->groundTrace.c.normal.x;
    v242 = v21;
    v243[0] = v22;
  }
  else
  {
    v20 = 0;
  }
  v23 = p_velocity->x;
  v24 = p_velocity->y;
  v25 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v26 = p_velocity->z;
  pusher = this->pusher;
  v28 = v20 + 1;
  v29 = &v241 + 3 * v20;
  v30 = (float)((float)(p_velocity->y * p_velocity->y) + (float)(p_velocity->z * p_velocity->z));
  *v29 = p_velocity->x;
  v29[1] = v24;
  v29[2] = v26;
  _FP4 = (float)((float)((float)((float)v23 * (float)v23) + (float)v30) - (float)v25);
  v32 = (float)((float)((float)((float)v23 * (float)v23) + (float)v30) * (float)0.5);
  __asm { fsel      f2, f4, f5, f0 }
  v34 = __frsqrte(_FP2);
  v35 = (float)((float)-(float)((float)((float)((float)v34
                                              * (float)((float)((float)((float)v23 * (float)v23) + (float)v30)
                                                      * (float)0.5))
                                      * (float)v34)
                              - (float)1.5)
              * (float)v34);
  v36 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34
                                                                              * (float)((float)((float)((float)v23 * (float)v23)
                                                                                              + (float)v30)
                                                                                      * (float)0.5))
                                                                      * (float)v34)
                                                              - (float)1.5)
                                              * (float)v34)
                                      * (float)((float)((float)((float)v23 * (float)v23) + (float)v30) * (float)0.5))
                              * (float)((float)-(float)((float)((float)((float)v34
                                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                                      + (float)v30)
                                                                              * (float)0.5))
                                                              * (float)v34)
                                                      - (float)1.5)
                                      * (float)v34))
                      - (float)1.5);
  v37 = (float)-(float)((float)((float)((float)((float)v36 * (float)v35) * (float)v32) * (float)((float)v36 * (float)v35))
                      - (float)1.5);
  *v29 = (float)((float)v37 * (float)((float)v36 * (float)v35)) * (float)v23;
  v29[1] = (float)((float)v37 * (float)((float)v36 * (float)v35)) * (float)v24;
  v29[2] = (float)((float)v37 * (float)((float)v36 * (float)v35)) * (float)v26;
  if ( pusher != nullptr )
    idPush::InitSavingPushedPhysicsObjectState(this: pusher);
  v38 = &v243[3 * v28 - 3];
  v39 = 1000.0;
  v234 = 1000.0;
  p_worldOrigin = &this->current.worldOrigin;
  v41 = 0;
  v233 = 0.0010526315;
  do
  {
    v42 = this->clipModels[0];
    v43 = (float)((float)frametime * p_velocity->x);
    v44 = (float)((float)frametime * p_velocity->y);
    v45 = p_worldOrigin->x;
    v46 = this->current.worldOrigin.y;
    clipMask = this->clipMask;
    clip = this->clip;
    v229.z = (float)((float)frametime * p_velocity->z) + this->current.worldOrigin.z;
    v229.x = (float)v43 + (float)v45;
    v229.y = (float)v44 + (float)v46;
    idClip::Translation(
      this: (idClip *)&v245,
      result: clip,
      a3: &v240,
      start: &this->current.worldOrigin,
      end: &v229,
      clipModel: v42,
      startAxis: &v42->axis,
      clipMask,
      passEntityNumber: v164,
      moveClipModel: v167,
      userName: v170,
      a12: v173,
      a13: v176,
      a14: v179,
      a15: v182,
      a16: v185,
      a17: v188,
      a18: v191,
      a19: v194,
      a20: v197,
      a21: v200,
      a22: v203,
      a23: v206,
      a24: v209,
      a25: v212,
      a26: v215,
      a27: v218,
      a28: ignoreEntityNum,
      a29: v221,
      a30: false,
      a31: v224,
      a32: 0);
    frametime = (float)-(float)((float)(v240.fraction * (float)frametime) - (float)frametime);
    v49 = v240.fraction < 1.0;
    v50 = v240.endpos.y;
    v51 = v240.endpos.z;
    p_worldOrigin->x = v240.endpos.x;
    this->current.worldOrigin.y = v50;
    this->current.worldOrigin.z = v51;
    if ( !v49 )
      break;
    v52 = 0;
    if ( !stepUp )
      goto LABEL_25;
    p_gravityNormal = &this->gravityNormal;
    v54 = v240.c.normal.y;
    v55 = v240.c.normal.z;
    v56 = v240.c.normal.x;
    if ( (float)((float)(v240.c.normal.x * (float)-this->gravityNormal.x)
               + (float)((float)(v240.c.normal.z * (float)-this->gravityNormal.z)
                       + (float)(v240.c.normal.y * (float)-this->gravityNormal.y))) < 0.69999999 )
    {
      v57 = this->ladder || this->groundPlane;
      if ( !v57 )
      {
        v58 = this->clipModels[0];
        v59 = (float)(this->maxStepHeight * this->gravityNormal.y);
        v60 = this->current.worldOrigin.z;
        v61 = (float)(this->maxStepHeight * this->gravityNormal.z);
        v62 = this->clipMask;
        v63 = this->clip;
        v236.x = (float)(this->maxStepHeight * this->gravityNormal.x) + p_worldOrigin->x;
        v236.y = (float)v59 + (float)v50;
        v236.z = (float)v61 + (float)v60;
        idClip::Translation(
          this: (idClip *)&v246,
          result: v63,
          a3: &v244,
          start: &this->current.worldOrigin,
          end: &v236,
          clipModel: v58,
          startAxis: &v58->axis,
          clipMask: v62,
          passEntityNumber: v164,
          moveClipModel: v167,
          userName: v170,
          a12: v173,
          a13: v176,
          a14: v179,
          a15: v182,
          a16: v185,
          a17: v188,
          a18: v191,
          a19: v194,
          a20: v197,
          a21: v200,
          a22: v203,
          a23: v206,
          a24: v209,
          a25: v212,
          a26: v215,
          a27: v218,
          a28: ignoreEntityNum,
          a29: v221,
          a30: false,
          a31: v224,
          a32: 0);
        if ( v244.fraction >= 1.0
          || (v57 = true,
              (float)((float)(v244.c.normal.y * (float)-this->gravityNormal.y)
                    + (float)((float)(v244.c.normal.x * (float)-p_gravityNormal->x)
                            + (float)(v244.c.normal.z * (float)-this->gravityNormal.z))) <= 0.69999999) )
        {
          v57 = false;
        }
        v55 = v240.c.normal.z;
        v54 = v240.c.normal.y;
        v56 = v240.c.normal.x;
      }
      if ( v57 )
      {
        v64 = (float)(this->maxStepHeight * this->gravityNormal.y);
        v65 = (float)(this->maxStepHeight * this->gravityNormal.z);
        v66 = this->clipModels[0];
        v67 = this->current.worldOrigin.y;
        v68 = this->current.worldOrigin.z;
        v69 = this->clipMask;
        v70 = this->clip;
        v228.x = p_worldOrigin->x - (float)(this->maxStepHeight * p_gravityNormal->x);
        v228.y = (float)v67 - (float)v64;
        v228.z = (float)v68 - (float)v65;
        idClip::Translation(
          this: (idClip *)&v247,
          result: v70,
          a3: &v244,
          start: &this->current.worldOrigin,
          end: &v228,
          clipModel: v66,
          startAxis: &v66->axis,
          clipMask: v69,
          passEntityNumber: v164,
          moveClipModel: v167,
          userName: v170,
          a12: v173,
          a13: v176,
          a14: v179,
          a15: v182,
          a16: v185,
          a17: v188,
          a18: v191,
          a19: v194,
          a20: v197,
          a21: v200,
          a22: v203,
          a23: v206,
          a24: v209,
          a25: v212,
          a26: v215,
          a27: v218,
          a28: ignoreEntityNum,
          a29: v221,
          a30: false,
          a31: v224,
          a32: 0);
        v71 = (float)((float)frametime * p_velocity->y);
        v72 = (float)((float)frametime * p_velocity->z);
        v73 = this->clipModels[0];
        v74 = this->clipMask;
        v75 = this->clip;
        v228.x = v244.endpos.x + (float)((float)frametime * p_velocity->x);
        v228.y = v244.endpos.y + (float)v71;
        v228.z = v244.endpos.z + (float)v72;
        idClip::Translation(
          this: (idClip *)&v248,
          result: v75,
          a3: v249,
          start: &v244.endpos,
          end: &v228,
          clipModel: v73,
          startAxis: &v73->axis,
          clipMask: v74,
          passEntityNumber: v165,
          moveClipModel: v168,
          userName: v171,
          a12: v174,
          a13: v177,
          a14: v180,
          a15: v183,
          a16: v186,
          a17: v189,
          a18: v192,
          a19: v195,
          a20: v198,
          a21: v201,
          a22: v204,
          a23: v207,
          a24: v210,
          a25: v213,
          a26: v216,
          a27: v219,
          a28: ignoreEntityNum,
          a29: v222,
          a30: false,
          a31: v225,
          a32: 0);
        v76 = this->clipModels[0];
        v77 = this->clipMask;
        v78 = (float)(this->maxStepHeight * this->gravityNormal.y);
        v79 = (float)(this->maxStepHeight * this->gravityNormal.z);
        v80 = this->clip;
        v228.x = v249[0].endpos.x + (float)(this->maxStepHeight * p_gravityNormal->x);
        v228.y = v249[0].endpos.y + (float)v78;
        v228.z = v249[0].endpos.z + (float)v79;
        idClip::Translation(
          this: (idClip *)v239,
          result: v80,
          a3: &v244,
          start: &v249[0].endpos,
          end: &v228,
          clipModel: v76,
          startAxis: &v76->axis,
          clipMask: v77,
          passEntityNumber: v166,
          moveClipModel: v169,
          userName: v172,
          a12: v175,
          a13: v178,
          a14: v181,
          a15: v184,
          a16: v187,
          a17: v190,
          a18: v193,
          a19: v196,
          a20: v199,
          a21: v202,
          a22: v205,
          a23: v208,
          a24: v211,
          a25: v214,
          a26: v217,
          a27: v220,
          a28: ignoreEntityNum,
          a29: v223,
          a30: false,
          a31: v226,
          a32: 0);
        if ( v244.fraction >= 1.0
          || (float)((float)((float)-this->gravityNormal.z * v244.c.normal.z)
                   + (float)((float)((float)-p_gravityNormal->x * v244.c.normal.x)
                           + (float)((float)-this->gravityNormal.y * v244.c.normal.y))) > 0.69999999 )
        {
          if ( v249[0].fraction >= 1.0 )
          {
            v161 = v244.endpos.z;
            v162 = v244.endpos.x;
            v163 = v244.endpos.y;
            this->current.stepUp = this->current.stepUp
                                 - (float)((float)((float)(v244.endpos.y - this->current.worldOrigin.y)
                                                 * this->gravityNormal.y)
                                         + (float)((float)((float)(v244.endpos.x - this->current.worldOrigin.x)
                                                         * this->gravityNormal.x)
                                                 + (float)((float)(v244.endpos.z - this->current.worldOrigin.z)
                                                         * this->gravityNormal.z)));
            p_worldOrigin->x = v162;
            this->current.worldOrigin.y = v163;
            this->current.worldOrigin.z = v161;
            this->current.movementFlags |= 4u;
            break;
          }
          if ( v249[0].fraction > (double)v240.fraction )
          {
            frametime = (float)-(float)((float)(v249[0].fraction * (float)frametime) - (float)frametime);
            v81 = v244.endpos.z;
            v82 = v244.endpos.x;
            v83 = v244.endpos.y;
            this->current.stepUp = this->current.stepUp
                                 - (float)((float)((float)(v244.endpos.y - this->current.worldOrigin.y)
                                                 * this->gravityNormal.y)
                                         + (float)((float)((float)(v244.endpos.x - this->current.worldOrigin.x)
                                                         * this->gravityNormal.x)
                                                 + (float)((float)(v244.endpos.z - this->current.worldOrigin.z)
                                                         * this->gravityNormal.z)));
            this->current.worldOrigin.y = v83;
            p_worldOrigin->x = v82;
            this->current.worldOrigin.z = v81;
            this->current.movementFlags |= 4u;
            trace_t::operator=(this: &v240, __that: v249);
            v52 = 1;
          }
        }
LABEL_25:
        v56 = v240.c.normal.x;
        v54 = v240.c.normal.y;
        v55 = v240.c.normal.z;
      }
    }
    if ( push && v240.c.entityNum != 8190 )
    {
      idClipModel::SetLinkedPosition(
        this: this->clipModels[0],
        newOrigin: &this->current.worldOrigin,
        newAxis: &this->clipModels[0]->axis);
      v84 = this->pusher;
      if ( v84 != nullptr
        && (v85 = (float)(v229.y - this->current.worldOrigin.y),
            v86 = (float)(v229.z - this->current.worldOrigin.z),
            v237.x = v229.x - p_worldOrigin->x,
            v237.y = v85,
            v237.z = v86,
            (v87 = idPush::ClipTranslationalPush(
                     this: v84,
                     results: &v240,
                     pusher: this,
                     flags: 45,
                     newOrigin: &v229,
                     translation: &v237)) > 0.0) )
      {
        v88 = (float)((float)v87 - (float)20.0);
        if ( v88 >= 0.0 )
        {
          if ( v88 > v39 )
            v88 = v39;
        }
        else
        {
          v88 = 0.0;
        }
        v89 = 1.0;
        v90 = (float)-(float)((float)((float)v88 * v233) - 1.0);
        v91 = p_velocity->y;
        v92 = p_velocity->z;
        p_velocity->x = (float)-(float)((float)((float)v88 * v233) - 1.0) * p_velocity->x;
        p_velocity->y = (float)v90 * (float)v91;
        p_velocity->z = (float)v90 * (float)v92;
      }
      else
      {
        v89 = 1.0;
      }
      frametime = (float)-(float)((float)(v240.fraction * (float)frametime) - (float)frametime);
      v93 = v240.endpos.y;
      v94 = v240.fraction < v89;
      v95 = v240.endpos.z;
      p_worldOrigin->x = v240.endpos.x;
      this->current.worldOrigin.y = v93;
      this->current.worldOrigin.z = v95;
      if ( !v94 )
        break;
      v55 = v240.c.normal.z;
      v54 = v240.c.normal.y;
      v56 = v240.c.normal.x;
    }
    if ( v52 == 0 )
    {
      this->callbacks->Collide(this: this->callbacks, a2: this->physicsId, a3: &v240, a4: p_velocity);
      v55 = v240.c.normal.z;
      v54 = v240.c.normal.y;
      v56 = v240.c.normal.x;
    }
    if ( v28 >= 5 )
      goto LABEL_89;
    v96 = 0;
    v97 = 0;
    if ( v28 > 0 )
    {
      v98 = v243;
      while ( (float)((float)((float)v54 * *(v98 - 1))
                    + (float)((float)((float)v55 * *v98) + (float)((float)v56 * *(v98 - 2)))) <= 0.99900001 )
      {
        ++v97;
        v98 += 3;
        if ( v97 >= v28 )
          goto LABEL_50;
      }
      v99 = p_velocity->z;
      v100 = p_velocity->x;
      v101 = p_velocity->y;
      if ( (float)((float)((float)v54 * p_velocity->y)
                 + (float)((float)(p_velocity->x * (float)v56) + (float)((float)v55 * p_velocity->z))) >= 0.0 )
        v102 = (float)((float)((float)((float)v54 * p_velocity->y)
                             + (float)((float)(p_velocity->x * (float)v56) + (float)((float)v55 * p_velocity->z)))
                     * (float)0.99900097);
      else
        v102 = (float)((float)((float)((float)v54 * p_velocity->y)
                             + (float)((float)(p_velocity->x * (float)v56) + (float)((float)v55 * p_velocity->z)))
                     * 1.001);
      v96 = 1;
      p_velocity->x = p_velocity->x - (float)((float)v102 * (float)v56);
      p_velocity->y = (float)v101 - (float)((float)v54 * (float)v102);
      p_velocity->z = (float)v99 - (float)((float)v55 * (float)v102);
      p_velocity->x = (float)v56 + (float)((float)v100 - (float)((float)v102 * (float)v56));
      p_velocity->y = (float)v54 + (float)((float)v101 - (float)((float)v54 * (float)v102));
      p_velocity->z = (float)v55 + (float)((float)v99 - (float)((float)v55 * (float)v102));
    }
LABEL_50:
    if ( v96 == 0 )
    {
      v38[1] = v56;
      ++v28;
      v38[2] = v54;
      v103 = 0;
      v38 += 3;
      *v38 = v55;
      if ( v28 > 0 )
      {
        v104 = p_velocity->z;
        v105 = &v242;
        v106 = p_velocity->y;
        v107 = p_velocity->x;
        while ( (float)((float)(*(v105 - 1) * p_velocity->x)
                      + (float)((float)(v105[1] * p_velocity->z) + (float)(*v105 * p_velocity->y))) >= 0.1 )
        {
          ++v103;
          v105 += 3;
          if ( v103 >= v28 )
            goto LABEL_79;
        }
        v108 = p_velocity->x;
        v109 = p_velocity->z;
        v231 = p_velocity->y;
        v230 = v108;
        v110 = &v241 + 3 * v103;
        v232 = v109;
        v111 = v110[2];
        v112 = v110[1];
        v113 = *v110;
        if ( (float)((float)(*v110 * v108) + (float)((float)(v231 * v110[1]) + (float)(v109 * v110[2]))) >= 0.0 )
          v114 = (float)((float)((float)(*v110 * v108) + (float)((float)(v231 * v110[1]) + (float)(v109 * v110[2])))
                       * (float)0.99900097);
        else
          v114 = (float)((float)((float)(*v110 * v108) + (float)((float)(v231 * v110[1]) + (float)(v109 * v110[2])))
                       * (float)1.001);
        v235 = velocity;
        v115 = (float)(v108 - (float)((float)v113 * (float)v114));
        v116 = (float)(v231 - (float)((float)v112 * (float)v114));
        v117 = (float)(v109 - (float)((float)v111 * (float)v114));
        if ( (float)((float)((float)v18 * (float)v111)
                   + (float)((float)((float)v113 * (float)x) + (float)((float)v17 * (float)v112))) >= 0.0 )
          v118 = (float)((float)((float)((float)v18 * (float)v111)
                               + (float)((float)((float)v113 * (float)x) + (float)((float)v17 * (float)v112)))
                       * (float)0.99900097);
        else
          v118 = (float)((float)((float)((float)v18 * (float)v111)
                               + (float)((float)((float)v113 * (float)x) + (float)((float)v17 * (float)v112)))
                       * (float)1.001);
        v119 = 0;
        v120 = &v242;
        v121 = (float)(v235.z - (float)((float)v111 * (float)v118));
        v122 = (float)((float)x - (float)((float)v113 * (float)v118));
        v123 = (float)(v235.y - (float)((float)v112 * (float)v118));
        while ( 1 )
        {
          if ( v119 != v103 )
          {
            v124 = (float)((float)(*(v120 - 1) * (float)v115)
                         + (float)((float)((float)v117 * v120[1]) + (float)((float)v116 * *v120)));
            if ( v124 < 0.1 )
            {
              v125 = v124 >= 0.0
                   ? (float)((float)((float)(*(v120 - 1) * (float)v115)
                                   + (float)((float)((float)v117 * v120[1]) + (float)((float)v116 * *v120)))
                           * (float)0.99900097)
                   : (float)((float)((float)(*(v120 - 1) * (float)v115)
                                   + (float)((float)((float)v117 * v120[1]) + (float)((float)v116 * *v120)))
                           * (float)1.001);
              v115 = (float)((float)v115 - (float)(*(v120 - 1) * (float)v125));
              v116 = (float)((float)v116 - (float)((float)v125 * *v120));
              v117 = (float)((float)v117 - (float)(v120[1] * (float)v125));
              v126 = (float)((float)(*(v120 - 1) * (float)v122)
                           + (float)((float)((float)v121 * v120[1]) + (float)((float)v123 * *v120))) >= 0.0
                   ? (float)((float)((float)(*(v120 - 1) * (float)v122)
                                   + (float)((float)((float)v121 * v120[1]) + (float)((float)v123 * *v120)))
                           * (float)0.99900097)
                   : (float)((float)((float)(*(v120 - 1) * (float)v122)
                                   + (float)((float)((float)v121 * v120[1]) + (float)((float)v123 * *v120)))
                           * (float)1.001);
              v122 = (float)((float)v122 - (float)(*(v120 - 1) * (float)v126));
              v123 = (float)((float)v123 - (float)((float)v126 * *v120));
              v121 = (float)((float)v121 - (float)(v120[1] * (float)v126));
              if ( (float)((float)((float)v113 * (float)v115)
                         + (float)((float)((float)v116 * (float)v112) + (float)((float)v117 * (float)v111))) < 0.0 )
                break;
            }
          }
LABEL_77:
          ++v119;
          v120 += 3;
          if ( v119 >= v28 )
          {
            v39 = v234;
            x = v122;
            velocity.x = v122;
            v17 = v123;
            p_velocity->x = v115;
            v18 = v121;
            velocity.y = v123;
            p_velocity->y = v116;
            velocity.z = v121;
            p_velocity->z = v117;
            goto LABEL_79;
          }
        }
        v127 = 0;
        v128 = v243;
        v129 = (float)((float)((float)v111 * *(v120 - 1)) - (float)((float)v113 * v120[1]));
        v130 = (float)((float)((float)v113 * *v120) - (float)((float)v112 * *(v120 - 1)));
        v131 = (float)((float)((float)v112 * v120[1]) - (float)((float)v111 * *v120));
        _FP10 = (float)((float)((float)((float)v131 * (float)v131)
                              + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129)))
                      - idMath::FLT_SMALLEST_NON_DENORMAL);
        _FP9 = _FP10;
        __asm
        {
          fsel      f12, f10, f12, f5
          fsel      f11, f9, f11, f5
        }
        v136 = __frsqrte(_FP12);
        v137 = __frsqrte(_FP11);
        v138 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v136
                                                                                             * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129))) * (float)0.5))
                                                                                     * (float)v136)
                                                                             - (float)1.5)
                                                             * (float)v136)
                                                     * (float)((float)((float)((float)v131 * (float)v131)
                                                                     + (float)((float)((float)v130 * (float)v130)
                                                                             + (float)((float)v129 * (float)v129)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v136
                                                                                     * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129)))
                                                                                             * (float)0.5))
                                                                             * (float)v136)
                                                                     - (float)1.5)
                                                     * (float)v136))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v136
                                                             * (float)((float)((float)((float)v131 * (float)v131)
                                                                             + (float)((float)((float)v130 * (float)v130)
                                                                                     + (float)((float)v129 * (float)v129)))
                                                                     * (float)0.5))
                                                     * (float)v136)
                                             - (float)1.5)
                             * (float)v136));
        v139 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v137
                                                                                             * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129))) * (float)0.5))
                                                                                     * (float)v137)
                                                                             - (float)1.5)
                                                             * (float)v137)
                                                     * (float)((float)((float)((float)v131 * (float)v131)
                                                                     + (float)((float)((float)v130 * (float)v130)
                                                                             + (float)((float)v129 * (float)v129)))
                                                             * (float)0.5))
                                             * (float)((float)-(float)((float)((float)((float)v137
                                                                                     * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129)))
                                                                                             * (float)0.5))
                                                                             * (float)v137)
                                                                     - (float)1.5)
                                                     * (float)v137))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)((float)v137
                                                             * (float)((float)((float)((float)v131 * (float)v131)
                                                                             + (float)((float)((float)v130 * (float)v130)
                                                                                     + (float)((float)v129 * (float)v129)))
                                                                     * (float)0.5))
                                                     * (float)v137)
                                             - (float)1.5)
                             * (float)v137));
        v140 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v136 * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129))) * (float)0.5)) * (float)v136) - (float)1.5) * (float)v136)
                                                                                             * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129))) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v136 * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129))) * (float)0.5)) * (float)v136) - (float)1.5)
                                                                                             * (float)v136))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v136 * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129))) * (float)0.5))
                                                                                             * (float)v136)
                                                                                     - (float)1.5)
                                                                     * (float)v136))
                                                     * (float)((float)((float)((float)v131 * (float)v131)
                                                                     + (float)((float)((float)v130 * (float)v130)
                                                                             + (float)((float)v129 * (float)v129)))
                                                             * (float)0.5))
                                             * (float)v138)
                                     - (float)1.5)
                     * (float)v138);
        v141 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v137 * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129))) * (float)0.5)) * (float)v137) - (float)1.5) * (float)v137)
                                                                                             * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129))) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v137 * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129))) * (float)0.5)) * (float)v137) - (float)1.5)
                                                                                             * (float)v137))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v137 * (float)((float)((float)((float)v131 * (float)v131) + (float)((float)((float)v130 * (float)v130) + (float)((float)v129 * (float)v129))) * (float)0.5))
                                                                                             * (float)v137)
                                                                                     - (float)1.5)
                                                                     * (float)v137))
                                                     * (float)((float)((float)((float)v131 * (float)v131)
                                                                     + (float)((float)((float)v130 * (float)v130)
                                                                             + (float)((float)v129 * (float)v129)))
                                                             * (float)0.5))
                                             * (float)v139)
                                     - (float)1.5)
                     * (float)v139);
        v142 = (float)((float)((float)((float)v111 * *(v120 - 1)) - (float)((float)v113 * v120[1])) * (float)v140);
        v143 = (float)((float)((float)((float)v111 * *(v120 - 1)) - (float)((float)v113 * v120[1])) * (float)v141);
        v144 = (float)((float)((float)((float)v113 * *v120) - (float)((float)v112 * *(v120 - 1))) * (float)v141);
        v146 = (float)((float)v141 * (float)((float)((float)v112 * v120[1]) - (float)((float)v111 * *v120)));
        v145 = (float)((float)v140 * (float)((float)((float)v112 * v120[1]) - (float)((float)v111 * *v120)));
        v147 = (float)((float)((float)((float)((float)((float)v113 * *v120) - (float)((float)v112 * *(v120 - 1)))
                                     * (float)v140)
                             * (float)v104)
                     + (float)((float)((float)((float)((float)v111 * *(v120 - 1)) - (float)((float)v113 * v120[1]))
                                     * (float)v140)
                             * (float)v106));
        v149 = (float)((float)((float)v130 * (float)v140)
                     * (float)((float)((float)((float)v140
                                             * (float)((float)((float)v112 * v120[1]) - (float)((float)v111 * *v120)))
                                     * (float)v107)
                             + (float)((float)((float)((float)v130 * (float)v140) * (float)v104)
                                     + (float)((float)((float)((float)((float)v111 * *(v120 - 1))
                                                             - (float)((float)v113 * v120[1]))
                                                     * (float)v140)
                                             * (float)v106))));
        v148 = (float)((float)((float)v145 * (float)v107) + (float)v147);
        v150 = (float)((float)v145 * (float)((float)((float)v145 * (float)v107) + (float)v147));
        v151 = (float)((float)v142 * (float)v148);
        v122 = (float)((float)v146
                     * (float)((float)((float)v146 * (float)x)
                             + (float)((float)((float)v144 * (float)v18) + (float)((float)v143 * (float)v17))));
        v123 = (float)((float)v143
                     * (float)((float)((float)v146 * (float)x)
                             + (float)((float)((float)v144 * (float)v18) + (float)((float)v143 * (float)v17))));
        v121 = (float)((float)v144
                     * (float)((float)((float)v146 * (float)x)
                             + (float)((float)((float)v144 * (float)v18) + (float)((float)v143 * (float)v17))));
        v117 = v149;
        v115 = v150;
        v116 = v151;
        while ( v127 == v103
             || v127 == v119
             || (float)((float)((float)v150 * *(v128 - 2))
                      + (float)((float)((float)v149 * *v128) + (float)((float)v151 * *(v128 - 1)))) >= 0.1 )
        {
          ++v127;
          v128 += 3;
          if ( v127 >= v28 )
            goto LABEL_77;
        }
LABEL_89:
        p_velocity->z = 0.0;
        p_velocity->y = 0.0;
        p_velocity->x = 0.0;
        return;
      }
    }
LABEL_79:
    ++v41;
  }
  while ( v41 < 4 );
  if ( stepDown && this->groundPlane )
  {
    v152 = this->clipModels[0];
    v153 = (float)(this->maxStepHeight * this->gravityNormal.y);
    v154 = this->current.worldOrigin.y;
    v155 = this->clipMask;
    v156 = this->clip;
    v157 = (float)((float)(this->maxStepHeight * this->gravityNormal.x) + p_worldOrigin->x);
    v238.z = (float)(this->maxStepHeight * this->gravityNormal.z) + this->current.worldOrigin.z;
    v238.x = v157;
    v238.y = (float)v153 + (float)v154;
    idClip::Translation(
      this: (idClip *)v239,
      result: v156,
      a3: v249,
      start: &this->current.worldOrigin,
      end: &v238,
      clipModel: v152,
      startAxis: &v152->axis,
      clipMask: v155,
      passEntityNumber: v164,
      moveClipModel: v167,
      userName: v170,
      a12: v173,
      a13: v176,
      a14: v179,
      a15: v182,
      a16: v185,
      a17: v188,
      a18: v191,
      a19: v194,
      a20: v197,
      a21: v200,
      a22: v203,
      a23: v206,
      a24: v209,
      a25: v212,
      a26: v215,
      a27: v218,
      a28: ignoreEntityNum,
      a29: v221,
      a30: false,
      a31: v224,
      a32: 0);
    if ( v249[0].fraction > 0.000099999997 && v249[0].fraction < 1.0 )
    {
      v158 = v249[0].endpos.z;
      v159 = v249[0].endpos.x;
      v160 = v249[0].endpos.y;
      this->current.stepUp = this->current.stepUp
                           - (float)((float)((float)(v249[0].endpos.y - this->current.worldOrigin.y)
                                           * this->gravityNormal.y)
                                   + (float)((float)((float)(v249[0].endpos.x - this->current.worldOrigin.x)
                                                   * this->gravityNormal.x)
                                           + (float)((float)(v249[0].endpos.z - this->current.worldOrigin.z)
                                                   * this->gravityNormal.z)));
      p_worldOrigin->x = v159;
      this->current.worldOrigin.y = v160;
      this->current.worldOrigin.z = v158;
      this->current.movementFlags |= 8u;
    }
  }
  if ( v8 )
  {
    p_velocity->x = x;
    p_velocity->y = v17;
    p_velocity->z = v18;
  }
}


// ========================================================================
// ?CanStand@idPhysics_Player@@QBA_NXZ
// EA  : 0x82756DA8
// RVA : 0x00756DA8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

BOOL __fastcall idPhysics_Player::CanStand(idPhysics_Player *this)
{
  double y; // fp11
  double z; // fp10
  idClipModel *v3; // r8
  double v4; // fp8
  int clipMask; // r10
  double v6; // fp6
  idClip *clip; // r4
  int v9; // [sp+8h] [-118h]
  bool v10; // [sp+Fh] [-111h]
  const char *v11; // [sp+10h] [-110h]
  int v12; // [sp+14h] [-10Ch]
  int v13; // [sp+18h] [-108h]
  int v14; // [sp+1Ch] [-104h]
  int v15; // [sp+20h] [-100h]
  int v16; // [sp+24h] [-FCh]
  int v17; // [sp+28h] [-F8h]
  int v18; // [sp+2Ch] [-F4h]
  int v19; // [sp+30h] [-F0h]
  int v20; // [sp+34h] [-ECh]
  int v21; // [sp+38h] [-E8h]
  int v22; // [sp+3Ch] [-E4h]
  int v23; // [sp+40h] [-E0h]
  int v24; // [sp+44h] [-DCh]
  int v25; // [sp+48h] [-D8h]
  int v26; // [sp+4Ch] [-D4h]
  int v27; // [sp+50h] [-D0h]
  int entityNumber; // [sp+54h] [-CCh]
  int v29; // [sp+58h] [-C8h]
  int v30; // [sp+60h] [-C0h]
  idVec3 v31; // [sp+70h] [-B0h] BYREF
  char v32; // [sp+80h] [-A0h] BYREF
  trace_t v33; // [sp+90h] [-90h] BYREF

  y = this->gravityNormal.y;
  z = this->gravityNormal.z;
  v3 = this->clipModels[0];
  v4 = this->current.worldOrigin.y;
  clipMask = this->clipMask;
  v6 = this->current.worldOrigin.z;
  clip = this->clip;
  entityNumber = this->entityNumber;
  v31.x = this->current.worldOrigin.x
        - (float)(this->gravityNormal.x * (float)(pm_normalheight.valueFloat - pm_crouchheight.valueFloat));
  v31.y = (float)v4 - (float)((float)y * (float)(pm_normalheight.valueFloat - pm_crouchheight.valueFloat));
  v31.z = (float)v6 - (float)((float)z * (float)(pm_normalheight.valueFloat - pm_crouchheight.valueFloat));
  idClip::Translation(
    this: (idClip *)&v32,
    result: clip,
    a3: &v33,
    start: &this->current.worldOrigin,
    end: &v31,
    clipModel: v3,
    startAxis: &v3->axis,
    clipMask,
    passEntityNumber: v9,
    moveClipModel: v10,
    userName: v11,
    a12: v12,
    a13: v13,
    a14: v14,
    a15: v15,
    a16: v16,
    a17: v17,
    a18: v18,
    a19: v19,
    a20: v20,
    a21: v21,
    a22: v22,
    a23: v23,
    a24: v24,
    a25: v25,
    a26: v26,
    a27: v27,
    a28: entityNumber,
    a29: v29,
    a30: false,
    a31: v30,
    a32: 0);
  return v33.fraction >= 1.0;
}


// ========================================================================
// ?CheckGround@idPhysics_Player@@AAAXXZ
// EA  : 0x82756E70
// RVA : 0x00756E70
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::CheckGround(idPhysics_Player *this)
{
  float *v2; // r11
  int v3; // r8
  int v4; // r9
  double y; // fp13
  contactInfo_t *v6; // r10
  double z; // fp12
  double v8; // fp11
  double v9; // fp8
  double v11; // fp4
  double v13; // fp2
  double v14; // fp5
  double v15; // fp4
  double v16; // fp2
  idClip *clip; // r29
  unsigned __int64 v18; // r28
  idClipQuery *p_contentsQuery; // r30
  unsigned __int64 collisionQueryLastSubmittedIndex; // r8
  unsigned __int64 index; // r11
  int contentFlags; // r5
  idVec3 *p_velocity; // r6
  double v24; // fp7
  double v25; // fp3
  double v26; // fp2
  double v27; // fp8
  double v28; // fp7
  int movementFlags; // r10
  int v30; // r9
  const char *v31; // [sp+8h] [-138h]
  int v32; // [sp+Ch] [-134h]
  int v33; // [sp+10h] [-130h]
  int v34; // [sp+14h] [-12Ch]
  int v35; // [sp+18h] [-128h]
  int v36; // [sp+1Ch] [-124h]
  int v37; // [sp+20h] [-120h]
  int v38; // [sp+24h] [-11Ch]
  int v39; // [sp+28h] [-118h]
  int v40; // [sp+2Ch] [-114h]
  int v41; // [sp+30h] [-110h]
  int v42; // [sp+34h] [-10Ch]
  int v43; // [sp+38h] [-108h]
  int v44; // [sp+3Ch] [-104h]
  int v45; // [sp+40h] [-100h]
  int v46; // [sp+44h] [-FCh]
  int v47; // [sp+48h] [-F8h]
  int v48; // [sp+4Ch] [-F4h]
  int v49; // [sp+50h] [-F0h]
  char v50; // [sp+60h] [-E0h] BYREF
  trace_t v51; // [sp+70h] [-D0h] BYREF

  if ( !g_pm_deferredSlideMove )
  {
    idClipModel::SetLinkedPosition(
      this: this->clipModels[0],
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->clipModels[0]->axis);
    this->EvaluateContacts(this);
  }
  this->groundTrace.endpos.x = this->current.worldOrigin.x;
  this->groundTrace.endpos.y = this->current.worldOrigin.y;
  this->groundTrace.endpos.z = this->current.worldOrigin.z;
  v2 = (float *)this->clipModels[0];
  this->groundTrace.endAxis.mat[0].x = v2[11];
  this->groundTrace.endAxis.mat[0].y = v2[12];
  this->groundTrace.endAxis.mat[0].z = v2[13];
  this->groundTrace.endAxis.mat[1].x = v2[14];
  this->groundTrace.endAxis.mat[1].y = v2[15];
  this->groundTrace.endAxis.mat[1].z = v2[16];
  this->groundTrace.endAxis.mat[2].x = v2[17];
  this->groundTrace.endAxis.mat[2].y = v2[18];
  this->groundTrace.endAxis.mat[2].z = v2[19];
  if ( this->contacts.num != 0 )
  {
    this->groundTrace.fraction = 0.0;
    contactInfo_t::operator=(this: &this->groundTrace.c, __that: this->contacts.list);
    v3 = 1;
    if ( this->contacts.num > 1 )
    {
      v4 = 1;
      do
      {
        y = this->groundTrace.c.normal.y;
        ++v3;
        v6 = &this->contacts.list[v4];
        z = this->groundTrace.c.normal.z;
        ++v4;
        this->groundTrace.c.normal.x = this->groundTrace.c.normal.x + v6->normal.x;
        this->groundTrace.c.normal.y = v6->normal.y + (float)y;
        this->groundTrace.c.normal.z = v6->normal.z + (float)z;
      }
      while ( v3 < this->contacts.num );
    }
    v8 = this->groundTrace.c.normal.y;
    v9 = this->groundTrace.c.normal.z;
    _FP5 = (float)((float)((float)(this->groundTrace.c.normal.z * this->groundTrace.c.normal.z)
                         + (float)((float)(this->groundTrace.c.normal.x * this->groundTrace.c.normal.x)
                                 + (float)(this->groundTrace.c.normal.y * this->groundTrace.c.normal.y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v11 = (float)((float)((float)(this->groundTrace.c.normal.z * this->groundTrace.c.normal.z)
                        + (float)((float)(this->groundTrace.c.normal.x * this->groundTrace.c.normal.x)
                                + (float)(this->groundTrace.c.normal.y * this->groundTrace.c.normal.y)))
                * (float)0.5);
    __asm { fsel      f3, f5, f6, f13 }
    v13 = __frsqrte(_FP3);
    v14 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                                        * (float)((float)((float)(this->groundTrace.c.normal.z * this->groundTrace.c.normal.z) + (float)((float)(this->groundTrace.c.normal.x * this->groundTrace.c.normal.x) + (float)(this->groundTrace.c.normal.y * this->groundTrace.c.normal.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v13)
                                                                        - (float)1.5)
                                                        * (float)v13)
                                                * (float)((float)((float)(this->groundTrace.c.normal.z
                                                                        * this->groundTrace.c.normal.z)
                                                                + (float)((float)(this->groundTrace.c.normal.x
                                                                                * this->groundTrace.c.normal.x)
                                                                        + (float)(this->groundTrace.c.normal.y
                                                                                * this->groundTrace.c.normal.y)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v13
                                                                                * (float)((float)((float)(this->groundTrace.c.normal.z * this->groundTrace.c.normal.z)
                                                                                                + (float)((float)(this->groundTrace.c.normal.x * this->groundTrace.c.normal.x) + (float)(this->groundTrace.c.normal.y * this->groundTrace.c.normal.y)))
                                                                                        * (float)0.5))
                                                                        * (float)v13)
                                                                - (float)1.5)
                                                * (float)v13))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v13
                                                        * (float)((float)((float)(this->groundTrace.c.normal.z
                                                                                * this->groundTrace.c.normal.z)
                                                                        + (float)((float)(this->groundTrace.c.normal.x
                                                                                        * this->groundTrace.c.normal.x)
                                                                                + (float)(this->groundTrace.c.normal.y
                                                                                        * this->groundTrace.c.normal.y)))
                                                                * (float)0.5))
                                                * (float)v13)
                                        - (float)1.5)
                        * (float)v13));
    v15 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13
                                                                                                * (float)((float)((float)(this->groundTrace.c.normal.z * this->groundTrace.c.normal.z) + (float)((float)(this->groundTrace.c.normal.x * this->groundTrace.c.normal.x) + (float)(this->groundTrace.c.normal.y * this->groundTrace.c.normal.y))) * (float)0.5))
                                                                                        * (float)v13)
                                                                                - (float)1.5)
                                                                * (float)v13)
                                                        * (float)((float)((float)(this->groundTrace.c.normal.z
                                                                                * this->groundTrace.c.normal.z)
                                                                        + (float)((float)(this->groundTrace.c.normal.x
                                                                                        * this->groundTrace.c.normal.x)
                                                                                + (float)(this->groundTrace.c.normal.y
                                                                                        * this->groundTrace.c.normal.y)))
                                                                * (float)0.5))
                                                * (float)((float)-(float)((float)((float)((float)v13
                                                                                        * (float)((float)((float)(this->groundTrace.c.normal.z * this->groundTrace.c.normal.z) + (float)((float)(this->groundTrace.c.normal.x * this->groundTrace.c.normal.x) + (float)(this->groundTrace.c.normal.y * this->groundTrace.c.normal.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v13)
                                                                        - (float)1.5)
                                                        * (float)v13))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v13
                                                                * (float)((float)((float)(this->groundTrace.c.normal.z
                                                                                        * this->groundTrace.c.normal.z)
                                                                                + (float)((float)(this->groundTrace.c.normal.x
                                                                                                * this->groundTrace.c.normal.x)
                                                                                        + (float)(this->groundTrace.c.normal.y
                                                                                                * this->groundTrace.c.normal.y)))
                                                                        * (float)0.5))
                                                        * (float)v13)
                                                - (float)1.5)
                                * (float)v13))
                * (float)v11);
    v16 = (float)((float)-(float)((float)((float)v15
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)(this->groundTrace.c.normal.z * this->groundTrace.c.normal.z) + (float)((float)(this->groundTrace.c.normal.x * this->groundTrace.c.normal.x) + (float)(this->groundTrace.c.normal.y * this->groundTrace.c.normal.y))) * (float)0.5)) * (float)v13) - (float)1.5)
                                                                                        * (float)v13)
                                                                                * (float)((float)((float)(this->groundTrace.c.normal.z * this->groundTrace.c.normal.z)
                                                                                                + (float)((float)(this->groundTrace.c.normal.x * this->groundTrace.c.normal.x) + (float)(this->groundTrace.c.normal.y * this->groundTrace.c.normal.y)))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v13 * (float)((float)((float)(this->groundTrace.c.normal.z * this->groundTrace.c.normal.z) + (float)((float)(this->groundTrace.c.normal.x * this->groundTrace.c.normal.x) + (float)(this->groundTrace.c.normal.y * this->groundTrace.c.normal.y))) * (float)0.5)) * (float)v13)
                                                                                                - (float)1.5)
                                                                                * (float)v13))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v13
                                                                                        * (float)((float)((float)(this->groundTrace.c.normal.z * this->groundTrace.c.normal.z) + (float)((float)(this->groundTrace.c.normal.x * this->groundTrace.c.normal.x) + (float)(this->groundTrace.c.normal.y * this->groundTrace.c.normal.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v13)
                                                                        - (float)1.5)
                                                        * (float)v13)))
                                - (float)1.5)
                * (float)v14);
    this->groundTrace.c.normal.x = this->groundTrace.c.normal.x * (float)v16;
    this->groundTrace.c.normal.y = (float)v8 * (float)v16;
    this->groundTrace.c.normal.z = (float)v9 * (float)v16;
  }
  else
  {
    this->groundTrace.fraction = 1.0;
  }
  clip = this->clip;
  LODWORD(v18) = 0;
  p_contentsQuery = &this->contentsQuery;
  collisionQueryLastSubmittedIndex = clip->collisionQueryLastSubmittedIndex;
  if ( LODWORD(this->contentsQuery.index) <= (unsigned int)collisionQueryLastSubmittedIndex )
  {
    if ( (unsigned __int8)idClip::QueryIsValid(this: this->clip, clipQuery: &this->contentsQuery) != 0 )
    {
      index = p_contentsQuery->index;
      HIDWORD(v18) = &this->current.worldOrigin;
      p_contentsQuery->index = v18;
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v51,
        query: &clip->collisionQueries[index & 0xFFF].query,
        peek: false);
      contentFlags = v51.c.contentFlags;
      if ( (v51.c.contentFlags & 1) != 0 )
      {
        idPhysics_Player::CorrectAllSolid(this, trace: &this->groundTrace, contents: v51.c.contentFlags);
        contentFlags = v51.c.contentFlags;
      }
      this->lastContents = contentFlags;
    }
    p_contentsQuery->index = *(unsigned __int64 *)&idClip::Contents(
                                                     this: (idClip *)&v50,
                                                     result: this->clip,
                                                     a3: nullptr,
                                                     start: &this->current.worldOrigin,
                                                     clipModel: this->clipModels[0],
                                                     startAxis: &this->clipModels[0]->axis,
                                                     clipMask: this->clipMask,
                                                     passEntityNumber: this->entityNumber,
                                                     userName: v31,
                                                     a10: v32,
                                                     a11: v33,
                                                     a12: v34,
                                                     a13: v35,
                                                     a14: v36,
                                                     a15: v37,
                                                     a16: v38,
                                                     a17: v39,
                                                     a18: v40,
                                                     a19: v41,
                                                     a20: v42,
                                                     a21: v43,
                                                     a22: v44,
                                                     a23: v45,
                                                     a24: v46,
                                                     a25: v47,
                                                     a26: v48,
                                                     a27: v49,
                                                     a28: (int)"w:\\tech5\\engine\\gamelib\\physics\\Physics_Player.cpp(1492) : Contents")->world;
  }
  if ( this->groundTrace.fraction == 1.0
    || (p_velocity = &this->current.velocity,
        this->groundSurfaceFlags = this->groundTrace.c.surfaceFlags,
        (v24 = (float)((float)((float)(this->current.velocity.y * this->gravityNormal.y)
                             + (float)(this->current.velocity.z * this->gravityNormal.z))
                     + (float)(this->current.velocity.x * this->gravityNormal.x))) < 0.0)
    && (float)((float)(this->groundTrace.c.normal.x * this->current.velocity.x)
             + (float)((float)(this->groundTrace.c.normal.y * this->current.velocity.y)
                     + (float)(this->groundTrace.c.normal.z * this->current.velocity.z))) > 10.0 )
  {
    this->groundPlane = false;
    this->walking = false;
  }
  else if ( (float)((float)(this->groundTrace.c.normal.x * (float)-this->gravityNormal.x)
                  + (float)((float)(this->groundTrace.c.normal.z * (float)-this->gravityNormal.z)
                          + (float)(this->groundTrace.c.normal.y * (float)-this->gravityNormal.y))) >= 0.69999999 )
  {
    movementFlags = this->current.movementFlags;
    this->groundPlane = true;
    this->walking = true;
    if ( (movementFlags & 0x80) != 0 )
    {
      this->current.movementTime = 0;
      this->current.movementFlags = movementFlags & 0xFFFFFF5F;
    }
    if ( !this->startedOnGround
      && (float)((float)(this->current.velocity.x * (float)-this->gravityNormal.x)
               + (float)((float)((float)-this->gravityNormal.y * this->current.velocity.y)
                       + (float)(this->current.velocity.z * (float)-this->gravityNormal.z))) < -200.0 )
    {
      v30 = this->current.movementFlags | 0x20;
      this->current.movementTime = 250;
      this->current.movementFlags = v30;
    }
    ((void (__fastcall *)(idPhysicsCallbacks *, int, trace_t *, idVec3 *, _DWORD))this->callbacks->Collide)(
      a1: this->callbacks,
      a2: this->physicsId,
      a3: &this->groundTrace,
      a4: p_velocity,
      a5: HIDWORD(collisionQueryLastSubmittedIndex));
  }
  else
  {
    if ( v24 > 150.0 )
    {
      v25 = this->current.velocity.y;
      v26 = this->current.velocity.z;
      v27 = (float)(this->gravityNormal.y
                  * (float)((float)((float)((float)(this->gravityNormal.y * this->current.velocity.y)
                                          + (float)(this->gravityNormal.z * this->current.velocity.z))
                                  + (float)(this->current.velocity.x * this->gravityNormal.x))
                          - (float)150.0));
      v28 = (float)(this->gravityNormal.z
                  * (float)((float)((float)((float)(this->gravityNormal.y * this->current.velocity.y)
                                          + (float)(this->gravityNormal.z * this->current.velocity.z))
                                  + (float)(this->current.velocity.x * this->gravityNormal.x))
                          - (float)150.0));
      p_velocity->x = p_velocity->x
                    - (float)(this->gravityNormal.x
                            * (float)((float)((float)((float)(this->gravityNormal.y * this->current.velocity.y)
                                                    + (float)(this->gravityNormal.z * this->current.velocity.z))
                                            + (float)(this->current.velocity.x * this->gravityNormal.x))
                                    - (float)150.0));
      this->current.velocity.y = (float)v25 - (float)v27;
      this->current.velocity.z = (float)v26 - (float)v28;
    }
    this->groundPlane = true;
    this->walking = false;
  }
}


// ========================================================================
// ?CanStand@idPhysics_Player@@QBA_NABVidVec3@@@Z
// EA  : 0x82757318
// RVA : 0x00757318
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

BOOL __fastcall idPhysics_Player::CanStand(idPhysics_Player *this, const idVec3 *pos)
{
  idClip *clip; // r4
  double y; // fp11
  double z; // fp10
  idClipModel *v6; // r8
  double v7; // fp8
  int clipMask; // r10
  double v9; // fp7
  const char *v11; // [sp+8h] [-118h]
  int v12; // [sp+Ch] [-114h]
  const char *v13; // [sp+10h] [-110h]
  int v14; // [sp+14h] [-10Ch]
  int v15; // [sp+18h] [-108h]
  int v16; // [sp+1Ch] [-104h]
  int v17; // [sp+20h] [-100h]
  int v18; // [sp+24h] [-FCh]
  int v19; // [sp+28h] [-F8h]
  int v20; // [sp+2Ch] [-F4h]
  int v21; // [sp+30h] [-F0h]
  int v22; // [sp+34h] [-ECh]
  int v23; // [sp+38h] [-E8h]
  int v24; // [sp+3Ch] [-E4h]
  int v25; // [sp+40h] [-E0h]
  int v26; // [sp+44h] [-DCh]
  int v27; // [sp+48h] [-D8h]
  int v28; // [sp+4Ch] [-D4h]
  int v29; // [sp+50h] [-D0h]
  int entityNumber; // [sp+54h] [-CCh]
  int v31; // [sp+58h] [-C8h]
  int v32; // [sp+60h] [-C0h]
  idVec3 v33; // [sp+70h] [-B0h] BYREF
  _BYTE v34[16]; // [sp+80h] [-A0h] BYREF
  trace_t v35; // [sp+90h] [-90h] BYREF

  clip = this->clip;
  if ( this->clipModels[0] == this->clipModel_crouched )
  {
    y = this->gravityNormal.y;
    z = this->gravityNormal.z;
    v6 = this->clipModels[0];
    v7 = pos->y;
    clipMask = this->clipMask;
    v9 = pos->z;
    entityNumber = this->entityNumber;
    v33.x = pos->x - (float)(this->gravityNormal.x * (float)(pm_normalheight.valueFloat - pm_crouchheight.valueFloat));
    v33.y = (float)v7 - (float)((float)y * (float)(pm_normalheight.valueFloat - pm_crouchheight.valueFloat));
    v33.z = (float)v9 - (float)((float)z * (float)(pm_normalheight.valueFloat - pm_crouchheight.valueFloat));
    idClip::Translation(
      this: (idClip *)v34,
      result: clip,
      a3: &v35,
      start: pos,
      end: &v33,
      clipModel: v6,
      startAxis: &v6->axis,
      clipMask,
      passEntityNumber: (int)v11,
      moveClipModel: v12,
      userName: v13,
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
      a28: entityNumber,
      a29: v31,
      a30: false,
      a31: v32,
      a32: 0);
  }
  else
  {
    idClip::Contents(
      this: (idClip *)v34,
      result: clip,
      a3: &v35,
      start: pos,
      clipModel: this->clipModels[0],
      startAxis: &this->clipModels[0]->axis,
      clipMask: this->clipMask,
      passEntityNumber: this->entityNumber,
      userName: v11,
      a10: v12,
      a11: (int)v13,
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
  }
  return v35.fraction >= 1.0;
}


// ========================================================================
// ?CheckLadder@idPhysics_Player@@AAAX_N@Z
// EA  : 0x82757420
// RVA : 0x00757420
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::CheckLadder(idPhysics_Player *this, bool oldLadder)
{
  unsigned __int64 v2; // r29
  BOOL walking; // r30
  idClip *clip; // r26
  idClipQuery *p_ladderQuery1; // r27
  idClipQuery *p_ladderQuery2; // r25
  unsigned __int64 index; // r11
  unsigned __int64 v10; // r29
  unsigned __int64 v11; // r11
  idClip *v12; // r9
  double x; // fp0
  double y; // fp13
  double z; // fp12
  idVec3 *p_gravityNormal; // r28
  double v17; // fp9
  double v18; // fp3
  double v19; // fp2
  double v20; // fp0
  int entityNumber; // r11
  double v22; // fp31
  double v23; // fp30
  double v24; // fp29
  idClipModel *v25; // r8
  double v26; // fp9
  double v27; // fp8
  int clipMask; // r10
  idClip *v29; // r4
  double v30; // fp11
  idClipModel *clipModel_crouched; // r8
  double v32; // fp10
  double v33; // fp8
  double v34; // fp7
  double v35; // fp6
  int v36; // r10
  idClip *v37; // r4
  double v38; // fp0
  double v39; // fp13
  double v40; // fp12
  int v41; // r9
  int v42; // [sp+8h] [-208h]
  int v43; // [sp+8h] [-208h]
  bool v44; // [sp+Fh] [-201h]
  bool v45; // [sp+Fh] [-201h]
  const char *v46; // [sp+10h] [-200h]
  const char *v47; // [sp+10h] [-200h]
  int v48; // [sp+14h] [-1FCh]
  int v49; // [sp+14h] [-1FCh]
  int v50; // [sp+18h] [-1F8h]
  int v51; // [sp+18h] [-1F8h]
  int v52; // [sp+1Ch] [-1F4h]
  int v53; // [sp+1Ch] [-1F4h]
  int v54; // [sp+20h] [-1F0h]
  int v55; // [sp+20h] [-1F0h]
  int v56; // [sp+24h] [-1ECh]
  int v57; // [sp+24h] [-1ECh]
  int v58; // [sp+28h] [-1E8h]
  int v59; // [sp+28h] [-1E8h]
  int v60; // [sp+2Ch] [-1E4h]
  int v61; // [sp+2Ch] [-1E4h]
  int v62; // [sp+30h] [-1E0h]
  int v63; // [sp+30h] [-1E0h]
  int v64; // [sp+34h] [-1DCh]
  int v65; // [sp+34h] [-1DCh]
  int v66; // [sp+38h] [-1D8h]
  int v67; // [sp+38h] [-1D8h]
  int v68; // [sp+3Ch] [-1D4h]
  int v69; // [sp+3Ch] [-1D4h]
  int v70; // [sp+40h] [-1D0h]
  int v71; // [sp+40h] [-1D0h]
  int v72; // [sp+44h] [-1CCh]
  int v73; // [sp+44h] [-1CCh]
  int v74; // [sp+48h] [-1C8h]
  int v75; // [sp+48h] [-1C8h]
  int v76; // [sp+4Ch] [-1C4h]
  int v77; // [sp+4Ch] [-1C4h]
  int v78; // [sp+50h] [-1C0h]
  int v79; // [sp+50h] [-1C0h]
  int v80; // [sp+54h] [-1BCh]
  int v81; // [sp+58h] [-1B8h]
  int v82; // [sp+58h] [-1B8h]
  int v83; // [sp+60h] [-1B0h]
  int v84; // [sp+60h] [-1B0h]
  idVec3 v85; // [sp+70h] [-1A0h] BYREF
  idVec3 v86; // [sp+80h] [-190h] BYREF
  idVec3 v87; // [sp+90h] [-180h] BYREF
  idVec3 v88; // [sp+A0h] [-170h] BYREF
  trace_t v89; // [sp+B0h] [-160h] BYREF
  trace_t v90; // [sp+130h] [-E0h] BYREF

  if ( this->canLadder && (this->current.movementTime == 0 || (this->current.movementFlags & 0x400) != 0) )
  {
    walking = this->walking;
    if ( !this->walking || this->command.forwardmove > 0 )
    {
      if ( g_pm_deferredSlideMove )
      {
        clip = this->clip;
        p_ladderQuery1 = &this->ladderQuery1;
        if ( (unsigned __int8)idClip::QueryIsValid(this: clip, clipQuery: &this->ladderQuery1) != 0 )
        {
          p_ladderQuery2 = &this->ladderQuery2;
          if ( (unsigned __int8)idClip::QueryIsValid(this: clip, clipQuery: &this->ladderQuery2) != 0 )
          {
            LODWORD(v2) = 0;
            index = p_ladderQuery1->index;
            p_ladderQuery1->index = v2;
            HIDWORD(v10) = &consoleFont[21088];
            idCollisionModelManager::GetContentsResult(
              this: collisionModelManager,
              result: &v89,
              query: &clip->collisionQueries[index & 0xFFF].query,
              peek: false);
            if ( v89.fraction < 1.0 && (v89.c.surfaceFlags & 0x80) != 0 )
            {
              v11 = p_ladderQuery2->index;
              v12 = this->clip;
              p_ladderQuery2->index = v10;
              idCollisionModelManager::GetContentsResult(
                this: collisionModelManager,
                result: &v89,
                query: &v12->collisionQueries[v11 & 0xFFF].query,
                peek: false);
              if ( v89.fraction < 1.0 && (v89.c.surfaceFlags & 0x80) != 0 )
              {
                x = v89.c.normal.x;
                y = v89.c.normal.y;
                z = v89.c.normal.z;
                this->ladder = true;
                this->ladderNormal.x = x;
                this->ladderNormal.y = y;
                this->ladderNormal.z = z;
              }
            }
          }
        }
      }
      else
      {
        p_gravityNormal = &this->gravityNormal;
        v17 = this->viewForward.z;
        v18 = (float)(this->gravityNormal.z
                    * (float)((float)(this->gravityNormal.z * this->viewForward.z)
                            + (float)((float)(this->gravityNormal.x * this->viewForward.x)
                                    + (float)(this->gravityNormal.y * this->viewForward.y))));
        v19 = (float)(this->viewForward.x
                    - (float)(this->gravityNormal.x
                            * (float)((float)(this->gravityNormal.z * this->viewForward.z)
                                    + (float)((float)(this->gravityNormal.x * this->viewForward.x)
                                            + (float)(this->gravityNormal.y * this->viewForward.y)))));
        v85.y = this->viewForward.y
              - (float)(this->gravityNormal.y
                      * (float)((float)(this->gravityNormal.z * this->viewForward.z)
                              + (float)((float)(this->gravityNormal.x * this->viewForward.x)
                                      + (float)(this->gravityNormal.y * this->viewForward.y))));
        v85.x = v19;
        v85.z = (float)v17 - (float)v18;
        idVec3::NormalizeFast(this: &v85);
        if ( walking )
          v20 = 1.0;
        else
          v20 = 48.0;
        entityNumber = this->entityNumber;
        v22 = (float)(v85.x * (float)v20);
        v23 = (float)(v85.y * (float)v20);
        v24 = (float)(v85.z * (float)v20);
        v25 = this->clipModels[0];
        v26 = this->current.worldOrigin.y;
        v27 = this->current.worldOrigin.z;
        clipMask = this->clipMask;
        v29 = this->clip;
        v88.x = this->current.worldOrigin.x + (float)(v85.x * (float)v20);
        v88.y = (float)v26 + (float)(v85.y * (float)v20);
        v88.z = (float)v27 + (float)(v85.z * (float)v20);
        idClip::Translation(
          this: (idClip *)&v85,
          result: v29,
          a3: &v90,
          start: &this->current.worldOrigin,
          end: &v88,
          clipModel: v25,
          startAxis: &v25->axis,
          clipMask,
          passEntityNumber: v42,
          moveClipModel: v44,
          userName: v46,
          a12: v48,
          a13: v50,
          a14: v52,
          a15: v54,
          a16: v56,
          a17: v58,
          a18: v60,
          a19: v62,
          a20: v64,
          a21: v66,
          a22: v68,
          a23: v70,
          a24: v72,
          a25: v74,
          a26: v76,
          a27: v78,
          a28: entityNumber,
          a29: v81,
          a30: false,
          a31: v83,
          a32: 0);
        if ( v90.fraction < 1.0 && (v90.c.surfaceFlags & 0x80) != 0 )
        {
          v30 = this->gravityNormal.y;
          clipModel_crouched = this->clipModel_crouched;
          v32 = this->gravityNormal.z;
          v33 = (float)(this->maxStepHeight * (float)0.75);
          v34 = this->current.worldOrigin.y;
          v35 = this->current.worldOrigin.z;
          v36 = this->clipMask;
          v37 = this->clip;
          v80 = this->entityNumber;
          v86.x = this->current.worldOrigin.x - (float)(p_gravityNormal->x * (float)(this->maxStepHeight * (float)0.75));
          v86.y = (float)v34 - (float)((float)v30 * (float)v33);
          v86.z = (float)v35 - (float)((float)v32 * (float)v33);
          v87.x = v86.x + (float)v22;
          v87.y = v86.y + (float)v23;
          v87.z = v86.z + (float)v24;
          idClip::Translation(
            this: (idClip *)&v85,
            result: v37,
            a3: &v90,
            start: &v86,
            end: &v87,
            clipModel: clipModel_crouched,
            startAxis: &clipModel_crouched->axis,
            clipMask: v36,
            passEntityNumber: v43,
            moveClipModel: v45,
            userName: v47,
            a12: v49,
            a13: v51,
            a14: v53,
            a15: v55,
            a16: v57,
            a17: v59,
            a18: v61,
            a19: v63,
            a20: v65,
            a21: v67,
            a22: v69,
            a23: v71,
            a24: v73,
            a25: v75,
            a26: v77,
            a27: v79,
            a28: v80,
            a29: v82,
            a30: false,
            a31: v84,
            a32: 0);
          if ( v90.fraction < 1.0 && (v90.c.surfaceFlags & 0x80) != 0 )
          {
            v38 = v90.c.normal.x;
            v39 = v90.c.normal.y;
            v40 = v90.c.normal.z;
            this->ladder = true;
            this->ladderNormal.x = v38;
            this->ladderNormal.y = v39;
            this->ladderNormal.z = v40;
          }
        }
        if ( !this->ladder && oldLadder )
        {
          v41 = this->current.movementFlags | 0x400;
          this->current.movementTime = 200;
          this->current.movementFlags = v41;
        }
      }
    }
  }
}


// ========================================================================
// ?Serialize@idPhysics_Player@@UAAXAAVidSerializer@@AAUplayerPState_t@@@Z
// EA  : 0x827577C8
// RVA : 0x007577C8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::Serialize(idPhysics_Player *this, idSerializer *ser, playerPState_t *catchupStart)
{
  idBitMsg *msg; // r3
  idBitMsg *v6; // r3
  pmtype_t movementType; // r30
  unsigned int v8; // r10
  BOOL writing; // r11
  idBitMsg *v10; // r3
  idBitMsg *v11; // r3
  idBitMsg *v12; // r3
  idBitMsg *v13; // r3
  idBitMsg *v14; // r3
  playerPState_t current; // [sp+60h] [-70h] BYREF

  current = this->current;
  idSerializer::Serialize(this: ser, value: &current.localOrigin);
  idSerializer::Serialize(this: ser, value: &current.worldOrigin);
  idSerializer::Serialize(this: ser, value: &current.velocity);
  idSerializer::Serialize(this: ser, value: &current.pushVelocity);
  msg = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: SLODWORD(current.stepUp), numBits: 32);
  else
    LODWORD(current.stepUp) = idBitMsg::ReadBits(this: msg, numBits: 32);
  v6 = ser->msg;
  movementType = current.movementType;
  v8 = _cntlzw(5u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: v6, value: current.movementType, numBits: 32 - v8);
  else
    movementType = idBitMsg::ReadBits(this: v6, numBits: 32 - v8);
  writing = ser->writing;
  v10 = ser->msg;
  current.movementType = movementType;
  if ( writing )
    idBitMsg::WriteBits(this: v10, value: current.movementFlags, numBits: 32);
  else
    current.movementFlags = idBitMsg::ReadBits(this: v10, numBits: 32);
  v11 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v11, value: current.movementTime, numBits: 32);
  else
    current.movementTime = idBitMsg::ReadBits(this: v11, numBits: 32);
  v12 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v12, value: SLODWORD(current.deltaViewAngles.pitch), numBits: 32);
  else
    LODWORD(current.deltaViewAngles.pitch) = idBitMsg::ReadBits(this: v12, numBits: 32);
  v13 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v13, value: SLODWORD(current.deltaViewAngles.yaw), numBits: 32);
  else
    LODWORD(current.deltaViewAngles.yaw) = idBitMsg::ReadBits(this: v13, numBits: 32);
  v14 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v14, value: SLODWORD(current.deltaViewAngles.roll), numBits: 32);
  else
    LODWORD(current.deltaViewAngles.roll) = idBitMsg::ReadBits(this: v14, numBits: 32);
  if ( common->SnapshotState(this: common) == SNAP_READING )
    playerPState_t::operator=(this: catchupStart, __that: &current);
}


// ========================================================================
// ?SerializeNonPredictiveState@idPhysics_Player@@UAAXAAVidSerializer@@@Z
// EA  : 0x827579B8
// RVA : 0x007579B8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SerializeNonPredictiveState(idPhysics_Player *this, idSerializer *ser)
{
  pmtype_t movementType; // r30
  idBitMsg *msg; // r3
  unsigned int v6; // r10
  idBitMsg *v7; // r3

  movementType = this->current.movementType;
  msg = ser->msg;
  v6 = _cntlzw(5u);
  if ( ser->writing )
    idBitMsg::WriteBits(this: msg, value: movementType, numBits: 32 - v6);
  else
    movementType = idBitMsg::ReadBits(this: msg, numBits: 32 - v6);
  this->current.movementType = movementType;
  v7 = ser->msg;
  if ( ser->writing )
    idBitMsg::WriteBits(this: v7, value: this->current.movementFlags, numBits: 32);
  else
    this->current.movementFlags = idBitMsg::ReadBits(this: v7, numBits: 32);
}


// ========================================================================
// ??0idPhysics_Player@@QAA@XZ
// EA  : 0x82757A40
// RVA : 0x00757A40
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

idPhysics_Player *__fastcall idPhysics_Player::idPhysics_Player(idPhysics_Player *this)
{
  unsigned __int64 v2; // r30
  double z; // fp0
  double v4; // fp0
  char v5; // r5
  __int64 v6; // r9
  float *p_z; // r11
  int v8; // ctr

  idPhysics_Actor::idPhysics_Actor(this);
  HIDWORD(v2) = &vec3_origin;
  LODWORD(v2) = 0;
  this->__vftable = (idPhysics_Player_vtbl *)&idPhysics_Player::`vftable';
  HIDWORD(v6) = 0x82000000;
  this->explicitMove.delta.x = vec3_origin.x;
  this->explicitMove.delta.y = vec3_origin.y;
  z = vec3_origin.z;
  this->explicitMove.clipMove = true;
  this->explicitMove.delta.z = z;
  this->explicitMove.velocityType = VEL_EXPLICIT;
  this->explicitMove.overrideVelocity = vec3_origin;
  this->explicitMove.ignoreEntityNum = 0x1FFF;
  this->explicitMove2.delta.x = vec3_origin.x;
  this->explicitMove2.delta.y = vec3_origin.y;
  v4 = vec3_origin.z;
  this->explicitMove2.clipMove = true;
  this->explicitMove2.delta.z = v4;
  this->explicitMove2.velocityType = VEL_EXPLICIT;
  this->explicitMove2.overrideVelocity = vec3_origin;
  this->explicitMove2.ignoreEntityNum = 0x1FFF;
  this->slideMoveQuery.index = v2;
  this->ladderQuery1.index = v2;
  this->ladderQuery2.index = v2;
  this->contentsQuery.index = v2;
  this->command.pos[2] = 0.0;
  this->command.pos[1] = 0.0;
  this->command.buttons = 0;
  this->command.pos[0] = 0.0;
  this->command.buttons2 = 0;
  this->command.forwardmove = 0;
  this->command.rightmove = 0;
  this->command.upmove = 0;
  this->command.angles[2] = 0;
  this->command.angles[1] = 0;
  this->command.angles[0] = 0;
  this->command.clientGameFrame = 0;
  this->command.yaw = 0;
  this->command.pitch = 0;
  this->command.roll = 0;
  this->command.predictionStateBits = 0;
  this->command.vehicleThrottle = 0;
  this->command.serverGameTime = 0;
  this->command.fireCount = 0;
  this->command.fireAngles[1] = 0;
  this->command.fireAngles[0] = 0;
  this->command.firePos[2] = 0;
  *((_BYTE *)&this->command + 9) &= 0x3Fu;
  this->command.firePos[1] = 0;
  this->command.firePos[0] = 0;
  this->command.speed = 0;
  this->prevcmd.pos[2] = 0.0;
  v5 = *((_BYTE *)&this->prevcmd + 9);
  this->prevcmd.pos[1] = 0.0;
  this->prevcmd.pos[0] = 0.0;
  this->prevcmd.buttons = 0;
  this->prevcmd.buttons2 = 0;
  this->prevcmd.forwardmove = 0;
  this->prevcmd.rightmove = 0;
  LODWORD(v6) = 0;
  this->prevcmd.upmove = 0;
  p_z = &this->explicitMove2.overrideVelocity.z;
  this->prevcmd.angles[2] = 0;
  v8 = 9;
  this->prevcmd.angles[1] = 0;
  this->prevcmd.angles[0] = 0;
  this->prevcmd.clientGameFrame = 0;
  this->prevcmd.yaw = 0;
  this->prevcmd.pitch = 0;
  this->prevcmd.roll = 0;
  this->prevcmd.predictionStateBits = 0;
  this->prevcmd.vehicleThrottle = 0;
  this->prevcmd.serverGameTime = 0;
  this->prevcmd.fireCount = 0;
  this->prevcmd.fireAngles[1] = 0;
  this->prevcmd.fireAngles[0] = 0;
  this->prevcmd.firePos[2] = 0;
  *((_BYTE *)&this->prevcmd + 9) = v5 & 0x3F;
  this->prevcmd.firePos[1] = 0;
  this->prevcmd.firePos[0] = 0;
  this->prevcmd.speed = 0;
  this->type = PHYSICS_PLAYER;
  do
  {
    p_z += 2;
    *(_QWORD *)p_z = v6;
    --v8;
  }
  while ( v8 != 0 );
  p_z[2] = 0.0;
  memset(Dst: &this->previous, Val: 0, Size: sizeof(this->previous));
  this->saved.localOrigin.x = this->current.localOrigin.x;
  this->saved.localOrigin.y = this->current.localOrigin.y;
  this->saved.localOrigin.z = this->current.localOrigin.z;
  this->saved.worldOrigin.x = this->current.worldOrigin.x;
  this->saved.worldOrigin.y = this->current.worldOrigin.y;
  this->saved.worldOrigin.z = this->current.worldOrigin.z;
  this->saved.velocity.x = this->current.velocity.x;
  this->saved.velocity.y = this->current.velocity.y;
  this->saved.velocity.z = this->current.velocity.z;
  this->saved.pushVelocity.x = this->current.pushVelocity.x;
  this->saved.pushVelocity.y = this->current.pushVelocity.y;
  this->saved.pushVelocity.z = this->current.pushVelocity.z;
  this->saved.deltaViewAngles.pitch = this->current.deltaViewAngles.pitch;
  this->saved.deltaViewAngles.yaw = this->current.deltaViewAngles.yaw;
  this->saved.deltaViewAngles.roll = this->current.deltaViewAngles.roll;
  this->saved.stepUp = this->current.stepUp;
  this->saved.movementType = this->current.movementType;
  this->saved.movementFlags = this->current.movementFlags;
  this->saved.movementTime = this->current.movementTime;
  this->walkSpeed = 0.0;
  this->crouchSpeed = 0.0;
  this->clipModel_dead = nullptr;
  this->maxStepHeight = 0.0;
  this->clipModel_standing = nullptr;
  this->maxJumpHeight = 0.0;
  this->clipModel_crouched = nullptr;
  this->clipModel_sprintSlide = nullptr;
  this->overrideClipMaterial = nullptr;
  this->pusher = nullptr;
  this->debugLevel = 0;
  this->forcedClientCrouchState = false;
  this->clientPusherLocked = false;
  this->clientOriginSet = false;
  this->nextClientOrigin.z = 0.0;
  this->nextClientOrigin.y = 0.0;
  this->nextClientOrigin.x = 0.0;
  this->walkFriction = 6.0;
  this->flyFriction = 3.0;
  this->waterFriction = 3.0;
  this->airFriction = 0.0;
  this->slideFriction = 1.5;
  this->walkAccelerate = 10.0;
  this->waterAccelerate = 4.0;
  this->airAccelerate = 1.0;
  this->flyAccelerate = 8.0;
  memset(Dst: &this->command, Val: 0, Size: sizeof(this->command));
  this->viewAngles.roll = 0.0;
  this->viewAngles.yaw = 0.0;
  this->viewAngles.pitch = 0.0;
  this->framemsec = 0;
  this->frametime = 0.0;
  this->playerSpeed = 0.0;
  this->viewForward.z = 0.0;
  this->viewForward.y = 0.0;
  this->viewForward.x = 0.0;
  this->viewRight.z = 0.0;
  this->viewRight.y = 0.0;
  this->viewRight.x = 0.0;
  this->walking = false;
  this->startedOnGround = false;
  this->groundPlane = false;
  memset(Dst: &this->groundTrace, Val: 0, Size: sizeof(this->groundTrace));
  this->groundSurfaceFlags = 0;
  this->ladder = false;
  this->ladderNormal.z = 0.0;
  this->ladderNormal.y = 0.0;
  this->ladderNormal.x = 0.0;
  this->canLadder = false;
  this->blockedAccelerationVec.z = 0.0;
  this->blockedAccelerationVec.y = 0.0;
  this->blockedAccelerationVec.x = 0.0;
  this->blockedAccelerationPercent = 0.0;
  this->modifiedMovementMaxPercent = 0.0;
  this->modifiedMovementAngle = 90.0;
  this->modifiedAccelerationVec = vec3_origin;
  this->ownerJumpHandler = nullptr;
  this->pushDeltaZ = 0.0;
  this->ownerCrouchHandler = nullptr;
  this->ownerCrouchJumpHandler = nullptr;
  this->inhibitSprint = false;
  this->inhibitJump = false;
  this->lastContents = 0;
  this->toggleCrouch = false;
  this->canCrouchSprint = false;
  this->lastJumpChance = 0;
  this->perfectOriginPosition = vec3_origin;
  this->perfectOriginDuration = 0;
  this->perfectOriginTime = 0;
  this->currentSwimDepthState = SWIMDEPTH_STATE_NONE;
  this->swimStrokeVelocity = vec3_origin;
  this->swimStrokeTime = -1000;
  this->currentWaterSurfaceHeight = 0.0;
  this->swimStrokeAltCurve = false;
  this->swimStrokeIgnoreInput = false;
  this->swimStrokeTimeLeft = -1000;
  this->currentWaterEnt = -1;
  this->externalVelocity = vec3_origin;
  return this;
}


// ========================================================================
// ?SlideMove@idPhysics_Player@@AAAX_N000H@Z
// EA  : 0x82757EC0
// RVA : 0x00757EC0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SlideMove(
        idPhysics_Player *this,
        bool gravity,
        bool stepUp,
        bool stepDown,
        bool push,
        int ignoreEntityNum)
{
  if ( ignoreEntityNum == 0x1FFF )
    ignoreEntityNum = this->entityNumber;
  if ( g_pm_deferredSlideMove )
  {
    idPhysics_Player::SlideMoveDeferred(this, gravity, stepUp, stepDown, ignoreEntityNum);
  }
  else
  {
    idPhysics_Player::SlideMoveNonDeferred(this, gravity, stepUp, stepDown, push, ignoreEntityNum);
    idPhysics_Player::CheckGround(this);
  }
}


// ========================================================================
// ?WaterJumpMove@idPhysics_Player@@AAAXXZ
// EA  : 0x82757F30
// RVA : 0x00757F30
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::WaterJumpMove(idPhysics_Player *this)
{
  double v2; // fp9
  double v3; // fp8
  double y; // fp6
  double z; // fp5
  double v6; // fp4
  int movementFlags; // r11

  if ( g_pm_deferredSlideMove )
  {
    idPhysics_Player::SlideMoveDeferred(
      this,
      gravity: true,
      stepUp: true,
      stepDown: false,
      ignoreEntityNum: this->entityNumber);
  }
  else
  {
    idPhysics_Player::SlideMoveNonDeferred(
      this,
      gravity: true,
      stepUp: true,
      stepDown: false,
      push: false,
      ignoreEntityNum: this->entityNumber);
    idPhysics_Player::CheckGround(this);
  }
  v2 = (float)(this->gravityNormal.y * this->frametime);
  v3 = (float)(this->gravityNormal.z * this->frametime);
  y = this->current.velocity.y;
  z = this->current.velocity.z;
  v6 = (float)(this->current.velocity.x + (float)(this->gravityNormal.x * this->frametime));
  this->current.velocity.x = this->current.velocity.x + (float)(this->gravityNormal.x * this->frametime);
  this->current.velocity.y = (float)y + (float)v2;
  this->current.velocity.z = (float)z + (float)v3;
  if ( (float)((float)(this->gravityNormal.x * (float)v6)
             + (float)((float)(this->gravityNormal.z * (float)((float)z + (float)v3))
                     + (float)(this->gravityNormal.y * (float)((float)y + (float)v2)))) > 0.0 )
  {
    movementFlags = this->current.movementFlags;
    this->current.movementTime = 0;
    this->current.movementFlags = movementFlags & 0xFFFFF31F;
  }
}


// ========================================================================
// ?SwimMove@idPhysics_Player@@AAAXXZ
// EA  : 0x82758028
// RVA : 0x00758028
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SwimMove(idPhysics_Player *this)
{
  __int64 v2; // r6
  double v3; // fp31
  __int64 v4; // r9
  swimdepthstate_t currentSwimDepthState; // r7
  double y; // fp12
  double z; // fp13
  double x; // fp11
  double v9; // fp0
  int swimStrokeTimeLeft; // r11
  __int64 v13; // r6
  long double v14; // fp2
  double v15; // fp29
  double v16; // fp28
  double v17; // fp30
  char upmove; // r10
  int v19; // r30
  double v20; // fp10
  double v21; // fp6
  double v22; // fp4
  __int64 v23; // r11
  int v24; // r11
  double v25; // fp10
  BOOL swimStrokeAltCurve; // r7
  double v27; // fp31
  char v28; // r30
  double v29; // fp27
  double v30; // fp25
  double v31; // fp26
  long double v32; // fp2
  float *v33; // r3
  double v34; // fp0
  idVec3 *p_swimStrokeVelocity; // r11
  double v36; // fp11
  double v37; // fp8
  double v38; // fp6
  float v39; // r9
  float v40; // r8
  swimdepthstate_t v41; // r9
  double v44; // fp5
  double v45; // fp8
  double v46; // fp13
  double v47; // fp12
  idVec3 v50[2]; // [sp+58h] [-B8h] BYREF
  idAngles v51[10]; // [sp+70h] [-A0h] BYREF

  idPhysics_Player::Friction(this);
  if ( this->swimStrokeIgnoreInput )
    v3 = 1.0;
  else
    v3 = idPhysics_Player::CmdScale(this, cmd: v2);
  LODWORD(v4) = LODWORD(this->viewForward.y);
  *(float *)&v4 = this->viewForward.z;
  currentSwimDepthState = this->currentSwimDepthState;
  v50[0].x = this->viewForward.x;
  LODWORD(v50[0].y) = v4;
  y = *((float *)&v4 + 1);
  v50[0].z = *(float *)&v4;
  z = *(float *)&v4;
  x = v50[0].x;
  if ( currentSwimDepthState == SWIMDEPTH_STATE_ON_SURFACE )
  {
    v9 = 1.0;
    LODWORD(v4) = this->command.forwardmove;
    if ( (float)v4 < 0.0
      || (float)((float)(this->current.velocity.x * v50[0].x)
               + (float)((float)(this->current.velocity.y * (float)y) + (float)(this->current.velocity.z * *(float *)&v4))) < 0.0 )
    {
      v9 = -1.0;
    }
    if ( (float)((float)((float)(v50[0].x * (float)v9) * vec3_up.x)
               + (float)((float)((float)((float)y * (float)v9) * vec3_up.y)
                       + (float)((float)(*(float *)&v4 * (float)v9) * vec3_up.z))) > (double)SWIMMING_BREAKSURFACEDOT )
    {
      v50[0].z = 0.0;
      idVec3::NormalizeFast(this: v50);
      z = v50[0].z;
      y = v50[0].y;
      x = v50[0].x;
      this->swimStrokeVelocity.z = 0.0;
    }
    if ( !this->groundPlane )
    {
      _FP10 = -this->current.velocity.z;
      __asm { fsel      f9, f10, f0, f23 }
      this->current.velocity.z = _FP9;
    }
  }
  swimStrokeTimeLeft = this->swimStrokeTimeLeft;
  if ( swimStrokeTimeLeft > 0 )
    this->swimStrokeTimeLeft = swimStrokeTimeLeft - this->framemsec;
  if ( v3 != 0.0 )
  {
    LODWORD(v4) = this->command.forwardmove;
    LODWORD(v2) = this->command.rightmove;
    *((double *)&v14 + 1) = (float)(this->viewRight.x * (float)v2);
    v15 = (float)((float)((float)((float)y * (float)v4) + (float)(this->viewRight.y * (float)v2)) * (float)v3);
    v16 = (float)((float)((float)((float)z * (float)v4) + (float)(this->viewRight.z * (float)v2)) * (float)v3);
    v17 = (float)((float)((float)((float)v4 * (float)x) + (float)(this->viewRight.x * (float)v2)) * (float)v3);
    HIDWORD(v13) = (int)v4 >> 31;
    if ( abs8(this->command.forwardmove) < 0xAu )
    {
      upmove = this->command.upmove;
      v19 = upmove;
      if ( abs8(upmove) > 0xAu )
      {
        v20 = this->viewRight.y;
        v21 = (float)((float)y * this->viewRight.z);
        v22 = (float)((float)((float)y * this->viewRight.x) - (float)(this->viewRight.y * (float)x));
        v50[0].y = (float)(this->viewRight.z * (float)x) - (float)((float)z * this->viewRight.x);
        v50[0].z = v22;
        v50[0].x = (float)((float)z * (float)v20) - (float)v21;
        idVec3::NormalizeFast(this: v50);
        LODWORD(v23) = v19;
        *((_QWORD *)&v14 + 1) = v23;
        v17 = (float)((float)((float)(v50[0].x * (float)v3) * (float)v23) + (float)v17);
        v15 = (float)((float)((float)(v50[0].y * (float)v3) * (float)v23) + (float)v15);
        v16 = (float)((float)((float)(v50[0].z * (float)v3) * (float)v23) + (float)v16);
      }
    }
    v24 = this->swimStrokeTimeLeft;
    v25 = 0.0;
    if ( v24 > 0 )
    {
      swimStrokeAltCurve = this->swimStrokeAltCurve;
      LODWORD(v13) = this->swimStrokeTime;
      v27 = 0.0;
      *(_QWORD *)&v50[0].x = v13;
      v28 = 0;
      v29 = (float)v13;
      v30 = (float)((float)v13 * (float)0.33333334);
      v31 = (float)((float)v13 - (float)__SPAIR64__(&unk_821C0000, v24));
      if ( swimStrokeAltCurve )
      {
        if ( v31 >= (float)((float)v13 * (float)0.25) )
        {
          v29 = (float)((float)v13 - (float)((float)v13 * (float)0.25));
          v31 = (float)((float)((float)v13 - (float)((float)v13 * (float)0.25)) - (float)__SPAIR64__(&unk_821C0000, v24));
        }
        else
        {
          v28 = 1;
          *(double *)&v14 = (float)((float)((float)((float)v13 - (float)__SPAIR64__(&unk_821C0000, v24))
                                          / (float)((float)v13 * (float)0.25))
                                  * 3.1415927);
          v14 = sin(x: v14);
          v27 = (float)((float)*(double *)&v14 * (float)0.34999999);
        }
      }
      if ( v28 == 0 )
      {
        if ( v31 >= v30 )
          *(double *)&v14 = (float)((float)((float)((float)((float)v31 - (float)v30) / (float)((float)v29 - (float)v30))
                                          * 3.1415927)
                                  + idMath::HALF_PI);
        else
          *(double *)&v14 = (float)((float)((float)((float)v31 / (float)v30) * 3.1415927) - idMath::HALF_PI);
        v32 = sin(x: v14);
        v27 = (float)((float)((float)*(double *)&v32 + (float)1.0) * (float)0.5);
      }
      if ( this->swimStrokeIgnoreInput )
      {
        v33 = (float *)idAngles::ToMat3(this: v51, result: (idMat3 *)&this->viewAngles);
        v34 = this->swimStrokeVelocity.z;
        p_swimStrokeVelocity = v50;
        v36 = v33[8];
        v37 = (float)((float)(v33[2] * this->swimStrokeVelocity.x) + (float)(v33[5] * this->swimStrokeVelocity.y));
        v38 = (float)((float)(v33[7] * this->swimStrokeVelocity.z)
                    + (float)((float)(v33[1] * this->swimStrokeVelocity.x) + (float)(v33[4] * this->swimStrokeVelocity.y)));
        v50[0].x = (float)(this->swimStrokeVelocity.x * *v33)
                 + (float)((float)(v33[3] * this->swimStrokeVelocity.y) + (float)(v33[6] * this->swimStrokeVelocity.z));
        v50[0].y = v38;
        v50[0].z = (float)((float)v36 * (float)v34) + (float)v37;
      }
      else
      {
        p_swimStrokeVelocity = &this->swimStrokeVelocity;
      }
      v39 = p_swimStrokeVelocity->x;
      v40 = p_swimStrokeVelocity->y;
      v50[0].z = p_swimStrokeVelocity->z;
      v50[0].x = v39;
      v50[0].y = v40;
      v15 = (float)((float)(v40 * (float)v27) + (float)v15);
      v17 = (float)((float)(v39 * (float)v27) + (float)v17);
      v16 = (float)((float)(v50[0].z * (float)v27) + (float)v16);
      v25 = (float)((float)__fsqrts((float)((float)(v39 * v39)
                                          + (float)((float)(v40 * v40) + (float)(v50[0].z * v50[0].z))))
                  * (float)v27);
      if ( v28 != 0 )
      {
        v17 = -v17;
        v15 = -v15;
        v16 = -v16;
      }
    }
    v41 = this->currentSwimDepthState;
    _FP8 = (float)((float)((float)((float)v17 * (float)v17)
                         + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f6, f8, f0, f12 }
    v44 = __frsqrte(_FP6);
    v45 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44
                                                                                        * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)))
                                                                                                * (float)0.5))
                                                                                * (float)v44)
                                                                        - (float)1.5)
                                                        * (float)v44)
                                                * (float)((float)((float)((float)v17 * (float)v17)
                                                                + (float)((float)((float)v16 * (float)v16)
                                                                        + (float)((float)v15 * (float)v15)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v44
                                                                                * (float)((float)((float)((float)v17 * (float)v17)
                                                                                                + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)))
                                                                                        * (float)0.5))
                                                                        * (float)v44)
                                                                - (float)1.5)
                                                * (float)v44))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v44
                                                        * (float)((float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)((float)v16 * (float)v16)
                                                                                + (float)((float)v15 * (float)v15)))
                                                                * (float)0.5))
                                                * (float)v44)
                                        - (float)1.5)
                        * (float)v44));
    v50[0].x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v44) - (float)1.5) * (float)v44)
                                                                                             * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                             * (float)v44))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                             * (float)v44)
                                                                                     - (float)1.5)
                                                                     * (float)v44))
                                                     * (float)((float)((float)((float)v17 * (float)v17)
                                                                     + (float)((float)((float)v16 * (float)v16)
                                                                             + (float)((float)v15 * (float)v15)))
                                                             * (float)0.5))
                                             * (float)v45)
                                     - (float)1.5)
                     * (float)v45)
             * (float)v17;
    v50[0].y = (float)v15
             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v44) - (float)1.5) * (float)v44)
                                                                                             * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                             * (float)v44))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                             * (float)v44)
                                                                                     - (float)1.5)
                                                                     * (float)v44))
                                                     * (float)((float)((float)((float)v17 * (float)v17)
                                                                     + (float)((float)((float)v16 * (float)v16)
                                                                             + (float)((float)v15 * (float)v15)))
                                                             * (float)0.5))
                                             * (float)v45)
                                     - (float)1.5)
                     * (float)v45);
    v50[0].z = (float)v16
             * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v44) - (float)1.5) * (float)v44)
                                                                                             * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                     * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                             * (float)v44))
                                                                             - (float)1.5)
                                                             * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                             * (float)v44)
                                                                                     - (float)1.5)
                                                                     * (float)v44))
                                                     * (float)((float)((float)((float)v17 * (float)v17)
                                                                     + (float)((float)((float)v16 * (float)v16)
                                                                             + (float)((float)v15 * (float)v15)))
                                                             * (float)0.5))
                                             * (float)v45)
                                     - (float)1.5)
                     * (float)v45);
    if ( v41 == SWIMDEPTH_STATE_ON_SURFACE )
      v47 = 0.60000002;
    else
      v47 = 1.0;
    v46 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                                * (float)v44)
                                                                                        * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v44 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v44) - (float)1.5)
                                                                                        * (float)v44))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v44
                                                                                                * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                        * (float)v44)
                                                                                - (float)1.5)
                                                                * (float)v44))
                                                * (float)((float)((float)((float)v17 * (float)v17)
                                                                + (float)((float)((float)v16 * (float)v16)
                                                                        + (float)((float)v15 * (float)v15)))
                                                        * (float)0.5))
                                        * (float)v45)
                                - (float)1.5)
                * (float)v45);
    _FP5 = (float)((float)((float)((float)(this->playerSpeed * (float)v47) * (float)0.60000002) + (float)v25)
                 - (float)((float)v46
                         * (float)((float)((float)v17 * (float)v17)
                                 + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)))));
    __asm { fsel      f1, f5, f8, f6# wishspeed }
    idPhysics_Player::Accelerate(this, wishdir: v50, wishspeed: _FP1, accel: this->waterAccelerate);
  }
  if ( this->groundPlane
    && (float)((float)(this->groundTrace.c.normal.x * this->current.velocity.x)
             + (float)((float)(this->current.velocity.z * this->groundTrace.c.normal.z)
                     + (float)(this->current.velocity.y * this->groundTrace.c.normal.y))) < 0.0 )
  {
    idVec3::ProjectOntoPlane(this: &this->current.velocity, normal: &this->groundTrace.c.normal, overBounce: 1.001);
  }
  if ( g_pm_deferredSlideMove )
  {
    idPhysics_Player::SlideMoveDeferred(
      this,
      gravity: false,
      stepUp: true,
      stepDown: false,
      ignoreEntityNum: this->entityNumber);
  }
  else
  {
    idPhysics_Player::SlideMoveNonDeferred(
      this,
      gravity: false,
      stepUp: true,
      stepDown: false,
      push: false,
      ignoreEntityNum: this->entityNumber);
    idPhysics_Player::CheckGround(this);
  }
}


// ========================================================================
// ?AirMove@idPhysics_Player@@AAAXXZ
// EA  : 0x827585F8
// RVA : 0x007585F8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::AirMove(idPhysics_Player *this)
{
  __int64 v2; // r6
  double v3; // fp1
  __int64 v4; // r11
  double z; // fp3
  double y; // fp4
  double v7; // fp8
  double v8; // fp9
  double v9; // fp2
  double v10; // fp6
  double v11; // fp4
  double v12; // fp5
  double v13; // fp9
  double v14; // fp8
  double v17; // fp12
  double v18; // fp12
  double v19; // fp6
  double x; // fp2
  double v21; // fp10
  double v24; // fp3
  double v25; // fp3
  double v26; // fp8
  double v27; // fp5
  double v28; // fp11
  double v29; // fp31
  double v30; // fp6
  __int64 v31; // r5
  double v32; // fp12
  double v33; // fp9
  double v34; // fp5
  double v35; // fp4
  double v36; // fp11
  double v37; // fp8
  double airAccelerate; // fp2
  double v41; // fp7
  double v42; // fp6
  double v43; // fp11
  double v44; // fp9
  double v45; // fp0
  bool v46; // r5
  idVec3 v47; // [sp+50h] [-40h] BYREF
  idVec3 v48; // [sp+60h] [-30h]

  idPhysics_Player::Friction(this);
  v3 = idPhysics_Player::CmdScale(this, cmd: v2);
  HIDWORD(v4) = &si_vector_decode_cat_0[184];
  z = this->viewForward.z;
  y = this->viewForward.y;
  v7 = (float)(this->gravityNormal.z
             * (float)((float)(this->viewForward.x * this->gravityNormal.x)
                     + (float)((float)(this->viewForward.y * this->gravityNormal.y)
                             + (float)(this->viewForward.z * this->gravityNormal.z))));
  v8 = (float)(this->gravityNormal.y
             * (float)((float)(this->viewForward.x * this->gravityNormal.x)
                     + (float)((float)(this->viewForward.y * this->gravityNormal.y)
                             + (float)(this->viewForward.z * this->gravityNormal.z))));
  this->viewForward.x = this->viewForward.x
                      - (float)(this->gravityNormal.x
                              * (float)((float)(this->viewForward.x * this->gravityNormal.x)
                                      + (float)((float)(this->viewForward.y * this->gravityNormal.y)
                                              + (float)(this->viewForward.z * this->gravityNormal.z))));
  this->viewForward.z = (float)z - (float)v7;
  this->viewForward.y = (float)y - (float)v8;
  v9 = this->viewRight.z;
  v10 = this->viewRight.y;
  v11 = (float)((float)((float)(this->viewRight.z * this->gravityNormal.z)
                      + (float)((float)(this->viewRight.x * this->gravityNormal.x)
                              + (float)(this->viewRight.y * this->gravityNormal.y)))
              * this->gravityNormal.z);
  v12 = (float)((float)((float)(this->viewRight.z * this->gravityNormal.z)
                      + (float)((float)(this->viewRight.x * this->gravityNormal.x)
                              + (float)(this->viewRight.y * this->gravityNormal.y)))
              * this->gravityNormal.y);
  this->viewRight.x = this->viewRight.x
                    - (float)(this->gravityNormal.x
                            * (float)((float)(this->viewRight.z * this->gravityNormal.z)
                                    + (float)((float)(this->viewRight.x * this->gravityNormal.x)
                                            + (float)(this->viewRight.y * this->gravityNormal.y))));
  this->viewRight.z = (float)v9 - (float)v11;
  this->viewRight.y = (float)v10 - (float)v12;
  v13 = this->viewForward.z;
  v14 = this->viewForward.y;
  _FP4 = (float)((float)((float)(this->viewForward.z * this->viewForward.z)
                       + (float)((float)(this->viewForward.x * this->viewForward.x)
                               + (float)(this->viewForward.y * this->viewForward.y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f2, f4, f5, f12 }
  v17 = __frsqrte(_FP2);
  v18 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v17
                                                                                      * (float)((float)((float)(this->viewForward.z * this->viewForward.z) + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v17)
                                                                      - (float)1.5)
                                                      * (float)v17)
                                              * (float)((float)((float)(this->viewForward.z * this->viewForward.z)
                                                              + (float)((float)(this->viewForward.x * this->viewForward.x)
                                                                      + (float)(this->viewForward.y * this->viewForward.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v17
                                                                              * (float)((float)((float)(this->viewForward.z * this->viewForward.z)
                                                                                              + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v17)
                                                              - (float)1.5)
                                              * (float)v17))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v17
                                                      * (float)((float)((float)(this->viewForward.z * this->viewForward.z)
                                                                      + (float)((float)(this->viewForward.x
                                                                                      * this->viewForward.x)
                                                                              + (float)(this->viewForward.y
                                                                                      * this->viewForward.y)))
                                                              * (float)0.5))
                                              * (float)v17)
                                      - (float)1.5)
                      * (float)v17));
  v19 = (float)((float)-(float)((float)((float)((float)v18
                                              * (float)((float)((float)(this->viewForward.z * this->viewForward.z)
                                                              + (float)((float)(this->viewForward.x * this->viewForward.x)
                                                                      + (float)(this->viewForward.y * this->viewForward.y)))
                                                      * (float)0.5))
                                      * (float)v18)
                              - (float)1.5)
              * (float)v18);
  this->viewForward.x = this->viewForward.x
                      * (float)((float)-(float)((float)((float)((float)v18
                                                              * (float)((float)((float)(this->viewForward.z
                                                                                      * this->viewForward.z)
                                                                              + (float)((float)(this->viewForward.x
                                                                                              * this->viewForward.x)
                                                                                      + (float)(this->viewForward.y
                                                                                              * this->viewForward.y)))
                                                                      * (float)0.5))
                                                      * (float)v18)
                                              - (float)1.5)
                              * (float)v18);
  this->viewForward.z = (float)v19 * (float)v13;
  this->viewForward.y = (float)v14 * (float)v19;
  x = this->viewRight.x;
  v21 = this->viewRight.y;
  _FP6 = (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                       + (float)((float)(this->viewRight.x * this->viewRight.x)
                               + (float)(this->viewRight.y * this->viewRight.y)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f4, f6, f7, f12 }
  v24 = __frsqrte(_FP4);
  v25 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v24
                                                                                      * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v24)
                                                                      - (float)1.5)
                                                      * (float)v24)
                                              * (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                                                              + (float)((float)(this->viewRight.x * this->viewRight.x)
                                                                      + (float)(this->viewRight.y * this->viewRight.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v24
                                                                              * (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                                                                                              + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v24)
                                                              - (float)1.5)
                                              * (float)v24))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v24
                                                      * (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                                                                      + (float)((float)(this->viewRight.x
                                                                                      * this->viewRight.x)
                                                                              + (float)(this->viewRight.y
                                                                                      * this->viewRight.y)))
                                                              * (float)0.5))
                                              * (float)v24)
                                      - (float)1.5)
                      * (float)v24));
  v26 = (float)((float)-(float)((float)((float)((float)v25
                                              * (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                                                              + (float)((float)(this->viewRight.x * this->viewRight.x)
                                                                      + (float)(this->viewRight.y * this->viewRight.y)))
                                                      * (float)0.5))
                                      * (float)v25)
                              - (float)1.5)
              * (float)v25);
  v27 = (float)(this->viewRight.z
              * (float)((float)-(float)((float)((float)((float)v25
                                                      * (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                                                                      + (float)((float)(this->viewRight.x
                                                                                      * this->viewRight.x)
                                                                              + (float)(this->viewRight.y
                                                                                      * this->viewRight.y)))
                                                              * (float)0.5))
                                              * (float)v25)
                                      - (float)1.5)
                      * (float)v25));
  this->viewRight.z = this->viewRight.z
                    * (float)((float)-(float)((float)((float)((float)v25
                                                            * (float)((float)((float)(this->viewRight.z
                                                                                    * this->viewRight.z)
                                                                            + (float)((float)(this->viewRight.x
                                                                                            * this->viewRight.x)
                                                                                    + (float)(this->viewRight.y
                                                                                            * this->viewRight.y)))
                                                                    * (float)0.5))
                                                    * (float)v25)
                                            - (float)1.5)
                            * (float)v25);
  this->viewRight.y = (float)v21 * (float)v26;
  this->viewRight.x = (float)x * (float)v26;
  v28 = this->viewForward.z;
  v29 = this->gravityNormal.x;
  v30 = this->viewForward.x;
  HIDWORD(v31) = (unsigned __int8)this->command.forwardmove;
  LODWORD(v4) = SBYTE3(v31);
  LODWORD(v31) = this->command.rightmove;
  v32 = (float)((float)v27 * (float)v31);
  v33 = (float)((float)((float)x * (float)v26) * (float)v31);
  v35 = (float)((float)(this->viewForward.z * (float)v4) + (float)((float)v27 * (float)v31));
  v34 = (float)((float)(this->viewForward.y * (float)v4) + (float)((float)((float)v21 * (float)v26) * (float)v31));
  *(_QWORD *)&v47.x = v4;
  v36 = (float)((float)((float)((float)((float)v30 * (float)v4) + (float)((float)((float)x * (float)v26) * (float)v31))
                      * (float)v29)
              + (float)((float)((float)((float)((float)v28 * (float)v4) + (float)v32) * this->gravityNormal.z)
                      + (float)((float)v34 * this->gravityNormal.y)));
  v37 = (float)((float)v36 * this->gravityNormal.z);
  v48.y = (float)v34 - (float)((float)v36 * this->gravityNormal.y);
  v48.x = (float)((float)((float)v30 * (float)v4) + (float)v33) - (float)((float)v36 * (float)v29);
  v48.z = (float)v35 - (float)v37;
  v47 = v48;
  airAccelerate = this->airAccelerate;
  _FP10 = (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f10, f3, f11 }
  v41 = __frsqrte(_FP8);
  v42 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41
                                                                                      * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y)))
                                                                                              * (float)0.5))
                                                                              * (float)v41)
                                                                      - (float)1.5)
                                                      * (float)v41)
                                              * (float)((float)((float)(v48.x * v48.x)
                                                              + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v41
                                                                              * (float)((float)((float)(v48.x * v48.x)
                                                                                              + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y)))
                                                                                      * (float)0.5))
                                                                      * (float)v41)
                                                              - (float)1.5)
                                              * (float)v41))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v41
                                                      * (float)((float)((float)(v48.x * v48.x)
                                                                      + (float)((float)(v48.z * v48.z)
                                                                              + (float)(v48.y * v48.y)))
                                                              * (float)0.5))
                                              * (float)v41)
                                      - (float)1.5)
                      * (float)v41));
  v47.x = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                                * (float)v41)
                                                                                        * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                        * (float)v41))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v41
                                                                                                * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5))
                                                                                        * (float)v41)
                                                                                - (float)1.5)
                                                                * (float)v41))
                                                * (float)((float)((float)(v48.x * v48.x)
                                                                + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y)))
                                                        * (float)0.5))
                                        * (float)v42)
                                - (float)1.5)
                * (float)v42)
        * v48.x;
  v47.y = v48.y
        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                                * (float)v41)
                                                                                        * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                        * (float)v41))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v41
                                                                                                * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5))
                                                                                        * (float)v41)
                                                                                - (float)1.5)
                                                                * (float)v41))
                                                * (float)((float)((float)(v48.x * v48.x)
                                                                + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y)))
                                                        * (float)0.5))
                                        * (float)v42)
                                - (float)1.5)
                * (float)v42);
  v47.z = v48.z
        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                                * (float)v41)
                                                                                        * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                        * (float)v41))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v41
                                                                                                * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5))
                                                                                        * (float)v41)
                                                                                - (float)1.5)
                                                                * (float)v41))
                                                * (float)((float)((float)(v48.x * v48.x)
                                                                + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y)))
                                                        * (float)0.5))
                                        * (float)v42)
                                - (float)1.5)
                * (float)v42);
  idPhysics_Player::Accelerate(
    this,
    wishdir: &v47,
    wishspeed: (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5)) * (float)v41) - (float)1.5) * (float)v41)
                                                                                                  * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5))
                                                                                          * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5)) * (float)v41) - (float)1.5)
                                                                                                  * (float)v41))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v41 * (float)((float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))) * (float)0.5))
                                                                                                  * (float)v41)
                                                                                          - (float)1.5)
                                                                          * (float)v41))
                                                          * (float)((float)((float)(v48.x * v48.x)
                                                                          + (float)((float)(v48.z * v48.z)
                                                                                  + (float)(v48.y * v48.y)))
                                                                  * (float)0.5))
                                                  * (float)v42)
                                          - (float)1.5)
                          * (float)v42)
                  * (float)((float)(v48.x * v48.x) + (float)((float)(v48.z * v48.z) + (float)(v48.y * v48.y))))
          * (float)v3),
    accel: airAccelerate);
  v43 = this->current.velocity.z;
  v44 = (float)(this->current.velocity.y + (float)(this->externalVelocity.y * pm_externalVelocityAirScale.valueFloat));
  v45 = (float)(this->externalVelocity.z * pm_externalVelocityAirScale.valueFloat);
  this->current.velocity.x = this->current.velocity.x
                           + (float)(pm_externalVelocityAirScale.valueFloat * this->externalVelocity.x);
  this->current.velocity.y = v44;
  this->current.velocity.z = (float)v43 + (float)v45;
  if ( this->groundPlane )
    idVec3::ProjectOntoPlane(this: &this->current.velocity, normal: &this->groundTrace.c.normal, overBounce: 1.001);
  v46 = (this->current.movementFlags & 0x400) != 0;
  if ( g_pm_deferredSlideMove )
  {
    idPhysics_Player::SlideMoveDeferred(
      this,
      gravity: true,
      stepUp: v46,
      stepDown: false,
      ignoreEntityNum: this->entityNumber);
  }
  else
  {
    idPhysics_Player::SlideMoveNonDeferred(
      this,
      gravity: true,
      stepUp: v46,
      stepDown: false,
      push: false,
      ignoreEntityNum: this->entityNumber);
    idPhysics_Player::CheckGround(this);
  }
}


// ========================================================================
// ?WalkMove@idPhysics_Player@@AAAXXZ
// EA  : 0x827589D8
// RVA : 0x007589D8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::WalkMove(idPhysics_Player *this)
{
  double y; // fp11
  double z; // fp8
  __int64 v4; // r6
  double v5; // fp1
  double v6; // fp6
  double v7; // fp10
  double v8; // fp29
  double v9; // fp31
  double v10; // fp13
  double v11; // fp0
  double v12; // fp2
  double v13; // fp13
  double v14; // fp6
  double v15; // fp7
  double v16; // fp2
  double v17; // fp11
  __int64 v18; // r11
  double v20; // fp5
  double v22; // fp6
  double v23; // fp7
  double v24; // fp4
  double v25; // fp10
  double v26; // fp9
  double v28; // fp4
  double v30; // fp2
  double v31; // fp3
  double v32; // fp12
  double v33; // fp8
  double v34; // fp10
  __int64 v35; // r4
  double x; // fp5
  double v37; // fp10
  double v38; // fp11
  double v39; // fp3
  bool v40; // mr_fpscr49
  double v42; // fp1
  double v44; // fp10
  double v45; // fp11
  double v46; // fp10
  double v47; // fp0
  double v48; // fp13
  double v49; // fp12
  double v50; // fp27
  double v51; // fp29
  const idVec3 *v52; // r3
  idVec3 *NearestPerpendicular; // r3
  float *v54; // r3
  idVec3 *p_modifiedAccelerationVec; // r30
  long double v56; // fp4
  long double v57; // fp2
  long double v58; // fp2
  double v59; // fp13
  double modifiedMovementAngle; // fp12
  double modifiedMovementMaxPercent; // fp0
  double v62; // fp0
  int movementFlags; // r11
  double airAccelerate; // fp2
  double v65; // fp9
  double v66; // fp8
  double v67; // fp6
  double v68; // fp5
  float v69; // r11
  float v70; // r10
  float v71; // r9
  double v72; // fp8
  double v73; // fp8
  double v74; // fp11
  double v75; // fp10
  double v76; // fp11
  double v77; // fp10
  double v78; // fp9
  idVec3 v79; // [sp+50h] [-80h] BYREF
  idVec3 v80[5]; // [sp+60h] [-70h] BYREF

  if ( (unsigned __int8)idPhysics_Player::CheckJump(this) != 0 )
  {
    idPhysics_Player::AirMove(this);
    y = this->current.velocity.y;
    this->current.velocity.x = this->current.velocity.x + this->current.pushVelocity.x;
    z = this->current.velocity.z;
    this->current.velocity.y = this->current.pushVelocity.y + (float)y;
    this->current.velocity.z = this->current.pushVelocity.z + (float)z;
    this->lastJumpChance = 0;
  }
  else
  {
    this->lastJumpChance = 100;
    idPhysics_Player::Friction(this);
    v5 = idPhysics_Player::CmdScale(this, cmd: v4);
    v6 = this->viewForward.y;
    v7 = this->viewForward.z;
    v8 = v5;
    v9 = 1.001;
    v10 = (float)(this->gravityNormal.z
                * (float)((float)(this->gravityNormal.x * this->viewForward.x)
                        + (float)((float)(this->gravityNormal.z * this->viewForward.z)
                                + (float)(this->gravityNormal.y * this->viewForward.y))));
    v11 = (float)(this->gravityNormal.y
                * (float)((float)(this->gravityNormal.x * this->viewForward.x)
                        + (float)((float)(this->gravityNormal.z * this->viewForward.z)
                                + (float)(this->gravityNormal.y * this->viewForward.y))));
    this->viewForward.x = this->viewForward.x
                        - (float)(this->gravityNormal.x
                                * (float)((float)(this->gravityNormal.x * this->viewForward.x)
                                        + (float)((float)(this->gravityNormal.z * this->viewForward.z)
                                                + (float)(this->gravityNormal.y * this->viewForward.y))));
    this->viewForward.z = (float)v7 - (float)v10;
    this->viewForward.y = (float)v6 - (float)v11;
    v12 = this->viewRight.y;
    v13 = this->viewRight.z;
    v14 = (float)(this->gravityNormal.z
                * (float)((float)(this->gravityNormal.x * this->viewRight.x)
                        + (float)((float)(this->viewRight.z * this->gravityNormal.z)
                                + (float)(this->gravityNormal.y * this->viewRight.y))));
    v15 = (float)(this->gravityNormal.y
                * (float)((float)(this->gravityNormal.x * this->viewRight.x)
                        + (float)((float)(this->viewRight.z * this->gravityNormal.z)
                                + (float)(this->gravityNormal.y * this->viewRight.y))));
    this->viewRight.x = this->viewRight.x
                      - (float)(this->gravityNormal.x
                              * (float)((float)(this->gravityNormal.x * this->viewRight.x)
                                      + (float)((float)(this->viewRight.z * this->gravityNormal.z)
                                              + (float)(this->gravityNormal.y * this->viewRight.y))));
    this->viewRight.z = (float)v13 - (float)v14;
    this->viewRight.y = (float)v12 - (float)v15;
    idVec3::ProjectOntoPlane(this: &this->viewForward, normal: &this->groundTrace.c.normal, overBounce: 1.001);
    idVec3::ProjectOntoPlane(this: &this->viewRight, normal: &this->groundTrace.c.normal, overBounce: 1.001);
    v16 = this->viewForward.y;
    v17 = this->viewForward.z;
    HIDWORD(v18) = &si_vector_decode_cat_0[184];
    _FP8 = (float)((float)((float)(this->viewForward.z * this->viewForward.z)
                         + (float)((float)(this->viewForward.x * this->viewForward.x)
                                 + (float)(this->viewForward.y * this->viewForward.y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v20 = (float)((float)((float)(this->viewForward.z * this->viewForward.z)
                        + (float)((float)(this->viewForward.x * this->viewForward.x)
                                + (float)(this->viewForward.y * this->viewForward.y)))
                * (float)0.5);
    __asm { fsel      f7, f8, f9, f0 }
    v22 = __frsqrte(_FP7);
    v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)(this->viewForward.z * this->viewForward.z) + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22)
                                                * (float)((float)((float)(this->viewForward.z * this->viewForward.z)
                                                                + (float)((float)(this->viewForward.x
                                                                                * this->viewForward.x)
                                                                        + (float)(this->viewForward.y
                                                                                * this->viewForward.y)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                * (float)((float)((float)(this->viewForward.z * this->viewForward.z)
                                                                                                + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y)))
                                                                                        * (float)0.5))
                                                                        * (float)v22)
                                                                - (float)1.5)
                                                * (float)v22))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v22
                                                        * (float)((float)((float)(this->viewForward.z
                                                                                * this->viewForward.z)
                                                                        + (float)((float)(this->viewForward.x
                                                                                        * this->viewForward.x)
                                                                                + (float)(this->viewForward.y
                                                                                        * this->viewForward.y)))
                                                                * (float)0.5))
                                                * (float)v22)
                                        - (float)1.5)
                        * (float)v22));
    v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(this->viewForward.z * this->viewForward.z) + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                * (float)v22)
                                                                                        * (float)((float)((float)(this->viewForward.z * this->viewForward.z) + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(this->viewForward.z * this->viewForward.z) + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                        * (float)v22))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                                * (float)((float)((float)(this->viewForward.z * this->viewForward.z) + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y))) * (float)0.5))
                                                                                        * (float)v22)
                                                                                - (float)1.5)
                                                                * (float)v22))
                                                * (float)v20)
                                        * (float)v23)
                                - (float)1.5)
                * (float)v23);
    this->viewForward.x = this->viewForward.x
                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(this->viewForward.z * this->viewForward.z) + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y))) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22) * (float)((float)((float)(this->viewForward.z * this->viewForward.z) + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y))) * (float)0.5))
                                                                                                * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(this->viewForward.z * this->viewForward.z) + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y))) * (float)0.5)) * (float)v22) - (float)1.5) * (float)v22))
                                                                                        - (float)1.5)
                                                                        * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)(this->viewForward.z * this->viewForward.z) + (float)((float)(this->viewForward.x * this->viewForward.x) + (float)(this->viewForward.y * this->viewForward.y))) * (float)0.5)) * (float)v22)
                                                                                                - (float)1.5)
                                                                                * (float)v22))
                                                                * (float)v20)
                                                        * (float)v23)
                                                - (float)1.5)
                                * (float)v23);
    this->viewForward.z = (float)v17 * (float)v24;
    this->viewForward.y = (float)v16 * (float)v24;
    v25 = this->viewRight.z;
    v26 = this->viewRight.y;
    _FP5 = (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                         + (float)((float)(this->viewRight.x * this->viewRight.x)
                                 + (float)(this->viewRight.y * this->viewRight.y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v28 = (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                        + (float)((float)(this->viewRight.x * this->viewRight.x)
                                + (float)(this->viewRight.y * this->viewRight.y)))
                * (float)0.5);
    __asm { fsel      f3, f5, f6, f12 }
    v30 = __frsqrte(_FP3);
    v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30
                                                                                        * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y)))
                                                                                                * (float)0.5))
                                                                                * (float)v30)
                                                                        - (float)1.5)
                                                        * (float)v30)
                                                * (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                                                                + (float)((float)(this->viewRight.x * this->viewRight.x)
                                                                        + (float)(this->viewRight.y * this->viewRight.y)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v30
                                                                                * (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                                                                                                + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y)))
                                                                                        * (float)0.5))
                                                                        * (float)v30)
                                                                - (float)1.5)
                                                * (float)v30))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v30
                                                        * (float)((float)((float)(this->viewRight.z * this->viewRight.z)
                                                                        + (float)((float)(this->viewRight.x
                                                                                        * this->viewRight.x)
                                                                                + (float)(this->viewRight.y
                                                                                        * this->viewRight.y)))
                                                                * (float)0.5))
                                                * (float)v30)
                                        - (float)1.5)
                        * (float)v30));
    v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                                * (float)v30)
                                                                                        * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                        * (float)v30))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v30
                                                                                                * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5))
                                                                                        * (float)v30)
                                                                                - (float)1.5)
                                                                * (float)v30))
                                                * (float)v28)
                                        * (float)v31)
                                - (float)1.5)
                * (float)v31);
    v33 = (float)(this->viewRight.x
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                                * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                                * (float)v30))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5))
                                                                                                * (float)v30)
                                                                                        - (float)1.5)
                                                                        * (float)v30))
                                                        * (float)v28)
                                                * (float)v31)
                                        - (float)1.5)
                        * (float)v31));
    this->viewRight.x = this->viewRight.x
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30) * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(this->viewRight.z * this->viewRight.z) + (float)((float)(this->viewRight.x * this->viewRight.x) + (float)(this->viewRight.y * this->viewRight.y))) * (float)0.5)) * (float)v30)
                                                                                              - (float)1.5)
                                                                              * (float)v30))
                                                              * (float)v28)
                                                      * (float)v31)
                                              - (float)1.5)
                              * (float)v31);
    v34 = (float)((float)v25 * (float)v32);
    this->viewRight.z = v34;
    this->viewRight.y = (float)v26 * (float)v32;
    LODWORD(v35) = this->command.rightmove;
    *(_QWORD *)&v79.x = v35;
    x = this->viewForward.x;
    LODWORD(v18) = this->command.forwardmove;
    v38 = (float)((float)((float)v18 * this->viewForward.z) + (float)((float)v34 * (float)v35));
    *(_QWORD *)&v79.x = v18;
    v37 = (float)(this->viewForward.y * (float)v18);
    v79.z = v38;
    v79.x = (float)((float)x * (float)v18) + (float)((float)v33 * (float)v35);
    v79.y = (float)v37 + (float)((float)v35 * (float)((float)v26 * (float)v32));
    v39 = (float)((float)(v79.y * v79.y) + (float)((float)(v79.x * v79.x) + (float)((float)v38 * (float)v38)));
    v40 = this->blockedAccelerationPercent > 0.0;
    _FP2 = (float)((float)((float)(v79.y * v79.y) + (float)((float)(v79.x * v79.x) + (float)((float)v38 * (float)v38)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v42 = (float)((float)((float)(v79.y * v79.y) + (float)((float)(v79.x * v79.x) + (float)((float)v38 * (float)v38)))
                * (float)0.5);
    __asm { fsel      f11, f2, f3, f11 }
    v44 = __frsqrte(_FP11);
    v45 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v42)
                                                                                * (float)v44)
                                                                        - (float)1.5)
                                                        * (float)v44)
                                                * (float)v42)
                                        * (float)((float)-(float)((float)((float)((float)v44 * (float)v42) * (float)v44)
                                                                - (float)1.5)
                                                * (float)v44))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v44 * (float)v42) * (float)v44) - (float)1.5)
                        * (float)v44));
    v46 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v44 * (float)v42)
                                                                                        * (float)v44)
                                                                                - (float)1.5)
                                                                * (float)v44)
                                                        * (float)v42)
                                                * (float)((float)-(float)((float)((float)((float)v44 * (float)v42)
                                                                                * (float)v44)
                                                                        - (float)1.5)
                                                        * (float)v44))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v44 * (float)v42) * (float)v44) - (float)1.5)
                                * (float)v44))
                * (float)v42);
    v47 = (float)(v79.x * (float)((float)-(float)((float)((float)v46 * (float)v45) - (float)1.5) * (float)v45));
    v80[0].x = v79.x * (float)((float)-(float)((float)((float)v46 * (float)v45) - (float)1.5) * (float)v45);
    v48 = (float)(v79.y * (float)((float)-(float)((float)((float)v46 * (float)v45) - (float)1.5) * (float)v45));
    v80[0].y = v79.y * (float)((float)-(float)((float)((float)v46 * (float)v45) - (float)1.5) * (float)v45);
    v49 = (float)(v79.z * (float)((float)-(float)((float)((float)v46 * (float)v45) - (float)1.5) * (float)v45));
    v80[0].z = v79.z * (float)((float)-(float)((float)((float)v46 * (float)v45) - (float)1.5) * (float)v45);
    v50 = (float)((float)((float)((float)-(float)((float)((float)v46 * (float)v45) - (float)1.5) * (float)v45)
                        * (float)v39)
                * (float)v8);
    if ( v40 )
    {
      v51 = (float)((float)(this->blockedAccelerationVec.x
                          * (float)(v79.x
                                  * (float)((float)-(float)((float)((float)v46 * (float)v45) - (float)1.5) * (float)v45)))
                  + (float)((float)(this->blockedAccelerationVec.z
                                  * (float)(v79.z
                                          * (float)((float)-(float)((float)((float)v46 * (float)v45) - (float)1.5)
                                                  * (float)v45)))
                          + (float)(this->blockedAccelerationVec.y
                                  * (float)(v79.y
                                          * (float)((float)-(float)((float)((float)v46 * (float)v45) - (float)1.5)
                                                  * (float)v45)))));
      if ( v51 > 0.0 )
      {
        v52 = this->GetGravityNormal(this);
        NearestPerpendicular = idGeometry::FindNearestPerpendicular(
                                 result: &v79,
                                 input: &this->blockedAccelerationVec,
                                 up: v52,
                                 hint: v80);
        v47 = NearestPerpendicular->x;
        v80[0].x = NearestPerpendicular->x;
        v50 = (float)((float)((float)((float)1.0 - (float)v51) * (float)v50) * (float)0.89999998);
        v48 = NearestPerpendicular->y;
        v80[0].y = NearestPerpendicular->y;
        v49 = NearestPerpendicular->z;
        v80[0].z = NearestPerpendicular->z;
      }
      this->blockedAccelerationPercent = 0.0;
    }
    if ( (float)((float)((float)v48 * (float)v48)
               + (float)((float)((float)v47 * (float)v47) + (float)((float)v49 * (float)v49))) > 0.0
      && this->modifiedMovementMaxPercent > 0.0
      && this->modifiedMovementAngle > 0.0 )
    {
      v54 = (float *)this->GetGravityAxis(this);
      *((double *)&v56 + 1) = (float)((float)(this->modifiedAccelerationVec.z * v80[0].z)
                                    + (float)(this->modifiedAccelerationVec.y * v80[0].y));
      *(double *)&v56 = (float)((float)((float)(v54[7] * this->modifiedAccelerationVec.x)
                                      - (float)(v54[6] * this->modifiedAccelerationVec.y))
                              * v80[0].z);
      *((double *)&v57 + 1) = (float)((float)(v80[0].x * this->modifiedAccelerationVec.x)
                                    + (float)((float)(this->modifiedAccelerationVec.z * v80[0].z)
                                            + (float)(this->modifiedAccelerationVec.y * v80[0].y)));
      *(double *)&v57 = (float)((float)((float)((float)(v54[6] * this->modifiedAccelerationVec.z)
                                              - (float)(v54[8] * this->modifiedAccelerationVec.x))
                                      * v80[0].y)
                              + (float)((float)((float)((float)(v54[8] * this->modifiedAccelerationVec.y)
                                                      - (float)(v54[7] * this->modifiedAccelerationVec.z))
                                              * v80[0].x)
                                      + (float)((float)((float)(v54[7] * this->modifiedAccelerationVec.x)
                                                      - (float)(v54[6] * this->modifiedAccelerationVec.y))
                                              * v80[0].z)));
      v58 = atan2(v: v57, u: v56);
      v59 = __fabs((float)((float)*(double *)&v58 * idMath::M_RAD2DEG));
      if ( v59 >= this->modifiedMovementAngle )
        modifiedMovementAngle = (float)((float)180.0 - this->modifiedMovementAngle);
      else
        modifiedMovementAngle = this->modifiedMovementAngle;
      p_modifiedAccelerationVec = &this->modifiedAccelerationVec;
      modifiedMovementMaxPercent = (float)-(float)((float)((float)__fsqrts((float)((float)(p_modifiedAccelerationVec->x
                                                                                         * p_modifiedAccelerationVec->x)
                                                                                 + (float)((float)(p_modifiedAccelerationVec->y
                                                                                                 * p_modifiedAccelerationVec->y)
                                                                                         + (float)(p_modifiedAccelerationVec->z
                                                                                                 * p_modifiedAccelerationVec->z))))
                                                         * (float)((float)(this->modifiedMovementAngle - (float)v59)
                                                                 / (float)modifiedMovementAngle))
                                                 - (float)1.0);
      if ( modifiedMovementMaxPercent >= 0.0 )
      {
        if ( modifiedMovementMaxPercent > this->modifiedMovementMaxPercent )
          modifiedMovementMaxPercent = this->modifiedMovementMaxPercent;
      }
      else
      {
        modifiedMovementMaxPercent = 0.0;
      }
      v9 = 1.001;
      v50 = (float)((float)modifiedMovementMaxPercent * (float)v50);
    }
    if ( this->waterLevel > 0.0 )
    {
      v62 = this->currentSwimDepthState == SWIMDEPTH_STATE_ON_SURFACE ? 0.60000002 : 1.0;
      if ( v50 > (float)(this->playerSpeed
                       * (float)-(float)((float)((float)-(float)((float)((float)v62 * 0.60000002) - (float)1.0)
                                               * this->waterLevel)
                                       - (float)1.0)) )
        v50 = (float)(this->playerSpeed
                    * (float)-(float)((float)((float)-(float)((float)((float)v62 * 0.60000002) - (float)1.0)
                                            * this->waterLevel)
                                    - (float)1.0));
    }
    movementFlags = this->current.movementFlags;
    airAccelerate = 0.0;
    if ( (movementFlags & 0x800) == 0 )
    {
      if ( (this->groundSurfaceFlags & 0x20) != 0 || (movementFlags & 0x40) != 0 )
        airAccelerate = this->airAccelerate;
      else
        airAccelerate = this->walkAccelerate;
    }
    idPhysics_Player::Accelerate(this, wishdir: v80, wishspeed: v50, accel: airAccelerate);
    if ( (this->groundSurfaceFlags & 0x20) != 0 || (this->current.movementFlags & 0x40) != 0 )
    {
      v65 = (float)(this->gravityVector.y * this->frametime);
      v66 = (float)(this->gravityVector.z * this->frametime);
      v67 = this->current.velocity.y;
      v68 = this->current.velocity.z;
      this->current.velocity.x = this->current.velocity.x + (float)(this->gravityVector.x * this->frametime);
      this->current.velocity.y = (float)v65 + (float)v67;
      this->current.velocity.z = (float)v66 + (float)v68;
    }
    v69 = this->current.velocity.x;
    v70 = this->current.velocity.y;
    v71 = this->current.velocity.z;
    this->current.velocity.x = v69 + this->externalVelocity.x;
    v72 = this->current.velocity.z;
    this->current.velocity.y = this->externalVelocity.y + v70;
    this->current.velocity.z = this->externalVelocity.z + (float)v72;
    v79.x = v69;
    v79.y = v70;
    v79.z = v71;
    idVec3::ProjectOntoPlane(this: &this->current.velocity, normal: &this->groundTrace.c.normal, overBounce: v9);
    if ( (float)((float)(v79.z * this->current.velocity.z)
               + (float)((float)(v79.x * this->current.velocity.x) + (float)(v79.y * this->current.velocity.y))) > 0.0 )
    {
      v73 = this->current.velocity.y;
      if ( (float)((float)(this->current.velocity.x * this->current.velocity.x)
                 + (float)((float)(this->current.velocity.y * this->current.velocity.y)
                         + (float)(this->current.velocity.z * this->current.velocity.z))) > 1.0
        && (float)((float)(v79.x * v79.x) + (float)((float)(v79.y * v79.y) + (float)(v79.z * v79.z))) > 1.0 )
      {
        v74 = this->current.velocity.z;
        v75 = __fsqrts((float)((float)((float)(v79.x * v79.x) + (float)((float)(v79.y * v79.y) + (float)(v79.z * v79.z)))
                             / (float)((float)(this->current.velocity.x * this->current.velocity.x)
                                     + (float)((float)(this->current.velocity.y * this->current.velocity.y)
                                             + (float)(this->current.velocity.z * this->current.velocity.z)))));
        this->current.velocity.x = this->current.velocity.x * (float)v75;
        this->current.velocity.y = (float)v75 * (float)v73;
        this->current.velocity.z = (float)v75 * (float)v74;
      }
    }
    v76 = (float)(this->current.velocity.y
                - (float)(this->gravityNormal.y
                        * (float)((float)(this->gravityNormal.x * this->current.velocity.x)
                                + (float)((float)(this->gravityNormal.z * this->current.velocity.z)
                                        + (float)(this->gravityNormal.y * this->current.velocity.y)))));
    v77 = (float)(this->current.velocity.z
                - (float)(this->gravityNormal.z
                        * (float)((float)(this->gravityNormal.x * this->current.velocity.x)
                                + (float)((float)(this->gravityNormal.z * this->current.velocity.z)
                                        + (float)(this->gravityNormal.y * this->current.velocity.y)))));
    v78 = (float)(this->current.velocity.x
                - (float)(this->gravityNormal.x
                        * (float)((float)(this->gravityNormal.x * this->current.velocity.x)
                                + (float)((float)(this->gravityNormal.z * this->current.velocity.z)
                                        + (float)(this->gravityNormal.y * this->current.velocity.y)))));
    if ( (float)((float)((float)v78 * (float)v78)
               + (float)((float)((float)v77 * (float)v77) + (float)((float)v76 * (float)v76))) >= 0.1 )
    {
      if ( g_pm_deferredSlideMove )
      {
        idPhysics_Player::SlideMoveDeferred(
          this,
          gravity: false,
          stepUp: true,
          stepDown: true,
          ignoreEntityNum: this->entityNumber);
      }
      else
      {
        idPhysics_Player::SlideMoveNonDeferred(
          this,
          gravity: false,
          stepUp: true,
          stepDown: true,
          push: true,
          ignoreEntityNum: this->entityNumber);
        idPhysics_Player::CheckGround(this);
      }
    }
  }
}


// ========================================================================
// ?PerfectOriginMove@idPhysics_Player@@AAAXH@Z
// EA  : 0x827591A0
// RVA : 0x007591A0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::PerfectOriginMove(idPhysics_Player *this, int deltaMS)
{
  float y; // r8
  int perfectOriginDuration; // r9
  int v5; // r10
  __int64 v6; // r7
  __int64 v7; // r5
  double v8; // fp0
  double v9; // fp13
  double v10; // fp12
  double v11; // fp9
  double v12; // fp4
  double v13; // fp3
  double v14; // fp1
  float x; // [sp+70h] [-20h]
  float z; // [sp+78h] [-18h]

  this->current.velocity.x = 0.0;
  this->current.velocity.y = 0.0;
  this->current.velocity.z = 0.0;
  y = this->perfectOriginPosition.y;
  perfectOriginDuration = this->perfectOriginDuration;
  v5 = this->perfectOriginTime + deltaMS;
  x = this->perfectOriginPosition.x;
  z = this->perfectOriginPosition.z;
  this->perfectOriginTime = v5;
  if ( v5 >= perfectOriginDuration )
  {
    v8 = x;
    v9 = y;
    v10 = z;
  }
  else
  {
    LODWORD(v6) = v5;
    *(float *)&v6 = this->perfectOriginPosition.z;
    LODWORD(v7) = perfectOriginDuration;
    *(float *)&v7 = this->current.worldOrigin.y;
    v8 = (float)((float)((float)(this->perfectOriginPosition.x - this->current.worldOrigin.x)
                       * (float)((float)v6 / (float)v7))
               + this->current.worldOrigin.x);
    v9 = (float)((float)((float)(y - *(float *)&v7) * (float)((float)v6 / (float)v7)) + *(float *)&v7);
    v10 = (float)((float)((float)(*(float *)&v6 - this->current.worldOrigin.z) * (float)((float)v6 / (float)v7))
                + this->current.worldOrigin.z);
  }
  v11 = (float)((float)v8 - this->current.worldOrigin.x);
  v12 = (float)((float)v10 - this->current.worldOrigin.z);
  v13 = (float)((float)1.0 / this->frametime);
  v14 = (float)((float)((float)v9 - this->current.worldOrigin.y) * (float)((float)1.0 / this->frametime));
  this->current.velocity.y = (float)((float)v9 - this->current.worldOrigin.y) * (float)((float)1.0 / this->frametime);
  this->current.velocity.x = (float)v13 * (float)v11;
  this->current.velocity.z = (float)v12 * (float)v13;
  if ( (float)((float)((float)((float)v12 * (float)v13) * (float)((float)v12 * (float)v13))
             + (float)((float)((float)((float)v13 * (float)v11) * (float)((float)v13 * (float)v11))
                     + (float)((float)v14 * (float)v14))) != 0.0 )
  {
    if ( g_pm_deferredSlideMove )
    {
      idPhysics_Player::SlideMoveDeferred(
        this,
        gravity: false,
        stepUp: false,
        stepDown: false,
        ignoreEntityNum: this->entityNumber);
    }
    else
    {
      idPhysics_Player::SlideMoveNonDeferred(
        this,
        gravity: false,
        stepUp: false,
        stepDown: false,
        push: false,
        ignoreEntityNum: this->entityNumber);
      idPhysics_Player::CheckGround(this);
    }
  }
}


// ========================================================================
// ?DeadMove@idPhysics_Player@@AAAXXZ
// EA  : 0x82759368
// RVA : 0x00759368
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::DeadMove(idPhysics_Player *this)
{
  idVec3 *p_velocity; // r31
  double v3; // fp31
  double v4; // fp10
  double v5; // fp9

  if ( common->IsMultiplayer(this: common) )
  {
    idPhysics_Player::Friction(this);
    if ( g_pm_deferredSlideMove )
    {
      idPhysics_Player::SlideMoveDeferred(
        this,
        gravity: true,
        stepUp: true,
        stepDown: true,
        ignoreEntityNum: this->entityNumber);
    }
    else
    {
      idPhysics_Player::SlideMoveNonDeferred(
        this,
        gravity: true,
        stepUp: true,
        stepDown: true,
        push: true,
        ignoreEntityNum: this->entityNumber);
      idPhysics_Player::CheckGround(this);
    }
  }
  else if ( this->walking )
  {
    p_velocity = &this->current.velocity;
    v3 = (float)((float)__fsqrts((float)((float)(p_velocity->z * p_velocity->z)
                                       + (float)((float)(p_velocity->x * p_velocity->x)
                                               + (float)(p_velocity->y * p_velocity->y))))
               - (float)20.0);
    if ( v3 > 0.0 )
    {
      idVec3::NormalizeFast(this: p_velocity);
      v4 = (float)(p_velocity->y * (float)v3);
      v5 = (float)((float)v3 * p_velocity->z);
      p_velocity->x = p_velocity->x * (float)v3;
      p_velocity->y = v4;
      p_velocity->z = v5;
    }
    else
    {
      p_velocity->z = 0.0;
      p_velocity->y = 0.0;
      p_velocity->x = 0.0;
    }
  }
}


// ========================================================================
// ?SpectatorMove@idPhysics_Player@@AAAXXZ
// EA  : 0x82759490
// RVA : 0x00759490
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysics_Player::SpectatorMove(idPhysics_Player *this)
{
  __int64 v2; // r6
  __int64 v3; // r6 OVERLAPPED
  double v4; // fp1
  double v5; // fp0
  double v6; // fp13
  double v7; // fp12
  int forwardmove; // r7
  double x; // fp11
  double v10; // fp2
  double v11; // fp0
  double v12; // fp13
  double flyAccelerate; // fp2
  double v14; // fp5
  double v16; // fp3
  double v18; // fp12
  double v19; // fp12
  idPhysics_Player *v20; // r3
  idVec3 v21; // [sp+50h] [-20h] BYREF

  idPhysics_Player::Friction(this);
  v4 = idPhysics_Player::CmdScale(this, cmd: v2);
  v5 = 0.0;
  if ( v4 == 0.0 )
  {
    v6 = 0.0;
    v7 = 0.0;
  }
  else
  {
    forwardmove = this->command.forwardmove;
    LODWORD(v3) = this->command.rightmove;
    x = this->viewForward.x;
    v10 = (float)(this->viewRight.x * (float)v3);
    v11 = (float)(this->viewRight.y * (float)v3);
    v12 = (float)(this->viewRight.z * (float)v3);
    *(_QWORD *)&v21.x = v3;
    v7 = (float)((float)((float)v11 + (float)(this->viewForward.y * (float)*(__int64 *)((char *)&v3 - 4))) * (float)v4);
    v5 = (float)((float)((float)((float)x * (float)*(__int64 *)((char *)&v3 - 4)) + (float)v10) * (float)v4);
    v6 = (float)((float)((float)(this->viewForward.z * (float)*(__int64 *)((char *)&v3 - 4)) + (float)v12) * (float)v4);
  }
  v21.y = v7;
  v21.z = v6;
  v21.x = v5;
  flyAccelerate = this->flyAccelerate;
  v14 = (float)((float)((float)v5 * (float)v5) + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)));
  _FP4 = (float)((float)((float)((float)v5 * (float)v5)
                       + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v16 = (float)((float)((float)((float)v5 * (float)v5)
                      + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))
              * (float)0.5);
  __asm { fsel      f1, f4, f5, f11 }
  v18 = __frsqrte(_FP1);
  v19 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v18 * (float)v16)
                                                                              * (float)v18)
                                                                      - (float)1.5)
                                                      * (float)v18)
                                              * (float)v16)
                                      * (float)((float)-(float)((float)((float)((float)v18 * (float)v16) * (float)v18)
                                                              - (float)1.5)
                                              * (float)v18))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v18 * (float)v16) * (float)v18) - (float)1.5) * (float)v18));
  v21.x = (float)((float)-(float)((float)((float)((float)v19 * (float)v16) * (float)v19) - (float)1.5) * (float)v19)
        * (float)v5;
  v21.y = v21.y
        * (float)((float)-(float)((float)((float)((float)v19 * (float)v16) * (float)v19) - (float)1.5) * (float)v19);
  v21.z = v21.z
        * (float)((float)-(float)((float)((float)((float)v19 * (float)v16) * (float)v19) - (float)1.5) * (float)v19);
  idPhysics_Player::Accelerate(
    this,
    wishdir: &v21,
    wishspeed: (float)((float)((float)-(float)((float)((float)((float)v19 * (float)v16) * (float)v19) - (float)1.5) * (float)v19)
          * (float)v14),
    accel: flyAccelerate);
  if ( g_pm_deferredSlideMove )
  {
    idPhysics_Player::SlideMoveDeferred(
      this: v20,
      gravity: false,
      stepUp: false,
      stepDown: false,
      ignoreEntityNum: this->entityNumber);
  }
  else
  {
    idPhysics_Player::SlideMoveNonDeferred(
      this: v20,
      gravity: false,
      stepUp: false,
      stepDown: false,
      push: false,
      ignoreEntityNum: this->entityNumber);
    idPhysics_Player::CheckGround(this);
  }
}


// ========================================================================
// ?LadderMove@idPhysics_Player@@AAAXXZ
// EA  : 0x82759660
// RVA : 0x00759660
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::LadderMove(idPhysics_Player *this, int a2, __int64 a3)
{
  idVec3 *p_velocity; // r31
  idVec3 *p_gravityNormal; // r29
  double v6; // fp1
  idVec3 *p_ladderNormal; // r28
  double v8; // fp0
  double v9; // fp10
  double v10; // fp5
  double v11; // fp4
  double y; // fp25
  double z; // fp24
  double x; // fp27
  double v15; // fp23
  double v16; // fp22
  double v17; // fp26
  double v18; // fp31
  double v19; // fp1
  __int64 v20; // r9
  __int64 v21; // r5
  double v22; // fp31
  double v23; // fp30
  double v24; // fp29
  double v25; // fp5
  double v26; // fp4
  double v27; // fp3
  double v30; // fp8
  double v31; // fp11
  double v32; // fp8
  double v33; // fp13
  double v34; // fp12
  double v35; // fp11
  double walkAccelerate; // fp2
  double v37; // fp11
  double v40; // fp7
  double v41; // fp13
  double v42; // fp9
  double v43; // fp31
  double v44; // fp30
  double v45; // fp29
  double v46; // fp13
  double v47; // fp12
  double v48; // fp11
  double v49; // fp0
  double v50; // fp7
  double v51; // fp8
  double v52; // fp0
  double v53; // fp9
  double v54; // fp8
  double v55; // fp5
  double v56; // fp12
  double frametime; // fp0
  double v58; // fp8
  double v59; // fp6
  double v60; // fp4
  double v61; // fp3
  double v62; // fp12
  double v63; // fp10
  double v64; // fp0
  double v65; // fp11
  double v66; // fp9
  double v67; // fp13
  double v68; // fp6
  double v69; // fp8
  double v70; // fp4
  double v71; // fp3
  double v72; // fp4
  double v73; // fp5
  double v74; // fp1
  double v75; // fp12
  idVec3 v76; // [sp+50h] [-B0h] BYREF

  p_velocity = &this->current.velocity;
  p_gravityNormal = &this->gravityNormal;
  v6 = (float)(this->ladderNormal.y * (float)-100.0);
  p_ladderNormal = &this->ladderNormal;
  v8 = 1.0;
  v9 = (float)(this->ladderNormal.z * (float)-100.0);
  v10 = (float)(this->gravityNormal.y
              * (float)((float)(this->gravityNormal.y * this->current.velocity.y)
                      + (float)((float)(this->gravityNormal.z * this->current.velocity.z)
                              + (float)(this->gravityNormal.x * this->current.velocity.x))));
  v11 = (float)(this->gravityNormal.z
              * (float)((float)(this->gravityNormal.y * this->current.velocity.y)
                      + (float)((float)(this->gravityNormal.z * this->current.velocity.z)
                              + (float)(this->gravityNormal.x * this->current.velocity.x))));
  this->current.velocity.x = (float)(this->gravityNormal.x
                                   * (float)((float)(this->gravityNormal.y * this->current.velocity.y)
                                           + (float)((float)(this->gravityNormal.z * this->current.velocity.z)
                                                   + (float)(this->gravityNormal.x * this->current.velocity.x))))
                           + (float)(this->ladderNormal.x * (float)-100.0);
  this->current.velocity.y = (float)v10 + (float)v6;
  this->current.velocity.z = (float)v11 + (float)v9;
  y = this->gravityNormal.y;
  z = this->viewForward.z;
  x = this->gravityNormal.x;
  v15 = this->viewForward.y;
  v16 = this->viewForward.x;
  v17 = this->gravityNormal.z;
  v18 = (float)((float)((float)((float)((float)-x * this->viewForward.x)
                              + (float)((float)((float)-y * this->viewForward.y)
                                      + (float)((float)-v17 * this->viewForward.z)))
                      + (float)0.5)
              * (float)2.5);
  if ( v18 > 1.0 || (v8 = -1.0, v18 < -1.0) )
    v18 = v8;
  v19 = idPhysics_Player::CmdScale(this, cmd: a3);
  HIDWORD(v20) = 0x82000000;
  LOBYTE(v20) = this->command.rightmove;
  LODWORD(v21) = this->command.forwardmove;
  *(_QWORD *)&v76.x = v21;
  v23 = (float)((float)((float)((float)((float)y * (float)-0.89999998) * (float)v18) * (float)v19) * (float)v21);
  v24 = (float)((float)((float)((float)((float)v17 * (float)-0.89999998) * (float)v18) * (float)v19) * (float)v21);
  v22 = (float)((float)((float)((float)((float)x * (float)-0.89999998) * (float)v18) * (float)v19) * (float)v21);
  if ( (_BYTE)v20 != 0 )
  {
    v25 = (float)((float)(this->viewRight.z
                        - (float)((float)v17
                                * (float)((float)((float)x * this->viewRight.x)
                                        + (float)((float)(p_gravityNormal->y * this->viewRight.y)
                                                + (float)(p_gravityNormal->z * this->viewRight.z)))))
                - (float)(p_ladderNormal->z
                        * (float)((float)(p_ladderNormal->x
                                        * (float)(this->viewRight.x
                                                - (float)((float)x
                                                        * (float)((float)((float)x * this->viewRight.x)
                                                                + (float)((float)(p_gravityNormal->y * this->viewRight.y)
                                                                        + (float)(p_gravityNormal->z * this->viewRight.z))))))
                                + (float)((float)((float)(this->viewRight.z
                                                        - (float)((float)v17
                                                                * (float)((float)((float)x * this->viewRight.x)
                                                                        + (float)((float)(p_gravityNormal->y
                                                                                        * this->viewRight.y)
                                                                                + (float)(p_gravityNormal->z
                                                                                        * this->viewRight.z)))))
                                                * p_ladderNormal->z)
                                        + (float)((float)(this->viewRight.y
                                                        - (float)((float)y
                                                                * (float)((float)((float)x * this->viewRight.x)
                                                                        + (float)((float)(p_gravityNormal->y
                                                                                        * this->viewRight.y)
                                                                                + (float)(p_gravityNormal->z
                                                                                        * this->viewRight.z)))))
                                                * p_ladderNormal->y)))));
    v26 = (float)((float)(this->viewRight.x
                        - (float)((float)x
                                * (float)((float)((float)x * this->viewRight.x)
                                        + (float)((float)(p_gravityNormal->y * this->viewRight.y)
                                                + (float)(p_gravityNormal->z * this->viewRight.z)))))
                - (float)(p_ladderNormal->x
                        * (float)((float)(p_ladderNormal->x
                                        * (float)(this->viewRight.x
                                                - (float)((float)x
                                                        * (float)((float)((float)x * this->viewRight.x)
                                                                + (float)((float)(p_gravityNormal->y * this->viewRight.y)
                                                                        + (float)(p_gravityNormal->z * this->viewRight.z))))))
                                + (float)((float)((float)(this->viewRight.z
                                                        - (float)((float)v17
                                                                * (float)((float)((float)x * this->viewRight.x)
                                                                        + (float)((float)(p_gravityNormal->y
                                                                                        * this->viewRight.y)
                                                                                + (float)(p_gravityNormal->z
                                                                                        * this->viewRight.z)))))
                                                * p_ladderNormal->z)
                                        + (float)((float)(this->viewRight.y
                                                        - (float)((float)y
                                                                * (float)((float)((float)x * this->viewRight.x)
                                                                        + (float)((float)(p_gravityNormal->y
                                                                                        * this->viewRight.y)
                                                                                + (float)(p_gravityNormal->z
                                                                                        * this->viewRight.z)))))
                                                * p_ladderNormal->y)))));
    v27 = (float)((float)(this->viewRight.y
                        - (float)((float)y
                                * (float)((float)((float)x * this->viewRight.x)
                                        + (float)((float)(p_gravityNormal->y * this->viewRight.y)
                                                + (float)(p_gravityNormal->z * this->viewRight.z)))))
                - (float)(p_ladderNormal->y
                        * (float)((float)(p_ladderNormal->x
                                        * (float)(this->viewRight.x
                                                - (float)((float)x
                                                        * (float)((float)((float)x * this->viewRight.x)
                                                                + (float)((float)(p_gravityNormal->y * this->viewRight.y)
                                                                        + (float)(p_gravityNormal->z * this->viewRight.z))))))
                                + (float)((float)((float)(this->viewRight.z
                                                        - (float)((float)v17
                                                                * (float)((float)((float)x * this->viewRight.x)
                                                                        + (float)((float)(p_gravityNormal->y
                                                                                        * this->viewRight.y)
                                                                                + (float)(p_gravityNormal->z
                                                                                        * this->viewRight.z)))))
                                                * p_ladderNormal->z)
                                        + (float)((float)(this->viewRight.y
                                                        - (float)((float)y
                                                                * (float)((float)((float)x * this->viewRight.x)
                                                                        + (float)((float)(p_gravityNormal->y
                                                                                        * this->viewRight.y)
                                                                                + (float)(p_gravityNormal->z
                                                                                        * this->viewRight.z)))))
                                                * p_ladderNormal->y)))));
    _FP11 = (float)((float)((float)((float)v27 * (float)v27)
                          + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
                  - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f9, f11, f12, f0 }
    v30 = __frsqrte(_FP9);
    v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30
                                                                                        * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
                                                                                                * (float)0.5))
                                                                                * (float)v30)
                                                                        - (float)1.5)
                                                        * (float)v30)
                                                * (float)((float)((float)((float)v27 * (float)v27)
                                                                + (float)((float)((float)v26 * (float)v26)
                                                                        + (float)((float)v25 * (float)v25)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v30
                                                                                * (float)((float)((float)((float)v27 * (float)v27)
                                                                                                + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
                                                                                        * (float)0.5))
                                                                        * (float)v30)
                                                                - (float)1.5)
                                                * (float)v30))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v30
                                                        * (float)((float)((float)((float)v27 * (float)v27)
                                                                        + (float)((float)((float)v26 * (float)v26)
                                                                                + (float)((float)v25 * (float)v25)))
                                                                * (float)0.5))
                                                * (float)v30)
                                        - (float)1.5)
                        * (float)v30));
    v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                                * (float)v30)
                                                                                        * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                        * (float)v30))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v30
                                                                                                * (float)((float)((float)((float)v27 * (float)v27) + (float)((float)((float)v26 * (float)v26) + (float)((float)v25 * (float)v25))) * (float)0.5))
                                                                                        * (float)v30)
                                                                                - (float)1.5)
                                                                * (float)v30))
                                                * (float)((float)((float)((float)v27 * (float)v27)
                                                                + (float)((float)((float)v26 * (float)v26)
                                                                        + (float)((float)v25 * (float)v25)))
                                                        * (float)0.5))
                                        * (float)v31)
                                - (float)1.5)
                * (float)v31);
    v33 = (float)((float)((float)(this->viewRight.x
                                - (float)((float)x
                                        * (float)((float)((float)x * this->viewRight.x)
                                                + (float)((float)(p_gravityNormal->y * this->viewRight.y)
                                                        + (float)(p_gravityNormal->z * this->viewRight.z)))))
                        - (float)(p_ladderNormal->x
                                * (float)((float)(p_ladderNormal->x
                                                * (float)(this->viewRight.x
                                                        - (float)((float)x
                                                                * (float)((float)((float)x * this->viewRight.x)
                                                                        + (float)((float)(p_gravityNormal->y
                                                                                        * this->viewRight.y)
                                                                                + (float)(p_gravityNormal->z
                                                                                        * this->viewRight.z))))))
                                        + (float)((float)((float)(this->viewRight.z
                                                                - (float)((float)v17
                                                                        * (float)((float)((float)x * this->viewRight.x)
                                                                                + (float)((float)(p_gravityNormal->y
                                                                                                * this->viewRight.y)
                                                                                        + (float)(p_gravityNormal->z
                                                                                                * this->viewRight.z)))))
                                                        * p_ladderNormal->z)
                                                + (float)((float)(this->viewRight.y
                                                                - (float)((float)y
                                                                        * (float)((float)((float)x * this->viewRight.x)
                                                                                + (float)((float)(p_gravityNormal->y
                                                                                                * this->viewRight.y)
                                                                                        + (float)(p_gravityNormal->z
                                                                                                * this->viewRight.z)))))
                                                        * p_ladderNormal->y)))))
                * (float)v32);
    v34 = (float)((float)((float)(this->viewRight.y
                                - (float)((float)y
                                        * (float)((float)((float)x * this->viewRight.x)
                                                + (float)((float)(p_gravityNormal->y * this->viewRight.y)
                                                        + (float)(p_gravityNormal->z * this->viewRight.z)))))
                        - (float)(p_ladderNormal->y
                                * (float)((float)(p_ladderNormal->x
                                                * (float)(this->viewRight.x
                                                        - (float)((float)x
                                                                * (float)((float)((float)x * this->viewRight.x)
                                                                        + (float)((float)(p_gravityNormal->y
                                                                                        * this->viewRight.y)
                                                                                + (float)(p_gravityNormal->z
                                                                                        * this->viewRight.z))))))
                                        + (float)((float)((float)(this->viewRight.z
                                                                - (float)((float)v17
                                                                        * (float)((float)((float)x * this->viewRight.x)
                                                                                + (float)((float)(p_gravityNormal->y
                                                                                                * this->viewRight.y)
                                                                                        + (float)(p_gravityNormal->z
                                                                                                * this->viewRight.z)))))
                                                        * p_ladderNormal->z)
                                                + (float)((float)(this->viewRight.y
                                                                - (float)((float)y
                                                                        * (float)((float)((float)x * this->viewRight.x)
                                                                                + (float)((float)(p_gravityNormal->y
                                                                                                * this->viewRight.y)
                                                                                        + (float)(p_gravityNormal->z
                                                                                                * this->viewRight.z)))))
                                                        * p_ladderNormal->y)))))
                * (float)v32);
    v35 = (float)((float)((float)(this->viewRight.z
                                - (float)((float)v17
                                        * (float)((float)((float)x * this->viewRight.x)
                                                + (float)((float)(p_gravityNormal->y * this->viewRight.y)
                                                        + (float)(p_gravityNormal->z * this->viewRight.z)))))
                        - (float)(p_ladderNormal->z
                                * (float)((float)(p_ladderNormal->x
                                                * (float)(this->viewRight.x
                                                        - (float)((float)x
                                                                * (float)((float)((float)x * this->viewRight.x)
                                                                        + (float)((float)(p_gravityNormal->y
                                                                                        * this->viewRight.y)
                                                                                + (float)(p_gravityNormal->z
                                                                                        * this->viewRight.z))))))
                                        + (float)((float)((float)(this->viewRight.z
                                                                - (float)((float)v17
                                                                        * (float)((float)((float)x * this->viewRight.x)
                                                                                + (float)((float)(p_gravityNormal->y
                                                                                                * this->viewRight.y)
                                                                                        + (float)(p_gravityNormal->z
                                                                                                * this->viewRight.z)))))
                                                        * p_ladderNormal->z)
                                                + (float)((float)(this->viewRight.y
                                                                - (float)((float)y
                                                                        * (float)((float)((float)x * this->viewRight.x)
                                                                                + (float)((float)(p_gravityNormal->y
                                                                                                * this->viewRight.y)
                                                                                        + (float)(p_gravityNormal->z
                                                                                                * this->viewRight.z)))))
                                                        * p_ladderNormal->y)))))
                * (float)v32);
    if ( (float)((float)(p_ladderNormal->z * (float)z)
               + (float)((float)(p_ladderNormal->x * (float)v16) + (float)(p_ladderNormal->y * (float)v15))) > 0.0 )
    {
      v33 = -v33;
      v34 = -v34;
      v35 = -v35;
    }
    LODWORD(v20) = (char)v20;
    *(_QWORD *)&v76.x = v20;
    v22 = (float)((float)((float)((float)((float)v33 * (float)2.0) * (float)v19) * (float)v20) + (float)v22);
    v23 = (float)((float)((float)((float)((float)v34 * (float)2.0) * (float)v19) * (float)v20) + (float)v23);
    v24 = (float)((float)((float)((float)((float)v35 * (float)2.0) * (float)v19) * (float)v20) + (float)v24);
  }
  if ( this->command.upmove != 0 )
  {
    LODWORD(v20) = this->command.upmove;
    *(_QWORD *)&v76.x = v20;
    v22 = (float)((float)((float)((float)((float)x * (float)-0.5) * (float)v19) * (float)v20) + (float)v22);
    v23 = (float)((float)((float)((float)((float)y * (float)-0.5) * (float)v19) * (float)v20) + (float)v23);
    v24 = (float)((float)((float)((float)((float)v17 * (float)-0.5) * (float)v19) * (float)v20) + (float)v24);
  }
  idPhysics_Player::Friction(this);
  walkAccelerate = this->walkAccelerate;
  v37 = (float)((float)((float)v23 * (float)v23)
              + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24)));
  _FP10 = (float)((float)((float)((float)v23 * (float)v23)
                        + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f8, f10, f11, f0 }
  v40 = __frsqrte(_FP8);
  v41 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40
                                                                                      * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24)))
                                                                                              * (float)0.5))
                                                                              * (float)v40)
                                                                      - (float)1.5)
                                                      * (float)v40)
                                              * (float)((float)((float)((float)v23 * (float)v23)
                                                              + (float)((float)((float)v22 * (float)v22)
                                                                      + (float)((float)v24 * (float)v24)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v40
                                                                              * (float)((float)((float)((float)v23 * (float)v23)
                                                                                              + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24)))
                                                                                      * (float)0.5))
                                                                      * (float)v40)
                                                              - (float)1.5)
                                              * (float)v40))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v40
                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                      + (float)((float)((float)v22 * (float)v22)
                                                                              + (float)((float)v24 * (float)v24)))
                                                              * (float)0.5))
                                              * (float)v40)
                                      - (float)1.5)
                      * (float)v40));
  v42 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v40) - (float)1.5)
                                                                                              * (float)v40)
                                                                                      * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v40) - (float)1.5)
                                                                                      * (float)v40))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v40
                                                                                              * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                      * (float)v40)
                                                                              - (float)1.5)
                                                              * (float)v40))
                                              * (float)((float)((float)((float)v23 * (float)v23)
                                                              + (float)((float)((float)v22 * (float)v22)
                                                                      + (float)((float)v24 * (float)v24)))
                                                      * (float)0.5))
                                      * (float)v41)
                              - (float)1.5)
              * (float)v41);
  v43 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v40) - (float)1.5) * (float)v40)
                                                                                              * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24))) * (float)0.5)) * (float)v40) - (float)1.5)
                                                                                              * (float)v40))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v40 * (float)((float)((float)((float)v23 * (float)v23) + (float)((float)((float)v22 * (float)v22) + (float)((float)v24 * (float)v24))) * (float)0.5))
                                                                                              * (float)v40)
                                                                                      - (float)1.5)
                                                                      * (float)v40))
                                                      * (float)((float)((float)((float)v23 * (float)v23)
                                                                      + (float)((float)((float)v22 * (float)v22)
                                                                              + (float)((float)v24 * (float)v24)))
                                                              * (float)0.5))
                                              * (float)v41)
                                      - (float)1.5)
                      * (float)v41)
              * (float)v22);
  v76.x = v43;
  v44 = (float)((float)v23 * (float)v42);
  v76.y = v44;
  v45 = (float)((float)v24 * (float)v42);
  v76.z = v45;
  idPhysics_Player::Accelerate(this, wishdir: &v76, wishspeed: (float)((float)v42 * (float)v37), accel: walkAccelerate);
  v46 = p_gravityNormal->x;
  v47 = p_gravityNormal->z;
  v48 = p_gravityNormal->y;
  v49 = (float)((float)((float)-v48 * p_velocity->y)
              + (float)((float)((float)-v47 * p_velocity->z) + (float)((float)-v46 * p_velocity->x)));
  if ( v49 >= -100.0 )
  {
    if ( v49 > 100.0 )
    {
      v52 = (float)((float)((float)((float)-v48 * p_velocity->y)
                          + (float)((float)((float)-v47 * p_velocity->z) + (float)((float)-v46 * p_velocity->x)))
                  - (float)100.0);
      v53 = p_velocity->y;
      v54 = p_velocity->z;
      p_velocity->x = (float)(p_gravityNormal->x
                            * (float)((float)((float)((float)-v48 * p_velocity->y)
                                            + (float)((float)((float)-v47 * p_velocity->z)
                                                    + (float)((float)-v46 * p_velocity->x)))
                                    - (float)100.0))
                    + p_velocity->x;
      p_velocity->y = (float)((float)v48 * (float)v52) + (float)v53;
      p_velocity->z = (float)((float)v47 * (float)v52) + (float)v54;
    }
  }
  else
  {
    v50 = p_velocity->z;
    v51 = p_velocity->y;
    p_velocity->x = (float)(p_gravityNormal->x
                          * (float)((float)((float)((float)-v48 * p_velocity->y)
                                          + (float)((float)((float)-v47 * p_velocity->z)
                                                  + (float)((float)-v46 * p_velocity->x)))
                                  + (float)100.0))
                  + p_velocity->x;
    p_velocity->y = (float)((float)v48 * (float)((float)v49 + (float)100.0)) + (float)v51;
    p_velocity->z = (float)((float)v47 * (float)((float)v49 + (float)100.0)) + (float)v50;
  }
  if ( (float)((float)(p_gravityNormal->x * (float)v43)
             + (float)((float)(p_gravityNormal->z * (float)v45) + (float)(p_gravityNormal->y * (float)v44))) == 0.0 )
  {
    v55 = p_velocity->z;
    v56 = this->gravityVector.y;
    frametime = this->frametime;
    if ( (float)((float)(p_gravityNormal->y * p_velocity->y)
               + (float)((float)(p_gravityNormal->z * p_velocity->z) + (float)(p_gravityNormal->x * p_velocity->x))) >= 0.0 )
    {
      v68 = (float)(this->gravityVector.z * this->frametime);
      v69 = p_velocity->y;
      v70 = (float)(p_velocity->x - (float)(this->gravityVector.x * this->frametime));
      p_velocity->x = p_velocity->x - (float)(this->gravityVector.x * this->frametime);
      v71 = (float)((float)v69 - (float)((float)v56 * (float)frametime));
      p_velocity->y = (float)v69 - (float)((float)v56 * (float)frametime);
      p_velocity->z = (float)v55 - (float)v68;
      v65 = v71;
      v64 = p_gravityNormal->z;
      v63 = p_gravityNormal->x;
      v67 = (float)((float)v55 - (float)v68);
      v62 = p_gravityNormal->y;
      v66 = (float)(p_gravityNormal->x * (float)v70);
      if ( (float)((float)((float)(p_gravityNormal->y * (float)v71)
                         + (float)(p_gravityNormal->z * (float)((float)v55 - (float)v68)))
                 + (float)(p_gravityNormal->x * (float)v70)) >= 0.0 )
        goto LABEL_20;
    }
    else
    {
      v58 = (float)(this->gravityVector.z * this->frametime);
      v59 = p_velocity->y;
      v60 = (float)((float)(this->gravityVector.x * this->frametime) + p_velocity->x);
      p_velocity->x = (float)(this->gravityVector.x * this->frametime) + p_velocity->x;
      v61 = (float)((float)((float)v56 * (float)frametime) + (float)v59);
      p_velocity->y = (float)((float)v56 * (float)frametime) + (float)v59;
      p_velocity->z = (float)v58 + (float)v55;
      v62 = p_gravityNormal->y;
      v63 = p_gravityNormal->x;
      v64 = p_gravityNormal->z;
      v65 = v61;
      v66 = (float)(p_gravityNormal->x * (float)v60);
      v67 = (float)((float)v58 + (float)v55);
      if ( (float)((float)((float)(p_gravityNormal->y * (float)v61)
                         + (float)(p_gravityNormal->z * (float)((float)v58 + (float)v55)))
                 + (float)(p_gravityNormal->x * (float)v60)) <= 0.0 )
        goto LABEL_20;
    }
    v72 = p_velocity->y;
    v73 = p_velocity->x;
    v74 = (float)((float)((float)((float)v65 * p_gravityNormal->y) + (float)((float)v67 * p_gravityNormal->z))
                + (float)v66);
    v75 = (float)((float)v62
                * (float)((float)((float)((float)v65 * p_gravityNormal->y) + (float)((float)v67 * p_gravityNormal->z))
                        + (float)v66));
    p_velocity->z = p_velocity->z
                  - (float)((float)v64
                          * (float)((float)((float)((float)v65 * p_gravityNormal->y)
                                          + (float)((float)v67 * p_gravityNormal->z))
                                  + (float)v66));
    p_velocity->y = (float)v72 - (float)v75;
    p_velocity->x = (float)v73 - (float)((float)v63 * (float)v74);
  }
LABEL_20:
  if ( g_pm_deferredSlideMove )
  {
    idPhysics_Player::SlideMoveDeferred(
      this,
      gravity: false,
      stepUp: (-this->command.forwardmove & ~this->command.forwardmove) < 0,
      stepDown: false,
      ignoreEntityNum: this->entityNumber);
  }
  else
  {
    idPhysics_Player::SlideMoveNonDeferred(
      this,
      gravity: false,
      stepUp: (-this->command.forwardmove & ~this->command.forwardmove) < 0,
      stepDown: false,
      push: false,
      ignoreEntityNum: this->entityNumber);
    idPhysics_Player::CheckGround(this);
  }
}


// ========================================================================
// ?ExplicitMove@idPhysics_Player@@AAAXAAUplayerExplicitMove_t@@@Z
// EA  : 0x82759C58
// RVA : 0x00759C58
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::ExplicitMove(idPhysics_Player *this, playerExplicitMove_t *move)
{
  idVec3 *p_velocity; // r30
  char v4; // r11
  double frametime; // fp0
  double y; // fp11
  double z; // fp10
  playerExplicitMove_t::velocityType_t velocityType; // r11
  double v9; // fp12
  double v10; // fp0
  idVec3 velocity; // [sp+50h] [-30h]

  p_velocity = &this->current.velocity;
  velocity = this->current.velocity;
  if ( move->delta.x != vec3_origin.x || move->delta.y != vec3_origin.y || (v4 = 1, move->delta.z != vec3_origin.z) )
    v4 = 0;
  if ( v4 == 0 )
  {
    frametime = this->frametime;
    if ( frametime != 0.0 )
    {
      y = move->delta.y;
      z = move->delta.z;
      p_velocity->x = move->delta.x * (float)((float)1.0 / this->frametime);
      this->current.velocity.y = (float)y * (float)((float)1.0 / (float)frametime);
      this->current.velocity.z = (float)z * (float)((float)1.0 / (float)frametime);
      idPhysics_Player::SlideMove(
        this,
        gravity: false,
        stepUp: true,
        stepDown: false,
        push: true,
        ignoreEntityNum: move->ignoreEntityNum);
      velocityType = move->velocityType;
      if ( velocityType == VEL_OVERRIDE )
      {
        p_velocity->x = move->overrideVelocity.x;
        p_velocity->y = move->overrideVelocity.y;
        v9 = move->overrideVelocity.z;
        goto LABEL_11;
      }
      if ( velocityType == VEL_CURRENT )
      {
        v9 = velocity.z;
        p_velocity->x = velocity.x;
        p_velocity->y = velocity.y;
LABEL_11:
        p_velocity->z = v9;
      }
    }
  }
  move->delta.x = vec3_origin.x;
  move->delta.y = vec3_origin.y;
  v10 = vec3_origin.z;
  move->clipMove = true;
  move->delta.z = v10;
  move->velocityType = VEL_EXPLICIT;
  move->overrideVelocity = vec3_origin;
  move->ignoreEntityNum = 0x1FFF;
}


// ========================================================================
// ?CheckDuck@idPhysics_Player@@AAAXXZ
// EA  : 0x82759DC0
// RVA : 0x00759DC0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::CheckDuck(idPhysics_Player *this)
{
  int v3; // r11
  bool v4; // cr57
  bool (__fastcall *ownerCrouchJumpHandler)(int, const idVec3 *, const idVec3 *, const idVec3 *, const idVec3 *, const usercmd_t *); // r11
  bool v6; // r30
  unsigned int upmove; // r11
  int movementFlags; // r11
  char v9; // r30
  int v10; // r11
  int v11; // r10
  idClipModel *clipModel_sprintSlide; // r11
  idClipModel *v13; // r8
  int v14; // r11
  int entityNumber; // r10
  double z; // fp12
  double x; // fp9
  double v18; // fp7
  double v19; // fp4
  int clipMask; // r10
  idClip *clip; // r4
  int v22; // [sp+8h] [-198h]
  bool v23; // [sp+Fh] [-191h]
  const char *v24; // [sp+10h] [-190h]
  int v25; // [sp+14h] [-18Ch]
  int v26; // [sp+18h] [-188h]
  int v27; // [sp+1Ch] [-184h]
  int v28; // [sp+20h] [-180h]
  int v29; // [sp+24h] [-17Ch]
  int v30; // [sp+28h] [-178h]
  int v31; // [sp+2Ch] [-174h]
  int v32; // [sp+30h] [-170h]
  int v33; // [sp+34h] [-16Ch]
  int v34; // [sp+38h] [-168h]
  int v35; // [sp+3Ch] [-164h]
  int v36; // [sp+40h] [-160h]
  int v37; // [sp+44h] [-15Ch]
  int v38; // [sp+48h] [-158h]
  int v39; // [sp+4Ch] [-154h]
  int v40; // [sp+50h] [-150h]
  int v41; // [sp+54h] [-14Ch]
  int v42; // [sp+58h] [-148h]
  int v43; // [sp+60h] [-140h]
  idVec3 v44; // [sp+70h] [-130h] BYREF
  idVec3 v45; // [sp+80h] [-120h] BYREF
  idVec3 v46; // [sp+90h] [-110h] BYREF
  idVec3 v47; // [sp+A0h] [-100h] BYREF
  idVec3 v48; // [sp+B0h] [-F0h] BYREF
  idVec3 v49; // [sp+C0h] [-E0h] BYREF
  idVec3 v50; // [sp+D0h] [-D0h] BYREF
  char v51; // [sp+E0h] [-C0h] BYREF
  trace_t v52; // [sp+F0h] [-B0h] BYREF

  if ( this->inhibitSprint && (this->command.buttons & 0x10) == 0 )
    this->inhibitSprint = false;
  if ( this->inhibitJump && this->command.upmove == 0 )
    this->inhibitJump = false;
  if ( this->current.movementType == PM_DEAD && pm_deadClipModel.valueInteger != 0 )
  {
    if ( pm_deadClipModel_mp.valueInteger == 0 || !common->IsMultiplayer(this: common) )
    {
      this->clipModels[0] = this->clipModel_dead;
      return;
    }
    goto LABEL_57;
  }
  if ( !this->forcedClientCrouchState )
  {
    if ( this->currentSwimDepthState != SWIMDEPTH_STATE_NONE
      || !this->walking && this->waterLevel >= (double)pm_waterlevel_eyes.valueFloat )
    {
      if ( (this->current.movementFlags & 1) != 0 )
        goto LABEL_37;
      goto LABEL_36;
    }
    if ( pm_crouchToggle.valueInteger == 0 )
    {
      upmove = (unsigned __int8)this->command.upmove;
      if ( (this->current.movementFlags & 1) != 0 )
      {
        if ( upmove >= 0x80 )
          goto LABEL_37;
      }
      else if ( upmove < 0x80 )
      {
        goto LABEL_37;
      }
      goto LABEL_36;
    }
    v3 = this->command.upmove;
    v4 = v3 > 0;
    if ( v3 < 0 )
    {
      if ( (unsigned __int8)this->prevcmd.upmove < 0x80u )
      {
LABEL_36:
        this->toggleCrouch = true;
        goto LABEL_37;
      }
      v4 = v3 > 0;
    }
    if ( v4 && (this->current.movementFlags & 1) != 0 )
    {
      ownerCrouchJumpHandler = this->ownerCrouchJumpHandler;
      this->toggleCrouch = true;
      if ( ownerCrouchJumpHandler != nullptr )
      {
        idAngles::ToVectors(this: &this->viewAngles, forward: &v45, right: &v50, up: &v47);
        v6 = this->ownerCrouchJumpHandler(
               a1: this->entityNumber,
               a2: &this->current.worldOrigin,
               a3: &v45,
               a4: &v50,
               a5: &v47,
               a6: &this->command);
      }
      else
      {
        v6 = common->IsClient(this: common);
      }
      if ( v6 )
        this->current.movementFlags |= 0x10u;
    }
LABEL_37:
    if ( !this->toggleCrouch )
    {
LABEL_48:
      this->toggleCrouch = false;
      goto LABEL_49;
    }
    movementFlags = this->current.movementFlags;
    v9 = 0;
    if ( (movementFlags & 1) != 0 )
    {
      if ( !idPhysics_Player::CanStand(this, pos: &this->current.worldOrigin) )
      {
LABEL_45:
        if ( v9 != 0 && this->ownerCrouchHandler != nullptr )
        {
          idAngles::ToVectors(this: &this->viewAngles, forward: &v49, right: &v48, up: &v46);
          this->ownerCrouchHandler(
            a1: this->entityNumber,
            a2: &this->current.worldOrigin,
            a3: &v49,
            a4: &v48,
            a5: &v46,
            a6: &this->command);
        }
        goto LABEL_48;
      }
      v10 = this->current.movementFlags;
      this->inhibitJump = true;
      this->current.movementFlags = v10 & 0xFFFFFFFE;
    }
    else
    {
      if ( this->ladder )
        goto LABEL_45;
      this->current.movementFlags = movementFlags | 1;
    }
    v9 = 1;
    goto LABEL_45;
  }
LABEL_49:
  v11 = this->current.movementFlags;
  if ( (v11 & 1) != 0 )
  {
    this->playerSpeed = this->crouchSpeed;
    if ( (v11 & 0x200) != 0 )
      clipModel_sprintSlide = this->clipModel_sprintSlide;
    else
      clipModel_sprintSlide = this->clipModel_crouched;
  }
  else
  {
    clipModel_sprintSlide = this->clipModel_standing;
  }
  v13 = this->clipModels[0];
  if ( clipModel_sprintSlide != v13 && v13 == this->clipModel_sprintSlide )
  {
    v14 = v11 | 1;
    entityNumber = this->entityNumber;
    this->current.movementFlags = v14;
    z = this->gravityNormal.z;
    x = this->current.worldOrigin.x;
    v18 = this->current.worldOrigin.z;
    v19 = (float)(this->gravityNormal.x * (float)(pm_normalheight.valueFloat - pm_crouchheight.valueFloat));
    v41 = entityNumber;
    clipMask = this->clipMask;
    clip = this->clip;
    v44.y = this->current.worldOrigin.y
          - (float)(this->gravityNormal.y * (float)(pm_normalheight.valueFloat - pm_crouchheight.valueFloat));
    v44.x = (float)x - (float)v19;
    v44.z = (float)v18 - (float)((float)z * (float)(pm_normalheight.valueFloat - pm_crouchheight.valueFloat));
    idClip::Translation(
      this: (idClip *)&v51,
      result: clip,
      a3: &v52,
      start: &this->current.worldOrigin,
      end: &v44,
      clipModel: v13,
      startAxis: &v13->axis,
      clipMask,
      passEntityNumber: v22,
      moveClipModel: v23,
      userName: v24,
      a12: v25,
      a13: v26,
      a14: v27,
      a15: v28,
      a16: v29,
      a17: v30,
      a18: v31,
      a19: v32,
      a20: v33,
      a21: v34,
      a22: v35,
      a23: v36,
      a24: v37,
      a25: v38,
      a26: v39,
      a27: v40,
      a28: v41,
      a29: v42,
      a30: false,
      a31: v43,
      a32: 0);
    if ( v52.fraction >= 1.0 )
    {
LABEL_57:
      this->clipModels[0] = this->clipModel_crouched;
      return;
    }
    clipModel_sprintSlide = this->clipModels[0];
  }
  this->clipModels[0] = clipModel_sprintSlide;
}


// ========================================================================
// ?ForcePhysicsQuery@idPhysics_Player@@QAAXXZ
// EA  : 0x8275A1C8
// RVA : 0x0075A1C8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::ForcePhysicsQuery(idPhysics_Player *this)
{
  if ( g_pm_deferredSlideMove )
  {
    idPhysics_Player::SlideMoveDeferred(
      this,
      gravity: true,
      stepUp: true,
      stepDown: true,
      ignoreEntityNum: this->entityNumber);
  }
  else
  {
    idPhysics_Player::SlideMoveNonDeferred(
      this,
      gravity: true,
      stepUp: true,
      stepDown: true,
      push: true,
      ignoreEntityNum: this->entityNumber);
    idPhysics_Player::CheckGround(this);
  }
}


// ========================================================================
// ?ClearCrouch@idPhysics_Player@@QAAXXZ
// EA  : 0x8275A240
// RVA : 0x0075A240
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::ClearCrouch(idPhysics_Player *this)
{
  idClipModel *v2; // r30
  idClipModel *v3; // r3

  v2 = this->clipModels[0];
  this->current.movementFlags &= ~1u;
  idPhysics_Player::CheckDuck(this);
  v3 = this->clipModels[0];
  if ( v3 != nullptr && v3 != v2 )
    idClipModel::Link(
      this: v3,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &v3->axis);
}


// ========================================================================
// ?SetCrouch@idPhysics_Player@@QAAX_N@Z
// EA  : 0x8275A2B0
// RVA : 0x0075A2B0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::SetCrouch(idPhysics_Player *this, bool crouch)
{
  idClipModel *v3; // r30
  idClipModel *v4; // r3

  if ( !crouch )
    goto LABEL_4;
  if ( (this->current.movementFlags & 1) != 0 )
  {
    if ( crouch )
      return;
LABEL_4:
    if ( (this->current.movementFlags & 1) == 0 )
      return;
  }
  v3 = this->clipModels[0];
  this->toggleCrouch = true;
  idPhysics_Player::CheckDuck(this);
  v4 = this->clipModels[0];
  if ( v4 != nullptr && v4 != v3 )
    idClipModel::Link(
      this: v4,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &v4->axis);
}


// ========================================================================
// ?ResolveSlideMove@idPhysics_Player@@AAAXXZ
// EA  : 0x8275A358
// RVA : 0x0075A358
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::ResolveSlideMove(idPhysics_Player *this)
{
  idClip *clip; // r29
  idClipQuery *p_slideMoveQuery; // r30
  __int128 v4; // r11
  double y; // fp12
  double z; // fp11
  double v7; // fp12
  double v8; // fp10
  double v9; // fp9
  double separation; // fp0
  int v11; // r10
  double stepUp; // fp13
  int v13; // r29
  contactInfo_t *contacts; // r30
  trace_t v15; // [sp+50h] [-450h] BYREF
  contactsResult_t v16; // [sp+D0h] [-3D0h] BYREF

  clip = this->clip;
  p_slideMoveQuery = &this->slideMoveQuery;
  if ( (unsigned __int8)idClip::QueryIsValid(this: clip, clipQuery: &this->slideMoveQuery) == 0 )
    return;
  LODWORD(v4) = 0;
  *(idClipQuery *)((char *)&v4 + 4) = (idClipQuery)p_slideMoveQuery->index;
  p_slideMoveQuery->index = v4;
  idCollisionModelManager::GetStepMoveContactsResult(
    this: collisionModelManager,
    result: &v15,
    contacts: &v16,
    query: &clip->collisionQueries[WORD5(v4) & 0xFFF].query,
    peek: false);
  y = v15.endpos.y;
  z = v15.endpos.z;
  this->current.worldOrigin.x = v15.endpos.x;
  this->current.worldOrigin.y = y;
  this->current.worldOrigin.z = z;
  if ( (this->current.movementFlags & 0x100) == 0 )
  {
    v7 = (float)((float)1.0 / this->frametime);
    v8 = v15.c.normal.y;
    v9 = v15.c.normal.z;
    this->current.velocity.x = v15.c.normal.x * (float)((float)1.0 / this->frametime);
    this->current.velocity.y = (float)v8 * (float)v7;
    this->current.velocity.z = (float)v9 * (float)v7;
  }
  separation = v15.c.separation;
  if ( v15.c.separation > 1.0 )
  {
    v11 = this->current.movementFlags | 4;
LABEL_8:
    stepUp = this->current.stepUp;
    this->current.movementFlags = v11;
    this->current.stepUp = (float)stepUp + (float)separation;
    goto LABEL_9;
  }
  if ( separation < -1.0 )
  {
    v11 = this->current.movementFlags | 8;
    goto LABEL_8;
  }
LABEL_9:
  if ( v15.c.type != CONTACT_NONE )
    this->callbacks->Collide(this: this->callbacks, a2: this->physicsId, a3: &v15, a4: &this->current.velocity);
  this->ClearContacts(this);
  v13 = 0;
  if ( v16.numContacts > 0 )
  {
    contacts = v16.contacts;
    do
    {
      idList<contactInfo_t,77>::Append(this: &this->contacts, obj: contacts);
      ++v13;
      ++contacts;
    }
    while ( v13 < v16.numContacts );
  }
  idPhysics_DynamicBase::AddContactPhysicsForContacts(this);
}


// ========================================================================
// ?MovePlayer@idPhysics_Player@@AAAXH@Z
// EA  : 0x8275A4F0
// RVA : 0x0075A4F0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::MovePlayer(idPhysics_Player *this, int msec)
{
  int v4; // r11
  double z; // fp10
  idPhysics_Player_vtbl *v6; // r4
  bool ladder; // r28
  bool v8; // r3
  __int64 v9; // r10
  int movementFlags; // r8
  char upmove; // r7
  double walkSpeed; // fp10
  __int64 v13; // r6
  int v14; // r4
  double v15; // fp13
  double v16; // fp9
  double y; // fp8
  double v18; // fp7
  double v19; // fp5
  double v20; // fp6
  double v21; // fp4
  double v22; // fp3
  double v23; // fp9
  double v24; // fp13
  double v25; // fp11
  double v26; // fp7
  double v27; // fp6
  double v28; // fp5
  double v29; // fp4
  double v30; // fp3
  double v31; // fp2
  double v32; // fp10
  double v33; // fp8
  double v36; // fp6
  double v37; // fp4
  double v38; // fp11
  double v39; // fp8
  double v40; // fp6
  pmtype_t movementType; // r11
  int movementTime; // r11
  int framemsec; // r10
  int v44; // r11
  int v45; // r11
  __int64 v46; // r6
  int v47; // r4
  int v48; // r11
  int v49; // r10
  int v50; // r11
  pmtype_t v51; // r11
  double waterLevel; // fp0
  float v53; // r10
  float v54; // r9
  idPhysics_Player_vtbl *v55; // r8
  int v56; // r30
  double v57; // fp1
  void (__fastcall *SetOrigin)(struct idPhysics_Player *, const idVec3 *, int); // ctr
  float x; // r10
  float v60; // r8
  float v61; // r7
  idPhysics_Player_vtbl *v62; // r6
  double valueFloat; // fp31
  int v64; // r30
  double v65; // fp1
  idPhysics_Player_vtbl *v66; // r10
  __int64 v67; // [sp+50h] [-40h] BYREF
  float v68; // [sp+58h] [-38h]

  this->previous = this->current;
  g_pm_deferredSlideMove = session->GetTitleStorageBool_2(
                             this: session,
                             a2: "pm_deferredSlideMove",
                             a3: pm_deferredSlideMove.valueInteger != 0);
  g_pm_deferredSlideMoveAccelScale = session->GetTitleStorageFloat_2(
                                       this: session,
                                       a2: "pm_deferredSlideMoveAccelScale",
                                       a3: pm_deferredSlideMoveAccelScale.valueFloat);
  v4 = c_pmove;
  this->previous.localOrigin.x = this->current.localOrigin.x;
  this->previous.localOrigin.y = this->current.localOrigin.y;
  z = this->current.localOrigin.z;
  c_pmove = v4 + 1;
  this->previous.localOrigin.z = z;
  this->previous.worldOrigin = this->current.worldOrigin;
  this->previous.velocity = this->current.velocity;
  this->previous.pushVelocity = this->current.pushVelocity;
  this->previous.deltaViewAngles = this->current.deltaViewAngles;
  this->previous.stepUp = this->current.stepUp;
  this->previous.movementType = this->current.movementType;
  this->previous.movementFlags = this->current.movementFlags;
  this->previous.movementTime = this->current.movementTime;
  v6 = this->__vftable;
  ladder = this->ladder;
  this->walking = false;
  this->groundPlane = false;
  this->ladder = false;
  v8 = v6->HasGroundContacts(this);
  LODWORD(v9) = msec;
  v67 = v9;
  movementFlags = this->current.movementFlags;
  upmove = this->command.upmove;
  this->startedOnGround = v8;
  this->framemsec = msec;
  walkSpeed = this->walkSpeed;
  this->current.movementFlags = movementFlags & 0xFFFFFFF1;
  this->playerSpeed = walkSpeed;
  this->frametime = (float)v67 * (float)0.001;
  this->current.stepUp = 0.0;
  if ( upmove < 10 )
    this->current.movementFlags = movementFlags & 0xFFFFFFE1;
  if ( this->current.movementType != PM_FREEZE )
  {
    idPhysics_Player::ResolveSlideMove(this);
    if ( this->clientOriginSet )
    {
      this->clientOriginSet = false;
      this->current.worldOrigin.x = this->nextClientOrigin.x;
      this->current.worldOrigin.y = this->nextClientOrigin.y;
      this->current.worldOrigin.z = this->nextClientOrigin.z;
      idClipModel::Link(
        this: this->clipModels[0],
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: 0,
        newOrigin: &this->current.worldOrigin,
        newAxis: &this->clipModels[0]->axis);
    }
    idAngles::ToVectors(this: &this->viewAngles, forward: &this->viewForward, right: nullptr, up: nullptr);
    v15 = this->viewForward.z;
    v16 = (float)((float)(this->clipModelAxis.mat[0].y * this->viewForward.x)
                + (float)(this->clipModelAxis.mat[1].y * this->viewForward.y));
    y = this->clipModelAxis.mat[2].y;
    v18 = (float)((float)(this->clipModelAxis.mat[0].z * this->viewForward.x)
                + (float)(this->clipModelAxis.mat[1].z * this->viewForward.y));
    v19 = this->clipModelAxis.mat[2].z;
    v20 = (float)((float)(this->viewForward.x * this->clipModelAxis.mat[0].x)
                + (float)((float)(this->clipModelAxis.mat[1].x * this->viewForward.y)
                        + (float)(this->clipModelAxis.mat[2].x * this->viewForward.z)));
    this->viewForward.x = (float)(this->viewForward.x * this->clipModelAxis.mat[0].x)
                        + (float)((float)(this->clipModelAxis.mat[1].x * this->viewForward.y)
                                + (float)(this->clipModelAxis.mat[2].x * this->viewForward.z));
    v21 = (float)((float)((float)y * (float)v15) + (float)v16);
    this->viewForward.y = (float)((float)y * (float)v15) + (float)v16;
    v22 = (float)((float)((float)v19 * (float)v15) + (float)v18);
    this->viewForward.z = (float)((float)v19 * (float)v15) + (float)v18;
    v23 = this->gravityNormal.y;
    v24 = v20;
    v25 = this->gravityNormal.z;
    v26 = (float)((float)v21 * this->gravityNormal.z);
    v28 = (float)((float)((float)v21 * this->gravityNormal.x) - (float)((float)v20 * this->gravityNormal.y));
    v27 = (float)((float)v22 * this->gravityNormal.x);
    this->viewRight.z = v28;
    v29 = (float)((float)((float)v22 * (float)v23) - (float)v26);
    this->viewRight.x = (float)((float)v22 * (float)v23) - (float)v26;
    this->viewRight.y = (float)((float)v24 * (float)v25) - (float)v27;
    v31 = v28;
    v32 = v29;
    v30 = (float)((float)((float)v24 * (float)v25) - (float)v27);
    v33 = (float)((float)((float)v28 * (float)v28)
                + (float)((float)((float)v29 * (float)v29) + (float)((float)v30 * (float)v30)));
    _FP7 = (float)((float)((float)((float)v28 * (float)v28)
                         + (float)((float)((float)v29 * (float)v29) + (float)((float)v30 * (float)v30)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f7, f8, f13 }
    v36 = (float)((float)v33 * (float)0.5);
    v37 = __frsqrte(_FP5);
    v38 = (float)((float)-(float)((float)((float)((float)v37 * (float)((float)v33 * (float)0.5)) * (float)v37)
                                - (float)1.5)
                * (float)v37);
    v39 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v37
                                                                                * (float)((float)v33 * (float)0.5))
                                                                        * (float)v37)
                                                                - (float)1.5)
                                                * (float)v37)
                                        * (float)((float)v33 * (float)0.5))
                                * (float)((float)-(float)((float)((float)((float)v37 * (float)((float)v33 * (float)0.5))
                                                                * (float)v37)
                                                        - (float)1.5)
                                        * (float)v37))
                        - (float)1.5);
    v40 = (float)((float)((float)v39 * (float)v38) * (float)v36);
    this->viewRight.y = (float)v30
                      * (float)((float)-(float)((float)((float)v40 * (float)((float)v39 * (float)v38)) - (float)1.5)
                              * (float)((float)v39 * (float)v38));
    this->viewRight.x = (float)v32
                      * (float)((float)-(float)((float)((float)v40 * (float)((float)v39 * (float)v38)) - (float)1.5)
                              * (float)((float)v39 * (float)v38));
    this->viewRight.z = (float)v31
                      * (float)((float)-(float)((float)((float)v40 * (float)((float)v39 * (float)v38)) - (float)1.5)
                              * (float)((float)v39 * (float)v38));
    movementType = this->current.movementType;
    if ( movementType == PM_SPECTATOR )
    {
      idPhysics_Player::SpectatorMove(this);
      movementTime = this->current.movementTime;
      if ( movementTime == 0 )
        return;
      framemsec = this->framemsec;
      if ( framemsec >= movementTime )
      {
        v44 = this->current.movementFlags;
        this->current.movementTime = 0;
        this->current.movementFlags = v44 & 0xFFFFF31F;
        return;
      }
      goto LABEL_10;
    }
    if ( movementType == PM_NOCLIP )
    {
      idPhysics_Player::NoclipMove(this, a2: v14, a3: v13);
      movementTime = this->current.movementTime;
      if ( movementTime != 0 )
      {
        framemsec = this->framemsec;
        if ( framemsec < movementTime )
        {
LABEL_10:
          this->current.movementTime = movementTime - framemsec;
          return;
        }
        v45 = this->current.movementFlags;
        this->current.movementTime = 0;
        this->current.movementFlags = v45 & 0xFFFFF31F;
      }
    }
    else
    {
      if ( movementType == PM_DEAD )
        usercmd_t::ClearMoveCmds(this: &this->command);
      idPhysics_Player::CheckGround(this);
      idPhysics_Player::CheckLadder(this, oldLadder: ladder);
      idPhysics_Player::CheckDuck(this);
      v48 = this->current.movementTime;
      if ( v48 != 0 )
      {
        v49 = this->framemsec;
        if ( v49 < v48 )
        {
          this->current.movementTime = v48 - v49;
        }
        else
        {
          v50 = this->current.movementFlags;
          this->current.movementTime = 0;
          this->current.movementFlags = v50 & 0xFFFFF31F;
        }
      }
      v51 = this->current.movementType;
      switch ( v51 )
      {
        case PM_DEAD:
          this->externalVelocity = vec3_origin;
          idPhysics_Player::DeadMove(this);
          break;
        case PM_EXPLICIT:
          idPhysics_Player::ExplicitMove(this, move: &this->explicitMove);
          break;
        case PM_PERFECTORIGIN:
          this->externalVelocity = vec3_origin;
          idPhysics_Player::PerfectOriginMove(this, deltaMS: msec);
          break;
        default:
          if ( this->ladder )
          {
            this->externalVelocity = vec3_origin;
            idPhysics_Player::LadderMove(this, a2: v47, a3: v46);
          }
          else if ( (this->current.movementFlags & 0x80) != 0 )
          {
            this->externalVelocity = vec3_origin;
            idPhysics_Player::WaterJumpMove(this);
          }
          else if ( this->currentSwimDepthState != SWIMDEPTH_STATE_NONE )
          {
            this->externalVelocity = vec3_origin;
            waterLevel = this->waterLevel;
            if ( waterLevel >= pm_waterlevel_waist.valueFloat )
            {
              if ( waterLevel > (float)(pm_waterlevel_shoulders.valueFloat + (float)0.1)
                && this->currentSwimDepthState == SWIMDEPTH_STATE_ON_SURFACE )
              {
                v53 = this->current.worldOrigin.y;
                v54 = this->current.worldOrigin.z;
                v55 = this->__vftable;
                *(float *)&v67 = this->current.worldOrigin.x;
                *((float *)&v67 + 1) = v53;
                v68 = v54;
                v56 = (int)v55->GetBounds(this, a2: -1);
                v57 = ((double (__fastcall *)(idPhysics_Player *))this->GetWaterSurfaceWrldHeight)(a1: this);
                SetOrigin = this->SetOrigin;
                v68 = (float)v57 - (float)(*(float *)(v56 + 20) + (float)1.0);
                SetOrigin(this, a2: (const idVec3 *)&v67, a3: -1);
                this->currentSwimDepthState = SWIMDEPTH_STATE_UNDER_SURFACE;
              }
              else if ( waterLevel < pm_waterlevel_head.valueFloat
                     && this->currentSwimDepthState == SWIMDEPTH_STATE_UNDER_SURFACE )
              {
                x = this->current.worldOrigin.x;
                v60 = this->current.worldOrigin.y;
                v61 = this->current.worldOrigin.z;
                this->currentSwimDepthState = SWIMDEPTH_STATE_ON_SURFACE;
                v62 = this->__vftable;
                *(float *)&v67 = x;
                *((float *)&v67 + 1) = v60;
                v68 = v61;
                valueFloat = pm_waterlevel_shoulders.valueFloat;
                v64 = (int)v62->GetBounds(this, a2: -1);
                v65 = ((double (__fastcall *)(idPhysics_Player *))this->GetWaterSurfaceWrldHeight)(a1: this);
                v66 = this->__vftable;
                v68 = -(float)((float)(*(float *)(v64 + 20) * (float)valueFloat) - (float)v65);
                v66->SetOrigin(this, a2: (const idVec3 *)&v67, a3: -1);
              }
              else
              {
                idPhysics_Player::SwimMove(this);
              }
            }
            else
            {
              this->currentSwimDepthState = SWIMDEPTH_STATE_NONE;
            }
          }
          else if ( this->waterLevel <= (double)pm_waterlevel_waist.valueFloat )
          {
            if ( this->walking )
            {
              idPhysics_Player::WalkMove(this);
            }
            else
            {
              if ( this->lastJumpChance > 0 )
              {
                if ( (unsigned __int8)idPhysics_Player::CheckJump(this) != 0 )
                  this->lastJumpChance = 0;
                else
                  this->lastJumpChance -= this->framemsec;
              }
              idPhysics_Player::AirMove(this);
            }
          }
          else
          {
            this->externalVelocity = vec3_origin;
            if ( this->startedOnGround || this->current.velocity.z >= (double)SWIMMING_MIN_DIVESPEED )
              this->currentSwimDepthState = SWIMDEPTH_STATE_ON_SURFACE;
            else
              this->currentSwimDepthState = SWIMDEPTH_STATE_UNDER_SURFACE;
          }
          break;
      }
      idPhysics_Player::UpdateExternalVelocity(this);
      ((void (*)(void))this->ClearPushedVelocity)();
      this->current.movementFlags &= ~0x100u;
    }
  }
}


// ========================================================================
// ?Evaluate@idPhysics_Player@@UAA_NHH@Z
// EA  : 0x8275ADA8
// RVA : 0x0075ADA8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

int __fastcall idPhysics_Player::Evaluate(idPhysics_Player *this, unsigned int timeStepMSec, int endTimeMSec)
{
  double v5; // fp9
  double v6; // fp5
  double v7; // fp2
  double v8; // fp1
  idClipModel *v9; // r3
  double v10; // fp2
  double v11; // fp1
  double v12; // fp1
  double v13; // fp7
  idClipModel *clipModel_dead; // r3
  float x; // [sp+58h] [-78h]
  float y; // [sp+5Ch] [-74h]
  float z; // [sp+60h] [-70h]
  float v19[6]; // [sp+68h] [-68h] BYREF
  idVec3 v20; // [sp+80h] [-50h] BYREF
  float v21; // [sp+8Ch] [-44h]
  float v22; // [sp+90h] [-40h]
  float v23; // [sp+94h] [-3Ch]
  float v24; // [sp+98h] [-38h]
  float v25; // [sp+9Ch] [-34h]
  float v26; // [sp+A0h] [-30h]

  idPhysics_Actor::RememberHistorySample(this);
  idClipModel::Unlink(this: this->clipModels[0]);
  if ( this->hasMaster )
  {
    x = this->current.worldOrigin.x;
    y = this->current.worldOrigin.y;
    z = this->current.worldOrigin.z;
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)v19, a3: (idMat3 *)&v20);
    v5 = v19[1];
    v6 = v19[2];
    v7 = (float)((float)(this->current.localOrigin.y * v22)
               + (float)((float)(this->current.localOrigin.x * v20.y) + (float)(this->current.localOrigin.z * v25)));
    v8 = (float)((float)(this->current.localOrigin.y * v23)
               + (float)((float)(this->current.localOrigin.x * v20.z) + (float)(this->current.localOrigin.z * v26)));
    this->current.worldOrigin.x = (float)((float)(this->current.localOrigin.x * v20.x)
                                        + (float)((float)(this->current.localOrigin.z * v24)
                                                + (float)(this->current.localOrigin.y * v21)))
                                + v19[0];
    this->current.worldOrigin.y = (float)v5 + (float)v7;
    this->current.worldOrigin.z = (float)v6 + (float)v8;
    v9 = this->clipModels[0];
    if ( this->current.movementType == PM_VEHICLE_NOCLIP )
    {
      idClipModel::Unlink(this: v9);
      idClipModel::SetLinkedPosition(
        this: this->clipModels[0],
        newOrigin: &this->current.worldOrigin,
        newAxis: &this->clipModels[0]->axis);
    }
    else
    {
      idClipModel::Link(
        this: v9,
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: 0,
        newOrigin: &this->current.worldOrigin,
        newAxis: &v9->axis);
    }
    v10 = (float)(this->current.worldOrigin.y - y);
    v11 = (float)(this->current.worldOrigin.z - z);
    this->current.velocity.x = (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&off_82040000, timeStepMSec) * (float)0.001))
                             * (float)(this->current.worldOrigin.x - x);
    this->current.velocity.y = (float)v10
                             * (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&off_82040000, timeStepMSec) * (float)0.001));
    this->current.velocity.z = (float)v11
                             * (float)((float)1.0
                                     / (float)((float)__SPAIR64__(&off_82040000, timeStepMSec) * (float)0.001));
    this->masterDeltaYaw = this->masterYaw;
    v12 = idVec3::ToYaw(this: &v20);
    v13 = (float)((float)v12 - this->masterDeltaYaw);
    this->masterYaw = v12;
    this->masterDeltaYaw = v13;
    return 1;
  }
  else
  {
    this->ActivateContactPhysics(this);
    idPhysics_Player::MovePlayer(this, msec: timeStepMSec);
    idClipModel::Link(
      this: this->clipModels[0],
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &this->current.worldOrigin,
      newAxis: &this->clipModels[0]->axis);
    if ( common->IsMultiplayer(this: common) && pm_deadClipModel_mp.valueInteger != 0 )
    {
      clipModel_dead = this->clipModel_dead;
      if ( this->current.movementType == PM_DEAD )
      {
        idClipModel::Link(
          this: clipModel_dead,
          newEntityNumber: this->entityNumber,
          newPhysicsId: this->physicsId,
          newBodyId: 0,
          newOrigin: &this->current.worldOrigin,
          newAxis: &this->clipModels[0]->axis);
        return 1;
      }
      if ( clipModel_dead->clipLinks != nullptr )
        idClipModel::Unlink(this: clipModel_dead);
    }
    return 1;
  }
}


// ========================================================================
// ?Translate@idPhysics_Player@@UAAXABVidVec3@@H@Z
// EA  : 0x8275B028
// RVA : 0x0075B028
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::Translate(idPhysics_Player *this, const idVec3 *translation, int id)
{
  double y; // fp5
  double z; // fp4

  idPhysics_Player::ResolveSlideMove(this);
  this->current.localOrigin.x = this->current.localOrigin.x + translation->x;
  this->current.localOrigin.y = translation->y + this->current.localOrigin.y;
  this->current.localOrigin.z = translation->z + this->current.localOrigin.z;
  y = this->current.worldOrigin.y;
  z = this->current.worldOrigin.z;
  this->current.worldOrigin.x = translation->x + this->current.worldOrigin.x;
  this->current.worldOrigin.y = translation->y + (float)y;
  this->current.worldOrigin.z = (float)z + translation->z;
  idClipModel::Link(
    this: this->clipModels[0],
    newEntityNumber: this->entityNumber,
    newPhysicsId: this->physicsId,
    newBodyId: 0,
    newOrigin: &this->current.worldOrigin,
    newAxis: &this->clipModels[0]->axis);
}


// ========================================================================
// ?Rotate@idPhysics_Player@@UAAXABVidRotation@@H@Z
// EA  : 0x8275B0E0
// RVA : 0x0075B0E0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __fastcall idPhysics_Player::Rotate(idPhysics_Player *this, idRotation *rotation, int id)
{
  idVec3 *p_worldOrigin; // r30
  double v6; // fp2
  double z; // fp11
  double v8; // fp7
  double v9; // fp4
  double v10; // fp3
  idRotation *v11; // r3
  int physicsId; // r28
  int entityNumber; // r27
  idMat3 *p_axis; // r29
  const idMat3 *v15; // r3
  const idMat3 *v16; // r3
  float v17; // [sp+50h] [-B0h] BYREF
  float v18; // [sp+54h] [-ACh]
  float v19; // [sp+58h] [-A8h]
  idRotation v20[2]; // [sp+60h] [-A0h] BYREF

  p_worldOrigin = &this->current.worldOrigin;
  idPhysics_Player::ResolveSlideMove(this);
  this->current.worldOrigin = idRotation::operator*(this: v20, result: rotation, v: &this->current.worldOrigin)->origin;
  if ( this->hasMaster )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v17, a3: (idMat3 *)&v20[0].vec.y);
    v6 = (float)(this->current.worldOrigin.z - v19);
    z = v20[0].axis.mat[0].z;
    v8 = v20[0].axis.mat[1].z;
    v9 = (float)((float)(v20[0].axis.mat[0].y * (float)(this->current.worldOrigin.y - v18))
               + (float)(v20[0].axis.mat[0].x * (float)(this->current.worldOrigin.x - v17)));
    v10 = (float)((float)(v20[0].axis.mat[1].x * (float)(this->current.worldOrigin.x - v17))
                + (float)(v20[0].axis.mat[1].y * (float)(this->current.worldOrigin.y - v18)));
    this->current.localOrigin.x = (float)(v20[0].angle * (float)(this->current.worldOrigin.z - v19))
                                + (float)((float)(v20[0].vec.z * (float)(this->current.worldOrigin.y - v18))
                                        + (float)(v20[0].vec.y * (float)(this->current.worldOrigin.x - v17)));
    this->current.localOrigin.y = (float)((float)z * (float)v6) + (float)v9;
    this->current.localOrigin.z = (float)((float)v8 * (float)v6) + (float)v10;
  }
  else
  {
    this->current.localOrigin.x = p_worldOrigin->x;
    this->current.localOrigin.y = this->current.worldOrigin.y;
    this->current.localOrigin.z = this->current.worldOrigin.z;
  }
  v11 = rotation;
  physicsId = this->physicsId;
  entityNumber = this->entityNumber;
  p_axis = &this->clipModels[0]->axis;
  v15 = idRotation::ToMat3(this: v11);
  v16 = idMat3::operator*(this: (idMat3 *)&v20[0].axisValid, result: p_axis, a: v15);
  idClipModel::Link(
    this: this->clipModels[0],
    newEntityNumber: entityNumber,
    newPhysicsId: physicsId,
    newBodyId: 0,
    newOrigin: &this->current.worldOrigin,
    newAxis: v16);
}


// ========================================================================
// `dynamic initializer for 'pm_bboxwidth''
// EA  : 0x83340EC0
// RVA : 0x01340EC0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bboxwidth__()
{
  idCVar::idCVar(
    this: &pm_bboxwidth,
    name: "pm_bboxwidth",
    value: "32",
    flags: 4,
    description: "x/y size of player's bounding box",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bboxwidth__);
}


// ========================================================================
// `dynamic initializer for 'pm_usecylinder''
// EA  : 0x83340F18
// RVA : 0x01340F18
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_usecylinder__()
{
  idCVar::idCVar(
    this: &pm_usecylinder,
    name: "pm_usecylinder",
    value: "1",
    flags: 1,
    description: "use a cylinder approximation instead of a bounding box for player collision detection",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_usecylinder__);
}


// ========================================================================
// `dynamic initializer for 'pm_crouchheight''
// EA  : 0x83340F70
// RVA : 0x01340F70
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_crouchheight__()
{
  idCVar::idCVar(
    this: &pm_crouchheight,
    name: "pm_crouchheight",
    value: "60",
    flags: 4,
    description: "height of player's bounding box while crouched",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_crouchheight__);
}


// ========================================================================
// `dynamic initializer for 'pm_sprintslideheight''
// EA  : 0x83340FC8
// RVA : 0x01340FC8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_sprintslideheight__()
{
  idCVar::idCVar(
    this: &pm_sprintslideheight,
    name: "pm_sprintslideheight",
    value: "40",
    flags: 4,
    description: "height of player's bounding box while sprintsliding",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_sprintslideheight__);
}


// ========================================================================
// `dynamic initializer for 'pm_normalheight''
// EA  : 0x83341020
// RVA : 0x01341020
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_normalheight__()
{
  idCVar::idCVar(
    this: &pm_normalheight,
    name: "pm_normalheight",
    value: "90",
    flags: 4,
    description: "height of player's bounding box while standing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_normalheight__);
}


// ========================================================================
// `dynamic initializer for 'pm_deadheight''
// EA  : 0x83341078
// RVA : 0x01341078
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_deadheight__()
{
  idCVar::idCVar(
    this: &pm_deadheight,
    name: "pm_deadheight",
    value: "20",
    flags: 4,
    description: "height of player's bounding box while dead",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_deadheight__);
}


// ========================================================================
// `dynamic initializer for 'pm_crouchToggle''
// EA  : 0x833410D0
// RVA : 0x013410D0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_crouchToggle__()
{
  idCVar::idCVar(
    this: &pm_crouchToggle,
    name: "pm_crouchToggle",
    value: "1",
    flags: 1,
    description: "crouch works as a toggle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_crouchToggle__);
}


// ========================================================================
// `dynamic initializer for 'pm_deadClipModel''
// EA  : 0x83341128
// RVA : 0x01341128
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_deadClipModel__()
{
  idCVar::idCVar(
    this: &pm_deadClipModel,
    name: "pm_deadClipModel",
    value: "1",
    flags: 1,
    description: "Use clipModel_dead when player is dead",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_deadClipModel__);
}


// ========================================================================
// `dynamic initializer for 'pm_deadClipModel_mp''
// EA  : 0x83341180
// RVA : 0x01341180
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_deadClipModel_mp__()
{
  idCVar::idCVar(
    this: &pm_deadClipModel_mp,
    name: "pm_deadClipModel_mp",
    value: "1",
    flags: 1,
    description: "Uses clipModel_dead in MP but treats it as a second clipmodel for player focus instead of replacing the physics default clip model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_deadClipModel_mp__);
}


// ========================================================================
// `dynamic initializer for 'pm_deferredSlideMove''
// EA  : 0x833411D8
// RVA : 0x013411D8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_deferredSlideMove__()
{
  idCVar::idCVar(
    this: &pm_deferredSlideMove,
    name: "pm_deferredSlideMove",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_deferredSlideMove__);
}


// ========================================================================
// `dynamic initializer for 'pm_deferredSlideMoveAccelScale''
// EA  : 0x83341230
// RVA : 0x01341230
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_deferredSlideMoveAccelScale__()
{
  idCVar::idCVar(
    this: &pm_deferredSlideMoveAccelScale,
    name: "pm_deferredSlideMoveAccelScale",
    value: "1.3",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_deferredSlideMoveAccelScale__);
}


// ========================================================================
// `dynamic initializer for 'pm_externalVelocityAirScale''
// EA  : 0x83341288
// RVA : 0x01341288
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_externalVelocityAirScale__()
{
  idCVar::idCVar(
    this: &pm_externalVelocityAirScale,
    name: "pm_externalVelocityAirScale",
    value: "0.1",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_externalVelocityAirScale__);
}


// ========================================================================
// `dynamic initializer for 'pm_waterlevel_knees''
// EA  : 0x833412E0
// RVA : 0x013412E0
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_waterlevel_knees__()
{
  idCVar::idCVar(
    this: &pm_waterlevel_knees,
    name: "pm_waterlevel_knees",
    value: "0.2",
    flags: 4,
    description: "Waterlevel for knees",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_waterlevel_knees__);
}


// ========================================================================
// `dynamic initializer for 'pm_waterlevel_waist''
// EA  : 0x83341338
// RVA : 0x01341338
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_waterlevel_waist__()
{
  idCVar::idCVar(
    this: &pm_waterlevel_waist,
    name: "pm_waterlevel_waist",
    value: "0.4",
    flags: 4,
    description: "Waterlevel for waist",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_waterlevel_waist__);
}


// ========================================================================
// `dynamic initializer for 'pm_waterlevel_shoulders''
// EA  : 0x83341390
// RVA : 0x01341390
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_waterlevel_shoulders__()
{
  idCVar::idCVar(
    this: &pm_waterlevel_shoulders,
    name: "pm_waterlevel_shoulders",
    value: "0.71",
    flags: 4,
    description: "Waterlevel for shoulders",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_waterlevel_shoulders__);
}


// ========================================================================
// `dynamic initializer for 'pm_waterlevel_eyes''
// EA  : 0x833413E8
// RVA : 0x013413E8
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_waterlevel_eyes__()
{
  idCVar::idCVar(
    this: &pm_waterlevel_eyes,
    name: "pm_waterlevel_eyes",
    value: "0.95",
    flags: 4,
    description: "Waterlevel for eyes",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_waterlevel_eyes__);
}


// ========================================================================
// `dynamic initializer for 'pm_waterlevel_head''
// EA  : 0x83341440
// RVA : 0x01341440
// PDB : w:\tech5\engine\gamelib\physics\physics_player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_waterlevel_head__()
{
  idCVar::idCVar(
    this: &pm_waterlevel_head,
    name: "pm_waterlevel_head",
    value: "0.99",
    flags: 4,
    description: "Waterlevel for head",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_waterlevel_head__);
}

