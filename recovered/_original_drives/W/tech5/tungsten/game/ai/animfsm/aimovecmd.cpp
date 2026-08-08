
// ========================================================================
// ??1idAIMoveCmd@@UAA@XZ
// EA  : 0x82A68C38
// RVA : 0x00A68C38
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

void __fastcall idAIMoveCmd::~idAIMoveCmd(idAIMoveCmd *this)
{
  this->__vftable = (idAIMoveCmd_vtbl *)&idAIMoveCmd::`vftable';
}


// ========================================================================
// ?SetArriveRadius@idAIMoveCmd@@QAAXMM@Z
// EA  : 0x82A68C48
// RVA : 0x00A68C48
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

void __fastcall idAIMoveCmd::SetArriveRadius(idAIMoveCmd *this, double radius, double height)
{
  this->arrivalRadius = radius;
  this->arrivalHeight = height;
}


// ========================================================================
// ?SetArriveOrientation@idAIMoveCmd@@QAAXW4aiArrivalOrientation_t@@ABVidMat3@@@Z
// EA  : 0x82A68CB0
// RVA : 0x00A68CB0
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

void __fastcall idAIMoveCmd::SetArriveOrientation(idAIMoveCmd *this, aiArrivalOrientation_t orient, const idMat3 *axis)
{
  this->arriveOrient = orient;
  this->arriveAxis = *axis;
}


// ========================================================================
// ?SetDest@idAIMoveCmd@@QAAXABVidVec3@@W4destEntityType_t@1@@Z
// EA  : 0x82A68D08
// RVA : 0x00A68D08
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

void __fastcall idAIMoveCmd::SetDest(idAIMoveCmd *this, const idVec3 *dest, idAIMoveCmd::destEntityType_t entType)
{
  this->destType = MOVE_POSITION;
  this->destPos = *dest;
  this->destEntityType = entType;
}


// ========================================================================
// ??0idAIMoveInfo@@QAA@XZ
// EA  : 0x82A68D30
// RVA : 0x00A68D30
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

idAIMoveInfo *__fastcall idAIMoveInfo::idAIMoveInfo(idAIMoveInfo *this)
{
  float *p_z; // r10
  float *p_y; // r11
  int i; // ctr
  float z; // r4

  this->destEntity.spawnId.value = 0x1FFF;
  this->destPosition = vec3_origin;
  p_z = &this->destPosition.z;
  p_y = &mat2_identity.mat[1].y;
  for ( i = 9; i != 0; --i )
    *++p_z = *++p_y;
  this->destNormal.x = vec3_up.x;
  this->destNormal.y = vec3_up.y;
  z = vec3_up.z;
  this->arrivalRadius = 0.0;
  this->destNormal.z = z;
  this->useDestOrientation = false;
  this->arrivalAction = AIARRIVAL_STOP;
  this->moveFlags = 0;
  return this;
}


// ========================================================================
// ?Init@idAIMoveCmd@@QAAXXZ
// EA  : 0x82A68DC0
// RVA : 0x00A68DC0
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

void __fastcall idAIMoveCmd::Init(idAIMoveCmd *this)
{
  this->destType = MOVE_NONE;
  this->destEnt.spawnId.value = 0x1FFF;
  this->destPos = vec3_origin;
  this->destNormal = vec3_origin;
  this->arrivalAction = AIARRIVAL_STOP;
  this->arriveOrient = AIARRIVAL_ORIENT_NONE;
  this->arrivalHeight = -1.0;
  this->destAnimUpdateDistanceMinSqr = 0.0;
  this->arrivalRadius = 0.0;
  this->arrivalBuffer = 0.0;
  this->arriveAxis = mat3_identity;
  this->moveFlags = 0;
  this->startMoveEvent = nullptr;
  this->arriveOrientAngleTolerance = 30.0;
  this->destEntityType = DEST_ENT_NONE;
  this->planeArrivalRadius = 0.0;
  this->destNormal = vec3_up;
  this->useDestAnimAsIdle = false;
  this->attemptArrivalAlign = false;
  this->userString = nullptr;
  this->moveReason = AIMOVEREASON_UNKNOWN;
  this->allowStrafing = false;
  idAnimWebState::Clear(this: &this->destAnim);
}


// ========================================================================
// ?Init@idAIMoveCmd@@QAAXPBD@Z
// EA  : 0x82A68F00
// RVA : 0x00A68F00
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

void __fastcall idAIMoveCmd::Init(idAIMoveCmd *this, const char *_userString)
{
  idAIMoveCmd::Init(this);
  this->userString = _userString;
}


// ========================================================================
// ?SetDest@idAIMoveCmd@@QAAXPBVidEntity@@W4destEntityType_t@1@@Z
// EA  : 0x82A68F40
// RVA : 0x00A68F40
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

void __fastcall idAIMoveCmd::SetDest(idAIMoveCmd *this, const idEntity *ent, idAIMoveCmd::destEntityType_t entType)
{
  this->destType = MOVE_ENTITY;
  if ( ent != nullptr )
    this->destEnt.spawnId.value = (gameLocal->spawnIds.ptr[ent->entityNumber] << 13) | ent->entityNumber;
  else
    this->destEnt.spawnId.value = 0x1FFF;
  this->destEntityType = entType;
}


// ========================================================================
// ?PrintDebugInfo@idAIMoveCmd@@QBAXAAVidGuiListBox@@@Z
// EA  : 0x82A68F90
// RVA : 0x00A68F90
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

void __fastcall idAIMoveCmd::PrintDebugInfo(idAIMoveCmd *this, idGuiListBox *info)
{
  const char *userString; // r31
  idGuiListBox *v5; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  idGuiListBox *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  idAIMoveCmd::DestinationType destType; // r11
  __int64 v14; // r10
  __int64 v15; // r8
  __int64 v16; // r6
  idGuiListBox *v17; // r3
  const char *v18; // r4
  char *data; // r31
  __int64 v20; // r10
  __int64 v21; // r8
  __int64 v22; // r6
  idGuiListBox *v23; // r3
  const char *v24; // r4
  int value; // r10
  idEntity *v26; // r3
  int v27; // r9
  idEntity *v28; // r3
  const char *EnumName; // r31
  idGuiListBox *v30; // r3
  __int64 v31; // r10
  __int64 v32; // r8
  __int64 v33; // r6
  idGuiListBox *v34; // r3
  __int64 v35; // r10
  __int64 v36; // r8
  __int64 v37; // r6

  userString = this->userString;
  if ( userString == nullptr )
    userString = "<unknown>";
  v5 = idGuiListBox::Row(this: info);
  v9 = idGuiListBox::Printf(this: v5, fmt: "MoveCmd User", a3: v8, a4: v7, a5: v6);
  idGuiListBox::Printf(this: v9, fmt: userString, a3: v12, a4: v11, a5: v10);
  destType = this->destType;
  if ( destType == MOVE_ENTITY )
  {
    value = this->destEnt.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v26 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
      && idEntity::CastTo(c: v26) != nullptr )
    {
      v27 = this->destEnt.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v27 & 0x1FFF] == v27 >> 13
        && (v28 = gameLocal->entities.ptr[v27 & 0x1FFF]) != nullptr )
      {
        data = idEntity::CastTo(c: v28)->name.data;
      }
      else
      {
        data = (char *)MEMORY[0x10];
      }
    }
    else
    {
      data = "<null entity>";
    }
    v23 = idGuiListBox::Row(this: info);
    v24 = "MoveCmd Dest Ent";
    goto LABEL_16;
  }
  if ( destType == MOVE_POSITION )
  {
    data = (char *)idVec3::ToString(this: (idAngles *)&this->destPos, precision: 1);
    v23 = idGuiListBox::Row(this: info);
    v24 = "MoveCmd Dest Pos";
LABEL_16:
    v17 = idGuiListBox::Printf(this: v23, fmt: v24, a3: v22, a4: v21, a5: v20);
    v18 = data;
    goto LABEL_17;
  }
  v17 = idGuiListBox::Row(this: info);
  v18 = "MoveCmd None";
LABEL_17:
  idGuiListBox::Printf(this: v17, fmt: v18, a3: v16, a4: v15, a5: v14);
  EnumName = idTypeInfoTools::GetEnumName(
               this: typeInfoTools,
               enumTypeName: "aiArrivalAction_t",
               enumValue: this->arrivalAction,
               defaultValue: "<unknown>");
  v30 = idGuiListBox::Row(this: info);
  HIDWORD(v31) = "1 - formation cover, such as behind regime shield units";
  v34 = idGuiListBox::Printf(this: v30, fmt: "MoveCmd Arrive Action", a3: v33, a4: v32, a5: v31);
  idGuiListBox::Printf(this: v34, fmt: EnumName, a3: v37, a4: v36, a5: v35);
}


// ========================================================================
// ?GetDestinationOrigin@idAIMoveCmd@@QBA?AVidVec3@@XZ
// EA  : 0x82A69128
// RVA : 0x00A69128
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

idAIMoveCmd *__fastcall idAIMoveCmd::GetDestinationOrigin(idAIMoveCmd *this, idVec3 *result)
{
  float y; // r11
  float v4; // r10
  int z_low; // r9
  float z; // r10
  idEntity *v7; // r3
  idEntity *v8; // r3
  idPhysics *Physics; // r3
  int v10; // r3
  idAIMoveCmd::DestinationType v11; // r7
  int v12; // r6
  float v13; // r8
  int v14; // r7

  y = result->y;
  if ( LODWORD(y) == 2 )
  {
    v4 = result[1].y;
    z_low = LODWORD(result[1].z);
    this->__vftable = (idAIMoveCmd_vtbl *)LODWORD(result[1].x);
    *(float *)&this->destType = v4;
    this->destEnt.spawnId.value = z_low;
  }
  else if ( LODWORD(y) == 1 )
  {
    z = result->z;
    if ( gameLocal->spawnIds.ptr[LOWORD(z) & 0x1FFF] == SLODWORD(z) >> 13
      && (v7 = gameLocal->entities.ptr[LOWORD(z) & 0x1FFF]) != nullptr )
    {
      v8 = idEntity::CastTo(c: v7);
    }
    else
    {
      v8 = nullptr;
    }
    Physics = idEntity::GetPhysics(this: v8);
    v10 = (int)Physics->GetOrigin(this: Physics, a2: 0);
    v11 = *(_DWORD *)(v10 + 4);
    v12 = *(_DWORD *)(v10 + 8);
    this->__vftable = *(idAIMoveCmd_vtbl **)v10;
    this->destType = v11;
    this->destEnt.spawnId.value = v12;
  }
  else
  {
    v13 = vec3_origin.y;
    v14 = LODWORD(vec3_origin.z);
    this->__vftable = (idAIMoveCmd_vtbl *)LODWORD(vec3_origin.x);
    *(float *)&this->destType = v13;
    this->destEnt.spawnId.value = v14;
  }
  return this;
}


// ========================================================================
// ??0idAIMoveCmd@@QAA@PBD@Z
// EA  : 0x82A69228
// RVA : 0x00A69228
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

idAIMoveCmd *__fastcall idAIMoveCmd::idAIMoveCmd(idAIMoveCmd *this, const char *user)
{
  const char *v4; // r11

  this->__vftable = (idAIMoveCmd_vtbl *)&idAIMoveCmd::`vftable';
  this->destEnt.spawnId.value = 0x1FFF;
  idAnimWebState::idAnimWebState(this: &this->destAnim);
  idAIMoveCmd::Init(this);
  v4 = user;
  for ( this->userString = user; v4 != nullptr; ++v4 )
  {
    if ( *v4 == 0 )
      break;
    if ( *v4 == 92 )
      this->userString = v4 + 1;
  }
  return this;
}


// ========================================================================
// `dynamic initializer for 'idAIMoveCmd::s_null''
// EA  : 0x83368248
// RVA : 0x01368248
// PDB : w:\tech5\tungsten\game\ai\animfsm\aimovecmd.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idAIMoveCmd::s_null__()
{
  idAIMoveCmd::idAIMoveCmd(
    this: &idAIMoveCmd::s_null,
    user: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AIMoveCmd.cpp(17) : null");
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idAIMoveCmd::s_null__);
}

