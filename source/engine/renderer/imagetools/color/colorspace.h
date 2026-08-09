#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\imagetools\color\colorspace.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 395; PDB kind: enum.
enum _D3DCOLORSPACE : __int32
{
  D3DCOLORSPACE_RGB = 0x0,
  D3DCOLORSPACE_YCbCr601 = 0x1,
  D3DCOLORSPACE_YCbCr709 = 0x2,
  D3DCOLORSPACE_FORCE_DWORD = 0x7FFFFFFF,
};

// IDA Local Type ordinal 3160; PDB kind: enum.
enum J_COLOR_SPACE : __int32
{
  JCS_UNKNOWN = 0x0,
  JCS_GRAYSCALE = 0x1,
  JCS_RGB = 0x2,
  JCS_YCbCr = 0x3,
  JCS_CMYK = 0x4,
  JCS_YCCK = 0x5,
};

// IDA Local Type ordinal 5255; PDB kind: struct.
struct HCOLORSPACE__
{
  int unused;
};

// IDA Local Type ordinal 25991; PDB kind: typedef.
typedef _D3DCOLORSPACE D3DCOLORSPACE;

// IDA Local Type ordinal 30658; PDB kind: typedef.
typedef HCOLORSPACE__ *HCOLORSPACE;
