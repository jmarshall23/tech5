
// ========================================================================
// ?JoinFromConnectInfo@idLobbyBackendDirect@@UAAXABUlobbyConnectInfo_t@@@Z
// EA  : 0x829B2970
// RVA : 0x009B2970
// PDB : w:\tech5\engine\sys\sys_lobby_backend_direct.cpp
// ========================================================================

void __fastcall idLobbyBackendDirect::JoinFromConnectInfo(
        idLobbyBackendDirect *this,
        const lobbyConnectInfo_t *connectInfo)
{
  const char *v3; // r3

  this->address = connectInfo->netAddr;
  v3 = Sys_NetAdrToString(a: *(const netadr_t **)connectInfo->netAddr.ip);
  idLib::Printf(fmt: "JoinFromConnectInfo %s\n", v3);
  this->isLocal = false;
  this->state = STATE_READY;
  this->isHost = false;
}


// ========================================================================
// ?Shutdown@idLobbyBackendDirect@@UAAXXZ
// EA  : 0x829B29E8
// RVA : 0x009B29E8
// PDB : w:\tech5\engine\sys\sys_lobby_backend_direct.cpp
// ========================================================================

void __fastcall idLobbyBackendDirect::Shutdown(idLobbyBackendDirect *this)
{
  this->state = STATE_SHUTDOWN;
}


// ========================================================================
// ?FinishBecomeHost@idLobbyBackendDirect@@UAAXXZ
// EA  : 0x829B29F8
// RVA : 0x009B29F8
// PDB : w:\tech5\engine\sys\sys_lobby_backend_direct.cpp
// ========================================================================

void __fastcall idLobbyBackendDirect::FinishBecomeHost(idLobbyBackendDirect *this)
{
  this->isHost = true;
}


// ========================================================================
// ?GetOwnerAddress@idLobbyBackendDirect@@UAAXAAVlobbyAddress_t@@@Z
// EA  : 0x829B2A08
// RVA : 0x009B2A08
// PDB : w:\tech5\engine\sys\sys_lobby_backend_direct.cpp
// ========================================================================

void __fastcall idLobbyBackendDirect::GetOwnerAddress(idLobbyBackendDirect *this, lobbyAddress_t *outAddr)
{
  lobbyAddress_t::InitFromNetadr(this: outAddr, netadr: &this->address);
  this->state = STATE_READY;
}


// ========================================================================
// ?IsOwnerOfConnectInfo@idLobbyBackendDirect@@UBA_NABUlobbyConnectInfo_t@@@Z
// EA  : 0x829B2A48
// RVA : 0x009B2A48
// PDB : w:\tech5\engine\sys\sys_lobby_backend_direct.cpp
// ========================================================================

BOOL __fastcall idLobbyBackendDirect::IsOwnerOfConnectInfo(
        idLobbyBackendDirect *this,
        const lobbyConnectInfo_t *connectInfo)
{
  if ( !connectInfo->usingBackendPlatform )
    return Sys_CompareNetAdrBase(
             a: *(const netadr_t **)this->address.ip,
             b: (const netadr_t *)__ROL4__(*(_DWORD *)&this->address.port, 32));
  idLib::Printf(fmt: "idLobbyBackendDirect::IsOwnerOfConnectInfo: Invalid connectInfo\n");
  return false;
}


// ========================================================================
// ?StartHosting@idLobbyBackendDirect@@UAAXABVidMatchParameters@@MW4lobbyBackendType_t@idLobbyBackend@@@Z
// EA  : 0x829B2AB0
// RVA : 0x009B2AB0
// PDB : w:\tech5\engine\sys\sys_lobby_backend_direct.cpp
// ========================================================================

void __fastcall idLobbyBackendDirect::StartHosting(
        idLobbyBackendDirect *this,
        const idMatchParameters *p,
        double skillLevel,
        idLobbyBackend::lobbyBackendType_t type)
{
  if ( net_verbose.valueInteger != 0 )
    idLib::Printf(fmt: "idLobbyBackendDirect::StartHosting\n", p, type, skillLevel);
  this->isHost = true;
  this->state = STATE_READY;
  this->isLocal = true;
}


// ========================================================================
// ?StartFinding@idLobbyBackendDirect@@UAAXABVidMatchParameters@@HM@Z
// EA  : 0x829B2B08
// RVA : 0x009B2B08
// PDB : w:\tech5\engine\sys\sys_lobby_backend_direct.cpp
// ========================================================================

