
// ========================================================================
// ?WriteToMsg@lobbyConnectInfo_t@@QBAXAAVidBitMsg@@@Z
// EA  : 0x829A5310
// RVA : 0x009A5310
// PDB : w:\tech5\engine\sys\sys_lobby_backend.h
// ========================================================================

void __fastcall lobbyConnectInfo_t::WriteToMsg(lobbyConnectInfo_t *this, idBitMsg *msg)
{
  idBitMsg::WriteBits(this: msg, value: this->usingBackendPlatform, numBits: 1);
  if ( this->usingBackendPlatform )
    idBitMsg::WriteData(this: msg, data: this, length: 60);
  else
    idBitMsg::WriteNetadr(this: (idBitMsg *)this->netAddr.type, adr: *(const netadr_t **)this->netAddr.ip);
}


// ========================================================================
// ?ReadFromMsg@lobbyConnectInfo_t@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829A5388
// RVA : 0x009A5388
// PDB : w:\tech5\engine\sys\sys_lobby_backend.h
// ========================================================================

void __fastcall lobbyConnectInfo_t::ReadFromMsg(lobbyConnectInfo_t *this, idBitMsg *msg)
{
  char v4; // r10

  v4 = _cntlzw(idBitMsg::ReadBits(this: msg, numBits: 1) - 1);
  this->usingBackendPlatform = (v4 & 0x20) != 0;
  if ( (v4 & 0x20) != 0 )
    idBitMsg::ReadData(this: msg, data: this, length: 60);
  else
    idBitMsg::ReadNetadr(this: msg, adr: &this->netAddr);
}


// ========================================================================
// ??0lobbyUser_t@@QAA@XZ
// EA  : 0x829A5400
// RVA : 0x009A5400
// PDB : w:\tech5\engine\sys\sys_lobby_backend.h
// ========================================================================

lobbyUser_t *__fastcall lobbyUser_t::lobbyUser_t(lobbyUser_t *this)
{
  unsigned __int64 v1; // r30

  LODWORD(v1) = 0;
  this->lobbyUserID.localUserHandle.handle = 0;
  this->lobbyUserID.lobbyType = -1;
  lobbyAddress_t::lobbyAddress_t(this: &this->address);
  this->isBot = false;
  this->botData = nullptr;
  this->peerIndex = -1;
  this->disconnecting = false;
  this->emblemOrdinal = 0;
  this->level = 1;
  this->pingMs = 9999;
  this->teamNumber = 0;
  this->arbitrationAcked = false;
  this->partyToken = 0;
  this->migrationGameData = -1;
  this->userIndex = 0;
  this->xuid = v1;
  return this;
}


// ========================================================================
// ?WriteClientMutableData@lobbyUser_t@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829A5490
// RVA : 0x009A5490
// PDB : w:\tech5\engine\sys\sys_lobby_backend.h
// ========================================================================

void __fastcall lobbyUser_t::WriteClientMutableData(lobbyUser_t *this, idBitMsg *msg)
{
  idBitMsg::WriteString(this: msg, s: this->gamertag, maxLength: 17, make7Bit: false);
  idBitMsg::WriteBits(this: msg, value: this->emblemOrdinal, numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->level, numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->teamNumber, numBits: 32);
}


// ========================================================================
// ?ReadClientMutableData@lobbyUser_t@@QAAXAAVidBitMsg@@@Z
// EA  : 0x829A5508
// RVA : 0x009A5508
// PDB : w:\tech5\engine\sys\sys_lobby_backend.h
// ========================================================================

void __fastcall lobbyUser_t::ReadClientMutableData(lobbyUser_t *this, idBitMsg *msg)
{
  idBitMsg::ReadString(this: msg, buffer: this->gamertag, bufferSize: 17);
  this->emblemOrdinal = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->level = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->teamNumber = idBitMsg::ReadBits(this: msg, numBits: 32);
}


// ========================================================================
// ?WriteToMsg@lobbyUser_t@@QAAXAAVidBitMsg@@_N@Z
// EA  : 0x829A7718
// RVA : 0x009A7718
// PDB : w:\tech5\engine\sys\sys_lobby_backend.h
// ========================================================================

void __fastcall lobbyUser_t::WriteToMsg(lobbyUser_t *this, idBitMsg *msg, bool useBackend)
{
  lobbyAddress_t::WriteToMsg(this: &this->address, msg);
  if ( net_usePlatformBackend.valueInteger != 0 && useBackend )
  {
    idBitMsg::WriteData(this: msg, data: &this->xuid, length: 8);
    idBitMsg::WriteBits(this: msg, value: this->userIndex, numBits: 8);
  }
  idBitMsg::WriteBits(this: msg, value: this->lobbyUserID.localUserHandle.handle, numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->lobbyUserID.lobbyType, numBits: 8);
  idBitMsg::WriteBits(this: msg, value: this->peerIndex, numBits: 32);
  idBitMsg::WriteBits(this: msg, value: this->pingMs, numBits: -16);
  idBitMsg::WriteBits(this: msg, value: this->partyToken, numBits: 32);
  lobbyUser_t::WriteClientMutableData(this, msg);
}


// ========================================================================
// ?ReadFromMsg@lobbyUser_t@@QAAXAAVidBitMsg@@_N@Z
// EA  : 0x829A77E0
// RVA : 0x009A77E0
// PDB : w:\tech5\engine\sys\sys_lobby_backend.h
// ========================================================================

void __fastcall lobbyUser_t::ReadFromMsg(lobbyUser_t *this, idBitMsg *msg, bool useBackend)
{
  lobbyAddress_t::ReadFromMsg(this: &this->address, msg);
  if ( net_usePlatformBackend.valueInteger != 0 && useBackend )
  {
    idBitMsg::ReadData(this: msg, data: &this->xuid, length: 8);
    this->userIndex = idBitMsg::ReadBits(this: msg, numBits: 8);
  }
  this->lobbyUserID.localUserHandle.handle = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->lobbyUserID.lobbyType = idBitMsg::ReadBits(this: msg, numBits: 8);
  this->peerIndex = idBitMsg::ReadBits(this: msg, numBits: 32);
  this->pingMs = (__int16)idBitMsg::ReadBits(this: msg, numBits: -16);
  this->partyToken = idBitMsg::ReadBits(this: msg, numBits: 32);
  lobbyUser_t::ReadClientMutableData(this, msg);
}


// ========================================================================
// ?IsHost@idLobbyBackend@@UAA_NXZ
// EA  : 0x829B2DB8
// RVA : 0x009B2DB8
// PDB : w:\tech5\engine\sys\sys_lobby_backend.h
// ========================================================================

BOOL __fastcall idLobbyBackend::IsHost(idLobbyBackend *this)
{
  return this->isHost;
}


// ========================================================================
// ?IsLocal@idLobbyBackend@@UBA_NXZ
// EA  : 0x829B2DC0
// RVA : 0x009B2DC0
// PDB : w:\tech5\engine\sys\sys_lobby_backend.h
// ========================================================================

BOOL __fastcall idLobbyBackend::IsLocal(idLobbyBackend *this)
{
  return this->isLocal;
}


// ========================================================================
// ?IsOnline@idLobbyBackend@@UBA_NXZ
// EA  : 0x829B2DC8
// RVA : 0x009B2DC8
// PDB : w:\tech5\engine\sys\sys_lobby_backend.h
// ========================================================================

BOOL __fastcall idLobbyBackend::IsOnline(idLobbyBackend *this)
{
  return (_cntlzw(this->isLocal) & 0x20) != 0;
}

