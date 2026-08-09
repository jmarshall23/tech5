#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\cuttertimer.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21739; PDB kind: class.
class idCutterTimerTree::TreeItem
{
public:
  idCutterTimerTree::TreeItem *next;
  idCutterTimerTree::TreeItem *parent;
  idCutterTimerTree::TreeItem *children;
  idStr name;
  idTimer timer;
  idTimer total;
};

// IDA Local Type ordinal 21919; PDB kind: class.
class __declspec(align(8)) idCutterTimerTree
{
public:
  idList<idCutterTimerTree::TreeItem *,5> items;
  idCutterTimerTree::TreeItem *current;
  idCutterTimerTree::TreeItem report;
  bool enabled;
};

// IDA Local Type ordinal 22068; PDB kind: class.
class idCutterTimer
{
public:
  idHashTable<idTimer> timers;
  idTimer *timer;
  idStr reportName;
};

// IDA Local Type ordinal 22073; PDB kind: class.
class idCutterTimerTreeScope
{
public:
  idCutterTimerTree *tree;
};
