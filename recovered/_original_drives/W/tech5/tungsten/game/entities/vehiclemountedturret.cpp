
// ========================================================================
// ?PullTrigger@idVehicleMountedTurret@@QAAXXZ
// EA  : 0x82D30450
// RVA : 0x00D30450
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void __fastcall idVehicleMountedTurret::PullTrigger(idVehicleMountedTurret *this)
{
  this->weapon->PullTrigger(this: this->weapon, a2: nullptr, a3: false);
}


// ========================================================================
// ?ReleaseTrigger@idVehicleMountedTurret@@QAAXXZ
// EA  : 0x82D30470
// RVA : 0x00D30470
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void __fastcall idVehicleMountedTurret::ReleaseTrigger(idVehicleMountedTurret *this)
{
  this->weapon->ReleaseTrigger(this: this->weapon, a2: nullptr);
}


// ========================================================================
// ?GetSeatState@idVehicleMountedTurret@@QBA?AW4seatState_t@1@XZ
// EA  : 0x82D30488
// RVA : 0x00D30488
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

idVehicleMountedTurret::seatState_t __fastcall idVehicleMountedTurret::GetSeatState(idVehicleMountedTurret *this)
{
  return this->seatState;
}


// ========================================================================
// ?GetFXDecl@idVehicleMountedTurret@@UBAPBVidDeclFX@@XZ
// EA  : 0x82D30490
// RVA : 0x00D30490
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

const idDeclFX *__fastcall idVehicleMountedTurret::GetFXDecl(idVehicleMountedTurret *this)
{
  const idDeclWeapon *weaponDecl; // r11
  const idDeclFX *weaponFX; // r11

  weaponDecl = this->weaponDecl;
  if ( weaponDecl != nullptr && (weaponFX = weaponDecl->weaponFX) != nullptr )
    return weaponFX;
  else
    return this->fxDecl;
}


// ========================================================================
// ?SetTargetPos@idVehicleMountedTurret@@QAAXABVidVec3@@@Z
// EA  : 0x82D304B8
// RVA : 0x00D304B8
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void __fastcall idVehicleMountedTurret::SetTargetPos(idVehicleMountedTurret *this, const idVec3 *targetPos)
{
  this->targetPos = *targetPos;
  this->hasValidTarget = true;
}


// ========================================================================
// ?GetTriggerState@idVehicleMountedTurret@@QBA?AW4triggerState_t@idWeapon@@XZ
// EA  : 0x82D304E0
// RVA : 0x00D304E0
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

idWeapon::triggerState_t __fastcall idVehicleMountedTurret::GetTriggerState(idVehicleMountedTurret *this)
{
  return this->weapon->triggerState;
}


// ========================================================================
// ?IsManned@idVehicleMountedTurret@@QBA_NXZ
// EA  : 0x82D304F0
// RVA : 0x00D304F0
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

