#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sys\sys_local.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22635; PDB kind: class.
class idSysLocal : public idSys
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22636.
  virtual ~idSysLocal();
  virtual __int64 GetClockTicks();
  virtual __int64 ClockTicksPerSecond();
  virtual cpuid_t GetProcessorId();
  virtual const char *GetProcessorString();
  virtual const char *FPU_GetState();
  virtual bool FPU_StackIsEmpty();
  virtual void FPU_SetFTZ(bool);
  virtual void FPU_SetDAZ(bool);
  virtual void FPU_EnableExceptions(int);
  virtual unsigned int DLL_Load(const char *);
  virtual void *DLL_GetProcAddress(unsigned int, const char *);
  virtual void DLL_Unload(unsigned int);
  virtual void DLL_GetFileName(const char *, char *, int);
  virtual void OpenURL(const char *, bool);
  virtual void StartProcess(const char *, bool);
  virtual const char *GetClipboardData();
  virtual void SetClipboardData(const char *);
  virtual int Milliseconds();
  virtual unsigned int VblCount();
  virtual void PrintStackTrace();
  virtual idJoystick *Joystick();
  virtual idKeyboard *Keyboard();
  virtual idMouse *Mouse();
  virtual const char *GetOSUserName();
  virtual const char *GetMachineName();
  virtual void QueueEvent(sysEventType_t, int, int, int, void *, int);
  virtual void GenerateEvents();
  virtual sysEvent_t *GetEvent(sysEvent_t *result);
  virtual void ClearEvents();

};
