#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\superscript\ss_system.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 12963; PDB kind: class.
class idNfsSystem::Client
{
public:
  idStr desc;
  idNfsClient *nfsClient;
};

// IDA Local Type ordinal 12965; PDB kind: class.
class idNfsSystem
{
public:
  idSysMutex mutex;
  idList<idNfsSystem::Client,5> nfsClients;
};
