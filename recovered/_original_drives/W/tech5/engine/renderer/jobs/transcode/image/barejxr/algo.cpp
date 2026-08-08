
// ========================================================================
// ?_jxr_floor_div2@@YAHH@Z
// EA  : 0x828FEF78
// RVA : 0x008FEF78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

int __fastcall _jxr_floor_div2(int x)
{
  if ( x < 0 )
    return (1 - x) / -2;
  else
    return x / 2;
}


// ========================================================================
// ?_jxr_ceil_div2@@YAHH@Z
// EA  : 0x828FEFA0
// RVA : 0x008FEFA0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

int __fastcall _jxr_ceil_div2(int x)
{
  if ( x < 0 )
    return x / 2;
  else
    return (x + 1) / 2;
}


// ========================================================================
// ?_jxr_quant_map@@YAHPAUjxr_image@@HH@Z
// EA  : 0x828FEFC8
// RVA : 0x008FEFC8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

int __fastcall _jxr_quant_map(jxr_image *image, int x, char shift)
{
  if ( x == 0 )
    return 1;
  if ( *((int *)image + 26) >= 0 )
  {
    if ( x >= 32 )
    {
      if ( x >= 48 )
        return (x % 16 + 16) << ((x >> 4) - 3);
      else
        return (x % 16 + 17) >> 1 << ((x >> 4) - 2);
    }
    else
    {
      return (x + 3) >> 2;
    }
  }
  else if ( x >= 16 )
  {
    return (x % 16 + 16) << ((x >> 4) + shift - 1);
  }
  else
  {
    return x << shift;
  }
}


// ========================================================================
// ?_jxr_vlc_select@@YAHHH@Z
// EA  : 0x828FF090
// RVA : 0x008FF090
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

int __fastcall _jxr_vlc_select(unsigned int band, unsigned int chroma_flag)
{
  int result; // r3
  bool v4; // cr58
  bool v5; // zf

  v4 = band == 1;
  v5 = band == 0;
  result = 0;
  if ( v5 )
    return chroma_flag != 0;
  if ( v4 )
    return ((_cntlzw(chroma_flag) & 0x20) == 0) + 3;
  if ( band < 3 )
    return ((_cntlzw(chroma_flag) & 0x20) == 0) + 5;
  return result;
}


// ========================================================================
// ?_jxr_InitVLCTable@@YAXPAUjxr_image@@H@Z
// EA  : 0x828FF0E0
// RVA : 0x008FF0E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_InitVLCTable(jxr_image *image, int vlc_select)
{
  adaptive_vlc_s *v2; // r11

  v2 = &image->vlc_table[vlc_select];
  v2->table = 0;
  v2->deltatable = 0;
  v2->discriminant = 0;
}


// ========================================================================
// ?_jxr_AdaptVLCTable@@YAXPAUjxr_image@@H@Z
// EA  : 0x828FF108
// RVA : 0x008FF108
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_AdaptVLCTable(jxr_image *image, int vlc_select)
{
  adaptive_vlc_s *v2; // r11
  int discriminant; // r10
  int v4; // r8
  int table; // r8

  v2 = &image->vlc_table[vlc_select];
  discriminant = v2->discriminant;
  v2->deltatable = 0;
  if ( discriminant < -8 && (v4 = v2->table) != 0 )
  {
    v2->discriminant = 0;
    v2->table = v4 - 1;
  }
  else if ( discriminant <= 8 || (table = v2->table) == 1 )
  {
    if ( discriminant >= -64 )
    {
      if ( discriminant > 64 )
        v2->discriminant = 64;
    }
    else
    {
      v2->discriminant = -64;
    }
  }
  else
  {
    v2->discriminant = 0;
    v2->table = table + 1;
  }
}


// ========================================================================
// AdaptVLCTable2
// EA  : 0x828FF198
// RVA : 0x008FF198
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall AdaptVLCTable2(jxr_image *image, int vlc_select, int max_index)
{
  adaptive_vlc_s *v3; // r11
  int discriminant; // r10
  int discriminant2; // r8
  int table; // r9
  int v7; // r10
  int v8; // r9
  int v9; // r10

  v3 = &image->vlc_table[vlc_select];
  discriminant = v3->discriminant;
  discriminant2 = v3->discriminant2;
  if ( v3->discriminant < -8 )
  {
    table = v3->table;
    if ( table > 0 )
    {
      v7 = table - 1;
      goto LABEL_7;
    }
  }
  if ( discriminant2 > 8 )
  {
    v8 = v3->table;
    if ( v8 < max_index )
    {
      v7 = v8 + 1;
LABEL_7:
      v3->table = v7;
      v3->discriminant = 0;
      v3->discriminant2 = 0;
      if ( v7 == max_index )
      {
        v9 = v7 - 1;
        v3->deltatable = v9;
        v3->delta2table = v9;
      }
      else if ( v7 != 0 )
      {
        v3->delta2table = v7;
        v3->deltatable = v7 - 1;
      }
      else
      {
        v3->deltatable = 0;
        v3->delta2table = 0;
      }
      return;
    }
  }
  if ( discriminant >= -64 )
  {
    if ( discriminant > 64 )
      v3->discriminant = 64;
  }
  else
  {
    v3->discriminant = -64;
  }
  if ( discriminant2 < -64 )
    v3->discriminant2 = -64;
  if ( v3->discriminant2 > 64 )
    v3->discriminant2 = 64;
}


// ========================================================================
// ?_jxr_AdaptLP@@YAXPAUjxr_image@@@Z
// EA  : 0x828FF280
// RVA : 0x008FF280
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_AdaptLP(jxr_image *image)
{
  jxr_image *v1; // r3
  int v2; // r5
  jxr_image *v3; // r3
  jxr_image *v4; // r3
  jxr_image *v5; // r3
  int v6; // r5
  jxr_image *v7; // r3
  jxr_image *v8; // r3
  jxr_image *v9; // r3

  AdaptVLCTable2(image, vlc_select: 2, max_index: 4);
  AdaptVLCTable2(image: v1, vlc_select: 7, max_index: 3);
  AdaptVLCTable2(image: v3, vlc_select: 8, max_index: v2);
  AdaptVLCTable2(image: v4, vlc_select: 9, max_index: 4);
  AdaptVLCTable2(image: v5, vlc_select: 10, max_index: 3);
  AdaptVLCTable2(image: v7, vlc_select: 11, max_index: v6);
  _jxr_AdaptVLCTable(image: v8, vlc_select: 3);
  _jxr_AdaptVLCTable(image: v9, vlc_select: 4);
}


// ========================================================================
// ?_jxr_AdaptHP@@YAXPAUjxr_image@@@Z
// EA  : 0x828FF2F0
// RVA : 0x008FF2F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_AdaptHP(jxr_image *image)
{
  jxr_image *v1; // r3
  int v2; // r5
  jxr_image *v3; // r3
  jxr_image *v4; // r3
  jxr_image *v5; // r3
  int v6; // r5
  jxr_image *v7; // r3
  jxr_image *v8; // r3
  jxr_image *v9; // r3
  jxr_image *v10; // r3
  jxr_image *v11; // r3

  AdaptVLCTable2(image, vlc_select: 16, max_index: 4);
  AdaptVLCTable2(image: v1, vlc_select: 14, max_index: 3);
  AdaptVLCTable2(image: v3, vlc_select: 15, max_index: v2);
  AdaptVLCTable2(image: v4, vlc_select: 17, max_index: 4);
  AdaptVLCTable2(image: v5, vlc_select: 18, max_index: 3);
  AdaptVLCTable2(image: v7, vlc_select: 19, max_index: v6);
  _jxr_AdaptVLCTable(image: v8, vlc_select: 5);
  _jxr_AdaptVLCTable(image: v9, vlc_select: 6);
  _jxr_AdaptVLCTable(image: v10, vlc_select: 12);
  _jxr_AdaptVLCTable(image: v11, vlc_select: 13);
}


// ========================================================================
// ?_jxr_InitContext@@YAHPAUjxr_image@@IIII@Z
// EA  : 0x828FF370
// RVA : 0x008FF370
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

int __fastcall _jxr_InitContext(jxr_image *image, unsigned int tx, unsigned int ty, unsigned int mx, unsigned int my)
{
  int result; // r3

  if ( mx != 0 )
    return 0;
  result = 1;
  if ( my != 0 )
    return 0;
  return result;
}


// ========================================================================
// ?_jxr_ResetContext@@YAHPAUjxr_image@@II@Z
// EA  : 0x828FF390
// RVA : 0x008FF390
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

BOOL __fastcall _jxr_ResetContext(jxr_image *image, unsigned int tx, unsigned int mx)
{
  return (mx & 0xF) == 0 || (_cntlzw(mx + 1 - image->tile_column_width[tx]) & 0x20) != 0;
}


// ========================================================================
// ?_jxr_ResetTotals@@YAHPAUjxr_image@@I@Z
// EA  : 0x828FF3C8
// RVA : 0x008FF3C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

BOOL __fastcall _jxr_ResetTotals(jxr_image *image, char mx)
{
  return (_cntlzw(mx & 0xF) & 0x20) != 0;
}


// ========================================================================
// ?_jxr_InitializeModelMB@@YAXPAUmodel_s@@H@Z
// EA  : 0x828FF3D8
// RVA : 0x008FF3D8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_InitializeModelMB(model_s *model, int band)
{
  int *v2; // r11
  int i; // ctr

  v2 = &model[-1].state[15];
  for ( i = 16; i != 0; --i )
  {
    v2[17] = 0;
    *++v2 = 4 * (2 - band);
  }
}


