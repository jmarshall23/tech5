
// ========================================================================
// ?StringForPresentableType@@YAPBDW4presentableType_t@@@Z
// EA  : 0x82B4AE80
// RVA : 0x00B4AE80
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

const char *__fastcall StringForPresentableType(presentableType_t presentableType)
{
  const char *result; // r3

  switch ( presentableType )
  {
    case PRESENTABLE_GENERIC:
      result = "PRESENTABLE_GENERIC";
      break;
    case PRESENTABLE_RENDERMODEL:
      result = "PRESENTABLE_RENDERMODEL";
      break;
    case PRESENTABLE_ANIMATED_ENTITY:
      result = "PRESENTABLE_ANIMATED_ENTITY";
      break;
    case PRESENTABLE_VEHICLE:
      result = "PRESENTABLE_VEHICLE";
      break;
    case PRESENTABLE_BREAKABLE:
      result = "PRESENTABLE_BREAKABLE";
      break;
    case PRESENTABLE_PIECE_EMITTER:
      result = "PRESENTABLE_PIECE_EMITTER";
      break;
    case PRESENTABLE_DAMAGEABLE:
      result = "PRESENTABLE_DAMAGEABLE";
      break;
    case PRESENTABLE_ACTOR:
      result = "PRESENTABLE_ACTOR";
      break;
    case PRESENTABLE_PLAYER:
      result = "PRESENTABLE_PLAYER";
      break;
    case PRESENTABLE_PROJECTILE:
      result = "PRESENTABLE_PROJECTILE";
      break;
    case PRESENTABLE_PROJECTILE_GRENADE:
      result = "PRESENTABLE_PROJECTILE_GRENADE";
      break;
    case PRESENTABLE_PROJECTILE_ROCKET:
      result = "PRESENTABLE_PROJECTILE_ROCKET";
      break;
    case PRESENTABLE_PROJECTILE_HOMING:
      result = "PRESENTABLE_PROJECTILE_HOMING";
      break;
    case PRESENTABLE_MULTIPLAYER_TRIGGER:
      result = "PRESENTABLE_MULTIPLAYER_TRIGGER";
      break;
    case PRESENTABLE_AI:
      result = "PRESENTABLE_AI";
      break;
    case PRESENTABLE_PROP:
      result = "PRESENTABLE_PROP";
      break;
    case PRESENTABLE_WEAPON_STATIC:
      result = "PRESENTABLE_WEAPON_STATIC";
      break;
    case PRESENTABLE_DOOR_ANIMATED:
      result = "PRESENTABLE_DOOR_ANIMATED";
      break;
    case PRESENTABLE_WEAPON:
      result = "PRESENTABLE_WEAPON";
      break;
    case PRESENTABLE_PARTICLE_EMITTER:
      result = "PRESENTABLE_PARTICLE_EMITTER";
      break;
    case PRESENTABLE_COLLISION_TRIGGER:
      result = "PRESENTABLE_COLLISION_TRIGGER";
      break;
    default:
      result = "Unknown presentable";
      break;
  }
  return result;
}


// ========================================================================
// ?SetServerGameTime@idClientGame@@QAAXH@Z
// EA  : 0x82B4B020
// RVA : 0x00B4B020
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::SetServerGameTime(idClientGame *this, int time)
{
  int serverTime; // r8

  serverTime = this->serverTime;
  this->serverTime = time;
  this->previousServerTime = serverTime;
}


// ========================================================================
// ?GetServerGameTime@idClientGame@@QBAHXZ
// EA  : 0x82B4B040
// RVA : 0x00B4B040
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::GetServerGameTime(idClientGame *this)
{
  return this->serverTime;
}


// ========================================================================
// ?GetPreviousServerGameTime@idClientGame@@QBAHXZ
// EA  : 0x82B4B050
// RVA : 0x00B4B050
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::GetPreviousServerGameTime(idClientGame *this)
{
  return this->previousServerTime;
}


// ========================================================================
// ??1idPlayerTimeLock@@QAA@XZ
// EA  : 0x82B4B060
// RVA : 0x00B4B060
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idPlayerTimeLock::~idPlayerTimeLock(idPlayerTimeLock *this)
{
  clientGame->playerTime = this->lastTime;
}


// ========================================================================
// ?GetPresentableByIndex@idClientGame@@QBAPAVidPresentable@@H@Z
// EA  : 0x82B4B258
// RVA : 0x00B4B258
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idPresentable *__fastcall idClientGame::GetPresentableByIndex(idClientGame *this, int index)
{
  return this->presentables.list[index];
}


// ========================================================================
// ?IsPresentableIndexValid@idClientGame@@QBA_NH@Z
// EA  : 0x82B4B270
// RVA : 0x00B4B270
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

BOOL __fastcall idClientGame::IsPresentableIndexValid(idClientGame *this, int index)
{
  return index >= 0 && index < this->presentables.num && this->presentables.list[index] != nullptr;
}


// ========================================================================
// ?FindPlayerPresentableByIndex@idClientGame@@QBAPAVidPresentablePlayer@@H@Z
// EA  : 0x82B4B2B8
// RVA : 0x00B4B2B8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idPresentablePlayer *__fastcall idClientGame::FindPlayerPresentableByIndex(idClientGame *this, int playerNum)
{
  idPresentable *v2; // r3

  if ( playerNum < this->presentables.num && playerNum >= 0 && (v2 = this->presentables.list[playerNum]) != nullptr )
    return v2->GetPlayerInterface_2(this: v2);
  else
    return nullptr;
}


// ========================================================================
// ?GetLobbyUserIdFromPlayerIndex@idClientGame@@QBA?AUlobbyUserID_t@@H@Z
// EA  : 0x82B4B308
// RVA : 0x00B4B308
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idClientGame *__fastcall idClientGame::GetLobbyUserIdFromPlayerIndex(
        idClientGame *this,
        lobbyUserID_t *result,
        int playerIndex)
{
  lobbyUserID_t *v3; // r11
  idRenderWorld *handle; // r8

  v3 = &result[playerIndex];
  handle = (idRenderWorld *)v3[63038].localUserHandle.handle;
  this->random.seed = *(_DWORD *)&v3[63037].lobbyType;
  this->renderWorld = handle;
  return this;
}


// ========================================================================
// ?SetLobbyUserIdForPlayerIndex@idClientGame@@QAAXHUlobbyUserID_t@@@Z
// EA  : 0x82B4B330
// RVA : 0x00B4B330
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::SetLobbyUserIdForPlayerIndex(idClientGame *this, __int64 lobbyUserID)
{
  this->lobbyUserIDs.ptr[HIDWORD(lobbyUserID)] = (lobbyUserID_t)lobbyUserID;
}


// ========================================================================
// ?GetProfileFromPlayerIndex@idClientGame@@QBAPAVidPlayerProfile@@H@Z
// EA  : 0x82B4B348
// RVA : 0x00B4B348
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::GetProfileFromPlayerIndex(idClientGame *this, int index)
{
  idLobbyBase *v3; // r3

  v3 = session->GetActingGameStateLobbyBase(this: session);
  if ( ((int (*)(void))v3->GetProfileFromLobbyUser)() == 0 )
    idLib::Error(fmt: "SessionUser %i profile is NULL", index);
}


// ========================================================================
// ?GetLocalUserFromPlayerIndex@idClientGame@@QBAPAVidLocalUser@@H@Z
// EA  : 0x82B4B3D0
// RVA : 0x00B4B3D0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idLocalUser *__fastcall idClientGame::GetLocalUserFromPlayerIndex(idClientGame *this, int index)
{
  lobbyUserID_t *v2; // r31 OVERLAPPED
  int v3; // r30
  char v4; // r11
  idLobbyBase *v6; // r3

  *(lobbyUserID_t *)&v2 = this->lobbyUserIDs.ptr[index];
  if ( v3 == 0 || (v4 = 1, HIBYTE(v2) == 255) )
    v4 = 0;
  if ( v4 == 0 )
    return nullptr;
  v6 = session->GetActingGameStateLobbyBase(this: session);
  return v6->GetLocalUserFromLobbyUser(this: v6, a2: v2);
}


// ========================================================================
// ?PlayerIndexIsLocal@idClientGame@@QBA_NH@Z
// EA  : 0x82B4B480
// RVA : 0x00B4B480
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::PlayerIndexIsLocal(idClientGame *this, int playerNum)
{
  int v2; // r10
  idArray<int,4> *i; // r11

  v2 = 0;
  for ( i = &this->inputToPlayerIndexRouting; i->ptr[0] != playerNum; i = (idArray<int,4> *)((char *)i + 4) )
  {
    if ( ++v2 >= 4 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?SubmitEffectPhysicsCollisionQueries@idClientGame@@QAAXXZ
// EA  : 0x82B4B4B8
// RVA : 0x00B4B4B8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::SubmitEffectPhysicsCollisionQueries(idClientGame *this)
{
  int v2; // r31
  idList<idEffectPhysicsBroadPhase *,5> *p_simulatingEffectPhysics; // r29
  int v4; // r30

  v2 = 0;
  p_simulatingEffectPhysics = &gameLocal->simulatingEffectPhysics;
  if ( p_simulatingEffectPhysics->num > 0 )
  {
    v4 = 0;
    do
    {
      idEffectPhysicsBroadPhase::SubmitQueries(
        this: p_simulatingEffectPhysics->list[v4],
        worldCollisionModelOnly: this->vehicleRaceMap);
      ++v2;
      ++v4;
    }
    while ( v2 < p_simulatingEffectPhysics->num );
  }
}


// ========================================================================
// ?InternalGetMergeBranch@idAnimator_BlendEq@@MAAPAVidMD6Branch@@XZ
// EA  : 0x82B4B518
// RVA : 0x00B4B518
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

const idMD6Branch *__fastcall idAnimator_BlendEq::InternalGetMergeBranch(idAnimator_BlendEq *this)
{
  return this->mergeBranch;
}


// ========================================================================
// ?GetFlags@idParser@@QBAHXZ
// EA  : 0x82B4B520
// RVA : 0x00B4B520
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idRenderModelDecal *__fastcall idParser::GetFlags(idClientGame *this)
{
  return this->gameLibEffects.decalModel;
}


// ========================================================================
// ?GetDeferredDecalMgr@idClientGame@@QAAPAVidDeferredDecalManager@@XZ
// EA  : 0x82B4B528
// RVA : 0x00B4B528
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idDeferredDecalManager *__fastcall idClientGame::GetDeferredDecalMgr(idClientGame *this)
{
  return &this->gameLibEffects.deferredDecalManager;
}


// ========================================================================
// ?GetWeaponTraceMgr@idClientGame@@QAAPAVidWeaponTraceManager@@XZ
// EA  : 0x82B4B530
// RVA : 0x00B4B530
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idWeaponTraceManager *__fastcall idClientGame::GetWeaponTraceMgr(idClientGame *this)
{
  return &this->gameLibEffects.weaponTraceManager;
}


// ========================================================================
// ?GetWeaponImpactMgr@idClientGame@@QAAPAVidImpactManager@@XZ
// EA  : 0x82B4B538
// RVA : 0x00B4B538
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idImpactManager *__fastcall idClientGame::GetWeaponImpactMgr(idClientGame *this)
{
  return &this->gameLibEffects.weaponImpactManager;
}


// ========================================================================
// ?GetAxis@idPhysics_Static@@UBAABVidMat3@@H@Z
// EA  : 0x82B4B540
// RVA : 0x00B4B540
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

const idMat3 *__fastcall idPhysics_Static::GetAxis(idPhysics_Static *this, int id)
{
  return &this->current.worldAxis;
}


// ========================================================================
// ?GetLocalViewForPlayerIndex@idClientGame@@QAAPAUlocalView_t@@H@Z
// EA  : 0x82B4B548
// RVA : 0x00B4B548
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

localView_t *__fastcall idClientGame::GetLocalViewForPlayerIndex(idClientGame *this, int playerNum)
{
  int v2; // r10
  idArray<int,4> *p_inputToPlayerIndexRouting; // r11
  char v4; // r11
  idPresentable *v5; // r3
  idPresentablePlayer *v6; // r3

  if ( playerNum == -1 )
    return nullptr;
  v2 = 0;
  p_inputToPlayerIndexRouting = &this->inputToPlayerIndexRouting;
  while ( p_inputToPlayerIndexRouting->ptr[0] != playerNum )
  {
    ++v2;
    p_inputToPlayerIndexRouting = (idArray<int,4> *)((char *)p_inputToPlayerIndexRouting + 4);
    if ( v2 >= 4 )
    {
      v4 = 0;
      goto LABEL_6;
    }
  }
  v4 = 1;
LABEL_6:
  if ( v4 != 0
    && playerNum < this->presentables.num
    && playerNum >= 0
    && (v5 = this->presentables.list[playerNum]) != nullptr
    && (v6 = v5->GetPlayerInterface_2(this: v5)) != nullptr )
  {
    return idPresentablePlayer::GetLocalView(this: v6);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?RenderLocalViewForPlayer@idClientGame@@QAAPAVidRenderModelGui@@HHPBUrenderView_t@@PAVidRenderWorld@@@Z
// EA  : 0x82B4B620
// RVA : 0x00B4B620
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idRenderModelGui *__fastcall idClientGame::RenderLocalViewForPlayer(
        idClientGame *this,
        int playerNum,
        unsigned __int64 view,
        idRenderWorld *rw)
{
  int v6; // r30
  int v7; // r25
  const renderView_t *v8; // r24
  idRenderModelGui *v10; // r3
  idRenderModelGui *v11; // r3
  idRenderModelGui *v12; // r30
  unsigned int v13; // r26
  unsigned int v14; // r3
  int v15; // r27
  __int64 v16; // r6
  int v17; // r9
  int v18; // r8
  int v19; // r7
  idPresentable *v20; // r3
  idPresentablePlayer *v21; // r3
  idPresentablePlayer *v22; // r26
  localView_t *LocalView; // r27
  __int64 v25; // [sp+8h] [-A8h]

  v6 = 4 * (playerNum + 127888);
  v7 = HIDWORD(view);
  v8 = (const renderView_t *)view;
  if ( *(unsigned int *)((char *)&this->random.seed + v6) == 0 )
  {
    v10 = (idRenderModelGui *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0xA410u,
                                tag: TAG_GUI_MODEL,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    if ( v10 != nullptr )
      v11 = idRenderModelGui::idRenderModelGui(this: v10);
    else
      v11 = nullptr;
    *(unsigned int *)((char *)&this->random.seed + v6) = (unsigned int)v11;
  }
  v12 = *(idRenderModelGui **)((char *)&this->random.seed + v6);
  idRenderModelGui::Clear(
    this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
    a2: defaultExtraGLState,
    bits: view,
    a4: (int)rw);
  v13 = renderSystem->GetHeight(this: renderSystem);
  v14 = renderSystem->GetWidth(this: renderSystem);
  idRenderModelGui::SetViewport(this: v12, x: 0, y: 0, width: v14, height: v13);
  renderSystem->GetWidth(this: renderSystem);
  v15 = renderSystem->GetHeight(this: renderSystem);
  renderSystem->GetPixelAspect(this: renderSystem);
  HIDWORD(v16) = v15;
  idRenderModelGui::SetVirtualSize(this: v12, height: v16, a3: v19, a4: v18, a5: v17, a6: v25);
  if ( playerNum < this->presentables.num && playerNum >= 0 )
  {
    v20 = this->presentables.list[playerNum];
    if ( v20 != nullptr )
    {
      v21 = v20->GetPlayerInterface_2(this: v20);
      v22 = v21;
      if ( v21 != nullptr )
      {
        LocalView = idPresentablePlayer::GetLocalView(this: v21);
        if ( LocalView != nullptr && !idPresentablePlayer::GuiIsActive(this: v22, g: GUI_SIDEMISSION) )
        {
          idPlayerHud_Render::SetPlayerNum(this: &LocalView->hudRender, p: playerNum);
          idPlayerHud_Render::Render(
            this: &LocalView->hudRender,
            guiModel: v12,
            current: &v22->hudInfo,
            currentTime: v7,
            renderView: v8,
            rw);
          idPlayerGuis_Render::SetPlayerNum(this: &LocalView->guisRender, p: playerNum);
          idPlayerGuis_Render::Render(this: &LocalView->guisRender, guiModel: v12, currentTime: v7, renderView: v8, rw);
        }
      }
    }
  }
  return v12;
}


// ========================================================================
// __unwind$494525
// EA  : 0x82B4B864
// RVA : 0x00B4B864
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_494525()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 176 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// ?HandleGuiEventForPlayer@idClientGame@@QAA_NHPBUsysEvent_t@@@Z
// EA  : 0x82B4B890
// RVA : 0x00B4B890
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

BOOL __fastcall idClientGame::HandleGuiEventForPlayer(idClientGame *this, int playerNum, const sysEvent_t *ev)
{
  localView_t *LocalViewForPlayerIndex; // r28
  idPresentable *v7; // r3
  idPresentablePlayer *v8; // r3

  LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(this, playerNum);
  if ( LocalViewForPlayerIndex == nullptr )
    return false;
  if ( playerNum < this->presentables.num && playerNum >= 0 && (v7 = this->presentables.list[playerNum]) != nullptr )
    v8 = v7->GetPlayerInterface_2(this: v7);
  else
    v8 = nullptr;
  return idPresentablePlayer::HandleGuiEvent(this: v8, ev)
      || idPlayerGuis_Render::HandleGuiEvent(this: &LocalViewForPlayerIndex->guisRender, ev)
      || idPlayerHud_Render::HandleGuiEvent(this: &LocalViewForPlayerIndex->hudRender, ev);
}


// ========================================================================
// ?IsPlayerControlInhibited@idClientGame@@QBA_NH@Z
// EA  : 0x82B4B960
// RVA : 0x00B4B960
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

BOOL __fastcall idClientGame::IsPlayerControlInhibited(idClientGame *this, int playerNum)
{
  idPresentable *v2; // r3
  idPresentablePlayer *v3; // r3

  return playerNum < this->presentables.num
      && playerNum >= 0
      && (v2 = this->presentables.list[playerNum]) != nullptr
      && (v3 = v2->GetPlayerInterface_2(this: v2)) != nullptr
      && idPresentablePlayer::IsPlayerControlInhibited(this: v3);
}


// ========================================================================
// ?HandleReliableGuiMsg@idClientGame@@QAAXHAAVidBitMsg@@@Z
// EA  : 0x82B4B9E8
// RVA : 0x00B4B9E8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleReliableGuiMsg(idClientGame *this, int type, idBitMsg *msg)
{
  int v6; // r31
  int v7; // r10
  idArray<int,4> *p_inputToPlayerIndexRouting; // r11
  char v9; // r11
  idPresentable *v10; // r3
  idPresentablePlayer *v11; // r3
  localView_t *LocalView; // r3

  v6 = 0;
  while ( 1 )
  {
    if ( v6 != -1 )
    {
      v7 = 0;
      p_inputToPlayerIndexRouting = &this->inputToPlayerIndexRouting;
      while ( p_inputToPlayerIndexRouting->ptr[0] != v6 )
      {
        ++v7;
        p_inputToPlayerIndexRouting = (idArray<int,4> *)((char *)p_inputToPlayerIndexRouting + 4);
        if ( v7 >= 4 )
        {
          v9 = 0;
          goto LABEL_7;
        }
      }
      v9 = 1;
LABEL_7:
      if ( v9 != 0 && v6 < this->presentables.num && v6 >= 0 )
      {
        v10 = this->presentables.list[v6];
        if ( v10 != nullptr )
        {
          v11 = v10->GetPlayerInterface_2(this: v10);
          if ( v11 != nullptr )
          {
            LocalView = idPresentablePlayer::GetLocalView(this: v11);
            if ( LocalView != nullptr )
              break;
          }
        }
      }
    }
    if ( ++v6 >= 6 )
      return;
  }
  idPlayerGuis_Render::HandleReliableGuiMsg(this: &LocalView->guisRender, type, msg);
}


// ========================================================================
// ?SendGameEventReliable_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82B4BAD8
// RVA : 0x00B4BAD8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall SendGameEventReliable_f(const idCmdArgs *args)
{
  const char *v2; // r3
  int v3; // r30
  const char *v4; // r3
  int v5; // r31

  if ( args->argc <= 1 )
    v2 = &byte_8200D768;
  else
    v2 = args->argv[1];
  v3 = atol(nptr: v2);
  if ( args->argc <= 2 )
    v4 = &byte_8200D768;
  else
    v4 = args->argv[2];
  v5 = atol(nptr: v4);
  if ( v3 >= 40 )
    idLib::Printf(fmt: "Event is outside legal range");
  idGameLocal::BroadcastUIStatusMessage(
    this: gameLocal,
    type: v3,
    numParams: 2,
    param1: v5,
    param2: 0,
    param3: -1,
    param4: -1);
}


// ========================================================================
// ?HandlePlayerMetricsMsg@idClientGame@@QAAXAAVidBitMsg@@@Z
// EA  : 0x82B4BB70
// RVA : 0x00B4BB70
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandlePlayerMetricsMsg(idClientGame *this, idBitMsg *msg)
{
  int Bits; // r31
  BOOL v5; // r26
  idRageMetrics *rageMetrics; // r29
  idLocalUser *LocalUserFromPlayerIndex; // r27
  idMainMenu *mainMenu; // r3

  if ( com_multiplayer.valueInteger != 0 )
  {
    Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
    v5 = (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0;
    rageMetrics = clientGame->rageMetrics;
    LocalUserFromPlayerIndex = idClientGame::GetLocalUserFromPlayerIndex(this, index: Bits);
    if ( v5 )
    {
      idRageMetrics::HandlePlayerMetricsMsg(this: rageMetrics, msg, playerId: Bits);
      idAchievementManager::CheckClientRequirements(user: LocalUserFromPlayerIndex);
      if ( gameLocal != nullptr )
      {
        mainMenu = gameLocal->mainMenu;
        if ( mainMenu != nullptr )
          idMainMenu::UpdateMatchResults(
            this: mainMenu,
            playerId: this->lobbyUserIDs.ptr[Bits].localUserHandle.handle,
            lobbyUserID: *(lobbyUserID_t **)&this->lobbyUserIDs.ptr[Bits].lobbyType);
      }
    }
    else
    {
      idRageMetrics::HandlePlayerUnlockMetricsMsg(this: rageMetrics, msg, playerId: Bits);
    }
    if ( LocalUserFromPlayerIndex != nullptr )
      idLocalUser::SaveProfileSettings(this: LocalUserFromPlayerIndex);
  }
}


// ========================================================================
// ?HandleVehiclePickupMsg@idClientGame@@QAAXAAVidBitMsg@@@Z
// EA  : 0x82B4BC70
// RVA : 0x00B4BC70
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleVehiclePickupMsg(idClientGame *this, idBitMsg *msg)
{
  int Bits; // r24
  localView_t *LocalViewForPlayerIndex; // r3
  idStr v6; // [sp+50h] [-90h] BYREF
  idStr v7[3]; // [sp+70h] [-70h] BYREF

  Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  idBitMsg::ReadBits(this: msg, numBits: 8);
  idBitMsg::ReadBits(this: msg, numBits: 32);
  v7[0].len = 0;
  v7[0].allocedAndFlag = 20;
  v7[0].data = v7[0].baseBuffer;
  v7[0].baseBuffer[0] = 0;
  idBitMsg::ReadString(this: msg, str: v7);
  v6.allocedAndFlag = 20;
  v6.data = v6.baseBuffer;
  v6.len = 0;
  v6.baseBuffer[0] = 0;
  idBitMsg::ReadString(this: msg, str: &v6);
  LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: Bits);
  if ( LocalViewForPlayerIndex != nullptr )
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalViewForPlayerIndex->hudRender);
  idStr::FreeData(this: &v6);
  idStr::FreeData(this: v7);
}


// ========================================================================
// __unwind$494757
// EA  : 0x82B4BD44
// RVA : 0x00B4BD44
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_494757()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$494758
// EA  : 0x82B4BD6C
// RVA : 0x00B4BD6C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_494758()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 80));
}


// ========================================================================
// ?GetObjectList@idClientGame@@QAAPAPAVidClass@@XZ
// EA  : 0x82B4BD98
// RVA : 0x00B4BD98
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idClass **__fastcall idClientGame::GetObjectList(idClientGame *this)
{
  return this->objectList.list;
}


// ========================================================================
// ?GetObjectListSize@idClientGame@@QAAHXZ
// EA  : 0x82B4BDA8
// RVA : 0x00B4BDA8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::GetObjectListSize(idClientGame *this)
{
  return this->objectList.num;
}


// ========================================================================
// ?CalcHitscanDamageScale@idClientGame@@QBAMPBVidDeclProjectile@@MPBVidPresentable@@ABVidVec3@@@Z
// EA  : 0x82B4BDB8
// RVA : 0x00B4BDB8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

float __fastcall idClientGame::CalcHitscanDamageScale(
        idClientGame *this,
        const idDeclProjectile *projDef,
        double startDamageScale,
        const idPresentable *attacker,
        const idVec3 *hitOrigin,
        float *a6,
        __int64 a7)
{
  double v7; // fp8
  double v8; // fp5
  double v9; // fp2

  LODWORD(a7) = projDef->maxRange;
  if ( projDef->damageFalloff < 1.0 )
  {
    v7 = (float)(a6[2] - hitOrigin[10].z);
    v8 = (float)(*a6 - hitOrigin[10].x);
    v9 = (float)(a6[1] - hitOrigin[10].y);
    if ( (float)((float)((float)v9 * (float)v9)
               + (float)((float)((float)v8 * (float)v8) + (float)((float)v7 * (float)v7))) > (double)(float)((float)(projDef->damageFalloff * (float)a7) * (float)(projDef->damageFalloff * (float)a7)) )
    {
      _FP10 = (float)((float)__fabs((float)((float)((float)((float)((float)v9 * (float)v9)
                                                          + (float)((float)((float)v8 * (float)v8)
                                                                  + (float)((float)v7 * (float)v7)))
                                                  / (float)((float)a7 * (float)a7))
                                          - (float)1.0))
                    - (float)startDamageScale);
      __asm { fsel      f1, f10, f1, f11 }
    }
  }
  return *((float *)&startDamageScale + 1);
}


// ========================================================================
// ?GetRandomSpreadTraceDir@idClientGame@@QAA?AVidVec3@@ABVidFireParms@@@Z
// EA  : 0x82B4BE40
// RVA : 0x00B4BE40
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idClientGame *__fastcall idClientGame::GetRandomSpreadTraceDir(idClientGame *this, __int64 fp, long double a3)
{
  idRandom2 *v4; // r29
  float *v5; // r31
  double v6; // fp13
  double v7; // fp31
  long double v8; // fp2
  __int64 v9; // r6
  double v10; // fp30
  long double v11; // fp2
  long double v12; // fp2
  double v13; // fp31
  __int64 v14; // r6
  double v15; // fp1
  double v17; // fp3
  double v18; // fp11
  double v19; // fp1
  double v22; // fp4
  double v23; // fp7
  double v24; // fp4
  int v25; // r8
  long double v26; // fp2
  double v27; // fp31
  int v28; // r11
  double v29; // fp9
  __int64 v30; // r8
  double v31; // fp30
  long double v32; // fp2
  double v33; // fp13
  double v34; // fp30
  double v35; // fp29
  double v36; // fp28
  double v38; // fp10
  double v39; // fp9
  double v40; // fp8
  double v42; // fp4

  v4 = (idRandom2 *)HIDWORD(fp);
  v5 = (float *)fp;
  v6 = (float)((float)(*(float *)(*(_DWORD *)(fp + 116) + 492) + *(float *)(fp + 136)) * idMath::M_DEG2RAD);
  if ( g_useGaussianWeaponSpread.valueInteger != 0 )
  {
    v7 = (float)((float)(*(float *)(*(_DWORD *)(fp + 116) + 492) + *(float *)(fp + 136)) * idMath::M_DEG2RAD);
    *(double *)&a3 = v7;
    v8 = sin(x: a3);
    v10 = (float)(idRandom2::BellCurve(this: v4, degree: v9) * (float)*(double *)&v8);
    *(double *)&v11 = v7;
    v12 = sin(x: v11);
    v13 = (float)*(double *)&v12;
    v15 = idRandom2::BellCurve(this: v4, degree: v14);
    v17 = (float)((float)(v5[21] + (float)(v5[27] * (float)((float)v15 * (float)v13))) - (float)(v5[24] * (float)v10));
    v18 = (float)((float)((float)((float)((float)v15 * (float)v13) * v5[26]) + v5[20]) - (float)((float)v10 * v5[23]));
    v19 = (float)((float)(v5[22] + (float)(v5[28] * (float)((float)v15 * (float)v13))) - (float)(v5[25] * (float)v10));
    _FP7 = (float)((float)((float)((float)v18 * (float)v18)
                         + (float)((float)((float)v19 * (float)v19) + (float)((float)v17 * (float)v17)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f5, f7, f8, f13 }
    v22 = __frsqrte(_FP5);
    v23 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v17 * (float)v17)))
                                                                                                * (float)0.5))
                                                                                * (float)v22)
                                                                        - (float)1.5)
                                                        * (float)v22)
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)((float)v19 * (float)v19)
                                                                        + (float)((float)v17 * (float)v17)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                                                + (float)((float)((float)v19 * (float)v19) + (float)((float)v17 * (float)v17)))
                                                                                        * (float)0.5))
                                                                        * (float)v22)
                                                                - (float)1.5)
                                                * (float)v22))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v22
                                                        * (float)((float)((float)((float)v18 * (float)v18)
                                                                        + (float)((float)((float)v19 * (float)v19)
                                                                                + (float)((float)v17 * (float)v17)))
                                                                * (float)0.5))
                                                * (float)v22)
                                        - (float)1.5)
                        * (float)v22));
    v24 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v17 * (float)v17))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                                * (float)v22)
                                                                                        * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v17 * (float)v17)))
                                                                                                * (float)0.5))
                                                                                * (float)((float)-(float)((float)((float)((float)v22 * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v17 * (float)v17))) * (float)0.5)) * (float)v22) - (float)1.5)
                                                                                        * (float)v22))
                                                                        - (float)1.5)
                                                        * (float)((float)-(float)((float)((float)((float)v22
                                                                                                * (float)((float)((float)((float)v18 * (float)v18) + (float)((float)((float)v19 * (float)v19) + (float)((float)v17 * (float)v17))) * (float)0.5))
                                                                                        * (float)v22)
                                                                                - (float)1.5)
                                                                * (float)v22))
                                                * (float)((float)((float)((float)v18 * (float)v18)
                                                                + (float)((float)((float)v19 * (float)v19)
                                                                        + (float)((float)v17 * (float)v17)))
                                                        * (float)0.5))
                                        * (float)v23)
                                - (float)1.5)
                * (float)v23);
    *(float *)&this->random.seed = (float)v18 * (float)v24;
    *(float *)&this->renderWorld = (float)v17 * (float)v24;
    *(float *)&this->soundWorld = (float)v19 * (float)v24;
  }
  else
  {
    v25 = 1664525 * *(_DWORD *)HIDWORD(fp);
    LODWORD(fp) = ((unsigned int)(v25 + 1013904223) >> 10) & 0x7FFF;
    *(_DWORD *)HIDWORD(fp) = v25 + 1013904223;
    *(double *)&a3 = (float)((float)((float)fp * (float)0.000030518509) * (float)v6);
    v26 = sin(x: a3);
    v27 = (float)*(double *)&v26;
    v28 = 1664525 * v4->seed;
    v29 = (float)(idMath::M_DEG2RAD * (float)360.0);
    LODWORD(v30) = ((unsigned int)(v28 + 1013904223) >> 10) & 0x7FFF;
    v4->seed = v28 + 1013904223;
    v31 = (float)((float)((float)v30 * (float)v29) * (float)0.000030518509);
    *(double *)&v26 = v31;
    v32 = cos(x: v26);
    *((double *)&v32 + 1) = v5[24];
    v33 = (float)((float)*(double *)&v32 * (float)v27);
    *(double *)&v32 = v31;
    v34 = (float)((float)v33 * v5[23]);
    v35 = (float)(v5[24] * (float)v33);
    v36 = (float)(v5[25] * (float)v33);
    _FP2 = sin(x: v32);
    v38 = (float)((float)(v5[21] + (float)(v5[27] * (float)((float)*(double *)&_FP2 * (float)v27))) - (float)v35);
    v39 = (float)((float)(v5[22] + (float)(v5[28] * (float)((float)*(double *)&_FP2 * (float)v27))) - (float)v36);
    v40 = (float)((float)((float)((float)((float)*(double *)&_FP2 * (float)v27) * v5[26]) + v5[20]) - (float)v34);
    _FP4 = (float)((float)((float)((float)v40 * (float)v40)
                         + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f5, f0 }
    *(double *)&_FP2 = __frsqrte(*((double *)&_FP2 + 1));
    v42 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)*(double *)&_FP2
                                                                                        * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))
                                                                                                * (float)0.5))
                                                                                * (float)*(double *)&_FP2)
                                                                        - (float)1.5)
                                                        * (float)*(double *)&_FP2)
                                                * (float)((float)((float)((float)v40 * (float)v40)
                                                                + (float)((float)((float)v39 * (float)v39)
                                                                        + (float)((float)v38 * (float)v38)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)*(double *)&_FP2
                                                                                * (float)((float)((float)((float)v40 * (float)v40)
                                                                                                + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)))
                                                                                        * (float)0.5))
                                                                        * (float)*(double *)&_FP2)
                                                                - (float)1.5)
                                                * (float)*(double *)&_FP2))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)*(double *)&_FP2
                                                        * (float)((float)((float)((float)v40 * (float)v40)
                                                                        + (float)((float)((float)v39 * (float)v39)
                                                                                + (float)((float)v38 * (float)v38)))
                                                                * (float)0.5))
                                                * (float)*(double *)&_FP2)
                                        - (float)1.5)
                        * (float)*(double *)&_FP2));
    *(double *)&_FP2 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)*(double *)&_FP2 * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38))) * (float)0.5)) * (float)*(double *)&_FP2) - (float)1.5) * (float)*(double *)&_FP2) * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38))) * (float)0.5))
                                                                                             * (float)((float)-(float)((float)((float)((float)*(double *)&_FP2 * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38))) * (float)0.5)) * (float)*(double *)&_FP2) - (float)1.5) * (float)*(double *)&_FP2))
                                                                                     - (float)1.5)
                                                                     * (float)((float)-(float)((float)((float)((float)*(double *)&_FP2 * (float)((float)((float)((float)v40 * (float)v40) + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38))) * (float)0.5)) * (float)*(double *)&_FP2)
                                                                                             - (float)1.5)
                                                                             * (float)*(double *)&_FP2))
                                                             * (float)((float)((float)((float)v40 * (float)v40)
                                                                             + (float)((float)((float)v39 * (float)v39)
                                                                                     + (float)((float)v38 * (float)v38)))
                                                                     * (float)0.5))
                                                     * (float)v42)
                                             - (float)1.5)
                             * (float)v42);
    *(float *)&this->random.seed = (float)v40 * (float)*(double *)&_FP2;
    *(float *)&this->renderWorld = (float)v38 * (float)*(double *)&_FP2;
    *(float *)&this->soundWorld = (float)v39 * (float)*(double *)&_FP2;
  }
  return this;
}


// ========================================================================
// ?GetPlayerPresentableCmds@idClientGame@@QAAHHQAPAVusercmd_t@@H@Z
// EA  : 0x82B4C130
// RVA : 0x00B4C130
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::GetPlayerPresentableCmds(idClientGame *this, int user, usercmd_t **buffer, int bufferSize)
{
  idPresentable *v6; // r3
  idPresentablePlayer *v7; // r3

  if ( user < this->presentables.num
    && (unsigned int)user <= 5
    && (v6 = this->presentables.list[user]) != nullptr
    && (v7 = v6->GetPlayerInterface_2(this: v6)) != nullptr )
  {
    return idPresentablePlayer::GetUserCmdsForNetSend(this: v7, buffer, bufferSize);
  }
  else
  {
    return -1;
  }
}


// ========================================================================
// ?FindReplicatedSound@idClientGame@@QAAPAVidReplicatedSound@@W4soundChannel_t@@G@Z
// EA  : 0x82B4C1D0
// RVA : 0x00B4C1D0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idArray<idReplicatedSound,32> *__fastcall idClientGame::FindReplicatedSound(
        idClientGame *this,
        const soundChannel_t channel,
        unsigned __int16 presentableIndex)
{
  unsigned int v6; // r3
  signed int v7; // r8
  idArray<idReplicatedSound,32> *v8; // r11
  int v9; // r7
  idArray<idReplicatedSound,32> *p_replicatedSounds; // r10
  unsigned __int8 *p_peerMask; // r10
  unsigned __int8 *v12; // r9
  int i; // ctr

  v6 = Sys_Milliseconds();
  v7 = 0;
  v8 = nullptr;
  v9 = 0;
  p_replicatedSounds = &this->replicatedSounds;
  do
  {
    if ( p_replicatedSounds->ptr[0].channel == channel
      && p_replicatedSounds->ptr[0].presentableIndex == presentableIndex )
    {
      p_replicatedSounds->ptr[0].time = v6;
      return p_replicatedSounds;
    }
    if ( p_replicatedSounds->ptr[0].framesToForceKeep == 0
      && (v8 == nullptr || (int)(v6 - p_replicatedSounds->ptr[0].time) > v7) )
    {
      v7 = v6 - p_replicatedSounds->ptr[0].time;
      v8 = p_replicatedSounds;
    }
    ++v9;
    p_replicatedSounds = (idArray<idReplicatedSound,32> *)((char *)p_replicatedSounds + 224);
  }
  while ( v9 < 32 );
  if ( v8 != nullptr )
  {
    v8->ptr[0].channel = SND_CHANNEL_ANY;
    v8->ptr[0].shader = nullptr;
    v8->ptr[0].internalFlags = 0;
    v8->ptr[0].presentableIndex = -1;
    v8->ptr[0].peerMask = -1;
    v8->ptr[0].volume = 0.0;
    v8->ptr[0].position = vec3_origin;
    p_peerMask = &v8->ptr[0].peerMask;
    v12 = &v8->ptr[0].changed[6];
    for ( i = 7; i != 0; --i )
      *++v12 = *++p_peerMask;
    v8->ptr[0].soundFadeTo = 0.0;
    v8->ptr[0].clearVolumeAdjustment = false;
    v8->ptr[0].soundFadeTime = 0.0;
    v8->ptr[0].framesToForceKeep = 0;
    v8->ptr[0].volumeAdjustment = 0.0;
    v8->ptr[0].time = v6;
    v8->ptr[0].presentableIndex = presentableIndex;
  }
  return v8;
}


// ========================================================================
// ?ReplicateSoundVolume@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@MGE@Z
// EA  : 0x82B4C308
// RVA : 0x00B4C308
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ReplicateSoundVolume(
        idClientGame *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms,
        double volume,
        unsigned __int16 presentableIndex,
        unsigned __int16 peerMask,
        unsigned __int8 a8)
{
  idLobbyBase *v15; // r3
  idLobbyBase *v16; // r3
  idArray<idReplicatedSound,32> *ReplicatedSound; // r3
  idArray<idReplicatedSound,32> *v18; // r31
  unsigned __int8 v19; // r11
  int num; // r7
  int v21; // r9
  idList<idReplicatedSound,5> *p_startSoundOverRun; // r30
  int v23; // r11
  idReplicatedSound *list; // r8
  int v25; // r31

  v15 = session->GetActingGameStateLobbyBase(this: session);
  if ( v15->IsHost(this: v15) != 0 )
  {
    v16 = session->GetActingGameStateLobbyBase(this: session);
    if ( v16->HasActivePeers(this: v16) )
    {
      if ( this->overrideSoundPeerMask != 0 )
        a8 &= this->overrideSoundPeerMask;
      if ( a8 != 0 )
      {
        ReplicatedSound = idClientGame::FindReplicatedSound(this, channel, presentableIndex: peerMask);
        v18 = ReplicatedSound;
        if ( ReplicatedSound != nullptr && shader != nullptr )
        {
          if ( ReplicatedSound->ptr[0].shader != shader
            || __fabs((float)(ReplicatedSound->ptr[0].volume - (float)volume)) > 0.0099999998 )
          {
            if ( mp_cg_soundDebug.valueInteger != 0 )
              idLib::Printf(
                fmt: "Server Volume Change: Presentable: %i Channel: %i Name: %s Old: %f Volume: %f\n",
                peerMask,
                channel,
                (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(ReplicatedSound->ptr[0].volume)),
                ReplicatedSound->ptr[0].volume,
                volume);
            v18->ptr[0].volume = volume;
            v18->ptr[0].peerMask = a8;
            memcpy(Dst: &v18->ptr[0].parms, Src: parms, Size: sizeof(v18->ptr[0].parms));
            v19 = v18->ptr[0].changed[1];
            v18->ptr[0].shader = shader;
            v18->ptr[0].changed[1] = v19 + 1;
          }
        }
        else
        {
          num = this->startSoundOverRun.num;
          if ( num > 0 )
          {
            v21 = 0;
            p_startSoundOverRun = &this->startSoundOverRun;
            v23 = 0;
            list = p_startSoundOverRun->list;
            while ( list[v23].channel != channel || list[v23].presentableIndex != peerMask )
            {
              ++v21;
              ++v23;
              if ( v21 >= num )
                return;
            }
            v25 = v21;
            list[v21].time = Sys_Milliseconds();
            p_startSoundOverRun->list[v25].volume = volume;
            p_startSoundOverRun->list[v25].peerMask = a8;
            ++p_startSoundOverRun->list[v25].changed[1];
          }
        }
      }
    }
  }
}


// ========================================================================
// ?ReplicateSoundPitch@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@MGE@Z
// EA  : 0x82B4C548
// RVA : 0x00B4C548
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ReplicateSoundPitch(
        idClientGame *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms,
        double pitch,
        unsigned __int16 presentableIndex,
        unsigned __int16 peerMask,
        unsigned __int8 a8)
{
  idLobbyBase *v15; // r3
  idLobbyBase *v16; // r3
  idArray<idReplicatedSound,32> *ReplicatedSound; // r3
  idArray<idReplicatedSound,32> *v18; // r31
  unsigned __int8 v19; // r11
  int num; // r7
  int v21; // r9
  idList<idReplicatedSound,5> *p_startSoundOverRun; // r30
  int v23; // r11
  idReplicatedSound *list; // r8
  int v25; // r31

  v15 = session->GetActingGameStateLobbyBase(this: session);
  if ( v15->IsHost(this: v15) != 0 )
  {
    v16 = session->GetActingGameStateLobbyBase(this: session);
    if ( v16->HasActivePeers(this: v16) )
    {
      if ( this->overrideSoundPeerMask != 0 )
        a8 &= this->overrideSoundPeerMask;
      if ( a8 != 0 )
      {
        ReplicatedSound = idClientGame::FindReplicatedSound(this, channel, presentableIndex: peerMask);
        v18 = ReplicatedSound;
        if ( ReplicatedSound != nullptr && shader != nullptr )
        {
          if ( ReplicatedSound->ptr[0].shader != shader
            || __fabs((float)(ReplicatedSound->ptr[0].pitch - (float)pitch)) > 0.0099999998 )
          {
            if ( mp_cg_soundDebug.valueInteger != 0 )
              idLib::Printf(
                fmt: "Server Pitch Change: Presentable: %i Channel: %i Name: %s Old: %f Pitch: %f\n",
                peerMask,
                channel,
                (const char *)(const char *)HIDWORD(COERCE_UNSIGNED_INT64(ReplicatedSound->ptr[0].pitch)),
                ReplicatedSound->ptr[0].pitch,
                pitch);
            v18->ptr[0].pitch = pitch;
            v18->ptr[0].peerMask = a8;
            memcpy(Dst: &v18->ptr[0].parms, Src: parms, Size: sizeof(v18->ptr[0].parms));
            v19 = v18->ptr[0].changed[2];
            v18->ptr[0].shader = shader;
            v18->ptr[0].changed[2] = v19 + 1;
          }
        }
        else
        {
          num = this->startSoundOverRun.num;
          if ( num > 0 )
          {
            v21 = 0;
            p_startSoundOverRun = &this->startSoundOverRun;
            v23 = 0;
            list = p_startSoundOverRun->list;
            while ( list[v23].channel != channel || list[v23].presentableIndex != peerMask )
            {
              ++v21;
              ++v23;
              if ( v21 >= num )
                return;
            }
            v25 = v21;
            list[v21].time = Sys_Milliseconds();
            p_startSoundOverRun->list[v25].pitch = pitch;
            p_startSoundOverRun->list[v25].peerMask = a8;
            ++p_startSoundOverRun->list[v25].changed[2];
          }
        }
      }
    }
  }
}


// ========================================================================
// ?ReplicateSoundModify@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@GE@Z
// EA  : 0x82B4C788
// RVA : 0x00B4C788
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ReplicateSoundModify(
        idClientGame *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms,
        unsigned __int16 presentableIndex,
        unsigned __int8 peerMask)
{
  idLobbyBase *v12; // r3
  idLobbyBase *v13; // r3
  idArray<idReplicatedSound,32> *ReplicatedSound; // r3
  idArray<idReplicatedSound,32> *v15; // r31
  const idSoundShader *v16; // r11
  const char *str; // r6
  unsigned __int8 v18; // r11
  int num; // r7
  int v20; // r9
  idList<idReplicatedSound,5> *p_startSoundOverRun; // r30
  int v22; // r11
  idReplicatedSound *list; // r8
  int v24; // r31

  v12 = session->GetActingGameStateLobbyBase(this: session);
  if ( v12->IsHost(this: v12) != 0 )
  {
    v13 = session->GetActingGameStateLobbyBase(this: session);
    if ( v13->HasActivePeers(this: v13) )
    {
      if ( this->overrideSoundPeerMask != 0 )
        peerMask &= this->overrideSoundPeerMask;
      if ( peerMask != 0 )
      {
        ReplicatedSound = idClientGame::FindReplicatedSound(this, channel, presentableIndex);
        v15 = ReplicatedSound;
        if ( ReplicatedSound != nullptr && shader != nullptr )
        {
          if ( mp_cg_soundDebug.valueInteger != 0 )
          {
            v16 = ReplicatedSound->ptr[0].shader;
            if ( v16 != nullptr )
              str = v16->name.str;
            else
              str = "none";
            idLib::Printf(
              fmt: "Server Parms Change: Presentable: %i Channel: %i Name: %s\n",
              presentableIndex,
              channel,
              str);
          }
          memcpy(Dst: &v15->ptr[0].parms, Src: parms, Size: sizeof(v15->ptr[0].parms));
          v18 = v15->ptr[0].changed[3];
          v15->ptr[0].shader = shader;
          v15->ptr[0].peerMask = peerMask;
          v15->ptr[0].changed[3] = v18 + 1;
        }
        else
        {
          num = this->startSoundOverRun.num;
          if ( num > 0 )
          {
            v20 = 0;
            p_startSoundOverRun = &this->startSoundOverRun;
            v22 = 0;
            list = p_startSoundOverRun->list;
            while ( list[v22].channel != channel || list[v22].presentableIndex != presentableIndex )
            {
              ++v20;
              ++v22;
              if ( v20 >= num )
                return;
            }
            v24 = v20;
            list[v20].time = Sys_Milliseconds();
            memcpy(
              Dst: &p_startSoundOverRun->list[v24].parms,
              Src: parms,
              Size: sizeof(p_startSoundOverRun->list[v24].parms));
            p_startSoundOverRun->list[v24].peerMask = peerMask;
            ++p_startSoundOverRun->list[v24].changed[3];
          }
        }
      }
    }
  }
}


// ========================================================================
// ?ReplicateSoundVolumeAdjustment@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@MGE@Z
// EA  : 0x82B4C980
// RVA : 0x00B4C980
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ReplicateSoundVolumeAdjustment(
        idClientGame *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms,
        double adjustment,
        unsigned __int16 presentableIndex,
        unsigned __int16 peerMask,
        unsigned __int8 a8)
{
  idLobbyBase *v15; // r3
  idLobbyBase *v16; // r3
  idArray<idReplicatedSound,32> *ReplicatedSound; // r3
  idArray<idReplicatedSound,32> *v18; // r31
  unsigned __int8 v19; // r11
  unsigned __int8 v20; // r10
  int num; // r7
  int v22; // r9
  idList<idReplicatedSound,5> *p_startSoundOverRun; // r30
  int v24; // r11
  idReplicatedSound *list; // r8
  int v26; // r31

  v15 = session->GetActingGameStateLobbyBase(this: session);
  if ( v15->IsHost(this: v15) != 0 )
  {
    v16 = session->GetActingGameStateLobbyBase(this: session);
    if ( v16->HasActivePeers(this: v16) )
    {
      if ( this->overrideSoundPeerMask != 0 )
        a8 &= this->overrideSoundPeerMask;
      if ( a8 != 0 )
      {
        ReplicatedSound = idClientGame::FindReplicatedSound(this, channel, presentableIndex: peerMask);
        v18 = ReplicatedSound;
        if ( ReplicatedSound != nullptr && shader != nullptr )
        {
          ReplicatedSound->ptr[0].volumeAdjustment = adjustment;
          ReplicatedSound->ptr[0].peerMask = a8;
          memcpy(Dst: &ReplicatedSound->ptr[0].parms, Src: parms, Size: sizeof(ReplicatedSound->ptr[0].parms));
          v19 = v18->ptr[0].changed[5];
          v20 = v18->ptr[0].changed[6];
          v18->ptr[0].shader = shader;
          v18->ptr[0].changed[5] = v19 + 1;
          v18->ptr[0].lastChanged[6] = v20;
        }
        else
        {
          num = this->startSoundOverRun.num;
          if ( num > 0 )
          {
            v22 = 0;
            p_startSoundOverRun = &this->startSoundOverRun;
            v24 = 0;
            list = p_startSoundOverRun->list;
            while ( list[v24].channel != channel || list[v24].presentableIndex != peerMask )
            {
              ++v22;
              ++v24;
              if ( v22 >= num )
                return;
            }
            v26 = v22;
            list[v22].time = Sys_Milliseconds();
            p_startSoundOverRun->list[v26].volumeAdjustment = adjustment;
            p_startSoundOverRun->list[v26].peerMask = a8;
            ++p_startSoundOverRun->list[v26].changed[5];
            p_startSoundOverRun->list[v26].lastChanged[6] = p_startSoundOverRun->list[v26].changed[6];
          }
        }
      }
    }
  }
}


// ========================================================================
// ?ReplicateSoundClearVolumeAdjustment@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@GE@Z
// EA  : 0x82B4CB58
// RVA : 0x00B4CB58
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ReplicateSoundClearVolumeAdjustment(
        idClientGame *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms,
        unsigned __int16 presentableIndex,
        unsigned __int8 peerMask)
{
  idLobbyBase *v12; // r3
  idLobbyBase *v13; // r3
  idArray<idReplicatedSound,32> *ReplicatedSound; // r3
  idArray<idReplicatedSound,32> *v15; // r31
  unsigned __int8 v16; // r11
  unsigned __int8 v17; // r10
  int num; // r7
  int v19; // r9
  idList<idReplicatedSound,5> *p_startSoundOverRun; // r30
  int v21; // r11
  idReplicatedSound *list; // r8
  int v23; // r31

  v12 = session->GetActingGameStateLobbyBase(this: session);
  if ( v12->IsHost(this: v12) != 0 )
  {
    v13 = session->GetActingGameStateLobbyBase(this: session);
    if ( v13->HasActivePeers(this: v13) )
    {
      if ( this->overrideSoundPeerMask != 0 )
        peerMask &= this->overrideSoundPeerMask;
      if ( peerMask != 0 )
      {
        ReplicatedSound = idClientGame::FindReplicatedSound(this, channel, presentableIndex);
        v15 = ReplicatedSound;
        if ( ReplicatedSound != nullptr && shader != nullptr )
        {
          ReplicatedSound->ptr[0].peerMask = peerMask;
          ReplicatedSound->ptr[0].clearVolumeAdjustment = true;
          memcpy(Dst: &ReplicatedSound->ptr[0].parms, Src: parms, Size: sizeof(ReplicatedSound->ptr[0].parms));
          v16 = v15->ptr[0].changed[6];
          v17 = v15->ptr[0].changed[5];
          v15->ptr[0].shader = shader;
          v15->ptr[0].changed[6] = v16 + 1;
          v15->ptr[0].lastChanged[5] = v17;
        }
        else
        {
          num = this->startSoundOverRun.num;
          if ( num > 0 )
          {
            v19 = 0;
            p_startSoundOverRun = &this->startSoundOverRun;
            v21 = 0;
            list = p_startSoundOverRun->list;
            while ( list[v21].channel != channel || list[v21].presentableIndex != presentableIndex )
            {
              ++v19;
              ++v21;
              if ( v19 >= num )
                return;
            }
            v23 = v19;
            list[v19].time = Sys_Milliseconds();
            p_startSoundOverRun->list[v23].clearVolumeAdjustment = true;
            p_startSoundOverRun->list[v23].peerMask = peerMask;
            ++p_startSoundOverRun->list[v23].changed[6];
            p_startSoundOverRun->list[v23].lastChanged[5] = p_startSoundOverRun->list[v23].changed[5];
          }
        }
      }
    }
  }
}


// ========================================================================
// ?HandleStatusMessageForPlayer@idClientGame@@QAAXHABVidStr@@_N@Z
// EA  : 0x82B4CD20
// RVA : 0x00B4CD20
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleStatusMessageForPlayer(
        idClientGame *this,
        int playerNum,
        const idStr *header,
        bool isError)
{
  localView_t *LocalViewForPlayerIndex; // r3

  LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(this, playerNum);
  if ( LocalViewForPlayerIndex != nullptr )
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalViewForPlayerIndex->hudRender);
}


// ========================================================================
// ?HandleStatusMessage@idClientGame@@QAAXABVidStr@@_N@Z
// EA  : 0x82B4CD70
// RVA : 0x00B4CD70
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleStatusMessage(idClientGame *this, const idStr *header, bool isError)
{
  int i; // r31
  int v5; // r10
  idArray<int,4> *p_inputToPlayerIndexRouting; // r11
  char v7; // r11
  idPresentable *v8; // r3
  idPresentablePlayer *v9; // r3
  localView_t *LocalView; // r3

  for ( i = 0; i < 6; ++i )
  {
    if ( i != -1 )
    {
      v5 = 0;
      p_inputToPlayerIndexRouting = &this->inputToPlayerIndexRouting;
      while ( p_inputToPlayerIndexRouting->ptr[0] != i )
      {
        ++v5;
        p_inputToPlayerIndexRouting = (idArray<int,4> *)((char *)p_inputToPlayerIndexRouting + 4);
        if ( v5 >= 4 )
        {
          v7 = 0;
          goto LABEL_7;
        }
      }
      v7 = 1;
LABEL_7:
      if ( v7 != 0 && i < this->presentables.num && i >= 0 )
      {
        v8 = this->presentables.list[i];
        if ( v8 != nullptr )
        {
          v9 = v8->GetPlayerInterface_2(this: v8);
          if ( v9 != nullptr )
          {
            LocalView = idPresentablePlayer::GetLocalView(this: v9);
            if ( LocalView != nullptr )
              idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalView->hudRender);
          }
        }
      }
    }
  }
}


// ========================================================================
// ?HandleStatusOrSystemMessage@idClientGame@@QAAXHABVidStr@@0_N@Z
// EA  : 0x82B4CE60
// RVA : 0x00B4CE60
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleStatusOrSystemMessage(
        idClientGame *this,
        int playerNum,
        const idStr *personalText,
        const idStr *systemText,
        bool isError)
{
  int i; // r21
  localView_t *LocalViewForPlayerIndex; // r3
  localView_t *v10; // r30
  lobbyUserID_t v11; // r18
  const char *String; // r16
  const char *v13; // r3
  idStr v14[5]; // [sp+50h] [-B0h] BYREF

  for ( i = 0; i < 6; ++i )
  {
    LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: i);
    v10 = LocalViewForPlayerIndex;
    if ( LocalViewForPlayerIndex != nullptr )
    {
      if ( LocalViewForPlayerIndex->hudRender.playerNum == playerNum )
      {
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalViewForPlayerIndex->hudRender);
      }
      else
      {
        v14[0].allocedAndFlag = 20;
        v14[0].len = 0;
        v14[0].data = v14[0].baseBuffer;
        v14[0].baseBuffer[0] = 0;
        v11 = this->lobbyUserIDs.ptr[playerNum];
        v11.localUserHandle.handle = (unsigned int)session->GetActingGameStateLobbyBase(this: session);
        String = idLocalization::GetString(inString: systemText->data);
        v13 = (const char *)(*(int (__fastcall **)(unsigned int, _DWORD))(*(_DWORD *)v11.localUserHandle.handle + 40))(
                              a1: v11.localUserHandle.handle,
                              a2: *(_DWORD *)&v11.lobbyType);
        idStr::Format(this: v14, fmt: "%s: %s", v13, String);
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v10->hudRender);
        idStr::FreeData(this: v14);
      }
    }
  }
}


// ========================================================================
// __unwind$496244
// EA  : 0x82B4CF78
// RVA : 0x00B4CF78
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_496244()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 80));
}


// ========================================================================
// ?HandleSystemMessage@idClientGame@@QAAXABVidStr@@@Z
// EA  : 0x82B4CFA0
// RVA : 0x00B4CFA0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleSystemMessage(idClientGame *this, const idStr *msg)
{
  int i; // r31
  int v4; // r10
  idArray<int,4> *p_inputToPlayerIndexRouting; // r11
  char v6; // r11
  idPresentable *v7; // r3
  idPresentablePlayer *v8; // r3
  localView_t *LocalView; // r3

  for ( i = 0; i < 6; ++i )
  {
    if ( i != -1 )
    {
      v4 = 0;
      p_inputToPlayerIndexRouting = &this->inputToPlayerIndexRouting;
      while ( p_inputToPlayerIndexRouting->ptr[0] != i )
      {
        ++v4;
        p_inputToPlayerIndexRouting = (idArray<int,4> *)((char *)p_inputToPlayerIndexRouting + 4);
        if ( v4 >= 4 )
        {
          v6 = 0;
          goto LABEL_7;
        }
      }
      v6 = 1;
LABEL_7:
      if ( v6 != 0 && i < this->presentables.num && i >= 0 )
      {
        v7 = this->presentables.list[i];
        if ( v7 != nullptr )
        {
          v8 = v7->GetPlayerInterface_2(this: v7);
          if ( v8 != nullptr )
          {
            LocalView = idPresentablePlayer::GetLocalView(this: v8);
            if ( LocalView != nullptr )
              idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalView->hudRender);
          }
        }
      }
    }
  }
}


// ========================================================================
// ?HandlePointsMessageForPlayer@idClientGame@@QAAXHH@Z
// EA  : 0x82B4D080
// RVA : 0x00B4D080
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

// attributes: thunk
void __fastcall idClientGame::HandlePointsMessageForPlayer(idClientGame *this, int playerNum, int points)
{
  idClientGame::GetLocalViewForPlayerIndex(this, playerNum);
}


// ========================================================================
// ?HandleMeteorPointsMessageForPlayer@idClientGame@@QAAXHHH@Z
// EA  : 0x82B4D090
// RVA : 0x00B4D090
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleMeteorPointsMessageForPlayer(
        idClientGame *this,
        int playerNum,
        int points,
        int numMeteors)
{
  const char *v5; // r3
  const char *String; // r3
  idStr v7; // [sp+50h] [-40h] BYREF

  if ( idClientGame::GetLocalViewForPlayerIndex(this, playerNum) != nullptr )
  {
    v7.len = 0;
    v7.allocedAndFlag = 20;
    v7.data = v7.baseBuffer;
    v7.baseBuffer[0] = 0;
    if ( abs32(points) == 1 )
      v5 = "#str_online_plus_points_single";
    else
      v5 = "#str_online_plus_points";
    String = idLocalization::GetString(inString: v5);
    idStr::Format(this: &v7, fmt: String, points);
    idStr::FreeData(this: &v7);
  }
}


// ========================================================================
// __unwind$496383
// EA  : 0x82B4D130
// RVA : 0x00B4D130
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_496383()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ?HandleShowTutorialForPlayer@idClientGame@@QAAXHH@Z
// EA  : 0x82B4D158
// RVA : 0x00B4D158
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleShowTutorialForPlayer(idClientGame *this, int playerNum, int tutorialDeclNetID)
{
  int v4; // r10
  idArray<int,4> *p_inputToPlayerIndexRouting; // r11
  char v6; // r11
  int v7; // r31
  idList<idPresentable *,5> *p_presentables; // r29
  idPresentable *v9; // r10
  const idDeclTutorialEvent *v10; // r30
  void *v11; // r3
  idPresentablePlayer *v12; // r3

  v4 = 0;
  p_inputToPlayerIndexRouting = &this->inputToPlayerIndexRouting;
  while ( p_inputToPlayerIndexRouting->ptr[0] != playerNum )
  {
    ++v4;
    p_inputToPlayerIndexRouting = (idArray<int,4> *)((char *)p_inputToPlayerIndexRouting + 4);
    if ( v4 >= 4 )
    {
      v6 = 0;
      goto LABEL_5;
    }
  }
  v6 = 1;
LABEL_5:
  if ( v6 != 0 && this->presentables.num > playerNum )
  {
    v7 = playerNum;
    p_presentables = &this->presentables;
    v9 = this->presentables.list[playerNum];
    if ( v9 != nullptr && ((int (*)(void))v9->GetPlayerInterface_2)() != 0 )
    {
      v10 = nullptr;
      if ( tutorialDeclNetID != 0 )
      {
        idResourceList::GetNetworkResource(networkID: tutorialDeclNetID - 1);
        v10 = (const idDeclTutorialEvent *)_RTDynamicCast(
                                             inptr: v11,
                                             VfDelta: 0,
                                             SrcType: &idResource `RTTI Type Descriptor',
                                             TargetType: (void *)&idDeclTutorialEvent `RTTI Type Descriptor',
                                             isReference: 0);
      }
      v12 = p_presentables->list[v7]->GetPlayerInterface_2(this: p_presentables->list[v7]);
      idPresentablePlayer::ShowTutorialGui(this: v12, decl: v10, activatingEntity: nullptr);
    }
  }
}


// ========================================================================
// ?GetLocalPresentablePlayer@idClientGame@@QAAPAVidPresentablePlayer@@XZ
// EA  : 0x82B4D258
// RVA : 0x00B4D258
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idPresentablePlayer *__fastcall idClientGame::GetLocalPresentablePlayer(idClientGame *this)
{
  int v1; // r9
  int v2; // r8
  int v3; // r10
  idArray<int,4> *p_inputToPlayerIndexRouting; // r11
  int v5; // r4
  char v6; // r11
  idPresentable **list; // r11

  v1 = 0;
  v2 = 0;
  while ( 1 )
  {
    v3 = 0;
    p_inputToPlayerIndexRouting = &this->inputToPlayerIndexRouting;
    while ( 1 )
    {
      v5 = p_inputToPlayerIndexRouting->ptr[0];
      if ( p_inputToPlayerIndexRouting->ptr[0] == v1 )
        break;
      ++v3;
      p_inputToPlayerIndexRouting = (idArray<int,4> *)((char *)p_inputToPlayerIndexRouting + 4);
      if ( v3 >= 4 )
      {
        v6 = 0;
        goto LABEL_6;
      }
    }
    v6 = 1;
LABEL_6:
    if ( v6 != 0 && this->presentables.num > v1 )
    {
      list = this->presentables.list;
      if ( list[v2] != nullptr )
        return ((idPresentablePlayer *(__fastcall *)(idPresentable *, int, int, idArray<int,4> *, int))list[v1]->GetPlayerInterface_2)(
                 a1: list[v1],
                 a2: v5,
                 a3: 504204,
                 a4: &this->inputToPlayerIndexRouting,
                 a5: 504200);
    }
    ++v2;
    ++v1;
    if ( v2 >= 6 )
      return nullptr;
  }
}


// ========================================================================
// ?PlaySoundForAllPeers@idClientGame@@QAAXPAVidEntity@@W4soundChannel_t@@PBVidSoundShader@@H@Z
// EA  : 0x82B4D300
// RVA : 0x00B4D300
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::PlaySoundForAllPeers(
        idClientGame *this,
        idEntity *entity,
        soundChannel_t channel,
        const idSoundShader *shader,
        int soundShaderFlags)
{
  unsigned __int8 *p_overrideSoundPeerMask; // r31
  unsigned __int8 overrideSoundPeerMask; // r30

  if ( entity != nullptr && shader != nullptr )
  {
    p_overrideSoundPeerMask = &this->overrideSoundPeerMask;
    overrideSoundPeerMask = this->overrideSoundPeerMask;
    this->overrideSoundPeerMask = 0;
    idEntity::StartSoundShader(this: entity, channel, shader, soundShaderFlags, peerMask: 0xFFu);
    *p_overrideSoundPeerMask = overrideSoundPeerMask;
  }
}


// ========================================================================
// ?GetPresentableByEntityNum@idClientGame@@QAAPAVidPresentable@@H@Z
// EA  : 0x82B4D370
// RVA : 0x00B4D370
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idPresentable *__fastcall idClientGame::GetPresentableByEntityNum(idClientGame *this, int entityNum)
{
  int v2; // r11

  if ( entityNum == 0x1FFF )
    return nullptr;
  if ( entityNum < 0 )
    return nullptr;
  if ( (((entityNum >= 0) + ((unsigned int)entityNum >= 0x2000)) & 1) == 0 )
    return nullptr;
  v2 = this->entityToPresentableLUT[entityNum];
  if ( v2 == -1 )
    return nullptr;
  else
    return clientGame->presentables.list[v2];
}


// ========================================================================
// ?GetPlayerGameTime@idClientGame@@QBAHXZ
// EA  : 0x82B4D3E0
// RVA : 0x00B4D3E0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::GetPlayerGameTime(idClientGame *this)
{
  int result; // r3

  if ( !common->IsMultiplayer(this: common) )
    return idGameTimeManager::GetGameMs(this: &this->gameTimeManager, type: GAMETIME_SCALED);
  result = this->playerTime;
  if ( result < 0 )
    return idGameTimeManager::GetGameMs(this: &this->gameTimeManager, type: GAMETIME_SCALED);
  return result;
}


// ========================================================================
// ?GetPreviousPlayerGameTime@idClientGame@@QBAHXZ
// EA  : 0x82B4D450
// RVA : 0x00B4D450
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::GetPreviousPlayerGameTime(idClientGame *this)
{
  int GameMsPerFrame; // r30

  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &this->gameTimeManager, type: GAMETIME_SCALED);
  return idClientGame::GetPlayerGameTime(this) - GameMsPerFrame;
}


// ========================================================================
// ?ConstructPeerMaskForPlayer@idClientGame@@QBAEH@Z
// EA  : 0x82B4D4A0
// RVA : 0x00B4D4A0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::ConstructPeerMaskForPlayer(idClientGame *this, int playerNum)
{
  idLobbyBase *v2; // r3
  int v3; // r3

  v2 = session->GetActingGameStateLobbyBase(this: session);
  v3 = ((int (*)(void))v2->PeerIndexFromLobbyUser)();
  if ( v3 == -1 )
    return 0;
  else
    return (unsigned __int8)(1 << v3);
}


// ========================================================================
// ?FindPredictedPresentable@idClientGame@@QAAPAVidPresentable@@IW4presentableType_t@@@Z
// EA  : 0x82B4D530
// RVA : 0x00B4D530
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idPresentable *__fastcall idClientGame::FindPredictedPresentable(
        idClientGame *this,
        unsigned int predictedKey,
        presentableType_t presentableType)
{
  int v4; // r10
  int num; // r9
  int i; // r11
  idPresentable *v7; // r31
  int v9; // r3

  v4 = 0;
  num = this->activePresentables.num;
  if ( num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v7 = this->activePresentables.list[i];
    if ( v7 != nullptr && v7->index >= 0x2000 && v7->predictedKey == predictedKey )
      break;
    if ( ++v4 >= num )
      return nullptr;
  }
  if ( v7->GetType(this: v7) != presentableType )
  {
    v9 = v7->GetType(this: v7);
    idLib::Warning(fmt: "Mismatched presentable type. Predicted: %d Actual: %d", v9, presentableType);
  }
  return v7;
}


// ========================================================================
// ?GeneratePredictionKey@idClientGame@@QAAIPAVidWeapon@@PAVidPresentablePlayer@@H@Z
// EA  : 0x82B4D610
// RVA : 0x00B4D610
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::GeneratePredictionKey(
        idClientGame *this,
        idWeapon *weapon,
        lobbyUserID_t *playerAttacker,
        int overrideKey)
{
  BOOL v6; // r8
  int (*v7)(void); // ctr
  int *v8; // r29
  lobbyUserID_t *v9; // r4
  int v10; // r31
  lobbyUserID_t *v11; // r3
  int v13; // r3
  int handle; // r30
  BOOL v15; // r8
  int (*GetActingGameStateLobbyBase)(void); // ctr
  int *v17; // r29
  lobbyUserID_t *v18; // r4
  int v19; // r31
  lobbyUserID_t *LobbyUserID; // r3
  int v21; // r3
  int v22; // r3
  int v23; // r31
  _BYTE v24[48]; // [sp+50h] [-30h] BYREF

  if ( overrideKey == -1 )
  {
    if ( weapon != nullptr )
      handle = playerAttacker[2917].localUserHandle.handle;
    else
      handle = playerAttacker[2919].localUserHandle.handle;
    v15 = common->IsServer(this: common);
    GetActingGameStateLobbyBase = (int (*)(void))session->GetActingGameStateLobbyBase;
    if ( v15 )
    {
      v17 = (int *)GetActingGameStateLobbyBase();
      v18 = playerAttacker;
      v19 = *v17;
      LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v24, result: v18);
      v21 = (*(int (__fastcall **)(unsigned int, _DWORD))(v19 + 104))(
              a1: LobbyUserID->localUserHandle.handle,
              a2: *(_DWORD *)&LobbyUserID->lobbyType);
    }
    else
    {
      v22 = GetActingGameStateLobbyBase();
      v21 = (*(int (__fastcall **)(int))(*(_DWORD *)v22 + 152))(a1: v22);
    }
    v23 = v21;
    if ( cg_predictedSpawn_debug.valueInteger != 0 )
      idLib::Printf(fmt: "GeneratePredictionKey. predictedKey: %d peedIndex: %d\n", handle, v21);
    return (v23 << 28) | handle;
  }
  else
  {
    v6 = common->IsServer(this: common);
    v7 = (int (*)(void))session->GetActingGameStateLobbyBase;
    if ( v6 )
    {
      v8 = (int *)v7();
      v9 = playerAttacker;
      v10 = *v8;
      v11 = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)v24, result: v9);
      return ((*(int (__fastcall **)(unsigned int, _DWORD))(v10 + 104))(
                a1: v11->localUserHandle.handle,
                a2: *(_DWORD *)&v11->lobbyType) << 28)
           | overrideKey;
    }
    else
    {
      v13 = v7();
      return ((*(int (__fastcall **)(int))(*(_DWORD *)v13 + 152))(a1: v13) << 28) | overrideKey;
    }
  }
}


// ========================================================================
// ?GetTracePresentable@idClientGame@@QAAPAVidPresentable@@ABUtrace_t@@@Z
// EA  : 0x82B4D798
// RVA : 0x00B4D798
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idPresentable *__fastcall idClientGame::GetTracePresentable(idClientGame *this, const trace_t *trace)
{
  idEntity *TraceEntity; // r3
  idEntity *v5; // r31
  idPresentable *result; // r3

  if ( !common->IsServer(this: common) )
    return idClientGame::GetPresentableByEntityNum(this, entityNum: trace->c.entityNum);
  TraceEntity = idGameLocal::GetTraceEntity(this: gameLocal, trace);
  v5 = TraceEntity;
  if ( TraceEntity == nullptr )
    return nullptr;
  result = TraceEntity->presentable;
  if ( result == nullptr )
  {
    idEntity::InitPresentableInternal(this: v5);
    return v5->presentable;
  }
  return result;
}


// ========================================================================
// ??0idPlayerTimeLock@@QAA@H@Z
// EA  : 0x82B4D840
// RVA : 0x00B4D840
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idPlayerTimeLock *__fastcall idPlayerTimeLock::idPlayerTimeLock(idPlayerTimeLock *this, int newTime)
{
  idClientGame *v4; // r29
  char v5; // r11
  idPlayerTimeLock *result; // r3

  v4 = clientGame;
  if ( !common->IsMultiplayer(this: common) || (v5 = 1, v4->playerTime < 0) )
    v5 = 0;
  if ( v5 != 0 )
  {
    this->lastTime = idClientGame::GetPlayerGameTime(this: clientGame);
    result = this;
  }
  else
  {
    result = this;
    this->lastTime = -1;
  }
  clientGame->playerTime = newTime;
  return result;
}


// ========================================================================
// ?ClientDisablePresentablePushers@idClientGame@@QAAX_N@Z
// EA  : 0x82B4D8E8
// RVA : 0x00B4D8E8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ClientDisablePresentablePushers(idClientGame *this, bool disable)
{
  int *p_num; // r28
  int v4; // r29
  int v5; // r31
  idList<idPresentable *,5> *p_pusherPresentables; // r30
  idPresentable *v7; // r10
  idPresentablePusher *v8; // r3

  p_num = &this->pusherPresentables.num;
  v4 = 0;
  if ( this->pusherPresentables.num > 0 )
  {
    v5 = 0;
    p_pusherPresentables = &this->pusherPresentables;
    do
    {
      v7 = p_pusherPresentables->list[v5];
      if ( v7 != nullptr && ((int (*)(void))v7->GetPusherInterface)() != 0 )
      {
        v8 = p_pusherPresentables->list[v5]->GetPusherInterface(this: p_pusherPresentables->list[v5]);
        idPresentablePusher::DisableClip(this: v8, disable);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < *p_num );
  }
}


// ========================================================================
// ?GetVehiclePresentable@idClientGame@@QAAPAVidPresentableVehicle@@H@Z
// EA  : 0x82B4D988
// RVA : 0x00B4D988
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idPresentableVehicle *__fastcall idClientGame::GetVehiclePresentable(idClientGame *this, int index)
{
  idPresentable *v2; // r3

  if ( index >= this->vehiclePresentables.num )
    return nullptr;
  v2 = this->vehiclePresentables.list[index];
  return v2->GetVehicleInterface(this: v2);
}


// ========================================================================
// ?GenerateInputToPlayerIndexRouting@idClientGame@@QAAHXZ
// EA  : 0x82B4D9C8
// RVA : 0x00B4D9C8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::GenerateInputToPlayerIndexRouting(idClientGame *this)
{
  idArray<int,4> *p_inputToPlayerIndexRouting; // r27
  int v4; // r23
  int *v5; // r29
  int i; // r25
  int v7; // r30
  idArray<lobbyUserID_t,6> *p_lobbyUserIDs; // r31
  idLobbyBase *v9; // r3
  int v10; // r3
  char v11; // r11
  char v12; // [sp+50h] [-70h] BYREF
  _BYTE v13[96]; // [sp+60h] [-60h] BYREF

  session->GetInputRouting(this: session, a2: (int *)v13);
  this->inputToPlayerIndexRouting.ptr[0] = -1;
  this->inputToPlayerIndexRouting.ptr[1] = -1;
  this->inputToPlayerIndexRouting.ptr[2] = -1;
  this->inputToPlayerIndexRouting.ptr[3] = -1;
  if ( com_skipInputRouting.valueInteger != 0 )
  {
    this->inputToPlayerIndexRouting.ptr[0] = 0;
    return 1;
  }
  else
  {
    p_inputToPlayerIndexRouting = &this->inputToPlayerIndexRouting;
    v4 = 0;
    v5 = (int *)v13;
    for ( i = 4; i != 0; --i )
    {
      if ( *v5 != -1 )
      {
        v7 = 0;
        p_lobbyUserIDs = &this->lobbyUserIDs;
        while ( 1 )
        {
          v9 = session->GetActingGameStateLobbyBase(this: session);
          v10 = (int)v9->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)&v12, result: (lobbyUserID_t *)v9, a3: *v5);
          if ( p_lobbyUserIDs->ptr[0].localUserHandle.handle != *(_DWORD *)v10
            || (v11 = 1, p_lobbyUserIDs->ptr[0].lobbyType != *(unsigned __int8 *)(v10 + 4)) )
          {
            v11 = 0;
          }
          if ( v11 != 0 )
            break;
          ++v7;
          p_lobbyUserIDs = (idArray<lobbyUserID_t,6> *)((char *)p_lobbyUserIDs + 8);
          if ( v7 >= 6 )
            goto LABEL_13;
        }
        p_inputToPlayerIndexRouting->ptr[0] = v7;
        ++v4;
      }
LABEL_13:
      ++v5;
      p_inputToPlayerIndexRouting = (idArray<int,4> *)((char *)p_inputToPlayerIndexRouting + 4);
    }
    return v4;
  }
}


// ========================================================================
// ?GetPlayerIndexFromInputDevice@idClientGame@@QBAHH@Z
// EA  : 0x82B4DB08
// RVA : 0x00B4DB08
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::GetPlayerIndexFromInputDevice(idClientGame *this, int inputDevice)
{
  return this->inputToPlayerIndexRouting.ptr[inputDevice];
}


// ========================================================================
// ?ClearViewCallbacks@idClientGame@@QAAXXZ
// EA  : 0x82B4E078
// RVA : 0x00B4E078
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ClearViewCallbacks(idClientGame *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeViewCallbacks);
}


// ========================================================================
// ?DeleteAllPresentables@idClientGame@@QAAXXZ
// EA  : 0x82B4E088
// RVA : 0x00B4E088
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::DeleteAllPresentables(idClientGame *this)
{
  int *p_num; // r26
  int v3; // r28
  int v4; // r31
  idList<idPresentable *,5> *p_presentables; // r30
  idPresentable *v6; // r3
  idList<idPresentable *,5> *v7; // r31
  idList<idPresentable *,5> *p_activePresentables; // r30
  idList<idPresentable *,5> *p_pusherPresentables; // r31
  idList<idPresentable *,5> *p_vehiclePresentables; // r31
  idList<idPresentable *,5> *p_serializedPresentables; // r31

  p_num = &this->presentables.num;
  v3 = 0;
  if ( this->presentables.num > 0 )
  {
    v4 = 0;
    p_presentables = &this->presentables;
    do
    {
      if ( p_presentables->list[v4] != nullptr )
      {
        idPresentable::RemoveFromEntityLUT(this: p_presentables->list[v4]);
        v6 = p_presentables->list[v4];
        if ( v6 != nullptr )
          ((void (__fastcall *)(idPresentable *, int))v6->dtr_idPresentable)(a1: v6, a2: 1);
        p_presentables->list[v4] = nullptr;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < *p_num );
  }
  v7 = &this->presentables;
  if ( this->presentables.listStatic == 0 || this->presentables.listStatic == 2 )
  {
    if ( v7->list != nullptr )
      idMem::Free(this: &mem, ptr: v7->list, align: ALIGN_16);
    v7->list = nullptr;
    this->presentables.size = 0;
  }
  this->presentables.num = 0;
  p_activePresentables = &this->activePresentables;
  if ( this->activePresentables.listStatic == 0 || this->activePresentables.listStatic == 2 )
  {
    if ( p_activePresentables->list != nullptr )
      idMem::Free(this: &mem, ptr: p_activePresentables->list, align: ALIGN_16);
    p_activePresentables->list = nullptr;
    this->activePresentables.size = 0;
  }
  this->activePresentables.num = 0;
  p_pusherPresentables = &this->pusherPresentables;
  if ( this->pusherPresentables.listStatic == 0 || this->pusherPresentables.listStatic == 2 )
  {
    if ( p_pusherPresentables->list != nullptr )
      idMem::Free(this: &mem, ptr: p_pusherPresentables->list, align: ALIGN_16);
    p_pusherPresentables->list = nullptr;
    this->pusherPresentables.size = 0;
  }
  this->pusherPresentables.num = 0;
  p_vehiclePresentables = &this->vehiclePresentables;
  if ( this->vehiclePresentables.listStatic == 0 || this->vehiclePresentables.listStatic == 2 )
  {
    if ( p_vehiclePresentables->list != nullptr )
      idMem::Free(this: &mem, ptr: p_vehiclePresentables->list, align: ALIGN_16);
    p_vehiclePresentables->list = nullptr;
    this->vehiclePresentables.size = 0;
  }
  this->vehiclePresentables.num = 0;
  p_serializedPresentables = &this->serializedPresentables;
  if ( this->serializedPresentables.listStatic == 0 || this->serializedPresentables.listStatic == 2 )
  {
    if ( p_serializedPresentables->list != nullptr )
      idMem::Free(this: &mem, ptr: p_serializedPresentables->list, align: ALIGN_16);
    p_serializedPresentables->list = nullptr;
    this->serializedPresentables.size = 0;
  }
  this->serializedPresentables.num = 0;
}


// ========================================================================
// ?RenderLocalViewForGame@idClientGame@@QAAPAVidRenderModelGui@@HPAVidRenderWorld@@@Z
// EA  : 0x82B4E270
// RVA : 0x00B4E270
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idRenderModelGui *__fastcall idClientGame::RenderLocalViewForGame(
        idClientGame *this,
        int time,
        unsigned __int64 rw,
        int a4)
{
  idRenderModelGui **p_guiModel; // r30
  const idRenderWorld *v7; // r26
  idRenderModelGui *v8; // r3
  idRenderModelGui *v9; // r3
  unsigned int v10; // r25
  unsigned int v11; // r3
  int v12; // r28
  __int64 v13; // r6
  int v14; // r9
  int v15; // r8
  int v16; // r7
  idPresentablePlayer *LocalPresentablePlayer; // r3
  localView_t *LocalView; // r28
  __int64 v20; // [sp+8h] [-98h]

  p_guiModel = &this->guiModel;
  v7 = (const idRenderWorld *)HIDWORD(rw);
  if ( this->guiModel == nullptr )
  {
    v8 = (idRenderModelGui *)idMem::AllocWithLocation(
                               this: &mem,
                               location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                               size: 0xA410u,
                               tag: TAG_GUI_MODEL,
                               zeroBuffer: false,
                               align: ALIGN_16,
                               heap: HEAP_DEFAULTHEAP);
    if ( v8 != nullptr )
      v9 = idRenderModelGui::idRenderModelGui(this: v8);
    else
      v9 = nullptr;
    *p_guiModel = v9;
  }
  idRenderModelGui::Clear(this: (idRenderModelGui *)HIDWORD(defaultExtraGLState), a2: defaultExtraGLState, bits: rw, a4);
  v10 = renderSystem->GetHeight(this: renderSystem);
  v11 = renderSystem->GetWidth(this: renderSystem);
  idRenderModelGui::SetViewport(this: *p_guiModel, x: 0, y: 0, width: v11, height: v10);
  renderSystem->GetWidth(this: renderSystem);
  v12 = renderSystem->GetHeight(this: renderSystem);
  renderSystem->GetPixelAspect(this: renderSystem);
  HIDWORD(v13) = v12;
  idRenderModelGui::SetVirtualSize(this: *p_guiModel, height: v13, a3: v16, a4: v15, a5: v14, a6: v20);
  LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this);
  if ( LocalPresentablePlayer != nullptr )
  {
    LocalView = idPresentablePlayer::GetLocalView(this: LocalPresentablePlayer);
    if ( LocalView != nullptr )
    {
      session->signInManager->GetNumLocalUsers(this: session->signInManager);
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalView->hudRender);
      idPlayerGuis_Render::RenderGame(
        this: &LocalView->guisRender,
        guiModel: *p_guiModel,
        currentTime: time,
        renderView: nullptr,
        rw: v7);
    }
  }
  return *p_guiModel;
}


// ========================================================================
// __unwind$498418
// EA  : 0x82B4E460
// RVA : 0x00B4E460
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_498418()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_GUI_MODEL);
}


// ========================================================================
// ?HandleKillMessage@idClientGame@@QAAXHHPBVidDeclDamage@@_NH@Z
// EA  : 0x82B4E498
// RVA : 0x00B4E498
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleKillMessage(
        idClientGame *this,
        const int victimIndex,
        int attackerIndex,
        const idDeclDamage *damageDef,
        const bool isTeamKill,
        const int points)
{
  lobbyUserID_t v8; // r27
  idLobbyBase *v9; // r3
  const char *v10; // r3
  localView_t *LocalViewForPlayerIndex; // r3
  char *data; // r28
  const char *String; // r3
  localView_t *v14; // r3
  idStr v15; // [sp+50h] [-70h] BYREF
  idStr v16[2]; // [sp+70h] [-50h] BYREF

  v8 = this->lobbyUserIDs.ptr[victimIndex];
  v9 = session->GetActingGameStateLobbyBase(this: session);
  v10 = v9->GetLobbyUserName(this: v9, a2: *(lobbyUserID_t **)&v8.lobbyType);
  idStr::idStr(this: v16, text: v10);
  idStr::RemoveColors(this: v16);
  if ( g_useMPReferenceHUD.valueInteger != 0 )
  {
    LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: attackerIndex);
    if ( LocalViewForPlayerIndex != nullptr )
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalViewForPlayerIndex->hudRender);
  }
  else
  {
    v15.len = 0;
    v15.allocedAndFlag = 20;
    v15.data = v15.baseBuffer;
    v15.baseBuffer[0] = 0;
    data = v16[0].data;
    String = idLocalization::GetString(inString: "#str_online_you_kill_message_no_xp");
    idStr::Format(this: &v15, fmt: String, data);
    v14 = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: attackerIndex);
    if ( v14 != nullptr )
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v14->hudRender);
    idClientGame::GetLocalViewForPlayerIndex(this, playerNum: attackerIndex);
    idStr::FreeData(this: &v15);
  }
  idStr::FreeData(this: v16);
}


// ========================================================================
// __unwind$498451
// EA  : 0x82B4E5C8
// RVA : 0x00B4E5C8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_498451()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$498452
// EA  : 0x82B4E5F0
// RVA : 0x00B4E5F0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_498452()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 80));
}


// ========================================================================
// ?HandleDeathMessage@idClientGame@@QAAXHHPBVidDeclDamage@@_N1@Z
// EA  : 0x82B4E620
// RVA : 0x00B4E620
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleDeathMessage(
        idClientGame *this,
        int victimIndex,
        int attackerIndex,
        const idDeclDamage *damageDef,
        const bool isTeamKill,
        const bool isSuicide)
{
  lobbyUserID_t v7; // r21
  idPresentable *v10; // r3
  lobbyUserID_t *v11; // r28
  idLobbyBase_vtbl *v12; // r27
  lobbyUserID_t *LobbyUserID; // r3
  const char *v14; // r3
  idPresentable *v15; // r3
  idLobbyBase *v16; // r3
  const char *v17; // r3
  localView_t *LocalViewForPlayerIndex; // r3
  int v19; // [sp+50h] [-D0h] BYREF
  idStr v20; // [sp+60h] [-C0h] BYREF
  idStr v21[5]; // [sp+80h] [-A0h] BYREF

  v7 = this->lobbyUserIDs.ptr[victimIndex];
  v20.len = 0;
  v20.baseBuffer[0] = 0;
  v20.allocedAndFlag = 20;
  v20.data = v20.baseBuffer;
  if ( attackerIndex == 8190 )
  {
    idStr::operator=(this: &v20, text: "<WORLD>");
  }
  else if ( attackerIndex < this->presentables.num && attackerIndex >= 0 )
  {
    v10 = this->presentables.list[attackerIndex];
    if ( v10 != nullptr )
    {
      v11 = (lobbyUserID_t *)v10->GetPlayerInterface_2(this: v10);
      if ( v11 != nullptr && !isSuicide )
      {
        v12 = session->GetActingGameStateLobbyBase(this: session)->__vftable;
        LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v19, result: v11);
        v14 = v12->GetLobbyUserName(this: LobbyUserID->localUserHandle.handle, a2: *(_DWORD *)&LobbyUserID->lobbyType);
        idStr::operator=(this: &v20, text: v14);
        idStr::RemoveColors(this: &v20);
      }
    }
  }
  if ( victimIndex < this->presentables.num && victimIndex >= 0 )
  {
    v15 = this->presentables.list[victimIndex];
    if ( v15 != nullptr && v15->GetPlayerInterface_2(this: v15) != nullptr )
    {
      v16 = session->GetActingGameStateLobbyBase(this: session);
      v17 = v16->GetLobbyUserName(this: v16, a2: *(lobbyUserID_t **)&v7.lobbyType);
      idStr::idStr(this: v21, text: v17);
      idStr::RemoveColors(this: v21);
      LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: victimIndex);
      if ( LocalViewForPlayerIndex != nullptr )
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalViewForPlayerIndex->hudRender);
      idStr::FreeData(this: v21);
    }
  }
  idStr::FreeData(this: &v20);
}


// ========================================================================
// __unwind$498540
// EA  : 0x82B4E858
// RVA : 0x00B4E858
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_498540()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 96));
}


// ========================================================================
// __unwind$498541
// EA  : 0x82B4E880
// RVA : 0x00B4E880
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_498541()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 128));
}


// ========================================================================
// ?HandlePersonalOrSystemMessage@idClientGame@@QAAXHABVidStr@@PBUsoundShaderParms_t@@PBVidDeclVoiceOver@@@Z
// EA  : 0x82B4E8B0
// RVA : 0x00B4E8B0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandlePersonalOrSystemMessage(
        idClientGame *this,
        int playerNum,
        const idStr *text,
        const soundShaderParms_t *parms,
        const idDeclVoiceOver *vo)
{
  idLobbyBase *v10; // r3
  int i; // r20
  localView_t *LocalViewForPlayerIndex; // r3
  localView_t *v13; // r30
  idPresentablePlayer *LocalPresentablePlayer; // r3
  lobbyUserID_t v15; // r17
  const char *String; // r15
  const char *v17; // r3
  idStrId v18; // [sp+50h] [-C0h] BYREF
  idStr v19[5]; // [sp+60h] [-B0h] BYREF

  v10 = session->GetActingGameStateLobbyBase(this: session);
  if ( v10->GetMatchParms(this: v10)->gameType == 2 )
  {
    for ( i = 0; i < 6; ++i )
    {
      LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: i);
      v13 = LocalViewForPlayerIndex;
      if ( LocalViewForPlayerIndex != nullptr )
      {
        if ( LocalViewForPlayerIndex->hudRender.playerNum == playerNum )
        {
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalViewForPlayerIndex->hudRender);
          if ( vo != nullptr )
          {
            v18.index = -1;
            LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this);
            idSound::PlayVoiceOverSound(
              channel: SND_CHANNEL_ANY,
              voiceOver: vo,
              parms,
              whoStartedMe: nullptr,
              target: LocalPresentablePlayer,
              voTalkerName: &v18,
              peerMask: 0);
          }
        }
        else
        {
          v19[0].allocedAndFlag = 20;
          v19[0].len = 0;
          v19[0].data = v19[0].baseBuffer;
          v19[0].baseBuffer[0] = 0;
          v15 = this->lobbyUserIDs.ptr[playerNum];
          v15.localUserHandle.handle = (unsigned int)session->GetActingGameStateLobbyBase(this: session);
          String = idLocalization::GetString(inString: text->data);
          v17 = (const char *)(*(int (__fastcall **)(unsigned int, _DWORD))(*(_DWORD *)v15.localUserHandle.handle + 40))(
                                a1: v15.localUserHandle.handle,
                                a2: *(_DWORD *)&v15.lobbyType);
          idStr::Format(this: v19, fmt: "%s: %s", v17, String);
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v13->hudRender);
          idStr::FreeData(this: v19);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$498651
// EA  : 0x82B4EA2C
// RVA : 0x00B4EA2C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_498651()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 272 + 96));
}


// ========================================================================
// ?messagemode_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82B4EA58
// RVA : 0x00B4EA58
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall messagemode_f(const idCmdArgs *args)
{
  idClientGame *v1; // r31
  int v2; // r3
  localView_t *LocalViewForPlayerIndex; // r3

  v1 = clientGame;
  v2 = common->GetMasterLocalUserInputDevice(this: common);
  LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(
                              this: v1,
                              playerNum: v1->inputToPlayerIndexRouting.ptr[v2]);
  if ( LocalViewForPlayerIndex != nullptr )
    idPlayerGuis_Render::DisplayTextChatEntry(this: &LocalViewForPlayerIndex->guisRender);
}


// ========================================================================
// ?messagemode2_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82B4EAC8
// RVA : 0x00B4EAC8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall messagemode2_f(const idCmdArgs *args)
{
  idClientGame *v1; // r31
  int v2; // r3
  localView_t *LocalViewForPlayerIndex; // r3

  v1 = clientGame;
  v2 = common->GetMasterLocalUserInputDevice(this: common);
  LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(
                              this: v1,
                              playerNum: v1->inputToPlayerIndexRouting.ptr[v2]);
  if ( LocalViewForPlayerIndex != nullptr )
    idPlayerGuis_Render::DisplayTeamTextChatEntry(this: &LocalViewForPlayerIndex->guisRender);
}


// ========================================================================
// ?SendChatText@idClientGame@@QAAXAAVidStr@@W4messageMode_t@@@Z
// EA  : 0x82B4EB38
// RVA : 0x00B4EB38
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::SendChatText(idClientGame *this, idStr *text, messageMode_t messagemode)
{
  unsigned __int64 v3; // r27
  idSession::sessionState_t v5; // r3
  int (*GetPartyLobbyBase)(void); // r10
  int v7; // r3
  int v8; // r31
  int v9; // r28
  unsigned __int8 v10; // r29
  int v11; // r30
  int v12; // r3
  __int64 v13; // r7
  idLocalUser *v14; // r28
  char v15; // r11
  idSession::sessionState_t v16; // r3
  __int64 v17; // [sp+50h] [-1B0h]
  idBitMsg v18; // [sp+60h] [-1A0h] BYREF
  _BYTE v19[8]; // [sp+88h] [-178h] BYREF
  _BYTE v20[368]; // [sp+90h] [-170h] BYREF

  HIDWORD(v3) = &joystick.joyAxis[0][2];
  if ( session->GetState(this: session) == PARTY_LOBBY
    || session->GetState(this: session) == GAME_LOBBY
    || session->GetState(this: session) == INGAME )
  {
    idStr::StripLeadingWhiteSpace(this: text);
    idStr::StripTrailingWhitespace(this: text);
    LODWORD(v3) = 0;
    if ( text->len <= 256 )
    {
      if ( text->len <= 0 )
        return;
    }
    else
    {
      text->data[256] = 0;
      text->len = 256;
    }
    v5 = session->GetState(this: session);
    switch ( v5 )
    {
      case PARTY_LOBBY:
        GetPartyLobbyBase = (int (*)(void))session->GetPartyLobbyBase;
        break;
      case GAME_LOBBY:
        GetPartyLobbyBase = (int (*)(void))session->GetGameLobbyBase;
        break;
      case INGAME:
        GetPartyLobbyBase = (int (*)(void))session->GetActingGameStateLobbyBase;
        break;
      default:
        return;
    }
    v7 = GetPartyLobbyBase();
    v8 = v7;
    if ( v7 != 0 )
    {
      v9 = 0;
      v10 = -1;
      v11 = 0;
      if ( (*(int (__fastcall **)(int))(*(_DWORD *)v7 + 12))(a1: v7) <= 0 )
        goto LABEL_19;
      do
      {
        v12 = (*(int (__fastcall **)(_BYTE *, int, int))(*(_DWORD *)v8 + 20))(a1: v19, a2: v8, a3: v11);
        v13 = *(_QWORD *)v12;
        HIDWORD(v13) = *(_DWORD *)(*(_DWORD *)v8 + 92);
        v17 = v13;
        v14 = (idLocalUser *)((int (__fastcall *)(int, _DWORD))HIDWORD(v13))(a1: v8, a2: *(_DWORD *)(v12 + 4));
        if ( common->GetMasterLocalUser(this: common) == v14 )
          break;
        ++v11;
      }
      while ( v11 < (*(int (__fastcall **)(int))(*(_DWORD *)v8 + 12))(a1: v8) );
      v9 = HIDWORD(v17);
      v10 = BYTE4(v17);
      if ( HIDWORD(v17) == 0 || (v15 = 1, BYTE4(v17) == 255) )
LABEL_19:
        v15 = 0;
      if ( v15 != 0 )
      {
        memset(&v18.curSize, 0, 18);
        v18.writeData = v20;
        v18.readData = v20;
        v18.maxSize = 292;
        v18.tempValue = v3;
        idBitMsg::WriteBits(this: &v18, value: v9, numBits: 32);
        idBitMsg::WriteBits(this: &v18, value: v10, numBits: 8);
        idBitMsg::WriteString(this: &v18, s: text->data, maxLength: 256, make7Bit: false);
        (*(void (__fastcall **)(int, int, idBitMsg *, int, int))(*(_DWORD *)v8 + 28))(
          a1: v8,
          a2: 25,
          a3: &v18,
          a4: 1,
          a5: 255);
      }
      else
      {
        v16 = session->GetState(this: session);
        idLib::Warning(fmt: "SendChatText: Can't find session user index for local user (Session State: %d)", v16);
      }
    }
  }
}


// ========================================================================
// ?HandleTextChat@idClientGame@@QAAXAAVidBitMsg@@@Z
// EA  : 0x82B4EDE8
// RVA : 0x00B4EDE8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleTextChat(idClientGame *this, idBitMsg *msg)
{
  unsigned __int8 Bits; // r11
  unsigned __int64 v5; // r30
  char v6; // r11
  bool v7; // zf
  int v8; // r28
  idLobbyBase *v9; // r3
  char v10; // r3
  const char *v11; // r3
  localView_t *LocalViewForPlayerIndex; // r3
  lobbyUserID_t v13; // [sp+50h] [-210h] BYREF
  idBitMsg v14; // [sp+60h] [-200h] BYREF
  idStr v15; // [sp+90h] [-1D0h] BYREF
  idStr v16; // [sp+B0h] [-1B0h] BYREF
  idStr v17; // [sp+D0h] [-190h] BYREF
  _BYTE v18[368]; // [sp+F0h] [-170h] BYREF

  if ( session->GetState(this: session) == PARTY_LOBBY
    || session->GetState(this: session) == GAME_LOBBY
    || session->GetState(this: session) == INGAME )
  {
    v13.localUserHandle.handle = idBitMsg::ReadBits(this: msg, numBits: 32);
    Bits = idBitMsg::ReadBits(this: msg, numBits: 8);
    LODWORD(v5) = 0;
    v13.lobbyType = Bits;
    if ( v13.localUserHandle.handle == 0 || (v7 = Bits != 255, v6 = 1, !v7) )
      v6 = 0;
    if ( v6 != 0 )
    {
      v8 = *(_DWORD *)&v13.lobbyType;
      v9 = session->GetLobbyFromLobbyUserID(this: session, a2: *(_DWORD *)&v13.lobbyType);
      v17.len = 0;
      v17.baseBuffer[0] = 0;
      v17.allocedAndFlag = 20;
      HIDWORD(v5) = v9;
      v17.data = v17.baseBuffer;
      idBitMsg::ReadString(this: msg, str: &v17);
      if ( (**(unsigned __int8 (__fastcall ***)(_DWORD))HIDWORD(v5))(a1: HIDWORD(v5)) != 0 )
      {
        memset(&v14.curSize, 0, 18);
        v14.writeData = v18;
        v14.readData = v18;
        v14.maxSize = 292;
        v14.tempValue = v5;
        lobbyUserID_t::WriteToMsg(this: &v13, msg: &v14);
        idBitMsg::WriteString(this: &v14, s: v17.data, maxLength: 256, make7Bit: false);
        v10 = (*(int (__fastcall **)(_DWORD, int))(*(_DWORD *)HIDWORD(v5) + 24))(a1: HIDWORD(v5), a2: v8);
        (*(void (__fastcall **)(_DWORD, int, idBitMsg *, _DWORD, _DWORD))(*(_DWORD *)HIDWORD(v5) + 28))(
          a1: HIDWORD(v5),
          a2: 25,
          a3: &v14,
          a4: 0,
          a5: (unsigned __int8)~(1 << v10));
      }
      v15.allocedAndFlag = 20;
      v15.len = 0;
      v15.data = v15.baseBuffer;
      v15.baseBuffer[0] = 0;
      v11 = (const char *)(*(int (__fastcall **)(_DWORD, int))(*(_DWORD *)HIDWORD(v5) + 40))(a1: HIDWORD(v5), a2: v8);
      idStr::operator=(this: &v15, text: v11);
      idStr::RemoveColors(this: &v15);
      v16.allocedAndFlag = 20;
      v16.data = v16.baseBuffer;
      v16.len = 0;
      v16.baseBuffer[0] = 0;
      idStr::Format(this: &v16, fmt: "%s: %s", v15.data, v17.data);
      if ( session->GetState(this: session) == INGAME )
      {
        do
        {
          LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: v5);
          if ( LocalViewForPlayerIndex != nullptr )
            idPlayerGuis_Render::DisplayTextChatMessage(this: &LocalViewForPlayerIndex->guisRender, message: &v16);
          LODWORD(v5) = v5 + 1;
        }
        while ( (int)v5 < 6 );
      }
      else
      {
        idMainMenu::DisplayTextChatMessage(this: gameLocal->mainMenu, message: &v16);
      }
      idStr::FreeData(this: &v16);
      idStr::FreeData(this: &v15);
      idStr::FreeData(this: &v17);
    }
  }
}


// ========================================================================
// __unwind$498852
// EA  : 0x82B4F0A0
// RVA : 0x00B4F0A0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_498852()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 208));
}


// ========================================================================
// __unwind$498853
// EA  : 0x82B4F0C8
// RVA : 0x00B4F0C8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_498853()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 144));
}


// ========================================================================
// __unwind$498854
// EA  : 0x82B4F0F0
// RVA : 0x00B4F0F0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_498854()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 608 + 176));
}


// ========================================================================
// ?RemoveSimulatingEffectPhysics@idClientGame@@QAAXPAVidEffectPhysicsBroadPhase@@@Z
// EA  : 0x82B4F118
// RVA : 0x00B4F118
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::RemoveSimulatingEffectPhysics(idClientGame *this, idEffectPhysicsBroadPhase *broadPhase)
{
  int v2; // r10
  idList<idEntityPtr<idEntity>,58> *p_simulatingEffectPhysics; // r3
  int num; // r9
  int i; // r11

  v2 = 0;
  p_simulatingEffectPhysics = (idList<idEntityPtr<idEntity>,58> *)&gameLocal->simulatingEffectPhysics;
  num = p_simulatingEffectPhysics->num;
  if ( num > 0 )
  {
    for ( i = 0; (idEffectPhysicsBroadPhase *)p_simulatingEffectPhysics->list[i].spawnId.value != broadPhase; ++i )
    {
      if ( ++v2 >= num )
        return;
    }
    if ( v2 >= 0 )
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::RemoveIndex(this: p_simulatingEffectPhysics, index: v2);
  }
}


// ========================================================================
// ?ShowThinks@idClientGame@@QAAXXZ
// EA  : 0x82B4F498
// RVA : 0x00B4F498
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ShowThinks(idClientGame *this)
{
  int valueInteger; // r11
  double v2; // fp31
  int v3; // r29
  int v4; // r25
  int *p_num; // r20
  int v6; // r24
  int v7; // r28
  idList<presentableThink_t,5> *p_presentableThinks; // r23
  presentableThink_t *v9; // r30
  int lastNumThinks; // r11
  double ms; // fp0
  int lastNumDormantThinks; // r10
  double v13; // fp13
  int numThinks; // r11
  char *v15; // r4
  __int64 v16; // r10
  __int64 v17; // r8
  va *v18; // r3
  int numDormantThinks; // r11
  int v20; // r10
  __int64 v23; // r10
  double v24; // fp1
  __int64 v25; // r8
  va *v26; // r3
  int v27; // [sp+8h] [-10F8h]
  int v28; // [sp+Ch] [-10F4h]
  int v29; // [sp+10h] [-10F0h]
  int v30; // [sp+14h] [-10ECh]
  int v31; // [sp+18h] [-10E8h]
  int v32; // [sp+1Ch] [-10E4h]
  int v33; // [sp+30h] [-10D0h]
  int v34; // [sp+38h] [-10C8h]
  idStr v35; // [sp+50h] [-10B0h] BYREF
  va v36; // [sp+70h] [-1090h] BYREF

  valueInteger = g_showThinks.valueInteger;
  if ( g_showThinks.valueInteger != 0 )
  {
    v2 = 0.0;
    v35.len = 0;
    v3 = 0;
    v35.baseBuffer[0] = 0;
    v4 = 0;
    v35.allocedAndFlag = 20;
    v35.data = v35.baseBuffer;
    p_num = &this->presentableThinks.num;
    v6 = 0;
    if ( this->presentableThinks.num > 0 )
    {
      v7 = 0;
      p_presentableThinks = &this->presentableThinks;
      do
      {
        v9 = &p_presentableThinks->list[v7];
        if ( valueInteger == 2
          && (lastNumThinks = v9->lastNumThinks,
              ms = v9->lastms,
              lastNumDormantThinks = v9->lastNumDormantThinks,
              v9->ms = v9->lastms,
              v9->numThinks = lastNumThinks,
              v9->numDormantThinks = lastNumDormantThinks,
              g_showThinks.valueInteger == 2) )
        {
          v13 = ms;
        }
        else
        {
          ms = v9->ms;
          v13 = (float)((float)((float)(v9->ms - v9->avgms) * (float)0.1) + v9->avgms);
        }
        numThinks = v9->numThinks;
        v9->avgms = v13;
        v2 = (float)((float)ms + (float)v2);
        v3 += numThinks;
        v4 += v9->numDormantThinks;
        v15 = "^1";
        if ( ms <= 1.0 )
          v15 = "^2";
        idStr::Append(this: &v35, text: v15);
        LODWORD(v16) = v9->numDormantThinks;
        HIDWORD(v16) = v9->name;
        LODWORD(v17) = v9->numThinks;
        HIDWORD(v17) = v17 - v16;
        v18 = va::va(
                this: &v36,
                fmt: "%5.02f / %5.02f ms (%3ix / %3ix) %s\n",
                a3: COERCE__INT64(v9->maxms),
                a4: v17,
                a5: v16,
                a6: v27,
                a7: v28,
                a8: v29,
                a9: v30,
                a10: v31,
                a11: v32);
        idStr::Append(this: &v35, text: v18);
        valueInteger = g_showThinks.valueInteger;
        if ( g_showThinks.valueInteger == 1 )
        {
          numDormantThinks = v9->numDormantThinks;
          v9->lastms = v9->ms;
          v20 = v9->numThinks;
          v9->ms = 0.0;
          v9->numDormantThinks = 0;
          v9->numThinks = 0;
          v9->lastNumDormantThinks = numDormantThinks;
          v9->lastNumThinks = v20;
          valueInteger = g_showThinks.valueInteger;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < *p_num );
    }
    _FP13 = (float)((float)v2 - maxTotalMs);
    __asm { fsel      f0, f13, f31, f0 }
    maxTotalMs = _FP0;
    if ( v3 > maxTotalThinks )
      maxTotalThinks = v3;
    idStr::Append(this: &v35, text: "^2--------------------------------\n");
    if ( g_showThinks.valueInteger == 2 )
      v24 = v2;
    else
      v24 = (float)((float)((float)((float)v2 - avgMs) * (float)0.1) + avgMs);
    LODWORD(v25) = v3;
    avgMs = v24;
    HIDWORD(v25) = v3 - v4;
    v26 = va::va(
            this: &v36,
            fmt: "^2Total: %5.02f / %5.02f (%3ix / %3ix)\n",
            a3: __SPAIR64__(LODWORD(v24), COERCE_UNSIGNED_INT64(maxTotalMs)),
            a4: v25,
            a5: v23,
            a6: v27,
            a7: v28,
            a8: v29,
            a9: v30,
            a10: v31,
            a11: v32);
    idStr::Append(this: &v35, text: v26);
    if ( (_S18_9 & 1) == 0 )
    {
      handle_7.time = 0;
      _S18_9 |= 1u;
      handle_7.index = -1;
    }
    ((void (__fastcall *)(idConsole *, idOverlayHandle *, _DWORD, int, int, char *))console->PrintOverlay)(
      a1: console,
      a2: &handle_7,
      a3: 0.5,
      a4: v33,
      a5: v34,
      a6: v35.data);
    idStr::FreeData(this: &v35);
  }
  else
  {
    maxTotalMs = 0.0;
    maxTotalThinks = 0;
    avgMs = 0.0;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->presentableThinks);
  }
}


// ========================================================================
// __unwind$499446
// EA  : 0x82B4F7A0
// RVA : 0x00B4F7A0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499446()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4352 + 80));
}


// ========================================================================
// ?ShowPresentableInfo@idClientGame@@QAAXXZ
// EA  : 0x82B4F7D0
// RVA : 0x00B4F7D0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ShowPresentableInfo(idClientGame *this)
{
  idPresentablePlayer *LocalPresentablePlayer; // r25
  int v3; // r20
  int v4; // r24
  idPresentable *v5; // r30
  double v6; // fp12
  double v7; // fp9
  const char *debugName; // r11
  const char *v9; // r4
  presentableType_t v10; // r3
  idRenderWorld *renderWorld; // r3
  double y; // fp8
  double x; // fp7
  float v14[6]; // [sp+68h] [-D8h] BYREF
  idStr v15; // [sp+80h] [-C0h] BYREF

  if ( cg_showPresentableInfo.valueInteger != 0 )
  {
    LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this);
    if ( LocalPresentablePlayer != nullptr )
    {
      v3 = 0;
      if ( this->activePresentables.num > 0 )
      {
        v4 = 0;
        do
        {
          v5 = this->activePresentables.list[v4];
          if ( v5->index < 0x2000 )
          {
            v6 = (float)(v5->origin.y - LocalPresentablePlayer->view.gameview.vieworg.y);
            v7 = (float)(v5->origin.x - LocalPresentablePlayer->view.gameview.vieworg.x);
            if ( __fsqrts((float)((float)((float)(v5->origin.z - LocalPresentablePlayer->view.gameview.vieworg.z)
                                        * (float)(v5->origin.z - LocalPresentablePlayer->view.gameview.vieworg.z))
                                + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))) < 256.0 )
            {
              v15.allocedAndFlag = 20;
              v15.len = 0;
              v15.data = v15.baseBuffer;
              v15.baseBuffer[0] = 0;
              if ( v5->entity != nullptr )
              {
                debugName = v5->debugName;
                if ( debugName == nullptr )
                  debugName = "NULL";
                idStr::operator=(this: &v15, text: debugName);
                idStr::Append(this: &v15, text: " : ");
                idStr::Append(this: &v15, text: v5->entity->name.data);
              }
              else
              {
                v9 = v5->debugName;
                if ( v9 == nullptr )
                {
                  v10 = v5->GetType(this: v5);
                  v9 = StringForPresentableType(presentableType: v10);
                }
                idStr::operator=(this: &v15, text: v9);
              }
              renderWorld = this->renderWorld;
              y = v5->origin.y;
              x = v5->origin.x;
              v14[2] = v5->origin.z + (float)(vec3_up.z * (float)5.0);
              v14[1] = (float)y + (float)(vec3_up.y * (float)5.0);
              v14[0] = (float)x + (float)(vec3_up.x * (float)5.0);
              ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))renderWorld->DebugText)(
                a1: renderWorld,
                a2: v15.data,
                a3: v14,
                a4: renderWorld->DebugText,
                a5: &idColor::colorWhite,
                a6: 1,
                a7: 0,
                a8: 0,
                a9: 0.1);
              idStr::FreeData(this: &v15);
            }
          }
          ++v3;
          ++v4;
        }
        while ( v3 < this->activePresentables.num );
      }
    }
  }
}


// ========================================================================
// __unwind$499592
// EA  : 0x82B4FA14
// RVA : 0x00B4FA14
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 320 + 128));
}


// ========================================================================
// ?HandleReliableOnlineGameEvent@idClientGame@@QAAXHAAVidBitMsg@@@Z
// EA  : 0x82B4FA48
// RVA : 0x00B4FA48
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleReliableOnlineGameEvent(idClientGame *this, int type, idBitMsg *msg)
{
  int Bits; // r26
  int v6; // r29
  int *v7; // r27
  idLobbyBase *v8; // r3
  idLobbyBase *v9; // r3
  idLobbyBase *v10; // r3
  idLobbyBase *v11; // r3
  idLobbyBase *v12; // r3
  int v13; // r29
  localView_t *LocalViewForPlayerIndex; // r3
  int v15; // r10
  idArray<int,4> *v16; // r11
  char v17; // r11
  int v18; // r29
  int v19; // r10
  idArray<int,4> *v20; // r11
  int v21; // r29
  int v22; // r10
  idArray<int,4> *v23; // r11
  int v24; // r29
  int v25; // r10
  idArray<int,4> *v26; // r11
  int v27; // r29
  int v28; // r10
  idArray<int,4> *v29; // r11
  char v30; // r11
  localView_t *v31; // r3
  int v32; // r29
  int v33; // r10
  idArray<int,4> *v34; // r11
  char v35; // r11
  localView_t *v36; // r3
  int v37; // r10
  idArray<int,4> *p_inputToPlayerIndexRouting; // r11
  char v39; // r11
  lobbyUserID_t v40; // r29
  const char *String; // r27
  const char *v42; // r3
  idPresentablePlayer *LocalPresentablePlayer; // r3
  idLobbyBase *v44; // r3
  idLobbyBase *v45; // r3
  idLobbyBase *v46; // r3
  idLobbyBase *v47; // r3
  idLobbyBase *v48; // r3
  idLobbyBase *v49; // r3
  idLobbyBase *v50; // r3
  idLobbyBase *v51; // r3
  int v52; // r29
  int v53; // r10
  idArray<int,4> *v54; // r11
  char v55; // r11
  lobbyUserID_t v56; // r29
  idLobbyBase *v57; // r3
  int v58; // r3
  const char *v59; // r3
  char *data; // r29
  const char *v61; // r3
  char *v62; // r29
  const char *v63; // r3
  idLobbyBase *v64; // r3
  const char *v65; // r3
  idLobbyBase *v66; // r3
  const char *v67; // r3
  char *v68; // r29
  char *v69; // r28
  const char *v70; // r3
  int v71; // [sp+4Ch] [-6D4h] BYREF
  int v72; // [sp+50h] [-6D0h]
  int v73; // [sp+54h] [-6CCh]
  int v74; // [sp+58h] [-6C8h]
  int v75; // [sp+5Ch] [-6C4h]
  soundShaderParms_t v76; // [sp+60h] [-6C0h] BYREF
  idStr v77; // [sp+100h] [-620h] BYREF
  idStr v78; // [sp+120h] [-600h] BYREF
  idStr v79; // [sp+140h] [-5E0h] BYREF
  idStr v80; // [sp+160h] [-5C0h] BYREF
  idStr v81; // [sp+180h] [-5A0h] BYREF
  idStr v82; // [sp+1A0h] [-580h] BYREF
  idStr v83; // [sp+1C0h] [-560h] BYREF
  idStr v84; // [sp+1E0h] [-540h] BYREF
  idStr v85; // [sp+200h] [-520h] BYREF
  idStr v86; // [sp+220h] [-500h] BYREF
  idStr v87; // [sp+240h] [-4E0h] BYREF
  idStr v88; // [sp+260h] [-4C0h] BYREF
  idStr v89; // [sp+280h] [-4A0h] BYREF
  idStr v90; // [sp+2A0h] [-480h] BYREF
  idStr v91; // [sp+2C0h] [-460h] BYREF
  idStr v92; // [sp+2E0h] [-440h] BYREF
  idStr v93; // [sp+300h] [-420h] BYREF
  idStr v94; // [sp+320h] [-400h] BYREF
  idStr v95; // [sp+340h] [-3E0h] BYREF
  idStr v96; // [sp+360h] [-3C0h] BYREF
  idStr v97; // [sp+380h] [-3A0h] BYREF
  idStr v98; // [sp+3A0h] [-380h] BYREF
  idStr v99; // [sp+3C0h] [-360h] BYREF
  idStr v100; // [sp+3E0h] [-340h] BYREF
  idStr v101; // [sp+400h] [-320h] BYREF
  idStr v102; // [sp+420h] [-300h] BYREF
  idStr v103; // [sp+440h] [-2E0h] BYREF
  idStr v104; // [sp+460h] [-2C0h] BYREF
  idStr v105; // [sp+480h] [-2A0h] BYREF
  idStr v106; // [sp+4A0h] [-280h] BYREF
  idStr v107; // [sp+4C0h] [-260h] BYREF
  idStr v108; // [sp+4E0h] [-240h] BYREF
  idStr v109; // [sp+500h] [-220h] BYREF
  idStr v110; // [sp+520h] [-200h] BYREF
  idStr v111; // [sp+540h] [-1E0h] BYREF
  idStr v112; // [sp+560h] [-1C0h] BYREF
  idStr v113; // [sp+580h] [-1A0h] BYREF
  idStr v114; // [sp+5A0h] [-180h] BYREF
  idStr v115; // [sp+5C0h] [-160h] BYREF
  idStr v116; // [sp+5E0h] [-140h] BYREF
  idStr v117; // [sp+600h] [-120h] BYREF
  idStr v118; // [sp+620h] [-100h] BYREF
  idStr v119; // [sp+640h] [-E0h] BYREF
  idStr v120; // [sp+660h] [-C0h] BYREF
  idStr v121; // [sp+680h] [-A0h] BYREF
  idStr v122; // [sp+6A0h] [-80h] BYREF
  idStr v123[3]; // [sp+6C0h] [-60h] BYREF

  Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  v72 = 0;
  v73 = 0;
  v74 = 0;
  v75 = 0;
  v6 = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  if ( v6 != 0 )
  {
    v7 = &v71;
    do
    {
      --v6;
      *++v7 = idBitMsg::ReadBits(this: msg, numBits: 32);
    }
    while ( v6 != 0 );
  }
  memset(&v76.shakeFalloff, 0, 16);
  v76.falloff = nullptr;
  v76.wetFalloff = nullptr;
  memset(&v76.maxPlay, 0, 12);
  v76.minDistance = 0.0;
  v76.maxDistance = 0.0;
  v76.distanceFactor = 1.0;
  v76.wetMinDistanceOffset = 0.0;
  v76.wetMaxDistanceOffset = 0.0;
  v76.coneAttenuation.innerAngle = 0.0;
  v76.coneAttenuation.outerAngle = 0.0;
  v76.coneAttenuation.outerVolume = -60.0;
  v76.volume.min = 0.0;
  v76.volume.max = 0.0;
  v76.volume.granularity = 0.0;
  v76.wetVolume = 0.0;
  v76.pitch.min = 0.0;
  v76.pitch.max = 0.0;
  v76.pitch.granularity = 0.0;
  v76.loopFadeInDuration = 0.0;
  v76.loopFadeOutDuration = 0.0;
  v76.dopplerMultiplier = 1.0;
  v76.shakes = 0.0;
  v76.minShakeDistance = 0.0;
  v76.maxShakeDistance = 0.0;
  v76.lowPassMinDistance = 0.0;
  v76.lowPassStrength = 0.0;
  v76.lfeVolume = -60.0;
  v76.centerChannel = 0.0;
  v76.headroom = 0.0;
  v76.distanceBasedRanges.farMaxRange = 0.0;
  v76.distanceBasedRanges.nearMinRange = 0.0;
  switch ( Bits )
  {
    case 0:
      v8 = session->GetActingGameStateLobbyBase(this: session);
      if ( v8->GetMatchParms(this: v8)->gameType == 2 )
      {
        idStr::idStr(this: v123, text: "#str_online_system_message_suicide");
        idStr::idStr(this: &v100, text: "#str_online_status_suicide");
        idClientGame::HandleStatusOrSystemMessage(
          this,
          playerNum: v72,
          personalText: &v100,
          systemText: v123,
          isError: true);
        idStr::FreeData(this: &v100);
        idStr::FreeData(this: v123);
      }
      return;
    case 1:
      v9 = session->GetActingGameStateLobbyBase(this: session);
      if ( v9->GetMatchParms(this: v9)->gameType == 2 )
      {
        idStr::idStr(this: &v118, text: "#str_online_double_kill_message");
        idClientGame::HandlePersonalOrSystemMessage(
          this,
          playerNum: v72,
          text: &v118,
          parms: &v76,
          vo: this->doubleKill);
        idStr::FreeData(this: &v118);
      }
      return;
    case 2:
      v10 = session->GetActingGameStateLobbyBase(this: session);
      if ( v10->GetMatchParms(this: v10)->gameType == 2 )
      {
        idStr::idStr(this: &v84, text: "#str_online_triple_kill_message");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v84, parms: &v76, vo: this->tripleKill);
        idStr::FreeData(this: &v84);
      }
      return;
    case 3:
      v11 = session->GetActingGameStateLobbyBase(this: session);
      if ( v11->GetMatchParms(this: v11)->gameType == 2 )
      {
        idStr::idStr(this: &v104, text: "#str_online_quad_kill_message");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v104, parms: &v76, vo: this->quadKill);
        idStr::FreeData(this: &v104);
      }
      return;
    case 4:
      v12 = session->GetActingGameStateLobbyBase(this: session);
      if ( v12->GetMatchParms(this: v12)->gameType == 2 )
      {
        idStr::idStr(this: &v86, text: "#str_online_killing_spree_message");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v86, parms: &v76, vo: this->slaughter);
        idStr::FreeData(this: &v86);
      }
      return;
    case 5:
      idStr::idStr(this: &v85, text: "#str_online_system_message_flag_pickedup");
      idStr::idStr(this: &v83, text: "#str_online_system_message_flag_you_pickedup");
      idClientGame::HandleStatusOrSystemMessage(
        this,
        playerNum: v72,
        personalText: &v83,
        systemText: &v85,
        isError: false);
      idStr::FreeData(this: &v83);
      idStr::FreeData(this: &v85);
      return;
    case 6:
      idStr::idStr(this: &v89, text: "#str_online_system_message_flag_dropped");
      idStr::idStr(this: &v87, text: "#str_online_system_message_flag_you_dropped");
      idClientGame::HandleStatusOrSystemMessage(
        this,
        playerNum: v72,
        personalText: &v87,
        systemText: &v89,
        isError: false);
      idStr::FreeData(this: &v87);
      idStr::FreeData(this: &v89);
      return;
    case 7:
      idStr::idStr(this: &v82, text: "#str_online_system_message_flag_captured");
      idStr::idStr(this: &v102, text: "#str_online_system_message_flag_captured");
      idClientGame::HandleStatusOrSystemMessage(
        this,
        playerNum: v72,
        personalText: &v102,
        systemText: &v82,
        isError: false);
      idStr::FreeData(this: &v102);
      idStr::FreeData(this: &v82);
      return;
    case 8:
      idStr::idStr(this: &v93, text: "#str_online_system_message_flag_returned");
      idStr::idStr(this: &v91, text: "#str_online_system_message_flag_returned");
      idClientGame::HandleStatusOrSystemMessage(
        this,
        playerNum: v72,
        personalText: &v91,
        systemText: &v93,
        isError: false);
      idStr::FreeData(this: &v91);
      idStr::FreeData(this: &v93);
      return;
    case 9:
      v37 = 0;
      p_inputToPlayerIndexRouting = &this->inputToPlayerIndexRouting;
      while ( p_inputToPlayerIndexRouting->ptr[0] != v72 )
      {
        ++v37;
        p_inputToPlayerIndexRouting = (idArray<int,4> *)((char *)p_inputToPlayerIndexRouting + 4);
        if ( v37 >= 4 )
        {
          v39 = 0;
          goto LABEL_63;
        }
      }
      v39 = 1;
LABEL_63:
      if ( v39 == 0 )
      {
        v80.len = 0;
        v80.baseBuffer[0] = 0;
        v80.allocedAndFlag = 20;
        v80.data = v80.baseBuffer;
        v40 = this->lobbyUserIDs.ptr[v72];
        v40.localUserHandle.handle = (unsigned int)session->GetActingGameStateLobbyBase(this: session);
        String = idLocalization::GetString(inString: "#str_online_quad_pickup_message");
        v42 = (const char *)(*(int (__fastcall **)(unsigned int, _DWORD))(*(_DWORD *)v40.localUserHandle.handle + 40))(
                              a1: v40.localUserHandle.handle,
                              a2: *(_DWORD *)&v40.lobbyType);
        idStr::Format(this: &v80, fmt: "%s: %s", v42, String);
        idClientGame::HandleStatusMessage(this, header: &v80, isError: false);
        idStr::FreeData(this: &v80);
      }
      return;
    case 10:
      idStr::idStr(this: &v112, text: "#str_online_system_message_quad_end");
      idStr::idStr(this: &v81, text: "#str_online_system_message_quad_end");
      idClientGame::HandleStatusOrSystemMessage(
        this,
        playerNum: v72,
        personalText: &v81,
        systemText: &v112,
        isError: true);
      idStr::FreeData(this: &v81);
      idStr::FreeData(this: &v112);
      return;
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 18:
    case 20:
      return;
    case 15:
      LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this);
      if ( LocalPresentablePlayer != nullptr )
        LocalPresentablePlayer->playerHud.forceScoreboard = true;
      return;
    case 19:
      idStr::idStr(this: &v114, text: "#str_online_chain_broke_message");
      idClientGame::HandlePersonalOrSystemMessage(
        this,
        playerNum: v72,
        text: &v114,
        parms: &v76,
        vo: this->chainBreaker);
      idStr::FreeData(this: &v114);
      idStr::idStr(this: &v88, text: "#str_online_lost_chain_message");
      v13 = v73;
      LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: v73);
      if ( LocalViewForPlayerIndex != nullptr )
        idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalViewForPlayerIndex->hudRender);
      idStr::FreeData(this: &v88);
      v15 = 0;
      v16 = &this->inputToPlayerIndexRouting;
      do
      {
        if ( v16->ptr[0] == v13 )
          goto LABEL_25;
        ++v15;
        v16 = (idArray<int,4> *)((char *)v16 + 4);
      }
      while ( v15 < 4 );
      goto LABEL_20;
    case 21:
      idStr::idStr(this: &v90, text: "#str_online_cr_callout_max_chain");
      idStr::idStr(this: &v106, text: "#str_online_cr_callout_max_chain");
      v18 = v72;
      idClientGame::HandleStatusOrSystemMessage(
        this,
        playerNum: v72,
        personalText: &v106,
        systemText: &v90,
        isError: false);
      idStr::FreeData(this: &v106);
      idStr::FreeData(this: &v90);
      idClientGame::GetLocalViewForPlayerIndex(this, playerNum: v18);
      v19 = 0;
      v20 = &this->inputToPlayerIndexRouting;
      while ( v20->ptr[0] != v18 )
      {
        ++v19;
        v20 = (idArray<int,4> *)((char *)v20 + 4);
        if ( v19 >= 4 )
          goto LABEL_20;
      }
      goto LABEL_25;
    case 22:
      idStr::idStr(this: &v94, text: "#str_online_kill_chain_controller_message");
      idStr::idStr(this: &v108, text: "#str_online_kill_chain_controller_message");
      idClientGame::HandleStatusOrSystemMessage(
        this,
        playerNum: v72,
        personalText: &v108,
        systemText: &v94,
        isError: false);
      idStr::FreeData(this: &v108);
      idStr::FreeData(this: &v94);
      v27 = v73;
      v28 = 0;
      v29 = &this->inputToPlayerIndexRouting;
      while ( v29->ptr[0] != v73 )
      {
        ++v28;
        v29 = (idArray<int,4> *)((char *)v29 + 4);
        if ( v28 >= 4 )
        {
          v30 = 0;
          goto LABEL_44;
        }
      }
      v30 = 1;
LABEL_44:
      if ( v30 != 0 )
      {
        idStr::idStr(this: &v116, text: "#str_online_lost_chain_message");
        v31 = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: v27);
        if ( v31 != nullptr )
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v31->hudRender);
        idStr::FreeData(this: &v116);
      }
      return;
    case 23:
      v44 = session->GetActingGameStateLobbyBase(this: session);
      if ( v44->GetMatchParms(this: v44)->gameType == 2 )
      {
        idStr::idStr(this: &v95, text: "#str_online_cr_callout_impressive");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v95, parms: &v76, vo: this->impressive);
        idStr::FreeData(this: &v95);
      }
      return;
    case 24:
      v45 = session->GetActingGameStateLobbyBase(this: session);
      if ( v45->GetMatchParms(this: v45)->gameType == 2 )
      {
        idStr::idStr(this: &v97, text: "#str_online_cr_callout_revenge");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v97, parms: &v76, vo: this->revenge);
        idStr::FreeData(this: &v97);
      }
      return;
    case 25:
      v46 = session->GetActingGameStateLobbyBase(this: session);
      if ( v46->GetMatchParms(this: v46)->gameType == 2 )
      {
        idStr::idStr(this: &v99, text: "#str_online_cr_callout_air_mail");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v99, parms: &v76, vo: this->airMail);
        idStr::FreeData(this: &v99);
      }
      return;
    case 26:
      v47 = session->GetActingGameStateLobbyBase(this: session);
      if ( v47->GetMatchParms(this: v47)->gameType == 2 )
      {
        idStr::idStr(this: &v101, text: "#str_online_cr_callout_pull");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v101, parms: &v76, vo: this->pull);
        idStr::FreeData(this: &v101);
      }
      return;
    case 27:
      v48 = session->GetActingGameStateLobbyBase(this: session);
      if ( v48->GetMatchParms(this: v48)->gameType == 2 )
      {
        idStr::idStr(this: &v103, text: "#str_online_cr_callout_afterlife");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v103, parms: &v76, vo: this->afterLife);
        idStr::FreeData(this: &v103);
      }
      return;
    case 28:
      v49 = session->GetActingGameStateLobbyBase(this: session);
      if ( v49->GetMatchParms(this: v49)->gameType == 2 )
      {
        idStr::idStr(this: &v105, text: "#str_online_cr_callout_denial");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v105, parms: &v76, vo: this->denial);
        idStr::FreeData(this: &v105);
      }
      return;
    case 29:
      v50 = session->GetActingGameStateLobbyBase(this: session);
      if ( v50->GetMatchParms(this: v50)->gameType == 2 )
      {
        idStr::idStr(this: &v107, text: "#str_online_cr_callout_close_call");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v107, parms: &v76, vo: this->closeCall);
        idStr::FreeData(this: &v107);
      }
      return;
    case 30:
      v51 = session->GetActingGameStateLobbyBase(this: session);
      if ( v51->GetMatchParms(this: v51)->gameType == 2 )
      {
        idStr::idStr(this: &v109, text: "#str_online_cr_callout_air_rally");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v109, parms: &v76, vo: this->airRally);
        idStr::FreeData(this: &v109);
      }
      return;
    case 31:
      idStr::idStr(this: &v122, text: "#str_online_cr_callout_triad");
      v21 = v72;
      idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v122, parms: nullptr, vo: nullptr);
      idStr::FreeData(this: &v122);
      idClientGame::GetLocalViewForPlayerIndex(this, playerNum: v21);
      v22 = 0;
      v23 = &this->inputToPlayerIndexRouting;
      while ( v23->ptr[0] != v21 )
      {
        ++v22;
        v23 = (idArray<int,4> *)((char *)v23 + 4);
        if ( v22 >= 4 )
          goto LABEL_20;
      }
      goto LABEL_25;
    case 32:
      v24 = v72;
      if ( v74 > 0 )
      {
        idStr::idStr(this: &v92, text: "#str_online_cr_callout_thief");
        idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v24, text: &v92, parms: nullptr, vo: nullptr);
        idStr::FreeData(this: &v92);
      }
      idClientGame::HandleMeteorPointsMessageForPlayer(this, playerNum: v24, points: v73, numMeteors: v75);
      v25 = 0;
      v26 = &this->inputToPlayerIndexRouting;
      while ( v26->ptr[0] != v24 )
      {
        ++v25;
        v26 = (idArray<int,4> *)((char *)v26 + 4);
        if ( v25 >= 4 )
        {
LABEL_20:
          v17 = 0;
          goto LABEL_21;
        }
      }
LABEL_25:
      v17 = 1;
LABEL_21:
      if ( v17 != 0 && soundSystem != nullptr && soundSystem->GetPlayingSoundWorld(this: soundSystem) != nullptr )
      {
        soundSystem->GetPlayingSoundWorld(this: soundSystem);
        soundSystem->GetEditorSoundWorld(this: soundSystem);
      }
      return;
    case 33:
      idStr::idStr(this: &v110, text: "#str_online_cr_callout_triad_killer");
      idStr::idStr(this: &v96, text: "#str_online_cr_callout_triad_killer");
      idClientGame::HandleStatusOrSystemMessage(
        this,
        playerNum: v72,
        personalText: &v96,
        systemText: &v110,
        isError: false);
      idStr::FreeData(this: &v96);
      idStr::FreeData(this: &v110);
      return;
    case 34:
      idStr::idStr(this: &v98, text: "#str_online_cr_callout_triad_breaker");
      idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v73, text: &v98, parms: nullptr, vo: nullptr);
      idStr::FreeData(this: &v98);
      v32 = v72;
      v33 = 0;
      v34 = &this->inputToPlayerIndexRouting;
      while ( v34->ptr[0] != v72 )
      {
        ++v33;
        v34 = (idArray<int,4> *)((char *)v34 + 4);
        if ( v33 >= 4 )
        {
          v35 = 0;
          goto LABEL_54;
        }
      }
      v35 = 1;
LABEL_54:
      if ( v35 != 0 )
      {
        idStr::idStr(this: &v120, text: "#str_online_system_message_triad_broke");
        v36 = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: v32);
        if ( v36 != nullptr )
          idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&v36->hudRender);
        idStr::FreeData(this: &v120);
      }
      return;
    case 35:
      v52 = v72;
      v53 = 0;
      v54 = &this->inputToPlayerIndexRouting;
      break;
    case 36:
      idStr::idStr(this: &v113, text: "#str_online_cr_callout_bully_killer");
      idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v72, text: &v113, parms: nullptr, vo: nullptr);
      idStr::FreeData(this: &v113);
      return;
    case 37:
      v56 = this->lobbyUserIDs.ptr[v72];
      v57 = session->GetActingGameStateLobbyBase(this: session);
      if ( v57->IsLobbyUserValid(this: v57, a2: *(lobbyUserID_t **)&v56.lobbyType) )
      {
        v58 = (*(int (__fastcall **)(_DWORD))(**(_DWORD **)(v56.localUserHandle.handle + 4160) + 156))(a1: *(_DWORD *)(v56.localUserHandle.handle + 4160));
        v59 = (const char *)(*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v58 + 40))(
                              a1: v58,
                              a2: *(_DWORD *)&v56.lobbyType);
        idStr::idStr(this: &v115, text: v59);
        v77.len = 0;
        v77.allocedAndFlag = 20;
        v77.data = v77.baseBuffer;
        v77.baseBuffer[0] = 0;
        data = v115.data;
        v61 = idLocalization::GetString(inString: "#str_online_player_joined_match_lobby");
        idStr::Format(this: &v77, fmt: v61, data);
        idClientGame::HandleSystemMessage(this, msg: &v77);
        idStr::FreeData(this: &v77);
        idStr::FreeData(this: &v115);
      }
      return;
    case 38:
      idStr::idStr(this: &v117, text: "FIXME: lobbyUserID_t");
      v79.len = 0;
      v79.allocedAndFlag = 20;
      v79.data = v79.baseBuffer;
      v79.baseBuffer[0] = 0;
      v62 = v117.data;
      v63 = idLocalization::GetString(inString: "#str_online_player_disconnected");
      idStr::Format(this: &v79, fmt: v63, v62);
      idClientGame::HandleSystemMessage(this, msg: &v79);
      idStr::FreeData(this: &v79);
      idStr::FreeData(this: &v117);
      return;
    case 39:
      v64 = session->GetActingGameStateLobbyBase(this: session);
      v65 = (const char *)((int (*)(void))v64->GetLobbyUserName)();
      idStr::idStr(this: &v121, text: v65);
      v66 = session->GetActingGameStateLobbyBase(this: session);
      v67 = (const char *)((int (*)(void))v66->GetLobbyUserName)();
      idStr::idStr(this: &v119, text: v67);
      v78.len = 0;
      v78.allocedAndFlag = 20;
      v78.data = v78.baseBuffer;
      v78.baseBuffer[0] = 0;
      v68 = v119.data;
      v69 = v121.data;
      v70 = idLocalization::GetString(inString: "#str_online_killed");
      idStr::Format(this: &v78, fmt: v70, v69, v68);
      idClientGame::HandleSystemMessage(this, msg: &v78);
      idStr::FreeData(this: &v78);
      idStr::FreeData(this: &v119);
      idStr::FreeData(this: &v121);
      return;
    default:
      idLib::Warning(fmt: "HandleReliableOnlineGameEvent() called with unknown message type");
      return;
  }
  while ( v54->ptr[0] != v72 )
  {
    ++v53;
    v54 = (idArray<int,4> *)((char *)v54 + 4);
    if ( v53 >= 4 )
    {
      v55 = 0;
      goto LABEL_93;
    }
  }
  v55 = 1;
LABEL_93:
  if ( v55 != 0 )
  {
    idStr::idStr(this: &v111, text: "#str_online_cr_callout_you_are_bully");
    idClientGame::HandlePersonalOrSystemMessage(this, playerNum: v52, text: &v111, parms: nullptr, vo: nullptr);
    idStr::FreeData(this: &v111);
  }
}


// ========================================================================
// __unwind$499821
// EA  : 0x82B50BB4
// RVA : 0x00B50BB4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499821()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1728));
}


// ========================================================================
// __unwind$499822
// EA  : 0x82B50BDC
// RVA : 0x00B50BDC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499822()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 992));
}


// ========================================================================
// __unwind$499823
// EA  : 0x82B50C04
// RVA : 0x00B50C04
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499823()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1568));
}


// ========================================================================
// __unwind$499824
// EA  : 0x82B50C2C
// RVA : 0x00B50C2C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499824()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 480));
}


// ========================================================================
// __unwind$499825
// EA  : 0x82B50C54
// RVA : 0x00B50C54
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499825()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1120));
}


// ========================================================================
// __unwind$499826
// EA  : 0x82B50C7C
// RVA : 0x00B50C7C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499826()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 544));
}


// ========================================================================
// __unwind$499827
// EA  : 0x82B50CA4
// RVA : 0x00B50CA4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499827()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1440));
}


// ========================================================================
// __unwind$499828
// EA  : 0x82B50CCC
// RVA : 0x00B50CCC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499828()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 608));
}


// ========================================================================
// __unwind$499829
// EA  : 0x82B50CF4
// RVA : 0x00B50CF4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499829()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 672));
}


// ========================================================================
// __unwind$499830
// EA  : 0x82B50D1C
// RVA : 0x00B50D1C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499830()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1184));
}


// ========================================================================
// __unwind$499831
// EA  : 0x82B50D44
// RVA : 0x00B50D44
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499831()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1696));
}


// ========================================================================
// __unwind$499832
// EA  : 0x82B50D6C
// RVA : 0x00B50D6C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499832()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 736));
}


// ========================================================================
// __unwind$499833
// EA  : 0x82B50D94
// RVA : 0x00B50D94
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499833()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 800));
}


// ========================================================================
// __unwind$499834
// EA  : 0x82B50DBC
// RVA : 0x00B50DBC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499834()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1248));
}


// ========================================================================
// __unwind$499835
// EA  : 0x82B50DE4
// RVA : 0x00B50DE4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499835()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1504));
}


// ========================================================================
// __unwind$499836
// EA  : 0x82B50E0C
// RVA : 0x00B50E0C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499836()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1312));
}


// ========================================================================
// __unwind$499837
// EA  : 0x82B50E34
// RVA : 0x00B50E34
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499837()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 864));
}


// ========================================================================
// __unwind$499838
// EA  : 0x82B50E5C
// RVA : 0x00B50E5C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499838()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 928));
}


// ========================================================================
// __unwind$499839
// EA  : 0x82B50E84
// RVA : 0x00B50E84
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499839()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1632));
}


// ========================================================================
// __unwind$499840
// EA  : 0x82B50EAC
// RVA : 0x00B50EAC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499840()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 352));
}


// ========================================================================
// __unwind$499841
// EA  : 0x82B50ED4
// RVA : 0x00B50ED4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499841()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1376));
}


// ========================================================================
// __unwind$499842
// EA  : 0x82B50EFC
// RVA : 0x00B50EFC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499842()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 384));
}


// ========================================================================
// __unwind$499843
// EA  : 0x82B50F24
// RVA : 0x00B50F24
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499843()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 416));
}


// ========================================================================
// __unwind$499844
// EA  : 0x82B50F4C
// RVA : 0x00B50F4C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499844()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1056));
}


// ========================================================================
// __unwind$499845
// EA  : 0x82B50F74
// RVA : 0x00B50F74
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499845()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 512));
}


// ========================================================================
// __unwind$499846
// EA  : 0x82B50F9C
// RVA : 0x00B50F9C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499846()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 448));
}


// ========================================================================
// __unwind$499847
// EA  : 0x82B50FC4
// RVA : 0x00B50FC4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499847()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 640));
}


// ========================================================================
// __unwind$499848
// EA  : 0x82B50FEC
// RVA : 0x00B50FEC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499848()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 576));
}


// ========================================================================
// __unwind$499849
// EA  : 0x82B51014
// RVA : 0x00B51014
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499849()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 768));
}


// ========================================================================
// __unwind$499850
// EA  : 0x82B5103C
// RVA : 0x00B5103C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499850()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 704));
}


// ========================================================================
// __unwind$499851
// EA  : 0x82B51064
// RVA : 0x00B51064
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499851()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 832));
}


// ========================================================================
// __unwind$499852
// EA  : 0x82B5108C
// RVA : 0x00B5108C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499852()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 896));
}


// ========================================================================
// __unwind$499853
// EA  : 0x82B510B4
// RVA : 0x00B510B4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499853()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 960));
}


// ========================================================================
// __unwind$499854
// EA  : 0x82B510DC
// RVA : 0x00B510DC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499854()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1024));
}


// ========================================================================
// __unwind$499855
// EA  : 0x82B51104
// RVA : 0x00B51104
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499855()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1088));
}


// ========================================================================
// __unwind$499856
// EA  : 0x82B5112C
// RVA : 0x00B5112C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499856()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1152));
}


// ========================================================================
// __unwind$499857
// EA  : 0x82B51154
// RVA : 0x00B51154
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499857()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1216));
}


// ========================================================================
// __unwind$499858
// EA  : 0x82B5117C
// RVA : 0x00B5117C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499858()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1280));
}


// ========================================================================
// __unwind$499859
// EA  : 0x82B511A4
// RVA : 0x00B511A4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499859()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1344));
}


// ========================================================================
// __unwind$499860
// EA  : 0x82B511CC
// RVA : 0x00B511CC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499860()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1408));
}


// ========================================================================
// __unwind$499861
// EA  : 0x82B511F4
// RVA : 0x00B511F4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499861()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1472));
}


// ========================================================================
// __unwind$499862
// EA  : 0x82B5121C
// RVA : 0x00B5121C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499862()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 256));
}


// ========================================================================
// __unwind$499863
// EA  : 0x82B51244
// RVA : 0x00B51244
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499863()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1536));
}


// ========================================================================
// __unwind$499864
// EA  : 0x82B5126C
// RVA : 0x00B5126C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499864()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 320));
}


// ========================================================================
// __unwind$499865
// EA  : 0x82B51294
// RVA : 0x00B51294
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499865()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1664));
}


// ========================================================================
// __unwind$499866
// EA  : 0x82B512BC
// RVA : 0x00B512BC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499866()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 1600));
}


// ========================================================================
// __unwind$499867
// EA  : 0x82B512E4
// RVA : 0x00B512E4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_499867()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 1824 + 288));
}


// ========================================================================
// ?HandleXpGainMsg@idClientGame@@QAAXAAVidBitMsg@@@Z
// EA  : 0x82B51318
// RVA : 0x00B51318
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::HandleXpGainMsg(idClientGame *this, idBitMsg *msg)
{
  int Bits; // r30
  int v5; // r26
  int v6; // r3
  void *v7; // r3
  _DWORD *v8; // r25
  idRageMetrics *rageMetrics; // r29
  int SessionStat; // r28
  lobbyUserID_t v11; // r24
  idLobbyBase *v12; // r3
  const char *v13; // r3
  const char *String; // r3
  localView_t *LocalViewForPlayerIndex; // r3
  char *data; // r30
  const char *LocalizedString; // r3
  idStrId v18; // [sp+50h] [-A0h] BYREF
  idStr v19; // [sp+60h] [-90h] BYREF
  idStr v20[3]; // [sp+80h] [-70h] BYREF

  if ( com_multiplayer.valueInteger != 0 )
  {
    Bits = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
    v5 = idBitMsg::ReadBits(this: msg, numBits: 32);
    v6 = idBitMsg::ReadBits(this: msg, numBits: 32);
    idResourceList::GetNetworkResource(networkID: v6 - 1);
    v8 = _RTDynamicCast(
           inptr: v7,
           VfDelta: 0,
           SrcType: &idResource `RTTI Type Descriptor',
           TargetType: (void *)&idDeclMetric `RTTI Type Descriptor',
           isReference: 0);
    rageMetrics = clientGame->rageMetrics;
    if ( common->IsClient(this: common) )
      idRageMetrics::GainXP(this: rageMetrics, playerId: Bits, xp: v5);
    SessionStat = idRageMetrics::GetSessionStat(this: rageMetrics, playerId: Bits, stat: RAGE_STAT_MP_LEVEL);
    idRageMetrics::UpdateLevel(this: rageMetrics, playerId: Bits);
    v11 = this->lobbyUserIDs.ptr[Bits];
    v12 = session->GetActingGameStateLobbyBase(this: session);
    v13 = v12->GetLobbyUserName(this: v12, a2: *(lobbyUserID_t **)&v11.lobbyType);
    idStr::idStr(this: v20, text: v13);
    String = idLocalization::GetString(inString: "#str_online_levelup_message");
    idStr::idStr(this: &v19, text: String);
    if ( idRageMetrics::GetSessionStat(this: rageMetrics, playerId: Bits, stat: RAGE_STAT_MP_LEVEL) > SessionStat )
      idClientGame::HandlePersonalOrSystemMessage(this, playerNum: Bits, text: &v19, parms: nullptr, vo: nullptr);
    LocalViewForPlayerIndex = idClientGame::GetLocalViewForPlayerIndex(this, playerNum: Bits);
    if ( LocalViewForPlayerIndex != nullptr )
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&LocalViewForPlayerIndex->hudRender);
    if ( v8 != nullptr )
    {
      data = v20[0].data;
      v18.index = v8[29];
      LocalizedString = idStrId::GetLocalizedString(this: &v18);
      idLib::Printf(fmt: "^2%s Gained +%dXP from %s\n", data, v5, LocalizedString);
    }
    idStr::FreeData(this: &v19);
    idStr::FreeData(this: v20);
  }
}


// ========================================================================
// __unwind$500706
// EA  : 0x82B51510
// RVA : 0x00B51510
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_500706()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$500707_0
// EA  : 0x82B51538
// RVA : 0x00B51538
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_500707_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 96));
}


// ========================================================================
// ?ReplicateStopSound@idClientGame@@QAAXW4soundChannel_t@@GE@Z
// EA  : 0x82B51560
// RVA : 0x00B51560
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ReplicateStopSound(
        idClientGame *this,
        soundChannel_t channel,
        unsigned __int16 presentableIndex,
        unsigned __int8 peerMask)
{
  idLobbyBase *v8; // r3
  idLobbyBase *v9; // r3
  idArray<idReplicatedSound,32> *ReplicatedSound; // r3
  idArray<idReplicatedSound,32> *v11; // r31
  const idSoundShader *shader; // r11
  const char *str; // r6
  unsigned __int8 v14; // r11
  int num; // r8
  int v16; // r4
  int v17; // r11
  idReplicatedSound *list; // r9

  v8 = session->GetActingGameStateLobbyBase(this: session);
  if ( v8->IsHost(this: v8) != 0 )
  {
    v9 = session->GetActingGameStateLobbyBase(this: session);
    if ( v9->HasActivePeers(this: v9) )
    {
      if ( this->overrideSoundPeerMask != 0 )
        peerMask &= this->overrideSoundPeerMask;
      if ( peerMask != 0 )
      {
        ReplicatedSound = idClientGame::FindReplicatedSound(this, channel, presentableIndex);
        v11 = ReplicatedSound;
        if ( ReplicatedSound != nullptr )
        {
          if ( mp_cg_soundDebug.valueInteger != 0 )
          {
            shader = ReplicatedSound->ptr[0].shader;
            if ( shader != nullptr )
              str = shader->name.str;
            else
              str = "none";
            idLib::Printf(
              fmt: "Server Stop Sound: Presentable: %i Channel: %i Name: %s\n",
              presentableIndex,
              channel,
              str);
          }
          v14 = v11->ptr[0].changed[0];
          v11->ptr[0].channel = channel;
          v11->ptr[0].shader = nullptr;
          v11->ptr[0].presentableIndex = presentableIndex;
          v11->ptr[0].peerMask = peerMask;
          v11->ptr[0].changed[0] = v14 + 1;
        }
        else
        {
          num = this->startSoundOverRun.num;
          if ( num > 0 )
          {
            v16 = 0;
            v17 = 0;
            list = this->startSoundOverRun.list;
            while ( list[v17].channel != channel || list[v17].presentableIndex != presentableIndex )
            {
              ++v16;
              ++v17;
              if ( v16 >= num )
                return;
            }
            idList<idReplicatedSound,5>::RemoveIndex(this: &this->startSoundOverRun, index: v16);
          }
        }
      }
    }
  }
}


// ========================================================================
// ??1idClientGame@@QAA@XZ
// EA  : 0x82B51F48
// RVA : 0x00B51F48
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::~idClientGame(idClientGame *this)
{
  idRageMetrics **p_rageMetrics; // r28
  idRageMetrics *rageMetrics; // r3
  idRenderModelGui **p_guiModel; // r29
  idRenderModelGui *guiModel; // r3
  int v6; // r28
  idArray<idRenderModelGui *,6> *p_localGuiModels; // r29
  idRenderModel *v8; // r3
  idList<idViewCallbacks *,5> *p_activeViewCallbacks; // r29
  idList<idClientGameMsg *,5> *p_queuedReliableMsgs; // r28
  idList<idReplicatedSound,5> *p_startSoundOverRun; // r29
  idList<idPresentable *,5> *p_serializedPresentables; // r29
  idList<idPresentable *,5> *p_vehiclePresentables; // r29
  idList<idPresentable *,5> *p_pusherPresentables; // r29
  idList<idPresentable *,5> *p_activePresentables; // r29
  idList<idPresentable *,5> *p_presentables; // r29
  idList<presentableThink_t,5> *p_presentableThinks; // r29
  idList<idPresentableAnimatedEntity *,5> *p_aimAssistTargets; // r29
  idList<idClass *,5> *p_objectList; // r29
  idPhysics **list; // r4

  p_rageMetrics = &this->rageMetrics;
  rageMetrics = this->rageMetrics;
  if ( rageMetrics != nullptr )
    ((void (__fastcall *)(idRageMetrics *, int))rageMetrics->dtr_idClass)(a1: rageMetrics, a2: 1);
  p_guiModel = &this->guiModel;
  *p_rageMetrics = nullptr;
  guiModel = this->guiModel;
  if ( guiModel != nullptr )
  {
    guiModel->unlinked = true;
    guiModel->deleteOnSync = true;
    idRenderModel::CommitThisFrame(this: guiModel);
    if ( *p_guiModel != nullptr )
      ((void (__fastcall *)(idRenderModelGui *, int))(*p_guiModel)->dtr_idRenderModel)(a1: *p_guiModel, a2: 1);
    *p_guiModel = nullptr;
  }
  v6 = 6;
  p_localGuiModels = &this->localGuiModels;
  do
  {
    v8 = p_localGuiModels->ptr[0];
    if ( p_localGuiModels->ptr[0] != nullptr )
    {
      v8->unlinked = true;
      v8->deleteOnSync = true;
      idRenderModel::CommitThisFrame(this: v8);
      if ( p_localGuiModels->ptr[0] != nullptr )
        ((void (__fastcall *)(idRenderModelGui *, int))p_localGuiModels->ptr[0]->dtr_idRenderModel)(
          a1: p_localGuiModels->ptr[0],
          a2: 1);
      p_localGuiModels->ptr[0] = nullptr;
    }
    --v6;
    p_localGuiModels = (idArray<idRenderModelGui *,6> *)((char *)p_localGuiModels + 4);
  }
  while ( v6 != 0 );
  common->ClearDialog(this: common, a2: GDM_CONNECTION_PROBLEMS, a3: nullptr, a4: 0);
  p_activeViewCallbacks = &this->activeViewCallbacks;
  if ( this->activeViewCallbacks.listStatic == 0 || this->activeViewCallbacks.listStatic == 2 )
  {
    if ( p_activeViewCallbacks->list != nullptr )
      idMem::Free(this: &mem, ptr: p_activeViewCallbacks->list, align: ALIGN_16);
    p_activeViewCallbacks->list = nullptr;
    this->activeViewCallbacks.size = 0;
  }
  this->activeViewCallbacks.num = 0;
  idClientGame::DeleteAllPresentables(this);
  p_queuedReliableMsgs = &this->queuedReliableMsgs;
  if ( this->queuedReliableMsgs.listStatic == 0 || this->queuedReliableMsgs.listStatic == 2 )
  {
    if ( p_queuedReliableMsgs->list != nullptr )
      idMem::Free(this: &mem, ptr: p_queuedReliableMsgs->list, align: ALIGN_16);
    p_queuedReliableMsgs->list = nullptr;
    this->queuedReliableMsgs.size = 0;
  }
  this->queuedReliableMsgs.num = 0;
  `eh vector destructor iterator'(
    ptr: &this->deferredFireManager,
    size: 0xA28u,
    count: 64,
    pDtor: (void (__fastcall *)(void *))idFireParms::~idFireParms);
  `eh vector destructor iterator'(
    ptr: this->influenceTrailManager.influenceTrails,
    size: 0x4Cu,
    count: 128,
    pDtor: (void (__fastcall *)(void *))idInfluenceTrail::~idInfluenceTrail);
  this->influenceTrailManager.__vftable = (idInfluenceTrailManager_vtbl *)&idClass::`vftable';
  if ( this->activeViewCallbacks.listStatic == 0 || this->activeViewCallbacks.listStatic == 2 )
  {
    if ( p_activeViewCallbacks->list != nullptr )
      idMem::Free(this: &mem, ptr: p_activeViewCallbacks->list, align: ALIGN_16);
    p_activeViewCallbacks->list = nullptr;
    this->activeViewCallbacks.size = 0;
  }
  this->activeViewCallbacks.num = 0;
  p_startSoundOverRun = &this->startSoundOverRun;
  if ( this->startSoundOverRun.listStatic == 0 || this->startSoundOverRun.listStatic == 2 )
  {
    if ( p_startSoundOverRun->list != nullptr )
      idMem::Free(this: &mem, ptr: p_startSoundOverRun->list, align: ALIGN_16);
    p_startSoundOverRun->list = nullptr;
    this->startSoundOverRun.size = 0;
  }
  this->startSoundOverRun.num = 0;
  p_serializedPresentables = &this->serializedPresentables;
  if ( this->serializedPresentables.listStatic == 0 || this->serializedPresentables.listStatic == 2 )
  {
    if ( p_serializedPresentables->list != nullptr )
      idMem::Free(this: &mem, ptr: p_serializedPresentables->list, align: ALIGN_16);
    p_serializedPresentables->list = nullptr;
    this->serializedPresentables.size = 0;
  }
  this->serializedPresentables.num = 0;
  p_vehiclePresentables = &this->vehiclePresentables;
  if ( this->vehiclePresentables.listStatic == 0 || this->vehiclePresentables.listStatic == 2 )
  {
    if ( p_vehiclePresentables->list != nullptr )
      idMem::Free(this: &mem, ptr: p_vehiclePresentables->list, align: ALIGN_16);
    p_vehiclePresentables->list = nullptr;
    this->vehiclePresentables.size = 0;
  }
  this->vehiclePresentables.num = 0;
  p_pusherPresentables = &this->pusherPresentables;
  if ( this->pusherPresentables.listStatic == 0 || this->pusherPresentables.listStatic == 2 )
  {
    if ( p_pusherPresentables->list != nullptr )
      idMem::Free(this: &mem, ptr: p_pusherPresentables->list, align: ALIGN_16);
    p_pusherPresentables->list = nullptr;
    this->pusherPresentables.size = 0;
  }
  this->pusherPresentables.num = 0;
  p_activePresentables = &this->activePresentables;
  if ( this->activePresentables.listStatic == 0 || this->activePresentables.listStatic == 2 )
  {
    if ( p_activePresentables->list != nullptr )
      idMem::Free(this: &mem, ptr: p_activePresentables->list, align: ALIGN_16);
    p_activePresentables->list = nullptr;
    this->activePresentables.size = 0;
  }
  this->activePresentables.num = 0;
  p_presentables = &this->presentables;
  if ( this->presentables.listStatic == 0 || this->presentables.listStatic == 2 )
  {
    if ( p_presentables->list != nullptr )
      idMem::Free(this: &mem, ptr: p_presentables->list, align: ALIGN_16);
    p_presentables->list = nullptr;
    this->presentables.size = 0;
  }
  this->presentables.num = 0;
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&this->gameTimeManager);
  p_presentableThinks = &this->presentableThinks;
  if ( this->presentableThinks.listStatic == 0 || this->presentableThinks.listStatic == 2 )
  {
    if ( p_presentableThinks->list != nullptr )
      idMem::Free(this: &mem, ptr: p_presentableThinks->list, align: ALIGN_16);
    p_presentableThinks->list = nullptr;
    this->presentableThinks.size = 0;
  }
  this->presentableThinks.num = 0;
  p_aimAssistTargets = &this->aimAssistTargets;
  if ( this->aimAssistTargets.listStatic == 0 || this->aimAssistTargets.listStatic == 2 )
  {
    if ( p_aimAssistTargets->list != nullptr )
      idMem::Free(this: &mem, ptr: p_aimAssistTargets->list, align: ALIGN_16);
    p_aimAssistTargets->list = nullptr;
    this->aimAssistTargets.size = 0;
  }
  this->aimAssistTargets.num = 0;
  idHashIndex::Free(this: &this->objectHash);
  p_objectList = &this->objectList;
  if ( this->objectList.listStatic == 0 || this->objectList.listStatic == 2 )
  {
    if ( p_objectList->list != nullptr )
      idMem::Free(this: &mem, ptr: p_objectList->list, align: ALIGN_16);
    p_objectList->list = nullptr;
    this->objectList.size = 0;
  }
  this->objectList.num = 0;
  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)&this->eventSystem);
  this->pvs.__vftable = (idPVS_vtbl *)&idPVS::`vftable';
  idPVS::Free(this: &this->pvs);
  idStr::FreeData(this: &this->pvs.pvsName);
  if ( this->push.pushed.listStatic == 0 || this->push.pushed.listStatic == 2 )
  {
    list = this->push.pushed.list;
    if ( list != nullptr )
      idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
    this->push.pushed.list = nullptr;
    this->push.pushed.size = 0;
  }
  this->push.pushed.num = 0;
  idClip::~idClip(this: &this->clip);
  idTraceModelRecycler::~idTraceModelRecycler(this: &this->traceModelRecycler);
  idTraceModelCache::~idTraceModelCache(this: &this->traceModelCache);
  idGameLibEffects::~idGameLibEffects(this: &this->gameLibEffects);
  idStr::FreeData(this: &this->mapName);
}


// ========================================================================
// __unwind$501486
// EA  : 0x82B5249C
// RVA : 0x00B5249C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501486()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 20));
}


// ========================================================================
// __unwind$501487
// EA  : 0x82B524C8
// RVA : 0x00B524C8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501487()
{
  int v0; // r12

  idGameLibEffects::~idGameLibEffects(this: (idGameLibEffects *)(*(_DWORD *)(v0 - 144 + 164) + 72));
}


// ========================================================================
// __unwind$501488
// EA  : 0x82B524F4
// RVA : 0x00B524F4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501488()
{
  int v0; // r12

  idTraceModelCache::~idTraceModelCache(this: (idTraceModelCache *)(*(_DWORD *)(v0 - 144 + 164) + 10504));
}


// ========================================================================
// __unwind$501489
// EA  : 0x82B52520
// RVA : 0x00B52520
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501489()
{
  int v0; // r12

  idTraceModelRecycler::~idTraceModelRecycler(this: (idTraceModelRecycler *)(*(_DWORD *)(v0 - 144 + 164) + 10604));
}


// ========================================================================
// __unwind$501490
// EA  : 0x82B5254C
// RVA : 0x00B5254C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501490()
{
  int v0; // r12

  idClip::~idClip(this: (idClip *)(*(_DWORD *)(v0 - 144 + 164) + 10688));
}


// ========================================================================
// __unwind$501491_0
// EA  : 0x82B52578
// RVA : 0x00B52578
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501491_0()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 144 + 164) + 470976));
}


// ========================================================================
// __unwind$501492
// EA  : 0x82B525AC
// RVA : 0x00B525AC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501492()
{
  int v0; // r12

  idPVS::~idPVS(this: (idPVS *)(*(_DWORD *)(v0 - 144 + 164) + 470996));
}


// ========================================================================
// __unwind$501493
// EA  : 0x82B525E0
// RVA : 0x00B525E0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501493()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 471192));
}


// ========================================================================
// __unwind$501494
// EA  : 0x82B52614
// RVA : 0x00B52614
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501494()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 471208));
}


// ========================================================================
// __unwind$501495
// EA  : 0x82B52648
// RVA : 0x00B52648
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501495()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 144 + 164) + 471224));
}


// ========================================================================
// __unwind$501496
// EA  : 0x82B5267C
// RVA : 0x00B5267C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501496()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 471256));
}


// ========================================================================
// __unwind$501497
// EA  : 0x82B526B0
// RVA : 0x00B526B0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501497()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 504040));
}


// ========================================================================
// __unwind$501498
// EA  : 0x82B526E4
// RVA : 0x00B526E4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501498()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 144 + 164) + 504064));
}


// ========================================================================
// __unwind$501499
// EA  : 0x82B52718
// RVA : 0x00B52718
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501499()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 504200));
}


// ========================================================================
// __unwind$501500
// EA  : 0x82B5274C
// RVA : 0x00B5274C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501500()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 504216));
}


// ========================================================================
// __unwind$501501
// EA  : 0x82B52780
// RVA : 0x00B52780
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501501()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 504232));
}


// ========================================================================
// __unwind$501502
// EA  : 0x82B527B4
// RVA : 0x00B527B4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501502()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 504248));
}


// ========================================================================
// __unwind$501503
// EA  : 0x82B527E8
// RVA : 0x00B527E8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501503()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 504264));
}


// ========================================================================
// __unwind$501504
// EA  : 0x82B5281C
// RVA : 0x00B5281C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501504()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 511516));
}


// ========================================================================
// __unwind$501505
// EA  : 0x82B52850
// RVA : 0x00B52850
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501505()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 511580));
}


// ========================================================================
// __unwind$501506
// EA  : 0x82B52884
// RVA : 0x00B52884
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501506()
{
  int v0; // r12

  idInfluenceTrailManager::~idInfluenceTrailManager(this: (idInfluenceTrailManager *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                    + 511596));
}


// ========================================================================
// __unwind$501507
// EA  : 0x82B528B8
// RVA : 0x00B528B8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501507()
{
  int v0; // r12

  idDeferredFireManager::~idDeferredFireManager(this: (idDeferredFireManager *)(*(_DWORD *)(v0 - 144 + 164) + 521336));
}


// ========================================================================
// __unwind$501508
// EA  : 0x82B528EC
// RVA : 0x00B528EC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501508()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 695800));
}


// ========================================================================
// __unwind$501610
// EA  : 0x82B52920
// RVA : 0x00B52920
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501610()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$501984
// EA  : 0x82B52948
// RVA : 0x00B52948
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_501984()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 80) + 32));
}


// ========================================================================
// ?FindFreePresentableIndex@idClientGame@@QAAHHH@Z
// EA  : 0x82B52978
// RVA : 0x00B52978
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::FindFreePresentableIndex(idClientGame *this, int index, int freeListType)
{
  int v4; // r4
  int v5; // r6
  int v6; // r7
  int num; // r9
  int v8; // r11
  int v9; // r10
  signed int v10; // r10
  signed int v11; // r5
  int v13[4]; // [sp+50h] [-20h] BYREF

  v4 = 12288;
  if ( freeListType != 1 )
    v4 = 0x2000;
  v5 = 504204;
  v6 = 504200;
  if ( index == -1 )
  {
    num = this->presentables.num;
    if ( v4 < num )
      num = v4;
    v8 = 4 * (freeListType + 126070);
    v9 = *(unsigned int *)((char *)&this->random.seed + v8);
    if ( v9 < num )
    {
      v10 = v9;
      do
      {
        if ( this->presentables.list[v10] == nullptr )
          break;
        v11 = *(unsigned int *)((char *)&this->random.seed + v8) + 1;
        *(unsigned int *)((char *)&this->random.seed + v8) = v11;
        v10 = v11;
      }
      while ( v11 < num );
    }
    index = *(unsigned int *)((char *)&this->random.seed + v8);
    *(unsigned int *)((char *)&this->random.seed + v8) = index + 1;
  }
  if ( index >= v4 )
    idLib::Error(fmt: "No free presentables.\n");
  if ( index >= *(signed int *)((char *)&this->random.seed + v5) )
  {
    v13[0] = 0;
    idList<idRenderModelCommitted *,5>::SetNum(
      this: (idList<int,5> *)((char *)this + v6),
      newNum: index + 1,
      initValue: v13);
  }
  return index;
}


// ========================================================================
// ?GetLocalViewCallbacks@idClientGame@@QAAABV?$idList@PAVidViewCallbacks@@$04@@XZ
// EA  : 0x82B52A70
// RVA : 0x00B52A70
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

const idList<idViewCallbacks *,5> *__fastcall idClientGame::GetLocalViewCallbacks(idClientGame *this)
{
  int v2; // r26
  idArray<int,4> *p_inputToPlayerIndexRouting; // r28
  int v4; // r11
  idPresentable *v5; // r3
  int v6; // r3
  int v8; // [sp+50h] [-40h] BYREF

  if ( this->activeViewCallbacks.num > 0 )
    return &this->activeViewCallbacks;
  v2 = 4;
  p_inputToPlayerIndexRouting = &this->inputToPlayerIndexRouting;
  do
  {
    v4 = p_inputToPlayerIndexRouting->ptr[0];
    if ( p_inputToPlayerIndexRouting->ptr[0] >= 0 && v4 < this->presentables.num )
    {
      v5 = this->presentables.list[v4];
      if ( v5 != nullptr )
      {
        v6 = (int)v5->GetPlayerInterface_2(this: v5);
        if ( v6 != 0 )
        {
          v8 = *(_DWORD *)(v6 + 23332);
          idList<idAnimWebBlendTree *,5>::Append(
            this: (idList<enum encounterGroupRole_t,5> *)&this->activeViewCallbacks,
            obj: (encounterGroupRole_t *)&v8);
        }
      }
    }
    --v2;
    p_inputToPlayerIndexRouting = (idArray<int,4> *)((char *)p_inputToPlayerIndexRouting + 4);
  }
  while ( v2 != 0 );
  return &this->activeViewCallbacks;
}


// ========================================================================
// ?ReadFromSnapshot@idClientGame@@QAAXAAVidSnapShot@@PBV2@@Z
// EA  : 0x82B52B38
// RVA : 0x00B52B38
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ReadFromSnapshot(idClientGame *this, idSnapShot *ss, const idSnapShot *oldss)
{
  unsigned __int64 v3; // r29
  int ObjectIndexByID; // r3
  int v7; // r31
  idArray<idReplicatedSound,32> *p_replicatedSounds; // r30
  unsigned __int8 *lastChanged; // r27
  unsigned __int8 *v10; // r31
  idLobbyBase *v11; // r3
  int v12; // r5
  int v13; // r11
  unsigned __int8 *v14; // r28
  char v15; // r11
  int v16; // r11
  idPresentable *v17; // r6
  bool v18; // r10
  idPresentable *v19; // r30
  int v20; // r11
  int v21; // r11
  idSoundWorld_vtbl *v22; // r11
  unsigned __int8 *v23; // r11
  unsigned __int8 *v24; // r10
  int i; // ctr
  int v27; // r31
  idList<idPresentable *,5> *p_presentables; // r27
  idPresentablePlayer *LocalPresentablePlayer; // r3
  int v30; // [sp+50h] [-180h]
  idSerializer v31; // [sp+58h] [-178h] BYREF
  idBitMsg v32; // [sp+60h] [-170h] BYREF
  soundShaderParms_t v33; // [sp+90h] [-140h] BYREF

  LODWORD(v3) = 0;
  if ( idSnapShot::FindObjectIndexByID(this: ss, objectNum: 5019) != -1 )
  {
    memset(&v32, 0, 30);
    v32.tempValue = v3;
    ObjectIndexByID = idSnapShot::FindObjectIndexByID(this: ss, objectNum: 5019);
    if ( idSnapShot::GetObjectMsgByIndex(this: ss, i: ObjectIndexByID, msg: &v32, ignoreIfStale: false) == 5019
      && (v32.writeBit != 0) + v32.curSize > 0 )
    {
      v31.writing = false;
      v31.msg = &v32;
      v7 = 32;
      p_replicatedSounds = &this->replicatedSounds;
      do
      {
        idReplicatedSound::Serialize(this: p_replicatedSounds->ptr, ser: &v31);
        --v7;
        p_replicatedSounds = (idArray<idReplicatedSound,32> *)((char *)p_replicatedSounds + 224);
      }
      while ( v7 != 0 );
      v30 = 32;
      lastChanged = this->replicatedSounds.ptr[0].lastChanged;
      while ( 1 )
      {
        v10 = lastChanged - 206;
        v11 = session->GetActingGameStateLobbyBase(this: session);
        v12 = 1 << v11->PeerIndexOnHost(this: v11);
        if ( (*(lastChanged - 8) & (unsigned __int8)v12) == 0 )
          goto LABEL_58;
        v13 = 0;
        v14 = lastChanged - 7;
        while ( v14[v13] == lastChanged[v13] )
        {
          if ( ++v13 >= 7 )
          {
            v15 = 0;
            goto LABEL_12;
          }
        }
        v15 = 1;
LABEL_12:
        if ( v15 == 0 )
          goto LABEL_58;
        v16 = *((unsigned __int16 *)v10 + 98);
        if ( v16 == 0xFFFF )
        {
          v21 = *((_DWORD *)v10 + 1);
          if ( v21 != 0 )
          {
            if ( mp_cg_soundDebug.valueInteger != 0 )
              idLib::Printf(fmt: "Global Sound: Channel %i Name: %s\n", *(_DWORD *)v10, *(const char **)(v21 + 8));
            v22 = this->soundWorld->__vftable;
            if ( (*((_DWORD *)v10 + 2) & 1) != 0 )
              ((void (__fastcall *)(double))v22->PlayGlobalShaderDirectly)(a1: 0.0);
            else
              ((void (__fastcall *)(double))v22->PlayPositionedShaderDirectly)(a1: 0.0);
          }
          goto LABEL_56;
        }
        if ( v16 >= this->presentables.num )
        {
          v18 = false;
        }
        else
        {
          v17 = this->presentables.list[v16];
          LOBYTE(v12) = (_BYTE)v17 - 1;
          v18 = v17 != nullptr;
        }
        if ( v18 )
        {
          v19 = this->presentables.list[v16];
          if ( v19 != nullptr )
          {
            v20 = *((_DWORD *)v10 + 1);
            if ( v20 == 0 )
            {
              if ( mp_cg_soundDebug.valueInteger != 0 )
                idLib::Printf(fmt: "Stop Sound: Channel %i\n", *(_DWORD *)v10);
              if ( idPresentable::IsPlayingSound(this: v19, channel: *(const soundChannel_t *)v10) )
                idPresentable::StopSound(this: v19, channel: *(const soundChannel_t *)v10, peerMask: 0);
              goto LABEL_56;
            }
            if ( mp_cg_soundDebug.valueInteger != 0 )
              idLib::Printf(fmt: "Sound Changed: Channel %i Name: %s", *(_DWORD *)v10, *(const char **)(v20 + 8));
            if ( *v14 != *lastChanged )
            {
              soundShaderParms_t::Clear(this: &v33);
              soundShaderParms_t::Override(this: &v33, over: (const soundShaderParms_t *)(v10 + 36));
              idPresentable::StartSoundShader(
                this: v19,
                channel: *(const soundChannel_t *)v10,
                shader: *((const idSoundShader **)v10 + 1),
                parms: &v33,
                peerMask: 0);
              if ( mp_cg_soundDebug.valueInteger != 0 )
                idLib::Printf(fmt: " - RS_PLAYED");
            }
            if ( v10[200] != v10[207] )
            {
              idPresentable::SetSoundVolume(
                this: v19,
                channel: *(const soundChannel_t *)v10,
                volume: *((float *)v10 + 3),
                peerMask: v12);
              if ( mp_cg_soundDebug.valueInteger != 0 )
                idLib::Printf(fmt: " - RS_VOLUME");
            }
            if ( v10[201] != v10[208] )
            {
              idPresentable::SetSoundPitch(
                this: v19,
                channel: *(const soundChannel_t *)v10,
                pitch: *((float *)v10 + 4),
                peerMask: v12);
              if ( mp_cg_soundDebug.valueInteger != 0 )
                idLib::Printf(fmt: " - RS_PITCH");
            }
            if ( v10[203] != v10[210] )
            {
              idPresentable::FadeSound(
                this: v19,
                channel: *(soundChannel_t *)v10,
                to: *((float *)v10 + 5),
                over: *((float *)v10 + 6));
              if ( mp_cg_soundDebug.valueInteger != 0 )
                idLib::Printf(fmt: " - RS_SOUNDFADE");
            }
            if ( v10[202] != v10[209] )
            {
              idPresentable::ModifySound(
                this: v19,
                channel: *(const soundChannel_t *)v10,
                shader: *((const idSoundShader **)v10 + 1),
                parms: (const soundShaderParms_t *)(v10 + 36),
                peerMask: 0);
              if ( mp_cg_soundDebug.valueInteger != 0 )
                idLib::Printf(fmt: " - RS_PARM");
            }
            if ( v10[204] != v10[211] )
            {
              idPresentable::SetVolumeAdjustment(
                this: v19,
                channel: *(const soundChannel_t *)v10,
                adjustment: *((float *)v10 + 7),
                peerMask: v12);
              if ( mp_cg_soundDebug.valueInteger != 0 )
                idLib::Printf(fmt: " - RS_VOLUME_ADJUSTMENT");
            }
            if ( v10[205] == v10[212] )
              goto LABEL_44;
            idPresentable::SetClearVolumeAdjustment(this: v19, channel: *(const soundChannel_t *)v10, peerMask: 0);
            if ( mp_cg_soundDebug.valueInteger != 0 )
              break;
          }
        }
LABEL_56:
        v23 = lastChanged - 8;
        v24 = lastChanged - 1;
        for ( i = 7; i != 0; --i )
          *++v24 = *++v23;
LABEL_58:
        lastChanged += 224;
        if ( v30-- == 1 )
        {
          LODWORD(v3) = 0;
          goto LABEL_60;
        }
      }
      idLib::Printf(fmt: " - RS_CLEAR_ADJUSTMENT");
LABEL_44:
      if ( mp_cg_soundDebug.valueInteger != 0 )
        idLib::Printf(fmt: "\n");
      goto LABEL_56;
    }
  }
LABEL_60:
  this->serialized = true;
  if ( com_drawPresentables.valueInteger != 0 )
  {
    console->ClearPresentables(this: console);
    if ( this->presentables.num > 0 )
    {
      v27 = 0;
      p_presentables = &this->presentables;
      do
      {
        if ( p_presentables->list[v27] != nullptr )
          console->AddPresentableObject(
            this: console,
            a2: p_presentables->list[v27]->debugName,
            a3: p_presentables->list[v27]->index,
            a4: (p_presentables->list[v27]->index >> 31) + (p_presentables->list[v27]->index >= 0x2000u));
        LODWORD(v3) = v3 + 1;
        ++v27;
      }
      while ( (int)v3 < this->presentables.num );
    }
  }
  LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this);
  if ( LocalPresentablePlayer != nullptr && LocalPresentablePlayer->sentOfficialSnap )
    ++gameLocal->numSnapshotsSerialized;
}


// ========================================================================
// ?GetChallengeMode@idClientGame@@QBA?AW4challengeGameMode_t@@XZ
// EA  : 0x82B53148
// RVA : 0x00B53148
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

challengeGameMode_t __fastcall idClientGame::GetChallengeMode(idClientGame *this)
{
  if ( common->IsServer(this: common) )
    return idGameLocal::GetChallengeMode(this: gameLocal);
  else
    return this->serializedChallengeMode;
}


// ========================================================================
// ?MarkPresentableSerialized@idClientGame@@QAAXPAVidPresentable@@_N1@Z
// EA  : 0x82B531C0
// RVA : 0x00B531C0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::MarkPresentableSerialized(
        idClientGame *this,
        idPresentable *presentable,
        bool serialized,
        bool deleted,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idPresentable *a14)
{
  int index; // r4
  idLobbyBase *v19; // r3
  int serializedIndex; // r11
  idLobbyBase *v21; // r3

  a14 = presentable;
  if ( common->IsServer(this: common) )
  {
    index = presentable->index;
    if ( index < 0x2000 && com_multiplayer.valueInteger != 0 )
    {
      if ( cg_optimizeSnapSerialize_debug.valueInteger != 0 && (!serialized || deleted) )
        idLib::Printf(
          fmt: "Snapshot presentable %d entity %d serialized %d deleted %d\n",
          index,
          presentable->entityNumber,
          serialized,
          deleted);
      if ( serialized )
      {
        presentable->stopSerializeCount = 0;
        if ( presentable->serializedIndex == -1 )
          presentable->serializedIndex = idList<idAnimWebBlendTree *,5>::Append(
                                           this: (idList<enum encounterGroupRole_t,5> *)&this->serializedPresentables,
                                           obj: (encounterGroupRole_t *)&a14);
        v19 = session->GetActingGameStateLobbyBase(this: session);
        v19->RefreshSnapObj(this: v19, a2: presentable->index + 19);
      }
      else
      {
        serializedIndex = presentable->serializedIndex;
        if ( serializedIndex != -1 )
        {
          this->serializedPresentables.list[serializedIndex] = this->serializedPresentables.list[this->serializedPresentables.num
                                                                                               - 1];
          this->serializedPresentables.list[presentable->serializedIndex]->serializedIndex = presentable->serializedIndex;
          idList<idObstacleBuffers *,5>::SetNum(
            this: (idList<int,37> *)&this->serializedPresentables,
            newNum: this->serializedPresentables.num - 1);
          presentable->serializedIndex = -1;
        }
        if ( deleted )
        {
          v21 = session->GetActingGameStateLobbyBase(this: session);
          v21->MarkSnapObjDeleted(this: v21, a2: presentable->index + 19);
        }
      }
    }
  }
}


// ========================================================================
// ?MarkAllPresentablesAsSerialized@idClientGame@@QAAX_N@Z
// EA  : 0x82B53368
// RVA : 0x00B53368
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::MarkAllPresentablesAsSerialized(
        idClientGame *this,
        bool skyOnly,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int *p_num; // r27
  int v11; // r29
  int v12; // r30
  idList<idPresentable *,5> *p_activePresentables; // r26
  idPresentable *v14; // r31
  idRenderModel *model; // r11
  int v16; // [sp+8h] [-98h]
  int v17; // [sp+Ch] [-94h]
  int v18; // [sp+10h] [-90h]
  int v19; // [sp+14h] [-8Ch]
  int v20; // [sp+18h] [-88h]
  idPresentable *v21; // [sp+1Ch] [-84h]

  p_num = &this->activePresentables.num;
  v11 = 0;
  if ( this->activePresentables.num > 0 )
  {
    v12 = 0;
    p_activePresentables = &this->activePresentables;
    do
    {
      v14 = p_activePresentables->list[v12];
      if ( v14 != nullptr
        && v14->index < 0x2000
        && (!skyOnly || (model = v14->model) != nullptr && strstr(str1: model->name.str, str2: "w2_skydome") != nullptr) )
      {
        idClientGame::MarkPresentableSerialized(
          this,
          presentable: v14,
          serialized: true,
          deleted: false,
          a5,
          a6,
          a7,
          a8,
          a9: v16,
          a10: v17,
          a11: v18,
          a12: v19,
          a13: v20,
          a14: v21);
      }
      ++v11;
      ++v12;
    }
    while ( v11 < *p_num );
  }
}


// ========================================================================
// ??0idClientGame@@QAA@XZ
// EA  : 0x82B534E8
// RVA : 0x00B534E8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idClientGame *__fastcall idClientGame::idClientGame(idClientGame *this)
{
  int v2; // r27
  idArray<idReplicatedSound,32> *p_replicatedSounds; // r26
  int v4; // r4
  int v5; // ctr
  int *v6; // r11
  int v7; // ctr
  __int16 *p_granularity; // r9
  idRageMetrics *v9; // r3
  idRageMetrics *v10; // r3

  this->random.seed = 0;
  this->mapName.allocedAndFlag = 20;
  this->mapName.len = 0;
  this->mapName.data = this->mapName.baseBuffer;
  this->mapName.baseBuffer[0] = 0;
  idGameLibEffects::idGameLibEffects(this: &this->gameLibEffects);
  idTraceModelCache::idTraceModelCache(this: &this->traceModelCache);
  idTraceModelRecycler::idTraceModelRecycler(this: &this->traceModelRecycler);
  idClip::idClip(this: &this->clip);
  this->push.pushed.list = nullptr;
  this->push.pushed.granularity = 0;
  this->push.pushed.memTag = 77;
  this->push.pushed.listStatic = 0;
  this->push.pushed.size = 0;
  this->push.pushed.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->push.pushed);
  this->push.clip = nullptr;
  idPVS::idPVS(this: &this->pvs);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&this->eventSystem);
  this->objectList.list = nullptr;
  this->objectList.granularity = 0;
  this->objectList.memTag = 5;
  this->objectList.listStatic = 0;
  this->objectList.size = 0;
  this->objectList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->objectList);
  this->objectHash.memTag = TAG_HASHINDEX;
  idHashIndex::InternalInit(this: &this->objectHash, initialHashSize: 1024, initialIndexSize: 1024);
  this->aimAssistTargets.list = nullptr;
  this->aimAssistTargets.granularity = 0;
  this->aimAssistTargets.memTag = 5;
  this->aimAssistTargets.listStatic = 0;
  this->aimAssistTargets.size = 0;
  this->aimAssistTargets.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->aimAssistTargets);
  this->presentableThinks.list = nullptr;
  this->presentableThinks.granularity = 0;
  this->presentableThinks.memTag = 5;
  this->presentableThinks.listStatic = 0;
  this->presentableThinks.size = 0;
  this->presentableThinks.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->presentableThinks);
  idGameTimeManager::idGameTimeManager(this: &this->gameTimeManager);
  this->presentables.list = nullptr;
  this->presentables.granularity = 0;
  this->presentables.memTag = 5;
  this->presentables.listStatic = 0;
  this->presentables.size = 0;
  this->presentables.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->presentables);
  this->activePresentables.list = nullptr;
  this->activePresentables.granularity = 0;
  this->activePresentables.memTag = 5;
  this->activePresentables.listStatic = 0;
  this->activePresentables.size = 0;
  this->activePresentables.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activePresentables);
  this->pusherPresentables.list = nullptr;
  this->pusherPresentables.granularity = 0;
  this->pusherPresentables.memTag = 5;
  this->pusherPresentables.listStatic = 0;
  this->pusherPresentables.size = 0;
  this->pusherPresentables.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pusherPresentables);
  this->vehiclePresentables.list = nullptr;
  this->vehiclePresentables.granularity = 0;
  this->vehiclePresentables.memTag = 5;
  this->vehiclePresentables.listStatic = 0;
  this->vehiclePresentables.size = 0;
  this->vehiclePresentables.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->vehiclePresentables);
  this->serializedPresentables.list = nullptr;
  this->serializedPresentables.granularity = 0;
  this->serializedPresentables.memTag = 5;
  this->serializedPresentables.listStatic = 0;
  this->serializedPresentables.size = 0;
  this->serializedPresentables.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->serializedPresentables);
  this->lobbyUserIDs.ptr[0].localUserHandle.handle = 0;
  this->lobbyUserIDs.ptr[0].lobbyType = -1;
  this->lobbyUserIDs.ptr[1].localUserHandle.handle = 0;
  this->lobbyUserIDs.ptr[1].lobbyType = -1;
  v2 = 31;
  this->lobbyUserIDs.ptr[2].localUserHandle.handle = 0;
  p_replicatedSounds = &this->replicatedSounds;
  this->lobbyUserIDs.ptr[2].lobbyType = -1;
  this->lobbyUserIDs.ptr[3].localUserHandle.handle = 0;
  this->lobbyUserIDs.ptr[3].lobbyType = -1;
  this->lobbyUserIDs.ptr[4].localUserHandle.handle = 0;
  this->lobbyUserIDs.ptr[4].lobbyType = -1;
  this->lobbyUserIDs.ptr[5].localUserHandle.handle = 0;
  this->lobbyUserIDs.ptr[5].lobbyType = -1;
  do
  {
    idReplicatedSound::idReplicatedSound(this: p_replicatedSounds->ptr);
    --v2;
    p_replicatedSounds = (idArray<idReplicatedSound,32> *)((char *)p_replicatedSounds + 224);
  }
  while ( v2 >= 0 );
  this->startSoundOverRun.list = nullptr;
  this->startSoundOverRun.granularity = 0;
  this->startSoundOverRun.memTag = 5;
  this->startSoundOverRun.listStatic = 0;
  this->startSoundOverRun.size = 0;
  this->startSoundOverRun.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->startSoundOverRun);
  this->activeViewCallbacks.list = nullptr;
  this->activeViewCallbacks.granularity = 0;
  this->activeViewCallbacks.memTag = 5;
  this->activeViewCallbacks.listStatic = 0;
  this->activeViewCallbacks.size = 0;
  this->activeViewCallbacks.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->activeViewCallbacks);
  idInfluenceTrailManager::idInfluenceTrailManager(this: &this->influenceTrailManager);
  idDeferredFireManager::idDeferredFireManager(this: &this->deferredFireManager);
  this->queuedReliableMsgs.list = nullptr;
  this->queuedReliableMsgs.granularity = 0;
  this->queuedReliableMsgs.memTag = 5;
  this->queuedReliableMsgs.listStatic = 0;
  this->queuedReliableMsgs.size = 0;
  this->queuedReliableMsgs.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->queuedReliableMsgs);
  this->renderWorld = nullptr;
  this->soundWorld = nullptr;
  v5 = 6;
  v6 = &this->inputToPlayerIndexRouting.ptr[3];
  this->guiModel = nullptr;
  do
  {
    *++v6 = 0;
    --v5;
  }
  while ( v5 != 0 );
  this->firstRenderFrame = 0;
  this->lastRenderFrame = 0;
  this->serializedChallengeMode = CHALLENGE_MODE_NORMAL;
  idGameTimeManager::Clear(this: &this->gameTimeManager, a2: v4);
  this->vehicleRaceMap = false;
  this->serverTime = 0;
  this->previousServerTime = 0;
  this->ssEndTime = 0;
  this->ssStartTime = 0;
  v7 = 0x2000;
  this->playerTime = -1;
  this->firstFreePresentable.ptr[1] = 0x2000;
  this->firstFreePresentable.ptr[0] = 6;
  this->firstFreePresentable.ptr[2] = 12288;
  p_granularity = &this->aimAssistTargets.granularity;
  do
  {
    p_granularity += 2;
    *(_DWORD *)p_granularity = -1;
    --v7;
  }
  while ( v7 != 0 );
  this->inputToPlayerIndexRouting.ptr[0] = -1;
  this->inputToPlayerIndexRouting.ptr[1] = -1;
  this->inputToPlayerIndexRouting.ptr[2] = -1;
  this->inputToPlayerIndexRouting.ptr[3] = -1;
  this->serialized = false;
  this->presentableSpawnId = 1;
  this->overrideSoundPeerMask = 0;
  v9 = (idRageMetrics *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x7544u,
                          tag: TAG_GAME,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v9 != nullptr )
    v10 = idRageMetrics::idRageMetrics(this: v9);
  else
    v10 = nullptr;
  this->rageMetrics = v10;
  if ( common->IsMultiplayer(this: common) )
  {
    this->impressive = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                  this: &idDeclVoiceOver::resourceList,
                                                  name: "multiplayer/announcements_x/feedback/impressive",
                                                  makeDefault: true);
    this->doubleKill = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                  this: &idDeclVoiceOver::resourceList,
                                                  name: "multiplayer/announcements_x/feedback/double_kill",
                                                  makeDefault: true);
    this->tripleKill = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                  this: &idDeclVoiceOver::resourceList,
                                                  name: "multiplayer/announcements_x/feedback/triple_kill",
                                                  makeDefault: true);
    this->quadKill = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                this: &idDeclVoiceOver::resourceList,
                                                name: "multiplayer/announcements_x/feedback/quad_kill",
                                                makeDefault: true);
    this->slaughter = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclVoiceOver::resourceList,
                                                 name: "multiplayer/announcements_x/feedback/slaughter",
                                                 makeDefault: true);
    this->revenge = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                               this: &idDeclVoiceOver::resourceList,
                                               name: "multiplayer/announcements_x/feedback/revenge",
                                               makeDefault: true);
    this->airMail = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                               this: &idDeclVoiceOver::resourceList,
                                               name: "multiplayer/announcements_x/feedback/air_mail",
                                               makeDefault: true);
    this->pull = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                            this: &idDeclVoiceOver::resourceList,
                                            name: "multiplayer/announcements_x/feedback/pull",
                                            makeDefault: true);
    this->afterLife = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclVoiceOver::resourceList,
                                                 name: "multiplayer/announcements_x/feedback/afterlife",
                                                 makeDefault: true);
    this->maxChain = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                this: &idDeclVoiceOver::resourceList,
                                                name: "multiplayer/announcements_x/feedback/max_chain",
                                                makeDefault: true);
    this->chainBreaker = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                    this: &idDeclVoiceOver::resourceList,
                                                    name: "multiplayer/announcements_x/feedback/chain_breaker",
                                                    makeDefault: true);
    this->denial = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                              this: &idDeclVoiceOver::resourceList,
                                              name: "multiplayer/announcements_x/feedback/denial",
                                              makeDefault: true);
    this->closeCall = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                 this: &idDeclVoiceOver::resourceList,
                                                 name: "multiplayer/announcements_x/feedback/close_call",
                                                 makeDefault: true);
    this->airRally = (const idDeclVoiceOver *)idDeclInfo::FindWithInheritance(
                                                this: &idDeclVoiceOver::resourceList,
                                                name: "multiplayer/announcements_x/feedback/air_rally",
                                                makeDefault: true);
  }
  else
  {
    this->impressive = nullptr;
    this->doubleKill = nullptr;
    this->tripleKill = nullptr;
    this->quadKill = nullptr;
    this->slaughter = nullptr;
    this->revenge = nullptr;
    this->airMail = nullptr;
    this->pull = nullptr;
    this->afterLife = nullptr;
    this->maxChain = nullptr;
    this->chainBreaker = nullptr;
    this->denial = nullptr;
    this->closeCall = nullptr;
    this->airRally = nullptr;
  }
  return this;
}


// ========================================================================
// __unwind$502932
// EA  : 0x82B53BF4
// RVA : 0x00B53BF4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502932()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 20));
}


// ========================================================================
// __unwind$502933
// EA  : 0x82B53C20
// RVA : 0x00B53C20
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502933()
{
  int v0; // r12

  idGameLibEffects::~idGameLibEffects(this: (idGameLibEffects *)(*(_DWORD *)(v0 - 160 + 180) + 72));
}


// ========================================================================
// __unwind$502934
// EA  : 0x82B53C4C
// RVA : 0x00B53C4C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502934()
{
  int v0; // r12

  idTraceModelCache::~idTraceModelCache(this: (idTraceModelCache *)(*(_DWORD *)(v0 - 160 + 180) + 10504));
}


// ========================================================================
// __unwind$502935
// EA  : 0x82B53C78
// RVA : 0x00B53C78
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502935()
{
  int v0; // r12

  idTraceModelRecycler::~idTraceModelRecycler(this: (idTraceModelRecycler *)(*(_DWORD *)(v0 - 160 + 180) + 10604));
}


// ========================================================================
// __unwind$502936
// EA  : 0x82B53CA4
// RVA : 0x00B53CA4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502936()
{
  int v0; // r12

  idClip::~idClip(this: (idClip *)(*(_DWORD *)(v0 - 160 + 180) + 10688));
}


// ========================================================================
// __unwind$502937
// EA  : 0x82B53CD0
// RVA : 0x00B53CD0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502937()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 160 + 180) + 470976));
}


// ========================================================================
// __unwind$502938
// EA  : 0x82B53D04
// RVA : 0x00B53D04
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502938()
{
  int v0; // r12

  idPVS::~idPVS(this: (idPVS *)(*(_DWORD *)(v0 - 160 + 180) + 470996));
}


// ========================================================================
// __unwind$502939
// EA  : 0x82B53D38
// RVA : 0x00B53D38
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502939()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 471192));
}


// ========================================================================
// __unwind$502940
// EA  : 0x82B53D6C
// RVA : 0x00B53D6C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502940()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 471208));
}


// ========================================================================
// __unwind$502941
// EA  : 0x82B53DA0
// RVA : 0x00B53DA0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502941()
{
  int v0; // r12

  idVectorSubset<idVec3,3>::~idVectorSubset<idVec3,3>(this: (idHashIndex *)(*(_DWORD *)(v0 - 160 + 180) + 471224));
}


// ========================================================================
// __unwind$502942
// EA  : 0x82B53DD4
// RVA : 0x00B53DD4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502942()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 471256));
}


// ========================================================================
// __unwind$502943
// EA  : 0x82B53E08
// RVA : 0x00B53E08
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502943()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 504040));
}


// ========================================================================
// __unwind$502944
// EA  : 0x82B53E3C
// RVA : 0x00B53E3C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502944()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)(*(_DWORD *)(v0 - 160 + 180) + 504064));
}


// ========================================================================
// __unwind$502945
// EA  : 0x82B53E70
// RVA : 0x00B53E70
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502945()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 504200));
}


// ========================================================================
// __unwind$502946
// EA  : 0x82B53EA4
// RVA : 0x00B53EA4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502946()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 504216));
}


// ========================================================================
// __unwind$502947
// EA  : 0x82B53ED8
// RVA : 0x00B53ED8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502947()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 504232));
}


// ========================================================================
// __unwind$502948
// EA  : 0x82B53F0C
// RVA : 0x00B53F0C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502948()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 504248));
}


// ========================================================================
// __unwind$502949
// EA  : 0x82B53F40
// RVA : 0x00B53F40
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502949()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 504264));
}


// ========================================================================
// __unwind$502950
// EA  : 0x82B53F74
// RVA : 0x00B53F74
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502950()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 511516));
}


// ========================================================================
// __unwind$502951
// EA  : 0x82B53FA8
// RVA : 0x00B53FA8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502951()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 511580));
}


// ========================================================================
// __unwind$502952
// EA  : 0x82B53FDC
// RVA : 0x00B53FDC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502952()
{
  int v0; // r12

  idInfluenceTrailManager::~idInfluenceTrailManager(this: (idInfluenceTrailManager *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                    + 511596));
}


// ========================================================================
// __unwind$502953
// EA  : 0x82B54010
// RVA : 0x00B54010
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502953()
{
  int v0; // r12

  idDeferredFireManager::~idDeferredFireManager(this: (idDeferredFireManager *)(*(_DWORD *)(v0 - 160 + 180) + 521336));
}


// ========================================================================
// __unwind$502954
// EA  : 0x82B54044
// RVA : 0x00B54044
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502954()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 695800));
}


// ========================================================================
// __unwind$502955
// EA  : 0x82B54078
// RVA : 0x00B54078
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_502955()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 160 + 80), tag: TAG_GAME);
}


// ========================================================================
// ?AddPresentable@idClientGame@@QAAXPAVidPresentable@@HH@Z
// EA  : 0x82B540A8
// RVA : 0x00B540A8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::AddPresentable(
        idClientGame *this,
        idPresentable *presentable,
        int index,
        int freeListType,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idPresentable *a14)
{
  int FreePresentableIndex; // r29
  unsigned int presentableSpawnId; // r11
  idList<enum encounterGroupRole_t,5> *p_pusherPresentables; // r3
  int v19; // r10
  int v20; // r9
  int v21; // r8
  int v22; // r7
  int v23; // [sp+8h] [-68h]
  int v24; // [sp+Ch] [-64h]
  int v25; // [sp+10h] [-60h]
  int v26; // [sp+14h] [-5Ch]
  int v27; // [sp+18h] [-58h]
  idPresentable *v28; // [sp+1Ch] [-54h]

  a14 = presentable;
  FreePresentableIndex = idClientGame::FindFreePresentableIndex(this, index, freeListType);
  this->presentables.list[FreePresentableIndex] = presentable;
  presentable->index = FreePresentableIndex;
  presentable->activeIndex = idList<idAnimWebBlendTree *,5>::Append(
                               this: (idList<enum encounterGroupRole_t,5> *)&this->activePresentables,
                               obj: (encounterGroupRole_t *)&a14);
  presentableSpawnId = this->presentableSpawnId;
  this->presentableSpawnId = presentableSpawnId + 1;
  presentable->spawnId = (presentableSpawnId << 14) | FreePresentableIndex;
  idPresentable::AddToEntityLUT(this: presentable);
  if ( presentable->GetPusherInterface(this: presentable) != nullptr )
  {
    p_pusherPresentables = (idList<enum encounterGroupRole_t,5> *)&this->pusherPresentables;
LABEL_5:
    idList<idAnimWebBlendTree *,5>::Append(this: p_pusherPresentables, obj: (encounterGroupRole_t *)&a14);
    goto LABEL_6;
  }
  if ( presentable->GetVehicleInterface(this: presentable) != nullptr )
  {
    p_pusherPresentables = (idList<enum encounterGroupRole_t,5> *)&this->vehiclePresentables;
    goto LABEL_5;
  }
LABEL_6:
  idClientGame::MarkPresentableSerialized(
    this,
    presentable,
    serialized: true,
    deleted: false,
    a5: v22,
    a6: v21,
    a7: v20,
    a8: v19,
    a9: v23,
    a10: v24,
    a11: v25,
    a12: v26,
    a13: v27,
    a14: v28);
}


// ========================================================================
// ?RemovePresentable@idClientGame@@QAAXPAVidPresentable@@@Z
// EA  : 0x82B54198
// RVA : 0x00B54198
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::RemovePresentable(
        idClientGame *this,
        lobbyUser_t *presentable,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        lobbyUser_t *a14)
{
  int v16; // r10
  int v17; // r9
  int v18; // r8
  int v19; // r7
  int v20; // r27
  int num; // r11
  int v22; // r28
  int size; // r11
  int v24; // r11
  int v25; // r11
  int v26; // r10
  signed int v27; // r11
  int v28; // [sp+8h] [-78h]
  int v29; // [sp+Ch] [-74h]
  int v30; // [sp+10h] [-70h]
  int v31; // [sp+14h] [-6Ch]
  int v32; // [sp+18h] [-68h]
  idPresentable *v33; // [sp+1Ch] [-64h]

  a14 = presentable;
  idPresentable::RemoveFromEntityLUT(this: (idPresentable *)presentable);
  idClientGame::MarkPresentableSerialized(
    this,
    (idPresentable *)presentable,
    serialized: false,
    deleted: true,
    a5: v19,
    a6: v18,
    a7: v17,
    a8: v16,
    a9: v28,
    a10: v29,
    a11: v30,
    a12: v31,
    a13: v32,
    a14: v33);
  v20 = *(_DWORD *)&presentable[5].gamertag[16];
  this->presentables.list[v20] = nullptr;
  this->activePresentables.list[presentable[5].pingMs] = this->activePresentables.list[this->activePresentables.num - 1];
  this->activePresentables.list[presentable[5].pingMs]->activeIndex = presentable[5].pingMs;
  num = this->activePresentables.num;
  v22 = num - 1;
  if ( num - 1 <= this->activePresentables.size
    || (unsigned __int8)idList<idNavSpline *,5>::Resize(
                          this: (idList<idSpawnArea::GeneratedPosition *,5> *)&this->activePresentables,
                          newsize: num - 1) != 0 )
  {
    size = this->activePresentables.size;
    if ( v22 < size )
      size = v22;
    this->activePresentables.num = size;
  }
  if ( v20 >= 6 )
  {
    v24 = *(_DWORD *)&presentable[5].gamertag[16];
    if ( v24 < 12288 )
      v25 = (v24 >> 31) + ((unsigned int)v24 >= 0x2000);
    else
      v25 = 2;
    v26 = 4 * (v25 + 126070);
    v27 = *(unsigned int *)((char *)&this->random.seed + v26);
    if ( v27 >= v20 )
      v27 = v20;
    *(unsigned int *)((char *)&this->random.seed + v26) = v27;
  }
  if ( (*(int (__fastcall **)(lobbyUser_t *))(*(_DWORD *)&presentable->isBot + 160))(a1: presentable) != 0 )
  {
    idList<idPresentableAnimatedEntity *,5>::Remove(
      this: (idList<lobbyUser_t *,5> *)&this->pusherPresentables,
      obj: &a14);
  }
  else if ( (*(int (__fastcall **)(lobbyUser_t *))(*(_DWORD *)&presentable->isBot + 76))(a1: presentable) != 0 )
  {
    idList<idPresentableAnimatedEntity *,5>::Remove(
      this: (idList<lobbyUser_t *,5> *)&this->vehiclePresentables,
      obj: &a14);
  }
}


// ========================================================================
// ?MakePresentableNonReplicated@idClientGame@@QAAXPAVidPresentable@@@Z
// EA  : 0x82B54328
// RVA : 0x00B54328
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::MakePresentableNonReplicated(
        idClientGame *this,
        lobbyUser_t *presentable,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  int v10; // r10
  int v11; // r9
  int v12; // r8
  int v13; // r7
  int v14; // [sp+8h] [-68h]
  int v15; // [sp+8h] [-68h]
  int v16; // [sp+Ch] [-64h]
  int v17; // [sp+Ch] [-64h]
  int v18; // [sp+10h] [-60h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  int v21; // [sp+14h] [-5Ch]
  int v22; // [sp+18h] [-58h]
  int v23; // [sp+18h] [-58h]
  lobbyUser_t *v24; // [sp+1Ch] [-54h]
  idPresentable *v25; // [sp+1Ch] [-54h]

  idClientGame::RemovePresentable(
    this,
    presentable,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v14,
    a10: v16,
    a11: v18,
    a12: v20,
    a13: v22,
    a14: v24);
  idClientGame::AddPresentable(
    this,
    (idPresentable *)presentable,
    index: -1,
    freeListType: 1,
    a5: v13,
    a6: v12,
    a7: v11,
    a8: v10,
    a9: v15,
    a10: v17,
    a11: v19,
    a12: v21,
    a13: v23,
    a14: v25);
}


// ========================================================================
// ?AddThink@idClientGame@@QAAXPBD_NM@Z
// EA  : 0x82B54378
// RVA : 0x00B54378
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::AddThink(idClientGame *this, const char *name, bool isDormant, double ms)
{
  int *p_num; // r25
  int v9; // r29
  int v10; // r30
  idList<presentableThink_t,5> *v11; // r28
  presentableThink_t *v12; // r31
  idList<presentableThink_t,5> *p_presentableThinks; // r31
  int num; // r11
  int size; // r10
  presentableThink_t *list; // r10
  int v17; // r11
  double v18; // fp0
  int maxThinks; // r10
  int v21; // r11

  p_num = &this->presentableThinks.num;
  v9 = 0;
  if ( this->presentableThinks.num <= 0 )
  {
LABEL_5:
    p_presentableThinks = &this->presentableThinks;
    idList<presentableThink_t,5>::PreAllocateWithGranularity(
      this: &this->presentableThinks,
      newSize: this->presentableThinks.num + 1);
    num = this->presentableThinks.num;
    size = this->presentableThinks.size;
    if ( num >= size )
    {
      v17 = (int)&p_presentableThinks->list[size - 1];
    }
    else
    {
      list = p_presentableThinks->list;
      this->presentableThinks.num = num + 1;
      v17 = (int)&list[num];
    }
    *(float *)(v17 + 4) = ms;
    *(float *)(v17 + 8) = ms;
    *(float *)(v17 + 16) = ms;
    *(_DWORD *)v17 = name;
    *(_DWORD *)(v17 + 20) = 1;
    *(_DWORD *)(v17 + 24) = isDormant;
    *(float *)(v17 + 12) = 0.0;
    *(_DWORD *)(v17 + 28) = 1;
    *(_DWORD *)(v17 + 36) = 1;
  }
  else
  {
    v10 = 0;
    v11 = &this->presentableThinks;
    while ( 1 )
    {
      v12 = &v11->list[v10];
      if ( idStr::Icmp(s1: v12->name, s2: name) == 0 )
        break;
      ++v9;
      ++v10;
      if ( v9 >= *p_num )
        goto LABEL_5;
    }
    v18 = (float)(v12->ms + (float)ms);
    v12->ms = v12->ms + (float)ms;
    if ( isDormant )
      ++v12->numDormantThinks;
    _FP12 = (float)((float)v18 - v12->maxms);
    maxThinks = v12->maxThinks;
    v21 = v12->numThinks + 1;
    v12->numThinks = v21;
    __asm { fsel      f11, f12, f0, f13 }
    v12->maxms = _FP11;
    if ( v21 <= maxThinks )
      v21 = maxThinks;
    v12->maxThinks = v21;
  }
}


// ========================================================================
// ?AddSimulatingEffectPhysics@idClientGame@@QAAXPAVidEffectPhysicsBroadPhase@@@Z
// EA  : 0x82B544F8
// RVA : 0x00B544F8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::AddSimulatingEffectPhysics(
        idClientGame *this,
        idEffectPhysicsBroadPhase *broadPhase,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idEffectPhysicsBroadPhase *a14)
{
  int v14; // r10
  idList<enum encounterGroupRole_t,5> *p_simulatingEffectPhysics; // r3
  int num; // r9
  int v17; // r11

  a14 = broadPhase;
  v14 = 0;
  p_simulatingEffectPhysics = (idList<enum encounterGroupRole_t,5> *)&gameLocal->simulatingEffectPhysics;
  num = p_simulatingEffectPhysics->num;
  if ( num <= 0 )
    goto LABEL_7;
  v17 = 0;
  while ( (idEffectPhysicsBroadPhase *)p_simulatingEffectPhysics->list[v17] != broadPhase )
  {
    ++v14;
    ++v17;
    if ( v14 >= num )
      goto LABEL_7;
  }
  if ( v14 < 0 )
LABEL_7:
    idList<idAnimWebBlendTree *,5>::Append(this: p_simulatingEffectPhysics, obj: (encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?AddPresentable@idClientGame@@QAAXPAVidPresentable@@H_N@Z
// EA  : 0x82B546E8
// RVA : 0x00B546E8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::AddPresentable(
        idClientGame *this,
        idPresentable *presentable,
        int index,
        bool skipReplication,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idPresentable *a14)
{
  idClientGame::AddPresentable(
    this,
    presentable,
    index,
    freeListType: skipReplication,
    a5,
    a6,
    a7,
    a8: skipReplication - 1,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14);
}


// ========================================================================
// ?WriteToSnapshot@idClientGame@@QBAXAAVidSnapShot@@PBV2@@Z
// EA  : 0x82B54700
// RVA : 0x00B54700
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::WriteToSnapshot(idClientGame *this, idSnapShot *ss, idSnapShot *oldss)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  __int64 v8; // r19
  int v9; // r30
  idArray<idReplicatedSound,32> *p_replicatedSounds; // r29
  idConsole_vtbl *v11; // r29
  int v12; // r30
  unsigned int v13; // r3
  int *p_num; // r21
  idList<idReplicatedSound,5> *p_startSoundOverRun; // r28
  unsigned __int16 v16; // r29
  soundChannel_t v17; // r27
  idArray<idReplicatedSound,32> *ReplicatedSound; // r3
  idArray<idReplicatedSound,32> *v19; // r30
  const idSoundShader *v20; // r26
  double v21; // fp0
  double v22; // fp12
  double v23; // fp11
  char v24; // r11
  unsigned __int8 v25; // r10
  unsigned __int8 v26; // r11
  int v27; // r28
  int v28; // r30
  idList<idPresentable *,5> *p_presentables; // r29
  idPLog *pLog; // r29
  idPLog::logEntry_t *v31; // r30
  int v32; // r3
  __int64 totalTicks; // r11
  __int64 v34; // r9
  _BYTE *v35; // [sp+60h] [-20F0h] BYREF
  const char *v36; // [sp+64h] [-20ECh]
  int v37; // [sp+68h] [-20E8h]
  int v38; // [sp+6Ch] [-20E4h]
  int v39; // [sp+70h] [-20E0h]
  int v40; // [sp+74h] [-20DCh]
  int v41; // [sp+78h] [-20D8h]
  char v42; // [sp+7Ch] [-20D4h]
  char v43; // [sp+7Dh] [-20D3h]
  __int64 v44; // [sp+80h] [-20D0h]
  idPLogScope v45; // [sp+88h] [-20C8h] BYREF
  idSerializer v46; // [sp+90h] [-20C0h] BYREF
  _QWORD v47[28]; // [sp+A0h] [-20B0h] BYREF
  _BYTE v48[4048]; // [sp+180h] [-1FD0h] BYREF

  RD_EventBegin(name: "idClientGame_WriteToSnapshot");
  LODWORD(v6) = "idClientGame_WriteToSnapshot";
  HIDWORD(v6) = 32;
  idPLogScope::idPLogScope(this: &v45, pl: &::pLog, gMask: v6, label: v7);
  HIDWORD(v8) = &consoleFont[21088];
  LODWORD(v8) = 0;
  if ( net_replicateSounds.valueInteger != 0 )
  {
    v38 = 0;
    v39 = 0;
    v35 = v48;
    v36 = v48;
    v37 = 8000;
    v40 = 0;
    v41 = 0;
    v9 = 32;
    p_replicatedSounds = &this->replicatedSounds;
    v42 = 0;
    v43 = 0;
    v44 = v8;
    v46.writing = true;
    v46.msg = (idBitMsg *)&v35;
    do
    {
      idReplicatedSound::Serialize(this: p_replicatedSounds->ptr, ser: &v46);
      --v9;
      p_replicatedSounds = (idArray<idReplicatedSound,32> *)((char *)p_replicatedSounds + 224);
    }
    while ( v9 != 0 );
    idSnapShot::S_AddObject(
      this: ss,
      objectNum: 5019,
      visMask: 0xFFFFFFFF,
      data: v36,
      _size: (v39 != 0) + v38,
      tag: "sounds");
    if ( com_drawSnapshots.valueInteger == 3 )
    {
      v11 = console->__vftable;
      v12 = (v39 != 0) + v38;
      v13 = idSnapShot::CompareObject(this: ss, oldss, objectNum: 5019, start: 0, end: 0, oldStart: 0);
      v11->AddSnapObject(this: console, a2: "sounds_new", a3: v12, a4: v13, a5: 0.0);
    }
    p_num = &this->startSoundOverRun.num;
    if ( this->startSoundOverRun.num > 0 )
    {
      p_startSoundOverRun = &this->startSoundOverRun;
      do
      {
        memcpy(Dst: v47, Src: p_startSoundOverRun->list, Size: sizeof(v47));
        v16 = WORD2(v47[24]);
        v17 = HIDWORD(v47[0]);
        ReplicatedSound = idClientGame::FindReplicatedSound(
                            this,
                            channel: SHIDWORD(v47[0]),
                            presentableIndex: WORD2(v47[24]));
        v19 = ReplicatedSound;
        if ( ReplicatedSound == nullptr )
          break;
        v20 = (const idSoundShader *)v47[0];
        v21 = *(float *)&v47[23];
        v22 = *((float *)&v47[23] + 1);
        v23 = *(float *)&v47[24];
        ReplicatedSound->ptr[0].position.x = *(float *)&v47[23];
        ReplicatedSound->ptr[0].position.y = v22;
        ReplicatedSound->ptr[0].position.z = v23;
        ReplicatedSound->ptr[0].channel = v17;
        ReplicatedSound->ptr[0].shader = v20;
        if ( v21 == vec3_infinity.x && v22 == vec3_infinity.y )
        {
          v24 = 1;
          if ( v23 == vec3_infinity.z )
            continue;
        }
        v24 = 0;
        v25 = BYTE6(v47[24]);
        ReplicatedSound->ptr[0].volume = 0.0;
        ReplicatedSound->ptr[0].presentableIndex = v16;
        ReplicatedSound->ptr[0].peerMask = v25;
        ReplicatedSound->ptr[0].internalFlags = v24 != 0;
        memcpy(
          Dst: &ReplicatedSound->ptr[0].parms,
          Src: &p_startSoundOverRun->list->parms,
          Size: sizeof(ReplicatedSound->ptr[0].parms));
        v26 = v19->ptr[0].changed[0];
        v19->ptr[0].framesToForceKeep = 2;
        v19->ptr[0].changed[0] = v26 + 1;
        idList<idReplicatedSound,5>::RemoveIndex(this: &this->startSoundOverRun, index: 0);
        if ( mp_cg_soundDebug.valueInteger != 0 )
          idLib::Printf(
            fmt: "Overrun removed %i: Presentable: %i Channel: %i Name: %s\n",
            *p_num,
            v16,
            v17,
            v20->name.str);
      }
      while ( *p_num > 0 );
    }
    if ( mp_cg_soundDebug.valueInteger != 0 )
      idLib::Printf(fmt: "Overrun sounds left: %i\n", *p_num);
  }
  if ( com_drawPresentables.valueInteger != 0 )
  {
    console->ClearPresentables(this: console);
    v27 = 0;
    if ( this->presentables.num > 0 )
    {
      v28 = 0;
      p_presentables = &this->presentables;
      do
      {
        if ( p_presentables->list[v28] != nullptr )
          ((void (__fastcall *)(idConsole *, const char *))console->AddPresentableObject)(
            a1: console,
            a2: p_presentables->list[v28]->debugName);
        ++v27;
        ++v28;
      }
      while ( v27 < this->presentables.num );
    }
  }
  if ( s_snapTrace.valueInteger != 0 )
    idCVar::SetBool(this: &s_snapTrace, newValue: false, force: true);
  if ( v45.logIndex >= 0 )
  {
    pLog = v45.pLog;
    v31 = &v45.pLog->logEntries.list[v45.logIndex];
    v32 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v31->totalTicks;
    HIDWORD(totalTicks) = v31->parent;
    LODWORD(v34) = v32 - totalTicks;
    v31->totalTicks = v34;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$503700
// EA  : 0x82B54AF4
// RVA : 0x00B54AF4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_503700()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 8528 + 8384));
}


// ========================================================================
// __unwind$503701
// EA  : 0x82B54B1C
// RVA : 0x00B54B1C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_503701()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 8528 + 136));
}


// ========================================================================
// ?TestLaunchProjectile@idClientGame@@QAA_NABVidFireParms@@AAVidTestFireResults@@@Z
// EA  : 0x82B54B50
// RVA : 0x00B54B50
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::TestLaunchProjectile(idClientGame *this, const idFireParms *fp, idTestFireResults *tfr)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  __int64 v8; // r7
  __int64 v9; // r4
  double y; // fp7
  double x; // fp6
  double v12; // fp4
  double v13; // fp3
  int entityNumber; // r8
  idPLogScope v16; // [sp+58h] [-48h] BYREF
  idVec3 v17; // [sp+60h] [-40h] BYREF

  RD_EventBegin(name: "idClientGame::TestLaunchProjectile");
  LODWORD(v6) = "idClientGame::TestLaunchProjectile";
  HIDWORD(v6) = 2;
  idPLogScope::idPLogScope(this: &v16, pl: &pLog, gMask: v6, label: v7);
  if ( fp->projDef->notHitscanInfo.fireAtPoint )
  {
    tfr->numTraces = 1;
    tfr->traceDirs[0].x = fp->fireAxis.mat[0].x;
    HIDWORD(v9) = fp;
    tfr->traceDirs[0].y = fp->fireAxis.mat[0].y;
    tfr->traceDirs[0].z = fp->fireAxis.mat[0].z;
    LODWORD(v8) = fp->projDef->maxRange;
    tfr->traceLens[0] = (float)v8;
    y = tfr->traceDirs[0].y;
    x = tfr->traceDirs[0].x;
    v12 = fp->start.y;
    v13 = fp->start.x;
    LODWORD(v9) = fp->projDef->maxRange;
    v17.z = fp->start.z + (float)(tfr->traceDirs[0].z * (float)v9);
    v17.y = (float)v12 + (float)((float)y * (float)v9);
    v17.x = (float)v13 + (float)((float)x * (float)v9);
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) != nullptr )
      entityNumber = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker)->entityNumber;
    else
      entityNumber = 0x1FFF;
    idClip::TracePoint(
      this: &this->clip,
      result: tfr->traces,
      start: &fp->start,
      end: &v17,
      clipMask: 8462469,
      passEntityNumber: entityNumber);
  }
  else
  {
    tfr->numTraces = 1;
  }
  idPLogScope::~idPLogScope(this: &v16);
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$503993
// EA  : 0x82B54CB0
// RVA : 0x00B54CB0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_503993()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 160 + 108));
}


// ========================================================================
// __unwind$503994
// EA  : 0x82B54CD8
// RVA : 0x00B54CD8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_503994()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 160 + 88));
}


// ========================================================================
// ?FinishLaunchProjectile@idClientGame@@QAA_NABVidFireParms@@ABVidTestFireResults@@AAVidFinishFireResults@@@Z
// EA  : 0x82B54D08
// RVA : 0x00B54D08
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::FinishLaunchProjectile(
        idClientGame *this,
        const idFireParms *fp,
        const idTestFireResults *tfr,
        idFinishFireResults *ffr)
{
  const idDeclProjectile *v7; // r30
  idPresentable *v8; // r3
  idPresentablePlayer *Presentable; // r19
  idPresentable *v10; // r3
  int v11; // r10
  idArray<int,4> *p_inputToPlayerIndexRouting; // r11
  char v13; // r11
  const idDeclProjectile *projDef; // r26
  int spawnCount; // r11
  idRenderModel *v16; // r30
  int *v17; // r9
  int *p_muzzleTagIndex; // r10
  int j; // ctr
  float y; // r9
  float z; // r8
  idDeclProjectile::projectileClientPredictive_t clientType; // r11
  idPresentableProjectile_Homing *v23; // r3
  idPresentableProjectile_Homing *v24; // r3
  idPresentableProjectile *v25; // r30
  idPresentableProjectile_Rocket *v26; // r3
  idPresentableProjectile_Rocket *v27; // r3
  idPresentableProjectile_Grenade *v28; // r3
  idPresentableProjectile_Grenade *v29; // r3
  idPresentable *v30; // r3
  unsigned int spawnId; // r11
  int v32; // r29
  idPresentable *Control; // r3
  idPresentable *v34; // r3
  idPresentableVehicle *v35; // r3
  idWeapon *Weapon; // r3
  unsigned int PredictionKey; // r29
  presentableType_t v38; // r3
  int v39; // r10
  int v40; // r9
  int v41; // r8
  int v42; // r7
  idPresentable *v43; // r3
  idPresentablePlayer *PlayerDriver; // r29
  idPresentable *v45; // r3
  idPresentableVehicle *v46; // r3
  idPresentableVehicle *v47; // r28
  const idDeclFX *fxDeclQuad; // r4
  int startTime; // r28
  double startSpeed; // fp31
  idPresentable *v51; // r3
  int v52; // r8
  int v53; // r9
  int v55; // [sp+8h] [-158h]
  int v56; // [sp+Ch] [-154h]
  int v57; // [sp+10h] [-150h]
  int v58; // [sp+14h] [-14Ch]
  int v59; // [sp+18h] [-148h]
  idPresentable *v60; // [sp+1Ch] [-144h]
  int v61; // [sp+50h] [-110h]
  int i; // [sp+54h] [-10Ch]
  idVec3 v63; // [sp+60h] [-100h] BYREF
  idProjectileTarget v64; // [sp+70h] [-F0h] BYREF
  int v65; // [sp+8Ch] [-D4h] BYREF
  idMat3 v66; // [sp+90h] [-D0h] BYREF

  if ( ffr->numProjectiles <= 0 && (v7 = fp->projDef, ffr->numProjectiles < v7->spawnCount)
    || (v7 = fp->projDef)->spawnCount >= 2 )
  {
    if ( cg_predictProjectiles.valueInteger != 0
      && idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) != nullptr
      && idStr::Cmp(s1: v7->clientModelName.data, s2: &byte_8200D768) != 0 )
    {
      v8 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
      Presentable = v8->GetPlayerInterface_2(this: v8);
      if ( Presentable != nullptr
        || (v10 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker),
            (Presentable = idPresentablePtr<idPresentablePlayer>::GetPresentable(this: &v10->controller)) != nullptr) )
      {
        v11 = 0;
        p_inputToPlayerIndexRouting = &this->inputToPlayerIndexRouting;
        while ( p_inputToPlayerIndexRouting->ptr[0] != Presentable->entityNumber )
        {
          ++v11;
          p_inputToPlayerIndexRouting = (idArray<int,4> *)((char *)p_inputToPlayerIndexRouting + 4);
          if ( v11 >= 4 )
          {
            v13 = 0;
            goto LABEL_13;
          }
        }
        v13 = 1;
LABEL_13:
        if ( v13 != 0 )
        {
          projDef = fp->projDef;
          if ( projDef->clientType != PROJCLIENT_NONE )
          {
            spawnCount = projDef->spawnCount;
            if ( spawnCount < 1 )
              spawnCount = 1;
            v61 = spawnCount;
            for ( i = 0; i < v61; ++i )
            {
              v16 = this->renderWorld->AllocRenderModel(
                      this: this->renderWorld,
                      a2: projDef->clientModelName.data,
                      a3: 1,
                      a4: -1);
              v17 = &v65;
              p_muzzleTagIndex = &fp->muzzleTagIndex;
              for ( j = 9; j != 0; --j )
                *++v17 = *++p_muzzleTagIndex;
              y = fp->start.y;
              z = fp->start.z;
              clientType = projDef->clientType;
              v63.x = fp->start.x;
              v63.y = y;
              v63.z = z;
              switch ( clientType )
              {
                case PROJCLIENT_GRENADE:
                  v28 = (idPresentableProjectile_Grenade *)idMem::AllocWithLocation(
                                                             this: &mem,
                                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                             size: 0x7F0u,
                                                             tag: TAG_PRESENTABLE,
                                                             zeroBuffer: false,
                                                             align: ALIGN_16,
                                                             heap: HEAP_DEFAULTHEAP);
                  if ( v28 != nullptr )
                    v29 = idPresentableProjectile_Grenade::idPresentableProjectile_Grenade(
                            this: v28,
                            decl: projDef,
                            renderModel_: v16,
                            animStack_: nullptr);
                  else
                    v29 = nullptr;
                  v25 = v29;
                  break;
                case PROJCLIENT_ROCKET:
                  v26 = (idPresentableProjectile_Rocket *)idMem::AllocWithLocation(
                                                            this: &mem,
                                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                            size: 0x7F8u,
                                                            tag: TAG_PRESENTABLE,
                                                            zeroBuffer: false,
                                                            align: ALIGN_16,
                                                            heap: HEAP_DEFAULTHEAP);
                  if ( v26 != nullptr )
                    v27 = idPresentableProjectile_Rocket::idPresentableProjectile_Rocket(
                            this: v26,
                            decl: projDef,
                            renderModel_: v16,
                            animStack_: nullptr);
                  else
                    v27 = nullptr;
                  v25 = v27;
                  break;
                case PROJCLIENT_HOMING:
                  v23 = (idPresentableProjectile_Homing *)idMem::AllocWithLocation(
                                                            this: &mem,
                                                            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                            size: 0x810u,
                                                            tag: TAG_PRESENTABLE,
                                                            zeroBuffer: false,
                                                            align: ALIGN_16,
                                                            heap: HEAP_DEFAULTHEAP);
                  if ( v23 != nullptr )
                    v24 = idPresentableProjectile_Homing::idPresentableProjectile_Homing(
                            this: v23,
                            decl: projDef,
                            renderModel_: v16,
                            animStack_: nullptr);
                  else
                    v24 = nullptr;
                  v25 = v24;
                  break;
                default:
                  continue;
              }
              if ( v25 != nullptr )
              {
                v30 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->target);
                v64.type = TARGET_PRESENTABLE;
                spawnId = 0;
                v64.pos = vec3_origin;
                if ( v30 != nullptr )
                  spawnId = v30->spawnId;
                v64.presentable.spawnId = spawnId;
                v32 = -1;
                if ( idPresentablePlayer::GetControl(this: Presentable) != nullptr )
                {
                  Control = idPresentablePlayer::GetControl(this: Presentable);
                  if ( Control->GetVehicleInterface(this: Control) != nullptr )
                  {
                    v34 = idPresentablePlayer::GetControl(this: Presentable);
                    v35 = v34->GetVehicleInterface(this: v34);
                    v32 = (ffr->numProjectiles << 24) | idPresentableVehicle::GetFireCount(this: v35);
                  }
                }
                Weapon = idFireParms::GetWeapon(this: fp);
                PredictionKey = idClientGame::GeneratePredictionKey(
                                  this,
                                  weapon: Weapon,
                                  playerAttacker: (lobbyUserID_t *)Presentable,
                                  overrideKey: v32);
                v38 = v25->GetType(this: v25);
                if ( idClientGame::FindPredictedPresentable(this, predictedKey: PredictionKey, presentableType: v38) != nullptr )
                {
                  ((void (__fastcall *)(idPresentableProjectile *, int))v25->dtr_idPresentable)(a1: v25, a2: 1);
                  idLib::Printf(fmt: "Spawned predictive projectile with duplicate predictedKey: %d\n", PredictionKey);
                  return 1;
                }
                if ( cg_predictedSpawn_debug.valueInteger != 0 )
                  idLib::Printf(fmt: "Spawned predictive projectile w/ predictedKey: %d\n", PredictionKey);
                v25->predictedKey = PredictionKey;
                idClientGame::AddPresentable(
                  this: clientGame,
                  presentable: v25,
                  index: -1,
                  freeListType: 1,
                  a5: v42,
                  a6: v41,
                  a7: v40,
                  a8: v39,
                  a9: v55,
                  a10: v56,
                  a11: v57,
                  a12: v58,
                  a13: v59,
                  a14: v60);
                if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) != nullptr )
                {
                  v43 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
                  PlayerDriver = v43->GetPlayerInterface_2(this: v43);
                  v45 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
                  v46 = v45->GetVehicleInterface(this: v45);
                  v47 = v46;
                  if ( PlayerDriver != nullptr )
                    goto LABEL_49;
                  if ( v46 != nullptr )
                  {
                    PlayerDriver = idPresentableVehicle::GetPlayerDriver(this: v46);
                    if ( PlayerDriver != nullptr )
                    {
LABEL_49:
                      if ( (*((_BYTE *)PlayerDriver + 47032) & 2) == 0 )
                        goto LABEL_50;
LABEL_52:
                      fxDeclQuad = fp->projDef->fxDeclQuad;
                      if ( fxDeclQuad != nullptr )
                      {
                        idPresentable::ResetFXMgr(this: v25, fxDecl_: fxDeclQuad);
                        v25->hasQuad = true;
                      }
                    }
                    else
                    {
LABEL_50:
                      if ( v47 != nullptr && v47->hasQuad )
                        goto LABEL_52;
                    }
                  }
                }
                idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
                startTime = fp->startTime;
                startSpeed = fp->startSpeed;
                v51 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
                idPresentableProjectile::ClientLaunch(
                  this: v25,
                  attacker_: v51,
                  start: &v63,
                  fireAxis: &v66,
                  target: &v64,
                  initialSpeed: startSpeed,
                  startTime: v52,
                  launchTime_: startTime);
                v53 = ffr->numProjectiles + 1;
                ffr->numProjectiles = v53;
                *(&ffr->numProjectiles + v53) = v25->spawnId;
              }
            }
          }
        }
      }
    }
  }
  return 1;
}


// ========================================================================
// __unwind$504086
// EA  : 0x82B55270
// RVA : 0x00B55270
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_504086()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 352 + 88), tag: TAG_PRESENTABLE);
}


// ========================================================================
// __unwind$504085
// EA  : 0x82B5529C
// RVA : 0x00B5529C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_504085()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 352 + 88), tag: TAG_PRESENTABLE);
}


// ========================================================================
// __unwind$504084
// EA  : 0x82B552C8
// RVA : 0x00B552C8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_504084()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 352 + 88), tag: TAG_PRESENTABLE);
}


// ========================================================================
// ?TestHitScan@idClientGame@@QAA_NABVidFireParms@@AAVidTestFireResults@@@Z
// EA  : 0x82B55300
// RVA : 0x00B55300
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::TestHitScan(idClientGame *this, const idFireParms *fp, idTestFireResults *tfr)
{
  unsigned __int64 v4; // r30
  unsigned __int64 v5; // r6
  const char *v6; // r7
  long double v7; // fp2
  const idDeclProjectile *projDef; // r8
  int spawnCount; // r11
  __int64 v10; // r6
  double v11; // fp29
  int v12; // r24
  __int64 v13; // r6
  idClip *v14; // r19
  idClientGame *RandomSpreadTraceDir; // r3
  int v16; // r28
  float *v17; // r11
  double z; // fp12
  int v19; // r25
  int ignoreEntityNum; // r10
  double v21; // fp12
  double y; // fp10
  double x; // fp9
  double v24; // fp6
  signed int v25; // r11
  bool v26; // r9
  idPresentable *v27; // r11
  idPresentable *v28; // r3
  idPresentable *v29; // r3
  idPresentable *v30; // r3
  idPresentable *v31; // r3
  idTurret *v32; // r3
  int v33; // r23
  const idDeclDamage *damageDecl; // r11
  idEntity *v35; // r3
  int v36; // r11
  char v37; // r11
  bool v38; // zf
  float v39; // r26
  float v40; // r22
  int v41; // r11
  bool v42; // r10
  double v43; // fp12
  double v44; // fp9
  double v45; // fp6
  double i; // fp31
  int v47; // r26
  int v48; // r27
  trace_t *v49; // r5
  double v50; // fp0
  double v51; // fp13
  double v52; // fp12
  float v53; // r11
  double v54; // fp11
  float v55; // r22
  int v56; // r14
  double v57; // fp6
  float v58; // r30
  double v59; // fp5
  double v60; // fp4
  int v61; // r11
  double v62; // fp12
  double v63; // fp6
  int v64; // r23
  int v65; // r11
  double v66; // fp12
  double v67; // fp9
  double v68; // fp6
  double v69; // fp31
  int v70; // r25
  int v71; // r28
  int v72; // r11
  float *v73; // r27
  float *v74; // r29
  double v75; // fp0
  double v76; // fp13
  double v77; // fp12
  float v78; // r26
  double v79; // fp11
  float v80; // r22
  double v81; // fp3
  float v82; // r15
  double v83; // fp2
  int v84; // r14
  double v85; // fp9
  double v86; // fp12
  double v87; // fp6
  idEntity *v88; // r3
  int v89; // r11
  char v90; // r11
  idVehicle *v91; // r3
  float v92; // r6
  float v93; // r9
  int v94; // r25
  double v95; // fp13
  int v96; // r11
  float *v97; // r28
  idVehicle *v98; // r27
  int v99; // r8
  double v100; // fp6
  double v101; // fp5
  char v102; // r22
  int v103; // r26
  float *v104; // r11
  unsigned __int8 v105; // r11
  int v106; // r28
  idPLog *pLog; // r29
  idPLog::logEntry_t *v108; // r30
  int v109; // r3
  __int64 totalTicks; // r11
  __int64 v111; // r9
  int v113; // [sp+8h] [-278h]
  bool v114; // [sp+Fh] [-271h]
  const char *v115; // [sp+10h] [-270h]
  int v116; // [sp+14h] [-26Ch]
  int v117; // [sp+18h] [-268h]
  int v118; // [sp+1Ch] [-264h]
  int v119; // [sp+20h] [-260h]
  int v120; // [sp+24h] [-25Ch]
  int v121; // [sp+28h] [-258h]
  int v122; // [sp+2Ch] [-254h]
  int v123; // [sp+30h] [-250h]
  int v124; // [sp+34h] [-24Ch]
  int v125; // [sp+38h] [-248h]
  int v126; // [sp+3Ch] [-244h]
  int v127; // [sp+40h] [-240h]
  int v128; // [sp+44h] [-23Ch]
  int v129; // [sp+48h] [-238h]
  int v130; // [sp+4Ch] [-234h]
  int v131; // [sp+50h] [-230h]
  int v132; // [sp+54h] [-22Ch]
  int v133; // [sp+54h] [-22Ch]
  int v134; // [sp+58h] [-228h]
  int v135; // [sp+60h] [-220h]
  unsigned __int64 v136; // [sp+70h] [-210h]
  idVec3 v137; // [sp+88h] [-1F8h] BYREF
  idPLogScope v138; // [sp+98h] [-1E8h] BYREF
  idVec3 v139; // [sp+A0h] [-1E0h] BYREF
  idVec3 v140; // [sp+B0h] [-1D0h] BYREF
  idVec3 v141; // [sp+C0h] [-1C0h] BYREF
  idVec3 v142; // [sp+D0h] [-1B0h] BYREF
  idVec3 v143; // [sp+E0h] [-1A0h] BYREF
  idVec3 v144; // [sp+F0h] [-190h] BYREF
  idVec3 v145; // [sp+100h] [-180h] BYREF
  int v146; // [sp+110h] [-170h] BYREF
  int v147; // [sp+118h] [-168h] BYREF
  int v148; // [sp+120h] [-160h] BYREF
  int v149; // [sp+128h] [-158h] BYREF
  int v150; // [sp+130h] [-150h] BYREF
  trace_t v151; // [sp+140h] [-140h] BYREF

  v4 = __PAIR64__((unsigned int)this, (unsigned int)tfr);
  RD_EventBegin(name: "idClientGame::TestHitScan");
  LODWORD(v5) = "idClientGame::TestHitScan";
  HIDWORD(v5) = 2;
  idPLogScope::idPLogScope(this: &v138, pl: &::pLog, gMask: v5, label: v6);
  projDef = fp->projDef;
  spawnCount = projDef->spawnCount;
  LODWORD(v10) = projDef->maxRange;
  v11 = (float)v10;
  if ( spawnCount >= 16 )
    spawnCount = 16;
  *(_DWORD *)v4 = spawnCount;
  v12 = 0;
  if ( spawnCount <= 0 )
    goto LABEL_69;
  LODWORD(v13) = 8454144;
  v14 = (idClip *)(HIDWORD(v4) + 10688);
  do
  {
    if ( fp->projDef->spread == 0.0 || (*((_BYTE *)fp + 128) & 2) != 0 )
    {
      v16 = 12 * (v12 + 171);
      v17 = (float *)(v16 + v4);
      *(float *)(v16 + v4) = fp->fireAxis.mat[0].x;
      *(float *)(v16 + v4 + 4) = fp->fireAxis.mat[0].y;
      z = fp->fireAxis.mat[0].z;
    }
    else
    {
      HIDWORD(v13) = fp;
      RandomSpreadTraceDir = idClientGame::GetRandomSpreadTraceDir(this: (idClientGame *)&v150, fp: v13, a3: v7);
      v16 = 12 * (v12 + 171);
      v17 = (float *)(v16 + v4);
      *(_QWORD *)(v16 + v4) = *(_QWORD *)&RandomSpreadTraceDir->random.seed;
      z = *(float *)&RandomSpreadTraceDir->soundWorld;
    }
    v17[2] = z;
    v19 = 4 * (v12 + 561);
    *(float *)(v19 + v4) = v11;
    ignoreEntityNum = fp->ignoreEntityNum;
    v21 = (float)(*v17 * (float)v11);
    y = fp->start.y;
    x = fp->start.x;
    v24 = (float)(v17[1] * (float)v11);
    v137.z = (float)(v17[2] * (float)v11) + fp->start.z;
    v137.x = (float)x + (float)v21;
    v137.y = (float)y + (float)v24;
    if ( ignoreEntityNum < 0 )
    {
      v25 = fp->attacker.spawnId & 0x3FFF;
      if ( fp->attacker.spawnId == 0
        || (v25 >= clientGame->presentables.num ? (v26 = false) : (v26 = clientGame->presentables.list[v25] != nullptr),
            !v26 || (v27 = clientGame->presentables.list[v25])->spawnId != fp->attacker.spawnId) )
      {
        v27 = nullptr;
      }
      HIDWORD(v4) = v27->entityNumber;
    }
    else
    {
      HIDWORD(v4) = ignoreEntityNum;
    }
    if ( common->IsMultiplayer(this: common)
      && gc_friendlyFire.valueInteger == 0
      && idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) != nullptr )
    {
      v28 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
      if ( v28->GetPlayerInterface_2(this: v28) == nullptr )
      {
        v29 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
        if ( v29->GetTurretInterface(this: v29) != nullptr && common->IsServer(this: common) )
        {
          v30 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
          if ( v30->GetTurretInterface(this: v30) != nullptr )
          {
            v31 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
            v32 = idTurret::CastTo(c: (idTurret *)v31->entity);
            if ( v32 != nullptr )
              idPlayer::CastTo(c: (idPlayer *)v32->turretOwner);
          }
        }
      }
    }
    v132 = HIDWORD(v4);
    v33 = v12 << 7;
    HIDWORD(v4) = (v12 << 7) + v4;
    idClip::Translation(
      this: (idClip *)&v148,
      result: v14,
      a3: (trace_t *)(HIDWORD(v4) + 4),
      start: &fp->start,
      end: &v137,
      clipModel: nullptr,
      startAxis: &mat3_identity,
      clipMask: 8462469,
      passEntityNumber: v113,
      moveClipModel: v114,
      userName: v115,
      a12: v116,
      a13: v117,
      a14: v118,
      a15: v119,
      a16: v120,
      a17: v121,
      a18: v122,
      a19: v123,
      a20: v124,
      a21: v125,
      a22: v126,
      a23: v127,
      a24: v128,
      a25: v129,
      a26: v130,
      a27: v131,
      a28: v132,
      a29: v134,
      a30: false,
      a31: v135,
      a32: 0);
    if ( !common->IsMultiplayer(this: common) || common->IsServer(this: common) )
    {
      damageDecl = fp->projDef->damageDecl;
      if ( damageDecl != nullptr && (damageDecl->damageTypes & 0x4000) == 0 )
      {
        while ( 1 )
        {
          v35 = gameLocal->entities.ptr[*(_DWORD *)(HIDWORD(v4) + 112)];
          v36 = *(_DWORD *)(v35->GetType(this: v35) + 36);
          if ( v36 < idCuttable::Type.typeNum || (v38 = v36 <= idCuttable::Type.lastChild, v37 = 1, !v38) )
            v37 = 0;
          if ( v37 == 0 )
            break;
          v39 = *(float *)(HIDWORD(v4) + 12);
          v40 = *(float *)(HIDWORD(v4) + 16);
          v133 = *(_DWORD *)(HIDWORD(v4) + 112);
          v142.x = *(float *)(HIDWORD(v4) + 8);
          v142.y = v39;
          v142.z = v40;
          idClip::Translation(
            this: (idClip *)&v147,
            result: v14,
            a3: (trace_t *)(HIDWORD(v4) + 4),
            start: &v142,
            end: &v137,
            clipModel: nullptr,
            startAxis: &mat3_identity,
            clipMask: 8462469,
            passEntityNumber: v113,
            moveClipModel: v114,
            userName: v115,
            a12: v116,
            a13: v117,
            a14: v118,
            a15: v119,
            a16: v120,
            a17: v121,
            a18: v122,
            a19: v123,
            a20: v124,
            a21: v125,
            a22: v126,
            a23: v127,
            a24: v128,
            a25: v129,
            a26: v130,
            a27: v131,
            a28: v133,
            a29: v134,
            a30: false,
            a31: v135,
            a32: 0);
        }
      }
    }
    v41 = *(_DWORD *)(HIDWORD(v4) + 100);
    v42 = false;
    if ( v41 != 3 )
      v42 = v41 != 27;
    if ( fp->projDef->hitscan_till_solid && !v42 )
    {
      v43 = (float)(*(float *)(HIDWORD(v4) + 12) - fp->start.y);
      v44 = (float)(*(float *)(HIDWORD(v4) + 8) - fp->start.x);
      v45 = (float)(*(float *)(HIDWORD(v4) + 16) - fp->start.z);
      *((double *)&v7 + 1) = __fsqrts((float)((float)((float)v45 * (float)v45)
                                            + (float)((float)((float)v44 * (float)v44) + (float)((float)v43 * (float)v43))));
      for ( i = (float)((float)v11 - (float)*((double *)&v7 + 1));
            i > 0.0;
            i = (float)((float)i - (float)*((double *)&v7 + 1)) )
      {
        if ( *(int *)v4 >= 16 )
          break;
        v19 += 4;
        v136 = v4;
        v16 += 12;
        ++*(_DWORD *)v4;
        v33 += 128;
        *(float *)(v19 + v4) = i;
        v47 = v16 + v4;
        v48 = v33 + v4;
        v49 = (trace_t *)(v33 + v4 + 4);
        ++v12;
        v50 = *(float *)(v16 + v4 - 12);
        *(float *)(v16 + v4) = *(float *)(v16 + v4 - 12);
        v51 = *(float *)(v16 + v4 - 8);
        *(float *)(v47 + 4) = *(float *)(v16 + v4 - 8);
        v52 = *(float *)(v16 + v4 - 4);
        *(float *)(v47 + 8) = *(float *)(v16 + v4 - 4);
        v53 = *(float *)(v33 + v4 - 120);
        v54 = *(float *)(v19 + v4);
        v55 = *(float *)(v33 + v4 - 112);
        v56 = *(_DWORD *)(v33 + v4 - 16);
        v57 = *(float *)(v33 + v4 - 116);
        v59 = (float)((float)v51 * *(float *)(v19 + v4));
        v60 = (float)((float)v52 * *(float *)(v19 + v4));
        v58 = *(float *)(v33 + v4 - 116);
        v139.x = v53;
        v139.y = v58;
        v140.y = (float)v59 + (float)v57;
        v139.z = v55;
        v140.z = (float)v60 + v55;
        v140.x = v53 + (float)((float)v54 * (float)v50);
        idClip::Translation(
          this: (idClip *)&v149,
          result: v14,
          a3: v49,
          start: &v139,
          end: &v140,
          clipModel: nullptr,
          startAxis: &mat3_identity,
          clipMask: 8462469,
          passEntityNumber: v113,
          moveClipModel: v114,
          userName: v115,
          a12: v116,
          a13: v117,
          a14: v118,
          a15: v119,
          a16: v120,
          a17: v121,
          a18: v122,
          a19: v123,
          a20: v124,
          a21: v125,
          a22: v126,
          a23: v127,
          a24: v128,
          a25: v129,
          a26: v130,
          a27: v131,
          a28: v56,
          a29: v134,
          a30: false,
          a31: v135,
          a32: 0);
        v61 = *(_DWORD *)(v48 + 100);
        v4 = v136;
        if ( v61 != 3 && v61 != 27 )
          break;
        v62 = (float)(*(float *)(v48 + 12) - *(float *)(HIDWORD(v136) + 4));
        v63 = (float)(*(float *)(v48 + 16) - *(float *)(HIDWORD(v136) + 8));
        *((double *)&v7 + 1) = __fsqrts((float)((float)((float)v63 * (float)v63)
                                              + (float)((float)((float)(*(float *)(v48 + 8) - *(float *)HIDWORD(v136))
                                                              * (float)(*(float *)(v48 + 8) - *(float *)HIDWORD(v136)))
                                                      + (float)((float)v62 * (float)v62))));
      }
    }
    if ( fp->projDef->hitscan_through_water )
    {
      v64 = v12 << 7;
      v65 = (v12 << 7) + v4;
      if ( *(_DWORD *)(v65 + 100) == 6 )
      {
        v66 = (float)(*(float *)(v65 + 12) - fp->start.y);
        v67 = (float)(*(float *)(v65 + 8) - fp->start.x);
        v68 = (float)(*(float *)(v65 + 16) - fp->start.z);
        *((double *)&v7 + 1) = __fsqrts((float)((float)((float)v68 * (float)v68)
                                              + (float)((float)((float)v67 * (float)v67)
                                                      + (float)((float)v66 * (float)v66))));
        v69 = (float)((float)v11 - (float)*((double *)&v7 + 1));
        if ( v69 > 0.0 )
        {
          v70 = 4 * (v12 + 561);
          v71 = 12 * (v12 + 171);
          do
          {
            if ( *(int *)v4 >= 16 )
              break;
            v70 += 4;
            v71 += 12;
            ++*(_DWORD *)v4;
            v64 += 128;
            *(float *)(v70 + v4) = v69;
            v72 = v71 + v4;
            v73 = (float *)(v64 + v4);
            v74 = (float *)(v64 + v4 - 120);
            ++v12;
            v75 = *(float *)(v71 + v4 - 12);
            *(float *)(v71 + v4) = *(float *)(v71 + v4 - 12);
            v76 = *(float *)(v71 + v4 - 8);
            *(float *)(v72 + 4) = *(float *)(v71 + v4 - 8);
            v77 = *(float *)(v71 + v4 - 4);
            *(float *)(v72 + 8) = *(float *)(v71 + v4 - 4);
            v78 = *v74;
            v79 = *(float *)(v64 + v4 - 112);
            v80 = *(float *)(v64 + v4 - 116);
            v81 = (float)((float)v75 * *(float *)(v70 + v4));
            v82 = *(float *)(v64 + v4 - 112);
            v83 = (float)(*(float *)(v70 + v4) * (float)v77);
            v84 = *(_DWORD *)(v64 + v4 - 16);
            v85 = *v74;
            v143.y = (float)(*(float *)(v70 + v4) * (float)v76) + v80;
            v141.x = v78;
            v143.x = (float)v85 + (float)v81;
            v143.z = (float)v83 + (float)v79;
            v141.z = v82;
            v141.y = v80;
            idClip::Translation(
              this: (idClip *)&v146,
              result: v14,
              a3: (trace_t *)(v64 + v4 + 4),
              start: &v141,
              end: &v143,
              clipModel: nullptr,
              startAxis: &mat3_identity,
              clipMask: 8462469,
              passEntityNumber: v113,
              moveClipModel: v114,
              userName: v115,
              a12: v116,
              a13: v117,
              a14: v118,
              a15: v119,
              a16: v120,
              a17: v121,
              a18: v122,
              a19: v123,
              a20: v124,
              a21: v125,
              a22: v126,
              a23: v127,
              a24: v128,
              a25: v129,
              a26: v130,
              a27: v131,
              a28: v84,
              a29: v134,
              a30: false,
              a31: v135,
              a32: 0);
            if ( *(_DWORD *)(v64 + v4 + 100) != 6 )
              break;
            v86 = (float)(v73[3] - v74[1]);
            v87 = (float)(v73[4] - v74[2]);
            *((double *)&v7 + 1) = __fsqrts((float)((float)((float)v87 * (float)v87)
                                                  + (float)((float)((float)(v73[2] - *v74) * (float)(v73[2] - *v74))
                                                          + (float)((float)v86 * (float)v86))));
            v69 = (float)((float)v69 - (float)*((double *)&v7 + 1));
          }
          while ( v69 > 0.0 );
        }
      }
    }
    if ( fp->projDef->hitscan_through_vehicles )
    {
      HIDWORD(v4) = (v12 << 7) + v4;
      v88 = gameLocal->entities.ptr[*(_DWORD *)(HIDWORD(v4) + 112)];
      v89 = *(_DWORD *)(v88->GetType(this: v88) + 36);
      if ( v89 < idVehicle::Type.typeNum || (v38 = v89 <= idVehicle::Type.lastChild, v90 = 1, !v38) )
        v90 = 0;
      if ( v90 != 0 )
      {
        v91 = idVehicle::CastTo(c: (idVehicle *)gameLocal->entities.ptr[*(_DWORD *)(HIDWORD(v4) + 112)]);
        v92 = *(float *)(HIDWORD(v4) + 16);
        v93 = *(float *)(HIDWORD(v4) + 8);
        v94 = 4 * (v12 + 561);
        v95 = *(float *)(HIDWORD(v4) + 12);
        v145.y = *(float *)(HIDWORD(v4) + 12);
        v96 = 12 * (v12 + 171);
        v145.z = v92;
        v145.x = v93;
        v97 = (float *)(v96 + v4);
        v98 = v91;
        v99 = *(_DWORD *)(HIDWORD(v4) + 112);
        v100 = (float)(*(float *)(v96 + v4 + 8) * *(float *)(v94 + v4));
        v101 = (float)(*(float *)(v96 + v4 + 4) * *(float *)(v94 + v4));
        v144.x = v93 + (float)(*(float *)(v96 + v4) * *(float *)(v94 + v4));
        v144.z = v92 + (float)v100;
        v144.y = (float)v95 + (float)v101;
        idClip::TracePoint(
          this: v14,
          result: (trace_t *)(HIDWORD(v4) + 132),
          start: &v145,
          end: &v144,
          clipMask: 8462469,
          passEntityNumber: v99);
        v102 = 0;
        v103 = 0;
        if ( idVehicle::GetNumActiveOccupants(this: v98) > 0 )
        {
          while ( *(_DWORD *)(HIDWORD(v4) + 240) != idVehicle::GetOccupantVisual(this: v98, index: v103)->entityNumber )
          {
            if ( ++v103 >= idVehicle::GetNumActiveOccupants(this: v98) )
              goto LABEL_63;
          }
          v102 = 1;
        }
LABEL_63:
        if ( v102 != 0 && v12 + 1 < 16 )
        {
          *(float *)(4 * (v12 + 562) + v4) = *(float *)(v94 + v4);
          v104 = (float *)(12 * (v12 + 172) + v4);
          ++v12;
          *v104 = *v97;
          v104[1] = v97[1];
          v104[2] = v97[2];
          LODWORD(v13) = *(_DWORD *)v4 + 1;
          *(_DWORD *)v4 = v13;
        }
        else
        {
          trace_t::operator=(this: (trace_t *)(HIDWORD(v4) + 132), __that: &v151);
        }
      }
    }
    ++v12;
  }
  while ( v12 < *(_DWORD *)v4 );
  v105 = 1;
  if ( *(int *)v4 <= 0 )
LABEL_69:
    v105 = 0;
  v106 = v105;
  if ( v138.logIndex >= 0 )
  {
    pLog = v138.pLog;
    v108 = &v138.pLog->logEntries.list[v138.logIndex];
    v109 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v108->totalTicks;
    HIDWORD(totalTicks) = v108->parent;
    LODWORD(v111) = v109 - totalTicks;
    v108->totalTicks = v111;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  return v106;
}


// ========================================================================
// __unwind$504307
// EA  : 0x82B55D60
// RVA : 0x00B55D60
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_504307()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 640 + 448));
}


// ========================================================================
// __unwind$504308
// EA  : 0x82B55D88
// RVA : 0x00B55D88
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_504308()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 640 + 152));
}


// ========================================================================
// ?ReplicatePlaySound@idClientGame@@QAAXW4soundChannel_t@@PBVidSoundShader@@ABUsoundShaderParms_t@@GABVidVec3@@E@Z
// EA  : 0x82B55DB0
// RVA : 0x00B55DB0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ReplicatePlaySound(
        idClientGame *this,
        soundChannel_t channel,
        const idSoundShader *shader,
        const soundShaderParms_t *parms,
        unsigned __int16 presentableIndex,
        const idVec3 *pos,
        unsigned __int8 peerMask)
{
  idLobbyBase *v14; // r3
  idLobbyBase *v15; // r3
  idArray<idReplicatedSound,32> *ReplicatedSound; // r3
  idArray<idReplicatedSound,32> *v17; // r31
  char v18; // r11
  unsigned __int8 v19; // r8
  int v20; // r10
  int v21; // r5
  int num; // r6
  char v23; // r8
  int v24; // r10
  idReplicatedSound *list; // r7
  int v26; // r11
  idList<idReplicatedSound,5> *p_startSoundOverRun; // r30
  int v28; // r31
  float *v29; // r11
  double x; // fp11
  char v31; // r10
  double v32; // fp12
  double y; // fp0
  double z; // fp13
  char v35; // r11
  idReplicatedSound v36; // [sp+50h] [-160h] BYREF

  v14 = session->GetActingGameStateLobbyBase(this: session);
  if ( v14->IsHost(this: v14) != 0 )
  {
    v15 = session->GetActingGameStateLobbyBase(this: session);
    if ( v15->HasActivePeers(this: v15) )
    {
      if ( this->overrideSoundPeerMask != 0 )
        peerMask &= this->overrideSoundPeerMask;
      if ( peerMask != 0 && (shader == nullptr || (shader->parms.soundShaderFlags & 1) == 0) )
      {
        ReplicatedSound = idClientGame::FindReplicatedSound(this, channel, presentableIndex);
        v17 = ReplicatedSound;
        if ( ReplicatedSound != nullptr )
        {
          ReplicatedSound->ptr[0].position.x = pos->x;
          ReplicatedSound->ptr[0].position.y = pos->y;
          ReplicatedSound->ptr[0].position.z = pos->z;
          ReplicatedSound->ptr[0].channel = channel;
          ReplicatedSound->ptr[0].shader = shader;
          if ( pos->x != vec3_infinity.x || pos->y != vec3_infinity.y || (v18 = 1, pos->z != vec3_infinity.z) )
            v18 = 0;
          ReplicatedSound->ptr[0].presentableIndex = presentableIndex;
          ReplicatedSound->ptr[0].peerMask = peerMask;
          ReplicatedSound->ptr[0].internalFlags = v18 != 0;
          ReplicatedSound->ptr[0].volume = 0.0;
          memcpy(Dst: &ReplicatedSound->ptr[0].parms, Src: parms, Size: sizeof(ReplicatedSound->ptr[0].parms));
          v19 = v17->ptr[0].changed[0] + 1;
          v20 = NumSoundsCreatedPerFrame_2;
          v21 = spawnNumer + 1;
          v17->ptr[0].framesToForceKeep = 2;
          v17->ptr[0].changed[0] = v19;
          spawnNumer = v21;
          NumSoundsCreatedPerFrame_2 = v20 + 1;
          if ( mp_cg_soundDebug.valueInteger != 0 )
            idLib::Printf(
              fmt: "%i Server Play Sound %i: Presentable: %i Channel: %i Name: %s\n",
              v20 + 1,
              v21,
              presentableIndex,
              channel,
              shader->name.str);
        }
        else
        {
          num = this->startSoundOverRun.num;
          if ( num >= 512 )
          {
            idLib::Warning(
              fmt: "Overrun buffer full Dropping Presentable: %i Channel: %i Name: %s",
              presentableIndex,
              channel,
              shader->name.str);
          }
          else
          {
            v23 = 0;
            v24 = 0;
            if ( num > 0 )
            {
              list = this->startSoundOverRun.list;
              v26 = 0;
              p_startSoundOverRun = &this->startSoundOverRun;
              while ( list[v26].channel != channel || list[v26].presentableIndex != presentableIndex )
              {
                ++v24;
                ++v26;
                if ( v24 >= num )
                  goto LABEL_27;
              }
              v28 = v24;
              v29 = (float *)&p_startSoundOverRun->list[v24];
              v29[46] = pos->x;
              v29[47] = pos->y;
              v29[48] = pos->z;
              p_startSoundOverRun->list[v24].channel = channel;
              x = pos->x;
              p_startSoundOverRun->list[v24].shader = shader;
              if ( x != vec3_infinity.x || pos->y != vec3_infinity.y || (v31 = 1, pos->z != vec3_infinity.z) )
                v31 = 0;
              p_startSoundOverRun->list[v28].internalFlags = v31 != 0;
              p_startSoundOverRun->list[v28].presentableIndex = presentableIndex;
              p_startSoundOverRun->list[v28].volume = 0.0;
              p_startSoundOverRun->list[v28].peerMask = peerMask;
              memcpy(
                Dst: &p_startSoundOverRun->list[v28].parms,
                Src: parms,
                Size: sizeof(p_startSoundOverRun->list[v28].parms));
              v23 = 1;
              ++p_startSoundOverRun->list[v28].changed[0];
              p_startSoundOverRun->list[v28].framesToForceKeep = 2;
            }
LABEL_27:
            if ( v23 == 0 )
            {
              idReplicatedSound::idReplicatedSound(this: &v36);
              v32 = pos->x;
              v36.channel = channel;
              y = pos->y;
              v36.position.y = pos->y;
              v36.shader = shader;
              v36.position.x = v32;
              z = pos->z;
              v36.position.z = pos->z;
              if ( v32 != vec3_infinity.x || y != vec3_infinity.y || (v35 = 1, z != vec3_infinity.z) )
                v35 = 0;
              v36.volume = 0.0;
              v36.presentableIndex = presentableIndex;
              v36.peerMask = peerMask;
              v36.internalFlags = v35 != 0;
              v36.parms = *parms;
              v36.framesToForceKeep = 2;
              ++v36.changed[0];
              idList<idReplicatedSound,5>::Append(this: &this->startSoundOverRun, obj: &v36);
              if ( mp_cg_soundDebug.valueInteger != 0 )
                idLib::Printf(
                  fmt: "Overrun added %i: Presentable: %i Channel: %i Name: %s\n",
                  this->startSoundOverRun.num,
                  presentableIndex,
                  channel,
                  shader->name.str);
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ?PlayShaderDirectly@idClientGame@@QAAXPBVidSoundShader@@W4soundChannel_t@@ABVidVec3@@ABVidMat3@@E@Z
// EA  : 0x82B56210
// RVA : 0x00B56210
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::PlayShaderDirectly(
        idClientGame *this,
        const idSoundShader *shader,
        soundChannel_t channel,
        const idVec3 *pos,
        const idMat3 *axis,
        unsigned __int8 peerMask)
{
  char v11; // r11
  idSoundWorld_vtbl *v12; // r10
  soundShaderParms_t v13; // [sp+50h] [-D0h] BYREF

  if ( pos->x != vec3_infinity.x || pos->y != vec3_infinity.y || (v11 = 1, pos->z != vec3_infinity.z) )
    v11 = 0;
  v12 = this->soundWorld->__vftable;
  if ( v11 != 0 )
    ((void (__fastcall *)(double))v12->PlayGlobalShaderDirectly)(a1: 0.0);
  else
    ((void (__fastcall *)(double))v12->PlayPositionedShaderDirectly)(a1: 0.0);
  if ( peerMask != 0 )
  {
    soundShaderParms_t::Clear(this: &v13);
    v13.soundShaderFlags = 0;
    idClientGame::ReplicatePlaySound(this, channel, shader, parms: &v13, presentableIndex: 0xFFFFu, pos, peerMask);
  }
}


// ========================================================================
// ?TestFire@idClientGame@@QAA_NABVidFireParms@@AAVidTestFireResults@@@Z
// EA  : 0x82B56300
// RVA : 0x00B56300
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::TestFire(idClientGame *this, const idFireParms *fp, idTestFireResults *tfr)
{
  if ( fp->projDef->hitscan )
    return idClientGame::TestHitScan(this, fp, tfr);
  else
    return idClientGame::TestLaunchProjectile(this, fp, tfr);
}


// ========================================================================
// ?ImpactEffect@idClientGame@@QAAXABVidVec3@@0ABVidColor@@PBUprojectileImpactEffect_t@idDeclProjectileImpactEffect@@_N33PBVidPresentable@@PAV6@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA  : 0x82B56320
// RVA : 0x00B56320
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __fastcall idClientGame::ImpactEffect(
        idClientGame *this,
        const idMat3 *point,
        idMat3 *normal,
        idColor *color,
        const idDeclProjectileImpactEffect::projectileImpactEffect_t *effect,
        const bool skipParticle,
        const bool noDecals,
        const bool noSounds,
        const idPresentable *owner,
        idPresentable *entity,
        idIndex<short,enum invalidJointIndex_t> *jointId,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        unsigned __int16 a32)
{
  unsigned __int64 v40; // r6
  const char *v41; // r7
  int v42; // r25
  int v43; // r3
  const idMaterial **list; // r6
  int v45; // r5
  int decalLifetime; // r4
  double decalSize; // fp0
  double decalDepth; // fp13
  double decalAngle; // fp12
  float v50; // r10
  float x; // r27
  int GameMs; // r3
  idRenderModelDecal *v53; // r27
  int v54; // r3
  const idSoundShader *sndImpact; // r4
  __int64 v56; // r11
  unsigned int v57; // r5
  double v58; // fp31
  int GameMsPerFrame; // r26
  int v60; // r27
  idRenderModelEffects *effectsModel; // r25
  idMat3 *v62; // r3
  double v63; // fp31
  double v64; // fp12
  double v65; // fp11
  double v66; // fp10
  double v67; // fp6
  idColor *v68; // r11
  float g; // r8
  float b; // r7
  float a; // r6
  unsigned int v72; // r27
  const idMaterial *particleImpact; // r29
  idMat3 *v74; // r3
  double v75; // fp0
  double z; // fp13
  double y; // fp12
  idRenderWorld *renderWorld; // r3
  double v79; // fp8
  double v80; // fp7
  double v81; // fp6
  double v82; // fp5
  idRenderWorld *v83; // r3
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // r9
  double v85; // fp3
  double v86; // fp2
  double v87; // fp1
  double v88; // fp0
  idRenderWorld *v89; // r3
  int v90; // [sp+8h] [-1F8h]
  const idColor *v91; // [sp+Ch] [-1F4h]
  int v92; // [sp+10h] [-1F0h]
  int v93; // [sp+14h] [-1ECh]
  int v94; // [sp+18h] [-1E8h]
  int v95; // [sp+1Ch] [-1E4h]
  int v96; // [sp+20h] [-1E0h]
  int v97; // [sp+24h] [-1DCh]
  int v98; // [sp+28h] [-1D8h]
  int v99; // [sp+2Ch] [-1D4h]
  int v100; // [sp+30h] [-1D0h]
  int v101; // [sp+34h] [-1CCh]
  int v102; // [sp+38h] [-1C8h]
  int v103; // [sp+3Ch] [-1C4h]
  int v104; // [sp+40h] [-1C0h]
  int v105; // [sp+44h] [-1BCh]
  int v106; // [sp+48h] [-1B8h]
  int v107; // [sp+4Ch] [-1B4h]
  int v108; // [sp+50h] [-1B0h]
  int v109; // [sp+58h] [-1A8h]
  int v110; // [sp+5Ch] [-1A4h]
  int v111; // [sp+60h] [-1A0h]
  int v112; // [sp+68h] [-198h]
  idVec3 v113; // [sp+70h] [-190h] BYREF
  float v114[10]; // [sp+80h] [-180h] BYREF
  idPLogScope v115; // [sp+A8h] [-158h] BYREF
  float v116[4]; // [sp+B0h] [-150h] BYREF
  float v117[4]; // [sp+C0h] [-140h] BYREF
  float v118[4]; // [sp+D0h] [-130h] BYREF
  float v119[4]; // [sp+E0h] [-120h] BYREF
  float v120[4]; // [sp+F0h] [-110h] BYREF
  float v121[4]; // [sp+100h] [-100h] BYREF
  float v122[4]; // [sp+110h] [-F0h] BYREF
  float v123[4]; // [sp+120h] [-E0h] BYREF
  float v124[4]; // [sp+130h] [-D0h] BYREF
  _QWORD v125[2]; // [sp+140h] [-C0h] BYREF
  idVec3 v126[4]; // [sp+150h] [-B0h] BYREF

  RD_EventBegin(name: "idClientGame::ImpactEffect");
  LODWORD(v40) = "idClientGame::ImpactEffect";
  HIDWORD(v40) = 2;
  idPLogScope::idPLogScope(this: &v115, pl: &pLog, gMask: v40, label: v41);
  if ( effect != nullptr )
  {
    v42 = 0;
    LODWORD(v113.x) = effect->decalMaterial.num;
    if ( SLODWORD(v113.x) > 0 && g_stopTime.valueInteger == 0 && !noDecals )
    {
      v114[4] = 0.0;
      v114[0] = 0.0;
      v114[7] = 0.0;
      LODWORD(v114[5]) = 10000;
      LODWORD(v114[6]) = 2000;
      v114[1] = 8.0;
      HIBYTE(v114[8]) = 0;
      v114[2] = 32.0;
      v114[3] = 32.0;
      v43 = idRandom2::RandomInt(this: &this->random, max: LODWORD(v113.x) - 1);
      list = effect->decalMaterial.list;
      v45 = v43;
      decalLifetime = effect->decalLifetime;
      decalSize = effect->decalSize;
      LOBYTE(v43) = effect->decalQuad;
      decalDepth = effect->decalDepth;
      decalAngle = effect->decalAngle;
      v113.x = effect->decalSize;
      v50 = *(float *)&list[v45];
      v114[1] = decalDepth;
      v114[4] = decalAngle;
      v114[2] = decalSize;
      LODWORD(v114[5]) = decalLifetime;
      v114[3] = decalSize;
      HIBYTE(v114[8]) = v43;
      v114[0] = v50;
      if ( a30 != 0 && (v113.x = *(float *)(a30 + 168), x = v113.x, LODWORD(v113.x) != 0) )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &this->gameTimeManager, type: GAMETIME_SCALED);
        (*(void (__fastcall **)(idVec3 *, double, float *, int, const idMat3 *, idMat3 *, _DWORD))(*(_DWORD *)LODWORD(x)
                                                                                                 + 16))(
          a1: &v113,
          a2: COERCE_DOUBLE(LODWORD(x)),
          a3: v114,
          a4: GameMs,
          a5: point,
          a6: normal,
          a7: a32);
      }
      else
      {
        v53 = this->renderWorld->DecalModel(this: this->renderWorld);
        v54 = idGameTimeManager::GetGameMs(this: &this->gameTimeManager, type: GAMETIME_SCALED);
        v53->AddDecalFromPoint(
          this: (idRenderModel *)&v113,
          result: (idHandle<int,enum invalidDecalHandle_t,-1> *)v53,
          a3: (const decalParams_t *)v114,
          a4: v54,
          a5: point->mat,
          a6: normal->mat,
          a7: (idIndex<short,enum invalidJointIndex_t> *)(unsigned __int16)NULL_JOINT_INDEX.value);
      }
    }
    sndImpact = effect->sndImpact;
    if ( sndImpact != nullptr && !noSounds )
      idClientGame::PlayShaderDirectly(
        this,
        shader: sndImpact,
        channel: SND_CHANNEL_DAMAGE,
        pos: point->mat,
        axis: &mat3_identity,
        peerMask: 0);
    if ( !skipParticle && effect->particleImpact != nullptr )
    {
      if ( effect->useSmokeSystem )
      {
        HIDWORD(v56) = this->random.seed;
        v57 = 1664525 * this->random.seed + 1013904223;
        v113.x = NAN;
        LODWORD(v56) = (v57 >> 10) & 0x7FFF;
        this->random.seed = v57;
        v125[0] = v56;
        v58 = (float)((float)v56 * (float)0.000030518509);
        GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &this->gameTimeManager, type: GAMETIME_SCALED);
        v60 = idGameTimeManager::GetGameMs(this: &this->gameTimeManager, type: GAMETIME_SCALED);
        effectsModel = this->gameLibEffects.effectsModel;
        v62 = idVec3::ToZAxis(this: v126, result: normal);
        idRenderModelEffects::AddParticles(
          this: effectsModel,
          particle: effect->particleImpact,
          systemStartTime: v60,
          gameMsPerFrame: GameMsPerFrame,
          diversity: v58,
          origin: &v113,
          axis: point,
          velocity: v62->mat,
          color: &vec3_origin.x,
          a10: v90,
          a11: (int)v91,
          a12: v92,
          a13: v93,
          a14: v94,
          a15: v95,
          a16: v96,
          a17: v97,
          a18: v98,
          a19: v99,
          a20: v100,
          a21: v101,
          a22: v102,
          a23: v103,
          a24: v104,
          a25: v105,
          a26: v106,
          a27: v107,
          a28: v108,
          a29: (unsigned int *)&v113);
      }
      else
      {
        v63 = 0.0;
        if ( a28 != 0 && (*(int (__fastcall **)(int))(*(_DWORD *)a28 + 100))(a1: a28) != 0 )
        {
          v42 = *(_DWORD *)(a28 + 1076);
          v64 = (float)(*(float *)(a28 + 124) - point->mat[0].y);
          v65 = *(float *)(a28 + 120);
          v66 = point->mat[0].x;
          LODWORD(v113.x) = a28 + 120;
          v67 = (float)(*(float *)(a28 + 128) - point->mat[0].z);
          v63 = (float)((float)((float)v67 * (float)v67)
                      + (float)((float)((float)((float)v65 - (float)v66) * (float)((float)v65 - (float)v66))
                              + (float)((float)v64 * (float)v64)));
        }
        if ( g_useImpactColor.valueInteger != 0 )
          v68 = color;
        else
          v68 = &idColor::colorWhite;
        g = v68->g;
        b = v68->b;
        a = v68->a;
        *(float *)v125 = v68->r;
        *((float *)v125 + 1) = g;
        *(float *)&v125[1] = b;
        *((float *)&v125[1] + 1) = a;
        v72 = idGameTimeManager::GetGameMs(this: &this->gameTimeManager, type: GAMETIME_SCALED);
        particleImpact = (const idMaterial *)effect->particleImpact;
        v74 = idVec3::ToZAxis(this: v126, result: normal);
        idImpactManager::UseImpact(
          this: &this->gameLibEffects.weaponImpactManager,
          org: point->mat,
          axis: v74,
          prt: particleImpact,
          startTime: v72,
          bindToParent: false,
          parentOrg: &vec3_origin,
          parentAxis: &mat3_identity,
          distSqr: v63,
          playerIndex: v90,
          color: v91,
          numCycles: v92,
          a13: v93,
          a14: v94,
          a15: v95,
          a16: v96,
          a17: v97,
          a18: v98,
          a19: v99,
          a20: v100,
          a21: v101,
          a22: v102,
          a23: v103,
          a24: v104,
          a25: v105,
          a26: v106,
          a27: v107,
          a28: v108,
          a29: v42,
          a30: v109,
          a31: v110,
          a32: v111,
          a33: (float *)v125,
          a34: v112,
          a35: 1);
      }
    }
    if ( g_debugImpactEffect.valueInteger != 0 )
    {
      v75 = point->mat[0].x;
      z = point->mat[0].z;
      y = point->mat[0].y;
      renderWorld = this->renderWorld;
      v120[2] = point->mat[0].z;
      v120[1] = y;
      v122[0] = 1.0;
      v120[0] = (float)v75 + (float)3.0;
      v119[0] = (float)v75 - (float)3.0;
      v119[1] = y;
      v119[2] = z;
      v122[1] = 0.0;
      v122[2] = 1.0;
      v122[3] = 1.0;
      v113.x = y;
      renderWorld->DebugLine(
        this: renderWorld,
        a2: (const idVec4 *)v122,
        a3: (const idVec3 *)v119,
        a4: (const idVec3 *)v120,
        a5: 5000,
        a6: true);
      v79 = point->mat[0].z;
      v80 = (float)(point->mat[0].y + (float)3.0);
      v81 = point->mat[0].x;
      v82 = (float)(point->mat[0].y - (float)3.0);
      v124[0] = 1.0;
      v83 = this->renderWorld;
      v124[1] = 0.0;
      v124[2] = 1.0;
      v124[3] = 1.0;
      v121[0] = v81;
      v121[2] = v79;
      v116[0] = v81;
      v116[2] = v79;
      v121[1] = v80;
      v116[1] = v82;
      DebugLine = v83->DebugLine;
      v113.x = v79;
      DebugLine(
        this: v83,
        a2: (const idVec4 *)v124,
        a3: (const idVec3 *)v116,
        a4: (const idVec3 *)v121,
        a5: 5000,
        a6: true);
      v85 = point->mat[0].y;
      v86 = (float)(point->mat[0].z + (float)3.0);
      v87 = point->mat[0].x;
      v88 = (float)(point->mat[0].z - (float)3.0);
      v113.x = point->mat[0].y;
      v89 = this->renderWorld;
      v123[0] = 1.0;
      v123[1] = 0.0;
      v123[2] = 1.0;
      v123[3] = 1.0;
      v118[0] = v87;
      v118[1] = v85;
      v117[0] = v87;
      v117[1] = v85;
      v113.x = v85;
      v118[2] = v86;
      v117[2] = v88;
      v89->DebugLine(
        this: v89,
        a2: (const idVec4 *)v123,
        a3: (const idVec3 *)v117,
        a4: (const idVec3 *)v118,
        a5: 5000,
        a6: true);
    }
    idPLogScope::~idPLogScope(this: &v115);
  }
  else
  {
    idLib::Warning(fmt: "NULL effect passed into idGameLocal::ImpactEffect");
    idPLogScope::~idPLogScope(this: &v115);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$505227_0
// EA  : 0x82B568AC
// RVA : 0x00B568AC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505227_0()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 512 + 372));
}


// ========================================================================
// __unwind$505228
// EA  : 0x82B568D4
// RVA : 0x00B568D4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505228()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 512 + 168));
}


// ========================================================================
// ?ProjectileImpact@idClientGame@@QAAXABUtrace_t@@PBVidPresentable@@PBVidDeclProjectile@@_N33@Z
// EA  : 0x82B56908
// RVA : 0x00B56908
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idClientGame::ProjectileImpact(
        idClientGame *this,
        const trace_t *trace,
        const idPresentable *attacker,
        const idDeclProjectile *projDef,
        const bool tracerFired,
        const bool noDecals,
        bool noSounds)
{
  unsigned __int64 v14; // r6
  const char *v15; // r7
  int valueInteger; // r11
  idDynamicWaterEntity *v17; // r27
  int entityNum; // r11
  int v19; // r8
  int IsType; // r10
  char v21; // r11
  char v22; // r24
  int v23; // r10
  char v24; // r11
  idDynamicWaterEntity *v25; // r3
  idDynamicWaterEntity *v26; // r28
  int v27; // r5
  int surfaceType; // r29
  double x; // fp0
  double z; // fp13
  idRenderWorld *renderWorld; // r3
  double y; // fp11
  double v33; // fp8
  double v34; // fp7
  double v35; // fp6
  double v36; // fp5
  idRenderWorld *v37; // r3
  void (__fastcall *DebugLine)(idRenderWorld *, const idVec4 *, const idVec3 *, const idVec3 *, const int, const bool); // r11
  double v39; // fp4
  double v40; // fp3
  double v41; // fp2
  double v42; // fp1
  idRenderWorld *v43; // r3
  idRenderWorld_vtbl *v44; // r10
  const idDeclProjectileImpactEffect::projectileImpactEffect_t *ImpactEffectForMaterial; // r25
  int v46; // r2 OVERLAPPED
  int presentable; // r28
  unsigned __int16 value; // r26
  idDynamicWaterEntity_vtbl *v49; // r29
  const idPresentablePlayer *v50; // r3
  double v51; // fp9
  double v52; // fp7
  __int128 v53; // r11
  __int64 v54; // r7
  bool v55; // r9
  bool v56; // r8
  __int64 v57; // r4
  __int64 v58; // r11
  bool v59; // r9
  bool v60; // r8
  const idPresentable *v61; // [sp+8h] [-208h]
  idPresentable *v62; // [sp+Ch] [-204h]
  idIndex<short,enum invalidJointIndex_t> *v63; // [sp+10h] [-200h]
  int v64; // [sp+14h] [-1FCh]
  int v65; // [sp+18h] [-1F8h]
  int v66; // [sp+1Ch] [-1F4h]
  int v67; // [sp+20h] [-1F0h]
  int v68; // [sp+24h] [-1ECh]
  int v69; // [sp+28h] [-1E8h]
  int v70; // [sp+2Ch] [-1E4h]
  int v71; // [sp+30h] [-1E0h]
  int v72; // [sp+34h] [-1DCh]
  int v73; // [sp+38h] [-1D8h]
  int v74; // [sp+3Ch] [-1D4h]
  int v75; // [sp+40h] [-1D0h]
  int v76; // [sp+44h] [-1CCh]
  int v77; // [sp+48h] [-1C8h]
  int v78; // [sp+4Ch] [-1C4h]
  int v79[20]; // [sp+50h] [-1C0h] BYREF
  __int64 v80; // [sp+A0h] [-170h] BYREF
  idPLogScope v81; // [sp+A8h] [-168h] BYREF
  idColor v82; // [sp+B0h] [-160h] BYREF
  idMat3 v83; // [sp+C0h] [-150h] BYREF
  float v84; // [sp+E4h] [-12Ch]
  float v85; // [sp+E8h] [-128h]
  float v86[4]; // [sp+F0h] [-120h] BYREF
  float v87[4]; // [sp+100h] [-110h] BYREF
  float v88[4]; // [sp+110h] [-100h] BYREF
  float v89[4]; // [sp+120h] [-F0h] BYREF
  float v90[4]; // [sp+130h] [-E0h] BYREF
  float v91[4]; // [sp+140h] [-D0h] BYREF
  float v92[4]; // [sp+150h] [-C0h] BYREF
  idColor v93; // [sp+160h] [-B0h] BYREF
  __int64 v94; // [sp+170h] [-A0h]

  RD_EventBegin(name: "idClientGame::ProjectileImpact");
  LODWORD(v14) = "idClientGame::ProjectileImpact";
  HIDWORD(v14) = 2;
  idPLogScope::idPLogScope(this: &v81, pl: &pLog, gMask: v14, label: v15);
  valueInteger = g_debugImpactEffect.valueInteger;
  if ( g_debugImpactEffect.valueInteger != 0 )
  {
    idLib::Printf(fmt: "ProjectileImpact for surface type: %d\n", trace->c.surfaceType);
    valueInteger = g_debugImpactEffect.valueInteger;
  }
  if ( projDef == nullptr )
  {
    if ( valueInteger != 0 )
      idLib::Warning(fmt: "ProjDef is NULL in ProjectileImpact");
    goto LABEL_59;
  }
  if ( projDef->impactEffectTable == nullptr )
  {
    if ( valueInteger != 0 )
      idLib::Warning(fmt: "ProjDef impactEffectTable is NULL in ProjectileImpact");
    goto LABEL_59;
  }
  v17 = nullptr;
  if ( !common->IsServer(this: common) )
  {
LABEL_14:
    if ( common->IsServer(this: common) )
    {
      if ( g_debugImpactEffect.valueInteger != 0 )
        idLib::Warning(fmt: " No hit entity in ProjectileImpactEffect ");
      goto LABEL_59;
    }
    goto LABEL_20;
  }
  entityNum = trace->c.entityNum;
  if ( entityNum < 0 )
  {
    v17 = nullptr;
    goto LABEL_14;
  }
  v19 = 4 * (entityNum + 21563);
  v17 = *(idDynamicWaterEntity **)((char *)&gameLocal->__vftable + v19);
  if ( v17 == nullptr )
    goto LABEL_14;
  IsType = (unsigned __int8)idClass::IsType(
                              this: *(idClass **)((char *)&gameLocal->__vftable + v19),
                              superclass: &idPlayer::Type);
  v21 = 1;
  if ( IsType == 0 )
LABEL_20:
    v21 = 0;
  v22 = v21;
  if ( v17 == nullptr
    || (v23 = (unsigned __int8)idClass::IsType(this: v17, superclass: &idDynamicWaterEntity::Type), v24 = 1, v23 == 0) )
  {
    v24 = 0;
  }
  if ( v24 != 0 && projDef->waterInteraction.allowWaterInteraction )
  {
    v25 = idDynamicWaterEntity::CastTo(c: v17);
    v26 = v25;
    if ( v25 != nullptr )
    {
      idDynamicWaterEntity::AddRipple(
        this: v25,
        pos: &trace->c.point,
        mag: projDef->waterInteraction.waterHitMagnitude,
        radius: projDef->waterInteraction.waterHitRadius);
      if ( projDef->waterInteraction.shouldIlluminateWater )
        idDynamicWaterEntity::ApplyRadiusEffect(
          this: v26,
          pos: &trace->c.point,
          radius: projDef->waterInteraction.waterIlluminationRadius,
          time: v27);
    }
  }
  surfaceType = trace->c.surfaceType;
  if ( surfaceType != 0
    || v17 == nullptr
    || (unsigned __int8)idClass::IsType(this: v17, superclass: &idWaterEntity::Type) == 0 )
  {
    goto LABEL_34;
  }
  surfaceType = 6;
  if ( g_debugImpactEffect.valueInteger != 0 )
  {
    idLib::Printf(fmt: "Setting surfacetype to SURFTYPE_LIQUID because we hit a idWaterEntity with a default surfacetype result\n");
LABEL_34:
    if ( g_debugImpactEffect.valueInteger != 0 && surfaceType == 0 )
    {
      idLib::Warning(fmt: "SurfaceType == SURFTYPE_NONE");
      x = trace->endpos.x;
      z = trace->endpos.z;
      renderWorld = this->renderWorld;
      y = trace->endpos.y;
      v90[0] = 1.0;
      v90[2] = 1.0;
      v90[3] = 1.0;
      v90[1] = 0.0;
      v89[2] = z;
      v89[1] = y;
      v89[0] = (float)x + (float)3.0;
      v87[0] = (float)x - (float)3.0;
      v87[1] = y;
      v87[2] = z;
      *(float *)&v80 = y;
      renderWorld->DebugLine(
        this: renderWorld,
        a2: (const idVec4 *)v90,
        a3: (const idVec3 *)v87,
        a4: (const idVec3 *)v89,
        a5: 5000,
        a6: true);
      v33 = trace->endpos.z;
      v34 = (float)(trace->endpos.y + (float)3.0);
      v35 = trace->endpos.x;
      v36 = (float)(trace->endpos.y - (float)3.0);
      v91[0] = 1.0;
      v37 = this->renderWorld;
      v91[1] = 0.0;
      v91[2] = 1.0;
      v91[3] = 1.0;
      v83.mat[1].y = v35;
      v83.mat[2].x = v33;
      v88[0] = v35;
      v88[2] = v33;
      v83.mat[1].z = v34;
      v88[1] = v36;
      DebugLine = v37->DebugLine;
      *(float *)&v80 = v33;
      DebugLine(
        this: v37,
        a2: (const idVec4 *)v91,
        a3: (const idVec3 *)v88,
        a4: (const idVec3 *)&v83.mat[1].y,
        a5: 5000,
        a6: true);
      v39 = trace->endpos.z;
      v40 = trace->endpos.y;
      v41 = (float)(trace->endpos.z + (float)3.0);
      v42 = trace->endpos.x;
      v43 = this->renderWorld;
      v92[0] = 1.0;
      v92[1] = 0.0;
      v92[2] = 1.0;
      v92[3] = 1.0;
      *(float *)&v80 = v40;
      v83.mat[2].z = v42;
      v84 = v40;
      v86[0] = v42;
      v86[1] = v40;
      v85 = v41;
      v86[2] = (float)v39 - (float)3.0;
      v44 = v43->__vftable;
      *(float *)&v80 = v40;
      v44->DebugLine(
        this: v43,
        a2: (const idVec4 *)v92,
        a3: (const idVec3 *)v86,
        a4: (const idVec3 *)&v83.mat[2].z,
        a5: 5000,
        a6: true);
    }
  }
  ImpactEffectForMaterial = idDeclProjectileImpactEffect::GetImpactEffectForMaterial(
                              this: projDef->impactEffectTable,
                              materialID: surfaceType);
  if ( ImpactEffectForMaterial != nullptr )
  {
    presentable = 0;
    value = NULL_JOINT_INDEX.value;
    if ( v17 != nullptr )
    {
      v49 = v17->__vftable;
      memcpy(Dst: v79, Src: &trace->endAxis.mat[2].z, Size: sizeof(v79));
      value = *(_WORD *)((int (__fastcall *)(__int64 *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v49->GetJointIndexFromTrace)(
                          a1: &v80,
                          a2: LODWORD(trace->fraction),
                          a3: LODWORD(trace->endpos.y),
                          a4: LODWORD(trace->endAxis.mat[0].x),
                          a5: LODWORD(trace->endAxis.mat[0].z),
                          a6: LODWORD(trace->endAxis.mat[1].y),
                          a7: LODWORD(trace->endAxis.mat[2].x),
                          a8: LODWORD(trace->endAxis.mat[2].y));
      if ( v17->presentable == nullptr )
        idEntity::InitPresentableInternal(this: v17);
      presentable = (int)v17->presentable;
    }
    if ( attacker != nullptr
      && attacker->GetPlayerInterface(this: attacker) != nullptr
      && g_testEffects.valueInteger != 0 )
    {
      v50 = attacker->GetPlayerInterface(this: attacker);
      v51 = (float)(v50->firstPersonViewOrigin.z - trace->c.point.z);
      v52 = (float)(v50->firstPersonViewOrigin.y - trace->c.point.y);
      v83.mat[0].x = v50->firstPersonViewOrigin.x - trace->c.point.x;
      v83.mat[0].z = v51;
      v83.mat[0].y = v52;
      idVec3::NormalizeFast(this: v83.mat);
      LODWORD(v53) = trace->c.surfaceColor[0];
      DWORD2(v53) = trace->c.surfaceColor[2];
      HIDWORD(v54) = byte_821B0000;
      LODWORD(v54) = trace->c.surfaceColor[1];
      v82.a = 1.0;
      v80 = v54;
      v82.g = (float)v54 * (float)0.0039215689;
      v82.b = (float)*(__int64 *)((char *)&v53 + 4) * (float)0.0039215689;
      v82.r = (float)(__int64)v53 * (float)0.0039215689;
      if ( noDecals || (v55 = false, v22 != 0) )
        v55 = true;
      if ( tracerFired || (v56 = false, v22 != 0) )
        v56 = true;
      idClientGame::ImpactEffect(
        this,
        point: (const idMat3 *)&trace->c.point,
        normal: &v83,
        color: &v82,
        effect: ImpactEffectForMaterial,
        skipParticle: v56,
        noDecals: v55,
        noSounds,
        owner: v61,
        entity: v62,
        jointId: v63,
        a12: v64,
        a13: v65,
        a14: v66,
        a15: v67,
        a16: v68,
        a17: v69,
        a18: v70,
        a19: v71,
        a20: v72,
        a21: v73,
        a22: v74,
        a23: v75,
        a24: v76,
        a25: v77,
        a26: v78,
        a27: v79[0],
        a28: (int)attacker,
        a29: v79[2],
        a30: presentable,
        a31: v79[4],
        a32: value);
    }
    else
    {
      HIDWORD(v57) = trace->c.surfaceColor[2];
      HIDWORD(v58) = byte_821B0000;
      LODWORD(v58) = trace->c.surfaceColor[1];
      LODWORD(v57) = trace->c.surfaceColor[0];
      v93.a = 1.0;
      v80 = *(_QWORD *)(&v46 - 1);
      v94 = v58;
      *(_QWORD *)&v82.r = v57;
      v93.r = (float)v57 * (float)0.0039215689;
      v93.b = (float)*(__int64 *)(&v46 - 1) * (float)0.0039215689;
      v93.g = (float)v58 * (float)0.0039215689;
      if ( noDecals || (v59 = false, v22 != 0) )
        v59 = true;
      if ( tracerFired || (v60 = false, v22 != 0) )
        v60 = true;
      idClientGame::ImpactEffect(
        this,
        point: (const idMat3 *)&trace->c.point,
        normal: (idMat3 *)&trace->c.normal,
        color: &v93,
        effect: ImpactEffectForMaterial,
        skipParticle: v60,
        noDecals: v59,
        noSounds,
        owner: v61,
        entity: v62,
        jointId: v63,
        a12: v64,
        a13: v65,
        a14: v66,
        a15: v67,
        a16: v68,
        a17: v69,
        a18: v70,
        a19: v71,
        a20: v72,
        a21: v73,
        a22: v74,
        a23: v75,
        a24: v76,
        a25: v77,
        a26: v78,
        a27: v79[0],
        a28: (int)attacker,
        a29: v79[2],
        a30: presentable,
        a31: v79[4],
        a32: value);
    }
  }
LABEL_59:
  idPLogScope::~idPLogScope(this: &v81);
  RD_EventEnd();
}


// ========================================================================
// __unwind$505593
// EA  : 0x82B56FE0
// RVA : 0x00B56FE0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505593()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 528 + 376));
}


// ========================================================================
// __unwind$505594
// EA  : 0x82B57008
// RVA : 0x00B57008
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505594()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 528 + 168));
}


// ========================================================================
// ?FinishHitScan@idClientGame@@QAA_NABVidFireParms@@AAVidTestFireResults@@AAVidFinishFireResults@@@Z
// EA  : 0x82B57038
// RVA : 0x00B57038
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::FinishHitScan(
        idClientGame *this,
        const idFireParms *fp,
        idTestFireResults *tfr,
        idFinishFireResults *ffr)
{
  idClientGame *v4; // r14
  idTestFireResults *v6; // r23
  idFinishFireResults *v7; // r22
  unsigned __int64 v8; // r6
  const char *v9; // r7
  idPresentable *v10; // r3
  int v11; // r26
  int v12; // r25
  trace_t *traces; // r30
  float *traceLens; // r28
  float *p_y; // r29
  double fraction; // fp30
  idEntity *entity; // r5
  double v18; // fp9
  double v19; // fp8
  double z; // fp7
  double y; // fp6
  const idSpawnId **SpawnId; // r3
  weaponStatsTag_t *v23; // r26
  idPresentable *v24; // r3
  const idDeclProjectile *projDef; // r11
  const idMaterial *tracerMtr; // r27
  idPresentable *v27; // r3
  idPresentablePlayer *PlayerDriver; // r30
  idPresentable *v29; // r3
  idPresentableVehicle *v30; // r3
  idPresentableVehicle *v31; // r28
  char v32; // r11
  const idDeclProjectile *v33; // r11
  unsigned int v34; // r3
  int tracerCount; // r9
  signed int tracers; // r8
  idCVar *v38; // r29
  int v39; // r28
  idRenderWorld *renderWorld; // r3
  double x; // fp11
  double v42; // fp10
  double v43; // fp9
  double v44; // fp8
  double v45; // fp7
  double v46; // fp6
  int numTraces; // r8
  int v48; // r30
  char *v49; // r11
  const trace_t *v50; // r26
  double v51; // fp13
  int v52; // r11
  double v53; // fp11
  double v54; // fp12
  idVec3 *p_start; // r20
  double v56; // fp9
  double v57; // fp0
  double v58; // fp8
  double v59; // fp7
  double v61; // fp10
  double v63; // fp6
  double v64; // fp6
  double v65; // fp27
  idAI2 *v66; // r25
  idPresentable *PresentableByEntityNum; // r21
  int v68; // r22
  char v69; // r23
  unsigned __int64 v70; // r6
  const char *v71; // r7
  idAI2 *v72; // r28
  idDamageableEntity *v73; // r30
  idProp_Breakable *v74; // r29
  idWaterEntity *v75; // r3
  double damageScale; // fp28
  idWaterEntity *v77; // r27
  const char *str; // r14
  idStrId *v79; // r3
  idStrId *DisplayName; // r3
  const char *LocalizedString; // r3
  double v82; // fp28
  idPhysics *Physics; // r3
  const idVec3 *v84; // r3
  __int64 v85; // r10
  const idPresentable *v86; // r5
  const char *v87; // r14
  idStrId *v88; // r3
  idStrId *v89; // r3
  const char *v90; // r3
  const idDeclDamage *v91; // r30
  const idDeclProjectile *v92; // r11
  const idDeclDamage *electricDamageDecl; // r11
  unsigned __int64 v94; // r6
  const char *v95; // r7
  idPresentable *v96; // r3
  bool v97; // r28
  int v98; // r11
  int *p_surfaceType; // r10
  bool v100; // r30
  int num; // ctr
  float *v102; // r10
  signed int v103; // r11
  bool v104; // r9
  const idPresentable *v105; // r11
  idPresentablePlayer *v106; // r30
  double maxDamage; // fp28
  idPresentable *v108; // r3
  idRenderWorld *v109; // r3
  idRenderWorld *v110; // r3
  idRenderWorld *v111; // r3
  float *v112; // r4
  double v113; // fp0
  int valueInteger; // r11
  double v115; // fp11
  double v116; // fp12
  double v117; // fp9
  double v118; // fp13
  double v119; // fp7
  double v122; // fp6
  double v123; // fp6
  idRenderWorld *v124; // r3
  idRenderWorld *v125; // r3
  idRenderWorld *v126; // r3
  const idSoundShader *sndTracer; // r30
  idPlayer *LocalPlayer; // r3
  idPresentable *presentable; // r3
  int v130; // r3
  double v131; // fp5
  double v132; // fp4
  double v133; // fp3
  unsigned int v134; // r8
  int index; // r30
  signed int v136; // r11
  idPresentable **list; // r9
  bool v139; // r10
  idPresentable *v140; // r11
  idPresentable *v141; // r3
  int v142; // r9
  bool v143; // r8
  double v144; // fp9
  double v145; // fp7
  idWeapon *Weapon; // r3
  int v147; // r9
  bool v148; // r8
  const idDeclProjectile *v149; // r11
  double v150; // fp9
  double v151; // fp6
  int v152; // r10
  int v153; // ctr
  idPresentablePtr<idPresentableProjectile> *projectiles; // r11
  char *v155; // r9
  idPLog *pLog; // r29
  idPLog::logEntry_t *v157; // r30
  int v158; // r3
  __int64 totalTicks; // r11
  __int64 v160; // r9
  int v161; // [sp+8h] [-538h]
  int v162; // [sp+Ch] [-534h]
  int v163; // [sp+10h] [-530h]
  int v164; // [sp+14h] [-52Ch]
  int v165; // [sp+18h] [-528h]
  int v166; // [sp+1Ch] [-524h]
  int v167; // [sp+20h] [-520h]
  int v168; // [sp+24h] [-51Ch]
  double v169; // [sp+28h] [-518h]
  int v170; // [sp+30h] [-510h]
  int v171; // [sp+34h] [-50Ch]
  int v172; // [sp+38h] [-508h]
  int v173; // [sp+3Ch] [-504h]
  int v174; // [sp+40h] [-500h]
  int v175; // [sp+44h] [-4FCh]
  int v176; // [sp+48h] [-4F8h]
  int v177; // [sp+4Ch] [-4F4h]
  int v178; // [sp+50h] [-4F0h]
  int v179; // [sp+58h] [-4E8h]
  int v180; // [sp+5Ch] [-4E4h]
  int v181; // [sp+60h] [-4E0h]
  float *v182; // [sp+70h] [-4D0h]
  bool v183; // [sp+74h] [-4CCh]
  idVec3 v184; // [sp+78h] [-4C8h] BYREF
  const idDeclDamage *damageDecl; // [sp+84h] [-4BCh]
  idPresentablePlayer *v186; // [sp+88h] [-4B8h]
  idCVar *v187; // [sp+8Ch] [-4B4h]
  _DWORD v188[2]; // [sp+90h] [-4B0h] BYREF
  idVec3 v189; // [sp+98h] [-4A8h] BYREF
  int v190; // [sp+A4h] [-49Ch]
  int v191; // [sp+A8h] [-498h] BYREF
  weaponStatsTag_t *v192; // [sp+ACh] [-494h]
  const idMaterial *v193; // [sp+B0h] [-490h]
  idPresentableVehicle *v194; // [sp+B4h] [-48Ch]
  float v195; // [sp+B8h] [-488h]
  const char *v196; // [sp+BCh] [-484h]
  idPLog *v197; // [sp+C0h] [-480h]
  idVec3 v198; // [sp+C8h] [-478h] BYREF
  idPLogScope v199; // [sp+D8h] [-468h] BYREF
  idCVar *v200; // [sp+E0h] [-460h]
  const char *v201; // [sp+E4h] [-45Ch]
  idCVar *v202; // [sp+E8h] [-458h]
  idVec3 v203; // [sp+F0h] [-450h] BYREF
  float v204[4]; // [sp+100h] [-440h] BYREF
  float v205[4]; // [sp+110h] [-430h] BYREF
  float v206[4]; // [sp+120h] [-420h] BYREF
  float v207[4]; // [sp+130h] [-410h] BYREF
  idVec3 v208; // [sp+140h] [-400h] BYREF
  float v209[4]; // [sp+150h] [-3F0h] BYREF
  idVec3 v210; // [sp+160h] [-3E0h] BYREF
  float v211[4]; // [sp+170h] [-3D0h] BYREF
  float v212[4]; // [sp+180h] [-3C0h] BYREF
  float v213[4]; // [sp+190h] [-3B0h] BYREF
  float v214[4]; // [sp+1A0h] [-3A0h] BYREF
  float v215[4]; // [sp+1B0h] [-390h] BYREF
  float v216[4]; // [sp+1C0h] [-380h] BYREF
  float v217[4]; // [sp+1D0h] [-370h] BYREF
  float v218[4]; // [sp+1E0h] [-360h] BYREF
  idVec3 v219; // [sp+1F0h] [-350h] BYREF
  float v220[4]; // [sp+200h] [-340h] BYREF
  float v221[4]; // [sp+210h] [-330h] BYREF
  float v222[4]; // [sp+220h] [-320h] BYREF
  float v223[4]; // [sp+230h] [-310h] BYREF
  float v224[4]; // [sp+240h] [-300h] BYREF
  float v225[4]; // [sp+250h] [-2F0h] BYREF
  float v226[4]; // [sp+260h] [-2E0h] BYREF
  float v227[4]; // [sp+270h] [-2D0h] BYREF
  float v228[4]; // [sp+280h] [-2C0h] BYREF
  idMat3 v229; // [sp+290h] [-2B0h] BYREF
  idPLogScope v230; // [sp+2B8h] [-288h] BYREF
  idPLogScope v231; // [sp+2C0h] [-280h] BYREF
  idInventoryItem v232; // [sp+2C8h] [-278h] BYREF
  idList<idVec3,5> v233; // [sp+300h] [-240h] BYREF
  int v234; // [sp+310h] [-230h] BYREF
  trace_t v235; // [sp+3D0h] [-170h] BYREF

  v4 = this;
  v6 = tfr;
  v7 = ffr;
  RD_EventBegin(name: "idClientGame::FinishHitScan");
  LODWORD(v8) = "idClientGame::FinishHitScan";
  HIDWORD(v8) = 2;
  v197 = &::pLog;
  idPLogScope::idPLogScope(this: &v199, pl: &::pLog, gMask: v8, label: v9);
  v7->numProjectiles = 0;
  if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) != nullptr
    && idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker)->entity != nullptr )
  {
    v10 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
    if ( idPlayer::CastTo(c: (idPlayer *)v10->entity) != nullptr )
    {
      v11 = 0;
      v12 = 0;
      if ( v6->numTraces > 0 )
      {
        traces = v6->traces;
        traceLens = v6->traceLens;
        p_y = &v6->traceDirs[0].y;
        do
        {
          if ( v11 >= 5 )
            break;
          fraction = traces->fraction;
          if ( fraction < 1.0 )
          {
            entity = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker)->entity;
            v18 = (float)(p_y[1] * *traceLens);
            v19 = (float)(*traceLens * *p_y);
            z = traces->endpos.z;
            y = traces->endpos.y;
            v208.x = traces->endpos.x - (float)((float)(*(p_y - 1) * *traceLens) * (float)fraction);
            v195 = fraction;
            v208.z = (float)z - (float)((float)v18 * (float)fraction);
            v208.y = (float)y - (float)((float)v19 * (float)fraction);
            SpawnId = (const idSpawnId **)idGameLocal::GetSpawnId(
                                            this: (idGameLocal *)v188,
                                            result: (idSpawnId *)gameLocal,
                                            ent: entity);
            idWeaponTraceManager::AddTrace(
              this: &v4->gameLibEffects.weaponTraceManager,
              start: &v208,
              end: &traces->endpos,
              spawnId: *SpawnId,
              damage: fp->projDef->damageDecl);
            ++v11;
          }
          ++v12;
          ++traceLens;
          p_y += 3;
          ++traces;
        }
        while ( v12 < v6->numTraces );
      }
    }
  }
  v191 = 0;
  v23 = nullptr;
  v192 = nullptr;
  if ( common->IsServer(this: common) )
  {
    v24 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
    v23 = (weaponStatsTag_t *)*idGameLocal::WeaponFired(
                                 this: (idGameLocal *)v188,
                                 result: (weaponStatsTag_t *)gameLocal,
                                 entity: v24,
                                 decl: fp->wepDef);
    v192 = v23;
    idGameLocal::SetCurrentStatsDamage(this: gameLocal, tag: v23, delayedCount: &v191);
  }
  projDef = fp->projDef;
  v186 = nullptr;
  v194 = nullptr;
  tracerMtr = projDef->tracerInfo.tracerMtr;
  v193 = tracerMtr;
  if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) != nullptr )
  {
    v27 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
    PlayerDriver = v27->GetPlayerInterface_2(this: v27);
    v186 = PlayerDriver;
    v29 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
    v30 = v29->GetVehicleInterface(this: v29);
    v31 = v30;
    v194 = v30;
    if ( PlayerDriver != nullptr )
      goto LABEL_16;
    if ( v30 == nullptr )
      goto LABEL_21;
    PlayerDriver = idPresentableVehicle::GetPlayerDriver(this: v30);
    v186 = PlayerDriver;
    if ( PlayerDriver != nullptr )
    {
LABEL_16:
      if ( (*((_BYTE *)PlayerDriver + 47032) & 2) != 0 )
        goto LABEL_19;
    }
    if ( v31 != nullptr && v31->hasQuad )
    {
LABEL_19:
      if ( fp->projDef->tracerInfo.tracerMtrQuad != nullptr )
      {
        tracerMtr = fp->projDef->tracerInfo.tracerMtrQuad;
        v193 = tracerMtr;
      }
    }
  }
LABEL_21:
  v183 = false;
  if ( idFireParms::GetWeapon(this: fp) == nullptr
    || fp->projDef->tracerInfo.tracers == 0
    || (v32 = 1, tracerMtr == nullptr) )
  {
    v32 = 0;
  }
  if ( v32 != 0 )
  {
    if ( (*((_BYTE *)fp + 128) & 8) != 0 )
    {
      v183 = true;
    }
    else
    {
      v33 = fp->projDef;
      if ( v33->tracerInfo.doRandomTracers )
      {
        v34 = idRandom2::RandomInt(this: &v4->random, max: v33->tracerInfo.tracers);
      }
      else
      {
        tracerCount = idFireParms::GetWeapon(this: fp)->tracerCount;
        tracers = fp->projDef->tracerInfo.tracers;
        __twllei(tracers, 0);
        v34 = tracerCount % tracers;
        __twlgei(tracers & ~(__ROL4__(tracerCount, 1) - 1), 0xFFFFFFFF);
      }
      v183 = (_cntlzw(v34) & 0x20) != 0;
    }
  }
  damageDecl = fp->projDef->damageDecl;
  if ( damageDecl == nullptr )
  {
    if ( common->IsServer(this: common) )
    {
      idGameLocal::ClearCurrentStatsDamage(this: gameLocal);
      idGameLocal::WeaponFiredDone(this: gameLocal, tag: v23, carryoverCount: v191);
    }
    idLib::Warning(fmt: "Projectile '%s' has no damage def.", fp->projDef->name.str);
    idPLogScope::~idPLogScope(this: &v199);
    RD_EventEnd();
    return 0;
  }
  v38 = &g_debugWeapon;
  v39 = 0;
  v187 = &g_debugWeapon;
  if ( g_debugWeapon.valueInteger != 0 )
  {
    renderWorld = v4->renderWorld;
    x = fp->fireAxis.mat[0].x;
    v42 = fp->start.z;
    v43 = fp->start.y;
    v44 = (float)(fp->fireAxis.mat[0].z * (float)1024.0);
    v45 = fp->start.x;
    v46 = (float)(fp->fireAxis.mat[0].y * (float)1024.0);
    v225[0] = 0.0;
    v225[1] = 1.0;
    v225[2] = 0.0;
    v225[3] = 1.0;
    v188[0] = &fp->fireAxis;
    v204[2] = (float)v42 + (float)v44;
    v204[1] = (float)v43 + (float)v46;
    v204[0] = (float)((float)x * (float)1024.0) + (float)v45;
    renderWorld->DebugLine(
      this: renderWorld,
      a2: (const idVec4 *)v225,
      a3: &fp->start,
      a4: (const idVec3 *)v204,
      a5: 3500,
      a6: true);
  }
  v233.num = 0;
  v233.granularity = 1;
  v233.size = 16;
  v233.list = (idVec3 *)&v234;
  v233.memTag = 5;
  v233.listStatic = 1;
  numTraces = v6->numTraces;
  v48 = 0;
  v190 = 0;
  if ( numTraces > 0 )
  {
    v188[0] = &s_tracerDistance;
    v195 = COERCE_FLOAT(&vec3_origin);
    v202 = &clientGame_impactDist;
    v201 = "Temp bandaid for no surftype on dead ai.  skipping effect\n";
    v200 = &g_debugImpactEffect;
    v196 = "weapon %s projectile %s, damageScale %f \n";
    while ( 1 )
    {
      v49 = (char *)v6 + 128 * v48;
      v50 = (const trace_t *)(v49 + 4);
      if ( (*((_DWORD *)v49 + 24) & 1) != 0 )
        goto LABEL_157;
      if ( v50->fraction < 1.0 )
        break;
      v113 = *((float *)v49 + 3);
      valueInteger = v38->valueInteger;
      v115 = (float)(v50->endpos.y - fp->start.y);
      v116 = v50->endpos.x;
      p_start = &fp->start;
      v117 = (float)(v50->endpos.x - fp->start.x);
      v118 = v50->endpos.z;
      v119 = (float)(v50->endpos.z - fp->start.z);
      v184.y = v50->endpos.y;
      v184.x = v116;
      v184.z = v118;
      _FP1 = (float)((float)((float)((float)v119 * (float)v119)
                           + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      __asm { fsel      f8, f1, f2, f6 }
      v122 = __frsqrte(_FP8);
      v123 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v122
                                                                                           * (float)((float)((float)((float)v119 * (float)v119) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115))) * (float)0.5))
                                                                                   * (float)v122)
                                                                           - (float)1.5)
                                                           * (float)v122)
                                                   * (float)((float)((float)((float)v119 * (float)v119)
                                                                   + (float)((float)((float)v117 * (float)v117)
                                                                           + (float)((float)v115 * (float)v115)))
                                                           * (float)0.5))
                                           * (float)((float)-(float)((float)((float)((float)v122
                                                                                   * (float)((float)((float)((float)v119 * (float)v119) + (float)((float)((float)v117 * (float)v117) + (float)((float)v115 * (float)v115)))
                                                                                           * (float)0.5))
                                                                           * (float)v122)
                                                                   - (float)1.5)
                                                   * (float)v122))
                                   - (float)1.5)
                   * (float)((float)-(float)((float)((float)((float)v122
                                                           * (float)((float)((float)((float)v119 * (float)v119)
                                                                           + (float)((float)((float)v117 * (float)v117)
                                                                                   + (float)((float)v115 * (float)v115)))
                                                                   * (float)0.5))
                                                   * (float)v122)
                                           - (float)1.5)
                           * (float)v122));
      v189.y = (float)v115
             * (float)((float)-(float)((float)((float)((float)v123
                                                     * (float)((float)((float)((float)v119 * (float)v119)
                                                                     + (float)((float)((float)v117 * (float)v117)
                                                                             + (float)((float)v115 * (float)v115)))
                                                             * (float)0.5))
                                             * (float)v123)
                                     - (float)1.5)
                     * (float)v123);
      v189.x = (float)v117
             * (float)((float)-(float)((float)((float)((float)v123
                                                     * (float)((float)((float)((float)v119 * (float)v119)
                                                                     + (float)((float)((float)v117 * (float)v117)
                                                                             + (float)((float)v115 * (float)v115)))
                                                             * (float)0.5))
                                             * (float)v123)
                                     - (float)1.5)
                     * (float)v123);
      v189.z = (float)v119
             * (float)((float)-(float)((float)((float)((float)v123
                                                     * (float)((float)((float)((float)v119 * (float)v119)
                                                                     + (float)((float)((float)v117 * (float)v117)
                                                                             + (float)((float)v115 * (float)v115)))
                                                             * (float)0.5))
                                             * (float)v123)
                                     - (float)1.5)
                     * (float)v123);
      if ( valueInteger != 0 )
      {
        v211[1] = v113;
        v211[2] = v118;
        v224[3] = 1.0;
        v124 = v4->renderWorld;
        v211[0] = (float)v116 + (float)4.0;
        v213[0] = (float)v116 - (float)4.0;
        v213[1] = v113;
        v213[2] = v118;
        v224[0] = 0.0;
        v224[1] = 0.0;
        v224[2] = 1.0;
        v124->DebugLine(
          this: v124,
          a2: (const idVec4 *)v224,
          a3: (const idVec3 *)v213,
          a4: (const idVec3 *)v211,
          a5: 3500,
          a6: true);
        v125 = v4->renderWorld;
        v226[0] = 0.0;
        v226[3] = 1.0;
        v207[2] = v184.z;
        v215[1] = v184.y + (float)4.0;
        v207[1] = v184.y - (float)4.0;
        v226[1] = 0.0;
        v226[2] = 1.0;
        v215[0] = v184.x;
        v215[2] = v184.z;
        v207[0] = v184.x;
        v125->DebugLine(
          this: v125,
          a2: (const idVec4 *)v226,
          a3: (const idVec3 *)v207,
          a4: (const idVec3 *)v215,
          a5: 3500,
          a6: true);
        v126 = v4->renderWorld;
        v228[0] = 0.0;
        v228[2] = 1.0;
        v228[1] = 0.0;
        v228[3] = 1.0;
        v205[0] = v184.x;
        v205[1] = v184.y;
        v206[0] = v184.x;
        v206[1] = v184.y;
        v205[2] = v184.z + (float)4.0;
        v206[2] = v184.z - (float)4.0;
        v126->DebugLine(
          this: v126,
          a2: (const idVec4 *)v228,
          a3: (const idVec3 *)v206,
          a4: (const idVec3 *)v205,
          a5: 3500,
          a6: true);
        v220[0] = 1.0;
        v220[1] = 1.0;
        v112 = v220;
        v220[3] = 1.0;
        v220[2] = 0.0;
        goto LABEL_127;
      }
LABEL_128:
      if ( v183 )
      {
        sndTracer = fp->projDef->tracerInfo.sndTracer;
        if ( sndTracer != nullptr && (*((_BYTE *)fp + 128) & 0x10) == 0 )
        {
          LocalPlayer = idGameLocal::GetLocalPlayer(this: gameLocal);
          if ( LocalPlayer != nullptr )
          {
            presentable = LocalPlayer->presentable;
            if ( presentable != nullptr )
            {
              v130 = (int)presentable->GetPlayerInterface_2(this: presentable);
              idView::GetViewPos(this: (idView *)(v130 + 16224), origin: &v198, axis: &v229);
            }
            else
            {
              idView::GetViewPos(this: (idView *)0x3F60, origin: &v198, axis: &v229);
            }
          }
          else
          {
            v131 = *(float *)LODWORD(v195);
            v132 = *(float *)(LODWORD(v195) + 4);
            v133 = *(float *)(LODWORD(v195) + 8);
            v229.mat[0].x = mat3_identity.mat[0].x;
            v229.mat[0].y = mat3_identity.mat[0].y;
            v229.mat[0].z = mat3_identity.mat[0].z;
            v229.mat[1].x = mat3_identity.mat[1].x;
            v229.mat[1].y = mat3_identity.mat[1].y;
            v229.mat[1].z = mat3_identity.mat[1].z;
            v229.mat[2].x = mat3_identity.mat[2].x;
            v229.mat[2].y = mat3_identity.mat[2].y;
            v229.mat[2].z = mat3_identity.mat[2].z;
            v198.x = v131;
            v198.y = v132;
            v198.z = v133;
          }
          idGeometry::ClosestPointOnLineSegment(point: &v198, start: p_start, end: &v184, closest: &v203);
          if ( (float)((float)((float)(v198.z - v203.z) * (float)(v198.z - v203.z))
                     + (float)((float)((float)(v198.x - v203.x) * (float)(v198.x - v203.x))
                             + (float)((float)(v198.y - v203.y) * (float)(v198.y - v203.y)))) < 262144.0
            && (float)((float)((float)(v184.z - v203.z) * (float)(v184.z - v203.z))
                     + (float)((float)((float)(v184.x - v203.x) * (float)(v184.x - v203.x))
                             + (float)((float)(v184.y - v203.y) * (float)(v184.y - v203.y)))) > (double)(float)(*(float *)(v188[0] + 36) * *(float *)(v188[0] + 36)) )
          {
            *(float *)&v232.forSale = -v189.x;
            *(float *)&v232.counttosave = -v189.z;
            *(float *)&v232.quickSlot = -v189.y;
            idVec3::NormalizeFast(this: (idVec3 *)&v232.forSale);
            idVec3::NormalVectors(
              this: (idVec3 *)&v232.forSale,
              left: (idVec3 *)&v232.listeningToList,
              down: (idVec3 *)&v232.coolDownTime);
            idClientGame::PlayShaderDirectly(
              this: v4,
              shader: sndTracer,
              channel: SND_CHANNEL_BODY,
              pos: &v203,
              axis: (const idMat3 *)&v232.listeningToList,
              peerMask: 0);
          }
        }
        v134 = fp->attacker.spawnId;
        index = 0;
        v136 = fp->attacker.spawnId & 0x3FFF;
        if ( fp->attacker.spawnId != 0
          && v136 < clientGame->presentables.num
          && clientGame->presentables.list[v136] != nullptr )
        {
          list = clientGame->presentables.list;
          if ( list[v136]->spawnId == v134 )
          {
            v139 = v136 < clientGame->presentables.num && list[v136] != nullptr;
            if ( !v139 || (v140 = list[v136])->spawnId != v134 )
              v140 = nullptr;
            if ( v140->GetPlayerInterface_2(this: v140) != nullptr )
            {
              v141 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
              index = v141->GetPlayerInterface_2(this: v141)->index;
            }
          }
        }
        if ( idFireParms::GetWeapon(this: fp) != nullptr )
        {
          v144 = (float)(fp->muzzleOffset.z + p_start->z);
          v145 = (float)(fp->muzzleOffset.y + p_start->y);
          v219.x = fp->muzzleOffset.x + p_start->x;
          v219.z = v144;
          v219.y = v145;
          Weapon = idFireParms::GetWeapon(this: fp);
          idTracerManager::AddTracer(
            this: &Weapon->tracerManager,
            mat: v193,
            origin: &v219,
            dir: &v189,
            maxDist: &v184,
            speed: fp->projDef->tracerInfo.tracerSpeed,
            length: fp->projDef->tracerInfo.tracerLength,
            height: fp->projDef->tracerInfo.tracerHeight,
            ensureVisual: v148,
            fractionInsured: 0.050000001,
            playerIndex: v147,
            a12: (int)fp->projDef,
            a13: v161,
            a14: v162,
            a15: v163,
            a16: v164,
            a17: v165,
            a18: v166,
            a19: v167,
            a20: v168,
            a21: SHIDWORD(v169),
            a22: SLODWORD(v169),
            a23: v170,
            a24: v171,
            a25: v172,
            a26: v173,
            a27: v174,
            a28: v175,
            a29: v176,
            a30: v177,
            a31: v178,
            a32: true,
            a33: v179,
            a34: v180,
            a35: v181,
            a36: index);
        }
        else
        {
          v149 = fp->projDef;
          v150 = (float)(fp->muzzleOffset.y + p_start->y);
          v151 = (float)(fp->muzzleOffset.x + p_start->x);
          v210.z = fp->muzzleOffset.z + p_start->z;
          v210.y = v150;
          v210.x = v151;
          idRenderModelEffects::AddTracer(
            this: v4->gameLibEffects.effectsModel,
            mat: v193,
            origin: &v210,
            dir: &v189,
            maxDist: &v184,
            speed: v149->tracerInfo.tracerSpeed,
            length: v149->tracerInfo.tracerLength,
            height: v149->tracerInfo.tracerHeight,
            ensureVisual: v143,
            fractionInsured: 0.050000001,
            lifeTime: -1.0,
            a12: v142,
            a13: 1,
            a14: v161,
            a15: v162,
            a16: v163,
            a17: v164,
            a18: v165,
            a19: v166,
            a20: v167,
            a21: v168,
            a22: SHIDWORD(v169),
            a23: SLODWORD(v169),
            a24: v170,
            a25: v171,
            a26: v172,
            a27: v173,
            a28: v174,
            a29: v175,
            a30: v176,
            a31: v177,
            a32: v178,
            a33: 1);
        }
      }
      v6 = tfr;
LABEL_157:
      v152 = v6->numTraces;
      v48 = v190 + 1;
      v190 = v48;
      if ( v48 >= v152 )
      {
        v23 = v192;
        v7 = ffr;
        goto LABEL_159;
      }
      v38 = v187;
    }
    v51 = *((float *)v49 + 16);
    v52 = *((_DWORD *)v49 + 28);
    v53 = (float)(v50->c.point.y - fp->start.y);
    v54 = v50->c.point.x;
    p_start = &fp->start;
    v56 = (float)(v50->c.point.x - fp->start.x);
    v57 = v50->c.point.z;
    v58 = fp->start.z;
    v59 = (float)(v50->c.point.z - fp->start.z);
    v184.y = v50->c.point.y;
    v184.x = v54;
    v184.z = v57;
    _FP1 = (float)((float)((float)((float)((float)v57 - (float)v58) * (float)((float)v57 - (float)v58))
                         + (float)((float)((float)v56 * (float)v56) + (float)((float)v53 * (float)v53)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v61 = (float)((float)((float)((float)((float)v57 - (float)v58) * (float)((float)v57 - (float)v58))
                        + (float)((float)((float)v56 * (float)v56) + (float)((float)v53 * (float)v53)))
                * (float)0.5);
    __asm { fsel      f8, f1, f2, f6 }
    v63 = __frsqrte(_FP8);
    v64 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v63 * (float)v61)
                                                                                * (float)v63)
                                                                        - (float)1.5)
                                                        * (float)v63)
                                                * (float)v61)
                                        * (float)((float)-(float)((float)((float)((float)v63 * (float)v61) * (float)v63)
                                                                - (float)1.5)
                                                * (float)v63))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v63 * (float)v61) * (float)v63) - (float)1.5)
                        * (float)v63));
    v189.y = (float)((float)-(float)((float)((float)((float)v64 * (float)v61) * (float)v64) - (float)1.5) * (float)v64)
           * (float)v53;
    v189.x = (float)((float)-(float)((float)((float)((float)v64 * (float)v61) * (float)v64) - (float)1.5) * (float)v64)
           * (float)v56;
    v189.z = (float)((float)-(float)((float)((float)((float)v64 * (float)v61) * (float)v64) - (float)1.5) * (float)v64)
           * (float)v59;
    if ( v52 < 0 )
    {
LABEL_123:
      v39 = 1;
      if ( v187->valueInteger != 0 )
      {
        v218[0] = (float)v54 - (float)4.0;
        v218[2] = v57;
        v218[1] = v51;
        v109 = v4->renderWorld;
        v223[2] = 0.0;
        v223[0] = 1.0;
        v223[1] = 0.0;
        v217[0] = (float)v54 + (float)4.0;
        v217[1] = v51;
        v217[2] = v57;
        v223[3] = 1.0;
        v109->DebugLine(
          this: v109,
          a2: (const idVec4 *)v223,
          a3: (const idVec3 *)v218,
          a4: (const idVec3 *)v217,
          a5: 3500,
          a6: true);
        v110 = v4->renderWorld;
        v227[0] = 1.0;
        v227[1] = 0.0;
        v227[2] = 0.0;
        v227[3] = 1.0;
        v212[0] = v184.x;
        v212[2] = v184.z;
        v216[0] = v184.x;
        v216[2] = v184.z;
        v212[1] = v184.y + (float)4.0;
        v216[1] = v184.y - (float)4.0;
        v110->DebugLine(
          this: v110,
          a2: (const idVec4 *)v227,
          a3: (const idVec3 *)v216,
          a4: (const idVec3 *)v212,
          a5: 3500,
          a6: true);
        v221[0] = 1.0;
        v111 = v4->renderWorld;
        v221[1] = 0.0;
        v221[2] = 0.0;
        v221[3] = 1.0;
        v214[0] = v184.x;
        v214[1] = v184.y;
        v209[0] = v184.x;
        v209[1] = v184.y;
        v214[2] = v184.z + (float)4.0;
        v209[2] = v184.z - (float)4.0;
        v111->DebugLine(
          this: v111,
          a2: (const idVec4 *)v221,
          a3: (const idVec3 *)v209,
          a4: (const idVec3 *)v214,
          a5: 3500,
          a6: true);
        v222[0] = 1.0;
        v222[2] = 0.0;
        v112 = v222;
        v222[1] = 1.0;
        v222[3] = 1.0;
LABEL_127:
        v4->renderWorld->DebugLine(
          this: v4->renderWorld,
          a2: (const idVec4 *)v112,
          a3: p_start,
          a4: &v184,
          a5: 3500,
          a6: true);
        goto LABEL_128;
      }
      goto LABEL_128;
    }
    v65 = 0.0;
    v66 = nullptr;
    PresentableByEntityNum = nullptr;
    if ( common->IsServer(this: common) )
    {
      v66 = (idAI2 *)gameLocal->entities.ptr[v50->c.entityNum];
      if ( v66 == nullptr )
        goto LABEL_50;
      PresentableByEntityNum = v66->presentable;
    }
    else
    {
      PresentableByEntityNum = idClientGame::GetPresentableByEntityNum(this: v4, entityNum: v50->c.entityNum);
    }
    if ( PresentableByEntityNum != nullptr )
    {
      v68 = (int)PresentableByEntityNum->GetAIInterface(this: PresentableByEntityNum);
      goto LABEL_51;
    }
LABEL_50:
    v68 = 0;
LABEL_51:
    v69 = 0;
    if ( v66 == nullptr )
      goto _M507286;
    RD_EventBegin(name: "idGameLocal::FinishHitScan - damage entity");
    LODWORD(v70) = "idGameLocal::FinishHitScan - damage entity";
    HIDWORD(v70) = 2;
    idPLogScope::idPLogScope(this: &v231, pl: v197, gMask: v70, label: v71);
    v72 = idAI2::CastTo(c: v66);
    v73 = idDamageableEntity::CastTo(c: (idDamageableEntity *)v66);
    v74 = idProp_Breakable::CastTo(c: (idProp_Breakable *)v66);
    v75 = idWaterEntity::CastTo(c: (idWaterEntity *)v66);
    damageScale = fp->damageScale;
    v77 = v75;
    if ( damageScale < 1.0 && v187->valueInteger != 0 )
    {
      str = fp->projDef->name.str;
      v79 = (idStrId *)idFireParms::GetWeapon(this: fp);
      DisplayName = idInventoryItem::GetDisplayName(this: &v232, result: v79);
      LocalizedString = idStrId::GetLocalizedString(this: DisplayName);
      v169 = damageScale;
      idLib::Printf(fmt: v196, LocalizedString, str, LODWORD(damageScale), damageScale);
      v4 = this;
    }
    v82 = 0.0;
    if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) != nullptr )
    {
      Physics = idEntity::GetPhysics(this: v66);
      v182 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v84 = (const idVec3 *)idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
      v4 = this;
      v82 = idClientGame::CalcHitscanDamageScale(
              this,
              projDef: fp->projDef,
              startDamageScale: fp->damageScale,
              attacker: v86,
              hitOrigin: v84,
              a6: v182,
              a7: v85);
    }
    if ( v187->valueInteger != 0 && idFireParms::GetWeapon(this: fp) != nullptr )
    {
      v87 = fp->projDef->name.str;
      v88 = (idStrId *)idFireParms::GetWeapon(this: fp);
      v89 = idInventoryItem::GetDisplayName(this: (idInventoryItem *)&v232.listenerList, result: v88);
      v90 = idStrId::GetLocalizedString(this: v89);
      v169 = v82;
      idLib::Printf(fmt: v196, v90, v87, LODWORD(v82), v82);
      v4 = this;
    }
    if ( (*((_BYTE *)fp + 129) & 0x80) == 0
      || v72 != nullptr && v72->IsDead(this: v72)
      || v73 != nullptr
      || v74 != nullptr )
    {
      if ( idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker) != nullptr )
      {
        RD_EventBegin(name: "idGameLocal::FinishHitScan - hitEntity->Damage");
        LODWORD(v94) = "idGameLocal::FinishHitScan - hitEntity->Damage";
        HIDWORD(v94) = 2;
        idPLogScope::idPLogScope(this: &v230, pl: v197, gMask: v94, label: v95);
        v96 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
        v91 = damageDecl;
        v65 = ((double (__fastcall *)(idAI2 *, _DWORD, idEntity *, const idDeclDamage *, double))v66->Damage)(
                a1: v66,
                a2: 0,
                a3: v96->entity,
                a4: damageDecl,
                a5: v82);
        idPLogScope::~idPLogScope(this: &v230);
        RD_EventEnd();
LABEL_67:
        if ( v72 != nullptr && v50->c.surfaceType == 0 && v65 >= 0.0 )
        {
          v69 = 1;
          if ( v200->valueInteger != 0 )
            idLib::Printf(fmt: v201);
        }
        if ( v77 != nullptr && (v91->damageTypes & 0x400) == 0x400 )
        {
          v92 = fp->projDef;
          if ( v92 != nullptr && (electricDamageDecl = v92->electricDamageDecl) != nullptr )
            v77->damageDecl = electricDamageDecl;
          else
            v77->damageDecl = v91;
        }
        idPLogScope::~idPLogScope(this: &v231);
        RD_EventEnd();
_M507286:
        v97 = false;
        v98 = v190 - 1;
        if ( v190 - 1 >= 0 )
        {
          p_surfaceType = &tfr->traces[v98].c.surfaceType;
          while ( *p_surfaceType != v50->c.surfaceType )
          {
            --v98;
            p_surfaceType -= 32;
            if ( v98 < 0 )
              goto LABEL_87;
          }
          v97 = true;
        }
LABEL_87:
        if ( v69 == 0 && (v68 == 0 || v65 != 0.0 || common->IsClient(this: common)) )
        {
          v235 = *v50;
          v100 = false;
          if ( v233.num > 0 )
          {
            num = v233.num;
            v102 = &v233.list->y;
            do
            {
              if ( (float)((float)((float)(v235.endpos.z - v102[1]) * (float)(v235.endpos.z - v102[1]))
                         + (float)((float)((float)(v235.endpos.x - *(v102 - 1)) * (float)(v235.endpos.x - *(v102 - 1)))
                                 + (float)((float)(v235.endpos.y - *v102) * (float)(v235.endpos.y - *v102)))) < (double)(float)(v202->valueFloat * v202->valueFloat) )
                v100 = true;
              v102 += 3;
              --num;
            }
            while ( num != 0 );
          }
          if ( !v100 )
            idList<idAngles,5>::Append(this: &v233, obj: &v235.endpos);
          v103 = fp->attacker.spawnId & 0x3FFF;
          if ( fp->attacker.spawnId == 0
            || (v103 >= clientGame->presentables.num
              ? (v104 = false)
              : (v104 = clientGame->presentables.list[v103] != nullptr),
                !v104 || (v105 = clientGame->presentables.list[v103])->spawnId != fp->attacker.spawnId) )
          {
            v105 = nullptr;
          }
          idClientGame::ProjectileImpact(
            this: v4,
            trace: &v235,
            attacker: v105,
            projDef: fp->projDef,
            tracerFired: v100,
            noDecals: *((_BYTE *)fp + 128) & 1 | (v68 != 0),
            noSounds: v97);
          if ( fp->projDef->delayedProjectile != nullptr )
            idGameLocal::AddDelayedProjectile(
              this: gameLocal,
              fp,
              trace: v50,
              forceSkipDecal: v68 != 0,
              forceSkipSound: v97);
          if ( !common->IsMultiplayer(this: common) )
          {
            v106 = v186;
LABEL_114:
            idGameLocal::WeaponFiredResult(this: gameLocal, tag: v192, target: v66, damage: v65);
            goto LABEL_116;
          }
          if ( common->IsServer(this: common) )
          {
            v106 = v186;
            if ( v186 != nullptr && v194 == nullptr && !v186->IsLocallyControlled(this: v186) )
              goto LABEL_116;
            goto LABEL_114;
          }
        }
        v106 = v186;
LABEL_116:
        if ( common->IsClient(this: common) )
        {
          maxDamage = damageDecl->maxDamage;
          if ( PresentableByEntityNum != nullptr )
          {
            v108 = idPresentablePtr<idPresentableProjectile>::operator->(this: &fp->attacker);
            ((void (__fastcall *)(idPresentable *, idPresentable *, double))PresentableByEntityNum->PredictHitScanHit)(
              a1: PresentableByEntityNum,
              a2: v108,
              a3: maxDamage);
            if ( v106 != nullptr
              && (PresentableByEntityNum->GetActorInterface_2(this: PresentableByEntityNum) != nullptr
               || PresentableByEntityNum->GetVehicleInterface(this: PresentableByEntityNum) != nullptr) )
            {
              idPresentablePlayer::DamageDealtFeedback(this: v106, victim: PresentableByEntityNum, predicted: true);
            }
          }
        }
        v54 = v184.x;
        v51 = v184.y;
        v57 = v184.z;
        goto LABEL_123;
      }
    }
    else
    {
      v65 = damageDecl->maxDamage;
    }
    v91 = damageDecl;
    goto LABEL_67;
  }
LABEL_159:
  if ( common->IsServer(this: common) )
  {
    v153 = 16;
    projectiles = v7->projectiles;
    v155 = (char *)((char *)&gameLocal->lastFinishFireResult - (char *)v7);
    gameLocal->lastFinishFireResult.numProjectiles = v7->numProjectiles;
    do
    {
      *(idPresentablePtr<idPresentableProjectile> *)((char *)projectiles + (_DWORD)v155) = (idPresentablePtr<idPresentableProjectile>)projectiles->spawnId;
      ++projectiles;
      --v153;
    }
    while ( v153 != 0 );
    idTestFireResults::operator=(this: &gameLocal->lastTestFireResult, __that: v6);
    idGameLocal::ClearCurrentStatsDamage(this: gameLocal);
    idGameLocal::WeaponFiredDone(this: gameLocal, tag: v23, carryoverCount: v191);
  }
  if ( v233.listStatic == 0 || v233.listStatic == 2 )
  {
    if ( v233.list != nullptr )
      idMem::Free(this: &mem, ptr: v233.list, align: ALIGN_16);
    v233.list = nullptr;
    v233.size = 0;
  }
  v233.num = 0;
  if ( v199.logIndex >= 0 )
  {
    pLog = v199.pLog;
    v157 = &v199.pLog->logEntries.list[v199.logIndex];
    v158 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v157->totalTicks;
    HIDWORD(totalTicks) = v157->parent;
    LODWORD(v160) = v158 - totalTicks;
    v157->totalTicks = v160;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  return v39;
}


// ========================================================================
// __unwind$505937
// EA  : 0x82B585BC
// RVA : 0x00B585BC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505937()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1344 + 1104));
}


// ========================================================================
// __unwind$505938
// EA  : 0x82B585E4
// RVA : 0x00B585E4
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505938()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1344 + 216));
}


// ========================================================================
// __unwind$505939_0
// EA  : 0x82B5860C
// RVA : 0x00B5860C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505939_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 1344 + 768));
}


// ========================================================================
// __unwind$505940
// EA  : 0x82B58634
// RVA : 0x00B58634
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505940()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1344 + 1105));
}


// ========================================================================
// __unwind$505941
// EA  : 0x82B5865C
// RVA : 0x00B5865C
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505941()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1344 + 704));
}


// ========================================================================
// __unwind$505942
// EA  : 0x82B58684
// RVA : 0x00B58684
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505942()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 1344 + 1106));
}


// ========================================================================
// __unwind$505943
// EA  : 0x82B586AC
// RVA : 0x00B586AC
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void _unwind_505943()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 1344 + 696));
}


// ========================================================================
// ?FinishFire@idClientGame@@QAA_NABVidFireParms@@AAVidTestFireResults@@AAVidFinishFireResults@@@Z
// EA  : 0x82B586D8
// RVA : 0x00B586D8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

int __fastcall idClientGame::FinishFire(
        idClientGame *this,
        const idFireParms *fp,
        idTestFireResults *tfr,
        idFinishFireResults *ffr)
{
  if ( fp->projDef->hitscan )
    return idClientGame::FinishHitScan(this, fp, tfr, ffr);
  else
    return idClientGame::FinishLaunchProjectile(this, fp, tfr, ffr);
}


// ========================================================================
// `dynamic initializer for 'cg_predictProjectiles''
// EA  : 0x8336CFE0
// RVA : 0x0136CFE0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_predictProjectiles__()
{
  idCVar::idCVar(
    this: &cg_predictProjectiles,
    name: "cg_predictProjectiles",
    value: "1",
    flags: 1,
    description: "Predict projectile spawning on clients",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_predictProjectiles__);
}


// ========================================================================
// `dynamic initializer for 'cg_predictProjectileExpire''
// EA  : 0x8336D038
// RVA : 0x0136D038
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_predictProjectileExpire__()
{
  idCVar::idCVar(
    this: &cg_predictProjectileExpire,
    name: "cg_predictProjectileExpire",
    value: "2",
    flags: 2,
    description: "Time in seconds until client predicted presentable will expire if the server version has not arrived yet.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_predictProjectileExpire__);
}


// ========================================================================
// `dynamic initializer for 'cg_projectile_clientAuthoritative''
// EA  : 0x8336D090
// RVA : 0x0136D090
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_projectile_clientAuthoritative__()
{
  idCVar::idCVar(
    this: &cg_projectile_clientAuthoritative,
    name: "cg_projectile_clientAuthoritative",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_projectile_clientAuthoritative__);
}


// ========================================================================
// `dynamic initializer for 'cg_optimizeSnapSerialize''
// EA  : 0x8336D0E8
// RVA : 0x0136D0E8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_optimizeSnapSerialize__()
{
  idCVar::idCVar(
    this: &cg_optimizeSnapSerialize,
    name: "cg_optimizeSnapSerialize",
    value: "1",
    flags: 1,
    description: "Turn on snapshot serialize and various optimizations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_optimizeSnapSerialize__);
}


// ========================================================================
// `dynamic initializer for 'cg_optimizeSnapSerialize_debug''
// EA  : 0x8336D140
// RVA : 0x0136D140
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_optimizeSnapSerialize_debug__()
{
  idCVar::idCVar(
    this: &cg_optimizeSnapSerialize_debug,
    name: "cg_optimizeSnapSerialize_debug",
    value: "0",
    flags: 1,
    description: "Turn on snapshot serialize and various optimizations",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_optimizeSnapSerialize_debug__);
}


// ========================================================================
// `dynamic initializer for 'cg_showSnapSerializePerformance''
// EA  : 0x8336D198
// RVA : 0x0136D198
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_showSnapSerializePerformance__()
{
  idCVar::idCVar(
    this: &cg_showSnapSerializePerformance,
    name: "cg_showSnapSerializePerformance",
    value: "0",
    flags: 1,
    description: "Print snapshot serialize timings",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_showSnapSerializePerformance__);
}


// ========================================================================
// `dynamic initializer for 'cg_projectile_clientAuthoritative_maxCatchup''
// EA  : 0x8336D1F0
// RVA : 0x0136D1F0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_projectile_clientAuthoritative_maxCatchup__()
{
  idCVar::idCVar(
    this: &cg_projectile_clientAuthoritative_maxCatchup,
    name: "cg_projectile_clientAuthoritative_maxCatchup",
    value: "500",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_projectile_clientAuthoritative_maxCatchup__);
}


// ========================================================================
// `dynamic initializer for 'cg_predictedSpawn_disable''
// EA  : 0x8336D248
// RVA : 0x0136D248
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_predictedSpawn_disable__()
{
  idCVar::idCVar(
    this: &cg_predictedSpawn_disable,
    name: "cg_predictedSpawn_disable",
    value: "0",
    flags: 1,
    description: "If true we will not reconcile predictive presentables with their serialized counter parts. In most cases this will r"
    "esult in there being 2 presentables: a local and serialized one.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_predictedSpawn_disable__);
}


// ========================================================================
// `dynamic initializer for 'cg_predictedSpawn_debug''
// EA  : 0x8336D2A0
// RVA : 0x0136D2A0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_predictedSpawn_debug__()
{
  idCVar::idCVar(
    this: &cg_predictedSpawn_debug,
    name: "cg_predictedSpawn_debug",
    value: "0",
    flags: 1,
    description: "Debug predictive spawning of presentables",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_predictedSpawn_debug__);
}


// ========================================================================
// `dynamic initializer for 'net_replicateSounds''
// EA  : 0x8336D2F8
// RVA : 0x0136D2F8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_replicateSounds__()
{
  idCVar::idCVar(
    this: &net_replicateSounds,
    name: "net_replicateSounds",
    value: "1",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_replicateSounds__);
}


// ========================================================================
// `dynamic initializer for 'net_visCullSnapshots''
// EA  : 0x8336D350
// RVA : 0x0136D350
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_visCullSnapshots__()
{
  idCVar::idCVar(
    this: &net_visCullSnapshots,
    name: "net_visCullSnapshots",
    value: "0",
    flags: 1,
    description: "Culls snapshots based on visiblity (currently only using screen coverage)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_visCullSnapshots__);
}


// ========================================================================
// `dynamic initializer for 'clientGame_impactDist''
// EA  : 0x8336D3A8
// RVA : 0x0136D3A8
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__clientGame_impactDist__()
{
  idCVar::idCVar(
    this: &clientGame_impactDist,
    name: "clientGame_ImpactDist",
    value: "16",
    flags: 4,
    description: "the distance that must be in between impact effects",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__clientGame_impactDist__);
}


// ========================================================================
// `dynamic initializer for 'mp_cg_soundDebug''
// EA  : 0x8336D400
// RVA : 0x0136D400
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_cg_soundDebug__()
{
  idCVar::idCVar(
    this: &mp_cg_soundDebug,
    name: "mp_cg_soundDebug",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_cg_soundDebug__);
}


// ========================================================================
// `dynamic initializer for 'cg_showPresentableInfo''
// EA  : 0x8336D458
// RVA : 0x0136D458
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__cg_showPresentableInfo__()
{
  idCVar::idCVar(
    this: &cg_showPresentableInfo,
    name: "cg_showPresentableInfo",
    value: "0",
    flags: 1,
    description: "If true, shows info of nearby presentables.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__cg_showPresentableInfo__);
}


// ========================================================================
// `dynamic initializer for 's_snapTrace''
// EA  : 0x8336D4B0
// RVA : 0x0136D4B0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_snapTrace__()
{
  idCVar::idCVar(
    this: &s_snapTrace,
    name: "s_snapTrace",
    value: "0",
    flags: 1,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_snapTrace__);
}


// ========================================================================
// `dynamic initializer for 's_tracerDistance''
// EA  : 0x8336D508
// RVA : 0x0136D508
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__s_tracerDistance__()
{
  idCVar::idCVar(
    this: &s_tracerDistance,
    name: "s_tracerDistance",
    value: "128",
    flags: 4,
    description: "The minimum distance a bullet has to go past the player for a tracer to be played",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__s_tracerDistance__);
}


// ========================================================================
// `dynamic initializer for 'SendGameEventReliable_v''
// EA  : 0x8336D560
// RVA : 0x0136D560
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__SendGameEventReliable_v__()
{
  return idCommandLink::idCommandLink(
           this: &SendGameEventReliable_v,
           cmdName: "SendGameEventReliable",
           function: SendGameEventReliable_f,
           description: "Sends reliable events. arg1 = event. arg2 = playernum. See onlineGameEvent_t for enum val",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'g_useImpactColor''
// EA  : 0x8336D588
// RVA : 0x0136D588
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_useImpactColor__()
{
  idCVar::idCVar(
    this: &g_useImpactColor,
    name: "g_useImpactColor",
    value: "0",
    flags: 1,
    description: "if true, pass through the trace point surface color for an impact to the impact particle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_useImpactColor__);
}


// ========================================================================
// `dynamic initializer for 'messagemode_v''
// EA  : 0x8336D5E0
// RVA : 0x0136D5E0
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__messagemode_v__()
{
  return idCommandLink::idCommandLink(
           this: &messagemode_v,
           cmdName: "messagemode",
           function: messagemode_f,
           description: "activate text entry in the hud",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'messagemode2_v''
// EA  : 0x8336D608
// RVA : 0x0136D608
// PDB : w:\tech5\tungsten\game\clientgame\clientgame_local.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__messagemode2_v__()
{
  return idCommandLink::idCommandLink(
           this: &messagemode2_v,
           cmdName: "messagemode2",
           function: messagemode2_f,
           description: "activate text entry in the hud",
           argCompletion: nullptr);
}

