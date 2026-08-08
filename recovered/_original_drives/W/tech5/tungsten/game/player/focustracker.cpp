
// ========================================================================
// ?ClientUpdateCursor@idFocusTracker@@IAA_NPAVidPresentablePlayer@@PAVidPresentable@@@Z
// EA  : 0x82DFAE58
// RVA : 0x00DFAE58
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

int __fastcall idFocusTracker::ClientUpdateCursor(
        idFocusTracker *this,
        idPresentablePlayer *owner,
        idPresentable *target)
{
  idStrId *p_text; // r28
  usableState_t v7; // r6
  char v9; // [sp+50h] [-30h] BYREF

  p_text = &this->crosshairInfo.text;
  idStrId::Set(this: &this->crosshairInfo.text, key: &byte_8200D768);
  this->crosshairInfo.material = CHMATERIAL_DEFAULT;
  if ( target != nullptr && this->traceDistance <= 160.0 )
  {
    v7 = target->GetOnlineUsableState(this: target, a2: owner, a3: owner->clientPlayerInputFrame);
    this->usableState = v7;
    if ( v7 != USABLE_NOT_USABLE )
    {
      target->GetOnlineModifiedCrosshairInfo(
        this: target,
        a2: owner,
        a3: &this->focusTrace,
        a4: v7,
        a5: &this->crosshairInfo);
      p_text->index = target->GetOnlineUsableText(this: &v9, result: target)->index;
    }
  }
  return 0;
}


// ========================================================================
// ?GetZoomedDistance@idFocusTracker_Player@@IBAMPBVidPlayer@@M@Z
// EA  : 0x82DFAF20
// RVA : 0x00DFAF20
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

float __fastcall idFocusTracker_Player::GetZoomedDistance(
        idFocusTracker_Player *this,
        const idPlayer *player,
        double dist)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v6; // r3
  idWeapon *EquippedWeapon; // r3
  double v8; // fp1

  if ( player != nullptr
    && ((presentable = player->presentable) == nullptr
      ? (v6 = nullptr)
      : (v6 = presentable->GetPlayerInterface_2(this: presentable)),
        idPresentablePlayer::IsZoomedIn(ptr: v6)
     && idActor::GetEquippedWeapon(this: &player->idActor, slot: EQUIP_RIGHT_HAND) != nullptr
     && (*((_BYTE *)idActor::GetEquippedWeapon(this: &player->idActor, slot: EQUIP_RIGHT_HAND) + 452) & 8) != 0) )
  {
    EquippedWeapon = idActor::GetEquippedWeapon(this: &player->idActor, slot: EQUIP_RIGHT_HAND);
    v8 = (float)((float)__SPAIR64__(0x82000000, idWeapon::MaxRange(this: EquippedWeapon, secondaryAmmo: false))
               + (float)10.0);
  }
  else
  {
    v8 = dist;
  }
  return *((float *)&v8 + 1);
}


// ========================================================================
// ?GetZoomedDistance@idFocusTracker_Player@@IBAMPBVidPresentablePlayer@@M@Z
// EA  : 0x82DFB000
// RVA : 0x00DFB000
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

float __fastcall idFocusTracker_Player::GetZoomedDistance(
        idFocusTracker_Player *this,
        idPresentablePlayer *player,
        double dist)
{
  idWeapon *v5; // r3
  double v6; // fp1

  if ( player != nullptr
    && idPresentablePlayer::IsZoomedIn(ptr: player)
    && player->GetEquippedWeapon(this: player, a2: 2) != nullptr
    && (*((_BYTE *)player->GetEquippedWeapon(this: player, a2: 2) + 452) & 8) != 0 )
  {
    v5 = player->GetEquippedWeapon(this: player, a2: 2);
    v6 = (float)((float)__SPAIR64__(0x82000000, idWeapon::MaxRange(this: v5, secondaryAmmo: false)) + (float)10.0);
  }
  else
  {
    v6 = dist;
  }
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?GetFocusDistance@idFocusTracker_Player@@MBAMPBVidActor@@PBVidEntity@@@Z
// EA  : 0x82DFB0E0
// RVA : 0x00DFB0E0
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

float __fastcall idFocusTracker_Player::GetFocusDistance(
        idFocusTracker_Player *this,
        idPlayer *owner,
        const idEntity *ent)
{
  idPlayer *v4; // r3
  double ZoomedDistance; // fp1

  v4 = idPlayer::CastTo(c: owner);
  ZoomedDistance = idFocusTracker_Player::GetZoomedDistance(this, player: v4, dist: 2048.0);
  return *((float *)&ZoomedDistance + 1);
}


// ========================================================================
// ?GetFocusDistance@idFocusTracker_Player@@MBAMPBVidPresentablePlayer@@PBVidEntity@@@Z
// EA  : 0x82DFB128
// RVA : 0x00DFB128
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

double __fastcall idFocusTracker_Player::GetFocusDistance(
        idFocusTracker_Player *this,
        idPresentablePlayer *owner,
        const idEntity *ent)
{
  return idFocusTracker_Player::GetZoomedDistance(this, player: owner, dist: 2048.0);
}


// ========================================================================
// ?GetUsableDistance@idFocusTracker_Player@@MBAMPBVidActor@@PBVidEntity@@@Z
// EA  : 0x82DFB138
// RVA : 0x00DFB138
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

float __fastcall idFocusTracker_Player::GetUsableDistance(
        idFocusTracker_Player *this,
        idPlayer *owner,
        const idEntity *ent)
{
  idPlayer *v4; // r3
  double ZoomedDistance; // fp1

  v4 = idPlayer::CastTo(c: owner);
  ZoomedDistance = idFocusTracker_Player::GetZoomedDistance(this, player: v4, dist: 160.0);
  return *((float *)&ZoomedDistance + 1);
}


// ========================================================================
// ?UpdateCursorFlash@idFocusTracker_Player@@MAAXPAVidActor@@@Z
// EA  : 0x82DFB180
// RVA : 0x00DFB180
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void __fastcall idFocusTracker_Player::UpdateCursorFlash(idFocusTracker_Player *this, idPlayer *owner)
{
  idPlayer *v3; // r30

  v3 = idPlayer::CastTo(c: owner);
  if ( v3 != nullptr
    && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) < v3->hitFlashTime )
  {
    this->crosshairInfo.color = idColor::colorRed;
    this->crosshairInfo.colorState = CROSSHAIR_COLOR_NEGATIVE;
  }
}


// ========================================================================
// ?GetValidTraceResultFocusEntity@idFocusTracker@@QAAPAVidEntity@@_NPAPBVidTypeInfo@@HPBMAAVidVec3@@AAH@Z
// EA  : 0x82DFB220
// RVA : 0x00DFB220
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

idEntity *__fastcall idFocusTracker::GetValidTraceResultFocusEntity(
        idFocusTracker *this,
        bool includeBoundCheck,
        const idTypeInfo **checkTypes,
        int numCheckTypes,
        const float *maxRanges,
        idVec3 *resultEndPos,
        int *resultID)
{
  idEntity *v13; // r22
  idGameLocal *v14; // r10
  int value; // r9
  idEntityPtr<idEntity> *p_gatherPointEntity; // r3
  idEntity *result; // r3
  int entityNum; // r11
  int v19; // r10
  idEntityPtr<idEntity> *v20; // r3
  idEntity *v21; // r25
  int v22; // r29
  const idTypeInfo **v23; // r27
  int v24; // r11
  idEntity *v25; // r27
  double z; // fp12
  int v27; // r11
  double v28; // fp12
  double v29; // fp9
  double v30; // fp6

  v13 = nullptr;
  if ( numCheckTypes == 0 )
  {
    v14 = gameLocal;
    if ( includeBoundCheck )
    {
      value = this->gatherPointEntity.spawnId.value;
      p_gatherPointEntity = &this->gatherPointEntity;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        result = idEntityPtr<idEntity const>::operator->(this: p_gatherPointEntity);
        resultEndPos->x = this->gatherPointEndPos.x;
        resultEndPos->y = this->gatherPointEndPos.y;
        resultEndPos->z = this->gatherPointEndPos.z;
        return result;
      }
    }
    entityNum = this->pointTraceResult.c.entityNum;
    if ( entityNum > 0 )
    {
      resultEndPos->x = this->pointTraceResult.endpos.x;
      resultEndPos->y = this->pointTraceResult.endpos.y;
      result = v14->entities.ptr[entityNum];
      resultEndPos->z = this->pointTraceResult.endpos.z;
      return result;
    }
    return v13;
  }
  if ( includeBoundCheck && this->validGatherPointResult )
  {
    v19 = this->gatherPointEntity.spawnId.value;
    v20 = &this->gatherPointEntity;
    if ( gameLocal->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13 )
    {
      v21 = idEntityPtr<idEntity const>::operator->(this: v20);
      if ( v21 != nullptr )
      {
        v22 = 0;
        if ( numCheckTypes > 0 )
        {
          v23 = checkTypes;
          while ( (unsigned __int8)idClass::IsType(this: v21, superclass: *v23) == 0 )
          {
            ++v22;
            ++v23;
            if ( v22 >= numCheckTypes )
              goto LABEL_15;
          }
          v13 = v21;
          resultEndPos->x = this->gatherPointEndPos.x;
          resultEndPos->y = this->gatherPointEndPos.y;
          z = this->gatherPointEndPos.z;
          goto LABEL_24;
        }
      }
    }
  }
LABEL_15:
  if ( this->validPointResult )
  {
    v24 = this->pointTraceResult.c.entityNum;
    if ( v24 > 0 )
    {
      v25 = gameLocal->entities.ptr[v24];
      if ( v25 != nullptr )
      {
        v22 = 0;
        if ( numCheckTypes > 0 )
        {
          while ( (unsigned __int8)idClass::IsType(this: v25, superclass: *checkTypes) == 0 )
          {
            ++v22;
            ++checkTypes;
            if ( v22 >= numCheckTypes )
              goto LABEL_25;
          }
          v13 = v25;
          resultEndPos->x = this->pointTraceResult.endpos.x;
          resultEndPos->y = this->pointTraceResult.endpos.y;
          z = this->pointTraceResult.endpos.z;
LABEL_24:
          resultEndPos->z = z;
          *resultID = v22;
        }
      }
    }
  }
LABEL_25:
  v27 = *resultID;
  if ( maxRanges[v27] <= 0.0 )
    return v13;
  result = nullptr;
  v28 = (float)(resultEndPos->z - this->focusTrace.start.z);
  v29 = (float)(resultEndPos->x - this->focusTrace.start.x);
  v30 = (float)(resultEndPos->y - this->focusTrace.start.y);
  if ( (float)((float)((float)((float)v30 * (float)v30)
                     + (float)((float)((float)v29 * (float)v29) + (float)((float)v28 * (float)v28)))
             / (float)(maxRanges[v27] * maxRanges[v27])) < 1.0 )
    return v13;
  return result;
}


