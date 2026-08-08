
// ========================================================================
// ?GetFocusTracker@idPlayer@@QAAAAVidFocusTracker@@XZ
// EA  : 0x829F0988
// RVA : 0x009F0988
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

int __fastcall idPlayer::GetFocusTracker(idPlayer *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return (int)&presentable->GetPlayerInterface_2(this: presentable)->focusTracker;
  else
    return 47160;
}


// ========================================================================
// ?SetInInteractionView@idPlayer@@QAAX_N@Z
// EA  : 0x829F09E8
// RVA : 0x009F09E8
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::SetInInteractionView(idPlayer *this, bool inView)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    presentable->GetPlayerInterface_2(this: presentable)->inInteractionView = inView;
  else
    MEMORY[0xB813] = inView;
}


// ========================================================================
// ?GetNoclip@idPlayer@@QBA_NXZ
// EA  : 0x82A37E58
// RVA : 0x00A37E58
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

BOOL __fastcall idPlayer::GetNoclip(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v2 = 0;
  return (*(_BYTE *)(v2 + 47032) & 0x20) != 0;
}


// ========================================================================
// ?SetNoclip@idPlayer@@QAAX_N@Z
// EA  : 0x82A50A28
// RVA : 0x00A50A28
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::SetNoclip(idPlayer *this, bool v)
{
  idPresentable *presentable; // r3
  int v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  *(_BYTE *)(v4 + 47032) = (32 * v) & 0x20 | *(_BYTE *)(v4 + 47032) & 0xDF;
}


// ========================================================================
// ?GetFocusEntity@idPlayer@@QBAPAVidEntity@@XZ
// EA  : 0x82AD2608
// RVA : 0x00AD2608
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idEntity *__fastcall idPlayer::GetFocusEntity(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v2; // r3
  int v3; // r8
  idEntity *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v2 = 0;
  v3 = *(_DWORD *)(v2 + 47236);
  if ( gameLocal->spawnIds.ptr[v3 & 0x1FFF] == v3 >> 13 && (v4 = gameLocal->entities.ptr[v3 & 0x1FFF]) != nullptr )
    return idEntity::CastTo(c: v4);
  else
    return nullptr;
}


// ========================================================================
// ?GetFocusFriendly@idPlayer@@QBA_NXZ
// EA  : 0x82B80658
// RVA : 0x00B80658
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

int __fastcall idPlayer::GetFocusFriendly(idPlayer *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetPlayerInterface_2(this: presentable)->focusTracker.overFriendly;
  else
    return MEMORY[0xBA48];
}


