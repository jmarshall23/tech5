#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\sourcecontrolwrapper.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22324; PDB kind: class.
class __declspec(align(4)) idSourceControlWrapper : public idSourceControl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22325.
  virtual ~idSourceControlWrapper();
  virtual bool Init();
  virtual void Shutdown();
  virtual void SetSilentCheckOut(bool);
  virtual bool GetSilentCheckOut();
  virtual void SetSilentCheckIn(bool);
  virtual bool GetSilentCheckIn();
  virtual bool IsConnected();
  virtual bool IsInitialized();
  virtual int CheckOut(const idList<idStr,5> *);
  virtual int UndoCheckOut(const idList<idStr,5> *);
  virtual int Import(const idList<idStr,5> *, bool, bool, scFileType_t);
  virtual int GetLatest(const idList<idStr,5> *, bool);
  virtual int CheckIn(const idList<idStr,5> *, const idStr *, bool);
  virtual int Delete(const idList<idStr,5> *);
  virtual int UpdateFolder(const char *);
  virtual scFileStatus_t GetFileStatus(const idStr *);
  virtual bool GetFileVersion(const idStr *, int *, int *);
  virtual int GetNumCheckOutUsers(const idStr *);
  virtual void GetCheckOutUser(const idStr *, int, char *, const int);
  virtual void GetUsernameForFileVersion(const idStr *, int, idStr *);
  virtual void GetCurrentWorkspace(idSourceControl::idSourceControlWorkspace *);
  virtual void GetAvailableWorkspaces(struct idList<idSourceControl::idSourceControlWorkspace,5> *);
  virtual void SetWorkspace(const char *);
  virtual void SetWorkspace_2(idSourceControl::idSourceControlWorkspace *);
  virtual bool IsWorkspaceValid();
  virtual idStr *GetUsername(idStr *result);

  idSourceControl *sc;
  unsigned int dllHandle;
  bool loadFailed;
  bool autoInitAttempt;
};
