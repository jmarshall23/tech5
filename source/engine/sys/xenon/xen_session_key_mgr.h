#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\xenon\xen_session_key_mgr.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22631; PDB kind: struct.
struct idSessionKeyMgr::sessionKey_t
{
  int refCount;
  XNKID sessionID;
  XNKEY keyExchangeKey;
  idLobbyBackend *lobbyOwner;
};

// IDA Local Type ordinal 22634; PDB kind: class.
class idSessionKeyMgr
{
public:
  idStaticList<idSessionKeyMgr::sessionKey_t,10> sessionKeys;
};
