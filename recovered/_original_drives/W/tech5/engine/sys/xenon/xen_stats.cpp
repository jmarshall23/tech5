
// ========================================================================
// ?UseHiddenSortColumn@@YA_NW4rankOrder_t@@@Z
// EA  : 0x829E8870
// RVA : 0x009E8870
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

BOOL __fastcall UseHiddenSortColumn(rankOrder_t rankOrder)
{
  return (_cntlzw(rankOrder - 1) & 0x20) != 0;
}


// ========================================================================
// ?HasCompleted@OverlappedOperation@@QBA_NXZ
// EA  : 0x829E8880
// RVA : 0x009E8880
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

unsigned int __fastcall OverlappedOperation::HasCompleted(OverlappedOperation *this)
{
  return this->overlapped.InternalLow
       - 997
       - (this->overlapped.InternalLow
        - 998
        + (this->overlapped.InternalLow == 997));
}


// ========================================================================
// CompareRows
// EA  : 0x829E8898
// RVA : 0x009E8898
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

int __fastcall CompareRows(_DWORD *a_, _DWORD *b_)
{
  unsigned int v2; // r10
  unsigned int v4; // r11

  v2 = a_[2];
  if ( v2 == 0 )
    return b_[2] != 0;
  v4 = b_[2];
  if ( v4 != 0 )
    return v2 >= v4 ? 1 : -1;
  else
    return -1;
}


// ========================================================================
// ?PrepareSpecForLeaderboard@@YAXAAU_XUSER_STATS_SPEC@@PBUleaderboardDefinition_t@@@Z
// EA  : 0x829E88F0
// RVA : 0x009E88F0
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void __fastcall PrepareSpecForLeaderboard(_XUSER_STATS_SPEC *statsSpec, const leaderboardDefinition_t *leaderboard)
{
  signed int v2; // r11
  unsigned int v3; // r10
  signed int v4; // r10
  _WORD *v5; // r10

  v2 = 0;
  statsSpec->dwViewId = leaderboard->id;
  v3 = leaderboard->numColumns - 1;
  statsSpec->dwNumColumnIds = v3;
  v4 = ((_cntlzw(leaderboard->rankOrder - 1) & 0x20) != 0) + v3;
  statsSpec->dwNumColumnIds = v4;
  if ( v4 > 0 )
  {
    v5 = (_WORD *)&statsSpec->dwNumColumnIds + 1;
    do
      *++v5 = ++v2;
    while ( v2 < (signed int)statsSpec->dwNumColumnIds );
  }
}


// ========================================================================
// ?SetLeaderboard@idLeaderboardQuery@@QAAXPBUleaderboardDefinition_t@@@Z
// EA  : 0x829E8948
// RVA : 0x009E8948
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void __fastcall idLeaderboardQuery::SetLeaderboard(idLeaderboardQuery *this, const leaderboardDefinition_t *def)
{
  this->leaderboard = def;
  PrepareSpecForLeaderboard(statsSpec: &this->statsSpec, leaderboard: def);
}


// ========================================================================
// ?CanDownload@idLeaderboards@@QBA_NXZ
// EA  : 0x829E8958
// RVA : 0x009E8958
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

BOOL __fastcall idLeaderboards::CanDownload(idLeaderboards *this)
{
  return (_cntlzw(this->state) & 0x20) != 0;
}


// ========================================================================
// ?OnFailed@idLeaderboardQuery@@UAAXXZ
// EA  : 0x829E8968
// RVA : 0x009E8968
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void __fastcall idLeaderboardQuery::OnFailed(idLeaderboardQuery *this)
{
  const leaderboardDefinition_t *leaderboard; // r9
  idLeaderboardCallback *Pointee; // r3
  idLeaderboardCallback_vtbl *v3; // r8

  leaderboard = this->leaderboard;
  Pointee = this->callback.Pointee;
  v3 = Pointee->__vftable;
  Pointee->errorCode = LEADERBOARD_ERROR_FAILED;
  Pointee->def = leaderboard;
  v3->Call(this: Pointee);
}


