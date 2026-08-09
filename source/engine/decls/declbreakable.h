#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declbreakable.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14552; PDB kind: class.
class idDeclBreakable : public idDecl
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14553.
  virtual ~idDeclBreakable();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  idAtomicString modelName;
  int numPieces;
  idBreakableSettings settings;
  idList<idBreakableExplosion,59> explosions;
  idList<idBreakableTrail,59> trails;
  idList<int,59> armoredPieces;
  idList<int,59> healthPieces;
  idList<idBreakableDecal,59> decals;
  idList<idBreakablePieceDecal,5> pieceDecals;
  idBreakableSpark sparks;
};
