
// ========================================================================
// ?SetState@idLobbyController@@AAAXW4state_t@1@@Z
// EA  : 0x82D9E8F0
// RVA : 0x00D9E8F0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::SetState(idLobbyController *this, idLobbyController::state_t s)
{
  if ( (_S18_17 & 1) == 0 )
  {
    stateToString[0] = "IDLE";
    stateToString[1] = "INTERMISSION";
    stateToString[2] = "FINAL_COUNTDOWN";
    stateToString[3] = "IN_GAME";
    stateToString[4] = "NUM_STATES";
    _S18_17 |= 1u;
  }
  if ( s != this->state )
  {
    idLib::Printf(fmt: "LobbyController changing state from %s to %s\n", stateToString[this->state], stateToString[s]);
    this->state = s;
  }
}


// ========================================================================
// ?CalcNumSkipVotesRequiredToPass@idLobbyController@@QBAHXZ
// EA  : 0x82D9E9B0
// RVA : 0x00D9E9B0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

int __fastcall idLobbyController::CalcNumSkipVotesRequiredToPass(idLobbyController *this)
{
  idLobbyBase *v1; // r3

  v1 = session->GetGameLobbyBase(this: session);
  return v1->GetNumLobbyUsers(this: v1) / 2 + 1;
}


// ========================================================================
// ??0idLobbyController@@QAA@PAVidMainMenu@@@Z
// EA  : 0x82D9EA00
// RVA : 0x00D9EA00
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

idLobbyController *__fastcall idLobbyController::idLobbyController(idLobbyController *this, idMainMenu *menu)
{
  this->state = 0;
  this->intermissionCountdown.intervalMs = 0;
  this->intermissionCountdown.startMs = 0;
  this->intermissionCountdown.pauseStartMs = 0;
  this->intermissionCountdown.pauseAccumulationMs = 0;
  this->intermissionCountdown.isPaused = false;
  this->finalCountdown.intervalMs = 0;
  this->finalCountdown.startMs = 0;
  this->finalCountdown.pauseStartMs = 0;
  this->finalCountdown.pauseAccumulationMs = 0;
  this->finalCountdown.isPaused = false;
  this->nextPeerUpdateMs = 0;
  this->mainMenu = menu;
  this->serverRemainingSecUntilLaunch = 255;
  this->skipVotes = 0;
  this->skipVotesNeeded = 0;
  this->votePerPeer = 0;
  this->numPlayers = 0;
  this->skipVoteState = SKIPVOTE_NONE;
  this->didVote = false;
  return this;
}


// ========================================================================
// ?StartFinalCountdown@idLobbyController@@QAAXH@Z
// EA  : 0x82D9EA60
// RVA : 0x00D9EA60
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::StartFinalCountdown(idLobbyController *this, int overrideCountdownMS)
{
  int v3; // ctr
  bool *v4; // r10
  int *v5; // r11
  int v6; // ctr
  bool *p_isPaused; // r10
  int *v8; // r11
  int v9; // [sp+4Ch] [-34h] BYREF
  int v10; // [sp+50h] [-30h]
  unsigned int v11; // [sp+54h] [-2Ch]
  int v12; // [sp+58h] [-28h]
  int v13; // [sp+5Ch] [-24h]
  char v14; // [sp+60h] [-20h]

  if ( overrideCountdownMS < 0 )
  {
    v10 = 1000
        * session->GetTitleStorageInt_2(
            this: session,
            a2: "lobby_FinalCountdownSec",
            a3: lobby_FinalCountdownSec.valueInteger);
    v11 = Sys_Milliseconds();
    v12 = 0;
    v13 = 0;
    v6 = 5;
    v14 = 0;
    p_isPaused = &this->intermissionCountdown.isPaused;
    v8 = &v9;
    do
    {
      ++v8;
      p_isPaused += 4;
      *(_DWORD *)p_isPaused = *v8;
      --v6;
    }
    while ( v6 != 0 );
  }
  else
  {
    v10 = overrideCountdownMS;
    v11 = Sys_Milliseconds();
    v12 = 0;
    v13 = 0;
    v3 = 5;
    v14 = 0;
    v4 = &this->intermissionCountdown.isPaused;
    v5 = &v9;
    do
    {
      ++v5;
      v4 += 4;
      *(_DWORD *)v4 = *v5;
      --v3;
    }
    while ( v3 != 0 );
  }
  idLobbyController::SetState(this, s: FINAL_COUNTDOWN);
}


// ========================================================================
// ?CanLaunchGame@idLobbyController@@AAA_NXZ
// EA  : 0x82D9EB48
// RVA : 0x00D9EB48
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

BOOL __fastcall idLobbyController::CanLaunchGame(idLobbyController *this)
{
  unsigned __int8 v1; // r29
  int i; // r31
  idLocalUser *LocalUserByInputDevice; // r3
  int v4; // r3

  v1 = 0;
  for ( i = 0; i < 4; ++i )
  {
    LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(this: session->signInManager, index: i);
    if ( LocalUserByInputDevice != nullptr )
    {
      v4 = (int)LocalUserByInputDevice->GetProfile(this: LocalUserByInputDevice);
      if ( v4 != 0 && (*(_DWORD *)(v4 + 8) == 1 || *(_DWORD *)(v4 + 12) == 3) )
        v1 = 1;
    }
  }
  return (_cntlzw(v1) & 0x20) != 0;
}


// ========================================================================
// ?GetMinPlayersToStartGame@idLobbyController@@QBAHXZ
// EA  : 0x82D9EBD0
// RVA : 0x00D9EBD0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

int __fastcall idLobbyController::GetMinPlayersToStartGame(idLobbyController *this)
{
  idLobbyBase *v2; // r3
  idCVar *v3; // r9
  const char *v4; // r4

  if ( this->mainMenu->privateMatch )
    return 1;
  v2 = session->GetGameLobbyBase(this: session);
  if ( v2->GetMatchParms(this: v2)->gameType == 1 )
  {
    v3 = &lobby_MinPlayersToStartGameCoop;
    v4 = "lobby_MinPlayersToStartGameCoop";
  }
  else
  {
    v3 = &lobby_MinPlayersToStartGame;
    v4 = "lobby_MinPlayersToStartGame";
  }
  return session->GetTitleStorageInt_2(this: session, a2: v4, a3: v3->valueInteger);
}


// ========================================================================
// ?GetMinPlayersToStartCountdown@idLobbyController@@QBAHXZ
// EA  : 0x82D9EC90
// RVA : 0x00D9EC90
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

int __fastcall idLobbyController::GetMinPlayersToStartCountdown(idLobbyController *this)
{
  idLobbyBase *v2; // r3
  idCVar *v3; // r9
  const char *v4; // r4

  if ( this->mainMenu->privateMatch )
    return 1;
  v2 = session->GetGameLobbyBase(this: session);
  if ( v2->GetMatchParms(this: v2)->gameType == 1 )
  {
    v3 = &lobby_MinPlayersToStartCoundownCoop;
    v4 = "lobby_MinPlayersToStartCoundownCoop";
  }
  else
  {
    v3 = &lobby_MinPlayersToStartCoundown;
    v4 = "lobby_MinPlayersToStartCoundown";
  }
  return session->GetTitleStorageInt_2(this: session, a2: v4, a3: v3->valueInteger);
}


