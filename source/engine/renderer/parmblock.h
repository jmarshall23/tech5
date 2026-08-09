#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\parmblock.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13321; PDB kind: class.
class __declspec(align(4)) idParmBlock
{
public:
  idList<expOp_t,56> ops;
  idList<parmValue_t,56> constants;
  threadId_t thread;
  bool usingTempOps;
};

// IDA Local Type ordinal 13533; PDB kind: class.
class idStaticParmBlock<32> : public idParmBlock
{
public:
  expOp_t staticOps[32];
  __declspec(align(16)) parmValue_t staticConstants[32];
};