// ========================================================================
// ?_jxr_UpdateModelMB@@YAXPAUjxr_image@@QAHPAUmodel_s@@H@Z
// EA  : 0x828FF400
// RVA : 0x008FF400
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_UpdateModelMB(jxr_image *image, char *lap_mean, model_s *model, int band)
{
  int v4; // r8
  model_s *v5; // r10
  int use_clr_fmt; // r11
  int v7; // r9
  char *v8; // r11
  int v9; // r6
  const int *v10; // r7
  int i; // r6
  int v12; // r11
  int v13; // r9
  int v14; // r9
  int v15; // r9
  int v16; // r9

  v4 = band;
  v5 = model;
  *(_DWORD *)lap_mean *= weight0[band];
  use_clr_fmt = image->use_clr_fmt;
  if ( use_clr_fmt == 1 )
  {
    v10 = weight2;
  }
  else
  {
    if ( use_clr_fmt != 2 )
    {
      v7 = 1;
      if ( image->num_channels > 1u )
      {
        v8 = lap_mean;
        do
        {
          ++v7;
          v9 = *((_DWORD *)v8 + 1) * weight0[v4];
          v8 += 4;
          *(_DWORD *)v8 = v9;
        }
        while ( v7 < image->num_channels );
      }
      goto LABEL_10;
    }
    v10 = weight3;
  }
  *((_DWORD *)lap_mean + 1) *= v10[v4];
LABEL_10:
  for ( i = 0; i < 16; ++i )
  {
    v12 = v5->state[0];
    v13 = (*(int *)((char *)v5->bits + lap_mean - (char *)model) - 70) >> 2;
    if ( v13 > -8 )
    {
      if ( v13 >= 8 )
      {
        v16 = v13 - 4;
        if ( v16 > 15 )
          v16 = 15;
        v12 += v16;
        if ( v12 > 8 )
        {
          if ( v5->bits[0] >= 15 )
          {
            v12 = 8;
            v5->bits[0] = 15;
            goto LABEL_26;
          }
          v15 = v5->bits[0] + 1;
LABEL_25:
          v5->bits[0] = v15;
          v12 = 0;
        }
      }
    }
    else
    {
      v14 = v13 + 4;
      if ( v14 < -16 )
        v14 = -16;
      v12 += v14;
      if ( v12 < -8 )
      {
        if ( v5->bits[0] != 0 )
        {
          v15 = v5->bits[0] - 1;
          goto LABEL_25;
        }
        v12 = -8;
      }
    }
LABEL_26:
    v5->state[0] = v12;
    if ( image->use_clr_fmt == 0 )
      break;
    v5 = (model_s *)((char *)v5 + 4);
  }
}


// ========================================================================
// ?_jxr_InitializeCountCBPLP@@YAXPAUjxr_image@@@Z
// EA  : 0x828FF558
// RVA : 0x008FF558
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_InitializeCountCBPLP(jxr_image *image)
{
  image->count_max_CBPLP = 1;
  image->count_zero_CBPLP = 1;
}


// ========================================================================
// ?_jxr_UpdateCountCBPLP@@YAXPAUjxr_image@@HH@Z
// EA  : 0x828FF568
// RVA : 0x008FF568
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_UpdateCountCBPLP(jxr_image *image, int cbplp, int max)
{
  int v3; // r11
  int v4; // r11

  v3 = image->count_zero_CBPLP + 1;
  image->count_zero_CBPLP = v3;
  if ( cbplp == 0 )
    image->count_zero_CBPLP = v3 - 4;
  if ( image->count_zero_CBPLP > 7 )
    image->count_zero_CBPLP = 7;
  if ( image->count_zero_CBPLP < -8 )
    image->count_zero_CBPLP = -8;
  v4 = image->count_max_CBPLP + 1;
  image->count_max_CBPLP = v4;
  if ( cbplp == max )
    image->count_max_CBPLP = v4 - 4;
  if ( image->count_max_CBPLP > 7 )
    image->count_max_CBPLP = 7;
  if ( image->count_max_CBPLP < -8 )
    image->count_max_CBPLP = -8;
}


// ========================================================================
// ?_jxr_InitLPVLC@@YAXPAUjxr_image@@@Z
// EA  : 0x828FF5F0
// RVA : 0x008FF5F0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_InitLPVLC(jxr_image *image)
{
  image->vlc_table[2].deltatable = 0;
  image->vlc_table[2].table = 1;
  image->vlc_table[2].delta2table = 1;
  image->vlc_table[2].discriminant = 0;
  image->vlc_table[2].discriminant2 = 0;
  image->vlc_table[7].table = 1;
  image->vlc_table[7].deltatable = 0;
  image->vlc_table[7].delta2table = 1;
  image->vlc_table[7].discriminant = 0;
  image->vlc_table[7].discriminant2 = 0;
  image->vlc_table[8].table = 1;
  image->vlc_table[8].deltatable = 0;
  image->vlc_table[8].delta2table = 1;
  image->vlc_table[8].discriminant = 0;
  image->vlc_table[8].discriminant2 = 0;
  image->vlc_table[9].table = 1;
  image->vlc_table[9].deltatable = 0;
  image->vlc_table[9].delta2table = 1;
  image->vlc_table[9].discriminant = 0;
  image->vlc_table[9].discriminant2 = 0;
  image->vlc_table[10].table = 1;
  image->vlc_table[10].deltatable = 0;
  image->vlc_table[10].delta2table = 1;
  image->vlc_table[10].discriminant = 0;
  image->vlc_table[10].discriminant2 = 0;
  image->vlc_table[11].table = 1;
  image->vlc_table[11].deltatable = 0;
  image->vlc_table[11].delta2table = 1;
  image->vlc_table[11].discriminant = 0;
  image->vlc_table[11].discriminant2 = 0;
  image->vlc_table[3].table = 0;
  image->vlc_table[3].deltatable = 0;
  image->vlc_table[3].discriminant = 0;
  image->vlc_table[4].table = 0;
  image->vlc_table[4].deltatable = 0;
  image->vlc_table[4].discriminant = 0;
}


// ========================================================================
// ?_jxr_InitializeAdaptiveScanLP@@YAXPAUjxr_image@@@Z
// EA  : 0x828FF690
// RVA : 0x008FF690
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_InitializeAdaptiveScanLP(jxr_image *image)
{
  unsigned int *v1; // r10
  int v2; // r11
  int i; // ctr
  unsigned int v4; // r6

  v1 = &image->lopass_scanorder[14];
  v2 = 0;
  for ( i = 15; i != 0; --i )
  {
    *(v1 - 14) = ScanOrderHor[v2];
    v4 = ScanTotals[v2++];
    *++v1 = v4;
  }
}


// ========================================================================
// ?_jxr_InitializeAdaptiveScanHP@@YAXPAUjxr_image@@@Z
// EA  : 0x828FF6D0
// RVA : 0x008FF6D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_InitializeAdaptiveScanHP(jxr_image *image)
{
  unsigned int *v1; // r10
  int v2; // r11
  int i; // ctr
  unsigned int v4; // r8

  v1 = &image->hipass_ver_scanorder[14];
  v2 = 0;
  for ( i = 15; i != 0; --i )
  {
    *(v1 - 44) = ScanOrderHor[v2];
    *(v1 - 29) = ScanTotals[v2];
    *(v1 - 14) = ScanOrderVer[v2];
    v4 = ScanTotals[v2++];
    *++v1 = v4;
  }
}


// ========================================================================
// ?_jxr_InitializeCBPModel@@YAXPAUjxr_image@@@Z
// EA  : 0x828FF728
// RVA : 0x008FF728
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_InitializeCBPModel(jxr_image *image)
{
  int *v1; // r11
  int i; // ctr

  v1 = &image->hp_cbp_model.count0[15];
  for ( i = 16; i != 0; --i )
  {
    *(v1 - 31) = 0;
    *(v1 - 15) = -4;
    *++v1 = 4;
  }
}


// ========================================================================
// ?_jxr_InitHPVLC@@YAXPAUjxr_image@@@Z
// EA  : 0x828FF758
// RVA : 0x008FF758
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_InitHPVLC(jxr_image *image)
{
  image->vlc_table[16].deltatable = 0;
  image->vlc_table[16].table = 1;
  image->vlc_table[16].delta2table = 1;
  image->vlc_table[16].discriminant = 0;
  image->vlc_table[16].discriminant2 = 0;
  image->vlc_table[14].table = 1;
  image->vlc_table[14].deltatable = 0;
  image->vlc_table[14].delta2table = 1;
  image->vlc_table[14].discriminant = 0;
  image->vlc_table[14].discriminant2 = 0;
  image->vlc_table[15].table = 1;
  image->vlc_table[15].deltatable = 0;
  image->vlc_table[15].delta2table = 1;
  image->vlc_table[15].discriminant = 0;
  image->vlc_table[15].discriminant2 = 0;
  image->vlc_table[17].table = 1;
  image->vlc_table[17].deltatable = 0;
  image->vlc_table[17].delta2table = 1;
  image->vlc_table[17].discriminant = 0;
  image->vlc_table[17].discriminant2 = 0;
  image->vlc_table[18].table = 1;
  image->vlc_table[18].deltatable = 0;
  image->vlc_table[18].delta2table = 1;
  image->vlc_table[18].discriminant = 0;
  image->vlc_table[18].discriminant2 = 0;
  image->vlc_table[19].table = 1;
  image->vlc_table[19].deltatable = 0;
  image->vlc_table[19].delta2table = 1;
  image->vlc_table[19].discriminant = 0;
  image->vlc_table[19].discriminant2 = 0;
  image->vlc_table[5].table = 0;
  image->vlc_table[5].deltatable = 0;
  image->vlc_table[5].discriminant = 0;
  image->vlc_table[6].table = 0;
  image->vlc_table[6].deltatable = 0;
  image->vlc_table[6].discriminant = 0;
}


