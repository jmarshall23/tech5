#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\superscript\generated\util\action.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2422; PDB kind: enum,struct.
enum swfAction_t : __int32
{
  Action_End = 0x0,
  Action_NextFrame = 0x4,
  Action_PrevFrame = 0x5,
  Action_Play = 0x6,
  Action_Stop = 0x7,
  Action_ToggleQuality = 0x8,
  Action_StopSounds = 0x9,
  Action_GotoFrame = 0x81,
  Action_GetURL = 0x83,
  Action_WaitForFrame = 0x8A,
  Action_SetTarget = 0x8B,
  Action_GoToLabel = 0x8C,
  Action_Add = 0xA,
  Action_Subtract = 0xB,
  Action_Multiply = 0xC,
  Action_Divide = 0xD,
  Action_Equals = 0xE,
  Action_Less = 0xF,
  Action_And = 0x10,
  Action_Or = 0x11,
  Action_Not = 0x12,
  Action_StringEquals = 0x13,
  Action_StringLength = 0x14,
  Action_StringExtract = 0x15,
  Action_Pop = 0x17,
  Action_ToInteger = 0x18,
  Action_GetVariable = 0x1C,
  Action_SetVariable = 0x1D,
  Action_SetTarget2 = 0x20,
  Action_StringAdd = 0x21,
  Action_GetProperty = 0x22,
  Action_SetProperty = 0x23,
  Action_CloneSprite = 0x24,
  Action_RemoveSprite = 0x25,
  Action_Trace = 0x26,
  Action_StartDrag = 0x27,
  Action_EndDrag = 0x28,
  Action_StringLess = 0x29,
  Action_RandomNumber = 0x30,
  Action_MBStringLength = 0x31,
  Action_CharToAscii = 0x32,
  Action_AsciiToChar = 0x33,
  Action_GetTime = 0x34,
  Action_MBStringExtract = 0x35,
  Action_MBCharToAscii = 0x36,
  Action_MBAsciiToChar = 0x37,
  Action_WaitForFrame2 = 0x8D,
  Action_Push = 0x96,
  Action_Jump = 0x99,
  Action_GetURL2 = 0x9A,
  Action_If = 0x9D,
  Action_Call = 0x9E,
  Action_GotoFrame2 = 0x9F,
  Action_Delete = 0x3A,
  Action_Delete2 = 0x3B,
  Action_DefineLocal = 0x3C,
  Action_CallFunction = 0x3D,
  Action_Return = 0x3E,
  Action_Modulo = 0x3F,
  Action_NewObject = 0x40,
  Action_DefineLocal2 = 0x41,
  Action_InitArray = 0x42,
  Action_InitObject = 0x43,
  Action_TypeOf = 0x44,
  Action_TargetPath = 0x45,
  Action_Enumerate = 0x46,
  Action_Add2 = 0x47,
  Action_Less2 = 0x48,
  Action_Equals2 = 0x49,
  Action_ToNumber = 0x4A,
  Action_ToString = 0x4B,
  Action_PushDuplicate = 0x4C,
  Action_StackSwap = 0x4D,
  Action_GetMember = 0x4E,
  Action_SetMember = 0x4F,
  Action_Increment = 0x50,
  Action_Decrement = 0x51,
  Action_CallMethod = 0x52,
  Action_NewMethod = 0x53,
  Action_BitAnd = 0x60,
  Action_BitOr = 0x61,
  Action_BitXor = 0x62,
  Action_BitLShift = 0x63,
  Action_BitRShift = 0x64,
  Action_BitURShift = 0x65,
  Action_StoreRegister = 0x87,
  Action_ConstantPool = 0x88,
  Action_With = 0x94,
  Action_DefineFunction = 0x9B,
  Action_InstanceOf = 0x54,
  Action_Enumerate2 = 0x55,
  Action_StrictEquals = 0x66,
  Action_Greater = 0x67,
  Action_StringGreater = 0x68,
  Action_Extends = 0x69,
  Action_CastOp = 0x2B,
  Action_ImplementsOp = 0x2C,
  Action_Throw = 0x2A,
  Action_Try = 0x8F,
  Action_DefineFunction2 = 0x8E,
};

