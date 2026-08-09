#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\libs\mgrd\shared\mgsys\mgringbuf.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 24744; PDB kind: struct.
struct MGRINGBUF
{
  char *start;
  char *end;
  unsigned int size;
  char cachelinepad0[116];
  char *volatile write;
  char cachelinepad1[124];
  char *volatile put;
  char cachelinepad2[124];
  char *volatile get;
  char cachelinepad3[124];
};
