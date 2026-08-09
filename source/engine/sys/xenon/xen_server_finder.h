#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\xenon\xen_server_finder.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2985; PDB kind: enum.
enum id360FriendsServerFinder::finderState_t : __int32
{
  STATE_IDLE = 0x0,
  STATE_FINDING_FRIENDS = 0x1,
  STATE_FINDING_SESSIONS = 0x2,
  STATE_QUERY_SERVERS = 0x3,
  STATE_SUCCESS = 0x4,
  STATE_FAILED = 0x5,
};

// IDA Local Type ordinal 22603; PDB kind: class.
class id360ServerFinder
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22604.
  virtual ~id360ServerFinder();
  virtual void FindServers(const idCallback *);
  virtual int NumServers();
  virtual bool GetServerSessionInfo(int, _XSESSION_INFO *);
  virtual void KeepServerSecurityAssociation(int);
  virtual const serverInfo_t *GetServerInfo(int);
  virtual unsigned __int64 GetFriendXuid(int);
  virtual void Pump();

  idCallback *callback;
  idServerQuery serverQuery;
  idLobby *partyLobby;
  idLobby *gameLobby;
};

// IDA Local Type ordinal 22621; PDB kind: struct.
struct __declspec(align(4)) id360FriendsServerFinder::friendGameQuery_t
{
  char szGamertag[16];
  unsigned __int64 xuid;
  serverInfo_t serverInfo;
  XNKID sessionID;
  _XSESSION_INFO sessionInfo;
  bool acked;
};

// IDA Local Type ordinal 22624; PDB kind: class.
class __declspec(align(8)) id360FriendsServerFinder : public id360ServerFinder
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22625.
  virtual ~id360FriendsServerFinder();
  virtual void FindServers(const idCallback *);
  virtual int NumServers();
  virtual bool GetServerSessionInfo(int, _XSESSION_INFO *);
  virtual void KeepServerSecurityAssociation(int);
  virtual const serverInfo_t *GetServerInfo(int);
  virtual unsigned __int64 GetFriendXuid(int);
  virtual void Pump();

  idFriendsEnum *friendsEnum;
  idSessionFinder *sessionFinder;
  idStaticList<XNKID,8> sessionIDs;
  idStaticList<id360FriendsServerFinder::friendGameQuery_t,16> friendGames;
  id360FriendsServerFinder::finderState_t state;
};
