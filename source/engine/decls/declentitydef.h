#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declentitydef.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13464; PDB kind: class.
class idDeclEntityDef : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13466.
  virtual ~idDeclEntityDef();
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
  virtual void SetInherit(const char *);
  virtual void SetClass(const char *);
  virtual const char *GetInherit();
  virtual const char *GetClass();
  virtual const char *GetEntityState();
  virtual int GetEntityStateLength();
  virtual int GetEntityStateLineNumber();
  virtual const char *GetEntityStateWithInheritance();
  virtual int GetEntityStateWithInheritanceLength();
  virtual int GetEntityStateWithInheritanceLineNumber();
  virtual void SetInheritedClass(bool);
  virtual void SetEntityState(const char *, bool);
  virtual void SetEntityState_2(const idTypeInfoTree *, bool, bool);
  virtual const idDeclEntityDef *GetListedParent();
  virtual bool IsParent(const idDeclEntityDef *);
  virtual void BuildText(const char *, const char *);
  virtual void GetTextWithInheritance(idStr *, bool);

  idAtomicString inherit;
  idAtomicString className;
  idEntityDefEditorVars editorVars;
  int stateOffset;
  int stateLineNumberOffset;
  bool expandInheritance;
  idStr entityStateWithInheritanceText;
  const idDeclEntityDef *listedParent;
};