// ========================================================================
// ?_jxr_InitCBPVLC@@YAXPAUjxr_image@@@Z
// EA  : 0x828FF7F8
// RVA : 0x008FF7F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_InitCBPVLC(jxr_image *image)
{
  image->vlc_table[12].table = 0;
  image->vlc_table[12].deltatable = 0;
  image->vlc_table[12].discriminant = 0;
  image->vlc_table[13].table = 0;
  image->vlc_table[13].deltatable = 0;
  image->vlc_table[13].discriminant = 0;
}


// ========================================================================
// update_cbp_model
// EA  : 0x828FF818
// RVA : 0x008FF818
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall update_cbp_model(jxr_image *image, int channel, int norig)
{
  cbp_model_s *p_hp_cbp_model; // r11
  unsigned int v4; // r9
  int v5; // r10
  int v6; // r10
  int v7; // r8
  int v8; // r9
  int v9; // r10
  int v10; // r10
  bool v11; // zf
  int v12; // r9

  p_hp_cbp_model = &image->hp_cbp_model;
  v4 = channel + 16;
  v5 = image->hp_cbp_model.state[v4] + norig - 3;
  image->hp_cbp_model.state[v4] = v5;
  if ( v5 <= 15 )
  {
    if ( v5 < -16 )
      p_hp_cbp_model->state[v4] = -16;
  }
  else
  {
    p_hp_cbp_model->state[v4] = 15;
  }
  v6 = channel + 32;
  v7 = p_hp_cbp_model->state[v6] - norig + 13;
  p_hp_cbp_model->state[v6] = v7;
  if ( v7 <= 15 )
  {
    if ( v7 < -16 )
      p_hp_cbp_model->state[v6] = -16;
  }
  else
  {
    p_hp_cbp_model->state[v6] = 15;
  }
  v8 = p_hp_cbp_model->state[v4];
  v9 = p_hp_cbp_model->state[v6];
  if ( v8 >= 0 )
  {
    v12 = 2;
    if ( v9 >= 0 )
      v12 = 0;
    p_hp_cbp_model->state[channel] = v12;
  }
  else
  {
    v11 = v8 >= v9;
    v10 = channel;
    if ( v11 )
      p_hp_cbp_model->state[v10] = 2;
    else
      p_hp_cbp_model->state[v10] = 1;
  }
}


// ========================================================================
// ?_jxr_PredCBP444@@YAHPAUjxr_image@@PAHHIII@Z
// EA  : 0x828FF8E0
// RVA : 0x008FF8E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

int __fastcall _jxr_PredCBP444(
        jxr_image *image,
        int *diff_cbp,
        int channel,
        unsigned int tx,
        unsigned int mx,
        unsigned int my)
{
  int v7; // r31
  int v8; // r10
  int v9; // r10
  int v10; // r6
  int v11; // r9
  int v12; // r10
  int i; // r5

  v7 = diff_cbp[channel];
  v8 = image->hp_cbp_model.state[channel];
  if ( v8 != 0 )
  {
    if ( v8 == 2 )
      v7 ^= 0xFFFFu;
  }
  else
  {
    if ( mx != 0 )
    {
      v9 = (image->strip[channel].cur[image->tile_column_position[tx] - 1 + mx].hp_cbp >> 5) & 1 ^ v7;
    }
    else if ( my != 0 )
    {
      v9 = (image->strip[channel].up1[image->tile_column_position[tx]].hp_cbp >> 10) & 1 ^ v7;
    }
    else
    {
      v9 = v7 ^ 1;
    }
    v10 = (8 * ((2 * v9) & 2 ^ v9)) & 0x10 ^ (2 * v9) & 2 ^ v9;
    v11 = (4 * ((2 * (_BYTE)v10) & 0x20 ^ (unsigned __int8)v10)) & 0xCF ^ (2 * v10) & 0x20 ^ v10;
    v7 = (4 * (((_WORD)v11 << 6) & 0x3300 ^ (unsigned __int16)v11)) & 0xCC00 ^ ((_WORD)v11 << 6) & 0x3300 ^ v11;
  }
  v12 = v7;
  for ( i = 0; v12 > 0; v12 >>= 1 )
  {
    if ( (v12 & 1) != 0 )
      ++i;
  }
  update_cbp_model(image, channel, norig: i);
  return v7;
}


// ========================================================================
// ?_jxr_w_PredCBP444@@YAXPAUjxr_image@@HIIH@Z
// EA  : 0x828FFA28
// RVA : 0x008FFA28
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_w_PredCBP444(jxr_image *image, int channel, unsigned int tx, unsigned int mx, int my)
{
  unsigned int v5; // r9
  int v6; // r5
  macroblock_s *v7; // r8
  int hp_cbp; // r11
  int i; // r10
  int v10; // r10
  int v11; // r11
  int v12; // r10
  int v13; // r11

  v5 = image->tile_column_position[tx];
  v6 = 0;
  v7 = &image->strip[channel].up1[v5 + mx];
  hp_cbp = v7->hp_cbp;
  for ( i = hp_cbp; i > 0; i >>= 1 )
  {
    if ( (i & 1) != 0 )
      ++v6;
  }
  v10 = image->hp_cbp_model.state[channel];
  if ( v10 != 0 )
  {
    if ( v10 == 2 )
      hp_cbp ^= 0xFFFFu;
  }
  else
  {
    v11 = (4 * (_BYTE)hp_cbp)
        & 0xCF
        ^ (((4 * (_WORD)hp_cbp) & 0xCC00 ^ (unsigned __int16)hp_cbp) << 6)
        & 0x3300
        ^ (4 * (_WORD)hp_cbp)
        & 0xCC00
        ^ hp_cbp;
    v12 = (8 * ((2 * v11) & 0x20 ^ v11)) & 0x10 ^ (2 * v11) & 0x20 ^ v11;
    v13 = (2 * v12) & 2 ^ v12;
    if ( mx != 0 )
    {
      hp_cbp = (v7[-1].hp_cbp >> 5) & 1 ^ v13;
    }
    else if ( my != 0 )
    {
      hp_cbp = (image->strip[channel].cur[v5].hp_cbp >> 10) & 1 ^ v13;
    }
    else
    {
      hp_cbp = v13 ^ 1;
    }
  }
  v7->hp_diff_cbp = hp_cbp;
  update_cbp_model(image, channel, norig: v6);
}


// ========================================================================
// ?_jxr_PredCBP422@@YAHPAUjxr_image@@PAHHIII@Z
// EA  : 0x828FFB58
// RVA : 0x008FFB58
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

int __fastcall _jxr_PredCBP422(
        jxr_image *image,
        int *diff_cbp,
        int channel,
        unsigned int tx,
        unsigned int mx,
        unsigned int my)
{
  int v6; // r11
  int v7; // r31
  int v8; // r11
  int v9; // r4
  int v10; // r7
  int v11; // r11
  int i; // r10

  v6 = image->hp_cbp_model.state[1];
  v7 = diff_cbp[channel];
  if ( v6 == 0 )
  {
    if ( mx != 0 )
    {
      v9 = image->strip[channel].cur[image->tile_column_position[tx] - 1 + mx].hp_cbp >> 1;
    }
    else
    {
      if ( my == 0 )
      {
        v8 = v7 ^ 1;
LABEL_8:
        v10 = (4 * ((2 * v8) & 2 ^ v8)) & 0xC ^ (2 * v8) & 2 ^ v8;
        v7 = (4 * ((4 * v10) & 0x30 ^ v10)) & 0xC0 ^ (4 * v10) & 0x30 ^ v10;
        goto LABEL_11;
      }
      v9 = image->strip[channel].up1[image->tile_column_position[tx]].hp_cbp >> 6;
    }
    v8 = v9 & 1 ^ v7;
    goto LABEL_8;
  }
  if ( v6 == 2 )
    v7 ^= 0xFFu;
LABEL_11:
  v11 = v7;
  for ( i = 0; v11 > 0; v11 >>= 1 )
  {
    if ( (v11 & 1) != 0 )
      ++i;
  }
  update_cbp_model(image, channel: 1, norig: 2 * i);
  return v7;
}


// ========================================================================
// ?_jxr_w_PredCBP422@@YAXPAUjxr_image@@HIIH@Z
// EA  : 0x828FFC70
// RVA : 0x008FFC70
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_w_PredCBP422(jxr_image *image, int channel, unsigned int tx, unsigned int mx, int my)
{
  unsigned int v5; // r9
  int v6; // r8
  macroblock_s *v7; // r31
  int hp_cbp; // r11
  int i; // r10
  int v10; // r10
  int v11; // r11
  int v12; // r11

  v5 = image->tile_column_position[tx];
  v6 = 0;
  v7 = &image->strip[channel].up1[v5 + mx];
  hp_cbp = v7->hp_cbp;
  for ( i = hp_cbp; i > 0; i >>= 1 )
  {
    if ( (i & 1) != 0 )
      ++v6;
  }
  v10 = image->hp_cbp_model.state[1];
  if ( v10 != 0 )
  {
    if ( v10 == 2 )
      hp_cbp ^= 0xFFu;
  }
  else
  {
    v11 = (4 * ((4 * hp_cbp) & 0xC0 ^ hp_cbp)) & 0x30 ^ (4 * hp_cbp) & 0xC0 ^ hp_cbp;
    v12 = (2 * ((4 * v11) & 0xC ^ v11)) & 2 ^ (4 * v11) & 0xC ^ v11;
    if ( mx != 0 )
    {
      hp_cbp = (v7[-1].hp_cbp >> 1) & 1 ^ v12;
    }
    else if ( my != 0 )
    {
      hp_cbp = (image->strip[channel].cur[v5].hp_cbp >> 6) & 1 ^ v12;
    }
    else
    {
      hp_cbp = v12 ^ 1;
    }
  }
  v7->hp_diff_cbp = hp_cbp;
  update_cbp_model(image, channel: 1, norig: 2 * v6);
}