// ========================================================================
// ?GetControlCamera@idPlayer@@QBAPAVidEntity@@XZ
// EA  : 0x82BF38E8
// RVA : 0x00BF38E8
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idCamera *__fastcall idPlayer::GetControlCamera(idPlayer *this)
{
  int value; // r10
  idCamera *v2; // r3

  value = this->controlledCameraEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idCamera *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idCamera::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?IsLocallyControlled@idPlayer@@QBA_NXZ
// EA  : 0x82BF7920
// RVA : 0x00BF7920
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

BOOL __fastcall idPlayer::IsLocallyControlled(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v2 = 0;
  return (*(bool (__fastcall **)(int))(*(_DWORD *)v2 + 300))(a1: v2);
}


// ========================================================================
// ?GetUCmdTracker2@idPlayer@@QAAAAVidUCmdTracker@@XZ
// EA  : 0x82C4B308
// RVA : 0x00C4B308
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

int __fastcall idPlayer::GetUCmdTracker2(idPlayer *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return (int)&presentable->GetPlayerInterface_2(this: presentable)->ucmdTracker2;
  else
    return 46244;
}


// ========================================================================
// ?GetBobCycle@idPlayer@@QAAAAVidBobCycle@@XZ
// EA  : 0x82C4B368
// RVA : 0x00C4B368
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

int __fastcall idPlayer::GetBobCycle(idPlayer *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return (int)&presentable->GetPlayerInterface_2(this: presentable)->bobCycle;
  else
    return 45664;
}


// ========================================================================
// ?GetPlayerHud@idPlayer@@QAAAAVidPlayerHud@@XZ
// EA  : 0x82C9B528
// RVA : 0x00C9B528
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

int __fastcall idPlayer::GetPlayerHud(idPlayer *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return (int)&presentable->GetPlayerInterface_2(this: presentable)->playerHud;
  else
    return 35096;
}


// ========================================================================
// ?GetFocusUsable@idPlayer@@QBAPAVidEntity@@XZ
// EA  : 0x82CA2B38
// RVA : 0x00CA2B38
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idEntity *__fastcall idPlayer::GetFocusUsable(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v2; // r3
  int v3; // r8
  idEntity *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v2 = 0;
  v3 = *(_DWORD *)(v2 + 47232);
  if ( gameLocal->spawnIds.ptr[v3 & 0x1FFF] == v3 >> 13 && (v4 = gameLocal->entities.ptr[v3 & 0x1FFF]) != nullptr )
    return idEntity::CastTo(c: v4);
  else
    return nullptr;
}


// ========================================================================
// ?GetInventoryGuiActive@idPlayer@@QAA_NXZ
// EA  : 0x82CCBF00
// RVA : 0x00CCBF00
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

BOOL __fastcall idPlayer::GetInventoryGuiActive(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v2 = nullptr;
  return idPresentablePlayer::GuiIsActive(this: v2, g: GUI_INVENTORY);
}


// ========================================================================
// ?GetShowDeadBody@idPlayer@@QAA_NXZ
// EA  : 0x82D03568
// RVA : 0x00D03568
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

BOOL __fastcall idPlayer::GetShowDeadBody(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v2 = 0;
  return (*(_BYTE *)(v2 + 47033) & 0x20) != 0;
}


// ========================================================================
// ?GetUCmdTracker1@idPlayer@@QAAAAVidUCmdTracker@@XZ
// EA  : 0x82DF6230
// RVA : 0x00DF6230
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

int __fastcall idPlayer::GetUCmdTracker1(idPlayer *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return (int)&presentable->GetPlayerInterface_2(this: presentable)->ucmdTracker1;
  else
    return 45960;
}


// ========================================================================
// ?ClearSpacialAnalysis@idPlayerBehaviorContextualLadder@idPlayer@@QAAXXZ
// EA  : 0x82E24B78
// RVA : 0x00E24B78
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::idPlayerBehaviorContextualLadder::ClearSpacialAnalysis(
        idPlayer::idPlayerBehaviorContextualLadder *this)
{
  this->testForward.bDisabled = false;
  this->testForward.bDetectedLadder = false;
  this->testForward.bDetectedLadderTop = false;
  this->testForward.point = vec3_origin;
  this->testForward.normal = vec3_origin;
  this->testForward.surfaceFlags = 0;
  this->testBackward.bDisabled = false;
  this->testBackward.bDetectedLadder = false;
  this->testBackward.bDetectedLadderTop = false;
  this->testBackward.point = vec3_origin;
  this->testBackward.normal = vec3_origin;
  this->testBackward.surfaceFlags = 0;
  this->testRight.bDisabled = false;
  this->testRight.bDetectedLadder = false;
  this->testRight.bDetectedLadderTop = false;
  this->testRight.point = vec3_origin;
  this->testRight.normal = vec3_origin;
  this->testRight.surfaceFlags = 0;
  this->testLeft.bDisabled = false;
  this->testLeft.bDetectedLadder = false;
  this->testLeft.bDetectedLadderTop = false;
  this->testLeft.point = vec3_origin;
  this->testLeft.normal = vec3_origin;
  this->testLeft.surfaceFlags = 0;
  this->testTop.bDisabled = false;
  this->testTop.bDetectedLadder = false;
  this->testTop.bDetectedLadderTop = false;
  this->testTop.point = vec3_origin;
  this->testTop.normal = vec3_origin;
  this->testTop.surfaceFlags = 0;
  this->testBottom.bDisabled = false;
  this->testBottom.bDetectedLadder = false;
  this->testBottom.bDetectedLadderTop = false;
  this->testBottom.point = vec3_origin;
  this->testBottom.normal = vec3_origin;
  this->testBottom.surfaceFlags = 0;
  this->ladderNormal = vec3_origin;
  this->ladderUp = vec3_origin;
  this->ladderRight = vec3_origin;
  this->groundDist = 1000.0;
  this->ceilingDist = 1000.0;
}


// ========================================================================
// ?GetPhysicsObj@idPlayer@@QAAAAVidPhysics_Player@@XZ
// EA  : 0x82E24D78
// RVA : 0x00E24D78
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

int __fastcall idPlayer::GetPhysicsObj(idPlayer *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return (int)&presentable->GetPlayerInterface_2(this: presentable)->physicsObj;
  else
    return 36264;
}


// ========================================================================
// ?GetIsSprinting@idPlayer@@QBA_NXZ
// EA  : 0x82E24DD8
// RVA : 0x00E24DD8
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

int __fastcall idPlayer::GetIsSprinting(idPlayer *this)
{
  idPresentable *presentable; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    return presentable->GetPlayerInterface_2(this: presentable)->isSprinting;
  else
    return MEMORY[0xB811];
}


// ========================================================================
// ?Clear@idPlayerBehaviorContextualShimmy@idPlayer@@QAAXXZ
// EA  : 0x82E2CF28
// RVA : 0x00E2CF28
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::idPlayerBehaviorContextualShimmy::Clear(idPlayer::idPlayerBehaviorContextualShimmy *this)
{
  this->state = CONTEXTUAL_SHIMMY_STATE_NONE;
  this->currentLedgeBit = -1;
  this->nextLedgeBit = -1;
  this->prevState = CONTEXTUAL_SHIMMY_STATE_NONE;
  this->dismountState = CONTEXTUAL_SHIMMY_STATE_NONE;
  this->bEnabled = true;
  this->initiateInputTime = 0;
  this->legsAlignPos = vec3_origin;
  this->averagedBodyRotationT.hasPMin = false;
  this->averagedBodyRotationT.hasPMax = false;
  this->averagedBodyRotationT.restLength = 0.0;
  this->averagedBodyRotationT.k = 1.0;
  this->averagedBodyRotationT.m = 1.0;
  this->averagedBodyRotationT.c = 2.0;
  this->averagedBodyRotationT.p0.x = 0.0;
  this->averagedBodyRotationT.p1.x = 0.0;
  this->averagedBodyRotationT.vel.x = 0.0;
  this->averagedBodyRotationT.maxSpeed = 0.0;
  this->averagedBodyRotationT.pMin.x = 0.0;
  this->averagedBodyRotationT.pMax.x = 0.0;
  this->fireTimeMS = 0.0;
  this->extraWorldTranslationBlend.hasPMin = false;
  this->extraWorldTranslationBlend.restLength = 0.0;
  this->extraWorldTranslationBlend.hasPMax = false;
  this->extraWorldTranslationBlend.k = 1.0;
  this->extraWorldTranslationBlend.m = 1.0;
  this->extraWorldTranslationBlend.c = 2.0;
  this->extraWorldTranslationBlend.p0.x = 0.0;
  this->extraWorldTranslationBlend.p1.x = 0.0;
  this->extraWorldTranslationBlend.vel.x = 0.0;
  this->extraWorldTranslationBlend.maxSpeed = 0.0;
  this->extraWorldTranslationBlend.pMin.x = 0.0;
  this->extraWorldTranslationBlend.pMax.x = 0.0;
  this->extraWorldRotationBlend.hasPMin = false;
  this->extraWorldRotationBlend.restLength = 0.0;
  this->extraWorldRotationBlend.hasPMax = false;
  this->extraWorldRotationBlend.k = 1.0;
  this->extraWorldRotationBlend.m = 1.0;
  this->extraWorldRotationBlend.c = 2.0;
  this->extraWorldRotationBlend.p0.x = 0.0;
  this->extraWorldRotationBlend.p1.x = 0.0;
  this->extraWorldRotationBlend.vel.x = 0.0;
  this->extraWorldRotationBlend.maxSpeed = 0.0;
  this->extraWorldRotationBlend.pMin.x = 0.0;
  this->extraWorldRotationBlend.pMax.x = 0.0;
  this->nextFidgetTime = 0;
}


// ========================================================================
// ?Clear@idPlayerBehaviorWallClimb@idPlayer@@QAAXXZ
// EA  : 0x82E2D028
// RVA : 0x00E2D028
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::idPlayerBehaviorWallClimb::Clear(idPlayer::idPlayerBehaviorWallClimb *this)
{
  this->bodyRotationAnimAliasHandles[0].value = -1;
  this->bodyRotationAnimAliasHandles[1].value = -1;
  this->bodyRotationAnimAliasHandles[2].value = -1;
  this->state = WALLCLIMB_STATE_NONE;
  this->bEnabled = true;
  this->legsAlignPos = vec3_origin;
  this->sidewaysPosition = 0.0;
  this->averagedBodyRotationT.hasPMin = false;
  this->averagedBodyRotationT.restLength = 0.0;
  this->averagedBodyRotationT.hasPMax = false;
  this->averagedBodyRotationT.k = 1.0;
  this->averagedBodyRotationT.m = 1.0;
  this->averagedBodyRotationT.c = 2.0;
  this->averagedBodyRotationT.p0.x = 0.0;
  this->averagedBodyRotationT.p1.x = 0.0;
  this->averagedBodyRotationT.vel.x = 0.0;
  this->averagedBodyRotationT.maxSpeed = 0.0;
  this->averagedBodyRotationT.pMin.x = 0.0;
  this->averagedBodyRotationT.pMax.x = 0.0;
  this->extraWorldTranslationBlend.hasPMin = false;
  this->extraWorldTranslationBlend.restLength = 0.0;
  this->extraWorldTranslationBlend.hasPMax = false;
  this->extraWorldTranslationBlend.k = 1.0;
  this->extraWorldTranslationBlend.m = 1.0;
  this->extraWorldTranslationBlend.c = 2.0;
  this->extraWorldTranslationBlend.p0.x = 0.0;
  this->extraWorldTranslationBlend.p1.x = 0.0;
  this->extraWorldTranslationBlend.vel.x = 0.0;
  this->extraWorldTranslationBlend.maxSpeed = 0.0;
  this->extraWorldTranslationBlend.pMin.x = 0.0;
  this->extraWorldTranslationBlend.pMax.x = 0.0;
  this->extraWorldRotationBlend.hasPMin = false;
  this->extraWorldRotationBlend.restLength = 0.0;
  this->extraWorldRotationBlend.hasPMax = false;
  this->extraWorldRotationBlend.k = 1.0;
  this->extraWorldRotationBlend.m = 1.0;
  this->extraWorldRotationBlend.c = 2.0;
  this->extraWorldRotationBlend.p0.x = 0.0;
  this->extraWorldRotationBlend.p1.x = 0.0;
  this->extraWorldRotationBlend.vel.x = 0.0;
  this->extraWorldRotationBlend.maxSpeed = 0.0;
  this->extraWorldRotationBlend.pMin.x = 0.0;
  this->extraWorldRotationBlend.pMax.x = 0.0;
  this->sideWaysTranslationBlend.hasPMin = false;
  this->sideWaysTranslationBlend.restLength = 0.0;
  this->sideWaysTranslationBlend.hasPMax = false;
  this->sideWaysTranslationBlend.k = 1.0;
  this->sideWaysTranslationBlend.m = 1.0;
  this->sideWaysTranslationBlend.c = 2.0;
  this->sideWaysTranslationBlend.p0.x = 0.0;
  this->sideWaysTranslationBlend.p1.x = 0.0;
  this->sideWaysTranslationBlend.vel.x = 0.0;
  this->sideWaysTranslationBlend.maxSpeed = 0.0;
  this->sideWaysTranslationBlend.pMin.x = 0.0;
  this->sideWaysTranslationBlend.pMax.x = 0.0;
  this->nextFidgetTime = 0;
}


// ========================================================================
// ?Clear@idPlayerBehaviorSprintSlide@idPlayer@@QAAXXZ
// EA  : 0x82E2D150
// RVA : 0x00E2D150
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::idPlayerBehaviorSprintSlide::Clear(idPlayer::idPlayerBehaviorSprintSlide *this)
{
  this->state = SPRINT_SLIDE_STATE_NONE;
  this->startSlide = false;
  this->endSlide = false;
  this->forwardDir = vec3_origin;
  this->forceEndSlide = false;
  this->bEnabled = true;
  this->forwardSpeed = 0.0;
  this->bodyRotationPos.restLength = 0.0;
  this->bodyRotationPos.p0.y = 0.0;
  this->bodyRotationPos.p0.x = 0.0;
  this->bodyRotationPos.k = 1.0;
  this->bodyRotationPos.m = 1.0;
  this->bodyRotationPos.c = 2.0;
  this->bodyRotationPos.p1.y = 0.0;
  this->bodyRotationPos.p1.x = 0.0;
  this->bodyRotationPos.vel.y = 0.0;
  this->bodyRotationPos.vel.x = 0.0;
  this->bodyRotationPos.maxSpeed = 0.0;
  this->bodyRotationPos.pMin.y = 0.0;
  this->bodyRotationPos.pMin.x = 0.0;
  this->bodyRotationPos.hasPMin = false;
  this->bodyRotationPos.pMax.y = 0.0;
  this->bodyRotationPos.pMax.x = 0.0;
  this->bodyRotationPos.hasPMax = false;
  this->bodyRotationAlpha.restLength = 0.0;
  this->bodyRotationAlpha.hasPMin = false;
  this->bodyRotationAlpha.k = 1.0;
  this->bodyRotationAlpha.hasPMax = false;
  this->bodyRotationAlpha.m = 1.0;
  this->bodyRotationAlpha.c = 2.0;
  this->bodyRotationAlpha.p0.x = 0.0;
  this->bodyRotationAlpha.p1.x = 0.0;
  this->bodyRotationAlpha.vel.x = 0.0;
  this->bodyRotationAlpha.maxSpeed = 0.0;
  this->bodyRotationAlpha.pMin.x = 0.0;
  this->bodyRotationAlpha.pMax.x = 0.0;
  this->handsDeferredSave = false;
  this->legsDeferredSave = false;
  this->maxSpeed = 500.0;
  this->springCamForceCalculateViewStageSave = STAGE_DEFAULT;
  this->friction = 0.0;
  this->inhibitFlagsSave = UCMD_INHIBIT_NONE;
  this->walkFrictionSave = 0.0;
  this->slideStartTime = 0;
  this->legsFwdDirSpring.restLength = 0.0;
  this->legsFwdDirSpring.k = 1.0;
  this->legsFwdDirSpring.m = 1.0;
  this->legsFwdDirSpring.c = 2.0;
  this->legsFwdDirSpring.p0.z = 0.0;
  this->legsFwdDirSpring.p0.y = 0.0;
  this->legsFwdDirSpring.p0.x = 0.0;
  this->legsFwdDirSpring.p1.z = 0.0;
  this->legsFwdDirSpring.p1.y = 0.0;
  this->legsFwdDirSpring.p1.x = 0.0;
  this->legsFwdDirSpring.vel.z = 0.0;
  this->legsFwdDirSpring.vel.y = 0.0;
  this->legsFwdDirSpring.vel.x = 0.0;
  this->legsFwdDirSpring.maxSpeed = 0.0;
  this->legsFwdDirSpring.pMin.z = 0.0;
  this->legsFwdDirSpring.pMin.y = 0.0;
  this->legsFwdDirSpring.pMin.x = 0.0;
  this->legsFwdDirSpring.hasPMin = false;
  this->legsFwdDirSpring.pMax.z = 0.0;
  this->legsFwdDirSpring.pMax.y = 0.0;
  this->legsFwdDirSpring.pMax.x = 0.0;
  this->legsFwdDirSpring.hasPMax = false;
  this->playLoopingSlideSound = false;
  this->loopingSlideSound = nullptr;
}


// ========================================================================
// ?Clear@idPlayerBehaviorLean@idPlayer@@QAAXXZ
// EA  : 0x82E2D2B0
// RVA : 0x00E2D2B0
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::idPlayerBehaviorLean::Clear(idPlayer::idPlayerBehaviorLean *this)
{
  this->state = LEAN_STATE_NONE;
  this->leanOffset.restLength = 0.0;
  this->leanOffset.k = 1.0;
  this->leanOffset.m = 1.0;
  this->leanOffset.p0.z = 0.0;
  this->leanOffset.p0.y = 0.0;
  this->leanOffset.p0.x = 0.0;
  this->leanOffset.c = 2.0;
  this->leanOffset.p1.z = 0.0;
  this->leanOffset.p1.y = 0.0;
  this->leanOffset.p1.x = 0.0;
  this->leanOffset.vel.z = 0.0;
  this->leanOffset.vel.y = 0.0;
  this->leanOffset.vel.x = 0.0;
  this->leanOffset.maxSpeed = 0.0;
  this->leanOffset.pMin.z = 0.0;
  this->leanOffset.pMin.y = 0.0;
  this->leanOffset.pMin.x = 0.0;
  this->leanOffset.hasPMin = false;
  this->leanOffset.pMax.z = 0.0;
  this->leanOffset.pMax.y = 0.0;
  this->leanOffset.pMax.x = 0.0;
  this->leanOffset.hasPMax = false;
  this->rollOffset.restLength = 0.0;
  this->rollOffset.hasPMin = false;
  this->rollOffset.k = 1.0;
  this->rollOffset.hasPMax = false;
  this->rollOffset.m = 1.0;
  this->rollOffset.c = 2.0;
  this->rollOffset.p0.x = 0.0;
  this->rollOffset.p1.x = 0.0;
  this->rollOffset.vel.x = 0.0;
  this->rollOffset.maxSpeed = 0.0;
  this->rollOffset.pMin.x = 0.0;
  this->rollOffset.pMax.x = 0.0;
  this->startLean = false;
  this->maxLeanDistLeft = 0.0;
  this->endLean = false;
  this->maxLeanDistRight = 0.0;
  this->maxLeanDistUp = 0.0;
  this->forwardDir = vec3_origin;
  this->forceEndLean = false;
  this->bEnabled = true;
  this->springCamForceCalculateViewStageSave = STAGE_DEFAULT;
  this->leanStartTime = 0;
}


// ========================================================================
// ?Clear@idPlayerBehaviorContextualLadder@idPlayer@@QAAXXZ
// EA  : 0x82E2D3A8
// RVA : 0x00E2D3A8
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::idPlayerBehaviorContextualLadder::Clear(idPlayer::idPlayerBehaviorContextualLadder *this)
{
  unsigned __int64 v1; // r30

  LODWORD(v1) = 0;
  this->state = CONTEXTUAL_LADDER_STATE_NONE;
  this->prevState = CONTEXTUAL_LADDER_STATE_NONE;
  this->dismountType = CONTEXTUAL_LADDER_DISMOUNT_TYPE_NONE;
  this->bEnabled = true;
  this->initiateInputTime = 0;
  idPlayer::idPlayerBehaviorContextualLadder::ClearSpacialAnalysis(this);
  this->handsAlignPos = vec3_origin;
  this->legsAlignPos = vec3_origin;
  this->prevPlayerMovementPos = vec3_origin;
  this->prevPlayerMovementAngles = ang_zero;
  this->prevPlayerDeltaZ = 0.0;
  this->averagedBodyRotationT.restLength = 0.0;
  this->averagedBodyRotationT.k = 1.0;
  this->averagedBodyRotationT.m = 1.0;
  this->averagedBodyRotationT.c = 2.0;
  this->averagedBodyRotationT.p0.y = 0.0;
  this->averagedBodyRotationT.p0.x = 0.0;
  this->averagedBodyRotationT.p1.y = 0.0;
  this->averagedBodyRotationT.p1.x = 0.0;
  this->averagedBodyRotationT.vel.y = 0.0;
  this->averagedBodyRotationT.vel.x = 0.0;
  this->averagedBodyRotationT.maxSpeed = 0.0;
  this->averagedBodyRotationT.pMin.y = 0.0;
  this->averagedBodyRotationT.pMin.x = 0.0;
  this->averagedBodyRotationT.hasPMin = false;
  this->averagedBodyRotationT.pMax.y = 0.0;
  this->averagedBodyRotationT.pMax.x = 0.0;
  this->averagedBodyRotationT.hasPMax = false;
  this->canMountTime = 0;
  this->speedScaleSpring.restLength = 0.0;
  this->speedScaleSpring.k = 1.0;
  this->speedScaleSpring.hasPMin = false;
  this->speedScaleSpring.m = 1.0;
  this->speedScaleSpring.hasPMax = false;
  this->speedScaleSpring.c = 2.0;
  this->speedScaleSpring.p0.x = 0.0;
  this->speedScaleSpring.p1.x = 0.0;
  this->speedScaleSpring.vel.x = 0.0;
  this->speedScaleSpring.maxSpeed = 0.0;
  this->speedScaleSpring.pMin.x = 0.0;
  this->speedScaleSpring.pMax.x = 0.0;
  this->speedScaleSpring.p1.x = 1.0;
  this->speedScaleSpring.p0.x = 1.0;
  this->ladderClipQuery.index = v1;
  this->invertInput = false;
  this->blockClimpOffAtTop = false;
}


// ========================================================================
// ??0idPlayerBehaviorWallClimb@idPlayer@@QAA@XZ
// EA  : 0x82E30A10
// RVA : 0x00E30A10
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idPlayer::idPlayerBehaviorWallClimb *__fastcall idPlayer::idPlayerBehaviorWallClimb::idPlayerBehaviorWallClimb(
        idPlayer::idPlayerBehaviorWallClimb *this)
{
  this->wallClimb.spawnId.value = 0x1FFF;
  this->bodyRotationAnimAliasHandles[0].value = -1;
  this->bodyRotationAnimAliasHandles[1].value = -1;
  this->bodyRotationAnimAliasHandles[2].value = -1;
  this->averagedBodyRotationT.restLength = 0.0;
  this->averagedBodyRotationT.k = 1.0;
  this->averagedBodyRotationT.hasPMin = false;
  this->averagedBodyRotationT.m = 1.0;
  this->averagedBodyRotationT.hasPMax = false;
  this->averagedBodyRotationT.c = 2.0;
  this->averagedBodyRotationT.p0.x = 0.0;
  this->averagedBodyRotationT.p1.x = 0.0;
  this->averagedBodyRotationT.vel.x = 0.0;
  this->averagedBodyRotationT.maxSpeed = 0.0;
  this->averagedBodyRotationT.pMin.x = 0.0;
  this->averagedBodyRotationT.pMax.x = 0.0;
  this->extraWorldTranslationBlend.hasPMin = false;
  this->extraWorldTranslationBlend.restLength = 0.0;
  this->extraWorldTranslationBlend.hasPMax = false;
  this->extraWorldTranslationBlend.k = 1.0;
  this->extraWorldTranslationBlend.m = 1.0;
  this->extraWorldTranslationBlend.c = 2.0;
  this->extraWorldTranslationBlend.p0.x = 0.0;
  this->extraWorldTranslationBlend.p1.x = 0.0;
  this->extraWorldTranslationBlend.vel.x = 0.0;
  this->extraWorldTranslationBlend.maxSpeed = 0.0;
  this->extraWorldTranslationBlend.pMin.x = 0.0;
  this->extraWorldTranslationBlend.pMax.x = 0.0;
  this->extraWorldRotationBlend.hasPMin = false;
  this->extraWorldRotationBlend.restLength = 0.0;
  this->extraWorldRotationBlend.hasPMax = false;
  this->extraWorldRotationBlend.k = 1.0;
  this->extraWorldRotationBlend.m = 1.0;
  this->extraWorldRotationBlend.c = 2.0;
  this->extraWorldRotationBlend.p0.x = 0.0;
  this->extraWorldRotationBlend.p1.x = 0.0;
  this->extraWorldRotationBlend.vel.x = 0.0;
  this->extraWorldRotationBlend.maxSpeed = 0.0;
  this->extraWorldRotationBlend.pMin.x = 0.0;
  this->extraWorldRotationBlend.pMax.x = 0.0;
  this->sideWaysTranslationBlend.hasPMin = false;
  this->sideWaysTranslationBlend.restLength = 0.0;
  this->sideWaysTranslationBlend.hasPMax = false;
  this->sideWaysTranslationBlend.k = 1.0;
  this->sideWaysTranslationBlend.m = 1.0;
  this->sideWaysTranslationBlend.c = 2.0;
  this->sideWaysTranslationBlend.p0.x = 0.0;
  this->sideWaysTranslationBlend.p1.x = 0.0;
  this->sideWaysTranslationBlend.vel.x = 0.0;
  this->sideWaysTranslationBlend.maxSpeed = 0.0;
  this->sideWaysTranslationBlend.pMin.x = 0.0;
  this->sideWaysTranslationBlend.pMax.x = 0.0;
  idPlayer::idPlayerBehaviorWallClimb::Clear(this);
  return this;
}


// ========================================================================
// ?Init@idPlayerBehaviorSprintSlide@idPlayer@@QAAXXZ
// EA  : 0x82E30B38
// RVA : 0x00E30B38
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::idPlayerBehaviorSprintSlide::Init(idPlayer::idPlayerBehaviorSprintSlide *this)
{
  double valueFloat; // fp13

  this->additiveAnimAlphaMin = 0.0;
  this->additiveAnimAlphaMax = 1.0;
  this->additiveAnimAlphaMinSpeed = 0.0;
  this->additiveAnimAlphaMaxSpeed = pm_sprintspeed.valueFloat;
  this->cameraShakeMax = 0.0049999999;
  this->cameraShakeMin = 0.0;
  this->cameraShakeMinSpeed = 0.0;
  valueFloat = pm_sprintspeed.valueFloat;
  this->slideSounds = nullptr;
  this->cameraShakeMaxSpeed = valueFloat;
  this->sndSlideMinVolume = -40.0;
  this->sndSlideMaxVolume = -5.0;
  this->sndSlideMinVolumeSpeed = 0.0;
  this->sndSlideMaxVolumeSpeed = 200.0;
  this->bodyRotationAnimWeights[0] = 0.0;
  this->bodyRotationAnimWeights[1] = 0.0;
  this->bodyRotationAnimWeights[2] = 0.0;
  this->bodyRotationAnimWeights[3] = 0.0;
  this->bodyRotationAnimWeights[4] = 0.0;
  *(_DWORD *)&this->bodyRotationLegsAnimAliasHandles[0].value = -1;
  *(_DWORD *)&this->bodyRotationLegsAnimAliasHandles[2].value = -1;
  this->bodyRotationLegsAnimAliasHandles[4].value = -1;
  idPlayer::idPlayerBehaviorSprintSlide::Clear(this);
}


// ========================================================================
// ??0idPlayerBehaviorLean@idPlayer@@QAA@XZ
// EA  : 0x82E30BD8
// RVA : 0x00E30BD8
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idPlayer::idPlayerBehaviorLean *__fastcall idPlayer::idPlayerBehaviorLean::idPlayerBehaviorLean(
        idPlayer::idPlayerBehaviorLean *this)
{
  this->leanOffset.restLength = 0.0;
  this->leanOffset.k = 1.0;
  this->leanOffset.m = 1.0;
  this->leanOffset.c = 2.0;
  this->leanOffset.p0.z = 0.0;
  this->leanOffset.p0.y = 0.0;
  this->leanOffset.p0.x = 0.0;
  this->leanOffset.p1.z = 0.0;
  this->leanOffset.p1.y = 0.0;
  this->leanOffset.p1.x = 0.0;
  this->leanOffset.vel.z = 0.0;
  this->leanOffset.vel.y = 0.0;
  this->leanOffset.vel.x = 0.0;
  this->leanOffset.maxSpeed = 0.0;
  this->leanOffset.pMin.z = 0.0;
  this->leanOffset.pMin.y = 0.0;
  this->leanOffset.pMin.x = 0.0;
  this->leanOffset.hasPMin = false;
  this->leanOffset.pMax.z = 0.0;
  this->leanOffset.pMax.y = 0.0;
  this->leanOffset.pMax.x = 0.0;
  this->leanOffset.hasPMax = false;
  this->rollOffset.restLength = 0.0;
  this->rollOffset.hasPMin = false;
  this->rollOffset.k = 1.0;
  this->rollOffset.hasPMax = false;
  this->rollOffset.m = 1.0;
  this->rollOffset.c = 2.0;
  this->rollOffset.p0.x = 0.0;
  this->rollOffset.p1.x = 0.0;
  this->rollOffset.vel.x = 0.0;
  this->rollOffset.maxSpeed = 0.0;
  this->rollOffset.pMin.x = 0.0;
  this->rollOffset.pMax.x = 0.0;
  idPlayer::idPlayerBehaviorLean::Clear(this);
  return this;
}


// ========================================================================
// ?Init@idPlayerBehaviorContextualLadder@idPlayer@@QAAXXZ
// EA  : 0x82E30CB0
// RVA : 0x00E30CB0
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::idPlayerBehaviorContextualLadder::Init(idPlayer::idPlayerBehaviorContextualLadder *this)
{
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v2; // r10
  int i; // ctr
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v4; // r10
  int j; // ctr

  idPlayer::idPlayerBehaviorContextualLadder::Clear(this);
  v2 = &this->armsRotationAnimAliasHandles[4];
  for ( i = 5; i != 0; --i )
  {
    v2[-4].value = -1;
    ++v2;
    v2->value = -1;
  }
  v4 = &this->legsAliases[22];
  for ( j = 23; j != 0; --j )
  {
    v4[-22].value = -1;
    ++v4;
    v4->value = -1;
  }
}


// ========================================================================
// ?Clear@idPlayerBehaviors@idPlayer@@QAAXXZ
// EA  : 0x82E30D18
// RVA : 0x00E30D18
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::idPlayerBehaviors::Clear(idPlayer::idPlayerBehaviors *this)
{
  this->shared.thirdPersonHandsFlags = 0;
  this->shared.thirdPersonLegsFlags = 0;
  this->shared.sharedFlags = 0;
  this->shared.deltaTransExternalWorld = vec3_origin;
  this->shared.deltaTransScale.x = 1.0;
  this->shared.deltaTransScale.y = 1.0;
  this->shared.deltaTransScale.z = 1.0;
  idPlayer::idPlayerBehaviorContextualShimmy::Clear(this: &this->contextualShimmy);
  idPlayer::idPlayerBehaviorWallClimb::Clear(this: &this->wallClimb);
  idPlayer::idPlayerBehaviorSprintSlide::Clear(this: &this->sprintSlide);
  idPlayer::idPlayerBehaviorContextualLadder::Clear(this: &this->contextualLadder);
  idPlayer::idPlayerBehaviorLean::Clear(this: &this->lean);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animDeltasTrans);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animDeltasRot);
}


