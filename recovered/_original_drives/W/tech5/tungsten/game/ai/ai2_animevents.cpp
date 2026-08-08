
// ========================================================================
// ?AnimEvent_DeathAnimImpulse@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4deathImpulse_t@@@Z
// EA  : 0x82A2DEE0
// RVA : 0x00A2DEE0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::AnimEvent_DeathAnimImpulse@<r4>(
        idAI2 *this@<r3>,
        int result@<r4>,
        const idMD6Anim *anim@<r5>,
        const deathImpulse_t impulse@<r6>)
{
  switch ( impulse )
  {
    case DEATHIMPULSE_ANIM_DONE:
      *(_DWORD *)(result + 20976) |= 4u;
      break;
    case DEATHIMPULSE_DISABLE_COLLISION:
      *(_DWORD *)(result + 20976) &= ~0x20u;
      break;
    case DEATHIMPULSE_ENABLE_COLLISION:
      *(_DWORD *)(result + 20976) |= 0x20u;
      break;
    default:
      break;
  }
  return result;
}


// ========================================================================
// ?AnimEvent_Kill@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclDamage@@@Z
// EA  : 0x82A2DF28
// RVA : 0x00A2DF28
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_Kill(
        idAI2 *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const idDeclDamage *damageType)
{
  eventVoid *v5; // r30
  char v7; // [sp+50h] [-20h] BYREF

  v5 = result + 61488;
  idAI2::Event_KillAI(this: (idAI2 *)&v7, result);
  (*(void (__fastcall **)(eventVoid *, double))(*(_DWORD *)v5 + 16))(a1: v5, a2: 0.0);
  (*(void (__fastcall **)(eventVoid *))(*(_DWORD *)v5 + 108))(a1: v5);
  return this;
}


// ========================================================================
// ?Event_DisableAutoFocus@idAI2@@QAA?AVeventVoid@@XZ
// EA  : 0x82A2DFA0
// RVA : 0x00A2DFA0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::Event_DisableAutoFocus(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAI2::SetEnableAutoFocus(this: result, enable: false);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableHeadTracking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2DFD8
// RVA : 0x00A2DFD8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableHeadTracking(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAI2::SetEnableHeadTracking(this: result, enable: true);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableHeadTracking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E010
// RVA : 0x00A2E010
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableHeadTracking(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAI2::SetEnableHeadTracking(this: result, enable: false);
  return this;
}


// ========================================================================
// ?AnimEvent_SetLookFocusHeadTrackingGroup@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82A2E048
// RVA : 0x00A2E048
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_SetLookFocusHeadTrackingGroup(
        idAI2 *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim,
        const char *groupName)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int HeadTrackGroupIndex; // r5

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  HeadTrackGroupIndex = idDeclMD6::GetHeadTrackGroupIndex(this: TreeAnimatorFromPresentable->decl, name: groupName);
  if ( HeadTrackGroupIndex >= 0 )
    idFocusInfo::SetCurHeadTrackGroup(
      this: (idFocusInfo *)&result[2].impactManager.impactBuffer[12].axis.mat[0].z,
      owner: result,
      trackGroupIndex: HeadTrackGroupIndex);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableEyeTracking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E098
