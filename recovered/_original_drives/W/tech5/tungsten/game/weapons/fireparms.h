
// ========================================================================
// ??0deferredFire_t@idDeferredFireManager@@QAA@XZ
// EA  : 0x82EB5AC8
// RVA : 0x00EB5AC8
// PDB : w:\tech5\tungsten\game\weapons\fireparms.h
// ========================================================================

idDeferredFireManager::deferredFire_t *__fastcall idDeferredFireManager::deferredFire_t::deferredFire_t(
        idDeferredFireManager::deferredFire_t *this)
{
  int *p_startTime; // r11
  __int64 v3; // r9
  int i; // ctr

  idFireParms::idFireParms(this: &this->fireParms);
  p_startTime = &this->fireParms.startTime;
  LODWORD(v3) = 0;
  for ( i = 16; i != 0; --i )
  {
    p_startTime += 2;
    *(_QWORD *)p_startTime = v3;
  }
  this->fireResults.numTraces = 0;
  memset(Dst: this->fireResults.traces, Val: 0, Size: sizeof(this->fireResults.traces));
  memset(Dst: this->fireResults.traceDirs, Val: 0, Size: sizeof(this->fireResults.traceDirs));
  memset(Dst: this->fireResults.traceLens, Val: 0, Size: sizeof(this->fireResults.traceLens));
  this->handle = 0;
  this->numTraces = 0;
  memset(Dst: this->queryHandles, Val: 0, Size: sizeof(this->queryHandles));
  return this;
}

