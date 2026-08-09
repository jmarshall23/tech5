#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\libs\zlib\inflate.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3404; PDB kind: enum.
enum inflate_mode : __int32
{
  HEAD = 0x0,
  FLAGS = 0x1,
  TIME = 0x2,
  OS = 0x3,
  EXLEN = 0x4,
  EXTRA = 0x5,
  NAME = 0x6,
  COMMENT = 0x7,
  HCRC = 0x8,
  DICTID = 0x9,
  DICT = 0xA,
  TYPE = 0xB,
  TYPEDO = 0xC,
  STORED = 0xD,
  COPY = 0xE,
  TABLE = 0xF,
  LENLENS = 0x10,
  CODELENS = 0x11,
  LEN = 0x12,
  LENEXT = 0x13,
  DIST = 0x14,
  DISTEXT = 0x15,
  MATCH = 0x16,
  LIT = 0x17,
  CHECK = 0x18,
  LENGTH = 0x19,
  DONE = 0x1A,
  BAD = 0x1B,
  MEM = 0x1C,
  SYNC = 0x1D,
};

// IDA Local Type ordinal 24743; PDB kind: struct.
struct inflate_state
{
  inflate_mode mode;
  int last;
  int wrap;
  int havedict;
  int flags;
  unsigned int dmax;
  unsigned int check;
  unsigned int total;
  gz_header_s *head;
  unsigned int wbits;
  unsigned int wsize;
  unsigned int whave;
  unsigned int write;
  unsigned __int8 *window;
  unsigned int hold;
  unsigned int bits;
  unsigned int length;
  unsigned int offset;
  unsigned int extra;
  const code *lencode;
  const code *distcode;
  unsigned int lenbits;
  unsigned int distbits;
  unsigned int ncode;
  unsigned int nlen;
  unsigned int ndist;
  unsigned int have;
  code *next;
  unsigned __int16 lens[320];
  unsigned __int16 work[288];
  code codes[2048];
};
