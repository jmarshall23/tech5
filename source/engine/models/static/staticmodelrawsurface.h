#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\static\staticmodelrawsurface.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13426; PDB kind: class.
class idStaticModelSurface : public idRenderModelSurface
{
public:
  idList<skinRemap_t,5> skinRemaps;
};
