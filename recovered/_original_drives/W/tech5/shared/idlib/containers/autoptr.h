
// ========================================================================
// ??1?$idAutoPtr_Array@U_XUSER_STATS_READ_RESULTS@@@@UAA@XZ
// EA  : 0x829E8AD8
// RVA : 0x009E8AD8
// PDB : w:\tech5\shared\idlib\containers\autoptr.h
// ========================================================================

void __fastcall idAutoPtr_Array<_XUSER_STATS_READ_RESULTS>::~idAutoPtr_Array<_XUSER_STATS_READ_RESULTS>(
        idAutoPtr_Array<_XUSER_STATS_READ_RESULTS> *this)
{
  _XUSER_STATS_READ_RESULTS *Pointee; // r4

  Pointee = this->Pointee;
  this->__vftable = (idAutoPtr_Array<_XUSER_STATS_READ_RESULTS>_vtbl *)&idAutoPtr_Array<_XUSER_STATS_READ_RESULTS>::`vftable';
  idMem::Free(this: &mem, ptr: Pointee, align: ALIGN_16);
}

