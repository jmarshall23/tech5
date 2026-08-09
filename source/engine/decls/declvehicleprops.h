#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\decls\declvehicleprops.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14510; PDB kind: struct.
struct idDeclVehicleProps::cameraPlacement_t
{
  float yaw;
  float pitch;
  float height;
  float lateral;
  float minRange;
  float maxRange;
  const idDeclTable *recovery;
  const idDeclTable *rotationOffset;
};

// IDA Local Type ordinal 14554; PDB kind: class.
class idDeclVehicleProps : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14555.
  virtual ~idDeclVehicleProps();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  idDeclVehicleProps::cameraPlacement_t camera;
  idDeclVehicleProps::cameraPlacement_t camera2;
  const idDeclTable *fpsStickYawTable;
  const idDeclTable *fpsStickPitchTable;
  steeringWheel_t steeringWheel;
  float steerControlInfluence;
  dialMeter_t tachometer;
  dialMeter_t speedometer;
  idVec3 cgLocation;
  idVec3 maxCgLocation;
  float maxSpeed;
  float boostMaxSpeedScalar;
  float additionalRaceSpeed;
  float maxReverseSpeed;
  float handBrakeForce;
  float handbrakeFrictionScale;
  float handbrakeMinThreshold;
  float brakeForce;
  const idDeclTable *motorTorque;
  float frictionForce;
  float pitchStabilization;
  float rollStabilization;
  float skidRoll;
  float skidRollBoostMult;
  bool hasBoost;
  const idMaterial *boostBlurMaterial;
  int baseBoostUpgrade;
  idStr sheildModel;
  float jumpImpulse;
  bool hasEngineIdle;
  bool removeOnExit;
  idEntityInfluenceTrail influence;
  bool remoteControl;
  bool raceRemoteControl;
  idList<idWheelDef,5> wheels;
  idVehicleBodyDef body;
  idVehicleSoundDef sounds;
  idVehicleEffectsDef effects;
  const idDeclBreakable *breakableDebris;
};

// IDA Local Type ordinal 17548; PDB kind: class.
class __declspec(align(4)) idDeclVehicleArmor : public idDeclInventory
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17549.
  virtual ~idDeclVehicleArmor();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  float damageScale;
  bool damageItemLast;
  bool isSpike;
};
