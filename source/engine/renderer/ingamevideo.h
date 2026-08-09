#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\ingamevideo.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13819; PDB kind: class.
class idInGameVideoFile : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13820.
  virtual ~idInGameVideoFile();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  unsigned __int8 *buffer;
};

// IDA Local Type ordinal 17674; PDB kind: class.
class idInGameVideoManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17675.
  virtual ~idInGameVideoManager();
  virtual void Init();
  virtual void Shutdown();
  virtual void Update();
  virtual void UnbindAll();
  virtual void BindVideo(int, const idInGameVideoFile *);
  virtual void SetVideoTime(int, int);
  virtual void SetLooping(int, bool);
  virtual void SetPaused(int, bool);
  virtual int GetWeaponVideoIndex();

};

// IDA Local Type ordinal 22991; PDB kind: struct.
struct idInGameVideoManagerLocal::video_t
{
  int timeOffset;
  int pausedTime;
  bool looping;
  int lastFrame;
  const idInGameVideoFile *file;
};

// IDA Local Type ordinal 22992; PDB kind: class.
class idInGameVideoManagerLocal : public idInGameVideoManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22993.
  virtual ~idInGameVideoManagerLocal();
  virtual void Init();
  virtual void Shutdown();
  virtual void Update();
  virtual void UnbindAll();
  virtual void BindVideo(int, const idInGameVideoFile *);
  virtual void SetVideoTime(int, int);
  virtual void SetLooping(int, bool);
  virtual void SetPaused(int, bool);
  virtual int GetWeaponVideoIndex();

  idParallelJobList *parallelJobList;
  idInGameVideoManagerLocal::video_t videos[6];
  videoTranscodeParms_t parms[6];
};
