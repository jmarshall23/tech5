
// ========================================================================
// ?Hide@idSplineFollower@@UAAXXZ
// EA  : 0x82CB8268
// RVA : 0x00CB8268
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __fastcall idSplineFollower::Hide(idSplineFollower *this)
{
  idEntity::Hide(this, stopFx: false);
}


// ========================================================================
// ?OnActivate@idSplineFollower@@UAAXPAVidEntity@@@Z
// EA  : 0x82CB8270
// RVA : 0x00CB8270
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __fastcall idSplineFollower::OnActivate(idSplineFollower *this, idEntity *activator)
{
  ((void (__fastcall *)(idSplineFollower *, idEntity *))this->Show)(a1: this, a2: activator);
}


// ========================================================================
// ??0idSplineFollower@@QAA@XZ
// EA  : 0x82CB8288
// RVA : 0x00CB8288
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

idSplineFollower *__fastcall idSplineFollower::idSplineFollower(idSplineFollower *this)
{
  float z; // r4
  const idDeclParticle **v3; // r10
  int v4; // ctr

  idAnimatedEntity::idAnimatedEntity(this);
  this->__vftable = (idSplineFollower_vtbl *)&idSplineFollower::`vftable';
  idPhysics_RigidBody::idPhysics_RigidBody(this: &this->physicsObj);
  this->solid = true;
  this->health = 50.0;
  this->popJointHits = 0;
  this->startupSetAngleOverride = 1.0;
  this->moveSpeed = 1.0;
  this->moveSpeedVariancePercent = 0.5;
  this->minMoveSpeed = 1.0;
  this->maxMoveSpeed = 1.0;
  this->currentMoveSpeed = 1.0;
  this->lastOrigin.x = vec3_origin.x;
  this->lastOrigin.y = vec3_origin.y;
  z = vec3_origin.z;
  this->maxWindSpeed = 1.0;
  this->maxHorizontalSplineDistance = 70.0;
  this->lastOrigin.z = z;
  this->maxVerticalSplineDistance = 70.0;
  this->highlightColor = HIGHLIGHT_COLOR_NONE;
  this->maxSpinSpeed = 1.0;
  this->attachedEventDecl = nullptr;
  this->deltaRotationSpeed = 1.0;
  this->explodeAtEndOfSplineFlag = false;
  this->rotationFriction = 1.0;
  this->minPopJoint = 5;
  this->bottomWeightPercent = 0.5;
  this->maxPopJoint = 5;
  this->windRotationAmount = 0.0099999998;
  this->hidePopMesh = 0;
  this->minDetonationHeight = 0.0;
  this->numPopTags = 7;
  this->maxDetonationHeight = 0.0;
  this->delayToHidePopMesh = 65;
  this->detonationPlayerDistance = 0.0;
  this->delayToExplodeAfterPop = 2000;
  this->immediateDetonationPlayerDistance = 0.0;
  this->spline = nullptr;
  this->drawnToPlayerSpeed = 0.0;
  this->drawnToPlayerDistance = 0.0;
  this->drawnToPlayerByBottomPercent = 0.0;
  this->splineDistance = 0.0;
  this->lastDeltaSplineDistance = 1.0;
  this->blendDownAxisScaler = 0.0099999998;
  this->actualMaxWindSpeed = 0.0;
  this->spinAmount = 0.0;
  this->bottomSpinAmount = 0.0;
  this->preExplosionSound = nullptr;
  this->spinSpeed = 0.0;
  this->preExplosionTime = 3000;
  this->bottomSpinSpeed = 0.0;
  this->explosionSound = nullptr;
  this->actualDetonationHeight = 0.0;
  this->preExplosionFxCondition = FX_PROJECTILE_LAUNCH;
  this->explosionFxCondition = FX_PROJECTILE_EXPLODE;
  v3 = &this->smokeParticles[1];
  this->delayToHideEntity = 100;
  v4 = 2;
  this->delayToRemoveEntity = 10000;
  this->damageDecl = nullptr;
  this->bendJointMin = -1;
  this->bendJointMax = -1;
  this->phaseOn = SFP_HIDDEN;
  this->nextPhaseTime = 0;
  this->eventHandle.value = -1;
  this->nextSmokeTime = 0;
  this->nextSparkTime = 0;
  do
  {
    *(v3 - 3) = nullptr;
    *(v3++ - 1) = nullptr;
    *v3 = nullptr;
    --v4;
  }
  while ( v4 != 0 );
  this->lastSplinePosition.z = 0.0;
  this->lastSplinePosition.y = 0.0;
  this->lastSplinePosition.x = 0.0;
  this->averageDown = quat_identity;
  this->driftLocation.z = 0.0;
  this->driftLocation.y = 0.0;
  this->driftLocation.x = 0.0;
  this->driftSpeed.z = 0.0;
  this->driftSpeed.y = 0.0;
  this->driftSpeed.x = 0.0;
  this->windDirection.z = 0.0;
  this->windDirection.y = 0.0;
  this->windDirection.x = 0.0;
  this->lastMovement.z = 0.0;
  this->lastMovement.y = 0.0;
  this->lastMovement.x = 0.0;
  this->rotation = quat_identity;
  this->facing = quat_identity;
  return this;
}


// ========================================================================
// __unwind$488832
// EA  : 0x82CB852C
// RVA : 0x00CB852C
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void _unwind_488832()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 160 + 180));
}


// ========================================================================
// ?ExplodeNow@idSplineFollower@@QAAXXZ
// EA  : 0x82CB8558
// RVA : 0x00CB8558
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __fastcall idSplineFollower::ExplodeNow(idSplineFollower *this)
{
  int GameMs; // r28
  idPhysics *Physics; // r3
  int v4; // r3
  idPresentable *presentable; // r11
  const idVec3 *v6; // r27
  idPhysics *v7; // r3
  const idVec3 *v8; // r3
  int v9; // r3
  int delayToRemoveEntity; // r5

  idEntity::StopSound(this, channel: SND_CHANNEL_VOICE, peerMask: 0xFFu);
  if ( this->GetFXDecl(this) != nullptr )
  {
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_VOICE,
      shader: this->explosionSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    Physics = idEntity::GetPhysics(this);
    v4 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    presentable = this->presentable;
    v6 = (const idVec3 *)v4;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idFXManager::StartFX(
      this: &presentable->fxManager,
      org: v6,
      axis: &mat3_identity,
      time: GameMs,
      startCondition: this->explosionFxCondition);
    v7 = idEntity::GetPhysics(this);
    v8 = v7->GetOrigin(this: v7, a2: 0);
    idGameLocal::RadiusDamage(
      this: gameLocal,
      origin: v8,
      inflictor: this,
      attacker: this,
      damageDef: this->damageDecl,
      dmgPower: 1.0);
    this->phaseOn = SFP_STARTED_EXPLOSION;
    v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    delayToRemoveEntity = this->delayToRemoveEntity;
    this->nextPhaseTime = this->delayToHideEntity + v9;
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: delayToRemoveEntity);
  }
  else
  {
    idLib::Warning(fmt: "Spline follower '%s' tried to explode but was missing fx.", this->name.data);
    idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 1);
    this->phaseOn = SFP_DONE;
  }
}


// ========================================================================
// ?GetModelTransform@idSplineFollower@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82CB86D0
// RVA : 0x00CB86D0
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __fastcall idSplineFollower::GetModelTransform(idSplineFollower *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  idPhysics *Physics; // r3
  idPhysics *v7; // r3
  float *v8; // r3
  const idMat3 *v9; // r3
  idPhysics *v10; // r3
  idVec3 v11; // [sp+50h] [-90h] BYREF
  idQuat v12; // [sp+60h] [-80h] BYREF
  idMat3 v13[2]; // [sp+90h] [-50h] BYREF

  Physics = idEntity::GetPhysics(this);
  *modelOrigin = *Physics->GetOrigin(this: Physics, a2: 0);
  if ( this->phaseOn == SFP_FALLING )
  {
    v7 = idEntity::GetPhysics(this);
    v8 = (float *)v7->GetAxis(this: v7, a2: 0);
    modelAxis->mat[0].x = *v8;
    modelAxis->mat[0].y = v8[1];
    modelAxis->mat[0].z = v8[2];
    modelAxis->mat[1].x = v8[3];
    modelAxis->mat[1].y = v8[4];
    modelAxis->mat[1].z = v8[5];
    modelAxis->mat[2].x = v8[6];
    modelAxis->mat[2].y = v8[7];
    modelAxis->mat[2].z = v8[8];
  }
  else
  {
    modelAxis->mat[0].x = DOWN_MATRIX.mat[0].x;
    modelAxis->mat[0].y = DOWN_MATRIX.mat[0].y;
    modelAxis->mat[0].z = DOWN_MATRIX.mat[0].z;
    v11.x = 0.0;
    v11.y = 0.0;
    modelAxis->mat[1] = DOWN_MATRIX.mat[1];
    modelAxis->mat[2] = DOWN_MATRIX.mat[2];
    v11.z = 1.0;
    idMat3::RotateSelf(this: modelAxis, axis: &v11, angle: this->spinAmount);
    v9 = idQuat::ToMat3(this: &v12, result: (idMat3 *)&this->facing);
    *modelAxis = *idMat3::operator*(this: v13, result: modelAxis, a: v9);
    v10 = idEntity::GetPhysics(this);
    v10->SetAxis(this: v10, a2: modelAxis, a3: -1);
  }
}


// ========================================================================
// ?Show@idSplineFollower@@UAAXXZ
// EA  : 0x82CB88A8
// RVA : 0x00CB88A8
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __fastcall idSplineFollower::Show(idSplineFollower *this)
{
  int v2; // r5
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r5
  idPresentable *presentable; // r11

  idEntity::Show(this);
  if ( this->solid )
  {
    this->physicsObj.SetContents(this: &this->physicsObj, a2: 1, a3: -1);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetClipModelContents(
      this: presentable,
      newContents: 1,
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v5,
      a7: v4,
      a8: v3);
  }
  idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v2);
}


// ========================================================================
// ??1idSplineFollower@@UAA@XZ
// EA  : 0x82CB8938
// RVA : 0x00CB8938
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __fastcall idSplineFollower::~idSplineFollower(idSplineFollower *this, int a2, int a3)
{
  idHandle<int,enum invalidAIEvent_t,-1> *p_eventHandle; // r29
  idCurve_Spline<idVec3> *spline; // r3

  this->__vftable = (idSplineFollower_vtbl *)&idSplineFollower::`vftable';
  p_eventHandle = &this->eventHandle;
  idEntity::SetPhysics(this, phys: nullptr, a3);
  if ( this->eventHandle.value != -1 )
  {
    idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: &this->eventHandle);
    p_eventHandle->value = -1;
  }
  spline = this->spline;
  if ( spline != nullptr )
  {
    ((void (__fastcall *)(idCurve_Spline<idVec3> *, int))spline->dtr_idCurve<idVec3>)(a1: spline, a2: 1);
    this->spline = nullptr;
  }
  idPhysics_RigidBody::~idPhysics_RigidBody(this: &this->physicsObj);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$489584_0
