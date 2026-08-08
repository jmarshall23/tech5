
// ========================================================================
// ??0idEntityParticle@@QAA@XZ
// EA  : 0x82C483E0
// RVA : 0x00C483E0
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

idEntityParticle *__fastcall idEntityParticle::idEntityParticle(idEntityParticle *this)
{
  float z; // r4
  float v4; // r5

  idEntity::idEntity(this);
  this->__vftable = (idEntityParticle_vtbl *)&idEntityParticle::`vftable';
  this->emitTime = 0.0;
  this->state = 0;
  this->nextSoundTime = 0.0;
  this->vel = vec3_origin;
  this->rotationAxis.x = vec3_origin.x;
  this->rotationAxis.y = vec3_origin.y;
  z = vec3_origin.z;
  this->rotationSpeed = 0.0;
  this->rotationAxis.z = z;
  this->lastCollisionPos = vec3_origin;
  this->lastCollisionNormal.x = vec3_origin.x;
  this->lastCollisionNormal.y = vec3_origin.y;
  v4 = vec3_origin.z;
  this->fovScale = 1.0;
  this->modelDepthHack = 0.0;
  this->lastCollisionNormal.z = v4;
  return this;
}


// ========================================================================
// ?Spawn@idEntityParticle@@QAAXXZ
// EA  : 0x82C484C0
// RVA : 0x00C484C0
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void __fastcall idEntityParticle::Spawn(idEntityParticle *this)
{
  idPhysics *Physics; // r3

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  idEntity::BecomeInactive(this, flags: 7);
  this->Hide_2(this);
}


// ========================================================================
// ?RunState_Fade@idEntityEmitter@@QAA_NPAVidEntityParticle@@@Z
// EA  : 0x82C48528
// RVA : 0x00C48528
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

int __fastcall idEntityEmitter::RunState_Fade(idEntityEmitter *this, idEntityParticle *particle)
{
  __int64 v4; // r8
  int numParticlesInUse; // r8

  LODWORD(v4) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  if ( (float)v4 < (double)(float)((float)(particle->emitTime + this->particleFadeTime) + this->particleLifespan) )
    return 1;
  particle->state = 0;
  idEntity::BecomeInactive(this: particle, flags: 7);
  particle->Hide_2(this: particle);
  numParticlesInUse = this->numParticlesInUse;
  this->numParticlesInUse = numParticlesInUse - 1;
  if ( numParticlesInUse == 1 )
    idEntity::BecomeInactive(this, flags: 7);
  return 0;
}


// ========================================================================
// ?RunPhysics@idEntityEmitter@@QAAXPAVidEntityParticle@@@Z
// EA  : 0x82C486D0
// RVA : 0x00C486D0
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEntityEmitter::RunPhysics(idEntityEmitter *this, idEntityParticle *particle)
{
  idPhysics *Physics; // r21
  idVec3 *p_gravity; // r7
  double y; // fp7
  double z; // fp6
  idVec3 *p_vel; // r30
  double v9; // fp22
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  double v11; // fp4
  double v12; // fp3
  float *v13; // r3
  double v14; // fp9
  double v15; // fp8
  const idVec3 *v16; // r25
  double v17; // fp7
  double v18; // fp6
  idPhysics *v19; // r3
  int v20; // r3
  char *v21; // r10
  _DWORD *v22; // r9
  int i; // ctr
  double v24; // fp30
  double v25; // fp1
  double v26; // fp31
  const idMat3 *v27; // r3
  unsigned __int8 *p_flags; // r10
  _DWORD *p_z; // r9
  int j; // ctr
  int v31; // r2 OVERLAPPED
  double v32; // fp12
  double v33; // fp29
  double v34; // fp0
  double v35; // fp3
  double x; // fp7
  double v37; // fp13
  double v38; // fp28
  __int64 v39; // r6
  double v40; // fp10
  double v41; // fp6
  double v42; // fp4
  double v43; // fp2
  double v44; // fp1
  double v45; // fp9
  double v46; // fp7
  double v47; // fp5
  int v48; // r10
  double v49; // fp8
  double particleCrazyBounceChance; // fp3
  double v51; // fp31
  double v52; // fp30
  double v53; // fp29
  int v54; // r11
  int v55; // r3
  int v56; // r11
  double v57; // fp26
  double v58; // fp12
  int v59; // r26
  double v60; // fp27
  idPhysics *v61; // r3
  int v62; // r3
  float *v63; // r4
  float v64; // r10
  double v65; // fp11
  double v66; // fp10
  double v67; // fp9
  double v68; // fp11
  double v69; // fp10
  double v70; // fp9
  double v71; // fp5
  double v72; // fp3
  int v73; // r11
  double v74; // fp11
  idEntityEmitter::AXIS particleAlignmentExcludeAxis; // r10
  float *p_x; // r11
  double v77; // fp4
  double v78; // fp3
  long double v79; // fp2
  double v82; // fp8
  double v83; // fp11
  double v84; // fp8
  double v85; // fp31
  double v86; // fp30
  double v87; // fp29
  double v88; // fp1
  const idMat3 *v89; // r3
  unsigned __int8 *v90; // r10
  _DWORD *v91; // r9
  int k; // ctr
  idPhysics *v93; // r3
  double v94; // fp12
  double v95; // fp11
  double v96; // fp10
  double v97; // fp9
  idDeclImpactSound *impactSoundTable; // r3
  const idSoundShader *ImpactSoundForMaterial; // r31
  __int64 v100; // r9
  int soundInterval; // r31
  __int64 v102; // r7
  double v103; // fp13
  double v104; // fp12
  double v105; // fp11
  double v106; // fp10
  double v107; // fp8
  double v108; // fp5
  double v111; // fp1
  double v112; // fp0
  double v113; // fp6
  double v114; // fp4
  double v115; // fp3
  double v118; // fp13
  double v119; // fp9
  __int64 v120; // [sp+50h] [-260h]
  float v121; // [sp+54h] [-25Ch]
  idVec3 v122; // [sp+60h] [-250h] BYREF
  idVec3 v123; // [sp+70h] [-240h]
  char v124; // [sp+7Ch] [-234h] BYREF
  idMat3 v125; // [sp+80h] [-230h] BYREF
  idRotation v126; // [sp+B0h] [-200h] BYREF
  idRotation v127; // [sp+100h] [-1B0h] BYREF
  trace_t v128; // [sp+150h] [-160h] BYREF
  idMat3 v129[3]; // [sp+1D0h] [-E0h] BYREF

  if ( (particle->thinkFlags & 2) != 0 )
  {
    Physics = idEntity::GetPhysics(this: particle);
    v120 = __PAIR64__(&off_82040000, gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED));
    p_gravity = &gameLocal->clientGame.gravity;
    y = particle->vel.y;
    z = particle->vel.z;
    p_vel = &particle->vel;
    v9 = (float)((float)v120 * (float)0.001);
    GetOrigin = Physics->GetOrigin;
    v11 = (float)(p_gravity->y * (float)((float)v120 * (float)0.001));
    v12 = (float)(p_gravity->z * (float)((float)v120 * (float)0.001));
    particle->vel.x = particle->vel.x + (float)((float)((float)v120 * (float)0.001) * p_gravity->x);
    particle->vel.y = (float)v11 + (float)y;
    particle->vel.z = (float)v12 + (float)z;
    v13 = (float *)GetOrigin(this: Physics, a2: 0);
    v14 = (float)((float)((float)v120 * (float)0.001) * particle->vel.z);
    v15 = (float)(particle->vel.x * (float)((float)v120 * (float)0.001));
    v16 = (const idVec3 *)v13;
    v17 = *v13;
    v18 = v13[2];
    v122.y = v13[1] + (float)((float)((float)v120 * (float)0.001) * particle->vel.y);
    v122.z = (float)v18 + (float)v14;
    v122.x = (float)v17 + (float)v15;
    v19 = idEntity::GetPhysics(this: particle);
    v20 = (int)v19->GetAxis(this: v19, a2: 0);
    v21 = &v124;
    v22 = (_DWORD *)(v20 - 4);
    for ( i = 9; i != 0; --i )
    {
      ++v22;
      v21 += 4;
      *(_DWORD *)v21 = *v22;
    }
    v24 = (float)(particle->rotationSpeed * (float)((float)v120 * (float)0.001));
    v25 = particle->rotationAxis.y;
    v26 = particle->rotationAxis.z;
    v126.vec.x = particle->rotationAxis.x;
    v126.axisValid = false;
    v126.vec.y = v25;
    v126.vec.z = v26;
    v126.origin.x = vec3_origin.x;
    v126.origin.y = vec3_origin.y;
    v126.origin.z = vec3_origin.z;
    v126.axis.mat[0].x = mat3_identity.mat[0].x;
    v126.axis.mat[0].y = mat3_identity.mat[0].y;
    v126.angle = v24;
    v126.axis.mat[0].z = mat3_identity.mat[0].z;
    v126.axis.mat[1].x = mat3_identity.mat[1].x;
    v126.axis.mat[1].y = mat3_identity.mat[1].y;
    v126.axis.mat[1].z = mat3_identity.mat[1].z;
    v126.axis.mat[2].x = mat3_identity.mat[2].x;
    v126.axis.mat[2].y = mat3_identity.mat[2].y;
    v126.axis.mat[2].z = mat3_identity.mat[2].z;
    v27 = idRotation::ToMat3(this: &v126);
    p_flags = &v128.c.flags;
    p_z = (_DWORD *)&v27[-1].mat[2].z;
    for ( j = 9; j != 0; --j )
    {
      ++p_z;
      p_flags += 4;
      *(_DWORD *)p_flags = *p_z;
    }
    idMat3::operator*=(this: &v125, a: v129);
    if ( entityEmitter_CheckCollisions.valueInteger != 0
      && idClip::TracePoint(
           this: &clientGame->clip,
           result: &v128,
           start: v16,
           end: &v122,
           clipMask: 1,
           passEntityNumber: particle->entityNumber) )
    {
      v32 = v128.c.normal.y;
      v33 = particle->vel.y;
      v34 = v128.c.normal.z;
      v35 = v16->z;
      x = p_vel->x;
      v37 = v128.c.normal.x;
      v38 = particle->vel.z;
      HIDWORD(v39) = 0x82000000;
      v40 = (float)((float)(v122.z - v16->z) * v128.fraction);
      v41 = (float)((float)((float)(v122.x - v16->x) * v128.fraction) + v16->x);
      v42 = (float)((float)((float)((float)x * v128.c.normal.x)
                          + (float)((float)(particle->vel.z * v128.c.normal.z)
                                  + (float)(particle->vel.y * v128.c.normal.y)))
                  * v128.c.normal.x);
      v43 = (float)(v128.c.normal.y
                  * (float)((float)((float)x * v128.c.normal.x)
                          + (float)((float)(particle->vel.z * v128.c.normal.z)
                                  + (float)(particle->vel.y * v128.c.normal.y))));
      v44 = (float)(v128.c.normal.z
                  * (float)((float)((float)x * v128.c.normal.x)
                          + (float)((float)(particle->vel.z * v128.c.normal.z)
                                  + (float)(particle->vel.y * v128.c.normal.y))));
      v45 = (float)((float)((float)(v122.y - v16->y) * v128.fraction) + v16->y);
      v47 = (float)((float)(v128.c.normal.y * (float)(particle->vel.y * entityEmitter_PushAwayFactor.valueFloat))
                  + (float)((float)((float)(p_vel->x * entityEmitter_PushAwayFactor.valueFloat) * v128.c.normal.x)
                          + (float)(v128.c.normal.z * (float)(particle->vel.z * entityEmitter_PushAwayFactor.valueFloat))));
      v123 = vec3_origin;
      p_vel->x = (float)x - (float)v42;
      v46 = (float)((float)v40 + (float)v35);
      particle->vel.y = (float)v33 - (float)v43;
      particle->vel.z = (float)v38 - (float)v44;
      v48 = 1103515245 * this->random.seed + 12345;
      v49 = -this->particleCollisionElasticity;
      this->random.seed = v48;
      LODWORD(v39) = (v48 >> 16) & 0x7FFF;
      v122.x = (float)v41 + (float)((float)v47 * (float)v37);
      particleCrazyBounceChance = this->particleCrazyBounceChance;
      v122.y = (float)v45 + (float)((float)v32 * (float)v47);
      v51 = (float)((float)v42 * (float)v49);
      v122.z = (float)v46 + (float)((float)v34 * (float)v47);
      v52 = (float)((float)v43 * (float)v49);
      v53 = (float)((float)v44 * (float)v49);
      if ( (float)((float)((float)v39 * (float)0.000061037019) - (float)1.0) >= particleCrazyBounceChance )
      {
        v70 = v123.z;
        v69 = v123.y;
        v68 = v123.x;
      }
      else
      {
        v54 = 1103515245 * v48 + 12345;
        this->random.seed = v54;
        v55 = (v54 >> 16) & 0x7FFF;
        v56 = 1103515245 * v54 + 12345;
        v57 = __fsqrts((float)((float)((float)((float)v43 * (float)v49) * (float)((float)v43 * (float)v49))
                             + (float)((float)((float)((float)v42 * (float)v49) * (float)((float)v42 * (float)v49))
                                     + (float)((float)((float)v44 * (float)v49) * (float)((float)v44 * (float)v49)))));
        v58 = this->particleCrazyBounceChance;
        this->random.seed = v56;
        v59 = ((v56 >> 16) & 0x7FFF) - 3 * ((unsigned __int64)(1431655766LL * ((v56 >> 16) & 0x7FFF)) >> 32);
        v60 = (float)((float)((float)((float)*(__int64 *)(&v31 - 1) * (float)0.000061037019) - (float)1.0) * (float)v58);
        v51 = (float)((float)((float)1.0
                            - (float)((float)((float)((float)*(__int64 *)(&v31 - 1) * (float)0.000061037019) - (float)1.0)
                                    * (float)v58))
                    * (float)((float)v42 * (float)v49));
        v52 = (float)((float)((float)v43 * (float)v49)
                    * (float)((float)1.0
                            - (float)((float)((float)((float)*(__int64 *)(&v31 - 1) * (float)0.000061037019) - (float)1.0)
                                    * (float)v58)));
        v53 = (float)((float)((float)v44 * (float)v49)
                    * (float)((float)1.0
                            - (float)((float)((float)((float)*(__int64 *)(&v31 - 1) * (float)0.000061037019) - (float)1.0)
                                    * (float)v58)));
        v61 = idEntity::GetPhysics(this: particle);
        v62 = (int)v61->GetAxis(this: v61, a2: 0);
        v34 = v128.c.normal.z;
        v37 = v128.c.normal.x;
        v32 = v128.c.normal.y;
        v63 = (float *)(12 * v59 + v62);
        v64 = v63[2];
        v65 = *v63;
        v121 = v63[1];
        v66 = v121;
        v67 = v64;
        if ( (float)((float)(v121 * v128.c.normal.y)
                   + (float)((float)(*v63 * v128.c.normal.x) + (float)(v64 * v128.c.normal.z))) < 0.0 )
        {
          v65 = (float)(*v63 * (float)-1.0);
          v66 = (float)(v121 * (float)-1.0);
          v67 = (float)(v64 * (float)-1.0);
        }
        v68 = (float)((float)v65 * (float)((float)v57 * (float)v60));
        v69 = (float)((float)v66 * (float)((float)v57 * (float)v60));
        v70 = (float)((float)v67 * (float)((float)v57 * (float)v60));
      }
      v71 = particle->vel.y;
      v72 = particle->vel.z;
      v73 = -1;
      p_vel->x = p_vel->x + (float)((float)v68 + (float)v51);
      v74 = 0.0;
      particle->vel.y = (float)((float)v69 + (float)v52) + (float)v71;
      particle->vel.z = (float)((float)v70 + (float)v53) + (float)v72;
      particle->rotationSpeed = (float)((float)1.0 - this->particleAngularFriction) * particle->rotationSpeed;
      particleAlignmentExcludeAxis = this->particleAlignmentExcludeAxis;
      if ( particleAlignmentExcludeAxis != 0
        && __fabs((float)((float)(v125.mat[0].x * (float)v37)
                        + (float)((float)(v125.mat[0].z * (float)v34) + (float)(v125.mat[0].y * (float)v32)))) > __fabs(0.0) )
      {
        v73 = 0;
        v74 = (float)((float)(v125.mat[0].x * (float)v37)
                    + (float)((float)(v125.mat[0].z * (float)v34) + (float)(v125.mat[0].y * (float)v32)));
      }
      if ( particleAlignmentExcludeAxis != 1
        && __fabs((float)((float)(v125.mat[1].x * (float)v37)
                        + (float)((float)(v125.mat[1].z * (float)v34) + (float)(v125.mat[1].y * (float)v32)))) > __fabs(v74) )
      {
        v73 = 1;
        v74 = (float)((float)(v125.mat[1].x * (float)v37)
                    + (float)((float)(v125.mat[1].z * (float)v34) + (float)(v125.mat[1].y * (float)v32)));
      }
      if ( particleAlignmentExcludeAxis != 2
        && __fabs((float)((float)(v125.mat[2].x * (float)v37)
                        + (float)((float)(v125.mat[2].z * (float)v34) + (float)(v125.mat[2].y * (float)v32)))) > __fabs(v74) )
      {
        v73 = 2;
      }
      p_x = &v125.mat[v73].x;
      v77 = (float)((float)(p_x[2] * (float)v37) - (float)((float)v34 * *p_x));
      v78 = (float)((float)((float)v32 * *p_x) - (float)(p_x[1] * (float)v37));
      *((double *)&v79 + 1) = (float)((float)((float)v34 * p_x[1]) - (float)((float)v32 * p_x[2]));
      _FP12 = (float)((float)((float)((float)*((double *)&v79 + 1) * (float)*((double *)&v79 + 1))
                            + (float)((float)((float)v78 * (float)v78) + (float)((float)v77 * (float)v77)))
                    - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f9, f12, f13, f11 }
      v82 = __frsqrte(_FP9);
      v83 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82
                                                                                          * (float)((float)((float)((float)*((double *)&v79 + 1) * (float)*((double *)&v79 + 1)) + (float)((float)((float)v78 * (float)v78) + (float)((float)v77 * (float)v77)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v82)
                                                                          - (float)1.5)
                                                          * (float)v82)
                                                  * (float)((float)((float)((float)*((double *)&v79 + 1)
                                                                          * (float)*((double *)&v79 + 1))
                                                                  + (float)((float)((float)v78 * (float)v78)
                                                                          + (float)((float)v77 * (float)v77)))
                                                          * (float)0.5))
                                          * (float)((float)-(float)((float)((float)((float)v82
                                                                                  * (float)((float)((float)((float)*((double *)&v79 + 1) * (float)*((double *)&v79 + 1))
                                                                                                  + (float)((float)((float)v78 * (float)v78) + (float)((float)v77 * (float)v77)))
                                                                                          * (float)0.5))
                                                                          * (float)v82)
                                                                  - (float)1.5)
                                                  * (float)v82))
                                  - (float)1.5)
                  * (float)((float)-(float)((float)((float)((float)v82
                                                          * (float)((float)((float)((float)*((double *)&v79 + 1)
                                                                                  * (float)*((double *)&v79 + 1))
                                                                          + (float)((float)((float)v78 * (float)v78)
                                                                                  + (float)((float)v77 * (float)v77)))
                                                                  * (float)0.5))
                                                  * (float)v82)
                                          - (float)1.5)
                          * (float)v82));
      v84 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)*((double *)&v79 + 1) * (float)*((double *)&v79 + 1)) + (float)((float)((float)v78 * (float)v78) + (float)((float)v77 * (float)v77))) * (float)0.5)) * (float)v82) - (float)1.5)
                                                                                                  * (float)v82)
                                                                                          * (float)((float)((float)((float)*((double *)&v79 + 1) * (float)*((double *)&v79 + 1)) + (float)((float)((float)v78 * (float)v78) + (float)((float)v77 * (float)v77)))
                                                                                                  * (float)0.5))
                                                                                  * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)*((double *)&v79 + 1) * (float)*((double *)&v79 + 1)) + (float)((float)((float)v78 * (float)v78) + (float)((float)v77 * (float)v77))) * (float)0.5)) * (float)v82) - (float)1.5)
                                                                                          * (float)v82))
                                                                          - (float)1.5)
                                                          * (float)((float)-(float)((float)((float)((float)v82
                                                                                                  * (float)((float)((float)((float)*((double *)&v79 + 1) * (float)*((double *)&v79 + 1)) + (float)((float)((float)v78 * (float)v78) + (float)((float)v77 * (float)v77))) * (float)0.5))
                                                                                          * (float)v82)
                                                                                  - (float)1.5)
                                                                  * (float)v82))
                                                  * (float)((float)((float)((float)*((double *)&v79 + 1)
                                                                          * (float)*((double *)&v79 + 1))
                                                                  + (float)((float)((float)v78 * (float)v78)
                                                                          + (float)((float)v77 * (float)v77)))
                                                          * (float)0.5))
                                          * (float)v83)
                                  - (float)1.5)
                  * (float)v83);
      v85 = (float)((float)*((double *)&v79 + 1) * (float)v84);
      v86 = (float)((float)((float)(p_x[2] * (float)v37) - (float)((float)v34 * *p_x)) * (float)v84);
      v87 = (float)((float)v78 * (float)v84);
      *(double *)&v79 = (float)((float)v84
                              * (float)((float)((float)*((double *)&v79 + 1) * (float)*((double *)&v79 + 1))
                                      + (float)((float)((float)v78 * (float)v78) + (float)((float)v77 * (float)v77))));
      v88 = idMath::ASin(a: v79);
      v127.axisValid = false;
      v127.origin.x = vec3_origin.x;
      v127.origin.y = vec3_origin.y;
      v127.origin.z = vec3_origin.z;
      v127.vec.x = v85;
      v127.vec.y = v86;
      v127.vec.z = v87;
      v127.axis.mat[0].x = mat3_identity.mat[0].x;
      v127.axis.mat[0].y = mat3_identity.mat[0].y;
      v127.axis.mat[0].z = mat3_identity.mat[0].z;
      v127.angle = -(float)((float)v88 * idMath::M_RAD2DEG);
      v127.axis.mat[1].x = mat3_identity.mat[1].x;
      v127.axis.mat[1].y = mat3_identity.mat[1].y;
      v127.axis.mat[1].z = mat3_identity.mat[1].z;
      v127.axis.mat[2].x = mat3_identity.mat[2].x;
      v127.axis.mat[2].y = mat3_identity.mat[2].y;
      v127.axis.mat[2].z = mat3_identity.mat[2].z;
      v89 = idRotation::ToMat3(this: &v127);
      v90 = &v128.c.flags;
      v91 = (_DWORD *)&v89[-1].mat[2].z;
      for ( k = 9; k != 0; --k )
      {
        ++v91;
        v90 += 4;
        *(_DWORD *)v90 = *v91;
      }
      idMat3::operator*=(this: &v125, a: v129);
      v93 = idEntity::GetPhysics(this: particle);
      v93->SetAxis(this: v93, a2: &v125, a3: -1);
      v94 = v128.c.point.z;
      particle->lastCollisionPos.y = v128.c.point.y;
      particle->lastCollisionPos.z = v94;
      v95 = v128.c.normal.x;
      v96 = v128.c.normal.y;
      v97 = v128.c.normal.z;
      particle->lastCollisionPos.x = v128.c.point.x;
      particle->lastCollisionNormal.x = v95;
      particle->lastCollisionNormal.y = v96;
      particle->lastCollisionNormal.z = v97;
      impactSoundTable = this->impactSoundTable;
      if ( impactSoundTable != nullptr )
      {
        ImpactSoundForMaterial = idDeclImpactSound::GetImpactSoundForMaterial(
                                   this: impactSoundTable,
                                   materialID: v128.c.surfaceType);
        if ( ImpactSoundForMaterial != nullptr )
        {
          LODWORD(v100) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          if ( (float)v100 >= (double)particle->nextSoundTime )
          {
            idEntity::StartSoundShader(
              this: particle,
              channel: SND_CHANNEL_WEAPON_AMBIENT,
              shader: ImpactSoundForMaterial,
              soundShaderFlags: (soundShaderFlags_t)0,
              peerMask: 0xFFu);
            soundInterval = this->impactSoundTable->soundInterval;
            LODWORD(v102) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + soundInterval;
            particle->nextSoundTime = (float)v102;
          }
        }
      }
    }
    v103 = v122.y;
    v104 = v122.z;
    v105 = v122.x;
    if ( (float)((float)((float)(v122.x - particle->lastCollisionPos.x) * particle->lastCollisionNormal.x)
               + (float)((float)(particle->lastCollisionNormal.z * (float)(v122.z - particle->lastCollisionPos.z))
                       + (float)(particle->lastCollisionNormal.y * (float)(v122.y - particle->lastCollisionPos.y)))) <= 0.5 )
    {
      v106 = particle->vel.y;
      v107 = p_vel->x;
      v108 = (float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y)));
      _FP4 = (float)((float)((float)(p_vel->z * p_vel->z)
                           + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f2, f4, f5, f0 }
      v111 = __frsqrte(_FP2);
      v112 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v111
                                                                                           * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y))) * (float)0.5))
                                                                                   * (float)v111)
                                                                           - (float)1.5)
                                                           * (float)v111)
                                                   * (float)((float)((float)(p_vel->z * p_vel->z)
                                                                   + (float)((float)(p_vel->x * p_vel->x)
                                                                           + (float)(p_vel->y * p_vel->y)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)((float)v111
                                                                                   * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y)))
                                                                                           * (float)0.5))
                                                                           * (float)v111)
                                                                   - (float)1.5)
                                                   * (float)v111))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v111
                                                           * (float)((float)((float)(p_vel->z * p_vel->z)
                                                                           + (float)((float)(p_vel->x * p_vel->x)
                                                                                   + (float)(p_vel->y * p_vel->y)))
                                                                   * (float)0.5))
                                                   * (float)v111)
                                           - (float)1.5)
                           * (float)v111));
      v113 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v111 * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y))) * (float)0.5)) * (float)v111) - (float)1.5)
                                                                                           * (float)v111)
                                                                                   * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y)))
                                                                                           * (float)0.5))
                                                                           * (float)((float)-(float)((float)((float)((float)v111 * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y))) * (float)0.5)) * (float)v111) - (float)1.5)
                                                                                   * (float)v111))
                                                                   - (float)1.5)
                                                   * (float)((float)-(float)((float)((float)((float)v111
                                                                                           * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y))) * (float)0.5))
                                                                                   * (float)v111)
                                                                           - (float)1.5)
                                                           * (float)v111))
                                           * (float)((float)((float)(p_vel->z * p_vel->z)
                                                           + (float)((float)(p_vel->x * p_vel->x)
                                                                   + (float)(p_vel->y * p_vel->y)))
                                                   * (float)0.5))
                                   * (float)v112)
                           - (float)1.5);
      v114 = (float)((float)v113
                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v111 * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y))) * (float)0.5))
                                                                                           * (float)v111)
                                                                                   - (float)1.5)
                                                                   * (float)v111)
                                                           * (float)((float)((float)(p_vel->z * p_vel->z)
                                                                           + (float)((float)(p_vel->x * p_vel->x)
                                                                                   + (float)(p_vel->y * p_vel->y)))
                                                                   * (float)0.5))
                                                   * (float)((float)-(float)((float)((float)((float)v111
                                                                                           * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y))) * (float)0.5))
                                                                                   * (float)v111)
                                                                           - (float)1.5)
                                                           * (float)v111))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v111
                                                                   * (float)((float)((float)(p_vel->z * p_vel->z)
                                                                                   + (float)((float)(p_vel->x * p_vel->x)
                                                                                           + (float)(p_vel->y * p_vel->y)))
                                                                           * (float)0.5))
                                                           * (float)v111)
                                                   - (float)1.5)
                                   * (float)v111)));
      v115 = (float)(p_vel->z
                   * (float)((float)v113
                           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v111 * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y))) * (float)0.5)) * (float)v111)
                                                                                           - (float)1.5)
                                                                           * (float)v111)
                                                                   * (float)((float)((float)(p_vel->z * p_vel->z)
                                                                                   + (float)((float)(p_vel->x * p_vel->x)
                                                                                           + (float)(p_vel->y * p_vel->y)))
                                                                           * (float)0.5))
                                                           * (float)((float)-(float)((float)((float)((float)v111 * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y))) * (float)0.5))
                                                                                           * (float)v111)
                                                                                   - (float)1.5)
                                                                   * (float)v111))
                                                   - (float)1.5)
                                   * (float)((float)-(float)((float)((float)((float)v111
                                                                           * (float)((float)((float)(p_vel->z * p_vel->z)
                                                                                           + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y)))
                                                                                   * (float)0.5))
                                                                   * (float)v111)
                                                           - (float)1.5)
                                           * (float)v111))));
      p_vel->z = p_vel->z
               * (float)((float)v113
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v111 * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y))) * (float)0.5))
                                                                                               * (float)v111)
                                                                                       - (float)1.5)
                                                                       * (float)v111)
                                                               * (float)((float)((float)(p_vel->z * p_vel->z)
                                                                               + (float)((float)(p_vel->x * p_vel->x)
                                                                                       + (float)(p_vel->y * p_vel->y)))
                                                                       * (float)0.5))
                                                       * (float)((float)-(float)((float)((float)((float)v111
                                                                                               * (float)((float)((float)(p_vel->z * p_vel->z) + (float)((float)(p_vel->x * p_vel->x) + (float)(p_vel->y * p_vel->y))) * (float)0.5))
                                                                                       * (float)v111)
                                                                               - (float)1.5)
                                                               * (float)v111))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)((float)v111
                                                                       * (float)((float)((float)(p_vel->z * p_vel->z)
                                                                                       + (float)((float)(p_vel->x * p_vel->x)
                                                                                               + (float)(p_vel->y * p_vel->y)))
                                                                               * (float)0.5))
                                                               * (float)v111)
                                                       - (float)1.5)
                                       * (float)v111)));
      p_vel->x = (float)v107 * (float)v114;
      particle->vel.y = (float)v106 * (float)v114;
      _FP7 = (float)((float)((float)v114 * (float)v108) - (float)(this->particleFriction * (float)v9));
      __asm { fsel      f5, f7, f7, f24 }
      p_vel->x = (float)((float)v107 * (float)v114) * (float)_FP5;
      particle->vel.y = (float)_FP5 * (float)((float)v106 * (float)v114);
      particle->vel.z = (float)_FP5 * (float)v115;
    }
    v118 = (float)((float)v103 - v16->y);
    v119 = (float)((float)v104 - v16->z);
    if ( (float)((float)((float)((float)v105 - v16->x) * (float)((float)v105 - v16->x))
               + (float)((float)((float)v119 * (float)v119) + (float)((float)v118 * (float)v118))) < 0.001 )
      particle->state = STATE_ACTIVE_STOPPED;
    Physics->SetOrigin(this: Physics, a2: &v122, a3: -1);
    Physics->SetAxis(this: Physics, a2: &v125, a3: -1);
  }
}


// ========================================================================
// ??0idEntityEmitter@@QAA@XZ
// EA  : 0x82C49088
// RVA : 0x00C49088
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

idEntityEmitter *__fastcall idEntityEmitter::idEntityEmitter(idEntityEmitter *this)
{
  idEntity::idEntity(this);
  this->__vftable = (idEntityEmitter_vtbl *)&idEntityEmitter::`vftable';
  this->particleLifespan = 0.0;
  this->particleFadeTime = 1000.0;
  this->particleCount = 0;
  this->particleFadeSpeed = 20.0;
  this->particleAlignmentExcludeAxis = AXIS_NONE;
  this->particleCollisionElasticity = 0.69999999;
  this->impactSoundTable = nullptr;
  this->particleCrazyBounceChance = 0.0;
  this->particleDef = nullptr;
  this->particleAngularVelocity = 10000.0;
  this->particleFriction = 450.0;
  this->particleAngularFriction = 0.2;
  this->particles.list = nullptr;
  this->particles.granularity = 0;
  this->particles.memTag = 5;
  this->particles.listStatic = 0;
  this->particles.size = 0;
  this->particles.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->particles);
  this->particleIndex = 0;
  this->numParticlesInUse = 0;
  this->random.seed = 0;
  this->emitModelDepthHack = 0.0;
  this->emitFovScale = 1.0;
  return this;
}


