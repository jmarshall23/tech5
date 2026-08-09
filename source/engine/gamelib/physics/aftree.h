#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\physics\aftree.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14606; PDB kind: class.
class idAFTree
{
public:
  idList<idAFBody *,71> sortedBodies;
};

// IDA Local Type ordinal 33695; PDB kind: typedef.
typedef void (__fastcall *Free_t)(void *);
