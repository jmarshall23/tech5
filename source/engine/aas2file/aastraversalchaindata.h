#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\aas2file\aastraversalchaindata.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2227; PDB kind: enum.
enum idAASTraversalChainData::localFlags_t : __int32
{
  EVASION_ONLY = 0x1,
  EMERGENCY_ONLY = 0x2,
  COMBAT_ONLY = 0x4,
  ENABLED = 0x8,
  RUN_WHEN_DONE = 0x10,
  DELTA_CORRECT = 0x20,
  MAX_FLAG_BITS = 0x6,
};

// IDA Local Type ordinal 2933; PDB kind: enum.
enum idAASTraversalChainData::localClass_t : __int32
{
  CLASS_A = 0x1,
  CLASS_B = 0x2,
  CLASS_C = 0x4,
  CLASS_D = 0x8,
  CLASS_E = 0x10,
  MAX_CLASS_BITS = 0x5,
};

// IDA Local Type ordinal 14103; PDB kind: struct.
const struct aas2Traversal_t
{
  idVec3 startPoint;
  idVec3 endPoint;
  idQuantizedVec3 orientationFwd;
  idQuantizedVec3 extrusionFwd;
  idIndex<short,enum invalidAASAnimIndex_t> animIndex;
  idIndex<short,enum invalidReachability_t> reachabilityIndex;
  idIndex<short,enum invalidAASDependencyIndex_t> dependencyIndex;
  idIndex<short,enum invalidAASInteractionEntIndex_t> interactionEntIndex;
  __int16 extrusionDistance;
  __int16 startAreaNum;
  __int16 endAreaNum;
  idIndex<short,enum invalidAASTraversalNameIndex_t> traversalNameIndex;
  unsigned int flags;
};

// IDA Local Type ordinal 20467; PDB kind: class.
class idAASTraversalChainData
{
public:
  aasType_t mAASType;
  idAASTraversalChainData::localClass_t mClass;
  idAASTraversalChainData::localFlags_t mFlags;
  idVec3 mExtrusionEndpoint;
  const idDeclAnimWeb *mAnimWeb;
};

// IDA Local Type ordinal 22459; PDB kind: struct.
struct idAASTraversalChainData::flagMap_t
{
  int gameFlag;
  int aasFlag;
};

// IDA Local Type ordinal 27754; PDB kind: typedef.
typedef idIndex<short,enum invalidAASTraversalNameIndex_t> aasTraversalNameIndex_t;