// ========================================================================
// ?Resume@idCountdown@idLobbyController@@QAAXXZ
// EA  : 0x82D9EDA8
// RVA : 0x00D9EDA8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::idCountdown::Resume(idLobbyController::idCountdown *this)
{
  unsigned int v2; // r3

  if ( this->isPaused )
  {
    this->isPaused = false;
    v2 = Sys_Milliseconds();
    this->pauseAccumulationMs += __CFADD__(v2 - this->pauseStartMs, 0x80000000) ? 0 : v2 - this->pauseStartMs;
  }
}


// ========================================================================
// ?SendVoteToSkip@idLobbyController@@AAAXXZ
// EA  : 0x82D9EE18
// RVA : 0x00D9EE18
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::SendVoteToSkip(idLobbyController *this)
{
  __int64 v1; // r11
  idLobbyBase *v2; // r3
  _DWORD v3[7]; // [sp+50h] [-30h] BYREF
  char v4; // [sp+6Ch] [-14h]
  char v5; // [sp+6Dh] [-13h]
  __int64 v6; // [sp+70h] [-10h]

  LODWORD(v1) = 0;
  HIDWORD(v1) = &joystick.joyAxis[0][2];
  memset(v3, 0, sizeof(v3));
  v4 = 0;
  v5 = 0;
  v6 = v1;
  v2 = session->GetGameLobbyBase(this: session);
  v2->SendReliable(this: v2, a2: 10, a3: (idBitMsg *)v3, a4: false, a5: 255u);
}


// ========================================================================
// ?RemainingMs@idCountdown@idLobbyController@@QBAHXZ
// EA  : 0x82D9EEA8
// RVA : 0x00D9EEA8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

int __fastcall idLobbyController::idCountdown::RemainingMs(idLobbyController::idCountdown *this)
{
  unsigned int pauseStartMs; // r3
  int intervalMs; // r10

  if ( this->isPaused )
    pauseStartMs = this->pauseStartMs;
  else
    pauseStartMs = Sys_Milliseconds();
  intervalMs = pauseStartMs - this->pauseAccumulationMs - this->startMs;
  if ( this->intervalMs < intervalMs )
    intervalMs = this->intervalMs;
  return __CFADD__(this->intervalMs - intervalMs, 0x80000000) ? 0 : this->intervalMs - intervalMs;
}


// ========================================================================
// ?CalcRemainingSecUntilLaunch@idLobbyController@@ABAHXZ
// EA  : 0x82D9EF28
// RVA : 0x00D9EF28
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

int __fastcall idLobbyController::CalcRemainingSecUntilLaunch(idLobbyController *this)
{
  long double v3; // fp2
  long double v4; // fp2
  idLobbyController::idCountdown *p_intermissionCountdown; // r3
  int v6; // r31
  __int64 v7; // r9
  long double v8; // fp2
  long double v9; // fp2

  if ( this->intermissionCountdown.isPaused )
    return 255;
  *(double *)&v3 = (float)((float)__SPAIR64__(
                                    &off_82040000,
                                    idLobbyController::idCountdown::RemainingMs(this: &this->finalCountdown))
                         * (float)0.001);
  v4 = ceil(x: v3);
  p_intermissionCountdown = &this->intermissionCountdown;
  v6 = (int)(float)*(double *)&v4;
  LODWORD(v7) = idLobbyController::idCountdown::RemainingMs(this: p_intermissionCountdown);
  *(double *)&v8 = (float)((float)v7 * (float)0.001);
  v9 = ceil(x: v8);
  return (int)(float)*(double *)&v9 + v6;
}


// ========================================================================
// ??0party_t@@QAA@XZ
// EA  : 0x82D9F148
// RVA : 0x00D9F148
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

party_t *__fastcall party_t::party_t(party_t *this)
{
  this->token = 0;
  this->users.num = 0;
  this->users.size = 6;
  this->users.granularity = 1;
  this->users.list = this->users.staticList;
  this->users.memTag = 5;
  this->users.listStatic = 1;
  return this;
}


// ========================================================================
// ?AddVoteToSkip@idLobbyController@@AAAXH@Z
// EA  : 0x82D9F2E8
// RVA : 0x00D9F2E8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::AddVoteToSkip(idLobbyController *this, int peer)
{
  int v3; // r29
  idSWFScriptVar v4; // [sp+58h] [-48h] BYREF
  idStr v5[2]; // [sp+60h] [-40h] BYREF

  if ( this->skipVoteState == SKIPVOTE_STARTED )
  {
    if ( peer != -1 )
      this->votePerPeer |= 1 << peer;
    v3 = this->skipVotes + 1;
    v4.type = SWF_VAR_UNDEF;
    this->skipVotes = v3;
    idSWFScriptVar::Free(this: &v4);
    v4.value.i = v3;
    v4.type = SWF_VAR_INTEGER;
    idStr::idStr(this: v5, text: "numVotes");
    idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: v5, value: &v4);
    idStr::FreeData(this: v5);
    idSWFScriptVar::Free(this: &v4);
    idMainMenu::UpdateMenuVoteStatus(this: this->mainMenu);
  }
  idMainMenu::UpdateMenuVoteStatus(this: this->mainMenu);
}


// ========================================================================
// __unwind$490165_0
// EA  : 0x82D9F394
// RVA : 0x00D9F394
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490165_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 160 + 88));
}


// ========================================================================
// __unwind$490166
// EA  : 0x82D9F3BC
// RVA : 0x00D9F3BC
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490166()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?UpdatePeers@idLobbyController@@AAAXXZ
// EA  : 0x82D9F3E8
// RVA : 0x00D9F3E8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::UpdatePeers(idLobbyController *this)
{
  signed int v2; // r3
  unsigned __int64 v3; // r11
  int v4; // r4
  idLobbyBase *v5; // r3
  _BYTE v6[16]; // [sp+50h] [-50h] BYREF
  idBitMsg v7; // [sp+60h] [-40h] BYREF

  v2 = Sys_Milliseconds();
  if ( this->nextPeerUpdateMs <= v2 )
  {
    LODWORD(v3) = 0;
    HIDWORD(v3) = this->state;
    v7.curSize = 0;
    this->nextPeerUpdateMs = v2 + 500;
    v7.writeData = v6;
    v7.readData = v6;
    v7.maxSize = 4;
    memset(&v7.writeBit, 0, 14);
    v7.tempValue = v3;
    if ( HIDWORD(v3) == 0
      || idLobbyController::idCountdown::RemainingMs(this: &this->intermissionCountdown) == 0
      && this->finalCountdown.isPaused
      || this->intermissionCountdown.isPaused )
    {
      v4 = 255;
    }
    else
    {
      v4 = idLobbyController::CalcRemainingSecUntilLaunch(this);
    }
    idBitMsg::WriteBits(this: &v7, value: v4, numBits: 8);
    idBitMsg::WriteBits(this: &v7, value: (unsigned __int8)this->skipVotes, numBits: 8);
    idBitMsg::WriteBits(this: &v7, value: (unsigned __int8)this->skipVotesNeeded, numBits: 8);
    idBitMsg::WriteBits(this: &v7, value: (unsigned __int8)this->skipVoteState, numBits: 8);
    v5 = session->GetGameLobbyBase(this: session);
    v5->SendReliable(this: v5, a2: 24, a3: &v7, a4: false, a5: 255u);
  }
}


