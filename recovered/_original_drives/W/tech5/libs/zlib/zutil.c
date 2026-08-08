
// ========================================================================
// zcalloc
// EA  : 0x832249A0
// RVA : 0x012249A0
// PDB : w:\tech5\libs\zlib\zutil.c
// ========================================================================

void *__fastcall zcalloc(void *opaque, unsigned int items, unsigned int size)
{
  return malloc(size: items * size);
}

