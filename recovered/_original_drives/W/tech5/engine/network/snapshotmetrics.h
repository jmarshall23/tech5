
// ========================================================================
// ?Find@idSerializerLog@@QBAHHPBD0@Z
// EA  : 0x8289FFE0
// RVA : 0x0089FFE0
// PDB : w:\tech5\engine\network\snapshotmetrics.h
// ========================================================================

int __fastcall idSerializerLog::Find(
        idSerializerLog *this,
        int parentObjID,
        const char *typeName,
        const char *instanceName)
{
  int v7; // r29
  int i; // r31
  idSerializerLog::logEntry_t *v9; // r11

  v7 = 0;
  if ( this->logEntries.num <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    v9 = &this->logEntries.list[i];
    if ( v9->parentObjID == parentObjID && idStr::Icmp(s1: v9->typeName.data, s2: typeName) == 0 )
      break;
    if ( ++v7 >= this->logEntries.num )
      return -1;
  }
  return v7;
}


// ========================================================================
// ??0idSnapshotMetricRecord@idSnapshotMetrics@@QAA@XZ
// EA  : 0x828A0068
// RVA : 0x008A0068
// PDB : w:\tech5\engine\network\snapshotmetrics.h
// ========================================================================

idSnapshotMetrics::idSnapshotMetricRecord *__fastcall idSnapshotMetrics::idSnapshotMetricRecord::idSnapshotMetricRecord(
        idSnapshotMetrics::idSnapshotMetricRecord *this)
{
  idStr v3; // [sp+50h] [-40h] BYREF

  idStr::idStr(this: &v3, text: "SnapshotReport");
  idMetricRecord::idMetricRecord(this, _name: &v3);
  idStr::FreeData(this: &v3);
  this->__vftable = (idSnapshotMetrics::idSnapshotMetricRecord_vtbl *)&idSnapshotMetrics::idSnapshotMetricRecord::`vftable';
  this->text.len = 0;
  this->text.allocedAndFlag = 20;
  this->text.data = this->text.baseBuffer;
  this->text.baseBuffer[0] = 0;
  return this;
}


// ========================================================================
// __unwind$221067
// EA  : 0x828A00F4
// RVA : 0x008A00F4
// PDB : w:\tech5\engine\network\snapshotmetrics.h
// ========================================================================

void _unwind_221067()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// __unwind$221068
// EA  : 0x828A011C
// RVA : 0x008A011C
// PDB : w:\tech5\engine\network\snapshotmetrics.h
// ========================================================================

void _unwind_221068()
{
  int v0; // r12

  idMetricRecord::~idMetricRecord(this: *(idMetricRecord **)(v0 - 144 + 164));
}

