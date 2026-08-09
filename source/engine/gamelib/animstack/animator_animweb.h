#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animator_animweb.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2404; PDB kind: enum.
enum idAnimator_AnimWeb::animWebError_t : __int32
{
  ANIMWEB_ERROR_NONE = 0x0,
  ANIMWEB_ERROR_NOPATH = 0x1,
};

// IDA Local Type ordinal 15030; PDB kind: class.
class __declspec(align(2)) idAnimator_AnimWeb : public idAnimator_Base
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15095.
  virtual ~idAnimator_AnimWeb();
  virtual idAnimator_Base::priority_t GetStackPriority();
  virtual serializeType_t GetSerializeType();
  virtual void SerializeSnapshot(idSerializer *);
  virtual void PreBlendSnapshot(idAnimStack *, int, const int, float);
  virtual void PreSerializeInit(idAnimStack *, idClip *, idGameTimeManager *);
  virtual bool InternalInit(const idAnimatorParms_Base *);
  virtual bool InternalPostInit(const idAnimatorParms_Base *);
  virtual void InternalShutdown(idAnimStack *);
  virtual void InternalPreBlendTree(const idAnimStack *, const int, const int);
  virtual void InternalPostBlendTree(const idAnimStack *, const int);
  virtual void InternalStart(const idAnimStack *, const int, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual void InternalEnd(const idAnimStack *, const int, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual void InternalBlend(const idAnimStack *, const int, const float, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual bool InternalIsContributing();
  virtual const idMD6Branch *InternalGetMergeBranch();
  virtual idMD6Branch *InternalGetMergeBranch_2();
  virtual void InternalPause(const idAnimStack *, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual void InternalUnpause(const idAnimStack *, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual const idMD6Branch *InternalGetEndBranch();
  virtual idMD6Branch *InternalGetEndBranch_2();
  virtual const idHandle<short,enum invalidAnimWebHandle_t,-1> *GetHandle();
  virtual void InternalInitWeb();
  virtual void InternalUpdate(const int);
  virtual idDeclAnimWebNode::animDelta_t InternalGetCurrentAnimDeltaMode();
  virtual void InternalSetAnimDelta(const idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t>, const idDeclAnimWebNode *);
  virtual int InternalGetEdgeCost(const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>, const idIndex<short,enum idDeclAnimWeb::invalidEdgeIndex_t>);
  virtual void InternalStartPath();
  virtual void InternalUpdateScalars(const int);
  virtual void InternalStartBlend(const idDeclAnimWebNode *, const idDeclAnimWebNode *, const int);
  virtual void InternalFinishBlend(const idDeclAnimWebNode *, const idDeclAnimWebNode *, const int);
  virtual awCheckPathResult_t CheckNextNode(const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual bool InternalShouldStartNextNode(const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>, const idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>, const int, const int, const blendParms_t *, idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t>, const bool, animWebEvent_t *);
  virtual void InternalTriggerEvent(const idDeclAnimWebNode *, const animWebEvent_t, const idHandle<short,enum invalidAnimWebHandle_t,-1> *, const int, const int);
  virtual void InternalTriggerBlendEvent(int, idIndex<short,enum idDeclAnimWeb::invalidModelIndex_t>, idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>, idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>, const int);
  virtual bool InternalRemapNames(idStr *, idStr *);
  virtual void InternalUpdateBlendEvents(const idAnimStack *, const int, const int);

  const idDeclAnimWeb *decl;
  idMD6Allocator *md6Allocator;
  idList<idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t>,5> initialActiveSubWebs;
  idList<idAnimator_AnimWeb::idModelAnimState,33> modelAnimStates;
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> curNodeIndex;
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> prevNodeIndex;
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> destSubWebIndex;
  idDeclAnimWeb::stateList_t destStateIndices;
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> viaSubWebIndex;
  idDeclAnimWeb::stateList_t viaStateIndices;
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> otherSubWebIndex;
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> curEdgeNodeIndex;
  __int16 curEdgeIndex;
  idStaticList<idList<idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t>,32> const *,16> pathableSubWebNodeLists;
  __int16 pathIndex;
  idAnimWebRoute curPath;
  interruptPath_t interruptPath;
  interruptBlend_t interruptBlend;
  int nodeStartTime;
  int prevNodeStartTime;
  int nodeStartFrame;
  idList<idAnimWebScalar,33> scalars;
  idScalarMemBlock scalarMem;
  int firstRandomScalarIndex;
  int blendEventMask;
  int declChangeId;
  idAtomicString curNodeStateName;
  idAtomicString curNodeSubWebName;
  idAtomicString destNodeStateName;
  idAtomicString destNodeSubWebName;
  idHandle<short,enum invalidAnimWebHandle_t,-1> handle;
  idAnimWebEventHandler_Zion eventHandler;
  bool clearEventsOnStateChanges;
  unsigned __int8 skipFlags;
  unsigned __int8 requiredFlags;
  idAnimator_AnimWeb::forcedEdge_t forcedEdge;
  float randomBlendVals[8];
  idMD6Branch *mergeBranch;
  idAnimator_ChannelWeight channelWeightAnimator;
  idList<idDeclMD6 const *,33> modelDecls;
  idAnimator_AnimWeb::animWebError_t error;
  bool debug;
  bool forceAnimDeltaModeOnBlendStart;
  bool skipForcedEdgeAutoPath;
};

// IDA Local Type ordinal 15075; PDB kind: class.
class __declspec(align(4)) idAnimator_AnimWeb::idModelAnimState
{
public:
  idMD6Node *tree;
  idMD6Branch *branches[2];
  idStaticList<idAnimWebBlendTree *,8> blendTreeCache;
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> recentNodes[3];
  __int16 recentNodeStart;
  bool blending;
};

// IDA Local Type ordinal 15087; PDB kind: struct.
struct idAnimator_AnimWeb::forcedEdge_t
{
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> destNodeIndex;
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> destSubWebIndex;
  blendParms_t blendParms;
};

// IDA Local Type ordinal 18100; PDB kind: class.
class idAnimatorParms_AnimWeb : public idAnimatorParms_Base
{
public:
  const idDeclAnimWeb *webDecl;
  idStr initialStateName;
  idStr initialSubWebName;
  int curTime;
  idList<idAtomicString,5> activeLayers;
};

// IDA Local Type ordinal 21365; PDB kind: struct.
struct idAnimator_AnimWeb::animInfo_t
{
  int curFrame;
  int numFrames;
  int frameRate;
};