// ========================================================================
// ??0idPlayerBehaviorContextualShimmy@idPlayer@@QAA@XZ
// EA  : 0x82E31EF8
// RVA : 0x00E31EF8
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idPlayer::idPlayerBehaviorContextualShimmy *__fastcall idPlayer::idPlayerBehaviorContextualShimmy::idPlayerBehaviorContextualShimmy(
        idPlayer::idPlayerBehaviorContextualShimmy *this)
{
  this->ledge.spawnId.value = 0x1FFF;
  this->useLedge.spawnId.value = 0x1FFF;
  this->averagedBodyRotationT.hasPMin = false;
  this->averagedBodyRotationT.hasPMax = false;
  this->averagedBodyRotationT.restLength = 0.0;
  this->averagedBodyRotationT.k = 1.0;
  this->averagedBodyRotationT.m = 1.0;
  this->averagedBodyRotationT.c = 2.0;
  this->averagedBodyRotationT.p0.x = 0.0;
  this->averagedBodyRotationT.p1.x = 0.0;
  this->averagedBodyRotationT.vel.x = 0.0;
  this->averagedBodyRotationT.maxSpeed = 0.0;
  this->averagedBodyRotationT.pMin.x = 0.0;
  this->averagedBodyRotationT.pMax.x = 0.0;
  this->bodyRotationAnimAliasHandles[0].value = -1;
  this->bodyRotationAnimAliasHandles[1].value = -1;
  this->bodyRotationAnimAliasHandles[2].value = -1;
  this->extraWorldTranslationBlend.restLength = 0.0;
  this->extraWorldTranslationBlend.k = 1.0;
  this->extraWorldTranslationBlend.hasPMin = false;
  this->extraWorldTranslationBlend.m = 1.0;
  this->extraWorldTranslationBlend.hasPMax = false;
  this->extraWorldTranslationBlend.c = 2.0;
  this->extraWorldTranslationBlend.p0.x = 0.0;
  this->extraWorldTranslationBlend.p1.x = 0.0;
  this->extraWorldTranslationBlend.vel.x = 0.0;
  this->extraWorldTranslationBlend.maxSpeed = 0.0;
  this->extraWorldTranslationBlend.pMin.x = 0.0;
  this->extraWorldTranslationBlend.pMax.x = 0.0;
  this->extraWorldRotationBlend.hasPMin = false;
  this->extraWorldRotationBlend.restLength = 0.0;
  this->extraWorldRotationBlend.hasPMax = false;
  this->extraWorldRotationBlend.k = 1.0;
  this->extraWorldRotationBlend.m = 1.0;
  this->extraWorldRotationBlend.c = 2.0;
  this->extraWorldRotationBlend.p0.x = 0.0;
  this->extraWorldRotationBlend.p1.x = 0.0;
  this->extraWorldRotationBlend.vel.x = 0.0;
  this->extraWorldRotationBlend.maxSpeed = 0.0;
  this->extraWorldRotationBlend.pMin.x = 0.0;
  this->extraWorldRotationBlend.pMax.x = 0.0;
  idPlayer::idPlayerBehaviorContextualShimmy::Clear(this);
  this->bodyRotationAnimAliasHandles[0].value = -1;
  this->bodyRotationAnimAliasHandles[1].value = -1;
  this->bodyRotationAnimAliasHandles[2].value = -1;
  return this;
}