// ========================================================================
// ?EnumFriends@idLeaderboards@@QAA_NXZ
// EA  : 0x829E8998
// RVA : 0x009E8998
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

int __fastcall idLeaderboards::EnumFriends(idLeaderboards *this)
{
  unsigned int MasterInputDevice; // r28
  idFriendsEnum *v3; // r3
  _DWORD *v4; // r11
  int i; // ctr
  idFriendsEnum *inFlightFriendsEnum; // r3

  if ( this->state != 0 )
    return 0;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  MasterInputDevice = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
  v3 = (idFriendsEnum *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(28) : TAG_NEW",
                          size: 0x28u,
                          tag: TAG_NEW,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
  if ( v3 != nullptr )
  {
    v4 = &v3->__vftable;
    for ( i = 7; i != 0; --i )
      *++v4 = 0;
    v3->resultsEnum = nullptr;
    v3->resultsBuffer = nullptr;
    v3->__vftable = (idFriendsEnum_vtbl *)&idFriendsEnum::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  this->inFlightFriendsEnum = v3;
  if ( (unsigned __int8)idFriendsEnum::Start(this: v3, user: MasterInputDevice) == 0 )
  {
    inFlightFriendsEnum = this->inFlightFriendsEnum;
    if ( inFlightFriendsEnum != nullptr )
      ((void (__fastcall *)(idFriendsEnum *, int))inFlightFriendsEnum->dtr_OverlappedOperation)(
        a1: inFlightFriendsEnum,
        a2: 1);
    this->inFlightFriendsEnum = nullptr;
    idMem::PopHeap(this: &mem);
    return 0;
  }
  this->state = STATE_DOWNLOADING_FRIENDS;
  idMem::PopHeap(this: &mem);
  return 1;
}


// ========================================================================
// __unwind$223462
// EA  : 0x829E8AAC
// RVA : 0x009E8AAC
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void _unwind_223462()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 144 + 80));
}


// ========================================================================
// ??0idLeaderboardQuery@@QAA@ABVidLeaderboardCallback@@@Z
// EA  : 0x829E8C30
// RVA : 0x009E8C30
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

idLeaderboardQuery *__fastcall idLeaderboardQuery::idLeaderboardQuery(
        idLeaderboardQuery *this,
        const idLeaderboardCallback *callback_)
{
  int v3; // ctr
  idLeaderboardQuery *v4; // r11

  v3 = 7;
  v4 = this;
  do
  {
    v4 = (idLeaderboardQuery *)((char *)v4 + 4);
    v4->__vftable = nullptr;
    --v3;
  }
  while ( v3 != 0 );
  this->__vftable = (idLeaderboardQuery_vtbl *)&idLeaderboardQuery::`vftable';
  this->statsArray.__vftable = (idAutoPtr_Array<_XUSER_STATS_READ_RESULTS>_vtbl *)&idAutoPtr_Array<_XUSER_STATS_READ_RESULTS>::`vftable';
  this->statsArray.Pointee = nullptr;
  this->startingRank = 0;
  this->callback.Pointee = (idLeaderboardCallback *)callback_->Clone(this: callback_);
  return this;
}


