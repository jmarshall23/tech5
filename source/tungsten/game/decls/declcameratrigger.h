#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declcameratrigger.h
// Recovered logical types: 20
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1688; PDB kind: enum.
enum idDeclCameraTrigger::cam_move_t : __int32
{
  CAM_MOVE_NONE = 0x0,
  CAM_MOVE_SPLINE = 0x1,
  CAM_MOVE_POSITION = 0x2,
  CAM_MOVE_ENTITY = 0x3,
  CAM_MOVE_PLAYER = 0x4,
  CAM_MOVE_PLAYER_VEHICLE = 0x5,
  CAM_MOVE_VEHICLE_DEFAULT = 0x6,
  CAM_MOVE_ENTITY_POSITION = 0x7,
  CAM_MOVE_ACTIVATOR = 0x8,
  CAM_MOVE_ACTIVATOR_POSITION = 0x9,
  CAM_MOVE_PLAYER_POSITION = 0xA,
  CAM_MOVE_PLAYER_VEHICLE_POSITION = 0xB,
  CAM_MOVE_CIRCLE_ENTITY = 0xC,
  CAM_MOVE_CIRCLE_PLAYER = 0xD,
  CAM_MOVE_CIRCLE_PLAYER_VEHICLE = 0xE,
  CAM_MOVE_RADIAL_ENTITY = 0xF,
  CAM_MOVE_RADIAL_PLAYER = 0x10,
  CAM_MOVE_RADIAL_PLAYER_VEHICLE = 0x11,
};

// IDA Local Type ordinal 1689; PDB kind: enum.
enum idDeclCameraTrigger::cam_focus_t : __int32
{
  CAM_FOCUS_NONE = 0x0,
  CAM_FOCUS_MOVEPATH = 0x1,
  CAM_FOCUS_SPLINE = 0x2,
  CAM_FOCUS_ACTIVATOR = 0x3,
  CAM_FOCUS_ACTIVATOR_POSITION = 0x4,
  CAM_FOCUS_PLAYER = 0x5,
  CAM_FOCUS_PLAYER_VEHICLE = 0x6,
  CAM_FOCUS_VEHICLE_DEFAULT = 0x7,
  CAM_FOCUS_ENTITY = 0x8,
  CAM_FOCUS_ENTITY_POSITION = 0x9,
  CAM_FOCUS_POSITION = 0xA,
  CAM_FOCUS_POSITION_LERP = 0xB,
};

// IDA Local Type ordinal 1690; PDB kind: enum.
enum idDeclCameraTrigger::cam_showhud_t : __int32
{
  CAM_SHOWHUD_NULL = 0x0,
  CAM_SHOWHUD_NO = 0x1,
  CAM_SHOWHUD_YES = 0x2,
};

// IDA Local Type ordinal 14400; PDB kind: class.
class idDeclCameraTrigger::idSplineMove
{
public:
  idSplinePath *path;
  float dist;
  int sc;
};

// IDA Local Type ordinal 14401; PDB kind: class.
class idDeclCameraTrigger::idTimeLerpHelper
{
public:
  float duration;
  float easeInTime;
  float easeOutTime;
  bool looping;
  int startTimeOfs;
};

// IDA Local Type ordinal 14402; PDB kind: class.
class idDeclCameraTrigger::idTrigMovement
{
public:
  idDeclCameraTrigger::cam_move_t moveType;
  idDeclCameraTrigger::idSplineMove spline;
  idVec3 position;
  idEntityPtr<idEntity> entity;
  idVec3 entityOffset;
  float scalarOffset;
  idDeclCameraTrigger::idTimeLerpHelper timing;
  idDeclCameraTrigger::idTimeLerpHelper frameLerp;
  idVec3 additionalOffset;
  idVec3 viewOrigin;
};

// IDA Local Type ordinal 14403; PDB kind: class.
class idDeclCameraTrigger::idTrigFocus
{
public:
  idDeclCameraTrigger::cam_focus_t focusType;
  idDeclCameraTrigger::idSplineMove spline;
  float splineTime;
  idEntityPtr<idEntity> entity;
  idVec3 position;
  idAngles pathAdjust;
  idVec3 focusOffset;
  idDeclCameraTrigger::idTimeLerpHelper frameLerp;
  idMat3 viewAxis;
  idVec3 lastKnownPosition;
};

