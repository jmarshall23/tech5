#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\decltypeinfo.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13311; PDB kind: class.
class __declspec(align(4)) idDeclTypeInfo : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13312.
  virtual ~idDeclTypeInfo();
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

  idDeclTypeInfo *parent;
  bool hasBeenParsedAtLeastOnce;
};

// IDA Local Type ordinal 28004; PDB kind: typedef.
typedef XGRAPHICS::_XLT_DECLTEX_INFO XLT_DECLTEX_INFO;
