#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\class.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 9440; PDB kind: unknown.
struct SUB_CLASS::<unnamed_type_bitfields>
{
  unsigned __int32 SUB_CLASS_INF : 8;
};

// IDA Local Type ordinal 9441; PDB kind: union.
union SUB_CLASS
{
  SUB_CLASS::<unnamed_type_bitfields> bitfields;
  SUB_CLASS::<unnamed_type_bitfields> bits;
  unsigned int u32All;
  int i32All;
  float f32All;
};

// IDA Local Type ordinal 12079; PDB kind: struct.
struct XUIClass
{
  unsigned int cbSize;
  const wchar_t *szClassName;
  const wchar_t *szBaseClassName;
  const wchar_t *szClassDetails;
  XUIObjectMethods Methods;
  const XUIElementPropDef *pPropDefs;
  unsigned int dwPropDefCount;
  int bExtensionClass;
};

// IDA Local Type ordinal 13472; PDB kind: class.
class idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13475.
  virtual idTypeInfo *GetType();
  virtual ~idClass();

};
