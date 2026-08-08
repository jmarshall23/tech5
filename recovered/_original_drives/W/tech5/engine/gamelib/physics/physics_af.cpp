
// ========================================================================
// ?SetSuspendTime@idPhysics_AF@@QAAXMM@Z
// EA  : 0x8273BB68
// RVA : 0x0073BB68
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetSuspendTime(idPhysics_AF *this, double minTime, double maxTime)
{
  this->minMoveTime = minTime;
  this->maxMoveTime = maxTime;
}


// ========================================================================
// ?SetSuspendTolerance@idPhysics_AF@@QAAXMMM@Z
// EA  : 0x8273BB78
// RVA : 0x0073BB78
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetSuspendTolerance(
        idPhysics_AF *this,
        double noMoveTime,
        double noMoveTranslation,
        double noMoveRotation)
{
  this->noMoveTime = noMoveTime;
  this->noMoveTranslation = noMoveTranslation;
  this->noMoveRotation = noMoveRotation;
}


// ========================================================================
// ?SetTimeScaleRamp@idPhysics_AF@@QAAXMM@Z
// EA  : 0x8273BB88
// RVA : 0x0073BB88
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetTimeScaleRamp(idPhysics_AF *this, double start, double end)
{
  this->timeScaleRampStart = start;
  this->timeScaleRampEnd = end;
}


// ========================================================================
// ?SetJointFrictionDent@idPhysics_AF@@QAAXMMM@Z
// EA  : 0x8273BB98
// RVA : 0x0073BB98
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetJointFrictionDent(idPhysics_AF *this, double dent, double start, double end)
{
  this->jointFrictionDent = dent;
  this->jointFrictionDentStart = start;
  this->jointFrictionDentEnd = end;
}


// ========================================================================
// ?SetContactFrictionDent@idPhysics_AF@@QAAXMMM@Z
// EA  : 0x8273BBA8
// RVA : 0x0073BBA8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetContactFrictionDent(idPhysics_AF *this, double dent, double start, double end)
{
  this->contactFrictionDent = dent;
  this->contactFrictionDentStart = start;
  this->contactFrictionDentEnd = end;
}


// ========================================================================
// ?SetDefaultFriction@idPhysics_AF@@QAAXMMM@Z
// EA  : 0x8273BBB8
// RVA : 0x0073BBB8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetDefaultFriction(idPhysics_AF *this, double linear, double angular, double contact)
{
  if ( linear >= 0.0 && linear <= 1.0 && angular >= 0.0 && angular <= 1.0 && contact >= 0.0 && contact <= 1.0 )
  {
    this->linearFriction = linear;
    this->angularFriction = angular;
    this->contactFriction = contact;
  }
}


// ========================================================================
// ?IsAtRest@idPhysics_AF@@UBA_NXZ
// EA  : 0x8273BC08
// RVA : 0x0073BC08
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

BOOL __fastcall idPhysics_AF::IsAtRest(idPhysics_AF *this)
{
  return this->current.atRest;
}


// ========================================================================
// ?IsPushable@idPhysics_AF@@UBA_NH@Z
// EA  : 0x8273BC10
// RVA : 0x0073BC10
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

BOOL __fastcall idPhysics_AF::IsPushable(idPhysics_AF *this, int sourceContentType)
{
  return !this->noImpact && (this->masterBody == nullptr || this->forcePushable);
}


// ========================================================================
// ?ApplyFriction@idPhysics_AF@@AAAXMM@Z
// EA  : 0x8273BF98
// RVA : 0x0073BF98
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::ApplyFriction(idPhysics_AF *this, double timeStep, double endTimeMSec)
{
  double v4; // fp13
  double v5; // fp12
  double v6; // fp13
  double v7; // fp12
  double v8; // fp31
  int v9; // r29
  int v10; // r30
  int v11; // r29
  int v12; // r30
  int v13; // r29
  int v14; // r30

  if ( af_skipFriction.valueInteger == 0 )
  {
    v4 = (float)((float)0.001 * (float)endTimeMSec);
    if ( this->jointFrictionDentStart >= v4 || this->jointFrictionDentEnd <= v4 )
    {
      this->jointFrictionDentScale = 0.0;
    }
    else if ( (float)(this->jointFrictionDentStart
                    + (float)((float)(this->jointFrictionDentEnd - this->jointFrictionDentStart) * (float)0.5)) <= v4 )
    {
      v5 = (float)((float)(this->jointFrictionDentEnd - this->jointFrictionDentStart) * (float)0.5);
      this->jointFrictionDentScale = (float)((float)((float)((float)((float)0.001 * (float)endTimeMSec)
                                                           - this->jointFrictionDentStart)
                                                   - (float)v5)
                                           * (float)((float)((float)1.0 - this->jointFrictionDent) / (float)v5))
                                   + this->jointFrictionDent;
    }
    else
    {
      this->jointFrictionDentScale = -(float)((float)((float)((float)1.0 - this->jointFrictionDent)
                                                    * (float)((float)((float)((float)0.001 * (float)endTimeMSec)
                                                                    - this->jointFrictionDentStart)
                                                            / (float)((float)(this->jointFrictionDentEnd
                                                                            - this->jointFrictionDentStart)
                                                                    * (float)0.5)))
                                            - (float)1.0);
    }
    v6 = (float)(0.001 * (float)endTimeMSec);
    if ( this->contactFrictionDentStart >= v6 || this->contactFrictionDentEnd <= v6 )
    {
      this->contactFrictionDentScale = 0.0;
    }
    else if ( (float)(this->contactFrictionDentStart
                    + (float)((float)(this->contactFrictionDentEnd - this->contactFrictionDentStart) * (float)0.5)) <= v6 )
    {
      v7 = (float)((float)(this->contactFrictionDentEnd - this->contactFrictionDentStart) * (float)0.5);
      this->contactFrictionDentScale = (float)((float)((float)((float)(0.001 * (float)endTimeMSec)
                                                             - this->contactFrictionDentStart)
                                                     - (float)v7)
                                             * (float)((float)((float)1.0 - this->contactFrictionDent) / (float)v7))
                                     + this->contactFrictionDent;
    }
    else
    {
      this->contactFrictionDentScale = -(float)((float)((float)((float)1.0 - this->contactFrictionDent)
                                                      * (float)((float)((float)(0.001 * (float)endTimeMSec)
                                                                      - this->contactFrictionDentStart)
                                                              / (float)((float)(this->contactFrictionDentEnd
                                                                              - this->contactFrictionDentStart)
                                                                      * (float)0.5)))
                                              - (float)1.0);
    }
    v8 = (float)((float)1.0 / (float)timeStep);
    v9 = 0;
    if ( this->primaryConstraints.num > 0 )
    {
      v10 = 0;
      do
      {
        this->primaryConstraints.list[v10]->ApplyFriction(this: this->primaryConstraints.list[v10], a2: v8);
        ++v9;
        ++v10;
      }
      while ( v9 < this->primaryConstraints.num );
    }
    v11 = 0;
    if ( this->auxiliaryConstraints.num > 0 )
    {
      v12 = 0;
      do
      {
        this->auxiliaryConstraints.list[v12]->ApplyFriction(this: this->auxiliaryConstraints.list[v12], a2: v8);
        ++v11;
        ++v12;
      }
      while ( v11 < this->auxiliaryConstraints.num );
    }
    v13 = 0;
    if ( this->frameConstraints.num > 0 )
    {
      v14 = 0;
      do
      {
        this->frameConstraints.list[v14]->ApplyFriction(this: this->frameConstraints.list[v14], a2: v8);
        ++v13;
        ++v14;
      }
      while ( v13 < this->frameConstraints.num );
    }
  }
}


// ========================================================================
// ?PrimaryFactor@idPhysics_AF@@AAAXXZ
// EA  : 0x8273C1A0
// RVA : 0x0073C1A0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::PrimaryFactor(idPhysics_AF *this)
{
  int v2; // r30
  int v3; // r31

  v2 = 0;
  if ( this->trees.num > 0 )
  {
    v3 = 0;
    do
    {
      idAFTree::Factor(this: this->trees.list[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->trees.num );
  }
}


// ========================================================================
// ?PrimaryForces@idPhysics_AF@@AAAXM@Z
// EA  : 0x8273C1F0
// RVA : 0x0073C1F0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::PrimaryForces(idPhysics_AF *this, double timeStep)
{
  int v4; // r30
  int v5; // r31

  v4 = 0;
  if ( this->trees.num > 0 )
  {
    v5 = 0;
    do
    {
      idAFTree::CalculateForces(this: this->trees.list[v5], timeStep);
      ++v4;
      ++v5;
    }
    while ( v4 < this->trees.num );
  }
}


// ========================================================================
// ?MultiplyJauxMK@@YAXPIAMHPIBM1PIBH@Z
// EA  : 0x8273C250
// RVA : 0x0073C250
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall MultiplyJauxMK(float *row, int rowLength, const float *jaux, const float *response, const int *index)
{
  const int *v7; // r11
  unsigned int v13; // ctr
  unsigned int v19; // r11
  const int *v20; // r11
  int v21; // ctr

  _R9 = 16;
  __asm { lvx128    v63, r0, r5 }
  __asm { lvx128    v62, r5, r9 }
  if ( rowLength - 3 > 0 )
  {
    v7 = index - 1;
    _R28 = 32;
    _R29 = 48;
    _R30 = 64;
    _R31 = 80;
    _R5 = 96;
    v13 = ((unsigned int)(rowLength - 4) >> 2) + 1;
    _R8 = 112;
    do
    {
      __asm { lvx128    v61, r6, r9 }
      __asm
      {
        lvx128    v60, r0, r6
        vmsum4fp128 v59, v93, v62
        vmsum4fp128 v58, v92, v63
      }
      _R10 = 4 * v7[1];
      __asm
      {
        vaddfp128 v57, v90, v59
        stvewx128 v57, r3, r10
      }
      __asm { lvx128    v56, r6, r28 }
      _R10 = 4 * v7[2];
      __asm
      {
        lvx128    v55, r6, r29
        vmsum4fp128 v54, v87, v62
        vmsum4fp128 v53, v88, v63
        vaddfp128 v52, v85, v54
        stvewx128 v52, r3, r10
      }
      __asm { lvx128    v51, r6, r30 }
      _R10 = 4 * v7[3];
      __asm
      {
        lvx128    v50, r6, r31
        vmsum4fp128 v49, v82, v62
        vmsum4fp128 v48, v83, v63
        vaddfp128 v47, v80, v49
        stvewx128 v47, r3, r10
      }
      v7 += 4;
      __asm { lvx128    v46, r6, r8 }
      _R10 = 4 * *v7;
      __asm
      {
        lvx128    v45, r6, r5
        vmsum4fp128 v44, v77, v63
        vmsum4fp128 v43, v78, v62
      }
      response += 32;
      __asm
      {
        vaddfp128 v42, v76, v43
        stvewx128 v42, r3, r10
      }
      --v13;
    }
    while ( v13 != 0 );
  }
  v19 = rowLength & 0xFFFFFFFC;
  if ( (int)(rowLength & 0xFFFFFFFC) < rowLength )
  {
    v21 = rowLength - v19;
    v20 = &index[v19 - 1];
    do
    {
      __asm { lvx128    v41, r6, r9 }
      ++v20;
      __asm
      {
        lvx128    v40, r0, r6
        vmsum4fp128 v39, v73, v62
        vmsum4fp128 v38, v72, v63
      }
      _R10 = 4 * *v20;
      response += 8;
      __asm
      {
        vaddfp128 v37, v70, v39
        stvewx128 v37, r3, r10
      }
      --v21;
    }
    while ( v21 != 0 );
  }
}


// ========================================================================
// ?MultiplyAddJauxMK@@YAXPIAMHPIBM1PIBH@Z
// EA  : 0x8273C370
// RVA : 0x0073C370
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall MultiplyAddJauxMK(
        float *row,
        int rowLength,
        const float *jaux,
        const float *response,
        const int *index)
{
  const int *v7; // r11
  unsigned int v13; // ctr
  unsigned int v19; // r11
  const int *v21; // r11
  int v22; // ctr

  _R28 = 16;
  __asm { lvx128    v63, r0, r5 }
  __asm { lvx128    v62, r5, r28 }
  if ( rowLength - 3 > 0 )
  {
    v7 = index - 4;
    _R29 = 32;
    _R30 = 48;
    _R31 = 64;
    _R5 = 80;
    _R8 = 96;
    v13 = ((unsigned int)(rowLength - 4) >> 2) + 1;
    _R9 = 112;
    do
    {
      __asm { lvx128    v61, r0, r6 }
      __asm
      {
        lvx128    v60, r6, r28
        vmsum4fp128 v59, v93, v63
        vmsum4fp128 v58, v92, v62
      }
      _R27 = v7[6];
      _R26 = v7[7];
      _R25 = 4 * v7[5];
      v7 += 4;
      _R27 *= 4;
      _R26 *= 4;
      _R10 = 4 * *v7;
      __asm
      {
        lvlx128   v57, r25, r3
        lvlx128   v56, r27, r3
        lvlx128   v55, r26, r3
        vspltw128 v54, v57, 0
        lvlx128   v53, r10, r3
        vspltw128 v52, v56, 0
        vspltw128 v51, v55, 0
        vspltw128 v50, v53, 0
        vaddfp128 v49, v91, v58
        vaddfp128 v48, v81, v50
        stvewx128 v48, r3, r10
        lvx128    v46, r6, r30
        lvx128    v47, r6, r29
        vmsum4fp128 v44, v79, v63
        vmsum4fp128 v45, v78, v62
        vaddfp128 v43, v76, v45
        vaddfp128 v42, v75, v54
        stvewx128 v42, r3, r25
        lvx128    v40, r6, r5
        lvx128    v41, r6, r31
        vmsum4fp128 v38, v73, v63
        vmsum4fp128 v39, v72, v62
        vaddfp128 v37, v70, v39
        vaddfp128 v36, v69, v52
        stvewx128 v36, r3, r27
        lvx128    v34, r6, r9
        lvx128    v35, r6, r8
        vmsum4fp128 v32, v67, v63
        vmsum4fp128 v33, v66, v62
      }
      response += 32;
      __asm
      {
        vaddfp128 v61, v64, v33
        vaddfp128 v60, v93, v51
        stvewx128 v60, r3, r26
      }
      --v13;
    }
    while ( v13 != 0 );
  }
  v19 = rowLength & 0xFFFFFFFC;
  if ( (int)(rowLength & 0xFFFFFFFC) < rowLength )
  {
    _R9 = 16;
    v22 = rowLength - v19;
    v21 = &index[v19 - 1];
    do
    {
      __asm { lvx128    v59, r6, r9 }
      ++v21;
      __asm
      {
        lvx128    v58, r0, r6
        vmsum4fp128 v57, v91, v62
        vmsum4fp128 v56, v90, v63
      }
      _R10 = 4 * *v21;
      response += 8;
      __asm
      {
        lvlx128   v55, r10, r3
        vspltw128 v54, v55, 0
        vaddfp128 v53, v88, v57
        vaddfp128 v52, v85, v54
        stvewx128 v52, r3, r10
      }
      --v22;
    }
    while ( v22 != 0 );
  }
}


// ========================================================================
// ?AddGravity@idPhysics_AF@@AAAXXZ
// EA  : 0x8273C4D0
// RVA : 0x0073C4D0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::AddGravity(idPhysics_AF *this)
{
  int v1; // r8
  int v2; // r10
  idAFBody *v3; // r11
  double v4; // fp8
  double v5; // fp7
  double v6; // fp6
  double v7; // fp5

  if ( this->addGravity )
  {
    v1 = 0;
    if ( this->bodies.num > 0 )
    {
      v2 = 0;
      do
      {
        ++v1;
        v3 = this->bodies.list[v2++];
        v4 = (float)(this->gravityVector.y * v3->mass);
        v5 = v3->current.externalForce.p[1];
        v6 = (float)(this->gravityVector.z * v3->mass);
        v7 = v3->current.externalForce.p[2];
        v3->current.externalForce.p[0] = v3->current.externalForce.p[0] + (float)(this->gravityVector.x * v3->mass);
        v3->current.externalForce.p[1] = (float)v5 + (float)v4;
        v3->current.externalForce.p[2] = (float)v7 + (float)v6;
      }
      while ( v1 < this->bodies.num );
    }
  }
}


// ========================================================================
// ?UpdateClipModels@idPhysics_AF@@QAAXXZ
// EA  : 0x8273C558
// RVA : 0x0073C558
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::UpdateClipModels(idPhysics_AF *this)
{
  int v2; // r29
  int v3; // r30
  idClipModel *clipModel; // r3

  v2 = 0;
  if ( this->bodies.num > 0 )
  {
    v3 = 0;
    do
    {
      clipModel = this->bodies.list[v3]->clipModel;
      idClipModel::Link(
        this: clipModel,
        newEntityNumber: this->entityNumber,
        newPhysicsId: this->physicsId,
        newBodyId: clipModel->bodyId,
        newOrigin: &clipModel->origin,
        newAxis: &clipModel->axis);
      ++v2;
      ++v3;
    }
    while ( v2 < this->bodies.num );
  }
}


// ========================================================================
// ?SetSuspendSpeed@idPhysics_AF@@QAAXABVidVec2@@0@Z
// EA  : 0x8273C5C0
// RVA : 0x0073C5C0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetSuspendSpeed(idPhysics_AF *this, const idVec2 *velocity, const idVec2 *acceleration)
{
  this->suspendVelocity = *velocity;
  this->suspendAcceleration = *acceleration;
}


// ========================================================================
// ?GetJointFrictionScale@idPhysics_AF@@QBAMXZ
// EA  : 0x8273C5E8
// RVA : 0x0073C5E8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

float __fastcall idPhysics_AF::GetJointFrictionScale(idPhysics_AF *this)
{
  double jointFrictionDentScale; // fp1

  jointFrictionDentScale = this->jointFrictionDentScale;
  if ( jointFrictionDentScale <= 0.0 )
  {
    jointFrictionDentScale = this->jointFrictionScale;
    if ( jointFrictionDentScale <= 0.0 )
    {
      jointFrictionDentScale = af_jointFrictionScale.valueFloat;
      if ( af_jointFrictionScale.valueFloat <= 0.0 )
        jointFrictionDentScale = 1.0;
    }
  }
  return *((float *)&jointFrictionDentScale + 1);
}


// ========================================================================
// ?GetContactFrictionScale@idPhysics_AF@@QBAMXZ
// EA  : 0x8273C628
// RVA : 0x0073C628
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

float __fastcall idPhysics_AF::GetContactFrictionScale(idPhysics_AF *this)
{
  double contactFrictionDentScale; // fp1

  contactFrictionDentScale = this->contactFrictionDentScale;
  if ( contactFrictionDentScale <= 0.0 )
  {
    contactFrictionDentScale = this->contactFrictionScale;
    if ( contactFrictionDentScale <= 0.0 )
    {
      contactFrictionDentScale = af_contactFrictionScale.valueFloat;
      if ( af_contactFrictionScale.valueFloat <= 0.0 )
        contactFrictionDentScale = 1.0;
    }
  }
  return *((float *)&contactFrictionDentScale + 1);
}


// ========================================================================
// ?TestIfAtRest@idPhysics_AF@@AAA_NM@Z
// EA  : 0x8273C668
// RVA : 0x0073C668
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

int __fastcall idPhysics_AF::TestIfAtRest(idPhysics_AF *this, double timeStep)
{
  double v4; // fp12
  double minMoveTime; // fp13
  double maxMoveTime; // fp13
  double noMoveTime; // fp13
  int v9; // r7
  int v10; // r8
  idAFBody *v11; // r9
  float *clipModel; // r11
  int num; // r11
  double v14; // fp31
  int v15; // r29
  double angle; // fp30
  int v17; // r30
  idAFBody *v18; // r11
  idClipModel *v19; // r10
  double v20; // fp10
  double v21; // fp8
  double v22; // fp6
  double z; // fp13
  double v24; // fp12
  double y; // fp11
  double v26; // fp10
  double v27; // fp9
  double x; // fp8
  double v29; // fp7
  double v30; // fp6
  idRotation *v31; // r3
  idRotation *v32; // r3
  int v33; // r9
  int i; // r10
  idAFBody *v35; // r11
  float *p; // r11
  idMat3 v37; // [sp+50h] [-E0h] BYREF
  idMat3 v38; // [sp+80h] [-B0h] BYREF
  idMat3 v39[2]; // [sp+B0h] [-80h] BYREF

  if ( !this->IsAtRest(this) )
  {
    v4 = (float)(this->current.activateTime + (float)timeStep);
    minMoveTime = this->minMoveTime;
    this->current.activateTime = this->current.activateTime + (float)timeStep;
    if ( minMoveTime > 0.0 && v4 < minMoveTime )
      return 0;
    maxMoveTime = this->maxMoveTime;
    if ( maxMoveTime <= 0.0 || this->current.activateTime <= maxMoveTime )
    {
      noMoveTime = this->current.noMoveTime;
      if ( noMoveTime == 0.0 )
      {
        v9 = 0;
        if ( this->bodies.num > 0 )
        {
          v10 = 0;
          do
          {
            ++v9;
            v11 = this->bodies.list[v10++];
            clipModel = (float *)v11->clipModel;
            v11->current.atRestOrigin.x = clipModel[8];
            v11->current.atRestOrigin.y = clipModel[9];
            v11->current.atRestOrigin.z = clipModel[10];
            v11->current.atRestAxis.mat[0].x = clipModel[11];
            v11->current.atRestAxis.mat[0].y = clipModel[12];
            v11->current.atRestAxis.mat[0].z = clipModel[13];
            v11->current.atRestAxis.mat[1].x = clipModel[14];
            v11->current.atRestAxis.mat[1].y = clipModel[15];
            v11->current.atRestAxis.mat[1].z = clipModel[16];
            v11->current.atRestAxis.mat[2].x = clipModel[17];
            v11->current.atRestAxis.mat[2].y = clipModel[18];
            v11->current.atRestAxis.mat[2].z = clipModel[19];
          }
          while ( v9 < this->bodies.num );
        }
        this->current.noMoveTime = this->current.noMoveTime + (float)timeStep;
      }
      else if ( noMoveTime <= this->noMoveTime )
      {
        this->current.noMoveTime = this->current.noMoveTime + (float)timeStep;
      }
      else
      {
        num = this->bodies.num;
        this->current.noMoveTime = 0.0;
        v14 = 0.0;
        v15 = 0;
        angle = 0.0;
        if ( num > 0 )
        {
          v17 = 0;
          do
          {
            v18 = this->bodies.list[v17];
            v19 = v18->clipModel;
            v20 = (float)(v19->origin.y - v18->current.atRestOrigin.y);
            v21 = (float)(v19->origin.z - v18->current.atRestOrigin.z);
            v22 = (float)(v19->origin.x - v18->current.atRestOrigin.x);
            if ( (float)((float)((float)v22 * (float)v22)
                       + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))) > v14 )
              v14 = (float)((float)((float)v22 * (float)v22)
                          + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)));
            z = v18->current.atRestAxis.mat[1].z;
            v24 = v18->current.atRestAxis.mat[0].z;
            y = v18->current.atRestAxis.mat[2].y;
            v26 = v18->current.atRestAxis.mat[1].y;
            v27 = v18->current.atRestAxis.mat[0].y;
            x = v18->current.atRestAxis.mat[2].x;
            v29 = v18->current.atRestAxis.mat[1].x;
            v30 = v18->current.atRestAxis.mat[0].x;
            v37.mat[2].z = v18->current.atRestAxis.mat[2].z;
            v37.mat[2].y = z;
            v37.mat[2].x = v24;
            v37.mat[1].z = y;
            v37.mat[1].y = v26;
            v37.mat[1].x = v27;
            v37.mat[0].z = x;
            v37.mat[0].x = v30;
            v37.mat[0].y = v29;
            v31 = (idRotation *)idMat3::operator*(this: &v38, result: &v37, a: &v19->axis);
            v32 = idMat3::ToRotation(this: v39, result: v31);
            if ( v32->angle > angle )
              angle = v32->angle;
            ++v15;
            ++v17;
          }
          while ( v15 < this->bodies.num );
        }
        if ( v14 < (float)(this->noMoveTranslation * this->noMoveTranslation) && angle < this->noMoveRotation )
          return 1;
      }
      v33 = 0;
      if ( this->bodies.num > 0 )
      {
        for ( i = 0; ; ++i )
        {
          v35 = this->bodies.list[i];
          if ( (float)((float)(v35->current.spatialVelocity.p[2] * v35->current.spatialVelocity.p[2])
                     + (float)((float)(v35->current.spatialVelocity.p[0] * v35->current.spatialVelocity.p[0])
                             + (float)(v35->current.spatialVelocity.p[1] * v35->current.spatialVelocity.p[1]))) > (double)(float)(this->suspendVelocity.x * this->suspendVelocity.x) )
            break;
          if ( (float)((float)(v35->current.spatialVelocity.p[5] * v35->current.spatialVelocity.p[5])
                     + (float)((float)(v35->current.spatialVelocity.p[3] * v35->current.spatialVelocity.p[3])
                             + (float)(v35->current.spatialVelocity.p[4] * v35->current.spatialVelocity.p[4]))) > (double)(float)(this->suspendVelocity.y * this->suspendVelocity.y) )
            break;
          p = v35->acceleration.p;
          if ( (float)((float)(p[2] * p[2]) + (float)((float)(*p * *p) + (float)(p[1] * p[1]))) > (double)(float)(this->suspendAcceleration.x * this->suspendAcceleration.x)
            || (float)((float)(p[5] * p[5]) + (float)((float)(p[3] * p[3]) + (float)(p[4] * p[4]))) > (double)(float)(this->suspendAcceleration.y * this->suspendAcceleration.y) )
          {
            break;
          }
          if ( ++v33 >= this->bodies.num )
            return 1;
        }
        return 0;
      }
    }
  }
  return 1;
}


// ========================================================================
// ?GetClipModel@idPhysics_AF@@UBAPAVidClipModel@@H@Z
// EA  : 0x8273C9C8
// RVA : 0x0073C9C8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

idClipModel *__fastcall idPhysics_AF::GetClipModel(idPhysics_AF *this, int id)
{
  if ( id < 0 || id >= this->bodies.num )
    return nullptr;
  else
    return this->bodies.list[id]->clipModel;
}


// ========================================================================
// ?SetMass@idPhysics_AF@@UAAXMH@Z
// EA  : 0x8273C9F8
// RVA : 0x0073C9F8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetMass(idPhysics_AF *this, double mass, int id)
{
  this->changedAF = true;
}


// ========================================================================
// ?GetMass@idPhysics_AF@@UBAMH@Z
// EA  : 0x8273CA08
// RVA : 0x0073CA08
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

float __fastcall idPhysics_AF::GetMass(idPhysics_AF *this, int id)
{
  double totalMass; // fp1
  int num; // r11
  int v4; // r10
  idAFBody **list; // r9
  int v6; // r11
  idAFBody *v7; // r8

  if ( id < 0 || id >= this->bodies.num )
  {
    if ( this->totalMass < 0.0 )
    {
      num = this->bodies.num;
      this->totalMass = 0.0;
      v4 = 0;
      if ( num > 0 )
      {
        list = this->bodies.list;
        v6 = 0;
        do
        {
          v7 = list[v6];
          ++v4;
          ++v6;
          this->totalMass = v7->mass + this->totalMass;
        }
        while ( v4 < this->bodies.num );
      }
    }
    totalMass = this->totalMass;
  }
  else
  {
    totalMass = this->bodies.list[id]->mass;
  }
  return *((float *)&totalMass + 1);
}


// ========================================================================
// ?SetContents@idPhysics_AF@@UAAXHH@Z
// EA  : 0x8273CA90
// RVA : 0x0073CA90
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetContents(idPhysics_AF *this, int contents, int id)
{
  int v5; // r30
  int v6; // r31

  if ( id < 0 || id >= this->bodies.num )
  {
    v5 = 0;
    if ( this->bodies.num > 0 )
    {
      v6 = 0;
      do
      {
        idClipModel::SetContents(this: this->bodies.list[v6]->clipModel, newContents: contents);
        ++v5;
        ++v6;
      }
      while ( v5 < this->bodies.num );
    }
  }
  else
  {
    idClipModel::SetContents(this: this->bodies.list[id]->clipModel, newContents: contents);
  }
}


// ========================================================================
// ?GetContents@idPhysics_AF@@UBAHH@Z
// EA  : 0x8273CB18
// RVA : 0x0073CB18
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

int __fastcall idPhysics_AF::GetContents(idPhysics_AF *this, int id)
{
  int result; // r3
  int num; // r10
  idAFBody **list; // r9
  int v6; // r11
  int i; // ctr
  idAFBody *v8; // r10

  if ( id >= 0 && id < this->bodies.num )
    return this->bodies.list[id]->clipModel->contents;
  num = this->bodies.num;
  result = 0;
  if ( num > 0 )
  {
    list = this->bodies.list;
    v6 = 0;
    for ( i = num; i != 0; --i )
    {
      v8 = list[v6++];
      result |= v8->clipModel->contents;
    }
  }
  return result;
}


// ========================================================================
// ?SetClipMask@idPhysics_AF@@UAAXHH@Z
// EA  : 0x8273CB80
// RVA : 0x0073CB80
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetClipMask(idPhysics_AF *this, int mask, int id)
{
  idAFBody *v3; // r9
  idAFBody::afBodyFlags_t v4; // r8
  int v5; // r10
  int v6; // r11
  idAFBody *v7; // r8
  idAFBody::afBodyFlags_t fl; // r7

  this->clipMask = mask;
  if ( id < 0 || id >= this->bodies.num )
  {
    v5 = 0;
    if ( this->bodies.num > 0 )
    {
      v6 = 0;
      do
      {
        ++v5;
        v7 = this->bodies.list[v6++];
        fl = v7->fl;
        v7->clipMask = mask;
        v7->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&fl | 0x80);
      }
      while ( v5 < this->bodies.num );
    }
  }
  else
  {
    v3 = this->bodies.list[id];
    v4 = v3->fl;
    v3->clipMask = mask;
    v3->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&v4 | 0x80);
  }
}


// ========================================================================
// ?GetClipMask@idPhysics_AF@@UBAHH@Z
// EA  : 0x8273CC00
// RVA : 0x0073CC00
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

int __fastcall idPhysics_AF::GetClipMask(idPhysics_AF *this, int id)
{
  int result; // r3
  int num; // r10
  idAFBody **list; // r9
  int v6; // r11
  int i; // ctr
  idAFBody *v8; // r10

  if ( id >= 0 && id < this->bodies.num )
    return this->bodies.list[id]->clipMask;
  num = this->bodies.num;
  result = 0;
  if ( num > 0 )
  {
    list = this->bodies.list;
    v6 = 0;
    for ( i = num; i != 0; --i )
    {
      v8 = list[v6++];
      result |= v8->clipMask;
    }
  }
  return result;
}


// ========================================================================
// ?ForceBodyId@idPhysics_AF@@QAAXPAVidAFBody@@H@Z
// EA  : 0x8273CC60
// RVA : 0x0073CC60
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::ForceBodyId(idPhysics_AF *this, idAFBody *body, int newId)
{
  int num; // r9
  int v4; // r11
  int v5; // r10
  idAFBody **list; // r10
  int v7; // r11
  idAFBody *v8; // r6

  num = this->bodies.num;
  v4 = 0;
  if ( num <= 0 )
    goto LABEL_7;
  v5 = 0;
  while ( this->bodies.list[v5] != body )
  {
    ++v4;
    ++v5;
    if ( v4 >= num )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    idLib::Error(fmt: "ForceBodyId: body '%s' is not part of the articulated figure.\n", body->name.str);
  }
  else if ( v4 != newId )
  {
    list = this->bodies.list;
    v7 = v4;
    v8 = list[newId];
    list[newId] = list[v7];
    this->bodies.list[v7] = v8;
    this->changedAF = true;
  }
}


// ========================================================================
// ?GetBodyId@idPhysics_AF@@QBAHPAVidAFBody@@@Z
// EA  : 0x8273CCE8
// RVA : 0x0073CCE8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::GetBodyId(idPhysics_AF *this, idAFBody *body)
{
  int num; // r9
  int v3; // r10
  int v4; // r11

  num = this->bodies.num;
  v3 = 0;
  if ( num <= 0 )
    goto LABEL_7;
  v4 = 0;
  while ( this->bodies.list[v4] != body )
  {
    ++v3;
    ++v4;
    if ( v3 >= num )
      goto LABEL_7;
  }
  if ( v3 == -1 )
  {
LABEL_7:
    if ( body != nullptr )
      idLib::Error(fmt: "GetBodyId: body '%s' is not part of the articulated figure.\n", body->name.str);
  }
}


// ========================================================================
// ?GetBody@idPhysics_AF@@QBAPAVidAFBody@@PBD@Z
// EA  : 0x8273CD50
// RVA : 0x0073CD50
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

idAFBody *__fastcall idPhysics_AF::GetBody(idPhysics_AF *this, const char *bodyName)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->bodies.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: this->bodies.list[i]->name.str, s2: bodyName) != 0; ++i )
  {
    if ( ++v4 >= this->bodies.num )
      return nullptr;
  }
  return this->bodies.list[v4];
}


// ========================================================================
// ?GetBody@idPhysics_AF@@QBAPAVidAFBody@@H@Z
// EA  : 0x8273CDC8
// RVA : 0x0073CDC8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

idAFBody *__fastcall idPhysics_AF::GetBody(idPhysics_AF *this, int id)
{
  if ( id >= 0 && id < this->bodies.num )
    return this->bodies.list[id];
  idLib::Warning(fmt: "GetBody: no body with id %d exists", id);
  return nullptr;
}


// ========================================================================
// ?GetConstraint@idPhysics_AF@@QBAPAVidAFConstraint@@PBD@Z
// EA  : 0x8273CE28
// RVA : 0x0073CE28
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

idAFConstraint *__fastcall idPhysics_AF::GetConstraint(idPhysics_AF *this, const char *constraintName)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->constraints.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: this->constraints.list[i]->name.str, s2: constraintName) != 0; ++i )
  {
    if ( ++v4 >= this->constraints.num )
      return nullptr;
  }
  return this->constraints.list[v4];
}


// ========================================================================
// ?GetConstraint@idPhysics_AF@@QBAPAVidAFConstraint@@H@Z
// EA  : 0x8273CEA0
// RVA : 0x0073CEA0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::GetConstraint(idPhysics_AF *this, int id)
{
  if ( id < 0 || id >= this->constraints.num )
    idLib::Error(fmt: "GetConstraint: no constraint with id %d exists\n", id);
}


// ========================================================================
// ?DeleteBody@idPhysics_AF@@QAAXH@Z
// EA  : 0x8273CED0
// RVA : 0x0073CED0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::DeleteBody(idPhysics_AF *this, int id)
{
  int v4; // r29
  int v5; // r27
  idList<idEntityPtr<idEntity>,58> *p_constraints; // r28
  int v7; // r31
  int value; // r3
  idAFBody *v9; // r11
  idAFBody *v10; // r3
  int v11; // r11
  int v12; // r10
  idAFBody *v13; // r8
  int v14; // r4
  idPhysics_AF *v15; // r3

  if ( id < 0 || id > this->bodies.num )
  {
    idLib::Error(fmt: "DeleteBody: no body with id %d.", id);
    idPhysics_AF::DeleteConstraint(this: v15, id: v14);
  }
  else
  {
    v4 = 0;
    if ( this->constraints.num > 0 )
    {
      v5 = id;
      p_constraints = (idList<idEntityPtr<idEntity>,58> *)&this->constraints;
      v7 = 0;
      do
      {
        value = p_constraints->list[v7].spawnId.value;
        v9 = this->bodies.list[v5];
        if ( *(idAFBody **)(value + 24) == v9 || *(idAFBody **)(value + 28) == v9 )
        {
          if ( value != 0 )
            (**(void (__fastcall ***)(int, int))value)(a1: value, a2: 1);
          idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_constraints, index: v4--);
          --v7;
        }
        ++v4;
        ++v7;
      }
      while ( v4 < this->constraints.num );
    }
    v10 = this->bodies.list[id];
    if ( v10 != nullptr )
      ((void (__fastcall *)(idAFBody *, int))v10->dtr_idAFBody)(a1: v10, a2: 1);
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
      this: (idList<idEntityPtr<idEntity>,58> *)&this->bodies,
      index: id);
    v11 = 0;
    if ( this->bodies.num > 0 )
    {
      v12 = 0;
      do
      {
        v13 = this->bodies.list[v12++];
        v13->clipModel->bodyId = v11++;
      }
      while ( v11 < this->bodies.num );
    }
    this->changedAF = true;
  }
}


// ========================================================================
// ?DeleteConstraint@idPhysics_AF@@QAAXH@Z
// EA  : 0x8273D010
// RVA : 0x0073D010
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::DeleteConstraint(idPhysics_AF *this, int id)
{
  idList<idEntityPtr<idEntity>,58> *p_constraints; // r30
  idAFConstraint *v5; // r3
  impactInfo_t *v6; // r6
  const idVec3 *v7; // r5
  int v8; // r4
  idPhysics_AF *v9; // r3

  if ( id < 0 || id >= this->constraints.num )
  {
    idLib::Error(fmt: "DeleteConstraint: no constraint with id %d.", id);
    idPhysics_AF::GetImpactInfo(this: v9, id: v8, point: v7, info: v6);
  }
  else
  {
    p_constraints = (idList<idEntityPtr<idEntity>,58> *)&this->constraints;
    v5 = this->constraints.list[id];
    if ( v5 != nullptr )
      ((void (__fastcall *)(idAFConstraint *, int))v5->dtr_idAFConstraint)(a1: v5, a2: 1);
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_constraints, index: id);
    this->changedAF = true;
  }
}


