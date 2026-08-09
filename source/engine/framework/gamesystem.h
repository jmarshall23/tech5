#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\framework\gamesystem.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18667; PDB kind: class.
class idGameSystem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18668.
  virtual ~idGameSystem();
  virtual void Init();
  virtual void Shutdown();
  virtual bool AllocGame(idGame **, const idGameSpawnInfo *, idFile *);
  virtual void FreeGame(idGame **);
  virtual void MinimalGameCleanup(idGame **);

};

// IDA Local Type ordinal 18679; PDB kind: class.
class idGameSystemLocal : public idGameSystem
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18680.
  virtual ~idGameSystemLocal();
  virtual void Init();
  virtual void Shutdown();
  virtual bool AllocGame(idGame **, const idGameSpawnInfo *, idFile *);
  virtual void FreeGame(idGame **);
  virtual void MinimalGameCleanup(idGame **);

  idStaticList<idFile_SaveGame *,2> retainedFiles;
  mgHttpServer *httpServer;
};
