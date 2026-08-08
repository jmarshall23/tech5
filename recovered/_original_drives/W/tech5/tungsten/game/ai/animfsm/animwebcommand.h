
// ========================================================================
// ??0idAnimWebCmd@@QAA@PAVidAnimWebCmdCtx@@PBD@Z
// EA  : 0x829F5E60
// RVA : 0x009F5E60
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.h
// ========================================================================

idAnimWebCmd *__fastcall idAnimWebCmd::idAnimWebCmd(idAnimWebCmd *this, idAnimWebCmdCtx *_owner, const char *userName)
{
  char v5; // r7
  float z; // r4

  this->owner = _owner;
  this->groups = -1;
  this->groupFilter = -1;
  idAnimWebState::idAnimWebState(this: &this->via);
  idAnimWebState::idAnimWebState(this: &this->dst);
  this->viaWeb.value = -1;
  blendParms_t::blendParms_t(this: &this->blendParms);
  this->doneEvent = nullptr;
  this->deltaCorrectParms.correctIdealPoint = IDEALPOINT_NONE;
  this->deltaCorrectParms.correctIdealDir = IDEALDIR_NONE;
  this->deltaCorrectParms.correctGravity = B_FALSE;
  this->deltaCorrectParms.parms.translationCorrectionMaxScale = 0.0;
  this->deltaCorrectParms.parms.translationCorrectionPerFrameMax = vec3_origin;
  v5 = *((_BYTE *)&this->deltaCorrectParms.parms + 41);
  this->deltaCorrectParms.parms.translationPerFrameMax.x = vec3_origin.x;
  this->deltaCorrectParms.parms.translationPerFrameMax.y = vec3_origin.y;
  z = vec3_origin.z;
  this->deltaCorrectParms.parms.rotationMaxScale = 0.0;
  this->deltaCorrectParms.parms.rotationMinScale = 0.0;
  *((_BYTE *)&this->deltaCorrectParms.parms + 40) = 0;
  this->deltaCorrectParms.parms.rotationRateMax = 0.0;
  *((_BYTE *)&this->deltaCorrectParms.parms + 41) = v5 & 3 | 0x40;
  this->deltaCorrectParms.parms.translationPerFrameMax.z = z;
  this->userString = userName;
  this->alreadyThere = false;
  idAnimWebCmd::Reset(this);
  return this;
}


// ========================================================================
// ??0idAnimWebCmdWaitHandle@@QAA@XZ
// EA  : 0x829FC090
// RVA : 0x009FC090
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.h
// ========================================================================

idAnimWebCmdWaitHandle *__fastcall idAnimWebCmdWaitHandle::idAnimWebCmdWaitHandle(idAnimWebCmdWaitHandle *this)
{
  char v2; // r7
  float z; // r4

  this->owner.spawnId.value = 0x1FFF;
  idAnimWebCmdWaitHandle::idAnimEventInfo_t::idAnimEventInfo_t(this: &this->animEventInfo);
  idAnimWebCmdWaitHandle::idAnimEventInfo_t::idAnimEventInfo_t(this: &this->animEventInfoDC);
  this->deltaCorrectParms.correctIdealPoint = IDEALPOINT_NONE;
  this->deltaCorrectParms.correctIdealDir = IDEALDIR_NONE;
  this->deltaCorrectParms.correctGravity = B_FALSE;
  this->deltaCorrectParms.parms.translationCorrectionMaxScale = 0.0;
  this->deltaCorrectParms.parms.translationCorrectionPerFrameMax = vec3_origin;
  v2 = *((_BYTE *)&this->deltaCorrectParms.parms + 41);
  this->deltaCorrectParms.parms.translationPerFrameMax.x = vec3_origin.x;
  this->deltaCorrectParms.parms.translationPerFrameMax.y = vec3_origin.y;
  z = vec3_origin.z;
  this->deltaCorrectParms.parms.rotationMaxScale = 0.0;
  this->deltaCorrectParms.parms.rotationMinScale = 0.0;
  *((_BYTE *)&this->deltaCorrectParms.parms + 40) = 0;
  this->deltaCorrectParms.parms.rotationRateMax = 0.0;
  *((_BYTE *)&this->deltaCorrectParms.parms + 41) = v2 & 3 | 0x40;
  this->deltaCorrectParms.parms.translationPerFrameMax.z = z;
  idAnimWebState::idAnimWebState(this: &this->via);
  idAnimWebState::idAnimWebState(this: &this->dst);
  idAnimWebCmdWaitHandle::Init(this);
  return this;
}


// ========================================================================
// ?CheckPriority@idAnimWebCmdCtx@@QAA_NW4awCmdPriority_t@@@Z
// EA  : 0x82A83230
// RVA : 0x00A83230
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.h
// ========================================================================

BOOL __fastcall idAnimWebCmdCtx::CheckPriority(idAnimWebCmdCtx *this, awCmdPriority_t _priority)
{
  idAnimWebCmdWaitHandle *activeWaitHandle; // r11
  awCmdPriority_t priority; // r11

  if ( _priority == AWCMD_PRIORITY_OVERRIDE )
    return true;
  activeWaitHandle = this->activeWaitHandle;
  if ( activeWaitHandle == nullptr
    || activeWaitHandle->status != AWCMD_STATUS_WAITING
    || (priority = activeWaitHandle->priority) <= this->priority )
  {
    priority = this->priority;
  }
  return _priority >= priority;
}


// ========================================================================
// ?SetActiveWaitHandle@idAnimWebCmdCtx@@QAAXPAVidAnimWebCmdWaitHandle@@@Z
// EA  : 0x82A84010
// RVA : 0x00A84010
// PDB : w:\tech5\tungsten\game\ai\animfsm\animwebcommand.h
// ========================================================================

void __fastcall idAnimWebCmdCtx::SetActiveWaitHandle(idAnimWebCmdCtx *this, idAnimWebCmdWaitHandle *handle)
{
  idAnimWebCmdWaitHandle *activeWaitHandle; // r3

  activeWaitHandle = this->activeWaitHandle;
  if ( activeWaitHandle != nullptr && handle != activeWaitHandle )
  {
    idAnimWebCmdWaitHandle::FireDoneEvent(this: activeWaitHandle, ent: this->entity);
    idAnimWebCmdWaitHandle::ReportStatus(this: this->activeWaitHandle, status: 9);
    this->activeWaitHandle->status = AWCMD_STATUS_INTERRUPTED;
  }
  this->activeWaitHandle = handle;
}

