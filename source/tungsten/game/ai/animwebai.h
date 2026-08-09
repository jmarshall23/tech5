#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\animwebai.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17126; PDB kind: class.
class idAnimWebAI : public idAnimator_AnimWeb
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17127.
  virtual ~idAnimWebAI();
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

  idAI2 *ai;
  float bodyTurnDot;
  turnDirection_t bodyTurnDir;
  float movementTurnDot;
  turnDirection_t movementTurnDir;
  float forwardRunIndex;
  float leftRunIndex;
  float rightRunIndex;
  float backRunIndex;
  float injuredRunOffset;
  float previousRunIndex;
  float forwardRunBlend;
  float forwardRunBlendLinear;
  float deathAnimIndex;
  float startTransitionIndex;
  float stopTransitionIndex;
  float aimAlpha;
  float nextRunIndex;
  float idleIndex;
  float nextIdleIndex;
  float previousIdleIndex;
  runIndexType_t runIndexType;
  runIndexType_t nextRunIndexType;
  int runIndexChangeFrame;
  float blendBack;
  float blendRight;
  float blendAngle;
  float walkRate;
  float runRate;
  float deathScale;
  float desiredTurn;
  float sync8index1;
  float sync8index2;
  float sync8blendAngle;
  float select01;
  float traversalAttack;
  float diveIndex;
  float transitionSelect;
  float toCombatTurn;
  float toSearchTurn;
  float turnLeanDirection;
  float turnLeanAmount;
  float gangstaAlpha;
};
