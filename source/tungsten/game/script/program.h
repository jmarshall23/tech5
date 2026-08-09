#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\script\program.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16007; PDB kind: class.
class __declspec(align(4)) idProgram::idFileInfo
{
public:
  idStr fileName;
  bool includeFile;
};

// IDA Local Type ordinal 16018; PDB kind: class.
class idProgram
{
public:
  idVarDef *returnDef;
  idVarDef *returnStringDef;
  idThreadManager threadManager;
  idList<idProgram::idFileInfo,58> fileList;
  idStr filename;
  int filenum;
  int numVariables;
  unsigned __int8 variables[65536];
  idStaticList<unsigned char,65536> variableDefaults;
  idStaticList<function_t,3072> functions;
  idStaticList<statement_t,10240> statements;
  idList<idTypeDef *,58> types;
  idList<idVarDefName *,58> varDefNames;
  idHashIndex varDefNameHash;
  idList<idVarDef *,58> varDefs;
  idList<idDecl const *,58> referencedDecls;
  idVarDef *sysDef;
  int top_functions;
  int top_statements;
  int top_types;
  int top_defs;
  int top_files;
  int compileFlags;
  idStr errMsg;
};