// ========================================================================
// ?GetImpactInfo@idPhysics_AF@@UBAXHABVidVec3@@AAUimpactInfo_t@@@Z
// EA  : 0x8273D090
// RVA : 0x0073D090
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::GetImpactInfo(idPhysics_AF *this, int id, const idVec3 *point, impactInfo_t *info)
{
  int v7; // r29
  idAFBody *v8; // r8
  float *clipModel; // r11
  double v10; // fp10
  double v11; // fp9
  double v12; // fp8
  const idMat3 *v13; // r30
  double v14; // fp7
  double v15; // fp6
  double v16; // fp5
  double v17; // fp4
  double v18; // fp3
  idMat3 *v19; // r3
  double y; // fp6
  idClipModel *v21; // r11
  double v22; // fp3
  double v23; // fp13
  double v24; // fp1
  idAFBody *v25; // r4
  double v26; // fp3
  double v27; // fp2
  double v28; // fp0
  double v29; // fp12
  double v30; // fp10
  idMat3 v31; // [sp+50h] [-C0h] BYREF
  idMat3 v32; // [sp+80h] [-90h] BYREF
  idMat3 v33[2]; // [sp+B0h] [-60h] BYREF

  if ( id < 0 || id >= this->bodies.num )
  {
    memset(Dst: info, Val: 0, Size: sizeof(impactInfo_t));
  }
  else
  {
    v7 = id;
    info->invMass = (float)1.0 / this->bodies.list[id]->mass;
    v8 = this->bodies.list[id];
    clipModel = (float *)v8->clipModel;
    v10 = clipModel[18];
    v11 = clipModel[15];
    v12 = clipModel[12];
    v13 = (const idMat3 *)(clipModel + 11);
    v14 = clipModel[17];
    v15 = clipModel[14];
    v16 = clipModel[11];
    v17 = clipModel[19];
    v18 = clipModel[16];
    v31.mat[2].x = clipModel[13];
    v31.mat[2].y = v18;
    v31.mat[2].z = v17;
    v31.mat[1].z = v10;
    v31.mat[1].y = v11;
    v31.mat[1].x = v12;
    v31.mat[0].z = v14;
    v31.mat[0].y = v15;
    v31.mat[0].x = v16;
    v19 = idMat3::operator*(this: &v32, result: &v31, a: &v8->inverseInertiaTensor);
    info->invInertiaTensor = *idMat3::operator*(this: v33, result: v19, a: v13);
    y = point->y;
    v21 = this->bodies.list[v7]->clipModel;
    v22 = v21->origin.y;
    v23 = (float)(point->x - v21->origin.x);
    v24 = (float)(point->z - v21->origin.z);
    info->position.x = point->x - v21->origin.x;
    info->position.y = (float)y - (float)v22;
    info->position.z = v24;
    v25 = this->bodies.list[v7];
    v27 = v25->current.spatialVelocity.p[2];
    v28 = (float)((float)((float)((float)y - (float)v22) * v25->current.spatialVelocity.p[3])
                - (float)((float)v23 * v25->current.spatialVelocity.p[4]));
    v29 = (float)((float)((float)v23 * v25->current.spatialVelocity.p[5])
                - (float)((float)v24 * v25->current.spatialVelocity.p[3]));
    v30 = (float)(v25->current.spatialVelocity.p[0]
                + (float)((float)((float)v24 * v25->current.spatialVelocity.p[4])
                        - (float)((float)((float)y - (float)v22) * v25->current.spatialVelocity.p[5])));
    v26 = v25->current.spatialVelocity.p[1];
    info->velocity.x = v30;
    info->velocity.z = (float)v27 + (float)v28;
    info->velocity.y = (float)v26 + (float)v29;
  }
}


// ========================================================================
// ?ApplyImpulse@idPhysics_AF@@UAAXHABVidVec3@@0@Z
// EA  : 0x8273D260
// RVA : 0x0073D260
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::ApplyImpulse(idPhysics_AF *this, int bodyId, const idVec3 *point, const idVec3 *impulse)
{
  idAFBody *v7; // r31
  float *clipModel; // r11
  const idMat3 *v9; // r30
  double v10; // fp13
  double v11; // fp12
  double v12; // fp11
  double v13; // fp10
  double v14; // fp9
  double v15; // fp8
  double v16; // fp7
  double v17; // fp6
  idMat3 *v18; // r3
  double v19; // fp0
  double v20; // fp13
  double v21; // fp11
  double v22; // fp10
  double x; // fp9
  double y; // fp8
  double z; // fp7
  double v26; // fp6
  float *v27; // r11
  double v28; // fp1
  double v29; // fp13
  double v30; // fp8
  double v31; // fp11
  double v32; // fp9
  idMat3 v33; // [sp+50h] [-90h] BYREF
  idMat3 v34; // [sp+80h] [-60h] BYREF

  if ( bodyId >= 0
    && bodyId < this->bodies.num
    && !this->noImpact
    && (float)((float)(impulse->z * impulse->z)
             + (float)((float)(impulse->x * impulse->x) + (float)(impulse->y * impulse->y))) >= (double)(float)(this->impulseThreshold * this->impulseThreshold) )
  {
    v7 = this->bodies.list[bodyId];
    clipModel = (float *)v7->clipModel;
    v9 = (const idMat3 *)(clipModel + 11);
    v10 = clipModel[16];
    v11 = clipModel[13];
    v12 = clipModel[18];
    v13 = clipModel[15];
    v14 = clipModel[12];
    v15 = clipModel[17];
    v16 = clipModel[14];
    v17 = clipModel[11];
    v33.mat[2].z = clipModel[19];
    v33.mat[2].y = v10;
    v33.mat[2].x = v11;
    v33.mat[1].z = v12;
    v33.mat[1].y = v13;
    v33.mat[1].x = v14;
    v33.mat[0].z = v15;
    v33.mat[0].y = v16;
    v33.mat[0].x = v17;
    v18 = idMat3::operator*(this: &v34, result: &v33, a: &v7->inverseInertiaTensor);
    idMat3::operator*(this: &v33, result: v18, a: v9);
    v19 = (float)(impulse->y * v7->invMass);
    v20 = (float)(impulse->z * v7->invMass);
    v21 = v7->current.spatialVelocity.p[1];
    v22 = v7->current.spatialVelocity.p[2];
    x = v33.mat[1].x;
    y = v33.mat[1].y;
    z = v33.mat[1].z;
    v26 = v33.mat[2].x;
    v7->current.spatialVelocity.p[0] = v7->current.spatialVelocity.p[0] + (float)(impulse->x * v7->invMass);
    v7->current.spatialVelocity.p[1] = (float)v19 + (float)v21;
    v7->current.spatialVelocity.p[2] = (float)v20 + (float)v22;
    v27 = (float *)v7->clipModel;
    v28 = (float)((float)((float)((float)(impulse->z * (float)(point->y - v27[9]))
                                - (float)(impulse->y * (float)(point->z - v27[10])))
                        * v33.mat[0].x)
                + (float)((float)((float)v26
                                * (float)((float)(impulse->y * (float)(point->x - v27[8]))
                                        - (float)(impulse->x * (float)(point->y - v27[9]))))
                        + (float)((float)x
                                * (float)((float)(impulse->x * (float)(point->z - v27[10]))
                                        - (float)(impulse->z * (float)(point->x - v27[8]))))));
    v29 = (float)((float)(v33.mat[0].y
                        * (float)((float)(impulse->z * (float)(point->y - v27[9]))
                                - (float)(impulse->y * (float)(point->z - v27[10]))))
                + (float)((float)(v33.mat[2].y
                                * (float)((float)(impulse->y * (float)(point->x - v27[8]))
                                        - (float)(impulse->x * (float)(point->y - v27[9]))))
                        + (float)((float)y
                                * (float)((float)(impulse->x * (float)(point->z - v27[10]))
                                        - (float)(impulse->z * (float)(point->x - v27[8]))))));
    v30 = (float)((float)(v33.mat[0].z
                        * (float)((float)(impulse->z * (float)(point->y - v27[9]))
                                - (float)(impulse->y * (float)(point->z - v27[10]))))
                + (float)((float)(v33.mat[2].z
                                * (float)((float)(impulse->y * (float)(point->x - v27[8]))
                                        - (float)(impulse->x * (float)(point->y - v27[9]))))
                        + (float)((float)z
                                * (float)((float)(impulse->x * (float)(point->z - v27[10]))
                                        - (float)(impulse->z * (float)(point->x - v27[8]))))));
    v31 = v7->current.spatialVelocity.p[4];
    v32 = v7->current.spatialVelocity.p[5];
    v7->current.spatialVelocity.p[3] = v7->current.spatialVelocity.p[3] + (float)v28;
    v7->current.spatialVelocity.p[4] = (float)v31 + (float)v29;
    v7->current.spatialVelocity.p[5] = (float)v32 + (float)v30;
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
}


// ========================================================================
// ?ApplyForce@idPhysics_AF@@UAAXHABVidVec3@@0@Z
// EA  : 0x8273D468
// RVA : 0x0073D468
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::ApplyForce(idPhysics_AF *this, int bodyId, const idVec3 *point, const idVec3 *force)
{
  if ( !this->noImpact && bodyId >= 0 && bodyId < this->bodies.num )
  {
    idAFBody::AddForce(this: this->bodies.list[bodyId], point, force);
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
}


// ========================================================================
// ?Activate@idPhysics_AF@@UAAXXZ
// EA  : 0x8273D4E8
// RVA : 0x0073D4E8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::Activate(idPhysics_AF *this)
{
  bool v2; // r3
  double v3; // fp1

  v2 = this->IsAtRest(this);
  v3 = 0.0;
  if ( v2 )
  {
    idPhysics_AF::AddGravity(this);
    this->current.activateTime = v3;
  }
  this->current.noMoveTime = v3;
  this->current.atRest = false;
}


// ========================================================================
// ?PutToRest@idPhysics_AF@@UAAXXZ
// EA  : 0x8273D550
// RVA : 0x0073D550
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::PutToRest(idPhysics_AF *this, int a2, int a3, int a4, unsigned __int64 a5)
{
  int num; // r11
  int v6; // r9
  int v7; // r10
  idAFBody *v8; // r11
  float *v9; // r11
  int v10; // r10
  int v11; // r11
  idPhysics_AF::noclipBodyInfo_t *v12; // r9

  num = this->bodies.num;
  LODWORD(a5) = 0;
  v6 = 0;
  this->current.atRest = true;
  if ( num > 0 )
  {
    v7 = 0;
    do
    {
      ++v6;
      v8 = this->bodies.list[v7];
      v8->current.spatialVelocity.p[5] = 0.0;
      v8->current.spatialVelocity.p[4] = 0.0;
      v8->current.spatialVelocity.p[3] = 0.0;
      v8->current.spatialVelocity.p[2] = 0.0;
      v8->current.spatialVelocity.p[1] = 0.0;
      v8->current.spatialVelocity.p[0] = 0.0;
      HIDWORD(a5) = this->bodies.list;
      v9 = *(float **)(HIDWORD(a5) + v7 * 4);
      ++v7;
      v9[91] = 0.0;
      v9[90] = 0.0;
      v9[89] = 0.0;
      v9[88] = 0.0;
      v9[87] = 0.0;
      v9[86] = 0.0;
    }
    while ( v6 < this->bodies.num );
  }
  v10 = 0;
  if ( this->noclipBodies.num > 0 )
  {
    v11 = 0;
    do
    {
      ++v10;
      v12 = &this->noclipBodies.list[v11++];
      v12->query.index = a5;
      HIDWORD(a5) = this->noclipBodies.num;
    }
    while ( v10 < SHIDWORD(a5) );
  }
}


// ========================================================================
// ?RestoreState@idPhysics_AF@@UAAXXZ
// EA  : 0x8273D608
// RVA : 0x0073D608
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::RestoreState(idPhysics_AF *this)
{
  int v2; // r29
  int v3; // r31

  memcpy(Dst: &this->current, Src: &this->saved, Size: sizeof(this->current));
  v2 = 0;
  if ( this->bodies.num > 0 )
  {
    v3 = 0;
    do
    {
      AFBodyPState_t::operator=(this: &this->bodies.list[v3]->current, __that: &this->bodies.list[v3]->saved);
      idClipModel::SetLinkedPosition(
        this: this->bodies.list[v3]->clipModel,
        newOrigin: &this->bodies.list[v3]->saved.worldOrigin,
        newAxis: &this->bodies.list[v3]->saved.worldAxis);
      ++v2;
      ++v3;
    }
    while ( v2 < this->bodies.num );
  }
  this->EvaluateContacts(this);
}


// ========================================================================
// ?SetOrigin@idPhysics_AF@@UAAXABVidVec3@@H@Z
// EA  : 0x8273D698
// RVA : 0x0073D698
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetOrigin(idPhysics_AF *this, const idVec3 *newOrigin, int id)
{
  int num; // r11
  __int64 v4; // r30
  int v5; // r6
  idClip *clip; // r11
  unsigned __int64 collisionQueryFirstSubmittedIndex; // r8
  __int64 v8; // r10
  idClipModel *clipModel; // r11
  void (__fastcall *Translate)(struct idPhysics_AF *, const idVec3 *, int); // ctr
  double v11; // fp9
  double v12; // fp7
  float v13[16]; // [sp+50h] [-40h] BYREF

  num = this->bodies.num;
  LODWORD(v4) = 0;
  v5 = 0;
  if ( num > 0 )
  {
    HIDWORD(v4) = 1;
    do
    {
      clip = this->clip;
      collisionQueryFirstSubmittedIndex = clip->collisionQueryFirstSubmittedIndex;
      v8 = *(_QWORD *)(HIDWORD(collisionQueryFirstSubmittedIndex) + 512);
      if ( (unsigned int)v8 >= (unsigned int)collisionQueryFirstSubmittedIndex )
      {
        collisionQueryFirstSubmittedIndex = clip->collisionQueryLastAllocedIndex;
        if ( (unsigned int)v8 <= (unsigned int)collisionQueryFirstSubmittedIndex )
          clip->collisionQueries[v8 & 0xFFF].type = QUERY_CANCELED;
      }
      ++v5;
      *(_QWORD *)(HIDWORD(collisionQueryFirstSubmittedIndex) + 512) = v4;
      num = this->bodies.num;
    }
    while ( v5 < num );
  }
  if ( (id < 0 || id >= num) && num > 0 )
  {
    clipModel = (*this->bodies.list)->clipModel;
    Translate = this->Translate;
    v11 = (float)(newOrigin->z - clipModel->origin.z);
    v12 = (float)(newOrigin->y - clipModel->origin.y);
    v13[0] = newOrigin->x - clipModel->origin.x;
    v13[2] = v11;
    v13[1] = v12;
    ((void (__fastcall *)(idPhysics_AF *, float *, int, int))Translate)(a1: this, a2: v13, a3: -1, a4: v5);
  }
}


// ========================================================================
// ?SetAxis@idPhysics_AF@@UAAXABVidMat3@@H@Z
// EA  : 0x8273D7A8
// RVA : 0x0073D7A8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetAxis(idPhysics_AF *this, const idMat3 *newAxis, int id)
{
  int num; // r11
  __int64 v4; // r30
  int v6; // r6
  idClip *clip; // r11
  unsigned __int64 collisionQueryFirstSubmittedIndex; // r8
  __int64 v9; // r10
  float *clipModel; // r11
  double v11; // fp13
  double v12; // fp12
  double v13; // fp11
  double v14; // fp10
  double v15; // fp9
  double v16; // fp8
  double v17; // fp7
  double v18; // fp6
  idRotation *v19; // r3
  idClipModel *v20; // r11
  void (__fastcall *Rotate)(struct idPhysics_AF *, const idRotation *, int); // ctr
  idMat3 v22; // [sp+50h] [-D0h] BYREF
  idMat3 v23[2]; // [sp+80h] [-A0h] BYREF
  idMat3 v24[2]; // [sp+D0h] [-50h] BYREF

  num = this->bodies.num;
  LODWORD(v4) = 0;
  v6 = 0;
  if ( num > 0 )
  {
    HIDWORD(v4) = 1;
    do
    {
      clip = this->clip;
      collisionQueryFirstSubmittedIndex = clip->collisionQueryFirstSubmittedIndex;
      v9 = *(_QWORD *)(HIDWORD(collisionQueryFirstSubmittedIndex) + 512);
      if ( (unsigned int)v9 >= (unsigned int)collisionQueryFirstSubmittedIndex )
      {
        collisionQueryFirstSubmittedIndex = clip->collisionQueryLastAllocedIndex;
        if ( (unsigned int)v9 <= (unsigned int)collisionQueryFirstSubmittedIndex )
          clip->collisionQueries[v9 & 0xFFF].type = QUERY_CANCELED;
      }
      ++v6;
      *(_QWORD *)(HIDWORD(collisionQueryFirstSubmittedIndex) + 512) = v4;
      num = this->bodies.num;
    }
    while ( v6 < num );
  }
  if ( (id < 0 || id >= num) && num > 0 )
  {
    clipModel = (float *)(*this->bodies.list)->clipModel;
    v11 = clipModel[16];
    v12 = clipModel[13];
    v13 = clipModel[18];
    v14 = clipModel[15];
    v15 = clipModel[12];
    v16 = clipModel[17];
    v17 = clipModel[14];
    v18 = clipModel[11];
    v22.mat[2].z = clipModel[19];
    v22.mat[2].y = v11;
    v22.mat[2].x = v12;
    v22.mat[1].z = v13;
    v22.mat[1].y = v14;
    v22.mat[1].x = v15;
    v22.mat[0].z = v16;
    v22.mat[0].y = v17;
    v22.mat[0].x = v18;
    v19 = (idRotation *)idMat3::operator*(this: v24, result: &v22, a: newAxis);
    idMat3::ToRotation(this: v23, result: v19);
    v20 = (*this->bodies.list)->clipModel;
    Rotate = this->Rotate;
    v23[0].mat[0].x = v20->origin.x;
    v23[0].mat[0].y = v20->origin.y;
    v23[0].mat[0].z = v20->origin.z;
    Rotate(this, a2: (const idRotation *)v23, a3: -1);
  }
}


// ========================================================================
// ?GetOrigin@idPhysics_AF@@UBAABVidVec3@@H@Z
// EA  : 0x8273D918
// RVA : 0x0073D918
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

const idVec3 *__fastcall idPhysics_AF::GetOrigin(idPhysics_AF *this, int id)
{
  if ( id < 0 || id >= this->bodies.num )
    return &vec3_origin;
  else
    return &this->bodies.list[id]->clipModel->origin;
}


// ========================================================================
// ?GetAxis@idPhysics_AF@@UBAABVidMat3@@H@Z
// EA  : 0x8273D950
// RVA : 0x0073D950
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_AF::GetAxis(idPhysics_AF *this, int id)
{
  if ( id < 0 || id >= this->bodies.num )
    return &mat3_identity;
  else
    return &this->bodies.list[id]->clipModel->axis;
}


// ========================================================================
// ?SetLinearVelocity@idPhysics_AF@@UAAXABVidVec3@@H@Z
// EA  : 0x8273D988
// RVA : 0x0073D988
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetLinearVelocity(idPhysics_AF *this, const idVec3 *newLinearVelocity, int id)
{
  if ( id >= 0 && id < this->bodies.num )
  {
    *(idVec3 *)this->bodies.list[id]->current.spatialVelocity.p = *newLinearVelocity;
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
}


// ========================================================================
// ?SetAngularVelocity@idPhysics_AF@@UAAXABVidVec3@@H@Z
// EA  : 0x8273D9E0
// RVA : 0x0073D9E0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetAngularVelocity(idPhysics_AF *this, const idVec3 *newAngularVelocity, int id)
{
  if ( id >= 0 && id < this->bodies.num )
  {
    *(idVec3 *)&this->bodies.list[id]->current.spatialVelocity.p[3] = *newAngularVelocity;
    this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
}


// ========================================================================
// ?GetLinearVelocity@idPhysics_AF@@UBA?AVidVec3@@H@Z
// EA  : 0x8273DA38
// RVA : 0x0073DA38
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

idPhysics_AF *__fastcall idPhysics_AF::GetLinearVelocity(idPhysics_AF *this, idVec3 *result, int id)
{
  int v3; // r11
  int v4; // r8
  physicsType_t v5; // r7
  float y; // r8
  float z; // r7

  if ( id < 0 || id >= SLODWORD(result[11].z) )
  {
    y = vec3_origin.y;
    z = vec3_origin.z;
    this->__vftable = (idPhysics_AF_vtbl *)LODWORD(vec3_origin.x);
    *((float *)&this->__vftable + 1) = y;
    *(float *)&this->type = z;
  }
  else
  {
    v3 = *(_DWORD *)(LODWORD(result[11].y) + 4 * id);
    v4 = *(_DWORD *)(v3 + 324);
    v5 = *(_DWORD *)(v3 + 328);
    this->__vftable = *(idPhysics_AF_vtbl **)(v3 + 320);
    *((_DWORD *)&this->__vftable + 1) = v4;
    this->type = v5;
  }
  return this;
}


// ========================================================================
// ?GetAngularVelocity@idPhysics_AF@@UBA?AVidVec3@@H@Z
// EA  : 0x8273DA98
// RVA : 0x0073DA98
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

idPhysics_AF *__fastcall idPhysics_AF::GetAngularVelocity(idPhysics_AF *this, idVec3 *result, int id)
{
  int v3; // r11
  int v4; // r8
  physicsType_t v5; // r7
  float y; // r8
  float z; // r7

  if ( id < 0 || id >= SLODWORD(result[11].z) )
  {
    y = vec3_origin.y;
    z = vec3_origin.z;
    this->__vftable = (idPhysics_AF_vtbl *)LODWORD(vec3_origin.x);
    *((float *)&this->__vftable + 1) = y;
    *(float *)&this->type = z;
  }
  else
  {
    v3 = *(_DWORD *)(LODWORD(result[11].y) + 4 * id);
    v4 = *(_DWORD *)(v3 + 336);
    v5 = *(_DWORD *)(v3 + 340);
    this->__vftable = *(idPhysics_AF_vtbl **)(v3 + 332);
    *((_DWORD *)&this->__vftable + 1) = v4;
    this->type = v5;
  }
  return this;
}


// ========================================================================
// ?DisableClip@idPhysics_AF@@UAAXXZ
// EA  : 0x8273DAF8
// RVA : 0x0073DAF8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::DisableClip(idPhysics_AF *this)
{
  int v1; // r10
  int v2; // r11
  idAFBody *v3; // r7

  v1 = 0;
  if ( this->bodies.num > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = this->bodies.list[v2++];
      v3->clipModel->enabled = false;
    }
    while ( v1 < this->bodies.num );
  }
}


// ========================================================================
// ?EnableClip@idPhysics_AF@@UAAXXZ
// EA  : 0x8273DB38
// RVA : 0x0073DB38
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::EnableClip(idPhysics_AF *this)
{
  int v1; // r10
  int v2; // r11
  idAFBody *v3; // r7

  v1 = 0;
  if ( this->bodies.num > 0 )
  {
    v2 = 0;
    do
    {
      ++v1;
      v3 = this->bodies.list[v2++];
      v3->clipModel->enabled = true;
    }
    while ( v1 < this->bodies.num );
  }
}


// ========================================================================
// ?UnlinkClip@idPhysics_AF@@UAAXXZ
// EA  : 0x8273DB78
// RVA : 0x0073DB78
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::UnlinkClip(idPhysics_AF *this)
{
  int v2; // r30
  int v3; // r31

  v2 = 0;
  if ( this->bodies.num > 0 )
  {
    v3 = 0;
    do
    {
      idClipModel::Unlink(this: this->bodies.list[v3]->clipModel);
      ++v2;
      ++v3;
    }
    while ( v2 < this->bodies.num );
  }
}


// ========================================================================
// ?LinkClip@idPhysics_AF@@UAAXXZ
// EA  : 0x8273DBC8
// RVA : 0x0073DBC8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPhysics_AF::LinkClip(idPhysics_AF *this)
{
  idPhysics_AF::UpdateClipModels(this);
}


// ========================================================================
// ?SetPushed@idPhysics_AF@@UAAXH@Z
// EA  : 0x8273DBD0
// RVA : 0x0073DBD0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetPushed(idPhysics_AF *this, int deltaTime)
{
  __int64 v3; // r11
  double v4; // fp12
  float *v5; // r7
  double v6; // fp3
  double v7; // fp2
  double v8; // fp31
  double v9; // fp11
  double v10; // fp10
  double v11; // fp9
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  double v15; // fp5
  double v16; // fp4
  idMat3 *v17; // r3
  idVec3 *v18; // r3
  double v19; // fp13
  double v20; // fp12
  idMat3 v21; // [sp+50h] [-80h] BYREF
  float v22; // [sp+74h] [-5Ch]
  float v23; // [sp+78h] [-58h]
  float v24; // [sp+7Ch] [-54h]
  float v25; // [sp+80h] [-50h]
  idMat3 v26; // [sp+90h] [-40h] BYREF

  if ( this->bodies.num > 0 )
  {
    LODWORD(v3) = deltaTime;
    HIDWORD(v3) = this->bodies.list;
    *(_QWORD *)&v21.mat[0].x = v3;
    v4 = (float)v3;
    v5 = *(float **)HIDWORD(v3);
    LODWORD(v3) = *(_DWORD *)(*(_DWORD *)HIDWORD(v3) + 20);
    v6 = (float)(*(float *)(v3 + 36) - *(float *)(*(_DWORD *)HIDWORD(v3) + 372));
    v7 = (float)(*(float *)(v3 + 40) - *(float *)(*(_DWORD *)HIDWORD(v3) + 376));
    v8 = (float)((float)1.0 / (float)((float)v4 * (float)0.001));
    this->current.pushVelocity.p[0] = (float)(*(float *)(v3 + 32) - *(float *)(*(_DWORD *)HIDWORD(v3) + 368))
                                    * (float)((float)1.0 / (float)((float)v4 * (float)0.001));
    this->current.pushVelocity.p[1] = (float)v6 * (float)((float)1.0 / (float)((float)v4 * (float)0.001));
    this->current.pushVelocity.p[2] = (float)v7 * (float)((float)1.0 / (float)((float)v4 * (float)0.001));
    v9 = v5[102];
    v10 = v5[99];
    v11 = v5[96];
    v12 = v5[101];
    v13 = v5[98];
    v14 = v5[95];
    v15 = v5[103];
    v16 = v5[100];
    v23 = v5[97];
    v24 = v16;
    v25 = v15;
    v22 = v9;
    v21.mat[2].z = v10;
    v21.mat[2].y = v11;
    v21.mat[2].x = v12;
    v21.mat[1].z = v13;
    v21.mat[1].y = v14;
    v17 = idMat3::operator*(this: &v26, result: (idMat3 *)(v3 + 44), a: (idMat3 *)&v21.mat[1].y);
    v18 = idMat3::ToAngularVelocity(this: &v21, result: v17->mat);
    v19 = (float)(v18->y * (float)v8);
    v20 = (float)(v18->z * (float)v8);
    this->current.pushVelocity.p[3] = v18->x * (float)v8;
    this->current.pushVelocity.p[4] = v19;
    this->current.pushVelocity.p[5] = v20;
  }
}


// ========================================================================
// ?GetPushedLinearVelocity@idPhysics_AF@@UBA?AVidVec3@@H@Z
// EA  : 0x8273DD08
// RVA : 0x0073DD08
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

idPhysics_AF *__fastcall idPhysics_AF::GetPushedLinearVelocity(idPhysics_AF *this, idVec3 *result, const int id)
{
  float x; // r10
  float y; // r9

  x = result[65].x;
  y = result[65].y;
  this->__vftable = (idPhysics_AF_vtbl *)LODWORD(result[64].z);
  *((float *)&this->__vftable + 1) = x;
  *(float *)&this->type = y;
  return this;
}


// ========================================================================
// ?GetPushedAngularVelocity@idPhysics_AF@@UBA?AVidVec3@@H@Z
// EA  : 0x8273DD28
// RVA : 0x0073DD28
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

idPhysics_AF *__fastcall idPhysics_AF::GetPushedAngularVelocity(idPhysics_AF *this, idVec3 *result, const int id)
{
  float x; // r10
  float y; // r9

  x = result[66].x;
  y = result[66].y;
  this->__vftable = (idPhysics_AF_vtbl *)LODWORD(result[65].z);
  *((float *)&this->__vftable + 1) = x;
  *(float *)&this->type = y;
  return this;
}


// ========================================================================
// ?SetColor@idLight@@UAAXABVidVec3@@@Z
// EA  : 0x8273DD48
// RVA : 0x0073DD48
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idLight::SetColor(idPhysics_AF *this, const idVec3 *linear)
{
  this->current.auxVelocity.p[0] = linear->x;
  this->current.auxVelocity.p[1] = linear->y;
  this->current.auxVelocity.p[2] = linear->z;
}


// ========================================================================
// ?SetAuxAngularVelocity@idPhysics_AF@@QAAXABVidVec3@@@Z
// EA  : 0x8273DD68
// RVA : 0x0073DD68
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetAuxAngularVelocity(idPhysics_AF *this, const idVec3 *angular)
{
  *(idVec3 *)&this->current.auxVelocity.p[3] = *angular;
}


// ========================================================================
// ?SetMaster@idPhysics_AF@@UAAX_NABVidVec3@@ABVidMat3@@W4bindFlags_t@@@Z
// EA  : 0x8273DD90
// RVA : 0x0073DD90
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetMaster(
        idPhysics_AF *this,
        bool enable,
        const idVec3 *masterOrigin,
        const idMat3 *masterAxis,
        const bindFlags_t bflags)
{
  idAFBody *masterBody; // r11
  idAFBody *v9; // r3
  idAFBody *v10; // r3
  idClipModel *v11; // r3
  idClipModel *v12; // r28
  double z; // fp13
  double v14; // fp12
  double y; // fp11
  double v16; // fp10
  double v17; // fp9
  double x; // fp8
  double v19; // fp7
  double v20; // fp6
  int v21; // r28
  int v22; // r29
  idAFConstraint *v23; // r3
  double v24; // fp10
  double v25; // fp9
  void (*ActivatePhysics)(void); // ctr
  int v27; // r28
  int v28; // r29
  idAFConstraint *v29; // r3
  idAFBody *v30; // r3
  idPhysicsCallbacks *callbacks; // r3
  float v32[6]; // [sp+58h] [-6F8h] BYREF
  idBounds v33; // [sp+70h] [-6E0h] BYREF
  idRotation v34; // [sp+90h] [-6C0h] BYREF
  idTraceModel v35; // [sp+110h] [-640h] BYREF

  masterBody = this->masterBody;
  if ( enable )
  {
    if ( masterBody != nullptr )
    {
      idClipModel::SetLinkedPosition(
        this: masterBody->clipModel,
        newOrigin: masterOrigin,
        newAxis: &masterBody->clipModel->axis);
      idClipModel::SetLinkedPosition(
        this: this->masterBody->clipModel,
        newOrigin: &this->masterBody->clipModel->origin,
        newAxis: masterAxis);
      return;
    }
    v9 = (idAFBody *)idMem::AllocWithLocation(
                       this: &mem,
                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                       size: 0x330u,
                       tag: TAG_AF,
                       zeroBuffer: false,
                       align: ALIGN_16,
                       heap: HEAP_DEFAULTHEAP);
    if ( v9 != nullptr )
      v10 = idAFBody::idAFBody(this: v9);
    else
      v10 = nullptr;
    this->masterBody = v10;
    v33.b[0].x = -8.0;
    v33.b[0].y = -8.0;
    v33.b[0].z = -8.0;
    v33.b[1].x = 8.0;
    v33.b[1].y = 8.0;
    v33.b[1].z = 8.0;
    idTraceModel::InitBox(this: &v35);
    idTraceModel::SetupBox(this: &v35, boxBounds: &v33);
    v11 = (idClipModel *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0xD8u,
                           tag: TAG_CLIPMODEL,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
    if ( v11 != nullptr )
      v12 = idClipModel::idClipModel(this: v11, clip: this->clip, trm: &v35, numTraceModels: 1, material: nullptr);
    else
      v12 = nullptr;
    idClipModel::SetContents(this: v12, newContents: 0);
    idAFBody::SetClipModel(this: this->masterBody, clipModel: v12);
    idClipModel::SetLinkedPosition(
      this: this->masterBody->clipModel,
      newOrigin: masterOrigin,
      newAxis: &this->masterBody->clipModel->axis);
    idClipModel::SetLinkedPosition(
      this: this->masterBody->clipModel,
      newOrigin: &this->masterBody->clipModel->origin,
      newAxis: masterAxis);
    z = masterAxis->mat[1].z;
    v14 = masterAxis->mat[0].z;
    y = masterAxis->mat[2].y;
    v16 = masterAxis->mat[1].y;
    v17 = masterAxis->mat[0].y;
    x = masterAxis->mat[2].x;
    v19 = masterAxis->mat[1].x;
    v20 = masterAxis->mat[0].x;
    v34.axis.mat[0].y = masterAxis->mat[2].z;
    v34.axis.mat[0].x = z;
    v34.angle = v14;
    v34.vec.z = y;
    v34.vec.y = v16;
    v34.vec.x = v17;
    v34.origin.z = x;
    v34.origin.y = v19;
    v34.origin.x = v20;
    idMat3::ToRotation(this: (idMat3 *)&v34.axis.mat[1].z, result: &v34);
    v21 = 0;
    if ( this->constraints.num > 0 )
    {
      v22 = 0;
      do
      {
        v23 = this->constraints.list[v22];
        if ( v23->body2 == nullptr )
        {
          v24 = -masterOrigin->y;
          v25 = -masterOrigin->z;
          v32[0] = -masterOrigin->x;
          v32[1] = v24;
          v32[2] = v25;
          v23->Translate(this: v23, a2: (const idVec3 *)v32);
          this->constraints.list[v22]->Rotate(this: this->constraints.list[v22], a2: (idRotation *)&v34.axis.mat[1].z);
        }
        ++v21;
        ++v22;
      }
      while ( v21 < this->constraints.num );
    }
    ActivatePhysics = (void (*)(void))this->callbacks->ActivatePhysics;
  }
  else
  {
    if ( masterBody == nullptr )
      return;
    idMat3::ToRotation(this: (idMat3 *)&v34.axis.mat[1].z, result: (idRotation *)&masterBody->clipModel->axis);
    v27 = 0;
    if ( this->constraints.num > 0 )
    {
      v28 = 0;
      do
      {
        v29 = this->constraints.list[v28];
        if ( v29->body2 == this->masterBody )
        {
          v29->Rotate(this: v29, a2: (idRotation *)&v34.axis.mat[1].z);
          this->constraints.list[v28]->Translate(
            this: this->constraints.list[v28],
            a2: &this->masterBody->clipModel->origin);
          this->constraints.list[v28]->SetBody2(this: this->constraints.list[v28], a2: nullptr);
        }
        ++v27;
        ++v28;
      }
      while ( v27 < this->constraints.num );
    }
    v30 = this->masterBody;
    if ( v30 != nullptr )
      ((void (__fastcall *)(idAFBody *, int))v30->dtr_idAFBody)(a1: v30, a2: 1);
    callbacks = this->callbacks;
    this->masterBody = nullptr;
    ActivatePhysics = (void (*)(void))callbacks->ActivatePhysics;
  }
  ActivatePhysics();
}


// ========================================================================
// __unwind$255235
// EA  : 0x8273E0F0
// RVA : 0x0073E0F0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_255235()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1872 + 80), tag: TAG_AF);
}


// ========================================================================
// __unwind$255236
// EA  : 0x8273E11C
// RVA : 0x0073E11C
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_255236()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 1872 + 80), tag: TAG_CLIPMODEL);
}


// ========================================================================
// ?SetLocalOrigin@idPhysics_AF@@UAAXABVidVec3@@H@Z
// EA  : 0x8273E148
// RVA : 0x0073E148
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysics_AF::SetLocalOrigin(idPhysics_AF *this, const idVec3 *newOrigin, int id)
{
  int v3; // r31 OVERLAPPED
  int v4; // r6
  int v5; // r30 OVERLAPPED
  idClip *clip; // r11
  unsigned __int64 collisionQueryFirstSubmittedIndex; // r8
  __int64 v8; // r10
  idAFBody *masterBody; // r11
  float *clipModel; // r9
  idClipModel *v11; // r11
  double v12; // fp9
  double v13; // fp8
  idClipModel *v14; // r11
  double v15; // fp6
  float v16; // [sp+50h] [-30h] BYREF
  float v17; // [sp+54h] [-2Ch]
  float v18; // [sp+58h] [-28h]

  v3 = 0;
  v4 = 0;
  if ( this->bodies.num > 0 )
  {
    v5 = 1;
    do
    {
      clip = this->clip;
      collisionQueryFirstSubmittedIndex = clip->collisionQueryFirstSubmittedIndex;
      v8 = *(_QWORD *)(HIDWORD(collisionQueryFirstSubmittedIndex) + 512);
      if ( (unsigned int)v8 >= (unsigned int)collisionQueryFirstSubmittedIndex )
      {
        collisionQueryFirstSubmittedIndex = clip->collisionQueryLastAllocedIndex;
        if ( (unsigned int)v8 <= (unsigned int)collisionQueryFirstSubmittedIndex )
          clip->collisionQueries[v8 & 0xFFF].type = QUERY_CANCELED;
      }
      ++v4;
      *(_QWORD *)(HIDWORD(collisionQueryFirstSubmittedIndex) + 512) = *(_QWORD *)&v3;
    }
    while ( v4 < this->bodies.num );
  }
  masterBody = this->masterBody;
  if ( masterBody != nullptr )
  {
    clipModel = (float *)masterBody->clipModel;
    v11 = (*this->bodies.list)->clipModel;
    v12 = (float)((float)(clipModel[8]
                        + (float)((float)(clipModel[11] * newOrigin->x)
                                + (float)((float)(clipModel[14] * newOrigin->y) + (float)(clipModel[17] * newOrigin->z))))
                - v11->origin.x);
    v13 = (float)((float)(clipModel[9]
                        + (float)((float)(clipModel[18] * newOrigin->z)
                                + (float)((float)(clipModel[12] * newOrigin->x) + (float)(clipModel[15] * newOrigin->y))))
                - v11->origin.y);
    v18 = (float)(clipModel[10]
                + (float)((float)(clipModel[19] * newOrigin->z)
                        + (float)((float)(clipModel[13] * newOrigin->x) + (float)(clipModel[16] * newOrigin->y))))
        - v11->origin.z;
    v17 = v13;
  }
  else
  {
    v14 = (*this->bodies.list)->clipModel;
    v15 = (float)(newOrigin->z - v14->origin.z);
    v12 = (float)(newOrigin->x - v14->origin.x);
    v17 = newOrigin->y - v14->origin.y;
    v18 = v15;
  }
  v16 = v12;
  ((void (__fastcall *)(idPhysics_AF *, float *, int, int))this->Translate)(a1: this, a2: &v16, a3: -1, a4: v4);
}


