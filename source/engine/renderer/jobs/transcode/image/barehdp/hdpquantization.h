#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpquantization.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22802; PDB kind: struct.
struct hdpTileQuantization_t
{
  hdpQuantizer_t *pQuantizerDC[16];
  hdpQuantizer_t *pQuantizerLP[16];
  hdpQuantizer_t *pQuantizerHP[16];
  unsigned __int8 cNumQPLP;
  unsigned __int8 cNumQPHP;
  unsigned __int8 cBitsLP;
  unsigned __int8 cBitsHP;
};
