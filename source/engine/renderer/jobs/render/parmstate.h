#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\parmstate.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21766; PDB kind: struct.
struct uniqueParmState_t
{
  unsigned __int64 renderParmVersion;
  unsigned int numBlocks;
  const idParmBlock *parmBlocks[32];
  void *userData;
};

// IDA Local Type ordinal 21822; PDB kind: struct.
struct idParmState::parmStack_t::parmBlockStack_t
{
  unsigned int lastOpLevel;
  const idParmBlock *parmBlock;
};

// IDA Local Type ordinal 21823; PDB kind: struct.
struct idParmState::parmStack_t
{
  unsigned int virtualParmBlockLevel;
  unsigned int currentParmBlockLevel;
  unsigned int currentOpLevel;
  unsigned int virtualParmBlockStackMask;
  idParmState::parmStack_t::parmBlockStack_t parmBlockStack[32];
  parmValue_t opStack[1024];
};

// IDA Local Type ordinal 21824; PDB kind: class.
class idParmState
{
public:
  unsigned __int64 renderParmVersion;
  unsigned __int64 vertexParmVersion;
  unsigned __int64 fragmentParmVersion;
  unsigned __int64 textureParmVersion;
  bool currentMVPHasNegativeDeterminant;
  __declspec(align(16)) parmValue_t values[2048];
  unsigned int onParmBlockStack[2048];
  idParmState::parmStack_t parmStack;
  const idDeclRenderParm *parmDecl[2048];
  unsigned __int8 parmUsageMask[2048];
  const idDeclTable *globalTables[128];
  const idLookupTable *globalLookupTables[128];
  int numGlobalTables;
  int parmIndexPositionToViewTexture;
  int parmIndexRenderPositionToViewTexture;
  int parmIndexPositionToFeedback;
  int parmIndexModelMatrixX;
  int parmIndexModelMatrixY;
  int parmIndexModelMatrixZ;
  int parmIndexModelMatrixW;
  int parmIndexInverseModelMatrixX;
  int parmIndexInverseModelMatrixY;
  int parmIndexInverseModelMatrixZ;
  int parmIndexInverseModelMatrixW;
  int parmIndexMVPMatrixX;
  int parmIndexMVPMatrixY;
  int parmIndexMVPMatrixZ;
  int parmIndexMVPMatrixW;
  int parmIndexPrimeLightDir;
  int parmIndexPrimeLightColor;
  int parmIndexChannelLight[6];
  int parmIndexLightingModel;
  int parmIndexHighlightColor;
  int parmIndexVertexStScaleBias;
  int parmIndexVertexXYZScale;
  int parmIndexVertexXYZBias;
  int parmIndexIf;
  int parmIndexPolygonOffset;
  int parmIndexVertexMorphScale;
};
