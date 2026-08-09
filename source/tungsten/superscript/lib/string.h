#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\superscript\lib\string.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13080; PDB kind: class.
class idFile_String : public idFile_Memory
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13081.
  virtual ~idFile_String();
  virtual const char *GetName();
  virtual const char *GetFullPath();
  virtual unsigned int Read(void *, unsigned int);
  virtual unsigned int Write(const void *, unsigned int);
  virtual unsigned int ReadOfs(__int64, void *, unsigned int);
  virtual unsigned int WriteOfs(__int64, const void *, unsigned int);
  virtual bool Lock(__int64, unsigned int, fsLock_t);
  virtual bool Unlock(__int64, unsigned int);
  virtual __int64 Length();
  virtual void SetLength(unsigned int);
  virtual __int64 Tell();
  virtual int Seek(__int64, fsOrigin_t);
  virtual unsigned int Printf(const char *, ...);
  virtual unsigned int VPrintf(const char *, char *);
  virtual unsigned int WriteFloatString(const char *, ...);
  virtual unsigned int Timestamp();
  virtual void Flush();
  virtual void ForceFlush();
  virtual int GetSectorSize();
  virtual fsDevice_t GetDevice();
  virtual bool IsOSNative();
  virtual void Clear(bool);

};