// EA  : 0x82CB89D8
// RVA : 0x00CB89D8
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void _unwind_489584_0()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489585_0
// EA  : 0x82CB8A00
// RVA : 0x00CB8A00
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void _unwind_489585_0()
{
  int v0; // r12

  idPhysics_RigidBody::~idPhysics_RigidBody(this: (idPhysics_RigidBody *)(*(_DWORD *)(v0 - 128 + 148) + 5200));
}


// ========================================================================
// ?Think@idSplineFollower@@UAAXXZ
// EA  : 0x82CB8A30
// RVA : 0x00CB8A30
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __fastcall idSplineFollower::Think(idSplineFollower *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  idVec3 *p_lastOrigin; // r22
  float z; // r8
  int bendJointMax; // r11
  int bendJointMin; // r7
  float x; // r6
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v11; // r29
  idPhysics *v12; // r3
  int v13; // r3
  float *p_y; // r10
  _DWORD *v15; // r11
  int i; // ctr
  double blendDownAxisScaler; // fp31
  const idQuat *v18; // r3
  long double v19; // fp2
  int v20; // r9
  double v21; // fp3
  int v22; // r30
  double v23; // fp13
  double v24; // fp12
  double v25; // fp9
  const idMat3 *v26; // r3
  idQuat *v27; // r3
  int v28; // r11
  idSplineFollower::splineFollowerPhase_t phaseOn; // r11
  const idDeclAiEvent *attachedEventDecl; // r11
  idPhysics *v31; // r28
  int GameMs; // r27
  idPhysics *v33; // r3
  idAIEventManager *p_aiEventManager; // r28
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v36; // r3
  int v37; // r3
  idPresentable *v38; // r11
  int v39; // r30
  idTreeAnimator *v40; // r3
  idPresentable *v41; // r11
  idTreeAnimator *v42; // r28
  double v43; // fp30
  double v44; // fp31
  double v45; // fp13
  idVec3 *p_lastSplinePosition; // r30
  double v47; // fp12
  double v48; // fp11
  double v49; // fp0
  double splineDistance; // fp10
  idCurve_Spline<idVec3> *spline; // r4
  double v52; // fp9
  double v53; // fp7
  double v54; // fp6
  idVec3 *p_driftSpeed; // r23
  double v56; // fp12
  double v57; // fp9
  double v58; // fp6
  double minMoveSpeed; // fp2
  double v60; // fp11
  double maxMoveSpeed; // fp12
  double v62; // fp13
  double v63; // fp9
  char v64; // r30
  char v65; // r24
  char v66; // r29
  double actualDetonationHeight; // fp0
  idPlayer *Player; // r3
  idPhysics *v69; // r3
  float *v70; // r3
  double v71; // fp0
  int v72; // r29
  idPhysics *v73; // r3
  int v74; // r3
  idPresentable *v75; // r11
  const idVec3 *v76; // r28
  char v77; // r30
  double v78; // fp0
  double v79; // fp13
  double v80; // fp11
  double v81; // fp31
  double actualMaxWindSpeed; // fp0
  double v83; // fp13
  double v84; // fp13
  double y; // fp11
  double v86; // fp13
  double v87; // fp13
  double v88; // fp11
  double v89; // fp9
  double bottomWeightPercent; // fp3
  double v91; // fp12
  double v92; // fp24
  double v93; // fp25
  double v94; // fp10
  double v95; // fp26
  double v96; // fp1
  idQuat *p_facing; // r29
  double v98; // fp30
  double v99; // fp1
  double v100; // fp11
  double v101; // fp8
  double v102; // fp5
  double v103; // fp2
  double v104; // fp1
  double v105; // fp3
  double v106; // fp0
  double v107; // fp13
  double v108; // fp12
  double v109; // fp1
  double rotationFriction; // fp31
  double v111; // fp2
  double v112; // fp1
  double maxSpinSpeed; // fp13
  double v114; // fp9
  double v115; // fp0
  double v116; // fp11
  double v117; // fp1
  double v118; // fp31
  double v119; // fp2
  double v120; // fp1
  double v121; // fp13
  double v122; // fp5
  double v123; // fp0
  double v124; // fp11
  idSplineFollower::splineFollowerPhase_t v125; // r11
  idVec3 v126; // [sp+50h] [-180h] BYREF
  idMat3 v127; // [sp+60h] [-170h] BYREF
  float v128; // [sp+84h] [-14Ch]
  float v129; // [sp+88h] [-148h]
  float v130[4]; // [sp+90h] [-140h] BYREF
  float v131; // [sp+A0h] [-130h] BYREF
  float v132; // [sp+A4h] [-12Ch]
  float v133; // [sp+A8h] [-128h]
  idMat3 v134[2]; // [sp+B0h] [-120h] BYREF
  idQuat v135; // [sp+100h] [-D0h] BYREF

  if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) != 0 )
    return;
  Physics = idEntity::GetPhysics(this);
  v3 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  this->lastOrigin.x = *v3;
  p_lastOrigin = &this->lastOrigin;
  this->lastOrigin.y = v3[1];
  this->lastOrigin.z = v3[2];
  z = this->lastOrigin.z;
  bendJointMax = this->bendJointMax;
  bendJointMin = this->bendJointMin;
  x = this->lastOrigin.x;
  v126.y = this->lastOrigin.y;
  v126.x = x;
  v126.z = z;
  if ( bendJointMin < bendJointMax && bendJointMax >= 0 )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
    presentable = this->presentable;
    v11 = TreeAnimatorFromPresentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    if ( v11 != nullptr )
    {
      v12 = idEntity::GetPhysics(this);
      v13 = (int)v12->GetAxis(this: v12, a2: 0);
      p_y = &v134[0].mat[2].y;
      v15 = (_DWORD *)(v13 - 4);
      for ( i = 9; i != 0; --i )
        *++p_y = *(float *)++v15;
      if ( idMat3::InverseSelf(this: (idMat3 *)&v134[0].mat[2].z) )
      {
        blendDownAxisScaler = this->blendDownAxisScaler;
        v18 = idMat3::ToQuat(this: v134, result: (idQuat *)&v134[0].mat[2].z);
        this->averageDown = *idQuat::Slerp(
                               this: &this->averageDown,
                               from: &this->averageDown,
                               to: v18,
                               t: blendDownAxisScaler);
        v127.mat[2].y = this->bottomSpinAmount;
        idQuat::idQuat(
          this: (idQuat *)&v127,
          axis: &vec3_up,
          angle: (const idTypesafeNumber<float,enum RadiansUnique_t> *)&v127.mat[2].y,
          a4: v19);
        v20 = this->bendJointMin;
        v21 = this->averageDown.z;
        v22 = this->bendJointMax;
        v23 = (float)-(float)((float)(v127.mat[0].y * this->averageDown.y)
                            - (float)((float)(v127.mat[1].x * this->averageDown.w)
                                    - (float)(v127.mat[0].x * this->averageDown.x)));
        v24 = (float)-(float)((float)(v127.mat[0].y * this->averageDown.z)
                            - (float)((float)(v127.mat[0].x * this->averageDown.w)
                                    + (float)((float)(v127.mat[1].x * this->averageDown.x)
                                            + (float)(v127.mat[0].z * this->averageDown.y))));
        v25 = (float)-(float)((float)(v127.mat[0].x * this->averageDown.y)
                            - (float)((float)(v127.mat[0].z * this->averageDown.w)
                                    + (float)((float)(v127.mat[1].x * this->averageDown.z)
                                            + (float)(v127.mat[0].y * this->averageDown.x))));
        v127.mat[0].y = -(float)((float)(v127.mat[0].z * this->averageDown.x)
                               - (float)((float)(v127.mat[0].x * this->averageDown.z)
                                       + (float)((float)(v127.mat[0].y * this->averageDown.w)
                                               + (float)(v127.mat[1].x * this->averageDown.y))));
        v127.mat[0].x = v24;
        v127.mat[1].x = -(float)((float)(v127.mat[0].z * (float)v21) - (float)v23);
        v127.mat[0].z = v25;
        if ( v22 >= v20 )
        {
          do
          {
            v26 = idQuat::ToMat3(this: &v135, result: &v127);
            idTreeAnimator::SetJointAxis(
              this: v11,
              pose: DRIVER_MODEL,
              jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(__int16)v22,
              type: JOINTMOD_MODEL_OVERRIDE,
              axis: v26);
            v27 = idQuat::Slerp(this: (idQuat *)&v127, from: &quat_identity, to: (const idQuat *)&v127, t: 0.5);
            v127.mat[0].x = v27->x;
            v28 = this->bendJointMin;
            --v22;
            v127.mat[0].y = v27->y;
            v127.mat[0].z = v27->z;
            v127.mat[1].x = v27->w;
          }
          while ( v22 >= v28 );
        }
      }
    }
  }
  phaseOn = this->phaseOn;
  switch ( phaseOn )
  {
    case SFP_HIDDEN:
      attachedEventDecl = this->attachedEventDecl;
      this->phaseOn = SFP_MOVING;
      if ( attachedEventDecl != nullptr )
      {
        v31 = idEntity::GetPhysics(this);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v33 = v31;
        GetOrigin = v31->GetOrigin;
        p_aiEventManager = &gameLocal->aiEventManager;
        v36 = GetOrigin(this: v33, a2: 0);
        this->eventHandle.value = (int)idAIEventManager::AddEvent(
                                         this: (idAIEventManager *)&v127.mat[2].y,
                                         result: p_aiEventManager,
                                         eventDecl: this->attachedEventDecl,
                                         curTime: GameMs,
                                         originator: this,
                                         instigator: this,
                                         origin: v36,
                                         delay: 0)->eventList.list;
      }
      v37 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v38 = this->presentable;
      v39 = v37;
      if ( v38 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v38 = this->presentable;
      }
      idFXManager::StopAllFX(this: &v38->fxManager, time: v39, immediateStop: true);
      goto LABEL_107;
    case SFP_STARTED_POP:
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextPhaseTime )
      {
        v40 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
        v41 = this->presentable;
        v42 = v40;
        if ( v41 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v41 = this->presentable;
        }
        idPresentable::UpdateModelTransform(this: v41);
        if ( v42 != nullptr )
          *v42->meshVisibility.list = false;
        this->phaseOn = SFP_FALLING;
        this->nextPhaseTime = this->delayToExplodeAfterPop
                            + idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      }
      goto LABEL_107;
    case SFP_FALLING:
      if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextPhaseTime )
        idSplineFollower::ExplodeNow(this);
      goto LABEL_107;
    case SFP_MOVING:
    case SFP_PLAYED_WARNING_SOUND:
      idEntity::TouchTriggers(this);
      idAnimatedEntity::Think(this);
      v43 = (float)(this->splineDistance + this->lastDeltaSplineDistance);
      v44 = (float)(this->currentMoveSpeed * (float)2.0);
      ((void (__fastcall *)(float *, double))this->spline->GetCurrentValue)(a1: &v131, a2: v43);
      v45 = v133;
      p_lastSplinePosition = &this->lastSplinePosition;
      v47 = v131;
      v48 = v132;
      v49 = (float)((float)v44
                  - (float)__fsqrts((float)((float)((float)(v132 - this->lastSplinePosition.y)
                                                  * (float)(v132 - this->lastSplinePosition.y))
                                          + (float)((float)((float)(v131 - this->lastSplinePosition.x)
                                                          * (float)(v131 - this->lastSplinePosition.x))
                                                  + (float)((float)(v133 - this->lastSplinePosition.z)
                                                          * (float)(v133 - this->lastSplinePosition.z))))));
      if ( __fabs(v49) >= (float)((float)v44 * (float)0.0024999999) )
      {
        splineDistance = this->splineDistance;
        spline = this->spline;
        v52 = (float)((float)(this->lastDeltaSplineDistance * (float)v44) / (float)((float)v44 - (float)v49));
        this->lastDeltaSplineDistance = (float)(this->lastDeltaSplineDistance * (float)v44)
                                      / (float)((float)v44 - (float)v49);
        this->splineDistance = (float)v52 + (float)splineDistance;
        ((void (__fastcall *)(float *))spline->GetCurrentValue)(a1: v130);
        v53 = v130[1];
        v54 = v130[2];
        p_lastSplinePosition->x = v130[0];
        this->lastSplinePosition.y = v53;
        this->lastSplinePosition.z = v54;
      }
      else
      {
        this->splineDistance = v43;
        p_lastSplinePosition->x = v47;
        this->lastSplinePosition.y = v48;
        this->lastSplinePosition.z = v45;
      }
      p_driftSpeed = &this->driftSpeed;
      v56 = (float)(this->driftLocation.x + this->driftSpeed.x);
      this->driftLocation.x = this->driftLocation.x + this->driftSpeed.x;
      v57 = (float)(this->driftLocation.y + this->driftSpeed.y);
      this->driftLocation.y = this->driftLocation.y + this->driftSpeed.y;
      v58 = (float)(this->driftLocation.z + this->driftSpeed.z);
      this->driftLocation.z = this->driftLocation.z + this->driftSpeed.z;
      minMoveSpeed = this->minMoveSpeed;
      v60 = (float)((float)v56 + p_lastSplinePosition->x);
      maxMoveSpeed = this->maxMoveSpeed;
      v62 = (float)((float)v58 + this->lastSplinePosition.z);
      v63 = (float)((float)v57 + this->lastSplinePosition.y);
      v126.x = v60;
      v126.y = v63;
      v126.z = v62;
      if ( minMoveSpeed < maxMoveSpeed && RandomFloat(max: 1.0) < 0.1 )
        RandomFloat(min: this->minMoveSpeed, max: this->maxMoveSpeed);
      v64 = 0;
      v65 = 0;
      v66 = 0;
      if ( this->spline->IsDone(this: this->spline, a2: this->splineDistance) )
      {
        if ( this->explodeAtEndOfSplineFlag )
          v64 = 1;
        else
          v66 = 1;
      }
      actualDetonationHeight = this->actualDetonationHeight;
      if ( actualDetonationHeight != 0.0 && v126.z > actualDetonationHeight )
        v64 = 1;
      if ( g_balloonDebugIgnorePlayer.valueInteger == 0 )
      {
        Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
        if ( Player != nullptr )
        {
          v69 = idEntity::GetPhysics(this: Player);
          v70 = (float *)v69->GetOrigin(this: v69, a2: 0);
          v71 = __fsqrts((float)((float)((float)(v126.y - v70[1]) * (float)(v126.y - v70[1]))
                               + (float)((float)((float)(v126.x - *v70) * (float)(v126.x - *v70))
                                       + (float)((float)(v126.z - v70[2]) * (float)(v126.z - v70[2])))));
          if ( v71 >= this->immediateDetonationPlayerDistance )
          {
            if ( v71 < this->detonationPlayerDistance )
              v64 = 1;
          }
          else
          {
            v65 = 1;
          }
        }
      }
      if ( v65 != 0 && v66 != 0 )
        v65 = 1;
      if ( v66 != 0 )
      {
        idEntity::StopSound(this, channel: SND_CHANNEL_VOICE, peerMask: 0xFFu);
        idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 1);
        this->phaseOn = SFP_DONE;
        return;
      }
      if ( v64 != 0 && this->phaseOn != SFP_PLAYED_WARNING_SOUND )
      {
        if ( this->preExplosionTime > 0 )
        {
          if ( v65 == 0 )
          {
            idEntity::StartSoundShader(
              this,
              channel: SND_CHANNEL_VOICE,
              shader: this->preExplosionSound,
              soundShaderFlags: (soundShaderFlags_t)0,
              peerMask: 0xFFu);
            v72 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
            v73 = idEntity::GetPhysics(this);
            v74 = (int)v73->GetOrigin(this: v73, a2: 0);
            v75 = this->presentable;
            v76 = (const idVec3 *)v74;
            if ( v75 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v75 = this->presentable;
            }
            idFXManager::StartFX(
              this: &v75->fxManager,
              org: v76,
              axis: &mat3_identity,
              time: v72,
              startCondition: this->preExplosionFxCondition);
            this->phaseOn = SFP_PLAYED_WARNING_SOUND;
            this->nextPhaseTime = idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED)
                                + this->preExplosionTime;
          }
        }
        else
        {
          idLib::Warning(fmt: "Pre explosion time not set in spline follower '%s'.", this->name.data);
          v65 = 1;
        }
      }
      if ( this->phaseOn == SFP_PLAYED_WARNING_SOUND
        && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextPhaseTime )
      {
        v65 = 1;
      }
      if ( v65 != 0 )
      {
        idSplineFollower::ExplodeNow(this);
        return;
      }
      v77 = 0;
      v78 = (float)((float)(p_driftSpeed->x * 100.0) + this->driftLocation.x);
      v79 = (float)((float)(this->driftSpeed.y * 100.0) + this->driftLocation.y);
      v80 = (float)(this->driftLocation.z + (float)(this->driftSpeed.z * 100.0));
      if ( __fsqrts((float)((float)((float)v79 * (float)v79) + (float)((float)v78 * (float)v78))) > (float)(this->maxHorizontalSplineDistance * 0.66600001) )
      {
        this->windDirection.x = -v78;
        this->windDirection.y = -v79;
        v77 = 1;
      }
      if ( __fabs(v80) > (float)(this->maxVerticalSplineDistance * (float)0.66600001) )
      {
        this->windDirection.z = -v80;
        v77 = 1;
      }
      if ( v77 == 0 && RandomFloat() < 0.1 )
      {
        v77 = 1;
        v81 = (float)(this->actualMaxWindSpeed * 0.1);
        this->windDirection.x = RandomFloat(min: -v81, max: v81) + this->windDirection.x;
        this->windDirection.y = RandomFloat(min: -v81, max: v81) + this->windDirection.y;
        this->windDirection.z = RandomFloat(min: -v81, max: v81) + this->windDirection.z;
      }
      if ( v77 != 0 )
      {
        actualMaxWindSpeed = this->actualMaxWindSpeed;
        v83 = __fsqrts((float)((float)(this->windDirection.x * this->windDirection.x)
                             + (float)(this->windDirection.y * this->windDirection.y)));
        if ( v83 > actualMaxWindSpeed )
        {
          v84 = (float)((float)v83 / this->actualMaxWindSpeed);
          y = this->windDirection.y;
          this->windDirection.x = (float)((float)1.0 / (float)v84) * this->windDirection.x;
          this->windDirection.y = (float)((float)1.0 / (float)v84) * (float)y;
        }
        v86 = this->windDirection.z;
        if ( v86 >= -actualMaxWindSpeed )
        {
          if ( v86 > actualMaxWindSpeed )
            this->windDirection.z = actualMaxWindSpeed;
        }
        else
        {
          this->windDirection.z = -actualMaxWindSpeed;
        }
      }
      p_driftSpeed->x = (float)(this->windDirection.x * 0.15000001) + p_driftSpeed->x;
      v87 = this->driftSpeed.y;
      v88 = this->windDirection.y;
      this->driftSpeed.z = (float)(this->windDirection.z * (float)0.15000001) + this->driftSpeed.z;
      this->driftSpeed.y = (float)((float)v88 * (float)0.15000001) + (float)v87;
      v89 = this->lastMovement.z;
      bottomWeightPercent = this->bottomWeightPercent;
      v91 = this->lastOrigin.z;
      v92 = (float)(v126.y - this->lastOrigin.y);
      v93 = (float)(v126.x - p_lastOrigin->x);
      v94 = (float)((float)(v126.y - this->lastOrigin.y) - this->lastMovement.y);
      v127.mat[1].y = (float)(v126.x - p_lastOrigin->x) - this->lastMovement.x;
      v127.mat[1].z = v94;
      v95 = (float)(v126.z - (float)v91);
      v127.mat[2].z = v127.mat[1].y;
      v128 = v127.mat[1].z;
      v127.mat[2].x = (float)((float)bottomWeightPercent * (float)0.5)
                    + (float)((float)(v126.z - (float)v91) - (float)v89);
      v129 = v127.mat[2].x;
      v96 = idVec3::NormalizeFast(this: (idVec3 *)&v127.mat[2].z);
      v127.mat[1].y = 0.0;
      v127.mat[1].z = 0.0;
      p_facing = &this->facing;
      v127.mat[2].x = 1.0;
      v98 = v96;
      idQuat::operator*(this: (idQuat *)v134, result: (idVec3 *)&this->facing, a: (const idVec3 *)&v127.mat[1].y);
      idQuat::MakeRotation(this: (idQuat *)&v134[0].mat[1].y, from: v134[0].mat, to: (const idVec3 *)&v127.mat[2].z);
      if ( v98 > 0.039999999 )
      {
        if ( v98 < 0.059999999 )
          v99 = (float)((float)((float)((float)v98 - 0.039999999) * (float)0.15000001) + 0.001);
        else
          v99 = 0.0040000002;
      }
      else
      {
        v99 = 0.001;
      }
      idQuat::Slerp(this: &this->rotation, from: &this->rotation, to: (const idQuat *)&v134[0].mat[1].y, t: v99);
      idQuat::Slerp(
        this: &this->rotation,
        from: &this->rotation,
        to: &quat_identity,
        t: (float)(this->rotationFriction * 0.00060000003));
      v100 = this->rotation.x;
      v101 = p_facing->x;
      v102 = this->facing.z;
      v103 = this->rotation.z;
      v104 = this->facing.y;
      v105 = (float)-(float)((float)(this->rotation.y * this->facing.y)
                           - (float)((float)(this->rotation.w * this->facing.w)
                                   - (float)(this->facing.x * this->rotation.x)));
      v106 = (float)((float)(this->rotation.w * this->facing.y)
                   + (float)((float)(this->facing.z * this->rotation.x) + (float)(this->rotation.y * this->facing.w)));
      v107 = (float)((float)(this->facing.w * this->rotation.z)
                   + (float)((float)(this->rotation.y * this->facing.x) + (float)(this->facing.z * this->rotation.w)));
      p_facing->x = -(float)((float)(p_facing->z * this->rotation.y)
                           - (float)((float)(p_facing->y * this->rotation.z)
                                   + (float)((float)(p_facing->x * this->rotation.w)
                                           + (float)(this->rotation.x * p_facing->w))));
      this->facing.w = -(float)((float)((float)v102 * (float)v103) - (float)v105);
      this->facing.y = -(float)((float)((float)v101 * (float)v103) - (float)v106);
      this->facing.z = -(float)((float)((float)v100 * (float)v104) - (float)v107);
      idQuat::Normalize(this: &this->facing);
      if ( this->startupSetAngleOverride != 0.0 )
      {
        idQuat::Slerp(
          this: &this->rotation,
          from: &this->rotation,
          to: &quat_identity,
          t: (float)(this->startupSetAngleOverride * 0.5));
        v108 = (float)(this->startupSetAngleOverride - 0.050000001);
        this->startupSetAngleOverride = this->startupSetAngleOverride - 0.050000001;
        if ( v108 < 0.0 )
          this->startupSetAngleOverride = 0.0;
      }
      v109 = RandomFloat(max: (float)((float)v98 * 0.1));
      rotationFriction = this->rotationFriction;
      v111 = (float)((float)v109 * this->deltaRotationSpeed);
      v112 = RandomFloat(min: -v111, max: v111);
      maxSpinSpeed = this->maxSpinSpeed;
      v114 = (float)(this->maxSpinSpeed * (float)0.75);
      v115 = (float)((float)((float)v112 + this->spinSpeed)
                   * (float)-(float)((float)((float)rotationFriction * 0.00025000001) - (float)1.0));
      this->spinSpeed = (float)((float)v112 + this->spinSpeed)
                      * (float)-(float)((float)((float)rotationFriction * 0.00025000001) - (float)1.0);
      if ( v115 <= v114 )
      {
        if ( v115 < (float)((float)maxSpinSpeed * (float)-0.75) )
        {
          v116 = (float)((float)-(float)((float)((float)rotationFriction * 0.00050000002) - (float)1.0) * this->spinSpeed);
          this->spinSpeed = (float)-(float)((float)((float)rotationFriction * 0.00050000002) - (float)1.0)
                          * this->spinSpeed;
          if ( v116 < -maxSpinSpeed )
            this->spinSpeed = -maxSpinSpeed;
        }
      }
      else
      {
        this->spinSpeed = (float)-(float)((float)((float)rotationFriction * 0.00050000002) - (float)1.0) * (float)v115;
        if ( (float)((float)-(float)((float)((float)rotationFriction * 0.00050000002) - (float)1.0) * (float)v115) > maxSpinSpeed )
          this->spinSpeed = maxSpinSpeed;
      }
      this->spinAmount = (float)(this->spinSpeed * 0.2) + this->spinAmount;
      v117 = RandomFloat(max: (float)((float)v98 * 0.0099999998));
      v118 = this->rotationFriction;
      v119 = (float)((float)v117 * this->deltaRotationSpeed);
      v120 = RandomFloat(min: -v119, max: v119);
      v121 = this->maxSpinSpeed;
      v122 = (float)(this->maxSpinSpeed * (float)0.75);
      v123 = (float)((float)((float)v120 + this->bottomSpinSpeed)
                   * (float)-(float)((float)((float)v118 * 0.00025000001) - (float)1.0));
      this->bottomSpinSpeed = (float)((float)v120 + this->bottomSpinSpeed)
                            * (float)-(float)((float)((float)v118 * 0.00025000001) - (float)1.0);
      if ( v123 <= v122 )
      {
        if ( v123 < (float)((float)v121 * (float)-0.75) )
        {
          v124 = (float)((float)-(float)((float)((float)v118 * 0.00050000002) - (float)1.0) * this->bottomSpinSpeed);
          this->bottomSpinSpeed = (float)-(float)((float)((float)v118 * 0.00050000002) - (float)1.0)
                                * this->bottomSpinSpeed;
          if ( v124 < -v121 )
            this->bottomSpinSpeed = -v121;
        }
      }
      else
      {
        this->bottomSpinSpeed = (float)-(float)((float)((float)v118 * 0.00050000002) - (float)1.0) * (float)v123;
        if ( (float)((float)-(float)((float)((float)v118 * 0.00050000002) - (float)1.0) * (float)v123) > v121 )
          this->bottomSpinSpeed = v121;
      }
      this->bottomSpinAmount = (float)(this->bottomSpinSpeed * 0.2) + this->bottomSpinAmount;
      this->lastMovement.x = v93;
      this->lastMovement.y = v92;
      this->lastMovement.z = v95;
      goto LABEL_107;
    default:
      break;
  }
  if ( this->eventHandle.value != -1 )
  {
    idAIEventManager::RemoveEvent(this: &gameLocal->aiEventManager, handle: &this->eventHandle);
    this->eventHandle.value = -1;
  }
  if ( this->phaseOn != SFP_STARTED_EXPLOSION )
  {
LABEL_107:
    v125 = this->phaseOn;
    if ( v125 == SFP_STARTED_POP || v125 == SFP_FALLING )
      idEntity::RunPhysics(this);
    else
      idEntity::SetOrigin(this, org: &v126);
    return;
  }
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->nextPhaseTime )
  {
    this->Hide_2(this);
    this->phaseOn = SFP_DONE;
  }
}