// ========================================================================
// ??0idPlayerBehaviorSprintSlide@idPlayer@@QAA@XZ
// EA  : 0x82E32010
// RVA : 0x00E32010
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idPlayer::idPlayerBehaviorSprintSlide *__fastcall idPlayer::idPlayerBehaviorSprintSlide::idPlayerBehaviorSprintSlide(
        idPlayer::idPlayerBehaviorSprintSlide *this)
{
  this->legsFwdDirSpring.restLength = 0.0;
  this->legsFwdDirSpring.p0.z = 0.0;
  this->legsFwdDirSpring.p0.y = 0.0;
  this->legsFwdDirSpring.p0.x = 0.0;
  this->legsFwdDirSpring.k = 1.0;
  this->legsFwdDirSpring.m = 1.0;
  this->legsFwdDirSpring.c = 2.0;
  this->legsFwdDirSpring.p1.z = 0.0;
  this->legsFwdDirSpring.p1.y = 0.0;
  this->legsFwdDirSpring.p1.x = 0.0;
  this->legsFwdDirSpring.vel.z = 0.0;
  this->legsFwdDirSpring.vel.y = 0.0;
  this->legsFwdDirSpring.vel.x = 0.0;
  this->legsFwdDirSpring.maxSpeed = 0.0;
  this->legsFwdDirSpring.pMin.z = 0.0;
  this->legsFwdDirSpring.pMin.y = 0.0;
  this->legsFwdDirSpring.pMin.x = 0.0;
  this->legsFwdDirSpring.hasPMin = false;
  this->legsFwdDirSpring.pMax.z = 0.0;
  this->legsFwdDirSpring.pMax.y = 0.0;
  this->legsFwdDirSpring.pMax.x = 0.0;
  this->legsFwdDirSpring.hasPMax = false;
  this->bodyRotationPos.restLength = 0.0;
  this->bodyRotationPos.k = 1.0;
  this->bodyRotationPos.m = 1.0;
  this->bodyRotationPos.c = 2.0;
  this->bodyRotationPos.p0.y = 0.0;
  this->bodyRotationPos.p0.x = 0.0;
  this->bodyRotationPos.p1.y = 0.0;
  this->bodyRotationPos.p1.x = 0.0;
  this->bodyRotationPos.vel.y = 0.0;
  this->bodyRotationPos.vel.x = 0.0;
  this->bodyRotationPos.maxSpeed = 0.0;
  this->bodyRotationPos.pMin.y = 0.0;
  this->bodyRotationPos.pMin.x = 0.0;
  this->bodyRotationPos.hasPMin = false;
  this->bodyRotationPos.pMax.y = 0.0;
  this->bodyRotationPos.pMax.x = 0.0;
  this->bodyRotationPos.hasPMax = false;
  this->bodyRotationAlpha.restLength = 0.0;
  this->bodyRotationAlpha.hasPMin = false;
  this->bodyRotationAlpha.k = 1.0;
  this->bodyRotationAlpha.hasPMax = false;
  this->bodyRotationAlpha.m = 1.0;
  this->bodyRotationAlpha.c = 2.0;
  this->bodyRotationAlpha.p0.x = 0.0;
  this->bodyRotationAlpha.p1.x = 0.0;
  this->bodyRotationAlpha.vel.x = 0.0;
  this->bodyRotationAlpha.maxSpeed = 0.0;
  this->bodyRotationAlpha.pMin.x = 0.0;
  this->bodyRotationAlpha.pMax.x = 0.0;
  this->bodyRotationLegsAnimAliasHandles[0].value = -1;
  this->bodyRotationLegsAnimAliasHandles[1].value = -1;
  this->bodyRotationLegsAnimAliasHandles[2].value = -1;
  this->bodyRotationLegsAnimAliasHandles[3].value = -1;
  this->bodyRotationLegsAnimAliasHandles[4].value = -1;
  idPlayer::idPlayerBehaviorSprintSlide::Init(this);
  return this;
}


