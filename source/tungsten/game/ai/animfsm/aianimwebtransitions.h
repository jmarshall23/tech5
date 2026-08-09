#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\animfsm\aianimwebtransitions.h
// Recovered logical types: 20
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1443; PDB kind: enum.
enum mainMenuTransition_t : __int32
{
  MENU_TRANSITION_INVALID = 0xFFFFFFFF,
  MENU_TRANSITION_ADVANCE = 0x0,
  MENU_TRANSITION_BACK = 0x1,
  MENU_TRANSITION_FORCE = 0x2,
};

// IDA Local Type ordinal 2319; PDB kind: enum.
enum idAnimWebTransitions::transitionQueryValidation_t::selectionType_t : __int32
{
  CHOOSE_ANGLE_DISTANCE_ERROR = 0x0,
  CHOOSE_CLOSEST_TO_DESTINATION = 0x1,
  CHOOSE_CLOSEST_TO_SEGMENT = 0x2,
  CHOOSE_CLOSEST_ANGLE_START = 0x3,
  CHOOSE_CLOSEST_TO_PATH_RELATIVE = 0x4,
};

// IDA Local Type ordinal 2342; PDB kind: enum.
enum idAnimWebTransitions::navTraceResult_t : __int32
{
  TRACE_CLEAR = 0x0,
  TRACE_BLOCKED = 0x1,
  TRACE_WAITING = 0x2,
};

// IDA Local Type ordinal 17173; PDB kind: struct.
struct idAnimWebTransitions::navTraceData_t
{
  idVec3 start;
  idVec3 stop;
  float fraction;
  int num[2];
  int numIndex;
};

// IDA Local Type ordinal 17175; PDB kind: struct.
struct idAnimWebTransitions::transitionData_t
{
  idVec3 deltaOrigin;
  idMat3 deltaAxis;
  float deltaCorrectEndDistanceSqr;
  idVec3 apex;
  idVec3 deltaCorrectEndTranslation;
  idMat3 deltaCorrectEndAxis;
  idVec3 deltaCorrectGoalTranslation;
  idMat3 deltaCorrectGoalAxis;
  bool hasApex;
  int flags;
  float approximatePathDistance;
  idAnimWebState src;
  idAnimWebState via;
  idAnimWebState dst;
  const idMD6Anim *anim;
  idArray<idAnimWebTransitions::navTraceData_t,8> navTraces;
  int selectionIndex;
};

// IDA Local Type ordinal 17177; PDB kind: struct.
struct __declspec(align(4)) idAnimWebTransitions::transitionCache_t
{
  idAnimWebState srcState;
  idAnimWebState dstState;
  int lastCheckFlags;
  idList<idAnimWebTransitions::transitionData_t,5> transitions;
  float maximumDeltaOriginDistanceSqr;
  float maximumPathDistance;
  float minimumDeltaOriginDistanceSqr;
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> nodeIndex;
};

// IDA Local Type ordinal 17178; PDB kind: struct.
struct idAnimWebTransitions::transitionQueryResult_t
{
  idAnimWebState dst;
  idAnimWebState via;
  idVec3 startOrigin;
  idVec3 destOrigin;
  int selectionIndex;
  float approximatePathDistance;
  const idMD6Anim *anim;
};

// IDA Local Type ordinal 20672; PDB kind: class.
class PCI_IsAnimWebTransitioning : public idAIStateTransitionStatic
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20673.
  virtual idTypeInfo *GetType();
  virtual ~PCI_IsAnimWebTransitioning();
  virtual int Evaluate(idFiniteStateMachine *, idState *, const int);
  virtual void InternalSave(idFile_String *, const char *, const idList<idStateTransition::transDest_t,5> *);
  virtual void Save(idFile_String *, const char *, const idList<idStateTransition::transDest_t,5> *);
  virtual idAIStateTransition::aiTransCode_t Evaluate_2(idAI2 *, idAIFSM *, idAIState *, const int);

};

// IDA Local Type ordinal 21391; PDB kind: struct.
struct idAnimWebTransitions::transitionQueryParms_t
{
  idVec3 sourceOrigin1;
  idVec3 sourceOrigin2;
  idMat3 sourceAxis;
  idVec3 destinationOrigin;
  idMat3 destinationAxis;
  idVec3 turnPoint;
  float totalPathDistance;
  float pathDistanceAlongAxis;
  int debugDrawTime;
  idStaticList<idVec3,31> cachedCorners;
};

// IDA Local Type ordinal 21392; PDB kind: struct.
struct __declspec(align(4)) idAnimWebTransitions::transitionQueryValidation_t
{
  idAnimWebTransitions::transitionQueryValidation_t::selectionType_t selectType;
  float requiredSourceAlignAngleDot;
  float requiredMoveAlignAngleDot;
  float movementDistanceFudge;
  bool usePathDirectionForMoveAlign;
  bool usePathDirectionForSourceAlign;
  float maxMoveDistanceMultiplier;
  int allowedFlags;
  int requiredFlags;
  int suggestedFlags;
  bool checkMaxMovementDistance;
  float requiredApexAlignAngleDot;
  bool usePathDirectionForApexAlign;
  bool checkAnimTooShort;
  bool navProbeAnimTranslation;
  bool navProbeAnimApex;
  bool navProbeToPathPosition;
  bool allowRejections;
};

// IDA Local Type ordinal 21401; PDB kind: class.
class idAIAnimWebState_Transition : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21402.
  virtual ~idAIAnimWebState_Transition();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21404; PDB kind: class.
class idAnimWebTransitions
{
public:
};

// IDA Local Type ordinal 21962; PDB kind: class.
class idAIAnimWebState_IdleToMoveTransition : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21963.
  virtual ~idAIAnimWebState_IdleToMoveTransition();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21976; PDB kind: class.
class idAIAnimWebState_MoveToIdleTransition : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21977.
  virtual ~idAIAnimWebState_MoveToIdleTransition();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

  float stopDistance;
};

// IDA Local Type ordinal 22371; PDB kind: struct.
struct idAnimWebTransitions::transition_t
{
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> src;
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> via;
  idIndex<short,enum idDeclAnimWeb::invalidNodeIndex_t> dst;
};

// IDA Local Type ordinal 22372; PDB kind: struct.
struct idAnimWebTransitions::defaultArrivalTransitionValidation_t : idAnimWebTransitions::transitionQueryValidation_t
{
};

// IDA Local Type ordinal 22373; PDB kind: struct.
struct idAnimWebTransitions::defaultStepTransitionValidation_t : idAnimWebTransitions::transitionQueryValidation_t
{
};

// IDA Local Type ordinal 22374; PDB kind: struct.
struct idAnimWebTransitions::defaultFlightTransitionValidation_t : idAnimWebTransitions::transitionQueryValidation_t
{
};

// IDA Local Type ordinal 22375; PDB kind: struct.
struct idAnimWebTransitions::defaultSoftStopTransitionValidation_t : idAnimWebTransitions::transitionQueryValidation_t
{
};

// IDA Local Type ordinal 22376; PDB kind: struct.
struct idAnimWebTransitions::defaultDepartureTransitionValidation_t : idAnimWebTransitions::transitionQueryValidation_t
{
};