// ========================================================================
// ?_jxr_PredCBP420@@YAHPAUjxr_image@@PAHHIII@Z
// EA  : 0x828FFD80
// RVA : 0x008FFD80
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

int __fastcall _jxr_PredCBP420(
        jxr_image *image,
        int *diff_cbp,
        int channel,
        unsigned int tx,
        unsigned int mx,
        unsigned int my)
{
  int v6; // r11
  int v7; // r31
  int v8; // r9
  int v9; // r4
  int v10; // r9
  int v11; // r11
  int i; // r10

  v6 = image->hp_cbp_model.state[1];
  v7 = diff_cbp[channel];
  if ( v6 != 0 )
  {
    if ( v6 == 2 )
      v7 ^= 0xFu;
  }
  else
  {
    if ( mx != 0 )
    {
      v9 = image->strip[channel].cur[image->tile_column_position[tx] - 1 + mx].hp_cbp >> 1;
    }
    else
    {
      if ( my == 0 )
      {
        v8 = (2 * (v7 ^ 1)) & 2 ^ v7 ^ 1;
        v7 = (4 * v8) & 0xC ^ v8;
        goto LABEL_10;
      }
      v9 = image->strip[channel].up1[image->tile_column_position[tx]].hp_cbp >> 2;
    }
    v10 = (2 * (v9 & 1 ^ v7)) & 2 ^ v9 & 1 ^ v7;
    v7 = (4 * v10) & 0xC ^ v10;
  }
LABEL_10:
  v11 = v7;
  for ( i = 0; v11 > 0; v11 >>= 1 )
  {
    if ( (v11 & 1) != 0 )
      ++i;
  }
  update_cbp_model(image, channel: 1, norig: 4 * i);
  return v7;
}


// ========================================================================
// ?_jxr_w_PredCBP420@@YAXPAUjxr_image@@HIIH@Z
// EA  : 0x828FFE98
// RVA : 0x008FFE98
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_w_PredCBP420(jxr_image *image, int channel, unsigned int tx, unsigned int mx, int my)
{
  unsigned int v5; // r9
  int v6; // r8
  macroblock_s *v7; // r31
  int hp_cbp; // r11
  int i; // r10
  int v10; // r10
  int v11; // r11

  v5 = image->tile_column_position[tx];
  v6 = 0;
  v7 = &image->strip[channel].up1[v5 + mx];
  hp_cbp = v7->hp_cbp;
  for ( i = hp_cbp; i > 0; i >>= 1 )
  {
    if ( (i & 1) != 0 )
      ++v6;
  }
  v10 = image->hp_cbp_model.state[1];
  if ( v10 != 0 )
  {
    if ( v10 == 2 )
      hp_cbp ^= 0xFu;
  }
  else
  {
    v11 = (2 * ((4 * hp_cbp) & 0xC ^ hp_cbp)) & 2 ^ (4 * hp_cbp) & 0xC ^ hp_cbp;
    if ( mx != 0 )
    {
      hp_cbp = (v7[-1].hp_cbp >> 1) & 1 ^ v11;
    }
    else if ( my != 0 )
    {
      hp_cbp = (image->strip[channel].cur[v5].hp_cbp >> 2) & 1 ^ v11;
    }
    else
    {
      hp_cbp = v11 ^ 1;
    }
  }
  v7->hp_diff_cbp = hp_cbp;
  update_cbp_model(image, channel: 1, norig: 4 * v6);
}


// ========================================================================
// ?_jxr_ResetTotalsAdaptiveScanLP@@YAXPAUjxr_image@@@Z
// EA  : 0x828FFF98
// RVA : 0x008FFF98
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_ResetTotalsAdaptiveScanLP(jxr_image *image)
{
  unsigned int *v1; // r10
  const int *v2; // r11
  int i; // ctr

  v1 = &image->lopass_scanorder[14];
  v2 = &_jxr_hp_scan_map[15];
  for ( i = 15; i != 0; --i )
    *++v1 = *++v2;
}


// ========================================================================
// ?_jxr_ResetTotalsAdaptiveScanHP@@YAXPAUjxr_image@@@Z
// EA  : 0x828FFFC0
// RVA : 0x008FFFC0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_ResetTotalsAdaptiveScanHP(jxr_image *image)
{
  unsigned int *v1; // r10
  const int *v2; // r11
  int i; // ctr

  v1 = &image->hipass_ver_scanorder[14];
  v2 = &_jxr_hp_scan_map[15];
  for ( i = 15; i != 0; --i )
  {
    *(v1 - 29) = v2[1];
    *++v1 = *++v2;
  }
}


// ========================================================================
// calculate_mbdc_mode
// EA  : 0x828FFFF0
// RVA : 0x008FFFF0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

int __fastcall calculate_mbdc_mode(jxr_image *image, int tx, int mx, int my)
{
  int use_clr_fmt; // r7
  int v6; // r9
  macroblock_s *v7; // r10
  int v8; // r30
  int v9; // r29
  int v10; // r6
  int v11; // r10
  int v12; // r11
  macroblock_s *v13; // r9
  macroblock_s *v14; // r8
  macroblock_s *v15; // r4
  int *data; // r28
  int *v17; // r3
  int *v18; // r11
  int *v19; // r9
  int *v20; // r31
  int v21; // r8
  int v22; // r11
  int v23; // r3
  int v24; // r9
  int v25; // r3
  unsigned int v26; // r9
  signed int v27; // r11

  if ( mx == 0 )
    return my == 0 ? 3 : 1;
  if ( my == 0 )
    return 0;
  use_clr_fmt = image->use_clr_fmt;
  v6 = image->tile_column_position[tx] + mx;
  v7 = &image->strip[0].up1[v6];
  v8 = *v7->data;
  v9 = *image->strip[0].cur[v6 - 1].data;
  v10 = *v7[-1].data;
  if ( image->use_clr_fmt == 0 || use_clr_fmt == 6 )
  {
    v26 = abs32(v10 - v9);
    v27 = abs32(v10 - v8);
  }
  else
  {
    v11 = 2;
    v12 = image->tile_column_position[tx] + mx;
    v13 = &image->strip[1].up1[v12];
    v14 = &image->strip[2].up1[v12];
    v15 = &image->strip[1].cur[v12];
    data = image->strip[2].cur[v12 - 1].data;
    v17 = v13->data;
    v18 = v13[-1].data;
    v19 = v14->data;
    v20 = v14[-1].data;
    v21 = *v17;
    v22 = *v18;
    v23 = *v19;
    v24 = *v20;
    if ( use_clr_fmt == 2 )
    {
      v11 = 4;
    }
    else if ( use_clr_fmt == 1 )
    {
      v11 = 8;
    }
    v25 = v24 - v23;
    v26 = abs32(v10 - v9) * v11 + abs32(v24 - *data) + abs32(v22 - *v15[-1].data);
    v27 = abs32(v10 - v8) * v11 + abs32(v25) + abs32(v22 - v21);
  }
  if ( (int)(4 * v26) >= v27 )
    return __CFADD__(4 * v27 - v26, v26 ^ 0x80000000) ? 0 : 2;
  else
    return 1;
}


// ========================================================================
// predict_lp444
// EA  : 0x829001C8
// RVA : 0x009001C8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall predict_lp444(jxr_image *image, int tx, int mx, int my, int ch, int mblp_mode)
{
  char *v6; // r11
  int v7; // r9
  unsigned int v8; // r10
  unsigned int v9; // r10
  int v10; // r10
  int v11; // r9
  unsigned int v12; // r11
  int v13; // r10
  unsigned int v14; // r11
  unsigned int v15; // r11
  unsigned int v16; // r11
  int v17; // r11
  _DWORD *v18; // r10
  _DWORD *v19; // r10
  _DWORD *v20; // r10
  _DWORD *v21; // r10
  _DWORD *v22; // r10
  _DWORD *v23; // r11

  if ( ch != 0 )
  {
    if ( ch == 1 )
    {
      v6 = (char *)image + 28 * my;
      v7 = 28 * (my + 5);
      v8 = 84 * (image->tile_column_position[tx] + mx);
      *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&image->user_flags + v7) + v8) + 4) += *(_DWORD *)(*(_DWORD *)(v8 + *((_DWORD *)v6 + 34) + 4)
                                                                                                + 4);
      v9 = 84 * (image->tile_column_position[tx] + mx);
      *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&image->user_flags + v7) + v9) + 8) += *(_DWORD *)(*(_DWORD *)(v9 + *((_DWORD *)v6 + 34) + 4)
                                                                                                + 8);
      v10 = *(int *)((char *)&image->user_flags + v7);
      v11 = *((_DWORD *)v6 + 34);
      v12 = 84 * (image->tile_column_position[tx] + mx);
      *(_DWORD *)(*(_DWORD *)(v10 + v12) + 12) += *(_DWORD *)(*(_DWORD *)(v12 + v11 + 4) + 12);
    }
  }
  else
  {
    v13 = 28 * (my + 5);
    v14 = 84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v13);
    *(_DWORD *)(*(_DWORD *)v14 + 16) += *(_DWORD *)(*(_DWORD *)(v14 - 80) + 16);
    v15 = 84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v13);
    *(_DWORD *)(*(_DWORD *)v15 + 32) += *(_DWORD *)(*(_DWORD *)(v15 - 80) + 20);
    v16 = 84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v13);
    *(_DWORD *)(*(_DWORD *)v16 + 48) += *(_DWORD *)(*(_DWORD *)(v16 - 80) + 24);
  }
  v17 = 28 * (my + 5);
  v18 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v17));
  *(_DWORD *)(v18[1] + 4) = *(_DWORD *)(*v18 + 4);
  v19 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v17));
  *(_DWORD *)(v19[1] + 8) = *(_DWORD *)(*v19 + 8);
  v20 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v17));
  *(_DWORD *)(v20[1] + 12) = *(_DWORD *)(*v20 + 12);
  v21 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v17));
  *(_DWORD *)(v21[1] + 16) = *(_DWORD *)(*v21 + 16);
  v22 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v17));
  *(_DWORD *)(v22[1] + 20) = *(_DWORD *)(*v22 + 32);
  v23 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v17));
  *(_DWORD *)(v23[1] + 24) = *(_DWORD *)(*v23 + 48);
}


