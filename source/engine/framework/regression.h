#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\regression.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17424; PDB kind: class.
class idRegression
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17434.
  virtual ~idRegression();
  virtual void MakeTest(const idCmdArgs *);
  virtual void MakeTestLoadGame(const idCmdArgs *);
  virtual void StopTest();
  virtual void PlayTest(const char *, bool);
  virtual void NextTest();
  virtual void DisplayTextScreen(const char *, int);
  virtual idTestReport *GetTestReport();
  virtual void SetName(const char *);
  virtual const char *GetName();
  virtual void QueueEventString(const char *);
  virtual bool ProcessQueuedEvents();
  virtual void SetTestInProgress(bool);
  virtual bool GetTestInProgress();
  virtual void UpdateCurrentTestFile(const char *);
  virtual void SetForceIgnoreNextTestCommands(bool);

};
