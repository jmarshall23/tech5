#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\iesfile.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13573; PDB kind: class.
class idIESfile : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13574.
  virtual ~idIESfile();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  int formatYear;
  int lampToLuminaireGeometry;
  int numAngleFactors;
  idList<float,5> factorAngles;
  idList<float,5> factorScales;
  int numLamps;
  float lumensPerLamp;
  float candelaMultiplier;
  int numVerticalAngles;
  int numHorizontalAngles;
  int photoMetricType;
  int unitsType;
  float width;
  float length;
  float height;
  float ballastFactor;
  int futureUse;
  float inputWats;
  idList<float,5> verticalAngles;
  idList<float,5> horizontalAngles;
  idList<float,5> candela;
  iesRenderInfo_t renderInfo;
  idStr editorModelName;
  idStaticModel *editorModel;
};
