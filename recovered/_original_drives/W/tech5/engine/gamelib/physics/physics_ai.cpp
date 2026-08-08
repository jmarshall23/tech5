
// ========================================================================
// ??1idPhysics_AI@@UAA@XZ
// EA  : 0x827456F0
// RVA : 0x007456F0
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::~idPhysics_AI(idPhysics_AI *this)
{
  idClipModel *clipModel_standing; // r3
  idClipModel *clipModel_crouched; // r3

  this->__vftable = (idPhysics_AI_vtbl *)&idPhysics_AI::`vftable';
  clipModel_standing = this->clipModel_standing;
  if ( clipModel_standing != nullptr )
    idClipModel::Delete(this: clipModel_standing);
  clipModel_crouched = this->clipModel_crouched;
  if ( clipModel_crouched != nullptr )
    idClipModel::Delete(this: clipModel_crouched);
  this->clipModels[0] = nullptr;
  idPhysics_Actor::~idPhysics_Actor(this);
}


// ========================================================================
// __unwind$246211
// EA  : 0x82745764
// RVA : 0x00745764
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void _unwind_246211()
{
  int v0; // r12

  idPhysics_Actor::~idPhysics_Actor(this: *(idPhysics_Actor **)(v0 - 112 + 132));
}


// ========================================================================
// ?Activate@idPhysics_AI@@UAAXXZ
// EA  : 0x82745790
// RVA : 0x00745790
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::Activate(idPhysics_AI *this)
{
  this->current.atRest = -1;
}


// ========================================================================
// ?IsAtRest@idPhysics_AI@@UBA_NXZ
// EA  : 0x827457A0
// RVA : 0x007457A0
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

BOOL __fastcall idPhysics_AI::IsAtRest(idPhysics_AI *this)
{
  return this->current.atRest >= 0;
}


// ========================================================================
// ?GetLinearVelocity@idPhysics_AI@@UBA?AVidVec3@@H@Z
// EA  : 0x827457B8
// RVA : 0x007457B8
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

idPhysics_AI *__fastcall idPhysics_AI::GetLinearVelocity(idPhysics_AI *this, idVec3 *result, int id)
{
  float z; // r10
  float x; // r9

  z = result[40].z;
  x = result[41].x;
  this->__vftable = (idPhysics_AI_vtbl *)LODWORD(result[40].y);
  *((float *)&this->__vftable + 1) = z;
  *(float *)&this->type = x;
  return this;
}


// ========================================================================
// ?GetPushedLinearVelocity@idPhysics_AI@@UBA?AVidVec3@@H@Z
// EA  : 0x827457D8
// RVA : 0x007457D8
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

idPhysics_AI *__fastcall idPhysics_AI::GetPushedLinearVelocity(idPhysics_AI *this, idVec3 *result, const int id)
{
  float z; // r10
  float x; // r9

  z = result[41].z;
  x = result[42].x;
  this->__vftable = (idPhysics_AI_vtbl *)LODWORD(result[41].y);
  *((float *)&this->__vftable + 1) = z;
  *(float *)&this->type = x;
  return this;
}


// ========================================================================
// ?SetContents@idPhysics_AI@@UAAXHH@Z
// EA  : 0x827457F8
// RVA : 0x007457F8
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::SetContents(idPhysics_AI *this, int contents, int id)
{
  idClipModel *clipModel_standing; // r3
  idClipModel *clipModel_crouched; // r3

  if ( id > 0 )
  {
    clipModel_crouched = this->clipModels[id];
LABEL_7:
    idClipModel::SetContents(this: clipModel_crouched, newContents: contents);
    return;
  }
  clipModel_standing = this->clipModel_standing;
  if ( clipModel_standing != nullptr )
    idClipModel::SetContents(this: clipModel_standing, newContents: contents);
  clipModel_crouched = this->clipModel_crouched;
  if ( clipModel_crouched != nullptr )
    goto LABEL_7;
}


// ========================================================================
// ?Evolve@idPhysics_AI@@AAAXM@Z
// EA  : 0x82745940
// RVA : 0x00745940
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::Evolve(idPhysics_AI *this, double timeStep)
{
  idPhysics_AI::aiMovement_t movementType; // r11
  double maxStepHeight; // fp29
  double v6; // fp30
  char v7; // r11
  double z; // fp0
  double v9; // fp10
  double v10; // fp9
  double v11; // fp7
  double v12; // fp6
  double v13; // fp28
  double v14; // fp27
  double v15; // fp5
  double v16; // fp4
  double v17; // fp12
  double v18; // fp13
  double v19; // fp10
  double v20; // fp9
  double v21; // fp7
  double v22; // fp6
  double v23; // fp30
  double v24; // fp28
  double v25; // fp12
  double v26; // fp10
  double x; // fp8
  double y; // fp7
  double v29; // fp3
  double v30; // fp10
  double v31; // fp9
  idClipModel *v32; // r11
  const idBounds *v33; // r30
  int entityNumber; // r29
  idClip *clip; // r4
  double v36; // fp8
  double v37; // fp7
  const idMat3 *v38; // [sp+8h] [-108h]
  int v39; // [sp+Ch] [-104h]
  int v40; // [sp+10h] [-100h]
  bool v41; // [sp+17h] [-F9h]
  const char *v42; // [sp+18h] [-F8h]
  int v43; // [sp+1Ch] [-F4h]
  int v44; // [sp+20h] [-F0h]
  int v45; // [sp+24h] [-ECh]
  int v46; // [sp+28h] [-E8h]
  int v47; // [sp+2Ch] [-E4h]
  int v48; // [sp+30h] [-E0h]
  int v49; // [sp+34h] [-DCh]
  int v50; // [sp+38h] [-D8h]
  int v51; // [sp+3Ch] [-D4h]
  int v52; // [sp+40h] [-D0h]
  int v53; // [sp+44h] [-CCh]
  int v54; // [sp+48h] [-C8h]
  int v55; // [sp+4Ch] [-C4h]
  int v56; // [sp+50h] [-C0h]
  int v57; // [sp+54h] [-BCh]
  int v58; // [sp+58h] [-B8h]
  int v59; // [sp+60h] [-B0h]
  int v60; // [sp+68h] [-A8h]
  int v61; // [sp+70h] [-A0h]
  int v62; // [sp+78h] [-98h]
  int v63; // [sp+80h] [-90h]
  idVec3 v64; // [sp+90h] [-80h] BYREF
  idVec3 v65; // [sp+A0h] [-70h] BYREF

  movementType = this->movementType;
  maxStepHeight = this->maxStepHeight;
  v6 = 0.0;
  if ( movementType != AI_MOVE_WALKING )
  {
    if ( movementType == AI_MOVE_FLYING )
    {
      v6 = this->maxStepHeight;
    }
    else
    {
      if ( movementType != AI_MOVE_DROPPING )
        return;
      v25 = (float)(this->gravityVector.x * (float)timeStep);
      v26 = (float)(this->gravityVector.y * (float)timeStep);
      x = this->current.velocity.x;
      y = this->current.velocity.y;
      v29 = (float)(this->current.velocity.z + (float)(this->gravityVector.z * (float)timeStep));
      this->current.velocity.z = this->current.velocity.z + (float)(this->gravityVector.z * (float)timeStep);
      this->current.velocity.x = (float)x + (float)v25;
      this->current.velocity.y = (float)y + (float)v26;
      if ( v29 < this->maxDropVelocity )
        this->current.velocity.z = this->maxDropVelocity;
      v6 = this->maxStepHeight;
    }
  }
  else
  {
    if ( this->gravityNormal.x != vec3_origin.x
      || this->gravityNormal.y != vec3_origin.y
      || (v7 = 1, this->gravityNormal.z != vec3_origin.z) )
    {
      v7 = 0;
    }
    if ( v7 != 0 )
      z = this->current.velocity.z;
    else
      z = (float)-(float)((float)(this->gravityNormal.x * this->current.velocity.x)
                        + (float)((float)(this->current.velocity.z * this->gravityNormal.z)
                                + (float)(this->current.velocity.y * this->gravityNormal.y)));
    if ( this->current.onGround
      && (z <= 1.0
       || this->swimmer && ((double (__fastcall *)(idPhysics_AI *, _DWORD))this->GetWaterLevel)(a1: this, a2: 0) != 0.0) )
    {
      if ( this->swimmer && ((double (__fastcall *)(idPhysics_AI *, _DWORD))this->GetWaterLevel)(a1: this, a2: 0) > 0.0 )
      {
        v9 = (float)(this->gravityVector.y * (float)timeStep);
        v10 = (float)(this->gravityVector.z * (float)timeStep);
        v11 = this->current.velocity.y;
        v12 = this->current.velocity.z;
        this->current.velocity.x = this->current.velocity.x + (float)(this->gravityVector.x * (float)timeStep);
        this->current.velocity.y = (float)v11 + (float)v9;
        this->current.velocity.z = (float)v12 + (float)v10;
        v13 = (float)((float)v12 + (float)v10);
        v14 = ((double (__fastcall *)(idPhysics_AI *, _DWORD))this->GetWaterViscosity)(a1: this, a2: 0);
        this->current.velocity.z = -(float)((float)((float)((float)v14 * this->GetWaterLevel(this, a2: 0)) * (float)v13)
                                          - (float)v13);
      }
      else
      {
        v15 = this->current.velocity.y;
        v16 = this->current.velocity.z;
        v17 = (float)(this->gravityNormal.z
                    * (float)((float)(this->gravityNormal.x * this->current.velocity.x)
                            + (float)((float)(this->gravityNormal.z * this->current.velocity.z)
                                    + (float)(this->gravityNormal.y * this->current.velocity.y))));
        v18 = (float)(this->gravityNormal.y
                    * (float)((float)(this->gravityNormal.x * this->current.velocity.x)
                            + (float)((float)(this->gravityNormal.z * this->current.velocity.z)
                                    + (float)(this->gravityNormal.y * this->current.velocity.y))));
        this->current.velocity.x = this->current.velocity.x
                                 - (float)(this->gravityNormal.x
                                         * (float)((float)(this->gravityNormal.x * this->current.velocity.x)
                                                 + (float)((float)(this->gravityNormal.z * this->current.velocity.z)
                                                         + (float)(this->gravityNormal.y * this->current.velocity.y))));
        this->current.velocity.z = (float)v16 - (float)v17;
        this->current.velocity.y = (float)v15 - (float)v18;
        v6 = (float)(this->maxStepHeight * (float)2.0);
      }
    }
    else
    {
      v19 = (float)(this->gravityVector.y * (float)timeStep);
      v20 = (float)(this->gravityVector.z * (float)timeStep);
      v21 = this->current.velocity.y;
      v22 = this->current.velocity.z;
      this->current.velocity.x = this->current.velocity.x + (float)(this->gravityVector.x * (float)timeStep);
      this->current.velocity.y = (float)v21 + (float)v19;
      this->current.velocity.z = (float)v22 + (float)v20;
      if ( this->swimmer )
      {
        v23 = (float)((float)v22 + (float)v20);
        v24 = ((double (__fastcall *)(idPhysics_AI *, _DWORD))this->GetWaterViscosity)(a1: this, a2: 0);
        this->current.velocity.z = -(float)((float)((float)((float)((float)v24 * this->GetWaterLevel(this, a2: 0))
                                                          * (float)v23)
                                                  * (float)0.1)
                                          - (float)v23);
      }
      v6 = (float)(this->maxStepHeight * (float)2.0);
    }
  }
  idVec3::ProjectOntoPlane(this: &this->current.velocity, normal: &this->lastCollisionNormal, overBounce: 1.001);
  v30 = (float)(this->current.velocity.y * (float)timeStep);
  v31 = (float)(this->current.velocity.z * (float)timeStep);
  v64.x = this->current.velocity.x * (float)timeStep;
  v64.y = v30;
  v64.z = v31;
  idVec3::FixDenormals(this: &v64);
  if ( ((LODWORD(v64.y) | LODWORD(v64.z) | LODWORD(v64.x)) & 0x7FFFFFFF) != 0 )
  {
    v32 = this->clipModels[0];
    v33 = (const idBounds *)this->clipMasks[0];
    entityNumber = this->entityNumber;
    clip = this->clip;
    v36 = (float)(v32->origin.z + v64.z);
    v37 = (float)(v32->origin.y + v64.y);
    v65.x = v32->origin.x + v64.x;
    v65.z = v36;
    v65.y = v37;
    this->stepMoveQuery.index = *(_QWORD *)&idClip::StepMoveContacts(
                                              this: (idClip *)&v64,
                                              result: clip,
                                              a3: nullptr,
                                              contacts: nullptr,
                                              start: &v32->origin,
                                              end: &v65,
                                              downNormal: &this->gravityNormal,
                                              stepUp: maxStepHeight,
                                              stepDown: v6,
                                              clipModel: (const idClipModel *)&v32->axis,
                                              startAxis: v38,
                                              clipMask: v39,
                                              passEntityNumber: v40,
                                              moveClipModel: v41,
                                              userName: v42,
                                              a16: v43,
                                              a17: v44,
                                              a18: v45,
                                              a19: v46,
                                              a20: v47,
                                              a21: v48,
                                              a22: v49,
                                              a23: v50,
                                              a24: v51,
                                              a25: v52,
                                              a26: v53,
                                              a27: v54,
                                              a28: v55,
                                              a29: v56,
                                              a30: v57,
                                              a31: v58,
                                              a32: v32,
                                              a33: v59,
                                              a34: (int)&v32->axis,
                                              a35: v60,
                                              a36: v33,
                                              a37: v61,
                                              a38: entityNumber,
                                              a39: v62,
                                              clipModel_0_3: true,
                                              a41: v63,
                                              startAxisa: (idMat3 *)"w:\\tech5\\engine\\gamelib\\physics\\Physics_AI.cpp(124) : StepMoveContacts")->world;
  }
}


// ========================================================================
// ?GetImpactInfo@idPhysics_AI@@UBAXHABVidVec3@@AAUimpactInfo_t@@@Z
// EA  : 0x82745D88
// RVA : 0x00745D88
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::GetImpactInfo(idPhysics_AI *this, const int id, const idVec3 *point, impactInfo_t *info)
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
// ?ApplyImpulse@idPhysics_AI@@UAAXHABVidVec3@@0@Z
// EA  : 0x82745DF8
// RVA : 0x00745DF8
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::ApplyImpulse(
        idPhysics_AI *this,
        const int bodyId,
        const idVec3 *point,
        const idVec3 *impulse)
{
  double v7; // fp2
  double v8; // fp5
  double v9; // fp3
  double v10; // fp7
  double v11; // fp6
  double y; // fp4
  double z; // fp3
  idVec3 *p_velocity; // r31
  double v17; // fp3
  double v18; // fp12
  double v19; // fp11
  double v20; // fp10
  double v21; // fp9

  if ( !this->noImpact )
  {
    if ( !this->swimmer )
      goto LABEL_5;
    _FP5 = (float)((float)((float)(impulse->z * impulse->z)
                         + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f13 }
    v7 = __frsqrte(_FP3);
    v8 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7
                                                                                       * (float)((float)((float)(impulse->z * impulse->z) + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y)))
                                                                                               * (float)0.5))
                                                                               * (float)v7)
                                                                       - (float)1.5)
                                                       * (float)v7)
                                               * (float)((float)((float)(impulse->z * impulse->z)
                                                               + (float)((float)(impulse->x * impulse->x)
                                                                       + (float)(impulse->y * impulse->y)))
                                                       * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v7
                                                                               * (float)((float)((float)(impulse->z * impulse->z)
                                                                                               + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y)))
                                                                                       * (float)0.5))
                                                                       * (float)v7)
                                                               - (float)1.5)
                                               * (float)v7))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v7
                                                       * (float)((float)((float)(impulse->z * impulse->z)
                                                                       + (float)((float)(impulse->x * impulse->x)
                                                                               + (float)(impulse->y * impulse->y)))
                                                               * (float)0.5))
                                               * (float)v7)
                                       - (float)1.5)
                       * (float)v7));
    v9 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7 * (float)((float)((float)(impulse->z * impulse->z) + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y))) * (float)0.5)) * (float)v7) - (float)1.5)
                                                                                       * (float)v7)
                                                                               * (float)((float)((float)(impulse->z * impulse->z)
                                                                                               + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y)))
                                                                                       * (float)0.5))
                                                                       * (float)((float)-(float)((float)((float)((float)v7 * (float)((float)((float)(impulse->z * impulse->z) + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y))) * (float)0.5)) * (float)v7)
                                                                                               - (float)1.5)
                                                                               * (float)v7))
                                                               - (float)1.5)
                                               * (float)((float)-(float)((float)((float)((float)v7
                                                                                       * (float)((float)((float)(impulse->z * impulse->z) + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y)))
                                                                                               * (float)0.5))
                                                                               * (float)v7)
                                                                       - (float)1.5)
                                                       * (float)v7))
                                       * (float)((float)((float)(impulse->z * impulse->z)
                                                       + (float)((float)(impulse->x * impulse->x)
                                                               + (float)(impulse->y * impulse->y)))
                                               * (float)0.5))
                               * (float)v8)
                       - (float)1.5);
    if ( impulse->z == (float)((float)((float)v9
                                     * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v7 * (float)((float)((float)(impulse->z * impulse->z) + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y))) * (float)0.5)) * (float)v7) - (float)1.5)
                                                                                     * (float)v7)
                                                                             * (float)((float)((float)(impulse->z * impulse->z)
                                                                                             + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y)))
                                                                                     * (float)0.5))
                                                                     * (float)((float)-(float)((float)((float)((float)v7 * (float)((float)((float)(impulse->z * impulse->z) + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y))) * (float)0.5)) * (float)v7)
                                                                                             - (float)1.5)
                                                                             * (float)v7))
                                                             - (float)1.5)
                                             * (float)((float)-(float)((float)((float)((float)v7
                                                                                     * (float)((float)((float)(impulse->z * impulse->z) + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y)))
                                                                                             * (float)0.5))
                                                                             * (float)v7)
                                                                     - (float)1.5)
                                                     * (float)v7)))
                             * (float)((float)(impulse->z * impulse->z)
                                     + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y)))) )
    {
      this->current.velocity.z = (float)((float)(this->invMass * impulse->z) * (float)1000.0) + this->current.velocity.z;
    }
    else
    {
LABEL_5:
      v10 = (float)(impulse->y * this->invMass);
      v11 = (float)(impulse->z * this->invMass);
      y = this->current.velocity.y;
      z = this->current.velocity.z;
      this->current.velocity.x = (float)(impulse->x * this->invMass) + this->current.velocity.x;
      this->current.velocity.y = (float)y + (float)v10;
      this->current.velocity.z = (float)z + (float)v11;
    }
    p_velocity = &this->current.velocity;
    _FP6 = (float)((float)((float)(this->current.velocity.z * this->current.velocity.z)
                         + (float)((float)(this->current.velocity.x * this->current.velocity.x)
                                 + (float)(this->current.velocity.y * this->current.velocity.y)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f4, f6, f7, f13 }
    v17 = __frsqrte(_FP4);
    v18 = (float)((float)-(float)((float)((float)((float)v17
                                                * (float)((float)((float)(this->current.velocity.z
                                                                        * this->current.velocity.z)
                                                                + (float)((float)(this->current.velocity.x
                                                                                * this->current.velocity.x)
                                                                        + (float)(this->current.velocity.y
                                                                                * this->current.velocity.y)))
                                                        * (float)0.5))
                                        * (float)v17)
                                - (float)1.5)
                * (float)v17);
    v19 = (float)((float)((float)-(float)((float)((float)((float)v17
                                                        * (float)((float)((float)(this->current.velocity.z
                                                                                * this->current.velocity.z)
                                                                        + (float)((float)(this->current.velocity.x
                                                                                        * this->current.velocity.x)
                                                                                + (float)(this->current.velocity.y
                                                                                        * this->current.velocity.y)))
                                                                * (float)0.5))
                                                * (float)v17)
                                        - (float)1.5)
                        * (float)v17)
                * (float)((float)((float)(this->current.velocity.z * this->current.velocity.z)
                                + (float)((float)(this->current.velocity.x * this->current.velocity.x)
                                        + (float)(this->current.velocity.y * this->current.velocity.y)))
                        * (float)0.5));
    if ( (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v19 * (float)v18)
                                                                               - (float)1.5)
                                                               * (float)v18)
                                                       * (float)((float)((float)(this->current.velocity.z
                                                                               * this->current.velocity.z)
                                                                       + (float)((float)(this->current.velocity.x
                                                                                       * this->current.velocity.x)
                                                                               + (float)(this->current.velocity.y
                                                                                       * this->current.velocity.y)))
                                                               * (float)0.5))
                                               * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5)
                                                       * (float)v18))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)v19 * (float)v18) - (float)1.5) * (float)v18))
               * (float)((float)(this->current.velocity.z * this->current.velocity.z)
                       + (float)((float)(this->current.velocity.x * this->current.velocity.x)
                               + (float)(this->current.velocity.y * this->current.velocity.y)))) > 2000.0 )
    {
      idVec3::NormalizeFast(this: &this->current.velocity);
      v20 = (float)(this->current.velocity.y * (float)2000.0);
      v21 = (float)(this->current.velocity.z * (float)2000.0);
      p_velocity->x = p_velocity->x * (float)2000.0;
      this->current.velocity.y = v20;
      this->current.velocity.z = v21;
    }
    ((void (__fastcall *)(idPhysicsCallbacks *, int, const idVec3 *))this->callbacks->ActivatePhysics)(
      a1: this->callbacks,
      a2: this->physicsId,
      a3: point);
  }
}


// ========================================================================
// ?PutToRest@idPhysics_AI@@UAAXXZ
// EA  : 0x82745FD8
// RVA : 0x00745FD8
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::PutToRest(idPhysics_AI *this)
{
  this->current.atRest = 1;
  this->current.velocity.z = 0.0;
  this->current.velocity.y = 0.0;
  this->current.velocity.x = 0.0;
}


// ========================================================================
// ?SaveState@idPhysics_AI@@UAAXXZ
// EA  : 0x82745FF8
// RVA : 0x00745FF8
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::SaveState(idPhysics_AI *this)
{
  idClipModel *v1; // r11

  this->saved.atRest = this->current.atRest;
  this->saved.onGround = this->current.onGround;
  this->saved.pad = this->current.pad;
  this->saved.localOrigin.x = this->current.localOrigin.x;
  v1 = this->clipModels[0];
  this->saved.localOrigin.y = this->current.localOrigin.y;
  this->saved.localOrigin.z = this->current.localOrigin.z;
  this->saved.worldOrigin = this->current.worldOrigin;
  this->saved.velocity = this->current.velocity;
  this->saved.pushVelocity = this->current.pushVelocity;
  this->saved.worldOrigin = v1->origin;
}


// ========================================================================
// ?RestoreState@idPhysics_AI@@UAAXXZ
// EA  : 0x82746098
// RVA : 0x00746098
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::RestoreState(idPhysics_AI *this)
{
  idPhysics_AI_vtbl *v1; // r7
  idClipModel *v2; // r11
  void (__fastcall *LinkClip_2)(struct idPhysics_AI *, const idVec3 *, const idMat3 *); // r6

  this->current.atRest = this->saved.atRest;
  this->current.onGround = this->saved.onGround;
  this->current.pad = this->saved.pad;
  this->current.localOrigin.x = this->saved.localOrigin.x;
  v1 = this->__vftable;
  v2 = this->clipModels[0];
  this->current.localOrigin.y = this->saved.localOrigin.y;
  LinkClip_2 = v1->LinkClip_2;
  this->current.localOrigin.z = this->saved.localOrigin.z;
  this->current.worldOrigin = this->saved.worldOrigin;
  this->current.velocity = this->saved.velocity;
  this->current.pushVelocity = this->saved.pushVelocity;
  LinkClip_2(this, a2: &this->current.worldOrigin, a3: &v2->axis);
}


// ========================================================================
// ?SetClipModel@idPhysics_AI@@UAAXPAVidClipModel@@MH_N@Z
// EA  : 0x82746140
// RVA : 0x00746140
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::SetClipModel(
        idPhysics_AI *this,
        idClipModel *model,
        double density,
        int id,
        unsigned int freeOld,
        char a6)
{
  idClipModel *clipModel_standing; // r3
  idClipModel *clipModel_crouched; // r3
  double heightCrouched; // fp9
  idClipModel *v14; // r3
  idClipModel *v15; // r3
  idBounds v16; // [sp+60h] [-660h] BYREF
  idTraceModel v17; // [sp+80h] [-640h] BYREF

  if ( freeOld == 0 )
  {
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
    this->clipModels[0] = nullptr;
    if ( model != nullptr )
    {
      this->clipModel_standing = model;
      v16.b[0].x = model->bounds.b[0].x;
      v16.b[0].y = model->bounds.b[0].y;
      v16.b[0].z = model->bounds.b[0].z;
      v16.b[1].x = model->bounds.b[1].x;
      heightCrouched = this->heightCrouched;
      v16.b[1].y = model->bounds.b[1].y;
      v16.b[1].z = heightCrouched;
      idTraceModel::InitBox(this: &v17);
      idTraceModel::SetupBox(this: &v17, boxBounds: &v16);
      v14 = (idClipModel *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                             size: 0xD8u,
                             tag: TAG_CLIPMODEL,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
      if ( v14 != nullptr )
        v15 = idClipModel::idClipModel(this: v14, clip: this->clip, trm: &v17, numTraceModels: 1, material: nullptr);
      else
        v15 = nullptr;
      this->clipModel_crouched = v15;
      idClipModel::SetContents(this: v15, newContents: this->clipModel_standing->contents);
      idClipModel::Translate(this: this->clipModel_crouched, translation: &this->current.worldOrigin);
    }
  }
  idPhysics_Actor::SetClipModel(this, model, density, id, freeOld, a6);
}


// ========================================================================
// __unwind$247287
// EA  : 0x8274628C
// RVA : 0x0074628C
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void _unwind_247287()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1728 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?SetOrigin@idPhysics_AI@@UAAXABVidVec3@@H@Z
// EA  : 0x827462B8
// RVA : 0x007462B8
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::SetOrigin(idPhysics_AI *this, const idVec3 *newOrigin, int id)
{
  unsigned __int64 index; // r11
  __int64 v6; // r7
  double v7; // fp2
  double v8; // fp9
  double v9; // fp6
  double v10; // fp4
  double v11; // fp3
  float v12; // [sp+50h] [-50h] BYREF
  float v13; // [sp+54h] [-4Ch]
  float v14; // [sp+58h] [-48h]
  float v15[10]; // [sp+60h] [-40h] BYREF

  index = this->stepMoveQuery.index;
  v6 = *(_QWORD *)(HIDWORD(index) + 377208);
  if ( (unsigned int)index >= (unsigned int)v6 )
  {
    v6 = *(_QWORD *)(HIDWORD(index) + 377232);
    if ( (unsigned int)index <= (unsigned int)v6 )
    {
      HIDWORD(v6) = 24 * ((index & 0xFFF) + 11621);
      *(_DWORD *)(HIDWORD(v6) + HIDWORD(index)) = 1;
    }
  }
  LODWORD(index) = 0;
  this->stepMoveQuery.index = index;
  ((void (__fastcall *)(idPhysics_AI *, const idVec3 *, idMat3 *, _DWORD))this->LinkClip_2)(
    a1: this,
    a2: newOrigin,
    a3: &this->clipModels[0]->axis,
    a4: HIDWORD(v6));
  if ( this->hasMaster )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v12, a3: (idMat3 *)v15);
    v7 = (float)(newOrigin->x - v12);
    v8 = v15[3];
    v9 = v15[6];
    v10 = (float)((float)(v15[4] * (float)(newOrigin->y - v13)) + (float)(v15[5] * (float)(newOrigin->z - v14)));
    v11 = (float)((float)(v15[7] * (float)(newOrigin->y - v13)) + (float)(v15[8] * (float)(newOrigin->z - v14)));
    this->current.localOrigin.x = (float)(v15[0] * (float)(newOrigin->x - v12))
                                + (float)((float)(v15[1] * (float)(newOrigin->y - v13))
                                        + (float)(v15[2] * (float)(newOrigin->z - v14)));
    this->current.localOrigin.y = (float)((float)v8 * (float)v7) + (float)v10;
    this->current.localOrigin.z = (float)((float)v9 * (float)v7) + (float)v11;
  }
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetAxis@idPhysics_AI@@UAAXABVidMat3@@H@Z
// EA  : 0x82746418
// RVA : 0x00746418
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::SetAxis(idPhysics_AI *this, const idMat3 *newAxis, int id)
{
  unsigned __int64 index; // r11
  __int64 v5; // r7

  index = this->stepMoveQuery.index;
  v5 = *(_QWORD *)(HIDWORD(index) + 377208);
  if ( (unsigned int)index >= (unsigned int)v5 )
  {
    v5 = *(_QWORD *)(HIDWORD(index) + 377232);
    if ( (unsigned int)index <= (unsigned int)v5 )
    {
      HIDWORD(v5) = 24 * ((index & 0xFFF) + 11621);
      *(_DWORD *)(HIDWORD(v5) + HIDWORD(index)) = 1;
    }
  }
  LODWORD(index) = 0;
  this->stepMoveQuery.index = index;
  ((void (__fastcall *)(idPhysics_AI *, idVec3 *, const idMat3 *, _DWORD))this->LinkClip_2)(
    a1: this,
    a2: &this->clipModels[0]->origin,
    a3: newAxis,
    a4: HIDWORD(v5));
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetLinearVelocity@idPhysics_AI@@UAAXABVidVec3@@H@Z
// EA  : 0x827464D0
// RVA : 0x007464D0
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::SetLinearVelocity(idPhysics_AI *this, const idVec3 *newLinearVelocity, int id)
{
  this->current.velocity = *newLinearVelocity;
  ((void (__fastcall *)(idPhysicsCallbacks *, int, int))this->callbacks->ActivatePhysics)(
    a1: this->callbacks,
    a2: this->physicsId,
    a3: id);
}


// ========================================================================
// ?SetPushed@idPhysics_AI@@UAAXH@Z
// EA  : 0x82746500
// RVA : 0x00746500
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::SetPushed(idPhysics_AI *this, unsigned int deltaTime)
{
  idClipModel *v2; // r11
  double v3; // fp4
  double v4; // fp3

  v2 = this->clipModels[0];
  v3 = (float)(v2->origin.y - this->saved.worldOrigin.y);
  v4 = (float)(v2->origin.z - this->saved.worldOrigin.z);
  this->current.pushVelocity.x = (float)((float)1.0
                                       / (float)((float)__SPAIR64__(&unk_82390000, deltaTime) * (float)0.001))
                               * (float)(v2->origin.x - this->saved.worldOrigin.x);
  this->current.pushVelocity.y = (float)((float)1.0
                                       / (float)((float)__SPAIR64__(&unk_82390000, deltaTime) * (float)0.001))
                               * (float)v3;
  this->current.pushVelocity.z = (float)((float)1.0
                                       / (float)((float)__SPAIR64__(&unk_82390000, deltaTime) * (float)0.001))
                               * (float)v4;
}


// ========================================================================
// ?SetMaster@idPhysics_AI@@UAAX_NABVidVec3@@ABVidMat3@@W4bindFlags_t@@@Z
// EA  : 0x82746570
// RVA : 0x00746570
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::SetMaster(
        idPhysics_AI *this,
        __int64 masterOrigin,
        const idMat3 *masterAxis,
        const bindFlags_t bflags)
{
  idClip *clip; // r11
  unsigned __int64 index; // r10
  int v7; // r7
  int v8; // r8
  idClipModel *v9; // r11
  double v10; // fp1
  double x; // fp13
  double v12; // fp9
  double v13; // fp10
  double v14; // fp8

  clip = this->clip;
  index = this->stepMoveQuery.index;
  v7 = HIDWORD(index) | 0xC178;
  v8 = 1;
  if ( (idClipModel *)index >= *(idClipModel **)((char *)&clip->temporaryClipModel + (HIDWORD(index) | 0xC178)) )
  {
    v7 = 377232;
    if ( (unsigned int)index <= LODWORD(clip->collisionQueryLastAllocedIndex) )
      clip->collisionQueries[index & 0xFFF].type = QUERY_CANCELED;
  }
  this->stepMoveQuery.index = masterOrigin & 0xFF00000000LL;
  if ( (masterOrigin & 0xFF00000000uLL) >> 32 != 0 )
  {
    if ( !this->hasMaster )
    {
      v9 = this->clipModels[0];
      v10 = (float)(v9->origin.x - *(float *)masterOrigin);
      x = masterAxis->mat[2].x;
      v12 = masterAxis->mat[1].x;
      v13 = (float)((float)((float)(v9->origin.y - *(float *)(masterOrigin + 4)) * masterAxis->mat[1].y)
                  + (float)((float)(v9->origin.z - *(float *)(masterOrigin + 8)) * masterAxis->mat[1].z));
      v14 = (float)((float)((float)(v9->origin.y - *(float *)(masterOrigin + 4)) * masterAxis->mat[2].y)
                  + (float)((float)(v9->origin.z - *(float *)(masterOrigin + 8)) * masterAxis->mat[2].z));
      this->current.localOrigin.x = (float)((float)(v9->origin.x - *(float *)masterOrigin) * masterAxis->mat[0].x)
                                  + (float)((float)((float)(v9->origin.y - *(float *)(masterOrigin + 4))
                                                  * masterAxis->mat[0].y)
                                          + (float)((float)(v9->origin.z - *(float *)(masterOrigin + 8))
                                                  * masterAxis->mat[0].z));
      this->current.localOrigin.y = (float)((float)v10 * (float)v12) + (float)v13;
      this->current.localOrigin.z = (float)((float)v10 * (float)x) + (float)v14;
      this->hasMaster = true;
      this->masterYaw = idVec3::ToYaw(this: masterAxis->mat);
    }
    ((void (__fastcall *)(idPhysics_AI *, _BYTE, _DWORD, const idMat3 *, int, int))this->ClearContacts)(
      a1: this,
      a2: BYTE3(masterOrigin),
      a3: masterOrigin,
      a4: masterAxis,
      a5: v7,
      a6: v8);
  }
  else if ( this->hasMaster )
  {
    this->hasMaster = false;
    ((void (__fastcall *)(idPhysicsCallbacks *, int, _DWORD, const idMat3 *, int, int))this->callbacks->ActivatePhysics)(
      a1: this->callbacks,
      a2: this->physicsId,
      a3: masterOrigin,
      a4: masterAxis,
      a5: v7,
      a6: 1);
  }
}


// ========================================================================
// ?SetLocalOrigin@idPhysics_AI@@UAAXABVidVec3@@H@Z
// EA  : 0x827466E0
// RVA : 0x007466E0
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::SetLocalOrigin(idPhysics_AI *this, const idVec3 *newOrigin, int id)
{
  unsigned __int64 index; // r11
  __int64 v6; // r7
  idClipModel *v7; // r11
  void (__fastcall *LinkClip_2)(struct idPhysics_AI *, const idVec3 *, const idMat3 *); // ctr
  double v9; // fp11
  double v10; // fp9
  int v11; // r6
  float v12[4]; // [sp+50h] [-60h] BYREF
  float v13[4]; // [sp+60h] [-50h] BYREF
  float v14[10]; // [sp+70h] [-40h] BYREF

  index = this->stepMoveQuery.index;
  v6 = *(_QWORD *)(HIDWORD(index) + 377208);
  if ( (unsigned int)index >= (unsigned int)v6 )
  {
    v6 = *(_QWORD *)(HIDWORD(index) + 377232);
    if ( (unsigned int)index <= (unsigned int)v6 )
    {
      HIDWORD(v6) = 24 * ((index & 0xFFF) + 11621);
      *(_DWORD *)(HIDWORD(v6) + HIDWORD(index)) = 1;
    }
  }
  LODWORD(index) = 0;
  this->stepMoveQuery.index = index;
  if ( this->hasMaster )
  {
    ((void (__fastcall *)(idPhysicsCallbacks *, float *, float *, _DWORD))this->callbacks->GetMasterPosition)(
      a1: this->callbacks,
      a2: v12,
      a3: v14,
      a4: HIDWORD(v6));
    this->current.localOrigin.x = newOrigin->x;
    this->current.localOrigin.y = newOrigin->y;
    this->current.localOrigin.z = newOrigin->z;
    v7 = this->clipModels[0];
    LinkClip_2 = this->LinkClip_2;
    v9 = (float)((float)(newOrigin->y * v14[5])
               + (float)((float)(newOrigin->x * v14[2]) + (float)(newOrigin->z * v14[8])));
    v10 = (float)(v12[1]
                + (float)((float)(newOrigin->x * v14[1])
                        + (float)((float)(newOrigin->z * v14[7]) + (float)(newOrigin->y * v14[4]))));
    v13[0] = (float)((float)(newOrigin->x * v14[0])
                   + (float)((float)(newOrigin->y * v14[3]) + (float)(newOrigin->z * v14[6])))
           + v12[0];
    v13[1] = v10;
    v13[2] = v12[2] + (float)v9;
    ((void (__fastcall *)(idPhysics_AI *, float *, idMat3 *, int))LinkClip_2)(a1: this, a2: v13, a3: &v7->axis, a4: v11);
  }
  else
  {
    ((void (__fastcall *)(idPhysics_AI *, const idVec3 *, idMat3 *, _DWORD))this->LinkClip_2)(
      a1: this,
      a2: newOrigin,
      a3: &this->clipModels[0]->axis,
      a4: HIDWORD(v6));
  }
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ?SetLocalAxis@idPhysics_AI@@UAAXABVidMat3@@H@Z
// EA  : 0x82746878
// RVA : 0x00746878
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::SetLocalAxis(idPhysics_AI *this, idMat3 *newAxis, int id)
{
  unsigned __int64 index; // r11
  __int64 v6; // r7
  idMat3 *v7; // r4
  idVec3 *p_origin; // r30
  idPhysics_AI_vtbl *v9; // r29
  idMat3 *v10; // r3
  int v11; // r6
  _BYTE v12[16]; // [sp+50h] [-90h] BYREF
  idMat3 v13; // [sp+60h] [-80h] BYREF
  idMat3 v14[2]; // [sp+90h] [-50h] BYREF

  index = this->stepMoveQuery.index;
  v6 = *(_QWORD *)(HIDWORD(index) + 377208);
  if ( (unsigned int)index >= (unsigned int)v6 )
  {
    v6 = *(_QWORD *)(HIDWORD(index) + 377232);
    if ( (unsigned int)index <= (unsigned int)v6 )
    {
      HIDWORD(v6) = 24 * ((index & 0xFFF) + 11621);
      *(_DWORD *)(HIDWORD(v6) + HIDWORD(index)) = 1;
    }
  }
  LODWORD(index) = 0;
  this->stepMoveQuery.index = index;
  if ( this->hasMaster )
  {
    ((void (__fastcall *)(idPhysicsCallbacks *, _BYTE *, idMat3 *, _DWORD))this->callbacks->GetMasterPosition)(
      a1: this->callbacks,
      a2: v12,
      a3: &v13,
      a4: HIDWORD(v6));
    v7 = newAxis;
    p_origin = &this->clipModels[0]->origin;
    v9 = this->__vftable;
    v10 = idMat3::operator*(this: v14, result: v7, a: &v13);
    ((void (__fastcall *)(idPhysics_AI *, idVec3 *, idMat3 *, int))v9->LinkClip_2)(
      a1: this,
      a2: p_origin,
      a3: v10,
      a4: v11);
  }
  else
  {
    ((void (__fastcall *)(idPhysics_AI *, idVec3 *, idMat3 *, _DWORD))this->LinkClip_2)(
      a1: this,
      a2: &this->clipModels[0]->origin,
      a3: newAxis,
      a4: HIDWORD(v6));
  }
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
}


// ========================================================================
// ??0idPhysics_AI@@QAA@XZ
// EA  : 0x82746978
// RVA : 0x00746978
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

idPhysics_AI *__fastcall idPhysics_AI::idPhysics_AI(idPhysics_AI *this)
{
  unsigned __int64 v1; // r30

  idPhysics_Actor::idPhysics_Actor(this);
  LODWORD(v1) = 0;
  this->__vftable = (idPhysics_AI_vtbl *)&idPhysics_AI::`vftable';
  this->stepMoveQuery.index = v1;
  this->contactsQuery.index = v1;
  this->lastCollisionNormal.x = 0.0;
  this->lastCollisionNormal.y = 0.0;
  this->lastCollisionNormal.z = 0.0;
  this->lastCollisionPoint.x = 0.0;
  this->lastCollisionPoint.y = 0.0;
  this->lastCollisionPoint.z = 0.0;
  this->stuckCollisionNormal.x = 0.0;
  this->stuckCollisionNormal.y = 0.0;
  this->stuckCollisionNormal.z = 0.0;
  this->stuckCollisionPoint.x = 0.0;
  this->stuckCollisionPoint.y = 0.0;
  this->stuckCollisionPoint.z = 0.0;
  this->clipModel_standing = nullptr;
  this->clipModel_crouched = nullptr;
  this->maxStepHeight = 18.0;
  this->movementType = AI_MOVE_WALKING;
  this->noImpact = false;
  this->masterControlledVelocity = false;
  this->minFloorCosine = 0.70710677;
  this->swimmer = false;
  this->maxDropVelocity = -500.0;
  this->crouched = false;
  this->heightCrouched = 48.0;
  this->canSetCrouchedPhysics = false;
  this->type = PHYSICS_AI;
  memset(Dst: &this->current, Val: 0, Size: sizeof(this->current));
  this->current.atRest = -1;
  this->saved.atRest = -1;
  this->saved.onGround = this->current.onGround;
  this->saved.pad = this->current.pad;
  this->saved.localOrigin = this->current.localOrigin;
  this->saved.worldOrigin = this->current.worldOrigin;
  this->saved.velocity = this->current.velocity;
  this->saved.pushVelocity = this->current.pushVelocity;
  this->masterControlledVelocity = false;
  return this;
}