// ========================================================================
// ?DisplaySecondsRemaining@idLobbyController@@ABAXH@Z
// EA  : 0x82D9F530
// RVA : 0x00D9F530
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::DisplaySecondsRemaining(idLobbyController *this, int seconds)
{
  const char *String; // r3
  idStr *v5; // r3
  idStr *v6; // r3
  const char *v7; // r3
  idStr *v8; // r3
  idSWFScriptVar v9; // [sp+50h] [-120h] BYREF
  idSWFScriptVar v10; // [sp+58h] [-118h] BYREF
  idSWFScriptVar v11[2]; // [sp+60h] [-110h] BYREF
  idStr v12; // [sp+70h] [-100h] BYREF
  idStr v13; // [sp+90h] [-E0h] BYREF
  idStr v14; // [sp+B0h] [-C0h] BYREF
  idStr v15; // [sp+D0h] [-A0h] BYREF
  idStr v16; // [sp+F0h] [-80h] BYREF
  idStr v17; // [sp+110h] [-60h] BYREF
  idStr v18[2]; // [sp+130h] [-40h] BYREF

  if ( seconds == 255 )
  {
    idSWFScriptVar::idSWFScriptVar(this: &v10, s: "#str_online_mpstatus_waiting_for_players");
    idStr::idStr(this: &v16, text: "mpstatus");
    idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: &v16, value: &v10);
    idStr::FreeData(this: &v16);
    idSWFScriptVar::Free(this: &v10);
  }
  else
  {
    if ( seconds == 1 )
    {
      String = idLocalization::GetString(inString: "#str_online_game_starts_in_second");
      idStr::idStr(this: &v13, text: String);
      v5 = idStr::idStr(this: &v17, i: 1);
      idStr::Replace(this: &v13, old: "<DNT_VAL>", nw: v5->data);
      idStr::FreeData(this: &v17);
      idSWFScriptVar::idSWFScriptVar(this: &v9, s: &v13);
      idStr::idStr(this: &v14, text: "mpstatus");
      idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: &v14, value: &v9);
      idStr::FreeData(this: &v14);
      idSWFScriptVar::Free(this: &v9);
      v6 = &v13;
    }
    else
    {
      v7 = idLocalization::GetString(inString: "#str_online_game_starts_in_seconds");
      idStr::idStr(this: &v12, text: v7);
      v8 = idStr::idStr(this: v18, i: seconds);
      idStr::Replace(this: &v12, old: "<DNT_VAL>", nw: v8->data);
      idStr::FreeData(this: v18);
      idSWFScriptVar::idSWFScriptVar(this: v11, s: &v12);
      idStr::idStr(this: &v15, text: "mpstatus");
      idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: &v15, value: v11);
      idStr::FreeData(this: &v15);
      idSWFScriptVar::Free(this: v11);
      v6 = &v12;
    }
    idStr::FreeData(this: v6);
  }
}


// ========================================================================
// __unwind$490266
// EA  : 0x82D9F6AC
// RVA : 0x00D9F6AC
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490266()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 88));
}


// ========================================================================
// __unwind$490267
// EA  : 0x82D9F6D4
// RVA : 0x00D9F6D4
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490267()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 240));
}


// ========================================================================
// __unwind$490268
// EA  : 0x82D9F6FC
// RVA : 0x00D9F6FC
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490268()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 144));
}


// ========================================================================
// __unwind$490269
// EA  : 0x82D9F724
// RVA : 0x00D9F724
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490269()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 272));
}


// ========================================================================
// __unwind$490270
// EA  : 0x82D9F74C
// RVA : 0x00D9F74C
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490270()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$490271
// EA  : 0x82D9F774
// RVA : 0x00D9F774
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490271()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 176));
}


// ========================================================================
// __unwind$490272_0
// EA  : 0x82D9F79C
// RVA : 0x00D9F79C
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490272_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$490273_0
// EA  : 0x82D9F7C4
// RVA : 0x00D9F7C4
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490273_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 304));
}


// ========================================================================
// __unwind$490274_0
// EA  : 0x82D9F7EC
// RVA : 0x00D9F7EC
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490274_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$490275_0
// EA  : 0x82D9F814
// RVA : 0x00D9F814
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490275_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 208));
}


// ========================================================================
// ?RecvUpdate@idLobbyController@@QAAXAAVidBitMsg@@@Z
// EA  : 0x82D9F848
// RVA : 0x00D9F848
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::RecvUpdate(idLobbyController *this, idBitMsg *msg)
{
  unsigned __int8 Bits; // r3
  int skipVotes; // r27
  int skipVotesNeeded; // r29
  idSWFScriptVar v7; // [sp+50h] [-B0h] BYREF
  idSWFScriptVar v8; // [sp+58h] [-A8h] BYREF
  idSWFScriptVar v9[2]; // [sp+60h] [-A0h] BYREF
  idStr v10; // [sp+70h] [-90h] BYREF
  idStr v11; // [sp+90h] [-70h] BYREF
  idStr v12[2]; // [sp+B0h] [-50h] BYREF

  this->serverRemainingSecUntilLaunch = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  this->skipVotes = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  this->skipVotesNeeded = (unsigned __int8)idBitMsg::ReadBits(this: msg, numBits: 8);
  Bits = idBitMsg::ReadBits(this: msg, numBits: 8);
  this->skipVoteState = Bits;
  if ( Bits == 0 )
  {
    v7.type = SWF_VAR_UNDEF;
    this->didVote = false;
    idSWFScriptVar::Free(this: &v7);
    v7.value.b = false;
    v7.type = SWF_VAR_BOOL;
    idStr::idStr(this: &v10, text: "didVote");
    idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: &v10, value: &v7);
    idStr::FreeData(this: &v10);
    idSWFScriptVar::Free(this: &v7);
  }
  v8.type = SWF_VAR_UNDEF;
  skipVotes = this->skipVotes;
  idSWFScriptVar::Free(this: &v8);
  v8.value.i = skipVotes;
  v8.type = SWF_VAR_INTEGER;
  idStr::idStr(this: &v11, text: "numVotes");
  idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: &v11, value: &v8);
  idStr::FreeData(this: &v11);
  idSWFScriptVar::Free(this: &v8);
  v9[0].type = SWF_VAR_UNDEF;
  skipVotesNeeded = this->skipVotesNeeded;
  idSWFScriptVar::Free(this: v9);
  v9[0].value.i = skipVotesNeeded;
  v9[0].type = SWF_VAR_INTEGER;
  idStr::idStr(this: v12, text: "numVotesNeeded");
  idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: v12, value: v9);
  idStr::FreeData(this: v12);
  idSWFScriptVar::Free(this: v9);
  idMainMenu::UpdateMenuVoteStatus(this: this->mainMenu);
}


// ========================================================================
// __unwind$490404_0
// EA  : 0x82D9F9B0
// RVA : 0x00D9F9B0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490404_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$490405_0
// EA  : 0x82D9F9D8
// RVA : 0x00D9F9D8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490405_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$490406_0
// EA  : 0x82D9FA00
// RVA : 0x00D9FA00
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490406_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 88));
}


// ========================================================================
// __unwind$490407
// EA  : 0x82D9FA28
// RVA : 0x00D9FA28
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490407()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$490408
// EA  : 0x82D9FA50
// RVA : 0x00D9FA50
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490408()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$490409
// EA  : 0x82D9FA78
// RVA : 0x00D9FA78
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490409()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 176));
}


