#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\animation\motioncontroller.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2177; PDB kind: enum.
enum idMotionController::channel_t : __int32
{
  CHANNEL_X = 0x0,
  CHANNEL_Y = 0x1,
  CHANNEL_Z = 0x2,
  CHANNEL_PITCH = 0x3,
  CHANNEL_YAW = 0x4,
  CHANNEL_ROLL = 0x5,
  CHANNEL_MAXNUM = 0x6,
};

// IDA Local Type ordinal 2178; PDB kind: enum.
enum idMotionController::flag_t : __int32
{
  FLAG_PARTIAL_LAST_FRAME_EXTRAPOLATE = 0x1,
};

// IDA Local Type ordinal 21807; PDB kind: struct.
struct idMotionController::tableArray_t
{
  const idDeclTable *tables[6];
};

// IDA Local Type ordinal 21808; PDB kind: struct.
struct idMotionController::channelData_t
{
  float prev;
  float cur;
  float delta;
  float duration;
  float scale;
  int flags;
};

// IDA Local Type ordinal 21809; PDB kind: class.
class idMotionController
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21810.
  virtual ~idMotionController();
  virtual void Init();
  virtual void Update();

  idMotionController::tableArray_t motionTables;
  idMotionController::channelData_t channelData[6];
  bool isPlaying;
  int startTime;
  int prevTime;
  int duration;
  idVec3 prevPos;
  idAngles prevAngles;
  idVec3 curPos;
  idAngles curAngles;
  idVec3 deltaPos;
  idAngles deltaAngles;
};

// IDA Local Type ordinal 24731; PDB kind: struct.
struct my_post_controller
{
  jpeg_d_post_controller pub;
  jvirt_sarray_control *whole_image;
  unsigned __int8 **buffer;
  unsigned int strip_height;
  unsigned int starting_row;
  unsigned int next_row;
};
