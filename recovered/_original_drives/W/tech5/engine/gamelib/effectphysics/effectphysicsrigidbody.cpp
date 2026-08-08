
// ========================================================================
// ?Setup@idEffectPhysicsRigidBody@@QAAXPBVidEffectPhysicsProperties@@@Z
// EA  : 0x82706E70
// RVA : 0x00706E70
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.cpp
// ========================================================================

void __fastcall idEffectPhysicsRigidBody::Setup(
        idEffectPhysicsRigidBody *this,
        const idEffectPhysicsProperties *props,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idSPObject *a14)
{
  BOOL worldCollisionOnly; // r9
  const idEffectPhysicsProperties *properties; // r8

  this->properties = props;
  this->currentState.position.z = 0.0;
  this->currentState.position.y = 0.0;
  this->currentState.position.x = 0.0;
  this->currentState.orientation.mat[2].z = 1.0;
  this->currentState.orientation.mat[1].y = 1.0;
  this->currentState.orientation.mat[0].x = 1.0;
  this->currentState.orientation.mat[1].z = 0.0;
  this->currentState.orientation.mat[0].z = 0.0;
  this->currentState.orientation.mat[0].y = 0.0;
  this->currentState.orientation.mat[2].y = 0.0;
  this->currentState.orientation.mat[2].x = 0.0;
  this->currentState.orientation.mat[1].x = 0.0;
  this->currentState.linearMomentum.z = 0.0;
  this->currentState.linearMomentum.y = 0.0;
  this->currentState.linearMomentum.x = 0.0;
  this->currentState.angularMomentum.z = 0.0;
  this->currentState.angularMomentum.y = 0.0;
  this->currentState.angularMomentum.x = 0.0;
  this->currentState.externalForce.z = 0.0;
  this->currentState.externalForce.y = 0.0;
  this->currentState.externalForce.x = 0.0;
  this->currentState.externalTorque.z = 0.0;
  this->currentState.externalTorque.y = 0.0;
  this->currentState.externalTorque.x = 0.0;
  this->active = false;
  this->settled = false;
  this->SPObject.traceModelIndex = props->traceModelIndex;
  worldCollisionOnly = props->worldCollisionOnly;
  this->SPObject.motion.worldCollisionOnly = worldCollisionOnly;
  properties = this->properties;
  this->SPObject.clipMask = props->clipMask;
  idEffectPhysicsBroadPhase::AddObject(
    this: properties->broadPhase,
    object: &this->SPObject,
    origin: &this->currentState.position,
    axis: &this->currentState.orientation,
    bounds: nullptr,
    a6: (int)properties,
    a7: worldCollisionOnly,
    a8: (int)props,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14);
}


// ========================================================================
// ?CapVelocity@idEffectPhysicsRigidBody@@ABAXMAAUeffectRBState_t@1@@Z
// EA  : 0x82706F28
// RVA : 0x00706F28
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.cpp
// ========================================================================

void __fastcall idEffectPhysicsRigidBody::CapVelocity(
        idEffectPhysicsRigidBody *this,
        double deltaTime,
        idEffectPhysicsRigidBody::effectRBState_t *current,
        float *a4)
{
  double v5; // fp13
  const idEffectPhysicsProperties *properties; // r11
  double v7; // fp12
  double v9; // fp10
  float *v10; // r30
  double v11; // fp9
  const idMat3 *v12; // r29
  double v13; // fp8
  double v14; // fp7
  double v15; // fp6
  double v16; // fp31
  double v17; // fp30
  double v18; // fp29
  idMat3 *v19; // r3
  const idEffectPhysicsProperties *v20; // r10
  double maxLinearVelocity; // fp12
  double v22; // fp10
  double v23; // fp9
  double v24; // fp8
  double v25; // fp6
  double v27; // fp3
  double v28; // fp2
  double v30; // fp13
  double v31; // fp13
  double v32; // fp1
  double v33; // fp13
  double v34; // fp9
  double v35; // fp13
  double v36; // fp10
  double v38; // fp7
  double v39; // fp6
  double v41; // fp4
  double v42; // fp13
  double v43; // fp1
  idMat3 v44; // [sp+50h] [-A0h] BYREF
  idMat3 v45; // [sp+80h] [-70h] BYREF

  v5 = a4[8];
  properties = this->properties;
  v7 = a4[5];
  v44.mat[2].z = a4[11];
  v44.mat[2].y = v5;
  v9 = a4[7];
  v10 = a4 + 12;
  v11 = a4[4];
  v12 = (const idMat3 *)(a4 + 3);
  v13 = a4[9];
  v14 = a4[6];
  v15 = a4[3];
  v44.mat[1].z = a4[10];
  v44.mat[2].x = v7;
  v44.mat[1].y = v9;
  v44.mat[1].x = v11;
  v44.mat[0].z = v13;
  v44.mat[0].y = v14;
  v44.mat[0].x = v15;
  v16 = (float)(properties->inverseMass * a4[12]);
  v17 = (float)(a4[13] * properties->inverseMass);
  v18 = (float)(a4[14] * properties->inverseMass);
  v19 = idMat3::operator*(this: &v45, result: &v44, a: &properties->inverseInertiaTensor);
  idMat3::operator*(this: &v44, result: v19, a: v12);
  v20 = this->properties;
  maxLinearVelocity = this->properties->maxLinearVelocity;
  v22 = (float)((float)(a4[15] * v44.mat[0].x) + (float)((float)(a4[17] * v44.mat[2].x) + (float)(a4[16] * v44.mat[1].x)));
  v23 = (float)((float)(a4[16] * v44.mat[1].y) + (float)((float)(a4[15] * v44.mat[0].y) + (float)(a4[17] * v44.mat[2].y)));
  v24 = (float)((float)(a4[16] * v44.mat[1].z) + (float)((float)(a4[15] * v44.mat[0].z) + (float)(a4[17] * v44.mat[2].z)));
  if ( (float)((float)((float)v16 * (float)v16)
             + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) > (double)(float)(this->properties->maxLinearVelocity * this->properties->maxLinearVelocity) )
  {
    v25 = (float)((float)((float)((float)v16 * (float)v16)
                        + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
                * (float)0.5);
    _FP5 = (float)((float)((float)((float)v16 * (float)v16)
                         + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v27 = v10[1];
    v28 = v10[2];
    __asm { fsel      f1, f5, f13, f11 }
    v30 = __frsqrte(_FP1);
    v31 = (float)((float)-(float)((float)((float)((float)v30
                                                * (float)((float)((float)((float)v16 * (float)v16)
                                                                + (float)((float)((float)v18 * (float)v18)
                                                                        + (float)((float)v17 * (float)v17)))
                                                        * (float)0.5))
                                        * (float)v30)
                                - (float)1.5)
                * (float)v30);
    v32 = (float)((float)-(float)((float)((float)((float)v31
                                                * (float)((float)((float)((float)v16 * (float)v16)
                                                                + (float)((float)((float)v18 * (float)v18)
                                                                        + (float)((float)v17 * (float)v17)))
                                                        * (float)0.5))
                                        * (float)v31)
                                - (float)1.5)
                * (float)v31);
    v33 = (float)((float)((float)-(float)((float)((float)((float)v31 * (float)v25) * (float)v31) - (float)1.5)
                        * (float)v31)
                * (float)v25);
    *v10 = (float)((float)((float)-(float)((float)((float)v33 * (float)v32) - (float)1.5) * (float)v32)
                 * this->properties->maxLinearVelocity)
         * *v10;
    v10[1] = (float)v27
           * (float)((float)((float)-(float)((float)((float)v33 * (float)v32) - (float)1.5) * (float)v32)
                   * (float)maxLinearVelocity);
    v10[2] = (float)v28
           * (float)((float)((float)-(float)((float)((float)v33 * (float)v32) - (float)1.5) * (float)v32)
                   * (float)maxLinearVelocity);
  }
  v34 = (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23));
  v35 = (float)((float)((float)v22 * (float)v22) + (float)v34);
  if ( v35 > (float)(v20->maxAngularVelocity * v20->maxAngularVelocity) )
  {
    v36 = (float)((float)((float)((float)v22 * (float)v22) + (float)v34) * (float)0.5);
    _FP9 = (float)((float)v35 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v39 = a4[17];
    __asm { fsel      f5, f9, f13, f11 }
    v41 = __frsqrte(_FP5);
    v42 = (float)((float)-(float)((float)((float)((float)v41 * (float)((float)v35 * (float)0.5)) * (float)v41)
                                - (float)1.5)
                * (float)v41);
    v38 = a4[16];
    v43 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42 * (float)v36)
                                                                                        * (float)v42)
                                                                                - (float)1.5)
                                                                * (float)v42)
                                                        * (float)v36)
                                                * (float)((float)-(float)((float)((float)((float)v42 * (float)v36)
                                                                                * (float)v42)
                                                                        - (float)1.5)
                                                        * (float)v42))
                                        - (float)1.5)
                        * (float)((float)-(float)((float)((float)((float)v42 * (float)v36) * (float)v42) - (float)1.5)
                                * (float)v42))
                * v20->maxAngularVelocity);
    a4[15] = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v42 * (float)v36)
                                                                                           * (float)v42)
                                                                                   - (float)1.5)
                                                                   * (float)v42)
                                                           * (float)v36)
                                                   * (float)((float)-(float)((float)((float)((float)v42 * (float)v36)
                                                                                   * (float)v42)
                                                                           - (float)1.5)
                                                           * (float)v42))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)v42 * (float)v36) * (float)v42) - (float)1.5)
                                   * (float)v42))
                   * v20->maxAngularVelocity)
           * a4[15];
    a4[16] = (float)v38 * (float)v43;
    a4[17] = (float)v43 * (float)v39;
  }
}


