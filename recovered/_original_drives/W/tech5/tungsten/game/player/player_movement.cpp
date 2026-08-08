
// ========================================================================
// ?ProcessInput_ServerOnly@idPlayer@@QAAXXZ
// EA  : 0x82E7BD58
// RVA : 0x00E7BD58
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::ProcessInput_ServerOnly(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v3; // r31
  idPresentable *Control; // r3
  int *p_fadeStartTime; // r31
  idUCmdTracker *v6; // r31
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3
  idGameChallenge *ChallengeEntity; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = nullptr;
  Control = idPresentablePlayer::GetControl(this: v3);
  p_fadeStartTime = &v3[1].screenPrtState.staticList[4].fadeStartTime;
  if ( Control != nullptr )
    v6 = (idUCmdTracker *)(p_fadeStartTime - 4823);
  else
    v6 = (idUCmdTracker *)(p_fadeStartTime - 4894);
  if ( common->IsMultiplayer(this: common) && !this->spawnPending )
  {
    v7 = this->presentable;
    v8 = v7 != nullptr ? (int)v7->GetPlayerInterface_2(this: v7) : 0;
    if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v8 + 352))(a1: v8) != 0
      || ((v9 = this->presentable) == nullptr ? (v10 = 0) : (v10 = (int)v9->GetPlayerInterface_2(this: v9)),
          (*(_BYTE *)(v10 + 47032) & 4) != 0) )
    {
      if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: v6, mask: 4) != 0 )
      {
        idPlayer::Revive(this, reviver: nullptr);
        ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
        idGameChallenge::RespawnPlayerFromDeath(this: ChallengeEntity, player: this);
      }
    }
  }
}


// ========================================================================
// ?RunPhysicsInternal@idPlayer@@QAAXXZ
// EA  : 0x82E7BEB8
// RVA : 0x00E7BEB8
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::RunPhysicsInternal(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r11
  double v5; // fp31
  int v6; // r3
  idAnimator_AF *v7; // r31
  int PlayerGameTime; // r29
  idAnimator_AF *v9; // r3
  idGameTimeManager *p_gameTimeManager; // r26
  int GameMsPerFrame; // r25
  int v12; // r31
  int v13; // r3
  idPresentable *v14; // r11
  int v15; // r29
  int v16; // r3
  idPresentable *v17; // r3
  int v18; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  v4 = this->presentable;
  v5 = *(float *)(v3 + 37596);
  if ( v4 != nullptr )
    v6 = (int)v4->GetPlayerInterface_2(this: this->presentable);
  else
    v6 = 0;
  *(float *)(v6 + 46640) = -v5;
  if ( common->IsServer(this: common) )
  {
    v7 = this->GetAF_2(this);
    LOBYTE(v7) = idEntity::GetPhysics(this) != (idPhysics *)&v7->physicsObj;
    PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
    v9 = this->GetAF_2(this);
    idAnimator_AF::Sync(this: v9, time: PlayerGameTime, runPhysics: (bool)v7);
    idEntity::RunPhysics(this);
  }
  else
  {
    p_gameTimeManager = &clientGame->gameTimeManager;
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v12 = idAccolade::Count(this: p_gameTimeManager) * GameMsPerFrame;
    v13 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v14 = this->presentable;
    v15 = v12 - v13;
    if ( v14 != nullptr )
      v16 = (int)v14->GetPlayerInterface_2(this: this->presentable);
    else
      v16 = 0;
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v16 + 36264) + 176))(a1: v16 + 36264, a2: v12 - v15, a3: v12);
  }
  if ( common->IsServer(this: common) )
  {
    v17 = this->presentable;
    if ( v17 != nullptr )
      v18 = (int)v17->GetPlayerInterface_2(this: v17);
    else
      v18 = 0;
    if ( idPhysics_Player::HasJumped(this: (idPhysics_Player *)(v18 + 36264)) )
      this->bodyAnimInfo.physicsJumped = true;
  }
}


// ========================================================================
// ?RunPhysics_RemoteClient@idPlayer@@QAAXXZ
// EA  : 0x82E7C0C8
// RVA : 0x00E7C0C8
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::RunPhysics_RemoteClient(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r11
  idPresentable *v4; // r3
  bool v5; // r29
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3
  unsigned __int8 IsCrouching; // r3
  _BYTE v12[60]; // [sp+50h] [-60h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  memcpy(Dst: v12, Src: (const void *)(v3 + 46312), Size: sizeof(v12));
  v4 = this->presentable;
  v5 = v12[38] & 1;
  if ( v4 != nullptr )
    v6 = (int)v4->GetPlayerInterface_2(this: v4);
  else
    v6 = 0;
  idPhysics_Player::SetClientCrouch(this: (idPhysics_Player *)(v6 + 36264), crouch: v5);
  idPlayer::RunPhysicsInternal(this);
  v7 = this->presentable;
  if ( v7 != nullptr )
    v8 = (int)v7->GetPlayerInterface_2(this: v7);
  else
    v8 = 0;
  if ( v5 != (unsigned __int8)idPhysics_Player::IsCrouching(this: (idPhysics_Player *)(v8 + 36264)) )
  {
    v9 = this->presentable;
    if ( v9 != nullptr )
      v10 = (int)v9->GetPlayerInterface_2(this: v9);
    else
      v10 = 0;
    IsCrouching = idPhysics_Player::IsCrouching(this: (idPhysics_Player *)(v10 + 36264));
    idLib::Warning(fmt: "Client crouching mismatch. client: %d server: %d", v5, IsCrouching);
  }
}


// ========================================================================
// ?AllowClientAuthPhysics@idPlayer@@QAA_NXZ
// EA  : 0x82E7C1E0
// RVA : 0x00E7C1E0
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

int __fastcall idPlayer::AllowClientAuthPhysics(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r11
  int v5; // r31
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  unsigned __int8 v9; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  v4 = this->presentable;
  v5 = v3 + 46312;
  if ( v4 != nullptr )
    v6 = (int)v4->GetPlayerInterface_2(this: this->presentable);
  else
    v6 = 0;
  if ( *(_DWORD *)(v5 + 40) <= *(_DWORD *)(v6 + 16216) )
    return 0;
  v7 = this->presentable;
  v8 = v7 != nullptr ? (int)v7->GetPlayerInterface_2(this: v7) : 0;
  v9 = 1;
  if ( *(int *)(v8 + 47128) <= 1 )
    return 0;
  return v9;
}


// ========================================================================
// ?RunPhysics_RemoteClientCorrection@idPlayer@@QAAXXZ
// EA  : 0x82E7C2B8
// RVA : 0x00E7C2B8
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::RunPhysics_RemoteClientCorrection(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v3; // r3
  int v4; // r25
  idPhysics *Physics; // r3
  const idVec3 *v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3
  idPhysics *v11; // r3
  void (*DebugPoint)(void); // ctr
  idPresentable *v13; // r3
  int v14; // r31
  int v15; // r3
  float *v16; // r3
  float v17; // r6
  float v18; // r5
  double v19; // fp0
  double v20; // fp8
  double v21; // fp7
  double v22; // fp1
  double v23; // fp31
  idPresentable *v24; // r3
  int v25; // r3
  int v26; // r3
  bool v27; // [sp+50h] [-80h] BYREF
  idVec3 v28; // [sp+58h] [-78h] BYREF
  float v29; // [sp+68h] [-68h] BYREF
  float v30; // [sp+6Ch] [-64h]
  float v31; // [sp+70h] [-60h]
  idVec3 v32; // [sp+78h] [-58h]

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = nullptr;
  if ( idPresentablePlayer::GetControl(this: v3) != nullptr || pm_clientAuthoritative.valueInteger == 0 )
    return;
  v4 = idPlayer::GetUCmdTracker2(this) + 68;
  if ( (unsigned __int8)idPlayer::AllowClientAuthPhysics(this) == 0 )
  {
    if ( pm_clientAuthoritative_debug.valueInteger != 0 )
    {
      Physics = idEntity::GetPhysics(this);
      v6 = Physics->GetOrigin(this: Physics, a2: 0);
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: v6,
        a4: 0,
        a5: false);
      v7 = this->presentable;
      if ( v7 != nullptr )
        v8 = (int)v7->GetPlayerInterface_2(this: v7);
      else
        v8 = 0;
      idLib::Printf(
        fmt: "[%d]Ignoring client auth:  cmd.serverTime: %d  overrideTime: %d \n",
        this->entityNumber,
        *(_DWORD *)(v4 + 40),
        *(_DWORD *)(v8 + 16216));
    }
    return;
  }
  v9 = this->presentable;
  v27 = false;
  if ( v9 != nullptr )
    v10 = (int)v9->GetPlayerInterface_2(this: v9);
  else
    v10 = 0;
  if ( idPhysics_Player::ClientPusherLocked(this: (idPhysics_Player *)(v10 + 36264), justBecameUnlocked: &v27) )
  {
    if ( pm_clientAuthoritative_debug.valueInteger == 0 )
      return;
    v11 = idEntity::GetPhysics(this);
    v11->GetOrigin(this: v11, a2: 0);
    DebugPoint = (void (*)(void))clientGame->renderWorld->DebugPoint;
LABEL_45:
    DebugPoint();
    return;
  }
  v13 = this->presentable;
  if ( v27 )
  {
    if ( v13 != nullptr )
    {
      v14 = (int)v13->GetPlayerInterface_2(this: v13);
      *(_DWORD *)(v14 + 16216) = idClientGame::GetServerGameTime(this: clientGame);
    }
    else
    {
      MEMORY[0x3F58] = idClientGame::GetServerGameTime(this: clientGame);
    }
    return;
  }
  if ( v13 != nullptr )
    v15 = (int)v13->GetPlayerInterface_2(this: v13);
  else
    v15 = 0;
  v16 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v15 + 36264) + 64))(a1: v15 + 36264, a2: 0);
  v17 = v16[2];
  v18 = *v16;
  v30 = v16[1];
  v31 = v17;
  v29 = v18;
  v19 = *(float *)(v4 + 20);
  v20 = *(float *)(v4 + 24);
  v21 = (float)(*(float *)(v4 + 24) - v30);
  v32.z = *(float *)(v4 + 28);
  v32.y = v20;
  v22 = (float)(v32.z - v17);
  v32.x = v19;
  v28 = v32;
  v23 = __fsqrts((float)((float)((float)((float)v19 - v18) * (float)((float)v19 - v18))
                       + (float)((float)((float)(v32.z - v17) * (float)(v32.z - v17)) + (float)((float)v21 * (float)v21))));
  if ( __fabs(v22) < pm_clientAuthoritative_minDistZ.valueFloat )
  {
    if ( pm_clientAuthoritative_debug.valueInteger != 0 )
      idLib::Printf(fmt: "[%d]Remote client physics: ignore small z delta: %f\n", *(_DWORD *)(v4 + 16), v22);
    v28.z = v31;
  }
  if ( v23 <= pm_clientAuthoritative_minDist.valueFloat )
  {
LABEL_43:
    if ( pm_clientAuthoritative_debug.valueInteger == 0 )
      return;
    idLib::Printf(
      fmt: "[%d]Remote client player physics delta: %.2f. forward: %d pos <%.2f, %.2f, %.2f> \n",
      HIDWORD(v23),
      v23,
      LODWORD(v23),
      v28.x,
      v28.y,
      v28.z);
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: (const idVec3 *)&v29,
      a4: &v28,
      a5: 0,
      a6: false);
    DebugPoint = (void (*)(void))clientGame->renderWorld->DebugPoint;
    goto LABEL_45;
  }
  if ( pm_clientAuthoritative_Lerp.valueFloat > 0.0 )
  {
    v28.x = LerpToWithScale(cur: v29, dest: v28.x, scale: pm_clientAuthoritative_Lerp.valueFloat);
    v28.y = LerpToWithScale(cur: v30, dest: v28.y, scale: pm_clientAuthoritative_Lerp.valueFloat);
  }
  v24 = this->presentable;
  if ( g_pm_deferredSlideMove )
  {
    if ( v24 != nullptr )
    {
      v25 = (int)v24->GetPlayerInterface_2(this: v24);
      idPhysics_Player::SetClientDeferredOrigin(this: (idPhysics_Player *)(v25 + 36264), nextOrigin: &v28);
    }
    else
    {
      idPhysics_Player::SetClientDeferredOrigin(this: (idPhysics_Player *)0x8DA8, nextOrigin: &v28);
    }
  }
  else
  {
    if ( v24 != nullptr )
      v26 = (int)v24->GetPlayerInterface_2(this: v24);
    else
      v26 = 0;
    (*(void (__fastcall **)(int, idVec3 *, int))(*(_DWORD *)(v26 + 36264) + 48))(a1: v26 + 36264, a2: &v28, a3: -1);
  }
  if ( pm_clientAuthoritative_debug.valueInteger != 0 )
  {
    if ( v23 > pm_clientAuthoritative_warnDist.valueFloat )
    {
      idLib::Warning(fmt: "Remote client player physics: delta movement for frame was %f units", v23);
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)&v29,
        a4: &v28,
        a5: 0,
        a6: false);
    }
    goto LABEL_43;
  }
}


// ========================================================================
// ?CancelSprint@idPlayer@@QAAXXZ
// EA  : 0x82E7C7E8
// RVA : 0x00E7C7E8
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::CancelSprint(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r3
  int v5; // r31
  idPresentable *v6; // r3
  int v7; // r28
  idPresentable *v8; // r3
  double valueFloat; // fp31
  int v10; // r31

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  *(_BYTE *)(v3 + 47121) = 0;
  v4 = this->presentable;
  if ( v4 != nullptr )
    v5 = (int)v4->GetPlayerInterface_2(this: v4);
  else
    v5 = 0;
  *(float *)(v5 + 47112) = (float)(unsigned int)idClientGame::GetPlayerGameTime(this: clientGame);
  v6 = this->presentable;
  if ( v6 != nullptr )
    v7 = (int)v6->GetPlayerInterface_2(this: v6);
  else
    v7 = 0;
  v8 = this->presentable;
  valueFloat = pm_sprintMaxTime.valueFloat;
  if ( v8 != nullptr )
    v10 = (int)v8->GetPlayerInterface_2(this: v8);
  else
    v10 = 0;
  *(float *)(v10 + 47108) = (float)(*(float *)(v7 + 47100)
                                  - (float)(unsigned int)idClientGame::GetPlayerGameTime(this: clientGame))
                          / (float)valueFloat;
}


// ========================================================================
// ?ResetSprintTimer@idPlayer@@QAAXXZ
// EA  : 0x82E7C928
// RVA : 0x00E7C928
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::ResetSprintTimer(idPlayer *this)
{
  idPresentable *presentable; // r3
  double valueFloat; // fp31
  int v3; // r31

  presentable = this->presentable;
  valueFloat = pm_sprintMaxTime.valueFloat;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  *(float *)(v3 + 47100) = (float)(unsigned int)idClientGame::GetPlayerGameTime(this: clientGame) + (float)valueFloat;
}


