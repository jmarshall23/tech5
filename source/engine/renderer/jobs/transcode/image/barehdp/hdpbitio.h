#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\transcode\image\barehdp\hdpbitio.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22800; PDB kind: struct.
struct hdpBitIO_t
{
  unsigned __int64 bitBuff;
  unsigned __int64 bitCnt;
  unsigned __int8 *byteBufStart;
  unsigned __int8 *byteBufEnd;
  unsigned __int8 *byteBufCur;
  unsigned int byteCount;
  hdpStream_t *stream;
  unsigned int streamOffset;
};