// ========================================================================
// ?EvalSkipVote@idLobbyController@@AAAXXZ
// EA  : 0x82D9FAA8
// RVA : 0x00D9FAA8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::EvalSkipVote(idLobbyController *this)
{
  idLobbyBase *v2; // r3
  int v3; // r3
  idSWFScriptVar::swfScriptVarValue_t v4; // r29
  idLobbyBase *v5; // r3
  int v6; // r28
  int v7; // r29
  idLobbyBase *v8; // r3
  idSWFScriptVar::swfScriptVarValue_t *v9; // r4
  idLobbyBase *v10; // r3
  idMainMenu *mainMenu; // r3
  idSWFScriptVar v12; // [sp+58h] [-98h] BYREF
  idSWFScriptVar v13[2]; // [sp+60h] [-90h] BYREF
  idStr v14; // [sp+70h] [-80h] BYREF
  idStr v15[3]; // [sp+90h] [-60h] BYREF

  if ( this->skipVoteState == SKIPVOTE_STARTED )
  {
    v2 = session->GetGameLobbyBase(this: session);
    if ( this->numPlayers != v2->GetNumLobbyUsers(this: v2) )
    {
      v3 = idLobbyController::CalcNumSkipVotesRequiredToPass(this);
      this->skipVotesNeeded = v3;
      v4.i = v3;
      v12.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v12);
      v12.value = v4;
      v12.type = SWF_VAR_INTEGER;
      idStr::idStr(this: &v14, text: "numVotesNeeded");
      idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: &v14, value: &v12);
      idStr::FreeData(this: &v14);
      idSWFScriptVar::Free(this: &v12);
      v5 = session->GetGameLobbyBase(this: session);
      if ( this->numPlayers > v5->GetNumLobbyUsers(this: v5) )
      {
        v6 = 0;
        v7 = 1;
        do
        {
          if ( (v7 & this->votePerPeer) != 0 )
          {
            v8 = session->GetGameLobbyBase(this: session);
            if ( v8->IsPeerDisconnected(this: v8, a2: v6) )
            {
              v9 = (idSWFScriptVar::swfScriptVarValue_t *)(this->skipVotes - 1);
              this->votePerPeer &= ~v7;
              this->skipVotes = (int)v9;
              idSWFScriptVar::idSWFScriptVar(this: v13, i: v9);
              idStr::idStr(this: v15, text: "numVotes");
              idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: v15, value: v13);
              idStr::FreeData(this: v15);
              idSWFScriptVar::Free(this: v13);
            }
          }
          ++v6;
          v7 = __ROL4__(v7, 1);
        }
        while ( v6 < 6 );
      }
      idMainMenu::UpdateMenuVoteStatus(this: this->mainMenu);
      v10 = session->GetGameLobbyBase(this: session);
      this->numPlayers = v10->GetNumLobbyUsers(this: v10);
    }
    if ( this->skipVotes >= this->skipVotesNeeded && !session->WasMigrationGame(this: session) )
    {
      mainMenu = this->mainMenu;
      this->skipVoteState = SKIPVOTE_PASSED;
      idMainMenu::SetRandomMatchMap(this: mainMenu);
      idMainMenu::UpdateMenuVoteStatus(this: this->mainMenu);
    }
  }
}


// ========================================================================
// __unwind$490518_0
// EA  : 0x82D9FCBC
// RVA : 0x00D9FCBC
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490518_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 88));
}


// ========================================================================
// __unwind$490519_0
// EA  : 0x82D9FCE4
// RVA : 0x00D9FCE4
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490519_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$490520_0
// EA  : 0x82D9FD0C
// RVA : 0x00D9FD0C
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490520_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$490521_0
// EA  : 0x82D9FD34
// RVA : 0x00D9FD34
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490521_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 144));
}


// ========================================================================
// ?ResetSkipVote@idLobbyController@@AAAXXZ
// EA  : 0x82D9FD68
// RVA : 0x00D9FD68
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::ResetSkipVote(idLobbyController *this)
{
  int skipVotesNeeded; // r30
  idSWFScriptVar v3; // [sp+50h] [-B0h] BYREF
  idSWFScriptVar v4; // [sp+58h] [-A8h] BYREF
  idSWFScriptVar v5[2]; // [sp+60h] [-A0h] BYREF
  idStr v6; // [sp+70h] [-90h] BYREF
  idStr v7; // [sp+90h] [-70h] BYREF
  idStr v8[2]; // [sp+B0h] [-50h] BYREF

  this->skipVoteState = SKIPVOTE_NONE;
  v3.type = SWF_VAR_UNDEF;
  this->numPlayers = 0;
  this->skipVotesNeeded = 0;
  this->skipVotes = 0;
  this->votePerPeer = 0;
  this->didVote = false;
  idSWFScriptVar::Free(this: &v3);
  v3.value.i = 0;
  v3.type = SWF_VAR_INTEGER;
  idStr::idStr(this: &v6, text: "numVotes");
  idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: &v6, value: &v3);
  idStr::FreeData(this: &v6);
  idSWFScriptVar::Free(this: &v3);
  v4.type = SWF_VAR_UNDEF;
  skipVotesNeeded = this->skipVotesNeeded;
  idSWFScriptVar::Free(this: &v4);
  v4.value.i = skipVotesNeeded;
  v4.type = SWF_VAR_INTEGER;
  idStr::idStr(this: &v7, text: "numVotesNeeded");
  idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: &v7, value: &v4);
  idStr::FreeData(this: &v7);
  idSWFScriptVar::Free(this: &v4);
  v5[0].type = SWF_VAR_UNDEF;
  LOBYTE(skipVotesNeeded) = this->didVote;
  idSWFScriptVar::Free(this: v5);
  v5[0].value.b = skipVotesNeeded;
  v5[0].type = SWF_VAR_BOOL;
  idStr::idStr(this: v8, text: "didVote");
  idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: v8, value: v5);
  idStr::FreeData(this: v8);
  idSWFScriptVar::Free(this: v5);
  idMainMenu::UpdateMenuVoteStatus(this: this->mainMenu);
}


// ========================================================================
// __unwind$490589
// EA  : 0x82D9FE88
// RVA : 0x00D9FE88
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490589()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$490590_0
// EA  : 0x82D9FEB0
// RVA : 0x00D9FEB0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490590_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$490591
// EA  : 0x82D9FED8
// RVA : 0x00D9FED8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490591()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 88));
}


// ========================================================================
// __unwind$490592
// EA  : 0x82D9FF00
// RVA : 0x00D9FF00
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490592()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$490593
// EA  : 0x82D9FF28
// RVA : 0x00D9FF28
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490593()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$490594_0
// EA  : 0x82D9FF50
// RVA : 0x00D9FF50
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490594_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 176));
}


// ========================================================================
// ?RecvVote@idLobbyController@@QAAXAAVidBitMsg@@H@Z
// EA  : 0x82D9FF78
// RVA : 0x00D9FF78
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::RecvVote(idLobbyController *this, idBitMsg *msg, int peer)
{
  idLobbyController::AddVoteToSkip(this, peer);
}


// ========================================================================
// ?VoteToSkip@idLobbyController@@QAAXXZ
// EA  : 0x82DA0110
// RVA : 0x00DA0110
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::VoteToSkip(idLobbyController *this)
{
  idLobbyBase *v2; // r3
  idSWFScriptVar v3[2]; // [sp+50h] [-50h] BYREF
  idStr v4[2]; // [sp+60h] [-40h] BYREF

  if ( !this->didVote && this->skipVoteState == SKIPVOTE_STARTED )
  {
    v3[0].type = SWF_VAR_UNDEF;
    this->didVote = true;
    idSWFScriptVar::Free(this: v3);
    v3[0].value.b = true;
    v3[0].type = SWF_VAR_BOOL;
    idStr::idStr(this: v4, text: "didVote");
    idMainMenu::SetMainMenuGlobal(this: this->mainMenu, name: v4, value: v3);
    idStr::FreeData(this: v4);
    idSWFScriptVar::Free(this: v3);
    idMainMenu::UpdateMenuVoteStatus(this: this->mainMenu);
    v2 = session->GetGameLobbyBase(this: session);
    if ( v2->IsHost(this: v2) != 0 )
      idLobbyController::AddVoteToSkip(this, peer: -1);
    else
      idLobbyController::SendVoteToSkip(this);
  }
}


