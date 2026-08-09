#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\virtualmaterialatlas.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3015; PDB kind: enum.
enum idVirtualMaterial::vmtrFlag_t : __int32
{
  VF_TRANSMAP = 0x1,
  VF_NO_BORDER = 0x2,
};

// IDA Local Type ordinal 13332; PDB kind: class.
class idVirtualMaterial
{
public:
  idAtomicString materialName;
  unsigned int materialChecksum;
  unsigned int cpuVmtrTimeStamp;
  int allocX;
  int allocY;
  int allocWidth;
  int allocHeight;
  int flags;
  const idMaterial *material;
  const struct idVmtrCPU *cpuVmtr;
  idVec4 scaleAndBias;
};
