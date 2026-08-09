#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\animfsm\animfsm.h
// Recovered logical types: 8
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2318; PDB kind: enum.
enum idAnimFSM::idMoveStateId : __int32
{
  STATE_MOVE = 0x1,
  STATE_LAST = 0x3,
};

// IDA Local Type ordinal 2328; PDB kind: enum.
enum idAnimFSM::cornerClipInfo_t::cornerQueryStatus_t : __int32
{
  CORNER_UNUSED = 0x0,
  CORNER_DIRTY = 0x1,
  CORNER_VALID = 0x2,
};

// IDA Local Type ordinal 2336; PDB kind: unknown.
enum idAnimFSM_NP::UpdateAvoidance::__l5::<unnamed_tag> : __int32
{
  MaxWedges = 0x10,
};

// IDA Local Type ordinal 2337; PDB kind: enum.
enum idAnimFSM_NP::UpdateAvoidance::__l13::avoidStatus_t : __int32
{
  WEDGE_AVOID_UNKNOWN = 0x0,
  WEDGE_AVOID_NONE = 0x1,
  WEDGE_AVOID = 0x2,
};

// IDA Local Type ordinal 17185; PDB kind: struct.
struct __declspec(align(4)) idAnimFSM::cornerClipInfo_t
{
  idClipQuery query;
  idVec3 navPos;
  idVec3 groundPos;
  idAnimFSM::cornerClipInfo_t::cornerQueryStatus_t status;
  bool stopToUseCorner;
};

