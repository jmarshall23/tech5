
// ========================================================================
// ?GetAddrAtIndex@idDedicatedServerSearch@@QAA_NAAUnetadr_t@@H@Z
// EA  : 0x829A22D0
// RVA : 0x009A22D0
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

int __fastcall idDedicatedServerSearch::GetAddrAtIndex(idDedicatedServerSearch *this, netadr_t *addr, int i)
{
  idDedicatedServerSearch::serverInfoDedicated_t *v3; // r11
  int v5; // r9
  int v6; // r8

  if ( i < 0 || i >= this->list.num )
    return 0;
  v3 = &this->list.list[i];
  v5 = *(_DWORD *)v3->addr.netAddr.ip;
  v6 = *(_DWORD *)&v3->addr.netAddr.port;
  addr->type = v3->addr.netAddr.type;
  *(_DWORD *)addr->ip = v5;
  *(_DWORD *)&addr->port = v6;
  return 1;
}


// ========================================================================
// ?DescribeServerAtIndex@idDedicatedServerSearch@@QBAPBUserverInfo_t@@H@Z
// EA  : 0x829A2318
// RVA : 0x009A2318
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

const serverInfo_t *__fastcall idDedicatedServerSearch::DescribeServerAtIndex(idDedicatedServerSearch *this, int i)
{
  if ( i < 0 || i >= this->list.num )
    return nullptr;
  else
    return &this->list.list[i].serverInfo;
}


// ========================================================================
// ?GetServerPlayersAtIndex@idDedicatedServerSearch@@QBAPBV?$idList@VidStr@@$04@@H@Z
// EA  : 0x829A2348
// RVA : 0x009A2348
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

const idList<idStr,5> *__fastcall idDedicatedServerSearch::GetServerPlayersAtIndex(
        idDedicatedServerSearch *this,
        int i)
{
  if ( i < 0 || i >= this->list.num )
    return nullptr;
  else
    return &this->list.list[i].connectedPlayers;
}


// ========================================================================
// ?Clear@idDedicatedServerSearch@@QAAXXZ
// EA  : 0x829A2AC8
// RVA : 0x009A2AC8
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