// ========================================================================
// ??0idPlayerBehaviorContextualLadder@idPlayer@@QAA@XZ
// EA  : 0x82E32160
// RVA : 0x00E32160
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idPlayer::idPlayerBehaviorContextualLadder *__fastcall idPlayer::idPlayerBehaviorContextualLadder::idPlayerBehaviorContextualLadder(
        idPlayer::idPlayerBehaviorContextualLadder *this)
{
  bool *p_invertInput; // r8
  int v3; // ctr
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> *v4; // r10
  int i; // ctr

  this->averagedBodyRotationT.restLength = 0.0;
  this->averagedBodyRotationT.k = 1.0;
  this->averagedBodyRotationT.m = 1.0;
  p_invertInput = &this->invertInput;
  this->averagedBodyRotationT.c = 2.0;
  v3 = 23;
  this->averagedBodyRotationT.p0.y = 0.0;
  this->averagedBodyRotationT.p0.x = 0.0;
  this->averagedBodyRotationT.p1.y = 0.0;
  this->averagedBodyRotationT.p1.x = 0.0;
  this->averagedBodyRotationT.vel.y = 0.0;
  this->averagedBodyRotationT.vel.x = 0.0;
  this->averagedBodyRotationT.maxSpeed = 0.0;
  this->averagedBodyRotationT.pMin.y = 0.0;
  this->averagedBodyRotationT.pMin.x = 0.0;
  this->averagedBodyRotationT.hasPMin = false;
  this->averagedBodyRotationT.pMax.y = 0.0;
  this->averagedBodyRotationT.pMax.x = 0.0;
  this->averagedBodyRotationT.hasPMax = false;
  this->speedScaleSpring.restLength = 0.0;
  this->speedScaleSpring.hasPMin = false;
  this->speedScaleSpring.k = 1.0;
  this->speedScaleSpring.hasPMax = false;
  this->speedScaleSpring.m = 1.0;
  this->speedScaleSpring.c = 2.0;
  this->speedScaleSpring.p0.x = 0.0;
  this->speedScaleSpring.p1.x = 0.0;
  this->speedScaleSpring.vel.x = 0.0;
  this->speedScaleSpring.maxSpeed = 0.0;
  this->speedScaleSpring.pMin.x = 0.0;
  this->speedScaleSpring.pMax.x = 0.0;
  this->ladderClipQuery.index = 0x1700000000LL;
  do
  {
    p_invertInput += 2;
    *(_WORD *)p_invertInput = -1;
    --v3;
  }
  while ( v3 != 0 );
  v4 = &this->legsAliases[22];
  for ( i = 23; i != 0; --i )
  {
    ++v4;
    v4->value = -1;
  }
  this->armsRotationAnimAliasHandles[0].value = -1;
  this->armsRotationAnimAliasHandles[1].value = -1;
  this->armsRotationAnimAliasHandles[2].value = -1;
  this->armsRotationAnimAliasHandles[3].value = -1;
  this->armsRotationAnimAliasHandles[4].value = -1;
  this->legsRotationAnimAliasHandles[0].value = -1;
  this->legsRotationAnimAliasHandles[1].value = -1;
  this->legsRotationAnimAliasHandles[2].value = -1;
  this->legsRotationAnimAliasHandles[3].value = -1;
  this->legsRotationAnimAliasHandles[4].value = -1;
  idPlayer::idPlayerBehaviorContextualLadder::Init(this);
  return this;
}