// ========================================================================
// ?UpdateSprint@idPlayer@@QAAXXZ
// EA  : 0x82E7C9B8
// RVA : 0x00E7C9B8
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::UpdateSprint(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r31
  double valueFloat; // fp29
  int PlayerGameTime; // r27
  char v6; // r24
  bool IsSliding; // r3
  __int64 v8; // r10
  _DWORD *v9; // r11
  char *v10; // r20
  __int64 v11; // r9
  __int64 v12; // r11
  float *v13; // r11
  double v14; // fp13
  double v15; // fp0
  float *v16; // r26
  double v17; // fp30
  bool IsPressedForPlayer; // r3
  char v19; // r11
  bool v20; // r21
  __int64 v21; // r6
  double v22; // fp0
  double v23; // fp31
  float *v24; // r3
  char v25; // r11
  char v26; // r29
  __int64 v27; // r10
  char v28; // r9
  double v29; // fp13
  double v30; // fp0
  double v31; // fp0
  double v32; // fp31
  double v33; // fp0
  float *v34; // r11
  idDebugGraph *v35; // r3
  char v36[128]; // [sp+58h] [-108h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  valueFloat = pm_sprintMaxTime.valueFloat;
  if ( gameLocal != nullptr && gameLocal->world != nullptr && gameLocal->world->mapType == MAPTYPE_OUTDOOR )
    valueFloat = (float)(pm_sprintScaleOutsideInstance.valueFloat * pm_sprintMaxTime.valueFloat);
  PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
  v6 = 0;
  memcpy(Dst: &v36[24], Src: (const void *)(v3 + 46028), Size: 0x3Cu);
  IsSliding = idPlayer::PlayerBehavior_SprintSlide_IsSliding(this);
  v8 = IsSliding;
  if ( IsSliding )
  {
    v9 = (_DWORD *)(v3 + 47104);
    if ( *(_DWORD *)(v3 + 47104) == 0 )
    {
      LODWORD(v8) = PlayerGameTime;
      *v9 = (int)(float)(*(float *)(v3 + 47100) - (float)v8);
    }
    LODWORD(v8) = *v9 + PlayerGameTime;
    *(float *)(v3 + 47100) = (float)v8;
  }
  else
  {
    *(_DWORD *)(v3 + 47104) = 0;
  }
  v10 = (char *)(v3 + 47121);
  HIDWORD(v11) = 0;
  HIDWORD(v12) = 47116;
  if ( *(_BYTE *)(v3 + 47121) != 0 )
  {
    if ( p_infiniteSprintMode.valueInteger == 0 )
    {
      LODWORD(v12) = PlayerGameTime;
      if ( *(float *)(v3 + 47100) < (double)(float)v12 )
      {
        *(_BYTE *)(v3 + 47120) = 1;
        v6 = 1;
        LODWORD(v11) = PlayerGameTime + 1000;
        *(float *)(v3 + 47116) = (float)v11;
      }
    }
  }
  else
  {
    LODWORD(v12) = PlayerGameTime;
    v14 = (float)((float)v12 + (float)valueFloat);
    v15 = (float)((float)((float)((float)v12 - *(float *)(v3 + 47112))
                        * (float)((float)valueFloat / pm_sprintChargeTime.valueFloat))
                + (float)((float)(*(float *)(v3 + 47108) * (float)valueFloat) + (float)v12));
    *(float *)(v3 + 47100) = (float)((float)((float)v12 - *(float *)(v3 + 47112))
                                   * (float)((float)valueFloat / pm_sprintChargeTime.valueFloat))
                           + (float)((float)(*(float *)(v3 + 47108) * (float)valueFloat) + (float)v12);
    v13 = (float *)(v3 + 47100);
    if ( v15 >= 0.0 )
    {
      if ( v15 > v14 )
        v15 = v14;
      *v13 = v15;
    }
    else
    {
      *v13 = 0.0;
    }
  }
  LODWORD(v12) = PlayerGameTime;
  v16 = (float *)(v3 + 47116);
  v17 = (float)v12;
  if ( v17 > *(float *)(v3 + 47116) )
  {
    if ( *(_BYTE *)(v3 + 47120) == 0
      || (IsPressedForPlayer = idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v3 + 45960), mask: 16),
          v19 = 1,
          !IsPressedForPlayer) )
    {
      v19 = 0;
    }
    *(_BYTE *)(v3 + 47120) = v19;
  }
  v20 = *(_DWORD *)(v3 + 37464) != 0;
  if ( (unsigned __int8)idPlayer::IsOnLadder(this) != 0 )
  {
    if ( abs8(v36[30]) >= 0x64u )
      goto LABEL_40;
    goto LABEL_39;
  }
  if ( v20 )
  {
    if ( *(_DWORD *)(v3 + 37464) == 1 )
      v22 = (float)((float)0.60000002 * (float)0.60000002);
    else
      v22 = (float)((float)1.0 * (float)0.60000002);
  }
  else
  {
    v22 = 1.0;
  }
  v23 = (float)((float)v22 * pm_walkspeed.valueFloat);
  if ( v36[30] < 100
    || v17 > *v16
    && (float)((float)((v24 = (float *)(*(int (__fastcall **)(char *, int, _DWORD))(*(_DWORD *)(v3 + 36264) + 88))(
                                         a1: v36,
                                         a2: v3 + 36264,
                                         a3: 0))[2]
                     * v24[2])
             + (float)((float)(*v24 * *v24) + (float)(v24[1] * v24[1]))) < (double)(float)((float)v23 * (float)v23)
    || *(_BYTE *)(v3 + 48521) != 0 )
  {
LABEL_39:
    v6 = 1;
  }
LABEL_40:
  if ( v6 == 0 )
  {
    if ( *(_DWORD *)(v3 + 36856) == 4 )
      goto LABEL_63;
    if ( usercmdGen->GetUseAimAssist(this: usercmdGen) || (v25 = 0, pm_togglesprint.valueInteger != 0) )
      v25 = 1;
    v26 = v25;
    if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: (idUCmdTracker *)(v3 + 45960), mask: 16) != 0
      || *(_BYTE *)(v3 + 47120) == 0 && idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v3 + 45960), mask: 16) )
    {
      if ( (unsigned __int8)idPlayer::IsOnLadder(this) == 0
        && !v20
        && idActor::IsCrouching(this)
        && !idPlayer::PlayerBehavior_SprintSlide_IsSliding(this) )
      {
        idPhysics_Player::SetCrouch(this: (idPhysics_Player *)(v3 + 36264), crouch: false);
        if ( idActor::IsCrouching(this) )
          return;
      }
      if ( *v10 == 0 && v17 > *v16 )
      {
        *v10 = 1;
        LODWORD(v27) = PlayerGameTime + 250;
        *v16 = (float)v27;
        goto LABEL_63;
      }
      if ( v26 == 0
        || *v10 == 0
        || (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: (idUCmdTracker *)(v3 + 45960), mask: 16) == 0 )
      {
        goto LABEL_63;
      }
      *(_BYTE *)(v3 + 47120) = 1;
    }
    else if ( v26 != 0 )
    {
      goto LABEL_63;
    }
  }
  *v10 = 0;
LABEL_63:
  v28 = *v10;
  if ( *v10 == 0 && *(_BYTE *)(v3 + 47122) != 0 )
  {
    v29 = (float)(*(float *)(v3 + 47100) - (float)v17);
    *(float *)(v3 + 47112) = v17;
    v30 = (float)((float)v29 / (float)valueFloat);
    if ( v30 >= 0.0 )
    {
      if ( v30 > 1.0 )
        v30 = 1.0;
    }
    else
    {
      v30 = 0.0;
    }
    *(float *)(v3 + 47108) = v30;
  }
  v31 = (float)((float)(*(float *)(v3 + 47100) - (float)v17) / (float)valueFloat);
  if ( v31 >= 0.0 )
  {
    if ( v31 <= 1.0 )
      v32 = (float)((float)(*(float *)(v3 + 47100) - (float)v17) / (float)valueFloat);
    else
      v32 = 1.0;
  }
  else
  {
    v32 = 0.0;
  }
  if ( v20 )
  {
    v33 = 1.0;
  }
  else
  {
    LODWORD(v21) = (int)(float)((float)((float)v32 * (float)100.0) + (float)0.5);
    v33 = (float)v21;
  }
  v34 = (float *)(v3 + 48568);
  *(float *)(v3 + 48568) = v33;
  if ( v33 < 1.0 )
  {
    if ( v33 >= 0.2 )
      *v34 = (float)((float)v33 - (float)0.2) * (float)1.25;
    else
      *v34 = 0.0;
  }
  *(_BYTE *)(v3 + 47122) = v28;
  if ( p_drawSprintValues.valueInteger == this->entityNumber )
  {
    v35 = graphSprint;
    if ( graphSprint == nullptr )
    {
      v35 = console->CreateGraph(this: console, a2: 100);
      graphSprint = v35;
    }
    idDebugGraph::SetValue(
      this: v35,
      b: -1,
      value: v32,
      color: (const idColor *)HIDWORD(v21),
      a5: &idColor::colorGreen.r);
  }
  if ( pm_autoSprint.valueInteger != 0 )
    *v10 = 0;
}


// ========================================================================
// ?AdjustSpeed@idPlayer@@QAAXABVusercmd_t@@@Z
// EA  : 0x82E7D090
// RVA : 0x00E7D090
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPlayer::AdjustSpeed(idPlayer *this, const usercmd_t *cmd)
{
  __int64 v2; // r29
  __int128 v3; // r5
  int v4; // r3
  double valueFloat; // fp30
  double v6; // fp28
  double z; // fp24
  int valueInteger; // r31
  double v9; // fp23
  double y; // fp25
  double x; // fp27
  int v12; // r3
  int v13; // r11
  idEnvironmentAnalyzer *v14; // r30
  int v15; // r3
  __int64 v16; // r9 OVERLAPPED
  int v17; // r7 OVERLAPPED
  int v18; // r3
  int v19; // r3
  char v20; // r31
  int v21; // r3
  int v22; // r3
  double v23; // fp0
  int v24; // r3
  _BYTE *v25; // r3
  int v26; // r3
  idPresentablePlayer *v27; // r3
  __int64 v28; // r11
  int v29; // r3
  int v30; // r3
  int v31; // r11
  int v32; // r3
  idPresentablePlayer *v33; // r3
  double v34; // fp30
  double v35; // fp29
  idPresentablePlayer *v36; // r3
  walkState_t v37; // r4
  idCVar *v38; // r10
  double v39; // fp0
  double v40; // fp12
  double v41; // fp13
  int v42; // r3
  idPresentablePlayer *v43; // r3
  int v44; // r3
  int v45; // r3
  idCVar *v46; // r10
  int v47; // r3
  int v48; // r3
  int v49; // r3
  int v50; // r3
  double v51; // fp1
  int v52; // r3
  double v53; // fp31
  double v54; // fp30
  idPresentablePlayer *v55; // r29
  int v56; // r3
  idPresentablePlayer *v57; // r30
  int v58; // r3
  int v59; // r31
  double v60; // fp30
  double MovementScale; // fp1

  v2 = *(_QWORD *)&cmd;
  LODWORD(v3) = cmd->rightmove;
  DWORD2(v3) = cmd->forwardmove;
  valueFloat = 0.0;
  v6 = 0.0;
  z = 0.0;
  valueInteger = pm_walkthreshold.valueInteger;
  v9 = 1.0;
  y = (float)(__int64)v3;
  x = (float)*(__int64 *)((char *)&v3 + 4);
  v4 = *(_DWORD *)(DWORD1(v3) + 488);
  if ( v4 != 0 )
    v12 = (*(int (__fastcall **)(int))(*(_DWORD *)v4 + 104))(a1: v4);
  else
    v12 = 0;
  v13 = *(_DWORD *)(HIDWORD(v2) + 488);
  v14 = (idEnvironmentAnalyzer *)(v12 + 47840);
  if ( v13 != 0 )
    v15 = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)v13 + 104))(a1: *(_DWORD *)(HIDWORD(v2) + 488));
  else
    v15 = 0;
  HIDWORD(v16) = 0;
  v17 = *(unsigned __int8 *)(v15 + 47032);
  if ( (v17 & 0x20) != 0 )
  {
    v18 = *(_DWORD *)(HIDWORD(v2) + 488);
    valueFloat = pm_noclipspeed.valueFloat;
    if ( v18 != 0 )
      v19 = (*(int (__fastcall **)(int))(*(_DWORD *)v18 + 104))(a1: v18);
    else
      v19 = 0;
    if ( idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v19 + 45960), mask: 16) )
      valueFloat = (float)((float)valueFloat * (float)2.0);
    goto LABEL_77;
  }
  if ( v14->forceLeanMode == 0 || (v14->forceLeanMode & 0x10) != 0 )
  {
    if ( (unsigned __int8)idPlayer::IsOnLadder(this: (idPlayer *)HIDWORD(v2)) != 0
      || ((v24 = *(_DWORD *)(HIDWORD(v2) + 488)) == 0
        ? (v25 = nullptr)
        : (v25 = (_BYTE *)(*(int (__fastcall **)(int))(*(_DWORD *)v24 + 104))(a1: v24)),
          idPresentablePlayer::IsZoomedIn(ptr: v25)
       || ((v26 = *(_DWORD *)(HIDWORD(v2) + 488)) == 0
         ? (v27 = nullptr)
         : (v27 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v26 + 104))(a1: v26)),
           (unsigned __int8)idPresentablePlayer::IsCrouching(this: v27) != 0 || *(unsigned __int8 *)(v2 + 8) >= 0x80u)) )
    {
      v42 = *(_DWORD *)(HIDWORD(v2) + 488);
      if ( v42 != 0 )
        v43 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v42 + 104))(a1: v42);
      else
        v43 = nullptr;
      idPresentablePlayer::SetWalkState(this: v43, state: WALKSTATE_WALKING);
      valueFloat = pm_walkspeed.valueFloat;
LABEL_77:
      v6 = 0.0;
      goto LABEL_78;
    }
    v29 = *(_DWORD *)(HIDWORD(v2) + 488);
    if ( v29 != 0 )
      v30 = (*(int (__fastcall **)(int))(*(_DWORD *)v29 + 104))(a1: v29);
    else
      v30 = 0;
    v31 = *(unsigned __int8 *)(v30 + 47121);
    v32 = *(_DWORD *)(HIDWORD(v2) + 488);
    if ( v31 != 0 )
    {
      if ( v32 != 0 )
        v33 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v32 + 104))(a1: v32);
      else
        v33 = nullptr;
      idPresentablePlayer::SetWalkState(this: v33, state: WALKSTATE_SPRINTING);
      v6 = 3.0;
      valueFloat = pm_sprintspeed.valueFloat;
    }
    else
    {
      LODWORD(v28) = valueInteger;
      v34 = (float)((float)((float)y * (float)y) + (float)((float)x * (float)x));
      v35 = (float)v28;
      if ( __fsqrts(v34) <= v35 )
      {
        if ( v32 != 0 )
          v36 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v32 + 104))(a1: v32);
        else
          v36 = nullptr;
        v37 = WALKSTATE_WALKING;
      }
      else
      {
        if ( v32 != 0 )
          v36 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v32 + 104))(a1: v32);
        else
          v36 = nullptr;
        v37 = WALKSTATE_RUNNING;
      }
      idPresentablePlayer::SetWalkState(this: v36, state: v37);
      if ( pm_autoSprint.valueInteger != 0 )
        v38 = &pm_autoSprintSpeed;
      else
        v38 = &pm_runspeed;
      v39 = (float)((float)__fsqrts(v34) * (float)((float)1.0 / (float)v35));
      if ( v39 >= 0.0 )
      {
        if ( v39 <= 1.0 )
          v40 = v39;
        else
          v40 = 1.0;
      }
      else
      {
        v40 = 0.0;
      }
      v41 = (float)((float)__fsqrts(v34) * (float)((float)1.0 / (float)v35));
      valueFloat = (float)((float)((float)(v38->valueFloat - pm_walkspeed.valueFloat) * (float)v40)
                         + pm_walkspeed.valueFloat);
      if ( v41 >= 0.0 )
      {
        if ( v41 > 1.0 )
          v41 = 1.0;
        v6 = v41;
      }
      else
      {
        v6 = 0.0;
      }
    }
  }
  else
  {
    v20 = 0;
    if ( (v14->forceLeanMode & 0xC) == 0
      || (v14->forceLeanMode & 2) != 0
      && (HIDWORD(v16) = *(char *)(v2 + 7), (float)*(__int64 *)((char *)&v16 + 4) > 0.0)
      || (v14->forceLeanMode & 1) != 0
      && (HIDWORD(v16) = *(char *)(v2 + 7), (float)*(__int64 *)((char *)&v16 + 4) < 0.0)
      || (v14->forceLeanMode & 8) != 0 && (LODWORD(v16) = *(char *)(v2 + 6), (float)v16 < 0.0) )
    {
      v20 = 1;
    }
    else
    {
      v21 = *(_DWORD *)(HIDWORD(v2) + 488);
      if ( v21 != 0 )
        v22 = (*(int (__fastcall **)(int))(*(_DWORD *)v21 + 104))(a1: v21);
      else
        v22 = 0;
      x = (float)(idEnvironmentAnalyzer::GetCoverModifiedScale(
                    this: v14,
                    viewDir: (const idVec3 *)(v22 + 46544),
                    getMovementScale: true)
                * (float)x);
      v23 = (float)((float)__fsqrts((float)((float)((float)y * (float)y) + (float)((float)x * (float)x)))
                  * (float)0.0078740157);
      if ( v23 >= 0.0 )
      {
        if ( v23 > 1.0 )
          v23 = 1.0;
      }
      else
      {
        v23 = 0.0;
      }
      v9 = v23;
      valueFloat = (float)(pm_runspeed.valueFloat * (float)v23);
    }
    if ( v20 != 0 )
    {
      valueFloat = 0.0;
      v6 = 0.0;
      v9 = 0.0;
      x = vec3_origin.x;
      y = vec3_origin.y;
      z = vec3_origin.z;
    }
  }
