
// ========================================================================
// ??0tlEventData_t@@QAA@XZ
// EA  : 0x8276ACC0
// RVA : 0x0076ACC0
// PDB : w:\tech5\engine\gamelib\timeline\timelineeventdata.cpp
// ========================================================================

tlEventData_t *__fastcall tlEventData_t::tlEventData_t(tlEventData_t *this)
{
  float roll; // r6

  this->time = 0;
  this->duration = 0;
  this->type = TL_EVENT_NONE;
  this->anim.allocedAndFlag = 20;
  this->anim.data = this->anim.baseBuffer;
  this->anim.len = 0;
  this->anim.baseBuffer[0] = 0;
  this->useAnimPos = false;
  this->sound = nullptr;
  this->worldPos = vec3_origin;
  this->worldRot.pitch = ang_zero.pitch;
  this->worldRot.yaw = ang_zero.yaw;
  roll = ang_zero.roll;
  this->keyName = TL_KEY_INVALID;
  this->worldRot.roll = roll;
  this->keyValue.allocedAndFlag = 20;
  this->keyValue.data = this->keyValue.baseBuffer;
  this->keyValue.len = 0;
  this->keyValue.baseBuffer[0] = 0;
  mgTimelineKeyAnimData::mgTimelineKeyAnimData(this: &this->keyAnimData);
  this->activateEnd = false;
  this->activateStart = true;
  this->env = nullptr;
  return this;
}


// ========================================================================
// __unwind$245838
// EA  : 0x8276AD90
// RVA : 0x0076AD90
// PDB : w:\tech5\engine\gamelib\timeline\timelineeventdata.cpp
// ========================================================================

void _unwind_245838()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}


// ========================================================================
// __unwind$245839
// EA  : 0x8276ADBC
// RVA : 0x0076ADBC
// PDB : w:\tech5\engine\gamelib\timeline\timelineeventdata.cpp
// ========================================================================

void _unwind_245839()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 80));
}