// ========================================================================
// ??0idPlayerBehaviors@idPlayer@@QAA@XZ
// EA  : 0x82E32298
// RVA : 0x00E32298
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idPlayer::idPlayerBehaviors *__fastcall idPlayer::idPlayerBehaviors::idPlayerBehaviors(
        idPlayer::idPlayerBehaviors *this)
{
  float *p_z; // r10
  float *p_y; // r11
  int i; // ctr

  this->shared.thirdPersonHandsFlags = 0;
  this->shared.thirdPersonLegsFlags = 0;
  this->shared.sharedFlags = 0;
  this->shared.deltaTransExternalWorld = vec3_origin;
  this->shared.deltaTransScale.x = 1.0;
  this->shared.deltaTransScale.y = 1.0;
  this->shared.deltaTransScale.z = 1.0;
  idPlayer::idPlayerBehaviorContextualShimmy::idPlayerBehaviorContextualShimmy(this: &this->contextualShimmy);
  idPlayer::idPlayerBehaviorWallClimb::idPlayerBehaviorWallClimb(this: &this->wallClimb);
  idPlayer::idPlayerBehaviorSprintSlide::idPlayerBehaviorSprintSlide(this: &this->sprintSlide);
  idPlayer::idPlayerBehaviorContextualLadder::idPlayerBehaviorContextualLadder(this: &this->contextualLadder);
  idPlayer::idPlayerBehaviorLean::idPlayerBehaviorLean(this: &this->lean);
  this->takedown.state = TAKEDOWNSTATE_NONE;
  this->takedown.enemyPosition = vec3_origin;
  p_z = &this->takedown.enemyPosition.z;
  p_y = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_z = *++p_y;
  this->animDeltasTrans.list = nullptr;
  this->animDeltasTrans.granularity = 0;
  this->animDeltasTrans.memTag = 5;
  this->animDeltasTrans.listStatic = 0;
  this->animDeltasTrans.size = 0;
  this->animDeltasTrans.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animDeltasTrans);
  this->animDeltasRot.list = nullptr;
  this->animDeltasRot.granularity = 0;
  this->animDeltasRot.memTag = 5;
  this->animDeltasRot.listStatic = 0;
  this->animDeltasRot.size = 0;
  this->animDeltasRot.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->animDeltasRot);
  idPlayer::idPlayerBehaviors::Clear(this);
  return this;
}


