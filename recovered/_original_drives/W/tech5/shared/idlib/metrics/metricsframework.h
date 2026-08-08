
// ========================================================================
// ??0MachineInfo@idMetricsFramework@@QAA@XZ
// EA  : 0x82F3CCE8
// RVA : 0x00F3CCE8
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.h
// ========================================================================

idMetricsFramework::MachineInfo *__fastcall idMetricsFramework::MachineInfo::MachineInfo(
        idMetricsFramework::MachineInfo *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "MachineInfo");
  idMetricRecord::idMetricRecord(this, _name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idMetricsFramework::MachineInfo_vtbl *)&idMetricsFramework::MachineInfo::`vftable';
  return this;
}


// ========================================================================
// __unwind$111883
// EA  : 0x82F3CD54
// RVA : 0x00F3CD54
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.h
// ========================================================================

void _unwind_111883()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$111884
// EA  : 0x82F3CD7C
// RVA : 0x00F3CD7C
// PDB : w:\tech5\shared\idlib\metrics\metricsframework.h
// ========================================================================

void _unwind_111884()
{
  int v0; // r12

  idMetricRecord::~idMetricRecord(this: *(idMetricRecord **)(v0 - 144 + 164));
}