// ========================================================================
// ?CollisionImpulse@idEffectPhysicsRigidBody@@ABAXAAUtrace_t@@ABUimpactInfo_t@@MAAUeffectRBState_t@1@AAVidVec3@@3@Z
// EA  : 0x82707160
// RVA : 0x00707160
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idEffectPhysicsRigidBody::CollisionImpulse(
        idEffectPhysicsRigidBody *this,
        trace_t *collision,
        const impactInfo_t *impact,
        double extraMomentumDecay,
        idEffectPhysicsRigidBody::effectRBState_t *state,
        idVec3 *normalVelocity,
        idVec3 *impulse,
        float *a8)
{
  const idEffectPhysicsProperties *properties; // r11
  double z; // fp13
  double v11; // fp12
  double y; // fp11
  double v15; // fp10
  double v16; // fp9
  idMat3 *p_inverseInertiaTensor; // r5
  double x; // fp8
  double v19; // fp7
  double v21; // fp6
  idVec3 *v24; // r26
  const idMat3 *v25; // r31
  double v26; // fp27
  double v27; // fp26
  double v28; // fp25
  idMat3 *v29; // r3
  int v30; // r2 OVERLAPPED
  double v31; // fp1
  double v32; // fp0
  double v33; // fp10
  float v34; // r8
  float v35; // r7
  __int64 v36; // r6 OVERLAPPED
  idVec3 *v37; // r27
  double v38; // fp23
  double v39; // fp22
  double v40; // fp21
  double v41; // fp20
  double v42; // fp19
  double v43; // fp18
  double v44; // fp17
  double v45; // fp16
  double v46; // fp15
  double v47; // fp31
  double v48; // fp30
  double v49; // fp29
  int seed; // r11
  int v51; // r11
  double crazyBounceChance; // fp13
  int v53; // r29
  unsigned int v54; // r11
  __int64 v55; // r10
  int v56; // r3
  int v57; // r7
  int v58; // r3
  double v59; // fp2
  __int64 v60; // r11
  int v61; // r3
  __int64 v62; // r7
  const idEffectPhysicsProperties *v63; // r11
  double v64; // fp0
  double v65; // fp13
  double v66; // fp12
  double v67; // fp11
  double v68; // fp10
  double v69; // fp9
  double v70; // fp3
  double v71; // fp2
  double v72; // fp1
  double v73; // fp8
  double v74; // fp6
  double inverseMass; // fp8
  double v76; // fp7
  double v77; // fp7
  double v78; // fp7
  double v79; // fp5
  double v80; // fp27
  double v81; // fp30
  double v82; // fp29
  double v83; // fp25
  double v84; // fp15
  double v85; // fp26
  double v86; // fp17
  double v87; // fp14
  double v88; // fp5
  double v89; // fp31
  double v90; // fp4
  double v91; // fp27
  double v92; // fp30
  double v93; // fp29
  double v94; // fp31
  double v95; // fp5
  double v96; // fp30
  double v97; // fp4
  double v98; // fp7
  double v99; // fp6
  double v100; // fp5
  double v101; // fp4
  double v102; // fp1
  double v103; // fp9
  double v104; // fp2
  double v105; // fp7
  double v106; // fp10
  double v109; // fp9
  double v110; // fp11
  double v111; // fp9
  double v112; // fp8
  double v113; // fp11
  double v114; // fp10
  double v115; // fp9
  double v116; // fp8
  double v117; // fp2
  double v118; // fp2
  double v119; // fp7
  double v120; // fp10
  double v121; // fp7
  double v122; // fp4
  double v123; // fp3
  double v124; // fp7
  double v125; // fp5
  double v126; // fp13
  double v127; // fp12
  double v128; // fp11
  double v129; // fp10
  double v130; // fp9
  double v131; // fp7
  double v132; // fp4
  idTypesafeNumber<float,enum RadiansUnique_t> v133; // [sp+50h] [-1A0h] BYREF
  float v134; // [sp+54h] [-19Ch]
  float v135; // [sp+58h] [-198h]
  __int64 v136; // [sp+60h] [-190h]
  __int64 v137; // [sp+68h] [-188h]
  double v138; // [sp+70h] [-180h]
  idVec3 v139; // [sp+78h] [-178h] BYREF
  idVec3 v140; // [sp+88h] [-168h] BYREF
  idMat3 v141; // [sp+A0h] [-150h] BYREF
  idMat3 v142[5]; // [sp+D0h] [-120h] BYREF
  float v143; // [sp+21Ch] [+2Ch]

  properties = this->properties;
  z = normalVelocity[2].z;
  v11 = normalVelocity[1].z;
  y = normalVelocity[3].y;
  v15 = normalVelocity[2].y;
  v16 = normalVelocity[1].y;
  p_inverseInertiaTensor = &this->properties->inverseInertiaTensor;
  x = normalVelocity[3].x;
  v19 = normalVelocity[2].x;
  v21 = normalVelocity[1].x;
  v141.mat[2].z = normalVelocity[3].z;
  v141.mat[2].y = z;
  v24 = normalVelocity + 4;
  v141.mat[2].x = v11;
  v25 = (const idMat3 *)&normalVelocity[1];
  v141.mat[1].z = y;
  v141.mat[1].y = v15;
  v141.mat[1].x = v16;
  v141.mat[0].z = x;
  v141.mat[0].y = v19;
  v141.mat[0].x = v21;
  v26 = (float)(properties->inverseMass * normalVelocity[4].x);
  v27 = (float)(normalVelocity[4].y * properties->inverseMass);
  v28 = (float)(normalVelocity[4].z * properties->inverseMass);
  v143 = extraMomentumDecay;
  v29 = idMat3::operator*(this: v142, result: &v141, a: p_inverseInertiaTensor);
  idMat3::operator*(this: &v141, result: v29, a: v25);
  v31 = normalVelocity[5].y;
  v32 = normalVelocity[5].z;
  v33 = normalVelocity[5].x;
  v34 = collision->c.normal.y;
  v35 = collision->c.normal.z;
  LODWORD(v36) = this->properties;
  v37 = normalVelocity + 5;
  v140.x = collision->c.normal.x;
  v140.y = v34;
  v140.z = v35;
  v38 = v141.mat[2].x;
  v39 = v141.mat[2].y;
  v40 = v141.mat[1].z;
  v41 = v141.mat[0].x;
  v42 = v141.mat[0].y;
  v43 = v141.mat[2].z;
  v44 = v141.mat[1].x;
  v45 = v141.mat[1].y;
  v46 = v141.mat[0].z;
  v47 = (float)((float)((float)v31 * v141.mat[1].x)
              + (float)((float)((float)v33 * v141.mat[0].x) + (float)((float)v32 * v141.mat[2].x)));
  v48 = (float)((float)((float)v31 * v141.mat[1].y)
              + (float)((float)((float)v33 * v141.mat[0].y) + (float)((float)v32 * v141.mat[2].y)));
  v49 = (float)((float)((float)v33 * v141.mat[0].z)
              + (float)((float)((float)v32 * v141.mat[2].z) + (float)((float)v31 * v141.mat[1].z)));
  if ( *(float *)(v36 + 52) > 0.0 )
  {
    if ( (_S13_10 & 1) != 0 )
    {
      seed = random_2.seed;
    }
    else
    {
      _S13_10 |= 1u;
      seed = 0;
    }
    v51 = 1103515245 * seed + 12345;
    random_2.seed = v51;
    LODWORD(v36) = HIWORD(v51) & 0x7FFF;
    crazyBounceChance = this->properties->crazyBounceChance;
    v137 = v36;
    if ( (float)((float)v36 * (float)0.000030518509) <= crazyBounceChance )
    {
      v53 = 1103515245 * v51 + 12345;
      random_2.seed = v53;
      v54 = (HIWORD(v53) & 0x7FFF) - 3 * ((1431655766 * (unsigned __int64)(HIWORD(v53) & 0x7FFF)) >> 32);
      if ( v54 != 0 )
      {
        if ( v54 != 1 )
        {
          if ( v54 < 3 )
          {
            random_2.seed = 1103515245 * v53 + 12345;
            HIDWORD(v55) = 1103515245 * random_2.seed;
            LODWORD(v36) = HIWORD(random_2.seed) & 0x7FFF;
            random_2.seed = 1103515245 * random_2.seed + 12345;
            v53 = 1103515245 * random_2.seed + 12345;
            v56 = HIWORD(random_2.seed) & 0x7FFF;
            random_2.seed = v53;
            LODWORD(v55) = HIWORD(v53) & 0x7FFF;
            v139.z = (float)((float)v36 * (float)0.000027466658) + (float)0.1;
            v137 = v55;
            v139.y = (float)((float)*(__int64 *)(&v30 - 1) * (float)0.000061037019) - (float)1.0;
            v139.x = (float)((float)v55 * (float)0.000061037019) - (float)1.0;
          }
          goto LABEL_13;
        }
        random_2.seed = 1103515245 * v53 + 12345;
        v57 = HIWORD(random_2.seed) & 0x7FFF;
        random_2.seed = 1103515245 * random_2.seed + 12345;
        HIDWORD(v36) = HIWORD(random_2.seed) & 0x7FFF;
        v137 = *(__int64 *)((char *)&v36 + 4);
        v53 = 1103515245 * random_2.seed + 12345;
        random_2.seed = v53;
        v58 = HIWORD(v53) & 0x7FFF;
        v136 = *(_QWORD *)(&v30 - 1);
        v139.z = (float)((float)*(__int64 *)((char *)&v36 - 4) * (float)0.000061037019) - (float)1.0;
        v139.y = (float)((float)*(__int64 *)((char *)&v36 + 4) * (float)0.000027466658) + (float)0.1;
        v59 = (float)((float)((float)*(__int64 *)(&v30 - 1) * (float)0.000061037019) - (float)1.0);
      }
      else
      {
        random_2.seed = 1103515245 * v53 + 12345;
        HIDWORD(v60) = HIWORD(random_2.seed);
        LODWORD(v36) = HIWORD(random_2.seed) & 0x7FFF;
        random_2.seed = 1103515245 * random_2.seed + 12345;
        v53 = 1103515245 * random_2.seed + 12345;
        v61 = HIWORD(random_2.seed) & 0x7FFF;
        random_2.seed = v53;
        LODWORD(v60) = HIWORD(v53) & 0x7FFF;
        v139.z = (float)((float)v36 * (float)0.000061037019) - (float)1.0;
        v137 = v60;
        v139.y = (float)((float)*(__int64 *)(&v30 - 1) * (float)0.000061037019) - (float)1.0;
        v59 = (float)((float)((float)v60 * (float)0.000027466658) + (float)0.1);
      }
      v139.x = v59;
LABEL_13:
      idVec3::NormalizeFast(this: &v139);
      random_2.seed = 1103515245 * v53 + 12345;
      LODWORD(v62) = HIWORD(random_2.seed) & 0x7FFF;
      v137 = v62;
      v133.value = (float)((float)((float)((float)((float)v62 * (float)0.000061037019) - (float)1.0)
                                 * (float)((float)1.0 - v143))
                         * (float)3.1415927)
                 * (float)0.25;
      idVec3::RotateSelf(this: &v140, axis: &v139, angle: &v133);
    }
  }
  v63 = this->properties;
  v64 = (float)(collision->c.point.x - normalVelocity->x);
  v65 = (float)(collision->c.point.y - normalVelocity->y);
  v66 = (float)(collision->c.point.z - normalVelocity->z);
  v67 = v140.z;
  v68 = v140.x;
  v69 = v140.y;
  v70 = (float)((float)((float)((float)((float)(collision->c.point.y - normalVelocity->y) * (float)v47)
                              - (float)((float)v48 * (float)(collision->c.point.x - normalVelocity->x)))
                      + (float)v28)
              - impact->velocity.z);
  v71 = (float)((float)((float)((float)((float)(collision->c.point.z - normalVelocity->z) * (float)v48)
                              - (float)((float)(collision->c.point.y - normalVelocity->y) * (float)v49))
                      + (float)v26)
              - impact->velocity.x);
  v72 = (float)((float)((float)((float)((float)v49 * (float)(collision->c.point.x - normalVelocity->x))
                              - (float)((float)(collision->c.point.z - normalVelocity->z) * (float)v47))
                      + (float)v27)
              - impact->velocity.y);
  v73 = (float)-(float)((float)(v140.y
                              * (float)((float)((float)((float)((float)v49
                                                              * (float)(collision->c.point.x - normalVelocity->x))
                                                      - (float)((float)(collision->c.point.z - normalVelocity->z)
                                                              * (float)v47))
                                              + (float)v27)
                                      - impact->velocity.y))
                      + (float)((float)((float)((float)((float)((float)((float)(collision->c.point.z - normalVelocity->z)
                                                                      * (float)v48)
                                                              - (float)((float)(collision->c.point.y - normalVelocity->y)
                                                                      * (float)v49))
                                                      + (float)v26)
                                              - impact->velocity.x)
                                      * v140.x)
                              + (float)(v140.z
                                      * (float)((float)((float)((float)((float)(collision->c.point.y - normalVelocity->y)
                                                                      * (float)v47)
                                                              - (float)((float)v48
                                                                      * (float)(collision->c.point.x - normalVelocity->x)))
                                                      + (float)v28)
                                              - impact->velocity.z))));
  impulse->x = v140.x
             * (float)-(float)((float)(v140.y
                                     * (float)((float)((float)((float)((float)v49
                                                                     * (float)(collision->c.point.x - normalVelocity->x))
                                                             - (float)((float)(collision->c.point.z - normalVelocity->z)
                                                                     * (float)v47))
                                                     + (float)v27)
                                             - impact->velocity.y))
                             + (float)((float)((float)((float)((float)((float)((float)(collision->c.point.z
                                                                                     - normalVelocity->z)
                                                                             * (float)v48)
                                                                     - (float)((float)(collision->c.point.y
                                                                                     - normalVelocity->y)
                                                                             * (float)v49))
                                                             + (float)v26)
                                                     - impact->velocity.x)
                                             * v140.x)
                                     + (float)(v140.z
                                             * (float)((float)((float)((float)((float)(collision->c.point.y
                                                                                     - normalVelocity->y)
                                                                             * (float)v47)
                                                                     - (float)((float)v48
                                                                             * (float)(collision->c.point.x
                                                                                     - normalVelocity->x)))
                                                             + (float)v28)
                                                     - impact->velocity.z))));
  impulse->y = (float)v69 * (float)v73;
  impulse->z = (float)v67 * (float)v73;
  if ( v73 >= v63->stopSpeed )
    v74 = (float)((float)((float)(v63->bouncyness * (float)((float)1.0 - v143)) + (float)1.0) * (float)v73);
  else
    v74 = (float)(v63->stopSpeed * (float)0.5);
  inverseMass = v63->inverseMass;
  if ( !v63->simplePointCollision )
  {
    v76 = (float)((float)((float)((float)((float)v42
                                        * (float)((float)((float)v67 * (float)v65) - (float)((float)v69 * (float)v66)))
                                + (float)((float)((float)((float)((float)v66 * (float)v68)
                                                        - (float)((float)v67 * (float)v64))
                                                * (float)v45)
                                        + (float)((float)((float)((float)v69 * (float)v64)
                                                        - (float)((float)v65 * (float)v68))
                                                * (float)v39)))
                        * (float)v66)
                - (float)((float)((float)((float)v46
                                        * (float)((float)((float)v67 * (float)v65) - (float)((float)v69 * (float)v66)))
                                + (float)((float)((float)((float)((float)v66 * (float)v68)
                                                        - (float)((float)v67 * (float)v64))
                                                * (float)v40)
                                        + (float)((float)((float)((float)v69 * (float)v64)
                                                        - (float)((float)v65 * (float)v68))
                                                * (float)v43)))
                        * (float)v65));
    v77 = (float)((float)((float)v76 * (float)v68)
                + (float)((float)((float)((float)((float)((float)v46
                                                        * (float)((float)((float)v67 * (float)v65)
                                                                - (float)((float)v69 * (float)v66)))
                                                + (float)((float)((float)((float)((float)v66 * (float)v68)
                                                                        - (float)((float)v67 * (float)v64))
                                                                * (float)v40)
                                                        + (float)((float)((float)((float)v69 * (float)v64)
                                                                        - (float)((float)v65 * (float)v68))
                                                                * (float)v43)))
                                        * (float)v64)
                                - (float)((float)v66
                                        * (float)((float)((float)((float)((float)v69 * (float)v64)
                                                                - (float)((float)v65 * (float)v68))
                                                        * (float)v38)
                                                + (float)((float)((float)((float)((float)v67 * (float)v65)
                                                                        - (float)((float)v69 * (float)v66))
                                                                * (float)v41)
                                                        + (float)((float)((float)((float)v66 * (float)v68)
                                                                        - (float)((float)v67 * (float)v64))
                                                                * (float)v44)))))
                        * (float)v69));
    inverseMass = (float)((float)((float)((float)((float)((float)v65
                                                        * (float)((float)((float)((float)((float)v69 * (float)v64)
                                                                                - (float)((float)v65 * (float)v68))
                                                                        * (float)v38)
                                                                + (float)((float)((float)((float)((float)v67 * (float)v65)
                                                                                        - (float)((float)v69 * (float)v66))
                                                                                * (float)v41)
                                                                        + (float)((float)((float)((float)v66 * (float)v68)
                                                                                        - (float)((float)v67 * (float)v64))
                                                                                * (float)v44))))
                                                - (float)((float)((float)((float)v42
                                                                        * (float)((float)((float)v67 * (float)v65)
                                                                                - (float)((float)v69 * (float)v66)))
                                                                + (float)((float)((float)((float)((float)v66 * (float)v68)
                                                                                        - (float)((float)v67 * (float)v64))
                                                                                * (float)v45)
                                                                        + (float)((float)((float)((float)v69 * (float)v64)
                                                                                        - (float)((float)v65 * (float)v68))
                                                                                * (float)v39)))
                                                        * (float)v64))
                                        * (float)v67)
                                + (float)v77)
                        + v63->inverseMass);
  }
  if ( impact->invMass != 0.0 )
  {
    inverseMass = (float)(impact->invMass + (float)inverseMass);
    if ( !v63->simplePointCollision )
    {
      v133.value = impact->invInertiaTensor.mat[1].y;
      v138 = v64;
      v78 = impact->position.x;
      v79 = (float)((float)v67 * impact->position.x);
      v80 = (float)(impact->position.z * (float)v69);
      v81 = (float)(impact->position.y * (float)v68);
      v82 = impact->invInertiaTensor.mat[1].x;
      v83 = impact->invInertiaTensor.mat[1].z;
      v84 = impact->position.y;
      v85 = impact->invInertiaTensor.mat[2].x;
      v86 = impact->position.z;
      v134 = impact->invInertiaTensor.mat[2].z;
      v135 = impact->invInertiaTensor.mat[2].y;
      v87 = impact->invInertiaTensor.mat[0].x;
      v88 = (float)((float)((float)v86 * (float)v68) - (float)v79);
      v89 = impact->invInertiaTensor.mat[0].z;
      v90 = (float)((float)((float)v84 * (float)v67) - (float)v80);
      v91 = impact->invInertiaTensor.mat[0].y;
      v92 = (float)((float)((float)v69 * (float)v78) - (float)v81);
      *(float *)&v137 = v84;
      *(float *)&v136 = v86;
      v44 = v141.mat[1].x;
      v42 = v141.mat[0].y;
      v45 = v141.mat[1].y;
      v46 = v141.mat[0].z;
      v43 = v141.mat[2].z;
      v93 = (float)((float)((float)v85 * (float)v92) + (float)((float)v82 * (float)v88));
      v94 = (float)((float)((float)v89 * (float)v90)
                  + (float)((float)(v134 * (float)v92) + (float)((float)v83 * (float)v88)));
      v95 = (float)((float)(v135 * (float)v92) + (float)(v133.value * (float)v88));
      v96 = (float)((float)((float)v90 * (float)v87) + (float)v93);
      v97 = (float)((float)((float)v91 * (float)v90) + (float)v95);
      inverseMass = (float)((float)((float)((float)((float)((float)v96 * *(float *)&v137)
                                                  - (float)((float)v97 * (float)v78))
                                          * (float)v67)
                                  + (float)((float)((float)((float)((float)v97 * *(float *)&v136)
                                                          - (float)((float)v94 * *(float *)&v137))
                                                  * (float)v68)
                                          + (float)((float)((float)((float)v94 * (float)v78)
                                                          - (float)((float)v96 * *(float *)&v136))
                                                  * (float)v69)))
                          + (float)inverseMass);
    }
  }
  v98 = (float)((float)v74 / (float)inverseMass);
  v99 = (float)((float)((float)v74 / (float)inverseMass) * (float)v68);
  *a8 = v99;
  v100 = (float)((float)v69 * (float)v98);
  a8[1] = (float)v69 * (float)v98;
  v101 = (float)((float)v67 * (float)v98);
  a8[2] = (float)v67 * (float)v98;
  v102 = -(float)((float)v72 + impulse->y);
  v103 = (float)(impulse->x + (float)v71);
  v104 = -(float)(impulse->z + (float)v70);
  v105 = v63->inverseMass;
  v106 = -v103;
  _FP9 = (float)((float)((float)((float)v106 * (float)v106)
                       + (float)((float)((float)v104 * (float)v104) + (float)((float)v102 * (float)v102)))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f11, f9, f3, f11 }
  v109 = __frsqrte(_FP11);
  v110 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v109
                                                                                       * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v104 * (float)v104) + (float)((float)v102 * (float)v102)))
                                                                                               * (float)0.5))
                                                                               * (float)v109)
                                                                       - (float)1.5)
                                                       * (float)v109)
                                               * (float)((float)((float)((float)v106 * (float)v106)
                                                               + (float)((float)((float)v104 * (float)v104)
                                                                       + (float)((float)v102 * (float)v102)))
                                                       * (float)0.5))
                                       * (float)((float)-(float)((float)((float)((float)v109
                                                                               * (float)((float)((float)((float)v106 * (float)v106)
                                                                                               + (float)((float)((float)v104 * (float)v104) + (float)((float)v102 * (float)v102)))
                                                                                       * (float)0.5))
                                                                       * (float)v109)
                                                               - (float)1.5)
                                               * (float)v109))
                               - (float)1.5)
               * (float)((float)-(float)((float)((float)((float)v109
                                                       * (float)((float)((float)((float)v106 * (float)v106)
                                                                       + (float)((float)((float)v104 * (float)v104)
                                                                               + (float)((float)v102 * (float)v102)))
                                                               * (float)0.5))
                                               * (float)v109)
                                       - (float)1.5)
                       * (float)v109));
  v111 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v104 * (float)v104) + (float)((float)v102 * (float)v102))) * (float)0.5)) * (float)v109) - (float)1.5)
                                                                                               * (float)v109)
                                                                                       * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v104 * (float)v104) + (float)((float)v102 * (float)v102)))
                                                                                               * (float)0.5))
                                                                               * (float)((float)-(float)((float)((float)((float)v109 * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v104 * (float)v104) + (float)((float)v102 * (float)v102))) * (float)0.5)) * (float)v109) - (float)1.5)
                                                                                       * (float)v109))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)((float)v109
                                                                                               * (float)((float)((float)((float)v106 * (float)v106) + (float)((float)((float)v104 * (float)v104) + (float)((float)v102 * (float)v102))) * (float)0.5))
                                                                                       * (float)v109)
                                                                               - (float)1.5)
                                                               * (float)v109))
                                               * (float)((float)((float)((float)v106 * (float)v106)
                                                               + (float)((float)((float)v104 * (float)v104)
                                                                       + (float)((float)v102 * (float)v102)))
                                                       * (float)0.5))
                                       * (float)v110)
                               - (float)1.5)
               * (float)v110);
  v112 = (float)((float)v111
               * (float)((float)((float)v106 * (float)v106)
                       + (float)((float)((float)v104 * (float)v104) + (float)((float)v102 * (float)v102))));
  v113 = (float)((float)v106 * (float)v111);
  v114 = (float)((float)v102 * (float)v111);
  v115 = (float)((float)v104 * (float)v111);
  v116 = (float)((float)v112 * v63->contactFriction);
  if ( !v63->simplePointCollision )
  {
    v117 = (float)((float)((float)v65
                         * (float)((float)((float)((float)((float)v114 * (float)v64) - (float)((float)v65 * (float)v113))
                                         * (float)v38)
                                 + (float)((float)((float)((float)((float)v115 * (float)v65)
                                                         - (float)((float)v114 * (float)v66))
                                                 * (float)v41)
                                         + (float)((float)((float)((float)v66 * (float)v113)
                                                         - (float)((float)v115 * (float)v64))
                                                 * (float)v44))))
                 - (float)((float)((float)((float)v42
                                         * (float)((float)((float)v115 * (float)v65) - (float)((float)v114 * (float)v66)))
                                 + (float)((float)((float)((float)((float)v66 * (float)v113)
                                                         - (float)((float)v115 * (float)v64))
                                                 * (float)v45)
                                         + (float)((float)((float)((float)v114 * (float)v64)
                                                         - (float)((float)v65 * (float)v113))
                                                 * (float)v39)))
                         * (float)v64));
    v118 = (float)((float)((float)v117 * (float)v115)
                 + (float)((float)((float)((float)((float)((float)v46
                                                         * (float)((float)((float)v115 * (float)v65)
                                                                 - (float)((float)v114 * (float)v66)))
                                                 + (float)((float)((float)((float)((float)v66 * (float)v113)
                                                                         - (float)((float)v115 * (float)v64))
                                                                 * (float)v40)
                                                         + (float)((float)((float)((float)v114 * (float)v64)
                                                                         - (float)((float)v65 * (float)v113))
                                                                 * (float)v43)))
                                         * (float)v64)
                                 - (float)((float)v66
                                         * (float)((float)((float)((float)((float)v114 * (float)v64)
                                                                 - (float)((float)v65 * (float)v113))
                                                         * (float)v38)
                                                 + (float)((float)((float)((float)((float)v115 * (float)v65)
                                                                         - (float)((float)v114 * (float)v66))
                                                                 * (float)v41)
                                                         + (float)((float)((float)((float)v66 * (float)v113)
                                                                         - (float)((float)v115 * (float)v64))
                                                                 * (float)v44)))))
                         * (float)v114));
    v105 = (float)((float)((float)((float)((float)((float)((float)((float)v42
                                                                 * (float)((float)((float)v115 * (float)v65)
                                                                         - (float)((float)v114 * (float)v66)))
                                                         + (float)((float)((float)((float)((float)v66 * (float)v113)
                                                                                 - (float)((float)v115 * (float)v64))
                                                                         * (float)v45)
                                                                 + (float)((float)((float)((float)v114 * (float)v64)
                                                                                 - (float)((float)v65 * (float)v113))
                                                                         * (float)v39)))
                                                 * (float)v66)
                                         - (float)((float)((float)((float)v46
                                                                 * (float)((float)((float)v115 * (float)v65)
                                                                         - (float)((float)v114 * (float)v66)))
                                                         + (float)((float)((float)((float)((float)v66 * (float)v113)
                                                                                 - (float)((float)v115 * (float)v64))
                                                                         * (float)v40)
                                                                 + (float)((float)((float)((float)v114 * (float)v64)
                                                                                 - (float)((float)v65 * (float)v113))
                                                                         * (float)v43)))
                                                 * (float)v65))
                                 * (float)v113)
                         + (float)v118)
                 + v63->inverseMass);
  }
  v119 = (float)((float)v116 / (float)v105);
  a8[1] = (float)((float)v114 * (float)v119) + (float)v100;
  v120 = (float)((float)v115 * (float)v119);
  v121 = (float)((float)((float)v119 * (float)v113) + (float)v99);
  *a8 = v121;
  a8[2] = (float)v120 + (float)v101;
  v24->x = (float)v121 + v24->x;
  v24->y = v24->y + a8[1];
  v24->z = a8[2] + v24->z;
  v122 = normalVelocity[5].y;
  v123 = normalVelocity[5].z;
  v124 = (float)(*a8 * (float)v65);
  v125 = (float)((float)(a8[2] * (float)v65) - (float)(a8[1] * (float)v66));
  v126 = (float)((float)(*a8 * (float)v66) - (float)(a8[2] * (float)v64));
  v127 = (float)((float)(a8[1] * (float)v64) - (float)v124);
  v128 = (float)((float)v125 + v37->x);
  v37->x = (float)v125 + v37->x;
  normalVelocity[5].y = (float)v126 + (float)v122;
  normalVelocity[5].z = (float)v127 + (float)v123;
  normalVelocity[5].z = (float)((float)1.0 - v143) * (float)((float)v127 + (float)v123);
  normalVelocity[5].y = (float)((float)1.0 - v143) * (float)((float)v126 + (float)v122);
  v37->x = (float)((float)1.0 - v143) * (float)v128;
  if ( collision->fraction < 0.000099999997 )
  {
    v129 = (float)(v24->z * (float)0.5);
    v130 = (float)(v24->x * (float)0.5);
    v24->y = v24->y * (float)0.5;
    v24->z = v129;
    v24->x = v130;
    v131 = (float)(normalVelocity[5].z * (float)0.5);
    v132 = (float)(normalVelocity[5].y * (float)0.5);
    v37->x = v37->x * (float)0.5;
    normalVelocity[5].y = v132;
    normalVelocity[5].z = v131;
  }
}


