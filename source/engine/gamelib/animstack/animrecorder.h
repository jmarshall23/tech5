#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\animstack\animrecorder.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1934; PDB kind: enum.
enum idAnimRecorder::blockType_t : __int32
{
  RECORD_HEADER_BLOCK = 0x0,
  ANIM_STACK_BLOCK = 0x1,
  INVALID_BLOCK = 0x2,
};

// IDA Local Type ordinal 1935; PDB kind: enum.
enum idAnimRecorder::recordingFileMode_t : __int32
{
  RECORDING_FILE_CLOSED = 0x0,
  RECORDING_FILE_READ = 0x1,
  RECORDING_FILE_WRITE = 0x2,
};

// IDA Local Type ordinal 17490; PDB kind: class.
class __declspec(align(4)) idAnimRecorder
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17491.
  virtual void Serialize(int *, idGameTimeManager *, const bool);
  virtual void Stop();
  virtual void ReadFrames(int);
  virtual ~idAnimRecorder();
  virtual void WriteHeaderBlock();
  virtual bool ReadHeaderBlock();

  idArray<unsigned char,1282> buffer;
  idList<idPair<unsigned short,idAnimRecorder::NameStruct_t>,5> networkIDDict;
  int cachedGameTime;
  int cachedMessageSize;
  int dataStart;
  idCompressor *compressor;
  idFile *file;
  idSerializer *activeSerializer;
  idAnimStack *activeAnimStack;
  idAnimRecorder::recordingFileMode_t recordingFileMode;
  bool isPaused;
};

// IDA Local Type ordinal 17493; PDB kind: struct.
struct idAnimRecorder::NameStruct_t
{
  const char *typeName;
  const char *objectName;
};

// IDA Local Type ordinal 21939; PDB kind: class.
class idAnimRecorder::idSearch_NetworkIDNamePair : public idSearch_Binary<idPair<unsigned short,idAnimRecorder::NameStruct_t>,idAnimRecorder::idSearch_NetworkIDNamePair>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21940.
  virtual ~idSearch_NetworkIDNamePair();
  virtual int Search(const idPair<unsigned short,idAnimRecorder::NameStruct_t> *, unsigned int, const idPair<unsigned short,idAnimRecorder::NameStruct_t> *);
  virtual int Search_FirstGreater(const idPair<unsigned short,idAnimRecorder::NameStruct_t> *, const int, const idPair<unsigned short,idAnimRecorder::NameStruct_t> *);
  virtual int Search_FirstGreaterEqual(const idPair<unsigned short,idAnimRecorder::NameStruct_t> *, const int, const idPair<unsigned short,idAnimRecorder::NameStruct_t> *);
  virtual int Search_LastLess(const idPair<unsigned short,idAnimRecorder::NameStruct_t> *, const int, const idPair<unsigned short,idAnimRecorder::NameStruct_t> *);
  virtual int Search_LastLessEqual(const idPair<unsigned short,idAnimRecorder::NameStruct_t> *, const int, const idPair<unsigned short,idAnimRecorder::NameStruct_t> *);

};

// IDA Local Type ordinal 31409; PDB kind: typedef.
typedef idAnimRecorder *(__fastcall *idAnimRecorderAlloc_t)();
