
// ========================================================================
// ?CycleFollow@idAISplinePathMgr@@AAAXXZ
// EA  : 0x82B04FC8
// RVA : 0x00B04FC8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __fastcall idAISplinePathMgr::CycleFollow(idAISplinePathMgr *this)
{
  const char *v1; // r10
  char *data; // r11
  int v3; // r9
  int v4; // r9
  bool v5; // zf
  char *v6; // r11
  const char *v7; // r10
  int v8; // r9
  int v9; // r9
  idVehicleAI *v10; // r31
  idVehicleAI *v11; // r3
  idLinkList<idVehicleAI> *next; // r11
  idVehicleAI *v13; // r30
  idVehicleAI *owner; // r31
  idLinkList<idVehicleAI> *v15; // r11
  idLinkList<idVehicleAI> *v16; // r11
  idVehicleAI *v17; // r31
  idVehicleAI *v18; // r3
  idLinkList<idVehicleAI> *prev; // r11
  idLinkList<idVehicleAI> *v20; // r11
  idLinkList<idVehicleAI> *v21; // r11
  idLinkList<idVehicleAI> *v22; // r11
  idVehicleAI *v23; // r11

  v1 = "any";
  data = vai_follow.valueString.data;
  do
  {
    v3 = (unsigned __int8)*data;
    v5 = v3 == 0;
    v4 = v3 - *(unsigned __int8 *)v1;
    if ( v5 )
      break;
    ++data;
    ++v1;
  }
  while ( v4 == 0 );
  if ( v4 == 0 )
    goto LABEL_51;
  v6 = vai_follow.valueString.data;
  v7 = "1";
  do
  {
    v8 = (unsigned __int8)*v6;
    v5 = v8 == 0;
    v9 = v8 - *(unsigned __int8 *)v7;
    if ( v5 )
      break;
    ++v6;
    ++v7;
  }
  while ( v9 == 0 );
  if ( v9 != 0 )
  {
    if ( vai_next.valueInteger != 0 )
    {
      v10 = (idVehicleAI *)((int (__fastcall *)(idGameLocal *))gameLocal->FindEntity)(a1: gameLocal);
      if ( (unsigned __int8)idVehicleAI::IsTypeOf(c: v10) == 0 )
      {
LABEL_11:
        idCVar::SetString(this: &vai_follow, newValue: "any", force: true);
        return;
      }
      idCVar::SetBool(this: &vai_next, newValue: false, force: true);
      v11 = idVehicleAI::CastTo(c: v10);
      next = v11->controlNode.next;
      v13 = v11;
      if ( next == nullptr || next == v11->controlNode.head )
        owner = nullptr;
      else
        owner = next->owner;
      if ( owner != v11 )
      {
        do
        {
          if ( owner == nullptr )
          {
            v15 = gameLocal->vehicleAIEntities.next;
            if ( v15 == nullptr )
              goto LABEL_29;
            if ( v15 == gameLocal->vehicleAIEntities.head )
              goto LABEL_29;
            owner = v15->owner;
            if ( owner == nullptr )
              goto LABEL_29;
            if ( owner == v13 )
              break;
          }
          if ( idVehicleAI::IsValid(this: owner) )
            break;
          v16 = owner->controlNode.next;
          if ( v16 == nullptr || v16 == owner->controlNode.head )
            owner = nullptr;
          else
            owner = v16->owner;
        }
        while ( owner != v13 );
      }
    }
    else
    {
      if ( vai_prev.valueInteger == 0 )
        return;
      v17 = (idVehicleAI *)((int (__fastcall *)(idGameLocal *))gameLocal->FindEntity)(a1: gameLocal);
      if ( (unsigned __int8)idVehicleAI::IsTypeOf(c: v17) == 0 )
        goto LABEL_11;
      idCVar::SetBool(this: &vai_prev, newValue: false, force: true);
      v18 = idVehicleAI::CastTo(c: v17);
      prev = v18->controlNode.prev;
      v13 = v18;
      if ( prev == nullptr || prev == v18->controlNode.head )
        owner = nullptr;
      else
        owner = prev->owner;
      if ( owner != v18 )
      {
        while ( 1 )
        {
          if ( owner == nullptr )
          {
            v20 = gameLocal->vehicleAIEntities.prev;
            if ( v20 == nullptr || v20 == gameLocal->vehicleAIEntities.head || (owner = v20->owner) == nullptr )
            {
LABEL_29:
              owner = v13;
              break;
            }
            if ( owner == v13 )
              break;
          }
          if ( !idVehicleAI::IsValid(this: owner) )
          {
            v21 = owner->controlNode.prev;
            if ( v21 == nullptr || v21 == owner->controlNode.head )
              owner = nullptr;
            else
              owner = v21->owner;
            if ( owner != v13 )
              continue;
          }
          break;
        }
      }
    }
    if ( owner != nullptr )
      idCVar::SetString(this: &vai_follow, newValue: owner->name.data, force: true);
  }
  else
  {
LABEL_51:
    v22 = gameLocal->vehicleAIEntities.next;
    if ( v22 != nullptr && v22 != gameLocal->vehicleAIEntities.head )
    {
      v23 = v22->owner;
      if ( v23 != nullptr )
        idCVar::SetString(this: &vai_follow, newValue: v23->name.data, force: true);
    }
  }
}