// ========================================================================
// __unwind$489544
// EA  : 0x82C4917C
// RVA : 0x00C4917C
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void _unwind_489544()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 128 + 148));
}


// ========================================================================
// ??1idEntityEmitter@@UAA@XZ
// EA  : 0x82C491B0
// RVA : 0x00C491B0
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void __fastcall idEntityEmitter::~idEntityEmitter(idEntityEmitter *this)
{
  this->__vftable = (idEntityEmitter_vtbl *)&idEntityEmitter::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->particles);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$489582_0
// EA  : 0x82C49204
// RVA : 0x00C49204
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void _unwind_489582_0()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 112 + 132));
}


// ========================================================================
// ?RunState_Active@idEntityEmitter@@QAAXPAVidEntityParticle@@@Z
// EA  : 0x82C49230
// RVA : 0x00C49230
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void __fastcall idEntityEmitter::RunState_Active(idEntityEmitter *this, idEntityParticle *particle)
{
  double valueFloat; // fp29
  __int64 v5; // r11
  double v8; // fp31
  __int64 v9; // r11
  __int64 v12; // r8

  if ( particle->state == STATE_ACTIVE_MOVING && entityEmitter_RunPhysics.valueInteger != 0 )
    idEntityEmitter::RunPhysics(this, particle);
  if ( particle->fovScale < 1.0 )
  {
    valueFloat = entityEmitter_FovScaleSpeed.valueFloat;
    LODWORD(v5) = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    _FP8 = (float)((float)((float)((float)((float)v5 * (float)valueFloat) * (float)0.001) + particle->fovScale)
                 - (float)1.0);
    __asm { fsel      f7, f8, f31, f9 }
    particle->fovScale = _FP7;
  }
  if ( particle->modelDepthHack > 0.0 )
  {
    v8 = entityEmitter_FovScaleSpeed.valueFloat;
    LODWORD(v9) = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    _FP9 = (float)-(float)((float)((float)((float)v9 * (float)v8) * (float)0.001) - particle->modelDepthHack);
    __asm { fsel      f8, f9, f9, f29 }
    particle->modelDepthHack = _FP8;
  }
  LODWORD(v12) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  if ( (float)v12 >= (double)(float)(particle->emitTime + this->particleLifespan) )
    particle->state = STATE_FADE;
}


