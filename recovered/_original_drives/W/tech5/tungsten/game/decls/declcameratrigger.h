
// ========================================================================
// ??0idTrigMovement@idDeclCameraTrigger@@QAA@XZ
// EA  : 0x82592608
// RVA : 0x00592608
// PDB : w:\tech5\tungsten\game\decls\declcameratrigger.h
// ========================================================================

idDeclCameraTrigger::idTrigMovement *__fastcall idDeclCameraTrigger::idTrigMovement::idTrigMovement(
        idDeclCameraTrigger::idTrigMovement *this)
{
  float z; // r6

  this->moveType = CAM_MOVE_NONE;
  this->spline.path = nullptr;
  this->spline.dist = 0.0;
  this->spline.sc = 0;
  this->position = vec3_origin;
  this->entity.spawnId.value = 0x1FFF;
  this->entityOffset.x = vec3_origin.x;
  this->entityOffset.y = vec3_origin.y;
  z = vec3_origin.z;
  this->scalarOffset = 0.0;
  this->entityOffset.z = z;
  this->timing.duration = 0.0;
  this->timing.easeInTime = 0.0;
  this->timing.looping = false;
  this->timing.easeOutTime = 0.0;
  this->timing.startTimeOfs = 0;
  this->frameLerp.duration = 0.0;
  this->frameLerp.looping = false;
  this->frameLerp.easeInTime = 0.0;
  this->frameLerp.startTimeOfs = 0;
  this->frameLerp.easeOutTime = 0.0;
  this->additionalOffset = vec3_origin;
  this->viewOrigin = vec3_origin;
  return this;
}


// ========================================================================
// ??0idTrigFocus@idDeclCameraTrigger@@QAA@XZ
// EA  : 0x825926D8
// RVA : 0x005926D8
// PDB : w:\tech5\tungsten\game\decls\declcameratrigger.h
// ========================================================================

idDeclCameraTrigger::idTrigFocus *__fastcall idDeclCameraTrigger::idTrigFocus::idTrigFocus(
        idDeclCameraTrigger::idTrigFocus *this)
{
  int v1; // ctr
  int *p_startTimeOfs; // r8
  float *p_y; // r9

  this->focusType = CAM_FOCUS_NONE;
  this->spline.dist = 0.0;
  this->spline.path = nullptr;
  this->spline.sc = 0;
  this->splineTime = 1.0;
  this->entity.spawnId.value = 0x1FFF;
  this->position = vec3_origin;
  v1 = 9;
  this->pathAdjust = ang_zero;
  p_startTimeOfs = &this->frameLerp.startTimeOfs;
  p_y = &mat2_identity.mat[1].y;
  this->focusOffset = vec3_origin;
  this->frameLerp.duration = 0.0;
  this->frameLerp.easeInTime = 0.0;
  this->frameLerp.looping = false;
  this->frameLerp.easeOutTime = 0.0;
  this->frameLerp.startTimeOfs = 0;
  do
  {
    *++p_startTimeOfs = *(_DWORD *)++p_y;
    --v1;
  }
  while ( v1 != 0 );
  this->lastKnownPosition = vec3_origin;
  return this;
}


// ========================================================================
// ?GetDeclInfo@idDeclCameraTrigger@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82BBCC38
// RVA : 0x00BBCC38
// PDB : w:\tech5\tungsten\game\decls\declcameratrigger.h
// ========================================================================

idDeclInfoTemplate<idDeclCameraTrigger> *__fastcall idDeclCameraTrigger::GetDeclInfo(idDeclCameraTrigger *this)
{
  return &idDeclCameraTrigger::resourceList;
}

