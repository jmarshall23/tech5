
// ========================================================================
// ?Scroll@idLBCache@@QAA_NH@Z
// EA  : 0x82D9DE38
// RVA : 0x00D9DE38
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

int __fastcall idLBCache::Scroll(idLBCache *this, int amount)
{
  int entryIndex; // r8
  int rowOffset; // r9
  int v5; // r11
  int v6; // r10
  int numRowsInLeaderboard; // r10
  int v8; // r10
  int v9; // r11
  unsigned __int8 v10; // r11

  if ( this->errorCode != LEADERBOARD_DISPLAY_ERROR_NONE )
    return 0;
  entryIndex = this->entryIndex;
  rowOffset = this->rowOffset;
  v5 = entryIndex + amount;
  this->entryIndex = entryIndex + amount;
  if ( entryIndex + amount < 0 )
  {
    v6 = 0;
    this->rowOffset = v5 + rowOffset;
LABEL_9:
    this->entryIndex = v6;
    goto LABEL_10;
  }
  numRowsInLeaderboard = this->numRowsInLeaderboard;
  if ( v5 < numRowsInLeaderboard )
  {
    if ( v5 >= 12 )
    {
      v6 = 11;
      this->rowOffset = v5 + rowOffset - 11;
      goto LABEL_9;
    }
  }
  else
  {
    this->entryIndex = numRowsInLeaderboard - 1;
    this->rowOffset = numRowsInLeaderboard - 12;
  }
LABEL_10:
  v8 = this->rowOffset;
  if ( v8 >= 0 )
  {
    if ( v8 > (int)(((this->numRowsInLeaderboard == 12) + ((unsigned int)(this->numRowsInLeaderboard - 12) >> 31) - 1)
                  & (this->numRowsInLeaderboard - 12)) )
      v8 = ((this->numRowsInLeaderboard == 12) + ((unsigned int)(this->numRowsInLeaderboard - 12) >> 31) - 1)
         & (this->numRowsInLeaderboard - 12);
  }
  else
  {
    v8 = 0;
  }
  v9 = this->entryIndex;
  this->rowOffset = v8;
  if ( entryIndex != v9 )
    return 1;
  v10 = 0;
  if ( rowOffset != v8 )
    return 1;
  return v10;
}


// ========================================================================
// ?FindFreeRowBlock@idLBCache@@QAAPAVidLBRowBlock@@XZ
// EA  : 0x82D9DF10
// RVA : 0x00D9DF10
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

idLBCache *__fastcall idLBCache::FindFreeRowBlock(idLBCache *this)
{
  int lastTime; // r9
  int v2; // r8
  int v3; // r11
  idLBCache *i; // r10

  lastTime = 0;
  v2 = 0;
  v3 = 0;
  for ( i = this; i->rowBlocks[0].rows.num != 0; i = (idLBCache *)((char *)i + 24) )
  {
    if ( v3 == 0 || i->rowBlocks[0].lastTime < lastTime )
    {
      lastTime = i->rowBlocks[0].lastTime;
      v2 = v3;
    }
    if ( ++v3 >= 5 )
      return (idLBCache *)((char *)this + 24 * v2);
  }
  return (idLBCache *)((char *)this + 24 * v3);
}


// ========================================================================
// ?DisplayGamerCardUI@idLBCache@@QAAXPBUrow_t@idLeaderboardCallback@@@Z
// EA  : 0x82D9DF80
// RVA : 0x00D9DF80
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void __fastcall idLBCache::DisplayGamerCardUI(idLBCache *this, const idLeaderboardCallback::row_t *row)
{
  idLocalUser *MasterLocalUser; // r3
  unsigned __int64 v4; // r6

  MasterLocalUser = idSignInManagerBase::GetMasterLocalUser(this: session->signInManager);
  MasterLocalUser->GetInputDevice(this: MasterLocalUser);
  XShowGamerCardUI(dwUserIndex: HIDWORD(row->user_id), XuidPlayer: v4);
}


// ========================================================================
// ?GetFilterStrType@idLBCache@@QAA?AVidStr@@XZ
// EA  : 0x82D9DFD0
// RVA : 0x00D9DFD0
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

