#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aimovestate.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1587; PDB kind: enum.
enum aiMovePushStatus_t : __int32
{
  AIMOVEPUSHSTATUS_PUSH_NONE = 0x0,
  AIMOVEPUSHSTATUS_PUSH_OTHER_NPCS = 0x1,
  AIMOVEPUSHSTATUS_PUSH_PLAYERS = 0x2,
  AIMOVEPUSHSTATUS_PUSH_PLAYERS_AND_NPCS = 0x3,
  AIMOVEPUSHSTATUS_MAX = 0x4,
};

// IDA Local Type ordinal 2246; PDB kind: enum.
enum aiMoveStatus_t : __int32
{
  AIMOVESTATUS_DONE = 0x0,
  AIMOVESTATUS_MOVING = 0x1,
  AIMOVESTATUS_ERROR = 0x2,
  AIMOVESTATUS_NO_AAS = 0x3,
  AIMOVESTATUS_INVALID_ENTITY = 0x4,
  AIMOVESTATUS_UNREACHABLE = 0x5,
  AIMOVESTATUS_NOT_IN_AAS = 0x6,
  AIMOVESTATUS_PATHING_FAILED = 0x7,
  AIMOVESTATUS_OBSTRUCTED = 0x8,
  AIMOVESTATUS_NO_PATH_GROUP = 0x9,
  AIMOVESTATUS_NO_PATH_POINT = 0xA,
  AIMOVESTATUS_STUCK = 0xB,
  AIMOVESTATUS_MAX = 0xC,
};

// IDA Local Type ordinal 2347; PDB kind: enum.
enum idAIMoveState::smoothAnimType_t : __int32
{
  SMOOTH_ANIM_INVALID = 0x0,
  SMOOTH_ANIM_START = 0x1,
  SMOOTH_ANIM_TURN = 0x2,
  SMOOTH_ANIM_STOP = 0x3,
};

// IDA Local Type ordinal 2348; PDB kind: enum.
enum idAIMoveState::destinationSector_t : __int32
{
  SECTOR_INVALID = 0x0,
  SECTOR_FORWARD = 0x1,
  SECTOR_BACKWARD = 0x2,
  SECTOR_LEFT = 0x3,
  SECTOR_RIGHT = 0x4,
};

// IDA Local Type ordinal 2350; PDB kind: enum.
enum idAIMoveState::lerpAxisFlags_t : __int32
{
  LERPAXIS_X = 0x1,
  LERPAXIS_Y = 0x2,
  LERPAXIS_Z = 0x4,
};

// IDA Local Type ordinal 16711; PDB kind: class.
class idAIMoveState : public idAIMoveInterface
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16716.
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
  virtual ~idAIMoveState();

  idAI2 *ai;
  int lastUpdateMS;
  idAIMoveParms moveParms;
  aiMovementMode_t movementMode;
  aiVelocityType_t velocityType;
  aiMoveStatus_t moveStatus;
  idAIMoveState::smoothAnimType_t curSmoothAnimType;
  idVec3 nextPoint;
  float maxMoveSpeed;
  float accelRate;
  float decelRate;
  idObstacleInfo obstacleInfo;
  idAIOrientation moveOrientation;
  idVec3 finalPoint;
  idVec3 lastFinalPoint;
  idQuat traversalOrientation;
  unsigned __int8 : 3;
  __int8 startedMovementAnim : 1;
  __int8 isPlayingTraversalAnim : 1;
  __int8 aligningToGoal : 1;
  __int8 inControl : 1;
  __int8 alignToTraversalOrientation : 1;
  idAAS2Path lastPath;
  idVec3 stuckRefPoint;
  int stuckTime;
  float accumulatedDeltaLen;
  int numZeroVelocityFrames;
  int startMoveFrame;
  int lastTravelTime;
  int lastMoveTime;
  int lastAreaNum;
  float turnRateScale;
  float actualTurnAngle;
  float accumulatedTurnAngle;
  int turnFramesRemaining;
  int totalTurnFrames;
  idObstacleAvoidance oa;
  int lerpAxisFlags;
  int endLerpTime;
  idVec3 lerpDest;
  idVec3 lerpDelta;
  bool perfectGotInitial;
  idQuat perfectInitialRotation;
  idVec3 perfectInitialPosition;
  idQuat perfectOriginRotation;
  idVec3 perfectOriginPosition;
  int perfectMovementDuration;
  int startPerfectMovementTime;
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> perfectMovementSwi;
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> perfectMovementSi;
  idVec3 traversalStartPoint;
  idVec3 traversalEndPoint;
  overrideAnim_t traversalAnimToPlay;
  int remainingTransitionFrames;
  idVec3 translationScale;
  idStaticList<moveFailureInfo_t,2> moveFailures;
};

// IDA Local Type ordinal 23755; PDB kind: struct.
struct slideMoveState_t
{
  idVec3 velocity;
  idVec3 endVelocity;
  contactInfo_t firstContact;
  float fractionRemaining;
  float steppedUp;
  idVec3 startNormal;
  idVec3 planes[4];
  int numPlanes;
  int pad;
};
