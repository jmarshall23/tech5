#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\weapons\trajectory.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15603; PDB kind: class.
class idTrajectory : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15606.
  virtual idTypeInfo *GetType();
  virtual ~idTrajectory();
  virtual bool WaitingOnJob();
  virtual bool HasResults();
  virtual void ClearResults();
  virtual int NumTrajectories();
  virtual idTrajectory::parms_t *GetTrajectoryParms(const int);
  virtual const idTrajectory::parms_t *GetTrajectoryParms_2(const int);
  virtual const idTrajectory::results_t *GetSimulationResults(const int);

};

// IDA Local Type ordinal 15604; PDB kind: struct.
struct idTrajectory::parms_t
{
  float time;
  float speed;
  float gravity;
};

// IDA Local Type ordinal 15605; PDB kind: struct.
const struct __declspec(align(4)) idTrajectory::results_t
{
  trace_t impactResult;
  bool impacted;
};