BOOL __fastcall idVehicleMountedTurret::IsManned(idVehicleMountedTurret *this)
{
  int value; // r10
  idTurretGunner *v2; // r3

  value = this->gunner.spawnId.value;
  return gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v2 = (idTurretGunner *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && idTurretGunner::CastTo(c: v2) != nullptr;
}


// ========================================================================
// ?AnimEvent_RaiseSeat@idVehicleMountedTurret@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82D30570
// RVA : 0x00D30570
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

idVehicleMountedTurret *__fastcall idVehicleMountedTurret::AnimEvent_RaiseSeat(
        idVehicleMountedTurret *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  int v3; // r10
  idTurretGunner *v5; // r3
  idTurretGunner *v6; // r3
  idTurretGunner *v7; // r3

  v3 = *(_DWORD *)&result[6092];
  if ( gameLocal->spawnIds.ptr[v3 & 0x1FFF] == v3 >> 13
    && (v5 = (idTurretGunner *)gameLocal->entities.ptr[v3 & 0x1FFF]) != nullptr )
  {
    v6 = idTurretGunner::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  v7 = idTurretGunner::CastTo(c: v6);
  if ( v7 != nullptr )
    idTurretGunner::RaiseSeat(this: v7);
  return this;
}


// ========================================================================
// ?AnimEvent_LowerSeat@idVehicleMountedTurret@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82D305F8
// RVA : 0x00D305F8
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

idVehicleMountedTurret *__fastcall idVehicleMountedTurret::AnimEvent_LowerSeat(
        idVehicleMountedTurret *this,
        eventVoid *result,
        const idMD6Anim *animHandle)
{
  int v3; // r10
  idTurretGunner *v5; // r3
  idTurretGunner *v6; // r3
  idTurretGunner *v7; // r3

  v3 = *(_DWORD *)&result[6092];
  if ( gameLocal->spawnIds.ptr[v3 & 0x1FFF] == v3 >> 13
    && (v5 = (idTurretGunner *)gameLocal->entities.ptr[v3 & 0x1FFF]) != nullptr )
  {
    v6 = idTurretGunner::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  v7 = idTurretGunner::CastTo(c: v6);
  if ( v7 != nullptr )
    idTurretGunner::LowerSeat(this: v7);
  return this;
}


// ========================================================================
// ?Think@idVehicleMountedTurret@@UAAXXZ
// EA  : 0x82D30688
// RVA : 0x00D30688
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void __fastcall idVehicleMountedTurret::Think(idVehicleMountedTurret *this)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idTreeAnimator *v4; // r27
  unsigned int value; // r9
  BOOL hasValidTarget; // r11
  double v7; // fp0
  float *p_deferredAxis; // r11
  double v9; // fp13
  double v10; // fp11
  double v11; // fp9
  double v12; // fp8
  idQuat *v13; // r3
  const idIndex<short,enum invalidJointIndex_t> *v14; // r5
  float *p_axis; // r11
  double v16; // fp0
  double v17; // fp13
  double v18; // fp11
  double v19; // fp9
  double v20; // fp8
  long double v21; // fp2
  int *v22; // r10
  int *v23; // r11
  int i; // ctr
  long double v25; // fp2
  idQuat *v26; // r3
  const idMat3 *v27; // r3
  double v28; // fp13
  double v29; // fp12
  double v30; // fp11
  const idMat3 *v31; // r3
  double v32; // fp9
  double v33; // fp8
  double v34; // fp7
  idClipModel **v35; // r26
  char *v36; // r29
  idPropsCollection *p_props; // r25
  int j; // r28
  const char *v39; // r5
  const tagData_t *Tag; // r3
  idWeapon *weapon; // r3
  double v42; // fp0
  double v43; // fp13
  double v44; // fp12
  double v45; // fp11
  double v46; // fp10
  double v47; // fp9
  double v48; // fp8
  double v49; // fp7
  double v50; // fp6
  double v51; // fp5
  double v52; // fp4
  double v53; // fp3
  idWeapon::fireState_t fireState; // r11
  idPresentable *v55; // r11
  double currentHeat; // fp0
  _DWORD *v57; // r11
  int k; // ctr
  int v59; // r9
  idTurretGunner *v60; // r3
  idTurretGunner *v61; // r29
  idPresentable *v62; // r4
  char v63; // r26
  int v64; // r28
  trace_t *traces; // r29
  idAI2 *v66; // r3
  idAI2 *v67; // r3
  const idFaction *v68; // r4
  idPresentable *v69; // r11
  float v70[12]; // [sp+50h] [-C50h] BYREF
  idQuat v71; // [sp+80h] [-C20h] BYREF
  idMat3 v72; // [sp+90h] [-C10h] BYREF
  int v73; // [sp+BCh] [-BE4h] BYREF
  idQuat v74; // [sp+C0h] [-BE0h] BYREF
  float v75; // [sp+D0h] [-BD0h]
  float v76; // [sp+D4h] [-BCCh]
  float x; // [sp+D8h] [-BC8h]
  float y; // [sp+DCh] [-BC4h]
  float z; // [sp+E0h] [-BC0h]
  idMat3 v80; // [sp+F0h] [-BB0h] BYREF
  float v81; // [sp+114h] [-B8Ch]
  float v82; // [sp+118h] [-B88h]
  idVec3 v83; // [sp+120h] [-B80h] BYREF
  idVec3 v84; // [sp+130h] [-B70h] BYREF
  idVec3 v85; // [sp+140h] [-B60h] BYREF
  idMat3 v86; // [sp+150h] [-B50h] BYREF
  idMat3 v87; // [sp+180h] [-B20h] BYREF
  idEntityPtr<idTurretGunner> *p_gunner; // [sp+1A4h] [-AFCh]
  idVec3 v89; // [sp+1A8h] [-AF8h] BYREF
  int v90; // [sp+1BCh] [-AE4h] BYREF
  idMat3 v91; // [sp+1C0h] [-AE0h] BYREF
  idMat3 v92; // [sp+1F0h] [-AB0h] BYREF
  idMat3 v93; // [sp+220h] [-A80h] BYREF
  idFireParms v94; // [sp+250h] [-A50h] BYREF
  _DWORD v95[20]; // [sp+2F0h] [-9B0h] BYREF
  idTestFireResults v96; // [sp+340h] [-960h] BYREF

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this);
  presentable = this->presentable;
  v4 = TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  value = (unsigned __int16)this->yawJoint.value;
  if ( value < 0x8000 && (unsigned __int16)this->pitchJoint.value < 0x8000u )
  {
    hasValidTarget = this->hasValidTarget;
    v70[8] = 0.0;
    v70[9] = 0.0;
    v70[10] = 0.0;
    v70[11] = 1.0;
    v71.x = 0.0;
    v71.y = 0.0;
    v71.z = 0.0;
    v71.w = 1.0;
    if ( hasValidTarget )
    {
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: v4,
        pose: (animationPose_t)0,
        jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)value,
        origin: &v83,
        axis: &v92);
      v7 = (float)(this->targetPos.z - v83.z);
      p_deferredAxis = (float *)&v4->deferredAxis;
      if ( !v4->useDeferredPosition )
        p_deferredAxis = (float *)&v4->g.axis;
      v10 = p_deferredAxis[2];
      v11 = (float)((float)(p_deferredAxis[3] * (float)(this->targetPos.x - v83.x))
                  + (float)(p_deferredAxis[4] * (float)(this->targetPos.y - v83.y)));
      v12 = (float)((float)(*p_deferredAxis * (float)(this->targetPos.x - v83.x))
                  + (float)(p_deferredAxis[1] * (float)(this->targetPos.y - v83.y)));
      v9 = p_deferredAxis[5];
      v70[2] = (float)(p_deferredAxis[8] * (float)(this->targetPos.z - v83.z))
             + (float)((float)(p_deferredAxis[6] * (float)(this->targetPos.x - v83.x))
                     + (float)(p_deferredAxis[7] * (float)(this->targetPos.y - v83.y)));
      v70[1] = (float)((float)v9 * (float)v7) + (float)v11;
      v70[0] = (float)((float)v10 * (float)v7) + (float)v12;
      idVec3::ProjectOntoPlane(this: (idVec3 *)v70, normal: &vec3_up, overBounce: 1.0);
      idVec3::NormalizeFast(this: (idVec3 *)v70);
      x = vec3_up.x;
      y = vec3_up.y;
      z = vec3_up.z;
      v74.x = v70[0];
      v74.y = v70[1];
      v74.z = v70[2];
      v75 = (float)(vec3_up.z * v70[0]) - (float)(vec3_up.x * v70[2]);
      v76 = (float)(vec3_up.x * v70[1]) - (float)(vec3_up.y * v70[0]);
      v74.w = (float)(vec3_up.y * v70[2]) - (float)(vec3_up.z * v70[1]);
      v13 = idMat3::ToQuat(this: (idMat3 *)v70, result: &v74);
      v14 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJoint.value;
      *(idQuat *)&v70[8] = *v13;
      idTreeAnimator::GetWorldSpaceJointTransform(
        this: v4,
        pose: (animationPose_t)0,
        jointIndex: v14,
        origin: (idVec3 *)&v80.mat[2].z,
        axis: &v93);
      p_axis = (float *)&v4->deferredAxis;
      v16 = (float)(this->targetPos.z - v82);
      if ( !v4->useDeferredPosition )
        p_axis = (float *)&v4->g.axis;
      v18 = p_axis[2];
      v19 = (float)((float)(p_axis[3] * (float)(this->targetPos.x - v80.mat[2].z))
                  + (float)(p_axis[4] * (float)(this->targetPos.y - v81)));
      v20 = (float)((float)(*p_axis * (float)(this->targetPos.x - v80.mat[2].z))
                  + (float)(p_axis[1] * (float)(this->targetPos.y - v81)));
      v17 = p_axis[5];
      v70[2] = (float)(p_axis[8] * (float)(this->targetPos.z - v82))
             + (float)((float)(p_axis[6] * (float)(this->targetPos.x - v80.mat[2].z))
                     + (float)(p_axis[7] * (float)(this->targetPos.y - v81)));
      v70[1] = (float)((float)v17 * (float)v16) + (float)v19;
      v70[0] = (float)((float)v18 * (float)v16) + (float)v20;
      idVec3::ProjectOntoPlane(this: (idVec3 *)v70, normal: (const idVec3 *)&v74.w, overBounce: 1.0);
      idVec3::NormalizeFast(this: (idVec3 *)v70);
      v22 = &v90;
      v23 = &v73;
      for ( i = 9; i != 0; --i )
        *++v22 = *++v23;
      *(double *)&v21 = (float)((float)(x * v70[0]) + (float)((float)(z * v70[2]) + (float)(y * v70[1])));
      v25 = acos(x: v21);
      idMat3::RotateSelf(
        this: &v91,
        axis: &v91.mat[1],
        angle: (float)-(float)((float)((float)3.1415927 * (float)0.5) - (float)*(double *)&v25));
      v71 = *idMat3::ToQuat(this: (idMat3 *)v70, result: (idQuat *)&v91);
    }
    v26 = idQuat::Slerp(
            this: &this->lastYawRot,
            from: &this->lastYawRot,
            to: (const idQuat *)&v70[8],
            t: this->slerpRate);
    v80.mat[0].x = v26->x;
    v80.mat[0].y = v26->y;
    v80.mat[0].z = v26->z;
    v80.mat[1].x = v26->w;
    v27 = idQuat::ToMat3(this: (idQuat *)&v93, result: &v80);
    idTreeAnimator::SetJointAxis(
      this: v4,
      pose: (animationPose_t)0,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->yawJoint.value,
      type: JOINTMOD_MODEL_OVERRIDE,
      axis: v27);
    v28 = v80.mat[0].y;
    v29 = v80.mat[0].z;
    v30 = v80.mat[1].x;
    this->lastYawRot.x = v80.mat[0].x;
    this->lastYawRot.y = v28;
    this->lastYawRot.z = v29;
    this->lastYawRot.w = v30;
    *(idQuat *)&v80.mat[1].y = *idQuat::Slerp(
                                  this: &this->lastPitchRot,
                                  from: &this->lastPitchRot,
                                  to: &v71,
                                  t: this->slerpRate);
    v31 = idQuat::ToMat3(this: (idQuat *)&v93, result: (idMat3 *)&v80.mat[1].y);
    idTreeAnimator::SetJointAxis(
      this: v4,
      pose: (animationPose_t)0,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)this->pitchJoint.value,
      type: JOINTMOD_MODEL_OVERRIDE,
      axis: v31);
    v32 = v80.mat[1].z;
    v33 = v80.mat[2].x;
    v34 = v80.mat[2].y;
    this->lastPitchRot.x = v80.mat[1].y;
    this->lastPitchRot.y = v32;
    this->lastPitchRot.z = v33;
    this->lastPitchRot.w = v34;
  }
  v35 = (idClipModel **)&this->shieldModelTags[1].baseBuffer[16];
  v36 = &this->pitchJointName.baseBuffer[16];
  p_props = &v4->decl->props;
  for ( j = 2; j != 0; --j )
  {
    v39 = *((const char **)v36 + 24);
    v36 += 32;
    Tag = idPropsCollection::GetTag(this: p_props, propName: *(const char **)v36, tagName: v39);
    idTreeAnimator::GetWorldSpaceTagTransform(this: v4, tagData: Tag, origin: &v89, axis: &v92);
    idClipModel::SetLinkedPosition(this: *++v35, newOrigin: &v89, newAxis: &v92);
  }
  idWeapon::UpdateState(this: this->weapon, inventory: &this->inventory, secondaryAmmo: false);
  weapon = this->weapon;
  if ( this->weaponDecl->attackSequence != ATTACKSEQ_DEFAULT )
  {
    idWeapon::GetMuzzleFlashWorldTransform(this: weapon, ta: v4, attackType: ATTACK_LEFT, origin: &v85, axis: &v86);
    idWeapon::GetMuzzleFlashWorldTransform(
      this: this->weapon,
      ta: v4,
      attackType: ATTACK_RIGHT,
      origin: &v84,
      axis: &v87);
    if ( this->weapon->attackType == ATTACK_LEFT )
    {
      v42 = v85.x;
      v43 = v85.y;
      v44 = v85.z;
      v45 = v86.mat[0].x;
      v46 = v86.mat[0].y;
      v47 = v86.mat[0].z;
      v48 = v86.mat[1].x;
      v49 = v86.mat[1].y;
      v50 = v86.mat[1].z;
      v51 = v86.mat[2].x;
      v52 = v86.mat[2].y;
      v53 = v86.mat[2].z;
    }
    else
    {
      v42 = v84.x;
      v43 = v84.y;
      v44 = v84.z;
      v45 = v87.mat[0].x;
      v46 = v87.mat[0].y;
      v47 = v87.mat[0].z;
      v48 = v87.mat[1].x;
      v49 = v87.mat[1].y;
      v50 = v87.mat[1].z;
      v51 = v87.mat[2].x;
      v52 = v87.mat[2].y;
      v53 = v87.mat[2].z;
    }
    v72.mat[2].z = v53;
    v72.mat[2].y = v52;
    v72.mat[2].x = v51;
    v72.mat[1].z = v50;
    v72.mat[1].y = v49;
    v72.mat[1].x = v48;
    v72.mat[0].z = v47;
    v72.mat[0].y = v46;
    v72.mat[0].x = v45;
    v70[6] = v44;
    v70[5] = v43;
    v70[4] = v42;
  }
  else
  {
    idWeapon::GetMuzzleFlashWorldTransform(
      this: weapon,
      ta: v4,
      attackType: ATTACK_DEFAULT,
      origin: (idVec3 *)&v70[4],
      axis: &v72);
  }
  fireState = this->weapon->fireState;
  if ( fireState == FIRESTATE_IDLE )
  {
LABEL_28:
    this->currentHeat = this->currentHeat - this->heatLostPerFrame;
    goto LABEL_29;
  }
  if ( fireState != FIRESTATE_FIRING )
  {
    if ( fireState != FIRESTATE_RELOADING )
      goto LABEL_29;
    v55 = this->presentable;
    if ( v55 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v55 = this->presentable;
    }
    this->weapon->Reload(this: this->weapon, a2: &this->inventory, a3: &v55->fxManager, a4: false, a5: false, a6: false);
    goto LABEL_28;
  }
  if ( idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < this->weapon->nextFireTime )
    goto LABEL_29;
  idFireParms::idFireParms(this: &v94);
  memset(&v96, 0, sizeof(v96));
  v57 = v95;
  v95[0] = 0;
  for ( k = 16; k != 0; --k )
    *++v57 = 0;
  v59 = this->gunner.spawnId.value;
  p_gunner = &this->gunner;
  *((_BYTE *)&v94 + 128) |= 0x20u;
  if ( gameLocal->spawnIds.ptr[v59 & 0x1FFF] == v59 >> 13
    && (v60 = (idTurretGunner *)gameLocal->entities.ptr[v59 & 0x1FFF]) != nullptr )
  {
    v61 = idTurretGunner::CastTo(c: v60);
  }
  else
  {
    v61 = nullptr;
  }
  v62 = v61->presentable;
  if ( v62 == nullptr )
  {
    idEntity::InitPresentableInternal(this: v61);
    v62 = v61->presentable;
  }
  if ( !idWeapon::TestFire(
          this: this->weapon,
          attacker: v62,
          target: nullptr,
          start: (const idVec3 *)&v70[4],
          fireAxis: &v72,
          fp: &v94,
          tfr: &v96,
          secondaryAmmo: false) )
    goto LABEL_57;
  v63 = 1;
  if ( !this->safeFireMode )
    goto LABEL_53;
  v64 = 0;
  if ( v96.numTraces <= 0 )
    goto LABEL_53;
  traces = v96.traces;
  while ( 1 )
  {
    if ( traces->fraction < 1.0 )
    {
      v66 = (idAI2 *)gameLocal->entities.ptr[traces->c.entityNum];
      if ( v66 == nullptr )
        goto LABEL_50;
      v67 = idAI2::CastTo(c: v66);
      if ( v67 == nullptr )
        goto LABEL_50;
      v68 = v67->GetFaction(this: v67);
      if ( v68 != nullptr )
        break;
      idLib::Warning(
        fmt: "ai '%s' needs to have a faction set so the vehicle mounted turret can interact.",
        this->name.data);
    }
LABEL_50:
    ++v64;
    ++traces;
    if ( v64 >= v96.numTraces )
      goto LABEL_53;
  }
  if ( idFaction::GetAttitudeTowards(this: &this->faction, otherFaction: v68) <= ATTITUDE_NEUTRAL )
    goto LABEL_50;
  v63 = 0;
