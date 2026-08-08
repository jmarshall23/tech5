
// ========================================================================
// ??0idSpecialEvent_Area_Tracker@@QAA@XZ
// EA  : 0x8253E3C0
// RVA : 0x0053E3C0
// PDB : w:\tech5\tungsten\game\player\jobmanager.h
// ========================================================================

idSpecialEvent_Area_Tracker *__fastcall idSpecialEvent_Area_Tracker::idSpecialEvent_Area_Tracker(
        idSpecialEvent_Area_Tracker *this)
{
  this->__vftable = (idSpecialEvent_Area_Tracker_vtbl *)&idSpecialEvent_Area_Tracker::`vftable';
  this->areaDecl.len = 0;
  this->areaDecl.allocedAndFlag = 20;
  this->areaDecl.data = this->areaDecl.baseBuffer;
  this->areaDecl.baseBuffer[0] = 0;
  this->jobStingersPlayed.list = nullptr;
  this->jobStingersPlayed.granularity = 0;
  this->jobStingersPlayed.memTag = 5;
  this->jobStingersPlayed.listStatic = 0;
  this->jobStingersPlayed.size = 0;
  this->jobStingersPlayed.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->jobStingersPlayed);
  return this;
}


// ========================================================================
// __unwind$583611
// EA  : 0x8253E44C
// RVA : 0x0053E44C
// PDB : w:\tech5\tungsten\game\player\jobmanager.h
// ========================================================================

void _unwind_583611()
{
  int v0; // r12

  idAIEvent::~idAIEvent(this: *(idAimAssist **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$583612
// EA  : 0x8253E474
// RVA : 0x0053E474
// PDB : w:\tech5\tungsten\game\player\jobmanager.h
// ========================================================================

void _unwind_583612()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}

