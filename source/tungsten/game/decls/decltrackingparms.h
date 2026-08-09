#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\decltrackingparms.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15951; PDB kind: struct.
struct trackingParms_t
{
  float kickScale;
  idTypesafeNumber<float,enum DegreesUnique_t> rate;
  idTypesafeNumber<float,enum DegreesUnique_t> acceleration;
  idTypesafeNumber<float,enum DegreesUnique_t> deceleration;
  float springMass;
  float springTightness;
  float springDampen;
  float springMaxSpeed;
  float springRestLength;
  float springMaxLength;
};

// IDA Local Type ordinal 15953; PDB kind: class.
class idDeclTrackingParms : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15954.
  virtual ~idDeclTrackingParms();
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

  idList<trackingParms_t,5> parms;
};
