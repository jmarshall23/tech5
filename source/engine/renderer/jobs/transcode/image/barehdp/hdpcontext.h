#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpcontext.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22808; PDB kind: struct.
struct hdpContext_t
{
  hdpBitIO_t *bitIODC;
  hdpBitIO_t *bitIOLP;
  hdpBitIO_t *bitIOHP;
  hdpBitIO_t *bitIOFL;
  hdpAdaptiveCBPModelLP_t adaptCBPModelLP;
  hdpAdaptiveCBPModelHP_t adaptCBPModelHP;
  hdpAdaptiveCNModel_t adaptCNModelDC;
  hdpAdaptiveCNModel_t adaptCNModelLP;
  hdpAdaptiveCNModel_t adaptCNModelHP;
  hdpAdaptiveScan_t adaptScanLP[1][16];
  hdpAdaptiveScan_t adaptScanHorHP[1][16];
  hdpAdaptiveScan_t adaptScanVerHP[1][16];
  hdpAdaptiveHuffman_t adaptHuffDC[3];
  hdpAdaptiveHuffman_t adaptHuffLP[8];
  hdpAdaptiveHuffman_t adaptHuffHP[8];
  hdpAdaptiveHuffman_t adaptHuffCBP[3];
  int trimTileFlexBits;
};

// IDA Local Type ordinal 31237; PDB kind: typedef.
typedef void *HCONTEXT;
