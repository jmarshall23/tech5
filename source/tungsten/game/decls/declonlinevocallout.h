#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declonlinevocallout.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15306; PDB kind: class.
class idDeclOnlineScoringCallout : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15307.
  virtual ~idDeclOnlineScoringCallout();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  const idSoundShader *sound;
  idStrId text;
  const idMaterial *icon;
  int priority;
};

// IDA Local Type ordinal 15553; PDB kind: class.
class idDeclOnlineVOCallout : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15554.
  virtual ~idDeclOnlineVOCallout();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  soundShaderParms_t parms;
  const idDeclVoiceOver *takenLead;
  const idDeclVoiceOver *tiedLead;
  const idDeclVoiceOver *lostLead;
  const idDeclVoiceOver *impressive;
  const idDeclVoiceOver *doubleKill;
  const idDeclVoiceOver *tripleKill;
  const idDeclVoiceOver *quadKill;
  const idDeclVoiceOver *slaughter;
  const idDeclVoiceOver *revenge;
  const idDeclVoiceOver *airMail;
  const idDeclVoiceOver *pull;
  const idDeclVoiceOver *afterLife;
  const idDeclVoiceOver *maxChain;
  const idDeclVoiceOver *chainBreaker;
  const idDeclVoiceOver *denial;
  const idDeclVoiceOver *closeCall;
  const idDeclVoiceOver *airRally;
};
