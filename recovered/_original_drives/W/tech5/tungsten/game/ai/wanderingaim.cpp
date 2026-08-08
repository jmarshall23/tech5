
// ========================================================================
// ?ConvergeTo@idWanderingAim@@AAAXMABVidVec3@@@Z
// EA  : 0x82B2BB78
// RVA : 0x00B2BB78
// PDB : w:\tech5\tungsten\game\ai\wanderingaim.cpp
// ========================================================================

void __fastcall idWanderingAim::ConvergeTo(idWanderingAim *this, double rate, const idVec3 *convergeTo, float *a4)
{
  double y; // fp11
  double v5; // fp7
  double x; // fp12
  double v7; // fp4
  double v10; // fp8
  double v11; // fp3
  double v12; // fp0
  double v13; // fp8
  double v14; // fp5
  double v15; // fp0
  double v16; // fp13
  double v17; // fp8

  y = this->error.y;
  v5 = (float)(a4[1] - this->error.y);
  x = this->error.x;
  v7 = (float)(a4[2] - this->error.z);
  _FP3 = (float)((float)((float)((float)v7 * (float)v7)
                       + (float)((float)((float)(*a4 - this->error.x) * (float)(*a4 - this->error.x))
                               + (float)((float)v5 * (float)v5)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f13, f3, f5, f13 }
  v10 = __frsqrte(_FP13);
  v11 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)(*a4 - this->error.x) * (float)(*a4 - this->error.x)) + (float)((float)v5 * (float)v5)))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10)
                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                              + (float)((float)((float)(*a4 - this->error.x)
                                                                              * (float)(*a4 - this->error.x))
                                                                      + (float)((float)v5 * (float)v5)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v10
                                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                                              + (float)((float)((float)(*a4 - this->error.x) * (float)(*a4 - this->error.x)) + (float)((float)v5 * (float)v5)))
                                                                                      * (float)0.5))
                                                                      * (float)v10)
                                                              - (float)1.5)
                                              * (float)v10))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v10
                                                      * (float)((float)((float)((float)v7 * (float)v7)
                                                                      + (float)((float)((float)(*a4 - this->error.x)
                                                                                      * (float)(*a4 - this->error.x))
                                                                              + (float)((float)v5 * (float)v5)))
                                                              * (float)0.5))
                                              * (float)v10)
                                      - (float)1.5)
                      * (float)v10));
  v12 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)(*a4 - this->error.x) * (float)(*a4 - this->error.x)) + (float)((float)v5 * (float)v5))) * (float)0.5)) * (float)v10) - (float)1.5)
                                                                                      * (float)v10)
                                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                                              + (float)((float)((float)(*a4 - this->error.x) * (float)(*a4 - this->error.x)) + (float)((float)v5 * (float)v5)))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v10 * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)(*a4 - this->error.x) * (float)(*a4 - this->error.x)) + (float)((float)v5 * (float)v5))) * (float)0.5)) * (float)v10)
                                                                                              - (float)1.5)
                                                                              * (float)v10))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)(*a4 - this->error.x) * (float)(*a4 - this->error.x)) + (float)((float)v5 * (float)v5)))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10))
                                      * (float)((float)((float)((float)v7 * (float)v7)
                                                      + (float)((float)((float)(*a4 - this->error.x)
                                                                      * (float)(*a4 - this->error.x))
                                                              + (float)((float)v5 * (float)v5)))
                                              * (float)0.5))
                              * (float)v11)
                      - (float)1.5);
  v13 = (float)((float)v12
              * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v10
                                                                                              * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)(*a4 - this->error.x) * (float)(*a4 - this->error.x)) + (float)((float)v5 * (float)v5))) * (float)0.5))
                                                                                      * (float)v10)
                                                                              - (float)1.5)
                                                              * (float)v10)
                                                      * (float)((float)((float)((float)v7 * (float)v7)
                                                                      + (float)((float)((float)(*a4 - this->error.x)
                                                                                      * (float)(*a4 - this->error.x))
                                                                              + (float)((float)v5 * (float)v5)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v10
                                                                                      * (float)((float)((float)((float)v7 * (float)v7) + (float)((float)((float)(*a4 - this->error.x) * (float)(*a4 - this->error.x)) + (float)((float)v5 * (float)v5)))
                                                                                              * (float)0.5))
                                                                              * (float)v10)
                                                                      - (float)1.5)
                                                      * (float)v10))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v10
                                                              * (float)((float)((float)((float)v7 * (float)v7)
                                                                              + (float)((float)((float)(*a4 - this->error.x)
                                                                                              * (float)(*a4 - this->error.x))
                                                                                      + (float)((float)v5 * (float)v5)))
                                                                      * (float)0.5))
                                                      * (float)v10)
                                              - (float)1.5)
                              * (float)v10)));
  v14 = (float)((float)v13
              * (float)((float)((float)v7 * (float)v7)
                      + (float)((float)((float)(*a4 - this->error.x) * (float)(*a4 - this->error.x))
                              + (float)((float)v5 * (float)v5))));
  v15 = (float)((float)(*a4 - this->error.x) * (float)v13);
  v16 = (float)((float)(a4[1] - this->error.y) * (float)v13);
  v17 = (float)((float)v13 * (float)(a4[2] - this->error.z));
  if ( v14 <= rate )
  {
    this->error.x = *a4;
    this->error.y = a4[1];
    this->error.z = a4[2];
  }
  else
  {
    this->error.z = this->error.z + (float)((float)v17 * (float)rate);
    this->error.x = (float)x + (float)((float)v15 * (float)rate);
    this->error.y = (float)y + (float)((float)v16 * (float)rate);
  }
}


