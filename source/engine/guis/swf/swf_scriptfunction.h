#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\swf\swf_scriptfunction.h
// Recovered logical types: 9
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14766; PDB kind: class.
class idSWFScriptFunction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14771.
  virtual ~idSWFScriptFunction();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

};

// IDA Local Type ordinal 14806; PDB kind: struct.
struct __declspec(align(4)) idSWFScriptFunction_Script::parmInfo_t
{
  const char *name;
  unsigned __int8 reg;
};

// IDA Local Type ordinal 14808; PDB kind: class.
class idSWFScriptFunction_Script : public idSWFScriptFunction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14809.
  virtual ~idSWFScriptFunction_Script();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  int refCount;
  unsigned __int16 flags;
  const unsigned __int8 *data;
  unsigned int length;
  idSWFScriptObject *prototype;
  idSWFSpriteInstance *defaultSprite;
  idStaticList<idSWFScriptObject *,19> scope;
  idSWFConstantPool constants;
  idList<idSWFScriptVar,72> registers;
  idList<idSWFScriptFunction_Script::parmInfo_t,72> parameters;
};

// IDA Local Type ordinal 14821; PDB kind: class.
class idSWFScriptFunction_Nested<idSWF> : public idSWFScriptFunction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14822.
  virtual ~idSWFScriptFunction_Nested();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *pThis;
};

// IDA Local Type ordinal 15400; PDB kind: class.
class idSWFScriptFunction_Nested<idPresentablePlayer> : public idSWFScriptFunction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15401.
  virtual ~idSWFScriptFunction_Nested();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idPresentablePlayer *pThis;
};

// IDA Local Type ordinal 16092; PDB kind: class.
class idSWFScriptFunction_Nested<idMainMenu> : public idSWFScriptFunction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16093.
  virtual ~idSWFScriptFunction_Nested();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idMainMenu *pThis;
};

// IDA Local Type ordinal 17652; PDB kind: class.
class idScriptFunction
{
public:
  idEventArg args[16];
  idEntity *owner;
  const function_t *function;
};

// IDA Local Type ordinal 17703; PDB kind: class.
class idSWFScriptFunction_RefCounted : public idSWFScriptFunction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17704.
  virtual ~idSWFScriptFunction_RefCounted();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  int refCount;
};

// IDA Local Type ordinal 20327; PDB kind: class.
class idSWFScriptFunction_CancelChatting : public idSWFScriptFunction_RefCounted
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20328.
  virtual ~idSWFScriptFunction_CancelChatting();
  virtual idSWFScriptVar *Call(idSWFScriptVar *result, idSWFScriptObject *, const idSWFParmList *);
  virtual void AddRef();
  virtual void Release();
  virtual idSWFScriptObject *GetPrototype();
  virtual void SetPrototype(idSWFScriptObject *);

  idSWF *gui;
};
