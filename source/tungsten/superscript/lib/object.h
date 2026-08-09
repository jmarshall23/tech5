#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\superscript\lib\object.h
// Recovered logical types: 12
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 309; PDB kind: enum.
enum _KOBJECTS : __int32
{
  EventNotificationObject = 0x0,
  EventSynchronizationObject = 0x1,
  MutantObject = 0x2,
  ProcessObject = 0x3,
  QueueObject = 0x4,
  SemaphoreObject = 0x5,
  ThreadObject = 0x6,
  Spare1Object = 0x7,
  TimerNotificationObject = 0x8,
  TimerSynchronizationObject = 0x9,
  Spare2Object = 0xA,
  Spare3Object = 0xB,
  Spare4Object = 0xC,
  Spare5Object = 0xD,
  Spare6Object = 0xE,
  Spare7Object = 0xF,
  Spare8Object = 0x10,
  Spare9Object = 0x11,
  ApcObject = 0x12,
  DpcObject = 0x13,
  DeviceQueueObject = 0x14,
  EventPairObject = 0x15,
  InterruptObject = 0x16,
  ProfileObject = 0x17,
};

// IDA Local Type ordinal 3745; PDB kind: struct.
struct _FILE_OBJECT
{
  __int16 Type;
  unsigned __int8 Flags;
  unsigned __int8 Flags2;
  _DEVICE_OBJECT *DeviceObject;
  void *FsContext;
  void *FsContext2;
  int FinalStatus;
  __unaligned __declspec(align(1)) _LARGE_INTEGER CurrentByteOffset;
  _FILE_OBJECT *RelatedFileObject;
  _IO_COMPLETION_CONTEXT *CompletionContext;
  int LockCount;
  _KEVENT Lock;
  _KEVENT Event;
  _LIST_ENTRY ProcessListEntry;
  _LIST_ENTRY FileSystemListEntry;
  unsigned __int8 IoPriority;
  unsigned __int8 PoolPadding[15];
};

// IDA Local Type ordinal 10647; PDB kind: struct.
struct OBJECT_T
{
  volatile LF_DATA State;
  volatile unsigned int dwThreadID;
  unsigned int dwRecursion;
};

// IDA Local Type ordinal 10896; PDB kind: struct.
struct _OBJECTID
{
  _GUID Lineage;
  unsigned int Uniquifier;
};

// IDA Local Type ordinal 26176; PDB kind: typedef.
typedef LFOBJECT_STORE LFOBJECT;

// IDA Local Type ordinal 26683; PDB kind: typedef.
typedef st_lwObject lwObject;

// IDA Local Type ordinal 27614; PDB kind: typedef.
typedef _OBJECTID OBJECTID;

// IDA Local Type ordinal 27850; PDB kind: typedef.
typedef _KOBJECTS KOBJECTS;

// IDA Local Type ordinal 32741; PDB kind: typedef.
typedef OBJECT_T OBJECT;

// IDA Local Type ordinal 32779; PDB kind: typedef.
typedef volatile LFOBJECT_STORE *PLFOBJECT;

// IDA Local Type ordinal 33424; PDB kind: typedef.
typedef void (__fastcall *objectFunc_t)(idSSObject *, void *);

// IDA Local Type ordinal 33616; PDB kind: typedef.
typedef _FILE_OBJECT FILE_OBJECT;
