#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declmanager.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17601; PDB kind: class.
class idDeclManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17602.
  virtual ~idDeclManager();
  virtual void Init();
  virtual void Shutdown();
  virtual void Reload(bool);
  virtual void MarkStatic();
  virtual void FreeDynamic();
  virtual void RegisterDeclFolder(const char *, const char *, idDeclInfo *);
  virtual int GetNumDeclTypes();
  virtual idDeclInfo *GetDeclType(const char *);
  virtual idDeclInfo *GetDeclType_2(int);
  virtual idDeclInfo *GetDeclTypeFromClassname(const char *);
  virtual idDecl *CreateNewDecl(idDeclInfo *, const char *, const char *, const char *);
  virtual void AddDependency(idDecl *, const char *);
  virtual void AddDependency_2(idDecl *, const idDecl *);
  virtual void ArgCompletion_DeclTypeName(idAutoComplete *);
  virtual void ArgCompletion_DeclName(idAutoComplete *, idDeclInfo *);
  virtual void PrintMultiplayerDeclOverrides();

};
