
// ========================================================================
// ?Init@idWeaponTraceManager@@QAAXXZ
// EA  : 0x82719000
// RVA : 0x00719000
// PDB : w:\tech5\engine\gamelib\effects\weapontracemanager.cpp
// ========================================================================

void __fastcall idWeaponTraceManager::Init(idWeaponTraceManager *this)
{
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weaponTraces[1]);
  this->currentDeferred = 0;
}


// ========================================================================
// ?Update@idWeaponTraceManager@@QAAXXZ
// EA  : 0x82719040
// RVA : 0x00719040
// PDB : w:\tech5\engine\gamelib\effects\weapontracemanager.cpp
// ========================================================================

void __fastcall idWeaponTraceManager::Update(idWeaponTraceManager *this)
{
  int v1; // r10

  v1 = this->currentDeferred ^ 1;
  this->currentDeferred = v1;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weaponTraces[v1]);
}


// ========================================================================
// ??0idWeaponTraceManager@@QAA@XZ
// EA  : 0x827190C8
// RVA : 0x007190C8
// PDB : w:\tech5\engine\gamelib\effects\weapontracemanager.cpp
// ========================================================================

idWeaponTraceManager *__fastcall idWeaponTraceManager::idWeaponTraceManager(idWeaponTraceManager *this)
{
  `eh vector constructor iterator'(
    ptr: this,
    size: 0x1A8u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idStaticList<weaponTrace_t,6>::idStaticList<weaponTrace_t,6>,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  this->currentDeferred = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->weaponTraces[1]);
  this->currentDeferred = 0;
  return this;
}


// ========================================================================
// __unwind$246501
// EA  : 0x82719124
// RVA : 0x00719124
// PDB : w:\tech5\engine\gamelib\effects\weapontracemanager.cpp
// ========================================================================

void _unwind_246501()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: *(void **)(v0 - 112 + 132),
    size: 0x1A8u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ?AddTrace@idWeaponTraceManager@@QAAXABVidVec3@@0VidSpawnId@@PBVidDeclDamage@@@Z
// EA  : 0x82719368
// RVA : 0x00719368
// PDB : w:\tech5\engine\gamelib\effects\weapontracemanager.cpp
// ========================================================================

void __fastcall idWeaponTraceManager::AddTrace(
        idWeaponTraceManager *this,
        const idVec3 *start,
        const idVec3 *end,
        const idSpawnId *spawnId,
        const idDeclDamage *damage)
{
  idList<weaponTrace_t,5> *v7; // r3
  weaponTrace_t *v10; // r3

  v7 = &this->weaponTraces[this->currentDeferred];
  if ( v7->num < 6 )
  {
    v10 = idList<weaponTrace_t,5>::Alloc(this: v7);
    v10->start.x = start->x;
    v10->start.y = start->y;
    v10->start.z = start->z;
    v10->end = *end;
    v10->attacker.value = (int)spawnId;
    v10->radius = 0.0;
    v10->damageDecl = damage;
    v10->weaponTraceType = WEAPON_TRACE_BULLET;
  }
}


// ========================================================================
// ?AddExplosion@idWeaponTraceManager@@QAAXABVidVec3@@MVidSpawnId@@PBVidDeclDamage@@@Z
// EA  : 0x827193F8
// RVA : 0x007193F8
// PDB : w:\tech5\engine\gamelib\effects\weapontracemanager.cpp
// ========================================================================

void __fastcall idWeaponTraceManager::AddExplosion(
        idWeaponTraceManager *this,
        const idVec3 *origin,
        double radius,
        const idSpawnId *attacker,
        const idDeclDamage *damage,
        const idDeclDamage *a6)
{
  idList<weaponTrace_t,5> *v9; // r3
  weaponTrace_t *v11; // r3
  double z; // fp12

  v9 = &this->weaponTraces[this->currentDeferred];
  if ( v9->num < 6 )
  {
    v11 = idList<weaponTrace_t,5>::Alloc(this: v9);
    v11->start.x = origin->x;
    v11->start.y = origin->y;
    z = origin->z;
    v11->attacker.value = (int)damage;
    v11->start.z = z;
    v11->damageDecl = a6;
    v11->radius = radius;
    v11->weaponTraceType = WEAPON_TRACE_EXPLOSION;
  }
}


// ========================================================================
// ?AddProjectile@idWeaponTraceManager@@QAAXABVidVec3@@MVidSpawnId@@1PBVidDeclDamage@@@Z
// EA  : 0x82719470
// RVA : 0x00719470
// PDB : w:\tech5\engine\gamelib\effects\weapontracemanager.cpp
// ========================================================================

void __fastcall idWeaponTraceManager::AddProjectile(
        idWeaponTraceManager *this,
        const idVec3 *origin,
        double radius,
        const idSpawnId *attacker,
        const idSpawnId *projectile,
        const idDeclDamage *damage,
        const idDeclDamage *a7)
{
  idList<weaponTrace_t,5> *v10; // r3
  weaponTrace_t *v13; // r3
  double z; // fp12

  v10 = &this->weaponTraces[this->currentDeferred];
  if ( v10->num < 6 )
  {
    v13 = idList<weaponTrace_t,5>::Alloc(this: v10);
    v13->start.x = origin->x;
    v13->start.y = origin->y;
    z = origin->z;
    v13->attacker.value = (int)projectile;
    v13->start.z = z;
    v13->projectile.value = (int)damage;
    v13->radius = radius;
    v13->damageDecl = a7;
    v13->weaponTraceType = WEAPON_TRACE_PROJECTILE;
  }
}


// ========================================================================
// ?GetCollisions@idWeaponTraceManager@@QAA?BHABVidBounds@@AAV?$idList@UweaponTrace_t@@$04@@@Z
// EA  : 0x827194F0
// RVA : 0x007194F0
// PDB : w:\tech5\engine\gamelib\effects\weapontracemanager.cpp
// ========================================================================

int __fastcall idWeaponTraceManager::GetCollisions(
        idWeaponTraceManager *this,
        const idBounds *inBounds,
        idList<idVehicleState *,5> *outTraces)
{
  int v6; // r29
  char *v7; // r10
  _DWORD *p_z; // r11
  int i; // ctr
  idRenderWorld *v10; // r3
  idStaticList<weaponTrace_t,6> *v11; // r26
  int v12; // r20
  int v13; // r24
  weaponTrace_t *v14; // r31
  weaponTrace_t::weaponTraceType_t weaponTraceType; // r11
  double v16; // fp30
  const idVec3 *p_start; // r4
  double v18; // fp29
  double v19; // fp28
  weaponTrace_t *v20; // r30
  double v21; // fp1
  int v22; // r3
  double radius; // fp13
  weaponTrace_t *v24; // r3
  double v25; // fp5
  double v26; // fp2
  double z; // fp6
  double v28; // fp5
  double v29; // fp3
  double v30; // fp2
  double v31; // fp13
  double v32; // fp9
  double v35; // fp7
  double v36; // fp5
  double v37; // fp9
  double v38; // fp7
  idRenderWorld *v39; // r3
  double v40; // fp0
  int v41; // r7
  float *v42; // r5
  float *v43; // r4
  double v44; // fp13
  weaponTrace_t *v45; // r3
  double v46; // fp0
  float v48[3]; // [sp+50h] [-170h] BYREF
  char v49; // [sp+5Ch] [-164h] BYREF
  idBounds v50; // [sp+60h] [-160h] BYREF
  idVec3 v51; // [sp+78h] [-148h] BYREF
  float v52[4]; // [sp+90h] [-130h] BYREF
  idSphere v53; // [sp+A0h] [-120h] BYREF
  idSphere v54; // [sp+B0h] [-110h] BYREF
  float v55[4]; // [sp+C0h] [-100h] BYREF
  float v56[4]; // [sp+D0h] [-F0h] BYREF
  float v57[4]; // [sp+E0h] [-E0h] BYREF
  float v58[4]; // [sp+F0h] [-D0h] BYREF
  float v59[20]; // [sp+100h] [-C0h] BYREF

  v6 = this->currentDeferred ^ 1;
  idList<idThread *,58>::Clear(this: outTraces);
  v7 = &v49;
  p_z = (_DWORD *)&inBounds[-1].b[1].z;
  for ( i = 6; i != 0; --i )
  {
    ++p_z;
    v7 += 4;
    *(_DWORD *)v7 = *p_z;
  }
  if ( debug_weaponTrace.valueInteger != 0 )
  {
    v10 = common->RW(this: common);
    v58[0] = 1.0;
    v58[1] = 1.0;
    v58[2] = 1.0;
    v58[3] = 1.0;
    v10->DebugBounds(this: v10, a2: (const idVec4 *)v58, a3: &v50, a4: &vec3_origin, a5: 0, a6: false);
  }
  v11 = &this->weaponTraces[v6];
  v12 = 0;
  if ( v11->num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = &v11->list[v13];
      weaponTraceType = v14->weaponTraceType;
      switch ( weaponTraceType )
      {
        case WEAPON_TRACE_BULLET:
          v16 = (float)(v14->end.x - v14->start.x);
          p_start = &v11->list[v13].start;
          v18 = (float)(v14->end.y - v14->start.y);
          v19 = (float)(v14->end.z - v14->start.z);
          v51.x = v14->end.x - v14->start.x;
          v51.y = v18;
          v51.z = v19;
          if ( (unsigned __int8)idBounds::RayIntersection(this: &v50, start: p_start, dir: &v51, scale: v48) != 0
            && v48[0] >= 0.0
            && v48[0] < 1.0 )
          {
            v20 = idList<weaponTrace_t,5>::Alloc(this: (idList<weaponTrace_t,5> *)outTraces);
            v20->start.x = v14->start.x;
            v20->start.y = v14->start.y;
            v20->start.z = v14->start.z;
            v20->end = v14->end;
            v20->impactPoint = v14->impactPoint;
            v20->dir.x = v16;
            v20->dir.y = v18;
            v20->dir.z = v19;
            v21 = idVec3::NormalizeFast(this: &v20->dir);
            v20->radius = 0.0;
            v20->attacker.value = v14->attacker.value;
            v20->projectile.value = v14->projectile.value;
            v20->damageDecl = v14->damageDecl;
            v20->weaponTraceType = WEAPON_TRACE_BULLET;
            if ( debug_weaponTrace.valueInteger != 0 )
            {
              v22 = ((int (__fastcall *)(idCommon *, double))common->RW)(a1: common, a2: v21);
              v59[2] = 0.0;
              v59[3] = 1.0;
              v59[0] = 0.0;
              v59[1] = 1.0;
              (*(void (__fastcall **)(int, float *, weaponTrace_t *, idVec3 *, int, _DWORD))(*(_DWORD *)v22 + 176))(
                a1: v22,
                a2: v59,
                a3: v14,
                a4: &v14->end,
                a5: 3000,
                a6: 0);
            }
          }
          goto LABEL_22;
        case WEAPON_TRACE_EXPLOSION:
          radius = v14->radius;
          v54.origin.x = v14->start.x;
          v54.origin.y = v14->start.y;
          v54.origin.z = v14->start.z;
          v54.radius = radius;
          if ( !idBounds::SphereIntersection(this: &v50, s: &v54) )
            goto LABEL_22;
          v24 = idList<weaponTrace_t,5>::Alloc(this: (idList<weaponTrace_t,5> *)outTraces);
          v24->start.x = v14->start.x;
          v24->start.y = v14->start.y;
          v24->start.z = v14->start.z;
          v25 = (float)(v50.b[0].z + v50.b[1].z);
          v26 = (float)(v50.b[0].x + v50.b[1].x);
          v24->end.y = (float)(v50.b[0].y + v50.b[1].y) * (float)0.5;
          v24->end.z = (float)v25 * (float)0.5;
          v24->end.x = (float)v26 * (float)0.5;
          v24->impactPoint.x = (float)v26 * (float)0.5;
          v24->impactPoint.y = v24->end.y;
          v24->impactPoint.z = v24->end.z;
          z = v24->end.z;
          v28 = v24->start.z;
          v29 = (float)(v24->end.y - v24->start.y);
          v30 = (float)(v24->end.x - v24->start.x);
          v24->dir.y = v24->end.y - v24->start.y;
          v24->dir.x = v30;
          v24->dir.z = (float)z - (float)v28;
          v31 = (float)((float)z - (float)v28);
          v32 = (float)((float)((float)((float)z - (float)v28) * (float)((float)z - (float)v28))
                      + (float)((float)((float)v30 * (float)v30) + (float)((float)v29 * (float)v29)));
          _FP8 = (float)((float)((float)((float)((float)z - (float)v28) * (float)((float)z - (float)v28))
                               + (float)((float)((float)v30 * (float)v30) + (float)((float)v29 * (float)v29)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f6, f8, f9, f0 }
          v35 = (float)((float)v32 * (float)0.5);
          v36 = __frsqrte(_FP6);
          v37 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v36
                                                                                              * (float)((float)v32 * (float)0.5))
                                                                                      * (float)v36)
                                                                              - (float)1.5)
                                                              * (float)v36)
                                                      * (float)((float)v32 * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v36
                                                                                      * (float)((float)v32 * (float)0.5))
                                                                              * (float)v36)
                                                                      - (float)1.5)
                                                      * (float)v36))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v36 * (float)((float)v32 * (float)0.5))
                                                      * (float)v36)
                                              - (float)1.5)
                              * (float)v36));
          v38 = (float)-(float)((float)((float)((float)v37 * (float)v35) * (float)v37) - (float)1.5);
          v24->dir.x = (float)((float)v38 * (float)v37) * (float)v30;
          v24->dir.y = (float)((float)v38 * (float)v37) * (float)v29;
          v24->dir.z = (float)((float)v38 * (float)v37) * (float)v31;
          v24->radius = v14->radius;
          v24->attacker.value = v14->attacker.value;
          v24->projectile.value = v14->projectile.value;
          v24->damageDecl = v14->damageDecl;
          v24->weaponTraceType = WEAPON_TRACE_EXPLOSION;
          if ( debug_weaponTrace.valueInteger == 0 )
            goto LABEL_22;
          v39 = common->RW(this: common);
          v40 = v14->radius;
          v41 = 3000;
          v42 = v52;
          v52[0] = v14->start.x;
          v43 = v56;
          v52[1] = v14->start.y;
          v52[2] = v14->start.z;
          v56[2] = 0.0;
          v56[3] = 1.0;
          v52[3] = v40;
          v56[0] = 0.0;
          v56[1] = 1.0;
          break;
        case WEAPON_TRACE_PROJECTILE:
          v44 = v14->radius;
          v53.origin.x = v14->start.x;
          v53.origin.y = v14->start.y;
          v53.origin.z = v14->start.z;
          v53.radius = v44;
          if ( !idBounds::SphereIntersection(this: &v50, s: &v53) )
            goto LABEL_22;
          v45 = idList<weaponTrace_t,5>::Alloc(this: (idList<weaponTrace_t,5> *)outTraces);
          v45->start.x = v14->start.x;
          v45->start.y = v14->start.y;
          v45->start.z = v14->start.z;
          v45->end = v14->start;
          v45->impactPoint = v14->start;
          v45->dir.y = 0.0;
          v45->dir.z = 0.0;
          v45->dir.x = 0.0;
          v45->radius = v14->radius;
          v45->attacker.value = v14->attacker.value;
          v45->projectile.value = v14->projectile.value;
          v45->damageDecl = v14->damageDecl;
          v45->weaponTraceType = WEAPON_TRACE_PROJECTILE;
          if ( debug_weaponTrace.valueInteger == 0 )
            goto LABEL_22;
          v39 = common->RW(this: common);
          v46 = v14->radius;
          v41 = 0;
          v42 = v57;
          v57[0] = v14->start.x;
          v43 = v55;
          v57[1] = v14->start.y;
          v57[2] = v14->start.z;
          v55[0] = 0.0;
          v55[2] = 0.0;
          v55[1] = 1.0;
          v55[3] = 1.0;
          v57[3] = v46;
          break;
        default:
          goto LABEL_22;
      }
      v39->DebugSphere(this: v39, a2: (const idVec4 *)v43, a3: (const idSphere *)v42, a4: 12, a5: v41, a6: false);
LABEL_22:
      ++v12;
      ++v13;
    }
    while ( v12 < v11->num );
  }
  return outTraces->num;
}


// ========================================================================
// `dynamic initializer for 'debug_weaponTrace''
// EA  : 0x8333FA90
// RVA : 0x0133FA90
// PDB : w:\tech5\engine\gamelib\effects\weapontracemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__debug_weaponTrace__()
{
  idCVar::idCVar(
    this: &debug_weaponTrace,
    name: "debug_weaponTrace",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__debug_weaponTrace__);
}