LABEL_78:
  if ( (float)((float)((float)((float)((float)z * (float)0.0078740157) + (float)((float)y * (float)0.0078740157))
                     * (float)0.0)
             - (float)((float)x * (float)0.0078740157)) > 0.0 )
  {
    v44 = *(_DWORD *)(HIDWORD(v2) + 488);
    if ( v44 != 0 )
      v45 = (*(int (__fastcall **)(int))(*(_DWORD *)v44 + 104))(a1: v44);
    else
      v45 = 0;
    if ( *(_BYTE *)(v45 + 47121) == 0 || (unsigned __int8)idPlayer::IsOnLadder(this: (idPlayer *)HIDWORD(v2)) != 0 )
      v46 = &pm_backSpeedRatio;
    else
      v46 = &pm_sprintBackSpeedRatio;
    valueFloat = (float)((float)-(float)((float)((float)((float)1.0 - v46->valueFloat)
                                               * (float)((float)((float)((float)((float)z * (float)0.0078740157)
                                                                       + (float)((float)y * (float)0.0078740157))
                                                               * (float)0.0)
                                                       - (float)((float)x * (float)0.0078740157)))
                                       - (float)1.0)
                       * (float)valueFloat);
  }
  v47 = *(_DWORD *)(HIDWORD(v2) + 488);
  if ( v47 != 0 )
    v48 = (*(int (__fastcall **)(int))(*(_DWORD *)v47 + 104))(a1: v47);
  else
    v48 = 0;
  *(float *)(v48 + 45836) = v6;
  v49 = *(_DWORD *)(HIDWORD(v2) + 488);
  if ( v49 != 0 )
    v50 = (*(int (__fastcall **)(int))(*(_DWORD *)v49 + 104))(a1: v49);
  else
    v50 = 0;
  v51 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v50 + 368))(a1: v50);
  v52 = *(_DWORD *)(HIDWORD(v2) + 488);
  v53 = (float)((float)v51 * (float)valueFloat);
  v54 = pm_crouchspeed.valueFloat;
  if ( v52 != 0 )
    v55 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v52 + 104))(a1: v52);
  else
    v55 = nullptr;
  v56 = *(_DWORD *)(HIDWORD(v2) + 488);
  if ( v56 != 0 )
    v57 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v56 + 104))(a1: v56);
  else
    v57 = nullptr;
  v58 = *(_DWORD *)(HIDWORD(v2) + 488);
  if ( v58 != 0 )
    v59 = (*(int (__fastcall **)(int))(*(_DWORD *)v58 + 104))(a1: v58);
  else
    v59 = 0;
  v60 = (float)(idPresentablePlayer::GetCrouchedScale(this: v55) * (float)v54);
  MovementScale = idPresentablePlayer::GetMovementScale(this: v57);
  idPhysics_Player::SetSpeed(
    this: (idPhysics_Player *)(v59 + 36264),
    newWalkSpeed: (float)((float)MovementScale * (float)v53),
    newCrouchSpeed: (float)((float)v60 * (float)v9));
}


// ========================================================================
// ?CrashLand@idPlayer@@QAAXABVidVec3@@0@Z
// EA  : 0x82E7D740
// RVA : 0x00E7D740
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::CrashLand(idPlayer *this, const idVec3 *oldOrigin, const idVec3 *oldVelocity)
{
  idPresentable *presentable; // r3
  int v7; // r3
  double v8; // fp1
  idPresentable *v9; // r3
  double v10; // fp23
  int v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  int v14; // r10
  idPresentable *v15; // r3
  int v16; // r3
  idPresentable *v17; // r3
  int v18; // r3
  double valueFloat; // fp27
  double v20; // fp26
  double v21; // fp25
  double v22; // fp29
  int v23; // r3
  int v24; // r3
  idPresentable *v25; // r11
  float *v26; // r29
  int v27; // r3
  float *v28; // r9
  idPresentable *v29; // r3
  double v30; // fp31
  double v31; // fp22
  int v32; // r3
  float *v33; // r31
  double v34; // fp29
  idPresentable *v35; // r3
  int v36; // r3
  double v37; // fp13
  double v38; // fp0
  double v39; // fp4
  double v40; // fp7
  double v41; // fp0
  double v42; // fp12
  double v43; // fp28
  char v44; // r11
  int i; // r31
  idPresentable *v46; // r3
  int v47; // r3
  idPresentable *v48; // r3
  bool v49; // zf
  int v50; // r3
  idPlayer *PlayerSounds; // r3
  double v52; // fp10
  double v53; // fp9
  double v54; // fp8
  double v56; // fp28
  double v57; // fp27
  double v58; // fp30
  int v59; // r3
  idPresentable *v60; // r3
  int v61; // r3
  idPresentable *v63; // r3
  int v64; // r3
  idPresentable *v65; // r3
  int v66; // r3
  idPresentable *v67; // r3
  int v68; // r3
  idPresentable *v69; // r3
  idPresentablePlayer *v70; // r3
  int v71; // r29
  int v72; // r31
  int v73; // r9
  idPresentable *v74; // r3
  int v75; // r30
  int PlayerGameTime; // r3
  idLobbyBase *v77; // r3
  float v78[4]; // [sp+60h] [-170h] BYREF
  char v79; // [sp+70h] [-160h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = 0;
  v8 = ((double (__fastcall *)(int, _DWORD))*(_DWORD *)(*(_DWORD *)(v7 + 36264) + 112))(a1: v7 + 36264, a2: 0);
  v9 = this->presentable;
  v10 = v8;
  if ( v9 != nullptr )
    v11 = (int)v9->GetPlayerInterface_2(this: v9);
  else
    v11 = 0;
  if ( (*(_BYTE *)(v11 + 47032) & 0x20) != 0 || v10 >= pm_waterlevel_head.valueFloat )
    return;
  v12 = this->presentable;
  if ( v12 != nullptr )
    v13 = (int)v12->GetPlayerInterface_2(this: v12);
  else
    v13 = 0;
  v14 = *(_DWORD *)(v13 + 47036);
  v15 = this->presentable;
  if ( v14 != 0 )
  {
    if ( v15 != nullptr )
      v16 = (int)v15->GetPlayerInterface_2(this: v15);
    else
      v16 = 0;
    if ( *(int *)(v16 + 47036) > 0 )
    {
      v17 = this->presentable;
      if ( v17 != nullptr )
      {
        v18 = (int)v17->GetPlayerInterface_2(this: v17);
        --*(_DWORD *)(v18 + 47036);
      }
      else
      {
        --MEMORY[0xB7BC];
      }
    }
    return;
  }
  valueFloat = pm_fatalFallDist.valueFloat;
  v20 = (float)(pm_fatalFallDist.valueFloat * (float)0.64999998);
  v21 = (float)((float)(pm_fatalFallDist.valueFloat * (float)0.64999998) * (float)0.64999998);
  v22 = (float)((float)((float)(pm_fatalFallDist.valueFloat * (float)0.64999998) * (float)0.64999998) * (float)0.27000001);
  if ( v15 != nullptr )
    v23 = (int)v15->GetPlayerInterface_2(this: v15);
  else
    v23 = 0;
  v24 = (*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v23 + 36264) + 64))(a1: v23 + 36264, a2: 0);
  v25 = this->presentable;
  v26 = (float *)v24;
  if ( v25 != nullptr )
    v27 = (int)v25->GetPlayerInterface_2(this: this->presentable);
  else
    v27 = 0;
  v28 = (float *)(*(int (__fastcall **)(int))(*(_DWORD *)(v27 + 36264) + 100))(a1: v27 + 36264);
  v29 = this->presentable;
  v30 = __fsqrts((float)((float)(v28[2] * v28[2]) + (float)((float)(*v28 * *v28) + (float)(v28[1] * v28[1]))));
  v31 = __fsqrts((float)((float)((float)v30 * (float)v22) * (float)2.0));
  if ( v29 != nullptr )
    v32 = (int)v29->GetPlayerInterface_2(this: v29);
  else
    v32 = 0;
  v33 = (float *)(*(int (__fastcall **)(int))(*(_DWORD *)(v32 + 36264) + 104))(a1: v32 + 36264);
  v34 = (float)((float)(*v33 * oldVelocity->x)
              + (float)((float)(v33[1] * oldVelocity->y) + (float)(oldVelocity->z * v33[2])));
  if ( v34 > 0.0 )
  {
    v35 = this->presentable;
    v36 = v35 != nullptr ? (int)v35->GetPlayerInterface_2(this: v35) : 0;
    (*(void (__fastcall **)(float *))(*(_DWORD *)(v36 + 36264) + 88))(a1: v78);
    v37 = v33[2];
    v38 = *v33;
    if ( (float)((float)((float)(v78[0] * *v33) + (float)((float)(v33[1] * v78[1]) + (float)(v78[2] * v33[2])))
               - (float)v34) < 0.0 )
    {
      v39 = -v33[1];
      v40 = (float)-(float)((float)((float)(*v26 - oldOrigin->x) * (float)-v38)
                          + (float)((float)((float)(v26[1] - oldOrigin->y) * (float)v39)
                                  + (float)((float)-v37 * (float)(v26[2] - oldOrigin->z))));
      v41 = (float)((float)((float)-v37 * oldVelocity->z)
                  + (float)((float)((float)-v38 * oldVelocity->x) + (float)((float)v39 * oldVelocity->y)));
      v42 = (float)((float)((float)v41 * (float)v41)
                  - (float)((float)((float)v40 * (float)((float)v30 * (float)-0.5)) * (float)4.0));
      if ( v42 >= 0.0 )
      {
        v44 = 1;
        v43 = __fabs((float)-(float)((float)((float)((float)((float)-v41 - (float)__fsqrts(v42))
                                                   / (float)((float)((float)v30 * (float)-0.5) * (float)2.0))
                                           * (float)v30)
                                   - (float)v41));
      }
      else
      {
        v43 = 0.0;
        v44 = 0;
      }
      if ( v44 != 0 )
      {
        for ( i = 0; ; ++i )
        {
          v46 = this->presentable;
          v47 = v46 != nullptr ? (int)v46->GetPlayerInterface_2(this: v46) : 0;
          v49 = i >= (*(int (__fastcall **)(int))(*(_DWORD *)(v47 + 36264) + 216))(a1: v47 + 36264);
          v48 = this->presentable;
          if ( v49 )
            break;
          if ( v48 != nullptr )
            v50 = (int)v48->GetPlayerInterface_2(this: v48);
          else
            v50 = 0;
          if ( (*(_DWORD *)((*(int (__fastcall **)(int, int))(*(_DWORD *)(v50 + 36264) + 220))(a1: v50 + 36264, a2: i)
                          + 40)
              & 0x10) != 0 )
          {
            PlayerSounds = idPlayer::GetPlayerSounds(
                             this: (idPlayer *)&v79,
                             result: (const idDeclPlayerProps::playerSounds_t *)this);
            idEntity::StartSoundShader(
              this,
              channel: SND_CHANNEL_ANY,
              shader: (const idSoundShader *)LODWORD(PlayerSounds->renderModelInfo.maxTexelDensity),
              soundShaderFlags: (soundShaderFlags_t)0,
              peerMask: 0xFFu);
            return;
          }
        }
        v52 = (float)((float)((float)v30 * (float)valueFloat) * (float)2.0);
        v53 = (float)((float)((float)v30 * (float)v20) * (float)2.0);
        v54 = (float)((float)((float)v30 * (float)v21) * (float)2.0);
        _FP31 = (float)((float)((float)1.0 - (float)v10) * (float)v43);
        v56 = __fsqrts(v52);
        v57 = __fsqrts(v53);
        v58 = __fsqrts(v54);
        if ( v48 != nullptr )
          v59 = (int)v48->GetPlayerInterface_2(this: v48);
        else
          v59 = 0;
        if ( (*(_BYTE *)(v59 + 47034) & 0x20) != 0 )
        {
          v60 = this->presentable;
          if ( v60 != nullptr )
            v61 = (int)v60->GetPlayerInterface_2(this: v60);
          else
            v61 = 0;
          _FP0 = (float)((float)_FP31 - (float)v58);
          *(_BYTE *)(v61 + 47034) &= ~0x20u;
          __asm { fsel      f31, f0, f31, f30 }
        }
        v63 = this->presentable;
        if ( v63 != nullptr )
          v64 = (int)v63->GetPlayerInterface_2(this: v63);
        else
          v64 = 0;
        if ( (*(_BYTE *)(v64 + 47034) & 0x10) != 0 )
        {
          v65 = this->presentable;
          if ( v65 != nullptr )
          {
            v66 = (int)v65->GetPlayerInterface_2(this: v65);
            *(_BYTE *)(v66 + 47034) &= ~0x10u;
          }
          else
          {
            MEMORY[0xB7BA] &= ~0x10u;
          }
          return;
        }
        if ( _FP31 < v31 )
          return;
        v67 = this->presentable;
        if ( v67 != nullptr )
          v68 = (int)v67->GetPlayerInterface_2(this: v67);
        else
          v68 = 0;
        if ( (*(_BYTE *)(v68 + 47032) & 0x20) == 0 )
        {
          v69 = this->presentable;
          if ( v69 != nullptr )
            v70 = v69->GetPlayerInterface_2(this: v69);
          else
            v70 = nullptr;
          idPresentablePlayer::PlayFootStepEffect(this: v70, footstepType: FOOTSTEP_LAND);
        }
        v71 = 0;
        v72 = -8;
        if ( _FP31 <= v56 )
        {
          if ( _FP31 <= v57 )
          {
            if ( _FP31 <= v58 )
              goto LABEL_80;
            v72 = -16;
            v73 = 1747756;
          }
          else
          {
            v72 = -24;
            v73 = 1747752;
          }
        }
        else
        {
          v72 = -32;
          v73 = 1747748;
        }
        v71 = *(int *)((char *)&gameLocal->__vftable + v73);
LABEL_80:
        v74 = this->presentable;
        if ( v74 != nullptr )
          v75 = (int)v74->GetPlayerInterface_2(this: v74);
        else
          v75 = 0;
        PlayerGameTime = idClientGame::GetPlayerGameTime(this: clientGame);
        idBobCycle::SetLandTime(this: (idBobCycle *)(v75 + 45664), _landTime: PlayerGameTime, _landChange: v72);
        if ( !common->IsMultiplayer(this: common)
          || (v77 = session->GetActingGameStateLobbyBase(this: session), v77->GetMatchParms(this: v77)->gameType != 1) )
        {
          if ( !this->ignoreFallDamage && v71 != 0 && common->IsServer(this: common) )
            ((void (__fastcall *)(idPlayer *, idWorldspawn *, idWorldspawn *, int, double))this->Damage)(
              a1: this,
              a2: gameLocal->world,
              a3: gameLocal->world,
              a4: v71,
              a5: 1.0);
        }
      }
    }
  }
}


// ========================================================================
// ?UpdatePhysicsMovementType@idPlayer@@QAAXXZ
// EA  : 0x82E7DF18
// RVA : 0x00E7DF18
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::UpdatePhysicsMovementType(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  char v4; // r10
  idPresentable *v5; // r3
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3
  pmtype_t v11; // r4
  int v12; // r3
  char v13; // r11
  idPresentable *v14; // r3
  int v15; // r3
  idPresentable *v16; // r3
  int v17; // r3
  idPresentable *v18; // r3
  int v19; // r3
  char v20; // r11
  idPresentable *v21; // r3
  int v22; // r3
  idPresentable *v23; // r3
  int v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  idPresentable *v27; // r3
  bool v28; // zf
  int v29; // r3
  int v30; // r3
  char v31; // r9
  idPresentable *v32; // r3
  int v33; // r3
  idPresentable *v34; // r3
  int v35; // r3
  idPresentable *v36; // r3
  int v37; // r3
  int v38; // r30
  idPresentable *v39; // r3
  int v40; // r3
  idLobbyBase *v41; // r3
  idPresentable *v42; // r3
  int v43; // r3
  int v44; // r4
  idPresentable *v45; // r3
  idPresentable *v46; // r3
  idPresentable *v47; // r3
  int v48; // r3
  double valueFloat; // fp28
  double v50; // fp27
  double v51; // fp26
  idPresentable *v52; // r3
  int v53; // r31
  idPresentable *v54; // r3
  int v55; // r3
  idPresentable *v56; // r3
  int v57; // r31
  idPresentable *v58; // r3
  int v59; // r3
  idPresentable *v60; // r3
  double x; // fp31
  double y; // fp30
  double z; // fp29
  bool v64; // r31
  int v65; // r3
  idPresentable *v66; // r3
  double v67; // fp30
  double v68; // fp29
  double v69; // fp31
  int v70; // r3
  int valueInteger; // r11
  idPresentable *v72; // r3
  bool v73; // r30
  int v74; // r3
  float *v75; // r11
  char v76; // r10
  double v77; // fp31
  double v78; // fp30
  double v79; // fp29
  int v80; // r3
  idPresentable *v81; // r3
  float *v82; // r3
  double v83; // fp31
  char v84; // r10
  double v85; // fp30
  double v86; // fp29
  int v87; // r3
  idPresentable *v88; // r3
  int v89; // r3
  idPresentable *v90; // r3
  int v91; // r3
  int v92; // r30
  idPresentable *v93; // r3
  int v94; // r3
  idPresentable *v95; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  v4 = *(_BYTE *)(v3 + 47032);
  v5 = this->presentable;
  if ( (v4 & 0x20) != 0 )
  {
    if ( v5 != nullptr )
      v6 = (int)v5->GetPlayerInterface_2(this: v5);
    else
      v6 = 0;
    (*(void (__fastcall **)(int, _DWORD, int))(*(_DWORD *)(v6 + 36264) + 24))(a1: v6 + 36264, a2: 0, a3: -1);
    v7 = this->presentable;
    if ( v7 != nullptr )
      v8 = (int)v7->GetPlayerInterface_2(this: v7);
    else
      v8 = 0;
    (*(void (__fastcall **)(int, _DWORD, int))(*(_DWORD *)(v8 + 36264) + 32))(a1: v8 + 36264, a2: 0, a3: -1);
    v9 = this->presentable;
    if ( v9 != nullptr )
      v10 = (int)v9->GetPlayerInterface_2(this: v9);
    else
      v10 = 0;
    v11 = PM_NOCLIP;
    goto LABEL_157;
  }
  if ( v5 != nullptr )
    v12 = (int)v5->GetPlayerInterface_2(this: v5);
  else
    v12 = 0;
  v13 = *(_BYTE *)(v12 + 47032);
  v14 = this->presentable;
  if ( (v13 & 8) != 0 )
  {
    if ( v14 != nullptr )
      v15 = (int)v14->GetPlayerInterface_2(this: v14);
    else
      v15 = 0;
    (*(void (__fastcall **)(int, _DWORD, int))(*(_DWORD *)(v15 + 36264) + 24))(a1: v15 + 36264, a2: 0, a3: -1);
    v16 = this->presentable;
    if ( v16 != nullptr )
      v17 = (int)v16->GetPlayerInterface_2(this: v16);
    else
      v17 = 0;
    (*(void (__fastcall **)(int, _DWORD, int))(*(_DWORD *)(v17 + 36264) + 32))(a1: v17 + 36264, a2: 0, a3: -1);
    v18 = this->presentable;
    if ( v18 != nullptr )
      v10 = (int)v18->GetPlayerInterface_2(this: v18);
    else
      v10 = 0;
    v11 = PM_SPECTATOR;
    goto LABEL_157;
  }
  if ( v14 != nullptr )
    v19 = (int)v14->GetPlayerInterface_2(this: v14);
  else
    v19 = 0;
  v20 = *(_BYTE *)(v19 + 47032);
  v21 = this->presentable;
  if ( (v20 & 4) != 0 )
  {
    if ( v21 != nullptr )
      v22 = (int)v21->GetPlayerInterface_2(this: v21);
    else
      v22 = 0;
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v22 + 36264) + 24))(a1: v22 + 36264, a2: 167936, a3: -1);
    v23 = this->presentable;
    if ( v23 == nullptr )
    {
      v24 = 0;
      goto LABEL_39;
    }
