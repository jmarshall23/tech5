#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15770; PDB kind: class.
class idVehicleBaseFSM : public idFiniteStateMachine
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15779.
  virtual idTypeInfo *GetType();
  virtual ~idVehicleBaseFSM();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual bool CanUse(idFiniteStateMachine *, const int);
  virtual idState *GetErrorState();
  virtual idState *GetDoneState();
  virtual void Save(idFile_String *, const char *);
  virtual void Restart(idFiniteStateMachine *, const int);
  virtual void AddState(idState *);
  virtual int GetUpdateInterval();
  virtual void InitStates(const idFiniteStateMachineParams *);
  virtual void AppendDefaultTransitions(idState *);
  virtual void SetNextState(const idStateData::transResult_t *, const int);
  virtual void SetState(const idStateData::transResult_t *, const int, const bool);
  virtual void SetState_2(idState *, int, bool);
  virtual void SetState_3(const idTypeInfo *, int, bool);

  idStaticList<idVehicleState *,4> stateStack;
  idState *dataState;
  idVS_Idle s_Idle;
  idVS_Wait s_Wait;
};

// IDA Local Type ordinal 15780; PDB kind: class.
class idVehicleFSM : public idVehicleBaseFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15781.
  virtual idTypeInfo *GetType();
  virtual ~idVehicleFSM();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual bool CanUse(idFiniteStateMachine *, const int);
  virtual idState *GetErrorState();
  virtual idState *GetDoneState();
  virtual void Save(idFile_String *, const char *);
  virtual void Restart(idFiniteStateMachine *, const int);
  virtual void AddState(idState *);
  virtual int GetUpdateInterval();
  virtual void InitStates(const idFiniteStateMachineParams *);
  virtual void AppendDefaultTransitions(idState *);
  virtual void SetNextState(const idStateData::transResult_t *, const int);
  virtual void SetState(const idStateData::transResult_t *, const int, const bool);
  virtual void SetState_2(idState *, int, bool);
  virtual void SetState_3(const idTypeInfo *, int, bool);

};

// IDA Local Type ordinal 15783; PDB kind: class.
class idVehicleFSMManager : public idFSMManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15784.
  virtual idTypeInfo *GetType();
  virtual ~idVehicleFSMManager();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual idFiniteStateMachine *AllocFSM(const idTypeInfo *, const idFiniteStateMachineParams *);
  virtual const idFiniteStateMachine *FindFSM(const idTypeInfo *);
  virtual const idFiniteStateMachine *FindFSM_2(const char *);
  virtual idFiniteStateMachine *FindFSM_3(const idTypeInfo *);
  virtual idFiniteStateMachine *FindFSM_4(const char *);
  virtual void FreeFSM(const idTypeInfo *);
  virtual void FreeFSM_2(const char *);

  idList<idVehicleFSM *,5> fsms;
};

// IDA Local Type ordinal 21734; PDB kind: class.
class idVehicleBaseFSM::idVehicleFSMParams : public idFiniteStateMachineParams
{
public:
};
