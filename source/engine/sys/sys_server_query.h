#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\sys_server_query.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22586; PDB kind: struct.
struct idServerQuery::serverQueryInfo_t
{
  lobbyConnectInfo_t connectInfo;
  lobbyAddress_t addr;
  int lastAttemptTime;
  int attempts;
  bool acked;
  serverInfo_t serverInfo;
};

// IDA Local Type ordinal 22589; PDB kind: class.
class idServerQuery
{
public:
  idStaticList<idServerQuery::serverQueryInfo_t,32> servers;
};
