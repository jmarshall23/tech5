
// ========================================================================
// rd_decoder_init
// EA  : 0x832337C8
// RVA : 0x012337C8
// PDB : w:\tech5\libs\mgrd\src\rdinternal.c
// ========================================================================

void __fastcall rd_decoder_init(RD_DECODER *decoder, MGRINGBUF *ringbuf)
{
  memset(Dst: decoder, Val: 0, Size: sizeof(RD_DECODER));
  decoder->ringbuf = ringbuf;
}


// ========================================================================
// rd_decoder_fetch
// EA  : 0x83233810
// RVA : 0x01233810
// PDB : w:\tech5\libs\mgrd\src\rdinternal.c
// ========================================================================

RD_HEADER *__fastcall rd_decoder_fetch(RD_DECODER *decoder)
{
  int *p_step; // r28
  int step; // r11
  unsigned int v5; // r11
  unsigned int v6; // r11

  p_step = &decoder->step;
  step = decoder->step;
  if ( step != 0 )
  {
    if ( step != 1 )
      return nullptr;
  }
  else
  {
    v5 = decoder->buffer_size
       + mgringbuf_get(
           ringbuf: decoder->ringbuf,
           buffer: &decoder->buffer[decoder->buffer_size],
           maxsize: 24 - decoder->buffer_size);
    decoder->buffer_size = v5;
    if ( v5 != 24 )
      return nullptr;
    ++*p_step;
  }
  if ( *(_WORD *)decoder->buffer != 0 )
  {
    v6 = decoder->buffer_size
       + mgringbuf_get(
           ringbuf: decoder->ringbuf,
           buffer: &decoder->buffer[decoder->buffer_size],
           maxsize: *(unsigned __int16 *)decoder->buffer - decoder->buffer_size + 24);
    decoder->buffer_size = v6;
    if ( v6 != *(unsigned __int16 *)decoder->buffer + 24 )
      return nullptr;
  }
  *p_step = 0;
  decoder->buffer_size = 0;
  return (RD_HEADER *)decoder->buffer;
}