LABEL_37:
    v24 = (int)v23->GetPlayerInterface_2(this: v23);
LABEL_39:
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v24 + 36264) + 32))(a1: v24 + 36264, a2: 9, a3: -1);
    v25 = this->presentable;
    if ( v25 != nullptr )
      v10 = (int)v25->GetPlayerInterface_2(this: v25);
    else
      v10 = 0;
    v11 = PM_DEAD;
    goto LABEL_157;
  }
  if ( v21 != nullptr )
    v26 = (int)v21->GetPlayerInterface_2(this: v21);
  else
    v26 = 0;
  v28 = (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v26 + 352))(a1: v26) == 0;
  v27 = this->presentable;
  if ( !v28 )
  {
    if ( v27 != nullptr )
      v29 = (int)v27->GetPlayerInterface_2(this: v27);
    else
      v29 = 0;
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v29 + 36264) + 24))(a1: v29 + 36264, a2: 135312, a3: -1);
    v23 = this->presentable;
    if ( v23 == nullptr )
    {
      v24 = 0;
      goto LABEL_39;
    }
    goto LABEL_37;
  }
  if ( v27 != nullptr )
    v30 = (int)v27->GetPlayerInterface_2(this: v27);
  else
    v30 = 0;
  v31 = *(_BYTE *)(v30 + 47033);
  v32 = this->presentable;
  if ( (v31 & 4) != 0 )
  {
    if ( v32 != nullptr )
      v33 = (int)v32->GetPlayerInterface_2(this: v32);
    else
      v33 = 0;
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v33 + 36264) + 24))(a1: v33 + 36264, a2: 163840, a3: -1);
    v34 = this->presentable;
    if ( v34 != nullptr )
      v35 = (int)v34->GetPlayerInterface_2(this: v34);
    else
      v35 = 0;
    (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v35 + 36264) + 32))(a1: v35 + 36264, a2: 107529, a3: -1);
    v36 = this->presentable;
    if ( v36 != nullptr )
      v10 = (int)v36->GetPlayerInterface_2(this: v36);
    else
      v10 = 0;
    v11 = PM_PERFECTORIGIN;
  }
  else
  {
    if ( v32 != nullptr )
      v37 = (int)v32->GetPlayerInterface_2(this: v32);
    else
      v37 = 0;
    if ( *(_DWORD *)(v37 + 16132) != 1
      && pm_forceExplicitMotionX.valueFloat == 0.0
      && pm_forceExplicitMotionY.valueFloat == 0.0
      && pm_forceExplicitMotionZ.valueFloat == 0.0 )
    {
      if ( common->IsMultiplayer(this: common) )
        v38 = 163840;
      else
        v38 = 163968;
      v39 = this->presentable;
      if ( v39 != nullptr )
        v40 = (int)v39->GetPlayerInterface_2(this: v39);
      else
        v40 = 0;
      (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v40 + 36264) + 24))(a1: v40 + 36264, a2: v38, a3: -1);
      if ( g_noCoopPlayerCollision.valueInteger != 0
        && common->IsMultiplayer(this: common)
        && (v41 = session->GetActingGameStateLobbyBase(this: session), v41->GetMatchParms(this: v41)->gameType == 1) )
      {
        v42 = this->presentable;
        if ( v42 != nullptr )
          v43 = (int)v42->GetPlayerInterface_2(this: v42);
        else
          v43 = 0;
        v44 = 74761;
      }
      else
      {
        v45 = this->presentable;
        if ( v45 != nullptr )
          v43 = (int)v45->GetPlayerInterface_2(this: v45);
        else
          v43 = 0;
        v44 = 107529;
      }
      (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v43 + 36264) + 32))(a1: v43 + 36264, a2: v44, a3: -1);
      v46 = this->presentable;
      if ( v46 != nullptr )
        v10 = (int)v46->GetPlayerInterface_2(this: v46);
      else
        v10 = 0;
      v11 = PM_NORMAL;
    }
    else
    {
      v47 = this->presentable;
      if ( v47 != nullptr )
        v48 = (int)v47->GetPlayerInterface_2(this: v47);
      else
        v48 = 0;
      *(_DWORD *)(v48 + 16132) = 0;
      valueFloat = pm_forceExplicitMotionX.valueFloat;
      v50 = pm_forceExplicitMotionY.valueFloat;
      v51 = pm_forceExplicitMotionZ.valueFloat;
      if ( pm_forceExplicitMotionX.valueFloat == 0.0 && v50 == 0.0 && v51 == 0.0 )
      {
        v52 = this->presentable;
        if ( v52 != nullptr )
          v53 = (int)v52->GetPlayerInterface_2(this: v52);
        else
          v53 = 0;
        v54 = this->presentable;
        if ( v54 != nullptr )
          v55 = (int)v54->GetPlayerInterface_2(this: v54);
        else
          v55 = 0;
        *(float *)(v55 + 36720) = *(float *)(v53 + 16136);
        *(float *)(v55 + 36724) = *(float *)(v53 + 16140);
        *(float *)(v55 + 36728) = *(float *)(v53 + 16144);
        *(_BYTE *)(v55 + 36732) = *(_BYTE *)(v53 + 16148);
        *(_DWORD *)(v55 + 36736) = *(_DWORD *)(v53 + 16152);
        *(float *)(v55 + 36740) = *(float *)(v53 + 16156);
        *(float *)(v55 + 36744) = *(float *)(v53 + 16160);
        *(float *)(v55 + 36748) = *(float *)(v53 + 16164);
        *(_DWORD *)(v55 + 36752) = *(_DWORD *)(v53 + 16168);
        v56 = this->presentable;
        if ( v56 != nullptr )
          v57 = (int)v56->GetPlayerInterface_2(this: v56);
        else
          v57 = 0;
        v58 = this->presentable;
        if ( v58 != nullptr )
          v59 = (int)v58->GetPlayerInterface_2(this: v58);
        else
          v59 = 0;
        *(float *)(v59 + 36756) = *(float *)(v57 + 16172);
        *(float *)(v59 + 36760) = *(float *)(v57 + 16176);
        *(float *)(v59 + 36764) = *(float *)(v57 + 16180);
        *(_BYTE *)(v59 + 36768) = *(_BYTE *)(v57 + 16184);
        *(_DWORD *)(v59 + 36772) = *(_DWORD *)(v57 + 16188);
        *(float *)(v59 + 36776) = *(float *)(v57 + 16192);
        *(float *)(v59 + 36780) = *(float *)(v57 + 16196);
        *(float *)(v59 + 36784) = *(float *)(v57 + 16200);
        *(_DWORD *)(v59 + 36788) = *(_DWORD *)(v57 + 16204);
      }
      else
      {
        v60 = this->presentable;
        x = vec3_origin.x;
        y = vec3_origin.y;
        z = vec3_origin.z;
        v64 = pm_forceExplicitMotionClip.valueInteger != 0;
        if ( v60 != nullptr )
          v65 = (int)v60->GetPlayerInterface_2(this: v60);
        else
          v65 = 0;
        *(float *)(v65 + 36720) = valueFloat;
        *(float *)(v65 + 36728) = v51;
        *(_BYTE *)(v65 + 36732) = v64;
        *(float *)(v65 + 36724) = v50;
        *(_DWORD *)(v65 + 36736) = 0;
        *(float *)(v65 + 36740) = x;
        *(float *)(v65 + 36744) = y;
        *(float *)(v65 + 36748) = z;
        *(_DWORD *)(v65 + 36752) = 0x1FFF;
        v66 = this->presentable;
        v67 = vec3_origin.y;
        v68 = vec3_origin.z;
        v69 = vec3_origin.x;
        if ( v66 != nullptr )
          v70 = (int)v66->GetPlayerInterface_2(this: v66);
        else
          v70 = 0;
        *(float *)(v70 + 36756) = v69;
        *(float *)(v70 + 36760) = v67;
        *(_BYTE *)(v70 + 36768) = 1;
        *(float *)(v70 + 36764) = v68;
        *(_DWORD *)(v70 + 36772) = 0;
        *(float *)(v70 + 36776) = v69;
        *(float *)(v70 + 36780) = v67;
        *(float *)(v70 + 36784) = v68;
        *(_DWORD *)(v70 + 36788) = 0x1FFF;
      }
      valueInteger = pm_traceExplicitMotion.valueInteger;
      if ( pm_traceExplicitMotion.valueInteger != 0 )
      {
        v72 = this->presentable;
        v73 = true;
        if ( v72 != nullptr )
        {
          v74 = (int)v72->GetPlayerInterface_2(this: v72);
          valueInteger = pm_traceExplicitMotion.valueInteger;
        }
        else
        {
          v74 = 0;
        }
        v28 = valueInteger != 2;
        v75 = (float *)(v74 + 36720);
        if ( !v28 )
        {
          if ( *v75 != vec3_origin.x
            || *(float *)(v74 + 36724) != vec3_origin.y
            || (v76 = 1, *(float *)(v74 + 36728) != vec3_origin.z) )
          {
            v76 = 0;
          }
          v73 = v76 == 0;
        }
        if ( v73 )
        {
          v77 = *(float *)(v74 + 36728);
          v78 = *(float *)(v74 + 36724);
          v79 = *v75;
          v80 = gameLocal->GetGameFrame(this: gameLocal);
          idLib::Printf(
            fmt: "(%d)%s - exclusive explicit motion ( %0.2f, %0.2f, %0.2f )\n",
            v80,
            "idPlayer::UpdatePhysicsMovementType",
            v79,
            v78,
            v77);
        }
        v81 = this->presentable;
        if ( v81 != nullptr )
          v82 = (float *)v81->GetPlayerInterface_2(this: v81);
        else
          v82 = nullptr;
        v83 = v82[9189];
        if ( v83 != vec3_origin.x || v82[9190] != vec3_origin.y || (v84 = 1, v82[9191] != vec3_origin.z) )
          v84 = 0;
        if ( v84 == 0 )
        {
          v85 = v82[9191];
          v86 = v82[9190];
          v87 = gameLocal->GetGameFrame(this: gameLocal);
          idLib::Printf(
            fmt: "(%d)%s - exclusive explicit motion 2 ( %0.2f, %0.2f, %0.2f )\n",
            v87,
            "idPlayer::UpdatePhysicsMovementType",
            v83,
            v86,
            v85);
        }
      }
      v88 = this->presentable;
      if ( v88 != nullptr )
        v89 = (int)v88->GetPlayerInterface_2(this: v88);
      else
        v89 = 0;
      (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v89 + 36264) + 24))(a1: v89 + 36264, a2: 163840, a3: -1);
      v90 = this->presentable;
      if ( v90 != nullptr )
        v91 = (int)v90->GetPlayerInterface_2(this: v90);
      else
        v91 = 0;
      if ( *(_BYTE *)(v91 + 16148) != 0 )
        v92 = 107529;
      else
        v92 = 0x8000;
      v93 = this->presentable;
      if ( v93 != nullptr )
        v94 = (int)v93->GetPlayerInterface_2(this: v93);
      else
        v94 = 0;
      (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v94 + 36264) + 32))(a1: v94 + 36264, a2: v92, a3: -1);
      v95 = this->presentable;
      if ( v95 != nullptr )
        v10 = (int)v95->GetPlayerInterface_2(this: v95);
      else
        v10 = 0;
      v11 = PM_EXPLICIT;
    }
  }
LABEL_157:
  idPhysics_Player::SetMovementType(this: (idPhysics_Player *)(v10 + 36264), type: v11);
}


