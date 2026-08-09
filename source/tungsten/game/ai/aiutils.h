#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aiutils.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 8439; PDB kind: unknown.
struct WAIT_UNTIL::<unnamed_type_bitfields>
{
  unsigned __int32 WAIT_CRTC_PFLIP : 1;
  unsigned __int32 WAIT_RE_CRTC_VLINE : 1;
  unsigned __int32 WAIT_FE_CRTC_VLINE : 1;
  unsigned __int32 WAIT_CRTC_VLINE : 1;
  unsigned __int32 : 4;
  unsigned __int32 WAIT_CP_DMA_IDLE : 1;
  unsigned __int32 : 1;
  unsigned __int32 WAIT_CMDFIFO : 1;
  unsigned __int32 WAIT_OV_FLIP : 1;
  unsigned __int32 : 3;
  unsigned __int32 WAIT_IDLE : 1;
  unsigned __int32 : 1;
  unsigned __int32 WAIT_IDLECLEAN : 1;
  unsigned __int32 : 2;
  unsigned __int32 CMDFIFO_ENTRIES : 4;
};

// IDA Local Type ordinal 8440; PDB kind: union.
union WAIT_UNTIL
{
  WAIT_UNTIL::<unnamed_type_bitfields> bitfields;
  WAIT_UNTIL::<unnamed_type_bitfields> bits;
  unsigned int u32All;
  int i32All;
  float f32All;
};

// IDA Local Type ordinal 20489; PDB kind: class.
class idAIUtils
{
public:
};
