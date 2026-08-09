#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\declrenderprog.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2609; PDB kind: enum.
enum idDeclRenderProg::programType_t : __int32
{
  PROGRAM_TYPE_VERTEX = 0x0,
  PROGRAM_TYPE_FRAGMENT = 0x1,
};

// IDA Local Type ordinal 13320; PDB kind: class.
class __declspec(align(8)) idDeclRenderProg : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13324.
  virtual ~idDeclRenderProg();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  const idDeclRenderProg *renamed;
  unsigned __int64 glState;
  bool hasClip;
  bool hasAlphaToCoverage;
  bool hasHardwareSkinning;
  bool hasInteractions;
  bool has16BitScaleBias;
  bool hasVertexTexture;
  unsigned __int16 fragmentOutputs;
  unsigned __int8 registerCountPS3;
  unsigned __int8 registerCount360;
  float stageSort;
  idParmBlock parmBlock;
  unsigned int vertexMask;
  unsigned int vertexProgramChecksum;
  unsigned int fragmentProgramChecksum;
  __int16 vertexParms[32];
  int numVertexParms;
  __int16 fragmentParms[32];
  int numFragmentParms;
  __int16 textureParms[16];
  int numTextureParms;
  bool hasDerived;
  const idDeclRenderProg *inheritedVertexProgram;
  const idDeclRenderProg *inheritedFragmentProgram;
  idArray<idDeclRenderProg::vertexDeclaration_t,4> vertexDeclarations;
  int numVertexDeclarations;
  void *compiledVertexCode;
  D3DPixelShader *fragmentShaderD3D;
  bool isFastZ;
  idStr vertexCode[4];
  idStr fragmentCode[4];
  const idDeclRenderProg *versions[4];
};

// IDA Local Type ordinal 13322; PDB kind: struct.
struct idDeclRenderProg::vertexDeclaration_t
{
  D3DVertexShader *vertexShaderD3D;
  unsigned int vertexMask;
};
