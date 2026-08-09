#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\player\crosshairinfo.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1234; PDB kind: unknown.
enum idCrosshairCombinerInfo::<unnamed_tag> : __int32
{
  MAX_ITEMS = 0x5,
};

// IDA Local Type ordinal 2138; PDB kind: unknown.
enum idCrosshairInfo::<unnamed_tag> : __int32
{
  MAX_COMBINERS = 0x3,
  MAX_ICONS = 0x3,
};

// IDA Local Type ordinal 15124; PDB kind: class.
class idCrosshairInfo
{
public:
  idColor color;
  idColor textColor;
  idStrId text;
  crosshairMaterial_t material;
  crosshairColorState_t colorState;
  crosshairTextColorState_t textColorState;
  float useAmount;
  bool hideCrossHairInfo;
  const idSoundShader *hoverSound;
  bool useCheckbox;
  idStaticList<idCrosshairCustomIcon,3> icons;
};

// IDA Local Type ordinal 15353; PDB kind: class.
class idCrosshairCombinerInfo
{
public:
  bool hovered;
  int itemCount;
  int itemIndex;
  int itemState[5];
  const idMaterial *itemIcons[5];
};
