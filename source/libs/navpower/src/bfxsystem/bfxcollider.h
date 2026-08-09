#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1035; PDB kind: enum.
enum collide_t : __int32
{
  COLLIDE_CONTINUE_SIMULATION = 0x0,
  COLLIDE_STOP_SIMULATION = 0x1,
  COLLIDE_IGNORE_COLLISION = 0x2,
};

// IDA Local Type ordinal 18257; PDB kind: class.
class idCollider : public bfx::Collider
{
public:
  // Recovered virtual interface; IDA vtable ordinal 18258.
  virtual bool CollideLineSegmentAndWorld(const bfx::CollideData *, const bfx::Vector3 *, bfx::Vector3 *);
  virtual ~idCollider();

};