// IDA Local Type ordinal 14213; PDB kind: class.
class idFXAction
{
public:
  int tagIndex;
  idVec3 startOrg;
  idMat3 startAxis;
  idRenderLight *rLight;
  idRenderModel *rModel;
  idRenderModelParticle *rParticle;
  int screenPrtHandle;
  idLensFlareManager flareManager;
  idRibbonManager ribbonManager;
  idList<tagData_t,109> tagData;
  idVec3 lastParticleDropPos;
  idVec4 renderParmStartValue;
  idAngles randomAngles;
  int viewCallbacksID;
};

// IDA Local Type ordinal 14478; PDB kind: class.
class idFaction
{
public:
  const idDeclFaction *myFaction;
  idRelationshipList relationships;
};

// IDA Local Type ordinal 17013; PDB kind: class.
class __unaligned __declspec(align(4)) idAction_Pain : public idAIAction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33773.
  virtual idTypeInfo *GetType();
  virtual ~idAction_Pain();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Save(const idFiniteStateMachine *, idFile_String *, const char *);
  virtual void InternalInitState(const idFiniteStateMachine *);
  virtual bool InternalCanUse(idFiniteStateMachine *, const int);
  virtual void InternalEnterState(idFiniteStateMachine *, const int);
  virtual void InternalExitState(idFiniteStateMachine *, const int);
  virtual void InternalWork(idFiniteStateMachine *, const int);
  virtual void InternalReenterState(idFiniteStateMachine *, const int, const int);
  virtual bool InternalIsStateWaiting(idFiniteStateMachine *, const int);
  virtual void InternalGetDebugString(idStr *);
  virtual bool AIState_CanUse(idAI2 *, idAIFSM *, const int);
  virtual void AIState_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIState_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIState_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIState_ReenterState(idAI2 *, idAIFSM *, const int, const int);
  virtual bool AIState_IsWaiting(idAI2 *, idAIFSM *, const int);
  virtual const idEventDef *GetActionEventDef();
  virtual int GetActionFlags();
  virtual void AIAction_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ReenterState(idAI2 *, idAIFSM *, const int);
  virtual bool AIAction_IsWaiting(idAI2 *, idAIFSM *, const int);

};

// IDA Local Type ordinal 17032; PDB kind: class.
class __unaligned __declspec(align(4)) idAction_Wait : public idAIAction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33825.
  virtual idTypeInfo *GetType();
  virtual ~idAction_Wait();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Save(const idFiniteStateMachine *, idFile_String *, const char *);
  virtual void InternalInitState(const idFiniteStateMachine *);
  virtual bool InternalCanUse(idFiniteStateMachine *, const int);
  virtual void InternalEnterState(idFiniteStateMachine *, const int);
  virtual void InternalExitState(idFiniteStateMachine *, const int);
  virtual void InternalWork(idFiniteStateMachine *, const int);
  virtual void InternalReenterState(idFiniteStateMachine *, const int, const int);
  virtual bool InternalIsStateWaiting(idFiniteStateMachine *, const int);
  virtual void InternalGetDebugString(idStr *);
  virtual bool AIState_CanUse(idAI2 *, idAIFSM *, const int);
  virtual void AIState_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIState_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIState_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIState_ReenterState(idAI2 *, idAIFSM *, const int, const int);
  virtual bool AIState_IsWaiting(idAI2 *, idAIFSM *, const int);
  virtual const idEventDef *GetActionEventDef();
  virtual int GetActionFlags();
  virtual void AIAction_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ReenterState(idAI2 *, idAIFSM *, const int);
  virtual bool AIAction_IsWaiting(idAI2 *, idAIFSM *, const int);

};

// IDA Local Type ordinal 23602; PDB kind: class.
class idKeyAction
{
public:
  cmdGenButton_t usercmdAction;
  idStr binding;
};

// IDA Local Type ordinal 25729; PDB kind: struct.
struct _XCPT_ACTION
{
  unsigned int XcptNum;
  int SigNum;
  void (__fastcall *XcptAction)(int);
};
