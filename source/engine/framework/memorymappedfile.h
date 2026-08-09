#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\memorymappedfile.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3202; PDB kind: enum.
enum idMemoryMappedFile::pageState_t : __int32
{
  PGST_UNCOMITTED = 0x0,
  PGST_READING = 0x1,
  PGST_FULL = 0x2,
};

// IDA Local Type ordinal 20010; PDB kind: struct.
struct idMemoryMappedFile::mmPage_t
{
  void *dest;
  bool completion;
  idMemoryMappedFile::pageState_t state;
};

// IDA Local Type ordinal 20012; PDB kind: class.
class __declspec(align(8)) idMemoryMappedFile
{
public:
  idFile *file;
  const __int64 alignedFileOffset;
  const __int64 alignedLength;
  unsigned __int8 *const virtualBase;
  idTempArray<idMemoryMappedFile::mmPage_t> pages;
};

// IDA Local Type ordinal 23596; PDB kind: struct.
struct idMemoryMappedFile::fileRange_t
{
  __int64 fileOffset;
  __int64 length;
};