LABEL_53:
  if ( v63 != 0 )
  {
    v69 = this->presentable;
    if ( v69 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v69 = this->presentable;
    }
    this->weapon->FinishFire(
      this: this->weapon,
      a2: &v94,
      a3: &v96,
      a4: (idFinishFireResults *)v95,
      a5: &v69->fxManager,
      a6: false);
    this->currentHeat = this->heatGainPerShot + this->currentHeat;
  }
LABEL_57:
  if ( v94.targetList.listStatic == 0 || v94.targetList.listStatic == 2 )
  {
    if ( v94.targetList.list != nullptr )
      idMem::Free(this: &mem, ptr: v94.targetList.list, align: ALIGN_16);
    v94.targetList.list = nullptr;
    v94.targetList.size = 0;
  }
  v94.targetList.num = 0;
LABEL_29:
  currentHeat = this->currentHeat;
  if ( currentHeat >= 0.0 )
  {
    if ( currentHeat > 100.0 )
      currentHeat = 100.0;
  }
  else
  {
    currentHeat = 0.0;
  }
  this->currentHeat = currentHeat;
  idAnimatedEntity::Think(this);
}


// ========================================================================
// __unwind$489329_1
// EA  : 0x82D30F4C
// RVA : 0x00D30F4C
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_489329_1()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 3232 + 592));
}