// ========================================================================
// ?SetColor@idSplineFollower@@UAAXMMM@Z
// EA  : 0x82CB9870
// RVA : 0x00CB9870
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __fastcall idSplineFollower::SetColor(
        idSplineFollower *this,
        double red,
        double green,
        double blue,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  idPresentable *presentable; // r3
  char v13; // r11
  idPresentable *v14; // r11
  __int64 v15; // [sp+8h] [-68h]
  __int64 v16; // [sp+10h] [-60h]
  __int64 v17; // [sp+18h] [-58h]
  __int64 v18; // [sp+20h] [-50h]
  __int64 v19; // [sp+28h] [-48h]
  __int64 v20; // [sp+58h] [-18h]

  presentable = this->presentable;
  if ( presentable == nullptr || (v13 = 1, presentable->model == nullptr) )
    v13 = 0;
  if ( v13 != 0 )
  {
    *(float *)&v20 = blue;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    *((float *)&v20 + 1) = 1.0;
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: v20,
      a4: a8,
      a5: a9,
      a6: a10,
      a7: a11,
      a8: v15,
      a9: v16,
      a10: v17,
      a11: v18,
      a12: v19);
    v14 = this->presentable;
    if ( v14 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v14 = this->presentable;
    }
    v14->Present(this: v14);
  }
}