// ========================================================================
// ?SetLocalAxis@idPhysics_AF@@UAAXABVidMat3@@H@Z
// EA  : 0x8273E2E8
// RVA : 0x0073E2E8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetLocalAxis(idPhysics_AF *this, unsigned __int64 id)
{
  __int64 v2; // r30
  int v4; // r6
  int v5; // r9
  idClip *clip; // r11
  unsigned __int64 collisionQueryLastAllocedIndex; // r8
  __int64 v8; // r10
  idAFBody *masterBody; // r11
  float *clipModel; // r11
  double v11; // fp13
  double v12; // fp12
  double v13; // fp11
  double v14; // fp10
  double v15; // fp9
  double v16; // fp8
  double v17; // fp7
  double v18; // fp6
  const idMat3 *v19; // r5
  float *v20; // r11
  double v21; // fp13
  double v22; // fp12
  double v23; // fp11
  double v24; // fp10
  double v25; // fp9
  double v26; // fp8
  double v27; // fp7
  double v28; // fp6
  float *v29; // r3
  void (__fastcall *Rotate)(struct idPhysics_AF *, const idRotation *, int); // ctr
  idClipModel *v31; // r11
  idMat3 v32; // [sp+50h] [-130h] BYREF
  idRotation v33; // [sp+80h] [-100h] BYREF
  idMat3 v34; // [sp+100h] [-80h] BYREF
  idMat3 v35[2]; // [sp+130h] [-50h] BYREF

  LODWORD(v2) = 0;
  v4 = 0;
  if ( this->bodies.num > 0 )
  {
    v5 = 0;
    HIDWORD(v2) = 1;
    do
    {
      clip = this->clip;
      HIDWORD(collisionQueryLastAllocedIndex) = *(idAFBody **)((char *)this->bodies.list + v5);
      id = clip->collisionQueryFirstSubmittedIndex;
      v8 = *(_QWORD *)(HIDWORD(collisionQueryLastAllocedIndex) + 512);
      if ( (unsigned int)v8 >= (unsigned int)id )
      {
        collisionQueryLastAllocedIndex = clip->collisionQueryLastAllocedIndex;
        if ( (unsigned int)v8 <= (unsigned int)collisionQueryLastAllocedIndex )
          clip->collisionQueries[v8 & 0xFFF].type = QUERY_CANCELED;
      }
      ++v4;
      *(_QWORD *)(HIDWORD(collisionQueryLastAllocedIndex) + 512) = v2;
      v5 = HIDWORD(v8) + 4;
    }
    while ( v4 < this->bodies.num );
  }
  masterBody = this->masterBody;
  if ( masterBody != nullptr )
  {
    LODWORD(id) = &masterBody->clipModel->axis;
    clipModel = (float *)(*this->bodies.list)->clipModel;
    v11 = clipModel[16];
    v12 = clipModel[13];
    v13 = clipModel[18];
    v14 = clipModel[15];
    v15 = clipModel[12];
    v16 = clipModel[17];
    v17 = clipModel[14];
    v18 = clipModel[11];
    v32.mat[2].z = clipModel[19];
    v32.mat[2].y = v11;
    v32.mat[2].x = v12;
    v32.mat[1].z = v13;
    v32.mat[1].y = v14;
    v32.mat[1].x = v15;
    v32.mat[0].z = v16;
    v32.mat[0].y = v17;
    v32.mat[0].x = v18;
    v19 = idMat3::operator*(this: v35, result: (idMat3 *)HIDWORD(id), a: (const idMat3 *)id);
  }
  else
  {
    v19 = (const idMat3 *)HIDWORD(id);
    v20 = (float *)(*this->bodies.list)->clipModel;
    v21 = v20[16];
    v22 = v20[13];
    v23 = v20[18];
    v24 = v20[15];
    v25 = v20[12];
    v26 = v20[17];
    v27 = v20[14];
    v28 = v20[11];
    v32.mat[2].z = v20[19];
    v32.mat[2].y = v21;
    v32.mat[2].x = v22;
    v32.mat[1].z = v23;
    v32.mat[1].y = v24;
    v32.mat[1].x = v25;
    v32.mat[0].z = v26;
    v32.mat[0].y = v27;
    v32.mat[0].x = v28;
  }
  v29 = (float *)idMat3::operator*(this: &v34, result: &v32, a: v19);
  v33.origin.x = *v29;
  v33.origin.y = v29[1];
  v33.origin.z = v29[2];
  v33.vec.x = v29[3];
  v33.vec.y = v29[4];
  v33.vec.z = v29[5];
  v33.angle = v29[6];
  v33.axis.mat[0].x = v29[7];
  v33.axis.mat[0].y = v29[8];
  idMat3::ToRotation(this: (idMat3 *)&v33.axis.mat[1].z, result: &v33);
  Rotate = this->Rotate;
  v31 = (*this->bodies.list)->clipModel;
  v33.axis.mat[1].z = v31->origin.x;
  v33.axis.mat[2].x = v31->origin.y;
  v33.axis.mat[2].y = v31->origin.z;
  Rotate(this, a2: (idRotation *)&v33.axis.mat[1].z, a3: -1);
}


// ========================================================================
// ?Serialize@idPhysics_AF@@UAAXAAVidSerializer@@@Z
// EA  : 0x8273E500
// RVA : 0x0073E500
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::Serialize(idPhysics_AF *this, idSerializer *ser)
{
  __int64 v2; // r30
  int i; // r6
  idClip *clip; // r11
  unsigned __int64 collisionQueryFirstSubmittedIndex; // r8
  __int64 v8; // r10
  int v9; // r28
  int v10; // r29
  int v11; // r28
  int v12; // r29

  LODWORD(v2) = 0;
  if ( !ser->writing )
  {
    for ( i = 0; i < this->bodies.num; *(_QWORD *)(HIDWORD(collisionQueryFirstSubmittedIndex) + 512) = v2 )
    {
      clip = this->clip;
      collisionQueryFirstSubmittedIndex = clip->collisionQueryFirstSubmittedIndex;
      v8 = *(_QWORD *)(HIDWORD(collisionQueryFirstSubmittedIndex) + 512);
      if ( (unsigned int)v8 >= (unsigned int)collisionQueryFirstSubmittedIndex )
      {
        collisionQueryFirstSubmittedIndex = clip->collisionQueryLastAllocedIndex;
        if ( (unsigned int)v8 <= (unsigned int)collisionQueryFirstSubmittedIndex )
          clip->collisionQueries[v8 & 0xFFF].type = QUERY_CANCELED;
      }
      ++i;
    }
    v9 = 0;
    if ( this->constraints.num > 0 )
    {
      v10 = 0;
      do
      {
        this->constraints.list[v10]->CancelCollisionQueries(this: this->constraints.list[v10]);
        ++v9;
        ++v10;
      }
      while ( v9 < this->constraints.num );
    }
  }
  v11 = 0;
  if ( this->constraints.num > 0 )
  {
    v12 = 0;
    do
    {
      this->constraints.list[v12]->Serialize(this: this->constraints.list[v12], a2: ser);
      ++v11;
      ++v12;
    }
    while ( v11 < this->constraints.num );
  }
  HIDWORD(v2) = 0;
  if ( this->bodies.num > 0 )
  {
    do
    {
      (*(void (__fastcall **)(_DWORD, idSerializer *))(**(_DWORD **)((char *)this->bodies.list + v2) + 4))(
        a1: *(idAFBody **)((char *)this->bodies.list + v2),
        a2: ser);
      ++HIDWORD(v2);
      LODWORD(v2) = v2 + 4;
    }
    while ( SHIDWORD(v2) < this->bodies.num );
  }
  if ( !ser->writing )
    idPhysics_AF::UpdateClipModels(this);
}


// ========================================================================
// ?EvaluateBodies@idPhysics_AF@@AAAXM@Z
// EA  : 0x8273E690
// RVA : 0x0073E690
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::EvaluateBodies(idPhysics_AF *this, double timeStep)
{
  int v4; // r25
  int v5; // r28
  idAFBody *v7; // r31
  double x; // fp5
  float *clipModel; // r11
  double v10; // fp0
  double v11; // fp13
  double v12; // fp12
  double v13; // fp11
  double v14; // fp10
  double v15; // fp9
  double v16; // fp3
  double v17; // fp8
  double v18; // fp7
  double v19; // fp6
  bool v20; // r11
  const idMat3 *p_inertiaTensor; // r5
  double v22; // fp31
  double v23; // fp30
  double v24; // fp29
  double v25; // fp28
  double v26; // fp26
  double v27; // fp4
  double v28; // fp3
  double v29; // fp2
  double v30; // fp1
  idMat3 *v31; // r3
  const idMat3 *v32; // r3
  double invMass; // fp3
  double v34; // fp2
  double v35; // fp1
  idMat3 *v36; // r3
  const idMat3 *v37; // r3
  idAFBody::afBodyFlags_t v39; // r10
  double mass; // fp24
  double v41; // fp23
  double v42; // fp21
  double v43; // fp20
  double v44; // fp22
  double v45; // fp4
  double v46; // fp3
  double v47; // fp19
  double v48; // fp26
  double v49; // fp25
  double v50; // fp2
  idMat3 *v51; // r3
  const idMat3 *v52; // r3
  idMat3 v56; // [sp+50h] [-2E0h] BYREF
  idMat3 v57; // [sp+80h] [-2B0h] BYREF
  idMat3 v58; // [sp+B0h] [-280h] BYREF
  idMat3 v59; // [sp+E0h] [-250h] BYREF
  idMat3 v60; // [sp+110h] [-220h] BYREF
  idMat3 v61; // [sp+140h] [-1F0h] BYREF
  idMat3 v62; // [sp+170h] [-1C0h] BYREF
  idMat3 v63; // [sp+1A0h] [-190h] BYREF
  idMat3 v64; // [sp+1D0h] [-160h] BYREF
  idMat3 v65; // [sp+200h] [-130h] BYREF
  idMat3 v66[4]; // [sp+230h] [-100h] BYREF

  _R12 = -208;
  __asm { stvx128   v127, r1, r12 }
  v4 = 0;
  if ( this->bodies.num > 0 )
  {
    __asm { vspltisw128 v127, 0 }
    v5 = 0;
    _R22 = 16;
    do
    {
      v7 = this->bodies.list[v5];
      x = v7->centerOfMass.x;
      clipModel = (float *)v7->clipModel;
      v10 = clipModel[19];
      v11 = clipModel[16];
      v12 = clipModel[13];
      v13 = clipModel[18];
      v14 = clipModel[15];
      v15 = clipModel[12];
      v16 = __fabs((float)(v7->centerOfMass.x - vec3_origin.x));
      v17 = clipModel[17];
      v18 = clipModel[14];
      v19 = clipModel[11];
      v56.mat[2].z = clipModel[19];
      v20 = false;
      v56.mat[2].y = v11;
      v56.mat[2].x = v12;
      v56.mat[1].z = v13;
      v56.mat[1].y = v14;
      v56.mat[0].z = v17;
      v56.mat[0].y = v18;
      v56.mat[0].x = v19;
      v56.mat[1].x = v15;
      if ( v16 <= 0.000099999997 && __fabs((float)(v7->centerOfMass.y - vec3_origin.y)) <= 0.000099999997 )
        v20 = __fabs((float)(v7->centerOfMass.z - vec3_origin.z)) <= 0.000099999997;
      p_inertiaTensor = &v7->inertiaTensor;
      if ( v20 )
      {
        v22 = (float)(v7->mass * mat3_identity.mat[2].z);
        v23 = (float)(v7->mass * mat3_identity.mat[2].y);
        v24 = (float)(v7->mass * mat3_identity.mat[2].x);
        v25 = (float)(v7->mass * mat3_identity.mat[1].z);
        v26 = (float)(v7->mass * mat3_identity.mat[1].y);
        v27 = (float)(v7->mass * mat3_identity.mat[1].x);
        v28 = (float)(v7->mass * mat3_identity.mat[0].z);
        v29 = (float)(v7->mass * mat3_identity.mat[0].y);
        v30 = (float)(v7->mass * mat3_identity.mat[0].x);
        v64.mat[0].x = v19;
        v64.mat[0].y = v15;
        v64.mat[0].z = v12;
        v64.mat[1].x = v18;
        v64.mat[1].y = v14;
        v64.mat[1].z = v11;
        v64.mat[2].x = v17;
        v64.mat[2].y = v13;
        v64.mat[2].z = v10;
        v59.mat[0].x = v30;
        v59.mat[0].y = v29;
        v59.mat[0].z = v28;
        v59.mat[1].x = v27;
        v59.mat[1].y = v26;
        v59.mat[1].z = v25;
        v59.mat[2].x = v24;
        v59.mat[2].y = v23;
        v59.mat[2].z = v22;
        v31 = idMat3::operator*(this: &v65, result: &v56, a: p_inertiaTensor);
        v32 = idMat3::operator*(this: v66, result: v31, a: &v64);
        idSpatialMat::Set(this: &v7->I, m1: &v59, m2: &mat3_zero, m3: &mat3_zero, m4: v32);
        invMass = v7->invMass;
        v34 = (float)(v7->invMass * mat3_identity.mat[2].z);
        v35 = (float)(v7->invMass * mat3_identity.mat[2].y);
        v63.mat[0].x = v56.mat[0].x;
        v63.mat[0].y = v56.mat[1].x;
        v63.mat[0].z = v56.mat[2].x;
        v63.mat[1].x = v56.mat[0].y;
        v63.mat[1].y = v56.mat[1].y;
        v63.mat[1].z = v56.mat[2].y;
        v63.mat[2].x = v56.mat[0].z;
        v63.mat[2].y = v56.mat[1].z;
        v63.mat[2].z = v56.mat[2].z;
        v61.mat[0].x = (float)invMass * mat3_identity.mat[0].x;
        v61.mat[2].z = v34;
        v61.mat[2].y = v35;
        v61.mat[2].x = (float)invMass * mat3_identity.mat[2].x;
        v61.mat[1].z = (float)invMass * mat3_identity.mat[1].z;
        v61.mat[1].y = (float)invMass * mat3_identity.mat[1].y;
        v61.mat[1].x = (float)invMass * mat3_identity.mat[1].x;
        v61.mat[0].z = (float)invMass * mat3_identity.mat[0].z;
        v61.mat[0].y = (float)invMass * mat3_identity.mat[0].y;
        v36 = idMat3::operator*(this: v66, result: &v56, a: &v7->inverseInertiaTensor);
        v37 = idMat3::operator*(this: &v65, result: v36, a: &v63);
        idSpatialMat::Set(this: &v7->inverseWorldSpatialInertia, m1: &v61, m2: &mat3_zero, m3: &mat3_zero, m4: v37);
        v39 = (idAFBody::afBodyFlags_t)(*(_BYTE *)&v7->fl | 0x20);
      }
      else
      {
        mass = v7->mass;
        v41 = (float)((float)x * v7->mass);
        v42 = (float)(v7->centerOfMass.z * v7->mass);
        v43 = (float)(v7->centerOfMass.y * v7->mass);
        v44 = (float)(v7->mass * (float)0.0);
        v45 = (float)(v7->mass * mat3_identity.mat[2].z);
        v46 = (float)(v7->mass * mat3_identity.mat[2].y);
        v47 = (float)((float)-x * v7->mass);
        v48 = (float)((float)-v7->centerOfMass.y * v7->mass);
        v49 = (float)((float)-v7->centerOfMass.z * v7->mass);
        v50 = (float)(v7->mass * mat3_identity.mat[2].x);
        v60.mat[0].y = (float)-v7->centerOfMass.z * v7->mass;
        v60.mat[0].x = v44;
        v60.mat[0].z = v43;
        v60.mat[1].x = v42;
        v60.mat[1].y = v44;
        v60.mat[1].z = v47;
        v60.mat[2].x = v48;
        v60.mat[2].y = v41;
        v60.mat[2].z = v44;
        v57.mat[0].x = v19;
        v57.mat[0].y = v15;
        v57.mat[0].z = v12;
        v57.mat[1].x = v18;
        v57.mat[1].y = v14;
        v57.mat[1].z = v11;
        v57.mat[2].x = v17;
        v57.mat[2].y = v13;
        v57.mat[2].z = v10;
        v58.mat[0].x = v44;
        v58.mat[0].y = v42;
        v58.mat[0].z = v48;
        v58.mat[1].x = v49;
        v58.mat[1].y = v44;
        v58.mat[1].z = v41;
        v58.mat[2].x = v43;
        v58.mat[2].y = v47;
        v58.mat[2].z = v44;
        v62.mat[0].x = (float)mass * mat3_identity.mat[0].x;
        v62.mat[0].y = (float)mass * mat3_identity.mat[0].y;
        v62.mat[0].z = (float)mass * mat3_identity.mat[0].z;
        v62.mat[1].x = (float)mass * mat3_identity.mat[1].x;
        v62.mat[1].y = (float)mass * mat3_identity.mat[1].y;
        v62.mat[1].z = (float)mass * mat3_identity.mat[1].z;
        v62.mat[2].x = v50;
        v62.mat[2].y = v46;
        v62.mat[2].z = v45;
        v51 = idMat3::operator*(this: v66, result: &v56, a: p_inertiaTensor);
        v52 = idMat3::operator*(this: &v65, result: v51, a: &v57);
        idSpatialMat::Set(this: &v7->I, m1: &v62, m2: &v60, m3: &v58, m4: v52);
        idSpatialMat::Inverse(this: &v7->I, dst: &v7->inverseWorldSpatialInertia);
        v39 = (idAFBody::afBodyFlags_t)(*(_BYTE *)&v7->fl & 0xDF);
      }
      v7->fl = v39;
      ++v4;
      _R10 = v7->auxForce.p;
      __asm { stvx128   v127, r0, r10 }
      _R9 = _R10;
      __asm { stvx128   v127, r9, r22 }
      ++v5;
    }
    while ( v4 < this->bodies.num );
  }
  _R0 = -208;
  __asm { lvx128    v127, r1, r0 }
}


// ========================================================================
// ?AuxiliaryForces@idPhysics_AF@@AAAXM@Z
// EA  : 0x8273EB10
// RVA : 0x0073EB10
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::AuxiliaryForces(idPhysics_AF *this, double timeStep)
{
  int v4; // r20
  int v5; // r10
  int v6; // r11
  idAFConstraint *v7; // r9
  int v8; // r9
  int v9; // r12
  float *v10; // r10
  idAFTree *tree; // r3
  int v12; // r9
  int v13; // r11
  int v14; // r12
  int *p_num; // r9
  bool v16; // zf
  int v17; // r8
  idAFBody *v18; // r4
  int v19; // r11
  int v20; // r6
  int v21; // r7
  int v22; // r8
  idAFConstraint *v23; // r9
  idAFBody *body1; // r10
  idAFBody *body2; // r10
  int v26; // r29
  int v27; // r30
  int v28; // r28
  int v29; // r26
  int v30; // r27
  int v31; // r29
  idAFConstraint *v32; // r30
  idAFBody *v33; // r11
  int v34; // r12
  int v35; // r5
  int v36; // r25
  int v37; // r22
  int v38; // r23
  idAFConstraint *v39; // r28
  idSpatialMat *p_J1; // r24
  int v41; // r29
  int v42; // r26
  int v43; // r27
  int v44; // r30
  int v45; // r11
  int numResponses; // r4
  int v47; // r3
  idAFBody *v48; // r11
  int v49; // r30
  int v50; // r29
  int v51; // r11
  int v52; // r4
  int v53; // r9
  int v54; // r10
  idAFBody *v55; // r11
  float *p; // r7
  float *mat; // r6
  float *v58; // r5
  double v59; // fp10
  double v60; // fp7
  double v61; // fp13
  double v62; // fp1
  double v63; // fp0
  double v64; // fp11
  double v65; // fp8
  double v66; // fp4
  double v67; // fp5
  double v68; // fp2
  double v69; // fp3
  int v70; // r12
  int v71; // r12
  int v72; // r12
  int v73; // r12
  int v74; // r12
  int v75; // r8
  int v76; // r11
  int v77; // r9
  int v78; // r12
  idAFConstraint **list; // r7
  int v80; // r10
  idAFConstraint *v81; // r6
  int v82; // r28
  int v83; // r23
  int v84; // r24
  idTimer *v85; // r30
  idAFConstraint *v86; // r10
  int v87; // r11
  int v88; // r8
  int v89; // r4
  int *boxIndex; // r27
  float *v91; // r9
  float *v92; // r5
  idAFBody *v93; // r9
  float *v94; // r6
  float *v95; // r9
  int v96; // r6
  idAFConstraint *boxConstraint; // r9
  __int64 v98; // r3
  float *v99; // r11
  int v100; // r3
  double v101; // fp0
  __int64 start; // r11
  int v103; // r4
  int v104; // r30
  int v105; // r3
  int v106; // r5
  idAFConstraint *v107; // r10
  int v108; // r9
  int v109; // r8
  int v110; // r7
  double v111; // fp0
  float *v112; // r11
  float *v113; // r6
  double v114; // fp5
  double v115; // fp3
  double v116; // fp1
  double v117; // fp12
  double v118; // fp10
  idAFBody *v119; // r11
  double v120; // fp9
  float *v121; // r29
  float *v122; // r11
  double v123; // fp3
  double v124; // fp1
  double v125; // fp12
  double v126; // fp9
  double v127; // fp8
  int v128; // r29
  int v129; // r30
  int v130; // r10
  int v131; // r11
  idAFBody *v132; // r8
  float *v133; // r11
  _DWORD v134[20]; // [sp+0h] [-280h]
  float v135[52]; // [sp+50h] [-230h] BYREF
  _DWORD back_chain[20]; // [sp+120h] [-160h]
  int num; // [sp+170h] [-110h] BYREF
  idVecX v138; // [sp+178h] [-108h] BYREF
  idVecX v139; // [sp+188h] [-F8h] BYREF
  idVecX v140; // [sp+198h] [-E8h] BYREF
  idVecX v141[2]; // [sp+1A8h] [-D8h] BYREF
  idMatX v142; // [sp+1C0h] [-C0h] BYREF
  idSpatialMat v143; // [sp+1D0h] [-B0h] BYREF
  double v144; // [sp+1E8h] [-98h] BYREF

  v4 = 0;
  v5 = 0;
  num = this->auxiliaryConstraints.num;
  if ( num <= 0 )
    return;
  v6 = 0;
  do
  {
    v7 = this->auxiliaryConstraints.list[v6];
    ++v5;
    ++v6;
    v4 += v7->J1.numRows;
  }
  while ( v5 < num );
  if ( v4 == 0 )
    return;
  num = this->bodies.num;
  ((void (*)(void))RtlCheckStack12)();
  num = v8;
  *(_DWORD *)((char *)back_chain + v9) = back_chain[0];
  tree = (idAFTree *)((int (*)(void))RtlCheckStack12)();
  num = v12;
  v13 = 0;
  *(_DWORD *)((char *)back_chain + v14) = back_chain[0];
  v16 = v12 <= 0;
  p_num = &num;
  if ( !v16 )
  {
    v17 = 0;
    do
    {
      ++v13;
      v18 = this->bodies.list[v17++];
      v18->response = v10;
      v10 += 8 * v4;
      v18->responseIndex = p_num;
      p_num += v4;
      v18->numResponses = 0;
      v18->maxAuxiliaryIndex = 0;
      tree = (idAFTree *)this->bodies.num;
    }
    while ( v13 < (int)tree );
  }
  if ( af_useSymmetry.valueInteger != 0 )
  {
    v19 = 0;
    v20 = 0;
    if ( this->auxiliaryConstraints.num > 0 )
    {
      v21 = 0;
      do
      {
        v22 = 0;
        v23 = this->auxiliaryConstraints.list[v21];
        if ( v23->J1.numRows > 0 )
        {
          do
          {
            body1 = v23->body1;
            if ( v19 > body1->maxAuxiliaryIndex )
              body1->maxAuxiliaryIndex = v19;
            body2 = v23->body2;
            if ( body2 != nullptr && v19 > body2->maxAuxiliaryIndex )
              body2->maxAuxiliaryIndex = v19;
            ++v22;
            ++v19;
          }
          while ( v22 < v23->J1.numRows );
        }
        ++v20;
        ++v21;
      }
      while ( v20 < this->auxiliaryConstraints.num );
    }
    v26 = 0;
    if ( this->trees.num > 0 )
    {
      v27 = 0;
      do
      {
        idAFTree::SetMaxSubTreeAuxiliaryIndex(this: this->trees.list[v27]);
        ++v26;
        ++v27;
      }
      while ( v26 < this->trees.num );
    }
  }
  v28 = 0;
  v29 = 0;
  if ( this->auxiliaryConstraints.num > 0 )
  {
    v30 = 0;
    do
    {
      v31 = 0;
      v32 = this->auxiliaryConstraints.list[v30];
      if ( v32->J1.numRows > 0 )
      {
        do
        {
          idAFTree::Response(this: v32->body1->tree, constraint: v32, row: v31, auxiliaryIndex: v28);
          v33 = v32->body2;
          if ( v33 != nullptr )
          {
            tree = v33->tree;
            if ( tree != v32->body1->tree )
              idAFTree::Response(this: tree, constraint: v32, row: v31, auxiliaryIndex: v28);
          }
          ++v31;
          ++v28;
        }
        while ( v31 < v32->J1.numRows );
      }
      ++v29;
      ++v30;
    }
    while ( v29 < this->auxiliaryConstraints.num );
  }
  memset(&v142, 0, sizeof(v142));
  ((void (__fastcall *)(idAFTree *))RtlCheckStack12)(a1: tree);
  *(_DWORD *)((char *)back_chain + v34) = back_chain[0];
  idMatX::SetDataCacheLines(
    this: &v142,
    rows: v4,
    columns: v35,
    data: (float *)(((unsigned int)&v144 + 7) & 0xFFFFFF80),
    clear: true);
  memset(&v143, 0, sizeof(v143));
  v134[0] = back_chain[0];
  idSpatialMat::SetData(this: &v143, rows: 6, columns: 6, data: v135);
  v36 = 0;
  v37 = 0;
  if ( this->auxiliaryConstraints.num > 0 )
  {
    v38 = 0;
    do
    {
      v39 = this->auxiliaryConstraints.list[v38];
      p_J1 = &v39->J1;
      idSpatialMat::Multiply(this: &v39->J1, dst: &v143, a: &v39->body1->inverseWorldSpatialInertia);
      v41 = 0;
      if ( v39->J1.numRows > 0 )
      {
        v42 = 0;
        v43 = 0;
        v44 = 4 * v36;
        do
        {
          if ( af_useSymmetry.valueInteger != 0 )
            v45 = v41 + v36 + 1;
          else
            v45 = v4;
          numResponses = v39->body1->numResponses;
          if ( numResponses >= v45 )
            numResponses = v45;
          MultiplyJauxMK(
            row: &v142.mat[(v41 + v36) * v142.numColumns],
            rowLength: numResponses,
            jaux: &v143.mat[v43],
            response: v39->body1->response,
            index: v39->body1->responseIndex);
          ++v41;
          v43 += 8;
          *(float *)(v44 + v47) = (float)(v39->e.p[v42++] * (float)((float)1.0 / (float)timeStep))
                                + *(float *)(v44 + v47);
          v44 += 4;
        }
        while ( v41 < p_J1->numRows );
      }
      v48 = v39->body2;
      if ( v48 != nullptr )
      {
        idSpatialMat::Multiply(this: &v39->J2, dst: &v143, a: &v48->inverseWorldSpatialInertia);
        v49 = 0;
        if ( v39->J2.numRows > 0 )
        {
          v50 = 0;
          do
          {
            if ( af_useSymmetry.valueInteger != 0 )
              v51 = v49 + v36 + 1;
            else
              v51 = v4;
            v52 = v39->body2->numResponses;
            if ( v52 >= v51 )
              v52 = v51;
            MultiplyAddJauxMK(
              row: &v142.mat[(v49 + v36) * v142.numColumns],
              rowLength: v52,
              jaux: &v143.mat[v50],
              response: v39->body2->response,
              index: v39->body2->responseIndex);
            ++v49;
            v50 += 8;
          }
          while ( v49 < v39->J2.numRows );
        }
      }
      ++v37;
      ++v38;
      v36 += p_J1->numRows;
    }
    while ( v37 < this->auxiliaryConstraints.num );
  }
  if ( af_useSymmetry.valueInteger != 0 )
    idMatX::CopyLowerToUpperTriangle(this: &v142);
  v53 = 0;
  if ( this->bodies.num > 0 )
  {
    v54 = 0;
    do
    {
      ++v53;
      v55 = this->bodies.list[v54];
      num = (int)&v55->current.spatialVelocity;
      p = v55->totalForce.p;
      mat = v55->inverseWorldSpatialInertia.mat;
      v58 = v55->acceleration.p;
      *v58 = *p * *mat;
      v59 = mat[9];
      num = (int)v58;
      v58[1] = (float)v59 * p[1];
      v58[2] = mat[18] * p[2];
      v58[3] = (float)(mat[29] * p[5]) + (float)((float)(mat[28] * p[4]) + (float)(mat[27] * p[3]));
      v58[4] = (float)(mat[37] * p[5]) + (float)((float)(mat[36] * p[4]) + (float)(mat[35] * p[3]));
      v60 = (float)((float)(mat[45] * p[5]) + (float)((float)(mat[44] * p[4]) + (float)(mat[43] * p[3])));
      v58[5] = (float)(mat[45] * p[5]) + (float)((float)(mat[44] * p[4]) + (float)(mat[43] * p[3]));
      v61 = v58[2];
      v62 = *v58;
      v63 = v58[1];
      v64 = v58[4];
      v65 = (float)(v55->current.spatialVelocity.p[2] * (float)((float)1.0 / (float)timeStep));
      v66 = (float)(v55->current.spatialVelocity.p[1] * (float)((float)1.0 / (float)timeStep));
      v67 = (float)(v55->current.spatialVelocity.p[0] * (float)((float)1.0 / (float)timeStep));
      v68 = (float)(v55->current.spatialVelocity.p[4] * (float)((float)1.0 / (float)timeStep));
      v69 = (float)(v55->current.spatialVelocity.p[5] * (float)((float)1.0 / (float)timeStep));
      v58[3] = v58[3] + (float)(v55->current.spatialVelocity.p[3] * (float)((float)1.0 / (float)timeStep));
      v58[2] = (float)v65 + (float)v61;
      v58[1] = (float)v66 + (float)v63;
      *v58 = (float)v62 + (float)v67;
      v58[4] = (float)v64 + (float)v68;
      v58[5] = (float)v69 + (float)v60;
      ++v54;
    }
    while ( v53 < this->bodies.num );
  }
  memset(&v138, 0, sizeof(v138));
  memset(v141, 0, 12);
  memset(&v140, 0, sizeof(v140));
  memset(&v139, 0, sizeof(v139));
  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)v134 + v70) = v134[0];
  idVecX::SetData(this: &v138, length: v4, data: v135);
  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)v134 + v71) = v134[0];
  idVecX::SetData(this: v141, length: v4, data: v135);
  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)v134 + v72) = v134[0];
  idVecX::SetData(this: &v140, length: v4, data: v135);
  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)v134 + v73) = v134[0];
  idVecX::SetData(this: &v139, length: v4, data: v135);
  ((void (*)(void))RtlCheckStack12)();
  *(_DWORD *)((char *)v134 + v74) = v134[0];
  ((void (*)(void))RtlCheckStack12)();
  v75 = 0;
  v76 = this->auxiliaryConstraints.num;
  v77 = 0;
  *(_DWORD *)((char *)v134 + v78) = v134[0];
  num = v76;
  if ( v76 > 0 )
  {
    list = this->auxiliaryConstraints.list;
    v80 = 0;
    do
    {
      ++v77;
      list[v80]->firstIndex = v75;
      list = this->auxiliaryConstraints.list;
      num = this->auxiliaryConstraints.num;
      v76 = num;
      v81 = list[v80++];
      v75 += v81->J1.numRows;
    }
    while ( v77 < num );
  }
  num = v76;
  v82 = 0;
  v83 = 0;
  if ( v76 <= 0 )
  {
LABEL_70:
    v85 = &timer_lcp;
    timer_lcp.state = TS_STARTED;
    LODWORD(v98) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    timer_lcp.start = v98;
    if ( this->lcp->Solve(
           this: this->lcp,
           a2: &v142,
           a3: &v139,
           a4: &v138,
           a5: v141,
           a6: &v140,
           a7: (const int *)v135,
           a8: v135) )
    {
      goto _LN418;
    }
    if ( v139.p != nullptr )
    {
      v99 = idVecX::tempPtr;
      if ( v139.p >= idVecX::tempPtr && v139.p < idVecX::tempPtr + 1024 || v139.alloced == -1 )
        goto _M258723;
      idMem::Free(this: &mem, ptr: v139.p, align: ALIGN_16);
    }
    v99 = idVecX::tempPtr;
_M258723:
    if ( v140.p != nullptr && (v140.p < v99 || v140.p >= v99 + 1024) && v140.alloced != -1 )
    {
      idMem::Free(this: &mem, ptr: v140.p, align: ALIGN_16);
      v99 = idVecX::tempPtr;
    }
    if ( v141[0].p != nullptr && (v141[0].p < v99 || v141[0].p >= v99 + 1024) && v141[0].alloced != -1 )
    {
      idMem::Free(this: &mem, ptr: v141[0].p, align: ALIGN_16);
      v99 = idVecX::tempPtr;
    }
    if ( v138.p != nullptr && (v138.p < v99 || v138.p >= v99 + 1024) && v138.alloced != -1 )
      idMem::Free(this: &mem, ptr: v138.p, align: ALIGN_16);
    if ( v143.mat != nullptr && v143.allocatedRows > 0 )
      idMem::Free(this: &mem, ptr: v143.mat, align: ALIGN_16);
    goto LABEL_139;
  }
  v84 = 0;
  while ( 1 )
  {
    v85 = nullptr;
    v86 = this->auxiliaryConstraints.list[v84];
    if ( v86->J1.numRows > 0 )
      break;
LABEL_69:
    ++v83;
    ++v84;
    if ( v83 >= this->auxiliaryConstraints.num )
      goto LABEL_70;
  }
  v87 = v82;
  v88 = 0;
  v89 = 0;
  boxIndex = v86->boxIndex;
  while ( 1 )
  {
    v91 = &v86->J1.mat[v89];
    v92 = v86->body1->acceleration.p;
    v138.p[v87] = (float)(*v92 * *v91)
                + (float)((float)(v92[1] * v91[1])
                        + (float)((float)(v92[2] * v91[2])
                                + (float)((float)(v92[3] * v91[3])
                                        + (float)((float)(v92[5] * v91[5]) + (float)(v92[4] * v91[4])))));
    v138.p[v87] = (float)(v86->c1.p[v88] * (float)((float)1.0 / (float)timeStep)) + v138.p[v87];
    v93 = v86->body2;
    if ( v93 != nullptr )
    {
      v94 = v93->acceleration.p;
      v95 = &v86->J2.mat[v89];
      v138.p[v87] = (float)((float)(*v94 * *v95)
                          + (float)((float)(v94[1] * v95[1])
                                  + (float)((float)(v94[2] * v95[2])
                                          + (float)((float)(v94[3] * v95[3])
                                                  + (float)((float)(v94[5] * v95[5]) + (float)(v94[4] * v95[4]))))))
                  + v138.p[v87];
      v138.p[v87] = (float)(v86->c2.p[v88] * (float)((float)1.0 / (float)timeStep)) + v138.p[v87];
    }
    v138.p[v87] = -v138.p[v87];
    v141[0].p[v87] = v86->lo.p[v88];
    v140.p[v87] = v86->hi.p[v88];
    v96 = boxIndex[v88];
    if ( v96 < 0 )
    {
      v135[v87] = NAN;
      v135[v87] = 0.0;
      goto LABEL_68;
    }
    boxConstraint = v86->boxConstraint;
    if ( (*(_BYTE *)&boxConstraint->fl & 0x10) != 0 )
      break;
    LODWORD(v135[v87]) = boxConstraint->firstIndex + v96;
    v135[v87] = *(float *)&boxIndex[v88 + 6];
LABEL_68:
    v85 = (idTimer *)((char *)v85 + 1);
    v89 += 8;
    ++v88;
    ++v82;
    ++v87;
    if ( (int)v85 >= v86->J1.numRows )
      goto LABEL_69;
  }
  idLib::Error(fmt: "cannot reference primary constraints for the box index");
