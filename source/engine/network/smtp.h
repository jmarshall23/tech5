#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\network\smtp.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 12990; PDB kind: struct.
struct idMTP::request_t
{
  unsigned __int64 offset;
  unsigned int length;
  unsigned __int16 filenameLength;
  unsigned __int16 operation;
};

// IDA Local Type ordinal 12992; PDB kind: struct.
struct idMTP::stats_t
{
  unsigned __int64 length;
  unsigned int timestamp;
  unsigned int unused;
};

// IDA Local Type ordinal 23109; PDB kind: class.
class idSMTP
{
public:
  idTCP tcp;
};