// ========================================================================
// ?ApplyImpulse@idEffectPhysicsRigidBody@@QAAXABVidVec3@@0@Z
// EA  : 0x82707A28
// RVA : 0x00707A28
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.cpp
// ========================================================================

void __fastcall idEffectPhysicsRigidBody::ApplyImpulse(
        idEffectPhysicsRigidBody *this,
        const idVec3 *point,
        const idVec3 *impulse)
{
  double y; // fp0
  double z; // fp13
  double x; // fp12
  double v6; // fp10
  double v7; // fp13
  double v8; // fp1

  this->settled = false;
  y = this->currentState.linearMomentum.y;
  z = this->currentState.linearMomentum.z;
  this->currentState.linearMomentum.x = this->currentState.linearMomentum.x + impulse->x;
  this->currentState.linearMomentum.y = impulse->y + (float)y;
  this->currentState.linearMomentum.z = (float)z + impulse->z;
  x = this->currentState.angularMomentum.x;
  v6 = this->currentState.angularMomentum.y;
  v7 = (float)((float)(impulse->x * (float)(point->z - this->currentState.position.z))
             - (float)(impulse->z * (float)(point->x - this->currentState.position.x)));
  v8 = (float)((float)(impulse->z * (float)(point->y - this->currentState.position.y))
             - (float)(impulse->y * (float)(point->z - this->currentState.position.z)));
  this->currentState.angularMomentum.z = this->currentState.angularMomentum.z
                                       + (float)((float)(impulse->y * (float)(point->x - this->currentState.position.x))
                                               - (float)(impulse->x * (float)(point->y - this->currentState.position.y)));
  this->currentState.angularMomentum.y = (float)v6 + (float)v7;
  this->currentState.angularMomentum.x = (float)x + (float)v8;
}