_LN418:
  v100 = (unsigned __int64)Sys_GetClockTicks() >> 32;
  start = v85->start;
  v101 = (double)idTimer::base;
  LODWORD(start) = v100 + HIDWORD(start) - start;
  v85->clockTicks = start;
  if ( (float)v101 < 0.0 )
  {
    idTimer::InitBaseClockTicks(this: v85);
    start = v85->clockTicks;
  }
  HIDWORD(start) = idTimer::base;
  if ( (int)start > (int)idTimer::base )
  {
    LODWORD(start) = start - idTimer::base;
    v85->clockTicks = start;
  }
  v103 = 0;
  v85->state = TS_STOPPED;
  v104 = 0;
  if ( this->auxiliaryConstraints.num > 0 )
  {
    v105 = 0;
    do
    {
      v106 = 0;
      v107 = this->auxiliaryConstraints.list[v105];
      if ( v107->J1.numRows > 0 )
      {
        v108 = 0;
        v109 = 0;
        v110 = v103;
        do
        {
          v111 = v139.p[v110];
          v107->lm.p[v109] = v139.p[v110];
          v112 = &v107->J1.mat[v108];
          v113 = v107->body1->auxForce.p;
          v114 = (float)((float)((float)v111 * *v112) + *v113);
          v115 = (float)((float)(v112[1] * (float)v111) + v113[1]);
          v116 = (float)((float)(v112[2] * (float)v111) + v113[2]);
          v117 = (float)((float)(v112[3] * (float)v111) + v113[3]);
          v118 = (float)((float)(v112[4] * (float)v111) + v113[4]);
          v120 = (float)((float)(v112[5] * (float)v111) + v113[5]);
          v119 = v107->body2;
          *v113 = v114;
          v113[1] = v115;
          v113[2] = v116;
          v113[3] = v117;
          v113[4] = v118;
          v113[5] = v120;
          if ( v119 != nullptr )
          {
            v121 = v119->auxForce.p;
            v122 = &v107->J2.mat[v108];
            v123 = (float)((float)(v122[1] * (float)v111) + v121[1]);
            v124 = (float)((float)(v122[2] * (float)v111) + v121[2]);
            v125 = (float)((float)(v122[3] * (float)v111) + v121[3]);
            v126 = (float)((float)(v122[4] * (float)v111) + v121[4]);
            v127 = (float)((float)(v122[5] * (float)v111) + v121[5]);
            *v121 = (float)(*v122 * (float)v111) + *v121;
            v121[1] = v123;
            v121[2] = v124;
            v121[3] = v125;
            v121[4] = v126;
            v121[5] = v127;
          }
          ++v106;
          ++v109;
          v108 += 8;
          ++v103;
          ++v110;
        }
        while ( v106 < v107->J1.numRows );
      }
      ++v104;
      ++v105;
    }
    while ( v104 < this->auxiliaryConstraints.num );
  }
  v128 = 0;
  if ( this->trees.num > 0 )
  {
    v129 = 0;
    do
    {
      idAFTree::CalculateForces(this: this->trees.list[v129], timeStep);
      ++v128;
      ++v129;
    }
    while ( v128 < this->trees.num );
  }
  v130 = 0;
  if ( this->bodies.num > 0 )
  {
    v131 = 0;
    do
    {
      ++v130;
      v132 = this->bodies.list[v131++];
      v132->responseIndex = nullptr;
      v132->response = nullptr;
    }
    while ( v130 < this->bodies.num );
  }
  if ( v139.p != nullptr )
  {
    v133 = idVecX::tempPtr;
    if ( (v139.p < idVecX::tempPtr || v139.p >= idVecX::tempPtr + 1024) && v139.alloced != -1 )
    {
      idMem::Free(this: &mem, ptr: v139.p, align: ALIGN_16);
      goto LABEL_120;
    }
  }
  else
  {
LABEL_120:
    v133 = idVecX::tempPtr;
  }
  if ( v140.p != nullptr && (v140.p < v133 || v140.p >= v133 + 1024) && v140.alloced != -1 )
  {
    idMem::Free(this: &mem, ptr: v140.p, align: ALIGN_16);
    v133 = idVecX::tempPtr;
  }
  if ( v141[0].p != nullptr && (v141[0].p < v133 || v141[0].p >= v133 + 1024) && v141[0].alloced != -1 )
  {
    idMem::Free(this: &mem, ptr: v141[0].p, align: ALIGN_16);
    v133 = idVecX::tempPtr;
  }
  if ( v138.p != nullptr && (v138.p < v133 || v138.p >= v133 + 1024) && v138.alloced != -1 )
    idMem::Free(this: &mem, ptr: v138.p, align: ALIGN_16);
  if ( v143.mat != nullptr && v143.allocatedRows > 0 )
    idMem::Free(this: &mem, ptr: v143.mat, align: ALIGN_16);
LABEL_139:
  if ( v142.mat != nullptr && v142.alloced != -1 )
    idMem::Free(this: &mem, ptr: v142.mat, align: ALIGN_16);
}


// ========================================================================
// $LN383
// EA  : 0x8273FA10
// RVA : 0x0073FA10
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _LN383()
{
  int v0; // r12

  idMatX::~idMatX(this: (idMatX *)(v0 - 352 + 160));
}


// ========================================================================
// __unwind$258162
// EA  : 0x8273FA38
// RVA : 0x0073FA38
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_258162()
{
  int v0; // r12

  idSpatialMat::~idSpatialMat(this: (idSpatialMat *)(v0 - 352 + 176));
}


// ========================================================================
// __unwind$258163
// EA  : 0x8273FA60
// RVA : 0x0073FA60
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_258163()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 352 + 88));
}


// ========================================================================
// __unwind$258164
// EA  : 0x8273FA88
// RVA : 0x0073FA88
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_258164()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 352 + 136));
}


// ========================================================================
// __unwind$258165
// EA  : 0x8273FAB0
// RVA : 0x0073FAB0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_258165()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 352 + 120));
}


// ========================================================================
// __unwind$258166
// EA  : 0x8273FAD8
// RVA : 0x0073FAD8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_258166()
{
  int v0; // r12

  idVecX::~idVecX(this: (idVecX *)(v0 - 352 + 104));
}


// ========================================================================
// ?CollisionImpulse@idPhysics_AF@@AAAXPAVidAFBody@@AAUtrace_t@@M@Z
// EA  : 0x8273FB00
// RVA : 0x0073FB00
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::CollisionImpulse(idPhysics_AF *this, idAFBody *body, trace_t *collision, double timeStep)
{
  idVec3 *p_point; // r26
  int physicsId; // r3
  float *clipModel; // r9
  double v10; // fp3
  double v11; // fp30
  double v12; // fp29
  double v13; // fp31
  double v14; // fp10
  double v15; // fp9
  idPhysics_AF *PhysicsForId; // r3
  idPhysics_AF *v17; // r28
  double y; // fp0
  double x; // fp13
  double z; // fp12
  double v21; // fp3
  double v22; // fp2
  double valueFloat; // fp28
  float *v24; // r11
  const idMat3 *v25; // r31
  double v26; // fp13
  double v27; // fp12
  double v28; // fp11
  double v29; // fp10
  double v30; // fp9
  double v31; // fp8
  double v32; // fp7
  double v33; // fp6
  idMat3 *v34; // r3
  double v35; // fp0
  double v36; // fp13
  double v37; // fp12
  idVec3 *p_normal; // r11
  double v39; // fp7
  double v40; // fp5
  double v41; // fp6
  double v42; // fp8
  double v43; // fp2
  collide_t v44; // r3
  idPhysicsCallbacks *callbacks; // r3
  double v46; // fp10
  double v47; // fp9
  float v48; // [sp+50h] [-150h] BYREF
  float v49; // [sp+54h] [-14Ch]
  float v50; // [sp+58h] [-148h]
  idMat3 v51; // [sp+60h] [-140h] BYREF
  float v52[6]; // [sp+88h] [-118h] BYREF
  float v53; // [sp+A0h] [-100h] BYREF
  float v54; // [sp+A4h] [-FCh]
  float v55; // [sp+A8h] [-F8h]
  float v56; // [sp+ACh] [-F4h]
  float v57; // [sp+B0h] [-F0h]
  float v58; // [sp+B4h] [-ECh]
  float v59; // [sp+B8h] [-E8h]
  float v60; // [sp+BCh] [-E4h]
  float v61; // [sp+C0h] [-E0h]
  float v62; // [sp+C4h] [-DCh]
  float v63; // [sp+C8h] [-D8h]
  float v64; // [sp+CCh] [-D4h]
  float v65; // [sp+D0h] [-D0h]
  float v66; // [sp+D4h] [-CCh]
  float v67; // [sp+D8h] [-C8h]
  float v68; // [sp+DCh] [-C4h]
  idMat3 v69[3]; // [sp+E0h] [-C0h] BYREF

  if ( collision->fraction < 1.0 )
  {
    p_point = &collision->c.point;
    physicsId = collision->c.physicsId;
    collision->c.selfId = body->clipModel->bodyId;
    clipModel = (float *)body->clipModel;
    v10 = body->current.spatialVelocity.p[2];
    v11 = (float)(collision->c.point.y
                - (float)(clipModel[9]
                        + (float)((float)(clipModel[18] * body->centerOfMass.z)
                                + (float)((float)(clipModel[12] * body->centerOfMass.x)
                                        + (float)(clipModel[15] * body->centerOfMass.y)))));
    v12 = (float)(collision->c.point.z
                - (float)(clipModel[10]
                        + (float)((float)(clipModel[19] * body->centerOfMass.z)
                                + (float)((float)(clipModel[13] * body->centerOfMass.x)
                                        + (float)(clipModel[16] * body->centerOfMass.y)))));
    v13 = (float)(collision->c.point.x
                - (float)((float)((float)(body->centerOfMass.x * clipModel[11])
                                + (float)((float)(clipModel[14] * body->centerOfMass.y)
                                        + (float)(clipModel[17] * body->centerOfMass.z)))
                        + clipModel[8]));
    v14 = (float)((float)(body->current.spatialVelocity.p[3]
                        * (float)(collision->c.point.y
                                - (float)(clipModel[9]
                                        + (float)((float)(clipModel[18] * body->centerOfMass.z)
                                                + (float)((float)(clipModel[12] * body->centerOfMass.x)
                                                        + (float)(clipModel[15] * body->centerOfMass.y))))))
                - (float)(body->current.spatialVelocity.p[4]
                        * (float)(collision->c.point.x
                                - (float)((float)((float)(body->centerOfMass.x * clipModel[11])
                                                + (float)((float)(clipModel[14] * body->centerOfMass.y)
                                                        + (float)(clipModel[17] * body->centerOfMass.z)))
                                        + clipModel[8]))));
    v15 = (float)(body->current.spatialVelocity.p[1]
                + (float)((float)(body->current.spatialVelocity.p[5]
                                * (float)(collision->c.point.x
                                        - (float)((float)((float)(body->centerOfMass.x * clipModel[11])
                                                        + (float)((float)(clipModel[14] * body->centerOfMass.y)
                                                                + (float)(clipModel[17] * body->centerOfMass.z)))
                                                + clipModel[8])))
                        - (float)(body->current.spatialVelocity.p[3]
                                * (float)(collision->c.point.z
                                        - (float)(clipModel[10]
                                                + (float)((float)(clipModel[19] * body->centerOfMass.z)
                                                        + (float)((float)(clipModel[13] * body->centerOfMass.x)
                                                                + (float)(clipModel[16] * body->centerOfMass.y))))))));
    v48 = body->current.spatialVelocity.p[0]
        + (float)((float)(body->current.spatialVelocity.p[4]
                        * (float)(collision->c.point.z
                                - (float)(clipModel[10]
                                        + (float)((float)(clipModel[19] * body->centerOfMass.z)
                                                + (float)((float)(clipModel[13] * body->centerOfMass.x)
                                                        + (float)(clipModel[16] * body->centerOfMass.y))))))
                - (float)(body->current.spatialVelocity.p[5]
                        * (float)(collision->c.point.y
                                - (float)(clipModel[9]
                                        + (float)((float)(clipModel[18] * body->centerOfMass.z)
                                                + (float)((float)(clipModel[12] * body->centerOfMass.x)
                                                        + (float)(clipModel[15] * body->centerOfMass.y)))))));
    v49 = v15;
    v50 = (float)v10 + (float)v14;
    PhysicsForId = (idPhysics_AF *)idPhysics::GetPhysicsForId(physicsId_: physicsId);
    v17 = PhysicsForId;
    if ( PhysicsForId != nullptr && PhysicsForId != this )
    {
      PhysicsForId->GetImpactInfo(this: PhysicsForId, a2: collision->c.bodyId, a3: p_point, a4: (impactInfo_t *)&v53);
      y = collision->c.normal.y;
      x = collision->c.normal.x;
      z = collision->c.normal.z;
      v21 = (float)((float)(collision->c.normal.x * (float)(v48 - v66))
                  + (float)((float)(v49 - v67) * collision->c.normal.y));
      v48 = v48 - v66;
      v49 = v49 - v67;
      v22 = (float)((float)((float)(v50 - v68) * (float)z) + (float)v21);
      v50 = v50 - v68;
      if ( v22 > 0.0 )
      {
        v48 = x;
        v49 = y;
        v50 = z;
      }
    }
    valueFloat = 1.0;
    if ( (collision->c.flags & 8) != 0 )
      valueFloat = af_collisionReductionMass.valueFloat;
    v24 = (float *)body->clipModel;
    v25 = (const idMat3 *)(v24 + 11);
    v26 = v24[16];
    v27 = v24[13];
    v28 = v24[18];
    v29 = v24[15];
    v30 = v24[12];
    v31 = v24[17];
    v32 = v24[14];
    v33 = v24[11];
    v51.mat[2].z = v24[19];
    v51.mat[2].y = v26;
    v51.mat[2].x = v27;
    v51.mat[1].z = v28;
    v51.mat[1].y = v29;
    v51.mat[1].x = v30;
    v51.mat[0].z = v31;
    v51.mat[0].y = v32;
    v51.mat[0].x = v33;
    v34 = idMat3::operator*(this: v69, result: &v51, a: &body->inverseInertiaTensor);
    idMat3::operator*(this: &v51, result: v34, a: v25);
    v35 = collision->c.normal.x;
    v36 = collision->c.normal.y;
    v37 = collision->c.normal.z;
    p_normal = &collision->c.normal;
    v39 = (float)((float)((float)((float)(v51.mat[1].y
                                        * (float)((float)((float)v12 * collision->c.normal.x)
                                                - (float)(collision->c.normal.z * (float)v13)))
                                + (float)((float)(v51.mat[0].y
                                                * (float)((float)(collision->c.normal.z * (float)v11)
                                                        - (float)(collision->c.normal.y * (float)v12)))
                                        + (float)(v51.mat[2].y
                                                * (float)((float)(collision->c.normal.y * (float)v13)
                                                        - (float)((float)v11 * collision->c.normal.x)))))
                        * (float)v12)
                - (float)((float)((float)(v51.mat[1].z
                                        * (float)((float)((float)v12 * collision->c.normal.x)
                                                - (float)(collision->c.normal.z * (float)v13)))
                                + (float)((float)(v51.mat[0].z
                                                * (float)((float)(collision->c.normal.z * (float)v11)
                                                        - (float)(collision->c.normal.y * (float)v12)))
                                        + (float)(v51.mat[2].z
                                                * (float)((float)(collision->c.normal.y * (float)v13)
                                                        - (float)((float)v11 * collision->c.normal.x)))))
                        * (float)v11));
    v40 = (float)((float)((float)v11
                        * (float)((float)(v51.mat[1].x
                                        * (float)((float)((float)v12 * collision->c.normal.x)
                                                - (float)(collision->c.normal.z * (float)v13)))
                                + (float)((float)(v51.mat[0].x
                                                * (float)((float)(collision->c.normal.z * (float)v11)
                                                        - (float)(collision->c.normal.y * (float)v12)))
                                        + (float)(v51.mat[2].x
                                                * (float)((float)(collision->c.normal.y * (float)v13)
                                                        - (float)((float)v11 * collision->c.normal.x))))))
                - (float)((float)((float)(v51.mat[1].y
                                        * (float)((float)((float)v12 * collision->c.normal.x)
                                                - (float)(collision->c.normal.z * (float)v13)))
                                + (float)((float)(v51.mat[0].y
                                                * (float)((float)(collision->c.normal.z * (float)v11)
                                                        - (float)(collision->c.normal.y * (float)v12)))
                                        + (float)(v51.mat[2].y
                                                * (float)((float)(collision->c.normal.y * (float)v13)
                                                        - (float)((float)v11 * collision->c.normal.x)))))
                        * (float)v13));
    v41 = -(float)((float)((float)(v50 * collision->c.normal.z)
                         + (float)((float)(collision->c.normal.x * v48) + (float)(v49 * collision->c.normal.y)))
                 * (float)(body->bouncyness + (float)1.0));
    v42 = (float)((float)(body->invMass * (float)valueFloat)
                + (float)((float)((float)v40 * collision->c.normal.z)
                        + (float)((float)(collision->c.normal.x * (float)v39)
                                + (float)((float)((float)((float)((float)(v51.mat[1].z
                                                                        * (float)((float)((float)v12
                                                                                        * collision->c.normal.x)
                                                                                - (float)(collision->c.normal.z
                                                                                        * (float)v13)))
                                                                + (float)((float)(v51.mat[0].z
                                                                                * (float)((float)(collision->c.normal.z
                                                                                                * (float)v11)
                                                                                        - (float)(collision->c.normal.y
                                                                                                * (float)v12)))
                                                                        + (float)(v51.mat[2].z
                                                                                * (float)((float)(collision->c.normal.y
                                                                                                * (float)v13)
                                                                                        - (float)((float)v11
                                                                                                * collision->c.normal.x)))))
                                                        * (float)v13)
                                                - (float)((float)v12
                                                        * (float)((float)(v51.mat[1].x
                                                                        * (float)((float)((float)v12
                                                                                        * collision->c.normal.x)
                                                                                - (float)(collision->c.normal.z
                                                                                        * (float)v13)))
                                                                + (float)((float)(v51.mat[0].x
                                                                                * (float)((float)(collision->c.normal.z
                                                                                                * (float)v11)
                                                                                        - (float)(collision->c.normal.y
                                                                                                * (float)v12)))
                                                                        + (float)(v51.mat[2].x
                                                                                * (float)((float)(collision->c.normal.y
                                                                                                * (float)v13)
                                                                                        - (float)((float)v11
                                                                                                * collision->c.normal.x)))))))
                                        * collision->c.normal.y))));
    if ( v17 != nullptr && __fabs(v53) >= idMath::FLT_SMALLEST_NON_DENORMAL )
    {
      v43 = (float)((float)((float)((float)(v55 * (float)((float)(p_normal->z * v64) - (float)(p_normal->y * v65)))
                                  + (float)((float)(v61 * (float)((float)(p_normal->y * v63) - (float)(v64 * (float)v35)))
                                          + (float)(v58 * (float)((float)(v65 * (float)v35) - (float)(p_normal->z * v63)))))
                          * v65)
                  - (float)((float)((float)(v56 * (float)((float)(p_normal->z * v64) - (float)(p_normal->y * v65)))
                                  + (float)((float)(v62 * (float)((float)(p_normal->y * v63) - (float)(v64 * (float)v35)))
                                          + (float)(v59 * (float)((float)(v65 * (float)v35) - (float)(p_normal->z * v63)))))
                          * v64));
      v42 = (float)((float)((float)(v53 * (float)valueFloat)
                          + (float)((float)((float)v35 * (float)v43)
                                  + (float)((float)((float)((float)((float)((float)(v56
                                                                                  * (float)((float)(p_normal->z * v64)
                                                                                          - (float)(p_normal->y * v65)))
                                                                          + (float)((float)(v62
                                                                                          * (float)((float)(p_normal->y * v63)
                                                                                                  - (float)(v64 * (float)v35)))
                                                                                  + (float)(v59
                                                                                          * (float)((float)(v65 * (float)v35)
                                                                                                  - (float)(p_normal->z * v63)))))
                                                                  * v63)
                                                          - (float)(v65
                                                                  * (float)((float)(v57
                                                                                  * (float)((float)(v65 * (float)v35)
                                                                                          - (float)(p_normal->z * v63)))
                                                                          + (float)((float)(v54
                                                                                          * (float)((float)(p_normal->z * v64)
                                                                                                  - (float)(p_normal->y * v65)))
                                                                                  + (float)(v60
                                                                                          * (float)((float)(p_normal->y * v63)
                                                                                                  - (float)(v64 * (float)v35)))))))
                                                  * collision->c.normal.y)
                                          + (float)((float)((float)(v64
                                                                  * (float)((float)(v57
                                                                                  * (float)((float)(v65 * (float)v35)
                                                                                          - (float)(p_normal->z * v63)))
                                                                          + (float)((float)(v54
                                                                                          * (float)((float)(p_normal->z * v64)
                                                                                                  - (float)(p_normal->y * v65)))
                                                                                  + (float)(v60
                                                                                          * (float)((float)(p_normal->y * v63)
                                                                                                  - (float)(v64 * (float)v35))))))
                                                          - (float)((float)((float)(v55
                                                                                  * (float)((float)(p_normal->z * v64)
                                                                                          - (float)(p_normal->y * v65)))
                                                                          + (float)((float)(v61
                                                                                          * (float)((float)(p_normal->y * v63)
                                                                                                  - (float)(v64 * (float)v35)))
                                                                                  + (float)(v58
                                                                                          * (float)((float)(v65 * (float)v35)
                                                                                                  - (float)(p_normal->z * v63)))))
                                                                  * v63))
                                                  * collision->c.normal.z))))
                  + (float)v42);
    }
    this->lastImpulse.x = collision->c.normal.x * (float)((float)v41 / (float)v42);
    this->lastImpulse.z = (float)v37 * (float)((float)v41 / (float)v42);
    this->lastImpulse.y = (float)v36 * (float)((float)v41 / (float)v42);
    v44 = this->callbacks->Collide(this: this->callbacks, a2: this->physicsId, a3: collision, a4: (const idVec3 *)&v48);
    if ( v44 != COLLIDE_IGNORE_COLLISION )
    {
      if ( v44 == COLLIDE_STOP_SIMULATION )
      {
        this->current.atRest = true;
        this->comeToRest = true;
      }
      else if ( v17 != nullptr && v17 != this )
      {
        callbacks = v17->callbacks;
        v46 = -this->lastImpulse.y;
        v47 = -this->lastImpulse.z;
        v52[0] = -this->lastImpulse.x;
        v52[1] = v46;
        v52[2] = v47;
        callbacks->ApplyImpulse(
          this: callbacks,
          a2: this->physicsId,
          a3: collision->c.bodyId,
          a4: p_point,
          a5: (const idVec3 *)v52);
      }
    }
  }
}


// ========================================================================
// ?IssueCollisionQueries@idPhysics_AF@@QAAXXZ
// EA  : 0x8273FFA0
// RVA : 0x0073FFA0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::IssueCollisionQueries(idPhysics_AF *this)
{
  int v2; // r21
  int v3; // r19
  idAFBody *v4; // r29
  int v5; // r26
  double v6; // fp31
  double v7; // fp30
  double v8; // fp29
  int v9; // r28
  int v10; // r27
  double v11; // fp28
  double v12; // fp27
  double v13; // fp26
  idPhysics_AF *PhysicsForId; // r3
  idVec3 *p_normal; // r11
  double v16; // fp0
  double timeStep; // fp12
  double v18; // fp9
  double v19; // fp6
  double v20; // fp5
  double v21; // fp30
  double v22; // fp29
  double v23; // fp28
  double v26; // fp7
  double v27; // fp7
  long double v28; // fp2
  double v29; // fp9
  double v30; // fp31
  long double v31; // fp2
  double v32; // fp5
  idVec3 *v33; // r10
  float *clipModel; // r11
  double x; // fp4
  double y; // fp3
  double z; // fp2
  idClip *clip; // r4
  float *v39; // r11
  double v40; // fp8
  double v41; // fp6
  int v42; // r29
  int v43; // r30
  const idMat3 *v44; // [sp+8h] [-218h]
  int v45; // [sp+Ch] [-214h]
  int v46; // [sp+10h] [-210h]
  bool v47; // [sp+17h] [-209h]
  const char *v48; // [sp+18h] [-208h]
  int v49; // [sp+1Ch] [-204h]
  int v50; // [sp+20h] [-200h]
  int v51; // [sp+24h] [-1FCh]
  int v52; // [sp+28h] [-1F8h]
  int v53; // [sp+2Ch] [-1F4h]
  int v54; // [sp+30h] [-1F0h]
  int v55; // [sp+34h] [-1ECh]
  int v56; // [sp+38h] [-1E8h]
  int v57; // [sp+3Ch] [-1E4h]
  int v58; // [sp+40h] [-1E0h]
  int v59; // [sp+44h] [-1DCh]
  int v60; // [sp+48h] [-1D8h]
  int v61; // [sp+4Ch] [-1D4h]
  int v62; // [sp+50h] [-1D0h]
  int v63; // [sp+58h] [-1C8h]
  int v64; // [sp+60h] [-1C0h]
  int v65; // [sp+68h] [-1B8h]
  int passEntityNum; // [sp+6Ch] [-1B4h]
  int v67; // [sp+70h] [-1B0h]
  int v68; // [sp+78h] [-1A8h]
  idVec3 v69; // [sp+80h] [-1A0h] BYREF
  float v70[4]; // [sp+90h] [-190h] BYREF
  idRotation v71; // [sp+A0h] [-180h] BYREF
  char v72; // [sp+E8h] [-138h] BYREF
  char v73; // [sp+F0h] [-130h] BYREF
  float v74; // [sp+124h] [-FCh]
  float v75; // [sp+128h] [-F8h]
  float v76; // [sp+12Ch] [-F4h]

  v2 = 0;
  if ( this->bodies.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->bodies.list[v3];
      if ( (unsigned __int8)idMat3::Compare(this: &v4->clipModel->axis, a: &mat3_zero) == 0 )
      {
        v5 = 0;
        v6 = (float)(this->current.auxVelocity.p[0] + v4->current.spatialVelocity.p[0]);
        v7 = (float)(this->current.auxVelocity.p[1] + v4->current.spatialVelocity.p[1]);
        v8 = (float)(this->current.auxVelocity.p[2] + v4->current.spatialVelocity.p[2]);
        if ( this->contacts.num > 0 )
        {
          v9 = 0;
          v10 = 0;
          do
          {
            if ( this->contactBodies.list[v10] == v2 )
            {
              v11 = 0.0;
              v12 = 0.0;
              v13 = 0.0;
              PhysicsForId = (idPhysics_AF *)idPhysics::GetPhysicsForId(physicsId_: this->contacts.list[v9].physicsId);
              if ( PhysicsForId != nullptr && PhysicsForId != this )
              {
                PhysicsForId->GetImpactInfo(
                  this: PhysicsForId,
                  a2: this->contacts.list[v9].bodyId,
                  a3: &this->contacts.list[v9].point,
                  a4: (impactInfo_t *)&v73);
                v11 = v74;
                v12 = v75;
                v13 = v76;
              }
              p_normal = &this->contacts.list[v9].normal;
              if ( (float)((float)(p_normal->x * (float)((float)v6 - (float)v11))
                         + (float)((float)(this->contacts.list[v9].normal.z * (float)((float)v8 - (float)v13))
                                 + (float)(this->contacts.list[v9].normal.y * (float)((float)v7 - (float)v12)))) < 0.0 )
              {
                v16 = (float)((float)((float)(p_normal->x * (float)((float)v6 - (float)v11))
                                    + (float)((float)(this->contacts.list[v9].normal.z * (float)((float)v8 - (float)v13))
                                            + (float)(this->contacts.list[v9].normal.y * (float)((float)v7 - (float)v12))))
                            * (float)1.0001);
                v6 = (float)((float)v6
                           - (float)(p_normal->x
                                   * (float)((float)((float)(p_normal->x * (float)((float)v6 - (float)v11))
                                                   + (float)((float)(this->contacts.list[v9].normal.z
                                                                   * (float)((float)v8 - (float)v13))
                                                           + (float)(this->contacts.list[v9].normal.y
                                                                   * (float)((float)v7 - (float)v12))))
                                           * (float)1.0001)));
                v7 = (float)((float)v7 - (float)(this->contacts.list[v9].normal.y * (float)v16));
                v8 = (float)((float)v8 - (float)(this->contacts.list[v9].normal.z * (float)v16));
              }
            }
            ++v5;
            ++v10;
            ++v9;
          }
          while ( v5 < this->contacts.num );
        }
        *(double *)&v28 = (float)(this->current.auxVelocity.p[4]
                                + (float)(v4->current.spatialVelocity.p[4] - this->current.pushVelocity.p[4]));
        timeStep = this->timeStep;
        v18 = (float)(this->current.auxVelocity.p[5]
                    + (float)(v4->current.spatialVelocity.p[5] - this->current.pushVelocity.p[5]));
        v19 = (float)((float)v8 - this->current.pushVelocity.p[2]);
        v20 = (float)(this->current.auxVelocity.p[3]
                    + (float)(v4->current.spatialVelocity.p[3] - this->current.pushVelocity.p[3]));
        v22 = (float)((float)((float)v7 - this->current.pushVelocity.p[1]) * this->timeStep);
        v21 = (float)((float)((float)v6 - this->current.pushVelocity.p[0]) * this->timeStep);
        v23 = (float)((float)v19 * this->timeStep);
        _FP11 = (float)((float)((float)((float)v20 * (float)v20)
                              + (float)((float)((float)v18 * (float)v18)
                                      + (float)((float)*(double *)&v28 * (float)*(double *)&v28)))
                      - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f8, f11, f2, f0 }
        v26 = __frsqrte(_FP8);
        v27 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26
                                                                                            * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v18 * (float)v18) + (float)((float)*(double *)&v28 * (float)*(double *)&v28))) * (float)0.5))
                                                                                    * (float)v26)
                                                                            - (float)1.5)
                                                            * (float)v26)
                                                    * (float)((float)((float)((float)v20 * (float)v20)
                                                                    + (float)((float)((float)v18 * (float)v18)
                                                                            + (float)((float)*(double *)&v28
                                                                                    * (float)*(double *)&v28)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v26
                                                                                    * (float)((float)((float)((float)v20 * (float)v20) + (float)((float)((float)v18 * (float)v18) + (float)((float)*(double *)&v28 * (float)*(double *)&v28)))
                                                                                            * (float)0.5))
                                                                            * (float)v26)
                                                                    - (float)1.5)
                                                    * (float)v26))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v26
                                                            * (float)((float)((float)((float)v20 * (float)v20)
                                                                            + (float)((float)((float)v18 * (float)v18)
                                                                                    + (float)((float)*(double *)&v28
                                                                                            * (float)*(double *)&v28)))
                                                                    * (float)0.5))
                                                    * (float)v26)
                                            - (float)1.5)
                            * (float)v26));
        *((double *)&v28 + 1) = (float)((float)((float)-(float)((float)((float)((float)v27
                                                                              * (float)((float)((float)((float)v20 * (float)v20)
                                                                                              + (float)((float)((float)v18 * (float)v18) + (float)((float)*(double *)&v28 * (float)*(double *)&v28)))
                                                                                      * (float)0.5))
                                                                      * (float)v27)
                                                              - (float)1.5)
                                              * (float)v27)
                                      * (float)((float)((float)v20 * (float)v20)
                                              + (float)((float)((float)v18 * (float)v18)
                                                      + (float)((float)*(double *)&v28 * (float)*(double *)&v28))));
        v70[2] = (float)v18
               * (float)((float)-(float)((float)((float)((float)v27
                                                       * (float)((float)((float)((float)v20 * (float)v20)
                                                                       + (float)((float)((float)v18 * (float)v18)
                                                                               + (float)((float)*(double *)&v28
                                                                                       * (float)*(double *)&v28)))
                                                               * (float)0.5))
                                               * (float)v27)
                                       - (float)1.5)
                       * (float)v27);
        v70[0] = (float)v20
               * (float)((float)-(float)((float)((float)((float)v27
                                                       * (float)((float)((float)((float)v20 * (float)v20)
                                                                       + (float)((float)((float)v18 * (float)v18)
                                                                               + (float)((float)*(double *)&v28
                                                                                       * (float)*(double *)&v28)))
                                                               * (float)0.5))
                                               * (float)v27)
                                       - (float)1.5)
                       * (float)v27);
        v70[1] = (float)*(double *)&v28
               * (float)((float)-(float)((float)((float)((float)v27
                                                       * (float)((float)((float)((float)v20 * (float)v20)
                                                                       + (float)((float)((float)v18 * (float)v18)
                                                                               + (float)((float)*(double *)&v28
                                                                                       * (float)*(double *)&v28)))
                                                               * (float)0.5))
                                               * (float)v27)
                                       - (float)1.5)
                       * (float)v27);
        v29 = (float)((float)((float)((float)-(float)((float)((float)((float)v27
                                                                    * (float)((float)((float)((float)v20 * (float)v20)
                                                                                    + (float)((float)((float)v18 * (float)v18)
                                                                                            + (float)((float)*(double *)&v28 * (float)*(double *)&v28)))
                                                                            * (float)0.5))
                                                            * (float)v27)
                                                    - (float)1.5)
                                    * (float)v27)
                            * (float)((float)((float)v20 * (float)v20)
                                    + (float)((float)((float)v18 * (float)v18)
                                            + (float)((float)*(double *)&v28 * (float)*(double *)&v28))))
                    * idMath::M_RAD2DEG);
        v30 = (float)((float)-v29 * (float)timeStep);
        if ( v30 >= 360.0 || v30 < 0.0 )
        {
          *(double *)&v28 = (float)((float)((float)-v29 * (float)timeStep) * (float)0.0027777778);
          v31 = floor(x: v28);
          v30 = (float)-(float)((float)((float)*(double *)&v31 * (float)360.0) - (float)v30);
        }
        v32 = v30;
        if ( v30 > 180.0 )
          v32 = (float)((float)v30 - (float)360.0);
        v33 = (idVec3 *)v70;
        if ( v32 == 0.0 )
          v33 = &vec3_up;
        clipModel = (float *)v4->clipModel;
        x = v33->x;
        y = v33->y;
        z = v33->z;
        passEntityNum = this->passEntityNum;
        v71.origin.x = clipModel[8];
        v71.origin.y = clipModel[9];
        v71.origin.z = clipModel[10];
        v71.axisValid = false;
        clip = this->clip;
        v71.axis.mat[2].x = mat3_identity.mat[2].x;
        v71.angle = v32;
        v71.axis.mat[2].z = mat3_identity.mat[2].z;
        v71.vec.x = x;
        v71.vec.y = y;
        v71.axis.mat[0].x = mat3_identity.mat[0].x;
        v71.vec.z = z;
        v71.axis.mat[0].y = mat3_identity.mat[0].y;
        v71.axis.mat[0].z = mat3_identity.mat[0].z;
        v71.axis.mat[1].x = mat3_identity.mat[1].x;
        v71.axis.mat[1].y = mat3_identity.mat[1].y;
        v71.axis.mat[1].z = mat3_identity.mat[1].z;
        v71.axis.mat[2].y = mat3_identity.mat[2].y;
        v39 = (float *)v4->clipModel;
        v40 = (float)(v39[9] + (float)v22);
        v41 = (float)(v39[8] + (float)v21);
        v69.z = v39[10] + (float)v23;
        v69.x = v41;
        v69.y = v40;
        v4->motionQuery.index = *(_QWORD *)&idClip::MotionContacts(
                                              this: (idClip *)&v72,
                                              result: clip,
                                              a3: nullptr,
                                              contacts: nullptr,
                                              start: &v4->clipModel->origin,
                                              end: &v69,
                                              rotation: &v71,
                                              depth: 2.0,
                                              clipModel: (const idClipModel *)v4->clipMask,
                                              startAxis: v44,
                                              clipMask: v45,
                                              passEntityNumber: v46,
                                              moveClipModel: v47,
                                              userName: v48,
                                              a15: v49,
                                              a16: v50,
                                              a17: v51,
                                              a18: v52,
                                              a19: v53,
                                              a20: v54,
                                              a21: v55,
                                              a22: v56,
                                              a23: v57,
                                              a24: v58,
                                              a25: v59,
                                              a26: v60,
                                              a27: v61,
                                              a28: v62,
                                              a29: v4->clipModel,
                                              a30: v63,
                                              a31: (int)(v39 + 11),
                                              a32: v64,
                                              a33: (const idBounds *)v4->clipMask,
                                              a34: v65,
                                              a35: passEntityNum,
                                              a36: v67,
                                              clipModel_0_3: true,
                                              a38: v68,
                                              startAxisa: (const idMat3 *)"w:\\tech5\\engine\\gamelib\\physics\\Physics_AF.cpp(1286) "
                                                              ": MotionContacts")->world;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->bodies.num );
  }
  v42 = 0;
  if ( this->constraints.num > 0 )
  {
    v43 = 0;
    do
    {
      this->constraints.list[v43]->IssueCollisionQueries(this: this->constraints.list[v43]);
      ++v42;
      ++v43;
    }
    while ( v42 < this->constraints.num );
  }
}