// ========================================================================
// __unwind$520854
// EA  : 0x82E323C8
// RVA : 0x00E323C8
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void _unwind_520854()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1564));
}


// ========================================================================
// __unwind$520855
// EA  : 0x82E323F4
// RVA : 0x00E323F4
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void _unwind_520855()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 1580));
}


// ========================================================================
// ?GetViewTransform@idPlayer@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82E34DD0
// RVA : 0x00E34DD0
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::GetViewTransform(idPlayer *this, idVec3 *origin, idMat3 *axis)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v6; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v6 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v6 = nullptr;
  idPresentablePlayer::GetViewTransform(this: v6, origin, axis);
}


// ========================================================================
// ?GetAAS@idPlayer@@UBAPBVidAAS2@@XZ
// EA  : 0x82E34E38
// RVA : 0x00E34E38
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

const idAAS2 *__fastcall idPlayer::GetAAS(idPlayer *this)
{
  return this->aas;
}


// ========================================================================
// ?GetHealthComponent@idPlayer@@UBAPBVidBaseHealth@@XZ
// EA  : 0x82E34E40
// RVA : 0x00E34E40
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idTungstenHealth *__fastcall idPlayer::GetHealthComponent(idPlayer *this)
{
  return &this->playerHealth;
}


// ========================================================================
// ?GetAuditor@idPlayer@@UAAPAVidEntityAuditor@@XZ
// EA  : 0x82E34E48
// RVA : 0x00E34E48
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idPlayerAuditor *__fastcall idPlayer::GetAuditor(idPlayer *this)
{
  return &this->auditor;
}


