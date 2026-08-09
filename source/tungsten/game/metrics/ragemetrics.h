#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\metrics\ragemetrics.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 12825; PDB kind: class.
class idGaugeMetric : public idMetricRecord
{
public:
  // Recovered virtual interface; IDA vtable ordinal 12826.
  virtual ~idGaugeMetric();
  virtual void WriteHeader(idMetricFile *);
  virtual void SerializeEntry(idMetricFile *);

  int count;
  float min;
  float max;
  float mean;
  float mean2;
  float m2;
  int handle;
  int lastPushFrame;
  int gameState;
};

// IDA Local Type ordinal 15593; PDB kind: class.
class __declspec(align(4)) idRageMetrics : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15594.
  virtual idTypeInfo *GetType();
  virtual ~idRageMetrics();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);

  idRagePlayerMetrics players[6];
  const idGameChallenge *gameChallenge;
  bool gameEnded;
};