// ========================================================================
// ?Think@idEntityEmitter@@UAAXXZ
// EA  : 0x82C493F8
// RVA : 0x00C493F8
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void __fastcall idEntityEmitter::Think(idEntityEmitter *this)
{
  char v2; // r27
  int v3; // r25
  int v4; // r26
  idEntity *v5; // r31
  unsigned int listeningToList; // r11
  idPhysics *Physics; // r3
  float *presentable; // r30
  idPhysics *v9; // r29
  float *v10; // r3
  idPhysics *v11; // r3
  float *v12; // r30
  idPhysics *v13; // r29
  float *v14; // r3
  idPresentable *v15; // r11
  idPresentable *v16; // r11
  idPresentable *v17; // r11

  idEntity::Think(this);
  if ( (this->thinkFlags & 1) != 0 )
  {
    v2 = 0;
    v3 = 0;
    this->random.seed = 1103515245 * this->random.seed + 12345;
    if ( this->particles.num > 0 )
    {
      v4 = 0;
      do
      {
        v5 = this->particles.list[v4];
        listeningToList = (unsigned int)v5[1].listeningToList;
        if ( listeningToList <= 3 )
        {
          if ( listeningToList == 1 || listeningToList == 2 )
          {
            idEntityEmitter::RunState_Active(this, particle: this->particles.list[v4]);
            v2 = 1;
          }
          else if ( listeningToList != 0 )
          {
            v2 = idEntityEmitter::RunState_Fade(this, particle: this->particles.list[v4]);
          }
          else
          {
            v2 = 0;
          }
        }
        if ( v2 != 0 )
        {
          Physics = idEntity::GetPhysics(this: v5);
          presentable = (float *)v5->presentable;
          v9 = Physics;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: v5);
            presentable = (float *)v5->presentable;
          }
          v10 = (float *)v9->GetOrigin(this: v9, a2: 0);
          presentable[30] = *v10;
          presentable[31] = v10[1];
          presentable[32] = v10[2];
          v11 = idEntity::GetPhysics(this: v5);
          v12 = (float *)v5->presentable;
          v13 = v11;
          if ( v12 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v5);
            v12 = (float *)v5->presentable;
          }
          v14 = (float *)v13->GetAxis(this: v13, a2: 0);
          v12[33] = *v14;
          v12[34] = v14[1];
          v12[35] = v14[2];
          v12[36] = v14[3];
          v12[37] = v14[4];
          v12[38] = v14[5];
          v12[39] = v14[6];
          v12[40] = v14[7];
          v12[41] = v14[8];
          v15 = v5->presentable;
          if ( v15 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v5);
            v15 = v5->presentable;
          }
          v15->model->g.fovScale = v5[1].spawnOrientation.mat[0].z;
          v16 = v5->presentable;
          if ( v16 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v5);
            v16 = v5->presentable;
          }
          v16->model->g.modelDepthHack = v5[1].spawnOrientation.mat[1].x;
          v17 = v5->presentable;
          if ( v17 == nullptr )
          {
            idEntity::InitPresentableInternal(this: v5);
            v17 = v5->presentable;
          }
          v17->Present(this: v17);
        }
        ++v3;
        ++v4;
      }
      while ( v3 < this->particles.num );
    }
  }
}


