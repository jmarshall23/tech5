#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\thirdpersonvehiclegui.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17666; PDB kind: struct.
struct idThirdPersonVehicleGUI::trackedVehicle_s
{
  bool valid;
  bool cleared;
  float distance;
  idVec3 direction;
};

// IDA Local Type ordinal 22297; PDB kind: class.
class idThirdPersonVehicleGUI
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22298.
  virtual ~idThirdPersonVehicleGUI();

  idEntityPtr<idEntity> entity;
  idVec3 origin;
  idVec3 arcOrigin;
  idMat3 axis;
  idVec3 forward;
  idVec3 left;
  idVec3 up;
  int trackedNumber;
  bool shouldDraw;
  idInterpolate<float> bringUp;
  idInterpolate<float> bringDown;
  idThirdPersonVehicleGUI::trackedVehicle_s trackedVehicles[16];
  idRenderModel *shell;
  idRenderModel *arrows[16];
};