// RVA : 0x00A2E098
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableEyeTracking(idAI2 *this, idEntity *result, const idMD6Anim *anim)
{
  idFaceMgr::SetEnableEyeTracking(this: (idFaceMgr *)&result[74].spawnOrientation.mat[1], owner: result, enable: true);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableEyeTracking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E0D8
// RVA : 0x00A2E0D8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableEyeTracking(idAI2 *this, idEntity *result, const idMD6Anim *anim)
{
  idFaceMgr::SetEnableEyeTracking(this: (idFaceMgr *)&result[74].spawnOrientation.mat[1], owner: result, enable: false);
  return this;
}


// ========================================================================
// ?AnimEvent_SetMovePushStatus@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiMovePushStatus_t@@H@Z
// EA  : 0x82A2E118
// RVA : 0x00A2E118
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_SetMovePushStatus(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        aiMovePushStatus_t pushMoveStatus,
        const int frameCount)
{
  idAI2::SetMovePushStatus(this: result, newStatus: pushMoveStatus, frameCount: 0);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableWorldCollision@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E158
// RVA : 0x00A2E158
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableWorldCollision(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAI2::SetWorldCollision(this: result, collideWithWorld: true);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableWorldCollision@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E190
// RVA : 0x00A2E190
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableWorldCollision(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAI2::SetWorldCollision(this: result, collideWithWorld: false);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableSolidCollision@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E1C8
// RVA : 0x00A2E1C8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableSolidCollision(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAI2::SetSolid(this: result, isSolid: true);
  result->aiVolatile.physics.restoreSolidCollisionTime = 0;
  return this;
}


// ========================================================================
// ?AnimEvent_DisableSolidCollision@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@H@Z
// EA  : 0x82A2E218
// RVA : 0x00A2E218
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableSolidCollision(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        int frameCount)
{
  idAI2::SetSolid(this: result, isSolid: false);
  result->aiVolatile.physics.restoreSolidCollisionTime = GetEndTimeByFrames(frameCount);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableDamage@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E258
// RVA : 0x00A2E258
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::AnimEvent_EnableDamage@<r4>(idAI2 *this@<r3>, int result@<r4>, const idMD6Anim *anim@<r5>)
{
  *(_BYTE *)(result + 92) |= 2u;
  return result;
}


// ========================================================================
// ?AnimEvent_DisableDamage@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E268
// RVA : 0x00A2E268
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::AnimEvent_DisableDamage@<r4>(idAI2 *this@<r3>, int result@<r4>, const idMD6Anim *anim@<r5>)
{
  *(_BYTE *)(result + 92) &= ~2u;
  return result;
}


// ========================================================================
// ?AnimEvent_ClearReferenceJointOverride@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiFoci_t@@@Z
// EA  : 0x82A2E280
// RVA : 0x00A2E280
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_ClearReferenceJointOverride(
        idAI2 *this,
        const idAnimatedEntity *result,
        const idMD6Anim *anim,
        const aiFoci_t foci)
{
  idFocusInfo::SetReferenceJointOverride(
    this: (idFocusInfo *)&result[2].impactManager.impactBuffer[8].pos.y + foci,
    owner: result,
    ji: (const idIndex<short,enum invalidJointIndex_t> *)0xFFFFFFFF);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableExtendedClipModel@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E2C0
// RVA : 0x00A2E2C0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableExtendedClipModel(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAI2::DeactivateExtendedClipModel(this: result);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableExtendedClipModel@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiExtendedClipModelStatus_t@@H@Z
// EA  : 0x82A2E2F8
// RVA : 0x00A2E2F8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableExtendedClipModel(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        aiExtendedClipModelStatus_t status,
        int frameCount)
{
  idAI2::ActivateExtendedClipModel(this: result, status, frameCount);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E338
// RVA : 0x00A2E338
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableIK(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  idAnimator_Base *v3; // r31
  int v6; // r28
  const idAnimStack *v7; // r3

  v3 = (idAnimator_Base *)&result[7648];
  idAnimator_WalkIK::EnableAll(this: (idAnimator_WalkIK *)&result[7648]);
  idAnimator_Base::SetAlpha(this: v3, alpha: 0.0);
  v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v7 = (const idAnimStack *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 184))(a1: result);
  idAnimator_Base::Start(this: v3, stack: v7, curTime: v6, blendDurationMS: 200, reset: false);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E3C0
// RVA : 0x00A2E3C0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableIK(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  idAnimator_Base *v3; // r30
  int v6; // r28
  const idAnimStack *v7; // r3

  v3 = (idAnimator_Base *)&result[7648];
  idAnimator_WalkIK::DisableAll(this: (idAnimator_WalkIK *)&result[7648]);
  v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  v7 = (const idAnimStack *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 184))(a1: result);
  idAnimator_Base::End(this: v3, stack: v7, curTime: v6, blendDurationMS: 200, reset: false);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@H@Z
// EA  : 0x82A2E438
// RVA : 0x00A2E438
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableLegIK(idAI2 *this, eventVoid *result, const idMD6Anim *anim, char legNumber)
{
  idAnimator_WalkIK::EnableLeg(this: (idAnimator_WalkIK *)&result[7648], num: legNumber);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@H@Z
// EA  : 0x82A2E478
// RVA : 0x00A2E478
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableLegIK(idAI2 *this, eventVoid *result, const idMD6Anim *anim, char legNumber)
{
  idAnimator_WalkIK::DisableLeg(this: (idAnimator_WalkIK *)&result[7648], num: legNumber);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableTwoLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E4B8
// RVA : 0x00A2E4B8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableTwoLegIK(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  idAnimator_WalkIK *v3; // r31

  v3 = (idAnimator_WalkIK *)&result[7648];
  idAnimator_WalkIK::DisableLeg(this: (idAnimator_WalkIK *)&result[7648], num: 0);
  idAnimator_WalkIK::DisableLeg(this: v3, num: 1);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableTwoLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E508
// RVA : 0x00A2E508
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableTwoLegIK(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  idAnimator_WalkIK *v3; // r31

  v3 = (idAnimator_WalkIK *)&result[7648];
  idAnimator_WalkIK::EnableLeg(this: (idAnimator_WalkIK *)&result[7648], num: 0);
  idAnimator_WalkIK::EnableLeg(this: v3, num: 1);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableFourLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E558
// RVA : 0x00A2E558
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableFourLegIK(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  idAnimator_WalkIK *v3; // r31

  v3 = (idAnimator_WalkIK *)&result[7648];
  idAnimator_WalkIK::DisableLeg(this: (idAnimator_WalkIK *)&result[7648], num: 0);
  idAnimator_WalkIK::DisableLeg(this: v3, num: 1);
  idAnimator_WalkIK::DisableLeg(this: v3, num: 2);
  idAnimator_WalkIK::DisableLeg(this: v3, num: 3);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableFourLegIK@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E5C0
// RVA : 0x00A2E5C0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableFourLegIK(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  idAnimator_WalkIK *v3; // r31

  v3 = (idAnimator_WalkIK *)&result[7648];
  idAnimator_WalkIK::EnableLeg(this: (idAnimator_WalkIK *)&result[7648], num: 0);
  idAnimator_WalkIK::EnableLeg(this: v3, num: 1);
  idAnimator_WalkIK::EnableLeg(this: v3, num: 2);
  idAnimator_WalkIK::EnableLeg(this: v3, num: 3);
  return this;
}


// ========================================================================
// ?AnimEvent_StartJetPackFX@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E628
// RVA : 0x00A2E628
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_StartJetPackFX(idAI2 *this, idEntity *result, const idMD6Anim *anim)
{
  idPhysics *Physics; // r30
  idPhysics *v6; // r29
  int GameMs; // r27
  idPresentable *presentable; // r31
  const idMat3 *v9; // r30
  const idVec3 *v10; // r3

  Physics = idEntity::GetPhysics(this: result);
  v6 = idEntity::GetPhysics(this: result);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  if ( result->presentable == nullptr )
    idEntity::InitPresentableInternal(this: result);
  presentable = result->presentable;
  v9 = Physics->GetAxis(this: Physics, a2: 0);
  v10 = v6->GetOrigin(this: v6, a2: 0);
  idFXManager::StartFX(this: &presentable->fxManager, org: v10, axis: v9, time: GameMs, startCondition: 3);
  return this;
}


// ========================================================================
// ?AnimEvent_StopJetPackFX@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E6E8
// RVA : 0x00A2E6E8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_StopJetPackFX(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  if ( idAI2::GetAlertCycle(this: result) != ALERTCYCLE_DYING )
    idAnimatedEntity::StopFX(this: result, condition: FX_VEH_STOP_BOOST2);
  return this;
}


// ========================================================================
// ?AnimEvent_DropJetPack@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E740
// RVA : 0x00A2E740
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DropJetPack(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  if ( idAI2::GetAlertCycle(this: result) != ALERTCYCLE_DYING )
    result->DropAttachment(this: result, a2: EQUIP_TORSO);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableBlinking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E7A0
// RVA : 0x00A2E7A0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableBlinking(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  idFaceMgr::SuppressBlinking(this: (idFaceMgr *)&result[59268], suppress: false);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableBlinking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E7E0
// RVA : 0x00A2E7E0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableBlinking(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  idFaceMgr::SuppressBlinking(this: (idFaceMgr *)&result[59268], suppress: true);
  return this;
}


// ========================================================================
// ?AnimEvent_EnableLidDeformation@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E820
// RVA : 0x00A2E820
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EnableLidDeformation(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  idFaceMgr::SuppressLidDeformation(this: (idFaceMgr *)&result[59268], suppress: false);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableLidDeformation@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E860
// RVA : 0x00A2E860
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DisableLidDeformation(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  idFaceMgr::SuppressLidDeformation(this: (idFaceMgr *)&result[59268], suppress: true);
  return this;
}


// ========================================================================
// ?AnimEvent_SetLookFocusOffset@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidVec3@@@Z
// EA  : 0x82A2E8A0
// RVA : 0x00A2E8A0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float *__usercall idAI2::AnimEvent_SetLookFocusOffset@<r4>(
        idAI2 *this@<r3>,
        float *result@<r4>,
        const idMD6Anim *anim@<r5>,
        const idVec3 *offset@<r6>)
{
  result[3422] = offset->x;
  result[3423] = offset->y;
  result[3424] = offset->z;
  return result;
}


// ========================================================================
// ?AnimEvent_SetAimFocusOffset@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidVec3@@@Z
// EA  : 0x82A2E8C0
// RVA : 0x00A2E8C0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float *__usercall idAI2::AnimEvent_SetAimFocusOffset@<r4>(
        idAI2 *this@<r3>,
        float *result@<r4>,
        const idMD6Anim *anim@<r5>,
        const idVec3 *offset@<r6>)
{
  result[3354] = offset->x;
  result[3355] = offset->y;
  result[3356] = offset->z;
  return result;
}


// ========================================================================
// ?AnimEvent_SetLookFocusRotationOffset@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@MMM@Z
// EA  : 0x82A2E8E0
// RVA : 0x00A2E8E0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float *__usercall idAI2::AnimEvent_SetLookFocusRotationOffset@<r4>(
        idAI2 *this@<r3>,
        float *result@<r4>,
        const idMD6Anim *anim@<r5>,
        double pitch@<f1>,
        double yaw@<f2>,
        double roll@<f3>)
{
  result[3425] = pitch;
  result[3426] = yaw;
  result[3427] = roll;
  return result;
}


// ========================================================================
// ?AnimEvent_SetAimFocusRotationOffset@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@MMM@Z
// EA  : 0x82A2E8F0
// RVA : 0x00A2E8F0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float *__usercall idAI2::AnimEvent_SetAimFocusRotationOffset@<r4>(
        idAI2 *this@<r3>,
        float *result@<r4>,
        const idMD6Anim *anim@<r5>,
        double pitch@<f1>,
        double yaw@<f2>,
        double roll@<f3>)
{
  result[3357] = pitch;
  result[3358] = yaw;
  result[3359] = roll;
  return result;
}


// ========================================================================
// ?AnimEvent_LockTracking@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@H@Z
// EA  : 0x82A2E900
// RVA : 0x00A2E900
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_LockTracking(idAI2 *this, eventVoid *result, const idMD6Anim *anim, const int lock)
{
  bool v5; // r31

  v5 = lock != 0;
  idFocusInfo::SetLockTracking(this: (idFocusInfo *)&result[13340], lock: lock != 0);
  idFocusInfo::SetLockTracking(this: (idFocusInfo *)&result[13612], lock: v5);
  return this;
}


// ========================================================================
// ?AnimEvent_DisableStaggeringPain@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E940
// RVA : 0x00A2E940
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::AnimEvent_DisableStaggeringPain@<r4>(
        idAI2 *this@<r3>,
        int result@<r4>,
        const idMD6Anim *anim@<r5>)
{
  *(_BYTE *)(result + 11056) &= ~0x80u;
  return result;
}


// ========================================================================
// ?AnimEvent_DisableDeathAnimations@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E950
// RVA : 0x00A2E950
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::AnimEvent_DisableDeathAnimations@<r4>(
        idAI2 *this@<r3>,
        int result@<r4>,
        const idMD6Anim *anim@<r5>)
{
  *(_BYTE *)(result + 20984) |= 0x80u;
  return result;
}


// ========================================================================
// ?AnimEvent_EnableDeathAnimations@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E960
// RVA : 0x00A2E960
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::AnimEvent_EnableDeathAnimations@<r4>(
        idAI2 *this@<r3>,
        int result@<r4>,
        const idMD6Anim *anim@<r5>)
{
  *(_BYTE *)(result + 20984) &= ~0x80u;
  return result;
}


// ========================================================================
// ?AnimEvent_EnableCanRagdoll@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E970
// RVA : 0x00A2E970
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::AnimEvent_EnableCanRagdoll@<r4>(idAI2 *this@<r3>, int result@<r4>, const idMD6Anim *anim@<r5>)
{
  *(_BYTE *)(result + 20984) &= ~2u;
  return result;
}


// ========================================================================
// ?AnimEvent_DisableCanRagdoll@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2E988
// RVA : 0x00A2E988
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __usercall idAI2::AnimEvent_DisableCanRagdoll@<r4>(idAI2 *this@<r3>, int result@<r4>, const idMD6Anim *anim@<r5>)
{
  *(_BYTE *)(result + 20984) |= 2u;
  return result;
}


// ========================================================================
// ?AnimEvent_StartWeaponFX@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82A2E998
// RVA : 0x00A2E998
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_StartWeaponFX(idAI2 *this, idActor *result, const idMD6Anim *anim, int condition)
{
  int v7; // r3
  idWeapon *v8; // r30
  idFXManager *v9; // r29
  const idTreeAnimator *EquippedWeaponAnimator; // r4
  int GameMs; // r3
  idVec3 v13; // [sp+50h] [-70h] BYREF
  idMat3 v14[2]; // [sp+60h] [-60h] BYREF

  v7 = (int)result->GetEquippedWeapon(this: result);
  v8 = (idWeapon *)v7;
  if ( v7 != 0 )
  {
    v9 = result->GetFXMgrForAttachment(this: result, a2: (idInventoryItem *)v7);
    if ( v9 != nullptr )
    {
      EquippedWeaponAnimator = idActor::GetEquippedWeaponAnimator(this: result);
      if ( EquippedWeaponAnimator != nullptr )
      {
        idWeapon::GetMuzzleFlashWorldTransform(
          this: v8,
          ta: EquippedWeaponAnimator,
          attackType: ATTACK_DEFAULT,
          origin: &v13,
          axis: v14);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idFXManager::StartFX(this: v9, org: &v13, axis: v14, time: GameMs, startCondition: condition);
      }
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_StopWeaponFX@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4fxCondition_t@@@Z
// EA  : 0x82A2EA58
// RVA : 0x00A2EA58
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_StopWeaponFX(idAI2 *this, eventVoid *result, const idMD6Anim *anim, int condition)
{
  int v7; // r4
  idFXManager *v8; // r31
  int GameMs; // r3

  v7 = (*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 704))(a1: result);
  if ( v7 != 0 )
  {
    v8 = (idFXManager *)(*(int (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 752))(a1: result, a2: v7);
    if ( v8 != nullptr )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idFXManager::StopFX(this: v8, time: GameMs, stopCondition: condition, immediateStop: false);
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_DeltaScaleToTarget@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@MMABVidJointName@@M@Z
// EA  : 0x82A2EAE8
// RVA : 0x00A2EAE8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idAI2 *__fastcall idAI2::AnimEvent_DeltaScaleToTarget(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        double minScale,
        double maxScale,
        const idJointName *jointName,
        double attackOriginOffset)
{
  char v13; // r11
  char v14; // r11
  const aiSenseState_t *EnemySenseState; // r3
  aiSenseState_t *v16; // r23
  const idCachedJoint *ModelSpaceJointTransformForAnimEvent; // r3
  idMD6AnimData *animData; // r11
  const idCachedJoint *v19; // r19
  double v20; // fp23
  int numFrames; // r11
  int v22; // r30
  idVec3 *v23; // r4
  const idCachedJoint *v24; // r3
  const idCachedJoint *v25; // r21
  idPhysics *Physics; // r3
  float *v27; // r30
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  double v29; // fp27
  double v30; // fp26
  double v31; // fp25
  idPhysics *v32; // r3
  float *v33; // r3
  float *presentable; // r30
  double v35; // fp31
  double v36; // fp30
  double v37; // fp29
  double v38; // fp31
  double x; // fp30
  double y; // fp29
  double z; // fp28
  idAIOrientation *BodyOrientation; // r3
  double v43; // fp27
  double v44; // fp31
  double v45; // fp30
  unsigned __int8 v46; // r28
  const idAAS2 *v47; // r3
  idAASPosition *AASPosition; // r30
  idAASPosition *v49; // r3
  idAAS2 *aas; // r27
  unsigned int v51; // r29
  idAAS2_vtbl *v52; // r30
  int AreaNum; // r26
  const aiPhysicalState_t *v54; // r3
  idAIMoveState *MoveInterface; // r3
  float *v56; // r4
  idRenderWorld *v57; // r27
  idPhysics *v58; // r3
  int v59; // r26
  idRenderWorld_vtbl *v60; // r29
  const aiPhysicalState_t *v61; // r3
  int v62; // r29
  idColor *v63; // r27
  idRenderWorld *v64; // r17
  idRenderWorld_vtbl *v65; // r28
  const aiPhysicalState_t *v66; // r3
  idColor *v67; // r28
  idRenderWorld *v68; // r27
  idRenderWorld_vtbl *v69; // r29
  const aiPhysicalState_t *v70; // r3
  int (*RW)(void); // ctr
  int v72; // r30
  idPhysics *v73; // r3
  float *v74; // r3
  double v75; // fp6
  double v76; // fp4
  __int64 v77; // r6
  va *v78; // r3
  int v80; // r30
  idPhysics *v81; // r3
  float *v82; // r3
  double v83; // fp6
  double v84; // fp4
  __int64 v85; // r6 OVERLAPPED
  __int128 v86; // r10
  va *v87; // r3
  int v88; // [sp+8h] [-1288h]
  int v89; // [sp+Ch] [-1284h]
  int v90; // [sp+10h] [-1280h]
  int v91; // [sp+14h] [-127Ch]
  int v92; // [sp+18h] [-1278h]
  int v93; // [sp+1Ch] [-1274h]
  double v94; // [sp+30h] [-1260h]
  double v95; // [sp+38h] [-1258h]
  idVec3 v96; // [sp+70h] [-1220h] BYREF
  float v97; // [sp+80h] [-1210h] BYREF
  float v98; // [sp+84h] [-120Ch]
  float v99; // [sp+88h] [-1208h]
  idVec3 v100; // [sp+90h] [-1200h] BYREF
  idVec3 v101; // [sp+A0h] [-11F0h] BYREF
  float v102[4]; // [sp+B0h] [-11E0h] BYREF
  idVec3 v103; // [sp+C0h] [-11D0h] BYREF
  float v104[4]; // [sp+D0h] [-11C0h] BYREF
  float v105[4]; // [sp+E0h] [-11B0h] BYREF
  float v106[4]; // [sp+F0h] [-11A0h] BYREF
  float v107[22]; // [sp+100h] [-1190h] BYREF
  idVec3 v108; // [sp+158h] [-1138h] BYREF
  idTypesafeNumber<int,enum millisecondUnique_t> v109; // [sp+164h] [-112Ch] BYREF
  idTypesafeNumber<int,enum millisecondUnique_t> v110; // [sp+168h] [-1128h] BYREF
  idMat3 v111; // [sp+170h] [-1120h] BYREF
  va v112; // [sp+1A0h] [-10F0h] BYREF

  if ( minScale <= 0.0 || (v13 = 1, minScale > 1.0) )
    v13 = 0;
  if ( v13 == 0 )
    idLib::Warning(
      fmt: "AI %s AnimEvent_DeltaScaleToTarget minScale %f out of reasonable range",
      result->name.data,
      minScale);
  if ( maxScale < 1.0 || (v14 = 1, maxScale >= 11.0) )
    v14 = 0;
  if ( v14 == 0 )
    idLib::Warning(
      fmt: "AI %s AnimEvent_DeltaScaleToTarget maxScale %f out of reasonable range",
      result->name.data,
      maxScale);
  EnemySenseState = idAI2::GetEnemySenseState(this: result, senseType: AISENSE_MAX);
  v16 = (aiSenseState_t *)EnemySenseState;
  if ( EnemySenseState != nullptr && EnemySenseState->lastUnconfirmedStimTime >= 0 && anim != nullptr )
  {
    idAI2::GetAnimationDelta(this: result, anim, outDelta: &v103);
    ModelSpaceJointTransformForAnimEvent = idAI2::GetModelSpaceJointTransformForAnimEvent(
                                             this: result,
                                             evDef: &AE_DeltaScaleToTarget,
                                             anim,
                                             cachedIndex: 0,
                                             jointOrigin: &v101,
                                             jointAxis: &v111,
                                             eventTime: &v109);
    animData = anim->animData;
    v19 = ModelSpaceJointTransformForAnimEvent;
    v20 = (float)(v103.x - v101.x);
    if ( animData != nullptr )
      numFrames = animData->numFrames;
    else
      numFrames = 0;
    v22 = numFrames - ModelSpaceJointTransformForAnimEvent->frameNum;
    v24 = idAI2::GetModelSpaceJointTransformForAnimEvent(
            this: result,
            evDef: &AE_DeltaScaleStrikeFrame,
            anim,
            cachedIndex: 0,
            jointOrigin: &v108,
            jointAxis: &v111,
            eventTime: &v110);
    v25 = v24;
    if ( v24 != nullptr )
    {
      v20 = (float)(v108.x - v101.x);
      v22 = v24->frameNum - v19->frameNum;
    }
    *(_QWORD *)&v96.x = __PAIR64__(byte_821B0000, v22);
    aiSenseState_t::ExtrapolatePosition(
      this: v16,
      seconds: (float)((float)__SPAIR64__(byte_821B0000, v22) * (float)0.033333335),
      futurePos: v23);
    Physics = idEntity::GetPhysics(this: result);
    v27 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v16);
    v29 = (float)(ConfirmedPhysicalSafe->origin.x - *v27);
    v30 = (float)(ConfirmedPhysicalSafe->origin.y - v27[1]);
    v31 = (float)(ConfirmedPhysicalSafe->origin.z - v27[2]);
    v32 = idEntity::GetPhysics(this: result);
    v33 = (float *)v32->GetOrigin(this: v32, a2: 0);
    presentable = (float *)result->presentable;
    v35 = (float)(v97 - *v33);
    v36 = (float)(v98 - v33[1]);
    v37 = (float)(v99 - v33[2]);
    v96.x = v97 - *v33;
    v96.y = v36;
    v96.z = v37;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = (float *)result->presentable;
    }
    v38 = (float)((float)(presentable[33] * (float)v35)
                + (float)((float)(presentable[35] * (float)v37) + (float)(presentable[34] * (float)v36)));
    idVec3::NormalizeFast(this: &v96);
    if ( presentable == nullptr )
      idEntity::InitPresentableInternal(this: result);
    x = v96.x;
    y = v96.y;
    z = v96.z;
    v100.x = v96.x;
    v100.y = v96.y;
    v100.z = v96.z;
    BodyOrientation = idAI2::GetBodyOrientation(this: result);
    idAIOrientation::SetAxis(this: BodyOrientation, ai: result, dir: &v100);
    if ( (float)((float)(v100.y * (float)v30) + (float)((float)(v100.x * (float)v29) + (float)(v100.z * (float)v31))) > v38 )
      v38 = (float)((float)(v100.y * (float)v30) + (float)((float)(v100.x * (float)v29) + (float)(v100.z * (float)v31)));
    v43 = (float)((float)v38 + (float)attackOriginOffset);
    v44 = (float)((float)((float)v38 + (float)attackOriginOffset) / (float)v20);
    v45 = (float)((float)(v100.y * (float)y) + (float)((float)(v100.x * (float)x) + (float)(v100.z * (float)z)));
    if ( v44 >= minScale )
    {
      if ( v44 > maxScale )
        v44 = maxScale;
    }
    else
    {
      v44 = minScale;
    }
    v46 = 0;
    if ( result->GetAAS(this: result) != nullptr )
    {
      v47 = result->GetAAS(this: result);
      AASPosition = (idAASPosition *)idActor::GetAASPosition(this: result, aas: v47);
      if ( idAASPosition::GetAreaNum(this: AASPosition) == 0 )
        goto LABEL_32;
      v107[0] = 0.0;
      v107[1] = 0.0;
      memset(&v107[4], 0, 12);
      v107[2] = 0.0;
      v107[3] = 0.0;
      v107[7] = 0.0;
      v107[10] = 0.0;
      v107[8] = 0.0;
      v107[11] = 0.0;
      v107[9] = 0.0;
      memset(&v107[15], 0, 24);
      v107[12] = 0.0;
      v107[13] = 0.0;
      v107[14] = 0.0;
      v49 = AASPosition;
      aas = (idAAS2 *)AASPosition->aas;
      v51 = result->aiVolatile.aas.travelFlags & 0xFE78FFFF;
      v52 = aas->__vftable;
      AreaNum = idAASPosition::GetAreaNum(this: v49);
      v54 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v16);
      ((void (__fastcall *)(idAAS2 *, float *, const aiPhysicalState_t *, int, float *, unsigned int, _DWORD, int))v52->TraceFloor)(
        a1: aas,
        a2: v107,
        a3: v54,
        a4: AreaNum,
        a5: &v97,
        a6: v51,
        a7: 0,
        a8: 1);
      if ( v107[0] >= 1.0 )
LABEL_32:
        v46 = 1;
    }
    if ( v45 > 0.0 && v46 != 0 )
    {
      MoveInterface = idAI2::GetMoveInterface(this: result);
      v105[0] = v44;
      v105[2] = 1.0;
      v56 = v105;
      v105[1] = 1.0;
    }
    else
    {
      MoveInterface = idAI2::GetMoveInterface(this: result);
      v102[0] = 1.0;
      v102[1] = 1.0;
      v56 = v102;
      v102[2] = 1.0;
    }
    MoveInterface->SetTranslationDeltaScale(this: MoveInterface, a2: (const idVec3 *)v56);
    if ( ai_debugAnimDeltaScale.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
    {
      v57 = common->RW(this: common);
      v58 = idEntity::GetPhysics(this: result);
      v59 = (int)v58->GetOrigin(this: v58, a2: 0);
      v60 = v57->__vftable;
      v61 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v16);
      ((void (__fastcall *)(idRenderWorld *, idColor *, int, const aiPhysicalState_t *, double))v60->DebugArrow)(
        a1: v57,
        a2: &idColor::colorWhite,
        a3: v59,
        a4: v61,
        a5: 4.0);
      v62 = v46;
      v63 = &idColor::colorOrange;
      if ( v46 == 0 )
        v63 = &idColor::colorRed;
      v64 = common->RW(this: common);
      v65 = v64->__vftable;
      v66 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v16);
      ((void (__fastcall *)(idRenderWorld *, idColor *, const aiPhysicalState_t *, float *, double))v65->DebugArrow)(
        a1: v64,
        a2: v63,
        a3: v66,
        a4: &v97,
        a5: 4.0);
      v67 = &idColor::colorOrange;
      if ( v62 == 0 )
        v67 = &idColor::colorRed;
      v68 = common->RW(this: common);
      v69 = v68->__vftable;
      v70 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v16);
      v69->DebugPoint(this: v68, a2: (const idVec4 *)v67, a3: &v70->origin, a4: 2000, a5: true);
      RW = (int (*)(void))common->RW;
      if ( v25 != nullptr )
      {
        v72 = RW();
        v73 = idEntity::GetPhysics(this: result);
        v74 = (float *)v73->GetOrigin(this: v73, a2: 0);
        v75 = (float)(v74[2] + v99);
        v76 = (float)((float)(v74[1] + v98) * (float)0.5);
        v106[0] = (float)(*v74 + v97) * (float)0.5;
        v106[1] = v76;
        v106[2] = (float)v75 * (float)0.5;
        HIDWORD(v77) = v19->frameNum;
        LODWORD(v77) = v25->frameNum;
        v78 = va::va(
                this: &v112,
                fmt: "frame %d/%d/%d  animDeltaX %.0f/%.0f/%.0f  extrapolatedDeltaX %.0f(%+.0f) scale %5.3f ",
                a3: v77,
                a4: COERCE__INT64(v101.x),
                a5: COERCE__INT64(v103.x),
                a6: v88,
                a7: v89,
                a8: v90,
                a9: v91,
                a10: v92,
                a11: v93);
        (*(void (__fastcall **)(int, va *, float *, _DWORD, idColor *, int, int, _DWORD, double))(*(_DWORD *)v72 + 268))(
          a1: v72,
          a2: v78,
          a3: v106,
          a4: *(_DWORD *)(*(_DWORD *)v72 + 268),
          a5: &idColor::colorWhite,
          a6: 1,
          a7: 2000,
          a8: 0,
          a9: 0.2);
        return this;
      }
      v80 = RW();
      v81 = idEntity::GetPhysics(this: result);
      v82 = (float *)v81->GetOrigin(this: v81, a2: 0);
      v83 = (float)(v82[2] + v99);
      v84 = (float)((float)(v82[1] + v98) * (float)0.5);
      v104[0] = (float)(v97 + *v82) * (float)0.5;
      v104[1] = v84;
      v104[2] = (float)v83 * (float)0.5;
      v94 = v101.x;
      v95 = v103.x;
      LODWORD(v85) = HIDWORD(v94);
      HIDWORD(v86) = HIDWORD(v95);
      LODWORD(v86) = LODWORD(v44);
      *(double *)((char *)&v86 + 4) = v43;
      HIDWORD(v85) = v19->frameNum;
      v87 = va::va(
              this: &v112,
              fmt: "frame %d/%d  animDeltaX %.0f/%.0f  extrapolatedDeltaX %.0f  scale %5.3f ",
              a3: v85,
              a4: *(__int64 *)&v86,
              a5: v86,
              a6: v88,
              a7: v89,
              a8: v90,
              a9: v91,
              a10: v92,
              a11: v93);
      (*(void (__fastcall **)(int, va *, float *, enum idAIStateTransition::aiTransCode_t (__fastcall **)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int), idColor *, int, int, _DWORD, double))(*(_DWORD *)v80 + 268))(
        a1: v80,
        a2: v87,
        a3: v104,
        a4: &off_82040000,
        a5: &idColor::colorWhite,
        a6: 1,
        a7: 2000,
        a8: 0,
        a9: 0.2);
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_SetDeltaScale@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidVec3@@@Z
// EA  : 0x82A2F390
// RVA : 0x00A2F390
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_SetDeltaScale(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const idVec3 *deltaScale)
{
  idAIMoveState *MoveInterface; // r3

  MoveInterface = idAI2::GetMoveInterface(this: result);
  MoveInterface->SetTranslationDeltaScale(this: MoveInterface, a2: deltaScale);
  return this;
}


// ========================================================================
// ?AnimEvent_PopOffArmor@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBDH@Z
// EA  : 0x82A2F3E8
// RVA : 0x00A2F3E8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_PopOffArmor(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const char *damageGroupName,
        int chance)
{
  eventVoid *p_armorPopOffAccumulation; // r27
  int armorPopOffAccumulation; // r28
  int v11; // r28
  idDamageGroup *DamageGroup; // r3
  idPhysics *Physics; // r3
  const idVec3 *v14; // r3
  float y; // r7
  float z; // r29
  idPhysics *v17; // r3
  __int128 v18; // r6
  _BYTE *v20; // [sp+8h] [-98h]
  char v21[8]; // [sp+50h] [-50h] BYREF
  float x; // [sp+58h] [-48h]
  float v23; // [sp+5Ch] [-44h]

  p_armorPopOffAccumulation = (eventVoid *)&result->aiVolatile.memory.armorPopOffAccumulation;
  armorPopOffAccumulation = result->aiVolatile.memory.armorPopOffAccumulation;
  v11 = RandomInt(max: 100) - armorPopOffAccumulation;
  if ( ai_debugLevel.valueInteger != 0 && ai_debugHealth.valueInteger >= 1 && damageGroupName != nullptr )
    idLib::Printf(fmt: "%s pop off %s armor %d/%d\n", result->name.data, damageGroupName, v11, chance);
  DamageGroup = idActor::GetDamageGroup(this: result, name: damageGroupName);
  if ( chance >= v11 && DamageGroup != nullptr && DamageGroup->locationArmor > 0.0 )
  {
    DamageGroup->locationArmor = 0.0;
    Physics = idEntity::GetPhysics(this: result);
    v14 = Physics->GetGravityNormal(this: Physics);
    y = v14->y;
    z = v14->z;
    x = v14->x;
    v23 = y;
    v17 = idEntity::GetPhysics(this: result);
    *(_QWORD *)((char *)&v18 + 4) = *(_QWORD *)&v17->GetOrigin(this: v17, a2: 0)->x;
    LODWORD(v18) = __ROL4__(LODWORD(x), 32);
    idAI2::DamageGroupPopOffArmor(
      this: result,
      impactPoint: v18,
      outArmorPoppedOff: __SPAIR64__(LODWORD(v23), __ROL4__(LODWORD(z), 32)),
      damage: 8.0,
      a5: (int)&unk_82150000,
      a6: (int)v21,
      a7: v20);
    *(_DWORD *)p_armorPopOffAccumulation = 0;
    return this;
  }
  else
  {
    *(_DWORD *)p_armorPopOffAccumulation += chance;
    return this;
  }
}


// ========================================================================
// ?AnimEvent_SetDefaultMoveMode@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2F548
// RVA : 0x00A2F548
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_SetDefaultMoveMode(idAI2 *this, _exception *result, const idMD6Anim *anim)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: result) != 0 )
    DWORD2(result[599].arg1) = 0;
  else
    idAIMoveState::SetMovementModeForReal(
      this: (idAIMoveState *)((char *)&result[190].arg2 + 4),
      mode: AIMOVEMODE_GROUND);
  return this;
}


