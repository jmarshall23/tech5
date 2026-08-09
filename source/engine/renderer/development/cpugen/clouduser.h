#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\development\cpugen\clouduser.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23642; PDB kind: class.
class idCloud
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23655.
  virtual ~idCloud();
  virtual bool IsAvailable();
  virtual bool IsRemote();
  virtual void Reset();
  virtual void Heartbeat();
  virtual int NumCloudServers();
  virtual int NumCommandsStillOutstanding();
  virtual idPageGenClient *GetPageGenClient();
  virtual idPixelGenClient *GetPixelGenClient();
  virtual idRenderBumpClient *GetRenderBumpClient();
  virtual void CloudStamp(idRenderWorld *, const idStr *, int, cloudMode_t, const idList<int,5> *);
  virtual void CloudRadPreview(const idStr *, idGenWorld *, const cloudMode_t);
  virtual void CloudRenderBump(const cloudMode_t);
  virtual void GetClusterInfos(struct idList<idComputeClusterInfo,5> *);
  virtual int GetNumQualityPresets();
  virtual const idQualityPreset *GetQualityPreset(const int);
  virtual void LoadQualityPresets();
  virtual int ProcessResponses();
  virtual bool LoadBuildCVars(const idStr *);
  virtual void AddTraceFile(const idStr *, const idStr *, const idStr *);
  virtual int GetOutstandingPages();
  virtual int GetOutstandingMips();
  virtual float GetPagesPerSecond();
  virtual float GetMipsPerSecond();
  virtual void ClearPendingWork();

};