// ========================================================================
// ?ResolveCollisions@idPhysics_AI@@AAAXXZ
// EA  : 0x82746AF0
// RVA : 0x00746AF0
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::ResolveCollisions(idPhysics_AI *this)
{
  unsigned __int64 v1; // r26
  idClipQuery *p_stepMoveQuery; // r28
  idVec3 *p_lastCollisionNormal; // r30
  idVec3 *p_lastCollisionPoint; // r29
  idClip *clip; // r27
  int v7; // r11
  double y; // fp13
  double z; // fp12
  double v10; // fp10
  double v11; // fp9
  const idVec3 *v12; // r3
  double v13; // fp0
  idRenderWorld *v14; // r3
  idRenderWorld *v15; // r3
  int v16; // r30
  contactInfo_t *contacts; // r29
  idGame *v18; // r3
  idClip *v19; // r27
  const idTypeInfoTools *v20; // r3
  int v21; // r29
  contactInfo_t *v22; // r30
  int num; // r8
  float *v24; // r10
  contactInfo_t *list; // r11
  int v26; // r9
  double x; // fp0
  double v28; // fp13
  double v29; // fp12
  int v30; // r6
  int v31; // r8
  double v32; // fp3
  double v33; // fp7
  double v34; // fp6
  double v35; // fp5
  double v38; // fp1
  double v39; // fp9
  idPhysicsCallbacks *callbacks; // r3
  int v41; // r4
  idPhysics *PhysicsForId; // r3
  idPhysics *v43; // r29
  idPhysicsCallbacks *v44; // r3
  double v45; // fp10
  int v46; // r4
  double v47; // fp6
  char v48; // [sp+50h] [-540h] BYREF
  float v49; // [sp+54h] [-53Ch]
  float v50; // [sp+58h] [-538h]
  float v51; // [sp+5Ch] [-534h]
  float v52; // [sp+60h] [-530h]
  float v53; // [sp+64h] [-52Ch]
  float v54; // [sp+68h] [-528h]
  float v55; // [sp+6Ch] [-524h]
  float v56; // [sp+70h] [-520h]
  float v57; // [sp+74h] [-51Ch]
  float v58; // [sp+78h] [-518h]
  float v59; // [sp+7Ch] [-514h]
  float v60; // [sp+80h] [-510h]
  contactType_t type; // [sp+84h] [-50Ch]
  float v62[3]; // [sp+88h] [-508h] BYREF
  float v63; // [sp+94h] [-4FCh]
  float v64; // [sp+98h] [-4F8h]
  float v65; // [sp+9Ch] [-4F4h]
  float dist; // [sp+A0h] [-4F0h]
  float separation; // [sp+A4h] [-4ECh]
  int contentFlags; // [sp+A8h] [-4E8h]
  int surfaceFlags; // [sp+ACh] [-4E4h]
  int surfaceType; // [sp+B0h] [-4E0h]
  int modelFeature; // [sp+B4h] [-4DCh]
  int trmFeature; // [sp+B8h] [-4D8h]
  int entityNum; // [sp+BCh] [-4D4h]
  int physicsId; // [sp+C0h] [-4D0h]
  int bodyId; // [sp+C4h] [-4CCh]
  int selfId; // [sp+C8h] [-4C8h]
  unsigned __int8 flags; // [sp+CCh] [-4C4h]
  unsigned __int8 v78; // [sp+CDh] [-4C3h]
  unsigned __int8 v79; // [sp+CEh] [-4C2h]
  unsigned __int8 v80; // [sp+CFh] [-4C1h]
  float v81[4]; // [sp+D0h] [-4C0h] BYREF
  float v82[4]; // [sp+E0h] [-4B0h] BYREF
  trace_t v83; // [sp+F0h] [-4A0h] BYREF
  impactInfo_t v84; // [sp+170h] [-420h] BYREF
  contactsResult_t v85; // [sp+1B0h] [-3E0h] BYREF

  p_stepMoveQuery = &this->stepMoveQuery;
  p_lastCollisionNormal = &this->lastCollisionNormal;
  p_lastCollisionPoint = &this->lastCollisionPoint;
  this->lastCollisionNormal.x = 0.0;
  this->lastCollisionNormal.z = 0.0;
  this->lastCollisionNormal.y = 0.0;
  this->lastCollisionPoint.z = 0.0;
  this->lastCollisionPoint.y = 0.0;
  this->lastCollisionPoint.x = 0.0;
  clip = this->clip;
  if ( (unsigned __int8)idClip::QueryIsValid(this: clip, clipQuery: &this->stepMoveQuery) != 0 )
  {
    LODWORD(v1) = 0;
    v7 = p_stepMoveQuery->index & 0xFFF;
    p_stepMoveQuery->index = v1;
    idCollisionModelManager::GetStepMoveContactsResult(
      this: collisionModelManager,
      result: &v83,
      contacts: &v85,
      query: &clip->collisionQueries[v7].query,
      peek: false);
    y = v83.c.normal.y;
    z = v83.c.normal.z;
    p_lastCollisionNormal->x = v83.c.normal.x;
    p_lastCollisionNormal->y = y;
    p_lastCollisionNormal->z = z;
    v10 = v83.c.point.y;
    v11 = v83.c.point.z;
    p_lastCollisionPoint->x = v83.c.point.x;
    p_lastCollisionPoint->y = v10;
    p_lastCollisionPoint->z = v11;
    if ( ((LODWORD(p_lastCollisionNormal->z) | LODWORD(p_lastCollisionNormal->y) | LODWORD(p_lastCollisionNormal->x))
        & 0x7FFFFFFF) != 0 )
    {
      v12 = this->GetGravityNormal(this);
      v13 = (float)((float)(p_lastCollisionNormal->x * v12->x)
                  + (float)((float)(v12->z * p_lastCollisionNormal->z) + (float)(v12->y * p_lastCollisionNormal->y)));
      if ( v13 > -0.99989998 && v13 < 0.99989998 )
      {
        this->stuckCollisionNormal.x = p_lastCollisionNormal->x;
        this->stuckCollisionNormal.y = p_lastCollisionNormal->y;
        this->stuckCollisionNormal.z = p_lastCollisionNormal->z;
        this->stuckCollisionPoint.x = p_lastCollisionPoint->x;
        this->stuckCollisionPoint.y = p_lastCollisionPoint->y;
        this->stuckCollisionPoint.z = p_lastCollisionPoint->z;
      }
    }
    if ( ai_debugCollision.valueInteger < 0 || ai_debugCollision.valueInteger == this->entityNumber )
    {
      if ( v83.fraction < 1.0
        && ((LODWORD(p_lastCollisionNormal->z) | LODWORD(p_lastCollisionNormal->y) | LODWORD(p_lastCollisionNormal->x))
          & 0x7FFFFFFF) != 0 )
      {
        v14 = common->RW(this: common);
        v14->DebugPoint(this: v14, a2: (const idVec4 *)&idColor::colorYellow, a3: &v83.c.point, a4: 100, a5: false);
        v15 = common->RW(this: common);
        v82[0] = (float)(v83.c.normal.x * (float)24.0) + v83.c.point.x;
        v82[1] = (float)(v83.c.normal.y * (float)24.0) + v83.c.point.y;
        v82[2] = (float)(v83.c.normal.z * (float)24.0) + v83.c.point.z;
        ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))v15->DebugArrow)(
          a1: v15,
          a2: &idColor::colorMagenta,
          a3: &v83.c.point,
          a4: v82,
          a5: 2.0);
      }
      v16 = 0;
      if ( v85.numContacts > 0 )
      {
        contacts = v85.contacts;
        do
        {
          v18 = common->Game(this: common);
          v19 = this->clip;
          v20 = v18->GetTypeInfoTools(this: v18);
          idClip::ShowCollisionPoint(this: v19, contact: contacts, tools: v20);
          ++v16;
          ++contacts;
        }
        while ( v16 < v85.numContacts );
      }
    }
    idPhysics::UpdateCollisionResidency(this, contact: &v83.c);
    this->ClearContacts(this);
    v21 = 0;
    if ( v85.numContacts > 0 )
    {
      v22 = v85.contacts;
      do
      {
        idList<contactInfo_t,77>::Append(this: &this->contacts, obj: v22);
        ++v21;
        ++v22;
      }
      while ( v21 < v85.numContacts );
    }
    idPhysics_DynamicBase::AddContactPhysicsForContacts(this);
    this->ActivateContactPhysics(this);
    this->current.onGround = false;
    if ( ((LODWORD(this->gravityNormal.z) | LODWORD(this->gravityNormal.y) | LODWORD(this->gravityNormal.x)) & 0x7FFFFFFF) != 0 )
    {
      num = this->contacts.num;
      if ( num > 0 )
      {
        v24 = (float *)this->clipModels[0];
        list = this->contacts.list;
        v26 = 1;
        v49 = v24[8];
        v50 = v24[9];
        v51 = v24[10];
        v52 = v24[11];
        v53 = v24[12];
        v54 = v24[13];
        v55 = v24[14];
        v56 = v24[15];
        v57 = v24[16];
        v58 = v24[17];
        v59 = v24[18];
        v60 = v24[19];
        type = list->type;
        v62[0] = list->point.x;
        v62[1] = list->point.y;
        v62[2] = list->point.z;
        x = list->normal.x;
        v63 = list->normal.x;
        v28 = list->normal.y;
        v64 = list->normal.y;
        v29 = list->normal.z;
        v65 = list->normal.z;
        dist = list->dist;
        separation = list->separation;
        contentFlags = list->contentFlags;
        surfaceFlags = list->surfaceFlags;
        surfaceType = list->surfaceType;
        modelFeature = list->modelFeature;
        trmFeature = list->trmFeature;
        entityNum = list->entityNum;
        physicsId = list->physicsId;
        bodyId = list->bodyId;
        selfId = list->selfId;
        flags = list->flags;
        v78 = list->surfaceColor[0];
        v79 = list->surfaceColor[1];
        v80 = list->surfaceColor[2];
        if ( num > 1 )
        {
          v30 = this->contacts.num;
          v31 = 1;
          do
          {
            ++v26;
            x = (float)(list[v31].normal.x + (float)x);
            v63 = x;
            v28 = (float)(list[v31].normal.y + (float)v28);
            v64 = v28;
            v29 = (float)(list[v31++].normal.z + (float)v29);
            v65 = v29;
          }
          while ( v26 < v30 );
        }
        v32 = -this->minFloorCosine;
        v33 = this->gravityNormal.z;
        v34 = this->gravityNormal.x;
        v35 = this->gravityNormal.y;
        _FP8 = (float)((float)((float)((float)v28 * (float)v28)
                             + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f2, f8, f1, f10 }
        v38 = __frsqrte(_FP2);
        v39 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38
                                                                                            * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5))
                                                                                    * (float)v38)
                                                                            - (float)1.5)
                                                            * (float)v38)
                                                    * (float)((float)((float)((float)v28 * (float)v28)
                                                                    + (float)((float)((float)x * (float)x)
                                                                            + (float)((float)v29 * (float)v29)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v38
                                                                                    * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29)))
                                                                                            * (float)0.5))
                                                                            * (float)v38)
                                                                    - (float)1.5)
                                                    * (float)v38))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v38
                                                            * (float)((float)((float)((float)v28 * (float)v28)
                                                                            + (float)((float)((float)x * (float)x)
                                                                                    + (float)((float)v29 * (float)v29)))
                                                                    * (float)0.5))
                                                    * (float)v38)
                                            - (float)1.5)
                            * (float)v38));
        v65 = (float)v29
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5)) * (float)v38) - (float)1.5) * (float)v38)
                                                                                            * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5)) * (float)v38) - (float)1.5)
                                                                                            * (float)v38))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5))
                                                                                            * (float)v38)
                                                                                    - (float)1.5)
                                                                    * (float)v38))
                                                    * (float)((float)((float)((float)v28 * (float)v28)
                                                                    + (float)((float)((float)x * (float)x)
                                                                            + (float)((float)v29 * (float)v29)))
                                                            * (float)0.5))
                                            * (float)v39)
                                    - (float)1.5)
                    * (float)v39);
        v63 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5)) * (float)v38) - (float)1.5) * (float)v38)
                                                                                            * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5)) * (float)v38) - (float)1.5)
                                                                                            * (float)v38))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5))
                                                                                            * (float)v38)
                                                                                    - (float)1.5)
                                                                    * (float)v38))
                                                    * (float)((float)((float)((float)v28 * (float)v28)
                                                                    + (float)((float)((float)x * (float)x)
                                                                            + (float)((float)v29 * (float)v29)))
                                                            * (float)0.5))
                                            * (float)v39)
                                    - (float)1.5)
                    * (float)v39)
            * (float)x;
        v64 = (float)v28
            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5)) * (float)v38) - (float)1.5) * (float)v38)
                                                                                            * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5)) * (float)v38) - (float)1.5)
                                                                                            * (float)v38))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v38 * (float)((float)((float)((float)v28 * (float)v28) + (float)((float)((float)x * (float)x) + (float)((float)v29 * (float)v29))) * (float)0.5))
                                                                                            * (float)v38)
                                                                                    - (float)1.5)
                                                                    * (float)v38))
                                                    * (float)((float)((float)((float)v28 * (float)v28)
                                                                    + (float)((float)((float)x * (float)x)
                                                                            + (float)((float)v29 * (float)v29)))
                                                            * (float)0.5))
                                            * (float)v39)
                                    - (float)1.5)
                    * (float)v39);
        if ( (float)((float)((float)v35 * v64) + (float)((float)(v63 * (float)v34) + (float)((float)v33 * v65))) < v32 )
        {
          callbacks = this->callbacks;
          v41 = this->physicsId;
          this->current.onGround = true;
          callbacks->Collide(this: callbacks, a2: v41, a3: (trace_t *)&v48, a4: &this->current.velocity);
          PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: physicsId);
          v43 = PhysicsForId;
          if ( PhysicsForId != nullptr )
          {
            PhysicsForId->GetImpactInfo(this: PhysicsForId, a2: bodyId, a3: (const idVec3 *)v62, a4: &v84);
            if ( __fabs(v84.invMass) > idMath::FLT_SMALLEST_NON_DENORMAL )
            {
              v44 = v43->callbacks;
              v45 = this->current.velocity.x;
              v46 = this->physicsId;
              v47 = (float)(this->current.velocity.y * (float)((float)1.0 / (float)(v84.invMass * (float)10.0)));
              v81[2] = this->current.velocity.z * (float)((float)1.0 / (float)(v84.invMass * (float)10.0));
              v81[1] = v47;
              v81[0] = (float)v45 * (float)((float)1.0 / (float)(v84.invMass * (float)10.0));
              v44->ApplyImpulse(this: v44, a2: v46, a3: 0, a4: (const idVec3 *)v62, a5: (const idVec3 *)v81);
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ?Evaluate@idPhysics_AI@@UAA_NHH@Z
// EA  : 0x82747160
// RVA : 0x00747160
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

BOOL __fastcall idPhysics_AI::Evaluate(idPhysics_AI *this, unsigned int timeStepMSec, int endTimeMSec)
{
  BOOL crouched; // r9
  double v6; // fp30
  idClipModel *clipModel_crouched; // r30
  idClipModel *v8; // r3
  char *v9; // r10
  idClipModel *p_z; // r11
  int i; // ctr
  float y; // r10
  float z; // r9
  idPhysicsCallbacks *callbacks; // r3
  idClipModel *v15; // r11
  float v16; // r8
  float v17; // r7
  bool (__fastcall *GetMasterPosition)(idPhysicsCallbacks *, idVec3 *, idMat3 *); // r6
  idMat3 *p_axis; // r5
  double v20; // fp1
  void (__fastcall *LinkClip_2)(struct idPhysics_AI *, const idVec3 *, const idMat3 *); // ctr
  double v22; // fp13
  double x; // fp31
  double v24; // fp29
  double v25; // fp28
  double v26; // fp6
  double v27; // fp5
  double v28; // fp1
  double v29; // fp0
  double v30; // fp12
  unsigned __int8 v31; // r11
  idVec3 v33; // [sp+50h] [-C0h] BYREF
  float v34; // [sp+60h] [-B0h] BYREF
  float v35; // [sp+64h] [-ACh]
  float v36; // [sp+68h] [-A8h]
  float v37[4]; // [sp+70h] [-A0h] BYREF
  idVec3 v38; // [sp+80h] [-90h] BYREF
  float v39; // [sp+8Ch] [-84h]
  float v40; // [sp+90h] [-80h]
  float v41; // [sp+94h] [-7Ch]
  float v42; // [sp+98h] [-78h]
  float v43; // [sp+9Ch] [-74h]
  float v44; // [sp+A0h] [-70h]
  char v45; // [sp+ACh] [-64h] BYREF
  idMat3 v46[2]; // [sp+B0h] [-60h] BYREF

  idPhysics_Actor::RememberHistorySample(this);
  crouched = this->crouched;
  *(_QWORD *)&v33.x = __PAIR64__(&unk_82390000, timeStepMSec);
  v6 = (float)((float)__SPAIR64__(&unk_82390000, timeStepMSec) * (float)0.001);
  if ( crouched && this->canSetCrouchedPhysics )
    clipModel_crouched = this->clipModel_crouched;
  else
    clipModel_crouched = this->clipModel_standing;
  v8 = this->clipModels[0];
  if ( clipModel_crouched != v8 )
  {
    v9 = &v45;
    p_z = (idClipModel *)&v8->origin.z;
    for ( i = 9; i != 0; --i )
    {
      p_z = (idClipModel *)((char *)p_z + 4);
      v9 += 4;
      *(_DWORD *)v9 = p_z->__vftable;
    }
    y = v8->origin.y;
    z = v8->origin.z;
    v33.x = v8->origin.x;
    v33.y = y;
    v33.z = z;
    idClipModel::Unlink(this: v8);
    this->clipModels[0] = clipModel_crouched;
    idClipModel::Link(
      this: clipModel_crouched,
      newEntityNumber: this->entityNumber,
      newPhysicsId: this->physicsId,
      newBodyId: 0,
      newOrigin: &v33,
      newAxis: v46);
  }
  if ( this->hasMaster )
  {
    callbacks = this->callbacks;
    v15 = this->clipModels[0];
    v16 = v15->origin.y;
    v17 = v15->origin.z;
    GetMasterPosition = callbacks->GetMasterPosition;
    v33.x = v15->origin.x;
    v33.y = v16;
    v33.z = v17;
    GetMasterPosition(this: callbacks, a2: (idVec3 *)v37, a3: (idMat3 *)&v38);
    p_axis = &this->clipModels[0]->axis;
    v20 = (float)((float)(this->current.localOrigin.y * v41)
                + (float)((float)(this->current.localOrigin.x * v38.z) + (float)(this->current.localOrigin.z * v44)));
    LinkClip_2 = this->LinkClip_2;
    v22 = (float)(v37[1]
                + (float)((float)(this->current.localOrigin.y * v40)
                        + (float)((float)(this->current.localOrigin.x * v38.y)
                                + (float)(this->current.localOrigin.z * v43))));
    v34 = (float)((float)(this->current.localOrigin.x * v38.x)
                + (float)((float)(this->current.localOrigin.z * v42) + (float)(this->current.localOrigin.y * v39)))
        + v37[0];
    v35 = v22;
    v36 = v37[2] + (float)v20;
    LinkClip_2(this, a2: (const idVec3 *)&v34, a3: p_axis);
    x = v33.x;
    v24 = v33.y;
    v25 = v33.z;
    v26 = (float)(v35 - v33.y);
    v27 = (float)(v36 - v33.z);
    this->current.velocity.x = (float)(v34 - v33.x) * (float)((float)1.0 / (float)v6);
    this->current.velocity.y = (float)v26 * (float)((float)1.0 / (float)v6);
    this->current.velocity.z = (float)v27 * (float)((float)1.0 / (float)v6);
    this->masterDeltaYaw = this->masterYaw;
    v28 = idVec3::ToYaw(this: &v38);
    v29 = v34;
    v30 = (float)((float)v28 - this->masterDeltaYaw);
    this->masterYaw = v28;
    this->masterDeltaYaw = v30;
    if ( v29 != x || v35 != v24 || (v31 = 1, v36 != v25) )
      v31 = 0;
    return (_cntlzw(v31) & 0x20) != 0;
  }
  else if ( (unsigned __int16)this->current.atRest >= 0x8000u )
  {
    idPhysics_AI::ResolveCollisions(this);
    idPhysics_AI::Evolve(this, timeStep: v6);
    if ( this->IsOutsideWorld(this) )
      this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
    return true;
  }
  else
  {
    return false;
  }
}


// ========================================================================
// ?Translate@idPhysics_AI@@UAAXABVidVec3@@H@Z
// EA  : 0x82747438
// RVA : 0x00747438
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::Translate(idPhysics_AI *this, const idVec3 *translation, int id)
{
  idClipModel *v5; // r11
  idPhysics_AI_vtbl *v6; // r10
  double v7; // fp9
  double v8; // fp7
  void (__fastcall *LinkClip_2)(struct idPhysics_AI *, const idVec3 *, const idMat3 *); // ctr
  double y; // fp11
  double z; // fp8
  float v12[6]; // [sp+50h] [-30h] BYREF

  idPhysics_AI::ResolveCollisions(this);
  v5 = this->clipModels[0];
  v6 = this->__vftable;
  v7 = (float)(v5->origin.z + translation->z);
  v8 = (float)(v5->origin.y + translation->y);
  v12[0] = v5->origin.x + translation->x;
  v12[2] = v7;
  LinkClip_2 = v6->LinkClip_2;
  v12[1] = v8;
  LinkClip_2(this, a2: (const idVec3 *)v12, a3: &v5->axis);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  if ( this->hasMaster )
  {
    y = this->current.localOrigin.y;
    this->current.localOrigin.x = translation->x + this->current.localOrigin.x;
    z = this->current.localOrigin.z;
    this->current.localOrigin.y = (float)y + translation->y;
    this->current.localOrigin.z = (float)z + translation->z;
  }
}


// ========================================================================
// ?Rotate@idPhysics_AI@@UAAXABVidRotation@@H@Z
// EA  : 0x82747518
// RVA : 0x00747518
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __fastcall idPhysics_AI::Rotate(idPhysics_AI *this, idRotation *rotation, int id)
{
  idClipModel *v5; // r11
  idMat3 *p_axis; // r30
  idRotation *v7; // r3
  idPhysics_AI_vtbl *v8; // r29
  const idMat3 *v9; // r3
  idMat3 *v10; // r3
  idClipModel *v11; // r11
  double v12; // fp2
  double z; // fp11
  double v14; // fp7
  double v15; // fp4
  double v16; // fp3
  float v17; // [sp+50h] [-A0h] BYREF
  float v18; // [sp+54h] [-9Ch]
  float v19; // [sp+58h] [-98h]
  idRotation v20[2]; // [sp+60h] [-90h] BYREF

  idPhysics_AI::ResolveCollisions(this);
  v5 = this->clipModels[0];
  p_axis = &v5->axis;
  idRotation::operator*(this: v20, result: rotation, v: &v5->origin);
  v7 = rotation;
  v8 = this->__vftable;
  v9 = idRotation::ToMat3(this: v7);
  v10 = idMat3::operator*(this: (idMat3 *)&v20[0].axisValid, result: p_axis, a: v9);
  v8->LinkClip_2(this, a2: &v20[0].origin, a3: v10);
  this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  if ( this->hasMaster )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: (idVec3 *)&v17, a3: (idMat3 *)&v20[0].vec.y);
    v11 = this->clipModels[0];
    v12 = (float)(v11->origin.z - v19);
    z = v20[0].axis.mat[0].z;
    v14 = v20[0].axis.mat[1].z;
    v15 = (float)((float)(v20[0].axis.mat[0].x * (float)(v11->origin.x - v17))
                + (float)(v20[0].axis.mat[0].y * (float)(v11->origin.y - v18)));
    v16 = (float)((float)(v20[0].axis.mat[1].x * (float)(v11->origin.x - v17))
                + (float)(v20[0].axis.mat[1].y * (float)(v11->origin.y - v18)));
    this->current.localOrigin.x = (float)(v20[0].angle * (float)(v11->origin.z - v19))
                                + (float)((float)(v20[0].vec.z * (float)(v11->origin.y - v18))
                                        + (float)(v20[0].vec.y * (float)(v11->origin.x - v17)));
    this->current.localOrigin.y = (float)((float)z * (float)v12) + (float)v15;
    this->current.localOrigin.z = (float)((float)v14 * (float)v12) + (float)v16;
  }
}


// ========================================================================
// `dynamic initializer for 'ai_debugCollision''
// EA  : 0x83340D08
// RVA : 0x01340D08
// PDB : w:\tech5\engine\gamelib\physics\physics_ai.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_debugCollision__()
{
  idCVar::idCVar(
    this: &ai_debugCollision,
    name: "ai_debugCollision",
    value: "0",
    flags: 2,
    description: "Draw AI Collision Info; -1 to draw all, or entity number for just that entity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_debugCollision__);
}

