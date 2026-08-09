#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\aas2\obstacleavoidancemanagerlocal.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23498; PDB kind: class.
class idObstacleAvoidanceManagerLocal : public idObstacleAvoidanceManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23499.
  virtual ~idObstacleAvoidanceManagerLocal();
  virtual void Init(idParallelJobList *);
  virtual void Shutdown();
  virtual void AllocObstacleBuffers(idObstacleAvoidance *);
  virtual void FreeObstacleBuffers(idObstacleAvoidance *);
  virtual void FrameFreeObstacleBuffers();
  virtual idParallelJobList *GetJobList();

  idParallelJobList *jobList;
  idList<idObstacleBuffers *,5> usedBuffers;
  idList<idObstacleBuffers *,5> freeBuffers;
  idList<idObstacleBuffers *,5> toBeFreedBuffers;
};
