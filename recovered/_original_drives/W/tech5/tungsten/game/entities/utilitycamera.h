
// ========================================================================
// ?GetDistance@idUtilityCamera@@UBAMXZ
// EA  : 0x824E34C0
// RVA : 0x004E34C0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

float __fastcall idUtilityCamera::GetDistance(idUtilityCamera *this)
{
  double distance; // fp1

  distance = this->distance;
  return *((float *)&distance + 1);
}


// ========================================================================
// ?SetDistance@idUtilityCamera@@UAAXM@Z
// EA  : 0x824E34C8
// RVA : 0x004E34C8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void __fastcall idUtilityCamera::SetDistance(idUtilityCamera *this, double dist)
{
  this->distance = dist;
}


// ========================================================================
// ?SetOffset@idUtilityCamera@@UAAXABVidVec3@@@Z
// EA  : 0x824E34D0
// RVA : 0x004E34D0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void __fastcall idUtilityCamera::SetOffset(idUtilityCamera *this, const idVec3 *ofs)
{
  this->offset = *ofs;
}


// ========================================================================
// ?GetAngles@idUtilityCamera@@UBAABVidAngles@@XZ
// EA  : 0x824E34F0
// RVA : 0x004E34F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

const idAngles *__fastcall idUtilityCamera::GetAngles(idUtilityCamera *this)
{
  return &this->angles;
}


// ========================================================================
// ?SetAngles@idUtilityCamera@@UAAXABVidAngles@@@Z
// EA  : 0x824E34F8
// RVA : 0x004E34F8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void __fastcall idUtilityCamera::SetAngles(idUtilityCamera *this, const idAngles *ang)
{
  this->angles = *ang;
}


// ========================================================================
// ?GetTargetEntity@idEntityCamera@@UAAPAVidEntity@@XZ
// EA  : 0x824FB238
// RVA : 0x004FB238
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

