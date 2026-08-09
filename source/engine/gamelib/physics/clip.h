#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\physics\clip.h
// Recovered logical types: 9
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1833; PDB kind: enum.
enum idClip::idClipCollisionQuery::type_t : __int32
{
  QUERY_VALID = 0x0,
  QUERY_CANCELED = 0x1,
  QUERY_SUBMITTED_TRANSLATION = 0x2,
  QUERY_SUBMITTED_ROTATION = 0x3,
  QUERY_SUBMITTED_MOTION = 0x4,
  QUERY_SUBMITTED_MOTION_CONTACTS = 0x5,
  QUERY_SUBMITTED_STEPMOVE = 0x6,
  QUERY_SUBMITTED_STEPMOVE_CONTACTS = 0x7,
  QUERY_SUBMITTED_SLIDEMOVE = 0x8,
  QUERY_SUBMITTED_SLIDEMOVE_CONTACTS = 0x9,
  QUERY_SUBMITTED_CONTENTS = 0xA,
  QUERY_SUBMITTED_CONTACTS = 0xB,
  QUERY_SUBMITTED_CLIP = 0xC,
};

// IDA Local Type ordinal 2572; PDB kind: enum.
enum idClip::gatherType_t : __int32
{
  GATHER_TOUCHING_BOUNDS = 0x0,
  GATHER_TOUCHING_LINE = 0x1,
  GATHER_TOUCHING_CLIPMODEL = 0x2,
};

// IDA Local Type ordinal 14068; PDB kind: class.
class idClip
{
public:
  idClipModel *world;
  idClipModel *temporaryClipModel;
  idClipModel *defaultClipModel;
  idClipModel *playerMeleeClipModel;
  idClipModel *clip8x8;
  idClipModel *clip8x8x8;
  idClipModel *clip16x16;
  idClipModel *clip16x16x16;
  idClipModel *clip24x24;
  idClipModel *clip32x32;
  idClipModel *clip8x16;
  idClipModel *clip48x48;
  idClipModel *clip96x96;
  idClipModel *clip24x24x96;
  idClipModel *clip32x32x96;
  idClipModel *clip48x48x96;
  idBlockAlloc<clipLink_t,256,13> clipLinkAllocator;
  idStaticList<clipSector_t,8191> clipSectors;
  int touchCount;
  idAAS2 *aases[8];
  idTraceModelCache *traceModelCache;
  idTraceModelRecycler *traceModelRecycler;
  idClipModel *deletedClipModels;
  idList<int,13> streamAreas;
  idClip::idClipQueryParms *queryParms;
  int numQueryParms;
  idStaticList<unsigned int,2048> translationQueries;
  idStaticList<unsigned int,2048> rotationQueries;
  idStaticList<unsigned int,2048> motionQueries;
  idStaticList<unsigned int,2048> motionContactsQueries;
  idStaticList<unsigned int,2048> stepMoveQueries;
  idStaticList<unsigned int,2048> stepMoveContactsQueries;
  idStaticList<unsigned int,2048> slideMoveQueries;
  idStaticList<unsigned int,2048> slideMoveContactsQueries;
  idStaticList<unsigned int,2048> contentsQueries;
  idStaticList<unsigned int,2048> contactsQueries;
  idStaticList<unsigned int,2048> clipQueries;
  idStaticList<unsigned int,2048> localTranslationQueries;
  idStaticList<unsigned int,2048> localContentsQueries;
  idStaticList<unsigned int,2048> translationTraceModelQueries;
  idClip::idClipCollisionQuery collisionQueries[4096];
  unsigned __int64 collisionQueryFirstSubmittedIndex;
  unsigned __int64 collisionQueryLastSubmittedIndex;
  unsigned __int64 collisionQueryFirstAllocedIndex;
  unsigned __int64 collisionQueryLastAllocedIndex;
  unsigned __int64 collisionQueryLastResolvedIndex;
  const char *gatherQueryUserNames[256];
  idClip::idClipGatherQuery gatherQueries[256];
  unsigned __int64 gatherQueryFirstSubmittedIndex;
  unsigned __int64 gatherQueryLastSubmittedIndex;
  unsigned __int64 gatherQueryFirstAllocedIndex;
  unsigned __int64 gatherQueryLastAllocedIndex;
  idClip::idGatherResult gatherResults[2048];
  unsigned __int64 gatherResultFirstSubmittedIndex;
  unsigned __int64 gatherResultLastSubmittedIndex;
  unsigned __int64 gatherResultFirstAllocedIndex;
  unsigned __int64 gatherResultLastAllocedIndex;
  idClip::idClipResidencyQuery residencyQueries[1024];
  unsigned __int64 residencyQueryFirstSubmittedIndex;
  unsigned __int64 residencyQueryLastSubmittedIndex;
  unsigned __int64 residencyQueryFirstAllocedIndex;
  unsigned __int64 residencyQueryLastAllocedIndex;
};

// IDA Local Type ordinal 14128; PDB kind: class.
class idClip::idClipQueryParms
{
public:
  idVec3 start;
  idVec3 end;
  idVec3 origin;
  idVec3 vec;
  float f1;
  float f2;
  idMat3 startAxis;
  int clipMask;
  unsigned __int16 passEntityNumber;
  unsigned __int16 flags;
  unsigned __int8 pad[12];
  unsigned int queryIndex;
  const idClipModel *clipModel;
  const idTraceModel *traceModel;
  const char *userName;
};

// IDA Local Type ordinal 14131; PDB kind: class.
class idClip::idClipCollisionQuery
{
public:
  idClip::idClipCollisionQuery::type_t type;
  int parmIndex;
  idClipModel *clipModel;
  idCollisionQuery query;
};

// IDA Local Type ordinal 14132; PDB kind: class.
class idClip::idClipGatherQuery
{
public:
  idVec3 vectors[4];
  int clipMask;
  __int16 passEntityNumber;
  __int16 gatherType;
  unsigned __int16 firstResultIndex;
  unsigned __int16 numResults;
  const idClipModel *clipModel;
};

// IDA Local Type ordinal 14133; PDB kind: class.
class idClip::idGatherResult
{
public:
  idCollisionQuery query;
  int physicsId;
  __int16 bodyId;
  __int16 entityNumber;
};

// IDA Local Type ordinal 14134; PDB kind: class.
class idClip::idClipResidencyQuery
{
public:
  idBounds absBounds;
  bool resident;
  unsigned __int8 pad[7];
};

// IDA Local Type ordinal 23461; PDB kind: struct.
struct idClip::GetClipModelsTouchingLine::__l2::stackPoints_t
{
  idVec4 start;
  idVec4 end;
};