// ========================================================================
// ?AnimEvent_SetFullDeltaGravityMovementMode@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2F5B8
// RVA : 0x00A2F5B8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_SetFullDeltaGravityMovementMode(
        idAI2 *this,
        _exception *result,
        const idMD6Anim *anim)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: result) != 0 )
    DWORD2(result[599].arg1) = 2;
  else
    idAIMoveState::SetMovementModeForReal(
      this: (idAIMoveState *)((char *)&result[190].arg2 + 4),
      mode: AIMOVEMODE_ANIM_GRAVITY);
  return this;
}


// ========================================================================
// ?AnimEvent_Death@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2F628
// RVA : 0x00A2F628
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_Death(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAI2::StartDeathSystem(this: result);
  return this;
}


// ========================================================================
// ?AnimEvent_ForceAllowLooting@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2F660
// RVA : 0x00A2F660
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_ForceAllowLooting(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  if ( idActor::IsLootable(this: result) )
  {
    idAI2::ActivateItemsOnDeath(this: result);
    *((_BYTE *)&result->aiVolatile.death + 1761) |= 0x40u;
  }
  return this;
}


// ========================================================================
// ?AnimEvent_BeginDrop@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2F6C0
// RVA : 0x00A2F6C0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_BeginDrop(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  int v5; // r8
  float v7[4]; // [sp+50h] [-40h] BYREF
  float v8[12]; // [sp+60h] [-30h] BYREF

  idAIMoveState::SetMovementModeForReal(this: (idAIMoveState *)&result[12196], mode: AIMOVEMODE_DROP);
  (*(void (__fastcall **)(float *, eventVoid *, _DWORD))(*(_DWORD *)&result[11520] + 88))(
    a1: v7,
    a2: result + 11520,
    a3: 0);
  v5 = *(_DWORD *)&result[11520];
  v8[0] = v7[0];
  v8[1] = v7[1];
  v8[2] = v7[2] - (float)1.0;
  (*(void (__fastcall **)(eventVoid *, float *, _DWORD))(v5 + 80))(a1: result + 11520, a2: v8, a3: 0);
  return this;
}


// ========================================================================
// ?AnimEvent_ParticleAtRottrack@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclParticle@@ABVidJointName@@ABVidVec3@@@Z
// EA  : 0x82A2F750
// RVA : 0x00A2F750
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_ParticleAtRottrack(
        idAI2 *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim,
        const idMaterial *particle,
        const idJointName *jointName,
        const idVec3 *offset)
{
  idPresentable *presentable; // r11
  int v12; // r25
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3
  idTreeAnimator *v14; // r30
  double v15; // fp1
  double v16; // fp13
  unsigned int GameMs; // r3
  int v19; // [sp+8h] [-118h]
  const idColor *v20; // [sp+Ch] [-114h]
  int v21; // [sp+10h] [-110h]
  int v22; // [sp+14h] [-10Ch]
  int v23; // [sp+18h] [-108h]
  int v24; // [sp+1Ch] [-104h]
  int v25; // [sp+20h] [-100h]
  int v26; // [sp+24h] [-FCh]
  int v27; // [sp+28h] [-F8h]
  int v28; // [sp+2Ch] [-F4h]
  int v29; // [sp+30h] [-F0h]
  int v30; // [sp+34h] [-ECh]
  int v31; // [sp+38h] [-E8h]
  int v32; // [sp+3Ch] [-E4h]
  int v33; // [sp+40h] [-E0h]
  int v34; // [sp+44h] [-DCh]
  int v35; // [sp+48h] [-D8h]
  int v36; // [sp+4Ch] [-D4h]
  int v37; // [sp+50h] [-D0h]
  int v38; // [sp+58h] [-C8h]
  int v39; // [sp+5Ch] [-C4h]
  int v40; // [sp+60h] [-C0h]
  int v41; // [sp+68h] [-B8h]
  unsigned __int16 v42; // [sp+70h] [-B0h] BYREF
  idVec3 v43; // [sp+78h] [-A8h] BYREF
  idVec3 v44; // [sp+88h] [-98h] BYREF
  idColor v45; // [sp+A0h] [-80h] BYREF
  idMat3 v46[3]; // [sp+B0h] [-70h] BYREF

  presentable = result->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  v12 = (int)presentable->GetAIInterface(this: presentable);
  TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  v14 = (idTreeAnimator *)TreeAnimatorFromPresentable;
  if ( v12 != 0 && TreeAnimatorFromPresentable != nullptr )
  {
    idTreeAnimator::GetJointIndex(
      this: (idTreeAnimator *)&v42,
      result: TreeAnimatorFromPresentable,
      jointName: jointName->data);
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: v14,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)v42,
      origin: &v43,
      axis: v46);
    v15 = (float)((float)(offset->z * v46[0].mat[2].z)
                + (float)((float)(offset->x * v46[0].mat[0].z) + (float)(offset->y * v46[0].mat[1].z)));
    v16 = (float)(v43.y
                + (float)((float)(offset->y * v46[0].mat[1].y)
                        + (float)((float)(offset->x * v46[0].mat[0].y) + (float)(offset->z * v46[0].mat[2].y))));
    v44.x = (float)((float)(offset->x * v46[0].mat[0].x)
                  + (float)((float)(offset->z * v46[0].mat[2].x) + (float)(offset->y * v46[0].mat[1].x)))
          + v43.x;
    v44.y = v16;
    v44.z = v43.z + (float)v15;
    if ( particle != nullptr )
    {
      v45 = idColor::colorWhite;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idImpactManager::UseImpact(
        this: &result->impactManager,
        org: &v44,
        axis: v46,
        prt: particle,
        startTime: GameMs,
        bindToParent: false,
        parentOrg: &vec3_origin,
        parentAxis: &mat3_identity,
        distSqr: 0.0,
        playerIndex: v19,
        color: v20,
        numCycles: v21,
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
        a28: v37,
        a29: 0,
        a30: v38,
        a31: v39,
        a32: v40,
        a33: &v45.r,
        a34: v41,
        a35: 1);
    }
  }
  return this;
}


// ========================================================================
// ?accelSim_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82A2F900
// RVA : 0x00A2F900
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void __fastcall accelSim_f(const idCmdArgs *args)
{
  const char *v2; // r3
  long double v3; // fp2
  double v4; // fp28
  const char *v5; // r3
  long double v6; // fp2
  double v7; // fp30
  const char *v8; // r3
  long double v9; // fp2
  double v10; // fp31
  const char *v11; // r3
  int v12; // r29
  const char *v13; // r3
  int v14; // r3
  int v15; // r31
  double v16; // fp29
  double v17; // fp28

  if ( args->argc >= 6 )
  {
    if ( args->argc <= 1 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[1];
    v3 = atof(nptr: v2);
    v4 = (float)*(double *)&v3;
    if ( args->argc <= 2 )
      v5 = &byte_8200D768;
    else
      v5 = args->argv[2];
    v6 = atof(nptr: v5);
    v7 = (float)*(double *)&v6;
    if ( args->argc <= 3 )
      v8 = &byte_8200D768;
    else
      v8 = args->argv[3];
    v9 = atof(nptr: v8);
    v10 = (float)*(double *)&v9;
    if ( args->argc <= 4 )
      v11 = &byte_8200D768;
    else
      v11 = args->argv[4];
    v12 = atol(nptr: v11);
    if ( args->argc <= 5 )
      v13 = &byte_8200D768;
    else
      v13 = args->argv[5];
    v14 = atol(nptr: v13);
    if ( v14 > 0 )
    {
      v15 = 0;
      v16 = (float)((float)1.0 / (float)__SPAIR64__(0x82000000, v14));
      if ( v12 > 0 )
      {
        v17 = (float)((float)((float)1.0 / (float)__SPAIR64__(0x82000000, v14)) * (float)v4);
        do
        {
          v7 = (float)((float)((float)v16 * (float)v10) + (float)v7);
          v10 = (float)((float)v17 + (float)v10);
          idLib::Printf(fmt: "step %4d: vel = %.4f pos = %.4f\n", v15++, v10, v7);
        }
        while ( v15 < v12 );
      }
    }
    else
    {
      idLib::Warning(fmt: "<sim hertz> must be a positive integer value.");
    }
  }
  else
  {
    idLib::Printf(fmt: "USAGE: accelSim <accel> <start pos> <start vel> <num steps> <sim hertz>\n");
  }
}


// ========================================================================
// ?AnimEvent_PlayVoice@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4voiceMsg_t@@@Z
// EA  : 0x82A2FA88
// RVA : 0x00A2FA88
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_PlayVoice(idAI2 *this, idAI2 *result, const idMD6Anim *anim, voiceMsg_t msg)
{
  idAIVoiceController::PlayVoice(this: &result->aiVolatile.voiceController, ai: result, msg);
  return this;
}


// ========================================================================
// ?AnimEvent_SetHealth@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@M@Z
// EA  : 0x82A2FAC8
// RVA : 0x00A2FAC8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_SetHealth(idAI2 *this, eventVoid *result, const idMD6Anim *anim, double val)
{
  (*(void (__fastcall **)(eventVoid *, double))(*(_DWORD *)&result[61488] + 12))(a1: result + 61488, a2: val);
  return this;
}


// ========================================================================
// ?AnimEvent_AnimEndEnterAnimation@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2FB10
// RVA : 0x00A2FB10
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_AnimEndEnterAnimation(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAnimWebCmdCtx *v6; // r3

  if ( result->GetAnimWebCmdCtx(this: result) != nullptr )
  {
    v6 = result->GetAnimWebCmdCtx(this: result);
    idAnimWebCmdCtx::ReleaseWaitHandleForAnim(this: v6, anim);
  }
  idAI2::ClearAnimWebEvent(
    this: result,
    web: AIANIMWEB_BODY,
    priority: PRIORITY_LOW,
    eventType: ANIMWEB_EVENT_START_BLEND_OUT);
  return this;
}


// ========================================================================
// ?AnimEvent_AnimReleaseWaitHandle@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A2FB80
// RVA : 0x00A2FB80
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_AnimReleaseWaitHandle(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  idAnimWebCmdCtx *v6; // r3

  if ( result->GetAnimWebCmdCtx(this: result) != nullptr )
  {
    v6 = result->GetAnimWebCmdCtx(this: result);
    idAnimWebCmdCtx::ReleaseWaitHandleForAnim(this: v6, anim);
  }
  idAI2::ClearAllAnimWebEvents(this: result, web: AIANIMWEB_BODY, priority: PRIORITY_MAX);
  return this;
}


// ========================================================================
// ?AnimEvent_SetTakedownWindowState@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@_N@Z
// EA  : 0x82A2FBF0
// RVA : 0x00A2FBF0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_SetTakedownWindowState(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        bool setOpen)
{
  idAI2::SetTakeDownWindow(this: result, setOpen);
  return this;
}


// ========================================================================
// ?AnimEvent_TriggerGore@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82A2FC28
// RVA : 0x00A2FC28
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_TriggerGore(
        idAI2 *this,
        eventVoid *result,
        const idMD6Anim *animHandle,
        const char *goreName)
{
  idAtomicString v7[2]; // [sp+50h] [-20h] BYREF

  idAtomicString::Set(this: v7, str_: goreName);
  idGoreComponent::CheckForGoreByName(this: (idGoreComponent *)&result[19248], name: v7);
  return this;
}


// ========================================================================
// ?AnimEvent_SetReferenceJointOverride@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@W4aiFoci_t@@ABVidJointName@@@Z
// EA  : 0x82A2FC78
// RVA : 0x00A2FC78
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_SetReferenceJointOverride(
        idAI2 *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim,
        const aiFoci_t foci,
        const idJointName *jointName)
{
  char *data; // r30
  const idMD6Model *model; // r11
  idIndex<short,enum invalidJointIndex_t> *skeleton; // r4
  idMD6Skel *JointIndex; // r3
  idMD6Skel var30; // [sp+50h] [-30h] BYREF

  data = jointName->data;
  model = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result)->decl->model;
  if ( model != nullptr && (skeleton = (idIndex<short,enum invalidJointIndex_t> *)model->skeleton) != nullptr )
  {
    JointIndex = idMD6Skel::GetJointIndex(this: &var30, result: skeleton, name: data);
  }
  else
  {
    JointIndex = &var30;
    HIWORD(var30.__vftable) = -1;
  }
  idFocusInfo::SetReferenceJointOverride(
    this: (idFocusInfo *)&result[2].impactManager.impactBuffer[8].pos.y + foci,
    owner: result,
    ji: (const idIndex<short,enum invalidJointIndex_t> *)HIWORD(JointIndex->__vftable));
  return this;
}


