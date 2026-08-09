#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\animfsm\aianimwebstate.h
// Recovered logical types: 14
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1590; PDB kind: enum.
enum aiAnimWeb_t : __int32
{
  AIANIMWEB_BODY = 0x0,
  AIANIMWEB_MAX = 0x1,
};

// IDA Local Type ordinal 21323; PDB kind: class.
class idAIAnimWebState : public idAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21324.
  virtual ~idAIAnimWebState();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21325; PDB kind: class.
class idAIAnimWebState_Current : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21326.
  virtual ~idAIAnimWebState_Current();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21386; PDB kind: class.
class idAIAnimWebState_Idle : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21387.
  virtual ~idAIAnimWebState_Idle();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21388; PDB kind: class.
class idAIAnimWebState_Movement : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21389.
  virtual ~idAIAnimWebState_Movement();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21393; PDB kind: class.
class idAIAnimWebState_Target : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21394.
  virtual ~idAIAnimWebState_Target();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21830; PDB kind: class.
class idAIAnimWebState_FallTraversal : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21831.
  virtual ~idAIAnimWebState_FallTraversal();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21853; PDB kind: class.
class idAIAnimWebState_BrakingTurn : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21854.
  virtual ~idAIAnimWebState_BrakingTurn();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21898; PDB kind: class.
class idAIAnimWebState_Pain : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21899.
  virtual ~idAIAnimWebState_Pain();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21947; PDB kind: class.
class idAIAnimWebState_Reload : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21948.
  virtual ~idAIAnimWebState_Reload();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 21951; PDB kind: class.
class idAIAnimWebState_Action : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21952.
  virtual ~idAIAnimWebState_Action();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 22002; PDB kind: class.
class idAIAnimWebState_Timeout : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22003.
  virtual ~idAIAnimWebState_Timeout();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 22289; PDB kind: class.
class idAIAnimWebState_Dest : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22290.
  virtual ~idAIAnimWebState_Dest();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};

// IDA Local Type ordinal 22369; PDB kind: class.
class idAIAnimWebState_Turn : public idAIAnimWebState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22370.
  virtual ~idAIAnimWebState_Turn();
  virtual void GetMoveStateString(const idAI2 *, idStr *, posture_t);
  virtual void GetTurnStateString(const idAI2 *, idStr *);

};
