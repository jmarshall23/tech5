#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\transcode\image\baredct\baredcthuffmantable.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22788; PDB kind: class.
class idBareDCTHuffmanTable
{
public:
  unsigned int code[256];
  char size[256];
  unsigned __int8 look_nbits[256];
  unsigned __int8 look_sym[256];
  unsigned __int8 symbols[256];
  int test_nbits[16];
  int minCode[17];
  int maxCode[18];
  int symOffset[17];
};