// ========================================================================
// ?SetColor@idSplineFollower@@UAAXABVidVec3@@@Z
// EA  : 0x82CB9938
// RVA : 0x00CB9938
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __fastcall idSplineFollower::SetColor(
        idSplineFollower *this,
        const idVec3 *color,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idPresentable *presentable; // r3
  char v10; // r11
  idPresentable *v11; // r11
  __int64 v12; // [sp+8h] [-68h]
  __int64 v13; // [sp+10h] [-60h]
  __int64 v14; // [sp+18h] [-58h]
  __int64 v15; // [sp+20h] [-50h]
  __int64 v16; // [sp+28h] [-48h]
  __int64 v17; // [sp+58h] [-18h]

  presentable = this->presentable;
  if ( presentable == nullptr || (v10 = 1, presentable->model == nullptr) )
    v10 = 0;
  if ( v10 != 0 )
  {
    *((float *)&v17 + 1) = 1.0;
    *(float *)&v17 = color->z;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    idPresentable::SetParm(
      this: presentable,
      parm: rp->Color,
      v4: v17,
      a4: a5,
      a5: a6,
      a6: a7,
      a7: a8,
      a8: v12,
      a9: v13,
      a10: v14,
      a11: v15,
      a12: v16);
    v11 = this->presentable;
    if ( v11 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v11 = this->presentable;
    }
    v11->Present(this: v11);
  }
}


