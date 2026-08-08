
// ========================================================================
// ?GetCurrentPlayerInteractionTempInfoState@idAI2@@QBA?AW4playerInteractionState_t@@XZ
// EA  : 0x82A37E38
// RVA : 0x00A37E38
// PDB : w:\tech5\tungsten\game\ai\ai2_interactions.cpp
// ========================================================================

playerInteractionState_t __fastcall idAI2::GetCurrentPlayerInteractionTempInfoState(idAI2 *this)
{
  return this->aiVolatile.tempPlayerInteractionInfoState;
}


// ========================================================================
// ?SetCurrentPlayerInteractionTempInfoState@idAI2@@QAAXW4playerInteractionState_t@@@Z
// EA  : 0x82A37E48
// RVA : 0x00A37E48
// PDB : w:\tech5\tungsten\game\ai\ai2_interactions.cpp
// ========================================================================

void __fastcall idAI2::SetCurrentPlayerInteractionTempInfoState(idAI2 *this, playerInteractionState_t newState)
{
  this->aiVolatile.tempPlayerInteractionInfoState = newState;
}


// ========================================================================
// ?GetBoundsExpansionForDir@@YAMABVidBounds@@ABVidVec3@@@Z
// EA  : 0x82A37EA8
// RVA : 0x00A37EA8
// PDB : w:\tech5\tungsten\game\ai\ai2_interactions.cpp
// ========================================================================

