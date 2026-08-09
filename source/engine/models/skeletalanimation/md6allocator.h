#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\skeletalanimation\md6allocator.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14227; PDB kind: class.
class idMD6Allocator
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14229.
  virtual ~idMD6Allocator();
  virtual idMD6Node *Alloc(const idMD6Node::nodeType_t);
  virtual void Free(idMD6Node *);
  virtual void Condense();
  virtual unsigned int Size();
  virtual int NumNodes();
  virtual idMD6Node *NodeForIndex(const int);
  virtual const idMD6Node *NodeForIndex_2(const int);

};

// IDA Local Type ordinal 21758; PDB kind: class.
class idMD6Allocator_New : public idMD6Allocator
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21759.
  virtual ~idMD6Allocator_New();
  virtual idMD6Node *Alloc(const idMD6Node::nodeType_t);
  virtual void Free(idMD6Node *);
  virtual void Condense();
  virtual unsigned int Size();
  virtual int NumNodes();
  virtual idMD6Node *NodeForIndex(const int);
  virtual const idMD6Node *NodeForIndex_2(const int);

  idList<idMD6Node *,19> nodes;
};