// ========================================================================
// ?ProcessInput_ServerAndClient_Local@idPlayer@@QAAXXZ
// EA  : 0x82E7EB10
// RVA : 0x00E7EB10
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::ProcessInput_ServerAndClient_Local(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v3; // r3
  int PlayerGameTime; // r3
  idLobbyBase *v5; // r3
  idLobbyBase *v6; // r3
  idPresentable *v7; // r11
  idLobbyBase *v8; // r30
  lobbyUserID_t *v9; // r4
  idLobbyBase_vtbl *v10; // r29
  idPresentablePlayer *LobbyUserID; // r3
  int v12; // r3
  unsigned __int64 v13; // r6
  const char *v14; // r7
  double CurrentValue; // fp1
  idPresentable *v16; // r3
  int v17; // r10
  double v18; // fp31
  __int64 v19; // r9
  int GameMsPerFrame; // r3
  idPresentable *v21; // r11
  int v22; // r28
  int v23; // r10
  idGameTimeManager *p_gameTimeManager; // r3
  int v25; // r3
  idPresentable *v26; // r11
  int v27; // r29
  int v28; // r28
  __int64 v29; // r10
  idPresentable *v30; // r3
  int v31; // r30
  idPresentable *v32; // r3
  int v33; // r3
  idPresentable *v34; // r3
  int v35; // r3
  idPresentable *v36; // r3
  idPresentablePlayer *v37; // r30
  idPlayer *PlayerSounds; // r3
  idPresentable *v39; // r3
  int v40; // r30
  idPresentable *v41; // r3
  int v42; // r3
  idPresentable *v43; // r3
  int v44; // r3
  idPresentable *v45; // r3
  idPresentablePlayer *v46; // r30
  idPlayer *v47; // r3
  idPresentable *v48; // r3
  idPresentablePlayer *v49; // r3
  idPresentable *v50; // r3
  bool v51; // zf
  int v52; // r3
  idPresentable *v53; // r3
  int v54; // r3
  idPresentable *v55; // r3
  idPresentablePlayer *v56; // r3
  idPresentable *v57; // r3
  int v58; // r3
  idPresentable *v59; // r3
  int v60; // r3
  int v61; // r11
  idPresentable *v62; // r3
  idPresentablePlayer *v63; // r3
  idPresentable *v64; // r3
  idPresentablePlayer *v65; // r3
  idPresentable *v66; // r3
  idPresentablePlayer *v67; // r3
  int v68; // r3
  idPresentable *v69; // r3
  int v70; // r3
  idPresentable *v71; // r3
  idPresentablePlayer *v72; // r3
  idPresentable *v73; // r3
  idPresentablePlayer *v74; // r3
  idPresentable *v75; // r3
  idPresentablePlayer *v76; // r3
  idPresentable *v77; // r3
  int v78; // r3
  idPresentable *v79; // r3
  int v80; // r3
  int v81; // r30
  idPresentable *v82; // r3
  int v83; // r3
  idPresentable *v84; // r3
  idPresentablePlayer *v85; // r3
  idPresentable *v86; // r3
  int v87; // r3
  idPresentable *v88; // r3
  idPresentablePlayer *v89; // r3
  int v90; // r3
  idPresentable *v91; // r3
  idPresentablePlayer *v92; // r3
  int v93; // r3
  idPresentable *v94; // r3
  idPresentablePlayer *v95; // r3
  idPresentable *v96; // r3
  int v97; // r3
  idPresentable *v98; // r3
  idPresentablePlayer *v99; // r3
  idPresentable *v100; // r3
  bfx::BinaryReplayLogOut *v101; // r3
  idPresentable *v102; // r3
  int v103; // r3
  int v104; // r3
  idPresentable *v105; // r11
  int v106; // r30
  int v107; // r29
  idActorModifierManager *v108; // r3
  idPresentable *v109; // r3
  int v110; // r3
  idPresentable *v111; // r3
  int v112; // r3
  idPresentable *v113; // r3
  int v114; // r3
  idPresentable *v115; // r3
  const idDeclPlayerProps::playerSounds_t *v116; // r29
  idPresentable *v117; // r3
  idPresentablePlayer *v118; // r30
  float z; // r5
  int v120; // r3
  idPresentable *v121; // r3
  const idDeclPlayerProps::playerSounds_t *v122; // r29
  idPresentable *v123; // r3
  int v124; // r3
  idPresentable *v125; // r3
  const idDeclPlayerProps::playerSounds_t *v126; // r29
  idPresentable *v127; // r3
  idPresentable *v128; // r3
  int v129; // r3
  idPresentable *v130; // r3
  const idSoundShader *len; // r27
  double v132; // fp31
  int v133; // r3
  idPresentable *v134; // r3
  int v135; // r29
  idPresentable *v136; // r3
  int v137; // r30
  double v138; // fp30
  double v139; // fp1
  idPresentable *v140; // r3
  const idDeclPlayerProps::playerSounds_t *v141; // r4
  idPresentablePlayer *v142; // r3
  idPresentable *v143; // r11
  int v144; // r3
  double valueFloat; // fp31
  double v146; // fp1
  idPresentable *v147; // r3
  double v148; // fp31
  int v149; // r3
  double v150; // fp1
  idPresentable *v151; // r3
  double v152; // fp30
  int v153; // r3
  int v154; // r3
  idPresentable *v155; // r3
  int v156; // r3
  idPresentable *v157; // r3
  int v158; // r3
  idPresentable *v159; // r3
  int v160; // r3
  unsigned __int8 v161; // r5
  idPresentable *v162; // r3
  idPresentablePlayer *v163; // r3
  idPresentable *v164; // r3
  double v165; // fp31
  idPresentablePlayer *v166; // r3
  unsigned __int8 v167; // r5
  idPresentable *v168; // r3
  idPresentablePlayer *v169; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v171; // r30
  int v172; // r3
  __int64 totalTicks; // r11
  __int64 v174; // r9
  __int64 v175; // [sp+50h] [-210h] BYREF
  idPlayerTimeLock v176[2]; // [sp+58h] [-208h] BYREF
  idPLogScope v177; // [sp+60h] [-200h] BYREF
  _BYTE v178[208]; // [sp+70h] [-1F0h] BYREF
  int v179; // [sp+140h] [-120h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = nullptr;
  PlayerGameTime = idPresentablePlayer::GetPlayerGameTime(this: v3);
  idPlayerTimeLock::idPlayerTimeLock(this: v176, newTime: PlayerGameTime);
  v5 = session->GetActingGameStateLobbyBase(this: session);
  if ( v5->IsHost(this: v5) != 0 )
  {
    v6 = session->GetActingGameStateLobbyBase(this: session);
    v7 = this->presentable;
    v8 = v6;
    v9 = v7 != nullptr ? (lobbyUserID_t *)v7->GetPlayerInterface_2(this: this->presentable) : nullptr;
    v10 = v8->__vftable;
    LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v175, result: v9);
    v12 = v10->PeerIndexFromLobbyUser(
            this: (idLobbyBase *)LobbyUserID->__vftable,
            a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1));
    if ( v12 != -1 )
      clientGame->overrideSoundPeerMask = ~(1 << v12);
  }
  RD_EventBegin(name: "idPlayer::ProcessInput");
  LODWORD(v13) = "idPlayer::ProcessInput";
  HIDWORD(v13) = 2;
  idPLogScope::idPLogScope(this: &v177, pl: &::pLog, gMask: v13, label: v14);
  if ( g_stopTime.valueInteger != 0 )
  {
    v16 = this->presentable;
    if ( v16 != nullptr )
      v17 = (int)v16->GetPlayerInterface_2(this: v16);
    else
      v17 = 0;
    v18 = *(float *)(v17 + 46648);
    GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v21 = this->presentable;
    v22 = GameMsPerFrame;
    if ( v21 != nullptr )
      v23 = (int)v21->GetPlayerInterface_2(this: this->presentable);
    else
      v23 = 0;
    LODWORD(v19) = v22;
    v175 = v19;
    p_gameTimeManager = &clientGame->gameTimeManager;
    *(float *)(v23 + 46648) = (float)v18 - (float)v19;
    v25 = idGameTimeManager::GetGameMsPerFrame(this: p_gameTimeManager, type: GAMETIME_SCALED);
    v26 = this->presentable;
    v27 = v25;
    if ( v26 != nullptr )
      v28 = (int)v26->GetPlayerInterface_2(this: this->presentable);
    else
      v28 = 0;
    LODWORD(v29) = idClientGame::GetPlayerGameTime(this: clientGame) - v27;
    v175 = v29;
    CurrentValue = idInterpolate<float>::GetCurrentValue(this: (idInterpolate<float> *)(v28 + 46648), time: (float)v29);
  }
  v30 = this->presentable;
  if ( v30 != nullptr )
    v31 = ((int (__fastcall *)(idPresentable *, double))v30->GetPlayerInterface_2)(a1: v30, a2: CurrentValue);
  else
    v31 = 0;
  v32 = this->presentable;
  if ( v32 != nullptr )
    v33 = (int)v32->GetPlayerInterface_2(this: v32);
  else
    v33 = 0;
  if ( (*(_DWORD *)(v31 + 46028) & ~*(_DWORD *)(v33 + 45968) & 0xA20FFD4) != 0 )
  {
    v34 = this->presentable;
    v35 = v34 != nullptr ? (int)v34->GetPlayerInterface_2(this: v34) : 0;
    if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v35 + 300))(a1: v35) != 0 )
    {
      v36 = this->presentable;
      if ( v36 != nullptr )
        v37 = v36->GetPlayerInterface_2(this: v36);
      else
        v37 = nullptr;
      PlayerSounds = idPlayer::GetPlayerSounds(
                       this: (idPlayer *)v178,
                       result: (const idDeclPlayerProps::playerSounds_t *)this);
      idPresentableVehicle::StartSoundShader(
        this: v37,
        channel: SND_CHANNEL_ANY,
        shader: (const idSoundShader *)LODWORD(PlayerSounds->spawnOrientation.mat[0].z),
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0);
    }
  }
  v39 = this->presentable;
  if ( v39 != nullptr )
    v40 = (int)v39->GetPlayerInterface_2(this: v39);
  else
    v40 = 0;
  v41 = this->presentable;
  if ( v41 != nullptr )
    v42 = (int)v41->GetPlayerInterface_2(this: v41);
  else
    v42 = 0;
  if ( (*(_DWORD *)(v42 + 45968) & ~*(_DWORD *)(v40 + 46028) & 0xA20FFD4) != 0 )
  {
    v43 = this->presentable;
    v44 = v43 != nullptr ? (int)v43->GetPlayerInterface_2(this: v43) : 0;
    if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v44 + 300))(a1: v44) != 0 )
    {
      v45 = this->presentable;
      if ( v45 != nullptr )
        v46 = v45->GetPlayerInterface_2(this: v45);
      else
        v46 = nullptr;
      v47 = idPlayer::GetPlayerSounds(this: (idPlayer *)v178, result: (const idDeclPlayerProps::playerSounds_t *)this);
      idPresentableVehicle::StartSoundShader(
        this: v46,
        channel: SND_CHANNEL_ANY,
        shader: (const idSoundShader *)LODWORD(v47->spawnOrientation.mat[1].x),
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0);
    }
  }
  v48 = this->presentable;
  if ( v48 != nullptr )
    v49 = v48->GetPlayerInterface_2(this: v48);
  else
    v49 = nullptr;
  v51 = !idPresentablePlayer::IsZoomedIn(ptr: v49);
  v50 = this->presentable;
  if ( v51 )
  {
    if ( v50 != nullptr )
      v68 = (int)v50->GetPlayerInterface_2(this: v50);
    else
      v68 = 0;
    if ( idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v68 + 45960), mask: 8) )
    {
      v69 = this->presentable;
      v70 = v69 != nullptr ? (int)v69->GetPlayerInterface_2(this: v69) : 0;
      if ( *(_BYTE *)(v70 + 47123) == 0 )
      {
        v71 = this->presentable;
        v72 = v71 != nullptr ? v71->GetPlayerInterface_2(this: v71) : nullptr;
        if ( !idPresentablePlayer::IsPlayerControlInhibited(this: v72) )
        {
          v73 = this->presentable;
          v74 = v73 != nullptr ? v73->GetPlayerInterface_2(this: v73) : nullptr;
          if ( !idPresentablePlayer::PlayerBehavior_WallClimb_IsInWallClimb(this: v74) )
          {
            v75 = this->presentable;
            if ( v75 != nullptr )
              v76 = v75->GetPlayerInterface_2(this: v75);
            else
              v76 = nullptr;
            idPresentablePlayer::ToggleZoom(this: v76, z: true);
          }
        }
      }
    }
  }
  else
  {
    if ( v50 != nullptr )
      v52 = (int)v50->GetPlayerInterface_2(this: v50);
    else
      v52 = 0;
    if ( !idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v52 + 45960), mask: 8)
      || ((v53 = this->presentable) == nullptr ? (v54 = 0) : (v54 = (int)v53->GetPlayerInterface_2(this: v53)),
          *(_BYTE *)(v54 + 47123) != 0
       || idPlayer::IsPlayerControlInhibited(this)
       || ((v55 = this->presentable) == nullptr ? (v56 = nullptr) : (v56 = v55->GetPlayerInterface_2(this: v55)),
           idPresentablePlayer::PlayerBehavior_WallClimb_IsInWallClimb(this: v56))) )
    {
      v64 = this->presentable;
      if ( v64 != nullptr )
        v65 = v64->GetPlayerInterface_2(this: v64);
      else
        v65 = nullptr;
      idPresentablePlayer::ToggleZoom(this: v65, z: false);
      v66 = this->presentable;
      if ( v66 != nullptr )
      {
        v67 = v66->GetPlayerInterface_2(this: v66);
        idPresentablePlayer::SetCurrentZoomLevel(this: v67, inZoomLevel: 0);
      }
      else
      {
        idPresentablePlayer::SetCurrentZoomLevel(this: nullptr, inZoomLevel: 0);
      }
    }
    else
    {
      v57 = this->presentable;
      if ( v57 != nullptr )
        v58 = (int)v57->GetPlayerInterface_2(this: v57);
      else
        v58 = 0;
      if ( idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v58 + 45960), mask: 4) )
      {
        v59 = this->presentable;
        v60 = v59 != nullptr ? (int)v59->GetPlayerInterface_2(this: v59) : 0;
        if ( (*(_BYTE *)(v60 + 45977) & 0x80) != 0 )
          LOBYTE(v61) = 0;
        else
          v61 = *(_DWORD *)(v60 + 45968);
        if ( (v61 & 4) == 0 )
        {
          v62 = this->presentable;
          if ( v62 != nullptr )
          {
            v63 = v62->GetPlayerInterface_2(this: v62);
            idPresentablePlayer::ChangeCurrentZoomLevel(this: v63);
          }
          else
          {
            idPresentablePlayer::ChangeCurrentZoomLevel(this: nullptr);
          }
        }
      }
    }
  }
  v77 = this->presentable;
  if ( v77 != nullptr )
    v78 = (int)v77->GetPlayerInterface_2(this: v77);
  else
    v78 = 0;
  if ( *(_BYTE *)(v78 + 35188) != 0 )
  {
    v79 = this->presentable;
    v80 = v79 != nullptr ? (int)v79->GetPlayerInterface_2(this: v79) : 0;
    if ( (*(_BYTE *)(v80 + 47034) & 0x40) == 0 )
    {
      v81 = 0;
      while ( 1 )
      {
        v82 = this->presentable;
        v83 = v82 != nullptr ? (int)v82->GetPlayerInterface_2(this: v82) : 0;
        if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(
                                this: (idUCmdTracker *)(v83 + 45960),
                                mask: 1024 << v81) != 0 )
          break;
        if ( ++v81 >= 6 )
          goto LABEL_127;
      }
      v84 = this->presentable;
      if ( v84 != nullptr )
        v85 = v84->GetPlayerInterface_2(this: v84);
      else
        v85 = nullptr;
      idPresentablePlayer::SelectWeapon(this: v85, num: (idDeclTypeInfo *)v81);
LABEL_127:
      v86 = this->presentable;
      if ( v86 != nullptr )
        v87 = (int)v86->GetPlayerInterface_2(this: v86);
      else
        v87 = 0;
      v51 = (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: (idUCmdTracker *)(v87 + 45960), mask: 0x40000) == 0;
      v88 = this->presentable;
      if ( v51 )
      {
        if ( v88 != nullptr )
          v90 = (int)v88->GetPlayerInterface_2(this: v88);
        else
          v90 = 0;
        v51 = (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: (idUCmdTracker *)(v90 + 45960), mask: 0x10000) == 0;
        v91 = this->presentable;
        if ( v51 )
        {
          if ( v91 != nullptr )
            v93 = (int)v91->GetPlayerInterface_2(this: v91);
          else
            v93 = 0;
          if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: (idUCmdTracker *)(v93 + 45960), mask: 0x20000) != 0 )
          {
            v94 = this->presentable;
            if ( v94 != nullptr )
              v95 = v94->GetPlayerInterface_2(this: v94);
            else
              v95 = nullptr;
            idPresentablePlayer::PrevWeapon(this: v95);
          }
        }
        else if ( v91 != nullptr )
        {
          v92 = v91->GetPlayerInterface_2(this: v91);
          idPresentablePlayer::NextWeapon(this: v92);
        }
        else
        {
          idPresentablePlayer::NextWeapon(this: nullptr);
        }
      }
      else if ( v88 != nullptr )
      {
        v89 = v88->GetPlayerInterface_2(this: v88);
        idPresentablePlayer::EquipPrevEquippedWeapon(this: v89);
      }
      else
      {
        idPresentablePlayer::EquipPrevEquippedWeapon(this: nullptr);
      }
    }
  }
  v96 = this->presentable;
  if ( v96 != nullptr )
    v97 = (int)v96->GetPlayerInterface_2(this: v96);
  else
    v97 = 0;
  if ( (unsigned __int8)idUCmdTracker::WasReleasedForPlayer(this: (idUCmdTracker *)(v97 + 45960), mask: 0x8000000) != 0 )
  {
    v98 = this->presentable;
    if ( v98 != nullptr )
      v99 = v98->GetPlayerInterface_2(this: v98);
    else
      v99 = nullptr;
    idPresentablePlayer::ShowInventory(this: v99, inVehicle: false);
  }
  v100 = this->presentable;
  if ( v100 != nullptr )
    v101 = (bfx::BinaryReplayLogOut *)v100->GetPlayerInterface_2(this: v100);
  else
    v101 = nullptr;
  idPhysics_StaticMulti::UpdateTime(this: v101);
  v102 = this->presentable;
  if ( v102 != nullptr )
    v103 = (int)v102->GetPlayerInterface_2(this: v102);
  else
    v103 = 0;
  v104 = (*(int (__fastcall **)(int))(*(_DWORD *)v103 + 96))(a1: v103);
  v105 = this->presentable;
  v106 = v104;
  if ( v105 != nullptr )
    v107 = (int)v105->GetPlayerInterface_2(this: this->presentable);
  else
    v107 = 0;
  v108 = (idActorModifierManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v106 + 360))(a1: v106);
  idActorModifierManager::HandleButtonPress(this: v108, cmdTracker: (idUCmdTracker *)(v107 + 45960));
  v109 = this->presentable;
  if ( v109 != nullptr )
    v110 = (int)v109->GetPlayerInterface_2(this: v109);
  else
    v110 = 0;
  idUCmdTracker::WasReleasedForPlayer(this: (idUCmdTracker *)(v110 + 45960), mask: 0x200000);
  v111 = this->presentable;
  if ( v111 != nullptr )
    v112 = (int)v111->GetPlayerInterface_2(this: v111);
  else
    v112 = 0;
  idUCmdTracker::WasPressedForPlayer(this: (idUCmdTracker *)(v112 + 45960), mask: 0x200000);
  v113 = this->presentable;
  if ( v113 != nullptr )
    v114 = (int)v113->GetPlayerInterface_2(this: v113);
  else
    v114 = 0;
  v51 = !idPhysics_Player::HasJumped(this: (idPhysics_Player *)(v114 + 36264));
  v115 = this->presentable;
  if ( v51 )
  {
    if ( v115 != nullptr )
      v120 = (int)v115->GetPlayerInterface_2(this: v115);
    else
      v120 = 0;
    v51 = (unsigned __int8)idPhysics_Player::HasCrouched(this: (idPhysics_Player *)(v120 + 36264)) == 0;
    v121 = this->presentable;
    if ( v51 )
    {
      if ( v121 != nullptr )
        v124 = (int)v121->GetPlayerInterface_2(this: v121);
      else
        v124 = 0;
      if ( (unsigned __int8)idPhysics_Player::HasStoodUp(this: (idPhysics_Player *)(v124 + 36264)) == 0 )
        goto LABEL_206;
      v125 = this->presentable;
      if ( v125 != nullptr )
        v126 = (const idDeclPlayerProps::playerSounds_t *)v125->GetPlayerInterface_2(this: v125);
      else
        v126 = nullptr;
      v127 = this->presentable;
      if ( v127 != nullptr )
        v118 = v127->GetPlayerInterface_2(this: v127);
      else
        v118 = nullptr;
      z = *(float *)&idPresentablePlayer::GetPlayerSounds(this: (idPresentablePlayer *)v178, result: v126)->becameReplicated;
    }
    else
    {
      if ( v121 != nullptr )
        v122 = (const idDeclPlayerProps::playerSounds_t *)v121->GetPlayerInterface_2(this: v121);
      else
        v122 = nullptr;
      v123 = this->presentable;
      if ( v123 != nullptr )
        v118 = v123->GetPlayerInterface_2(this: v123);
      else
        v118 = nullptr;
      z = idPresentablePlayer::GetPlayerSounds(this: (idPresentablePlayer *)v178, result: v122)->axes[1].mat[2].z;
    }
  }
  else
  {
    if ( v115 != nullptr )
      v116 = (const idDeclPlayerProps::playerSounds_t *)v115->GetPlayerInterface_2(this: v115);
    else
      v116 = nullptr;
    v117 = this->presentable;
    if ( v117 != nullptr )
      v118 = v117->GetPlayerInterface_2(this: v117);
    else
      v118 = nullptr;
    z = idPresentablePlayer::GetPlayerSounds(this: (idPresentablePlayer *)v178, result: v116)->axes[1].mat[2].y;
  }
  idPresentableVehicle::StartSoundShader(
    this: v118,
    channel: SND_CHANNEL_BODY,
    shader: (const idSoundShader *)LODWORD(z),
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
LABEL_206:
  if ( idPlayer::GetControl(this) != nullptr )
    goto LABEL_265;
  v128 = this->presentable;
  v129 = v128 != nullptr ? (int)v128->GetPlayerInterface_2(this: v128) : 0;
  if ( (*(_BYTE *)(v129 + 47032) & 4) != 0 )
    goto LABEL_265;
  v130 = this->presentable;
  len = nullptr;
  v132 = 1.0;
  if ( v130 != nullptr )
    v133 = (int)v130->GetPlayerInterface_2(this: v130);
  else
    v133 = 0;
  if ( *(_BYTE *)(v133 + 48573) != 0 )
  {
    v134 = this->presentable;
    if ( v134 != nullptr )
      v135 = (int)v134->GetPlayerInterface_2(this: v134);
    else
      v135 = 0;
    v136 = this->presentable;
    if ( v136 != nullptr )
      v137 = (int)v136->GetPlayerInterface_2(this: v136);
    else
      v137 = 0;
    v138 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v135 + 240))(a1: v135);
    v139 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v137 + 244))(a1: v137);
    v140 = this->presentable;
    if ( v138 >= v139 )
    {
      if ( v140 != nullptr )
        v154 = (int)v140->GetPlayerInterface_2(this: v140);
      else
        v154 = 0;
      *(_BYTE *)(v154 + 48573) = 0;
    }
    else
    {
      if ( v140 != nullptr )
        v141 = (const idDeclPlayerProps::playerSounds_t *)v140->GetPlayerInterface_2(this: v140);
      else
        v141 = nullptr;
      v142 = idPresentablePlayer::GetPlayerSounds(this: (idPresentablePlayer *)v178, result: v141);
      v143 = this->presentable;
      len = *((const idSoundShader **)&v142->__vftable + 1);
      if ( v143 != nullptr )
        v144 = (int)v143->GetPlayerInterface_2(this: this->presentable);
      else
        v144 = 0;
      valueFloat = g_damageHealthLimitHeavy.valueFloat;
      v146 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v144 + 244))(a1: v144);
      v147 = this->presentable;
      v148 = (float)((float)v146 * (float)valueFloat);
      if ( v147 != nullptr )
        v149 = (int)v147->GetPlayerInterface_2(this: v147);
      else
        v149 = 0;
      v150 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v149 + 240))(a1: v149);
      if ( v150 < v148 )
        v150 = v148;
      v151 = this->presentable;
      v152 = (float)((float)v150 - (float)v148);
      if ( v151 != nullptr )
        v153 = (int)v151->GetPlayerInterface_2(this: v151);
      else
        v153 = 0;
      v132 = (float)((float)v152
                   / (float)((float)((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v153 + 244))(a1: v153)
                           - (float)v148));
    }
  }
  v155 = this->presentable;
  if ( v155 != nullptr )
    v156 = (int)v155->GetPlayerInterface_2(this: v155);
  else
    v156 = 0;
  if ( *(float *)(v156 + 48568) < 1.0 )
  {
    if ( len == nullptr )
      len = (const idSoundShader *)idPlayer::GetPlayerSounds(
                                     this: (idPlayer *)&v179,
                                     result: (const idDeclPlayerProps::playerSounds_t *)this)->name.len;
    v157 = this->presentable;
    if ( v157 != nullptr )
      v158 = (int)v157->GetPlayerInterface_2(this: v157);
    else
      v158 = 0;
    if ( v132 > *(float *)(v158 + 48568) )
    {
      v159 = this->presentable;
      if ( v159 != nullptr )
        v160 = (int)v159->GetPlayerInterface_2(this: v159);
      else
        v160 = 0;
      v132 = *(float *)(v160 + 48568);
    }
  }
  if ( len == nullptr || v132 > 1.0 )
  {
LABEL_265:
    v168 = this->presentable;
    if ( v168 != nullptr )
      v169 = v168->GetPlayerInterface_2(this: v168);
    else
      v169 = nullptr;
    idPresentablePlayer::StopSound(this: v169, channel: SND_CHANNEL_BREATHE, peerMask: 0xFFu);
  }
  else
  {
    if ( idEntity::GetCurrentSoundShader(this, channel: SND_CHANNEL_BREATHE) != len )
    {
      v162 = this->presentable;
      if ( v162 != nullptr )
        v163 = v162->GetPlayerInterface_2(this: v162);
      else
        v163 = nullptr;
      idPresentablePlayer::PlayLocalSound(
        this: v163,
        channel: SND_CHANNEL_BREATHE,
        shader: len,
        soundShaderFlags: (soundShaderFlags_t)0);
    }
    v164 = this->presentable;
    v165 = (float)((float)v132 * (float)-60.0);
    if ( v164 != nullptr )
    {
      v166 = v164->GetPlayerInterface_2(this: v164);
      idPresentablePlayer::SetSoundVolume(
        this: v166,
        channel: SND_CHANNEL_BREATHE,
        volume: v165,
        peerMask: v167,
        a5: 0xFFu);
    }
    else
    {
      idPresentablePlayer::SetSoundVolume(
        this: nullptr,
        channel: SND_CHANNEL_BREATHE,
        volume: v165,
        peerMask: v161,
        a5: 0xFFu);
    }
  }
  if ( v177.logIndex >= 0 )
  {
    pLog = v177.pLog;
    v171 = &v177.pLog->logEntries.list[v177.logIndex];
    v172 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v171->totalTicks;
    HIDWORD(totalTicks) = v171->parent;
    LODWORD(v174) = v172 - totalTicks;
    v171->totalTicks = v174;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  idPlayerTimeLock::~idPlayerTimeLock(this: v176);
}