// ========================================================================
// ?AnimEvent_RandomRunCycleIndex@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@HHH@Z
// EA  : 0x82A2FCF8
// RVA : 0x00A2FCF8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_RandomRunCycleIndex(
        idAI2 *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const int index1,
        const int index2,
        const int index3)
{
  unsigned int v11; // r4
  int v12; // r29
  int v13; // r3
  runIndexType_t v14; // r4
  __int64 v15; // r11
  __int64 v16; // fp0

  v11 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v11 + 1013904223;
  v12 = (((v11 + 1013904223) >> 10) & 0x7FFF)
      - 3 * ((unsigned __int64)(1431655766LL * (((v11 + 1013904223) >> 10) & 0x7FFF)) >> 32)
      + 1;
  v13 = idAccolade::Count(this: &clientGame->gameTimeManager);
  v14 = *(_DWORD *)&result[33700];
  if ( v13 - v14 > 5 )
  {
    HIDWORD(v15) = 33692;
    if ( *(_DWORD *)&result[33692] == 2 )
    {
      switch ( v12 )
      {
        case 1:
          LODWORD(v15) = index1;
          v16 = v15;
LABEL_9:
          idAnimWebAI::SetForwardRunIndex(
            this: (idAnimWebAI *)&result[32960],
            newRunIndex: (float)v16,
            newIdleIndex: 0.0,
            t: v14,
            blend: 164);
          return this;
        case 2:
          LODWORD(v15) = index2;
          v16 = v15;
          goto LABEL_9;
        case 3:
          LODWORD(v15) = index3;
          v16 = v15;
          goto LABEL_9;
        default:
          break;
      }
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_RandomRunCycleNormal@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@HHH@Z
// EA  : 0x82A2FE18
// RVA : 0x00A2FE18
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_RandomRunCycleNormal(
        idAI2 *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const int index1,
        const int index2,
        const int index3)
{
  unsigned int v11; // r4
  int v12; // r29
  int v13; // r3
  runIndexType_t v14; // r4
  __int64 v15; // r11
  __int64 v16; // fp0

  v11 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v11 + 1013904223;
  v12 = (((v11 + 1013904223) >> 10) & 0x7FFF)
      - 3 * ((unsigned __int64)(1431655766LL * (((v11 + 1013904223) >> 10) & 0x7FFF)) >> 32)
      + 1;
  v13 = idAccolade::Count(this: &clientGame->gameTimeManager);
  v14 = *(_DWORD *)&result[33700];
  if ( v13 - v14 > 5 )
  {
    HIDWORD(v15) = 33692;
    if ( *(_DWORD *)&result[33692] == 0 )
    {
      switch ( v12 )
      {
        case 1:
          LODWORD(v15) = index1;
          v16 = v15;
LABEL_9:
          idAnimWebAI::SetForwardRunIndex(
            this: (idAnimWebAI *)&result[32960],
            newRunIndex: (float)v16,
            newIdleIndex: 0.0,
            t: v14,
            blend: 164);
          return this;
        case 2:
          LODWORD(v15) = index2;
          v16 = v15;
          goto LABEL_9;
        case 3:
          LODWORD(v15) = index3;
          v16 = v15;
          goto LABEL_9;
        default:
          break;
      }
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_StartDropToGround@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA  : 0x82A2FF38
// RVA : 0x00A2FF38
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_StartDropToGround(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const idJointName *jointName)
{
  double v8; // fp29
  double v9; // fp28
  double v10; // fp31
  idPhysics *Physics; // r3
  float *v12; // r3
  float v13; // r29
  float v14; // r31
  idPhysics *v15; // r3
  char v16; // r29
  double v17; // fp27
  double v18; // fp26
  idAIMoveState *MoveInterface; // r3
  idRenderWorld *v20; // r3
  idColor *v21; // r28
  idRenderWorld *v22; // r24
  idPhysics *v23; // r3
  float *v24; // r3
  double v25; // fp12
  double v26; // fp11
  idPhysics *v27; // r3
  float *v28; // r3
  double v29; // fp4
  double v30; // fp2
  idColor *v31; // r30
  idRenderWorld *v32; // r3
  idRenderWorld *v33; // r3
  __int64 v34; // r8
  idRenderWorld *v35; // r31
  __int64 v36; // r10
  va *v37; // r3
  int v38; // [sp+8h] [-1208h]
  int v39; // [sp+Ch] [-1204h]
  int v40; // [sp+10h] [-1200h]
  int v41; // [sp+14h] [-11FCh]
  int v42; // [sp+18h] [-11F8h]
  int v43; // [sp+1Ch] [-11F4h]
  float z; // [sp+68h] [-11A8h]
  idVec3 v45; // [sp+70h] [-11A0h] BYREF
  idVec3 v46; // [sp+80h] [-1190h] BYREF
  idVec3 v47; // [sp+90h] [-1180h] BYREF
  float v48[4]; // [sp+A0h] [-1170h] BYREF
  float v49[4]; // [sp+B0h] [-1160h] BYREF
  float v50[4]; // [sp+C0h] [-1150h] BYREF
  idVec3 v51; // [sp+D0h] [-1140h] BYREF
  idTypesafeNumber<int,enum millisecondUnique_t> v52; // [sp+DCh] [-1134h] BYREF
  idMat3 v53; // [sp+E0h] [-1130h] BYREF
  trace_t v54; // [sp+110h] [-1100h] BYREF
  va v55; // [sp+190h] [-1080h] BYREF

  idAI2::GetAnimationDelta(this: result, anim, outDelta: &v51);
  if ( idAI2::GetModelSpaceJointTransformForAnimEvent(
         this: result,
         evDef: &AE_StartDropToGround,
         anim,
         cachedIndex: 0,
         jointOrigin: &v47,
         jointAxis: &v53,
         eventTime: &v52) != nullptr )
  {
    v8 = (float)(v51.x - v47.x);
    v9 = (float)(v51.y - v47.y);
    v10 = (float)(v51.z - v47.z);
    Physics = idEntity::GetPhysics(this: result);
    v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v13 = v12[1] + (float)v9;
    v14 = *v12 + (float)v8;
    v45.z = v12[2] + (float)v10;
    v45.x = v14;
    v45.y = v13;
    v15 = idEntity::GetPhysics(this: result);
    z = v15->GetOrigin(this: v15, a2: 0)->z;
    v46.x = v14;
    v46.z = z - (float)128.0;
    v46.y = v13;
    idClip::TracePoint(
      this: &clientGame->clip,
      result: &v54,
      start: &v45,
      end: &v46,
      clipMask: 1,
      passEntityNumber: result->entityNumber);
    v16 = 0;
    v17 = (float)(v45.z - (float)((float)((float)(v45.z - v46.z) * v54.fraction) + v45.z));
    v18 = (float)((float)v10 / (float)(v45.z - (float)((float)((float)(v45.z - v46.z) * v54.fraction) + v45.z)));
    if ( v54.fraction < 1.0 )
    {
      v16 = 1;
      MoveInterface = idAI2::GetMoveInterface(this: result);
      v50[0] = 1.0;
      v50[1] = 1.0;
      v50[2] = v18;
      MoveInterface->SetTranslationDeltaScale(this: MoveInterface, a2: (const idVec3 *)v50);
    }
    if ( ai_debugAnimDeltaScale.valueInteger != 0 && ai_debugLevel.valueInteger > 0 )
    {
      v20 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))v20->DebugArrow)(
        a1: v20,
        a2: &idColor::colorWhite,
        a3: &v45,
        a4: &v46,
        a5: 4.0);
      if ( v16 != 0 )
        v21 = &idColor::colorGreen;
      else
        v21 = &idColor::colorOrange;
      v22 = common->RW(this: common);
      v23 = idEntity::GetPhysics(this: result);
      v24 = (float *)v23->GetOrigin(this: v23, a2: 0);
      v25 = (float)((float)v8 + *v24);
      v26 = (float)(v24[1] + (float)v9);
      v48[2] = v24[2] + (float)v10;
      v48[0] = (float)v25 + (float)4.0;
      v48[1] = (float)v26 + (float)4.0;
      v27 = idEntity::GetPhysics(this: result);
      v28 = (float *)v27->GetOrigin(this: v27, a2: 0);
      v29 = (float)(v28[1] + (float)4.0);
      v30 = (float)(*v28 + (float)4.0);
      v49[2] = v28[2];
      v49[0] = v30;
      v49[1] = v29;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))v22->DebugArrow)(
        a1: v22,
        a2: v21,
        a3: v49,
        a4: v48,
        a5: 4.0);
      if ( v16 != 0 )
        v31 = &idColor::colorGreen;
      else
        v31 = &idColor::colorRed;
      v32 = common->RW(this: common);
      v32->DebugPoint(this: v32, a2: (const idVec4 *)v31, a3: &v54.endpos, a4: 2000, a5: true);
      v33 = common->RW(this: common);
      HIDWORD(v34) = LODWORD(v18);
      v35 = v33;
      v37 = va::va(
              this: &v55,
              fmt: (const char *)HIDWORD(v10),
              a3: __SPAIR64__(LODWORD(v10), LODWORD(v17)),
              a4: v34,
              a5: v36,
              a6: v38,
              a7: v39,
              a8: v40,
              a9: v41,
              a10: v42,
              a11: v43,
              v10,
              v17,
              v18);
      ((void (__fastcall *)(idRenderWorld *, va *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, int, _DWORD, double))v35->DebugText)(
        a1: v35,
        a2: v37,
        a3: &v45,
        a4: v35->DebugText,
        a5: &idColor::colorWhite,
        a6: 1,
        a7: 2000,
        a8: 0,
        a9: 0.30000001);
    }
    return this;
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_StartDropToGround: invalid joint");
    return this;
  }
}


// ========================================================================
// ?AnimEvent_HideMesh@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82A30350
// RVA : 0x00A30350
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_HideMesh(
        idAI2 *this,
        idAnimatedEntity *result,
        const idMD6Anim *animHandle,
        const char *meshName)
{
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int MeshIndex; // r31

  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  if ( TreeAnimatorFromPresentable != nullptr )
  {
    MeshIndex = idTreeAnimator::GetMeshIndex(this: TreeAnimatorFromPresentable, meshName);
    if ( MeshIndex >= 0 )
      idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result)->meshVisibility.list[MeshIndex] = false;
  }
  return this;
}


// ========================================================================
// ?AnimEvent_Explode@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A303B0
// RVA : 0x00A303B0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_Explode(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  const idDeclEntityDef *explosionEntity; // r4
  idProjectile *v6; // r3
  idProjectile *v7; // r29
  idAI2_vtbl *v8; // r9
  idWeapon *(__fastcall *GetEquippedWeapon)(struct idAI2 *); // ctr
  idWeapon *v10; // r30
  idPhysics *Physics; // r3
  int v12; // r3
  float v13; // r8
  float v14; // r7
  idAI2_vtbl *v15; // r30
  idWeapon *EquippedWeapon; // r3
  idAI2_vtbl *v17; // r30
  idWeapon *v18; // r3
  int GameMs; // r3
  idVec3 v21; // [sp+50h] [-90h] BYREF
  idVec3 v22; // [sp+60h] [-80h] BYREF
  idProjectileTarget v23; // [sp+70h] [-70h] BYREF
  idMat3 v24[2]; // [sp+90h] [-50h] BYREF

  explosionEntity = result->aiEditable.behaviors.decl->damageBehaviors.explosionEntity;
  if ( explosionEntity != nullptr )
  {
    v6 = (idProjectile *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: explosionEntity, a3: -1, a4: -1, a5: -1);
    v7 = idProjectile::CastTo(c: v6);
    if ( v7 != nullptr )
    {
      v8 = result->__vftable;
      v23.type = TARGET_NONE;
      v23.presentable.spawnId = 0;
      GetEquippedWeapon = v8->GetEquippedWeapon;
      v23.pos = vec3_origin;
      v10 = GetEquippedWeapon(this: result);
      Physics = idEntity::GetPhysics(this: result);
      v12 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v13 = *(float *)(v12 + 4);
      v14 = *(float *)(v12 + 8);
      v21.x = *(float *)v12;
      v21.y = v13;
      v21.z = v14;
      if ( v10 != nullptr && idAI2::GetMuzzlePoint(this: result, weapon: v10, muzzlePos: &v22, muzzleAxis: v24) )
      {
        v21.x = v22.x;
        v21.y = v22.y;
        v21.z = v22.z;
      }
      v15 = result->__vftable;
      EquippedWeapon = idActor::GetEquippedWeapon(this: result, slot: EQUIP_RIGHT_HAND);
      v15->UnequipItem(this: result, a2: EquippedWeapon);
      v17 = result->__vftable;
      v18 = idActor::GetEquippedWeapon(this: result, slot: EQUIP_LEFT_HAND);
      v17->UnequipItem(this: result, a2: v18);
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idProjectile::Launch(
        this: v7,
        attacker_: result,
        start: &v21,
        fireAxis: &result->actorVolatile.modelInfo.modelAxis,
        target: &v23,
        initialSpeed: 0.0,
        startTime: 0x82000000,
        launchTimeOverride: GameMs);
    }
  }
  return this;
}


