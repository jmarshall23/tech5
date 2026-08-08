
// ========================================================================
// ?_jxr_w_TILE_SPATIAL@@YAXPAUjxr_image@@PAUwbitstream@@II@Z
// EA  : 0x829221A8
// RVA : 0x009221A8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\w_tile_spatial.cpp
// ========================================================================

void __fastcall _jxr_w_TILE_SPATIAL(jxr_image *image, wbitstream *str, unsigned int tx, unsigned int ty)
{
  unsigned int v8; // r21
  unsigned int v9; // r22
  unsigned int v10; // r29
  unsigned int i; // r23
  unsigned int j; // r30
  unsigned int k; // r24
  jxr_image *alpha; // r31
  unsigned __int8 v15; // r3
  unsigned __int8 v16; // r3

  _jxr_wbitstream_uint8(str, val: 0);
  _jxr_wbitstream_uint8(str, val: 0);
  _jxr_wbitstream_uint8(str, val: 1u);
  _jxr_wbitstream_uint8(str, val: 0);
  if ( (image->header_flags2 & 0x10) != 0 )
    _jxr_wbitstream_uint4(str, val: *((_DWORD *)image + 9) >> 28);
  _jxr_w_TILE_HEADER_DC(image, str, alpha_flag: 0, tx, ty);
  if ( image->bands_present != 3 )
  {
    _jxr_w_TILE_HEADER_LOWPASS(image, str, alpha_flag: 0, tx, ty);
    if ( image->bands_present != 2 )
      _jxr_w_TILE_HEADER_HIGHPASS(image, str, alpha_flag: 0, tx, ty);
  }
  if ( (image->header_flags2 & 1) != 0 )
  {
    _jxr_w_TILE_HEADER_DC(image: image->alpha, str, alpha_flag: 1, tx, ty);
    if ( image->bands_present != 3 )
    {
      _jxr_w_TILE_HEADER_LOWPASS(image: image->alpha, str, alpha_flag: 1, tx, ty);
      if ( image->bands_present != 2 )
        _jxr_w_TILE_HEADER_HIGHPASS(image: image->alpha, str, alpha_flag: 1, tx, ty);
    }
  }
  v8 = image->extended_height >> 4;
  v9 = image->extended_width >> 4;
  if ( (image->header_flags1 & 0x80) != 0 )
  {
    v8 = image->tile_row_height[ty];
    v9 = image->tile_column_width[tx];
  }
  v10 = 0;
  for ( i = ((_cntlzw(image->header_flags2 & 1) & 0x20) == 0) + 1; v10 < v8; ++v10 )
  {
    _jxr_w_flush_rotate_mb_strip(image, tx, ty, my: v10, read_new: 1);
    for ( j = 0; j < v9; ++j )
    {
      for ( k = 0; k < i; ++k )
      {
        alpha = image;
        if ( k != 0 )
          alpha = image->alpha;
        if ( alpha->bands_present != 3 )
        {
          if ( alpha->num_lp_qps > 1 && (*((_DWORD *)alpha + 26) & 0x20000000) == 0 )
          {
            v15 = _jxr_select_lp_index(image: alpha, tx, ty, mx: j, my: v10);
            _jxr_w_ENCODE_QP_INDEX(image: alpha, str, tx, ty, mx: j, my: v10, num_qps: alpha->num_lp_qps, qp_index: v15);
          }
          if ( alpha->bands_present != 2 && alpha->num_hp_qps > 1 && (*((_DWORD *)alpha + 26) & 0x8000000) == 0 )
          {
            v16 = _jxr_select_hp_index(image: alpha, tx, ty, mx: j, my: v10);
            _jxr_w_ENCODE_QP_INDEX(image: alpha, str, tx, ty, mx: j, my: v10, num_qps: alpha->num_hp_qps, qp_index: v16);
          }
        }
        _jxr_w_MB_DC(image: alpha, str, alpha_flag: 0, tx, ty, mx: j, my: v10);
        if ( alpha->bands_present != 3 )
        {
          _jxr_w_MB_LP(image: alpha, str, alpha_flag: 0, tx, ty, mx: j, my: v10);
          if ( alpha->bands_present != 2 )
          {
            _jxr_w_MB_CBP(image: alpha, str, alpha_flag: 0, tx, ty, mx: j, my: v10);
            _jxr_w_MB_HP(image: alpha, str, alpha_flag: 0, tx, ty, mx: j, my: v10, strFB: nullptr);
          }
        }
      }
    }
  }
  _jxr_wbitstream_syncbyte(str);
  _jxr_wbitstream_flush(str);
}

