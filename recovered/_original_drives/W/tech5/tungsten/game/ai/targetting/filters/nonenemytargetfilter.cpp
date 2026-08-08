
// ========================================================================
// ??0idNonEnemyTargetFilter@@QAA@W4aiAwareness_t@@@Z
// EA  : 0x82B021A0
// RVA : 0x00B021A0
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\nonenemytargetfilter.cpp
// ========================================================================

idNonEnemyTargetFilter *__fastcall idNonEnemyTargetFilter::idNonEnemyTargetFilter(
        idNonEnemyTargetFilter *this,
        aiAwareness_t minAwareness_)
{
  this->minAwareness = minAwareness_;
  this->__vftable = (idNonEnemyTargetFilter_vtbl *)&idNonEnemyTargetFilter::`vftable';
  return this;
}


// ========================================================================
// ?InternalFilter@idNonEnemyTargetFilter@@MBA_NPBVidEntity@@ABVidTargetInfo@@@Z
// EA  : 0x82B021B8
// RVA : 0x00B021B8
// PDB : w:\tech5\tungsten\game\ai\targetting\filters\nonenemytargetfilter.cpp
// ========================================================================

BOOL __fastcall idNonEnemyTargetFilter::InternalFilter(
        idNonEnemyTargetFilter *this,
        const idEntity *owner,
        const idTargetInfo *ti)
{
  return ti->es->entityType != 3 && ti->attitude >= 2;
}

