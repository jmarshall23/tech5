
// ========================================================================
// ?_jxr_r_TILE_SPATIAL_decode_mb@@YAHPAUjxr_image@@PAUrbitstream@@IIHH@Z
// EA  : 0x829144D0
// RVA : 0x009144D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_spatial.cpp
// ========================================================================

int __fastcall _jxr_r_TILE_SPATIAL_decode_mb(
        jxr_image *image,
        rbitstream *str,
        unsigned int tx,
        unsigned int ty,
        unsigned int mx,
        unsigned int my)
{
  int v12; // r27
  unsigned int v13; // r29
  unsigned int v14; // r3
  jxr_image *alpha; // r31
  unsigned int num_lp_qps; // r4
  unsigned int num_hp_qps; // r4
  int v18; // r10
  unsigned int *p_num_lp_qps; // r11
  unsigned __int8 *v20; // r9
  int result; // r3

  v12 = 0;
  if ( ((_cntlzw(image->header_flags2 & 1) & 0x20) == 0) != -1 )
  {
    do
    {
      v13 = 0;
      v14 = 0;
      alpha = image;
      if ( v12 != 0 )
        alpha = image->alpha;
      if ( alpha->bands_present != 3 )
      {
        num_lp_qps = alpha->num_lp_qps;
        if ( num_lp_qps > 1 && (*((_DWORD *)alpha + 26) & 0x20000000) == 0 )
          v13 = _jxr_DECODE_QP_INDEX(str, index_count: num_lp_qps);
        v14 = 0;
        if ( alpha->bands_present != 2 )
        {
          num_hp_qps = alpha->num_hp_qps;
          if ( num_hp_qps > 1 )
          {
            if ( (*((_DWORD *)alpha + 26) & 0x8000000) != 0 )
              v14 = v13;
            else
              v14 = _jxr_DECODE_QP_INDEX(str, index_count: num_hp_qps);
          }
        }
      }
      v18 = 0;
      if ( alpha->num_channels != 0 )
      {
        p_num_lp_qps = &alpha->num_lp_qps;
        v20 = &alpha->lp_quant_ch[15][v14];
        do
        {
          ++v18;
          *(_BYTE *)(84 * (alpha->tile_column_position[tx] + mx) + p_num_lp_qps[7] + 8) = v13;
          p_num_lp_qps += 7;
          v20 += 16;
          *(_BYTE *)(84 * (alpha->tile_column_position[tx] + mx) + *p_num_lp_qps + 9) = *v20;
        }
        while ( v18 < alpha->num_channels );
      }
      _jxr_r_MB_DC(image: alpha, str, alpha_flag: v12, tx, ty, mx, my);
      if ( alpha->bands_present == 3 )
      {
        _jxr_complete_cur_dclp(image: alpha, tx, mx, my);
      }
      else
      {
        _jxr_r_MB_LP(image: alpha, str, alpha_flag: v12, tx, ty, mx, my);
        _jxr_complete_cur_dclp(image: alpha, tx, mx, my);
        if ( alpha->bands_present != 2 )
        {
          result = _jxr_r_MB_CBP(image: alpha, str, alpha_flag: v12, tx, ty, mx, my);
          if ( result < 0 )
            return result;
          result = _jxr_r_MB_HP(image: alpha, str, alpha_flag: v12, tx, ty, mx, my);
          if ( result < 0 )
            return result;
        }
      }
      ++v12;
    }
    while ( __PAIR64__(v12, _cntlzw(image->header_flags2 & 1) & 0x20) < 0x100000001LL );
  }
  return 0;
}


// ========================================================================
// ?_jxr_r_TILE_SPATIAL_stripe@@YAHPAUjxr_image@@PAUrbitstream@@II@Z
// EA  : 0x82914710
// RVA : 0x00914710
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\r_tile_spatial.cpp
// ========================================================================