// ========================================================================
// ?GetWebState@idVehicleMountedTurret@@ABAXAAVidStr@@0@Z
// EA  : 0x82D30F78
// RVA : 0x00D30F78
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void __fastcall idVehicleMountedTurret::GetWebState(idVehicleMountedTurret *this, idStr *subWebName, idStr *stateName)
{
  const char *v6; // r4
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  va *v10; // r3
  int v11; // [sp+8h] [-1068h]
  int v12; // [sp+Ch] [-1064h]
  int v13; // [sp+10h] [-1060h]
  int v14; // [sp+14h] [-105Ch]
  int v15; // [sp+18h] [-1058h]
  int v16; // [sp+1Ch] [-1054h]
  va v17; // [sp+50h] [-1020h] BYREF

  if ( idVehicleMountedTurret::IsManned(this) )
    v6 = "manned";
  else
    v6 = "unmanned";
  idStr::operator=(this: subWebName, text: v6);
  HIDWORD(v7) = idVehicleMountedTurret::seatStateNames;
  LODWORD(v8) = idVehicleMountedTurret::weaponNames;
  LODWORD(v7) = 4 * this->selectedWeapon;
  HIDWORD(v8) = &unk_82200000;
  LODWORD(v9) = idVehicleMountedTurret::seatStateNames[this->seatState];
  HIDWORD(v9) = *(const char **)((char *)idVehicleMountedTurret::weaponNames + v7);
  v10 = va::va(this: &v17, fmt: "%s_%s", a3: v9, a4: v8, a5: v7, a6: v11, a7: v12, a8: v13, a9: v14, a10: v15, a11: v16);
  idStr::operator=(this: stateName, text: v10);
}


