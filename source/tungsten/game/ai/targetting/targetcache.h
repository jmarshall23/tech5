#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\targetting\targetcache.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15972; PDB kind: class.
class idTargetCache
{
public:
  idStaticList<idTargetInfo,8> targets;
  int curFrame;
};
