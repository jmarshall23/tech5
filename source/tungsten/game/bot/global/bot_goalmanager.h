#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\global\bot_goalmanager.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16523; PDB kind: class.
class idBotGoalManager : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16524.
  virtual idTypeInfo *GetType();
  virtual ~idBotGoalManager();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Think(const int);

};

// IDA Local Type ordinal 20347; PDB kind: class.
class idBotGoalManager_DM : public idBotGoalManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20348.
  virtual idTypeInfo *GetType();
  virtual ~idBotGoalManager_DM();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Think(const int);

};

// IDA Local Type ordinal 20349; PDB kind: class.
class idBotGoalManager_TDM : public idBotGoalManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20350.
  virtual idTypeInfo *GetType();
  virtual ~idBotGoalManager_TDM();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Think(const int);

};

// IDA Local Type ordinal 20351; PDB kind: class.
class idBotGoalManager_CTF : public idBotGoalManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20352.
  virtual idTypeInfo *GetType();
  virtual ~idBotGoalManager_CTF();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Think(const int);

};

// IDA Local Type ordinal 20353; PDB kind: class.
class idBotGoalManager_HORDE : public idBotGoalManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20354.
  virtual idTypeInfo *GetType();
  virtual ~idBotGoalManager_HORDE();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Think(const int);

};

// IDA Local Type ordinal 20355; PDB kind: class.
class idBotGoalManager_DOM : public idBotGoalManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20356.
  virtual idTypeInfo *GetType();
  virtual ~idBotGoalManager_DOM();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Think(const int);

};
