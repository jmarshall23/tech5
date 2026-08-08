
// ========================================================================
// ?FindAvoidEntityPoint@idBotUtils@@SA_NPBVidBot@@PBVidEntity@@MAAVidVec3@@PBV4@M@Z
// EA  : 0x82B44060
// RVA : 0x00B44060
// PDB : w:\tech5\tungsten\game\bot\bot_utils.cpp
// ========================================================================

int __fastcall idBotUtils::FindAvoidEntityPoint(
        const idBot *bot,
        idPlayer *ent,
        double moveDist,
        idVec3 *point,
        const idVec3 *anchorPoint,
        double anchorRadius,
        float *a7)
{
  idBotMoveState *moveState; // r11
  const idAAS2 *aas; // r23
  int AreaNum; // r22
  idPhysics *Physics; // r3
  float *v18; // r25
  idPhysics *v19; // r3
  float *v20; // r30
  double v21; // fp7
  double v22; // fp6
  idPlayer *v23; // r3
  idPresentable *presentable; // r3
  int v25; // r3
  float v26; // r8
  idPresentable *v27; // r11
  double v28; // fp22
  double v29; // fp27
  double v30; // fp26
  double v31; // fp25
  double v32; // fp29
  float *v33; // r29
  double v34; // fp6
  double v35; // fp0
  double v36; // fp12
  double v37; // fp13
  double v38; // fp8
  double v39; // fp7
  double v40; // fp6
  double v41; // fp30
  idVec3 v42; // [sp+60h] [-1C0h] BYREF
  idVec3 v43; // [sp+70h] [-1B0h] BYREF
  float v44; // [sp+80h] [-1A0h] BYREF
  float v45; // [sp+84h] [-19Ch]
  float v46; // [sp+88h] [-198h]
  idVec3 v47; // [sp+90h] [-190h] BYREF
  idRotation v48; // [sp+A0h] [-180h] BYREF
  float v49; // [sp+E4h] [-13Ch]
  float v50; // [sp+E8h] [-138h]
  int v51; // [sp+ECh] [-134h]
  int v52; // [sp+F0h] [-130h]
  int v53; // [sp+F4h] [-12Ch]
  int v54; // [sp+F8h] [-128h]
  int v55; // [sp+FCh] [-124h]
  int v56; // [sp+100h] [-120h]
  idRotation v57[2]; // [sp+110h] [-110h] BYREF

  if ( ent == nullptr )
    return 0;
  moveState = bot->moveState;
  aas = moveState->pathInfo.aas;
  if ( aas == nullptr )
    return 0;
  AreaNum = idActor::GetAreaNum(this: bot->owner, aas: moveState->pathInfo.aas);
  if ( AreaNum == 0 )
    return 0;
  Physics = idEntity::GetPhysics(this: ent);
  v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v19 = idEntity::GetPhysics(this: bot->owner);
  v20 = (float *)v19->GetOrigin(this: v19, a2: 0);
  v21 = (float)(v20[1] - v18[1]);
  v22 = (float)(v20[2] - v18[2]);
  v47.x = *v20 - *v18;
  v47.y = v21;
  v47.z = v22;
  idVec3::NormalizeFast(this: &v47);
  v23 = idPlayer::CastTo(c: ent);
  if ( v23 != nullptr )
  {
    presentable = v23->presentable;
    v25 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
    v26 = *(float *)(v25 + 46172);
    v42.y = *(float *)(v25 + 46168);
    v42.x = 0.0;
    v42.z = v26;
    idAngles::ToVectors(this: (idAngles *)&v42, forward: &v43, right: nullptr, up: nullptr);
  }
  else
  {
    v27 = ent->presentable;
    if ( v27 == nullptr )
    {
      idEntity::InitPresentableInternal(this: ent);
      v27 = ent->presentable;
    }
    v43.x = v27->axis.mat[0].x;
    v43.y = v27->axis.mat[0].y;
    v43.z = v27->axis.mat[0].z;
  }
  v28 = (float)((float)anchorRadius * (float)anchorRadius);
  v29 = 0.0;
  v30 = 0.0;
  v31 = 0.0;
  v32 = -1.0;
  v33 = (float *)ANGLES_TO_TEST;
  do
  {
    if ( v32 >= 1.0 )
      break;
    idRotation::idRotation(this: v57, rotationOrigin: &vec3_origin, rotationVec: &vec3_up, rotationAngle: *v33);
    idRotation::operator*(this: &v48, result: v57, v: &v47);
    v34 = *v20;
    v35 = (float)(v20[1] + (float)(v48.origin.y * (float)moveDist));
    v36 = (float)(v20[2] + (float)(v48.origin.z * (float)moveDist));
    v45 = v20[1] + (float)(v48.origin.y * (float)moveDist);
    v46 = v36;
    v37 = (float)((float)v34 + (float)(v48.origin.x * (float)moveDist));
    v44 = (float)v34 + (float)(v48.origin.x * (float)moveDist);
    if ( a7 != nullptr )
    {
      v38 = (float)((float)v35 - a7[1]);
      if ( (float)((float)((float)v38 * (float)v38) + (float)((float)((float)v37 - *a7) * (float)((float)v37 - *a7))) > v28 )
        continue;
    }
    v39 = (float)((float)v35 - v18[1]);
    v40 = (float)((float)v36 - v18[2]);
    v42.x = (float)v37 - *v18;
    v42.y = v39;
    v41 = 1.0;
    v42.z = v40;
    idVec3::NormalizeFast(this: &v42);
    if ( (float)((float)(v42.x * v43.x) + (float)((float)(v42.z * v43.z) + (float)(v42.y * v43.y))) > 0.85000002 )
      v41 = 0.5;
    v48.vec.y = 0.0;
    memset(&v48.axis.mat[0].y, 0, 12);
    v48.vec.z = 0.0;
    v48.angle = 0.0;
    v48.axis.mat[0].x = 0.0;
    v48.axis.mat[2].y = 0.0;
    v48.axis.mat[1].y = 0.0;
    v48.axis.mat[2].z = 0.0;
    v48.axis.mat[1].z = 0.0;
    v51 = 0;
    v48.axis.mat[2].x = 0.0;
    v52 = 0;
    *(float *)&v48.axisValid = 0.0;
    v53 = 0;
    v49 = 0.0;
    v54 = 0;
    v50 = 0.0;
    v55 = 0;
    v56 = 0;
    ((void (__fastcall *)(const idAAS2 *, float *, float *, int, float *, int, _DWORD, _DWORD))aas->TraceFloor)(
      a1: aas,
      a2: &v48.vec.y,
      a3: v20,
      a4: AreaNum,
      a5: &v44,
      a6: 40,
      a7: 0,
      a8: 0);
    if ( v48.vec.y > v32 )
    {
      v29 = v44;
      v32 = (float)(v48.vec.y * (float)v41);
      v30 = v45;
      v31 = v46;
    }
    ++v33;
  }
  while ( (int)v33 < (int)flt_822A860C );
  if ( v32 == -1.0 )
    return 0;
  anchorPoint->x = v29;
  anchorPoint->y = v30;
  anchorPoint->z = v31;
  return 1;
}