idLBCache *__fastcall idLBCache::GetFilterStrType(idLBCache *this, idStr *result)
{
  int v2; // r11
  const char *v4; // r3
  const char *String; // r3

  v2 = *(_DWORD *)&result[3].baseBuffer[16];
  if ( v2 == 2 )
  {
    v4 = "#str_online_leaderboards_title_friends";
  }
  else if ( v2 == 1 )
  {
    v4 = "#str_online_leaderboards_title_myscore";
  }
  else
  {
    v4 = "#str_online_leaderboards_title_global";
  }
  String = idLocalization::GetString(inString: v4);
  idStr::idStr((idStr *)this, text: String);
  return this;
}


// ========================================================================
// ?Reset@idLBCache@@QAAXXZ
// EA  : 0x82D9E040
// RVA : 0x00D9E040
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void __fastcall idLBCache::Reset(idLBCache *this)
{
  unsigned __int8 *p_listStatic; // r29
  int i; // r26
  char *v4; // r28
  int v5; // r31
  idStr *v6; // r30

  p_listStatic = &this->rowBlocks[0].rows.listStatic;
  for ( i = 5; i != 0; --i )
  {
    *(_DWORD *)(p_listStatic - 19) = 0;
    if ( *p_listStatic == 0 || *p_listStatic == 2 )
    {
      v4 = *(char **)(p_listStatic - 15);
      if ( v4 != nullptr )
      {
        v5 = *(_DWORD *)(p_listStatic - 7);
        if ( v5 > 0 )
        {
          v6 = (idStr *)(v4 + 16);
          do
          {
            idStr::FreeData(this: v6);
            --v5;
            v6 += 6;
          }
          while ( v5 != 0 );
        }
        idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      }
      *(_DWORD *)(p_listStatic - 15) = 0;
      *(_DWORD *)(p_listStatic - 7) = 0;
    }
    *(_DWORD *)(p_listStatic - 11) = 0;
    p_listStatic += 24;
  }
  this->def = nullptr;
  this->filter = LEADERBOARD_FILTER_OVERALL;
  this->pendingDef = nullptr;
  this->pendingFilter = LEADERBOARD_FILTER_OVERALL;
  this->rowOffset = 0;
  this->requestingRows = false;
  this->numRowsInLeaderboard = 0;
  this->entryIndex = 0;
  this->loadingNewLeaderboard = false;
}