// ========================================================================
// ?AnimEvent_SetAimFocusToEnemy@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A30558
// RVA : 0x00A30558
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_SetAimFocusToEnemy(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  int value; // r8
  idEntity *v6; // r3
  idEntity *v7; // r4

  value = result->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  idAI2::SetAimFocusEntity(this: result, ent: v7, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
  return this;
}


// ========================================================================
// ?AnimEvent_AIReloadWeapon@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82A30600
// RVA : 0x00A30600
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_AIReloadWeapon(
        idAI2 *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const char *slotName)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  equipSlot_t v9; // r3
  idClass *v10; // r3
  idClass *v11; // r29
  idClass_vtbl *v12; // r27
  int v13; // r26
  int v14; // r3
  idPLogScope v16[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "AnimEvent_AIReloadWeapon");
  LODWORD(v7) = "AnimEvent_AIReloadWeapon";
  HIDWORD(v7) = 6;
  idPLogScope::idPLogScope(this: v16, pl: &pLog, gMask: v7, label: v8);
  v9 = idDeclInventory::EquipSlotForName(name: slotName);
  v10 = (idClass *)(*(int (__fastcall **)(eventVoid *, equipSlot_t))(*(_DWORD *)result + 740))(a1: result, a2: v9);
  v11 = v10;
  if ( v10 != nullptr )
  {
    if ( (unsigned __int8)idWeapon::IsTypeOf(c: v10) != 0 )
    {
      if ( v11[18].__vftable == (idClass_vtbl *)3 )
      {
        v12 = v11->__vftable;
        v13 = (*(int (__fastcall **)(eventVoid *, idClass *))(*(_DWORD *)result + 752))(a1: result, a2: v11);
        v14 = (*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 468))(a1: result);
        ((void (__fastcall *)(idClass *, int, int, _DWORD, _DWORD, _DWORD))v12[13].dtr_idClass)(
          a1: v11,
          a2: v14,
          a3: v13,
          a4: 0,
          a5: 0,
          a6: 0);
      }
      idPLogScope::~idPLogScope(this: v16);
    }
    else
    {
      idLib::Warning(fmt: "AnimEvent_AIReloadWeapon - tired to fire an inventory item that is not a weapon.");
      idPLogScope::~idPLogScope(this: v16);
    }
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_AIReloadWeapon - tried to fire a weapon from an empty slot.");
    idPLogScope::~idPLogScope(this: v16);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$492373
// EA  : 0x82A3073C
// RVA : 0x00A3073C
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492373()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$492374
// EA  : 0x82A30764
// RVA : 0x00A30764
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492374()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?AnimEvent_AIFireWeapon@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82A30798
// RVA : 0x00A30798
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_AIFireWeapon(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const char *slotName)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  equipSlot_t v9; // r3
  idClass *v10; // r3
  idWeapon *v11; // r27
  idFinishFireResults *v12; // r11
  int i; // ctr
  idEntity *Enemy; // r29
  double z; // fp0
  double v16; // fp8
  const idPresentable *presentable; // r28
  idPresentable *v18; // r29
  idFXManager *v20; // [sp+8h] [-AF8h]
  bool v21; // [sp+Fh] [-AF1h]
  idInventoryItem *v22; // [sp+60h] [-AA0h]
  idVec3 v23; // [sp+68h] [-A98h] BYREF
  idPLogScope v24; // [sp+78h] [-A88h] BYREF
  idVec3 v25; // [sp+80h] [-A80h] BYREF
  idMat3 v26; // [sp+90h] [-A70h] BYREF
  idFinishFireResults v27; // [sp+C0h] [-A40h] BYREF
  idFireParms v28; // [sp+110h] [-9F0h] BYREF
  idTestFireResults v29; // [sp+1B0h] [-950h] BYREF

  RD_EventBegin(name: "AnimEvent_AIFireWeapon");
  LODWORD(v7) = "AnimEvent_AIFireWeapon";
  HIDWORD(v7) = 6;
  idPLogScope::idPLogScope(this: &v24, pl: &pLog, gMask: v7, label: v8);
  v9 = idDeclInventory::EquipSlotForName(name: slotName);
  v10 = result->GetEquipped(this: result, a2: v9);
  v11 = (idWeapon *)v10;
  if ( v10 != nullptr )
  {
    if ( (unsigned __int8)idWeapon::IsTypeOf(c: v10) != 0 )
    {
      idFireParms::idFireParms(this: &v28);
      memset(&v29, 0, sizeof(v29));
      v12 = &v27;
      v27.numProjectiles = 0;
      for ( i = 16; i != 0; --i )
      {
        v12 = (idFinishFireResults *)((char *)v12 + 4);
        v12->numProjectiles = 0;
      }
      Enemy = (idEntity *)idAIMemory::GetEnemy(this: &result->aiVolatile.memory);
      if ( idAI2::GetMuzzlePoint(this: result, weapon: v11, muzzlePos: &v25, muzzleAxis: &v26) )
      {
        z = result->aiVolatile.focus.foci.ptr[0].curFocusPoint.z;
        v16 = (float)(result->aiVolatile.focus.foci.ptr[0].curFocusPoint.y - v25.y);
        v23.x = result->aiVolatile.focus.foci.ptr[0].curFocusPoint.x - v25.x;
        v23.z = (float)z - v25.z;
        v23.y = v16;
        idVec3::NormalizeFast(this: &v23);
        if ( (float)((float)(v26.mat[0].x * v23.x)
                   + (float)((float)(v26.mat[0].z * v23.z) + (float)(v26.mat[0].y * v23.y))) > 0.89999998 )
        {
          v26.mat[0].x = v23.x;
          v26.mat[0].y = v23.y;
          v26.mat[0].z = v23.z;
          idMat3::OrthoNormalizeSelf(this: &v26);
        }
        if ( v11->NeedsReload(this: v11, a2: false) )
        {
          v22 = &v11->ammoClip->idInventoryItem;
          if ( v22 != nullptr )
            idInventoryItem::ModifyCount(this: v22, amount: (const int)v11->decl[1].declSource);
        }
        if ( Enemy != nullptr )
        {
          presentable = Enemy->presentable;
          if ( presentable == nullptr )
          {
            idEntity::InitPresentableInternal(this: Enemy);
            presentable = Enemy->presentable;
          }
        }
        else
        {
          presentable = nullptr;
        }
        v18 = result->presentable;
        if ( v18 == nullptr )
        {
          idEntity::InitPresentableInternal(this: result);
          v18 = result->presentable;
        }
        result->GetFXMgrForAttachment(this: result, a2: v11);
        idWeapon::Fire(
          this: v11,
          attacker: v18,
          target: presentable,
          start: &v25,
          fireAxis: &v26,
          fp: &v28,
          tfr: &v29,
          ffr: &v27,
          fxMgr: v20,
          secondaryAmmo: v21);
        result->aiVolatile.memory.lastFireTime = idGameTimeManager::GetGameMs(
                                                   this: &clientGame->gameTimeManager,
                                                   type: GAMETIME_SCALED);
      }
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v28.targetList);
      idPLogScope::~idPLogScope(this: &v24);
    }
    else
    {
      idLib::Warning(fmt: "AnimEvent_AIFireWeapon - tired to fire an inventory item that is not a weapon.");
      idPLogScope::~idPLogScope(this: &v24);
    }
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_AIFireWeapon - tried to fire a weapon from an empty slot.");
    idPLogScope::~idPLogScope(this: &v24);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$492441
// EA  : 0x82A30A6C
// RVA : 0x00A30A6C
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492441()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 2816 + 2740));
}


// ========================================================================
// __unwind$492442
// EA  : 0x82A30A94
// RVA : 0x00A30A94
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492442()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 2816 + 120));
}


// ========================================================================
// __unwind$492443
// EA  : 0x82A30ABC
// RVA : 0x00A30ABC
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492443()
{
  int v0; // r12

  idFireParms::~idFireParms(this: (idAI2::idAIVolatile::idAIEventInfo *)(v0 - 2816 + 272));
}


// ========================================================================
// ?AnimEvent_MeleeKick@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA  : 0x82A30AF0
// RVA : 0x00A30AF0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_MeleeKick(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const idJointName *jointName)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idIndex<short,enum invalidJointIndex_t> *v11; // r28
  const idDeclAIBehavior *decl; // r11
  const idDeclDamage *closeMeleeKickDamage; // r9
  double radius; // fp13
  double v15; // fp12
  const idDeclProjectileImpactEffect *meleeImpactEffect; // r7
  const idDeclDamage *v17; // r6
  __int16 v19; // [sp+50h] [-60h] BYREF
  float v20; // [sp+54h] [-5Ch]
  idPLogScope v21; // [sp+58h] [-58h] BYREF
  idBounds v22; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "AnimEvent_MeleeKick");
  LODWORD(v7) = "AnimEvent_MeleeKick";
  HIDWORD(v7) = 6;
  idPLogScope::idPLogScope(this: &v21, pl: &pLog, gMask: v7, label: v8);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v11 = (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v19, result: v11, jointName: jointName->data);
  if ( v19 >= 0 )
  {
    decl = result->aiEditable.behaviors.decl;
    closeMeleeKickDamage = decl->closeMeleeKickDamage;
    radius = closeMeleeKickDamage->radius;
    v15 = (float)(closeMeleeKickDamage->radius * (float)-1.0);
    v22.b[1].x = closeMeleeKickDamage->radius;
    v22.b[1].y = radius;
    v22.b[1].z = radius;
    v22.b[0].y = v15;
    v22.b[0].z = v15;
    v22.b[0].x = v15;
    meleeImpactEffect = decl->meleeImpactEffect;
    v20 = v15;
    v17 = decl->closeMeleeKickDamage;
    v20 = v15;
    idAI2::DoMeleeDamage(
      this: result,
      jointIndex: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v19,
      bounds: &v22,
      damageDecl: v17,
      impactEffect: meleeImpactEffect);
  }
  idPLogScope::~idPLogScope(this: &v21);
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$492655
// EA  : 0x82A30BF0
// RVA : 0x00A30BF0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492655()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 120));
}


// ========================================================================
// __unwind$492656
// EA  : 0x82A30C18
// RVA : 0x00A30C18
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492656()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?AnimEvent_EquipItem@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82A30C48
// RVA : 0x00A30C48
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EquipItem(
        idAI2 *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const char *slotName)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  equipSlot_t v9; // r4
  int v10; // r4
  idPLogScope v12[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "AnimEvent_EquipItem");
  LODWORD(v7) = "AnimEvent_EquipItem";
  HIDWORD(v7) = 6;
  idPLogScope::idPLogScope(this: v12, pl: &pLog, gMask: v7, label: v8);
  v9 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v9 >= EQUIP_NONE) + ((unsigned int)v9 >= EQUIP_MAX)) & 1) != 0 )
  {
    v10 = (*(int (__fastcall **)(eventVoid *, equipSlot_t))(*(_DWORD *)result + 740))(a1: result, a2: v9);
    if ( v10 != 0 )
      (*(void (__fastcall **)(eventVoid *, int, _DWORD))(*(_DWORD *)result + 708))(a1: result, a2: v10, a3: 0);
    idPLogScope::~idPLogScope(this: v12);
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_EquipItem - Invalid slot name", v9);
    idPLogScope::~idPLogScope(this: v12);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$492777
// EA  : 0x82A30D2C
// RVA : 0x00A30D2C
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492777()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$492778
// EA  : 0x82A30D54
// RVA : 0x00A30D54
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492778()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?AnimEvent_HolsterItem@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82A30D88
// RVA : 0x00A30D88
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_HolsterItem(
        idAI2 *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const char *slotName)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  equipSlot_t v9; // r3
  equipSlot_t v10; // r29
  const idInventoryItem *v11; // r28
  idAttachmentCollection *v12; // r3
  idPLogScope v14[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "AnimEvent_HolsterItem");
  LODWORD(v7) = "AnimEvent_HolsterItem";
  HIDWORD(v7) = 6;
  idPLogScope::idPLogScope(this: v14, pl: &pLog, gMask: v7, label: v8);
  v9 = idDeclInventory::EquipSlotForName(name: slotName);
  v10 = v9;
  if ( (((v9 >= EQUIP_NONE) + ((unsigned int)v9 >= EQUIP_MAX)) & 1) != 0 )
  {
    v11 = (const idInventoryItem *)(*(int (__fastcall **)(eventVoid *, equipSlot_t))(*(_DWORD *)result + 740))(
                                     a1: result,
                                     a2: v9);
    if ( v11 != nullptr )
    {
      v12 = (idAttachmentCollection *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 484))(a1: result);
      idAttachmentCollection::RemoveAttachment(this: v12, item: v11);
      (*(void (__fastcall **)(eventVoid *, equipSlot_t))(*(_DWORD *)result + 748))(a1: result, a2: v10);
      (*(void (__fastcall **)(eventVoid *, const idInventoryItem *, _DWORD))(*(_DWORD *)result + 716))(
        a1: result,
        a2: v11,
        a3: 0);
    }
    else
    {
      idLib::Warning(fmt: "AnimEvent_HolsterItem - Attempting to holster from empty slot");
    }
    idPLogScope::~idPLogScope(this: v14);
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_HolsterItem - Invalid slot name");
    idPLogScope::~idPLogScope(this: v14);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$492832
// EA  : 0x82A30EB4
// RVA : 0x00A30EB4
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492832()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$492833
// EA  : 0x82A30EDC
// RVA : 0x00A30EDC
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492833()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?AnimEvent_DropAttachment@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82A30F10
// RVA : 0x00A30F10
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_DropAttachment(
        idAI2 *this,
        eventVoid *result,
        const idMD6Anim *anim,
        const char *slotName)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  equipSlot_t v10; // r4
  int v11; // r4
  idPLogScope v13[10]; // [sp+50h] [-50h] BYREF

  RD_EventBegin(name: "AnimEvent_DropAttachment");
  LODWORD(v8) = "AnimEvent_DropAttachment";
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: v13, pl: &pLog, gMask: v8, label: v9);
  v10 = idDeclInventory::EquipSlotForName(name: slotName);
  if ( (((v10 >= EQUIP_NONE) + ((unsigned int)v10 >= EQUIP_MAX)) & 1) != 0 )
  {
    v11 = (*(int (__fastcall **)(eventVoid *, equipSlot_t))(*(_DWORD *)result + 740))(a1: result, a2: v10);
    if ( v11 != 0 )
      (*(void (__fastcall **)(eventVoid *, int))(*(_DWORD *)result + 732))(a1: result, a2: v11);
    idPLogScope::~idPLogScope(this: v13);
  }
  else
  {
    idLib::Warning(fmt: "AnimEvent_DropAttachment - Invalid slot name for animation %s", anim->name.str);
    idPLogScope::~idPLogScope(this: v13);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$492887
// EA  : 0x82A30FF8
// RVA : 0x00A30FF8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492887()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$492888
// EA  : 0x82A31020
// RVA : 0x00A31020
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492888()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 80));
}


// ========================================================================
// ?AnimEvent_MeleePunch@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA  : 0x82A31050
// RVA : 0x00A31050
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_MeleePunch(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const idJointName *jointName)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idIndex<short,enum invalidJointIndex_t> *v11; // r28
  const idDeclAIBehavior *decl; // r11
  const idDeclDamage *closeMeleePunchDamage; // r9
  double radius; // fp13
  double v15; // fp12
  const idDeclProjectileImpactEffect *meleeImpactEffect; // r7
  const idDeclDamage *v17; // r6
  __int16 v19; // [sp+50h] [-60h] BYREF
  float v20; // [sp+54h] [-5Ch]
  idPLogScope v21; // [sp+58h] [-58h] BYREF
  idBounds v22; // [sp+60h] [-50h] BYREF

  RD_EventBegin(name: "AnimEvent_MeleePunch");
  LODWORD(v7) = "AnimEvent_MeleePunch";
  HIDWORD(v7) = 6;
  idPLogScope::idPLogScope(this: &v21, pl: &pLog, gMask: v7, label: v8);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v11 = (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v19, result: v11, jointName: jointName->data);
  if ( v19 >= 0 )
  {
    decl = result->aiEditable.behaviors.decl;
    closeMeleePunchDamage = decl->closeMeleePunchDamage;
    radius = closeMeleePunchDamage->radius;
    v15 = (float)(closeMeleePunchDamage->radius * (float)-1.0);
    v22.b[1].x = closeMeleePunchDamage->radius;
    v22.b[1].y = radius;
    v22.b[1].z = radius;
    v22.b[0].y = v15;
    v22.b[0].z = v15;
    v22.b[0].x = v15;
    meleeImpactEffect = decl->meleeImpactEffect;
    v20 = v15;
    v17 = decl->closeMeleePunchDamage;
    v20 = v15;
    idAI2::DoMeleeDamage(
      this: result,
      jointIndex: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v19,
      bounds: &v22,
      damageDecl: v17,
      impactEffect: meleeImpactEffect);
  }
  idPLogScope::~idPLogScope(this: &v21);
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$492950
// EA  : 0x82A31150
// RVA : 0x00A31150
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492950()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 120));
}