// ========================================================================
// ?AddWeaponFireKickbackImpulse@idWanderingAim@@QAAXPBVidAI2@@PBVidWeapon@@@Z
// EA  : 0x82B2BC50
// RVA : 0x00B2BC50
// PDB : w:\tech5\tungsten\game\ai\wanderingaim.cpp
// ========================================================================

void __fastcall idWanderingAim::AddWeaponFireKickbackImpulse(idWanderingAim *this, idAI2 *ai, const idWeapon *weapon)
{
  const idDeclInventory *decl; // r30
  double v5; // fp12
  unsigned int v6; // r3
  __int64 v7; // r7
  unsigned int v8; // r9
  __int128 v9; // r4
  double v10; // fp10
  double x; // fp7
  double y; // fp6

  if ( weapon != nullptr )
  {
    decl = weapon->decl;
    v5 = *((float *)&decl[2].networkID + 8 * idAI2::GetEffectiveAccuracy(this: ai));
    v6 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v6;
    HIDWORD(v7) = (v6 >> 10) & 0x7FFF;
    LODWORD(v7) = HIDWORD(v7);
    v8 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v8;
    DWORD2(v9) = (v8 >> 10) & 0x7FFF;
    v10 = (float)((float)((float)v7 * (float)0.000061037019) - (float)1.0);
    HIDWORD(v7) = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = HIDWORD(v7);
    x = this->error.x;
    LODWORD(v9) = (HIDWORD(v7) >> 10) & 0x7FFF;
    y = this->error.y;
    this->error.z = this->error.z + (float)((float)v10 * (float)v5);
    this->error.y = (float)y
                  + (float)((float)((float)((float)*(__int64 *)((char *)&v9 + 4) * (float)0.000061037019) - (float)1.0)
                          * (float)v5);
    this->error.x = (float)x
                  + (float)((float)((float)((float)(__int64)v9 * (float)0.000061037019) - (float)1.0) * (float)v5);
  }
}


// ========================================================================
// ?SmoothWander@idWanderingAim@@AAAXMM@Z
// EA  : 0x82B2BD90
// RVA : 0x00B2BD90
// PDB : w:\tech5\tungsten\game\ai\wanderingaim.cpp
// ========================================================================