// IDA Local Type ordinal 17187; PDB kind: class.
class idAnimFSM : public idAnimBaseFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17188.
  virtual idTypeInfo *GetType();
  virtual ~idAnimFSM();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void PrintDebugInfo(idGuiListBox *);
  virtual int GetNumStates();
  virtual idAIStateLite *GetState(const int);
  virtual int GetDefaultStateId();
  virtual void InternalInit();
  virtual void InternalUpdate();
  virtual void AnimStartBlend(const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual void AnimFinishBlend(const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual awCheckPathResult_t AnimCheckNextNode(idAnimWebAI *, const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual void EnterHiddenMode(bool);
  virtual void InitTransform(const idVec3 *, const idMat3 *);
  virtual void TeleportToSpace(const idNavigationSpace *, const idVec3 *, const idMat3 *);
  virtual void Reset();
  virtual const idVec3 *GetNavUpAxis(const idVec3 *result);
  virtual int GetMoveInfo(const idAIMoveCmd *, idAIMoveInfo *);
  virtual bool ReachedDestination(const int);
  virtual bool ReachedDestination_2();
  virtual bool HasDestination();
  virtual idAnimBaseFSM::reachDestFlags_t HasReachedDestination(const idAIMoveCmd *, const idAIMoveInfo *);
  virtual bool IsMoveDone();
  virtual void JobSync();
  virtual bool SetOnLink(bool);
  virtual int GetPathPositionAndDirection(const idAnimBaseFSM::pathPositionAndDirectionParms_t *, idVec3 *, idVec3 *);
  virtual int GetClosestReachableAreas(const idVec3 *, float, int, idNpAreaHandle *);
  virtual void RegisterBlendVariables(idAnimator_AnimWeb *);
  virtual void PrintMoveDebugInfo(idGuiListBox *);
  virtual void CallbackFinishLinkTraversal();
  virtual bool CallbackCanUseLink(idInfoLinkSegment *);
  virtual bool AlignToNextPoint();
  virtual void UpdateCachedCorners();
  virtual void UpdateBlendVariables();
  virtual void UpdateAvoidance(const float, idVec3 *);
  virtual bool ShouldStartAASTraversal(idVec3 *, idVec3 *, idMat3 *, aas2Traversal_t *);
  virtual idVec3 *GetTraversalEndpoint(idVec3 *result);
  virtual void SubmitNavTraces();
  virtual void RecordNavTraceResults();
  virtual void InitNavTraceSystem();
  virtual idVec3 *GetPathDelta(idVec3 *result, const idVec3 *, float, bool);
  virtual bool AddCornerAtEveryArea();
  virtual void InternalUpdateBodyRotation();

  __declspec(align(8)) idArray<idAnimFSM::cornerClipInfo_t,31> cornerGroundInfo;
};

// IDA Local Type ordinal 17190; PDB kind: class.
class idAnimFSM_AAS : public idAnimFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17191.
  virtual idTypeInfo *GetType();
  virtual ~idAnimFSM_AAS();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void PrintDebugInfo(idGuiListBox *);
  virtual int GetNumStates();
  virtual idAIStateLite *GetState(const int);
  virtual int GetDefaultStateId();
  virtual void InternalInit();
  virtual void InternalUpdate();
  virtual void AnimStartBlend(const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual void AnimFinishBlend(const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual awCheckPathResult_t AnimCheckNextNode(idAnimWebAI *, const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual void EnterHiddenMode(bool);
  virtual void InitTransform(const idVec3 *, const idMat3 *);
  virtual void TeleportToSpace(const idNavigationSpace *, const idVec3 *, const idMat3 *);
  virtual void Reset();
  virtual const idVec3 *GetNavUpAxis(const idVec3 *result);
  virtual int GetMoveInfo(const idAIMoveCmd *, idAIMoveInfo *);
  virtual bool ReachedDestination(const int);
  virtual bool ReachedDestination_2();
  virtual bool HasDestination();
  virtual idAnimBaseFSM::reachDestFlags_t HasReachedDestination(const idAIMoveCmd *, const idAIMoveInfo *);
  virtual bool IsMoveDone();
  virtual void JobSync();
  virtual bool SetOnLink(bool);
  virtual int GetPathPositionAndDirection(const idAnimBaseFSM::pathPositionAndDirectionParms_t *, idVec3 *, idVec3 *);
  virtual int GetClosestReachableAreas(const idVec3 *, float, int, idNpAreaHandle *);
  virtual void RegisterBlendVariables(idAnimator_AnimWeb *);
  virtual void PrintMoveDebugInfo(idGuiListBox *);
  virtual void CallbackFinishLinkTraversal();
  virtual bool CallbackCanUseLink(idInfoLinkSegment *);
  virtual bool AlignToNextPoint();
  virtual void UpdateCachedCorners();
  virtual void UpdateBlendVariables();
  virtual void UpdateAvoidance(const float, idVec3 *);
  virtual bool ShouldStartAASTraversal(idVec3 *, idVec3 *, idMat3 *, aas2Traversal_t *);
  virtual idVec3 *GetTraversalEndpoint(idVec3 *result);
  virtual void SubmitNavTraces();
  virtual void RecordNavTraceResults();
  virtual void InitNavTraceSystem();
  virtual idVec3 *GetPathDelta(idVec3 *result, const idVec3 *, float, bool);
  virtual bool AddCornerAtEveryArea();
  virtual void InternalUpdateBodyRotation();

  idObstacleAvoidance oa;
  idAAS2Path lastPath;
  obstacleTraceSet_t obstacleTraces;
};

// IDA Local Type ordinal 21399; PDB kind: class.
class idAnimFSM_NP : public idAnimFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21400.
  virtual idTypeInfo *GetType();
  virtual ~idAnimFSM_NP();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void PrintDebugInfo(idGuiListBox *);
  virtual int GetNumStates();
  virtual idAIStateLite *GetState(const int);
  virtual int GetDefaultStateId();
  virtual void InternalInit();
  virtual void InternalUpdate();
  virtual void AnimStartBlend(const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual void AnimFinishBlend(const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual awCheckPathResult_t AnimCheckNextNode(idAnimWebAI *, const idDeclAnimWebNode *, const idDeclAnimWebNode *);
  virtual void EnterHiddenMode(bool);
  virtual void InitTransform(const idVec3 *, const idMat3 *);
  virtual void TeleportToSpace(const idNavigationSpace *, const idVec3 *, const idMat3 *);
  virtual void Reset();
  virtual const idVec3 *GetNavUpAxis(const idVec3 *result);
  virtual int GetMoveInfo(const idAIMoveCmd *, idAIMoveInfo *);
  virtual bool ReachedDestination(const int);
  virtual bool ReachedDestination_2();
  virtual bool HasDestination();
  virtual idAnimBaseFSM::reachDestFlags_t HasReachedDestination(const idAIMoveCmd *, const idAIMoveInfo *);
  virtual bool IsMoveDone();
  virtual void JobSync();
  virtual bool SetOnLink(bool);
  virtual int GetPathPositionAndDirection(const idAnimBaseFSM::pathPositionAndDirectionParms_t *, idVec3 *, idVec3 *);
  virtual int GetClosestReachableAreas(const idVec3 *, float, int, idNpAreaHandle *);
  virtual void RegisterBlendVariables(idAnimator_AnimWeb *);
  virtual void PrintMoveDebugInfo(idGuiListBox *);
  virtual void CallbackFinishLinkTraversal();
  virtual bool CallbackCanUseLink(idInfoLinkSegment *);
  virtual bool AlignToNextPoint();
  virtual void UpdateCachedCorners();
  virtual void UpdateBlendVariables();
  virtual void UpdateAvoidance(const float, idVec3 *);
  virtual bool ShouldStartAASTraversal(idVec3 *, idVec3 *, idMat3 *, aas2Traversal_t *);
  virtual idVec3 *GetTraversalEndpoint(idVec3 *result);
  virtual void SubmitNavTraces();
  virtual void RecordNavTraceResults();
  virtual void InitNavTraceSystem();
  virtual idVec3 *GetPathDelta(idVec3 *result, const idVec3 *, float, bool);
  virtual bool AddCornerAtEveryArea();
  virtual void InternalUpdateBodyRotation();

  idNpNavigator *groundNavigator;
  idNpLink linkTraversing;
  idNpCornerInfo linkEndCorner;
};
