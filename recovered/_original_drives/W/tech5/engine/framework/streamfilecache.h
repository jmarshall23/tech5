
// ========================================================================
// ??0pinnedCacheLines_t@@QAA@XZ
// EA  : 0x829A0CD8
// RVA : 0x009A0CD8
// PDB : w:\tech5\engine\framework\streamfilecache.h
// ========================================================================

pinnedCacheLines_t *__fastcall pinnedCacheLines_t::pinnedCacheLines_t(pinnedCacheLines_t *this)
{
  __int64 v1; // r11

  LODWORD(v1) = 0;
  this->cacheFile = nullptr;
  this->ofs = v1;
  this->length = 0;
  this->numLines = 0;
  this->extra = 0;
  return this;
}