void __fastcall idWanderingAim::SmoothWander(idWanderingAim *this, double scale, double maxDivergence)
{
  long double v6; // fp2
  long double v7; // fp2
  double v8; // fp30
  long double v9; // fp2
  long double v10; // fp2
  double z; // fp0
  double v12; // fp13
  double v13; // fp13
  double v14; // fp11
  double v15; // fp12
  double v18; // fp5
  double v19; // fp1
  double v20; // fp12

  *(double *)&v6 = (float)((float)__SPAIR64__(
                                    &off_82040000,
                                    idGameTimeManager::GetGameMs(
                                      this: &clientGame->gameTimeManager,
                                      type: GAMETIME_SCALED))
                         * (float)0.001);
  v7 = cos(x: v6);
  v8 = (float)((float)*(double *)&v7 * (float)scale);
  *(double *)&v9 = (float)((float)__SPAIR64__(
                                    "Could not find AI state, idVS_ds_Car_Chase! ",
                                    idGameTimeManager::GetGameMs(
                                      this: &clientGame->gameTimeManager,
                                      type: GAMETIME_SCALED))
                         * (float)0.0042300001);
  v10 = cos(x: v9);
  z = this->error.z;
  v12 = (float)((float)*(double *)&v10 * (float)scale);
  if ( (float)((float)(this->error.z * (float)0.0)
             + (float)((float)(this->error.y * (float)((float)*(double *)&v10 * (float)scale))
                     + (float)(this->error.x * (float)v8))) < 0.0 )
  {
    v8 = (float)((float)v8 * (float)0.19999999);
    v12 = (float)((float)((float)*(double *)&v10 * (float)scale) * (float)0.19999999);
  }
  v13 = (float)(this->error.y + (float)v12);
  v14 = (float)(this->error.x + (float)v8);
  this->error.x = this->error.x + (float)v8;
  this->error.y = v13;
  this->error.z = z;
  v15 = (float)((float)((float)z * (float)z)
              + (float)((float)((float)v13 * (float)v13) + (float)((float)v14 * (float)v14)));
  if ( v15 > (float)((float)maxDivergence * (float)maxDivergence) )
  {
    _FP8 = (float)((float)((float)((float)z * (float)z)
                         + (float)((float)((float)v13 * (float)v13) + (float)((float)v14 * (float)v14)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f6, f8, f12, f10 }
    v18 = __frsqrte(_FP6);
    v19 = (float)((float)-(float)((float)((float)((float)v18
                                                * (float)((float)((float)((float)z * (float)z)
                                                                + (float)((float)((float)v13 * (float)v13)
                                                                        + (float)((float)v14 * (float)v14)))
                                                        * (float)0.5))
                                        * (float)v18)
                                - (float)1.5)
                * (float)v18);
    v20 = (float)((float)((float)-(float)((float)((float)((float)v18 * (float)((float)v15 * (float)0.5)) * (float)v18)
                                        - (float)1.5)
                        * (float)v18)
                * (float)((float)v15 * (float)0.5));
    this->error.y = (float)((float)v13
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v20
                                                                                                  * (float)v19)
                                                                                          - (float)1.5)
                                                                          * (float)v19)
                                                                  * (float)((float)((float)((float)z * (float)z)
                                                                                  + (float)((float)((float)v13
                                                                                                  * (float)v13)
                                                                                          + (float)((float)v14
                                                                                                  * (float)v14)))
                                                                          * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)v20 * (float)v19)
                                                                                  - (float)1.5)
                                                                  * (float)v19))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)v20 * (float)v19) - (float)1.5) * (float)v19)))
                  * (float)maxDivergence;
    this->error.z = (float)((float)z
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v20
                                                                                                  * (float)v19)
                                                                                          - (float)1.5)
                                                                          * (float)v19)
                                                                  * (float)((float)((float)((float)z * (float)z)
                                                                                  + (float)((float)((float)v13
                                                                                                  * (float)v13)
                                                                                          + (float)((float)v14
                                                                                                  * (float)v14)))
                                                                          * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)v20 * (float)v19)
                                                                                  - (float)1.5)
                                                                  * (float)v19))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)v20 * (float)v19) - (float)1.5) * (float)v19)))
                  * (float)maxDivergence;
    this->error.x = (float)((float)v14
                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v20
                                                                                                  * (float)v19)
                                                                                          - (float)1.5)
                                                                          * (float)v19)
                                                                  * (float)((float)((float)((float)z * (float)z)
                                                                                  + (float)((float)((float)v13
                                                                                                  * (float)v13)
                                                                                          + (float)((float)v14
                                                                                                  * (float)v14)))
                                                                          * (float)0.5))
                                                          * (float)((float)-(float)((float)((float)v20 * (float)v19)
                                                                                  - (float)1.5)
                                                                  * (float)v19))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)v20 * (float)v19) - (float)1.5) * (float)v19)))
                  * (float)maxDivergence;
  }
}


// ========================================================================
// ?GetEffectiveWeapon@idWanderingAim@@AAAPAVidWeapon@@PBVidAI2@@@Z
// EA  : 0x82B2BF30
// RVA : 0x00B2BF30
// PDB : w:\tech5\tungsten\game\ai\wanderingaim.cpp
// ========================================================================

idWeapon *__fastcall idWanderingAim::GetEffectiveWeapon(idWanderingAim *this, const idAI2 *ai)
{
  idWeapon *v3; // r31
  int value; // r6
  idEntity *v5; // r3
  idProp_WeaponStatic *v6; // r3
  idProp_WeaponStatic *v7; // r3

  v3 = ai->GetEquippedWeapon(this: ai);
  value = ai->aiVolatile.memory.usedProp.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = (idProp_WeaponStatic *)idEntity::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  v7 = idProp_WeaponStatic::CastTo(c: v6);
  if ( v7 != nullptr )
    return v7->weapon;
  else
    return v3;
}