// ========================================================================
// ?GetValidpointTraceResultWithinRange@idFocusTracker@@QAAPBUtrace_t@@ABM@Z
// EA  : 0x82DFB490
// RVA : 0x00DFB490
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

const trace_t *__fastcall idFocusTracker::GetValidpointTraceResultWithinRange(
        idFocusTracker *this,
        const float *maxRange)
{
  double v3; // fp10
  double v4; // fp7
  double v5; // fp4

  if ( this->validPointResult
    && (*maxRange <= 0.0
     || (v3 = (float)(this->pointTraceResult.endpos.y - this->focusTrace.start.y),
         v4 = (float)(this->pointTraceResult.endpos.x - this->focusTrace.start.x),
         (float)((float)((float)((float)(v5 = (float)(this->pointTraceResult.endpos.z - this->focusTrace.start.z))
                               * (float)v5)
                       + (float)((float)((float)v4 * (float)v4) + (float)((float)v3 * (float)v3)))
               / (float)(*maxRange * *maxRange)) < 1.0)) )
  {
    return &this->pointTraceResult;
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?ClearFocus@idFocusTracker@@QAAXXZ
// EA  : 0x82DFB600
// RVA : 0x00DFB600
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void __fastcall idFocusTracker::ClearFocus(idFocusTracker *this)
{
  this->useButtonOverride = 4;
  this->focusUsable.spawnId.value = 0x1FFF;
  this->focusEntity.spawnId.value = 0x1FFF;
  this->focusPresentable.spawnId = 0;
  this->cursorId = 0;
  this->clearFocusTime = 0;
  this->overFriendly = false;
  this->overTakedownTarget = TAKEDOWNMODE_UNAVAILABLE;
}


// ========================================================================
// ?SetFocusEntity@idFocusTracker@@AAAXPAVidEntity@@@Z
// EA  : 0x82DFB6B8
// RVA : 0x00DFB6B8
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void __fastcall idFocusTracker::SetFocusEntity(idFocusTracker *this, idEntity *ent)
{
  if ( ent != nullptr )
    this->focusEntity.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    this->focusEntity.spawnId.value = 0x1FFF;
  this->clearFocusTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) + 100;
}


// ========================================================================
// ?SetFocusOverride@idFocusTracker@@QAAXPAVidEntity@@@Z
// EA  : 0x82DFB738
// RVA : 0x00DFB738
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void __fastcall idFocusTracker::SetFocusOverride(idFocusTracker *this, idEntity *ent)
{
  if ( ent != nullptr )
    this->focusEntityOverride.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    this->focusEntityOverride.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?ClientUpdateFocus@idFocusTracker@@QAAXPAVidPresentablePlayer@@ABVidVec3@@ABVidMat3@@@Z
// EA  : 0x82DFB778
// RVA : 0x00DFB778
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void __fastcall idFocusTracker::ClientUpdateFocus(
        idFocusTracker *this,
        idPresentablePlayer *owner,
        const idVec3 *viewPos,
        const idMat3 *viewAxis)
{
  __int64 v8; // r29
  char v9; // r25
  idClientGame *v10; // r27
  __int64 v11; // r11
  double v12; // fp1
  double x; // fp0
  double y; // fp13
  double v15; // fp31
  double z; // fp12
  double v17; // fp5
  double v18; // fp3
  double v19; // fp9
  double v20; // fp8
  double v21; // fp6
  double v22; // fp5
  idPresentable *PresentableByEntityNum; // r3
  double v24; // fp13
  idPresentable *v25; // r3
  int v26; // [sp+8h] [-158h]
  bool v27; // [sp+Fh] [-151h]
  const char *v28; // [sp+10h] [-150h]
  int v29; // [sp+14h] [-14Ch]
  int v30; // [sp+18h] [-148h]
  int v31; // [sp+1Ch] [-144h]
  int v32; // [sp+20h] [-140h]
  int v33; // [sp+24h] [-13Ch]
  int v34; // [sp+28h] [-138h]
  int v35; // [sp+2Ch] [-134h]
  int v36; // [sp+30h] [-130h]
  int v37; // [sp+34h] [-12Ch]
  int v38; // [sp+38h] [-128h]
  int v39; // [sp+3Ch] [-124h]
  int v40; // [sp+40h] [-120h]
  int v41; // [sp+44h] [-11Ch]
  int v42; // [sp+48h] [-118h]
  int v43; // [sp+4Ch] [-114h]
  int v44; // [sp+50h] [-110h]
  int v45; // [sp+58h] [-108h]
  int v46; // [sp+60h] [-100h]
  char v47; // [sp+70h] [-F0h] BYREF
  trace_t v48; // [sp+80h] [-E0h] BYREF

  LODWORD(v8) = 0;
  if ( player_updateFocus.valueInteger != 0 )
  {
    HIDWORD(v8) = &this->focusTrace.pointTrace;
    v9 = 0;
    v10 = clientGame;
    if ( (unsigned __int8)idClip::QueryIsValid(this: &clientGame->clip, clipQuery: &this->focusTrace.pointTrace) != 0 )
    {
      v11 = *(_QWORD *)HIDWORD(v8);
      *(_QWORD *)HIDWORD(v8) = v8;
      idCollisionModelManager::GetContentsResult(
        this: collisionModelManager,
        result: &v48,
        query: &v10->clip.collisionQueries[v11 & 0xFFF].query,
        peek: false);
      v9 = 1;
      v10 = clientGame;
    }
    if ( this->clearFocusTime <= idGameTimeManager::GetGameMs(this: &v10->gameTimeManager, type: GAMETIME_SCALED) )
    {
      this->useButtonOverride = 4;
      this->focusUsable.spawnId.value = 0x1FFF;
      this->focusEntity.spawnId.value = 0x1FFF;
      this->focusPresentable.spawnId = 0;
      this->cursorId = 0;
      this->clearFocusTime = 0;
      this->overFriendly = false;
      this->overTakedownTarget = TAKEDOWNMODE_UNAVAILABLE;
    }
    v12 = ((double (__fastcall *)(idFocusTracker *, idPresentablePlayer *, _DWORD))this->GetFocusDistance)(
            a1: this,
            a2: owner,
            a3: 0);
    x = viewPos->x;
    this->focusTrace.start.x = viewPos->x;
    y = viewPos->y;
    v15 = v12;
    this->focusTrace.start.y = viewPos->y;
    z = viewPos->z;
    this->focusTrace.start.z = viewPos->z;
    v17 = (float)(viewAxis->mat[0].z * (float)160.0);
    v18 = (float)(viewAxis->mat[0].x * (float)160.0);
    this->focusTrace.close.y = (float)y + (float)(viewAxis->mat[0].y * (float)160.0);
    this->focusTrace.close.z = (float)z + (float)v17;
    this->focusTrace.close.x = (float)x + (float)v18;
    v19 = this->focusTrace.start.y;
    v20 = this->focusTrace.start.z;
    v21 = (float)(viewAxis->mat[0].z * (float)v12);
    v22 = (float)(viewAxis->mat[0].y * (float)v12);
    this->focusTrace.end.x = this->focusTrace.start.x + (float)(viewAxis->mat[0].x * (float)v12);
    this->focusTrace.end.z = (float)v20 + (float)v21;
    this->focusTrace.end.y = (float)v19 + (float)v22;
    this->focusTrace.distance = 160.0;
    *(_QWORD *)HIDWORD(v8) = *(_QWORD *)&idClip::Translation(
                                           this: (idClip *)&v47,
                                           result: &clientGame->clip,
                                           a3: nullptr,
                                           start: &this->focusTrace.start,
                                           end: &this->focusTrace.end,
                                           clipModel: nullptr,
                                           startAxis: &mat3_identity,
                                           clipMask: 2209987,
                                           passEntityNumber: v26,
                                           moveClipModel: v27,
                                           userName: v28,
                                           a12: v29,
                                           a13: v30,
                                           a14: v31,
                                           a15: v32,
                                           a16: v33,
                                           a17: v34,
                                           a18: v35,
                                           a19: v36,
                                           a20: v37,
                                           a21: v38,
                                           a22: v39,
                                           a23: v40,
                                           a24: v41,
                                           a25: v42,
                                           a26: v43,
                                           a27: v44,
                                           a28: owner->entityNumber,
                                           a29: v45,
                                           a30: false,
                                           a31: v46,
                                           a32: (int)"w:\\tech5\\tungsten\\game\\player\\FocusTracker.cpp(695) : Translation")->world;
    if ( v9 != 0 )
    {
      if ( v48.c.entityNum != 0x1FFF && v48.c.entityNum >= 0 )
      {
        PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(this: clientGame, entityNum: v48.c.entityNum);
        if ( PresentableByEntityNum != nullptr )
          this->focusPresentable.spawnId = PresentableByEntityNum->spawnId;
        else
          this->focusPresentable.spawnId = 0;
        this->clearFocusTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
                             + 100;
      }
      v24 = (float)(v48.fraction * (float)v15);
      this->traceDistance = v48.fraction * (float)v15;
      this->focusTrace.distance = v24;
    }
    v25 = idPresentablePtr<idPresentableProjectile>::operator->(this: &this->focusPresentable);
    idFocusTracker::ClientUpdateCursor(this, owner, target: v25);
  }
  else
  {
    this->useButtonOverride = 4;
    this->focusUsable.spawnId.value = 0x1FFF;
    this->focusEntity.spawnId.value = 0x1FFF;
    this->focusPresentable.spawnId = 0;
    this->cursorId = 0;
    this->clearFocusTime = 0;
    this->overFriendly = false;
    this->overTakedownTarget = TAKEDOWNMODE_UNAVAILABLE;
  }
}


// ========================================================================
// ??1idFocusTracker@@UAA@XZ
// EA  : 0x82DFBA78
// RVA : 0x00DFBA78
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void __fastcall idFocusTracker::~idFocusTracker(idFocusTracker *this)
{
  this->__vftable = (idFocusTracker_vtbl *)&idFocusTracker::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->crosshairInfo.icons);
}


// ========================================================================
// ??0idFocusTracker@@QAA@XZ
// EA  : 0x82DFBB60
// RVA : 0x00DFBB60
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

idFocusTracker *__fastcall idFocusTracker::idFocusTracker(idFocusTracker *this)
{
  unsigned __int64 v2; // r30
  idFocusTrace *p_focusTrace; // r28
  char v4; // r5
  float z; // r7

  LODWORD(v2) = 0;
  this->__vftable = (idFocusTracker_vtbl *)&idFocusTracker::`vftable';
  this->traceDistance = 0.0;
  this->usercmd.pos[2] = 0.0;
  this->usercmd.buttons = 0;
  this->usercmd.pos[1] = 0.0;
  this->usercmd.buttons2 = 0;
  this->usercmd.pos[0] = 0.0;
  this->usercmd.forwardmove = 0;
  this->usercmd.rightmove = 0;
  this->usercmd.upmove = 0;
  this->usercmd.angles[2] = 0;
  HIDWORD(v2) = &this->usercmd;
  this->usercmd.angles[1] = 0;
  this->usercmd.angles[0] = 0;
  p_focusTrace = &this->focusTrace;
  this->usercmd.clientGameFrame = 0;
  this->usercmd.yaw = 0;
  this->usercmd.pitch = 0;
  this->usercmd.roll = 0;
  this->usercmd.predictionStateBits = 0;
  this->usercmd.vehicleThrottle = 0;
  this->usercmd.serverGameTime = 0;
  this->usercmd.fireCount = 0;
  this->usercmd.fireAngles[1] = 0;
  this->usercmd.fireAngles[0] = 0;
  this->usercmd.firePos[2] = 0;
  v4 = *((_BYTE *)&this->usercmd + 9);
  this->usercmd.firePos[1] = 0;
  this->usercmd.firePos[0] = 0;
  this->usercmd.speed = 0;
  *((_BYTE *)&this->usercmd + 9) = v4 & 0x3F;
  this->focusUsable.spawnId.value = 0x1FFF;
  this->focusEntity.spawnId.value = 0x1FFF;
  this->gatherPointEntity.spawnId.value = 0x1FFF;
  this->focusEntityOverride.spawnId.value = 0x1FFF;
  this->focusPresentable.spawnId = 0;
  this->cursorId = 0;
  this->clearFocusTime = 0;
  this->focusedEntityFlags = 0;
  this->traceModelIndex = -1;
  this->useButtonOverride = 4;
  this->focusTrace.start.x = 0.0;
  this->focusTrace.start.y = 0.0;
  this->focusTrace.start.z = 0.0;
  this->focusTrace.close.x = 0.0;
  this->focusTrace.close.y = 0.0;
  this->focusTrace.close.z = 0.0;
  this->focusTrace.end.x = 0.0;
  this->focusTrace.end.y = 0.0;
  this->focusTrace.end.z = 0.0;
  this->focusTrace.closeEnough = false;
  this->focusTrace.distance = 0.0;
  this->focusTrace.ent.spawnId.value = 0x1FFF;
  this->focusTrace.pointTrace.index = v2;
  this->focusTrace.gatherQuery.index = v2;
  this->focusTrace.focusTraces[0].entity.spawnId.value = 0x1FFF;
  this->focusTrace.focusTraces[0].pointTrace.index = v2;
  this->focusTrace.focusTraces[1].entity.spawnId.value = 0x1FFF;
  this->focusTrace.focusTraces[1].pointTrace.index = v2;
  this->focusTrace.focusTraces[2].entity.spawnId.value = 0x1FFF;
  this->focusTrace.focusTraces[2].pointTrace.index = v2;
  this->focusTrace.focusTraces[3].entity.spawnId.value = 0x1FFF;
  this->focusTrace.focusTraces[3].pointTrace.index = v2;
  this->focusTrace.numFocusTraces = 0;
  idCrosshairInfo::idCrosshairInfo(this: &this->crosshairInfo);
  this->usableState = USABLE_NOT_USABLE;
  this->overFriendly = false;
  this->overTakedownTarget = TAKEDOWNMODE_UNAVAILABLE;
  this->gatherPointEndPos.x = vec3_origin.x;
  this->gatherPointEndPos.y = vec3_origin.y;
  z = vec3_origin.z;
  this->validGatherPointResult = false;
  this->validPointResult = false;
  this->gatherPointEndPos.z = z;
  memset(Dst: &this->pointTraceResult, Val: 0, Size: sizeof(this->pointTraceResult));
  memset(Dst: (void *)HIDWORD(v2), Val: 0, Size: 0x3Cu);
  memset(Dst: (void *)p_focusTrace, Val: 0, Size: sizeof(idFocusTrace));
  return this;
}


// ========================================================================
// ?UpdateCursor@idFocusTracker@@MAA_NPAVidActor@@PAVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82DFBD80
// RVA : 0x00DFBD80
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

BOOL __fastcall idFocusTracker::UpdateCursor(
        idFocusTracker *this,
        idPlayer *owner,
        idUse *ent,
        const idFocusTrace *focusTrace)
{
  idPlayer *v9; // r3
  idPlayer *v10; // r29
  idPresentable *presentable; // r3
  idPresentablePlayer *v12; // r3
  idPresentable *v13; // r3
  int v14; // r3
  const idCrosshairInfo *CrosshairInfo; // r3
  idUse *v16; // r3

  this->usableState = USABLE_NOT_USABLE;
  if ( ent == nullptr )
    return false;
  v9 = idPlayer::CastTo(c: owner);
  v10 = v9;
  if ( v9 != nullptr )
  {
    presentable = v9->presentable;
    v12 = presentable != nullptr ? presentable->GetPlayerInterface_2(this: presentable) : nullptr;
    if ( !idPresentablePlayer::IsFullyZoomedOut(this: v12) )
      return false;
  }
  if ( !ent->IsEverUsable(this: ent, a2: owner)
    || focusTrace->distance > ((double (__fastcall *)(idUse *))ent->GetCrosshairIconDistance)(a1: ent) )
  {
    return false;
  }
  this->usableState = ent->GetUsableState(this: ent, a2: owner, a3: focusTrace);
  if ( (unsigned __int8)idVehicle::IsTypeOf(c: ent) != 0 && v10 != nullptr )
  {
    v13 = v10->presentable;
    v14 = v13 != nullptr ? (int)v13->GetPlayerInterface_2(this: v13) : 0;
    if ( *(_DWORD *)(v14 + 45280) != 0 )
      this->usableState = USABLE_NOT_USABLE;
  }
  CrosshairInfo = idCrosshairInfo::GetCrosshairInfo(ut: (const usableState_t)this->usableState);
  idCrosshairInfo::operator=(this: &this->crosshairInfo, __that: CrosshairInfo);
  if ( ent->ModifyCrosshairInfo(this: ent, a2: owner, a3: focusTrace, a4: this->usableState, a5: &this->crosshairInfo) )
  {
    if ( idEntityPtr<idEntity const>::operator->(this: &this->focusUsable) != ent )
    {
      idFocusTracker::SetFocusUsable(this, ent);
      v16 = idUse::CastTo(c: ent);
      if ( v16 != nullptr )
        this->useButtonOverride = v16->useButtonOverride;
    }
  }
  else
  {
    this->focusUsable.spawnId.value = 0x1FFF;
    this->useButtonOverride = 4;
  }
  return idEntityPtr<idEntity const>::operator->(this: &this->focusUsable) != nullptr;
}


// ========================================================================
// ?UpdateFocus@idFocusTracker@@QAAXPAVidActor@@ABVidVec3@@ABVidMat3@@PBVidEntity@@@Z
// EA  : 0x82DFBF70
// RVA : 0x00DFBF70
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void __fastcall idFocusTracker::UpdateFocus(
        idFocusTracker *this,
        idPlayer *owner,
        const idVec3 *viewPos,
        const idMat3 *viewAxis,
        const idEntity *passEntityOverride)
{
  unsigned __int64 v10; // r6
  const char *v11; // r7
  idPlayer *v12; // r16
  unsigned __int64 v13; // r21
  idClip *p_clip; // r29
  unsigned __int64 index; // r11
  __int64 v16; // r9
  char v17; // r11
  bool v18; // zf
  idClipQuery *p_pointTrace; // r27
  unsigned __int64 v20; // r11
  const idCrosshairInfo *CrosshairInfo; // r3
  double v22; // fp1
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v26; // fp9
  idVec3 *p_end; // r29
  double v28; // fp5
  double v29; // fp4
  double v30; // fp8
  double v31; // fp7
  double v32; // fp5
  double v33; // fp4
  int GatheredEntities; // r3
  double v35; // fp12
  double v36; // fp11
  double v37; // fp10
  idPhysics *Physics; // r3
  __int64 v39; // r4
  float v40; // r4
  double v41; // fp2
  double v42; // fp1
  float v43; // r6
  float v44; // r10
  float v45; // r11
  double v46; // fp31
  double v47; // fp30
  double v50; // fp28
  double v51; // fp28
  double v52; // fp28
  double v53; // fp10
  double v63; // fp15
  double v64; // fp16
  double v65; // fp28
  double v66; // fp17
  double v67; // fp14
  double v71; // fp18
  double v72; // fp28
  double v73; // fp19
  double v92; // fp28
  double v109; // fp12
  int v115; // r7
  double v125; // fp12
  unsigned __int64 *v162; // r3
  int entityNumber; // r8
  float v164; // r10
  float v165; // r9
  int numFocusTraces; // r9
  int v167; // r19
  double v168; // fp31
  double v169; // fp29
  float *p_distance; // r23
  int v171; // r10
  idEntity *v172; // r3
  idProp_ContinuallyUsed *v173; // r26
  _QWORD *v174; // r29
  idClip *v175; // r27
  __int128 v176; // r11
  int entityNum; // r27
  idClass *v178; // r3
  idEntity *v179; // r29
  idEntity *BindMaster; // r3
  idProp_ContinuallyUsed *v181; // r29
  int v182; // r29
  int GameMs; // r14
  idUse *v184; // r3
  double v185; // fp13
  double v186; // fp12
  double v187; // fp11
  int v188; // r3
  char v189; // r11
  char v190; // r29
  idAI2 *v191; // r3
  idEntity *v192; // r29
  idPhysics *v193; // r3
  int v194; // r3
  double v195; // fp13
  float v196; // r7
  double v197; // fp12
  float v198; // r6
  int v199; // r10
  double v200; // fp24
  double v201; // fp22
  idActor *v202; // r26
  idMat3 *v203; // r16
  int v204; // r18
  int *v205; // r19
  int v206; // r11
  idAI2 *v207; // r27
  char v208; // r26
  idAI2 *v209; // r29
  idPhysics *v210; // r3
  int v211; // r3
  float v212; // r7
  float v213; // r6
  int v215; // r3
  int v216; // r3
  float v217; // r5
  float v218; // r4
  const idAnimator_AF *(__fastcall *GetAF)(struct idAI2 *); // r11
  int v220; // r3
  float *v221; // r3
  double v222; // fp0
  double v223; // fp13
  double v224; // fp12
  double v225; // fp30
  double v226; // fp31
  double v227; // fp11
  double v228; // fp9
  double v229; // fp8
  double v230; // fp7
  double v231; // fp6
  double v232; // fp5
  idPhysics *v233; // r3
  idPhysics *v234; // r3
  int v235; // r3
  idPhysics *v236; // r3
  int v237; // r3
  float v238; // r8
  float v239; // r7
  idPhysics *v240; // r3
  int v241; // r3
  float v242; // r5
  float v243; // r29
  double v244; // fp0
  double v245; // fp31
  double v246; // fp30
  double v247; // fp29
  double v248; // fp1
  double v249; // fp28
  double v250; // fp27
  double v251; // fp26
  double v252; // fp0
  int v253; // r10
  double v254; // fp0
  double v255; // fp13
  double v256; // fp12
  char *v257; // r29
  float v258; // r11
  double v259; // fp9
  double v260; // fp8
  int v261; // r4
  int v262; // r11
  int v263; // r9
  idEntity *v264; // r29
  idEntity *v265; // r3
  idGameLocal *v266; // r11
  int value; // r9
  idEntity *v268; // r3
  idAI2 *v269; // r3
  idAI2 *v270; // r3
  int v271; // r9
  idEntity *v272; // r3
  idAnimatedSimple *v273; // r3
  idAnimatedSimple *v274; // r3
  int v275; // r9
  idEntity *v276; // r3
  int v277; // r9
  idGameLocal *v278; // r11
  idEntity *v279; // r3
  idEntity *v280; // r3
  int v281; // r9
  idEntity *v282; // r3
  idEntity *v283; // r29
  idPresentable *presentable; // r11
  int v285; // r9
  idEntity *v286; // r3
  idPLog *v287; // r29
  idPLog::logEntry_t *v288; // r30
  int v289; // r3
  __int64 v290; // r11
  __int64 v291; // r9
  int v292; // r9
  idGameLocal *v293; // r11
  idEntity *v294; // r3
  int v295; // r9
  idEntity *v296; // r3
  idEntity *v297; // r3
  idPhysics *v298; // r3
  const idBounds *v299; // r3
  int v300; // r9
  idEntity *v301; // r3
  idEntity *v302; // r5
  int v303; // r9
  idEntity *v304; // r3
  idProp_Noticable *v305; // r3
  idProp_Noticable *v306; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v308; // r30
  int v309; // r3
  __int64 totalTicks; // r11
  __int64 v311; // r9
  int v312; // [sp+8h] [-3E8h]
  int v313; // [sp+8h] [-3E8h]
  bool v314; // [sp+Fh] [-3E1h]
  bool v315; // [sp+Fh] [-3E1h]
  const char *v316; // [sp+10h] [-3E0h]
  const char *v317; // [sp+10h] [-3E0h]
  int v318; // [sp+14h] [-3DCh]
  int v319; // [sp+14h] [-3DCh]
  int v320; // [sp+18h] [-3D8h]
  int v321; // [sp+18h] [-3D8h]
  int v322; // [sp+1Ch] [-3D4h]
  int v323; // [sp+1Ch] [-3D4h]
  int v324; // [sp+20h] [-3D0h]
  int v325; // [sp+20h] [-3D0h]
  int v326; // [sp+24h] [-3CCh]
  int v327; // [sp+24h] [-3CCh]
  int v328; // [sp+28h] [-3C8h]
  int v329; // [sp+28h] [-3C8h]
  int v330; // [sp+2Ch] [-3C4h]
  int v331; // [sp+2Ch] [-3C4h]
  int v332; // [sp+30h] [-3C0h]
  int v333; // [sp+30h] [-3C0h]
  int v334; // [sp+34h] [-3BCh]
  int v335; // [sp+34h] [-3BCh]
  int v336; // [sp+38h] [-3B8h]
  int v337; // [sp+38h] [-3B8h]
  int v338; // [sp+3Ch] [-3B4h]
  int v339; // [sp+3Ch] [-3B4h]
  int v340; // [sp+40h] [-3B0h]
  int v341; // [sp+40h] [-3B0h]
  int v342; // [sp+44h] [-3ACh]
  int v343; // [sp+44h] [-3ACh]
  int v344; // [sp+48h] [-3A8h]
  int v345; // [sp+48h] [-3A8h]
  int v346; // [sp+4Ch] [-3A4h]
  int v347; // [sp+4Ch] [-3A4h]
  int v348; // [sp+50h] [-3A0h]
  int v349; // [sp+50h] [-3A0h]
  int v350; // [sp+54h] [-39Ch]
  int v351; // [sp+58h] [-398h]
  int v352; // [sp+58h] [-398h]
  int v353; // [sp+60h] [-390h]
  int v354; // [sp+60h] [-390h]
  int v355; // [sp+64h] [-38Ch]
  float v356; // [sp+70h] [-380h]
  idVec3 v357; // [sp+78h] [-378h] BYREF
  char v358; // [sp+84h] [-36Ch]
  unsigned __int8 v359; // [sp+85h] [-36Bh]
  float v360; // [sp+88h] [-368h]
  float v361; // [sp+8Ch] [-364h]
  float v362; // [sp+90h] [-360h] BYREF
  float v363; // [sp+94h] [-35Ch]
  float v364; // [sp+98h] [-358h]
  __int64 v365; // [sp+A0h] [-350h] BYREF
  idVec3 v366; // [sp+A8h] [-348h] BYREF
  float v367; // [sp+B4h] [-33Ch]
  float v368; // [sp+B8h] [-338h] BYREF
  idVec3 v369; // [sp+C0h] [-330h] BYREF
  idBounds v370; // [sp+D0h] [-320h] BYREF
  idPLogScope v371; // [sp+E8h] [-308h] BYREF
  int v372; // [sp+F0h] [-300h]
  int v373; // [sp+F4h] [-2FCh]
  idVec3 v374; // [sp+F8h] [-2F8h] BYREF
  idVec3 v375; // [sp+108h] [-2E8h] BYREF
  idVec3 v376; // [sp+118h] [-2D8h] BYREF
  idVec3 v377; // [sp+128h] [-2C8h] BYREF
  idBounds v378; // [sp+140h] [-2B0h] BYREF
  float v379; // [sp+158h] [-298h]
  float v380; // [sp+15Ch] [-294h]
  float v381; // [sp+160h] [-290h]
  float v382; // [sp+168h] [-288h] BYREF
  float v383; // [sp+170h] [-280h]
  idVec3 v384; // [sp+178h] [-278h] BYREF
  float v385[6]; // [sp+188h] [-268h] BYREF
  float v386; // [sp+1A0h] [-250h]
  float v387[6]; // [sp+1A8h] [-248h] BYREF
  idSphere v388; // [sp+1C0h] [-230h] BYREF
  float v389[4]; // [sp+1D0h] [-220h] BYREF
  float v390[4]; // [sp+1E0h] [-210h] BYREF
  float v391[4]; // [sp+1F0h] [-200h] BYREF
  trace_t v392; // [sp+200h] [-1F0h] BYREF
  int v393[54]; // [sp+280h] [-170h] BYREF

  RD_EventBegin(name: "idFocusTracker::UpdateFocus");
  LODWORD(v10) = "idFocusTracker::UpdateFocus";
  HIDWORD(v10) = 2;
  idPLogScope::idPLogScope(this: &v371, pl: &::pLog, gMask: v10, label: v11);
  v12 = idPlayer::CastTo(c: owner);
  HIDWORD(v13) = passEntityOverride;
  if ( passEntityOverride == nullptr )
    HIDWORD(v13) = owner;
  v373 = HIDWORD(v13);
  LODWORD(v13) = 0;
  this->validGatherPointResult = false;
  this->validPointResult = false;
  p_clip = &clientGame->clip;
  index = this->focusTrace.gatherQuery.index;
  v16 = *(_QWORD *)((char *)&clientGame->clip.world + HIDWORD(index));
  v359 = 0;
  if ( (unsigned int)index < (unsigned int)v16
    || (v18 = (unsigned int)index <= LODWORD(clientGame->clip.gatherQueryLastSubmittedIndex), v17 = 1, !v18) )
  {
    v17 = 0;
  }
  if ( v17 != 0 )
    v359 = 1;
  p_pointTrace = &this->focusTrace.pointTrace;
  if ( (unsigned __int8)idClip::QueryIsValid(this: p_clip, clipQuery: &this->focusTrace.pointTrace) != 0 )
  {
    v20 = p_pointTrace->index;
    p_pointTrace->index = v13;
    idCollisionModelManager::GetContentsResult(
      this: collisionModelManager,
      result: &this->pointTraceResult,
      query: &p_clip->collisionQueries[v20 & 0xFFF].query,
      peek: false);
    this->validPointResult = true;
  }
  this->useButtonOverride = 4;
  this->focusUsable.spawnId.value = 0x1FFF;
  this->focusEntity.spawnId.value = 0x1FFF;
  this->focusPresentable.spawnId = 0;
  this->overTakedownTarget = TAKEDOWNMODE_UNAVAILABLE;
  this->cursorId = 0;
  this->clearFocusTime = 0;
  this->overFriendly = false;
  if ( player_updateFocus.valueInteger != 0 )
  {
    this->overFriendly = false;
    CrosshairInfo = idCrosshairInfo::GetCrosshairInfo(ut: USABLE_NOT_USABLE);
    idCrosshairInfo::operator=(this: &this->crosshairInfo, __that: CrosshairInfo);
    this->overTakedownTarget = TAKEDOWNMODE_UNAVAILABLE;
    v22 = ((double (__fastcall *)(idFocusTracker *, idPlayer *, _DWORD))this->GetFocusDistance_2)(
            a1: this,
            a2: owner,
            a3: 0);
    this->focusTrace.start.x = viewPos->x;
    y = viewPos->y;
    this->focusTrace.start.y = viewPos->y;
    z = viewPos->z;
    this->focusTrace.start.z = viewPos->z;
    x = viewAxis->mat[0].x;
    v26 = this->focusTrace.start.x;
    p_end = &this->focusTrace.end;
    v28 = (float)(viewAxis->mat[0].y * (float)160.0);
    v29 = (float)(viewAxis->mat[0].z * (float)160.0);
    v383 = v22;
    v368 = 160.0;
    this->focusTrace.close.y = (float)v28 + (float)y;
    this->focusTrace.close.z = (float)v29 + (float)z;
    this->focusTrace.close.x = (float)((float)x * (float)160.0) + (float)v26;
    v30 = this->focusTrace.start.y;
    v31 = this->focusTrace.start.z;
    v32 = (float)(viewAxis->mat[0].y * (float)v22);
    v33 = (float)((float)v22 * viewAxis->mat[0].z);
    this->focusTrace.end.x = (float)(viewAxis->mat[0].x * (float)v22) + this->focusTrace.start.x;
    this->focusTrace.end.y = (float)v32 + (float)v30;
    this->focusTrace.end.z = (float)v33 + (float)v31;
    this->focusTrace.distance = 160.0;
    trace_t::operator=(this: &this->focusTrace.tr, __that: &this->pointTraceResult);
    GatheredEntities = idClip::GetGatheredEntities(
                         this: &clientGame->clip,
                         query: &this->focusTrace.gatherQuery,
                         entityList: v393,
                         maxCount: 16);
    v35 = this->focusTrace.start.x;
    v36 = this->focusTrace.start.y;
    v372 = GatheredEntities;
    v37 = this->focusTrace.start.z;
    v370.b[0].x = v35;
    v370.b[0].y = v36;
    v370.b[1].x = v35;
    v370.b[0].z = v37;
    v370.b[1].y = v36;
    v370.b[1].z = v37;
    Physics = idEntity::GetPhysics(this: owner);
    HIDWORD(v39) = Physics->GetOrigin(this: Physics, a2: 0);
    v40 = viewAxis->mat[0].y;
    v41 = viewAxis->mat[1].x;
    v42 = viewAxis->mat[1].y;
    v362 = viewAxis->mat[0].x;
    v363 = v40;
    v43 = *(float *)(HIDWORD(v39) + 8);
    v44 = *(float *)(HIDWORD(v39) + 4);
    LODWORD(v39) = idFocusTracker::FOCUS_DEFAULT_PASSIVE_SELOFFSET;
    v382 = 0.0;
    v45 = *(float *)HIDWORD(v39);
    v46 = viewAxis->mat[1].z;
    v369.z = v43;
    v365 = v39;
    v369.x = v45;
    v369.y = v44;
    v47 = (float)((float)v41 * (float)40.0);
    v364 = viewAxis->mat[0].z;
    _FP26 = (float)((float)((float)(v363 * v363) + (float)(v362 * v362)) - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f28, f26, f28, f12 }
    v50 = __frsqrte(_FP28);
    v51 = (float)((float)-(float)((float)((float)((float)v50
                                                * (float)((float)((float)(v363 * v363) + (float)(v362 * v362))
                                                        * (float)0.5))
                                        * (float)v50)
                                - (float)1.5)
                * (float)v50);
    v52 = (float)((float)-(float)((float)((float)((float)v51
                                                * (float)((float)((float)(v363 * v363) + (float)(v362 * v362))
                                                        * (float)0.5))
                                        * (float)v51)
                                - (float)1.5)
                * (float)v51);
    v53 = (float)(v45
                - (float)((float)v39
                        * (float)((float)((float)-(float)((float)((float)((float)v52
                                                                        * (float)((float)((float)(v363 * v363)
                                                                                        + (float)(v362 * v362))
                                                                                * (float)0.5))
                                                                * (float)v52)
                                                        - (float)1.5)
                                        * (float)v52)
                                * v362)));
    _FP0 = (float)(v370.b[0].z
                 - (float)(v43
                         - (float)((float)v39
                                 * (float)((float)((float)-(float)((float)((float)((float)v52
                                                                                 * (float)((float)((float)(v363 * v363)
                                                                                                 + (float)(v362 * v362))
                                                                                         * (float)0.5))
                                                                         * (float)v52)
                                                                 - (float)1.5)
                                                 * (float)v52)
                                         * (float)0.0))));
    __asm { fsel      f4, f0, f5, f4 }
    _FP21 = (float)((float)(v44
                          - (float)((float)v39
                                  * (float)((float)((float)-(float)((float)((float)((float)v52
                                                                                  * (float)((float)((float)(v363 * v363)
                                                                                                  + (float)(v362 * v362))
                                                                                          * (float)0.5))
                                                                          * (float)v52)
                                                                  - (float)1.5)
                                                  * (float)v52)
                                          * v363)))
                  - v370.b[1].y);
    v360 = v41;
    _FP20 = (float)((float)(v43
                          - (float)((float)v39
                                  * (float)((float)((float)-(float)((float)((float)((float)v52
                                                                                  * (float)((float)((float)(v363 * v363)
                                                                                                  + (float)(v362 * v362))
                                                                                          * (float)0.5))
                                                                          * (float)v52)
                                                                  - (float)1.5)
                                                  * (float)v52)
                                          * (float)0.0)))
                  - v370.b[1].z);
    _FP27 = (float)(v370.b[0].x
                  - (float)(v45
                          - (float)((float)v39
                                  * (float)((float)((float)-(float)((float)((float)((float)v52
                                                                                  * (float)((float)((float)(v363 * v363)
                                                                                                  + (float)(v362 * v362))
                                                                                          * (float)0.5))
                                                                          * (float)v52)
                                                                  - (float)1.5)
                                                  * (float)v52)
                                          * v362))));
    _FP28 = (float)(v370.b[0].y
                  - (float)(v44
                          - (float)((float)v39
                                  * (float)((float)((float)-(float)((float)((float)((float)v52
                                                                                  * (float)((float)((float)(v363 * v363)
                                                                                                  + (float)(v362 * v362))
                                                                                          * (float)0.5))
                                                                          * (float)v52)
                                                                  - (float)1.5)
                                                  * (float)v52)
                                          * v363))));
    __asm { fsel      f3, f28, f6, f3 }
    _FP25 = (float)((float)v53 - v370.b[1].x);
    v63 = viewAxis->mat[2].z;
    v64 = (float)(v45 - (float)((float)v41 * (float)40.0));
    _FP2 = (float)((float)_FP4 - (float)(v43 - (float)((float)v46 * (float)40.0)));
    v65 = viewAxis->mat[2].y;
    v66 = viewAxis->mat[2].x;
    v67 = this->focusTrace.close.x;
    __asm { fsel      f6, f21, f6, f12 }
    __asm { fsel      f11, f20, f5, f11 }
    v367 = 20.0;
    __asm { fsel      f27, f27, f10, f23 }
    v71 = this->focusTrace.close.z;
    v72 = (float)((float)v65 * (float)20.0);
    v73 = this->focusTrace.close.y;
    _FP13 = (float)((float)_FP3 - (float)(v44 - (float)((float)v42 * (float)40.0)));
    __asm { fsel      f10, f25, f10, f22 }
    __asm { fsel      f4, f2, f24, f4 }
    _FP2 = (float)((float)(v44 - (float)((float)v42 * (float)40.0)) - (float)_FP6);
    _FP29 = (float)((float)(v43 - (float)((float)v46 * (float)40.0)) - (float)_FP11);
    _FP23 = (float)((float)_FP27 - (float)v64);
    __asm { fsel      f13, f13, f26, f3 }
    _FP22 = (float)((float)v64 - (float)_FP10);
    _FP20 = (float)((float)_FP4 - (float)((float)((float)v46 * (float)40.0) + v43));
    __asm
    {
      fsel      f2, f2, f26, f6
      fsel      f11, f29, f24, f11
      fsel      f6, f23, f16, f27
    }
    _FP0 = (float)((float)_FP13 - (float)((float)((float)v42 * (float)40.0) + v44));
    __asm
    {
      fsel      f10, f22, f16, f10
      fsel      f4, f20, f9, f4
    }
    _FP26 = (float)((float)((float)((float)v42 * (float)40.0) + v44) - (float)_FP2);
    _FP24 = (float)((float)((float)((float)v46 * (float)40.0) + v43) - (float)_FP11);
    _FP23 = (float)((float)_FP6 - (float)((float)v47 + v45));
    __asm { fsel      f0, f0, f8, f13 }
    _FP22 = (float)((float)((float)v47 + v45) - (float)_FP10);
    _FP13 = (float)((float)_FP4 - this->focusTrace.close.z);
    __asm
    {
      fsel      f8, f26, f8, f2
      fsel      f2, f24, f9, f11
      fsel      f11, f23, f7, f6
    }
    _FP9 = (float)((float)_FP0 - this->focusTrace.close.y);
    __asm
    {
      fsel      f10, f22, f7, f10
      fsel      f7, f13, f18, f4
    }
    _FP6 = (float)(this->focusTrace.close.y - (float)_FP8);
    _FP4 = (float)(this->focusTrace.close.z - (float)_FP2);
    __asm { fsel      f13, f9, f19, f0 }
    _FP9 = (float)((float)_FP11 - (float)v67);
    __asm
    {
      fsel      f8, f6, f19, f8
      fsel      f6, f4, f18, f2
    }
    _FP5 = (float)((float)v67 - (float)_FP10);
    v109 = (float)((float)v46 * (float)20.0);
    _FP4 = (float)((float)_FP13 - (float)((float)v72 + this->focusTrace.close.y));
    __asm { fsel      f11, f9, f14, f11 }
    _FP2 = (float)((float)_FP7 - (float)((float)((float)v63 * (float)20.0) + this->focusTrace.close.z));
    _FP9 = (float)((float)((float)v72 + this->focusTrace.close.y) - (float)_FP8);
    v92 = (float)(this->focusTrace.close.y - (float)v72);
    v361 = v42;
    v356 = v361 * (float)20.0;
    _FP26 = (float)((float)((float)((float)v63 * (float)20.0) + (float)v71) - (float)_FP6);
    v115 = *(_DWORD *)(HIDWORD(v13) + 492);
    __asm { fsel      f5, f5, f14, f10 }
    __asm { fsel      f4, f4, f3, f13 }
    _FP30 = (float)((float)_FP11 - (float)((float)((float)v66 * (float)20.0) + (float)v67));
    __asm
    {
      fsel      f2, f2, f21, f7
      fsel      f9, f9, f3, f8
    }
    __asm { fsel      f8, f26, f21, f6 }
    _FP6 = (float)((float)((float)((float)v66 * (float)20.0) + (float)v67) - (float)_FP5);
    _FP3 = (float)((float)_FP4 - (float)v92);
    __asm { fsel      f11, f30, f29, f11 }
    _FP26 = (float)((float)_FP2 - (float)((float)v71 - (float)((float)v63 * (float)20.0)));
    _FP31 = (float)((float)v92 - (float)_FP9);
    _FP30 = (float)((float)((float)v71 - (float)((float)v63 * (float)20.0)) - (float)_FP8);
    __asm
    {
      fsel      f6, f6, f29, f5
      fsel      f5, f3, f28, f4
    }
    _FP3 = (float)((float)_FP11 - (float)((float)v67 - (float)((float)v66 * (float)20.0)));
    __asm
    {
      fsel      f4, f26, f25, f2
      fsel      f2, f31, f28, f9
      fsel      f9, f30, f25, f8
    }
    _FP8 = (float)((float)((float)v67 - (float)((float)v66 * (float)20.0)) - (float)_FP6);
    _FP31 = (float)((float)_FP5 - (float)((float)v73 - v356));
    __asm { fsel      f3, f3, f27, f11 }
    _FP30 = (float)((float)_FP4 - (float)((float)v71 - (float)v109));
    _FP11 = (float)((float)((float)v73 - v356) - (float)_FP2);
    _FP29 = (float)((float)((float)v71 - (float)v109) - (float)_FP9);
    v125 = (float)((float)v71 + (float)v109);
    __asm
    {
      fsel      f8, f8, f27, f6
      fsel      f6, f31, f10, f5
      fsel      f5, f30, f13, f4
      fsel      f2, f11, f10, f2
    }
    _FP4 = (float)((float)_FP3 - (float)((float)v67 - (float)(v360 * (float)20.0)));
    __asm { fsel      f13, f29, f13, f9 }
    _FP11 = (float)((float)((float)v67 - (float)(v360 * (float)20.0)) - (float)_FP8);
    _FP10 = (float)((float)_FP6 - (float)((float)v73 + v356));
    _FP9 = (float)((float)_FP5 - (float)v125);
    __asm { fsel      f4, f4, f7, f3 }
    _FP3 = (float)((float)((float)v73 + v356) - (float)_FP2);
    _FP31 = (float)((float)v125 - (float)_FP13);
    __asm
    {
      fsel      f11, f11, f7, f8
      fsel      f10, f10, f1, f6
    }
    v370.b[0].y = _FP10;
    __asm { fsel      f9, f9, f12, f5 }
    v370.b[0].z = _FP9;
    _FP8 = (float)((float)_FP4 - (float)((float)v67 + (float)(v360 * (float)20.0)));
    __asm { fsel      f7, f3, f1, f2 }
    v370.b[1].y = _FP7;
    __asm { fsel      f6, f31, f12, f13 }
    v370.b[1].z = _FP6;
    _FP5 = (float)((float)((float)v67 + (float)(v360 * (float)20.0)) - (float)_FP11);
    __asm { fsel      f4, f8, f0, f4 }
    v370.b[0].x = _FP4;
    __asm { fsel      f3, f5, f0, f11 }
    v370.b[1].x = _FP3;
    v162 = (unsigned __int64 *)idClip::GatherTouchingBounds(
                                 this: (idClip *)&v365,
                                 result: (idGatherQuery *)&clientGame->clip,
                                 bounds: &v370,
                                 clipMask: 2209987,
                                 passEntityNumber: v115,
                                 userName: "w:\\tech5\\tungsten\\game\\player\\FocusTracker.cpp(252) : Translation");
    v355 = *(_DWORD *)v162 + 26440;
    this->focusTrace.gatherQuery.index = *v162;
    v350 = *(_DWORD *)(HIDWORD(v13) + 492);
    v360 = COERCE_FLOAT(&mat3_identity);
    p_pointTrace->index = *(unsigned __int64 *)&idClip::Translation(
                                                  this: (idClip *)&v365,
                                                  result: &clientGame->clip,
                                                  a3: nullptr,
                                                  start: &this->focusTrace.start,
                                                  end: &this->focusTrace.end,
                                                  clipModel: nullptr,
                                                  startAxis: &mat3_identity,
                                                  clipMask: 2209987,
                                                  passEntityNumber: v312,
                                                  moveClipModel: v314,
                                                  userName: v316,
                                                  a12: v318,
                                                  a13: v320,
                                                  a14: v322,
                                                  a15: v324,
                                                  a16: v326,
                                                  a17: v328,
                                                  a18: v330,
                                                  a19: v332,
                                                  a20: v334,
                                                  a21: v336,
                                                  a22: v338,
                                                  a23: v340,
                                                  a24: v342,
                                                  a25: v344,
                                                  a26: v346,
                                                  a27: v348,
                                                  a28: v350,
                                                  a29: v351,
                                                  a30: false,
                                                  a31: v353,
                                                  a32: v355)->world;
    entityNumber = owner->entityNumber;
    v361 = COERCE_FLOAT(&player_focusDebug);
    v367 = COERCE_FLOAT(&idColor::colorRed);
    if ( player_focusDebug.valueInteger == entityNumber )
    {
      if ( this->validPointResult )
        p_end = &this->pointTraceResult.c.point;
      v164 = p_end->x;
      v165 = p_end->z;
      v363 = p_end->y;
      v362 = v164;
      v364 = v165;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)&this->focusTrace,
        a4: (const idVec3 *)&v362,
        a5: 100,
        a6: true);
      clientGame->renderWorld->DebugBounds(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorOrange,
        a3: &v370,
        a4: &vec3_origin,
        a5: 0,
        a6: true);
    }
    numFocusTraces = this->focusTrace.numFocusTraces;
    v358 = 0;
    v167 = 0;
    v168 = 1.0e30;
    v169 = -1.0;
    if ( numFocusTraces > 0 )
    {
      p_distance = &this->focusTrace.focusTraces[0].distance;
      do
      {
        v171 = *((_DWORD *)p_distance - 1);
        if ( gameLocal->spawnIds.ptr[v171 & 0x1FFF] == v171 >> 13 )
        {
          v172 = gameLocal->entities.ptr[v171 & 0x1FFF];
          if ( v172 != nullptr )
          {
            v173 = (idProp_ContinuallyUsed *)idEntity::CastTo(c: v172);
            if ( v173 != nullptr )
            {
              v174 = p_distance + 3;
              v175 = &clientGame->clip;
              if ( (unsigned __int8)idClip::QueryIsValid(
                                      this: &clientGame->clip,
                                      clipQuery: (const idClipQuery *)(p_distance + 3)) != 0 )
              {
                LODWORD(v176) = 0;
                *(_QWORD *)((char *)&v176 + 4) = *v174;
                HIDWORD(v365) = v175;
                *v174 = v176;
                idCollisionModelManager::GetContentsResult(
                  this: collisionModelManager,
                  result: &v392,
                  query: &v175->collisionQueries[WORD5(v176) & 0xFFF].query,
                  peek: false);
                entityNum = v392.c.entityNum;
                if ( v392.c.entityNum != v173->entityNumber )
                {
                  v178 = (idClass *)((int (__fastcall *)(idGameLocal *))gameLocal->GetEntity)(a1: gameLocal);
                  v179 = (idEntity *)v178;
                  if ( v178 != nullptr && (unsigned __int8)idExplodable::IsTypeOf(c: v178) != 0 )
                  {
                    BindMaster = idEntity::GetBindMaster(this: v179);
                    if ( BindMaster != nullptr )
                      entityNum = BindMaster->entityNumber;
                  }
                }
                v181 = idProp_ContinuallyUsed::CastTo(c: v173);
                if ( v181 == nullptr
                  || v12 == nullptr
                  || idPlayer::GetLastDamagedTime(this: v12) == 0
                  || (LODWORD(v365) = (int)(float)(v181->waitTimeIfDamaged * 1000.0), v182 = v365, (int)v365 <= 0)
                  || (GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED))
                   - idPlayer::GetLastDamagedTime(this: v12) >= v182 )
                {
                  v184 = idUse::CastTo(c: (idUse *)v173);
                  if ( (v392.fraction >= 1.0
                     || entityNum == v173->entityNumber
                     || v184 != nullptr && (*((_BYTE *)v184 + 844) & 0x40) != 0)
                    && ((v185 = __fabs((float)(*p_distance - (float)v168))) > 75.0 && *p_distance < v168
                     || v185 < 75.0 && p_distance[1] > v169) )
                  {
                    v169 = p_distance[1];
                    v168 = *p_distance;
                    v186 = v392.endpos.y;
                    HIDWORD(v365) = &this->gatherPointEndPos;
                    v187 = v392.endpos.z;
                    LODWORD(v13) = v173;
                    this->gatherPointEndPos.x = v392.endpos.x;
                    this->gatherPointEndPos.y = v186;
                    this->gatherPointEndPos.z = v187;
                  }
                }
              }
            }
          }
        }
        ++v167;
        p_distance += 6;
      }
      while ( v167 < this->focusTrace.numFocusTraces );
      if ( (_DWORD)v13 != 0 )
      {
        HIDWORD(v365) = &this->gatherPointEntity;
        this->validGatherPointResult = true;
        HIDWORD(v365) = *(_DWORD *)(v13 + 492);
        this->gatherPointEntity.spawnId.value = (gameLocal->spawnIds.ptr[HIDWORD(v365)] << 13) | HIDWORD(v365);
        idFocusTracker::SetFocusEntity(this, ent: (idEntity *)v13);
        this->focusTrace.distance = v168;
        if ( v12->GetEquippedWeapon(this: v12) == nullptr
          || (v188 = (int)v12->GetEquippedWeapon(this: v12), v189 = 1, *(_DWORD *)(*(_DWORD *)(v188 + 12) + 560) != 0) )
        {
          v189 = 0;
        }
        v190 = v189;
        if ( (unsigned __int8)idAI2::IsTypeOf(c: (idClass *)v13) != 0 && v190 != 0 )
        {
          v191 = idAI2::CastTo(c: (idAI2 *)v13);
          v192 = v191;
          if ( v191 != nullptr )
          {
            this->overTakedownTarget = idAI2::CanBeTakenDown(this: v191, activator: owner);
            v193 = idEntity::GetPhysics(this: v192);
            v194 = (int)v193->GetOrigin(this: v193, a2: 0);
            v195 = viewPos->y;
            v196 = *(float *)v194;
            v197 = viewPos->x;
            v198 = *(float *)(v194 + 8);
            v363 = *(float *)(v194 + 4);
            v362 = v196;
            v364 = v198;
            if ( (float)((float)((float)((float)v197 - v196) * (float)((float)v197 - v196))
                       + (float)((float)((float)v195 - v363) * (float)((float)v195 - v363))) > 6400.0 )
              this->overTakedownTarget = TAKEDOWNMODE_UNAVAILABLE;
          }
        }
        else if ( (unsigned __int8)idProp_Moveable::IsTypeOf(c: (idClass *)v13) == 0 )
        {
          v358 = 1;
        }
      }
    }
    v199 = v359;
    this->focusTrace.numFocusTraces = 0;
    if ( v199 != 0 && v372 > 0 )
    {
      v200 = v382;
      v201 = v368;
      v202 = owner;
      v203 = (idMat3 *)LODWORD(v360);
      v204 = 0;
      v205 = v393;
      do
      {
        if ( this->focusTrace.numFocusTraces == 4 )
          break;
        v206 = *v205 + 21563;
        v207 = *((idAI2 **)&gameLocal->__vftable + v206);
        if ( v207 != nullptr
          && (unsigned __int8)idExplodable::IsTypeOf(c: *((idClass **)&gameLocal->__vftable + v206)) == 0
          && v207->IsCurrentlyUsable(this: v207, a2: v202) )
        {
          v208 = 0;
          v209 = idAI2::CastTo(c: v207);
          v210 = idEntity::GetPhysics(this: v207);
          v211 = (int)v210->GetOrigin(this: v210, a2: 0);
          v212 = *(float *)(v211 + 4);
          v213 = *(float *)(v211 + 8);
          v357.x = *(float *)v211;
          v357.y = v212;
          v357.z = v213;
          if ( (unsigned __int8)idProp_Moveable::IsTypeOf(c: v207) != 0 || v209 != nullptr && v209->IsDead(this: v209) )
          {
            if ( v209 != nullptr && v209->GetAF(this: v209) != nullptr && v209->GetAF(this: v209)->isLoaded )
            {
              v215 = (int)v209->GetAF(this: v209);
              v216 = (*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v215 + 288) + 68))(a1: v215 + 288, a2: 0);
              v217 = *(float *)(v216 + 28);
              v218 = *(float *)(v216 + 32);
              GetAF = v209->GetAF;
              v379 = *(float *)(v216 + 24);
              v380 = v217;
              v381 = v218;
              v220 = (int)GetAF(this: v209);
              v221 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v220 + 288) + 64))(a1: v220 + 288, a2: 0);
              v222 = *v221;
              v357.x = *v221;
              v223 = v221[1];
              v357.y = v221[1];
              v224 = v221[2];
              v357.z = v221[2];
              v375.x = (float)v222 - (float)(v379 * 45.0);
              v375.y = (float)v223 - (float)(v380 * 45.0);
              v374.y = (float)(v380 * (float)90.0) + v375.y;
              v375.z = (float)v224 - (float)(v381 * 45.0);
              v374.x = (float)(v379 * (float)90.0) + v375.x;
              v374.z = (float)(v381 * (float)90.0) + v375.z;
              idGeometry::ClosestPointOnLineSegment(point: viewPos, start: &v375, end: &v374, closest: &v357);
              v225 = (float)(viewPos->y - v357.y);
              v226 = (float)(viewPos->x - v357.x);
              if ( *(_DWORD *)(LODWORD(v361) + 32) == owner->entityNumber )
              {
                v390[1] = v357.y;
                v390[2] = v357.z;
                v390[0] = v357.x;
                v390[3] = 3.0;
                clientGame->renderWorld->DebugSphere(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)LODWORD(v367),
                  a3: (const idSphere *)v390,
                  a4: 12,
                  a5: 0,
                  a6: false);
                clientGame->renderWorld->DebugLine(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorPurple,
                  a3: &v375,
                  a4: &v374,
                  a5: 0,
                  a6: false);
                v391[3] = 1.0;
                v391[0] = v375.x;
                v391[2] = v375.z;
                v391[1] = v375.y;
                clientGame->renderWorld->DebugSphere(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorPurple,
                  a3: (const idSphere *)v391,
                  a4: 12,
                  a5: 0,
                  a6: false);
                v389[2] = v374.z;
                v389[3] = 1.0;
                v389[1] = v374.y;
                v389[0] = v374.x;
                clientGame->renderWorld->DebugSphere(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)&idColor::colorPurple,
                  a3: (const idSphere *)v389,
                  a4: 12,
                  a5: 0,
                  a6: false);
              }
            }
            else
            {
              v225 = (float)(viewPos->y - v357.y);
              v226 = (float)(viewPos->x - v357.x);
            }
            if ( (float)((float)((float)v226 * (float)v226) + (float)((float)v225 * (float)v225)) <= 1600.0 )
              v208 = 1;
          }
          if ( v208 == 0 )
          {
            v227 = (float)(viewAxis->mat[0].z * (float)v201);
            v228 = (float)(viewAxis->mat[0].y * (float)v201);
            v229 = (float)(viewAxis->mat[0].x * (float)v201);
            v230 = viewPos->z;
            v231 = viewPos->y;
            v232 = viewPos->x;
            v366.x = v200;
            v366.y = v200;
            v366.z = v200;
            v378.b[0].x = v357.x;
            v378.b[0].y = v357.y;
            v378.b[0].z = v357.z;
            v378.b[1] = v357;
            v384.z = (float)v230 + (float)v227;
            v384.y = (float)v228 + (float)v231;
            v384.x = (float)v232 + (float)v229;
            v233 = idEntity::GetPhysics(this: v207);
            if ( v233->GetClipModel(this: v233, a2: 0) != nullptr )
            {
              v234 = idEntity::GetPhysics(this: v207);
              v235 = (int)v234->GetClipModel(this: v234, a2: 0);
              v378.b[0].x = *(float *)(v235 + 104);
              LODWORD(v360) = v235 + 116;
              v378.b[0].y = *(float *)(v235 + 108);
              v378.b[0].z = *(float *)(v235 + 112);
              v378.b[1] = *(idVec3 *)(v235 + 116);
            }
            if ( v209 == nullptr || v209->IsDead(this: v209) )
            {
              if ( idGeometry::ClosestPointOnLineSegment(point: &v357, start: viewPos, end: &v384, closest: &v366) )
              {
                if ( (float)((float)((float)(v366.z - v357.z) * (float)(v366.z - v357.z))
                           + (float)((float)((float)(v366.x - v357.x) * (float)(v366.x - v357.x))
                                   + (float)((float)(v366.y - v357.y) * (float)(v366.y - v357.y)))) < 400.0
                  || (v388.origin.x = v366.x,
                      v388.origin.y = v366.y,
                      v388.origin.z = v366.z,
                      v388.radius = 20.0,
                      idBounds::SphereIntersection(this: &v378, s: &v388)) )
                {
                  v208 = 1;
                }
              }
            }
            else
            {
              v236 = idEntity::GetPhysics(this: v207);
              v237 = (int)v236->GetAxis(this: v236, a2: 0);
              v238 = *(float *)(v237 + 28);
              v239 = *(float *)(v237 + 32);
              v362 = *(float *)(v237 + 24);
              v363 = v238;
              v364 = v239;
              v240 = idEntity::GetPhysics(this: v207);
              v241 = (int)v240->GetBounds(this: v240, a2: -1);
              v242 = *(float *)(v241 + 16);
              v243 = *(float *)(v241 + 12);
              v386 = *(float *)(v241 + 20);
              v360 = v242;
              v377.z = v357.z + (float)(v386 * v364);
              v385[4] = v243;
              v385[5] = v242;
              v377.y = v357.y + (float)(v386 * v363);
              v377.x = (float)(v386 * v362) + v357.x;
              idGeometry::SegmentSegmentClosestPoints(
                start1: viewPos,
                end1: &v384,
                start2: &v357,
                end2: &v377,
                out1: &v366,
                out2: &v357,
                t1: (float *)&v365,
                t2: &v368,
                clampTValues: v313);
              v244 = v368;
              if ( v368 > v200
                && v244 < 1.15
                && (float)((float)((float)(v366.z - v357.z) * (float)(v366.z - v357.z))
                         + (float)((float)((float)(v366.x - v357.x) * (float)(v366.x - v357.x))
                                 + (float)((float)(v366.y - v357.y) * (float)(v366.y - v357.y)))) < 400.0 )
              {
                v208 = 1;
              }
              if ( *(_DWORD *)(LODWORD(v361) + 32) == owner->entityNumber && v244 > v200 && v244 >= 1.0 )
              {
                v357.x = v377.x;
                v357.y = v377.y;
                v357.z = v377.z;
              }
            }
            if ( *(_DWORD *)(LODWORD(v361) + 32) == owner->entityNumber )
            {
              clientGame->renderWorld->DebugPoint(
                this: clientGame->renderWorld,
                a2: (const idVec4 *)&idColor::colorBlue,
                a3: &v357,
                a4: 0,
                a5: false);
              v245 = v366.z;
              v246 = v366.y;
              v247 = v366.x;
              v376.x = v357.x - v366.x;
              v376.z = v357.z - v366.z;
              v376.y = v357.y - v366.y;
              v248 = idVec3::NormalizeFast(this: &v376);
              v249 = v376.z;
              v250 = v376.y;
              v251 = v376.x;
              v252 = 20.0;
              if ( v248 > 20.0 )
              {
                v387[2] = (float)v245 + (float)(v376.z * (float)20.0);
                v387[1] = (float)v246 + (float)(v376.y * (float)20.0);
                v387[0] = (float)(v376.x * (float)20.0) + (float)v247;
                clientGame->renderWorld->DebugLine(
                  this: clientGame->renderWorld,
                  a2: (const idVec4 *)LODWORD(v367),
                  a3: (const idVec3 *)v387,
                  a4: &v357,
                  a5: 0,
                  a6: false);
                v252 = 20.0;
                v245 = v366.z;
                v246 = v366.y;
                v247 = v366.x;
              }
              v385[2] = (float)v245 + (float)((float)v249 * (float)v252);
              v385[1] = (float)v246 + (float)((float)v250 * (float)v252);
              v385[0] = (float)((float)v251 * (float)v252) + (float)v247;
              clientGame->renderWorld->DebugLine(
                this: clientGame->renderWorld,
                a2: (const idVec4 *)&idColor::colorBlue,
                a3: &v366,
                a4: (const idVec3 *)v385,
                a5: 0,
                a6: false);
            }
          }
          if ( v208 != 0 )
          {
            v253 = this->focusTrace.numFocusTraces;
            v254 = v357.y;
            v255 = v357.z;
            v256 = v357.x;
            this->focusTrace.numFocusTraces = v253 + 1;
            v257 = (char *)this + 24 * v253;
            v258 = *(float *)&v207->entityNumber;
            v259 = viewPos->y;
            v260 = viewPos->x;
            v369.z = (float)v255 - viewPos->z;
            v369.x = (float)v256 - (float)v260;
            v369.y = (float)v254 - (float)v259;
            v360 = v258;
            *((_DWORD *)v257 + 44) = (gameLocal->spawnIds.ptr[LODWORD(v258)] << 13) | LODWORD(v258);
            *((float *)v257 + 45) = idVec3::NormalizeFast(this: &v369);
            v261 = v373;
            *((float *)v257 + 46) = (float)(v369.x * viewAxis->mat[0].x)
                                  + (float)((float)(v369.z * viewAxis->mat[0].z) + (float)(v369.y * viewAxis->mat[0].y));
            *((_QWORD *)v257 + 24) = *(_QWORD *)&idClip::Translation(
                                                   this: (idClip *)&v382,
                                                   result: &clientGame->clip,
                                                   a3: nullptr,
                                                   start: &this->focusTrace.start,
                                                   end: &v357,
                                                   clipModel: nullptr,
                                                   startAxis: v203,
                                                   clipMask: 2209987,
                                                   passEntityNumber: v313,
                                                   moveClipModel: v315,
                                                   userName: v317,
                                                   a12: v319,
                                                   a13: v321,
                                                   a14: v323,
                                                   a15: v325,
                                                   a16: v327,
                                                   a17: v329,
                                                   a18: v331,
                                                   a19: v333,
                                                   a20: v335,
                                                   a21: v337,
                                                   a22: v339,
                                                   a23: v341,
                                                   a24: v343,
                                                   a25: v345,
                                                   a26: v347,
                                                   a27: v349,
                                                   a28: *(_DWORD *)(v261 + 492),
                                                   a29: v352,
                                                   a30: false,
                                                   a31: v354,
                                                   a32: (int)"w:\\tech5\\tungsten\\game\\player\\FocusTracker.cpp(457) : Translation")->world;
          }
          v202 = owner;
        }
        ++v204;
        ++v205;
      }
      while ( v204 < v372 );
    }
    else
    {
      v200 = v382;
      v202 = owner;
      v201 = v368;
    }
    if ( this->validPointResult && this->pointTraceResult.fraction < 1.0 && v358 == 0 )
    {
      v262 = this->pointTraceResult.c.entityNum;
      if ( v262 >= 0 && (this->pointTraceResult.c.surfaceFlags & 0x8000) != 0 )
        this->overFriendly = true;
      if ( v262 != 8190 )
      {
        v263 = 4 * (v262 + 21563);
        v264 = *(idEntity **)((char *)&gameLocal->__vftable + v263);
        if ( v264 != nullptr )
        {
          if ( (unsigned __int8)idExplodable::IsTypeOf(c: *(idClass **)((char *)&gameLocal->__vftable + v263)) != 0 )
          {
            v265 = idEntity::GetBindMaster(this: v264);
            if ( v265 != nullptr )
              v264 = v265;
          }
          idFocusTracker::SetFocusEntity(this, ent: v264);
          trace_t::operator=(this: &this->focusTrace.tr, __that: &this->pointTraceResult);
          this->focusTrace.distance = this->pointTraceResult.fraction * v383;
        }
      }
    }
    this->focusTrace.closeEnough = this->focusTrace.distance < v201;
    v266 = gameLocal;
    if ( gameLocal->spawnIds.ptr[this->focusEntityOverride.spawnId.value & 0x1FFF] == this->focusEntityOverride.spawnId.value >> 13 )
    {
      this->focusEntity.spawnId.value = this->focusEntityOverride.spawnId.value;
      this->focusTrace.distance = v200;
      this->focusTrace.closeEnough = true;
      v266 = gameLocal;
    }
    if ( !this->overFriendly )
    {
      value = this->focusEntity.spawnId.value;
      if ( v266->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v268 = v266->entities.ptr[value & 0x1FFF]) != nullptr )
        v269 = (idAI2 *)idEntity::CastTo(c: v268);
      else
        v269 = nullptr;
      v270 = idAI2::CastTo(c: v269);
      if ( v270 != nullptr && v270->aiEditable.interactions.playerShouldLowerWeapon )
        this->overFriendly = true;
      v271 = this->focusEntity.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v271 & 0x1FFF] == v271 >> 13
        && (v272 = gameLocal->entities.ptr[v271 & 0x1FFF]) != nullptr )
      {
        v273 = (idAnimatedSimple *)idEntity::CastTo(c: v272);
      }
      else
      {
        v273 = nullptr;
      }
      v274 = idAnimatedSimple::CastTo(c: v273);
      if ( v274 != nullptr && (*((_BYTE *)v274 + 5292) & 0x20) != 0 )
        this->overFriendly = true;
      v266 = gameLocal;
    }
    v275 = this->focusEntity.spawnId.value;
    if ( v266->spawnIds.ptr[v275 & 0x1FFF] != v275 >> 13 )
      goto LABEL_146;
    v276 = v266->entities.ptr[v275 & 0x1FFF];
    if ( v276 == nullptr || idEntity::CastTo(c: v276) == nullptr )
      goto LABEL_146;
    v277 = this->focusEntity.spawnId.value;
    v278 = gameLocal;
    if ( gameLocal->spawnIds.ptr[v277 & 0x1FFF] == v277 >> 13
      && (v279 = gameLocal->entities.ptr[v277 & 0x1FFF]) != nullptr )
    {
      v280 = idEntity::CastTo(c: v279);
      v278 = gameLocal;
    }
    else
    {
      v280 = nullptr;
    }
    if ( v280->presentable != nullptr
      && ((v281 = this->focusEntity.spawnId.value, v278->spawnIds.ptr[v281 & 0x1FFF] != v281 >> 13)
       || (v282 = v278->entities.ptr[v281 & 0x1FFF]) == nullptr
        ? (v283 = nullptr)
        : (v283 = idEntity::CastTo(c: v282)),
          (presentable = v283->presentable) != nullptr
       || (idEntity::InitPresentableInternal(this: v283), (presentable = v283->presentable) != nullptr)) )
    {
      this->focusPresentable.spawnId = presentable->spawnId;
    }
    else
    {
LABEL_146:
      this->focusPresentable.spawnId = 0;
    }
    v285 = this->focusEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v285 & 0x1FFF] == v285 >> 13
      && (v286 = gameLocal->entities.ptr[v285 & 0x1FFF]) != nullptr
      && idEntity::CastTo(c: v286) != nullptr )
    {
      v292 = this->focusEntity.spawnId.value;
      v293 = gameLocal;
      if ( gameLocal->spawnIds.ptr[v292 & 0x1FFF] == v292 >> 13 )
      {
        v294 = gameLocal->entities.ptr[v292 & 0x1FFF];
        if ( v294 != nullptr )
        {
          if ( idEntity::CastTo(c: v294) != nullptr && *(_DWORD *)(LODWORD(v361) + 32) == v202->entityNumber )
          {
            v295 = this->focusEntity.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v295 & 0x1FFF] == v295 >> 13
              && (v296 = gameLocal->entities.ptr[v295 & 0x1FFF]) != nullptr )
            {
              v297 = idEntity::CastTo(c: v296);
            }
            else
            {
              v297 = nullptr;
            }
            v298 = idEntity::GetPhysics(this: v297);
            v299 = v298->GetAbsBounds(this: v298, a2: -1);
            clientGame->renderWorld->DebugBounds(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&idColor::colorCyan,
              a3: v299,
              a4: &vec3_origin,
              a5: 0,
              a6: false);
          }
          v293 = gameLocal;
        }
      }
      v300 = this->focusEntity.spawnId.value;
      if ( v293->spawnIds.ptr[v300 & 0x1FFF] == v300 >> 13 && (v301 = v293->entities.ptr[v300 & 0x1FFF]) != nullptr )
        v302 = idEntity::CastTo(c: v301);
      else
        v302 = nullptr;
      if ( this->UpdateCursor(this, a2: v202, a3: v302, a4: &this->focusTrace) )
      {
        v303 = this->focusEntity.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v303 & 0x1FFF] == v303 >> 13
          && (v304 = gameLocal->entities.ptr[v303 & 0x1FFF]) != nullptr )
        {
          v305 = (idProp_Noticable *)idEntity::CastTo(c: v304);
        }
        else
        {
          v305 = nullptr;
        }
        v306 = idProp_Noticable::CastTo(c: v305);
        if ( v306 != nullptr )
          idProp_Noticable::BecomeNoticed(this: v306, ent: v202);
      }
      if ( v371.logIndex >= 0 )
      {
        pLog = v371.pLog;
        v308 = &v371.pLog->logEntries.list[v371.logIndex];
        v309 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        totalTicks = v308->totalTicks;
        HIDWORD(totalTicks) = v308->parent;
        LODWORD(v311) = v309 - totalTicks;
        v308->totalTicks = v311;
        pLog->lastEntry = HIDWORD(totalTicks);
      }
    }
    else
    {
      this->UpdateCursor(this, a2: v202, a3: nullptr, a4: &this->focusTrace);
      this->UpdateCursorFlash(this, a2: v202);
      if ( v371.logIndex >= 0 )
      {
        v287 = v371.pLog;
        v288 = &v371.pLog->logEntries.list[v371.logIndex];
        v289 = (unsigned __int64)Sys_GetClockTicks() >> 32;
        v290 = v288->totalTicks;
        HIDWORD(v290) = v288->parent;
        LODWORD(v291) = v289 - v290;
        v288->totalTicks = v291;
        v287->lastEntry = HIDWORD(v290);
      }
    }
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v371);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$490896_0
// EA  : 0x82DFDA38
// RVA : 0x00DFDA38
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void _unwind_490896_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1008 + 704));
}


// ========================================================================
// __unwind$490897_0
// EA  : 0x82DFDA60
// RVA : 0x00DFDA60
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void _unwind_490897_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1008 + 232));
}


// ========================================================================
// `dynamic initializer for 'player_updateFocus''
// EA  : 0x833874A0
// RVA : 0x013874A0
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_updateFocus__()
{
  idCVar::idCVar(
    this: &player_updateFocus,
    name: "player_updateFocus",
    value: "1",
    flags: 1,
    description: "1 to enable updating the player's focus icon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_updateFocus__);
}


// ========================================================================
// `dynamic initializer for 'player_focusDebug''
// EA  : 0x833874F8
// RVA : 0x013874F8
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_focusDebug__()
{
  idCVar::idCVar(
    this: &player_focusDebug,
    name: "player_focusDebug",
    value: "-1",
    flags: 2,
    description: "Debug player focus (0 for local player!)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_focusDebug__);
}


// ========================================================================
// `dynamic initializer for 'idFocusTracker::FOCUS_DEFAULT_PASSIVE_SELOFFSET''
// EA  : 0x83387550
// RVA : 0x01387550
// PDB : w:\tech5\tungsten\game\player\focustracker.cpp
// ========================================================================

void _dynamic_initializer_for__idFocusTracker::FOCUS_DEFAULT_PASSIVE_SELOFFSET__()
{
  idFocusTracker::FOCUS_DEFAULT_PASSIVE_SELOFFSET = (int)__fsqrts(3200.0);
}

