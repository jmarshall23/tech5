#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17200; PDB kind: class.
class idAnimFSMHumanoid : public idAnimFSM_AAS
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17201.
  virtual idTypeInfo *GetType();
  virtual ~idAnimFSMHumanoid();
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

  idAnimStateIdleGround stateIdle;
  idAnimStateMoveGround stateMove;
  idAnimStateDead stateDead;
};