idEntity *__fastcall idEntityCamera::GetTargetEntity(idEntityCamera *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->targetEnt.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??0idCameraView@@QAA@XZ
// EA  : 0x82558280
// RVA : 0x00558280
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

idCameraView *__fastcall idCameraView::idCameraView(idCameraView *this)
{
  float z; // r9

  idEntity::idEntity(this);
  this->activator.spawnId.value = 0x1FFF;
  this->__vftable = (idCameraView_vtbl *)&idCameraView::`vftable';
  this->viewOrigin = vec3_origin;
  this->viewAngles = ang_zero;
  this->target.spawnId.value = 0x1FFF;
  this->orbit = false;
  this->orbitOffset.x = vec3_origin.x;
  this->orbitOffset.y = vec3_origin.y;
  z = vec3_origin.z;
  this->orbitAdjust = 0.0;
  this->startingAngle = 0.0;
  this->highSpeed = false;
  this->orbitRadius = 64.0;
  this->returnToSavedControl = false;
  this->currentAngle = 0.0;
  this->forcePlayerNoFade = false;
  this->fading = false;
  this->usePhysicsToGetAngles = false;
  this->orbitOffset.z = z;
  return this;
}


// ========================================================================
// ??0trigFocus_t@idCinematicCamera@@QAA@XZ
// EA  : 0x82592AD8
// RVA : 0x00592AD8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

idCinematicCamera::trigFocus_t *__fastcall idCinematicCamera::trigFocus_t::trigFocus_t(
        idCinematicCamera::trigFocus_t *this)
{
  int v1; // ctr
  int *p_startTimeOfs; // r9
  float *p_y; // r10
  float z; // r4

  this->focusType = 0;
  this->spline.path.spawnId.value = 0x1FFF;
  this->spline.dist = 0.0;
  this->spline.sc = 0;
  this->splineTime = 1.0;
  this->splineTimeOfs = 0.0;
  this->entity.spawnId.value = 0x1FFF;
  this->position = vec3_origin;
  v1 = 9;
  this->pathAdjust = ang_zero;
  p_startTimeOfs = &this->startTimeOfs;
  p_y = &mat2_identity.mat[1].y;
  this->focusOffset.x = vec3_origin.x;
  this->focusOffset.y = vec3_origin.y;
  z = vec3_origin.z;
  this->easeInTime = 0.0;
  this->easeOutTime = 0.0;
  this->focusOffset.z = z;
  this->transTime = 0.0;
  this->startTimeOfs = 0;
  do
  {
    *++p_startTimeOfs = *(_DWORD *)++p_y;
    --v1;
  }
  while ( v1 != 0 );
  this->totalFocusTime = 0.0;
  return this;
}


// ========================================================================
// ?GetActivator@idCamera@@QBAPAVidEntity@@XZ
// EA  : 0x82C06D68
// RVA : 0x00C06D68
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

idEntity *__fastcall idCamera::GetActivator(idCamera *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->activator.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetType@idPresentableReviveCamera@@UBA?AW4presentableType_t@@XZ
// EA  : 0x82D03560
// RVA : 0x00D03560
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

int __fastcall idPresentableReviveCamera::GetType(idPresentableReviveCamera *this)
{
  return 25;
}


// ========================================================================
// ?GetTargetPos@idUtilityCamera@@UBAXAAVidVec3@@@Z
// EA  : 0x82D0A7E8
// RVA : 0x00D0A7E8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void __fastcall idUtilityCamera::GetTargetPos(idUtilityCamera *this, idVec3 *pos)
{
  *pos = this->targetPos;
}


// ========================================================================
// ?SetTargetPos@idUtilityCamera@@UAAXABVidVec3@@@Z
// EA  : 0x82D0A808
// RVA : 0x00D0A808
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void __fastcall idUtilityCamera::SetTargetPos(idUtilityCamera *this, const idVec3 *pos)
{
  this->targetPos = *pos;
}


// ========================================================================
// ?InhibitButtons@idRotatableCamera@@UBAHXZ
// EA  : 0x82D0A9F0
// RVA : 0x00D0A9F0
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

int __fastcall idRotatableCamera::InhibitButtons(idRotatableCamera *this)
{
  return ~((*((_BYTE *)this + 1028) & 0x40) != 0 ? 0 : 0x24);
}


// ========================================================================
// ?CanShowCrosshair@idRotatableCamera@@UBA_NXZ
// EA  : 0x82D0AA10
// RVA : 0x00D0AA10
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

BOOL __fastcall idRotatableCamera::CanShowCrosshair(idRotatableCamera *this)
{
  return (~*((unsigned __int8 *)this + 1028) & 0x40) != 0;
}


// ========================================================================
// ??1idTownGarageCamera@@UAA@XZ
// EA  : 0x82D0B710
// RVA : 0x00D0B710
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void __fastcall idTownGarageCamera::~idTownGarageCamera(idTownGarageCamera *this)
{
  this->__vftable = (idTownGarageCamera_vtbl *)&idTownGarageCamera::`vftable';
  idStr::FreeData(this: &this->wastelandExitLocation);
  idStr::FreeData(this: &this->wastelandExitMap);
  idStr::FreeData(this: &this->exitTownName);
  this->__vftable = (idTownGarageCamera_vtbl *)&idCamera::`vftable';
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$510220
// EA  : 0x82D0B780
// RVA : 0x00D0B780
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void _unwind_510220()
{
  int v0; // r12

  idEntityCamera::~idEntityCamera(this: *(idEntityCamera **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$510221
// EA  : 0x82D0B7A8
// RVA : 0x00D0B7A8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void _unwind_510221()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 996));
}


// ========================================================================
// __unwind$510222
// EA  : 0x82D0B7D4
// RVA : 0x00D0B7D4
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void _unwind_510222()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 1048));
}


// ========================================================================
// ?GetOffset@idUtilityCamera@@UBAXAAVidVec3@@@Z
// EA  : 0x82D0B800
// RVA : 0x00D0B800
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void __fastcall idUtilityCamera::GetOffset(idTownGarageCamera *this, idVec3 *_offset)
{
  *_offset = this->offset;
}


// ========================================================================
// ?GetTargetPos@idRaceDeathCamera@@UBAXAAVidVec3@@@Z
// EA  : 0x82D134B8
// RVA : 0x00D134B8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void __fastcall idRaceDeathCamera::GetTargetPos(idSpectatorCamera *this, idVec3 *pos)
{
  *pos = this->targetPos;
}


// ========================================================================
// ?SetTargetPos@idRaceDeathCamera@@UAAXABVidVec3@@@Z
// EA  : 0x82D134D8
// RVA : 0x00D134D8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

void __fastcall idRaceDeathCamera::SetTargetPos(idSpectatorCamera *this, const idVec3 *pos)
{
  this->targetPos = *pos;
}


// ========================================================================
// ?GetExitTownName@idTownGarageCamera@@QBA?AVidStr@@XZ
// EA  : 0x82E5BC90
// RVA : 0x00E5BC90
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

idTownGarageCamera *__fastcall idTownGarageCamera::GetExitTownName(idTownGarageCamera *this, idStr *result)
{
  idStr::idStr((idStr *)this, text: (idStr *)((char *)result + 996));
  return this;
}


// ========================================================================
// ?GetWastelandExitMap@idTownGarageCamera@@QBA?AVidStr@@XZ
// EA  : 0x82E5BCC8
// RVA : 0x00E5BCC8
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

idTownGarageCamera *__fastcall idTownGarageCamera::GetWastelandExitMap(idTownGarageCamera *this, idStr *result)
{
  idStr::idStr((idStr *)this, text: (idStr *)((char *)result + 1048));
  return this;
}


// ========================================================================
// ?GetWastelandExitLocation@idTownGarageCamera@@QBA?AVidStr@@XZ
// EA  : 0x82E5BD00
// RVA : 0x00E5BD00
// PDB : w:\tech5\tungsten\game\entities\utilitycamera.h
// ========================================================================

idTownGarageCamera *__fastcall idTownGarageCamera::GetWastelandExitLocation(idTownGarageCamera *this, idStr *result)
{
  idStr::idStr((idStr *)this, text: (idStr *)((char *)result + 1080));
  return this;
}