// ========================================================================
// ?Evolve@idEffectPhysicsRigidBody@@ABAXMABUeffectRBState_t@1@AAUeffectRBDelta_t@1@@Z
// EA  : 0x82707AD8
// RVA : 0x00707AD8
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.cpp
// ========================================================================

void __fastcall idEffectPhysicsRigidBody::Evolve(
        idEffectPhysicsRigidBody *this,
        double deltaTime,
        const idEffectPhysicsRigidBody::effectRBState_t *current,
        idEffectPhysicsRigidBody::effectRBDelta_t *delta,
        int a5)
{
  double z; // fp13
  const idEffectPhysicsProperties *properties; // r11
  double v8; // fp12
  double y; // fp10
  double v12; // fp9
  double angle; // fp8
  double x; // fp7
  float *p_z; // r29
  double v17; // fp6
  idRotation *p_rotation; // r27
  double v19; // fp27
  double v20; // fp29
  double v21; // fp28
  double v22; // fp26
  double v23; // fp25
  idMat3 *v24; // r3
  double v25; // fp12
  double v26; // fp11
  double v27; // fp0
  double v28; // fp13
  double v29; // fp1
  double v30; // fp10
  double v31; // fp4
  double v33; // fp6
  double v35; // fp2
  double v36; // fp11
  double v37; // fp2
  double v38; // fp4
  idVec3 *v39; // r10
  const idEffectPhysicsProperties *v40; // r10
  double v41; // fp2
  double v42; // fp1
  double v43; // fp1
  double v44; // fp0
  float v45[4]; // [sp+50h] [-D0h] BYREF
  idMat3 v46; // [sp+60h] [-C0h] BYREF
  idMat3 v47[2]; // [sp+90h] [-90h] BYREF

  z = delta->rotation.vec.z;
  properties = this->properties;
  v8 = delta->rotation.origin.z;
  v46.mat[2].z = delta->rotation.axis.mat[0].y;
  v46.mat[2].y = z;
  y = delta->rotation.vec.y;
  v12 = delta->rotation.origin.y;
  angle = delta->rotation.angle;
  x = delta->rotation.vec.x;
  p_z = &delta->rotation.axis.mat[0].z;
  v17 = delta->rotation.origin.x;
  p_rotation = &delta->rotation;
  v46.mat[1].z = delta->rotation.axis.mat[0].x;
  v46.mat[2].x = v8;
  v46.mat[1].y = y;
  v46.mat[1].x = v12;
  v46.mat[0].z = angle;
  v46.mat[0].y = x;
  v46.mat[0].x = v17;
  v19 = (float)(delta->rotation.axis.mat[0].z * properties->inverseMass);
  v20 = (float)((float)(properties->linearFrictionWater * (float)0.0) + properties->linearFriction);
  v21 = (float)((float)(properties->angularFrictionWater * (float)0.0) + properties->angularFriction);
  v22 = (float)(delta->rotation.axis.mat[1].x * properties->inverseMass);
  v23 = (float)(delta->rotation.axis.mat[1].y * properties->inverseMass);
  v24 = idMat3::operator*(this: v47, result: &v46, a: &properties->inverseInertiaTensor);
  idMat3::operator*(this: &v46, result: v24, a: (const idMat3 *)p_rotation);
  v25 = idMath::FLT_SMALLEST_NON_DENORMAL;
  v26 = (float)((float)(v46.mat[0].z * delta->rotation.axis.mat[1].z)
              + (float)((float)(delta->rotation.axis.mat[2].y * v46.mat[2].z)
                      + (float)(delta->rotation.axis.mat[2].x * v46.mat[1].z)));
  v27 = (float)((float)(v46.mat[0].x * delta->rotation.axis.mat[1].z)
              + (float)((float)(delta->rotation.axis.mat[2].y * v46.mat[2].x)
                      + (float)(delta->rotation.axis.mat[2].x * v46.mat[1].x)));
  v28 = (float)((float)(v46.mat[0].y * delta->rotation.axis.mat[1].z)
              + (float)((float)(delta->rotation.axis.mat[2].y * v46.mat[2].y)
                      + (float)(delta->rotation.axis.mat[2].x * v46.mat[1].y)));
  v29 = v26;
  v30 = idMath::M_RAD2DEG;
  *(float *)a5 = (float)v19 * (float)deltaTime;
  *(float *)(a5 + 4) = (float)v22 * (float)deltaTime;
  *(float *)(a5 + 8) = (float)v23 * (float)deltaTime;
  v31 = (float)((float)((float)v27 * (float)v27)
              + (float)((float)((float)v26 * (float)v26) + (float)((float)v28 * (float)v28)));
  _FP7 = (float)((float)((float)((float)v27 * (float)v27)
                       + (float)((float)((float)v26 * (float)v26) + (float)((float)v28 * (float)v28)))
               - (float)v25);
  v33 = (float)((float)((float)((float)v27 * (float)v27)
                      + (float)((float)((float)v26 * (float)v26) + (float)((float)v28 * (float)v28)))
              * (float)0.5);
  __asm { fsel      f5, f7, f4, f12 }
  v35 = __frsqrte(_FP5);
  v36 = (float)((float)v35
              * (float)((float)((float)((float)v27 * (float)v27)
                              + (float)((float)((float)v26 * (float)v26) + (float)((float)v28 * (float)v28)))
                      * (float)0.5));
  v37 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v36 * (float)v35) - (float)1.5)
                                                      * (float)v35)
                                              * (float)v33)
                                      * (float)((float)-(float)((float)((float)v36 * (float)v35) - (float)1.5)
                                              * (float)v35))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)v36 * (float)v35) - (float)1.5) * (float)v35));
  v45[1] = (float)v28
         * (float)((float)-(float)((float)((float)((float)v37 * (float)v33) * (float)v37) - (float)1.5) * (float)v37);
  v45[0] = (float)v27
         * (float)((float)-(float)((float)((float)((float)v37 * (float)v33) * (float)v37) - (float)1.5) * (float)v37);
  v45[2] = (float)v29
         * (float)((float)-(float)((float)((float)((float)v37 * (float)v33) * (float)v37) - (float)1.5) * (float)v37);
  v38 = (float)((float)((float)((float)-(float)((float)((float)((float)v37 * (float)v33) * (float)v37) - (float)1.5)
                              * (float)v37)
                      * (float)v31)
              * (float)v30);
  if ( (float)((float)-v38 * (float)deltaTime) == 0.0 )
    v39 = &vec3_up;
  else
    v39 = (idVec3 *)v45;
  *(float *)(a5 + 24) = v39->x;
  *(float *)(a5 + 28) = v39->y;
  *(float *)(a5 + 32) = v39->z;
  *(_BYTE *)(a5 + 76) = 0;
  *(float *)(a5 + 36) = (float)-v38 * (float)deltaTime;
  *(_BYTE *)(a5 + 76) = 0;
  v40 = this->properties;
  *(float *)(a5 + 12) = delta->translation.x;
  *(float *)(a5 + 16) = delta->translation.y;
  *(float *)(a5 + 20) = delta->translation.z;
  v41 = (float)((float)(delta->linearForce.x - (float)(p_z[2] * (float)v20)) + (float)(v40->gravityVector.z * v40->mass));
  v42 = (float)((float)(*(float *)&delta->rotation.axisValid - (float)(p_z[1] * (float)v20))
              + (float)(v40->gravityVector.y * v40->mass));
  *(float *)(a5 + 80) = (float)((float)(delta->rotation.axis.mat[2].z - (float)(*p_z * (float)v20))
                              + (float)(v40->gravityVector.x * v40->mass))
                      * (float)deltaTime;
  *(float *)(a5 + 88) = (float)v41 * (float)deltaTime;
  *(float *)(a5 + 84) = (float)v42 * (float)deltaTime;
  v43 = (float)(delta->angularForce.x - (float)(delta->rotation.axis.mat[2].y * (float)v21));
  v44 = (float)(delta->linearForce.z - (float)(delta->rotation.axis.mat[2].x * (float)v21));
  *(float *)(a5 + 92) = (float)(delta->linearForce.y - (float)((float)v21 * delta->rotation.axis.mat[1].z))
                      * (float)deltaTime;
  *(float *)(a5 + 100) = (float)v43 * (float)deltaTime;
  *(float *)(a5 + 96) = (float)v44 * (float)deltaTime;
}