// ========================================================================
// ?GetBounds@idPhysics_AF@@UBAABVidBounds@@H@Z
// EA  : 0x827403F8
// RVA : 0x007403F8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_AF::GetBounds(idPhysics_AF *this, int id)
{
  int v4; // r28
  int v5; // r30
  idAFBody **list; // r8
  float *clipModel; // r10
  float *v8; // r9
  float *v9; // r11
  double v10; // fp6
  double v11; // fp9
  double v12; // fp2
  double v13; // fp0
  float *v14; // r11
  idMat3 *p_axis; // r4
  double v16; // fp12
  double v17; // fp11
  double v18; // fp9
  double v19; // fp8
  double v20; // fp7
  double v21; // fp6
  double v22; // fp5
  double v23; // fp4
  idVec3 v36; // [sp+50h] [-C0h] BYREF
  idBounds v37; // [sp+60h] [-B0h] BYREF
  idMat3 v38; // [sp+80h] [-90h] BYREF
  idMat3 v39; // [sp+B0h] [-60h] BYREF

  if ( (_S13_13 & 1) == 0 )
    _S13_13 |= 1u;
  if ( id >= 0 && id < this->bodies.num )
    return &this->bodies.list[id]->clipModel->bounds;
  if ( this->bodies.num != 0 )
  {
    v4 = 1;
    relBounds = (*this->bodies.list)->clipModel->bounds;
    if ( this->bodies.num > 1 )
    {
      v5 = 1;
      do
      {
        list = this->bodies.list;
        clipModel = (float *)(*list)->clipModel;
        v8 = (float *)list[v5]->clipModel;
        v9 = clipModel;
        v10 = clipModel[11];
        v11 = (float)(v8[8] - clipModel[8]);
        v12 = (float)((float)((float)(v8[9] - clipModel[9]) * v9[12]) + (float)((float)(v8[10] - clipModel[10]) * v9[13]));
        v13 = (float)((float)(v9[14] * (float)(v8[8] - clipModel[8]))
                    + (float)((float)((float)(v8[9] - clipModel[9]) * v9[15])
                            + (float)((float)(v8[10] - clipModel[10]) * v9[16])));
        v36.z = (float)(v9[17] * (float)(v8[8] - clipModel[8]))
              + (float)((float)((float)(v8[9] - clipModel[9]) * v9[18])
                      + (float)((float)(v8[10] - clipModel[10]) * v9[19]));
        v36.y = v13;
        v36.x = (float)((float)v10 * (float)v11) + (float)v12;
        v14 = (float *)(*list)->clipModel;
        p_axis = &list[v5]->clipModel->axis;
        v16 = v14[16];
        v17 = v14[13];
        v18 = v14[12];
        v19 = v14[17];
        v20 = v14[14];
        v21 = v14[11];
        v22 = v14[19];
        v23 = v14[18];
        v38.mat[1].y = v14[15];
        v38.mat[1].z = v23;
        v38.mat[2].z = v22;
        v38.mat[2].y = v16;
        v38.mat[2].x = v17;
        v38.mat[1].x = v18;
        v38.mat[0].z = v19;
        v38.mat[0].x = v21;
        v38.mat[0].y = v20;
        idMat3::operator*(this: &v39, result: p_axis, a: &v38);
        idBounds::FromTransformedBounds(
          this: &v37,
          bounds: &this->bodies.list[v5]->clipModel->bounds,
          origin: &v36,
          axis: &v39);
        _FP3 = (float)(relBounds.b[0].x - v37.b[0].x);
        _FP2 = (float)(relBounds.b[0].y - v37.b[0].y);
        __asm { fsel      f0, f3, f8, f0 }
        relBounds.b[0].x = _FP0;
        _FP1 = (float)(v37.b[1].x - relBounds.b[1].x);
        _FP8 = (float)(v37.b[1].y - relBounds.b[1].y);
        __asm { fsel      f0, f2, f7, f13 }
        _FP31 = (float)(v37.b[1].z - relBounds.b[1].z);
        ++v4;
        _FP30 = (float)(relBounds.b[0].z - v37.b[0].z);
        relBounds.b[0].y = _FP0;
        ++v5;
        __asm { fsel      f0, f1, f5, f11 }
        relBounds.b[1].x = _FP0;
        __asm { fsel      f0, f8, f4, f10 }
        relBounds.b[1].y = _FP0;
        __asm { fsel      f0, f31, f3, f9 }
        relBounds.b[1].z = _FP0;
        __asm { fsel      f0, f30, f6, f12 }
        relBounds.b[0].z = _FP0;
      }
      while ( v4 < this->bodies.num );
    }
    return &relBounds;
  }
  else
  {
    relBounds.b[1].z = 0.0;
    relBounds.b[1].y = 0.0;
    relBounds.b[1].x = 0.0;
    relBounds.b[0].z = 0.0;
    relBounds.b[0].y = 0.0;
    relBounds.b[0].x = 0.0;
    return &relBounds;
  }
}


// ========================================================================
// ?GetAbsBounds@idPhysics_AF@@UBAABVidBounds@@H@Z
// EA  : 0x827406C0
// RVA : 0x007406C0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

const idBounds *__fastcall idPhysics_AF::GetAbsBounds(idPhysics_AF *this, int id)
{
  int v3; // r9
  float *clipModel; // r7
  int v11; // r8
  idAFBody *v12; // r7
  float *v13; // r10

  if ( (_S14_1 & 1) == 0 )
    _S14_1 |= 1u;
  if ( id >= 0 && id < this->bodies.num )
    return &this->bodies.list[id]->clipModel->absBounds;
  if ( this->bodies.num != 0 )
  {
    v3 = 1;
    clipModel = (float *)(*this->bodies.list)->clipModel;
    _FP0 = clipModel[26];
    absBounds.b[0].x = clipModel[26];
    _FP13 = clipModel[27];
    absBounds.b[0].y = clipModel[27];
    _FP12 = clipModel[28];
    absBounds.b[0].z = clipModel[28];
    _FP11 = clipModel[29];
    absBounds.b[1].x = clipModel[29];
    _FP10 = clipModel[30];
    absBounds.b[1].y = clipModel[30];
    _FP9 = clipModel[31];
    absBounds.b[1].z = clipModel[31];
    if ( this->bodies.num > 1 )
    {
      v11 = 1;
      do
      {
        ++v3;
        v12 = this->bodies.list[v11++];
        v13 = (float *)v12->clipModel;
        _FP7 = (float)((float)_FP0 - v13[26]);
        __asm { fsel      f0, f7, f8, f0 }
        absBounds.b[0].x = _FP0;
        _FP5 = (float)((float)_FP13 - v13[27]);
        __asm { fsel      f13, f5, f6, f13 }
        absBounds.b[0].y = _FP13;
        _FP3 = (float)((float)_FP12 - v13[28]);
        __asm { fsel      f12, f3, f4, f12 }
        absBounds.b[0].z = _FP12;
        _FP1 = (float)(v13[29] - (float)_FP11);
        __asm { fsel      f11, f1, f2, f11 }
        absBounds.b[1].x = _FP11;
        _FP7 = (float)(v13[30] - (float)_FP10);
        __asm { fsel      f10, f7, f8, f10 }
        absBounds.b[1].y = _FP10;
        _FP5 = (float)(v13[31] - (float)_FP9);
        __asm { fsel      f9, f5, f6, f9 }
        absBounds.b[1].z = _FP9;
      }
      while ( v3 < this->bodies.num );
    }
    return &absBounds;
  }
  else
  {
    absBounds.b[1].z = 0.0;
    absBounds.b[1].y = 0.0;
    absBounds.b[1].x = 0.0;
    absBounds.b[0].z = 0.0;
    absBounds.b[0].y = 0.0;
    absBounds.b[0].x = 0.0;
    return &absBounds;
  }
}


