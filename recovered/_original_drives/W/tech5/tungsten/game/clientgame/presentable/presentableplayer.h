
// ========================================================================
// ?GetActorModifierManager@idPresentableActor@@UAAPAVidActorModifierManager@@XZ
// EA  : 0x82B6A520
// RVA : 0x00B6A520
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

const idActorModifierManager *__fastcall idPresentableActor::GetActorModifierManager(idPresentableActor *this)
{
  return this->actorModifierManager;
}


// ========================================================================
// ?DebugPrintInhibitFlagNames@idUCmdInhibit@@SAXW4inhibitFlags_t@1@@Z
// EA  : 0x82B73E28
// RVA : 0x00B73E28
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

void __fastcall idUCmdInhibit::DebugPrintInhibitFlagNames(idUCmdInhibit::inhibitFlags_t flags)
{
  idLib::Printf(fmt: "DebugPrintInhibitFlagNames %i \n", flags);
  if ( flags != UCMD_INHIBIT_NONE )
  {
    if ( (flags & 1) != 0 )
      idLib::Printf(fmt: " - UCMD_INHIBIT_MOVEMENT_FWD \n");
    if ( (flags & 2) != 0 )
      idLib::Printf(fmt: " - UCMD_INHIBIT_MOVEMENT_RT \n");
    if ( (flags & 4) != 0 )
      idLib::Printf(fmt: " - UCMD_INHIBIT_MOVEMENT_UP \n");
    if ( (flags & 8) != 0 )
      idLib::Printf(fmt: " - UCMD_INHIBIT_VIEW \n");
    if ( (flags & 0x10) != 0 )
      idLib::Printf(fmt: " - UCMD_INHIBIT_BUTTONS \n");
    if ( (flags & 0x20) != 0 )
      idLib::Printf(fmt: " - UCMD_INHIBIT_MOVEMENT_ONCE \n");
    if ( (flags & 0x40) != 0 )
      idLib::Printf(fmt: " - UCMD_INHIBIT_VIEW_ONCE \n");
    if ( (flags & 0x80) != 0 )
      idLib::Printf(fmt: " - UCMD_INHIBIT_BUTTONS_ONCE \n");
    if ( (flags & 0x100) != 0 )
      idLib::Printf(fmt: " - UCMD_INHIBIT_VIEW_DISCARD \n");
  }
  else
  {
    idLib::Printf(fmt: " No flags set \n");
  }
}


// ========================================================================
// ??0localView_t@@QAA@XZ
// EA  : 0x82B73F58
// RVA : 0x00B73F58
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

localView_t *__fastcall localView_t::localView_t(localView_t *this)
{
  this->initialized = false;
  idPlayerHud_Render::idPlayerHud_Render(this: &this->hudRender);
  idPlayerGuis_Render::idPlayerGuis_Render(this: &this->guisRender);
  return this;
}


// ========================================================================
// __unwind$494384
// EA  : 0x82B73FAC
// RVA : 0x00B73FAC
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

