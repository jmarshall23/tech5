
// ========================================================================
// ?jpeg_abort@@YAXPAUjpeg_common_struct@@@Z
// EA  : 0x832270A8
// RVA : 0x012270A8
// PDB : w:\tech5\libs\jpeg\jcomapi.cpp
// ========================================================================

void __fastcall jpeg_abort(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // r11
  int v3; // r11

  mem = cinfo->mem;
  if ( mem != nullptr )
  {
    ((void (*)(void))mem->free_pool)();
    if ( cinfo->is_decompressor != 0 )
    {
      v3 = 200;
      cinfo[11].mem = nullptr;
    }
    else
    {
      v3 = 100;
    }
    cinfo->global_state = v3;
  }
}


// ========================================================================
// ?jpeg_destroy@@YAXPAUjpeg_common_struct@@@Z
// EA  : 0x83227110
// RVA : 0x01227110
// PDB : w:\tech5\libs\jpeg\jcomapi.cpp
// ========================================================================

void __fastcall jpeg_destroy(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // r11

  mem = cinfo->mem;
  if ( mem != nullptr )
    ((void (*)(void))mem->self_destruct)();
  cinfo->mem = nullptr;
  cinfo->global_state = 0;
}


// ========================================================================
// ?jpeg_alloc_quant_table@@YAPAUJQUANT_TBL@@PAUjpeg_common_struct@@@Z
// EA  : 0x83227160
// RVA : 0x01227160
// PDB : w:\tech5\libs\jpeg\jcomapi.cpp
// ========================================================================

JQUANT_TBL *__fastcall jpeg_alloc_quant_table(jpeg_common_struct *cinfo)
{
  JQUANT_TBL *result; // r3

  result = (JQUANT_TBL *)((int (*)(void))cinfo->mem->alloc_small)();
  result->sent_table = 0;
  return result;
}


// ========================================================================
// ?jpeg_alloc_huff_table@@YAPAUJHUFF_TBL@@PAUjpeg_common_struct@@@Z
// EA  : 0x832271A0
// RVA : 0x012271A0
// PDB : w:\tech5\libs\jpeg\jcomapi.cpp
// ========================================================================

JHUFF_TBL *__fastcall jpeg_alloc_huff_table(jpeg_common_struct *cinfo)
{
  JHUFF_TBL *result; // r3

  result = (JHUFF_TBL *)((int (*)(void))cinfo->mem->alloc_small)();
  result->sent_table = 0;
  return result;
}

