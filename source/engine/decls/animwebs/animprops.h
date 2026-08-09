#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\animwebs\animprops.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1063; PDB kind: enum.
typedef idMD6Blend::jointMod_t::<unnamed_tag> animationPose_t;

// IDA Local Type ordinal 15038; PDB kind: class.
class idMD6AnimProps
{
public:
  const idMD6Anim *anim;
  idHandle<unsigned short,enum invalidAliasHandle_t,65535> aliasHandle;
  idMD6Leaf::wrapMode_t wrap;
  float rate;
  unsigned int tags;
};
