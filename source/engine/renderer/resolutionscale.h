#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\resolutionscale.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 22821; PDB kind: class.
class idResolutionScale
{
public:
  float dropMilliseconds;
  float raiseMilliseconds;
  int framesAboveRaise;
  float currentResolution;
  idGaugeMetric resolutionScaleMetricX;
  idGaugeMetric resolutionScaleMetricY;
};
