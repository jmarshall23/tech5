#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declmanagerlocal.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23706; PDB kind: class.
class idDeclManagerLocal : public idDeclManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23707.
  virtual ~idDeclManagerLocal();
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

  idList<idDeclInfo *,46> declTypes;
  idList<idDeclFile *,46> loadedFiles;
  int loadedFilesDynamicStartIndex;
  idList<declFileDependency_t,46> declFileDependencies;
  int dependenciesDynamicStartIndex;
  int checksum;
  idList<idStr,5> multiplayerDeclOverrides;
  idList<idStr,5> registeredDeclLogTypes;
};

// IDA Local Type ordinal 23708; PDB kind: struct.
struct idDeclManagerLocal::Init::__l10::declFolder_t
{
  const char *folder;
  const char *extension;
  idDeclInfo *defaultType;
};