// ========================================================================
// __unwind$490754
// EA  : 0x82DA01E8
// RVA : 0x00DA01E8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490754()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$490755
// EA  : 0x82DA0210
// RVA : 0x00DA0210
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_490755()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// ?StartIntermission@idLobbyController@@QAAX_N@Z
// EA  : 0x82DA0238
// RVA : 0x00DA0238
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::StartIntermission(idLobbyController *this, bool randomMap)
{
  int v4; // ctr
  idLobbyController::state_t *v5; // r11
  idLobbyController *v6; // r10
  int v7; // ctr
  int *v8; // r11
  bool *p_isPaused; // r10
  int v10; // [sp+4Ch] [-54h] BYREF
  int v11; // [sp+50h] [-50h]
  unsigned int v12; // [sp+54h] [-4Ch]
  int v13; // [sp+58h] [-48h]
  int v14; // [sp+5Ch] [-44h]
  char v15; // [sp+60h] [-40h]

  v11 = 1000
      * session->GetTitleStorageInt_2(
          this: session,
          a2: "lobby_IntermissionSecMax",
          a3: lobby_IntermissionSecMax.valueInteger);
  v12 = Sys_Milliseconds();
  v13 = 0;
  v4 = 5;
  v5 = (idLobbyController::state_t *)&v10;
  v14 = 0;
  v6 = this;
  v15 = 0;
  do
  {
    ++v5;
    v6 = (idLobbyController *)((char *)v6 + 4);
    v6->state = *v5;
    --v4;
  }
  while ( v4 != 0 );
  if ( !this->intermissionCountdown.isPaused )
  {
    this->intermissionCountdown.isPaused = true;
    this->intermissionCountdown.pauseStartMs = Sys_Milliseconds();
  }
  v11 = 1000
      * session->GetTitleStorageInt_2(
          this: session,
          a2: "lobby_FinalCountdownSec",
          a3: lobby_FinalCountdownSec.valueInteger);
  v12 = Sys_Milliseconds();
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v7 = 5;
  v8 = &v10;
  p_isPaused = &this->intermissionCountdown.isPaused;
  do
  {
    ++v8;
    p_isPaused += 4;
    *(_DWORD *)p_isPaused = *v8;
    --v7;
  }
  while ( v7 != 0 );
  if ( !this->finalCountdown.isPaused )
  {
    this->finalCountdown.isPaused = true;
    this->finalCountdown.pauseStartMs = Sys_Milliseconds();
  }
  if ( randomMap && !session->WasMigrationGame(this: session) && !session->WasGameLobbyCoalesced(this: session) )
    idMainMenu::SetRandomMatchMap(this: this->mainMenu);
  idLobbyController::ResetSkipVote(this);
  idLobbyController::SetState(this, s: INTERMISSION);
}


// ========================================================================
// ?PumpMainMenu@idLobbyController@@ABAXXZ
// EA  : 0x82DA03C8
// RVA : 0x00DA03C8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::PumpMainMenu(idLobbyController *this)
{
  idLobbyController::state_t state; // r11
  int v3; // r3
  idLobbyController *v4; // r3

  state = this->state;
  if ( this->state > (unsigned int)IN_GAME )
  {
    idLib::Error(fmt: "Unexpected state in idLobbyController::Pump\n");
    idLobbyController::PumpIntermission(this: v4);
  }
  else if ( state != 0 && (state == INTERMISSION || state == FINAL_COUNTDOWN) )
  {
    v3 = idLobbyController::CalcRemainingSecUntilLaunch(this);
    idLobbyController::DisplaySecondsRemaining(this, seconds: v3);
  }
}


// ========================================================================
// ?PumpIntermission@idLobbyController@@AAAXXZ
// EA  : 0x82DA0430
// RVA : 0x00DA0430
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::PumpIntermission(idLobbyController *this)
{
  idLobbyBase *v2; // r3
  int v3; // r31
  idLobbyBase *v4; // r3
  int v5; // r31
  idLobbyBase *v6; // r31
  idLobbyBase *v7; // r3
  int v8; // r29
  int v9; // r27
  idLobbyBase *v10; // r3
  int v11; // r31
  signed int v12; // r31
  int v13; // r30
  int v14; // r3
  int v15; // r10
  unsigned int v16; // r8
  int v17; // r31
  long double v18; // fp2
  long double v19; // fp2
  int v20; // ctr
  idLobbyController::state_t *v21; // r11
  idLobbyController *v22; // r10
  _DWORD v23[5]; // [sp+5Ch] [-54h] BYREF
  char v24; // [sp+70h] [-40h]

  if ( this->intermissionCountdown.isPaused
    && (v2 = session->GetGameLobbyBase(this: session),
        v3 = v2->GetNumLobbyUsers(this: v2),
        idLobbyController::GetMinPlayersToStartCountdown(this) <= v3) )
  {
    idLobbyController::idCountdown::Resume(this: &this->intermissionCountdown);
    this->skipVoteState = SKIPVOTE_STARTED;
  }
  else if ( !this->intermissionCountdown.isPaused )
  {
    v4 = session->GetGameLobbyBase(this: session);
    v5 = v4->GetNumLobbyUsers(this: v4);
    if ( v5 < idLobbyController::GetMinPlayersToStartGame(this) )
      idLobbyController::StartIntermission(this, randomMap: false);
  }
  if ( !this->intermissionCountdown.isPaused )
  {
    v6 = session->GetGameLobbyBase(this: session);
    v7 = session->GetGameLobbyBase(this: session);
    v8 = 2;
    if ( v7->GetMatchParms(this: v7)->gameType != 1 )
      v8 = 6;
    v9 = v8 - v6->GetNumLobbyUsers(this: v6);
    v10 = session->GetGameLobbyBase(this: session);
    v11 = 2;
    if ( v10->GetMatchParms(this: v10)->gameType != 1 )
      v11 = 6;
    v12 = v11 - idLobbyController::GetMinPlayersToStartCountdown(this);
    v13 = session->GetTitleStorageInt_2(
            this: session,
            a2: "lobby_IntermissionSecMin",
            a3: lobby_IntermissionSecMin.valueInteger);
    v14 = session->GetTitleStorageInt_2(
            this: session,
            a2: "lobby_IntermissionSecMax",
            a3: lobby_IntermissionSecMax.valueInteger);
    if ( v12 <= 1 )
      v12 = 1;
    v15 = (v14 - v13) * v9;
    v16 = v12 & ~(__ROL4__(v15, 1) - 1);
    __twllei(v12, 0);
    v17 = v15 / v12 + v13;
    __twlgei(v16, 0xFFFFFFFF);
    *(double *)&v18 = (float)((float)__SPAIR64__(
                                       &off_82040000,
                                       idLobbyController::idCountdown::RemainingMs(this: &this->intermissionCountdown))
                            * (float)0.001);
    v19 = ceil(x: v18);
    if ( (int)(float)*(double *)&v19 > v17 )
    {
      v23[1] = 1000 * v17;
      v23[2] = Sys_Milliseconds();
      v23[3] = 0;
      v23[4] = 0;
      v20 = 5;
      v24 = 0;
      v21 = (idLobbyController::state_t *)v23;
      v22 = this;
      do
      {
        ++v21;
        v22 = (idLobbyController *)((char *)v22 + 4);
        v22->state = *v21;
        --v20;
      }
      while ( v20 != 0 );
      idLobbyController::idCountdown::Resume(this: &this->intermissionCountdown);
    }
  }
  if ( idLobbyController::idCountdown::RemainingMs(this: &this->intermissionCountdown) == 0 )
    idLobbyController::StartFinalCountdown(this, overrideCountdownMS: -1);
}