// ========================================================================
// predict_lp422
// EA  : 0x82900448
// RVA : 0x00900448
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall predict_lp422(jxr_image *image, int tx, int mx, int my, unsigned int ch, int mblp_mode, int mbdc_mode)
{
  int *data; // r8
  char *v8; // r11
  int v9; // r9
  unsigned int v10; // r10
  int v11; // r8
  unsigned int v12; // r11
  int v13; // r8
  int v14; // r10
  unsigned int v15; // r11
  unsigned int v16; // r11
  unsigned int v17; // r11
  int v18; // r11
  _DWORD *v19; // r10
  _DWORD *v20; // r10
  _DWORD *v21; // r10
  _DWORD *v22; // r10
  _DWORD *v23; // r11

  if ( ch != 0 )
  {
    if ( ch == 1 )
    {
      v8 = (char *)image + 28 * my;
      v9 = 28 * (my + 5);
      v10 = 84 * (image->tile_column_position[tx] + mx);
      *(_DWORD *)(*(_DWORD *)(v10 + *(int *)((char *)&image->user_flags + v9)) + 16) += *(_DWORD *)(*(_DWORD *)(v10 + *((_DWORD *)v8 + 34) + 4)
                                                                                                  + 16);
      v11 = *((_DWORD *)v8 + 34);
      v12 = 84 * (image->tile_column_position[tx] + mx);
      *(_DWORD *)(*(_DWORD *)(v12 + *(int *)((char *)&image->user_flags + v9)) + 4) += *(_DWORD *)(*(_DWORD *)(v12 + v11 + 4)
                                                                                                 + 20);
      v13 = *(_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v9));
      *(_DWORD *)(v13 + 20) += *(_DWORD *)(v13 + 4);
    }
    else if ( ch < 3 && mblp_mode == 1 )
    {
      data = image->strip[my].cur[image->tile_column_position[tx] + mx].data;
      data[5] += data[1];
    }
  }
  else
  {
    v14 = 28 * (my + 5);
    v15 = 84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v14);
    *(_DWORD *)(*(_DWORD *)v15 + 16) += *(_DWORD *)(*(_DWORD *)(v15 - 80) + 16);
    v16 = 84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v14);
    *(_DWORD *)(*(_DWORD *)v16 + 8) += *(_DWORD *)(*(_DWORD *)(v16 - 80) + 8);
    v17 = 84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v14);
    *(_DWORD *)(*(_DWORD *)v17 + 24) += *(_DWORD *)(*(_DWORD *)(v17 - 80) + 24);
  }
  v18 = 28 * (my + 5);
  v19 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v18));
  *(_DWORD *)(v19[1] + 4) = *(_DWORD *)(*v19 + 4);
  v20 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v18));
  *(_DWORD *)(v20[1] + 8) = *(_DWORD *)(*v20 + 8);
  v21 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v18));
  *(_DWORD *)(v21[1] + 16) = *(_DWORD *)(*v21 + 16);
  v22 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v18));
  *(_DWORD *)(v22[1] + 20) = *(_DWORD *)(*v22 + 20);
  v23 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v18));
  *(_DWORD *)(v23[1] + 24) = *(_DWORD *)(*v23 + 24);
}


// ========================================================================
// predict_lp420
// EA  : 0x829006E0
// RVA : 0x009006E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall predict_lp420(jxr_image *image, int tx, int mx, int my, int ch, int mblp_mode)
{
  int v6; // r11
  macroblock_s *v7; // r11
  int v8; // r10
  _DWORD *v9; // r11
  _DWORD *v10; // r11

  if ( ch != 0 )
  {
    if ( ch == 1 )
    {
      v6 = image->tile_column_position[tx] + mx;
      image->strip[my].cur[v6].data[1] += image->strip[my].up1[v6].pred_dclp[1];
    }
  }
  else
  {
    v7 = &image->strip[my].cur[image->tile_column_position[tx] + mx];
    v7->data[2] += v7[-1].pred_dclp[2];
  }
  v8 = 28 * (my + 5);
  v9 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v8));
  *(_DWORD *)(v9[1] + 4) = *(_DWORD *)(*v9 + 4);
  v10 = (_DWORD *)(84 * (image->tile_column_position[tx] + mx) + *(int *)((char *)&image->user_flags + v8));
  *(_DWORD *)(v10[1] + 8) = *(_DWORD *)(*v10 + 8);
}


// ========================================================================
// _InvT_odd
// EA  : 0x829007E0
// RVA : 0x009007E0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall InvT_odd(int *a, int *b, int *c, int *d)
{
  int v4; // r11
  int v5; // r11

  *b += *d;
  *a -= *c;
  *d -= *b >> 1;
  *c += (*a + 1) >> 1;
  v4 = *a - ((3 * *b + 4) >> 3);
  *a = v4;
  *b += (3 * v4 + 4) >> 3;
  v5 = *c - ((3 * *d + 4) >> 3);
  *c = v5;
  *d += (3 * v5 + 4) >> 3;
  *c -= (*b + 1) >> 1;
  *d = ((*a + 1) >> 1) - *d;
  *b += *c;
  *a -= *d;
}


// ========================================================================
// _T_odd
// EA  : 0x829008F8
// RVA : 0x009008F8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall T_odd(int *a, int *b, int *c, int *d)
{
  int v4; // r11
  int v5; // r11

  *b -= *c;
  *a += *d;
  *c += (*b + 1) >> 1;
  *d = ((*a + 1) >> 1) - *d;
  v4 = *b - ((3 * *a + 4) >> 3);
  *b = v4;
  *a += (3 * v4 + 4) >> 3;
  v5 = *d - ((3 * *c + 4) >> 3);
  *d = v5;
  *c += (3 * v5 + 4) >> 3;
  *d += *b >> 1;
  *c -= (*a + 1) >> 1;
  *b -= *d;
  *a += *c;
}


// ========================================================================
// ?_jxr_InvPermute2pt@@YAXPAH0@Z
// EA  : 0x82900A10
// RVA : 0x00900A10
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_InvPermute2pt(int *a, int *b)
{
  int v2; // r10

  v2 = *a;
  *a = *b;
  *b = v2;
}


// ========================================================================
// ?_jxr_2ptT@@YAXPAH0@Z
// EA  : 0x82900A28
// RVA : 0x00900A28
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_2ptT(int *a, int *b)
{
  int v2; // r11

  v2 = *a - ((*b + 1) >> 1);
  *a = v2;
  *b += v2;
}


// ========================================================================
// ?_jxr_2ptFwdT@@YAXPAH0@Z
// EA  : 0x82900A50
// RVA : 0x00900A50
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_2ptFwdT(int *a, int *b)
{
  int v2; // r11

  v2 = *b - *a;
  *b = v2;
  *a += (v2 + 1) >> 1;
}


// ========================================================================
// ?_jxr_2x2IPCT@@YAXPAH@Z
// EA  : 0x82900A78
// RVA : 0x00900A78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_2x2IPCT(int *coeff)
{
  int v1; // r8
  int v2; // r4
  int v3; // r9

  *coeff += coeff[3];
  v1 = coeff[1] - coeff[2];
  coeff[1] = v1;
  v2 = *coeff - v1;
  v3 = (v2 >> 1) - coeff[2];
  coeff[2] = (v2 >> 1) - coeff[3];
  coeff[3] = v3;
  *coeff -= v3;
  coeff[1] += coeff[2];
}