int __fastcall _jxr_r_TILE_SPATIAL_stripe(jxr_image *image, rbitstream *str, unsigned __int64 ty)
{
  unsigned int v5; // r29
  unsigned int v6; // r28
  __int64 v7; // r4
  char v8; // r23
  char v9; // r30
  char v10; // r26
  int v11; // r8
  unsigned int v12; // r11
  unsigned int v13; // r10
  unsigned int spatial_mb_width; // r26
  unsigned int v15; // r30
  int result; // r3
  unsigned int v17; // r6
  int v18; // r30
  unsigned int stripe_my; // r11
  unsigned int spatial_mb_height; // r10
  bool v21; // cr58
  unsigned int v22; // r6
  int v23; // r30
  unsigned int v24; // r11

  v5 = HIDWORD(ty);
  v6 = ty;
  if ( image->spatial_buffered_flag == 0 )
  {
    if ( (image->header_flags1 & 4) != 0 )
    {
      v7 = image->tile_index_table[image->tile_columns * ty + HIDWORD(ty)];
      _jxr_rbitstream_seek(str: (rbitstream *)HIDWORD(v7), a2: v7, off: ty);
    }
    v8 = _jxr_rbitstream_uint8(str);
    v9 = _jxr_rbitstream_uint8(str);
    v10 = _jxr_rbitstream_uint8(str);
    _jxr_rbitstream_uint8(str);
    if ( v8 != 0 || v9 != 0 || v10 != 1 )
      return -1;
    v11 = image->header_flags2 & 0x10;
    *((_DWORD *)image + 9) &= 0xFFFFFFFu;
    if ( v11 != 0 )
      *((_DWORD *)image + 9) = (_jxr_rbitstream_uint4(str) << 28) | *((_DWORD *)image + 9) & 0xFFFFFFF;
    _jxr_r_TILE_HEADER_DC(image, str, alpha_flag: 0, tx: v5, ty: v6);
    if ( image->bands_present != 3 )
    {
      _jxr_r_TILE_HEADER_LOWPASS(image, str, alpha_flag: 0, tx: v5, ty: v6);
      if ( image->bands_present != 2 )
        _jxr_r_TILE_HEADER_HIGHPASS(image, str, alpha_flag: 0, tx: v5, ty: v6);
    }
    if ( (image->header_flags2 & 1) != 0 )
    {
      _jxr_r_TILE_HEADER_DC(image: image->alpha, str, alpha_flag: 1, tx: v5, ty: v6);
      if ( image->bands_present != 3 )
      {
        _jxr_r_TILE_HEADER_LOWPASS(image: image->alpha, str, alpha_flag: 1, tx: v5, ty: v6);
        if ( image->bands_present != 2 )
          _jxr_r_TILE_HEADER_HIGHPASS(image: image->alpha, str, alpha_flag: 1, tx: v5, ty: v6);
      }
    }
    v12 = image->extended_height >> 4;
    v13 = image->extended_width >> 4;
    if ( (image->header_flags1 & 0x80) != 0 )
    {
      v12 = image->tile_row_height[v6];
      v13 = image->tile_column_width[v5];
    }
    image->spatial_mb_height = v12;
    image->spatial_mb_width = v13;
    image->spatial_buffered_flag = 1;
    image->stripe_my = 0;
    image->cleanup_state = 0;
  }
  if ( image->cleanup_state == 0 )
  {
    while ( 1 )
    {
      spatial_mb_width = image->spatial_mb_width;
      _jxr_r_rotate_mb_strip(image, my: image->stripe_my);
      if ( (image->header_flags2 & 1) != 0 )
        _jxr_r_rotate_mb_strip(image: image->alpha, my: image->stripe_my);
      v15 = 0;
      if ( spatial_mb_width != 0 )
      {
        do
        {
          result = _jxr_r_TILE_SPATIAL_decode_mb(image, str, tx: v5, ty: v6, mx: v15, my: image->stripe_my);
          if ( result < 0 )
            return result;
        }
        while ( ++v15 < spatial_mb_width );
      }
      v17 = image->stripe_my + 1;
      image->stripe_my = v17;
      v18 = _jxr_r_transform_mb_strip(image, tx: v5, ty: v6, my: v17);
      if ( (image->header_flags2 & 1) != 0 )
        _jxr_r_transform_mb_strip(image: image->alpha, tx: v5, ty: v6, my: image->stripe_my);
      stripe_my = image->stripe_my;
      spatial_mb_height = image->spatial_mb_height;
      v21 = stripe_my == spatial_mb_height;
      if ( stripe_my >= spatial_mb_height )
        break;
      if ( v18 != 0 )
      {
        v21 = stripe_my == spatial_mb_height;
        break;
      }
    }
    if ( v21 )
      _jxr_rbitstream_syncbyte(pLeafNode: (bfx::DynKDNode *)str);
    if ( v5 + 1 != image->tile_columns )
    {
      image->spatial_buffered_flag = 0;
      image->stripe_my = 0;
      return 1;
    }
    if ( image->stripe_my < image->spatial_mb_height && v18 != 0 )
      return 0;
    if ( v6 + 1 != image->tile_rows )
      goto LABEL_42;
    image->cleanup_state = 1;
    if ( v18 != 0 )
      return 0;
  }
  if ( v5 + 1 != image->tile_columns || v6 + 1 != image->tile_rows )
    return 1;
  if ( image->cleanup_state <= 3 )
  {
    while ( 1 )
    {
      _jxr_r_rotate_mb_strip(image, my: image->stripe_my);
      if ( (image->header_flags2 & 1) != 0 )
        _jxr_r_rotate_mb_strip(image: image->alpha, my: image->stripe_my);
      v22 = image->stripe_my + 1;
      image->stripe_my = v22;
      v23 = _jxr_r_transform_mb_strip(image, tx: v5, ty: v6, my: v22);
      if ( (image->header_flags2 & 1) != 0 )
        _jxr_r_transform_mb_strip(image: image->alpha, tx: v5, ty: v6, my: image->stripe_my);
      v24 = image->cleanup_state + 1;
      image->cleanup_state = v24;
      if ( v23 != 0 )
        break;
      if ( v24 > 3 )
      {
        image->spatial_buffered_flag = 0;
        image->stripe_my = 0;
        return -256;
      }
    }
    return 0;
  }
LABEL_42:
  image->spatial_buffered_flag = 0;
  image->stripe_my = 0;
  return -256;
}