// ========================================================================
// __unwind$491921
// EA  : 0x82E7FC3C
// RVA : 0x00E7FC3C
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void _unwind_491921()
{
  int v0; // r12

  idPlayerTimeLock::~idPlayerTimeLock(this: (idPlayerTimeLock *)(v0 - 608 + 88));
}


// ========================================================================
// __unwind$491922
// EA  : 0x82E7FC64
// RVA : 0x00E7FC64
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void _unwind_491922()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 608 + 520));
}


// ========================================================================
// __unwind$491923
// EA  : 0x82E7FC8C
// RVA : 0x00E7FC8C
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void _unwind_491923()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 608 + 96));
}


// ========================================================================
// ?Move@idPlayer@@QAAXXZ
// EA  : 0x82E7FCC0
// RVA : 0x00E7FCC0
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::Move(idPlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPresentable *presentable; // r3
  int v5; // r3
  int v6; // r7
  idPresentable *v7; // r3
  float v8; // r5
  float v9; // r4
  int v10; // r3
  idPresentable *v11; // r3
  int v12; // r3
  float *v13; // r9
  idPresentable *v14; // r3
  double valueFloat; // fp31
  int v16; // r3
  idPresentable *v17; // r3
  double v18; // fp31
  int v19; // r3
  idPresentable *v20; // r3
  idPresentable *v21; // r3
  bool v22; // r30
  int v23; // r3
  idPresentable *v24; // r3
  const idAngles *v25; // r27
  idPresentable *v26; // r3
  int v27; // r28
  idPresentable *v28; // r3
  int v29; // r29
  idPresentable *v30; // r3
  int v31; // r30
  idPresentablePlayer *ViewAngles; // r3
  idPresentable *v33; // r3
  int v34; // r3
  idPresentable *v35; // r3
  int v36; // r3
  idPresentable *v37; // r3
  int v38; // r3
  idPresentable *v39; // r3
  int v40; // r30
  idPresentable *v41; // r3
  int v42; // r3
  idPresentable *v43; // r3
  int v44; // r30
  idPresentable *v45; // r3
  int v46; // r3
  double v47; // fp13
  bool v48; // r30
  idPresentable *v49; // r3
  float *v50; // r3
  char v51; // r11
  idPresentable *v52; // r3
  int v53; // r29
  idPresentable *v54; // r3
  int v55; // r30
  idPresentable *v56; // r3
  int v57; // r3
  double v58; // fp31
  double v59; // fp30
  double v60; // fp29
  int v61; // r3
  idPresentable *v62; // r3
  float *v63; // r3
  char v64; // r11
  idPresentable *v65; // r3
  int v66; // r29
  idPresentable *v67; // r3
  int v68; // r30
  idPresentable *v69; // r3
  int v70; // r3
  double v71; // fp31
  double v72; // fp30
  double v73; // fp29
  int v74; // r3
  idPresentable *v75; // r3
  int v76; // r3
  idPresentable *v77; // r3
  int v78; // r3
  int v79; // r30
  idPresentable *v80; // r3
  int v81; // r3
  idPresentable *v82; // r3
  int v83; // r3
  idPresentable *v84; // r3
  int v85; // r3
  idPresentable *v86; // r11
  int v87; // r29
  float *v88; // r30
  float *v89; // r3
  double v90; // fp13
  idPresentable *v91; // r3
  int v92; // r3
  int entityNumber; // r30
  double v94; // fp31
  double v95; // fp30
  idPresentable *v96; // r3
  int v97; // r30
  int v98; // r3
  idPlayer *PlayerSounds; // r3
  idPresentable *v100; // r3
  int v101; // r3
  idPresentable *v102; // r3
  int v103; // r3
  idPresentable *v104; // r3
  int v105; // r30
  idPresentable *v106; // r3
  int v107; // r3
  float *v108; // [sp+50h] [-190h] BYREF
  int v109; // [sp+54h] [-18Ch]
  idVec3 v110; // [sp+60h] [-180h] BYREF
  idAngles v111; // [sp+70h] [-170h] BYREF
  idVec3 v112; // [sp+80h] [-160h] BYREF
  idPLogScope v113[2]; // [sp+90h] [-150h] BYREF
  int v114; // [sp+A0h] [-140h] BYREF

  RD_EventBegin(name: "idPlayer::Move");
  LODWORD(v2) = "idPlayer::Move";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v113, pl: &pLog, gMask: v2, label: v3);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  v6 = (*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v5 + 36264) + 64))(a1: v5 + 36264, a2: 0);
  v8 = *(float *)(v6 + 4);
  v9 = *(float *)(v6 + 8);
  v7 = this->presentable;
  v112.x = *(float *)v6;
  v112.y = v8;
  v112.z = v9;
  if ( v7 != nullptr )
    v10 = (int)v7->GetPlayerInterface_2(this: v7);
  else
    v10 = 0;
  (*(void (__fastcall **)(idVec3 *))(*(_DWORD *)(v10 + 36264) + 88))(a1: &v110);
  v11 = this->presentable;
  if ( v11 != nullptr )
    v12 = (int)v11->GetPlayerInterface_2(this: v11);
  else
    v12 = 0;
  v13 = (float *)(*(int (__fastcall **)(float **))(*(_DWORD *)(v12 + 36264) + 264))(a1: &v108);
  v14 = this->presentable;
  v110.x = v110.x - *v13;
  v110.y = v110.y - v13[1];
  valueFloat = pm_stepsize.valueFloat;
  v110.z = v110.z - v13[2];
  if ( v14 != nullptr )
    v16 = (int)v14->GetPlayerInterface_2(this: v14);
  else
    v16 = 0;
  idPhysics_Player::SetMaxStepHeight(this: (idPhysics_Player *)(v16 + 36264), newMaxStepHeight: valueFloat);
  v17 = this->presentable;
  v18 = pm_jumpheight.valueFloat;
  if ( v17 != nullptr )
    v19 = (int)v17->GetPlayerInterface_2(this: v17);
  else
    v19 = 0;
  idPhysics_Player::SetMaxJumpHeight(this: (idPhysics_Player *)(v19 + 36264), newMaxJumpHeight: v18);
  idPlayer::UpdatePhysicsMovementType(this);
  v20 = this->presentable;
  if ( v20 != nullptr )
    v20->GetPlayerInterface_2(this: v20);
  v21 = this->presentable;
  v22 = g_debugMove.valueInteger != 0;
  if ( v21 != nullptr )
    v23 = (int)v21->GetPlayerInterface_2(this: v21);
  else
    v23 = 0;
  idPhysics_Player::SetDebugLevel(this: (idPhysics_Player *)(v23 + 36264), set: v22);
  v24 = this->presentable;
  if ( v24 != nullptr )
    v25 = (const idAngles *)v24->GetPlayerInterface_2(this: v24);
  else
    v25 = nullptr;
  v26 = this->presentable;
  if ( v26 != nullptr )
    v27 = (int)v26->GetPlayerInterface_2(this: v26);
  else
    v27 = 0;
  v28 = this->presentable;
  if ( v28 != nullptr )
    v29 = (int)v28->GetPlayerInterface_2(this: v28);
  else
    v29 = 0;
  v30 = this->presentable;
  if ( v30 != nullptr )
    v31 = (int)v30->GetPlayerInterface_2(this: v30);
  else
    v31 = 0;
  ViewAngles = idPresentablePlayer::GetViewAngles(
                 this: (idPresentablePlayer *)&v108,
                 result: v25,
                 includeWeaponKick: true);
  idPhysics_Player::SetPlayerInput(
    this: (idPhysics_Player *)(v31 + 36264),
    _prevcmd: (const usercmd_t *)(v29 + 45968),
    cmd: (const usercmd_t *)(v27 + 46028),
    newViewAngles: (const idAngles *)ViewAngles);
  if ( common->IsServer(this: common)
    && ((v33 = this->presentable) == nullptr ? (v34 = 0) : (v34 = (int)v33->GetPlayerInterface_2(this: v33)),
        (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v34 + 300))(a1: v34) == 0
     && pm_clientAuthoritative.valueInteger != 0
     && (unsigned __int8)idPlayer::AllowClientAuthPhysics(this) != 0) )
  {
    idPlayer::RunPhysics_RemoteClient(this);
  }
  else
  {
    idPlayer::RunPhysicsInternal(this);
    v35 = this->presentable;
    if ( v35 != nullptr )
      v36 = (int)v35->GetPlayerInterface_2(this: v35);
    else
      v36 = 0;
    if ( *(_DWORD *)(v36 + 16132) == 2 )
    {
      v37 = this->presentable;
      if ( v37 != nullptr )
        v38 = (int)v37->GetPlayerInterface_2(this: v37);
      else
        v38 = 0;
      *(_DWORD *)(v38 + 16132) = 0;
      v39 = this->presentable;
      if ( v39 != nullptr )
        v40 = (int)v39->GetPlayerInterface_2(this: v39);
      else
        v40 = 0;
      v41 = this->presentable;
      if ( v41 != nullptr )
        v42 = (int)v41->GetPlayerInterface_2(this: v41);
      else
        v42 = 0;
      *(float *)(v42 + 36720) = *(float *)(v40 + 16136);
      v108 = (float *)(v40 + 16156);
      *(float *)(v42 + 36724) = *(float *)(v40 + 16140);
      *(float *)(v42 + 36728) = *(float *)(v40 + 16144);
      *(_BYTE *)(v42 + 36732) = *(_BYTE *)(v40 + 16148);
      *(_DWORD *)(v42 + 36736) = *(_DWORD *)(v40 + 16152);
      *(float *)(v42 + 36740) = *(float *)(v40 + 16156);
      *(float *)(v42 + 36744) = *(float *)(v40 + 16160);
      *(float *)(v42 + 36748) = *(float *)(v40 + 16164);
      *(_DWORD *)(v42 + 36752) = *(_DWORD *)(v40 + 16168);
      v43 = this->presentable;
      if ( v43 != nullptr )
        v44 = (int)v43->GetPlayerInterface_2(this: v43);
      else
        v44 = 0;
      v45 = this->presentable;
      if ( v45 != nullptr )
        v46 = (int)v45->GetPlayerInterface_2(this: v45);
      else
        v46 = 0;
      *(float *)(v46 + 36756) = *(float *)(v44 + 16172);
      v108 = (float *)(v46 + 36776);
      v47 = *(float *)(v44 + 16176);
      v108 = (float *)(v44 + 16192);
      *(float *)(v46 + 36760) = v47;
      *(float *)(v46 + 36764) = *(float *)(v44 + 16180);
      *(_BYTE *)(v46 + 36768) = *(_BYTE *)(v44 + 16184);
      *(_DWORD *)(v46 + 36772) = *(_DWORD *)(v44 + 16188);
      *(float *)(v46 + 36776) = *(float *)(v44 + 16192);
      *(float *)(v46 + 36780) = *(float *)(v44 + 16196);
      *(float *)(v46 + 36784) = *(float *)(v44 + 16200);
      *(_DWORD *)(v46 + 36788) = *(_DWORD *)(v44 + 16204);
      if ( pm_traceExplicitMotion.valueInteger != 0 )
      {
        v48 = true;
        if ( pm_traceExplicitMotion.valueInteger == 2 )
        {
          v49 = this->presentable;
          if ( v49 != nullptr )
            v50 = (float *)v49->GetPlayerInterface_2(this: v49);
          else
            v50 = nullptr;
          if ( v50[4034] != vec3_origin.x || v50[4035] != vec3_origin.y || (v51 = 1, v50[4036] != vec3_origin.z) )
            v51 = 0;
          v48 = v51 == 0;
        }
        if ( v48 )
        {
          v52 = this->presentable;
          if ( v52 != nullptr )
            v53 = (int)v52->GetPlayerInterface_2(this: v52);
          else
            v53 = 0;
          v54 = this->presentable;
          if ( v54 != nullptr )
            v55 = (int)v54->GetPlayerInterface_2(this: v54);
          else
            v55 = 0;
          v56 = this->presentable;
          if ( v56 != nullptr )
            v57 = (int)v56->GetPlayerInterface_2(this: v56);
          else
            v57 = 0;
          v58 = *(float *)(v57 + 16136);
          v59 = *(float *)(v53 + 16144);
          v60 = *(float *)(v55 + 16140);
          v61 = gameLocal->GetGameFrame(this: gameLocal);
          idLib::Printf(
            fmt: "(%d)%s - additional explicit motion ( %0.2f, %0.2f, %0.2f )\n",
            v61,
            "idPlayer::Move",
            v58,
            v60,
            v59);
        }
        v62 = this->presentable;
        if ( v62 != nullptr )
          v63 = (float *)v62->GetPlayerInterface_2(this: v62);
        else
          v63 = nullptr;
        if ( v63[4043] != vec3_origin.x || v63[4044] != vec3_origin.y || (v64 = 1, v63[4045] != vec3_origin.z) )
          v64 = 0;
        if ( v64 == 0 )
        {
          v65 = this->presentable;
          if ( v65 != nullptr )
            v66 = (int)v65->GetPlayerInterface_2(this: v65);
          else
            v66 = 0;
          v67 = this->presentable;
          if ( v67 != nullptr )
            v68 = (int)v67->GetPlayerInterface_2(this: v67);
          else
            v68 = 0;
          v69 = this->presentable;
          if ( v69 != nullptr )
            v70 = (int)v69->GetPlayerInterface_2(this: v69);
          else
            v70 = 0;
          v71 = *(float *)(v70 + 16172);
          v72 = *(float *)(v66 + 16180);
          v73 = *(float *)(v68 + 16176);
          v74 = gameLocal->GetGameFrame(this: gameLocal);
          idLib::Printf(
            fmt: "(%d)%s - additional explicit motion 2 ( %0.2f, %0.2f, %0.2f )\n",
            v74,
            (const char *)HIDWORD(v71),
            v71,
            v73,
            v72);
        }
      }
      v75 = this->presentable;
      if ( v75 != nullptr )
        v76 = (int)v75->GetPlayerInterface_2(this: v75);
      else
        v76 = 0;
      (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v76 + 36264) + 24))(a1: v76 + 36264, a2: 163840, a3: -1);
      v77 = this->presentable;
      if ( v77 != nullptr )
        v78 = (int)v77->GetPlayerInterface_2(this: v77);
      else
        v78 = 0;
      if ( *(_BYTE *)(v78 + 16148) != 0 )
        v79 = 107529;
      else
        v79 = 0x8000;
      v80 = this->presentable;
      if ( v80 != nullptr )
        v81 = (int)v80->GetPlayerInterface_2(this: v80);
      else
        v81 = 0;
      (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v81 + 36264) + 32))(a1: v81 + 36264, a2: v79, a3: -1);
      v82 = this->presentable;
      if ( v82 != nullptr )
        v83 = (int)v82->GetPlayerInterface_2(this: v82);
      else
        v83 = 0;
      idPhysics_Player::SetMovementType(this: (idPhysics_Player *)(v83 + 36264), type: PM_EXPLICIT);
      idPlayer::RunPhysicsInternal(this);
    }
    if ( common->IsMultiplayer(this: common) )
    {
      v84 = this->presentable;
      if ( v84 != nullptr )
        v85 = (int)v84->GetPlayerInterface_2(this: v84);
      else
        v85 = 0;
      v86 = this->presentable;
      v87 = v85 + 36264;
      if ( v86 != nullptr )
        v88 = (float *)v86->GetPlayerInterface_2(this: this->presentable);
      else
        v88 = nullptr;
      v89 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v87 + 64))(a1: v87, a2: 0);
      v88[30] = *v89;
      v90 = v89[1];
      v108 = v88 + 30;
      v88[31] = v90;
      v88[32] = v89[2];
    }
  }
  if ( common->IsServer(this: common) )
    idPlayer::PlayerBehavior_PostEvent(this, event: PBE_PHYSICS_UPDATED);
  if ( g_showSpeeds.valueInteger == this->entityNumber )
  {
    v91 = this->presentable;
    if ( v91 != nullptr )
      v92 = (int)v91->GetPlayerInterface_2(this: v91);
    else
      v92 = 0;
    (*(void (__fastcall **)(idAngles *))(*(_DWORD *)(v92 + 36264) + 88))(a1: &v111);
    entityNumber = this->entityNumber;
    v94 = __fsqrts((float)((float)(v111.pitch * v111.pitch) + (float)(v111.yaw * v111.yaw)));
    v95 = __fsqrts((float)((float)((float)(v111.roll * v111.roll) + (float)(v111.pitch * v111.pitch))
                         + (float)(v111.yaw * v111.yaw)));
    idVec3::ToString(this: &v111, precision: 2);
    idLib::Printf(
      fmt: "player %d velocity dir: ( %s ), speed: %.2f, speed XY: %.2f\n",
      entityNumber,
      (const char *)HIDWORD(v95),
      v95,
      v94);
  }
  if ( (unsigned __int8)idPlayer::IsOnLadder(this) != 0 )
  {
    v96 = this->presentable;
    v109 = (int)(float)(v112.z * (float)0.03125);
    v97 = v109;
    v98 = v96 != nullptr ? (int)v96->GetPlayerInterface_2(this: v96) : 0;
    v109 = (int)(float)(*(float *)((*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v98 + 36264) + 64))(
                                     a1: v98 + 36264,
                                     a2: 0)
                                 + 8)
                      * (float)0.03125);
    if ( v97 != v109 )
    {
      PlayerSounds = idPlayer::GetPlayerSounds(
                       this: (idPlayer *)&v114,
                       result: (const idDeclPlayerProps::playerSounds_t *)this);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_ANY,
        shader: (const idSoundShader *)LODWORD(PlayerSounds->renderModelInfo.scale.x),
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
  }
  v100 = this->presentable;
  if ( v100 != nullptr )
    v101 = (int)v100->GetPlayerInterface_2(this: v100);
  else
    v101 = 0;
  if ( *(_DWORD *)(v101 + 37560) >= *(_DWORD *)(v101 + 37556) )
  {
    v102 = this->presentable;
    if ( v102 != nullptr )
      v103 = (int)v102->GetPlayerInterface_2(this: v102);
    else
      v103 = 0;
    *(_BYTE *)(v103 + 47033) &= ~4u;
  }
  v104 = this->presentable;
  if ( v104 != nullptr )
    v105 = (int)v104->GetPlayerInterface_2(this: v104);
  else
    v105 = 0;
  v106 = this->presentable;
  if ( v106 != nullptr )
    v107 = (int)v106->GetPlayerInterface_2(this: v106);
  else
    v107 = 0;
  idBobCycle::TestSteppedUp(this: (idBobCycle *)(v107 + 45664), physicsObj: (idPhysics_Player *)(v105 + 36264));
  idPlayer::CrashLand(this, oldOrigin: &v112, oldVelocity: &v110);
  idPLogScope::~idPLogScope(this: v113);
  RD_EventEnd();
}


