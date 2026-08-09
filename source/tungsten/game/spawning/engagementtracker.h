#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\spawning\engagementtracker.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15223; PDB kind: class.
class __declspec(align(4)) idEngagementTracker
{
public:
  idEntityPtr<idEntity> lastAttacker;
  int lastAttackerTime;
  int lastNonPlayerEngagementTime;
  float nonPlayerEngagementTimer;
  float playerEngagementTimers[6];
  bool isEngaged;
};
