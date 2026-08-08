
// ========================================================================
// ?InitLeaderboards@@YAXXZ
// EA  : 0x82E8A098
// RVA : 0x00E8A098
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void __fastcall InitLeaderboards()
{
  int v0; // r29
  const leaderboardDefinition_t **v1; // r23
  leaderboardDefinition_t *v2; // r3
  const leaderboardDefinition_t *v3; // r10
  int v4; // r11

  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  if ( !leaderboardsInitialized )
  {
    v0 = 0;
    v1 = rageMPCoopLeaderboards;
    do
    {
      v2 = (leaderboardDefinition_t *)idMem::AllocWithLocation(
                                        this: &mem,
                                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                        size: 0x14u,
                                        tag: TAG_NETWORKING,
                                        zeroBuffer: false,
                                        align: ALIGN_16,
                                        heap: HEAP_DEFAULTHEAP);
      if ( v2 != nullptr )
      {
        v2->columnDefs = columnDefCoop;
        v2->numColumns = 3;
        v3 = v2;
        v2->id = v0 + 10;
        v2->rankOrder = RANK_GREATEST_FIRST;
        *(_WORD *)&v2->supportsAttachments = 1;
        v4 = numRegisteredLeaderboards;
        registeredLeaderboards[numRegisteredLeaderboards] = v2;
        numRegisteredLeaderboards = v4 + 1;
      }
      else
      {
        v3 = nullptr;
      }
      *v1++ = v3;
      ++v0;
    }
    while ( (int)v1 < (int)&Ps3_TestSendScore );
    leaderboardsInitialized = true;
  }
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$488293
// EA  : 0x82E8A1A0
// RVA : 0x00E8A1A0
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _unwind_488293()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 208 + 80));
}


// ========================================================================
// ?Ps3_TestSendScore_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E8A1D0
// RVA : 0x00E8A1D0
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall Ps3_TestSendScore_f(const idCmdArgs *args)
{
  int v1; // r30
  __int128 v3; // r10 OVERLAPPED
  int v4; // r11
  __int64 v5; // r11
  bool v6; // cr57
  idLobbyBase *v7; // r3
  int v8; // r3
  unsigned __int64 v9[2]; // [sp+50h] [-40h] BYREF
  idList<unsigned __int64,5> v10[3]; // [sp+60h] [-30h] BYREF

  v1 = 0;
  memset(v10, 0, 14);
  v10[0].listStatic = 0;
  v10[0].memTag = 5;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v10);
  *((_QWORD *)&v3 + 1) = __PAIR64__(score, HIDWORD(score));
  v4 = score + 1;
  v9[0] = *(_QWORD *)((char *)&v3 + 4);
  *(_QWORD *)(HIDWORD(score) - 15008) = *(_QWORD *)((char *)&v3 - 4);
  idList<column_t,5>::Append(this: v10, obj: v9);
  HIDWORD(v5) = HIDWORD(kills);
  v9[0] = kills;
  LODWORD(v5) = kills + 1;
  kills = v5;
  idList<column_t,5>::Append(this: v10, obj: v9);
  v6 = args->argc > 1;
  HIDWORD(v9[0]) = args->argc;
  if ( v6 )
    v1 = atol(nptr: args->argv[1]);
  v7 = session->GetGameLobbyBase(this: session);
  v8 = (int)v7->GetLobbyUserIdByOrdinal(this: (idLobbyBase *)v9, result: (lobbyUserID_t *)v7, a3: v1);
  session->LeaderboardUpload(
    this: *(idSession **)v8,
    a2: *(lobbyUserID_t **)(v8 + 4),
    a3: &rageLeaderboardRally,
    a4: (const column_t *)v10[0].list,
    a5: nullptr);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v10);
}


// ========================================================================
// __unwind$488519
// EA  : 0x82E8A2E4
// RVA : 0x00E8A2E4
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _unwind_488519()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 144 + 96));
}