// ========================================================================
// ?Update@idLBCache@@QAAXPBVidLeaderboardCallback@@@Z
// EA  : 0x82D9E100
// RVA : 0x00D9E100
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void __fastcall idLBCache::Update(idLBCache *this, const idLeaderboardCallback *callback)
{
  BOOL loadingNewLeaderboard; // r9
  leaderboardDisplayError_t v5; // r11
  leaderboardDisplayError_t errorCode; // r11
  int localIndex; // r11
  int v8; // r10
  leaderboardFilterMode_t filter; // r11
  int startIndex; // r11
  idLBCache *FreeRowBlock; // r31

  loadingNewLeaderboard = this->loadingNewLeaderboard;
  this->requestingRows = false;
  v5 = callback->errorCode != LEADERBOARD_ERROR_NONE;
  this->errorCode = v5;
  if ( loadingNewLeaderboard
    && this->filter == LEADERBOARD_FILTER_MYSCORE
    && callback->localIndex == -1
    && v5 == LEADERBOARD_DISPLAY_ERROR_NONE )
  {
    this->errorCode = LEADERBOARD_DISPLAY_ERROR_NOT_RANKED;
  }
  errorCode = this->errorCode;
  if ( errorCode != LEADERBOARD_DISPLAY_ERROR_NONE )
  {
    this->numRowsInLeaderboard = 0;
    this->loadingNewLeaderboard = false;
    if ( errorCode == LEADERBOARD_DISPLAY_ERROR_NOT_ONLINE )
    {
      idMainMenu::GoToMultiplayerMainMenu(this: gameLocal->mainMenu);
      ((void (__fastcall *)(idCommon *, int, _DWORD, _DWORD, _DWORD, int, char *, _DWORD))common->AddDialog)(
        a1: common,
        a2: 14,
        a3: 0,
        a4: 0,
        a5: 0,
        a6: 1,
        a7: &byte_8200D768,
        a8: 0);
    }
  }
  else if ( callback->def == this->def )
  {
    this->numRowsInLeaderboard = callback->numRowsInLeaderboard;
    localIndex = callback->localIndex;
    if ( localIndex != -1 )
      this->localIndex = callback->startIndex + localIndex;
    if ( loadingNewLeaderboard )
    {
      v8 = callback->localIndex;
      if ( v8 != -1 )
      {
        filter = this->filter;
        if ( filter == LEADERBOARD_FILTER_MYSCORE || filter == LEADERBOARD_FILTER_FRIENDS )
        {
          startIndex = callback->startIndex;
          this->entryIndex = 0;
          this->rowOffset = startIndex + v8;
          idLBCache::Scroll(this, amount: -6);
          this->entryIndex = callback->startIndex - this->rowOffset + callback->localIndex;
        }
      }
      this->loadingNewLeaderboard = false;
    }
    FreeRowBlock = idLBCache::FindFreeRowBlock(this);
    FreeRowBlock->rowBlocks[0].lastTime = Sys_Milliseconds();
    FreeRowBlock->rowBlocks[0].startIndex = callback->startIndex;
    idList<idLeaderboardCallback::row_t,5>::operator=(this: &FreeRowBlock->rowBlocks[0].rows, other: &callback->rows);
  }
  else
  {
    idLib::Printf(fmt: "Wrong leaderboard.\n");
    this->numRowsInLeaderboard = 0;
    this->loadingNewLeaderboard = false;
  }
}


// ========================================================================
// ??0RageLeaderboardCallback@@QAA@XZ
// EA  : 0x82D9E2F8
// RVA : 0x00D9E2F8
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

