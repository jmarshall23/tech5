#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1400; PDB kind: unknown.
enum idNpNavigatorImpl::CalcCollisionFreeWedges::__l2::<unnamed_tag> : __int32
{
  NumWedges = 0x20,
};

// IDA Local Type ordinal 18242; PDB kind: class.
class idNpNavigatorImpl
{
public:
  idNavigationSpace moverSpace;
  bfx::Navigator *navigator;
};