// ========================================================================
// ?Spawn@idEntityEmitter@@QAAXXZ
// EA  : 0x82C49620
// RVA : 0x00C49620
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void __fastcall idEntityEmitter::Spawn(idEntityEmitter *this)
{
  idPhysics *Physics; // r3
  int i; // r29
  idEntityParticle *v4; // r3
  idEntityParticle *v5; // r3
  idEntityParticle *v6; // r31
  idPresentable *presentable; // r11
  double particleAngularFriction; // fp0
  double particleCollisionElasticity; // fp0
  idEntityParticle *v10; // [sp+50h] [-40h] BYREF

  Physics = idEntity::GetPhysics(this);
  Physics->SetContents(this: Physics, a2: 0, a3: -1);
  idEntity::BecomeInactive(this, flags: 7);
  this->Hide_2(this);
  if ( this->particleDef != nullptr )
  {
    for ( i = 0; i < this->particleCount; ++i )
    {
      v4 = (idEntityParticle *)gameLocal->SpawnEntityFromDef(
                                 this: gameLocal,
                                 a2: this->particleDef,
                                 a3: -1,
                                 a4: -1,
                                 a5: -1);
      v5 = idEntityParticle::CastTo(c: v4);
      v6 = v5;
      v10 = v5;
      if ( v5 != nullptr )
      {
        presentable = v5->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this: v5);
          presentable = v6->presentable;
        }
        presentable->model->g.castDimShadows = DIMSHADOW_OFF;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->particles,
          obj: (encounterGroupRole_t *)&v10);
      }
    }
  }
  particleAngularFriction = this->particleAngularFriction;
  if ( particleAngularFriction >= 0.0 )
  {
    if ( particleAngularFriction > 1.0 )
      particleAngularFriction = 1.0;
  }
  else
  {
    particleAngularFriction = 0.0;
  }
  this->particleAngularFriction = particleAngularFriction;
  particleCollisionElasticity = this->particleCollisionElasticity;
  if ( particleCollisionElasticity >= 0.0 )
  {
    if ( particleCollisionElasticity <= 1.0 )
      this->particleCollisionElasticity = this->particleCollisionElasticity;
    else
      this->particleCollisionElasticity = 1.0;
  }
  else
  {
    this->particleCollisionElasticity = 0.0;
  }
}


