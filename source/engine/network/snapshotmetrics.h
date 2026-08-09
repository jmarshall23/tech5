#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\network\snapshotmetrics.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22308; PDB kind: class.
class idSnapshotMetrics
{
public:
  idStaticList<idStr,16> ignoreList;
  idStaticList<idStr,16> watchList;
  bool printNextReport;
  float SNAPSHOTS_DRAW_SCALE;
  float SNAPSHOTS_Y_OFFSET;
  float SNAPSHOTS_X_OFFSET;
  float SNAPSHOTS_Y_SPACING;
  float curY;
  int width;
  int height;
  int nameLen;
  int lastReportMS;
  int guiOffset;
  int nextKeyEvent;
  idArray<int,6> peerSeq;
};

// IDA Local Type ordinal 22309; PDB kind: class.
class idSnapshotMetrics::idSnapshotMetricRecord : public idMetricRecord
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22310.
  virtual ~idSnapshotMetricRecord();
  virtual void WriteHeader(idMetricFile *);
  virtual void SerializeEntry(idMetricFile *);

  idStr text;
};
