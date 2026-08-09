#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\image.h
// Recovered logical types: 8
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 4963; PDB kind: union.
union _IMAGE_PTE
{
  struct
  {
    unsigned __int32 ReadOnly : 1;
    unsigned __int32 Data : 1;
    unsigned __int32 NoExecute : 1;
    unsigned __int32 Valid : 1;
    unsigned __int32 StartOfImage : 1;
    unsigned __int32 EndOfImage : 1;
    unsigned __int32 PageFrameNumber : 14;
    unsigned __int32 Whitening : 10;
    unsigned __int32 Terabyte : 2;
  } __s0;
  struct
  {
    unsigned __int32 VNDR : 4;
    unsigned __int32 Markers : 2;
    unsigned __int32 RealPageNumber : 26;
  } __s1;
  unsigned int AsULONG;
};

// IDA Local Type ordinal 13318; PDB kind: class.
class idImage : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13319.
  virtual ~idImage();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  void *backgroundReadData;
  volatile bool backgroundReadComplete;
  bool defaulted;
  unsigned int sourceFileTime;
  unsigned int binaryFileTime;
  int frameUsed;
  int bindCount;
  idImageOpts opts;
  bool optsHasBeenSet;
  bool allocationFailed;
  _D3DFORMAT d3dFormat;
  _D3DLOCKED_RECT lockRect[14];
  D3DTexture *d3dTexture;
  void *imageBuffer;
  int allocWidth;
  int allocHeight;
  int _D3DSAMP_MAGFILTER;
  int _D3DSAMP_MINFILTER;
  int _D3DSAMP_MIPFILTER;
  int _D3DSAMP_MAXANISOTROPY;
  int _D3DSAMP_MIPMAPLODBIAS;
  int _D3DSAMP_MAXMIPLEVEL;
  int _D3DSAMP_MINMIPLEVEL;
  int _D3DSAMP_BORDERCOLOR;
  int _D3DSAMP_ADDRESSU;
  int _D3DSAMP_ADDRESSV;
  int _D3DSAMP_TRILINEARTHRESHOLD;
  int physicalMemoryBytes;
};

// IDA Local Type ordinal 22948; PDB kind: unknown.
struct jxr_image::<unnamed_type_strip>
{
  macroblock_s *up4;
  macroblock_s *up3;
  macroblock_s *up2;
  macroblock_s *up1;
  macroblock_s *cur;
  int *upsample_memory_y;
  int *upsample_memory_x;
};

// IDA Local Type ordinal 22952; PDB kind: struct.
struct __declspec(align(8)) jxr_image
{
  int user_flags;
  unsigned int width1;
  unsigned int height1;
  unsigned int extended_width;
  unsigned int extended_height;
  unsigned __int8 header_flags1;
  unsigned __int8 header_flags2;
  unsigned __int8 header_flags_fmt;
  jxr_output_clr_fmt_e output_clr_fmt;
  unsigned __int8 use_clr_fmt;
  JXRC_GUID_e ePixelFormat;
  unsigned __int32 : 28;
  unsigned __int32 trim_flexbits : 4;
  unsigned __int8 bands_present;
  unsigned __int8 bands_present_of_primary;
  unsigned __int8 chroma_centering_x;
  unsigned __int8 chroma_centering_y;
  unsigned __int8 num_channels;
  unsigned int disableTileOverlapFlag;
  unsigned int tile_rows;
  unsigned int tile_columns;
  unsigned int *tile_row_height;
  unsigned int *tile_column_width;
  unsigned int *tile_row_height_input;
  unsigned int *tile_column_width_input;
  unsigned int *tile_column_position;
  unsigned int *tile_row_position;
  __int64 *tile_index_table;
  __int64 tile_index_table_length;
  unsigned __int16 window_extra_top;
  unsigned __int16 window_extra_left;
  unsigned __int16 window_extra_bottom;
  unsigned __int16 window_extra_right;
  unsigned __int32 : 26;
  unsigned __int32 hp_frame_uniform : 1;
  unsigned __int32 hp_use_lp_qp : 1;
  unsigned __int32 lp_frame_uniform : 1;
  unsigned __int32 lp_use_dc_qp : 1;
  unsigned __int32 dc_frame_uniform : 1;
  unsigned __int32 scaled_flag : 1;
  unsigned __int8 shift_bits;
  unsigned __int8 len_mantissa;
  char exp_bias;
  unsigned int num_lp_qps;
  unsigned int num_hp_qps;
  int cur_my;
  jxr_image::<unnamed_type_strip> strip[16];
  macroblock_s *mb_row_buffer[16];
  macroblock_s *mb_row_context[16];
  adaptive_vlc_s vlc_table[20];
  int count_max_CBPLP;
  int count_zero_CBPLP;
  cbp_model_s hp_cbp_model;
  unsigned int lopass_scanorder[15];
  unsigned int lopass_scantotals[15];
  unsigned int hipass_hor_scanorder[15];
  unsigned int hipass_hor_scantotals[15];
  unsigned int hipass_ver_scanorder[15];
  unsigned int hipass_ver_scantotals[15];
  jxr_component_mode_e dc_component_mode;
  jxr_component_mode_e lp_component_mode;
  jxr_component_mode_e hp_component_mode;
  unsigned __int8 dc_quant_ch[16];
  unsigned __int8 lp_quant_ch[16][16];
  unsigned __int8 hp_quant_ch[16][16];
  jxr_tile_qp *tile_quant;
  model_s model_dc;
  model_s model_lp;
  model_s model_hp;
  model_s *model_hp_buffer;
  cbp_model_s *hp_cbp_model_buffer;
  void (__fastcall *out_fun)(jxr_image *, int, int, int *);
  void (__fastcall *inp_fun)(jxr_image *, int, int, int *);
  void *user_data;
  jxr_image *alpha;
  int primary;
  unsigned __int8 profile_idc;
  unsigned __int8 level_idc;
  unsigned __int8 lwf_test;
  unsigned int container_width;
  unsigned int container_height;
  unsigned __int8 container_nc;
  unsigned __int8 container_alpha;
  unsigned __int8 container_separate_alpha;
  jxr_bitdepth_e container_bpc;
  jxr_output_clr_fmt_e container_color;
  unsigned __int8 container_image_band_presence;
  unsigned __int8 container_alpha_band_presence;
  unsigned __int8 container_current_separate_alpha;
  rbitstream rbits;
  wbitstream wbits;
  unsigned int stripe_tx;
  unsigned int stripe_ty;
  unsigned int stripe_my;
  unsigned int cleanup_state;
  int freq_buffered_flag;
  int spatial_buffered_flag;
  int output_sent;
  unsigned int spatial_mb_width;
  unsigned int spatial_mb_height;
  void *temp_buffer;
  int temp_buffer_size;
  int temp_buffer_used;
};

// IDA Local Type ordinal 23018; PDB kind: class.
class idImageCPU : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23019.
  virtual ~idImageCPU();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  struct idHashStoreJar *jar;
  imageCpuHeader_t *header;
  int width;
  int height;
  unsigned __int8 *data;
  bool emptyImage;
  unsigned int fileLength;
};

// IDA Local Type ordinal 23100; PDB kind: class.
class idImageDef
{
public:
  idImageOpts opts;
  idStr imageProgram;
};

// IDA Local Type ordinal 28136; PDB kind: typedef.
typedef jxr_image *jxr_image_t;

// IDA Local Type ordinal 29664; PDB kind: typedef.
typedef _IMAGE_PTE IMAGE_PTE;