// ========================================================================
// __unwind$492951
// EA  : 0x82A31178
// RVA : 0x00A31178
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_492951()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 88));
}


// ========================================================================
// ?AnimEvent_PushEntity@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A311A8
// RVA : 0x00A311A8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_PushEntity(idAI2 *this, idEntity *result, const idMD6Anim *anim)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  idGameLocal *v7; // r11
  int prev; // r9
  idEntity *v9; // r3
  idEntity *v10; // r28
  int v11; // r29
  idPlayer *Player; // r30
  idPhysics *Physics; // r3
  float *v14; // r22
  idPhysics *v15; // r3
  float *v16; // r3
  double v17; // fp9
  double v18; // fp5
  idPhysics *v19; // r3
  double v20; // fp31
  idPhysics *v21; // r30
  idPhysics *v22; // r29
  float *v23; // r30
  float *v24; // r3
  double v25; // fp30
  double v26; // fp29
  idPhysics *v27; // r3
  const idVec3 *v28; // r3
  float y; // r7
  float z; // r6
  idPhysics *v31; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v33; // r30
  int v34; // r3
  __int64 totalTicks; // r11
  __int64 v36; // r9
  idPLogScope v38; // [sp+50h] [-A0h] BYREF
  _DWORD v39[4]; // [sp+58h] [-98h] BYREF
  float v40[6]; // [sp+68h] [-88h] BYREF

  RD_EventBegin(name: "AnimEvent_PushEntity");
  LODWORD(v5) = "AnimEvent_PushEntity";
  HIDWORD(v5) = 6;
  idPLogScope::idPLogScope(this: &v38, pl: &::pLog, gMask: v5, label: v6);
  v7 = gameLocal;
  prev = (int)result[72].removeNode.prev;
  if ( gameLocal->spawnIds.ptr[prev & 0x1FFF] == prev >> 13 )
  {
    v9 = gameLocal->entities.ptr[prev & 0x1FFF];
    if ( v9 != nullptr )
    {
      v9 = idEntity::CastTo(c: v9);
      v7 = gameLocal;
    }
  }
  else
  {
    v9 = nullptr;
  }
  v10 = v9;
  if ( v9 != nullptr )
    goto LABEL_13;
  v11 = 0;
  while ( 1 )
  {
    Player = idGameLocal::GetPlayer(this: v7, i: v11);
    if ( Player != nullptr )
    {
      Physics = idEntity::GetPhysics(this: result);
      v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v15 = idEntity::GetPhysics(this: Player);
      v16 = (float *)v15->GetOrigin(this: v15, a2: 0);
      v17 = (float)(v14[1] - v16[1]);
      v18 = (float)(v14[2] - v16[2]);
      if ( __fsqrts((float)((float)((float)v18 * (float)v18)
                          + (float)((float)((float)(*v14 - *v16) * (float)(*v14 - *v16))
                                  + (float)((float)v17 * (float)v17)))) < 64.0 )
        v10 = Player;
    }
    if ( ++v11 >= 6 )
      break;
    v7 = gameLocal;
  }
  if ( v10 != nullptr )
  {
LABEL_13:
    v19 = idEntity::GetPhysics(this: v10);
    v20 = ((double (__fastcall *)(idPhysics *, int))v19->GetMass)(a1: v19, a2: -1);
    v21 = idEntity::GetPhysics(this: result);
    v22 = idEntity::GetPhysics(this: v10);
    v23 = (float *)v21->GetOrigin(this: v21, a2: 0);
    v24 = (float *)v22->GetOrigin(this: v22, a2: 0);
    v25 = (float)(v24[1] - v23[1]);
    v26 = (float)(*v24 - *v23);
    v27 = idEntity::GetPhysics(this: v10);
    v28 = v27->GetOrigin(this: v27, a2: 0);
    y = v28->y;
    z = v28->z;
    v39[0] = LODWORD(v28->x);
    *(float *)&v39[1] = y;
    *(float *)&v39[2] = z;
    v31 = idEntity::GetPhysics(this: v10);
    v40[1] = (float)((float)v25 * (float)v20) * (float)10.0;
    v40[0] = (float)((float)v26 * (float)v20) * (float)10.0;
    v40[2] = (float)((float)v20 * (float)0.0) * (float)10.0;
    v31->ApplyImpulse(this: v31, a2: 0, a3: (const idVec3 *)v39, a4: (const idVec3 *)v40);
    result[72].removeNode.prev = (idLinkList<idEntity> *)0x1FFF;
  }
  if ( v38.logIndex >= 0 )
  {
    pLog = v38.pLog;
    v33 = &v38.pLog->logEntries.list[v38.logIndex];
    v34 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v33->totalTicks;
    HIDWORD(totalTicks) = v33->parent;
    LODWORD(v36) = v34 - totalTicks;
    v33->totalTicks = v36;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$493070
// EA  : 0x82A31480
// RVA : 0x00A31480
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493070()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 116));
}


// ========================================================================
// __unwind$493071
// EA  : 0x82A314A8
// RVA : 0x00A314A8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493071()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 80));
}


// ========================================================================
// ?AnimEvent_LaunchItem@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA  : 0x82A314D8
// RVA : 0x00A314D8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_LaunchItem(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const idJointName *jointName)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int value; // r8
  const idDeclInventory *itemDecl; // r7
  const idDeclProjectile *v10; // r25
  idEntity *v11; // r3
  idEntity *v12; // r27
  aiSenseState_t *v13; // r28
  idWeapon *v14; // r3
  idEntity *v15; // r3
  idAIEntityState *v16; // r3
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  int v18; // r3
  idVec3 *p_velocity; // r11
  float y; // r9
  float z; // r8
  idVec3 *p_eyePos; // r11
  float v23; // r7
  float v24; // r5
  idAI2::aiCondition_t condition; // r10
  const idDeclAIBehavior *decl; // r23
  aiSkill_t ModifiedSkill; // r28
  __int64 v28; // r6
  double v29; // fp31
  __int64 v30; // r6
  double v31; // fp30
  __int64 v32; // r6
  double v33; // fp1
  int v34; // r9
  double v35; // fp29
  double v36; // fp31
  double v37; // fp30
  float *presentable; // r11
  double v39; // fp9
  const idVec3 *v40; // r5
  idVec3 v42; // [sp+50h] [-120h] BYREF
  float x; // [sp+60h] [-110h]
  float v44; // [sp+64h] [-10Ch]
  float v45; // [sp+68h] [-108h]
  eventVoid *p_target; // [sp+6Ch] [-104h]
  idVec3 v47; // [sp+70h] [-100h]
  idVec3 v48; // [sp+80h] [-F0h] BYREF
  idPLogScope v49; // [sp+90h] [-E0h] BYREF
  idVec3 v50; // [sp+98h] [-D8h] BYREF
  idVec3 v51; // [sp+A8h] [-C8h] BYREF
  idVec3 v52[2]; // [sp+B8h] [-B8h] BYREF
  idMat3 v53; // [sp+D0h] [-A0h] BYREF

  RD_EventBegin(name: "AnimEvent_LaunchItem");
  LODWORD(v6) = "AnimEvent_LaunchItem";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v49, pl: &pLog, gMask: v6, label: v7);
  value = result->aiVolatile.memory.projectileInfo.target.spawnId.value;
  itemDecl = result->aiVolatile.memory.projectileInfo.itemDecl;
  p_target = (eventVoid *)&result->aiVolatile.memory.projectileInfo.target;
  v10 = (const idDeclProjectile *)itemDecl[1].__vftable;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
  {
    v12 = nullptr;
    goto LABEL_4;
  }
  v11 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v11 == nullptr )
  {
    v12 = nullptr;
LABEL_4:
    v13 = nullptr;
    goto LABEL_5;
  }
  v15 = idEntity::CastTo(c: v11);
  v12 = v15;
  if ( v15 == nullptr )
    goto LABEL_4;
  v16 = idAIWorldState::StateForEntity(this: &result->aiVolatile.world.worldState, ent: v15);
  if ( v16 == nullptr )
    goto LABEL_4;
  v13 = v16->senses.ptr[1];
LABEL_5:
  if ( result->aiVolatile.memory.projectileInfo.useMuzzleForLaunch )
  {
    if ( result->GetEquippedWeapon(this: result) != nullptr )
    {
      v14 = result->GetEquippedWeapon(this: result);
      if ( !idAI2::GetMuzzlePoint(this: result, weapon: v14, muzzlePos: &v48, muzzleAxis: &v53) )
      {
        idLib::Warning(
          fmt: "idAI2::AnimEvent_LaunchItem: could not find muzzle point for AI %s equipped weapon",
          result->name.data);
        idPLogScope::~idPLogScope(this: &v49);
        goto LABEL_33;
      }
    }
  }
  else
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: TreeAnimatorFromPresentable,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)result->aiVolatile.memory.projectileInfo.jointIndex.value,
      origin: &v48,
      axis: &v53);
  }
  if ( v10->notHitscanInfo.parabolicFlight )
  {
    v18 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idAI2::LaunchParabolicProjectile(
      this: result,
      projDecl: v10,
      trajectoryParms: &result->aiVolatile.memory.projectileInfo.parabolicParms,
      targetPos: &result->aiVolatile.memory.projectileInfo.predictedTargetPos,
      startPos: &v48,
      startTime: v18);
  }
  else
  {
    if ( v13 != nullptr )
      p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v13)->velocity;
    else
      p_velocity = &result->aiVolatile.memory.projectileInfo.actualTargetVel;
    y = p_velocity->y;
    z = p_velocity->z;
    v42.x = p_velocity->x;
    v42.y = y;
    v42.z = z;
    if ( v13 != nullptr )
      p_eyePos = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v13)->eyePos;
    else
      p_eyePos = &result->aiVolatile.memory.projectileInfo.actualTargetPos;
    v23 = p_eyePos->y;
    v24 = p_eyePos->z;
    x = p_eyePos->x;
    condition = result->aiVolatile.groupStatus.condition;
    v44 = v23;
    v45 = v24;
    v47 = vec3_origin;
    if ( (condition & 0x2000) != 0 )
    {
      v36 = v47.z;
      v37 = v47.y;
      v35 = v47.x;
    }
    else
    {
      decl = result->aiEditable.behaviors.decl;
      ModifiedSkill = idAI2::GetModifiedSkill(this: result);
      v29 = (float)(idRandom2::BellCurve(this: &clientGame->random, degree: v28) * (float)0.5);
      v31 = idRandom2::BellCurve(this: &clientGame->random, degree: v30);
      v33 = idRandom2::BellCurve(this: &clientGame->random, degree: v32);
      v34 = 4 * (ModifiedSkill + 59);
      v35 = (float)(*(float *)((char *)&decl->__vftable + v34) * (float)v33);
      v36 = (float)(*(float *)((char *)&decl->__vftable + v34) * (float)v29);
      v37 = (float)(*(float *)((char *)&decl->__vftable + v34) * (float)v31);
      if ( v12 != nullptr )
      {
        presentable = (float *)v12->presentable;
        if ( presentable == nullptr )
        {
          idEntity::InitPresentableInternal(this: v12);
          presentable = (float *)v12->presentable;
        }
        v39 = (float)((float)(presentable[33] * (float)v35)
                    + (float)((float)(presentable[34] * (float)v37) + (float)(presentable[35] * (float)v36)));
        p_target = (eventVoid *)(presentable + 33);
        if ( v39 < 0.0 )
        {
          v36 = -v36;
          v37 = -v37;
          v35 = -v35;
        }
      }
      if ( ((LODWORD(v42.y) | LODWORD(v42.z) | LODWORD(v42.x)) & 0x7FFFFFFF) == 0 )
      {
        v35 = (float)((float)v35 * (float)0.60000002);
        v37 = (float)((float)v37 * (float)0.60000002);
        v36 = (float)((float)v36 * (float)0.60000002);
      }
    }
    v50.x = x + (float)v35;
    v50.z = v45 + (float)v36;
    v50.y = v44 + (float)v37;
    idAI2::LeadTargetWithLinearProjectile(
      this: result,
      info: &result->aiVolatile.memory.projectileInfo,
      curTargetPos: &v50,
      curTargetVel: &v42,
      projStartPos: &v48,
      extrapolatedPos: v52,
      dirToExtrapolatedPos: &v51);
    gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idAI2::LaunchLinearProjectile(
      this: result,
      projDecl: v10,
      speed: result->aiVolatile.memory.projectileInfo.linearParms.speed,
      startPos: v40,
      targetPos: &v48,
      launchDir: v52,
      startTime: (const int)&v51);
  }
  idPLogScope::~idPLogScope(this: &v49);
LABEL_33:
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$493380
// EA  : 0x82A318CC
// RVA : 0x00A318CC
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493380()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 368 + 244));
}


// ========================================================================
// __unwind$493381
// EA  : 0x82A318F4
// RVA : 0x00A318F4
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493381()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 368 + 144));
}


