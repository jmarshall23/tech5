#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\components\healthcomponent.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2390; PDB kind: enum.
enum aiHealthComponent_t : __int32
{
  AI_HEALTH_HITPOINTS = 0x0,
  AI_HEALTH_SHIELD = 0x1,
  AI_HEALTH_MAX = 0x2,
};

// IDA Local Type ordinal 2431; PDB kind: enum.
enum vehicleHealthComponent_t : __int32
{
  VEHICLE_HEALTH_HITPOINTS = 0x0,
  VEHICLE_HEALTH_ARMOR = 0x1,
  VEHICLE_HEALTH_MAX = 0x2,
};

// IDA Local Type ordinal 2442; PDB kind: enum.
enum simpleHealthComponent_t : __int32
{
  SIMPLE_HEALTH_HITPOINTS = 0x0,
  SIMPLE_HEALTH_MAX = 0x1,
};