// ========================================================================
// __unwind$223698
// EA  : 0x829E8CCC
// RVA : 0x009E8CCC
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void _unwind_223698()
{
  int v0; // r12

  OverlappedOperation::~OverlappedOperation(this: *(OverlappedOperation **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$223699
// EA  : 0x829E8CF4
// RVA : 0x009E8CF4
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void _unwind_223699()
{
  int v0; // r12

  idAutoPtr_Array<_XUSER_STATS_READ_RESULTS>::~idAutoPtr_Array<_XUSER_STATS_READ_RESULTS>(this: (idAutoPtr_Array<_XUSER_STATS_READ_RESULTS> *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// ?AllocStats@idLeaderboardQuery@@AAAXK@Z
// EA  : 0x829E8E10
// RVA : 0x009E8E10
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void __fastcall idLeaderboardQuery::AllocStats(idLeaderboardQuery *this, unsigned int size)
{
  idAutoPtr_Array<_XUSER_STATS_READ_RESULTS> *p_statsArray; // r29
  _XUSER_STATS_READ_RESULTS *v4; // r28
  _XUSER_STATS_READ_RESULTS *Pointee; // r4

  p_statsArray = &this->statsArray;
  idMem::PushHeap(this: &mem, heapType: HEAP_SYSTEMHEAP);
  v4 = (_XUSER_STATS_READ_RESULTS *)idMem::AllocWithLocation(
                                      this: &mem,
                                      location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                      size,
                                      tag: TAG_NEW,
                                      zeroBuffer: false,
                                      align: ALIGN_16,
                                      heap: HEAP_DEFAULTHEAP);
  Pointee = p_statsArray->Pointee;
  if ( v4 != Pointee )
    idMem::Free(this: &mem, ptr: Pointee, align: ALIGN_16);
  p_statsArray->Pointee = v4;
  idMem::PopHeap(this: &mem);
}


// ========================================================================
// __unwind$223782
// EA  : 0x829E8E98
// RVA : 0x009E8E98
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void _unwind_223782()
{
  int v0; // r12

  idScopedGlobalHeap::~idScopedGlobalHeap(this: (idScopedGlobalHeap *)(v0 - 128 + 84));
}


// ========================================================================
// ?ProcessDownload@idLeaderboards@@QAA_NPAVidLeaderboardQuery@@@Z
// EA  : 0x829E8EC0
// RVA : 0x009E8EC0
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

int __fastcall idLeaderboards::ProcessDownload(
        idLeaderboards *this,
        idLeaderboardQuery *leaderboardQuery,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        unsigned int *a8)
{
  unsigned int startingRank; // r4
  unsigned int numFriends; // r4
  unsigned int v13; // r4
  _XUSER_STATS_SPEC *p_statsSpec; // r7
  unsigned __int64 v15; // r6
  unsigned int v16; // r4
  unsigned int StatsEnumeratorByXuid; // r4
  unsigned int v18; // r4
  void **v19; // [sp+8h] [-78h]
  unsigned int v20; // [sp+50h] [-30h] BYREF
  void *v21[11]; // [sp+54h] [-2Ch] BYREF

  startingRank = leaderboardQuery->startingRank;
  v20 = 0;
  if ( startingRank == -1 )
  {
    numFriends = this->numFriends;
    if ( numFriends == 0 )
    {
      idLib::Printf(fmt: "XUserReadStats: no friends\n");
      return 0;
    }
    v13 = XUserReadStats(
            dwTitleId: 0,
            dwNumXuids: numFriends,
            pXuids: this->friendsXuids,
            dwNumStatsSpecs: 1u,
            pSpecs: &leaderboardQuery->statsSpec,
            pcbResults: &v20,
            pResults: nullptr,
            pOverlapped: nullptr);
    if ( v13 != 122
      || (idLeaderboardQuery::AllocStats(this: leaderboardQuery, size: v20),
          (v13 = XUserReadStats(
                   dwTitleId: 0,
                   dwNumXuids: this->numFriends,
                   pXuids: this->friendsXuids,
                   dwNumStatsSpecs: 1u,
                   pSpecs: &leaderboardQuery->statsSpec,
                   pcbResults: &v20,
                   pResults: leaderboardQuery->statsArray.Pointee,
                   pOverlapped: &leaderboardQuery->overlapped)) != 997) )
    {
      idLib::Printf(fmt: "XUserReadStats failed with error 0x%08x\n", v13);
      return 0;
    }
  }
  else
  {
    HIDWORD(v15) = leaderboardQuery->numRows;
    p_statsSpec = &leaderboardQuery->statsSpec;
    LODWORD(v15) = 1;
    if ( startingRank != 0 )
    {
      v16 = XUserCreateStatsEnumeratorByRank(
              dwTitleId: 0,
              dwRankStart: startingRank,
              dwNumRows: HIDWORD(v15),
              dwNumStatsSpecs: 1u,
              pSpecs: p_statsSpec,
              pcbBuffer: &v20,
              ph: v21);
      if ( v16 != 0 )
      {
        idLib::Printf(fmt: "XUserCreateStatsEnumeratorByRank failed with error 0x%08x\n", v16);
        return 0;
      }
    }
    else
    {
      StatsEnumeratorByXuid = XUserCreateStatsEnumeratorByXuid(
                                dwTitleId: HIDWORD(leaderboardQuery->xuid),
                                xuidPivot: v15,
                                dwNumRows: (unsigned int)p_statsSpec,
                                dwNumStatsSpecs: (unsigned int)&v20,
                                pSpecs: (const _XUSER_STATS_SPEC *)v21,
                                pcbBuffer: a8,
                                ph: v19);
      if ( StatsEnumeratorByXuid != 0 )
      {
        idLib::Printf(fmt: "XUserCreateStatsEnumeratorByXuid failed with error 0x%08x\n", StatsEnumeratorByXuid);
        return 0;
      }
    }
    idLeaderboardQuery::AllocStats(this: leaderboardQuery, size: v20);
    v18 = XEnumerate(
            hEnum: v21[0],
            pvBuffer: leaderboardQuery->statsArray.Pointee,
            cbBuffer: v20,
            pcItemsReturned: nullptr,
            pOverlapped: &leaderboardQuery->overlapped);
    if ( v18 != 997 )
    {
      idLib::Printf(fmt: "XEnumerate failed with error 0x%08x\n", v18);
      return 0;
    }
  }
  return 1;
}


// ========================================================================
// ??0idLeaderboards@@QAA@AAVidSessionLocal@@@Z
// EA  : 0x829E9278
// RVA : 0x009E9278
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

idLeaderboards *__fastcall idLeaderboards::idLeaderboards(idLeaderboards *this, idSessionLocal *sessionLocal_)
{
  this->sessionLocal = sessionLocal_;
  this->state = 0;
  this->numFriends = 0;
  this->inFlightFriendsEnum = nullptr;
  this->inFlightStats.list = nullptr;
  this->inFlightStats.granularity = 0;
  this->inFlightStats.memTag = 5;
  this->inFlightStats.listStatic = 0;
  this->inFlightStats.size = 0;
  this->inFlightStats.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->inFlightStats);
  return this;
}


// ========================================================================
// ??1idLeaderboards@@QAA@XZ
// EA  : 0x829E92E0
// RVA : 0x009E92E0
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void __fastcall idLeaderboards::~idLeaderboards(idLeaderboards *this)
{
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->inFlightStats);
}


// ========================================================================
// ?SubmitDownload@idLeaderboards@@QAAXPAVidLeaderboardQuery@@@Z
// EA  : 0x829E9410
// RVA : 0x009E9410
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void __fastcall idLeaderboards::SubmitDownload(
        idLeaderboards *this,
        idLeaderboardQuery *leaderboardQuery,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        unsigned int *a8)
{
  idLeaderboardQuery *v10; // [sp+50h] [-20h] BYREF

  if ( (unsigned __int8)idLeaderboards::ProcessDownload(this, leaderboardQuery, a3, a4, a5, a6, a7, a8) != 0 )
  {
    v10 = leaderboardQuery;
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->inFlightStats,
      obj: (const encounterGroupRole_t *)&v10);
    this->state = STATE_DOWNLOAD_IN_FLIGHT;
  }
  else if ( leaderboardQuery != nullptr )
  {
    ((void (__fastcall *)(idLeaderboardQuery *, int))leaderboardQuery->dtr_OverlappedOperation)(
      a1: leaderboardQuery,
      a2: 1);
  }
}


// ========================================================================
// ?FillRows@idLeaderboardQuery@@AAAXXZ
// EA  : 0x829E9618
// RVA : 0x009E9618
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void __fastcall idLeaderboardQuery::FillRows(idLeaderboardQuery *this)
{
  _XUSER_STATS_VIEW *pViews; // r24
  unsigned int v3; // r26
  int v4; // r27
  _XUSER_STATS_ROW *v5; // r30
  __int64 v6; // r8
  idArray<__int64,16> *p_columns; // r9
  unsigned int v8; // r10
  int v9; // r11
  __int64 *v10; // r9
  char *v11; // r8
  idLeaderboardCallback *Pointee; // r11
  int v13; // r10
  int v14; // r9
  int num; // r10
  idLeaderboardCallback::row_t v16; // [sp+50h] [-110h] BYREF

  pViews = this->statsArray.Pointee->pViews;
  if ( this->startingRank == -1 )
    qsort(
      base: pViews->pRows,
      num: pViews->dwNumRows,
      width: 0x30u,
      comp: (int (__fastcall *)(const void *, const void *))CompareRows);
  v3 = 0;
  if ( pViews->dwNumRows != 0 )
  {
    v4 = 0;
    do
    {
      v5 = &pViews->pRows[v4];
      if ( v5->dwRank != 0 )
      {
        v16.name.len = 0;
        v16.name.data = v16.name.baseBuffer;
        v16.name.baseBuffer[0] = 0;
        v16.name.allocedAndFlag = 20;
        idStr::operator=(this: &v16.name, text: v5->szGamertag);
        LODWORD(v6) = v5->dwRank;
        HIDWORD(v6) = this->leaderboard;
        p_columns = &v16.columns;
        v16.rank = v6;
        v16.user_id = v5->xuid;
        v16.hasAttachment = false;
        if ( *(_DWORD *)(HIDWORD(v6) + 12) != 1 )
        {
          p_columns = (idArray<__int64,16> *)&v16.columns.ptr[1];
          v16.columns.ptr[0] = v5->i64Rating;
        }
        v8 = 0;
        if ( v5->dwNumColumns != 0 )
        {
          v9 = 0;
          v10 = &p_columns[-1].ptr[15];
          do
          {
            ++v8;
            v11 = (char *)v5->pColumns + v9;
            v9 += 24;
            *++v10 = *((_QWORD *)v11 + 2);
          }
          while ( v8 < v5->dwNumColumns );
        }
        idList<idLeaderboardCallback::row_t,5>::Append(this: &this->callback.Pointee->rows, obj: &v16);
        idStr::FreeData(this: &v16.name);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < pViews->dwNumRows );
  }
  Pointee = this->callback.Pointee;
  v13 = 0;
  if ( Pointee->rows.num > 0 )
  {
    v14 = 0;
    do
    {
      if ( LODWORD(Pointee->rows.list[v14].user_id) == LODWORD(this->xuid) )
        Pointee->localIndex = v13;
      Pointee = this->callback.Pointee;
      ++v13;
      ++v14;
    }
    while ( v13 < Pointee->rows.num );
  }
  if ( this->startingRank == -1 )
  {
    Pointee = this->callback.Pointee;
    num = Pointee->rows.num;
  }
  else
  {
    num = pViews->dwTotalViewRows;
  }
  Pointee->numRowsInLeaderboard = num;
}


// ========================================================================
// __unwind$224081
// EA  : 0x829E97C4
// RVA : 0x009E97C4
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void _unwind_224081()
{
  int v0; // r12

  idBotWeaponState::BotWeaponRequest_t::~BotWeaponRequest_t(this: (idSWFSpriteInstance::placeObject2Data_t *)(v0 - 352 + 80));
}


// ========================================================================
// ?Pump@idLeaderboards@@QAAXXZ
// EA  : 0x829E97F0
// RVA : 0x009E97F0
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void __fastcall idLeaderboards::Pump(idLeaderboards *this)
{
  idLeaderboards::state_t state; // r11
  _XOVERLAPPED *p_overlapped; // r3
  unsigned __int64 v4; // r10
  __int64 v5; // r8
  int v6; // r6
  int v7; // r5
  unsigned int v8; // r3
  unsigned int v9; // r31
  unsigned int MasterInputDevice; // r3
  unsigned __int8 *v11; // r11
  idFriendsEnum *inFlightFriendsEnum; // r3
  int v13; // r27
  idList<OverlappedOperation *,5> *p_inFlightStats; // r31
  int v15; // r26
  OverlappedOperation *v16; // r30
  int v17; // r29
  OverlappedOperation_vtbl *v18; // r11
  int num; // r11
  int v20; // r11
  bool v21; // zf
  int v22; // r10
  _DWORD *v23; // r9
  unsigned int v24; // [sp+50h] [-60h] BYREF
  unsigned __int64 v25; // [sp+58h] [-58h] BYREF

  state = this->state;
  if ( state == STATE_DOWNLOADING_FRIENDS )
  {
    p_overlapped = &this->inFlightFriendsEnum->overlapped;
    if ( p_overlapped->InternalLow != 997 )
    {
      v24 = 0;
      v8 = XGetOverlappedResult(lpXOverlapped: p_overlapped, pdwResult: &v24, bWait: 1);
      v9 = v8;
      if ( v8 == 0 || v8 == 18 || v8 == 1627 )
      {
        this->numFriends = 0;
        MasterInputDevice = idSignInManagerBase::GetMasterInputDevice(this: session->signInManager);
        if ( XUserGetXUID(dwUserIndex: MasterInputDevice, pxuid: &v25) == 0 )
        {
          LODWORD(v4) = v25;
          HIDWORD(v4) = this->numFriends + 1;
          LODWORD(v5) = 8 * HIDWORD(v4);
          *((_QWORD *)&this->sessionLocal + HIDWORD(v4)) = v4;
          HIDWORD(v5) = this->numFriends + 1;
          this->numFriends = HIDWORD(v5);
        }
      }
      if ( v9 == 0 )
      {
        v4 = v24;
        if ( v24 != 0 )
        {
          v11 = this->inFlightFriendsEnum->resultsBuffer + 24;
          do
          {
            LODWORD(v5) = *(_DWORD *)v11 & 0x80000000;
            if ( *(int *)v11 >= 0 && (*(_DWORD *)v11 & 0x40000000) == 0 )
            {
              v5 = *((_QWORD *)v11 - 3);
              HIDWORD(v5) = this->numFriends + 1;
              v6 = 8 * HIDWORD(v5);
              *((_QWORD *)&this->sessionLocal + HIDWORD(v5)) = v5;
              v7 = this->numFriends + 1;
              this->numFriends = v7;
            }
            v4 = __PAIR64__(HIDWORD(v4), v24) + 0x100000000LL;
            v11 += 196;
          }
          while ( HIDWORD(v4) < v24 );
        }
      }
      inFlightFriendsEnum = this->inFlightFriendsEnum;
      if ( inFlightFriendsEnum != nullptr )
        ((void (__fastcall *)(idFriendsEnum *, int))inFlightFriendsEnum->dtr_OverlappedOperation)(
          a1: inFlightFriendsEnum,
          a2: 1);
      this->inFlightFriendsEnum = nullptr;
      this->state = 0;
      idLeaderboards::SubmitDownload(
        this,
        leaderboardQuery: this->pendingDownload,
        a3: v7,
        a4: v6,
        a5: SHIDWORD(v5),
        a6: v5,
        a7: SHIDWORD(v4),
        a8: (unsigned int *)v4);
      this->pendingDownload = nullptr;
    }
  }
  else if ( state == STATE_DOWNLOAD_IN_FLIGHT && this->inFlightStats.num == 0 )
  {
    this->state = 0;
  }
  v13 = 0;
  if ( this->inFlightStats.num > 0 )
  {
    p_inFlightStats = &this->inFlightStats;
    v15 = 0;
    do
    {
      v16 = p_inFlightStats->list[v15];
      if ( v16->overlapped.InternalLow == 997 )
      {
        ++v13;
        ++v15;
      }
      else
      {
        v17 = XGetOverlappedExtendedError(lpXOverlapped: &v16->overlapped);
        v18 = v16->__vftable;
        if ( v17 < 0 )
        {
          v18->OnFailed(this: v16);
          idLib::Printf(fmt: "Leaderboard overlapped operation failed, error 0x%08x\n", v17);
        }
        else
        {
          v18->OnCompleted(this: v16);
        }
        ((void (__fastcall *)(OverlappedOperation *, int))v16->dtr_OverlappedOperation)(a1: v16, a2: 1);
        if ( v13 >= 0 )
        {
          num = this->inFlightStats.num;
          if ( v13 < num )
          {
            this->inFlightStats.num = num - 1;
            v21 = v13 >= num - 1;
            v20 = v13;
            if ( !v21 )
            {
              v22 = v15 * 4;
              do
              {
                ++v20;
                v23 = (OverlappedOperation **)((char *)p_inFlightStats->list + v22);
                v22 += 4;
                *v23 = v23[1];
              }
              while ( v20 < this->inFlightStats.num );
            }
          }
        }
      }
    }
    while ( v13 < this->inFlightStats.num );
  }
  if ( this->state == STATE_DOWNLOAD_IN_FLIGHT && this->inFlightStats.num == 0 )
    this->state = 0;
}


// ========================================================================
// ?QueueDownload@idLeaderboards@@QAAXPAVidLeaderboardQuery@@@Z
// EA  : 0x829E9A78
// RVA : 0x009E9A78
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void __fastcall idLeaderboards::QueueDownload(
        idLeaderboards *this,
        idLeaderboardQuery *leaderboardQuery,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        unsigned int *a8)
{
  if ( leaderboardQuery->startingRank == -1 )
  {
    if ( (unsigned __int8)idLeaderboards::EnumFriends(this) != 0 )
      this->pendingDownload = leaderboardQuery;
    else
      ((void (__fastcall *)(idLeaderboardQuery *, int))leaderboardQuery->dtr_OverlappedOperation)(
        a1: leaderboardQuery,
        a2: 1);
  }
  else
  {
    idLeaderboards::SubmitDownload(this, leaderboardQuery, a3, a4, a5, a6, a7, a8);
  }
}


// ========================================================================
// ?OnCompleted@idLeaderboardQuery@@UAAXXZ
// EA  : 0x829E9AF8
// RVA : 0x009E9AF8
// PDB : w:\tech5\engine\sys\xenon\xen_stats.cpp
// ========================================================================

void __fastcall idLeaderboardQuery::OnCompleted(idLeaderboardQuery *this)
{
  unsigned int v1; // r29
  _XUSER_STATS_VIEW *pViews; // r31
  int v4; // r11
  int v5; // r30

  v1 = 0;
  pViews = this->statsArray.Pointee->pViews;
  this->callback.Pointee->def = this->leaderboard;
  this->callback.Pointee->localIndex = -1;
  this->callback.Pointee->errorCode = LEADERBOARD_ERROR_NONE;
  if ( pViews->dwNumRows != 0 )
  {
    if ( this->startingRank == -1 )
      v4 = 0;
    else
      v4 = pViews->pRows->dwRank - 1;
    this->callback.Pointee->startIndex = v4;
    if ( pViews->dwNumRows != 0 )
    {
      v5 = 0;
      do
      {
        if ( v1 != 0 && this->startingRank != -1 && pViews->pRows[v5].dwRank != pViews->pRows[v5 - 1].dwRank + 1 )
          idLib::Printf(fmt: "Leaderboard rank out of order.\n");
        ++v1;
        ++v5;
      }
      while ( v1 < pViews->dwNumRows );
    }
  }
  else
  {
    this->callback.Pointee->startIndex = -1;
  }
  idLeaderboardQuery::FillRows(this);
  this->callback.Pointee->Call(this: this->callback.Pointee);
}