// ========================================================================
// `dynamic initializer for 'entityEmitter_PushAwayFactor''
// EA  : 0x83376C10
// RVA : 0x01376C10
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__entityEmitter_PushAwayFactor__()
{
  idCVar::idCVar(
    this: &entityEmitter_PushAwayFactor,
    name: "entityEmitter_PushAwayFactor",
    value: "-0.005",
    flags: 4,
    description: "Push entities away from surfaces they collide with, proportionally to their speed in the direction of the surface normal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__entityEmitter_PushAwayFactor__);
}


// ========================================================================
// `dynamic initializer for 'entityEmitter_RunPhysics''
// EA  : 0x83376C68
// RVA : 0x01376C68
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__entityEmitter_RunPhysics__()
{
  idCVar::idCVar(
    this: &entityEmitter_RunPhysics,
    name: "entityEmitter_RunPhysics",
    value: "1",
    flags: 1,
    description: "Run physics on the emitted entities",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__entityEmitter_RunPhysics__);
}


// ========================================================================
// `dynamic initializer for 'entityEmitter_FovScaleSpeed''
// EA  : 0x83376CC0
// RVA : 0x01376CC0
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__entityEmitter_FovScaleSpeed__()
{
  idCVar::idCVar(
    this: &entityEmitter_FovScaleSpeed,
    name: "entityEmitter_FovScaleSpeed",
    value: "1",
    flags: 4,
    description: "Speed at which the fov transitions up to 1.0",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__entityEmitter_FovScaleSpeed__);
}


// ========================================================================
// `dynamic initializer for 'entityEmitter_CheckCollisions''
// EA  : 0x83376D18
// RVA : 0x01376D18
// PDB : w:\tech5\tungsten\game\entities\entityemitter.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__entityEmitter_CheckCollisions__()
{
  idCVar::idCVar(
    this: &entityEmitter_CheckCollisions,
    name: "entityEmitter_CheckCollisions",
    value: "1",
    flags: 1,
    description: "Check collisions on emitted entites?",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__entityEmitter_CheckCollisions__);
}