// ========================================================================
// ?Call@idLeaderboardCallbackTest@@EAAXXZ
// EA  : 0x82E8A318
// RVA : 0x00E8A318
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idLeaderboardCallbackTest::Call(idLeaderboardCallbackTest *this)
{
  __int64 v2; // r8
  int v3; // r29
  int v4; // r28
  int v5; // r27
  __int64 v6; // r6 OVERLAPPED
  int i; // r31

  idLib::Printf(fmt: "Leaderboard information retrieved in user callback.\n");
  idLib::Printf(fmt: "%d total entries in leaderboard %d.\n", this->numRowsInLeaderboard, this->def->id);
  LODWORD(v2) = this->rows.num;
  v3 = 0;
  if ( (int)v2 > 0 )
  {
    v4 = 0;
    v5 = 7;
    do
    {
      idLib::Printf(fmt: "%d: %s rank:%lld", v3, this->rows.list[v4].name.data, v2);
      for ( i = 0; i < this->def->numColumns; ++i )
      {
        *(__int64 *)((char *)&v6 + 4) = *((_QWORD *)&this->rows.list->hasAttachment + v5 + i);
        idLib::Printf(fmt: ", score[%d]: %lld", *((_DWORD *)&this->rows.list->hasAttachment + 2 * v5 + 2 * i), v6);
      }
      idLib::Printf(fmt: "\n");
      ++v3;
      ++v4;
      v5 += 24;
    }
    while ( v3 < this->rows.num );
  }
}


// ========================================================================
// ?Ps3_TestGetMyScore_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E8A410
// RVA : 0x00E8A410
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void __fastcall Ps3_TestGetMyScore_f(const idCmdArgs *args)
{
  int v1; // r11
  idLeaderboardCallback v2; // [sp+60h] [-40h] BYREF

  v1 = 0;
  v2.def = nullptr;
  v2.rows.listStatic = 0;
  memset(&v2.rows, 0, 14);
  v2.errorCode = LEADERBOARD_ERROR_NONE;
  v2.startIndex = -1;
  v2.localIndex = -1;
  v2.rows.memTag = 5;
  v2.numRowsInLeaderboard = -1;
  v2.__vftable = (idLeaderboardCallback_vtbl *)&idLeaderboardCallbackTest::`vftable';
  if ( args->argc > 1 )
    v1 = atol(nptr: args->argv[1]);
  session->LeaderboardDownload(this: session, a2: v1, a3: &rageLeaderboardRally, a4: 0, a5: 100, a6: &v2);
  idLeaderboardCallback::~idLeaderboardCallback(this: &v2);
}


// ========================================================================
// __unwind$488970
// EA  : 0x82E8A4D4
// RVA : 0x00E8A4D4
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _unwind_488970()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$488966
// EA  : 0x82E8A4FC
// RVA : 0x00E8A4FC
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _unwind_488966()
{
  int v0; // r12

  fakeLeaderboardCallback::~fakeLeaderboardCallback(this: (fakeLeaderboardCallback *)(v0 - 160 + 96));
}


// ========================================================================
// ?Ps3_TestFriendScores_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E8A530
// RVA : 0x00E8A530
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void __fastcall Ps3_TestFriendScores_f(const idCmdArgs *args)
{
  int v1; // r11
  idLeaderboardCallback v2; // [sp+60h] [-40h] BYREF

  v1 = 0;
  v2.def = nullptr;
  v2.rows.listStatic = 0;
  memset(&v2.rows, 0, 14);
  v2.errorCode = LEADERBOARD_ERROR_NONE;
  v2.startIndex = -1;
  v2.localIndex = -1;
  v2.rows.memTag = 5;
  v2.numRowsInLeaderboard = -1;
  v2.__vftable = (idLeaderboardCallback_vtbl *)&idLeaderboardCallbackTest::`vftable';
  if ( args->argc > 1 )
    v1 = atol(nptr: args->argv[1]);
  session->LeaderboardDownload(this: session, a2: v1, a3: &rageLeaderboardRally, a4: -1, a5: 100, a6: &v2);
  idLeaderboardCallback::~idLeaderboardCallback(this: &v2);
}


