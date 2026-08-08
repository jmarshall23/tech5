
// ========================================================================
// ?CallAndDeleteCallback@id360ServerFinder@@QAAXXZ
// EA  : 0x829DE550
// RVA : 0x009DE550
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.h
// ========================================================================

void __fastcall id360ServerFinder::CallAndDeleteCallback(id360ServerFinder *this)
{
  idCallback *callback; // r31
  idCallback *v3; // r3

  callback = this->callback;
  if ( callback != nullptr )
  {
    v3 = this->callback;
    this->callback = nullptr;
    callback->Call(this: v3);
    ((void (__fastcall *)(idCallback *, int))callback->dtr_idCallback)(a1: callback, a2: 1);
  }
}


// ========================================================================
// ?Start@idSessionFinder@@QAA_NKPAUXNKID@@H@Z
// EA  : 0x829DE8D0
// RVA : 0x009DE8D0
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.h
// ========================================================================

BOOL __fastcall idSessionFinder::Start(
        idSessionFinder *this,
        unsigned int user,
        XNKID *sessionIDs,
        unsigned int numSessionIDs)
{
  unsigned int *p_searchResultBufferSize; // r30
  unsigned int v10; // r3
  _XSESSION_SEARCHRESULT_HEADER *v11; // r3
  size_t v12; // r5

  if ( numSessionIDs == 0 )
    return false;
  p_searchResultBufferSize = &this->searchResultBufferSize;
  v10 = XSessionSearchByIds(
          cSessionIds: numSessionIDs,
          rgSessionIds: sessionIDs,
          dwUserIndex: user,
          pcbResultsBuffer: &this->searchResultBufferSize,
          pSearchResults: nullptr,
          pXOverlapped: nullptr);
  if ( v10 == 122 )
  {
    if ( *p_searchResultBufferSize == 0 )
      return false;
    v11 = (_XSESSION_SEARCHRESULT_HEADER *)idMem::AllocWithLocation(
                                             this: &mem,
                                             location: "w:\\tech5\\shared\\idlib\\Heap.h(46) : TAG_NEW",
                                             size: *p_searchResultBufferSize,
                                             tag: TAG_NEW,
                                             zeroBuffer: false,
                                             align: ALIGN_16,
                                             heap: HEAP_DEFAULTHEAP);
    v12 = *p_searchResultBufferSize;
    this->searchResultsBuffer = v11;
    memset(Dst: v11, Val: 0, Size: v12);
    v10 = XSessionSearchByIds(
            cSessionIds: numSessionIDs,
            rgSessionIds: sessionIDs,
            dwUserIndex: user,
            pcbResultsBuffer: &this->searchResultBufferSize,
            pSearchResults: this->searchResultsBuffer,
            pXOverlapped: &this->overlapped);
  }
  return v10 == 997;
}


// ========================================================================
// ??0friendGameQuery_t@id360FriendsServerFinder@@QAA@XZ
// EA  : 0x829DEA50
// RVA : 0x009DEA50
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.h
// ========================================================================

id360FriendsServerFinder::friendGameQuery_t *__fastcall id360FriendsServerFinder::friendGameQuery_t::friendGameQuery_t(
        id360FriendsServerFinder::friendGameQuery_t *this)
{
  this->serverInfo.name.len = 0;
  this->serverInfo.name.allocedAndFlag = 20;
  this->serverInfo.name.data = this->serverInfo.name.baseBuffer;
  this->serverInfo.name.baseBuffer[0] = 0;
  this->serverInfo.map = -1;
  this->serverInfo.type = -1;
  this->serverInfo.mode = -1;
  this->serverInfo.joinable = true;
  this->serverInfo.numPlayers = -1;
  this->serverInfo.maxPlayers = -1;
  *(_QWORD *)this->szGamertag = 0xFFFFFFFF00000000uLL;
  *(_QWORD *)&this->szGamertag[8] = 0xFFFFFFFF00000000uLL;
  this->sessionID = (XNKID)0xFFFFFFFF00000000uLL;
  this->acked = false;
  this->xuid = 0xFFFFFFFF00000000uLL;
  return this;
}


// ========================================================================
// ??1id360ServerFinder@@UAA@XZ
// EA  : 0x829E0720
// RVA : 0x009E0720
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.h
// ========================================================================

void __fastcall id360ServerFinder::~id360ServerFinder(id360ServerFinder *this)
{
  idCallback *callback; // r30

  this->__vftable = (id360ServerFinder_vtbl *)&id360ServerFinder::`vftable';
  callback = this->callback;
  if ( callback != nullptr )
  {
    this->callback = nullptr;
    callback->Call(this: callback);
    ((void (__fastcall *)(idCallback *, int))callback->dtr_idCallback)(a1: callback, a2: 1);
  }
  idStaticList<idServerQuery::serverQueryInfo_t,32>::~idStaticList<idServerQuery::serverQueryInfo_t,32>(this: &this->serverQuery.servers);
}


// ========================================================================
// __unwind$226632
// EA  : 0x829E0798
// RVA : 0x009E0798
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.h
// ========================================================================

void _unwind_226632()
{
  int v0; // r12

  idServerQuery::~idServerQuery(this: (idServerQuery *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// ?GetServerInfo@id360ServerBrowserFinder@@UAAPBUserverInfo_t@@H@Z
// EA  : 0x829E0A60
// RVA : 0x009E0A60
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.h
// ========================================================================

const serverInfo_t *__fastcall id360ServerBrowserFinder::GetServerInfo(id360ServerBrowserFinder *this, int index)
{
  int v4; // r3
  char v5; // r11

  if ( index < 0 || (v4 = this->NumServers(this), v5 = 1, index >= v4) )
    v5 = 0;
  if ( v5 != 0 )
    return &this->serverQuery.servers.list[index].serverInfo;
  else
    return nullptr;
}


// ========================================================================
// ?GetServerSessionInfo@id360ServerBrowserFinder@@UAA_NHAAU_XSESSION_INFO@@@Z
// EA  : 0x829E0AE0
// RVA : 0x009E0AE0
// PDB : w:\tech5\engine\sys\xenon\xen_server_finder.h
// ========================================================================

int __fastcall id360ServerBrowserFinder::GetServerSessionInfo(
        id360ServerBrowserFinder *this,
        int index,
        _XSESSION_INFO *outInfo)
{
  int v6; // r3
  char v7; // r11

  if ( index < 0 || (v6 = this->NumServers(this), v7 = 1, index >= v6) )
    v7 = 0;
  if ( v7 == 0 )
    return 0;
  memcpy(Dst: outInfo, Src: &this->serverQuery.servers.list[index], Size: sizeof(_XSESSION_INFO));
  return 1;
}