// ========================================================================
// ?PumpFinalCountdown@idLobbyController@@AAAXXZ
// EA  : 0x82DA06F0
// RVA : 0x00DA06F0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::PumpFinalCountdown(idLobbyController *this)
{
  idLobbyBase *v2; // r3
  int v3; // r29

  if ( this->mainMenu->privateMatch
    || (v2 = session->GetGameLobbyBase(this: session),
        (v3 = v2->GetNumLobbyUsers(this: v2)) >= idLobbyController::GetMinPlayersToStartGame(this)) )
  {
    if ( idLobbyController::idCountdown::RemainingMs(this: &this->finalCountdown) == 0
      && idLobbyController::CanLaunchGame(this) )
    {
      idLobbyController::SetState(this, s: IN_GAME);
      session->StartMatch(this: session);
    }
  }
  else
  {
    idLobbyController::StartIntermission(this, randomMap: false);
  }
}


// ========================================================================
// ?Reset@idLobbyController@@QAAXXZ
// EA  : 0x82DA07B0
// RVA : 0x00DA07B0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::Reset(idLobbyController *this)
{
  idLobbyController v1; // [sp+50h] [-60h] BYREF

  v1.mainMenu = this->mainMenu;
  memset(&v1, 0, 21);
  memset(&v1.finalCountdown, 0, 17);
  v1.nextPeerUpdateMs = 0;
  v1.serverRemainingSecUntilLaunch = 255;
  memset(&v1.skipVotes, 0, 21);
  *this = v1;
  idLobbyController::ResetSkipVote(this);
}


// ========================================================================
// ?PumpState@idLobbyController@@AAAXXZ
// EA  : 0x82DA0DC0
// RVA : 0x00DA0DC0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::PumpState(idLobbyController *this)
{
  idLobbyController::state_t state; // r11

  if ( lobby_ForceStart.valueInteger != 0 )
  {
    if ( idLobbyController::CanLaunchGame(this) )
    {
      idLib::Warning(fmt: "Forcing game launch due to lobby_ForceStart 1");
      idCVar::SetBool(this: &lobby_ForceStart, newValue: false, force: true);
      idLobbyController::SetState(this, s: IN_GAME);
      session->StartMatch(this: session);
    }
  }
  else
  {
    state = this->state;
    if ( this->state == INTERMISSION )
    {
      idLobbyController::PumpIntermission(this);
    }
    else
    {
      if ( state != FINAL_COUNTDOWN )
      {
        if ( state == IN_GAME )
          return;
        idLib::Error(fmt: "Unexpected state in idLobbyController::Pump\n");
      }
      idLobbyController::PumpFinalCountdown(this);
    }
  }
}