RageLeaderboardCallback *__fastcall RageLeaderboardCallback::RageLeaderboardCallback(RageLeaderboardCallback *this)
{
  this->def = nullptr;
  this->startIndex = -1;
  this->localIndex = -1;
  this->rows.granularity = 0;
  this->rows.memTag = 5;
  this->rows.listStatic = 0;
  this->rows.list = nullptr;
  this->rows.size = 0;
  this->rows.num = 0;
  this->numRowsInLeaderboard = -1;
  this->errorCode = LEADERBOARD_ERROR_NONE;
  this->__vftable = (RageLeaderboardCallback_vtbl *)&RageLeaderboardCallback::`vftable';
  return this;
}


// ========================================================================
// __unwind$488716
// EA  : 0x82D9E35C
// RVA : 0x00D9E35C
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void _unwind_488716()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: *(idCallback **)(v0 - 32 + 52));
}


// ========================================================================
// ?Call@RageLeaderboardCallback@@UAAXXZ
// EA  : 0x82D9E388
// RVA : 0x00D9E388
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void __fastcall RageLeaderboardCallback::Call(RageLeaderboardCallback *this)
{
  if ( gameLocal != nullptr )
    idMainMenu::UpdateLeaderboard(this: gameLocal->mainMenu, callback: this);
}


// ========================================================================
// ?SetLeaderboard@idLBCache@@QAAXPBUleaderboardDefinition_t@@W4leaderboardFilterMode_t@@@Z
// EA  : 0x82D9E420
// RVA : 0x00D9E420
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void __fastcall idLBCache::SetLeaderboard(
        idLBCache *this,
        const leaderboardDefinition_t *def_,
        leaderboardFilterMode_t filter_)
{
  idLeaderboardCallback v6; // [sp+50h] [-B0h] BYREF
  idLeaderboardCallback v7; // [sp+80h] [-80h] BYREF
  idLeaderboardCallback v8[2]; // [sp+B0h] [-50h] BYREF

  if ( this->loadingNewLeaderboard || this->requestingRows )
  {
    this->pendingDef = def_;
    this->pendingFilter = filter_;
  }
  else
  {
    idLBCache::Reset(this);
    this->filter = filter_;
    this->loadingNewLeaderboard = true;
    this->localIndex = -1;
    this->def = def_;
    if ( filter_ == LEADERBOARD_FILTER_MYSCORE )
    {
      RageLeaderboardCallback::RageLeaderboardCallback(this: (RageLeaderboardCallback *)&v6);
      session->LeaderboardDownload(this: session, a2: 0, a3: this->def, a4: 0, a5: 50, a6: &v6);
      idLeaderboardCallback::~idLeaderboardCallback(this: &v6);
    }
    else if ( filter_ == LEADERBOARD_FILTER_FRIENDS )
    {
      RageLeaderboardCallback::RageLeaderboardCallback(this: (RageLeaderboardCallback *)&v7);
      session->LeaderboardDownload(this: session, a2: 0, a3: this->def, a4: -1, a5: 100, a6: &v7);
      idLeaderboardCallback::~idLeaderboardCallback(this: &v7);
    }
    else
    {
      RageLeaderboardCallback::RageLeaderboardCallback(this: (RageLeaderboardCallback *)v8);
      session->LeaderboardDownload(this: session, a2: 0, a3: this->def, a4: this->rowOffset + 1, a5: 50, a6: v8);
      idLeaderboardCallback::~idLeaderboardCallback(this: v8);
    }
  }
}


// ========================================================================
// __unwind$488824_0
// EA  : 0x82D9E554
// RVA : 0x00D9E554
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void _unwind_488824_0()
{
  int v0; // r12

  fakeLeaderboardCallback::~fakeLeaderboardCallback(this: (fakeLeaderboardCallback *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$488825_0
// EA  : 0x82D9E57C
// RVA : 0x00D9E57C
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void _unwind_488825_0()
{
  int v0; // r12

  fakeLeaderboardCallback::~fakeLeaderboardCallback(this: (fakeLeaderboardCallback *)(v0 - 256 + 128));
}


// ========================================================================
// __unwind$488826
// EA  : 0x82D9E5A4
// RVA : 0x00D9E5A4
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void _unwind_488826()
{
  int v0; // r12

  fakeLeaderboardCallback::~fakeLeaderboardCallback(this: (fakeLeaderboardCallback *)(v0 - 256 + 176));
}


// ========================================================================
// ?CycleFilter@idLBCache@@QAAXXZ
// EA  : 0x82D9E5D0
// RVA : 0x00D9E5D0
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void __fastcall idLBCache::CycleFilter(idLBCache *this)
{
  leaderboardFilterMode_t filter; // r11

  filter = this->filter;
  if ( filter != LEADERBOARD_FILTER_OVERALL )
    this->filter = filter != LEADERBOARD_FILTER_MYSCORE ? LEADERBOARD_FILTER_OVERALL : LEADERBOARD_FILTER_FRIENDS;
  else
    this->filter = LEADERBOARD_FILTER_MYSCORE;
  idLBCache::SetLeaderboard(this, def_: this->def, filter_: this->filter);
}


// ========================================================================
// ?GetLeaderboardRow@idLBCache@@QAAPBUrow_t@idLeaderboardCallback@@H@Z
// EA  : 0x82D9E618
// RVA : 0x00D9E618
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

const idLeaderboardCallback::row_t *__fastcall idLBCache::GetLeaderboardRow(idLBCache *this, int row)
{
  int *p_num; // r11
  int i; // r9
  int v5; // r30
  const leaderboardDefinition_t *def; // r5
  idLBRowBlock *v8; // r29
  unsigned int v9; // r3
  idLeaderboardCallback::row_t *list; // r10
  idLeaderboardCallback v11[2]; // [sp+50h] [-50h] BYREF

  if ( !this->loadingNewLeaderboard && row < this->numRowsInLeaderboard )
  {
    p_num = &this->rowBlocks[0].rows.num;
    for ( i = 0; i < 5; ++i )
    {
      v5 = *(p_num - 2);
      if ( row >= v5 && row <= *p_num + v5 - 1 )
      {
        v8 = &this->rowBlocks[i];
        v9 = Sys_Milliseconds();
        list = v8->rows.list;
        v8->lastTime = v9;
        return &list[row - v5];
      }
      p_num += 6;
    }
    if ( !this->requestingRows )
    {
      v11[0].def = nullptr;
      v11[0].rows.granularity = 0;
      v11[0].startIndex = -1;
      v11[0].localIndex = -1;
      v11[0].rows.memTag = 5;
      v11[0].rows.listStatic = 0;
      v11[0].rows.list = nullptr;
      v11[0].rows.size = 0;
      v11[0].rows.num = 0;
      v11[0].numRowsInLeaderboard = -1;
      v11[0].errorCode = LEADERBOARD_ERROR_NONE;
      v11[0].__vftable = (idLeaderboardCallback_vtbl *)&RageLeaderboardCallback::`vftable';
      def = this->def;
      this->requestingRows = true;
      session->LeaderboardDownload(this: session, a2: 0, a3: def, a4: row + 1, a5: 50, a6: v11);
      idLeaderboardCallback::~idLeaderboardCallback(this: v11);
    }
  }
  return nullptr;
}


