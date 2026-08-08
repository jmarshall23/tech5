
// ========================================================================
// ??0idModifiedPlayerMovement@@QAA@XZ
// EA  : 0x82C7C518
// RVA : 0x00C7C518
// PDB : w:\tech5\tungsten\game\entities\modifiedplayermovement.cpp
// ========================================================================

idModifiedPlayerMovement *__fastcall idModifiedPlayerMovement::idModifiedPlayerMovement(idModifiedPlayerMovement *this)
{
  idAnimatedSimple::idAnimatedSimple(this);
  this->__vftable = (idModifiedPlayerMovement_vtbl *)&idModifiedPlayerMovement::`vftable';
  this->strengthModifier = 1.0;
  this->useFixedDirection = false;
  this->maxSpeedDiff = 1.0;
  this->baseAngle = 90.0;
  this->playerEntity.spawnId.value = 0x1FFF;
  return this;
}


// ========================================================================
// ?Think@idModifiedPlayerMovement@@UAAXXZ
// EA  : 0x82C7C5E0
// RVA : 0x00C7C5E0
// PDB : w:\tech5\tungsten\game\entities\modifiedplayermovement.cpp
// ========================================================================

void __fastcall idModifiedPlayerMovement::Think(idModifiedPlayerMovement *this)
{
  idPhysics *Physics; // r3
  int v3; // r3
  char *v4; // r10
  _DWORD *v5; // r11
  int i; // ctr
  int value; // r9
  idPlayer *v8; // r3
  idPlayer *v9; // r3
  idPresentable *presentable; // r3
  int v11; // r3
  float *v12; // r30
  double v13; // fp30
  double v14; // fp29
  idPhysics *v15; // r3
  double baseAngle; // fp7
  double maxSpeedDiff; // fp5
  double v18; // fp4
  double v19; // fp3
  char v20; // [sp+4Ch] [-64h] BYREF
  float v21; // [sp+68h] [-48h]
  float v22; // [sp+6Ch] [-44h]
  float v23; // [sp+70h] [-40h]

  idAnimatedSimple::Think(this);
  if ( gameLocal->spawnIds.ptr[this->playerEntity.spawnId.value & 0x1FFF] == this->playerEntity.spawnId.value >> 13 )
  {
    Physics = idEntity::GetPhysics(this);
    v3 = (int)Physics->GetAxis(this: Physics, a2: 0);
    v4 = &v20;
    v5 = (_DWORD *)(v3 - 4);
    for ( i = 9; i != 0; --i )
    {
      ++v5;
      v4 += 4;
      *(_DWORD *)v4 = *v5;
    }
    value = this->playerEntity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v8 = (idPlayer *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v9 = idPlayer::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    presentable = v9->presentable;
    if ( presentable != nullptr )
      v11 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v11 = 0;
    v12 = (float *)(v11 + 36264);
    (*(void (__fastcall **)(int))(*(_DWORD *)(v11 + 36264) + 100))(a1: v11 + 36264);
    v13 = (float)((float)((float)(v22 * (float)0.0) - v21) + (float)(v23 * (float)0.0));
    v14 = (float)((float)((float)(v21 * (float)0.0) - v22) + (float)(v23 * (float)0.0));
    v15 = idEntity::GetPhysics(this);
    v15->GetOrigin(this: v15, a2: 0);
    baseAngle = this->baseAngle;
    maxSpeedDiff = this->maxSpeedDiff;
    v18 = (float)((float)v14 * this->strengthModifier);
    v19 = (float)(this->strengthModifier * (float)0.0);
    v12[315] = (float)v13 * this->strengthModifier;
    v12[316] = v18;
    v12[317] = v19;
    v12[313] = maxSpeedDiff;
    v12[314] = baseAngle;
  }
}


// ========================================================================
// ?Hide@idModifiedPlayerMovement@@UAAXXZ
// EA  : 0x82C7C780
// RVA : 0x00C7C780
// PDB : w:\tech5\tungsten\game\entities\modifiedplayermovement.cpp
// ========================================================================

void __fastcall idModifiedPlayerMovement::Hide(idModifiedPlayerMovement *this)
{
  idPlayer *v2; // r3
  idPlayer *v3; // r3
  idPresentable *presentable; // r3
  idVec3 *v5; // r3

  idAnimatedSimple::Hide(this);
  if ( gameLocal->spawnIds.ptr[this->playerEntity.spawnId.value & 0x1FFF] == this->playerEntity.spawnId.value >> 13 )
  {
    v2 = (idPlayer *)gameLocal->entities.ptr[this->playerEntity.spawnId.value & 0x1FFF];
    if ( v2 != nullptr )
      v3 = idPlayer::CastTo(c: v2);
    else
      v3 = nullptr;
    presentable = v3->presentable;
    if ( presentable != nullptr )
      v5 = (idVec3 *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = nullptr;
    v5[3127] = vec3_origin;
    v5[3126].y = 0.0;
    v5[3126].z = 90.0;
    this->playerEntity.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?Hide@idModifiedPlayerMovement@@UAAX_N@Z
// EA  : 0x82C7C878
// RVA : 0x00C7C878
// PDB : w:\tech5\tungsten\game\entities\modifiedplayermovement.cpp
// ========================================================================

void __fastcall idModifiedPlayerMovement::Hide(idModifiedPlayerMovement *this, bool stopFx)
{
  idPlayer *v3; // r3
  idPlayer *v4; // r3
  idPresentable *presentable; // r3
  idVec3 *v6; // r3

  idAnimatedSimple::Hide(this, stopFx);
  if ( gameLocal->spawnIds.ptr[this->playerEntity.spawnId.value & 0x1FFF] == this->playerEntity.spawnId.value >> 13 )
  {
    v3 = (idPlayer *)gameLocal->entities.ptr[this->playerEntity.spawnId.value & 0x1FFF];
    if ( v3 != nullptr )
      v4 = idPlayer::CastTo(c: v3);
    else
      v4 = nullptr;
    presentable = v4->presentable;
    if ( presentable != nullptr )
      v6 = (idVec3 *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v6 = nullptr;
    v6[3127] = vec3_origin;
    v6[3126].y = 0.0;
    v6[3126].z = 90.0;
    this->playerEntity.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?OnActivate@idModifiedPlayerMovement@@MAAXPAVidEntity@@@Z
// EA  : 0x82C7C970
// RVA : 0x00C7C970
// PDB : w:\tech5\tungsten\game\entities\modifiedplayermovement.cpp
// ========================================================================

void __fastcall idModifiedPlayerMovement::OnActivate(idModifiedPlayerMovement *this, idEntity *activator)
{
  idEntityPtr<idPlayer> *p_playerEntity; // r29
  idPlayer *Player; // r3
  idPhysics *Physics; // r3
  float *v6; // r3
  double baseAngle; // fp31
  double maxSpeedDiff; // fp30
  double v9; // fp29
  double v10; // fp28
  double v11; // fp27
  idPlayer *v12; // r3
  idPhysics_Player *PhysicsObj; // r3
  idPlayer *v14; // r3
  idPlayer *v15; // r3
  idPresentable *presentable; // r3
  idVec3 *v17; // r3

  p_playerEntity = &this->playerEntity;
  if ( gameLocal->spawnIds.ptr[this->playerEntity.spawnId.value & 0x1FFF] == this->playerEntity.spawnId.value >> 13 )
  {
    v14 = (idPlayer *)gameLocal->entities.ptr[this->playerEntity.spawnId.value & 0x1FFF];
    if ( v14 != nullptr )
      v15 = idPlayer::CastTo(c: v14);
    else
      v15 = nullptr;
    presentable = v15->presentable;
    if ( presentable != nullptr )
      v17 = (idVec3 *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v17 = nullptr;
    v17[3127] = vec3_origin;
    v17[3126].y = 0.0;
    v17[3126].z = 90.0;
    p_playerEntity->spawnId.value = 0x1FFF;
  }
  else
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    if ( Player != nullptr )
      p_playerEntity->spawnId.value = (gameLocal->spawnIds.ptr[Player->entityNumber] << 13) | Player->entityNumber;
    else
      p_playerEntity->spawnId.value = 0x1FFF;
    if ( gameLocal->spawnIds.ptr[p_playerEntity->spawnId.value & 0x1FFF] == p_playerEntity->spawnId.value >> 13
      && this->useFixedDirection )
    {
      Physics = idEntity::GetPhysics(this);
      v6 = (float *)Physics->GetAxis(this: Physics, a2: 0);
      baseAngle = this->baseAngle;
      maxSpeedDiff = this->maxSpeedDiff;
      v9 = (float)(*v6 * this->strengthModifier);
      v10 = (float)(v6[1] * this->strengthModifier);
      v11 = (float)(v6[2] * this->strengthModifier);
      v12 = idEntityPtr<idPlayer>::operator->(this: p_playerEntity);
      PhysicsObj = idPlayer::GetPhysicsObj(this: v12);
      PhysicsObj->modifiedAccelerationVec.x = v9;
      PhysicsObj->modifiedAccelerationVec.y = v10;
      PhysicsObj->modifiedAccelerationVec.z = v11;
      PhysicsObj->modifiedMovementMaxPercent = maxSpeedDiff;
      PhysicsObj->modifiedMovementAngle = baseAngle;
    }
  }
}


// ========================================================================
// ?Event_Remove@idModifiedPlayerMovement@@AAA?AVeventVoid@@XZ
// EA  : 0x82C7CB48
// RVA : 0x00C7CB48
// PDB : w:\tech5\tungsten\game\entities\modifiedplayermovement.cpp
// ========================================================================

idModifiedPlayerMovement *__fastcall idModifiedPlayerMovement::Event_Remove(
        idModifiedPlayerMovement *this,
        eventVoid *result)
{
  idGameLocal *v3; // r11
  idPlayer *v5; // r3
  idPlayer *v6; // r3
  idPresentable *presentable; // r3
  idVec3 *v8; // r3
  idLinkList<idEntity> *head; // r5

  v3 = gameLocal;
  if ( gameLocal->spawnIds.ptr[*(_DWORD *)&result[7672] & 0x1FFF] == *(int *)&result[7672] >> 13 )
  {
    v5 = (idPlayer *)gameLocal->entities.ptr[*(_DWORD *)&result[7672] & 0x1FFF];
    if ( v5 != nullptr )
      v6 = idPlayer::CastTo(c: v5);
    else
      v6 = nullptr;
    presentable = v6->presentable;
    if ( presentable != nullptr )
      v8 = (idVec3 *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v8 = nullptr;
    v8[3127] = vec3_origin;
    v8[3126].y = 0.0;
    v8[3126].z = 90.0;
    *(_DWORD *)&result[7672] = 0x1FFF;
    v3 = gameLocal;
  }
  head = v3->removeEntities.head;
  *(_DWORD *)(*(_DWORD *)&result[788] + 4) = *(_DWORD *)&result[784];
  *(_DWORD *)(*(_DWORD *)&result[784] + 8) = *(_DWORD *)&result[788];
  *(_DWORD *)&result[788] = result + 780;
  *(_DWORD *)&result[780] = result + 780;
  *(_DWORD *)&result[784] = head;
  *(_DWORD *)&result[788] = head->prev;
  head->prev = (idLinkList<idEntity> *)&result[780];
  *(_DWORD *)(*(_DWORD *)&result[788] + 4) = result + 780;
  *(_DWORD *)&result[780] = head->head;
  return this;
}