// ========================================================================
// ?AnimateToState@idVehicleMountedTurret@@AAAXXZ
// EA  : 0x82D31018
// RVA : 0x00D31018
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void __fastcall idVehicleMountedTurret::AnimateToState(idVehicleMountedTurret *this)
{
  idStr v2; // [sp+50h] [-60h] BYREF
  idStr v3; // [sp+70h] [-40h] BYREF

  v3.len = 0;
  v3.allocedAndFlag = 20;
  v3.data = v3.baseBuffer;
  v3.baseBuffer[0] = 0;
  v2.allocedAndFlag = 20;
  v2.data = v2.baseBuffer;
  v2.len = 0;
  v2.baseBuffer[0] = 0;
  idVehicleMountedTurret::GetWebState(this, subWebName: &v3, stateName: &v2);
  idAnimator_AnimWeb::ChangeState(
    this: &this->animWeb,
    subWebName: v3.data,
    stateName: v2.data,
    interruptPath_: INTR_PATH_YES,
    interruptBlend_: INTR_BLEND_NO,
    blendEventMask_: 0);
  idStr::FreeData(this: &v2);
  idStr::FreeData(this: &v3);
}


// ========================================================================
// __unwind$490152_0
// EA  : 0x82D310B4
// RVA : 0x00D310B4
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490152_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$490153_0
// EA  : 0x82D310DC
// RVA : 0x00D310DC
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490153_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 80));
}


// ========================================================================
// ?RaiseSeat@idVehicleMountedTurret@@QAAXXZ
// EA  : 0x82D31108
// RVA : 0x00D31108
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void __fastcall idVehicleMountedTurret::RaiseSeat(idVehicleMountedTurret *this)
{
  if ( this->seatState != SEATSTATE_RAISED )
  {
    this->seatState = SEATSTATE_RAISED;
    idVehicleMountedTurret::AnimateToState(this);
  }
}


// ========================================================================
// ?OnActivate@idVehicleMountedTurret@@UAAXPAVidEntity@@@Z
// EA  : 0x82D31128
// RVA : 0x00D31128
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void __fastcall idVehicleMountedTurret::OnActivate(idVehicleMountedTurret *this, idEntity *activator)
{
  this->seatState = this->seatState == SEATSTATE_LOWERED;
  idVehicleMountedTurret::AnimateToState(this);
}


// ========================================================================
// ??0idVehicleMountedTurret@@QAA@XZ
// EA  : 0x82D31158
// RVA : 0x00D31158
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