// IDA Local Type ordinal 14404; PDB kind: class.
class __declspec(align(4)) idDeclCameraTrigger::idTrigFade
{
public:
  idColor color;
  float transTime;
  bool timeScaleFade;
  bool activate;
};

// IDA Local Type ordinal 14405; PDB kind: class.
class idDeclCameraTrigger::idTrigTimeScale
{
public:
  float scale;
  idDeclCameraTrigger::idTimeLerpHelper timing;
  float initScale;
};

// IDA Local Type ordinal 14406; PDB kind: class.
class idDeclCameraTrigger::idTrigFovZoom
{
public:
  float angle;
  idDeclCameraTrigger::idTimeLerpHelper timing;
};

// IDA Local Type ordinal 14407; PDB kind: class.
class idDeclCameraTrigger::idTrigActivateEnt
{
public:
  idList<idEntityPtr<idEntity>,5> entity;
};

// IDA Local Type ordinal 14409; PDB kind: class.
class idDeclCameraTrigger::idTrigSounds
{
public:
  idList<idSoundShader const *,5> sound;
};

// IDA Local Type ordinal 14410; PDB kind: class.
class idDeclCameraTrigger::idTrigDof
{
public:
  float blurStart;
  float blurScale;
  idDeclCameraTrigger::idTimeLerpHelper timing;
  idVec3 vec;
};

// IDA Local Type ordinal 14411; PDB kind: class.
class __declspec(align(4)) idDeclCameraTrigger::idTrigShakeView
{
public:
  float shakeVolume;
  bool activate;
};

// IDA Local Type ordinal 14412; PDB kind: class.
class idDeclCameraTrigger::idTrigRenderParms
{
public:
  float fogScale;
  idColor fogColor;
  idDeclCameraTrigger::idTimeLerpHelper timing;
};

// IDA Local Type ordinal 14413; PDB kind: class.
class idDeclCameraTrigger::idTrigMisc
{
public:
  bool endCinematic;
  bool notifyGUI;
  bool suspendCamera;
  idDeclCameraTrigger::cam_showhud_t showHud;
};

// IDA Local Type ordinal 14414; PDB kind: class.
class __declspec(align(4)) idDeclCameraTrigger::idCameraTriggerParms
{
public:
  idStr title;
  float offsetTime;
  idDeclCameraTrigger::idTrigMovement movement;
  idDeclCameraTrigger::idTrigFocus focus;
  idDeclCameraTrigger::idTrigFade fade;
  idDeclCameraTrigger::idTrigTimeScale timeScale;
  idDeclCameraTrigger::idTrigFovZoom fovZoom;
  idDeclCameraTrigger::idTrigActivateEnt activate;
  idDeclCameraTrigger::idTrigSounds sounds;
  idDeclCameraTrigger::idTrigDof depthOfField;
  idDeclCameraTrigger::idTrigShakeView shakeView;
  idDeclCameraTrigger::idTrigRenderParms renderParms;
  idDeclCameraTrigger::idTrigMisc misc;
  bool triggered;
};

// IDA Local Type ordinal 14416; PDB kind: class.
class idDeclCameraTrigger : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14417.
  virtual ~idDeclCameraTrigger();
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

  idList<idDeclCameraTrigger::idCameraTriggerParms,5> triggers;
};

// IDA Local Type ordinal 14761; PDB kind: class.
class idDeclCameraTrigger::idCameraTriggerState
{
public:
  idDeclCameraTrigger::idTrigMovement movement;
  idDeclCameraTrigger::idTrigFocus focus;
  idDeclCameraTrigger::idTrigFade fade;
  idDeclCameraTrigger::idTrigTimeScale timeScale;
  idDeclCameraTrigger::idTrigFovZoom fovZoom;
  idDeclCameraTrigger::idTrigDof depthOfField;
  idDeclCameraTrigger::idTrigShakeView shakeView;
  idDeclCameraTrigger::idTrigRenderParms renderParms;
  idDeclCameraTrigger::idTrigMisc misc;
};

// IDA Local Type ordinal 14762; PDB kind: class.
class idDeclCameraTrigger::idSplineCurve
{
public:
  idSplinePath *splinePath;
  idCurve_Spline<idVec3> *curve;
  float length;
  idVec3 lastOrigin;
};