// ========================================================================
// ?Damage@idSplineFollower@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82CB9A10
// RVA : 0x00CB9A10
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

float __fastcall idSplineFollower::Damage(
        idSplineFollower *this,
        idWorldspawn *inflictor,
        idSplineFollower *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        trace_t *trace,
        int a8)
{
  idSplineFollower::splineFollowerPhase_t phaseOn; // r11
  char v14; // r9
  unsigned int v15; // r10
  int v16; // r11
  int v17; // r11
  double v18; // fp12
  double z; // fp12
  double y; // fp11
  int v21; // r27
  int i; // r23
  const idDeclParticle *v23; // r20
  int GameMsPerFrame; // r19
  int v25; // r18
  double v26; // fp31
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v28; // r7
  idPhysics_RigidBody_vtbl *v30; // r9
  double v31; // fp9
  double v32; // fp8
  double v33; // fp30
  double v34; // fp29
  idPhysics_RigidBody_vtbl *v35; // r11
  int v36; // r3
  double v37; // fp1
  int GameMs; // r3
  char flags; // r9
  idSplineFollower_vtbl *v40; // r7
  int v42; // [sp+8h] [-188h]
  int v43; // [sp+Ch] [-184h]
  int v44; // [sp+10h] [-180h]
  int v45; // [sp+14h] [-17Ch]
  int v46; // [sp+18h] [-178h]
  int v47; // [sp+1Ch] [-174h]
  int v48; // [sp+20h] [-170h]
  int v49; // [sp+24h] [-16Ch]
  int v50; // [sp+28h] [-168h]
  int v51; // [sp+2Ch] [-164h]
  int v52; // [sp+30h] [-160h]
  int v53; // [sp+34h] [-15Ch]
  int v54; // [sp+38h] [-158h]
  int v55; // [sp+3Ch] [-154h]
  int v56; // [sp+40h] [-150h]
  int v57; // [sp+44h] [-14Ch]
  int v58; // [sp+48h] [-148h]
  int v59; // [sp+4Ch] [-144h]
  int v60; // [sp+50h] [-140h]
  float v61; // [sp+60h] [-130h] BYREF
  unsigned int v62; // [sp+64h] [-12Ch] BYREF
  float v63[4]; // [sp+68h] [-128h] BYREF
  float v64[4]; // [sp+78h] [-118h] BYREF
  float v65[4]; // [sp+88h] [-108h] BYREF
  idMat3 v66; // [sp+98h] [-F8h] BYREF
  idMat3 v67; // [sp+D0h] [-C0h] BYREF

  if ( !this->TakesDamage(this)
    || this->health <= 0.0
    || idSplineFollower::CastTo(c: attacker) != nullptr
    || (phaseOn = this->phaseOn) != SFP_MOVING && phaseOn != SFP_PLAYED_WARNING_SOUND )
  {
    v37 = 0.0;
    return *((float *)&v37 + 1);
  }
  if ( inflictor == nullptr )
    inflictor = gameLocal->world;
  v61 = idDeclDamage::DamageAmount(this: damageDef);
  if ( attacker != nullptr )
    attacker->DamageFeedback(this: attacker, a2: this, a3: inflictor, a4: damageDef, a5: &v61);
  v14 = 0;
  LOBYTE(v15) = 0;
  if ( a8 != 0 )
  {
    if ( *(_DWORD *)(a8 + 52) == 4 )
      v16 = *(_DWORD *)(a8 + 104);
    else
      LOWORD(v16) = -1;
    if ( (v16 & 0x8000u) == 0 )
    {
      v14 = 1;
      if ( (__int16)v16 < this->minPopJoint || (__int16)v16 > this->maxPopJoint )
      {
        v17 = this->popJointHits - 1;
      }
      else
      {
        LOBYTE(v15) = 1;
        v17 = this->popJointHits + 1;
      }
      this->popJointHits = v17;
    }
  }
  if ( v61 == 0.0 )
    goto LABEL_34;
  v18 = (float)(this->health - v61);
  this->health = this->health - v61;
  if ( v18 > 0.0 )
    goto LABEL_34;
  if ( v14 == 0 )
    v15 = (-this->popJointHits & (unsigned int)~this->popJointHits) >> 31;
  if ( (_BYTE)v15 == 0 )
  {
    this->phaseOn = SFP_PLAYED_WARNING_SOUND;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    flags = (char)this->flags;
    this->nextPhaseTime = GameMs;
    v40 = this->__vftable;
    *(_BYTE *)&this->flags = flags & 0xFD;
    v40->ActivateTargets(this, a2: attacker);
LABEL_34:
    v37 = v61;
    return *((float *)&v37 + 1);
  }
  z = this->lastMovement.z;
  y = this->lastMovement.y;
  v63[0] = this->lastMovement.x * (float)60.0;
  v63[2] = (float)z * (float)60.0;
  v63[1] = (float)y * (float)60.0;
  v21 = RandomInt(max: 2);
  for ( i = 0; i < this->numPopTags; ++i )
  {
    idStr::idStr(this: (idStr *)&v66.mat[2], text: "pop#");
    *(_BYTE *)(LODWORD(v66.mat[2].y) + 3) = i + 49;
    if ( (unsigned __int8)idAnimatedEntity::GetTagPosition(
                            this,
                            propName: "_info",
                            tagName: (const char *)LODWORD(v66.mat[2].y),
                            origin: v66.mat,
                            axis: &v67) != 0 )
    {
      v62 = -1;
      v23 = this->balloonPopParticle[v21];
      GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v25 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v26 = RandomFloat();
      MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
      idRenderModelEffects::AddParticles(
        this: MergeBranch,
        particle: v23,
        systemStartTime: v25,
        gameMsPerFrame: GameMsPerFrame,
        diversity: v26,
        origin: v28,
        axis: &v66,
        velocity: v67.mat,
        color: v63,
        a10: v42,
        a11: v43,
        a12: v44,
        a13: v45,
        a14: v46,
        a15: v47,
        a16: v48,
        a17: v49,
        a18: v50,
        a19: v51,
        a20: v52,
        a21: v53,
        a22: v54,
        a23: v55,
        a24: v56,
        a25: v57,
        a26: v58,
        a27: v59,
        a28: v60,
        a29: &v62);
    }
    if ( RandomInt(max: 3) != 0 && v21++ >= 1 )
      v21 = 0;
    idStr::FreeData(this: (idStr *)&v66.mat[2]);
  }
  this->physicsObj.Activate(this: &this->physicsObj);
  idEntity::BecomeActive(this, flags: 2);
  v30 = this->physicsObj.__vftable;
  v31 = (float)(this->lastMovement.y * 60.0);
  v32 = (float)(this->lastMovement.z * 60.0);
  v64[0] = this->lastMovement.x * 60.0;
  v64[1] = v31;
  v64[2] = v32;
  v30->SetLinearVelocity(this: &this->physicsObj, a2: (const idVec3 *)v64, a3: 0);
  v33 = RandomFloat(min: -10000.0, max: 10000.0);
  v34 = RandomFloat(min: -50.0, max: 50.0);
  v65[0] = RandomFloat(min: -50.0, max: 50.0);
  v35 = this->physicsObj.__vftable;
  v65[1] = v34;
  v65[2] = v33;
  v35->SetAngularVelocity(this: &this->physicsObj, a2: (const idVec3 *)v65, a3: 0);
  this->phaseOn = SFP_STARTED_POP;
  v36 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v37 = v61;
  this->nextPhaseTime = this->delayToHidePopMesh + v36;
  return *((float *)&v37 + 1);
}


