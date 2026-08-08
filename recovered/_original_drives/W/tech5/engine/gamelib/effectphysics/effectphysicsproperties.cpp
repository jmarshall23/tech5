
// ========================================================================
// ??0idEffectPhysicsProperties@@QAA@XZ
// EA  : 0x82706A78
// RVA : 0x00706A78
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsproperties.cpp
// ========================================================================

idEffectPhysicsProperties *__fastcall idEffectPhysicsProperties::idEffectPhysicsProperties(
        idEffectPhysicsProperties *this)
{
  this->broadPhase = nullptr;
  this->traceModelIndex = -1;
  this->mass = 1.0;
  return this;
}


// ========================================================================
// ?Setup@idEffectPhysicsProperties@@QAAXPAVidEffectPhysicsBroadPhase@@HM@Z
// EA  : 0x82706A98
// RVA : 0x00706A98
// PDB : w:\tech5\engine\gamelib\effectphysics\effectphysicsproperties.cpp
// ========================================================================

void __fastcall idEffectPhysicsProperties::Setup(
        idEffectPhysicsProperties *this,
        idEffectPhysicsBroadPhase *broadPhase,
        float *traceModelIndex,
        double mass)
{
  idVec3 *p_centerOfMass; // r28
  idMat3 *p_inertiaTensor; // r30
  float *p_mass; // r27
  idMat3 *p_inverseInertiaTensor; // r29
  idVec3 *v10; // r24
  idVec3 *v11; // r23
  double v12; // fp13
  double y; // fp11
  double z; // fp10
  double x; // fp9
  double v16; // fp8
  double v17; // fp7
  double v18; // fp6
  double v19; // fp5
  double v20; // fp4
  double v21; // fp12
  double v22; // fp13
  double v23; // fp11
  int v24; // r9
  float *v25; // r8
  double v26; // fp9
  double v27; // fp13
  double v28; // fp12
  double v29; // fp11
  double v30; // fp12
  int v31; // r10
  double v32; // fp10
  float *v33; // r3
  double v34; // fp6
  double v35; // fp3
  double v36; // fp1
  double v37; // fp8
  double v38; // fp12
  double v39; // fp4
  double v40; // fp9
  double v41; // fp2
  idMat3 v42; // [sp+50h] [-90h] BYREF

  this->linearFriction = 0.60000002;
  this->angularFriction = 0.60000002;
  this->bouncyness = 0.60000002;
  this->clipMask = 1;
  this->contactFriction = 0.5;
  this->linearFrictionWater = 1.0;
  this->angularFrictionWater = 1.0;
  p_centerOfMass = &this->centerOfMass;
  p_inertiaTensor = &this->inertiaTensor;
  this->gravityVector.z = -250.0;
  p_mass = &this->mass;
  this->gravityVector.x = 0.0;
  p_inverseInertiaTensor = &this->inverseInertiaTensor;
  this->gravityVector.y = 0.0;
  this->worldCollisionOnly = false;
  this->crazyBounceChance = 0.0;
  this->simplePointCollision = false;
  this->inverseMass = 1.0;
  this->centerOfMass.x = 0.0;
  this->centerOfMass.z = 0.0;
  this->centerOfMass.y = 0.0;
  this->inertiaTensor.mat[0].x = 1.0;
  v10 = &this->inverseInertiaTensor.mat[2];
  this->inertiaTensor.mat[2].z = 1.0;
  v11 = &this->inverseInertiaTensor.mat[1];
  this->inertiaTensor.mat[1].y = 1.0;
  this->inertiaTensor.mat[1].z = 0.0;
  this->inertiaTensor.mat[0].z = 0.0;
  this->inertiaTensor.mat[0].y = 0.0;
  this->inertiaTensor.mat[2].y = 0.0;
  this->inertiaTensor.mat[2].x = 0.0;
  this->inertiaTensor.mat[1].x = 0.0;
  this->inverseInertiaTensor.mat[2].z = 1.0;
  this->inverseInertiaTensor.mat[1].y = 1.0;
  this->inverseInertiaTensor.mat[0].x = 1.0;
  this->inverseInertiaTensor.mat[1].z = 0.0;
  this->inverseInertiaTensor.mat[0].z = 0.0;
  this->inverseInertiaTensor.mat[0].y = 0.0;
  this->inverseInertiaTensor.mat[2].y = 0.0;
  this->inverseInertiaTensor.mat[2].x = 0.0;
  this->inverseInertiaTensor.mat[1].x = 0.0;
  this->maxLinearVelocity = 5000.0;
  this->stopSpeed = 10.0;
  this->maxAngularVelocity = (float)3.1415927 * (float)4.0;
  this->traceModelIndex = (int)traceModelIndex;
  this->broadPhase = broadPhase;
  idTraceModelCache::GetMassProperties(
    this: broadPhase->traceModelCache,
    (const int)traceModelIndex,
    density: 1.0,
    mass: traceModelIndex,
    centerOfMass: (idVec3 *)&this->mass,
    inertiaTensor: (idMat3 *)&this->centerOfMass);
  if ( this->mass <= 0.0 )
  {
    *p_mass = 1.0;
    p_centerOfMass->z = 0.0;
    p_centerOfMass->y = 0.0;
    p_centerOfMass->x = 0.0;
    p_inertiaTensor->mat[2].z = 1.0;
    p_inertiaTensor->mat[1].y = 1.0;
    p_inertiaTensor->mat[0].x = 1.0;
    p_inertiaTensor->mat[1].z = 0.0;
    p_inertiaTensor->mat[0].z = 0.0;
    p_inertiaTensor->mat[0].y = 0.0;
    p_inertiaTensor->mat[2].y = 0.0;
    p_inertiaTensor->mat[2].x = 0.0;
    p_inertiaTensor->mat[1].x = 0.0;
  }
  v12 = (float)((float)mass / *p_mass);
  y = p_inertiaTensor->mat[0].y;
  z = p_inertiaTensor->mat[0].z;
  x = p_inertiaTensor->mat[1].x;
  v16 = p_inertiaTensor->mat[1].y;
  v17 = p_inertiaTensor->mat[1].z;
  v18 = p_inertiaTensor->mat[2].x;
  v19 = p_inertiaTensor->mat[2].y;
  v20 = p_inertiaTensor->mat[2].z;
  p_inertiaTensor->mat[0].x = p_inertiaTensor->mat[0].x * (float)((float)mass / *p_mass);
  p_inertiaTensor->mat[0].y = (float)y * (float)v12;
  p_inertiaTensor->mat[1].y = (float)v12 * (float)v16;
  p_inertiaTensor->mat[0].z = (float)z * (float)v12;
  p_inertiaTensor->mat[1].x = (float)x * (float)v12;
  p_inertiaTensor->mat[1].z = (float)v17 * (float)v12;
  p_inertiaTensor->mat[2].x = (float)v18 * (float)v12;
  p_inertiaTensor->mat[2].y = (float)v19 * (float)v12;
  p_inertiaTensor->mat[2].z = (float)v20 * (float)v12;
  *p_mass = mass;
  v21 = this->inertiaTensor.mat[1].y;
  v22 = p_inertiaTensor->mat[0].x;
  v23 = this->inertiaTensor.mat[2].z;
  if ( v22 >= v21 )
  {
    v24 = 1;
    if ( v21 < v23 )
      goto LABEL_8;
LABEL_7:
    v24 = 2;
    goto LABEL_8;
  }
  if ( v22 >= v23 )
    goto LABEL_7;
  v24 = 0;
LABEL_8:
  v42.mat[1].z = 0.0;
  v25 = (float *)((char *)this + 16 * v24);
  v42.mat[0].z = 0.0;
  v42.mat[0].y = 0.0;
  v42.mat[2].y = 0.0;
  v42.mat[2].x = 0.0;
  v42.mat[1].x = 0.0;
  v26 = (float)((float)1.0 / v25[19]);
  v27 = (float)((float)((float)1.0 / v25[19]) * (float)v22);
  v28 = (float)((float)((float)1.0 / v25[19]) * (float)v21);
  v42.mat[0].x = v27;
  v42.mat[1].y = v28;
  v29 = (float)((float)v26 * (float)v23);
  v42.mat[2].z = v29;
  if ( v27 > 4.0 || v28 > 4.0 || v29 > 4.0 )
  {
    v30 = (float)(v25[19] * (float)4.0);
    v31 = 16 * ((v24 + 2) % 3);
    v32 = *(float *)((char *)&this->inertiaTensor.mat[0].x + v31);
    *(&v42.mat[0].x + 4 * ((v24 + 1) % 3)) = (float)(v25[19] * (float)4.0)
                                           / *(&this->inertiaTensor.mat[0].x + 4 * ((v24 + 1) % 3));
    *(float *)((char *)&v42.mat[0].x + v31) = (float)v30 / (float)v32;
    idMat3::operator*=(this: p_inertiaTensor, a: &v42);
  }
  this->inverseMass = (float)1.0 / *p_mass;
  v33 = (float *)idMat3::Inverse(this: &v42, result: p_inertiaTensor);
  v34 = (float)(v33[2] * (float)0.16666667);
  v35 = v33[7];
  v36 = v33[6];
  v37 = (float)(v33[3] * (float)0.16666667);
  v38 = v33[5];
  v39 = (float)(v33[1] * (float)0.16666667);
  v40 = v33[4];
  v41 = (float)(v33[8] * (float)0.16666667);
  p_inverseInertiaTensor->mat[0].x = *v33 * (float)0.16666667;
  v11->x = v37;
  p_inverseInertiaTensor->mat[0].y = v39;
  p_inverseInertiaTensor->mat[0].z = v34;
  v11->y = (float)v40 * (float)0.16666667;
  v11->z = (float)v38 * (float)0.16666667;
  v10->x = (float)v36 * (float)0.16666667;
  v10->y = (float)v35 * (float)0.16666667;
  v10->z = v41;
}