// ========================================================================
// ?_jxr_4x4IPCT@@YAXPAH@Z
// EA  : 0x82900AE0
// RVA : 0x00900AE0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_4x4IPCT(int *coeff)
{
  int *v1; // r30
  int v3; // ctr
  const unsigned int *v4; // r10
  int *v5; // r11
  unsigned int v6; // r5
  int v7; // r28
  int v8; // r9
  int v9; // r29
  int v10; // r26
  int v11; // r24
  int v12; // r27
  int v13; // r23
  _DWORD *v14; // r11
  int *v15; // r10
  int i; // ctr
  int v17; // r8
  int v18; // r8
  int v19; // r11
  int v20; // r4
  int v21; // r10
  int v22; // r11
  int v23; // r8
  int v24; // r11
  int v25; // r10
  int v26; // r11
  int v27; // r4
  int v28; // r6
  int v29; // r11
  int v30; // r9
  int v31; // r11
  int v32; // r11
  int v33; // r5
  int v34; // r7
  int v35; // r4
  int v36; // r3
  _BYTE v37[148]; // [sp+4Ch] [-94h] BYREF

  v1 = coeff + 2;
  v3 = 4;
  v4 = &ScanOrderVer[12];
  v5 = coeff + 2;
  do
  {
    v6 = v4[3];
    v4 += 4;
    v7 = *(v5 - 2);
    v8 = 4 * *v4;
    v9 = 4 * *(int *)((char *)v5 + &unk_82236C30 - (_UNKNOWN *)coeff);
    v10 = *(v5 - 1);
    v11 = *v5;
    v12 = 4 * *(int *)((char *)v5 + &unk_82236C34 - (_UNKNOWN *)coeff);
    v13 = v5[1];
    v5 += 4;
    *(_DWORD *)&v37[4 * v6 + 4] = v7;
    *(_DWORD *)&v37[v8 + 4] = v10;
    *(_DWORD *)&v37[v9 + 4] = v11;
    *(_DWORD *)&v37[v12 + 4] = v13;
    --v3;
  }
  while ( v3 != 0 );
  v14 = v37;
  v15 = coeff - 1;
  for ( i = 16; i != 0; --i )
    *++v15 = *++v14;
  *coeff += coeff[5];
  v17 = coeff[1] - coeff[4];
  coeff[1] = v17;
  v18 = *coeff - v17 + 1;
  v19 = (v18 >> 1) - coeff[4];
  coeff[4] = (v18 >> 1) - coeff[5];
  coeff[5] = v19;
  *coeff -= v19;
  coeff[1] += coeff[4];
  InvT_odd(a: coeff + 2, b: coeff + 3, c: coeff + 6, d: coeff + 7);
  InvT_odd(a: coeff + 8, b: coeff + 12, c: coeff + 9, d: coeff + 13);
  coeff[15] += coeff[10];
  v20 = coeff[14] - coeff[11];
  coeff[14] = v20;
  v21 = coeff[15] >> 1;
  coeff[10] -= v21;
  v22 = coeff[11] + (v20 >> 1);
  coeff[11] = v22;
  v23 = coeff[10] - ((3 * (v22 + 1)) >> 3);
  coeff[10] = v23;
  v24 = ((3 * (v23 + 1)) >> 2) + coeff[11];
  coeff[11] = v24;
  coeff[10] -= (3 * v24 + 4) >> 3;
  coeff[11] -= v20 >> 1;
  coeff[10] += v21;
  coeff[14] += coeff[11];
  coeff[15] -= coeff[10];
  coeff[11] = -coeff[11];
  coeff[14] = -coeff[14];
  *coeff += coeff[15];
  v25 = coeff[3] - coeff[12];
  coeff[3] = v25;
  v26 = (*coeff - v25) >> 1;
  v27 = v26 - coeff[12];
  coeff[12] = v26 - coeff[15];
  coeff[15] = v27;
  *coeff -= v27;
  coeff[3] += coeff[12];
  coeff[5] += coeff[10];
  v28 = coeff[6] - coeff[9];
  coeff[6] = v28;
  v29 = (coeff[5] - v28) >> 1;
  v30 = v29 - coeff[9];
  coeff[9] = v29 - coeff[10];
  coeff[10] = v30;
  coeff[5] -= v30;
  coeff[6] += coeff[9];
  coeff[1] += coeff[14];
  v31 = *v1 - coeff[13];
  *v1 = v31;
  v32 = (coeff[1] - v31) >> 1;
  v33 = v32 - coeff[13];
  coeff[13] = v32 - coeff[14];
  coeff[14] = v33;
  coeff[1] -= v33;
  *v1 += coeff[13];
  coeff[4] += coeff[11];
  v34 = coeff[7] - coeff[8];
  coeff[7] = v34;
  v35 = coeff[4] - v34;
  v36 = coeff[8];
  coeff[8] = (v35 >> 1) - coeff[11];
  coeff[11] = (v35 >> 1) - v36;
  coeff[4] -= (v35 >> 1) - v36;
  coeff[7] += coeff[8];
}


// ========================================================================
// ?_jxr_4x4PCT@@YAXPAH@Z
// EA  : 0x82900E88
// RVA : 0x00900E88
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_4x4PCT(int *coeff)
{
  int *v2; // r5
  int *v3; // r29
  int *v4; // r4
  int *v5; // r28
  int *v6; // r27
  int v7; // r8
  int *v8; // r30
  int *v9; // r6
  int v10; // r10
  int v11; // r8
  int v12; // r7
  int v13; // r11
  int v14; // r7
  int v15; // r3
  int v16; // r11
  int v17; // r11
  int v18; // r3
  int v19; // r11
  int v20; // r9
  int v21; // r11
  int v22; // r8
  int v23; // r11
  int v24; // r7
  int v25; // r8
  int v26; // r8
  int v27; // r9
  int v28; // r11
  _DWORD *v29; // r5
  int v30; // r11
  int v31; // ctr
  int v32; // r10
  int v33; // r10
  int v34; // r29
  int v35; // r11
  int v36; // r7
  int v37; // r27
  int v38; // r25
  int v39; // r28
  int v40; // r24
  _DWORD *v41; // r11
  int *v42; // r10
  int i; // ctr
  _BYTE v44[148]; // [sp+4Ch] [-94h] BYREF

  v2 = coeff + 6;
  v3 = coeff + 12;
  v4 = coeff + 3;
  *coeff += coeff[15];
  v5 = coeff + 9;
  v6 = coeff + 13;
  v7 = coeff[3] - coeff[12];
  coeff[3] = v7;
  v8 = coeff + 2;
  v9 = coeff + 7;
  v10 = *coeff - v7;
  v11 = (v10 >> 1) - coeff[12];
  coeff[12] = (v10 >> 1) - coeff[15];
  coeff[15] = v11;
  *coeff -= v11;
  coeff[3] += coeff[12];
  coeff[5] += coeff[10];
  v12 = coeff[6] - coeff[9];
  coeff[6] = v12;
  v13 = (coeff[5] - v12) >> 1;
  v14 = v13 - coeff[10];
  v15 = v13 - coeff[9];
  coeff[9] = v14;
  coeff[10] = v15;
  coeff[5] -= v15;
  coeff[6] += coeff[9];
  coeff[1] += coeff[14];
  v16 = coeff[2] - coeff[13];
  coeff[2] = v16;
  v17 = (coeff[1] - v16) >> 1;
  v18 = v17 - coeff[14];
  v19 = v17 - coeff[13];
  coeff[13] = v18;
  coeff[14] = v19;
  coeff[1] -= v19;
  coeff[2] += coeff[13];
  coeff[4] += coeff[11];
  v20 = coeff[7] - coeff[8];
  coeff[7] = v20;
  v21 = (coeff[4] - v20) >> 1;
  v22 = v21 - coeff[8];
  coeff[8] = v21 - coeff[11];
  coeff[11] = v22;
  coeff[4] -= v22;
  coeff[7] += coeff[8];
  *coeff += coeff[5];
  v23 = coeff[1] - coeff[4];
  coeff[1] = v23;
  v24 = *coeff - v23 + 1;
  v25 = (v24 >> 1) - coeff[4];
  coeff[4] = (v24 >> 1) - coeff[5];
  coeff[5] = v25;
  *coeff -= v25;
  coeff[1] += coeff[4];
  T_odd(a: v8, b: v4, c: v2, d: v9);
  T_odd(a: coeff + 8, b: v3, c: v5, d: v6);
  coeff[11] = -coeff[11];
  coeff[14] = -coeff[14];
  coeff[15] += coeff[10];
  v26 = coeff[14] - coeff[11];
  coeff[14] = v26;
  v27 = coeff[15] >> 1;
  v26 >>= 1;
  coeff[10] -= v27;
  v28 = coeff[11] + v26;
  coeff[11] = v28;
  v29 = &unk_82236C64;
  v30 = ((3 * v28 + 4) >> 3) + coeff[10];
  coeff[10] = v30;
  v31 = 4;
  v32 = coeff[11] - ((3 * (v30 + 1)) >> 2);
  coeff[11] = v32;
  coeff[10] += (3 * (v32 + 1)) >> 3;
  coeff[11] -= v26;
  coeff[10] += v27;
  coeff[14] += coeff[11];
  coeff[15] -= coeff[10];
  do
  {
    v33 = v29[3];
    v29 += 4;
    v34 = *(v8 - 2);
    v35 = 4 * *v29;
    v36 = 4 * *(int *)((char *)v8 + &unk_82236C70 - (_UNKNOWN *)coeff);
    v37 = *(v8 - 1);
    v38 = *v8;
    v39 = 4 * *(int *)((char *)v8 + &unk_82236C74 - (_UNKNOWN *)coeff);
    v40 = v8[1];
    v8 += 4;
    *(_DWORD *)&v44[4 * v33 + 4] = v34;
    *(_DWORD *)&v44[v35 + 4] = v37;
    *(_DWORD *)&v44[v36 + 4] = v38;
    *(_DWORD *)&v44[v39 + 4] = v40;
    --v31;
  }
  while ( v31 != 0 );
  v41 = v44;
  v42 = coeff - 1;
  for ( i = 16; i != 0; --i )
    *++v42 = *++v41;
}


