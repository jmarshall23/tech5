#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\gameplayfilter.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1614; PDB kind: enum.
enum idGameplayFilter::Element::flagState_t : __int32
{
  FS_FALSE = 0x0,
  FS_TRUE = 0x1,
  FS_IGNORE = 0x2,
};

// IDA Local Type ordinal 1615; PDB kind: enum.
enum idGameplayFilter::Element::elementType_t : __int32
{
  ET_AND = 0x0,
  ET_OR = 0x1,
};

// IDA Local Type ordinal 15568; PDB kind: class.
class idGameplayFilterTarget
{
public:
  unsigned int bits;
};

// IDA Local Type ordinal 18788; PDB kind: class.
class idGameplayFilter::Element
{
public:
  unsigned int desiredBits;
  unsigned int activeBits;
  idGameplayFilter::Element::elementType_t elementType;
};

// IDA Local Type ordinal 22274; PDB kind: class.
class idGameplayFilter
{
public:
  idList<idGameplayFilter::Element,5> elements;
};