// ========================================================================
// __unwind$489053
// EA  : 0x82E8A5F4
// RVA : 0x00E8A5F4
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _unwind_489053()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$489049
// EA  : 0x82E8A61C
// RVA : 0x00E8A61C
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _unwind_489049()
{
  int v0; // r12

  fakeLeaderboardCallback::~fakeLeaderboardCallback(this: (fakeLeaderboardCallback *)(v0 - 160 + 96));
}


// ========================================================================
// ?Ps3_TestGetScores_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x82E8A650
// RVA : 0x00E8A650
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void __fastcall Ps3_TestGetScores_f(const idCmdArgs *args)
{
  int v1; // r11
  idLeaderboardCallback v2; // [sp+60h] [-40h] BYREF

  v1 = 0;
  v2.def = nullptr;
  v2.rows.listStatic = 0;
  memset(&v2.rows, 0, 14);
  v2.errorCode = LEADERBOARD_ERROR_NONE;
  v2.startIndex = -1;
  v2.localIndex = -1;
  v2.rows.memTag = 5;
  v2.numRowsInLeaderboard = -1;
  v2.__vftable = (idLeaderboardCallback_vtbl *)&idLeaderboardCallbackTest::`vftable';
  if ( args->argc > 1 )
    v1 = atol(nptr: args->argv[1]);
  session->LeaderboardDownload(this: session, a2: v1, a3: &rageLeaderboardRally, a4: 1, a5: 100, a6: &v2);
  idLeaderboardCallback::~idLeaderboardCallback(this: &v2);
}


// ========================================================================
// __unwind$489167
// EA  : 0x82E8A714
// RVA : 0x00E8A714
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _unwind_489167()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 160 + 96));
}


// ========================================================================
// __unwind$489163_0
// EA  : 0x82E8A73C
// RVA : 0x00E8A73C
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _unwind_489163_0()
{
  int v0; // r12

  fakeLeaderboardCallback::~fakeLeaderboardCallback(this: (fakeLeaderboardCallback *)(v0 - 160 + 96));
}


// ========================================================================
// ?Clone@idLeaderboardCallbackTest@@EBAPAVidLeaderboardCallback@@XZ
// EA  : 0x82E8A770
// RVA : 0x00E8A770
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

idLeaderboardCallback *__fastcall idLeaderboardCallbackTest::Clone(idLeaderboardCallbackTest *this)
{
  idLeaderboardCallback *v2; // r3
  _DWORD *v3; // r30

  v2 = (idLeaderboardCallback *)idMem::AllocWithLocation(
                                  this: &mem,
                                  location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                                  size: 0x28u,
                                  tag: TAG_NEW,
                                  zeroBuffer: false,
                                  align: ALIGN_16,
                                  heap: HEAP_DEFAULTHEAP);
  v3 = &v2->__vftable;
  if ( v2 == nullptr )
    return nullptr;
  idLeaderboardCallback::idLeaderboardCallback(this: v2, __that: this);
  *v3 = &idLeaderboardCallbackTest::`vftable';
  return (idLeaderboardCallback *)v3;
}


// ========================================================================
// __unwind$489250
// EA  : 0x82E8A7E4
// RVA : 0x00E8A7E4
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void __fastcall _unwind_489250(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}


// ========================================================================
// `dynamic initializer for 'rageTestLeaderboardTime''
// EA  : 0x83391AF0
// RVA : 0x01391AF0
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _dynamic_initializer_for__rageTestLeaderboardTime__()
{
  int v0; // r5

  v0 = numRegisteredLeaderboards++;
  registeredLeaderboards[v0] = &rageTestLeaderboardTime;
}


// ========================================================================
// `dynamic initializer for 'rageTestLeaderboardScore1''
// EA  : 0x83391B20
// RVA : 0x01391B20
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _dynamic_initializer_for__rageTestLeaderboardScore1__()
{
  int v0; // r5

  v0 = numRegisteredLeaderboards++;
  registeredLeaderboards[v0] = &rageTestLeaderboardScore1;
}