// ========================================================================
// __unwind$493397
// EA  : 0x82E80914
// RVA : 0x00E80914
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void _unwind_493397()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 480 + 360));
}


// ========================================================================
// __unwind$493398
// EA  : 0x82E8093C
// RVA : 0x00E8093C
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void _unwind_493398()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 480 + 144));
}


// ========================================================================
// ?ProcessInput_ServerAndClient_LocalAndRemote@idPlayer@@QAAX_N@Z
// EA  : 0x82E80970
// RVA : 0x00E80970
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::ProcessInput_ServerAndClient_LocalAndRemote(idPlayer *this, bool doMovement)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v5; // r3
  int PlayerGameTime; // r3
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r30
  idPresentable *v11; // r3
  int v12; // r3
  idPresentable *v13; // r3
  int v14; // r3
  idPresentable *v15; // r11
  int v16; // r30
  int v17; // r3
  idPresentable *v18; // r3
  int v19; // r11
  idPresentable *v20; // r3
  idPresentablePlayer *v21; // r3
  idPresentable *v22; // r3
  const idAngles *v23; // r4
  idPresentablePlayer *ViewAngles; // r3
  idPresentable *v25; // r11
  idPresentablePlayer *v26; // r3
  idPresentable *v27; // r3
  idPresentablePlayer *v28; // r3
  idPresentable *v29; // r3
  int v30; // r3
  idPresentable *v31; // r11
  idUCmdTracker *v32; // r24
  int v33; // r3
  idPresentable *v34; // r11
  idUCmdTracker *v35; // r30
  int v36; // r3
  idPresentable *v37; // r11
  int v38; // r25
  int v39; // r3
  idPresentable *v40; // r3
  idPresentablePlayer *v41; // r3
  idPresentable *v42; // r3
  int v43; // r11
  int v44; // r30
  idPlayerHud *PlayerHud; // r3
  idPresentable *v46; // r3
  int v47; // r11
  int v48; // r30
  idPlayerHud *v49; // r3
  idPresentable *v50; // r3
  int v51; // r3
  idPresentable *v52; // r3
  idPresentablePlayer *v53; // r3
  idAI2 *FocusEntity; // r3
  idAI2 *v55; // r3
  idAI2 *v56; // r27
  idPresentable *v57; // r3
  int v58; // r28
  int v59; // r29
  idPresentable *v60; // r3
  int v61; // r30
  idPresentable *v62; // r3
  int v63; // r3
  idPlayer *v64; // r16
  bool IsReverse; // r29
  bool IsDW; // r3
  int v67; // r29
  int v68; // r28
  idPresentable *v69; // r3
  idPresentablePlayer *v70; // r3
  idPresentable *v71; // r3
  idPresentablePlayer *v72; // r3
  idPresentable *v74; // r3
  idPresentablePlayer *v75; // r3
  idPresentable *v76; // r3
  idPresentablePlayer *v77; // r3
  idPresentable *v78; // r3
  int v79; // r3
  idPresentable *v80; // r3
  idPresentablePlayer *v81; // r3
  idPresentable *v82; // r3
  idPresentablePlayer *v83; // r30
  idPresentable *v84; // r3
  int v85; // r3
  idPresentable *v86; // r3
  int v87; // r3
  idPresentable *v88; // r3
  int v89; // r11
  idPresentable *v90; // r3
  int v91; // r3
  idPresentable *v92; // r3
  int v93; // r3
  idPresentable *v94; // r3
  idPresentablePlayer *v95; // r3
  idPresentable *v96; // r3
  idPresentablePlayer *v97; // r3
  idPresentable *v98; // r3
  idPresentablePlayer *v99; // r3
  idPresentable *v100; // r3
  idPresentablePlayer *v101; // r3
  idPresentable *v102; // r3
  idPresentablePlayer *v103; // r3
  idPresentable *v104; // r3
  int v105; // r3
  idPresentable *v106; // r3
  int v107; // r3
  idPresentable *v108; // r3
  int v109; // r3
  int v110; // r29
  int PreviousPlayerGameTime; // r3
  idPresentable *v112; // r11
  int v113; // r28
  int v114; // r30
  idPresentable *v115; // r3
  idPresentablePlayer *v116; // r3
  idPlayerTimeLock v117; // [sp+50h] [-B0h] BYREF
  int v118; // [sp+54h] [-ACh]
  idAngles v119; // [sp+58h] [-A8h] BYREF
  int v120; // [sp+68h] [-98h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = nullptr;
  PlayerGameTime = idPresentablePlayer::GetPlayerGameTime(this: v5);
  idPlayerTimeLock::idPlayerTimeLock(this: &v117, newTime: PlayerGameTime);
  if ( !common->IsMultiplayer(this: common)
    || ((v7 = this->presentable) == nullptr ? (v8 = 0) : (v8 = (int)v7->GetPlayerInterface_2(this: v7)),
        (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v8 + 300))(a1: v8) != 0) )
  {
    idPlayer::UpdateSprint(this);
  }
  else
  {
    v9 = this->presentable;
    if ( v9 != nullptr )
      v10 = (int)v9->GetPlayerInterface_2(this: v9);
    else
      v10 = 0;
    v11 = this->presentable;
    if ( v11 != nullptr )
      v12 = (int)v11->GetPlayerInterface_2(this: v11);
    else
      v12 = 0;
    *(_BYTE *)(v12 + 47121) = (*(_BYTE *)(v10 + 46066) & 2) != 0;
    v13 = this->presentable;
    if ( v13 != nullptr )
      v14 = (int)v13->GetPlayerInterface_2(this: v13);
    else
      v14 = 0;
    v15 = this->presentable;
    v16 = v14 + 46028;
    if ( v15 != nullptr )
      v17 = (int)v15->GetPlayerInterface_2(this: this->presentable);
    else
      v17 = 0;
    *(_BYTE *)(v17 + 47032) = (16 * *(_BYTE *)(v16 + 38)) & 0x40 | *(_BYTE *)(v17 + 47032) & 0xBF;
  }
  v18 = this->presentable;
  if ( v18 != nullptr )
    v19 = (int)v18->GetPlayerInterface_2(this: v18);
  else
    v19 = 0;
  idPlayer::AdjustSpeed(this, cmd: (const usercmd_t *)(v19 + 46028));
  v20 = this->presentable;
  if ( v20 != nullptr )
    v21 = v20->GetPlayerInterface_2(this: v20);
  else
    v21 = nullptr;
  idPresentablePlayer::UpdateViewAngles(this: v21);
  v22 = this->presentable;
  if ( v22 != nullptr )
    v23 = (const idAngles *)v22->GetPlayerInterface_2(this: v22);
  else
    v23 = nullptr;
  ViewAngles = idPresentablePlayer::GetViewAngles(
                 this: (idPresentablePlayer *)&v120,
                 result: v23,
                 includeWeaponKick: true);
  v25 = this->presentable;
  v119.yaw = *((float *)&ViewAngles->__vftable + 1);
  v119.pitch = 0.0;
  v119.roll = 0.0;
  if ( v25 != nullptr )
    v26 = v25->GetPlayerInterface_2(this: v25);
  else
    v26 = nullptr;
  idPresentablePlayer::SetAngles(this: v26, ang: &v119);
  v27 = this->presentable;
  if ( v27 != nullptr )
    v28 = v27->GetPlayerInterface_2(this: v27);
  else
    v28 = nullptr;
  idPresentablePlayer::PlayerUpdateZoomState(this: v28);
  if ( doMovement )
    idPlayer::Move(this);
  clientGame->overrideSoundPeerMask = 0;
  v29 = this->presentable;
  if ( v29 != nullptr )
    v30 = (int)v29->GetPlayerInterface_2(this: v29);
  else
    v30 = 0;
  v31 = this->presentable;
  v32 = (idUCmdTracker *)(v30 + 45960);
  if ( v31 != nullptr )
    v33 = (int)v31->GetPlayerInterface_2(this: this->presentable);
  else
    v33 = 0;
  v34 = this->presentable;
  v35 = (idUCmdTracker *)(v33 + 46244);
  if ( v34 != nullptr )
    v36 = (int)v34->GetPlayerInterface_2(this: this->presentable);
  else
    v36 = 0;
  v37 = this->presentable;
  v38 = v36 + 47160;
  if ( v37 != nullptr )
    v39 = (int)v37->GetPlayerInterface_2(this: this->presentable);
  else
    v39 = 0;
  if ( (*(_BYTE *)(v39 + 47033) & 0x40) != 0 )
  {
    v40 = this->presentable;
    if ( v40 != nullptr )
      v41 = v40->GetPlayerInterface_2(this: v40);
    else
      v41 = nullptr;
    if ( idPresentablePlayer::GetControl(this: v41) == nullptr )
      v35 = v32;
    if ( (unsigned __int8)idUCmdTracker::WasReleasedForPlayer(this: v35, mask: 4) != 0 )
    {
      v42 = this->presentable;
      if ( v42 != nullptr )
        v43 = (int)v42->GetPlayerInterface_2(this: v42);
      else
        v43 = 0;
      v44 = *(_DWORD *)(v43 + 180);
      PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this);
      idPlayerHud::AcceptRespawnFromSpectate(this: PlayerHud, playerIndex: v44);
    }
    else if ( (unsigned __int8)idUCmdTracker::WasReleasedForPlayer(this: v35, mask: 128) != 0 )
    {
      v46 = this->presentable;
      if ( v46 != nullptr )
        v47 = (int)v46->GetPlayerInterface_2(this: v46);
      else
        v47 = 0;
      v48 = *(_DWORD *)(v47 + 180);
      v49 = (idPlayerHud *)idPlayer::GetPlayerHud(this);
      idPlayerHud::OpenGarageFromSpectate(this: v49, playerIndex: v48);
    }
  }
  if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: v32, mask: 1) != 0
    || ((v50 = this->presentable) == nullptr ? (v51 = 0) : (v51 = (int)v50->GetPlayerInterface_2(this: v50)),
        idHands::TakedownKnifeGripIsDW(this: (idHands *)(v51 + 37616))
     && (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: v32, mask: 8) != 0) )
  {
    if ( *(_DWORD *)(v38 + 532) != 0 )
    {
      v52 = this->presentable;
      v53 = v52 != nullptr ? v52->GetPlayerInterface_2(this: v52) : nullptr;
      FocusEntity = (idAI2 *)idPresentablePlayer::GetFocusEntity(this: v53);
      v55 = idAI2::CastTo(c: FocusEntity);
      v56 = v55;
      if ( v55 != nullptr )
      {
        v118 = *(_DWORD *)(v38 + 532);
        if ( v118 == 2 || v118 == 3 || idAI2::TakedownWindoIsOpen(this: v55) )
        {
          v57 = this->presentable;
          v58 = *(_DWORD *)(v38 + 532);
          if ( v57 != nullptr )
            v59 = (int)v57->GetPlayerInterface_2(this: v57);
          else
            v59 = 0;
          v60 = this->presentable;
          if ( v60 != nullptr )
            v61 = (int)v60->GetPlayerInterface_2(this: v60);
          else
            v61 = 0;
          v62 = this->presentable;
          if ( v62 != nullptr )
            v63 = (int)v62->GetPlayerInterface_2(this: v62);
          else
            v63 = 0;
          v64 = *(idPlayer **)(v63 + 1096);
          IsReverse = idHands::TakedownKnifeGripIsReverse(this: (idHands *)(v59 + 37616));
          IsDW = idHands::TakedownKnifeGripIsDW(this: (idHands *)(v61 + 37616));
          idAI2::Takedown(this: v56, activator: v64, dualWield: IsDW, reversedGrip: IsReverse, takeDownMode: v58);
        }
      }
    }
  }
  v67 = *(_DWORD *)(v38 + 108) | 0x20;
  v68 = (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: v32, mask: v67);
  if ( v68 != 0 )
  {
    v69 = this->presentable;
    if ( v69 != nullptr )
      v70 = v69->GetPlayerInterface_2(this: v69);
    else
      v70 = nullptr;
    idPresentablePlayer::BeforeUse(this: v70);
  }
  v71 = this->presentable;
  if ( v71 != nullptr )
    v72 = v71->GetPlayerInterface_2(this: v71);
  else
    v72 = nullptr;
  if ( idPresentablePlayer::BeforeUseIsRunning(this: v72) )
  {
    if ( (unsigned __int8)idUCmdTracker::WasReleasedForPlayer(this: v32, mask: v67) == 0 )
      goto LABEL_116;
  }
  else if ( v68 == 0 )
  {
    goto LABEL_116;
  }
  v74 = this->presentable;
  if ( v74 != nullptr )
    v75 = v74->GetPlayerInterface_2(this: v74);
  else
    v75 = nullptr;
  if ( idPresentablePlayer::Use(this: v75) )
  {
    if ( common->IsServer(this: common) && (this->thinkFlags & 1) == 0 )
    {
      clientGame->overrideSoundPeerMask = 0;
      goto LABEL_187;
    }
  }
  else if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: v32, mask: 32) != 0 )
  {
    v76 = this->presentable;
    if ( v76 != nullptr )
      v77 = v76->GetPlayerInterface_2(this: v76);
    else
      v77 = nullptr;
    idPresentablePlayer::Reload(this: v77);
  }