void __fastcall idDedicatedServerSearch::Clear(idDedicatedServerSearch *this)
{
  idCallback *callback; // r3

  callback = this->callback;
  if ( callback != nullptr )
  {
    ((void (__fastcall *)(idCallback *, int))callback->dtr_idCallback)(a1: callback, a2: 1);
    this->callback = nullptr;
  }
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    if ( this->list.list != nullptr )
      idListArrayDelete<idDedicatedServerSearch::serverInfoDedicated_t>(
        ptr: (char *)&this->list.list->addr.usingBackendPlatform,
        num: this->list.size);
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// ??1idDedicatedServerSearch@@QAA@XZ
// EA  : 0x829A2CD8
// RVA : 0x009A2CD8
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

void __fastcall idDedicatedServerSearch::~idDedicatedServerSearch(idDedicatedServerSearch *this)
{
  idCallback *callback; // r3

  callback = this->callback;
  if ( callback != nullptr )
    ((void (__fastcall *)(idCallback *, int))callback->dtr_idCallback)(a1: callback, a2: 1);
  if ( this->list.listStatic == 0 || this->list.listStatic == 2 )
  {
    if ( this->list.list != nullptr )
      idListArrayDelete<idDedicatedServerSearch::serverInfoDedicated_t>(
        ptr: (char *)&this->list.list->addr.usingBackendPlatform,
        num: this->list.size);
    this->list.list = nullptr;
    this->list.size = 0;
  }
  this->list.num = 0;
}


// ========================================================================
// __unwind$221007
// EA  : 0x829A2D74
// RVA : 0x009A2D74
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

void _unwind_221007()
{
  int v0; // r12

  idList<idDedicatedServerSearch::serverInfoDedicated_t,5>::~idList<idDedicatedServerSearch::serverInfoDedicated_t,5>(this: *(idList<idDedicatedServerSearch::serverInfoDedicated_t,5> **)(v0 - 112 + 132));
}


// ========================================================================
// ?StartSearch@idDedicatedServerSearch@@QAAXABVidCallback@@@Z
// EA  : 0x829A2DA0
// RVA : 0x009A2DA0
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

void __fastcall idDedicatedServerSearch::StartSearch(idDedicatedServerSearch *this, const idCallback *cb)
{
  idDedicatedServerSearch::Clear(this);
  this->callback = cb->Clone(this: cb);
}


// ========================================================================
// ?HandleQueryAck@idDedicatedServerSearch@@QAAXAAVlobbyAddress_t@@AAVidBitMsg@@@Z
// EA  : 0x829A2DF8
// RVA : 0x009A2DF8
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

void __fastcall idDedicatedServerSearch::HandleQueryAck(
        idDedicatedServerSearch *this,
        lobbyAddress_t *addr,
        idBitMsg *msg)
{
  char v6; // r22
  int v7; // r27
  int v8; // r29
  idDedicatedServerSearch::serverInfoDedicated_t *v9; // r30
  idStr **p_list; // r27
  int i; // r29
  const char *v12; // r3
  int v13; // r30
  idStr *list; // r29
  int size; // r30
  idStr *v16; // r28
  idCallback *callback; // r11
  idStr v18; // [sp+50h] [-120h] BYREF
  idStr v19; // [sp+70h] [-100h] BYREF
  idDedicatedServerSearch::serverInfoDedicated_t v20; // [sp+90h] [-E0h] BYREF

  v6 = 0;
  v7 = 0;
  if ( this->list.num > 0 )
  {
    v8 = 0;
    while ( 1 )
    {
      v9 = &this->list.list[v8];
      if ( lobbyAddress_t::Compare(this: &v9->addr, addr, ignoreSessionCheck: false) )
        break;
      ++v7;
      ++v8;
      if ( v7 >= this->list.num )
        goto LABEL_15;
    }
    v6 = 1;
    if ( (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0 )
    {
      v9->serverInfo.joinable = -1 - ((idBitMsg::ReadBits(this: msg, numBits: 1) == 1) - 2);
      idBitMsg::ReadString(this: msg, str: &v9->serverInfo.name);
      v9->serverInfo.type = idBitMsg::ReadBits(this: msg, numBits: 32);
      v9->serverInfo.map = idBitMsg::ReadBits(this: msg, numBits: 32);
      v9->serverInfo.mode = idBitMsg::ReadBits(this: msg, numBits: 32);
      v9->serverInfo.numPlayers = idBitMsg::ReadBits(this: msg, numBits: 32);
      v9->serverInfo.maxPlayers = idBitMsg::ReadBits(this: msg, numBits: 32);
      p_list = &v9->connectedPlayers.list;
      if ( v9->connectedPlayers.listStatic == 0 || v9->connectedPlayers.listStatic == 2 )
      {
        if ( *p_list != nullptr )
          idListArrayDelete<idStr>(ptr: *p_list, num: v9->connectedPlayers.size);
        *p_list = nullptr;
        v9->connectedPlayers.size = 0;
      }
      v9->connectedPlayers.num = 0;
      for ( i = 0; i < v9->serverInfo.numPlayers; ++i )
      {
        v19.allocedAndFlag = 20;
        v19.len = 0;
        v19.data = v19.baseBuffer;
        v19.baseBuffer[0] = 0;
        idBitMsg::ReadString(this: msg, str: &v19);
        idList<idStr,5>::Append(this: &v9->connectedPlayers, obj: &v19);
        idStr::FreeData(this: &v19);
      }
    }
    else
    {
      idList<idDedicatedServerSearch::serverInfoDedicated_t,5>::RemoveIndex(this: &this->list, index: v7);
    }
  }
LABEL_15:
  if ( v6 == 0 && (_cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1) & 0x20) != 0 )
  {
    idDedicatedServerSearch::serverInfoDedicated_t::serverInfoDedicated_t(this: &v20);
    v20.addr = *addr;
    v20.serverInfo.joinable = -1 - ((idBitMsg::ReadBits(this: msg, numBits: 1) == 1) - 2);
    idBitMsg::ReadString(this: msg, str: &v20.serverInfo.name);
    if ( idStr::Find(
           searchIn: v20.serverInfo.name.data,
           searchFor: "HeadlessServer",
           casesensitive: true,
           start: 0,
           end: v20.serverInfo.name.len) != -1 )
    {
      v12 = lobbyAddress_t::ToString(this: addr);
      idStr::operator=(this: &v20.serverInfo.name, text: v12);
    }
    v20.serverInfo.type = idBitMsg::ReadBits(this: msg, numBits: 32);
    v20.serverInfo.map = idBitMsg::ReadBits(this: msg, numBits: 32);
    v20.serverInfo.mode = idBitMsg::ReadBits(this: msg, numBits: 32);
    v20.serverInfo.numPlayers = idBitMsg::ReadBits(this: msg, numBits: 32);
    v20.serverInfo.maxPlayers = idBitMsg::ReadBits(this: msg, numBits: 32);
    if ( v20.connectedPlayers.listStatic == 0 || v20.connectedPlayers.listStatic == 2 )
    {
      if ( v20.connectedPlayers.list != nullptr )
        idListArrayDelete<idStr>(ptr: v20.connectedPlayers.list, num: v20.connectedPlayers.size);
      v20.connectedPlayers.list = nullptr;
      v20.connectedPlayers.size = 0;
    }
    v13 = 0;
    for ( v20.connectedPlayers.num = 0; v13 < v20.serverInfo.numPlayers; ++v13 )
    {
      v18.allocedAndFlag = 20;
      v18.len = 0;
      v18.data = v18.baseBuffer;
      v18.baseBuffer[0] = 0;
      idBitMsg::ReadString(this: msg, str: &v18);
      idList<idStr,5>::Append(this: &v20.connectedPlayers, obj: &v18);
      idStr::FreeData(this: &v18);
    }
    idList<idDedicatedServerSearch::serverInfoDedicated_t,5>::Append(this: &this->list, obj: &v20);
    if ( v20.connectedPlayers.listStatic == 0 || v20.connectedPlayers.listStatic == 2 )
    {
      list = v20.connectedPlayers.list;
      if ( v20.connectedPlayers.list != nullptr )
      {
        size = v20.connectedPlayers.size;
        v16 = v20.connectedPlayers.list;
        if ( v20.connectedPlayers.size > 0 )
        {
          do
          {
            idStr::FreeData(this: list);
            --size;
            ++list;
          }
          while ( size != 0 );
        }
        idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
      }
      v20.connectedPlayers.list = nullptr;
      v20.connectedPlayers.size = 0;
    }
    v20.connectedPlayers.num = 0;
    idStr::FreeData(this: &v20.serverInfo.name);
  }
  callback = this->callback;
  if ( callback != nullptr )
    ((void (*)(void))callback->Call)();
}


// ========================================================================
// __unwind$221046
// EA  : 0x829A31C4
// RVA : 0x009A31C4
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

void _unwind_221046()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 112));
}


// ========================================================================
// __unwind$221047
// EA  : 0x829A31EC
// RVA : 0x009A31EC
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

void _unwind_221047()
{
  int v0; // r12

  idDedicatedServerSearch::serverInfoDedicated_t::~serverInfoDedicated_t(this: (idDedicatedServerSearch::serverInfoDedicated_t *)(v0 - 368 + 144));
}


// ========================================================================
// __unwind$221048
// EA  : 0x829A3214
// RVA : 0x009A3214
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

void _unwind_221048()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 80));
}


// ========================================================================
// __unwind$221167
// EA  : 0x829A323C
// RVA : 0x009A323C
// PDB : w:\tech5\engine\sys\sys_dedicated_server_search.cpp
// ========================================================================

void _unwind_221167()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 368 + 204));
}

