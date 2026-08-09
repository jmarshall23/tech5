#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\gamesys\counter.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 117; PDB kind: enum.
enum _D3DCOUNTER : __int32
{
  D3DCOUNTER_FRAMETIME = 0x0,
  D3DCOUNTER_FRAMESPERSECOND = 0x1,
  D3DCOUNTER_FRAMECOUNT = 0x2,
  D3DCOUNTER_FRAME_BLOCKED_PERCENT = 0x3,
  D3DCOUNTER_FRAME_THROTTLED_PERCENT = 0x4,
  D3DCOUNTER_FRAME_ACTIVE_PERCENT = 0x5,
  D3DCOUNTER_XAM_GPU_PERCENT = 0x6,
  D3DCOUNTER_FRAME_GPU_IDLE_PERCENT = 0x7,
  D3DCOUNTER_PRIMITIVES_CULLED_PERCENT = 0x8,
  D3DCOUNTER_PRIMITIVES_CLIPPED_PERCENT = 0x9,
  D3DCOUNTER_PRIMITIVES_VISIBLE_PERCENT = 0xA,
  D3DCOUNTER_BANDWIDTH_SYSTEM = 0xB,
  D3DCOUNTER_BANDWIDTH_INDICES = 0xC,
  D3DCOUNTER_BANDWIDTH_TEXTURE = 0xD,
  D3DCOUNTER_BANDWIDTH_VERTEX = 0xE,
  D3DCOUNTER_BANDWIDTH_RESOLVE = 0xF,
  D3DCOUNTER_BANDWIDTH_MEMEXPORT = 0x10,
  D3DCOUNTER_XAM_COMMAND_BUFFER_SIZE = 0x11,
  D3DCOUNTER_FRAME_GPU_WASTED_PERCENT = 0x12,
  D3DCOUNTER_MAX = 0x13,
};

// IDA Local Type ordinal 5462; PDB kind: struct.
struct _IO_COUNTERS
{
  unsigned __int64 ReadOperationCount;
  unsigned __int64 WriteOperationCount;
  unsigned __int64 OtherOperationCount;
  unsigned __int64 ReadTransferCount;
  unsigned __int64 WriteTransferCount;
  unsigned __int64 OtherTransferCount;
};

// IDA Local Type ordinal 21692; PDB kind: class.
class idCounter
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21693.
  virtual ~idCounter();
  virtual void BeginFrame();
  virtual void EndFrame();
  virtual void Init();

  int high;
  int cur;
};

// IDA Local Type ordinal 28933; PDB kind: typedef.
typedef _D3DCOUNTER D3DCOUNTER;

// IDA Local Type ordinal 30460; PDB kind: typedef.
typedef _IO_COUNTERS IO_COUNTERS;

// IDA Local Type ordinal 31786; PDB kind: typedef.
typedef _IO_COUNTERS *PIO_COUNTERS;