idVehicleMountedTurret *__fastcall idVehicleMountedTurret::idVehicleMountedTurret(idVehicleMountedTurret *this)
{
  idAnimatedEntity::idAnimatedEntity(this);
  this->slerpRate = 0.1;
  this->__vftable = (idVehicleMountedTurret_vtbl *)&idVehicleMountedTurret::`vftable';
  this->webDecl = nullptr;
  this->gunnerDef = nullptr;
  this->yawJointName.allocedAndFlag = 20;
  this->yawJointName.data = this->yawJointName.baseBuffer;
  this->yawJointName.len = 0;
  this->yawJointName.baseBuffer[0] = 0;
  this->pitchJointName.allocedAndFlag = 20;
  this->pitchJointName.len = 0;
  this->pitchJointName.data = this->pitchJointName.baseBuffer;
  this->pitchJointName.baseBuffer[0] = 0;
  this->weaponDecl = nullptr;
  idFaction::idFaction(this: &this->faction);
  `eh vector constructor iterator'(
    ptr: this->shieldModels,
    size: 0x20u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  `eh vector constructor iterator'(
    ptr: this->shieldModelTags,
    size: 0x20u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))idZippedFile::idZippedFile,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  this->heatLostPerFrame = 0.1;
  this->heatGainPerShot = 1.0;
  idAnimator_AnimWeb::idAnimator_AnimWeb(this: &this->animWeb);
  this->gunner.spawnId.value = 0x1FFF;
  this->targetPos.x = 0.0;
  this->targetPos.y = 0.0;
  this->targetPos.z = 0.0;
  this->lastYawRot.x = 0.0;
  this->lastYawRot.y = 0.0;
  this->lastYawRot.z = 0.0;
  this->lastYawRot.w = 1.0;
  this->lastPitchRot.x = 0.0;
  this->lastPitchRot.y = 0.0;
  this->lastPitchRot.z = 0.0;
  this->lastPitchRot.w = 1.0;
  this->yawJoint.value = -1;
  this->pitchJoint.value = -1;
  idInventoryCollection::idInventoryCollection(this: &this->inventory);
  this->weapon = nullptr;
  this->selectedWeapon = WEAPON_MACHINEGUN;
  this->seatState = SEATSTATE_LOWERED;
  this->hasValidTarget = false;
  this->safeFireMode = true;
  idMQBuffer::idMQBuffer(this: &this->attachments);
  this->currentHeat = 0.0;
  this->attachments.parent = this;
  this->shieldClipModels[0] = nullptr;
  this->shieldClipModels[1] = nullptr;
  return this;
}


// ========================================================================
// __unwind$490369
// EA  : 0x82D31300
// RVA : 0x00D31300
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490369()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$490370
// EA  : 0x82D31328
// RVA : 0x00D31328
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490370()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 5212));
}


// ========================================================================
// __unwind$490371
// EA  : 0x82D31354
// RVA : 0x00D31354
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490371()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 5244));
}


// ========================================================================
// __unwind$490372
// EA  : 0x82D31380
// RVA : 0x00D31380
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490372()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 144 + 164) + 5280));
}


// ========================================================================
// __unwind$490373
// EA  : 0x82D313AC
// RVA : 0x00D313AC
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490373()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 5300),
    size: 0x20u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$490374_0
// EA  : 0x82D313E8
// RVA : 0x00D313E8
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490374_0()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 5364),
    size: 0x20u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$490375
// EA  : 0x82D31424
// RVA : 0x00D31424
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490375()
{
  int v0; // r12

  idAnimator_AnimWeb::~idAnimator_AnimWeb(this: (idAnimator_AnimWeb *)(*(_DWORD *)(v0 - 144 + 164) + 5444));
}


// ========================================================================
// __unwind$490376
// EA  : 0x82D31450
// RVA : 0x00D31450
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490376()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 6144));
}


// ========================================================================
// ??1idVehicleMountedTurret@@UAA@XZ
// EA  : 0x82D31570
// RVA : 0x00D31570
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void __fastcall idVehicleMountedTurret::~idVehicleMountedTurret(idVehicleMountedTurret *this)
{
  idClipModel **shieldClipModels; // r29
  int i; // r28
  idAttachment *list; // r4
  idInventoryItem **v5; // r4
  idRelationship *v6; // r4

  this->__vftable = (idVehicleMountedTurret_vtbl *)&idVehicleMountedTurret::`vftable';
  shieldClipModels = this->shieldClipModels;
  for ( i = 2; i != 0; --i )
  {
    if ( *shieldClipModels != nullptr )
    {
      idClipModel::Delete(this: *shieldClipModels);
      *shieldClipModels = nullptr;
    }
    ++shieldClipModels;
  }
  if ( this->attachments.attachments.listStatic == 0 || this->attachments.attachments.listStatic == 2 )
  {
    list = this->attachments.attachments.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->attachments.attachments.list = nullptr;
    this->attachments.attachments.size = 0;
  }
  this->attachments.attachments.num = 0;
  if ( this->inventory.inventory.listStatic == 0 || this->inventory.inventory.listStatic == 2 )
  {
    v5 = this->inventory.inventory.list;
    if ( v5 != nullptr )
      idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
    this->inventory.inventory.list = nullptr;
    this->inventory.inventory.size = 0;
  }
  this->inventory.inventory.num = 0;
  idAnimator_AnimWeb::~idAnimator_AnimWeb(this: &this->animWeb);
  `eh vector destructor iterator'(
    ptr: this->shieldModelTags,
    size: 0x20u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  `eh vector destructor iterator'(
    ptr: this->shieldModels,
    size: 0x20u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
  if ( this->faction.relationships.relationships.listStatic == 0
    || this->faction.relationships.relationships.listStatic == 2 )
  {
    v6 = this->faction.relationships.relationships.list;
    if ( v6 != nullptr )
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
    this->faction.relationships.relationships.list = nullptr;
    this->faction.relationships.relationships.size = 0;
  }
  this->faction.relationships.relationships.num = 0;
  idStr::FreeData(this: &this->pitchJointName);
  idStr::FreeData(this: &this->yawJointName);
  idAnimatedEntity::~idAnimatedEntity(this);
}


// ========================================================================
// __unwind$490913
// EA  : 0x82D316D8
// RVA : 0x00D316D8
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490913()
{
  int v0; // r12

  idAnimatedEntity::~idAnimatedEntity(this: *(idAnimatedEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$490914
// EA  : 0x82D31700
// RVA : 0x00D31700
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490914()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 5212));
}


// ========================================================================
// __unwind$490915
// EA  : 0x82D3172C
// RVA : 0x00D3172C
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490915()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 5244));
}


// ========================================================================
// __unwind$490916
// EA  : 0x82D31758
// RVA : 0x00D31758
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490916()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 144 + 164) + 5280));
}


// ========================================================================
// __unwind$490917
// EA  : 0x82D31784
// RVA : 0x00D31784
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490917()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 5300),
    size: 0x20u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$490918
// EA  : 0x82D317C0
// RVA : 0x00D317C0
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490918()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 5364),
    size: 0x20u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idStrStatic<260>::~idStrStatic<260>);
}


// ========================================================================
// __unwind$490919
// EA  : 0x82D317FC
// RVA : 0x00D317FC
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490919()
{
  int v0; // r12

  idAnimator_AnimWeb::~idAnimator_AnimWeb(this: (idAnimator_AnimWeb *)(*(_DWORD *)(v0 - 144 + 164) + 5444));
}


// ========================================================================
// __unwind$490920
// EA  : 0x82D31828
// RVA : 0x00D31828
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490920()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 6144));
}


// ========================================================================
// __unwind$490921
// EA  : 0x82D31854
// RVA : 0x00D31854
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_490921()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 6960));
}