float __fastcall GetBoundsExpansionForDir(const idBounds *bounds, const idVec3 *dir)
{
  double v2; // fp11
  double v3; // fp1

  v2 = (float)((float)(bounds->b[0].x * dir->x)
             + (float)((float)(bounds->b[0].y * dir->y) + (float)(bounds->b[0].z * dir->z)));
  if ( v2 <= 0.0 )
    v3 = __fabs((float)((float)(bounds->b[1].x * dir->x)
                      + (float)((float)(bounds->b[1].y * dir->y) + (float)(bounds->b[1].z * dir->z))));
  else
    v3 = __fabs(v2);
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?GetCurrentPlayerInteraction@idAI2@@QBAPBVaiPlayerInteraction_t@@XZ
// EA  : 0x82A37F08
// RVA : 0x00A37F08
// PDB : w:\tech5\tungsten\game\ai\ai2_interactions.cpp
// ========================================================================

const aiPlayerInteraction_t *__fastcall idAI2::GetCurrentPlayerInteraction(idAI2 *this)
{
  int currentPlayerInteraction; // r4

  currentPlayerInteraction = this->aiVolatile.memory.currentPlayerInteraction;
  if ( currentPlayerInteraction >= 0 )
    return idAIPlayerInteraction::GetInteraction(
             this: &this->aiVolatile.aiPlayerInteraction,
             index: currentPlayerInteraction);
  else
    return nullptr;
}


// ========================================================================
// ?SetCurrentPlayerInteraction@idAI2@@QAAXPBVaiPlayerInteraction_t@@@Z
// EA  : 0x82A37F30
// RVA : 0x00A37F30
// PDB : w:\tech5\tungsten\game\ai\ai2_interactions.cpp
// ========================================================================

void __fastcall idAI2::SetCurrentPlayerInteraction(idAI2 *this, const aiPlayerInteraction_t *interaction)
{
  if ( interaction != nullptr )
    this->aiVolatile.memory.currentPlayerInteraction = idAIPlayerInteraction::GetInteractionIndex(
                                                         this: &this->aiVolatile.aiPlayerInteraction,
                                                         interaction);
  else
    this->aiVolatile.memory.currentPlayerInteraction = -1;
}


// ========================================================================
// ?CanIdleTrackFriendlyTarget@idAI2@@QBA_NPBVidEntity@@@Z
// EA  : 0x82A37FA0
// RVA : 0x00A37FA0
// PDB : w:\tech5\tungsten\game\ai\ai2_interactions.cpp
// ========================================================================

int __fastcall idAI2::CanIdleTrackFriendlyTarget(idAI2 *this, const idEntity *friendlyTarget)
{
  idAIEntityState *v3; // r3
  idAIEntityState *v4; // r30
  int result; // r3
  idVec3 v6; // [sp+50h] [-40h] BYREF
  float v7; // [sp+60h] [-30h] BYREF
  float v8; // [sp+64h] [-2Ch]
  float v9; // [sp+68h] [-28h]

  if ( friendlyTarget == nullptr
    || this->aiEditable.interactions.idleTrackFriendlyDist < 0.0
    || this->aiEditable.interactions.playerMustLeaveBeforeIdleTracking
    && (*((_BYTE *)&this->aiVolatile + 49704) & 2) == 0 )
  {
    return 0;
  }
  v3 = idAIWorldState::StateForEntity(this: &this->aiVolatile.world.worldState, ent: friendlyTarget);
  v4 = v3;
  if ( v3 == nullptr )
    return 0;
  if ( !idAIEntityState::IsVisible(this: v3) )
    return 0;
  idAIEntityState::GetAimPoint(this: v4, sense: AISENSE_SIGHT, aimPoint: AIMPOINT_HEAD, point: &v6);
  this->GetEyePos(this, a2: (idVec3 *)&v7);
  result = 1;
  if ( (float)((float)((float)(v6.x - v7) * (float)(v6.x - v7))
             + (float)((float)((float)(v6.z - v9) * (float)(v6.z - v9))
                     + (float)((float)(v6.y - v8) * (float)(v6.y - v8)))) > (double)(float)(this->aiEditable.interactions.idleTrackFriendlyDist
                                                                                          * this->aiEditable.interactions.idleTrackFriendlyDist) )
    return 0;
  return result;
}


// ========================================================================
// ?PlayerApproachingInteraction@idAI2@@QAA_NPAVidPlayer@@@Z
// EA  : 0x82A380C0
// RVA : 0x00A380C0
// PDB : w:\tech5\tungsten\game\ai\ai2_interactions.cpp
// ========================================================================

int __fastcall idAI2::PlayerApproachingInteraction(idAI2 *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v5; // r3
  const idDeclAIPlayerInteraction **p_decl; // r28
  const idDeclAIPlayerInteraction *decl; // r11
  double approachRadius; // fp31
  idPhysics *Physics; // r3
  float *v10; // r3
  idPhysics *v11; // r3
  int v12; // r3
  float v13; // r11
  float v14; // r10
  double departureRadius; // fp30
  idPhysics *v16; // r3
  float *v17; // r3
  double v18; // fp13
  double v19; // fp12
  idPhysics *v20; // r3
  idPhysics *v21; // r3
  const idBounds *v22; // r3
  idPhysics *v23; // r3
  double lookAheadTime; // fp31
  float *v25; // r3
  double v26; // fp6
  double v27; // fp5
  int *p_currentPlayerInteraction; // r26
  int currentPlayerInteraction; // r10
  int v30; // r31
  const idDeclAIPlayerInteraction *v31; // r28
  const aiPlayerInteraction_t *Interaction; // r4
  idAIPlayerInteraction *p_aiPlayerInteraction; // r31
  bool HasExpired; // r3
  const aiPlayerInteraction_t *v35; // r3
  const aiPlayerInteraction_t *v36; // r3
  idAIEntityState *v37; // r3
  idVec3 v39; // [sp+50h] [-A0h] BYREF
  idVec3 v40; // [sp+60h] [-90h] BYREF
  idVec3 v41; // [sp+70h] [-80h] BYREF
  idSphere v42; // [sp+80h] [-70h] BYREF
  idSphere v43; // [sp+90h] [-60h] BYREF

  presentable = player->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  if ( (*(_BYTE *)(v5 + 47032) & 0x20) != 0 )
    return 0;
  if ( (*((_BYTE *)player + 12824) & 8) != 0 )
    return 0;
  if ( idAI2::ActionScriptFlagIsSet(this, flags: 32) )
    return 0;
  p_decl = &this->aiVolatile.aiPlayerInteraction.decl;
  decl = this->aiVolatile.aiPlayerInteraction.decl;
  if ( decl == nullptr )
    return 0;
  approachRadius = decl->approachRadius;
  Physics = idEntity::GetPhysics(this);
  v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v43.origin.x = *v10;
  v43.origin.y = v10[1];
  v43.origin.z = v10[2];
  v43.radius = approachRadius;
  v11 = idEntity::GetPhysics(this: player);
  v12 = (int)v11->GetOrigin(this: v11, a2: 0);
  v13 = *(float *)(v12 + 4);
  v14 = *(float *)(v12 + 8);
  v39.x = *(float *)v12;
  v39.y = v13;
  v39.z = v14;
  if ( !idSphere::ContainsPoint(this: &v43, p: &v39) )
  {
    departureRadius = (*p_decl)->departureRadius;
    v16 = idEntity::GetPhysics(this);
    v17 = (float *)v16->GetOrigin(this: v16, a2: 0);
    v42.radius = departureRadius;
    v18 = v17[1];
    v19 = v17[2];
    v42.origin.x = *v17;
    v42.origin.y = v18;
    v42.origin.z = v19;
    if ( !idSphere::ContainsPoint(this: &v42, p: &v39) )
      return 0;
    v20 = idEntity::GetPhysics(this: player);
    v20->GetLinearVelocity(this: (idPhysics *)&v41, result: (idVec3 *)v20, a3: 0);
    if ( idVec3::NormalizeFast(this: &v41) < 0.0099999998 )
      return 0;
    v21 = idEntity::GetPhysics(this: player);
    v22 = v21->GetBounds(this: v21, a2: -1);
    v43.radius = GetBoundsExpansionForDir(bounds: v22, dir: &v41) + (float)approachRadius;
    v23 = idEntity::GetPhysics(this: player);
    lookAheadTime = (*p_decl)->lookAheadTime;
    v25 = (float *)v23->GetLinearVelocity(this: (idPhysics *)&v42, result: (idVec3 *)v23, a3: 0);
    v26 = (float)(v25[1] * (float)lookAheadTime);
    v27 = (float)(v25[2] * (float)lookAheadTime);
    v40.x = v39.x + (float)(*v25 * (float)lookAheadTime);
    v40.y = v39.y + (float)v26;
    v40.z = v39.z + (float)v27;
    if ( !idSphere::LineIntersection(this: &v43, start: &v39, end: &v40) )
      return 0;
  }
  p_currentPlayerInteraction = &this->aiVolatile.memory.currentPlayerInteraction;
  currentPlayerInteraction = this->aiVolatile.memory.currentPlayerInteraction;
  if ( currentPlayerInteraction >= 0 )
  {
    v30 = this->aiVolatile.memory.currentPlayerInteraction;
    v31 = *p_decl;
    Interaction = idAIPlayerInteraction::GetInteraction(
                    this: &this->aiVolatile.aiPlayerInteraction,
                    index: currentPlayerInteraction);
    HasExpired = idAIPlayerInteraction::InteractionHasExpired(
                   this: &this->aiVolatile.aiPlayerInteraction,
                   interaction: Interaction,
                   player,
                   interactionDecl: v31,
                   interactionNumber: v30);
    p_aiPlayerInteraction = &this->aiVolatile.aiPlayerInteraction;
    if ( !HasExpired )
      goto LABEL_16;
    idAI2::PlayerInteractionDone(this, playerLeft: true);
  }
  p_aiPlayerInteraction = &this->aiVolatile.aiPlayerInteraction;
  v35 = idAIPlayerInteraction::FindInteraction(
          this: &this->aiVolatile.aiPlayerInteraction,
          player,
          modifyState: true,
          debugString: nullptr);
  idAI2::SetCurrentPlayerInteraction(this, interaction: v35);
LABEL_16:
  if ( *p_currentPlayerInteraction >= 0
    && idAIPlayerInteraction::GetInteraction(this: p_aiPlayerInteraction, index: *p_currentPlayerInteraction) != nullptr )
  {
    v36 = *p_currentPlayerInteraction >= 0
        ? idAIPlayerInteraction::GetInteraction(this: p_aiPlayerInteraction, index: *p_currentPlayerInteraction)
        : nullptr;
    if ( !v36->activateWhenVisible
      || (*((_BYTE *)&this->aiVolatile + 49704) & 8) == 0
      || (v37 = idAIWorldState::StateForEntity(this: &this->aiVolatile.world.worldState, ent: player)) != nullptr
      && idAIEntityState::IsVisible(this: v37) )
    {
      this->aiVolatile.memory.interactionEntity.spawnId.value = (gameLocal->spawnIds.ptr[player->entityNumber] << 13)
                                                              | player->entityNumber;
      return 1;
    }
  }
  return 0;
}

