
// ========================================================================
// ?GetWeight@idTurretTargetSelector@@UBAMPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B03428
// RVA : 0x00B03428
// PDB : w:\tech5\tungsten\game\ai\targetting\selectors\turrettargetselector.cpp
// ========================================================================

float __fastcall idTurretTargetSelector::GetWeight(
        idTurretTargetSelector *this,
        idEntity *owner,
        const idTargetInfo *ti)
{
  idEntity *Entity; // r3
  idEntity *v7; // r30
  double v8; // fp1
  double v10; // fp29
  double v12; // fp7
  double v13; // fp13
  double v14; // fp31
  idPhysics *Physics; // r27
  idPhysics *v16; // r26
  float *v17; // r27
  float *v18; // r3
  double v19; // fp7
  double v20; // fp6
  long double v21; // fp2
  double v22; // fp30
  long double v23; // fp4
  long double v24; // fp2
  long double v25; // fp2
  long double v26; // fp2
  double v27; // fp27
  double v28; // fp28
  idEntityPtr<idEntity> *p_lastAttacker; // r31
  double v30; // fp26
  double v31; // fp31
  idPhysics *v32; // r31
  idPhysics *v33; // r28
  idRenderWorld *v34; // r27
  idPhysics *v35; // r3
  idRenderWorld_vtbl *v36; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v38; // r26
  int v39; // r3
  idPhysics *v40; // r30
  idRenderWorld *v41; // r29
  __int64 v42; // r10
  va *v43; // r28
  idRenderWorld_vtbl *v44; // r31
  int v45; // r3
  int v46; // r6
  int v48; // [sp+8h] [-10E8h]
  int v49; // [sp+Ch] [-10E4h]
  int v50; // [sp+10h] [-10E0h]
  int v51; // [sp+14h] [-10DCh]
  int v52; // [sp+18h] [-10D8h]
  int v53; // [sp+1Ch] [-10D4h]
  idVec3 v54; // [sp+60h] [-1090h] BYREF
  float v55; // [sp+70h] [-1080h] BYREF
  float v56; // [sp+74h] [-107Ch]
  float v57; // [sp+78h] [-1078h]
  float a; // [sp+7Ch] [-1074h]
  va v59; // [sp+80h] [-1070h] BYREF

  if ( ti->es != nullptr )
  {
    Entity = idAIEntityState::GetEntity(this: (idAIEntityState *)ti->es);
    v7 = Entity;
    if ( Entity != nullptr && !Entity->IsDead(this: Entity) )
    {
      if ( this->trackOnlyPlayer && (unsigned __int8)idClass::IsType(this: v7, superclass: &idPlayer::Type) != 0 )
      {
        v8 = 1.0;
        return *((float *)&v8 + 1);
      }
      if ( !this->trackOnlyPlayer )
      {
        _FP10 = (float)(ti->distSqr - idMath::FLT_SMALLEST_NON_DENORMAL);
        v10 = 0.5;
        __asm { fsel      f8, f10, f12, f13 }
        v12 = __frsqrte(_FP8);
        v13 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12
                                                                                            * (float)(ti->distSqr * (float)0.5))
                                                                                    * (float)v12)
                                                                            - (float)1.5)
                                                            * (float)v12)
                                                    * (float)(ti->distSqr * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v12
                                                                                    * (float)(ti->distSqr * (float)0.5))
                                                                            * (float)v12)
                                                                    - (float)1.5)
                                                    * (float)v12))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v12 * (float)(ti->distSqr * (float)0.5))
                                                    * (float)v12)
                                            - (float)1.5)
                            * (float)v12));
        v14 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)(ti->distSqr * (float)0.5)) * (float)v12) - (float)1.5) * (float)v12) * (float)(ti->distSqr * (float)0.5))
                                                                                            * (float)((float)-(float)((float)((float)((float)v12 * (float)(ti->distSqr * (float)0.5)) * (float)v12) - (float)1.5) * (float)v12))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v12 * (float)(ti->distSqr * (float)0.5)) * (float)v12)
                                                                                            - (float)1.5)
                                                                            * (float)v12))
                                                            * (float)(ti->distSqr * (float)0.5))
                                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v12 * (float)(ti->distSqr * (float)0.5)) * (float)v12) - (float)1.5) * (float)v12)
                                                                                            * (float)(ti->distSqr * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v12 * (float)(ti->distSqr * (float)0.5)) * (float)v12) - (float)1.5)
                                                                                            * (float)v12))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v12 * (float)(ti->distSqr * (float)0.5))
                                                                                            * (float)v12)
                                                                                    - (float)1.5)
                                                                    * (float)v12)))
                                            - (float)1.5)
                            * (float)v13)
                    * ti->distSqr);
        if ( v14 <= this->maxTargetDistance && v14 >= this->minTargetDistance )
        {
          Physics = idEntity::GetPhysics(this: owner);
          v16 = idEntity::GetPhysics(this: v7);
          v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v18 = (float *)v16->GetOrigin(this: v16, a2: 0);
          v19 = (float)(v18[1] - v17[1]);
          v20 = (float)(v18[2] - v17[2]);
          v54.x = *v18 - *v17;
          v54.y = v19;
          v54.z = v20;
          idVec3::NormalizeFast(this: &v54);
          *((double *)&v21 + 1) = this->forwardSearchDir.x;
          *(double *)&v21 = (float)((float)(this->maxSearchAngle * idMath::M_DEG2RAD) * (float)0.5);
          v22 = (float)((float)(v54.x * this->forwardSearchDir.x)
                      + (float)((float)(this->forwardSearchDir.z * v54.z) + (float)(this->forwardSearchDir.y * v54.y)));
          v24 = cos(x: v21);
          if ( v22 >= (float)*(double *)&v24 )
          {
            *(_QWORD *)&v25 = 0x4000000000000000LL;
            *((double *)&v25 + 1) = (float)((float)v14 * (float)-0.001953125);
            v26 = pow(x: v25, y: v23);
            v27 = (float)((float)((float)*(double *)&v26 * (float)0.89999998) + (float)0.1);
            if ( (unsigned __int8)idAIEntityState::IsVisible(this: (idAIEntityState *)ti->es) != 0 )
              v28 = 1.0;
            else
              v28 = 0.5;
            if ( idEntityPtr<idEntity const>::operator->(this: &this->lastTarget) != nullptr
              && idEntityPtr<idEntity const>::operator->(this: &this->lastTarget) == v7 )
            {
              v10 = 1.0;
            }
            p_lastAttacker = &this->lastAttacker;
            v30 = 0.80000001;
            if ( idEntityPtr<idEntity const>::operator->(this: p_lastAttacker) != nullptr
              && idEntityPtr<idEntity const>::operator->(this: p_lastAttacker) == v7 )
            {
              v30 = 1.0;
            }
            if ( turret_debugTargeting.valueInteger != 0 )
            {
              a = idColor::colorBlack.a;
              v55 = 1.0;
              v56 = (float)1.0 - (float)((float)((float)v10 * (float)v28) * (float)v27);
              v57 = v56;
              v32 = idEntity::GetPhysics(this: v7);
              v33 = idEntity::GetPhysics(this: owner);
              v34 = common->RW(this: common);
              v35 = v32;
              GetOrigin = v32->GetOrigin;
              v36 = v34->__vftable;
              v38 = (int)GetOrigin(this: v35, a2: 0);
              v39 = (int)v33->GetOrigin(this: v33, a2: 0);
              ((void (__fastcall *)(idRenderWorld *, float *, int, int, double))v36->DebugArrow)(
                a1: v34,
                a2: &v55,
                a3: v39,
                a4: v38,
                a5: 12.0);
              v40 = idEntity::GetPhysics(this: v7);
              v41 = common->RW(this: common);
              v31 = (float)((float)((float)v10 * (float)v28) * (float)v27);
              HIDWORD(v42) = LODWORD(v31);
              v43 = va::va(
                      this: &v59,
                      fmt: (const char *)HIDWORD(v27),
                      a3: __SPAIR64__(LODWORD(v27), LODWORD(v28)),
                      a4: __SPAIR64__(LODWORD(v10), LODWORD(v30)),
                      a5: v42,
                      a6: v48,
                      a7: v49,
                      a8: v50,
                      a9: v51,
                      a10: v52,
                      a11: v53,
                      v27,
                      v28,
                      v10,
                      v30,
                      v31);
              v44 = v41->__vftable;
              v45 = (int)v40->GetOrigin(this: v40, a2: 0);
              ((void (__fastcall *)(idRenderWorld *, va *, int, int, float *, int, double))v44->DebugText)(
                a1: v41,
                a2: v43,
                a3: v45,
                a4: v46,
                a5: &v55,
                a6: 1,
                a7: 0.2);
            }
            v8 = (float)((float)((float)v10 * (float)v28) * (float)v27);
            return *((float *)&v8 + 1);
          }
        }
      }
    }
  }
  v8 = 0.0;
  return *((float *)&v8 + 1);
}


// ========================================================================
// `dynamic initializer for 'turret_debugTargeting''
// EA  : 0x83369B50
// RVA : 0x01369B50
// PDB : w:\tech5\tungsten\game\ai\targetting\selectors\turrettargetselector.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__turret_debugTargeting__()
{
  idCVar::idCVar(
    this: &turret_debugTargeting,
    name: "turret_debugTargeting",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__turret_debugTargeting__);
}

