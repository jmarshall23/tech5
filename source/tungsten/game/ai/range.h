#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\range.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1530; PDB kind: enum.
enum rangeId_t : __int32
{
  RANGE_MAIN = 0x0,
  RANGE_RENDER = 0x1,
  RANGE_GPU = 0x2,
  RANGE_JBL_COLL = 0x3,
  RANGE_JBL_GAME = 0x4,
  RANGE_JBL_RMDL = 0x5,
  RANGE_JBL_TRNS = 0x6,
  RANGE_JBL_VDEO = 0x7,
  RANGE_JBL_ANLZ = 0x8,
  RANGE_JBL_VIRT = 0x9,
  RANGE_JBL_SNDO = 0xA,
  RANGE_JBL_SNAP = 0xB,
  RANGE_STREAM_CT = 0xC,
  RANGE_STREAM_HD = 0xD,
  RANGE_STREAM_OD = 0xE,
  RANGE_JPU0 = 0xF,
  RANGE_JPU1 = 0x10,
  RANGE_JPU2 = 0x11,
  RANGE_JPU3 = 0x12,
  RANGE_JPU4 = 0x13,
  RANGE_JPU5 = 0x14,
  RANGE_JPU6 = 0x15,
  RANGE_JPU7 = 0x16,
  RANGE_JPU8 = 0x17,
  RANGE_JPU9 = 0x18,
  RANGE_JPU10 = 0x19,
  RANGE_JPU11 = 0x1A,
  RANGE_JPU12 = 0x1B,
  RANGE_JPU13 = 0x1C,
  RANGE_JPU14 = 0x1D,
  RANGE_JPU15 = 0x1E,
  RANGE_JPU16 = 0x1F,
  RANGE_JPU17 = 0x20,
  RANGE_JPU18 = 0x21,
  RANGE_JPU19 = 0x22,
  RANGE_JPU20 = 0x23,
  RANGE_JPU21 = 0x24,
  RANGE_JPU22 = 0x25,
  RANGE_JPU23 = 0x26,
  RANGE_MAX = 0x27,
};

// IDA Local Type ordinal 16588; PDB kind: class.
class idRange<float>
{
public:
  float minRange;
  float maxRange;
};