// ========================================================================
// ?_jxr_4x4OverlapFilter@@YAXPAH000000000000000@Z
// EA  : 0x82901240
// RVA : 0x00901240
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_4x4OverlapFilter(
        int *a,
        int *b,
        int *c,
        int *d,
        int *e,
        int *f,
        int *g,
        int *h,
        int *i,
        int *j,
        int *k,
        int *l,
        int *m,
        int *n,
        int *o,
        int *p,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int *a28,
        int a29,
        int *a30,
        int a31,
        int *a32,
        int a33,
        int *a34,
        int a35,
        int *ia,
        int a37,
        int *ja,
        int a39,
        int *ka,
        int a41,
        int *la)
{
  int v47; // r3
  int v48; // r4
  int v49; // r3
  int v50; // r4
  int v51; // r3
  int v52; // r4
  int v53; // r3
  int v54; // r4
  int v55; // r3
  int v56; // r4
  int v57; // r3
  int v58; // r4
  int v59; // r3
  int v60; // r3
  int v61; // r31
  int v62; // r3
  int v63; // r3
  int v64; // r3
  int v65; // r3
  int v66; // r3
  int v67; // r3
  int v68; // r31
  int v69; // r30
  int v70; // r3
  int v71; // r3
  int v72; // r3
  int v73; // r3
  int v74; // r3
  int v75; // r3
  int v76; // r3
  int v77; // r3
  int v78; // r3
  int v79; // r3
  int v80; // r3
  int v81; // r3
  int v82; // r3
  int v83; // r3
  int v84; // r3
  int v85; // r3
  int v86; // r3
  int v87; // r31
  int v88; // r30
  int v89; // r9
  int v90; // r7
  int v91; // r8
  int v92; // r7
  int v93; // r5
  int v94; // r8
  int v95; // r7

  *a += *la;
  v47 = *d - *ia;
  *d = v47;
  v48 = (*a - v47) >> 1;
  v49 = v48 - *la;
  v50 = v48 - *ia;
  *ia = v49;
  *la = v50;
  *a -= v50;
  *d += *ia;
  *b += *ka;
  v51 = *c - *ja;
  *c = v51;
  v52 = (*b - v51) >> 1;
  v53 = v52 - *ka;
  v54 = v52 - *ja;
  *ja = v53;
  *ka = v54;
  *b -= v54;
  *c += *ja;
  *e += *a34;
  v55 = *h - *a28;
  *h = v55;
  v56 = (*e - v55) >> 1;
  v57 = v56 - *a34;
  v58 = v56 - *a28;
  *a28 = v57;
  *a34 = v58;
  *e -= v58;
  *h += *a28;
  *f += *a32;
  v59 = *g - *a30;
  *g = v59;
  v60 = (*f - v59) >> 1;
  v61 = v60 - *a32;
  v62 = v60 - *a30;
  *a30 = v61;
  *a32 = v62;
  *f -= v62;
  *g += *a30;
  v63 = *ja - ((*ia + 1) >> 1);
  *ja = v63;
  *ia += (v63 + 1) >> 1;
  v64 = *a30 - ((*a28 + 1) >> 1);
  *a30 = v64;
  *a28 += (v64 + 1) >> 1;
  v65 = *h - ((*d + 1) >> 1);
  *h = v65;
  *d += (v65 + 1) >> 1;
  v66 = *g - ((*c + 1) >> 1);
  *g = v66;
  *c += (v66 + 1) >> 1;
  *la += *a32;
  v67 = *ka - *a34;
  *ka = v67;
  v68 = *la >> 1;
  v69 = v67 >> 1;
  *a32 -= v68;
  v70 = *a34 + (v67 >> 1);
  *a34 = v70;
  v71 = *a32 - ((3 * (v70 + 2)) >> 3);
  *a32 = v71;
  v72 = ((3 * v71 + 2) >> 2) + *a34;
  *a34 = v72;
  *a32 -= (3 * v72 + 4) >> 3;
  *a34 -= v69;
  *a32 += v68;
  *ka += *a34;
  v73 = *la - *a32;
  *la = v73;
  v74 = v73 + *a;
  *a = v74;
  v75 = (v74 >> 1) - *la;
  *la = v75;
  v76 = ((3 * v75 + 8) >> 4) + *a;
  *a = v76;
  *la += (3 * v76 + 4) >> 5;
  v77 = *b + *ka;
  *b = v77;
  v78 = (v77 >> 1) - *ka;
  *ka = v78;
  v79 = ((3 * v78 + 8) >> 4) + *b;
  *b = v79;
  *ka += (3 * v79 + 4) >> 5;
  v80 = *a34 + *e;
  *e = v80;
  v81 = (v80 >> 1) - *a34;
  *a34 = v81;
  v82 = ((3 * v81 + 8) >> 4) + *e;
  *e = v82;
  *a34 += (3 * v82 + 4) >> 5;
  v83 = *a32 + *f;
  *f = v83;
  v84 = (v83 >> 1) - *a32;
  *a32 = v84;
  v85 = ((3 * v84 + 8) >> 4) + *f;
  *f = v85;
  *a32 += (3 * v85 + 4) >> 5;
  *d -= *ia;
  *a += (3 * *la + 8) >> 4;
  v86 = *la - (*d >> 1);
  *la = v86;
  v87 = (*a - *d) >> 1;
  v88 = *ia;
  *ia = v86;
  *la = v87 - v88;
  *a -= *la;
  *d += *ia;
  *c -= *ja;
  *b += (3 * *ka + 8) >> 4;
  *ka -= *c >> 1;
  v89 = (*b - *c) >> 1;
  v90 = *ja;
  *ja = *ka;
  *ka = v89 - v90;
  *b -= v89 - v90;
  *c += *ja;
  *h -= *a28;
  *e += (3 * *a34 + 8) >> 4;
  *a34 -= *h >> 1;
  v91 = *a28;
  v92 = (*e - *h) >> 1;
  *a28 = *a34;
  *a34 = v92 - v91;
  *e -= v92 - v91;
  *h += *a28;
  *g -= *a30;
  *f += (3 * *a32 + 8) >> 4;
  v93 = *a32 - (*g >> 1);
  *a32 = v93;
  v94 = *a30;
  v95 = *f - *g;
  *a30 = v93;
  *a32 = (v95 >> 1) - v94;
  *f -= (v95 >> 1) - v94;
  *g += *a30;
}


// ========================================================================
// ?_jxr_4OverlapFilter@@YAXPAH000@Z
// EA  : 0x82901908
// RVA : 0x00901908
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_4OverlapFilter(int *a, int *b, int *c, int *d)
{
  int v4; // r7
  int v5; // r11
  int v6; // r11

  *a += *d;
  *b += *c;
  *d -= (*a + 1) >> 1;
  v4 = *c - ((*b + 1) >> 1);
  *c = v4;
  v5 = v4 - ((*d + 1) >> 1);
  *c = v5;
  v6 = ((v5 + 1) >> 1) + *d;
  *d = v6;
  *d = ((*a + 1) >> 1) + v6;
  *c += (*b + 1) >> 1;
  *a += ((3 * *d + 16) >> 5) - *d;
  *b += ((3 * *c + 16) >> 5) - *c;
  *d += (3 * *a + 8) >> 4;
  *c += (3 * *b + 8) >> 4;
  *a += (3 * *d + 16) >> 5;
  *b += (3 * *c + 16) >> 5;
}


// ========================================================================
// ?_jxr_2x2OverlapFilter@@YAXPAH000@Z
// EA  : 0x82901A78
// RVA : 0x00901A78
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_2x2OverlapFilter(int *a, int *b, int *c, int *d)
{
  int v4; // r11
  int v5; // r11

  *a += *d;
  *b += *c;
  *d -= (*a + 1) >> 1;
  *c -= (*b + 1) >> 1;
  v4 = ((*a + 2) >> 2) + *b;
  *b = v4;
  v5 = ((v4 + 1) >> 1) + *a;
  *a = v5;
  *b += (v5 + 2) >> 2;
  *d += (*a + 1) >> 1;
  *c += (*b + 1) >> 1;
  *a -= *d;
  *b -= *c;
}


// ========================================================================
// ?_jxr_2OverlapFilter@@YAXPAH0@Z
// EA  : 0x82901B60
// RVA : 0x00901B60
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_2OverlapFilter(int *a, int *b)
{
  int v2; // r11
  int v3; // r11

  v2 = ((*a + 4) >> 3) + *b;
  *b = v2;
  v3 = ((v2 + 2) >> 2) + *a;
  *a = v3;
  *b += (v3 + 4) >> 3;
}


