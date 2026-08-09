#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\sys_dedicated_server_search.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17414; PDB kind: struct.
struct idDedicatedServerSearch::serverInfoDedicated_t
{
  lobbyAddress_t addr;
  serverInfo_t serverInfo;
  idList<idStr,5> connectedPlayers;
};

// IDA Local Type ordinal 17416; PDB kind: class.
class idDedicatedServerSearch
{
public:
  idList<idDedicatedServerSearch::serverInfoDedicated_t,5> list;
  idCallback *callback;
};
