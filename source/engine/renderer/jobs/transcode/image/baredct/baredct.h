#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredct.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22789; PDB kind: class.
class idBareDctBase
{
public:
  int luminanceQuality;
  int chrominanceQuality;
  int alphaQuality;
  sampleMode_t sampleMode;
  unsigned __int16 quantTableY[64];
  unsigned __int16 quantTableCoCg[64];
  unsigned __int16 quantTableA[64];
};
