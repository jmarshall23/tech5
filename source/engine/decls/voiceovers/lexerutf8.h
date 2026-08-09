#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\voiceovers\lexerutf8.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3223; PDB kind: unknown.
enum idLexerUTF8::Error::__l14::<unnamed_tag> : __int32
{
  BuffSize = 0x80,
};

// IDA Local Type ordinal 18073; PDB kind: class.
class __declspec(align(2)) idLexerUTF8
{
public:
  idStr filename;
  int flags;
  const unsigned __int8 *buffer;
  const unsigned __int8 *cur;
  const unsigned __int8 *end;
  const unsigned __int8 *prev;
  unsigned int len;
  int lastline;
  int line;
  const punctuation_t *punctuations;
  int *punctuationtable;
  int *nextpunctuation;
  bool loaded;
  bool hadError;
  bool hadWarning;
};
