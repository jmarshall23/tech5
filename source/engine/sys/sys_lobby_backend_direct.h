#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\sys_lobby_backend_direct.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22616; PDB kind: class.
class idLobbyBackendDirect : public idLobbyBackend
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22615.
  virtual void StartHosting(const idMatchParameters *, float, idLobbyBackend::lobbyBackendType_t);
  virtual void StartFinding(const idMatchParameters *, int, float);
  virtual void JoinFromConnectInfo(const lobbyConnectInfo_t *);
  virtual void GetSearchResults(idList<lobbyConnectInfo_t,5> *);
  virtual lobbyConnectInfo_t *GetConnectInfo(lobbyConnectInfo_t *result);
  virtual void FillMsgWithPostConnectInfo(idBitMsg *);
  virtual void PostConnectFromMsg(idBitMsg *);
  virtual bool IsOwnerOfConnectInfo(const lobbyConnectInfo_t *);
  virtual void Shutdown();
  virtual void GetOwnerAddress(lobbyAddress_t *);
  virtual bool IsHost();
  virtual void SetIsJoinable(bool);
  virtual void Pump();
  virtual void UpdateMatchParms(const idMatchParameters *);
  virtual void UpdateLobbySkill(float);
  virtual void SetInGame(bool);
  virtual idLobbyBackend::lobbyBackendState_t GetState();
  virtual bool IsLocal();
  virtual bool IsOnline();
  virtual bool StartArbitration();
  virtual void Arbitrate();
  virtual void VerifyArbitration();
  virtual bool UserArbitrated(lobbyUser_t *);
  virtual void RegisterUser(lobbyUser_t *, bool);
  virtual void UnregisterUser(lobbyUser_t *, bool);
  virtual void StartSession();
  virtual void EndSession();
  virtual bool IsSessionStarted();
  virtual void FlushStats();
  virtual void BecomeHost(int);
  virtual void RegisterAddress(lobbyAddress_t *);
  virtual void FinishBecomeHost();

  idLobbyBackend::lobbyBackendState_t state;
  netadr_t address;
};
