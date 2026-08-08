
// ========================================================================
// `idSWF::Inflate'::`2'::local_swf_alloc_t::zalloc
// EA  : 0x8279E6F8
// RVA : 0x0079E6F8
// PDB : w:\tech5\engine\guis\swf\swf_zlib.cpp
// ========================================================================

void *__fastcall _idSWF::Inflate_::_2_::local_swf_alloc_t::zalloc(void *opaque, unsigned int items, unsigned int size)
{
  return idMem::AllocWithLocation(
           this: &mem,
           location: "w:\\tech5\\engine\\guis\\swf\\SWF_Zlib.cpp(19) : TAG_SWF",
           size: items * size,
           tag: TAG_SWF,
           zeroBuffer: false,
           align: ALIGN_16,
           heap: HEAP_DEFAULTHEAP);
}


// ========================================================================
// ?Inflate@idSWF@@AAA_NPBEHPAEH@Z
// EA  : 0x8279E728
// RVA : 0x0079E728
// PDB : w:\tech5\engine\guis\swf\swf_zlib.cpp
// ========================================================================

BOOL __fastcall idSWF::Inflate(
        idSWF *this,
        unsigned __int8 *input,
        unsigned int inputSize,
        unsigned __int8 *output,
        unsigned int outputSize,
        __int64 a6)
{
  char *v6; // r11
  int i; // ctr
  BOOL v8; // r31
  char v10; // [sp+48h] [-58h] BYREF
  z_stream_s v11; // [sp+50h] [-50h] BYREF

  v6 = &v10;
  LODWORD(a6) = 0;
  for ( i = 7; i != 0; --i )
  {
    v6 += 8;
    *(_QWORD *)v6 = a6;
  }
  v11.next_in = input;
  v11.avail_in = inputSize;
  v11.avail_out = outputSize;
  v11.next_out = output;
  v11.zalloc = _idSWF::Inflate_::_2_::local_swf_alloc_t::zalloc;
  v11.zfree = ZlibFree;
  inflateInit_(strm: &v11, version: "1.2.3", stream_size: 56);
  v8 = (_cntlzw(inflate(strm: &v11, flush: 4) - 1) & 0x20) != 0;
  inflateEnd(strm: &v11);
  return v8;
}