// ========================================================================
// ?Diverge@idWanderingAim@@QAAXPBVidAI2@@@Z
// EA  : 0x82B2BFE0
// RVA : 0x00B2BFE0
// PDB : w:\tech5\tungsten\game\ai\wanderingaim.cpp
// ========================================================================

void __fastcall idWanderingAim::Diverge(idWanderingAim *this, idAI2 *ai)
{
  idWeapon *EffectiveWeapon; // r29
  __int32 v5; // r31

  EffectiveWeapon = idWanderingAim::GetEffectiveWeapon(this, ai);
  if ( EffectiveWeapon != nullptr )
  {
    v5 = (__int32)EffectiveWeapon->decl + 32 * idAI2::GetEffectiveAccuracy(this: ai);
    this->lastTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idWanderingAim::SmoothWander(this, scale: *(float *)(v5 + 1036), maxDivergence: *(float *)(v5 + 1036));
  }
}


// ========================================================================
// ?Update@idWanderingAim@@QAAXPBVidAI2@@ABVidVec3@@1MAAV3@_N@Z
// EA  : 0x82B2C050
// RVA : 0x00B2C050
// PDB : w:\tech5\tungsten\game\ai\wanderingaim.cpp
// ========================================================================

void __fastcall idWanderingAim::Update(
        idWanderingAim *this,
        idAI2 *ai,
        const idVec3 *eyePos,
        const idVec3 *dirToTarget,
        double distToTarget,
        idVec3 *newFocusPoint,
        float *showDebug,
        unsigned __int8 a8)
{
  int v8; // r21
  double v9; // fp10
  double v10; // fp9
  double y; // fp7
  double z; // fp6
  idWeapon *EffectiveWeapon; // r30
  __int32 v20; // r25
  const idVec3 *v21; // r4
  bool v22; // r23
  int GameMs; // r20
  double v24; // fp7
  double v25; // fp6
  coverAction_t coverAction; // r11
  unsigned __int8 v27; // r11
  bool v28; // zf
  int v29; // r30
  int v30; // r11
  idPhysics *Physics; // r3
  float *v32; // r3
  double v33; // fp0
  double v34; // fp13
  double x; // fp12
  float v36; // r6
  float v37; // r8
  double v38; // fp28
  double v39; // fp30
  double v40; // fp29
  double v41; // fp0
  double v42; // fp12
  double v43; // fp11
  double v44; // fp13
  idColor *r_low; // r9
  float r; // r8
  float b; // r6
  float a; // r5
  idVec3 v49; // [sp+50h] [-E0h] BYREF
  idVec3 v50; // [sp+60h] [-D0h] BYREF
  idColor v51; // [sp+70h] [-C0h] BYREF
  idMat3 v52; // [sp+80h] [-B0h] BYREF

  v8 = a8;
  v9 = (float)(dirToTarget->y * (float)distToTarget);
  v10 = (float)(dirToTarget->z * (float)distToTarget);
  y = eyePos->y;
  z = eyePos->z;
  *showDebug = eyePos->x + (float)(dirToTarget->x * (float)distToTarget);
  showDebug[1] = (float)y + (float)v9;
  showDebug[2] = (float)z + (float)v10;
  if ( a8 != 0 )
    ((void (__fastcall *)(idRenderWorld *, idColor *))clientGame->renderWorld->DebugLine)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorYellow);
  EffectiveWeapon = idWanderingAim::GetEffectiveWeapon(this, ai);
  if ( EffectiveWeapon == nullptr )
    return;
  v20 = (__int32)EffectiveWeapon->decl + 32 * idAI2::GetEffectiveAccuracy(this: ai);
  if ( idAI2::GetAlertCycle(this: ai) != ALERTCYCLE_COMBAT )
  {
    this->error.z = 0.0;
    this->error.y = 0.0;
    this->error.x = 0.0;
    return;
  }
  v22 = false;
  if ( EffectiveWeapon->decl[3].hasBeenParsedAtLeastOnce
    && idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX) != nullptr )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( GameMs - idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX)->lastConfirmedStimTime < 1000
      && EffectiveWeapon->fireState != FIRESTATE_RELOADING
      && idAI2::GetMuzzlePoint(this: ai, weapon: EffectiveWeapon, muzzlePos: &v50, muzzleAxis: &v52) )
    {
      v24 = (float)(ai->aiVolatile.focus.foci.ptr[0].curFocusPoint.y - v50.y);
      v25 = (float)(ai->aiVolatile.focus.foci.ptr[0].curFocusPoint.z - v50.z);
      v49.x = ai->aiVolatile.focus.foci.ptr[0].curFocusPoint.x - v50.x;
      v49.y = v24;
      v49.z = v25;
      idVec3::NormalizeFast(this: &v49);
      v22 = (float)((float)(v52.mat[0].x * v49.x)
                  + (float)((float)(v52.mat[0].z * v49.z) + (float)(v52.mat[0].y * v49.y))) > 0.89999998;
    }
  }
  coverAction = ai->aiVolatile.cover.coverAction;
  if ( coverAction == COVERACTION_BLINDFIRE_LEFT
    || coverAction == COVERACTION_BLINDFIRE_RIGHT
    || (v28 = coverAction != COVERACTION_BLINDFIRE_OVER, v27 = 0, !v28) )
  {
    v27 = 1;
  }
  v29 = v27;
  if ( v27 == 0
    && (v22
     || idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
      - ai->aiVolatile.memory.lastFireTime < *(_DWORD *)(v20 + 1052)) )
  {
    if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->lastTime <= *(_DWORD *)(v20 + 1048) )
      goto LABEL_24;
    goto LABEL_20;
  }
  if ( v29 == 0 && ai->aiVolatile.memory.numShotsThisPullBlockedConsecutive > 0 )
  {
LABEL_20:
    idWanderingAim::ConvergeTo(this, rate: *(float *)(v20 + 1040), convergeTo: v21, a4: &vec3_origin.x);
    goto LABEL_24;
  }
  idWanderingAim::SmoothWander(this, scale: *(float *)(v20 + 1044), maxDivergence: *(float *)(v20 + 1036));
  this->lastTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