// ========================================================================
// ?BalanceTeams@idLobbyController@@AAAXXZ
// EA  : 0x82DA1190
// RVA : 0x00DA1190
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::BalanceTeams(idLobbyController *this)
{
  char v1; // r27
  int v2; // r29
  idLobbyBase *v3; // r3
  idLobbyBase *v4; // r28
  idLobbyBase *v5; // r26
  idLobbyBase *v6; // r4
  lobbyUserID_t *(__fastcall *v7)(idLobbyBase *, lobbyUserID_t *, int); // r6
  idLobbyBase_vtbl *v8; // r28
  idLobbyBase **v9; // r3
  idLobbyBase *v10; // r3
  idLobbyBase *v11; // r3
  int v12; // r29
  idLobbyBase *v13; // r3
  int v14; // r9
  __int64 v15; // r8
  int v16; // r6
  idLobbyBase *v17; // r30
  idLobbyBase *v18; // r3
  idLobbyBase *v19; // r4
  lobbyUserID_t *(__fastcall *GetLobbyUserIdByOrdinal)(idLobbyBase *, lobbyUserID_t *, int); // r6
  idLobbyBase_vtbl *v21; // r30
  idLobbyBase **v22; // r3
  int v23; // r3
  int v24; // r11
  party_t *list; // r10
  idLobbyBase *v26; // r3
  party_t *v27; // r10
  idStaticList<int,6> *v28; // r29
  int i; // r30
  int v30; // r30
  int v31; // r28
  int v32; // r26
  int v33; // r27
  int v34; // r30
  idStaticList<int,6> *v35; // r28
  int v36; // r29
  party_t *v37; // r11
  unsigned int v38; // r27
  int v39; // r25
  int v40; // r26
  int v41; // r30
  idStaticList<int,6> *p_users; // r28
  int v43; // r29
  int *v44; // r11
  int v45; // r11
  int num; // r10
  int j; // r9
  int v48; // r10
  int v49; // r7
  encounterGroupRole_t *v50; // r8
  encounterGroupRole_t *v51; // r11
  int v52; // r11
  int v53; // r9
  int v54; // r7
  encounterGroupRole_t *v55; // r8
  encounterGroupRole_t *v56; // r11
  int v57; // r11
  char v58; // r24
  int v59; // r25
  int *p_num; // r28
  int v61; // r26
  int v62; // r29
  idLobbyBase *v63; // r30
  idLobbyBase *v64; // r20
  idLobbyBase *v65; // r4
  lobbyUserID_t *(__fastcall *v66)(idLobbyBase *, lobbyUserID_t *, int); // r6
  idLobbyBase_vtbl *v67; // r30
  idLobbyBase **v68; // r3
  idLobbyBase *v69; // r3
  encounterGroupRole_t v70[2]; // [sp+50h] [-210h] BYREF
  idSort_Quick<party_t,idSortPartyBySize> v71; // [sp+58h] [-208h] BYREF
  idList<enum encounterGroupRole_t,5> v72; // [sp+60h] [-200h] BYREF
  idList<enum encounterGroupRole_t,5> v73[2]; // [sp+7Ch] [-1E4h] BYREF
  party_t v74; // [sp+A0h] [-1C0h] BYREF
  _BYTE v75[16]; // [sp+D0h] [-190h] BYREF
  idStaticList<party_t,6> v76; // [sp+E0h] [-180h] BYREF

  if ( idMainMenu::IsTeamGameMatch(this: this->mainMenu) )
  {
    idStaticList<party_t,6>::idStaticList<party_t,6>(this: &v76);
    v12 = 0;
    v70[0] = ROLE_NONE;
    v13 = session->GetGameLobbyBase(this: session);
    if ( v13->GetNumLobbyUsers(this: v13) > 0 )
    {
      do
      {
        v17 = session->GetGameLobbyBase(this: session);
        v18 = session->GetGameLobbyBase(this: session);
        v19 = v17;
        GetLobbyUserIdByOrdinal = v17->GetLobbyUserIdByOrdinal;
        v21 = v18->__vftable;
        v22 = (idLobbyBase **)GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v75, result: (lobbyUserID_t *)v19, a3: v12);
        v23 = v21->GetLobbyUserPartyToken(this: *v22, a2: (lobbyUserID_t *)v22[1]);
        v74.users.size = 6;
        v74.users.num = 0;
        v74.users.granularity = 1;
        v74.users.list = v74.users.staticList;
        v74.token = v23;
        v74.users.memTag = 5;
        v74.users.listStatic = 1;
        v24 = 0;
        if ( v76.num <= 0 )
          goto LABEL_13;
        list = v76.list;
        while ( list->token != v23 )
        {
          ++v24;
          ++list;
          if ( v24 >= v76.num )
            goto LABEL_13;
        }
        if ( v24 >= 0 && (v37 = &v76.list[v24]) != nullptr )
        {
          idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v37->users, obj: v70);
        }
        else
        {
LABEL_13:
          idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v74.users, obj: v70);
          idList<party_t,5>::Append(this: &v76, obj: &v74);
        }
        if ( v74.users.listStatic == 0 || v74.users.listStatic == 2 )
        {
          if ( v74.users.list != nullptr )
            idMem::Free(this: &mem, ptr: v74.users.list, align: ALIGN_16);
          v74.users.list = nullptr;
          v74.users.size = 0;
        }
        v74.users.num = 0;
        v70[0] = ++v12;
        v26 = session->GetGameLobbyBase(this: session);
      }
      while ( v12 < v26->GetNumLobbyUsers(this: v26) );
    }
    v71.__vftable = (idSort_Quick<party_t,idSortPartyBySize>_vtbl *)&idSortPartyBySize::`vftable';
    if ( v76.list != nullptr )
      idSort_Quick<party_t,idSortPartyBySize>::Sort(this: &v71, base: v76.list, num: v76.num, a4: v16, a5: v15, a6: v14);
    v71.__vftable = (idSort_Quick<party_t,idSortPartyBySize>_vtbl *)&idSort<party_t>::`vftable';
    `eh vector constructor iterator'(
      ptr: &v72,
      size: 0x1Cu,
      count: 2,
      pCtor: (void (__fastcall *)(void *))idStaticList<int,3>::idStaticList<int,3>,
      pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
    v27 = v76.list;
    if ( v76.list->users.idList<party_t,5>::num < 3 )
    {
      v38 = 0;
      v39 = 0;
      if ( v76.num > 0 )
      {
        v40 = 0;
        do
        {
          v41 = 0;
          p_users = &v27[v40].users;
          if ( v27[v40].users.num > 0 )
          {
            v43 = 0;
            do
            {
              v44 = (int *)&v72 + 7 * v38;
              if ( *((_BYTE *)v44 + 15) != 0 )
                v45 = (v44[1] >> 31) + (v44[1] >= (unsigned int)v44[2]) + ((unsigned int)v44[2] >> 31);
              else
                LOBYTE(v45) = 0;
              if ( (_BYTE)v45 != 0 )
                v38 = (_cntlzw(v38) & 0x20) != 0;
              idList<idAnimWebBlendTree *,5>::Append(
                this: (idList<enum encounterGroupRole_t,5> *)((char *)&v72 + 28 * v38),
                obj: (encounterGroupRole_t *)&p_users->list[v43]);
              ++v41;
              ++v43;
            }
            while ( v41 < p_users->num );
            v27 = v76.list;
          }
          ++v39;
          v38 = (_cntlzw(v38) & 0x20) != 0;
          ++v40;
        }
        while ( v39 < v76.num );
      }
    }
    else
    {
      v28 = &v76.list->users;
      for ( i = 0; i < 3; ++i )
        idList<idAnimWebBlendTree *,5>::Append(this: &v72, obj: (encounterGroupRole_t *)&v28->list[i]);
      v30 = 3;
      if ( v28->num > 3 )
      {
        v31 = 3;
        do
        {
          idList<idAnimWebBlendTree *,5>::Append(this: v73, obj: (encounterGroupRole_t *)&v28->list[v31]);
          ++v30;
          ++v31;
        }
        while ( v30 < v28->num );
      }
      v32 = 1;
      if ( v76.num > 1 )
      {
        v33 = 1;
        do
        {
          v34 = 0;
          v35 = &v76.list[v33].users;
          if ( v76.list[v33].users.num > 0 )
          {
            v36 = 0;
            do
            {
              idList<idAnimWebBlendTree *,5>::Append(this: v73, obj: (encounterGroupRole_t *)&v35->list[v36]);
              ++v34;
              ++v36;
            }
            while ( v34 < v35->num );
          }
          ++v32;
          ++v33;
        }
        while ( v32 < v76.num );
      }
    }
    num = v73[0].num;
    for ( j = v72.num; j - v73[0].num > 1; num = v73[0].num )
    {
      v70[0] = j - 1;
      idList<idAnimWebBlendTree *,5>::Append(this: v73, obj: v70);
      j = v72.num;
      v48 = 0;
      v49 = v72.num - 1;
      if ( v72.num > 0 )
      {
        v50 = v72.list;
        v51 = v72.list;
        while ( *v51 != v49 )
        {
          ++v48;
          ++v51;
          if ( v48 >= v72.num )
            goto LABEL_62;
        }
        if ( v48 >= 0 && v48 < v72.num )
        {
          j = --v72.num;
          if ( v48 < v49 )
          {
            v52 = v48;
            while ( 1 )
            {
              ++v48;
              v50[v52] = v50[v52 + 1];
              ++v52;
              j = v72.num;
              if ( v48 >= v72.num )
                break;
              v50 = v72.list;
            }
          }
        }
      }
LABEL_62:
      ;
    }
    if ( num - j > 1 )
    {
      do
      {
        v70[0] = num - 1;
        idList<idAnimWebBlendTree *,5>::Append(this: &v72, obj: v70);
        num = v73[0].num;
        v53 = 0;
        v54 = v73[0].num - 1;
        if ( v73[0].num > 0 )
        {
          v55 = v73[0].list;
          v56 = v73[0].list;
          while ( *v56 != v54 )
          {
            ++v53;
            ++v56;
            if ( v53 >= v73[0].num )
              goto LABEL_75;
          }
          if ( v53 >= 0 && v53 < v73[0].num )
          {
            num = --v73[0].num;
            if ( v53 < v54 )
            {
              v57 = v53;
              while ( 1 )
              {
                ++v53;
                v55[v57] = v55[v57 + 1];
                ++v57;
                num = v73[0].num;
                if ( v53 >= v73[0].num )
                  break;
                v55 = v73[0].list;
              }
            }
          }
        }
LABEL_75:
        ;
      }
      while ( num - v72.num > 1 );
    }
    v58 = 0;
    v59 = 0;
    p_num = &v72.num;
    do
    {
      v61 = 0;
      if ( *p_num > 0 )
      {
        v62 = 0;
        do
        {
          v63 = session->GetGameLobbyBase(this: session);
          v64 = session->GetActivePlatformLobbyBase(this: session);
          v65 = v63;
          v66 = v63->GetLobbyUserIdByOrdinal;
          v67 = v64->__vftable;
          v68 = (idLobbyBase **)v66(
                                  this: (idLobbyBase *)v75,
                                  result: (lobbyUserID_t *)v65,
                                  a3: *(_DWORD *)(*(p_num - 1) + v62));
          if ( v67->SetLobbyUserTeam(this: *v68, a2: (lobbyUserID_t *)v68[1], a3: v59 + 1) )
            v58 = 1;
          ++v61;
          v62 += 4;
        }
        while ( v61 < *p_num );
      }
      ++v59;
      p_num += 7;
    }
    while ( v59 < 2 );
    if ( v58 != 0 )
    {
      v69 = session->GetGameLobbyBase(this: session);
      v69->SendLobbyUserUpdateToPeers(this: v69);
    }
    `eh vector destructor iterator'(
      ptr: &v72,
      size: 0x1Cu,
      count: 2,
      pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
    idStaticList<party_t,6>::~idStaticList<party_t,6>(this: &v76);
  }
  else
  {
    v1 = 0;
    v2 = 0;
    v3 = session->GetGameLobbyBase(this: session);
    if ( v3->GetNumLobbyUsers(this: v3) > 0 )
    {
      do
      {
        v4 = session->GetGameLobbyBase(this: session);
        v5 = session->GetGameLobbyBase(this: session);
        v6 = v4;
        v7 = v4->GetLobbyUserIdByOrdinal;
        v8 = v5->__vftable;
        v9 = (idLobbyBase **)v7(this: (idLobbyBase *)v70, result: (lobbyUserID_t *)v6, a3: v2);
        if ( v8->SetLobbyUserTeam(this: *v9, a2: (lobbyUserID_t *)v9[1], a3: 0) )
          v1 = 1;
        ++v2;
        v10 = session->GetGameLobbyBase(this: session);
      }
      while ( v2 < v10->GetNumLobbyUsers(this: v10) );
    }
    if ( v1 != 0 )
    {
      v11 = session->GetGameLobbyBase(this: session);
      v11->SendLobbyUserUpdateToPeers(this: v11);
    }
  }
}


