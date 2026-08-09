#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\pagesort\pagesort.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1498; PDB kind: enum.
enum pageSource_t : __int32
{
  PAGESOURCE_INVALID = 0x0,
  PAGESOURCE_VMTR = 0x1,
  PAGESOURCE_UNIQUE = 0x2,
  PAGESOURCE_ALLOC2 = 0x3,
  PAGESOURCE_ALLOC3 = 0x4,
  PAGESOURCE_ALLOC4 = 0x5,
  PAGESOURCE_ALLOC5 = 0x6,
  PAGESOURCE_ALLOC6 = 0x7,
  PAGESOURCE_ALLOC7 = 0x8,
  PAGESOURCE_ALLOC8 = 0x9,
  PAGESOURCE_ALLOC9 = 0xA,
  PAGESOURCE_ALLOC10 = 0xB,
  PAGESOURCE_ALLOC11 = 0xC,
  PAGESOURCE_ALLOC12 = 0xD,
  PAGESOURCE_ALLOC13 = 0xE,
  PAGESOURCE_ALLOC14 = 0xF,
  PAGESOURCE_TOTAL = 0x10,
};

// IDA Local Type ordinal 13650; PDB kind: struct.
struct pageSortParms_t
{
  int frameNum;
  const int *pagePriority;
  const int *pageFrameNum;
  const __int64 *physicalPageNums;
  int *firstPageIndex;
  int *lastPageIndex;
  int indexMask;
  __int64 *sortedPhysicalPageNums;
  volatile int *done;
};
