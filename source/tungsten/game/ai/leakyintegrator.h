#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\leakyintegrator.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14956; PDB kind: class.
class __declspec(align(4)) idLeakyIntegrator<0,1>
{
public:
  float value;
  float decayRate;
  int lastUpdateMS;
  unsigned __int8 : 7;
  __int8 wasTriggered : 1;
};

// IDA Local Type ordinal 26288; PDB kind: typedef.
typedef idLeakyIntegrator<0,1> leakyIntegrator_t;