// ========================================================================
// ?Spawn@idVehicleMountedTurret@@QAAXXZ
// EA  : 0x82D31888
// RVA : 0x00D31888
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void __fastcall idVehicleMountedTurret::Spawn(idVehicleMountedTurret *this)
{
  idRenderModel *RenderModelFromPresentable; // r3
  idTreeAnimator *v3; // r21
  char *data; // r5
  const idMD6Model *model; // r11
  idMD6Skel *JointIndex; // r3
  char *v7; // r5
  const idMD6Model *v8; // r11
  idMD6Skel *v9; // r3
  __int16 v10; // r11
  int value; // r8
  idTurretGunner *v12; // r3
  idTurretGunner *v13; // r29
  idPresentable *presentable; // r3
  int entityNumber; // r11
  idPropsCollection *p_props; // r22
  const tagData_t *Tag; // r28
  idPhysics *Physics; // r3
  const idVec3 *v19; // r3
  idPhysics *v20; // r3
  idTurretGunner_vtbl *v21; // r26
  int v22; // r3
  const char *resourceError; // r29
  char *v24; // r28
  const char *v25; // r26
  int v26; // r25
  const idDeclAnimWeb *webDecl; // r24
  idAnimStack *v28; // r3
  const idDeclAnimWeb *v29; // r10
  idGameTimeManager *v30; // r3
  idAnimStack *v31; // r3
  idPresentable *v32; // r11
  idWeapon *v33; // r3
  idWeapon *v34; // r3
  int v35; // r28
  int v36; // r29
  idPresentable *v37; // r4
  idDeclWeapon::ammoClip *list; // r27
  const char **p_data; // r29
  const char **v40; // r27
  int i; // r28
  int v42; // r27
  idClipModel **shieldClipModels; // r28
  idMD6Skel_vtbl *v44; // r3
  idClipModel *v45; // r3
  const tagData_t *v46; // r3
  idPhysics *v47; // r3
  idPhysics *v48; // r3
  const char *v49; // [sp+8h] [-1E8h]
  const char *v50; // [sp+Ch] [-1E4h]
  int v51; // [sp+10h] [-1E0h]
  int v52; // [sp+14h] [-1DCh]
  int v53; // [sp+18h] [-1D8h]
  int v54; // [sp+1Ch] [-1D4h]
  int v55; // [sp+20h] [-1D0h]
  int v56; // [sp+24h] [-1CCh]
  int v57; // [sp+28h] [-1C8h]
  int v58; // [sp+2Ch] [-1C4h]
  int v59; // [sp+30h] [-1C0h]
  int v60; // [sp+34h] [-1BCh]
  int v61; // [sp+38h] [-1B8h]
  int v62; // [sp+3Ch] [-1B4h]
  int v63; // [sp+40h] [-1B0h]
  int v64; // [sp+44h] [-1ACh]
  int v65; // [sp+48h] [-1A8h]
  int v66; // [sp+4Ch] [-1A4h]
  int v67; // [sp+50h] [-1A0h]
  int v68; // [sp+58h] [-198h]
  int v69; // [sp+60h] [-190h]
  int v70; // [sp+68h] [-188h]
  idMD6Skel v71; // [sp+70h] [-180h] BYREF
  const char *v72; // [sp+A4h] [-14Ch]
  int v73; // [sp+A8h] [-148h]
  char v74; // [sp+ACh] [-144h] BYREF
  idVec3 v75; // [sp+C0h] [-130h] BYREF
  idMat3 v76; // [sp+D0h] [-120h] BYREF
  idAnimatorParms_AnimWeb v77; // [sp+100h] [-F0h] BYREF

  RenderModelFromPresentable = idEntity::GetRenderModelFromPresentable(this);
  v3 = (idTreeAnimator *)_RTDynamicCast(
                           inptr: RenderModelFromPresentable,
                           VfDelta: 0,
                           SrcType: &idRenderModel `RTTI Type Descriptor',
                           TargetType: &idTreeAnimator `RTTI Type Descriptor',
                           isReference: 0);
  if ( v3 == nullptr )
    idLib::Error(fmt: "%s - model is not a tree animator", this->name.data);
  data = this->yawJointName.data;
  model = v3->decl->model;
  if ( model != nullptr && (v71.__vftable = (idMD6Skel_vtbl *)model->skeleton, v71.__vftable != nullptr) )
  {
    JointIndex = idMD6Skel::GetJointIndex(
                   this: &v71,
                   result: (idIndex<short,enum invalidJointIndex_t> *)v71.__vftable,
                   name: data);
  }
  else
  {
    JointIndex = &v71;
    HIWORD(v71.__vftable) = -1;
  }
  v7 = this->pitchJointName.data;
  this->yawJoint.value = HIWORD(JointIndex->__vftable);
  v8 = v3->decl->model;
  if ( v8 != nullptr && (v71.__vftable = (idMD6Skel_vtbl *)v8->skeleton, v71.__vftable != nullptr) )
  {
    v9 = idMD6Skel::GetJointIndex(
           this: &v71,
           result: (idIndex<short,enum invalidJointIndex_t> *)v71.__vftable,
           name: v7);
  }
  else
  {
    v9 = &v71;
    HIWORD(v71.__vftable) = -1;
  }
  v10 = HIWORD(v9->__vftable);
  value = this->yawJoint.value;
  this->pitchJoint.value = HIWORD(v9->__vftable);
  if ( value == v10 )
    idLib::Error(fmt: "%s - pitch and yaw joints cannot be the same", this->name.data);
  v12 = (idTurretGunner *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: this->gunnerDef, a3: -1, a4: -1, a5: -1);
  v13 = idTurretGunner::CastTo(c: v12);
  if ( v13 == nullptr )
    idLib::Error(fmt: "%s - failed to spawn gunner", this->name.data);
  if ( idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v13) == nullptr )
    idLib::Error(fmt: "%s - gunner model is not a tree animator", this->name.data);
  presentable = v13->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: v13);
    presentable = v13->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  entityNumber = v13->entityNumber;
  v71.__vftable = (idMD6Skel_vtbl *)&this->gunner;
  this->gunner.spawnId.value = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
  p_props = &v3->decl->props;
  Tag = idPropsCollection::GetTag(this: p_props, propName: idPropInfo::INFO_PROP_NAME, tagName: "seat");
  if ( Tag->parentJoint.value == 0xFFFF )
    idLib::Error(fmt: "%s - no gunner attachment tag found on %s", this->name.data, v3->decl->name.str);
  Physics = idEntity::GetPhysics(this);
  v19 = Physics->GetOrigin(this: Physics, a2: 0);
  idEntity::SetOrigin(this: v13, org: v19);
  v20 = idEntity::GetPhysics(this);
  v21 = v13->__vftable;
  v22 = (int)v20->GetAxis(this: v20, a2: 0);
  v21->SetAxis(this: v13, a2: (const idMat3 *)v22);
  idEntity::BindToTag(this: v13, master: (idWorldspawn *)this, tag: Tag, orientated: true);
  *(_DWORD *)&v71.jointConversion.value = 0;
  v73 = 20;
  v72 = &v74;
  v74 = 0;
  v71.networkID = 20;
  v71.resourceError = (const char *)&v71.staleCount;
  v71.resourceListPtr = nullptr;
  HIBYTE(v71.staleCount) = 0;
  idVehicleMountedTurret::GetWebState(
    this,
    subWebName: (idStr *)&v71.jointConversion,
    stateName: (idStr *)&v71.resourceListPtr);
  resourceError = v71.resourceError;
  v24 = this->name.data;
  v25 = v72;
  v26 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  webDecl = this->webDecl;
  v28 = this->GetAnimStack_2(this);
  idAnimatorParms_AnimWeb::idAnimatorParms_AnimWeb(
    this: &v77,
    animStack_: v28,
    name_: v24,
    blendOp_: BOP_LERP,
    originBlend_: ORIGINBLEND_BRANCH,
    weightGroup_: MD6_WEIGHTGROUP_ALL,
    filterGroup_: MD6_WEIGHTGROUP_ALL,
    alpha_: 1.0,
    webDecl_: v29,
    initialSubWebName_: v49,
    initialStateName_: v50,
    curTime_: v51,
    a13: v52,
    a14: v53,
    a15: v54,
    a16: v55,
    a17: v56,
    a18: v57,
    a19: v58,
    a20: v59,
    a21: v60,
    a22: v61,
    a23: v62,
    a24: v63,
    a25: v64,
    a26: v65,
    a27: v66,
    a28: v67,
    a29: webDecl,
    a30: v68,
    a31: v25,
    a32: v69,
    a33: resourceError,
    a34: v70,
    a35: v26);
  v30 = gameLocal->GetGameTimeManager(this: gameLocal);
  idAnimator_Base::Init(this: &this->animWeb, gametimeManager: v30, parms: &v77);
  v31 = this->GetAnimStack_2(this);
  idAnimator_Base::SetEnabled(this: &this->animWeb, animStack: v31, enabled: true);
  v32 = this->presentable;
  if ( v32 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v32 = this->presentable;
  }
  v33 = (idWeapon *)idInventoryCollection::GiveItem(
                      this: &this->inventory,
                      owner: v32,
                      decl: this->weaponDecl,
                      count: 1,
                      forceCount: false,
                      canIntro: false);
  v34 = idWeapon::CastTo(c: v33);
  this->weapon = v34;
  if ( v34 == nullptr )
    idLib::Error(fmt: "%s - no weapon specified", this->name.data);
  v35 = 0;
  if ( this->weaponDecl->validAmmoClips.num > 0 )
  {
    v36 = 0;
    do
    {
      v37 = this->presentable;
      list = this->weaponDecl->validAmmoClips.list;
      if ( v37 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v37 = this->presentable;
      }
      idInventoryCollection::GiveItem(
        this: &this->inventory,
        owner: v37,
        decl: list[v36].validAmmoDecl,
        count: 1,
        forceCount: false,
        canIntro: false);
      ++v35;
      ++v36;
    }
    while ( v35 < this->weaponDecl->validAmmoClips.num );
  }
  p_data = (const char **)&this->shieldModels[0].data;
  v40 = (const char **)&this->pitchJointName.baseBuffer[16];
  for ( i = 2; i != 0; --i )
  {
    v40 += 8;
    idAttachmentCollection::AddAttachment(
      this: (idAttachmentCollection *)&v71,
      result: &this->attachments.attachments,
      modelName: *v40,
      tag: "shield");
  }
  v42 = 0;
  shieldClipModels = this->shieldClipModels;
  do
  {
    v44 = (idMD6Skel_vtbl *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0xD8u,
                              tag: TAG_CLIPMODEL,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
    v71.__vftable = v44;
    if ( v44 != nullptr )
      v45 = idClipModel::idClipModel(
              this: (idClipModel *)v44,
              clip: &clientGame->clip,
              name: *p_data,
              overrideClipMaterial: nullptr);
    else
      v45 = nullptr;
    *shieldClipModels = v45;
    if ( v45 != nullptr )
    {
      idClipModel::SetContents(this: v45, newContents: 128);
      v46 = idPropsCollection::GetTag(this: p_props, propName: *p_data, tagName: p_data[16]);
      idTreeAnimator::GetWorldSpaceTagTransform(this: v3, tagData: v46, origin: &v75, axis: &v76);
      v47 = idEntity::GetPhysics(this);
      idClipModel::Link(
        this: *shieldClipModels,
        newEntityNumber: this->entityNumber,
        newPhysicsId: v47->physicsId,
        newBodyId: v42 + 1,
        newOrigin: &v75,
        newAxis: &v76);
    }
    ++v42;
    ++shieldClipModels;
    p_data += 8;
  }
  while ( v42 < 2 );
  v48 = idEntity::GetPhysics(this);
  v48->SetContents(this: v48, a2: 640, a3: -1);
  idEntity::BecomeActive(this, flags: 5);
  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: &v77);
  idStr::FreeData(this: (idStr *)&v71.resourceListPtr);
  idStr::FreeData(this: (idStr *)&v71.jointConversion);
}


// ========================================================================
// $LN190
// EA  : 0x82D31E10
// RVA : 0x00D31E10
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _LN190()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 160));
}


// ========================================================================
// __unwind$491195_0
// EA  : 0x82D31E38
// RVA : 0x00D31E38
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_491195_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 128));
}


// ========================================================================
// __unwind$491196
// EA  : 0x82D31E60
// RVA : 0x00D31E60
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_491196()
{
  int v0; // r12

  idAnimatorParms_AnimWeb::~idAnimatorParms_AnimWeb(this: (idAnimatorParms_AnimWeb *)(v0 - 496 + 256));
}


// ========================================================================
// __unwind$491197
// EA  : 0x82D31E88
// RVA : 0x00D31E88
// PDB : w:\tech5\tungsten\game\entities\vehiclemountedturret.cpp
// ========================================================================

void _unwind_491197()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 496 + 112), tag: TAG_CLIPMODEL);
}