// ========================================================================
// ?UpdateTrackersPeriodic@idAISplinePathMgr@@AAAXAAV?$idList@H$04@@H_N@Z
// EA  : 0x82B052F8
// RVA : 0x00B052F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __fastcall idAISplinePathMgr::UpdateTrackersPeriodic(
        idAISplinePathMgr *this,
        idList<int,5> *indexList,
        signed int frequencyInFrames,
        const bool fastUpdateOthers)
{
  signed int v6; // r10
  int num; // r11
  signed int v9; // r29
  int v10; // r3
  signed int v11; // r11
  int v12; // r23
  int v13; // r24
  int v14; // r28
  int v15; // r29
  idNavPathPosTracker *v16; // r31
  idEntity *Owner; // r3
  bool v18; // r30
  idPhysics *Physics; // r3
  int v20; // r3
  signed int v21; // r27
  int v22; // r30
  idNavPathPosTracker *v23; // r31
  idEntity *v24; // r3
  idPhysics *v25; // r3
  int v26; // r3

  v6 = frequencyInFrames;
  if ( this->usedTrackers.num > 0 )
  {
    num = indexList->num;
    if ( num > 0 )
    {
      if ( num < frequencyInFrames )
        v6 = indexList->num;
      v9 = num / v6;
      __twllei(v6, 0);
      __twlgei(v6 & ~(__ROL4__(num, 1) - 1), 0xFFFFFFFF);
      if ( num / v6 > 0 )
      {
        v10 = idAccolade::Count(this: &clientGame->gameTimeManager);
        v11 = indexList->num;
        __twllei(v11, 0);
        __twllei(v9, 0);
        __twlgei(v11 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
        __twlgei(v9 & ~(__ROL4__(v10 % v11, 1) - 1), 0xFFFFFFFF);
        v12 = v10 % v11 / v9 * v9;
        if ( fastUpdateOthers )
        {
          v13 = v12 + v9;
          v14 = 0;
          if ( v11 > 0 )
          {
            v15 = 0;
            do
            {
              v16 = &this->trackerPool.trackers[this->usedTrackers.list[indexList->list[v15]].value];
              Owner = idNavPathPosTracker::GetOwner(this: v16);
              if ( Owner != nullptr && v16->pathPosition.navSpline != nullptr )
              {
                if ( v14 < v12 || (v18 = true, v14 >= v13) )
                  v18 = false;
                Physics = idEntity::GetPhysics(this: Owner);
                v20 = (int)Physics->GetOrigin(this: Physics, a2: 0);
                idNavPathPosTracker::SetWorldPosition(
                  this: *(idNavPathPosTracker **)v20,
                  pos: *(idVec3 **)(v20 + 4),
                  splineDistance: (idNavSplinePosition *)__ROL4__(*(_DWORD *)(v20 + 8), 32));
                idNavPathPosTracker::Update(this: v16, fullUpdate: v18);
              }
              ++v14;
              ++v15;
            }
            while ( v14 < indexList->num );
          }
        }
        else
        {
          v21 = 0;
          if ( v9 > 0 )
          {
            v22 = v12;
            do
            {
              if ( v21 + v12 >= indexList->num )
                break;
              v23 = &this->trackerPool.trackers[this->usedTrackers.list[indexList->list[v22]].value];
              v24 = idNavPathPosTracker::GetOwner(this: v23);
              if ( v24 != nullptr && v23->pathPosition.navSpline != nullptr )
              {
                v25 = idEntity::GetPhysics(this: v24);
                v26 = (int)v25->GetOrigin(this: v25, a2: 0);
                idNavPathPosTracker::SetWorldPosition(
                  this: *(idNavPathPosTracker **)v26,
                  pos: *(idVec3 **)(v26 + 4),
                  splineDistance: (idNavSplinePosition *)__ROL4__(*(_DWORD *)(v26 + 8), 32));
                idNavPathPosTracker::Update(this: v23, fullUpdate: true);
              }
              ++v21;
              ++v22;
            }
            while ( v21 < v9 );
          }
        }
      }
    }
  }
}


// ========================================================================
// ?GetDebugAiView@idAISplinePathMgr@@QAA_NAAVidVec3@@AAVidMat3@@AAM@Z
// EA  : 0x82B05560
// RVA : 0x00B05560
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

int __fastcall idAISplinePathMgr::GetDebugAiView(idAISplinePathMgr *this, idVec3 *origin, idMat3 *axis, float *fov_x)
{
  idVehicleAI *v7; // r30
  idVehicleAI *v9; // r30
  idVehicle *Owner; // r24
  __int64 v11; // r6
  double v12; // fp31
  __int64 v13; // r9
  __int64 v14; // r9
  double v15; // fp27
  idPhysics *Physics; // r3
  idAngles *v17; // r3
  double valueFloat; // fp31
  const idDeclVehicleProps::cameraPlacement_t *CameraPlacement; // r3
  double v20; // fp26
  double v21; // fp1
  double v22; // fp29
  double v23; // fp1
  double v24; // fp30
  double v25; // fp1
  double v26; // fp13
  double v27; // fp1
  double v28; // fp29
  idAngles *p_currentViewAngles; // r23
  double v30; // fp1
  double v31; // fp30
  float *p_viewAnglesDeltaPerc; // r29
  double v33; // fp13
  double v34; // fp11
  double pitch; // fp9
  int v36; // r3
  double v37; // fp13
  double v38; // fp12
  double yaw; // fp31
  double v40; // fp30
  idPhysics *v41; // r3
  float *v42; // r3
  double v43; // fp6
  double v44; // fp13
  idMat3 *v45; // r3
  long double v46; // fp2
  double y; // fp13
  double z; // fp12
  double v49; // fp10
  double v50; // fp8
  double v51; // fp7
  double v52; // fp6
  double v53; // fp5
  double v54; // fp4
  double v55; // fp12
  double v56; // fp13
  idPhysics *v57; // r3
  idClipModel *clip8x8; // r26
  const idVec3 *v59; // r3
  double v60; // fp13
  double v61; // fp12
  double v62; // fp10
  idPhysics *v63; // r3
  idClipModel *v64; // r26
  const idVec3 *v65; // r3
  double v66; // fp7
  double v67; // fp6
  idPhysics *v68; // r28
  idVec3 *v69; // r3
  double v70; // fp31
  double v71; // fp29
  double v72; // fp28
  float *v73; // r3
  double v74; // fp9
  double v75; // fp8
  double v76; // fp2
  double v77; // fp1
  idPhysics *v78; // r3
  float *v79; // r3
  double v80; // fp11
  double v81; // fp10
  double v82; // fp9
  double v83; // fp4
  double x; // fp7
  double v85; // fp2
  double v86; // fp1
  idMat3 v87; // [sp+50h] [-180h] BYREF
  float v88; // [sp+74h] [-15Ch]
  float v89; // [sp+78h] [-158h]
  float v90; // [sp+7Ch] [-154h] BYREF
  trace_t v91; // [sp+80h] [-150h] BYREF
  idAngles v92[8]; // [sp+100h] [-D0h] BYREF

  v7 = (idVehicleAI *)gameLocal->FindEntity(this: gameLocal, a2: vai_follow.valueString.data);
  if ( (unsigned __int8)idVehicleAI::IsTypeOf(c: v7) == 0 )
    return 0;
  v9 = idVehicleAI::CastTo(c: v7);
  if ( idVehicleAI::GetOwner(this: v9) == nullptr )
    return 0;
  Owner = (idVehicle *)idVehicleAI::GetOwner(this: v9);
  LODWORD(v11) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
               - this->lastDrawTime;
  *(_QWORD *)&v87.mat[1].y = v11;
  v12 = (float)v11;
  if ( vai_cam.valueInteger != 0 )
  {
    LODWORD(v13) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    *(_QWORD *)&v87.mat[1].y = v13;
    v12 = (float)v13;
  }
  if ( v12 == 0.0 )
    return 0;
  LODWORD(v14) = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  *(_QWORD *)&v87.mat[1].y = v14;
  v15 = (float)((float)v12 / (float)v14);
  this->lastDrawTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  Physics = idEntity::GetPhysics(this: Owner);
  v17 = (idAngles *)Physics->GetAxis(this: Physics, a2: 0);
  idMat3::ToAngles(this: (idMat3 *)&v87.mat[2].z, result: v17);
  if ( pm_vehicleFreeCam.valueInteger != 0 )
  {
    v87.mat[0].x = Owner->freeAngles.pitch;
    v87.mat[0].y = Owner->freeAngles.yaw;
    v87.mat[0].z = Owner->freeAngles.roll;
  }
  else
  {
    v87.mat[0].y = vai_cam_yaw.valueFloat + v88;
    valueFloat = vai_cam_pitch.valueFloat;
    CameraPlacement = idVehicle::GetCameraPlacement(this: Owner);
    v87.mat[0].x = (float)(CameraPlacement->pitch + (float)valueFloat) + v87.mat[2].z;
    v87.mat[0].z = 0.0;
  }
  v20 = vai_cam_range.valueFloat;
  v21 = idMath::AngleNormalize360(angle: (float)(v88 - this->lastCarAngles.yaw));
  if ( v21 > 180.0 )
    v21 = (float)((float)v21 - (float)360.0);
  v22 = __fabs(v21);
  v23 = idMath::AngleNormalize360(angle: (float)(v87.mat[2].z - this->lastCarAngles.pitch));
  if ( v23 > 180.0 )
    v23 = (float)((float)v23 - (float)360.0);
  v24 = __fabs(v23);
  v25 = idMath::AngleNormalize360(angle: (float)(v89 - this->lastCarAngles.roll));
  if ( v25 > 180.0 )
    v25 = (float)((float)v25 - (float)360.0);
  v26 = __fabs(v25);
  if ( v22 >= vc_wildyaw.valueFloat || v24 >= vc_wildpitch.valueFloat || v26 >= vc_wildroll.valueFloat )
  {
    v36 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
    LODWORD(v87.mat[1].z) = (int)v15;
    this->wildSpinTime += 2 * v36 * (int)v15;
    if ( this->wildSpinTime > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                            + 1000 )
      this->wildSpinTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                         + 1000;
  }
  else
  {
    v27 = idMath::AngleNormalize360(angle: (float)(v87.mat[0].y - this->currentViewAngles.yaw));
    v28 = v27;
    if ( v27 > 180.0 )
      v28 = (float)((float)v27 - (float)360.0);
    p_currentViewAngles = &this->currentViewAngles;
    v30 = idMath::AngleNormalize360(angle: (float)(v87.mat[0].x - this->currentViewAngles.pitch));
    v31 = v30;
    if ( v30 > 180.0 )
      v31 = (float)((float)v30 - (float)360.0);
    p_viewAnglesDeltaPerc = &this->viewAnglesDeltaPerc;
    if ( this->wildSpinTime > idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
    {
      *p_viewAnglesDeltaPerc = 0.0099999998;
    }
    else
    {
      if ( *p_viewAnglesDeltaPerc < 0.1 )
      {
        v33 = (float)((float)(vc_recoverrate.valueFloat * (float)v15) + *p_viewAnglesDeltaPerc);
        *p_viewAnglesDeltaPerc = (float)(vc_recoverrate.valueFloat * (float)v15) + *p_viewAnglesDeltaPerc;
        if ( v33 > 0.1 )
          *p_viewAnglesDeltaPerc = 0.1;
      }
      this->wildSpinTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    }
    v34 = (float)(*p_viewAnglesDeltaPerc * (float)v31);
    pitch = p_currentViewAngles->pitch;
    this->currentViewAngles.yaw = (float)((float)(*p_viewAnglesDeltaPerc * (float)v28) * (float)v15)
                                + this->currentViewAngles.yaw;
    p_currentViewAngles->pitch = (float)((float)v34 * (float)v15) + (float)pitch;
    idAngles::Normalize180(this: &this->currentViewAngles);
  }
  v37 = v88;
  v38 = v89;
  this->lastCarAngles.pitch = v87.mat[2].z;
  this->lastCarAngles.yaw = v37;
  this->lastCarAngles.roll = v38;
  yaw = idVehicle::GetCameraPlacement(this: Owner)->yaw;
  v40 = vai_cam_height.valueFloat;
  v41 = idEntity::GetPhysics(this: Owner);
  v42 = (float *)v41->GetOrigin(this: v41, a2: 0);
  origin->x = *v42;
  origin->y = v42[1];
  origin->z = (float)(v42[2] + (float)v40) + (float)8.0;
  v43 = this->currentViewAngles.yaw;
  v44 = this->currentViewAngles.pitch;
  v87.mat[0].x = this->currentViewAngles.pitch;
  v87.mat[0].y = v43;
  if ( v44 < vc_minpitch.valueFloat )
    v87.mat[0].x = vc_minpitch.valueFloat;
  v45 = idAngles::ToMat3(this: v92, result: &v87);
  *axis = *v45;
  *(double *)&v46 = (float)(idMath::M_DEG2RAD * (float)yaw);
  idMath::SinCos(a: v46, s: (float *)v45, c: &v87.mat[1].y, a4: &v90);
  y = origin->y;
  z = origin->z;
  v49 = (float)(v87.mat[1].y * (float)v20);
  v50 = (float)(axis->mat[0].y * (float)(v90 * (float)v20));
  v51 = (float)(axis->mat[0].z * (float)(v90 * (float)v20));
  v52 = (float)(origin->x - (float)(axis->mat[0].x * (float)(v90 * (float)v20)));
  origin->x = origin->x - (float)(axis->mat[0].x * (float)(v90 * (float)v20));
  v53 = (float)((float)y - (float)v50);
  origin->y = (float)y - (float)v50;
  v54 = (float)((float)z - (float)v51);
  origin->z = (float)z - (float)v51;
  v55 = (float)((float)v49 * axis->mat[1].y);
  v56 = (float)((float)v49 * axis->mat[1].z);
  origin->x = (float)(axis->mat[1].x * (float)v49) + (float)v52;
  origin->y = (float)v55 + (float)v53;
  origin->z = (float)v56 + (float)v54;
  v57 = idEntity::GetPhysics(this: Owner);
  clip8x8 = clientGame->clip.clip8x8;
  v59 = v57->GetOrigin(this: v57, a2: 0);
  idClip::TraceBounds(
    this: &clientGame->clip,
    result: &v91,
    start: v59,
    end: origin,
    trm: clip8x8,
    clipMask: 1,
    passEntityNumber: 0);
  if ( v91.fraction != 1.0 && (v91.c.flags & 1) == 0 )
  {
    v60 = (float)((float)1.0 - v91.fraction);
    v61 = v91.endpos.z;
    v62 = v91.endpos.y;
    origin->x = v91.endpos.x;
    origin->y = v62;
    origin->z = (float)((float)v60 * (float)32.0) + (float)v61;
    v63 = idEntity::GetPhysics(this: Owner);
    v64 = clientGame->clip.clip8x8;
    v65 = v63->GetOrigin(this: v63, a2: 0);
    idClip::TraceBounds(
      this: &clientGame->clip,
      result: &v91,
      start: v65,
      end: origin,
      trm: v64,
      clipMask: 1,
      passEntityNumber: 0);
    v66 = v91.endpos.y;
    v67 = v91.endpos.z;
    origin->x = v91.endpos.x;
    origin->y = v66;
    origin->z = v67;
  }
  v68 = idEntity::GetPhysics(this: Owner);
  v69 = idAngles::ToForward(this: (idAngles *)&v87.mat[1].y, result: v87.mat);
  v70 = (float)(v69->x * (float)512.0);
  v71 = (float)(v69->y * (float)512.0);
  v72 = (float)(v69->z * (float)512.0);
  v73 = (float *)v68->GetOrigin(this: v68, a2: 0);
  v74 = origin->y;
  v75 = origin->z;
  v76 = (float)(v73[1] + (float)v71);
  v77 = (float)((float)(v73[2] + (float)v72) + (float)v40);
  axis->mat[0].x = (float)((float)v70 + *v73) - origin->x;
  axis->mat[0].y = (float)v76 - (float)v74;
  axis->mat[0].z = (float)v77 - (float)v75;
  v78 = idEntity::GetPhysics(this: Owner);
  v79 = (float *)v78->GetGravityNormal(this: v78);
  v80 = *v79;
  axis->mat[2].x = *v79;
  v81 = v79[1];
  axis->mat[2].y = v79[1];
  v82 = v79[2];
  axis->mat[2].z = v79[2];
  v83 = axis->mat[0].y;
  x = axis->mat[0].x;
  v85 = (float)((float)v80 * axis->mat[0].y);
  v86 = (float)(axis->mat[0].z * (float)v81);
  axis->mat[1].y = (float)((float)v80 * axis->mat[0].z) - (float)((float)v82 * axis->mat[0].x);
  axis->mat[1].z = (float)((float)v81 * (float)x) - (float)v85;
  axis->mat[1].x = (float)((float)v83 * (float)v82) - (float)v86;
  idMat3::OrthoNormalizeSelf(this: axis);
  return 1;
}


// ========================================================================
// ??0idAISplinePathMgr@@QAA@XZ
// EA  : 0x82B05DB8
// RVA : 0x00B05DB8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

idAISplinePathMgr *__fastcall idAISplinePathMgr::idAISplinePathMgr(idAISplinePathMgr *this)
{
  idNavSplinePathMgr::idNavSplinePathMgr(this);
  this->__vftable = (idAISplinePathMgr_vtbl *)&idAISplinePathMgr::`vftable';
  idNavPathPosTracker::idNavPathPosTracker(this: &this->null_splineTracker);
  this->dormancyList.list = nullptr;
  this->dormancyList.granularity = 0;
  this->dormancyList.memTag = 5;
  this->dormancyList.listStatic = 0;
  this->dormancyList.size = 0;
  this->dormancyList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->dormancyList);
  this->navSplineType = NAV_SPLINE_TYPE_VEHICLE_AI;
  idStr::operator=(this: &this->tempNavSplinePathName, text: "tempVehAISplinePath");
  this->trackPickups = false;
  this->numVehiclePickups = 0;
  return this;
}


// ========================================================================
// __unwind$490812
// EA  : 0x82B05E60
// RVA : 0x00B05E60
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_490812()
{
  int v0; // r12

  idNavSplinePathMgr::~idNavSplinePathMgr(this: *(idNavSplinePathMgr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$490813
// EA  : 0x82B05E88
// RVA : 0x00B05E88
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_490813()
{
  int v0; // r12

  idNavPathPosTracker::~idNavPathPosTracker(this: (idNavPathPosTracker *)(*(_DWORD *)(v0 - 112 + 132) + 158480));
}


// ========================================================================
// __unwind$490814
// EA  : 0x82B05EBC
// RVA : 0x00B05EBC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_490814()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 158792));
}


// ========================================================================
// ?ShowVehicleAiStats@idAISplinePathMgr@@AAAXXZ
// EA  : 0x82B05FB8
// RVA : 0x00B05FB8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __fastcall idAISplinePathMgr::ShowVehicleAiStats(idAISplinePathMgr *this)
{
  idVehicleAI *v1; // r30
  idVehicleAI *v2; // r3
  idVehicleAI *v3; // r29
  char v4; // r30
  char *data; // r11
  char *v6; // r10
  int v7; // r9
  int v8; // r9
  bool v9; // zf
  idEntity *Owner; // r3
  char *v11; // r11
  char *v12; // r10
  int v13; // r9
  int v14; // r9
  const idStr *v15; // r3
  char *v16; // r28
  idDebugHUD_vtbl *v17; // r28
  idNavPathPosTracker *SplineTracker; // r3
  float v19; // r10
  float v20; // r9
  void (*Printf)(idDebugHUD *, const char *, ...); // r8
  idVehicleAI *IdObstaclesStr; // r3
  const char *v23; // r11
  const char *v24; // r6
  idVehicle_Car *VehicleCar; // r3
  idDebugHUD_vtbl *v26; // r28
  unsigned int level; // r11
  idDebugHUD_vtbl *v28; // r5
  idDebugHUD_vtbl *v29; // r28
  idDebugHUD_vtbl *v30; // r28
  idDebugHUD_vtbl *v31; // r28
  idDebugHUD_vtbl *v32; // r28
  idDebugHUD_vtbl *v33; // r28
  idDebugHUD_vtbl *v34; // r6
  void (*v35)(idDebugHUD *, const char *, ...); // r9
  idDebugHUD_vtbl *v36; // r28
  idDebugHUD_vtbl *v37; // r28
  idDebugHUD_vtbl *v38; // r28
  idDebugHUD_vtbl *v39; // r28
  idDebugHUD_vtbl *v40; // r28
  long double v41; // fp2
  long double v42; // fp2
  idDebugHUD_vtbl *v43; // r28
  vaiObstacleAvoidance_t AvoidanceType; // r3
  idDebugHUD_vtbl *v45; // r28
  idDebugHUD_vtbl *v46; // r28
  idDebugHUD_vtbl *v47; // r28
  idDebugHUD_vtbl *v48; // r28
  idDebugHUD_vtbl *v49; // r28
  const char *Classname; // r3
  const char *v51; // r3
  const char *v52; // r3
  idVehicle *Enemy; // r28
  const char *v54; // r3
  idVehicle_Car *v55; // r3
  idPhysics *Physics; // r3
  float y; // r10
  float z; // r9
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r7
  float *v60; // r3
  double v61; // fp3
  double v63; // fp12
  double v65; // fp10
  double v66; // r6
  idNavPathPosTracker *v67; // r3
  navSplinePath_t *rightDistance_low; // r9
  navSplinePath_t *ShortestPath; // r3
  navSplinePath_t *v70; // r27
  int num; // r11
  int v72; // r28
  idNavPathPosTracker *v73; // r3
  float v74; // r10
  float v75; // r9
  double length; // fp1
  idNavPathPosTracker *v77; // r3
  navSplinePath_t *v78; // r10
  idNavSpline *navSpline; // r9
  double SpeedLimit; // [sp+20h] [-140h]
  double rightDistance; // [sp+20h] [-140h]
  double Difficulty_AttackScale; // [sp+20h] [-140h]
  double Difficulty_DamageScale; // [sp+20h] [-140h]
  double Difficulty_SpeedRate; // [sp+20h] [-140h]
  double Difficulty_Accuracy; // [sp+20h] [-140h]
  double Difficulty_DamageTakenScale; // [sp+20h] [-140h]
  double v87; // [sp+20h] [-140h]
  double StopDistance; // [sp+20h] [-140h]
  double MoveDistance; // [sp+20h] [-140h]
  double DecelDistance; // [sp+20h] [-140h]
  double MaxCurveSpeed; // [sp+20h] [-140h]
  double v92; // [sp+20h] [-140h]
  double v93; // [sp+20h] [-140h]
  double PowerTurnSpeed; // [sp+20h] [-140h]
  double PowerTurnTime; // [sp+20h] [-140h]
  double StopPowerTurnSpeed; // [sp+20h] [-140h]
  double TraversalStepSize; // [sp+20h] [-140h]
  double BackupSpeed; // [sp+20h] [-140h]
  int v99; // [sp+24h] [-13Ch]
  int obstacleFlags; // [sp+50h] [-110h]
  int speedFlags; // [sp+50h] [-110h]
  int steerFlags; // [sp+50h] [-110h]
  int v103; // [sp+50h] [-110h]
  float distance; // [sp+58h] [-108h] BYREF
  float v105; // [sp+5Ch] [-104h]
  float v106; // [sp+60h] [-100h]
  float v107; // [sp+70h] [-F0h] BYREF
  navSplinePath_t *v108; // [sp+74h] [-ECh]
  const char *v109; // [sp+78h] [-E8h]
  const char *v110; // [sp+7Ch] [-E4h]
  idStr v111; // [sp+80h] [-E0h] BYREF
  idStr v112; // [sp+A0h] [-C0h] BYREF
  idStr v113; // [sp+C0h] [-A0h] BYREF
  idStr v114; // [sp+E0h] [-80h] BYREF
  idStr v115[3]; // [sp+100h] [-60h] BYREF

  v1 = (idVehicleAI *)gameLocal->FindEntity(this: gameLocal, a2: vai_follow.valueString.data);
  if ( (unsigned __int8)idVehicleAI::IsTypeOf(c: v1) == 0 )
    return;
  v2 = idVehicleAI::CastTo(c: v1);
  v3 = v2;
  v4 = 0;
  if ( vai_stats.valueInteger != 0 )
  {
    data = vai_follow.valueString.data;
    v6 = v2->name.data;
    do
    {
      v7 = (unsigned __int8)*data;
      v9 = v7 == 0;
      v8 = v7 - (unsigned __int8)*v6;
      if ( v9 )
        break;
      ++data;
      ++v6;
    }
    while ( v8 == 0 );
    if ( v8 == 0 )
      goto LABEL_13;
    if ( idVehicleAI::GetOwner(this: v2) != nullptr )
    {
      Owner = idVehicleAI::GetOwner(this: v3);
      v11 = vai_follow.valueString.data;
      v12 = Owner->name.data;
      do
      {
        v13 = (unsigned __int8)*v11;
        v9 = v13 == 0;
        v14 = v13 - (unsigned __int8)*v12;
        if ( v9 )
          break;
        ++v11;
        ++v12;
      }
      while ( v14 == 0 );
      if ( v14 == 0 )
      {
        idCVar::SetString(this: &vai_follow, newValue: v3->name.data, force: true);
LABEL_13:
        v4 = 1;
      }
    }
  }
  if ( v4 != 0 )
  {
    v112.len = 0;
    v112.baseBuffer[0] = 0;
    v112.allocedAndFlag = 20;
    v112.data = v112.baseBuffer;
    obstacleFlags = v3->obstacleFlags;
    if ( obstacleFlags != 0 )
    {
      if ( (obstacleFlags & 1) != 0 )
        idStr::Append(this: &v112, text: " FRONT");
      if ( (v3->obstacleFlags & 2) != 0 )
        idStr::Append(this: &v112, text: " RIGHT");
      if ( (v3->obstacleFlags & 4) != 0 )
        idStr::Append(this: &v112, text: " LEFT");
      if ( (v3->obstacleFlags & 8) != 0 )
        idStr::Append(this: &v112, text: " REAR");
    }
    else
    {
      idStr::operator=(this: &v112, text: "None");
    }
    v111.allocedAndFlag = 20;
    v111.len = 0;
    v111.data = v111.baseBuffer;
    v111.baseBuffer[0] = 0;
    speedFlags = v3->speedFlags;
    if ( speedFlags != 0 )
    {
      if ( (speedFlags & 1) != 0 )
        idStr::Append(this: &v111, text: " STOP DISTANCE .");
      if ( (v3->speedFlags & 2) != 0 )
        idStr::Append(this: &v111, text: " DECEL DISTANCE .");
      if ( (v3->speedFlags & 4) != 0 )
        idStr::Append(this: &v111, text: " MOVE DISTANCE .");
      if ( (v3->speedFlags & 8) != 0 )
      {
        idStr::Append(this: &v111, text: " TURN SPEED . ");
        v15 = idStr::idStr(this: &v114, f: v3->turnSpeedRatio);
        idStr::Append(this: &v111, text: v15);
        idStr::FreeData(this: &v114);
      }
      if ( (v3->speedFlags & 0x10) != 0 )
        idStr::Append(this: &v111, text: " CURVE SPEED");
      if ( (v3->speedFlags & 0x20) != 0 )
        idStr::Append(this: &v111, text: " FRONT OBSTRUCTION");
    }
    else
    {
      idStr::operator=(this: &v111, text: "None");
    }
    v113.allocedAndFlag = 20;
    v113.len = 0;
    v113.data = v113.baseBuffer;
    v113.baseBuffer[0] = 0;
    steerFlags = v3->steerFlags;
    if ( steerFlags != 0 )
    {
      if ( (steerFlags & 1) != 0 )
        idStr::Append(this: &v113, text: " OPPOSITE");
      v103 = v3->steerFlags;
      if ( (v103 & 2) != 0 )
      {
        if ( v103 != 2 )
          idStr::Append(this: &v113, text: " +");
        idStr::Append(this: &v113, text: " NARROW PATH");
      }
    }
    if ( idVehicleAI::GetOwner(this: v3) != nullptr )
      v16 = idVehicleAI::GetOwner(this: v3)->name.data;
    else
      v16 = "none";
    debugHUD->SetTextScale(this: debugHUD, a2: 0.75);
    debugHUD->Printf(this: debugHUD, a2: "\n^3-- VEHICLE AI STATS --\n");
    debugHUD->Printf(this: debugHUD, a2: "^7 name: ^5%s\n", v3->name.data);
    if ( idVehicleAI::IsValid(this: v3) )
    {
      debugHUD->Printf(this: debugHUD, a2: "^7  num: ^5%d\n", v3->entityNumber);
      debugHUD->Printf(this: debugHUD, a2: "^7owner: %s\n", v16);
      debugHUD->Printf(
        this: debugHUD,
        a2: "^7     Steering: ^2% 6.1f %s\n",
        (unsigned int)COERCE_UNSIGNED_INT64(v3->desiredSteering),
        v113.data);
      debugHUD->Printf(this: debugHUD, a2: "^7      Braking:     ^2% 1d\n", v3->desiredBraking);
      v17 = debugHUD->__vftable;
      SpeedLimit = idVehicleAI::GetSpeedLimit(this: v3);
      v17->Printf(this: debugHUD, a2: "^7  Speed Limit: ^2% 6.0f\n", LODWORD(SpeedLimit));
      debugHUD->Printf(
        this: debugHUD,
        a2: "^7Desired Speed: ^2% 6.0f ( %s )\n",
        (unsigned int)COERCE_UNSIGNED_INT64(v3->desiredSpeed),
        v111.data);
      debugHUD->Printf(
        this: debugHUD,
        a2: "^7 Actual Speed: ^2% 6.0f\n",
        (unsigned int)COERCE_UNSIGNED_INT64(v3->actualSpeed));
      rightDistance = idVehicleAI::GetSplineTracker(this: v3)->pathPosition.rightDistance;
      debugHUD->Printf(this: debugHUD, a2: "^7   Right Dist: ^2% 6.0f\n", LODWORD(rightDistance));
      SplineTracker = idVehicleAI::GetSplineTracker(this: v3);
      v19 = SplineTracker->pathPosition.rightDistance;
      v20 = *(float *)&SplineTracker->pathPosition.navSpline;
      Printf = debugHUD->Printf;
      distance = SplineTracker->pathPosition.distance;
      v105 = v19;
      v106 = v20;
      Printf(
        this: debugHUD,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(distance)),
        COERCE_UNSIGNED_INT64(distance));
      debugHUD->Printf(this: debugHUD, a2: "^7Spline Obstcl: ^2%s\n", v112.data);
      IdObstaclesStr = idVehicleAI::GetIdObstaclesStr(this: (idVehicleAI *)v115, result: (idStr *)v3);
      debugHUD->Printf(this: debugHUD, a2: "^7 id Obstacles: ^2%s\n", IdObstaclesStr->listenerList);
      idStr::FreeData(this: v115);
      v23 = "Yes";
      v24 = "Yes";
      if ( v3->setup.dormancy.distance <= 0.0 )
        v24 = "No";
      if ( (*((_BYTE *)&v3->flags + 1) & 0x80) == 0 )
        v23 = "No";
      debugHUD->Printf(this: debugHUD, a2: "^7  Is Dormant?: ^2%s   ^7( AI Specific? ^2%s^7 )\n", v23, v24);
      if ( idVehicleAI::GetVehicleCar(this: v3) != nullptr )
      {
        VehicleCar = idVehicleAI::GetVehicleCar(this: v3);
        v26 = debugHUD->__vftable;
        v99 = COERCE_UNSIGNED_INT64(((double (__fastcall *)(idVehicle_Car *))VehicleCar->GetHealth)(a1: VehicleCar));
        v26->Printf(this: debugHUD, a2: "\n^7       Health: ^2%3.1f\n", v99);
      }
      level = v3->setup.difficultyLevel.level;
      if ( level <= 2 )
      {
        distance = COERCE_FLOAT("DIFFICULTY_LOW");
        v28 = debugHUD->__vftable;
        v105 = COERCE_FLOAT("DIFFICULTY_MED");
        v106 = COERCE_FLOAT("DIFFICULTY_HIGH");
        v28->Printf(this: debugHUD, a2: "\n^7DIFFICULTY: ^2%s\n", *((_DWORD *)&distance + level));
        v29 = debugHUD->__vftable;
        Difficulty_AttackScale = idVehicleAI::GetDifficulty_AttackScale(this: v3);
        v29->Printf(this: debugHUD, a2: "^7    Attack: ^2%f\n", LODWORD(Difficulty_AttackScale));
        v30 = debugHUD->__vftable;
        Difficulty_DamageScale = idVehicleAI::GetDifficulty_DamageScale(this: v3);
        v30->Printf(this: debugHUD, a2: "^7  DmgGiven: ^2%f\n", LODWORD(Difficulty_DamageScale));
        v31 = debugHUD->__vftable;
        Difficulty_SpeedRate = idVehicleAI::GetDifficulty_SpeedRate(this: v3);
        v31->Printf(this: debugHUD, a2: "^7     Speed: ^2%f\n", LODWORD(Difficulty_SpeedRate));
        v32 = debugHUD->__vftable;
        Difficulty_Accuracy = idVehicleAI::GetDifficulty_Accuracy(this: v3);
        v32->Printf(this: debugHUD, a2: "^7  Accuracy: ^2%f\n", LODWORD(Difficulty_Accuracy));
        v33 = debugHUD->__vftable;
        Difficulty_DamageTakenScale = idVehicleAI::GetDifficulty_DamageTakenScale(this: v3);
        v33->Printf(this: debugHUD, a2: "^7  DmgTaken: ^2%f\n", LODWORD(Difficulty_DamageTakenScale));
      }
      v34 = debugHUD->__vftable;
      v107 = COERCE_FLOAT("OAT_INIT");
      v108 = (navSplinePath_t *)"OAT_GENERAL";
      v109 = "OAT_RACE";
      v35 = v34->Printf;
      v110 = "OAT_NONE";
      v35(this: debugHUD, a2: "\n^7CONTROL VARS\n");
      v36 = debugHUD->__vftable;
      v87 = idVehicleAI::GetSpeedLimit(this: v3);
      v36->Printf(this: debugHUD, a2: "^7          Speed Limit: ^2%f\n", LODWORD(v87));
      v37 = debugHUD->__vftable;
      StopDistance = idVehicleAI::GetStopDistance(this: v3);
      v37->Printf(this: debugHUD, a2: "^7        Stop Distance: ^2%f\n", LODWORD(StopDistance));
      v38 = debugHUD->__vftable;
      MoveDistance = idVehicleAI::GetMoveDistance(this: v3);
      v38->Printf(this: debugHUD, a2: "^7        Move Distance: ^2%f\n", LODWORD(MoveDistance));
      v39 = debugHUD->__vftable;
      DecelDistance = idVehicleAI::GetDecelDistance(this: v3);
      v39->Printf(this: debugHUD, a2: "^7       Decel Distance: ^2%f\n", LODWORD(DecelDistance));
      v40 = debugHUD->__vftable;
      MaxCurveSpeed = idVehicleAI::GetMaxCurveSpeed(this: v3);
      v40->Printf(this: debugHUD, a2: (const char *)HIDWORD(MaxCurveSpeed), LODWORD(MaxCurveSpeed));
      *(double *)&v41 = idVehicleAI::GetMaxCurveCosine(this: v3);
      v92 = (float)(idMath::ACos(a: v41) * idMath::M_RAD2DEG);
      debugHUD->Printf(this: debugHUD, a2: (const char *)HIDWORD(v92), LODWORD(v92));
      *(double *)&v42 = idVehicleAI::GetMaxStepCosine(this: v3);
      v93 = (float)(idMath::ACos(a: v42) * idMath::M_RAD2DEG);
      debugHUD->Printf(this: debugHUD, a2: "^7       Max Step Angle: ^2%f\n", LODWORD(v93));
      v43 = debugHUD->__vftable;
      AvoidanceType = idVehicleAI::GetAvoidanceType(this: v3);
      v43->Printf(this: debugHUD, a2: "^7       Avoidance Type: ^2%s\n", *((_DWORD *)&v107 + AvoidanceType));
      v45 = debugHUD->__vftable;
      PowerTurnSpeed = idVehicleAI::GetPowerTurnSpeed(this: v3);
      v45->Printf(this: debugHUD, a2: "^7     Power Turn Speed: ^2%f\n", LODWORD(PowerTurnSpeed));
      v46 = debugHUD->__vftable;
      PowerTurnTime = idVehicleAI::GetPowerTurnTime(this: v3);
      v46->Printf(this: debugHUD, a2: "^7      Power Turn Time: ^2%f\n", LODWORD(PowerTurnTime));
      v47 = debugHUD->__vftable;
      StopPowerTurnSpeed = idVehicleAI::GetStopPowerTurnSpeed(this: v3);
      v47->Printf(this: debugHUD, a2: "^7Stop Power Turn Speed: ^2%f\n", LODWORD(StopPowerTurnSpeed));
      v48 = debugHUD->__vftable;
      TraversalStepSize = idVehicleAI::GetTraversalStepSize(this: v3);
      v48->Printf(this: debugHUD, a2: (const char *)HIDWORD(TraversalStepSize), LODWORD(TraversalStepSize));
      v49 = debugHUD->__vftable;
      BackupSpeed = idVehicleAI::GetBackupSpeed(this: v3);
      v49->Printf(this: debugHUD, a2: "^7         Backup Speed: ^2%f\n", LODWORD(BackupSpeed));
      Classname = idClass::GetClassname(this: v3->decisionFSM.curState);
      debugHUD->Printf(this: debugHUD, a2: "\n^7Decision State: ^2%s\n", Classname);
      v51 = idClass::GetClassname(this: v3->movementFSM.curState);
      debugHUD->Printf(this: debugHUD, a2: "^7Movement State: ^2%s\n", v51);
      v52 = idClass::GetClassname(this: v3->attackFSM.curState);
      debugHUD->Printf(this: debugHUD, a2: "^7  Attack State: ^2%s\n", v52);
      if ( idVehicleAI::GetEnemy(this: v3) != nullptr )
      {
        Enemy = (idVehicle *)idVehicleAI::GetEnemy(this: v3);
        if ( (unsigned __int8)idVehicle::IsTypeOf(c: Enemy) != 0 && idVehicle::GetDriver(this: Enemy) != nullptr )
          Enemy = (idVehicle *)idVehicle::GetDriver(this: Enemy);
        debugHUD->Printf(this: debugHUD, a2: "^7         Enemy: ^2%s\n", Enemy->name.data);
      }
      else
      {
        debugHUD->Printf(this: debugHUD, a2: "^7         Enemy: ^2---\n");
      }
      v54 = idClass::GetClassname(this: v3->commandsFSM.curState);
      debugHUD->Printf(this: debugHUD, a2: "\n^7 Command State: ^2%s\n", v54);
      if ( idVehicleAI::GetSplineTracker(this: v3) != nullptr
        && idVehicleAI::GetSplineTracker(this: v3)->pathToGoal.path.num < 1 )
      {
        debugHUD->Printf(this: debugHUD, a2: "\nDist To Goal: ^1*** NO PATH TO GOAL ***\n");
      }
      else
      {
        v55 = idVehicleAI::GetVehicleCar(this: v3);
        Physics = idEntity::GetPhysics(this: v55);
        y = v3->finalGoalPosition.y;
        z = v3->finalGoalPosition.z;
        GetOrigin = Physics->GetOrigin;
        distance = v3->finalGoalPosition.x;
        v105 = y;
        v106 = z;
        v60 = (float *)GetOrigin(this: Physics, a2: 0);
        v61 = (float)((float)((float)(v60[2] - v106) * (float)(v60[2] - v106))
                    + (float)((float)((float)(*v60 - distance) * (float)(*v60 - distance))
                            + (float)((float)(v60[1] - v105) * (float)(v60[1] - v105))));
        _FP2 = (float)((float)((float)((float)(v60[2] - v106) * (float)(v60[2] - v106))
                             + (float)((float)((float)(*v60 - distance) * (float)(*v60 - distance))
                                     + (float)((float)(v60[1] - v105) * (float)(v60[1] - v105))))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v63 = (float)((float)((float)((float)(v60[2] - v106) * (float)(v60[2] - v106))
                            + (float)((float)((float)(*v60 - distance) * (float)(*v60 - distance))
                                    + (float)((float)(v60[1] - v105) * (float)(v60[1] - v105))))
                    * (float)0.5);
        __asm { fsel      f11, f2, f3, f13 }
        v65 = __frsqrte(_FP11);
        v66 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65) - (float)1.5) * (float)v65) * (float)v63)
                                                                                            * (float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65) - (float)1.5) * (float)v65))
                                                                                    - (float)1.5)
                                                                    * (float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65)
                                                                                            - (float)1.5)
                                                                            * (float)v65))
                                                            * (float)v63)
                                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65) - (float)1.5) * (float)v65)
                                                                                            * (float)v63)
                                                                                    * (float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65) - (float)1.5)
                                                                                            * (float)v65))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v65 * (float)v63)
                                                                                            * (float)v65)
                                                                                    - (float)1.5)
                                                                    * (float)v65)))
                                            - (float)1.5)
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65)
                                                                                            - (float)1.5)
                                                                            * (float)v65)
                                                                    * (float)v63)
                                                            * (float)((float)-(float)((float)((float)((float)v65 * (float)v63)
                                                                                            * (float)v65)
                                                                                    - (float)1.5)
                                                                    * (float)v65))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)v65 * (float)v63) * (float)v65)
                                                            - (float)1.5)
                                            * (float)v65)))
                    * (float)v61);
        debugHUD->Printf(this: debugHUD, a2: "\nDist To Goal: ^2% 5.0f    ( % 5.0f )\n", HIDWORD(v66), LODWORD(v66));
      }
      v67 = idVehicleAI::GetSplineTracker(this: v3);
      rightDistance_low = (navSplinePath_t *)LODWORD(v67->goalPathPosition.rightDistance);
      v107 = v67->goalPathPosition.distance;
      v108 = rightDistance_low;
      idVehicleAI::GetSplineTracker(this: v3);
      ShortestPath = idNavSplinePathMgr::GetShortestPath(
                       this: *(idNavSplinePathMgr **)LODWORD(v107),
                       start: *(idNavSplinePosition **)(LODWORD(v107) + 4),
                       end: (idNavSplinePosition *)__ROL4__(*(_DWORD *)(LODWORD(v107) + 8), 32),
                       path: v108);
      v70 = ShortestPath;
      if ( ShortestPath != nullptr )
      {
        if ( spl_disablePathing.valueInteger != 0 )
        {
          debugHUD->Printf(this: debugHUD, a2: "^2 *** PATHING DISABLED ***\n");
        }
        else
        {
          v72 = 0;
          num = ShortestPath->path.num;
          if ( num > 0 )
          {
            do
            {
              if ( v72 != 0 )
              {
                if ( v72 == num - 1 )
                {
                  v77 = idVehicleAI::GetSplineTracker(this: v3);
                  v78 = (navSplinePath_t *)LODWORD(v77->goalPathPosition.rightDistance);
                  navSpline = v77->goalPathPosition.navSpline;
                  v107 = v77->goalPathPosition.distance;
                  length = v107;
                  v108 = v78;
                  v109 = (const char *)navSpline;
                }
                else
                {
                  length = v70->path.list[v72].navSpline->length;
                }
              }
              else
              {
                v73 = idVehicleAI::GetSplineTracker(this: v3);
                v74 = v73->pathPosition.rightDistance;
                v75 = *(float *)&v73->pathPosition.navSpline;
                distance = v73->pathPosition.distance;
                length = distance;
                v105 = v74;
                v106 = v75;
              }
              debugHUD->Printf(
                this: debugHUD,
                a2: "^2%s  -  % 6.0f\n",
                v70->path.list[v72++].navSpline->splinePath->name.data,
                LODWORD(length));
              num = v70->path.num;
            }
            while ( v72 < num );
          }
        }
      }
      idStr::FreeData(this: &v113);
      idStr::FreeData(this: &v111);
    }
    else
    {
      debugHUD->Printf(this: debugHUD, a2: "^7owner: ** INVALID **\n");
      idStr::FreeData(this: &v113);
      idStr::FreeData(this: &v111);
    }
    idStr::FreeData(this: &v112);
  }
}


// ========================================================================
// __unwind$490897
// EA  : 0x82B06E9C
// RVA : 0x00B06E9C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_490897()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 160));
}


// ========================================================================
// __unwind$490898_0
// EA  : 0x82B06EC4
// RVA : 0x00B06EC4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_490898_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 128));
}


// ========================================================================
// __unwind$490899_0
// EA  : 0x82B06EEC
// RVA : 0x00B06EEC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_490899_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 224));
}


// ========================================================================
// __unwind$490900
// EA  : 0x82B06F14
// RVA : 0x00B06F14
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_490900()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 192));
}


// ========================================================================
// __unwind$490901
// EA  : 0x82B06F3C
// RVA : 0x00B06F3C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_490901()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 352 + 256));
}


// ========================================================================
// ?DrawWaypoints@idAISplinePathMgr@@AAAXXZ
// EA  : 0x82B06F68
// RVA : 0x00B06F68
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __fastcall idAISplinePathMgr::DrawWaypoints(idAISplinePathMgr *this)
{
  idLinkList<idWaypoint> *next; // r11
  idWaypoint *owner; // r31
  int v3; // r27
  int v4; // r29
  int value; // r9
  idEntity *v6; // r3
  idSplineWaypoint *v7; // r3
  idSplineWaypoint *v8; // r3
  float distance; // r10
  float rightDistance; // r9
  float v11; // r6
  float v12; // r5
  idRenderWorld_vtbl *v13; // r30
  idVec3 *WorldPos; // r24
  idVec3 *v15; // r3
  float v16; // r11
  float v17; // r10
  float v18; // r9
  idVec3 *v19; // r3
  float v20; // r8
  float v21; // r7
  float v22; // r5
  float v23; // r10
  idRenderWorld_vtbl *v24; // r30
  idVec3 *SplineWorldPos; // r29
  idVec3 *v26; // r3
  idLinkList<idWaypoint> *v27; // r11
  idVec3 v28; // [sp+50h] [-120h] BYREF
  idVec3 v29; // [sp+60h] [-110h] BYREF
  idVec3 v30; // [sp+70h] [-100h] BYREF
  idVec3 v31; // [sp+80h] [-F0h] BYREF
  idVec3 v32; // [sp+90h] [-E0h] BYREF
  float v33[8]; // [sp+A0h] [-D0h] BYREF
  idNavSplinePosition v34; // [sp+C0h] [-B0h] BYREF
  idNavSplinePosition v35; // [sp+D0h] [-A0h] BYREF
  idNavSplinePosition v36; // [sp+E0h] [-90h] BYREF
  idNavSplinePosition v37; // [sp+F0h] [-80h] BYREF
  idNavSplinePosition v38[2]; // [sp+100h] [-70h] BYREF

  next = gameLocal->waypointEntities.next;
  if ( next != nullptr && next != gameLocal->waypointEntities.head )
  {
    owner = next->owner;
    while ( owner != nullptr )
    {
      if ( (unsigned __int8)idSplineWaypoint::IsTypeOf(c: owner) != 0 )
      {
        v3 = 0;
        if ( owner->targets.num > 0 )
        {
          v4 = 0;
          do
          {
            value = owner->targets.list[v4].spawnId.value;
            if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
              && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
            {
              v7 = (idSplineWaypoint *)idEntity::CastTo(c: v6);
            }
            else
            {
              v7 = nullptr;
            }
            v8 = idSplineWaypoint::CastTo(c: v7);
            if ( v8 != nullptr )
            {
              distance = v8->splinePathPosition.distance;
              rightDistance = v8->splinePathPosition.rightDistance;
              LODWORD(v32.z) = v8->splinePathPosition.navSpline;
              v32.x = distance;
              v32.y = rightDistance;
              v11 = *(float *)&owner[1].listenerList;
              v12 = *(float *)&owner[1].listeningToList;
              LODWORD(v30.x) = owner[1].__vftable;
              v30.y = v11;
              v30.z = v12;
              v13 = clientGame->renderWorld->__vftable;
              WorldPos = idNavSplinePosition::GetWorldPos(this: v38, result: &v32);
              v15 = idNavSplinePosition::GetWorldPos(this: &v35, result: &v30);
              ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))v13->DebugArrow)(
                a1: clientGame->renderWorld,
                a2: &idColor::colorMagenta,
                a3: v15,
                a4: WorldPos,
                a5: 25.0);
            }
            ++v3;
            ++v4;
          }
          while ( v3 < owner->targets.num );
        }
        v16 = *(float *)&owner[1].__vftable;
        v17 = *(float *)&owner[1].listenerList;
        v18 = *(float *)&owner[1].listeningToList;
        v33[5] = v17;
        v33[4] = v16;
        if ( v18 != 0.0 )
        {
          v28.x = v16;
          v28.y = v17;
          v28.z = v18;
          v19 = idNavSplinePosition::GetWorldPos(this: &v37, result: &v28);
          v33[0] = v19->x;
          v33[1] = v19->y;
          v33[2] = v19->z;
          v33[3] = 20.0;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)&idColor::colorMagenta,
            a3: (const idSphere *)v33,
            a4: 12,
            a5: 0,
            a6: false);
          v20 = *(float *)&owner[1].listenerList;
          v21 = *(float *)&owner[1].listeningToList;
          LODWORD(v29.x) = owner[1].__vftable;
          v29.y = v20;
          v29.z = v21;
          v22 = *(float *)&owner[1].listenerList;
          v23 = *(float *)&owner[1].listeningToList;
          LODWORD(v31.x) = owner[1].__vftable;
          v31.y = v22;
          v31.z = v23;
          v24 = clientGame->renderWorld->__vftable;
          SplineWorldPos = idNavSplinePosition::GetSplineWorldPos(this: &v34, result: &v29);
          v26 = idNavSplinePosition::GetWorldPos(this: &v36, result: &v31);
          ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))v24->DebugArrow)(
            a1: clientGame->renderWorld,
            a2: &idColor::colorMagenta,
            a3: v26,
            a4: SplineWorldPos,
            a5: 25.0);
        }
      }
      v27 = owner->waypointNode.next;
      if ( v27 == nullptr || v27 == owner->waypointNode.head )
        owner = nullptr;
      else
        owner = v27->owner;
    }
  }
}


// ========================================================================
// ?SetupWaypoints@idAISplinePathMgr@@QAAXXZ
// EA  : 0x82B07238
// RVA : 0x00B07238
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __fastcall idAISplinePathMgr::SetupWaypoints(idAISplinePathMgr *this)
{
  idLinkList<idWaypoint> *next; // r11
  idWaypoint *owner; // r30
  int num; // r11
  idNavSpline *v5; // r27
  int v6; // r29
  idGameLocal *v7; // r10
  int v8; // r31
  int value; // r9
  idEntity *v10; // r3
  int v11; // r9
  idEntity *v12; // r3
  idEntity *v13; // r3
  int v14; // r11
  char v15; // r11
  bool v16; // zf
  int v17; // r9
  idEntity *v18; // r3
  idEntity *v19; // r11
  idStr *v20; // r3
  idNavSpline *NavSpline; // r3
  idPhysics *Physics; // r3
  idAISplinePathMgr_vtbl *v23; // r31
  const idVec3 *v24; // r3
  idPhysics *v25; // r3
  idAISplinePathMgr_vtbl *v26; // r31
  const idVec3 *v27; // r3
  int v28; // r8
  idList<idEventReceiver *,5> *v29; // r8
  idList<idEventReceiver *,5> *v30; // r7
  idLinkList<idWaypoint> *v31; // r11
  idWaypoint *v32; // r11
  _DWORD v33[4]; // [sp+70h] [-C0h] BYREF
  char v34[8]; // [sp+80h] [-B0h] BYREF
  idNavSpline *v35; // [sp+88h] [-A8h]
  idStr v36; // [sp+90h] [-A0h] BYREF

  if ( (gameLocal->GetGameFlags(this: gameLocal) & 2) == 0 )
  {
    next = gameLocal->waypointEntities.next;
    if ( next != nullptr && next != gameLocal->waypointEntities.head )
    {
      owner = next->owner;
      if ( owner != nullptr )
      {
        do
        {
          if ( (unsigned __int8)idSplineWaypoint::IsTypeOf(c: owner) != 0 )
          {
            num = owner->targets.num;
            v5 = nullptr;
            if ( num == 0 )
              goto LABEL_39;
            v6 = 0;
            if ( num <= 0 )
              goto LABEL_34;
            v7 = gameLocal;
            v8 = 0;
            while ( 1 )
            {
              if ( v6 < owner->targets.num )
              {
                value = owner->targets.list[v8].spawnId.value;
                if ( v7->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
                {
                  v10 = v7->entities.ptr[value & 0x1FFF];
                  if ( v10 != nullptr )
                  {
                    if ( idEntity::CastTo(c: v10) != nullptr )
                    {
                      if ( v6 < owner->targets.num
                        && (v11 = owner->targets.list[v8].spawnId.value,
                            gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13)
                        && (v12 = gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
                      {
                        v13 = idEntity::CastTo(c: v12);
                      }
                      else
                      {
                        v13 = nullptr;
                      }
                      v14 = *(_DWORD *)(v13->GetType(this: v13) + 36);
                      if ( v14 < idSplinePath::Type.typeNum
                        || (v16 = v14 <= idSplinePath::Type.lastChild, v15 = 1, !v16) )
                      {
                        v15 = 0;
                      }
                      if ( v15 != 0 )
                      {
                        if ( v6 < owner->targets.num
                          && (v17 = owner->targets.list[v8].spawnId.value,
                              gameLocal->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13)
                          && (v18 = gameLocal->entities.ptr[v17 & 0x1FFF]) != nullptr )
                        {
                          v19 = idEntity::CastTo(c: v18);
                        }
                        else
                        {
                          v19 = nullptr;
                        }
                        v20 = idStr::idStr(this: &v36, text: v19->name.data);
                        NavSpline = idNavSplinePathMgr::FindNavSpline(this, splineName: v20, searchExact: true);
                        if ( NavSpline != nullptr
                          && NavSpline->splinePath != nullptr
                          && NavSpline->splinePath->navSplineType == this->navSplineType )
                        {
                          v5 = NavSpline;
LABEL_34:
                          if ( v6 == owner->targets.num )
                          {
                            Physics = idEntity::GetPhysics(this: owner);
                            v23 = this->__vftable;
                            v24 = Physics->GetOrigin(this: Physics, a2: 0);
                            ((void (__fastcall *)(char *, _DWORD, _DWORD, _DWORD, _DWORD, idNavSplinePosition *(__fastcall *)(struct idAISplinePathMgr *, idNavSplinePosition *, idVec3 *__struct_ptr, idNavSpline *, float, float, idVec3 *__struct_ptr, bool), _DWORD, _DWORD, double, double))v23->GetClosestPathPosition)(
                              a1: v34,
                              a2: LODWORD(v24->x),
                              a3: LODWORD(v24->y),
                              a4: __ROL4__(LODWORD(v24->z), 32),
                              a5: 0,
                              a6: v23->GetClosestPathPosition,
                              a7: LODWORD(vec3_origin.x),
                              a8: LODWORD(vec3_origin.y),
                              a9: 1000.0,
                              a10: 0.1);
                            v5 = v35;
                          }
                          if ( v5 != nullptr && v5->splinePath == nullptr )
                          {
                            idLib::Warning(
                              fmt: "Spline waypoint ( %s ) not associated with a spline! (Spline could be in a different layer.)",
                              owner->name.data);
                            break;
                          }
LABEL_39:
                          v25 = idEntity::GetPhysics(this: owner);
                          v26 = this->__vftable;
                          v27 = v25->GetOrigin(this: v25, a2: 0);
                          ((void (__fastcall *)(_DWORD *, _DWORD, _DWORD, _DWORD, idNavSpline *, int, _DWORD, _DWORD, double, double))v26->GetClosestPathPosition)(
                            a1: v33,
                            a2: LODWORD(v27->x),
                            a3: LODWORD(v27->y),
                            a4: __ROL4__(LODWORD(v27->z), 32),
                            a5: v5,
                            a6: v28,
                            a7: LODWORD(vec3_origin.x),
                            a8: LODWORD(vec3_origin.y),
                            a9: 1000.0,
                            a10: 0.0099999998);
                          v29 = (idList<idEventReceiver *,5> *)v33[1];
                          v30 = (idList<idEventReceiver *,5> *)v33[2];
                          owner[1].__vftable = (idWaypoint_vtbl *)v33[0];
                          owner[1].listenerList = v29;
                          owner[1].listeningToList = v30;
                          break;
                        }
                      }
                    }
                    v7 = gameLocal;
                  }
                }
              }
              ++v6;
              ++v8;
              if ( v6 >= owner->targets.num )
                goto LABEL_34;
            }
          }
          v31 = owner->waypointNode.next;
          if ( v31 == nullptr || v31 == owner->waypointNode.head )
            v32 = nullptr;
          else
            v32 = v31->owner;
          owner = v32;
        }
        while ( v32 != nullptr );
      }
    }
  }
}


// ========================================================================
// ?SpecialSetup@idAISplinePathMgr@@UAAXXZ
// EA  : 0x82B07610
// RVA : 0x00B07610
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __fastcall idAISplinePathMgr::SpecialSetup(idAISplinePathMgr *this)
{
  idAISplinePathMgr::SetupWaypoints(this);
  idNavPathPosTracker::Init(
    this: &this->null_splineTracker,
    gs: &this->tempNavSpline,
    splineType: NAV_SPLINE_TYPE_VEHICLE_AI,
    owner: nullptr);
}


// ========================================================================
// ?CanFindEnemy@idAISplinePathMgr@@QAA_NPAVidVehicleAI@@@Z
// EA  : 0x82B07658
// RVA : 0x00B07658
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

BOOL __fastcall idAISplinePathMgr::CanFindEnemy(idAISplinePathMgr *this, idVehicleAI *vai)
{
  int *p_num; // r27
  signed int num; // r31
  int v6; // r3
  int v7; // r9
  int v8; // r28
  int v9; // r26
  idGameLocal *v10; // r10
  int v11; // r31
  idList<idEntityPtr<idVehicleAI>,5> *p_dormancyList; // r30
  int value; // r9
  idVehicleAI *v14; // r3
  idVehicleAI *v15; // r3

  p_num = &this->dormancyList.num;
  num = this->dormancyList.num;
  if ( num == 0 )
    return true;
  v6 = gameLocal->GetGameFrame(this: gameLocal);
  v7 = *p_num;
  v8 = 0;
  __twllei(num, 0);
  v9 = v6 % num;
  __twlgei(num & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF);
  if ( v7 <= 0 )
    return true;
  v10 = gameLocal;
  v11 = 0;
  p_dormancyList = &this->dormancyList;
  while ( 1 )
  {
    value = p_dormancyList->list[v11].spawnId.value;
    if ( v10->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v14 = (idVehicleAI *)v10->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v15 = idVehicleAI::CastTo(c: v14);
      v10 = gameLocal;
    }
    else
    {
      v15 = nullptr;
    }
    if ( v15 == vai )
      break;
    ++v8;
    ++v11;
    if ( v8 >= *p_num )
      return true;
  }
  return (_cntlzw(v9 - v8) & 0x20) != 0;
}


// ========================================================================
// ?RemoveFromDormancyList@idAISplinePathMgr@@QAAXPAVidVehicleAI@@@Z
// EA  : 0x82B07760
// RVA : 0x00B07760
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __fastcall idAISplinePathMgr::RemoveFromDormancyList(idAISplinePathMgr *this, idVehicleAI *vai)
{
  int *p_num; // r27
  int v4; // r30
  int v5; // r29
  idList<idEntityPtr<idVehicleAI>,5> *p_dormancyList; // r31
  int value; // r9
  idVehicleAI *v8; // r3
  idVehicleAI *v9; // r3
  int num; // r11
  int v11; // r11

  p_num = &this->dormancyList.num;
  v4 = 0;
  if ( this->dormancyList.num > 0 )
  {
    v5 = 0;
    p_dormancyList = &this->dormancyList;
    do
    {
      value = p_dormancyList->list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v8 = (idVehicleAI *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v9 = idVehicleAI::CastTo(c: v8);
      }
      else
      {
        v9 = nullptr;
      }
      if ( v9 == vai && v4 >= 0 )
      {
        num = p_dormancyList->num;
        if ( v4 < num )
        {
          v11 = num - 1;
          p_dormancyList->num = v11;
          if ( v4 != v11 )
            p_dormancyList->list[v5].spawnId.value = p_dormancyList->list[v11].spawnId.value;
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < *p_num );
  }
}


// ========================================================================
// ?Update@idAISplinePathMgr@@UAAXXZ
// EA  : 0x82B078A8
// RVA : 0x00B078A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __fastcall idAISplinePathMgr::Update(idAISplinePathMgr *this)
{
  __int64 v2; // r10
  double updatetime; // fp0
  idCVar *v4; // r25
  unsigned int LastError; // r3
  __int64 v6; // r20
  idGameLocal *v7; // r9
  idLinkList<idVehicle> *next; // r11
  _DWORD *v9; // r29
  int v10; // r11
  idLinkList<idVehicleAI> *v11; // r11
  idVehicleAI *owner; // r29
  idLinkList<idVehicleAI> *v13; // r11
  char *data; // r11
  const char *v15; // r10
  int v16; // r9
  int v17; // r9
  bool v18; // zf
  int v19; // r27
  int v20; // r29
  float *v21; // r26
  double valueFloat; // fp31
  idNavSpline *v23; // r28
  idList<idNavSpline,5> *NavSplineList; // r3
  idNavSpline *v25; // r9
  idPlayer *DebugPlayer; // r3
  idPhysics *Physics; // r3
  float *v28; // r3
  int v29; // r28
  double v42; // fp28
  double v43; // fp27
  double v44; // fp29
  double v45; // fp25
  double v46; // fp24
  double v47; // fp26
  int v48; // r29
  float *v49; // r11
  double v50; // fp0
  char v51; // r11
  idList<idNavSpline,5> *v52; // r3
  idNavPathPosTracker **p_debugTracker; // r29
  idNavPathPosTracker *Tracker; // r3
  navSplineType_t navSplineType; // r8
  char v56; // r5
  __int64 v57; // r4
  __int64 v58; // r4
  char v59; // r5
  float distance; // r9
  idNavSpline *navSpline; // r8
  idDebugHUD_vtbl *v62; // r10
  float rightDistance; // r7
  void (*Printf)(idDebugHUD *, const char *, ...); // r10
  idNavSplinePath *splinePath; // r9
  float v66; // r9
  float v67; // r11
  __int64 v68; // r6
  __int64 v69; // r4
  float v70; // r24
  float v71; // r28
  float v72; // r27
  navSplinePath_t *ShortestPath; // r3
  navSplinePath_t *v74; // r28
  int v75; // r11
  int v76; // r29
  double v77; // fp31
  double v78; // fp30
  double v79; // fp1
  int v80; // r26
  int v81; // r27
  char *v82; // r29
  idEntity *v83; // r3
  idPhysics *v84; // r3
  int v85; // r28
  int v86; // r11
  unsigned int value; // r11
  idNavPathPosTracker *v88; // r29
  idVehicle *v89; // r3
  idProp_VehiclePickup *v90; // r27
  idList<int,5> *v91; // r3
  bool v92; // cr56
  double clockTicks; // fp30
  __int64 v94; // r3
  double v95; // r5
  __int64 v96; // r3
  __int64 v97; // r3
  __int64 v98; // r3
  __int64 v99; // r11
  int valueInteger; // r11
  double length; // [sp+20h] [-3C0h]
  double v102; // [sp+28h] [-3B8h]
  encounterGroupRole_t v103[2]; // [sp+50h] [-390h] BYREF
  __int64 v104; // [sp+58h] [-388h]
  float v105; // [sp+60h] [-380h] BYREF
  float v106; // [sp+64h] [-37Ch]
  float v107; // [sp+68h] [-378h]
  float v108; // [sp+6Ch] [-374h]
  float v109; // [sp+70h] [-370h] BYREF
  float v110; // [sp+74h] [-36Ch]
  float v111; // [sp+78h] [-368h]
  float v112; // [sp+7Ch] [-364h]
  float v113[4]; // [sp+80h] [-360h] BYREF
  idList<int,5> v114; // [sp+90h] [-350h] BYREF
  int v115; // [sp+A0h] [-340h] BYREF
  idList<int,5> v116; // [sp+E0h] [-300h] BYREF
  int v117; // [sp+F0h] [-2F0h] BYREF
  idList<int,5> v118; // [sp+1F0h] [-1F0h] BYREF
  int v119; // [sp+200h] [-1E0h] BYREF

  if ( gameLocal == nullptr )
    return;
  LODWORD(v2) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  updatetime = this->updatetime;
  v104 = v2;
  if ( (float)v2 == updatetime )
    return;
  v4 = &spl_trace;
  HIDWORD(v104) = &spl_trace;
  if ( spl_trace.valueInteger == 1 )
  {
    LastError = GetLastError();
    idLib::Printf(fmt: "BeginTraceRecording: error %d\n", LastError);
  }
  LODWORD(v6) = 0;
  if ( vai_reset.valueInteger != 0 )
  {
    v7 = gameLocal;
    next = gameLocal->vehicleEntities.next;
    if ( next != nullptr && next != gameLocal->vehicleEntities.head )
    {
      v9 = &next->owner->__vftable;
      if ( v9 != nullptr )
      {
        do
        {
          (*(void (__fastcall **)(_DWORD *))(*v9 + 668))(a1: v9);
          (*(void (__fastcall **)(_DWORD *))(*v9 + 132))(a1: v9);
          v10 = v9[4011];
          if ( v10 == 0 || v10 == v9[4010] )
            v9 = nullptr;
          else
            v9 = *(_DWORD **)(v10 + 12);
        }
        while ( v9 != nullptr );
        v7 = gameLocal;
      }
    }
    v11 = v7->vehicleAIEntities.next;
    if ( v11 != nullptr && v11 != v7->vehicleAIEntities.head )
    {
      owner = v11->owner;
      while ( owner != nullptr )
      {
        idVehicleAI::Reset(this: owner);
        owner->vehicleWasActive = false;
        v13 = owner->controlNode.next;
        if ( v13 == nullptr || v13 == owner->controlNode.head )
          owner = nullptr;
        else
          owner = v13->owner;
      }
    }
    idCVar::SetBool(this: &vai_reset, newValue: false, force: true);
  }
  idNavSplinePathMgr::CleanupSplineEntities(this);
  HIDWORD(v6) = &consoleFont[21088];
  if ( spl_debug.valueInteger != 0 || spl_timer.valueInteger != 0 )
    goto LABEL_30;
  data = vai_stats.valueString.data;
  v15 = "0";
  do
  {
    v16 = (unsigned __int8)*data;
    v18 = v16 == 0;
    v17 = v16 - *(unsigned __int8 *)v15;
    if ( v18 )
      break;
    ++data;
    ++v15;
  }
  while ( v17 == 0 );
  if ( v17 != 0 )
  {
LABEL_30:
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_debugHUD", a3: 1, a4: 0);
    debugHUD->Clear(this: debugHUD, a2: false);
    debugHUD->Printf_3(this: debugHUD, a2: 0, a3: 0, a4: &byte_8200D768);
  }
  if ( spl_showAllPaths.valueFloat != 0.0 )
  {
    v19 = 0;
    if ( idNavSplinePathMgr::GetNavSplineList(this)->num > 0 )
    {
      v20 = 0;
      do
      {
        if ( idNavSplinePathMgr::GetNavSplineList(this)->list[v20].startNode != nullptr
          || idNavSplinePathMgr::GetNavSplineList(this)->list[v20].endNode != nullptr )
        {
          v109 = 1.0;
          v21 = &v109;
          v110 = 1.0;
          v111 = 1.0;
          v112 = 1.0;
        }
        else
        {
          v105 = 0.25;
          v21 = &v105;
          v106 = 0.25;
          v107 = 0.25;
          v108 = 0.25;
        }
        valueFloat = spl_pathStepSize.valueFloat;
        v23 = &idNavSplinePathMgr::GetNavSplineList(this)->list[v20];
        NavSplineList = idNavSplinePathMgr::GetNavSplineList(this);
        idNavSpline::Draw(
          this: &NavSplineList->list[v20],
          color: *((idColor **)v21 + 2),
          startDist: 0.0,
          endDist: v23->length,
          stepSize: valueFloat,
          showRight: *((_QWORD *)v21 + 1));
        ++v19;
        v25 = &idNavSplinePathMgr::GetNavSplineList(this)->list[v20++];
        v25->drawtime = 0;
      }
      while ( v19 < idNavSplinePathMgr::GetNavSplineList(this)->num );
      v4 = (idCVar *)HIDWORD(v104);
    }
  }
  if ( spl_showPathBounds.valueInteger != 0 )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    Physics = idEntity::GetPhysics(this: DebugPlayer);
    v28 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v29 = 0;
    _FP8 = (float)((float)1.0e30 - v28[1]);
    _FP6 = (float)((float)1.0e30 - v28[2]);
    _FP10 = (float)((float)1.0e30 - *v28);
    _FP3 = (float)(v28[1] - (float)-1.0e30);
    _FP2 = (float)(v28[2] - (float)-1.0e30);
    _FP4 = (float)(*v28 - (float)-1.0e30);
    __asm
    {
      fsel      f13, f8, f11, f28
      fsel      f11, f6, f9, f28
      fsel      f1, f10, f12, f28
      fsel      f9, f3, f7, f25
      fsel      f8, f2, f5, f25
      fsel      f10, f4, f12, f25
    }
    v42 = (float)((float)_FP13 - (float)1000.0);
    v43 = (float)((float)_FP11 - (float)1000.0);
    v44 = (float)((float)_FP1 - (float)1000.0);
    v45 = (float)((float)_FP9 + (float)1000.0);
    v46 = (float)((float)_FP8 + (float)1000.0);
    v47 = (float)((float)_FP10 + (float)1000.0);
    if ( idNavSplinePathMgr::GetNavSplineList(this)->num > 0 )
    {
      v48 = 0;
      do
      {
        v113[0] = 0.5;
        v113[1] = 0.5;
        v113[2] = 0.5;
        v113[3] = 1.0;
        v49 = (float *)&idNavSplinePathMgr::GetNavSplineList(this)->list[v48];
        if ( v49[24] < v44
          || v49[25] < v42
          || v49[26] < v43
          || v49[21] > v47
          || v49[22] > v45
          || (v50 = v49[23], v51 = 1, v50 > v46) )
        {
          v51 = 0;
        }
        if ( v51 == 0 )
        {
          v105 = 1.0;
          v106 = 1.0;
          v107 = 1.0;
          v108 = 1.0;
          v113[1] = 1.0;
          v113[3] = 1.0;
          v113[0] = 1.0;
          v113[2] = 1.0;
        }
        v52 = idNavSplinePathMgr::GetNavSplineList(this);
        clientGame->renderWorld->DebugBounds(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)v113,
          a3: &v52->list[v48].bounds,
          a4: &vec3_origin,
          a5: 0,
          a6: false);
        ++v29;
        ++v48;
      }
      while ( v29 < idNavSplinePathMgr::GetNavSplineList(this)->num );
    }
  }
  if ( spl_debug.valueInteger != 0 )
  {
    p_debugTracker = &this->debugTracker;
    if ( this->debugTracker == nullptr )
    {
      Tracker = idNavSplinePathMgr::FindTracker(this, owner: gameLocal->world, createTrackerIfNotFound: true);
      navSplineType = this->navSplineType;
      *p_debugTracker = Tracker;
      v103[0] = (encounterGroupRole_t)Tracker;
      Tracker->navSplineType = navSplineType;
      v56 = __ROL4__((*p_debugTracker)->pathPosition.navSpline, 32);
      v57 = *(_QWORD *)&(*p_debugTracker)->pathPosition.distance;
      v103[0] = (encounterGroupRole_t)*p_debugTracker;
      idNavPathPosTracker::SetGoalPathPosition(
        this: (idNavPathPosTracker *)HIDWORD(v57),
        pathPos: (idNavSplinePosition *)v57,
        doPathSearch: v56);
    }
    if ( spl_pos.valueInteger != 0 )
    {
      idCVar::SetBool(this: &spl_pos, newValue: false, force: true);
      v58 = *(_QWORD *)&(*p_debugTracker)->pathPosition.distance;
      v59 = __ROL4__((*p_debugTracker)->pathPosition.navSpline, 32);
      v103[0] = (encounterGroupRole_t)*p_debugTracker;
      idNavPathPosTracker::SetGoalPathPosition(
        this: (idNavPathPosTracker *)HIDWORD(v58),
        pathPos: (idNavSplinePosition *)v58,
        doPathSearch: v59);
    }
    debugHUD->SetTextScale(this: debugHUD, a2: 0.75);
    debugHUD->Printf(this: debugHUD, a2: "\n^3     -- VEHICLE SPLINE DEBUG --\n");
    distance = (*p_debugTracker)->pathPosition.distance;
    navSpline = (*p_debugTracker)->pathPosition.navSpline;
    v62 = debugHUD->__vftable;
    rightDistance = (*p_debugTracker)->pathPosition.rightDistance;
    v103[0] = (encounterGroupRole_t)*p_debugTracker;
    v109 = distance;
    v102 = distance;
    Printf = v62->Printf;
    splinePath = navSpline->splinePath;
    v111 = *(float *)&v102;
    v110 = rightDistance;
    Printf(this: debugHUD, a2: "^7     Spline: ^5%s  -  % 6.0f\n", splinePath->name.data, LODWORD(v102));
    length = (*p_debugTracker)->pathPosition.navSpline->length;
    debugHUD->Printf(this: debugHUD, a2: (const char *)HIDWORD(length), LODWORD(length));
    v66 = (*p_debugTracker)->pathPosition.distance;
    v67 = (*p_debugTracker)->pathPosition.rightDistance;
    v103[0] = (encounterGroupRole_t)*p_debugTracker;
    v68 = *(_QWORD *)(v103[0] + 28);
    v69 = *(_QWORD *)(v103[0] + 4);
    v109 = v66;
    v110 = v67;
    v70 = *(float *)(v103[0] + 36);
    v71 = *(float *)(v103[0] + 28);
    v72 = *(float *)(v103[0] + 32);
    HIDWORD(v68) = __ROL4__(*(_DWORD *)(v103[0] + 12), 32);
    v111 = *(float *)(v103[0] + 12);
    v105 = v71;
    v107 = v70;
    v106 = v72;
    ShortestPath = idNavSplinePathMgr::GetShortestPath(
                     this: (idNavSplinePathMgr *)HIDWORD(v69),
                     start: (idNavSplinePosition *)v69,
                     end: (idNavSplinePosition *)HIDWORD(v68),
                     path: (navSplinePath_t *)v68);
    v74 = ShortestPath;
    if ( ShortestPath != nullptr && ShortestPath->path.num >= 2 )
    {
      debugHUD->Printf(
        this: debugHUD,
        a2: "\n     Dist To Goal: ^2% 5.0f\n",
        (unsigned int)COERCE_UNSIGNED_INT64(ShortestPath->distance));
      v76 = 0;
      v103[0] = (encounterGroupRole_t)v74->path.num;
      v75 = v103[0];
      if ( v103[0] > ROLE_NONE )
      {
        v77 = v109;
        v78 = v105;
        do
        {
          if ( v76 != 0 )
          {
            v103[0] = v75;
            if ( v76 == v75 - 1 )
              v79 = v78;
            else
              v79 = v74->path.list[v76].navSpline->length;
          }
          else
          {
            v79 = v77;
          }
          debugHUD->Printf(this: debugHUD, a2: "^2     %s  -  % 6.0f\n", HIDWORD(v79), LODWORD(v79));
          ++v76;
          v103[0] = (encounterGroupRole_t)v74->path.num;
          v75 = v103[0];
        }
        while ( v76 < v103[0] );
      }
      navSplinePath_t::Draw(
        this: (navSplinePath_t *)LODWORD(idColor::colorMagenta.r),
        color: (idColor *)LODWORD(idColor::colorMagenta.b),
        stepSize: spl_pathStepSize.valueFloat);
    }
    else
    {
      debugHUD->Printf(this: debugHUD, a2: "\n     Dist To Goal: ^1** NO PATH **\n");
    }
  }
  idAISplinePathMgr::CycleFollow(this);
  if ( vai_stats.valueInteger != 0 )
    idAISplinePathMgr::ShowVehicleAiStats(this);
  idVehicle::CycleFollow();
  if ( this->navSplineType != NAV_SPLINE_TYPE_QUEST )
  {
    v114.num = 0;
    v114.granularity = 1;
    v114.memTag = 5;
    v114.size = 16;
    v114.list = &v115;
    v114.listStatic = 1;
    v118.num = 0;
    v118.size = 64;
    v118.granularity = 1;
    v118.list = &v119;
    v118.memTag = 5;
    v118.listStatic = 1;
    v116.size = 64;
    v116.granularity = 1;
    v116.list = &v117;
    v116.num = 0;
    v116.memTag = 5;
    v116.listStatic = 1;
    v85 = 0;
    v103[0] = ROLE_NONE;
    if ( this->usedTrackers.num > 0 )
    {
      v86 = 0;
      do
      {
        value = this->usedTrackers.list[v86].value;
        v88 = &this->trackerPool.trackers[value];
        if ( (idAISplinePathMgr *)((char *)this + value * 312) == (idAISplinePathMgr *)-140 )
        {
          idNavSplinePathMgr::ReleaseTracker(this, tracker: nullptr);
        }
        else
        {
          v89 = (idVehicle *)idNavPathPosTracker::GetOwner(this: &this->trackerPool.trackers[value]);
          v90 = (idProp_VehiclePickup *)v89;
          if ( v89 != nullptr )
          {
            if ( idVehicle::CastTo(c: v89) != nullptr )
            {
              v91 = &v114;
            }
            else
            {
              v18 = idProp_VehiclePickup::CastTo(c: v90) != nullptr;
              v91 = &v116;
              if ( !v18 )
                v91 = &v118;
            }
            idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)v91, obj: v103);
          }
          else
          {
            idNavSplinePathMgr::ReleaseTracker(this, tracker: v88);
          }
        }
        v92 = ++v85 < this->usedTrackers.num;
        v86 = v85;
        v103[0] = v85;
      }
      while ( v92 );
    }
    this->numVehiclePickups = v116.num;
    idAISplinePathMgr::UpdateTrackersPeriodic(this, indexList: &v114, frequencyInFrames: 4, fastUpdateOthers: true);
    idAISplinePathMgr::UpdateTrackersPeriodic(this, indexList: &v116, frequencyInFrames: 30, fastUpdateOthers: false);
    idAISplinePathMgr::UpdateTrackersPeriodic(this, indexList: &v118, frequencyInFrames: 10, fastUpdateOthers: false);
    if ( v116.listStatic == 0 || v116.listStatic == 2 )
    {
      if ( v116.list != nullptr )
        idMem::Free(this: &mem, ptr: v116.list, align: ALIGN_16);
      v116.list = nullptr;
      v116.size = 0;
    }
    v116.num = 0;
    if ( v118.listStatic == 0 || v118.listStatic == 2 )
    {
      if ( v118.list != nullptr )
        idMem::Free(this: &mem, ptr: v118.list, align: ALIGN_16);
      v118.list = nullptr;
      v118.size = 0;
    }
    v118.num = 0;
    if ( v114.listStatic == 0 || v114.listStatic == 2 )
    {
      if ( v114.list != nullptr )
        idMem::Free(this: &mem, ptr: v114.list, align: ALIGN_16);
      v114.list = nullptr;
      v114.size = 0;
    }
    v114.num = 0;
    goto LABEL_105;
  }
  v80 = 0;
  if ( this->usedTrackers.num > 0 )
  {
    v81 = 0;
    do
    {
      v82 = (char *)this + 312 * this->usedTrackers.list[v81].value;
      v83 = idNavPathPosTracker::GetOwner(this: (idNavPathPosTracker *)(v82 + 140));
      v84 = idEntity::GetPhysics(this: v83);
      v84->GetOrigin(this: v84, a2: 0);
      idNavPathPosTracker::SetWorldPosition(
        this: **((idNavPathPosTracker ***)v82 + 36),
        pos: *(idVec3 **)(*((_DWORD *)v82 + 36) + 4),
        splineDistance: (idNavSplinePosition *)__ROL4__(*(_DWORD *)(*((_DWORD *)v82 + 36) + 8), 32));
      idNavPathPosTracker::Update(this: (idNavPathPosTracker *)(v82 + 140), fullUpdate: true);
      ++v80;
      ++v81;
    }
    while ( v80 < this->usedTrackers.num );
LABEL_105:
    v4 = (idCVar *)HIDWORD(v104);
  }
  if ( spl_graph.valueInteger != 0 )
    idNavSplineGraph::Draw(this: &this->splineGraph);
  if ( spl_waypoints.valueInteger != 0 )
    idAISplinePathMgr::DrawWaypoints(this);
  if ( spl_timer.valueInteger != 0 )
  {
    debugHUD->Printf(this: debugHUD, a2: "\n\n^7     -- SPLINE / PATH TIMING --\n");
    clockTicks = (float)this->navSplinePathTimer.clockTicks;
    LODWORD(v94) = Sys_ClockTicksPerSecond();
    v104 = v94;
    v95 = (float)((float)clockTicks / (float)((float)v94 * (float)0.001));
    debugHUD->Printf(
      this: debugHUD,
      a2: (const char *)HIDWORD(v95),
      LODWORD(v95),
      this->navSplinePathCount,
      this->navSplinePathCount2);
    LODWORD(v96) = Sys_ClockTicksPerSecond();
    v104 = v96;
    ((void (*)(void))debugHUD->Printf)();
    LODWORD(v97) = Sys_ClockTicksPerSecond();
    v104 = v97;
    ((void (*)(void))debugHUD->Printf)();
    LODWORD(v98) = Sys_ClockTicksPerSecond();
    v104 = v98;
    ((void (*)(void))debugHUD->Printf)();
    this->navSplinePathTimer.clockTicks = v6;
    this->navSplinePathCount = 0;
    this->navSplinePathCount2 = 0;
    this->navSplineTrackerTimer.clockTicks = v6;
    this->navSplineTrackerCount = 0;
    this->navSplineClosestPosTimer.clockTicks = v6;
    this->navSplineClosestPosCount = 0;
    this->navSplineClosestPosSectionTimer.clockTicks = v6;
    this->navSplineClosestPosSectionCount = 0;
  }
  LODWORD(v99) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v104 = v99;
  this->updatetime = (float)v99;
  if ( this->nextRecalcTime < idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) )
    this->nextRecalcTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  valueInteger = v4->valueInteger;
  if ( valueInteger > 0 )
    idCVar::SetInteger(this: v4, newValue: valueInteger - 1, force: true);
}


// ========================================================================
// __unwind$492067
// EA  : 0x82B086C0
// RVA : 0x00B086C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_492067()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 992 + 144));
}


// ========================================================================
// __unwind$492068
// EA  : 0x82B086E8
// RVA : 0x00B086E8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_492068()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 992 + 496));
}


// ========================================================================
// __unwind$492069
// EA  : 0x82B08710
// RVA : 0x00B08710
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void _unwind_492069()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 992 + 224));
}


// ========================================================================
// ?AddToDormancyList@idAISplinePathMgr@@QAAXPAVidVehicleAI@@@Z
// EA  : 0x82B08738
// RVA : 0x00B08738
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __fastcall idAISplinePathMgr::AddToDormancyList(idAISplinePathMgr *this, idVehicleAI *vai)
{
  int *p_num; // r27
  int v5; // r30
  idGameLocal *v6; // r10
  int v7; // r31
  idList<idEntityPtr<idVehicleAI>,5> *p_dormancyList; // r29
  int value; // r9
  idVehicleAI *v10; // r3
  idVehicleAI *v11; // r3
  idEntityPtr<idEntity> v12; // [sp+50h] [-50h] BYREF

  p_num = &this->dormancyList.num;
  v5 = 0;
  v6 = gameLocal;
  if ( this->dormancyList.num <= 0 )
  {
LABEL_9:
    if ( vai != nullptr )
      v12.spawnId.value = (v6->spawnIds.ptr[vai->entityNumber] << 13) | vai->entityNumber;
    else
      v12.spawnId.value = 0x1FFF;
    idList<idEntityPtr<idEntity>,58>::Append(this: (idList<idEntityPtr<idEntity>,58> *)&this->dormancyList, obj: &v12);
  }
  else
  {
    v7 = 0;
    p_dormancyList = &this->dormancyList;
    while ( 1 )
    {
      value = p_dormancyList->list[v7].spawnId.value;
      if ( v6->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v10 = (idVehicleAI *)v6->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v11 = idVehicleAI::CastTo(c: v10);
        v6 = gameLocal;
      }
      else
      {
        v11 = nullptr;
      }
      if ( v11 == vai )
        break;
      ++v5;
      ++v7;
      if ( v5 >= *p_num )
        goto LABEL_9;
    }
  }
}


// ========================================================================
// `dynamic initializer for 'spl_debug''
// EA  : 0x83369BA8
// RVA : 0x01369BA8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_debug__()
{
  idCVar::idCVar(
    this: &spl_debug,
    name: "spl_debug",
    value: "0",
    flags: 1,
    description: "Show debug path",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_debug__);
}


// ========================================================================
// `dynamic initializer for 'spl_pos''
// EA  : 0x83369C00
// RVA : 0x01369C00
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_pos__()
{
  idCVar::idCVar(
    this: &spl_pos,
    name: "spl_pos",
    value: "0",
    flags: 1,
    description: "Set spline position (for path debugging)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_pos__);
}


// ========================================================================
// `dynamic initializer for 'spl_graph''
// EA  : 0x83369C58
// RVA : 0x01369C58
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_graph__()
{
  idCVar::idCVar(
    this: &spl_graph,
    name: "spl_graph",
    value: "0",
    flags: 1,
    description: "Draw spline graph",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_graph__);
}


// ========================================================================
// `dynamic initializer for 'spl_timer''
// EA  : 0x83369CB0
// RVA : 0x01369CB0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_timer__()
{
  idCVar::idCVar(
    this: &spl_timer,
    name: "spl_timer",
    value: "0",
    flags: 1,
    description: "Show spline timing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_timer__);
}


// ========================================================================
// `dynamic initializer for 'spl_showAllPaths''
// EA  : 0x83369D08
// RVA : 0x01369D08
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_showAllPaths__()
{
  idCVar::idCVar(
    this: &spl_showAllPaths,
    name: "spl_showAllPaths",
    value: "0",
    flags: 4,
    description: "Display all vehicle ai paths",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_showAllPaths__);
}


// ========================================================================
// `dynamic initializer for 'spl_pathStepSize''
// EA  : 0x83369D60
// RVA : 0x01369D60
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_pathStepSize__()
{
  idCVar::idCVar(
    this: &spl_pathStepSize,
    name: "spl_pathStepSize",
    value: "300",
    flags: 4,
    description: "Spline point step size (smaller = more detail)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_pathStepSize__);
}


// ========================================================================
// `dynamic initializer for 'spl_showPathBounds''
// EA  : 0x83369DB8
// RVA : 0x01369DB8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_showPathBounds__()
{
  idCVar::idCVar(
    this: &spl_showPathBounds,
    name: "spl_showPathBounds",
    value: "0",
    flags: 1,
    description: "Show spline bounds",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_showPathBounds__);
}


// ========================================================================
// `dynamic initializer for 'spl_waypoints''
// EA  : 0x83369E10
// RVA : 0x01369E10
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_waypoints__()
{
  idCVar::idCVar(
    this: &spl_waypoints,
    name: "spl_waypoints",
    value: "0",
    flags: 1,
    description: "Show spline waypoints",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_waypoints__);
}


// ========================================================================
// `dynamic initializer for 'spl_trace''
// EA  : 0x83369E68
// RVA : 0x01369E68
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__spl_trace__()
{
  idCVar::idCVar(
    this: &spl_trace,
    name: "spl_trace",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__spl_trace__);
}


// ========================================================================
// `dynamic initializer for 'vai_reset''
// EA  : 0x83369EC0
// RVA : 0x01369EC0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\splinepathmgr.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_reset__()
{
  idCVar::idCVar(
    this: &vai_reset,
    name: "vai_reset",
    value: "0",
    flags: 1,
    description: "Resets vehicle AI",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_reset__);
}