// ========================================================================
// ?_jxr_4x4PreFilter@@YAXPAH000000000000000@Z
// EA  : 0x82901BA8
// RVA : 0x00901BA8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_4x4PreFilter(
        int *a,
        int *b,
        int *c,
        int *d,
        int *e,
        int *f,
        int *g,
        int *h,
        int *i,
        int *j,
        int *k,
        int *l,
        int *m,
        int *n,
        int *o,
        int *p,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int *a28,
        int a29,
        int *a30,
        int a31,
        _DWORD *a32,
        int a33,
        _DWORD *a34,
        int a35,
        int *ia,
        int a37,
        int *ja,
        int a39,
        int *ka,
        int a41,
        int *la)
{
  int v44; // r11
  int v45; // r11
  int v46; // r11
  int v47; // r3
  int v48; // r3
  int v49; // r3
  int v50; // r3
  int v51; // r3
  int v52; // r3
  int v53; // r3
  int v54; // r3
  int v55; // r3
  int v56; // r3
  int v57; // r3
  int v58; // r3
  int v59; // r3
  int v60; // r3
  int v61; // r3
  int v62; // r3
  int v63; // r3
  int v64; // r3
  int v65; // r31
  int v66; // r30
  int v67; // r3
  int v68; // r3
  int v69; // r3
  int v70; // r3
  int v71; // r3
  int v72; // r3
  int v73; // r31
  int v74; // r3
  int v75; // r9
  int v76; // r9
  int v77; // r3
  int v78; // r5
  int v79; // r9
  int v80; // r3
  int v81; // r10
  int v82; // r5
  int v83; // r3

  *a += *la;
  *d -= *ia;
  v44 = *ia;
  *ia = ((*a - *d) >> 1) - *la;
  *la = (*d >> 1) + v44;
  *d += *ia;
  *a -= (3 * *la + 8) >> 4;
  *b += *ka;
  *c -= *ja;
  v45 = *ja;
  *ja = ((*b - *c) >> 1) - *ka;
  *ka = (*c >> 1) + v45;
  *c += *ja;
  *b -= (3 * *ka + 8) >> 4;
  *e += *a34;
  v46 = *h - *a28;
  *h = v46;
  v47 = *a28;
  *a28 = ((*e - v46) >> 1) - *a34;
  *a34 = (*h >> 1) + v47;
  *h += *a28;
  *e -= (3 * *a34 + 8) >> 4;
  *f += *a32;
  *g -= *a30;
  v48 = *a30;
  *a30 = ((*f - *g) >> 1) - *a32;
  *a32 = (*g >> 1) + v48;
  *g += *a30;
  *f -= (3 * *a32 + 8) >> 4;
  v49 = *la - ((3 * *a + 4) >> 5);
  *la = v49;
  v50 = *a - ((3 * v49 + 8) >> 4);
  *a = v50;
  *la = (v50 >> 1) - *la;
  *a -= *la;
  v51 = *ka - ((3 * *b + 4) >> 5);
  *ka = v51;
  v52 = *b - ((3 * v51 + 8) >> 4);
  *b = v52;
  v53 = (v52 >> 1) - *ka;
  *ka = v53;
  *b -= v53;
  v54 = *a34 - ((3 * *e + 4) >> 5);
  *a34 = v54;
  v55 = *e - ((3 * v54 + 8) >> 4);
  *e = v55;
  v56 = (v55 >> 1) - *a34;
  *a34 = v56;
  *e -= v56;
  v57 = *a32 - ((3 * *f + 4) >> 5);
  *a32 = v57;
  v58 = *f - ((3 * v57 + 8) >> 4);
  *f = v58;
  v59 = (v58 >> 1) - *a32;
  *a32 = v59;
  *f -= v59;
  v60 = *ia - ((*ja + 1) >> 1);
  *ia = v60;
  *ja += (v60 + 1) >> 1;
  v61 = *a28 - ((*a30 + 1) >> 1);
  *a28 = v61;
  *a30 += (v61 + 1) >> 1;
  v62 = *d - ((*h + 1) >> 1);
  *d = v62;
  *h += (v62 + 1) >> 1;
  v63 = *c - ((*g + 1) >> 1);
  *c = v63;
  *g += (v63 + 1) >> 1;
  *la += *a32;
  v64 = *ka - *a34;
  *ka = v64;
  v65 = *la >> 1;
  v66 = v64 >> 1;
  *a32 -= v65;
  v67 = *a34 + (v64 >> 1);
  *a34 = v67;
  v68 = ((3 * v67 + 4) >> 3) + *a32;
  *a32 = v68;
  v69 = *a34 - ((3 * v68 + 2) >> 2);
  *a34 = v69;
  *a32 += (3 * (v69 + 2)) >> 3;
  *a34 -= v66;
  *a32 += v65;
  *ka += *a34;
  v70 = *la - *a32;
  *la = v70;
  *a += v70;
  v71 = *ia - *d;
  *ia = v71;
  v72 = (*a - v71) >> 1;
  v73 = v72 - *la;
  v74 = v72 - *d;
  *d = v73;
  *la = v74;
  *a -= v74;
  *ia += *d;
  *b += *ka;
  v75 = *c - *ja;
  *c = v75;
  v76 = (*b - v75) >> 1;
  v77 = v76 - *ja;
  *ja = v76 - *ka;
  *ka = v77;
  *b -= v77;
  *c += *ja;
  *e += *a34;
  v78 = *h - *a28;
  *h = v78;
  v79 = (*e - v78) >> 1;
  v80 = v79 - *a28;
  *a28 = v79 - *a34;
  *a34 = v80;
  *e -= v80;
  *h += *a28;
  *f += *a32;
  v81 = *g - *a30;
  *g = v81;
  v82 = *f - v81;
  v83 = (v82 >> 1) - *a30;
  *a30 = (v82 >> 1) - *a32;
  *a32 = v83;
  *f -= v83;
  *g += *a30;
}


// ========================================================================
// ?_jxr_4PreFilter@@YAXPAH000@Z
// EA  : 0x82902270
// RVA : 0x00902270
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_4PreFilter(int *a, int *b, int *c, int *d)
{
  int v4; // r11
  int v5; // r11

  *a -= (3 * *d + 16) >> 5;
  *b -= (3 * *c + 16) >> 5;
  *d -= (3 * *a + 8) >> 4;
  *c -= (3 * *b + 8) >> 4;
  *a = *a - ((3 * *d + 16) >> 5) + *d;
  *b = *b - ((3 * *c + 16) >> 5) + *c;
  *d -= (*a + 1) >> 1;
  v4 = *c - ((*b + 1) >> 1);
  *c = v4;
  v5 = *d - ((v4 + 1) >> 1);
  *d = v5;
  *c += (v5 + 1) >> 1;
  *d += (*a + 1) >> 1;
  *c += (*b + 1) >> 1;
  *a -= *d;
  *b -= *c;
}


// ========================================================================
// ?_jxr_2x2PreFilter@@YAXPAH000@Z
// EA  : 0x829023E8
// RVA : 0x009023E8
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_2x2PreFilter(int *a, int *b, int *c, int *d)
{
  int v4; // r11
  int v5; // r11

  *a += *d;
  *b += *c;
  *d -= (*a + 1) >> 1;
  *c -= (*b + 1) >> 1;
  v4 = *b - ((*a + 2) >> 2);
  *b = v4;
  v5 = *a - ((v4 + 1) >> 1);
  *a = v5;
  *b -= (v5 + 2) >> 2;
  *d += (*a + 1) >> 1;
  *c += (*b + 1) >> 1;
  *a -= *d;
  *b -= *c;
}


// ========================================================================
// ?_jxr_2PreFilter@@YAXPAH0@Z
// EA  : 0x829024D0
// RVA : 0x009024D0
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_2PreFilter(int *a, int *b)
{
  int v2; // r11
  int v3; // r11

  v2 = *b - ((*a + 4) >> 3);
  *b = v2;
  v3 = *a - ((v2 + 2) >> 2);
  *a = v3;
  *b -= (v3 + 4) >> 3;
}


// ========================================================================
// ?_jxr_read_lwf_test_flag@@YAEXZ
// EA  : 0x82902518
// RVA : 0x00902518
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

int __fastcall _jxr_read_lwf_test_flag()
{
  return (unsigned __int8)long_word_flag;
}


// ========================================================================
// ?_jxr_complete_cur_dclp@@YAXPAUjxr_image@@HHH@Z
// EA  : 0x82902528
// RVA : 0x00902528
// PDB : w:\tech5\engine\renderer\jobs\transcode\image\barejxr\algo.cpp
// ========================================================================

void __fastcall _jxr_complete_cur_dclp(jxr_image *image, int tx, int mx, int my)
{
  unsigned int v7; // r26
  int v8; // r8
  int v9; // r6
  int v10; // r10
  macroblock_s **p_cur; // r11
  int v12; // r7
  unsigned int v13; // r9
  int v14; // r9
  int use_clr_fmt; // r8
  int *data; // r4
  int *v17; // r4
  int *v18; // r3
  int v19; // r9
  int v20; // r28
  int v21; // r11
  int v22; // r9
  int v23; // r8
  int v24; // r29
  int v25; // r11

  v7 = calculate_mbdc_mode(image, tx, mx, my: image->cur_my);
  v9 = 0;
  if ( image->num_channels != 0 )
  {
    v10 = tx;
    p_cur = &image->strip[0].cur;
    do
    {
      if ( mx <= 0 )
        v12 = 0;
      else
        v12 = *(*p_cur)[image->tile_column_position[v10] - 1 + mx].data;
      v13 = image->tile_column_position[v10] + mx;
      v8 = (int)&(*p_cur)[v13];
      v14 = *(*(p_cur - 1))[v13].data;
      **(_DWORD **)(v8 + 4) = **(_DWORD **)v8;
      if ( v7 != 0 )
      {
        if ( v7 != 1 )
        {
          if ( v7 < 3 )
          {
            if ( v9 > 0 && ((use_clr_fmt = image->use_clr_fmt) == 1 || use_clr_fmt == 2) )
            {
              v8 = (int)*p_cur;
              data = (*p_cur)[image->tile_column_position[v10] + mx].data;
              *data += ((v14 + v12 + 1) >> 1) | (v14 + v12 + 1) & 0x80000000;
            }
            else
            {
              v8 = (int)*p_cur;
              v17 = (*p_cur)[image->tile_column_position[v10] + mx].data;
              *v17 += ((v14 + v12) >> 1) | (v14 + v12) & 0x80000000;
            }
          }
          goto LABEL_17;
        }
        v18 = (*p_cur)[image->tile_column_position[v10] + mx].data;
        v8 = *v18;
        v19 = *v18 + v14;
      }
      else
      {
        v8 = (int)*p_cur;
        v18 = (*p_cur)[image->tile_column_position[v10] + mx].data;
        v19 = *v18 + v12;
      }
      *v18 = v19;
LABEL_17:
      ++v9;
      p_cur += 7;
    }
    while ( v9 < image->num_channels );
  }
  if ( v7 == 0 )
  {
    v8 = image->tile_column_position[tx] + mx;
    if ( *((unsigned __int8 *)&image->strip[0].cur[v8] + 8) == *((unsigned __int8 *)&image->strip[0].cur[v8 - 1] + 8) )
    {
      v20 = 0;
      goto LABEL_24;
    }
    goto LABEL_23;
  }
  if ( v7 != 1
    || (v8 = 4 * tx,
        v20 = 1,
        v21 = image->tile_column_position[tx] + mx,
        *((unsigned __int8 *)&image->strip[0].cur[v21] + 8) != *((unsigned __int8 *)&image->strip[0].up1[v21] + 8)) )
  {
LABEL_23:
    v20 = 2;
  }
LABEL_24:
  predict_lp444(image, tx, mx, my: 0, ch: v20, mblp_mode: v8);
  v24 = 1;
  if ( image->num_channels > 1u )
  {
    do
    {
      v25 = image->use_clr_fmt;
      if ( v25 == 1 )
      {
        predict_lp420(image, tx, mx, my: v24, ch: v20, mblp_mode: v23);
      }
      else if ( v25 == 2 )
      {
        predict_lp422(image, tx, mx, my: v24, ch: v20, mblp_mode: v7, mbdc_mode: v22);
      }
      else
      {
        predict_lp444(image, tx, mx, my: v24, ch: v20, mblp_mode: v23);
      }
      ++v24;
    }
    while ( v24 < image->num_channels );
  }
}