void __fastcall idLobbyBackendDirect::StartFinding(
        idLobbyBackendDirect *this,
        const idMatchParameters *p,
        int numPartyUsers,
        double skillLevel)
{
  int matchFlags; // r8
  bool v6; // r3
  idLobbyBackend::lobbyBackendState_t v7; // r11

  matchFlags = p->matchFlags;
  this->isHost = false;
  this->isLocal = (~matchFlags & 2) != 0;
  v6 = lobbyToSessionCB->CanJoinLocalHost(this: lobbyToSessionCB);
  v7 = STATE_READY;
  if ( !v6 )
    v7 = 8;
  this->state = v7;
}


// ========================================================================
// ?GetConnectInfo@idLobbyBackendDirect@@UAA?AUlobbyConnectInfo_t@@XZ
// EA  : 0x829B2B78
// RVA : 0x009B2B78
// PDB : w:\tech5\engine\sys\sys_lobby_backend_direct.cpp
// ========================================================================

idLobbyBackendDirect *__fastcall idLobbyBackendDirect::GetConnectInfo(
        idLobbyBackendDirect *this,
        lobbyConnectInfo_t *result)
{
  int v4; // r11
  const char *started; // r3
  const char *v6; // r3
  netadrtype_t type; // r9
  int v8; // r8
  int v10; // r7

  memset(Dst: this, Val: 0, Size: 0x3Cu);
  v4 = *(_DWORD *)result->sessionInfo.sessionID.ab;
  *(_DWORD *)this->parms.mapName.buffer = 0;
  *(_DWORD *)&this->parms.mapName.buffer[4] = 0;
  *(_DWORD *)&this->parms.mapName.buffer[8] = 0;
  if ( (*(unsigned __int8 (__fastcall **)(lobbyConnectInfo_t *))(v4 + 40))(a1: result) != 0 )
  {
    started = (const char *)idLobbyBackend360::StartArbitration(pexcept: nullptr);
    Sys_StringToNetAdr(s: started, a: &result[61].netAddr, doDNSResolve: false);
    result[61].netAddr.port = net_port.valueInteger;
  }
  v6 = Sys_NetAdrToString(a: *(const netadr_t **)result[61].netAddr.ip);
  idLib::Printf(fmt: "GetConnectInfo %s\n", v6);
  type = result[61].netAddr.type;
  v8 = *(_DWORD *)result[61].netAddr.ip;
  v10 = *(_DWORD *)&result[61].netAddr.port;
  this->parms.mapName.baseBuffer[16] = 0;
  *(_DWORD *)this->parms.mapName.buffer = type;
  *(_DWORD *)&this->parms.mapName.buffer[4] = v8;
  *(_DWORD *)&this->parms.mapName.buffer[8] = v10;
  return this;
}


// ========================================================================
// ??0idLobbyBackendDirect@@QAA@XZ
// EA  : 0x829B2DD8
// RVA : 0x009B2DD8
// PDB : w:\tech5\engine\sys\sys_lobby_backend_direct.cpp
// ========================================================================

idLobbyBackendDirect *__fastcall idLobbyBackendDirect::idLobbyBackendDirect(idLobbyBackendDirect *this)
{
  this->type = TYPE_INVALID;
  this->__vftable = (idLobbyBackendDirect_vtbl *)&idLobbyBackend::`vftable';
  idMatchParameters::idMatchParameters(this: &this->parms);
  this->isLocal = false;
  this->__vftable = (idLobbyBackendDirect_vtbl *)&idLobbyBackendDirect::`vftable';
  this->isHost = false;
  this->state = STATE_INVALID;
  return this;
}


// ========================================================================
// ?GetSearchResults@idLobbyBackendDirect@@UAAXAAV?$idList@UlobbyConnectInfo_t@@$04@@@Z
// EA  : 0x829B2E48
// RVA : 0x009B2E48
// PDB : w:\tech5\engine\sys\sys_lobby_backend_direct.cpp
// ========================================================================

void __fastcall idLobbyBackendDirect::GetSearchResults(
        idLobbyBackendDirect *this,
        idList<idVehicleState *,5> *searchResults)
{
  char *v2; // r11
  int i; // ctr
  char v5; // [sp+48h] [-68h] BYREF
  lobbyConnectInfo_t v6; // [sp+50h] [-60h] BYREF

  v2 = &v5;
  for ( i = 7; i != 0; --i )
  {
    v2 += 8;
    *(_QWORD *)v2 = 0x700000000LL;
  }
  *((_DWORD *)v2 + 2) = 0;
  memset(&v6.netAddr, 0, sizeof(v6.netAddr));
  idList<idThread *,58>::Clear(this: searchResults);
  idList<lobbyConnectInfo_t,5>::Append(this: (idList<lobbyConnectInfo_t,5> *)searchResults, obj: &v6);
}

