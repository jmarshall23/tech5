
// ========================================================================
// ?_jxr_w_TILE_DC@@YAXPAUjxr_image@@PAUwbitstream@@II@Z
// EA  : 0x82921E50
// RVA : 0x00921E50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_tile_frequency.cpp
// ========================================================================

void __fastcall _jxr_w_TILE_DC(jxr_image *image, wbitstream *str, unsigned int tx, unsigned int ty)
{
  unsigned int v8; // r24
  unsigned int v9; // r25
  unsigned int i; // r29
  unsigned int j; // r30

  _jxr_wbitstream_uint8(str, val: 0);
  _jxr_wbitstream_uint8(str, val: 0);
  _jxr_wbitstream_uint8(str, val: 1u);
  _jxr_wbitstream_uint8(str, val: 0);
  _jxr_w_TILE_HEADER_DC(image, str, alpha_flag: 0, tx, ty);
  if ( (image->header_flags2 & 1) != 0 )
    _jxr_w_TILE_HEADER_DC(image: image->alpha, str, alpha_flag: 1, tx, ty);
  v8 = image->extended_height >> 4;
  v9 = image->extended_width >> 4;
  if ( (image->header_flags1 & 0x80) != 0 )
  {
    v8 = image->tile_row_height[ty];
    v9 = image->tile_column_width[tx];
  }
  for ( i = 0; i < v8; ++i )
  {
    _jxr_w_flush_rotate_mb_strip(image, tx, ty, my: i, read_new: 1);
    for ( j = 0; j < v9; ++j )
    {
      _jxr_w_MB_DC(image, str, alpha_flag: 0, tx, ty, mx: j, my: i);
      if ( (image->header_flags2 & 1) != 0 )
        _jxr_w_MB_DC(image: image->alpha, str, alpha_flag: 1, tx, ty, mx: j, my: i);
    }
  }
  _jxr_wbitstream_syncbyte(str);
  _jxr_wbitstream_flush(str);
}


// ========================================================================
// ?_jxr_w_TILE_LP@@YAXPAUjxr_image@@PAUwbitstream@@II@Z
// EA  : 0x82921FC8
// RVA : 0x00921FC8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_tile_frequency.cpp
// ========================================================================

void __fastcall _jxr_w_TILE_LP(jxr_image *image, wbitstream *str, unsigned int tx, unsigned int ty)
{
  unsigned int bands_present_of_primary; // r23
  unsigned int v9; // r24
  unsigned int v10; // r25
  unsigned int i; // r29
  unsigned int j; // r30
  unsigned __int8 v13; // r3

  bands_present_of_primary = image->bands_present_of_primary;
  if ( bands_present_of_primary < 3 )
  {
    _jxr_wbitstream_uint8(str, val: 0);
    _jxr_wbitstream_uint8(str, val: 0);
    _jxr_wbitstream_uint8(str, val: 1u);
    _jxr_wbitstream_uint8(str, val: 0);
    _jxr_w_TILE_HEADER_LOWPASS(image, str, alpha_flag: 0, tx, ty);
    if ( (image->header_flags2 & 1) != 0 )
      _jxr_w_TILE_HEADER_LOWPASS(image: image->alpha, str, alpha_flag: 1, tx, ty);
  }
  v9 = image->extended_height >> 4;
  v10 = image->extended_width >> 4;
  if ( (image->header_flags1 & 0x80) != 0 )
  {
    v9 = image->tile_row_height[ty];
    v10 = image->tile_column_width[tx];
  }
  for ( i = 0; i < v9; ++i )
  {
    _jxr_w_flush_rotate_mb_strip(image, tx, ty, my: i, read_new: 0);
    for ( j = 0; j < v10; ++j )
    {
      if ( bands_present_of_primary < 3 )
      {
        if ( image->num_lp_qps > 1 && (*((_DWORD *)image + 26) & 0x20000000) == 0 )
        {
          v13 = _jxr_select_lp_index(image, tx, ty, mx: j, my: i);
          _jxr_w_ENCODE_QP_INDEX(image, str, tx, ty, mx: j, my: i, num_qps: image->num_lp_qps, qp_index: v13);
        }
        _jxr_w_MB_LP(image, str, alpha_flag: 0, tx, ty, mx: j, my: i);
        if ( (image->header_flags2 & 1) != 0 )
          _jxr_w_MB_LP(image: image->alpha, str, alpha_flag: 1, tx, ty, mx: j, my: i);
      }
    }
  }
  _jxr_wbitstream_syncbyte(str);
  _jxr_wbitstream_flush(str);
}