// ========================================================================
// ?DebugDraw@idPhysics_AF@@AAAXXZ
// EA  : 0x82740820
// RVA : 0x00740820
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPhysics_AF::DebugDraw(idPhysics_AF *this)
{
  idAFBody *Body; // r22
  idAFBody *body1; // r24
  idAFBody *body2; // r27
  idAFConstraint *Constraint; // r3
  idAFConstraint *v6; // r28
  idRenderWorld *v7; // r3
  idCVarSystem_vtbl *v8; // r27
  const char *v9; // r3
  idCVarSystem_vtbl *v10; // r27
  const char *v11; // r3
  idCVarSystem_vtbl *v12; // r28
  const char *v13; // r3
  idCVarSystem_vtbl *v14; // r28
  const char *v15; // r3
  idCVarSystem_vtbl *v16; // r28
  const char *v17; // r3
  int v18; // r29
  int v19; // r30
  idAFBody *v20; // r11
  int v21; // r29
  int v22; // r30
  idAFBody *v23; // r28
  idRenderWorld *v24; // r3
  int v25; // r29
  int v26; // r30
  idAFBody *v27; // r28
  idRenderWorld *v28; // r3
  __int64 v29; // r6
  idRenderWorld *v30; // r26
  int p_origin; // r28
  __int64 v32; // r10
  __int64 v33; // r8
  va *v34; // r3
  idRenderWorld *v35; // r3
  __int64 v36; // r10
  __int64 v37; // r6
  __int64 v38; // r8
  idRenderWorld *v39; // r30
  float *v40; // r11
  double v41; // fp11
  double v42; // fp10
  va *v43; // r3
  int v44; // r29
  int v45; // r30
  idAFBody *v46; // r26
  idRenderWorld *v47; // r25
  int v48; // r28
  int v49; // r10 OVERLAPPED
  double x; // r5 OVERLAPPED
  __int128 v51; // r9 OVERLAPPED
  va *v52; // r3
  int v53; // r29
  int v54; // r30
  int v55; // r29
  int v56; // r30
  int v57; // r29
  int v58; // r30
  int v59; // r29
  int v60; // r30
  idAFConstraint *v61; // r27
  idRenderWorld *v62; // r3
  int v63; // r29
  int v64; // r30
  idAFConstraint *v65; // r28
  idRenderWorld *v66; // r3
  int v67; // r30
  int v68; // r29
  idAFTree **list; // r28
  const idVec4 *v70; // r3
  int v71; // [sp+8h] [-1118h]
  int v72; // [sp+Ch] [-1114h]
  int v73; // [sp+10h] [-1110h]
  int v74; // [sp+14h] [-110Ch]
  int v75; // [sp+18h] [-1108h]
  int v76; // [sp+1Ch] [-1104h]
  double v77; // [sp+20h] [-1100h]
  double totalMass; // [sp+20h] [-1100h]
  double z; // [sp+48h] [-10D8h]
  idVec3 v80; // [sp+70h] [-10B0h] BYREF
  float v81[4]; // [sp+80h] [-10A0h] BYREF
  float v82[4]; // [sp+90h] [-1090h] BYREF
  va v83; // [sp+A0h] [-1080h] BYREF

  Body = nullptr;
  body1 = nullptr;
  body2 = nullptr;
  if ( *af_highlightConstraint.valueString.data != 0 )
  {
    Constraint = idPhysics_AF::GetConstraint(this, constraintName: af_highlightConstraint.valueString.data);
    v6 = Constraint;
    if ( Constraint != nullptr )
    {
      Constraint->DebugDraw(this: Constraint);
      v6->GetCenter(this: v6, a2: &v80);
      v7 = common->RW(this: common);
      v81[2] = 4.0;
      v81[0] = 0.0;
      v81[1] = 0.0;
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *))v7->DebugCone_2)(
        a1: v7,
        a2: &idColor::colorYellow,
        a3: &v80,
        a4: v81);
      if ( af_showConstrainedBodies.valueInteger != 0 )
      {
        v8 = cvarSystem->__vftable;
        v9 = idColor::ToString(this: &idColor::colorCyan, precision: 0, parens: false);
        v8->SetCVarString(this: cvarSystem, a2: "cm_drawColor", a3: v9, a4: 0);
        body1 = v6->body1;
        if ( body1 != nullptr )
          idClip::DrawSingleClipModel(
            this: this->clip,
            clipModel: body1->clipModel,
            origin: &body1->clipModel->origin,
            axis: &body1->clipModel->axis,
            lifeTime: 0);
        v10 = cvarSystem->__vftable;
        v11 = idColor::ToString(this: &idColor::colorBlue, precision: 0, parens: false);
        v10->SetCVarString(this: cvarSystem, a2: "cm_drawColor", a3: v11, a4: 0);
        body2 = v6->body2;
        if ( body2 != nullptr )
          idClip::DrawSingleClipModel(
            this: this->clip,
            clipModel: body2->clipModel,
            origin: &body2->clipModel->origin,
            axis: &body2->clipModel->axis,
            lifeTime: 0);
        v12 = cvarSystem->__vftable;
        v13 = idColor::ToString(this: &idColor::colorRed, precision: 0, parens: false);
        v12->SetCVarString(this: cvarSystem, a2: "cm_drawColor", a3: v13, a4: 0);
      }
    }
  }
  if ( *af_highlightBody.valueString.data != 0 )
  {
    Body = idPhysics_AF::GetBody(this, bodyName: af_highlightBody.valueString.data);
    if ( Body != nullptr )
    {
      v14 = cvarSystem->__vftable;
      v15 = idColor::ToString(this: &idColor::colorYellow, precision: 0, parens: false);
      v14->SetCVarString(this: cvarSystem, a2: "cm_drawColor", a3: v15, a4: 0);
      idClip::DrawSingleClipModel(
        this: this->clip,
        clipModel: Body->clipModel,
        origin: &Body->clipModel->origin,
        axis: &Body->clipModel->axis,
        lifeTime: 0);
      v16 = cvarSystem->__vftable;
      v17 = idColor::ToString(this: &idColor::colorRed, precision: 0, parens: false);
      v16->SetCVarString(this: cvarSystem, a2: "cm_drawColor", a3: v17, a4: 0);
    }
  }
  if ( af_showBodies.valueInteger != 0 )
  {
    v18 = 0;
    if ( this->bodies.num > 0 )
    {
      v19 = 0;
      do
      {
        v20 = this->bodies.list[v19];
        if ( v20 != body1 && v20 != body2 && v20 != Body )
          idClip::DrawSingleClipModel(
            this: this->clip,
            clipModel: v20->clipModel,
            origin: &v20->clipModel->origin,
            axis: &v20->clipModel->axis,
            lifeTime: 1);
        ++v18;
        ++v19;
      }
      while ( v18 < this->bodies.num );
    }
  }
  if ( af_showBodyNames.valueInteger != 0 )
  {
    v21 = 0;
    if ( this->bodies.num > 0 )
    {
      v22 = 0;
      do
      {
        v23 = this->bodies.list[v22];
        v24 = common->RW(this: common);
        ((void (__fastcall *)(idRenderWorld *, const char *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v24->DebugText)(
          a1: v24,
          a2: v23->name.str,
          a3: &v23->clipModel->origin,
          a4: v24->__vftable,
          a5: &idColor::colorCyan,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.079999998);
        ++v21;
        ++v22;
      }
      while ( v21 < this->bodies.num );
    }
  }
  if ( af_showMass.valueInteger != 0 )
  {
    v25 = 0;
    if ( this->bodies.num > 0 )
    {
      v26 = 0;
      do
      {
        v27 = this->bodies.list[v26];
        v28 = common->RW(this: common);
        v77 = (float)((float)1.0 / v27->invMass);
        HIDWORD(v29) = LODWORD(v77);
        v30 = v28;
        p_origin = (int)&v27->clipModel->origin;
        v34 = va::va(
                this: &v83,
                fmt: "\n%1.2f",
                a3: v29,
                a4: v33,
                a5: v32,
                a6: v71,
                a7: v72,
                a8: v73,
                a9: v74,
                a10: v75,
                a11: v76);
        ((void (__fastcall *)(idRenderWorld *, va *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v30->DebugText)(
          a1: v30,
          a2: v34,
          a3: p_origin,
          a4: v30->DebugText,
          a5: &idColor::colorCyan,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.079999998);
        ++v25;
        ++v26;
      }
      while ( v25 < this->bodies.num );
    }
  }
  if ( af_showTotalMass.valueInteger != 0 )
  {
    v35 = common->RW(this: common);
    HIDWORD(v36) = this->bodies.list;
    totalMass = this->totalMass;
    HIDWORD(v37) = LODWORD(totalMass);
    LODWORD(v38) = &unk_82150000;
    v39 = v35;
    HIDWORD(v38) = *(_DWORD *)HIDWORD(v36);
    v40 = *(float **)(*(_DWORD *)HIDWORD(v36) + 20);
    v41 = (float)(v40[10] + (float)8.0);
    v42 = v40[8];
    v82[1] = v40[9];
    v82[2] = v41;
    v82[0] = v42;
    v43 = va::va(
            this: &v83,
            fmt: "\n%1.2f",
            a3: v37,
            a4: v38,
            a5: v36,
            a6: v71,
            a7: v72,
            a8: v73,
            a9: v74,
            a10: v75,
            a11: v76);
    ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v39->DebugText)(
      a1: v39,
      a2: v43,
      a3: v82,
      a4: v39->__vftable,
      a5: &idColor::colorCyan,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.15000001);
  }
  if ( af_showInertia.valueInteger != 0 )
  {
    v44 = 0;
    if ( this->bodies.num > 0 )
    {
      v45 = 0;
      do
      {
        v46 = this->bodies.list[v45];
        v47 = common->RW(this: common);
        v48 = (int)&v46->clipModel->origin;
        z = v46->inertiaTensor.mat[1].z;
        v49 = LODWORD(z);
        x = v46->inertiaTensor.mat[0].x;
        *((double *)&v51 + 1) = v46->inertiaTensor.mat[1].y;
        *(double *)&v51 = v46->inertiaTensor.mat[0].z;
        v52 = va::va(
                this: &v83,
                fmt: (const char *)HIDWORD(x),
                a3: *(__int64 *)((char *)&x - 4),
                a4: *(__int64 *)((char *)&v51 + 4),
                a5: *(__int64 *)&v49,
                a6: v71,
                a7: v72,
                a8: v73,
                a9: v74,
                a10: v75,
                a11: v76);
        ((void (__fastcall *)(idRenderWorld *, va *, int, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v47->DebugText)(
          a1: v47,
          a2: v52,
          a3: v48,
          a4: v47->DebugText,
          a5: &idColor::colorCyan,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.050000001);
        ++v44;
        ++v45;
      }
      while ( v44 < this->bodies.num );
    }
  }
  if ( af_showVelocity.valueInteger != 0 )
  {
    v53 = 0;
    if ( this->bodies.num > 0 )
    {
      v54 = 0;
      do
      {
        idPhysics_DynamicBase::DrawVelocity(
          this: &this->idPhysics_DynamicBase,
          id: this->bodies.list[v54]->clipModel->bodyId,
          linearScale: 0.1,
          angularScale: 4.0);
        ++v53;
        ++v54;
      }
      while ( v53 < this->bodies.num );
    }
  }
  if ( af_showConstraints.valueInteger != 0 )
  {
    v55 = 0;
    if ( this->primaryConstraints.num > 0 )
    {
      v56 = 0;
      do
      {
        this->primaryConstraints.list[v56]->DebugDraw(this: this->primaryConstraints.list[v56]);
        ++v55;
        ++v56;
      }
      while ( v55 < this->primaryConstraints.num );
    }
    if ( af_showPrimaryOnly.valueInteger == 0 )
    {
      v57 = 0;
      if ( this->auxiliaryConstraints.num > 0 )
      {
        v58 = 0;
        do
        {
          this->auxiliaryConstraints.list[v58]->DebugDraw(this: this->auxiliaryConstraints.list[v58]);
          ++v57;
          ++v58;
        }
        while ( v57 < this->auxiliaryConstraints.num );
      }
    }
  }
  if ( af_showConstraintNames.valueInteger != 0 )
  {
    v59 = 0;
    if ( this->primaryConstraints.num > 0 )
    {
      v60 = 0;
      do
      {
        v61 = this->primaryConstraints.list[v60];
        v61->GetCenter(this: v61, a2: &v80);
        v62 = common->RW(this: common);
        ((void (__fastcall *)(idRenderWorld *, const char *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v62->DebugText)(
          a1: v62,
          a2: v61->name.str,
          a3: &v80,
          a4: v62->__vftable,
          a5: &idColor::colorCyan,
          a6: 1,
          a7: 0,
          a8: 0,
          a9: 0.079999998);
        ++v59;
        ++v60;
      }
      while ( v59 < this->primaryConstraints.num );
    }
    if ( af_showPrimaryOnly.valueInteger == 0 )
    {
      v63 = 0;
      if ( this->auxiliaryConstraints.num > 0 )
      {
        v64 = 0;
        do
        {
          v65 = this->auxiliaryConstraints.list[v64];
          v65->GetCenter(this: v65, a2: &v80);
          v66 = common->RW(this: common);
          ((void (__fastcall *)(idRenderWorld *, const char *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))v66->DebugText)(
            a1: v66,
            a2: v65->name.str,
            a3: &v80,
            a4: v66->__vftable,
            a5: &idColor::colorCyan,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 0.079999998);
          ++v63;
          ++v64;
        }
        while ( v63 < this->auxiliaryConstraints.num );
      }
    }
  }
  if ( af_showTrees.valueInteger != 0 || af_showActive.valueInteger != 0 && !this->IsAtRest(this) )
  {
    v67 = 0;
    if ( this->trees.num > 0 )
    {
      v68 = 0;
      do
      {
        list = this->trees.list;
        v70 = idStr::ColorForIndex(i: v67 + 3);
        idAFTree::DebugDraw(this: list[v68], color: v70);
        ++v67;
        ++v68;
      }
      while ( v67 < this->trees.num );
    }
  }
}


// ========================================================================
// ?DeleteConstraint@idPhysics_AF@@QAAXPBD@Z
// EA  : 0x82741138
// RVA : 0x00741138
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::DeleteConstraint(idPhysics_AF *this, const char *constraintName)
{
  int v4; // r30
  int v5; // r29
  const char *v6; // r3
  idAFConstraint *v7; // r3

  v4 = 0;
  if ( this->constraints.num > 0 )
  {
    v5 = 0;
    do
    {
      if ( idStr::Icmp(s1: this->constraints.list[v5]->name.str, s2: constraintName) == 0 )
        break;
      ++v4;
      ++v5;
    }
    while ( v4 < this->constraints.num );
  }
  if ( v4 < this->constraints.num )
  {
    if ( v4 < 0 )
    {
      idLib::Error(fmt: "DeleteConstraint: no constraint with id %d.", v4);
      JUMPOUT(0x8274122C);
    }
    v7 = this->constraints.list[v4];
    if ( v7 != nullptr )
      ((void (__fastcall *)(idAFConstraint *, int))v7->dtr_idAFConstraint)(a1: v7, a2: 1);
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
      this: (idList<idEntityPtr<idEntity>,58> *)&this->constraints,
      index: v4);
    this->changedAF = true;
  }
  else
  {
    v6 = this->callbacks->GetName(this: this->callbacks);
    idLib::Warning(
      fmt: "DeleteConstraint: no constriant found in the articulated figure with the name '%s' for entity '%s'",
      constraintName,
      v6);
  }
}


// ========================================================================
// ?SaveState@idPhysics_AF@@UAAXXZ
// EA  : 0x82741230
// RVA : 0x00741230
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SaveState(idPhysics_AF *this)
{
  int v2; // r29
  int v3; // r31
  idAFBody *v4; // r11
  float *p_axis; // r10
  idAFBody *v6; // r9
  float *clipModel; // r11

  memcpy(Dst: &this->saved, Src: &this->current, Size: sizeof(this->saved));
  v2 = 0;
  if ( this->bodies.num > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this->bodies.list[v3];
      p_axis = (float *)&v4->clipModel->axis;
      v4->current.worldAxis.mat[0].x = *p_axis;
      v4->current.worldAxis.mat[0].y = p_axis[1];
      v4->current.worldAxis.mat[0].z = p_axis[2];
      v4->current.worldAxis.mat[1].x = p_axis[3];
      v4->current.worldAxis.mat[1].y = p_axis[4];
      v4->current.worldAxis.mat[1].z = p_axis[5];
      v4->current.worldAxis.mat[2].x = p_axis[6];
      v4->current.worldAxis.mat[2].y = p_axis[7];
      v4->current.worldAxis.mat[2].z = p_axis[8];
      v6 = this->bodies.list[v3];
      clipModel = (float *)v6->clipModel;
      v6->current.worldOrigin.x = clipModel[8];
      v6->current.worldOrigin.y = clipModel[9];
      v6->current.worldOrigin.z = clipModel[10];
      AFBodyPState_t::operator=(this: &this->bodies.list[v3]->saved, __that: &this->bodies.list[v3]->current);
      ++v2;
      ++v3;
    }
    while ( v2 < this->bodies.num );
  }
}


// ========================================================================
// ?ClipTranslation@idPhysics_AF@@UBAXAAUtrace_t@@ABVidVec3@@PBVidClipModel@@@Z
// EA  : 0x82741318
// RVA : 0x00741318
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::ClipTranslation(
        idPhysics_AF *this,
        trace_t *results,
        const idVec3 *translation,
        idClipModel *model)
{
  int v8; // r25
  int v9; // r26
  idAFBody *v10; // r11
  idClipModel *clipModel; // r10
  idClip *clip; // r3
  double v13; // fp9
  double v14; // fp7
  idClipModel *v15; // r10
  int entityNumber; // r8
  idClip *v17; // r4
  double v18; // fp7
  double v19; // fp6
  double v20; // fp8
  idClipModel *v21; // r11
  double z; // fp4
  double v23; // fp3
  float *p_axis; // r11
  const idVec3 *v25; // [sp+8h] [-158h]
  const idMat3 *v26; // [sp+Ch] [-154h]
  const char *v27; // [sp+10h] [-150h]
  int v28; // [sp+14h] [-14Ch]
  int v29; // [sp+18h] [-148h]
  int v30; // [sp+1Ch] [-144h]
  int v31; // [sp+20h] [-140h]
  int v32; // [sp+24h] [-13Ch]
  int v33; // [sp+28h] [-138h]
  int v34; // [sp+2Ch] [-134h]
  int v35; // [sp+30h] [-130h]
  int v36; // [sp+34h] [-12Ch]
  int v37; // [sp+38h] [-128h]
  int v38; // [sp+3Ch] [-124h]
  int v39; // [sp+40h] [-120h]
  int v40; // [sp+44h] [-11Ch]
  int v41; // [sp+48h] [-118h]
  int v42; // [sp+4Ch] [-114h]
  int v43; // [sp+50h] [-110h]
  int v44; // [sp+58h] [-108h]
  int v45; // [sp+60h] [-100h]
  idVec3 v46; // [sp+70h] [-F0h] BYREF
  idVec3 v47; // [sp+80h] [-E0h] BYREF
  char v48; // [sp+90h] [-D0h] BYREF
  trace_t v49; // [sp+A0h] [-C0h] BYREF

  results->fraction = 1.0;
  v8 = 0;
  if ( this->bodies.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = this->bodies.list[v9];
      clipModel = v10->clipModel;
      if ( clipModel->traceModels.num != 0 )
      {
        if ( model != nullptr )
        {
          clip = this->clip;
          v13 = (float)(clipModel->origin.z + translation->z);
          v14 = (float)(clipModel->origin.y + translation->y);
          v46.x = translation->x + clipModel->origin.x;
          v46.z = v13;
          v46.y = v14;
          idClip::TranslationModel(
            this: clip,
            result: &v49,
            start: &v10->clipModel->origin,
            end: &v46,
            trm: v10->clipModel,
            trmAxis: &clipModel->axis,
            clipMask: v10->clipMask,
            model,
            modelOrigin: v25,
            modelAxis: v26,
            a11: (int)v27,
            a12: v28,
            a13: v29,
            a14: v30,
            a15: v31,
            a16: v32,
            a17: v33,
            a18: v34,
            a19: v35,
            a20: v36,
            a21: v37,
            a22: v38,
            a23: v39,
            a24: v40,
            a25: v41,
            a26: v42,
            a27: v43,
            a28: &model->origin.x,
            a29: v44,
            a30: (float *)&model->axis);
        }
        else
        {
          v15 = v10->clipModel;
          entityNumber = this->entityNumber;
          v17 = this->clip;
          v18 = (float)(v15->origin.y + translation->y);
          v19 = (float)(v15->origin.x + translation->x);
          v47.z = v15->origin.z + translation->z;
          v47.y = v18;
          v47.x = v19;
          idClip::Translation(
            this: (idClip *)&v48,
            result: v17,
            a3: &v49,
            start: &v10->clipModel->origin,
            end: &v47,
            clipModel: v10->clipModel,
            startAxis: &v15->axis,
            clipMask: v10->clipMask,
            passEntityNumber: (int)v25,
            moveClipModel: (bool)v26,
            userName: v27,
            a12: v28,
            a13: v29,
            a14: v30,
            a15: v31,
            a16: v32,
            a17: v33,
            a18: v34,
            a19: v35,
            a20: v36,
            a21: v37,
            a22: v38,
            a23: v39,
            a24: v40,
            a25: v41,
            a26: v42,
            a27: v43,
            a28: entityNumber,
            a29: v44,
            a30: false,
            a31: v45,
            a32: 0);
        }
        if ( v49.fraction < (double)results->fraction )
          trace_t::operator=(this: results, __that: &v49);
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->bodies.num );
  }
  v20 = (float)(translation->z * results->fraction);
  v21 = (*this->bodies.list)->clipModel;
  z = v21->origin.z;
  v23 = (float)(v21->origin.y + (float)(translation->y * results->fraction));
  results->endpos.x = v21->origin.x + (float)(translation->x * results->fraction);
  results->endpos.y = v23;
  results->endpos.z = (float)z + (float)v20;
  p_axis = (float *)&(*this->bodies.list)->clipModel->axis;
  results->endAxis.mat[0].x = *p_axis;
  results->endAxis.mat[0].y = p_axis[1];
  results->endAxis.mat[0].z = p_axis[2];
  results->endAxis.mat[1].x = p_axis[3];
  results->endAxis.mat[1].y = p_axis[4];
  results->endAxis.mat[1].z = p_axis[5];
  results->endAxis.mat[2].x = p_axis[6];
  results->endAxis.mat[2].y = p_axis[7];
  results->endAxis.mat[2].z = p_axis[8];
}


// ========================================================================
// ?ClipRotation@idPhysics_AF@@UBAXAAUtrace_t@@ABVidRotation@@PBVidClipModel@@@Z
// EA  : 0x82741520
// RVA : 0x00741520
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::ClipRotation(
        idPhysics_AF *this,
        trace_t *results,
        idRotation *rotation,
        idClipModel *model)
{
  int v8; // r25
  int v9; // r26
  idAFBody *v10; // r11
  idClipModel *clipModel; // r10
  idAFBody **list; // r10
  double v13; // fp4
  double y; // fp3
  double z; // fp2
  double x; // fp1
  double v17; // fp31
  double v18; // fp30
  double v19; // fp13
  double v20; // fp12
  idMat3 *p_axis; // r30
  const idMat3 *v22; // r3
  const idVec3 *v23; // [sp+8h] [-1C8h]
  const idMat3 *v24; // [sp+Ch] [-1C4h]
  const char *v25; // [sp+10h] [-1C0h]
  int v26; // [sp+14h] [-1BCh]
  int v27; // [sp+18h] [-1B8h]
  int v28; // [sp+1Ch] [-1B4h]
  int v29; // [sp+20h] [-1B0h]
  int v30; // [sp+24h] [-1ACh]
  int v31; // [sp+28h] [-1A8h]
  int v32; // [sp+2Ch] [-1A4h]
  int v33; // [sp+30h] [-1A0h]
  int v34; // [sp+34h] [-19Ch]
  int v35; // [sp+38h] [-198h]
  int v36; // [sp+3Ch] [-194h]
  int v37; // [sp+40h] [-190h]
  int v38; // [sp+44h] [-18Ch]
  int v39; // [sp+48h] [-188h]
  int v40; // [sp+4Ch] [-184h]
  int v41; // [sp+50h] [-180h]
  int v42; // [sp+58h] [-178h]
  int v43; // [sp+60h] [-170h]
  idRotation v44; // [sp+70h] [-160h] BYREF
  float v45; // [sp+B4h] [-11Ch]
  float v46; // [sp+B8h] [-118h]
  float v47; // [sp+BCh] [-114h]
  char v48; // [sp+C0h] [-110h]
  trace_t v49; // [sp+D0h] [-100h] BYREF
  idMat3 v50; // [sp+150h] [-80h] BYREF

  results->fraction = 1.0;
  v8 = 0;
  if ( this->bodies.num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = this->bodies.list[v9];
      clipModel = v10->clipModel;
      if ( clipModel->traceModels.num != 0 )
      {
        if ( model != nullptr )
          idClip::RotationModel(
            this: this->clip,
            result: &v49,
            start: (const idMat3 *)&clipModel->origin,
            rotation,
            trm: v10->clipModel,
            trmAxis: &clipModel->axis,
            clipMask: (const idVec3 *)v10->clipMask,
            model,
            modelOrigin: v23,
            modelAxis: v24,
            a11: (int)v25,
            a12: v26,
            a13: v27,
            a14: v28,
            a15: v29,
            a16: v30,
            a17: v31,
            a18: v32,
            a19: v33,
            a20: v34,
            a21: v35,
            a22: v36,
            a23: v37,
            a24: v38,
            a25: v39,
            a26: v40,
            a27: v41,
            a28: &model->origin.x,
            a29: v42,
            a30: (float *)&model->axis);
        else
          idClip::Rotation(
            this: (idClip *)&v44,
            result: this->clip,
            a3: &v49,
            start: (const idMat3 *)&v10->clipModel->origin,
            rotation,
            clipModel: v10->clipModel,
            startAxis: &v10->clipModel->axis,
            clipMask: v10->clipMask,
            passEntityNumber: (int)v23,
            moveClipModel: (bool)v24,
            userName: v25,
            a12: v26,
            a13: v27,
            a14: v28,
            a15: v29,
            a16: v30,
            a17: v31,
            a18: v32,
            a19: v33,
            a20: v34,
            a21: v35,
            a22: v36,
            a23: v37,
            a24: v38,
            a25: v39,
            a26: v40,
            a27: v41,
            a28: this->entityNumber,
            a29: v42,
            a30: false,
            a31: v43,
            a32: 0);
        if ( v49.fraction < (double)results->fraction )
          trace_t::operator=(this: results, __that: &v49);
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->bodies.num );
  }
  v48 = 0;
  list = this->bodies.list;
  v13 = (float)(rotation->angle * results->fraction);
  y = rotation->origin.y;
  z = rotation->origin.z;
  x = rotation->vec.x;
  v17 = rotation->vec.y;
  v18 = rotation->vec.z;
  v44.vec.y = rotation->origin.x;
  v44.axis.mat[1].y = mat3_identity.mat[0].x;
  v44.axis.mat[1].x = v13;
  v44.vec.z = y;
  v44.axis.mat[1].z = mat3_identity.mat[0].y;
  v44.angle = z;
  v44.axis.mat[2].x = mat3_identity.mat[0].z;
  v44.axis.mat[0].x = x;
  v44.axis.mat[2].y = mat3_identity.mat[1].x;
  v44.axis.mat[0].y = v17;
  v44.axis.mat[2].z = mat3_identity.mat[1].y;
  v44.axis.mat[0].z = v18;
  *(float *)&v44.axisValid = mat3_identity.mat[1].z;
  v45 = mat3_identity.mat[2].x;
  v46 = mat3_identity.mat[2].y;
  v47 = mat3_identity.mat[2].z;
  idRotation::operator*(this: &v44, result: (idRotation *)&v44.vec.y, v: &(*list)->clipModel->origin);
  v19 = v44.origin.y;
  v20 = v44.origin.z;
  results->endpos.x = v44.origin.x;
  results->endpos.y = v19;
  results->endpos.z = v20;
  p_axis = &(*this->bodies.list)->clipModel->axis;
  v22 = idRotation::ToMat3(this: (idRotation *)&v44.vec.y);
  results->endAxis = *idMat3::operator*(this: &v50, result: p_axis, a: v22);
}


// ========================================================================
// ?ClipContents@idPhysics_AF@@UBAHPBVidClipModel@@H@Z
// EA  : 0x82741770
// RVA : 0x00741770
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

int __fastcall idPhysics_AF::ClipContents(idPhysics_AF *this, idClipModel *model, int clipMask)
{
  int v6; // r30
  int v7; // r27
  int v8; // r28
  idAFBody *v9; // r11
  int v10; // r8
  int v11; // r9
  const idMat3 *v13; // [sp+8h] [-128h]
  int v14; // [sp+Ch] [-124h]
  int v15; // [sp+10h] [-120h]
  int v16; // [sp+14h] [-11Ch]
  int v17; // [sp+18h] [-118h]
  int v18; // [sp+1Ch] [-114h]
  int v19; // [sp+20h] [-110h]
  int v20; // [sp+24h] [-10Ch]
  int v21; // [sp+28h] [-108h]
  int v22; // [sp+2Ch] [-104h]
  int v23; // [sp+30h] [-100h]
  int v24; // [sp+34h] [-FCh]
  int v25; // [sp+38h] [-F8h]
  int v26; // [sp+3Ch] [-F4h]
  int v27; // [sp+40h] [-F0h]
  int v28; // [sp+44h] [-ECh]
  int v29; // [sp+48h] [-E8h]
  int v30; // [sp+4Ch] [-E4h]
  int v31; // [sp+50h] [-E0h]
  char v32; // [sp+60h] [-D0h] BYREF
  trace_t v33; // [sp+70h] [-C0h] BYREF

  v6 = 0;
  v7 = 0;
  if ( this->bodies.num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = this->bodies.list[v8];
      if ( v9->clipModel->traceModels.num != 0 )
      {
        if ( model != nullptr )
        {
          v10 = clipMask;
          if ( clipMask == 0 )
            v10 = v9->clipMask;
          idClip::ContentsModel(
            this: this->clip,
            result: &v33,
            start: &v9->clipModel->origin,
            trm: v9->clipModel,
            trmAxis: &v9->clipModel->axis,
            clipMask: v10,
            model,
            modelOrigin: &model->origin,
            modelAxis: v13,
            a10: v14,
            a11: v15,
            a12: v16,
            a13: v17,
            a14: v18,
            a15: v19,
            a16: v20,
            a17: v21,
            a18: v22,
            a19: v23,
            a20: v24,
            a21: v25,
            a22: v26,
            a23: v27,
            a24: v28,
            a25: v29,
            a26: v30,
            a27: v31,
            a28: (float *)&model->axis);
          v6 |= v33.c.contentFlags;
        }
        else
        {
          v11 = clipMask;
          if ( clipMask == 0 )
            v11 = v9->clipMask;
          idClip::Contents(
            this: (idClip *)&v32,
            result: this->clip,
            a3: &v33,
            start: &v9->clipModel->origin,
            clipModel: v9->clipModel,
            startAxis: &v9->clipModel->axis,
            clipMask: v11,
            passEntityNumber: 0x1FFF,
            userName: (const char *)v13,
            a10: v14,
            a11: v15,
            a12: v16,
            a13: v17,
            a14: v18,
            a15: v19,
            a16: v20,
            a17: v21,
            a18: v22,
            a19: v23,
            a20: v24,
            a21: v25,
            a22: v26,
            a23: v27,
            a24: v28,
            a25: v29,
            a26: v30,
            a27: v31,
            a28: 0);
          v6 |= v33.c.contentFlags;
        }
      }
      ++v7;
      ++v8;
    }
    while ( v7 < this->bodies.num );
  }
  return v6;
}


// ========================================================================
// ?GetLcpEpsilon@idPhysics_AF@@QBAMXZ
// EA  : 0x82741868
// RVA : 0x00741868
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetLcpEpsilon(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_lcpEpsilon; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->lcpEpsilon.type;
  p_lcpEpsilon = &this->lcpEpsilon;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_lcpEpsilon, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_lcpEpsilon, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_lcpEpsilon, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?GetErrorReduction@idPhysics_AF@@QBAMXZ
// EA  : 0x827418A8
// RVA : 0x007418A8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetErrorReduction(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_errorReduction; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->errorReduction.type;
  p_errorReduction = &this->errorReduction;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_errorReduction, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_errorReduction, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_errorReduction, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?GetErrorReductionMax@idPhysics_AF@@QBAMXZ
// EA  : 0x827418E8
// RVA : 0x007418E8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetErrorReductionMax(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_errorReductionMax; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->errorReductionMax.type;
  p_errorReductionMax = &this->errorReductionMax;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_errorReductionMax, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_errorReductionMax, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_errorReductionMax, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?GetLimitErrorReduction@idPhysics_AF@@QBAMXZ
// EA  : 0x82741928
// RVA : 0x00741928
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetLimitErrorReduction(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_limitErrorReduction; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->limitErrorReduction.type;
  p_limitErrorReduction = &this->limitErrorReduction;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_limitErrorReduction, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_limitErrorReduction, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_limitErrorReduction, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?GetLimitErrorReductionMax@idPhysics_AF@@QBAMXZ
// EA  : 0x82741968
// RVA : 0x00741968
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetLimitErrorReductionMax(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_limitErrorReductionMax; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->limitErrorReductionMax.type;
  p_limitErrorReductionMax = &this->limitErrorReductionMax;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_limitErrorReductionMax, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_limitErrorReductionMax, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_limitErrorReductionMax, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?GetLimitLcpEpsilon@idPhysics_AF@@QBAMXZ
// EA  : 0x827419A8
// RVA : 0x007419A8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetLimitLcpEpsilon(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_limitLcpEpsilon; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->limitLcpEpsilon.type;
  p_limitLcpEpsilon = &this->limitLcpEpsilon;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_limitLcpEpsilon, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_limitLcpEpsilon, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_limitLcpEpsilon, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?GetContactErrorReduction@idPhysics_AF@@QBAMXZ
// EA  : 0x827419E8
// RVA : 0x007419E8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetContactErrorReduction(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_contactErrorReduction; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->contactErrorReduction.type;
  p_contactErrorReduction = &this->contactErrorReduction;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_contactErrorReduction, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_contactErrorReduction, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_contactErrorReduction, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?GetContactErrorReductionMax@idPhysics_AF@@QBAMXZ
// EA  : 0x82741A28
// RVA : 0x00741A28
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetContactErrorReductionMax(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_contactErrorReductionMax; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->contactErrorReductionMax.type;
  p_contactErrorReductionMax = &this->contactErrorReductionMax;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_contactErrorReductionMax, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_contactErrorReductionMax, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_contactErrorReductionMax, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?GetContactLcpEpsilon@idPhysics_AF@@QBAMXZ
// EA  : 0x82741A68
// RVA : 0x00741A68
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetContactLcpEpsilon(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_contactLcpEpsilon; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->contactLcpEpsilon.type;
  p_contactLcpEpsilon = &this->contactLcpEpsilon;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_contactLcpEpsilon, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_contactLcpEpsilon, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_contactLcpEpsilon, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?GetUniversalErrorReduction@idPhysics_AF@@QBAMXZ
// EA  : 0x82741AA8
// RVA : 0x00741AA8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetUniversalErrorReduction(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_universalErrorReduction; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->universalErrorReduction.type;
  p_universalErrorReduction = &this->universalErrorReduction;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_universalErrorReduction, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_universalErrorReduction, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_universalErrorReduction, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?GetUniversalTorsionLcpEpsilon@idPhysics_AF@@QBAMXZ
// EA  : 0x82741AE8
// RVA : 0x00741AE8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

double __fastcall idPhysics_AF::GetUniversalTorsionLcpEpsilon(
        idPhysics_AF *this,
        long double a2,
        int a3,
        int a4,
        int a5,
        int a6,
        _BYTE *a7,
        __int64 a8)
{
  idFader *p_universalTorsionLcpEpsilon; // r3
  int endTime; // r4
  idFader::type_t type; // r11

  endTime = this->endTime;
  type = this->universalTorsionLcpEpsilon.type;
  p_universalTorsionLcpEpsilon = &this->universalTorsionLcpEpsilon;
  if ( type == FADE_LINEAR )
    return idFader::GetLinear(this: p_universalTorsionLcpEpsilon, time: endTime, a3: a4, a4: a5, a5: a6, a6: a7);
  if ( type == FADE_SINE )
    return idFader::GetSine(this: p_universalTorsionLcpEpsilon, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  if ( (unsigned int)type < (FADE_INVERSE_SINE|FADE_SINE) )
    return idFader::GetInverseSine(this: p_universalTorsionLcpEpsilon, time: endTime, a3: a2, a4, a5, a6, (int)a7, a8);
  return 0.0;
}


// ========================================================================
// ?TestNoclipBodies@idPhysics_AF@@QAAXXZ
// EA  : 0x82741B28
// RVA : 0x00741B28
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::TestNoclipBodies(idPhysics_AF *this)
{
  int v2; // r23
  idStaticList<idPhysics_AF::noclipBodyInfo_t,8> *p_noclipBodies; // r27
  int v4; // r24
  unsigned __int64 v5; // r22
  idPhysics_AF::noclipBodyInfo_t *v6; // r31
  int bodyId; // r4
  idAFBody *v8; // r30
  unsigned __int64 index; // r11
  unsigned int v10; // r11
  char v11; // r11
  bool v12; // zf
  unsigned __int64 v13; // r11
  idAFBody::afBodyFlags_t fl; // r10
  int num; // r11
  idPhysics_AF::noclipBodyInfo_t *v16; // r9
  idPhysics_AF::noclipBodyInfo_t *v17; // r8
  const char *v18; // [sp+8h] [-188h]
  int v19; // [sp+Ch] [-184h]
  int v20; // [sp+10h] [-180h]
  int v21; // [sp+14h] [-17Ch]
  int v22; // [sp+18h] [-178h]
  int v23; // [sp+1Ch] [-174h]
  int v24; // [sp+20h] [-170h]
  int v25; // [sp+24h] [-16Ch]
  int v26; // [sp+28h] [-168h]
  int v27; // [sp+2Ch] [-164h]
  int v28; // [sp+30h] [-160h]
  int v29; // [sp+34h] [-15Ch]
  int v30; // [sp+38h] [-158h]
  int v31; // [sp+3Ch] [-154h]
  int v32; // [sp+40h] [-150h]
  int v33; // [sp+44h] [-14Ch]
  int v34; // [sp+48h] [-148h]
  int v35; // [sp+4Ch] [-144h]
  int v36; // [sp+50h] [-140h]
  char v37; // [sp+60h] [-130h] BYREF
  trace_t v38; // [sp+70h] [-120h] BYREF

  v2 = this->noclipBodies.num - 1;
  if ( v2 >= 0 )
  {
    p_noclipBodies = &this->noclipBodies;
    v4 = v2;
    LODWORD(v5) = 0;
    HIDWORD(v5) = &vec3_origin;
    do
    {
      v6 = &p_noclipBodies->list[v4];
      bodyId = v6->bodyId;
      if ( v6->bodyId < 0 || bodyId >= this->bodies.num )
      {
        idLib::Warning(fmt: "GetBody: no body with id %d exists", bodyId);
      }
      else
      {
        v8 = this->bodies.list[bodyId];
        if ( v8 != nullptr )
        {
          index = v6->query.index;
          if ( (unsigned int)index < *(_DWORD *)(HIDWORD(index) + 377212)
            || (unsigned int)index > *(_DWORD *)(HIDWORD(index) + 377220) )
          {
            v11 = 0;
          }
          else
          {
            v10 = *(_DWORD *)(8 * (HIDWORD(idCollisionQuery::finalResultsFirstSubmittedOffset) + ((2 * index) & 0x1FFE))
                            + HIDWORD(index)
                            + 278924);
            if ( v10 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
              || (v12 = v10 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v11 = 1, !v12) )
            {
              v11 = 0;
            }
          }
          if ( v11 != 0
            && (v13 = v6->query.index,
                v6->query.index = v5,
                idCollisionModelManager::GetContentsResult(
                  this: collisionModelManager,
                  result: &v38,
                  query: (idCollisionQuery *)(24 * (v13 & 0xFFF) + HIDWORD(v13) + 278920),
                  peek: false),
                v38.fraction >= 1.0) )
          {
            fl = v8->fl;
            v8->clipMask = v6->originalClipMask;
            v8->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&fl | 0x80);
            num = p_noclipBodies->num;
            if ( v2 < num )
            {
              p_noclipBodies->num = num - 1;
              if ( v2 != num - 1 )
              {
                v16 = &p_noclipBodies->list[num - 1];
                v17 = &p_noclipBodies->list[v4];
                *(_QWORD *)&v17->bodyId = *(_QWORD *)&v16->bodyId;
                v17->query.index = v16->query.index;
              }
            }
          }
          else
          {
            v6->query.index = *(_QWORD *)&idClip::LocalContents(
                                            this: (idClip *)&v37,
                                            result: (idClipQuery *)HIDWORD(v8->motionQuery.index),
                                            localSpace: (idClipQuery *)v8->motionQuery.index,
                                            start: &vec3_origin,
                                            clipModel: v8->clipModel,
                                            startAxis: &mat3_identity,
                                            clipMask: v6->originalClipMask,
                                            passEntityNumber: this->entityNumber,
                                            userName: v18,
                                            a10: v19,
                                            a11: v20,
                                            a12: v21,
                                            a13: v22,
                                            a14: v23,
                                            a15: v24,
                                            a16: v25,
                                            a17: v26,
                                            a18: v27,
                                            a19: v28,
                                            a20: v29,
                                            a21: v30,
                                            a22: v31,
                                            a23: v32,
                                            a24: v33,
                                            a25: v34,
                                            a26: v35,
                                            a27: v36,
                                            a28: (int)"w:\\tech5\\engine\\gamelib\\physics\\Physics_AF.cpp(3671) : AF_TestSolid")->world;
          }
        }
      }
      --v2;
      --v4;
    }
    while ( v2 >= 0 );
  }
}


// ========================================================================
// ?Evolve@idPhysics_AF@@AAAXM@Z
// EA  : 0x82741D38
// RVA : 0x00741D38
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::Evolve(idPhysics_AF *this, double timeStep)
{
  int v4; // r8
  double v5; // fp11
  double v6; // fp10
  int v7; // r9
  idAFBody *v8; // r10
  float *p; // r11
  float *v10; // r6
  float *mat; // r5
  float *v12; // r4
  double v13; // fp5
  double v14; // fp7
  double v15; // fp6
  double v16; // fp12
  double v17; // fp29
  double v18; // fp5
  double v19; // fp28
  double v20; // fp4
  double v21; // fp1
  double v22; // fp3
  double v23; // fp2
  double v24; // fp13
  double v26; // fp5
  double v27; // fp4
  double v29; // fp2
  double v30; // fp7
  double v31; // fp2
  double v32; // fp7
  double v33; // fp13
  double v35; // fp5
  double v36; // fp4
  double v38; // fp2
  double v39; // fp7
  double v40; // fp2
  double v41; // fp7
  __int64 v42; // r3
  int v43; // r27
  int v44; // r28
  idAFBody *v45; // r31
  double v46; // fp29
  double v47; // fp1
  double v48; // fp6
  double v49; // fp3
  double v50; // fp9
  double v51; // fp4
  double v52; // fp5
  double v53; // fp5
  double v54; // fp1
  double v55; // fp7
  double v56; // fp11
  int v57; // r3
  __int64 v58; // r11
  __int64 v59; // r11

  v4 = 0;
  v5 = (float)(af_maxLinearVelocity.valueFloat * (float)((float)1.0 / (float)timeStep));
  v6 = (float)(af_maxAngularVelocity.valueFloat * (float)((float)1.0 / (float)timeStep));
  if ( this->bodies.num > 0 )
  {
    v7 = 0;
    do
    {
      v8 = this->bodies.list[v7];
      p = v8->current.spatialVelocity.p;
      v10 = v8->totalForce.p;
      mat = v8->inverseWorldSpatialInertia.mat;
      v12 = v8->acceleration.p;
      *v12 = *v10 * *mat;
      v12[1] = mat[9] * v10[1];
      v12[2] = mat[18] * v10[2];
      v12[3] = (float)(mat[29] * v10[5]) + (float)((float)(mat[28] * v10[4]) + (float)(mat[27] * v10[3]));
      v12[4] = (float)(mat[37] * v10[5]) + (float)((float)(mat[36] * v10[4]) + (float)(mat[35] * v10[3]));
      v13 = (float)((float)(mat[45] * v10[5]) + (float)((float)(mat[44] * v10[4]) + (float)(mat[43] * v10[3])));
      v12[5] = (float)(mat[45] * v10[5]) + (float)((float)(mat[44] * v10[4]) + (float)(mat[43] * v10[3]));
      v14 = v8->current.spatialVelocity.p[2];
      v15 = v8->current.spatialVelocity.p[3];
      v16 = v8->current.spatialVelocity.p[0];
      v17 = v8->current.spatialVelocity.p[5];
      v19 = (float)(v12[2] * (float)timeStep);
      v20 = (float)(v12[3] * (float)timeStep);
      v21 = (float)((float)timeStep * *v12);
      v22 = (float)(v12[4] * (float)timeStep);
      v23 = (float)((float)v13 * (float)timeStep);
      v18 = v8->current.spatialVelocity.p[4];
      v8->current.spatialVelocity.p[1] = v8->current.spatialVelocity.p[1] + (float)(v12[1] * (float)timeStep);
      v8->current.spatialVelocity.p[2] = (float)v14 + (float)v19;
      v8->current.spatialVelocity.p[3] = (float)v15 + (float)v20;
      v8->current.spatialVelocity.p[0] = (float)v16 + (float)v21;
      v8->current.spatialVelocity.p[4] = (float)v18 + (float)v22;
      v8->current.spatialVelocity.p[5] = (float)v17 + (float)v23;
      if ( v5 > 0.0 )
      {
        v24 = (float)((float)(p[2] * p[2]) + (float)((float)(*p * *p) + (float)(p[1] * p[1])));
        if ( v24 > (float)((float)v5 * (float)v5) )
        {
          _FP7 = (float)((float)((float)(p[2] * p[2]) + (float)((float)(*p * *p) + (float)(p[1] * p[1])))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          v26 = v8->current.spatialVelocity.p[1];
          v27 = v8->current.spatialVelocity.p[2];
          __asm { fsel      f3, f7, f13, f12 }
          v29 = __frsqrte(_FP3);
          v30 = (float)((float)-(float)((float)((float)((float)((float)((float)(p[2] * p[2])
                                                                      + (float)((float)(*p * *p) + (float)(p[1] * p[1])))
                                                              * (float)0.5)
                                                      * (float)v29)
                                              * (float)v29)
                                      - (float)1.5)
                      * (float)v29);
          v31 = (float)-(float)((float)((float)((float)((float)v24 * (float)0.5)
                                              * (float)((float)-(float)((float)((float)((float)((float)v24 * (float)0.5)
                                                                                      * (float)v29)
                                                                              * (float)v29)
                                                                      - (float)1.5)
                                                      * (float)v29))
                                      * (float)((float)-(float)((float)((float)((float)((float)v24 * (float)0.5)
                                                                              * (float)v29)
                                                                      * (float)v29)
                                                              - (float)1.5)
                                              * (float)v29))
                              - (float)1.5);
          v32 = (float)((float)((float)-(float)((float)((float)((float)((float)((float)(p[2] * p[2])
                                                                              + (float)((float)(*p * *p)
                                                                                      + (float)(p[1] * p[1])))
                                                                      * (float)0.5)
                                                              * (float)((float)v31 * (float)v30))
                                                      * (float)((float)v31 * (float)v30))
                                              - (float)1.5)
                              * (float)((float)v31 * (float)v30))
                      * (float)v5);
          *p = *p * (float)v32;
          v8->current.spatialVelocity.p[1] = (float)v26 * (float)v32;
          v8->current.spatialVelocity.p[2] = (float)v27 * (float)v32;
        }
      }
      if ( v6 > 0.0 )
      {
        v33 = (float)((float)(v8->current.spatialVelocity.p[5] * v8->current.spatialVelocity.p[5])
                    + (float)((float)(v8->current.spatialVelocity.p[3] * v8->current.spatialVelocity.p[3])
                            + (float)(v8->current.spatialVelocity.p[4] * v8->current.spatialVelocity.p[4])));
        if ( v33 > (float)((float)v6 * (float)v6) )
        {
          _FP7 = (float)((float)((float)(v8->current.spatialVelocity.p[5] * v8->current.spatialVelocity.p[5])
                               + (float)((float)(v8->current.spatialVelocity.p[3] * v8->current.spatialVelocity.p[3])
                                       + (float)(v8->current.spatialVelocity.p[4] * v8->current.spatialVelocity.p[4])))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          v35 = v8->current.spatialVelocity.p[4];
          v36 = v8->current.spatialVelocity.p[5];
          __asm { fsel      f3, f7, f13, f12 }
          v38 = __frsqrte(_FP3);
          v39 = (float)((float)-(float)((float)((float)((float)v38
                                                      * (float)((float)((float)(v8->current.spatialVelocity.p[5]
                                                                              * v8->current.spatialVelocity.p[5])
                                                                      + (float)((float)(v8->current.spatialVelocity.p[3]
                                                                                      * v8->current.spatialVelocity.p[3])
                                                                              + (float)(v8->current.spatialVelocity.p[4]
                                                                                      * v8->current.spatialVelocity.p[4])))
                                                              * (float)0.5))
                                              * (float)v38)
                                      - (float)1.5)
                      * (float)v38);
          v40 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v38
                                                                                      * (float)((float)v33 * (float)0.5))
                                                                              * (float)v38)
                                                                      - (float)1.5)
                                                      * (float)v38)
                                              * (float)((float)v33 * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v38
                                                                              * (float)((float)v33 * (float)0.5))
                                                                      * (float)v38)
                                                              - (float)1.5)
                                              * (float)v38))
                              - (float)1.5);
          v41 = (float)((float)((float)-(float)((float)((float)((float)((float)v40 * (float)v39)
                                                              * (float)((float)((float)(v8->current.spatialVelocity.p[5]
                                                                                      * v8->current.spatialVelocity.p[5])
                                                                              + (float)((float)(v8->current.spatialVelocity.p[3]
                                                                                              * v8->current.spatialVelocity.p[3])
                                                                                      + (float)(v8->current.spatialVelocity.p[4]
                                                                                              * v8->current.spatialVelocity.p[4])))
                                                                      * (float)0.5))
                                                      * (float)((float)v40 * (float)v39))
                                              - (float)1.5)
                              * (float)((float)v40 * (float)v39))
                      * (float)v6);
          v8->current.spatialVelocity.p[3] = (float)v41 * v8->current.spatialVelocity.p[3];
          v8->current.spatialVelocity.p[4] = (float)v35 * (float)v41;
          v8->current.spatialVelocity.p[5] = (float)v36 * (float)v41;
        }
      }
      ++v4;
      ++v7;
    }
    while ( v4 < this->bodies.num );
  }
  timer_collision.state = TS_STARTED;
  LODWORD(v42) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  timer_collision.start = v42;
  v43 = 0;
  if ( this->bodies.num > 0 )
  {
    v44 = 0;
    do
    {
      v45 = this->bodies.list[v44];
      if ( af_skipAirFriction.valueInteger == 0 )
      {
        v46 = (float)(this->GetWaterViscosity(this, a2: 0) * v45->linearFrictionWater);
        v47 = ((double (__fastcall *)(idPhysics_AF *, _DWORD))this->GetWaterViscosity)(a1: this, a2: 0);
        v48 = v45->current.spatialVelocity.p[2];
        v49 = v45->current.spatialVelocity.p[0];
        v50 = (float)((float)((float)((float)((float)v47 * v45->angularFrictionWater) - v45->angularFriction)
                            * this->waterLevel)
                    + v45->angularFriction);
        v51 = (float)((float)(v45->current.spatialVelocity.p[0]
                            * (float)((float)((float)((float)v46 - v45->linearFriction) * this->waterLevel)
                                    + v45->linearFriction))
                    * (float)timeStep);
        v52 = (float)((float)(v45->current.spatialVelocity.p[2]
                            * (float)((float)((float)((float)v46 - v45->linearFriction) * this->waterLevel)
                                    + v45->linearFriction))
                    * (float)timeStep);
        v45->current.spatialVelocity.p[1] = v45->current.spatialVelocity.p[1]
                                          - (float)((float)(v45->current.spatialVelocity.p[1]
                                                          * (float)((float)((float)((float)v46 - v45->linearFriction)
                                                                          * this->waterLevel)
                                                                  + v45->linearFriction))
                                                  * (float)timeStep);
        v45->current.spatialVelocity.p[0] = (float)v49 - (float)v51;
        v45->current.spatialVelocity.p[2] = (float)v48 - (float)v52;
        v53 = (float)(v45->current.spatialVelocity.p[3] * (float)v50);
        v54 = (float)(v45->current.spatialVelocity.p[5] * (float)v50);
        v55 = v45->current.spatialVelocity.p[3];
        v56 = v45->current.spatialVelocity.p[5];
        v45->current.spatialVelocity.p[4] = v45->current.spatialVelocity.p[4]
                                          - (float)((float)(v45->current.spatialVelocity.p[4] * (float)v50)
                                                  * (float)timeStep);
        v45->current.spatialVelocity.p[3] = (float)v55 - (float)((float)v53 * (float)timeStep);
        v45->current.spatialVelocity.p[5] = (float)v56 - (float)((float)v54 * (float)timeStep);
      }
      v45->current.externalForce.p[2] = 0.0;
      ++v43;
      v45->current.externalForce.p[4] = 0.0;
      ++v44;
      v45->current.externalForce.p[5] = 0.0;
      v45->current.externalForce.p[3] = 0.0;
      v45->current.externalForce.p[1] = 0.0;
      v45->current.externalForce.p[0] = 0.0;
    }
    while ( v43 < this->bodies.num );
  }
  idPhysics_AF::IssueCollisionQueries(this);
  idPhysics_AF::TestNoclipBodies(this);
  v57 = (unsigned __int64)Sys_GetClockTicks() >> 32;
  HIDWORD(v58) = HIDWORD(timer_collision.start);
  LODWORD(v58) = v57 + HIDWORD(timer_collision.start) - LODWORD(timer_collision.start);
  timer_collision.clockTicks = v58;
  if ( (float)idTimer::base < 0.0 )
  {
    idTimer::InitBaseClockTicks(this: &timer_collision);
    LODWORD(v58) = timer_collision.clockTicks;
  }
  if ( (int)v58 > (int)idTimer::base )
  {
    LODWORD(v59) = v58 - idTimer::base;
    HIDWORD(v59) = 1;
    timer_collision.clockTicks = v59;
  }
  timer_collision.state = TS_STOPPED;
}


// ========================================================================
// ??0idPhysics_AF@@QAA@XZ
// EA  : 0x827423A0
// RVA : 0x007423A0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

idPhysics_AF *__fastcall idPhysics_AF::idPhysics_AF(idPhysics_AF *this)
{
  double valueFloat; // fp0
  double v3; // fp0
  double v4; // fp0
  double v5; // fp0
  double v6; // fp0
  double v7; // fp0
  double v8; // fp0
  double v9; // fp0
  double v10; // fp0
  double v11; // fp0
  double v12; // fp0
  double v13; // fp0

  idPhysics_DynamicBase::idPhysics_DynamicBase(this: &this->idPhysics_DynamicBase);
  this->__vftable = (idPhysics_AF_vtbl *)&idPhysics_AF::`vftable';
  this->trees.list = nullptr;
  this->trees.granularity = 0;
  this->trees.memTag = 71;
  this->trees.listStatic = 0;
  this->trees.size = 0;
  this->trees.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trees);
  this->bodies.list = nullptr;
  this->bodies.granularity = 0;
  this->bodies.memTag = 71;
  this->bodies.listStatic = 0;
  this->bodies.size = 0;
  this->bodies.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->bodies);
  this->constraints.list = nullptr;
  this->constraints.granularity = 0;
  this->constraints.memTag = 71;
  this->constraints.listStatic = 0;
  this->constraints.size = 0;
  this->constraints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constraints);
  this->primaryConstraints.list = nullptr;
  this->primaryConstraints.granularity = 0;
  this->primaryConstraints.memTag = 71;
  this->primaryConstraints.listStatic = 0;
  this->primaryConstraints.size = 0;
  this->primaryConstraints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->primaryConstraints);
  this->auxiliaryConstraints.list = nullptr;
  this->auxiliaryConstraints.granularity = 0;
  this->auxiliaryConstraints.memTag = 71;
  this->auxiliaryConstraints.listStatic = 0;
  this->auxiliaryConstraints.size = 0;
  this->auxiliaryConstraints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->auxiliaryConstraints);
  this->frameConstraints.list = nullptr;
  this->frameConstraints.granularity = 0;
  this->frameConstraints.memTag = 71;
  this->frameConstraints.listStatic = 0;
  this->frameConstraints.size = 0;
  this->frameConstraints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->frameConstraints);
  this->contactConstraints.list = nullptr;
  this->contactConstraints.granularity = 0;
  this->contactConstraints.memTag = 71;
  this->contactConstraints.listStatic = 0;
  this->contactConstraints.size = 0;
  this->contactConstraints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactConstraints);
  this->contactBodies.list = nullptr;
  this->contactBodies.granularity = 0;
  this->contactBodies.memTag = 71;
  this->contactBodies.listStatic = 0;
  this->contactBodies.size = 0;
  this->contactBodies.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactBodies);
  this->noclipBodies.num = 0;
  this->noclipBodies.granularity = 1;
  this->noclipBodies.list = this->noclipBodies.staticList;
  this->noclipBodies.size = 8;
  this->noclipBodies.memTag = 5;
  this->noclipBodies.listStatic = 1;
  this->noclipBodies.staticList[0].bodyId = -1;
  this->noclipBodies.staticList[0].originalClipMask = 0;
  this->noclipBodies.staticList[0].query.index = 0x100000000LL;
  this->noclipBodies.staticList[1].bodyId = -1;
  this->noclipBodies.staticList[1].originalClipMask = 0;
  this->noclipBodies.staticList[1].query.index = 0x100000000LL;
  this->noclipBodies.staticList[2].bodyId = -1;
  this->noclipBodies.staticList[2].originalClipMask = 0;
  this->noclipBodies.staticList[2].query.index = 0x100000000LL;
  this->noclipBodies.staticList[3].bodyId = -1;
  this->noclipBodies.staticList[3].originalClipMask = 0;
  this->noclipBodies.staticList[3].query.index = 0x100000000LL;
  this->noclipBodies.staticList[4].bodyId = -1;
  this->noclipBodies.staticList[4].originalClipMask = 0;
  this->noclipBodies.staticList[4].query.index = 0x100000000LL;
  this->noclipBodies.staticList[5].bodyId = -1;
  this->noclipBodies.staticList[5].originalClipMask = 0;
  this->noclipBodies.staticList[5].query.index = 0x100000000LL;
  this->noclipBodies.staticList[6].bodyId = -1;
  this->noclipBodies.staticList[6].originalClipMask = 0;
  this->noclipBodies.staticList[6].query.index = 0x100000000LL;
  this->noclipBodies.staticList[7].bodyId = -1;
  this->noclipBodies.staticList[7].originalClipMask = 0;
  this->noclipBodies.staticList[7].query.index = 0x100000000LL;
  this->errorReduction.type = FADE_LINEAR;
  this->errorReduction.startTime = -1;
  this->errorReduction.duration = -1;
  this->errorReduction.startValue = 0.0;
  this->errorReduction.endValue = 0.0;
  this->errorReductionMax.type = FADE_LINEAR;
  this->errorReductionMax.startValue = 0.0;
  this->errorReductionMax.startTime = -1;
  this->errorReductionMax.endValue = 0.0;
  this->errorReductionMax.duration = -1;
  this->lcpEpsilon.startValue = 0.0;
  this->lcpEpsilon.type = FADE_LINEAR;
  this->lcpEpsilon.endValue = 0.0;
  this->lcpEpsilon.startTime = -1;
  this->lcpEpsilon.duration = -1;
  this->limitErrorReduction.startValue = 0.0;
  this->limitErrorReduction.endValue = 0.0;
  this->limitErrorReduction.type = FADE_LINEAR;
  this->limitErrorReduction.startTime = -1;
  this->limitErrorReduction.duration = -1;
  this->limitErrorReductionMax.startValue = 0.0;
  this->limitErrorReductionMax.endValue = 0.0;
  this->limitErrorReductionMax.type = FADE_LINEAR;
  this->limitErrorReductionMax.startTime = -1;
  this->limitErrorReductionMax.duration = -1;
  this->limitLcpEpsilon.startValue = 0.0;
  this->limitLcpEpsilon.endValue = 0.0;
  this->limitLcpEpsilon.type = FADE_LINEAR;
  this->limitLcpEpsilon.startTime = -1;
  this->limitLcpEpsilon.duration = -1;
  this->contactErrorReduction.startValue = 0.0;
  this->contactErrorReduction.endValue = 0.0;
  this->contactErrorReduction.type = FADE_LINEAR;
  this->contactErrorReduction.startTime = -1;
  this->contactErrorReduction.duration = -1;
  this->contactErrorReductionMax.startValue = 0.0;
  this->contactErrorReductionMax.endValue = 0.0;
  this->contactErrorReductionMax.type = FADE_LINEAR;
  this->contactErrorReductionMax.startTime = -1;
  this->contactErrorReductionMax.duration = -1;
  this->contactLcpEpsilon.startValue = 0.0;
  this->contactLcpEpsilon.endValue = 0.0;
  this->contactLcpEpsilon.type = FADE_LINEAR;
  this->contactLcpEpsilon.startTime = -1;
  this->contactLcpEpsilon.duration = -1;
  this->universalErrorReduction.startValue = 0.0;
  this->universalErrorReduction.endValue = 0.0;
  this->universalErrorReduction.type = FADE_LINEAR;
  this->universalErrorReduction.startTime = -1;
  this->universalErrorReduction.duration = -1;
  this->universalErrorReductionMax.startValue = 0.0;
  this->universalErrorReductionMax.endValue = 0.0;
  this->universalErrorReductionMax.type = FADE_LINEAR;
  this->universalErrorReductionMax.startTime = -1;
  this->universalErrorReductionMax.duration = -1;
  this->universalTorsionLcpEpsilon.startValue = 0.0;
  this->universalTorsionLcpEpsilon.endValue = 0.0;
  this->universalTorsionLcpEpsilon.type = FADE_LINEAR;
  this->universalTorsionLcpEpsilon.startTime = -1;
  this->universalTorsionLcpEpsilon.duration = -1;
  this->type = PHYSICS_AF;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trees);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->bodies);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->primaryConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->auxiliaryConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->frameConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contacts);
  this->changedAF = true;
  this->masterBody = nullptr;
  this->lcp = idLCP::AllocSymmetric();
  memset(Dst: &this->current, Val: 0, Size: sizeof(this->current));
  this->current.atRest = false;
  memcpy(Dst: &this->saved, Src: &this->current, Size: sizeof(this->saved));
  this->linearFriction = 0.0049999999;
  this->angularFriction = 0.0049999999;
  this->lastTimeStep = 0.016666668;
  this->contactFriction = 0.80000001;
  this->bouncyness = 0.5;
  this->totalMass = -1.0;
  this->suspendVelocity.x = 10.0;
  this->suspendVelocity.y = 15.0;
  this->suspendAcceleration.x = 20.0;
  this->suspendAcceleration.y = 20.0;
  this->noMoveTranslation = 10.0;
  this->noMoveRotation = 10.0;
  this->minMoveTime = -1.0;
  this->noMoveTime = 1.0;
  this->maxMoveTime = -1.0;
  this->impulseThreshold = 1.0;
  this->timeScale = 1.0;
  this->timeScaleRampStart = 0.0;
  this->timeScaleRampEnd = 0.0;
  this->jointFrictionScale = 0.0;
  this->jointFrictionDent = 0.0;
  this->jointFrictionDentStart = 0.0;
  this->jointFrictionDentEnd = 0.0;
  this->jointFrictionDentScale = 0.0;
  this->contactFrictionScale = 0.0;
  this->contactFrictionDent = 0.0;
  this->contactFrictionDentStart = 0.0;
  this->contactFrictionDentEnd = 0.0;
  this->contactFrictionDentScale = 0.0;
  lastTimerReset = 0;
  valueFloat = af_lcpEpsilon.valueFloat;
  this->lcpEpsilon.startValue = af_lcpEpsilon.valueFloat;
  this->lcpEpsilon.endValue = valueFloat;
  v3 = af_errorReduction.valueFloat;
  this->errorReduction.startValue = af_errorReduction.valueFloat;
  this->errorReduction.endValue = v3;
  v4 = af_errorReductionMax.valueFloat;
  this->errorReductionMax.startValue = af_errorReductionMax.valueFloat;
  this->errorReductionMax.endValue = v4;
  v5 = af_limitErrorReduction.valueFloat;
  this->limitErrorReduction.startValue = af_limitErrorReduction.valueFloat;
  this->limitErrorReduction.endValue = v5;
  v6 = af_limitErrorReductionMax.valueFloat;
  this->limitErrorReductionMax.startValue = af_limitErrorReductionMax.valueFloat;
  this->limitErrorReductionMax.endValue = v6;
  v7 = af_limitLcpEpsilon.valueFloat;
  this->limitLcpEpsilon.startValue = af_limitLcpEpsilon.valueFloat;
  this->limitLcpEpsilon.endValue = v7;
  v8 = af_contactErrorReduction.valueFloat;
  this->contactErrorReduction.startValue = af_contactErrorReduction.valueFloat;
  this->contactErrorReduction.endValue = v8;
  v9 = af_contactErrorReductionMax.valueFloat;
  this->contactErrorReductionMax.startValue = af_contactErrorReductionMax.valueFloat;
  this->contactErrorReductionMax.endValue = v9;
  v10 = af_contactLcpEpsilon.valueFloat;
  this->contactLcpEpsilon.startValue = af_contactLcpEpsilon.valueFloat;
  this->contactLcpEpsilon.endValue = v10;
  v11 = af_universalErrorReduction.valueFloat;
  this->universalErrorReduction.startValue = af_universalErrorReduction.valueFloat;
  this->universalErrorReduction.endValue = v11;
  v12 = af_universalErrorReductionMax.valueFloat;
  this->universalErrorReductionMax.startValue = af_universalErrorReductionMax.valueFloat;
  this->universalErrorReductionMax.endValue = v12;
  v13 = af_universalTorsionLcpEpsilon.valueFloat;
  this->universalTorsionLcpEpsilon.startValue = af_universalTorsionLcpEpsilon.valueFloat;
  this->universalTorsionLcpEpsilon.endValue = v13;
  this->addContactConstraints = true;
  this->timeStep = 0.0;
  this->addGravity = true;
  this->endTime = 0;
  this->passEntityNum = 0x1FFF;
  this->selfCollision = true;
  this->comeToRest = true;
  this->linearTime = true;
  this->noImpact = false;
  this->worldConstraintsLocked = false;
  this->forcePushable = false;
  this->lastImpulse = vec3_origin;
  return this;
}


// ========================================================================
// __unwind$262920
// EA  : 0x827429E0
// RVA : 0x007429E0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_262920()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 272 + 292));
}


// ========================================================================
// __unwind$262921
// EA  : 0x82742A08
// RVA : 0x00742A08
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_262921()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 120));
}


// ========================================================================
// __unwind$262922
// EA  : 0x82742A34
// RVA : 0x00742A34
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_262922()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 136));
}


// ========================================================================
// __unwind$262923
// EA  : 0x82742A60
// RVA : 0x00742A60
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_262923()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 152));
}


// ========================================================================
// __unwind$262924
// EA  : 0x82742A8C
// RVA : 0x00742A8C
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_262924()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 168));
}


// ========================================================================
// __unwind$262925
// EA  : 0x82742AB8
// RVA : 0x00742AB8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_262925()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 184));
}


// ========================================================================
// __unwind$262926
// EA  : 0x82742AE4
// RVA : 0x00742AE4
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_262926()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 200));
}


// ========================================================================
// __unwind$262927
// EA  : 0x82742B10
// RVA : 0x00742B10
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_262927()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 216));
}


// ========================================================================
// __unwind$262928
// EA  : 0x82742B3C
// RVA : 0x00742B3C
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_262928()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 232));
}


// ========================================================================
// __unwind$262929
// EA  : 0x82742B68
// RVA : 0x00742B68
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_262929()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 272 + 292) + 248));
}


// ========================================================================
// ?AddFrameConstraints@idPhysics_AF@@AAAXXZ
// EA  : 0x82742B98
// RVA : 0x00742B98
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::AddFrameConstraints(idPhysics_AF *this)
{
  int num; // r3
  int v3; // r8
  int v4; // r7
  int numRows; // r30
  int v6; // r10
  idAFConstraint **list; // r9
  int v8; // r11
  idAFConstraint *v9; // r31
  idAFConstraint *v10; // r29
  int v11; // r6
  int v12; // r31
  int v13; // r11
  int v14; // r10
  int size; // r11
  int v16; // r30
  int v17; // r31

  if ( af_maxAuxiliaryConstraints.valueInteger > 0 )
  {
    num = this->auxiliaryConstraints.num;
    v3 = 0;
    v4 = 0;
    numRows = 0;
    v6 = 0;
    if ( num >= 2 )
    {
      list = this->auxiliaryConstraints.list;
      v8 = 0;
      do
      {
        v9 = list[v8];
        v6 += 2;
        v10 = list[v8 + 1];
        v8 += 2;
        v3 += v9->J1.numRows;
        v4 += v10->J1.numRows;
      }
      while ( v6 < num - 1 );
    }
    if ( v6 < num )
      numRows = this->auxiliaryConstraints.list[v6]->J1.numRows;
    v11 = this->frameConstraints.num;
    v12 = 0;
    v13 = v3 + v4 + numRows;
    if ( v11 > 0 )
    {
      v14 = 0;
      while ( 1 )
      {
        v13 += this->frameConstraints.list[v14]->J1.numRows;
        if ( v13 > af_maxAuxiliaryConstraints.valueInteger )
          break;
        ++v12;
        ++v14;
        if ( v12 >= v11 )
          goto LABEL_17;
      }
      idLib::Warning(fmt: "idPhysics_AF: more than %d auxiliary constraints", af_maxAuxiliaryConstraints.valueInteger);
      if ( v12 <= this->frameConstraints.size
        || idList<idNavSpline *,5>::Resize(
             this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->frameConstraints,
             newsize: v12) )
      {
        size = this->frameConstraints.size;
        if ( v12 < size )
          size = v12;
        this->frameConstraints.num = size;
      }
    }
  }
LABEL_17:
  v16 = 0;
  if ( this->frameConstraints.num > 0 )
  {
    v17 = 0;
    do
    {
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->auxiliaryConstraints,
        obj: (const encounterGroupRole_t *)&this->frameConstraints.list[v17]);
      ++v16;
      ++v17;
    }
    while ( v16 < this->frameConstraints.num );
  }
}


// ========================================================================
// ?RemoveFrameConstraints@idPhysics_AF@@AAAXXZ
// EA  : 0x82742D00
// RVA : 0x00742D00
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::RemoveFrameConstraints(idPhysics_AF *this)
{
  int num; // r11
  int v3; // r10
  idList<idAFConstraint *,71> *p_auxiliaryConstraints; // r3
  int v5; // r4
  idList<idVehicleState *,5> *p_frameConstraints; // r31

  num = this->frameConstraints.num;
  v3 = this->auxiliaryConstraints.num;
  p_auxiliaryConstraints = &this->auxiliaryConstraints;
  v5 = 0;
  if ( num <= v3 )
    v5 = v3 - num;
  idList<idObstacleBuffers *,5>::SetNum(this: (idList<int,37> *)p_auxiliaryConstraints, newNum: v5);
  p_frameConstraints = (idList<idVehicleState *,5> *)&this->frameConstraints;
  if ( p_frameConstraints->size < 0 )
    idList<idThread *,58>::Clear(this: p_frameConstraints);
  p_frameConstraints->num = __CFADD__(-p_frameConstraints->size, p_frameConstraints->size ^ 0x80000000)
                          ? 0
                          : p_frameConstraints->size;
}


// ========================================================================
// ?SetupContactConstraints@idPhysics_AF@@AAAXM@Z
// EA  : 0x82742D88
// RVA : 0x00742D88
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::SetupContactConstraints(idPhysics_AF *this, double timeStep)
{
  int v2; // r11
  int num; // r9
  double v5; // fp31
  idList<enum encounterGroupRole_t,5> *p_contactConstraints; // r27
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  int v13; // r4
  idAFConstraint_Contact *v14; // r3
  idAFConstraint_Contact *v15; // r3
  int v16; // r26
  int v17; // r29
  int v18; // r28
  double v19; // fp1
  contactInfo_t *list; // r11
  contactInfo_t *v21; // r6
  idAFBody **v22; // r9
  idAFConstraint_Contact *v23; // r3
  idAFBody *v24; // r4
  idAFBody *v25; // r5
  encounterGroupRole_t v26[4]; // [sp+50h] [-50h] BYREF

  num = this->contactConstraints.num;
  v26[0] = (encounterGroupRole_t)this->contacts.num;
  v2 = v26[0];
  v5 = (float)((float)1.0 / (float)timeStep);
  if ( v26[0] >= num )
  {
    p_contactConstraints = (idList<enum encounterGroupRole_t,5> *)&this->contactConstraints;
    do
    {
      v14 = (idAFConstraint_Contact *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x230u,
                                        tag: TAG_AF,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
      v26[0] = (encounterGroupRole_t)v14;
      if ( v14 != nullptr )
        v15 = idAFConstraint_Contact::idAFConstraint_Contact(
                this: v14,
                a2: v13,
                a3: v12,
                a4: v11,
                a5: v10,
                a6: v9,
                a7: v8,
                a8: v7);
      else
        v15 = nullptr;
      v26[0] = (encounterGroupRole_t)v15;
      idList<idAnimWebBlendTree *,5>::Append(this: p_contactConstraints, obj: v26);
      v2 = this->contacts.num;
    }
    while ( v2 >= this->contactConstraints.num );
  }
  v16 = 0;
  if ( v2 > 0 )
  {
    v17 = 0;
    v18 = 0;
    do
    {
      v19 = CONTACT_SEPARATION;
      this->contactConstraints.list[v17]->physics = this;
      list = this->contacts.list;
      v21 = &list[v18];
      if ( list[v18].entityNum == this->entityNumber )
      {
        v22 = this->bodies.list;
        v21 = &list[v18];
        v23 = this->contactConstraints.list[v17];
        v24 = v22[this->contactBodies.list[v17]];
        v25 = v22[list[v18].bodyId];
      }
      else
      {
        v25 = nullptr;
        v23 = this->contactConstraints.list[v17];
        v24 = this->bodies.list[this->contactBodies.list[v17]];
      }
      idAFConstraint_Contact::Setup(this: v23, b1: v24, b2: v25, c: v21, separation: v19, invTimeStep: v5);
      ++v16;
      ++v18;
      ++v17;
    }
    while ( v16 < this->contacts.num );
  }
}


// ========================================================================
// __unwind$263566
// EA  : 0x82742EEC
// RVA : 0x00742EEC
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_263566()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_AF);
}


// ========================================================================
// ?AddBody@idPhysics_AF@@QAAHPAVidAFBody@@@Z
// EA  : 0x82742F18
// RVA : 0x00742F18
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

int __fastcall idPhysics_AF::AddBody(
        idPhysics_AF *this,
        idAFBody *body,
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
        idAFBody *a14)
{
  idClipModel *clipModel; // r11
  idAFBody **v17; // r3
  const char *str; // r4
  int num; // r29

  clipModel = body->clipModel;
  a14 = body;
  if ( clipModel == nullptr )
    idLib::Error(fmt: "idPhysics_AF::AddBody: body '%s' has no clip model.", body->name.str);
  v17 = idList<idSaveGameProcessor *,5>::Find(this: &this->bodies, obj: &a14);
  str = body->name.str;
  if ( v17 != nullptr )
    idLib::Error(fmt: "idPhysics_AF::AddBody: body '%s' added twice.", str);
  if ( idPhysics_AF::GetBody(this, bodyName: str) != nullptr )
    idLib::Error(fmt: "idPhysics_AF::AddBody: a body with the name '%s' already exists.", body->name.str);
  num = this->bodies.num;
  body->clipModel->bodyId = num;
  if ( body->linearFriction < 0.0 )
  {
    body->linearFriction = this->linearFriction;
    body->angularFriction = this->angularFriction;
    body->contactFriction = this->contactFriction;
  }
  if ( body->bouncyness < 0.0 )
    body->bouncyness = this->bouncyness;
  if ( (*(_BYTE *)&body->fl & 0x80) == 0 )
    body->clipMask = this->clipMask;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->bodies,
    obj: (const encounterGroupRole_t *)&a14);
  this->changedAF = true;
  return num;
}


// ========================================================================
// ?AddConstraint@idPhysics_AF@@QAAXPAVidAFConstraint@@@Z
// EA  : 0x82743018
// RVA : 0x00743018
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::AddConstraint(
        idPhysics_AF *this,
        idAFConstraint *constraint,
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
        idAFConstraint *a14)
{
  int num; // r9
  idList<enum encounterGroupRole_t,5> *p_constraints; // r26
  int v18; // r10
  encounterGroupRole_t *list; // r8
  int v20; // r11
  idAFBody *body1; // r28
  idAFBody **p_body1; // r4
  idAFBody *body2; // r30

  num = this->constraints.num;
  a14 = constraint;
  p_constraints = (idList<enum encounterGroupRole_t,5> *)&this->constraints;
  v18 = 0;
  if ( num > 0 )
  {
    list = p_constraints->list;
    v20 = 0;
    do
    {
      if ( (idAFConstraint *)list[v20] == constraint )
        goto _LN38;
      ++v18;
      ++v20;
    }
    while ( v18 < num );
  }
  while ( idPhysics_AF::GetConstraint(this, constraintName: constraint->name.str) != nullptr )
  {
    idLib::Error(
      fmt: "idPhysics_AF::AddConstraint: a constraint with the name '%s' already exists.",
      constraint->name.str);
_LN38:
    if ( v18 >= 0 && &list[v18] != nullptr )
    {
      idLib::Error(fmt: "idPhysics_AF::AddConstraint: constraint '%s' added twice.", constraint->name.str);
      break;
    }
  }
  body1 = constraint->body1;
  p_body1 = &constraint->body1;
  if ( body1 == nullptr )
    idLib::Error(fmt: "idPhysics_AF::AddConstraint: body1 == NULL on constraint '%s'.", constraint->name.str);
  if ( idList<idSaveGameProcessor *,5>::Find(this: &this->bodies, obj: p_body1) == nullptr )
    idLib::Error(
      fmt: "idPhysics_AF::AddConstraint: body1 of constraint '%s' is not part of the articulated figure.",
      constraint->name.str);
  body2 = constraint->body2;
  if ( body2 != nullptr
    && idList<idSaveGameProcessor *,5>::Find(this: &this->bodies, obj: &constraint->body2) == nullptr )
  {
    idLib::Error(
      fmt: "idPhysics_AF::AddConstraint: body2 of constraint '%s' is not part of the articulated figure.",
      constraint->name.str);
  }
  if ( body1 == body2 )
    idLib::Error(
      fmt: "idPhysics_AF::AddConstraint: body1 and body2 of constraint '%s' are the same.",
      constraint->name.str);
  idList<idAnimWebBlendTree *,5>::Append(this: p_constraints, obj: (const encounterGroupRole_t *)&a14);
  constraint->physics = this;
  this->changedAF = true;
}


// ========================================================================
// ?AddFrameConstraint@idPhysics_AF@@QAAXPAVidAFConstraint@@@Z
// EA  : 0x82743160
// RVA : 0x00743160
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::AddFrameConstraint(
        idPhysics_AF *this,
        idAFConstraint *constraint,
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
        idAFConstraint *a14)
{
  a14 = constraint;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->frameConstraints,
    obj: (const encounterGroupRole_t *)&a14);
  constraint->physics = this;
}


// ========================================================================
// ?EvaluateConstraints@idPhysics_AF@@AAAXM@Z
// EA  : 0x827433F0
// RVA : 0x007433F0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::EvaluateConstraints(idPhysics_AF *this, double timeStep)
{
  int v3; // r28
  double v4; // fp31
  int v5; // r29
  idAFConstraint *v6; // r30
  int v7; // r29
  int v8; // r30
  int v9; // r29
  int v10; // r30
  int v11; // r29
  int v12; // r30
  idAFConstraint_Contact *v13; // r28
  int v14; // r29
  int v15; // r30
  idAFBody *v16; // r11
  idSpatialMat *primaryConstraint; // r10
  idAFConstraint_Contact *v18; // [sp+50h] [-40h] BYREF

  v3 = 0;
  v4 = (float)((float)1.0 / (float)timeStep);
  if ( this->primaryConstraints.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this->primaryConstraints.list[v5];
      v6->Evaluate(this: v6, a2: this, a3: v4);
      idSpatialMat::operator=(this: &v6->J, a: &v6->J2);
      ++v3;
      ++v5;
    }
    while ( v3 < this->primaryConstraints.num );
  }
  v7 = 0;
  if ( this->auxiliaryConstraints.num > 0 )
  {
    v8 = 0;
    do
    {
      this->auxiliaryConstraints.list[v8]->Evaluate(this: this->auxiliaryConstraints.list[v8], a2: this, a3: v4);
      ++v7;
      ++v8;
    }
    while ( v7 < this->auxiliaryConstraints.num );
  }
  v9 = 0;
  if ( this->frameConstraints.num > 0 )
  {
    v10 = 0;
    do
    {
      this->frameConstraints.list[v10]->Evaluate(this: this->frameConstraints.list[v10], a2: this, a3: v4);
      ++v9;
      ++v10;
    }
    while ( v9 < this->frameConstraints.num );
  }
  if ( this->addContactConstraints )
  {
    v11 = 0;
    if ( this->contacts.num > 0 )
    {
      v12 = 0;
      do
      {
        v18 = this->contactConstraints.list[v12];
        v13 = v18;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->frameConstraints,
          obj: (const encounterGroupRole_t *)&v18);
        ++v11;
        v13->physics = this;
        ++v12;
      }
      while ( v11 < this->contacts.num );
    }
  }
  v14 = 0;
  if ( this->bodies.num > 0 )
  {
    v15 = 0;
    do
    {
      v16 = this->bodies.list[v15];
      primaryConstraint = (idSpatialMat *)v16->primaryConstraint;
      if ( primaryConstraint != nullptr )
        idSpatialMat::Transpose(this: primaryConstraint + 6, dst: &v16->J);
      ++v14;
      ++v15;
    }
    while ( v14 < this->bodies.num );
  }
}


// ========================================================================
// ?AddContacts@idPhysics_AF@@AAAXPAVidAFBody@@AAUcontactsResult_t@@@Z
// EA  : 0x827435A0
// RVA : 0x007435A0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::AddContacts(idPhysics_AF *this, idAFBody *body, contactsResult_t *contactInfo)
{
  int v6; // r29
  contactInfo_t *contacts; // r31
  int bodyId; // r11
  idPhysicsCallbacks *callbacks; // r3
  int physicsId; // r4
  collide_t (__fastcall *Contact)(idPhysicsCallbacks *, const int, contactInfo_t *); // ctr
  int v12; // r3
  int v13; // [sp+50h] [-40h] BYREF

  v6 = 0;
  if ( contactInfo->numContacts > 0 )
  {
    contacts = contactInfo->contacts;
    do
    {
      bodyId = body->clipModel->bodyId;
      contacts->selfId = bodyId;
      callbacks = this->callbacks;
      physicsId = this->physicsId;
      Contact = callbacks->Contact;
      v13 = bodyId;
      v12 = Contact(this: callbacks, a2: physicsId, a3: contacts);
      if ( v12 != 2 )
      {
        if ( v12 == 1 )
        {
          this->current.atRest = true;
          this->comeToRest = true;
        }
        else
        {
          idList<contactInfo_t,77>::Append(this: &this->contacts, obj: contacts);
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->contactBodies,
            obj: (const encounterGroupRole_t *)&v13);
        }
      }
      ++v6;
      ++contacts;
    }
    while ( v6 < contactInfo->numContacts );
  }
}


// ========================================================================
// ?ResolveCollisions@idPhysics_AF@@AAAXM@Z
// EA  : 0x82743650
// RVA : 0x00743650
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::ResolveCollisions(idPhysics_AF *this, double timeStep, __int64 a3)
{
  unsigned __int64 v3; // r27
  char v6; // r22
  int v7; // r23
  idAFBody *v8; // r30
  unsigned __int64 index; // r11
  int v10; // r6
  unsigned int v11; // r11
  char v12; // r11
  bool v13; // zf
  unsigned __int64 v14; // r11
  idClip *clip; // r9
  trace_t v16; // [sp+50h] [-4A0h] BYREF
  contactsResult_t v17; // [sp+D0h] [-420h] BYREF

  LODWORD(v3) = 0;
  v6 = 0;
  v7 = 0;
  if ( this->bodies.num > 0 )
  {
    HIDWORD(v3) = 0;
    do
    {
      v8 = *(idAFBody **)((char *)this->bodies.list + HIDWORD(v3));
      index = v8->motionQuery.index;
      if ( (unsigned int)index < LODWORD(this->clip->collisionQueryFirstSubmittedIndex)
        || (unsigned int)index > *(_DWORD *)(HIDWORD(index) + 377220) )
      {
        v12 = 0;
      }
      else
      {
        v10 = 8 * ((index & 0xFFF) + ((2 * index) & 0x1FFE)) + HIDWORD(index);
        a3 = *(_QWORD *)(v10 + 278920);
        v11 = *(_DWORD *)(v10 + 278924);
        if ( v11 < (unsigned int)idCollisionQuery::finalResultsFirstSubmittedOffset
          || (v13 = v11 < (unsigned int)idCollisionQuery::finalResultsLastSubmittedOffset, v12 = 1, !v13) )
        {
          v12 = 0;
        }
      }
      if ( v12 != 0 )
      {
        if ( v6 == 0 )
        {
          ((void (__fastcall *)(idPhysics_AF *, _DWORD))this->ClearContacts)(a1: this, a2: HIDWORD(a3));
          if ( this->contactBodies.size < 0 )
            idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactBodies);
          v6 = 1;
          this->contactBodies.num = __CFADD__(-this->contactBodies.size, this->contactBodies.size ^ 0x80000000)
                                  ? 0
                                  : this->contactBodies.size;
        }
        v14 = v8->motionQuery.index;
        clip = this->clip;
        v8->motionQuery.index = v3;
        idCollisionModelManager::GetMotionContactsResult(
          this: collisionModelManager,
          result: &v16,
          contacts: &v17,
          query: &clip->collisionQueries[v14 & 0xFFF].query,
          peek: false);
        idPhysics::UpdateCollisionResidency(this: &this->idPhysics_DynamicBase, contact: &v16.c);
        idPhysics_AF::AddContacts(this, body: v8, contactInfo: &v17);
        idPhysics_AF::CollisionImpulse(this, body: v8, collision: &v16, timeStep);
      }
      ++v7;
      HIDWORD(v3) += 4;
    }
    while ( v7 < this->bodies.num );
  }
  if ( v6 != 0 )
  {
    this->current.pushVelocity.p[5] = 0.0;
    this->current.pushVelocity.p[4] = 0.0;
    this->current.pushVelocity.p[3] = 0.0;
    this->current.pushVelocity.p[2] = 0.0;
    this->current.pushVelocity.p[1] = 0.0;
    this->current.pushVelocity.p[0] = 0.0;
  }
  idPhysics_DynamicBase::AddContactPhysicsForContacts(this: &this->idPhysics_DynamicBase);
}


// ========================================================================
// ?EvaluateContacts@idPhysics_AF@@UAA_NXZ
// EA  : 0x82743840
// RVA : 0x00743840
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

BOOL __fastcall idPhysics_AF::EvaluateContacts(idPhysics_AF *this)
{
  __int64 v2; // r29
  int v3; // r23
  idClip *clip; // r11
  int v5; // r30
  __int64 v6; // r10
  int v7; // r30
  int v9; // [sp+8h] [-478h]
  const char *v10; // [sp+Ch] [-474h]
  int v11; // [sp+10h] [-470h]
  int v12; // [sp+14h] [-46Ch]
  int v13; // [sp+18h] [-468h]
  int v14; // [sp+1Ch] [-464h]
  int v15; // [sp+20h] [-460h]
  int v16; // [sp+24h] [-45Ch]
  int v17; // [sp+28h] [-458h]
  int v18; // [sp+2Ch] [-454h]
  int v19; // [sp+30h] [-450h]
  int v20; // [sp+34h] [-44Ch]
  int v21; // [sp+38h] [-448h]
  int v22; // [sp+3Ch] [-444h]
  int v23; // [sp+40h] [-440h]
  int v24; // [sp+44h] [-43Ch]
  int v25; // [sp+48h] [-438h]
  int v26; // [sp+4Ch] [-434h]
  int v27; // [sp+50h] [-430h]
  int v28; // [sp+58h] [-428h]
  int v29; // [sp+60h] [-420h]
  char v30; // [sp+70h] [-410h] BYREF
  contactsResult_t v31; // [sp+80h] [-400h] BYREF

  this->ClearContacts(this);
  if ( this->contactBodies.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactBodies);
  LODWORD(v2) = 0;
  v3 = 0;
  this->contactBodies.num = __CFADD__(-this->contactBodies.size, this->contactBodies.size ^ 0x80000000)
                          ? 0
                          : this->contactBodies.size;
  if ( this->bodies.num > 0 )
  {
    HIDWORD(v2) = 0;
    do
    {
      clip = this->clip;
      v5 = *(int *)((char *)this->bodies.list + HIDWORD(v2));
      v6 = *(_QWORD *)(v5 + 512);
      if ( (unsigned int)v6 >= HIDWORD(v6) && (unsigned int)v6 <= LODWORD(clip->collisionQueryLastAllocedIndex) )
        clip->collisionQueries[v6 & 0xFFF].type = QUERY_CANCELED;
      *(_QWORD *)(v5 + 512) = v2;
      if ( *(_DWORD *)(v5 + 24) != 0 )
      {
        idClip::Contacts(
          this: (idClip *)&v30,
          result: this->clip,
          a3: &v31,
          start: (const idVec3 *)(*(_DWORD *)(v5 + 20) + 32),
          dir: &vec3_origin,
          depth: 2.0,
          clipModel: (const idClipModel *)this->passEntityNum,
          startAxis: *(const idMat3 **)(v5 + 20),
          clipMask: *(_DWORD *)(v5 + 20) + 44,
          passEntityNumber: v9,
          userName: v10,
          a12: v11,
          a13: v12,
          a14: v13,
          a15: v14,
          a16: v15,
          a17: v16,
          a18: v17,
          a19: v18,
          a20: v19,
          a21: v20,
          a22: v21,
          a23: v22,
          a24: v23,
          a25: v24,
          a26: v25,
          a27: v26,
          a28: v27,
          a29: *(const idBounds **)(v5 + 24),
          a30: v28,
          a31: (const idClipModel *)this->passEntityNum,
          a32: v29,
          a33: 0);
        idPhysics_AF::AddContacts(this, body: (idAFBody *)v5, contactInfo: &v31);
      }
      ++v3;
      HIDWORD(v2) += 4;
    }
    while ( v3 < this->bodies.num );
  }
  if ( this->constraints.num > 0 )
  {
    v7 = 0;
    do
    {
      this->constraints.list[v7]->CancelCollisionQueries(this: this->constraints.list[v7]);
      LODWORD(v2) = v2 + 1;
      ++v7;
    }
    while ( (int)v2 < this->constraints.num );
  }
  idPhysics_DynamicBase::AddContactPhysicsForContacts(this: &this->idPhysics_DynamicBase);
  return this->contacts.num != 0;
}


// ========================================================================
// ?Translate@idPhysics_AF@@UAAXABVidVec3@@H@Z
// EA  : 0x827439D0
// RVA : 0x007439D0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::Translate(idPhysics_AF *this, const idVec3 *translation, __int64 id)
{
  int v5; // r30
  int v6; // r29
  int v7; // r30
  int v8; // r29
  int v9; // r30
  idClipModel *clipModel; // r3
  double v11; // fp7
  double v12; // fp6
  idVec3 v13; // [sp+50h] [-40h] BYREF

  v5 = HIDWORD(id);
  idPhysics_AF::ResolveCollisions(this, timeStep: this->lastTimeStep, a3: id);
  if ( v5 < 0 || v5 >= this->bodies.num )
  {
    if ( !this->worldConstraintsLocked )
    {
      v6 = 0;
      if ( this->constraints.num > 0 )
      {
        v7 = 0;
        do
        {
          this->constraints.list[v7]->Translate(this: this->constraints.list[v7], a2: translation);
          ++v6;
          ++v7;
        }
        while ( v6 < this->constraints.num );
      }
    }
    v8 = 0;
    if ( this->bodies.num > 0 )
    {
      v9 = 0;
      do
      {
        clipModel = this->bodies.list[v9]->clipModel;
        v11 = (float)(clipModel->origin.y + translation->y);
        v12 = (float)(clipModel->origin.z + translation->z);
        v13.x = clipModel->origin.x + translation->x;
        v13.y = v11;
        v13.z = v12;
        idClipModel::SetLinkedPosition(this: clipModel, newOrigin: &v13, newAxis: &clipModel->axis);
        ++v8;
        ++v9;
      }
      while ( v8 < this->bodies.num );
    }
  }
  idPhysics_AF::UpdateClipModels(this);
}


// ========================================================================
// ?Rotate@idPhysics_AF@@UAAXABVidRotation@@H@Z
// EA  : 0x82743AD8
// RVA : 0x00743AD8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::Rotate(idPhysics_AF *this, idRotation *rotation, __int64 id)
{
  int v5; // r31
  int v6; // r29
  int v7; // r31
  int v8; // r27
  int v9; // r29
  idAFBody *v10; // r31
  idVec3 *p_vec; // r10
  int v12; // ctr
  float *p_z; // r11
  const idMat3 *v14; // r3
  idRotation v15; // [sp+50h] [-70h] BYREF

  v5 = HIDWORD(id);
  idPhysics_AF::ResolveCollisions(this, timeStep: this->lastTimeStep, a3: id);
  if ( v5 < 0 || v5 >= this->bodies.num )
  {
    if ( !this->worldConstraintsLocked )
    {
      v6 = 0;
      if ( this->constraints.num > 0 )
      {
        v7 = 0;
        do
        {
          this->constraints.list[v7]->Rotate(this: this->constraints.list[v7], a2: rotation);
          ++v6;
          ++v7;
        }
        while ( v6 < this->constraints.num );
      }
    }
    v8 = 0;
    if ( this->bodies.num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = this->bodies.list[v9];
        idRotation::operator*(this: &v15, result: rotation, v: &v10->clipModel->origin);
        idClipModel::SetLinkedPosition(this: v10->clipModel, newOrigin: &v15.origin, newAxis: &v10->clipModel->axis);
        p_vec = &v15.vec;
        v12 = 9;
        p_z = &v10->clipModel->origin.z;
        do
        {
          ++p_z;
          p_vec = (idVec3 *)((char *)p_vec + 4);
          p_vec->x = *p_z;
          --v12;
        }
        while ( v12 != 0 );
        v14 = idRotation::ToMat3(this: rotation);
        idMat3::operator*=(this: (idMat3 *)&v15.vec.y, a: v14);
        idMat3::OrthoNormalizeSelf(this: (idMat3 *)&v15.vec.y);
        idMat3::FixDenormals(this: (idMat3 *)&v15.vec.y);
        idClipModel::SetLinkedPosition(
          this: v10->clipModel,
          newOrigin: &v10->clipModel->origin,
          newAxis: (const idMat3 *)&v15.vec.y);
        ++v8;
        ++v9;
      }
      while ( v8 < this->bodies.num );
    }
  }
  idPhysics_AF::UpdateClipModels(this);
}


// ========================================================================
// ?Shutdown@idPhysics_AF@@QAAXXZ
// EA  : 0x82743D78
// RVA : 0x00743D78
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::Shutdown(idPhysics_AF *this)
{
  __int64 v1; // r28
  int i; // r6
  idClip *clip; // r11
  unsigned __int64 collisionQueryFirstSubmittedIndex; // r8
  __int64 v6; // r10
  int v7; // r29
  int v8; // r30
  int v9; // r29
  int v10; // r30
  idAFBody *v11; // r3
  int v12; // r29
  int v13; // r30
  idAFConstraint *v14; // r3
  int v15; // r29
  int v16; // r30
  idAFConstraint_Contact *v17; // r3
  idAFBody **list; // r4
  idAFConstraint **v19; // r4
  idAFConstraint_Contact **v20; // r4
  idAFBody *masterBody; // r3

  LODWORD(v1) = 0;
  for ( i = 0; i < this->bodies.num; *(_QWORD *)(HIDWORD(collisionQueryFirstSubmittedIndex) + 512) = v1 )
  {
    clip = this->clip;
    collisionQueryFirstSubmittedIndex = clip->collisionQueryFirstSubmittedIndex;
    v6 = *(_QWORD *)(HIDWORD(collisionQueryFirstSubmittedIndex) + 512);
    if ( (unsigned int)v6 >= (unsigned int)collisionQueryFirstSubmittedIndex )
    {
      collisionQueryFirstSubmittedIndex = clip->collisionQueryLastAllocedIndex;
      if ( (unsigned int)v6 <= (unsigned int)collisionQueryFirstSubmittedIndex )
        clip->collisionQueries[v6 & 0xFFF].type = QUERY_CANCELED;
    }
    ++i;
  }
  v7 = 0;
  if ( this->constraints.num > 0 )
  {
    v8 = 0;
    do
    {
      this->constraints.list[v8]->CancelCollisionQueries(this: this->constraints.list[v8]);
      ++v7;
      ++v8;
    }
    while ( v7 < this->constraints.num );
  }
  idList<idAFTree *,71>::DeleteContents(this: &this->trees);
  v9 = 0;
  if ( this->bodies.num > 0 )
  {
    v10 = 0;
    do
    {
      v11 = this->bodies.list[v10];
      if ( v11 != nullptr )
        ((void (__fastcall *)(idAFBody *, int))v11->dtr_idAFBody)(a1: v11, a2: 1);
      ++v9;
      ++v10;
    }
    while ( v9 < this->bodies.num );
  }
  v12 = 0;
  if ( this->constraints.num > 0 )
  {
    v13 = 0;
    do
    {
      v14 = this->constraints.list[v13];
      if ( v14 != nullptr )
        ((void (__fastcall *)(idAFConstraint *, int))v14->dtr_idAFConstraint)(a1: v14, a2: 1);
      ++v12;
      ++v13;
    }
    while ( v12 < this->constraints.num );
  }
  v15 = 0;
  if ( this->contactConstraints.num > 0 )
  {
    v16 = 0;
    do
    {
      v17 = this->contactConstraints.list[v16];
      if ( v17 != nullptr )
        ((void (__fastcall *)(idAFConstraint_Contact *, int))v17->dtr_idAFConstraint)(a1: v17, a2: 1);
      ++v15;
      ++v16;
    }
    while ( v15 < this->contactConstraints.num );
  }
  if ( this->bodies.listStatic == 0 || this->bodies.listStatic == 2 )
  {
    list = this->bodies.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->bodies.list = nullptr;
    this->bodies.size = 0;
  }
  this->bodies.num = 0;
  if ( this->constraints.listStatic == 0 || this->constraints.listStatic == 2 )
  {
    v19 = this->constraints.list;
    if ( v19 != nullptr )
      idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
    this->constraints.list = nullptr;
    this->constraints.size = 0;
  }
  this->constraints.num = 0;
  if ( this->contactConstraints.listStatic == 0 || this->contactConstraints.listStatic == 2 )
  {
    v20 = this->contactConstraints.list;
    if ( v20 != nullptr )
      idMem::Free(this: &mem, ptr: v20, align: ALIGN_16);
    this->contactConstraints.list = nullptr;
    this->contactConstraints.size = 0;
  }
  this->contactConstraints.num = 0;
  masterBody = this->masterBody;
  if ( masterBody != nullptr )
  {
    ((void (__fastcall *)(idAFBody *, int))masterBody->dtr_idAFBody)(a1: masterBody, a2: 1);
    this->masterBody = nullptr;
  }
}


// ========================================================================
// ?BuildTrees@idPhysics_AF@@AAAXXZ
// EA  : 0x82744028
// RVA : 0x00744028
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::BuildTrees(idPhysics_AF *this)
{
  idList<idAFTree *,71> *p_trees; // r19
  int num; // r9
  int v4; // r27
  int v5; // r28
  idAFBody *v6; // r30
  void **p_list; // r29
  void *v8; // r4
  idAFBody **list; // r4
  double mass; // fp0
  int v11; // r27
  int v12; // r28
  idAFConstraint *v13; // r30
  idAFBody **p_body1; // r29
  idAFBody *body2; // r10
  idAFBody *parent; // r11
  idAFBody *i; // r9
  idAFBody *v18; // r10
  idAFBody *j; // r11
  idList<enum encounterGroupRole_t,5> *p_auxiliaryConstraints; // r3
  int v21; // r28
  int v22; // r29
  idList<enum encounterGroupRole_t,5> *v23; // r3
  idList<enum encounterGroupRole_t,5> *v24; // r30
  int listStatic; // r11
  encounterGroupRole_t *v26; // r4
  int v27; // r28
  int v28; // r29
  const encounterGroupRole_t *v29; // r4
  int v30; // r11
  idList<enum encounterGroupRole_t,5> **k; // r30
  int v32; // r30
  const char *v33; // r3
  __int64 v34; // r8
  __int64 v35; // r6
  int v36; // r27
  __int64 v37; // r10
  int v38; // r25
  idAFTree *v39; // r28
  va *v40; // r3
  int v41; // r30
  int v42; // r29
  char *data; // r4
  int v44; // r29
  int v45; // r30
  int v46; // r28
  int v47; // r29
  idList<enum encounterGroupRole_t,5> *v48; // r3
  idList<enum encounterGroupRole_t,5> *v49; // r30
  int v50; // r11
  encounterGroupRole_t *v51; // r4
  int v52; // r28
  int v53; // r29
  idAFConstraint *v54; // r30
  idAFBody *v55; // r10
  BOOL selfCollision; // r11
  int v57; // r3
  int m; // r4
  idAFBody *v59; // r10
  idClipModel *clipModel; // r11
  int v61; // r7
  int v62; // r6
  int v63; // r8
  idAFConstraint *v64; // r11
  idAFBody *v65; // r9
  idAFBody *body1; // r11
  int v67; // r6
  int v68; // r7
  int v69; // r8
  idAFBody *v70; // r11
  int v71; // r10
  idAFConstraint *v72; // r9
  int v73; // [sp+8h] [-10F8h]
  int v74; // [sp+Ch] [-10F4h]
  int v75; // [sp+10h] [-10F0h]
  int v76; // [sp+14h] [-10ECh]
  int v77; // [sp+18h] [-10E8h]
  int v78; // [sp+1Ch] [-10E4h]
  void *v79; // [sp+50h] [-10B0h] BYREF
  int v80; // [sp+54h] [-10ACh]
  idStr v81; // [sp+60h] [-10A0h] BYREF
  va v82; // [sp+80h] [-1080h] BYREF

  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contacts);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->primaryConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->auxiliaryConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->frameConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactBodies);
  p_trees = &this->trees;
  idList<idAFTree *,71>::DeleteContents(this: &this->trees);
  num = this->bodies.num;
  v4 = 0;
  this->totalMass = 0.0;
  if ( num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this->bodies.list[v5];
      p_list = (void **)&v6->constraints.list;
      v6->parent = nullptr;
      v6->primaryConstraint = nullptr;
      if ( v6->constraints.size < 0 )
      {
        if ( v6->constraints.listStatic == 0 || v6->constraints.listStatic == 2 )
        {
          v8 = *p_list;
          if ( *p_list != nullptr )
          {
            v79 = *p_list;
            idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
          }
          *p_list = nullptr;
          v6->constraints.size = 0;
        }
        v6->constraints.num = 0;
      }
      v6->constraints.num = __CFADD__(-v6->constraints.size, v6->constraints.size ^ 0x80000000)
                          ? 0
                          : v6->constraints.size;
      if ( v6->children.listStatic == 0 || v6->children.listStatic == 2 )
      {
        list = v6->children.list;
        if ( list != nullptr )
        {
          v79 = v6->children.list;
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        }
        v6->children.list = nullptr;
        v6->children.size = 0;
      }
      v6->children.num = 0;
      mass = v6->mass;
      v6->tree = nullptr;
      this->totalMass = (float)mass + this->totalMass;
      ++v4;
      ++v5;
    }
    while ( v4 < this->bodies.num );
  }
  if ( af_useLinearTime.valueInteger != 0 )
  {
    v11 = 0;
    if ( this->constraints.num > 0 )
    {
      v12 = 0;
      do
      {
        v13 = this->constraints.list[v12];
        p_body1 = &v13->body1;
        v79 = v13;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&v13->body1->constraints,
          obj: (const encounterGroupRole_t *)&v79);
        body2 = v13->body2;
        if ( body2 != nullptr )
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&body2->constraints,
            obj: (const encounterGroupRole_t *)&v79);
        if ( (*p_body1)->primaryConstraint != nullptr || (*(_BYTE *)&v13->fl & 0x80) == 0 || v13->body2 == nullptr )
          goto LABEL_30;
        parent = (*p_body1)->parent;
        for ( i = *p_body1; parent != nullptr; parent = parent->parent )
          i = parent;
        v18 = v13->body2;
        for ( j = v18->parent; j != nullptr; j = j->parent )
          v18 = j;
        if ( i == v18 )
        {
LABEL_30:
          p_auxiliaryConstraints = (idList<enum encounterGroupRole_t,5> *)&this->auxiliaryConstraints;
          *(_BYTE *)&v13->fl &= ~0x10u;
        }
        else
        {
          (*p_body1)->primaryConstraint = v13;
          (*p_body1)->parent = v13->body2;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&v13->body2->children,
            obj: (const encounterGroupRole_t *)&v13->body1);
          p_auxiliaryConstraints = (idList<enum encounterGroupRole_t,5> *)&this->primaryConstraints;
          *(_BYTE *)&v13->fl |= 0x10u;
          v13->firstIndex = 0;
        }
        idList<idAnimWebBlendTree *,5>::Append(this: p_auxiliaryConstraints, obj: (const encounterGroupRole_t *)&v79);
        ++v11;
        ++v12;
      }
      while ( v11 < this->constraints.num );
    }
    v21 = 0;
    if ( this->bodies.num > 0 )
    {
      v22 = 0;
      do
      {
        if ( this->bodies.list[v22]->parent == nullptr )
        {
          v23 = (idList<enum encounterGroupRole_t,5> *)idMem::AllocWithLocation(
                                                         this: &mem,
                                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                         size: 0x10u,
                                                         tag: TAG_AF,
                                                         zeroBuffer: false,
                                                         align: ALIGN_16,
                                                         heap: HEAP_DEFAULTHEAP);
          if ( v23 != nullptr )
          {
            v23->granularity = 0;
            v24 = v23;
            v23->memTag = 71;
            v23->listStatic = 0;
            v23->list = nullptr;
            v23->size = 0;
            v23->num = 0;
          }
          else
          {
            v24 = nullptr;
          }
          listStatic = v24->listStatic;
          v79 = v24;
          if ( listStatic == 0 || listStatic == 2 )
          {
            v26 = v24->list;
            if ( v24->list != nullptr )
            {
              v80 = (int)v24->list;
              idMem::Free(this: &mem, ptr: v26, align: ALIGN_16);
            }
            v24->list = nullptr;
            v24->size = 0;
          }
          v24->num = 0;
          idList<idAnimWebBlendTree *,5>::Append(this: v24, obj: (const encounterGroupRole_t *)&this->bodies.list[v22]);
          this->bodies.list[v22]->tree = (idAFTree *)v24;
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->trees,
            obj: (const encounterGroupRole_t *)&v79);
        }
        ++v21;
        ++v22;
      }
      while ( v21 < this->bodies.num );
    }
    v27 = 0;
    if ( this->bodies.num > 0 )
    {
      v28 = 0;
      do
      {
        v29 = (const encounterGroupRole_t *)&this->bodies.list[v28];
        v30 = *(_DWORD *)(*v29 + 176);
        if ( v30 != 0 )
        {
          for ( k = (idList<enum encounterGroupRole_t,5> **)(v30 + 216);
                *(_DWORD *)(v30 + 216) == 0;
                k = (idList<enum encounterGroupRole_t,5> **)(v30 + 216) )
          {
            v30 = *(_DWORD *)(v30 + 176);
          }
          idList<idAnimWebBlendTree *,5>::Append(this: *k, obj: v29);
          this->bodies.list[v28]->tree = (idAFTree *)*k;
        }
        ++v27;
        ++v28;
      }
      while ( v27 < this->bodies.num );
    }
    v80 = this->trees.num;
    v32 = v80;
    if ( v80 > 1 )
    {
      v33 = this->callbacks->GetName(this: this->callbacks);
      idLib::Warning(fmt: "Articulated figure has multiple separate tree structures( %d ) for entity '%s'", v32, v33);
      v36 = 0;
      if ( this->trees.num > 0 )
      {
        LODWORD(v37) = &unk_821C0000;
        HIDWORD(v37) = &unk_821F0000;
        LODWORD(v34) = &unk_821F0000;
        v38 = 0;
        do
        {
          HIDWORD(v35) = v36;
          v39 = p_trees->list[v38];
          v40 = va::va(
                  this: &v82,
                  fmt: "AF Tree %d: ",
                  a3: v35,
                  a4: v34,
                  a5: v37,
                  a6: v73,
                  a7: v74,
                  a8: v75,
                  a9: v76,
                  a10: v77,
                  a11: v78);
          idStr::idStr(this: &v81, text: v40);
          v41 = 0;
          if ( v39->sortedBodies.num > 0 )
          {
            v42 = 0;
            do
            {
              data = " -> ";
              if ( v41 <= 0 )
                data = v81.data;
              idLib::Printf(fmt: "%s%s", data, v39->sortedBodies.list[v42]->name.str);
              ++v41;
              ++v42;
            }
            while ( v41 < v39->sortedBodies.num );
          }
          idLib::Printf(fmt: "\n");
          idStr::FreeData(this: &v81);
          ++v36;
          ++v38;
        }
        while ( v36 < this->trees.num );
      }
    }
    v44 = 0;
    if ( this->trees.num > 0 )
    {
      v45 = 0;
      do
      {
        idAFTree::SortBodies(this: p_trees->list[v45]);
        ++v44;
        ++v45;
      }
      while ( v44 < this->trees.num );
    }
  }
  else
  {
    v46 = 0;
    if ( this->bodies.num > 0 )
    {
      v47 = 0;
      do
      {
        v48 = (idList<enum encounterGroupRole_t,5> *)idMem::AllocWithLocation(
                                                       this: &mem,
                                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                       size: 0x10u,
                                                       tag: TAG_AF,
                                                       zeroBuffer: false,
                                                       align: ALIGN_16,
                                                       heap: HEAP_DEFAULTHEAP);
        if ( v48 != nullptr )
        {
          v48->granularity = 0;
          v49 = v48;
          v48->memTag = 71;
          v48->listStatic = 0;
          v48->list = nullptr;
          v48->size = 0;
          v48->num = 0;
        }
        else
        {
          v49 = nullptr;
        }
        v50 = v49->listStatic;
        v79 = v49;
        if ( v50 == 0 || v50 == 2 )
        {
          v51 = v49->list;
          if ( v49->list != nullptr )
          {
            v80 = (int)v49->list;
            idMem::Free(this: &mem, ptr: v51, align: ALIGN_16);
          }
          v49->list = nullptr;
          v49->size = 0;
        }
        v49->num = 0;
        idList<idAnimWebBlendTree *,5>::Append(this: v49, obj: (const encounterGroupRole_t *)&this->bodies.list[v47]);
        this->bodies.list[v47]->tree = (idAFTree *)v49;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->trees,
          obj: (const encounterGroupRole_t *)&v79);
        ++v46;
        ++v47;
      }
      while ( v46 < this->bodies.num );
    }
    v52 = 0;
    if ( this->constraints.num > 0 )
    {
      v53 = 0;
      do
      {
        v54 = this->constraints.list[v53];
        v79 = v54;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&v54->body1->constraints,
          obj: (const encounterGroupRole_t *)&v79);
        v55 = v54->body2;
        if ( v55 != nullptr )
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&v55->constraints,
            obj: (const encounterGroupRole_t *)&v79);
        *(_BYTE *)&v54->fl &= ~0x10u;
        idList<idAnimWebBlendTree *,5>::Append(
          this: (idList<enum encounterGroupRole_t,5> *)&this->auxiliaryConstraints,
          obj: (const encounterGroupRole_t *)&v79);
        ++v52;
        ++v53;
      }
      while ( v52 < this->constraints.num );
    }
  }
  selfCollision = this->selfCollision;
  this->passEntityNum = 0x1FFF;
  if ( !selfCollision || af_skipSelfCollision.valueInteger != 0 )
  {
    v67 = 0;
    if ( this->bodies.num > 0 )
    {
      v68 = 0;
      do
      {
        v69 = 0;
        v70 = this->bodies.list[v68];
        v70->clipModel->bodyMask = -1;
        if ( v70->constraints.num > 0 )
        {
          v71 = 0;
          do
          {
            v72 = v70->constraints.list[v71];
            if ( (*(_BYTE *)&v72->fl & 0x20) != 0 && v72->body2 == nullptr )
              this->passEntityNum = 8190;
            ++v69;
            ++v71;
          }
          while ( v69 < v70->constraints.num );
        }
        ++v67;
        ++v68;
      }
      while ( v67 < this->bodies.num );
    }
  }
  else
  {
    v57 = 0;
    if ( this->bodies.num > 0 )
    {
      for ( m = 0; ; ++m )
      {
        v59 = this->bodies.list[m];
        clipModel = v59->clipModel;
        if ( (*(_BYTE *)&v59->fl & 0x40) != 0 )
          break;
        clipModel->bodyMask = -1;
LABEL_98:
        if ( ++v57 >= this->bodies.num )
          return;
      }
      v61 = 0;
      v62 = 1 << clipModel->bodyId;
      if ( v59->constraints.num <= 0 )
      {
LABEL_97:
        v59->clipModel->bodyMask = v62;
        goto LABEL_98;
      }
      v63 = 0;
      while ( 1 )
      {
        v64 = v59->constraints.list[v63];
        if ( (*(_BYTE *)&v64->fl & 0x20) != 0 )
        {
          v65 = v64->body2;
          if ( v65 != nullptr )
          {
            body1 = v64->body1;
            if ( body1 == v59 )
            {
              body1 = v65;
LABEL_95:
              v62 |= 1 << body1->clipModel->bodyId;
              goto LABEL_96;
            }
            if ( v65 == v59 )
              goto LABEL_95;
          }
          else
          {
            this->passEntityNum = 8190;
          }
        }
LABEL_96:
        ++v61;
        ++v63;
        if ( v61 >= v59->constraints.num )
          goto LABEL_97;
      }
    }
  }
}


// ========================================================================
// __unwind$264786
// EA  : 0x82744894
// RVA : 0x00744894
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_264786()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4352 + 4224), tag: TAG_AF);
}


// ========================================================================
// __unwind$264787
// EA  : 0x827448C0
// RVA : 0x007448C0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_264787()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 96));
}


// ========================================================================
// __unwind$264788
// EA  : 0x827448E8
// RVA : 0x007448E8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_264788()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4352 + 4228), tag: TAG_AF);
}


// ========================================================================
// ?AddNoclipBody@idPhysics_AF@@QAA_NH@Z
// EA  : 0x82744918
// RVA : 0x00744918
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

int __fastcall idPhysics_AF::AddNoclipBody(idPhysics_AF *this, int bodyId)
{
  idAFBody *v4; // r31
  idPhysics_AF::noclipBodyInfo_t *v5; // r3
  unsigned __int64 v6; // r11
  idAFBody::afBodyFlags_t fl; // r8

  if ( this->noclipBodies.num >= this->noclipBodies.size )
    return 0;
  if ( bodyId < 0 || bodyId >= this->bodies.num )
  {
    idLib::Warning(fmt: "GetBody: no body with id %d exists", bodyId);
    return 0;
  }
  else
  {
    v4 = this->bodies.list[bodyId];
    if ( v4 == nullptr )
      return 0;
    v5 = idList<idPhysics_AF::noclipBodyInfo_t,5>::Alloc(this: &this->noclipBodies);
    HIDWORD(v6) = v4->clipMask;
    LODWORD(v6) = 0;
    v5->originalClipMask = HIDWORD(v6);
    v5->bodyId = bodyId;
    v5->query.index = v6;
    fl = v4->fl;
    v4->clipMask = 0;
    v4->fl = (idAFBody::afBodyFlags_t)(*(_BYTE *)&fl | 0x80);
    return 1;
  }
}


// ========================================================================
// ??1idPhysics_AF@@UAA@XZ
// EA  : 0x827449E0
// RVA : 0x007449E0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __fastcall idPhysics_AF::~idPhysics_AF(idPhysics_AF *this)
{
  idLCP *lcp; // r3

  this->__vftable = (idPhysics_AF_vtbl *)&idPhysics_AF::`vftable';
  idPhysics_AF::Shutdown(this);
  lcp = this->lcp;
  if ( lcp != nullptr )
    ((void (__fastcall *)(idLCP *, int))lcp->dtr_idLCP)(a1: lcp, a2: 1);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->noclipBodies);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactBodies);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->contactConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->frameConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->auxiliaryConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->primaryConstraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->constraints);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->bodies);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->trees);
  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: &this->idPhysics_DynamicBase);
}


