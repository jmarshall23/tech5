#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\skillsetting.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16645; PDB kind: class.
class idSkillSetting<float>
{
public:
  float setting[5];
};

// IDA Local Type ordinal 16648; PDB kind: class.
class idSkillSetting<int>
{
public:
  int setting[5];
};

// IDA Local Type ordinal 16649; PDB kind: class.
class idSkillSetting<bool>
{
public:
  bool setting[5];
};

// IDA Local Type ordinal 21503; PDB kind: struct.
struct aiSkillSettings_t
{
  aiAccuracy_t aimAccuracy;
  int minFireAtLastKnownDuration;
  int maxFireAtLastKnownDuration;
};

// IDA Local Type ordinal 26700; PDB kind: typedef.
typedef idSkillSetting<bool> idSkillSetting_Bool;

// IDA Local Type ordinal 26828; PDB kind: typedef.
typedef idSkillSetting<int> idSkillSetting_Int;

// IDA Local Type ordinal 30709; PDB kind: typedef.
typedef idSkillSetting<float> idSkillSetting_Float;
