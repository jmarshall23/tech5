#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\jobs\render\rendercapture.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3021; PDB kind: enum.
enum renderCapture_t : __int32
{
  CAPTURE_VIEW_COLOR = 0x0,
  CAPTURE_VIEW_DEPTH = 0x1,
  CAPTURE_FEEDBACK = 0x2,
  CAPTURE_GLARE_MAP = 0x3,
  CAPTURE_GUI_IMAGE = 0x4,
};