// ========================================================================
// __unwind$265504
// EA  : 0x82744A98
// RVA : 0x00744A98
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_265504()
{
  int v0; // r12

  idPhysics_DynamicBase::~idPhysics_DynamicBase(this: *(idPhysics_DynamicBase **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$265505
// EA  : 0x82744AC0
// RVA : 0x00744AC0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_265505()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 120));
}


// ========================================================================
// __unwind$265506
// EA  : 0x82744AEC
// RVA : 0x00744AEC
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_265506()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$265507
// EA  : 0x82744B18
// RVA : 0x00744B18
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_265507()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 152));
}


// ========================================================================
// __unwind$265508
// EA  : 0x82744B44
// RVA : 0x00744B44
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_265508()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 168));
}


// ========================================================================
// __unwind$265509
// EA  : 0x82744B70
// RVA : 0x00744B70
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_265509()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 184));
}


// ========================================================================
// __unwind$265510
// EA  : 0x82744B9C
// RVA : 0x00744B9C
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_265510()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 200));
}


// ========================================================================
// __unwind$265511
// EA  : 0x82744BC8
// RVA : 0x00744BC8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_265511()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 216));
}


// ========================================================================
// __unwind$265512
// EA  : 0x82744BF4
// RVA : 0x00744BF4
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_265512()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 232));
}