LABEL_116:
  v78 = this->presentable;
  if ( v78 != nullptr )
    v79 = (int)v78->GetPlayerInterface_2(this: v78);
  else
    v79 = 0;
  if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: (idUCmdTracker *)(v79 + 45960), mask: 128) != 0 )
  {
    v80 = this->presentable;
    if ( v80 != nullptr )
      v81 = v80->GetPlayerInterface_2(this: v80);
    else
      v81 = nullptr;
    idPresentablePlayer::Reload(this: v81);
  }
  v82 = this->presentable;
  if ( v82 != nullptr )
    v83 = v82->GetPlayerInterface_2(this: v82);
  else
    v83 = nullptr;
  v84 = this->presentable;
  if ( v84 != nullptr )
    v85 = (int)v84->GetPlayerInterface_2(this: v84);
  else
    v85 = 0;
  idBobCycle::Update(this: (idBobCycle *)(v85 + 45664), player: v83);
  v86 = this->presentable;
  if ( v86 != nullptr )
    v87 = (int)v86->GetPlayerInterface_2(this: v86);
  else
    v87 = 0;
  if ( *(_DWORD *)(v87 + 45940) != 0 && pm_thirdPerson.valueInteger == 0 )
  {
    v88 = this->presentable;
    v89 = v88 != nullptr ? (int)v88->GetPlayerInterface_2(this: v88) : 0;
    if ( (unsigned __int8)idActor::PlayFootStepEffect(
                            this,
                            footstepType: (footStepType_t)((_cntlzw(*(_DWORD *)(v89 + 45940) - 1) & 0x20) != 0)) != 0 )
    {
      v90 = this->presentable;
      if ( v90 != nullptr )
        v91 = (int)v90->GetPlayerInterface_2(this: v90);
      else
        v91 = 0;
      *(_DWORD *)(v91 + 45940) = 0;
    }
  }
  v92 = this->presentable;
  if ( v92 != nullptr )
    v93 = (int)v92->GetPlayerInterface_2(this: v92);
  else
    v93 = 0;
  if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v93 + 300))(a1: v93) != 0 )
  {
    v94 = this->presentable;
    v95 = v94 != nullptr ? v94->GetPlayerInterface_2(this: v94) : nullptr;
    idPresentablePlayer::HandleCameraShake(this: v95);
    v96 = this->presentable;
    v97 = v96 != nullptr ? v96->GetPlayerInterface_2(this: v96) : nullptr;
    idPresentablePlayer::UpdateStepUpSprings(this: v97);
    v98 = this->presentable;
    v99 = v98 != nullptr ? v98->GetPlayerInterface_2(this: v98) : nullptr;
    idPresentablePlayer::CalculateView(this: v99);
    if ( g_dragEntity.valueInteger != 0 || g_editEntityMode.valueInteger > 0 )
    {
      v102 = this->presentable;
      v103 = v102 != nullptr ? v102->GetPlayerInterface_2(this: v102) : nullptr;
      idPresentablePlayer::UpdateEditEntityMode(this: v103);
    }
    else
    {
      v100 = this->presentable;
      if ( v100 != nullptr )
      {
        v101 = v100->GetPlayerInterface_2(this: v100);
        idPresentablePlayer::UpdateWeapon(this: v101);
      }
      else
      {
        idPresentablePlayer::UpdateWeapon(this: nullptr);
      }
    }
    v104 = this->presentable;
    v105 = v104 != nullptr ? (int)v104->GetPlayerInterface_2(this: v104) : 0;
    if ( (*(int (__fastcall **)(int, int))(*(_DWORD *)v105 + 344))(a1: v105, a2: 2) != 0 && !idPlayer::IsBot(this) )
    {
      v106 = this->presentable;
      if ( v106 != nullptr )
        v107 = (int)v106->GetPlayerInterface_2(this: v106);
      else
        v107 = 0;
      idAimAssist::Update(this: (idAimAssist *)(v107 + 48688));
    }
  }
  if ( common->IsMultiplayer(this: common) && common->IsServer(this: common) )
  {
    v108 = this->presentable;
    v109 = v108 != nullptr ? (int)v108->GetPlayerInterface_2(this: v108) : 0;
    if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v109 + 300))(a1: v109) == 0 )
    {
      v110 = idClientGame::GetPlayerGameTime(this: clientGame);
      PreviousPlayerGameTime = idClientGame::GetPreviousPlayerGameTime(this: clientGame);
      v112 = this->presentable;
      v113 = PreviousPlayerGameTime;
      if ( v112 != nullptr )
        v114 = (int)v112->GetPlayerInterface_2(this: this->presentable);
      else
        v114 = 0;
      v115 = this->presentable;
      if ( v115 != nullptr )
        v116 = v115->GetPlayerInterface_2(this: v115);
      else
        v116 = nullptr;
      idPresentablePlayer::EvaluateClientFire(
        this: v116,
        usercmd: (const usercmd_t *)(v114 + 46028),
        startTime: v113,
        endTime: v110);
    }
  }
LABEL_187:
  idPlayerTimeLock::~idPlayerTimeLock(this: &v117);
}


// ========================================================================
// __unwind$494368
// EA  : 0x82E81504
// RVA : 0x00E81504
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void _unwind_494368()
{
  int v0; // r12

  idPlayerTimeLock::~idPlayerTimeLock(this: (idPlayerTimeLock *)(v0 - 256 + 80));
}


// ========================================================================
// ?ProcessInput@idPlayer@@QAAX_N@Z
// EA  : 0x82E81530
// RVA : 0x00E81530
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __fastcall idPlayer::ProcessInput(idPlayer *this, bool doMovement)
{
  idPresentable *presentable; // r3
  int v5; // r3

  if ( common->IsServer(this: common) )
    idPlayer::ProcessInput_ServerOnly(this);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v5 + 300))(a1: v5) != 0 )
    idPlayer::ProcessInput_ServerAndClient_Local(this);
  idPlayer::ProcessInput_ServerAndClient_LocalAndRemote(this, doMovement);
}


// ========================================================================
// `dynamic initializer for 'pm_traceExplicitMotion''
// EA  : 0x8338FFB0
// RVA : 0x0138FFB0
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_traceExplicitMotion__()
{
  idCVar::idCVar(
    this: &pm_traceExplicitMotion,
    name: "pm_traceExplicitMotion",
    value: "0",
    flags: 2,
    description: "0=off, 1=trace the explicit motion deltas, 2=trace nonzero deltas only",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_traceExplicitMotion__);
}


// ========================================================================
// `dynamic initializer for 'pm_forceExplicitMotionClip''
// EA  : 0x83390008
// RVA : 0x01390008
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_forceExplicitMotionClip__()
{
  idCVar::idCVar(
    this: &pm_forceExplicitMotionClip,
    name: "pm_forceExplicitMotionClip",
    value: "0",
    flags: 1,
    description: "clip the forced move",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_forceExplicitMotionClip__);
}


// ========================================================================
// `dynamic initializer for 'pm_clientAuthoritative_warnDist''
// EA  : 0x83390060
// RVA : 0x01390060
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_clientAuthoritative_warnDist__()
{
  idCVar::idCVar(
    this: &pm_clientAuthoritative_warnDist,
    name: "pm_clientAuthoritative_warnDist",
    value: "100.0f",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_clientAuthoritative_warnDist__);
}


// ========================================================================
// `dynamic initializer for 'pm_clientAuthoritative_minDistZ''
// EA  : 0x833900B8
// RVA : 0x013900B8
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_clientAuthoritative_minDistZ__()
{
  idCVar::idCVar(
    this: &pm_clientAuthoritative_minDistZ,
    name: "pm_clientAuthoritative_minDistZ",
    value: "1.0f",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_clientAuthoritative_minDistZ__);
}


// ========================================================================
// `dynamic initializer for 'pm_clientAuthoritative_minDist''
// EA  : 0x83390110
// RVA : 0x01390110
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_clientAuthoritative_minDist__()
{
  idCVar::idCVar(
    this: &pm_clientAuthoritative_minDist,
    name: "pm_clientAuthoritative_minDist",
    value: "-1.0f",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_clientAuthoritative_minDist__);
}


// ========================================================================
// `dynamic initializer for 'pm_clientAuthoritative_Lerp''
// EA  : 0x83390168
// RVA : 0x01390168
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_clientAuthoritative_Lerp__()
{
  idCVar::idCVar(
    this: &pm_clientAuthoritative_Lerp,
    name: "pm_clientAuthoritative_Lerp",
    value: "0.9f",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_clientAuthoritative_Lerp__);
}


// ========================================================================
// `dynamic initializer for 'pm_forceExplicitMotionX''
// EA  : 0x833901C0
// RVA : 0x013901C0
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_forceExplicitMotionX__()
{
  idCVar::idCVar(
    this: &pm_forceExplicitMotionX,
    name: "pm_forceExplicitMotionX",
    value: "0",
    flags: 4,
    description: "x value of explicit motion to force",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_forceExplicitMotionX__);
}


// ========================================================================
// `dynamic initializer for 'pm_forceExplicitMotionY''
// EA  : 0x83390218
// RVA : 0x01390218
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_forceExplicitMotionY__()
{
  idCVar::idCVar(
    this: &pm_forceExplicitMotionY,
    name: "pm_forceExplicitMotionY",
    value: "0",
    flags: 4,
    description: "y value of explicit motion to force",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_forceExplicitMotionY__);
}


// ========================================================================
// `dynamic initializer for 'pm_forceExplicitMotionZ''
// EA  : 0x83390270
// RVA : 0x01390270
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_forceExplicitMotionZ__()
{
  idCVar::idCVar(
    this: &pm_forceExplicitMotionZ,
    name: "pm_forceExplicitMotionZ",
    value: "0",
    flags: 4,
    description: "z value of explicit motion to force",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_forceExplicitMotionZ__);
}


// ========================================================================
// `dynamic initializer for 'pm_autoSprint''
// EA  : 0x833902C8
// RVA : 0x013902C8
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_autoSprint__()
{
  idCVar::idCVar(
    this: &pm_autoSprint,
    name: "pm_autoSprint",
    value: "0",
    flags: 1,
    description: "Forces sprint off. When pm_autoSprint is 1, pm_autoSprintSpeed will be used as max movement speed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_autoSprint__);
}


// ========================================================================
// `dynamic initializer for 'pm_autoSprintSpeed''
// EA  : 0x83390320
// RVA : 0x01390320
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_autoSprintSpeed__()
{
  idCVar::idCVar(
    this: &pm_autoSprintSpeed,
    name: "pm_autoSprintSpeed",
    value: "480",
    flags: 4,
    description: "Max movement speed used when pm_autoSprint is 1.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_autoSprintSpeed__);
}


// ========================================================================
// `dynamic initializer for 'p_infiniteSprintMode''
// EA  : 0x83390378
// RVA : 0x01390378
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_infiniteSprintMode__()
{
  idCVar::idCVar(
    this: &p_infiniteSprintMode,
    name: "p_infiniteSprintMode",
    value: "1",
    flags: 1,
    description: "Disable the stamina system",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_infiniteSprintMode__);
}


// ========================================================================
// `dynamic initializer for 'p_drawSprintValues''
// EA  : 0x833903D0
// RVA : 0x013903D0
// PDB : w:\tech5\tungsten\game\player\player_movement.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_drawSprintValues__()
{
  idCVar::idCVar(
    this: &p_drawSprintValues,
    name: "p_drawSprintValues",
    value: "-1",
    flags: 2,
    description: "draw a graph the sprint values for this entitynum. -1 disables",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_drawSprintValues__);
}

