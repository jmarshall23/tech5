
// ========================================================================
// ?ApplyImpulse@idPlayer@@UAAXHHABVidVec3@@0@Z
// EA  : 0x82E24710
// RVA : 0x00E24710
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ApplyImpulse(idPlayer *this, int physId, int id, const idVec3 *point, const idVec3 *impulse)
{
  if ( idPhysics::GetPhysicsForId(physicsId_: physId) != nullptr )
    idAnimatedEntity::ApplyImpulse(this, physId, bodyId: id, point, impulse);
}


// ========================================================================
// ?UpdateApplyDamageScale@idPlayer@@QAAXXZ
// EA  : 0x82E24760
// RVA : 0x00E24760
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateApplyDamageScale(idPlayer *this)
{
  if ( this->applyDamageScaleEndTime != 0
    && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL) > this->applyDamageScaleEndTime )
  {
    this->applyDamageScaleEndTime = 0;
    this->applyDamageScale = 1.0;
    idLib::Warning(fmt: "Damage scale increase has ended");
  }
}


// ========================================================================
// ?UpdateInvulnerability@idPlayer@@QAAXXZ
// EA  : 0x82E247E0
// RVA : 0x00E247E0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateInvulnerability(idPlayer *this)
{
  if ( this->invulnerabilityEndTime != 0
    && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL) > this->invulnerabilityEndTime )
  {
    idLib::Warning(fmt: "Authority Force has ended");
    this->invulnerabilityEndTime = 0;
    this->isInvulnerable = false;
  }
}


// ========================================================================
// ?GetLastDamagedTime@idPlayer@@QBAHXZ
// EA  : 0x82E24858
// RVA : 0x00E24858
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::GetLastDamagedTime(idPlayer *this)
{
  return this->lastDamagedTime;
}


// ========================================================================
// ?ClearLevelTransitionGuiVolume@idPlayer@@QAAXXZ
// EA  : 0x82E24860
// RVA : 0x00E24860
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ClearLevelTransitionGuiVolume(idPlayer *this)
{
  this->levelTransitionGuiVolume = nullptr;
  this->levelTransitionGuiVolumeActive = false;
}


// ========================================================================
// ?ApplyDamage@idPlayer@@UAAXHHPBVidDeclDamage@@@Z
// EA  : 0x82E24870
// RVA : 0x00E24870
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ApplyDamage(
        idPlayer *this,
        const int physId,
        const int bodyId,
        const idDeclDamage *damageDecl)
{
  if ( damageDecl != nullptr )
    ((void (__fastcall *)(idPlayer *, _DWORD, _DWORD, double))this->Damage)(a1: this, a2: 0, a3: 0, a4: 1.0);
}


// ========================================================================
// ?CanBeHealed@idPlayer@@UBA_NXZ
// EA  : 0x82E248A8
// RVA : 0x00E248A8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

// attributes: thunk
const idBaseHealth *__fastcall idPlayer::CanBeHealed(idPlayer *this)
{
  return idActor::CanBeHealed(this);
}


// ========================================================================
// ?SetPosture@idPlayer@@UAAXW4posture_t@@@Z
// EA  : 0x82E248B0
// RVA : 0x00E248B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

// attributes: thunk
void __fastcall idPlayer::SetPosture(idPlayer *this, posture_t state)
{
  idActor::SetPosture(this, state);
}


// ========================================================================
// ?Event_GetGameStateInt@idPlayer@@AAA?AVeventFloat@@PBD@Z
// EA  : 0x82E248B8
// RVA : 0x00E248B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_GetGameStateInt(idPlayer *this, eventFloat *result, const char *gameStateName)
{
  __int64 v4; // r10

  LODWORD(v4) = idJobManager::GetGameStateIntValue(this: (idJobManager *)&result[3103], name: gameStateName);
  eventFloat::eventFloat((eventFloat *)this, f: (float)v4);
  return this;
}


// ========================================================================
// ?RespondsToAIEvent@idPlayer@@UBA_NPBVidAIEvent@@@Z
// EA  : 0x82E24918
// RVA : 0x00E24918
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::RespondsToAIEvent(idPlayer *this, const idAIEvent *event)
{
  return (idAIEvent::GetEventClass(this: event) & 0x100000) != 0;
}


// ========================================================================
// ?GetPlayerSounds@idPlayer@@QBA?BUplayerSounds_t@idDeclPlayerProps@@XZ
// EA  : 0x82E24940
// RVA : 0x00E24940
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::GetPlayerSounds(idPlayer *this, const idDeclPlayerProps::playerSounds_t *result)
{
  const idSoundShader *sndBreatheMedium; // r11

  sndBreatheMedium = result[60].sndBreatheMedium;
  if ( sndBreatheMedium != nullptr )
    memcpy(Dst: this, Src: &sndBreatheMedium->parms.wetMaxDistanceOffset, Size: 0xC8u);
  else
    idDeclPlayerProps::playerSounds_t::playerSounds_t((idDeclPlayerProps::playerSounds_t *)this);
  return this;
}


// ========================================================================
// ?IsEverUsable@idPlayer@@UBA_NPBVidEntity@@@Z
// EA  : 0x82E24990
// RVA : 0x00E24990
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::IsEverUsable(idPlayer *this, const idEntity *activator)
{
  idGameChallenge *ChallengeEntity; // r3

  ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
  return ChallengeEntity->PlayerReviveEnabled(this: ChallengeEntity);
}


// ========================================================================
// ?SetTension@idPlayer@@QAAXW4tensionType_t@1@@Z
// EA  : 0x82E249C8
// RVA : 0x00E249C8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetTension(idPlayer *this, idPlayer::tensionType_t tension)
{
  this->currentPlayerTension = tension;
  this->lastSetTensionTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
}


// ========================================================================
// ?GetBotGoalTask@idPlayer@@QAAPAVidBotGoal@@XZ
// EA  : 0x82E24A18
// RVA : 0x00E24A18
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idBotGoal *__fastcall idPlayer::GetBotGoalTask(idPlayer *this)
{
  idBot *botController; // r11
  idBotGoal *result; // r3

  botController = this->botController;
  result = &botController->goalTask;
  if ( botController == nullptr )
    return nullptr;
  return result;
}


// ========================================================================
// ?IsBot@idPlayer@@QBA_NXZ
// EA  : 0x82E24A30
// RVA : 0x00E24A30
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::IsBot(idPlayer *this)
{
  return this->botController != nullptr;
}


// ========================================================================
// ?IsBotControllingAFKPlayer@idPlayer@@QBA_NXZ
// EA  : 0x82E24A40
// RVA : 0x00E24A40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::IsBotControllingAFKPlayer(idPlayer *this)
{
  idBot *botController; // r11
  BOOL result; // r3

  botController = this->botController;
  result = false;
  if ( botController != nullptr )
    return botController->isControllingAFKPlayer;
  return result;
}


// ========================================================================
// ?UpdateBotGUI@idPlayer@@QBAXAAVidGuiListBox@@W4botDebugGuiType_t@@@Z
// EA  : 0x82E24A58
// RVA : 0x00E24A58
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateBotGUI(idPlayer *this, idGuiListBox *infoList, unsigned int debugType)
{
  idBot *botController; // r3

  botController = this->botController;
  if ( botController != nullptr )
    idBot::UpdateBotGUI(this: botController, infoList, debugType);
}


// ========================================================================
// ?PhysicsHandler_CrouchJump@idPlayer@@CA_NHABVidVec3@@000ABVusercmd_t@@@Z
// EA  : 0x82E24A70
// RVA : 0x00E24A70
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::PhysicsHandler_CrouchJump(
        unsigned int entityNumber,
        const idVec3 *pos,
        const idVec3 *forward,
        const idVec3 *right,
        const idVec3 *up,
        const usercmd_t *userCmd)
{
  return idGameLocal::GetPlayer(this: gameLocal, i: entityNumber) != nullptr;
}


// ========================================================================
// ?PhysicsHandler_Jump@idPlayer@@CA_NHABVidVec3@@000ABVusercmd_t@@@Z
// EA  : 0x82E24AA8
// RVA : 0x00E24AA8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::PhysicsHandler_Jump(
        unsigned int entityNumber,
        const idVec3 *pos,
        const idVec3 *forward,
        const idVec3 *right,
        const idVec3 *up,
        const usercmd_t *userCmd)
{
  if ( ((unsigned __int8 (__fastcall *)(idCommon *, const idVec3 *, const idVec3 *, const idVec3 *, const idVec3 *, const usercmd_t *))common->IsMultiplayer)(
         a1: common,
         a2: pos,
         a3: forward,
         a4: right,
         a5: up,
         a6: userCmd) == 0 )
    idGameLocal::GetPlayer(this: gameLocal, i: entityNumber);
  return 0;
}


// ========================================================================
// ?AddControl@idPlayer@@QAAXPAVidEntity@@@Z
// EA  : 0x82E24EC0
// RVA : 0x00E24EC0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::AddControl(idPlayer *this, idPlayer *entity)
{
  idPresentable *presentable; // r3
  idPresentable *v5; // r31
  idPresentable *v6; // r3
  idPresentablePlayer *v7; // r3
  idPresentablePlayer *v8; // r4
  idPresentable *v9; // r3

  presentable = this->presentable;
  if ( presentable != nullptr && presentable->GetPlayerInterface_2(this: presentable) != nullptr )
  {
    if ( entity == nullptr || entity == this )
    {
      v9 = this->presentable;
      if ( v9 != nullptr )
        v7 = v9->GetPlayerInterface_2(this: v9);
      else
        v7 = nullptr;
      v8 = nullptr;
    }
    else
    {
      if ( entity->presentable == nullptr )
        idEntity::InitPresentableInternal(this: entity);
      v5 = entity->presentable;
      v6 = this->presentable;
      if ( v6 != nullptr )
        v7 = v6->GetPlayerInterface_2(this: v6);
      else
        v7 = nullptr;
      v8 = (idPresentablePlayer *)v5;
    }
    idPresentablePlayer::AddControl(this: v7, control: v8);
  }
}


// ========================================================================
// ?RemoveControl@idPlayer@@QAAXPAVidEntity@@@Z
// EA  : 0x82E24FA8
// RVA : 0x00E24FA8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::RemoveControl(idPlayer *this, idPlayer *entity)
{
  idPresentable *presentable; // r3
  idPresentable *v5; // r31
  idPresentable *v6; // r3
  idPresentablePlayer *v7; // r3

  presentable = this->presentable;
  if ( presentable != nullptr
    && presentable->GetPlayerInterface_2(this: presentable) != nullptr
    && entity != nullptr
    && entity != this )
  {
    if ( entity->presentable == nullptr )
      idEntity::InitPresentableInternal(this: entity);
    v5 = entity->presentable;
    v6 = this->presentable;
    if ( v6 != nullptr )
      v7 = v6->GetPlayerInterface_2(this: v6);
    else
      v7 = nullptr;
    idPresentablePlayer::RemoveControl(this: v7, control: v5);
  }
}


// ========================================================================
// ?ResetControl@idPlayer@@QAAXXZ
// EA  : 0x82E25060
// RVA : 0x00E25060
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ResetControl(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentable *v3; // r3
  idPresentablePlayer *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr && presentable->GetPlayerInterface_2(this: presentable) != nullptr )
  {
    v3 = this->presentable;
    if ( v3 != nullptr )
      v4 = v3->GetPlayerInterface_2(this: v3);
    else
      v4 = nullptr;
    idPresentablePlayer::ResetControl(this: v4);
  }
}


// ========================================================================
// ?GetControl@idPlayer@@QBAPAVidEntity@@XZ
// EA  : 0x82E250D8
// RVA : 0x00E250D8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idEntity *__fastcall idPlayer::GetControl(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentable *v3; // r3
  idPresentablePlayer *v4; // r3
  idPresentable *v5; // r3
  idPresentablePlayer *v6; // r3

  presentable = this->presentable;
  if ( presentable == nullptr || presentable->GetPlayerInterface_2(this: presentable) == nullptr )
    return nullptr;
  v3 = this->presentable;
  v4 = v3 != nullptr ? v3->GetPlayerInterface_2(this: v3) : nullptr;
  if ( idPresentablePlayer::GetControl(this: v4) == nullptr )
    return nullptr;
  v5 = this->presentable;
  if ( v5 == nullptr )
    return idPresentablePlayer::GetControl(this: nullptr)->entity;
  v6 = v5->GetPlayerInterface_2(this: v5);
  return idPresentablePlayer::GetControl(this: v6)->entity;
}


// ========================================================================
// ?GetPlayerInputSettings@idPlayer@@QAA?AUinputSettings_t@@XZ
// EA  : 0x82E251B0
// RVA : 0x00E251B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::GetPlayerInputSettings(idPlayer *this, idPlayer *result)
{
  idTrailerCamera *v4; // r3
  idEntity *Control; // r3
  idLobbyBase *v6; // r3
  float v7; // r11
  idLobbyBase *v8; // r31
  lobbyUserID_t *v9; // r4
  idLobbyBase_vtbl *v10; // r30
  idPresentablePlayer *LobbyUserID; // r3
  int v12; // r3
  idPlayer_vtbl **v13; // r11
  idPlayer *v14; // r10
  int k; // ctr
  idPlayerProfileGame *v17; // r3
  float *v18; // r31
  idPlayer_vtbl **v19; // r11
  idPlayer *v20; // r10
  int j; // ctr
  idPlayer_vtbl **v22; // r11
  idPlayer *v23; // r10
  int i; // ctr
  float v25; // r3
  idPresentablePlayer *v26; // r3
  char v27; // [sp+50h] [-50h] BYREF
  char v28; // [sp+5Ch] [-44h] BYREF
  char v29; // [sp+60h] [-40h] BYREF
  float v30; // [sp+6Ch] [-34h]
  float v31; // [sp+70h] [-30h]
  float v32; // [sp+74h] [-2Ch]
  bool InvertLook; // [sp+79h] [-27h]

  if ( idPlayer::GetControl(this: result) == nullptr
    || (v4 = (idTrailerCamera *)idPlayer::GetControl(this: result), idTrailerCamera::CastTo(c: v4) != nullptr) )
  {
    v25 = *(float *)&result->presentable;
    if ( v25 == 0.0 )
    {
      idPresentablePlayer::GetPlayerInputSettings((idPresentablePlayer *)this, result: nullptr);
    }
    else
    {
      v26 = (idPresentablePlayer *)(*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v25) + 104))(a1: COERCE_DOUBLE(LODWORD(v25)));
      idPresentablePlayer::GetPlayerInputSettings((idPresentablePlayer *)this, result: v26);
    }
    return this;
  }
  else
  {
    Control = idPlayer::GetControl(this: result);
    Control->GetInputSettings(this: (idEntity *)&v29, result: (inputSettings_t *)Control, a3: result);
    v6 = session->GetActingGameStateLobbyBase(this: session);
    v7 = *(float *)&result->presentable;
    v8 = v6;
    if ( v7 == 0.0 )
      v9 = nullptr;
    else
      v9 = (lobbyUserID_t *)(*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v7) + 104))(a1: COERCE_DOUBLE(LODWORD(v7)));
    v10 = v8->__vftable;
    LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v27, result: v9);
    v12 = (int)v10->GetLocalUserFromLobbyUser(
                 this: (idLobbyBase *)LobbyUserID->__vftable,
                 a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1));
    if ( v12 != 0 )
    {
      v17 = (idPlayerProfileGame *)(*(int (__fastcall **)(int))(*(_DWORD *)v12 + 72))(a1: v12);
      v18 = (float *)v17;
      if ( v17 != nullptr )
      {
        InvertLook = idPlayerProfileGame::GetInvertLook(this: v17);
        v31 = v18[517];
        v30 = v18[518];
        v32 = ((double (__fastcall *)(float *))*(_DWORD *)(*(_DWORD *)v18 + 20))(a1: v18);
        v22 = (idPlayer_vtbl **)&v28;
        v23 = (idPlayer *)((char *)this - 4);
        for ( i = 7; i != 0; --i )
        {
          ++v22;
          v23 = (idPlayer *)((char *)v23 + 4);
          v23->__vftable = *v22;
        }
        return this;
      }
      else
      {
        v19 = (idPlayer_vtbl **)&v28;
        v20 = (idPlayer *)((char *)this - 4);
        for ( j = 7; j != 0; --j )
        {
          ++v19;
          v20 = (idPlayer *)((char *)v20 + 4);
          v20->__vftable = *v19;
        }
        return this;
      }
    }
    else
    {
      v13 = (idPlayer_vtbl **)&v28;
      v14 = (idPlayer *)((char *)this - 4);
      for ( k = 7; k != 0; --k )
      {
        ++v13;
        v14 = (idPlayer *)((char *)v14 + 4);
        v14->__vftable = *v13;
      }
      return this;
    }
  }
}


// ========================================================================
// ?GetLocalUser@idPlayer@@QBAPAVidLocalUser@@XZ
// EA  : 0x82E25398
// RVA : 0x00E25398
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idLocalUser *__fastcall idPlayer::GetLocalUser(idPlayer *this)
{
  return idClientGame::GetLocalUserFromPlayerIndex(this: clientGame, index: this->entityNumber);
}


// ========================================================================
// ?PrepareForNextMap@idPlayer@@QAAXABVidColor@@0M@Z
// EA  : 0x82E253A8
// RVA : 0x00E253A8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::PrepareForNextMap(idPlayer *this, const idColor *fadeColor, const idVec4 *fadeTo, double to)
{
  idPresentable *presentable; // r3
  float *v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  idEntity *Control; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v9 = (float *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v9 = nullptr;
  v9[4767] = fadeColor->r;
  v9[4768] = fadeColor->g;
  v9[4769] = fadeColor->b;
  v9[4770] = fadeColor->a;
  v10 = this->presentable;
  if ( v10 != nullptr )
    v11 = (int)v10->GetPlayerInterface_2(this: v10);
  else
    v11 = 0;
  idView::Fade(this: (idView *)(v11 + 16224), color: fadeTo, time: (int)to);
  v12 = this->presentable;
  if ( v12 != nullptr )
    v13 = (int)v12->GetPlayerInterface_2(this: v12);
  else
    v13 = 0;
  idPlayerHud::SetHudState(this: (idPlayerHud *)(v13 + 35096), state: HUDSTATE_NONE);
  *((_BYTE *)this + 12824) |= 4u;
  idPlayer::SetForceInhibitControl(this, inhibit: true);
  *(_BYTE *)&this->flags &= ~2u;
  if ( idPlayer::GetControl(this) != nullptr )
  {
    Control = idPlayer::GetControl(this);
    *(_BYTE *)&Control->flags &= ~2u;
  }
}


// ========================================================================
// ?Event_PostSpawn@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E254D8
// RVA : 0x00E254D8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_PostSpawn(idPlayer *this, idEntity *result, int a3, int a4, __int64 a5)
{
  __int64 v7; // r10
  idPlayerStart *SpawnSpot; // r3

  LODWORD(v7) = &gameLocal->gameSpawnInfo.spawnSpotOverride;
  HIDWORD(v7) = gameLocal->gameSpawnInfo.spawnSpotOverride.len;
  if ( HIDWORD(v7) == 0 )
    LODWORD(v7) = &gameLocal->gameSpawnInfo.spawnSpot;
  SpawnSpot = idGameLocal::FindSpawnSpot(
                this: gameLocal,
                spawnspot: *(const char **)(v7 + 4),
                playerNum: result->entityNumber,
                a4,
                a5,
                a6: v7);
  SpawnSpot->ActivateTargets(this: SpawnSpot, a2: result);
  return this;
}


// ========================================================================
// ?DisplayStats@idPlayer@@QAAXXZ
// EA  : 0x82E25558
// RVA : 0x00E25558
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPlayer::DisplayStats(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  const idColor *v4; // r4
  int v5; // r26
  idDebugHUD_vtbl *v6; // r26
  int v7; // r3
  __int64 v8; // r10
  int StatInt; // r3
  idStr *v10; // r25
  idStr *v11; // r3
  idDebugHUD_vtbl *v12; // r25
  profileStatValue_t v13; // r24
  int v14; // r3
  idDebugHUD_vtbl *v15; // r25
  profileStatValue_t v16; // r24
  int v17; // r3
  profileStatValue_t v18; // r24
  idDebugHUD_vtbl *v19; // r25
  int v20; // r3
  __int64 v21; // r10
  __int64 v22; // r10
  __int64 v23; // r10
  __int64 v24; // r10
  __int64 v25; // r10
  profileStatValue_t v26; // r24
  int v27; // r26
  idRageMetrics *rageMetrics; // r23
  idDebugHUD_vtbl *v29; // r25
  profileStatValue_t v30; // r20
  profileStatValue_t v31; // r19
  profileStatValue_t v32; // r18
  int v33; // r14
  int v34; // r3
  __int64 v35; // r9 OVERLAPPED
  int v36; // r3
  int v37; // r10
  double v38; // fp2
  __int64 v39; // r11
  idRageMetrics *v40; // r25
  idDebugHUD_vtbl *v41; // r26
  profileStatValue_t v42; // r24
  profileStatValue_t v43; // r23
  profileStatValue_t v44; // r22
  int v45; // r21
  int v46; // r20
  int v47; // r3
  idDebugHUD_vtbl *v48; // r26
  profileStatValue_t v49; // r25
  int v50; // r3
  idDebugHUD_vtbl *v51; // r26
  profileStatValue_t v52; // r25
  int v53; // r3
  profileStatValue_t v54; // r25
  idRageMetrics *v55; // r23
  profileStatValue_t v56; // r24
  idDebugHUD_vtbl *v57; // r26
  int v58; // r22
  int v59; // r3
  idRageMetrics *v60; // r25
  idDebugHUD_vtbl *v61; // r26
  profileStatValue_t v62; // r24
  profileStatValue_t v63; // r23
  int v64; // r22
  int v65; // r3
  idRageMetrics *v66; // r25
  idDebugHUD_vtbl *v67; // r26
  profileStatValue_t v68; // r24
  profileStatValue_t v69; // r23
  int v70; // r22
  int v71; // r3
  profileStatValue_t v72; // r25
  idDebugHUD_vtbl *v73; // r26
  int v74; // r3
  idDebugHUD_vtbl *v75; // r26
  profileStatValue_t v76; // r25
  int v77; // r3
  idDebugHUD_vtbl *v78; // r26
  profileStatValue_t v79; // r25
  int v80; // r3
  idDebugHUD_vtbl *v81; // r26
  profileStatValue_t v82; // r25
  int v83; // r3
  idDebugHUD_vtbl *v84; // r26
  profileStatValue_t v85; // r25
  int v86; // r3
  idRageMetrics *v87; // r22
  profileStatValue_t v88; // r25
  profileStatValue_t v89; // r24
  profileStatValue_t v90; // r23
  idDebugHUD_vtbl *v91; // r26
  int v92; // r21
  int v93; // r20
  int v94; // r3
  idDebugHUD_vtbl *v95; // r26
  profileStatValue_t v96; // r25
  int v97; // r3
  idDebugHUD_vtbl *v98; // r26
  profileStatValue_t v99; // r25
  int v100; // r3
  idDebugHUD_vtbl *v101; // r26
  profileStatValue_t v102; // r25
  int v103; // r3
  profileStatValue_t v104; // r24
  int v105; // r3
  profileStatValue_t v106; // r23
  __int64 v107; // r26
  __int64 v108; // r10
  double v109; // fp2
  double v110; // fp1
  profileStatValue_t v111; // r25
  idDebugHUD_vtbl *v112; // r26
  int v113; // r3
  double f; // fp29
  idDebugHUD_vtbl *v115; // r25
  double StatFloat; // fp1
  idDebugHUD_vtbl *v117; // r25
  idDebugHUD_vtbl *v118; // r25
  int v119; // r3
  idStr *v120; // r25
  idStr *v121; // r3
  double v122; // [sp+20h] [-300h]
  double v123; // [sp+20h] [-300h]
  double v124; // [sp+28h] [-2F8h]
  double v125; // [sp+28h] [-2F8h]
  int v126; // [sp+70h] [-2B0h]
  __int64 v127; // [sp+74h] [-2ACh] BYREF
  int v128; // [sp+7Ch] [-2A4h]
  idColor *v129; // [sp+80h] [-2A0h]
  const char *v130; // [sp+84h] [-29Ch]
  const char *v131; // [sp+88h] [-298h]
  const char *v132; // [sp+8Ch] [-294h]
  const char *v133; // [sp+90h] [-290h]
  const char *v134; // [sp+94h] [-28Ch]
  const char *v135; // [sp+98h] [-288h]
  const char *v136; // [sp+9Ch] [-284h]
  const char *v137; // [sp+A0h] [-280h]
  const char *v138; // [sp+A4h] [-27Ch]
  const char *v139; // [sp+A8h] [-278h]
  const char *v140; // [sp+ACh] [-274h]
  const char *v141; // [sp+B0h] [-270h]
  const char *v142; // [sp+B4h] [-26Ch]
  const char *v143; // [sp+B8h] [-268h]
  const char *v144; // [sp+BCh] [-264h]
  const char *v145; // [sp+C0h] [-260h]
  const char *v146; // [sp+C4h] [-25Ch]
  const char *v147; // [sp+C8h] [-258h]
  const char *v148; // [sp+CCh] [-254h]
  const char *v149; // [sp+D0h] [-250h]
  const char *v150; // [sp+D4h] [-24Ch]
  const char *v151; // [sp+D8h] [-248h]
  const char *v152; // [sp+DCh] [-244h]
  const char *v153; // [sp+E0h] [-240h]
  const char *v154; // [sp+E4h] [-23Ch]
  const char *v155; // [sp+E8h] [-238h]
  const char *v156; // [sp+ECh] [-234h]
  const char *v157; // [sp+F0h] [-230h]
  const char *v158; // [sp+F4h] [-22Ch]
  const char *v159; // [sp+F8h] [-228h]
  const char *v160; // [sp+FCh] [-224h]
  const char *v161; // [sp+100h] [-220h]
  const char *v162; // [sp+104h] [-21Ch]
  const char *v163; // [sp+108h] [-218h]
  const char *v164; // [sp+10Ch] [-214h]
  const char *v165; // [sp+110h] [-210h]
  _DWORD v166[2]; // [sp+118h] [-208h] BYREF
  _DWORD v167[2]; // [sp+120h] [-200h] BYREF
  __int64 v168; // [sp+128h] [-1F8h]
  __int64 v169; // [sp+130h] [-1F0h]
  unsigned __int64 v170; // [sp+138h] [-1E8h]
  __int64 v171; // [sp+140h] [-1E0h]
  __int64 v172; // [sp+148h] [-1D8h]
  __int64 v173; // [sp+150h] [-1D0h]
  __int64 v174; // [sp+158h] [-1C8h]
  unsigned __int64 v175; // [sp+160h] [-1C0h]
  __int64 v176; // [sp+168h] [-1B8h]
  unsigned __int64 v177; // [sp+170h] [-1B0h]
  __int64 v178; // [sp+178h] [-1A8h]
  unsigned __int64 v179; // [sp+180h] [-1A0h]
  __int64 v180; // [sp+188h] [-198h]
  __int64 v181; // [sp+190h] [-190h]
  unsigned __int64 v182; // [sp+198h] [-188h]
  unsigned __int64 v183; // [sp+1A0h] [-180h]
  __int64 v184; // [sp+1A8h] [-178h]
  unsigned __int64 v185; // [sp+1B0h] [-170h]
  __int64 v186; // [sp+1B8h] [-168h]
  __int64 v187; // [sp+1C0h] [-160h]
  idColor v188[2]; // [sp+1D0h] [-150h] BYREF
  idStr v189; // [sp+1F0h] [-130h] BYREF
  idStr v190; // [sp+210h] [-110h] BYREF
  idStr v191; // [sp+230h] [-F0h] BYREF
  idStr v192; // [sp+250h] [-D0h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v3 + 300))(a1: v3) != 0 )
  {
    v127 = 0;
    v188[0] = idColor::colorBlack;
    v188[1] = idColor::colorWhite;
    v167[0] = 41;
    v167[1] = 40;
    v166[0] = 11;
    v166[1] = 10;
    cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_debugHUD", a3: 1, a4: 0);
    debugHUD->Clear(this: debugHUD, a2: false);
    debugHUD->SetTextScale(this: debugHUD, a2: 0.75);
    v128 = 0;
    v138 = "Vehicle Time in Air: %s-%s\n";
    v129 = v188;
    v136 = "Miles Driven in Air: %.0f-%.0f\n";
    v160 = "Kills: (b:%d-%d/m:%d-%d/a:%d-%d)\n";
    v134 = "Miles Driven on Two Wheels: %.0f-%.0f\n";
    v132 = "Miles Driven: %.2f-%.2f\n";
    v153 = "Vehicle Shots: %d-%d\n";
    v131 = "Vehicle Damage Dealt: %d-%d\n";
    v155 = "Vehicle Accuracy: %.1f%%-%.1f%%\n";
    v149 = "Roadkills: %d-%d\n";
    v147 = "Total Vehicle Kills: %d-%d\n";
    v141 = "Damage Taken: %d-%d\n";
    v130 = "Vehicle Suicides: %d-%d\n";
    v145 = "Vehicle Kills by Class: (1:%d-%d  2:%d-%d  3:%d-%d)\n";
    v143 = "Vehicle Deaths: %d-%d\n";
    v144 = "Hit Accuracy: %.1f%%/%.1f%%\n";
    v152 = "Jetpacker Kills: %d-%d\n";
    v158 = "Stealth crossbow: %d-%d\n";
    v148 = "Turret Kills: %d-%d, max single kill: %d-%d\n";
    v140 = "Kills with Engineered Items: %d-%d\n";
    v150 = "Mindcontrolled Kills: %d-%d, max single kill: %d-%d\n";
    v164 = "Sentrybot Kills: %d-%d, max single kill: %d-%d\n";
    v146 = "Headshot Kills: %d-%d\n";
    v142 = "Hits: (enemy:%d-%d friend:%d-%d obj:%d-%d direct:%d-%d break:%d-%d)\n";
    v162 = "Shots: %d-%d\n";
    v156 = "Headshot Sniper Kills: %d-%d\n";
    v4 = v188;
    v5 = 0;
    v135 = "Items Looted: %d-%d\n";
    v133 = "Cash SP: %d-%d\n";
    v165 = "Odd Jobs: %d/%d, %.0f%%\n";
    v139 = "Field Goals Made: %d/%d, %.0f%%\n";
    v163 = "Recipes Collected: %d/%d, %.0f%%\n";
    v137 = "Playing Cards Collected: %d/%d, %.0f%%\n";
    v161 = "Jumps Reached: %d/%d, %.0f%%\n";
    v159 = "Items Engineered: %d-%d\n";
    v157 = "Time Played: %s - %s\n";
    v151 = "Overall Progress: %d/%d, %.0f%%\n";
    v154 = "Game Difficulty: %i\n";
    do
    {
      debugHUD->SetTextColor(this: debugHUD, a2: v4);
      debugHUD->SetTextPosition(
        this: debugHUD,
        a2: *(_DWORD *)((char *)v167 + v5) + 5,
        a3: *(_DWORD *)((char *)v166 + v5) + 5);
      v6 = debugHUD->__vftable;
      v7 = gameLocal->GetGameDifficulty(this: gameLocal);
      v6->Printf(this: debugHUD, a2: v154, v7);
      idAchievementManager::GetAchievementCompletionPercent(
        this: &this->achievementManager,
        id: GAME_ACHIEVEMENT_44,
        gained: (int *)&v127,
        required: (int *)&v127 + 1,
        isFulfilled: nullptr);
      if ( (int)v127 > 0 )
      {
        LODWORD(v8) = HIDWORD(v127);
        v181 = v8;
        v184 = v127;
      }
      debugHUD->Printf(this: debugHUD, a2: v151);
      StatInt = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 156);
      v10 = Sys_SecToStr(result: &v189, sec: StatInt);
      v11 = Sys_SecToStr(result: &v191, sec: this->stats[156].i);
      debugHUD->Printf(this: debugHUD, a2: v157, v11->data, v10->data);
      idStr::FreeData(this: &v191);
      idStr::FreeData(this: &v189);
      v12 = debugHUD->__vftable;
      v13.i = (int)this->stats[255];
      v14 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 255);
      v12->Printf(this: debugHUD, a2: v133, (profileStatValue_t *)v13.i, v14);
      v15 = debugHUD->__vftable;
      v16.i = (int)this->stats[240];
      v17 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 240);
      v15->Printf(this: debugHUD, a2: v159, (profileStatValue_t *)v16.i, v17);
      v18.i = (int)this->stats[160];
      v19 = debugHUD->__vftable;
      v20 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 160);
      v19->Printf(this: debugHUD, a2: v135, (profileStatValue_t *)v18.i, v20);
      idAchievementManager::GetAchievementCompletionPercent(
        this: &this->achievementManager,
        id: GAME_ACHIEVEMENT_12,
        gained: (int *)&v127,
        required: (int *)&v127 + 1,
        isFulfilled: nullptr);
      if ( (int)v127 > 0 )
      {
        LODWORD(v21) = v127;
        v171 = v21;
        v185 = __PAIR64__(v127, HIDWORD(v127));
      }
      debugHUD->Printf(this: debugHUD, a2: v161);
      idAchievementManager::GetAchievementCompletionPercent(
        this: &this->achievementManager,
        id: GAME_ACHIEVEMENT_13,
        gained: (int *)&v127,
        required: (int *)&v127 + 1,
        isFulfilled: nullptr);
      if ( (int)v127 > 0 )
      {
        LODWORD(v22) = v127;
        v183 = __PAIR64__(v127, HIDWORD(v127));
        v173 = v22;
      }
      debugHUD->Printf(this: debugHUD, a2: v137);
      idAchievementManager::GetAchievementCompletionPercent(
        this: &this->achievementManager,
        id: GAME_ACHIEVEMENT_14,
        gained: (int *)&v127,
        required: (int *)&v127 + 1,
        isFulfilled: nullptr);
      if ( (int)v127 > 0 )
      {
        LODWORD(v23) = v127;
        v175 = __PAIR64__(v127, HIDWORD(v127));
        v187 = v23;
      }
      debugHUD->Printf(this: debugHUD, a2: v163);
      idAchievementManager::GetAchievementCompletionPercent(
        this: &this->achievementManager,
        id: GAME_ACHIEVEMENT_23,
        gained: (int *)&v127,
        required: (int *)&v127 + 1,
        isFulfilled: nullptr);
      if ( (int)v127 > 0 )
      {
        LODWORD(v24) = v127;
        v177 = __PAIR64__(v127, HIDWORD(v127));
        v186 = v24;
      }
      debugHUD->Printf(this: debugHUD, a2: v139);
      idAchievementManager::GetAchievementCompletionPercent(
        this: &this->achievementManager,
        id: GAME_ACHIEVEMENT_38,
        gained: (int *)&v127,
        required: (int *)&v127 + 1,
        isFulfilled: nullptr);
      if ( (int)v127 > 0 )
      {
        LODWORD(v25) = v127;
        v179 = __PAIR64__(v127, HIDWORD(v127));
        v168 = v25;
      }
      debugHUD->Printf(this: debugHUD, a2: v165);
      v26.i = (int)this->stats[159];
      v27 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 159);
      debugHUD->Printf(this: debugHUD, a2: v162, v26.i, v27);
      v29 = debugHUD->__vftable;
      v30.i = (int)this->stats[164];
      rageMetrics = clientGame->rageMetrics;
      v31.i = (int)this->stats[163];
      v32.i = (int)this->stats[162];
      idRageMetrics::GetStatInt(this: rageMetrics, player: this, stat: 166);
      idRageMetrics::GetStatInt(this: rageMetrics, player: this, stat: 165);
      v33 = idRageMetrics::GetStatInt(this: rageMetrics, player: this, stat: 164);
      v126 = idRageMetrics::GetStatInt(this: rageMetrics, player: this, stat: 163);
      v34 = idRageMetrics::GetStatInt(this: rageMetrics, player: this, stat: 162);
      v29->Printf(
        this: debugHUD,
        a2: v142,
        (profileStatValue_t *)v32.i,
        v34,
        (profileStatValue_t *)v31.i,
        v126,
        (profileStatValue_t *)v30.i,
        v33);
      if ( v27 <= 0 )
      {
        v38 = 0.0;
      }
      else
      {
        v36 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 167);
        v37 = v27;
        v169 = *(__int64 *)((char *)&v35 - 4);
        v170 = __PAIR64__(v27, v36);
        v38 = (float)((float)((float)__SPAIR64__(v27, v36) / (float)*(__int64 *)((char *)&v35 - 4)) * (float)100.0);
      }
      if ( v26.i > 0 )
      {
        HIDWORD(v39) = this->stats[167].i;
        LODWORD(v39) = v26;
        LODWORD(v35) = HIDWORD(v39);
        v174 = v39;
        v172 = v35;
      }
      debugHUD->Printf(this: debugHUD, a2: v144, HIDWORD(v38), LODWORD(v38));
      v41 = debugHUD->__vftable;
      v42.i = (int)this->stats[149];
      v43.i = (int)this->stats[148];
      v44.i = (int)this->stats[147];
      v40 = clientGame->rageMetrics;
      v45 = idRageMetrics::GetStatInt(this: v40, player: this, stat: 149);
      v46 = idRageMetrics::GetStatInt(this: v40, player: this, stat: 148);
      v47 = idRageMetrics::GetStatInt(this: v40, player: this, stat: 147);
      v41->Printf(
        this: debugHUD,
        a2: v160,
        (profileStatValue_t *)v44.i,
        v47,
        (profileStatValue_t *)v43.i,
        v46,
        (profileStatValue_t *)v42.i,
        v45);
      v48 = debugHUD->__vftable;
      v49.i = (int)this->stats[145];
      v50 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 145);
      v48->Printf(this: debugHUD, a2: v146, (profileStatValue_t *)v49.i, v50);
      v51 = debugHUD->__vftable;
      v52.i = (int)this->stats[146];
      v53 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 146);
      v51->Printf(this: debugHUD, a2: v156, (profileStatValue_t *)v52.i, v53);
      v54.i = (int)this->stats[246];
      v56.i = (int)this->stats[245];
      v57 = debugHUD->__vftable;
      v55 = clientGame->rageMetrics;
      v58 = idRageMetrics::GetStatInt(this: v55, player: this, stat: 246);
      v59 = idRageMetrics::GetStatInt(this: v55, player: this, stat: 245);
      v57->Printf(this: debugHUD, a2: v148, (profileStatValue_t *)v56.i, v59, (profileStatValue_t *)v54.i, v58);
      v61 = debugHUD->__vftable;
      v62.i = (int)this->stats[244];
      v63.i = (int)this->stats[243];
      v60 = clientGame->rageMetrics;
      v64 = idRageMetrics::GetStatInt(this: v60, player: this, stat: 244);
      v65 = idRageMetrics::GetStatInt(this: v60, player: this, stat: 243);
      v61->Printf(this: debugHUD, a2: v164, (profileStatValue_t *)v63.i, v65, (profileStatValue_t *)v62.i, v64);
      v67 = debugHUD->__vftable;
      v68.i = (int)this->stats[248];
      v69.i = (int)this->stats[247];
      v66 = clientGame->rageMetrics;
      v70 = idRageMetrics::GetStatInt(this: v66, player: this, stat: 248);
      v71 = idRageMetrics::GetStatInt(this: v66, player: this, stat: 247);
      v67->Printf(this: debugHUD, a2: v150, (profileStatValue_t *)v69.i, v71, (profileStatValue_t *)v68.i, v70);
      v72.i = (int)this->stats[242];
      v73 = debugHUD->__vftable;
      v74 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 242);
      v73->Printf(this: debugHUD, a2: v158, (profileStatValue_t *)v72.i, v74);
      v75 = debugHUD->__vftable;
      v76.i = (int)this->stats[253];
      v77 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 253);
      v75->Printf(this: debugHUD, a2: v152, (profileStatValue_t *)v76.i, v77);
      v78 = debugHUD->__vftable;
      v79.i = (int)this->stats[241];
      v80 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 241);
      v78->Printf(this: debugHUD, a2: v140, (profileStatValue_t *)v79.i, v80);
      v81 = debugHUD->__vftable;
      v82.i = (int)this->stats[161];
      v83 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 161);
      v81->Printf(this: debugHUD, a2: v141, (profileStatValue_t *)v82.i, v83);
      v84 = debugHUD->__vftable;
      v85.i = (int)this->stats[1];
      v86 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 1);
      v84->Printf(this: debugHUD, a2: v143, (profileStatValue_t *)v85.i, v86);
      v88.i = (int)this->stats[152];
      v89.i = (int)this->stats[151];
      v90.i = (int)this->stats[150];
      v91 = debugHUD->__vftable;
      v87 = clientGame->rageMetrics;
      v92 = idRageMetrics::GetStatInt(this: v87, player: this, stat: 152);
      v93 = idRageMetrics::GetStatInt(this: v87, player: this, stat: 151);
      v94 = idRageMetrics::GetStatInt(this: v87, player: this, stat: 150);
      v91->Printf(
        this: debugHUD,
        a2: v145,
        (profileStatValue_t *)v90.i,
        v94,
        (profileStatValue_t *)v89.i,
        v93,
        (profileStatValue_t *)v88.i,
        v92);
      v95 = debugHUD->__vftable;
      v96.i = (int)this->stats[0];
      v97 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 0);
      v95->Printf(this: debugHUD, a2: v147, (profileStatValue_t *)v96.i, v97);
      v98 = debugHUD->__vftable;
      v99.i = (int)this->stats[40];
      v100 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 40);
      v98->Printf(this: debugHUD, a2: v149, (profileStatValue_t *)v99.i, v100);
      v101 = debugHUD->__vftable;
      v102.i = (int)this->stats[2];
      v103 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 2);
      v101->Printf(this: debugHUD, a2: v130, (profileStatValue_t *)v102.i, v103);
      v104.i = (int)this->stats[7];
      v105 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 7);
      v106.i = (int)this->stats[8];
      LODWORD(v107) = v105;
      HIDWORD(v107) = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 8);
      debugHUD->Printf(this: debugHUD, a2: v153, v104.i, v107);
      debugHUD->Printf(this: debugHUD, a2: "Vehicle Hits: %d-%d\n", v106.i, HIDWORD(v107));
      if ( (int)v107 <= 0 )
      {
        v109 = 0.0;
      }
      else
      {
        LODWORD(v108) = HIDWORD(v107);
        v176 = v108;
        v178 = v107;
        v109 = (float)((float)((float)v108 / (float)v107) * (float)100.0);
      }
      if ( v104.i <= 0 )
      {
        v110 = 0.0;
      }
      else
      {
        LODWORD(v108) = v104;
        v182 = __PAIR64__(v104.i, v106.i);
        v180 = v108;
        v110 = (float)((float)((float)__SPAIR64__(v104.i, v106.i) / (float)v108) * (float)100.0);
      }
      debugHUD->Printf(this: debugHUD, a2: (const char *)HIDWORD(v110), LODWORD(v110), LODWORD(v109));
      v111.i = (int)this->stats[9];
      v112 = debugHUD->__vftable;
      v113 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 9);
      v112->Printf(this: debugHUD, a2: v131, (profileStatValue_t *)v111.i, v113);
      f = this->stats[12].f;
      v115 = debugHUD->__vftable;
      StatFloat = idRageMetrics::GetStatFloat(this: clientGame->rageMetrics, player: this, stat: 12);
      v115->Printf(
        this: debugHUD,
        a2: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64((float)((float)f * (float)0.000015782829))),
        COERCE_UNSIGNED_INT64((float)((float)f * (float)0.000015782829)),
        COERCE_UNSIGNED_INT64((float)((float)StatFloat * (float)0.000015782829)));
      v117 = debugHUD->__vftable;
      v122 = (float)(this->stats[14].f * (float)0.000015782829);
      v124 = (float)(idRageMetrics::GetStatFloat(this: clientGame->rageMetrics, player: this, stat: 14) * 0.000015782829);
      v117->Printf(this: debugHUD, a2: v134, LODWORD(v122), LODWORD(v124));
      v118 = debugHUD->__vftable;
      v123 = (float)(this->stats[15].f * (float)0.000015782829);
      v125 = (float)(idRageMetrics::GetStatFloat(this: clientGame->rageMetrics, player: this, stat: 15) * 0.000015782829);
      v118->Printf(this: debugHUD, a2: v136, LODWORD(v123), LODWORD(v125));
      v119 = idRageMetrics::GetStatInt(this: clientGame->rageMetrics, player: this, stat: 16);
      v120 = Sys_SecToStr(result: &v192, sec: v119 / 1000);
      v121 = Sys_SecToStr(result: &v190, sec: this->stats[16].i / 1000);
      debugHUD->Printf(this: debugHUD, a2: v138, v121->data, v120->data);
      idStr::FreeData(this: &v190);
      idStr::FreeData(this: &v192);
      v5 = v128 + 4;
      v4 = ++v129;
      v128 = v5;
    }
    while ( v5 < 8 );
  }
}


// ========================================================================
// __unwind$502749
// EA  : 0x82E266A4
// RVA : 0x00E266A4
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_502749()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 800 + 496));
}


// ========================================================================
// __unwind$502750
// EA  : 0x82E266CC
// RVA : 0x00E266CC
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_502750()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 800 + 560));
}


// ========================================================================
// __unwind$502751
// EA  : 0x82E266F4
// RVA : 0x00E266F4
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_502751()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 800 + 592));
}


// ========================================================================
// __unwind$502752
// EA  : 0x82E2671C
// RVA : 0x00E2671C
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_502752()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 800 + 528));
}


// ========================================================================
// ?DisplayStatsMP_VDM@idPlayer@@QAAXXZ
// EA  : 0x82E26748
// RVA : 0x00E26748
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::DisplayStatsMP_VDM(idPlayer *this)
{
  int v2; // r27
  void (__fastcall *SetCVarInteger)(idCVarSystem *, const char *, const int, int); // r9
  const idColor *v4; // r26
  idRageMetrics *rageMetrics; // r15
  int entityNumber; // r14
  idDebugHUD_vtbl *v7; // r25
  int SessionStat; // r3
  idRageMetrics *v9; // r15
  int v10; // r14
  idDebugHUD_vtbl *v11; // r25
  int v12; // r3
  idRageMetrics *v13; // r15
  int v14; // r14
  idDebugHUD_vtbl *v15; // r25
  int v16; // r3
  idRageMetrics *v17; // r15
  idDebugHUD_vtbl *v18; // r25
  int v19; // r14
  idRageMetrics *v20; // r15
  idDebugHUD_vtbl *v21; // r25
  int v22; // r14
  int v23; // r3
  idRageMetrics *v24; // r15
  idDebugHUD_vtbl *v25; // r25
  int v26; // r14
  int v27; // r3
  int v28; // r15
  idRageMetrics *v29; // r14
  idDebugHUD_vtbl *v30; // r25
  int v31; // r3
  idRageMetrics *v32; // r15
  int v33; // r14
  idDebugHUD_vtbl *v34; // r25
  int v35; // r3
  idRageMetrics *v36; // r15
  int v37; // r14
  idDebugHUD_vtbl *v38; // r25
  int v39; // r3
  idRageMetrics *v40; // r15
  int v41; // r14
  idDebugHUD_vtbl *v42; // r25
  int v43; // r3
  idRageMetrics *v44; // r15
  idDebugHUD_vtbl *v45; // r25
  int v46; // r14
  int v47; // r3
  idRageMetrics *v48; // r15
  idDebugHUD_vtbl *v49; // r25
  int v50; // r14
  int v51; // r3
  idRageMetrics *v52; // r15
  idDebugHUD_vtbl *v53; // r25
  int v54; // r14
  int v55; // r3
  idRageMetrics *v56; // r14
  int v57; // r15
  idDebugHUD_vtbl *v58; // r25
  int v59; // r3
  idRageMetrics *v60; // r15
  int v61; // r14
  idDebugHUD_vtbl *v62; // r25
  int v63; // r3
  idRageMetrics *v64; // r15
  idDebugHUD_vtbl *v65; // r25
  int v66; // r14
  int v67; // r3
  idRageMetrics *v68; // r15
  int v69; // r14
  idDebugHUD_vtbl *v70; // r25
  int v71; // r3
  idRageMetrics *v72; // r15
  idDebugHUD_vtbl *v73; // r25
  int v74; // r14
  int v75; // r3
  idRageMetrics *v76; // r15
  idDebugHUD_vtbl *v77; // r25
  int v78; // r14
  int v79; // r3
  double SessionStatFloat; // [sp+20h] [-130h]
  double StatFloat; // [sp+28h] [-128h]
  int StatInt; // [sp+50h] [-100h]
  int v83; // [sp+50h] [-100h]
  int v84; // [sp+50h] [-100h]
  int v85; // [sp+50h] [-100h]
  int v86; // [sp+50h] [-100h]
  int v87; // [sp+50h] [-100h]
  int v88; // [sp+50h] [-100h]
  int v89; // [sp+50h] [-100h]
  int v90; // [sp+50h] [-100h]
  int v91; // [sp+50h] [-100h]
  int v92; // [sp+50h] [-100h]
  int v93; // [sp+50h] [-100h]
  int v94; // [sp+50h] [-100h]
  int v95; // [sp+50h] [-100h]
  int v96; // [sp+50h] [-100h]
  int v97; // [sp+50h] [-100h]
  int v98; // [sp+50h] [-100h]
  int v99; // [sp+50h] [-100h]
  _DWORD v100[2]; // [sp+80h] [-D0h] BYREF
  _DWORD v101[2]; // [sp+88h] [-C8h] BYREF
  idColor v102[2]; // [sp+90h] [-C0h] BYREF

  v2 = 0;
  v102[1] = idColor::colorWhite;
  v102[0] = idColor::colorBlack;
  SetCVarInteger = cvarSystem->SetCVarInteger;
  v101[1] = 0;
  v100[1] = 0;
  v101[0] = 1;
  v100[0] = 1;
  SetCVarInteger(this: cvarSystem, a2: "com_debugHUD", a3: 1, a4: 0);
  debugHUD->Clear(this: debugHUD, a2: false);
  debugHUD->SetTextScale(this: debugHUD, a2: 0.75);
  v4 = v102;
  do
  {
    debugHUD->SetTextColor(this: debugHUD, a2: v4);
    debugHUD->SetTextPosition(this: debugHUD, a2: v101[v2] + 5, a3: v100[v2] + 5);
    rageMetrics = clientGame->rageMetrics;
    entityNumber = this->entityNumber;
    v7 = debugHUD->__vftable;
    StatInt = idRageMetrics::GetStatInt(this: rageMetrics, player: this, stat: 32);
    SessionStat = idRageMetrics::GetSessionStat(this: rageMetrics, playerId: entityNumber, stat: RAGE_STAT_MP_LEVEL);
    v7->Printf(this: debugHUD, a2: "level: %d %d\n", SessionStat, StatInt);
    v9 = clientGame->rageMetrics;
    v10 = this->entityNumber;
    v11 = debugHUD->__vftable;
    v83 = idRageMetrics::GetStatInt(this: v9, player: this, stat: 23);
    v12 = idRageMetrics::GetSessionStat(this: v9, playerId: v10, stat: RAGE_STAT_MP_XP);
    v11->Printf(this: debugHUD, a2: "xp: %d %d\n", v12, v83);
    v13 = clientGame->rageMetrics;
    v14 = this->entityNumber;
    v15 = debugHUD->__vftable;
    v84 = idRageMetrics::GetStatInt(this: v13, player: this, stat: 35);
    v16 = idRageMetrics::GetSessionStat(this: v13, playerId: v14, stat: RAGE_STAT_SCORE_VDM);
    v15->Printf(this: debugHUD, a2: "score: %d %d\n\n", v16, v84);
    v17 = clientGame->rageMetrics;
    v18 = debugHUD->__vftable;
    v19 = this->entityNumber;
    StatFloat = idRageMetrics::GetStatFloat(this: v17, player: this, stat: 13);
    SessionStatFloat = idRageMetrics::GetSessionStatFloat(
                         this: v17,
                         playerId: v19,
                         stat: RAGE_STAT_VEHICLE_ODOMETER_ON_GROUND);
    v18->Printf(this: debugHUD, a2: "odo ground: %.0f %.0f\n\n", LODWORD(SessionStatFloat), LODWORD(StatFloat));
    v20 = clientGame->rageMetrics;
    v21 = debugHUD->__vftable;
    v22 = this->entityNumber;
    v85 = idRageMetrics::GetStatInt(this: v20, player: this, stat: 0);
    v23 = idRageMetrics::GetSessionStat(this: v20, playerId: v22, stat: RAGE_STAT_VEHICLE_KILLS);
    v21->Printf(this: debugHUD, a2: "Kills: %d %d\n", v23, v85);
    v24 = clientGame->rageMetrics;
    v25 = debugHUD->__vftable;
    v26 = this->entityNumber;
    v86 = idRageMetrics::GetStatInt(this: v24, player: this, stat: 102);
    v27 = idRageMetrics::GetSessionStat(this: v24, playerId: v26, stat: RAGE_STAT_REVENGE_KILLS);
    v25->Printf(this: debugHUD, a2: "Rally Caps: %d %d\n", v27, v86);
    v28 = this->entityNumber;
    v29 = clientGame->rageMetrics;
    v30 = debugHUD->__vftable;
    v87 = idRageMetrics::GetStatInt(this: v29, player: this, stat: 41);
    v31 = idRageMetrics::GetSessionStat(this: v29, playerId: v28, stat: RAGE_STAT_VEHICLE_RALLY_CAPTURES);
    v30->Printf(this: debugHUD, a2: "Chain owner kills: %d %d\n", v31, v87);
    v32 = clientGame->rageMetrics;
    v33 = this->entityNumber;
    v34 = debugHUD->__vftable;
    v88 = idRageMetrics::GetStatInt(this: v32, player: this, stat: 102);
    v35 = idRageMetrics::GetSessionStat(this: v32, playerId: v33, stat: RAGE_STAT_REVENGE_KILLS);
    v34->Printf(this: debugHUD, a2: "Revenge: %d %d\n", v35, v88);
    v36 = clientGame->rageMetrics;
    v37 = this->entityNumber;
    v38 = debugHUD->__vftable;
    v89 = idRageMetrics::GetStatInt(this: v36, player: this, stat: 99);
    v39 = idRageMetrics::GetSessionStat(this: v36, playerId: v37, stat: RAGE_STAT_AERIAL_KILLS);
    v38->Printf(this: debugHUD, a2: "Air Mail: %d %d\n", v39, v89);
    v40 = clientGame->rageMetrics;
    v41 = this->entityNumber;
    v42 = debugHUD->__vftable;
    v90 = idRageMetrics::GetStatInt(this: v40, player: this, stat: 98);
    v43 = idRageMetrics::GetSessionStat(this: v40, playerId: v41, stat: RAGE_STAT_AIR_KILLS);
    v42->Printf(this: debugHUD, a2: "Pull: %d %d\n", v43, v90);
    v44 = clientGame->rageMetrics;
    v45 = debugHUD->__vftable;
    v46 = this->entityNumber;
    v91 = idRageMetrics::GetStatInt(this: v44, player: this, stat: 101);
    v47 = idRageMetrics::GetSessionStat(this: v44, playerId: v46, stat: RAGE_STAT_AFTERLIFE_KILLS);
    v45->Printf(this: debugHUD, a2: "Afterlife: %d %d\n", v47, v91);
    v48 = clientGame->rageMetrics;
    v49 = debugHUD->__vftable;
    v50 = this->entityNumber;
    v92 = idRageMetrics::GetStatInt(this: v48, player: this, stat: 44);
    v51 = idRageMetrics::GetSessionStat(this: v48, playerId: v50, stat: RAGE_STAT_VEHICLE_RALLY_DENIALS);
    v49->Printf(this: debugHUD, a2: "Denial: %d %d\n", v51, v92);
    v52 = clientGame->rageMetrics;
    v53 = debugHUD->__vftable;
    v54 = this->entityNumber;
    v93 = idRageMetrics::GetStatInt(this: v52, player: this, stat: 43);
    v55 = idRageMetrics::GetSessionStat(this: v52, playerId: v54, stat: RAGE_STAT_VEHICLE_RALLY_CLOSECALLS);
    v53->Printf(this: debugHUD, a2: "Closecalls: %d %d\n", v55, v93);
    v56 = clientGame->rageMetrics;
    v57 = this->entityNumber;
    v58 = debugHUD->__vftable;
    v94 = idRageMetrics::GetStatInt(this: v56, player: this, stat: 42);
    v59 = idRageMetrics::GetSessionStat(this: v56, playerId: v57, stat: RAGE_STAT_VEHICLE_RALLY_AIR_CAPTURES);
    v58->Printf(this: debugHUD, a2: "Air Capture: %d %d\n\n", v59, v94);
    v60 = clientGame->rageMetrics;
    v61 = this->entityNumber;
    v62 = debugHUD->__vftable;
    v95 = idRageMetrics::GetStatInt(this: v60, player: this, stat: 140);
    v63 = idRageMetrics::GetSessionStat(this: v60, playerId: v61, stat: RAGE_STAT_MOST_SPECIAL_KILLS);
    v62->Printf(this: debugHUD, a2: "Special Kills: %d %d\n\n", v63, v95);
    v64 = clientGame->rageMetrics;
    v65 = debugHUD->__vftable;
    v66 = this->entityNumber;
    v96 = idRageMetrics::GetStatInt(this: v64, player: this, stat: 104);
    v67 = idRageMetrics::GetSessionStat(this: v64, playerId: v66, stat: RAGE_STAT_LONGEST_KILLSTREAK);
    v65->Printf(this: debugHUD, a2: "Longest kill streak: %d %d\n", v67, v96);
    v68 = clientGame->rageMetrics;
    v69 = this->entityNumber;
    v70 = debugHUD->__vftable;
    v97 = idRageMetrics::GetStatInt(this: v68, player: this, stat: 105);
    v71 = idRageMetrics::GetSessionStat(this: v68, playerId: v69, stat: RAGE_STAT_LONGEST_LIFE);
    v70->Printf(this: debugHUD, a2: "Longest life: %d %d\n", v71, v97);
    v72 = clientGame->rageMetrics;
    v73 = debugHUD->__vftable;
    v74 = this->entityNumber;
    v98 = idRageMetrics::GetStatInt(this: v72, player: this, stat: 107);
    v75 = idRageMetrics::GetSessionStat(this: v72, playerId: v74, stat: RAGE_STAT_LONGEST_RALLY_CHAIN);
    v73->Printf(this: debugHUD, a2: "Longest Chain: %d %d\n", v75, v98);
    v76 = clientGame->rageMetrics;
    v77 = debugHUD->__vftable;
    v78 = this->entityNumber;
    v99 = idRageMetrics::GetStatInt(this: v76, player: this, stat: 108);
    v79 = idRageMetrics::GetSessionStat(this: v76, playerId: v78, stat: RAGE_STAT_LONGEST_RALLY_CHAIN_MAX_TIME);
    v77->Printf(this: debugHUD, a2: "Longest Chain Max Time: %d %d\n", v79, v99);
    ++v2;
    ++v4;
  }
  while ( v2 < 2 );
}


// ========================================================================
// ?DisplayStatsMP_Coop@idPlayer@@QAAXXZ
// EA  : 0x82E27038
// RVA : 0x00E27038
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::DisplayStatsMP_Coop(idPlayer *this)
{
  int v2; // r28
  void (__fastcall *SetCVarInteger)(idCVarSystem *, const char *, const int, int); // r9
  const idColor *v4; // r26
  idRageMetrics *rageMetrics; // r21
  int entityNumber; // r20
  idDebugHUD_vtbl *v7; // r25
  int StatInt; // r19
  int SessionStat; // r3
  idRageMetrics *v10; // r21
  int v11; // r20
  idDebugHUD_vtbl *v12; // r25
  int v13; // r19
  int v14; // r3
  idRageMetrics *v15; // r21
  int v16; // r20
  idDebugHUD_vtbl *v17; // r25
  int v18; // r19
  int v19; // r3
  _DWORD v20[2]; // [sp+50h] [-A0h] BYREF
  _DWORD v21[2]; // [sp+58h] [-98h] BYREF
  idColor v22[9]; // [sp+60h] [-90h] BYREF

  v2 = 0;
  v22[1] = idColor::colorWhite;
  v22[0] = idColor::colorBlack;
  SetCVarInteger = cvarSystem->SetCVarInteger;
  v21[1] = 0;
  v20[1] = 0;
  v21[0] = 1;
  v20[0] = 1;
  SetCVarInteger(this: cvarSystem, a2: "com_debugHUD", a3: 1, a4: 0);
  debugHUD->Clear(this: debugHUD, a2: false);
  debugHUD->SetTextScale(this: debugHUD, a2: 0.75);
  v4 = v22;
  do
  {
    debugHUD->SetTextColor(this: debugHUD, a2: v4);
    debugHUD->SetTextPosition(this: debugHUD, a2: v21[v2] + 5, a3: v20[v2] + 5);
    rageMetrics = clientGame->rageMetrics;
    entityNumber = this->entityNumber;
    v7 = debugHUD->__vftable;
    StatInt = idRageMetrics::GetStatInt(this: rageMetrics, player: this, stat: 32);
    SessionStat = idRageMetrics::GetSessionStat(this: rageMetrics, playerId: entityNumber, stat: RAGE_STAT_MP_LEVEL);
    v7->Printf(this: debugHUD, a2: "level: %d-%d", SessionStat, StatInt);
    v10 = clientGame->rageMetrics;
    v11 = this->entityNumber;
    v12 = debugHUD->__vftable;
    v13 = idRageMetrics::GetStatInt(this: v10, player: this, stat: 23);
    v14 = idRageMetrics::GetSessionStat(this: v10, playerId: v11, stat: RAGE_STAT_MP_XP);
    v12->Printf(this: debugHUD, a2: "xp: %d-%d\n", v14, v13);
    v15 = clientGame->rageMetrics;
    v16 = this->entityNumber;
    v17 = debugHUD->__vftable;
    v18 = idRageMetrics::GetStatInt(this: v15, player: this, stat: 35);
    v19 = idRageMetrics::GetSessionStat(this: v15, playerId: v16, stat: RAGE_STAT_SCORE_VDM);
    v17->Printf(this: debugHUD, a2: "score: %d-%d\n", v19, v18);
    ++v2;
    ++v4;
  }
  while ( v2 < 2 );
}


// ========================================================================
// ?DeactivateGeneralGameGui@idPlayer@@QAAXXZ
// EA  : 0x82E272A8
// RVA : 0x00E272A8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::DeactivateGeneralGameGui(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v3; // r3
  idPresentable *v4; // r3
  idPresentablePlayer *v5; // r3
  idSWF *PlayerGui; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = nullptr;
  if ( idPresentablePlayer::GuiIsActive(this: v3, g: GUI_GENERAL_GAME_USE) )
  {
    v4 = this->presentable;
    if ( v4 != nullptr )
      v5 = v4->GetPlayerInterface_2(this: v4);
    else
      v5 = nullptr;
    PlayerGui = idPresentablePlayer::GetPlayerGui(this: v5, g: GUI_GENERAL_GAME_USE);
    idSWF::Activate(this: PlayerGui, b: false);
  }
}


// ========================================================================
// ?ForceCloseInventory@idPlayer@@QAAXXZ
// EA  : 0x82E27340
// RVA : 0x00E27340
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ForceCloseInventory(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v3; // r3
  idPresentable *v4; // r3
  idPresentablePlayer *v5; // r3
  idSWF *PlayerGui; // r3
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = nullptr;
  if ( idPresentablePlayer::GuiIsActive(this: v3, g: GUI_INVENTORY) )
  {
    v4 = this->presentable;
    if ( v4 != nullptr )
      v5 = v4->GetPlayerInterface_2(this: v4);
    else
      v5 = nullptr;
    PlayerGui = idPresentablePlayer::GetPlayerGui(this: v5, g: GUI_INVENTORY);
    idSWF::Activate(this: PlayerGui, b: false);
    v7 = this->presentable;
    if ( v7 != nullptr )
      v8 = (int)v7->GetPlayerInterface_2(this: v7);
    else
      v8 = 0;
    idView::ForceBlurValues(this: (idView *)(v8 + 16224), blurBegin: 2.5, blurEnd: 0.0, blurTime: 250.0);
    v9 = this->presentable;
    if ( v9 != nullptr )
      v10 = (int)v9->GetPlayerInterface_2(this: v9);
    else
      v10 = 0;
    idPlayerHud::SetHudState(this: (idPlayerHud *)(v10 + 35096), state: HUDSTATE_ALL);
  }
}


// ========================================================================
// ?GetFireTrajectory@idPlayer@@QAAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82E27450
// RVA : 0x00E27450
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::GetFireTrajectory(idPlayer *this, idVec3 *firePos, idMat3 *fireAxis)
{
  idPresentable *presentable; // r3
  float *v7; // r3
  idPresentable *v8; // r3
  float *v9; // r3
  idSpringCamera *springCamera; // r11
  idSpringCamera *v11; // r11
  float *v12; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = (float *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = nullptr;
  firePos->x = v7[11633];
  firePos->y = v7[11634];
  firePos->z = v7[11635];
  v8 = this->presentable;
  if ( v8 != nullptr )
    v9 = (float *)v8->GetPlayerInterface_2(this: v8);
  else
    v9 = nullptr;
  fireAxis->mat[0].x = v9[11636];
  fireAxis->mat[0].y = v9[11637];
  fireAxis->mat[0].z = v9[11638];
  fireAxis->mat[1].x = v9[11639];
  fireAxis->mat[1].y = v9[11640];
  fireAxis->mat[1].z = v9[11641];
  fireAxis->mat[2].x = v9[11642];
  fireAxis->mat[2].y = v9[11643];
  fireAxis->mat[2].z = v9[11644];
  springCamera = this->springCamera;
  if ( springCamera != nullptr
    && springCamera->state != STATE_INACTIVE
    && (idPlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this)
     || idPlayer::PlayerBehavior_WallClimb_IsInWallClimb(this)) )
  {
    v11 = this->springCamera;
    firePos->x = v11->viewOrigin.x;
    firePos->y = v11->viewOrigin.y;
    firePos->z = v11->viewOrigin.z;
    v12 = (float *)this->springCamera;
    fireAxis->mat[0].x = v12[339];
    fireAxis->mat[0].y = v12[340];
    fireAxis->mat[0].z = v12[341];
    fireAxis->mat[1].x = v12[342];
    fireAxis->mat[1].y = v12[343];
    fireAxis->mat[1].z = v12[344];
    fireAxis->mat[2].x = v12[345];
    fireAxis->mat[2].y = v12[346];
    fireAxis->mat[2].z = v12[347];
  }
}


// ========================================================================
// ?GetVehicleCash@idPlayer@@QBAHXZ
// EA  : 0x82E275E8
// RVA : 0x00E275E8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::GetVehicleCash(idPlayer *this)
{
  const idDeclInventory *cashVehicleDecl; // r31
  idInventoryCollection *v2; // r3

  cashVehicleDecl = this->cashVehicleDecl;
  v2 = (idInventoryCollection *)this->GetInventory(this);
  return idInventoryCollection::FindTotalInventoryItemCount(this: v2, decl: cashVehicleDecl);
}


// ========================================================================
// ?RemoveVehicleCash@idPlayer@@QAAXH@Z
// EA  : 0x82E27628
// RVA : 0x00E27628
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::RemoveVehicleCash(idPlayer *this, int amount)
{
  const idDeclInventory *cashVehicleDecl; // r28
  idPresentable *presentable; // r30
  idInventoryCollection *v6; // r3

  cashVehicleDecl = this->cashVehicleDecl;
  if ( this->presentable != nullptr )
  {
    presentable = this->presentable;
  }
  else
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v6 = this->GetInventory_2(this);
  idInventoryCollection::DeleteInventoryItem(this: v6, owner: presentable, decl: cashVehicleDecl, count: amount);
}


// ========================================================================
// ?GiveVehicleCash@idPlayer@@QAAXH@Z
// EA  : 0x82E27690
// RVA : 0x00E27690
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::GiveVehicleCash(idPlayer *this, int amount)
{
  const idDeclInventory *cashVehicleDecl; // r28
  idPresentable *presentable; // r30
  idInventoryCollection *v6; // r3

  cashVehicleDecl = this->cashVehicleDecl;
  if ( this->presentable != nullptr )
  {
    presentable = this->presentable;
  }
  else
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v6 = this->GetInventory_2(this);
  idInventoryCollection::GiveItem(
    this: v6,
    owner: presentable,
    decl: cashVehicleDecl,
    count: amount,
    forceCount: false,
    canIntro: false);
}


// ========================================================================
// ?Event_ResumeLiving@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E27700
// RVA : 0x00E27700
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_ResumeLiving(idPlayer *this, idEntity *result)
{
  result[16].name.baseBuffer[0] &= ~8u;
  idEntity::StopSound(this: result, channel: SND_CHANNEL_BODY, peerMask: 0xFFu);
  return this;
}


// ========================================================================
// ?Event_Teleport@idPlayer@@AAA?AVeventVoid@@ABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82E27750
// RVA : 0x00E27750
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Teleport(
        idPlayer *this,
        idPlayer *result,
        const idVec3 *origin,
        const idAngles *angles)
{
  idPlayer::SetForceInhibitControl(this: result, inhibit: false);
  result->Teleport(this: result, a2: origin, a3: angles);
  return this;
}


// ========================================================================
// ?Event_FadeView@idPlayer@@AAA?AVeventVoid@@ABVidVec3@@MH@Z
// EA  : 0x82E277A0
// RVA : 0x00E277A0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_FadeView(
        idPlayer *this,
        eventVoid *result,
        const idVec3 *color,
        double alpha,
        const int fadeTimeMS,
        int a6)
{
  int v7; // r3
  double x; // fp30
  double y; // fp29
  double z; // fp28
  float *v15; // r3
  int v16; // r3
  double v17; // fp12
  double v18; // fp13
  int v19; // r3
  idVec4 v21; // [sp+50h] [-60h] BYREF

  v7 = *(_DWORD *)&result[488];
  x = color->x;
  y = color->y;
  z = color->z;
  if ( v7 != 0 )
    v15 = (float *)(*(int (__fastcall **)(int))(*(_DWORD *)v7 + 104))(a1: v7);
  else
    v15 = nullptr;
  v15[4767] = x;
  v15[4768] = y;
  v15[4769] = z;
  v15[4770] = 1.0;
  v16 = *(_DWORD *)&result[488];
  v17 = color->z;
  v18 = color->x;
  v21.y = color->y;
  v21.w = alpha;
  v21.x = v18;
  v21.z = v17;
  if ( v16 != 0 )
    v19 = (*(int (__fastcall **)(int))(*(_DWORD *)v16 + 104))(a1: v16);
  else
    v19 = 0;
  idView::Fade(this: (idView *)(v19 + 16224), color: &v21, time: a6);
  return this;
}


// ========================================================================
// ?Event_InhibitControl@idPlayer@@AAA?AVeventVoid@@_N@Z
// EA  : 0x82E27878
// RVA : 0x00E27878
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_InhibitControl(idPlayer *this, idPlayer *result, bool shouldInhibit)
{
  idPlayer::SetForceInhibitControl(this: result, inhibit: shouldInhibit);
  return this;
}


// ========================================================================
// ?Event_InhibitMove@idPlayer@@AAA?AVeventVoid@@_N@Z
// EA  : 0x82E278B0
// RVA : 0x00E278B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_InhibitMove(idPlayer *this, idPlayer *result, bool shouldInhibit)
{
  idPlayer::SetForceInhibitMove(this: result, inhibit: shouldInhibit);
  return this;
}


// ========================================================================
// ?Event_InhibitLook@idPlayer@@AAA?AVeventVoid@@_N0@Z
// EA  : 0x82E278E8
// RVA : 0x00E278E8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_InhibitLook(
        idPlayer *this,
        idPlayer *result,
        bool shouldInhibit,
        bool discardDelta)
{
  idPlayer::SetForceInhibitLook(this: result, inhibit: shouldInhibit, discardDelta);
  return this;
}


// ========================================================================
// ?Event_InhibitFreeGamePlay@idPlayer@@AAA?AVeventVoid@@_N0@Z
// EA  : 0x82E27928
// RVA : 0x00E27928
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_InhibitFreeGamePlay(
        idPlayer *this,
        idPlayer *result,
        bool shouldInhibit,
        bool canRun)
{
  idPlayer::SetForceInhibitFreeGamePlay(this: result, inhibit: shouldInhibit, canRun);
  return this;
}


// ========================================================================
// ?Event_InhibitRaiseWeapon@idPlayer@@AAA?AVeventVoid@@_N@Z
// EA  : 0x82E27968
// RVA : 0x00E27968
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_InhibitRaiseWeapon(idPlayer *this, idPlayer *result, bool shouldInhibit)
{
  idPlayer::SetForceInhibitRaiseWeapon(this: result, inhibit: shouldInhibit);
  return this;
}


// ========================================================================
// ?Event_InhibitChangeWeapon@idPlayer@@AAA?AVeventVoid@@_N@Z
// EA  : 0x82E279A0
// RVA : 0x00E279A0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_InhibitChangeWeapon(idPlayer *this, idPlayer *result, bool shouldInhibit)
{
  idPlayer::SetForceInhibitChangeWeapon(this: result, inhibit: shouldInhibit);
  return this;
}


// ========================================================================
// ?Event_RespawnFromWastelandDeath@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E279D8
// RVA : 0x00E279D8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_RespawnFromWastelandDeath(idPlayer *this, idPlayer *result)
{
  idPlayer::SetForceInhibitControl(this: result, inhibit: false);
  result->playerHealth.Reset_Impl(this: &result->playerHealth);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "restartmap\n");
  return this;
}


// ========================================================================
// ?UpdateWeapon@idPlayer@@QAAXXZ
// EA  : 0x82E27A50
// RVA : 0x00E27A50
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateWeapon(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetPlayerInterface_2(this: presentable);
    idPresentablePlayer::UpdateWeapon(this: v2);
  }
  else
  {
    idPresentablePlayer::UpdateWeapon(this: nullptr);
  }
}


// ========================================================================
// ?Collide@idPlayer@@UAA?AW4collide_t@@HAAUtrace_t@@ABVidVec3@@@Z
// EA  : 0x82E27AA8
// RVA : 0x00E27AA8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
collide_t __fastcall idPlayer::Collide(idPlayer *this, const int physId, trace_t *collision, const idVec3 *velocity)
{
  int v5; // r9
  idEventReceiver *v6; // r31
  idEventArg *v7; // r3
  __int128 v8; // r7 OVERLAPPED
  int v9; // r8
  __int64 v11; // [sp+8h] [-E8h]
  __int64 v12; // [sp+10h] [-E0h]
  __int64 v13; // [sp+18h] [-D8h]
  __int64 v14; // [sp+20h] [-D0h]
  __int64 v15; // [sp+28h] [-C8h]
  __int64 v16; // [sp+30h] [-C0h]
  __int64 v17; // [sp+38h] [-B8h]
  __int64 v18; // [sp+40h] [-B0h]
  __int64 v19; // [sp+48h] [-A8h]
  __int64 v20; // [sp+50h] [-A0h]
  __int64 v21; // [sp+58h] [-98h]
  __int64 v22; // [sp+78h] [-78h]
  idEventArg v23; // [sp+90h] [-60h] BYREF
  idEventReceiver v24[5]; // [sp+B0h] [-40h] BYREF

  v5 = collision->c.entityNum + 21563;
  v6 = *((idEventReceiver **)&gameLocal->__vftable + v5);
  if ( v6 != nullptr )
  {
    idEntity::Signal(this: *((idEntity **)&gameLocal->__vftable + v5), signalnum: SIG_TOUCH);
    if ( v6->RespondsTo(this: v6, a2: &EV_Touch) )
    {
      v7 = idEventArg::idEventArg(this: &v23, data: this);
      *(_QWORD *)((char *)&v8 + 4) = *(_QWORD *)&v7->type;
      v9 = __ROL4__(LODWORD(v7->value.q[3]), 32);
      *((_QWORD *)&v8 + 1) = *(_QWORD *)&v7->value.q[1];
      idEventReceiver::ProcessEvent(
        this: v24,
        result: v6,
        arg1: *(__int64 *)((char *)&v8 + 4),
        arg2: *(__int64 *)((char *)&v8 - 4),
        a5: v22,
        a6: v11,
        a7: v12,
        a8: v13,
        a9: v14,
        a10: v15,
        a11: v16,
        a12: v17,
        a13: v18,
        a14: v19,
        a15: v20,
        a16: v21);
    }
  }
  return COLLIDE_CONTINUE_SIMULATION;
}


// ========================================================================
// ?ForceFistUp@idPlayer@@QAAXXZ
// EA  : 0x82E27B78
// RVA : 0x00E27B78
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ForceFistUp(idPlayer *this)
{
  idInventoryCollection *v2; // r3
  idWeapon *InventoryItemByName; // r3
  idWeapon *v4; // r30
  idPresentable *presentable; // r3
  int v6; // r3

  v2 = this->GetInventory_2(this);
  InventoryItemByName = (idWeapon *)idInventoryCollection::FindInventoryItemByName(this: v2, internalName: "fists");
  if ( InventoryItemByName != nullptr )
  {
    v4 = idWeapon::CastTo(c: InventoryItemByName);
    if ( v4 != nullptr )
    {
      presentable = this->presentable;
      if ( presentable != nullptr )
        v6 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v6 = 0;
      idHands::SetPendingAction(
        this: (idHands *)(v6 + 37616),
        action: HANDSACTION_BRINGUP,
        weapon: v4,
        useIntroBringUp: false,
        secondary: false);
    }
  }
}


// ========================================================================
// ?Event_Carry_ShowHands@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E27C20
// RVA : 0x00E27C20
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Carry_ShowHands(idPlayer *this, eventVoid *result)
{
  int v3; // r3
  int v5; // r3
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r3

  v3 = *(_DWORD *)&result[488];
  if ( v3 != 0 )
    v5 = (*(int (__fastcall **)(int))(*(_DWORD *)v3 + 104))(a1: v3);
  else
    v5 = 0;
  *(_BYTE *)(v5 + 40606) = 1;
  v6 = *(_DWORD *)&result[488];
  if ( v6 != 0 )
    v7 = (*(int (__fastcall **)(int))(*(_DWORD *)v6 + 104))(a1: v6);
  else
    v7 = 0;
  idHands::Enable(this: (idHands *)(v7 + 37616));
  v8 = *(_DWORD *)&result[488];
  if ( v8 != 0 )
    v9 = (*(int (__fastcall **)(int))(*(_DWORD *)v8 + 104))(a1: v8);
  else
    v9 = 0;
  idHands::Reset(this: (idHands *)(v9 + 37616), doIntro: false);
  return this;
}


// ========================================================================
// ?PlayPickupSound@idPlayer@@QAAXXZ
// EA  : 0x82E27CD8
// RVA : 0x00E27CD8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::PlayPickupSound(idPlayer *this)
{
  const idDeclPlayerProps *playerProps; // r11
  idDeclPlayerProps::playerSounds_t sounds; // [sp+50h] [-E0h] BYREF

  playerProps = this->playerProps;
  if ( playerProps != nullptr )
    sounds = playerProps->sounds;
  else
    idDeclPlayerProps::playerSounds_t::playerSounds_t(this: &sounds);
  idClientGame::PlaySoundForAllPeers(
    this: clientGame,
    entity: this,
    channel: SND_CHANNEL_ITEM,
    shader: sounds.sndPickup,
    soundShaderFlags: 0);
}


// ========================================================================
// ?PlayPickupSound@idPlayer@@QAAXPAVidProp_Moveable@@@Z
// EA  : 0x82E27D40
// RVA : 0x00E27D40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::PlayPickupSound(idPlayer *this, idProp_Moveable *prop)
{
  const idSoundShader *sound_pickup; // r6

  sound_pickup = prop->sound_pickup;
  if ( sound_pickup != nullptr )
    idClientGame::PlaySoundForAllPeers(
      this: clientGame,
      entity: this,
      channel: SND_CHANNEL_ITEM,
      shader: sound_pickup,
      soundShaderFlags: 0);
  else
    idPlayer::PlayPickupSound(this);
}


// ========================================================================
// ?SetApplyDamageScale@idPlayer@@UAAXMM@Z
// EA  : 0x82E27D68
// RVA : 0x00E27D68
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetApplyDamageScale(idPlayer *this, double newApplyDamageScale, double newApplyDamageTime)
{
  int v5; // r30

  this->applyDamageScale = newApplyDamageScale;
  v5 = (int)(float)((float)1000.0 * (float)newApplyDamageTime);
  gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL);
  this->applyDamageScaleEndTime = HIDWORD(newApplyDamageScale) + v5;
  idLib::Warning(fmt: "Damage scale has increased to %g", newApplyDamageScale);
}


// ========================================================================
// ?GetAuthorityDetonationTimeRatio@idPlayer@@QAAMXZ
// EA  : 0x82E27E00
// RVA : 0x00E27E00
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

float __fastcall idPlayer::GetAuthorityDetonationTimeRatio(idPlayer *this, int a2, int a3, __int64 a4)
{
  double v4; // fp1
  double v5; // fp31
  __int64 v6; // r7

  LODWORD(a4) = this->authorityEndTime - this->authorityStartTime;
  v4 = 0.0;
  v5 = (float)a4;
  if ( v5 > 0.0 )
  {
    LODWORD(v6) = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_NORMAL)
                - this->authorityStartTime;
    v4 = (float)((float)1.0 - (float)((float)v6 / (float)v5));
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?SetApplyInvulnerability@idPlayer@@UAAXM@Z
// EA  : 0x82E27EA8
// RVA : 0x00E27EA8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetApplyInvulnerability(idPlayer *this, double invulnerabilityTime)
{
  this->invulnerabilityEndTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL)
                               + (int)(float)((float)1000.0 * (float)invulnerabilityTime);
  this->isInvulnerable = true;
}


// ========================================================================
// ?SetApplyBulletTime@idPlayer@@UAAXMM@Z
// EA  : 0x82E27F20
// RVA : 0x00E27F20
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetApplyBulletTime(idPlayer *this, double bTTime, double timeScale)
{
  idGameLocal_vtbl *v5; // r9
  float slowmoDuration; // r30
  int v7; // r3
  idGame *v8; // r3
  idGameTimeManager *v9; // r3
  slowmoParms_t v10; // [sp+50h] [-30h] BYREF

  v5 = gameLocal->__vftable;
  LODWORD(v10.slowmoDuration) = (int)(float)((float)1000.0 * (float)bTTime);
  slowmoDuration = v10.slowmoDuration;
  v7 = v5->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL);
  v10.easeInDuration = 0.0;
  v10.slowmoDuration = 0.0;
  this->bulletTimeEndTime = v7 + LODWORD(slowmoDuration);
  v10.easeOutDuration = 0.0;
  v10.timeScale = 1.0;
  v8 = common->Game(this: common);
  v9 = v8->GetGameTimeManager(this: v8);
  v10.timeScale = timeScale;
  v10.easeInDuration = 0.5;
  v10.easeOutDuration = 0.5;
  idGameTimeManager::StartSlowmotion(this: v9, slowmoParms: &v10);
}


// ========================================================================
// ?ResetBulletTime@idPlayer@@QAAXXZ
// EA  : 0x82E28000
// RVA : 0x00E28000
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ResetBulletTime(idPlayer *this)
{
  idGame *v1; // r3
  idGameTimeManager *v2; // r3
  slowmoParms_t v3; // [sp+50h] [-20h] BYREF

  this->bulletTimeEndTime = 0;
  v3.easeInDuration = 0.0;
  v3.slowmoDuration = 0.0;
  v3.easeOutDuration = 0.0;
  v3.timeScale = 1.0;
  v1 = common->Game(this: common);
  v2 = v1->GetGameTimeManager(this: v1);
  v3.timeScale = 1.0;
  v3.easeInDuration = 2.0;
  v3.easeOutDuration = 2.0;
  idGameTimeManager::StartSlowmotion(this: v2, slowmoParms: &v3);
}


// ========================================================================
// ?UpdateBulletTime@idPlayer@@QAAXXZ
// EA  : 0x82E28090
// RVA : 0x00E28090
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateBulletTime(idPlayer *this)
{
  if ( this->bulletTimeEndTime != 0
    && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL) > this->bulletTimeEndTime )
  {
    idLib::Warning(fmt: "Authority Force has ended");
    idPlayer::ResetBulletTime(this);
  }
}


// ========================================================================
// ?CanAddDroppable@idPlayer@@QAA_NXZ
// EA  : 0x82E28100
// RVA : 0x00E28100
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::CanAddDroppable(idPlayer *this)
{
  bool v2; // r3
  int num; // r11
  int v4; // r11

  v2 = common->IsMultiplayer(this: common);
  num = this->droppableList.num;
  if ( v2 )
    v4 = num - 1;
  else
    v4 = num - 2;
  return v4 != 0;
}


// ========================================================================
// ?CheckForStandingOnAI@idPlayer@@QAAXXZ
// EA  : 0x82E28168
// RVA : 0x00E28168
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::CheckForStandingOnAI(idPlayer *this)
{
  idPhysics *Physics; // r3
  float *v3; // r24
  idAI2 *v4; // r25
  int v5; // r30
  int v6; // r3
  int v7; // r11
  float *v8; // r31
  bool v9; // r31
  idPhysics *v10; // r3
  float *v11; // r25
  idPhysics *v12; // r3
  float *v13; // r3
  double v14; // fp7
  double v15; // fp6
  double y; // fp4
  double v19; // fp10
  double v20; // fp0
  double v21; // fp10
  double v22; // fp9
  idClientGame *v23; // r10
  double v24; // fp9
  double v25; // fp8
  idVec3 *p_onAiPushDir; // r31
  double v27; // fp12
  double v30; // fp6
  double v31; // fp11
  double v32; // fp7
  double v33; // fp6
  double v34; // fp5
  idClientGame *v35; // r11
  double z; // fp10

  Physics = idEntity::GetPhysics(this);
  v3 = (float *)Physics;
  if ( Physics != nullptr )
  {
    v4 = nullptr;
    v5 = 0;
    if ( Physics->GetNumContacts(this: Physics) <= 0 )
      goto LABEL_9;
    do
    {
      v6 = (*(int (__fastcall **)(float *, int))(*(_DWORD *)v3 + 220))(a1: v3, a2: v5);
      v7 = *(_DWORD *)(v6 + 56);
      v8 = (float *)v6;
      if ( v7 > 0 && v7 < 0x2000 )
      {
        v4 = idAI2::CastTo(c: (idAI2 *)gameLocal->entities.ptr[v7]);
        if ( v4 != nullptr
          && (float)((float)(v3[16] * v8[4]) + (float)((float)(v3[18] * v8[6]) + (float)(v3[17] * v8[5]))) < -0.1 )
        {
          break;
        }
      }
      ++v5;
    }
    while ( v5 < (*(int (__fastcall **)(float *))(*(_DWORD *)v3 + 216))(a1: v3) );
    if ( v4 != nullptr )
    {
      v9 = false;
      if ( this->onAiChangePushDirMilliSeconds != 0 )
      {
        v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) >= this->onAiChangePushDirMilliSeconds;
      }
      else
      {
        v10 = idEntity::GetPhysics(this: v4);
        v11 = (float *)v10->GetOrigin(this: v10, a2: 0);
        v12 = idEntity::GetPhysics(this);
        v13 = (float *)v12->GetOrigin(this: v12, a2: 0);
        v14 = (float)(v13[1] - v11[1]);
        v15 = (float)(v13[2] - v11[2]);
        this->onAiPushDir.x = *v13 - *v11;
        this->onAiPushDir.y = v14;
        this->onAiPushDir.z = v15;
        this->onAiPushDir.z = 0.0;
        y = this->onAiPushDir.y;
        _FP1 = (float)((float)((float)(this->onAiPushDir.x * this->onAiPushDir.x)
                             + (float)(this->onAiPushDir.y * this->onAiPushDir.y))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f11, f1, f2, f0 }
        v19 = __frsqrte(_FP11);
        v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                            * (float)((float)((float)(this->onAiPushDir.x * this->onAiPushDir.x) + (float)(this->onAiPushDir.y * this->onAiPushDir.y)) * (float)0.5))
                                                                                    * (float)v19)
                                                                            - (float)1.5)
                                                            * (float)v19)
                                                    * (float)((float)((float)(this->onAiPushDir.x * this->onAiPushDir.x)
                                                                    + (float)(this->onAiPushDir.y * this->onAiPushDir.y))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v19
                                                                                    * (float)((float)((float)(this->onAiPushDir.x * this->onAiPushDir.x) + (float)(this->onAiPushDir.y * this->onAiPushDir.y))
                                                                                            * (float)0.5))
                                                                            * (float)v19)
                                                                    - (float)1.5)
                                                    * (float)v19))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v19
                                                            * (float)((float)((float)(this->onAiPushDir.x
                                                                                    * this->onAiPushDir.x)
                                                                            + (float)(this->onAiPushDir.y
                                                                                    * this->onAiPushDir.y))
                                                                    * (float)0.5))
                                                    * (float)v19)
                                            - (float)1.5)
                            * (float)v19));
        v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(this->onAiPushDir.x * this->onAiPushDir.x) + (float)(this->onAiPushDir.y * this->onAiPushDir.y)) * (float)0.5)) * (float)v19) - (float)1.5) * (float)v19)
                                                                                            * (float)((float)((float)(this->onAiPushDir.x * this->onAiPushDir.x) + (float)(this->onAiPushDir.y * this->onAiPushDir.y)) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(this->onAiPushDir.x * this->onAiPushDir.x) + (float)(this->onAiPushDir.y * this->onAiPushDir.y)) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                            * (float)v19))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(this->onAiPushDir.x * this->onAiPushDir.x) + (float)(this->onAiPushDir.y * this->onAiPushDir.y)) * (float)0.5))
                                                                                            * (float)v19)
                                                                                    - (float)1.5)
                                                                    * (float)v19))
                                                    * (float)((float)((float)(this->onAiPushDir.x * this->onAiPushDir.x)
                                                                    + (float)(this->onAiPushDir.y * this->onAiPushDir.y))
                                                            * (float)0.5))
                                            * (float)v20)
                                    - (float)1.5)
                    * (float)v20);
        v22 = (float)((float)v21
                    * (float)((float)(this->onAiPushDir.x * this->onAiPushDir.x)
                            + (float)(this->onAiPushDir.y * this->onAiPushDir.y)));
        this->onAiPushDir.x = this->onAiPushDir.x * (float)v21;
        this->onAiPushDir.y = (float)y * (float)v21;
        if ( v22 >= 0.001 )
        {
          v23 = clientGame;
          v24 = (float)(this->onAiPushDir.y * 500.0);
          v25 = (float)(this->onAiPushDir.z * 500.0);
          this->onAiPushDir.x = this->onAiPushDir.x * 500.0;
          this->onAiPushDir.y = v24;
          this->onAiPushDir.z = v25;
          this->onAiChangePushDirMilliSeconds = idGameTimeManager::GetGameMs(
                                                  this: &v23->gameTimeManager,
                                                  type: GAMETIME_SCALED)
                                              + 250;
        }
        else
        {
          v9 = true;
        }
      }
      if ( v9 )
      {
        p_onAiPushDir = &this->onAiPushDir;
        do
        {
          p_onAiPushDir->x = RandomFloat(min: -1.0, max: 1.0);
          this->onAiPushDir.y = RandomFloat(min: -1.0, max: 1.0);
          v27 = this->onAiPushDir.y;
          _FP9 = (float)((float)((float)(this->onAiPushDir.x * this->onAiPushDir.x)
                               + (float)(this->onAiPushDir.y * this->onAiPushDir.y))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f7, f9, f10, f0 }
          v30 = __frsqrte(_FP7);
          v31 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30
                                                                                              * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5))
                                                                                      * (float)v30)
                                                                              - (float)1.5)
                                                              * (float)v30)
                                                      * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x)
                                                                      + (float)(p_onAiPushDir->y * p_onAiPushDir->y))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v30
                                                                                      * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y))
                                                                                              * (float)0.5))
                                                                              * (float)v30)
                                                                      - (float)1.5)
                                                      * (float)v30))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v30
                                                              * (float)((float)((float)(p_onAiPushDir->x
                                                                                      * p_onAiPushDir->x)
                                                                              + (float)(p_onAiPushDir->y
                                                                                      * p_onAiPushDir->y))
                                                                      * (float)0.5))
                                                      * (float)v30)
                                              - (float)1.5)
                              * (float)v30));
          v32 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30)
                                                                                              * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5)) * (float)v30) - (float)1.5)
                                                                                              * (float)v30))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5))
                                                                                              * (float)v30)
                                                                                      - (float)1.5)
                                                                      * (float)v30))
                                                      * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x)
                                                                      + (float)(p_onAiPushDir->y * p_onAiPushDir->y))
                                                              * (float)0.5))
                                              * (float)v31)
                                      - (float)1.5)
                      * (float)v31);
          v34 = (float)(p_onAiPushDir->x
                      * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30) * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5)) * (float)v30)
                                                                                              - (float)1.5)
                                                                              * (float)v30))
                                                              * (float)((float)((float)(p_onAiPushDir->x
                                                                                      * p_onAiPushDir->x)
                                                                              + (float)(p_onAiPushDir->y
                                                                                      * p_onAiPushDir->y))
                                                                      * (float)0.5))
                                                      * (float)v31)
                                              - (float)1.5)
                              * (float)v31));
          v33 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30) * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5))
                                                                                              * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5)) * (float)v30) - (float)1.5) * (float)v30))
                                                                                      - (float)1.5)
                                                                      * (float)((float)-(float)((float)((float)((float)v30 * (float)((float)((float)(p_onAiPushDir->x * p_onAiPushDir->x) + (float)(p_onAiPushDir->y * p_onAiPushDir->y)) * (float)0.5)) * (float)v30)
                                                                                              - (float)1.5)
                                                                              * (float)v30))
                                                              * (float)((float)((float)(p_onAiPushDir->x
                                                                                      * p_onAiPushDir->x)
                                                                              + (float)(p_onAiPushDir->y
                                                                                      * p_onAiPushDir->y))
                                                                      * (float)0.5))
                                                      * (float)v31)
                                              - (float)1.5)
                              * (float)v31)
                      * (float)((float)(p_onAiPushDir->x * p_onAiPushDir->x)
                              + (float)(p_onAiPushDir->y * p_onAiPushDir->y)));
          p_onAiPushDir->x = v34;
          this->onAiPushDir.y = (float)v27 * (float)v32;
        }
        while ( v33 < 0.000099999997 );
        v35 = clientGame;
        z = this->onAiPushDir.z;
        p_onAiPushDir->x = (float)v34 * 500.0;
        this->onAiPushDir.y = (float)((float)v27 * (float)v32) * 500.0;
        this->onAiPushDir.z = (float)z * (float)500.0;
        this->onAiChangePushDirMilliSeconds = idGameTimeManager::GetGameMs(
                                                this: &v35->gameTimeManager,
                                                type: GAMETIME_SCALED)
                                            + 250;
      }
      (*(void (__fastcall **)(float *, idVec3 *, _DWORD))(*(_DWORD *)v3 + 80))(a1: v3, a2: &this->onAiPushDir, a3: 0);
    }
    else
    {
LABEL_9:
      this->onAiChangePushDirMilliSeconds = 0;
    }
  }
}


// ========================================================================
// ?UpdateActiveJob@idPlayer@@QAAXXZ
// EA  : 0x82E28538
// RVA : 0x00E28538
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateActiveJob(idPlayer *this)
{
  idJobManager *p_jobManager; // r30
  idJob *ActiveJob; // r3
  idPresentable *presentable; // r11
  const idDeclJob *decl; // r31
  int v6; // r3
  const idDeclJob *v7; // r4
  idPresentable *v8; // r3

  p_jobManager = &this->jobManager;
  if ( idJobManager::GetActiveJob(this: &this->jobManager) != nullptr )
  {
    ActiveJob = idJobManager::GetActiveJob(this: p_jobManager);
    presentable = this->presentable;
    decl = ActiveJob->decl;
    if ( presentable != nullptr )
      v6 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v6 = 0;
    v7 = decl;
  }
  else
  {
    v8 = this->presentable;
    if ( v8 != nullptr )
      v6 = (int)v8->GetPlayerInterface_2(this: v8);
    else
      v6 = 0;
    v7 = nullptr;
  }
  idPlayerHud::UpdateJob(
    this: (idPlayerHud *)(v6 + 35096),
    jobDecl: v7,
    requirementNum: -1,
    playSound: false,
    treatAsSameStatusUpdate: false);
}


// ========================================================================
// ?SetLevelTransitionGuiVolume@idPlayer@@QAAXPAVidVolume_ShowGui_Leveltransition@@VidStrId@@_N2@Z
// EA  : 0x82E28600
// RVA : 0x00E28600
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetLevelTransitionGuiVolume(
        idPlayer *this,
        idVolume_ShowGui_Leveltransition *volume,
        idStrId *levelName,
        bool active,
        bool inVehicle)
{
  int entityNumber; // r4

  if ( (*((_BYTE *)this + 12824) & 4) == 0 && (active || this->levelTransitionGuiVolume == nullptr) )
  {
    this->levelTransitionGuiVolume = volume;
    entityNumber = this->entityNumber;
    this->levelTransitionGuiVolumeActive = active;
    idClientGame::GetProfileFromPlayerIndex(this: clientGame, index: entityNumber);
  }
}


// ========================================================================
// ?GetWalkState@idPlayer@@UBA?AW4walkState_t@@XZ
// EA  : 0x82E28648
// RVA : 0x00E28648
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

walkState_t __fastcall idPlayer::GetWalkState(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  char v4; // r9
  walkState_t result; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  v4 = *(_BYTE *)(v3 + 47032);
  result = WALKSTATE_NOCLIP;
  if ( (v4 & 0x20) == 0 )
    return this->actorVolatile.walkState;
  return result;
}


// ========================================================================
// ?HandleUserCmds@idPlayer@@QAAXABVusercmd_t@@@Z
// EA  : 0x82E286B8
// RVA : 0x00E286B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::HandleUserCmds(idPlayer *this, const usercmd_t *newcmd)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = nullptr;
  idPresentablePlayer::HandleUserCmds(this: v4, newcmd);
}


// ========================================================================
// ?SetViewAngles@idPlayer@@QAAXABVidAngles@@_N@Z
// EA  : 0x82E28710
// RVA : 0x00E28710
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetViewAngles(idPlayer *this, idAngles *angles, bool force)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v7; // r3
  idAngles v8[6]; // [sp+50h] [-50h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = nullptr;
  idPresentablePlayer::SetViewAngles(this: v7, angles, force);
  this->modelAxis = *idAngles::ToMat3(this: v8, result: (idMat3 *)angles);
}


// ========================================================================
// ?JobSync@idPlayer@@UAAXXZ
// EA  : 0x82E287C0
// RVA : 0x00E287C0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::JobSync(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v3; // r3
  int PlayerGameTime; // r3
  idPresentable *v5; // r3
  int v6; // r3
  idBot *botController; // r3
  idPlayerTimeLock v8[2]; // [sp+50h] [-20h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = nullptr;
  PlayerGameTime = idPresentablePlayer::GetPlayerGameTime(this: v3);
  idPlayerTimeLock::idPlayerTimeLock(this: v8, newTime: PlayerGameTime);
  idAnimatedEntity::JobSync(this);
  v5 = this->presentable;
  if ( v5 != nullptr )
    v6 = (int)v5->GetPlayerInterface_2(this: v5);
  else
    v6 = 0;
  idHands::JobSync(this: (idHands *)(v6 + 37616));
  botController = this->botController;
  if ( botController != nullptr )
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)botController);
  idPlayerTimeLock::~idPlayerTimeLock(this: v8);
}


// ========================================================================
// __unwind$504718
// EA  : 0x82E28878
// RVA : 0x00E28878
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_504718()
{
  int v0; // r12

  idPlayerTimeLock::~idPlayerTimeLock(this: (idPlayerTimeLock *)(v0 - 112 + 80));
}


// ========================================================================
// ?ApplyWaterEffects@idPlayer@@UAAXHH@Z
// EA  : 0x82E288A0
// RVA : 0x00E288A0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ApplyWaterEffects(idPlayer *this, int physId, int bodyId)
{
  idPhysics *PhysicsForId; // r3
  idPhysics *v7; // r28
  idDynamicWaterEntity *v8; // r31
  const idDeclDamage *damage; // r30
  idPlayer_vtbl *v10; // r27
  idPhysics *Physics; // r3
  int v12; // r3
  int v13; // r7
  float v14; // r6
  int v15; // r30
  idDynamicWaterEntity *v16; // r31
  idPhysics *v17; // r3
  idBounds *v18; // r3
  double v19; // fp31
  idPhysics *v20; // r3
  int v21; // r3
  int v24; // r6
  idPresentable *presentable; // r3
  int v26; // r3
  bool IsUnderWater; // r3
  bool v28; // r20
  __int64 v29; // r5
  unsigned int v30; // r9
  double v31; // fp31
  int GameMsPerFrame; // r22
  int GameMs; // r21
  const idDeclParticle *prtWaterSplash; // r18
  idRenderModelEffects *MergeBranch; // r3
  const idVec3 *v36; // r7
  idPlayer *PlayerSounds; // r3
  idPresentable *v38; // r3
  int v39; // r3
  char *v40; // r10
  _DWORD *v41; // r11
  int i; // ctr
  idPhysics *v43; // r3
  float *v44; // r3
  __int64 v45; // r6
  double v46; // fp8
  double v47; // fp6
  unsigned int v48; // r10
  double v49; // fp31
  int v50; // r18
  int v51; // r17
  const idDeclParticle *prtUnderwater; // r16
  idRenderModelEffects *v53; // r3
  const idVec3 *v54; // r7
  idPlayer *v55; // r3
  __int64 v56; // r5
  unsigned int v57; // r9
  double v58; // fp31
  int v59; // r28
  int v60; // r31
  const idDeclParticle *prtWaterTransition; // r30
  idRenderModelEffects *v62; // r3
  const idVec3 *v63; // r7
  int v64; // [sp+8h] [-238h]
  int v65; // [sp+Ch] [-234h]
  int v66; // [sp+10h] [-230h]
  int v67; // [sp+14h] [-22Ch]
  int v68; // [sp+18h] [-228h]
  int v69; // [sp+1Ch] [-224h]
  int v70; // [sp+20h] [-220h]
  int v71; // [sp+24h] [-21Ch]
  int v72; // [sp+28h] [-218h]
  int v73; // [sp+2Ch] [-214h]
  int v74; // [sp+30h] [-210h]
  int v75; // [sp+34h] [-20Ch]
  int v76; // [sp+38h] [-208h]
  int v77; // [sp+3Ch] [-204h]
  int v78; // [sp+40h] [-200h]
  int v79; // [sp+44h] [-1FCh]
  int v80; // [sp+48h] [-1F8h]
  int v81; // [sp+4Ch] [-1F4h]
  int v82; // [sp+50h] [-1F0h]
  unsigned int v83[2]; // [sp+60h] [-1E0h] BYREF
  idMat3 v84; // [sp+68h] [-1D8h] BYREF
  int v85; // [sp+8Ch] [-1B4h]
  float v86; // [sp+90h] [-1B0h]
  float v87[5]; // [sp+98h] [-1A8h] BYREF
  char v88; // [sp+ACh] [-194h] BYREF
  idMat3 v89; // [sp+B0h] [-190h] BYREF
  _BYTE v90[208]; // [sp+E0h] [-160h] BYREF

  PhysicsForId = idPhysics::GetPhysicsForId(physicsId_: physId);
  v7 = PhysicsForId;
  if ( PhysicsForId != nullptr )
  {
    v8 = (idDynamicWaterEntity *)idWaterEntity::CastTo(c: (idWaterEntity *)gameLocal->entities.ptr[PhysicsForId->entityNumber]);
    if ( v8 != nullptr )
    {
      idActor::ApplyWaterEffects(this, physId, id: bodyId);
      damage = v8->damage;
      if ( damage != nullptr )
      {
        v10 = this->__vftable;
        gameLocal->GetRealSecPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
        ((void (__fastcall *)(idPlayer *, idDynamicWaterEntity *, _DWORD, const idDeclDamage *))v10->Damage)(
          a1: this,
          a2: v8,
          a3: 0,
          a4: damage);
      }
      Physics = idEntity::GetPhysics(this);
      v12 = (int)Physics->GetOrigin(this: Physics, a2: 0);
      v13 = *(_DWORD *)(v12 + 4);
      v14 = *(float *)(v12 + 8);
      v84.mat[2].z = *(float *)v12;
      v85 = v13;
      v86 = v14;
      v15 = (int)v7->GetBounds(this: v7, a2: -1);
      v86 = v7->GetOrigin(this: v7, a2: 0)->z + *(float *)(v15 + 20);
      v16 = idDynamicWaterEntity::CastTo(c: v8);
      if ( v16 != nullptr )
      {
        v17 = idEntity::GetPhysics(this);
        v18 = (idBounds *)v17->GetBounds(this: v17, a2: -1);
        v19 = (float)(idBounds::GetRadius(this: v18) * (float)0.5);
        v20 = idEntity::GetPhysics(this);
        v21 = (int)v20->GetLinearVelocity(this: (idPhysics *)&v84.mat[1].y, result: (idVec3 *)v20, a3: 0);
        _FP8 = (float)((float)1.0
                     - (float)__fsqrts((float)((float)(*(float *)v21 * *(float *)v21)
                                             + (float)(*(float *)(v21 + 4) * *(float *)(v21 + 4)))));
        __asm { fsel      f7, f8, f0, f9 }
        idDynamicWaterEntity::AddRipple(
          this: v16,
          pos: (const idVec3 *)&v84.mat[2].z,
          mag: (float)((float)_FP7 * (float)-0.02),
          radius: v19,
          a5: (const idRenderModel *)v21,
          a6: v24);
      }
      presentable = this->presentable;
      if ( presentable != nullptr )
        v26 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v26 = 0;
      IsUnderWater = idPhysics_Player::GetIsUnderWater(this: (idPhysics_Player *)(v26 + 36264));
      v28 = IsUnderWater;
      if ( !this->lastFrameInWater && !IsUnderWater )
      {
        v83[0] = -1;
        HIDWORD(v29) = 1;
        v30 = 1664525 * clientGame->random.seed;
        clientGame->random.seed = v30 + 1013904223;
        LODWORD(v29) = ((v30 + 1013904223) >> 10) & 0x7FFF;
        *(_QWORD *)&v84.mat[1].y = v29;
        v31 = (float)((float)v29 * (float)0.000030518509);
        GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        prtWaterSplash = this->prtWaterSplash;
        MergeBranch = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
        idRenderModelEffects::AddParticles(
          this: MergeBranch,
          particle: prtWaterSplash,
          systemStartTime: GameMs,
          gameMsPerFrame: GameMsPerFrame,
          diversity: v31,
          origin: v36,
          axis: (idMat3 *)&v84.mat[2].z,
          velocity: mat3_identity.mat,
          color: &vec3_origin.x,
          a10: v64,
          a11: v65,
          a12: v66,
          a13: v67,
          a14: v68,
          a15: v69,
          a16: v70,
          a17: v71,
          a18: v72,
          a19: v73,
          a20: v74,
          a21: v75,
          a22: v76,
          a23: v77,
          a24: v78,
          a25: v79,
          a26: v80,
          a27: v81,
          a28: v82,
          a29: v83);
      }
      if ( v28 )
      {
        if ( !this->underwaterEffectIsRunning )
        {
          this->underwaterEffectIsRunning = true;
          PlayerSounds = idPlayer::GetPlayerSounds(
                           this: (idPlayer *)v90,
                           result: (const idDeclPlayerProps::playerSounds_t *)this);
          idEntity::StartSoundShader(
            this,
            channel: SND_CHANNEL_WATER,
            shader: (const idSoundShader *)PlayerSounds->targets.list,
            soundShaderFlags: (soundShaderFlags_t)0,
            peerMask: 0xFFu);
        }
        this->GetEyePos(this, a2: (idVec3 *)v87);
        v38 = this->presentable;
        if ( v38 != nullptr )
          v39 = (int)v38->GetPlayerInterface_2(this: v38);
        else
          v39 = 0;
        v40 = &v88;
        v41 = (_DWORD *)(v39 + 46540);
        for ( i = 9; i != 0; --i )
        {
          ++v41;
          v40 += 4;
          *(_DWORD *)v40 = *v41;
        }
        v89.mat[2].x = vec3_up.x;
        v89.mat[2].y = vec3_up.y;
        v89.mat[2].z = vec3_up.z;
        idMat3::OrthoNormalizeSelf(this: &v89, prio1: 2, prio2: 1);
        v84.mat[0].x = v87[0] + (float)(v89.mat[0].x * (float)-32.0);
        v84.mat[0].y = v87[1] + (float)(v89.mat[0].y * (float)-32.0);
        v84.mat[0].z = v87[2] + (float)(v89.mat[0].z * (float)-32.0);
        v43 = idEntity::GetPhysics(this);
        v44 = (float *)v43->GetLinearVelocity(this: (idPhysics *)&v84.mat[1].y, result: (idVec3 *)v43, a3: 0);
        HIDWORD(v45) = &unk_821F0000;
        v46 = v44[2];
        v47 = (float)(v44[1] * (float)0.34999999);
        v84.mat[0].x = (float)(*v44 * (float)0.34999999) + v84.mat[0].x;
        v83[0] = -1;
        v84.mat[0].y = (float)v47 + v84.mat[0].y;
        v84.mat[0].z = (float)((float)v46 * (float)0.34999999) + v84.mat[0].z;
        v48 = 1664525 * clientGame->random.seed;
        clientGame->random.seed = v48 + 1013904223;
        LODWORD(v45) = ((v48 + 1013904223) >> 10) & 0x7FFF;
        *(_QWORD *)&v84.mat[1].y = v45;
        v49 = (float)((float)v45 * (float)0.000030518509);
        v50 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v51 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        prtUnderwater = this->prtUnderwater;
        v53 = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
        idRenderModelEffects::AddParticles(
          this: v53,
          particle: prtUnderwater,
          systemStartTime: v51,
          gameMsPerFrame: v50,
          diversity: v49,
          origin: v54,
          axis: &v84,
          velocity: v89.mat,
          color: &vec3_origin.x,
          a10: v64,
          a11: v65,
          a12: v66,
          a13: v67,
          a14: v68,
          a15: v69,
          a16: v70,
          a17: v71,
          a18: v72,
          a19: v73,
          a20: v74,
          a21: v75,
          a22: v76,
          a23: v77,
          a24: v78,
          a25: v79,
          a26: v80,
          a27: v81,
          a28: v82,
          a29: v83);
      }
      else if ( this->underwaterEffectIsRunning )
      {
        this->underwaterEffectIsRunning = false;
        v55 = idPlayer::GetPlayerSounds(this: (idPlayer *)v90, result: (const idDeclPlayerProps::playerSounds_t *)this);
        idEntity::StartSoundShader(
          this,
          channel: SND_CHANNEL_WATER,
          shader: (const idSoundShader *)v55->targets.num,
          soundShaderFlags: (soundShaderFlags_t)0,
          peerMask: 0xFFu);
      }
      if ( !this->lastFrameUnderwater || v28 )
      {
        this->transitionEffectIsRunning = false;
        this->lastFrameUnderwater = v28;
        this->lastFrameInWater = true;
      }
      else
      {
        v83[0] = -1;
        HIDWORD(v56) = 1;
        v57 = 1664525 * clientGame->random.seed;
        clientGame->random.seed = v57 + 1013904223;
        LODWORD(v56) = ((v57 + 1013904223) >> 10) & 0x7FFF;
        *(_QWORD *)&v84.mat[1].y = v56;
        v58 = (float)((float)v56 * (float)0.000030518509);
        v59 = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        v60 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        prtWaterTransition = this->prtWaterTransition;
        v62 = (idRenderModelEffects *)idAnimator_BlendEq::InternalGetMergeBranch(this: (idAnimator_BlendEq *)clientGame);
        idRenderModelEffects::AddParticles(
          this: v62,
          particle: prtWaterTransition,
          systemStartTime: v60,
          gameMsPerFrame: v59,
          diversity: v58,
          origin: v63,
          axis: (idMat3 *)&v84.mat[2].z,
          velocity: mat3_identity.mat,
          color: &vec3_origin.x,
          a10: v64,
          a11: v65,
          a12: v66,
          a13: v67,
          a14: v68,
          a15: v69,
          a16: v70,
          a17: v71,
          a18: v72,
          a19: v73,
          a20: v74,
          a21: v75,
          a22: v76,
          a23: v77,
          a24: v78,
          a25: v79,
          a26: v80,
          a27: v81,
          a28: v82,
          a29: v83);
        this->transitionEffectIsRunning = true;
        this->lastFrameUnderwater = v28;
        this->lastFrameInWater = true;
      }
    }
  }
}


// ========================================================================
// ?UpdateBonuses@idPlayer@@QAAXXZ
// EA  : 0x82E28EC8
// RVA : 0x00E28EC8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateBonuses(idPlayer *this)
{
  idPlayerProfileGame *v2; // r3
  idPlayerProfileGame *v3; // r30
  int secretAndProgressStamp; // r11
  int v5; // r3
  int v6; // r3
  __int64 v7; // r5

  idClientGame::GetProfileFromPlayerIndex(this: clientGame, index: this->entityNumber);
  v3 = v2;
  if ( v2 != nullptr )
  {
    secretAndProgressStamp = v2->secretAndProgressStamp;
    if ( this->bonusStamp != secretAndProgressStamp )
    {
      this->bonusStamp = secretAndProgressStamp;
      v5 = idPlayerProfileGame::CountBonuses(this: v2, bonusType: 1, onlyTaken: true);
      this->playerHealth.SetComponentMax_Impl(
        this: &this->playerHealth,
        a2: 0,
        a3: (float)(unsigned int)(20 * (v5 + 5)));
      v6 = idPlayerProfileGame::CountBonuses(this: v3, bonusType: 2, onlyTaken: true);
      HIDWORD(v7) = 1;
      LODWORD(v7) = 20 * (v6 + 5);
      this->playerHealth.SetComponentMax_Impl(this: &this->playerHealth, a2: 1, a3: (float)v7);
    }
  }
}


// ========================================================================
// ?IsOnLadder@idPlayer@@QBA_NXZ
// EA  : 0x82E28FA8
// RVA : 0x00E28FA8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::IsOnLadder(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  bool v4; // r3
  unsigned __int8 v5; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  if ( *(_BYTE *)(v3 + 37447) != 0 )
    return 1;
  v4 = idPlayer::PlayerBehavior_ContextualLadder_IsOnLadder(this);
  v5 = 0;
  if ( v4 )
    return 1;
  return v5;
}


// ========================================================================
// ?DamageFeedback@idPlayer@@UAAXPAVidEntity@@0PBVidDeclDamage@@AAM@Z
// EA  : 0x82E29028
// RVA : 0x00E29028
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::DamageFeedback(
        idPlayer *this,
        idAI2 *victim,
        idEntity *inflictor,
        const idDeclDamage *damageDef,
        float *damage)
{
  char v10; // r11
  bool v11; // r28
  idPresentable *presentable; // r31
  idPresentable *v13; // r3
  idPresentablePlayer *v14; // r3
  idAI2 *v15; // r3
  idEntity *v16; // r31
  idAIHealth *p_aiHealth; // r30
  double v18; // fp30
  idPhysics *Physics; // r3
  idPresentable *v20; // r11
  idPhysics *v21; // r30
  int v22; // r31
  char v23; // r3
  const idVec3 *v24; // r5
  __int64 v25; // [sp+50h] [-50h]

  idActor::DamageFeedback(this, victim, inflictor, damageDef, damage);
  v25 = (unsigned int)idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
      | 0x32DC00000000LL;
  *(idPlayer_vtbl **)((char *)&this->__vftable + HIDWORD(v25)) = (idPlayer_vtbl *)(int)(float)(this->hitFlashDuration
                                                                                             + (float)v25);
  if ( common->IsMultiplayer(this: common) && damageDef != nullptr )
  {
    if ( inflictor != nullptr || (v10 = 1, damageDef->radius > 0.0) )
      v10 = 0;
    v11 = v10;
    if ( victim->presentable == nullptr )
      idEntity::InitPresentableInternal(this: victim);
    presentable = victim->presentable;
    v13 = this->presentable;
    if ( v13 != nullptr )
      v14 = v13->GetPlayerInterface_2(this: v13);
    else
      v14 = nullptr;
    idPresentablePlayer::DamageDealtFeedback(this: v14, victim: presentable, predicted: v11);
  }
  v15 = idAI2::CastTo(c: victim);
  v16 = v15;
  if ( v15 != nullptr
    && damageDef != nullptr
    && (*((_BYTE *)&v15->aiEditable.behaviors.decl->damageBehaviors + 84) & 1) != 0
    && v15->aiHealth.components[1].cur <= 0.0 )
  {
    p_aiHealth = &v15->aiHealth;
    v18 = (float)(*damage / v15->aiHealth.GetMaxBaseHealth_Impl(this: &v15->aiHealth));
    p_aiHealth->GetCurBaseHealth_Impl(this: p_aiHealth);
    Physics = idEntity::GetPhysics(this: v16);
    v20 = this->presentable;
    v21 = Physics;
    if ( v20 != nullptr )
      v22 = (int)v20->GetPlayerInterface_2(this: this->presentable);
    else
      v22 = 0;
    v23 = (char)v21->GetOrigin(this: v21, a2: 0);
    idView::DamageFeedback(this: (idView *)(v22 + 16224), damageDef, damageScale: v18, victimOrg: v24, isGibbed: v23);
  }
}


// ========================================================================
// ?DefaultFov@idPlayer@@QBAMXZ
// EA  : 0x82E29258
// RVA : 0x00E29258
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

float __fastcall idPlayer::DefaultFov(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v2; // r3
  double v3; // fp1

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetPlayerInterface_2(this: presentable);
    v3 = idPresentablePlayer::DefaultFov(this: v2);
  }
  else
  {
    v3 = idPresentablePlayer::DefaultFov(this: nullptr);
  }
  return *((float *)&v3 + 1);
}


// ========================================================================
// ?CalcFov@idPlayer@@QBAM_N@Z
// EA  : 0x82E292B0
// RVA : 0x00E292B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

float __fastcall idPlayer::CalcFov(idPlayer *this, bool honorZoom)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v4; // r3
  double v5; // fp1

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = nullptr;
  v5 = idPresentablePlayer::CalcFov(this: v4, honorZoom);
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?SetupZoom@idPlayer@@QAAX_N@Z
// EA  : 0x82E29308
// RVA : 0x00E29308
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetupZoom(idPlayer *this, bool handsZoomIn)
{
  idPresentable *presentable; // r3
  int v5; // r30
  idPresentable *v6; // r3
  idPresentablePlayer *v7; // r31
  idWeapon *v8; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  v6 = this->presentable;
  if ( v6 != nullptr )
    v7 = v6->GetPlayerInterface_2(this: v6);
  else
    v7 = nullptr;
  v8 = (idWeapon *)(*(int (__fastcall **)(int, int))(*(_DWORD *)v5 + 344))(a1: v5, a2: 2);
  idPresentablePlayer::SetupZoom(this: v7, handsZoomIn, weapon: v8);
}


// ========================================================================
// ?GetEyePos@idPlayer@@UBAXAAVidVec3@@@Z
// EA  : 0x82E293A0
// RVA : 0x00E293A0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::GetEyePos(idPlayer *this, idVec3 *eyePos)
{
  idPresentable *presentable; // r3
  float *v5; // r3
  idSpringCamera *springCamera; // r11
  idSpringCamera *v7; // r11

  if ( pm_thirdPerson.valueInteger != 0 || common->IsMultiplayer(this: common) )
  {
    idActor::GetEyePos(this, eyePos);
  }
  else
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      v5 = (float *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v5 = nullptr;
    eyePos->x = v5[11633];
    eyePos->y = v5[11634];
    eyePos->z = v5[11635];
    springCamera = this->springCamera;
    if ( springCamera != nullptr
      && springCamera->state != STATE_INACTIVE
      && (idPlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this)
       || idPlayer::PlayerBehavior_WallClimb_IsInWallClimb(this)) )
    {
      v7 = this->springCamera;
      eyePos->x = v7->viewOrigin.x;
      eyePos->y = v7->viewOrigin.y;
      eyePos->z = v7->viewOrigin.z;
    }
  }
}


// ========================================================================
// ?GetVisibilityPoint@idPlayer@@UBAXW4visPoint_t@@AAVidVec3@@@Z
// EA  : 0x82E294C0
// RVA : 0x00E294C0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::GetVisibilityPoint(idActor *this, visPoint_t type, idVec3 *pos)
{
  idEntity *BindMaster; // r3
  idPhysics *v7; // r3
  float *v8; // r3
  idPhysics *Physics; // r3
  int v10; // r3
  char *v11; // r10
  _DWORD *v12; // r11
  int i; // ctr
  double v14; // fp8
  double v15; // fp6
  char v16; // [sp+4Ch] [-44h] BYREF
  float v17; // [sp+50h] [-40h]
  float v18; // [sp+54h] [-3Ch]
  float v19; // [sp+58h] [-38h]
  float v20; // [sp+5Ch] [-34h]
  float v21; // [sp+60h] [-30h]
  float v22; // [sp+64h] [-2Ch]

  BindMaster = idEntity::GetBindMaster(this);
  if ( BindMaster != nullptr )
  {
    BindMaster->GetVisibilityPoint(this: BindMaster, a2: type, a3: pos);
  }
  else if ( type != VISPOINT_EYES )
  {
    if ( type == VISPOINT_CENTER )
    {
      Physics = idEntity::GetPhysics(this);
      v10 = (int)Physics->GetAbsBounds(this: Physics, a2: -1);
      v11 = &v16;
      v12 = (_DWORD *)(v10 - 4);
      for ( i = 6; i != 0; --i )
      {
        ++v12;
        v11 += 4;
        *(_DWORD *)v11 = *v12;
      }
      v14 = (float)(v18 + v21);
      v15 = (float)(v19 + v22);
      pos->x = (float)(v17 + v20) * (float)0.5;
      pos->y = (float)v14 * (float)0.5;
      pos->z = (float)v15 * (float)0.5;
    }
    else
    {
      v7 = idEntity::GetPhysics(this);
      v8 = (float *)v7->GetOrigin(this: v7, a2: 0);
      pos->x = *v8;
      pos->y = v8[1];
      pos->z = v8[2];
    }
  }
  else
  {
    this->GetEyePos(this, a2: pos);
  }
}


// ========================================================================
// ?GetAimPoint@idPlayer@@UBAXW4aimPoint_t@@AAVidVec3@@@Z
// EA  : 0x82E295F0
// RVA : 0x00E295F0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::GetAimPoint(idPlayer *this, aimPoint_t type, idVec3 *pos)
{
  idVehicle *v6; // r3
  idVehicleOccupant *OccupantForEntity; // r3
  idPhysics *Physics; // r3
  int v9; // r3
  char *v10; // r10
  _DWORD *v11; // r11
  int i; // ctr
  idPhysics *v13; // r3
  float *v14; // r3
  idPhysics *v15; // r3
  float *v16; // r3
  idPhysics *v17; // r3
  double y; // fp12
  double v19; // fp6
  double z; // fp11
  double v21; // fp5
  idPhysics *v22; // r3
  float *v23; // r3
  double v24; // fp6
  double v25; // fp7
  idVec3 v26; // [sp+50h] [-60h] BYREF
  char v27; // [sp+5Ch] [-54h] BYREF
  _BYTE v28[8]; // [sp+60h] [-50h] BYREF
  float v29; // [sp+68h] [-48h]
  float v30; // [sp+74h] [-3Ch]

  v6 = (idVehicle *)this->GetVehicle(this);
  if ( v6 != nullptr )
  {
    OccupantForEntity = idVehicle::GetOccupantForEntity(this: v6, entity: this);
    if ( OccupantForEntity == nullptr )
    {
      this->GetViewTransform(this, a2: pos, a3: (idMat3 *)v28);
      return;
    }
    goto LABEL_5;
  }
  OccupantForEntity = (idVehicleOccupant *)idEntity::GetBindMaster(this);
  if ( OccupantForEntity != nullptr )
  {
LABEL_5:
    OccupantForEntity->GetAimPoint(this: OccupantForEntity, a2: type, a3: pos);
    return;
  }
  if ( (unsigned int)(type - 1) > 7 || type == AIMPOINT_TORSO || type == AIMPOINT_CENTER )
    goto LABEL_20;
  switch ( type )
  {
    case AIMPOINT_LEGS:
      Physics = idEntity::GetPhysics(this);
      v9 = (int)Physics->GetAbsBounds(this: Physics, a2: -1);
      v10 = &v27;
      v11 = (_DWORD *)(v9 - 4);
      for ( i = 6; i != 0; --i )
      {
        ++v11;
        v10 += 4;
        *(_DWORD *)v10 = *v11;
      }
      v13 = idEntity::GetPhysics(this);
      v14 = (float *)v13->GetOrigin(this: v13, a2: 0);
      pos->x = *v14;
      pos->y = v14[1];
      pos->z = (float)((float)(v30 - v29) * (float)0.25) + v14[2];
      return;
    case AIMPOINT_FEET:
      v15 = idEntity::GetPhysics(this);
      v16 = (float *)v15->GetOrigin(this: v15, a2: 0);
      pos->x = *v16;
      pos->y = v16[1];
      pos->z = v16[2];
      return;
    case AIMPOINT_BEST:
LABEL_20:
      v22 = idEntity::GetPhysics(this);
      v23 = (float *)v22->GetAbsBounds(this: v22, a2: -1);
      v24 = (float)(v23[2] + v23[5]);
      v25 = (float)(v23[1] + v23[4]);
      pos->x = (float)(*v23 + v23[3]) * (float)0.5;
      pos->z = (float)v24 * (float)0.5;
      pos->y = (float)v25 * (float)0.5;
      return;
    case AIMPOINT_EYELEVEL:
    case AIMPOINT_HEAD:
      this->GetEyePos(this, a2: pos);
      break;
    default:
      this->GetEyePos(this, a2: pos);
      v17 = idEntity::GetPhysics(this);
      v17->GetLinearVelocity(this: (idPhysics *)&v26, result: (idVec3 *)v17, a3: 0);
      idVec3::NormalizeFast(this: &v26);
      y = pos->y;
      v19 = (float)(v26.y * (float)64.0);
      z = pos->z;
      v21 = (float)(v26.z * (float)64.0);
      pos->x = pos->x + (float)(v26.x * (float)64.0);
      pos->y = (float)v19 + (float)y;
      pos->z = (float)z + (float)v21;
      break;
  }
}


// ========================================================================
// ?CalculateView@idPlayer@@QAAXXZ
// EA  : 0x82E29898
// RVA : 0x00E29898
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::CalculateView(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetPlayerInterface_2(this: presentable);
    idPresentablePlayer::CalculateView(this: v2);
  }
  else
  {
    idPresentablePlayer::CalculateView(this: nullptr);
  }
}


// ========================================================================
// ?GetModelTransform@idPlayer@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82E298F0
// RVA : 0x00E298F0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::GetModelTransform(idPlayer *this, idVec3 *modelOrigin, idMat3 *modelAxis)
{
  const idAnimator_AF *v6; // r3
  char v7; // r11
  idAnimator_AF *v8; // r3
  idPresentable *presentable; // r3
  int v10; // r3
  float *v11; // r3
  double z; // fp4
  double v13; // fp9
  double v14; // fp8
  double v15; // fp12
  double v16; // fp11
  double v17; // fp7
  double v18; // fp9
  double v19; // fp8

  v6 = this->GetAF(this);
  if ( v6->isActive || (v7 = 0, v6->isClientAuthoritativeActive) )
    v7 = 1;
  if ( v7 != 0 )
  {
    v8 = (idAnimator_AF *)this->GetAF(this);
    idAnimator_AF::GetModelTransform(this: v8, modelOrigin, modelAxis);
  }
  else
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      v10 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v10 = 0;
    v11 = (float *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)(v10 + 36264) + 64))(a1: v10 + 36264, a2: 0);
    modelAxis->mat[0].x = this->modelAxis.mat[0].x;
    modelAxis->mat[0].y = this->modelAxis.mat[0].y;
    modelAxis->mat[0].z = this->modelAxis.mat[0].z;
    modelAxis->mat[1].x = this->modelAxis.mat[1].x;
    modelAxis->mat[1].y = this->modelAxis.mat[1].y;
    modelAxis->mat[1].z = this->modelAxis.mat[1].z;
    modelAxis->mat[2].x = this->modelAxis.mat[2].x;
    modelAxis->mat[2].y = this->modelAxis.mat[2].y;
    z = this->modelAxis.mat[2].z;
    modelAxis->mat[2].z = this->modelAxis.mat[2].z;
    v13 = *v11;
    v14 = v11[1];
    v15 = (float)((float)(modelAxis->mat[1].x * this->actorConstants.modelInfo.modelOffset.y)
                + (float)((float)(this->actorConstants.modelInfo.modelOffset.x * modelAxis->mat[0].x)
                        + (float)(modelAxis->mat[2].x * this->actorConstants.modelInfo.modelOffset.z)));
    v16 = (float)((float)(modelAxis->mat[0].y * this->actorConstants.modelInfo.modelOffset.x)
                + (float)((float)(modelAxis->mat[1].y * this->actorConstants.modelInfo.modelOffset.y)
                        + (float)(modelAxis->mat[2].y * this->actorConstants.modelInfo.modelOffset.z)));
    v17 = (float)(v11[2]
                + (float)((float)(this->actorConstants.modelInfo.modelOffset.x * modelAxis->mat[0].z)
                        + (float)((float)(modelAxis->mat[1].z * this->actorConstants.modelInfo.modelOffset.y)
                                + (float)((float)z * this->actorConstants.modelInfo.modelOffset.z))));
    modelOrigin->z = v11[2]
                   + (float)((float)(this->actorConstants.modelInfo.modelOffset.x * modelAxis->mat[0].z)
                           + (float)((float)(modelAxis->mat[1].z * this->actorConstants.modelInfo.modelOffset.y)
                                   + (float)((float)z * this->actorConstants.modelInfo.modelOffset.z)));
    v18 = (float)((float)v13 + (float)v15);
    modelOrigin->x = v18;
    v19 = (float)((float)v14 + (float)v16);
    modelOrigin->y = v19;
    modelOrigin->x = this->playerModelOffset.x + (float)v18;
    modelOrigin->y = this->playerModelOffset.y + (float)v19;
    modelOrigin->z = this->playerModelOffset.z + (float)v17;
  }
}


// ========================================================================
// ?HideHands@idPlayer@@QAAXXZ
// EA  : 0x82E29AB0
// RVA : 0x00E29AB0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::HideHands(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v2 = 0;
  idHands::Hide(this: (idHands *)(v2 + 37616), hideReason: HAND_HIDE_GENERIC);
}


// ========================================================================
// ?ShowHands@idPlayer@@QAAXXZ
// EA  : 0x82E29B00
// RVA : 0x00E29B00
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ShowHands(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v2 = 0;
  idHands::Show(this: (idHands *)(v2 + 37616), hideReason: HAND_HIDE_GENERIC);
}


// ========================================================================
// ?AllocPresentable@idPlayer@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
// EA  : 0x82E29B58
// RVA : 0x00E29B58
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPresentablePlayer *__fastcall idPlayer::AllocPresentable(idPlayer *this, idRenderModel *renderModel_)
{
  idPresentablePlayer *v4; // r29
  int entityNumber; // r27
  const idDeclPlayerProps *playerProps; // r26
  idInventoryCollection *v7; // r25
  idAnimStack *v8; // r3

  v4 = (idPresentablePlayer *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xC200u,
                                tag: TAG_PRESENTABLE,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
  if ( v4 == nullptr )
    return nullptr;
  entityNumber = this->entityNumber;
  playerProps = this->playerProps;
  v7 = this->GetInventory_2(this);
  v8 = this->GetAnimStack_2(this);
  return idPresentablePlayer::idPresentablePlayer(
           this: v4,
           ent: this,
           renderModel_,
           animStack_: v8,
           inv: v7,
           props: playerProps,
           entityNum_: entityNumber);
}


// ========================================================================
// __unwind$506036
// EA  : 0x82E29C10
// RVA : 0x00E29C10
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_506036()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?Hide@idPlayer@@UAAXXZ
// EA  : 0x82E29C40
// RVA : 0x00E29C40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::Hide(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r3
  int v5; // r3

  idActor::Hide(this);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  idHands::Hide(this: (idHands *)(v3 + 37616), hideReason: HAND_HIDE_GENERIC);
  idEntity::BecomeInactive(this, flags: 3);
  if ( (*((_BYTE *)this + 12824) & 0x80) == 0 )
    idGameLocal::BotSystems_UnRegisterEntity(this: gameLocal, entity: this);
  v4 = this->presentable;
  *((_BYTE *)this + 12824) |= 0x80u;
  if ( v4 != nullptr )
    v5 = (int)v4->GetPlayerInterface_2(this: v4);
  else
    v5 = 0;
  *(_BYTE *)(v5 + 176) = *((_BYTE *)this + 12824) >> 7;
}


// ========================================================================
// ?Show@idPlayer@@UAAXXZ
// EA  : 0x82E29D08
// RVA : 0x00E29D08
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::Show(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r3
  int v5; // r3
  idPresentable *v6; // r3
  int v7; // r3

  idActor::Show(this);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  idHands::Show(this: (idHands *)(v3 + 37616), hideReason: HAND_HIDE_GENERIC);
  v4 = this->presentable;
  if ( v4 != nullptr )
    v5 = (int)v4->GetPlayerInterface_2(this: v4);
  else
    v5 = 0;
  idHands::Enable(this: (idHands *)(v5 + 37616));
  idEntity::BecomeActive(this, flags: 7);
  if ( (*((_BYTE *)this + 12824) & 0x80) != 0 )
    idGameLocal::BotSystems_RegisterEntity(this: gameLocal, entity: this, entityType: 1, entityFlags: 608);
  v6 = this->presentable;
  *((_BYTE *)this + 12824) &= ~0x80u;
  if ( v6 != nullptr )
    v7 = (int)v6->GetPlayerInterface_2(this: v6);
  else
    v7 = 0;
  *(_BYTE *)(v7 + 176) = *((_BYTE *)this + 12824) >> 7;
}


// ========================================================================
// ?SetSpectating@idPlayer@@QAAX_N@Z
// EA  : 0x82E29E10
// RVA : 0x00E29E10
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetSpectating(idPlayer *this, bool v)
{
  idPresentable *presentable; // r3
  int v5; // r3
  BOOL v6; // r30
  bool v7; // r28
  idPresentable *v8; // r3
  int v9; // r3
  idPlayer_vtbl *v10; // r11
  idPresentable *v11; // r3
  int v12; // r3
  idPresentable *v13; // r3
  int v14; // r3
  idPresentable *v15; // r3
  int v16; // r3
  idPresentable *v17; // r3
  int v18; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  v6 = v;
  *(_BYTE *)(v5 + 47032) = (8 * v) & 8 | *(_BYTE *)(v5 + 47032) & 0xF7;
  v7 = v;
  v8 = this->presentable;
  if ( v8 != nullptr )
    v9 = (int)v8->GetPlayerInterface_2(this: v8);
  else
    v9 = 0;
  *(_BYTE *)(v9 + 47032) = *(_BYTE *)(v9 + 47032) & 0xDF | (32 * v7);
  v10 = this->__vftable;
  if ( v6 )
  {
    v10->Hide_2(this);
    v11 = this->presentable;
    if ( v11 != nullptr )
      v12 = (int)v11->GetPlayerInterface_2(this: v11);
    else
      v12 = 0;
    idHands::Hide(this: (idHands *)(v12 + 37616), hideReason: HAND_HIDE_SERVER_AUTHORITATIVE);
    v13 = this->presentable;
    if ( v13 != nullptr )
      v14 = (int)v13->GetPlayerInterface_2(this: v13);
    else
      v14 = 0;
    idHands::Hide(this: (idHands *)(v14 + 37616), hideReason: HAND_HIDE_SPECTATING);
    idEntity::BecomeActive(this, flags: 1);
  }
  else
  {
    v10->Show(this);
    v15 = this->presentable;
    if ( v15 != nullptr )
      v16 = (int)v15->GetPlayerInterface_2(this: v15);
    else
      v16 = 0;
    idHands::Show(this: (idHands *)(v16 + 37616), hideReason: HAND_HIDE_SERVER_AUTHORITATIVE);
    v17 = this->presentable;
    if ( v17 != nullptr )
    {
      v18 = (int)v17->GetPlayerInterface_2(this: v17);
      idHands::Show(this: (idHands *)(v18 + 37616), hideReason: HAND_HIDE_SPECTATING);
    }
    else
    {
      idHands::Show(this: (idHands *)0x92F0, hideReason: HAND_HIDE_SPECTATING);
    }
  }
}


// ========================================================================
// ?GetPosture@idPlayer@@UBA?AW4posture_t@@XZ
// EA  : 0x82E29FC8
// RVA : 0x00E29FC8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

posture_t __fastcall idPlayer::GetPosture(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPlayer *v4; // r3
  char v5; // r10
  posture_t v6; // r31

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  v5 = _cntlzw((unsigned __int8)idPhysics_Player::IsCrouching(this: (idPhysics_Player *)(v3 + 36264)));
  v4 = this;
  v6 = ((v5 & 0x20) == 0) + 1;
  idActor::SetPosture(this: v4, state: v6);
  return v6;
}


// ========================================================================
// ?Event_StartTimeScaleExperiment@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E2A048
// RVA : 0x00E2A048
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_StartTimeScaleExperiment(idPlayer *this, idEventReceiver *result)
{
  __int64 v4; // r10
  __int64 v5; // r8
  int v6; // r6

  ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
    a1: cvarSystem,
    a2: "timescale",
    a3: (float)(unsigned int)rcbomb_timeInitialScaleAmount.valueInteger);
  LODWORD(v4) = &pb_ss_UpdateAfterPhysics.name;
  HIDWORD(v4) = &idTarget_SoundDuck::Type.node;
  LODWORD(v5) = &rcbomb_timeScaleTickTime;
  idEventReceiver::PostEventMS(
    this: result,
    ev: &EV_TickTimeScale,
    time: rcbomb_timeScaleTickTime.valueInteger,
    a4: v6,
    a5: v5,
    a6: v4);
  return this;
}


// ========================================================================
// ?Event_TickTimeScale@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E2A0E0
// RVA : 0x00E2A0E0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_TickTimeScale(idPlayer *this, idEventReceiver *result)
{
  double v4; // fp1
  __int64 v5; // r8
  double v6; // fp31
  __int64 v7; // r10

  v4 = ((double (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->GetCVarFloat)(
         a1: cvarSystem,
         a2: "timescale",
         a3: 0.0);
  HIDWORD(v5) = &pb_ss_UpdateAfterPhysics.name;
  v6 = (float)(rcbomb_timeScaleAmount.valueFloat + (float)v4);
  if ( v6 < 1.0 )
  {
    LODWORD(v7) = &idTarget_SoundDuck::Type.node;
    HIDWORD(v7) = &rcbomb_timeScaleTickTime;
    idEventReceiver::PostEventMS(
      this: result,
      ev: &EV_TickTimeScale,
      time: rcbomb_timeScaleTickTime.valueInteger,
      a4: 0x82000000,
      a5: v5,
      a6: v7);
  }
  else
  {
    v6 = 1.0;
  }
  ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
    a1: cvarSystem,
    a2: "timescale",
    a3: v6);
  return this;
}


// ========================================================================
// ?Event_EndDeathCameraView@idPlayer@@AAA?AVeventVoid@@H@Z
// EA  : 0x82E2A198
// RVA : 0x00E2A198
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_EndDeathCameraView(idPlayer *this, idPlayer *result, int ms)
{
  idPresentable *presentable; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  idPresentable *v12; // r3
  idVec4 v14; // [sp+50h] [-30h] BYREF

  idPlayer::RemoveControl(this: result, entity: (idPlayer *)result->deathCamera);
  idCamera::Deactivate(this: result->deathCamera);
  presentable = result->presentable;
  v14.x = 0.0;
  v14.y = 0.0;
  v14.z = 0.0;
  v14.w = 1.0;
  if ( presentable != nullptr )
    v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = 0;
  idView::Flash(this: (idView *)(v7 + 16224), color: &v14, time: ms);
  v8 = result->presentable;
  if ( v8 != nullptr )
    v9 = (int)v8->GetPlayerInterface_2(this: v8);
  else
    v9 = 0;
  if ( v9 != -37616 )
  {
    v10 = result->presentable;
    if ( v10 != nullptr )
      v11 = (int)v10->GetPlayerInterface_2(this: v10);
    else
      v11 = 0;
    idHands::Show(this: (idHands *)(v11 + 37616), hideReason: HAND_HIDE_VEHICLE);
  }
  v12 = result->presentable;
  if ( v12 != nullptr )
  {
    v12->GetPlayerInterface_2(this: v12)->view.isBobEnabled = true;
    return this;
  }
  else
  {
    MEMORY[0x4A60] = 1;
    return this;
  }
}


// ========================================================================
// ?Event_EnterVehicle@idPlayer@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82E2A2C8
// RVA : 0x00E2A2C8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_EnterVehicle(idPlayer *this, idEntity *result, idVehicle *entity)
{
  idVehicle *v5; // r3

  v5 = idVehicle::CastTo(c: entity);
  v5->EnterVehicle(this: v5, a2: result, a3: SEAT_MAX);
  return this;
}


// ========================================================================
// ?Event_TrackEntity@idPlayer@@AAA?AVeventVoid@@PAVidEntity@@M@Z
// EA  : 0x82E2A320
// RVA : 0x00E2A320
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_TrackEntity(idPlayer *this, idPlayer *result, idEntity *entity, double percent)
{
  idPresentable *presentable; // r3
  int v9; // r11
  idPhysics *Physics; // r3
  idPresentable *v11; // r11
  idPhysics *v12; // r30
  int v13; // r11
  idPhysics *v14; // r3
  float *v15; // r30
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  float *v17; // r3
  double v18; // fp9
  double v19; // fp7
  double v20; // fp13
  double v21; // fp0
  idVec3 v23; // [sp+50h] [-80h] BYREF
  idAngles v24; // [sp+60h] [-70h] BYREF
  idAngles v25; // [sp+70h] [-60h] BYREF
  idVec3 v26; // [sp+80h] [-50h] BYREF
  idAngles v27; // [sp+90h] [-40h] BYREF

  presentable = result->presentable;
  if ( presentable != nullptr )
    v9 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v9 = 0;
  idVec3::ToAngles(this: &v23, result: (idAngles *)(v9 + 46544));
  idAngles::Normalize180(this: (idAngles *)&v23);
  Physics = idEntity::GetPhysics(this: entity);
  v11 = result->presentable;
  v12 = Physics;
  if ( v11 != nullptr )
    v13 = (int)v11->GetPlayerInterface_2(this: result->presentable);
  else
    v13 = 0;
  v14 = v12;
  GetOrigin = v12->GetOrigin;
  v15 = (float *)(v13 + 46532);
  v17 = (float *)GetOrigin(this: v14, a2: 0);
  v18 = (float)(v17[2] - v15[2]);
  v19 = (float)(v17[1] - v15[1]);
  v27.pitch = *v17 - *v15;
  v27.roll = v18;
  v27.yaw = v19;
  idVec3::ToAngles(this: &v26, result: &v27);
  idAngles::Normalize180(this: (idAngles *)&v26);
  v24.pitch = v26.x - v23.x;
  v24.yaw = v26.y - v23.y;
  v24.roll = v26.z - v23.z;
  idAngles::Normalize180(this: &v24);
  v20 = 89.0;
  v21 = (float)((float)(v24.pitch * (float)percent) + v23.x);
  v25.pitch = (float)(v24.pitch * (float)percent) + v23.x;
  v25.yaw = (float)(v24.yaw * (float)percent) + v23.y;
  v25.roll = (float)(v24.roll * (float)percent) + v23.z;
  if ( v21 > 89.0 || (v20 = -89.0, v21 < -89.0) )
    v25.pitch = v20;
  idPlayer::SetViewAngles(this: result, angles: &v25, force: false);
  return this;
}


// ========================================================================
// ?Event_GetUserButtons@idPlayer@@AAA?AVeventFloat@@XZ
// EA  : 0x82E2A4D8
// RVA : 0x00E2A4D8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_GetUserButtons(idPlayer *this, eventFloat *result, int a3, __int64 a4)
{
  float value; // r3
  int v6; // r11

  value = result[122].value;
  if ( value == 0.0 )
    v6 = 0;
  else
    v6 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(value) + 104))(a1: COERCE_DOUBLE(LODWORD(value)));
  LODWORD(a4) = *(_DWORD *)(v6 + 46312);
  eventFloat::eventFloat((eventFloat *)this, f: (float)a4);
  return this;
}


// ========================================================================
// ?Event_GetUserMove@idPlayer@@AAA?AVeventVector@@XZ
// EA  : 0x82E2A558
// RVA : 0x00E2A558
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_GetUserMove(idPlayer *this, eventVector *result)
{
  float z; // r3
  int v5; // r29
  float v6; // r3
  int v7; // r30
  float v8; // r3
  int v9; // r11
  __int64 v10; // r9
  __int64 v11; // r11
  __int64 v12; // r6
  eventVector v14; // [sp+58h] [-38h] BYREF

  z = result[40].value.z;
  if ( z == 0.0 )
    v5 = 0;
  else
    v5 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(z) + 104))(a1: COERCE_DOUBLE(LODWORD(z)));
  v6 = result[40].value.z;
  if ( v6 == 0.0 )
    v7 = 0;
  else
    v7 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v6) + 104))(a1: COERCE_DOUBLE(LODWORD(v6)));
  v8 = result[40].value.z;
  if ( v8 == 0.0 )
    v9 = 0;
  else
    v9 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v8) + 104))(a1: COERCE_DOUBLE(LODWORD(v8)));
  HIDWORD(v10) = 46320;
  HIDWORD(v11) = *(unsigned __int8 *)(v5 + 46320);
  LODWORD(v12) = SBYTE3(v11);
  HIDWORD(v12) = *(unsigned __int8 *)(v9 + 46318);
  LODWORD(v11) = *(char *)(v7 + 46319);
  LODWORD(v10) = SBYTE3(v12);
  v14.value.z = (float)v12;
  v14.value.y = (float)v11;
  v14.value.x = (float)v10;
  eventVector::eventVector((eventVector *)this, v: &v14);
  return this;
}


// ========================================================================
// ?Event_GetUserAngles@idPlayer@@AAA?AVeventVector@@XZ
// EA  : 0x82E2A668
// RVA : 0x00E2A668
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_GetUserAngles(idPlayer *this, eventVector *result)
{
  float z; // r3
  int v5; // r29
  float v6; // r3
  int v7; // r30
  float v8; // r3
  int v9; // r3
  __int64 v10; // r10
  __int64 v11; // r5
  __int64 v12; // r7
  eventVector v14[4]; // [sp+58h] [-38h] BYREF

  z = result[40].value.z;
  if ( z == 0.0 )
    v5 = 0;
  else
    v5 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(z) + 104))(a1: COERCE_DOUBLE(LODWORD(z)));
  v6 = result[40].value.z;
  if ( v6 == 0.0 )
    v7 = 0;
  else
    v7 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v6) + 104))(a1: COERCE_DOUBLE(LODWORD(v6)));
  v8 = result[40].value.z;
  if ( v8 == 0.0 )
    v9 = 0;
  else
    v9 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(v8) + 104))(a1: COERCE_DOUBLE(LODWORD(v8)));
  HIDWORD(v10) = 46326;
  HIDWORD(v11) = v14;
  LODWORD(v12) = *(__int16 *)(v5 + 46326);
  HIDWORD(v12) = *(unsigned __int16 *)(v9 + 46322);
  LODWORD(v11) = *(__int16 *)(v7 + 46324);
  LODWORD(v10) = SWORD1(v12);
  v14[0].value.x = (float)v10 * (float)0.0054931641;
  v14[0].value.z = (float)v12 * (float)0.0054931641;
  v14[0].value.y = (float)v11 * (float)0.0054931641;
  eventVector::eventVector((eventVector *)this, v: v14);
  return this;
}


// ========================================================================
// ?Event_GetViewAngles@idPlayer@@AAA?AVeventVector@@XZ
// EA  : 0x82E2A788
// RVA : 0x00E2A788
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_GetViewAngles(idPlayer *this, eventVector *result)
{
  float *p_y; // r10
  float *v4; // r11
  int i; // ctr
  float y; // r11
  double v7; // fp6
  float z; // r3
  float *v9; // r3
  idMat3 v11; // [sp+50h] [-60h] BYREF
  float v12; // [sp+74h] [-3Ch]
  float v13; // [sp+78h] [-38h]
  float v14; // [sp+7Ch] [-34h]
  float v15; // [sp+80h] [-30h]
  float v16; // [sp+84h] [-2Ch]
  float v17; // [sp+88h] [-28h]
  float v18; // [sp+8Ch] [-24h]
  float v19; // [sp+90h] [-20h]

  p_y = &v11.mat[2].y;
  v4 = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_y = *++v4;
  y = result[1104].value.y;
  if ( *(_DWORD *)(LODWORD(y) + 1336) != 0 && springCam_UpdateView.valueInteger != 0 )
  {
    v11.mat[2].z = *(float *)(LODWORD(y) + 1356);
    v12 = *(float *)(LODWORD(y) + 1360);
    v13 = *(float *)(LODWORD(y) + 1364);
    v14 = *(float *)(LODWORD(y) + 1368);
    v15 = *(float *)(LODWORD(y) + 1372);
    v16 = *(float *)(LODWORD(y) + 1376);
    v17 = *(float *)(LODWORD(y) + 1380);
    v18 = *(float *)(LODWORD(y) + 1384);
    v7 = *(float *)(LODWORD(y) + 1388);
  }
  else
  {
    z = result[40].value.z;
    if ( z == 0.0 )
      v9 = nullptr;
    else
      v9 = (float *)(*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(z) + 104))(a1: COERCE_DOUBLE(LODWORD(z)));
    v11.mat[2].z = v9[11636];
    v12 = v9[11637];
    v13 = v9[11638];
    v14 = v9[11639];
    v15 = v9[11640];
    v16 = v9[11641];
    v17 = v9[11642];
    v18 = v9[11643];
    v7 = v9[11644];
  }
  v19 = v7;
  idMat3::ToAngles(this: &v11, result: (idAngles *)&v11.mat[2].z);
  v11.mat[1].y = v11.mat[0].x;
  v11.mat[1].z = v11.mat[0].y;
  v11.mat[2].x = v11.mat[0].z;
  eventVector::eventVector((eventVector *)this, v: (eventVector *)&v11.mat[1].y);
  return this;
}


// ========================================================================
// ?Event_SetViewAngles@idPlayer@@AAA?AVeventVoid@@ABVidAngles@@@Z
// EA  : 0x82E2A8F8
// RVA : 0x00E2A8F8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_SetViewAngles(idPlayer *this, idPlayer *result, idAngles *vAngles)
{
  idPlayer::SetViewAngles(this: result, angles: vAngles, force: false);
  return this;
}


// ========================================================================
// ?Event_GetViewPos@idPlayer@@AAA?AVeventVector@@XZ
// EA  : 0x82E2A938
// RVA : 0x00E2A938
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_GetViewPos(idPlayer *this, eventVector *result)
{
  float z; // r3
  int v4; // r3
  float v5; // r9
  float v6; // r8
  eventVector v8; // [sp+50h] [-20h] BYREF

  z = result[40].value.z;
  if ( z == 0.0 )
    v4 = 0;
  else
    v4 = (*(int (__fastcall **)(double))(*(_DWORD *)LODWORD(z) + 104))(a1: COERCE_DOUBLE(LODWORD(z)));
  v5 = *(float *)(v4 + 46536);
  v6 = *(float *)(v4 + 46540);
  v8.value.x = *(float *)(v4 + 46532);
  v8.value.y = v5;
  v8.value.z = v6;
  eventVector::eventVector((eventVector *)this, v: &v8);
  return this;
}


// ========================================================================
// ?Event_CompleteJob@idPlayer@@AAA?AVeventBool@@PBVidDeclJob@@@Z
// EA  : 0x82E2A9B8
// RVA : 0x00E2A9B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_CompleteJob(idPlayer *this, eventBool *result, idStrId *jobDecl)
{
  char v6; // r3

  if ( jobDecl != nullptr
    && (idDeclInfoTemplate<idDeclJob> *)(*(int (__fastcall **)(idStrId *))(jobDecl->index + 32))(a1: jobDecl) == &idDeclJob::resourceList )
  {
    v6 = idJobManager::CompleteJob(
           this: (idJobManager *)&result[12412],
           jobDecl,
           completeTree: false,
           giveJob: true,
           force: false);
    eventBool::eventBool((eventBool *)this, b: v6);
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idPlayer::Event_CompleteJob",
      decl: (const idDecl *)jobDecl,
      declInfo: &idDeclJob::resourceList);
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
}


// ========================================================================
// ?Event_UnCompleteJob@idPlayer@@AAA?AVeventBool@@PBVidDeclJob@@@Z
// EA  : 0x82E2AA58
// RVA : 0x00E2AA58
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_UnCompleteJob(idPlayer *this, eventBool *result, const idDeclJob *jobDecl)
{
  char v6; // r3

  if ( jobDecl != nullptr && jobDecl->GetDeclInfo(this: jobDecl) == &idDeclJob::resourceList )
  {
    v6 = idJobManager::UnCompleteJob(this: (idJobManager *)&result[12412], jobDecl);
    eventBool::eventBool((eventBool *)this, b: v6);
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idPlayer::Event_UnCompleteJob",
      decl: jobDecl,
      declInfo: &idDeclJob::resourceList);
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
}


// ========================================================================
// ?Event_AcceptJob@idPlayer@@AAA?AVeventBool@@PBVidDeclJob@@@Z
// EA  : 0x82E2AAF0
// RVA : 0x00E2AAF0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_AcceptJob(idPlayer *this, eventBool *result, idStrId *jobDecl)
{
  char v6; // r3

  if ( jobDecl != nullptr
    && (idDeclInfoTemplate<idDeclJob> *)(*(int (__fastcall **)(idStrId *))(jobDecl->index + 32))(a1: jobDecl) == &idDeclJob::resourceList )
  {
    v6 = idJobManager::AcceptJob(this: (idJobManager *)&result[12412], jobDecl, completeTree: false, force: false);
    eventBool::eventBool((eventBool *)this, b: v6);
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idPlayer::Event_AcceptJob",
      decl: (const idDecl *)jobDecl,
      declInfo: &idDeclJob::resourceList);
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
}


// ========================================================================
// ?Event_FailJob@idPlayer@@AAA?AVeventBool@@PBVidDeclJob@@@Z
// EA  : 0x82E2AB90
// RVA : 0x00E2AB90
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_FailJob(idPlayer *this, eventBool *result, const idDeclJob *jobDecl)
{
  char v6; // r3

  if ( jobDecl != nullptr && jobDecl->GetDeclInfo(this: jobDecl) == &idDeclJob::resourceList )
  {
    v6 = idJobManager::FailJob(this: (idJobManager *)&result[12412], jobDecl);
    eventBool::eventBool((eventBool *)this, b: v6);
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idPlayer::Event_FailJob",
      decl: jobDecl,
      declInfo: &idDeclJob::resourceList);
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
}


// ========================================================================
// ?Event_IsJobComplete@idPlayer@@AAA?AVeventBool@@PBVidDeclJob@@@Z
// EA  : 0x82E2AC28
// RVA : 0x00E2AC28
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_IsJobComplete(idPlayer *this, eventBool *result, const idDeclJob *jobDecl)
{
  bool IsJobComplete; // r3

  if ( jobDecl != nullptr && jobDecl->GetDeclInfo(this: jobDecl) == &idDeclJob::resourceList )
  {
    IsJobComplete = idJobManager::IsJobComplete(this: (idJobManager *)&result[12412], jobDecl);
    eventBool::eventBool((eventBool *)this, b: IsJobComplete);
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idPlayer::Event_IsJobComplete",
      decl: jobDecl,
      declInfo: &idDeclJob::resourceList);
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
}


// ========================================================================
// ?Event_IsJobAccepted@idPlayer@@AAA?AVeventBool@@PBVidDeclJob@@@Z
// EA  : 0x82E2ACC0
// RVA : 0x00E2ACC0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_IsJobAccepted(idPlayer *this, eventBool *result, const idDeclJob *jobDecl)
{
  bool IsJobAccepted; // r3

  if ( jobDecl != nullptr && jobDecl->GetDeclInfo(this: jobDecl) == &idDeclJob::resourceList )
  {
    IsJobAccepted = idJobManager::IsJobAccepted(this: (idJobManager *)&result[12412], jobDecl);
    eventBool::eventBool((eventBool *)this, b: IsJobAccepted);
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idPlayer::Event_IsJobAccepted",
      decl: jobDecl,
      declInfo: &idDeclJob::resourceList);
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
}


// ========================================================================
// ?Event_IsJobReadyToTurnIn@idPlayer@@AAA?AVeventBool@@PBVidDeclJob@@@Z
// EA  : 0x82E2AD58
// RVA : 0x00E2AD58
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_IsJobReadyToTurnIn(idPlayer *this, eventBool *result, const idDeclJob *jobDecl)
{
  char IsJobReadyToTurnIn; // r3

  if ( jobDecl != nullptr && jobDecl->GetDeclInfo(this: jobDecl) == &idDeclJob::resourceList )
  {
    IsJobReadyToTurnIn = idJobManager::IsJobReadyToTurnIn(this: (idJobManager *)&result[12412], jobDecl);
    eventBool::eventBool((eventBool *)this, b: IsJobReadyToTurnIn);
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idPlayer::Event_IsJobReadyToTurnIn",
      decl: jobDecl,
      declInfo: &idDeclJob::resourceList);
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
}


// ========================================================================
// ?Event_IsJobInProgress@idPlayer@@AAA?AVeventBool@@PBVidDeclJob@@@Z
// EA  : 0x82E2ADF0
// RVA : 0x00E2ADF0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_IsJobInProgress(idPlayer *this, eventBool *result, const idDeclJob *jobDecl)
{
  bool IsJobInProgress; // r3

  if ( jobDecl != nullptr && jobDecl->GetDeclInfo(this: jobDecl) == &idDeclJob::resourceList )
  {
    IsJobInProgress = idJobManager::IsJobInProgress(this: (idJobManager *)&result[12412], jobDecl);
    eventBool::eventBool((eventBool *)this, b: IsJobInProgress);
    return this;
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idPlayer::Event_IsJobInProgress",
      decl: jobDecl,
      declInfo: &idDeclJob::resourceList);
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
}


// ========================================================================
// ?Event_IsJobReadyToComplete@idPlayer@@AAA?AVeventBool@@PBVidDeclJob@@PBVidEntity@@@Z
// EA  : 0x82E2AE88
// RVA : 0x00E2AE88
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_IsJobReadyToComplete(
        idPlayer *this,
        eventBool *result,
        const idDeclJob *jobDecl,
        idAI2 *npc)
{
  idAI2 *v8; // r5
  char IsJobReadyToComplete; // r3

  if ( jobDecl != nullptr && jobDecl->GetDeclInfo(this: jobDecl) == &idDeclJob::resourceList )
  {
    v8 = idAI2::CastTo(c: npc);
    if ( v8 != nullptr )
    {
      IsJobReadyToComplete = idJobManager::IsJobReadyToComplete(this: (idJobManager *)&result[12412], jobDecl, npc: v8);
      eventBool::eventBool((eventBool *)this, b: IsJobReadyToComplete);
      return this;
    }
  }
  else
  {
    idEventDef::InvalidDeclWarning(
      eventName: "idPlayer::Event_IsJobReadyToComplete",
      decl: jobDecl,
      declInfo: &idDeclJob::resourceList);
  }
  eventBool::eventBool((eventBool *)this, b: false);
  return this;
}


// ========================================================================
// ?Event_SetGameStateInt@idPlayer@@AAA?AVeventVoid@@PBDH@Z
// EA  : 0x82E2AF38
// RVA : 0x00E2AF38
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_SetGameStateInt(
        idPlayer *this,
        eventVoid *result,
        const char *gameStateName,
        int inValue)
{
  idJobManager::SetGameStateIntValue(this: (idJobManager *)&result[12412], name: gameStateName, stateValue: inValue);
  return this;
}


// ========================================================================
// ?Event_Camera_InitSprings@idPlayer@@AAA?AVeventVoid@@M@Z
// EA  : 0x82E2AF78
// RVA : 0x00E2AF78
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Camera_InitSprings(idPlayer *this, eventVoid *result, double k)
{
  idSpringCamera::InitSprings(this: *(idSpringCamera **)&result[13252], k);
  return this;
}


// ========================================================================
// ?Event_Camera_InitDefaultSprings@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E2AFB0
// RVA : 0x00E2AFB0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Camera_InitDefaultSprings(idPlayer *this, eventVoid *result)
{
  idSpringCamera::InitDefaultSprings(this: *(idSpringCamera **)&result[13252]);
  return this;
}


// ========================================================================
// ?Event_Camera_FollowEntity@idPlayer@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82E2AFE8
// RVA : 0x00E2AFE8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Camera_FollowEntity(idPlayer *this, idEntity *result, idEntity *entity)
{
  idSpringCamera::SetFollowTarget(this: (idSpringCamera *)LODWORD(result[16].dormancy.distance), entity);
  idCamera::Activate(this: (idCamera *)LODWORD(result[16].dormancy.distance), activator_: result);
  return this;
}


// ========================================================================
// ?Event_Camera_FollowEntityJoint@idPlayer@@AAA?AVeventVoid@@PAVidEntity@@PBDW4duration_t@idSpringCamera@@@Z
// EA  : 0x82E2B038
// RVA : 0x00E2B038
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Camera_FollowEntityJoint(
        idPlayer *this,
        idEntity *result,
        idAnimatedEntity *entity,
        const char *jointName,
        __int32 duration)
{
  idAnimatedEntity *v9; // r3
  idEntity *v10; // r30
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3

  v9 = idAnimatedEntity::CastTo(c: entity);
  v10 = v9;
  if ( v9 != nullptr )
  {
    TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v9);
    idSpringCamera::SetFollowTarget(
      this: (idSpringCamera *)LODWORD(result[16].dormancy.distance),
      entity: v10,
      ta: TreeAnimatorFromPresentable,
      jointName,
      duration);
    idCamera::Activate(this: (idCamera *)LODWORD(result[16].dormancy.distance), activator_: result);
  }
  else
  {
    idLib::Warning(fmt: "event_viewSpring_FollowEntityJoint: entity must be an idAnimatedEntity");
  }
  return this;
}


// ========================================================================
// ?Event_Camera_EndFollowEntity@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E2B0B8
// RVA : 0x00E2B0B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Camera_EndFollowEntity(idPlayer *this, eventVoid *result)
{
  idSpringCamera::ClearFollowTarget(this: *(idSpringCamera **)&result[13252]);
  return this;
}


// ========================================================================
// ?Event_Camera_TrackEntity@idPlayer@@AAA?AVeventVoid@@PAVidEntity@@@Z
// EA  : 0x82E2B0F0
// RVA : 0x00E2B0F0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Camera_TrackEntity(idPlayer *this, idEntity *result, idEntity *entity)
{
  idSpringCamera::SetLookTarget(this: (idSpringCamera *)LODWORD(result[16].dormancy.distance), entity);
  idCamera::Activate(this: (idCamera *)LODWORD(result[16].dormancy.distance), activator_: result);
  return this;
}


// ========================================================================
// ?Event_Camera_TrackEntityJoint@idPlayer@@AAA?AVeventVoid@@PAVidEntity@@PBDW4duration_t@idSpringCamera@@W4lookMode_t@5@@Z
// EA  : 0x82E2B140
// RVA : 0x00E2B140
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Camera_TrackEntityJoint(
        idPlayer *this,
        idEntity *result,
        idAnimatedEntity *entity,
        const char *jointName,
        __int32 duration,
        idSpringCamera::lookMode_t lookMode)
{
  idAnimatedEntity *v11; // r3
  idEntity *v12; // r30
  idIndex<short,enum invalidJointIndex_t> *TreeAnimatorFromPresentable; // r3

  v11 = idAnimatedEntity::CastTo(c: entity);
  v12 = v11;
  if ( v11 != nullptr )
  {
    TreeAnimatorFromPresentable = (idIndex<short,enum invalidJointIndex_t> *)idAnimatedEntity::GetTreeAnimatorFromPresentable(this: v11);
    idSpringCamera::SetLookTarget(
      this: (idSpringCamera *)LODWORD(result[16].dormancy.distance),
      entity: v12,
      ta: TreeAnimatorFromPresentable,
      jointName,
      duration,
      mode: lookMode);
    idCamera::Activate(this: (idCamera *)LODWORD(result[16].dormancy.distance), activator_: result);
  }
  else
  {
    idLib::Warning(fmt: "event_viewSpring_TrackEntityJoint: entity must be an idAnimatedEntity");
  }
  return this;
}


// ========================================================================
// ?Event_Camera_EndTrackEntity@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E2B1C8
// RVA : 0x00E2B1C8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Camera_EndTrackEntity(idPlayer *this, eventVoid *result)
{
  idSpringCamera::ClearLookTarget(this: *(idSpringCamera **)&result[13252]);
  return this;
}


// ========================================================================
// ?GetFXMgrForAttachment@idPlayer@@UAAPAVidFXManager@@PAVidInventoryItem@@@Z
// EA  : 0x82E2B200
// RVA : 0x00E2B200
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idFXManager *__fastcall idPlayer::GetFXMgrForAttachment(idPlayer *this, idInventoryItem *item)
{
  idPresentable *presentable; // r3
  equipSlot_t equipSlot; // r31
  int v4; // r3
  idHandsItem *v5; // r3

  if ( item != nullptr
    && ((presentable = this->presentable, equipSlot = item->decl->equipSlot, presentable == nullptr)
      ? (v4 = 0)
      : (v4 = (int)presentable->GetPlayerInterface_2(this: presentable)),
        (v5 = idHands::ItemForSlot(this: (idHands *)(v4 + 37616), slot: equipSlot)) != nullptr) )
  {
    return idHandsItem::GetFXMgr(this: v5);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?EquipItem@idPlayer@@QAA_NPAVidInventoryItem@@@Z
// EA  : 0x82E2B290
// RVA : 0x00E2B290
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::EquipItem(idPlayer *this, idWeapon *item)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = nullptr;
  return idPresentablePlayer::EquipItem(this: v4, item);
}


// ========================================================================
// ?Server_EquipItem@idPlayer@@QAA_NPAVidInventoryItem@@W4equipSlot_t@@@Z
// EA  : 0x82E2B2E8
// RVA : 0x00E2B2E8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::Server_EquipItem(idPlayer *this, idWeapon *item, __int32 slot)
{
  int v7; // r26
  idWeapon *v8; // r28
  idPresentable *presentable; // r3
  int v10; // r3
  idHandsItem *v11; // r3
  idHandsItem *v12; // r31
  idTreeAnimator *TreeAnimatorFromPresentable; // r30
  idPresentableAnimatedEntity *v14; // r3
  idPresentable *v15; // r3
  int v16; // r3
  idHands *v17; // r31
  idPresentableAnimatedEntity *v18; // r3

  if ( item == nullptr )
    return 0;
  if ( common->IsClient(this: common) )
    return idActor::EquipItem(this, item, equipSlot: (equipSlot_t)slot);
  v7 = idActor::EquipItem(this, item, equipSlot: (equipSlot_t)slot);
  v8 = idWeapon::CastTo(c: item);
  if ( v8 != nullptr )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      v10 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v10 = 0;
    v11 = idHands::ItemForSlot(this: (idHands *)(v10 + 37616), (const equipSlot_t)slot);
    v12 = v11;
    if ( v11 != nullptr )
    {
      TreeAnimatorFromPresentable = idHandsItem::GetTreeAnimatorFromPresentable(this: v11);
      if ( idHandsItem::GetPresentable(this: v12) != nullptr )
      {
        v14 = idHandsItem::GetPresentable(this: v12);
        idPresentable::UpdateModelTransform(this: v14);
      }
      if ( TreeAnimatorFromPresentable != nullptr )
      {
        v8->UpdateHiddenMeshes(this: v8, a2: TreeAnimatorFromPresentable);
        TreeAnimatorFromPresentable->g.allowSurfaceOnlyInViewID = this->entityNumber + 1;
      }
    }
    v15 = this->presentable;
    if ( v15 != nullptr )
      v16 = (int)v15->GetPlayerInterface_2(this: v15);
    else
      v16 = 0;
    v17 = (idHands *)(v16 + 37616);
    if ( v16 != -37616 )
    {
      idHands::GetTreeAnimatorFromPresentable(this: (idHands *)(v16 + 37616));
      if ( idHands::GetPresentable(this: v17) != nullptr )
      {
        v18 = idHands::GetPresentable(this: v17);
        idPresentable::UpdateModelTransform(this: v18);
      }
    }
  }
  return v7;
}


// ========================================================================
// ?CanRevive@idPlayer@@QBA_NXZ
// EA  : 0x82E2B460
// RVA : 0x00E2B460
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::CanRevive(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v2 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v2 = 0;
  return (*(_BYTE *)(v2 + 47032) & 4) != 0;
}


// ========================================================================
// ?InventoryAdded@idPlayer@@UAAXPAVidInventoryItem@@H@Z
// EA  : 0x82E2B4D0
// RVA : 0x00E2B4D0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::InventoryAdded(idPlayer *this, idActorModifierItem *item, int count)
{
  idPresentable *presentable; // r3
  int v6; // r3
  idActorModifierManager *v7; // r3
  idVehicleUpgrade *v8; // r27
  idInventoryCollection *v9; // r28
  int i; // r29
  idVehicleKey *InventoryItem; // r3
  idVehicleKey *v12; // r3
  idVehicleKey *v13; // r31

  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  idJobManager::NotifyInventoryAdded(this: &this->jobManager, item);
  presentable = this->presentable;
  if ( presentable == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    presentable = this->presentable;
  }
  v6 = (int)presentable->GetActorInterface_2(this: presentable);
  v7 = (idActorModifierManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v6 + 360))(a1: v6);
  idActorModifierManager::InventoryItemAdded(this: v7, item, owner: this);
  v8 = idVehicleUpgrade::CastTo(c: (idVehicleUpgrade *)item);
  if ( v8 != nullptr )
  {
    v9 = this->GetInventory_2(this);
    for ( i = 0; i < (int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v9); ++i )
    {
      InventoryItem = (idVehicleKey *)idInventoryCollection::GetInventoryItem(this: v9, index: i);
      v12 = idVehicleKey::CastTo(c: InventoryItem);
      v13 = v12;
      if ( v12 != nullptr && idVehicleKey::IsValidUpgrade(this: v12, upgrade: v8) )
      {
        v13->upgradeAvailable = true;
        if ( (*((_BYTE *)this + 12824) & 2) == 0 )
          idVehicleKey::EquipUpgradeIfBetter(this: v13, upgrade: v8);
      }
    }
  }
}


// ========================================================================
// ?InventoryRemoved@idPlayer@@UAAXPAVidInventoryItem@@@Z
// EA  : 0x82E2B5E8
// RVA : 0x00E2B5E8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::InventoryRemoved(idPlayer *this, idInventoryItem *item)
{
  idPresentable *presentable; // r3
  int v5; // r3
  idActorModifierManager *v6; // r3

  idActor::InventoryRemoved(this, item);
  if ( common->IsServer(this: common) )
  {
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v5 = (int)presentable->GetActorInterface_2(this: presentable);
    v6 = (idActorModifierManager *)(*(int (__fastcall **)(int))(*(_DWORD *)v5 + 360))(a1: v5);
    idActorModifierManager::InventoryItemRemoved(this: v6, item, owner: this);
  }
}


// ========================================================================
// ?EnteredVehicle@idPlayer@@QAAXPAVidVehicle@@@Z
// EA  : 0x82E2B688
// RVA : 0x00E2B688
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::EnteredVehicle(idPlayer *this, idVehicle *veh)
{
  idPresentable *presentable; // r3
  int v4; // r3
  idHands *v5; // r3

  idEntity::StopSound(this, channel: SND_CHANNEL_BREATHE, peerMask: 0xFFu);
  idEntity::StopSound(this, channel: SND_CHANNEL_ITEM, peerMask: 0xFFu);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  v5 = (idHands *)(v4 + 37616);
  if ( v5 != nullptr )
    idHands::Reset(this: v5, doIntro: false);
}


// ========================================================================
// ?ExitedVehicle@idPlayer@@QAAXXZ
// EA  : 0x82E2B708
// RVA : 0x00E2B708
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ExitedVehicle(idPlayer *this)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v2; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v2 = presentable->GetPlayerInterface_2(this: presentable);
    idPresentablePlayer::ExitedVehicle(this: v2);
  }
  else
  {
    idPresentablePlayer::ExitedVehicle(this: nullptr);
  }
}


// ========================================================================
// ?Event_DevMap@idPlayer@@AAA?AVeventVoid@@PBD000@Z
// EA  : 0x82E2B760
// RVA : 0x00E2B760
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_DevMap(
        idPlayer *this,
        eventVoid *result,
        const char *mapName,
        const char *spawnSpot,
        const char *layersActive,
        const char *layersDeactive)
{
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r10
  va *v13; // r3
  int v15; // [sp+8h] [-1078h]
  int v16; // [sp+Ch] [-1074h]
  int v17; // [sp+10h] [-1070h]
  int v18; // [sp+14h] [-106Ch]
  int v19; // [sp+18h] [-1068h]
  int v20; // [sp+1Ch] [-1064h]
  va v21; // [sp+50h] [-1030h] BYREF

  idCVar::SetString(this: &si_nextlayeractive, newValue: layersActive, force: true);
  idCVar::SetString(this: &si_nextlayerdeactive, newValue: layersDeactive, force: true);
  idCVar::SetString(this: &si_spawnspot, newValue: spawnSpot, force: true);
  LODWORD(v10) = "ame: %s\n";
  HIDWORD(v11) = mapName;
  v13 = va::va(
          this: &v21,
          fmt: "devcmap %s\n",
          a3: v11,
          a4: v10,
          a5: v12,
          a6: v15,
          a7: v16,
          a8: v17,
          a9: v18,
          a10: v19,
          a11: v20);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v13->buffer);
  return this;
}


// ========================================================================
// ?Event_Kill@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E2B7F8
// RVA : 0x00E2B7F8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Kill(idPlayer *this, eventVoid *result)
{
  if ( (*(unsigned __int8 (__fastcall **)(eventVoid *))(*(_DWORD *)&result[12168] + 88))(a1: result + 12168) == 0
    && gameLocal->damageSuicide != nullptr )
  {
    (*(void (__fastcall **)(eventVoid *, eventVoid *, eventVoid *, double))(*(_DWORD *)result + 312))(
      a1: result,
      a2: result,
      a3: result,
      a4: 1.0);
  }
  return this;
}


// ========================================================================
// ?Event_VehicleKill@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E2B8A0
// RVA : 0x00E2B8A0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_VehicleKill(idPlayer *this, eventVoid *result)
{
  if ( (*(unsigned __int8 (__fastcall **)(eventVoid *))(*(_DWORD *)&result[12168] + 88))(a1: result + 12168) == 0
    && gameLocal->damageVehicleExplode != nullptr )
  {
    (*(void (__fastcall **)(eventVoid *, eventVoid *, eventVoid *, double))(*(_DWORD *)result + 312))(
      a1: result,
      a2: result,
      a3: result,
      a4: 1.0);
  }
  return this;
}


// ========================================================================
// ?Event_GetLastOfferChoice@idPlayer@@AAA?AVeventInt@@XZ
// EA  : 0x82E2B948
// RVA : 0x00E2B948
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_GetLastOfferChoice(idPlayer *this, eventInt *result)
{
  eventInt::eventInt((eventInt *)this, i: result[3143].value);
  return this;
}


// ========================================================================
// ?Event_EndSpecificTutorial@idPlayer@@AAA?AVeventVoid@@PBVidDeclTutorialEvent@@@Z
// EA  : 0x82E2B980
// RVA : 0x00E2B980
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_EndSpecificTutorial(
        idPlayer *this,
        eventVoid *result,
        const idDeclTutorialEvent *decl)
{
  int v4; // r3
  idPresentablePlayer *v6; // r3

  v4 = *(_DWORD *)&result[488];
  if ( v4 != 0 )
    v6 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v4 + 104))(a1: v4);
  else
    v6 = nullptr;
  idPresentablePlayer::HideSpecificTutorialGui(this: v6, decl);
  return this;
}


// ========================================================================
// ?ToggleZoom@idPlayer@@QAAX_N@Z
// EA  : 0x82E2B9E8
// RVA : 0x00E2B9E8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ToggleZoom(idPlayer *this, bool z)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = nullptr;
  idPresentablePlayer::ToggleZoom(this: v4, z);
}


// ========================================================================
// ?ActivateCinematicCamera@idPlayer@@QAAXPBVidDeclCameraTrigger@@PAVidEntity@@@Z
// EA  : 0x82E2BA40
// RVA : 0x00E2BA40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ActivateCinematicCamera(
        idPlayer *this,
        const idDeclCameraTrigger *cameraTriggerDecl,
        idVehicleAI *activator)
{
  idSlowMotionCamera *slowMotionCamera; // r30
  idEntity *Control; // r3

  slowMotionCamera = this->slowMotionCamera;
  if ( slowMotionCamera != nullptr
    && activator != nullptr
    && (unsigned __int8)idSlowMotionCamera::SetTriggers(
                          this: this->slowMotionCamera,
                          decl: cameraTriggerDecl,
                          activator_: activator,
                          player: this) != 0 )
  {
    Control = idPlayer::GetControl(this);
    idCamera::Activate(this: slowMotionCamera, activator_: Control);
  }
}


// ========================================================================
// ?GetCoverCheckEyePoint@idPlayer@@IBA?AVidVec3@@H@Z
// EA  : 0x82E2BAB0
// RVA : 0x00E2BAB0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::GetCoverCheckEyePoint(idPlayer *this, idVec3 *result, int coverIndex)
{
  int v4; // r3
  int v5; // r6
  double v6; // fp13
  idPlayer *v7; // r3
  double v8; // fp0

  v4 = (*(int (__fastcall **)(_DWORD, _DWORD))(*(_DWORD *)LODWORD(result[1946].z) + 264))(
         a1: LODWORD(result[1946].z),
         a2: *(_DWORD *)(LODWORD(result[1948].y) + 16 * coverIndex));
  v5 = *(_WORD *)(v4 + 26) & 1;
  v6 = *(float *)(v4 + 8);
  this->__vftable = *(idPlayer_vtbl **)v4;
  this->listenerList = *(idList<idEventReceiver *,5> **)(v4 + 4);
  v7 = this;
  if ( v5 != 0 )
    v8 = 56.0;
  else
    v8 = 90.0;
  *(float *)&this->listeningToList = (float)v6 + (float)v8;
  return v7;
}


// ========================================================================
// ?GetFiringPoint@idPlayer@@IAA_NW4firePoint_t@1@HHAAVidVec3@@@Z
// EA  : 0x82E2BB40
// RVA : 0x00E2BB40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::GetFiringPoint(
        idPlayer *this,
        unsigned int fp,
        int i,
        int coverFlags,
        idEventReceiver *firePointLocation)
{
  const aas2Cover_t *v9; // r31
  double x; // fp30
  double y; // fp29
  double z; // fp28
  const idAAS2Settings *v13; // r3
  double v14; // fp6
  double v15; // fp5
  double v16; // fp4
  double v19; // fp9
  double v20; // fp12
  double v21; // fp9
  double v22; // fp30
  double v23; // fp29
  double v24; // fp28
  float *v25; // r3
  double v26; // fp27
  double v27; // fp26
  double v28; // fp31
  double v29; // fp31
  __int16 flags; // r7
  bool v31; // r10
  bool v32; // r6
  char v33; // r9
  bool v34; // r8
  bool v35; // r7
  double v36; // fp13
  double v38; // fp11
  double v39; // fp8
  double v40; // fp7
  double v41; // fp6
  char v42; // [sp+50h] [-90h] BYREF

  v9 = this->aas->GetCoverPoint(this: this->aas, a2: this->playerCoverScores.list[i].coverIndex);
  x = v9->dir.x;
  y = v9->dir.y;
  z = v9->dir.z;
  v13 = this->aas->GetSettings(this: this->aas);
  v14 = (float)((float)(v13->gravityDir.x * (float)y) - (float)(v13->gravityDir.y * (float)x));
  v15 = (float)((float)(v13->gravityDir.z * (float)x) - (float)(v13->gravityDir.x * (float)z));
  v16 = (float)((float)(v13->gravityDir.y * (float)z) - (float)(v13->gravityDir.z * (float)y));
  _FP12 = (float)((float)((float)((float)v16 * (float)v16)
                        + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
                - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f10, f12, f1, f13 }
  v19 = __frsqrte(_FP10);
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19)
                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                              + (float)((float)((float)v15 * (float)v15)
                                                                      + (float)((float)v14 * (float)v14)))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v19
                                                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                                                              + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
                                                                                      * (float)0.5))
                                                                      * (float)v19)
                                                              - (float)1.5)
                                              * (float)v19))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v19
                                                      * (float)((float)((float)((float)v16 * (float)v16)
                                                                      + (float)((float)((float)v15 * (float)v15)
                                                                              + (float)((float)v14 * (float)v14)))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                              * (float)v19)
                                                                                      * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
                                                                                              * (float)0.5))
                                                                              * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                      * (float)v19))
                                                                      - (float)1.5)
                                                      * (float)((float)-(float)((float)((float)((float)v19
                                                                                              * (float)((float)((float)((float)v16 * (float)v16) + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))) * (float)0.5))
                                                                                      * (float)v19)
                                                                              - (float)1.5)
                                                              * (float)v19))
                                              * (float)((float)((float)((float)v16 * (float)v16)
                                                              + (float)((float)((float)v15 * (float)v15)
                                                                      + (float)((float)v14 * (float)v14)))
                                                      * (float)0.5))
                                      * (float)v20)
                              - (float)1.5)
              * (float)v20);
  v23 = (float)((float)((float)(v13->gravityDir.z * (float)x) - (float)(v13->gravityDir.x * (float)z)) * (float)v21);
  v22 = (float)((float)v21 * (float)v16);
  v24 = (float)((float)v14 * (float)v21);
  v25 = (float *)this->aas->GetSettings(this: this->aas);
  v26 = (float)((float)(v25[25] + v25[28]) * (float)0.5);
  v27 = (float)((float)(v25[26] + v25[29]) * (float)0.5);
  v28 = (float)((float)(v25[27] + v25[30]) * (float)0.5);
  v29 = (float)((float)(this->aas->GetSettings(this: this->aas)->coverCornerDistance
                      + (float)((float)((float)((float)__fabs((float)((float)v23
                                                                    * (float)(v25[29]
                                                                            - (float)((float)(v25[26] + v25[29])
                                                                                    * (float)0.5))))
                                              + (float)__fabs((float)((float)v22
                                                                    * (float)(v25[28]
                                                                            - (float)((float)(v25[25] + v25[28])
                                                                                    * (float)0.5)))))
                                      + (float)__fabs((float)((float)v24
                                                            * (float)(v25[30]
                                                                    - (float)((float)(v25[27] + v25[30]) * (float)0.5)))))
                              + (float)((float)((float)v22 * (float)v26)
                                      + (float)((float)((float)v24 * (float)v28) + (float)((float)v23 * (float)v27)))))
              + (float)4.0);
  *firePointLocation = idPlayer::GetCoverCheckEyePoint(this: (idPlayer *)&v42, result: (idVec3 *)this, coverIndex: i)->idEventReceiver;
  flags = v9->flags;
  v31 = (flags & 0x140) != 0;
  v32 = (flags & 0x200) != 0;
  v33 = flags & 1;
  v34 = (flags & 0x280) != 0;
  v35 = (flags & 0x100) != 0;
  if ( fp == 0 )
  {
    if ( (v33 == 0 || v31) && (v31 || v35) )
    {
      v39 = (float)(*(float *)&firePointLocation->__vftable - (float)((float)v22 * (float)v29));
      v40 = (float)(*(float *)&firePointLocation->listenerList - (float)((float)v23 * (float)v29));
      v41 = (float)(*(float *)&firePointLocation->listeningToList - (float)((float)v24 * (float)v29));
      goto LABEL_18;
    }
    return 0;
  }
  if ( fp != 1 )
  {
    if ( fp < 3 && v33 != 0 && (v9->flags & 0x20) != 0 )
    {
      v36 = v9->origin.z;
      v38 = v9->origin.y;
      *(float *)&firePointLocation->__vftable = v9->origin.x;
      *(float *)&firePointLocation->listenerList = v38;
      *(float *)&firePointLocation->listeningToList = (float)v36 + (float)90.0;
      return 1;
    }
    return 0;
  }
  if ( v33 != 0 && !v34 || !v34 && !v32 )
    return 0;
  v39 = (float)(*(float *)&firePointLocation->__vftable + (float)((float)v22 * (float)v29));
  v40 = (float)(*(float *)&firePointLocation->listenerList + (float)((float)v23 * (float)v29));
  v41 = (float)((float)((float)v24 * (float)v29) + *(float *)&firePointLocation->listeningToList);
LABEL_18:
  *(float *)&firePointLocation->listeningToList = v41;
  *(float *)&firePointLocation->listenerList = v40;
  *(float *)&firePointLocation->__vftable = v39;
  return 1;
}


// ========================================================================
// ?Revive@idPlayer@@QAAXPBV1@@Z
// EA  : 0x82E2C0E8
// RVA : 0x00E2C0E8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::Revive(idPlayer *this, idVehicle *reviver)
{
  idPresentable *presentable; // r3
  int v5; // r3
  idPresentable *v6; // r3
  int v7; // r3
  double v8; // fp1
  __int64 v9; // r8
  __int64 v10; // r10
  int v11; // r6
  idPresentable *v12; // r3
  int v13; // r3
  idPresentable *v14; // r3
  int v15; // r3
  idPresentable *v16; // r3
  const idAngles *v17; // r4
  idPresentable *v18; // r3
  int v19; // r3
  idPresentable *v20; // r3
  int v21; // r3
  idPresentable *v22; // r3
  int v23; // r3
  idPresentable *v24; // r3
  int v25; // r30
  idAngles v26; // [sp+50h] [-90h] BYREF
  float v27[16]; // [sp+60h] [-80h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  if ( (*(_BYTE *)(v5 + 47032) & 4) != 0 )
  {
    v6 = this->presentable;
    if ( v6 != nullptr )
      v7 = (int)v6->GetPlayerInterface_2(this: v6);
    else
      v7 = 0;
    idView::ClearEffects(this: (idView *)(v7 + 16224));
    v8 = ((double (__fastcall *)(idTungstenHealth *))this->playerHealth.GetMaxBaseHealth_Impl)(a1: &this->playerHealth);
    idBaseHealth::SetCurBaseHealth(this: &this->playerHealth, h: (float)(g_coop_revivePCT.valueFloat * (float)v8));
    HIDWORD(v9) = &idTarget_SoundDuck::Type.node;
    idEventReceiver::PostEventMS(this, ev: &EV_EndRevive, time: 0, a4: v11, a5: v9, a6: v10);
    v12 = this->presentable;
    if ( v12 != nullptr )
      v13 = (int)v12->GetPlayerInterface_2(this: v12);
    else
      v13 = 0;
    idPlayerHud::SetHudState(this: (idPlayerHud *)(v13 + 35096), state: HUDSTATE_ALL);
    v14 = this->presentable;
    if ( v14 != nullptr )
      v15 = (int)v14->GetPlayerInterface_2(this: v14);
    else
      v15 = 0;
    *(_BYTE *)(v15 + 35104) = 1;
    v16 = this->presentable;
    if ( v16 != nullptr )
      v17 = (const idAngles *)v16->GetPlayerInterface_2(this: v16);
    else
      v17 = nullptr;
    idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)&v26, result: v17, includeWeaponKick: true);
    v26.roll = 0.0;
    v26.pitch = 0.0;
    idPlayer::SetViewAngles(this, angles: &v26, force: false);
    v18 = this->presentable;
    *(_BYTE *)&this->flags = *(_BYTE *)&this->flags & 0xF9 | 2;
    if ( v18 != nullptr )
      v19 = (int)v18->GetPlayerInterface_2(this: v18);
    else
      v19 = 0;
    idHands::Show(this: (idHands *)(v19 + 37616), hideReason: HAND_HIDE_GENERIC);
    v20 = this->presentable;
    if ( v20 != nullptr )
      v21 = (int)v20->GetPlayerInterface_2(this: v20);
    else
      v21 = 0;
    idHands::Show(this: (idHands *)(v21 + 37616), hideReason: HAND_HIDE_SERVER_AUTHORITATIVE);
    idPlayer::SetForceInhibitControl(this, inhibit: false);
    idPlayer::AddControl(this, entity: this);
    v27[0] = 0.0;
    v27[2] = 0.0;
    v27[13] = 0.0;
    v27[14] = 0.0;
    LODWORD(v27[3]) = 100;
    LODWORD(v27[8]) = 40;
    v27[1] = -60.0;
    v27[5] = -60.0;
    LODWORD(v27[4]) = 200;
    v27[6] = -60.0;
    LODWORD(v27[7]) = 20;
    v27[9] = 1.0;
    v27[12] = 0.0;
    v27[10] = 1.0;
    v27[11] = 5000.0;
    clientGame->soundWorld->OverrideEnvironmentParams(
      this: clientGame->soundWorld,
      a2: (const soundEnvironment_t *)v27,
      a3: this->entityNumber);
    v22 = this->presentable;
    if ( v22 != nullptr )
      v23 = (int)v22->GetPlayerInterface_2(this: v22);
    else
      v23 = 0;
    *(_BYTE *)(v23 + 47032) &= ~4u;
    v24 = this->presentable;
    this->lastIncapacitate = 0;
    if ( v24 != nullptr )
      v25 = (int)v24->GetPlayerInterface_2(this: v24);
    else
      v25 = 0;
    *(_BYTE *)(v25 + 47032) = (this->IsDead(this) << 7) | *(_BYTE *)(v25 + 47032) & 0x7F;
    if ( reviver != nullptr )
      idRageMetrics::PlayerRevived(this: clientGame->rageMetrics, revivedPlayer: (idVehicle *)this, reviver);
  }
}


// ========================================================================
// ?GetUsableState@idPlayer@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
// EA  : 0x82E2C438
// RVA : 0x00E2C438
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

usableState_t __fastcall idPlayer::GetUsableState(idPlayer *this, idPlayer *activator, const idFocusTrace *ft)
{
  usableState_t result; // r3
  bool CanRevive; // zf

  if ( activator == this )
    return USABLE_NOT_USABLE;
  if ( activator->IsDead(this: activator) )
    return USABLE_NOT_USABLE;
  CanRevive = idPlayer::CanRevive(this);
  result = USABLE_LOOT;
  if ( !CanRevive )
    return USABLE_NOT_USABLE;
  return result;
}


// ========================================================================
// ?GetOnlineUsableState@idPlayer@@UBA?AW4usableState_t@@XZ
// EA  : 0x82E2C4A8
// RVA : 0x00E2C4A8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::GetOnlineUsableState(idPlayer *this)
{
  idPresentable *presentable; // r3
  char v2; // r31
  int v3; // r3

  presentable = this->presentable;
  v2 = 0;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  if ( (*(_BYTE *)(v3 + 47032) & 4) != 0 )
    v2 = 1;
  return v2 == 0 ? 0 : 2;
}


// ========================================================================
// ?GetGodMode@idPlayer@@QBA_NXZ
// EA  : 0x82E2C528
// RVA : 0x00E2C528
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::GetGodMode(idPlayer *this)
{
  unsigned __int8 v1; // r11

  if ( (*((_BYTE *)this + 12824) & 0x40) != 0 )
    return 1;
  v1 = 0;
  if ( g_permaGodMode.valueInteger != 0 )
    return 1;
  return v1;
}


// ========================================================================
// ?PlayLocalSound@idPlayer@@QAAXW4soundChannel_t@@PBVidSoundShader@@H@Z
// EA  : 0x82E2C560
// RVA : 0x00E2C560
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::PlayLocalSound(
        idPlayer *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        soundShaderFlags_t soundShaderFlags)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v8; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v8 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v8 = nullptr;
  idPresentablePlayer::PlayLocalSound(this: v8, channel, shader, soundShaderFlags);
}


// ========================================================================
// ?GetSoundTransform@idPlayer@@UBAXAAVidVec3@@AAVidMat3@@@Z
// EA  : 0x82E2C5B8
// RVA : 0x00E2C5B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::GetSoundTransform(idPlayer *this, idVec3 *soundOrigin, idMat3 *soundAxis)
{
  idPresentable *presentable; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = 0;
  if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v7 + 300))(a1: v7) == 0 || pm_thirdPerson.valueInteger != 0 )
  {
    idActor::GetSoundTransform(this, soundOrigin, soundAxis);
  }
  else
  {
    v8 = this->presentable;
    if ( v8 != nullptr )
    {
      v9 = (int)v8->GetPlayerInterface_2(this: v8);
      idView::GetViewPos(this: (idView *)(v9 + 16224), origin: soundOrigin, axis: soundAxis);
    }
    else
    {
      idView::GetViewPos(this: (idView *)0x3F60, origin: soundOrigin, axis: soundAxis);
    }
  }
}


// ========================================================================
// ?ModifyCrosshairInfo@idPlayer@@UBA_NPBVidEntity@@ABVidFocusTrace@@W4usableState_t@@AAVidCrosshairInfo@@@Z
// EA  : 0x82E2C690
// RVA : 0x00E2C690
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::ModifyCrosshairInfo(
        idPlayer *this,
        const idEntity *activator,
        const idFocusTrace *ft,
        const usableState_t usable,
        idCrosshairInfo *info)
{
  if ( usable != USABLE_LOOT )
    return 0;
  idStrId::Set(this: &info->text, key: "#str_online_revive_crosshair_info");
  return 1;
}


// ========================================================================
// ?AnimEvent_ShowThrowItem@idPlayer@@AAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E2C6E0
// RVA : 0x00E2C6E0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::AnimEvent_ShowThrowItem(idPlayer *this, eventVoid *result, const idMD6Anim *animHandle)
{
  int v5; // r28
  int v6; // r29
  const idHandle<int,enum invalidAttachment_t,-1> *v7; // r30
  idAttachmentCollection *v8; // r3
  const idAttachment *v9; // r3

  v5 = 0;
  if ( *(int *)&result[12372] > 0 )
  {
    v6 = 0;
    do
    {
      v7 = (const idHandle<int,enum invalidAttachment_t,-1> *)(v6 + *(_DWORD *)&result[12368]);
      if ( v7->value != -1 )
      {
        v8 = (idAttachmentCollection *)(*(int (__fastcall **)(eventVoid *))(*(_DWORD *)result + 484))(a1: result);
        v9 = idAttachmentCollection::Get(this: v8, handle: v7);
        v9->presentable->Show(this: v9->presentable);
      }
      ++v5;
      v6 += 4;
    }
    while ( v5 < *(_DWORD *)&result[12372] );
  }
  return this;
}


// ========================================================================
// ?SetMaxTension@idPlayer@@QAAXW4tensionType_t@1@@Z
// EA  : 0x82E2C770
// RVA : 0x00E2C770
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetMaxTension(idPlayer *this, idPlayer::tensionType_t tension)
{
  idPlayer::tensionType_t currentPlayerTension; // r11

  currentPlayerTension = this->currentPlayerTension;
  if ( currentPlayerTension <= tension )
    this->currentPlayerTension = tension;
  else
    this->currentPlayerTension = currentPlayerTension;
}


// ========================================================================
// ?PhysicsHandler_Crouch@idPlayer@@CA_NHABVidVec3@@000ABVusercmd_t@@@Z
// EA  : 0x82E2CA18
// RVA : 0x00E2CA18
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::PhysicsHandler_Crouch(
        unsigned int entityNumber,
        const idVec3 *pos,
        const idVec3 *forward,
        const idVec3 *right,
        const idVec3 *up,
        const usercmd_t *userCmd)
{
  idPlayer *Player; // r3
  idPlayer *v12; // r31
  idPresentable *presentable; // r3

  Player = idGameLocal::GetPlayer(this: gameLocal, i: entityNumber);
  v12 = Player;
  return Player != nullptr
      && (presentable = Player->presentable) != nullptr
      && presentable->GetPlayerInterface_2(this: presentable) != nullptr
      && idPlayer::PlayerBehavior_SprintSlide_CheckCrouch(this: v12, pos, forward, right, up, userCmd);
}


// ========================================================================
// ?SerializePredictionState@idPlayer@@QAAXAAVidSerializer@@@Z
// EA  : 0x82E2CAB8
// RVA : 0x00E2CAB8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SerializePredictionState(idPlayer *this, idSerializer *ser)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = nullptr;
  idPresentablePlayer::SerializePredictionState(this: v4, ser);
}


// ========================================================================
// ?SerializeNonPredictionState@idPlayer@@QAAXAAVidSerializer@@@Z
// EA  : 0x82E2CB10
// RVA : 0x00E2CB10
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SerializeNonPredictionState(idPlayer *this, idSerializer *ser)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v4; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = nullptr;
  idPresentablePlayer::SerializeNonPredictionState(this: v4, ser);
}


// ========================================================================
// ?WriteLevelStateToFile@idPlayer@@QBAXPAVidFile@@@Z
// EA  : 0x82E2D520
// RVA : 0x00E2D520
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::WriteLevelStateToFile(idPlayer *this, idFile *file)
{
  idFile_vtbl *v2; // r10
  idInventoryCollection *v5; // r3
  idGame *v6; // r3
  profileStatValue_t *stats; // r28
  int i; // r29
  idPlayer_vtbl *v9; // r29
  equipSlot_t v10; // r3
  int v11; // r3
  idFile_vtbl *v12; // r9
  int v13; // r29
  const idFaction *v14; // r3
  const char *str; // r4
  idFile_vtbl *v16; // r10
  bool v17[4]; // [sp+50h] [-40h] BYREF
  int v18; // [sp+54h] [-3Ch] BYREF
  int v19; // [sp+58h] [-38h] BYREF
  int v20[13]; // [sp+5Ch] [-34h] BYREF

  v2 = file->__vftable;
  v18 = 3;
  v2->Write(this: file, a2: &v18, a3: 4u);
  v17[0] = gameLocal->GetConsoleUsed(this: gameLocal);
  file->Write(this: file, a2: v17, a3: 1u);
  file->Write(this: file, a2: &this->shouldHideVehicles, a3: 1u);
  idJobManager::WriteToFile(this: &this->jobManager, file);
  idJobTimerManager::WriteToFile(this: &this->jobTimerManager, file);
  v5 = (idInventoryCollection *)this->GetInventory(this);
  idInventoryCollection::WriteToFile(this: v5, file);
  idGameLayerManager::WriteToFile(this: &this->gameLayerManager, file);
  this->playerHealth.WriteComponents_Impl(this: &this->playerHealth, a2: file);
  v6 = common->Game(this: common);
  v6->GetGameDifficultySettingsForTransition(this: v6, a2: &v19, a3: v20);
  file->Write(this: file, a2: &v19, a3: 4u);
  file->Write(this: file, a2: v20, a3: 4u);
  stats = this->stats;
  for ( i = 256; i != 0; --i )
    file->Write(this: file, a2: stats++, a3: 4u);
  v9 = this->__vftable;
  v10 = this->GetWeaponSlot(this);
  v11 = (int)v9->GetEquipped(this, a2: v10);
  v12 = file->__vftable;
  v13 = v11;
  v17[0] = v11 != 0;
  v12->Write(this: file, a2: v17, a3: 1u);
  if ( v13 != 0 )
    idFile::WriteString(this: file, string: *(const char **)(*(_DWORD *)(v13 + 12) + 8));
  v14 = this->GetFaction_2(this);
  if ( v14 != nullptr && v14->myFaction != nullptr )
    str = v14->myFaction->name.str;
  else
    str = "error";
  idFile::WriteString(this: file, string: str);
  v16 = file->__vftable;
  v17[0] = this->infoMessages.seenDiceHelp;
  v16->Write(this: file, a2: v17, a3: 1u);
  file->Write(this: file, a2: &this->infoMessages.savedInventoryScreen, a3: 4u);
}


// ========================================================================
// ?ReadLevelStateFromFile@idPlayer@@QAAXPAVidFile@@@Z
// EA  : 0x82E2D798
// RVA : 0x00E2D798
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ReadLevelStateFromFile(idPlayer *this, idFile *file)
{
  char v4; // r11
  idPresentable *presentable; // r3
  bool inInitState; // r21
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  idPresentable *v10; // r3
  idPresentablePlayer *v11; // r3
  idPresentable *v12; // r28
  idInventoryCollection *v13; // r3
  idGame *v14; // r3
  profileStatValue_t *stats; // r27
  int i; // r28
  char *data; // r28
  idJobManager *v18; // r3
  idWeapon *InventoryItemByDeclName; // r28
  idPresentable *v20; // r3
  idPresentablePlayer *v21; // r3
  idPresentable *v22; // r3
  int v23; // r3
  char *v24; // r4
  const idDeclFaction *v25; // r4
  idPresentable *v26; // r3
  int v27; // r3
  char v28; // r7
  bool v29; // [sp+50h] [-B0h] BYREF
  _BYTE v30[3]; // [sp+51h] [-AFh] BYREF
  int v31; // [sp+54h] [-ACh] BYREF
  int v32; // [sp+58h] [-A8h] BYREF
  int v33; // [sp+5Ch] [-A4h] BYREF
  idStr v34; // [sp+60h] [-A0h] BYREF
  idStr v35[4]; // [sp+80h] [-80h] BYREF

  file->Read(this: file, a2: &v31, a3: 4u);
  if ( v31 >= 2 )
  {
    v29 = false;
    file->Read(this: file, a2: &v29, a3: 1u);
    gameLocal->SetConsoleUsed(this: gameLocal, a2: v29);
  }
  v4 = *((_BYTE *)this + 12824);
  presentable = this->presentable;
  inInitState = this->jobManager.inInitState;
  this->jobManager.inInitState = true;
  *((_BYTE *)this + 12824) = v4 | 2;
  if ( presentable != nullptr )
    v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = 0;
  idHands::Reset(this: (idHands *)(v7 + 37616), doIntro: false);
  file->Read(this: file, a2: &this->shouldHideVehicles, a3: 1u);
  v8 = this->presentable;
  if ( v8 != nullptr )
    v9 = (int)v8->GetPlayerInterface_2(this: v8);
  else
    v9 = 0;
  idPlayerHud::SetIgnoreJobUpdates(this: (idPlayerHud *)(v9 + 35096), ignore: true);
  v10 = this->presentable;
  if ( v10 != nullptr )
    v11 = v10->GetPlayerInterface_2(this: v10);
  else
    v11 = nullptr;
  idPresentablePlayer::ClearPickupItems(this: v11);
  idJobManager::ReadFromFile(this: &this->jobManager, file);
  idJobTimerManager::ReadFromFile(this: &this->jobTimerManager, file);
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  v12 = this->presentable;
  v13 = this->GetInventory_2(this);
  idInventoryCollection::ReadFromFile(this: v13, owner: v12, file);
  idGameLayerManager::ReadFromFile(this: &this->gameLayerManager, file);
  this->playerHealth.ReadComponents_Impl(this: &this->playerHealth, a2: file);
  file->Read(this: file, a2: &v33, a3: 4u);
  file->Read(this: file, a2: &v32, a3: 4u);
  v14 = common->Game(this: common);
  v14->SetGameDifficultySettingsForTransition(this: v14, a2: v33, a3: v32);
  stats = this->stats;
  for ( i = 256; i != 0; --i )
    file->Read(this: file, a2: stats++, a3: 4u);
  v30[0] = 0;
  file->Read(this: file, a2: v30, a3: 1u);
  if ( v30[0] != 0 )
  {
    v34.allocedAndFlag = 20;
    v34.len = 0;
    v34.data = v34.baseBuffer;
    v34.baseBuffer[0] = 0;
    idFile::ReadString(this: file, string: &v34);
    data = v34.data;
    v18 = (idJobManager *)this->GetInventory_2(this);
    InventoryItemByDeclName = (idWeapon *)idInventoryCollection::FindInventoryItemByDeclName(this: v18, jobName: data);
    if ( InventoryItemByDeclName != nullptr )
    {
      v20 = this->presentable;
      if ( v20 != nullptr )
        v21 = v20->GetPlayerInterface_2(this: v20);
      else
        v21 = nullptr;
      idPresentablePlayer::EquipItem(this: v21, item: InventoryItemByDeclName);
    }
    else
    {
      idLib::Warning(fmt: "No equipped item on player load.  string says %s", v34.data);
    }
    idStr::FreeData(this: &v34);
  }
  v22 = this->presentable;
  if ( v22 != nullptr )
    v23 = (int)v22->GetPlayerInterface_2(this: v22);
  else
    v23 = 0;
  idHands::ResetAnimWeb(this: (idHands *)(v23 + 37616));
  v35[0].allocedAndFlag = 20;
  v35[0].data = v35[0].baseBuffer;
  v35[0].len = 0;
  v35[0].baseBuffer[0] = 0;
  idFile::ReadString(this: file, string: v35);
  v24 = v35[0].data;
  if ( v35[0].data != nullptr )
  {
    v25 = (const idDeclFaction *)idDeclInfo::FindWithInheritance(
                                   this: &idDeclFaction::resourceList,
                                   name: v35[0].data,
                                   makeDefault: false);
    if ( v25 != nullptr )
    {
      idActor::SetFaction(this, faction: v25);
      goto LABEL_32;
    }
    v24 = v35[0].data;
  }
  idLib::Warning(fmt: "No faction on player load.  string says %s", v24);
LABEL_32:
  v26 = this->presentable;
  if ( v26 != nullptr )
    v27 = (int)v26->GetPlayerInterface_2(this: v26);
  else
    v27 = 0;
  idPlayerHud::SetIgnoreJobUpdates(this: (idPlayerHud *)(v27 + 35096), ignore: false);
  idPlayer::SetForceInhibitControl(this, inhibit: false);
  file->Read(this: file, a2: &this->infoMessages, a3: 1u);
  file->Read(this: file, a2: &this->infoMessages.savedInventoryScreen, a3: 4u);
  idAI2::RestartPlayerInteractions();
  v28 = *((_BYTE *)this + 12824);
  this->jobManager.inInitState = inInitState;
  *((_BYTE *)this + 12824) = v28 & 0xFD;
  idJobManager::UpdateRelevantJobNotesForMap(this: &this->jobManager);
  gameLocal->SetPlayerLoadedGameDifficulty(this: gameLocal, a2: true);
  idStr::FreeData(this: v35);
}


// ========================================================================
// __unwind$511528
// EA  : 0x82E2DC0C
// RVA : 0x00E2DC0C
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_511528()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$511529
// EA  : 0x82E2DC34
// RVA : 0x00E2DC34
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_511529()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// ?PostLoad@idPlayer@@QAAXXZ
// EA  : 0x82E2DC60
// RVA : 0x00E2DC60
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::PostLoad(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  idPresentable *v4; // r3
  int v5; // r3
  idPresentable *v6; // r3
  int v7; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  *(_DWORD *)(v3 + 37604) = idPlayer::PhysicsHandler_Crouch;
  v4 = this->presentable;
  if ( v4 != nullptr )
    v5 = (int)v4->GetPlayerInterface_2(this: v4);
  else
    v5 = 0;
  *(_DWORD *)(v5 + 37608) = idPlayer::PhysicsHandler_CrouchJump;
  v6 = this->presentable;
  if ( v6 != nullptr )
    v7 = (int)v6->GetPlayerInterface_2(this: v6);
  else
    v7 = 0;
  *(_DWORD *)(v7 + 37600) = idPlayer::PhysicsHandler_Jump;
  idPlayer::PlayerBehavior_Startup(this);
}


// ========================================================================
// ?InitPhysics@idPlayer@@QAAXXZ
// EA  : 0x82E2DD40
// RVA : 0x00E2DD40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::InitPhysics(idPlayer *this)
{
  idPresentable *presentable; // r3
  int entityNumber; // r28
  int v4; // r3
  idPresentable *v5; // r3
  const idMaterial *overrideClipMaterial; // r28
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  int v14; // r29
  idPresentable *v15; // r3
  int v16; // r3
  idLobbyBase *v17; // r3
  int *PhysicsObj; // r3
  int v19; // r11
  int v20; // r4
  idPresentable *v21; // r3
  int v22; // r3
  idPresentable *v23; // r3
  int v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  idPresentable *v27; // r3
  int v28; // r3
  idPresentable *v29; // r3
  int v30; // r3
  int v31; // r5
  idPresentable *v32; // r3
  int v33; // r11
  idPhysics *Physics; // r3
  idClipModel *v35; // r3
  idPresentable *v36; // r11
  int v37; // r3
  idPresentable *v38; // r3
  int v39; // r3
  idPresentable *v40; // r3
  int v41; // r3

  entityNumber = this->entityNumber;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  idPhysics::InitPhysics(
    this: (idPhysics *)(v4 + 36264),
    clip_: &clientGame->clip,
    callbacks_: &this->physicsCallbacks,
    entityNumber_: entityNumber);
  v5 = this->presentable;
  overrideClipMaterial = this->clipModelInfo.overrideClipMaterial;
  if ( v5 != nullptr )
    v7 = (int)v5->GetPlayerInterface_2(this: v5);
  else
    v7 = 0;
  *(_DWORD *)(v7 + 37036) = overrideClipMaterial;
  v8 = this->presentable;
  if ( v8 != nullptr )
    v9 = (int)v8->GetPlayerInterface_2(this: v8);
  else
    v9 = 0;
  *(_DWORD *)(v9 + 37040) = &clientGame->push;
  v10 = this->presentable;
  if ( v10 != nullptr )
    v11 = (int)v10->GetPlayerInterface_2(this: v10);
  else
    v11 = 0;
  (*(void (__fastcall **)(int, _DWORD, double))(*(_DWORD *)(v11 + 36264) + 4))(a1: v11 + 36264, a2: 0, a3: 0.0049999999);
  v12 = this->presentable;
  if ( v12 != nullptr )
    v13 = (int)v12->GetPlayerInterface_2(this: v12);
  else
    v13 = 0;
  (*(void (__fastcall **)(int, double))(*(_DWORD *)(v13 + 36264) + 16))(a1: v13 + 36264, a2: this->mass);
  if ( common->IsMultiplayer(this: common) )
    v14 = 163840;
  else
    v14 = 163968;
  v15 = this->presentable;
  if ( v15 != nullptr )
    v16 = (int)v15->GetPlayerInterface_2(this: v15);
  else
    v16 = 0;
  (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v16 + 36264) + 24))(a1: v16 + 36264, a2: v14, a3: -1);
  if ( g_noCoopPlayerCollision.valueInteger != 0
    && common->IsMultiplayer(this: common)
    && (v17 = session->GetActingGameStateLobbyBase(this: session), v17->GetMatchParms(this: v17)->gameType == 1) )
  {
    PhysicsObj = (int *)idPlayer::GetPhysicsObj(this);
    v19 = *PhysicsObj;
    v20 = 74761;
  }
  else
  {
    v21 = this->presentable;
    if ( v21 != nullptr )
      v22 = (int)v21->GetPlayerInterface_2(this: v21);
    else
      v22 = 0;
    v19 = *(_DWORD *)(v22 + 36264);
    PhysicsObj = (int *)(v22 + 36264);
    v20 = 107529;
  }
  (*(void (__fastcall **)(int *, int, int))(v19 + 32))(a1: PhysicsObj, a2: v20, a3: -1);
  v23 = this->presentable;
  if ( v23 != nullptr )
    v24 = (int)v23->GetPlayerInterface_2(this: v23);
  else
    v24 = 0;
  (*(void (__fastcall **)(int, idVec3 *))(*(_DWORD *)(v24 + 36264) + 96))(
    a1: v24 + 36264,
    a2: &gameLocal->clientGame.gravity);
  v25 = this->presentable;
  if ( v25 != nullptr )
    v26 = (int)v25->GetPlayerInterface_2(this: v25);
  else
    v26 = 0;
  idPhysics_Actor::SetClipModelAxis(this: (idPhysics_Actor *)(v26 + 36264));
  v27 = this->presentable;
  if ( v27 != nullptr )
    v28 = (int)v27->GetPlayerInterface_2(this: v27);
  else
    v28 = 0;
  (*(void (__fastcall **)(int))(*(_DWORD *)(v28 + 36264) + 200))(a1: v28 + 36264);
  v29 = this->presentable;
  if ( v29 != nullptr )
    v30 = (int)v29->GetPlayerInterface_2(this: v29);
  else
    v30 = 0;
  (*(void (__fastcall **)(int, idVec3 *, _DWORD))(*(_DWORD *)(v30 + 36264) + 80))(
    a1: v30 + 36264,
    a2: &vec3_origin,
    a3: 0);
  v32 = this->presentable;
  if ( v32 != nullptr )
    v33 = (int)v32->GetPlayerInterface_2(this: v32);
  else
    v33 = 0;
  idEntity::SetPhysics(this, phys: (idPhysics *)(v33 + 36264), a3: v31);
  Physics = idEntity::GetPhysics(this);
  v35 = Physics->GetClipModel(this: Physics, a2: 0);
  v36 = this->presentable;
  this->walkIK.clipModel = v35;
  if ( v36 != nullptr )
    v37 = (int)v36->GetPlayerInterface_2(this: v36);
  else
    v37 = 0;
  *(_DWORD *)(v37 + 37604) = idPlayer::PhysicsHandler_Crouch;
  v38 = this->presentable;
  if ( v38 != nullptr )
    v39 = (int)v38->GetPlayerInterface_2(this: v38);
  else
    v39 = 0;
  *(_DWORD *)(v39 + 37608) = idPlayer::PhysicsHandler_CrouchJump;
  v40 = this->presentable;
  if ( v40 != nullptr )
    v41 = (int)v40->GetPlayerInterface_2(this: v40);
  else
    v41 = 0;
  *(_DWORD *)(v41 + 37600) = idPlayer::PhysicsHandler_Jump;
}


// ========================================================================
// ?FinishRevive@idPlayer@@AAAXXZ
// EA  : 0x82E2E1C8
// RVA : 0x00E2E1C8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::FinishRevive(idPlayer *this)
{
  char v1; // r11
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentable *v5; // r3
  int v6; // r3
  idPresentable *v7; // r3
  int v8; // r3
  __int64 v9; // r10
  __int64 v10; // r8
  int v11; // r6
  int v12; // r5
  idPresentable *v13; // r3
  const idAngles *v14; // r4
  idPhysics *Physics; // r3
  idPhysics *v16; // r3
  idPresentable *v17; // r3
  int v18; // r3
  idPresentable *v19; // r3
  int v20; // r3
  idPresentable *v21; // r3
  int v22; // r3
  idPresentable *v23; // r3
  int v24; // r3
  idPresentable *v25; // r3
  int v26; // r3
  idPresentable *v27; // r3
  int v28; // r29
  idAngles v29; // [sp+50h] [-60h] BYREF
  float v30[4]; // [sp+60h] [-50h] BYREF
  float v31[6]; // [sp+70h] [-40h] BYREF

  v1 = *((_BYTE *)this + 12824);
  presentable = this->presentable;
  *((_BYTE *)this + 12824) = v1 | 8;
  if ( presentable != nullptr )
    v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v4 = 0;
  idHands::Reset(this: (idHands *)(v4 + 37616), doIntro: false);
  v5 = this->presentable;
  if ( v5 != nullptr )
    v6 = (int)v5->GetPlayerInterface_2(this: v5);
  else
    v6 = 0;
  *(_BYTE *)(v6 + 40606) = 1;
  v7 = this->presentable;
  if ( v7 != nullptr )
    v8 = (int)v7->GetPlayerInterface_2(this: v7);
  else
    v8 = 0;
  idHands::Enable(this: (idHands *)(v8 + 37616));
  LODWORD(v9) = &idTarget_SoundDuck::Type.node;
  idEventReceiver::PostEventSec(this, ev: &EV_ResumeLiving, time: 1.0, a4: v12, a5: v11, a6: v10, a7: v9);
  idAIEventManager::RemoveEntityEventsOfType(this: &gameLocal->aiEventManager, ent: this, eventClass: AIEVENT_BODY);
  v13 = this->presentable;
  if ( v13 != nullptr )
    v14 = (const idAngles *)v13->GetPlayerInterface_2(this: v13);
  else
    v14 = nullptr;
  idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)&v29, result: v14, includeWeaponKick: true);
  v29.roll = 0.0;
  v29.pitch = 0.0;
  idPlayer::SetViewAngles(this, angles: &v29, force: true);
  Physics = idEntity::GetPhysics(this);
  v30[0] = 0.0;
  v30[1] = 0.0;
  v30[2] = 0.0;
  Physics->SetLinearVelocity(this: Physics, a2: (const idVec3 *)v30, a3: 0);
  v16 = idEntity::GetPhysics(this);
  v31[0] = 0.0;
  v31[1] = 0.0;
  v31[2] = 0.0;
  v16->SetAngularVelocity(this: v16, a2: (const idVec3 *)v31, a3: 0);
  v17 = this->presentable;
  if ( v17 != nullptr )
    v18 = (int)v17->GetPlayerInterface_2(this: v17);
  else
    v18 = 0;
  idPlayerHud::SetHudState(this: (idPlayerHud *)(v18 + 35096), state: HUDSTATE_ALL);
  v19 = this->presentable;
  if ( v19 != nullptr )
    v20 = (int)v19->GetPlayerInterface_2(this: v19);
  else
    v20 = 0;
  *(_BYTE *)(v20 + 35104) = 1;
  v21 = this->presentable;
  *(_BYTE *)&this->flags = *(_BYTE *)&this->flags & 0xF9 | 2;
  if ( v21 != nullptr )
    v22 = (int)v21->GetPlayerInterface_2(this: v21);
  else
    v22 = 0;
  idHands::Show(this: (idHands *)(v22 + 37616), hideReason: HAND_HIDE_GENERIC);
  v23 = this->presentable;
  if ( v23 != nullptr )
    v24 = (int)v23->GetPlayerInterface_2(this: v23);
  else
    v24 = 0;
  idHands::Show(this: (idHands *)(v24 + 37616), hideReason: HAND_HIDE_SERVER_AUTHORITATIVE);
  idPlayer::SetForceInhibitControl(this, inhibit: false);
  idCamera::Deactivate(this: this->reviveCamera);
  v25 = this->presentable;
  if ( v25 != nullptr )
    v26 = (int)v25->GetPlayerInterface_2(this: v25);
  else
    v26 = 0;
  *(_BYTE *)(v26 + 47032) &= ~4u;
  v27 = this->presentable;
  this->lastIncapacitate = 0;
  if ( v27 != nullptr )
    v28 = (int)v27->GetPlayerInterface_2(this: v27);
  else
    v28 = 0;
  *(_BYTE *)(v28 + 47032) = (this->IsDead(this) << 7) | *(_BYTE *)(v28 + 47032) & 0x7F;
}


// ========================================================================
// ?Event_EndRevive@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E2E4E8
// RVA : 0x00E2E4E8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_EndRevive(idPlayer *this, idPlayer *result)
{
  idPlayer::FinishRevive(this: result);
  return this;
}


// ========================================================================
// ?Event_RespawnWithFade@idPlayer@@AAA?AVeventVoid@@PBDH@Z
// EA  : 0x82E2E520
// RVA : 0x00E2E520
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
eventVoid *__fastcall idPlayer::Event_RespawnWithFade(
        idPlayer *this,
        eventVoid *result,
        const char *spawnSpot,
        const int fadeTimeMS,
        __int64 a5,
        __int64 a6)
{
  unsigned __int64 v6; // r28
  idPlayerStart *v8; // r31
  int v9; // r6
  double z; // fp13
  double y; // fp10
  __int128 v12; // r7 OVERLAPPED
  int v13; // r8
  int v14; // r8 OVERLAPPED
  __int128 v15; // r7 OVERLAPPED
  __int64 v17; // [sp+8h] [-158h]
  __int64 v18; // [sp+8h] [-158h]
  __int64 v19; // [sp+10h] [-150h]
  __int64 v20; // [sp+10h] [-150h]
  __int64 v21; // [sp+18h] [-148h]
  __int64 v22; // [sp+18h] [-148h]
  __int64 v23; // [sp+20h] [-140h]
  __int64 v24; // [sp+20h] [-140h]
  __int64 v25; // [sp+28h] [-138h]
  __int64 v26; // [sp+28h] [-138h]
  __int64 v27; // [sp+30h] [-130h]
  __int64 v28; // [sp+30h] [-130h]
  __int64 v29; // [sp+38h] [-128h]
  __int64 v30; // [sp+38h] [-128h]
  __int64 v31; // [sp+40h] [-120h]
  __int64 v32; // [sp+40h] [-120h]
  __int64 v33; // [sp+48h] [-118h]
  __int64 v34; // [sp+48h] [-118h]
  __int64 v35; // [sp+50h] [-110h]
  __int64 v36; // [sp+50h] [-110h]
  __int64 v37; // [sp+58h] [-108h]
  __int64 v38; // [sp+58h] [-108h]
  int v39; // [sp+64h] [-FCh]
  int v40; // [sp+68h] [-F8h]
  int v41; // [sp+6Ch] [-F4h]
  int v42[8]; // [sp+70h] [-F0h] BYREF
  int v43; // [sp+90h] [-D0h] BYREF
  idVec3 v44[2]; // [sp+A0h] [-C0h] BYREF
  float v45[6]; // [sp+B8h] [-A8h] BYREF
  int v46; // [sp+D0h] [-90h]
  float r; // [sp+D4h] [-8Ch]
  __int64 v48; // [sp+D8h] [-88h]
  int v49; // [sp+F0h] [-70h]
  float v50; // [sp+F4h] [-6Ch]
  __int64 v51; // [sp+F8h] [-68h]
  int v52; // [sp+100h] [-60h]

  LODWORD(a6) = *(_DWORD *)&result[492];
  v6 = __PAIR64__((unsigned int)result, (unsigned int)this);
  v8 = idGameLocal::FindSpawnSpot(this: gameLocal, spawnspot: spawnSpot, playerNum: a6, a4: fadeTimeMS, a5, a6);
  v44[0].x = idColor::colorBlack.r;
  v44[0].y = idColor::colorBlack.g;
  v44[0].z = idColor::colorBlack.b;
  idPlayer::Event_FadeView(
    this: (idPlayer *)&v43,
    result: (eventVoid *)HIDWORD(v6),
    color: v44,
    alpha: 1.0,
    fadeTimeMS: v9,
    a6: fadeTimeMS);
  idMat3::ToAngles(this: (idMat3 *)v45, result: (idAngles *)&v8->spawnOrientation);
  z = v8->spawnPosition.z;
  y = v8->spawnPosition.y;
  v44[0].y = v8->spawnPosition.x;
  HIBYTE(v44[0].x) = 118;
  v44[0].z = y;
  HIBYTE(v46) = 97;
  v44[1].x = (float)z + (float)5.0;
  r = v45[0];
  *((_QWORD *)&v12 + 1) = *(_QWORD *)&v44[0].z;
  *(float *)&v48 = v45[1];
  *((float *)&v48 + 1) = v45[2];
  DWORD1(v12) = fadeTimeMS;
  v13 = __ROL4__(LODWORD(v44[1].y), 32);
  idEventReceiver::PostEventMS(
    this: (idEventReceiver *)HIDWORD(v6),
    ev: &EV_Teleport,
    arg1: *(__int64 *)((char *)&v12 + 4),
    arg2: *(__int64 *)((char *)&v12 - 4),
    a5: v48,
    a6: v17,
    a7: v19,
    a8: v21,
    a9: v23,
    a10: v25,
    a11: v27,
    a12: v29,
    a13: v31,
    a14: v33,
    a15: v35,
    a16: v37);
  HIBYTE(v46) = 118;
  HIBYTE(v49) = 102;
  *(float *)&v48 = idColor::colorBlack.g;
  LODWORD(v44[0].y) = fadeTimeMS;
  HIBYTE(v44[0].x) = 105;
  v50 = 0.0;
  r = idColor::colorBlack.r;
  *((float *)&v48 + 1) = idColor::colorBlack.b;
  memcpy(Dst: v42, Src: v44, Size: 0x14u);
  v14 = __ROL4__(v49, 32);
  DWORD1(v15) = v46;
  *((_QWORD *)&v15 + 1) = v48;
  idEventReceiver::PostEventMS(
    this: (idEventReceiver *)HIDWORD(v6),
    ev: &EV_FadeView,
    arg1: *(__int64 *)((char *)&v15 + 4),
    arg3: *(__int64 *)&v14,
    a5: v51,
    a6: v18,
    a7: v20,
    a8: v22,
    a9: v24,
    a10: v26,
    a11: v28,
    a12: v30,
    a13: v32,
    a14: v34,
    a15: v36,
    a16: v38,
    a17: v52,
    a18: v39,
    a19: v40,
    a20: v41,
    a21: v42[0]);
  return (eventVoid *)v6;
}


// ========================================================================
// ?Teleport@idPlayer@@UAAXABVidVec3@@ABVidAngles@@@Z
// EA  : 0x82E2E6B8
// RVA : 0x00E2E6B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::Teleport(idPlayer *this, const idVec3 *origin, idMat3 *angles)
{
  idPresentable *presentable; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  idPresentable *v10; // r3
  idAngles *v11; // r3
  idPresentable *v12; // r3
  idPresentablePlayer *v13; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v7 = 0;
  idPhysics_Player::ClearCrouch(this: (idPhysics_Player *)(v7 + 36264));
  v8 = this->presentable;
  if ( v8 != nullptr )
    v9 = (int)v8->GetPlayerInterface_2(this: v8);
  else
    v9 = 0;
  (*(void (__fastcall **)(int))(*(_DWORD *)(v9 + 36264) + 324))(a1: v9 + 36264);
  v10 = this->presentable;
  if ( v10 != nullptr )
    v11 = (idAngles *)v10->GetPlayerInterface_2(this: v10);
  else
    v11 = nullptr;
  v11[3070] = ang_zero;
  idActor::Teleport(this, origin, angles);
  idPlayer::SetViewAngles(this, (idAngles *)angles, force: true);
  if ( common->IsMultiplayer(this: common) )
  {
    v12 = this->presentable;
    if ( v12 != nullptr )
    {
      v13 = v12->GetPlayerInterface_2(this: v12);
      idPresentablePlayer::SetServerOverridePos(this: v13, teleport: true, extra: 0);
    }
    else
    {
      idPresentablePlayer::SetServerOverridePos(this: nullptr, teleport: true, extra: 0);
    }
  }
}


// ========================================================================
// ?Give@idPlayer@@QAA_NPBD0@Z
// EA  : 0x82E2E818
// RVA : 0x00E2E818
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::Give(idPlayer *this, const char *statname, const char *value)
{
  int v5; // r21
  bfx::Planner3D *v6; // r22
  idTungstenHealth *p_playerHealth; // r31
  double v8; // fp31
  __int64 v9; // r11
  int v11; // r27
  int v12; // r25
  idInventoryItem *InventoryItem; // r3
  idDeclInventory *decl; // r31
  int *v15; // r3
  int *v16; // r29
  int v17; // r28
  int v18; // r31
  int v19; // r30
  int v20; // r11
  idPresentable *presentable; // r4
  bool v22; // cr57
  idDeclInfoTemplate<idDeclThrowable> *v23; // r30
  const idDeclInventory *v24; // r30
  idPresentable *v25; // r4
  int v26; // r29
  int v27; // r28
  int num; // r27
  const char *str; // r4
  const idDecl *v30; // r3
  const idDeclInventory *v31; // r31
  idPresentable *v32; // r4
  unsigned __int8 v33; // r11

  v5 = atol(nptr: value);
  if ( this->IsDead(this) )
    return 0;
  v6 = (bfx::Planner3D *)this->GetInventory_2(this);
  if ( idStr::Icmp(s1: statname, s2: "health") == 0 )
  {
    p_playerHealth = &this->playerHealth;
    v8 = ((double (__fastcall *)(idTungstenHealth *))this->playerHealth.GetCurBaseHealth_Impl)(a1: &this->playerHealth);
    if ( v8 < ((double (__fastcall *)(idTungstenHealth *))this->playerHealth.GetMaxBaseHealth_Impl)(a1: &this->playerHealth) )
    {
      if ( v5 != 0 )
      {
        LODWORD(v9) = v5;
        HIDWORD(v9) = p_playerHealth->__vftable;
        p_playerHealth->Heal_Impl(this: &this->playerHealth, a2: (float)v9);
      }
      return 1;
    }
    return 0;
  }
  if ( idStr::Icmp(s1: statname, s2: "ammo") == 0 )
  {
    v11 = 0;
    v12 = 0;
    if ( (int)idScriptObject::GetTypeDef(this: v6) <= 0 )
      return 0;
    do
    {
      InventoryItem = idInventoryCollection::GetInventoryItem(this: (idInventoryCollection *)v6, index: v12);
      decl = (idDeclInventory *)InventoryItem->decl;
      if ( decl != nullptr )
      {
        idPlayer::CheckIsNewItem(this, decl: InventoryItem->decl);
        v15 = (int *)_RTDynamicCast(
                       inptr: decl,
                       VfDelta: 0,
                       SrcType: &idDeclInventory `RTTI Type Descriptor',
                       TargetType: (void *)&idDeclWeapon `RTTI Type Descriptor',
                       isReference: 0);
        v16 = v15;
        if ( v15 != nullptr )
        {
          v17 = 0;
          if ( v15[129] > 0 )
          {
            v18 = 0;
            do
            {
              v19 = v16[128];
              v20 = *(_DWORD *)(v18 + v19);
              if ( v20 != 0 && *(_BYTE *)(v20 + 252) != 0 )
              {
                presentable = this->presentable;
                if ( presentable == nullptr )
                {
                  idEntity::InitPresentableInternal(this);
                  presentable = this->presentable;
                }
                idInventoryCollection::GiveItem(
                  this: (idInventoryCollection *)v6,
                  owner: presentable,
                  decl: *(const idDeclInventory **)(v18 + v19),
                  count: v5,
                  forceCount: false,
                  canIntro: false);
                ++v11;
              }
              ++v17;
              v18 += 28;
            }
            while ( v17 < v16[129] );
          }
        }
      }
      ++v12;
    }
    while ( v12 < (int)idScriptObject::GetTypeDef(this: v6) );
    v22 = v11 > 0;
LABEL_59:
    v33 = 1;
    if ( v22 )
      return v33;
    return 0;
  }
  if ( idStr::Icmp(s1: statname, s2: "cash") == 0 )
  {
    idPlayer::GiveCash(this, amount: v5);
    return 1;
  }
  if ( idStr::Icmp(s1: statname, s2: "racecash") == 0 )
  {
    idPlayer::GiveVehicleCash(this, amount: v5);
    return 1;
  }
  if ( idStr::Icmp(s1: statname, s2: "weapons") == 0 )
  {
    v23 = (idDeclInfoTemplate<idDeclThrowable> *)&idDeclWeapon::resourceList;
LABEL_49:
    v26 = 0;
    if ( v23->declSources.num <= 0 )
      return 0;
    v27 = 0;
    num = v23->declSources.num;
    do
    {
      str = v23->declSources.list[v27]->name.str;
      if ( str != nullptr )
      {
        v30 = idDeclInfo::FindWithInheritance(this: v23, name: str, makeDefault: false);
        v31 = (const idDeclInventory *)v30;
        if ( v30 != nullptr && HIBYTE(v30[4].staleCount) != 0 )
        {
          v32 = this->presentable;
          if ( v32 == nullptr )
          {
            idEntity::InitPresentableInternal(this);
            v32 = this->presentable;
          }
          idInventoryCollection::GiveItem(
            this: (idInventoryCollection *)v6,
            owner: v32,
            decl: v31,
            count: v5,
            forceCount: false,
            canIntro: false);
          ++v26;
        }
      }
      --num;
      ++v27;
    }
    while ( num != 0 );
    v22 = v26 > 0;
    goto LABEL_59;
  }
  if ( idStr::Icmp(s1: statname, s2: "ammoall") == 0 )
  {
    v23 = (idDeclInfoTemplate<idDeclThrowable> *)&idDeclAmmo::resourceList;
    goto LABEL_49;
  }
  if ( idStr::Icmp(s1: statname, s2: "items") == 0 || idStr::Icmp(s1: statname, s2: "inventory") == 0 )
  {
    v23 = (idDeclInfoTemplate<idDeclThrowable> *)&idDeclInventory::resourceList;
    goto LABEL_49;
  }
  if ( idStr::Icmp(s1: statname, s2: "throwable") == 0 )
  {
    v23 = &idDeclThrowable::resourceList;
    goto LABEL_49;
  }
  if ( idStr::Icmp(s1: statname, s2: "healthitems") == 0 )
  {
    v23 = (idDeclInfoTemplate<idDeclThrowable> *)&idDeclHealthItem::resourceList;
    goto LABEL_49;
  }
  if ( idStr::Icmp(s1: statname, s2: "damageitems") == 0 )
  {
    v23 = (idDeclInfoTemplate<idDeclThrowable> *)&idDeclDamageBoostItem::resourceList;
    goto LABEL_49;
  }
  if ( statname == nullptr
    || (v24 = (const idDeclInventory *)idDeclInfo::FindWithInheritance(
                                         this: &idDeclInventory::resourceList,
                                         name: statname,
                                         makeDefault: false)) == nullptr )
  {
    idLib::Warning(fmt: "Unknown item '%s'", statname);
    return 0;
  }
  v25 = this->presentable;
  if ( v5 >= 0 )
  {
    if ( v25 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v25 = this->presentable;
    }
    idInventoryCollection::GiveItem(
      this: (idInventoryCollection *)v6,
      owner: v25,
      decl: v24,
      count: v5,
      forceCount: false,
      canIntro: false);
    return 1;
  }
  else
  {
    if ( v25 == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      v25 = this->presentable;
    }
    idInventoryCollection::DeleteInventoryItem(this: (idInventoryCollection *)v6, owner: v25, decl: v24, count: -v5);
    return 1;
  }
}


// ========================================================================
// ?PickupItems@idPlayer@@QAA_NPBVidDeclInventory@@ABVidVec3@@@Z
// EA  : 0x82E2ECE8
// RVA : 0x00E2ECE8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::PickupItems(idPlayer *this, const idDeclInventory *inventoryDecl, const idVec3 *location)
{
  double x; // fp13
  double y; // fp12
  double z; // fp11
  int EntitiesTouchingBounds; // r27
  int v10; // r25
  int v11; // r26
  int *v12; // r30
  idVolume_ItemGroup *v13; // r3
  idVolume_ItemGroup *v14; // r31
  const idSoundShader *sound_pickup; // r20
  int *v16; // r24
  idProp_Moveable *v17; // r30
  idProp_Moveable *v18; // r31
  idProjectile *v19; // r3
  idEventReceiver *v20; // r30
  idPresentable *presentable; // r28
  int v22; // r3
  idPresentable *v24; // r30
  idInventoryCollection *v25; // r3
  int backupInventoryCount; // r28
  const idDeclInventory *backupInventoryDecl; // r26
  idPresentable *v28; // r30
  idInventoryCollection *v29; // r3
  int FocusTracker; // r3
  idPresentable *v31; // r31
  idInventoryCollection *v32; // r3
  __int64 v33; // r10
  __int64 v34; // r8
  int v35; // r6
  const idDeclPlayerProps *playerProps; // r11
  const idSoundShader *sndPickup; // r6
  idBounds v38; // [sp+50h] [-260h] BYREF
  idDeclPlayerProps::playerSounds_t sounds; // [sp+70h] [-240h] BYREF
  int v40[92]; // [sp+140h] [-170h] BYREF

  if ( inventoryDecl == nullptr )
    return 0;
  x = location->x;
  y = location->y;
  z = location->z;
  v38.b[0].x = location->x - (float)64.0;
  v38.b[0].y = (float)y - (float)64.0;
  v38.b[0].z = (float)z - (float)64.0;
  v38.b[1].x = (float)x + (float)64.0;
  v38.b[1].y = (float)y + (float)64.0;
  v38.b[1].z = (float)z + (float)64.0;
  EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                             this: &clientGame->clip,
                             bounds: &v38,
                             clipMask: -1,
                             entityList: v40,
                             maxCount: 64);
  v10 = 0;
  v11 = 0;
  if ( EntitiesTouchingBounds <= 0 )
  {
LABEL_7:
    sound_pickup = nullptr;
    if ( EntitiesTouchingBounds > 0 )
    {
      v16 = v40;
      do
      {
        v17 = (idProp_Moveable *)gameLocal->entities.ptr[*v16];
        if ( v17->IsEverUsable(this: v17, a2: this) )
        {
          v18 = idProp_Moveable::CastTo(c: v17);
          v19 = idProjectile::CastTo(c: (idProjectile *)v17);
          v20 = v19;
          if ( v18 != nullptr )
          {
            if ( v18->inventoryDecl != inventoryDecl
              || !v18->IsEverUsable(this: v18, a2: this)
              || v18->GetInventory_2(this: v18) == nullptr )
            {
              goto LABEL_35;
            }
            if ( this->presentable == nullptr )
              idEntity::InitPresentableInternal(this);
            presentable = this->presentable;
            v24 = v18->presentable;
            if ( v24 == nullptr )
            {
              idEntity::InitPresentableInternal(this: v18);
              v24 = v18->presentable;
            }
            v25 = v18->GetInventory_2(this: v18);
            if ( idInventoryCollection::TransferInventory(this: v25, owner: v24, toOwner: presentable, canIntro: true) == nullptr
              && v18->backupInventoryDecl != nullptr
              && this->GetInventory_2(this) != nullptr )
            {
              backupInventoryCount = v18->backupInventoryCount;
              backupInventoryDecl = v18->backupInventoryDecl;
              if ( this->presentable == nullptr )
                idEntity::InitPresentableInternal(this);
              v28 = this->presentable;
              v29 = this->GetInventory_2(this);
              idInventoryCollection::GiveItem(
                this: v29,
                owner: v28,
                decl: backupInventoryDecl,
                count: backupInventoryCount,
                forceCount: false,
                canIntro: true);
            }
            if ( v18->sound_pickup != nullptr )
              sound_pickup = v18->sound_pickup;
            FocusTracker = idPlayer::GetFocusTracker(this);
            v18->Use(this: v18, a2: this, a3: *(const usableState_t *)(FocusTracker + 524));
            idProp_Moveable::NaniteInspection(this: v18);
          }
          else
          {
            if ( v19 == nullptr || v19->GetInventoryItem(this: v19) != inventoryDecl )
              goto LABEL_35;
            v31 = this->presentable;
            if ( v31 == nullptr )
            {
              idEntity::InitPresentableInternal(this);
              v31 = this->presentable;
            }
            v32 = this->GetInventory_2(this);
            idInventoryCollection::GiveItem(
              this: v32,
              owner: v31,
              decl: inventoryDecl,
              count: 1,
              forceCount: false,
              canIntro: false);
            idEventReceiver::PostEventMS(this: v20, ev: &EV_Remove, time: 0, a4: v35, a5: v34, a6: v33);
          }
          ++v10;
        }
LABEL_35:
        --EntitiesTouchingBounds;
        ++v16;
      }
      while ( EntitiesTouchingBounds != 0 );
    }
    idRageMetrics::ItemsTaken(this: clientGame->rageMetrics, player: (idVehicle *)this, items: v10);
    if ( v10 > 0 )
    {
      if ( sound_pickup != nullptr )
      {
        sndPickup = sound_pickup;
      }
      else
      {
        playerProps = this->playerProps;
        if ( playerProps != nullptr )
          sounds = playerProps->sounds;
        else
          idDeclPlayerProps::playerSounds_t::playerSounds_t(this: &sounds);
        sndPickup = sounds.sndPickup;
      }
      idClientGame::PlaySoundForAllPeers(
        this: clientGame,
        entity: this,
        channel: SND_CHANNEL_ITEM,
        shader: sndPickup,
        soundShaderFlags: 0);
      return 1;
    }
    return 0;
  }
  v12 = v40;
  while ( 1 )
  {
    v13 = idVolume_ItemGroup::CastTo(c: (idVolume_ItemGroup *)gameLocal->entities.ptr[*v12]);
    v14 = v13;
    if ( v13 != nullptr && (unsigned __int8)idVolume_ItemGroup::Contains(this: v13, pos: location) != 0 )
      break;
    ++v11;
    ++v12;
    if ( v11 >= EntitiesTouchingBounds )
      goto LABEL_7;
  }
  v22 = idVolume_ItemGroup::Pickup(this: v14, player: this);
  idRageMetrics::ItemsTaken(this: clientGame->rageMetrics, player: (idVehicle *)this, items: v22);
  return 1;
}


// ========================================================================
// ?RemoveDroppableInfo@idPlayer@@QAAXPAVidEntity@@@Z
// EA  : 0x82E2F0F8
// RVA : 0x00E2F0F8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::RemoveDroppableInfo(idPlayer *this, idEntity *ent)
{
  int v3; // r30
  idStaticList<idEntityPtr<idEntity>,2> *p_droppableList; // r31
  int v5; // r29
  int value; // r9
  idEntity *v7; // r3
  idEntity *v8; // r3
  int num; // r11
  int v10; // r11

  v3 = this->droppableList.num - 1;
  if ( v3 >= 0 )
  {
    p_droppableList = &this->droppableList;
    v5 = v3;
    do
    {
      value = p_droppableList->list[v5].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v8 = idEntity::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      if ( v8 == ent )
      {
        num = p_droppableList->num;
        if ( v3 < num )
        {
          v10 = num - 1;
          p_droppableList->num = v10;
          if ( v3 != v10 )
            p_droppableList->list[v5].spawnId.value = p_droppableList->list[v10].spawnId.value;
        }
      }
      --v3;
      --v5;
    }
    while ( v3 >= 0 );
  }
}


// ========================================================================
// ?ProcessLastUserCmd@idPlayer@@QAAXPAVidUserCmdMgr@@@Z
// EA  : 0x82E2F1C0
// RVA : 0x00E2F1C0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ProcessLastUserCmd(idPlayer *this, idUserCmdMgr *userCmdMgr)
{
  int entityNumber; // r10
  int v4; // r11
  int v5; // r9
  idPresentable *presentable; // r3
  const usercmd_t *v7; // r30
  idPresentablePlayer *v8; // r3
  idPresentable *v9; // r3
  idPresentablePlayer *v10; // r3
  int PlayerGameTime; // r3
  idVehicle_Car *Control; // r3
  idVehicle_Car *v13; // r3
  idPlayerTimeLock v14[2]; // [sp+50h] [-20h] BYREF

  entityNumber = this->entityNumber;
  v4 = 4 * (entityNumber + 11526);
  v5 = *(int *)((char *)&userCmdMgr->cmdBuffer[0][0].buttons + v4);
  if ( v5 < userCmdMgr->writeFrame[entityNumber] - 1 )
    *(int *)((char *)&userCmdMgr->cmdBuffer[0][0].buttons + v4) = v5 + 1;
  presentable = this->presentable;
  v7 = &userCmdMgr->cmdBuffer[*(int *)((char *)&userCmdMgr->cmdBuffer[0][0].buttons + v4) % 128][entityNumber];
  if ( presentable != nullptr )
    v8 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v8 = nullptr;
  idPresentablePlayer::HandleUserCmds(this: v8, newcmd: v7);
  v9 = this->presentable;
  if ( v9 != nullptr )
    v10 = v9->GetPlayerInterface_2(this: v9);
  else
    v10 = nullptr;
  PlayerGameTime = idPresentablePlayer::GetPlayerGameTime(this: v10);
  idPlayerTimeLock::idPlayerTimeLock(this: v14, newTime: PlayerGameTime);
  idPlayerTimeLock::~idPlayerTimeLock(this: v14);
  Control = (idVehicle_Car *)idPlayer::GetControl(this);
  v13 = idVehicle_Car::CastTo(c: Control);
  if ( v13 != nullptr )
    idVehicle_Car::ProcessLastUserCmd(this: v13);
  else
    idPlayer::ProcessInput(this, doMovement: false);
}


// ========================================================================
// ?CalcDamagePoints@idPlayer@@QAAXPAVidEntity@@0PBVidDeclDamage@@MV?$idIndex@FW4invalidJointIndex_t@@@@PAM@Z
// EA  : 0x82E2F2E0
// RVA : 0x00E2F2E0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::CalcDamagePoints(
        idPlayer *this,
        idWorldspawn *inflictor,
        idPlayer *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        idIndex<short,enum invalidJointIndex_t> *joint,
        const idIndex<short,enum invalidJointIndex_t> *health,
        float *a8)
{
  double DamageForJoint; // fp31
  double v15; // fp31
  unsigned int v16; // r3
  double v17; // fp1
  bool v18; // r4
  idCVar *v19; // r10
  double v20; // fp1
  bool v21; // r4
  double v22; // fp1
  bool v23; // r4
  double v24; // fp1
  bool v25; // r4
  idAI2 *v26; // r3
  idAI2 *v27; // r30
  double v28; // fp31
  char v29; // r11
  idPresentable *presentable; // r3
  int v31; // r3
  double v32; // fp1

  DamageForJoint = idActor::GetDamageForJoint(this, joint: health);
  v15 = (float)((float)DamageForJoint * idDeclDamage::DamageAmount(this: damageDef));
  if ( inflictor != gameLocal->world )
  {
    v16 = gameLocal->GetGameDifficulty(this: gameLocal);
    if ( v16 <= 3 )
    {
      if ( v16 == 1 )
      {
        if ( this->normalTable != nullptr )
        {
          v20 = ((double (__fastcall *)(idTungstenHealth *))this->playerHealth.GetBaseHealthRatio_Impl)(a1: &this->playerHealth);
          v15 = (float)(idLookupTable::TableLookup(this: this->normalTable->table, time: v20, fastSearch: v21)
                      * (float)v15);
          goto LABEL_19;
        }
        v19 = &player_difficultyDamageScaleMedium;
      }
      else if ( v16 == 2 )
      {
        if ( this->normalTable != nullptr )
        {
          v22 = ((double (__fastcall *)(idTungstenHealth *))this->playerHealth.GetBaseHealthRatio_Impl)(a1: &this->playerHealth);
          v15 = (float)(idLookupTable::TableLookup(this: this->hardTable->table, time: v22, fastSearch: v23) * (float)v15);
          goto LABEL_19;
        }
        v19 = &player_difficultyDamageScaleHard;
      }
      else if ( v16 != 0 )
      {
        if ( this->nightmareTable != nullptr )
        {
          v24 = ((double (__fastcall *)(idTungstenHealth *))this->playerHealth.GetBaseHealthRatio_Impl)(a1: &this->playerHealth);
          v15 = (float)(idLookupTable::TableLookup(this: this->nightmareTable->table, time: v24, fastSearch: v25)
                      * (float)v15);
          goto LABEL_19;
        }
        v19 = &player_difficultyDamageScaleNightmare;
      }
      else
      {
        if ( this->easyTable != nullptr )
        {
          v17 = ((double (__fastcall *)(idTungstenHealth *))this->playerHealth.GetBaseHealthRatio_Impl)(a1: &this->playerHealth);
          v15 = (float)(idLookupTable::TableLookup(this: this->easyTable->table, time: v17, fastSearch: v18) * (float)v15);
          goto LABEL_19;
        }
        v19 = &player_difficultyDamageScaleEasy;
      }
      v15 = (float)(v19->valueFloat * (float)v15);
    }
  }
LABEL_19:
  if ( v15 < 1.0 )
    v15 = 1.0;
  v26 = idAI2::CastTo(c: (idAI2 *)attacker);
  v27 = v26;
  if ( v26 != nullptr )
  {
    if ( idAI2::GetEncounterGroup(this: v26) != nullptr && (v27->aiVolatile.groupStatus.condition & 0x20000) != 0 )
      v15 = (float)(idAI2::GetEncounterGroup(this: v27)->goodWillSettings.damageScale * (float)v15);
    v15 = (float)(v27->aiEditable.damageMultiplier * (float)v15);
  }
  v28 = (float)((float)((float)((float)v15 * (float)damageScale) * damageDef->playerDamageScale)
              * this->actorVolatile.damageTakenMultiplier);
  if ( attacker == this )
    v28 = (float)(damageDef->selfDamageScale * (float)v28);
  if ( (*((_BYTE *)this + 12824) & 0x40) != 0 || (v29 = 0, g_permaGodMode.valueInteger != 0) )
    v29 = 1;
  if ( v29 != 0 && !damageDef->ignoreGodMode )
    v28 = 0.0;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v31 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v31 = 0;
  if ( (*(_BYTE *)(v31 + 47033) & 4) != 0 )
    v28 = 0.0;
  if ( gameLocal->world != nullptr && gameLocal->world->mapType == MAPTYPE_TOWN )
    v28 = 0.0;
  if ( g_damageSave.valueInteger != 0 )
  {
    v32 = ((double (__fastcall *)(idTungstenHealth *))this->playerHealth.GetBaseHealthRatio_Impl)(a1: &this->playerHealth);
    if ( v32 < 0.25 )
      v32 = 0.25;
    *a8 = (float)v32 * (float)v28;
  }
  else
  {
    *a8 = v28;
  }
}


// ========================================================================
// ?Event_EquipItem@idPlayer@@AAA?AVeventBool@@PBD@Z
// EA  : 0x82E2F628
// RVA : 0x00E2F628
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_EquipItem(idPlayer *this, idPlayer *result, const char *declName)
{
  const idDeclJob *v6; // r30
  idJobManager *v7; // r3
  idWeapon *JobByDecl; // r3
  idWeapon *v9; // r30
  idWeapon *v10; // r3
  idWeapon *v11; // r29
  const idDeclInventory *decl; // r11
  idPresentable *presentable; // r3
  equipSlot_t equipSlot; // r31
  int v15; // r3
  bool v17; // r3

  if ( declName == nullptr
    || (v6 = (const idDeclJob *)idDeclInfo::FindWithInheritance(
                                  this: &idDeclInventory::resourceList,
                                  name: declName,
                                  makeDefault: false)) == nullptr )
  {
    idLib::Warning(fmt: "Unknown decl '%s'", declName);
    goto LABEL_12;
  }
  v7 = (idJobManager *)result->GetInventory_2(this: result);
  JobByDecl = (idWeapon *)idJobManager::FindJobByDecl(this: v7, jobDecl: v6);
  v9 = JobByDecl;
  if ( JobByDecl == nullptr )
  {
    idLib::Warning(fmt: "Item '%s' not found in inventory", declName);
LABEL_12:
    eventBool::eventBool((eventBool *)this, b: false);
    return this;
  }
  v10 = idWeapon::CastTo(c: JobByDecl);
  v11 = v10;
  if ( v10 != nullptr )
  {
    decl = v10->decl;
    presentable = result->presentable;
    equipSlot = decl->equipSlot;
    if ( presentable != nullptr )
      v15 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v15 = 0;
    idHands::SelectWeapon(this: (idHands *)(v15 + 37616), slot: equipSlot, weapon: v11, useIntroBringUp: false);
    eventBool::eventBool((eventBool *)this, b: true);
    return this;
  }
  else
  {
    v17 = idPlayer::EquipItem(this: result, item: v9);
    eventBool::eventBool((eventBool *)this, b: v17);
    return this;
  }
}


// ========================================================================
// ?Use@idPlayer@@UAA_NPAVidEntity@@W4usableState_t@@@Z
// EA  : 0x82E2F758
// RVA : 0x00E2F758
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::Use(idPlayer *this, idEntity *activator, usableState_t usable)
{
  idPresentable *presentable; // r3
  char v4; // r31
  int v5; // r3

  presentable = this->presentable;
  v4 = 0;
  if ( presentable != nullptr )
    v5 = ((int (__fastcall *)(idPresentable *, idEntity *, const usableState_t))presentable->GetPlayerInterface_2)(
           a1: presentable,
           a2: activator,
           a3: usable);
  else
    v5 = 0;
  if ( (*(_BYTE *)(v5 + 47032) & 4) != 0 )
    v4 = 1;
  return v4 != 0;
}


// ========================================================================
// ?Event_NextMap@idPlayer@@AAA?AVeventVoid@@PBD000@Z
// EA  : 0x82E2F7D8
// RVA : 0x00E2F7D8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_NextMap(
        idPlayer *this,
        eventVoid *result,
        const char *mapName,
        const char *spawnSpot,
        void (__fastcall **_layersActive)(idPhysics_StaticMulti *__hidden this, int),
        const char *_layersDeactive)
{
  __int64 v6; // r10
  int len; // r26
  int v13; // r26
  __int64 v14; // r8
  va *v15; // r3
  int v17; // [sp+8h] [-1108h]
  int v18; // [sp+Ch] [-1104h]
  int v19; // [sp+10h] [-1100h]
  int v20; // [sp+14h] [-10FCh]
  int v21; // [sp+18h] [-10F8h]
  int v22; // [sp+1Ch] [-10F4h]
  idStr v23; // [sp+50h] [-10C0h] BYREF
  idStr v24; // [sp+70h] [-10A0h] BYREF
  idStr v25; // [sp+90h] [-1080h] BYREF
  idStr v26; // [sp+B0h] [-1060h] BYREF
  va v27; // [sp+D0h] [-1040h] BYREF

  LODWORD(v6) = 20;
  HIDWORD(v6) = v24.baseBuffer;
  v24.len = 0;
  v24.allocedAndFlag = 20;
  v24.data = v24.baseBuffer;
  v24.baseBuffer[0] = 0;
  v23.allocedAndFlag = 20;
  v23.data = v23.baseBuffer;
  v23.len = 0;
  v23.baseBuffer[0] = 0;
  idGameLayerManager::GetLayerStrings(
    this: (idGameLayerManager *)&result[12576],
    activeLayerString: &v24,
    deactiveLayerString: &v23,
    propagateTheNextMapLayers: 1,
    a5: _layersActive,
    layerState: (int)v23.baseBuffer,
    a7: v6);
  idStr::idStr(this: &v26, text: (const char *)_layersActive);
  idStr::idStr(this: &v25, text: _layersDeactive);
  if ( v26.len == 0 && v25.len == 0 )
  {
    len = v24.len;
    idStr::EnsureAlloced(this: &v26, amount: v24.len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v26.data, Src: v24.data, Size: len);
    v26.data[len] = 0;
    v26.len = len;
    v13 = v23.len;
    idStr::EnsureAlloced(this: &v25, amount: v23.len + 1, keepold: false, geometricGrowth: false);
    memcpy(Dst: v25.data, Src: v23.data, Size: v13);
    v25.data[v13] = 0;
    v25.len = v13;
  }
  LODWORD(v14) = &byte_8200D768;
  HIDWORD(v14) = spawnSpot;
  v15 = va::va(
          this: &v27,
          fmt: "nextmap %d %s \"%s\" \"%s\" \"%s\" \"%s\"\n",
          a3: (unsigned int)mapName,
          a4: v14,
          a5: __SPAIR64__((unsigned int)v26.data, (unsigned int)v25.data),
          a6: v17,
          a7: v18,
          a8: v19,
          a9: v20,
          a10: v21,
          a11: v22);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v15->buffer);
  idStr::FreeData(this: &v25);
  idStr::FreeData(this: &v26);
  idStr::FreeData(this: &v23);
  idStr::FreeData(this: &v24);
  return this;
}


// ========================================================================
// __unwind$514483
// EA  : 0x82E2F95C
// RVA : 0x00E2F95C
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_514483()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 112));
}


// ========================================================================
// __unwind$514484
// EA  : 0x82E2F984
// RVA : 0x00E2F984
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_514484()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 80));
}


// ========================================================================
// __unwind$514485
// EA  : 0x82E2F9AC
// RVA : 0x00E2F9AC
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_514485()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 176));
}


// ========================================================================
// __unwind$514486
// EA  : 0x82E2F9D4
// RVA : 0x00E2F9D4
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_514486()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4368 + 144));
}


// ========================================================================
// ?UpdateEditEntityMode@idPlayer@@QAAXXZ
// EA  : 0x82E2FA00
// RVA : 0x00E2FA00
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateEditEntityMode(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  char v4; // r11
  idPresentable *v5; // r3
  int v6; // r31
  idPresentable *v7; // r3
  int v8; // r3
  idPresentable *v9; // r3
  int v10; // r31
  idPresentable *v11; // r3
  int v12; // r3
  idUCmdTracker *UCmdTracker1; // r3
  idUCmdTracker *v14; // r3
  idPresentable *v15; // r3
  int v16; // r3
  bool v17; // r5
  idUCmdTracker *v18; // r3
  idPresentable *v19; // r3
  idPresentable *v20; // r3
  int v21; // r30
  idPresentable *v22; // r3
  int v23; // r3
  idUCmdTracker *v24; // r3
  idUCmdTracker *v25; // r3
  idPresentable *v26; // r3
  int v27; // r31
  idPresentable *v28; // r3
  int v29; // r3
  char v30; // r11

  if ( g_dragEntity.valueInteger != 0 )
    idDragEntity::Update(this: &this->dragEntity, player: this);
  if ( g_editEntityMode.valueInteger != 0 )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v3 = 0;
    if ( idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v3 + 45960), mask: 1) )
    {
      if ( gameLocal->editEntities.selectedEntities.num <= 0 || (v4 = 1, !gameLocal->editEntities.dragging) )
        v4 = 0;
      if ( v4 != 0 )
      {
        if ( g_editEntityMouseDrag.valueInteger != 0 )
        {
          v5 = this->presentable;
          if ( v5 != nullptr )
            v6 = (int)v5->GetPlayerInterface_2(this: v5);
          else
            v6 = 0;
          v7 = this->presentable;
          if ( v7 != nullptr )
            v8 = (int)v7->GetPlayerInterface_2(this: v7);
          else
            v8 = 0;
          idEditEntities::UpdateSelected(
            this: &gameLocal->editEntities,
            origin: (const idVec3 *)(v8 + 46532),
            dir: (const idVec3 *)(v6 + 46544),
            skip: this);
        }
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
        if ( !idEditEntities::SelectEntity(
                this: &gameLocal->editEntities,
                origin: (const idVec3 *)(v12 + 46532),
                dir: (const idVec3 *)(v10 + 46544),
                skip: this) )
          idPlayer::UpdateWeapon(this);
      }
      return;
    }
    UCmdTracker1 = (idUCmdTracker *)idPlayer::GetUCmdTracker1(this);
    if ( idUCmdTracker::IsPressedForPlayer(this: UCmdTracker1, mask: 2) && g_editEntityMouseDrag.valueInteger == 0 )
    {
      v14 = (idUCmdTracker *)idPlayer::GetUCmdTracker1(this);
      if ( idUCmdTracker::IsPressedForPlayer(this: v14, mask: 256) )
      {
        v15 = this->presentable;
        if ( v15 != nullptr )
          v16 = (int)v15->GetPlayerInterface_2(this: v15);
        else
          v16 = 0;
        v17 = true;
      }
      else
      {
        v18 = (idUCmdTracker *)idPlayer::GetUCmdTracker1(this);
        if ( !idUCmdTracker::IsPressedForPlayer(this: v18, mask: 512) )
        {
LABEL_41:
          v20 = this->presentable;
          if ( v20 != nullptr )
            v21 = (int)v20->GetPlayerInterface_2(this: v20);
          else
            v21 = 0;
          v22 = this->presentable;
          if ( v22 != nullptr )
            v23 = (int)v22->GetPlayerInterface_2(this: v22);
          else
            v23 = 0;
          idEditEntities::UpdateSelected(
            this: &gameLocal->editEntities,
            origin: (const idVec3 *)(v23 + 46532),
            dir: (const idVec3 *)(v21 + 46544),
            skip: this);
          return;
        }
        v19 = this->presentable;
        if ( v19 != nullptr )
          v16 = (int)v19->GetPlayerInterface_2(this: v19);
        else
          v16 = 0;
        v17 = false;
      }
      idEditEntities::ZoomEntity(this: &gameLocal->editEntities, camPos: (const idVec3 *)(v16 + 46532), push: v17);
      goto LABEL_41;
    }
    v24 = (idUCmdTracker *)idPlayer::GetUCmdTracker1(this);
    if ( idUCmdTracker::IsPressedForPlayer(this: v24, mask: 4) )
    {
      idEditEntities::EditSelected(this: &gameLocal->editEntities);
    }
    else
    {
      v25 = (idUCmdTracker *)idPlayer::GetUCmdTracker1(this);
      if ( (unsigned __int8)idUCmdTracker::WasPressedForPlayer(this: v25, mask: 8) != 0 )
      {
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
        idEditEntities::DuplicateSelected(
          this: &gameLocal->editEntities,
          origin: (const idVec3 *)(v29 + 46532),
          dir: (const idVec3 *)(v27 + 46544));
      }
      else
      {
        if ( gameLocal->editEntities.selectedEntities.num <= 0 || (v30 = 1, !gameLocal->editEntities.dragging) )
          v30 = 0;
        if ( v30 != 0 )
          idEditEntities::ResetDragging(this: &gameLocal->editEntities);
      }
    }
  }
}


// ========================================================================
// ?GetCoverFirePointVisiblity@idPlayer@@IAAMHH_N@Z
// EA  : 0x82E2FE40
// RVA : 0x00E2FE40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

float __fastcall idPlayer::GetCoverFirePointVisiblity(idPlayer *this, int coverIndex, char flags, const bool debug)
{
  int v8; // r27
  int v9; // r25
  const aas2Cover_t *v10; // r31
  double x; // fp31
  double y; // fp30
  double z; // fp29
  const idAAS2Settings *v14; // r3
  double v15; // fp7
  double v16; // fp6
  double v17; // fp5
  double v20; // fp11
  double v21; // fp1
  double v22; // fp30
  double v23; // fp29
  double v24; // fp28
  float *v25; // r3
  double v26; // fp31
  double v27; // fp21
  double v28; // fp20
  double v29; // fp31
  const aas2Cover_t *v30; // r3
  double v31; // fp0
  double v32; // fp12
  double v33; // fp13
  __int16 v34; // r7
  bool v35; // r9
  bool v36; // r6
  char v37; // r10
  bool v38; // r8
  bool v39; // r7
  char v40; // r11
  double v41; // fp12
  double v42; // fp11
  double v43; // fp8
  double v44; // fp7
  double v45; // fp6
  idColor *v46; // r9
  idColor *v47; // r8
  double v49; // fp1
  idVec3 v51; // [sp+50h] [-F0h] BYREF

  _FP22 = 0.0;
  v8 = 0;
  v9 = coverIndex;
  do
  {
    v10 = this->aas->GetCoverPoint(this: this->aas, a2: this->playerCoverScores.list[v9].coverIndex);
    x = v10->dir.x;
    y = v10->dir.y;
    z = v10->dir.z;
    v14 = this->aas->GetSettings(this: this->aas);
    v15 = (float)((float)(v14->gravityDir.z * (float)x) - (float)(v14->gravityDir.x * (float)z));
    v16 = (float)((float)(v14->gravityDir.x * (float)y) - (float)(v14->gravityDir.y * (float)x));
    v17 = (float)((float)(v14->gravityDir.y * (float)z) - (float)(v14->gravityDir.z * (float)y));
    _FP1 = (float)((float)((float)((float)v17 * (float)v17)
                         + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f12, f1, f2, f0 }
    v20 = __frsqrte(_FP12);
    v21 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20
                                                                                        * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)))
                                                                                                * (float)0.5))
                                                                                * (float)v20)
                                                                        - (float)1.5)
                                                        * (float)v20)
                                                * (float)((float)((float)((float)v17 * (float)v17)
                                                                + (float)((float)((float)v16 * (float)v16)
                                                                        + (float)((float)v15 * (float)v15)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v20
                                                                                * (float)((float)((float)((float)v17 * (float)v17)
                                                                                                + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)))
                                                                                        * (float)0.5))
                                                                        * (float)v20)
                                                                - (float)1.5)
                                                * (float)v20))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v20
                                                        * (float)((float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)((float)v16 * (float)v16)
                                                                                + (float)((float)v15 * (float)v15)))
                                                                * (float)0.5))
                                                * (float)v20)
                                        - (float)1.5)
                        * (float)v20));
    v22 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20)
                                                                                                * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                                * (float)v20))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                                * (float)v20)
                                                                                        - (float)1.5)
                                                                        * (float)v20))
                                                        * (float)((float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)((float)v16 * (float)v16)
                                                                                + (float)((float)v15 * (float)v15)))
                                                                * (float)0.5))
                                                * (float)v21)
                                        - (float)1.5)
                        * (float)v21)
                * (float)v17);
    v23 = (float)((float)v15
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20)
                                                                                                * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                                * (float)v20))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                                * (float)v20)
                                                                                        - (float)1.5)
                                                                        * (float)v20))
                                                        * (float)((float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)((float)v16 * (float)v16)
                                                                                + (float)((float)v15 * (float)v15)))
                                                                * (float)0.5))
                                                * (float)v21)
                                        - (float)1.5)
                        * (float)v21));
    v24 = (float)((float)v16
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v20) - (float)1.5) * (float)v20)
                                                                                                * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5)) * (float)v20) - (float)1.5)
                                                                                                * (float)v20))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v20 * (float)((float)((float)((float)v17 * (float)v17) + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))) * (float)0.5))
                                                                                                * (float)v20)
                                                                                        - (float)1.5)
                                                                        * (float)v20))
                                                        * (float)((float)((float)((float)v17 * (float)v17)
                                                                        + (float)((float)((float)v16 * (float)v16)
                                                                                + (float)((float)v15 * (float)v15)))
                                                                * (float)0.5))
                                                * (float)v21)
                                        - (float)1.5)
                        * (float)v21));
    v25 = (float *)this->aas->GetSettings(this: this->aas);
    v26 = (float)((float)(v25[28] + v25[25]) * (float)0.5);
    v27 = (float)((float)(v25[26] + v25[29]) * (float)0.5);
    v28 = (float)((float)(v25[27] + v25[30]) * (float)0.5);
    v29 = (float)((float)(this->aas->GetSettings(this: this->aas)->coverCornerDistance
                        + (float)((float)((float)((float)__fabs((float)((float)v23
                                                                      * (float)(v25[29]
                                                                              - (float)((float)(v25[26] + v25[29])
                                                                                      * (float)0.5))))
                                                + (float)__fabs((float)((float)v22
                                                                      * (float)(v25[28]
                                                                              - (float)((float)(v25[28] + v25[25])
                                                                                      * (float)0.5)))))
                                        + (float)__fabs((float)((float)v24
                                                              * (float)(v25[30]
                                                                      - (float)((float)(v25[27] + v25[30]) * (float)0.5)))))
                                + (float)((float)((float)v22 * (float)v26)
                                        + (float)((float)((float)v24 * (float)v28) + (float)((float)v23 * (float)v27)))))
                + (float)4.0);
    v30 = this->aas->GetCoverPoint(this: this->aas, a2: this->playerCoverScores.list[v9].coverIndex);
    v31 = v30->origin.x;
    v32 = v30->origin.y;
    if ( (v30->flags & 1) != 0 )
      v33 = (float)(v30->origin.z + (float)56.0);
    else
      v33 = (float)(v30->origin.z + (float)90.0);
    v51.x = v30->origin.x;
    v51.y = v32;
    v51.z = v33;
    v34 = v10->flags;
    v35 = (v34 & 0x140) != 0;
    v36 = (v34 & 0x200) != 0;
    v37 = v34 & 1;
    v38 = (v34 & 0x280) != 0;
    v39 = (v34 & 0x100) != 0;
    if ( v8 != 0 )
    {
      if ( v8 != 1 )
      {
        if ( (unsigned int)v8 >= 3 )
        {
          v40 = 0;
          goto LABEL_25;
        }
        if ( v37 == 0 || (v10->flags & 0x20) == 0 )
        {
LABEL_19:
          v40 = 0;
          goto LABEL_25;
        }
        v41 = (float)(v10->origin.z + (float)90.0);
        v42 = v10->origin.y;
        v51.x = v10->origin.x;
        v51.y = v42;
        v51.z = v41;
        goto LABEL_24;
      }
      if ( (v37 == 0 || (v40 = v38) != 0) && (v38 || (v40 = v36) != 0) )
      {
        v43 = (float)((float)((float)v22 * (float)v29) + (float)v31);
        v44 = (float)((float)((float)v23 * (float)v29) + (float)v32);
        v45 = (float)((float)((float)v24 * (float)v29) + (float)v33);
        goto LABEL_23;
      }
    }
    else
    {
      if ( v37 != 0 && !v35 )
        goto LABEL_19;
      if ( v35 || (v40 = v39) != 0 )
      {
        v43 = (float)((float)v31 - (float)((float)v22 * (float)v29));
        v44 = (float)((float)v32 - (float)((float)v23 * (float)v29));
        v45 = (float)((float)v33 - (float)((float)v24 * (float)v29));
LABEL_23:
        v51.z = v45;
        v51.y = v44;
        v51.x = v43;
LABEL_24:
        v40 = 1;
      }
    }
LABEL_25:
    if ( v40 != 0 )
    {
      if ( debug )
      {
        v46 = &idColor::colorOrange;
        v47 = &idColor::colorYellow;
      }
      else
      {
        v46 = nullptr;
        v47 = nullptr;
      }
      _FP0 = (float)((float)_FP22
                   - idDeferredVisGrid::GetGridVisibility(
                       this: &this->deferredVisGrid,
                       worldPoint: &v51,
                       deferredVisCache: &gameLocal->deferredVisCache,
                       staggerZ: nullptr,
                       flags,
                       missDebugColor: v47,
                       hitDebugColor: v46));
      __asm { fsel      f22, f0, f22, f1 }
    }
    ++v8;
  }
  while ( v8 < 3 );
  v49 = _FP22;
  return *((float *)&v49 + 1);
}


// ========================================================================
// ?RemoveThrowItemAttachments@idPlayer@@QAAXPAVidPresentableProjectile@@@Z
// EA  : 0x82E30240
// RVA : 0x00E30240
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::RemoveThrowItemAttachments(idPlayer *this, idPresentableProjectile *spawnedProjectile)
{
  int v4; // r26
  int v5; // r28
  const idHandle<int,enum invalidAttachment_t,-1> *v6; // r29
  idAttachmentCollection *v7; // r3
  const idAttachment *v8; // r3
  double v9; // fp13
  double v10; // fp12
  double v11; // fp9
  double v12; // fp8
  double v13; // fp5
  double v14; // fp4
  double v15; // fp3
  const idHandle<int,enum invalidAttachment_t,-1> *v16; // r29
  idAttachmentCollection *v17; // r3
  idHandle<int,enum invalidAttachment_t,-1> *list; // r4
  float v19[4]; // [sp+50h] [-90h] BYREF
  float v20[32]; // [sp+60h] [-80h] BYREF

  v4 = 0;
  if ( this->throwableAttachments.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->throwableAttachments.list[v5];
      v7 = this->GetAttachments_2(this);
      v8 = idAttachmentCollection::Get(this: v7, handle: v6);
      if ( v8 != nullptr )
      {
        if ( spawnedProjectile != nullptr )
        {
          v8->presentable->GetWorldTransform(this: v8->presentable, a2: (idVec3 *)v19, a3: (idMat3 *)v20);
          if ( g_projectileDebug.valueInteger != 0 )
          {
            clientGame->renderWorld->DebugAxis_2(
              this: clientGame->renderWorld,
              a2: (const idVec3 *)v19,
              a3: (const idMat3 *)v20,
              a4: 5000,
              a5: false);
            clientGame->renderWorld->DebugAxis_2(
              this: clientGame->renderWorld,
              a2: &spawnedProjectile->origin,
              a3: &spawnedProjectile->axis,
              a4: 0,
              a5: false);
          }
          v9 = v19[1];
          v10 = v19[2];
          spawnedProjectile->launchOrigin.x = v19[0];
          spawnedProjectile->launchOrigin.y = v9;
          spawnedProjectile->launchOrigin.z = v10;
          spawnedProjectile->launchAxis.mat[0].x = v20[0];
          v11 = v20[1];
          v12 = v20[2];
          spawnedProjectile->launchAxis.mat[1].x = v20[3];
          spawnedProjectile->launchAxis.mat[0].y = v11;
          spawnedProjectile->launchAxis.mat[0].z = v12;
          spawnedProjectile->launchAxis.mat[1].y = v20[4];
          v13 = v20[6];
          spawnedProjectile->launchAxis.mat[1].z = v20[5];
          v14 = v20[7];
          spawnedProjectile->launchAxis.mat[2].x = v13;
          v15 = v20[8];
          spawnedProjectile->launchAxis.mat[2].y = v14;
          spawnedProjectile->launchAxis.mat[2].z = v15;
          spawnedProjectile->launched = true;
        }
        v16 = &this->throwableAttachments.list[v5];
        v17 = this->GetAttachments_2(this);
        idAttachmentCollection::RemoveAttachment(this: v17, handle: v16);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->throwableAttachments.num );
  }
  if ( this->throwableAttachments.listStatic == 0 || this->throwableAttachments.listStatic == 2 )
  {
    list = this->throwableAttachments.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->throwableAttachments.list = nullptr;
    this->throwableAttachments.size = 0;
  }
  this->throwableAttachments.num = 0;
}


// ========================================================================
// ?CancelTransition@idPlayer@@QAAXXZ
// EA  : 0x82E30410
// RVA : 0x00E30410
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPlayer::CancelTransition(idPlayer *this)
{
  int v2; // r8 OVERLAPPED
  __int128 v3; // r7 OVERLAPPED
  idPresentable *presentable; // r3
  char v5; // r4
  idPresentable *v6; // r3
  int v7; // r3
  idEntity *Control; // r3
  idList<idEntityPtr<idEntity>,5> *v9; // r3
  idList<idEntityPtr<idEntity>,5> *v10; // r30
  int v11; // r27
  int v12; // r31
  int value; // r9
  idEntity *v14; // r3
  idVolume *v15; // r3
  idEventArg *v16; // r4
  __int64 v17; // [sp+8h] [-118h]
  __int64 v18; // [sp+10h] [-110h]
  __int64 v19; // [sp+18h] [-108h]
  __int64 v20; // [sp+20h] [-100h]
  __int64 v21; // [sp+28h] [-F8h]
  __int64 v22; // [sp+30h] [-F0h]
  __int64 v23; // [sp+38h] [-E8h]
  __int64 v24; // [sp+40h] [-E0h]
  __int64 v25; // [sp+48h] [-D8h]
  __int64 v26; // [sp+50h] [-D0h]
  __int64 v27; // [sp+58h] [-C8h]
  int v28; // [sp+64h] [-BCh]
  int v29; // [sp+68h] [-B8h]
  int v30; // [sp+6Ch] [-B4h]
  int v31[8]; // [sp+70h] [-B0h] BYREF
  int v32; // [sp+90h] [-90h]
  float r; // [sp+94h] [-8Ch]
  __int64 v34; // [sp+98h] [-88h]
  _DWORD v35[5]; // [sp+B0h] [-70h] BYREF
  int v36; // [sp+D0h] [-50h]
  float v37; // [sp+D4h] [-4Ch]
  __int64 v38; // [sp+D8h] [-48h]
  int v39; // [sp+E0h] [-40h]

  HIBYTE(v35[0]) = 105;
  v35[1] = 750;
  v37 = 0.0;
  r = idColor::colorBlack.r;
  *(float *)&v34 = idColor::colorBlack.g;
  HIBYTE(v36) = 102;
  *((float *)&v34 + 1) = idColor::colorBlack.b;
  HIBYTE(v32) = 118;
  memcpy(Dst: v31, Src: v35, Size: 0x14u);
  v2 = __ROL4__(v36, 32);
  DWORD1(v3) = v32;
  *((_QWORD *)&v3 + 1) = v34;
  idEventReceiver::PostEventMS(
    this,
    ev: &EV_FadeView,
    arg1: *(__int64 *)((char *)&v3 + 4),
    arg3: *(__int64 *)&v2,
    a5: v38,
    a6: v17,
    a7: v18,
    a8: v19,
    a9: v20,
    a10: v21,
    a11: v22,
    a12: v23,
    a13: v24,
    a14: v25,
    a15: v26,
    a16: v27,
    a17: v39,
    a18: v28,
    a19: v29,
    a20: v30,
    a21: v31[0]);
  idPlayer::SetForceInhibitControl(this, inhibit: false);
  presentable = this->presentable;
  v5 = *((_BYTE *)this + 12824) & 0xFB;
  *(_BYTE *)&this->flags |= 2u;
  *((_BYTE *)this + 12824) = v5;
  if ( presentable != nullptr && presentable->GetPlayerInterface_2(this: presentable) != nullptr )
  {
    v6 = this->presentable;
    if ( v6 != nullptr )
      v7 = (int)v6->GetPlayerInterface_2(this: v6);
    else
      v7 = 0;
    idPlayerHud::SetHudState(this: (idPlayerHud *)(v7 + 35096), state: HUDSTATE_ALL);
  }
  if ( idPlayer::GetControl(this) != nullptr )
  {
    Control = idPlayer::GetControl(this);
    *(_BYTE *)&Control->flags |= 2u;
  }
  idJobManager::RemoveDiscSwappingJobs(this: &this->jobManager);
  v9 = this->GetTriggerTouchList_2(this);
  v10 = v9;
  if ( v9 != nullptr )
  {
    v11 = 0;
    if ( v9->num > 0 )
    {
      v12 = 0;
      do
      {
        value = v10->list[v12].spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v14 = gameLocal->entities.ptr[value & 0x1FFF];
          if ( v14 != nullptr )
          {
            v15 = (idVolume *)idEntity::CastTo(c: v14);
            if ( v15 != nullptr )
            {
              v16 = (idEventArg *)idVolume::CastTo(c: v15);
              if ( v16 != nullptr )
                idEntity::UntouchTrigger(this, trigger: v16);
            }
          }
        }
        ++v11;
        ++v12;
      }
      while ( v11 < v10->num );
    }
  }
}


// ========================================================================
// ?UpdateWeaponZoom@idPlayer@@IAAXXZ
// EA  : 0x82E30620
// RVA : 0x00E30620
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateWeaponZoom(idPlayer *this)
{
  idWeapon *EquippedWeapon; // r3
  bool v3; // r30
  idPresentable *presentable; // r3
  idPresentablePlayer *v5; // r3
  float *FocusTracker; // r3
  double dofCurrentFocus; // fp13
  double valueFloat; // fp0
  idPresentable *v9; // r3
  int v10; // r3
  idPresentable *v11; // r3
  int v12; // r3
  float v13; // [sp+50h] [-70h] BYREF
  float v14; // [sp+54h] [-6Ch]
  float v15; // [sp+58h] [-68h]
  idVec4 v16; // [sp+60h] [-60h] BYREF
  _BYTE v17[48]; // [sp+70h] [-50h] BYREF

  EquippedWeapon = idActor::GetEquippedWeapon(this, slot: EQUIP_RIGHT_HAND);
  v3 = EquippedWeapon != nullptr && (*((_BYTE *)EquippedWeapon + 452) & 8) != 0;
  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = nullptr;
  if ( idPresentablePlayer::IsZoomedIn(ptr: v5) && v3 )
  {
    if ( dof_focus.valueFloat <= 0.0 )
    {
      this->GetViewTransform(this, a2: (idVec3 *)&v13, a3: (idMat3 *)v17);
      FocusTracker = (float *)idPlayer::GetFocusTracker(this);
      this->dofGoalFocus = __fsqrts((float)((float)((float)(FocusTracker[70] - v13) * (float)(FocusTracker[70] - v13))
                                          + (float)((float)((float)(FocusTracker[72] - v15)
                                                          * (float)(FocusTracker[72] - v15))
                                                  + (float)((float)(FocusTracker[71] - v14)
                                                          * (float)(FocusTracker[71] - v14)))));
    }
    else
    {
      this->dofGoalFocus = dof_focus.valueFloat;
    }
    if ( this->dofCurrentFocus != this->dofGoalFocus )
      this->dofCurrentFocus = (float)((float)(this->dofGoalFocus - this->dofCurrentFocus) * dof_lerpPerFrame.valueFloat)
                            + this->dofCurrentFocus;
    dofCurrentFocus = this->dofCurrentFocus;
    v16.x = this->dofCurrentFocus;
    v16.y = dof_near.valueFloat;
    if ( dof_useFocusScale.valueInteger != 0 )
      valueFloat = (float)(dof_focusScale.valueFloat * (float)dofCurrentFocus);
    else
      valueFloat = dof_far.valueFloat;
    v9 = this->presentable;
    v16.z = valueFloat;
    v16.w = dof_blur.valueFloat;
    if ( v9 != nullptr )
      v10 = (int)v9->GetPlayerInterface_2(this: v9);
    else
      v10 = 0;
    idView::SetEnvironmentParm(this: (idView *)(v10 + 16224), parm: rp->depthOfField, val: &v16, blendDuration: 0.0);
  }
  else if ( this->dofCurrentFocus != 0.0 )
  {
    v11 = this->presentable;
    this->dofCurrentFocus = 0.0;
    if ( v11 != nullptr )
      v12 = (int)v11->GetPlayerInterface_2(this: v11);
    else
      v12 = 0;
    idView::ClearEnvironmentParm(this: (idView *)(v12 + 16224), parm: rp->depthOfField, blendDuration: 0.0);
  }
}


// ========================================================================
// ?debugHUDPrintfVA@idPlayer@@QAAXPBDPAD@Z
// EA  : 0x82E30868
// RVA : 0x00E30868
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::debugHUDPrintfVA(idPlayer *this, const char *fmt, char *argptr)
{
  int v6; // r30
  int v7; // r5
  __int64 v8; // r8
  int v9; // r3
  __int64 v10; // r11
  float v11[4]; // [sp+60h] [-80h] BYREF
  float v12[4]; // [sp+70h] [-70h] BYREF
  idStr v13[3]; // [sp+80h] [-60h] BYREF

  v12[0] = p_debugHudForegroundR.valueFloat;
  v12[1] = p_debugHudForegroundG.valueFloat;
  v12[2] = p_debugHudForegroundB.valueFloat;
  v12[3] = p_debugHudForegroundA.valueFloat;
  v11[0] = p_debugHudBackgroundR.valueFloat;
  v11[1] = p_debugHudBackgroundG.valueFloat;
  v11[2] = p_debugHudBackgroundB.valueFloat;
  v11[3] = p_debugHudBackgroundA.valueFloat;
  debugHUD->SetTextScale(this: debugHUD, a2: sDebugHud_scale_0);
  debugHUD->Printf_4(
    this: debugHUD,
    a2: this->debugHud_x,
    a3: this->debugHud_y,
    a4: (const idColor *)v12,
    a5: (const idColor *)v11,
    a6: fmt,
    a7: argptr);
  idStr::idStr(this: v13, text: fmt);
  v6 = 1;
  v7 = 0;
  while ( 1 )
  {
    v9 = idStr::Find(str: v13[0].data, c: 10, start: v7, end: v13[0].len);
    if ( v9 == -1 )
      break;
    v7 = v9 + 1;
    ++v6;
  }
  LODWORD(v10) = v6;
  HIDWORD(v10) = this->debugHud_y;
  LODWORD(v8) = HIDWORD(v10);
  this->debugHud_y = (int)(float)((float)((float)((float)v10 * SMALLCHAR_HEIGHT) * sDebugHud_scale_0) + (float)v8);
  idStr::FreeData(this: v13);
}


// ========================================================================
// __unwind$516200_0
// EA  : 0x82E309E4
// RVA : 0x00E309E4
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_516200_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// ?SetVehicleInfo@idPlayer@@QAA_NPAVidVehicle@@W4garageList_t@@_N@Z
// EA  : 0x82E30E48
// RVA : 0x00E30E48
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::SetVehicleInfo(idPlayer *this, idVehicle *vehicle, int garage, char markForGarageView)
{
  int v8; // r30
  const idDeclEntityDef *entityDef; // r27
  idInventoryCollection *v10; // r3
  idVehicleState **list; // r11
  idVehicleState *v12; // r29
  idStr *v14; // r3
  idList<idVehicleState *,5> v15; // [sp+50h] [-70h] BYREF
  idStr v16[3]; // [sp+60h] [-60h] BYREF

  if ( vehicle == nullptr )
  {
    idLib::Warning(fmt: "NULL vehicle in idPlayer::SetVehicleInfo");
    return 0;
  }
  v8 = 0;
  entityDef = vehicle->entityDef;
  memset(&v15, 0, 14);
  *(_WORD *)&v15.memTag = 1280;
  idList<idThread *,58>::Clear(this: &v15);
  v10 = this->GetInventory_2(this);
  idInventoryCollection::GetVehicleKeys(this: v10, vehicleList: (idList<idVehicleKey *,5> *)&v15);
  if ( v15.num <= 0 )
  {
LABEL_7:
    if ( (v15.listStatic == 0 || v15.listStatic == 2) && v15.list != nullptr )
      idMem::Free(this: &mem, ptr: v15.list, align: ALIGN_16);
    return 0;
  }
  list = v15.list;
  while ( 1 )
  {
    v12 = *list;
    if ( (const idDeclEntityDef *)(*list)->stateData[9].transitions.list == entityDef )
      break;
    ++v8;
    ++list;
    if ( v8 >= v15.num )
      goto LABEL_7;
  }
  v14 = idStr::idStr(this: v16, text: vehicle->name.data);
  idVehicleKey::SetVehicleEntityName(this: (idVehicleKey *)v12, vehName: v14);
  idVehicleKey::SetValuesFromVehicle(this: (idVehicleKey *)v12, vehicle);
  v12[1].debugName.allocedAndFlag = garage;
  if ( garage != 0 )
    idVehicleKey::SetMinValuesForGarage(this: (idVehicleKey *)v12);
  v12[1].debugName.baseBuffer[1] = markForGarageView;
  if ( (v15.listStatic == 0 || v15.listStatic == 2) && v15.list != nullptr )
    idMem::Free(this: &mem, ptr: v15.list, align: ALIGN_16);
  return 1;
}


// ========================================================================
// __unwind$518015
// EA  : 0x82E30FAC
// RVA : 0x00E30FAC
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_518015()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 80));
}


// ========================================================================
// ?SetupForLevelTransition@idPlayer@@QAAXXZ
// EA  : 0x82E30FE0
// RVA : 0x00E30FE0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetupForLevelTransition(idPlayer *this)
{
  idTungstenHealth *p_playerHealth; // r29
  double v3; // fp1
  __int64 v4; // r7
  idInventoryCollection *v5; // r3
  int v6; // r28
  int v7; // r29
  int allocedAndFlag; // r11
  char v9; // r11
  bool v10; // zf
  idVehicleKey **v11; // r30
  const idVehicle *VehicleFromKey; // r3
  idList<idVehicleState *,5> v13[4]; // [sp+60h] [-40h] BYREF

  p_playerHealth = &this->playerHealth;
  v3 = ((double (__fastcall *)(idTungstenHealth *))this->playerHealth.GetCurBaseHealth_Impl)(a1: &this->playerHealth);
  LODWORD(v4) = g_playerHealthRegenSteps.valueInteger;
  if ( v3 < (float)v4 )
    idBaseHealth::SetCurBaseHealth(this: p_playerHealth, h: (float)v4);
  memset(v13, 0, 14);
  v13[0].listStatic = 0;
  v13[0].memTag = 5;
  idList<idThread *,58>::Clear(this: v13);
  v5 = this->GetInventory_2(this);
  idInventoryCollection::GetVehicleKeys(this: v5, vehicleList: (idList<idVehicleKey *,5> *)v13);
  v6 = 0;
  if ( v13[0].num > 0 )
  {
    v7 = 0;
    do
    {
      allocedAndFlag = v13[0].list[v7][1].debugName.allocedAndFlag;
      if ( allocedAndFlag == 0 || (v10 = allocedAndFlag != 4, v9 = 1, !v10) )
        v9 = 0;
      if ( v9 == 0 && idVehicleKey::GetVehicleFromKey(this: (idVehicleKey *)v13[0].list[v7]) != nullptr )
      {
        v11 = (idVehicleKey **)&v13[0].list[v7];
        VehicleFromKey = idVehicleKey::GetVehicleFromKey(this: (idVehicleKey *)v13[0].list[v7]);
        idVehicleKey::SetValuesFromVehicle(this: *v11, vehicle: VehicleFromKey);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < v13[0].num );
  }
  if ( (v13[0].listStatic == 0 || v13[0].listStatic == 2) && v13[0].list != nullptr )
    idMem::Free(this: &mem, ptr: v13[0].list, align: ALIGN_16);
}


// ========================================================================
// __unwind$518143
// EA  : 0x82E31150
// RVA : 0x00E31150
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_518143()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 160 + 96));
}


// ========================================================================
// ?UpdateAuthorityForce@idPlayer@@QAAXXZ
// EA  : 0x82E31178
// RVA : 0x00E31178
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateAuthorityForce(idPlayer *this)
{
  idPlayer *PlayerSounds; // r3
  char v3; // [sp+50h] [-E0h] BYREF

  if ( this->authorityEndTime != 0 )
  {
    if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL) > this->authorityEndTime )
    {
      idLib::Warning(fmt: "Authority Force has ended");
      this->authorityEndTime = 0;
      this->authorityStartTime = 0;
      idPlayer::RemoveDroppableInfo(this, ent: this);
    }
    if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL) > this->authorityEndTime - 2500
      && !idEntity::IsPlayingSound(this, channel: SND_CHANNEL_JET_PACK) )
    {
      PlayerSounds = idPlayer::GetPlayerSounds(
                       this: (idPlayer *)&v3,
                       result: (const idDeclPlayerProps::playerSounds_t *)this);
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_JET_PACK,
        shader: (const idSoundShader *)PlayerSounds->renderModelInfo.editorModel.allocedAndFlag,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    }
  }
}


// ========================================================================
// ?UseFocus@idPlayer@@QAA_NXZ
// EA  : 0x82E31268
// RVA : 0x00E31268
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::UseFocus(idPlayer *this)
{
  idEntity *BindMaster; // r3
  int v3; // r11
  char v4; // r11
  bool v5; // zf
  idPresentable *presentable; // r3
  int v8; // r3
  int v9; // r8
  idEntity *v10; // r3
  idEntity *v11; // r31
  idPresentable *v12; // r3
  idPresentablePlayer *v13; // r3
  idPresentable *v14; // r3
  idPresentablePlayer *v15; // r3
  int FocusTracker; // r3

  if ( idEntity::GetBindMaster(this) == nullptr )
    goto LABEL_7;
  BindMaster = idEntity::GetBindMaster(this);
  v3 = *(_DWORD *)(BindMaster->GetType(this: BindMaster) + 36);
  if ( v3 < idProp_Moveable::Type.typeNum || (v5 = v3 <= idProp_Moveable::Type.lastChild, v4 = 1, !v5) )
    v4 = 0;
  if ( v4 != 0 )
  {
    idEntity::Unbind(this);
    return true;
  }
  else
  {
LABEL_7:
    presentable = this->presentable;
    if ( presentable != nullptr )
      v8 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v8 = 0;
    v9 = *(_DWORD *)(v8 + 47232);
    if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
      && (v10 = gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr
      && (v11 = idEntity::CastTo(c: v10)) != nullptr
      && ((v12 = this->presentable) == nullptr ? (v13 = nullptr) : (v13 = v12->GetPlayerInterface_2(this: v12)),
          !idPresentablePlayer::IsZoomedIn(ptr: v13)
       && ((v14 = this->presentable) == nullptr ? (v15 = nullptr) : (v15 = v14->GetPlayerInterface_2(this: v14)),
           !idPresentablePlayer::GuiIsActive(this: v15, g: GUI_INVENTORY))) )
    {
      FocusTracker = idPlayer::GetFocusTracker(this);
      return v11->Use(this: v11, a2: this, a3: *(const usableState_t *)(FocusTracker + 524));
    }
    else
    {
      return false;
    }
  }
}


// ========================================================================
// ?BeforeUse@idPlayer@@QAA_NXZ
// EA  : 0x82E31418
// RVA : 0x00E31418
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

BOOL __fastcall idPlayer::BeforeUse(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  int v4; // r8
  idEntity *v5; // r3
  idProp_ContinuallyUsed *v6; // r3
  idProp_ContinuallyUsed *v7; // r3

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  v4 = *(_DWORD *)(v3 + 47232);
  if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13 && (v5 = gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
    v6 = (idProp_ContinuallyUsed *)idEntity::CastTo(c: v5);
  else
    v6 = nullptr;
  v7 = idProp_ContinuallyUsed::CastTo(c: v6);
  return v7 != nullptr && v7->BeforeUse(this: v7, a2: this);
}


// ========================================================================
// ?BeforeUseIsRunning@idPlayer@@QAA_NXZ
// EA  : 0x82E314F0
// RVA : 0x00E314F0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::BeforeUseIsRunning(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  int v4; // r8
  idEntity *v5; // r3
  idProp_ContinuallyUsed *v6; // r3
  idProp_ContinuallyUsed *v7; // r3
  unsigned __int8 v8; // r11

  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  v4 = *(_DWORD *)(v3 + 47232);
  if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13 && (v5 = gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
    v6 = (idProp_ContinuallyUsed *)idEntity::CastTo(c: v5);
  else
    v6 = nullptr;
  v7 = idProp_ContinuallyUsed::CastTo(c: v6);
  if ( v7 == nullptr )
    return 0;
  v8 = 1;
  if ( v7->user != this )
    return 0;
  return v8;
}


// ========================================================================
// ?Use@idPlayer@@QAA_NXZ
// EA  : 0x82E315B0
// RVA : 0x00E315B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::Use(idPlayer *this)
{
  int result; // r3
  idList<idEntityPtr<idEntity>,5> *v3; // r3
  idList<idEntityPtr<idEntity>,5> *v4; // r29
  char v5; // r25
  int v6; // r27
  int v7; // r30
  int value; // r9
  idEntity *v9; // r3
  idVolume *v10; // r3
  idVolume *v11; // r31
  int FocusTracker; // r3

  if ( idPlayer::UseFocus(this) )
    return 1;
  v3 = this->GetTriggerTouchList_2(this);
  v4 = v3;
  if ( v3 == nullptr )
    return 0;
  v5 = 0;
  v6 = 0;
  if ( v3->num > 0 )
  {
    v7 = 0;
    do
    {
      value = v4->list[v7].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v9 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v9 != nullptr )
        {
          v10 = (idVolume *)idEntity::CastTo(c: v9);
          if ( v10 != nullptr )
          {
            v11 = idVolume::CastTo(c: v10);
            if ( v11 != nullptr )
            {
              FocusTracker = idPlayer::GetFocusTracker(this);
              if ( v11->Use(this: v11, a2: this, a3: *(const usableState_t *)(FocusTracker + 524)) )
                v5 = 1;
            }
          }
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < v4->num );
  }
  result = 1;
  if ( v5 == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?GetCurrentNPC@idPlayer@@UBA?AVidStrId@@XZ
// EA  : 0x82E316E0
// RVA : 0x00E316E0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::GetCurrentNPC(idPlayer *this, idPlayer *result)
{
  idEntity *FocusUsable; // r3
  int v5; // r11
  char v6; // r11
  bool v7; // zf

  if ( idPlayer::GetFocusUsable(this: result) == nullptr )
    goto LABEL_7;
  FocusUsable = idPlayer::GetFocusUsable(this: result);
  v5 = *(_DWORD *)(FocusUsable->GetType(this: FocusUsable) + 36);
  if ( v5 < idActor::Type.typeNum || (v7 = v5 <= idActor::Type.lastChild, v6 = 1, !v7) )
    v6 = 0;
  if ( v6 != 0 )
    this->__vftable = (idPlayer_vtbl *)idPlayer::GetFocusUsable(this: result)[8].removeNode.next;
  else
LABEL_7:
    this->__vftable = (idPlayer_vtbl *)-1;
  return this;
}


// ========================================================================
// ?Event_SetDeathTrigger@idPlayer@@AAA?AVeventVoid@@PBD@Z
// EA  : 0x82E31798
// RVA : 0x00E31798
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_SetDeathTrigger(idPlayer *this, eventVoid *result, const char *name)
{
  idEntity *v6; // r3
  int v7; // r9
  idEntity *v8; // r3

  v6 = gameLocal->FindEntity(this: gameLocal, a2: name);
  if ( v6 != nullptr )
    *(_DWORD *)&result[12408] = (gameLocal->spawnIds.ptr[v6->entityNumber] << 13) | v6->entityNumber;
  else
    *(_DWORD *)&result[12408] = 0x1FFF;
  v7 = *(_DWORD *)&result[12408];
  if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] != v7 >> 13
    || (v8 = gameLocal->entities.ptr[v7 & 0x1FFF]) == nullptr
    || idEntity::CastTo(c: v8) == nullptr )
  {
    idLib::Warning(fmt: "setDeathTrigger for %s returned NULL", name);
  }
  return this;
}


// ========================================================================
// ?Event_GetFocusEntity@idPlayer@@AAA?AVeventEntity@@XZ
// EA  : 0x82E31860
// RVA : 0x00E31860
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_GetFocusEntity(idPlayer *this, idPlayer *result)
{
  idEntity *FocusEntity; // r3

  FocusEntity = idPlayer::GetFocusEntity(this: result);
  eventEntity::eventEntity((eventEntity *)this, e: FocusEntity);
  return this;
}


// ========================================================================
// ?UpdateGuiInteraction@idPlayer@@IAAXXZ
// EA  : 0x82E318A0
// RVA : 0x00E318A0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateGuiInteraction(idPlayer *this)
{
  idGameLocal *v2; // r11
  idEntity *v3; // r3
  idEntity *v4; // r3
  idEntity *v5; // r31
  idPresentable *presentable; // r3
  int v7; // r3
  int v8; // r8
  idEntity *v9; // r3
  idEntity *v10; // r3
  idPhysics *Physics; // r3
  int value; // r9
  idPhysics *v13; // r31
  idEntity *v14; // r3
  idEntity *v15; // r3
  idPhysics *v16; // r28
  float *v17; // r31
  float *v18; // r3
  int v19; // r7
  double v20; // fp10
  double v21; // fp8
  char v22; // r30
  double v23; // fp31
  idEntity *v24; // r3
  idAI2 *v25; // r3
  idAI2 *v26; // r3
  idAI2 *v27; // r31
  const idDeclAIPlayerInteraction *decl; // r11
  bool v29; // cr57
  __int64 v30; // r9

  v2 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->guiInteractionEntity.spawnId.value & 0x1FFF] == this->guiInteractionEntity.spawnId.value >> 13 )
  {
    v3 = gameLocal->entities.ptr[this->guiInteractionEntity.spawnId.value & 0x1FFF];
    if ( v3 != nullptr )
    {
      v4 = idEntity::CastTo(c: v3);
      v2 = gameLocal;
      v5 = v4;
    }
    else
    {
      v5 = nullptr;
    }
    presentable = this->presentable;
    if ( presentable != nullptr )
    {
      v7 = (int)presentable->GetPlayerInterface_2(this: presentable);
      v2 = gameLocal;
    }
    else
    {
      v7 = 0;
    }
    v8 = *(_DWORD *)(v7 + 47236);
    if ( v2->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = v2->entities.ptr[v8 & 0x1FFF]) != nullptr )
      v10 = idEntity::CastTo(c: v9);
    else
      v10 = nullptr;
    if ( v5 != v10 )
    {
      Physics = idEntity::GetPhysics(this);
      value = this->guiInteractionEntity.spawnId.value;
      v13 = Physics;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v14 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v15 = idEntity::CastTo(c: v14);
      }
      else
      {
        v15 = nullptr;
      }
      v16 = idEntity::GetPhysics(this: v15);
      v17 = (float *)v13->GetOrigin(this: v13, a2: 0);
      v18 = (float *)v16->GetOrigin(this: v16, a2: 0);
      v19 = this->guiInteractionEntity.spawnId.value;
      v20 = (float)(v18[1] - v17[1]);
      v21 = (float)(v18[2] - v17[2]);
      v22 = 0;
      v23 = (float)((float)((float)(*v18 - *v17) * (float)(*v18 - *v17))
                  + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20)));
      if ( gameLocal->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13
        && (v24 = gameLocal->entities.ptr[v19 & 0x1FFF]) != nullptr )
      {
        v25 = (idAI2 *)idEntity::CastTo(c: v24);
      }
      else
      {
        v25 = nullptr;
      }
      v26 = idAI2::CastTo(c: v25);
      v27 = v26;
      if ( v26 == nullptr
        || v26->IsDead(this: v26)
        || v27 == (idAI2 *)-61208
        || (decl = v27->aiVolatile.aiPlayerInteraction.decl) == nullptr )
      {
        idPlayer::GetFocusTracker(this);
        LODWORD(v30) = 25600;
        v29 = v23 > (float)v30;
      }
      else
      {
        v29 = v23 > (float)(decl->departureRadius * decl->departureRadius);
      }
      if ( v29 )
        v22 = 1;
      if ( v22 != 0 )
        this->guiInteractionEntity.spawnId.value = 0x1FFF;
    }
  }
}


// ========================================================================
// ?debugHUDPrintf@idPlayer@@QAAXPBDZZ
// EA  : 0x82E31B48
// RVA : 0x00E31B48
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void idPlayer::debugHUDPrintf(
        idPlayer *this,
        const char *fmt,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        ...)
{
  __int64 v13; // [sp+90h] [+20h] BYREF
  va_list va; // [sp+90h] [+20h]
  __int64 v15; // [sp+98h] [+28h]
  __int64 v16; // [sp+A0h] [+30h]
  __int64 v17; // [sp+A8h] [+38h]
  __int64 v18; // [sp+B0h] [+40h]
  __int64 v19; // [sp+B8h] [+48h]
  va_list va1; // [sp+C0h] [+50h] BYREF

  va_start(va1, a11);
  va_start(va, a11);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  va_arg(va1, _DWORD);
  v13 = *(__int64 *)((char *)&a3 + 4);
  v15 = a3;
  v16 = *(__int64 *)((char *)&a4 + 4);
  v17 = a4;
  v18 = *(__int64 *)((char *)&a5 + 4);
  v19 = a5;
  if ( !console->IsActive(this: console) )
    idPlayer::debugHUDPrintfVA(this, fmt, argptr: va);
}


// ========================================================================
// ?DrawInventory@idPlayer@@QAAXPAVidEntity@@@Z
// EA  : 0x82E31BD8
// RVA : 0x00E31BD8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::DrawInventory(idPlayer *this, idEntity *entity)
{
  bfx::Planner3D *v4; // r3
  idInventoryCollection *v5; // r28
  bfx::Space *TypeDef; // r29
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  int i; // r30
  idInventoryItem *InventoryItem; // r3
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  int v15; // [sp+8h] [-C8h]
  int v16; // [sp+8h] [-C8h]
  int v17; // [sp+Ch] [-C4h]
  int v18; // [sp+Ch] [-C4h]
  int v19; // [sp+10h] [-C0h]
  int v20; // [sp+10h] [-C0h]
  int v21; // [sp+14h] [-BCh]
  int v22; // [sp+14h] [-BCh]
  int v23; // [sp+18h] [-B8h]
  int v24; // [sp+18h] [-B8h]
  int v25; // [sp+1Ch] [-B4h]
  int v26; // [sp+1Ch] [-B4h]
  idStr v27[3]; // [sp+70h] [-60h] BYREF

  v4 = (bfx::Planner3D *)entity->GetInventory_2(this: entity);
  v5 = (idInventoryCollection *)v4;
  if ( v4 != nullptr )
  {
    TypeDef = idScriptObject::GetTypeDef(this: v4);
    HIDWORD(v7) = entity->name.data;
    LODWORD(v7) = TypeDef;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "-- inventory for %s (%d items) --",
      a3: v7,
      a4: v9,
      a5: v8,
      a6: v15,
      a7: v17,
      a8: v19,
      a9: v21,
      a10: v23,
      a11: v25);
    for ( i = 0; i < (int)TypeDef; ++i )
    {
      InventoryItem = idInventoryCollection::GetInventoryItem(this: v5, index: i);
      v27[0].allocedAndFlag = 20;
      v27[0].data = v27[0].baseBuffer;
      v27[0].len = 0;
      v27[0].baseBuffer[0] = 0;
      idInventoryItem::DebugGetContentsString(this: InventoryItem, itemString: v27);
      idPlayer::debugHUDPrintf(
        this,
        fmt: v27[0].data,
        a3: v14,
        a4: v13,
        a5: v12,
        a6: v16,
        a7: v18,
        a8: v20,
        a9: v22,
        a10: v24,
        a11: v26);
      idStr::FreeData(this: v27);
    }
  }
}


// ========================================================================
// __unwind$519487
// EA  : 0x82E31C94
// RVA : 0x00E31C94
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_519487()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 112));
}


// ========================================================================
// ?DrawPlayerInventory@idPlayer@@QAAXXZ
// EA  : 0x82E31CC8
// RVA : 0x00E31CC8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::DrawPlayerInventory(idPlayer *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  equipSlot_t v5; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  idWeapon *EquippedWeapon; // r3
  _DWORD *v10; // r30
  const idDeclAmmo *v11; // r4
  char v12; // r10
  idDeclWeapon *decl; // r3
  const char *str; // r28
  int ClipSize; // r27
  int v16; // r3
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  int v20; // [sp+8h] [-C8h]
  int v21; // [sp+8h] [-C8h]
  int v22; // [sp+Ch] [-C4h]
  int v23; // [sp+Ch] [-C4h]
  int v24; // [sp+10h] [-C0h]
  int v25; // [sp+10h] [-C0h]
  int v26; // [sp+14h] [-BCh]
  int v27; // [sp+14h] [-BCh]
  int v28; // [sp+18h] [-B8h]
  int v29; // [sp+18h] [-B8h]
  int v30; // [sp+1Ch] [-B4h]
  int v31; // [sp+1Ch] [-B4h]
  idStr v32[2]; // [sp+80h] [-50h] BYREF

  idPlayer::DrawInventory(this, entity: this);
  idPlayer::debugHUDPrintf(
    this,
    fmt: "-- player current weapon info --",
    a3: v4,
    a4: v3,
    a5: v2,
    a6: v20,
    a7: v22,
    a8: v24,
    a9: v26,
    a10: v28,
    a11: v30);
  v5 = this->GetWeaponSlot(this);
  EquippedWeapon = idActor::GetEquippedWeapon(this, slot: v5);
  if ( EquippedWeapon != nullptr )
  {
    v10 = &EquippedWeapon->ammoClip->__vftable;
    v32[0].len = 0;
    v32[0].allocedAndFlag = 20;
    v32[0].data = v32[0].baseBuffer;
    v32[0].baseBuffer[0] = 0;
    v11 = (const idDeclAmmo *)v10[3];
    if ( v11->stackable )
    {
      v12 = *((_BYTE *)EquippedWeapon + 452);
      decl = (idDeclWeapon *)EquippedWeapon->decl;
      str = decl->name.str;
      ClipSize = idDeclWeapon::GetClipSize(this: decl, ammoDecl: v11, weaponUpgraded: (v12 & 4) != 0, secondary: false);
      v16 = (*(int (__fastcall **)(_DWORD *))(*v10 + 52))(a1: v10);
      idStr::Format(this: v32, fmt: "%s (%d rounds/%d)", str, v16, ClipSize);
    }
    else
    {
      idStr::Format(this: v32, fmt: "%s", EquippedWeapon->decl->name.str);
    }
    HIDWORD(v19) = v32[0].data;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "CURRENT WEAPON: %s",
      a3: v19,
      a4: v18,
      a5: v17,
      a6: v21,
      a7: v23,
      a8: v25,
      a9: v27,
      a10: v29,
      a11: v31);
    idStr::FreeData(this: v32);
  }
  else
  {
    idPlayer::debugHUDPrintf(
      this,
      fmt: "CURRENT WEAPON: none",
      a3: v8,
      a4: v7,
      a5: v6,
      a6: v21,
      a7: v23,
      a8: v25,
      a9: v27,
      a10: v29,
      a11: v31);
  }
}


// ========================================================================
// __unwind$519545
// EA  : 0x82E31E00
// RVA : 0x00E31E00
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_519545()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 208 + 128));
}


// ========================================================================
// ?SpawnVehicles@idPlayer@@QAAXXZ
// EA  : 0x82E32428
// RVA : 0x00E32428
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SpawnVehicles(idPlayer *this)
{
  idGameLocal *v2; // r3
  idLinkList<idEntity> *next; // r11
  idTownGarageManager *owner; // r30
  idTownGarageManager *v5; // r3
  idLinkList<idEntity> *v6; // r11
  idEntity *v7; // r17
  idInventoryCollection *v8; // r3
  int v9; // r15
  int v10; // r8
  idVehicleKey *v11; // r26
  char v12; // r11
  char v13; // r18
  char v14; // r24
  char v15; // r22
  idInfoGarageBay *v16; // r21
  garageList_t vehicleGarage; // r11
  char v18; // r11
  bool v19; // zf
  idPhysics *Physics; // r3
  float *v21; // r3
  double v22; // fp13
  double v23; // fp12
  idPresentable *presentable; // r3
  const idAngles *v25; // r4
  double z; // fp11
  double x; // fp10
  double v28; // fp7
  double v29; // fp6
  double v30; // fp5
  float y; // r10
  float v32; // r9
  double v33; // fp13
  char v34; // r27
  int v35; // r28
  int v36; // r30
  int value; // r8
  idInfoGarageBay *v38; // r3
  idInfoGarageBay *v39; // r3
  idInfoGarageBay *v40; // r29
  int v41; // r28
  int num; // r11
  int v43; // r29
  int v44; // r8
  idInfoGarageBay *v45; // r3
  idInfoGarageBay *v46; // r3
  idInfoGarageBay *v47; // r30
  int v48; // r28
  int v49; // r29
  int v50; // r8
  idInfoGarageBay *v51; // r3
  float v52; // r6
  float *v53; // r10
  float v54; // r8
  idInfoGarageBay *v55; // r9
  double v56; // fp13
  int v57; // ctr
  double v58; // fp0
  double v59; // fp13
  double v60; // fp12
  double v61; // fp11
  double v62; // fp10
  double v63; // fp9
  double v64; // fp8
  double v65; // fp7
  double v66; // fp6
  float v67; // r8
  float *v68; // r10
  float v69; // r7
  idInfoGarageBay *p_z; // r9
  double v71; // fp0
  int v72; // ctr
  double v73; // fp13
  idEntity *v74; // r30
  idPhysics *v75; // r3
  float v76; // r10
  float v77; // r9
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r7
  float *v79; // r3
  int v80; // r29
  int v81; // r11
  int v82; // r8
  idEntity *v83; // r3
  idEntity *v84; // r3
  idPhysics *v85; // r3
  int v86; // r3
  float v87; // r8
  float v88; // r7
  double v89; // fp13
  double v90; // fp0
  idPhysics *v91; // r3
  int v92; // r3
  float *v93; // r10
  _DWORD *v94; // r11
  int i; // ctr
  double v96; // fp12
  double v97; // fp11
  double v98; // fp10
  double v99; // fp9
  double v100; // fp8
  double v101; // fp7
  double v102; // fp6
  float v103; // r10
  float v104; // r9
  idPhysics *v105; // r3
  float *v106; // r3
  double v107; // fp23
  float v108; // r7
  float v109; // r9
  double v110; // fp6
  double v112; // fp8
  double v114; // fp2
  double v115; // fp11
  double v116; // fp9
  idVehicle *v117; // r3
  idVehicle *v118; // r30
  idStr *v119; // r27
  int allocedAndFlag; // r11
  size_t len; // r28
  int v122; // r4
  idWorldspawn::mapType_t mapType; // [sp+54h] [-2ACh]
  idList<idVehicleKey *,5> v124; // [sp+60h] [-2A0h] BYREF
  int v125; // [sp+70h] [-290h]
  float v126; // [sp+78h] [-288h]
  float v127; // [sp+7Ch] [-284h]
  float v128; // [sp+80h] [-280h]
  float v129; // [sp+88h] [-278h]
  float v130; // [sp+8Ch] [-274h]
  float v131; // [sp+90h] [-270h]
  float v132; // [sp+98h] [-268h]
  float v133; // [sp+9Ch] [-264h]
  float v134; // [sp+A0h] [-260h]
  float v135; // [sp+A8h] [-258h]
  float v136; // [sp+ACh] [-254h]
  float v137; // [sp+B0h] [-250h]
  const char *v138; // [sp+B4h] [-24Ch]
  const char *v139; // [sp+B8h] [-248h]
  float v140; // [sp+C0h] [-240h]
  float v141; // [sp+C4h] [-23Ch]
  float v142; // [sp+C8h] [-238h]
  float v143; // [sp+D0h] [-230h]
  float v144; // [sp+D4h] [-22Ch]
  float v145; // [sp+D8h] [-228h]
  float v146; // [sp+E0h] [-220h]
  float v147; // [sp+E4h] [-21Ch]
  float v148; // [sp+E8h] [-218h]
  float v149; // [sp+F0h] [-210h]
  float v150; // [sp+F4h] [-20Ch]
  float v151; // [sp+F8h] [-208h]
  idMat3 v152; // [sp+100h] [-200h] BYREF
  float v153; // [sp+124h] [-1DCh]
  float v154; // [sp+128h] [-1D8h]
  float v155; // [sp+12Ch] [-1D4h]
  float v156; // [sp+130h] [-1D0h]
  float v157[12]; // [sp+13Ch] [-1C4h] BYREF
  float v158[12]; // [sp+16Ch] [-194h] BYREF
  float v159[13]; // [sp+19Ch] [-164h] BYREF
  float v160[10]; // [sp+1D0h] [-130h] BYREF
  int v161; // [sp+1F8h] [-108h] BYREF
  int v162; // [sp+208h] [-F8h] BYREF

  if ( this->shouldHideVehicles )
  {
    this->shouldHideVehicles = false;
    return;
  }
  v2 = gameLocal;
  mapType = gameLocal->world->mapType;
  if ( mapType == MAPTYPE_OUTDOOR || mapType == MAPTYPE_TOWN )
  {
    next = gameLocal->spawnedEntities.next;
    if ( next != nullptr && next != gameLocal->spawnedEntities.head )
    {
      owner = (idTownGarageManager *)next->owner;
      if ( owner != nullptr )
      {
        while ( 1 )
        {
          v5 = idTownGarageManager::CastTo(c: owner);
          if ( v5 != nullptr )
            break;
          v6 = owner->spawnNode.next;
          if ( v6 != nullptr && v6 != owner->spawnNode.head )
          {
            owner = (idTownGarageManager *)v6->owner;
            if ( owner != nullptr )
              continue;
          }
          v2 = gameLocal;
          goto LABEL_13;
        }
        idTownGarageManager::SpawnVehicles(this: v5, player: this);
        return;
      }
    }
LABEL_13:
    v7 = v2->FindEntity(this: v2, a2: "vehicle_multispawn_1");
    *(_WORD *)&v124.memTag = 1280;
    memset(&v124, 0, 14);
    v125 = 0;
    v8 = this->GetInventory_2(this);
    idInventoryCollection::GetVehicleKeys(this: v8, vehicleList: &v124);
    v9 = 0;
    if ( v124.num <= 0 )
    {
LABEL_106:
      if ( (v124.listStatic == 0 || v124.listStatic == 2) && v124.list != nullptr )
        idMem::Free(this: &mem, ptr: v124.list, align: ALIGN_16);
      return;
    }
    v138 = "w:\\tech5\\shared\\idlib\\text/Str.h";
    v10 = 0;
    v139 = "amount <= GetAlloced()";
    while ( 1 )
    {
      v11 = v124.list[v10];
      if ( !v11->enterVehicle || (v12 = 1, gameLocal->world->mapType == MAPTYPE_TOWN) )
        v12 = 0;
      v13 = v12;
      v14 = 0;
      v15 = 0;
      v16 = nullptr;
      if ( gameLocal->world->mapType == MAPTYPE_OUTDOOR )
      {
        vehicleGarage = v11->vehicleGarage;
        if ( vehicleGarage == GARAGE_NONE || (v19 = vehicleGarage != GARAGE_MAX, v18 = 1, !v19) )
          v18 = 0;
        if ( v18 == 0 || v13 != 0 )
        {
          v14 = 1;
          if ( v13 != 0 )
          {
            Physics = idEntity::GetPhysics(this);
            v21 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
            v22 = *v21;
            v23 = (float)(v21[2] + (float)32.0);
            v11->position.y = v21[1];
            v11->position.z = v23;
            v11->position.x = v22;
            presentable = this->presentable;
            if ( presentable != nullptr )
              v25 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
            else
              v25 = nullptr;
            v152.mat[0].y = *((float *)&idPresentablePlayer::GetViewAngles(
                                          this: (idPresentablePlayer *)&v161,
                                          result: v25,
                                          includeWeaponKick: true)->__vftable
                            + 1);
            v152.mat[0].x = 0.0;
            v152.mat[0].z = 0.0;
            idAngles::ToMat3(this: (idAngles *)&v152.mat[1].y, result: &v152);
            v11->orientation.mat[0].x = v152.mat[1].y;
            z = v152.mat[1].z;
            x = v152.mat[2].x;
            v11->orientation.mat[1].x = v152.mat[2].y;
            v11->orientation.mat[0].y = z;
            v11->orientation.mat[0].z = x;
            v11->orientation.mat[1].y = v152.mat[2].z;
            v28 = v154;
            v11->orientation.mat[1].z = v153;
            v29 = v155;
            v11->orientation.mat[2].x = v28;
            v30 = v156;
            v11->orientation.mat[2].y = v29;
            v11->orientation.mat[2].z = v30;
            v11->vehicleGarage = GARAGE_NONE;
          }
          else
          {
            y = v11->position.y;
            v32 = v11->position.z;
            v146 = v11->position.x;
            v33 = v146;
            v147 = y;
            v148 = v32;
            v11->position.z = v32 + (float)16.0;
            v11->position.y = y;
            v11->position.x = v33;
          }
          goto LABEL_69;
        }
      }
      v34 = 0;
      v35 = 0;
      if ( gameLocal->infoGarageBays.num > 0 )
      {
        v36 = 0;
        while ( 1 )
        {
          value = gameLocal->infoGarageBays.list[v36].spawnId.value;
          if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
          {
            v38 = (idInfoGarageBay *)gameLocal->entities.ptr[value & 0x1FFF];
            if ( v38 != nullptr )
            {
              v39 = idInfoGarageBay::CastTo(c: v38);
              v40 = v39;
              if ( v39 != nullptr
                && idInfoGarageBay::GetVehicle(this: v39) != nullptr
                && idInfoGarageBay::GetVehicle(this: v40)->playerKey == v11 )
              {
                break;
              }
            }
          }
          ++v35;
          ++v36;
          if ( v35 >= gameLocal->infoGarageBays.num )
            goto LABEL_41;
        }
        v34 = 1;
      }
LABEL_41:
      if ( v34 != 0 )
        goto LABEL_105;
      v41 = 0;
      num = gameLocal->infoGarageBays.num;
      if ( num > 0 )
        break;
LABEL_51:
      v48 = 0;
      if ( num > 0 )
      {
        v49 = 0;
        while ( 1 )
        {
          v50 = gameLocal->infoGarageBays.list[v49].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v50 & 0x1FFF] == v50 >> 13
            && (v51 = (idInfoGarageBay *)gameLocal->entities.ptr[v50 & 0x1FFF]) != nullptr )
          {
            v47 = idInfoGarageBay::CastTo(c: v51);
          }
          else
          {
            v47 = nullptr;
          }
          if ( v47->vehicleClass == VEHICLE_CLASSNONE
            && v11->vehicleGarage == v47->garage
            && idInfoGarageBay::GetVehicle(this: v47) == nullptr )
          {
            break;
          }
          ++v48;
          ++v49;
          if ( v48 >= gameLocal->infoGarageBays.num )
            goto LABEL_69;
        }
        v67 = v47->spawnPosition.z;
        v68 = v158;
        v69 = v47->spawnPosition.x;
        v14 = 1;
        p_z = (idInfoGarageBay *)&v47->spawnPosition.z;
        v144 = v47->spawnPosition.y;
        v71 = v144;
        v145 = v67;
        v72 = 9;
        v143 = v69;
        v11->position.x = v69;
        v73 = v145;
        v11->position.y = v71;
        v11->position.z = v73;
        do
        {
          p_z = (idInfoGarageBay *)((char *)p_z + 4);
          *++v68 = *(float *)&p_z->__vftable;
          --v72;
        }
        while ( v72 != 0 );
        v58 = v158[1];
        v15 = 1;
        v59 = v158[4];
        v60 = v158[2];
        v61 = v158[3];
        v62 = v158[5];
        v63 = v158[6];
        v64 = v158[7];
        v65 = v158[8];
        v66 = v158[9];
LABEL_68:
        v11->orientation.mat[0].x = v58;
        v16 = v47;
        v11->orientation.mat[1].x = v59;
        v11->orientation.mat[0].y = v60;
        v11->orientation.mat[0].z = v61;
        v11->orientation.mat[1].y = v62;
        v11->orientation.mat[1].z = v63;
        v11->orientation.mat[2].x = v64;
        v11->orientation.mat[2].y = v65;
        v11->orientation.mat[2].z = v66;
      }
LABEL_69:
      if ( v14 != 0 )
      {
        v74 = v7;
        if ( v7 != nullptr && v16 == nullptr )
        {
          v75 = idEntity::GetPhysics(this: v7);
          v76 = v11->position.y;
          v77 = v11->position.z;
          GetOrigin = v75->GetOrigin;
          v129 = v11->position.x;
          v130 = v76;
          v131 = v77;
          v79 = (float *)GetOrigin(this: v75, a2: 0);
          if ( (float)((float)((float)(v79[2] - v131) * (float)(v79[2] - v131))
                     + (float)((float)((float)(*v79 - v129) * (float)(*v79 - v129))
                             + (float)((float)(v79[1] - v130) * (float)(v79[1] - v130)))) < 4000000.0 )
          {
            v80 = v125;
            if ( v125 > 0 )
            {
              v81 = v125 - 2;
              if ( v125 - 2 >= 0 && v81 < v7->targets.num )
              {
                v82 = v7->targets.list[v81].spawnId.value;
                if ( gameLocal->spawnIds.ptr[v82 & 0x1FFF] == v82 >> 13
                  && (v83 = gameLocal->entities.ptr[v7->targets.list[v81].spawnId.value & 0x1FFF]) != nullptr )
                {
                  v84 = idEntity::CastTo(c: v83);
                }
                else
                {
                  v84 = nullptr;
                }
                v74 = v84;
              }
              if ( v74 != nullptr )
              {
                v85 = idEntity::GetPhysics(this: v74);
                v86 = (int)v85->GetOrigin(this: v85, a2: 0);
                v87 = *(float *)v86;
                v88 = *(float *)(v86 + 8);
                v133 = *(float *)(v86 + 4);
                v89 = v133;
                v132 = v87;
                v134 = v88;
                v11->position.z = v88;
                v90 = v132;
                v11->position.y = v89;
                v11->position.x = v90;
                v91 = idEntity::GetPhysics(this: v74);
                v92 = (int)v91->GetAxis(this: v91, a2: 0);
                v93 = v159;
                v94 = (_DWORD *)(v92 - 4);
                for ( i = 9; i != 0; --i )
                  *++v93 = *(float *)++v94;
                v11->orientation.mat[0].x = v159[1];
                v15 = 1;
                v96 = v159[2];
                v97 = v159[3];
                v11->orientation.mat[1].x = v159[4];
                v98 = v159[5];
                v11->orientation.mat[0].y = v96;
                v11->orientation.mat[0].z = v97;
                v99 = v159[6];
                v11->orientation.mat[1].y = v98;
                v100 = v159[7];
                v11->orientation.mat[1].z = v99;
                v101 = v159[8];
                v11->orientation.mat[2].x = v100;
                v102 = v159[9];
                v11->orientation.mat[2].y = v101;
                v11->orientation.mat[2].z = v102;
              }
            }
            v125 = v80 + 1;
          }
        }
        if ( v15 == 0 && v13 == 0 )
        {
          v103 = v11->position.y;
          v104 = v11->position.z;
          v126 = v11->position.x;
          v127 = v103;
          v128 = v104;
          v105 = idEntity::GetPhysics(this);
          v106 = (float *)v105->GetOrigin(this: v105, a2: 0);
          if ( (float)((float)((float)(*v106 - v126) * (float)(*v106 - v126))
                     + (float)((float)(v106[1] - v127) * (float)(v106[1] - v127))) < 90000.0 )
          {
            v107 = (float)((float)300.0
                         - (float)__fsqrts((float)((float)((float)((float)(v106[2] - v128) * (float)(v106[2] - v128))
                                                         + (float)((float)(*v106 - v126) * (float)(*v106 - v126)))
                                                 + (float)((float)(v106[1] - v127) * (float)(v106[1] - v127)))));
            this->GetViewTransform(this, a2: (idVec3 *)&v162, a3: (idMat3 *)v160);
            v108 = v11->position.z;
            v109 = v11->position.x;
            v141 = v11->position.y;
            v110 = v141;
            v142 = v108;
            v150 = v160[1];
            v140 = v109;
            v149 = v160[0];
            v151 = v160[2];
            _FP9 = (float)((float)((float)(v160[0] * v160[0]) + (float)(v160[1] * v160[1]))
                         - idMath::FLT_SMALLEST_NON_DENORMAL);
            v112 = (float)((float)((float)(v160[0] * v160[0]) + (float)(v160[1] * v160[1])) * (float)0.5);
            __asm { fsel      f3, f9, f10, f0 }
            v114 = __frsqrte(_FP3);
            v115 = (float)((float)-(float)((float)((float)((float)v114
                                                         * (float)((float)((float)(v160[0] * v160[0])
                                                                         + (float)(v160[1] * v160[1]))
                                                                 * (float)0.5))
                                                 * (float)v114)
                                         - (float)1.5)
                         * (float)v114);
            v116 = (float)((float)(v160[1]
                                 * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v115 * (float)v112) * (float)v115)
                                                                                                 - (float)1.5)
                                                                                 * (float)v115)
                                                                         * (float)v112)
                                                                 * (float)((float)-(float)((float)((float)((float)v115 * (float)v112)
                                                                                                 * (float)v115)
                                                                                         - (float)1.5)
                                                                         * (float)v115))
                                                         - (float)1.5)
                                         * (float)((float)-(float)((float)((float)((float)v115 * (float)v112)
                                                                         * (float)v115)
                                                                 - (float)1.5)
                                                 * (float)v115)))
                         * (float)v107);
            v11->position.x = v109
                            + (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v115 * (float)v112) * (float)v115) - (float)1.5)
                                                                                            * (float)v115)
                                                                                    * (float)v112)
                                                                            * (float)((float)-(float)((float)((float)((float)v115 * (float)v112) * (float)v115) - (float)1.5)
                                                                                    * (float)v115))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v115 * (float)v112)
                                                                                    * (float)v115)
                                                                            - (float)1.5)
                                                            * (float)v115))
                                            * v160[0])
                                    * (float)v107);
            v11->position.y = (float)v110 + (float)v116;
            v11->position.z = v108
                            + (float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v115 * (float)v112) * (float)v115) - (float)1.5)
                                                                                            * (float)v115)
                                                                                    * (float)v112)
                                                                            * (float)((float)-(float)((float)((float)((float)v115 * (float)v112) * (float)v115) - (float)1.5)
                                                                                    * (float)v115))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v115 * (float)v112)
                                                                                    * (float)v115)
                                                                            - (float)1.5)
                                                            * (float)v115))
                                            * (float)0.0)
                                    * (float)v107);
          }
        }
        v117 = (idVehicle *)idGameLocal::SpawnPlayerVehicle(this: gameLocal, key: v11);
        v118 = idVehicle::CastTo(c: v117);
        if ( v118 != nullptr )
        {
          v119 = idStr::idStr(this: (idStr *)&v152.mat[1].y, text: v118->name.data);
          allocedAndFlag = v11->referenceVehicleName.allocedAndFlag;
          len = v119->len;
          v122 = v119->len + 1;
          if ( allocedAndFlag >= 0 )
          {
            if ( v122 > (allocedAndFlag & 0x7FFFFFFF) )
              idStr::ReAllocate(this: &v11->referenceVehicleName, amount: v122, keepold: false);
          }
          else if ( v122 > (allocedAndFlag & 0x7FFFFFFF)
                 && AssertFailed(file: v138, line: 463, expression: v139, inlineBreak: true) )
          {
            __trap();
          }
          memcpy(Dst: v11->referenceVehicleName.data, Src: v119->data, Size: len);
          v11->referenceVehicleName.data[len] = 0;
          v11->referenceVehicleName.len = len;
          idStr::FreeData(this: v119);
          idVehicle::SetArmorFromKey(this: v118, key: v11);
          idVehicle::RecalcMaxArmoredHealth(this: v118);
          if ( v11->doTotalRepairOnSpawn )
          {
            idVehicleKey::DoTotalRepair(this: v11);
            v11->doTotalRepairOnSpawn = false;
          }
          if ( v13 != 0 )
          {
            v118->playerKey = v11;
            v118->EnterVehicle(this: v118, a2: this, a3: SEAT_MAX);
          }
          if ( v16 != nullptr )
          {
            v16->vehicle.spawnId.value = (gameLocal->spawnIds.ptr[v118->entityNumber] << 13) | v118->entityNumber;
            v11->garageBay.spawnId.value = (gameLocal->spawnIds.ptr[v16->entityNumber] << 13) | v16->entityNumber;
          }
        }
        else
        {
          idLib::Warning(fmt: "Error spawning vehicle from key %s", *(_DWORD *)(v11->decl[1].trackedMemory + 8));
        }
      }
      v11->enterVehicle = false;
LABEL_105:
      v10 = ++v9;
      if ( v9 >= v124.num )
        goto LABEL_106;
    }
    v43 = 0;
    while ( 1 )
    {
      v44 = gameLocal->infoGarageBays.list[v43].spawnId.value;
      if ( gameLocal->spawnIds.ptr[v44 & 0x1FFF] == v44 >> 13 )
      {
        v45 = (idInfoGarageBay *)gameLocal->entities.ptr[v44 & 0x1FFF];
        if ( v45 != nullptr )
        {
          v46 = idInfoGarageBay::CastTo(c: v45);
          v47 = v46;
          if ( v46 != nullptr
            && (idDeclInventory_vtbl *)v46->vehicleClass == v11->decl[1].__vftable
            && v11->vehicleGarage == v46->garage
            && idInfoGarageBay::GetVehicle(this: v46) == nullptr )
          {
            break;
          }
        }
      }
      ++v41;
      ++v43;
      num = gameLocal->infoGarageBays.num;
      if ( v41 >= num )
        goto LABEL_51;
    }
    v52 = v47->spawnPosition.y;
    v53 = v157;
    v54 = v47->spawnPosition.z;
    v14 = 1;
    v55 = (idInfoGarageBay *)&v47->spawnPosition.z;
    v135 = v47->spawnPosition.x;
    v56 = v135;
    v136 = v52;
    v137 = v54;
    v11->position.z = v54;
    v57 = 9;
    v11->position.y = v52;
    v11->position.x = v56;
    do
    {
      v55 = (idInfoGarageBay *)((char *)v55 + 4);
      *++v53 = *(float *)&v55->__vftable;
      --v57;
    }
    while ( v57 != 0 );
    v58 = v157[1];
    v59 = v157[4];
    v60 = v157[2];
    v61 = v157[3];
    v62 = v157[5];
    v63 = v157[6];
    v64 = v157[7];
    v65 = v157[8];
    v66 = v157[9];
    goto LABEL_68;
  }
}


// ========================================================================
// __unwind$521235
// EA  : 0x82E33060
// RVA : 0x00E33060
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_521235()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 768 + 96));
}


// ========================================================================
// __unwind$521857_0
// EA  : 0x82E33088
// RVA : 0x00E33088
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_521857_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 768 + 80));
}


// ========================================================================
// ?RestartMapForMissionFailure@idPlayer@@QAAXH@Z
// EA  : 0x82E330B8
// RVA : 0x00E330B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::RestartMapForMissionFailure(idPlayer *this, int fadeTime)
{
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentable *v5; // r3
  idPresentablePlayer *v6; // r3
  idPresentable *v7; // r3
  idPresentablePlayer *v8; // r3
  idSWF *v9; // r28
  idSWFScriptFunction *v10; // r3
  idSWFScriptFunction *v11; // r4
  idSWFScriptFunction *v12; // r3
  idSWFScriptFunction *v13; // r4
  idSWFScriptFunction *v14; // r3
  idSWFScriptFunction *v15; // r4
  idSWFScriptFunction *v16; // r3
  idSWFScriptFunction *v17; // r4
  idSWFScriptVar v18; // [sp+50h] [-60h] BYREF
  idSWFScriptVar v19; // [sp+58h] [-58h] BYREF
  idSWFScriptVar v20; // [sp+60h] [-50h] BYREF
  idSWFScriptVar v21[9]; // [sp+68h] [-48h] BYREF

  if ( !this->IsDead(this) )
  {
    if ( gameLocal->world->mapType != MAPTYPE_INSTANCE )
    {
      idLib::Warning(fmt: "RestartMapForMissionFailure called outside of an instance map.");
    }
    else
    {
      idPlayer::DeactivateGuis(this);
      presentable = this->presentable;
      if ( presentable != nullptr )
        v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v4 = 0;
      idPlayerHud::SetHudState(this: (idPlayerHud *)(v4 + 35096), state: HUDSTATE_NONE);
      v5 = this->presentable;
      if ( v5 != nullptr )
        v6 = v5->GetPlayerInterface_2(this: v5);
      else
        v6 = nullptr;
      if ( idPresentablePlayer::GetLocalView(this: v6) != nullptr )
      {
        v7 = this->presentable;
        v8 = v7 != nullptr ? v7->GetPlayerInterface_2(this: v7) : nullptr;
        v9 = idPresentablePlayer::GetLocalView(this: v8)->guisRender.guis[1];
        if ( v9 != nullptr )
        {
          v10 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 0x10u,
                                         tag: TAG_SWF,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
          if ( v10 != nullptr )
          {
            v10[2].__vftable = (idSWFScriptFunction_vtbl *)this;
            v10[3].__vftable = (idSWFScriptFunction_vtbl *)v9;
            v11 = v10;
            v10[1].__vftable = nullptr;
            v10->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::RestartMapForMissionFailure'::`9'::idSWFScriptFunction_PlayerInstanceDeath::`vftable';
          }
          else
          {
            v11 = nullptr;
          }
          idSWFScriptVar::idSWFScriptVar(this: &v18, nf: v11);
          idSWFScriptObject::Set(this: v9->globals, name: "restartLevel", value: &v18);
          idSWFScriptVar::Free(this: &v18);
          v12 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 8u,
                                         tag: TAG_SWF,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
          if ( v12 != nullptr )
          {
            v12[1].__vftable = nullptr;
            v13 = v12;
            v12->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::RestartMapForMissionFailure'::`10'::idSWFScriptFunction_ExitToMenu::`vftable';
          }
          else
          {
            v13 = nullptr;
          }
          idSWFScriptVar::idSWFScriptVar(this: &v19, nf: v13);
          idSWFScriptObject::Set(this: v9->globals, name: "exitGame", value: &v19);
          idSWFScriptVar::Free(this: &v19);
          v14 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 8u,
                                         tag: TAG_SWF,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
          if ( v14 != nullptr )
          {
            v14[1].__vftable = nullptr;
            v15 = v14;
            v14->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::RestartMapForMissionFailure'::`11'::idSWFScriptFunction_setLoadOnly::`vftable';
          }
          else
          {
            v15 = nullptr;
          }
          idSWFScriptVar::idSWFScriptVar(this: &v20, nf: v15);
          idSWFScriptObject::Set(this: v9->globals, name: "loadGameFromSave", value: &v20);
          idSWFScriptVar::Free(this: &v20);
          v16 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                         this: &mem,
                                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                         size: 8u,
                                         tag: TAG_SWF,
                                         zeroBuffer: false,
                                         align: ALIGN_16,
                                         heap: HEAP_DEFAULTHEAP);
          if ( v16 != nullptr )
          {
            v16[1].__vftable = nullptr;
            v17 = v16;
            v16->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::RestartMapForMissionFailure'::`12'::idSWFScriptFunction_loadMostRecent::`vftable';
          }
          else
          {
            v17 = nullptr;
          }
          idSWFScriptVar::idSWFScriptVar(this: v21, nf: v17);
          idSWFScriptObject::Set(this: v9->globals, name: "loadMostRecent", value: v21);
          idSWFScriptVar::Free(this: v21);
          idSWF::Activate(this: v9, b: true);
        }
      }
      *((_BYTE *)this + 12824) |= 8u;
      idPlayer::SetForceInhibitControl(this, inhibit: true);
      *(_BYTE *)&this->flags &= ~2u;
    }
  }
}


// ========================================================================
// __unwind$522324
// EA  : 0x82E333B0
// RVA : 0x00E333B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522324()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$522326
// EA  : 0x82E333D8
// RVA : 0x00E333D8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522326()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 88));
}


// ========================================================================
// __unwind$522328_0
// EA  : 0x82E33400
// RVA : 0x00E33400
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522328_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$522330
// EA  : 0x82E33428
// RVA : 0x00E33428
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522330()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 104));
}


// ========================================================================
// `idPlayer::Killed'::`30'::idSWFScriptFunction_loadMostRecent::Call
// EA  : 0x82E33458
// RVA : 0x00E33458
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idPlayer::Killed_::_30_::idSWFScriptFunction_loadMostRecent::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idStr **v6; // r29
  __int64 v7; // r6
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  int v12; // [sp+8h] [-1098h]
  int v13; // [sp+Ch] [-1094h]
  int v14; // [sp+10h] [-1090h]
  int v15; // [sp+14h] [-108Ch]
  int v16; // [sp+18h] [-1088h]
  int v17; // [sp+1Ch] [-1084h]
  idStr v18; // [sp+60h] [-1040h] BYREF
  va v19; // [sp+80h] [-1020h] BYREF

  v6 = (idStr **)parms;
  LODWORD(a5) = *(_DWORD *)(parms + 4);
  if ( (_DWORD)a5 != 1 )
    idLib::Warning(fmt: "Unable to load game because no game name was passed as parameter");
  idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v18, result: *v6, a3: parms, a4, a5);
  HIDWORD(v7) = v18.data;
  v10 = va::va(
          this: &v19,
          fmt: "loadGame %s\n",
          a3: v7,
          a4: v9,
          a5: v8,
          a6: v12,
          a7: v13,
          a8: v14,
          a9: v15,
          a10: v16,
          a11: v17);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: v10->buffer);
  idLib::Printf(fmt: "Loading %s...\n", v18.data);
  result->type = SWF_VAR_UNDEF;
  idStr::FreeData(this: &v18);
  return result;
}


// ========================================================================
// __unwind$523324
// EA  : 0x82E33508
// RVA : 0x00E33508
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523324()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4256 + 96));
}


// ========================================================================
// __unwind$523325
// EA  : 0x82E33530
// RVA : 0x00E33530
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523325()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4256;
  if ( (*(_DWORD *)(v0 - 4256 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 4276));
  }
}


// ========================================================================
// ?Killed@idPlayer@@QAAXPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@2ABV?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82E33580
// RVA : 0x00E33580
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::Killed(
        idPlayer *this,
        idEntity *inflictor,
        idEntity *attacker,
        const idDeclDamage *damageDecl,
        double damage,
        const idVec3 *impactPoint,
        const idVec3 *impactDir,
        const idIndex<short,enum invalidJointIndex_t> *joint)
{
  int value; // r9
  idEntity *v10; // r3
  idEntity *v11; // r4
  idPresentable *presentable; // r3
  idSWF *v13; // r27
  idPresentablePlayer *v14; // r3
  idPresentable *v15; // r3
  idPresentablePlayer *v16; // r3
  idPhysics *Physics; // r3
  idPhysics *v18; // r3
  idPresentable *v19; // r3
  int v20; // r3
  const idDeclPlayerProps *playerProps; // r11
  idPresentable *v22; // r3
  int v23; // r3
  idPresentable *v24; // r3
  int v25; // r3
  idPresentable *v26; // r3
  int v27; // r3
  __int64 v28; // r8
  int v29; // r6
  idSWFScriptFunction *v30; // r3
  idSWFScriptFunction *v31; // r4
  idSWFScriptFunction *v32; // r3
  idSWFScriptFunction *v33; // r4
  idSWFScriptFunction *v34; // r3
  idSWFScriptFunction *v35; // r4
  idSWFScriptFunction *v36; // r3
  idSWFScriptFunction *v37; // r4
  idSWFScriptVar *v38; // r3
  idSWFScriptFunction *v39; // r3
  idSWFScriptFunction *v40; // r4
  idSWFScriptFunction *v41; // r3
  idSWFScriptFunction *v42; // r4
  idSWFScriptFunction *v43; // r3
  idSWFScriptFunction *v44; // r4
  idSWFScriptFunction *v45; // r3
  idSWFScriptFunction *v46; // r4
  int v47; // [sp+50h] [-160h]
  idSWFScriptVar v48; // [sp+58h] [-158h] BYREF
  idSWFScriptVar v49; // [sp+60h] [-150h] BYREF
  idSWFScriptVar v50; // [sp+68h] [-148h] BYREF
  idSWFScriptVar v51; // [sp+70h] [-140h] BYREF
  idSWFScriptVar v52; // [sp+78h] [-138h] BYREF
  idSWFScriptVar v53; // [sp+80h] [-130h] BYREF
  idSWFScriptVar v54; // [sp+88h] [-128h] BYREF
  idSWFScriptVar v55; // [sp+90h] [-120h] BYREF
  _BYTE v56[24]; // [sp+98h] [-118h] BYREF
  idDeclPlayerProps::playerSounds_t sounds; // [sp+B0h] [-100h] BYREF

  if ( attacker != nullptr )
    this->killer.spawnId.value = (gameLocal->spawnIds.ptr[attacker->entityNumber] << 13) | attacker->entityNumber;
  else
    this->killer.spawnId.value = 0x1FFF;
  value = this->killer.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v10 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v11 = idEntity::CastTo(c: v10);
  }
  else
  {
    v11 = nullptr;
  }
  if ( this->botController != nullptr )
    idBot::OnDeath(this: this->botController, killer: v11);
  *(_BYTE *)&this->flags |= 4u;
  idPlayer::PlayerBehavior_PlayerKilled(this);
  idAnimator_WalkIK::DisableAll(this: &this->walkIK);
  presentable = this->presentable;
  v13 = nullptr;
  if ( presentable != nullptr )
    v14 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v14 = nullptr;
  if ( idPresentablePlayer::GetLocalView(this: v14) != nullptr )
  {
    v15 = this->presentable;
    if ( v15 != nullptr )
      v16 = v15->GetPlayerInterface_2(this: v15);
    else
      v16 = nullptr;
    v13 = idPresentablePlayer::GetLocalView(this: v16)->guisRender.guis[1];
  }
  Physics = idEntity::GetPhysics(this);
  Physics->GetLinearVelocity(this: (idPhysics *)v56, result: (idVec3 *)Physics, a3: 0);
  v18 = idEntity::GetPhysics(this);
  v18->SetLinearVelocity(this: v18, a2: (const idVec3 *)v56, a3: 0);
  v19 = this->presentable;
  if ( v19 != nullptr )
    v20 = (int)v19->GetPlayerInterface_2(this: v19);
  else
    v20 = 0;
  idPhysics_Player::SetMovementType(this: (idPhysics_Player *)(v20 + 36264), type: PM_DEAD);
  playerProps = this->playerProps;
  if ( playerProps != nullptr )
    sounds = playerProps->sounds;
  else
    idDeclPlayerProps::playerSounds_t::playerSounds_t(this: &sounds);
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_VOICE,
    shader: sounds.sndDeath,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  idEntity::StopSound(this, channel: SND_CHANNEL_BODY2, peerMask: 0xFFu);
  idEntity::StopSound(this, channel: SND_CHANNEL_BREATHE, peerMask: 0xFFu);
  v22 = this->presentable;
  *(_BYTE *)&this->flags |= 2u;
  if ( v22 != nullptr )
    v23 = (int)v22->GetPlayerInterface_2(this: v22);
  else
    v23 = 0;
  (*(void (__fastcall **)(int, int, int))(*(_DWORD *)(v23 + 36264) + 24))(a1: v23 + 36264, a2: 135312, a3: -1);
  idEntity::UpdateVisuals(this);
  v24 = this->presentable;
  if ( v24 != nullptr )
    v25 = (int)v24->GetPlayerInterface_2(this: v24);
  else
    v25 = 0;
  idPlayerHud::SetHudState(this: (idPlayerHud *)(v25 + 35096), state: HUDSTATE_DAMAGE);
  idPlayer::DeactivateGuis(this);
  v26 = this->presentable;
  if ( v26 != nullptr )
    v27 = (int)v26->GetPlayerInterface_2(this: v26);
  else
    v27 = 0;
  idPlayerHud::SetHudState(this: (idPlayerHud *)(v27 + 35096), state: HUDSTATE_NONE);
  if ( idGameLocal::GetChallengeMode(this: gameLocal) == CHALLENGE_MODE_NORMAL )
  {
    LODWORD(v28) = gameLocal->world;
    v47 = *(_DWORD *)(v28 + 832);
    if ( v47 == 0 )
    {
      if ( v13 == nullptr )
        return;
      v30 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 8u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v30 != nullptr )
      {
        v30[1].__vftable = nullptr;
        v31 = v30;
        v30->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::Killed'::`14'::idSWFScriptFunction_loadMostRecent::`vftable';
      }
      else
      {
        v31 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v55, nf: v31);
      idSWFScriptObject::Set(this: v13->globals, name: "loadMostRecent", value: &v55);
      idSWFScriptVar::Free(this: &v55);
      v32 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 8u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v32 != nullptr )
      {
        v32[1].__vftable = nullptr;
        v33 = v32;
        v32->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::Killed'::`13'::idSWFScriptFunction_setLoadOnly::`vftable';
      }
      else
      {
        v33 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v50, nf: v33);
      idSWFScriptObject::Set(this: v13->globals, name: "loadGameFromSave", value: &v50);
      idSWFScriptVar::Free(this: &v50);
      v34 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x10u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v34 != nullptr )
      {
        v34[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v34[3].__vftable = (idSWFScriptFunction_vtbl *)v13;
        v35 = v34;
        v34[1].__vftable = nullptr;
        v34->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::Killed'::`11'::idSWFScriptFunction_PlayerInstanceDeath::`vftable';
      }
      else
      {
        v35 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v54, nf: v35);
      idSWFScriptObject::Set(this: v13->globals, name: "restartLevel", value: &v54);
      idSWFScriptVar::Free(this: &v54);
      v36 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 8u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v36 != nullptr )
      {
        v36[1].__vftable = nullptr;
        v37 = v36;
        v36->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::Killed'::`12'::idSWFScriptFunction_ExitToMenu::`vftable';
      }
      else
      {
        v37 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v52, nf: v37);
      idSWFScriptObject::Set(this: v13->globals, name: "exitGame", value: &v52);
      v38 = &v52;
      goto _M523200;
    }
    if ( v47 != 1 && v47 != 3 )
    {
      idEventReceiver::PostEventMS(
        this,
        ev: &EV_Respawn,
        time: 5000,
        a4: v29,
        a5: v28,
        a6: (unsigned int)gameLocal | 0x2511000000000LL);
      return;
    }
    if ( gameLocal->challengeState == CHALLENGE_STATE_NONE && v13 != nullptr )
    {
      v39 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 8u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v39 != nullptr )
      {
        v39[1].__vftable = nullptr;
        v40 = v39;
        v39->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::Killed'::`30'::idSWFScriptFunction_loadMostRecent::`vftable';
      }
      else
      {
        v40 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v48, nf: v40);
      idSWFScriptObject::Set(this: v13->globals, name: "loadMostRecent", value: &v48);
      idSWFScriptVar::Free(this: &v48);
      v41 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 8u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v41 != nullptr )
      {
        v41[1].__vftable = nullptr;
        v42 = v41;
        v41->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::Killed'::`29'::idSWFScriptFunction_setLoadOnly::`vftable';
      }
      else
      {
        v42 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v49, nf: v42);
      idSWFScriptObject::Set(this: v13->globals, name: "loadGameFromSave", value: &v49);
      idSWFScriptVar::Free(this: &v49);
      v43 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 0x10u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v43 != nullptr )
      {
        v43[2].__vftable = (idSWFScriptFunction_vtbl *)this;
        v43[3].__vftable = (idSWFScriptFunction_vtbl *)v13;
        v44 = v43;
        v43[1].__vftable = nullptr;
        v43->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::Killed'::`27'::idSWFScriptFunction_PlayerVehicleDeath::`vftable';
      }
      else
      {
        v44 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v51, nf: v44);
      idSWFScriptObject::Set(this: v13->globals, name: "restartLevel", value: &v51);
      idSWFScriptVar::Free(this: &v51);
      v45 = (idSWFScriptFunction *)idMem::AllocWithLocation(
                                     this: &mem,
                                     location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                     size: 8u,
                                     tag: TAG_SWF,
                                     zeroBuffer: false,
                                     align: ALIGN_16,
                                     heap: HEAP_DEFAULTHEAP);
      if ( v45 != nullptr )
      {
        v45[1].__vftable = nullptr;
        v46 = v45;
        v45->__vftable = (idSWFScriptFunction_vtbl *)&`idPlayer::Killed'::`28'::idSWFScriptFunction_ExitToMenu::`vftable';
      }
      else
      {
        v46 = nullptr;
      }
      idSWFScriptVar::idSWFScriptVar(this: &v53, nf: v46);
      idSWFScriptObject::Set(this: v13->globals, name: "exitGame", value: &v53);
      v38 = &v53;
_M523200:
      idSWFScriptVar::Free(this: v38);
      idSWF::Activate(this: v13, b: true);
    }
  }
}


// ========================================================================
// __unwind$522662
// EA  : 0x82E33C5C
// RVA : 0x00E33C5C
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522662()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 144));
}


// ========================================================================
// __unwind$522664
// EA  : 0x82E33C84
// RVA : 0x00E33C84
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522664()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 104));
}


// ========================================================================
// __unwind$522666
// EA  : 0x82E33CAC
// RVA : 0x00E33CAC
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522666()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 136));
}


// ========================================================================
// __unwind$522668
// EA  : 0x82E33CD4
// RVA : 0x00E33CD4
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522668()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 120));
}


// ========================================================================
// __unwind$522670
// EA  : 0x82E33CFC
// RVA : 0x00E33CFC
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522670()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 88));
}


// ========================================================================
// __unwind$522672
// EA  : 0x82E33D24
// RVA : 0x00E33D24
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522672()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 96));
}


// ========================================================================
// __unwind$522674
// EA  : 0x82E33D4C
// RVA : 0x00E33D4C
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522674()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 112));
}


// ========================================================================
// __unwind$522676
// EA  : 0x82E33D74
// RVA : 0x00E33D74
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_522676()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 432 + 128));
}


// ========================================================================
// `idPlayer::Killed'::`14'::idSWFScriptFunction_loadMostRecent::Call
// EA  : 0x82E33DA0
// RVA : 0x00E33DA0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idPlayer::Killed_::_14_::idSWFScriptFunction_loadMostRecent::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a4)
{
  if ( *(_DWORD *)(a4 + 4) != 1 )
    idLib::Warning(fmt: "Unable to load game because no game name was passed as parameter", thisObject, parms);
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "RestartMapFromMemoryCheckpoint\n");
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idPlayer::Killed'::`28'::idSWFScriptFunction_ExitToMenu::Call
// EA  : 0x82E33E10
// RVA : 0x00E33E10
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idPlayer::Killed_::_28_::idSWFScriptFunction_ExitToMenu::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  cmdSystem->AppendCommandText(this: cmdSystem, a2: "disconnect\n");
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idPlayer::Killed'::`29'::idSWFScriptFunction_setLoadOnly::Call
// EA  : 0x82E33E68
// RVA : 0x00E33E68
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idPlayer::Killed_::_29_::idSWFScriptFunction_setLoadOnly::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idGame *v4; // r3

  v4 = common->Game(this: common);
  if ( v4->IsGameActive(this: v4) && !common->IsDialogActive(this: common) )
  {
    idMainMenu::SetDeadLoadOnly(this: gameLocal->mainMenu);
    idMainMenu::Show(this: gameLocal->mainMenu, show: true);
  }
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Draw@idPlayer@@UAA_NPAV1@@Z
// EA  : 0x82E33F08
// RVA : 0x00E33F08
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::Draw(idPlayer *this, idPlayer *player)
{
  idPresentable *presentable; // r3
  int v4; // r3
  idPresentable *v6; // r3
  int v7; // r31
  idPresentable *v8; // r3
  int v9; // r4
  int v10; // r29
  unsigned int v11; // r28
  idPresentable *v12; // r3
  idPresentablePlayer *v13; // r27
  idPresentable *v14; // r3
  int v15; // r3
  idView *v16; // r31
  double v17; // fp1
  __int64 v18; // r9
  idRenderModelGui *guiModel; // r3
  __int64 v20; // r6
  int v21; // r7
  int v22; // r7
  unsigned __int64 v23; // r6
  double v24; // fp1
  idEntity *Control; // r3
  idEntity *v26; // r3
  idEntity *v27; // r31
  idPresentable *v28; // r3
  int value; // r9
  idCamera *v30; // r3
  idCamera *ControlCamera; // r3
  __int64 v32; // [sp+8h] [-C8h]
  float v33[2]; // [sp+50h] [-80h] BYREF
  idVec3 v34[2]; // [sp+58h] [-78h] BYREF
  idMat3 v35[2]; // [sp+70h] [-60h] BYREF

  if ( !common->IsServer(this: common) )
  {
    presentable = this->presentable;
    if ( presentable != nullptr )
      v4 = (int)presentable->GetPlayerInterface_2(this: presentable);
    else
      v4 = 0;
    if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v4 + 300))(a1: v4) == 0 )
      return 0;
    v6 = this->presentable;
    if ( v6 != nullptr )
      v7 = (int)v6->GetPlayerInterface_2(this: v6);
    else
      v7 = 0;
    v8 = this->presentable;
    if ( v8 != nullptr )
      v9 = (int)v8->GetPlayerInterface_2(this: v8);
    else
      v9 = 0;
    return (*(int (__fastcall **)(int, int))(*(_DWORD *)v7 + 56))(a1: v7, a2: v9);
  }
  v10 = renderSystem->GetWidth(this: renderSystem);
  v11 = renderSystem->GetHeight(this: renderSystem);
  v12 = this->presentable;
  if ( v12 != nullptr )
    v13 = v12->GetPlayerInterface_2(this: v12);
  else
    v13 = nullptr;
  v14 = this->presentable;
  if ( v14 != nullptr )
    v15 = (int)v14->GetPlayerInterface_2(this: v14);
  else
    v15 = 0;
  v16 = (idView *)(v15 + 16224);
  idRenderModelGui::SetViewport(this: *(idRenderModelGui **)(v15 + 16224), x: 0, y: 0, width: v10, height: v11);
  v17 = ((double (__fastcall *)(idRenderSystem *))renderSystem->GetPixelAspect)(a1: renderSystem);
  LODWORD(v18) = v10;
  guiModel = v16->guiModel;
  HIDWORD(v20) = v11;
  LODWORD(v33[1]) = (int)(float)((float)v17 * (float)v18);
  idRenderModelGui::SetVirtualSize(this: guiModel, height: v20, a3: v21, a4: SHIDWORD(v18), a5: v10, a6: v32);
  idRenderModelGui::Clear(
    this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
    a2: defaultExtraGLState,
    bits: v23,
    a4: v22);
  idPlayerHud::Update(this: &v13->playerHud, hudInfo: &v13->hudInfo);
  if ( vai_cam.valueInteger != 0
    && (unsigned __int8)idAISplinePathMgr::GetDebugAiView(
                          this: &gameLocal->aiSplinePathMgr,
                          origin: v34,
                          axis: v35,
                          fov_x: v33) != 0 )
  {
    idView::SetViewPos(this: v16, origin: v34, axis: v35);
    v24 = idPlayer::CalcFov(this, honorZoom: true);
    v13->lastFov = v24;
    idView::CalcFOV(this: v16, base_fov: v24);
    idView::Render(this: v16);
    return 1;
  }
  idPlayer::PlayerBehavior_Draw(this);
  Control = idPlayer::GetControl(this);
  if ( Control != nullptr && Control->Draw(this: Control, a2: this) )
  {
    v26 = idPlayer::GetControl(this);
    v27 = v26;
    if ( v26 != nullptr )
    {
      v28 = v26->presentable;
      if ( v28 == nullptr )
      {
        idEntity::InitPresentableInternal(this: v27);
        v28 = v27->presentable;
      }
      if ( v28->GetType(this: v28) <= PRESENTABLE_RENDERMODEL )
        v13->UpdateSerializedView(this: v13);
    }
    idPresentablePlayer::UpdateScreenParticles(this: v13);
    if ( (unsigned __int8)idProp_WeaponStatic::IsTypeOf(c: v27) == 0 )
      goto LABEL_34;
  }
  else
  {
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nearbyThreats);
  }
  idPresentablePlayer::Draw_Shared(this: v13);
LABEL_34:
  value = this->controlledCameraEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v30 = (idCamera *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v30 != nullptr && idCamera::CastTo(c: v30) != nullptr )
    {
      ControlCamera = idPlayer::GetControlCamera(this);
      ControlCamera->Draw(this: ControlCamera, a2: this);
    }
  }
  return 1;
}


// ========================================================================
// ?SetControlCamera@idPlayer@@QAAXPAVidEntity@@_N@Z
// EA  : 0x82E342B0
// RVA : 0x00E342B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetControlCamera(idPlayer *this, idPlayer *entity, bool allowHUD)
{
  idCamera *v5; // r29
  idGameLocal *v6; // r11
  idCamera *v7; // r3
  idCamera *v8; // r3

  if ( entity == this )
    v5 = nullptr;
  else
    v5 = idCamera::CastTo(c: (idCamera *)entity);
  v6 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->controlledCameraEntity.spawnId.value & 0x1FFF] == this->controlledCameraEntity.spawnId.value >> 13
    && (v7 = (idCamera *)gameLocal->entities.ptr[this->controlledCameraEntity.spawnId.value & 0x1FFF]) != nullptr )
  {
    v8 = idCamera::CastTo(c: v7);
    v6 = gameLocal;
  }
  else
  {
    v8 = nullptr;
  }
  if ( v5 != v8 )
  {
    if ( v5 != nullptr )
      this->controlledCameraEntity.spawnId.value = (v6->spawnIds.ptr[v5->entityNumber] << 13) | v5->entityNumber;
    else
      this->controlledCameraEntity.spawnId.value = 0x1FFF;
    this->controlledCameraEntityAllowHUD = allowHUD;
  }
}


// ========================================================================
// ?RemoveReviveItemAttachment@idPlayer@@QAAXXZ
// EA  : 0x82E34378
// RVA : 0x00E34378
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::RemoveReviveItemAttachment(idPlayer *this)
{
  idHandle<int,enum invalidAttachment_t,-1> *p_reviveItemAttachment; // r30
  idAttachmentCollection *v3; // r3
  idWeapon *v4; // r3
  idWeapon *v5; // r31
  idPresentableWeapon *PresentableWeapon; // r3

  p_reviveItemAttachment = &this->reviveItemAttachment;
  if ( this->reviveItemAttachment.value != -1 )
  {
    v3 = this->GetAttachments_2(this);
    idAttachmentCollection::RemoveAttachment(this: v3, handle: p_reviveItemAttachment);
    p_reviveItemAttachment->value = -1;
  }
  v4 = this->GetEquippedWeapon(this);
  v5 = v4;
  if ( v4 != nullptr && idWeapon::GetPresentableWeapon(this: v4) != nullptr )
  {
    PresentableWeapon = idWeapon::GetPresentableWeapon(this: v5);
    PresentableWeapon->Show(this: PresentableWeapon);
  }
}


// ========================================================================
// ?ShutDownBotComponent@idPlayer@@QAAXXZ
// EA  : 0x82E34420
// RVA : 0x00E34420
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ShutDownBotComponent(idPlayer *this)
{
  idBot *botController; // r3
  int entityNumber; // r10
  idEntityPtr<idAI2> v4; // [sp+50h] [-20h] BYREF

  botController = this->botController;
  if ( botController != nullptr )
  {
    ((void (__fastcall *)(idBot *, int))botController->dtr_idBot)(a1: botController, a2: 1);
    entityNumber = this->entityNumber;
    this->botController = nullptr;
    v4.spawnId.value = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
    idList<idEntityPtr<idPlayer>,5>::Remove(this: (idList<idEntityPtr<idAI2>,5> *)&gameLocal->botEntities, obj: &v4);
  }
}


// ========================================================================
// ??0idPlayer@@QAA@XZ
// EA  : 0x82E34528
// RVA : 0x00E34528
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::idPlayer(idPlayer *this)
{
  unsigned __int64 v1; // r29
  char v3; // r8
  bool v4; // r6
  char v5; // r3
  char v6; // r10

  idActor::idActor(this);
  this->__vftable = (idPlayer_vtbl *)&idPlayer::`vftable';
  idPlayer::idPlayerBehaviors::idPlayerBehaviors(this: &this->behaviors);
  LODWORD(v1) = 0;
  this->vehicleWeaponGroupIndex = 0;
  this->vehicleQuickUseIndex = 0;
  this->loadoutChanged = false;
  this->holsteredForRCcontroller = nullptr;
  this->snapBackFromRCcontroller = false;
  this->spawnTimeMS = 0;
  this->handsModel = nullptr;
  this->playerProps = nullptr;
  idDragEntity::idDragEntity(this: &this->dragEntity);
  this->ignoreFallDamage = false;
  this->bodyAnimInfo.turning = false;
  this->bodyAnimInfo.framesIdle = 0;
  this->bodyAnimInfo.movementQuery.index = v1;
  this->bodyAnimInfo.jumpQuery.index = v1;
  this->bodyAnimInfo.physicsJumped = false;
  this->bodyAnimInfo.hasJumped = false;
  this->bodyAnimInfo.framesInAir = 0;
  this->bodyAnimInfo.jumpPreLand = false;
  this->bodyAnimInfo.fwdMovementBlocked = false;
  this->bodyAnimInfo.lastVelocity = vec3_origin;
  this->bodyAnimInfo.leftHandIKTag.trans.x = 0.0;
  this->bodyAnimInfo.leftHandIKTag.trans.y = 0.0;
  this->bodyAnimInfo.leftHandIKTag.trans.z = 0.0;
  this->bodyAnimInfo.leftHandIKTag.rot.x = 0.0;
  this->bodyAnimInfo.leftHandIKTag.rot.y = 0.0;
  this->bodyAnimInfo.leftHandIKTag.rot.z = 0.0;
  this->bodyAnimInfo.leftHandIKTag.rot.w = 0.0;
  this->bodyAnimInfo.leftHandIKTag.parentJoint.value = -1;
  idTungstenHealth::idTungstenHealth(this: &this->playerHealth);
  HIDWORD(v1) = 0x1FFF;
  this->guiInteractionEntity.spawnId.value = 0x1FFF;
  this->lootQuery.index = v1;
  this->lootSoundPlayed = false;
  this->onlinePlayerUseableQuery.index = v1;
  this->shouldHideVehicles = false;
  this->droppableList.list = this->droppableList.staticList;
  this->droppableList.size = 2;
  this->droppableList.num = 0;
  this->droppableList.granularity = 1;
  this->droppableList.memTag = 5;
  this->droppableList.listStatic = 1;
  this->droppableList.staticList[0].spawnId.value = 0x1FFF;
  this->droppableList.staticList[1].spawnId.value = 0x1FFF;
  this->throwableAttachments.list = nullptr;
  this->throwableAttachments.granularity = 0;
  this->throwableAttachments.memTag = 5;
  this->throwableAttachments.listStatic = 0;
  this->throwableAttachments.size = 0;
  this->throwableAttachments.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->throwableAttachments);
  this->suffocationDamage = nullptr;
  this->maxTimeUnderwater = 10000;
  this->refillAirTime = 2000;
  this->diveTime = -1;
  this->sprintAirReductionScale = 1.5;
  this->airLeft = 1.0;
  this->deathTrigger.spawnId.value = 0x1FFF;
  idJobManager::idJobManager(this: &this->jobManager);
  idJobTimerManager::idJobTimerManager(this: &this->jobTimerManager);
  this->lastOfferChoice = OFFERCHOICE_UNKNOWN;
  idGameLayerManager::idGameLayerManager(this: &this->gameLayerManager);
  this->infoMessages.seenDiceHelp = false;
  this->infoMessages.savedInventoryScreen = 0;
  this->npcInteractionState.offeringEntity.allocedAndFlag = 20;
  this->npcInteractionState.offeringEntity.len = 0;
  this->npcInteractionState.offeringEntity.data = this->npcInteractionState.offeringEntity.baseBuffer;
  this->npcInteractionState.offeringEntity.baseBuffer[0] = 0;
  this->npcInteractionState.interaction.allocedAndFlag = 20;
  this->npcInteractionState.interaction.data = this->npcInteractionState.interaction.baseBuffer;
  this->npcInteractionState.interaction.len = 0;
  this->npcInteractionState.interaction.baseBuffer[0] = 0;
  this->npcInteractionState.offerType = OFFERTYPE_NONE;
  this->mutantTag = nullptr;
  this->newItemList.list = nullptr;
  this->newItemList.granularity = 0;
  this->newItemList.memTag = 5;
  this->newItemList.listStatic = 0;
  this->newItemList.size = 0;
  this->newItemList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->newItemList);
  this->lastIncapacitate = 0;
  idPlayerAuditor::idPlayerAuditor(this: &this->auditor);
  this->nearbyThreats.num = 0;
  this->nearbyThreats.granularity = 1;
  this->nearbyThreats.size = 4;
  this->nearbyThreats.list = this->nearbyThreats.staticList;
  this->nearbyThreats.memTag = 5;
  this->nearbyThreats.listStatic = 1;
  this->nearbyThreats.staticList[0].spawnId.value = 0x1FFF;
  this->nearbyThreats.staticList[1].spawnId.value = 0x1FFF;
  this->nearbyThreats.staticList[2].spawnId.value = 0x1FFF;
  this->nearbyThreats.staticList[3].spawnId.value = 0x1FFF;
  this->reviveItemAttachment.value = -1;
  this->controlledCameraEntity.spawnId.value = 0x1FFF;
  this->lastVehicle.spawnId.value = 0x1FFF;
  this->botController = nullptr;
  this->dofFocusTrace.index = v1;
  this->dofCurrentFocus = 0.0;
  this->dofGoalFocus = 0.0;
  this->onAiPushDir = vec3_origin;
  this->onAiChangePushDirMilliSeconds = 0;
  this->springCamera = nullptr;
  this->reviveTarget.spawnId.value = 0x1FFF;
  this->killer.spawnId.value = 0x1FFF;
  idAchievementManager::idAchievementManager(this: &this->achievementManager);
  this->aas = nullptr;
  this->previousCoverCheckPos = vec3_origin;
  this->playerCoverScores.list = nullptr;
  this->playerCoverScores.granularity = 0;
  this->playerCoverScores.memTag = 5;
  this->playerCoverScores.listStatic = 0;
  this->playerCoverScores.size = 0;
  this->playerCoverScores.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->playerCoverScores);
  this->incapDuck = nullptr;
  this->playerAimEventDecl = nullptr;
  this->playerInteractionEventDecl = nullptr;
  this->bodyEventDecl = nullptr;
  this->demonPlayer = nullptr;
  idAASPositionMgr::idAASPositionMgr(this: &this->aasPositionMgr);
  this->actorConstants.actorClass = ACTORCLASS_PLAYER;
  this->prtUnderwater = nullptr;
  this->prtWaterTransition = nullptr;
  this->prtWaterSplash = nullptr;
  this->lastFrameUnderwater = false;
  this->lastFrameInWater = false;
  this->underwaterEffectIsRunning = false;
  this->transitionEffectIsRunning = false;
  this->isControllingAi = false;
  v3 = *((_BYTE *)this + 12824) & 0x1F;
  *((_BYTE *)this + 12824) = v3;
  v4 = g_demoMode.valueInteger != 0;
  this->standDecay.time = 200;
  this->crouchDecay.time = 200;
  this->standDecay.linear = 1.0;
  this->standDecay.lambda = 0.25;
  this->crouchDecay.linear = 1.0;
  this->dropRandomLoot = false;
  this->crouchDecay.lambda = 0.25;
  this->hitFlashDuration = 200.0;
  this->levelTransitionGuiVolume = nullptr;
  this->applyDamageScale = 1.0;
  this->levelTransitionGuiVolumeActive = false;
  *((_BYTE *)this + 12824) = (16 * v4) & 0x10 | v3 & 1;
  this->inPersonalGarage = false;
  this->hitFlashTime = 0;
  this->applyDamageScaleEndTime = 0;
  this->bulletTimeEndTime = 0;
  this->invulnerabilityEndTime = 0;
  this->isInvulnerable = false;
  this->authorityEndTime = 0;
  this->authorityStartTime = 0;
  this->authorityIcon = nullptr;
  this->cover.aas = nullptr;
  this->cover.wallNormal.z = 0.0;
  this->cover.wallNormal.y = 0.0;
  this->cover.wallNormal.x = 0.0;
  this->cover.intersectionPoint.z = 0.0;
  this->cover.intersectionPoint.y = 0.0;
  this->cover.intersectionPoint.x = 0.0;
  this->cover.coverPoints[0].pos.x = 0.0;
  this->cover.coverPoints[0].pos.y = 0.0;
  this->cover.coverPoints[0].pos.z = 0.0;
  v5 = *((_BYTE *)this->cover.coverPoints + 16) & 0x3F;
  this->cover.coverPoints[0].coverIndex = 0;
  *((_BYTE *)this->cover.coverPoints + 16) = v5;
  this->cover.coverPoints[1].pos.x = 0.0;
  this->cover.coverPoints[1].pos.y = 0.0;
  this->cover.coverPoints[1].pos.z = 0.0;
  v6 = *((_BYTE *)&this->cover.coverPoints[1] + 16) & 0x3F;
  this->cover.coverPoints[1].coverIndex = 0;
  this->currentCoverCheckIndex = 0;
  *((_BYTE *)&this->cover.coverPoints[1] + 16) = v6;
  this->currentPlayerTension = PLAYER_TENSION_NONE;
  this->lastSetTensionTime = -1;
  this->guiObjectScreenCoords.x = 0.0;
  this->guiObjectScreenCoords.y = 0.0;
  this->vendorKeyIndex = 0;
  this->deathCamera = nullptr;
  this->onlineVehicleDeathCamera = nullptr;
  this->thrownCamera = nullptr;
  this->dynamicInteractionCamera = nullptr;
  this->spectatorCamera = nullptr;
  this->slowMotionCamera = nullptr;
  this->reviveCamera = nullptr;
  this->reviveTarget.spawnId.value = 0x1FFF;
  this->controlledCameraEntity.spawnId.value = 0x1FFF;
  this->controlledCameraEntityAllowHUD = false;
  this->thirdPersonHandsDef = nullptr;
  this->thirdPersonHands = nullptr;
  this->thirdPersonLegsDef = nullptr;
  this->thirdPersonLegs = nullptr;
  this->playerDriver[0] = nullptr;
  this->playerDriver[1] = nullptr;
  this->cashVehicleDecl = nullptr;
  this->cashDecl = nullptr;
  this->coopModelDef = nullptr;
  this->bonusStamp = -1;
  this->overrideActiveJob = -1;
  this->currentDPadSelection = -1;
  this->modelAxis = mat3_identity;
  this->playerModelOffset = vec3_origin;
  this->easyTable = nullptr;
  this->normalTable = nullptr;
  this->hardTable = nullptr;
  this->nightmareTable = nullptr;
  memset(Dst: this->stats, Val: 0, Size: sizeof(this->stats));
  this->stats[32].i = 1;
  this->stats[31].i = 1;
  this->debugHud_x = 0;
  this->debugHud_y = 0;
  this->lightDebugHelperTypes[0] = nullptr;
  this->lightDebugHelperTypes[1] = nullptr;
  this->lightDebugHelperTypes[2] = nullptr;
  this->lightDebugHelperTypes[3] = nullptr;
  this->lightDebugHelperCommited = LIGHTDEBUGHELPERMODELTYPE_INVALID;
  this->lightDebugHelperModel = nullptr;
  return this;
}


// ========================================================================
// __unwind$523887
// EA  : 0x82E34B40
// RVA : 0x00E34B40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523887()
{
  int v0; // r12

  idActor::~idActor(this: *(idActor **)(v0 - 208 + 228));
}


// ========================================================================
// __unwind$523888
// EA  : 0x82E34B68
// RVA : 0x00E34B68
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523888()
{
  int v0; // r12

  idPlayer::idPlayerBehaviors::~idPlayerBehaviors(this: (idPlayer::idPlayerBehaviors *)(*(_DWORD *)(v0 - 208 + 228)
                                                                                      + 10368));
}


// ========================================================================
// __unwind$523889
// EA  : 0x82E34B94
// RVA : 0x00E34B94
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idActor *__fastcall _unwind_523889(int a1, idStrId *a2)
{
  int v2; // r12

  return idDragEntity::~idDragEntity(this: (idActor *)(*(_DWORD *)(v2 - 208 + 228) + 12020), result: a2);
}


// ========================================================================
// __unwind$523890
// EA  : 0x82E34BC0
// RVA : 0x00E34BC0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523890()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: (idAIHealth *)(*(_DWORD *)(v0 - 208 + 228) + 12168));
}


// ========================================================================
// __unwind$523891
// EA  : 0x82E34BEC
// RVA : 0x00E34BEC
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523891()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 12296));
}


// ========================================================================
// __unwind$523892
// EA  : 0x82E34C18
// RVA : 0x00E34C18
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523892()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 12368));
}


// ========================================================================
// __unwind$523893
// EA  : 0x82E34C44
// RVA : 0x00E34C44
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523893()
{
  int v0; // r12

  idJobManager::~idJobManager(this: (idJobManager *)(*(_DWORD *)(v0 - 208 + 228) + 12412));
}


// ========================================================================
// __unwind$523894
// EA  : 0x82E34C70
// RVA : 0x00E34C70
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523894()
{
  int v0; // r12

  idJobTimerManager::~idJobTimerManager(this: (idJobTimerManager *)(*(_DWORD *)(v0 - 208 + 228) + 12552));
}


// ========================================================================
// __unwind$523895
// EA  : 0x82E34C9C
// RVA : 0x00E34C9C
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523895()
{
  int v0; // r12

  idGameLayerManager::~idGameLayerManager(this: (idGameLayerManager *)(*(_DWORD *)(v0 - 208 + 228) + 12576));
}


// ========================================================================
// __unwind$523896
// EA  : 0x82E34CC8
// RVA : 0x00E34CC8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523896()
{
  int v0; // r12

  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)(*(_DWORD *)(v0 - 208 + 228) + 12736));
}


// ========================================================================
// __unwind$523897
// EA  : 0x82E34CF4
// RVA : 0x00E34CF4
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523897()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 12808));
}


// ========================================================================
// __unwind$523898
// EA  : 0x82E34D20
// RVA : 0x00E34D20
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523898()
{
  int v0; // r12

  idPlayerAuditor::~idPlayerAuditor(this: (idPlayerAuditor *)(*(_DWORD *)(v0 - 208 + 228) + 12832));
}


// ========================================================================
// __unwind$523899
// EA  : 0x82E34D4C
// RVA : 0x00E34D4C
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523899()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 13024));
}


// ========================================================================
// __unwind$523900
// EA  : 0x82E34D78
// RVA : 0x00E34D78
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523900()
{
  int v0; // r12

  idAchievementManager::~idAchievementManager(this: (idAchievementManager *)(*(_DWORD *)(v0 - 208 + 228) + 15280));
}


// ========================================================================
// __unwind$523901
// EA  : 0x82E34DA4
// RVA : 0x00E34DA4
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_523901()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 208 + 228) + 23380));
}


// ========================================================================
// ??1idPlayer@@UAA@XZ
// EA  : 0x82E34E68
// RVA : 0x00E34E68
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::~idPlayer(idPlayer *this)
{
  int v2; // r5
  idDeathCamera *deathCamera; // r3
  idDeathCamera_vtbl *v4; // r11
  idReviveCamera *reviveCamera; // r3
  idReviveCamera_vtbl *v6; // r11
  idThrownCamera *thrownCamera; // r3
  idThrownCamera_vtbl *v8; // r11
  idSlowMotionCamera *slowMotionCamera; // r3
  idSlowMotionCamera_vtbl *v10; // r11
  idSpectatorCamera *spectatorCamera; // r3
  idSpectatorCamera_vtbl *v12; // r11
  idOnlineVehicleDeathCamera *onlineVehicleDeathCamera; // r3
  idOnlineVehicleDeathCamera_vtbl *v14; // r11
  idInteractionCamera *dynamicInteractionCamera; // r3
  idInteractionCamera_vtbl *v16; // r11
  int v17; // r4
  idGameLocal *v18; // r10
  idList<idEntityPtr<idEntity>,58> *p_playerEntities; // r3
  int num; // r8
  int v21; // r11
  idPresentable *presentable; // r3
  lobbyUserID_t *v23; // r3
  idPresentablePlayer *LobbyUserID; // r3
  char v25; // r11
  idLobbyBase *v26; // r3
  idPresentable *v27; // r11
  idLobbyBase *v28; // r28
  lobbyUserID_t *v29; // r4
  idLobbyBase_vtbl *v30; // r27
  idPresentablePlayer *v31; // r3
  idLobbyBase *v32; // r3
  idPresentable *v33; // r11
  idLobbyBase *v34; // r29
  lobbyUserID_t *v35; // r4
  idLobbyBase_vtbl *v36; // r28
  idPresentablePlayer *v37; // r3
  __int64 v38; // r6
  idPresentable *v39; // r3
  idStrId *v40; // r4
  idPresentablePlayer *entityNumber; // [sp+50h] [-40h] BYREF
  lobbyUserID_t *v42; // [sp+54h] [-3Ch]

  this->__vftable = (idPlayer_vtbl *)&idPlayer::`vftable';
  idAIEventManager::RemoveEntityEvents(this: &gameLocal->aiEventManager, ent: this);
  idEntity::SetPhysics(this, phys: nullptr, a3: v2);
  deathCamera = this->deathCamera;
  if ( deathCamera != nullptr )
  {
    v4 = deathCamera->__vftable;
    entityNumber = (idPresentablePlayer *)this->deathCamera;
    ((void (__fastcall *)(idDeathCamera *, int))v4->dtr_idClass)(a1: deathCamera, a2: 1);
  }
  reviveCamera = this->reviveCamera;
  if ( reviveCamera != nullptr )
  {
    v6 = reviveCamera->__vftable;
    entityNumber = (idPresentablePlayer *)this->reviveCamera;
    ((void (__fastcall *)(idReviveCamera *, int))v6->dtr_idClass)(a1: reviveCamera, a2: 1);
  }
  thrownCamera = this->thrownCamera;
  if ( thrownCamera != nullptr )
  {
    v8 = thrownCamera->__vftable;
    entityNumber = (idPresentablePlayer *)this->thrownCamera;
    ((void (__fastcall *)(idThrownCamera *, int))v8->dtr_idClass)(a1: thrownCamera, a2: 1);
  }
  slowMotionCamera = this->slowMotionCamera;
  if ( slowMotionCamera != nullptr )
  {
    v10 = slowMotionCamera->__vftable;
    entityNumber = (idPresentablePlayer *)this->slowMotionCamera;
    ((void (__fastcall *)(idSlowMotionCamera *, int))v10->dtr_idClass)(a1: slowMotionCamera, a2: 1);
  }
  spectatorCamera = this->spectatorCamera;
  if ( spectatorCamera != nullptr )
  {
    v12 = spectatorCamera->__vftable;
    entityNumber = (idPresentablePlayer *)this->spectatorCamera;
    ((void (__fastcall *)(idSpectatorCamera *, int))v12->dtr_idClass)(a1: spectatorCamera, a2: 1);
  }
  onlineVehicleDeathCamera = this->onlineVehicleDeathCamera;
  if ( onlineVehicleDeathCamera != nullptr )
  {
    v14 = onlineVehicleDeathCamera->__vftable;
    entityNumber = (idPresentablePlayer *)this->onlineVehicleDeathCamera;
    ((void (__fastcall *)(idOnlineVehicleDeathCamera *, int))v14->dtr_idClass)(a1: onlineVehicleDeathCamera, a2: 1);
  }
  dynamicInteractionCamera = this->dynamicInteractionCamera;
  if ( dynamicInteractionCamera != nullptr )
  {
    v16 = dynamicInteractionCamera->__vftable;
    entityNumber = (idPresentablePlayer *)this->dynamicInteractionCamera;
    ((void (__fastcall *)(idInteractionCamera *, int))v16->dtr_idClass)(a1: dynamicInteractionCamera, a2: 1);
  }
  v17 = 0;
  v18 = gameLocal;
  p_playerEntities = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->playerEntities;
  entityNumber = (idPresentablePlayer *)this->entityNumber;
  num = gameLocal->playerEntities.num;
  if ( num > 0 )
  {
    v21 = 0;
    while ( p_playerEntities->list[v21].spawnId.value != ((*((_DWORD *)&gameLocal->__vftable
                                                           + (_DWORD)&entityNumber->moveBuffer[34].curCmd.angles[2]
                                                           + 1) << 13)
                                                        | (unsigned int)entityNumber) )
    {
      ++v17;
      ++v21;
      if ( v17 >= num )
        goto LABEL_22;
    }
    if ( v17 >= 0 )
    {
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_playerEntities, index: v17);
      v18 = gameLocal;
    }
  }
LABEL_22:
  idGameLocal::BotSystems_UnRegisterEntity(this: v18, entity: this);
  presentable = this->presentable;
  if ( presentable != nullptr )
  {
    v23 = (lobbyUserID_t *)presentable->GetPlayerInterface_2(this: presentable);
    LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&entityNumber, result: v23);
    if ( LobbyUserID->__vftable == nullptr || (v25 = 1, *((unsigned __int8 *)&LobbyUserID->__vftable + 4) == 255) )
      v25 = 0;
    if ( v25 != 0 )
    {
      v26 = session->GetActingGameStateLobbyBase(this: session);
      v27 = this->presentable;
      v28 = v26;
      v29 = v27 != nullptr ? (lobbyUserID_t *)v27->GetPlayerInterface_2(this: this->presentable) : nullptr;
      v30 = v28->__vftable;
      v31 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&entityNumber, result: v29);
      if ( v30->GetLobbyUserIsBot(this: (idLobbyBase *)v31->__vftable, a2: *((lobbyUserID_t **)&v31->__vftable + 1)) )
      {
        v32 = session->GetActingGameStateLobbyBase(this: session);
        v33 = this->presentable;
        v34 = v32;
        if ( v33 != nullptr )
          v35 = (lobbyUserID_t *)v33->GetPlayerInterface_2(this: this->presentable);
        else
          v35 = nullptr;
        v36 = v34->__vftable;
        v37 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&entityNumber, result: v35);
        v36->RemoveBotFromLobbyUserList(
          this: (idLobbyBase *)v37->__vftable,
          a2: *((lobbyUserID_t **)&v37->__vftable + 1));
        v39 = this->presentable;
        HIBYTE(v42) = -1;
        entityNumber = nullptr;
        if ( v39 != nullptr )
          v39->GetPlayerInterface_2(this: v39);
        idPresentablePlayer::SetLobbyUserID(this: entityNumber, value: v42, a3: v38);
      }
    }
  }
  idPlayer::ShutDownBotComponent(this);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->playerCoverScores);
  idAchievementManager::~idAchievementManager(this: &this->achievementManager);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->nearbyThreats);
  idPlayerAuditor::~idPlayerAuditor(this: &this->auditor);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->newItemList);
  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)&this->npcInteractionState);
  idGameLayerManager::~idGameLayerManager(this: &this->gameLayerManager);
  idJobTimerManager::~idJobTimerManager(this: &this->jobTimerManager);
  idJobManager::~idJobManager(this: &this->jobManager);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->throwableAttachments);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->droppableList);
  entityNumber = (idPresentablePlayer *)&this->playerHealth;
  this->playerHealth.__vftable = (idTungstenHealth_vtbl *)&idBaseHealth::`vftable';
  idDragEntity::~idDragEntity(this: (idActor *)&this->dragEntity, result: v40);
  idPlayer::idPlayerBehaviors::~idPlayerBehaviors(this: &this->behaviors);
  idActor::~idActor(this);
}


// ========================================================================
// __unwind$524912
// EA  : 0x82E35230
// RVA : 0x00E35230
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524912()
{
  int v0; // r12

  idActor::~idActor(this: *(idActor **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$524913
// EA  : 0x82E35258
// RVA : 0x00E35258
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524913()
{
  int v0; // r12

  idPlayer::idPlayerBehaviors::~idPlayerBehaviors(this: (idPlayer::idPlayerBehaviors *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                      + 10368));
}


// ========================================================================
// __unwind$524914
// EA  : 0x82E35284
// RVA : 0x00E35284
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idActor *__fastcall _unwind_524914(int a1, idStrId *a2)
{
  int v2; // r12

  return idDragEntity::~idDragEntity(this: (idActor *)(*(_DWORD *)(v2 - 144 + 164) + 12020), result: a2);
}


// ========================================================================
// __unwind$524915
// EA  : 0x82E352B0
// RVA : 0x00E352B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524915()
{
  int v0; // r12

  idSimpleHealth::~idSimpleHealth(this: (idAIHealth *)(*(_DWORD *)(v0 - 144 + 164) + 12168));
}


// ========================================================================
// __unwind$524916
// EA  : 0x82E352DC
// RVA : 0x00E352DC
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524916()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 12296));
}


// ========================================================================
// __unwind$524917
// EA  : 0x82E35308
// RVA : 0x00E35308
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524917()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 12368));
}


// ========================================================================
// __unwind$524918
// EA  : 0x82E35334
// RVA : 0x00E35334
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524918()
{
  int v0; // r12

  idJobManager::~idJobManager(this: (idJobManager *)(*(_DWORD *)(v0 - 144 + 164) + 12412));
}


// ========================================================================
// __unwind$524919
// EA  : 0x82E35360
// RVA : 0x00E35360
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524919()
{
  int v0; // r12

  idJobTimerManager::~idJobTimerManager(this: (idJobTimerManager *)(*(_DWORD *)(v0 - 144 + 164) + 12552));
}


// ========================================================================
// __unwind$524920
// EA  : 0x82E3538C
// RVA : 0x00E3538C
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524920()
{
  int v0; // r12

  idGameLayerManager::~idGameLayerManager(this: (idGameLayerManager *)(*(_DWORD *)(v0 - 144 + 164) + 12576));
}


// ========================================================================
// __unwind$524921
// EA  : 0x82E353B8
// RVA : 0x00E353B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524921()
{
  int v0; // r12

  idFuncChain::binddef_t::~binddef_t(this: (idSelectedTypeInfo *)(*(_DWORD *)(v0 - 144 + 164) + 12736));
}


// ========================================================================
// __unwind$524922
// EA  : 0x82E353E4
// RVA : 0x00E353E4
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524922()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 12808));
}


// ========================================================================
// __unwind$524923
// EA  : 0x82E35410
// RVA : 0x00E35410
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524923()
{
  int v0; // r12

  idPlayerAuditor::~idPlayerAuditor(this: (idPlayerAuditor *)(*(_DWORD *)(v0 - 144 + 164) + 12832));
}


// ========================================================================
// __unwind$524924
// EA  : 0x82E3543C
// RVA : 0x00E3543C
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524924()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 13024));
}


// ========================================================================
// __unwind$524925
// EA  : 0x82E35468
// RVA : 0x00E35468
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524925()
{
  int v0; // r12

  idAchievementManager::~idAchievementManager(this: (idAchievementManager *)(*(_DWORD *)(v0 - 144 + 164) + 15280));
}


// ========================================================================
// __unwind$524926
// EA  : 0x82E35494
// RVA : 0x00E35494
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_524926()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 23380));
}


// ========================================================================
// ?PickupItem@idPlayer@@QAA_NPAVidProp_Moveable@@@Z
// EA  : 0x82E354C8
// RVA : 0x00E354C8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

int __fastcall idPlayer::PickupItem(idPlayer *this, idProp_Moveable *prop)
{
  bfx::Planner3D *v4; // r3
  const idSoundShader *sound_pickup; // r28
  idInventoryCollection *v6; // r3
  idInventoryItem *InventoryItem; // r3
  idPresentable *presentable; // r26
  idPresentable *v10; // r27
  idInventoryCollection *v11; // r3
  int backupInventoryCount; // r26
  const idDeclInventory *backupInventoryDecl; // r25
  idPresentable *v14; // r27
  idInventoryCollection *v15; // r3
  int FocusTracker; // r3
  idList<idVehicleState *,5> v17; // [sp+50h] [-80h] BYREF
  _DWORD v18[28]; // [sp+60h] [-70h] BYREF

  if ( !prop->IsEverUsable(this: prop, a2: this) || prop->GetInventory_2(this: prop) == nullptr )
    return 0;
  v4 = (bfx::Planner3D *)prop->GetInventory_2(this: prop);
  sound_pickup = nullptr;
  if ( idScriptObject::GetTypeDef(this: v4) != nullptr )
  {
    v6 = prop->GetInventory_2(this: prop);
    InventoryItem = idInventoryCollection::GetInventoryItem(this: v6, index: 0);
    v17.num = 0;
    v17.granularity = 1;
    v17.size = 3;
    v17.list = (idVehicleState **)v18;
    v17.memTag = 5;
    v17.listStatic = 1;
    v18[0] = 0;
    v18[1] = 0;
    HIBYTE(v18[2]) = 1;
    v18[3] = 0;
    v18[4] = 0;
    HIBYTE(v18[5]) = 1;
    v18[6] = 0;
    v18[7] = 0;
    HIBYTE(v18[8]) = 1;
    InventoryItem->GetPickupHudInfo(this: InventoryItem, a2: this, a3: (idPickupHudInfo *)&v17);
    if ( *((_BYTE *)v17.list + 8) == 0 )
    {
      idList<idThread *,58>::Clear(this: &v17);
      return 0;
    }
    idList<idThread *,58>::Clear(this: &v17);
  }
  if ( this->presentable == nullptr )
    idEntity::InitPresentableInternal(this);
  presentable = this->presentable;
  v10 = prop->presentable;
  if ( v10 == nullptr )
  {
    idEntity::InitPresentableInternal(this: prop);
    v10 = prop->presentable;
  }
  v11 = prop->GetInventory_2(this: prop);
  if ( idInventoryCollection::TransferInventory(this: v11, owner: v10, toOwner: presentable, canIntro: true) == nullptr
    && prop->backupInventoryDecl != nullptr
    && this->GetInventory_2(this) != nullptr )
  {
    backupInventoryCount = prop->backupInventoryCount;
    backupInventoryDecl = prop->backupInventoryDecl;
    if ( this->presentable == nullptr )
      idEntity::InitPresentableInternal(this);
    v14 = this->presentable;
    v15 = this->GetInventory_2(this);
    idInventoryCollection::GiveItem(
      this: v15,
      owner: v14,
      decl: backupInventoryDecl,
      count: backupInventoryCount,
      forceCount: false,
      canIntro: true);
  }
  if ( prop->sound_pickup != nullptr )
    sound_pickup = prop->sound_pickup;
  FocusTracker = idPlayer::GetFocusTracker(this);
  prop->Use(this: prop, a2: this, a3: *(const usableState_t *)(FocusTracker + 524));
  idProp_Moveable::NaniteInspection(this: prop);
  idRageMetrics::ItemsTaken(this: clientGame->rageMetrics, player: (idVehicle *)this, items: 1);
  if ( sound_pickup != nullptr )
    idClientGame::PlaySoundForAllPeers(
      this: clientGame,
      entity: this,
      channel: SND_CHANNEL_ITEM,
      shader: sound_pickup,
      soundShaderFlags: 0);
  else
    idPlayer::PlayPickupSound(this);
  return 1;
}


// ========================================================================
// __unwind$525274
// EA  : 0x82E35764
// RVA : 0x00E35764
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_525274()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 80));
}


// ========================================================================
// ?AddDroppableInfo@idPlayer@@QAAXPAVidEntity@@@Z
// EA  : 0x82E35790
// RVA : 0x00E35790
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::AddDroppableInfo(idPlayer *this, idEntity *ent)
{
  idEntityPtr<idEntity> v2; // [sp+50h] [-10h] BYREF

  if ( this->droppableList.num != 2 )
  {
    if ( ent != nullptr )
      v2.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
    else
      v2.spawnId.value = 0x1FFF;
    idList<idEntityPtr<idEntity>,58>::Append(this: (idList<idEntityPtr<idEntity>,58> *)&this->droppableList, obj: &v2);
  }
}


// ========================================================================
// `idPlayer::Killed'::`27'::idSWFScriptFunction_PlayerVehicleDeath::Call
// EA  : 0x82E35800
// RVA : 0x00E35800
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idPlayer::Killed_::_27_::idSWFScriptFunction_PlayerVehicleDeath::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  ((void (__fastcall *)(idGameLocal *, int, const idSWFParmList *))gameLocal->LoadMostRecentGame)(
    a1: gameLocal,
    a2: thisObject->variables.size,
    a3: parms);
  result->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: result);
  result->type = SWF_VAR_BOOL;
  result->value.b = true;
  return result;
}


// ========================================================================
// ?Event_DoHudInitialFlash@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E35870
// RVA : 0x00E35870
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_DoHudInitialFlash(idPlayer *this, eventVoid *result)
{
  int v3; // r3
  idPresentablePlayer *v4; // r3
  idSWF *PlayerGui; // r29
  idSWFScriptVar v7[6]; // [sp+50h] [-30h] BYREF

  v3 = *(_DWORD *)&result[488];
  if ( v3 != 0 )
    v4 = (idPresentablePlayer *)(*(int (__fastcall **)(int))(*(_DWORD *)v3 + 104))(a1: v3);
  else
    v4 = nullptr;
  PlayerGui = idPresentablePlayer::GetPlayerGui(this: v4, g: GUI_INITIAL_ACTIVATE);
  v7[0].type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: v7);
  v7[0].type = SWF_VAR_INTEGER;
  v7[0].value.i = 0;
  idSWFScriptObject::Set(this: PlayerGui->globals, name: "effectType", value: v7);
  idSWFScriptVar::Free(this: v7);
  idSWF::Activate(this: PlayerGui, b: true);
  return this;
}


// ========================================================================
// __unwind$525556
// EA  : 0x82E35908
// RVA : 0x00E35908
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_525556()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 128 + 80));
}


// ========================================================================
// ?Incapacitate@idPlayer@@QAAXXZ
// EA  : 0x82E35930
// RVA : 0x00E35930
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::Incapacitate(idPlayer *this)
{
  idPresentable *presentable; // r3
  int v3; // r3
  const idDeclPlayerProps *playerProps; // r11
  idBot *botController; // r11
  idPresentable *v6; // r3
  int v7; // r3
  idPresentable *v8; // r3
  int v9; // r3
  idPresentable *v10; // r3
  int v11; // r3
  idReviveCamera *reviveCamera; // r30
  idPhysics *Physics; // r29
  idPhysics *v14; // r3
  idPresentable *v15; // r11
  idPhysics *v16; // r28
  idReviveCamera_vtbl *v17; // r27
  const idMat3 *v18; // r29
  const idVec3 *v19; // r3
  idBot *v20; // r11
  idDeclPlayerProps::playerSounds_t sounds; // [sp+60h] [-100h] BYREF

  this->invulnerabilityEndTime = 0;
  this->isInvulnerable = false;
  idPlayer::ResetBulletTime(this);
  this->authorityEndTime = 0;
  this->authorityStartTime = 0;
  idPlayer::RemoveDroppableInfo(this, ent: this);
  this->applyDamageScaleEndTime = 0;
  this->applyDamageScale = 1.0;
  this->lastIncapacitate = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v3 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v3 = 0;
  *(_BYTE *)(v3 + 47032) |= 4u;
  *(_BYTE *)&this->flags |= 4u;
  idRageMetrics::PlayerIncapacitated(this: clientGame->rageMetrics, player: (idVehicle *)this);
  playerProps = this->playerProps;
  if ( playerProps != nullptr )
    sounds = playerProps->sounds;
  else
    idDeclPlayerProps::playerSounds_t::playerSounds_t(this: &sounds);
  idEntity::StartSoundShader(
    this,
    channel: SND_CHANNEL_VOICE,
    shader: sounds.sndDeath,
    soundShaderFlags: (soundShaderFlags_t)0,
    peerMask: 0xFFu);
  idEntity::StopSound(this, channel: SND_CHANNEL_BODY2, peerMask: 0xFFu);
  idEntity::StopSound(this, channel: SND_CHANNEL_BREATHE, peerMask: 0xFFu);
  botController = this->botController;
  if ( botController == nullptr || botController->isControllingAFKPlayer )
  {
    v6 = this->presentable;
    if ( v6 != nullptr )
      v7 = (int)v6->GetPlayerInterface_2(this: v6);
    else
      v7 = 0;
    idPlayerHud::SetHudState(this: (idPlayerHud *)(v7 + 35096), state: HUDSTATE_DAMAGE);
    v8 = this->presentable;
    if ( v8 != nullptr )
      v9 = (int)v8->GetPlayerInterface_2(this: v8);
    else
      v9 = 0;
    idHands::Hide(this: (idHands *)(v9 + 37616), hideReason: HAND_HIDE_GENERIC);
    v10 = this->presentable;
    if ( v10 != nullptr )
      v11 = (int)v10->GetPlayerInterface_2(this: v10);
    else
      v11 = 0;
    idHands::Hide(this: (idHands *)(v11 + 37616), hideReason: HAND_HIDE_SERVER_AUTHORITATIVE);
  }
  reviveCamera = this->reviveCamera;
  Physics = idEntity::GetPhysics(this);
  v14 = idEntity::GetPhysics(this);
  v15 = this->presentable;
  v16 = v14;
  if ( v15 != nullptr )
    v15->GetPlayerInterface_2(this: this->presentable);
  v17 = reviveCamera->__vftable;
  v18 = Physics->GetAxis(this: Physics, a2: 0);
  v19 = v16->GetOrigin(this: v16, a2: 0);
  ((void (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v17->Init)(
    a1: LODWORD(v19->x),
    a2: LODWORD(v19->y),
    a3: __ROL4__(LODWORD(v19->z), 32),
    a4: LODWORD(v18->mat[0].z),
    a5: LODWORD(v18->mat[1].y),
    a6: LODWORD(v18->mat[2].x),
    a7: LODWORD(v18->mat[2].y),
    a8: __ROL4__(LODWORD(v18->mat[2].z), 32));
  idCamera::Activate(this: reviveCamera, activator_: this);
  v20 = this->botController;
  if ( v20 == nullptr || v20->isControllingAFKPlayer )
    idPlayer::DeactivateGuis(this);
  if ( common->IsMultiplayer(this: common) && this->GetAttachments_2(this) != nullptr )
  {
    idPlayer::RemoveReviveItemAttachment(this);
    idPlayer::RemoveThrowItemAttachments(this, spawnedProjectile: nullptr);
  }
}


// ========================================================================
// ?AnimEvent_AttachEquippedWeapon@idPlayer@@AAA?AVeventVoid@@PBVidMD6Anim@@@Z
// EA  : 0x82E35C40
// RVA : 0x00E35C40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::AnimEvent_AttachEquippedWeapon(
        idPlayer *this,
        idPlayer *result,
        const idMD6Anim *animHandle)
{
  idPlayer::RemoveReviveItemAttachment(this: result);
  return this;
}


// ========================================================================
// ?UpdateWater@idPlayer@@QAAXXZ
// EA  : 0x82E35CE0
// RVA : 0x00E35CE0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateWater(idPlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int GameMs; // r27
  int PreviousGameMs; // r3
  idPresentable *presentable; // r11
  int v7; // r27
  int v8; // r3
  __int64 v9; // r8
  double sprintAirReductionScale; // fp12
  double v11; // fp2
  const idDeclDamage *suffocationDamage; // r6
  __int64 v13; // r11
  double airLeft; // fp13
  idPLogScope v17[8]; // [sp+60h] [-40h] BYREF

  RD_EventBegin(name: "idPlayer::UpdateWater");
  LODWORD(v2) = "idPlayer::UpdateWater";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: v17, pl: &pLog, gMask: v2, label: v3);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  PreviousGameMs = idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  presentable = this->presentable;
  v7 = GameMs - PreviousGameMs;
  if ( presentable != nullptr )
    v8 = (int)presentable->GetPlayerInterface_2(this: this->presentable);
  else
    v8 = 0;
  if ( idPhysics_Player::GetIsUnderWater(this: (idPhysics_Player *)(v8 + 36264)) )
  {
    if ( this->diveTime == -1 )
    {
      this->diveTime = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    }
    else
    {
      if ( (unsigned __int8)idPlayer::GetIsSprinting(this) != 0 )
        sprintAirReductionScale = this->sprintAirReductionScale;
      else
        sprintAirReductionScale = 1.0;
      LODWORD(v9) = this->maxTimeUnderwater;
      v11 = (float)-(float)((float)((float)__SPAIR64__(0x82000000, v7)
                                  * (float)((float)((float)1.0 / (float)v9) * (float)sprintAirReductionScale))
                          - this->airLeft);
      this->airLeft = -(float)((float)((float)__SPAIR64__(0x82000000, v7)
                                     * (float)((float)((float)1.0 / (float)v9) * (float)sprintAirReductionScale))
                             - this->airLeft);
      if ( v11 < 0.0 )
      {
        suffocationDamage = this->suffocationDamage;
        this->airLeft = 0.0;
        if ( suffocationDamage != nullptr )
          ((void (__fastcall *)(idPlayer *, _DWORD, _DWORD, double))this->Damage)(
            a1: this,
            a2: 0,
            a3: 0,
            a4: (float)((float)__SPAIR64__(0x82000000, v7) * (float)0.0049999999));
      }
    }
  }
  else
  {
    LODWORD(v13) = v7;
    HIDWORD(v13) = this->refillAirTime;
    airLeft = this->airLeft;
    this->diveTime = -1;
    _FP4 = (float)((float)1.0
                 - (float)((float)((float)v13
                                 * (float)((float)1.0 / (float)(__int64)(HIDWORD(v13) | 0xFFFFFFFF00000000uLL)))
                         + (float)airLeft));
    __asm { fsel      f3, f4, f5, f0 }
    this->airLeft = _FP3;
  }
  idPLogScope::~idPLogScope(this: v17);
  RD_EventEnd();
}


// ========================================================================
// __unwind$525976
// EA  : 0x82E35EDC
// RVA : 0x00E35EDC
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_525976()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 104));
}


// ========================================================================
// __unwind$525977
// EA  : 0x82E35F04
// RVA : 0x00E35F04
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_525977()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 96));
}


// ========================================================================
// ?SetApplyAuthorityForce@idPlayer@@UAAXMPBVidDeclInventory@@@Z
// EA  : 0x82E35F38
// RVA : 0x00E35F38
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetApplyAuthorityForce(
        idPlayer *this,
        double authorityForceTime,
        const idDeclInventory *itemDecl,
        int a4)
{
  int (__fastcall *GetGameMs)(struct idGameLocal *, const gameTimeType_t); // r7
  idPresentable *presentable; // r3
  idPresentablePlayer *v9; // r3
  idSWF *PlayerGui; // r3
  idSWF *v11; // r30
  idSWFScriptVar v12; // [sp+50h] [-40h] BYREF
  int v14; // [sp+5Ch] [-34h]

  this->authorityStartTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL);
  GetGameMs = gameLocal->GetGameMs;
  v14 = (int)(float)((float)1000.0 * (float)authorityForceTime);
  this->authorityEndTime = GetGameMs(this: gameLocal, a2: GAMETIME_NORMAL) + v14;
  if ( a4 != 0 )
  {
    this->authorityIcon = *(const idMaterial **)(a4 + 212);
    if ( *(_BYTE *)(a4 + 254) != 0 )
      idPlayer::AddDroppableInfo(this, ent: this);
  }
  else
  {
    this->authorityIcon = nullptr;
  }
  presentable = this->presentable;
  if ( presentable != nullptr )
    v9 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v9 = nullptr;
  PlayerGui = idPresentablePlayer::GetPlayerGui(this: v9, g: GUI_INITIAL_ACTIVATE);
  v11 = PlayerGui;
  if ( PlayerGui != nullptr )
  {
    if ( PlayerGui->isActive )
      idSWF::Activate(this: PlayerGui, b: false);
    v12.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v12);
    v12.value.i = 4;
    v12.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: v11->globals, name: "effectType", value: &v12);
    idSWFScriptVar::Free(this: &v12);
    idSWF::Activate(this: v11, b: true);
  }
}


// ========================================================================
// __unwind$526091
// EA  : 0x82E36080
// RVA : 0x00E36080
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_526091()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 80));
}


// ========================================================================
// ?UpdateDroppableList@idPlayer@@QAAXXZ
// EA  : 0x82E360B0
// RVA : 0x00E360B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateDroppableList(idPlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int v4; // r28
  idStaticList<idEntityPtr<idEntity>,2> *p_droppableList; // r29
  int v6; // r25
  int value; // r9
  idEntity *v8; // r3
  idTurret *v9; // r3
  idAI2 *v10; // r30
  int num; // r11
  int v12; // r11
  int v13; // r10
  int v14; // r9
  _DWORD *v15; // r11
  idTurret *v16; // r3
  idAI2 *v17; // r3
  double valueFloat; // fp30
  idPhysics *Physics; // r21
  idPhysics *v20; // r20
  float *v21; // r21
  float *v22; // r3
  double v23; // fp9
  double v24; // fp5
  idPLog *pLog; // r29
  idPLog::logEntry_t *v26; // r30
  int v27; // r3
  __int64 totalTicks; // r11
  __int64 v29; // r9
  idPLogScope v30; // [sp+58h] [-88h] BYREF

  RD_EventBegin(name: "idPlayer::UpdateDroppableList");
  LODWORD(v2) = "idPlayer::UpdateDroppableList";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v30, pl: &::pLog, gMask: v2, label: v3);
  v4 = 0;
  if ( this->droppableList.num > 0 )
  {
    p_droppableList = &this->droppableList;
    v6 = 0;
    do
    {
      value = p_droppableList->list[v6].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
        && (v9 = (idTurret *)idEntity::CastTo(c: v8), v10 = (idAI2 *)v9, v9 != nullptr) )
      {
        v16 = idTurret::CastTo(c: v9);
        if ( v16 != nullptr && v16->IsDead(this: v16) )
          idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
            this: (idList<idEntityPtr<idEntity>,58> *)&this->droppableList,
            index: v4);
        v17 = idAI2::CastTo(c: v10);
        if ( v17 != nullptr && v17->IsDead(this: v17) )
          idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(
            this: (idList<idEntityPtr<idEntity>,58> *)&this->droppableList,
            index: v4);
        valueFloat = g_droppableMaxRange.valueFloat;
        Physics = idEntity::GetPhysics(this);
        v20 = idEntity::GetPhysics(this: v10);
        v21 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v22 = (float *)v20->GetOrigin(this: v20, a2: 0);
        v23 = (float)(v22[1] - v21[1]);
        v24 = (float)(v22[2] - v21[2]);
        if ( (float)((float)((float)v24 * (float)v24)
                   + (float)((float)((float)(*v22 - *v21) * (float)(*v22 - *v21)) + (float)((float)v23 * (float)v23))) > (double)(float)((float)valueFloat * (float)valueFloat) )
          ((void (__fastcall *)(idAI2 *, _DWORD, idPlayer *, const idDeclDamage *, double))v10->Damage)(
            a1: v10,
            a2: 0,
            a3: this,
            a4: gameLocal->damageDecl,
            a5: 0.1);
      }
      else if ( v4 >= 0 )
      {
        num = this->droppableList.num;
        if ( v4 < num )
        {
          v12 = num - 1;
          v13 = v4;
          this->droppableList.num = v12;
          if ( v4 < v12 )
          {
            v14 = v6 * 4;
            do
            {
              ++v13;
              v15 = (int *)((char *)&p_droppableList->list->spawnId.value + v14);
              v14 += 4;
              *v15 = v15[1];
            }
            while ( v13 < this->droppableList.num );
          }
        }
      }
      ++v4;
      ++v6;
    }
    while ( v4 < this->droppableList.num );
  }
  if ( v30.logIndex >= 0 )
  {
    pLog = v30.pLog;
    v26 = &v30.pLog->logEntries.list[v30.logIndex];
    v27 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v26->totalTicks;
    HIDWORD(totalTicks) = v26->parent;
    LODWORD(v29) = v27 - totalTicks;
    v26->totalTicks = v29;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$526156
// EA  : 0x82E36368
// RVA : 0x00E36368
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_526156()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$526157
// EA  : 0x82E36390
// RVA : 0x00E36390
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_526157()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 88));
}


// ========================================================================
// ?Damage@idPlayer@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
// EA  : 0x82E363B8
// RVA : 0x00E363B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

float __fastcall idPlayer::Damage(
        idPlayer *this,
        idWorldspawn *inflictor,
        idPlayer *attacker,
        const idDeclDamage *damageDef,
        double damageScale,
        const idVec3 *dir,
        const idDeclDamage *trace,
        int a8)
{
  int v14; // r28
  char *v15; // r31
  char *data; // r29
  const char *str; // r27
  int v18; // r3
  idPresentable *presentable; // r3
  int v20; // r3
  idThrownCamera *thrownCamera; // r31
  idPresentable *v22; // r3
  int v23; // r3
  double v24; // fp1
  idGameChallenge *ChallengeEntity; // r3
  idIndex<short,enum invalidJointIndex_t> *v26; // r7
  idPlayer *v27; // r3
  idEntity *v28; // r31
  gameTeam_t Team; // r29
  gameTeam_t v30; // r31
  idGameChallenge *v31; // r3
  int v32; // r10
  const idIndex<short,enum invalidJointIndex_t> *v33; // r14
  idPresentable *v34; // r3
  int v35; // r3
  double v36; // fp1
  int knockBack; // r31
  int v38; // r29
  double v39; // fp13
  double v40; // fp12
  __int64 v41; // r10
  __int64 v42; // r8
  int PhysicsObj; // r3
  int v44; // r29
  int v45; // r27
  float *v46; // r3
  double v47; // fp9
  double v48; // fp7
  bool absoluteknockBack; // r31
  idPhysics_Player *v50; // r3
  idPlayer *PlayerSounds; // r3
  double v52; // fp1
  idPresentable *v53; // r31
  idPresentable *v54; // r3
  idPresentablePlayer *v55; // r3
  idPresentable *v56; // r3
  idPresentablePlayer *v57; // r3
  int trackedMemory; // r10
  int v59; // r9
  double v60; // fp1
  idPresentable *v61; // r3
  float *v62; // r3
  double v63; // fp13
  double v64; // fp12
  idTungstenHealth *p_playerHealth; // r25
  int v66; // r4
  double v67; // fp1
  double v68; // fp31
  idPhysics *Physics; // r3
  int v70; // r7
  idPresentable *v71; // r3
  int v72; // r5
  int v73; // r4
  int v74; // r3
  const idVec3 *v75; // r5
  idPresentablePlayer *v76; // r31
  idPresentable *v77; // r3
  idPresentablePlayer *v78; // r3
  idPresentable *v79; // r11
  int entityNumber; // r31
  idPhysics *v81; // r31
  fxCondition_t hitFXStartCondition; // r29
  int GameMs; // r28
  idPhysics *v84; // r3
  const idVec3 *v85; // r27
  idPresentable *v86; // r26
  const idMat3 *v87; // r3
  idPresentable *v88; // r11
  idPlayerHud *PlayerHud; // r3
  idPresentable *v90; // r3
  int v91; // r3
  int v92; // r4
  double PlayerIncomingDamageScale; // fp1
  double v94; // fp1
  int v95; // r11
  const idDeclDamage *v96; // r5
  bool v97; // r3
  idPresentable *v98; // r11
  char v99; // r29
  int v100; // r11
  idEventArg *v101; // r3
  memTag_t *p_memTag; // r10
  _DWORD *v103; // r11
  int i; // ctr
  idEntity *v105; // r3
  __int64 v106; // r10
  idPresentable *v107; // r3
  int v108; // r3
  idPresentable *v109; // r3
  int v110; // r3
  idBot *botController; // r11
  idPresentable *v112; // r3
  int v113; // r3
  idPresentable *v114; // r3
  int v115; // r11
  idPlayerHud *v116; // r3
  idPresentable *v117; // r3
  int v118; // r3
  idPhysics *v119; // r31
  int v120; // r29
  idPhysics *v121; // r3
  idAIEventManager *p_aiEventManager; // r31
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  const idVec3 *v124; // r3
  idEventArg *v125; // r3
  __int64 v126; // r10
  idGameChallenge *v127; // r3
  const idVec3 *v128; // r7
  double v129; // fp1
  idPresentable *v130; // r3
  idPresentablePlayer *v131; // r3
  idDamageGroup *DamageGroup; // r3
  int v133; // r11
  idBot *v134; // r3
  int v136; // [sp+8h] [-258h]
  __int64 v137; // [sp+8h] [-258h]
  int v138; // [sp+Ch] [-254h]
  int v139; // [sp+10h] [-250h]
  __int64 v140; // [sp+10h] [-250h]
  int v141; // [sp+14h] [-24Ch]
  int v142; // [sp+18h] [-248h]
  __int64 v143; // [sp+18h] [-248h]
  int v144; // [sp+1Ch] [-244h]
  double v145; // [sp+20h] [-240h]
  __int64 v146; // [sp+20h] [-240h]
  double v147; // [sp+28h] [-238h]
  __int64 v148; // [sp+28h] [-238h]
  int v149; // [sp+30h] [-230h]
  __int64 v150; // [sp+30h] [-230h]
  int v151; // [sp+34h] [-22Ch]
  int v152; // [sp+38h] [-228h]
  __int64 v153; // [sp+38h] [-228h]
  int v154; // [sp+3Ch] [-224h]
  double v155; // [sp+40h] [-220h]
  __int64 v156; // [sp+40h] [-220h]
  int v157; // [sp+48h] [-218h]
  int v158; // [sp+4Ch] [-214h]
  int v159; // [sp+50h] [-210h]
  int v160; // [sp+58h] [-208h]
  float v161[2]; // [sp+60h] [-200h] BYREF
  idVec3 v162[2]; // [sp+68h] [-1F8h] BYREF
  idAIEventManager v163; // [sp+80h] [-1E0h] BYREF
  float v164; // [sp+D0h] [-190h]
  char v165; // [sp+E0h] [-180h] BYREF

  v14 = a8;
  if ( damageDef == nullptr || damageDef->ignorePlayer )
    goto LABEL_23;
  if ( g_tracePlayerDamage.valueInteger != 0 )
  {
    v15 = "n/a";
    if ( inflictor != nullptr )
      data = inflictor->name.data;
    else
      data = "n/a";
    if ( attacker != nullptr )
      v15 = attacker->name.data;
    str = damageDef->name.str;
    v18 = gameLocal->GetGameFrame(this: gameLocal);
    v155 = damageScale;
    idLib::Printf(
      fmt: "(%d)%s - inflictor = <%s>, attacker = <%s>, damageDef = <%s>, damageScale = %0.2f\n",
      v18,
      "idPlayer::Damage",
      data,
      v15,
      str,
      damageScale);
  }
  if ( !this->TakesDamage(this) )
    goto LABEL_23;
  presentable = this->presentable;
  v20 = presentable != nullptr ? (int)presentable->GetPlayerInterface_2(this: presentable) : 0;
  if ( (*(_BYTE *)(v20 + 47032) & 0x20) != 0 )
    goto LABEL_23;
  if ( (*((_BYTE *)this + 12824) & 8) != 0 )
    goto LABEL_23;
  thrownCamera = this->thrownCamera;
  if ( thrownCamera == idPlayer::GetControl(this) )
    goto LABEL_23;
  v22 = this->presentable;
  if ( v22 != nullptr )
    v23 = (int)v22->GetPlayerInterface_2(this: v22);
  else
    v23 = 0;
  if ( (*(_BYTE *)(v23 + 47032) & 4) != 0 )
  {
    if ( (damageDef->damageTypes & 0x400) != 0 )
      idPlayer::Revive(this, reviver: nullptr);
LABEL_23:
    v24 = 0.0;
    return *((float *)&v24 + 1);
  }
  ChallengeEntity = idGameLocal::GetChallengeEntity(this: gameLocal);
  if ( !ChallengeEntity->FriendlyFireEnabled(this: ChallengeEntity) )
  {
    v27 = (idPlayer *)idActor::CastTo(c: attacker);
    v28 = v27;
    if ( v27 != nullptr && v27 != this )
    {
      Team = idEntity::GetTeam(this);
      v30 = idEntity::GetTeam(this: v28);
      v31 = idGameLocal::GetChallengeEntity(this: gameLocal);
      if ( (unsigned __int8)idGameChallenge::IsHostile(this: v31, team1: v30, team2: Team) == 0 )
        goto LABEL_23;
    }
  }
  if ( this->isInvulnerable )
    goto LABEL_23;
  if ( v14 != 0 )
  {
    if ( *(_DWORD *)(v14 + 52) == 4 )
      v32 = *(_DWORD *)(v14 + 104);
    else
      LOWORD(v32) = -1;
  }
  else
  {
    LOWORD(v32) = -1;
  }
  HIWORD(v163.eventList.list) = v32;
  v161[0] = 0.0;
  v33 = (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v32;
  idPlayer::CalcDamagePoints(
    this,
    inflictor,
    attacker,
    damageDef,
    damageScale,
    joint: v26,
    health: (const idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)v32,
    a8: v161);
  if ( idVehicle::CastTo(c: (idVehicle *)inflictor) != nullptr )
    v161[0] = player_vehicleDamageMult.valueFloat * v161[0];
  if ( !common->IsMultiplayer(this: common) )
    goto LABEL_42;
  if ( attacker != nullptr )
  {
    v34 = attacker->presentable;
    if ( v34 == nullptr )
    {
      idEntity::InitPresentableInternal(this: attacker);
      v34 = attacker->presentable;
    }
    v35 = (int)v34->GetActorInterface_2(this: v34);
    if ( v35 != 0 )
    {
      v36 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v35 + 372))(a1: v35);
      v161[0] = (float)v36 * v161[0];
    }
LABEL_42:
    if ( attacker != nullptr )
      attacker->DamageFeedback(this: attacker, a2: this, a3: inflictor, a4: damageDef, a5: v161);
  }
  knockBack = damageDef->knockBack;
  v38 = 0;
  v162[0] = vec3_origin;
  if ( knockBack != 0 && (*(_BYTE *)&this->flags & 4) == 0 )
  {
    if ( attacker == this )
      damageScale = (float)(damageDef->selfKnockbackScale * (float)damageScale);
    v39 = *(float *)&trace->trackedMemory;
    v40 = *(float *)&trace->name.str;
    v162[0].x = *(float *)&trace->__vftable;
    v162[0].y = v39;
    v162[0].z = v40;
    idVec3::NormalizeFast(this: v162);
    LODWORD(v41) = knockBack;
    HIDWORD(v42) = &idEventDef::eventDefList[3154];
    LODWORD(v42) = damageDef->knockUp;
    *(_QWORD *)&v163.eventList.list = v41;
    HIDWORD(v41) = damageDef->absoluteknockBack;
    v162[0].x = (float)((float)((float)((float)*(__int64 *)&v163.eventList.list * g_knockback.valueFloat)
                              * (float)damageScale)
                      * (float)0.0049999999)
              * v162[0].x;
    v162[0].y = v162[0].y
              * (float)((float)((float)((float)*(__int64 *)&v163.eventList.list * g_knockback.valueFloat)
                              * (float)damageScale)
                      * (float)0.0049999999);
    v162[0].z = (float)((float)((float)((float)((float)*(__int64 *)&v163.eventList.list * g_knockback.valueFloat)
                                      * (float)damageScale)
                              * (float)0.0049999999)
                      * v162[0].z)
              + (float)((float)v42 * (float)0.5);
    *(_QWORD *)&v163.eventList.list = v42;
    if ( HIDWORD(v41) != 0 )
    {
      PhysicsObj = idPlayer::GetPhysicsObj(this);
      (*(void (__fastcall **)(int, idVec3 *, _DWORD))(*(_DWORD *)PhysicsObj + 80))(a1: PhysicsObj, a2: v162, a3: 0);
    }
    else
    {
      v44 = idPlayer::GetPhysicsObj(this);
      v45 = idPlayer::GetPhysicsObj(this);
      v46 = (float *)(*(int (__fastcall **)(idList<idEntityPtr<idEntity>,5> *, int, _DWORD))(*(_DWORD *)v44 + 88))(
                       a1: &v163.receivers,
                       a2: v44,
                       a3: 0);
      v47 = (float)(v46[2] + v162[0].z);
      v48 = (float)(v46[1] + v162[0].y);
      *(float *)&v163.eventPools.size = *v46 + v162[0].x;
      v164 = v47;
      *(float *)&v163.eventPools.granularity = v48;
      (*(void (__fastcall **)(int, int *, _DWORD))(*(_DWORD *)v45 + 80))(a1: v45, a2: &v163.eventPools.size, a3: 0);
    }
    if ( 2 * knockBack >= 50 )
    {
      v38 = 200;
      if ( 2 * knockBack <= 200 )
        v38 = 2 * knockBack;
    }
    else
    {
      v38 = 50;
    }
    absoluteknockBack = damageDef->absoluteknockBack;
    v50 = (idPhysics_Player *)idPlayer::GetPhysicsObj(this);
    idPhysics_Player::SetKnockBack(this: v50, knockBackTime: v38, absoluteKnockBack: absoluteknockBack);
  }
  if ( damageDef->burning )
  {
    PlayerSounds = idPlayer::GetPlayerSounds(
                     this: (idPlayer *)&v165,
                     result: (const idDeclPlayerProps::playerSounds_t *)this);
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_BODY3,
      shader: (const idSoundShader *)LODWORD(PlayerSounds->spawnOrientation.mat[0].x),
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  }
  if ( g_debugDamage.valueInteger != 0 )
  {
    v52 = ((double (__fastcall *)(idTungstenHealth *))this->playerHealth.GetCurBaseHealth_Impl)(a1: &this->playerHealth);
    v147 = v161[0];
    v145 = v52;
    idLib::Printf(fmt: "client:%i health:%.2f damage:%.2f\n", this->entityNumber, v52, v161[0]);
  }
  if ( attacker != nullptr )
  {
    if ( attacker->presentable == nullptr )
      idEntity::InitPresentableInternal(this: attacker);
    v53 = attacker->presentable;
    v54 = this->presentable;
    if ( v54 != nullptr )
      v55 = v54->GetPlayerInterface_2(this: v54);
    else
      v55 = nullptr;
    idPresentablePlayer::ApplyDamageToPresentable(
      this: v55,
      _attacker: v53,
      _damageDef: damageDef,
      _damage: v161[0],
      dir: (idVec3 *)trace->__vftable,
      kick: (idVec3 *)trace->trackedMemory,
      timer: __SPAIR64__(LODWORD(v162[0].y), __ROL4__(LODWORD(v162[0].z), 32)),
      a8: v136,
      a9: v138,
      a10: v139,
      a11: v141,
      a12: v142,
      a13: v144,
      a14: SHIDWORD(v145),
      a15: SLODWORD(v145),
      a16: SHIDWORD(v147),
      a17: SLODWORD(v147),
      a18: v149,
      a19: v151,
      a20: v152,
      a21: v154,
      a22: SHIDWORD(v155),
      a23: SLODWORD(v155),
      a24: v157,
      a25: v158,
      a26: v159,
      a27: v38,
      a28: v160);
  }
  else
  {
    v56 = this->presentable;
    if ( v56 != nullptr )
      v57 = v56->GetPlayerInterface_2(this: v56);
    else
      v57 = nullptr;
    idPresentablePlayer::ApplyDamageToPresentable(
      this: v57,
      _attacker: nullptr,
      _damageDef: damageDef,
      _damage: v161[0],
      dir: (idVec3 *)trace->__vftable,
      kick: (idVec3 *)trace->trackedMemory,
      timer: __SPAIR64__(LODWORD(v162[0].y), __ROL4__(LODWORD(v162[0].z), 32)),
      a8: v136,
      a9: v138,
      a10: v139,
      a11: v141,
      a12: v142,
      a13: v144,
      a14: SHIDWORD(v145),
      a15: SLODWORD(v145),
      a16: SHIDWORD(v147),
      a17: SLODWORD(v147),
      a18: v149,
      a19: v151,
      a20: v152,
      a21: v154,
      a22: SHIDWORD(v155),
      a23: SLODWORD(v155),
      a24: v157,
      a25: v158,
      a26: v159,
      a27: v38,
      a28: v160);
  }
  if ( attacker == (idPlayer *)gameLocal->world )
  {
    v63 = *(float *)&trace->trackedMemory;
    v64 = *(float *)&trace->name.str;
    v163.eventHash.hashSize = (int)trace->__vftable;
    *(float *)&v163.eventHash.indexSize = v63;
    *(float *)&v163.eventHash.granularity = v64;
    idVec3::NormalizeFast(this: (idVec3 *)&v163.eventHash.hashSize);
  }
  else
  {
    trackedMemory = trace->trackedMemory;
    v59 = (int)trace->name.str;
    v163.eventList.list = (idAIEvent **)trace->__vftable;
    v163.eventList.num = trackedMemory;
    v163.eventList.size = v59;
    v60 = idVec3::NormalizeFast(this: (idVec3 *)&v163);
    v61 = this->presentable;
    if ( v61 != nullptr )
      v62 = (float *)((int (__fastcall *)(idPresentable *, double))v61->GetPlayerInterface_2)(a1: v61, a2: v60);
    else
      v62 = nullptr;
    *(float *)&v163.eventHash.hashSize = (float)(*(float *)&v163.eventList.list * v62[11636])
                                       + (float)((float)(v62[11637] * *(float *)&v163.eventList.num)
                                               + (float)(v62[11638] * *(float *)&v163.eventList.size));
    *(float *)&v163.eventHash.indexSize = (float)(v62[11639] * *(float *)&v163.eventList.list)
                                        + (float)((float)(v62[11640] * *(float *)&v163.eventList.num)
                                                + (float)(v62[11641] * *(float *)&v163.eventList.size));
    *(float *)&v163.eventHash.granularity = (float)(*(float *)&v163.eventList.list * v62[11642])
                                          + (float)((float)(v62[11643] * *(float *)&v163.eventList.num)
                                                  + (float)(v62[11644] * *(float *)&v163.eventList.size));
  }
  p_playerHealth = &this->playerHealth;
  if ( !this->playerHealth.IsDead_Impl(this: &this->playerHealth) && attacker != nullptr && attacker != this )
  {
    v67 = ((double (__fastcall *)(idTungstenHealth *))p_playerHealth->GetMaxBaseHealth_Impl)(a1: &this->playerHealth);
    v68 = (float)(v161[0] / (float)v67);
    Physics = idEntity::GetPhysics(this: attacker);
    v70 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v72 = *(_DWORD *)(v70 + 4);
    v73 = *(_DWORD *)(v70 + 8);
    v71 = this->presentable;
    v163.eventList.list = *(idAIEvent ***)v70;
    v163.eventList.num = v72;
    v163.eventList.size = v73;
    if ( v71 != nullptr )
      v74 = (int)v71->GetPlayerInterface_2(this: v71);
    else
      v74 = 0;
    idView::DamageImpulse(
      this: (idView *)(v74 + 16224),
      localKickDir: (const idVec3 *)&v163.eventHash.hashSize,
      inflictorOrg: (const idVec3 *)&v163,
      damageDef,
      impulseDamageScale: v68);
    if ( attacker->presentable == nullptr )
      idEntity::InitPresentableInternal(this: attacker);
    v76 = (idPresentablePlayer *)attacker->presentable;
    v77 = this->presentable;
    if ( v77 != nullptr )
      v78 = v77->GetPlayerInterface_2(this: v77);
    else
      v78 = nullptr;
    idPresentablePlayer::AddAttacker(this: v78, attacker: v76, damage: v161[0], dir: v75, damageDef: trace);
    if ( damageDef->hitFXStartCondition < FX_MAX_CONDITIONS )
    {
      v79 = attacker->presentable;
      entityNumber = this->entityNumber;
      if ( v79 == nullptr )
      {
        idEntity::InitPresentableInternal(this: attacker);
        v79 = attacker->presentable;
      }
      v79->fxManager.viewCallbacksID = entityNumber + 1;
      v81 = idEntity::GetPhysics(this);
      hitFXStartCondition = damageDef->hitFXStartCondition;
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v84 = idEntity::GetPhysics(this);
      v85 = v84->GetOrigin(this: v84, a2: 0);
      if ( attacker->presentable == nullptr )
        idEntity::InitPresentableInternal(this: attacker);
      v86 = attacker->presentable;
      v87 = v81->GetAxis(this: v81, a2: 0);
      idFXManager::StartFX(
        this: &v86->fxManager,
        org: v85,
        axis: v87,
        time: GameMs,
        startCondition: hitFXStartCondition);
      v88 = attacker->presentable;
      if ( v88 == nullptr )
      {
        idEntity::InitPresentableInternal(this: attacker);
        v88 = attacker->presentable;
      }
      v14 = a8;
      v88->fxManager.viewCallbacksID = -1;
    }
    *(_QWORD *)&v163.receivers.list = *(_QWORD *)&v163.eventList.list;
    idPlayer::GetPlayerHud(this);
    idPlayerHud::DamageImpulse(this: (idPlayerHud *)v163.receivers.list, origin: (idVec3 *)v163.receivers.num);
    PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this);
    idPlayerHud::ActivateCombatHud(this: PlayerHud);
  }
  if ( damageDef->instantRagdoll )
  {
    v90 = this->presentable;
    if ( v90 != nullptr )
      v91 = (int)v90->GetPlayerInterface_2(this: v90);
    else
      v91 = 0;
    idView::SetControllerShake(
      this: (idView *)(v91 + 16224),
      highMagnitude: 0.5,
      highDuration: v66,
      lowMagnitude: 1.0,
      lowDuration: 250);
  }
  if ( !this->IsDead(this) && v161[0] > 0.0 )
  {
    if ( g_damageScale.valueFloat > 0.0 )
      v161[0] = g_damageScale.valueFloat * v161[0];
    PlayerIncomingDamageScale = idGameLocal::GetPlayerIncomingDamageScale(this: gameLocal);
    if ( PlayerIncomingDamageScale <= 0.0 )
    {
      v94 = v161[0];
    }
    else
    {
      v94 = (float)((float)PlayerIncomingDamageScale * v161[0]);
      v161[0] = v94;
    }
    v95 = *((unsigned __int8 *)this + 12824);
    if ( (v95 & 0x20) != 0 )
    {
      v161[0] = 0.0;
      v94 = 0.0;
    }
    *(float *)&v163.eventHash.hashMask = v94;
    ((void (__fastcall *)(idTungstenHealth *, int, bool, int *))p_playerHealth->Damage_Impl)(
      a1: &this->playerHealth,
      a2: v92,
      a3: (~v95 & 0x10) != 0,
      a4: &v163.eventHash.hashMask);
    idRageMetrics::ClientDamage(
      this: clientGame->rageMetrics,
      player: (idVehicle *)this,
      damage: v161[0],
      damageDef: v96,
      a5: damageDef);
    v97 = p_playerHealth->IsDead_Impl(this: &this->playerHealth);
    v98 = this->presentable;
    v99 = v97;
    if ( v98 != nullptr )
      v100 = (int)v98->GetPlayerInterface_2(this: this->presentable);
    else
      v100 = 0;
    *(_BYTE *)(v100 + 47032) = (v99 << 7) | *(_BYTE *)(v100 + 47032) & 0x7F;
    if ( this->IsDead(this) )
    {
      idRageMetrics::Kill(
        this: clientGame->rageMetrics,
        killer: (idTurret *)attacker,
        victim: (idVehicle *)this,
        inflictor,
        damageDef);
      if ( attacker != nullptr )
        attacker->KilledNotification(this: attacker, a2: this, a3: inflictor, a4: damageDef, a5: v161[0]);
      if ( common->TimeTrialPlaying(this: common) )
        common->StopSnapshotFilePlayback(this: common);
      if ( common->TimeTrialRecording(this: common) )
        common->StopSnapshotFileRecord(this: common);
      idPlayer::ToggleZoom(this, z: false);
      idPlayer::SetupZoom(this, handsZoomIn: false);
      if ( idEntityPtr<idEntity const>::operator->(this: &this->deathTrigger) != nullptr )
      {
        v101 = idEventArg::idEventArg(this: (idEventArg *)&v163, data: this);
        p_memTag = &v163.eventHash.memTag;
        v103 = (_DWORD *)&v101[-1].value.q[3];
        for ( i = 5; i != 0; --i )
          *++p_memTag = *(memTag_t *)++v103;
        v105 = idEntityPtr<idEntity const>::operator->(this: &this->deathTrigger);
        LODWORD(v106) = &s_memTag[218];
        idEventReceiver::PostEventMS(
          this: v105,
          ev: &EV_Activate,
          arg1: (unsigned int)v163.receivers.size,
          a4: __SPAIR64__(*(unsigned int *)&v163.receivers.granularity, __ROL4__(v163.eventPools.list, 32)),
          a5: v106,
          a6: v137,
          a7: v140,
          a8: v143,
          a9: v146,
          a10: v148,
          a11: v150,
          a12: v153,
          a13: v156);
      }
      v107 = this->presentable;
      if ( v107 != nullptr )
        v108 = (int)v107->GetPlayerInterface_2(this: v107);
      else
        v108 = 0;
      if ( *(_DWORD *)(v108 + 45280) != 0 )
      {
        v109 = this->presentable;
        if ( v109 != nullptr )
          v110 = (int)v109->GetPlayerInterface_2(this: v109);
        else
          v110 = 0;
        idHands::DropThrowable(this: (idHands *)(v110 + 37616));
      }
      botController = this->botController;
      if ( botController == nullptr || botController->isControllingAFKPlayer )
      {
        v112 = this->presentable;
        if ( v112 != nullptr )
          v113 = (int)v112->GetPlayerInterface_2(this: v112);
        else
          v113 = 0;
        idHands::Hide(this: (idHands *)(v113 + 37616), hideReason: HAND_HIDE_GENERIC);
        v114 = this->presentable;
        if ( v114 != nullptr )
          v115 = (int)v114->GetPlayerInterface_2(this: v114);
        else
          v115 = 0;
        *(_BYTE *)(v115 + 40605) = 1;
        v116 = (idPlayerHud *)idPlayer::GetPlayerHud(this);
        idPlayerHud::SetHudState(this: v116, state: HUDSTATE_DAMAGE);
        v117 = this->presentable;
        if ( v117 != nullptr )
          v118 = (int)v117->GetPlayerInterface_2(this: v117);
        else
          v118 = 0;
        *(float *)(v118 + 35392) = 0.0;
      }
      v119 = idEntity::GetPhysics(this);
      v120 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      v121 = v119;
      GetOrigin = v119->GetOrigin;
      p_aiEventManager = &gameLocal->aiEventManager;
      v124 = GetOrigin(this: v121, a2: 0);
      idAIEventManager::AddEvent(
        this: &v163,
        result: p_aiEventManager,
        eventDecl: this->bodyEventDecl,
        curTime: v120,
        originator: this,
        instigator: inflictor,
        origin: v124,
        delay: 0);
      v125 = idEventArg::idEventArg(this: (idEventArg *)&v163.receivers, data: attacker);
      idEventReceiver::BroadcastEvent(
        this,
        ev: *(const idEventDef **)&v125->type,
        arg1: *(_QWORD *)&v125->value.q[1],
        a4: __SPAIR64__(__ROL4__(LODWORD(v125->value.q[3]), 32), (unsigned int)v125),
        a5: v126,
        a6: v137,
        a7: v140,
        a8: v143,
        a9: v146,
        a10: v148,
        a11: v150);
      v127 = idGameLocal::GetChallengeEntity(this: gameLocal);
      if ( v127->PlayerReviveEnabled(this: v127) )
      {
        idPlayer::Incapacitate(this);
      }
      else
      {
        v129 = v161[0];
        if ( v14 != 0 )
          idPlayer::Killed(
            this,
            inflictor,
            attacker,
            damageDecl: damageDef,
            damage: v129,
            impactPoint: v128,
            impactDir: (const idVec3 *)(v14 + 4),
            joint: (const idIndex<short,enum invalidJointIndex_t> *)trace);
        else
          idPlayer::Killed(
            this,
            inflictor,
            attacker,
            damageDecl: damageDef,
            damage: v129,
            impactPoint: v128,
            impactDir: &vec3_origin,
            joint: (const idIndex<short,enum invalidJointIndex_t> *)trace);
      }
    }
    else
    {
      v130 = this->presentable;
      if ( v130 != nullptr )
        v131 = v130->GetPlayerInterface_2(this: v130);
      else
        v131 = nullptr;
      idPresentablePlayer::PresentableDamaged(this: v131, damage: v161[0]);
      if ( com_multiplayer.valueInteger == 0 && idPlayer::IsLocallyControlled(this) )
        p_playerHealth->GetBaseHealthRatio_Impl(this: &this->playerHealth);
    }
  }
  if ( !damageDef->noSound )
    idEntity::StartSoundShader(
      this,
      channel: SND_CHANNEL_DAMAGE,
      shader: damageDef->damageSound,
      soundShaderFlags: (soundShaderFlags_t)0,
      peerMask: 0xFFu);
  DamageGroup = idActor::GetDamageGroup(this, joint: v33);
  if ( DamageGroup != nullptr )
    v133 = DamageGroup - this->actorEditable.damageGroups.list;
  else
    v133 = -1;
  this->damageGroup = v133;
  idEngagementTracker::OnEngaged(this: &this->engagementTracker, attacker, engagementTimeOverride: 0.0);
  if ( v161[0] > 0.0 )
  {
    v134 = this->botController;
    if ( v134 != nullptr )
      idBot::OnTakeDamage(this: v134, attacker);
  }
  v24 = v161[0];
  return *((float *)&v24 + 1);
}


// ========================================================================
// ?UpdateCoverCheck@idPlayer@@IAAXXZ
// EA  : 0x82E37368
// RVA : 0x00E37368
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateCoverCheck(idPlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idWorldspawn *world; // r9
  int valueInteger; // r11
  bool v6; // r20
  idPhysics *Physics; // r3
  int v8; // r3
  int *v9; // r10
  _DWORD *v10; // r11
  int i; // ctr
  int AreaNum; // r25
  int currentCoverCheckIndex; // r10
  idPlayerCoverScore_t *list; // r9
  signed int v15; // r8
  int v16; // r27
  int v17; // r30
  bool v18; // r11
  bool v19; // r26
  idPlayerCoverScore_t *v20; // r28
  idColor *v21; // r9
  idColor *v22; // r8
  idPlayerCoverScore_t *v23; // r30
  idPhysics *v24; // r3
  double valueFloat; // fp31
  float *v26; // r3
  double v27; // fp13
  double v28; // fp12
  idPhysics *v29; // r3
  float *v30; // r3
  double v31; // fp6
  double v32; // fp4
  double v33; // fp2
  bool v34; // r3
  bool IsLocallyControlled; // zf
  bool v36; // r3
  idPhysics *v37; // r3
  float *v38; // r3
  double v39; // fp12
  int v40; // r7
  int v41; // r6
  __int64 v42; // r10
  int *v43; // r11
  int v44; // ctr
  int v45; // r10
  int v46; // r8
  idPhysics *v47; // r3
  const idAAS2 *aas; // r30
  idAAS2_vtbl *v49; // r28
  int v50; // r3
  idVehicleState **v51; // r4
  int v52; // r30
  int *v53; // r28
  aas2Cluster_t *v54; // r3
  int v55; // r11
  int num; // r10
  int v57; // r30
  int v58; // r26
  unsigned int v59; // r27
  idPlayerCoverScore_t *v60; // r10
  idVehicleState **v61; // r11
  idVehicleState *coverIndex; // r6
  int v63; // r28
  idVehicleState **v64; // r8
  idList<idPlayerCoverScore_t,5> *p_playerCoverScores; // r27
  int v66; // r10
  unsigned int v67; // r11
  idVehicleState **v68; // r9
  idPlayerCoverScore_t *v69; // r8
  int v70; // r28
  int v71; // r30
  signed int v72; // r11
  idPhysics *v73; // r3
  float *v74; // r3
  idPVS *p_pvs; // r26
  int PVSAreas; // r28
  int v77; // r30
  int v78; // r30
  int v79; // r9
  int v80; // r26
  int v81; // r28
  idPlayerCoverScore_t *v82; // r11
  double v83; // fp0
  const idAAS2 *v84; // r3
  int v85; // r4
  float *v86; // r3
  float *v87; // r30
  double v88; // fp0
  double v89; // fp12
  idPlayerCoverScore_t *v90; // r11
  double v91; // fp3
  double v92; // fp2
  __int64 v93; // r6
  __int64 v94; // r10
  __int64 v95; // r8
  va *v96; // r4
  idPlayerCoverScore_t *v97; // r11
  double firePointScore; // fp0
  double v99; // fp8
  double v100; // fp4
  idPlayerCoverScore_t *v101; // r11
  double v102; // fp10
  double v103; // fp8
  __int64 v104; // r6
  __int64 v105; // r10
  __int64 v106; // r8
  va *v107; // r4
  int v108; // [sp+8h] [-1CA8h]
  int v109; // [sp+8h] [-1CA8h]
  int v110; // [sp+Ch] [-1CA4h]
  int v111; // [sp+Ch] [-1CA4h]
  int v112; // [sp+10h] [-1CA0h]
  int v113; // [sp+10h] [-1CA0h]
  int v114; // [sp+14h] [-1C9Ch]
  int v115; // [sp+14h] [-1C9Ch]
  double standingScore; // [sp+18h] [-1C98h]
  int v117; // [sp+18h] [-1C98h]
  int v118; // [sp+1Ch] [-1C94h]
  double v119; // [sp+20h] [-1C90h]
  double v120; // [sp+20h] [-1C90h]
  unsigned int v121[4]; // [sp+60h] [-1C50h] BYREF
  float v122[4]; // [sp+70h] [-1C40h] BYREF
  float v123; // [sp+80h] [-1C30h] BYREF
  float v124; // [sp+84h] [-1C2Ch]
  float v125; // [sp+88h] [-1C28h]
  idVec3 v126; // [sp+90h] [-1C20h] BYREF
  idSort_Quick<idPlayerCoverScore_t,idSort_PlayerCoverScores> v127; // [sp+9Ch] [-1C14h] BYREF
  idPLogScope v128; // [sp+A0h] [-1C10h] BYREF
  idVec3 v129; // [sp+A8h] [-1C08h] BYREF
  idVec3 v130; // [sp+B8h] [-1BF8h] BYREF
  float v131[6]; // [sp+C8h] [-1BE8h] BYREF
  idBounds v132; // [sp+E0h] [-1BD0h] BYREF
  float v133[5]; // [sp+F8h] [-1BB8h] BYREF
  int v134; // [sp+10Ch] [-1BA4h] BYREF
  idEventReceiver v135; // [sp+110h] [-1BA0h] BYREF
  float v136; // [sp+124h] [-1B8Ch]
  float v137[4]; // [sp+128h] [-1B88h] BYREF
  float v138[6]; // [sp+138h] [-1B78h] BYREF
  idList<idDeclVehicleUpgrade const *,5> v139; // [sp+150h] [-1B60h] BYREF
  idBounds v140; // [sp+160h] [-1B50h] BYREF
  int v141[8]; // [sp+180h] [-1B30h] BYREF
  int v142[7]; // [sp+1A0h] [-1B10h] BYREF
  int v143; // [sp+1BCh] [-1AF4h] BYREF
  _BYTE v144[512]; // [sp+1C0h] [-1AF0h] BYREF
  idList<idVehicleState *,5> v145; // [sp+3C0h] [-18F0h] BYREF
  _BYTE v146[2048]; // [sp+3D0h] [-18E0h] BYREF
  va v147; // [sp+BD0h] [-10E0h] BYREF

  RD_EventBegin(name: "idPlayer::UpdateCoverCheck");
  LODWORD(v2) = "idPlayer::UpdateCoverCheck";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v128, pl: &pLog, gMask: v2, label: v3);
  world = gameLocal->world;
  if ( world == nullptr
    || world->mapType == MAPTYPE_TOWN
    || !world->aiUsesCover
    || g_stopTime.valueInteger != 0
    || g_usePlayerCoverCheck.valueInteger == 0
    || this->aas == nullptr
    || ((int (*)(void))gameLocal->GetGameFrame)() < 10 )
  {
    goto _M527781;
  }
  valueInteger = vis_dumpCoverInfo.valueInteger;
  if ( vis_dumpCoverInfo.valueInteger == 1 )
  {
    if ( idPlayer::IsLocallyControlled(this) )
    {
LABEL_13:
      v6 = true;
      goto LABEL_15;
    }
    valueInteger = vis_dumpCoverInfo.valueInteger;
  }
  if ( valueInteger == 2 && !idPlayer::IsLocallyControlled(this) )
    goto LABEL_13;
  v6 = false;
LABEL_15:
  Physics = idEntity::GetPhysics(this);
  v8 = (int)Physics->GetBounds(this: Physics, a2: -1);
  v9 = &v134;
  v10 = (_DWORD *)(v8 - 4);
  for ( i = 6; i != 0; --i )
    *++v9 = *++v10;
  AreaNum = idActor::GetAreaNum(this, aas: (idAAS2 *)this->aas);
  if ( AreaNum != 0 )
  {
    v121[0] = this->playerCoverScores.num;
    if ( (int)v121[0] > 0 )
    {
      currentCoverCheckIndex = this->currentCoverCheckIndex;
      __twllei(v121[0], 0);
      list = this->playerCoverScores.list;
      v15 = currentCoverCheckIndex + v121[0] - 1;
      v16 = v15 % (signed int)v121[0];
      v17 = v15 % (signed int)v121[0];
      __twlgei(v121[0] & ~(__ROL4__(v15, 1) - 1), 0xFFFFFFFF);
      if ( list[v17].coverState == 1 )
      {
        list[v17].standingScore = 0.0;
        this->playerCoverScores.list[v17].firePointScore = 0.0;
      }
      else
      {
        idPlayer::GetCoverCheckEyePoint(
          this: (idPlayer *)&v130,
          result: (idVec3 *)this,
          coverIndex: v15 % (signed int)v121[0]);
        *(float *)v121 = (float)(v130.z - (float)10.0) - (float)20.0;
        v130.z = v130.z - (float)10.0;
        v18 = vis_showPlayerCoverLineChecks.valueInteger != 0
           && (vis_showCoverNum.valueInteger == -1
            || vis_showCoverNum.valueInteger == this->playerCoverScores.list[v17].coverIndex);
        v19 = v18;
        if ( v18 )
        {
          v21 = &idColor::colorRed;
          v22 = &idColor::colorGreen;
        }
        else
        {
          v21 = nullptr;
          v22 = nullptr;
        }
        v20 = &this->playerCoverScores.list[v17];
        v20->standingScore = idDeferredVisGrid::GetGridVisibility(
                               this: &this->deferredVisGrid,
                               worldPoint: &v130,
                               deferredVisCache: &gameLocal->deferredVisCache,
                               staggerZ: (const float *)v121,
                               flags: 0,
                               missDebugColor: v22,
                               hitDebugColor: v21);
        v23 = &this->playerCoverScores.list[v17];
        v23->firePointScore = idPlayer::GetCoverFirePointVisiblity(this, coverIndex: v16, flags: 1, debug: v19);
      }
    }
    v24 = idEntity::GetPhysics(this);
    valueFloat = pm_normalviewheight.valueFloat;
    v26 = (float *)v24->GetOrigin(this: v24, a2: 0);
    v27 = v26[1];
    v28 = (float)(v26[2] + (float)valueFloat);
    v129.x = *v26;
    v129.y = v27;
    v129.z = v28;
    idDeferredVisGrid::Update(
      this: &this->deferredVisGrid,
      entityPos: &v129,
      aas: this->aas,
      areaNum: AreaNum,
      travelFlags: 53240);
    v29 = idEntity::GetPhysics(this);
    v30 = (float *)v29->GetOrigin(this: v29, a2: 0);
    v31 = (float)(this->previousCoverCheckPos.y - v30[1]);
    v32 = (float)(this->previousCoverCheckPos.x - *v30);
    v33 = (float)(this->previousCoverCheckPos.z - v30[2]);
    if ( (float)((float)((float)v33 * (float)v33)
               + (float)((float)((float)v32 * (float)v32) + (float)((float)v31 * (float)v31))) > 16384.0 )
    {
      if ( !v6 || (IsLocallyControlled = idPlayer::IsLocallyControlled(this), v34 = true, !IsLocallyControlled) )
        v34 = false;
      idLib::PrintfIf(condition: v34, fmt: "Updating cover points for locally controlled player\n");
      if ( !v6 || (IsLocallyControlled = !idPlayer::IsLocallyControlled(this), v36 = true, !IsLocallyControlled) )
        v36 = false;
      idLib::PrintfIf(condition: v36, fmt: "Updating cover points for non-locally controlled player\n");
      v37 = idEntity::GetPhysics(this);
      v38 = (float *)v37->GetOrigin(this: v37, a2: 0);
      this->previousCoverCheckPos.x = *v38;
      this->previousCoverCheckPos.y = v38[1];
      v39 = v38[2];
      v121[0] = 0;
      this->previousCoverCheckPos.z = v39;
      idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: &v139);
      idEncounterGroupManager::GetActiveHintNodeCoverIndices(
        this: &gameLocal->encounterGroupManager,
        coverIndices: (idList<idVehicleState *,5> *)&v139);
      if ( v139.num <= 0 )
      {
        v47 = idEntity::GetPhysics(this);
        aas = this->aas;
        v49 = aas->__vftable;
        v50 = (int)v47->GetOrigin(this: v47, a2: 0);
        ((void (__fastcall *)(const idAAS2 *, int, int, char *, int, _DWORD, int, _BYTE *, double))v49->FindCoverPoints)(
          a1: aas,
          a2: AreaNum,
          a3: v50,
          a4: byte_821B0000,
          a5: 0x7FFFFFFF,
          a6: 0,
          a7: 0x7FFFFFFF,
          a8: v144,
          a9: 1536.0);
        HIDWORD(v42) = v121[0];
      }
      else
      {
        HIDWORD(v42) = 128;
        if ( v139.num <= 128 )
          HIDWORD(v42) = v139.num;
        v121[0] = HIDWORD(v42);
        v43 = (int *)v144;
        v44 = HIDWORD(v42);
        v45 = (char *)v139.list - v144;
        do
        {
          v46 = *(int *)((char *)v43 + v45);
          *v43++ = v46;
          --v44;
        }
        while ( v44 != 0 );
      }
      if ( HIDWORD(v42) != 0 )
      {
        v145.granularity = 1;
        LODWORD(v42) = 128;
        v145.num = 0;
        v51 = (idVehicleState **)v146;
        v145.memTag = 5;
        v145.size = 128;
        v145.list = (idVehicleState **)v146;
        v145.listStatic = 1;
        v52 = 0;
        if ( SHIDWORD(v42) > 0 )
        {
          v53 = &v143;
          do
          {
            v54 = idList<idPlayerCoverScore_t,5>::Alloc(this: (idList<aas2Cluster_t,37> *)&v145);
            v55 = *++v53;
            ++v52;
            *(float *)&v54->numPortals = 0.0;
            *(float *)&v54->firstPortal = 0.0;
            v54->numReachableAreas = 0;
            v54->numAreas = v55;
            HIDWORD(v42) = v121[0];
          }
          while ( v52 < (int)v121[0] );
          v51 = v145.list;
        }
        v127.__vftable = (idSort_Quick<idPlayerCoverScore_t,idSort_PlayerCoverScores>_vtbl *)&idSort_PlayerCoverScores::`vftable';
        if ( v51 != nullptr )
        {
          idSort_Quick<idPlayerCoverScore_t,idSort_PlayerCoverScores>::Sort(
            this: &v127,
            base: (idPlayerCoverScore_t *)v51,
            num: v145.num,
            a4: v41,
            a5: v40,
            a6: v46,
            a7: v42);
          HIDWORD(v42) = v121[0];
          v51 = v145.list;
        }
        num = this->playerCoverScores.num;
        v57 = 0;
        v58 = 0;
        v127.__vftable = (idSort_Quick<idPlayerCoverScore_t,idSort_PlayerCoverScores>_vtbl *)&idSort<idPlayerCoverScore_t>::`vftable';
        if ( num > 0 )
        {
          v59 = 0;
          do
          {
            if ( v57 >= SHIDWORD(v42) )
              break;
            v60 = &this->playerCoverScores.list[v59 / 0x10];
            v61 = &v51[4 * v57];
            coverIndex = (idVehicleState *)v60->coverIndex;
            while ( (int)*v61 < (int)coverIndex )
            {
              ++v57;
              v61 += 4;
              if ( v57 >= SHIDWORD(v42) )
                goto LABEL_62;
            }
            if ( v57 < SHIDWORD(v42) )
            {
              v63 = 4 * v57;
              if ( v51[4 * v57] == coverIndex )
              {
                idLib::PrintfIf(
                  condition: v6,
                  fmt: "  Recycled %d : %d - %f\n",
                  v58,
                  (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v60->standingScore)),
                  v60->standingScore);
                LODWORD(v42) = this->playerCoverScores.list;
                ++v57;
                v64 = &v145.list[v63];
                *v64 = *(idVehicleState **)(v59 + v42);
                v64[1] = *(idVehicleState **)(v59 + v42 + 4);
                v64[2] = *(idVehicleState **)(v59 + v42 + 8);
                v64[3] = *(idVehicleState **)(v59 + v42 + 12);
                HIDWORD(v42) = v121[0];
                v51 = v145.list;
              }
            }
LABEL_62:
            ++v58;
            v59 += 16;
          }
          while ( v58 < this->playerCoverScores.num );
        }
        p_playerCoverScores = &this->playerCoverScores;
        idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)&this->playerCoverScores, newNum: v145.num);
        v66 = 0;
        if ( this->playerCoverScores.num > 0 )
        {
          v67 = 0;
          do
          {
            ++v66;
            v68 = &v145.list[v67 / 4];
            v69 = &p_playerCoverScores->list[v67 / 0x10];
            v69->coverIndex = (int)v145.list[v67 / 4];
            v67 += 16;
            v69->coverState = (int)v68[1];
            LODWORD(v69->standingScore) = v68[2];
            LODWORD(v69->firePointScore) = v68[3];
          }
          while ( v66 < this->playerCoverScores.num );
        }
        this->currentCoverCheckIndex = 0;
        if ( v6 )
        {
          v70 = 0;
          if ( this->playerCoverScores.num > 0 )
          {
            v71 = 0;
            do
            {
              idLib::Printf(fmt: " %d : %d\n", v70, p_playerCoverScores->list[v71].coverIndex);
              standingScore = p_playerCoverScores->list[v71].standingScore;
              idLib::Printf(fmt: (const char *)HIDWORD(standingScore), LODWORD(standingScore));
              ++v70;
              ++v71;
            }
            while ( v70 < this->playerCoverScores.num );
          }
        }
        idList<idThread *,58>::Clear(this: &v145);
      }
      else
      {
        idLib::PrintfIf(condition: v6, fmt: "No cover points!\n");
        idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)&this->playerCoverScores, newNum: 0);
        this->currentCoverCheckIndex = 0;
      }
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v139);
    }
    v121[0] = this->playerCoverScores.num;
    v72 = v121[0];
    if ( (int)v121[0] > 0 )
    {
      idPlayer::GetCoverCheckEyePoint(
        this: (idPlayer *)&v126,
        result: (idVec3 *)this,
        coverIndex: this->currentCoverCheckIndex);
      v126.z = v126.z - (float)10.0;
      v73 = idEntity::GetPhysics(this);
      v74 = (float *)v73->GetOrigin(this: v73, a2: 0);
      if ( (float)((float)((float)(v126.z - v74[2]) * (float)(v126.z - v74[2]))
                 + (float)((float)((float)(v126.x - *v74) * (float)(v126.x - *v74))
                         + (float)((float)(v126.y - v74[1]) * (float)(v126.y - v74[1])))) > 25000000.0 )
      {
        this->playerCoverScores.list[this->currentCoverCheckIndex].coverState = 1;
      }
      else
      {
        v140.b[1].z = v136 + v129.z;
        v140.b[0].z = v129.z - *(float *)&v135.listeningToList;
        v140.b[1].x = v129.x + (float)128.0;
        v140.b[0].x = v129.x - (float)128.0;
        v140.b[1].y = v129.y + (float)128.0;
        p_pvs = &clientGame->pvs;
        v140.b[0].y = v129.y - (float)128.0;
        PVSAreas = idPVS::GetPVSAreas(this: &clientGame->pvs, bounds: &v140, areas: v141, maxAreas: 8);
        if ( PVSAreas > 0 )
        {
          v77 = 0;
          v132.b[0].x = v126.x;
          v132.b[0].y = v126.y;
          v132.b[0].z = v126.z;
          v132.b[1].x = v126.x;
          v132.b[1].y = v126.y;
          v132.b[1].z = v126.z;
          do
          {
            if ( (unsigned __int8)idPlayer::GetFiringPoint(
                                    this,
                                    fp: v77,
                                    i: this->currentCoverCheckIndex,
                                    coverFlags: v77,
                                    firePointLocation: &v135) != 0 )
              idBounds::AddPoint(this: &v132, v: (const idVec3 *)&v135);
            ++v77;
          }
          while ( v77 < 3 );
          v78 = idPVS::GetPVSAreas(this: p_pvs, bounds: &v132, areas: v142, maxAreas: 8);
          if ( v78 > 0 )
          {
            idPVS::DecodePVS(retstr: (pvsHandle_t *)&v135, this: p_pvs, sourceAreas: v141, numSourceAreas: PVSAreas);
            if ( (unsigned __int8)idPVS::InPVS(
                                    this: p_pvs,
                                    handle: (const pvsHandle_t *)v135.listenerList,
                                    targetAreas: (int)v142,
                                    numTargetAreas: v78) != 0 )
            {
              *(float *)v121 = v126.z - (float)20.0;
              idDeferredVisGrid::GetGridVisibility(
                this: &this->deferredVisGrid,
                worldPoint: &v126,
                deferredVisCache: &gameLocal->deferredVisCache,
                staggerZ: (const float *)v121,
                flags: 2,
                missDebugColor: nullptr,
                hitDebugColor: nullptr);
              idPlayer::GetCoverFirePointVisiblity(
                this,
                coverIndex: this->currentCoverCheckIndex,
                flags: 3,
                debug: false);
              this->playerCoverScores.list[this->currentCoverCheckIndex].coverState = 0;
            }
            else
            {
              this->playerCoverScores.list[this->currentCoverCheckIndex].coverState = 1;
            }
            idPVS::FreePVS(this: (idPVS *)v135.__vftable, handle: (pvsHandle_t *)v135.listenerList);
          }
        }
      }
      v72 = this->playerCoverScores.num;
      v79 = this->currentCoverCheckIndex + 1;
      __twllei(v72, 0);
      v121[0] = v72;
      this->currentCoverCheckIndex = v79 % v72;
      __twlgei(v72 & ~(__ROL4__(v79, 1) - 1), 0xFFFFFFFF);
    }
    if ( v6 )
    {
      v80 = 0;
      v121[0] = v72;
      if ( v72 > 0 )
      {
        v81 = 0;
        while ( 1 )
        {
          v82 = &this->playerCoverScores.list[v81];
          if ( v82->coverState == 1 )
            break;
          v83 = v82->standingScore;
          if ( v83 > 0.75 && v83 <= 1.0 )
          {
            v122[0] = 0.0;
            v122[1] = 1.0;
            v122[2] = 0.0;
            goto LABEL_106;
          }
          if ( v83 > 0.5 && v83 <= 0.75 )
          {
            v122[0] = 0.25;
            v122[1] = 0.75;
            v122[2] = 0.0;
            goto LABEL_106;
          }
          if ( v83 > 0.25 && v83 <= 0.5 )
          {
            v122[0] = 0.75;
            v122[1] = 0.25;
            v122[2] = 0.0;
            goto LABEL_106;
          }
          if ( v83 < 0.0 || v83 > 0.25 )
          {
            v122[1] = 0.0;
            goto LABEL_104;
          }
          v122[1] = 0.0;
          v122[2] = 0.0;
LABEL_105:
          v122[0] = 1.0;
LABEL_106:
          v122[3] = 1.0;
          v84 = this->aas;
          v85 = v82->coverIndex;
          v121[0] = (unsigned int)v82;
          v86 = (float *)v84->GetCoverPoint(this: v84, a2: v85);
          v125 = -1.0;
          v123 = 0.0;
          v87 = v86;
          v124 = 0.0;
          v88 = v86[1];
          v89 = (float)(v86[2] + (float)4.0);
          v133[0] = *v86;
          v133[1] = v88;
          v133[2] = v89;
          ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))clientGame->renderWorld->DebugCircle)(
            a1: clientGame->renderWorld,
            a2: v122,
            a3: v133,
            a4: &v123,
            a5: 16.0);
          v90 = &this->playerCoverScores.list[v81];
          v91 = v87[1];
          v92 = *v87;
          v137[2] = (float)(v125 * (float)-4.0) + v87[2];
          v137[1] = (float)(v124 * (float)-4.0) + (float)v91;
          v137[0] = (float)(v123 * (float)-4.0) + (float)v92;
          v119 = v90->standingScore;
          HIDWORD(v93) = LODWORD(v119);
          v96 = va::va(
                  this: &v147,
                  fmt: (const char *)HIDWORD(v119),
                  a3: v93,
                  a4: v95,
                  a5: v94,
                  a6: v108,
                  a7: v110,
                  a8: v112,
                  a9: v114,
                  a10: SHIDWORD(standingScore),
                  a11: SLODWORD(standingScore));
          ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, float *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
            a1: clientGame->renderWorld,
            a2: v96,
            a3: v137,
            a4: clientGame->renderWorld->__vftable,
            a5: v122,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 0.2);
          v97 = &this->playerCoverScores.list[v81];
          if ( v97->coverState == 1 )
          {
            v122[1] = 1.0;
            goto LABEL_121;
          }
          firePointScore = v97->firePointScore;
          if ( firePointScore <= 0.75 || firePointScore > 1.0 )
          {
            if ( firePointScore <= 0.5 || firePointScore > 0.75 )
            {
              if ( firePointScore <= 0.25 || firePointScore > 0.5 )
              {
                if ( firePointScore >= 0.0 && firePointScore <= 0.25 )
                {
                  v122[1] = 0.0;
                  v122[2] = 0.0;
LABEL_122:
                  v122[0] = 1.0;
                  goto LABEL_123;
                }
                v122[1] = 0.0;
LABEL_121:
                v122[2] = 1.0;
                goto LABEL_122;
              }
              v122[0] = 0.75;
              v122[1] = 0.25;
              v122[2] = 0.0;
            }
            else
            {
              v122[0] = 0.25;
              v122[1] = 0.75;
              v122[2] = 0.0;
            }
          }
          else
          {
            v122[0] = 0.0;
            v122[1] = 1.0;
            v122[2] = 0.0;
          }
LABEL_123:
          v122[3] = 1.0;
          v99 = v87[1];
          v100 = (float)((float)(v123 * (float)-4.0) + *v87);
          v131[2] = (float)(v125 * (float)-4.0) + v87[2];
          v131[0] = v100;
          v131[1] = (float)(v124 * (float)-4.0) + (float)v99;
          ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))clientGame->renderWorld->DebugCircle)(
            a1: clientGame->renderWorld,
            a2: v122,
            a3: v131,
            a4: &v123,
            a5: 8.0);
          v101 = &this->playerCoverScores.list[v81];
          v102 = *v87;
          v103 = v87[1];
          v138[2] = (float)(v125 * (float)-4.0) + v87[2];
          v138[0] = (float)(v123 * (float)-4.0) + (float)v102;
          v138[1] = (float)(v124 * (float)-4.0) + (float)v103;
          v120 = v101->firePointScore;
          HIDWORD(v104) = LODWORD(v120);
          v107 = va::va(
                   this: &v147,
                   fmt: (const char *)HIDWORD(v120),
                   a3: v104,
                   a4: v106,
                   a5: v105,
                   a6: v109,
                   a7: v111,
                   a8: v113,
                   a9: v115,
                   a10: v117,
                   a11: v118);
          ((void (__fastcall *)(idRenderWorld *, va *, float *, idRenderWorld_vtbl *, float *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
            a1: clientGame->renderWorld,
            a2: v107,
            a3: v138,
            a4: clientGame->renderWorld->__vftable,
            a5: v122,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: 0.2);
          ++v80;
          ++v81;
          if ( v80 >= this->playerCoverScores.num )
            goto _M527781;
        }
        v122[1] = 1.0;
LABEL_104:
        v122[2] = 1.0;
        goto LABEL_105;
      }
    }
  }
_M527781:
  idPLogScope::~idPLogScope(this: &v128);
  RD_EventEnd();
}


// ========================================================================
// __unwind$527015
// EA  : 0x82E381F0
// RVA : 0x00E381F0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_527015()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 7344 + 7120));
}


// ========================================================================
// __unwind$527016
// EA  : 0x82E38218
// RVA : 0x00E38218
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_527016()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 7344 + 160));
}


// ========================================================================
// __unwind$527017
// EA  : 0x82E38240
// RVA : 0x00E38240
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_527017()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7344 + 336));
}


// ========================================================================
// __unwind$527018
// EA  : 0x82E38268
// RVA : 0x00E38268
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_527018()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 7344 + 960));
}


// ========================================================================
// __unwind$527019
// EA  : 0x82E38290
// RVA : 0x00E38290
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_527019()
{
  int v0; // r12

  idSort_PlayerCoverScores::~idSort_PlayerCoverScores(this: (idSort_PlayerCoverScores *)(v0 - 7344 + 156));
}


// ========================================================================
// ?GetCoverScoreInfo@idPlayer@@QBAPBUidPlayerCoverScore_t@@H@Z
// EA  : 0x82E382C0
// RVA : 0x00E382C0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

const idPlayerCoverScore_t *__fastcall idPlayer::GetCoverScoreInfo(idPlayer *this, int coverIndex)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  int v6; // r3
  idPlayerCoverScore_t *v7; // r30
  idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore> v9; // [sp+50h] [-50h] BYREF
  idPLogScope v10; // [sp+58h] [-48h] BYREF
  idPlayerCoverScore_t v11; // [sp+60h] [-40h] BYREF

  RD_EventBegin(name: "idPlayer::GetCoverScoreInfo");
  LODWORD(v4) = "idPlayer::GetCoverScoreInfo";
  HIDWORD(v4) = 2;
  idPLogScope::idPLogScope(this: &v10, pl: &pLog, gMask: v4, label: v5);
  v11.coverIndex = coverIndex;
  v9.__vftable = (idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore>_vtbl *)&idSearchPlayerCoverScore::`vftable';
  v6 = idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore>::Search(
         this: &v9,
         base: this->playerCoverScores.list,
         num: this->playerCoverScores.num,
         value: &v11);
  v9.__vftable = (idSearch_Binary<idPlayerCoverScore_t,idSearchPlayerCoverScore>_vtbl *)&idSearch<idPlayerCoverScore_t>::`vftable';
  if ( v6 < 0 || v6 >= this->playerCoverScores.num )
  {
    idPLogScope::~idPLogScope(this: &v10);
    RD_EventEnd();
    return nullptr;
  }
  else
  {
    v7 = &this->playerCoverScores.list[v6];
    idPLogScope::~idPLogScope(this: &v10);
    RD_EventEnd();
    return v7;
  }
}


// ========================================================================
// __unwind$527816
// EA  : 0x82E38384
// RVA : 0x00E38384
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_527816()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 112));
}


// ========================================================================
// __unwind$527817
// EA  : 0x82E383AC
// RVA : 0x00E383AC
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_527817()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$527818
// EA  : 0x82E383D4
// RVA : 0x00E383D4
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_527818()
{
  int v0; // r12

  idSearchPlayerCoverScore::~idSearchPlayerCoverScore(this: (idSearchPlayerCoverScore *)(v0 - 160 + 80));
}


// ========================================================================
// ?UpdateBotComponent@idPlayer@@QAAXXZ
// EA  : 0x82E38408
// RVA : 0x00E38408
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::UpdateBotComponent(idPlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  idPresentable *presentable; // r3
  idPresentableAnimatedEntity *v5; // r3
  idPLogScope v6[6]; // [sp+50h] [-30h] BYREF

  if ( this->botController != nullptr )
  {
    RD_EventBegin(name: "PlayerThink_UpdateBotComponent");
    LODWORD(v2) = "PlayerThink_UpdateBotComponent";
    HIDWORD(v2) = 1536;
    idPLogScope::idPLogScope(this: v6, pl: &pLog, gMask: v2, label: v3);
    idBot::Think(this: this->botController);
    presentable = this->presentable;
    if ( presentable == nullptr )
    {
      idEntity::InitPresentableInternal(this);
      presentable = this->presentable;
    }
    v5 = presentable->GetAnimatedEntityInterface(this: presentable);
    idPresentableAnimatedEntity::UpdateAimAssist(this: v5);
    idPLogScope::~idPLogScope(this: v6);
    RD_EventEnd();
  }
}


// ========================================================================
// __unwind$527911
// EA  : 0x82E38498
// RVA : 0x00E38498
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_527911()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 128 + 88));
}


// ========================================================================
// __unwind$527912
// EA  : 0x82E384C0
// RVA : 0x00E384C0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_527912()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 128 + 80));
}


// ========================================================================
// ?Respawn@idPlayer@@QAAX_NABVidVec3@@ABVidAngles@@PAVidEntity@@0@Z
// EA  : 0x82E384E8
// RVA : 0x00E384E8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::Respawn(
        idPlayer *this,
        bool initial,
        const idVec3 *spawnPos,
        const idAngles *spawnAngles,
        idVehicle *spawnVehicle,
        bool initialSpawnPoint)
{
  idPresentable *presentable; // r3
  int v13; // r3
  idPresentable *v14; // r3
  int v15; // r3
  int entityNumber; // r4
  const idDeclAnimWeb *v17; // r26
  const idDeclAnimWeb *v18; // r27
  const idDeclFX *v19; // r29
  idPresentable *v20; // r11
  char v21; // r10
  int v22; // r30
  idPresentable *v23; // r3
  idPresentablePlayer *v24; // r3
  idSpringCamera *Instance; // r3
  idSpringCamera *v26; // r3
  idPresentable *v27; // r3
  int v28; // r3
  idPresentable *v29; // r3
  int v30; // r29
  int v31; // r3
  idPresentable *v32; // r3
  idPresentablePlayer *v33; // r3
  idPresentable *v34; // r3
  int v35; // r3
  char flags; // r6
  char v37; // r3
  double valueFloat; // fp0
  int GameMs; // r3
  int v40; // r3
  const idDeclEntityDef *v41; // r4
  idPlayerHud *PlayerHud; // r3
  idPlayerHud *v43; // r3
  idPlayerHud *v44; // r3
  idPlayerHud *v45; // r3
  idDeathCamera *v46; // r3
  idThrownCamera *v47; // r3
  idSlowMotionCamera *v48; // r3
  idReviveCamera *v49; // r3
  idSpectatorCamera *v50; // r3
  idSpectatorCamera *v51; // r3
  idInteractionCamera *v52; // r3
  idInteractionCamera *v53; // r3
  const idDeclEntityDef *v54; // r4
  idEntity *v55; // r4
  float *p_nonPlayerEngagementTimer; // r10
  int i; // ctr
  idVehicle *v58; // r3
  idLobbyBase *v59; // r3
  int PhysicsObj; // r3
  int v61; // r4
  idPresentable *v62; // r3
  int v63; // r3
  idPresentable *v64; // r3
  idPresentablePlayer *v65; // r3
  double x; // fp13
  idPresentable *v67; // r3
  idPresentablePlayer *v68; // r3
  idWeapon *Equipped; // r3
  idWeapon *v70; // r30
  idPresentable *v71; // r3
  idPresentablePlayer *v72; // r3
  idPresentable *v73; // r3
  int v74; // r3
  idAIEventManager v75; // [sp+50h] [-80h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v13 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v13 = 0;
  *(_BYTE *)(v13 + 47033) |= 0x20u;
  v14 = this->presentable;
  if ( v14 != nullptr )
    v15 = (int)v14->GetPlayerInterface_2(this: v14);
  else
    v15 = 0;
  *(_BYTE *)(v15 + 47033) &= ~0x40u;
  idPlayer::SetSpectating(this, v: false);
  entityNumber = this->entityNumber;
  if ( entityNumber >= 6 )
    idLib::Error(fmt: "entityNum > MAX_PLAYERS for player.  This is inconceivable. %d", entityNumber);
  idPlayer::ResetControl(this);
  this->StopRagdoll(this);
  idPlayer::InitPhysics(this);
  if ( initial )
  {
    if ( idPresentablePlayer::HANDS_ANIMWEB_NAME != nullptr )
      v17 = (const idDeclAnimWeb *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclAnimWeb::resourceList,
                                     name: idPresentablePlayer::HANDS_ANIMWEB_NAME,
                                     makeDefault: true);
    else
      v17 = nullptr;
    if ( idPresentablePlayer::HANDS_SECONDARY_ANIMWEB_NAME != nullptr )
      v18 = (const idDeclAnimWeb *)idDeclInfo::FindWithInheritance(
                                     this: &idDeclAnimWeb::resourceList,
                                     name: idPresentablePlayer::HANDS_SECONDARY_ANIMWEB_NAME,
                                     makeDefault: true);
    else
      v18 = nullptr;
    if ( idPresentablePlayer::HANDS_FX_NAME != nullptr )
      v19 = (const idDeclFX *)idDeclInfo::FindWithInheritance(
                                this: &idDeclFX::resourceList,
                                name: idPresentablePlayer::HANDS_FX_NAME,
                                makeDefault: true);
    else
      v19 = nullptr;
    v20 = this->presentable;
    if ( v20 == nullptr || (v21 = 1, v20->model == nullptr) )
      v21 = 0;
    if ( v21 != 0 )
    {
      v22 = this->entityNumber;
      if ( v20 == nullptr )
      {
        idEntity::InitPresentableInternal(this);
        v20 = this->presentable;
      }
      v20->model->g.suppressSurfaceInViewID = v22 + 1;
    }
    v23 = this->presentable;
    if ( v23 != nullptr )
      v24 = v23->GetPlayerInterface_2(this: v23);
    else
      v24 = nullptr;
    idPresentablePlayer::Init(
      this: v24,
      handsDeclMD6: this->handsModel,
      handsDeclAnimWeb: v17,
      handsDeclSecondaryAnimWeb: v18,
      handsFX: v19);
    Instance = idSpringCamera::CreateInstance();
    v26 = idSpringCamera::CastTo(c: Instance);
    this->springCamera = v26;
    gameLocal->SpawnEntity(this: gameLocal, a2: v26, a3: -1, a4: -1, a5: 0);
    idSpringCamera::InitDefaultSprings(this: this->springCamera);
    v27 = this->presentable;
    if ( v27 != nullptr )
      v28 = (int)v27->GetPlayerInterface_2(this: v27);
    else
      v28 = 0;
    if ( *(_DWORD *)(v28 + 39204) != 0 )
    {
      v29 = this->presentable;
      v30 = this->entityNumber;
      if ( v29 != nullptr )
        v31 = (int)v29->GetPlayerInterface_2(this: v29);
      else
        v31 = 0;
      *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v31 + 39204) + 168) + 188) = v30 + 1;
    }
  }
  v32 = this->presentable;
  if ( v32 != nullptr )
    v33 = v32->GetPlayerInterface_2(this: v32);
  else
    v33 = nullptr;
  idPresentablePlayer::PresentableRespawn(this: v33, initial);
  v34 = this->presentable;
  if ( v34 != nullptr )
    v35 = (int)v34->GetPlayerInterface_2(this: v34);
  else
    v35 = 0;
  idFocusTracker::ClearFocus(this: (idFocusTracker *)(v35 + 47160));
  flags = (char)this->flags;
  v37 = *((_BYTE *)this + 12824);
  this->lastFrameUnderwater = false;
  this->lastFrameInWater = false;
  this->underwaterEffectIsRunning = false;
  this->transitionEffectIsRunning = false;
  *(_BYTE *)&this->flags = flags | 2;
  *((_BYTE *)this + 12824) = v37 & 0xF7;
  this->actorConstants.perception.eyeOffset.z = pm_normalviewheight.valueFloat;
  this->actorConstants.perception.eyeOffset.x = 0.0;
  this->actorConstants.perception.eyeOffset.y = 0.0;
  valueFloat = pm_crouchviewheight.valueFloat;
  this->actorConstants.perception.crouchedEyeOffset.x = 0.0;
  this->actorConstants.perception.crouchedEyeOffset.y = 0.0;
  this->actorConstants.perception.crouchedEyeOffset.z = valueFloat;
  if ( initial )
    idEntity::ConstructScriptObject(this);
  this->hitFlashTime = 0;
  this->applyDamageScaleEndTime = 0;
  this->applyDamageScale = 1.0;
  idNavSplinePathMgr::GetTracker(this: &gameLocal->aiSplinePathMgr, owner: this);
  idAIEventManager::RemoveEntityEvents(this: &gameLocal->aiEventManager, ent: this);
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAIEventManager::AddEvent(
    this: &v75,
    result: &gameLocal->aiEventManager,
    eventDecl: this->playerAimEventDecl,
    curTime: GameMs,
    originator: this,
    instigator: nullptr,
    origin: spawnPos,
    delay: 0);
  v40 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  idAIEventManager::AddEvent(
    this: &v75,
    result: &gameLocal->aiEventManager,
    eventDecl: this->playerInteractionEventDecl,
    curTime: v40,
    originator: this,
    instigator: nullptr,
    origin: spawnPos,
    delay: 0);
  if ( initial )
  {
    if ( gameLocal->gameSpawnInfo.devmap
      && !gameLocal->gameSpawnInfo.isTransitionalMapRequest
      && gameLocal->world != nullptr )
    {
      PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this);
      idPlayerHud::SetIgnoreJobUpdates(this: PlayerHud, ignore: true);
      idWorldspawn::SetupDevmapInventory(this: gameLocal->world, player: this);
      idWorldspawn::SetDevmapPlayerSettings(this: gameLocal->world, player: this);
      v43 = (idPlayerHud *)idPlayer::GetPlayerHud(this);
      idPlayerHud::SetIgnoreJobUpdates(this: v43, ignore: false);
    }
    v44 = (idPlayerHud *)idPlayer::GetPlayerHud(this);
    idPlayerHud::SetIgnoreJobUpdates(this: v44, ignore: true);
    idJobManager::Init(this: &this->jobManager, player: this, firstLoad: initialSpawnPoint);
    idGameLayerManager::Init(this: &this->gameLayerManager, player: this, firstLoad: initialSpawnPoint);
    v45 = (idPlayerHud *)idPlayer::GetPlayerHud(this);
    idPlayerHud::SetIgnoreJobUpdates(this: v45, ignore: false);
    idAchievementManager::Init(this: &this->achievementManager, player: this);
    idAIEventManager::AddReceiver(this: &gameLocal->aiEventManager, receiver: this);
    this->Hide_2(this);
    v46 = idDeathCamera::CreateInstance();
    this->deathCamera = idDeathCamera::CastTo(c: v46);
    v47 = idThrownCamera::CreateInstance();
    this->thrownCamera = idThrownCamera::CastTo(c: v47);
    v48 = idSlowMotionCamera::CreateInstance();
    this->slowMotionCamera = idSlowMotionCamera::CastTo(c: v48);
    v49 = idReviveCamera::CreateInstance();
    this->reviveCamera = idReviveCamera::CastTo(c: v49);
    gameLocal->SpawnEntity(this: gameLocal, a2: this->deathCamera, a3: -1, a4: -1, a5: -1);
    gameLocal->SpawnEntity(this: gameLocal, a2: this->thrownCamera, a3: -1, a4: -1, a5: -1);
    gameLocal->SpawnEntity(this: gameLocal, a2: this->slowMotionCamera, a3: -1, a4: -1, a5: -1);
    gameLocal->SpawnEntity(this: gameLocal, a2: this->reviveCamera, a3: -1, a4: -1, a5: -1);
    if ( common->IsMultiplayer(this: common) )
    {
      v50 = idSpectatorCamera::CreateInstance();
      v51 = idSpectatorCamera::CastTo(c: v50);
      this->spectatorCamera = v51;
      gameLocal->SpawnEntity(this: gameLocal, a2: v51, a3: -1, a4: -1, a5: -1);
    }
    v52 = idInteractionCamera::CreateInstance();
    v53 = idInteractionCamera::CastTo(c: v52);
    this->dynamicInteractionCamera = v53;
    gameLocal->SpawnEntity(this: gameLocal, a2: v53, a3: -1, a4: -1, a5: -1);
    v54 = this->playerDriver[0];
    if ( v54 != nullptr )
    {
      v55 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v54, a3: -1, a4: -1, a5: -1);
      if ( v55 != nullptr )
        gameLocal->DeleteEntity(this: gameLocal, a2: v55);
    }
    v41 = this->playerDriver[1];
    if ( v41 != nullptr )
    {
      v41 = (const idDeclEntityDef *)gameLocal->SpawnEntityFromDef(this: gameLocal, a2: v41, a3: -1, a4: -1, a5: -1);
      if ( v41 != nullptr )
        gameLocal->DeleteEntity(this: gameLocal, a2: (idEntity *)v41);
    }
  }
  *(_BYTE *)&this->flags &= ~4u;
  ((void (__fastcall *)(idTungstenHealth *, const idDeclEntityDef *))this->playerHealth.Reset_Impl)(
    a1: &this->playerHealth,
    a2: v41);
  this->engagementTracker.nonPlayerEngagementTimer = 0.0;
  this->engagementTracker.lastNonPlayerEngagementTime = 0;
  p_nonPlayerEngagementTimer = &this->engagementTracker.nonPlayerEngagementTimer;
  for ( i = 6; i != 0; --i )
    *++p_nonPlayerEngagementTimer = 0.0;
  this->engagementTracker.isEngaged = false;
  this->engagementTracker.lastAttackerTime = 0;
  this->engagementTracker.lastAttacker.spawnId.value = 0x1FFF;
  idEntity::BecomeActive(this, flags: 7);
  v58 = idVehicle::CastTo(c: spawnVehicle);
  if ( v58 != nullptr )
    v58->EnterVehicle(this: v58, a2: this, a3: SEAT_MAX);
  else
    this->Teleport(this, a2: spawnPos, a3: spawnAngles);
  if ( g_noCoopPlayerCollision.valueInteger != 0
    && common->IsMultiplayer(this: common)
    && (v59 = session->GetActingGameStateLobbyBase(this: session), v59->GetMatchParms(this: v59)->gameType == 1) )
  {
    PhysicsObj = idPlayer::GetPhysicsObj(this);
    v61 = 74761;
  }
  else
  {
    v62 = this->presentable;
    if ( v62 != nullptr )
      v63 = (int)v62->GetPlayerInterface_2(this: v62);
    else
      v63 = 0;
    PhysicsObj = v63 + 36264;
    v61 = 107529;
  }
  (*(void (__fastcall **)(int, int, int))(*(_DWORD *)PhysicsObj + 32))(a1: PhysicsObj, a2: v61, a3: -1);
  if ( this->GetVehicle_2(this) == nullptr )
  {
    this->Show(this);
    idPlayer::ResetControl(this);
  }
  idPlayer::PlayerBehavior_Startup(this);
  v64 = this->presentable;
  if ( v64 != nullptr )
    v65 = v64->GetPlayerInterface_2(this: v64);
  else
    v65 = nullptr;
  idPresentablePlayer::ClearWeaponKick(this: v65);
  if ( this->botController == nullptr )
  {
    this->aas = (const idAAS2 *)idGameLocal::GetAAS(this: gameLocal, typeName: "aas_monster48", load: false);
    idList<parmValue_t,56>::SetNum(this: (idList<idPlane,37> *)&this->playerCoverScores, newNum: 0);
    x = this->previousCoverCheckPos.x;
    this->currentCoverCheckIndex = 0;
    this->previousCoverCheckPos.x = (float)x + (float)10000.0;
    idPlayer::UpdateCoverCheck(this);
  }
  idRageMetrics::AddPlayer(this: clientGame->rageMetrics, player: this);
  v67 = this->presentable;
  if ( v67 != nullptr )
    v68 = v67->GetPlayerInterface_2(this: v67);
  else
    v68 = nullptr;
  Equipped = (idWeapon *)idPresentablePlayer::GetEquipped(this: v68, slot: EQUIP_RIGHT_HAND);
  v70 = idWeapon::CastTo(c: Equipped);
  if ( v70 != nullptr )
  {
    v71 = this->presentable;
    if ( v71 != nullptr )
      v72 = v71->GetPlayerInterface_2(this: v71);
    else
      v72 = nullptr;
    idPresentablePlayer::EquipItem(this: v72, item: v70);
    v73 = this->presentable;
    if ( v73 != nullptr )
      v74 = (int)v73->GetPlayerInterface_2(this: v73);
    else
      v74 = 0;
    idHands::ResetAnimWeb(this: (idHands *)(v74 + 37616));
  }
}


// ========================================================================
// ?Think@idPlayer@@UAAXXZ
// EA  : 0x82E38EE0
// RVA : 0x00E38EE0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idPlayer::Think(idPlayer *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  unsigned __int64 v4; // r6
  const char *v5; // r7
  idRageMetrics *rageMetrics; // r29
  int GameMs; // r29
  __int64 v8; // r7
  idPresentable *presentable; // r3
  idPresentablePlayer *v10; // r3
  int PlayerGameTime; // r3
  double valueFloat; // fp0
  int v13; // r10
  int v14; // r9
  idBot *botController; // r11
  idPresentable *v16; // r3
  int v17; // r3
  idPresentable *v18; // r3
  int v19; // r3
  idPhysics *Physics; // r3
  float *v21; // r3
  idPhysics *v22; // r3
  float *v23; // r3
  idPhysics *v24; // r3
  idBaseHealth *v25; // r3
  idPresentable *v26; // r3
  int v27; // r3
  idPresentable *v28; // r3
  int v29; // r3
  idPresentable *v30; // r3
  int v31; // r3
  idPresentable *v32; // r3
  int v33; // r3
  idBot *v34; // r11
  idPresentable *v35; // r3
  idPresentablePlayer *v36; // r3
  int v37; // r3
  idPresentable *v38; // r11
  int v39; // r29
  idPresentablePlayer *v40; // r3
  idPresentable *v41; // r3
  int v42; // r3
  unsigned __int64 index; // r10
  char v44; // r11
  idBot *v45; // r11
  unsigned __int64 v46; // r6
  const char *v47; // r7
  idPresentable *v48; // r3
  int v49; // r3
  idAlignedEntity *thirdPersonHands; // r3
  idAlignedEntity *thirdPersonLegs; // r3
  idSpringCamera *springCamera; // r3
  unsigned __int64 v53; // r6
  const char *v54; // r7
  idPresentable *v55; // r3
  int v56; // r3
  int FocusTracker; // r28
  const idSoundShader *v58; // r27
  int UCmdTracker1; // r29
  int v60; // r3
  idPresentable *v61; // r3
  int v62; // r3
  idPresentable *v63; // r11
  float v64; // r8
  float v65; // r7
  int v66; // r3
  int *v67; // r10
  _DWORD *v68; // r11
  int i; // ctr
  idEntity *Control; // r3
  idAI2 *v71; // r3
  idAI2 *v72; // r3
  idPLog **p_pLog; // r10
  int v74; // ctr
  idAI2 *p_z; // r11
  float y; // r5
  float x; // r7
  idEntity *v78; // r3
  idUtilityCamera *v79; // r3
  idUtilityCamera *v80; // r3
  double z; // fp3
  idEntity *v82; // r3
  idProp_WeaponStatic *v83; // r3
  idProp_WeaponStatic *v84; // r29
  const idMat3 *ViewAxis; // r3
  float v86; // r11
  idFocusTracker *v87; // r3
  idPresentable *v88; // r3
  int v89; // r3
  idPresentable *v90; // r3
  int v91; // r3
  idPresentable *v92; // r3
  int v93; // r3
  idPresentable *v94; // r3
  int v95; // r3
  idPresentable *v96; // r3
  int v97; // r3
  idPresentable *v98; // r3
  int v99; // r3
  const idSoundShader *v100; // r5
  idFocusTracker *v101; // r3
  idAI2 *FocusEntity; // r3
  idAI2 *v103; // r3
  idLinkList<idActor> *next; // r11
  idAI2 *owner; // r29
  idAI2 *v106; // r3
  idWeapon *EquippedWeapon; // r3
  __int64 v108; // r9
  double v109; // fp31
  idPhysics *v110; // r3
  float *v111; // r28
  idPhysics *v112; // r3
  float *v113; // r3
  double v114; // fp9
  double v115; // fp7
  double v116; // fp1
  idPresentable *v117; // r3
  float *v118; // r3
  idLinkList<idActor> *v119; // r11
  idAI2 *v120; // r11
  int v121; // r29
  unsigned __int64 v122; // r6
  const char *v123; // r7
  idPresentable *v124; // r29
  int v125; // r3
  idBot *v126; // r11
  idPresentable *v127; // r3
  int v128; // r3
  unsigned __int64 v129; // r6
  const char *v130; // r7
  idPresentable *v131; // r3
  idPresentableAI *v132; // r3
  int v133; // r3
  idBot *v134; // r11
  idPresentable *v135; // r3
  idPresentablePlayer *v136; // r3
  idPhysics *v137; // r3
  __int64 v138; // r10
  bool (__fastcall **v139)(idLobbyBackend360 *__hidden); // r8 OVERLAPPED
  float v140; // r5
  float v141; // r7
  __int128 v142; // r7 OVERLAPPED
  idPhysics *v143; // r3
  int v144; // r3
  idPLog **v145; // r10
  _DWORD *v146; // r11
  int j; // ctr
  idRenderWorld *v148; // r3
  idPhysics *v149; // r3
  int v150; // r3
  float v151; // r6
  float v152; // r5
  int (__fastcall *GetGameFrame)(struct idGameLocal *); // r4
  idPhysics *v154; // r3
  double v155; // fp31
  double v156; // fp30
  double v157; // fp29
  idPhysics *v158; // r3
  bool (__fastcall **v159)(idLobbyBackend360 *__hidden); // r8 OVERLAPPED
  __int128 v160; // r7 OVERLAPPED
  __int64 v161; // r10
  idPhysics *v162; // r3
  __int64 v163; // r8
  __int64 v164; // r6
  __int64 v165; // r10
  idPresentable *v166; // r3
  int v167; // r3
  int v168; // r7
  idPresentable *v169; // r3
  float v170; // r5
  float v171; // r4
  int v172; // r3
  __int128 v173; // r7 OVERLAPPED
  __int64 v174; // r10
  idPresentable *v175; // r3
  const idAngles *v176; // r4
  __int128 v177; // r7 OVERLAPPED
  __int64 v178; // r10
  idPresentable *v179; // r3
  const idAngles *v180; // r4
  double v181; // fp31
  double v182; // fp30
  double v183; // fp29
  idPresentable *v184; // r3
  int v185; // r3
  __int64 v186; // r8
  __int128 v187; // r6
  __int64 v188; // r10
  idPresentable *v189; // r3
  int v190; // r3
  double v191; // fp31
  double v192; // fp30
  double v193; // fp29
  idPresentable *v194; // r3
  int v195; // r3
  __int64 v196; // r8
  __int64 v197; // r10
  idPresentable *v198; // r3
  int v199; // r3
  double v200; // fp31
  double v201; // fp30
  double v202; // fp29
  int v203; // r3
  idPresentable *v204; // r3
  int v205; // r3
  __int64 v206; // r10
  float v207; // r8 OVERLAPPED
  __int128 v208; // r7 OVERLAPPED
  idPresentable *v209; // r3
  int v210; // r3
  __int64 v211; // r10
  __int64 v212; // r8
  int v213; // [sp+8h] [-2D8h]
  int v214; // [sp+Ch] [-2D4h]
  int v215; // [sp+10h] [-2D0h]
  int v216; // [sp+14h] [-2CCh]
  int v217; // [sp+18h] [-2C8h]
  int v218; // [sp+1Ch] [-2C4h]
  double v219; // [sp+20h] [-2C0h]
  double v220; // [sp+20h] [-2C0h]
  double v221; // [sp+20h] [-2C0h]
  double v222; // [sp+28h] [-2B8h]
  double v223; // [sp+28h] [-2B8h]
  double v224; // [sp+28h] [-2B8h]
  double v225; // [sp+30h] [-2B0h]
  double v226; // [sp+30h] [-2B0h]
  double v227; // [sp+30h] [-2B0h]
  idMat3 v228; // [sp+80h] [-260h] BYREF
  int v229; // [sp+ACh] [-234h] BYREF
  idMat3 v230; // [sp+B0h] [-230h] BYREF
  idPLogScope v231; // [sp+D8h] [-208h] BYREF
  idMat3 v232; // [sp+E0h] [-200h] BYREF
  idPLogScope v233; // [sp+108h] [-1D8h] BYREF
  idPLogScope v234; // [sp+110h] [-1D0h] BYREF
  idPLogScope v235; // [sp+118h] [-1C8h] BYREF
  idPLogScope v236; // [sp+120h] [-1C0h] BYREF
  idPLogScope v237; // [sp+128h] [-1B8h] BYREF
  float v238[4]; // [sp+130h] [-1B0h] BYREF
  idVec3 v239; // [sp+140h] [-1A0h] BYREF
  idVec3 v240; // [sp+150h] [-190h] BYREF
  float v241[4]; // [sp+160h] [-180h] BYREF
  float v242[4]; // [sp+170h] [-170h] BYREF
  idVec3 v243; // [sp+180h] [-160h] BYREF
  idVec3 v244; // [sp+190h] [-150h] BYREF
  float v245[46]; // [sp+1A0h] [-140h] BYREF

  RD_EventBegin(name: "idPlayer::Think");
  LODWORD(v2) = "idPlayer::Think";
  HIDWORD(v2) = 514;
  idPLogScope::idPLogScope(this: &v237, pl: &pLog, gMask: v2, label: v3);
  RD_EventBegin(name: "idPlayer_Think_Misc1");
  LODWORD(v4) = "idPlayer_Think_Misc1";
  HIDWORD(v4) = 514;
  idPLogScope::idPLogScope(this: &v231, pl: &pLog, gMask: v4, label: v5);
  if ( common->IsMultiplayer(this: common) )
  {
    if ( g_playerShowStats.valueInteger == this->entityNumber )
    {
      if ( idGameLocal::GetChallengeMode(this: gameLocal) == CHALLENGE_MODE_COOP )
        idPlayer::DisplayStatsMP_Coop(this);
      else
        idPlayer::DisplayStatsMP_VDM(this);
    }
  }
  else if ( g_playerShowStats.valueInteger > 0 )
  {
    idPlayer::DisplayStats(this);
  }
  rageMetrics = clientGame->rageMetrics;
  LODWORD(v228.mat[1].z) = (int)idGameTimeManager::GetRealMsPerFrame(
                                  this: &clientGame->gameTimeManager,
                                  type: GAMETIME_NORMAL);
  idRageMetrics::UpdateTime(this: rageMetrics, player: (idVehicle *)this, ms: SLODWORD(v228.mat[1].z));
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  LODWORD(v8) = GameMs - idGameTimeManager::GetPreviousGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  *(_QWORD *)&v228.mat[1].y = v8;
  idEngagementTracker::Update(this: &this->engagementTracker, elapsedTime: (float)v8);
  presentable = this->presentable;
  if ( presentable != nullptr )
    v10 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v10 = nullptr;
  PlayerGameTime = idPresentablePlayer::GetPlayerGameTime(this: v10);
  idPlayerTimeLock::idPlayerTimeLock(this: (idPlayerTimeLock *)&v228.mat[1].y, newTime: PlayerGameTime);
  idPlayerTimeLock::~idPlayerTimeLock(this: (idPlayerTimeLock *)&v228.mat[1].y);
  valueFloat = pm_normalviewheight.valueFloat;
  this->actorConstants.perception.eyeOffset.x = 0.0;
  this->actorConstants.perception.eyeOffset.y = 0.0;
  LODWORD(v228.mat[1].y) = &this->actorConstants.perception.crouchedEyeOffset;
  this->actorConstants.perception.eyeOffset.z = valueFloat;
  v13 = sDebugHud_x0_0;
  this->actorConstants.perception.crouchedEyeOffset.z = pm_crouchviewheight.valueFloat;
  v14 = sDebugHud_y0_0;
  this->actorConstants.perception.crouchedEyeOffset.x = 0.0;
  this->actorConstants.perception.crouchedEyeOffset.y = 0.0;
  botController = this->botController;
  this->debugHud_x = v13;
  this->debugHud_y = v14;
  if ( botController == nullptr || botController->isControllingAFKPlayer )
  {
    v16 = this->presentable;
    if ( v16 != nullptr )
      v17 = (int)v16->GetPlayerInterface_2(this: v16);
    else
      v17 = 0;
    (*(void (__fastcall **)(int))(*(_DWORD *)v17 + 380))(a1: v17);
    v18 = this->presentable;
    if ( v18 != nullptr )
      v19 = (int)v18->GetPlayerInterface_2(this: v18);
    else
      v19 = 0;
    idPlayerHud::Think(this: (idPlayerHud *)(v19 + 35096));
    idAchievementManager::Update(this: &this->achievementManager);
    idJobManager::Think(this: &this->jobManager);
    idGameLayerManager::Think(this: &this->gameLayerManager);
  }
  if ( g_stopTime.valueInteger == 0 || g_runFrames.valueInteger > 0 )
  {
    if ( pm_trackPlayerPos.valueInteger > 0 )
    {
      if ( (_S18_21 & 1) == 0 )
      {
        _S18_21 |= 1u;
        lastSpherePos = vec3_origin;
      }
      Physics = idEntity::GetPhysics(this);
      v21 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      if ( (float)((float)((float)(lastSpherePos.z - v21[2]) * (float)(lastSpherePos.z - v21[2]))
                 + (float)((float)((float)(lastSpherePos.x - *v21) * (float)(lastSpherePos.x - *v21))
                         + (float)((float)(lastSpherePos.y - v21[1]) * (float)(lastSpherePos.y - v21[1])))) > 62500.0 )
      {
        v22 = idEntity::GetPhysics(this);
        v23 = (float *)v22->GetOrigin(this: v22, a2: 0);
        v242[0] = *v23;
        v242[1] = v23[1];
        v242[2] = v23[2];
        v242[3] = 25.0;
        clientGame->renderWorld->DebugSphere(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&idColor::colorWhite,
          a3: (const idSphere *)v242,
          a4: 12,
          a5: 1000 * pm_trackPlayerPos.valueInteger,
          a6: false);
        v24 = idEntity::GetPhysics(this);
        lastSpherePos = *v24->GetOrigin(this: v24, a2: 0);
      }
    }
    idPlayer::UpdateBonuses(this);
    v25 = this->GetHealthComponent_2(this);
    v25->Update_Impl(this: v25);
    idGameLocal::TouchStreamAreas(this: gameLocal, activator: this);
    idPlayer::CheckForStandingOnAI(this);
  }
  v26 = this->presentable;
  if ( v26 != nullptr )
    v27 = (int)v26->GetPlayerInterface_2(this: v26);
  else
    v27 = 0;
  if ( idHands::GetState(this: (idHands *)(v27 + 37616), animWeb: (const idAnimWebHands *)(v27 + 39208)) != 0 )
  {
    if ( this->IsDrivingVehicle(this)
      || ((v28 = this->presentable) == nullptr ? (v29 = 0) : (v29 = (int)v28->GetPlayerInterface_2(this: v28)),
          (*(_BYTE *)(v29 + 47032) & 4) != 0) )
    {
      v30 = this->presentable;
      if ( v30 != nullptr )
        v31 = (int)v30->GetPlayerInterface_2(this: v30);
      else
        v31 = 0;
      idHands::RestHandsToIdle(this: (idHands *)(v31 + 37616));
    }
  }
  v32 = this->presentable;
  if ( v32 != nullptr )
    v33 = (int)v32->GetPlayerInterface_2(this: v32);
  else
    v33 = 0;
  if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v33 + 300))(a1: v33) != 0 )
  {
    v34 = this->botController;
    if ( v34 == nullptr || v34->isControllingAFKPlayer )
    {
      v35 = this->presentable;
      if ( v35 != nullptr )
        v36 = v35->GetPlayerInterface_2(this: v35);
      else
        v36 = nullptr;
      idPresentablePlayer::UpdateDamageFeedback(this: v36);
    }
  }
  v37 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v38 = this->presentable;
  v39 = v37;
  if ( v38 != nullptr )
    v40 = v38->GetPlayerInterface_2(this: this->presentable);
  else
    v40 = nullptr;
  idPresentablePlayer::UpdateSubtitles(this: v40, curTime: v39);
  if ( (this->thinkFlags & 1) == 0 )
  {
    v41 = this->presentable;
    if ( v41 != nullptr )
      v42 = (int)v41->GetPlayerInterface_2(this: v41);
    else
      v42 = 0;
    idHands::Update(this: (idHands *)(v42 + 37616));
    idPlayer::UpdateSprint(this);
    idPLogScope::End(this: &v231, totalTicks: nullptr);
    idPLogScope::~idPLogScope(this: &v231);
    RD_EventEnd();
    idPLogScope::~idPLogScope(this: &v237);
    goto LABEL_263;
  }
  index = this->lootQuery.index;
  LODWORD(v228.mat[1].y) = &this->lootQuery;
  if ( (idClipModel *)index < *(idClipModel **)((char *)&clientGame->clip.temporaryClipModel + (HIDWORD(index) | 0x5A0))
    || (v44 = 1, (unsigned int)index > LODWORD(clientGame->clip.gatherQueryLastSubmittedIndex)) )
  {
    v44 = 0;
  }
  if ( v44 != 0 )
    idPlayer::ResolveLoot(this);
  idAnimatedEntity::UpdateFrameCommands(this);
  v45 = this->botController;
  if ( v45 == nullptr || v45->isControllingAFKPlayer )
    idJobTimerManager::UpdateJobTimers(this: &this->jobTimerManager, player: this);
  idPLogScope::End(this: &v231, totalTicks: nullptr);
  RD_EventBegin(name: "idPlayer_Think_Move");
  LODWORD(v46) = "idPlayer_Think_Move";
  HIDWORD(v46) = 514;
  idPLogScope::idPLogScope(this: &v233, pl: &pLog, gMask: v46, label: v47);
  v48 = this->presentable;
  if ( v48 != nullptr )
    v49 = (int)v48->GetPlayerInterface_2(this: v48);
  else
    v49 = 0;
  if ( (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v49 + 300))(a1: v49) != 0 )
  {
    idPlayer::ProcessInput(this, doMovement: true);
    idPlayer::PlayerBehavior_Handle(this);
    thirdPersonHands = this->thirdPersonHands;
    if ( thirdPersonHands != nullptr )
      idAlignedEntity::Update(this: thirdPersonHands);
    thirdPersonLegs = this->thirdPersonLegs;
    if ( thirdPersonLegs != nullptr )
      idAlignedEntity::Update(this: thirdPersonLegs);
    if ( (p_setSpringCameraK.flags & 0x20000) != 0 )
    {
      p_setSpringCameraK.flags &= ~0x20000u;
      springCamera = this->springCamera;
      if ( p_setSpringCameraK.valueFloat <= 0.0 )
        idSpringCamera::InitDefaultSprings(this: springCamera);
      else
        idSpringCamera::InitSprings(this: springCamera, k: p_setSpringCameraK.valueFloat);
    }
  }
  else
  {
    idPlayer::Move(this);
    idPlayer::RunPhysics_RemoteClientCorrection(this);
  }
  idPLogScope::End(this: &v233, totalTicks: nullptr);
  RD_EventBegin(name: "idPlayer_Think_Misc2");
  LODWORD(v53) = "idPlayer_Think_Misc2";
  HIDWORD(v53) = 514;
  idPLogScope::idPLogScope(this: &v234, pl: &pLog, gMask: v53, label: v54);
  if ( g_stopTime.valueInteger == 0 || g_runFrames.valueInteger > 0 )
  {
    v55 = this->presentable;
    if ( v55 != nullptr )
      v56 = (int)v55->GetPlayerInterface_2(this: v55);
    else
      v56 = 0;
    if ( (*(_BYTE *)(v56 + 47032) & 0x20) == 0
      && !this->playerHealth.IsDead_Impl(this: &this->playerHealth)
      && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: (unsigned __int8 *)this) == 0 )
    {
      idEntity::TouchTriggers(this);
    }
    FocusTracker = idPlayer::GetFocusTracker(this);
    v58 = *(const idSoundShader **)(FocusTracker + 464);
    UCmdTracker1 = idPlayer::GetUCmdTracker1(this);
    v60 = idPlayer::GetFocusTracker(this);
    memcpy(Dst: (void *)(v60 + 12), Src: (const void *)(UCmdTracker1 + 68), Size: 0x3Cu);
    v61 = this->presentable;
    if ( v61 != nullptr )
      v62 = (int)v61->GetPlayerInterface_2(this: v61);
    else
      v62 = 0;
    v63 = this->presentable;
    v64 = *(float *)(v62 + 46536);
    v65 = *(float *)(v62 + 46540);
    v228.mat[2].x = *(float *)(v62 + 46532);
    v228.mat[2].y = v64;
    v228.mat[2].z = v65;
    if ( v63 != nullptr )
      v66 = (int)v63->GetPlayerInterface_2(this: v63);
    else
      v66 = 0;
    v67 = &v229;
    v68 = (_DWORD *)(v66 + 46540);
    for ( i = 9; i != 0; --i )
      *++v67 = *++v68;
    if ( idPlayer::GetControl(this) != nullptr )
    {
      Control = idPlayer::GetControl(this);
      if ( (unsigned __int8)idClass::IsType(this: Control, superclass: &idAI2::Type) != 0 )
      {
        v71 = (idAI2 *)idPlayer::GetControl(this);
        v72 = idAI2::CastTo(c: v71);
        p_pLog = &v231.pLog;
        v74 = 9;
        p_z = (idAI2 *)&v72->aiVolatile.playerControl.camera.camPos.z;
        y = v72->aiVolatile.playerControl.camera.camPos.y;
        x = v72->aiVolatile.playerControl.camera.camPos.x;
        v228.mat[0].z = v72->aiVolatile.playerControl.camera.camPos.z;
        v228.mat[0].y = y;
        v228.mat[0].x = x;
        v228.mat[2].x = x;
        v228.mat[2].y = y;
        v228.mat[2].z = v228.mat[0].z;
        do
        {
          p_z = (idAI2 *)((char *)p_z + 4);
          *++p_pLog = (idPLog *)p_z->__vftable;
          --v74;
        }
        while ( v74 != 0 );
        v230.mat[0].x = v232.mat[0].x;
        v230.mat[0].y = v232.mat[0].y;
        v230.mat[0].z = v232.mat[0].z;
        v230.mat[1].x = v232.mat[1].x;
        v230.mat[1].y = v232.mat[1].y;
        v230.mat[1].z = v232.mat[1].z;
        v230.mat[2].x = v232.mat[2].x;
        v230.mat[2].y = v232.mat[2].y;
        v230.mat[2].z = v232.mat[2].z;
        goto LABEL_112;
      }
    }
    if ( idPlayer::GetControl(this) != nullptr
      && (v78 = idPlayer::GetControl(this),
          (unsigned __int8)idClass::IsType(this: v78, superclass: &idUtilityCamera::Type) != 0) )
    {
      v79 = (idUtilityCamera *)idPlayer::GetControl(this);
      v80 = idUtilityCamera::CastTo(c: v79);
      v228.mat[2].x = v80->cachedViewOrg.x;
      v228.mat[2].y = v80->cachedViewOrg.y;
      v228.mat[2].z = v80->cachedViewOrg.z;
      LODWORD(v228.mat[1].y) = &v80->cachedViewAxis.mat[2];
      v230.mat[0] = v80->cachedViewAxis.mat[0];
      v230.mat[1] = v80->cachedViewAxis.mat[1];
      v230.mat[2].x = v80->cachedViewAxis.mat[2].x;
      v230.mat[2].y = v80->cachedViewAxis.mat[2].y;
      z = v80->cachedViewAxis.mat[2].z;
    }
    else
    {
      if ( idPlayer::GetControl(this) != nullptr )
      {
        v82 = idPlayer::GetControl(this);
        if ( (unsigned __int8)idClass::IsType(this: v82, superclass: &idProp_WeaponStatic::Type) != 0 )
        {
          v83 = (idProp_WeaponStatic *)idPlayer::GetControl(this);
          v84 = idProp_WeaponStatic::CastTo(c: v83);
          idProp_WeaponStatic::GetViewOrg(this: v84, pos: &v228.mat[2], player: this);
          ViewAxis = idProp_WeaponStatic::GetViewAxis(this: v84);
          v230.mat[0].x = ViewAxis->mat[0].x;
          v230.mat[0].y = ViewAxis->mat[0].y;
          LODWORD(v228.mat[1].y) = &ViewAxis->mat[1];
          v230.mat[0].z = ViewAxis->mat[0].z;
          LODWORD(v228.mat[1].y) = &ViewAxis->mat[2];
          v230.mat[1] = ViewAxis->mat[1];
          v230.mat[2] = ViewAxis->mat[2];
          goto LABEL_112;
        }
      }
      LODWORD(v228.mat[1].y) = this->springCamera;
      v86 = v228.mat[1].y;
      if ( LODWORD(v228.mat[1].y) == 0 || *(_DWORD *)(LODWORD(v228.mat[1].y) + 1336) == 0 )
        goto LABEL_112;
      v228.mat[2].x = *(float *)(LODWORD(v228.mat[1].y) + 1344);
      v228.mat[2].y = *(float *)(LODWORD(v228.mat[1].y) + 1348);
      LODWORD(v228.mat[1].y) += 1356;
      v228.mat[2].z = *(float *)(LODWORD(v86) + 1352);
      LODWORD(v228.mat[1].y) = LODWORD(v86) + 1368;
      v230.mat[0].x = *(float *)(LODWORD(v86) + 1356);
      LODWORD(v228.mat[1].y) = LODWORD(v86) + 1344;
      v230.mat[0].y = *(float *)(LODWORD(v86) + 1360);
      LODWORD(v228.mat[1].y) = LODWORD(v86) + 1380;
      v230.mat[0].z = *(float *)(LODWORD(v86) + 1364);
      v230.mat[1] = *(idVec3 *)(LODWORD(v86) + 1368);
      v230.mat[2].x = *(float *)(LODWORD(v86) + 1380);
      v230.mat[2].y = *(float *)(LODWORD(v86) + 1384);
      z = *(float *)(LODWORD(v86) + 1388);
    }
    v230.mat[2].z = z;
LABEL_112:
    v87 = (idFocusTracker *)idPlayer::GetFocusTracker(this);
    idFocusTracker::UpdateFocus(
      this: v87,
      owner: this,
      viewPos: &v228.mat[2],
      viewAxis: &v230,
      passEntityOverride: nullptr);
    if ( (unsigned __int8)idPlayer::IsOnLadder(this) != 0
      || idPlayer::PlayerBehavior_ContextualShimmy_IsInShimmy(this)
      || idPlayer::PlayerBehavior_WallClimb_IsInWallClimb(this)
      || ((v88 = this->presentable) == nullptr ? (v89 = 0) : (v89 = (int)v88->GetPlayerInterface_2(this: v88)),
          (*(_BYTE *)(v89 + 47032) & 0x20) != 0
       || ((v90 = this->presentable) == nullptr ? (v91 = 0) : (v91 = (int)v90->GetPlayerInterface_2(this: v90)),
           *(_DWORD *)(v91 + 40596) != 0)) )
    {
      v94 = this->presentable;
      if ( v94 != nullptr )
        v95 = (int)v94->GetPlayerInterface_2(this: v94);
      else
        v95 = 0;
      if ( *(_BYTE *)(v95 + 48520) != 0
        || ((v96 = this->presentable) == nullptr ? (v97 = 0) : (v97 = (int)v96->GetPlayerInterface_2(this: v96)),
            *(_BYTE *)(v97 + 48521) != 0) )
      {
        v98 = this->presentable;
        if ( v98 != nullptr )
          v99 = (int)v98->GetPlayerInterface_2(this: v98);
        else
          v99 = 0;
        *(_BYTE *)(v99 + 48520) = 0;
        *(_BYTE *)(v99 + 48521) = 0;
      }
    }
    else
    {
      v92 = this->presentable;
      if ( v92 != nullptr )
        v93 = (int)v92->GetPlayerInterface_2(this: v92);
      else
        v93 = 0;
      idEnvironmentAnalyzer::Update(
        this: (idEnvironmentAnalyzer *)(v93 + 47840),
        owner: this,
        viewPos: &v228.mat[2],
        viewAxis: &v230);
    }
    v100 = *(const idSoundShader **)(FocusTracker + 464);
    if ( v58 != v100 && v100 != nullptr )
      idEntity::StartSoundShader(
        this,
        channel: SND_CHANNEL_ANY,
        shader: v100,
        soundShaderFlags: (soundShaderFlags_t)0,
        peerMask: 0xFFu);
    idPlayer::UpdateGuiInteraction(this);
    idPlayer::UpdateApplyDamageScale(this);
    idPlayer::UpdateAuthorityForce(this);
    idPlayer::UpdateBulletTime(this);
    idPlayer::UpdateInvulnerability(this);
    if ( this->currentPlayerTension >= PLAYER_TENSION_HOSTILE )
      goto LABEL_170;
    v101 = (idFocusTracker *)idPlayer::GetFocusTracker(this);
    FocusEntity = (idAI2 *)idFocusTracker::GetFocusEntity(this: v101);
    v103 = idAI2::CastTo(c: FocusEntity);
    if ( v103 == nullptr || v103->aiEditable.interactions.playerShouldLowerWeapon )
    {
      next = gameLocal->actorEntities.next;
      if ( next == nullptr || next == gameLocal->actorEntities.head || (owner = (idAI2 *)next->owner) == nullptr )
      {
LABEL_170:
        if ( this->currentPlayerTension > PLAYER_TENSION_NONE )
        {
          v121 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
          if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->lastSetTensionTime >= v121 )
          {
            --this->currentPlayerTension;
            this->lastSetTensionTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          }
        }
        goto LABEL_173;
      }
      while ( 1 )
      {
        if ( owner != (idAI2 *)this && !owner->IsDead(this: owner) )
        {
          v106 = idAI2::CastTo(c: owner);
          if ( v106 != nullptr && !v106->aiEditable.interactions.playerShouldLowerWeapon )
          {
            EquippedWeapon = idActor::GetEquippedWeapon(this, slot: EQUIP_RIGHT_HAND);
            if ( EquippedWeapon != nullptr
              && (LODWORD(v108) = idWeapon::MaxRange(
                                    this: EquippedWeapon,
                                    secondaryAmmo: (_cntlzw(EquippedWeapon->weaponState - 1) & 0x20) != 0),
                  *(_QWORD *)&v228.mat[1].y = v108,
                  (v109 = (float)v108) >= 512.0) )
            {
              if ( v109 > 1280.0 )
                v109 = 1280.0;
            }
            else
            {
              v109 = 512.0;
            }
            v110 = idEntity::GetPhysics(this);
            v111 = (float *)v110->GetOrigin(this: v110, a2: 0);
            v112 = idEntity::GetPhysics(this: owner);
            v113 = (float *)v112->GetOrigin(this: v112, a2: 0);
            v114 = (float)(v113[2] - v111[2]);
            v115 = (float)(v113[1] - v111[1]);
            v228.mat[0].x = *v113 - *v111;
            v228.mat[0].z = v114;
            v228.mat[0].y = v115;
            v116 = idVec3::NormalizeFast(this: v228.mat);
            if ( v116 <= v109 )
            {
              if ( v116 <= (float)((float)v109 * (float)0.5) )
                break;
              v117 = this->presentable;
              v118 = v117 != nullptr ? (float *)v117->GetPlayerInterface_2(this: v117) : nullptr;
              if ( (float)((float)(v228.mat[0].x * v118[11636])
                         + (float)((float)(v118[11638] * v228.mat[0].z) + (float)(v118[11637] * v228.mat[0].y))) >= 0.75 )
                break;
            }
          }
        }
        v119 = owner->actorNode.next;
        if ( v119 == nullptr || v119 == owner->actorNode.head )
          v120 = nullptr;
        else
          v120 = (idAI2 *)v119->owner;
        owner = v120;
        if ( v120 == nullptr )
          goto LABEL_170;
      }
    }
    idPlayer::SetTension(this, tension: PLAYER_TENSION_HOSTILE);
    goto LABEL_170;
  }
LABEL_173:
  idPLogScope::End(this: &v234, totalTicks: nullptr);
  RD_EventBegin(name: "idPlayer_Think_Misc3");
  LODWORD(v122) = "idPlayer_Think_Misc3";
  HIDWORD(v122) = 514;
  idPLogScope::idPLogScope(this: &v236, pl: &pLog, gMask: v122, label: v123);
  idPlayer::UpdateWater(this);
  v124 = this->presentable;
  if ( v124 == nullptr )
  {
    idEntity::InitPresentableInternal(this);
    v124 = this->presentable;
  }
  v125 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v124->ServerThink(this: v124, a2: v125);
  v126 = this->botController;
  if ( v126 == nullptr || v126->isControllingAFKPlayer )
  {
    v127 = this->presentable;
    if ( v127 != nullptr )
      v128 = (int)v127->GetPlayerInterface_2(this: v127);
    else
      v128 = 0;
    idHands::Draw(this: (idHands *)(v128 + 37616));
  }
  if ( g_stopTime.valueInteger == 0 || g_runFrames.valueInteger > 0 )
  {
    if ( pm_skipAnimation.valueInteger == 0 )
      idAnimatedEntity::UpdateAnimation(this, forceNonDeferredBlend: false);
    idAnimatedEntity::UpdateDamageEffects(this);
  }
  idPLogScope::End(this: &v236, totalTicks: nullptr);
  RD_EventBegin(name: "idPlayer_Think_Misc4");
  LODWORD(v129) = "idPlayer_Think_Misc4";
  HIDWORD(v129) = 514;
  idPLogScope::idPLogScope(this: &v235, pl: &pLog, gMask: v129, label: v130);
  this->UpdateFX(this);
  v131 = this->presentable;
  if ( v131 != nullptr )
    v132 = (idPresentableAI *)v131->GetPlayerInterface_2(this: v131);
  else
    v132 = nullptr;
  idPresentableAI::UpdateInfluenceTrail(this: v132);
  idPlayer::UpdateDroppableList(this);
  v133 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->auditor.CollectData(this: &this->auditor, a2: this, a3: v133);
  if ( this->botController == nullptr )
    idPlayer::UpdateCoverCheck(this);
  v134 = this->botController;
  if ( v134 == nullptr || v134->isControllingAFKPlayer )
    idPlayer::UpdateWeaponZoom(this);
  v135 = this->presentable;
  if ( v135 != nullptr )
    v136 = v135->GetPlayerInterface_2(this: v135);
  else
    v136 = nullptr;
  idPresentablePlayer::UpdateOutline(this: v136);
  if ( common->IsMultiplayer(this: common) )
    idPlayer::UpdateUsable(this);
  idPlayer::UpdateBotComponent(this);
  idPLogScope::End(this: &v235, totalTicks: nullptr);
  if ( g_drawPlayerPos.valueInteger != 0 )
  {
    v137 = idEntity::GetPhysics(this);
    HIDWORD(v138) = v137->GetOrigin(this: v137, a2: 0);
    v139 = &off_82350000;
    v140 = *(float *)HIDWORD(v138);
    v141 = *(float *)(HIDWORD(v138) + 8);
    v228.mat[0].y = *(float *)(HIDWORD(v138) + 4);
    v228.mat[0].x = v140;
    v228.mat[0].z = v141;
    v219 = v140;
    v222 = v228.mat[0].y;
    DWORD1(v142) = HIDWORD(v222);
    *((double *)&v142 + 1) = v141;
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)HIDWORD(v219),
      a3: *(__int64 *)((char *)&v142 + 4),
      a4: *(__int64 *)&v139,
      a5: v138,
      a6: v213,
      a7: v214,
      a8: v215,
      a9: v216,
      a10: v217,
      a11: v218);
    if ( g_drawPlayerPos.valueInteger > 1 )
    {
      v143 = idEntity::GetPhysics(this);
      v144 = (int)v143->GetAxis(this: v143, a2: 0);
      v145 = &v231.pLog;
      v146 = (_DWORD *)(v144 - 4);
      for ( j = 9; j != 0; --j )
        *++v145 = (idPLog *)*++v146;
      v148 = gameLocal->GetRenderWorld(this: gameLocal);
      v148->DebugAxis_2(this: v148, a2: v228.mat, a3: &v232, a4: 0, a5: false);
    }
  }
  if ( g_tracePlayerPos.valueInteger != 0 )
  {
    v149 = idEntity::GetPhysics(this);
    v150 = (int)v149->GetOrigin(this: v149, a2: 0);
    v151 = *(float *)(v150 + 4);
    v152 = *(float *)(v150 + 8);
    GetGameFrame = gameLocal->GetGameFrame;
    v228.mat[0].x = *(float *)v150;
    v228.mat[0].y = v151;
    v228.mat[0].z = v152;
    GetGameFrame(this: gameLocal);
    idLib::Printf(
      fmt: "(%d)Player Pos = (%0.2f,%0.2f,%0.2f)\n",
      (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(v228.mat[0].x)),
      v228.mat[0].x,
      v228.mat[0].y,
      v228.mat[0].z);
  }
  if ( g_tracePlayerVel.valueInteger != 0 )
  {
    v154 = idEntity::GetPhysics(this);
    v154->GetLinearVelocity(this: (idPhysics *)&v228, result: (idVec3 *)v154, a3: 0);
    v155 = v228.mat[0].z;
    v156 = v228.mat[0].y;
    v157 = v228.mat[0].x;
    gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "(%d)Player Vel = (%0.2f,%0.2f,%0.2f)\n", HIDWORD(v157), v157, v156, v155);
  }
  if ( g_drawPlayerVel.valueInteger != 0 )
  {
    v158 = idEntity::GetPhysics(this);
    v158->GetLinearVelocity(this: (idPhysics *)&v228, result: (idVec3 *)v158, a3: 0);
    v159 = &off_82350000;
    v223 = v228.mat[0].y;
    DWORD1(v160) = HIDWORD(v223);
    *((double *)&v160 + 1) = v228.mat[0].z;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Player Vel = (%0.2f,%0.2f,%0.2f)",
      a3: *(__int64 *)((char *)&v160 + 4),
      a4: *(__int64 *)&v159,
      a5: v161,
      a6: v213,
      a7: v214,
      a8: v215,
      a9: v216,
      a10: v217,
      a11: v218);
  }
  if ( g_drawPlayerSpeed.valueInteger != 0 )
  {
    v162 = idEntity::GetPhysics(this);
    v162->GetLinearVelocity(this: (idPhysics *)v238, result: (idVec3 *)v162, a3: 0);
    LODWORD(v163) = &off_82350000;
    v220 = __fsqrts((float)((float)(v238[0] * v238[0]) + (float)((float)(v238[1] * v238[1]) + (float)(v238[2] * v238[2]))));
    HIDWORD(v164) = LODWORD(v220);
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)HIDWORD(v220),
      a3: v164,
      a4: v163,
      a5: v165,
      a6: v213,
      a7: v214,
      a8: v215,
      a9: v216,
      a10: v217,
      a11: v218);
  }
  if ( g_drawPlayerGround.valueInteger != 0 )
  {
    v166 = this->presentable;
    if ( v166 != nullptr )
      v167 = (int)v166->GetPlayerInterface_2(this: v166);
    else
      v167 = 0;
    v168 = (*(int (__fastcall **)(int))(*(_DWORD *)(v167 + 36264) + 104))(a1: v167 + 36264);
    v170 = *(float *)(v168 + 4);
    v171 = *(float *)(v168 + 8);
    v169 = this->presentable;
    v228.mat[0].x = *(float *)v168;
    v228.mat[0].y = v170;
    v228.mat[0].z = v171;
    if ( v169 != nullptr )
      v172 = (int)v169->GetPlayerInterface_2(this: v169);
    else
      v172 = 0;
    v241[1] = v228.mat[0].y * (float)2000.0;
    v241[2] = v228.mat[0].z * (float)2000.0;
    v241[0] = v228.mat[0].x * (float)2000.0;
    (*(void (__fastcall **)(int, float *, float *, _DWORD))(*(_DWORD *)(v172 + 36264) + 184))(
      a1: v172 + 36264,
      a2: v245,
      a3: v241,
      a4: 0);
    *((double *)&v173 + 1) = v245[16];
    *(double *)&v173 = v245[14];
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v245[14])),
      a3: *(__int64 *)((char *)&v173 + 4),
      a4: *(__int64 *)((char *)&v173 - 4),
      a5: v174,
      a6: v213,
      a7: v214,
      a8: v215,
      a9: v216,
      a10: v217,
      a11: v218);
  }
  if ( g_drawPlayerAngles.valueInteger != 0 )
  {
    v175 = this->presentable;
    if ( v175 != nullptr )
      v176 = (const idAngles *)v175->GetPlayerInterface_2(this: v175);
    else
      v176 = nullptr;
    idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)&v228, result: v176, includeWeaponKick: true);
    v221 = v228.mat[0].x;
    DWORD1(v177) = LODWORD(v221);
    *((double *)&v177 + 1) = v228.mat[0].z;
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Player Angles (p,y,r) = (%0.2f,%0.2f,%0.2f)",
      a3: *(__int64 *)((char *)&v177 + 4),
      a4: *(__int64 *)((char *)&v177 - 4),
      a5: v178,
      a6: v213,
      a7: v214,
      a8: v215,
      a9: v216,
      a10: v217,
      a11: v218);
  }
  if ( g_tracePlayerAngles.valueInteger != 0 )
  {
    v179 = this->presentable;
    if ( v179 != nullptr )
      v180 = (const idAngles *)v179->GetPlayerInterface_2(this: v179);
    else
      v180 = nullptr;
    idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)&v228, result: v180, includeWeaponKick: true);
    v181 = v228.mat[0].z;
    v182 = v228.mat[0].y;
    v183 = v228.mat[0].x;
    gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "(%d)Player Angles = (%0.2f,%0.2f,%0.2f)\n", HIDWORD(v183), v183, v182, v181);
  }
  if ( g_drawPlayerViewPos.valueInteger != 0 )
  {
    v184 = this->presentable;
    if ( v184 != nullptr )
      v185 = (int)v184->GetPlayerInterface_2(this: v184);
    else
      v185 = 0;
    idView::GetViewPos(this: (idView *)(v185 + 16224), origin: &v240, axis: &v232);
    v225 = v240.z;
    HIDWORD(v186) = LODWORD(v225);
    v224 = v240.y;
    LODWORD(v187) = LODWORD(v224);
    *(double *)((char *)&v187 + 4) = v240.x;
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(v240.x)),
      a3: v187,
      a4: v186,
      a5: v188,
      a6: v213,
      a7: v214,
      a8: v215,
      a9: v216,
      a10: v217,
      a11: v218);
  }
  if ( g_tracePlayerViewPos.valueInteger != 0 )
  {
    v189 = this->presentable;
    if ( v189 != nullptr )
      v190 = (int)v189->GetPlayerInterface_2(this: v189);
    else
      v190 = 0;
    idView::GetViewPos(this: (idView *)(v190 + 16224), origin: &v239, axis: &v232);
    v191 = v239.z;
    v192 = v239.y;
    v193 = v239.x;
    gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "(%d)Player View Pos = ( %0.2f, %0.2f, %0.2f )\n", HIDWORD(v193), v193, v192, v191);
  }
  if ( g_drawPlayerViewAngles.valueInteger != 0 )
  {
    v194 = this->presentable;
    if ( v194 != nullptr )
      v195 = (int)v194->GetPlayerInterface_2(this: v194);
    else
      v195 = 0;
    idView::GetViewPos(this: (idView *)(v195 + 16224), origin: &v243, axis: &v232);
    idMat3::ToAngles(this: &v228, result: (idAngles *)&v232);
    v226 = v228.mat[0].z;
    HIDWORD(v196) = LODWORD(v226);
    idPlayer::debugHUDPrintf(
      this,
      fmt: "Player View Angles = (%0.2f,%0.2f,%0.2f)",
      a3: COERCE__INT64(v228.mat[0].y),
      a4: v196,
      a5: v197,
      a6: v213,
      a7: v214,
      a8: v215,
      a9: v216,
      a10: v217,
      a11: v218);
  }
  if ( g_tracePlayerViewAngles.valueInteger != 0 )
  {
    v198 = this->presentable;
    if ( v198 != nullptr )
      v199 = (int)v198->GetPlayerInterface_2(this: v198);
    else
      v199 = 0;
    idView::GetViewPos(this: (idView *)(v199 + 16224), origin: &v244, axis: &v232);
    idMat3::ToAngles(this: &v228, result: (idAngles *)&v232);
    v200 = v228.mat[0].z;
    v201 = v228.mat[0].y;
    v202 = v228.mat[0].x;
    v203 = gameLocal->GetGameFrame(this: gameLocal);
    idLib::Printf(fmt: "(%d)Player View Angles = (%0.2f,%0.2f,%0.2f)\n", v203, v202, v201, v200);
  }
  if ( g_drawUCmdTracker1ViewAngles.valueInteger != 0 )
  {
    v204 = this->presentable;
    if ( v204 != nullptr )
      v205 = (int)v204->GetPlayerInterface_2(this: v204);
    else
      v205 = 0;
    LODWORD(v206) = &off_82350000;
    HIDWORD(v206) = *(_DWORD *)(v205 + 46164);
    v207 = *(float *)(v205 + 46168);
    v228.mat[0].z = *(float *)(v205 + 46172);
    v228.mat[0].x = *(float *)&v206;
    v228.mat[0].y = v207;
    *((double *)&v208 + 1) = v228.mat[0].z;
    *(double *)&v208 = *(float *)&v206;
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)&v206)),
      a3: *(__int64 *)((char *)&v208 + 4),
      a4: *(__int64 *)&v207,
      a5: v206,
      a6: v213,
      a7: v214,
      a8: v215,
      a9: v216,
      a10: v217,
      a11: v218);
  }
  if ( g_drawUCmdTracker2ViewAngles.valueInteger != 0 )
  {
    v209 = this->presentable;
    if ( v209 != nullptr )
      v210 = (int)v209->GetPlayerInterface_2(this: v209);
    else
      v210 = 0;
    LODWORD(v211) = &off_82350000;
    LODWORD(v212) = *(_DWORD *)(v210 + 46456);
    HIDWORD(v211) = *(_DWORD *)(v210 + 46448);
    v228.mat[0].y = *(float *)(v210 + 46452);
    LODWORD(v228.mat[0].z) = v212;
    v228.mat[0].x = *(float *)&v211;
    v227 = *((float *)&v212 + 1);
    HIDWORD(v212) = LODWORD(v227);
    idPlayer::debugHUDPrintf(
      this,
      fmt: (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(*(float *)&v211)),
      a3: COERCE__INT64(v228.mat[0].y),
      a4: v212,
      a5: v211,
      a6: v213,
      a7: v214,
      a8: v215,
      a9: v216,
      a10: v217,
      a11: v218);
  }
  if ( g_drawPlayerInventory.valueInteger != 0 )
    idPlayer::DrawPlayerInventory(this);
  idPLogScope::~idPLogScope(this: &v235);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: &v236);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: &v234);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: &v233);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: &v231);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: &v237);
LABEL_263:
  RD_EventEnd();
}


// ========================================================================
// __unwind$528640_0
// EA  : 0x82E3AB18
// RVA : 0x00E3AB18
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528640_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 544));
}


// ========================================================================
// __unwind$528641_0
// EA  : 0x82E3AB40
// RVA : 0x00E3AB40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528641_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 296));
}


// ========================================================================
// __unwind$528642_0
// EA  : 0x82E3AB68
// RVA : 0x00E3AB68
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528642_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 545));
}


// ========================================================================
// __unwind$528643_0
// EA  : 0x82E3AB90
// RVA : 0x00E3AB90
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528643_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 216));
}


// ========================================================================
// __unwind$528646_0
// EA  : 0x82E3ABB8
// RVA : 0x00E3ABB8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528646_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 546));
}


// ========================================================================
// __unwind$528647_0
// EA  : 0x82E3ABE0
// RVA : 0x00E3ABE0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528647_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 264));
}


// ========================================================================
// __unwind$528648_0
// EA  : 0x82E3AC08
// RVA : 0x00E3AC08
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528648_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 547));
}


// ========================================================================
// __unwind$528649_0
// EA  : 0x82E3AC30
// RVA : 0x00E3AC30
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528649_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 272));
}


// ========================================================================
// __unwind$528650_0
// EA  : 0x82E3AC58
// RVA : 0x00E3AC58
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528650_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 548));
}


// ========================================================================
// __unwind$528651_0
// EA  : 0x82E3AC80
// RVA : 0x00E3AC80
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528651_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 288));
}


// ========================================================================
// __unwind$528652_0
// EA  : 0x82E3ACA8
// RVA : 0x00E3ACA8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528652_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 736 + 549));
}


// ========================================================================
// __unwind$528653_0
// EA  : 0x82E3ACD0
// RVA : 0x00E3ACD0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_528653_0()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 736 + 280));
}


// ========================================================================
// ?OnAIEvent@idPlayer@@UAAXPBVidAIEvent@@@Z
// EA  : 0x82E3ACF8
// RVA : 0x00E3ACF8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::OnAIEvent(idPlayer *this, idAIEventSphere *event)
{
  idAIEventSphere *v4; // r3
  int v5; // r10
  float *v6; // r30
  idEntity *v7; // r3
  idEntity *v8; // r3
  idPhysics *Physics; // r3
  float *v10; // r3
  double v11; // fp0
  int v12; // r7
  double v13; // fp13
  int v14; // r6
  double v15; // fp12
  int v16; // r9
  int v17; // r26
  int v18; // r28
  double v19; // fp29
  double v20; // fp28
  double v21; // fp30
  double v22; // fp31
  idStaticList<idEntityPtr<idEntity const >,4> *v23; // r29
  int v24; // r30
  int v25; // r9
  idEntity *v26; // r3
  idEntity *v27; // r3
  idEntity *v28; // r31
  idPhysics *v29; // r3
  float *v30; // r3
  double v31; // fp13
  double v32; // fp11
  int v33; // r11
  int v34; // r11
  idList<idEntityPtr<idAI2>,5> *p_nearbyThreats; // r3
  int value; // r10
  idEntity *v37; // r3
  idProjectile_Grenade *v38; // r3
  idProjectile_Grenade *v39; // r3
  int num; // r8
  int size; // r7
  idPlayerHud *PlayerHud; // r3
  idEntityPtr<idEntity> v43[4]; // [sp+50h] [-80h] BYREF
  float v44; // [sp+60h] [-70h]

  if ( idAIEvent::GetEventClass(this: event) == AIEVENT_PLAYER_GRENADE )
  {
    if ( idAIEventSphere::CastTo(c: event) != nullptr )
    {
      value = event->originator.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v37 = gameLocal->entities.ptr[value & 0x1FFF];
        if ( v37 != nullptr )
        {
          v38 = (idProjectile_Grenade *)idEntity::CastTo(c: v37);
          if ( v38 != nullptr )
          {
            v39 = idProjectile_Grenade::CastTo(c: v38);
            if ( v39 != nullptr && v39->numBounces > 1 )
            {
              num = this->nearbyThreats.num;
              size = this->nearbyThreats.size;
              v43[0].spawnId.value = (gameLocal->spawnIds.ptr[v39->entityNumber] << 13) | v39->entityNumber;
              if ( num >= size )
              {
LABEL_37:
                PlayerHud = (idPlayerHud *)idPlayer::GetPlayerHud(this);
                idPlayerHud::ActivateCombatHud(this: PlayerHud);
                return;
              }
              goto LABEL_35;
            }
          }
        }
      }
    }
    else
    {
      v4 = idAIEventSphere::CastTo(c: event);
      v5 = event->originator.spawnId.value;
      v6 = (float *)v4;
      if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13
        && (v7 = gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr
        && (v8 = idEntity::CastTo(c: v7)) != nullptr )
      {
        v43[0].spawnId.value = (gameLocal->spawnIds.ptr[v8->entityNumber] << 13) | v8->entityNumber;
      }
      else
      {
        v43[0].spawnId.value = 0x1FFF;
      }
      if ( v6 != nullptr )
      {
        if ( this->nearbyThreats.num < this->nearbyThreats.size )
        {
          if ( idEntityPtr<idEntity const>::operator->(this: v43) == nullptr )
            return;
LABEL_35:
          p_nearbyThreats = (idList<idEntityPtr<idAI2>,5> *)&this->nearbyThreats;
LABEL_36:
          idList<idEntityPtr<idEntity>,5>::AddUnique(this: p_nearbyThreats, obj: v43);
          goto LABEL_37;
        }
        Physics = idEntity::GetPhysics(this);
        v10 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v11 = v6[6];
        v12 = *(int *)v10;
        v13 = v6[7];
        v14 = *((int *)v10 + 1);
        v15 = v6[5];
        v16 = this->nearbyThreats.num;
        v17 = -1;
        v18 = 0;
        v44 = v10[2];
        v19 = v44;
        v43[2].spawnId.value = v12;
        v20 = *(float *)&v12;
        v43[3].spawnId.value = v14;
        v21 = *(float *)&v14;
        v22 = (float)((float)((float)((float)v15 - *(float *)&v12) * (float)((float)v15 - *(float *)&v12))
                    + (float)((float)((float)((float)v13 - v44) * (float)((float)v13 - v44))
                            + (float)((float)((float)v11 - *(float *)&v14) * (float)((float)v11 - *(float *)&v14))));
        if ( v16 > 0 )
        {
          v23 = &this->nearbyThreats;
          v24 = 0;
          do
          {
            v25 = v23->list[v24].spawnId.value;
            if ( gameLocal->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13
              && (v26 = gameLocal->entities.ptr[v25 & 0x1FFF]) != nullptr )
            {
              v27 = idEntity::CastTo(c: v26);
            }
            else
            {
              v27 = nullptr;
            }
            v28 = idEntity::CastTo(c: v27);
            if ( v28 != nullptr )
            {
              if ( v28 == idEntityPtr<idEntity const>::operator->(this: v43) )
                return;
              v29 = idEntity::GetPhysics(this: v28);
              v30 = (float *)v29->GetOrigin(this: v29, a2: 0);
              v31 = (float)(v30[1] - (float)v21);
              v32 = (float)(v30[2] - (float)v19);
              if ( (float)((float)((float)(*v30 - (float)v20) * (float)(*v30 - (float)v20))
                         + (float)((float)((float)v32 * (float)v32) + (float)((float)v31 * (float)v31))) > v22 )
              {
                v17 = v18;
                v22 = (float)((float)((float)(*v30 - (float)v20) * (float)(*v30 - (float)v20))
                            + (float)((float)((float)v32 * (float)v32) + (float)((float)v31 * (float)v31)));
              }
            }
            ++v18;
            ++v24;
          }
          while ( v18 < this->nearbyThreats.num );
          if ( v17 != -1 )
          {
            if ( v17 >= 0 )
            {
              v33 = this->nearbyThreats.num;
              if ( v17 < v33 )
              {
                v34 = v33 - 1;
                this->nearbyThreats.num = v34;
                if ( v17 != v34 )
                  v23->list[v17].spawnId.value = v23->list[v34].spawnId.value;
              }
            }
            p_nearbyThreats = (idList<idEntityPtr<idAI2>,5> *)&this->nearbyThreats;
            goto LABEL_36;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?SetupBotComponent@idPlayer@@QAAXPBVidDeclBot@@@Z
// EA  : 0x82E3B038
// RVA : 0x00E3B038
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::SetupBotComponent(idPlayer *this, const idDeclBot *botDef)
{
  idBot *v4; // r3
  idBot *v5; // r3
  int entityNumber; // r10
  int v7; // r9
  idList<idEntityPtr<idEntity>,58> *p_botEntities; // r3
  int num; // r8
  int v10; // r10
  int v11; // r11
  idEntityPtr<idEntity> v12; // [sp+50h] [-30h] BYREF

  v4 = (idBot *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                  size: 0x8Cu,
                  tag: TAG_NEW,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v12.spawnId.value = (int)v4;
  if ( v4 != nullptr )
    v5 = idBot::idBot(this: v4, newOwner: this, botDef);
  else
    v5 = nullptr;
  entityNumber = this->entityNumber;
  this->botController = v5;
  v7 = 0;
  p_botEntities = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->botEntities;
  num = gameLocal->botEntities.num;
  v10 = (gameLocal->spawnIds.ptr[entityNumber] << 13) | entityNumber;
  v12.spawnId.value = v10;
  if ( num <= 0 )
    goto LABEL_10;
  v11 = 0;
  while ( p_botEntities->list[v11].spawnId.value != v10 )
  {
    ++v7;
    ++v11;
    if ( v7 >= num )
      goto LABEL_10;
  }
  if ( v7 < 0 )
LABEL_10:
    idList<idEntityPtr<idEntity>,58>::Append(this: p_botEntities, obj: &v12);
}


// ========================================================================
// __unwind$530669
// EA  : 0x82E3B118
// RVA : 0x00E3B118
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall _unwind_530669(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// ?Respawn@idPlayer@@QAAX_NPAVidPlayerStart@@@Z
// EA  : 0x82E3B140
// RVA : 0x00E3B140
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::Respawn(idPlayer *this, bool initial, idPlayerStart *spawnSpot)
{
  __int64 v6; // r8
  int v7; // r6
  __int64 v8; // r10
  int value; // r9
  bool v10; // r28
  idEntity *v11; // r3
  idVehicle *v12; // r30
  double y; // fp12
  double v14; // fp11
  idPhysics *Physics; // r31
  idPhysics *v16; // r30
  idAngles *v17; // r3
  const idAngles *v18; // r31
  const idVec3 *v19; // r3
  idVec3 v20; // [sp+50h] [-60h] BYREF
  idMat3 v21[2]; // [sp+60h] [-50h] BYREF

  LODWORD(v6) = common->IsServer(this: common);
  if ( (_DWORD)v6 != 0 )
  {
    if ( spawnSpot == nullptr )
    {
      LODWORD(v8) = &gameLocal->gameSpawnInfo.spawnSpotOverride;
      HIDWORD(v8) = gameLocal->gameSpawnInfo.spawnSpotOverride.len;
      if ( HIDWORD(v8) == 0 )
        LODWORD(v8) = &gameLocal->gameSpawnInfo.spawnSpot;
      spawnSpot = idGameLocal::FindSpawnSpot(
                    this: gameLocal,
                    spawnspot: *(const char **)(v8 + 4),
                    playerNum: this->entityNumber,
                    a4: v7,
                    a5: v6,
                    a6: v8);
    }
    value = spawnSpot->vehicle.spawnId.value;
    v10 = spawnSpot->initial;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v11 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v12 = (idVehicle *)idEntity::CastTo(c: v11);
    }
    else
    {
      v12 = nullptr;
    }
    idMat3::ToAngles(this: v21, result: (idAngles *)&spawnSpot->spawnOrientation);
    y = spawnSpot->spawnPosition.y;
    v14 = (float)(spawnSpot->spawnPosition.z + (float)5.0);
    v20.x = spawnSpot->spawnPosition.x;
    v20.y = y;
    v20.z = v14;
    idPlayer::Respawn(
      this,
      initial,
      spawnPos: &v20,
      spawnAngles: (const idAngles *)v21,
      spawnVehicle: v12,
      initialSpawnPoint: v10);
    if ( !initial )
      spawnSpot->ActivateTargets(this: spawnSpot, a2: this);
    this->deathTrigger.spawnId.value = spawnSpot->deathTrigger.spawnId.value;
  }
  else
  {
    Physics = idEntity::GetPhysics(this);
    v16 = idEntity::GetPhysics(this);
    v17 = (idAngles *)Physics->GetAxis(this: Physics, a2: 0);
    v18 = idMat3::ToAngles(this: (idMat3 *)&v21[0].mat[1].y, result: v17);
    v19 = v16->GetOrigin(this: v16, a2: 0);
    idPlayer::Respawn(this, initial, spawnPos: v19, spawnAngles: v18, spawnVehicle: nullptr, initialSpawnPoint: false);
  }
  this->spawnTimeMS = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
}


// ========================================================================
// ?Event_Respawn@idPlayer@@AAA?AVeventVoid@@XZ
// EA  : 0x82E3B318
// RVA : 0x00E3B318
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

idPlayer *__fastcall idPlayer::Event_Respawn(idPlayer *this, idPlayer *result)
{
  idPlayer::Respawn(this: result, initial: false, spawnSpot: nullptr);
  return this;
}


// ========================================================================
// ?Spawn@idPlayer@@QAAXXZ
// EA  : 0x82E3B358
// RVA : 0x00E3B358
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::Spawn(idPlayer *this)
{
  idPresentable *v2; // r3
  idPresentablePlayer *v3; // r3
  idAlignedEntity *v4; // r3
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  idAlignedEntity *v8; // r3
  va *v9; // r3
  idAlignedEntity *thirdPersonHands; // r30
  idPresentable *presentable; // r11
  idAlignedEntity *v12; // r30
  idPresentable *v13; // r11
  idAlignedEntity *v14; // r3
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  idAlignedEntity *v18; // r3
  va *v19; // r3
  idAlignedEntity *thirdPersonLegs; // r30
  idPresentable *v21; // r11
  idAlignedEntity *v22; // r30
  idPresentable *v23; // r11
  idPresentable *v24; // r3
  idPresentablePlayer *v25; // r3
  int v26; // [sp+8h] [-1088h]
  int v27; // [sp+Ch] [-1084h]
  int v28; // [sp+10h] [-1080h]
  int v29; // [sp+14h] [-107Ch]
  int v30; // [sp+18h] [-1078h]
  int v31; // [sp+1Ch] [-1074h]
  idEntityPtr<idEntity> v32[4]; // [sp+50h] [-1040h] BYREF
  va v33; // [sp+60h] [-1030h] BYREF

  if ( common->IsServer(this: common) )
  {
    idPlayer::Respawn(this, initial: true, spawnSpot: nullptr);
    this->easyTable = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                             this: &idDeclTable::resourceList,
                                             name: "playerdamage/easy",
                                             makeDefault: false);
    this->normalTable = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                               this: &idDeclTable::resourceList,
                                               name: "playerdamage/normal",
                                               makeDefault: false);
    this->hardTable = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                             this: &idDeclTable::resourceList,
                                             name: "playerdamage/hard",
                                             makeDefault: false);
    this->nightmareTable = (const idDeclTable *)idDeclInfo::FindWithInheritance(
                                                  this: &idDeclTable::resourceList,
                                                  name: "playerdamage/nightmare",
                                                  makeDefault: false);
    v4 = (idAlignedEntity *)gameLocal->SpawnEntityFromDef(
                              this: gameLocal,
                              a2: this->thirdPersonHandsDef,
                              a3: -1,
                              a4: -1,
                              a5: -1);
    v8 = idAlignedEntity::CastTo(c: v4);
    this->thirdPersonHands = v8;
    if ( v8 != nullptr )
    {
      v8->owner = this;
      HIDWORD(v7) = this->entityNumber;
      v9 = va::va(
             this: &v33,
             fmt: "thirdPersonHands_%d",
             a3: v7,
             a4: v6,
             a5: v5,
             a6: v26,
             a7: v27,
             a8: v28,
             a9: v29,
             a10: v30,
             a11: v31);
      idEntity::SetName(this: this->thirdPersonHands, newName: v9->buffer);
      this->thirdPersonHands->manualUpdate = true;
      thirdPersonHands = this->thirdPersonHands;
      presentable = thirdPersonHands->presentable;
      if ( presentable == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        presentable = thirdPersonHands->presentable;
      }
      *((_BYTE *)&presentable->model->g + 105) |= 0x80u;
      v12 = this->thirdPersonHands;
      v13 = v12->presentable;
      if ( v13 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonHands);
        v13 = v12->presentable;
      }
      v13->Hide(this: v13, a2: true);
    }
    v14 = (idAlignedEntity *)gameLocal->SpawnEntityFromDef(
                               this: gameLocal,
                               a2: this->thirdPersonLegsDef,
                               a3: -1,
                               a4: -1,
                               a5: -1);
    v18 = idAlignedEntity::CastTo(c: v14);
    this->thirdPersonLegs = v18;
    if ( v18 != nullptr )
    {
      v18->owner = this;
      HIDWORD(v17) = this->entityNumber;
      v19 = va::va(
              this: &v33,
              fmt: "thirdPersonLegs_%d",
              a3: v17,
              a4: v16,
              a5: v15,
              a6: v26,
              a7: v27,
              a8: v28,
              a9: v29,
              a10: v30,
              a11: v31);
      idEntity::SetName(this: this->thirdPersonLegs, newName: v19->buffer);
      this->thirdPersonLegs->manualUpdate = true;
      thirdPersonLegs = this->thirdPersonLegs;
      v21 = thirdPersonLegs->presentable;
      if ( v21 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v21 = thirdPersonLegs->presentable;
      }
      *((_BYTE *)&v21->model->g + 105) |= 0x80u;
      v22 = this->thirdPersonLegs;
      v23 = v22->presentable;
      if ( v23 == nullptr )
      {
        idEntity::InitPresentableInternal(this: this->thirdPersonLegs);
        v23 = v22->presentable;
      }
      v23->Hide(this: v23, a2: true);
    }
    idPlayer::PlayerBehavior_Startup(this);
    if ( (gameLocal->GetGameFlags(this: gameLocal) & 0x20) != 0 )
    {
      idPlayerHud_Render::NoteSwfForBuildGame();
      idPlayerGuis_Render::NoteSwfForBuildGame();
      v24 = this->presentable;
      if ( v24 != nullptr )
        v25 = v24->GetPlayerInterface_2(this: v24);
      else
        v25 = nullptr;
      idPresentablePlayer::NoteSwfForBuildGame(this: v25);
    }
    v32[0].spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
    idList<idEntityPtr<idEntity>,5>::AddUnique(
      this: (idList<idEntityPtr<idAI2>,5> *)&gameLocal->playerEntities,
      obj: v32);
    idGameLocal::BotSystems_RegisterEntity(this: gameLocal, entity: this, entityType: 1, entityFlags: 608);
  }
  else
  {
    idPlayer::InitPhysics(this);
    v2 = this->presentable;
    if ( v2 != nullptr )
      v3 = v2->GetPlayerInterface_2(this: v2);
    else
      v3 = nullptr;
    idPresentablePlayer::InitForClient(this: v3);
    v32[0].spawnId.value = (gameLocal->spawnIds.ptr[this->entityNumber] << 13) | this->entityNumber;
    idList<idEntityPtr<idEntity>,5>::AddUnique(
      this: (idList<idEntityPtr<idAI2>,5> *)&gameLocal->playerEntities,
      obj: v32);
  }
}


// ========================================================================
// ?ClearSubtitle@idPlayer@@QAAXPBVidEntity@@@Z
// EA  : 0x82E3B6A8
// RVA : 0x00E3B6A8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __fastcall idPlayer::ClearSubtitle(idPlayer *this, const idEntity *ent)
{
  idPresentable *presentable; // r3
  idPresentablePlayer *v5; // r3
  idPresentable *v6; // r3
  idPresentablePlayer *v7; // r3
  idSWF *PlayerGui; // r3
  idStaticList<idSWFScriptVar,16> v9; // [sp+50h] [-B0h] BYREF

  presentable = this->presentable;
  if ( presentable != nullptr )
    v5 = presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = nullptr;
  if ( idPresentablePlayer::GetPlayerGui(this: v5, g: GUI_SUBTITLE) != nullptr )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v9);
    idSWFParmList::Append(this: (idSWFParmList *)&v9, i: (idSWFScriptVar::swfScriptVarValue_t *)ent->entityNumber);
    v6 = this->presentable;
    if ( v6 != nullptr )
      v7 = v6->GetPlayerInterface_2(this: v6);
    else
      v7 = nullptr;
    PlayerGui = idPresentablePlayer::GetPlayerGui(this: v7, g: GUI_SUBTITLE);
    idSWF::Invoke(this: PlayerGui, functionName: "clearSubtitle", parms: (const idSWFParmList *)&v9);
    idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v9);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v9);
  }
}


// ========================================================================
// __unwind$531313
// EA  : 0x82E3B75C
// RVA : 0x00E3B75C
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void _unwind_531313()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// `dynamic initializer for 'g_armorProtectionAmount''
// EA  : 0x83388A40
// RVA : 0x01388A40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_armorProtectionAmount__()
{
  idCVar::idCVar(
    this: &g_armorProtectionAmount,
    name: "g_armorProtectionAmount",
    value: "0.75",
    flags: 4,
    description: "how much damage the armor should soak",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_armorProtectionAmount__);
}


// ========================================================================
// `dynamic initializer for 'g_weaponSwitchDelay''
// EA  : 0x83388A98
// RVA : 0x01388A98
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_weaponSwitchDelay__()
{
  idCVar::idCVar(
    this: &g_weaponSwitchDelay,
    name: "g_weaponSwitchDelay",
    value: "300",
    flags: 2,
    description: "time to wait before a pending weapon switch takes effect",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_weaponSwitchDelay__);
}


// ========================================================================
// `dynamic initializer for 'g_ammoSwitchDelay''
// EA  : 0x83388AF0
// RVA : 0x01388AF0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_ammoSwitchDelay__()
{
  idCVar::idCVar(
    this: &g_ammoSwitchDelay,
    name: "g_ammoSwitchDelay",
    value: "600",
    flags: 2,
    description: "time to wait before a pending ammo switch takes effect",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_ammoSwitchDelay__);
}


// ========================================================================
// `dynamic initializer for 'g_damageSoundDuration''
// EA  : 0x83388B48
// RVA : 0x01388B48
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_damageSoundDuration__()
{
  idCVar::idCVar(
    this: &g_damageSoundDuration,
    name: "g_breathDamageDuration",
    value: "20",
    flags: 4,
    description: "number of seconds the damage sounds, heartbeat or breathing lasts",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_damageSoundDuration__);
}


// ========================================================================
// `dynamic initializer for 'g_heartBeatIntervals''
// EA  : 0x83388BA0
// RVA : 0x01388BA0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_heartBeatIntervals__()
{
  idCVar::idCVar(
    this: &g_heartBeatIntervals,
    name: "g_heartBeatIntervals",
    value: "400",
    flags: 4,
    description: "time in MS to wait between player heartbeats",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_heartBeatIntervals__);
}


// ========================================================================
// `dynamic initializer for 'g_damageHealthLimitHeavy''
// EA  : 0x83388BF8
// RVA : 0x01388BF8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_damageHealthLimitHeavy__()
{
  idCVar::idCVar(
    this: &g_damageHealthLimitHeavy,
    name: "g_damageHealthLimitHeavy",
    value: "0.25",
    flags: 4,
    description: "health level to start heartbeat",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_damageHealthLimitHeavy__);
}


// ========================================================================
// `dynamic initializer for 'g_damageHealthLimitMedium''
// EA  : 0x83388C50
// RVA : 0x01388C50
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_damageHealthLimitMedium__()
{
  idCVar::idCVar(
    this: &g_damageHealthLimitMedium,
    name: "g_damageHealthLimitMedium",
    value: "0.5",
    flags: 4,
    description: "health level to start medium breathing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_damageHealthLimitMedium__);
}


// ========================================================================
// `dynamic initializer for 'g_showSpeeds''
// EA  : 0x83388CA8
// RVA : 0x01388CA8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_showSpeeds__()
{
  idCVar::idCVar(
    this: &g_showSpeeds,
    name: "g_showSpeeds",
    value: "-1",
    flags: 2,
    description: "shows the speed for the player with the specified entity number",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_showSpeeds__);
}


// ========================================================================
// `dynamic initializer for 'g_demoMode''
// EA  : 0x83388D00
// RVA : 0x01388D00
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_demoMode__()
{
  idCVar::idCVar(
    this: &g_demoMode,
    name: "g_demoMode",
    value: "0",
    flags: 2,
    description: "demo mode just used for main menu",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_demoMode__);
}


// ========================================================================
// `dynamic initializer for 'g_drawPlayerHealth''
// EA  : 0x83388D58
// RVA : 0x01388D58
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawPlayerHealth__()
{
  idCVar::idCVar(
    this: &g_drawPlayerHealth,
    name: "g_drawPlayerHealth",
    value: "0",
    flags: 1,
    description: "shows the player health and max health",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawPlayerHealth__);
}


// ========================================================================
// `dynamic initializer for 'g_drawPlayerPos''
// EA  : 0x83388DB0
// RVA : 0x01388DB0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawPlayerPos__()
{
  idCVar::idCVar(
    this: &g_drawPlayerPos,
    name: "g_drawPlayerPos",
    value: "0",
    flags: 2,
    description: "1 = shows the player position, 2 = also draws the player origin in the world",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawPlayerPos__);
}


// ========================================================================
// `dynamic initializer for 'g_tracePlayerPos''
// EA  : 0x83388E08
// RVA : 0x01388E08
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_tracePlayerPos__()
{
  idCVar::idCVar(
    this: &g_tracePlayerPos,
    name: "g_tracePlayerPos",
    value: "0",
    flags: 1,
    description: "outputs the player position to the console every frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_tracePlayerPos__);
}


// ========================================================================
// `dynamic initializer for 'g_tracePlayerVel''
// EA  : 0x83388E60
// RVA : 0x01388E60
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_tracePlayerVel__()
{
  idCVar::idCVar(
    this: &g_tracePlayerVel,
    name: "g_tracePlayerVel",
    value: "0",
    flags: 1,
    description: "outputs the player velocity to the console every frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_tracePlayerVel__);
}


// ========================================================================
// `dynamic initializer for 'g_tracePlayerAngles''
// EA  : 0x83388EB8
// RVA : 0x01388EB8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_tracePlayerAngles__()
{
  idCVar::idCVar(
    this: &g_tracePlayerAngles,
    name: "g_tracePlayerAngles",
    value: "0",
    flags: 1,
    description: "outputs the player angles to the console every frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_tracePlayerAngles__);
}


// ========================================================================
// `dynamic initializer for 'g_tracePlayerDamage''
// EA  : 0x83388F10
// RVA : 0x01388F10
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_tracePlayerDamage__()
{
  idCVar::idCVar(
    this: &g_tracePlayerDamage,
    name: "g_tracePlayerDamage",
    value: "0",
    flags: 1,
    description: "outputs the incoming damage to the player",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_tracePlayerDamage__);
}


// ========================================================================
// `dynamic initializer for 'g_drawPlayerVel''
// EA  : 0x83388F68
// RVA : 0x01388F68
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawPlayerVel__()
{
  idCVar::idCVar(
    this: &g_drawPlayerVel,
    name: "g_drawPlayerVel",
    value: "0",
    flags: 1,
    description: "shows the player velocity (vector)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawPlayerVel__);
}


// ========================================================================
// `dynamic initializer for 'g_drawPlayerSpeed''
// EA  : 0x83388FC0
// RVA : 0x01388FC0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawPlayerSpeed__()
{
  idCVar::idCVar(
    this: &g_drawPlayerSpeed,
    name: "g_drawPlayerSpeed",
    value: "0",
    flags: 1,
    description: "shows the player speed (scalar)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawPlayerSpeed__);
}


// ========================================================================
// `dynamic initializer for 'g_drawPlayerGround''
// EA  : 0x83389018
// RVA : 0x01389018
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawPlayerGround__()
{
  idCVar::idCVar(
    this: &g_drawPlayerGround,
    name: "g_drawPlayerGround",
    value: "0",
    flags: 1,
    description: "shows the player ground height",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawPlayerGround__);
}


// ========================================================================
// `dynamic initializer for 'g_drawPlayerAngles''
// EA  : 0x83389070
// RVA : 0x01389070
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawPlayerAngles__()
{
  idCVar::idCVar(
    this: &g_drawPlayerAngles,
    name: "g_drawPlayerAngles",
    value: "0",
    flags: 1,
    description: "shows the player view angles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawPlayerAngles__);
}


// ========================================================================
// `dynamic initializer for 'g_drawPlayerViewPos''
// EA  : 0x833890C8
// RVA : 0x013890C8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawPlayerViewPos__()
{
  idCVar::idCVar(
    this: &g_drawPlayerViewPos,
    name: "g_drawPlayerViewPos",
    value: "0",
    flags: 1,
    description: "shows the player view position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawPlayerViewPos__);
}


// ========================================================================
// `dynamic initializer for 'g_tracePlayerViewPos''
// EA  : 0x83389120
// RVA : 0x01389120
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_tracePlayerViewPos__()
{
  idCVar::idCVar(
    this: &g_tracePlayerViewPos,
    name: "g_tracePlayerViewPos",
    value: "0",
    flags: 1,
    description: "outputs the player view pos to the console every frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_tracePlayerViewPos__);
}


// ========================================================================
// `dynamic initializer for 'g_drawPlayerViewAngles''
// EA  : 0x83389178
// RVA : 0x01389178
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawPlayerViewAngles__()
{
  idCVar::idCVar(
    this: &g_drawPlayerViewAngles,
    name: "g_drawPlayerViewAngles",
    value: "0",
    flags: 1,
    description: "shows the player view angles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawPlayerViewAngles__);
}


// ========================================================================
// `dynamic initializer for 'g_tracePlayerViewAngles''
// EA  : 0x833891D0
// RVA : 0x013891D0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_tracePlayerViewAngles__()
{
  idCVar::idCVar(
    this: &g_tracePlayerViewAngles,
    name: "g_tracePlayerViewAngles",
    value: "0",
    flags: 1,
    description: "outputs the player view angles to the console every frame",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_tracePlayerViewAngles__);
}


// ========================================================================
// `dynamic initializer for 'g_drawUCmdTracker1ViewAngles''
// EA  : 0x83389228
// RVA : 0x01389228
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawUCmdTracker1ViewAngles__()
{
  idCVar::idCVar(
    this: &g_drawUCmdTracker1ViewAngles,
    name: "g_drawUCmdTracker1ViewAngles",
    value: "0",
    flags: 1,
    description: "draw the umdTracker1 angles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawUCmdTracker1ViewAngles__);
}


// ========================================================================
// `dynamic initializer for 'g_drawUCmdTracker2ViewAngles''
// EA  : 0x83389280
// RVA : 0x01389280
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawUCmdTracker2ViewAngles__()
{
  idCVar::idCVar(
    this: &g_drawUCmdTracker2ViewAngles,
    name: "g_drawUCmdTracker2ViewAngles",
    value: "0",
    flags: 1,
    description: "draw the umdTracker2 angles",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawUCmdTracker2ViewAngles__);
}


// ========================================================================
// `dynamic initializer for 'g_drawPlayerInventory''
// EA  : 0x833892D8
// RVA : 0x013892D8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_drawPlayerInventory__()
{
  idCVar::idCVar(
    this: &g_drawPlayerInventory,
    name: "g_drawPlayerInventory",
    value: "0",
    flags: 1,
    description: "draws the player inventory",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_drawPlayerInventory__);
}


// ========================================================================
// `dynamic initializer for 'pm_subWeb''
// EA  : 0x83389330
// RVA : 0x01389330
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_subWeb__()
{
  idCVar::idCVar(
    this: &pm_subWeb,
    name: "pm_subWeb",
    value: "combat",
    flags: 0,
    description: "sub-web postfix for the player - this is for testing only",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_subWeb__);
}


// ========================================================================
// `dynamic initializer for 'g_permaGodMode''
// EA  : 0x83389388
// RVA : 0x01389388
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_permaGodMode__()
{
  idCVar::idCVar(
    this: &g_permaGodMode,
    name: "g_permaGodMode",
    value: "0",
    flags: 1,
    description: "player never loses god mode",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_permaGodMode__);
}


// ========================================================================
// `dynamic initializer for 'g_droppableMaxRange''
// EA  : 0x833893E0
// RVA : 0x013893E0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_droppableMaxRange__()
{
  idCVar::idCVar(
    this: &g_droppableMaxRange,
    name: "g_droppableMaxRange",
    value: "2000",
    flags: 4,
    description: "max droppable range before they disassemble",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_droppableMaxRange__);
}


// ========================================================================
// `dynamic initializer for 'pm_torsoTrackRate''
// EA  : 0x83389438
// RVA : 0x01389438
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_torsoTrackRate__()
{
  idCVar::idCVar(
    this: &pm_torsoTrackRate,
    name: "pm_torsoTrackRate",
    value: "100000.0",
    flags: 4,
    description: "max rate that torso will track to client view angle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_torsoTrackRate__);
}


// ========================================================================
// `dynamic initializer for 'pm_torsoYawClamp''
// EA  : 0x83389490
// RVA : 0x01389490
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_torsoYawClamp__()
{
  idCVar::idCVar(
    this: &pm_torsoYawClamp,
    name: "pm_torsoYawClamp",
    value: "90.0",
    flags: 4,
    description: "max angle torso can turn from body forward around yaw axis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_torsoYawClamp__);
}


// ========================================================================
// `dynamic initializer for 'pm_torsoPitchClamp''
// EA  : 0x833894E8
// RVA : 0x013894E8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_torsoPitchClamp__()
{
  idCVar::idCVar(
    this: &pm_torsoPitchClamp,
    name: "pm_torsoPitchClamp",
    value: "45.0",
    flags: 4,
    description: "max angle torso can turn from body forward around pitch axis",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_torsoPitchClamp__);
}


// ========================================================================
// `dynamic initializer for 'pm_torsoUseIndependentConstraints''
// EA  : 0x83389540
// RVA : 0x01389540
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_torsoUseIndependentConstraints__()
{
  idCVar::idCVar(
    this: &pm_torsoUseIndependentConstraints,
    name: "pm_torsoUseIndependentConstraints",
    value: "1",
    flags: 1,
    description: "true to use independent pitch and yaw constraints on torso",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_torsoUseIndependentConstraints__);
}


// ========================================================================
// `dynamic initializer for 'rcbomb_timeInitialScaleAmount''
// EA  : 0x83389598
// RVA : 0x01389598
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rcbomb_timeInitialScaleAmount__()
{
  idCVar::idCVar(
    this: &rcbomb_timeInitialScaleAmount,
    name: "rcbomb_timeInitialScaleAmount",
    value: "0.25",
    flags: 4,
    description: "amount time scale starts at",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rcbomb_timeInitialScaleAmount__);
}


// ========================================================================
// `dynamic initializer for 'rcbomb_timeScaleAmount''
// EA  : 0x833895F0
// RVA : 0x013895F0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rcbomb_timeScaleAmount__()
{
  idCVar::idCVar(
    this: &rcbomb_timeScaleAmount,
    name: "rcbomb_timeScaleAmount",
    value: "0.10",
    flags: 4,
    description: "amount time scale increases each event",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rcbomb_timeScaleAmount__);
}


// ========================================================================
// `dynamic initializer for 'rcbomb_timeScaleTickTime''
// EA  : 0x83389648
// RVA : 0x01389648
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rcbomb_timeScaleTickTime__()
{
  idCVar::idCVar(
    this: &rcbomb_timeScaleTickTime,
    name: "rcbomb_timeScaleTickTime",
    value: "150",
    flags: 2,
    description: "time between ticks of timescale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rcbomb_timeScaleTickTime__);
}


// ========================================================================
// `dynamic initializer for 'rcbomb_lookatNoncinematicExplosion''
// EA  : 0x833896A0
// RVA : 0x013896A0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__rcbomb_lookatNoncinematicExplosion__()
{
  idCVar::idCVar(
    this: &rcbomb_lookatNoncinematicExplosion,
    name: "rcbomb_lookatNoncinematicExplosion",
    value: "0",
    flags: 1,
    description: "if true the player will be turned to look at a non cinematic rcbombcar explosion",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__rcbomb_lookatNoncinematicExplosion__);
}


// ========================================================================
// `dynamic initializer for 'swf_subtitleRange''
// EA  : 0x833896F8
// RVA : 0x013896F8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_subtitleRange__()
{
  idCVar::idCVar(
    this: &swf_subtitleRange,
    name: "swf_subtitleRange",
    value: "500.0f",
    flags: 4,
    description: "distance a which subtitles no longer appear (note: for AI's this is overridden by their idDeclAIBehavior).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_subtitleRange__);
}


// ========================================================================
// `dynamic initializer for 'swf_combatSubtitleRange''
// EA  : 0x83389750
// RVA : 0x01389750
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_combatSubtitleRange__()
{
  idCVar::idCVar(
    this: &swf_combatSubtitleRange,
    name: "swf_combatSubtitleRange",
    value: "1024.0f",
    flags: 4,
    description: "distance a which combat subtitles no longer appear (note: for AI's this is overridden by their idDeclAIBehavior).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_combatSubtitleRange__);
}


// ========================================================================
// `dynamic initializer for 'swf_useSubtitles''
// EA  : 0x833897A8
// RVA : 0x013897A8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_useSubtitles__()
{
  idCVar::idCVar(
    this: &swf_useSubtitles,
    name: "swf_useSubtitles",
    value: "0",
    flags: 1,
    description: "set to override the profile setting",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_useSubtitles__);
}


// ========================================================================
// `dynamic initializer for 'swf_subtitlePause''
// EA  : 0x83389800
// RVA : 0x01389800
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_subtitlePause__()
{
  idCVar::idCVar(
    this: &swf_subtitlePause,
    name: "swf_subtitlePause",
    value: "3000",
    flags: 2,
    description: "number of seconds before a pause is considered",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_subtitlePause__);
}


// ========================================================================
// `dynamic initializer for 'g_noCoopPlayerCollision''
// EA  : 0x83389858
// RVA : 0x01389858
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_noCoopPlayerCollision__()
{
  idCVar::idCVar(
    this: &g_noCoopPlayerCollision,
    name: "g_noCoopPlayerCollision",
    value: "1",
    flags: 1,
    description: "allow co-op players to clip through one another.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_noCoopPlayerCollision__);
}


// ========================================================================
// `dynamic initializer for 'pm_torsoDebug''
// EA  : 0x833898B0
// RVA : 0x013898B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_torsoDebug__()
{
  idCVar::idCVar(
    this: &pm_torsoDebug,
    name: "pm_torsoDebug",
    value: "-1",
    flags: 2,
    description: "Debug torso aiming of this player",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_torsoDebug__);
}


// ========================================================================
// `dynamic initializer for 'pm_torsoDisable''
// EA  : 0x83389908
// RVA : 0x01389908
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_torsoDisable__()
{
  idCVar::idCVar(
    this: &pm_torsoDisable,
    name: "pm_torsoDisable",
    value: "0",
    flags: 1,
    description: "Debug torso aiming of this player",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_torsoDisable__);
}


// ========================================================================
// `dynamic initializer for 'pm_torsoDisableBlendMS''
// EA  : 0x83389960
// RVA : 0x01389960
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_torsoDisableBlendMS__()
{
  idCVar::idCVar(
    this: &pm_torsoDisableBlendMS,
    name: "pm_torsoDisableBlendMS",
    value: "1000",
    flags: 2,
    description: "Debug torso aiming of this player",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_torsoDisableBlendMS__);
}


// ========================================================================
// `dynamic initializer for 'g_playerShowStats''
// EA  : 0x833899B8
// RVA : 0x013899B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_playerShowStats__()
{
  idCVar::idCVar(
    this: &g_playerShowStats,
    name: "g_playerShowStats",
    value: "-1",
    flags: 2,
    description: "detailed view of new player metrics system",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_playerShowStats__);
}


// ========================================================================
// `dynamic initializer for 'pm_modelRotationBiasDot''
// EA  : 0x83389A10
// RVA : 0x01389A10
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_modelRotationBiasDot__()
{
  idCVar::idCVar(
    this: &pm_modelRotationBiasDot,
    name: "pm_modelRotationBiasDot",
    value: "-0.5",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_modelRotationBiasDot__);
}


// ========================================================================
// `dynamic initializer for 'pm_modelRotationTurnThresh''
// EA  : 0x83389A68
// RVA : 0x01389A68
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_modelRotationTurnThresh__()
{
  idCVar::idCVar(
    this: &pm_modelRotationTurnThresh,
    name: "pm_modelRotationTurnThresh",
    value: "0.70",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_modelRotationTurnThresh__);
}


// ========================================================================
// `dynamic initializer for 'pm_modelRotationTurnThreshEnd''
// EA  : 0x83389AC0
// RVA : 0x01389AC0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_modelRotationTurnThreshEnd__()
{
  idCVar::idCVar(
    this: &pm_modelRotationTurnThreshEnd,
    name: "pm_modelRotationTurnThreshEnd",
    value: "0.8",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_modelRotationTurnThreshEnd__);
}


// ========================================================================
// `dynamic initializer for 'g_coop_revivePCT''
// EA  : 0x83389B18
// RVA : 0x01389B18
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_coop_revivePCT__()
{
  idCVar::idCVar(
    this: &g_coop_revivePCT,
    name: "g_coop_revivePCT",
    value: "1.0",
    flags: 4,
    description: "PCT of health to revive to in coop (player to player)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_coop_revivePCT__);
}


// ========================================================================
// `dynamic initializer for 'pm_modelRotationRate''
// EA  : 0x83389B70
// RVA : 0x01389B70
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_modelRotationRate__()
{
  idCVar::idCVar(
    this: &pm_modelRotationRate,
    name: "pm_modelRotationRate",
    value: "360",
    flags: 4,
    description: "rate at which the player model will align to velocity direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_modelRotationRate__);
}


// ========================================================================
// `dynamic initializer for 'pm_modelRotation_AnimBased''
// EA  : 0x83389BC8
// RVA : 0x01389BC8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_modelRotation_AnimBased__()
{
  idCVar::idCVar(
    this: &pm_modelRotation_AnimBased,
    name: "pm_modelRotation_AnimBased",
    value: "1",
    flags: 1,
    description: "rate at which the player model will align to velocity direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_modelRotation_AnimBased__);
}


// ========================================================================
// `dynamic initializer for 'pm_modelRotationRate_TurnMin''
// EA  : 0x83389C20
// RVA : 0x01389C20
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_modelRotationRate_TurnMin__()
{
  idCVar::idCVar(
    this: &pm_modelRotationRate_TurnMin,
    name: "pm_modelRotationRate_TurnMin",
    value: "180",
    flags: 4,
    description: "rate at which the player model will align to velocity direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_modelRotationRate_TurnMin__);
}


// ========================================================================
// `dynamic initializer for 'pm_modelRotationRate_TurnMax''
// EA  : 0x83389C78
// RVA : 0x01389C78
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_modelRotationRate_TurnMax__()
{
  idCVar::idCVar(
    this: &pm_modelRotationRate_TurnMax,
    name: "pm_modelRotationRate_TurnMax",
    value: "720",
    flags: 4,
    description: "rate at which the player model will align to velocity direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_modelRotationRate_TurnMax__);
}


// ========================================================================
// `dynamic initializer for 'pm_modelRotationRate_AnimBigThresh''
// EA  : 0x83389CD0
// RVA : 0x01389CD0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_modelRotationRate_AnimBigThresh__()
{
  idCVar::idCVar(
    this: &pm_modelRotationRate_AnimBigThresh,
    name: "pm_modelRotationRate_AnimBigThresh",
    value: "0.1",
    flags: 4,
    description: "rate at which the player model will align to velocity direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_modelRotationRate_AnimBigThresh__);
}


// ========================================================================
// `dynamic initializer for 'pm_modelRotation_disableTorsoAim''
// EA  : 0x83389D28
// RVA : 0x01389D28
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_modelRotation_disableTorsoAim__()
{
  idCVar::idCVar(
    this: &pm_modelRotation_disableTorsoAim,
    name: "pm_modelRotation_disableTorsoAim",
    value: "0",
    flags: 2,
    description: "rate at which the player model will align to velocity direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_modelRotation_disableTorsoAim__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyAnim_upperBodyBlendInTimeMS''
// EA  : 0x83389D80
// RVA : 0x01389D80
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyAnim_upperBodyBlendInTimeMS__()
{
  idCVar::idCVar(
    this: &pm_bodyAnim_upperBodyBlendInTimeMS,
    name: "pm_bodyAnim_upperBodyBlendInTimeMS",
    value: "200",
    flags: 2,
    description: "rate at which the player model will align to velocity direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyAnim_upperBodyBlendInTimeMS__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyAnim_upperBodyBlendOutTimeMS''
// EA  : 0x83389DD8
// RVA : 0x01389DD8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyAnim_upperBodyBlendOutTimeMS__()
{
  idCVar::idCVar(
    this: &pm_bodyAnim_upperBodyBlendOutTimeMS,
    name: "pm_bodyAnim_upperBodyBlendOutTimeMS",
    value: "200",
    flags: 2,
    description: "rate at which the player model will align to velocity direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyAnim_upperBodyBlendOutTimeMS__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyAnim_fireBlendInTimeMS''
// EA  : 0x83389E30
// RVA : 0x01389E30
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyAnim_fireBlendInTimeMS__()
{
  idCVar::idCVar(
    this: &pm_bodyAnim_fireBlendInTimeMS,
    name: "pm_bodyAnim_fireBlendInTimeMS",
    value: "100",
    flags: 2,
    description: "rate at which the player model will align to velocity direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyAnim_fireBlendInTimeMS__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyAnim_fireBlendOutTimeMS''
// EA  : 0x83389E88
// RVA : 0x01389E88
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyAnim_fireBlendOutTimeMS__()
{
  idCVar::idCVar(
    this: &pm_bodyAnim_fireBlendOutTimeMS,
    name: "pm_bodyAnim_fireBlendOutTimeMS",
    value: "200",
    flags: 2,
    description: "temp",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyAnim_fireBlendOutTimeMS__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyAnim_painBlendInTimeMS''
// EA  : 0x83389EE0
// RVA : 0x01389EE0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyAnim_painBlendInTimeMS__()
{
  idCVar::idCVar(
    this: &pm_bodyAnim_painBlendInTimeMS,
    name: "pm_bodyAnim_painBlendInTimeMS",
    value: "200",
    flags: 2,
    description: "temp",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyAnim_painBlendInTimeMS__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyAnim_painBlendOutTimeMS''
// EA  : 0x83389F38
// RVA : 0x01389F38
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyAnim_painBlendOutTimeMS__()
{
  idCVar::idCVar(
    this: &pm_bodyAnim_painBlendOutTimeMS,
    name: "pm_bodyAnim_painBlendOutTimeMS",
    value: "200",
    flags: 2,
    description: "temp",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyAnim_painBlendOutTimeMS__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyAnim_painAnim''
// EA  : 0x83389F90
// RVA : 0x01389F90
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyAnim_painAnim__()
{
  idCVar::idCVar(
    this: &pm_bodyAnim_painAnim,
    name: "pm_bodyAnim_painAnim",
    value: "hands/pain/twitch/front/chest",
    flags: 0,
    description: "temp",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyAnim_painAnim__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyAnim_painAnimForce''
// EA  : 0x83389FE8
// RVA : 0x01389FE8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyAnim_painAnimForce__()
{
  idCVar::idCVar(
    this: &pm_bodyAnim_painAnimForce,
    name: "pm_bodyAnim_painAnimForce",
    value: "0",
    flags: 1,
    description: "force using pm_bodyAnim_painAnim for pain animations. For debugging",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyAnim_painAnimForce__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyAnim_painAnimDebug''
// EA  : 0x8338A040
// RVA : 0x0138A040
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyAnim_painAnimDebug__()
{
  idCVar::idCVar(
    this: &pm_bodyAnim_painAnimDebug,
    name: "pm_bodyAnim_painAnimDebug",
    value: "0",
    flags: 1,
    description: "debug player pain animations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyAnim_painAnimDebug__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyAnim_additivePainAlpha''
// EA  : 0x8338A098
// RVA : 0x0138A098
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyAnim_additivePainAlpha__()
{
  idCVar::idCVar(
    this: &pm_bodyAnim_additivePainAlpha,
    name: "pm_bodyAnim_additivePainAlpha",
    value: "0.50",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyAnim_additivePainAlpha__);
}


// ========================================================================
// `dynamic initializer for 'p_playAdditiveCrouchAnims''
// EA  : 0x8338A0F0
// RVA : 0x0138A0F0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_playAdditiveCrouchAnims__()
{
  idCVar::idCVar(
    this: &p_playAdditiveCrouchAnims,
    name: "p_playAdditiveCrouchAnims",
    value: "1",
    flags: 1,
    description: "Play additive crouch anims on hands",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_playAdditiveCrouchAnims__);
}


// ========================================================================
// `dynamic initializer for 'pm_ads_IK_enable''
// EA  : 0x8338A148
// RVA : 0x0138A148
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_ads_IK_enable__()
{
  idCVar::idCVar(
    this: &pm_ads_IK_enable,
    name: "pm_ads_IK_enable",
    value: "1",
    flags: 1,
    description: "Debug player body animation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_ads_IK_enable__);
}


// ========================================================================
// `dynamic initializer for 'pm_ads_IK_alwaysOn''
// EA  : 0x8338A1A0
// RVA : 0x0138A1A0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_ads_IK_alwaysOn__()
{
  idCVar::idCVar(
    this: &pm_ads_IK_alwaysOn,
    name: "pm_ads_IK_alwaysOn",
    value: "0",
    flags: 1,
    description: "Debug player body animation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_ads_IK_alwaysOn__);
}


// ========================================================================
// `dynamic initializer for 'pm_strafe_threshold''
// EA  : 0x8338A1F8
// RVA : 0x0138A1F8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_strafe_threshold__()
{
  idCVar::idCVar(
    this: &pm_strafe_threshold,
    name: "pm_strafe_threshold",
    value: "0.5",
    flags: 4,
    description: "Cos of angle to transition into strafe animations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_strafe_threshold__);
}


// ========================================================================
// `dynamic initializer for 'pm_bodyDebug''
// EA  : 0x8338A250
// RVA : 0x0138A250
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_bodyDebug__()
{
  idCVar::idCVar(
    this: &pm_bodyDebug,
    name: "pm_bodyDebug",
    value: "-1",
    flags: 2,
    description: "Debug player body animation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_bodyDebug__);
}


// ========================================================================
// `dynamic initializer for 'pm_minPhysSpeed''
// EA  : 0x8338A2A8
// RVA : 0x0138A2A8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_minPhysSpeed__()
{
  idCVar::idCVar(
    this: &pm_minPhysSpeed,
    name: "pm_minPhysSpeed",
    value: "5.0",
    flags: 4,
    description: "Minimum physics speed where direction is still reliable. If physics is < than this, we use cmd velocity or previous "
    "velocity to determine animation direction",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_minPhysSpeed__);
}


// ========================================================================
// `dynamic initializer for 'pm_skipAnimation''
// EA  : 0x8338A300
// RVA : 0x0138A300
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_skipAnimation__()
{
  idCVar::idCVar(
    this: &pm_skipAnimation,
    name: "pm_skipAnimation",
    value: "0",
    flags: 1,
    description: "If true, skip updating the player animation state - only for debugging animations in isolation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_skipAnimation__);
}


// ========================================================================
// `dynamic initializer for 'pm_restFrameThresh''
// EA  : 0x8338A358
// RVA : 0x0138A358
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_restFrameThresh__()
{
  idCVar::idCVar(
    this: &pm_restFrameThresh,
    name: "pm_restFrameThresh",
    value: "7",
    flags: 2,
    description: "Number of frames of no cmd movement to consider player at rest and transition to idle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_restFrameThresh__);
}


// ========================================================================
// `dynamic initializer for 'pm_restFrameDebug''
// EA  : 0x8338A3B0
// RVA : 0x0138A3B0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_restFrameDebug__()
{
  idCVar::idCVar(
    this: &pm_restFrameDebug,
    name: "pm_restFrameDebug",
    value: "-1",
    flags: 2,
    description: "Debug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_restFrameDebug__);
}


// ========================================================================
// `dynamic initializer for 'pm_ct_debug''
// EA  : 0x8338A408
// RVA : 0x0138A408
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_ct_debug__()
{
  idCVar::idCVar(
    this: &pm_ct_debug,
    name: "pm_ct_debug",
    value: "0",
    flags: 1,
    description: "PlayerModel CollisionTest Debug",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_ct_debug__);
}


// ========================================================================
// `dynamic initializer for 'pm_ct_checkDist''
// EA  : 0x8338A460
// RVA : 0x0138A460
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_ct_checkDist__()
{
  idCVar::idCVar(
    this: &pm_ct_checkDist,
    name: "pm_ct_checkDist",
    value: "32.0f",
    flags: 4,
    description: "Forward distance to check for player model collision",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_ct_checkDist__);
}


// ========================================================================
// `dynamic initializer for 'pm_ct_push_decayOut''
// EA  : 0x8338A4B8
// RVA : 0x0138A4B8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_ct_push_decayOut__()
{
  idCVar::idCVar(
    this: &pm_ct_push_decayOut,
    name: "pm_ct_push_decayOut",
    value: "0.1f",
    flags: 4,
    description: "Player model decay out",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_ct_push_decayOut__);
}


// ========================================================================
// `dynamic initializer for 'pm_ct_push_decayIn''
// EA  : 0x8338A510
// RVA : 0x0138A510
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_ct_push_decayIn__()
{
  idCVar::idCVar(
    this: &pm_ct_push_decayIn,
    name: "pm_ct_push_decayIn",
    value: "0.1f",
    flags: 4,
    description: "Player Model decay in",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_ct_push_decayIn__);
}


// ========================================================================
// `dynamic initializer for 'pm_ct_push_dist''
// EA  : 0x8338A568
// RVA : 0x0138A568
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_ct_push_dist__()
{
  idCVar::idCVar(
    this: &pm_ct_push_dist,
    name: "pm_ct_push_dist",
    value: "25.0f",
    flags: 4,
    description: "Desired distance to keep clear infront of model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_ct_push_dist__);
}


// ========================================================================
// `dynamic initializer for 'pm_ct_jump_dist''
// EA  : 0x8338A5C0
// RVA : 0x0138A5C0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_ct_jump_dist__()
{
  idCVar::idCVar(
    this: &pm_ct_jump_dist,
    name: "pm_ct_jump_dist",
    value: "20.0f",
    flags: 4,
    description: "Desired distance to keep clear infront of model",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_ct_jump_dist__);
}


// ========================================================================
// `dynamic initializer for 'pm_fall_frames''
// EA  : 0x8338A618
// RVA : 0x0138A618
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_fall_frames__()
{
  idCVar::idCVar(
    this: &pm_fall_frames,
    name: "pm_fall_frames",
    value: "20",
    flags: 2,
    description: "Number of frames without ground contact before we play a fall animation",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_fall_frames__);
}


// ========================================================================
// `dynamic initializer for 'pm_trackPlayerPos''
// EA  : 0x8338A670
// RVA : 0x0138A670
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__pm_trackPlayerPos__()
{
  idCVar::idCVar(
    this: &pm_trackPlayerPos,
    name: "pm_trackPlayerPos",
    value: "0",
    flags: 2,
    description: "Draw spheres at player origin",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__pm_trackPlayerPos__);
}


// ========================================================================
// `dynamic initializer for 'p_setSpringCameraK''
// EA  : 0x8338A6C8
// RVA : 0x0138A6C8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_setSpringCameraK__()
{
  idCVar::idCVar(
    this: &p_setSpringCameraK,
    name: "p_setSpringCameraK",
    value: "0",
    flags: 4,
    description: "Set the spring camera spring constant",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_setSpringCameraK__);
}


// ========================================================================
// `dynamic initializer for 'dof_near''
// EA  : 0x8338A720
// RVA : 0x0138A720
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dof_near__()
{
  idCVar::idCVar(
    this: &dof_near,
    name: "dof_near",
    value: "0.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dof_near__);
}


// ========================================================================
// `dynamic initializer for 'dof_far''
// EA  : 0x8338A778
// RVA : 0x0138A778
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dof_far__()
{
  idCVar::idCVar(
    this: &dof_far,
    name: "dof_far",
    value: "100000.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dof_far__);
}


// ========================================================================
// `dynamic initializer for 'dof_focus''
// EA  : 0x8338A7D0
// RVA : 0x0138A7D0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dof_focus__()
{
  idCVar::idCVar(
    this: &dof_focus,
    name: "dof_focus",
    value: "-1.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dof_focus__);
}


// ========================================================================
// `dynamic initializer for 'dof_blur''
// EA  : 0x8338A828
// RVA : 0x0138A828
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dof_blur__()
{
  idCVar::idCVar(
    this: &dof_blur,
    name: "dof_blur",
    value: "0.35",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dof_blur__);
}


// ========================================================================
// `dynamic initializer for 'dof_useFocusScale''
// EA  : 0x8338A880
// RVA : 0x0138A880
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dof_useFocusScale__()
{
  idCVar::idCVar(
    this: &dof_useFocusScale,
    name: "dof_useFocusScale",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dof_useFocusScale__);
}


// ========================================================================
// `dynamic initializer for 'dof_focusScale''
// EA  : 0x8338A8D8
// RVA : 0x0138A8D8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dof_focusScale__()
{
  idCVar::idCVar(
    this: &dof_focusScale,
    name: "dof_focusScale",
    value: "2.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dof_focusScale__);
}


// ========================================================================
// `dynamic initializer for 'dof_lerpPerFrame''
// EA  : 0x8338A930
// RVA : 0x0138A930
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__dof_lerpPerFrame__()
{
  idCVar::idCVar(
    this: &dof_lerpPerFrame,
    name: "dof_lerpPerFrame",
    value: "0.1",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__dof_lerpPerFrame__);
}


// ========================================================================
// `dynamic initializer for 'player_LootCheck''
// EA  : 0x8338A988
// RVA : 0x0138A988
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_LootCheck__()
{
  idCVar::idCVar(
    this: &player_LootCheck,
    name: "player_LootCheck",
    value: "250.0",
    flags: 4,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_LootCheck__);
}


// ========================================================================
// `dynamic initializer for 'player_showHealth''
// EA  : 0x8338A9E0
// RVA : 0x0138A9E0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_showHealth__()
{
  idCVar::idCVar(
    this: &player_showHealth,
    name: "player_showHealth",
    value: "0",
    flags: 1,
    description: "spam current player health to the console",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_showHealth__);
}


// ========================================================================
// `dynamic initializer for 'player_vehicleDamageMult''
// EA  : 0x8338AA38
// RVA : 0x0138AA38
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_vehicleDamageMult__()
{
  idCVar::idCVar(
    this: &player_vehicleDamageMult,
    name: "player_vehicleDamageMult",
    value: "1.5",
    flags: 4,
    description: "Damage multiplier for player so he goes to dead state rather than fly out of the map.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_vehicleDamageMult__);
}


// ========================================================================
// `dynamic initializer for 'p_debugHudForegroundR''
// EA  : 0x8338AA90
// RVA : 0x0138AA90
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_debugHudForegroundR__()
{
  idCVar::idCVar(
    this: &p_debugHudForegroundR,
    name: "p_debugHudForegroundR",
    value: "1.00",
    flags: 4,
    description: "player debug hud foreground R component",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_debugHudForegroundR__);
}


// ========================================================================
// `dynamic initializer for 'p_debugHudForegroundG''
// EA  : 0x8338AAE8
// RVA : 0x0138AAE8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_debugHudForegroundG__()
{
  idCVar::idCVar(
    this: &p_debugHudForegroundG,
    name: "p_debugHudForegroundG",
    value: "1.00",
    flags: 4,
    description: "player debug hud foreground G component",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_debugHudForegroundG__);
}


// ========================================================================
// `dynamic initializer for 'p_debugHudForegroundB''
// EA  : 0x8338AB40
// RVA : 0x0138AB40
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_debugHudForegroundB__()
{
  idCVar::idCVar(
    this: &p_debugHudForegroundB,
    name: "p_debugHudForegroundB",
    value: "0.00",
    flags: 4,
    description: "player debug hud foreground B component",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_debugHudForegroundB__);
}


// ========================================================================
// `dynamic initializer for 'p_debugHudForegroundA''
// EA  : 0x8338AB98
// RVA : 0x0138AB98
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_debugHudForegroundA__()
{
  idCVar::idCVar(
    this: &p_debugHudForegroundA,
    name: "p_debugHudForegroundA",
    value: "1.00",
    flags: 4,
    description: "player debug hud foreground A component",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_debugHudForegroundA__);
}


// ========================================================================
// `dynamic initializer for 'p_debugHudBackgroundR''
// EA  : 0x8338ABF0
// RVA : 0x0138ABF0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_debugHudBackgroundR__()
{
  idCVar::idCVar(
    this: &p_debugHudBackgroundR,
    name: "p_debugHudBackgroundR",
    value: "0.25",
    flags: 4,
    description: "player debug hud background R component",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_debugHudBackgroundR__);
}


// ========================================================================
// `dynamic initializer for 'p_debugHudBackgroundG''
// EA  : 0x8338AC48
// RVA : 0x0138AC48
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_debugHudBackgroundG__()
{
  idCVar::idCVar(
    this: &p_debugHudBackgroundG,
    name: "p_debugHudBackgroundG",
    value: "0.25",
    flags: 4,
    description: "player debug hud background G component",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_debugHudBackgroundG__);
}


// ========================================================================
// `dynamic initializer for 'p_debugHudBackgroundB''
// EA  : 0x8338ACA0
// RVA : 0x0138ACA0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_debugHudBackgroundB__()
{
  idCVar::idCVar(
    this: &p_debugHudBackgroundB,
    name: "p_debugHudBackgroundB",
    value: "0.25",
    flags: 4,
    description: "player debug hud background B component",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_debugHudBackgroundB__);
}


// ========================================================================
// `dynamic initializer for 'p_debugHudBackgroundA''
// EA  : 0x8338ACF8
// RVA : 0x0138ACF8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__p_debugHudBackgroundA__()
{
  idCVar::idCVar(
    this: &p_debugHudBackgroundA,
    name: "p_debugHudBackgroundA",
    value: "1.00",
    flags: 4,
    description: "player debug hud background A component",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__p_debugHudBackgroundA__);
}


// ========================================================================
// `dynamic initializer for 'player_difficultyDamageScaleEasy''
// EA  : 0x8338AD50
// RVA : 0x0138AD50
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_difficultyDamageScaleEasy__()
{
  idCVar::idCVar(
    this: &player_difficultyDamageScaleEasy,
    name: "player_difficultyDamageScaleEasy",
    value: "0.5",
    flags: 4,
    description: "how much to scale incoming damage on easy if there is no easy damage table",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_difficultyDamageScaleEasy__);
}


// ========================================================================
// `dynamic initializer for 'player_difficultyDamageScaleMedium''
// EA  : 0x8338ADA8
// RVA : 0x0138ADA8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_difficultyDamageScaleMedium__()
{
  idCVar::idCVar(
    this: &player_difficultyDamageScaleMedium,
    name: "player_difficultyDamageScaleMedium",
    value: "1.0",
    flags: 4,
    description: "how much to scale incoming damage on medium if there is no normal damage table",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_difficultyDamageScaleMedium__);
}


// ========================================================================
// `dynamic initializer for 'player_difficultyDamageScaleHard''
// EA  : 0x8338AE00
// RVA : 0x0138AE00
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_difficultyDamageScaleHard__()
{
  idCVar::idCVar(
    this: &player_difficultyDamageScaleHard,
    name: "player_difficultyDamageScaleHard",
    value: "1.25",
    flags: 4,
    description: "how much to scale incoming damage on hard if there is no hard damage table",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_difficultyDamageScaleHard__);
}


// ========================================================================
// `dynamic initializer for 'player_difficultyDamageScaleNightmare''
// EA  : 0x8338AE58
// RVA : 0x0138AE58
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__player_difficultyDamageScaleNightmare__()
{
  idCVar::idCVar(
    this: &player_difficultyDamageScaleNightmare,
    name: "player_difficultyDamageScaleNightmare",
    value: "1.5",
    flags: 4,
    description: "how much to scale incoming damage on nightmare if there is no nightmare damage table",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__player_difficultyDamageScaleNightmare__);
}


// ========================================================================
// `dynamic initializer for 'vis_dumpCoverInfo''
// EA  : 0x8338AEB0
// RVA : 0x0138AEB0
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vis_dumpCoverInfo__()
{
  idCVar::idCVar(
    this: &vis_dumpCoverInfo,
    name: "vis_dumpCoverInfo",
    value: "0",
    flags: 2,
    description: " >= 1: Dump CoverInfo when generated. 2: Output number of cover points occluded by pvs  3: Draw bounds used by pvs. "
    " Use negative values for client players",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vis_dumpCoverInfo__);
}


// ========================================================================
// `dynamic initializer for 'vis_showPlayerCoverLineChecks''
// EA  : 0x8338AF08
// RVA : 0x0138AF08
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vis_showPlayerCoverLineChecks__()
{
  idCVar::idCVar(
    this: &vis_showPlayerCoverLineChecks,
    name: "vis_showPlayerCoverLineChecks",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vis_showPlayerCoverLineChecks__);
}


// ========================================================================
// `dynamic initializer for 'g_usePlayerCoverCheck''
// EA  : 0x8338AF60
// RVA : 0x0138AF60
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_usePlayerCoverCheck__()
{
  idCVar::idCVar(
    this: &g_usePlayerCoverCheck,
    name: "g_usePlayerCoverCheck",
    value: "1",
    flags: 1,
    description: "usePlayerCoverCheck",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_usePlayerCoverCheck__);
}


// ========================================================================
// `dynamic initializer for 'vis_showCoverNum''
// EA  : 0x8338AFB8
// RVA : 0x0138AFB8
// PDB : w:\tech5\tungsten\game\player\player.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vis_showCoverNum__()
{
  idCVar::idCVar(
    this: &vis_showCoverNum,
    name: "vis_showCoverNum",
    value: "-1",
    flags: 2,
    description: "show vis for given aas cover num only",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vis_showCoverNum__);
}

