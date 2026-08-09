#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aievents\aieventtrace.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16706; PDB kind: class.
class idAIMoveInterface
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16710.
  virtual aiMoveStatus_t GetMoveStatus();
  virtual const idVec3 *GetFinalPoint();
  virtual bool RecentlyFailedMove(const aiMoveReason_t, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual void MoveFailed(const aiMoveReason_t, const aiMoveStatus_t, const idTypesafeNumber<int,enum gameTimeUnique_t>);
  virtual bool PointInMovementRange(const idVec3 *, const idVec3 *, float, float *);
  virtual bool ReachedPoint(const idVec3 *, const float);
  virtual bool WillReachPoint(const idVec3 *, float, bool);
  virtual float GetReachedEntityDist(const idEntity *, const float);
  virtual bool ReachedEntity(const idEntity *, const float);
  virtual bool WillReachEntity(const idEntity *, const float, const float);
  virtual bool IsPlayingTraversalAnim();
  virtual bool IsLineInNavGraph(const idVec3 *, const idVec3 *, idVec3 *);
  virtual const idVec3 *GetNextPoint();
  virtual const idObstacleInfo *GetObstacleInfo();
  virtual idObstacleInfo *GetObstacleInfo_2();
  virtual int GetLastTravelTime();
  virtual const aas2Traversal_t *GetDestinationTraversal();
  virtual void SetTranslationDeltaScale(const idVec3 *);
  virtual aiMoveStatus_t TestMove(const idAIMoveParms *, idVec3 *, idVec3 *, int *);

};

// IDA Local Type ordinal 21482; PDB kind: class.
class __declspec(align(8)) idAIEventTrace : public idAIEvent
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21483.
  virtual idTypeInfo *GetType();
  virtual ~idAIEventTrace();
  virtual void Clear();
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdate(const int);
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdateAttached(const int);
  virtual bool InternalIsTouching(const idEntity *, const int);
  virtual void InternalDrawDebug(const int, const int, const int);
  virtual float InternalGetIntensity(const idEntity *);
  virtual float GetDistance();

  idVec3 dir;
  idClipQuery traceQuery;
  int lastTraceFrame;
  trace_t lastTraceResult;
};