// ========================================================================
// __unwind$488883
// EA  : 0x82D9E748
// RVA : 0x00D9E748
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void _unwind_488883()
{
  int v0; // r12

  idCallbackBindMem<idMainMenu>::~idCallbackBindMem<idMainMenu>(this: (idCallback *)(v0 - 160 + 80));
}


// ========================================================================
// __unwind$488872
// EA  : 0x82D9E770
// RVA : 0x00D9E770
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void _unwind_488872()
{
  int v0; // r12

  fakeLeaderboardCallback::~fakeLeaderboardCallback(this: (fakeLeaderboardCallback *)(v0 - 160 + 80));
}


// ========================================================================
// ??0idLBCache@@QAA@XZ
// EA  : 0x82D9E798
// RVA : 0x00D9E798
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

idLBCache *__fastcall idLBCache::idLBCache(idLBCache *this)
{
  `eh vector constructor iterator'(
    ptr: this,
    size: 0x18u,
    count: 5,
    pCtor: (void (__fastcall *)(void *))idLBRowBlock::idLBRowBlock,
    pDtor: (void (__fastcall *)(void *))idLBRowBlock::~idLBRowBlock);
  this->def = nullptr;
  this->filter = LEADERBOARD_FILTER_OVERALL;
  this->pendingDef = nullptr;
  this->pendingFilter = LEADERBOARD_FILTER_OVERALL;
  this->requestingRows = false;
  this->loadingNewLeaderboard = false;
  this->numRowsInLeaderboard = 0;
  this->entryIndex = 0;
  this->rowOffset = 0;
  this->localIndex = -1;
  this->errorCode = LEADERBOARD_DISPLAY_ERROR_NONE;
  return this;
}


// ========================================================================
// ?Pump@idLBCache@@QAAXXZ
// EA  : 0x82D9E818
// RVA : 0x00D9E818
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void __fastcall idLBCache::Pump(idLBCache *this)
{
  const leaderboardDefinition_t *pendingDef; // r4

  if ( !this->loadingNewLeaderboard && !this->requestingRows )
  {
    pendingDef = this->pendingDef;
    if ( pendingDef != nullptr )
      idLBCache::SetLeaderboard(this, def_: pendingDef, filter_: this->pendingFilter);
  }
}


// ========================================================================
// ?Clone@RageLeaderboardCallback@@UBAPAV1@XZ
// EA  : 0x82D9E850
// RVA : 0x00D9E850
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

RageLeaderboardCallback *__fastcall RageLeaderboardCallback::Clone(RageLeaderboardCallback *this)
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
  *v3 = &RageLeaderboardCallback::`vftable';
  return (RageLeaderboardCallback *)v3;
}


// ========================================================================
// __unwind$489000
// EA  : 0x82D9E8C4
// RVA : 0x00D9E8C4
// PDB : w:\tech5\tungsten\game\lbcache.cpp
// ========================================================================

void __fastcall _unwind_489000(int a1, memTag_t a2)
{
  int v2; // r12

  operator delete(p: *(void **)(v2 - 128 + 80), tag: a2);
}

