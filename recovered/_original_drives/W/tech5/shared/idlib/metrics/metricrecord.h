
// ========================================================================
// ??1idMetricRecord@@UAA@XZ
// EA  : 0x82642628
// RVA : 0x00642628
// PDB : w:\tech5\shared\idlib\metrics\metricrecord.h
// ========================================================================

void __fastcall idMetricRecord::~idMetricRecord(idMetricRecord *this)
{
  this->__vftable = (idMetricRecord_vtbl *)&idMetricRecord::`vftable';
  idStr::FreeData(this: &this->baseName);
  idStr::FreeData(this: &this->name);
}


// ========================================================================
// __unwind$235060
// EA  : 0x8264267C
// RVA : 0x0064267C
// PDB : w:\tech5\shared\idlib\metrics\metricrecord.h
// ========================================================================

void _unwind_235060()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}