// ========================================================================
// ??1idEffectPhysicsRigidBody@@QAA@XZ
// EA  : 0x82707E08
// RVA : 0x00707E08
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.cpp
// ========================================================================

void __fastcall idEffectPhysicsRigidBody::~idEffectPhysicsRigidBody(idEffectPhysicsRigidBody *this)
{
  const idEffectPhysicsProperties *properties; // r11

  properties = this->properties;
  if ( this->properties != nullptr && properties->broadPhase != nullptr )
  {
    idEffectPhysicsBroadPhase::RemoveObject(this: properties->broadPhase, object: &this->SPObject);
    this->properties = nullptr;
  }
  this->active = false;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->SPObject.overlap);
}


// ========================================================================
// __unwind$247901
// EA  : 0x82707E60
// RVA : 0x00707E60
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.cpp
// ========================================================================

void _unwind_247901()
{
  int v0; // r12

  idSPObject::~idSPObject(this: (idSPObject *)(*(_DWORD *)(v0 - 112 + 132) + 104));
}


// ========================================================================
// ?Update@idEffectPhysicsRigidBody@@QAAXMMAAVidEffectPhysicsCollision@@@Z
// EA  : 0x82707E90
// RVA : 0x00707E90
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.cpp
// ========================================================================

void __fastcall idEffectPhysicsRigidBody::Update(
        idEffectPhysicsRigidBody *this,
        double deltaTime,
        double extraMomentumDecay,
        idEffectPhysicsRigidBody::effectRBState_t *collision,
        int a5,
        int a6)
{
  float *v10; // r29
  char v11; // r27
  unsigned int offset; // r11
  char v13; // r11
  bool v14; // zf
  idEffectPhysicsRigidBody::effectRBState_t *v15; // r6
  bool v16; // mr_fpscr48
  int surfaceType; // r10
  double y; // fp12
  double z; // fp11
  double v20; // fp9
  double v21; // fp8
  double v22; // fp0
  const idEffectPhysicsRigidBody::effectRBState_t *v23; // r4
  const char *v24; // r7
  double v25; // fp7
  double v26; // fp6
  double v27; // fp12
  double v28; // fp11
  idVec3 v29; // [sp+50h] [-1B0h] BYREF
  impactInfo_t v30; // [sp+60h] [-1A0h] BYREF
  idVec3 v31; // [sp+A0h] [-160h] BYREF
  idRotation v32; // [sp+ACh] [-154h] BYREF
  float v33; // [sp+F0h] [-110h]
  float v34; // [sp+F4h] [-10Ch]
  float v35; // [sp+F8h] [-108h]
  float v36; // [sp+FCh] [-104h]
  float v37; // [sp+100h] [-100h]
  float v38; // [sp+104h] [-FCh]
  float v39[6]; // [sp+108h] [-F8h] BYREF
  trace_t v40; // [sp+120h] [-E0h] BYREF

  if ( this->active && !this->settled )
  {
    v10 = (float *)(a6 + 12);
    v11 = 0;
    *(float *)a6 = 0.0;
    *(float *)(a6 + 8) = 0.0;
    *(float *)(a6 + 4) = 0.0;
    *(float *)(a6 + 20) = 0.0;
    *(float *)(a6 + 16) = 0.0;
    *(float *)(a6 + 12) = 0.0;
    *(_DWORD *)(a6 + 24) = 0;
    offset = this->SPObject.query.offset;
    if ( offset < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
      || (v14 = offset < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v13 = 1, !v14) )
    {
      v13 = 0;
    }
    if ( v13 != 0 )
    {
      idEffectPhysicsBroadPhase::GetMotionResult(
        this: this->properties->broadPhase,
        result: &v40,
        object: &this->SPObject);
      this->currentState.position.x = this->SPObject.origin.x;
      this->currentState.position.y = this->SPObject.origin.y;
      this->currentState.position.z = this->SPObject.origin.z;
      this->currentState.orientation.mat[0].x = this->SPObject.axis.mat[0].x;
      this->currentState.orientation.mat[0].y = this->SPObject.axis.mat[0].y;
      this->currentState.orientation.mat[0].z = this->SPObject.axis.mat[0].z;
      this->currentState.orientation.mat[1].x = this->SPObject.axis.mat[1].x;
      this->currentState.orientation.mat[1].y = this->SPObject.axis.mat[1].y;
      this->currentState.orientation.mat[1].z = this->SPObject.axis.mat[1].z;
      this->currentState.orientation.mat[2].x = this->SPObject.axis.mat[2].x;
      this->currentState.orientation.mat[2].y = this->SPObject.axis.mat[2].y;
      v16 = v40.fraction < 1.0;
      this->currentState.orientation.mat[2].z = this->SPObject.axis.mat[2].z;
      if ( v16 )
      {
        v30.invInertiaTensor.mat[2].z = 1.0;
        v30.invInertiaTensor.mat[1].y = 1.0;
        v30.invInertiaTensor.mat[0].x = 1.0;
        v30.invInertiaTensor.mat[1].z = 0.0;
        v30.invInertiaTensor.mat[0].z = 0.0;
        v30.invInertiaTensor.mat[0].y = 0.0;
        v30.invInertiaTensor.mat[2].y = 0.0;
        v30.invInertiaTensor.mat[2].x = 0.0;
        v30.invInertiaTensor.mat[1].x = 0.0;
        v30.invMass = 0.0;
        v30.position.z = 0.0;
        v30.position.y = 0.0;
        v30.position.x = 0.0;
        v30.velocity.z = 0.0;
        v30.velocity.y = 0.0;
        v30.velocity.x = 0.0;
        idEffectPhysicsRigidBody::CollisionImpulse(
          this,
          collision: &v40,
          impact: &v30,
          extraMomentumDecay,
          state: v15,
          normalVelocity: &this->currentState.position,
          impulse: &v29,
          a8: v39);
        surfaceType = v40.c.surfaceType;
        y = v40.c.point.y;
        z = v40.c.point.z;
        *(float *)a6 = v40.c.point.x;
        *(float *)(a6 + 4) = y;
        *(float *)(a6 + 8) = z;
        v20 = v29.y;
        v21 = v29.z;
        *v10 = v29.x;
        v10[1] = v20;
        v10[2] = v21;
        *(_DWORD *)(a6 + 24) = surfaceType;
        v22 = __fsqrts((float)((float)(this->currentState.linearMomentum.x * this->currentState.linearMomentum.x)
                             + (float)(this->currentState.linearMomentum.y * this->currentState.linearMomentum.y)));
        if ( v22 <= 10.0 && this->currentState.linearMomentum.z < 0.0 )
        {
          if ( v22 >= 2.0 )
            v11 = 1;
          else
            this->settled = true;
        }
      }
    }
    idEffectPhysicsRigidBody::CapVelocity(this, deltaTime, current: collision, a4: &this->currentState.position.x);
    idEffectPhysicsRigidBody::Evolve(
      this,
      deltaTime,
      current: v23,
      delta: (idEffectPhysicsRigidBody::effectRBDelta_t *)&this->currentState,
      a5: (int)&v31);
    idEffectPhysicsBroadPhase::ApplyMotion(
      this: this->properties->broadPhase,
      object: &this->SPObject,
      translation: &v31,
      rotation: &v32,
      a5: v24);
    if ( v11 != 0 && (float)((float)(v31.y * v31.y) + (float)(v31.x * v31.x)) < 0.000099999997 )
      this->settled = true;
    if ( this->settled )
    {
      this->SPObject.motion.valid = false;
      this->currentState.linearMomentum.z = 0.0;
      this->currentState.linearMomentum.y = 0.0;
      this->currentState.linearMomentum.x = 0.0;
      this->currentState.angularMomentum.z = 0.0;
      this->currentState.angularMomentum.y = 0.0;
      this->currentState.angularMomentum.x = 0.0;
      *(float *)(a6 + 8) = 0.0;
      *(float *)(a6 + 4) = 0.0;
      *(float *)a6 = 0.0;
      v10[2] = 0.0;
      v10[1] = 0.0;
      *v10 = 0.0;
      *(_DWORD *)(a6 + 24) = 0;
    }
    else
    {
      v25 = (float)(this->currentState.linearMomentum.x + v33);
      v26 = (float)(this->currentState.linearMomentum.z + v35);
      this->currentState.linearMomentum.y = this->currentState.linearMomentum.y + v34;
      this->currentState.linearMomentum.x = v25;
      this->currentState.linearMomentum.z = v26;
      v27 = (float)(this->currentState.angularMomentum.z + v38);
      v28 = (float)(this->currentState.angularMomentum.y + v37);
      this->currentState.angularMomentum.x = this->currentState.angularMomentum.x + v36;
      this->currentState.angularMomentum.y = v28;
      this->currentState.angularMomentum.z = v27;
    }
    this->currentState.externalForce.z = 0.0;
    this->currentState.externalForce.y = 0.0;
    this->currentState.externalForce.x = 0.0;
    this->currentState.externalTorque.z = 0.0;
    this->currentState.externalTorque.y = 0.0;
    this->currentState.externalTorque.x = 0.0;
  }
}


// ========================================================================
// ??0idEffectPhysicsRigidBody@@QAA@XZ
// EA  : 0x82708200
// RVA : 0x00708200
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsrigidbody.cpp
// ========================================================================

idEffectPhysicsRigidBody *__fastcall idEffectPhysicsRigidBody::idEffectPhysicsRigidBody(idEffectPhysicsRigidBody *this)
{
  this->properties = nullptr;
  idSPObject::idSPObject(this: &this->SPObject);
  return this;
}