LABEL_24:
  if ( ((LODWORD(this->error.y) | LODWORD(this->error.z) | LODWORD(this->error.x)) & 0x7FFFFFFF) != 0 )
    v30 = 0;
  else
    v30 = this->convergeTime
        + idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->convergeTime = v30;
  Physics = idEntity::GetPhysics(this: ai);
  v32 = (float *)Physics->GetGravityNormal(this: Physics);
  v33 = dirToTarget->z;
  v34 = dirToTarget->y;
  x = dirToTarget->x;
  v36 = *v32;
  v37 = v32[1];
  v49.z = v32[2];
  v38 = v49.z;
  v39 = v36;
  v40 = v37;
  v49.y = (float)((float)x * v49.z) - (float)((float)v33 * v36);
  v49.x = (float)((float)v33 * v37) - (float)((float)v34 * v49.z);
  v49.z = (float)((float)v34 * v36) - (float)((float)x * v37);
  idVec3::NormalizeFast(this: &v49);
  v41 = showDebug[1];
  v42 = showDebug[2];
  v43 = (float)((float)((float)((float)v38 * this->error.y) + (float)(v49.z * this->error.x)) * (float)distToTarget);
  v44 = (float)((float)((float)((float)v40 * this->error.y) + (float)(v49.y * this->error.x)) * (float)distToTarget);
  *showDebug = *showDebug
             + (float)((float)((float)((float)v39 * this->error.y) + (float)(v49.x * this->error.x))
                     * (float)distToTarget);
  showDebug[2] = (float)v43 + (float)v42;
  showDebug[1] = (float)v41 + (float)v44;
  if ( v8 != 0 )
  {
    r_low = &idColor::colorOrange;
    v51 = idColor::colorOrange;
    if ( v29 != 0 )
    {
      r_low = &idColor::colorLtGrey;
      r = idColor::colorLtGrey.r;
LABEL_36:
      b = r_low->b;
      a = r_low->a;
      v51.g = r_low->g;
      v51.r = r;
      v51.b = b;
      v51.a = a;
      goto LABEL_37;
    }
    if ( v22 )
    {
      if ( ((LODWORD(this->error.y) | LODWORD(this->error.z) | LODWORD(this->error.x)) & 0x7FFFFFFF) != 0 )
      {
        r_low = &idColor::colorRed;
        r = idColor::colorRed.r;
        goto LABEL_36;
      }
      if ( this->convergeTime >= *(_DWORD *)(v20 + 1056) )
      {
        r_low = &idColor::colorGreen;
        r = idColor::colorGreen.r;
        goto LABEL_36;
      }
      r_low = (idColor *)LODWORD(idColor::colorOrange.r);
      v51 = idColor::colorOrange;
    }
LABEL_37:
    ((void (__fastcall *)(idRenderWorld *, idColor *, const idVec3 *, float *, int, int, idColor *))clientGame->renderWorld->DebugLine)(
      a1: clientGame->renderWorld,
      a2: &v51,
      a3: eyePos,
      a4: showDebug,
      a5: 1,
      a6: 1,
      a7: r_low);
  }
}