void _unwind_494384()
{
  int v0; // r12

  idPlayerHud_Render::~idPlayerHud_Render(this: (idPlayerHud_Render *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ??0idPlayerExplicitMotion_t@idPresentablePlayer@@QAA@XZ
// EA  : 0x82B77180
// RVA : 0x00B77180
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

idPresentablePlayer::idPlayerExplicitMotion_t *__fastcall idPresentablePlayer::idPlayerExplicitMotion_t::idPlayerExplicitMotion_t(
        idPresentablePlayer::idPlayerExplicitMotion_t *this)
{
  double z; // fp0
  double v2; // fp0
  double v3; // fp0
  double v4; // fp0

  this->moveType = EXPLICIT_MOVE_NONE;
  this->singleMove.delta.x = vec3_origin.x;
  this->singleMove.delta.y = vec3_origin.y;
  z = vec3_origin.z;
  this->singleMove.clipMove = true;
  this->singleMove.delta.z = z;
  this->singleMove.velocityType = VEL_EXPLICIT;
  this->singleMove.overrideVelocity = vec3_origin;
  this->singleMove.ignoreEntityNum = 0x1FFF;
  this->singleMove2.delta.x = vec3_origin.x;
  this->singleMove2.delta.y = vec3_origin.y;
  v2 = vec3_origin.z;
  this->singleMove2.clipMove = true;
  this->singleMove2.delta.z = v2;
  this->singleMove2.velocityType = VEL_EXPLICIT;
  this->singleMove2.overrideVelocity = vec3_origin;
  this->singleMove2.ignoreEntityNum = 0x1FFF;
  this->singleMove.delta.x = vec3_origin.x;
  this->singleMove.delta.y = vec3_origin.y;
  v3 = vec3_origin.z;
  this->singleMove.clipMove = true;
  this->singleMove.delta.z = v3;
  this->singleMove.velocityType = VEL_EXPLICIT;
  this->singleMove.overrideVelocity = vec3_origin;
  this->singleMove.ignoreEntityNum = 0x1FFF;
  this->singleMove2.delta.x = vec3_origin.x;
  this->singleMove2.delta.y = vec3_origin.y;
  v4 = vec3_origin.z;
  this->singleMove2.clipMove = true;
  this->singleMove2.delta.z = v4;
  this->singleMove2.velocityType = VEL_EXPLICIT;
  this->singleMove2.overrideVelocity = vec3_origin;
  this->singleMove2.ignoreEntityNum = 0x1FFF;
  return this;
}


// ========================================================================
// ??0idWeaponKick@@QAA@XZ
// EA  : 0x82B78AA0
// RVA : 0x00B78AA0
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

idWeaponKick *__fastcall idWeaponKick::idWeaponKick(idWeaponKick *this)
{
  double currentValue; // fp12
  double v2; // fp11

  this->recoilOffset.duration = 0.0;
  this->recoilOffset.startTime = 0.0;
  this->recoilOffset.currentTime = 0.0;
  this->recoilOffset.currentValue = 0.0;
  currentValue = this->recoilOffset.currentValue;
  this->recoilOffset.endValue = this->recoilOffset.currentValue;
  this->recoilOffset.startValue = currentValue;
  this->recoveryOffset.duration = 0.0;
  this->recoveryOffset.startTime = 0.0;
  this->recoveryOffset.currentTime = 0.0;
  this->recoveryOffset.currentValue = 0.0;
  v2 = this->recoveryOffset.currentValue;
  this->recoveryOffset.endValue = this->recoveryOffset.currentValue;
  this->recoveryOffset.startValue = v2;
  this->recoilOffset.startTime = 0.0;
  this->recoilOffset.duration = 0.0;
  this->recoilOffset.startValue = 0.0;
  this->recoilOffset.endValue = 0.0;
  this->recoilOffset.currentTime = -1.0;
  this->recoilOffset.currentValue = 0.0;
  this->recoveryOffset.startTime = 0.0;
  this->recoveryOffset.duration = 0.0;
  this->recoveryOffset.startValue = 0.0;
  this->recoveryOffset.endValue = 0.0;
  this->recoveryOffset.currentTime = -1.0;
  this->recoveryOffset.currentValue = 0.0;
  return this;
}


// ========================================================================
// ?GetMissionPin@idPresentablePlayer@@QBAPAVidEntity@@XZ
// EA  : 0x82B797E8
// RVA : 0x00B797E8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

idEntity *__fastcall idPresentablePlayer::GetMissionPin(idPresentablePlayer *this)
{
  int value; // r8
  idEntity *v2; // r3

  value = this->missionPin.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetUsableState@idGuiEntity@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82B7E580
// RVA : 0x00B7E580
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

int __fastcall idGuiEntity::GetUsableState(
        ActionFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 8;
}


// ========================================================================
// ?GetControllingPlayerIndex@idPresentablePlayer@@UAAHXZ
// EA  : 0x82B7E588
// RVA : 0x00B7E588
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

int __fastcall idPresentablePlayer::GetControllingPlayerIndex(idPresentablePlayer *this)
{
  return this->entityNumber;
}


// ========================================================================
// ?GetOnlineUsableText@idPresentablePlayer@@UBA?AVidStrId@@XZ
// EA  : 0x82B7E590
// RVA : 0x00B7E590
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

idPresentablePlayer *__fastcall idPresentablePlayer::GetOnlineUsableText(idPresentablePlayer *this, idStrId *result)
{
  idStrId::Set((idStrId *)this, key: "#str_online_revive_crosshair_info");
  return this;
}


// ========================================================================
// ?GetSmoothOrigin@idPresentablePlayer@@QAA?AVidVec3@@XZ
// EA  : 0x82B83D50
// RVA : 0x00B83D50
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

idPresentablePlayer *__fastcall idPresentablePlayer::GetSmoothOrigin(idPresentablePlayer *this, idVec3 *result)
{
  float *p_z; // r30
  float *v4; // r3
  double v6; // fp7
  double v7; // fp6

  p_z = &result[3885].z;
  v4 = (float *)(*(int (__fastcall **)(idVec3 *, _DWORD))(LODWORD(result[3022].x) + 64))(a1: result + 3022, a2: 0);
  v6 = (float)(p_z[1] + v4[1]);
  v7 = (float)(p_z[2] + v4[2]);
  *(float *)&this->__vftable = *p_z + *v4;
  *((float *)&this->__vftable + 1) = v6;
  *(float *)&this->groupMaster.idPresentableActor::idPresentableAnimatedEntity::idPresentable::spawnId = v7;
  return this;
}


// ========================================================================
// ?GetUniqueProjectile@idPresentablePlayer@@QBAPBVidPresentableProjectile@@XZ
// EA  : 0x82D242B8
// RVA : 0x00D242B8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

const idPresentableProjectile *__fastcall idPresentablePlayer::GetUniqueProjectile(idPresentablePlayer *this)
{
  unsigned int spawnId; // r11
  int v3; // r30
  const idPresentableProjectile *result; // r3

  spawnId = this->uniqueTrackedProjectile.spawnId;
  v3 = spawnId & 0x3FFF;
  if ( spawnId == 0 )
    return nullptr;
  if ( !idClientGame::IsPresentableIndexValid(this: clientGame, index: spawnId & 0x3FFF) )
    return nullptr;
  result = (const idPresentableProjectile *)idClientGame::GetPresentableByIndex(this: clientGame, index: v3);
  if ( result->spawnId != this->uniqueTrackedProjectile.spawnId )
    return nullptr;
  return result;
}


// ========================================================================
// ?GetActiveUCmdTracker@idPresentablePlayer@@QAAAAVidUCmdTracker@@XZ
// EA  : 0x82D78DA8
// RVA : 0x00D78DA8
// PDB : w:\tech5\tungsten\game\clientgame\presentable\presentableplayer.h
// ========================================================================

idUCmdTracker *__fastcall idPresentablePlayer::GetActiveUCmdTracker(idPresentablePlayer *this)
{
  if ( idPresentablePlayer::GetControl(this) != nullptr )
    return &this->ucmdTracker2;
  else
    return &this->ucmdTracker1;
}