// ========================================================================
// `dynamic initializer for 'rageTestLeaderboardScore2''
// EA  : 0x83391B50
// RVA : 0x01391B50
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _dynamic_initializer_for__rageTestLeaderboardScore2__()
{
  int v0; // r5

  v0 = numRegisteredLeaderboards++;
  registeredLeaderboards[v0] = &rageTestLeaderboardScore2;
}


// ========================================================================
// `dynamic initializer for 'rageLeaderboardRally''
// EA  : 0x83391B80
// RVA : 0x01391B80
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _dynamic_initializer_for__rageLeaderboardRally__()
{
  int v0; // r5

  v0 = numRegisteredLeaderboards++;
  registeredLeaderboards[v0] = &rageLeaderboardRally;
}


// ========================================================================
// `dynamic initializer for 'rageLeaderboardVDM''
// EA  : 0x83391BB0
// RVA : 0x01391BB0
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _dynamic_initializer_for__rageLeaderboardVDM__()
{
  int v0; // r5

  v0 = numRegisteredLeaderboards++;
  registeredLeaderboards[v0] = &rageLeaderboardVDM;
}


// ========================================================================
// `dynamic initializer for 'rageLeaderboardBully''
// EA  : 0x83391BE0
// RVA : 0x01391BE0
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _dynamic_initializer_for__rageLeaderboardBully__()
{
  int v0; // r5

  v0 = numRegisteredLeaderboards++;
  registeredLeaderboards[v0] = &rageLeaderboardBully;
}


// ========================================================================
// `dynamic initializer for 'rageLeaderboardMeteor''
// EA  : 0x83391C10
// RVA : 0x01391C10
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _dynamic_initializer_for__rageLeaderboardMeteor__()
{
  int v0; // r5

  v0 = numRegisteredLeaderboards++;
  registeredLeaderboards[v0] = &rageLeaderboardMeteor;
}


// ========================================================================
// `dynamic initializer for 'rageLeaderboardTriad''
// EA  : 0x83391C40
// RVA : 0x01391C40
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

void _dynamic_initializer_for__rageLeaderboardTriad__()
{
  int v0; // r5

  v0 = numRegisteredLeaderboards++;
  registeredLeaderboards[v0] = &rageLeaderboardTriad;
}


// ========================================================================
// `dynamic initializer for 'Ps3_TestSendScore''
// EA  : 0x83391C70
// RVA : 0x01391C70
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Ps3_TestSendScore__()
{
  return idCommandLink::idCommandLink(
           this: &Ps3_TestSendScore,
           cmdName: "ps3_testSendScore",
           function: Ps3_TestSendScore_f,
           description: "Send a test score to the ps3 ranking server",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Ps3_TestGetScores''
// EA  : 0x83391C98
// RVA : 0x01391C98
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Ps3_TestGetScores__()
{
  return idCommandLink::idCommandLink(
           this: &Ps3_TestGetScores,
           cmdName: "ps3_testGetScores",
           function: Ps3_TestGetScores_f,
           description: "Gets scores from ps3 ranking server",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Ps3_TestGetMyScore''
// EA  : 0x83391CC0
// RVA : 0x01391CC0
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Ps3_TestGetMyScore__()
{
  return idCommandLink::idCommandLink(
           this: &Ps3_TestGetMyScore,
           cmdName: "ps3_testGetMyScore",
           function: Ps3_TestGetMyScore_f,
           description: "Gets scores from ps3 ranking server",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'Ps3_TestFriendScores''
// EA  : 0x83391CE8
// RVA : 0x01391CE8
// PDB : w:\tech5\tungsten\game\rageleaderboards.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__Ps3_TestFriendScores__()
{
  return idCommandLink::idCommandLink(
           this: &Ps3_TestFriendScores,
           cmdName: "ps3_testGetFriendScores",
           function: Ps3_TestFriendScores_f,
           description: "Gets scores from ps3 ranking server",
           argCompletion: nullptr);
}