// ========================================================================
// ?GetApplyDamageScale@idPlayer@@UBAMXZ
// EA  : 0x82E34E50
// RVA : 0x00E34E50
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

float __fastcall idPlayer::GetApplyDamageScale(idPlayer *this)
{
  double applyDamageScale; // fp1

  applyDamageScale = this->applyDamageScale;
  return *((float *)&applyDamageScale + 1);
}


// ========================================================================
// ?GetAASPositionMgr@idPlayer@@UBAAAVidAASPositionMgr@@XZ
// EA  : 0x82E34E58
// RVA : 0x00E34E58
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idAASPositionMgr *__fastcall idPlayer::GetAASPositionMgr(idPlayer *this)
{
  return &this->aasPositionMgr;
}


// ========================================================================
// ??0jobMessage_t@idPlayer@@QAA@XZ
// EA  : 0x82E5B0E8
// RVA : 0x00E5B0E8
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

idPlayer::jobMessage_t *__fastcall idPlayer::jobMessage_t::jobMessage_t(idPlayer::jobMessage_t *this)
{
  this->message.len = 0;
  this->message.data = this->message.baseBuffer;
  this->message.allocedAndFlag = 20;
  this->message.baseBuffer[0] = 0;
  idStr::EnsureAlloced(this: &this->message, amount: 1, keepold: true, geometricGrowth: false);
  *this->message.data = 0;
  this->message.len = 0;
  this->complete = false;
  return this;
}


// ========================================================================
// __unwind$507243
// EA  : 0x82E5B148
// RVA : 0x00E5B148
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void _unwind_507243()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// ?SetArmor@idPlayer@@QAAXM@Z
// EA  : 0x82EBF4B0
// RVA : 0x00EBF4B0
// PDB : w:\tech5\tungsten\game\player\player.h
// ========================================================================

void __fastcall idPlayer::SetArmor(idPlayer *this, double value)
{
  struct idTungstenHealth *p_playerHealth; // r30

  p_playerHealth = &this->playerHealth;
  this->playerHealth.ClearDeadFlag(this: &this->playerHealth);
  this->playerHealth.SetComponentCur_Impl(this: p_playerHealth, a2: 1, a3: value);
}