// ========================================================================
// __unwind$491540
// EA  : 0x82DA1938
// RVA : 0x00DA1938
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_491540()
{
  int v0; // r12

  idStaticList<party_t,6>::~idStaticList<party_t,6>(this: (idStaticList<party_t,6> *)(v0 - 608 + 224));
}


// ========================================================================
// __unwind$491541
// EA  : 0x82DA1960
// RVA : 0x00DA1960
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_491541()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(v0 - 608 + 160));
}


// ========================================================================
// __unwind$491542
// EA  : 0x82DA1988
// RVA : 0x00DA1988
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_491542()
{
  int v0; // r12

  idSortPartyBySize::~idSortPartyBySize(this: (idSortPartyBySize *)(v0 - 608 + 88));
}


// ========================================================================
// __unwind$491543
// EA  : 0x82DA19B0
// RVA : 0x00DA19B0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void _unwind_491543()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 - 608 + 96),
    size: 0x1Cu,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// ?PumpHost@idLobbyController@@AAAXXZ
// EA  : 0x82DA19E8
// RVA : 0x00DA19E8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::PumpHost(idLobbyController *this)
{
  idLobbyController::state_t state; // r10
  char v3; // r11

  if ( this->state != IN_GAME
    && session->ShouldRelaunchMigrationGame(this: session)
    && idLobbyController::CanLaunchGame(this) )
  {
    idLobbyController::SetState(this, s: IN_GAME);
    session->StartMatch(this: session);
  }
  state = this->state;
  if ( this->state == 0 || (v3 = 1, state == IN_GAME) )
    v3 = 0;
  if ( v3 != 0 )
  {
    idLobbyController::PumpState(this);
    idLobbyController::EvalSkipVote(this);
    idLobbyController::PumpMainMenu(this);
    idLobbyController::UpdatePeers(this);
    idLobbyController::BalanceTeams(this);
  }
  else if ( state == 0 )
  {
    idLobbyController::UpdatePeers(this);
  }
}


// ========================================================================
// ?Pump@idLobbyController@@QAAXXZ
// EA  : 0x82DA1AE0
// RVA : 0x00DA1AE0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __fastcall idLobbyController::Pump(idLobbyController *this)
{
  idLobbyBase *v2; // r3

  v2 = session->GetGameLobbyBase(this: session);
  if ( v2->IsHost(this: v2) != 0 )
    idLobbyController::PumpHost(this);
  else
    idLobbyController::DisplaySecondsRemaining(this, seconds: this->serverRemainingSecUntilLaunch);
}


// ========================================================================
// `dynamic initializer for 'lobby_IntermissionSecMax''
// EA  : 0x83384CA8
// RVA : 0x01384CA8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lobby_IntermissionSecMax__()
{
  idCVar::idCVar(
    this: &lobby_IntermissionSecMax,
    name: "lobby_IntermissionSecMax",
    value: "20",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lobby_IntermissionSecMax__);
}


// ========================================================================
// `dynamic initializer for 'lobby_IntermissionSecMin''
// EA  : 0x83384D00
// RVA : 0x01384D00
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lobby_IntermissionSecMin__()
{
  idCVar::idCVar(
    this: &lobby_IntermissionSecMin,
    name: "lobby_IntermissionSecMin",
    value: "20",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lobby_IntermissionSecMin__);
}


// ========================================================================
// `dynamic initializer for 'lobby_FinalCountdownSec''
// EA  : 0x83384D58
// RVA : 0x01384D58
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lobby_FinalCountdownSec__()
{
  idCVar::idCVar(
    this: &lobby_FinalCountdownSec,
    name: "lobby_FinalCountdownSec",
    value: "3",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lobby_FinalCountdownSec__);
}


// ========================================================================
// `dynamic initializer for 'lobby_MinPlayersToStartGame''
// EA  : 0x83384DB0
// RVA : 0x01384DB0
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lobby_MinPlayersToStartGame__()
{
  idCVar::idCVar(
    this: &lobby_MinPlayersToStartGame,
    name: "lobby_MinPlayersToStartGame",
    value: "3",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lobby_MinPlayersToStartGame__);
}


// ========================================================================
// `dynamic initializer for 'lobby_MinPlayersToStartGameCoop''
// EA  : 0x83384E08
// RVA : 0x01384E08
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lobby_MinPlayersToStartGameCoop__()
{
  idCVar::idCVar(
    this: &lobby_MinPlayersToStartGameCoop,
    name: "lobby_MinPlayersToStartGameCoop",
    value: "1",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lobby_MinPlayersToStartGameCoop__);
}


// ========================================================================
// `dynamic initializer for 'lobby_MinPlayersToStartCoundown''
// EA  : 0x83384E60
// RVA : 0x01384E60
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lobby_MinPlayersToStartCoundown__()
{
  idCVar::idCVar(
    this: &lobby_MinPlayersToStartCoundown,
    name: "lobby_MinPlayersToStartCoundown",
    value: "3",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lobby_MinPlayersToStartCoundown__);
}


// ========================================================================
// `dynamic initializer for 'lobby_MinPlayersToStartCoundownCoop''
// EA  : 0x83384EB8
// RVA : 0x01384EB8
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lobby_MinPlayersToStartCoundownCoop__()
{
  idCVar::idCVar(
    this: &lobby_MinPlayersToStartCoundownCoop,
    name: "lobby_MinPlayersToStartCoundownCoop",
    value: "1",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lobby_MinPlayersToStartCoundownCoop__);
}


// ========================================================================
// `dynamic initializer for 'lobby_ForceStart''
// EA  : 0x83384F10
// RVA : 0x01384F10
// PDB : w:\tech5\tungsten\game\lobbycontroller.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__lobby_ForceStart__()
{
  idCVar::idCVar(
    this: &lobby_ForceStart,
    name: "lobby_ForceStart",
    value: "0",
    flags: 2,
    description: &byte_8200D768,
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__lobby_ForceStart__);
}