// ========================================================================
// __unwind$490462
// EA  : 0x82CB9E50
// RVA : 0x00CB9E50
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void _unwind_490462()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 400 + 176));
}


// ========================================================================
// ?Spawn@idSplineFollower@@QAAXXZ
// EA  : 0x82CB9ED8
// RVA : 0x00CB9ED8
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __fastcall idSplineFollower::Spawn(idSplineFollower *this)
{
  double maxWindSpeed; // fp0
  double rotationFriction; // fp0
  double bottomWeightPercent; // fp0
  double windRotationAmount; // fp0
  double v6; // fp13
  double moveSpeedVariancePercent; // fp0
  double moveSpeed; // fp12
  double v11; // fp2
  double v12; // fp28
  double v13; // fp27
  double v14; // fp1
  double actualMaxWindSpeed; // fp8
  double v16; // fp6
  double minDetonationHeight; // fp1
  double v18; // fp1
  int value; // r9
  idEntity *v20; // r3
  idSplinePath *v21; // r3
  idSplinePath *v22; // r3
  idCurve_Spline<idVec3> *v23; // r4
  double v24; // fp13
  double v25; // fp12
  idClientGame *v26; // r11
  int GameMs; // r3
  idPresentable *presentable; // r11
  int v29; // r30
  int v30; // r5
  idPhysics_RigidBody_vtbl *v31; // r29
  idClipModel *MoveableClipModel; // r3
  idPresentable *v33; // r11
  char v34; // r10
  idPresentable *v35; // r11
  highlightColor_t highlightColor; // r10
  idRenderModel *model; // r9
  float v38[16]; // [sp+50h] [-60h] BYREF

  if ( this->moveSpeed < 0.0099999998 )
    this->moveSpeed = 0.0099999998;
  maxWindSpeed = this->maxWindSpeed;
  if ( maxWindSpeed >= 0.0 )
  {
    if ( maxWindSpeed > 100.0 )
      this->maxWindSpeed = 1120403456;
  }
  else
  {
    this->maxWindSpeed = 0.0;
  }
  if ( this->maxHorizontalSplineDistance < 0.0 )
    this->maxHorizontalSplineDistance = 0.0;
  if ( this->maxVerticalSplineDistance < 0.0 )
    this->maxVerticalSplineDistance = 0.0;
  if ( this->deltaRotationSpeed < 0.0 )
    this->deltaRotationSpeed = 0.0;
  rotationFriction = this->rotationFriction;
  if ( rotationFriction >= 0.0 )
  {
    if ( rotationFriction > 100.0 )
      this->rotationFriction = 100.0;
  }
  else
  {
    this->rotationFriction = 0.0;
  }
  bottomWeightPercent = this->bottomWeightPercent;
  if ( bottomWeightPercent >= -1.0 )
  {
    if ( bottomWeightPercent > 1.0 )
      this->bottomWeightPercent = 1065353216;
  }
  else
  {
    this->bottomWeightPercent = -1.0;
  }
  windRotationAmount = this->windRotationAmount;
  if ( windRotationAmount >= -1.0 )
  {
    if ( windRotationAmount > 1.0 )
      this->windRotationAmount = 1.0;
  }
  else
  {
    this->windRotationAmount = -1.0;
  }
  v6 = (float)(this->maxWindSpeed * 0.1);
  _FP7 = (float)((float)((float)(this->maxVerticalSplineDistance * (float)0.5) + this->maxHorizontalSplineDistance)
               - (float)((float)(this->maxHorizontalSplineDistance * (float)0.5) + this->maxVerticalSplineDistance));
  __asm { fsel      f6, f7, f9, f8 }
  this->actualMaxWindSpeed = (float)_FP6 * 0.00050000002;
  if ( (float)((float)_FP6 * 0.00050000002) > v6 )
    this->actualMaxWindSpeed = v6;
  this->lastDeltaSplineDistance = this->moveSpeed;
  moveSpeedVariancePercent = this->moveSpeedVariancePercent;
  if ( moveSpeedVariancePercent >= 0.0 )
  {
    if ( moveSpeedVariancePercent > 0.99000001 )
      this->moveSpeedVariancePercent = 0.99000001;
  }
  else
  {
    this->moveSpeedVariancePercent = 0.0;
  }
  moveSpeed = this->moveSpeed;
  v11 = (float)((float)(this->moveSpeedVariancePercent + (float)1.0) * this->moveSpeed);
  this->maxMoveSpeed = (float)(this->moveSpeedVariancePercent + (float)1.0) * this->moveSpeed;
  this->minMoveSpeed = (float)moveSpeed - (float)((float)v11 - (float)moveSpeed);
  this->currentMoveSpeed = RandomFloat(
                             min: (float)((float)moveSpeed - (float)((float)v11 - (float)moveSpeed)),
                             max: v11);
  v12 = RandomFloat(min: -1.0, max: 1.0);
  v13 = RandomFloat(min: -1.0, max: 1.0);
  v14 = RandomFloat(min: -1.0, max: 1.0);
  this->windDirection.y = v13;
  this->windDirection.z = v12;
  this->windDirection.x = v14;
  actualMaxWindSpeed = this->actualMaxWindSpeed;
  v16 = (float)((float)v12 * this->actualMaxWindSpeed);
  this->windDirection.y = (float)v13 * this->actualMaxWindSpeed;
  this->windDirection.x = (float)actualMaxWindSpeed * (float)v14;
  this->windDirection.z = v16;
  if ( this->GetFXDecl(this) != nullptr )
  {
    minDetonationHeight = this->minDetonationHeight;
    if ( minDetonationHeight != 0.0 || this->maxDetonationHeight != 0.0 )
    {
      v18 = RandomFloat(min: minDetonationHeight, max: this->maxDetonationHeight);
      this->actualDetonationHeight = v18;
      if ( v18 == 0.0 )
        this->actualDetonationHeight = 981668463;
    }
  }
  if ( this->targets.num > 0
    && (value = this->targets.list->spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v20 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v21 = (idSplinePath *)idEntity::CastTo(c: v20);
  }
  else
  {
    v21 = nullptr;
  }
  v22 = idSplinePath::CastTo(c: v21);
  if ( v22 != nullptr )
  {
    v23 = idSplinePath::AllocSpline(this: v22);
    this->spline = v23;
    if ( v23 != nullptr )
    {
      ((void (__fastcall *)(float *, double))v23->GetCurrentValue)(a1: v38, a2: this->splineDistance);
      v24 = v38[1];
      v25 = v38[2];
      this->lastOrigin.x = v38[0];
      this->lastOrigin.y = v24;
      this->lastOrigin.z = v25;
      idEntity::SetOrigin(this, org: &this->lastOrigin);
      this->lastSplinePosition.x = this->lastOrigin.x;
      this->lastSplinePosition.y = this->lastOrigin.y;
      v26 = clientGame;
      this->lastSplinePosition.z = this->lastOrigin.z;
      GameMs = idGameTimeManager::GetGameMs(this: &v26->gameTimeManager, type: GAMETIME_SCALED);
      presentable = this->presentable;
      v29 = GameMs;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        presentable = this->presentable;
      }
      idFXManager::StopAllFX(this: &presentable->fxManager, time: v29, immediateStop: true);
      idPhysics::InitPhysics(
        this: &this->physicsObj,
        clip_: &clientGame->clip,
        callbacks_: &this->physicsCallbacks,
        entityNumber_: this->entityNumber);
      idEntity::SetPhysics(this, phys: &this->physicsObj, a3: v30);
      v31 = this->physicsObj.__vftable;
      MoveableClipModel = idEntity::CreateMoveableClipModel(this, barrelCollision: true, overrideRadius: -1.0);
      ((void (__fastcall *)(idPhysics_RigidBody *, idClipModel *, double))v31->SetClipModel)(
        a1: &this->physicsObj,
        a2: MoveableClipModel,
        a3: 1.0);
      this->physicsObj.SetContents(this: &this->physicsObj, a2: this->solid, a3: -1);
      this->physicsObj.SetClipMask(this: &this->physicsObj, a2: this->solid, a3: -1);
      if ( this->health > 0.0 )
        *(_BYTE *)&this->flags |= 2u;
      v33 = this->presentable;
      if ( v33 == nullptr || (v34 = 1, v33->model == nullptr) )
        v34 = 0;
      if ( v34 != 0 )
      {
        if ( v33 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v33 = this->presentable;
        }
        v33->model->g.castDimShadows = DIMSHADOW_ON;
        idEntity::GetRenderModelFromPresentable(this)->useDeferredPosition = true;
        v35 = this->presentable;
        if ( v35 == nullptr )
        {
          idEntity::InitPresentableInternal(this);
          v35 = this->presentable;
        }
        highlightColor = this->highlightColor;
        model = v35->model;
        v35->highlightColor = highlightColor;
        model->g.highlightColor = highlightColor;
      }
      idEntity::BecomeActive(this, flags: 5);
    }
    else
    {
      idLib::Warning(fmt: "Spline follower '%s' can't alloc spline.", this->name.data);
    }
  }
  else
  {
    idLib::Warning(fmt: "Spline follower '%s' does not have a valid spline path as it's first target.", this->name.data);
  }
}


// ========================================================================
// `dynamic initializer for 'g_balloonDebugShowTrails''
// EA  : 0x83378650
// RVA : 0x01378650
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_balloonDebugShowTrails__()
{
  idCVar::idCVar(
    this: &g_balloonDebugShowTrails,
    name: "g_balloonDebugShowTrails",
    value: "0",
    flags: 1,
    description: "1 = show debug trails to visualize balloon movement.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_balloonDebugShowTrails__);
}


// ========================================================================
// `dynamic initializer for 'g_balloonDebugIgnorePlayer''
// EA  : 0x833786A8
// RVA : 0x013786A8
// PDB : w:\tech5\tungsten\game\entities\splinefollower.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_balloonDebugIgnorePlayer__()
{
  idCVar::idCVar(
    this: &g_balloonDebugIgnorePlayer,
    name: "g_balloonDebugIgnorePlayer",
    value: "0",
    flags: 1,
    description: "1 = ignore the player's approach--don't explode when player is near.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_balloonDebugIgnorePlayer__);
}