// ========================================================================
// ?AnimEvent_LaunchItemFromWeapon@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@PBD@Z
// EA  : 0x82A31928
// RVA : 0x00A31928
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_LaunchItemFromWeapon(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const idJointName *jointName,
        const char *tagName)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  int value; // r8
  const idDeclInventory *itemDecl; // r7
  const idDeclProjectile *v12; // r24
  idEntity *v13; // r3
  idEntity *v14; // r4
  idAIEntityState *v15; // r3
  aiSenseState_t *v16; // r26
  idTreeAnimator *EquippedWeaponAnimator; // r3
  idTreeAnimator *v18; // r28
  idPropsCollection *decl; // r11
  const tagData_t *Tag; // r3
  int v21; // r3
  idVec3 *p_velocity; // r11
  float y; // r9
  float z; // r8
  idVec3 *p_eyePos; // r11
  float v26; // r3
  float x; // r10
  float v28; // r11
  const idVec3 *v29; // r5
  tagData_t v31; // [sp+50h] [-100h] BYREF
  eventVoid *p_target; // [sp+70h] [-E0h]
  idPLogScope v33; // [sp+78h] [-D8h] BYREF
  idVec3 v34; // [sp+80h] [-D0h] BYREF
  idVec3 v35; // [sp+90h] [-C0h] BYREF
  idVec3 v36; // [sp+A0h] [-B0h] BYREF
  idVec3 v37; // [sp+B0h] [-A0h] BYREF
  idVec3 v38; // [sp+C0h] [-90h] BYREF
  idMat3 v39[3]; // [sp+D0h] [-80h] BYREF

  RD_EventBegin(name: "AnimEvent_LaunchItemFromWeapon");
  LODWORD(v8) = "AnimEvent_LaunchItemFromWeapon";
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: &v33, pl: &pLog, gMask: v8, label: v9);
  value = result->aiVolatile.memory.projectileInfo.target.spawnId.value;
  itemDecl = result->aiVolatile.memory.projectileInfo.itemDecl;
  p_target = (eventVoid *)&result->aiVolatile.memory.projectileInfo.target;
  v12 = (const idDeclProjectile *)itemDecl[1].__vftable;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v13 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v14 = idEntity::CastTo(c: v13)) != nullptr
    && (v15 = idAIWorldState::StateForEntity(this: &result->aiVolatile.world.worldState, ent: v14)) != nullptr )
  {
    v16 = v15->senses.ptr[1];
  }
  else
  {
    v16 = nullptr;
  }
  EquippedWeaponAnimator = idActor::GetEquippedWeaponAnimator(this: result);
  v18 = EquippedWeaponAnimator;
  if ( EquippedWeaponAnimator != nullptr )
  {
    decl = (idPropsCollection *)EquippedWeaponAnimator->decl;
    if ( decl == nullptr || decl == (idPropsCollection *)-352 )
    {
      idLib::Warning(fmt: "idAI2::AnimEvent_LaunchItemFromWeapon could not find props");
    }
    else
    {
      v31.parentJoint.value = -1;
      v31.trans.x = 0.0;
      v31.trans.y = 0.0;
      v31.trans.z = 0.0;
      v31.rot.x = 0.0;
      v31.rot.y = 0.0;
      v31.rot.z = 0.0;
      v31.rot.w = 0.0;
      Tag = idPropsCollection::GetTag(this: decl + 22, propName: idPropInfo::INFO_PROP_NAME, tagName);
      v31.trans.x = Tag->trans.x;
      v31.trans.y = Tag->trans.y;
      p_target = (eventVoid *)&Tag->rot;
      v31.trans.z = Tag->trans.z;
      v31.rot = Tag->rot;
      v31.parentJoint.value = Tag->parentJoint.value;
      if ( v31.parentJoint.value == 0xFFFF )
      {
        idLib::Warning(fmt: "idAI2::AnimEvent_LaunchItemFromWeapon bad tag data");
      }
      else if ( result->GetEquippedWeapon(this: result)->decl != nullptr
             && (unsigned __int8)idTreeAnimator::GetWorldSpaceTagTransform(
                                   this: v18,
                                   tagData: &v31,
                                   origin: &v34,
                                   axis: v39) != 0 )
      {
        if ( v12->notHitscanInfo.parabolicFlight )
        {
          v21 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          idAI2::LaunchParabolicProjectile(
            this: result,
            projDecl: v12,
            trajectoryParms: &result->aiVolatile.memory.projectileInfo.parabolicParms,
            targetPos: &result->aiVolatile.memory.projectileInfo.predictedTargetPos,
            startPos: &v34,
            startTime: v21);
        }
        else
        {
          if ( v16 != nullptr )
            p_velocity = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v16)->velocity;
          else
            p_velocity = &result->aiVolatile.memory.projectileInfo.actualTargetVel;
          y = p_velocity->y;
          z = p_velocity->z;
          v36.x = p_velocity->x;
          v36.y = y;
          v36.z = z;
          if ( v16 != nullptr )
            p_eyePos = &aiSenseState_t::GetConfirmedPhysicalSafe(this: v16)->eyePos;
          else
            p_eyePos = &result->aiVolatile.memory.projectileInfo.actualTargetPos;
          v26 = p_eyePos->y;
          x = p_eyePos->x;
          v28 = p_eyePos->z;
          v35.y = v26;
          v35.x = x;
          v35.z = v28;
          idAI2::LeadTargetWithLinearProjectile(
            this: result,
            info: &result->aiVolatile.memory.projectileInfo,
            curTargetPos: &v35,
            curTargetVel: &v36,
            projStartPos: &v34,
            extrapolatedPos: &v37,
            dirToExtrapolatedPos: &v38);
          gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          idAI2::LaunchLinearProjectile(
            this: result,
            projDecl: v12,
            speed: result->aiVolatile.memory.projectileInfo.linearParms.speed,
            startPos: v29,
            targetPos: &v34,
            launchDir: &v37,
            startTime: (const int)&v38);
        }
      }
    }
    idPLogScope::~idPLogScope(this: &v33);
  }
  else
  {
    idLib::Warning(fmt: "idAI2::AnimEvent_LaunchItemFromWeapon - could not get weapon animator");
    idPLogScope::~idPLogScope(this: &v33);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$493594
// EA  : 0x82A31C34
// RVA : 0x00A31C34
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493594()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 336 + 244));
}


// ========================================================================
// __unwind$493595
// EA  : 0x82A31C5C
// RVA : 0x00A31C5C
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493595()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 336 + 120));
}


// ========================================================================
// ?AnimEvent_ThrowGrenade@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA  : 0x82A31C90
// RVA : 0x00A31C90
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_ThrowGrenade(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const idJointName *jointName)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  const idDeclInventory *itemDecl; // r11
  const idDeclProjectile *v9; // r29
  idTreeAnimator *TreeAnimatorFromPresentable; // r28
  idPresentable *presentable; // r3
  int v12; // r3
  int v13; // r8
  int maxDetonationDelay; // r10
  int v16; // [sp+54h] [-7Ch]
  idPLogScope v17; // [sp+58h] [-78h] BYREF
  idVec3 v18; // [sp+60h] [-70h] BYREF
  idMat3 v19[2]; // [sp+70h] [-60h] BYREF

  RD_EventBegin(name: "AnimEvent_ThrowGrenade");
  LODWORD(v6) = "AnimEvent_ThrowGrenade";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v17, pl: &pLog, gMask: v6, label: v7);
  itemDecl = result->aiVolatile.memory.projectileInfo.itemDecl;
  if ( itemDecl != nullptr && (v9 = (const idDeclProjectile *)itemDecl[1].__vftable) != nullptr )
  {
    TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    presentable = result->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = result->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    idTreeAnimator::GetWorldSpaceJointTransform(
      this: TreeAnimatorFromPresentable,
      pose: DRIVER_MODEL,
      jointIndex: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)result->aiVolatile.memory.projectileInfo.jointIndex.value,
      origin: &v18,
      axis: v19);
    v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    v13 = v12;
    if ( v9->notHitscanInfo.grenadeInfo.cookable && ai_cookGrenades.valueInteger >= 1 )
    {
      maxDetonationDelay = v9->notHitscanInfo.grenadeInfo.maxDetonationDelay;
      v16 = (int)(float)(result->aiVolatile.memory.projectileInfo.parabolicParms.time * (float)1000.0);
      if ( maxDetonationDelay - v16 > 0 )
        v13 = v12 - (maxDetonationDelay - v16);
    }
    idAI2::LaunchParabolicProjectile(
      this: result,
      projDecl: v9,
      trajectoryParms: &result->aiVolatile.memory.projectileInfo.parabolicParms,
      targetPos: &result->aiVolatile.memory.projectileInfo.predictedTargetPos,
      startPos: &v18,
      startTime: v13);
    idPLogScope::~idPLogScope(this: &v17);
  }
  else
  {
    idPLogScope::~idPLogScope(this: &v17);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$493753
// EA  : 0x82A31E14
// RVA : 0x00A31E14
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493753()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 208 + 148));
}


// ========================================================================
// __unwind$493754
// EA  : 0x82A31E3C
// RVA : 0x00A31E3C
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493754()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 208 + 88));
}


// ========================================================================
// ?AnimEvent_VoiceOver@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82A31E70
// RVA : 0x00A31E70
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_VoiceOver(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        const idDeclVoiceOver *vo)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  idPLogScope v10[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "AnimEvent_VoiceOver");
  LODWORD(v7) = "AnimEvent_VoiceOver";
  HIDWORD(v7) = 6;
  idPLogScope::idPLogScope(this: v10, pl: &pLog, gMask: v7, label: v8);
  if ( vo != nullptr )
    idAIVoiceController::PlayVoiceOver(
      this: &result->aiVolatile.voiceController,
      ai: result,
      vo,
      priority: AIVOICEPRIORITY_MED,
      samePriorityInterupts: true);
  else
    idLib::Warning(fmt: "Invalid voice over decl specified for AnimEvent_VoiceOver");
  idPLogScope::~idPLogScope(this: v10);
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$493841
// EA  : 0x82A31F08
// RVA : 0x00A31F08
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493841()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$493842
// EA  : 0x82A31F30
// RVA : 0x00A31F30
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493842()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?AnimEvent_StopVoiceOver@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A31F60
// RVA : 0x00A31F60
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_StopVoiceOver(idAI2 *this, idAI2 *result, const idMD6Anim *anim)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPLogScope v9[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "AnimEvent_StopVoiceOver");
  LODWORD(v5) = "AnimEvent_StopVoiceOver";
  HIDWORD(v5) = 6;
  idPLogScope::idPLogScope(this: v9, pl: &pLog, gMask: v5, label: v6);
  idAIVoiceController::StopVoiceOver(this: &result->aiVolatile.voiceController, ai: result);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  idFaceMgr::Reset(this: &result->aiVolatile.faceMgr, owner: result, ta: TreeAnimatorFromPresentable);
  idPLogScope::~idPLogScope(this: v9);
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$493890
// EA  : 0x82A31FE4
// RVA : 0x00A31FE4
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493890()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$493891
// EA  : 0x82A3200C
// RVA : 0x00A3200C
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493891()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?AnimEvent_StartMeleeTrace@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@@Z
// EA  : 0x82A32040
// RVA : 0x00A32040
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_StartMeleeTrace(
        idAI2 *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim,
        const idJointName *jointName)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idIndex<short,enum invalidJointIndex_t> *v11; // r28
  int v12; // r28
  int v13; // r29
  double v14; // fp0
  const idTreeAnimator *v15; // r3
  __int16 v17; // [sp+60h] [-50h] BYREF
  idPLogScope v18[9]; // [sp+68h] [-48h] BYREF

  RD_EventBegin(name: "AnimEvent_StartMeleeTrace");
  LODWORD(v7) = "AnimEvent_StartMeleeTrace";
  HIDWORD(v7) = 6;
  idPLogScope::idPLogScope(this: v18, pl: &pLog, gMask: v7, label: v8);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v11 = (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v17, result: v11, jointName: jointName->data);
  if ( v17 >= 0 )
  {
    v12 = *(_DWORD *)&result[2].animStack.md6Allocator.nodesToDelete.granularity;
    v13 = 2;
    v14 = *(float *)(*(_DWORD *)(v12 + 636) + 200);
    if ( v14 == 8.0 )
    {
      v13 = 1;
    }
    else if ( v14 == 16.0 )
    {
      v13 = 2;
    }
    else if ( v14 == 24.0 )
    {
      v13 = 3;
    }
    else if ( v14 == 32.0 )
    {
      v13 = 4;
    }
    else
    {
      idLib::Warning(
        fmt: "AnimEvent_StartMeleeTrace %s damage decl must have radius of 8, 16, 24, or 32",
        result->name.data);
    }
    v15 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    idMeleeTrace::Start(
      this: (idMeleeTrace *)&result[11].animEventHandler.triggeredEvents.num,
      ta: v15,
      jointIndex_: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v17,
      numSamples_: 100,
      damageCap_: 100.0,
      meleeType_: *(const idMeleeTrace::meleeDamage_t *)(v12 + 644),
      boundsType_: BOUNDS_8x8,
      damageDef_: (const idDeclDamage *)v13,
      impactEffect_: *(const idDeclProjectileImpactEffect **)(v12 + 636));
    idPLogScope::~idPLogScope(this: v18);
  }
  else
  {
    idPLogScope::~idPLogScope(this: v18);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$493932
// EA  : 0x82A321B0
// RVA : 0x00A321B0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493932()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$493933
// EA  : 0x82A321D8
// RVA : 0x00A321D8
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_493933()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 104));
}


// ========================================================================
// ?AnimEvent_StartMeleeTrace2@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@ABVidJointName@@1PBVidDeclDamage@@@Z
// EA  : 0x82A32208
// RVA : 0x00A32208
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_StartMeleeTrace2(
        idAI2 *this,
        idAnimatedEntity *result,
        const idMD6Anim *anim,
        const idJointName *jointName,
        const idJointName *jointName2,
        const idDeclDamage *damageDecl)
{
  unsigned __int64 v11; // r6
  const char *v12; // r7
  idTreeAnimator *TreeAnimatorFromPresentable; // r3
  idPresentable *presentable; // r11
  idIndex<short,enum invalidJointIndex_t> *v15; // r29
  int v16; // r26
  const idDeclDamage *v17; // r28
  double radius; // fp0
  int v19; // r29
  const idTreeAnimator *v20; // r3
  const idDeclProjectileImpactEffect *v22; // [sp+8h] [-B8h]
  __int16 v23; // [sp+60h] [-60h] BYREF
  unsigned __int16 v24; // [sp+62h] [-5Eh] BYREF
  idPLogScope v25[11]; // [sp+68h] [-58h] BYREF

  RD_EventBegin(name: "AnimEvent_StartMeleeTrace2");
  LODWORD(v11) = "AnimEvent_StartMeleeTrace2";
  HIDWORD(v11) = 6;
  idPLogScope::idPLogScope(this: v25, pl: &pLog, gMask: v11, label: v12);
  TreeAnimatorFromPresentable = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
  presentable = result->presentable;
  v15 = (idIndex<short,enum invalidJointIndex_t> *)TreeAnimatorFromPresentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this: result);
    presentable = result->presentable;
  }
  idPresentable::UpdateModelTransform(this: presentable);
  idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v23, result: v15, jointName: jointName->data);
  if ( v23 >= 0 )
  {
    idTreeAnimator::GetJointIndex(this: (idTreeAnimator *)&v24, result: v15, jointName: jointName2->data);
    v16 = *(_DWORD *)&result[2].animStack.md6Allocator.nodesToDelete.granularity;
    v17 = *(const idDeclDamage **)(v16 + 636);
    if ( damageDecl != nullptr && !idDecl::IsImplicit(this: &damageDecl->idDeclTypeInfo) )
      v17 = damageDecl;
    radius = v17->radius;
    v19 = 2;
    if ( radius == 8.0 )
    {
      v19 = 1;
    }
    else if ( radius == 16.0 )
    {
      v19 = 2;
    }
    else if ( radius == 24.0 )
    {
      v19 = 3;
    }
    else if ( radius == 32.0 )
    {
      v19 = 4;
    }
    else
    {
      idLib::Warning(
        fmt: "AnimEvent_StartMeleeTrace %s damage decl must have radius of 8, 16, 24, or 32",
        result->name.data);
    }
    v20 = idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    idMeleeTrace::Start(
      this: (idMeleeTrace *)&result[11].animEventHandler.triggeredEvents.num,
      ta: v20,
      jointIndex_: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v23,
      jointIndex2_: (const idIndex<short,enum invalidJointIndex_t> *)v24,
      numSamples_: 100,
      damageCap_: 100.0,
      meleeType_: *(const idMeleeTrace::meleeDamage_t *)(v16 + 644),
      boundsType_: BOUNDS_8x8,
      damageDef_: (const idDeclDamage *)v19,
      impactEffect_: v22);
    idPLogScope::~idPLogScope(this: v25);
  }
  else
  {
    idPLogScope::~idPLogScope(this: v25);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$494023
// EA  : 0x82A323B4
// RVA : 0x00A323B4
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_494023()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$494024
// EA  : 0x82A323DC
// RVA : 0x00A323DC
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_494024()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 104));
}


