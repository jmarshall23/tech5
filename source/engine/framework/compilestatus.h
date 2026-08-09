#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\compilestatus.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 993; PDB kind: enum.
enum scFileStatus_t : __int32
{
  SCF_NOTMANAGED = 0x0,
  SCF_NOTIMPORTED = 0x1,
  SCF_CHECKEDOUT = 0x2,
  SCF_CHECKEDOUT_PLUS = 0x3,
  SCF_CHECKEDOUT_BYOTHER = 0x4,
  SCF_CHECKEDOUT_BYOTHER_EXCLUSIVE = 0x5,
  SCF_CHECKEDIN = 0x6,
};

// IDA Local Type ordinal 21610; PDB kind: class.
class idCompileStatus
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21612.
  virtual ~idCompileStatus();
  virtual void SetDialog(struct CDialog *);
  virtual void UnsetDialog();
  virtual void Begin(const char *, bool, bool);
  virtual void End(bool);
  virtual void SetProgressRange(idCompileProgress *, int);
  virtual void SetProgress(idCompileProgress *, int);
  virtual void IncProgress(idCompileProgress *);
  virtual void Indent();
  virtual void Unindent();
  virtual void Print(const char *);
  virtual void Error(const char *);
  virtual void Cancel();
  virtual bool IsCompiling();
  virtual bool IsCancelled();
  virtual bool IsHandled();
  virtual bool HadErrors();
  virtual void SetStatusText(const char *);
  virtual void ShowRenderWindow(bool);
  virtual void MakeCurrentForRender();
  virtual void AddCompileProgress(idCompileProgress *);
  virtual void RemoveCompileProgress(idCompileProgress *);
  virtual int GetProgressRecordCount();
  virtual void StartConsoleListen();
  virtual void EndConsoleListen();

};

// IDA Local Type ordinal 21613; PDB kind: class.
class idCompileStatusHandler
{
public:
  idCompileStatus *compileStatus;
};
