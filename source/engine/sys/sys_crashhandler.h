#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\sys_crashhandler.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 19086; PDB kind: class.
class idCrashHandler
{
public:
  bool defaultMessage;
  int (__fastcall *originalHandler)(_EXCEPTION_POINTERS *);
};