// ========================================================================
// ?AnimEvent_StartMeleeTraceTag@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBD@Z
// EA  : 0x82A32410
// RVA : 0x00A32410
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_StartMeleeTraceTag(
        idAI2 *this,
        idActor *result,
        const idMD6Anim *anim,
        const char *tagName)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  int v9; // r29
  int v10; // r30
  double v11; // fp0
  const idDeclProjectileImpactEffect *v13; // [sp+8h] [-D8h]
  bool v14; // [sp+60h] [-80h] BYREF
  idPLogScope v15; // [sp+68h] [-78h] BYREF
  idVec3 v16; // [sp+70h] [-70h] BYREF
  tagData_t v17[3]; // [sp+80h] [-60h] BYREF

  RD_EventBegin(name: "AnimEvent_StartMeleeTraceTag");
  LODWORD(v7) = "AnimEvent_StartMeleeTraceTag";
  HIDWORD(v7) = 6;
  idPLogScope::idPLogScope(this: &v15, pl: &pLog, gMask: v7, label: v8);
  v17[0].parentJoint.value = -1;
  v17[0].trans.x = 0.0;
  v17[0].trans.y = 0.0;
  v17[0].trans.z = 0.0;
  v17[0].rot.x = 0.0;
  v17[0].rot.y = 0.0;
  v17[0].rot.z = 0.0;
  v17[0].rot.w = 0.0;
  if ( idActor::GetMeleeTagData(this: result, tagName, outTagData: v17, outOrigin: &v16, outUseWeaponAnimator: &v14) )
  {
    if ( result->GetEquippedWeapon(this: result)->decl != nullptr )
    {
      v9 = *(_DWORD *)&result[1].animStack.branchMemory[18];
      v10 = 3;
      v11 = *(float *)(*(_DWORD *)(v9 + 636) + 200);
      if ( v11 == 8.0 )
      {
        v10 = 1;
      }
      else if ( v11 == 16.0 )
      {
        v10 = 2;
      }
      else if ( v11 == 24.0 )
      {
        v10 = 3;
      }
      else if ( v11 == 32.0 )
      {
        v10 = 4;
      }
      else if ( v11 == 48.0 )
      {
        v10 = 5;
      }
      else if ( v11 == 96.0 )
      {
        v10 = 6;
      }
      else
      {
        idLib::Warning(
          fmt: "AnimEvent_StartMeleeTraceTag %s damage decl must have radius of 8, 16, 24, or 32",
          result->name.data);
      }
      idMeleeTrace::Start(
        this: (idMeleeTrace *)&result[5].inventory.net_addedItems[14].setCount,
        startPos: &v16,
        tagData_: v17,
        useWeaponAnimator_: v14,
        numSamples_: 100,
        damageCap_: 100.0,
        meleeType_: *(const idMeleeTrace::meleeDamage_t *)(v9 + 644),
        bounds_: BOUNDS_8x8,
        damageDef_: (const idDeclDamage *)v10,
        impactEffect_: v13);
      idPLogScope::~idPLogScope(this: &v15);
    }
    else
    {
      idPLogScope::~idPLogScope(this: &v15);
    }
  }
  else
  {
    idLib::Warning(fmt: "idAI2::AnimEvent_StartMeleeTraceTag - could not get tag data");
    idPLogScope::~idPLogScope(this: &v15);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$494117
// EA  : 0x82A325EC
// RVA : 0x00A325EC
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_494117()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 160));
}


// ========================================================================
// __unwind$494118
// EA  : 0x82A32614
// RVA : 0x00A32614
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_494118()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 104));
}


// ========================================================================
// ?AnimEvent_StartMeleeTraceTag2@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@PBDABVidJointName@@PBVidDeclDamage@@@Z
// EA  : 0x82A32648
// RVA : 0x00A32648
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_StartMeleeTraceTag2(
        idAI2 *this,
        idActor *result,
        const idMD6Anim *anim,
        const char *tagName,
        const idJointName *jointName2,
        const idDeclDamage *damageDecl)
{
  unsigned __int64 v11; // r6
  const char *v12; // r7
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r29
  idPresentable *presentable; // r3
  int v15; // r28
  const idDeclDamage *v16; // r29
  double radius; // fp0
  const idDeclDamage *v19; // [sp+8h] [-F8h]
  const idDeclProjectileImpactEffect *v20; // [sp+Ch] [-F4h]
  bool v21; // [sp+70h] [-90h] BYREF
  unsigned __int16 v22; // [sp+72h] [-8Eh] BYREF
  idPLogScope v23; // [sp+78h] [-88h] BYREF
  idVec3 v24; // [sp+80h] [-80h] BYREF
  tagData_t v25[3]; // [sp+90h] [-70h] BYREF

  RD_EventBegin(name: "AnimEvent_StartMeleeTraceTag2");
  LODWORD(v11) = "AnimEvent_StartMeleeTraceTag2";
  HIDWORD(v11) = 6;
  idPLogScope::idPLogScope(this: &v23, pl: &pLog, gMask: v11, label: v12);
  v25[0].parentJoint.value = -1;
  v25[0].trans.x = 0.0;
  v25[0].trans.y = 0.0;
  v25[0].trans.z = 0.0;
  v25[0].rot.x = 0.0;
  v25[0].rot.y = 0.0;
  v25[0].rot.z = 0.0;
  v25[0].rot.w = 0.0;
  if ( idActor::GetMeleeTagData(this: result, tagName, outTagData: v25, outOrigin: &v24, outUseWeaponAnimator: &v21) )
  {
    TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this: result);
    presentable = result->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this: result);
      presentable = result->presentable;
    }
    idPresentable::UpdateModelTransform(this: presentable);
    idTreeAnimator::GetJointIndex(
      this: (idTreeAnimator *)&v22,
      result: TreeAnimatorFromPresentable,
      jointName: jointName2->data);
    if ( result->GetEquippedWeapon(this: result)->decl != nullptr )
    {
      v15 = *(_DWORD *)&result[1].animStack.branchMemory[18];
      v16 = *(const idDeclDamage **)(v15 + 636);
      if ( damageDecl != nullptr && !idDecl::IsImplicit(this: &damageDecl->idDeclTypeInfo) )
        v16 = damageDecl;
      radius = v16->radius;
      if ( radius != 8.0 && radius != 16.0 && radius != 24.0 && radius != 32.0 )
        idLib::Warning(
          fmt: "AnimEvent_StartMeleeTraceTag %s damage decl must have radius of 8, 16, 24, or 32",
          result->name.data);
      idMeleeTrace::Start(
        this: (idMeleeTrace *)&result[5].inventory.net_addedItems[14].setCount,
        startPos: &v24,
        tagData_: v25,
        useWeaponAnimator_: v21,
        jointIndex2_: (const idIndex<short,enum invalidJointIndex_t> *)v22,
        numSamples_: 100,
        damageCap_: 100.0,
        meleeType_: *(const idMeleeTrace::meleeDamage_t *)(v15 + 644),
        bounds_: BOUNDS_8x8,
        damageDef_: v19,
        impactEffect_: v20);
      idPLogScope::~idPLogScope(this: &v23);
    }
    else
    {
      idPLogScope::~idPLogScope(this: &v23);
    }
  }
  else
  {
    idLib::Warning(fmt: "idAI2::AnimEvent_StartMeleeTraceTag - could not get tag data");
    idPLogScope::~idPLogScope(this: &v23);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$494217
// EA  : 0x82A32858
// RVA : 0x00A32858
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_494217()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 176));
}


// ========================================================================
// __unwind$494218
// EA  : 0x82A32880
// RVA : 0x00A32880
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_494218()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 120));
}


// ========================================================================
// ?AnimEvent_EndMeleeTrace@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82A328B0
// RVA : 0x00A328B0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_EndMeleeTrace(idAI2 *this, eventVoid *result, const idMD6Anim *anim)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  idPLogScope v8[8]; // [sp+50h] [-40h] BYREF

  RD_EventBegin(name: "AnimEvent_EndMeleeTrace");
  LODWORD(v5) = "AnimEvent_EndMeleeTrace";
  HIDWORD(v5) = 6;
  idPLogScope::idPLogScope(this: v8, pl: &pLog, gMask: v5, label: v6);
  idRibbon::~idRibbon(this: (idRibbon *)&result[61328]);
  idPLogScope::~idPLogScope(this: v8);
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$494330
// EA  : 0x82A32914
// RVA : 0x00A32914
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_494330()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 144 + 88));
}


// ========================================================================
// __unwind$494331
// EA  : 0x82A3293C
// RVA : 0x00A3293C
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_494331()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 144 + 80));
}


// ========================================================================
// ?AnimEvent_TraversalAttackChoice@idAI2@@QAA?AVeventVoid@@PBVidMD6Anim@@HMM@Z
// EA  : 0x82A32970
// RVA : 0x00A32970
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idAI2 *__fastcall idAI2::AnimEvent_TraversalAttackChoice(
        idAI2 *this,
        idAI2 *result,
        const idMD6Anim *anim,
        unsigned int extrapolate,
        double attackRadius,
        double attackOffset)
{
  unsigned __int64 v11; // r6
  const char *v12; // r7
  int value; // r6
  idEntity *v14; // r3
  idEntity *v15; // r3
  idEntity *v16; // r28
  idPhysics *Physics; // r3
  const idVec3 *v18; // r3
  float y; // r7
  float z; // r6
  float x; // r5
  float v22; // r4
  float v23; // r11
  idPhysics *v24; // r3
  float *v25; // r3
  double v26; // fp13
  double v27; // fp0
  double v28; // fp10
  double v29; // fp9
  double v30; // fp8
  float *p_traversalAttack; // r27
  double v32; // fp7
  double v33; // fp6
  __int64 v34; // r9
  idVec3 *v35; // r4
  aiSenseState_t *EnemySenseState; // r3
  double v37; // fp31
  double v38; // fp0
  idRenderWorld *v39; // r3
  idRenderWorld *v40; // r3
  idRenderWorld *v41; // r3
  idPhysics *v42; // r30
  idRenderWorld *v43; // r29
  idPhysics *v44; // r3
  idRenderWorld_vtbl *v45; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v47; // r3
  idPhysics *v48; // r30
  idRenderWorld *v49; // r29
  idPhysics *v50; // r3
  idRenderWorld_vtbl *v51; // r30
  const idVec3 *(__fastcall *v52)(idPhysics *, int); // ctr
  int v53; // r3
  idPLogScope v55; // [sp+50h] [-B0h] BYREF
  idVec3 v56; // [sp+58h] [-A8h] BYREF
  float v57; // [sp+68h] [-98h] BYREF
  float v58; // [sp+6Ch] [-94h]
  float v59; // [sp+70h] [-90h]
  float v60; // [sp+78h] [-88h] BYREF
  float v61; // [sp+7Ch] [-84h]
  float v62; // [sp+80h] [-80h]
  idColor v63; // [sp+90h] [-70h] BYREF

  RD_EventBegin(name: "AnimEvent_TraversalAttackChoice");
  LODWORD(v11) = "AnimEvent_TraversalAttackChoice";
  HIDWORD(v11) = 6;
  idPLogScope::idPLogScope(this: &v55, pl: &pLog, gMask: v11, label: v12);
  value = result->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v14 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v15 = idEntity::CastTo(c: v14), v16 = v15, v15 != nullptr) )
  {
    Physics = idEntity::GetPhysics(this: v15);
    v18 = Physics->GetOrigin(this: Physics, a2: 0);
    y = result->aiVolatile.physics.moveState.traversalEndPoint.y;
    z = result->aiVolatile.physics.moveState.traversalEndPoint.z;
    x = v18->x;
    v22 = v18->y;
    v23 = v18->z;
    v57 = result->aiVolatile.physics.moveState.traversalEndPoint.x;
    v58 = y;
    v60 = x;
    v61 = v22;
    v59 = z;
    v62 = v23;
    v24 = idEntity::GetPhysics(this: result);
    v25 = (float *)v24->GetOrigin(this: v24, a2: 0);
    v26 = (float)(result->aiVolatile.physics.moveState.traversalEndPoint.y - v25[1]);
    v27 = (float)(result->aiVolatile.physics.moveState.traversalEndPoint.x - *v25);
    v56.x = result->aiVolatile.physics.moveState.traversalEndPoint.x - *v25;
    v56.z = 0.0;
    v56.y = v26;
    if ( (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26)) > 0.1 )
    {
      idVec3::NormalizeFast(this: &v56);
      v27 = v56.x;
    }
    v28 = (float)(v56.z * (float)attackOffset);
    v29 = (float)(v56.y * (float)attackOffset);
    v30 = v57;
    p_traversalAttack = &result->aiVolatile.animation.animWebAnimator.ptr[0].traversalAttack;
    v32 = v59;
    v33 = v58;
    result->aiVolatile.animation.animWebAnimator.ptr[0].traversalAttack = 0.0;
    v57 = (float)((float)v27 * (float)attackOffset) + (float)v30;
    v59 = (float)v32 + (float)v28;
    v58 = (float)v33 + (float)v29;
    EnemySenseState = (aiSenseState_t *)idAI2::GetEnemySenseState(this: result, senseType: AISENSE_MAX);
    if ( EnemySenseState != nullptr )
    {
      *(_QWORD *)&v56.x = __PAIR64__(&off_82040000, extrapolate);
      aiSenseState_t::ExtrapolatePosition(
        this: EnemySenseState,
        seconds: (float)((float)__SPAIR64__(&off_82040000, extrapolate) * (float)0.001),
        futurePos: v35);
    }
    LODWORD(v34) = result->aiEditable.behaviors.decl->traversalAttackTolerance;
    *(_QWORD *)&v56.x = v34;
    v37 = (float)v34;
    if ( attackRadius > 0.0 )
      v37 = attackRadius;
    if ( ((LODWORD(v58) | LODWORD(v59) | LODWORD(v57)) & 0x7FFFFFFF) != 0
      && (float)((float)((float)(v62 - v59) * (float)(v62 - v59))
               + (float)((float)((float)(v60 - v57) * (float)(v60 - v57))
                       + (float)((float)(v61 - v58) * (float)(v61 - v58)))) < (double)(float)((float)v37 * (float)v37) )
    {
      *p_traversalAttack = 1.0;
    }
    if ( ai_debugLevel.valueInteger > 0 && ai_debugTraversals.valueInteger != 0 )
    {
      v38 = *p_traversalAttack;
      v63 = idColor::colorYellow;
      if ( v38 > 0.0 )
        v63 = idColor::colorRed;
      v39 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))v39->DebugCircle)(
        a1: v39,
        a2: &v63,
        a3: &v57,
        a4: &vec3_up,
        a5: v37);
      v40 = common->RW(this: common);
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, float *, double))v40->DebugArrow)(
        a1: v40,
        a2: &idColor::colorOrange,
        a3: &result->aiVolatile.physics.moveState.traversalEndPoint,
        a4: &v57,
        a5: 10.0);
      v41 = common->RW(this: common);
      v41->DebugPoint(this: v41, a2: (const idVec4 *)&v63, a3: (const idVec3 *)&v57, a4: 3000, a5: true);
      v42 = idEntity::GetPhysics(this: v16);
      v43 = common->RW(this: common);
      v44 = v42;
      GetOrigin = v42->GetOrigin;
      v45 = v43->__vftable;
      v47 = (int)GetOrigin(this: v44, a2: 0);
      ((void (__fastcall *)(idRenderWorld *, idColor *, int, float *, double))v45->DebugArrow)(
        a1: v43,
        a2: &v63,
        a3: v47,
        a4: &v60,
        a5: 10.0);
      v48 = idEntity::GetPhysics(this: v16);
      v49 = common->RW(this: common);
      v50 = v48;
      v52 = v48->GetOrigin;
      v51 = v49->__vftable;
      v53 = (int)v52(this: v50, a2: 0);
      v51->DebugPoint(this: v49, a2: (const idVec4 *)&v63, a3: (const idVec3 *)v53, a4: 3000, a5: true);
    }
    idPLogScope::~idPLogScope(this: &v55);
  }
  else
  {
    result->aiVolatile.animation.animWebAnimator.ptr[0].traversalAttack = 0.0;
    idPLogScope::~idPLogScope(this: &v55);
  }
  RD_EventEnd();
  return this;
}


// ========================================================================
// __unwind$494366
// EA  : 0x82A32E50
// RVA : 0x00A32E50
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_494366()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 160));
}


// ========================================================================
// __unwind$494367
// EA  : 0x82A32E78
// RVA : 0x00A32E78
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void _unwind_494367()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 80));
}


// ========================================================================
// `dynamic initializer for 'ai_cookGrenades''
// EA  : 0x83366CC0
// RVA : 0x01366CC0
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_cookGrenades__()
{
  idCVar::idCVar(
    this: &ai_cookGrenades,
    name: "ai_cookGrenades",
    value: "0",
    flags: 2,
    description: "1 = cook grenades when throwing them",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_cookGrenades__);
}


// ========================================================================
// `dynamic initializer for 'accelSim_v''
// EA  : 0x83366D18
// RVA : 0x01366D18
// PDB : w:\tech5\tungsten\game\ai\ai2_animevents.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__accelSim_v__()
{
  return idCommandLink::idCommandLink(
           this: &accelSim_v,
           cmdName: "accelSim",
           function: accelSim_f,
           description: "outputs a 1D positional value for a point accelerated over time",
           argCompletion: nullptr);
}

