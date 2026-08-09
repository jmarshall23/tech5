#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\script\compiler.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17653; PDB kind: class.
class idCompiler
{
public:
  idParser parser;
  idParser *parserPtr;
  idToken token;
  idTypeDef *immediateType;
  eval_s immediate;
  bool eof;
  int compileFlags;
  bool callthread;
  int braceDepth;
  int loopDepth;
  int currentLineNumber;
  int currentFileNumber;
  int errorCount;
  idVarDef *scope;
  const idVarDef *basetype;
};

// IDA Local Type ordinal 17655; PDB kind: class.
class idCompileError : public idException
{
public:
};