// ========================================================================
// __unwind$265513
// EA  : 0x82744C20
// RVA : 0x00744C20
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void _unwind_265513()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 248));
}


// ========================================================================
// ?Evaluate@idPhysics_AF@@UAA_NHH@Z
// EA  : 0x82744C50
// RVA : 0x00744C50
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

int __fastcall idPhysics_AF::Evaluate(idPhysics_AF *this, unsigned int timeStepMSec, int endTimeMSec)
{
  __int64 v3; // r21
  __int64 v4; // r11
  double v5; // fp31
  double v8; // fp13
  double v9; // fp9
  idClipModel *clipModel; // r10
  char v11; // r11
  unsigned int LastError; // r3
  __int64 v13; // r3
  __int64 v14; // r6
  __int64 v15; // r11
  __int64 v16; // r11
  int v17; // r9
  int v18; // r8
  idAFBody *v19; // r11
  float *v20; // r10
  idPhysics_AF *v21; // r3
  idPhysicsCallbacks *callbacks; // r29
  const char *v23; // r28
  const char *v24; // r3
  int v25; // r26
  int v26; // r27
  int v27; // r10
  int v28; // r11
  idAFConstraint *v29; // r9
  int v30; // r10
  int v31; // r11
  idAFConstraint *v32; // r9
  double clockTicks; // fp30
  __int64 v34; // r3
  double v35; // fp29
  double v36; // fp30
  __int64 v37; // r3
  double v38; // fp28
  double v39; // fp29
  __int64 v40; // r3
  double v41; // fp27
  double v42; // fp28
  __int64 v43; // r3
  double v44; // fp26
  double v45; // fp27
  __int64 v46; // r3
  double v47; // fp25
  double v48; // fp26
  __int128 v49; // r4
  double v50; // fp31
  double v51; // fp30
  __int64 v52; // r3
  double v53; // fp29
  double v54; // fp30
  __int64 v55; // r3
  double v56; // fp28
  double v57; // fp29
  __int64 v58; // r3
  double v59; // fp27
  double v60; // fp28
  __int64 v61; // r3
  double v62; // fp26
  double v63; // fp27
  __int64 v64; // r3
  double v65; // fp25
  double v66; // fp26
  __int64 v67; // r3
  double v68; // r5
  int num; // r11
  int v70; // r10
  idList<idAFConstraint *,71> *p_auxiliaryConstraints; // r30
  int v72; // r30
  int size; // r11
  idList<idAFConstraint *,71> *p_frameConstraints; // r30
  idVec3 v76[2]; // [sp+68h] [-E8h] BYREF
  idMat3 v77[2]; // [sp+80h] [-D0h] BYREF

  HIDWORD(v4) = &unk_82390000;
  this->endTime = endTimeMSec;
  v5 = (float)__SPAIR64__(&unk_82390000, endTimeMSec);
  v8 = (float)((float)__SPAIR64__(&unk_82390000, endTimeMSec) * (float)0.001);
  if ( this->timeScaleRampStart >= v8 || this->timeScaleRampEnd <= v8 )
  {
    if ( af_timeScale.valueFloat == 1.0 )
      v9 = (float)(this->timeScale * (float)__SPAIR64__(0x82000000, timeStepMSec));
    else
      v9 = (float)((float)__SPAIR64__(0x82000000, timeStepMSec) * af_timeScale.valueFloat);
    this->timeStep = (float)v9 * (float)0.001;
  }
  else
  {
    LODWORD(v4) = timeStepMSec;
    this->timeStep = (float)((float)((float)((float)((float)__SPAIR64__(&unk_82390000, endTimeMSec) * (float)0.001)
                                           - this->timeScaleRampStart)
                                   * (float)v4)
                           * (float)0.001)
                   / (float)(this->timeScaleRampEnd - this->timeScaleRampStart);
  }
  LODWORD(v3) = 0;
  if ( this->changedAF || this->linearTime != (af_useLinearTime.valueInteger != 0) )
  {
    idPhysics_AF::BuildTrees(this);
    this->changedAF = false;
    this->linearTime = af_useLinearTime.valueInteger != 0;
  }
  if ( this->masterBody != nullptr )
  {
    this->callbacks->GetMasterPosition(this: this->callbacks, a2: v76, a3: v77);
    if ( this->IsAtRest(this) )
    {
      clipModel = this->masterBody->clipModel;
      if ( clipModel->origin.x != v76[0].x
        || clipModel->origin.y != v76[0].y
        || (v11 = 1, clipModel->origin.z != v76[0].z) )
      {
        v11 = 0;
      }
      if ( v11 == 0 || (unsigned __int8)idMat3::Compare(this: &clipModel->axis, a: v77) == 0 )
        this->callbacks->ActivatePhysics(this: this->callbacks, a2: this->physicsId);
    }
    idClipModel::SetLinkedPosition(
      this: this->masterBody->clipModel,
      newOrigin: v76,
      newAxis: &this->masterBody->clipModel->axis);
    idClipModel::SetLinkedPosition(
      this: this->masterBody->clipModel,
      newOrigin: &this->masterBody->clipModel->origin,
      newAxis: v77);
  }
  if ( this->IsAtRest(this) || this->timeStep <= 0.0 )
  {
    idPhysics_AF::DebugDraw(this);
    idPhysics_AF::RemoveFrameConstraints(this);
    return 0;
  }
  if ( af_recordTrace.valueInteger == 1 )
  {
    LastError = GetLastError();
    idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
  }
  timer_total.state = TS_STARTED;
  LODWORD(v13) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  timer_total.start = v13;
  idPhysics_AF::ResolveCollisions(this, timeStep: this->lastTimeStep, a3: v14);
  idPhysics_AF::EvaluateBodies(this, timeStep: this->timeStep);
  idPhysics_AF::SetupContactConstraints(this, timeStep: this->timeStep);
  idPhysics_AF::EvaluateConstraints(this, timeStep: this->timeStep);
  idPhysics_AF::ApplyFriction(this, timeStep: this->timeStep, endTimeMSec: v5);
  idPhysics_AF::AddFrameConstraints(this);
  timer_pc.state = TS_STARTED;
  LODWORD(v15) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  timer_pc.start = v15;
  idPhysics_AF::PrimaryFactor(this);
  idPhysics_AF::PrimaryForces(this, timeStep: this->timeStep);
  idTimer::Stop(this: &timer_pc);
  timer_ac.state = TS_STARTED;
  LODWORD(v16) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  timer_ac.start = v16;
  idPhysics_AF::AuxiliaryForces(this, timeStep: this->timeStep);
  idTimer::Stop(this: &timer_ac);
  idPhysics_AF::Evolve(this, timeStep: this->timeStep);
  v17 = 0;
  if ( this->bodies.num > 0 )
  {
    v18 = 0;
    do
    {
      ++v17;
      v19 = this->bodies.list[v18++];
      v20 = (float *)v19->clipModel;
      v19->current.worldOrigin.x = v20[8];
      v19->current.worldOrigin.y = v20[9];
      v19->current.worldOrigin.z = v20[10];
      v19->current.worldAxis.mat[0].x = v20[11];
      v19->current.worldAxis.mat[0].y = v20[12];
      v19->current.worldAxis.mat[0].z = v20[13];
      v19->current.worldAxis.mat[1].x = v20[14];
      v19->current.worldAxis.mat[1].y = v20[15];
      v19->current.worldAxis.mat[1].z = v20[16];
      v19->current.worldAxis.mat[2].x = v20[17];
      v19->current.worldAxis.mat[2].y = v20[18];
      v19->current.worldAxis.mat[2].z = v20[19];
    }
    while ( v17 < this->bodies.num );
  }
  idPhysics_AF::AddGravity(this);
  if ( this->comeToRest
    && af_neverRest.valueInteger == 0
    && (unsigned __int8)idPhysics_AF::TestIfAtRest(this: v21, timeStep: this->timeStep) != 0 )
  {
    this->PutToRest(this);
    if ( this->IsAtRest(this) )
      this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
  else
  {
    this->ActivateContactPhysics(this);
  }
  idPhysics_AF::DebugDraw(this);
  if ( this->IsOutsideWorld(this) )
  {
    callbacks = this->callbacks;
    v23 = idVec3::ToString(this: (idAngles *)&(*this->bodies.list)->clipModel->origin, precision: 0);
    v24 = (const char *)callbacks->GetName(this: callbacks);
    idLib::Warning(fmt: "articulated figure moved outside world bounds for entity '%s' at (%s)", v24, v23);
    this->callbacks->DeactivatePhysics(this: this->callbacks, a2: this->physicsId);
  }
  idTimer::Stop(this: &timer_total);
  if ( af_recordTrace.valueInteger > 0 )
    idCVar::SetInteger(this: &af_recordTrace, newValue: af_recordTrace.valueInteger - 1, force: true);
  v25 = 0;
  v26 = 0;
  v27 = 0;
  if ( this->primaryConstraints.num > 0 )
  {
    v28 = 0;
    do
    {
      v29 = this->primaryConstraints.list[v28];
      ++v27;
      ++v28;
      v25 += v29->J1.numRows;
    }
    while ( v27 < this->primaryConstraints.num );
  }
  v30 = 0;
  if ( this->auxiliaryConstraints.num > 0 )
  {
    v31 = 0;
    do
    {
      v32 = this->auxiliaryConstraints.list[v31];
      ++v30;
      ++v31;
      v26 += v32->J1.numRows;
    }
    while ( v30 < this->auxiliaryConstraints.num );
  }
  if ( af_showTimings.valueInteger == 1 )
  {
    HIDWORD(v3) = this->callbacks;
    clockTicks = (float)timer_collision.clockTicks;
    LODWORD(v34) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v35 = (float)timer_lcp.clockTicks;
    v36 = (float)((float)clockTicks / (float)((float)v34 * (float)0.001));
    LODWORD(v37) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v38 = (float)timer_lcp.clockTicks;
    v39 = (float)((float)v35 / (float)((float)v37 * (float)0.001));
    LODWORD(v40) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v41 = (float)timer_ac.clockTicks;
    v42 = (float)((float)v38 / (float)((float)v40 * (float)0.001));
    LODWORD(v43) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v44 = (float)timer_pc.clockTicks;
    v45 = (float)((float)v41 / (float)((float)v43 * (float)0.001));
    LODWORD(v46) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v47 = (float)timer_total.clockTicks;
    v48 = (float)((float)v44 / (float)((float)v46 * (float)0.001));
    *((_QWORD *)&v49 + 1) = Sys_ClockTicksPerSecond();
    v50 = (float)((float)v47 / (float)((float)*(__int64 *)((char *)&v49 + 4) * (float)0.001));
    DWORD2(v49) = (**(int (__fastcall ***)(_DWORD, _DWORD))HIDWORD(v3))(a1: HIDWORD(v3), a2: v49);
    idLib::Printf(
      fmt: "%12s: t %1.4f pc %2d, %1.4f ac %2d %1.4f lcp %1.4f cd %1.4f\n",
      (const char *)DWORD2(v49),
      v50,
      LODWORD(v50),
      v48,
      v25,
      (float)((float)v45 - (float)v42),
      v39,
      v36);
    goto LABEL_49;
  }
  if ( af_showTimings.valueInteger != 2 )
  {
LABEL_49:
    if ( endTimeMSec > lastTimerReset )
    {
      lastTimerReset = endTimeMSec;
      numArticulatedFigures = 0;
      timer_total.clockTicks = v3;
      timer_pc.clockTicks = v3;
      timer_ac.clockTicks = v3;
      timer_collision.clockTicks = v3;
      timer_lcp.clockTicks = v3;
    }
    goto LABEL_51;
  }
  ++numArticulatedFigures;
  if ( endTimeMSec > lastTimerReset )
  {
    v51 = (float)timer_collision.clockTicks;
    LODWORD(v52) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v53 = (float)timer_lcp.clockTicks;
    v54 = (float)((float)v51 / (float)((float)v52 * (float)0.001));
    LODWORD(v55) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v56 = (float)timer_ac.clockTicks;
    v57 = (float)((float)v53 / (float)((float)v55 * (float)0.001));
    LODWORD(v58) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v59 = (float)timer_lcp.clockTicks;
    v60 = (float)((float)v56 / (float)((float)v58 * (float)0.001));
    LODWORD(v61) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v62 = (float)timer_pc.clockTicks;
    v63 = (float)((float)v59 / (float)((float)v61 * (float)0.001));
    LODWORD(v64) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v65 = (float)timer_total.clockTicks;
    v66 = (float)((float)v62 / (float)((float)v64 * (float)0.001));
    LODWORD(v67) = (unsigned __int64)Sys_ClockTicksPerSecond() >> 32;
    v68 = (float)((float)v65 / (float)((float)v67 * (float)0.001));
    idLib::Printf(
      fmt: "af %d: t %1.4f pc %2d, %1.4f ac %2d %1.4f lcp %1.4f cd %1.4f\n",
      HIDWORD(v68),
      v68,
      LODWORD(v68),
      v66,
      v25,
      (float)((float)v60 - (float)v63),
      v57,
      v54);
    goto LABEL_49;
  }
LABEL_51:
  num = this->frameConstraints.num;
  v70 = this->auxiliaryConstraints.num;
  if ( num <= v70 )
  {
    v72 = v70 - num;
    if ( v70 - num <= this->auxiliaryConstraints.size
      || idList<idNavSpline *,5>::Resize(
           this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->auxiliaryConstraints,
           newsize: v70 - num) )
    {
      size = this->auxiliaryConstraints.size;
      if ( v72 < size )
        size = v72;
      this->auxiliaryConstraints.num = size;
    }
  }
  else
  {
    p_auxiliaryConstraints = &this->auxiliaryConstraints;
    if ( this->auxiliaryConstraints.size < 0 )
    {
      if ( this->auxiliaryConstraints.listStatic == 0 || this->auxiliaryConstraints.listStatic == 2 )
      {
        if ( p_auxiliaryConstraints->list != nullptr )
          idMem::Free(this: &mem, ptr: p_auxiliaryConstraints->list, align: ALIGN_16);
        p_auxiliaryConstraints->list = nullptr;
        this->auxiliaryConstraints.size = 0;
      }
      this->auxiliaryConstraints.num = 0;
    }
    this->auxiliaryConstraints.num = __CFADD__(
                                       -this->auxiliaryConstraints.size,
                                       this->auxiliaryConstraints.size ^ 0x80000000)
                                   ? 0
                                   : this->auxiliaryConstraints.size;
  }
  p_frameConstraints = &this->frameConstraints;
  if ( this->frameConstraints.size < 0 )
  {
    if ( this->frameConstraints.listStatic == 0 || this->frameConstraints.listStatic == 2 )
    {
      if ( p_frameConstraints->list != nullptr )
        idMem::Free(this: &mem, ptr: p_frameConstraints->list, align: ALIGN_16);
      p_frameConstraints->list = nullptr;
      this->frameConstraints.size = 0;
    }
    this->frameConstraints.num = 0;
  }
  this->frameConstraints.num = __CFADD__(-this->frameConstraints.size, this->frameConstraints.size ^ 0x80000000)
                             ? 0
                             : this->frameConstraints.size;
  this->lastTimeStep = this->timeStep;
  return 1;
}


// ========================================================================
// `dynamic initializer for 'af_skipSelfCollision''
// EA  : 0x83340318
// RVA : 0x01340318
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_skipSelfCollision__()
{
  idCVar::idCVar(
    this: &af_skipSelfCollision,
    name: "af_skipSelfCollision",
    value: "0",
    flags: 1,
    description: "skip self collision detection",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_skipSelfCollision__);
}


// ========================================================================
// `dynamic initializer for 'af_skipFriction''
// EA  : 0x83340370
// RVA : 0x01340370
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_skipFriction__()
{
  idCVar::idCVar(
    this: &af_skipFriction,
    name: "af_skipFriction",
    value: "0",
    flags: 1,
    description: "skip friction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_skipFriction__);
}


// ========================================================================
// `dynamic initializer for 'af_skipAirFriction''
// EA  : 0x833403C8
// RVA : 0x013403C8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_skipAirFriction__()
{
  idCVar::idCVar(
    this: &af_skipAirFriction,
    name: "af_skipAirFriction",
    value: "0",
    flags: 1,
    description: "skip air friction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_skipAirFriction__);
}


// ========================================================================
// `dynamic initializer for 'af_jointFrictionScale''
// EA  : 0x83340420
// RVA : 0x01340420
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_jointFrictionScale__()
{
  idCVar::idCVar(
    this: &af_jointFrictionScale,
    name: "af_jointFrictionScale",
    value: "0",
    flags: 4,
    description: "scales the joint friction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_jointFrictionScale__);
}


// ========================================================================
// `dynamic initializer for 'af_contactFrictionScale''
// EA  : 0x83340478
// RVA : 0x01340478
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_contactFrictionScale__()
{
  idCVar::idCVar(
    this: &af_contactFrictionScale,
    name: "af_contactFrictionScale",
    value: "0",
    flags: 4,
    description: "scales the contact friction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_contactFrictionScale__);
}


// ========================================================================
// `dynamic initializer for 'af_useLinearTime''
// EA  : 0x833404D0
// RVA : 0x013404D0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_useLinearTime__()
{
  idCVar::idCVar(
    this: &af_useLinearTime,
    name: "af_useLinearTime",
    value: "1",
    flags: 1,
    description: "use linear time algorithm for tree-like structures",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_useLinearTime__);
}


// ========================================================================
// `dynamic initializer for 'af_maxLinearVelocity''
// EA  : 0x83340528
// RVA : 0x01340528
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_maxLinearVelocity__()
{
  idCVar::idCVar(
    this: &af_maxLinearVelocity,
    name: "af_maxLinearVelocity",
    value: "128",
    flags: 4,
    description: "maximum linear velocity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_maxLinearVelocity__);
}


// ========================================================================
// `dynamic initializer for 'af_maxAngularVelocity''
// EA  : 0x83340580
// RVA : 0x01340580
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_maxAngularVelocity__()
{
  idCVar::idCVar(
    this: &af_maxAngularVelocity,
    name: "af_maxAngularVelocity",
    value: "1.57",
    flags: 4,
    description: "maximum angular velocity",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_maxAngularVelocity__);
}


// ========================================================================
// `dynamic initializer for 'af_maxAuxiliaryConstraints''
// EA  : 0x833405D8
// RVA : 0x013405D8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_maxAuxiliaryConstraints__()
{
  idCVar::idCVar(
    this: &af_maxAuxiliaryConstraints,
    name: "af_maxAuxiliaryConstraints",
    value: "200",
    flags: 2,
    description: "maximum number of auxiliary constraints on an articulated figure",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_maxAuxiliaryConstraints__);
}


// ========================================================================
// `dynamic initializer for 'af_timeScale''
// EA  : 0x83340630
// RVA : 0x01340630
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_timeScale__()
{
  idCVar::idCVar(
    this: &af_timeScale,
    name: "af_timeScale",
    value: "1",
    flags: 4,
    description: "scales the time",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_timeScale__);
}


// ========================================================================
// `dynamic initializer for 'af_neverRest''
// EA  : 0x83340688
// RVA : 0x01340688
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_neverRest__()
{
  idCVar::idCVar(
    this: &af_neverRest,
    name: "af_neverRest",
    value: "0",
    flags: 1,
    description: "never come to rest",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_neverRest__);
}


// ========================================================================
// `dynamic initializer for 'af_highlightBody''
// EA  : 0x833406E0
// RVA : 0x013406E0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_highlightBody__()
{
  idCVar::idCVar(
    this: &af_highlightBody,
    name: "af_highlightBody",
    value: &byte_8200D768,
    flags: 0,
    description: "name of the body to highlight",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_highlightBody__);
}


// ========================================================================
// `dynamic initializer for 'af_highlightConstraint''
// EA  : 0x83340738
// RVA : 0x01340738
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_highlightConstraint__()
{
  idCVar::idCVar(
    this: &af_highlightConstraint,
    name: "af_highlightConstraint",
    value: &byte_8200D768,
    flags: 0,
    description: "name of the constraint to highlight",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_highlightConstraint__);
}


// ========================================================================
// `dynamic initializer for 'af_showTimings''
// EA  : 0x83340790
// RVA : 0x01340790
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showTimings__()
{
  idCVar::idCVar(
    this: &af_showTimings,
    name: "af_showTimings",
    value: "0",
    flags: 1,
    description: "show articulated figure cpu usage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showTimings__);
}


// ========================================================================
// `dynamic initializer for 'af_showConstraints''
// EA  : 0x833407E8
// RVA : 0x013407E8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showConstraints__()
{
  idCVar::idCVar(
    this: &af_showConstraints,
    name: "af_showConstraints",
    value: "0",
    flags: 1,
    description: "show constraints",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showConstraints__);
}


// ========================================================================
// `dynamic initializer for 'af_showConstraintNames''
// EA  : 0x83340840
// RVA : 0x01340840
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showConstraintNames__()
{
  idCVar::idCVar(
    this: &af_showConstraintNames,
    name: "af_showConstraintNames",
    value: "0",
    flags: 1,
    description: "show constraint names",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showConstraintNames__);
}


// ========================================================================
// `dynamic initializer for 'af_showConstrainedBodies''
// EA  : 0x83340898
// RVA : 0x01340898
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showConstrainedBodies__()
{
  idCVar::idCVar(
    this: &af_showConstrainedBodies,
    name: "af_showConstrainedBodies",
    value: "0",
    flags: 1,
    description: "show the two bodies contrained by the highlighted constraint",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showConstrainedBodies__);
}


// ========================================================================
// `dynamic initializer for 'af_showPrimaryOnly''
// EA  : 0x833408F0
// RVA : 0x013408F0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showPrimaryOnly__()
{
  idCVar::idCVar(
    this: &af_showPrimaryOnly,
    name: "af_showPrimaryOnly",
    value: "0",
    flags: 1,
    description: "show primary constraints only",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showPrimaryOnly__);
}


// ========================================================================
// `dynamic initializer for 'af_showTrees''
// EA  : 0x83340948
// RVA : 0x01340948
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showTrees__()
{
  idCVar::idCVar(
    this: &af_showTrees,
    name: "af_showTrees",
    value: "0",
    flags: 1,
    description: "show tree-like structures",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showTrees__);
}


// ========================================================================
// `dynamic initializer for 'af_showBodies''
// EA  : 0x833409A0
// RVA : 0x013409A0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showBodies__()
{
  idCVar::idCVar(
    this: &af_showBodies,
    name: "af_showBodies",
    value: "0",
    flags: 1,
    description: "show bodies",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showBodies__);
}


// ========================================================================
// `dynamic initializer for 'af_showBodyNames''
// EA  : 0x833409F8
// RVA : 0x013409F8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showBodyNames__()
{
  idCVar::idCVar(
    this: &af_showBodyNames,
    name: "af_showBodyNames",
    value: "0",
    flags: 1,
    description: "show body names",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showBodyNames__);
}


// ========================================================================
// `dynamic initializer for 'af_showMass''
// EA  : 0x83340A50
// RVA : 0x01340A50
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showMass__()
{
  idCVar::idCVar(
    this: &af_showMass,
    name: "af_showMass",
    value: "0",
    flags: 1,
    description: "show the mass of each body",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showMass__);
}


// ========================================================================
// `dynamic initializer for 'af_showTotalMass''
// EA  : 0x83340AA8
// RVA : 0x01340AA8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showTotalMass__()
{
  idCVar::idCVar(
    this: &af_showTotalMass,
    name: "af_showTotalMass",
    value: "0",
    flags: 1,
    description: "show the total mass of each articulated figure",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showTotalMass__);
}


// ========================================================================
// `dynamic initializer for 'af_showInertia''
// EA  : 0x83340B00
// RVA : 0x01340B00
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showInertia__()
{
  idCVar::idCVar(
    this: &af_showInertia,
    name: "af_showInertia",
    value: "0",
    flags: 1,
    description: "show the inertia tensor of each body",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showInertia__);
}


// ========================================================================
// `dynamic initializer for 'af_showVelocity''
// EA  : 0x83340B58
// RVA : 0x01340B58
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showVelocity__()
{
  idCVar::idCVar(
    this: &af_showVelocity,
    name: "af_showVelocity",
    value: "0",
    flags: 1,
    description: "show the velocity of each body",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showVelocity__);
}


// ========================================================================
// `dynamic initializer for 'af_showActive''
// EA  : 0x83340BB0
// RVA : 0x01340BB0
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_showActive__()
{
  idCVar::idCVar(
    this: &af_showActive,
    name: "af_showActive",
    value: "0",
    flags: 1,
    description: "show tree-like structures of articulated figures not at rest",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_showActive__);
}


// ========================================================================
// `dynamic initializer for 'af_collisionReductionMass''
// EA  : 0x83340C08
// RVA : 0x01340C08
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_collisionReductionMass__()
{
  idCVar::idCVar(
    this: &af_collisionReductionMass,
    name: "af_collisionReductionMass",
    value: "0.9",
    flags: 4,
    description: "fraction of the original colliding mass that is removed for the collision impulse, this only applied to car-car damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_collisionReductionMass__);
}


// ========================================================================
// `dynamic initializer for 'af_recordTrace''
// EA  : 0x83340C60
// RVA : 0x01340C60
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__af_recordTrace__()
{
  idCVar::idCVar(
    this: &af_recordTrace,
    name: "af_recordTrace",
    value: "0",
    flags: 2,
    description: "record a CPU trace",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__af_recordTrace__);
}


// ========================================================================
// `dynamic initializer for 'timer_total''
// EA  : 0x83340CB8
// RVA : 0x01340CB8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timer_total__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timer_total__);
}


// ========================================================================
// `dynamic initializer for 'timer_pc''
// EA  : 0x83340CC8
// RVA : 0x01340CC8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timer_pc__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timer_pc__);
}


// ========================================================================
// `dynamic initializer for 'timer_ac''
// EA  : 0x83340CD8
// RVA : 0x01340CD8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timer_ac__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timer_ac__);
}


// ========================================================================
// `dynamic initializer for 'timer_collision''
// EA  : 0x83340CE8
// RVA : 0x01340CE8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timer_collision__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timer_collision__);
}


// ========================================================================
// `dynamic initializer for 'timer_lcp''
// EA  : 0x83340CF8
// RVA : 0x01340CF8
// PDB : w:\tech5\engine\gamelib\physics\physics_af.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__timer_lcp__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__timer_lcp__);
}

