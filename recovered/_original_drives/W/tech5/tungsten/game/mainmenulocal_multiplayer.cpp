
// ========================================================================
// IsInPlatformParty
// EA  : 0x82DBE5F0
// RVA : 0x00DBE5F0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

int __fastcall IsInPlatformParty()
{
  idLocalUser *v0; // r3
  idLocalUser *v1; // r31
  bool v3; // r3
  unsigned __int8 v4; // r11

  v0 = common->GetMasterLocalUser(this: common);
  v1 = v0;
  if ( v0 != nullptr )
  {
    if ( !v0->IsInParty(this: v0) )
      return 0;
    if ( v1->GetPartyCount(this: v1) <= 1 )
      return 0;
    v3 = session->IsPlatformPartyInLobby(this: session);
    v4 = 1;
    if ( v3 )
      return 0;
    return v4;
  }
  else
  {
    idLib::Warning(fmt: "Couldn't find local user");
    return 0;
  }
}


// ========================================================================
// ?HackForPatchFindBetterFix_ClearMatchResults@@YAXXZ
// EA  : 0x82DBE6C8
// RVA : 0x00DBE6C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall HackForPatchFindBetterFix_ClearMatchResults()
{
  playerMatchResults[0].shouldShowMatchResults = false;
  playerMatchResults[1].shouldShowMatchResults = false;
}


// ========================================================================
// ?HandleLobbyUpdate@idMainMenu@@QAAXAAVidBitMsg@@@Z
// EA  : 0x82DBE6E8
// RVA : 0x00DBE6E8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::HandleLobbyUpdate(idMainMenu *this, idBitMsg *msg)
{
  idLobbyController::RecvUpdate(this: this->lobbyController, msg);
}


// ========================================================================
// ?HandleLobbyVote@idMainMenu@@QAAXAAVidBitMsg@@H@Z
// EA  : 0x82DBE6F0
// RVA : 0x00DBE6F0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::HandleLobbyVote(idMainMenu *this, idBitMsg *msg, int peer)
{
  idLobbyController::RecvVote(this: this->lobbyController, msg, peer);
}


// ========================================================================
// ?LoadMultiplayerDecls@idMainMenu@@QAAXXZ
// EA  : 0x82DBE6F8
// RVA : 0x00DBE6F8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::LoadMultiplayerDecls(idMainMenu *this)
{
  if ( common->IsMultiplayer(this: common) )
  {
    idDeclMenuPopup::LoadAllDecls();
    idDeclMenuItem::LoadAllDecls();
    idDeclPvPMap::LoadAllDecls();
    idDeclGameMode::LoadAllDecls();
    idDeclCoopMap::LoadAllDecls();
    idDeclAccolade::LoadAllDecls();
    idDeclMetric::LoadAllDecls();
    idDeclOnlinePerk::LoadAllDecls();
    idDeclOnlineCoopScoring::LoadAllDecls();
    idDeclVehicleUnlock::LoadAllDecls();
  }
  idDeclAchievement::LoadAllDecls();
  idDeclOnlineLevel::LoadAllDecls();
}


// ========================================================================
// ?SetScoreLimit@idMainMenu@@QAAXH_N@Z
// EA  : 0x82DBE768
// RVA : 0x00DBE768
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetScoreLimit(idMainMenu *this, int newScoreLimit, bool storeDefaults)
{
  if ( storeDefaults )
    common->GetProfileFromMasterLocalUser(this: common);
  this->scoreLimit = newScoreLimit;
}


// ========================================================================
// ?SetTimeLimit@idMainMenu@@QAAXH_N@Z
// EA  : 0x82DBE7C8
// RVA : 0x00DBE7C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetTimeLimit(idMainMenu *this, int newTimeLimit, bool storeDefaults)
{
  if ( storeDefaults )
    common->GetProfileFromMasterLocalUser(this: common);
  this->timeLimit = newTimeLimit;
}


// ========================================================================
// PickRandomIndexUsingWeighted
// EA  : 0x82DBE878
// RVA : 0x00DBE878
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

int __fastcall PickRandomIndexUsingWeighted(idList<float,5> *weightings, int a2, __int64 a3)
{
  int v4; // r10
  double v5; // fp31
  int v6; // r11
  unsigned int seed; // r3
  double v8; // fp0
  int result; // r3
  int v10; // r10
  int i; // r11
  int num; // [sp+50h] [-40h]

  v4 = 0;
  num = weightings->num;
  v5 = 0.0;
  if ( num > 0 )
  {
    v6 = 0;
    do
    {
      ++v4;
      v5 = (float)(weightings->list[v6++] + (float)v5);
    }
    while ( v4 < num );
  }
  if ( (_S18_18 & 1) != 0 )
  {
    seed = random_9.seed;
  }
  else
  {
    _S18_18 |= 1u;
    seed = Sys_Milliseconds();
  }
  v8 = 0.0;
  LODWORD(a3) = ((1664525 * seed + 1013904223) >> 10) & 0x7FFF;
  random_9.seed = 1664525 * seed + 1013904223;
  result = 0;
  v10 = weightings->num;
  if ( v10 <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v8 = (float)(weightings->list[i] + (float)v8);
    if ( (float)((float)((float)a3 * (float)v5) * (float)0.000030518509) <= v8 )
      break;
    if ( ++result >= v10 )
      return 0;
  }
  return result;
}


// ========================================================================
// __unwind$500425_0
// EA  : 0x82DBE98C
// RVA : 0x00DBE98C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_500425_0()
{
  _S18_18 &= ~1u;
}


// ========================================================================
// ?EnsureValidIndexes@idMainMenu@@QBAXPAVidPlayerProfile@@@Z
// EA  : 0x82DBE9B0
// RVA : 0x00DBE9B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::EnsureValidIndexes(idMainMenu *this, idPlayerProfile *profile_)
{
  int i; // r11
  int num; // r7
  profileStatValue_t v4; // r6
  int v5; // r9
  int v6; // r11

  i = profile_[1].stats.staticList[365].i;
  if ( i < 0 || i >= this->mpMaps.num || this->mpMaps.list[i].type != 1 )
  {
    num = this->mpMaps.num;
    v4.i = -1;
    v5 = 0;
    if ( num > 0 )
    {
      v6 = 0;
      while ( this->mpMaps.list[v6].type != 1 )
      {
        ++v5;
        ++v6;
        if ( v5 >= num )
          goto LABEL_10;
      }
      v4.i = v5;
    }
LABEL_10:
    profile_[1].stats.staticList[365] = v4;
  }
}


// ========================================================================
// ?IsTeamGameMatch@idMainMenu@@QBA_NXZ
// EA  : 0x82DBEA88
// RVA : 0x00DBEA88
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

BOOL __fastcall idMainMenu::IsTeamGameMatch(idMainMenu *this)
{
  int matchMapIndex; // r10
  int matchModeIndex; // r11
  mpMap_t *v3; // r10

  matchMapIndex = this->matchMapIndex;
  if ( matchMapIndex < 0 )
    return false;
  if ( matchMapIndex >= this->mpMaps.num )
    return false;
  matchModeIndex = this->matchModeIndex;
  v3 = &this->mpMaps.list[matchMapIndex];
  return matchModeIndex >= 0 && matchModeIndex < v3->modes.num && v3->modes.list[matchModeIndex].isTeamGame;
}


// ========================================================================
// ?UpdateLeaderboard@idMainMenu@@QAAXPBVidLeaderboardCallback@@@Z
// EA  : 0x82DBEAE8
// RVA : 0x00DBEAE8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateLeaderboard(idMainMenu *this, const idLeaderboardCallback *callback)
{
  int menuState; // r11
  idLBCache *lbCache; // r3

  menuState = this->menuState;
  lbCache = this->lbCache;
  this->menuState = 3;
  this->lastMenuState = menuState;
  idLBCache::Update(this: lbCache, callback);
  if ( callback->errorCode != LEADERBOARD_ERROR_NONE
    && !idSignInManagerBase::IsMasterLocalUserOnline(this: session->signInManager) )
  {
    this->refreshWhenMasterIsOnline = true;
  }
  this->refreshLeaderboard = true;
}


// ========================================================================
// ?GetCoopPrivacy@idMainMenu@@QBA_N_N@Z
// EA  : 0x82DBEBC8
// RVA : 0x00DBEBC8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

int __fastcall idMainMenu::GetCoopPrivacy(idMainMenu *this, bool defaults)
{
  idSignInManagerBase *signInManager; // r30
  int v4; // r3
  idLocalUser *LocalUserByInputDevice; // r3
  int v6; // r3

  if ( defaults
    && (signInManager = session->signInManager,
        v4 = common->GetFocusDeviceNum(this: common),
        (LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(this: signInManager, index: v4)) != nullptr)
    && (v6 = (int)LocalUserByInputDevice->GetProfile(this: LocalUserByInputDevice)) != 0 )
  {
    return *(unsigned __int8 *)(v6 + 3588);
  }
  else
  {
    return this->coopInviteOnly;
  }
}


// ========================================================================
// ?SetCoopPrivacy@idMainMenu@@QAAX_N0@Z
// EA  : 0x82DBEC60
// RVA : 0x00DBEC60
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetCoopPrivacy(idMainMenu *this, bool newPrivacy, bool storeDefaults)
{
  idPlayerProfile *v5; // r3

  if ( storeDefaults )
  {
    v5 = common->GetProfileFromMasterLocalUser(this: common);
    if ( v5 != nullptr )
      HIBYTE(v5[1].stats.staticList[366].f) = newPrivacy;
  }
  this->coopInviteOnly = newPrivacy;
}


// ========================================================================
// ?GetCoopDifficulty@idMainMenu@@QBAH_N@Z
// EA  : 0x82DBECC8
// RVA : 0x00DBECC8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

int __fastcall idMainMenu::GetCoopDifficulty(idMainMenu *this, bool defaults)
{
  idPlayerProfile *v2; // r3

  if ( defaults && (v2 = common->GetProfileFromMasterLocalUser(this: common)) != nullptr )
    return v2[1].stats.staticList[367].i;
  else
    return idGameLocal::GetGameCoopDifficulty(this: gameLocal);
}


// ========================================================================
// ?SetCoopDifficulty@idMainMenu@@QAAXH_N@Z
// EA  : 0x82DBED30
// RVA : 0x00DBED30
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetCoopDifficulty(idMainMenu *this, int newDifficulty, bool storeDefaults)
{
  idPlayerProfile *v4; // r3

  if ( storeDefaults )
  {
    v4 = common->GetProfileFromMasterLocalUser(this: common);
    if ( v4 != nullptr )
      v4[1].stats.staticList[367].i = newDifficulty;
  }
  idGameLocal::SetGameCoopDifficulty(this: gameLocal, difficulty: newDifficulty);
}


// ========================================================================
// ?WaitForSessionState@idMainMenu@@QAAXW4sessionState_t@idSession@@@Z
// EA  : 0x82DBED98
// RVA : 0x00DBED98
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::WaitForSessionState(idMainMenu *this, idSession::sessionState_t desiredState)
{
  idSession::sessionState_t v3; // r3
  const char *v4; // r31
  const char *v5; // r3
  __int64 v6; // r8
  __int64 v7; // r10
  va *v8; // r3
  int v9; // [sp+8h] [-1078h]
  int v10; // [sp+Ch] [-1074h]
  int v11; // [sp+10h] [-1070h]
  int v12; // [sp+14h] [-106Ch]
  int v13; // [sp+18h] [-1068h]
  int v14; // [sp+1Ch] [-1064h]
  _BYTE v15[16]; // [sp+50h] [-1030h] BYREF
  va v16; // [sp+60h] [-1020h] BYREF

  while ( session->GetState(this: session) != desiredState )
  {
    session->UpdateSignInManager(this: session);
    session->Pump(this: session);
    session->ProcessSnapAckQueue(this: session);
    mgthread_sleep(ms: 10);
    v3 = session->GetState(this: session);
    if ( v3 != (PARTY_LOBBY|SEARCHING) && v3 != SEARCHING && v3 != CONNECTING && v3 != BUSY && v3 != desiredState )
    {
      v4 = session->GetStateString_2(this: session, a2: desiredState);
      v5 = session->GetStateString(this: session);
      HIDWORD(v6) = &unk_821D0000;
      v8 = va::va(
             this: &v16,
             fmt: "WaitOnSession: Invalid state (%s) while waiting on state (%s).",
             a3: __SPAIR64__((unsigned int)v5, (unsigned int)v4),
             a4: v6,
             a5: v7,
             a6: v9,
             a7: v10,
             a8: v11,
             a9: v12,
             a10: v13,
             a11: v14);
      strncpy(dest: idException::error, source: v8->buffer, count: 0x800u);
      CxxThrowException(pExceptionObject: v15, pThrowInfo: (const _s__ThrowInfo *)&TI2_AVidNetworkLoadException__);
    }
  }
}


// ========================================================================
// FormatCash
// EA  : 0x82DBF080
// RVA : 0x00DBF080
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idStr *__fastcall FormatCash(idStr *result, int a2, __int64 cash)
{
  idStr::FormatCash(result, num: a2);
  return result;
}


// ========================================================================
// ?TestPlayerProfile@idMainMenu@@QAAXXZ
// EA  : 0x82DBF0B8
// RVA : 0x00DBF0B8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::TestPlayerProfile(idMainMenu *this)
{
  idLocalUser *v1; // r3
  idLocalUser *v2; // r31
  int v3; // r3
  int v4; // r3
  int v5; // r3
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r3
  int v10; // r3
  int v11; // r3
  int v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r3
  int v16; // r28
  idResource *v17; // r24
  int v18; // r27
  idResource *v19; // r3
  idResource *v20; // r29
  int v21; // r30
  const char *LocalizedString; // r3
  const char *v23; // r3
  idStrId v24; // [sp+50h] [-50h] BYREF
  idStrId v25; // [sp+54h] [-4Ch] BYREF

  v1 = common->GetMasterLocalUser(this: common);
  v2 = v1;
  if ( v1 != nullptr )
  {
    v3 = v1->GetStatInt(this: v1, a2: 219);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_LEGENDS_COMPLETED", v3);
    v4 = v2->GetStatInt(this: v2, a2: 220);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_BEST_SCORE", v4);
    v5 = v2->GetStatInt(this: v2, a2: 221);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_SHOTS_FIRED", v5);
    v6 = v2->GetStatInt(this: v2, a2: 217);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_KILLS", v6);
    v7 = v2->GetStatInt(this: v2, a2: 223);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_HEADSHOT_KILLS", v7);
    v8 = v2->GetStatInt(this: v2, a2: 207);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_PARTNER_REVIVES", v8);
    v9 = v2->GetStatInt(this: v2, a2: 224);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_COLLECTIBLES_FOUND", v9);
    v10 = v2->GetStatInt(this: v2, a2: 201);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_VDM_COMPLETED_RALLY", v10);
    v11 = v2->GetStatInt(this: v2, a2: 202);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_VDM_COMPLETED_RALLY_FIRST", v11);
    v12 = v2->GetStatInt(this: v2, a2: 24);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_VEHICLE_FLAG_CAPTURES", v12);
    v13 = v2->GetStatInt(this: v2, a2: 228);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_RR_KILLS", v13);
    v14 = v2->GetStatInt(this: v2, a2: 229);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_RR_AWARDS_EARNED", v14);
    v15 = v2->GetStatInt(this: v2, a2: 107);
    idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_LONGEST_RALLY_CHAIN", v15);
    idLib::Printf(fmt: "\nFavorite Weapon: \n");
    v16 = -1;
    v17 = nullptr;
    v18 = 0;
    if ( idDeclMetric::resourceList.num > 0 )
    {
      do
      {
        v19 = idResourceList::Index(this: &idDeclMetric::resourceList, index: v18);
        v20 = v19;
        if ( v19 != nullptr && HIBYTE(v19[2].resourceError) != 0 && v19[1].staleCount != -1 && (int)v19[3].name.str >= 0 )
        {
          v21 = ((int (__fastcall *)(idLocalUser *))v2->GetStatInt)(a1: v2);
          v24.index = (int)v20[3].name.str;
          LocalizedString = idStrId::GetLocalizedString(this: &v24);
          idLib::Printf(fmt: "^4Weapon %s Kills: %d \n", LocalizedString, v21);
          if ( v21 > v16 )
          {
            v16 = v21;
            v17 = v20;
          }
        }
        ++v18;
      }
      while ( v18 < idDeclMetric::resourceList.num );
      if ( v17 != nullptr )
      {
        v25.index = (int)v17[3].name.str;
        v23 = idStrId::GetLocalizedString(this: &v25);
        idLib::Printf(fmt: "^3Favorite weapon: %s. Kills: %d\n", v23, v16);
      }
    }
  }
  else
  {
    idLib::Warning(fmt: "Couldn't find local user");
  }
}


// ========================================================================
// GetSessionMatchFlagsForGameType
// EA  : 0x82DBF520
// RVA : 0x00DBF520
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

int __fastcall GetSessionMatchFlagsForGameType(int gameType, bool useDefaults)
{
  int v3; // r31
  idMainMenu *mainMenu; // r30
  unsigned __int8 v5; // r31

  if ( com_multiplayer.valueInteger == 0 )
    return 0;
  v3 = 0;
  mainMenu = gameLocal->mainMenu;
  if ( gameType == 1 )
  {
    if ( !mainMenu->localMatch )
      LOBYTE(v3) = 98;
    v3 = (unsigned __int8)v3 | 1;
    if ( mainMenu->privateMatch )
      v3 = (unsigned __int8)v3 | 8;
    if ( (unsigned __int8)idMainMenu::GetCoopPrivacy(this: gameLocal->mainMenu, defaults: useDefaults) != 0 )
      return (unsigned __int8)v3 | 0x10;
  }
  else if ( gameType == 2 )
  {
    v5 = 34;
    if ( session->GetTitleStorageBool_2(this: session, a2: "joinInProgress", a3: true) )
      v5 = -94;
    if ( mp_enableJoinInProgress.valueInteger != 0 )
      v5 |= 0x80u;
    if ( mainMenu->privateMatch )
      return v5 | 8;
    else
      return v5 | 5;
  }
  return v3;
}


// ========================================================================
// ?LookupGameType@idMainMenu@@SAHVidStr@@@Z
// EA  : 0x82DBF668
// RVA : 0x00DBF668
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

int __fastcall idMainMenu::LookupGameType(idStr *strGameType)
{
  if ( (_S19_2 & 1) == 0 )
  {
    _S19_2 |= 1u;
    idStr::idStr(this: (idStr *)TYPE_TO_STRING_MAP, text: "unused");
    idStr::idStr(this: (idStr *)&TYPE_TO_STRING_MAP[1], text: "coop");
    idStr::idStr(this: (idStr *)&TYPE_TO_STRING_MAP[2], text: "vdm");
    atexit(func: (void (__fastcall *)())_idMainMenu::LookupGameType_::_2_::_dynamic_atexit_destructor_for__TYPE_TO_STRING_MAP__);
  }
  if ( idStr::Cmp(s1: TYPE_TO_STRING_MAP[1].data, s2: strGameType->data) != 0 )
  {
    idStr::FreeData(this: strGameType);
    return 2;
  }
  else
  {
    idStr::FreeData(this: strGameType);
    return 1;
  }
}


// ========================================================================
// __unwind$502721
// EA  : 0x82DBF718
// RVA : 0x00DBF718
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_502721()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: *(idStr **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$502722
// EA  : 0x82DBF740
// RVA : 0x00DBF740
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_502722()
{
  _S19_2 &= ~1u;
}


// ========================================================================
// __unwind$502723
// EA  : 0x82DBF760
// RVA : 0x00DBF760
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_502723()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)TYPE_TO_STRING_MAP);
}


// ========================================================================
// __unwind$502724
// EA  : 0x82DBF788
// RVA : 0x00DBF788
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_502724()
{
  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)&TYPE_TO_STRING_MAP[1]);
}


// ========================================================================
// ?SetMatchModeIndex@idMainMenu@@QAAXH@Z
// EA  : 0x82DBF7C0
// RVA : 0x00DBF7C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetMatchModeIndex(idMainMenu *this, int index)
{
  int matchMapIndex; // r10
  mpMap_t *v3; // r9
  int v4; // r11
  mpMapMode_t *list; // r9
  idStrId *p_name; // r30
  const char *Key; // r3
  const char *v8; // r3
  int num; // [sp+50h] [-B0h]
  idStr v10; // [sp+60h] [-A0h] BYREF
  idStr v11; // [sp+80h] [-80h] BYREF
  idStr v12; // [sp+A0h] [-60h] BYREF
  idStr v13[2]; // [sp+C0h] [-40h] BYREF

  matchMapIndex = this->matchMapIndex;
  if ( matchMapIndex >= 0 && matchMapIndex < this->mpMaps.num )
  {
    v3 = &this->mpMaps.list[matchMapIndex];
    if ( v3 != nullptr )
    {
      num = v3->modes.num;
      if ( (-num & ~num) < 0 )
      {
        v4 = num - 1;
        if ( index >= 0 )
        {
          if ( index <= v4 )
            v4 = index;
        }
        else
        {
          v4 = 0;
        }
        list = v3->modes.list;
        p_name = &list[v4].name;
        if ( p_name != nullptr )
        {
          this->matchModeIndex = v4;
          playerMatchResults[0].matchModeIndex = v4;
          playerMatchResults[1].matchModeIndex = v4;
          Key = idStrId::GetKey(this: &list[v4].name);
          idStr::idStr(this: &v10, text: Key);
          idStr::idStr(this: &v12, text: "mapLoadGameName");
          common->SetLoadScreenInfo(this: common, a2: &v12, a3: &v10);
          idStr::FreeData(this: &v12);
          idStr::FreeData(this: &v10);
          v8 = idStrId::GetKey(this: p_name + 1);
          idStr::idStr(this: v13, text: v8);
          idStr::idStr(this: &v11, text: "mapLoadGameDesc");
          common->SetLoadScreenInfo(this: common, a2: &v11, a3: v13);
          idStr::FreeData(this: &v11);
          idStr::FreeData(this: v13);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$502784
// EA  : 0x82DBF914
// RVA : 0x00DBF914
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_502784()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$502785
// EA  : 0x82DBF93C
// RVA : 0x00DBF93C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_502785()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 160));
}


// ========================================================================
// __unwind$502786
// EA  : 0x82DBF964
// RVA : 0x00DBF964
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_502786()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 192));
}


// ========================================================================
// __unwind$502787
// EA  : 0x82DBF98C
// RVA : 0x00DBF98C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_502787()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// ?InitPopupGui@idMainMenu@@QAAPAVidSWF@@PBD@Z
// EA  : 0x82DBF9C0
// RVA : 0x00DBF9C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idSWF *__fastcall idMainMenu::InitPopupGui(idMainMenu *this, char *filename)
{
  idSWF *popupGui; // r29
  idSWF *v5; // r3
  idSWF *v6; // r4

  if ( this->popupGui != nullptr )
  {
    idLib::Warning(fmt: "Previous popup existed, very bad! Deleting current to replace with new.");
    popupGui = this->popupGui;
    if ( popupGui != nullptr )
    {
      idSWF::~idSWF(this: this->popupGui);
      idMem::Free(this: &mem, ptr: popupGui, align: ALIGN_16);
    }
    this->popupGui = nullptr;
  }
  v5 = (idSWF *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                  size: 0x27Cu,
                  tag: TAG_SWF,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    v6 = idSWF::idSWF(this: v5, filename_: filename, soundWorld: this->soundWorld, atlasPurgable_: true);
  else
    v6 = nullptr;
  this->popupGui = v6;
  idMainMenu::SetupBindings(this, gui: v6);
  return this->popupGui;
}


// ========================================================================
// __unwind$503107
// EA  : 0x82DBFA88
// RVA : 0x00DBFA88
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_503107()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 144 + 80), tag: TAG_SWF);
}


// ========================================================================
// ?SetMatchMapIndex@idMainMenu@@QAAXH@Z
// EA  : 0x82DBFE00
// RVA : 0x00DBFE00
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetMatchMapIndex(idMainMenu *this, int index)
{
  int v2; // r11
  mpMap_t *v3; // r30
  int v4; // r4
  const char *Key; // r3
  const char *v6; // r3
  int num; // [sp+50h] [-B0h]
  idStr v8; // [sp+60h] [-A0h] BYREF
  idStr v9; // [sp+80h] [-80h] BYREF
  idStr v10; // [sp+A0h] [-60h] BYREF
  idStr v11[2]; // [sp+C0h] [-40h] BYREF

  num = this->mpMaps.num;
  if ( (-num & ~num) < 0 )
  {
    v2 = num - 1;
    if ( index >= 0 )
    {
      if ( index <= v2 )
        v2 = index;
    }
    else
    {
      v2 = 0;
    }
    v3 = &this->mpMaps.list[v2];
    if ( v3 != nullptr )
    {
      this->matchMapIndex = v2;
      playerMatchResults[0].matchMapIndex = v2;
      playerMatchResults[1].matchMapIndex = v2;
      v4 = v3->modes.num - 1;
      if ( this->matchModeIndex > v4 )
        idMainMenu::SetMatchModeIndex(this, index: v4);
      Key = idStrId::GetKey(this: &v3->name);
      idStr::idStr(this: &v8, text: Key);
      idStr::idStr(this: &v10, text: "mapLoadName");
      common->SetLoadScreenInfo(this: common, a2: &v10, a3: &v8);
      idStr::FreeData(this: &v10);
      idStr::FreeData(this: &v8);
      v6 = idStrId::GetKey(this: &v3->introQuote);
      idStr::idStr(this: v11, text: v6);
      idStr::idStr(this: &v9, text: "mapLoadIntroQuote");
      common->SetLoadScreenInfo(this: common, a2: &v9, a3: v11);
      idStr::FreeData(this: &v9);
      idStr::FreeData(this: v11);
      idCVar::SetInteger(this: &swf_loadScreenAlternate, newValue: v3->loadScreenAlternate, force: true);
    }
  }
}


// ========================================================================
// __unwind$503909
// EA  : 0x82DBFF4C
// RVA : 0x00DBFF4C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_503909()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 96));
}


// ========================================================================
// __unwind$503910
// EA  : 0x82DBFF74
// RVA : 0x00DBFF74
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_503910()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 160));
}


// ========================================================================
// __unwind$503911
// EA  : 0x82DBFF9C
// RVA : 0x00DBFF9C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_503911()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 192));
}


// ========================================================================
// __unwind$503912
// EA  : 0x82DBFFC4
// RVA : 0x00DBFFC4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_503912()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 128));
}


// ========================================================================
// ?SetMatchTypeIndex@idMainMenu@@QAAXH@Z
// EA  : 0x82DBFFF0
// RVA : 0x00DBFFF0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetMatchTypeIndex(idMainMenu *this, int index)
{
  idPlayerProfile *v4; // r11

  this->matchTypeIndex = index;
  v4 = common->GetProfileFromMasterLocalUser(this: common);
  if ( v4 != nullptr && index == 1 )
  {
    idMainMenu::SetMatchMapIndex(this, index: v4[1].stats.staticList[365].i);
    idMainMenu::SetMatchModeIndex(this, index: 1);
  }
}


// ========================================================================
// `idMainMenu::SetupMPMenuBindings'::`12'::idSWFScriptFunction_ShowPauseGamerCardUI::Call
// EA  : 0x82DC05E0
// RVA : 0x00DC05E0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::SetupMPMenuBindings_::_12_::idSWFScriptFunction_ShowPauseGamerCardUI::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v4; // r30
  idPresentablePlayer *PlayerPresentableByIndex; // r3
  idPresentablePlayer *v6; // r31
  lobbyUserID_t *v8; // r4
  idSession_vtbl *v9; // r31
  idPresentablePlayer *LobbyUserID; // r3
  char v11; // [sp+50h] [-30h] BYREF

  v4 = 0;
  while ( 1 )
  {
    PlayerPresentableByIndex = idClientGame::FindPlayerPresentableByIndex(this: clientGame, playerNum: v4);
    v6 = PlayerPresentableByIndex;
    if ( PlayerPresentableByIndex != nullptr
      && !PlayerPresentableByIndex->IsLocallyControlled(this: PlayerPresentableByIndex) )
    {
      break;
    }
    if ( ++v4 >= 6 )
    {
      result->type = SWF_VAR_UNDEF;
      return result;
    }
  }
  v8 = (lobbyUserID_t *)v6;
  v9 = session->__vftable;
  LobbyUserID = idPresentablePlayer::GetLobbyUserID(this: (idPresentablePlayer *)&v11, result: v8);
  v9->ShowLobbyUserGamerCardUI(
    this: (idSession *)LobbyUserID->__vftable,
    a2: *((lobbyUserID_t **)&LobbyUserID->__vftable + 1));
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::idSWFScriptFunction_startMatch::Call'::`2'::idSWFScriptFunction_Accept::Call
// EA  : 0x82DC0690
// RVA : 0x00DC0690
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::idSWFScriptFunction_startMatch::Call_::_2_::idSWFScriptFunction_Accept::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.num, a3: nullptr, a4: 0);
  session->StartMatch(this: session);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idCommonLocal::ShowDialog'::`19'::idSWFScriptFunction_Accept::Call
// EA  : 0x82DC0700
// RVA : 0x00DC0700
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idCommonLocal::ShowDialog_::_19_::idSWFScriptFunction_Accept::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.num, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Call@idSWFScriptFunction_startMatchCountdown@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0758
// RVA : 0x00DC0758
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_startMatchCountdown *__fastcall idMainMenu::idSWFScriptFunction_startMatchCountdown::Call(
        idMainMenu::idSWFScriptFunction_startMatchCountdown *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num != 0 )
    idLib::Warning(fmt: "Invalid parameters specified for startMatchCountdown", result, thisObject);
  else
    idLobbyController::StartFinalCountdown(
      this: *(idLobbyController **)(result->value.i + 3052),
      overrideCountdownMS: -1);
  this->__vftable = (idMainMenu::idSWFScriptFunction_startMatchCountdown_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_cancelMatchCountdown@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC07B8
// RVA : 0x00DC07B8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_cancelMatchCountdown *__fastcall idMainMenu::idSWFScriptFunction_cancelMatchCountdown::Call(
        idMainMenu::idSWFScriptFunction_cancelMatchCountdown *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num != 0 )
    idLib::Warning(fmt: "Invalid parameters specified for cancelMatchCountdown", result, thisObject);
  else
    idLobbyController::Reset(this: *(idLobbyController **)(result->value.i + 3052));
  this->__vftable = (idMainMenu::idSWFScriptFunction_cancelMatchCountdown_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_joinMatch@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0818
// RVA : 0x00DC0818
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_joinMatch *__fastcall idMainMenu::idSWFScriptFunction_joinMatch::Call(
        idMainMenu::idSWFScriptFunction_joinMatch *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::idSWFScriptFunction_joinMatch *v4; // r31
  idSession_vtbl *v5; // r30
  int v6; // r3

  v4 = this;
  if ( parms->num == 1 )
  {
    v5 = session->__vftable;
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
    v5->ConnectToServer(this: session, a2: v6);
    v4->__vftable = (idMainMenu::idSWFScriptFunction_joinMatch_vtbl *)4;
    return v4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_joinMatch_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_showServerGamerCardUI@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0880
// RVA : 0x00DC0880
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showServerGamerCardUI *__fastcall idMainMenu::idSWFScriptFunction_showServerGamerCardUI::Call(
        idMainMenu::idSWFScriptFunction_showServerGamerCardUI *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::idSWFScriptFunction_showServerGamerCardUI *v4; // r31
  idSession_vtbl *v5; // r30
  int v6; // r3

  v4 = this;
  if ( parms->num == 1 )
  {
    v5 = session->__vftable;
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
    v5->ShowServerGamerCardUI(this: session, a2: v6);
    v4->__vftable = (idMainMenu::idSWFScriptFunction_showServerGamerCardUI_vtbl *)4;
    return v4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_showServerGamerCardUI_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_inviteFriends@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC08E8
// RVA : 0x00DC08E8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_inviteFriends *__fastcall idMainMenu::idSWFScriptFunction_inviteFriends::Call(
        idMainMenu::idSWFScriptFunction_inviteFriends *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idLobbyBase *v5; // r3
  idLobbyBase *v6; // r3
  _DWORD *v8; // r3
  _DWORD *v9; // r6

  v5 = session->GetPartyLobbyBase(this: session);
  if ( v5->IsLobbyFull(this: v5) || (v6 = session->GetGameLobbyBase(this: session), v6->IsLobbyFull(this: v6)) )
  {
    v8 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 8u,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v8 != nullptr )
    {
      v8[1] = 0;
      v9 = v8;
      *v8 = &`idMainMenu::idSWFScriptFunction_inviteFriends::Call'::`5'::idSWFScriptFunction_Accept::`vftable';
    }
    else
    {
      v9 = nullptr;
    }
    ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD, int, const char *, int))common->AddDialog)(
      a1: common,
      a2: 118,
      a3: 1,
      a4: v9,
      a5: 0,
      a6: 1,
      a7: "idMainMenu::idSWFScriptFunction_inviteFriends::Call",
      a8: 770);
    this->__vftable = (idMainMenu::idSWFScriptFunction_inviteFriends_vtbl *)4;
    return this;
  }
  else
  {
    session->InviteFriends(this: session);
    this->__vftable = (idMainMenu::idSWFScriptFunction_inviteFriends_vtbl *)4;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_showPartySessions@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0A28
// RVA : 0x00DC0A28
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showPartySessions *__fastcall idMainMenu::idSWFScriptFunction_showPartySessions::Call(
        idMainMenu::idSWFScriptFunction_showPartySessions *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  ((void (__fastcall *)(idSession *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))session->ShowPartySessions)(
    a1: session,
    a2: result,
    a3: thisObject,
    a4: parms);
  this->__vftable = (idMainMenu::idSWFScriptFunction_showPartySessions_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_voteToSkipMap@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0A78
// RVA : 0x00DC0A78
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_voteToSkipMap *__fastcall idMainMenu::idSWFScriptFunction_voteToSkipMap::Call(
        idMainMenu::idSWFScriptFunction_voteToSkipMap *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idLobbyController::VoteToSkip(this: gameLocal->mainMenu->lobbyController);
  this->__vftable = (idMainMenu::idSWFScriptFunction_voteToSkipMap_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setPrivateMatch@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0AC8
// RVA : 0x00DC0AC8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setPrivateMatch *__fastcall idMainMenu::idSWFScriptFunction_setPrivateMatch::Call(
        idMainMenu::idSWFScriptFunction_setPrivateMatch *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r3

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToBool(this: parms->list);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setPrivateMatch_vtbl *)4;
    gameLocal->mainMenu->privateMatch = v5;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setPrivateMatch", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setPrivateMatch_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setLocalMatch@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0B48
// RVA : 0x00DC0B48
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setLocalMatch *__fastcall idMainMenu::idSWFScriptFunction_setLocalMatch::Call(
        idMainMenu::idSWFScriptFunction_setLocalMatch *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r3

  if ( parms->num == 1 )
  {
    v5 = idSWFScriptVar::ToBool(this: parms->list);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setLocalMatch_vtbl *)4;
    gameLocal->mainMenu->localMatch = v5;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setLocalMatch", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setLocalMatch_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_sendChatText@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0BD0
// RVA : 0x00DC0BD0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_sendChatText *__fastcall idMainMenu::idSWFScriptFunction_sendChatText::Call(
        idMainMenu::idSWFScriptFunction_sendChatText *this,
        idStr *result,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  int v6; // r11
  char v7; // r11
  bool v8; // zf
  idStr v10; // [sp+60h] [-40h] BYREF

  LODWORD(a5) = *(_DWORD *)(parms + 4);
  if ( (_DWORD)a5 != 1 )
    goto LABEL_7;
  result = *(idStr **)parms;
  v6 = **(_DWORD **)parms;
  if ( v6 == 1 || (v8 = v6 != 0, v7 = 0, !v8) )
    v7 = 1;
  if ( v7 != 0 )
  {
    idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v10, result, a3: parms, a4, a5);
    idClientGame::SendChatText(this: clientGame, text: &v10, messagemode: MESSAGEMODE_ALL);
    this->__vftable = (idMainMenu::idSWFScriptFunction_sendChatText_vtbl *)4;
    idStr::FreeData(this: &v10);
    return this;
  }
  else
  {
LABEL_7:
    idLib::Warning(fmt: "Invalid parameters specified for sendChatText", result, HIDWORD(parms));
    this->__vftable = (idMainMenu::idSWFScriptFunction_sendChatText_vtbl *)4;
    return this;
  }
}


// ========================================================================
// __unwind$505157
// EA  : 0x82DC0CA4
// RVA : 0x00DC0CA4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_505157()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$505154
// EA  : 0x82DC0CCC
// RVA : 0x00DC0CCC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_505154()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 160;
  if ( (*(_DWORD *)(v0 - 160 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 180));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_togglePlayerMute@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0D10
// RVA : 0x00DC0D10
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_togglePlayerMute *__fastcall idMainMenu::idSWFScriptFunction_togglePlayerMute::Call(
        idMainMenu::idSWFScriptFunction_togglePlayerMute *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v6; // r11
  bool v7; // zf
  int v8; // r29
  idLobbyBase *v9; // r3
  _DWORD v11[12]; // [sp+50h] [-30h] BYREF

  if ( parms->num != 1 )
    goto LABEL_8;
  type = parms->list->type;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v7 = type != SWF_VAR_BOOL, v6 = 0, !v7) )
    v6 = 1;
  if ( v6 != 0 )
  {
    v8 = idSWFScriptVar::ToInteger(this: parms->list);
    v9 = session->GetActivePlatformLobbyBase(this: session);
    v9->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v11, result: (lobbyUserID_t *)v9, a3: v8);
    (*(void (__fastcall **)(_DWORD, _DWORD))(*(_DWORD *)v11[0] + 452))(a1: v11[0], a2: v11[1]);
    this->__vftable = (idMainMenu::idSWFScriptFunction_togglePlayerMute_vtbl *)4;
    return this;
  }
  else
  {
LABEL_8:
    idLib::Warning(fmt: "Invalid parameters specified for togglePlayerMute");
    this->__vftable = (idMainMenu::idSWFScriptFunction_togglePlayerMute_vtbl *)4;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_showGamerCardUI@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0DF0
// RVA : 0x00DC0DF0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showGamerCardUI *__fastcall idMainMenu::idSWFScriptFunction_showGamerCardUI::Call(
        idMainMenu::idSWFScriptFunction_showGamerCardUI *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v7; // r11
  bool v8; // zf
  idLobbyBase *v9; // r28
  idSWFScriptVar *list; // r3
  idLobbyBase_vtbl *v11; // r31
  int v12; // r3
  _DWORD v14[12]; // [sp+50h] [-30h] BYREF

  if ( parms->num != 1 )
    goto LABEL_8;
  type = parms->list->type;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v8 = type != SWF_VAR_BOOL, v7 = 0, !v8) )
    v7 = 1;
  if ( v7 != 0 )
  {
    v9 = session->GetActivePlatformLobbyBase(this: session);
    list = parms->list;
    v11 = v9->__vftable;
    v12 = idSWFScriptVar::ToInteger(this: list);
    v11->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v14, result: (lobbyUserID_t *)v9, a3: v12);
    (*(void (__fastcall **)(_DWORD, _DWORD))(*(_DWORD *)v14[0] + 408))(a1: v14[0], a2: v14[1]);
    this->__vftable = (idMainMenu::idSWFScriptFunction_showGamerCardUI_vtbl *)4;
    return this;
  }
  else
  {
LABEL_8:
    idLib::Warning(fmt: "Invalid parameters specified for showGamerCardUI");
    this->__vftable = (idMainMenu::idSWFScriptFunction_showGamerCardUI_vtbl *)4;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_kickPlayer@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0ED8
// RVA : 0x00DC0ED8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_kickPlayer *__fastcall idMainMenu::idSWFScriptFunction_kickPlayer::Call(
        idMainMenu::idSWFScriptFunction_kickPlayer *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v6; // r11
  bool v7; // zf
  int v8; // r29
  idLobbyBase *v9; // r31
  idLobbyBase *v10; // r28
  idLobbyBase *v11; // r4
  lobbyUserID_t *(__fastcall *GetLobbyUserIdByOrdinal)(idLobbyBase *, lobbyUserID_t *, int); // r6
  idLobbyBase_vtbl *v13; // r31
  idLobbyBase **v14; // r3
  char v16; // [sp+50h] [-30h] BYREF

  if ( parms->num != 1 )
    goto LABEL_10;
  type = parms->list->type;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v7 = type != SWF_VAR_BOOL, v6 = 0, !v7) )
    v6 = 1;
  if ( v6 != 0 )
  {
    if ( gameLocal->mainMenu->privateMatch )
    {
      v8 = idSWFScriptVar::ToInteger(this: parms->list);
      v9 = session->GetActivePlatformLobbyBase(this: session);
      v10 = session->GetActivePlatformLobbyBase(this: session);
      v11 = v9;
      GetLobbyUserIdByOrdinal = v9->GetLobbyUserIdByOrdinal;
      v13 = v10->__vftable;
      v14 = (idLobbyBase **)GetLobbyUserIdByOrdinal(this: (idLobbyBase *)&v16, result: (lobbyUserID_t *)v11, a3: v8);
      v13->KickLobbyUser(this: *v14, a2: (lobbyUserID_t *)v14[1]);
    }
    this->__vftable = (idMainMenu::idSWFScriptFunction_kickPlayer_vtbl *)4;
    return this;
  }
  else
  {
LABEL_10:
    idLib::Warning(fmt: "Invalid parameters specified for kickPlayer");
    this->__vftable = (idMainMenu::idSWFScriptFunction_kickPlayer_vtbl *)4;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_invitePlatformParty@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC0FF8
// RVA : 0x00DC0FF8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_invitePlatformParty *__fastcall idMainMenu::idSWFScriptFunction_invitePlatformParty::Call(
        idMainMenu::idSWFScriptFunction_invitePlatformParty *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idLobbyBase *v6; // r3
  idLobbyBase *v7; // r3
  _DWORD *v8; // r3
  _DWORD *v9; // r6

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for invitePlatformParty");
    this->__vftable = (idMainMenu::idSWFScriptFunction_invitePlatformParty_vtbl *)4;
    return this;
  }
  else
  {
    v6 = session->GetPartyLobbyBase(this: session);
    if ( v6->IsLobbyFull(this: v6) || (v7 = session->GetGameLobbyBase(this: session), v7->IsLobbyFull(this: v7)) )
    {
      v8 = idMem::AllocWithLocation(
             this: &mem,
             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
             size: 8u,
             tag: TAG_SWF,
             zeroBuffer: false,
             align: ALIGN_16,
             heap: HEAP_DEFAULTHEAP);
      if ( v8 != nullptr )
      {
        v8[1] = 0;
        v9 = v8;
        *v8 = &`idMainMenu::idSWFScriptFunction_invitePlatformParty::Call'::`8'::idSWFScriptFunction_Accept::`vftable';
      }
      else
      {
        v9 = nullptr;
      }
      ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD, int, const char *, int))common->AddDialog)(
        a1: common,
        a2: 118,
        a3: 1,
        a4: v9,
        a5: 0,
        a6: 1,
        a7: "idMainMenu::idSWFScriptFunction_invitePlatformParty::Call",
        a8: 1387);
      this->__vftable = (idMainMenu::idSWFScriptFunction_invitePlatformParty_vtbl *)4;
      return this;
    }
    else
    {
      session->InviteParty(this: session);
      this->__vftable = (idMainMenu::idSWFScriptFunction_invitePlatformParty_vtbl *)4;
      return this;
    }
  }
}


// ========================================================================
// `idMainMenu::idSWFScriptFunction_invitePlatformParty::Call'::`8'::idSWFScriptFunction_Accept::Call
// EA  : 0x82DC1168
// RVA : 0x00DC1168
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::idSWFScriptFunction_invitePlatformParty::Call_::_8_::idSWFScriptFunction_Accept::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_CANNOT_INVITE_LOBBY_FULL, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setAllowFriendlyFire@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC11C0
// RVA : 0x00DC11C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setAllowFriendlyFire *__fastcall idMainMenu::idSWFScriptFunction_setAllowFriendlyFire::Call(
        idMainMenu::idSWFScriptFunction_setAllowFriendlyFire *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num == 1 )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowFriendlyFire_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setAllowFriendlyFire", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowFriendlyFire_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setAllowSpectators@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC1218
// RVA : 0x00DC1218
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setAllowSpectators *__fastcall idMainMenu::idSWFScriptFunction_setAllowSpectators::Call(
        idMainMenu::idSWFScriptFunction_setAllowSpectators *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num == 1 )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowSpectators_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setAllowSpectators", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowSpectators_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setAllowPowerups@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC1270
// RVA : 0x00DC1270
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setAllowPowerups *__fastcall idMainMenu::idSWFScriptFunction_setAllowPowerups::Call(
        idMainMenu::idSWFScriptFunction_setAllowPowerups *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num == 1 )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowPowerups_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setAllowPowerups", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowPowerups_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setAllowQuickUse@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC12C8
// RVA : 0x00DC12C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setAllowQuickUse *__fastcall idMainMenu::idSWFScriptFunction_setAllowQuickUse::Call(
        idMainMenu::idSWFScriptFunction_setAllowQuickUse *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num == 1 )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowQuickUse_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setAllowQuickUse", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowQuickUse_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setAllowSponsors@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC1320
// RVA : 0x00DC1320
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setAllowSponsors *__fastcall idMainMenu::idSWFScriptFunction_setAllowSponsors::Call(
        idMainMenu::idSWFScriptFunction_setAllowSponsors *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num == 1 )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowSponsors_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setAllowSponsors", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowSponsors_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setAllowBoost@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC1378
// RVA : 0x00DC1378
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setAllowBoost *__fastcall idMainMenu::idSWFScriptFunction_setAllowBoost::Call(
        idMainMenu::idSWFScriptFunction_setAllowBoost *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num == 1 )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowBoost_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setAllowBoost", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setAllowBoost_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_suicide@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC13D0
// RVA : 0x00DC13D0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
idMainMenu::idSWFScriptFunction_suicide *__fastcall idMainMenu::idSWFScriptFunction_suicide::Call(
        idMainMenu::idSWFScriptFunction_suicide *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r31 OVERLAPPED
  idClientGame *v6; // r3
  int v7; // r30 OVERLAPPED
  idLobbyBase *v9; // r3
  _BYTE v10[16]; // [sp+50h] [-60h] BYREF
  idBitMsg v11[2]; // [sp+60h] [-50h] BYREF

  v5 = 0;
  v6 = clientGame;
  if ( clientGame != nullptr )
  {
    v7 = 0;
    while ( (unsigned __int8)idClientGame::PlayerIndexIsLocal(this: v6, playerNum: v7) == 0 )
    {
      if ( ++v7 >= 6 )
      {
        this->__vftable = (idMainMenu::idSWFScriptFunction_suicide_vtbl *)4;
        return this;
      }
      v6 = clientGame;
    }
    v11[0].curSize = 0;
    v11[0].writeBit = 0;
    v11[0].writeData = v10;
    v11[0].readData = v10;
    v11[0].maxSize = 2;
    v11[0].readCount = 0;
    v11[0].readBit = 0;
    v11[0].allowOverflow = false;
    v11[0].overflowed = false;
    v11[0].tempValue = *(_QWORD *)&v5;
    idBitMsg::WriteBits(this: v11, value: v7, numBits: 8);
    v9 = session->GetGameLobbyBase(this: session);
    v9->SendReliable(this: v9, a2: 8, a3: v11, a4: true, a5: 255u);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_suicide_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_scrollLeaderboard@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC14C8
// RVA : 0x00DC14C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_scrollLeaderboard *__fastcall idMainMenu::idSWFScriptFunction_scrollLeaderboard::Call(
        idMainMenu::idSWFScriptFunction_scrollLeaderboard *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a5,
        int a6,
        __int64 a7)
{
  idSWFScriptVar::swfScriptVarValue_t v10; // r11
  int v11; // [sp+54h] [-2Ch]

  if ( parms->num > 0 )
  {
    v11 = (int)idSWFScriptVar::ToFloat(
                 this: parms->list,
                 a2: (int)result,
                 a3: (int)thisObject,
                 a4: (int)parms,
                 a5,
                 a6,
                 a7);
    if ( (unsigned __int8)idLBCache::Scroll(this: *(idLBCache **)(result->value.i + 900), amount: v11) != 0 )
    {
      idMainMenu::PlayScrollSound(this: (idMainMenu *)result->value.i);
      *(_BYTE *)(result->value.i + 916) = 1;
      this->__vftable = (idMainMenu::idSWFScriptFunction_scrollLeaderboard_vtbl *)4;
      return this;
    }
    LODWORD(v10.f) = result->value;
    if ( *(_BYTE *)(v10.i + 919) != 0 )
    {
      *(_BYTE *)(v10.i + 919) = 0;
      *(_BYTE *)(result->value.i + 916) = 1;
    }
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_scrollLeaderboard_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_selectLeaderboardIndex@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC1578
// RVA : 0x00DC1578
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_selectLeaderboardIndex *__fastcall idMainMenu::idSWFScriptFunction_selectLeaderboardIndex::Call(
        idMainMenu::idSWFScriptFunction_selectLeaderboardIndex *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r3
  idSWFScriptVar::swfScriptVarValue_t v7; // r11

  if ( parms->num == 1 )
  {
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
    if ( *(_DWORD *)(*(_DWORD *)(result->value.i + 900) + 148) + v6 < *(_DWORD *)(*(_DWORD *)(result->value.i + 900)
                                                                                + 140) )
    {
      LODWORD(v7.f) = result->value;
      if ( *(_DWORD *)(*(_DWORD *)(v7.i + 900) + 144) != v6 )
      {
        *(_DWORD *)(*(_DWORD *)(v7.i + 900) + 144) = v6;
        *(_BYTE *)(result->value.i + 916) = 1;
      }
    }
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_selectLeaderboardIndex_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_showLeaderboardGamerCardUI@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC1618
// RVA : 0x00DC1618
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showLeaderboardGamerCardUI *__fastcall idMainMenu::idSWFScriptFunction_showLeaderboardGamerCardUI::Call(
        idMainMenu::idSWFScriptFunction_showLeaderboardGamerCardUI *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  const idLeaderboardCallback::row_t *LeaderboardRow; // r4

  if ( parms->num == 0 )
  {
    LeaderboardRow = idLBCache::GetLeaderboardRow(
                       this: *(idLBCache **)(result->value.i + 900),
                       row: *(_DWORD *)(*(_DWORD *)(result->value.i + 900) + 144)
                     + *(_DWORD *)(*(_DWORD *)(result->value.i + 900) + 148));
    if ( LeaderboardRow != nullptr )
      idLBCache::DisplayGamerCardUI(this: *(idLBCache **)(result->value.i + 900), row: LeaderboardRow);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_showLeaderboardGamerCardUI_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setScrolling@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC1698
// RVA : 0x00DC1698
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setScrolling *__fastcall idMainMenu::idSWFScriptFunction_setScrolling::Call(
        idMainMenu::idSWFScriptFunction_setScrolling *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v6; // r3
  idSWFScriptVar::swfScriptVarValue_t v7; // r11

  if ( parms->num == 1 )
  {
    v6 = idSWFScriptVar::ToBool(this: parms->list);
    LODWORD(v7.f) = result->value;
    this->__vftable = (idMainMenu::idSWFScriptFunction_setScrolling_vtbl *)4;
    *(_BYTE *)(v7.i + 919) = v6;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_setScrolling_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_showNextUnlockPopup@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC1700
// RVA : 0x00DC1700
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showNextUnlockPopup *__fastcall idMainMenu::idSWFScriptFunction_showNextUnlockPopup::Call(
        idMainMenu::idSWFScriptFunction_showNextUnlockPopup *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for showNextUnlockPopup", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_showNextUnlockPopup_vtbl *)4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_showNextUnlockPopup_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_closePopup@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC1758
// RVA : 0x00DC1758
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_closePopup *__fastcall idMainMenu::idSWFScriptFunction_closePopup::Call(
        idMainMenu::idSWFScriptFunction_closePopup *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r10
  bool v7; // cr57
  idSWFScriptVar::swfScriptVarType type; // r11
  char v9; // r11
  bool v10; // zf

  num = parms->num;
  v7 = num > 1;
  if ( num == 1 )
  {
    type = parms->list->type;
    if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v10 = type != SWF_VAR_BOOL, v9 = 0, !v10) )
      v9 = 1;
    if ( v9 == 0 )
      goto LABEL_9;
    v7 = false;
  }
  if ( v7 )
  {
LABEL_9:
    idLib::Warning(fmt: "Invalid parameters specified for closePopup", result, thisObject);
    goto LABEL_13;
  }
  if ( num == 1 )
    *(_DWORD *)(result->value.i + 688) = idSWFScriptVar::ToInteger(this: parms->list);
  *(_BYTE *)(result->value.i + 684) = 1;
LABEL_13:
  this->__vftable = (idMainMenu::idSWFScriptFunction_closePopup_vtbl *)4;
  return this;
}


// ========================================================================
// `idMainMenu::ShowLeaveLobbyDialog'::`4'::idSWFScriptFunction_LeaveCancel::Call
// EA  : 0x82DC1818
// RVA : 0x00DC1818
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ShowLeaveLobbyDialog_::_4_::idSWFScriptFunction_LeaveCancel::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_LEAVE_WITH_PARTY, a3: nullptr, a4: 0);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// DescribeServer
// EA  : 0x82DC2580
// RVA : 0x00DC2580
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

int __fastcall DescribeServer(const serverInfo_t *server, idSWFScriptObject *obj)
{
  int type; // r11
  char v5; // r10
  const char *v7; // r4
  int map; // r11
  char v9; // r9
  int index; // r25
  int v11; // r25
  int numPlayers; // r25
  int maxPlayers; // r25
  bool joinable; // r29
  idSWFScriptVar *v15; // r3
  int mode; // r11
  mpMap_t *v17; // r28
  char v18; // r11
  bool v19; // zf
  idSWFScriptVar *v20; // r3
  idStrId v21; // [sp+50h] [-E0h] BYREF
  idStrId v22; // [sp+54h] [-DCh] BYREF
  idSWFScriptVar v23; // [sp+58h] [-D8h] BYREF
  idSWFScriptVar v24; // [sp+60h] [-D0h] BYREF
  idSWFScriptVar v25; // [sp+68h] [-C8h] BYREF
  idSWFScriptVar v26; // [sp+70h] [-C0h] BYREF
  idSWFScriptVar v27; // [sp+78h] [-B8h] BYREF
  idSWFScriptVar v28; // [sp+80h] [-B0h] BYREF
  idSWFScriptVar v29; // [sp+88h] [-A8h] BYREF
  idSWFScriptVar v30; // [sp+90h] [-A0h] BYREF
  idSWFScriptVar v31; // [sp+98h] [-98h] BYREF
  idSWFScriptVar v32; // [sp+A0h] [-90h] BYREF
  idSWFScriptVar v33; // [sp+A8h] [-88h] BYREF
  idSWFScriptVar v34; // [sp+B0h] [-80h] BYREF
  idSWFScriptVar v35; // [sp+B8h] [-78h] BYREF
  idSWFScriptVar v36; // [sp+C0h] [-70h] BYREF
  idSWFScriptVar v37; // [sp+C8h] [-68h] BYREF
  idSWFScriptVar v38; // [sp+D0h] [-60h] BYREF
  idSWFScriptVar v39; // [sp+D8h] [-58h] BYREF
  idSWFScriptVar v40; // [sp+E0h] [-50h] BYREF
  idSWFScriptVar v41[9]; // [sp+E8h] [-48h] BYREF

  type = server->type;
  if ( type == 2 || (v5 = 0, type == 1) )
    v5 = 1;
  if ( v5 == 0 )
    return 0;
  if ( type == 1 )
    v7 = "#str_online_lotw_title_alt";
  else
    v7 = "#str_online_roadrage";
  idStrId::Set(this: &v22, key: v7);
  map = server->map;
  if ( map < 0 || (v9 = 1, map >= idMainMenu::pMPMaps->num) )
    v9 = 0;
  if ( v9 != 0 )
  {
    v17 = &idMainMenu::pMPMaps->list[map];
    mode = server->mode;
    if ( mode < 0 || (v19 = mode < v17->modes.num, v18 = 1, !v19) )
      v18 = 0;
    if ( v18 == 0 )
      return 0;
    idSWFScriptVar::idSWFScriptVar(this: &v40, b: true);
    idSWFScriptObject::Set(this: obj, name: "validMap", value: &v40);
    idSWFScriptVar::Free(this: &v40);
    idSWFScriptVar::idSWFScriptVar(this: &v34, s: server->name.data);
    idSWFScriptObject::Set(this: obj, name: "gameName", value: &v34);
    idSWFScriptVar::Free(this: &v34);
    v21.index = v22.index;
    idSWFScriptVar::idSWFScriptVar(this: &v38, s: &v21);
    idSWFScriptObject::Set(this: obj, name: "gameTypeStr", value: &v38);
    idSWFScriptVar::Free(this: &v38);
    idSWFScriptVar::idSWFScriptVar(this: &v30, i: (idSWFScriptVar::swfScriptVarValue_t *)server->type);
    idSWFScriptObject::Set(this: obj, name: "gameType", value: &v30);
    idSWFScriptVar::Free(this: &v30);
    v21.index = v17->name.index;
    idSWFScriptVar::idSWFScriptVar(this: &v31, s: &v21);
    idSWFScriptObject::Set(this: obj, name: "gameMap", value: &v31);
    idSWFScriptVar::Free(this: &v31);
    if ( server->type == 1 )
    {
      v21.index = v22.index;
      idSWFScriptVar::idSWFScriptVar(this: &v33, s: &v21);
      idSWFScriptObject::Set(this: obj, name: "gameMode", value: &v33);
      v20 = &v33;
    }
    else
    {
      v21.index = v17->modes.list[server->mode].name.index;
      idSWFScriptVar::idSWFScriptVar(this: &v35, s: &v21);
      idSWFScriptObject::Set(this: obj, name: "gameMode", value: &v35);
      v20 = &v35;
    }
    idSWFScriptVar::Free(this: v20);
    idSWFScriptVar::idSWFScriptVar(this: &v37, i: (idSWFScriptVar::swfScriptVarValue_t *)server->numPlayers);
    idSWFScriptObject::Set(this: obj, name: "numPlayers", value: &v37);
    idSWFScriptVar::Free(this: &v37);
    idSWFScriptVar::idSWFScriptVar(this: &v39, i: (idSWFScriptVar::swfScriptVarValue_t *)server->maxPlayers);
    idSWFScriptObject::Set(this: obj, name: "maxPlayers", value: &v39);
    idSWFScriptVar::Free(this: &v39);
    idSWFScriptVar::idSWFScriptVar(this: v41, b: server->joinable);
    idSWFScriptObject::Set(this: obj, name: "joinable", value: v41);
    v15 = v41;
  }
  else
  {
    v25.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v25);
    v25.value.b = false;
    v25.type = SWF_VAR_BOOL;
    idSWFScriptObject::Set(this: obj, name: "validMap", value: &v25);
    idSWFScriptVar::Free(this: &v25);
    idSWFScriptVar::idSWFScriptVar(this: &v32, s: server->name.data);
    idSWFScriptObject::Set(this: obj, name: "gameName", value: &v32);
    idSWFScriptVar::Free(this: &v32);
    v23.type = SWF_VAR_UNDEF;
    index = v22.index;
    idSWFScriptVar::Free(this: &v23);
    v23.value.i = index;
    v23.type = SWF_VAR_STRINGID;
    idSWFScriptObject::Set(this: obj, name: "gameTypeStr", value: &v23);
    idSWFScriptVar::Free(this: &v23);
    v27.type = SWF_VAR_UNDEF;
    v11 = server->type;
    idSWFScriptVar::Free(this: &v27);
    v27.value.i = v11;
    v27.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: obj, name: "gameType", value: &v27);
    idSWFScriptVar::Free(this: &v27);
    idSWFScriptVar::idSWFScriptVar(this: &v36, s: "#str_online_in_lobby");
    idSWFScriptObject::Set(this: obj, name: "gameMap", value: &v36);
    idSWFScriptVar::Free(this: &v36);
    idSWFScriptVar::idSWFScriptVar(this: &v29, s: &byte_8200D768);
    idSWFScriptObject::Set(this: obj, name: "gameMode", value: &v29);
    idSWFScriptVar::Free(this: &v29);
    v24.type = SWF_VAR_UNDEF;
    numPlayers = server->numPlayers;
    idSWFScriptVar::Free(this: &v24);
    v24.value.i = numPlayers;
    v24.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: obj, name: "numPlayers", value: &v24);
    idSWFScriptVar::Free(this: &v24);
    v26.type = SWF_VAR_UNDEF;
    maxPlayers = server->maxPlayers;
    idSWFScriptVar::Free(this: &v26);
    v26.value.i = maxPlayers;
    v26.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: obj, name: "maxPlayers", value: &v26);
    idSWFScriptVar::Free(this: &v26);
    v28.type = SWF_VAR_UNDEF;
    joinable = server->joinable;
    idSWFScriptVar::Free(this: &v28);
    v28.value.b = joinable;
    v28.type = SWF_VAR_BOOL;
    idSWFScriptObject::Set(this: obj, name: "joinable", value: &v28);
    v15 = &v28;
  }
  idSWFScriptVar::Free(this: v15);
  return 1;
}


// ========================================================================
// __unwind$507401
// EA  : 0x82DC29F4
// RVA : 0x00DC29F4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507401()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 104));
}


// ========================================================================
// __unwind$507402
// EA  : 0x82DC2A1C
// RVA : 0x00DC2A1C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507402()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 160));
}


// ========================================================================
// __unwind$507403
// EA  : 0x82DC2A44
// RVA : 0x00DC2A44
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507403()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 88));
}


// ========================================================================
// __unwind$507404
// EA  : 0x82DC2A6C
// RVA : 0x00DC2A6C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507404()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 120));
}


// ========================================================================
// __unwind$507405
// EA  : 0x82DC2A94
// RVA : 0x00DC2A94
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507405()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 192));
}


// ========================================================================
// __unwind$507406
// EA  : 0x82DC2ABC
// RVA : 0x00DC2ABC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507406()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 136));
}


// ========================================================================
// __unwind$507407
// EA  : 0x82DC2AE4
// RVA : 0x00DC2AE4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507407()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 96));
}


// ========================================================================
// __unwind$507408
// EA  : 0x82DC2B0C
// RVA : 0x00DC2B0C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507408()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$507409
// EA  : 0x82DC2B34
// RVA : 0x00DC2B34
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507409()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 128));
}


// ========================================================================
// __unwind$507410
// EA  : 0x82DC2B5C
// RVA : 0x00DC2B5C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507410()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 224));
}


// ========================================================================
// __unwind$507411
// EA  : 0x82DC2B84
// RVA : 0x00DC2B84
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507411()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 176));
}


// ========================================================================
// __unwind$507412
// EA  : 0x82DC2BAC
// RVA : 0x00DC2BAC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507412()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 208));
}


// ========================================================================
// __unwind$507413
// EA  : 0x82DC2BD4
// RVA : 0x00DC2BD4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507413()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 144));
}


// ========================================================================
// __unwind$507414
// EA  : 0x82DC2BFC
// RVA : 0x00DC2BFC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507414()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 152));
}


// ========================================================================
// __unwind$507415
// EA  : 0x82DC2C24
// RVA : 0x00DC2C24
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507415()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 168));
}


// ========================================================================
// __unwind$507416
// EA  : 0x82DC2C4C
// RVA : 0x00DC2C4C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507416()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 184));
}


// ========================================================================
// __unwind$507417
// EA  : 0x82DC2C74
// RVA : 0x00DC2C74
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507417()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 200));
}


// ========================================================================
// __unwind$507418
// EA  : 0x82DC2C9C
// RVA : 0x00DC2C9C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507418()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 216));
}


// ========================================================================
// __unwind$507419
// EA  : 0x82DC2CC4
// RVA : 0x00DC2CC4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507419()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 304 + 232));
}


// ========================================================================
// FormatColumn
// EA  : 0x82DC2CF8
// RVA : 0x00DC2CF8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall FormatColumn(idSWFScriptVar *result, const columnDef_t *columnDef, __int64 score)
{
  statsColumnDisplayType_t displayType; // r11
  idSWFScriptVar::swfScriptVarValue_t v5; // r29
  idStr *v6; // r3
  idStr *v7; // r3
  const idStr *v8; // r29
  idStr v10; // [sp+60h] [-60h] BYREF
  idStr v11[2]; // [sp+80h] [-40h] BYREF

  displayType = columnDef->displayType;
  v5.f = *(float *)&score;
  if ( displayType == STATS_COLUMN_DISPLAY_TIME_MILLISECONDS )
  {
    v8 = FormatTime(result: v11, time: score);
    result->type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: result);
    result->type = SWF_VAR_STRING;
    result->value.i = (int)idSWFScriptString::Alloc(s: v8);
    v7 = v11;
    goto LABEL_6;
  }
  if ( displayType == STATS_COLUMN_DISPLAY_CASH )
  {
    v6 = FormatCash(result: &v10, a2: SHIDWORD(score), cash: score);
    idSWFScriptVar::idSWFScriptVar(this: result, s: v6);
    v7 = &v10;
LABEL_6:
    idStr::FreeData(this: v7);
    return result;
  }
  result->type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: result);
  result->value = v5;
  result->type = SWF_VAR_INTEGER;
  return result;
}


// ========================================================================
// __unwind$507728
// EA  : 0x82DC2DB0
// RVA : 0x00DC2DB0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507728()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$507724
// EA  : 0x82DC2DD8
// RVA : 0x00DC2DD8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507724()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 128));
}


// ========================================================================
// ?SetupMPMenuBindings@idMainMenu@@QAAXPAVidSWF@@@Z
// EA  : 0x82DC2E08
// RVA : 0x00DC2E08
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetupMPMenuBindings(idMainMenu *this, idSWF *gui)
{
  idSWFScriptVar::swfScriptVarValue_t v4; // r24
  idList<idVehicleState *,5> *p_coopLeaderboards; // r30
  int i; // r26
  idResource *v7; // r3
  idAtomicString *p_name; // r22
  int v9; // r21
  int v10; // r25
  int *v11; // r11
  int v12; // r10
  int v13; // r9
  _DWORD *v14; // r3
  idMainMenu::coopLeaderboard_t v15; // [sp+50h] [-4A0h] BYREF
  idStrId v16; // [sp+5Ch] [-494h] BYREF
  idSWFScriptVar v17; // [sp+60h] [-490h] BYREF
  idSWFScriptVar v18; // [sp+68h] [-488h] BYREF
  idSWFScriptVar v19; // [sp+70h] [-480h] BYREF
  idSWFScriptVar v20; // [sp+78h] [-478h] BYREF
  idSWFScriptVar v21; // [sp+80h] [-470h] BYREF
  idSWFScriptVar v22; // [sp+88h] [-468h] BYREF
  idSWFScriptVar v23; // [sp+90h] [-460h] BYREF
  idSWFScriptVar v24; // [sp+98h] [-458h] BYREF
  idSWFScriptVar v25; // [sp+A0h] [-450h] BYREF
  idSWFScriptVar v26; // [sp+A8h] [-448h] BYREF
  idSWFScriptVar v27; // [sp+B0h] [-440h] BYREF
  idSWFScriptVar v28; // [sp+B8h] [-438h] BYREF
  idSWFScriptVar v29; // [sp+C0h] [-430h] BYREF
  idSWFScriptVar v30; // [sp+C8h] [-428h] BYREF
  idSWFScriptVar v31; // [sp+D0h] [-420h] BYREF
  idSWFScriptVar v32; // [sp+D8h] [-418h] BYREF
  idSWFScriptVar v33; // [sp+E0h] [-410h] BYREF
  idSWFScriptVar v34; // [sp+E8h] [-408h] BYREF
  idSWFScriptVar v35; // [sp+F0h] [-400h] BYREF
  idSWFScriptVar v36; // [sp+F8h] [-3F8h] BYREF
  idSWFScriptVar v37; // [sp+100h] [-3F0h] BYREF
  idSWFScriptVar v38; // [sp+108h] [-3E8h] BYREF
  idSWFScriptVar v39; // [sp+110h] [-3E0h] BYREF
  idSWFScriptVar v40; // [sp+118h] [-3D8h] BYREF
  idSWFScriptVar v41; // [sp+120h] [-3D0h] BYREF
  idSWFScriptVar v42; // [sp+128h] [-3C8h] BYREF
  idSWFScriptVar v43; // [sp+130h] [-3C0h] BYREF
  idSWFScriptVar v44; // [sp+138h] [-3B8h] BYREF
  idSWFScriptVar v45; // [sp+140h] [-3B0h] BYREF
  idSWFScriptVar v46; // [sp+148h] [-3A8h] BYREF
  idSWFScriptVar v47; // [sp+150h] [-3A0h] BYREF
  idSWFScriptVar v48; // [sp+158h] [-398h] BYREF
  idStrId v49; // [sp+160h] [-390h] BYREF
  idStrId v50; // [sp+164h] [-38Ch] BYREF
  idStrId v51; // [sp+168h] [-388h] BYREF
  idSWFScriptVar v52; // [sp+170h] [-380h] BYREF
  idSWFScriptVar v53; // [sp+178h] [-378h] BYREF
  idSWFScriptVar v54; // [sp+180h] [-370h] BYREF
  idSWFScriptVar v55; // [sp+188h] [-368h] BYREF
  idSWFScriptVar v56; // [sp+190h] [-360h] BYREF
  idSWFScriptVar v57; // [sp+198h] [-358h] BYREF
  idSWFScriptVar v58; // [sp+1A0h] [-350h] BYREF
  idSWFScriptVar v59; // [sp+1A8h] [-348h] BYREF
  idSWFScriptVar v60; // [sp+1B0h] [-340h] BYREF
  idSWFScriptVar v61; // [sp+1B8h] [-338h] BYREF
  idSWFScriptVar v62; // [sp+1C0h] [-330h] BYREF
  idSWFScriptVar v63; // [sp+1C8h] [-328h] BYREF
  idSWFScriptVar v64; // [sp+1D0h] [-320h] BYREF
  idSWFScriptVar v65; // [sp+1D8h] [-318h] BYREF
  idSWFScriptVar v66; // [sp+1E0h] [-310h] BYREF
  idSWFScriptVar v67; // [sp+1E8h] [-308h] BYREF
  idSWFScriptVar v68; // [sp+1F0h] [-300h] BYREF
  idSWFScriptVar v69; // [sp+1F8h] [-2F8h] BYREF
  idSWFScriptVar v70; // [sp+200h] [-2F0h] BYREF
  idSWFScriptVar v71; // [sp+208h] [-2E8h] BYREF
  idSWFScriptVar v72; // [sp+210h] [-2E0h] BYREF
  idSWFScriptVar v73; // [sp+218h] [-2D8h] BYREF
  idSWFScriptVar v74; // [sp+220h] [-2D0h] BYREF
  idSWFScriptVar v75; // [sp+228h] [-2C8h] BYREF
  idSWFScriptVar v76; // [sp+230h] [-2C0h] BYREF
  idSWFScriptVar v77; // [sp+238h] [-2B8h] BYREF
  idSWFScriptVar v78; // [sp+240h] [-2B0h] BYREF
  idSWFScriptVar v79; // [sp+248h] [-2A8h] BYREF
  idSWFScriptVar v80; // [sp+250h] [-2A0h] BYREF
  idSWFScriptVar v81; // [sp+258h] [-298h] BYREF
  idSWFScriptVar v82; // [sp+260h] [-290h] BYREF
  idSWFScriptVar v83; // [sp+268h] [-288h] BYREF
  idSWFScriptVar v84; // [sp+270h] [-280h] BYREF
  idSWFScriptVar v85; // [sp+278h] [-278h] BYREF
  idSWFScriptVar v86; // [sp+280h] [-270h] BYREF
  idSWFScriptVar v87; // [sp+288h] [-268h] BYREF
  idSWFScriptVar v88; // [sp+290h] [-260h] BYREF
  idSWFScriptVar v89; // [sp+298h] [-258h] BYREF
  idSWFScriptVar v90; // [sp+2A0h] [-250h] BYREF
  idSWFScriptVar v91; // [sp+2A8h] [-248h] BYREF
  idSWFScriptVar v92; // [sp+2B0h] [-240h] BYREF
  idSWFScriptVar v93; // [sp+2B8h] [-238h] BYREF
  idSWFScriptVar v94; // [sp+2C0h] [-230h] BYREF
  idSWFScriptVar v95; // [sp+2C8h] [-228h] BYREF
  idSWFScriptVar v96; // [sp+2D0h] [-220h] BYREF
  idSWFScriptVar v97; // [sp+2D8h] [-218h] BYREF
  idSWFScriptVar v98; // [sp+2E0h] [-210h] BYREF
  idSWFScriptVar v99; // [sp+2E8h] [-208h] BYREF
  idSWFScriptVar v100; // [sp+2F0h] [-200h] BYREF
  idSWFScriptVar v101; // [sp+2F8h] [-1F8h] BYREF
  idSWFScriptVar v102; // [sp+300h] [-1F0h] BYREF
  idSWFScriptVar v103; // [sp+308h] [-1E8h] BYREF
  idSWFScriptVar v104; // [sp+310h] [-1E0h] BYREF
  idSWFScriptVar v105; // [sp+318h] [-1D8h] BYREF
  idSWFScriptVar v106; // [sp+320h] [-1D0h] BYREF
  idSWFScriptVar v107; // [sp+328h] [-1C8h] BYREF
  idSWFScriptVar v108; // [sp+330h] [-1C0h] BYREF
  idSWFScriptVar v109; // [sp+338h] [-1B8h] BYREF
  idSWFScriptVar v110; // [sp+340h] [-1B0h] BYREF
  idSWFScriptVar v111; // [sp+348h] [-1A8h] BYREF
  idSWFScriptVar v112; // [sp+350h] [-1A0h] BYREF
  idSWFScriptVar v113; // [sp+358h] [-198h] BYREF
  idSWFScriptVar v114; // [sp+360h] [-190h] BYREF
  idSWFScriptVar v115; // [sp+368h] [-188h] BYREF
  idSWFScriptVar v116; // [sp+370h] [-180h] BYREF
  idSWFScriptVar v117; // [sp+378h] [-178h] BYREF
  idSWFScriptVar v118; // [sp+380h] [-170h] BYREF
  idSWFScriptVar v119; // [sp+388h] [-168h] BYREF
  idSWFScriptVar v120; // [sp+390h] [-160h] BYREF
  idSWFScriptVar v121; // [sp+398h] [-158h] BYREF
  idSWFScriptVar v122; // [sp+3A0h] [-150h] BYREF
  idSWFScriptVar v123; // [sp+3A8h] [-148h] BYREF
  idSWFScriptVar v124; // [sp+3B0h] [-140h] BYREF
  idSWFScriptVar v125; // [sp+3B8h] [-138h] BYREF
  idSWFScriptVar v126; // [sp+3C0h] [-130h] BYREF
  idSWFScriptVar v127; // [sp+3C8h] [-128h] BYREF
  idSWFScriptVar v128; // [sp+3D0h] [-120h] BYREF
  idSWFScriptVar v129; // [sp+3D8h] [-118h] BYREF
  idSWFScriptVar v130; // [sp+3E0h] [-110h] BYREF
  idSWFScriptVar v131; // [sp+3E8h] [-108h] BYREF
  idSWFScriptVar v132; // [sp+3F0h] [-100h] BYREF
  idSWFScriptVar v133; // [sp+3F8h] [-F8h] BYREF
  idSWFScriptVar v134; // [sp+400h] [-F0h] BYREF
  idSWFScriptVar v135; // [sp+408h] [-E8h] BYREF
  idSWFScriptVar v136; // [sp+410h] [-E0h] BYREF
  idSWFScriptVar v137; // [sp+418h] [-D8h] BYREF
  idSWFScriptVar v138; // [sp+420h] [-D0h] BYREF
  idSWFScriptVar v139; // [sp+428h] [-C8h] BYREF
  idSWFScriptVar v140; // [sp+430h] [-C0h] BYREF
  idSWFScriptVar v141; // [sp+438h] [-B8h] BYREF
  idSWFScriptVar v142; // [sp+440h] [-B0h] BYREF
  idSWFScriptVar v143; // [sp+448h] [-A8h] BYREF
  idSWFScriptVar v144; // [sp+450h] [-A0h] BYREF
  idSWFScriptVar v145; // [sp+458h] [-98h] BYREF
  idSWFScriptVar v146; // [sp+460h] [-90h] BYREF
  idSWFScriptVar v147; // [sp+468h] [-88h] BYREF
  idSWFScriptVar v148; // [sp+470h] [-80h] BYREF
  idSWFScriptVar v149; // [sp+478h] [-78h] BYREF
  idSWFScriptVar v150[14]; // [sp+480h] [-70h] BYREF

  idSWFScriptVar::idSWFScriptVar(this: &v83, s: &byte_8200D768);
  idSWFScriptObject::Set(this: gui->globals, name: "mpusers", value: &v83);
  idSWFScriptVar::Free(this: &v83);
  idSWFScriptVar::idSWFScriptVar(this: v150, s: &byte_8200D768);
  idSWFScriptObject::Set(this: gui->globals, name: "mpstatus", value: v150);
  idSWFScriptVar::Free(this: v150);
  idSWFScriptVar::idSWFScriptVar(this: &v147, s: &byte_8200D768);
  idSWFScriptObject::Set(this: gui->globals, name: "mpnumplayers", value: &v147);
  idSWFScriptVar::Free(this: &v147);
  idSWFScriptVar::idSWFScriptVar(this: &v55, s: &byte_8200D768);
  idSWFScriptObject::Set(this: gui->globals, name: "mpmap", value: &v55);
  idSWFScriptVar::Free(this: &v55);
  idSWFScriptVar::idSWFScriptVar(this: &v103, s: &byte_8200D768);
  idSWFScriptObject::Set(this: gui->globals, name: "mpmode", value: &v103);
  idSWFScriptVar::Free(this: &v103);
  v20.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v20);
  v20.type = SWF_VAR_INTEGER;
  v20.value.i = 6;
  idSWFScriptObject::Set(this: gui->globals, name: "MAX_GAMEMODES", value: &v20);
  idSWFScriptVar::Free(this: &v20);
  v35.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v35);
  v4.i = 0;
  v35.type = SWF_VAR_INTEGER;
  v35.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "GAME_LOBBY", value: &v35);
  idSWFScriptVar::Free(this: &v35);
  v23.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v23);
  v23.type = SWF_VAR_INTEGER;
  v23.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "SELECTING_MAP", value: &v23);
  idSWFScriptVar::Free(this: &v23);
  v45.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v45);
  v45.type = SWF_VAR_INTEGER;
  v45.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "SELECTING_GAMEMODE", value: &v45);
  idSWFScriptVar::Free(this: &v45);
  v25.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v25);
  v25.type = SWF_VAR_INTEGER;
  v25.value.i = 3;
  idSWFScriptObject::Set(this: gui->globals, name: "VIEWING_LEADERBOARD", value: &v25);
  idSWFScriptVar::Free(this: &v25);
  v37.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v37);
  v37.type = SWF_VAR_INTEGER;
  v37.value.i = 4;
  idSWFScriptObject::Set(this: gui->globals, name: "LOADING_LEADERBOARD", value: &v37);
  idSWFScriptVar::Free(this: &v37);
  v27.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v27);
  v27.type = SWF_VAR_INTEGER;
  v27.value.i = 5;
  idSWFScriptObject::Set(this: gui->globals, name: "MAX_STATES", value: &v27);
  idSWFScriptVar::Free(this: &v27);
  v43.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v43);
  v43.type = SWF_VAR_INTEGER;
  v43.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "GAME_TYPE_COOP", value: &v43);
  idSWFScriptVar::Free(this: &v43);
  v29.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v29);
  v29.type = SWF_VAR_INTEGER;
  v29.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "GAME_TYPE_PVP", value: &v29);
  idSWFScriptVar::Free(this: &v29);
  v39.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v39);
  v39.type = SWF_VAR_INTEGER;
  v39.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "LEADERBOARD_FILTER_OVERALL", value: &v39);
  idSWFScriptVar::Free(this: &v39);
  v31.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v31);
  v31.type = SWF_VAR_INTEGER;
  v31.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "LEADERBOARD_FILTER_MYSCORE", value: &v31);
  idSWFScriptVar::Free(this: &v31);
  v47.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v47);
  v47.type = SWF_VAR_INTEGER;
  v47.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "LEADERBOARD_FILTER_FRIENDS", value: &v47);
  idSWFScriptVar::Free(this: &v47);
  v33.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v33);
  v33.type = SWF_VAR_INTEGER;
  v33.value.i = 219;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_COOP_LEGENDS_COMPLETED", value: &v33);
  idSWFScriptVar::Free(this: &v33);
  v18.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v18);
  v18.type = SWF_VAR_INTEGER;
  v18.value.i = 220;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_COOP_BEST_SCORE", value: &v18);
  idSWFScriptVar::Free(this: &v18);
  v41.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v41);
  v41.type = SWF_VAR_INTEGER;
  v41.value.i = 221;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_COOP_SHOTS_FIRED", value: &v41);
  idSWFScriptVar::Free(this: &v41);
  v19.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v19);
  v19.type = SWF_VAR_INTEGER;
  v19.value.i = 217;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_COOP_KILLS", value: &v19);
  idSWFScriptVar::Free(this: &v19);
  v22.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v22);
  v22.type = SWF_VAR_INTEGER;
  v22.value.i = 223;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_COOP_HEADSHOT_KILLS", value: &v22);
  idSWFScriptVar::Free(this: &v22);
  v24.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v24);
  v24.type = SWF_VAR_INTEGER;
  v24.value.i = 207;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_PARTNER_REVIVES", value: &v24);
  idSWFScriptVar::Free(this: &v24);
  v26.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v26);
  v26.type = SWF_VAR_INTEGER;
  v26.value.i = 224;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_COOP_COLLECTIBLES_FOUND", value: &v26);
  idSWFScriptVar::Free(this: &v26);
  v28.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v28);
  v28.type = SWF_VAR_INTEGER;
  v28.value.i = 201;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_VDM_COMPLETED_RALLY", value: &v28);
  idSWFScriptVar::Free(this: &v28);
  v30.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v30);
  v30.type = SWF_VAR_INTEGER;
  v30.value.i = 202;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_VDM_COMPLETED_RALLY_FIRST", value: &v30);
  idSWFScriptVar::Free(this: &v30);
  v32.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v32);
  v32.type = SWF_VAR_INTEGER;
  v32.value.i = 24;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_VEHICLE_FLAG_CAPTURES", value: &v32);
  idSWFScriptVar::Free(this: &v32);
  v34.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v34);
  v34.type = SWF_VAR_INTEGER;
  v34.value.i = 228;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_RR_KILLS", value: &v34);
  idSWFScriptVar::Free(this: &v34);
  v36.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v36);
  v36.type = SWF_VAR_INTEGER;
  v36.value.i = 229;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_RR_AWARDS_EARNED", value: &v36);
  idSWFScriptVar::Free(this: &v36);
  v38.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v38);
  v38.type = SWF_VAR_INTEGER;
  v38.value.i = 230;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_RR_ODO_GROUND", value: &v38);
  idSWFScriptVar::Free(this: &v38);
  v40.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v40);
  v40.type = SWF_VAR_INTEGER;
  v40.value.i = 107;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_LONGEST_RALLY_CHAIN", value: &v40);
  idSWFScriptVar::Free(this: &v40);
  v42.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v42);
  v42.type = SWF_VAR_INTEGER;
  v42.value.i = 41;
  idSWFScriptObject::Set(this: gui->globals, name: "RAGE_STAT_VEHICLE_RALLY_CAPTURES", value: &v42);
  idSWFScriptVar::Free(this: &v42);
  v44.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v44);
  v44.type = SWF_VAR_INTEGER;
  v44.value.i = 0;
  idSWFScriptObject::Set(this: gui->globals, name: "VOICECHAT_DISPLAY_NONE", value: &v44);
  idSWFScriptVar::Free(this: &v44);
  v46.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v46);
  v46.type = SWF_VAR_INTEGER;
  v46.value.i = 1;
  idSWFScriptObject::Set(this: gui->globals, name: "VOICECHAT_DISPLAY_NOTTALKING", value: &v46);
  idSWFScriptVar::Free(this: &v46);
  v48.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v48);
  v48.type = SWF_VAR_INTEGER;
  v48.value.i = 2;
  idSWFScriptObject::Set(this: gui->globals, name: "VOICECHAT_DISPLAY_TALKING", value: &v48);
  idSWFScriptVar::Free(this: &v48);
  v21.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v21);
  v21.type = SWF_VAR_INTEGER;
  v21.value.i = 4;
  idSWFScriptObject::Set(this: gui->globals, name: "VOICECHAT_DISPLAY_MUTED", value: &v21);
  idSWFScriptVar::Free(this: &v21);
  this->scriptFunction_createTeamLobby.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v57, nf: &this->scriptFunction_createTeamLobby);
  idSWFScriptObject::Set(this: gui->globals, name: "createTeamLobby", value: &v57);
  idSWFScriptVar::Free(this: &v57);
  this->scriptFunction_createGameLobby.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v127, nf: &this->scriptFunction_createGameLobby);
  idSWFScriptObject::Set(this: gui->globals, name: "createGameLobby", value: &v127);
  idSWFScriptVar::Free(this: &v127);
  this->scriptFunction_autoJoinGameLobby.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v59, nf: &this->scriptFunction_autoJoinGameLobby);
  idSWFScriptObject::Set(this: gui->globals, name: "autoJoinGameLobby", value: &v59);
  idSWFScriptVar::Free(this: &v59);
  this->scriptFunction_isInGameLobby.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v105, nf: &this->scriptFunction_isInGameLobby);
  idSWFScriptObject::Set(this: gui->globals, name: "isInGameLobby", value: &v105);
  idSWFScriptVar::Free(this: &v105);
  this->scriptFunction_startMatch.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v61, nf: &this->scriptFunction_startMatch);
  idSWFScriptObject::Set(this: gui->globals, name: "startMatch", value: &v61);
  idSWFScriptVar::Free(this: &v61);
  this->scriptFunction_startMatchCountdown.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v139, nf: &this->scriptFunction_startMatchCountdown);
  idSWFScriptObject::Set(this: gui->globals, name: "startMatchCountdown", value: &v139);
  idSWFScriptVar::Free(this: &v139);
  this->scriptFunction_cancelMatch.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v63, nf: &this->scriptFunction_cancelMatch);
  idSWFScriptObject::Set(this: gui->globals, name: "cancelMatch", value: &v63);
  idSWFScriptVar::Free(this: &v63);
  this->scriptFunction_cancelMatchCountdown.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v107, nf: &this->scriptFunction_cancelMatchCountdown);
  idSWFScriptObject::Set(this: gui->globals, name: "cancelMatchCountdown", value: &v107);
  idSWFScriptVar::Free(this: &v107);
  this->scriptFunction_joinMatch.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v65, nf: &this->scriptFunction_joinMatch);
  idSWFScriptObject::Set(this: gui->globals, name: "joinMatch", value: &v65);
  idSWFScriptVar::Free(this: &v65);
  this->scriptFunction_showServerGamerCardUI.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v129, nf: &this->scriptFunction_showServerGamerCardUI);
  idSWFScriptObject::Set(this: gui->globals, name: "showServerGamerCardUI", value: &v129);
  idSWFScriptVar::Free(this: &v129);
  this->scriptFunction_inviteFriends.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v67, nf: &this->scriptFunction_inviteFriends);
  idSWFScriptObject::Set(this: gui->globals, name: "inviteFriends", value: &v67);
  idSWFScriptVar::Free(this: &v67);
  this->scriptFunction_showPartySessions.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v109, nf: &this->scriptFunction_showPartySessions);
  idSWFScriptObject::Set(this: gui->globals, name: "showPartySessions", value: &v109);
  idSWFScriptVar::Free(this: &v109);
  this->scriptFunction_getMatchType.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v69, nf: &this->scriptFunction_getMatchType);
  idSWFScriptObject::Set(this: gui->globals, name: "getMatchType", value: &v69);
  idSWFScriptVar::Free(this: &v69);
  this->scriptFunction_setMatchType.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v145, nf: &this->scriptFunction_setMatchType);
  idSWFScriptObject::Set(this: gui->globals, name: "setMatchType", value: &v145);
  idSWFScriptVar::Free(this: &v145);
  this->scriptFunction_isPeer.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v71, nf: &this->scriptFunction_isPeer);
  idSWFScriptObject::Set(this: gui->globals, name: "isPeer", value: &v71);
  idSWFScriptVar::Free(this: &v71);
  this->scriptFunction_isPartyPeer.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v111, nf: &this->scriptFunction_isPartyPeer);
  idSWFScriptObject::Set(this: gui->globals, name: "isPartyPeer", value: &v111);
  idSWFScriptVar::Free(this: &v111);
  this->scriptFunction_updateLanServerList.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v73, nf: &this->scriptFunction_updateLanServerList);
  idSWFScriptObject::Set(this: gui->globals, name: "updateLanServerList", value: &v73);
  idSWFScriptVar::Free(this: &v73);
  this->scriptFunction_isLobbyFull.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v131, nf: &this->scriptFunction_isLobbyFull);
  idSWFScriptObject::Set(this: gui->globals, name: "isLobbyFull", value: &v131);
  idSWFScriptVar::Free(this: &v131);
  this->scriptFunction_showVoteResults.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v75, nf: &this->scriptFunction_showVoteResults);
  idSWFScriptObject::Set(this: gui->globals, name: "showVoteResults", value: &v75);
  idSWFScriptVar::Free(this: &v75);
  this->scriptFunction_voteToSkipMap.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v113, nf: &this->scriptFunction_voteToSkipMap);
  idSWFScriptObject::Set(this: gui->globals, name: "voteToSkipMap", value: &v113);
  idSWFScriptVar::Free(this: &v113);
  this->scriptFunction_getMapList.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v77, nf: &this->scriptFunction_getMapList);
  idSWFScriptObject::Set(this: gui->globals, name: "getMapList", value: &v77);
  idSWFScriptVar::Free(this: &v77);
  this->scriptFunction_getGameMapAvailable.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v141, nf: &this->scriptFunction_getGameMapAvailable);
  idSWFScriptObject::Set(this: gui->globals, name: "getGameMapAvailable", value: &v141);
  idSWFScriptVar::Free(this: &v141);
  this->scriptFunction_getMatchMap.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v79, nf: &this->scriptFunction_getMatchMap);
  idSWFScriptObject::Set(this: gui->globals, name: "getMatchMap", value: &v79);
  idSWFScriptVar::Free(this: &v79);
  this->scriptFunction_setMatchMap.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v115, nf: &this->scriptFunction_setMatchMap);
  idSWFScriptObject::Set(this: gui->globals, name: "setMatchMap", value: &v115);
  idSWFScriptVar::Free(this: &v115);
  this->scriptFunction_updateMapSelection.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v81, nf: &this->scriptFunction_updateMapSelection);
  idSWFScriptObject::Set(this: gui->globals, name: "updateMapSelection", value: &v81);
  idSWFScriptVar::Free(this: &v81);
  this->scriptFunction_getModeList.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v133, nf: &this->scriptFunction_getModeList);
  idSWFScriptObject::Set(this: gui->globals, name: "getModeList", value: &v133);
  idSWFScriptVar::Free(this: &v133);
  this->scriptFunction_getGameModeAvailable.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v52, nf: &this->scriptFunction_getGameModeAvailable);
  idSWFScriptObject::Set(this: gui->globals, name: "getGameModeAvailable", value: &v52);
  idSWFScriptVar::Free(this: &v52);
  this->scriptFunction_getMatchMode.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v117, nf: &this->scriptFunction_getMatchMode);
  idSWFScriptObject::Set(this: gui->globals, name: "getMatchMode", value: &v117);
  idSWFScriptVar::Free(this: &v117);
  this->scriptFunction_setMatchMode.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v85, nf: &this->scriptFunction_setMatchMode);
  idSWFScriptObject::Set(this: gui->globals, name: "setMatchMode", value: &v85);
  idSWFScriptVar::Free(this: &v85);
  this->scriptFunction_joinQuickMatch.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v149, nf: &this->scriptFunction_joinQuickMatch);
  idSWFScriptObject::Set(this: gui->globals, name: "joinQuickMatch", value: &v149);
  idSWFScriptVar::Free(this: &v149);
  this->scriptFunction_setPrivateMatch.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v87, nf: &this->scriptFunction_setPrivateMatch);
  idSWFScriptObject::Set(this: gui->globals, name: "setPrivateMatch", value: &v87);
  idSWFScriptVar::Free(this: &v87);
  this->scriptFunction_isPrivateMatch.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v119, nf: &this->scriptFunction_isPrivateMatch);
  idSWFScriptObject::Set(this: gui->globals, name: "isPrivateMatch", value: &v119);
  idSWFScriptVar::Free(this: &v119);
  this->scriptFunction_setLocalMatch.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v89, nf: &this->scriptFunction_setLocalMatch);
  idSWFScriptObject::Set(this: gui->globals, name: "setLocalMatch", value: &v89);
  idSWFScriptVar::Free(this: &v89);
  this->scriptFunction_isLocalMatch.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v135, nf: &this->scriptFunction_isLocalMatch);
  idSWFScriptObject::Set(this: gui->globals, name: "isLocalMatch", value: &v135);
  idSWFScriptVar::Free(this: &v135);
  this->scriptFunction_updateModeSelection.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v91, nf: &this->scriptFunction_updateModeSelection);
  idSWFScriptObject::Set(this: gui->globals, name: "updateModeSelection", value: &v91);
  idSWFScriptVar::Free(this: &v91);
  this->scriptFunction_sendChatText.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v121, nf: &this->scriptFunction_sendChatText);
  idSWFScriptObject::Set(this: gui->globals, name: "sendChatText", value: &v121);
  idSWFScriptVar::Free(this: &v121);
  this->scriptFunction_togglePlayerMute.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v93, nf: &this->scriptFunction_togglePlayerMute);
  idSWFScriptObject::Set(this: gui->globals, name: "togglePlayerMute", value: &v93);
  idSWFScriptVar::Free(this: &v93);
  this->scriptFunction_showGamerCardUI.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v143, nf: &this->scriptFunction_showGamerCardUI);
  idSWFScriptObject::Set(this: gui->globals, name: "showGamerCardUI", value: &v143);
  idSWFScriptVar::Free(this: &v143);
  this->scriptFunction_kickPlayer.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v95, nf: &this->scriptFunction_kickPlayer);
  idSWFScriptObject::Set(this: gui->globals, name: "kickPlayer", value: &v95);
  idSWFScriptVar::Free(this: &v95);
  this->scriptFunction_isInPlatformParty.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v123, nf: &this->scriptFunction_isInPlatformParty);
  idSWFScriptObject::Set(this: gui->globals, name: "isInPlatformParty", value: &v123);
  idSWFScriptVar::Free(this: &v123);
  this->scriptFunction_invitePlatformParty.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v97, nf: &this->scriptFunction_invitePlatformParty);
  idSWFScriptObject::Set(this: gui->globals, name: "invitePlatformParty", value: &v97);
  idSWFScriptVar::Free(this: &v97);
  this->scriptFunction_loadProfileData.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v137, nf: &this->scriptFunction_loadProfileData);
  idSWFScriptObject::Set(this: gui->globals, name: "loadProfileData", value: &v137);
  idSWFScriptVar::Free(this: &v137);
  this->scriptFunction_changeTeam.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v99, nf: &this->scriptFunction_changeTeam);
  idSWFScriptObject::Set(this: gui->globals, name: "changeTeam", value: &v99);
  idSWFScriptVar::Free(this: &v99);
  this->scriptFunction_isGameModeTeam.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v125, nf: &this->scriptFunction_isGameModeTeam);
  idSWFScriptObject::Set(this: gui->globals, name: "isGameModeTeam", value: &v125);
  idSWFScriptVar::Free(this: &v125);
  this->scriptFunction_loadScrollingControlValues.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v101, nf: &this->scriptFunction_loadScrollingControlValues);
  idSWFScriptObject::Set(this: gui->globals, name: "loadScrollingControlValues", value: &v101);
  idSWFScriptVar::Free(this: &v101);
  this->scriptFunction_getTimeLimit.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v53, nf: &this->scriptFunction_getTimeLimit);
  idSWFScriptObject::Set(this: gui->globals, name: "getTimeLimit", value: &v53);
  idSWFScriptVar::Free(this: &v53);
  this->scriptFunction_setTimeLimit.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v54, nf: &this->scriptFunction_setTimeLimit);
  idSWFScriptObject::Set(this: gui->globals, name: "setTimeLimit", value: &v54);
  idSWFScriptVar::Free(this: &v54);
  this->scriptFunction_getScoreLimit.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v56, nf: &this->scriptFunction_getScoreLimit);
  idSWFScriptObject::Set(this: gui->globals, name: "getScoreLimit", value: &v56);
  idSWFScriptVar::Free(this: &v56);
  this->scriptFunction_setScoreLimit.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v58, nf: &this->scriptFunction_setScoreLimit);
  idSWFScriptObject::Set(this: gui->globals, name: "setScoreLimit", value: &v58);
  idSWFScriptVar::Free(this: &v58);
  this->scriptFunction_getCoopDifficulty.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v60, nf: &this->scriptFunction_getCoopDifficulty);
  idSWFScriptObject::Set(this: gui->globals, name: "getCoopDifficulty", value: &v60);
  idSWFScriptVar::Free(this: &v60);
  this->scriptFunction_setCoopDifficulty.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v62, nf: &this->scriptFunction_setCoopDifficulty);
  idSWFScriptObject::Set(this: gui->globals, name: "setCoopDifficulty", value: &v62);
  idSWFScriptVar::Free(this: &v62);
  this->scriptFunction_getSessionCoopDifficulty.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v64, nf: &this->scriptFunction_getSessionCoopDifficulty);
  idSWFScriptObject::Set(this: gui->globals, name: "getSessionCoopDifficulty", value: &v64);
  idSWFScriptVar::Free(this: &v64);
  this->scriptFunction_getCOOPPrivacy.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v66, nf: &this->scriptFunction_getCOOPPrivacy);
  idSWFScriptObject::Set(this: gui->globals, name: "getCOOPPrivacy", value: &v66);
  idSWFScriptVar::Free(this: &v66);
  this->scriptFunction_setCOOPPrivacy.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v68, nf: &this->scriptFunction_setCOOPPrivacy);
  idSWFScriptObject::Set(this: gui->globals, name: "setCOOPPrivacy", value: &v68);
  idSWFScriptVar::Free(this: &v68);
  this->scriptFunction_shouldPrivacyBeVisible.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v70, nf: &this->scriptFunction_shouldPrivacyBeVisible);
  idSWFScriptObject::Set(this: gui->globals, name: "shouldPrivacyBeVisible", value: &v70);
  idSWFScriptVar::Free(this: &v70);
  this->scriptFunction_getAllowFriendlyFire.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v72, nf: &this->scriptFunction_getAllowFriendlyFire);
  idSWFScriptObject::Set(this: gui->globals, name: "getAllowFriendlyFire", value: &v72);
  idSWFScriptVar::Free(this: &v72);
  this->scriptFunction_setAllowFriendlyFire.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v74, nf: &this->scriptFunction_setAllowFriendlyFire);
  idSWFScriptObject::Set(this: gui->globals, name: "setAllowFriendlyFire", value: &v74);
  idSWFScriptVar::Free(this: &v74);
  this->scriptFunction_getAllowSpectators.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v76, nf: &this->scriptFunction_getAllowSpectators);
  idSWFScriptObject::Set(this: gui->globals, name: "getAllowSpectators", value: &v76);
  idSWFScriptVar::Free(this: &v76);
  this->scriptFunction_setAllowSpectators.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v78, nf: &this->scriptFunction_setAllowSpectators);
  idSWFScriptObject::Set(this: gui->globals, name: "setAllowSpectators", value: &v78);
  idSWFScriptVar::Free(this: &v78);
  this->scriptFunction_getAllowPowerups.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v80, nf: &this->scriptFunction_getAllowPowerups);
  idSWFScriptObject::Set(this: gui->globals, name: "getAllowPowerups", value: &v80);
  idSWFScriptVar::Free(this: &v80);
  this->scriptFunction_setAllowPowerups.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v82, nf: &this->scriptFunction_setAllowPowerups);
  idSWFScriptObject::Set(this: gui->globals, name: "setAllowPowerups", value: &v82);
  idSWFScriptVar::Free(this: &v82);
  this->scriptFunction_getAllowQuickUse.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v84, nf: &this->scriptFunction_getAllowQuickUse);
  idSWFScriptObject::Set(this: gui->globals, name: "getAllowQuickUse", value: &v84);
  idSWFScriptVar::Free(this: &v84);
  this->scriptFunction_setAllowQuickUse.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v86, nf: &this->scriptFunction_setAllowQuickUse);
  idSWFScriptObject::Set(this: gui->globals, name: "setAllowQuickUse", value: &v86);
  idSWFScriptVar::Free(this: &v86);
  this->scriptFunction_getAllowSponsors.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v88, nf: &this->scriptFunction_getAllowSponsors);
  idSWFScriptObject::Set(this: gui->globals, name: "getAllowSponsors", value: &v88);
  idSWFScriptVar::Free(this: &v88);
  this->scriptFunction_setAllowSponsors.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v90, nf: &this->scriptFunction_setAllowSponsors);
  idSWFScriptObject::Set(this: gui->globals, name: "setAllowSponsors", value: &v90);
  idSWFScriptVar::Free(this: &v90);
  this->scriptFunction_getAllowBoost.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v92, nf: &this->scriptFunction_getAllowBoost);
  idSWFScriptObject::Set(this: gui->globals, name: "getAllowBoost", value: &v92);
  idSWFScriptVar::Free(this: &v92);
  this->scriptFunction_setAllowBoost.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v94, nf: &this->scriptFunction_setAllowBoost);
  idSWFScriptObject::Set(this: gui->globals, name: "setAllowBoost", value: &v94);
  idSWFScriptVar::Free(this: &v94);
  this->scriptFunction_suicide.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v96, nf: &this->scriptFunction_suicide);
  idSWFScriptObject::Set(this: gui->globals, name: "suicide", value: &v96);
  idSWFScriptVar::Free(this: &v96);
  this->scriptFunction_getPlayerLevelTitle.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v98, nf: &this->scriptFunction_getPlayerLevelTitle);
  idSWFScriptObject::Set(this: gui->globals, name: "getPlayerLevelTitle", value: &v98);
  idSWFScriptVar::Free(this: &v98);
  this->scriptFunction_getAccoladeInfo.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v100, nf: &this->scriptFunction_getAccoladeInfo);
  idSWFScriptObject::Set(this: gui->globals, name: "getAccoladeInfo", value: &v100);
  idSWFScriptVar::Free(this: &v100);
  this->scriptFunction_getAccoladeCount.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v102, nf: &this->scriptFunction_getAccoladeCount);
  idSWFScriptObject::Set(this: gui->globals, name: "getAccoladeCount", value: &v102);
  idSWFScriptVar::Free(this: &v102);
  this->scriptFunction_selectAccolade.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v104, nf: &this->scriptFunction_selectAccolade);
  idSWFScriptObject::Set(this: gui->globals, name: "selectAccolade", value: &v104);
  idSWFScriptVar::Free(this: &v104);
  this->scriptFunction_drawPlayerInfo.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v106, nf: &this->scriptFunction_drawPlayerInfo);
  idSWFScriptObject::Set(this: gui->globals, name: "drawPlayerInfo", value: &v106);
  idSWFScriptVar::Free(this: &v106);
  this->scriptFunction_getMissionMapList.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v108, nf: &this->scriptFunction_getMissionMapList);
  idSWFScriptObject::Set(this: gui->globals, name: "getMissionMapList", value: &v108);
  idSWFScriptVar::Free(this: &v108);
  this->scriptFunction_hasNewAccolade.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v110, nf: &this->scriptFunction_hasNewAccolade);
  idSWFScriptObject::Set(this: gui->globals, name: "hasNewAccolade", value: &v110);
  idSWFScriptVar::Free(this: &v110);
  this->scriptFunction_loadMenuItems.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v112, nf: &this->scriptFunction_loadMenuItems);
  idSWFScriptObject::Set(this: gui->globals, name: "loadMenuItems", value: &v112);
  idSWFScriptVar::Free(this: &v112);
  this->scriptFunction_clearLeaderboard.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v114, nf: &this->scriptFunction_clearLeaderboard);
  idSWFScriptObject::Set(this: gui->globals, name: "clearLeaderboard", value: &v114);
  idSWFScriptVar::Free(this: &v114);
  this->scriptFunction_refreshLeaderboard.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v116, nf: &this->scriptFunction_refreshLeaderboard);
  idSWFScriptObject::Set(this: gui->globals, name: "refreshLeaderboard", value: &v116);
  idSWFScriptVar::Free(this: &v116);
  this->scriptFunction_scrollLeaderboard.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v118, nf: &this->scriptFunction_scrollLeaderboard);
  idSWFScriptObject::Set(this: gui->globals, name: "scrollLeaderboard", value: &v118);
  idSWFScriptVar::Free(this: &v118);
  this->scriptFunction_nextLeaderboard.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v120, nf: &this->scriptFunction_nextLeaderboard);
  idSWFScriptObject::Set(this: gui->globals, name: "nextLeaderboard", value: &v120);
  idSWFScriptVar::Free(this: &v120);
  this->scriptFunction_prevLeaderboard.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v122, nf: &this->scriptFunction_prevLeaderboard);
  idSWFScriptObject::Set(this: gui->globals, name: "prevLeaderboard", value: &v122);
  idSWFScriptVar::Free(this: &v122);
  this->scriptFunction_selectLeaderboardIndex.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v124, nf: &this->scriptFunction_selectLeaderboardIndex);
  idSWFScriptObject::Set(this: gui->globals, name: "selectLeaderboardIndex", value: &v124);
  idSWFScriptVar::Free(this: &v124);
  this->scriptFunction_showLeaderboardGamerCardUI.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v126, nf: &this->scriptFunction_showLeaderboardGamerCardUI);
  idSWFScriptObject::Set(this: gui->globals, name: "showLeaderboardGamerCardUI", value: &v126);
  idSWFScriptVar::Free(this: &v126);
  this->scriptFunction_toggleCoopNightmareLeaderboard.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v128, nf: &this->scriptFunction_toggleCoopNightmareLeaderboard);
  idSWFScriptObject::Set(this: gui->globals, name: "toggleCoopNightmareLeaderboard", value: &v128);
  idSWFScriptVar::Free(this: &v128);
  this->scriptFunction_isCoopNightmareLeaderboard.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v130, nf: &this->scriptFunction_isCoopNightmareLeaderboard);
  idSWFScriptObject::Set(this: gui->globals, name: "isCoopNightmareLeaderboard", value: &v130);
  idSWFScriptVar::Free(this: &v130);
  this->scriptFunction_filterList.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v132, nf: &this->scriptFunction_filterList);
  idSWFScriptObject::Set(this: gui->globals, name: "filterList", value: &v132);
  idSWFScriptVar::Free(this: &v132);
  this->scriptFunction_setScrolling.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v134, nf: &this->scriptFunction_setScrolling);
  idSWFScriptObject::Set(this: gui->globals, name: "setScrolling", value: &v134);
  idSWFScriptVar::Free(this: &v134);
  this->scriptFunction_updateScroll.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v136, nf: &this->scriptFunction_updateScroll);
  idSWFScriptObject::Set(this: gui->globals, name: "updateScroll", value: &v136);
  idSWFScriptVar::Free(this: &v136);
  this->scriptFunction_updateLbScroll.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v138, nf: &this->scriptFunction_updateLbScroll);
  idSWFScriptObject::Set(this: gui->globals, name: "updateLbScroll", value: &v138);
  idSWFScriptVar::Free(this: &v138);
  this->scriptFunction_getPostGameResults.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v140, nf: &this->scriptFunction_getPostGameResults);
  idSWFScriptObject::Set(this: gui->globals, name: "getPostGameResults", value: &v140);
  idSWFScriptVar::Free(this: &v140);
  this->scriptFunction_showMatchResultsPopup.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v142, nf: &this->scriptFunction_showMatchResultsPopup);
  idSWFScriptObject::Set(this: gui->globals, name: "showMatchResultsPopup", value: &v142);
  idSWFScriptVar::Free(this: &v142);
  this->scriptFunction_showNextUnlockPopup.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v144, nf: &this->scriptFunction_showNextUnlockPopup);
  idSWFScriptObject::Set(this: gui->globals, name: "showNextUnlockPopup", value: &v144);
  idSWFScriptVar::Free(this: &v144);
  this->scriptFunction_showPopupDialog.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v146, nf: &this->scriptFunction_showPopupDialog);
  idSWFScriptObject::Set(this: gui->globals, name: "showPopupDialog", value: &v146);
  idSWFScriptVar::Free(this: &v146);
  this->scriptFunction_closePopup.pThis = this;
  idSWFScriptVar::idSWFScriptVar(this: &v148, nf: &this->scriptFunction_closePopup);
  idSWFScriptObject::Set(this: gui->globals, name: "closePopup", value: &v148);
  idSWFScriptVar::Free(this: &v148);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->roadRageLeaderboards);
  idStrId::Set(this: &v51, key: "#str_empty");
  v15.name.index = (int)&rageLeaderboardRally;
  v15.leaderboardId = v51.index;
  idList<idMainMenu::roadRageLeaderboard_t,5>::Append(
    this: &this->roadRageLeaderboards,
    obj: (const idMainMenu::roadRageLeaderboard_t *)&v15);
  idStrId::Set(this: &v50, key: "#str_empty");
  v15.name.index = (int)&rageLeaderboardVDM;
  v15.leaderboardId = v50.index;
  idList<idMainMenu::roadRageLeaderboard_t,5>::Append(
    this: &this->roadRageLeaderboards,
    obj: (const idMainMenu::roadRageLeaderboard_t *)&v15);
  idStrId::Set(this: &v49, key: "#str_empty");
  v15.name.index = (int)&rageLeaderboardMeteor;
  v15.leaderboardId = v49.index;
  idList<idMainMenu::roadRageLeaderboard_t,5>::Append(
    this: &this->roadRageLeaderboards,
    obj: (const idMainMenu::roadRageLeaderboard_t *)&v15);
  idStrId::Set(this: &v16, key: "#str_empty");
  v15.name.index = (int)&rageLeaderboardTriad;
  v15.leaderboardId = v16.index;
  idList<idMainMenu::roadRageLeaderboard_t,5>::Append(
    this: &this->roadRageLeaderboards,
    obj: (const idMainMenu::roadRageLeaderboard_t *)&v15);
  p_coopLeaderboards = (idList<idVehicleState *,5> *)&this->coopLeaderboards;
  idList<idThread *,58>::Clear(this: p_coopLeaderboards);
  for ( i = 0; i < idDeclCoopMap::resourceList.num; ++i )
  {
    v7 = idResourceList::Index(this: &idDeclCoopMap::resourceList, index: i);
    if ( v7 != nullptr )
    {
      p_name = &v7[3].name;
      v9 = 0;
      if ( (int)v7[3].nextOnHashChain > 0 )
      {
        v10 = 0;
        do
        {
          v11 = (int *)&p_name->str[v10];
          v12 = v11[15];
          if ( v12 >= 0 )
          {
            v13 = *v11;
            v15.leaderboardId = v11[15];
            v15.nightmareLeaderboardId = v12 + 10;
            v15.name.index = v13;
            v16.index = v12;
            idList<idMainMenu::coopLeaderboard_t,5>::Append(
              this: (idList<idMainMenu::coopLeaderboard_t,5> *)p_coopLeaderboards,
              obj: &v15);
          }
          ++v9;
          v10 += 76;
        }
        while ( v9 < (int)p_name[1].str );
      }
    }
  }
  v14 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
          size: 8u,
          tag: TAG_SWF,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  if ( v14 != nullptr )
  {
    v14[1] = 0;
    v4.i = (int)v14;
    *v14 = &`idMainMenu::SetupMPMenuBindings'::`12'::idSWFScriptFunction_ShowPauseGamerCardUI::`vftable';
  }
  v17.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v17);
  if ( v4.i != 0 )
  {
    v17.value = v4;
    v17.type = SWF_VAR_FUNCTION;
    (*(void (__fastcall **)(int __struct_ptr))(*(_DWORD *)v4.i + 8))(a1: v4.i);
  }
  else
  {
    v17.type = SWF_VAR_NULL;
  }
  idSWFScriptObject::Set(this: gui->globals, name: "ShowPauseGamerCardUI", value: &v17);
  idSWFScriptVar::Free(this: &v17);
}


// ========================================================================
// __unwind$507930
// EA  : 0x82DC4760
// RVA : 0x00DC4760
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507930()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 616));
}


// ========================================================================
// __unwind$507931
// EA  : 0x82DC4788
// RVA : 0x00DC4788
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507931()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1152));
}


// ========================================================================
// __unwind$507932
// EA  : 0x82DC47B0
// RVA : 0x00DC47B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507932()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1128));
}


// ========================================================================
// __unwind$507933
// EA  : 0x82DC47D8
// RVA : 0x00DC47D8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507933()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 392));
}


// ========================================================================
// __unwind$507934
// EA  : 0x82DC4800
// RVA : 0x00DC4800
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507934()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 776));
}


// ========================================================================
// __unwind$507935
// EA  : 0x82DC4828
// RVA : 0x00DC4828
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507935()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 120));
}


// ========================================================================
// __unwind$507936
// EA  : 0x82DC4850
// RVA : 0x00DC4850
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507936()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 240));
}


// ========================================================================
// __unwind$507937
// EA  : 0x82DC4878
// RVA : 0x00DC4878
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507937()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 144));
}


// ========================================================================
// __unwind$507938
// EA  : 0x82DC48A0
// RVA : 0x00DC48A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507938()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 320));
}


// ========================================================================
// __unwind$507939
// EA  : 0x82DC48C8
// RVA : 0x00DC48C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507939()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 160));
}


// ========================================================================
// __unwind$507940
// EA  : 0x82DC48F0
// RVA : 0x00DC48F0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507940()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 256));
}


// ========================================================================
// __unwind$507941
// EA  : 0x82DC4918
// RVA : 0x00DC4918
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507941()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 176));
}


// ========================================================================
// __unwind$507942
// EA  : 0x82DC4940
// RVA : 0x00DC4940
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507942()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 304));
}


// ========================================================================
// __unwind$507943
// EA  : 0x82DC4968
// RVA : 0x00DC4968
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507943()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 192));
}


// ========================================================================
// __unwind$507944
// EA  : 0x82DC4990
// RVA : 0x00DC4990
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507944()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 272));
}


// ========================================================================
// __unwind$507945
// EA  : 0x82DC49B8
// RVA : 0x00DC49B8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507945()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 208));
}


// ========================================================================
// __unwind$507946
// EA  : 0x82DC49E0
// RVA : 0x00DC49E0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507946()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 336));
}


// ========================================================================
// __unwind$507947
// EA  : 0x82DC4A08
// RVA : 0x00DC4A08
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507947()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 224));
}


// ========================================================================
// __unwind$507948
// EA  : 0x82DC4A30
// RVA : 0x00DC4A30
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507948()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 104));
}


// ========================================================================
// __unwind$507949
// EA  : 0x82DC4A58
// RVA : 0x00DC4A58
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507949()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 288));
}


// ========================================================================
// __unwind$507950
// EA  : 0x82DC4A80
// RVA : 0x00DC4A80
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507950()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 112));
}


// ========================================================================
// __unwind$507951
// EA  : 0x82DC4AA8
// RVA : 0x00DC4AA8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507951()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 136));
}


// ========================================================================
// __unwind$507952
// EA  : 0x82DC4AD0
// RVA : 0x00DC4AD0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507952()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 152));
}


// ========================================================================
// __unwind$507953
// EA  : 0x82DC4AF8
// RVA : 0x00DC4AF8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507953()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 168));
}


// ========================================================================
// __unwind$507954_0
// EA  : 0x82DC4B20
// RVA : 0x00DC4B20
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507954_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 184));
}


// ========================================================================
// __unwind$507955
// EA  : 0x82DC4B48
// RVA : 0x00DC4B48
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507955()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 200));
}


// ========================================================================
// __unwind$507956
// EA  : 0x82DC4B70
// RVA : 0x00DC4B70
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507956()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 216));
}


// ========================================================================
// __unwind$507957
// EA  : 0x82DC4B98
// RVA : 0x00DC4B98
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507957()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 232));
}


// ========================================================================
// __unwind$507958
// EA  : 0x82DC4BC0
// RVA : 0x00DC4BC0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507958()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 248));
}


// ========================================================================
// __unwind$507959
// EA  : 0x82DC4BE8
// RVA : 0x00DC4BE8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507959()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 264));
}


// ========================================================================
// __unwind$507960
// EA  : 0x82DC4C10
// RVA : 0x00DC4C10
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507960()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 280));
}


// ========================================================================
// __unwind$507961
// EA  : 0x82DC4C38
// RVA : 0x00DC4C38
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507961()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 296));
}


// ========================================================================
// __unwind$507962
// EA  : 0x82DC4C60
// RVA : 0x00DC4C60
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507962()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 312));
}


// ========================================================================
// __unwind$507963
// EA  : 0x82DC4C88
// RVA : 0x00DC4C88
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507963()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 328));
}


// ========================================================================
// __unwind$507964
// EA  : 0x82DC4CB0
// RVA : 0x00DC4CB0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507964()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 344));
}


// ========================================================================
// __unwind$507965
// EA  : 0x82DC4CD8
// RVA : 0x00DC4CD8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507965()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 128));
}


// ========================================================================
// __unwind$507966
// EA  : 0x82DC4D00
// RVA : 0x00DC4D00
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507966()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 408));
}


// ========================================================================
// __unwind$507967
// EA  : 0x82DC4D28
// RVA : 0x00DC4D28
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507967()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 968));
}


// ========================================================================
// __unwind$507968
// EA  : 0x82DC4D50
// RVA : 0x00DC4D50
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507968()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 424));
}


// ========================================================================
// __unwind$507969
// EA  : 0x82DC4D78
// RVA : 0x00DC4D78
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507969()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 792));
}


// ========================================================================
// __unwind$507970
// EA  : 0x82DC4DA0
// RVA : 0x00DC4DA0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507970()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 440));
}


// ========================================================================
// __unwind$507971
// EA  : 0x82DC4DC8
// RVA : 0x00DC4DC8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507971()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1064));
}


// ========================================================================
// __unwind$507972
// EA  : 0x82DC4DF0
// RVA : 0x00DC4DF0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507972()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 456));
}


// ========================================================================
// __unwind$507973
// EA  : 0x82DC4E18
// RVA : 0x00DC4E18
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507973()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 808));
}


// ========================================================================
// __unwind$507974
// EA  : 0x82DC4E40
// RVA : 0x00DC4E40
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507974()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 472));
}


// ========================================================================
// __unwind$507975
// EA  : 0x82DC4E68
// RVA : 0x00DC4E68
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507975()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 984));
}


// ========================================================================
// __unwind$507976
// EA  : 0x82DC4E90
// RVA : 0x00DC4E90
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507976()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 488));
}


// ========================================================================
// __unwind$507977
// EA  : 0x82DC4EB8
// RVA : 0x00DC4EB8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507977()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 824));
}


// ========================================================================
// __unwind$507978
// EA  : 0x82DC4EE0
// RVA : 0x00DC4EE0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507978()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 504));
}


// ========================================================================
// __unwind$507979
// EA  : 0x82DC4F08
// RVA : 0x00DC4F08
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507979()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1112));
}


// ========================================================================
// __unwind$507980
// EA  : 0x82DC4F30
// RVA : 0x00DC4F30
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507980()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 520));
}


// ========================================================================
// __unwind$507981
// EA  : 0x82DC4F58
// RVA : 0x00DC4F58
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507981()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 840));
}


// ========================================================================
// __unwind$507982
// EA  : 0x82DC4F80
// RVA : 0x00DC4F80
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507982()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 536));
}


// ========================================================================
// __unwind$507983
// EA  : 0x82DC4FA8
// RVA : 0x00DC4FA8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507983()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1000));
}


// ========================================================================
// __unwind$507984
// EA  : 0x82DC4FD0
// RVA : 0x00DC4FD0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507984()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 552));
}


// ========================================================================
// __unwind$507985
// EA  : 0x82DC4FF8
// RVA : 0x00DC4FF8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507985()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 856));
}


// ========================================================================
// __unwind$507986
// EA  : 0x82DC5020
// RVA : 0x00DC5020
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507986()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 568));
}


// ========================================================================
// __unwind$507987
// EA  : 0x82DC5048
// RVA : 0x00DC5048
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507987()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1080));
}


// ========================================================================
// __unwind$507988
// EA  : 0x82DC5070
// RVA : 0x00DC5070
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507988()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 584));
}


// ========================================================================
// __unwind$507989
// EA  : 0x82DC5098
// RVA : 0x00DC5098
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507989()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 872));
}


// ========================================================================
// __unwind$507990
// EA  : 0x82DC50C0
// RVA : 0x00DC50C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507990()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 600));
}


// ========================================================================
// __unwind$507991
// EA  : 0x82DC50E8
// RVA : 0x00DC50E8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507991()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1016));
}


// ========================================================================
// __unwind$507992
// EA  : 0x82DC5110
// RVA : 0x00DC5110
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507992()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 368));
}


// ========================================================================
// __unwind$507993
// EA  : 0x82DC5138
// RVA : 0x00DC5138
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507993()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 888));
}


// ========================================================================
// __unwind$507994
// EA  : 0x82DC5160
// RVA : 0x00DC5160
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507994()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 632));
}


// ========================================================================
// __unwind$507995
// EA  : 0x82DC5188
// RVA : 0x00DC5188
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507995()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1144));
}


// ========================================================================
// __unwind$507996
// EA  : 0x82DC51B0
// RVA : 0x00DC51B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507996()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 648));
}


// ========================================================================
// __unwind$507997
// EA  : 0x82DC51D8
// RVA : 0x00DC51D8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507997()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 904));
}


// ========================================================================
// __unwind$507998
// EA  : 0x82DC5200
// RVA : 0x00DC5200
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507998()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 664));
}


// ========================================================================
// __unwind$507999
// EA  : 0x82DC5228
// RVA : 0x00DC5228
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_507999()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1032));
}


// ========================================================================
// __unwind$508000
// EA  : 0x82DC5250
// RVA : 0x00DC5250
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508000()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 680));
}


// ========================================================================
// __unwind$508001
// EA  : 0x82DC5278
// RVA : 0x00DC5278
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508001()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 920));
}


// ========================================================================
// __unwind$508002
// EA  : 0x82DC52A0
// RVA : 0x00DC52A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508002()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 696));
}


// ========================================================================
// __unwind$508003
// EA  : 0x82DC52C8
// RVA : 0x00DC52C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508003()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1096));
}


// ========================================================================
// __unwind$508004
// EA  : 0x82DC52F0
// RVA : 0x00DC52F0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508004()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 712));
}


// ========================================================================
// __unwind$508005_0
// EA  : 0x82DC5318
// RVA : 0x00DC5318
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508005_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 936));
}


// ========================================================================
// __unwind$508006
// EA  : 0x82DC5340
// RVA : 0x00DC5340
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508006()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 728));
}


// ========================================================================
// __unwind$508007
// EA  : 0x82DC5368
// RVA : 0x00DC5368
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508007()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1048));
}


// ========================================================================
// __unwind$508008
// EA  : 0x82DC5390
// RVA : 0x00DC5390
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508008()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 744));
}


// ========================================================================
// __unwind$508009
// EA  : 0x82DC53B8
// RVA : 0x00DC53B8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508009()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 952));
}


// ========================================================================
// __unwind$508010
// EA  : 0x82DC53E0
// RVA : 0x00DC53E0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508010()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 760));
}


// ========================================================================
// __unwind$508011
// EA  : 0x82DC5408
// RVA : 0x00DC5408
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508011()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 376));
}


// ========================================================================
// __unwind$508012
// EA  : 0x82DC5430
// RVA : 0x00DC5430
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508012()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 384));
}


// ========================================================================
// __unwind$508013
// EA  : 0x82DC5458
// RVA : 0x00DC5458
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508013()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 400));
}


// ========================================================================
// __unwind$508014
// EA  : 0x82DC5480
// RVA : 0x00DC5480
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508014()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 416));
}


// ========================================================================
// __unwind$508015
// EA  : 0x82DC54A8
// RVA : 0x00DC54A8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508015()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 432));
}


// ========================================================================
// __unwind$508016_0
// EA  : 0x82DC54D0
// RVA : 0x00DC54D0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508016_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 448));
}


// ========================================================================
// __unwind$508017
// EA  : 0x82DC54F8
// RVA : 0x00DC54F8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508017()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 464));
}


// ========================================================================
// __unwind$508018
// EA  : 0x82DC5520
// RVA : 0x00DC5520
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508018()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 480));
}


// ========================================================================
// __unwind$508019
// EA  : 0x82DC5548
// RVA : 0x00DC5548
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508019()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 496));
}


// ========================================================================
// __unwind$508020
// EA  : 0x82DC5570
// RVA : 0x00DC5570
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508020()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 512));
}


// ========================================================================
// __unwind$508021
// EA  : 0x82DC5598
// RVA : 0x00DC5598
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508021()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 528));
}


// ========================================================================
// __unwind$508022
// EA  : 0x82DC55C0
// RVA : 0x00DC55C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508022()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 544));
}


// ========================================================================
// __unwind$508023
// EA  : 0x82DC55E8
// RVA : 0x00DC55E8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508023()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 560));
}


// ========================================================================
// __unwind$508024
// EA  : 0x82DC5610
// RVA : 0x00DC5610
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508024()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 576));
}


// ========================================================================
// __unwind$508025
// EA  : 0x82DC5638
// RVA : 0x00DC5638
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508025()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 592));
}


// ========================================================================
// __unwind$508026
// EA  : 0x82DC5660
// RVA : 0x00DC5660
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508026()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 608));
}


// ========================================================================
// __unwind$508027
// EA  : 0x82DC5688
// RVA : 0x00DC5688
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508027()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 624));
}


// ========================================================================
// __unwind$508028
// EA  : 0x82DC56B0
// RVA : 0x00DC56B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508028()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 640));
}


// ========================================================================
// __unwind$508029
// EA  : 0x82DC56D8
// RVA : 0x00DC56D8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508029()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 656));
}


// ========================================================================
// __unwind$508030
// EA  : 0x82DC5700
// RVA : 0x00DC5700
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508030()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 672));
}


// ========================================================================
// __unwind$508031
// EA  : 0x82DC5728
// RVA : 0x00DC5728
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508031()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 688));
}


// ========================================================================
// __unwind$508032
// EA  : 0x82DC5750
// RVA : 0x00DC5750
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508032()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 704));
}


// ========================================================================
// __unwind$508033
// EA  : 0x82DC5778
// RVA : 0x00DC5778
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508033()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 720));
}


// ========================================================================
// __unwind$508034
// EA  : 0x82DC57A0
// RVA : 0x00DC57A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508034()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 736));
}


// ========================================================================
// __unwind$508035
// EA  : 0x82DC57C8
// RVA : 0x00DC57C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508035()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 752));
}


// ========================================================================
// __unwind$508036
// EA  : 0x82DC57F0
// RVA : 0x00DC57F0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508036()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 768));
}


// ========================================================================
// __unwind$508037
// EA  : 0x82DC5818
// RVA : 0x00DC5818
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508037()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 784));
}


// ========================================================================
// __unwind$508038
// EA  : 0x82DC5840
// RVA : 0x00DC5840
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508038()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 800));
}


// ========================================================================
// __unwind$508039
// EA  : 0x82DC5868
// RVA : 0x00DC5868
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508039()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 816));
}


// ========================================================================
// __unwind$508040
// EA  : 0x82DC5890
// RVA : 0x00DC5890
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508040()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 832));
}


// ========================================================================
// __unwind$508041
// EA  : 0x82DC58B8
// RVA : 0x00DC58B8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508041()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 848));
}


// ========================================================================
// __unwind$508042
// EA  : 0x82DC58E0
// RVA : 0x00DC58E0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508042()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 864));
}


// ========================================================================
// __unwind$508043
// EA  : 0x82DC5908
// RVA : 0x00DC5908
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508043()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 880));
}


// ========================================================================
// __unwind$508044
// EA  : 0x82DC5930
// RVA : 0x00DC5930
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508044()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 896));
}


// ========================================================================
// __unwind$508045
// EA  : 0x82DC5958
// RVA : 0x00DC5958
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508045()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 912));
}


// ========================================================================
// __unwind$508046_0
// EA  : 0x82DC5980
// RVA : 0x00DC5980
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508046_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 928));
}


// ========================================================================
// __unwind$508047
// EA  : 0x82DC59A8
// RVA : 0x00DC59A8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508047()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 944));
}


// ========================================================================
// __unwind$508048
// EA  : 0x82DC59D0
// RVA : 0x00DC59D0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508048()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 960));
}


// ========================================================================
// __unwind$508049
// EA  : 0x82DC59F8
// RVA : 0x00DC59F8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508049()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 976));
}


// ========================================================================
// __unwind$508050
// EA  : 0x82DC5A20
// RVA : 0x00DC5A20
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508050()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 992));
}


// ========================================================================
// __unwind$508051
// EA  : 0x82DC5A48
// RVA : 0x00DC5A48
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508051()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1008));
}


// ========================================================================
// __unwind$508052
// EA  : 0x82DC5A70
// RVA : 0x00DC5A70
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508052()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1024));
}


// ========================================================================
// __unwind$508053
// EA  : 0x82DC5A98
// RVA : 0x00DC5A98
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508053()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1040));
}


// ========================================================================
// __unwind$508054
// EA  : 0x82DC5AC0
// RVA : 0x00DC5AC0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508054()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1056));
}


// ========================================================================
// __unwind$508055
// EA  : 0x82DC5AE8
// RVA : 0x00DC5AE8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508055()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1072));
}


// ========================================================================
// __unwind$508056
// EA  : 0x82DC5B10
// RVA : 0x00DC5B10
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508056()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1088));
}


// ========================================================================
// __unwind$508057
// EA  : 0x82DC5B38
// RVA : 0x00DC5B38
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508057()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1104));
}


// ========================================================================
// __unwind$508058
// EA  : 0x82DC5B60
// RVA : 0x00DC5B60
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508058()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1120));
}


// ========================================================================
// __unwind$508059
// EA  : 0x82DC5B88
// RVA : 0x00DC5B88
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508059()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 1136));
}


// ========================================================================
// __unwind$508061
// EA  : 0x82DC5BB0
// RVA : 0x00DC5BB0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_508061()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 1264 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_isInGameLobby@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC5BD8
// RVA : 0x00DC5BD8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isInGameLobby *__fastcall idMainMenu::idSWFScriptFunction_isInGameLobby::Call(
        idMainMenu::idSWFScriptFunction_isInGameLobby *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r3
  bool v6; // r30

  v5 = ((int (__fastcall *)(idSession *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))session->GetState)(
         a1: session,
         a2: result,
         a3: thisObject,
         a4: parms);
  this->__vftable = (idMainMenu::idSWFScriptFunction_isInGameLobby_vtbl *)4;
  v6 = (_cntlzw(v5 - 5) & 0x20) != 0;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v6;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isInGameLobby_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_startMatch@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC5C58
// RVA : 0x00DC5C58
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_startMatch *__fastcall idMainMenu::idSWFScriptFunction_startMatch::Call(
        idMainMenu::idSWFScriptFunction_startMatch *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idLobbyBase *v6; // r3
  idLobbyBase *v7; // r3
  _DWORD *v8; // r3
  _DWORD *v9; // r11
  _DWORD *v10; // r3
  _DWORD *v11; // r11
  idStrStatic<256> *v12; // r3
  _DWORD *v14; // [sp+60h] [-1C0h] BYREF
  idStrId v15; // [sp+64h] [-1BCh] BYREF
  idStrId v16[2]; // [sp+68h] [-1B8h] BYREF
  idList<idVehicleState *,5> v17; // [sp+70h] [-1B0h] BYREF
  _BYTE v18[16]; // [sp+80h] [-1A0h] BYREF
  idList<enum encounterGroupRole_t,5> v19; // [sp+90h] [-190h] BYREF
  int v20; // [sp+A0h] [-180h] BYREF
  idStrStatic<256> v21; // [sp+B0h] [-170h] BYREF

  v15.index = 0;
  if ( gameLocal->mainMenu != nullptr )
  {
    v6 = session->GetGameLobbyBase(this: session);
    if ( v6->GetMatchParms(this: v6)->gameType == 1
      && (v7 = session->GetGameLobbyBase(this: session), v7->GetNumLobbyUsers(this: v7) < 2) )
    {
      v19.size = 4;
      v19.num = 0;
      v19.granularity = 1;
      v19.memTag = 5;
      v19.list = (encounterGroupRole_t *)&v20;
      v19.listStatic = 1;
      v8 = idMem::AllocWithLocation(
             this: &mem,
             location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
             size: 0xCu,
             tag: TAG_SWF,
             zeroBuffer: false,
             align: ALIGN_16,
             heap: HEAP_DEFAULTHEAP);
      if ( v8 != nullptr )
      {
        v8[1] = 0;
        v9 = v8;
        v8[2] = 110;
        *v8 = &`idMainMenu::idSWFScriptFunction_startMatch::Call'::`2'::idSWFScriptFunction_Accept::`vftable';
      }
      else
      {
        v9 = nullptr;
      }
      v14 = v9;
      idList<idAnimWebBlendTree *,5>::Append(this: &v19, obj: (encounterGroupRole_t *)&v14);
      v10 = idMem::AllocWithLocation(
              this: &mem,
              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
              size: 0xCu,
              tag: TAG_SWF,
              zeroBuffer: false,
              align: ALIGN_16,
              heap: HEAP_DEFAULTHEAP);
      if ( v10 != nullptr )
      {
        v10[1] = 0;
        v11 = v10;
        v10[2] = 110;
        *v10 = &`idMainMenu::idSWFScriptFunction_startMatch::Call'::`3'::idSWFScriptFunction_Cancel::`vftable';
      }
      else
      {
        v11 = nullptr;
      }
      v14 = v11;
      idList<idAnimWebBlendTree *,5>::Append(this: &v19, obj: (encounterGroupRole_t *)&v14);
      *(_QWORD *)&v17.num = 4;
      v17.list = (idVehicleState **)v18;
      *(_DWORD *)&v17.granularity = 66817;
      memset(v18, 255, sizeof(v18));
      idStrId::Set(this: v16, key: "#STR_SWF_ACCEPT");
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v17, obj: v16);
      idStrId::Set(this: &v15, key: "#STR_SWF_CANCEL");
      idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v17, obj: &v15);
      v12 = idStrStatic<256>::idStrStatic<256>(this: &v21, text: &byte_8200D768);
      ((void (__fastcall *)(idCommon *, int, idList<enum encounterGroupRole_t,5> *, idList<idVehicleState *,5> *, _DWORD, idStrStatic<256> *, _DWORD, _DWORD))common->AddDynamicDialog)(
        a1: common,
        a2: 110,
        a3: &v19,
        a4: &v17,
        a5: 0,
        a6: v12,
        a7: 0,
        a8: 0);
      idList<idThread *,58>::Clear(this: &v17);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v19);
    }
    else
    {
      idLobbyController::StartFinalCountdown(
        this: *(idLobbyController **)(result->value.i + 3052),
        overrideCountdownMS: 0);
    }
    this->__vftable = (idMainMenu::idSWFScriptFunction_startMatch_vtbl *)4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_startMatch_vtbl *)4;
  }
  return this;
}


// ========================================================================
// __unwind$510466
// EA  : 0x82DC5ED0
// RVA : 0x00DC5ED0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_510466()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 544 + 144));
}


// ========================================================================
// __unwind$510469
// EA  : 0x82DC5EF8
// RVA : 0x00DC5EF8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_510469()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 544 + 112));
}


// ========================================================================
// ?Call@idSWFScriptFunction_getMatchType@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC5F20
// RVA : 0x00DC5F20
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getMatchType *__fastcall idMainMenu::idSWFScriptFunction_getMatchType::Call(
        idMainMenu::idSWFScriptFunction_getMatchType *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *v5; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getMatchType", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getMatchType_vtbl *)4;
  }
  else
  {
    v5 = *(idMainMenu **)(result->value.i + 856);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getMatchType_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->pThis = v5;
    this->__vftable = (idMainMenu::idSWFScriptFunction_getMatchType_vtbl *)6;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setMatchType@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC5FA8
// RVA : 0x00DC5FA8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setMatchType *__fastcall idMainMenu::idSWFScriptFunction_setMatchType::Call(
        idMainMenu::idSWFScriptFunction_setMatchType *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *mainMenu; // r26
  int v7; // r3
  idSWFScriptVar::swfScriptVarValue_t v8; // r26
  idSWFScriptVar v10[8]; // [sp+50h] [-40h] BYREF

  v10[0].type = parms->num;
  if ( v10[0].type == SWF_VAR_STRING )
  {
    mainMenu = gameLocal->mainMenu;
    v7 = idSWFScriptVar::ToInteger(this: parms->list);
    idMainMenu::SetMatchTypeIndex(this: mainMenu, index: v7);
    v8.i = idSWFScriptVar::ToInteger(this: parms->list);
    v10[0].type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: v10);
    v10[0].value = v8;
    v10[0].type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: gameLocal->mainMenu->mainMenu->globals, name: "sessionType", value: v10);
    idSWFScriptVar::Free(this: v10);
  }
  else
  {
    idLib::Warning(fmt: "Invalid number of params for setMatchType %d", v10[0].type);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setMatchType_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$510644
// EA  : 0x82DC6078
// RVA : 0x00DC6078
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_510644()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 144 + 80));
}


// ========================================================================
// ?Call@idSWFScriptFunction_isPeer@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC60A0
// RVA : 0x00DC60A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isPeer *__fastcall idMainMenu::idSWFScriptFunction_isPeer::Call(
        idMainMenu::idSWFScriptFunction_isPeer *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  bool v5; // cr58
  idSession_vtbl *v6; // r11
  int (__fastcall ***v7)(_DWORD); // r3
  unsigned __int8 v8; // r3
  char v9; // r30
  int v10; // r3

  v5 = ((int (__fastcall *)(idSession *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))session->GetState)(
         a1: session,
         a2: result,
         a3: thisObject,
         a4: parms) == 4;
  v6 = session->__vftable;
  if ( v5 )
  {
    v7 = (int (__fastcall ***)(_DWORD))((int (*)(void))v6->GetPartyLobbyBase)();
    v8 = (**v7)(a1: v7);
    this->__vftable = (idMainMenu::idSWFScriptFunction_isPeer_vtbl *)4;
    v9 = (_cntlzw(v8) & 0x20) != 0;
  }
  else
  {
    v10 = ((int (*)(void))v6->GetGameLobbyBase)();
    v9 = (*(int (__fastcall **)(int))(*(_DWORD *)v10 + 4))(a1: v10);
    this->__vftable = (idMainMenu::idSWFScriptFunction_isPeer_vtbl *)4;
  }
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->__vftable = (idMainMenu::idSWFScriptFunction_isPeer_vtbl *)5;
  HIBYTE(this->pThis) = v9;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_isPartyPeer@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC6180
// RVA : 0x00DC6180
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isPartyPeer *__fastcall idMainMenu::idSWFScriptFunction_isPartyPeer::Call(
        idMainMenu::idSWFScriptFunction_isPartyPeer *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int (__fastcall ***v5)(_DWORD); // r3
  unsigned __int8 v6; // r3
  bool v7; // r30

  v5 = (int (__fastcall ***)(_DWORD))((int (__fastcall *)(idSession *, idSWFScriptVar *, idSWFScriptObject *, const idSWFParmList *))session->GetPartyLobbyBase)(
                                       a1: session,
                                       a2: result,
                                       a3: thisObject,
                                       a4: parms);
  v6 = (**v5)(a1: v5);
  this->__vftable = (idMainMenu::idSWFScriptFunction_isPartyPeer_vtbl *)4;
  v7 = (_cntlzw(v6) & 0x20) != 0;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v7;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isPartyPeer_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_isLobbyFull@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC6208
// RVA : 0x00DC6208
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isLobbyFull *__fastcall idMainMenu::idSWFScriptFunction_isLobbyFull::Call(
        idMainMenu::idSWFScriptFunction_isLobbyFull *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  bool v5; // cr58
  idSession_vtbl *v6; // r11
  int v7; // r3
  char v8; // r30
  idLobbyBase *v9; // r3
  bool v10; // r4

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for isLobbyFull", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_isLobbyFull_vtbl *)4;
  }
  else
  {
    v5 = ((int (__fastcall *)(idSession *, idSWFScriptVar *, idSWFScriptObject *))session->GetState)(
           a1: session,
           a2: result,
           a3: thisObject) == 5;
    v6 = session->__vftable;
    if ( v5 )
    {
      v7 = ((int (*)(void))v6->GetGameLobbyBase)();
      v8 = (*(int (__fastcall **)(int))(*(_DWORD *)v7 + 132))(a1: v7);
      this->__vftable = (idMainMenu::idSWFScriptFunction_isLobbyFull_vtbl *)4;
      idSWFScriptVar::Free((idSWFScriptVar *)this);
      HIBYTE(this->pThis) = v8;
      this->__vftable = (idMainMenu::idSWFScriptFunction_isLobbyFull_vtbl *)5;
    }
    else
    {
      if ( ((int (*)(void))v6->GetState)() == 4 )
      {
        v9 = session->GetPartyLobbyBase(this: session);
        v10 = v9->IsLobbyFull(this: v9);
      }
      else
      {
        v10 = false;
      }
      idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, b: v10);
    }
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_showVoteResults@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC6318
// RVA : 0x00DC6318
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showVoteResults *__fastcall idMainMenu::idSWFScriptFunction_showVoteResults::Call(
        idMainMenu::idSWFScriptFunction_showVoteResults *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for showVoteResults", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_showVoteResults_vtbl *)4;
  }
  else
  {
    v5 = *(_DWORD *)(*(_DWORD *)(result->value.i + 3052) + 72);
    this->__vftable = (idMainMenu::idSWFScriptFunction_showVoteResults_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idMainMenu::idSWFScriptFunction_showVoteResults_vtbl *)5;
    HIBYTE(this->pThis) = v5 != 0;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getGameMapAvailable@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC63A0
// RVA : 0x00DC63A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getGameMapAvailable *__fastcall idMainMenu::idSWFScriptFunction_getGameMapAvailable::Call(
        idMainMenu::idSWFScriptFunction_getGameMapAvailable *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms,
        int a5,
        int a6,
        int a7)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v9; // r11
  bool v10; // zf
  int v11; // r10

  if ( parms->num != 1 )
    goto LABEL_8;
  type = parms->list->type;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v10 = type != SWF_VAR_BOOL, v9 = 0, !v10) )
    v9 = 1;
  if ( v9 != 0 )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_getGameMapAvailable_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v11 = 5;
    HIBYTE(this->pThis) = 1;
  }
  else
  {
LABEL_8:
    idLib::Warning(
      fmt: "Invalid parameters specified for getGameMapAvailable",
      result,
      thisObject,
      parms,
      a5,
      a6,
      a7,
      0);
    v11 = 4;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getGameMapAvailable_vtbl *)v11;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getMatchMap@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC6448
// RVA : 0x00DC6448
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getMatchMap *__fastcall idMainMenu::idSWFScriptFunction_getMatchMap::Call(
        idMainMenu::idSWFScriptFunction_getMatchMap *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *v5; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getMatchMap", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getMatchMap_vtbl *)4;
  }
  else
  {
    v5 = *(idMainMenu **)(result->value.i + 844);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getMatchMap_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->pThis = v5;
    this->__vftable = (idMainMenu::idSWFScriptFunction_getMatchMap_vtbl *)6;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getMatchMode@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC64C8
// RVA : 0x00DC64C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getMatchMode *__fastcall idMainMenu::idSWFScriptFunction_getMatchMode::Call(
        idMainMenu::idSWFScriptFunction_getMatchMode *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *v5; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getMatchMode", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getMatchMode_vtbl *)4;
  }
  else
  {
    v5 = *(idMainMenu **)(result->value.i + 848);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getMatchMode_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->pThis = v5;
    this->__vftable = (idMainMenu::idSWFScriptFunction_getMatchMode_vtbl *)6;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_isPrivateMatch@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC6548
// RVA : 0x00DC6548
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isPrivateMatch *__fastcall idMainMenu::idSWFScriptFunction_isPrivateMatch::Call(
        idMainMenu::idSWFScriptFunction_isPrivateMatch *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  bool privateMatch; // r30

  privateMatch = gameLocal->mainMenu->privateMatch;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isPrivateMatch_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = privateMatch;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isPrivateMatch_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_isLocalMatch@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC65B0
// RVA : 0x00DC65B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isLocalMatch *__fastcall idMainMenu::idSWFScriptFunction_isLocalMatch::Call(
        idMainMenu::idSWFScriptFunction_isLocalMatch *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  bool localMatch; // r30

  localMatch = gameLocal->mainMenu->localMatch;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isLocalMatch_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = localMatch;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isLocalMatch_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_isInPlatformParty@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC6618
// RVA : 0x00DC6618
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isInPlatformParty *__fastcall idMainMenu::idSWFScriptFunction_isInPlatformParty::Call(
        idMainMenu::idSWFScriptFunction_isInPlatformParty *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r10
  char v6; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for isInPlatformParty", result, thisObject);
    v5 = 4;
  }
  else
  {
    v6 = IsInPlatformParty();
    this->__vftable = (idMainMenu::idSWFScriptFunction_isInPlatformParty_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v5 = 5;
    HIBYTE(this->pThis) = v6;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_isInPlatformParty_vtbl *)v5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_loadProfileData@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC6698
// RVA : 0x00DC6698
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_loadProfileData *__fastcall idMainMenu::idSWFScriptFunction_loadProfileData::Call(
        idMainMenu::idSWFScriptFunction_loadProfileData *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11
  idSignInManagerBase *signInManager; // r30
  int v8; // r3
  idLocalUser *LocalUserByInputDevice; // r30
  idSWFScriptVar::swfScriptVarValue_t v10; // r26
  __int64 v11; // r10
  __int64 v12; // r6
  __int64 v13; // r8
  va *v14; // r3
  int v15; // r3
  int v16; // r3
  idSWFScriptVar::swfScriptVarValue_t v17; // r24
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r8
  va *v21; // r3
  int v22; // r3
  int v23; // r3
  idSWFScriptVar::swfScriptVarValue_t v24; // r24
  __int64 v25; // r6
  __int64 v26; // r10
  __int64 v27; // r8
  va *v28; // r3
  int v29; // r3
  int v30; // r3
  idSWFScriptVar::swfScriptVarValue_t v31; // r24
  __int64 v32; // r6
  __int64 v33; // r10
  __int64 v34; // r8
  va *v35; // r3
  int v36; // r3
  int v37; // r3
  idSWFScriptVar::swfScriptVarValue_t v38; // r24
  __int64 v39; // r6
  __int64 v40; // r10
  __int64 v41; // r8
  va *v42; // r3
  int v43; // r3
  int v44; // r3
  idSWFScriptVar::swfScriptVarValue_t v45; // r24
  __int64 v46; // r6
  __int64 v47; // r10
  __int64 v48; // r8
  va *v49; // r3
  int v50; // r3
  int v51; // r3
  idSWFScriptVar::swfScriptVarValue_t v52; // r24
  __int64 v53; // r6
  __int64 v54; // r10
  __int64 v55; // r8
  va *v56; // r3
  int v57; // r3
  int v58; // r3
  idSWFScriptVar::swfScriptVarValue_t v59; // r24
  __int64 v60; // r6
  __int64 v61; // r10
  __int64 v62; // r8
  va *v63; // r3
  int v64; // r3
  int v65; // r3
  idSWFScriptVar::swfScriptVarValue_t v66; // r24
  __int64 v67; // r6
  __int64 v68; // r10
  __int64 v69; // r8
  va *v70; // r3
  int v71; // r3
  int v72; // r3
  idSWFScriptVar::swfScriptVarValue_t v73; // r24
  __int64 v74; // r6
  __int64 v75; // r10
  __int64 v76; // r8
  va *v77; // r3
  int v78; // r3
  int v79; // r3
  idSWFScriptVar::swfScriptVarValue_t v80; // r24
  __int64 v81; // r6
  __int64 v82; // r10
  __int64 v83; // r8
  va *v84; // r3
  int v85; // r3
  int v86; // r3
  idSWFScriptVar::swfScriptVarValue_t v87; // r24
  __int64 v88; // r6
  __int64 v89; // r10
  __int64 v90; // r8
  va *v91; // r3
  int v92; // r3
  int v93; // r3
  idSWFScriptVar::swfScriptVarValue_t v94; // r24
  __int64 v95; // r6
  __int64 v96; // r10
  __int64 v97; // r8
  va *v98; // r3
  int v99; // r3
  int v100; // r3
  idSWFScriptVar::swfScriptVarValue_t v101; // r24
  __int64 v102; // r6
  __int64 v103; // r10
  __int64 v104; // r8
  va *v105; // r3
  int v106; // r3
  double v107; // fp1
  __int64 v108; // r10
  __int128 v109; // r6
  __int64 v110; // r8
  va *v111; // r3
  __int64 v112; // r6
  __int64 v113; // r10
  __int64 v114; // r8
  va *v115; // r3
  idSWFScriptVar::swfScriptVarValue_t v116; // r25
  idResource *v117; // r22
  int v118; // r24
  idResource *v119; // r3
  idResource *v120; // r26
  int v121; // r3
  idSWFScriptVar::swfScriptVarValue_t v122; // r30
  int v124; // [sp+8h] [-2368h]
  int v125; // [sp+8h] [-2368h]
  int v126; // [sp+8h] [-2368h]
  int v127; // [sp+8h] [-2368h]
  int v128; // [sp+8h] [-2368h]
  int v129; // [sp+8h] [-2368h]
  int v130; // [sp+8h] [-2368h]
  int v131; // [sp+8h] [-2368h]
  int v132; // [sp+8h] [-2368h]
  int v133; // [sp+8h] [-2368h]
  int v134; // [sp+8h] [-2368h]
  int v135; // [sp+8h] [-2368h]
  int v136; // [sp+8h] [-2368h]
  int v137; // [sp+8h] [-2368h]
  int v138; // [sp+8h] [-2368h]
  int v139; // [sp+8h] [-2368h]
  int v140; // [sp+Ch] [-2364h]
  int v141; // [sp+Ch] [-2364h]
  int v142; // [sp+Ch] [-2364h]
  int v143; // [sp+Ch] [-2364h]
  int v144; // [sp+Ch] [-2364h]
  int v145; // [sp+Ch] [-2364h]
  int v146; // [sp+Ch] [-2364h]
  int v147; // [sp+Ch] [-2364h]
  int v148; // [sp+Ch] [-2364h]
  int v149; // [sp+Ch] [-2364h]
  int v150; // [sp+Ch] [-2364h]
  int v151; // [sp+Ch] [-2364h]
  int v152; // [sp+Ch] [-2364h]
  int v153; // [sp+Ch] [-2364h]
  int v154; // [sp+Ch] [-2364h]
  int v155; // [sp+Ch] [-2364h]
  int v156; // [sp+10h] [-2360h]
  int v157; // [sp+10h] [-2360h]
  int v158; // [sp+10h] [-2360h]
  int v159; // [sp+10h] [-2360h]
  int v160; // [sp+10h] [-2360h]
  int v161; // [sp+10h] [-2360h]
  int v162; // [sp+10h] [-2360h]
  int v163; // [sp+10h] [-2360h]
  int v164; // [sp+10h] [-2360h]
  int v165; // [sp+10h] [-2360h]
  int v166; // [sp+10h] [-2360h]
  int v167; // [sp+10h] [-2360h]
  int v168; // [sp+10h] [-2360h]
  int v169; // [sp+10h] [-2360h]
  int v170; // [sp+10h] [-2360h]
  int v171; // [sp+10h] [-2360h]
  int v172; // [sp+14h] [-235Ch]
  int v173; // [sp+14h] [-235Ch]
  int v174; // [sp+14h] [-235Ch]
  int v175; // [sp+14h] [-235Ch]
  int v176; // [sp+14h] [-235Ch]
  int v177; // [sp+14h] [-235Ch]
  int v178; // [sp+14h] [-235Ch]
  int v179; // [sp+14h] [-235Ch]
  int v180; // [sp+14h] [-235Ch]
  int v181; // [sp+14h] [-235Ch]
  int v182; // [sp+14h] [-235Ch]
  int v183; // [sp+14h] [-235Ch]
  int v184; // [sp+14h] [-235Ch]
  int v185; // [sp+14h] [-235Ch]
  int v186; // [sp+14h] [-235Ch]
  int v187; // [sp+14h] [-235Ch]
  int v188; // [sp+18h] [-2358h]
  int v189; // [sp+18h] [-2358h]
  int v190; // [sp+18h] [-2358h]
  int v191; // [sp+18h] [-2358h]
  int v192; // [sp+18h] [-2358h]
  int v193; // [sp+18h] [-2358h]
  int v194; // [sp+18h] [-2358h]
  int v195; // [sp+18h] [-2358h]
  int v196; // [sp+18h] [-2358h]
  int v197; // [sp+18h] [-2358h]
  int v198; // [sp+18h] [-2358h]
  int v199; // [sp+18h] [-2358h]
  int v200; // [sp+18h] [-2358h]
  int v201; // [sp+18h] [-2358h]
  int v202; // [sp+18h] [-2358h]
  int v203; // [sp+18h] [-2358h]
  int v204; // [sp+1Ch] [-2354h]
  int v205; // [sp+1Ch] [-2354h]
  int v206; // [sp+1Ch] [-2354h]
  int v207; // [sp+1Ch] [-2354h]
  int v208; // [sp+1Ch] [-2354h]
  int v209; // [sp+1Ch] [-2354h]
  int v210; // [sp+1Ch] [-2354h]
  int v211; // [sp+1Ch] [-2354h]
  int v212; // [sp+1Ch] [-2354h]
  int v213; // [sp+1Ch] [-2354h]
  int v214; // [sp+1Ch] [-2354h]
  int v215; // [sp+1Ch] [-2354h]
  int v216; // [sp+1Ch] [-2354h]
  int v217; // [sp+1Ch] [-2354h]
  int v218; // [sp+1Ch] [-2354h]
  int v219; // [sp+1Ch] [-2354h]
  idSWFScriptVar v220; // [sp+50h] [-2320h] BYREF
  idSWFScriptVar v221; // [sp+58h] [-2318h] BYREF
  idSWFScriptVar v222; // [sp+60h] [-2310h] BYREF
  idSWFScriptVar v223; // [sp+68h] [-2308h] BYREF
  idSWFScriptVar v224; // [sp+70h] [-2300h] BYREF
  idSWFScriptVar v225; // [sp+78h] [-22F8h] BYREF
  idSWFScriptVar v226; // [sp+80h] [-22F0h] BYREF
  idSWFScriptVar v227; // [sp+88h] [-22E8h] BYREF
  idSWFScriptVar v228; // [sp+90h] [-22E0h] BYREF
  idSWFScriptVar v229; // [sp+98h] [-22D8h] BYREF
  idSWFScriptVar v230; // [sp+A0h] [-22D0h] BYREF
  idSWFScriptVar v231; // [sp+A8h] [-22C8h] BYREF
  idSWFScriptVar v232; // [sp+B0h] [-22C0h] BYREF
  idSWFScriptVar v233; // [sp+B8h] [-22B8h] BYREF
  idSWFScriptVar v234; // [sp+C0h] [-22B0h] BYREF
  idSWFScriptVar v235; // [sp+C8h] [-22A8h] BYREF
  idSWFScriptVar v236[2]; // [sp+D0h] [-22A0h] BYREF
  idStr v237; // [sp+E0h] [-2290h] BYREF
  idStr v238; // [sp+100h] [-2270h] BYREF
  idStr v239; // [sp+120h] [-2250h] BYREF
  idStr v240; // [sp+140h] [-2230h] BYREF
  idStr v241; // [sp+160h] [-2210h] BYREF
  idStr v242; // [sp+180h] [-21F0h] BYREF
  idStr v243; // [sp+1A0h] [-21D0h] BYREF
  idStr v244; // [sp+1C0h] [-21B0h] BYREF
  idStr v245; // [sp+1E0h] [-2190h] BYREF
  idStr v246; // [sp+200h] [-2170h] BYREF
  idStr v247; // [sp+220h] [-2150h] BYREF
  idStr v248; // [sp+240h] [-2130h] BYREF
  idStr v249; // [sp+260h] [-2110h] BYREF
  idStr v250; // [sp+280h] [-20F0h] BYREF
  idStr v251; // [sp+2A0h] [-20D0h] BYREF
  idStr v252; // [sp+2C0h] [-20B0h] BYREF
  idStr v253; // [sp+2E0h] [-2090h] BYREF
  va v254; // [sp+300h] [-2070h] BYREF
  va v255; // [sp+1300h] [-1070h] BYREF

  num = parms->num;
  v220.type = SWF_VAR_STRINGID;
  if ( num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for loadProfileData");
    this->__vftable = (idMainMenu::idSWFScriptFunction_loadProfileData_vtbl *)4;
  }
  else
  {
    signInManager = session->signInManager;
    v8 = common->GetFocusDeviceNum(this: common);
    LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(this: signInManager, index: v8);
    if ( LocalUserByInputDevice != nullptr
      || (LocalUserByInputDevice = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager)) != nullptr )
    {
      v10.i = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 219);
      v220.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v220);
      v220.value = v10;
      v220.type = SWF_VAR_INTEGER;
      HIDWORD(v11) = &unk_82340000;
      HIDWORD(v12) = 219;
      v14 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v12,
              a4: v13,
              a5: v11,
              a6: v124,
              a7: v140,
              a8: v156,
              a9: v172,
              a10: v188,
              a11: v204);
      idStr::idStr(this: &v237, text: v14);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v237, value: &v220);
      idStr::FreeData(this: &v237);
      idSWFScriptVar::Free(this: &v220);
      v15 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 219);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_LEGENDS_COMPLETED", v15);
      v16 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 220);
      v229.type = SWF_VAR_UNDEF;
      v17.i = v16;
      idSWFScriptVar::Free(this: &v229);
      v229.value = v17;
      v229.type = SWF_VAR_INTEGER;
      HIDWORD(v18) = 220;
      v21 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v18,
              a4: v20,
              a5: v19,
              a6: v125,
              a7: v141,
              a8: v157,
              a9: v173,
              a10: v189,
              a11: v205);
      idStr::idStr(this: &v253, text: v21);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v253, value: &v229);
      idStr::FreeData(this: &v253);
      idSWFScriptVar::Free(this: &v229);
      v22 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 220);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_BEST_SCORE", v22);
      v23 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 221);
      v223.type = SWF_VAR_UNDEF;
      v24.i = v23;
      idSWFScriptVar::Free(this: &v223);
      v223.value = v24;
      v223.type = SWF_VAR_INTEGER;
      HIDWORD(v25) = 221;
      v28 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v25,
              a4: v27,
              a5: v26,
              a6: v126,
              a7: v142,
              a8: v158,
              a9: v174,
              a10: v190,
              a11: v206);
      idStr::idStr(this: &v240, text: v28);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v240, value: &v223);
      idStr::FreeData(this: &v240);
      idSWFScriptVar::Free(this: &v223);
      v29 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 221);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_SHOTS_FIRED", v29);
      v30 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 217);
      v233.type = SWF_VAR_UNDEF;
      v31.i = v30;
      idSWFScriptVar::Free(this: &v233);
      v233.value = v31;
      v233.type = SWF_VAR_INTEGER;
      HIDWORD(v32) = 217;
      v35 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v32,
              a4: v34,
              a5: v33,
              a6: v127,
              a7: v143,
              a8: v159,
              a9: v175,
              a10: v191,
              a11: v207);
      idStr::idStr(this: &v248, text: v35);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v248, value: &v233);
      idStr::FreeData(this: &v248);
      idSWFScriptVar::Free(this: &v233);
      v36 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 217);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_KILLS", v36);
      v37 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 223);
      v225.type = SWF_VAR_UNDEF;
      v38.i = v37;
      idSWFScriptVar::Free(this: &v225);
      v225.value = v38;
      v225.type = SWF_VAR_INTEGER;
      HIDWORD(v39) = 223;
      v42 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v39,
              a4: v41,
              a5: v40,
              a6: v128,
              a7: v144,
              a8: v160,
              a9: v176,
              a10: v192,
              a11: v208);
      idStr::idStr(this: &v242, text: v42);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v242, value: &v225);
      idStr::FreeData(this: &v242);
      idSWFScriptVar::Free(this: &v225);
      v43 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 223);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_HEADSHOT_KILLS", v43);
      v44 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 207);
      v231.type = SWF_VAR_UNDEF;
      v45.i = v44;
      idSWFScriptVar::Free(this: &v231);
      v231.value = v45;
      v231.type = SWF_VAR_INTEGER;
      HIDWORD(v46) = 207;
      v49 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v46,
              a4: v48,
              a5: v47,
              a6: v129,
              a7: v145,
              a8: v161,
              a9: v177,
              a10: v193,
              a11: v209);
      idStr::idStr(this: &v252, text: v49);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v252, value: &v231);
      idStr::FreeData(this: &v252);
      idSWFScriptVar::Free(this: &v231);
      v50 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 207);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_PARTNER_REVIVES", v50);
      v51 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 224);
      v227.type = SWF_VAR_UNDEF;
      v52.i = v51;
      idSWFScriptVar::Free(this: &v227);
      v227.value = v52;
      v227.type = SWF_VAR_INTEGER;
      HIDWORD(v53) = 224;
      v56 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v53,
              a4: v55,
              a5: v54,
              a6: v130,
              a7: v146,
              a8: v162,
              a9: v178,
              a10: v194,
              a11: v210);
      idStr::idStr(this: &v244, text: v56);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v244, value: &v227);
      idStr::FreeData(this: &v244);
      idSWFScriptVar::Free(this: &v227);
      v57 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 224);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_COOP_COLLECTIBLES_FOUND", v57);
      v58 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 201);
      v235.type = SWF_VAR_UNDEF;
      v59.i = v58;
      idSWFScriptVar::Free(this: &v235);
      v235.value = v59;
      v235.type = SWF_VAR_INTEGER;
      HIDWORD(v60) = 201;
      v63 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v60,
              a4: v62,
              a5: v61,
              a6: v131,
              a7: v147,
              a8: v163,
              a9: v179,
              a10: v195,
              a11: v211);
      idStr::idStr(this: &v250, text: v63);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v250, value: &v235);
      idStr::FreeData(this: &v250);
      idSWFScriptVar::Free(this: &v235);
      v64 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 201);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_VDM_COMPLETED_RALLY", v64);
      v65 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 202);
      v221.type = SWF_VAR_UNDEF;
      v66.i = v65;
      idSWFScriptVar::Free(this: &v221);
      v221.value = v66;
      v221.type = SWF_VAR_INTEGER;
      HIDWORD(v67) = 202;
      v70 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v67,
              a4: v69,
              a5: v68,
              a6: v132,
              a7: v148,
              a8: v164,
              a9: v180,
              a10: v196,
              a11: v212);
      idStr::idStr(this: &v246, text: v70);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v246, value: &v221);
      idStr::FreeData(this: &v246);
      idSWFScriptVar::Free(this: &v221);
      v71 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 202);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_VDM_COMPLETED_RALLY_FIRST", v71);
      v72 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 24);
      v222.type = SWF_VAR_UNDEF;
      v73.i = v72;
      idSWFScriptVar::Free(this: &v222);
      v222.value = v73;
      v222.type = SWF_VAR_INTEGER;
      HIDWORD(v74) = 24;
      v77 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v74,
              a4: v76,
              a5: v75,
              a6: v133,
              a7: v149,
              a8: v165,
              a9: v181,
              a10: v197,
              a11: v213);
      idStr::idStr(this: &v238, text: v77);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v238, value: &v222);
      idStr::FreeData(this: &v238);
      idSWFScriptVar::Free(this: &v222);
      v78 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 24);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_VEHICLE_FLAG_CAPTURES", v78);
      v79 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 228);
      v224.type = SWF_VAR_UNDEF;
      v80.i = v79;
      idSWFScriptVar::Free(this: &v224);
      v224.value = v80;
      v224.type = SWF_VAR_INTEGER;
      HIDWORD(v81) = 228;
      v84 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v81,
              a4: v83,
              a5: v82,
              a6: v134,
              a7: v150,
              a8: v166,
              a9: v182,
              a10: v198,
              a11: v214);
      idStr::idStr(this: &v239, text: v84);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v239, value: &v224);
      idStr::FreeData(this: &v239);
      idSWFScriptVar::Free(this: &v224);
      v85 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 228);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_RR_KILLS", v85);
      v86 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 229);
      v226.type = SWF_VAR_UNDEF;
      v87.i = v86;
      idSWFScriptVar::Free(this: &v226);
      v226.value = v87;
      v226.type = SWF_VAR_INTEGER;
      HIDWORD(v88) = 229;
      v91 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v88,
              a4: v90,
              a5: v89,
              a6: v135,
              a7: v151,
              a8: v167,
              a9: v183,
              a10: v199,
              a11: v215);
      idStr::idStr(this: &v241, text: v91);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v241, value: &v226);
      idStr::FreeData(this: &v241);
      idSWFScriptVar::Free(this: &v226);
      v92 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 229);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_RR_AWARDS_EARNED", v92);
      v93 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 107);
      v228.type = SWF_VAR_UNDEF;
      v94.i = v93;
      idSWFScriptVar::Free(this: &v228);
      v228.value = v94;
      v228.type = SWF_VAR_INTEGER;
      HIDWORD(v95) = 107;
      v98 = va::va(
              this: &v254,
              fmt: "onlinePlayerProfileStat%d",
              a3: v95,
              a4: v97,
              a5: v96,
              a6: v136,
              a7: v152,
              a8: v168,
              a9: v184,
              a10: v200,
              a11: v216);
      idStr::idStr(this: &v243, text: v98);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v243, value: &v228);
      idStr::FreeData(this: &v243);
      idSWFScriptVar::Free(this: &v228);
      v99 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 107);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_LONGEST_RALLY_CHAIN", v99);
      v100 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 41);
      v230.type = SWF_VAR_UNDEF;
      v101.i = v100;
      idSWFScriptVar::Free(this: &v230);
      v230.value = v101;
      v230.type = SWF_VAR_INTEGER;
      HIDWORD(v102) = 41;
      v105 = va::va(
               this: &v254,
               fmt: "onlinePlayerProfileStat%d",
               a3: v102,
               a4: v104,
               a5: v103,
               a6: v137,
               a7: v153,
               a8: v169,
               a9: v185,
               a10: v201,
               a11: v217);
      idStr::idStr(this: &v245, text: v105);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v245, value: &v230);
      idStr::FreeData(this: &v245);
      idSWFScriptVar::Free(this: &v230);
      v106 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 41);
      idLib::Printf(fmt: "^4%s: %d\n", "RAGE_STAT_VEHICLE_RALLY_CAPTURES", v106);
      v107 = ((double (__fastcall *)(idLocalUser *, int))LocalUserByInputDevice->GetStatFloat)(
               a1: LocalUserByInputDevice,
               a2: 230);
      LODWORD(v108) = "ound traces";
      *(double *)((char *)&v109 + 4) = (float)((float)v107 * (float)0.000015782829);
      v111 = va::va(
               this: &v254,
               fmt: (const char *)DWORD1(v109),
               a3: v109,
               a4: v110,
               a5: v108,
               a6: v138,
               a7: v154,
               a8: v170,
               a9: v186,
               a10: v202,
               a11: v218);
      v236[0].type = SWF_VAR_UNDEF;
      idSWFScriptVar::SetString(this: v236, s: v111);
      HIDWORD(v112) = 230;
      v115 = va::va(
               this: &v255,
               fmt: "onlinePlayerProfileStat%d",
               a3: v112,
               a4: v114,
               a5: v113,
               a6: v139,
               a7: v155,
               a8: v171,
               a9: v187,
               a10: v203,
               a11: v219);
      idStr::idStr(this: &v247, text: v115);
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v247, value: v236);
      idStr::FreeData(this: &v247);
      idSWFScriptVar::Free(this: v236);
      v116.i = -1;
      v117 = nullptr;
      v118 = 0;
      if ( idDeclMetric::resourceList.num > 0 )
      {
        do
        {
          v119 = idResourceList::Index(this: &idDeclMetric::resourceList, index: v118);
          v120 = v119;
          if ( v119 != nullptr
            && HIBYTE(v119[2].resourceError) != 0
            && v119[1].staleCount != -1
            && (int)v119[3].name.str >= 0 )
          {
            v121 = ((int (__fastcall *)(idLocalUser *))LocalUserByInputDevice->GetStatInt)(a1: LocalUserByInputDevice);
            if ( v121 > v116.i )
            {
              v116.i = v121;
              v117 = v120;
            }
          }
          ++v118;
        }
        while ( v118 < idDeclMetric::resourceList.num );
        if ( v117 != nullptr )
        {
          *(const char **)&v122.f = v117[3].name.str;
          v232.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v232);
          v232.value = v122;
          v232.type = SWF_VAR_STRINGID;
          idStr::idStr(this: &v249, text: "onlinePlayerProfileFavoriteWeapon");
          idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v249, value: &v232);
          idStr::FreeData(this: &v249);
          idSWFScriptVar::Free(this: &v232);
          v234.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v234);
          v234.value = v116;
          v234.type = SWF_VAR_INTEGER;
          idStr::idStr(this: &v251, text: "onlinePlayerProfileFavoriteWeaponKills");
          idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v251, value: &v234);
          idStr::FreeData(this: &v251);
          idSWFScriptVar::Free(this: &v234);
        }
      }
      this->__vftable = (idMainMenu::idSWFScriptFunction_loadProfileData_vtbl *)4;
    }
    else
    {
      idLib::Warning(fmt: "Couldn't find master local user");
      this->__vftable = (idMainMenu::idSWFScriptFunction_loadProfileData_vtbl *)4;
    }
  }
  return this;
}


// ========================================================================
// __unwind$511037
// EA  : 0x82DC7174
// RVA : 0x00DC7174
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511037()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 80));
}


// ========================================================================
// __unwind$511038
// EA  : 0x82DC719C
// RVA : 0x00DC719C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511038()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 224));
}


// ========================================================================
// __unwind$511039_0
// EA  : 0x82DC71C4
// RVA : 0x00DC71C4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511039_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 152));
}


// ========================================================================
// __unwind$511040_0
// EA  : 0x82DC71EC
// RVA : 0x00DC71EC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511040_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 736));
}


// ========================================================================
// __unwind$511041_0
// EA  : 0x82DC7214
// RVA : 0x00DC7214
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511041_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 104));
}


// ========================================================================
// __unwind$511042_0
// EA  : 0x82DC723C
// RVA : 0x00DC723C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511042_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 320));
}


// ========================================================================
// __unwind$511043
// EA  : 0x82DC7264
// RVA : 0x00DC7264
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511043()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 184));
}


// ========================================================================
// __unwind$511044
// EA  : 0x82DC728C
// RVA : 0x00DC728C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511044()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 576));
}


// ========================================================================
// __unwind$511045
// EA  : 0x82DC72B4
// RVA : 0x00DC72B4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511045()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 120));
}


// ========================================================================
// __unwind$511046
// EA  : 0x82DC72DC
// RVA : 0x00DC72DC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511046()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 384));
}


// ========================================================================
// __unwind$511047
// EA  : 0x82DC7304
// RVA : 0x00DC7304
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511047()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 168));
}


// ========================================================================
// __unwind$511048
// EA  : 0x82DC732C
// RVA : 0x00DC732C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511048()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 704));
}


// ========================================================================
// __unwind$511049
// EA  : 0x82DC7354
// RVA : 0x00DC7354
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511049()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 136));
}


// ========================================================================
// __unwind$511050
// EA  : 0x82DC737C
// RVA : 0x00DC737C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511050()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 448));
}


// ========================================================================
// __unwind$511051
// EA  : 0x82DC73A4
// RVA : 0x00DC73A4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511051()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 200));
}


// ========================================================================
// __unwind$511052
// EA  : 0x82DC73CC
// RVA : 0x00DC73CC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511052()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 640));
}


// ========================================================================
// __unwind$511053
// EA  : 0x82DC73F4
// RVA : 0x00DC73F4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511053()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 88));
}


// ========================================================================
// __unwind$511054
// EA  : 0x82DC741C
// RVA : 0x00DC741C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511054()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 512));
}


// ========================================================================
// __unwind$511055
// EA  : 0x82DC7444
// RVA : 0x00DC7444
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511055()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 96));
}


// ========================================================================
// __unwind$511056
// EA  : 0x82DC746C
// RVA : 0x00DC746C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511056()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 256));
}


// ========================================================================
// __unwind$511057
// EA  : 0x82DC7494
// RVA : 0x00DC7494
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511057()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 112));
}


// ========================================================================
// __unwind$511058
// EA  : 0x82DC74BC
// RVA : 0x00DC74BC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511058()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 288));
}


// ========================================================================
// __unwind$511059
// EA  : 0x82DC74E4
// RVA : 0x00DC74E4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511059()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 128));
}


// ========================================================================
// __unwind$511060
// EA  : 0x82DC750C
// RVA : 0x00DC750C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511060()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 352));
}


// ========================================================================
// __unwind$511061
// EA  : 0x82DC7534
// RVA : 0x00DC7534
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511061()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 144));
}


// ========================================================================
// __unwind$511062
// EA  : 0x82DC755C
// RVA : 0x00DC755C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511062()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 416));
}


// ========================================================================
// __unwind$511063
// EA  : 0x82DC7584
// RVA : 0x00DC7584
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511063()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 160));
}


// ========================================================================
// __unwind$511064
// EA  : 0x82DC75AC
// RVA : 0x00DC75AC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511064()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 480));
}


// ========================================================================
// __unwind$511065
// EA  : 0x82DC75D4
// RVA : 0x00DC75D4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511065()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 208));
}


// ========================================================================
// __unwind$511066
// EA  : 0x82DC75FC
// RVA : 0x00DC75FC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511066()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 544));
}


// ========================================================================
// __unwind$511067
// EA  : 0x82DC7624
// RVA : 0x00DC7624
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511067()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 176));
}


// ========================================================================
// __unwind$511068
// EA  : 0x82DC764C
// RVA : 0x00DC764C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511068()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 608));
}


// ========================================================================
// __unwind$511069
// EA  : 0x82DC7674
// RVA : 0x00DC7674
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511069()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 9072 + 192));
}


// ========================================================================
// __unwind$511070
// EA  : 0x82DC769C
// RVA : 0x00DC769C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511070()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 9072 + 672));
}


// ========================================================================
// ?Call@idSWFScriptFunction_isGameModeTeam@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC76C8
// RVA : 0x00DC76C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isGameModeTeam *__fastcall idMainMenu::idSWFScriptFunction_isGameModeTeam::Call(
        idMainMenu::idSWFScriptFunction_isGameModeTeam *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r10
  bool IsTeamGameMatch; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for isGameModeTeam", result, thisObject);
    v5 = 4;
  }
  else
  {
    IsTeamGameMatch = idMainMenu::IsTeamGameMatch(this: (idMainMenu *)result->value.i);
    this->__vftable = (idMainMenu::idSWFScriptFunction_isGameModeTeam_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v5 = 5;
    HIBYTE(this->pThis) = IsTeamGameMatch;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_isGameModeTeam_vtbl *)v5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_loadScrollingControlValues@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC7750
// RVA : 0x00DC7750
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_loadScrollingControlValues *__fastcall idMainMenu::idSWFScriptFunction_loadScrollingControlValues::Call(
        idMainMenu::idSWFScriptFunction_loadScrollingControlValues *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptObject *v8; // r3
  idSWFScriptObject *v9; // r29
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r10
  int *v14; // r28
  __int64 v15; // r8
  __int64 v16; // r6
  int v17; // r30
  va *v18; // r3
  int v19; // r3
  idSWFScriptVar::swfScriptVarValue_t v20; // r19
  __int64 v21; // r10
  int *v22; // r28
  __int64 v23; // r8
  __int64 v24; // r6
  int v25; // r30
  va *v26; // r3
  int v27; // r3
  idSWFScriptVar::swfScriptVarValue_t v28; // r19
  __int64 v29; // r10
  __int64 v30; // r8
  __int64 v31; // r6
  va *v32; // r3
  int v34; // [sp+8h] [-1118h]
  int v35; // [sp+Ch] [-1114h]
  int v36; // [sp+10h] [-1110h]
  int v37; // [sp+14h] [-110Ch]
  int v38; // [sp+18h] [-1108h]
  int v39; // [sp+1Ch] [-1104h]
  idSWFScriptVar v40; // [sp+50h] [-10D0h] BYREF
  idSWFScriptVar v41; // [sp+58h] [-10C8h] BYREF
  idSWFScriptVar v42; // [sp+60h] [-10C0h] BYREF
  int v43; // [sp+68h] [-10B8h]
  _DWORD v44[9]; // [sp+6Ch] [-10B4h] BYREF
  idStr v45; // [sp+90h] [-1090h] BYREF
  va v46; // [sp+B0h] [-1070h] BYREF

  v43 = 0;
  if ( parms->num != 1 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getScrollingControlLimits");
    this->__vftable = (idMainMenu::idSWFScriptFunction_loadScrollingControlValues_vtbl *)4;
    return this;
  }
  v8 = (idSWFScriptObject *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x60u,
                              tag: TAG_SWF,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
  v44[8] = v8;
  if ( v8 != nullptr )
    v9 = idSWFScriptObject::idSWFScriptObject(this: v8);
  else
    v9 = nullptr;
  idSWFScriptObject::MakeArray(this: v9);
  idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v45, result: (idStr *)parms->list, a3: v12, a4: v11, a5: v10);
  if ( idStr::Cmp(s1: v45.data, s2: "scorelimit") == 0 )
  {
    v13 = 0x6400000032LL;
    v14 = v44;
    v44[1] = 50;
    v15 = 0xFA000000C8LL;
    v44[2] = 100;
    LODWORD(v16) = 300;
    v44[3] = 200;
    v44[4] = 250;
    v44[5] = 300;
    v44[6] = 400;
    v17 = 0;
    v44[7] = 500;
    do
    {
      HIDWORD(v16) = v17;
      v18 = va::va(
              this: &v46,
              fmt: "VDM_SCORELIMIT_%d",
              a3: v16,
              a4: v15,
              a5: v13,
              a6: v34,
              a7: v35,
              a8: v36,
              a9: v37,
              a10: v38,
              a11: v39);
      v19 = session->GetTitleStorageInt_2(this: session, a2: (const char *)v18, a3: *++v14);
      v41.type = SWF_VAR_UNDEF;
      v20.i = v19;
      idSWFScriptVar::Free(this: &v41);
      v41.value = v20;
      v41.type = SWF_VAR_INTEGER;
      idSWFScriptObject::Set(this: v9, index: v17, value: &v41);
      idSWFScriptVar::Free(this: &v41);
      ++v17;
    }
    while ( v17 < 7 );
    goto LABEL_13;
  }
  if ( idStr::Cmp(s1: v45.data, s2: "timelimit") == 0 )
  {
    v44[3] = 8;
    v21 = 0x500000002LL;
    v22 = v44;
    v44[1] = 2;
    v23 = 0xF0000000ALL;
    v44[2] = 5;
    LODWORD(v24) = 20;
    v44[4] = 10;
    v44[5] = 15;
    v44[6] = 20;
    v25 = 0;
    v44[7] = 30;
    do
    {
      HIDWORD(v24) = v25;
      v26 = va::va(
              this: &v46,
              fmt: "VDM_TIMELIMIT_%d",
              a3: v24,
              a4: v23,
              a5: v21,
              a6: v34,
              a7: v35,
              a8: v36,
              a9: v37,
              a10: v38,
              a11: v39);
      v27 = session->GetTitleStorageInt_2(this: session, a2: (const char *)v26, a3: *++v22);
      v42.type = SWF_VAR_UNDEF;
      v28.i = v27;
      idSWFScriptVar::Free(this: &v42);
      v42.value = v28;
      v42.type = SWF_VAR_INTEGER;
      idSWFScriptObject::Set(this: v9, index: v25, value: &v42);
      idSWFScriptVar::Free(this: &v42);
      ++v25;
    }
    while ( v25 < 7 );
LABEL_13:
    v40.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v40);
    if ( v9 != nullptr )
    {
      v40.value.i = (int)v9;
      v40.type = SWF_VAR_OBJECT;
      ++v9->refCount;
    }
    else
    {
      v40.type = SWF_VAR_NULL;
    }
    HIDWORD(v31) = v45.data;
    v32 = va::va(
            this: &v46,
            fmt: "%sValues",
            a3: v31,
            a4: v30,
            a5: v29,
            a6: v34,
            a7: v35,
            a8: v36,
            a9: v37,
            a10: v38,
            a11: v39);
    idSWFScriptObject::Set(
      this: *(idSWFScriptObject **)(*(_DWORD *)(result->value.i + 668) + 68),
      name: v32->buffer,
      value: &v40);
    idSWFScriptVar::Free(this: &v40);
    if ( v9->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: v9);
      idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
    }
    this->__vftable = (idMainMenu::idSWFScriptFunction_loadScrollingControlValues_vtbl *)4;
    v43 = 1;
    goto LABEL_20;
  }
  idLib::Warning(fmt: "Unrecognized control name %s for getScrollingControlLimits", v45.data);
  this->__vftable = (idMainMenu::idSWFScriptFunction_loadScrollingControlValues_vtbl *)4;
  v43 = 1;
LABEL_20:
  idStr::FreeData(this: &v45);
  return this;
}


// ========================================================================
// __unwind$511644
// EA  : 0x82DC7A90
// RVA : 0x00DC7A90
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511644()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4384;
  if ( (*(_DWORD *)(v0 - 4384 + 104) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 104) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 4404));
  }
}


// ========================================================================
// __unwind$511647
// EA  : 0x82DC7AD4
// RVA : 0x00DC7AD4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511647()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 4384 + 140), tag: TAG_SWF);
}


// ========================================================================
// __unwind$511648
// EA  : 0x82DC7B00
// RVA : 0x00DC7B00
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511648()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4384 + 144));
}


// ========================================================================
// __unwind$511649
// EA  : 0x82DC7B28
// RVA : 0x00DC7B28
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511649()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4384 + 88));
}


// ========================================================================
// __unwind$511650
// EA  : 0x82DC7B50
// RVA : 0x00DC7B50
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511650()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4384 + 96));
}


// ========================================================================
// __unwind$511651
// EA  : 0x82DC7B78
// RVA : 0x00DC7B78
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_511651()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4384 + 80));
}


// ========================================================================
// ?Call@idSWFScriptFunction_getTimeLimit@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC7BA0
// RVA : 0x00DC7BA0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getTimeLimit *__fastcall idMainMenu::idSWFScriptFunction_getTimeLimit::Call(
        idMainMenu::idSWFScriptFunction_getTimeLimit *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int timeLimit; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getTimeLimit", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getTimeLimit_vtbl *)4;
  }
  else
  {
    timeLimit = gameLocal->mainMenu->timeLimit;
    this->__vftable = (idMainMenu::idSWFScriptFunction_getTimeLimit_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getTimeLimit_vtbl *)6;
    this->pThis = (idMainMenu *)(timeLimit / 60);
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getScoreLimit@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC7C38
// RVA : 0x00DC7C38
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getScoreLimit *__fastcall idMainMenu::idSWFScriptFunction_getScoreLimit::Call(
        idMainMenu::idSWFScriptFunction_getScoreLimit *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *scoreLimit; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getScoreLimit", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getScoreLimit_vtbl *)4;
  }
  else
  {
    scoreLimit = (idMainMenu *)gameLocal->mainMenu->scoreLimit;
    this->__vftable = (idMainMenu::idSWFScriptFunction_getScoreLimit_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->pThis = scoreLimit;
    this->__vftable = (idMainMenu::idSWFScriptFunction_getScoreLimit_vtbl *)6;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getCoopDifficulty@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC7CC8
// RVA : 0x00DC7CC8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getSessionCoopDifficulty *__fastcall idMainMenu::idSWFScriptFunction_getCoopDifficulty::Call(
        idMainMenu::idSWFScriptFunction_getSessionCoopDifficulty *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *GameCoopDifficulty; // r30

  GameCoopDifficulty = (idMainMenu *)idGameLocal::GetGameCoopDifficulty(this: gameLocal);
  this->__vftable = (idMainMenu::idSWFScriptFunction_getSessionCoopDifficulty_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  this->pThis = GameCoopDifficulty;
  this->__vftable = (idMainMenu::idSWFScriptFunction_getSessionCoopDifficulty_vtbl *)6;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getCOOPPrivacy@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC7D28
// RVA : 0x00DC7D28
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getCOOPPrivacy *__fastcall idMainMenu::idSWFScriptFunction_getCOOPPrivacy::Call(
        idMainMenu::idSWFScriptFunction_getCOOPPrivacy *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char CoopPrivacy; // r30

  CoopPrivacy = idMainMenu::GetCoopPrivacy(this: gameLocal->mainMenu, defaults: false);
  this->__vftable = (idMainMenu::idSWFScriptFunction_getCOOPPrivacy_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = CoopPrivacy;
  this->__vftable = (idMainMenu::idSWFScriptFunction_getCOOPPrivacy_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_shouldPrivacyBeVisible@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC7D98
// RVA : 0x00DC7D98
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible *__fastcall idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible::Call(
        idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idLobbyBase *v6; // r3
  idLobbyBase *v7; // r3
  idLobbyBase *v8; // r3
  bool v9; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for shouldPrivacyBeVisible");
    this->__vftable = (idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 0;
    this->__vftable = (idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible_vtbl *)5;
    return this;
  }
  else
  {
    v6 = session->GetPartyLobbyBase(this: session);
    v9 = false;
    if ( v6->IsHost(this: v6) != 0 )
    {
      v7 = session->GetGameLobbyBase(this: session);
      if ( v7->GetMatchParms(this: v7)->gameType != 1
        || (v8 = session->GetGameLobbyBase(this: session), (v8->GetMatchParms(this: v8)->matchFlags & 2) != 0) )
      {
        v9 = true;
      }
    }
    this->__vftable = (idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = v9;
    this->__vftable = (idMainMenu::idSWFScriptFunction_shouldPrivacyBeVisible_vtbl *)5;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_getAllowFriendlyFire@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC7EB8
// RVA : 0x00DC7EB8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getAllowFriendlyFire *__fastcall idMainMenu::idSWFScriptFunction_getAllowFriendlyFire::Call(
        idMainMenu::idSWFScriptFunction_getAllowFriendlyFire *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r10

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getAllowFriendlyFire", result, thisObject);
    v5 = 4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowFriendlyFire_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v5 = 5;
    HIBYTE(this->pThis) = 1;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowFriendlyFire_vtbl *)v5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getAllowSpectators@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC7F28
// RVA : 0x00DC7F28
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getAllowSpectators *__fastcall idMainMenu::idSWFScriptFunction_getAllowSpectators::Call(
        idMainMenu::idSWFScriptFunction_getAllowSpectators *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r10

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getAllowSpectators", result, thisObject);
    v5 = 4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowSpectators_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v5 = 5;
    HIBYTE(this->pThis) = 1;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowSpectators_vtbl *)v5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getAllowPowerups@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC7F98
// RVA : 0x00DC7F98
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getAllowPowerups *__fastcall idMainMenu::idSWFScriptFunction_getAllowPowerups::Call(
        idMainMenu::idSWFScriptFunction_getAllowPowerups *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r10

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getAllowPowerups", result, thisObject);
    v5 = 4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowPowerups_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v5 = 5;
    HIBYTE(this->pThis) = 1;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowPowerups_vtbl *)v5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getAllowQuickUse@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC8008
// RVA : 0x00DC8008
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getAllowQuickUse *__fastcall idMainMenu::idSWFScriptFunction_getAllowQuickUse::Call(
        idMainMenu::idSWFScriptFunction_getAllowQuickUse *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r10

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getAllowQuickUse", result, thisObject);
    v5 = 4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowQuickUse_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v5 = 5;
    HIBYTE(this->pThis) = 1;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowQuickUse_vtbl *)v5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getAllowSponsors@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC8078
// RVA : 0x00DC8078
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getAllowSponsors *__fastcall idMainMenu::idSWFScriptFunction_getAllowSponsors::Call(
        idMainMenu::idSWFScriptFunction_getAllowSponsors *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r10

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getAllowSponsors", result, thisObject);
    v5 = 4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowSponsors_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v5 = 5;
    HIBYTE(this->pThis) = 1;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowSponsors_vtbl *)v5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getAllowBoost@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC80E8
// RVA : 0x00DC80E8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getAllowBoost *__fastcall idMainMenu::idSWFScriptFunction_getAllowBoost::Call(
        idMainMenu::idSWFScriptFunction_getAllowBoost *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v5; // r10

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getAllowBoost", result, thisObject);
    v5 = 4;
  }
  else
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowBoost_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    v5 = 5;
    HIBYTE(this->pThis) = 1;
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getAllowBoost_vtbl *)v5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_getPlayerLevelTitle@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC8160
// RVA : 0x00DC8160
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getPlayerLevelTitle *__fastcall idMainMenu::idSWFScriptFunction_getPlayerLevelTitle::Call(
        idMainMenu::idSWFScriptFunction_getPlayerLevelTitle *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idPlayerProfile *v6; // r30
  int v7; // r30
  const char *LocalizedString; // r3
  idStrId v9; // [sp+50h] [-60h] BYREF
  int v10; // [sp+54h] [-5Ch]
  idStr v11[2]; // [sp+60h] [-50h] BYREF

  v10 = 0;
  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getPlayerLevelTitle");
    this->__vftable = (idMainMenu::idSWFScriptFunction_getPlayerLevelTitle_vtbl *)4;
    return this;
  }
  else
  {
    v6 = common->GetProfileFromMasterLocalUser(this: common);
    if ( v6 != nullptr )
    {
      v11[0].len = 0;
      v11[0].baseBuffer[0] = 0;
      v11[0].allocedAndFlag = 20;
      v11[0].data = v11[0].baseBuffer;
      idStrId::Set(this: &v9, key: "#str_swf_lvl_short");
      v7 = v6->GetLevel(this: v6);
      LocalizedString = idStrId::GetLocalizedString(this: &v9);
      idStr::Format(this: v11, fmt: LocalizedString, v7);
      idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, s: v11);
      v10 = 1;
      idStr::FreeData(this: v11);
    }
    else
    {
      this->__vftable = (idMainMenu::idSWFScriptFunction_getPlayerLevelTitle_vtbl *)4;
    }
    return this;
  }
}


// ========================================================================
// __unwind$512199
// EA  : 0x82DC825C
// RVA : 0x00DC825C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512199()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 196));
  }
}


// ========================================================================
// __unwind$512202
// EA  : 0x82DC82A0
// RVA : 0x00DC82A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512202()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_getAccoladeInfo@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC82D0
// RVA : 0x00DC82D0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getAccoladeInfo *__fastcall idMainMenu::idSWFScriptFunction_getAccoladeInfo::Call(
        idMainMenu::idSWFScriptFunction_getAccoladeInfo *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idLocalUser *v7; // r3
  idSWFScriptVar *list; // r8
  idLocalUser *v9; // r30
  int v10; // r3
  int v11; // r29
  idSWFScriptObject *v12; // r30
  idSWFScriptVar::swfScriptVarValue_t *v13; // r3
  char *v14; // r3
  char *v15; // r3
  const char *v16; // r3
  idAccolade v17; // [sp+58h] [-58h] BYREF
  idSWFScriptVar v18; // [sp+60h] [-50h] BYREF
  idSWFScriptVar v19; // [sp+68h] [-48h] BYREF
  idSWFScriptVar v20; // [sp+70h] [-40h] BYREF
  idSWFScriptVar v21; // [sp+78h] [-38h] BYREF
  idSWFScriptVar v22[6]; // [sp+80h] [-30h] BYREF

  if ( parms->num == 1 )
  {
    v7 = common->GetMasterLocalUser(this: common);
    list = parms->list;
    v9 = v7;
    v10 = idSWFScriptVar::ToInteger(this: list);
    v11 = v10;
    if ( v9 != nullptr && v10 >= 0 && v10 < idAccolades::Num() )
    {
      idAccolades::GetLifetime(result: &v17, user: v9, index: v11);
      v12 = idSWFScriptObject::Alloc();
      v13 = (idSWFScriptVar::swfScriptVarValue_t *)idAccolade::Count(this: (idGameTimeManager *)&v17);
      idSWFScriptVar::idSWFScriptVar(this: &v18, i: v13);
      idSWFScriptObject::Set(this: v12, name: "count", value: &v18);
      idSWFScriptVar::Free(this: &v18);
      v14 = idAccolade::Name(this: &v17);
      idSWFScriptVar::idSWFScriptVar(this: &v19, s: v14);
      idSWFScriptObject::Set(this: v12, name: "name", value: &v19);
      idSWFScriptVar::Free(this: &v19);
      v15 = idAccolade::Description(this: &v17);
      idSWFScriptVar::idSWFScriptVar(this: &v20, s: v15);
      idSWFScriptObject::Set(this: v12, name: "description", value: &v20);
      idSWFScriptVar::Free(this: &v20);
      v16 = idAccolade::Icon(this: &v17);
      idSWFScriptVar::idSWFScriptVar(this: &v21, s: v16);
      idSWFScriptObject::Set(this: v12, name: "material", value: &v21);
      idSWFScriptVar::Free(this: &v21);
      idSWFScriptVar::idSWFScriptVar(this: v22, o: v12);
      idSWFScriptObject::Release(this: v12);
      idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, other: v22);
      idSWFScriptVar::Free(this: v22);
    }
    else
    {
      this->__vftable = (idMainMenu::idSWFScriptFunction_getAccoladeInfo_vtbl *)4;
    }
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for getAccoladeInfo");
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAccoladeInfo_vtbl *)4;
    return this;
  }
}


// ========================================================================
// __unwind$512265
// EA  : 0x82DC8484
// RVA : 0x00DC8484
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512265()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 176;
  if ( (*(_DWORD *)(v0 - 176 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 196));
  }
}


// ========================================================================
// __unwind$512268
// EA  : 0x82DC84C8
// RVA : 0x00DC84C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512268()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 96));
}


// ========================================================================
// __unwind$512269
// EA  : 0x82DC84F0
// RVA : 0x00DC84F0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512269()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 104));
}


// ========================================================================
// __unwind$512270
// EA  : 0x82DC8518
// RVA : 0x00DC8518
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512270()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 112));
}


// ========================================================================
// __unwind$512271
// EA  : 0x82DC8540
// RVA : 0x00DC8540
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512271()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 120));
}


// ========================================================================
// __unwind$512272
// EA  : 0x82DC8568
// RVA : 0x00DC8568
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512272()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 176 + 128));
}


// ========================================================================
// ?Call@idSWFScriptFunction_getAccoladeCount@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC8590
// RVA : 0x00DC8590
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getAccoladeCount *__fastcall idMainMenu::idSWFScriptFunction_getAccoladeCount::Call(
        idMainMenu::idSWFScriptFunction_getAccoladeCount *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *num; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getAccoladeCount", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAccoladeCount_vtbl *)4;
  }
  else
  {
    num = (idMainMenu *)idDeclAccolade::orderedList.num;
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAccoladeCount_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->pThis = num;
    this->__vftable = (idMainMenu::idSWFScriptFunction_getAccoladeCount_vtbl *)6;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_selectAccolade@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC8618
// RVA : 0x00DC8618
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_selectAccolade *__fastcall idMainMenu::idSWFScriptFunction_selectAccolade::Call(
        idMainMenu::idSWFScriptFunction_selectAccolade *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11
  idSWFScriptVar::swfScriptVarType type; // r11
  char v8; // r11
  bool v9; // zf
  idLocalUser *v10; // r3
  idSWFScriptVar *list; // r8
  idLocalUser *v12; // r30
  int v13; // r3
  int v14; // r29
  char *v15; // r3
  char *v16; // r3
  idSWFScriptVar v18; // [sp+50h] [-90h] BYREF
  idAccolade v19; // [sp+58h] [-88h] BYREF
  idSWFScriptVar v20[2]; // [sp+60h] [-80h] BYREF
  idStr v21; // [sp+70h] [-70h] BYREF
  idStr v22[2]; // [sp+90h] [-50h] BYREF

  num = parms->num;
  v18.type = SWF_VAR_STRINGID;
  if ( num != 1 )
    goto LABEL_12;
  type = parms->list->type;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v9 = type != SWF_VAR_BOOL, v8 = 0, !v9) )
    v8 = 1;
  if ( v8 != 0 )
  {
    v10 = common->GetMasterLocalUser(this: common);
    list = parms->list;
    v12 = v10;
    v13 = idSWFScriptVar::ToInteger(this: list);
    v14 = v13;
    if ( v12 != nullptr && v13 >= 0 && v13 < idAccolades::Num() )
    {
      idAccolades::GetLifetime(result: &v19, user: v12, index: v14);
      v15 = idAccolade::Name(this: &v19);
      idSWFScriptVar::idSWFScriptVar(this: &v18, s: v15);
      idStr::idStr(this: &v21, text: "accoladeName");
      idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v21, value: &v18);
      idStr::FreeData(this: &v21);
      idSWFScriptVar::Free(this: &v18);
      v16 = idAccolade::Description(this: &v19);
      idSWFScriptVar::idSWFScriptVar(this: v20, s: v16);
      idStr::idStr(this: v22, text: "accoladeDescription");
      idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: v22, value: v20);
      idStr::FreeData(this: v22);
      idSWFScriptVar::Free(this: v20);
      this->__vftable = (idMainMenu::idSWFScriptFunction_selectAccolade_vtbl *)4;
    }
    else
    {
      this->__vftable = (idMainMenu::idSWFScriptFunction_selectAccolade_vtbl *)4;
    }
  }
  else
  {
LABEL_12:
    idLib::Warning(fmt: "Invalid parameters specified for selectAccolade");
    this->__vftable = (idMainMenu::idSWFScriptFunction_selectAccolade_vtbl *)4;
  }
  return this;
}


// ========================================================================
// __unwind$512388
// EA  : 0x82DC87A4
// RVA : 0x00DC87A4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512388()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$512389
// EA  : 0x82DC87CC
// RVA : 0x00DC87CC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512389()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 112));
}


// ========================================================================
// __unwind$512390
// EA  : 0x82DC87F4
// RVA : 0x00DC87F4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512390()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 224 + 96));
}


// ========================================================================
// __unwind$512391
// EA  : 0x82DC881C
// RVA : 0x00DC881C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512391()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 144));
}


// ========================================================================
// ?Call@idSWFScriptFunction_drawPlayerInfo@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC8850
// RVA : 0x00DC8850
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_drawPlayerInfo *__fastcall idMainMenu::idSWFScriptFunction_drawPlayerInfo::Call(
        idMainMenu::idSWFScriptFunction_drawPlayerInfo *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11
  idSignInManagerBase *signInManager; // r29
  int v7; // r3
  idLocalUser *LocalUserByInputDevice; // r29
  int v9; // r26
  idDeclOnlineLevel *v10; // r28
  int v11; // r24
  __int64 v12; // r10
  int v13; // r8
  int v14; // r7
  int v15; // r6
  int v16; // r5
  int XpRequiredForLevel; // r30
  __int64 v18; // r10
  int v19; // r8
  int v20; // r7
  int v21; // r6
  int v22; // r5
  int v23; // r3
  signed int v24; // r11
  idSWFScriptVar::swfScriptVarValue_t v25; // r22
  int v26; // r9
  int v27; // r25
  int NumLoadouts; // r3
  idSWFScriptVar::swfScriptVarValue_t v29; // r23
  const char *v30; // r3
  const idStr *v31; // r3
  int v32; // r3
  __int64 v33; // r6
  idStr *v34; // r3
  idSWFScriptVar v36; // [sp+50h] [-1D0h] BYREF
  idSWFScriptVar v37; // [sp+58h] [-1C8h] BYREF
  idSWFScriptVar v38; // [sp+60h] [-1C0h] BYREF
  idSWFScriptVar v39; // [sp+68h] [-1B8h] BYREF
  idSWFScriptVar v40; // [sp+70h] [-1B0h] BYREF
  idSWFScriptVar v41; // [sp+78h] [-1A8h] BYREF
  idSWFScriptVar v42[2]; // [sp+80h] [-1A0h] BYREF
  idStr v43; // [sp+90h] [-190h] BYREF
  idStr v44; // [sp+B0h] [-170h] BYREF
  idStr v45; // [sp+D0h] [-150h] BYREF
  idStr v46; // [sp+F0h] [-130h] BYREF
  idStr v47; // [sp+110h] [-110h] BYREF
  idStr v48; // [sp+130h] [-F0h] BYREF
  idStr v49; // [sp+150h] [-D0h] BYREF
  idStr v50; // [sp+170h] [-B0h] BYREF
  idStr v51[4]; // [sp+190h] [-90h] BYREF

  num = parms->num;
  v36.type = SWF_VAR_STRINGID;
  if ( num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for drawPlayerInfo");
    this->__vftable = (idMainMenu::idSWFScriptFunction_drawPlayerInfo_vtbl *)4;
  }
  else
  {
    signInManager = session->signInManager;
    v7 = common->GetFocusDeviceNum(this: common);
    LocalUserByInputDevice = idSignInManagerBase::GetLocalUserByInputDevice(this: signInManager, index: v7);
    if ( LocalUserByInputDevice != nullptr
      || (LocalUserByInputDevice = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager)) != nullptr )
    {
      v9 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 32);
      v10 = (idDeclOnlineLevel *)idResourceList::Index(this: &idDeclOnlineLevel::resourceList, index: 0);
      v11 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 23);
      XpRequiredForLevel = idDeclOnlineLevel::GetXpRequiredForLevel(
                             this: v10,
                             level: v9,
                             a3: v16,
                             a4: v15,
                             a5: v14,
                             a6: v13,
                             a7: v12);
      v23 = idDeclOnlineLevel::GetXpRequiredForLevel(
              this: v10,
              level: v9 + 1,
              a3: v22,
              a4: v21,
              a5: v20,
              a6: v19,
              a7: v18);
      v24 = v23 - XpRequiredForLevel;
      v25.i = v23 - v11;
      if ( v23 - XpRequiredForLevel < 1 )
        v24 = 1;
      __twllei(v24, 0);
      v26 = 100 * (v11 - XpRequiredForLevel);
      v27 = v26 / v24;
      __twlgei(v24 & ~(__ROL4__(v26, 1) - 1), 0xFFFFFFFF);
      if ( v26 / v24 >= 1 )
      {
        if ( v27 > 100 )
          v27 = 100;
      }
      else
      {
        v27 = 1;
      }
      NumLoadouts = idDeclOnlineLevel::GetNumLoadouts(this: v10, level: v9);
      v29.i = 1;
      if ( NumLoadouts >= 1 )
        v29.i = NumLoadouts;
      v30 = LocalUserByInputDevice->GetGamerTag(this: LocalUserByInputDevice);
      idSWFScriptVar::idSWFScriptVar(this: &v40, s: v30);
      idStr::idStr(this: &v43, text: "playerName");
      idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v43, value: &v40);
      idStr::FreeData(this: &v43);
      idSWFScriptVar::Free(this: &v40);
      v36.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v36);
      v36.value.i = v9;
      v36.type = SWF_VAR_INTEGER;
      idStr::idStr(this: &v48, text: "playerLevel");
      idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v48, value: &v36);
      idStr::FreeData(this: &v48);
      idSWFScriptVar::Free(this: &v36);
      v31 = idStr::FormatInt(result: &v50, num: v11, isCash: false);
      idSWFScriptVar::idSWFScriptVar(this: &v41, s: v31);
      idStr::idStr(this: &v46, text: "playerXP");
      idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v46, value: &v41);
      idStr::FreeData(this: &v46);
      idSWFScriptVar::Free(this: &v41);
      idStr::FreeData(this: &v50);
      v39.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v39);
      v39.value = v25;
      v39.type = SWF_VAR_INTEGER;
      idStr::idStr(this: &v49, text: "playerXPToNextLevel");
      idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v49, value: &v39);
      idStr::FreeData(this: &v49);
      idSWFScriptVar::Free(this: &v39);
      v38.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v38);
      v38.value.i = v27;
      v38.type = SWF_VAR_INTEGER;
      idStr::idStr(this: &v44, text: "playerXPPercent");
      idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v44, value: &v38);
      idStr::FreeData(this: &v44);
      idSWFScriptVar::Free(this: &v38);
      v32 = LocalUserByInputDevice->GetStatInt(this: LocalUserByInputDevice, a2: 21);
      v34 = FormatCash(result: v51, a2: v32, cash: v33);
      idSWFScriptVar::idSWFScriptVar(this: v42, s: v34);
      idStr::idStr(this: &v45, text: "playerCash");
      idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v45, value: v42);
      idStr::FreeData(this: &v45);
      idSWFScriptVar::Free(this: v42);
      idStr::FreeData(this: v51);
      v37.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v37);
      v37.value = v29;
      v37.type = SWF_VAR_INTEGER;
      idStr::idStr(this: &v47, text: "playerNumLoadouts");
      idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v47, value: &v37);
      idStr::FreeData(this: &v47);
      idSWFScriptVar::Free(this: &v37);
      this->__vftable = (idMainMenu::idSWFScriptFunction_drawPlayerInfo_vtbl *)4;
    }
    else
    {
      idLib::Warning(fmt: "No master user for drawPlayerInfo");
      this->__vftable = (idMainMenu::idSWFScriptFunction_drawPlayerInfo_vtbl *)4;
    }
  }
  return this;
}


// ========================================================================
// __unwind$512495
// EA  : 0x82DC8C2C
// RVA : 0x00DC8C2C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512495()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 544 + 112));
}


// ========================================================================
// __unwind$512496
// EA  : 0x82DC8C54
// RVA : 0x00DC8C54
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512496()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 144));
}


// ========================================================================
// __unwind$512497
// EA  : 0x82DC8C7C
// RVA : 0x00DC8C7C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512497()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 544 + 80));
}


// ========================================================================
// __unwind$512498
// EA  : 0x82DC8CA4
// RVA : 0x00DC8CA4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512498()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 304));
}


// ========================================================================
// __unwind$512499
// EA  : 0x82DC8CCC
// RVA : 0x00DC8CCC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512499()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 368));
}


// ========================================================================
// __unwind$512500
// EA  : 0x82DC8CF4
// RVA : 0x00DC8CF4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512500()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 544 + 120));
}


// ========================================================================
// __unwind$512501
// EA  : 0x82DC8D1C
// RVA : 0x00DC8D1C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512501()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 240));
}


// ========================================================================
// __unwind$512502
// EA  : 0x82DC8D44
// RVA : 0x00DC8D44
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512502()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 544 + 104));
}


// ========================================================================
// __unwind$512503
// EA  : 0x82DC8D6C
// RVA : 0x00DC8D6C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512503()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 336));
}


// ========================================================================
// __unwind$512504
// EA  : 0x82DC8D94
// RVA : 0x00DC8D94
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512504()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 544 + 96));
}


// ========================================================================
// __unwind$512505
// EA  : 0x82DC8DBC
// RVA : 0x00DC8DBC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512505()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 176));
}


// ========================================================================
// __unwind$512506
// EA  : 0x82DC8DE4
// RVA : 0x00DC8DE4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512506()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 400));
}


// ========================================================================
// __unwind$512507
// EA  : 0x82DC8E0C
// RVA : 0x00DC8E0C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512507()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 544 + 128));
}


// ========================================================================
// __unwind$512508
// EA  : 0x82DC8E34
// RVA : 0x00DC8E34
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512508()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 208));
}


// ========================================================================
// __unwind$512509
// EA  : 0x82DC8E5C
// RVA : 0x00DC8E5C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512509()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 544 + 88));
}


// ========================================================================
// __unwind$512510
// EA  : 0x82DC8E84
// RVA : 0x00DC8E84
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512510()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 544 + 272));
}


// ========================================================================
// ?Call@idSWFScriptFunction_hasNewAccolade@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC8EB0
// RVA : 0x00DC8EB0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_hasNewAccolade *__fastcall idMainMenu::idSWFScriptFunction_hasNewAccolade::Call(
        idMainMenu::idSWFScriptFunction_hasNewAccolade *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  cmType_t ScriptP; // r3
  unsigned int v6; // r30

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for hasNewAccolade", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_hasNewAccolade_vtbl *)4;
  }
  else
  {
    ScriptP = idLexer::GetScriptP(this: (idCollisionModelLocal *)playerMatchResults);
    this->__vftable = (idMainMenu::idSWFScriptFunction_hasNewAccolade_vtbl *)4;
    v6 = (-ScriptP & (unsigned int)~ScriptP) >> 31;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = v6;
    this->__vftable = (idMainMenu::idSWFScriptFunction_hasNewAccolade_vtbl *)5;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_loadMenuItems@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC8F48
// RVA : 0x00DC8F48
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_loadMenuItems *__fastcall idMainMenu::idSWFScriptFunction_loadMenuItems::Call(
        idMainMenu::idSWFScriptFunction_loadMenuItems *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v4; // r21
  idMainMenu::idSWFScriptFunction_loadMenuItems *v5; // r30
  idSWFScriptVar *v6; // r29
  idSWFScriptObject *v7; // r3
  idSWFScriptObject *v8; // r18
  idResource *v9; // r29
  idSWFScriptObject *v10; // r3
  idSWFScriptObject *v11; // r30
  int staleCount; // r11
  const char *v13; // r4
  idSWFScriptVar::swfScriptVarValue_t v14; // r14
  idSWFScriptVar v18; // [sp+58h] [-C8h] BYREF
  idSWFScriptVar v19; // [sp+60h] [-C0h] BYREF
  idSWFScriptVar v20; // [sp+68h] [-B8h] BYREF
  idSWFScriptVar v21; // [sp+70h] [-B0h] BYREF
  idSWFScriptVar v22; // [sp+78h] [-A8h] BYREF
  idSWFScriptVar v23[20]; // [sp+80h] [-A0h] BYREF

  v4 = 0;
  v5 = this;
  v6 = result;
  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for loadMenuItems");
    v5->__vftable = (idMainMenu::idSWFScriptFunction_loadMenuItems_vtbl *)4;
  }
  else
  {
    v7 = (idSWFScriptObject *)idMem::AllocWithLocation(
                                this: &mem,
                                location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                size: 0x60u,
                                tag: TAG_SWF,
                                zeroBuffer: false,
                                align: ALIGN_16,
                                heap: HEAP_DEFAULTHEAP);
    if ( v7 != nullptr )
      v8 = idSWFScriptObject::idSWFScriptObject(this: v7);
    else
      v8 = nullptr;
    if ( idDeclMenuItem::resourceList.num > 0 )
    {
      do
      {
        v9 = idResourceList::Index(this: &idDeclMenuItem::resourceList, index: v4);
        if ( v9 != nullptr )
        {
          v10 = (idSWFScriptObject *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x60u,
                                       tag: TAG_SWF,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
          if ( v10 != nullptr )
            v11 = idSWFScriptObject::idSWFScriptObject(this: v10);
          else
            v11 = nullptr;
          staleCount = v9[1].staleCount;
          if ( staleCount != 0 )
            v13 = *(const char **)(staleCount + 8);
          else
            v13 = &byte_8200D768;
          idSWFScriptVar::idSWFScriptVar(this: v23, s: v13);
          idSWFScriptObject::Set(this: v11, name: "material", value: v23);
          idSWFScriptVar::Free(this: v23);
          v20.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v20);
          v20.type = SWF_VAR_STRING;
          v20.value.i = (int)idSWFScriptString::Alloc(s: (const idStr *)&v9[1] + 1);
          idSWFScriptObject::Set(this: v11, name: "title", value: &v20);
          idSWFScriptVar::Free(this: &v20);
          v21.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v21);
          v21.type = SWF_VAR_STRING;
          v21.value.i = (int)idSWFScriptString::Alloc(s: (const idStr *)&v9[2].staleCount);
          idSWFScriptObject::Set(this: v11, name: "help", value: &v21);
          idSWFScriptVar::Free(this: &v21);
          SLODWORD(v14.f) = v9[3].networkID;
          v22.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v22);
          v22.value = v14;
          v22.type = SWF_VAR_INTEGER;
          idSWFScriptObject::Set(this: v11, name: "loadoutSlot", value: &v22);
          idSWFScriptVar::Free(this: &v22);
          v18.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v18);
          if ( v11 != nullptr )
          {
            v18.value.i = (int)v11;
            v18.type = SWF_VAR_OBJECT;
            ++v11->refCount;
          }
          else
          {
            v18.type = SWF_VAR_NULL;
          }
          idSWFScriptObject::Set(this: v8, name: (char *)v9->name.str, value: &v18);
          idSWFScriptVar::Free(this: &v18);
          if ( v11->refCount-- == 1 )
          {
            idSWFScriptObject::~idSWFScriptObject(this: v11);
            idMem::Free(this: &mem, ptr: v11, align: ALIGN_16);
          }
          v5 = this;
        }
        ++v4;
      }
      while ( v4 < idDeclMenuItem::resourceList.num );
      v6 = result;
    }
    v19.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v19);
    if ( v8 != nullptr )
    {
      v19.value.i = (int)v8;
      v19.type = SWF_VAR_OBJECT;
      ++v8->refCount;
    }
    else
    {
      v19.type = SWF_VAR_NULL;
    }
    idSWFScriptObject::Set(
      this: *(idSWFScriptObject **)(*(_DWORD *)(v6->value.i + 668) + 68),
      name: "MENU_ITEMS",
      value: &v19);
    idSWFScriptVar::Free(this: &v19);
    if ( v8->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: v8);
      idMem::Free(this: &mem, ptr: v8, align: ALIGN_16);
    }
    v5->__vftable = (idMainMenu::idSWFScriptFunction_loadMenuItems_vtbl *)4;
  }
  return v5;
}


// ========================================================================
// __unwind$512823
// EA  : 0x82DC926C
// RVA : 0x00DC926C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512823()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 288 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$512824
// EA  : 0x82DC9298
// RVA : 0x00DC9298
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512824()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 288 + 80), tag: TAG_SWF);
}


// ========================================================================
// __unwind$512825
// EA  : 0x82DC92C4
// RVA : 0x00DC92C4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512825()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$512826
// EA  : 0x82DC92EC
// RVA : 0x00DC92EC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512826()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 104));
}


// ========================================================================
// __unwind$512827
// EA  : 0x82DC9314
// RVA : 0x00DC9314
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512827()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$512828
// EA  : 0x82DC933C
// RVA : 0x00DC933C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512828()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 120));
}


// ========================================================================
// __unwind$512829
// EA  : 0x82DC9364
// RVA : 0x00DC9364
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512829()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 88));
}


// ========================================================================
// __unwind$512830
// EA  : 0x82DC938C
// RVA : 0x00DC938C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_512830()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_isCoopNightmareLeaderboard@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC93B8
// RVA : 0x00DC93B8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_isCoopNightmareLeaderboard *__fastcall idMainMenu::idSWFScriptFunction_isCoopNightmareLeaderboard::Call(
        idMainMenu::idSWFScriptFunction_isCoopNightmareLeaderboard *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v5; // r30

  v5 = *(_BYTE *)(result->value.i + 3128);
  this->__vftable = (idMainMenu::idSWFScriptFunction_isCoopNightmareLeaderboard_vtbl *)4;
  idSWFScriptVar::Free((idSWFScriptVar *)this);
  HIBYTE(this->pThis) = v5;
  this->__vftable = (idMainMenu::idSWFScriptFunction_isCoopNightmareLeaderboard_vtbl *)5;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_filterList@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC9418
// RVA : 0x00DC9418
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_filterList *__fastcall idMainMenu::idSWFScriptFunction_filterList::Call(
        idMainMenu::idSWFScriptFunction_filterList *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::swfScriptVarValue_t v4; // r11
  idLBCache *FilterStrType; // r26
  idSWFScriptVar v9[2]; // [sp+50h] [-90h] BYREF
  idStr v10; // [sp+60h] [-80h] BYREF
  idStr v11[3]; // [sp+80h] [-60h] BYREF

  LODWORD(v4.f) = result->value;
  v9[0].type = SWF_VAR_STRINGID;
  idLBCache::CycleFilter(this: *(idLBCache **)(v4.i + 900));
  *(_BYTE *)(result->value.i + 916) = 1;
  FilterStrType = idLBCache::GetFilterStrType(this: (idLBCache *)v11, result: *(idStr **)(result->value.i + 900));
  v9[0].type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: v9);
  v9[0].type = SWF_VAR_STRING;
  v9[0].value.i = (int)idSWFScriptString::Alloc(s: (const idStr *)FilterStrType);
  idStr::idStr(this: &v10, text: "onlineLeaderboardTitle");
  idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v10, value: v9);
  idStr::FreeData(this: &v10);
  idSWFScriptVar::Free(this: v9);
  idStr::FreeData(this: v11);
  this->__vftable = (idMainMenu::idSWFScriptFunction_filterList_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$513102
// EA  : 0x82DC94CC
// RVA : 0x00DC94CC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513102()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 128));
}


// ========================================================================
// __unwind$513103
// EA  : 0x82DC94F4
// RVA : 0x00DC94F4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513103()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$513104
// EA  : 0x82DC951C
// RVA : 0x00DC951C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513104()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 224 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_updateScroll@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC9548
// RVA : 0x00DC9548
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_updateScroll *__fastcall idMainMenu::idSWFScriptFunction_updateScroll::Call(
        idMainMenu::idSWFScriptFunction_updateScroll *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int valueInteger; // r29
  int v7; // r28

  if ( (signed int)Sys_Milliseconds() < *(_DWORD *)(result->value.i + 924) )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateScroll_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 0;
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateScroll_vtbl *)5;
    return this;
  }
  else
  {
    valueInteger = swf_textScrollSpeed.valueInteger;
    v7 = swf_optionScrollSpeed.valueInteger;
    *(_DWORD *)(result->value.i + 924) = Sys_Milliseconds() + v7 + valueInteger;
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateScroll_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateScroll_vtbl *)5;
    HIBYTE(this->pThis) = 1;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_updateLbScroll@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC95F8
// RVA : 0x00DC95F8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_updateLbScroll *__fastcall idMainMenu::idSWFScriptFunction_updateLbScroll::Call(
        idMainMenu::idSWFScriptFunction_updateLbScroll *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v6; // r30

  v6 = 210;
  if ( parms->num > 0 )
    v6 = idSWFScriptVar::ToInteger(this: parms->list);
  if ( (signed int)Sys_Milliseconds() < *(_DWORD *)(result->value.i + 924) )
  {
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateLbScroll_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    HIBYTE(this->pThis) = 0;
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateLbScroll_vtbl *)5;
    return this;
  }
  else
  {
    *(_DWORD *)(result->value.i + 924) = Sys_Milliseconds() + v6;
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateLbScroll_vtbl *)4;
    idSWFScriptVar::Free((idSWFScriptVar *)this);
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateLbScroll_vtbl *)5;
    HIBYTE(this->pThis) = 1;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_getPostGameResults@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC96B0
// RVA : 0x00DC96B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getPostGameResults *__fastcall idMainMenu::idSWFScriptFunction_getPostGameResults::Call(
        idMainMenu::idSWFScriptFunction_getPostGameResults *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11
  const idStr *CashGainStr; // r27
  int score; // r27
  const idStr *MatchTimeStr; // r27
  int xpGained; // r27
  idSWFScriptVar v12; // [sp+50h] [-130h] BYREF
  idSWFScriptVar v13; // [sp+58h] [-128h] BYREF
  idSWFScriptVar v14; // [sp+60h] [-120h] BYREF
  idSWFScriptVar v15; // [sp+68h] [-118h] BYREF
  idStr v16; // [sp+70h] [-110h] BYREF
  idStr v17; // [sp+90h] [-F0h] BYREF
  idStr v18; // [sp+B0h] [-D0h] BYREF
  idStr v19; // [sp+D0h] [-B0h] BYREF
  idMatchResults v20; // [sp+F0h] [-90h] BYREF

  num = parms->num;
  v12.type = SWF_VAR_STRINGID;
  if ( num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for getPostGameResults");
  }
  else
  {
    CashGainStr = idMatchResults::GetCashGainStr(this: &v20, result: (idStr *)playerMatchResults);
    v12.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v12);
    v12.type = SWF_VAR_STRING;
    v12.value.i = (int)idSWFScriptString::Alloc(s: CashGainStr);
    idStr::idStr(this: &v16, text: "matchResultCash");
    idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v16, value: &v12);
    idStr::FreeData(this: &v16);
    idSWFScriptVar::Free(this: &v12);
    idStr::FreeData(this: (idStr *)&v20);
    v13.type = SWF_VAR_UNDEF;
    score = playerMatchResults[0].score;
    idSWFScriptVar::Free(this: &v13);
    v13.value.i = score;
    v13.type = SWF_VAR_INTEGER;
    idStr::idStr(this: &v18, text: "matchResultScore");
    idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v18, value: &v13);
    idStr::FreeData(this: &v18);
    idSWFScriptVar::Free(this: &v13);
    MatchTimeStr = idMatchResults::GetMatchTimeStr(
                     this: (idMatchResults *)&v20.score,
                     result: (idStr *)playerMatchResults);
    v14.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v14);
    v14.type = SWF_VAR_STRING;
    v14.value.i = (int)idSWFScriptString::Alloc(s: MatchTimeStr);
    idStr::idStr(this: &v19, text: "matchResultTime");
    idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v19, value: &v14);
    idStr::FreeData(this: &v19);
    idSWFScriptVar::Free(this: &v14);
    idStr::FreeData(this: (idStr *)&v20.score);
    v15.type = SWF_VAR_UNDEF;
    xpGained = playerMatchResults[0].xpGained;
    idSWFScriptVar::Free(this: &v15);
    v15.value.i = xpGained;
    v15.type = SWF_VAR_INTEGER;
    idStr::idStr(this: &v17, text: "matchResultXP");
    idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v17, value: &v15);
    idStr::FreeData(this: &v17);
    idSWFScriptVar::Free(this: &v15);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_getPostGameResults_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$513239
// EA  : 0x82DC9870
// RVA : 0x00DC9870
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513239()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 240));
}


// ========================================================================
// __unwind$513240
// EA  : 0x82DC9898
// RVA : 0x00DC9898
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513240()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 384 + 80));
}


// ========================================================================
// __unwind$513241
// EA  : 0x82DC98C0
// RVA : 0x00DC98C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513241()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 112));
}


// ========================================================================
// __unwind$513242
// EA  : 0x82DC98E8
// RVA : 0x00DC98E8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513242()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 384 + 88));
}


// ========================================================================
// __unwind$513243
// EA  : 0x82DC9910
// RVA : 0x00DC9910
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513243()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 176));
}


// ========================================================================
// __unwind$513244
// EA  : 0x82DC9938
// RVA : 0x00DC9938
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513244()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 272));
}


// ========================================================================
// __unwind$513245
// EA  : 0x82DC9960
// RVA : 0x00DC9960
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513245()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$513246
// EA  : 0x82DC9988
// RVA : 0x00DC9988
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513246()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 208));
}


// ========================================================================
// __unwind$513247
// EA  : 0x82DC99B0
// RVA : 0x00DC99B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513247()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 384 + 104));
}


// ========================================================================
// __unwind$513248
// EA  : 0x82DC99D8
// RVA : 0x00DC99D8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513248()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 144));
}


// ========================================================================
// ?Call@idSWFScriptFunction_showPopupDialog@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DC9A08
// RVA : 0x00DC9A08
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showPopupDialog *__fastcall idMainMenu::idSWFScriptFunction_showPopupDialog::Call(
        idMainMenu::idSWFScriptFunction_showPopupDialog *this,
        idSWFScriptVar *result,
        __int64 parms,
        __int64 a4,
        __int64 a5)
{
  idStr **v6; // r29
  int v9; // r11
  char v10; // r11
  bool v11; // zf
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  idStr *v15; // r30
  size_t len; // r25
  __int64 v17; // r8
  __int64 v18; // r6
  idSWF *inited; // r3
  __int64 v20; // r10
  idSWF *v21; // r30
  idStr *v22; // r4
  char v23; // r11
  idSWFScriptVar *v24; // r3
  idStr *v25; // r4
  char v26; // r11
  idSWFScriptVar *v27; // r3
  idStr *v28; // r4
  char v29; // r11
  idSWFScriptVar *v30; // r3
  idStr *v31; // r4
  char v32; // r11
  idSWFScriptVar *v33; // r3
  idSWFScriptVar v34; // [sp+58h] [-128h] BYREF
  idSWFScriptVar v35; // [sp+60h] [-120h] BYREF
  idSWFScriptVar v36; // [sp+68h] [-118h] BYREF
  idSWFScriptVar v37[2]; // [sp+70h] [-110h] BYREF
  idStr v38; // [sp+80h] [-100h] BYREF
  idStr v39; // [sp+A0h] [-E0h] BYREF
  idStr v40; // [sp+C0h] [-C0h] BYREF
  idStr v41; // [sp+E0h] [-A0h] BYREF
  idStr v42; // [sp+100h] [-80h] BYREF
  idStr v43[3]; // [sp+120h] [-60h] BYREF

  v6 = (idStr **)parms;
  if ( *(int *)(parms + 4) >= 2 )
  {
    v9 = **(_DWORD **)parms;
    if ( v9 == 1 || (v11 = v9 != 0, v10 = 0, !v11) )
      v10 = 1;
    if ( v10 != 0 )
    {
      idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v39, result: *(idStr **)parms, a3: parms, a4, a5);
      idSWFScriptVar::ToString(
        this: (idSWFScriptVar *)&v38,
        result: (idStr *)&(*v6)->allocedAndFlag,
        a3: v14,
        a4: v13,
        a5: v12);
      v15 = (idStr *)(result->value.i + 692);
      len = v38.len;
      idStr::EnsureAlloced(this: v15, amount: v38.len + 1, keepold: false, geometricGrowth: false);
      memcpy(Dst: v15->data, Src: v38.data, Size: len);
      v15->data[len] = 0;
      v15->len = len;
      inited = idMainMenu::InitPopupGui(this: (idMainMenu *)result->value.i, filename: v39.data);
      LODWORD(v20) = v6[1];
      v21 = inited;
      if ( (int)v20 >= 3 )
      {
        v22 = (idStr *)&(*v6)->baseBuffer[4];
        if ( v22->len == 1 || (v23 = 0, v22->len == 0) )
          v23 = 1;
        if ( v23 != 0 )
        {
          v24 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v42, result: v22, a3: v18, a4: v17, a5: v20);
          idSWFScriptVar::idSWFScriptVar(this: &v36, s: (const idStr *)v24);
          idSWFScriptObject::Set(this: v21->globals, name: "dialogPopupText", value: &v36);
          idSWFScriptVar::Free(this: &v36);
          idStr::FreeData(this: &v42);
        }
      }
      if ( (int)v6[1] >= 4 )
      {
        v25 = (idStr *)&(*v6)->baseBuffer[12];
        if ( v25->len == 1 || (v26 = 0, v25->len == 0) )
          v26 = 1;
        if ( v26 != 0 )
        {
          v27 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v40, result: v25, a3: v18, a4: v17, a5: v20);
          idSWFScriptVar::idSWFScriptVar(this: v37, s: (const idStr *)v27);
          idSWFScriptObject::Set(this: v21->globals, name: "dialogPopupOption1", value: v37);
          idSWFScriptVar::Free(this: v37);
          idStr::FreeData(this: &v40);
        }
      }
      if ( (int)v6[1] >= 5 )
      {
        v28 = *v6 + 1;
        if ( v28->len == 1 || (v29 = 0, v28->len == 0) )
          v29 = 1;
        if ( v29 != 0 )
        {
          v30 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)&v41, result: v28, a3: v18, a4: v17, a5: v20);
          idSWFScriptVar::idSWFScriptVar(this: &v35, s: (const idStr *)v30);
          idSWFScriptObject::Set(this: v21->globals, name: "dialogPopupOption2", value: &v35);
          idSWFScriptVar::Free(this: &v35);
          idStr::FreeData(this: &v41);
        }
      }
      if ( (int)v6[1] >= 6 )
      {
        v31 = (idStr *)((char *)*v6 + 40);
        if ( v31->len == 1 || (v32 = 0, v31->len == 0) )
          v32 = 1;
        if ( v32 != 0 )
        {
          v33 = idSWFScriptVar::ToString(this: (idSWFScriptVar *)v43, result: v31, a3: v18, a4: v17, a5: v20);
          idSWFScriptVar::idSWFScriptVar(this: &v34, s: (const idStr *)v33);
          idSWFScriptObject::Set(this: v21->globals, name: "dialogPopupOption3", value: &v34);
          idSWFScriptVar::Free(this: &v34);
          idStr::FreeData(this: v43);
        }
      }
      idSWF::Activate(this: v21, b: true);
      this->__vftable = (idMainMenu::idSWFScriptFunction_showPopupDialog_vtbl *)4;
      idStr::FreeData(this: &v38);
      idStr::FreeData(this: &v39);
      return this;
    }
    else
    {
      idLib::Warning(fmt: "Invalid popup specified for showPopupDialog");
      this->__vftable = (idMainMenu::idSWFScriptFunction_showPopupDialog_vtbl *)4;
      return this;
    }
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for showPopupDialog");
    this->__vftable = (idMainMenu::idSWFScriptFunction_showPopupDialog_vtbl *)4;
    return this;
  }
}


// ========================================================================
// __unwind$513411
// EA  : 0x82DC9D38
// RVA : 0x00DC9D38
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513411()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 384;
  if ( (*(_DWORD *)(v0 - 384 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 404));
  }
}


// ========================================================================
// __unwind$513414
// EA  : 0x82DC9D7C
// RVA : 0x00DC9D7C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513414()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 160));
}


// ========================================================================
// __unwind$513415
// EA  : 0x82DC9DA4
// RVA : 0x00DC9DA4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513415()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 128));
}


// ========================================================================
// __unwind$513416
// EA  : 0x82DC9DCC
// RVA : 0x00DC9DCC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513416()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 256));
}


// ========================================================================
// __unwind$513417
// EA  : 0x82DC9DF4
// RVA : 0x00DC9DF4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513417()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 384 + 104));
}


// ========================================================================
// __unwind$513418
// EA  : 0x82DC9E1C
// RVA : 0x00DC9E1C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513418()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 192));
}


// ========================================================================
// __unwind$513419
// EA  : 0x82DC9E44
// RVA : 0x00DC9E44
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513419()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 384 + 112));
}


// ========================================================================
// __unwind$513420
// EA  : 0x82DC9E6C
// RVA : 0x00DC9E6C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513420()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 224));
}


// ========================================================================
// __unwind$513421
// EA  : 0x82DC9E94
// RVA : 0x00DC9E94
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513421()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 384 + 96));
}


// ========================================================================
// __unwind$513422
// EA  : 0x82DC9EBC
// RVA : 0x00DC9EBC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513422()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 384 + 288));
}


// ========================================================================
// __unwind$513423
// EA  : 0x82DC9EE4
// RVA : 0x00DC9EE4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513423()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 384 + 88));
}


// ========================================================================
// ?ClearLeaderboard@idMainMenu@@QAAXXZ
// EA  : 0x82DC9F18
// RVA : 0x00DC9F18
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::ClearLeaderboard(idMainMenu *this)
{
  int v1; // r30
  const idStr *v3; // r21
  const idStr *v4; // r21
  const idStr *v5; // r21
  const idStr *v6; // r21
  idSWFScriptVar v7; // [sp+50h] [-120h] BYREF
  idSWFScriptVar v8; // [sp+58h] [-118h] BYREF
  idSWFScriptVar v9; // [sp+60h] [-110h] BYREF
  idSWFScriptVar v10; // [sp+68h] [-108h] BYREF
  idStr v11; // [sp+70h] [-100h] BYREF
  idStr v12; // [sp+90h] [-E0h] BYREF
  idStr v13; // [sp+B0h] [-C0h] BYREF
  idStr v14; // [sp+D0h] [-A0h] BYREF
  idStr v15[4]; // [sp+F0h] [-80h] BYREF

  v1 = 0;
  v11.len = 0;
  v11.baseBuffer[0] = 0;
  v11.allocedAndFlag = 20;
  v11.data = v11.baseBuffer;
  do
  {
    idStr::Format(this: &v11, fmt: "lbDataRank%d", v1);
    v9.type = SWF_VAR_UNDEF;
    v3 = idStr::idStr(this: &v14, text: &byte_8200D768);
    idSWFScriptVar::Free(this: &v9);
    v9.type = SWF_VAR_STRING;
    v9.value.i = (int)idSWFScriptString::Alloc(s: v3);
    idStr::FreeData(this: &v14);
    idMainMenu::SetMainMenuGlobal(this, name: &v11, value: &v9);
    idSWFScriptVar::Free(this: &v9);
    idStr::Format(this: &v11, fmt: "lbDataName%d", v1);
    v7.type = SWF_VAR_UNDEF;
    v4 = idStr::idStr(this: &v12, text: &byte_8200D768);
    idSWFScriptVar::Free(this: &v7);
    v7.type = SWF_VAR_STRING;
    v7.value.i = (int)idSWFScriptString::Alloc(s: v4);
    idStr::FreeData(this: &v12);
    idMainMenu::SetMainMenuGlobal(this, name: &v11, value: &v7);
    idSWFScriptVar::Free(this: &v7);
    idStr::Format(this: &v11, fmt: "lbDataFieldA%d", v1);
    v8.type = SWF_VAR_UNDEF;
    v5 = idStr::idStr(this: &v13, text: &byte_8200D768);
    idSWFScriptVar::Free(this: &v8);
    v8.type = SWF_VAR_STRING;
    v8.value.i = (int)idSWFScriptString::Alloc(s: v5);
    idStr::FreeData(this: &v13);
    idMainMenu::SetMainMenuGlobal(this, name: &v11, value: &v8);
    idSWFScriptVar::Free(this: &v8);
    idStr::Format(this: &v11, fmt: "lbDataFieldB%d", v1);
    v10.type = SWF_VAR_UNDEF;
    v6 = idStr::idStr(this: v15, text: &byte_8200D768);
    idSWFScriptVar::Free(this: &v10);
    v10.type = SWF_VAR_STRING;
    v10.value.i = (int)idSWFScriptString::Alloc(s: v6);
    idStr::FreeData(this: v15);
    idMainMenu::SetMainMenuGlobal(this, name: &v11, value: &v10);
    idSWFScriptVar::Free(this: &v10);
    ++v1;
  }
  while ( v1 < 10 );
  idLBCache::Reset(this: this->lbCache);
  idStr::FreeData(this: &v11);
}


// ========================================================================
// __unwind$513704
// EA  : 0x82DCA10C
// RVA : 0x00DCA10C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513704()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$513733
// EA  : 0x82DCA134
// RVA : 0x00DCA134
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513733()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 208));
}


// ========================================================================
// __unwind$513705
// EA  : 0x82DCA15C
// RVA : 0x00DCA15C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513705()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 96));
}


// ========================================================================
// __unwind$513753
// EA  : 0x82DCA184
// RVA : 0x00DCA184
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513753()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 144));
}


// ========================================================================
// __unwind$513706
// EA  : 0x82DCA1AC
// RVA : 0x00DCA1AC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513706()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$513773
// EA  : 0x82DCA1D4
// RVA : 0x00DCA1D4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513773()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 176));
}


// ========================================================================
// __unwind$513707
// EA  : 0x82DCA1FC
// RVA : 0x00DCA1FC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513707()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 88));
}


// ========================================================================
// __unwind$513793
// EA  : 0x82DCA224
// RVA : 0x00DCA224
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513793()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 240));
}


// ========================================================================
// __unwind$513708
// EA  : 0x82DCA24C
// RVA : 0x00DCA24C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513708()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 368 + 104));
}


// ========================================================================
// ?GoBack@idMainMenu@@QAAXXZ
// EA  : 0x82DCA340
// RVA : 0x00DCA340
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::GoBack(idMainMenu *this)
{
  idLobbyBase *v1; // r3
  const idMatchParameters *v2; // r29
  idLobbyBase *v3; // r3
  const idMatchParameters *v4; // r3
  char v5; // r28
  idMatchParameters v6; // [sp+50h] [-1280h] BYREF

  idLobbyController::Reset(this: this->lobbyController);
  if ( session->GetState(this: session) >= GAME_LOBBY )
  {
    v1 = session->GetGameLobbyBase(this: session);
    v2 = v1->GetMatchParms(this: v1);
    v3 = session->GetPartyLobbyBase(this: session);
    v4 = v3->GetMatchParms(this: v3);
    idMatchParameters::idMatchParameters(this: &v6, __that: v4);
    v5 = v6.matchFlags & 0x10;
    idMatchParameters::operator=(this: &v6, __that: v2);
    v6.matchFlags = v2->matchFlags & 0xEF | v5;
    session->UpdatePartyParms(this: session, a2: &v6);
    idMatchParameters::~idMatchParameters(this: &v6);
  }
  session->Cancel(this: session);
}


// ========================================================================
// __unwind$513915
// EA  : 0x82DCA43C
// RVA : 0x00DCA43C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513915()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4816 + 80));
}


// ========================================================================
// ?GenerateMatchParms@idMainMenu@@QBA?AVidMatchParameters@@_N@Z
// EA  : 0x82DCA470
// RVA : 0x00DCA470
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu *__fastcall idMainMenu::GenerateMatchParms(idMainMenu *this, idMainMenu *result, bool useDefaults)
{
  int v6; // r29
  int matchMapIndex; // r20
  int matchModeIndex; // r24
  int matchSearchIndex; // r18
  int matchTypeIndex; // r21
  idPlayerProfile *v11; // r4
  int v12; // r4
  int v13; // r27
  int v14; // r30
  char v15; // r11
  int v16; // r11
  char v17; // r10
  int v18; // r9
  const idStrStatic<128> *v19; // r27
  int v20; // r30
  int v21; // r25
  unsigned __int8 SessionMatchFlagsForGameType; // r15
  idMainMenu *scoreLimit; // r11
  int v24; // r6
  int v25; // r5
  idMainMenu::idSWFScriptFunction_ps3ShowFriends_vtbl *v26; // r10
  idMainMenu *v27; // r9
  idMainMenu::idSWFScriptFunction_ps3ShowNotifications_vtbl *v28; // r8
  int v29; // r7
  int v30; // r28
  const idStr *v32; // [sp+8h] [-1E8h]
  int v33; // [sp+8h] [-1E8h]
  const idStr *v34; // [sp+Ch] [-1E4h]
  int v35; // [sp+Ch] [-1E4h]
  const idStr *v36; // [sp+10h] [-1E0h]
  int v37; // [sp+10h] [-1E0h]
  const idStr *v38; // [sp+14h] [-1DCh]
  int v39; // [sp+14h] [-1DCh]
  int v40; // [sp+18h] [-1D8h]
  int v41; // [sp+18h] [-1D8h]
  int v42; // [sp+1Ch] [-1D4h]
  int v43; // [sp+1Ch] [-1D4h]
  int v44; // [sp+20h] [-1D0h]
  bool v45; // [sp+27h] [-1C9h]
  bool v46; // [sp+2Bh] [-1C5h]
  bool v47; // [sp+2Fh] [-1C1h]
  bool v48; // [sp+33h] [-1BDh]
  bool v49; // [sp+37h] [-1B9h]
  int v50; // [sp+38h] [-1B8h]
  int v51; // [sp+3Ch] [-1B4h]
  int v52; // [sp+40h] [-1B0h]
  int v53; // [sp+44h] [-1ACh]
  int v54; // [sp+48h] [-1A8h]
  int v55; // [sp+4Ch] [-1A4h]
  int v56; // [sp+50h] [-1A0h]
  int v57; // [sp+58h] [-198h]
  int v58; // [sp+60h] [-190h]
  int v59; // [sp+68h] [-188h]
  int v60; // [sp+70h] [-180h]
  int v61; // [sp+78h] [-178h]
  const idStr *v62; // [sp+7Ch] [-174h]
  int v63; // [sp+80h] [-170h]
  const idStr *v64; // [sp+84h] [-16Ch]
  int v65; // [sp+88h] [-168h]
  int v66; // [sp+90h] [-160h]
  int v67; // [sp+98h] [-158h]
  int v68; // [sp+A0h] [-150h]
  int v69; // [sp+A8h] [-148h]
  int v70; // [sp+B0h] [-140h]
  int v71; // [sp+B8h] [-138h]
  idStr v72; // [sp+D0h] [-120h] BYREF
  idStr v73; // [sp+F0h] [-100h] BYREF
  idStr v74; // [sp+110h] [-E0h] BYREF
  idStrStatic<128> v75; // [sp+130h] [-C0h] BYREF

  v6 = 0;
  if ( idMainMenu::pMPMaps == nullptr )
    idLib::Error(fmt: "idMainMenu::GenerateMatchParms: mpMaps is invalid");
  matchMapIndex = result->matchMapIndex;
  matchModeIndex = result->matchModeIndex;
  matchSearchIndex = result->matchSearchIndex;
  matchTypeIndex = result->matchTypeIndex;
  if ( useDefaults )
  {
    v11 = common->GetProfileFromMasterLocalUser(this: common);
    if ( v11 != nullptr )
    {
      idMainMenu::EnsureValidIndexes(this: result, profile_: v11);
      if ( matchTypeIndex == 1 )
        matchMapIndex = *(_DWORD *)(v12 + 3584);
    }
  }
  if ( *si_mapNameOverride.valueString.data != 0 )
  {
    v13 = 0;
    if ( result->mpMaps.num > 0 )
    {
      v14 = 0;
      while ( 1 )
      {
        idStr::idStr(this: &v73, text: &result->mpMaps.list[v14].map);
        idStr::StripPath(this: &v73);
        if ( idStr::Icmp(s1: v73.data, s2: si_mapNameOverride.valueString.data) == 0 )
          break;
        idStr::FreeData(this: &v73);
        ++v13;
        ++v14;
        if ( v13 >= result->mpMaps.num )
          goto LABEL_14;
      }
      matchMapIndex = v13;
      idStr::FreeData(this: &v73);
    }
  }
LABEL_14:
  if ( matchMapIndex < 0 || (v15 = 1, matchMapIndex >= result->mpMaps.num) )
    v15 = 0;
  if ( v15 == 0 )
    idLib::Error(
      fmt: "idMainMenu::GenerateMatchParms: gameMapIndex out of range: %d : %d",
      matchMapIndex,
      result->mpMaps.num);
  v16 = (int)&result->mpMaps.list[matchMapIndex];
  if ( matchModeIndex < 0 || (v17 = 1, matchModeIndex >= *(_DWORD *)(v16 + 136)) )
    v17 = 0;
  if ( v17 == 0 )
    idLib::Error(fmt: "idMainMenu::GenerateMatchParms: gameModeIndex out of range");
  v18 = *(_DWORD *)(v16 + 132);
  v72.len = 0;
  v72.baseBuffer[0] = 0;
  v72.allocedAndFlag = 20;
  v72.data = v72.baseBuffer;
  v19 = (const idStrStatic<128> *)(v16 + 4);
  v20 = v18 + 160 * matchModeIndex;
  if ( com_multiplayer.valueInteger != 0 )
  {
    if ( matchTypeIndex == 1 )
    {
      v21 = 2;
    }
    else
    {
      if ( matchTypeIndex != 2 )
        idLib::Error(fmt: "Unknown gameType %i in GetNumSessionSlotsForGameType\n", matchTypeIndex);
      v21 = 6;
    }
  }
  else
  {
    v21 = 6;
  }
  SessionMatchFlagsForGameType = GetSessionMatchFlagsForGameType(gameType: matchTypeIndex, useDefaults);
  idStr::idStr(this: &v75, text: &byte_8200D768);
  idStr::idStr(this: &v74, text: "player_start");
  idMatchParameters::idMatchParameters(
    (idMatchParameters *)this,
    gameMode_: matchModeIndex,
    searchMode_: matchSearchIndex,
    gameMap_: matchMapIndex,
    gameType_: matchTypeIndex,
    numSlots_: v21,
    matchFlags_: SessionMatchFlagsForGameType,
    mapName_: v19,
    minRespawnDelay_: si_minRespawnDelay.valueFloat,
    timeLimit_: si_timeLimit.valueFloat,
    layersActive_: v32,
    layersDeactive_: v34,
    spawnSpot_: v36,
    debugJobName_: v38,
    debugJobState_: v40,
    scoreLimit_: v42,
    teamCount_: v44,
    swapTeams_: v45,
    stopWatch_: v46,
    comboMap_: v47,
    devmap_: v48,
    isTransitionalMapRequest_: v49,
    a23: v50,
    a24: v51,
    a25: v52,
    a26: v53,
    a27: v54,
    a28: v55,
    a29: v56,
    a30: (const idStrStatic<2048> *)(v20 + 8),
    a31: v57,
    a32: (const idStrStatic<2048> *)&v72,
    a33: v58,
    a34: &v74,
    a35: v59,
    a36: &v75,
    a37: v60,
    layersActive_a: nullptr,
    a39: v61,
    layersDeactive_a: v62,
    a41: v63,
    spawnSpot_a: v64,
    a43: v65,
    debugJobName_a: (const idStr *)si_scoreLimit.valueInteger,
    a45: v66,
    debugJobState_a: si_teamCount.valueInteger,
    a47: v67,
    a48: false,
    a49: v68,
    a50: false,
    a51: v69,
    scoreLimit__3: net_useCMap.valueInteger != 0,
    a53: v70,
    teamCount__3: si_multiplayerTestWeapons.valueInteger != 0,
    a55: v71,
    swapTeams_a: false);
  idStr::FreeData(this: &v74);
  idStr::FreeData(this: &v75);
  if ( matchTypeIndex == 2 )
  {
    if ( useDefaults )
      common->GetProfileFromMasterLocalUser(this: common);
    this->scriptFunction_checkActivateRenderDemo.__vftable = (idMainMenu::idSWFScriptFunction_checkActivateRenderDemo_vtbl *)result->timeLimit;
    if ( useDefaults )
      common->GetProfileFromMasterLocalUser(this: common);
    scoreLimit = (idMainMenu *)result->scoreLimit;
    BYTE1(this->scriptFunction_isDemoMode.pThis) = 1;
    BYTE2(this->scriptFunction_isDemoMode.pThis) = 1;
    LOBYTE(this->scriptFunction_isDemoMode.pThis) = 1;
    HIBYTE(this->scriptFunction_showDLCOption.__vftable) = 1;
    this->scriptFunction_checkActivateRenderDemo.pThis = scoreLimit;
    BYTE1(this->scriptFunction_showDLCOption.__vftable) = 1;
    BYTE2(this->scriptFunction_showDLCOption.__vftable) = 1;
  }
  else if ( matchTypeIndex == 1 )
  {
    this->scriptFunction_ps3ShowNotifications.pThis = (idMainMenu *)idMainMenu::GetCoopDifficulty(
                                                                      this: result,
                                                                      defaults: useDefaults);
    this->scriptFunction_showDLCOption.pThis = *(idMainMenu **)(v20 + 124);
    v26 = *(idMainMenu::idSWFScriptFunction_ps3ShowFriends_vtbl **)(v20 + 144);
    this->scriptFunction_ps3ShowFriends.__vftable = v26;
    v27 = *(idMainMenu **)(v20 + 148);
    this->scriptFunction_ps3ShowFriends.pThis = v27;
    v28 = *(idMainMenu::idSWFScriptFunction_ps3ShowNotifications_vtbl **)(v20 + 152);
    this->scriptFunction_ps3ShowNotifications.__vftable = v28;
    v29 = *(_DWORD *)(v20 + 132);
    if ( v29 > 0 )
    {
      v30 = 0;
      do
      {
        idMatchParameters::AddCompletionStat(
          (idMatchParameters *)this,
          newValue: *(_DWORD *)(*(_DWORD *)(v20 + 128) + v30),
          a3: v25,
          a4: v24,
          a5: v29,
          a6: (int)v28,
          a7: (int)v27,
          a8: (int)v26,
          a9: v33,
          a10: v35,
          a11: v37,
          a12: v39,
          a13: v41,
          a14: v43);
        v26 = *(idMainMenu::idSWFScriptFunction_ps3ShowFriends_vtbl **)(v20 + 132);
        ++v6;
        v30 += 4;
      }
      while ( v6 < (int)v26 );
    }
  }
  idStr::FreeData(this: &v72);
  return this;
}


// ========================================================================
// $LN150_0
// EA  : 0x82DCA874
// RVA : 0x00DCA874
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _LN150_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 240));
}


// ========================================================================
// __unwind$513954
// EA  : 0x82DCA89C
// RVA : 0x00DCA89C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513954()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 208));
}


// ========================================================================
// __unwind$513955
// EA  : 0x82DCA8C4
// RVA : 0x00DCA8C4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513955()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 304));
}


// ========================================================================
// __unwind$513956
// EA  : 0x82DCA8EC
// RVA : 0x00DCA8EC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513956()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 496 + 272));
}


// ========================================================================
// __unwind$513957
// EA  : 0x82DCA914
// RVA : 0x00DCA914
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_513957()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 496;
  if ( (*(_DWORD *)(v0 - 496 + 192) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 192) &= ~1u;
    idMatchParameters::~idMatchParameters(this: *(idMatchParameters **)(v1 + 516));
  }
}


// ========================================================================
// ?SetLeaderboardIndex@idMainMenu@@QAAX_N@Z
// EA  : 0x82DCA960
// RVA : 0x00DCA960
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetLeaderboardIndex(idMainMenu *this, bool isVDM)
{
  int v3; // r30
  idSWFScriptVar::swfScriptVarType type; // r11
  idSWFScriptVar::swfScriptVarType vdmLBIndex; // r10
  idSWFScriptVar::swfScriptVarType coopLBIndex; // r10
  const leaderboardDefinition_t *lb; // r28
  int v8; // r27
  const columnDef_t *v9; // r11
  __int64 v10; // r6
  __int64 v11; // r10
  __int64 v12; // r8
  va *v13; // r3
  idMainMenu::coopLeaderboard_t *v14; // r10
  int nightmareLeaderboardId; // r11
  int v16; // r27
  const columnDef_t *v17; // r11
  __int64 v18; // r6
  __int64 v19; // r10
  __int64 v20; // r8
  va *v21; // r3
  int v22; // [sp+8h] [-10A8h]
  int v23; // [sp+Ch] [-10A4h]
  int v24; // [sp+10h] [-10A0h]
  int v25; // [sp+14h] [-109Ch]
  int v26; // [sp+18h] [-1098h]
  int v27; // [sp+1Ch] [-1094h]
  idSWFScriptVar v28; // [sp+50h] [-1060h] BYREF
  idSWFScriptVar v29; // [sp+58h] [-1058h] BYREF
  va v30; // [sp+60h] [-1050h] BYREF

  v3 = 0;
  if ( isVDM )
  {
    vdmLBIndex = this->vdmLBIndex;
    v28.type = this->roadRageLeaderboards.num;
    type = v28.type;
    if ( vdmLBIndex >= v28.type )
    {
      this->vdmLBIndex = 0;
      goto LABEL_11;
    }
    if ( vdmLBIndex < SWF_VAR_STRINGID )
    {
      this->vdmLBIndex = v28.type - 1;
LABEL_10:
      v28.type = type;
    }
  }
  else
  {
    coopLBIndex = this->coopLBIndex;
    v28.type = this->coopLeaderboards.num;
    type = v28.type;
    if ( coopLBIndex >= v28.type )
    {
      this->coopLBIndex = 0;
      goto LABEL_11;
    }
    if ( coopLBIndex < SWF_VAR_STRINGID )
    {
      this->coopLBIndex = v28.type - 1;
      goto LABEL_10;
    }
  }
LABEL_11:
  if ( isVDM )
  {
    lb = this->roadRageLeaderboards.list[this->vdmLBIndex].lb;
    if ( lb->numColumns > 0 )
    {
      v8 = 0;
      do
      {
        v9 = &lb->columnDefs[v8];
        if ( v9->displayType != STATS_COLUMN_NEVER_DISPLAY )
        {
          idSWFScriptVar::idSWFScriptVar(this: &v28, s: v9->locDisplayName);
          HIDWORD(v10) = v3;
          v13 = va::va(
                  this: &v30,
                  fmt: "columnname%d",
                  a3: v10,
                  a4: v12,
                  a5: v11,
                  a6: v22,
                  a7: v23,
                  a8: v24,
                  a9: v25,
                  a10: v26,
                  a11: v27);
          idSWFScriptObject::Set(this: gameLocal->mainMenu->mainMenu->globals, name: v13->buffer, value: &v28);
          idSWFScriptVar::Free(this: &v28);
        }
        ++v3;
        ++v8;
      }
      while ( v3 < lb->numColumns );
    }
  }
  else
  {
    v14 = &this->coopLeaderboards.list[this->coopLBIndex];
    if ( this->viewCoopNightmareLeaderboard )
      nightmareLeaderboardId = v14->nightmareLeaderboardId;
    else
      nightmareLeaderboardId = v14->leaderboardId;
    lb = rageMPCoopLeaderboards[nightmareLeaderboardId];
    if ( lb->numColumns > 0 )
    {
      v16 = 0;
      do
      {
        v17 = &lb->columnDefs[v16];
        if ( v17->displayType != STATS_COLUMN_NEVER_DISPLAY )
        {
          idSWFScriptVar::idSWFScriptVar(this: &v29, s: v17->locDisplayName);
          HIDWORD(v18) = v3;
          v21 = va::va(
                  this: &v30,
                  fmt: "columnname%d",
                  a3: v18,
                  a4: v20,
                  a5: v19,
                  a6: v22,
                  a7: v23,
                  a8: v24,
                  a9: v25,
                  a10: v26,
                  a11: v27);
          idSWFScriptObject::Set(this: gameLocal->mainMenu->mainMenu->globals, name: v21->buffer, value: &v29);
          idSWFScriptVar::Free(this: &v29);
        }
        ++v3;
        ++v16;
      }
      while ( v3 < lb->numColumns );
    }
  }
  idLBCache::SetLeaderboard(this: this->lbCache, def_: lb, filter_: this->lbCache->filter);
  this->refreshLeaderboard = true;
}


// ========================================================================
// __unwind$514219
// EA  : 0x82DCAB7C
// RVA : 0x00DCAB7C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514219()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4272 + 80));
}


// ========================================================================
// __unwind$514220
// EA  : 0x82DCABA4
// RVA : 0x00DCABA4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514220()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4272 + 88));
}


// ========================================================================
// ?CopySettingsToSession@idMainMenu@@QAAX_N@Z
// EA  : 0x82DCABD8
// RVA : 0x00DCABD8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::CopySettingsToSession(idMainMenu *this, bool forceUpdateParty)
{
  idSession::sessionState_t v4; // r3
  char v5; // r11
  idMainMenu *matched; // r3
  idMainMenu *v7; // r3
  idMainMenu v8; // [sp+50h] [-1280h] BYREF

  if ( session->GetState(this: session) == PARTY_LOBBY
    || (v4 = session->GetState(this: session), v5 = 0, v4 == GAME_LOBBY) )
  {
    v5 = 1;
  }
  if ( v5 != 0 && net_headlessServer.valueInteger == 0 )
  {
    if ( session->GetState(this: session) == PARTY_LOBBY || forceUpdateParty )
    {
      matched = idMainMenu::GenerateMatchParms(this: &v8, result: this, useDefaults: false);
      session->UpdatePartyParms(this: session, a2: (const idMatchParameters *)matched);
      idMatchParameters::~idMatchParameters(this: (idMatchParameters *)&v8);
    }
    if ( session->GetState(this: session) == GAME_LOBBY )
    {
      v7 = idMainMenu::GenerateMatchParms(this: &v8, result: this, useDefaults: false);
      session->UpdateMatchParms(this: session, a2: (const idMatchParameters *)v7);
      idMatchParameters::~idMatchParameters(this: (idMatchParameters *)&v8);
    }
  }
}


// ========================================================================
// __unwind$514347
// EA  : 0x82DCAD0C
// RVA : 0x00DCAD0C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514347()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4816 + 80));
}


// ========================================================================
// __unwind$514348
// EA  : 0x82DCAD34
// RVA : 0x00DCAD34
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514348()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4816 + 80));
}


// ========================================================================
// ?CopySettingsFromSession@idMainMenu@@QAAXXZ
// EA  : 0x82DCAD60
// RVA : 0x00DCAD60
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::CopySettingsFromSession(idMainMenu *this)
{
  idSession::sessionState_t v2; // r3
  char v3; // r11
  bool v4; // cr58
  idSession_vtbl *v5; // r11
  int v6; // r3
  int v7; // r31
  idSession_vtbl *v8; // r11
  int (*GetActingGameStateLobbyBase)(void); // r10
  int v10; // r3
  int v11; // r31

  if ( session->GetState(this: session) == GAME_LOBBY
    || (v2 = session->GetState(this: session), v3 = 0, v2 == PARTY_LOBBY) )
  {
    v3 = 1;
  }
  if ( v3 != 0 )
  {
    v4 = session->GetState(this: session) == PARTY_LOBBY;
    v5 = session->__vftable;
    if ( v4 )
    {
      v6 = ((int (*)(void))v5->GetPartyLobbyBase)();
      v7 = (*(int (__fastcall **)(int))(*(_DWORD *)v6 + 128))(a1: v6);
      idMainMenu::SetMatchTypeIndex(this, index: *(_DWORD *)(v7 + 12));
      idMainMenu::SetMatchMapIndex(this, index: *(_DWORD *)(v7 + 8));
      idMainMenu::SetMatchModeIndex(this, index: *(_DWORD *)v7);
      this->matchSearchIndex = *(_DWORD *)(v7 + 4);
      this->privateMatch = (*(_BYTE *)(v7 + 20) & 8) != 0;
      this->localMatch = (~*(unsigned __int8 *)(v7 + 20) & 2) != 0;
      if ( *(_DWORD *)(v7 + 12) == 1 )
        idMainMenu::SetCoopPrivacy(this, newPrivacy: (*(_BYTE *)(v7 + 20) & 0x10) != 0, storeDefaults: false);
    }
    else if ( ((int (*)(void))v5->GetState)() == 5 )
    {
      v8 = session->__vftable;
      if ( net_headlessServer.valueInteger != 0 )
        GetActingGameStateLobbyBase = (int (*)(void))v8->GetActingGameStateLobbyBase;
      else
        GetActingGameStateLobbyBase = (int (*)(void))v8->GetGameLobbyBase;
      v10 = GetActingGameStateLobbyBase();
      v11 = (*(int (__fastcall **)(int))(*(_DWORD *)v10 + 128))(a1: v10);
      idMainMenu::SetMatchTypeIndex(this, index: *(_DWORD *)(v11 + 12));
      idMainMenu::SetMatchMapIndex(this, index: *(_DWORD *)(v11 + 8));
      idMainMenu::SetMatchModeIndex(this, index: *(_DWORD *)v11);
      this->matchSearchIndex = *(_DWORD *)(v11 + 4);
      this->privateMatch = (*(_BYTE *)(v11 + 20) & 8) != 0;
      this->localMatch = (~*(unsigned __int8 *)(v11 + 20) & 2) != 0;
      if ( *(_DWORD *)(v11 + 12) == 1 )
        idMainMenu::SetCoopDifficulty(this, newDifficulty: *(_DWORD *)(v11 + 4680), storeDefaults: false);
      idMainMenu::SetTimeLimit(this, newTimeLimit: *(_DWORD *)(v11 + 4604), storeDefaults: false);
      idMainMenu::SetScoreLimit(this, newScoreLimit: *(_DWORD *)(v11 + 4608), storeDefaults: false);
    }
    idMainMenu::CopySettingsToSession(this, forceUpdateParty: false);
  }
}


// ========================================================================
// ?ShowLeaveLobbyDialog@idMainMenu@@QAAX_N0@Z
// EA  : 0x82DCAF80
// RVA : 0x00DCAF80
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::ShowLeaveLobbyDialog(idMainMenu *this, bool askLeaveWithTeam, bool askLeaveTeam)
{
  _DWORD *v4; // r3
  int v5; // r11
  _DWORD *v6; // r3
  int v7; // r11
  _DWORD *v8; // r3
  int v9; // r11
  idStrStatic<256> *v10; // r3
  _DWORD *v11; // r3
  _DWORD *v12; // r26
  _DWORD *v13; // r3
  _DWORD *v14; // r6
  _DWORD *v15; // r3
  _DWORD *v16; // r26
  _DWORD *v17; // r3
  _DWORD *v18; // r6
  idStrId v19[4]; // [sp+70h] [-1C0h] BYREF
  idList<idVehicleState *,5> v20; // [sp+80h] [-1B0h] BYREF
  _BYTE v21[16]; // [sp+90h] [-1A0h] BYREF
  idStrId v22; // [sp+A0h] [-190h] BYREF
  idStrId v23; // [sp+A4h] [-18Ch] BYREF
  idStrId v24[2]; // [sp+A8h] [-188h] BYREF
  idList<enum encounterGroupRole_t,5> v25; // [sp+B0h] [-180h] BYREF
  int v26; // [sp+C0h] [-170h] BYREF
  idStrStatic<256> v27; // [sp+D0h] [-160h] BYREF

  if ( askLeaveWithTeam )
  {
    *(_QWORD *)&v25.num = 4;
    v25.list = (encounterGroupRole_t *)&v26;
    *(_DWORD *)&v25.granularity = 66817;
    *(_QWORD *)&v20.num = 4;
    v20.list = (idVehicleState **)v21;
    *(_DWORD *)&v20.granularity = 66817;
    memset(v21, 255, sizeof(v21));
    v4 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 0xCu,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v4 != nullptr )
    {
      v4[2] = this;
      v4[1] = 0;
      v5 = (int)v4;
      *v4 = &`idMainMenu::ShowLeaveLobbyDialog'::`2'::idSWFScriptFunction_LeaveWithParty::`vftable';
    }
    else
    {
      v5 = 0;
    }
    v19[0].index = v5;
    idList<idAnimWebBlendTree *,5>::Append(this: &v25, obj: (encounterGroupRole_t *)v19);
    v6 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 0xCu,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v6 != nullptr )
    {
      v6[2] = this;
      v6[1] = 0;
      v7 = (int)v6;
      *v6 = &`idMainMenu::ShowLeaveLobbyDialog'::`4'::idSWFScriptFunction_LeaveCancel::`vftable';
    }
    else
    {
      v7 = 0;
    }
    v19[0].index = v7;
    idList<idAnimWebBlendTree *,5>::Append(this: &v25, obj: (encounterGroupRole_t *)v19);
    v8 = idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
           size: 0xCu,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
    if ( v8 != nullptr )
    {
      v8[2] = this;
      v8[1] = 0;
      v9 = (int)v8;
      *v8 = &`idMainMenu::ShowLeaveLobbyDialog'::`3'::idSWFScriptFunction_LeaveWithoutParty::`vftable';
    }
    else
    {
      v9 = 0;
    }
    v19[0].index = v9;
    idList<idAnimWebBlendTree *,5>::Append(this: &v25, obj: (encounterGroupRole_t *)v19);
    v19[0].index = 0;
    idList<idAnimWebBlendTree *,5>::Append(this: &v25, obj: (encounterGroupRole_t *)v19);
    idStrId::Set(this: v24, key: "#STR_SWF_LEAVE_WITH_PARTY");
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v20, obj: v24);
    idStrId::Set(this: &v23, key: "#STR_SWF_DO_NOT_LEAVE");
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v20, obj: &v23);
    idStrId::Set(this: &v22, key: "#STR_SWF_LEAVE_WITHOUT_PARTY");
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v20, obj: &v22);
    v19[0].index = -1;
    idList<idHandle<int,enum invalidAIEvent_t,-1>,5>::Append(this: (idList<idStrId,5> *)&v20, obj: v19);
    v10 = idStrStatic<256>::idStrStatic<256>(this: &v27, text: &byte_8200D768);
    ((void (__fastcall *)(idCommon *, int, idList<enum encounterGroupRole_t,5> *, idList<idVehicleState *,5> *, _DWORD, idStrStatic<256> *, _DWORD, _DWORD))common->AddDynamicDialog)(
      a1: common,
      a2: 29,
      a3: &v25,
      a4: &v20,
      a5: 0,
      a6: v10,
      a7: 0,
      a8: 0);
    idList<idThread *,58>::Clear(this: &v20);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v25);
  }
  else if ( askLeaveTeam )
  {
    v11 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
            size: 0x10u,
            tag: TAG_SWF,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    if ( v11 != nullptr )
    {
      v11[2] = this;
      v11[3] = 94;
      v12 = v11;
      v11[1] = 0;
      *v11 = &`idMainMenu::ShowLeaveLobbyDialog'::`6'::idSWFScriptFunction_LeaveLobbyNo::`vftable';
    }
    else
    {
      v12 = nullptr;
    }
    v13 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
            size: 0x10u,
            tag: TAG_SWF,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    if ( v13 != nullptr )
    {
      v13[2] = this;
      v13[1] = 0;
      v14 = v13;
      v13[3] = 94;
      *v13 = &`idMainMenu::ShowLeaveLobbyDialog'::`5'::idSWFScriptFunction_LeaveLobbyYes::`vftable';
    }
    else
    {
      v14 = nullptr;
    }
    ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 94,
      a3: 3,
      a4: v14,
      a5: v12,
      a6: 0,
      a7: 0,
      a8: 0);
  }
  else
  {
    v15 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
            size: 0x10u,
            tag: TAG_SWF,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    if ( v15 != nullptr )
    {
      v15[2] = this;
      v15[3] = 93;
      v16 = v15;
      v15[1] = 0;
      *v15 = &`idMainMenu::ShowLeaveLobbyDialog'::`6'::idSWFScriptFunction_LeaveLobbyNo::`vftable';
    }
    else
    {
      v16 = nullptr;
    }
    v17 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
            size: 0x10u,
            tag: TAG_SWF,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    if ( v17 != nullptr )
    {
      v17[2] = this;
      v17[1] = 0;
      v18 = v17;
      v17[3] = 93;
      *v17 = &`idMainMenu::ShowLeaveLobbyDialog'::`5'::idSWFScriptFunction_LeaveLobbyYes::`vftable';
    }
    else
    {
      v18 = nullptr;
    }
    ((void (__fastcall *)(idCommon *, int, int, _DWORD *, _DWORD *, _DWORD, _DWORD, _DWORD))common->AddDialog)(
      a1: common,
      a2: 93,
      a3: 3,
      a4: v18,
      a5: v16,
      a6: 0,
      a7: 0,
      a8: 0);
  }
}


// ========================================================================
// __unwind$514543
// EA  : 0x82DCB3A8
// RVA : 0x00DCB3A8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514543()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 560 + 176));
}


// ========================================================================
// __unwind$514544
// EA  : 0x82DCB3D0
// RVA : 0x00DCB3D0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514544()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 560 + 128));
}


// ========================================================================
// `idMainMenu::ShowLeaveLobbyDialog'::`2'::idSWFScriptFunction_LeaveWithParty::Call
// EA  : 0x82DCB3F8
// RVA : 0x00DCB3F8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ShowLeaveLobbyDialog_::_2_::idSWFScriptFunction_LeaveWithParty::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_LEAVE_WITH_PARTY, a3: nullptr, a4: 0);
  session->SetSessionOption(this: session, a2: OPTION_LEAVE_WITH_PARTY);
  idMainMenu::GoBack(this: (idMainMenu *)thisObject->variables.num);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::ShowLeaveLobbyDialog'::`3'::idSWFScriptFunction_LeaveWithoutParty::Call
// EA  : 0x82DCB480
// RVA : 0x00DCB480
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ShowLeaveLobbyDialog_::_3_::idSWFScriptFunction_LeaveWithoutParty::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: GDM_LEAVE_WITH_PARTY, a3: nullptr, a4: 0);
  session->ClearSessionOption(this: session, a2: OPTION_LEAVE_WITH_PARTY);
  idMainMenu::GoBack(this: (idMainMenu *)thisObject->variables.num);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// `idMainMenu::ShowLeaveLobbyDialog'::`5'::idSWFScriptFunction_LeaveLobbyYes::Call
// EA  : 0x82DCB508
// RVA : 0x00DCB508
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idSWFScriptVar *__fastcall _idMainMenu::ShowLeaveLobbyDialog_::_5_::idSWFScriptFunction_LeaveLobbyYes::Call(
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  common->ClearDialog(this: common, a2: (gameDialogMessages_t)thisObject->variables.size, a3: nullptr, a4: 0);
  idMainMenu::GoBack(this: (idMainMenu *)thisObject->variables.num);
  result->type = SWF_VAR_UNDEF;
  return result;
}


// ========================================================================
// ?ShowNextMatchResultPopup@idMainMenu@@QAAXXZ
// EA  : 0x82DCB580
// RVA : 0x00DCB580
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::ShowNextMatchResultPopup(idMainMenu *this)
{
  idSWF *v2; // r30
  const idDeclVehicleUnlock *ItemUnlock; // r29
  idSWFScriptVar::swfScriptVarValue_t v4; // r25
  char *BigLoadoutImageName; // r3
  int levelRequired; // r29
  const char *String; // r3
  __int64 v8; // r10
  __int64 v9; // r8
  va *v10; // r3
  idSWF *v11; // r3
  int v12; // r30
  idSWF *inited; // r29
  const idStr *CashGainStr; // r25
  int score; // r25
  const idStr *MatchTimeStr; // r25
  int xpGained; // r25
  char *v18; // r3
  const idStr *v19; // r22
  __int64 v20; // r6
  __int64 v21; // r10
  __int64 v22; // r8
  va *v23; // r3
  char *v24; // r3
  const idStr *v25; // r22
  __int64 v26; // r6
  __int64 v27; // r10
  __int64 v28; // r8
  va *v29; // r3
  const char *v30; // r3
  const idStr *v31; // r22
  __int64 v32; // r6
  __int64 v33; // r10
  __int64 v34; // r8
  va *v35; // r3
  int v36; // [sp+8h] [-11A8h]
  int v37; // [sp+8h] [-11A8h]
  int v38; // [sp+8h] [-11A8h]
  int v39; // [sp+Ch] [-11A4h]
  int v40; // [sp+Ch] [-11A4h]
  int v41; // [sp+Ch] [-11A4h]
  int v42; // [sp+10h] [-11A0h]
  int v43; // [sp+10h] [-11A0h]
  int v44; // [sp+10h] [-11A0h]
  int v45; // [sp+14h] [-119Ch]
  int v46; // [sp+14h] [-119Ch]
  int v47; // [sp+14h] [-119Ch]
  int v48; // [sp+18h] [-1198h]
  int v49; // [sp+18h] [-1198h]
  int v50; // [sp+18h] [-1198h]
  int v51; // [sp+1Ch] [-1194h]
  int v52; // [sp+1Ch] [-1194h]
  int v53; // [sp+1Ch] [-1194h]
  idSWFScriptVar v54; // [sp+50h] [-1160h] BYREF
  idSWFScriptVar v55; // [sp+58h] [-1158h] BYREF
  idSWFScriptVar v56; // [sp+60h] [-1150h] BYREF
  idSWFScriptVar v57; // [sp+68h] [-1148h] BYREF
  idSWFScriptVar v58; // [sp+70h] [-1140h] BYREF
  idSWFScriptVar v59; // [sp+78h] [-1138h] BYREF
  idSWFScriptVar v60; // [sp+80h] [-1130h] BYREF
  idSWFScriptVar v61; // [sp+88h] [-1128h] BYREF
  idSWFScriptVar v62; // [sp+90h] [-1120h] BYREF
  idMatchResults v63; // [sp+98h] [-1118h] BYREF
  idStr v64; // [sp+130h] [-1080h] BYREF
  va v65; // [sp+150h] [-1060h] BYREF

  if ( (int)idAnimator_Channel::InternalGetMergeBranch(this: (idDeclEntityDef *)playerMatchResults) <= 0
    || (int)idAnimator_Channel::InternalGetMergeBranch(this: (idDeclEntityDef *)playerMatchResults) <= this->showingUnlockedItemIndex )
  {
    v12 = 0;
    inited = idMainMenu::InitPopupGui(this, filename: "online_popup_results");
    this->showingMatchResults = false;
    this->showingUnlockedItemIndex = 0;
    CashGainStr = idMatchResults::GetCashGainStr(
                    this: (idMatchResults *)v63.statValues,
                    result: (idStr *)playerMatchResults);
    v56.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v56);
    v56.type = SWF_VAR_STRING;
    v56.value.i = (int)idSWFScriptString::Alloc(s: CashGainStr);
    idSWFScriptObject::Set(this: inited->globals, name: "matchResultCash", value: &v56);
    idSWFScriptVar::Free(this: &v56);
    idStr::FreeData(this: (idStr *)v63.statValues);
    v60.type = SWF_VAR_UNDEF;
    score = playerMatchResults[0].score;
    idSWFScriptVar::Free(this: &v60);
    v60.value.i = score;
    v60.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: inited->globals, name: "matchResultScore", value: &v60);
    idSWFScriptVar::Free(this: &v60);
    MatchTimeStr = idMatchResults::GetMatchTimeStr(
                     this: (idMatchResults *)&v63.levelsGained,
                     result: (idStr *)playerMatchResults);
    v54.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v54);
    v54.type = SWF_VAR_STRING;
    v54.value.i = (int)idSWFScriptString::Alloc(s: MatchTimeStr);
    idSWFScriptObject::Set(this: inited->globals, name: "matchResultTime", value: &v54);
    idSWFScriptVar::Free(this: &v54);
    idStr::FreeData(this: (idStr *)&v63.levelsGained);
    v55.type = SWF_VAR_UNDEF;
    xpGained = playerMatchResults[0].xpGained;
    idSWFScriptVar::Free(this: &v55);
    v55.value.i = xpGained;
    v55.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: inited->globals, name: "matchResultXP", value: &v55);
    idSWFScriptVar::Free(this: &v55);
    do
    {
      if ( v12 >= playerMatchResults[0].accoladesEarned.num )
        break;
      idMatchResults::GetAccolade(this: &v63, result: (idAccolade *)playerMatchResults, i: v12);
      v18 = idAccolade::Name(this: (idAccolade *)&v63);
      v57.type = SWF_VAR_UNDEF;
      v19 = idStr::idStr(this: &v64, text: v18);
      idSWFScriptVar::Free(this: &v57);
      v57.type = SWF_VAR_STRING;
      v57.value.i = (int)idSWFScriptString::Alloc(s: v19);
      idStr::FreeData(this: &v64);
      HIDWORD(v20) = v12;
      v23 = va::va(
              this: &v65,
              fmt: "accoladeName%d",
              a3: v20,
              a4: v22,
              a5: v21,
              a6: v36,
              a7: v39,
              a8: v42,
              a9: v45,
              a10: v48,
              a11: v51);
      idSWFScriptObject::Set(this: inited->globals, name: v23->buffer, value: &v57);
      idSWFScriptVar::Free(this: &v57);
      v24 = idAccolade::Description(this: (idAccolade *)&v63);
      v59.type = SWF_VAR_UNDEF;
      v25 = idStr::idStr(this: (idStr *)&v63.itemsUnlocked, text: v24);
      idSWFScriptVar::Free(this: &v59);
      v59.type = SWF_VAR_STRING;
      v59.value.i = (int)idSWFScriptString::Alloc(s: v25);
      idStr::FreeData(this: (idStr *)&v63.itemsUnlocked);
      HIDWORD(v26) = v12;
      v29 = va::va(
              this: &v65,
              fmt: "accoladeDescription%d",
              a3: v26,
              a4: v28,
              a5: v27,
              a6: v37,
              a7: v40,
              a8: v43,
              a9: v46,
              a10: v49,
              a11: v52);
      idSWFScriptObject::Set(this: inited->globals, name: v29->buffer, value: &v59);
      idSWFScriptVar::Free(this: &v59);
      v30 = idAccolade::Icon(this: (idAccolade *)&v63);
      v61.type = SWF_VAR_UNDEF;
      v31 = idStr::idStr(this: (idStr *)&v63.screenMode, text: v30);
      idSWFScriptVar::Free(this: &v61);
      v61.type = SWF_VAR_STRING;
      v61.value.i = (int)idSWFScriptString::Alloc(s: v31);
      idStr::FreeData(this: (idStr *)&v63.screenMode);
      HIDWORD(v32) = v12;
      v35 = va::va(
              this: &v65,
              fmt: "accoladeMaterial%d",
              a3: v32,
              a4: v34,
              a5: v33,
              a6: v38,
              a7: v41,
              a8: v44,
              a9: v47,
              a10: v50,
              a11: v53);
      idSWFScriptObject::Set(this: inited->globals, name: v35->buffer, value: &v61);
      idSWFScriptVar::Free(this: &v61);
      ++v12;
    }
    while ( v12 < 3 );
    v11 = inited;
  }
  else
  {
    v2 = idMainMenu::InitPopupGui(this, filename: "online_popup_unlock");
    ItemUnlock = idMatchResults::GetItemUnlock(this: playerMatchResults, i: this->showingUnlockedItemIndex);
    SLODWORD(v4.f) = ItemUnlock->displayName.index;
    v58.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v58);
    v58.value = v4;
    v58.type = SWF_VAR_STRINGID;
    idSWFScriptObject::Set(this: v2->globals, name: "unlockPopupItemName", value: &v58);
    idSWFScriptVar::Free(this: &v58);
    BigLoadoutImageName = idDeclVehicleUnlock::GetBigLoadoutImageName(this: ItemUnlock);
    idSWFScriptVar::idSWFScriptVar(this: (idSWFScriptVar *)&v63.lobbyUserID.lobbyType, s: BigLoadoutImageName);
    idSWFScriptObject::Set(
      this: v2->globals,
      name: "unlockPopupItemMaterial",
      value: (idSWFScriptVar *)&v63.lobbyUserID.lobbyType);
    idSWFScriptVar::Free(this: (idSWFScriptVar *)&v63.lobbyUserID.lobbyType);
    levelRequired = ItemUnlock->levelRequired;
    String = idLocalization::GetString(inString: "#str_online_level");
    v10 = va::va(
            this: &v65,
            fmt: "%s %d",
            a3: __SPAIR64__((unsigned int)String, levelRequired),
            a4: v9,
            a5: v8,
            a6: v36,
            a7: v39,
            a8: v42,
            a9: v45,
            a10: v48,
            a11: v51);
    v62.type = SWF_VAR_UNDEF;
    idSWFScriptVar::SetString(this: &v62, s: v10);
    idSWFScriptObject::Set(this: v2->globals, name: "unlockPopupItemLevel", value: &v62);
    idSWFScriptVar::Free(this: &v62);
    ++this->showingUnlockedItemIndex;
    if ( this->showingUnlockedItemIndex >= (int)idAnimator_Channel::InternalGetMergeBranch(this: (idDeclEntityDef *)playerMatchResults) )
      idMatchResults::ClearItemsUnlocked(this: playerMatchResults);
    v11 = v2;
  }
  idSWF::Activate(this: v11, b: true);
}


// ========================================================================
// __unwind$514826
// EA  : 0x82DCB98C
// RVA : 0x00DCB98C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514826()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4528 + 112));
}


// ========================================================================
// __unwind$514827
// EA  : 0x82DCB9B4
// RVA : 0x00DCB9B4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514827()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4528 + 160));
}


// ========================================================================
// __unwind$514828
// EA  : 0x82DCB9DC
// RVA : 0x00DCB9DC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514828()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4528 + 144));
}


// ========================================================================
// __unwind$514829
// EA  : 0x82DCBA04
// RVA : 0x00DCBA04
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514829()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4528 + 240));
}


// ========================================================================
// __unwind$514830
// EA  : 0x82DCBA2C
// RVA : 0x00DCBA2C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514830()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4528 + 96));
}


// ========================================================================
// __unwind$514831
// EA  : 0x82DCBA54
// RVA : 0x00DCBA54
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514831()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4528 + 128));
}


// ========================================================================
// __unwind$514832
// EA  : 0x82DCBA7C
// RVA : 0x00DCBA7C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514832()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4528 + 176));
}


// ========================================================================
// __unwind$514833
// EA  : 0x82DCBAA4
// RVA : 0x00DCBAA4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514833()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4528 + 80));
}


// ========================================================================
// __unwind$514834
// EA  : 0x82DCBACC
// RVA : 0x00DCBACC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514834()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4528 + 88));
}


// ========================================================================
// __unwind$514975
// EA  : 0x82DCBAF4
// RVA : 0x00DCBAF4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514975()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4528 + 304));
}


// ========================================================================
// __unwind$514835
// EA  : 0x82DCBB1C
// RVA : 0x00DCBB1C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514835()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4528 + 104));
}


// ========================================================================
// __unwind$515003
// EA  : 0x82DCBB44
// RVA : 0x00DCBB44
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_515003()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4528 + 208));
}


// ========================================================================
// __unwind$514836
// EA  : 0x82DCBB6C
// RVA : 0x00DCBB6C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514836()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4528 + 120));
}


// ========================================================================
// __unwind$515031
// EA  : 0x82DCBB94
// RVA : 0x00DCBB94
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_515031()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4528 + 272));
}


// ========================================================================
// __unwind$514837
// EA  : 0x82DCBBBC
// RVA : 0x00DCBBBC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_514837()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4528 + 136));
}


// ========================================================================
// GenerateMatchParmsFromMainMenu
// EA  : 0x82DCC870
// RVA : 0x00DCC870
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu *__fastcall GenerateMatchParmsFromMainMenu(idMainMenu *result)
{
  idMainMenu *mainMenu; // r4

  mainMenu = gameLocal->mainMenu;
  if ( mainMenu == nullptr )
    idLib::Error(fmt: "Expected main menu to exist\n");
  idMainMenu::GenerateMatchParms(this: result, result: mainMenu, useDefaults: true);
  return result;
}


// ========================================================================
// ?Call@idSWFScriptFunction_createTeamLobby@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCC8D8
// RVA : 0x00DCC8D8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_createTeamLobby *__fastcall idMainMenu::idSWFScriptFunction_createTeamLobby::Call(
        idMainMenu::idSWFScriptFunction_createTeamLobby *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu v6; // [sp+60h] [-1270h] BYREF

  GenerateMatchParmsFromMainMenu(result: &v6);
  session->CreatePartyLobby(this: session, a2: (const idMatchParameters *)&v6);
  this->__vftable = (idMainMenu::idSWFScriptFunction_createTeamLobby_vtbl *)4;
  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)&v6);
  return this;
}


// ========================================================================
// __unwind$516136
// EA  : 0x82DCC95C
// RVA : 0x00DCC95C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516136()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4816 + 96));
}


// ========================================================================
// __unwind$516137
// EA  : 0x82DCC984
// RVA : 0x00DCC984
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516137()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4816;
  if ( (*(_DWORD *)(v0 - 4816 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 4836));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_createGameLobby@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCC9D0
// RVA : 0x00DCC9D0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_createGameLobby *__fastcall idMainMenu::idSWFScriptFunction_createGameLobby::Call(
        idMainMenu::idSWFScriptFunction_createGameLobby *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu v6; // [sp+60h] [-1270h] BYREF

  GenerateMatchParmsFromMainMenu(result: &v6);
  session->CreateMatch(this: session, a2: (const idMatchParameters *)&v6);
  this->__vftable = (idMainMenu::idSWFScriptFunction_createGameLobby_vtbl *)4;
  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)&v6);
  return this;
}


// ========================================================================
// __unwind$516163
// EA  : 0x82DCCA54
// RVA : 0x00DCCA54
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516163()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4816 + 96));
}


// ========================================================================
// __unwind$516164
// EA  : 0x82DCCA7C
// RVA : 0x00DCCA7C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516164()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4816;
  if ( (*(_DWORD *)(v0 - 4816 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 4836));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_autoJoinGameLobby@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCCAC8
// RVA : 0x00DCCAC8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_autoJoinGameLobby *__fastcall idMainMenu::idSWFScriptFunction_autoJoinGameLobby::Call(
        idMainMenu::idSWFScriptFunction_autoJoinGameLobby *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu v6; // [sp+60h] [-1270h] BYREF

  GenerateMatchParmsFromMainMenu(result: &v6);
  v6.actionRepeater.event.type = (widgetEvent_t)v6.actionRepeater.widget;
  session->FindOrCreateMatch(this: session, a2: (const idMatchParameters *)&v6, a3: 0);
  this->__vftable = (idMainMenu::idSWFScriptFunction_autoJoinGameLobby_vtbl *)4;
  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)&v6);
  return this;
}


// ========================================================================
// __unwind$516190
// EA  : 0x82DCCB58
// RVA : 0x00DCCB58
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516190()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4816 + 96));
}


// ========================================================================
// __unwind$516191
// EA  : 0x82DCCB80
// RVA : 0x00DCCB80
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516191()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4816;
  if ( (*(_DWORD *)(v0 - 4816 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 4836));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_cancelMatch@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCCBC8
// RVA : 0x00DCCBC8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_cancelMatch *__fastcall idMainMenu::idSWFScriptFunction_cancelMatch::Call(
        idMainMenu::idSWFScriptFunction_cancelMatch *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *mainMenu; // r30
  idLobbyBase *v6; // r3
  idLobbyBase *v7; // r3
  idLobbyBase *v8; // r3
  idLobbyBase *v9; // r3
  idLobbyBase *v11; // r3
  idLobbyBase *v12; // r3

  mainMenu = gameLocal->mainMenu;
  if ( session->GetBackState(this: session) < 1
    || (v6 = session->GetPartyLobbyBase(this: session), v6->GetNumLobbyUsers(this: v6) <= 1)
    && (v7 = session->GetGameLobbyBase(this: session), v7->GetNumLobbyUsers(this: v7) <= 1) )
  {
    idMainMenu::GoBack(this: mainMenu);
  }
  else
  {
    if ( session->GetBackState(this: session) == PARTY_LOBBY )
    {
      v8 = session->GetPartyLobbyBase(this: session);
      if ( v8->IsHost(this: v8) != 0 )
      {
        v9 = session->GetPartyLobbyBase(this: session);
        if ( v9->GetNumLobbyUsers(this: v9) > 1 )
        {
          idMainMenu::ShowLeaveLobbyDialog(this: mainMenu, askLeaveWithTeam: true, askLeaveTeam: false);
          this->__vftable = (idMainMenu::idSWFScriptFunction_cancelMatch_vtbl *)4;
          return this;
        }
      }
    }
    v11 = session->GetPartyLobbyBase(this: session);
    if ( v11->GetNumLobbyUsers(this: v11) > 1 )
    {
      idMainMenu::ShowLeaveLobbyDialog(this: mainMenu, askLeaveWithTeam: false, askLeaveTeam: true);
      this->__vftable = (idMainMenu::idSWFScriptFunction_cancelMatch_vtbl *)4;
      return this;
    }
    v12 = session->GetGameLobbyBase(this: session);
    if ( v12->GetNumLobbyUsers(this: v12) > 1 )
    {
      idMainMenu::ShowLeaveLobbyDialog(this: mainMenu, askLeaveWithTeam: false, askLeaveTeam: false);
      this->__vftable = (idMainMenu::idSWFScriptFunction_cancelMatch_vtbl *)4;
      return this;
    }
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_cancelMatch_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setMatchMap@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCCDC0
// RVA : 0x00DCCDC0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setMatchMap *__fastcall idMainMenu::idSWFScriptFunction_setMatchMap::Call(
        idMainMenu::idSWFScriptFunction_setMatchMap *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v7; // r11
  bool v8; // zf
  int v9; // r3
  int v10; // r30
  mpMap_t *v11; // r7
  int v12; // r4
  idMainMenu *mainMenu; // r3
  int v14; // r5
  int matchTypeIndex; // r6
  idPlayerProfile *v17; // r28
  idLobbyBase *v18; // r3

  if ( parms->num < 1 )
    goto LABEL_7;
  type = parms->list->type;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v8 = type != SWF_VAR_BOOL, v7 = 0, !v8) )
    v7 = 1;
  if ( v7 == 0 )
LABEL_7:
    idLib::Warning(fmt: "Invalid parameter specified for setMatchMap");
  v9 = idSWFScriptVar::ToInteger(this: parms->list);
  v10 = v9;
  if ( v9 < 0 || v9 >= idMainMenu::pMPMaps->num )
  {
    idLib::Warning(fmt: "Map index %d is out of range [0, %d]", v9, idMainMenu::pMPMaps->num);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setMatchMap_vtbl *)4;
    return this;
  }
  else
  {
    v11 = &idMainMenu::pMPMaps->list[v9];
    v12 = v9;
    mainMenu = gameLocal->mainMenu;
    v14 = v11->type;
    matchTypeIndex = mainMenu->matchTypeIndex;
    if ( v14 == matchTypeIndex )
    {
      idMainMenu::SetMatchMapIndex(this: mainMenu, index: v12);
      idMainMenu::CopySettingsToSession(this: gameLocal->mainMenu, forceUpdateParty: true);
      v17 = common->GetProfileFromMasterLocalUser(this: common);
      if ( v17 != nullptr )
      {
        v18 = session->GetGameLobbyBase(this: session);
        if ( v18->IsHost(this: v18) != 0 && gameLocal->mainMenu->matchTypeIndex == 1 )
          v17[1].stats.staticList[365].i = v10;
      }
      this->__vftable = (idMainMenu::idSWFScriptFunction_setMatchMap_vtbl *)4;
      return this;
    }
    else
    {
      idLib::Warning(
        fmt: "Setting map index %d to map that doesn't match current game type (%d != %d)",
        v12,
        v14,
        matchTypeIndex);
      this->__vftable = (idMainMenu::idSWFScriptFunction_setMatchMap_vtbl *)4;
      return this;
    }
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_setMatchMode@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCCF60
// RVA : 0x00DCCF60
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setMatchMode *__fastcall idMainMenu::idSWFScriptFunction_setMatchMode::Call(
        idMainMenu::idSWFScriptFunction_setMatchMode *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::idSWFScriptFunction_setMatchMode *v4; // r28
  int matchMapIndex; // r30
  int v6; // r3

  v4 = this;
  if ( idMainMenu::pMPMaps != nullptr )
  {
    if ( parms->num < 1 )
    {
      idLib::Warning(fmt: "Invalid number of parameters specified for setMatchMode");
      v4->__vftable = (idMainMenu::idSWFScriptFunction_setMatchMode_vtbl *)4;
      return v4;
    }
    matchMapIndex = gameLocal->mainMenu->matchMapIndex;
    if ( matchMapIndex >= 0 && matchMapIndex < idMainMenu::pMPMaps->num )
    {
      v6 = idSWFScriptVar::ToInteger(this: parms->list);
      if ( v6 < 0 || v6 >= idMainMenu::pMPMaps->list[matchMapIndex].modes.num )
      {
        idLib::Warning(fmt: "Invalid game mode specified for setMatchMode", v6);
        v4->__vftable = (idMainMenu::idSWFScriptFunction_setMatchMode_vtbl *)4;
        return v4;
      }
      else
      {
        idMainMenu::SetMatchModeIndex(this: gameLocal->mainMenu, index: v6);
        idMainMenu::CopySettingsToSession(this: gameLocal->mainMenu, forceUpdateParty: true);
        common->GetProfileFromMasterLocalUser(this: common);
        v4->__vftable = (idMainMenu::idSWFScriptFunction_setMatchMode_vtbl *)4;
        return v4;
      }
    }
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setMatchMode_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_joinQuickMatch@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCD090
// RVA : 0x00DCD090
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_joinQuickMatch *__fastcall idMainMenu::idSWFScriptFunction_joinQuickMatch::Call(
        idMainMenu::idSWFScriptFunction_joinQuickMatch *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu v6; // [sp+60h] [-1270h] BYREF

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid number of parameters specified for joinQuickMatch", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_joinQuickMatch_vtbl *)4;
  }
  else
  {
    GenerateMatchParmsFromMainMenu(result: &v6);
    v6.actionRepeater.event.type = -1;
    session->FindOrCreateMatch(this: session, a2: (const idMatchParameters *)&v6, a3: 0);
    this->__vftable = (idMainMenu::idSWFScriptFunction_joinQuickMatch_vtbl *)4;
    idMatchParameters::~idMatchParameters(this: (idMatchParameters *)&v6);
  }
  return this;
}


// ========================================================================
// __unwind$516414
// EA  : 0x82DCD148
// RVA : 0x00DCD148
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516414()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 4816;
  if ( (*(_DWORD *)(v0 - 4816 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 4836));
  }
}


// ========================================================================
// __unwind$516417
// EA  : 0x82DCD18C
// RVA : 0x00DCD18C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516417()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 4816 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_setTimeLimit@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCD1B8
// RVA : 0x00DCD1B8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setTimeLimit *__fastcall idMainMenu::idSWFScriptFunction_setTimeLimit::Call(
        idMainMenu::idSWFScriptFunction_setTimeLimit *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *mainMenu; // r28
  int v7; // r27

  if ( parms->num == 1 )
  {
    mainMenu = gameLocal->mainMenu;
    v7 = 60 * idSWFScriptVar::ToInteger(this: parms->list);
    common->GetProfileFromMasterLocalUser(this: common);
    mainMenu->timeLimit = v7;
    idMainMenu::CopySettingsToSession(this: gameLocal->mainMenu, forceUpdateParty: true);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setTimeLimit_vtbl *)4;
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setTimeLimit");
    this->__vftable = (idMainMenu::idSWFScriptFunction_setTimeLimit_vtbl *)4;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_setScoreLimit@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCD258
// RVA : 0x00DCD258
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setScoreLimit *__fastcall idMainMenu::idSWFScriptFunction_setScoreLimit::Call(
        idMainMenu::idSWFScriptFunction_setScoreLimit *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *mainMenu; // r28
  int v7; // r27

  if ( parms->num == 1 )
  {
    mainMenu = gameLocal->mainMenu;
    v7 = idSWFScriptVar::ToInteger(this: parms->list);
    common->GetProfileFromMasterLocalUser(this: common);
    mainMenu->scoreLimit = v7;
    idMainMenu::CopySettingsToSession(this: gameLocal->mainMenu, forceUpdateParty: true);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setScoreLimit_vtbl *)4;
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setScoreLimit");
    this->__vftable = (idMainMenu::idSWFScriptFunction_setScoreLimit_vtbl *)4;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_setCoopDifficulty@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCD2F8
// RVA : 0x00DCD2F8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setCoopDifficulty *__fastcall idMainMenu::idSWFScriptFunction_setCoopDifficulty::Call(
        idMainMenu::idSWFScriptFunction_setCoopDifficulty *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *mainMenu; // r28
  int v7; // r3

  if ( parms->num == 1 )
  {
    mainMenu = gameLocal->mainMenu;
    v7 = idSWFScriptVar::ToInteger(this: parms->list);
    idMainMenu::SetCoopDifficulty(this: mainMenu, newDifficulty: v7, storeDefaults: true);
    idMainMenu::CopySettingsToSession(this: gameLocal->mainMenu, forceUpdateParty: true);
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setCoopDifficulty");
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_setCoopDifficulty_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_setCOOPPrivacy@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCD388
// RVA : 0x00DCD388
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_setCOOPPrivacy *__fastcall idMainMenu::idSWFScriptFunction_setCOOPPrivacy::Call(
        idMainMenu::idSWFScriptFunction_setCOOPPrivacy *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *mainMenu; // r30
  char v7; // r3

  if ( parms->num == 1 )
  {
    mainMenu = gameLocal->mainMenu;
    v7 = idSWFScriptVar::ToBool(this: parms->list);
    idMainMenu::SetCoopPrivacy(this: mainMenu, newPrivacy: v7, storeDefaults: true);
    if ( session->GetState(this: session) == PARTY_LOBBY || session->GetState(this: session) == GAME_LOBBY )
      idMainMenu::CopySettingsToSession(this: gameLocal->mainMenu, forceUpdateParty: true);
    this->__vftable = (idMainMenu::idSWFScriptFunction_setCOOPPrivacy_vtbl *)4;
    return this;
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for setCOOPPrivacy");
    this->__vftable = (idMainMenu::idSWFScriptFunction_setCOOPPrivacy_vtbl *)4;
    return this;
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_clearLeaderboard@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCD450
// RVA : 0x00DCD450
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_clearLeaderboard *__fastcall idMainMenu::idSWFScriptFunction_clearLeaderboard::Call(
        idMainMenu::idSWFScriptFunction_clearLeaderboard *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  if ( parms->num != 0 )
    idLib::Warning(fmt: "Invalid parameters specified for clearLeaderboard", result, thisObject);
  else
    idMainMenu::ClearLeaderboard(this: gameLocal->mainMenu);
  this->__vftable = (idMainMenu::idSWFScriptFunction_clearLeaderboard_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_refreshLeaderboard@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCD4C0
// RVA : 0x00DCD4C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_refreshLeaderboard *__fastcall idMainMenu::idSWFScriptFunction_refreshLeaderboard::Call(
        idMainMenu::idSWFScriptFunction_refreshLeaderboard *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v6; // r3

  if ( parms->num >= 1 )
  {
    v6 = idSWFScriptVar::ToBool(this: parms->list);
    *(_BYTE *)(result->value.i + 904) = v6;
    idMainMenu::SetLeaderboardIndex(this: (idMainMenu *)result->value.i, isVDM: v6);
    *(_BYTE *)(result->value.i + 916) = 1;
  }
  else
  {
    idLib::Warning(fmt: "no parms - Leaderboards need to know whether its for VDM or COOP", result, thisObject);
  }
  this->__vftable = (idMainMenu::idSWFScriptFunction_refreshLeaderboard_vtbl *)4;
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_nextLeaderboard@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCD550
// RVA : 0x00DCD550
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_nextLeaderboard *__fastcall idMainMenu::idSWFScriptFunction_nextLeaderboard::Call(
        idMainMenu::idSWFScriptFunction_nextLeaderboard *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v6; // r3
  idSWFScriptVar::swfScriptVarValue_t v7; // r11

  if ( parms->num == 1 )
  {
    v6 = idSWFScriptVar::ToBool(this: parms->list);
    LODWORD(v7.f) = result->value;
    if ( v6 != 0 )
      ++*(_DWORD *)(v7.i + 912);
    else
      ++*(_DWORD *)(v7.i + 908);
    idMainMenu::SetLeaderboardIndex(this: (idMainMenu *)result->value.i, isVDM: v6);
    this->__vftable = (idMainMenu::idSWFScriptFunction_nextLeaderboard_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "specify weather you want to increment coop or road rally leaderboard", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_nextLeaderboard_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_prevLeaderboard@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCD5F8
// RVA : 0x00DCD5F8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_prevLeaderboard *__fastcall idMainMenu::idSWFScriptFunction_prevLeaderboard::Call(
        idMainMenu::idSWFScriptFunction_prevLeaderboard *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  char v6; // r3
  idSWFScriptVar::swfScriptVarValue_t v7; // r11

  if ( parms->num == 1 )
  {
    v6 = idSWFScriptVar::ToBool(this: parms->list);
    LODWORD(v7.f) = result->value;
    if ( v6 != 0 )
      --*(_DWORD *)(v7.i + 912);
    else
      --*(_DWORD *)(v7.i + 908);
    idMainMenu::SetLeaderboardIndex(this: (idMainMenu *)result->value.i, isVDM: v6);
    this->__vftable = (idMainMenu::idSWFScriptFunction_prevLeaderboard_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "specify weather you want to increment coop or road rally leaderboard", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_prevLeaderboard_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?Call@idSWFScriptFunction_toggleCoopNightmareLeaderboard@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCD6A0
// RVA : 0x00DCD6A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_toggleCoopNightmareLeaderboard *__fastcall idMainMenu::idSWFScriptFunction_toggleCoopNightmareLeaderboard::Call(
        idMainMenu::idSWFScriptFunction_toggleCoopNightmareLeaderboard *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  *(_BYTE *)(result->value.i + 3128) = (_cntlzw(*(unsigned __int8 *)(result->value.i + 3128)) & 0x20) != 0;
  idMainMenu::SetLeaderboardIndex(this: (idMainMenu *)result->value.i, isVDM: false);
  this->__vftable = (idMainMenu::idSWFScriptFunction_toggleCoopNightmareLeaderboard_vtbl *)4;
  return this;
}


// ========================================================================
// ?SetRandomMatchMap@idMainMenu@@QAAXXZ
// EA  : 0x82DCD708
// RVA : 0x00DCD708
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetRandomMatchMap(idMainMenu *this)
{
  int v1; // r27
  int matchMapIndex; // r11
  mpMap_t *list; // r10
  mpMapMode_t *v5; // r25
  int matchModeIndex; // r24
  float *v7; // r29
  idList<mpMap_t,57> *v8; // r7
  int v9; // r28
  int v10; // r10
  mpMap_t *v11; // r11
  float v12; // r9
  mpMapMode_t *v13; // r8
  int v14; // r11
  int index; // r6
  int v16; // r5
  __int64 v17; // r6
  int v18; // r4
  int num; // r29
  idSkinMapping *v20; // r21
  idSkinMapping *v21; // r26
  const idStr *v22; // r3
  int *v23; // r29
  int v24; // r25
  idLobbyBase *v25; // r3
  idLobbyBase *v26; // r3
  __int64 v27; // r6
  int v28; // r4
  float *v29; // r26
  const idStr *v30; // r3
  const idStr *v31; // r26
  const idStr *v32; // r3
  const idStr *v33; // r3
  const idStr *v34; // r3
  const idStr *v35; // r26
  const idStr *v36; // r3
  const idStr *v37; // r3
  const idStr *v38; // r3
  float v39[4]; // [sp+50h] [-270h] BYREF
  idList<float,5> v40; // [sp+60h] [-260h] BYREF
  idList<idSkinMapping,46> v41; // [sp+70h] [-250h] BYREF
  idList<float,5> v42; // [sp+80h] [-240h] BYREF
  idStr v43; // [sp+90h] [-230h] BYREF
  idStr v44; // [sp+B0h] [-210h] BYREF
  idStr v45; // [sp+D0h] [-1F0h] BYREF
  idStr v46; // [sp+F0h] [-1D0h] BYREF
  idStr v47; // [sp+110h] [-1B0h] BYREF
  idStr v48; // [sp+130h] [-190h] BYREF
  idStr v49; // [sp+150h] [-170h] BYREF
  idStr v50; // [sp+170h] [-150h] BYREF
  idStr v51; // [sp+190h] [-130h] BYREF
  idStr v52; // [sp+1B0h] [-110h] BYREF
  idStr v53; // [sp+1D0h] [-F0h] BYREF
  idStr v54; // [sp+1F0h] [-D0h] BYREF
  idStr v55; // [sp+210h] [-B0h] BYREF
  idStr v56; // [sp+230h] [-90h] BYREF

  v1 = 0;
  matchMapIndex = this->matchMapIndex;
  list = this->mpMaps.list;
  memset(&v41, 0, 14);
  *(_WORD *)&v41.memTag = 1280;
  v5 = list[matchMapIndex].modes.list;
  matchModeIndex = this->matchModeIndex;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v41);
  v7 = nullptr;
  v8 = idMainMenu::pMPMaps;
  if ( idMainMenu::pMPMaps->num > 0 )
  {
    v9 = 0;
    do
    {
      v10 = 0;
      v11 = &v8->list[v9];
      v39[0] = *(float *)&v11->modes.num;
      v12 = v39[0];
      if ( SLODWORD(v39[0]) > 0 )
      {
        v13 = v11->modes.list;
        v14 = 0;
        index = v5[matchModeIndex].name.index;
        while ( 1 )
        {
          v16 = v13[v14].name.index;
          LODWORD(v39[0]) = &v13[v14];
          if ( v16 == index )
            break;
          ++v10;
          ++v14;
          if ( v10 >= SLODWORD(v12) )
            goto _M517094;
        }
        v40.list = v7;
        v40.num = v10;
        idList<cachedPageFile_t,5>::Append(this: &v41, obj: (const idSkinMapping *)&v40);
        v8 = idMainMenu::pMPMaps;
      }
_M517094:
      v7 = (float *)((char *)v7 + 1);
      ++v9;
    }
    while ( (int)v7 < v8->num );
  }
  memset(&v40, 0, 14);
  *(_WORD *)&v40.memTag = 1280;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v40);
  v20 = v41.list;
  num = v41.num;
  if ( v41.num > 0 )
  {
    v21 = v41.list - 1;
    do
    {
      v22 = idStr::idStr(this: &v47, text: "_weighting");
      ++v21;
      operator+(result: &v45, a: &this->mpMaps.list[(int)v21->from].titleStorageMapName, b: v22);
      idStr::FreeData(this: &v47);
      v39[0] = session->GetTitleStorageFloat_2(this: session, a2: v45.data, a3: 1.0);
      idList<float,13>::Append(this: (idList<float,13> *)&v40, obj: v39);
      idStr::FreeData(this: &v45);
      --num;
    }
    while ( num != 0 );
  }
  v23 = (int *)&v20[PickRandomIndexUsingWeighted(weightings: &v40, a2: v18, a3: v17)];
  idMainMenu::SetMatchMapIndex(this, index: *v23);
  v24 = v23[1];
  v25 = session->GetGameLobbyBase(this: session);
  if ( v25->IsHost(this: v25) != 0 )
  {
    v26 = session->GetGameLobbyBase(this: session);
    if ( v26->GetMatchParms(this: v26)->searchMode == -1 )
    {
      v29 = nullptr;
      *(_WORD *)&v42.memTag = 1280;
      memset(&v42, 0, 14);
      if ( this->mpMaps.list[*v23].modes.num > 0 )
      {
        do
        {
          v30 = idStr::idStr(this: &v49, text: "_weighting");
          operator+(
            result: &v43,
            a: (const idStr *)((char *)&this->mpMaps.list[*v23].modes.list->titleStorageModeName + (unsigned int)v29),
            b: v30);
          idStr::FreeData(this: &v49);
          v39[0] = session->GetTitleStorageFloat_2(this: session, a2: v43.data, a3: 1.0);
          idList<float,13>::Append(this: (idList<float,13> *)&v42, obj: v39);
          idStr::FreeData(this: &v43);
          ++v1;
          LODWORD(v27) = &this->mpMaps.list[*v23];
          v29 += 40;
          HIDWORD(v27) = *(_DWORD *)(v27 + 136);
        }
        while ( v1 < SHIDWORD(v27) );
        v29 = v42.list;
      }
      v24 = PickRandomIndexUsingWeighted(weightings: &v42, a2: v28, a3: v27);
      if ( (v42.listStatic == 0 || v42.listStatic == 2) && v29 != nullptr )
        idMem::Free(this: &mem, ptr: v29, align: ALIGN_16);
    }
  }
  idMainMenu::SetMatchModeIndex(this, index: v24);
  v31 = idStr::idStr(this: &v48, text: "_Random_Score");
  v32 = idStr::idStr(this: &v55, text: "_");
  v33 = operator+(result: &v51, a: &this->mpMaps.list[*v23].titleStorageMapName, b: v32);
  v34 = operator+(result: &v53, a: v33, b: &this->mpMaps.list[*v23].modes.list[v24].titleStorageModeName);
  operator+(result: &v46, a: v34, b: v31);
  idStr::FreeData(this: &v53);
  idStr::FreeData(this: &v51);
  idStr::FreeData(this: &v55);
  idStr::FreeData(this: &v48);
  v35 = idStr::idStr(this: &v56, text: "_Random_Time");
  v36 = idStr::idStr(this: &v54, text: "_");
  v37 = operator+(result: &v52, a: &this->mpMaps.list[*v23].titleStorageMapName, b: v36);
  v38 = operator+(result: &v50, a: v37, b: &this->mpMaps.list[*v23].modes.list[v24].titleStorageModeName);
  operator+(result: &v44, a: v38, b: v35);
  idStr::FreeData(this: &v50);
  idStr::FreeData(this: &v52);
  idStr::FreeData(this: &v54);
  idStr::FreeData(this: &v56);
  this->scoreLimit = session->GetTitleStorageInt_2(this: session, a2: v46.data, a3: 200);
  this->timeLimit = session->GetTitleStorageInt_2(this: session, a2: v44.data, a3: 420);
  idMainMenu::CopySettingsToSession(this, forceUpdateParty: true);
  idStr::FreeData(this: &v44);
  idStr::FreeData(this: &v46);
  if ( (v40.listStatic == 0 || v40.listStatic == 2) && v40.list != nullptr )
    idMem::Free(this: &mem, ptr: v40.list, align: ALIGN_16);
  if ( (v41.listStatic == 0 || v41.listStatic == 2) && v20 != nullptr )
    idMem::Free(this: &mem, ptr: v20, align: ALIGN_16);
}


// ========================================================================
// __unwind$516711
// EA  : 0x82DCDC60
// RVA : 0x00DCDC60
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516711()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 704 + 112));
}


// ========================================================================
// __unwind$516712
// EA  : 0x82DCDC88
// RVA : 0x00DCDC88
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516712()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 704 + 96));
}


// ========================================================================
// __unwind$516713
// EA  : 0x82DCDCB0
// RVA : 0x00DCDCB0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516713()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 272));
}


// ========================================================================
// __unwind$516714
// EA  : 0x82DCDCD8
// RVA : 0x00DCDCD8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516714()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 208));
}


// ========================================================================
// __unwind$516715
// EA  : 0x82DCDD00
// RVA : 0x00DCDD00
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516715()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 704 + 128));
}


// ========================================================================
// __unwind$516716
// EA  : 0x82DCDD28
// RVA : 0x00DCDD28
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516716()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 336));
}


// ========================================================================
// __unwind$516717
// EA  : 0x82DCDD50
// RVA : 0x00DCDD50
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516717()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 144));
}


// ========================================================================
// __unwind$516718
// EA  : 0x82DCDD78
// RVA : 0x00DCDD78
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516718()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 304));
}


// ========================================================================
// __unwind$516719
// EA  : 0x82DCDDA0
// RVA : 0x00DCDDA0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516719()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 528));
}


// ========================================================================
// __unwind$516720
// EA  : 0x82DCDDC8
// RVA : 0x00DCDDC8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516720()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 400));
}


// ========================================================================
// __unwind$516721
// EA  : 0x82DCDDF0
// RVA : 0x00DCDDF0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516721()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 464));
}


// ========================================================================
// __unwind$516722
// EA  : 0x82DCDE18
// RVA : 0x00DCDE18
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516722()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 240));
}


// ========================================================================
// __unwind$516723
// EA  : 0x82DCDE40
// RVA : 0x00DCDE40
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516723()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 560));
}


// ========================================================================
// __unwind$516724
// EA  : 0x82DCDE68
// RVA : 0x00DCDE68
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516724()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 496));
}


// ========================================================================
// __unwind$516725
// EA  : 0x82DCDE90
// RVA : 0x00DCDE90
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516725()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 432));
}


// ========================================================================
// __unwind$516726
// EA  : 0x82DCDEB8
// RVA : 0x00DCDEB8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516726()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 368));
}


// ========================================================================
// __unwind$516727
// EA  : 0x82DCDEE0
// RVA : 0x00DCDEE0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_516727()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 704 + 176));
}


// ========================================================================
// ?UpdateMatchResults@idMainMenu@@QAAXHUlobbyUserID_t@@@Z
// EA  : 0x82DCDF10
// RVA : 0x00DCDF10
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMatchResults(
        idMainMenu *this,
        localUserHandle_t *playerId,
        lobbyUserID_t *lobbyUserID)
{
  lobbyUserID_t v3; // r26
  idLocalUser *LocalUserByHandle; // r3
  idLocalUser *v6; // r29
  idLocalUser *v7; // r3
  idRageMetrics *rageMetrics; // r27
  idMatchResults *v9; // r30
  int v10; // r23
  idDeclOnlineLevel *v11; // r3
  __int64 v12; // r10
  int v13; // r8
  int v14; // r7
  int v15; // r6
  int v16; // r5
  int XpRequiredForLevel; // r3
  int v18; // r26
  int v19; // r3
  idList<int,5> *p_itemsUnlocked; // r29
  int i; // r25
  breakableIsland_t *v22; // r3
  int v23; // r25
  int v24; // r21
  int j; // r20
  idResource *v26; // r3
  int v27; // r11
  idResource *v28; // r26
  idResource *nextOnHashChain; // r26
  int num; // r11
  int size; // r10
  int *list; // r10
  int *v33; // r11
  idSession *v34; // r3
  int v35; // r3
  double SessionStatFloat; // fp1
  idClientGame *v37; // r3
  idGameTimeManager v38; // [sp+50h] [-90h] BYREF

  *(_DWORD *)&v3.lobbyType = lobbyUserID;
  v38.framenum = (int)playerId;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  LocalUserByHandle = idSignInManagerBase::GetLocalUserByHandle(this: session->signInManager, handle: playerId);
  v6 = LocalUserByHandle;
  if ( LocalUserByHandle != nullptr )
  {
    if ( LocalUserByHandle->GetProfile(this: LocalUserByHandle) != nullptr )
    {
      v7 = common->GetMasterLocalUser(this: common);
      rageMetrics = clientGame->rageMetrics;
      v9 = &playerMatchResults[v7 != v6];
      v10 = v6->GetStatInt(this: v6, a2: 32);
      v11 = (idDeclOnlineLevel *)idResourceList::Index(this: &idDeclOnlineLevel::resourceList, index: 0);
      XpRequiredForLevel = idDeclOnlineLevel::GetXpRequiredForLevel(
                             this: v11,
                             level: v10 + 1,
                             a3: v16,
                             a4: v15,
                             a5: v14,
                             a6: v13,
                             a7: v12);
      v9->lobbyUserID = v3;
      v9->playerId = (int)playerId;
      v18 = XpRequiredForLevel;
      v9->xpGained = idRageMetrics::GetSessionStat(this: rageMetrics, (int)playerId, stat: RAGE_STAT_MP_XP);
      v19 = v6->GetStatInt(this: v6, a2: 23);
      v9->totalXp = v19;
      v9->xpToNextLevel = v18 - v19;
      v9->levelsGained = idRageMetrics::GetSessionStat(this: rageMetrics, (int)playerId, stat: RAGE_STAT_MP_LEVEL);
      v9->cashGained = idRageMetrics::GetSessionStat(this: rageMetrics, (int)playerId, stat: RAGE_STAT_CASH_MP);
      v9->score = idRageMetrics::GetSessionStat(this: rageMetrics, (int)playerId, stat: RAGE_STAT_SCORE_VDM);
      idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v9->accoladesEarned);
      p_itemsUnlocked = &v9->itemsUnlocked;
      idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v9->itemsUnlocked);
      idMem::PopHeap(this: &mem);
      for ( i = 0; i < idAccolades::Num(); ++i )
      {
        idAccolades::GetSession(result: (idAccolade *)&v38, (int)playerId, index: i);
        if ( idAccolade::Count(this: &v38) != 0 )
        {
          idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
          *(_QWORD *)&v38.hz[1] = __PAIR64__(i, idAccolade::Count(this: &v38));
          v22 = idList<breakableIsland_t,59>::Alloc(this: (idList<breakableIsland_t,59> *)&v9->accoladesEarned);
          *v22 = *(breakableIsland_t *)&v38.hz[1];
          idMem::PopHeap(this: &mem);
        }
      }
      v23 = 0;
      v24 = v10 - v9->levelsGained;
      for ( j = idDeclVehicleUnlock::resourceList.num; v23 < j; ++v23 )
      {
        v26 = idResourceList::Index(this: &idDeclVehicleUnlock::resourceList, index: v23);
        v27 = *((_DWORD *)&v26[1] + 8);
        v28 = v26;
        if ( v27 > v24 && v27 <= v10 )
        {
          idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
          nextOnHashChain = v28[3].nextOnHashChain;
          idList<idMD6Node *,5>::PreAllocateWithGranularity(
            this: (idList<idMD6Filter *,5> *)&v9->itemsUnlocked,
            newSize: v9->itemsUnlocked.num + 1);
          num = v9->itemsUnlocked.num;
          size = v9->itemsUnlocked.size;
          if ( num >= size )
          {
            v33 = &p_itemsUnlocked->list[size - 1];
          }
          else
          {
            list = p_itemsUnlocked->list;
            v9->itemsUnlocked.num = num + 1;
            v33 = &list[num];
          }
          *v33 = (int)nextOnHashChain;
          idMem::PopHeap(this: &mem);
        }
      }
      if ( idRageMetrics::GetSessionStat(this: rageMetrics, (int)playerId, stat: RAGE_STAT_WINS) != 0 )
        v9->matchTime = idRageMetrics::GetSessionStat(this: rageMetrics, (int)playerId, stat: RAGE_STAT_TIME_PLAYED);
      else
        v9->matchTime = 0x7FFFFFFF;
      v34 = session;
      v9->shouldShowMatchResults = true;
      v35 = (int)v34->GetGameLobbyBase(this: v34);
      if ( *(_DWORD *)((*(int (__fastcall **)(int))(*(_DWORD *)v35 + 128))(a1: v35) + 12) == 2 )
      {
        v9->challengeMode = idClientGame::GetChallengeMode(this: clientGame);
        v9->statValues[0] = idRageMetrics::GetSessionStat(
                              this: rageMetrics,
                              (int)playerId,
                              stat: RAGE_STAT_VEHICLE_KILLS);
        v9->statValues[1] = idRageMetrics::GetSessionStat(
                              this: rageMetrics,
                              (int)playerId,
                              stat: RAGE_STAT_VEHICLE_DEATHS);
        v9->statValues[2] = idRageMetrics::GetSessionStat(
                              this: rageMetrics,
                              (int)playerId,
                              stat: RAGE_STAT_VDM_SPECIAL_KILLS);
        v9->statValues[3] = idRageMetrics::GetSessionStat(
                              this: rageMetrics,
                              (int)playerId,
                              stat: RAGE_STAT_LONGEST_LIFE);
        SessionStatFloat = idRageMetrics::GetSessionStatFloat(
                             this: rageMetrics,
                             (int)playerId,
                             stat: RAGE_STAT_VEHICLE_ODOMETER_ON_GROUND);
        v37 = clientGame;
        v9->miles = (float)SessionStatFloat * (float)0.000015782829;
        if ( idClientGame::GetChallengeMode(this: v37) == CHALLENGE_MODE_DM )
        {
          v9->statValues[4] = idRageMetrics::GetSessionStat(
                                this: rageMetrics,
                                (int)playerId,
                                stat: RAGE_STAT_LONGEST_KILLSTREAK);
          v9->statValues[5] = idRageMetrics::GetSessionStat(
                                this: rageMetrics,
                                (int)playerId,
                                stat: RAGE_STAT_VEHICLE_POWERUPS);
          v9->statValues[6] = idRageMetrics::GetSessionStat(
                                this: rageMetrics,
                                (int)playerId,
                                stat: RAGE_STAT_REVENGE_KILLS);
        }
        if ( v9->levelsGained <= 0 )
          v9->screenMode = 2;
        else
          v9->screenMode = 1;
      }
      else
      {
        v9->shouldShowMatchResults = false;
      }
    }
    else
    {
      idLib::Warning(fmt: "[%s] No profile for master user", "idMainMenu::UpdateMatchResults");
    }
  }
  else
  {
    idLib::Warning(fmt: "[%s] No master user", "idMainMenu::UpdateMatchResults");
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$517204
// EA  : 0x82DCE38C
// RVA : 0x00DCE38C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_517204()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 224 + 96));
}


// ========================================================================
// ?SetSwfLangameList@idMainMenu@@QAAXXZ
// EA  : 0x82DCE4F8
// RVA : 0x00DCE4F8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetSwfLangameList(idMainMenu *this)
{
  idSWFScriptObject *v2; // r20
  idPair<serverInfo_t,int> *list; // r19
  int size; // r17
  signed int num; // r28
  int v6; // r30
  const serverInfo_t *v7; // r3
  const serverInfo_t *v8; // r28
  idPair<serverInfo_t,int> *v9; // r27
  int v10; // r23
  const serverInfo_t *p_first; // r29
  idSort_Quick<idPair<serverInfo_t,int>,idSort_PlayerGamesList>_vtbl *v12; // r3
  idSWFScriptObject *v13; // r30
  idSWFScriptVar::swfScriptVarValue_t v14; // r14
  idStr *p_name; // r29
  int i; // r30
  idSort_Quick<idPair<serverInfo_t,int>,idSort_PlayerGamesList> v19[2]; // [sp+50h] [-D0h] BYREF
  idSWFScriptVar v20; // [sp+58h] [-C8h] BYREF
  idSWFScriptVar v21; // [sp+60h] [-C0h] BYREF
  idSWFScriptVar v22; // [sp+68h] [-B8h] BYREF
  idList<idPair<serverInfo_t,int>,5> v23; // [sp+70h] [-B0h] BYREF

  v2 = idSWFScriptObject::Alloc();
  idSWFScriptObject::MakeArray(this: v2);
  *(_WORD *)&v23.memTag = 1280;
  list = nullptr;
  size = 0;
  num = 0;
  memset(&v23, 0, 14);
  v6 = 0;
  if ( session->NumServers(this: session) > 0 )
  {
    do
    {
      v7 = session->ServerInfo(this: session, a2: v6);
      v8 = v7;
      if ( v7 != nullptr && v7->joinable )
      {
        v9 = idList<idPair<serverInfo_t,int>,5>::Alloc(this: &v23);
        serverInfo_t::operator=(this: &v9->first, __that: v8);
        v9->second = v6;
      }
      ++v6;
    }
    while ( v6 < session->NumServers(this: session) );
    size = v23.size;
    num = v23.num;
    list = v23.list;
  }
  v19[0].__vftable = (idSort_Quick<idPair<serverInfo_t,int>,idSort_PlayerGamesList>_vtbl *)&idSort_PlayerGamesList::`vftable';
  if ( list != nullptr )
    idSort_Quick<idPair<serverInfo_t,int>,idSort_PlayerGamesList>::Sort(this: v19, base: list, num);
  v19[0].__vftable = (idSort_Quick<idPair<serverInfo_t,int>,idSort_PlayerGamesList>_vtbl *)&idSort<idPair<serverInfo_t,int>>::`vftable';
  v10 = 0;
  if ( num > 0 )
  {
    p_first = &list->first;
    do
    {
      v12 = (idSort_Quick<idPair<serverInfo_t,int>,idSort_PlayerGamesList>_vtbl *)idMem::AllocWithLocation(
                                                                                    this: &mem,
                                                                                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                                                                    size: 0x60u,
                                                                                    tag: TAG_SWF,
                                                                                    zeroBuffer: false,
                                                                                    align: ALIGN_16,
                                                                                    heap: HEAP_DEFAULTHEAP);
      v19[1].__vftable = v12;
      if ( v12 != nullptr )
        v13 = idSWFScriptObject::idSWFScriptObject(this: (idSWFScriptObject *)v12);
      else
        v13 = nullptr;
      SLODWORD(v14.f) = p_first[1].name.len;
      v22.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v22);
      v22.value = v14;
      v22.type = SWF_VAR_INTEGER;
      idSWFScriptObject::Set(this: v13, name: "serverIndex", value: &v22);
      idSWFScriptVar::Free(this: &v22);
      if ( (unsigned __int8)DescribeServer(server: p_first, obj: v13) != 0 )
      {
        v20.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v20);
        if ( v13 != nullptr )
        {
          v20.value.i = (int)v13;
          v20.type = SWF_VAR_OBJECT;
          ++v13->refCount;
        }
        else
        {
          v20.type = SWF_VAR_NULL;
        }
        idSWFScriptObject::Set(this: v2, index: v10++, value: &v20);
        idSWFScriptVar::Free(this: &v20);
      }
      if ( v13->refCount-- == 1 )
      {
        idSWFScriptObject::~idSWFScriptObject(this: v13);
        idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
      }
      --num;
      p_first = (const serverInfo_t *)((char *)p_first + 60);
    }
    while ( num != 0 );
  }
  v21.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v21);
  if ( v2 != nullptr )
  {
    v21.value.i = (int)v2;
    v21.type = SWF_VAR_OBJECT;
    ++v2->refCount;
  }
  else
  {
    v21.type = SWF_VAR_NULL;
  }
  idSWFScriptObject::Set(this: this->mainMenu->globals, name: "lanGames", value: &v21);
  idSWFScriptVar::Free(this: &v21);
  if ( v2->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: v2);
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
  }
  if ( (v23.listStatic == 0 || v23.listStatic == 2) && list != nullptr )
  {
    if ( size > 0 )
    {
      p_name = &list->first.name;
      for ( i = size; i != 0; --i )
      {
        idStr::FreeData(this: p_name);
        p_name = (idStr *)((char *)p_name + 60);
      }
    }
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$517356
// EA  : 0x82DCE820
// RVA : 0x00DCE820
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_517356()
{
  int v0; // r12

  idList<idActionNode::anim_t,5>::~idList<idActionNode::anim_t,5>(this: (idList<idActionNode::anim_t,5> *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$517357
// EA  : 0x82DCE848
// RVA : 0x00DCE848
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_517357()
{
  int v0; // r12

  idSort_PlayerGamesList::~idSort_PlayerGamesList(this: (idSort_PlayerGamesList *)(v0 - 288 + 80));
}


// ========================================================================
// __unwind$517433
// EA  : 0x82DCE870
// RVA : 0x00DCE870
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_517433()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 288 + 84), tag: TAG_SWF);
}


// ========================================================================
// __unwind$517358
// EA  : 0x82DCE89C
// RVA : 0x00DCE89C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_517358()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 104));
}


// ========================================================================
// __unwind$517359
// EA  : 0x82DCE8C4
// RVA : 0x00DCE8C4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_517359()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 88));
}


// ========================================================================
// __unwind$517360
// EA  : 0x82DCE8EC
// RVA : 0x00DCE8EC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_517360()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 288 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_updateMapSelection@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCEC38
// RVA : 0x00DCEC38
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_updateMapSelection *__fastcall idMainMenu::idSWFScriptFunction_updateMapSelection::Call(
        idMainMenu::idSWFScriptFunction_updateMapSelection *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11
  idSWFScriptVar *list; // r3
  idSWFScriptVar::swfScriptVarType type; // r11
  char v8; // r11
  bool v9; // zf
  int v10; // r3
  idSWFScriptVar v12[2]; // [sp+50h] [-AE0h] BYREF
  idStr v13; // [sp+60h] [-AD0h] BYREF
  mpMap_t v14; // [sp+80h] [-AB0h] BYREF

  num = parms->num;
  v12[0].type = SWF_VAR_STRINGID;
  if ( num < 1 )
    goto LABEL_12;
  list = parms->list;
  type = parms->list->type;
  v12[0].type = (idSWFScriptVar::swfScriptVarType)parms->list;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v9 = type != SWF_VAR_BOOL, v8 = 0, !v9) )
    v8 = 1;
  if ( v8 != 0 )
  {
    v12[0].type = (idSWFScriptVar::swfScriptVarType)list;
    v10 = idSWFScriptVar::ToInteger(this: list);
    if ( v10 < idMainMenu::pMPMaps->num )
    {
      mpMap_t::mpMap_t(this: &v14, __that: &idMainMenu::pMPMaps->list[v10]);
      if ( v14.map.len != 0 )
      {
        idSWFScriptVar::idSWFScriptVar(this: v12, s: &v14.material);
        idStr::idStr(this: &v13, text: GLOBAL_MPMAPFILENAME);
        idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v13, value: v12);
        idStr::FreeData(this: &v13);
        idSWFScriptVar::Free(this: v12);
      }
      mpMap_t::~mpMap_t(this: &v14);
    }
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateMapSelection_vtbl *)4;
  }
  else
  {
LABEL_12:
    idLib::Warning(fmt: "Invalid number of parameters specified for updateMapSelection", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateMapSelection_vtbl *)4;
  }
  return this;
}


// ========================================================================
// __unwind$518148
// EA  : 0x82DCED6C
// RVA : 0x00DCED6C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518148()
{
  int v0; // r12

  mpMap_t::~mpMap_t(this: (mpMap_t *)(v0 - 2864 + 128));
}


// ========================================================================
// __unwind$518149
// EA  : 0x82DCED94
// RVA : 0x00DCED94
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518149()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2864 + 80));
}


// ========================================================================
// __unwind$518150
// EA  : 0x82DCEDBC
// RVA : 0x00DCEDBC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518150()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2864 + 96));
}


// ========================================================================
// ?Call@idSWFScriptFunction_updateModeSelection@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCEDF0
// RVA : 0x00DCEDF0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_updateModeSelection *__fastcall idMainMenu::idSWFScriptFunction_updateModeSelection::Call(
        idMainMenu::idSWFScriptFunction_updateModeSelection *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar *list; // r3
  idSWFScriptVar::swfScriptVarType type; // r11
  char v8; // r11
  bool v9; // zf
  int v10; // r29
  int v11; // r30
  idStrId v13; // [sp+50h] [-B40h] BYREF
  int v14; // [sp+54h] [-B3Ch]
  idSWFScriptVar v15; // [sp+58h] [-B38h] BYREF
  idSWFScriptVar v16[2]; // [sp+60h] [-B30h] BYREF
  idStr v17; // [sp+70h] [-B20h] BYREF
  idStr v18; // [sp+90h] [-B00h] BYREF
  mpMap_t v19; // [sp+B0h] [-AE0h] BYREF

  v14 = 0;
  if ( parms->num < 1 )
    goto LABEL_14;
  list = parms->list;
  type = parms->list->type;
  v13.index = (int)parms->list;
  if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v9 = type != SWF_VAR_BOOL, v8 = 0, !v9) )
    v8 = 1;
  if ( v8 != 0 )
  {
    v13.index = (int)list;
    v10 = idSWFScriptVar::ToInteger(this: list);
    v11 = *(_DWORD *)(result->value.i + 844);
    mpMap_t::mpMap_t(this: &v19, __that: &idMainMenu::pMPMaps->list[v11]);
    if ( v11 < 0 || v11 > idMainMenu::pMPMaps->num )
    {
      idLib::Warning(fmt: "Invalid current map selected in updateModeSelection");
      v14 = 1;
      this->__vftable = (idMainMenu::idSWFScriptFunction_updateModeSelection_vtbl *)4;
      mpMap_t::~mpMap_t(this: &v19);
      return this;
    }
    else if ( v10 < 0 || v10 > v19.modes.num )
    {
      idLib::Warning(fmt: "Invalid mode index specified in updateModeSelection");
      v14 = 1;
      this->__vftable = (idMainMenu::idSWFScriptFunction_updateModeSelection_vtbl *)4;
      mpMap_t::~mpMap_t(this: &v19);
      return this;
    }
    else
    {
      v13.index = (int)&v19.modes.list[v10];
      v13.index = *(_DWORD *)v13.index;
      idSWFScriptVar::idSWFScriptVar(this: v16, s: &v13);
      idStr::idStr(this: &v17, text: "selectedModeName");
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v17, value: v16);
      idStr::FreeData(this: &v17);
      idSWFScriptVar::Free(this: v16);
      v13.index = v19.modes.list[v10].description.index;
      idSWFScriptVar::idSWFScriptVar(this: &v15, s: &v13);
      idStr::idStr(this: &v18, text: "selectedModeDescription");
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)result->value.i, name: &v18, value: &v15);
      idStr::FreeData(this: &v18);
      idSWFScriptVar::Free(this: &v15);
      v14 = 1;
      this->__vftable = (idMainMenu::idSWFScriptFunction_updateModeSelection_vtbl *)4;
      mpMap_t::~mpMap_t(this: &v19);
      return this;
    }
  }
  else
  {
LABEL_14:
    idLib::Warning(fmt: "Invalid parameters specified for updateModeSelection");
    this->__vftable = (idMainMenu::idSWFScriptFunction_updateModeSelection_vtbl *)4;
    return this;
  }
}


// ========================================================================
// __unwind$518244
// EA  : 0x82DCEFEC
// RVA : 0x00DCEFEC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518244()
{
  int v0; // r12

  mpMap_t::~mpMap_t(this: (mpMap_t *)(v0 - 2960 + 176));
}


// ========================================================================
// __unwind$518245
// EA  : 0x82DCF014
// RVA : 0x00DCF014
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518245()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2960 + 96));
}


// ========================================================================
// __unwind$518246
// EA  : 0x82DCF03C
// RVA : 0x00DCF03C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518246()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2960 + 112));
}


// ========================================================================
// __unwind$518247
// EA  : 0x82DCF064
// RVA : 0x00DCF064
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518247()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2960 + 88));
}


// ========================================================================
// __unwind$518248
// EA  : 0x82DCF08C
// RVA : 0x00DCF08C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518248()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2960 + 144));
}


// ========================================================================
// __unwind$518241
// EA  : 0x82DCF0B4
// RVA : 0x00DCF0B4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518241()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 2960;
  if ( (*(_DWORD *)(v0 - 2960 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 2980));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_getModeList@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCF100
// RVA : 0x00DCF100
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getModeList *__fastcall idMainMenu::idSWFScriptFunction_getModeList::Call(
        idMainMenu::idSWFScriptFunction_getModeList *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int v4; // r24
  idMainMenu::idSWFScriptFunction_getModeList *v5; // r23
  idMainMenu *mainMenu; // r11
  int matchMapIndex; // r4
  int matchTypeIndex; // r8
  mpMap_t *v9; // r10
  int type; // r5
  idSWFScriptObject *v11; // r28
  int v12; // r29
  int i; // r30
  idSWFScriptObject *v14; // r20
  idStrId v16; // [sp+50h] [-B50h] BYREF
  int v17; // [sp+54h] [-B4Ch]
  idSWFScriptVar v18; // [sp+58h] [-B48h] BYREF
  idSWFScriptVar v19; // [sp+60h] [-B40h] BYREF
  idSWFScriptVar v20; // [sp+68h] [-B38h] BYREF
  idSWFScriptVar v21; // [sp+70h] [-B30h] BYREF
  idSWFScriptVar v22; // [sp+78h] [-B28h] BYREF
  idStr v23; // [sp+80h] [-B20h] BYREF
  mpMap_t v24; // [sp+A0h] [-B00h] BYREF

  v4 = 0;
  v5 = this;
  v17 = 0;
  if ( parms->num <= 0 )
  {
    if ( idMainMenu::pMPMaps != nullptr )
    {
      mainMenu = gameLocal->mainMenu;
      matchMapIndex = mainMenu->matchMapIndex;
      v16.index = (int)mainMenu;
      if ( matchMapIndex < 0 || matchMapIndex > idMainMenu::pMPMaps->num )
      {
        this->__vftable = (idMainMenu::idSWFScriptFunction_getModeList_vtbl *)4;
      }
      else
      {
        matchTypeIndex = mainMenu->matchTypeIndex;
        v9 = &idMainMenu::pMPMaps->list[matchMapIndex];
        v16.index = (int)mainMenu;
        type = v9->type;
        if ( type != matchTypeIndex )
        {
          v16.index = (int)mainMenu;
          idLib::Warning(
            fmt: "Selected map index %d doesn't match current game type (%d != %d)",
            matchMapIndex,
            type,
            matchTypeIndex);
          v5->__vftable = (idMainMenu::idSWFScriptFunction_getModeList_vtbl *)4;
          return v5;
        }
        v16.index = (int)v9;
        mpMap_t::mpMap_t(this: &v24, __that: v9);
        v11 = idSWFScriptObject::Alloc();
        idSWFScriptObject::MakeArray(this: v11);
        v12 = 0;
        for ( i = 0; i < 6; ++i )
        {
          if ( v4 < v24.modes.num )
          {
            v14 = idSWFScriptObject::Alloc();
            v16.index = (int)&v24.modes.list[i];
            v16.index = v24.modes.list[i].name.index;
            idSWFScriptVar::idSWFScriptVar(this: &v21, s: &v16);
            idSWFScriptObject::Set(this: v14, name: "name", value: &v21);
            idSWFScriptVar::Free(this: &v21);
            v16.index = v24.modes.list[i].description.index;
            idSWFScriptVar::idSWFScriptVar(this: &v22, s: &v16);
            idSWFScriptObject::Set(this: v14, name: "desc", value: &v22);
            idSWFScriptVar::Free(this: &v22);
            idSWFScriptVar::idSWFScriptVar(this: &v18, s: &v24.modes.list[i].menuMaterial);
            idSWFScriptObject::Set(this: v14, name: "img", value: &v18);
            idSWFScriptVar::Free(this: &v18);
            idSWFScriptVar::idSWFScriptVar(this: &v19, o: v14);
            idSWFScriptObject::Set(this: v11, index: v12, value: &v19);
            idSWFScriptVar::Free(this: &v19);
            idSWFScriptObject::Release(this: v14);
            ++v12;
          }
          ++v4;
        }
        idSWFScriptVar::idSWFScriptVar(this: &v20, o: v11);
        idStr::idStr(this: &v23, text: "modeList");
        idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v23, value: &v20);
        idStr::FreeData(this: &v23);
        idSWFScriptVar::Free(this: &v20);
        idSWFScriptObject::Release(this: v11);
        v5->__vftable = (idMainMenu::idSWFScriptFunction_getModeList_vtbl *)4;
        v17 = 1;
        mpMap_t::~mpMap_t(this: &v24);
      }
      return v5;
    }
    this->__vftable = (idMainMenu::idSWFScriptFunction_getModeList_vtbl *)4;
  }
  else
  {
    idLib::Warning(fmt: "Invalid number of parameters specified for getModeList");
    v5->__vftable = (idMainMenu::idSWFScriptFunction_getModeList_vtbl *)4;
    return v5;
  }
  return this;
}


// ========================================================================
// __unwind$518388
// EA  : 0x82DCF37C
// RVA : 0x00DCF37C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518388()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 2976;
  if ( (*(_DWORD *)(v0 - 2976 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 2996));
  }
}


// ========================================================================
// __unwind$518391
// EA  : 0x82DCF3C0
// RVA : 0x00DCF3C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518391()
{
  int v0; // r12

  mpMap_t::~mpMap_t(this: (mpMap_t *)(v0 - 2976 + 160));
}


// ========================================================================
// __unwind$518392
// EA  : 0x82DCF3E8
// RVA : 0x00DCF3E8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518392()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2976 + 112));
}


// ========================================================================
// __unwind$518393
// EA  : 0x82DCF410
// RVA : 0x00DCF410
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518393()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2976 + 120));
}


// ========================================================================
// __unwind$518394
// EA  : 0x82DCF438
// RVA : 0x00DCF438
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518394()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2976 + 88));
}


// ========================================================================
// __unwind$518395
// EA  : 0x82DCF460
// RVA : 0x00DCF460
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518395()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2976 + 96));
}


// ========================================================================
// __unwind$518396
// EA  : 0x82DCF488
// RVA : 0x00DCF488
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518396()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2976 + 104));
}


// ========================================================================
// __unwind$518397
// EA  : 0x82DCF4B0
// RVA : 0x00DCF4B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518397()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2976 + 128));
}


// ========================================================================
// ?Call@idSWFScriptFunction_getGameModeAvailable@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCF4E0
// RVA : 0x00DCF4E0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getGameModeAvailable *__fastcall idMainMenu::idSWFScriptFunction_getGameModeAvailable::Call(
        idMainMenu::idSWFScriptFunction_getGameModeAvailable *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idSWFScriptVar::swfScriptVarType type; // r11
  char v6; // r11
  bool v7; // zf
  int matchMapIndex; // r30
  int v9; // r29
  mpMap_t v11; // [sp+60h] [-AD0h] BYREF

  if ( parms->num == 1 )
  {
    type = parms->list->type;
    if ( type == SWF_VAR_FLOAT || type == SWF_VAR_INTEGER || (v7 = type != SWF_VAR_BOOL, v6 = 0, !v7) )
      v6 = 1;
    if ( v6 != 0 )
    {
      matchMapIndex = gameLocal->mainMenu->matchMapIndex;
      v9 = idSWFScriptVar::ToInteger(this: parms->list);
      if ( matchMapIndex < 0 || matchMapIndex > idMainMenu::pMPMaps->num )
      {
        idLib::Warning(fmt: "Invalid map index specified for getGameModeAvailable");
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, b: false);
        return this;
      }
      mpMap_t::mpMap_t(this: &v11, __that: &idMainMenu::pMPMaps->list[matchMapIndex]);
      if ( v9 < 0 || v9 > v11.modes.num )
      {
        idLib::Warning(fmt: "Invalid mode index specified for getGameModeAvailable");
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, b: false);
        mpMap_t::~mpMap_t(this: &v11);
        return this;
      }
      else
      {
        idSWFScriptVar::idSWFScriptVar((idSWFScriptVar *)this, b: true);
        mpMap_t::~mpMap_t(this: &v11);
        return this;
      }
    }
  }
  idLib::Warning(fmt: "Invalid parameters specified for getGameModeAvailable");
  this->__vftable = (idMainMenu::idSWFScriptFunction_getGameModeAvailable_vtbl *)4;
  return this;
}


// ========================================================================
// __unwind$518576
// EA  : 0x82DCF638
// RVA : 0x00DCF638
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518576()
{
  int v0; // r12

  mpMap_t::~mpMap_t(this: (mpMap_t *)(v0 - 2864 + 96));
}


// ========================================================================
// __unwind$518573
// EA  : 0x82DCF660
// RVA : 0x00DCF660
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518573()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 2864;
  if ( (*(_DWORD *)(v0 - 2864 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 2884));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_getMissionMapList@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DCF6B0
// RVA : 0x00DCF6B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getMissionMapList *__fastcall idMainMenu::idSWFScriptFunction_getMissionMapList::Call(
        idMainMenu::idSWFScriptFunction_getMissionMapList *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  int num; // r11
  idMainMenu::idSWFScriptFunction_getMissionMapList *v5; // r28
  idSWFScriptVar *v6; // r27
  idSWFScriptObject *v7; // r20
  idList<mpMap_t,57> *v8; // r24
  int v9; // r20
  unsigned int *v10; // r28
  int v11; // r3
  int v12; // r27
  bool v13; // r25
  char *data; // r30
  int v15; // r3
  idSWFScriptObject *v16; // r3
  idSWFScriptObject *v17; // r30
  idSWFScriptVar::swfScriptVarValue_t v18; // r25
  idSWFScriptVar::swfScriptVarValue_t v19; // r25
  unsigned int v20; // r24
  unsigned int index; // r25
  int v22; // r3
  int v23; // r3
  int v24; // r28
  idSWFScriptObject *v28; // [sp+50h] [-C20h]
  int v29; // [sp+54h] [-C1Ch]
  int v30; // [sp+58h] [-C18h]
  int v31; // [sp+5Ch] [-C14h]
  idSWFScriptVar v32; // [sp+60h] [-C10h] BYREF
  idSWFScriptVar v33; // [sp+68h] [-C08h] BYREF
  idSWFScriptVar v34; // [sp+70h] [-C00h] BYREF
  idSWFScriptVar v35; // [sp+78h] [-BF8h] BYREF
  idSWFScriptVar v36; // [sp+80h] [-BF0h] BYREF
  idSWFScriptVar v37; // [sp+88h] [-BE8h] BYREF
  idSWFScriptVar v38; // [sp+90h] [-BE0h] BYREF
  idSWFScriptVar v39; // [sp+98h] [-BD8h] BYREF
  int v40; // [sp+A0h] [-BD0h]
  idSWFScriptVar v41; // [sp+A8h] [-BC8h] BYREF
  idSWFScriptVar v42; // [sp+B0h] [-BC0h] BYREF
  idSWFScriptVar v43; // [sp+B8h] [-BB8h] BYREF
  idMem *v44; // [sp+C0h] [-BB0h]
  idSWFScriptVar v45; // [sp+C8h] [-BA8h] BYREF
  char *v46; // [sp+D0h] [-BA0h]
  idSWFScriptVar v47; // [sp+D8h] [-B98h] BYREF
  idCVar *v48; // [sp+E0h] [-B90h]
  int v49; // [sp+E4h] [-B8Ch]
  const char *v50; // [sp+E8h] [-B88h]
  char *v51; // [sp+ECh] [-B84h]
  char *v52; // [sp+F0h] [-B80h]
  char *v53; // [sp+F4h] [-B7Ch]
  int v54; // [sp+F8h] [-B78h]
  char *v55; // [sp+FCh] [-B74h]
  idStr v56; // [sp+100h] [-B70h] BYREF
  idStr v57; // [sp+120h] [-B50h] BYREF
  mpMap_t v58; // [sp+140h] [-B30h] BYREF

  num = parms->num;
  v5 = this;
  v6 = result;
  v46 = nullptr;
  if ( num == 1 )
  {
    if ( idMainMenu::pMPMaps != nullptr )
    {
      v54 = idSWFScriptVar::ToInteger(this: parms->list);
      v7 = idSWFScriptObject::Alloc();
      v28 = v7;
      idSWFScriptObject::MakeArray(this: v7);
      v40 = 0;
      v29 = 0;
      v44 = &mem;
      v8 = idMainMenu::pMPMaps;
      if ( idMainMenu::pMPMaps->num > 0 )
      {
        v31 = 0;
        v46 = "specialCollectionComplete";
        v52 = "collectionComplete";
        v51 = "map";
        v49 = -2091188224;
        v53 = "disabled";
        v55 = "name";
        v50 = "Map %s - unlockstat %d - userstat: %d disabled: %d \n";
        v48 = &mp_map_unlock_debug;
        do
        {
          mpMap_t::mpMap_t(this: &v58, __that: &v8->list[v31]);
          if ( v58.type == v54 )
          {
            v9 = 0;
            if ( v58.modes.num > 0 )
            {
              v30 = 0;
              do
              {
                v10 = (unsigned int *)&v58.modes.list[v30];
                v11 = (*(int (__fastcall **)(_DWORD))(**(_DWORD **)(v49 - 23172) + 104))(a1: *(_DWORD *)(v49 - 23172));
                v56.len = 0;
                v56.baseBuffer[0] = 0;
                v56.data = v56.baseBuffer;
                v12 = v11;
                v56.allocedAndFlag = 20;
                idStr::ExtractFileBase(this: &v58.map, dest: &v56);
                v13 = false;
                if ( v12 != 0 && v10[29] != -1 )
                  v13 = (_cntlzw((*(int (__fastcall **)(int))(*(_DWORD *)v12 + 64))(a1: v12)) & 0x20) != 0;
                if ( v48->valueInteger != 0 && v12 != 0 )
                {
                  data = v56.data;
                  v15 = (*(int (__fastcall **)(int, unsigned int))(*(_DWORD *)v12 + 64))(a1: v12, a2: v10[29]);
                  idLib::Printf(fmt: v50, data, v10[29], v15, v13);
                }
                v16 = idSWFScriptObject::Alloc();
                v20 = *v10;
                v34.type = SWF_VAR_UNDEF;
                v17 = v16;
                idSWFScriptVar::Free(this: &v34);
                v34.value.i = v20;
                v34.type = SWF_VAR_STRINGID;
                idSWFScriptObject::Set(this: v17, name: v55, value: &v34);
                idSWFScriptVar::Free(this: &v34);
                v35.type = SWF_VAR_UNDEF;
                idSWFScriptVar::Free(this: &v35);
                v35.type = SWF_VAR_STRING;
                v35.value.i = (int)idSWFScriptString::Alloc(s: &v56);
                idSWFScriptObject::Set(this: v17, name: v51, value: &v35);
                idSWFScriptVar::Free(this: &v35);
                v36.type = SWF_VAR_UNDEF;
                idSWFScriptVar::Free(this: &v36);
                v36.value.b = v13;
                v36.type = SWF_VAR_BOOL;
                idSWFScriptObject::Set(this: v17, name: v53, value: &v36);
                idSWFScriptVar::Free(this: &v36);
                v18.i = v10[30];
                v42.type = SWF_VAR_UNDEF;
                idSWFScriptVar::Free(this: &v42);
                v42.value = v18;
                v42.type = SWF_VAR_STRINGID;
                idSWFScriptObject::Set(this: v17, name: "unlockDescription", value: &v42);
                idSWFScriptVar::Free(this: &v42);
                v37.type = SWF_VAR_UNDEF;
                idSWFScriptVar::Free(this: &v37);
                v37.type = SWF_VAR_STRING;
                v37.value.i = (int)idSWFScriptString::Alloc(s: &v58.material);
                idSWFScriptObject::Set(this: v17, name: "img", value: &v37);
                idSWFScriptVar::Free(this: &v37);
                v19.i = v10[1];
                v39.type = SWF_VAR_UNDEF;
                idSWFScriptVar::Free(this: &v39);
                v39.value = v19;
                v39.type = SWF_VAR_STRINGID;
                idSWFScriptObject::Set(this: v17, name: "description", value: &v39);
                idSWFScriptVar::Free(this: &v39);
                v41.type = SWF_VAR_UNDEF;
                idSWFScriptVar::Free(this: &v41);
                v41.type = SWF_VAR_INTEGER;
                v41.value.i = v29;
                idSWFScriptObject::Set(this: v17, name: "mapIndex", value: &v41);
                idSWFScriptVar::Free(this: &v41);
                v43.type = SWF_VAR_UNDEF;
                idSWFScriptVar::Free(this: &v43);
                v43.value.i = v9;
                v43.type = SWF_VAR_INTEGER;
                idSWFScriptObject::Set(this: v17, name: "modeIndex", value: &v43);
                idSWFScriptVar::Free(this: &v43);
                v45.type = SWF_VAR_UNDEF;
                index = v58.introQuote.index;
                idSWFScriptVar::Free(this: &v45);
                v45.value.i = index;
                v45.type = SWF_VAR_STRINGID;
                idSWFScriptObject::Set(this: v17, name: "introQuote", value: &v45);
                idSWFScriptVar::Free(this: &v45);
                LOBYTE(v20) = 0;
                LOBYTE(index) = 0;
                if ( v12 != 0 )
                {
                  if ( v10[36] != -1 )
                  {
                    v22 = (*(int (__fastcall **)(int))(*(_DWORD *)v12 + 64))(a1: v12);
                    v20 = (-v22 & (unsigned int)~v22) >> 31;
                  }
                  if ( v58.challengeSpecialCollectionStat != RAGE_STAT_INVALID )
                  {
                    v23 = (*(int (__fastcall **)(int))(*(_DWORD *)v12 + 64))(a1: v12);
                    index = (-v23 & (unsigned int)~v23) >> 31;
                  }
                }
                v47.type = SWF_VAR_UNDEF;
                idSWFScriptVar::Free(this: &v47);
                v47.value.b = v20;
                v47.type = SWF_VAR_BOOL;
                idSWFScriptObject::Set(this: v17, name: v52, value: &v47);
                idSWFScriptVar::Free(this: &v47);
                v38.type = SWF_VAR_UNDEF;
                idSWFScriptVar::Free(this: &v38);
                v38.value.b = index;
                v38.type = SWF_VAR_BOOL;
                idSWFScriptObject::Set(this: v17, name: v46, value: &v38);
                idSWFScriptVar::Free(this: &v38);
                v32.type = SWF_VAR_UNDEF;
                idSWFScriptVar::Free(this: &v32);
                if ( v17 != nullptr )
                {
                  v32.value.i = (int)v17;
                  v32.type = SWF_VAR_OBJECT;
                  ++v17->refCount;
                }
                else
                {
                  v32.type = SWF_VAR_NULL;
                }
                v24 = v40;
                idSWFScriptObject::Set(this: v28, index: v40, value: &v32);
                v40 = v24 + 1;
                idSWFScriptVar::Free(this: &v32);
                if ( v17->refCount-- == 1 )
                {
                  idSWFScriptObject::~idSWFScriptObject(this: v17);
                  idMem::Free(this: v44, ptr: v17, align: ALIGN_16);
                }
                idStr::FreeData(this: &v56);
                ++v9;
                ++v30;
              }
              while ( v9 < v58.modes.num );
            }
            v7 = v28;
          }
          mpMap_t::~mpMap_t(this: &v58);
          ++v29;
          ++v31;
          v8 = idMainMenu::pMPMaps;
        }
        while ( v29 < idMainMenu::pMPMaps->num );
        v6 = result;
        v5 = this;
      }
      v33.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v33);
      if ( v7 != nullptr )
      {
        v33.value.i = (int)v7;
        v33.type = SWF_VAR_OBJECT;
        ++v7->refCount;
      }
      else
      {
        v33.type = SWF_VAR_NULL;
      }
      idStr::idStr(this: &v57, text: "mapList");
      idMainMenu::SetMainMenuGlobal(this: (idMainMenu *)v6->value.i, name: &v57, value: &v33);
      idStr::FreeData(this: &v57);
      idSWFScriptVar::Free(this: &v33);
      if ( v7->refCount-- == 1 )
      {
        idSWFScriptObject::~idSWFScriptObject(this: v7);
        idMem::Free(this: v44, ptr: v7, align: ALIGN_16);
      }
      v5->__vftable = (idMainMenu::idSWFScriptFunction_getMissionMapList_vtbl *)4;
    }
    else
    {
      this->__vftable = (idMainMenu::idSWFScriptFunction_getMissionMapList_vtbl *)4;
    }
  }
  else
  {
    idLib::Warning(fmt: "Invalid parameters specified for getMissionMapList");
    v5->__vftable = (idMainMenu::idSWFScriptFunction_getMissionMapList_vtbl *)4;
  }
  return v5;
}


// ========================================================================
// __unwind$518679
// EA  : 0x82DCFCFC
// RVA : 0x00DCFCFC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518679()
{
  int v0; // r12

  mpMap_t::~mpMap_t(this: (mpMap_t *)(v0 - 3184 + 320));
}


// ========================================================================
// __unwind$518680
// EA  : 0x82DCFD24
// RVA : 0x00DCFD24
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518680()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 3184 + 256));
}


// ========================================================================
// __unwind$518681
// EA  : 0x82DCFD4C
// RVA : 0x00DCFD4C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518681()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 112));
}


// ========================================================================
// __unwind$518682
// EA  : 0x82DCFD74
// RVA : 0x00DCFD74
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518682()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 120));
}


// ========================================================================
// __unwind$518683
// EA  : 0x82DCFD9C
// RVA : 0x00DCFD9C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518683()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 128));
}


// ========================================================================
// __unwind$518684
// EA  : 0x82DCFDC4
// RVA : 0x00DCFDC4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518684()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 176));
}


// ========================================================================
// __unwind$518685
// EA  : 0x82DCFDEC
// RVA : 0x00DCFDEC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518685()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 136));
}


// ========================================================================
// __unwind$518686_0
// EA  : 0x82DCFE14
// RVA : 0x00DCFE14
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518686_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 152));
}


// ========================================================================
// __unwind$518687
// EA  : 0x82DCFE3C
// RVA : 0x00DCFE3C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518687()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 168));
}


// ========================================================================
// __unwind$518688
// EA  : 0x82DCFE64
// RVA : 0x00DCFE64
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518688()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 184));
}


// ========================================================================
// __unwind$518689
// EA  : 0x82DCFE8C
// RVA : 0x00DCFE8C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518689()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 200));
}


// ========================================================================
// __unwind$518690
// EA  : 0x82DCFEB4
// RVA : 0x00DCFEB4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518690()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 216));
}


// ========================================================================
// __unwind$518691
// EA  : 0x82DCFEDC
// RVA : 0x00DCFEDC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518691()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 144));
}


// ========================================================================
// __unwind$518692
// EA  : 0x82DCFF04
// RVA : 0x00DCFF04
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518692()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 96));
}


// ========================================================================
// __unwind$518693
// EA  : 0x82DCFF2C
// RVA : 0x00DCFF2C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518693()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3184 + 104));
}


// ========================================================================
// __unwind$518694
// EA  : 0x82DCFF54
// RVA : 0x00DCFF54
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_518694()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 3184 + 288));
}


// ========================================================================
// ?UpdateMenuVoteStatus@idMainMenu@@QAAXXZ
// EA  : 0x82DCFF88
// RVA : 0x00DCFF88
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMenuVoteStatus(idMainMenu *this)
{
  idStaticList<idSWFScriptVar,16> v2; // [sp+50h] [-B0h] BYREF

  if ( session->GetState(this: session) == GAME_LOBBY && this->mainMenu != nullptr )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v2);
    idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v2);
    idSWF::Invoke(this: this->mainMenu, functionName: "updateVoteStatus", parms: (const idSWFParmList *)&v2);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v2);
  }
}


// ========================================================================
// __unwind$519184
// EA  : 0x82DD0014
// RVA : 0x00DD0014
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519184()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?UpdateMenuSessionStatus@idMainMenu@@QAAXXZ
// EA  : 0x82DD0048
// RVA : 0x00DD0048
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMenuSessionStatus(idMainMenu *this)
{
  idStaticList<idSWFScriptVar,16> v2; // [sp+50h] [-B0h] BYREF

  if ( this->mainMenu != nullptr )
  {
    idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v2);
    idList<idSWFScriptVar,72>::~idList<idSWFScriptVar,72>(this: &v2);
    idSWF::Invoke(this: this->mainMenu, functionName: "updateSessionStatus", parms: (const idSWFParmList *)&v2);
    idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v2);
  }
}


// ========================================================================
// __unwind$519209
// EA  : 0x82DD00B4
// RVA : 0x00DD00B4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519209()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?UpdateMPMenu@idMainMenu@@QAAXXZ
// EA  : 0x82DD00E8
// RVA : 0x00DD00E8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateMPMenu(idMainMenu *this)
{
  idSWF *mainMenu; // r11
  idMainMenu *v2; // r24
  idSession_vtbl *v3; // r6
  idSession::sessionState_t (__fastcall *GetState)(idSession *); // r6
  unsigned int v5; // r18
  idLobbyBase *v6; // r3
  idLobbyBase *v7; // r29
  int v8; // r17
  int v9; // r26
  int v10; // r21
  idSWFScriptVar::swfScriptVarValue_t v11; // r20
  __int64 v12; // r8
  int v13; // r6
  int i; // r27
  lobbyPlayerInfo_t *v15; // r30
  int v16; // r16
  const char *v17; // r3
  int v18; // r3
  BOOL isMasterLocalUser; // r6
  idLobbyBase *v20; // r3
  idSession_vtbl *v21; // r16
  int v22; // r3
  idLobbyBase *v23; // r3
  int v24; // r3
  int v25; // r30
  int j; // r29
  idLobbyBase *v27; // r3
  idSWFScriptObject *v28; // r16
  int v29; // r15
  idMem *v30; // r26
  lobbyPlayerInfo_t *v31; // r29
  idSWFScriptObject *v32; // r3
  idSWFScriptVar::swfScriptVarValue_t v33; // r14
  idSWFScriptObject *v34; // r30
  int level; // r14
  const char *LocalizedString; // r3
  idSWFScriptVar::swfScriptVarValue_t v37; // r14
  idSWFScriptVar::swfScriptVarValue_t v38; // r29
  idSWFScriptObject *v41; // r30
  idLobbyBase *v42; // r3
  const char *v43; // r3
  const idStr *v44; // r25
  idLobbyBase *v46; // r3
  idSWFScriptVar::swfScriptVarValue_t v47; // r30
  idLobbyBase *v48; // r3
  int v49; // r3
  idSWFScriptVar::swfScriptVarValue_t v50; // r26
  idLobbyBase *v51; // r3
  idSWFScriptVar::swfScriptVarValue_t v52; // r30
  idLobbyController *lobbyController; // r3
  unsigned int skipVoteState; // r11
  const char *v55; // r3
  idSWFScriptVar *v56; // r3
  int v57; // r30
  const char *String; // r3
  __int64 v59; // r6
  __int64 v60; // r10
  __int64 v61; // r8
  va *v62; // r3
  int v63; // [sp+8h] [-1378h]
  int v64; // [sp+Ch] [-1374h]
  int v65; // [sp+10h] [-1370h]
  int v66; // [sp+14h] [-136Ch]
  int v67; // [sp+18h] [-1368h]
  int v68; // [sp+1Ch] [-1364h]
  idLobbyBase *v69; // [sp+50h] [-1330h] BYREF
  lobbyUserID_t *v70; // [sp+54h] [-132Ch]
  idSWFScriptVar v71; // [sp+58h] [-1328h] BYREF
  idSWFScriptVar v72; // [sp+60h] [-1320h] BYREF
  idSWFScriptVar v73; // [sp+68h] [-1318h] BYREF
  idSWFScriptVar v74; // [sp+70h] [-1310h] BYREF
  idSWFScriptVar v75; // [sp+78h] [-1308h] BYREF
  idSWFScriptVar::swfScriptVarValue_t v76; // [sp+80h] [-1300h]
  idSWFScriptVar v77; // [sp+88h] [-12F8h] BYREF
  idSWFScriptVar v78; // [sp+90h] [-12F0h] BYREF
  idSWFScriptVar v79; // [sp+98h] [-12E8h] BYREF
  idSort_Quick<lobbyPlayerInfo_t,idSort_LobbyPlayerInfoRef_ByPartyAndName> v80; // [sp+A0h] [-12E0h] BYREF
  idSWFScriptVar v81; // [sp+A8h] [-12D8h] BYREF
  idSWFScriptVar v82; // [sp+B0h] [-12D0h] BYREF
  idSWFScriptVar v83; // [sp+B8h] [-12C8h] BYREF
  idSWFScriptVar v84; // [sp+C0h] [-12C0h] BYREF
  idSWFScriptVar v85; // [sp+C8h] [-12B8h] BYREF
  idSWFScriptVar v86; // [sp+D0h] [-12B0h] BYREF
  idSWFScriptVar v87; // [sp+D8h] [-12A8h] BYREF
  idSWFScriptVar v88; // [sp+E0h] [-12A0h] BYREF
  idSession::sessionState_t v89; // [sp+E8h] [-1298h]
  idStrId v90; // [sp+ECh] [-1294h] BYREF
  idSWFScriptVar v91; // [sp+F0h] [-1290h] BYREF
  idSWFScriptVar v92; // [sp+F8h] [-1288h] BYREF
  idSWFScriptVar v93; // [sp+100h] [-1280h] BYREF
  idSWFScriptVar v94; // [sp+108h] [-1278h] BYREF
  _DWORD v95[12]; // [sp+110h] [-1270h] BYREF
  idStr v96; // [sp+140h] [-1240h] BYREF
  idStr v97; // [sp+160h] [-1220h] BYREF
  idStaticList<lobbyPlayerInfo_t,6> v98; // [sp+180h] [-1200h] BYREF
  va v99; // [sp+2E0h] [-10A0h] BYREF

  mainMenu = this->mainMenu;
  v2 = this;
  if ( mainMenu != nullptr
    && mainMenu->isActive
    && session->GetState(this: session) != (PARTY_LOBBY|SEARCHING)
    && session->GetState(this: session) != INGAME
    && !gameLocal->IsGameActive(this: gameLocal) )
  {
    v95[0] = "#str_online_mpstatus_press_start";
    v3 = session->__vftable;
    v95[1] = "#str_online_mpstatus_idle";
    GetState = v3->GetState;
    v95[2] = "#str_online_mpstatus_searching";
    v95[3] = "#str_online_mpstatus_connecting";
    v95[4] = "#str_online_mpstatus_waiting_for_party_players";
    v95[5] = "#str_online_mpstatus_waiting_for_players";
    v95[6] = "#str_online_mpstatus_loading";
    v95[7] = "#str_online_mpstatus_ingame";
    v95[8] = "#str_online_mpstatus_busy";
    v89 = GetState(this: session);
    v5 = v89;
    idSWFScriptVar::idSWFScriptVar(this: &v93, s: (const char *)v95[v89]);
    idSWFScriptObject::Set(this: v2->mainMenu->globals, name: "mpstatus", value: &v93);
    idSWFScriptVar::Free(this: &v93);
    if ( !common->IsMultiplayer(this: common) )
    {
      idMainMenu::SyncMenuStateWithSession(this: v2, sessionState: v89);
      idMainMenu::UpdateMenuArea(this: v2);
      return;
    }
    idLobbyController::Pump(this: v2->lobbyController);
    if ( session->GetState(this: session) == 1 )
      idLobbyController::Reset(this: v2->lobbyController);
    if ( session->GetState(this: session) == GAME_LOBBY )
    {
      v6 = session->GetGameLobbyBase(this: session);
      if ( v6->IsPeer(this: v6) )
      {
        idMainMenu::CopySettingsFromSession(this: v2);
        idMainMenu::UpdateMenuSessionStatus(this: v2);
      }
    }
    v7 = session->GetActivePlatformLobbyBase(this: session);
    v8 = 0;
    v9 = v7->GetNumLobbyUsers(this: v7);
    v76.i = 0;
    v10 = 0;
    v11.i = 0;
    idStaticList<lobbyPlayerInfo_t,6>::idStaticList<lobbyPlayerInfo_t,6>(this: &v98);
    for ( i = 0; i < v9; ++i )
    {
      v15 = idList<lobbyPlayerInfo_t,5>::Alloc(this: &v98);
      v7->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)&v69, result: (lobbyUserID_t *)v7, a3: i);
      v15->sessionUserIndex = i;
      v16 = (int)v7->GetLocalUserFromLobbyUser(this: v69, a2: v70);
      v15->isMasterLocalUser = (_cntlzw(v16 - (unsigned int)common->GetMasterLocalUser(this: common)) & 0x20) != 0;
      v17 = v7->GetLobbyUserName(this: v69, a2: v70);
      idStr::operator=(this: &v15->name, text: v17);
      v18 = v7->GetLobbyUserPartyToken(this: v69, a2: v70);
      isMasterLocalUser = v15->isMasterLocalUser;
      v15->partyToken = v18;
      if ( isMasterLocalUser )
        v10 = v18;
      v20 = session->GetActivePlatformLobbyBase(this: session);
      v15->level = ((int (*)(void))v20->GetLobbyUserLevel)();
      v21 = session->__vftable;
      v22 = ((int (*)(void))session->GetLobbyUserVoiceState)();
      v15->voiceState = v21->GetDisplayStateFromVoiceState(this: session, a2: (voiceState_t)v22);
      v23 = session->GetActivePlatformLobbyBase(this: session);
      v24 = ((int (*)(void))v23->GetLobbyUserQoS)();
      if ( v24 <= 200 )
      {
        if ( v24 <= 100 )
        {
          if ( v24 <= 50 )
            v15->qosState = QOS_STATE_GREAT;
          else
            v15->qosState = QOS_STATE_GOOD;
        }
        else
        {
          v15->qosState = QOS_STATE_WEAK;
        }
      }
      else
      {
        v15->qosState = QOS_STATE_CRAPPY;
      }
    }
    if ( v9 > 0 )
    {
      v25 = 0;
      for ( j = v9; j != 0; --j )
      {
        v27 = session->GetPartyLobbyBase(this: session);
        if ( v27->GetNumLobbyUsers(this: v27) > 1 && v98.list[v25].partyToken == v10 )
        {
          ++v11.i;
          v98.list[v25].isPartyMember = true;
        }
        else
        {
          v98.list[v25].isPartyMember = false;
        }
        ++v25;
      }
      v76.f = v11.f;
    }
    v80.__vftable = (idSort_Quick<lobbyPlayerInfo_t,idSort_LobbyPlayerInfoRef_ByPartyAndName>_vtbl *)&idSort_LobbyPlayerInfoRef_ByPartyAndName::`vftable';
    if ( v98.list != nullptr )
      idSort_Quick<lobbyPlayerInfo_t,idSort_LobbyPlayerInfoRef_ByPartyAndName>::Sort(
        this: &v80,
        base: v98.list,
        num: v98.num,
        a4: v13,
        a5: v12);
    v80.__vftable = (idSort_Quick<lobbyPlayerInfo_t,idSort_LobbyPlayerInfoRef_ByPartyAndName>_vtbl *)&idSort<lobbyPlayerInfo_t>::`vftable';
    v28 = idSWFScriptObject::Alloc();
    idSWFScriptObject::MakeArray(this: v28);
    v96.len = 0;
    v96.allocedAndFlag = 20;
    v96.data = v96.baseBuffer;
    v96.baseBuffer[0] = 0;
    v29 = 0;
    v30 = &mem;
    v69 = (idLobbyBase *)&mem;
    if ( v98.num > 0 )
    {
      do
      {
        v31 = &v98.list[v8];
        v32 = idSWFScriptObject::Alloc();
        SLODWORD(v33.f) = v31->sessionUserIndex;
        v34 = v32;
        v86.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v86);
        v86.value = v33;
        v86.type = SWF_VAR_INTEGER;
        idSWFScriptObject::Set(this: v34, name: "sessionUserIndex", value: &v86);
        idSWFScriptVar::Free(this: &v86);
        *(&v33.b + 3) = v31->isMasterLocalUser;
        v87.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v87);
        v87.value.b = *(&v33.b + 3);
        v87.type = SWF_VAR_BOOL;
        idSWFScriptObject::Set(this: v34, name: "isMasterLocalUser", value: &v87);
        idSWFScriptVar::Free(this: &v87);
        *(&v33.b + 3) = v31->isPartyMember;
        v81.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v81);
        v81.value.b = *(&v33.b + 3);
        v81.type = SWF_VAR_BOOL;
        idSWFScriptObject::Set(this: v34, name: "isPartyMember", value: &v81);
        idSWFScriptVar::Free(this: &v81);
        idStrId::Set(this: &v90, key: "#str_swf_lvl_short");
        level = v31->level;
        LocalizedString = idStrId::GetLocalizedString(this: &v90);
        idStr::Format(this: &v96, fmt: LocalizedString, level);
        v85.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v85);
        v85.type = SWF_VAR_STRING;
        v85.value.i = (int)idSWFScriptString::Alloc(s: &v96);
        idSWFScriptObject::Set(this: v34, name: "rank", value: &v85);
        idSWFScriptVar::Free(this: &v85);
        v83.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v83);
        v83.type = SWF_VAR_STRING;
        v83.value.i = (int)idSWFScriptString::Alloc(s: &v31->name);
        idSWFScriptObject::Set(this: v34, name: "name", value: &v83);
        idSWFScriptVar::Free(this: &v83);
        SLODWORD(v37.f) = v31->voiceState;
        v78.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v78);
        v78.value = v37;
        v78.type = SWF_VAR_INTEGER;
        idSWFScriptObject::Set(this: v34, name: "voiceState", value: &v78);
        idSWFScriptVar::Free(this: &v78);
        SLODWORD(v38.f) = v31->qosState;
        v74.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v74);
        v74.value = v38;
        v74.type = SWF_VAR_INTEGER;
        idSWFScriptObject::Set(this: v34, name: "qosState", value: &v74);
        idSWFScriptVar::Free(this: &v74);
        v71.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v71);
        if ( v34 != nullptr )
        {
          v71.value.i = (int)v34;
          v71.type = SWF_VAR_OBJECT;
          ++v34->refCount;
        }
        else
        {
          v71.type = SWF_VAR_NULL;
        }
        idSWFScriptObject::Set(this: v28, index: v29, value: &v71);
        idSWFScriptVar::Free(this: &v71);
        if ( v34->refCount-- == 1 )
        {
          idSWFScriptObject::~idSWFScriptObject(this: v34);
          idMem::Free(this: (idMem *)v69, ptr: v34, align: ALIGN_16);
        }
        ++v29;
        ++v8;
      }
      while ( v29 < v98.num );
      v2 = this;
      v11.f = v76.f;
      v5 = v89;
      v30 = (idMem *)v69;
    }
    v73.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v73);
    if ( v28 != nullptr )
    {
      v73.value.i = (int)v28;
      v73.type = SWF_VAR_OBJECT;
      ++v28->refCount;
    }
    else
    {
      v73.type = SWF_VAR_NULL;
    }
    idSWFScriptObject::Set(this: v2->mainMenu->globals, name: "playerList", value: &v73);
    idSWFScriptVar::Free(this: &v73);
    if ( v28->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: v28);
      idMem::Free(this: v30, ptr: v28, align: ALIGN_16);
    }
    v82.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v82);
    v82.type = SWF_VAR_INTEGER;
    v82.value.i = 6;
    idSWFScriptObject::Set(this: v2->mainMenu->globals, name: "PLAYER_LIST_SIZE", value: &v82);
    idSWFScriptVar::Free(this: &v82);
    v41 = idSWFScriptObject::Alloc();
    v42 = session->GetPartyLobbyBase(this: session);
    v43 = v42->GetHostUserName(this: v42);
    v84.type = SWF_VAR_UNDEF;
    v44 = idStr::idStr(this: &v97, text: v43);
    idSWFScriptVar::Free(this: &v84);
    v84.type = SWF_VAR_STRING;
    v84.value.i = (int)idSWFScriptString::Alloc(s: v44);
    idStr::FreeData(this: &v97);
    idSWFScriptObject::Set(this: v41, name: "leaderName", value: &v84);
    idSWFScriptVar::Free(this: &v84);
    v75.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v75);
    v75.value = v11;
    v75.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: v41, name: "numMembers", value: &v75);
    idSWFScriptVar::Free(this: &v75);
    v72.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v72);
    if ( v41 != nullptr )
    {
      v72.value.i = (int)v41;
      v72.type = SWF_VAR_OBJECT;
      ++v41->refCount;
    }
    else
    {
      v72.type = SWF_VAR_NULL;
    }
    idSWFScriptObject::Set(this: v2->mainMenu->globals, name: "partyInfo", value: &v72);
    idSWFScriptVar::Free(this: &v72);
    if ( v41->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: v41);
      idMem::Free(this: v30, ptr: v41, align: ALIGN_16);
    }
    idMainMenu::SyncMenuStateWithSession(this: v2, sessionState: v5);
    idMainMenu::UpdateMenuArea(this: v2);
    v46 = session->GetGameLobbyBase(this: session);
    v47.i = v46->GetNumLobbyUsersOnTeam(this: v46, a2: 1);
    v48 = session->GetGameLobbyBase(this: session);
    v49 = v48->GetNumLobbyUsersOnTeam(this: v48, a2: 2);
    v77.type = SWF_VAR_UNDEF;
    v50.i = v49;
    idSWFScriptVar::Free(this: &v77);
    v77.value = v47;
    v77.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: v2->mainMenu->globals, name: "mpTeamCount1", value: &v77);
    idSWFScriptVar::Free(this: &v77);
    v88.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v88);
    v88.value = v50;
    v88.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: v2->mainMenu->globals, name: "mpTeamCount2", value: &v88);
    idSWFScriptVar::Free(this: &v88);
    v51 = session->GetGameLobbyBase(this: session);
    SLODWORD(v52.f) = v51->GetMatchParms(this: v51)->gameType;
    v79.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v79);
    v79.value = v52;
    v79.type = SWF_VAR_INTEGER;
    idSWFScriptObject::Set(this: v2->mainMenu->globals, name: "sessionType", value: &v79);
    idSWFScriptVar::Free(this: &v79);
    lobbyController = v2->lobbyController;
    skipVoteState = lobbyController->skipVoteState;
    if ( skipVoteState != 0 )
    {
      if ( skipVoteState == 1 )
      {
        v57 = idLobbyController::CalcNumSkipVotesRequiredToPass(this: lobbyController);
        String = idLocalization::GetString(inString: "#str_online_num_votes");
        HIDWORD(v59) = v57;
        v62 = va::va(
                this: &v99,
                fmt: String,
                a3: v59,
                a4: v61,
                a5: v60,
                a6: v63,
                a7: v64,
                a8: v65,
                a9: v66,
                a10: v67,
                a11: v68);
        v91.type = SWF_VAR_UNDEF;
        idSWFScriptVar::SetString(this: &v91, s: v62);
        idSWFScriptObject::Set(this: v2->mainMenu->globals, name: "mpvotes", value: &v91);
        v56 = &v91;
      }
      else
      {
        if ( skipVoteState >= 3 )
        {
LABEL_59:
          idStr::FreeData(this: &v96);
          idStaticList<lobbyPlayerInfo_t,6>::~idStaticList<lobbyPlayerInfo_t,6>(this: &v98);
          return;
        }
        v55 = idLocalization::GetString(inString: "#str_online_vote_successful");
        idSWFScriptVar::idSWFScriptVar(this: &v94, s: v55);
        idSWFScriptObject::Set(this: v2->mainMenu->globals, name: "mpvotes", value: &v94);
        v56 = &v94;
      }
    }
    else
    {
      v92.type = SWF_VAR_UNDEF;
      idSWFScriptObject::Set(this: v2->mainMenu->globals, name: "mpvotes", value: &v92);
      v56 = &v92;
    }
    idSWFScriptVar::Free(this: v56);
    goto LABEL_59;
  }
}


// ========================================================================
// __unwind$519256
// EA  : 0x82DD0C44
// RVA : 0x00DD0C44
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519256()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 256));
}


// ========================================================================
// __unwind$519257
// EA  : 0x82DD0C6C
// RVA : 0x00DD0C6C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519257()
{
  int v0; // r12

  idStaticList<lobbyPlayerInfo_t,6>::~idStaticList<lobbyPlayerInfo_t,6>(this: (idStaticList<lobbyPlayerInfo_t,6> *)(v0 - 4992 + 384));
}


// ========================================================================
// __unwind$519258
// EA  : 0x82DD0C94
// RVA : 0x00DD0C94
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519258()
{
  int v0; // r12

  idSort_LobbyPlayerInfoRef_ByPartyAndName::~idSort_LobbyPlayerInfoRef_ByPartyAndName(this: (idSort_LobbyPlayerInfoRef_ByPartyAndName *)(v0 - 4992 + 160));
}


// ========================================================================
// __unwind$519259_0
// EA  : 0x82DD0CBC
// RVA : 0x00DD0CBC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519259_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4992 + 320));
}


// ========================================================================
// __unwind$519260_0
// EA  : 0x82DD0CE4
// RVA : 0x00DD0CE4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519260_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 208));
}


// ========================================================================
// __unwind$519261_0
// EA  : 0x82DD0D0C
// RVA : 0x00DD0D0C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519261_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 216));
}


// ========================================================================
// __unwind$519262_0
// EA  : 0x82DD0D34
// RVA : 0x00DD0D34
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519262_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 168));
}


// ========================================================================
// __unwind$519263_0
// EA  : 0x82DD0D5C
// RVA : 0x00DD0D5C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519263_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 200));
}


// ========================================================================
// __unwind$519264_0
// EA  : 0x82DD0D84
// RVA : 0x00DD0D84
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519264_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 184));
}


// ========================================================================
// __unwind$519265_0
// EA  : 0x82DD0DAC
// RVA : 0x00DD0DAC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519265_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 144));
}


// ========================================================================
// __unwind$519266_0
// EA  : 0x82DD0DD4
// RVA : 0x00DD0DD4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519266_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 112));
}


// ========================================================================
// __unwind$519267
// EA  : 0x82DD0DFC
// RVA : 0x00DD0DFC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519267()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 88));
}


// ========================================================================
// __unwind$519268
// EA  : 0x82DD0E24
// RVA : 0x00DD0E24
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519268()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 104));
}


// ========================================================================
// __unwind$519269
// EA  : 0x82DD0E4C
// RVA : 0x00DD0E4C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519269()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 176));
}


// ========================================================================
// __unwind$519576
// EA  : 0x82DD0E74
// RVA : 0x00DD0E74
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519576()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4992 + 352));
}


// ========================================================================
// __unwind$519270
// EA  : 0x82DD0E9C
// RVA : 0x00DD0E9C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519270()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 192));
}


// ========================================================================
// __unwind$519271
// EA  : 0x82DD0EC4
// RVA : 0x00DD0EC4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519271()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 120));
}


// ========================================================================
// __unwind$519272
// EA  : 0x82DD0EEC
// RVA : 0x00DD0EEC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519272()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 96));
}


// ========================================================================
// __unwind$519273
// EA  : 0x82DD0F14
// RVA : 0x00DD0F14
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519273()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 136));
}


// ========================================================================
// __unwind$519274
// EA  : 0x82DD0F3C
// RVA : 0x00DD0F3C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519274()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 224));
}


// ========================================================================
// __unwind$519275
// EA  : 0x82DD0F64
// RVA : 0x00DD0F64
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519275()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 152));
}


// ========================================================================
// __unwind$519278
// EA  : 0x82DD0F8C
// RVA : 0x00DD0F8C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519278()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 264));
}


// ========================================================================
// __unwind$519277
// EA  : 0x82DD0FB4
// RVA : 0x00DD0FB4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519277()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 240));
}


// ========================================================================
// __unwind$519276
// EA  : 0x82DD0FDC
// RVA : 0x00DD0FDC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519276()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 4992 + 248));
}


// ========================================================================
// ?GoToPartyLobby@idMainMenu@@QAAXXZ
// EA  : 0x82DD1010
// RVA : 0x00DD1010
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::GoToPartyLobby(idMainMenu *this)
{
  idStaticList<idSWFScriptVar,16> v2; // [sp+50h] [-B0h] BYREF

  idMainMenu::CopySettingsFromSession(this);
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v2);
  idSWF::Invoke(this: this->mainMenu, functionName: SCREENNAME_LOBBY_PARTY, parms: (const idSWFParmList *)&v2);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v2);
}


// ========================================================================
// __unwind$519908
// EA  : 0x82DD106C
// RVA : 0x00DD106C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519908()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?GoToSplashScreen@idMainMenu@@QAAXXZ
// EA  : 0x82DD10A0
// RVA : 0x00DD10A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::GoToSplashScreen(idMainMenu *this)
{
  idStaticList<idSWFScriptVar,16> v2; // [sp+50h] [-B0h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v2);
  idSWF::Invoke(this: this->mainMenu, functionName: SCREENNAME_SPLASH, parms: (const idSWFParmList *)&v2);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v2);
}


// ========================================================================
// __unwind$519933
// EA  : 0x82DD10F8
// RVA : 0x00DD10F8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519933()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?GoToGameLobby@idMainMenu@@QAAXXZ
// EA  : 0x82DD1128
// RVA : 0x00DD1128
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::GoToGameLobby(idMainMenu *this)
{
  int matchTypeIndex; // r11
  const char *v3; // r4
  idLobbyBase *v4; // r3
  idStr v5; // [sp+50h] [-D0h] BYREF
  idStaticList<idSWFScriptVar,16> v6; // [sp+70h] [-B0h] BYREF

  idMainMenu::CopySettingsFromSession(this);
  v5.len = 0;
  v5.baseBuffer[0] = 0;
  v5.allocedAndFlag = 20;
  v5.data = v5.baseBuffer;
  matchTypeIndex = this->matchTypeIndex;
  if ( matchTypeIndex == 1 )
  {
    if ( this->privateMatch )
      v3 = SCREENNAME_LOBBY_COOP_PRIVATE;
    else
      v3 = SCREENNAME_LOBBY_COOP_PUBLIC;
  }
  else
  {
    if ( matchTypeIndex != 2 )
      goto _M520037;
    if ( this->privateMatch )
      v3 = SCREENNAME_LOBBY_VDM_PRIVATE;
    else
      v3 = SCREENNAME_LOBBY_VDM_PUBLIC;
  }
  idStr::operator=(this: &v5, text: v3);
  idLobbyController::Reset(this: this->lobbyController);
  if ( !this->privateMatch && idStr::Cmp(s1: v5.data, s2: SCREENNAME_LOBBY_VDM_PUBLIC) == 0 )
  {
    v4 = session->GetGameLobbyBase(this: session);
    if ( v4->IsHost(this: v4) != 0 )
      idLobbyController::StartIntermission(this: this->lobbyController, randomMap: true);
  }
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v6);
  idSWF::Invoke(this: this->mainMenu, functionName: v5.data, parms: (const idSWFParmList *)&v6);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v6);
_M520037:
  idStr::FreeData(this: &v5);
}


// ========================================================================
// __unwind$519962
// EA  : 0x82DD1264
// RVA : 0x00DD1264
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519962()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 288 + 80));
}


// ========================================================================
// __unwind$519963
// EA  : 0x82DD128C
// RVA : 0x00DD128C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_519963()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 112));
}


// ========================================================================
// ?DisplayTextChatMessage@idMainMenu@@QAAXABVidStr@@@Z
// EA  : 0x82DD12C0
// RVA : 0x00DD12C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::DisplayTextChatMessage(idMainMenu *this, const idStr *message)
{
  int len; // r6
  idStrStatic<2048> *p_chatHistory; // r30
  int v6; // r10
  char *data; // r3
  int v8; // r3
  const idStrStatic<2048> *v9; // r3
  char *v10; // r4
  size_t v11; // r5
  char *v12; // r3
  int v13; // r11
  char *v14; // r7
  int v15; // r11
  idSWFScriptVar v16; // [sp+50h] [-930h] BYREF
  idSWFScriptVar v17; // [sp+58h] [-928h] BYREF
  int v18; // [sp+60h] [-920h]
  idStr v19; // [sp+70h] [-910h] BYREF
  idStaticList<idSWFScriptVar,16> v20; // [sp+90h] [-8F0h] BYREF
  idStrStatic<2048> v21; // [sp+120h] [-860h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v20);
  v17.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v17);
  v17.type = SWF_VAR_STRING;
  v17.value.i = (int)idSWFScriptString::Alloc(s: message);
  idSWFParmList::Append(this: (idSWFParmList *)&v20, other: &v17);
  idSWFScriptVar::Free(this: &v17);
  idSWF::Invoke(this: this->mainMenu, functionName: "TextChatUpdated", parms: (const idSWFParmList *)&v20);
  len = this->chatHistory.len;
  p_chatHistory = &this->chatHistory;
  v6 = len + message->len;
  v18 = len;
  if ( v6 >= 1024 )
  {
    do
    {
      data = this->chatHistory.data;
      v18 = len;
      v8 = idStr::Find(str: data, c: 10, start: 0, end: len);
      if ( v8 == 0 )
        v8 = idStr::Find(str: this->chatHistory.data, c: 10, start: 1, end: p_chatHistory->len);
      if ( v8 != -1 )
      {
        v9 = (const idStrStatic<2048> *)idStr::Mid(
                                          this: &v19,
                                          result: &this->chatHistory,
                                          start: v8,
                                          len: p_chatHistory->len - v8);
        idStrStatic<2048>::idStrStatic<2048>(this: &v21, text: v9);
        v10 = v21.data;
        v11 = v21.len + 1;
        v12 = this->chatHistory.data;
        p_chatHistory->len = v21.len;
        memcpy(Dst: v12, Src: v10, Size: v11);
        idStr::FreeData(this: &v21);
        idStr::FreeData(this: &v19);
      }
      len = p_chatHistory->len;
      v13 = p_chatHistory->len + message->len;
      v18 = p_chatHistory->len;
    }
    while ( v13 >= 1024 );
  }
  idStr::Append(this: &this->chatHistory, text: message);
  idStr::EnsureAlloced(this: &this->chatHistory, amount: p_chatHistory->len + 2, keepold: true, geometricGrowth: true);
  this->chatHistory.data[p_chatHistory->len] = 10;
  v14 = this->chatHistory.data;
  v15 = p_chatHistory->len + 1;
  p_chatHistory->len = v15;
  v14[v15] = 0;
  v16.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v16);
  v16.type = SWF_VAR_STRING;
  v16.value.i = (int)idSWFScriptString::Alloc(s: &this->chatHistory);
  idSWFScriptObject::Set(this: this->mainMenu->globals, name: "textchat", value: &v16);
  idSWFScriptVar::Free(this: &v16);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v20);
}


// ========================================================================
// __unwind$520059
// EA  : 0x82DD147C
// RVA : 0x00DD147C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520059()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 2432 + 144));
}


// ========================================================================
// __unwind$520060
// EA  : 0x82DD14A4
// RVA : 0x00DD14A4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520060()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2432 + 88));
}


// ========================================================================
// __unwind$520061
// EA  : 0x82DD14CC
// RVA : 0x00DD14CC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520061()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 2432 + 112));
}


// ========================================================================
// __unwind$520063
// EA  : 0x82DD14F4
// RVA : 0x00DD14F4
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520063()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 2432 + 80));
}


// ========================================================================
// ?GoToMultiplayerMainMenu@idMainMenu@@QAAXXZ
// EA  : 0x82DD1528
// RVA : 0x00DD1528
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::GoToMultiplayerMainMenu(idMainMenu *this)
{
  idStaticList<idSWFScriptVar,16> v2; // [sp+50h] [-B0h] BYREF

  idLobbyController::Reset(this: this->lobbyController);
  session->Cancel(this: session);
  idMainMenu::ForceMenuArea(this, newMenuArea: MENU_MAIN);
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v2);
  if ( v2.listStatic == 0 || v2.listStatic == 2 )
  {
    if ( v2.list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v2.list, num: v2.size);
    v2.list = nullptr;
    v2.size = 0;
  }
  v2.num = 0;
  idSWF::Invoke(this: this->mainMenu, functionName: "startPressed", parms: (const idSWFParmList *)&v2);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v2);
}


// ========================================================================
// __unwind$520183
// EA  : 0x82DD15CC
// RVA : 0x00DD15CC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520183()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 256 + 80));
}


// ========================================================================
// ?RefreshLeaderboard@idMainMenu@@QAAXXZ
// EA  : 0x82DD1600
// RVA : 0x00DD1600
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::RefreshLeaderboard(idMainMenu *this)
{
  idSWFScriptObject *v2; // r25
  const char *v3; // r14
  idLBCache *lbCache; // r11
  idSWFScriptObject *v5; // r30
  idLBCache *v6; // r3
  int v7; // r26
  const idLeaderboardCallback::row_t *LeaderboardRow; // r27
  __int64 rank; // r14
  __int128 v10; // r6
  idSWFScriptVar *v11; // r3
  __int128 v12; // r6
  idSWFScriptVar *v13; // r3
  int localIndex; // r27
  idSWFScriptVar *v15; // r3
  int v16; // r27
  idSWFScriptVar *v17; // r3
  __int64 v19; // r10
  int index; // r30
  int v21; // r11
  int v22; // r30
  int v23; // r30
  idSWFScriptVar *v24; // r3
  int v25; // r30
  int v26; // r11
  int v27; // r30
  int v28; // r30
  idLBCache *FilterStrType; // r3
  bool v31; // [sp+50h] [-240h]
  bool v32; // [sp+51h] [-23Fh]
  int v33; // [sp+54h] [-23Ch]
  int rowOffset; // [sp+58h] [-238h]
  int numRowsInLeaderboard; // [sp+5Ch] [-234h]
  idSWFScriptVar v36; // [sp+60h] [-230h] BYREF
  idSWFScriptVar v37; // [sp+68h] [-228h] BYREF
  idSWFScriptVar v38; // [sp+70h] [-220h] BYREF
  idSWFScriptVar v39; // [sp+78h] [-218h] BYREF
  idSWFScriptVar v40; // [sp+80h] [-210h] BYREF
  idSWFScriptVar v41; // [sp+88h] [-208h] BYREF
  idSWFScriptVar v42; // [sp+90h] [-200h] BYREF
  idSWFScriptVar v43; // [sp+98h] [-1F8h] BYREF
  idSWFScriptVar v44; // [sp+A0h] [-1F0h] BYREF
  idSWFScriptVar v45; // [sp+A8h] [-1E8h] BYREF
  idSWFScriptVar v46; // [sp+B0h] [-1E0h] BYREF
  idSWFScriptVar v47; // [sp+B8h] [-1D8h] BYREF
  idSWFScriptVar v48; // [sp+C0h] [-1D0h] BYREF
  idSWFScriptVar v49; // [sp+C8h] [-1C8h] BYREF
  idSWFScriptVar v50; // [sp+D0h] [-1C0h] BYREF
  idSWFScriptVar v51; // [sp+D8h] [-1B8h] BYREF
  idSWFScriptVar v52; // [sp+E0h] [-1B0h] BYREF
  idSWFScriptVar v53; // [sp+E8h] [-1A8h] BYREF
  idSWFScriptVar v54; // [sp+F0h] [-1A0h] BYREF
  idSWFScriptVar v55; // [sp+F8h] [-198h] BYREF
  idMem *v56; // [sp+100h] [-190h]
  char *v57; // [sp+104h] [-18Ch]
  idSWFScriptVar v58; // [sp+108h] [-188h] BYREF
  idSWFScriptVar v59; // [sp+110h] [-180h] BYREF
  idSWFScriptVar v60; // [sp+118h] [-178h] BYREF
  _DWORD v61[4]; // [sp+120h] [-170h] BYREF
  idSWFScriptVar v62; // [sp+130h] [-160h] BYREF
  idSWFScriptVar v63; // [sp+138h] [-158h] BYREF
  idLBCache v64[2]; // [sp+140h] [-150h] BYREF

  numRowsInLeaderboard = this->lbCache->numRowsInLeaderboard;
  v2 = idSWFScriptObject::Alloc();
  idSWFScriptObject::MakeArray(this: v2);
  v56 = &mem;
  v32 = false;
  v3 = &byte_8200D768;
  v31 = true;
  v57 = &byte_8200D768;
  lbCache = this->lbCache;
  if ( !lbCache->loadingNewLeaderboard && lbCache->errorCode == LEADERBOARD_DISPLAY_ERROR_NONE )
  {
    v33 = 0;
    do
    {
      v5 = idSWFScriptObject::Alloc();
      v6 = this->lbCache;
      v7 = v6->rowOffset + v33;
      LeaderboardRow = idLBCache::GetLeaderboardRow(this: v6, row: v7);
      if ( LeaderboardRow != nullptr )
      {
        v40.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v40);
        v40.type = SWF_VAR_STRING;
        v40.value.i = (int)idSWFScriptString::Alloc(s: &LeaderboardRow->name);
        idSWFScriptObject::Set(this: v5, name: "name", value: &v40);
        idSWFScriptVar::Free(this: &v40);
        rank = LeaderboardRow->rank;
        v52.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v52);
        v52.value.i = rank;
        v52.type = SWF_VAR_INTEGER;
        idSWFScriptObject::Set(this: v5, name: "rank", value: &v52);
        idSWFScriptVar::Free(this: &v52);
        *(_QWORD *)((char *)&v10 + 4) = LeaderboardRow->columns.ptr[0];
        v11 = FormatColumn(result: &v63, columnDef: this->lbCache->def->columnDefs, score: v10);
        idSWFScriptObject::Set(this: v5, name: "lbFieldA", value: v11);
        idSWFScriptVar::Free(this: &v63);
        *(_QWORD *)((char *)&v12 + 4) = LeaderboardRow->columns.ptr[1];
        LODWORD(v12) = this->lbCache->def;
        v13 = FormatColumn(result: &v62, columnDef: (const columnDef_t *)(*(_DWORD *)(v12 + 8) + 16), score: v12);
        idSWFScriptObject::Set(this: v5, name: "lbFieldB", value: v13);
        idSWFScriptVar::Free(this: &v62);
        v42.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v42);
        v42.type = SWF_VAR_BOOL;
        v42.value.b = true;
        idSWFScriptObject::Set(this: v5, name: "loaded", value: &v42);
        idSWFScriptVar::Free(this: &v42);
        v3 = v57;
      }
      else
      {
        idSWFScriptVar::idSWFScriptVar(this: &v58, s: v3);
        idSWFScriptObject::Set(this: v5, name: "name", value: &v58);
        idSWFScriptVar::Free(this: &v58);
        v55.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v55);
        v55.value.i = v7 + 1;
        v55.type = SWF_VAR_INTEGER;
        idSWFScriptObject::Set(this: v5, name: "rank", value: &v55);
        idSWFScriptVar::Free(this: &v55);
        idSWFScriptVar::idSWFScriptVar(this: &v60, s: v3);
        idSWFScriptObject::Set(this: v5, name: "lbFieldA", value: &v60);
        idSWFScriptVar::Free(this: &v60);
        idSWFScriptVar::idSWFScriptVar(this: &v59, s: v3);
        idSWFScriptObject::Set(this: v5, name: "lbFieldB", value: &v59);
        idSWFScriptVar::Free(this: &v59);
        v44.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v44);
        v44.type = SWF_VAR_BOOL;
        v44.value.b = false;
        idSWFScriptObject::Set(this: v5, name: "loaded", value: &v44);
        idSWFScriptVar::Free(this: &v44);
      }
      localIndex = this->lbCache->localIndex;
      v51.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v51);
      v51.type = SWF_VAR_BOOL;
      v51.value.b = (_cntlzw(localIndex - v7) & 0x20) != 0;
      idSWFScriptObject::Set(this: v5, name: "localUser", value: &v51);
      idSWFScriptVar::Free(this: &v51);
      if ( v7 >= numRowsInLeaderboard )
      {
        v54.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v54);
        v54.type = SWF_VAR_BOOL;
        v54.value.b = false;
        idSWFScriptObject::Set(this: v5, name: "visible", value: &v54);
        v15 = &v54;
      }
      else
      {
        v46.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v46);
        v46.type = SWF_VAR_BOOL;
        v46.value.b = true;
        idSWFScriptObject::Set(this: v5, name: "visible", value: &v46);
        v15 = &v46;
      }
      idSWFScriptVar::Free(this: v15);
      v16 = v33;
      if ( this->lbCache->entryIndex == v33 )
      {
        v48.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v48);
        v48.type = SWF_VAR_BOOL;
        v48.value.b = true;
        idSWFScriptObject::Set(this: v5, name: "active", value: &v48);
        v17 = &v48;
      }
      else
      {
        v37.type = SWF_VAR_UNDEF;
        idSWFScriptVar::Free(this: &v37);
        v37.type = SWF_VAR_BOOL;
        v37.value.b = false;
        idSWFScriptObject::Set(this: v5, name: "active", value: &v37);
        v17 = &v37;
      }
      idSWFScriptVar::Free(this: v17);
      v36.type = SWF_VAR_UNDEF;
      idSWFScriptVar::Free(this: &v36);
      if ( v5 != nullptr )
      {
        v36.value.i = (int)v5;
        v36.type = SWF_VAR_OBJECT;
        ++v5->refCount;
      }
      else
      {
        v36.type = SWF_VAR_NULL;
      }
      idSWFScriptObject::Set(this: v2, index: v33, value: &v36);
      idSWFScriptVar::Free(this: &v36);
      if ( v5->refCount-- == 1 )
      {
        idSWFScriptObject::~idSWFScriptObject(this: v5);
        idMem::Free(this: v56, ptr: v5, align: ALIGN_16);
      }
      ++v33;
    }
    while ( v16 + 1 < 12 );
    rowOffset = this->lbCache->rowOffset;
    if ( rowOffset != 0 )
      v32 = true;
    HIDWORD(v19) = (unsigned int)(rowOffset + 12) >> 31;
    LODWORD(v19) = numRowsInLeaderboard;
    v31 = ((__PAIR64__((unsigned int)numRowsInLeaderboard >> 31, rowOffset + 12) - v19) >> 32) & 1;
  }
  if ( this->vdmLeaderboard )
  {
    index = this->roadRageLeaderboards.list[this->vdmLBIndex].name.index;
    v50.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v50);
    v50.value.i = index;
    v50.type = SWF_VAR_STRINGID;
    idSWFScriptObject::Set(this: v2, name: "name", value: &v50);
    idSWFScriptVar::Free(this: &v50);
    v21 = this->vdmLBIndex - 1;
    if ( v21 < 0 )
      v21 = this->roadRageLeaderboards.num - 1;
    v22 = this->roadRageLeaderboards.list[v21].name.index;
    v53.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v53);
    v53.value.i = v22;
    v53.type = SWF_VAR_STRINGID;
    idSWFScriptObject::Set(this: v2, name: "prevName", value: &v53);
    idSWFScriptVar::Free(this: &v53);
    v23 = this->roadRageLeaderboards.list[__CFADD__(
                                            this->roadRageLeaderboards.num - 1 - (this->vdmLBIndex + 1),
                                            (this->vdmLBIndex + 1) ^ 0x80000000)
                                        ? 0
                                        : this->vdmLBIndex + 1].name.index;
    v38.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v38);
    v38.value.i = v23;
    v38.type = SWF_VAR_STRINGID;
    idSWFScriptObject::Set(this: v2, name: "nextName", value: &v38);
    v24 = &v38;
  }
  else
  {
    v25 = this->coopLeaderboards.list[this->coopLBIndex].name.index;
    v39.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v39);
    v39.value.i = v25;
    v39.type = SWF_VAR_STRINGID;
    idSWFScriptObject::Set(this: v2, name: "name", value: &v39);
    idSWFScriptVar::Free(this: &v39);
    v26 = this->coopLBIndex - 1;
    if ( v26 < 0 )
      v26 = this->coopLeaderboards.num - 1;
    v27 = this->coopLeaderboards.list[v26].name.index;
    v41.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v41);
    v41.value.i = v27;
    v41.type = SWF_VAR_STRINGID;
    idSWFScriptObject::Set(this: v2, name: "prevName", value: &v41);
    idSWFScriptVar::Free(this: &v41);
    v28 = this->coopLeaderboards.list[__CFADD__(
                                        this->coopLeaderboards.num - 1 - (this->coopLBIndex + 1),
                                        (this->coopLBIndex + 1) ^ 0x80000000)
                                    ? 0
                                    : this->coopLBIndex + 1].name.index;
    v43.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v43);
    v43.value.i = v28;
    v43.type = SWF_VAR_STRINGID;
    idSWFScriptObject::Set(this: v2, name: "nextName", value: &v43);
    v24 = &v43;
  }
  idSWFScriptVar::Free(this: v24);
  v45.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v45);
  v45.type = SWF_VAR_BOOL;
  v45.value.b = v32;
  idSWFScriptObject::Set(this: v2, name: "isTop", value: &v45);
  idSWFScriptVar::Free(this: &v45);
  v47.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v47);
  v47.type = SWF_VAR_BOOL;
  v47.value.b = v31;
  idSWFScriptObject::Set(this: v2, name: "isBottom", value: &v47);
  idSWFScriptVar::Free(this: &v47);
  v49.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v49);
  v49.type = SWF_VAR_INTEGER;
  v49.value.i = numRowsInLeaderboard;
  idSWFScriptObject::Set(this: v2, name: "totalRows", value: &v49);
  idSWFScriptVar::Free(this: &v49);
  v61[0] = v3;
  v61[2] = v3;
  v61[1] = "#str_online_leaderboards_error_failed";
  v61[3] = "#str_online_leaderboards_error_not_ranked";
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v64[0].rowBlocks[1].rows);
  FilterStrType = idLBCache::GetFilterStrType(this: v64, result: (idStr *)this->lbCache);
  idSWFParmList::Append(this: (idSWFParmList *)&v64[0].rowBlocks[1].rows, s: (const idStr *)FilterStrType);
  idStr::FreeData(this: (idStr *)v64);
  idSWFParmList::Append(this: (idSWFParmList *)&v64[0].rowBlocks[1].rows, o: v2);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v64[0].rowBlocks[1].rows,
    i: (idSWFScriptVar::swfScriptVarValue_t *)this->lbCache->numRowsInLeaderboard);
  idSWFParmList::Append(this: (idSWFParmList *)&v64[0].rowBlocks[1].rows, b: this->lbCache->loadingNewLeaderboard);
  idSWFParmList::Append(
    this: (idSWFParmList *)&v64[0].rowBlocks[1].rows,
    s: (const char *)v61[this->lbCache->errorCode]);
  idSWF::Invoke(
    this: this->mainMenu,
    functionName: "UpdateLeaderboard",
    parms: (const idSWFParmList *)&v64[0].rowBlocks[1].rows);
  if ( v2->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: v2);
    idMem::Free(this: v56, ptr: v2, align: ALIGN_16);
  }
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: (idStaticList<idSWFScriptVar,16> *)&v64[0].rowBlocks[1].rows);
}


// ========================================================================
// __unwind$520256
// EA  : 0x82DD1E18
// RVA : 0x00DD1E18
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520256()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 128));
}


// ========================================================================
// __unwind$520257
// EA  : 0x82DD1E40
// RVA : 0x00DD1E40
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520257()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 224));
}


// ========================================================================
// __unwind$520258
// EA  : 0x82DD1E68
// RVA : 0x00DD1E68
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520258()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 312));
}


// ========================================================================
// __unwind$520259
// EA  : 0x82DD1E90
// RVA : 0x00DD1E90
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520259()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 304));
}


// ========================================================================
// __unwind$520260
// EA  : 0x82DD1EB8
// RVA : 0x00DD1EB8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520260()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 144));
}


// ========================================================================
// __unwind$520261
// EA  : 0x82DD1EE0
// RVA : 0x00DD1EE0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520261()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 264));
}


// ========================================================================
// __unwind$520262
// EA  : 0x82DD1F08
// RVA : 0x00DD1F08
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520262()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 248));
}


// ========================================================================
// __unwind$520263
// EA  : 0x82DD1F30
// RVA : 0x00DD1F30
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520263()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 280));
}


// ========================================================================
// __unwind$520264
// EA  : 0x82DD1F58
// RVA : 0x00DD1F58
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520264()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 272));
}


// ========================================================================
// __unwind$520265
// EA  : 0x82DD1F80
// RVA : 0x00DD1F80
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520265()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 160));
}


// ========================================================================
// __unwind$520266
// EA  : 0x82DD1FA8
// RVA : 0x00DD1FA8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520266()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 216));
}


// ========================================================================
// __unwind$520267
// EA  : 0x82DD1FD0
// RVA : 0x00DD1FD0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520267()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 176));
}


// ========================================================================
// __unwind$520268
// EA  : 0x82DD1FF8
// RVA : 0x00DD1FF8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520268()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 240));
}


// ========================================================================
// __unwind$520269
// EA  : 0x82DD2020
// RVA : 0x00DD2020
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520269()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 192));
}


// ========================================================================
// __unwind$520270
// EA  : 0x82DD2048
// RVA : 0x00DD2048
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520270()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 104));
}


// ========================================================================
// __unwind$520271
// EA  : 0x82DD2070
// RVA : 0x00DD2070
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520271()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 96));
}


// ========================================================================
// __unwind$520272
// EA  : 0x82DD2098
// RVA : 0x00DD2098
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520272()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 208));
}


// ========================================================================
// __unwind$520273
// EA  : 0x82DD20C0
// RVA : 0x00DD20C0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520273()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 232));
}


// ========================================================================
// __unwind$520274
// EA  : 0x82DD20E8
// RVA : 0x00DD20E8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520274()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 112));
}


// ========================================================================
// __unwind$520275
// EA  : 0x82DD2110
// RVA : 0x00DD2110
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520275()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 120));
}


// ========================================================================
// __unwind$520276
// EA  : 0x82DD2138
// RVA : 0x00DD2138
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520276()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 136));
}


// ========================================================================
// __unwind$520277
// EA  : 0x82DD2160
// RVA : 0x00DD2160
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520277()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 152));
}


// ========================================================================
// __unwind$520278
// EA  : 0x82DD2188
// RVA : 0x00DD2188
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520278()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 168));
}


// ========================================================================
// __unwind$520279
// EA  : 0x82DD21B0
// RVA : 0x00DD21B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520279()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 184));
}


// ========================================================================
// __unwind$520280
// EA  : 0x82DD21D8
// RVA : 0x00DD21D8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520280()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 656 + 200));
}


// ========================================================================
// __unwind$520281
// EA  : 0x82DD2200
// RVA : 0x00DD2200
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520281()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 656 + 352));
}


// ========================================================================
// __unwind$520282
// EA  : 0x82DD2228
// RVA : 0x00DD2228
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_520282()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 320));
}


// ========================================================================
// ?OnServerListReady@idMainMenu@@QAAXXZ
// EA  : 0x82DD2258
// RVA : 0x00DD2258
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::OnServerListReady(idMainMenu *this)
{
  idStaticList<idSWFScriptVar,16> v2; // [sp+50h] [-140h] BYREF
  idStaticList<idSWFScriptVar,16> v3; // [sp+E0h] [-B0h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v3);
  idSWF::Invoke(this: this->mainMenu, functionName: "hideLoadingPacifier", parms: (const idSWFParmList *)&v3);
  idMainMenu::SetSwfLangameList(this);
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v2);
  idSWF::Invoke(this: this->mainMenu, functionName: "gameRefreshComplete", parms: (const idSWFParmList *)&v2);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v2);
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v3);
}


// ========================================================================
// __unwind$521022
// EA  : 0x82DD22DC
// RVA : 0x00DD22DC
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521022()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 400 + 224));
}


// ========================================================================
// __unwind$521023
// EA  : 0x82DD2304
// RVA : 0x00DD2304
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521023()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 400 + 80));
}


// ========================================================================
// ?ShowMatchResultsPopup@idMainMenu@@QAAXXZ
// EA  : 0x82DD2338
// RVA : 0x00DD2338
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::ShowMatchResultsPopup(idMainMenu *this)
{
  idSWFScriptObject *v2; // r30
  idSWFScriptVar v4; // [sp+50h] [-190h] BYREF
  idSWFScriptVar v5; // [sp+58h] [-188h] BYREF
  idSWFScriptVar v6; // [sp+60h] [-180h] BYREF
  idSWFScriptVar v7; // [sp+68h] [-178h] BYREF
  idSWFScriptVar v8; // [sp+70h] [-170h] BYREF
  idSWFScriptVar v9; // [sp+78h] [-168h] BYREF
  idSWFScriptVar v10; // [sp+80h] [-160h] BYREF
  idSWFScriptVar v11; // [sp+88h] [-158h] BYREF
  idSWFScriptVar v12; // [sp+90h] [-150h] BYREF
  idSWFScriptVar v13; // [sp+98h] [-148h] BYREF
  idSWFScriptVar v14; // [sp+A0h] [-140h] BYREF
  idSWFScriptVar v15; // [sp+A8h] [-138h] BYREF
  idSWFScriptVar v16; // [sp+B0h] [-130h] BYREF
  idSWFScriptVar v17; // [sp+B8h] [-128h] BYREF
  idSWFScriptVar v18; // [sp+C0h] [-120h] BYREF
  idSWFScriptVar v19; // [sp+C8h] [-118h] BYREF
  idSWFScriptVar v20; // [sp+D0h] [-110h] BYREF
  idSWFScriptVar v21; // [sp+D8h] [-108h] BYREF
  idSWFScriptVar v22; // [sp+E0h] [-100h] BYREF
  idSWFScriptVar v23; // [sp+E8h] [-F8h] BYREF
  idSWFScriptVar v24; // [sp+F0h] [-F0h] BYREF
  idSWFScriptVar v25; // [sp+F8h] [-E8h] BYREF
  idSWFScriptVar v26; // [sp+100h] [-E0h] BYREF
  idSWFScriptVar v27; // [sp+108h] [-D8h] BYREF
  idStaticList<idSWFScriptVar,16> v28; // [sp+110h] [-D0h] BYREF

  this->showingMatchResults = true;
  v2 = idSWFScriptObject::Alloc();
  v5.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v5);
  v5.value.i = 1;
  v5.type = SWF_VAR_INTEGER;
  idSWFScriptObject::Set(this: v2, name: "screenType", value: &v5);
  idSWFScriptVar::Free(this: &v5);
  v13.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v13);
  v13.type = SWF_VAR_INTEGER;
  v13.value.i = 200;
  idSWFScriptObject::Set(this: v2, name: "matchScore", value: &v13);
  idSWFScriptVar::Free(this: &v13);
  v7.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v7);
  v7.type = SWF_VAR_INTEGER;
  v7.value.i = 75;
  idSWFScriptObject::Set(this: v2, name: "awardScore", value: &v7);
  idSWFScriptVar::Free(this: &v7);
  v15.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v15);
  v15.type = SWF_VAR_INTEGER;
  v15.value.i = 275;
  idSWFScriptObject::Set(this: v2, name: "totalScore", value: &v15);
  idSWFScriptVar::Free(this: &v15);
  idSWFScriptVar::idSWFScriptVar(this: &v20, s: "Kills");
  idSWFScriptObject::Set(this: v2, name: "statTitle0", value: &v20);
  idSWFScriptVar::Free(this: &v20);
  idSWFScriptVar::idSWFScriptVar(this: &v25, s: "Deaths");
  idSWFScriptObject::Set(this: v2, name: "statTitle1", value: &v25);
  idSWFScriptVar::Free(this: &v25);
  idSWFScriptVar::idSWFScriptVar(this: &v23, s: "Special Kills");
  idSWFScriptObject::Set(this: v2, name: "statTitle2", value: &v23);
  idSWFScriptVar::Free(this: &v23);
  idSWFScriptVar::idSWFScriptVar(this: &v27, s: "Longest Life");
  idSWFScriptObject::Set(this: v2, name: "statTitle3", value: &v27);
  idSWFScriptVar::Free(this: &v27);
  idSWFScriptVar::idSWFScriptVar(this: &v21, s: "Rally Captures");
  idSWFScriptObject::Set(this: v2, name: "statTitle4", value: &v21);
  idSWFScriptVar::Free(this: &v21);
  idSWFScriptVar::idSWFScriptVar(this: &v22, s: "Longest Chain");
  idSWFScriptObject::Set(this: v2, name: "statTitle5", value: &v22);
  idSWFScriptVar::Free(this: &v22);
  idSWFScriptVar::idSWFScriptVar(this: &v24, s: "Chain Breakers");
  idSWFScriptObject::Set(this: v2, name: "statTitle6", value: &v24);
  idSWFScriptVar::Free(this: &v24);
  idSWFScriptVar::idSWFScriptVar(this: &v26, s: "Miles Driven");
  idSWFScriptObject::Set(this: v2, name: "statTitle7", value: &v26);
  idSWFScriptVar::Free(this: &v26);
  v9.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v9);
  v9.type = SWF_VAR_INTEGER;
  v9.value.i = 4;
  idSWFScriptObject::Set(this: v2, name: "statValue0", value: &v9);
  idSWFScriptVar::Free(this: &v9);
  v17.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v17);
  v17.type = SWF_VAR_INTEGER;
  v17.value.i = 2;
  idSWFScriptObject::Set(this: v2, name: "statValue1", value: &v17);
  idSWFScriptVar::Free(this: &v17);
  v11.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v11);
  v11.type = SWF_VAR_INTEGER;
  v11.value.i = 1;
  idSWFScriptObject::Set(this: v2, name: "statValue2", value: &v11);
  idSWFScriptVar::Free(this: &v11);
  v19.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v19);
  v19.type = SWF_VAR_INTEGER;
  v19.value.i = 35;
  idSWFScriptObject::Set(this: v2, name: "statValue3", value: &v19);
  idSWFScriptVar::Free(this: &v19);
  v16.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v16);
  v16.type = SWF_VAR_INTEGER;
  v16.value.i = 4;
  idSWFScriptObject::Set(this: v2, name: "statValue4", value: &v16);
  idSWFScriptVar::Free(this: &v16);
  v14.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v14);
  v14.type = SWF_VAR_INTEGER;
  v14.value.i = 2;
  idSWFScriptObject::Set(this: v2, name: "statValue5", value: &v14);
  idSWFScriptVar::Free(this: &v14);
  v18.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v18);
  v18.type = SWF_VAR_INTEGER;
  v18.value.i = 3;
  idSWFScriptObject::Set(this: v2, name: "statValue6", value: &v18);
  idSWFScriptVar::Free(this: &v18);
  v12.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v12);
  v12.type = SWF_VAR_INTEGER;
  v12.value.i = 23;
  idSWFScriptObject::Set(this: v2, name: "statValue7", value: &v12);
  idSWFScriptVar::Free(this: &v12);
  v4.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v4);
  v4.type = SWF_VAR_INTEGER;
  v4.value.i = 50;
  idSWFScriptObject::Set(this: v2, name: "expPCT", value: &v4);
  idSWFScriptVar::Free(this: &v4);
  v6.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v6);
  v6.type = SWF_VAR_INTEGER;
  v6.value.i = 12;
  idSWFScriptObject::Set(this: v2, name: "nextRank", value: &v6);
  idSWFScriptVar::Free(this: &v6);
  v8.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v8);
  v8.type = SWF_VAR_INTEGER;
  v8.value.i = 11;
  idSWFScriptObject::Set(this: v2, name: "currentRank", value: &v8);
  idSWFScriptVar::Free(this: &v8);
  v10.type = SWF_VAR_UNDEF;
  idSWFScriptVar::Free(this: &v10);
  v10.type = SWF_VAR_INTEGER;
  v10.value.i = 2;
  idSWFScriptObject::Set(this: v2, name: "totalUnlocks", value: &v10);
  idSWFScriptVar::Free(this: &v10);
  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v28);
  if ( v28.listStatic == 0 || v28.listStatic == 2 )
  {
    if ( v28.list != nullptr )
      idListArrayDelete<idSWFScriptVar>(ptr: v28.list, num: v28.size);
    v28.list = nullptr;
    v28.size = 0;
  }
  v28.num = 0;
  idSWFParmList::Append(this: (idSWFParmList *)&v28, o: v2);
  idSWF::Invoke(this: this->mainMenu, functionName: "gotoAwardMenu", parms: (const idSWFParmList *)&v28);
  if ( v2->refCount-- == 1 )
  {
    idSWFScriptObject::~idSWFScriptObject(this: v2);
    idMem::Free(this: &mem, ptr: v2, align: ALIGN_16);
  }
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v28);
}


// ========================================================================
// __unwind$521837
// EA  : 0x82DD2888
// RVA : 0x00DD2888
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521837()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 88));
}


// ========================================================================
// __unwind$521838
// EA  : 0x82DD28B0
// RVA : 0x00DD28B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521838()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 152));
}


// ========================================================================
// __unwind$521839
// EA  : 0x82DD28D8
// RVA : 0x00DD28D8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521839()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 104));
}


// ========================================================================
// __unwind$521840
// EA  : 0x82DD2900
// RVA : 0x00DD2900
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521840()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 168));
}


// ========================================================================
// __unwind$521841
// EA  : 0x82DD2928
// RVA : 0x00DD2928
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521841()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 208));
}


// ========================================================================
// __unwind$521842
// EA  : 0x82DD2950
// RVA : 0x00DD2950
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521842()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 248));
}


// ========================================================================
// __unwind$521843_0
// EA  : 0x82DD2978
// RVA : 0x00DD2978
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521843_0()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 232));
}


// ========================================================================
// __unwind$521844
// EA  : 0x82DD29A0
// RVA : 0x00DD29A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521844()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 264));
}


// ========================================================================
// __unwind$521845
// EA  : 0x82DD29C8
// RVA : 0x00DD29C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521845()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 216));
}


// ========================================================================
// __unwind$521846
// EA  : 0x82DD29F0
// RVA : 0x00DD29F0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521846()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 224));
}


// ========================================================================
// __unwind$521847
// EA  : 0x82DD2A18
// RVA : 0x00DD2A18
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521847()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 240));
}


// ========================================================================
// __unwind$521848
// EA  : 0x82DD2A40
// RVA : 0x00DD2A40
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521848()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 256));
}


// ========================================================================
// __unwind$521849
// EA  : 0x82DD2A68
// RVA : 0x00DD2A68
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521849()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 120));
}


// ========================================================================
// __unwind$521850
// EA  : 0x82DD2A90
// RVA : 0x00DD2A90
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521850()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 184));
}


// ========================================================================
// __unwind$521851
// EA  : 0x82DD2AB8
// RVA : 0x00DD2AB8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521851()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 136));
}


// ========================================================================
// __unwind$521852
// EA  : 0x82DD2AE0
// RVA : 0x00DD2AE0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521852()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 200));
}


// ========================================================================
// __unwind$521853
// EA  : 0x82DD2B08
// RVA : 0x00DD2B08
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521853()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 176));
}


// ========================================================================
// __unwind$521854
// EA  : 0x82DD2B30
// RVA : 0x00DD2B30
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521854()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 160));
}


// ========================================================================
// __unwind$521855
// EA  : 0x82DD2B58
// RVA : 0x00DD2B58
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521855()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 192));
}


// ========================================================================
// __unwind$521856
// EA  : 0x82DD2B80
// RVA : 0x00DD2B80
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521856()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 144));
}


// ========================================================================
// __unwind$521857
// EA  : 0x82DD2BA8
// RVA : 0x00DD2BA8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521857()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 80));
}


// ========================================================================
// __unwind$521858
// EA  : 0x82DD2BD0
// RVA : 0x00DD2BD0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521858()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 96));
}


// ========================================================================
// __unwind$521859
// EA  : 0x82DD2BF8
// RVA : 0x00DD2BF8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521859()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 112));
}


// ========================================================================
// __unwind$521860
// EA  : 0x82DD2C20
// RVA : 0x00DD2C20
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521860()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 480 + 128));
}


// ========================================================================
// __unwind$521861
// EA  : 0x82DD2C48
// RVA : 0x00DD2C48
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_521861()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 480 + 272));
}


// ========================================================================
// ?Call@idSWFScriptFunction_getMapList@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DD2CF8
// RVA : 0x00DD2CF8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_getMapList *__fastcall idMainMenu::idSWFScriptFunction_getMapList::Call(
        idMainMenu::idSWFScriptFunction_getMapList *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::idSWFScriptFunction_getMapList *v4; // r14
  idSWFScriptVar::swfScriptVarType type; // r11
  char v7; // r11
  bool v8; // zf
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  idStr *v12; // r3
  int v13; // r17
  idSWFScriptObject *v14; // r25
  int v15; // r26
  idSWFScriptVar::swfScriptVarValue_t v16; // r24
  idList<mpMap_t,57> *v17; // r11
  int v18; // r28
  idSWFScriptObject *v19; // r30
  int index; // r14
  idSWFScriptVar *v21; // r3
  idSWFScriptVar v25; // [sp+50h] [-BD0h] BYREF
  idSWFScriptVar v26; // [sp+58h] [-BC8h] BYREF
  idSWFScriptVar v27; // [sp+60h] [-BC0h] BYREF
  idSWFScriptVar v28; // [sp+68h] [-BB8h] BYREF
  idSWFScriptVar v29; // [sp+70h] [-BB0h] BYREF
  int v30; // [sp+78h] [-BA8h]
  idSWFScriptVar v31[2]; // [sp+80h] [-BA0h] BYREF
  idStr v32; // [sp+90h] [-B90h] BYREF
  idStr v33; // [sp+B0h] [-B70h] BYREF
  idSWFScriptVar v34; // [sp+D0h] [-B50h] BYREF
  mpMap_t v35; // [sp+F0h] [-B30h] BYREF

  v4 = this;
  v30 = 0;
  if ( parms->num != 1 )
    goto LABEL_22;
  type = parms->list->type;
  if ( type == SWF_VAR_STRING || (v8 = type != SWF_VAR_STRINGID, v7 = 0, !v8) )
    v7 = 1;
  if ( v7 != 0 )
  {
    idStr::idStr(this: &v33, text: &byte_8200D768);
    v12 = (idStr *)idSWFScriptVar::ToString(this: &v34, result: (idStr *)parms->list, a3: v11, a4: v10, a5: v9);
    v13 = idMainMenu::LookupGameType(strGameType: v12);
    v14 = idSWFScriptObject::Alloc();
    idSWFScriptObject::MakeArray(this: v14);
    v15 = 0;
    v16.i = 0;
    v17 = idMainMenu::pMPMaps;
    if ( idMainMenu::pMPMaps->num > 0 )
    {
      v18 = 0;
      do
      {
        if ( v17->list[v18].type == v13 )
        {
          v19 = idSWFScriptObject::Alloc();
          index = idMainMenu::pMPMaps->list[v18].name.index;
          v29.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v29);
          v29.value.i = index;
          v29.type = SWF_VAR_STRINGID;
          idSWFScriptObject::Set(this: v19, name: "name", value: &v29);
          idSWFScriptVar::Free(this: &v29);
          mpMap_t::mpMap_t(this: &v35, __that: &idMainMenu::pMPMaps->list[v18]);
          if ( v35.map.len != 0 )
          {
            v27.type = SWF_VAR_UNDEF;
            idSWFScriptVar::Free(this: &v27);
            v27.type = SWF_VAR_STRING;
            v27.value.i = (int)idSWFScriptString::Alloc(s: &v35.material);
            idSWFScriptObject::Set(this: v19, name: "img", value: &v27);
            v21 = &v27;
          }
          else
          {
            v28.type = SWF_VAR_UNDEF;
            idSWFScriptVar::Free(this: &v28);
            v28.type = SWF_VAR_STRING;
            v28.value.i = (int)idSWFScriptString::Alloc(s: &v35.material);
            idSWFScriptObject::Set(this: v19, name: &byte_8200D768, value: &v28);
            v21 = &v28;
          }
          idSWFScriptVar::Free(this: v21);
          v26.type = SWF_VAR_UNDEF;
          idSWFScriptVar::Free(this: &v26);
          v26.value = v16;
          v26.type = SWF_VAR_INTEGER;
          idSWFScriptObject::Set(this: v19, name: "index", value: &v26);
          idSWFScriptVar::Free(this: &v26);
          idSWFScriptVar::idSWFScriptVar(this: v31, o: v19);
          idSWFScriptObject::Set(this: v14, index: v15++, value: v31);
          idSWFScriptVar::Free(this: v31);
          if ( v19->refCount-- == 1 )
          {
            idSWFScriptObject::~idSWFScriptObject(this: v19);
            idMem::Free(this: &mem, ptr: v19, align: ALIGN_16);
          }
          mpMap_t::~mpMap_t(this: &v35);
          v17 = idMainMenu::pMPMaps;
          v4 = this;
        }
        ++v16.i;
        ++v18;
      }
      while ( v16.i < v17->num );
    }
    v25.type = SWF_VAR_UNDEF;
    idSWFScriptVar::Free(this: &v25);
    if ( v14 != nullptr )
    {
      v25.value.i = (int)v14;
      v25.type = SWF_VAR_OBJECT;
      ++v14->refCount;
    }
    else
    {
      v25.type = SWF_VAR_NULL;
    }
    idStr::idStr(this: &v32, text: "mapList");
    idMainMenu::SetMainMenuGlobal(this: gameLocal->mainMenu, name: &v32, value: &v25);
    idStr::FreeData(this: &v32);
    idSWFScriptVar::Free(this: &v25);
    if ( v14->refCount-- == 1 )
    {
      idSWFScriptObject::~idSWFScriptObject(this: v14);
      idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
    }
    v4->__vftable = (idMainMenu::idSWFScriptFunction_getMapList_vtbl *)4;
    v30 = 1;
    idStr::FreeData(this: &v33);
    return v4;
  }
  else
  {
LABEL_22:
    idLib::Warning(fmt: "Invalid number of parameters to getMapList().  Usage: getMapList(\"gametype\")");
    v4->__vftable = (idMainMenu::idSWFScriptFunction_getMapList_vtbl *)4;
    return v4;
  }
}


// ========================================================================
// __unwind$522469
// EA  : 0x82DD3028
// RVA : 0x00DD3028
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522469()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 3104 + 176));
}


// ========================================================================
// __unwind$522471
// EA  : 0x82DD3050
// RVA : 0x00DD3050
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522471()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3104 + 112));
}


// ========================================================================
// __unwind$522472
// EA  : 0x82DD3078
// RVA : 0x00DD3078
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522472()
{
  int v0; // r12

  mpMap_t::~mpMap_t(this: (mpMap_t *)(v0 - 3104 + 240));
}


// ========================================================================
// __unwind$522473
// EA  : 0x82DD30A0
// RVA : 0x00DD30A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522473()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3104 + 96));
}


// ========================================================================
// __unwind$522474
// EA  : 0x82DD30C8
// RVA : 0x00DD30C8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522474()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3104 + 104));
}


// ========================================================================
// __unwind$522475
// EA  : 0x82DD30F0
// RVA : 0x00DD30F0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522475()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3104 + 88));
}


// ========================================================================
// __unwind$522476
// EA  : 0x82DD3118
// RVA : 0x00DD3118
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522476()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3104 + 128));
}


// ========================================================================
// __unwind$522477
// EA  : 0x82DD3140
// RVA : 0x00DD3140
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522477()
{
  int v0; // r12

  idSWFScriptVar::~idSWFScriptVar(this: (idSWFScriptVar *)(v0 - 3104 + 80));
}


// ========================================================================
// __unwind$522478
// EA  : 0x82DD3168
// RVA : 0x00DD3168
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522478()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 3104 + 144));
}


// ========================================================================
// __unwind$522466
// EA  : 0x82DD3190
// RVA : 0x00DD3190
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522466()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 3104;
  if ( (*(_DWORD *)(v0 - 3104 + 120) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 120) &= ~1u;
    idSWFScriptVar::~idSWFScriptVar(this: *(idSWFScriptVar **)(v1 + 3124));
  }
}


// ========================================================================
// ?Call@idSWFScriptFunction_showMatchResultsPopup@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DD31D8
// RVA : 0x00DD31D8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_showMatchResultsPopup *__fastcall idMainMenu::idSWFScriptFunction_showMatchResultsPopup::Call(
        idMainMenu::idSWFScriptFunction_showMatchResultsPopup *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu *i; // r3

  if ( parms->num != 0 )
  {
    idLib::Warning(fmt: "Invalid parameters specified for showMatchResultsPopup", result, thisObject);
    this->__vftable = (idMainMenu::idSWFScriptFunction_showMatchResultsPopup_vtbl *)4;
  }
  else
  {
    i = (idMainMenu *)result->value.i;
    if ( i->showingMatchResults )
      idLib::Warning(fmt: "Already showing match results!");
    else
      idMainMenu::ShowMatchResultsPopup(this: i);
    this->__vftable = (idMainMenu::idSWFScriptFunction_showMatchResultsPopup_vtbl *)4;
  }
  return this;
}


// ========================================================================
// ?UpdateLanServerList@idMainMenu@@QAAXXZ
// EA  : 0x82DD3268
// RVA : 0x00DD3268
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::UpdateLanServerList(idMainMenu *this)
{
  const char *LocalizedString; // r3
  idCallbackBindMem<idMainMenu> *v3; // r3
  idStrId v4[2]; // [sp+50h] [-D0h] BYREF
  idCallbackBindMem<idMainMenu> v5[2]; // [sp+58h] [-C8h] BYREF
  idStaticList<idSWFScriptVar,16> v6; // [sp+70h] [-B0h] BYREF

  idStaticList<idSWFScriptVar,16>::idStaticList<idSWFScriptVar,16>(this: &v6);
  idStrId::Set(this: v4, key: "#str_online_mpstatus_searching");
  LocalizedString = idStrId::GetLocalizedString(this: v4);
  idSWFParmList::Append(this: (idSWFParmList *)&v6, s: LocalizedString);
  idSWF::Invoke(this: this->mainMenu, functionName: "showLoadingPacifier", parms: (const idSWFParmList *)&v6);
  v3 = MakeCallback<idMainMenu>(result: v5, t: this, f: idMainMenu::OnServerListReady);
  session->ListServers(this: session, a2: v3);
  v5[0].__vftable = (idCallbackBindMem<idMainMenu>_vtbl *)&idCallback::`vftable';
  idStaticList<idSWFScriptVar,16>::~idStaticList<idSWFScriptVar,16>(this: &v6);
}


// ========================================================================
// __unwind$522784
// EA  : 0x82DD3320
// RVA : 0x00DD3320
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522784()
{
  int v0; // r12

  idSWFParmList::~idSWFParmList(this: (idSWFParmList *)(v0 - 288 + 112));
}


// ========================================================================
// __unwind$522785
// EA  : 0x82DD3348
// RVA : 0x00DD3348
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522785()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 288 + 88));
}


// ========================================================================
// ?Call@idSWFScriptFunction_updateLanServerList@idMainMenu@@EAA?AVidSWFScriptVar@@PAVidSWFScriptObject@@ABVidSWFParmList@@@Z
// EA  : 0x82DD36A0
// RVA : 0x00DD36A0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

idMainMenu::idSWFScriptFunction_updateLanServerList *__fastcall idMainMenu::idSWFScriptFunction_updateLanServerList::Call(
        idMainMenu::idSWFScriptFunction_updateLanServerList *this,
        idSWFScriptVar *result,
        idSWFScriptObject *thisObject,
        const idSWFParmList *parms)
{
  idMainMenu::UpdateLanServerList(this: gameLocal->mainMenu);
  this->__vftable = (idMainMenu::idSWFScriptFunction_updateLanServerList_vtbl *)4;
  return this;
}


// ========================================================================
// ?SetupMultiplayerMenu@idMainMenu@@QAAXXZ
// EA  : 0x82DD3888
// RVA : 0x00DD3888
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::SetupMultiplayerMenu(idMainMenu *this, int a2, int a3, int a4, __int64 a5)
{
  idMainMenu *v5; // r27
  idList<mpMap_t,57> *p_mpMaps; // r15
  __int64 v7; // r10
  int v8; // r20
  idResource *v9; // r30
  int num; // r11
  int size; // r10
  int v12; // r23
  int staleCount; // r11
  size_t v14; // r29
  int v15; // r8
  size_t v16; // r29
  int v17; // r11
  const char *v18; // r4
  idResource *v19; // r22
  int v20; // r21
  int v21; // r24
  int v22; // r27
  int v23; // r11
  int v24; // r10
  int v25; // r9
  int v26; // r30
  size_t v27; // r28
  unsigned int v28; // r11
  int v29; // r4
  int v30; // r11
  bool v31; // zf
  const char *v32; // r4
  char *v33; // r26
  unsigned int v34; // r11
  size_t v35; // r28
  int v36; // r4
  int v37; // r11
  mpMapMode_t *v38; // r4
  unsigned int v39; // r5
  int i; // r21
  idResource *v41; // r30
  int v42; // r11
  int v43; // r10
  int v44; // r24
  int v45; // r8
  unsigned int v46; // r11
  size_t trackedMemory; // r28
  int v48; // r4
  int v49; // r11
  const char *v50; // r4
  int v51; // r11
  idAtomicString *p_name; // r29
  int v53; // r23
  int v54; // r28
  int v55; // r11
  int v56; // r11
  int v57; // r10
  int v58; // r9
  int v59; // r30
  idOnlineChallenge *MapLayers; // r25
  int v61; // r11
  size_t index; // r26
  int v63; // r4
  _DWORD *v64; // r27
  int v65; // r9
  int v66; // r10
  encounterGroupRole_t v67; // r8
  int v68; // r11
  int v69; // r10
  int v70; // r9
  encounterGroupRole_t v71; // r7
  int v72; // r11
  int v73; // r11
  int v74; // r11
  mpMap_t *list; // r4
  unsigned int v76; // r5
  idPlayerProfile *v77; // r4
  int v78; // r4
  idSort_Quick<mpMapMode_t,idSort_Modes_ByMenuIndex> v79; // [sp+58h] [-D8h] BYREF
  idSort_Quick<mpMap_t,idSort_MpMapsRef_ByMenuIndex> v80; // [sp+5Ch] [-D4h] BYREF
  encounterGroupRole_t v81[4]; // [sp+60h] [-D0h] BYREF
  idOnlineChallenge v82[2]; // [sp+70h] [-C0h] BYREF

  v5 = this;
  p_mpMaps = &this->mpMaps;
  if ( this->mpMaps.listStatic == 0 || this->mpMaps.listStatic == 2 )
  {
    if ( p_mpMaps->list != nullptr )
      idListArrayDelete<mpMap_t>(ptr: this->mpMaps.list, num: this->mpMaps.size);
    p_mpMaps->list = nullptr;
    p_mpMaps->size = 0;
  }
  p_mpMaps->num = 0;
  LODWORD(v7) = 0x82000000;
  HIDWORD(v7) = "amount <= GetAlloced()";
  LODWORD(a5) = &byte_8200D768;
  v8 = 0;
  if ( idDeclPvPMap::resourceList.num > 0 )
  {
    do
    {
      v9 = idResourceList::Index(this: &idDeclPvPMap::resourceList, index: v8);
      if ( v9 != nullptr )
      {
        idList<mpMap_t,57>::PreAllocateWithGranularity(this: p_mpMaps, newSize: p_mpMaps->num + 1);
        num = p_mpMaps->num;
        size = p_mpMaps->size;
        if ( num >= size )
        {
          v12 = (int)&p_mpMaps->list[size - 1];
        }
        else
        {
          v12 = (int)&p_mpMaps->list[num];
          p_mpMaps->num = num + 1;
        }
        staleCount = v9[1].staleCount;
        v81[0] = (encounterGroupRole_t)((char *)&v9[2] + 32);
        *(_DWORD *)v12 = staleCount;
        v14 = *((_DWORD *)&v9[2] + 8);
        idStr::EnsureAlloced(this: (idStr *)(v12 + 36), amount: v14 + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: *(void **)(v12 + 40), Src: v9[3].__vftable, Size: v14);
        v15 = *(_DWORD *)(v12 + 40);
        v81[0] = (encounterGroupRole_t)&v9[2];
        *(_BYTE *)(v14 + v15) = 0;
        *(_DWORD *)(v12 + 36) = v14;
        *(_DWORD *)(v12 + 68) = *((_DWORD *)&v9[1] + 8);
        v16 = (size_t)v9[2].__vftable;
        idStr::EnsureAlloced(this: (idStr *)(v12 + 4), amount: v16 + 1, keepold: false, geometricGrowth: false);
        memcpy(Dst: *(void **)(v12 + 8), Src: (const void *)v9[2].trackedMemory, Size: v16);
        *(_BYTE *)(*(_DWORD *)(v12 + 8) + v16) = 0;
        *(_DWORD *)(v12 + 4) = v16;
        *(_DWORD *)(v12 + 108) = v9[4].resourceError;
        *(_DWORD *)(v12 + 116) = v9[3].staleCount;
        v17 = *((_DWORD *)&v9[3] + 8);
        v18 = &byte_8200D768;
        if ( v17 != 0 )
          v18 = *(const char **)(v17 + 8);
        idStr::operator=(this: (idStr *)(v12 + 76), text: v18);
        v19 = v9 + 4;
        v20 = 0;
        *(_DWORD *)(v12 + 120) = v9[4].resourceListPtr;
        LODWORD(v7) = v9[4].trackedMemory;
        if ( (int)v7 > 0 )
        {
          v21 = 0;
          do
          {
            v22 = *(int *)((char *)&v19->dtr_idResource + v21);
            idList<mpMapMode_t,5>::PreAllocateWithGranularity(
              this: (idList<mpMapMode_t,5> *)(v12 + 132),
              newSize: *(_DWORD *)(v12 + 136) + 1);
            v23 = *(_DWORD *)(v12 + 136);
            v24 = *(_DWORD *)(v12 + 140);
            v25 = *(_DWORD *)(v12 + 132);
            if ( v23 >= v24 )
            {
              v26 = 160 * v24 + v25 - 160;
            }
            else
            {
              *(_DWORD *)(v12 + 136) = v23 + 1;
              v26 = 160 * v23 + v25;
            }
            *(_DWORD *)(v26 + 72) = *(_DWORD *)(v22 + 188);
            *(_DWORD *)v26 = *(_DWORD *)(v22 + 116);
            v27 = *(_DWORD *)(v22 + 124);
            v28 = *(_DWORD *)(v26 + 84);
            v29 = v27 + 1;
            v31 = v28 >> 31 == 0;
            v30 = v28 & 0x7FFFFFFF;
            if ( v31 )
            {
              if ( v29 > v30 )
                idStr::ReAllocate(this: (idStr *)(v26 + 76), amount: v29, keepold: false);
            }
            else if ( v29 > v30
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: "amount <= GetAlloced()",
                        inlineBreak: true) )
            {
              __trap();
            }
            memcpy(Dst: *(void **)(v26 + 80), Src: *(const void **)(v22 + 128), Size: v27);
            *(_BYTE *)(v27 + *(_DWORD *)(v26 + 80)) = 0;
            *(_DWORD *)(v26 + 76) = v27;
            *(_DWORD *)(v26 + 4) = *(_DWORD *)(v22 + 120);
            v81[0] = *(encounterGroupRole_t *)(v22 + 176);
            if ( v81[0] != ROLE_NONE )
              v32 = *(const char **)(v81[0] + 8);
            else
              v32 = &byte_8200D768;
            idStr::operator=(this: (idStr *)(v26 + 40), text: v32);
            *(_DWORD *)(v26 + 112) = *(_DWORD *)(v22 + 180);
            v33 = (char *)v19->__vftable + v21;
            v34 = *(_DWORD *)(v26 + 16);
            v35 = *((_DWORD *)v33 + 1);
            v36 = v35 + 1;
            v31 = v34 >> 31 == 0;
            v37 = v34 & 0x7FFFFFFF;
            if ( v31 )
            {
              if ( v36 > v37 )
                idStr::ReAllocate(this: (idStr *)(v26 + 8), amount: v36, keepold: false);
            }
            else if ( v36 > v37
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: "amount <= GetAlloced()",
                        inlineBreak: true) )
            {
              __trap();
            }
            memcpy(Dst: *(void **)(v26 + 12), Src: *((const void **)v33 + 2), Size: v35);
            ++v20;
            v21 += 36;
            *(_BYTE *)(v35 + *(_DWORD *)(v26 + 12)) = 0;
            *(_DWORD *)(v26 + 8) = v35;
            LODWORD(v7) = *(unsigned __int8 *)(v22 + 184);
            *(_BYTE *)(v26 + 156) = v7;
            HIDWORD(v7) = v19->trackedMemory;
          }
          while ( v20 < SHIDWORD(v7) );
        }
        v79.__vftable = (idSort_Quick<mpMapMode_t,idSort_Modes_ByMenuIndex>_vtbl *)&idSort_Modes_ByMenuIndex::`vftable';
        v38 = *(mpMapMode_t **)(v12 + 132);
        if ( v38 != nullptr )
        {
          v39 = *(_DWORD *)(v12 + 136);
          v81[0] = *(encounterGroupRole_t *)(v12 + 132);
          idSort_Quick<mpMapMode_t,idSort_Modes_ByMenuIndex>::Sort(
            this: &v79,
            base: v38,
            num: v39,
            a4,
            a5: SHIDWORD(a5),
            a6: a5,
            a7: v7);
        }
        v79.__vftable = (idSort_Quick<mpMapMode_t,idSort_Modes_ByMenuIndex>_vtbl *)&idSort<mpMapMode_t>::`vftable';
      }
      ++v8;
    }
    while ( v8 < idDeclPvPMap::resourceList.num );
    v5 = this;
  }
  for ( i = 0; i < idDeclCoopMap::resourceList.num; ++i )
  {
    v41 = idResourceList::Index(this: &idDeclCoopMap::resourceList, index: i);
    if ( v41 != nullptr )
    {
      idList<mpMap_t,57>::PreAllocateWithGranularity(this: p_mpMaps, newSize: p_mpMaps->num + 1);
      v42 = p_mpMaps->num;
      v43 = p_mpMaps->size;
      if ( v42 >= v43 )
      {
        v44 = (int)&p_mpMaps->list[v43 - 1];
      }
      else
      {
        v44 = (int)&p_mpMaps->list[v42];
        p_mpMaps->num = v42 + 1;
      }
      *(_DWORD *)v44 = v41[1].staleCount;
      *(_DWORD *)(v44 + 68) = *((_DWORD *)&v41[1] + 8);
      *(_DWORD *)(v44 + 72) = v41[2].__vftable;
      v45 = *((_DWORD *)&v41[3] + 8);
      *(_DWORD *)(v44 + 112) = 0x7FFFFFFF;
      *(_DWORD *)(v44 + 124) = v45;
      v46 = *(_DWORD *)(v44 + 12);
      trackedMemory = v41[2].trackedMemory;
      v48 = trackedMemory + 1;
      v31 = v46 >> 31 == 0;
      v49 = v46 & 0x7FFFFFFF;
      if ( v31 )
      {
        if ( v48 > v49 )
          idStr::ReAllocate(this: (idStr *)(v44 + 4), amount: v48, keepold: false);
      }
      else if ( v48 > v49
             && AssertFailed(
                  file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                  line: 463,
                  expression: "amount <= GetAlloced()",
                  inlineBreak: true) )
      {
        __trap();
      }
      memcpy(Dst: *(void **)(v44 + 8), Src: v41[2].name.str, Size: trackedMemory);
      v50 = &byte_8200D768;
      *(_BYTE *)(trackedMemory + *(_DWORD *)(v44 + 8)) = 0;
      *(_DWORD *)(v44 + 4) = trackedMemory;
      *(_DWORD *)(v44 + 108) = v41[4].__vftable;
      v51 = v41[3].trackedMemory;
      if ( v51 != 0 )
        v50 = *(const char **)(v51 + 8);
      idStr::operator=(this: (idStr *)(v44 + 76), text: v50);
      p_name = &v41[3].name;
      v53 = 0;
      *(_DWORD *)(v44 + 128) = v41[3].networkID;
      LODWORD(v7) = v41[3].staleCount;
      *(_DWORD *)(v44 + 120) = v7;
      HIDWORD(v7) = v41[3].nextOnHashChain;
      if ( SHIDWORD(v7) > 0 )
      {
        v54 = 0;
        do
        {
          v55 = *(_DWORD *)(v44 + 136);
          LODWORD(v7) = *(_DWORD *)(v44 + 140);
          if ( v55 < (int)v7 )
          {
            idList<mpMapMode_t,5>::PreAllocateWithGranularity(
              this: (idList<mpMapMode_t,5> *)(v44 + 132),
              newSize: v55 + 1);
            v56 = *(_DWORD *)(v44 + 136);
            v57 = *(_DWORD *)(v44 + 140);
            v58 = *(_DWORD *)(v44 + 132);
            if ( v56 >= v57 )
            {
              v59 = 160 * v57 + v58 - 160;
            }
            else
            {
              *(_DWORD *)(v44 + 136) = v56 + 1;
              v59 = 160 * v56 + v58;
            }
            *(_DWORD *)v59 = *(_DWORD *)&p_name->str[v54];
            MapLayers = idOnlineChallenge::GetMapLayers(this: v82, result: (idStr *)&p_name->str[v54]);
            v61 = *(_DWORD *)(v59 + 16);
            index = MapLayers->displayName.index;
            v63 = MapLayers->displayName.index + 1;
            if ( v61 >= 0 )
            {
              if ( v63 > (v61 & 0x7FFFFFFF) )
                idStr::ReAllocate(this: (idStr *)(v59 + 8), amount: v63, keepold: false);
            }
            else if ( v63 > (v61 & 0x7FFFFFFF)
                   && AssertFailed(
                        file: "w:\\tech5\\shared\\idlib\\text/Str.h",
                        line: 463,
                        expression: "amount <= GetAlloced()",
                        inlineBreak: true) )
            {
              __trap();
            }
            memcpy(Dst: *(void **)(v59 + 12), Src: (const void *)MapLayers->description.index, Size: index);
            *(_BYTE *)(*(_DWORD *)(v59 + 12) + index) = 0;
            *(_DWORD *)(v59 + 8) = index;
            idStr::FreeData(this: (idStr *)v82);
            v64 = (_DWORD *)(v59 + 128);
            v65 = 0;
            *(_DWORD *)(v59 + 108) = *(_DWORD *)&p_name->str[v54 + 40];
            *(_DWORD *)(v59 + 4) = *(_DWORD *)&p_name->str[v54 + 4];
            *(_DWORD *)(v59 + 124) = *(_DWORD *)&p_name->str[v54 + 44];
            *(_DWORD *)(v59 + 144) = *(_DWORD *)&p_name->str[v54 + 52];
            *(_DWORD *)(v59 + 148) = *(_DWORD *)&p_name->str[v54 + 56];
            *(_DWORD *)(v59 + 152) = *(_DWORD *)&p_name->str[v54 + 60];
            *(_DWORD *)(v59 + 116) = *(_DWORD *)&p_name->str[v54 + 64];
            *(_DWORD *)(v59 + 120) = *(_DWORD *)&p_name->str[v54 + 68];
            v66 = *(_DWORD *)(v59 + 132);
            v67 = *(_DWORD *)&p_name->str[v54 + 48];
            v81[0] = v67;
            if ( v66 <= 0 )
              goto LABEL_70;
            v68 = 0;
            while ( *(_DWORD *)(v68 + *v64) != v67 )
            {
              ++v65;
              v68 += 4;
              if ( v65 >= v66 )
                goto LABEL_70;
            }
            if ( v65 < 0 )
LABEL_70:
              idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)(v59 + 128), obj: v81);
            v69 = 0;
            v70 = *(_DWORD *)(v59 + 132);
            v71 = *(_DWORD *)&p_name->str[v54 + 64];
            v81[0] = v71;
            if ( v70 <= 0 )
              goto LABEL_77;
            v72 = 0;
            while ( *(_DWORD *)(v72 + *v64) != v71 )
            {
              ++v69;
              v72 += 4;
              if ( v69 >= v70 )
                goto LABEL_77;
            }
            if ( v69 < 0 )
LABEL_77:
              idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)(v59 + 128), obj: v81);
            LODWORD(v7) = 0;
            HIDWORD(v7) = *(_DWORD *)(v59 + 132);
            HIDWORD(a5) = *(_DWORD *)&p_name->str[v54 + 72];
            v81[0] = SHIDWORD(a5);
            if ( SHIDWORD(v7) <= 0 )
              goto LABEL_84;
            LODWORD(a5) = *v64;
            v73 = 0;
            while ( 1 )
            {
              a4 = *(_DWORD *)(v73 + a5);
              if ( a4 == HIDWORD(a5) )
                break;
              LODWORD(v7) = v7 + 1;
              v73 += 4;
              if ( (int)v7 >= SHIDWORD(v7) )
                goto LABEL_84;
            }
            if ( (int)v7 < 0 )
LABEL_84:
              idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)(v59 + 128), obj: v81);
            v74 = *(_DWORD *)(v59 + 108);
            LODWORD(v7) = *(_DWORD *)(v44 + 112);
            if ( (int)v7 < v74 )
              v74 = *(_DWORD *)(v44 + 112);
            *(_DWORD *)(v44 + 112) = v74;
          }
          ++v53;
          v54 += 76;
        }
        while ( v53 < (int)p_name[1].str );
        v5 = this;
      }
    }
  }
  v80.__vftable = (idSort_Quick<mpMap_t,idSort_MpMapsRef_ByMenuIndex>_vtbl *)&idSort_MpMapsRef_ByMenuIndex::`vftable';
  list = p_mpMaps->list;
  if ( p_mpMaps->list != nullptr )
  {
    v76 = p_mpMaps->num;
    v81[0] = (encounterGroupRole_t)p_mpMaps->list;
    idSort_Quick<mpMap_t,idSort_MpMapsRef_ByMenuIndex>::Sort(this: &v80, base: list, num: v76, a4, a5, a6: v7);
  }
  v80.__vftable = (idSort_Quick<mpMap_t,idSort_MpMapsRef_ByMenuIndex>_vtbl *)&idSort<mpMap_t>::`vftable';
  v77 = common->GetProfileFromMasterLocalUser(this: common);
  if ( v77 != nullptr )
  {
    idMainMenu::EnsureValidIndexes(this: v5, profile_: v77);
    v5->coopInviteOnly = *(_BYTE *)(v78 + 3588);
  }
}


// ========================================================================
// __unwind$522993
// EA  : 0x82DD4138
// RVA : 0x00DD4138
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522993()
{
  int v0; // r12

  idSort_Modes_ByMenuIndex::~idSort_Modes_ByMenuIndex(this: (idSort_Modes_ByMenuIndex *)(v0 - 304 + 88));
}


// ========================================================================
// __unwind$522994
// EA  : 0x82DD4160
// RVA : 0x00DD4160
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522994()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$522995
// EA  : 0x82DD4188
// RVA : 0x00DD4188
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_522995()
{
  int v0; // r12

  idSort_MpMapsRef_ByMenuIndex::~idSort_MpMapsRef_ByMenuIndex(this: (idSort_MpMapsRef_ByMenuIndex *)(v0 - 304 + 92));
}


// ========================================================================
// ?MultiplayerMenu@idMainMenu@@QAAXXZ
// EA  : 0x82DD41B0
// RVA : 0x00DD41B0
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::MultiplayerMenu(idMainMenu *this, int a2, int a3, int a4, __int64 a5)
{
  int v6; // r7
  unsigned __int64 v7; // r6

  idMainMenu::SetupMultiplayerMenu(this, a2, a3, a4, a5);
  idMainMenu::Load(this, filename: "multiplayer", a3: v7, a4: v6);
  idMainMenu::Show(this, show: true);
}


// ========================================================================
// ?EnsureHeadlessServer@idMainMenu@@QAAXXZ
// EA  : 0x82DD4200
// RVA : 0x00DD4200
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __fastcall idMainMenu::EnsureHeadlessServer(idMainMenu *this)
{
  __int64 v2; // r8
  int v3; // r6
  int v4; // r5
  int v5; // r4
  idStrStatic<128> v6; // [sp+50h] [-1B40h] BYREF
  idMatchParameters v7; // [sp+F0h] [-1AA0h] BYREF
  idStrStatic<2048> v8; // [sp+1340h] [-850h] BYREF

  if ( net_headlessServer.valueInteger != 0 && session->GetState(this: session) < GAME_LOBBY )
  {
    idCVar::SetBool(this: &com_multiplayer, newValue: true, force: true);
    this->menuRequest = MENU_SWITCH_MP;
    idMainMenu::SetupMultiplayerMenu(this, a2: v5, a3: v4, a4: v3, a5: v2);
    idMatchParameters::idMatchParameters(this: &v7);
    v7.matchFlags = -118;
    v7.gameType = 2;
    idStrStatic<128>::idStrStatic<128>(this: &v6, text: "game/online/mp_furnace/mp_furnace");
    v7.mapName.len = v6.len;
    memcpy(Dst: v7.mapName.data, Src: v6.data, Size: v6.len + 1);
    idStr::FreeData(this: &v6);
    idStrStatic<2048>::idStrStatic<2048>(this: &v8, text: "mp/dm");
    v7.layersActive.len = v8.len;
    memcpy(Dst: v7.layersActive.data, Src: v8.data, Size: v8.len + 1);
    idStr::FreeData(this: &v8);
    v7.comboMap = true;
    v7.gameMode = 2;
    v7.skillLevel = 0;
    v7.gameMap = 3;
    session->ClearSessionOption(this: session, a2: OPTION_ALL);
    session->CreateGameStateLobby(this: session, a2: &v7);
    idMainMenu::WaitForSessionState(this, desiredState: GAME_LOBBY);
    session->StartMatch(this: session);
    idMainMenu::WaitForSessionState(this, desiredState: PARTY_LOBBY|SEARCHING);
    idMatchParameters::~idMatchParameters(this: &v7);
  }
}


// ========================================================================
// __unwind$523820
// EA  : 0x82DD436C
// RVA : 0x00DD436C
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void _unwind_523820()
{
  int v0; // r12

  idMatchParameters::~idMatchParameters(this: (idMatchParameters *)(v0 - 7056 + 240));
}


// ========================================================================
// `dynamic initializer for 'net_useCMap''
// EA  : 0x83385708
// RVA : 0x01385708
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__net_useCMap__()
{
  idCVar::idCVar(
    this: &net_useCMap,
    name: "net_useCMap",
    value: "1",
    flags: 1,
    description: "Use cmap for multiplayer maps",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__net_useCMap__);
}


// ========================================================================
// `dynamic initializer for 'mp_map_unlock_debug''
// EA  : 0x83385760
// RVA : 0x01385760
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_map_unlock_debug__()
{
  idCVar::idCVar(
    this: &mp_map_unlock_debug,
    name: "mp_map_unlock_debug",
    value: "0",
    flags: 1,
    description: "Debug online unlocking",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_map_unlock_debug__);
}


// ========================================================================
// `dynamic initializer for 'mp_enableJoinInProgress''
// EA  : 0x833857B8
// RVA : 0x013857B8
// PDB : w:\tech5\tungsten\game\mainmenulocal_multiplayer.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__mp_enableJoinInProgress__()
{
  idCVar::idCVar(
    this: &mp_enableJoinInProgress,
    name: "mp_enableJoinInProgress",
    value: "0",
    flags: 1,
    description: "If true, join in progress is enabled by default.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__mp_enableJoinInProgress__);
}

