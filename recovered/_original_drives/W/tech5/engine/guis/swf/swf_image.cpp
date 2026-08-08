
// ========================================================================
// ?swf_jpeg_output_message@@YAXPAUjpeg_common_struct@@@Z
// EA  : 0x82771AE0
// RVA : 0x00771AE0
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall swf_jpeg_output_message(jpeg_common_struct *cinfo)
{
  char v1[208]; // [sp+50h] [-E0h] BYREF

  memset(v1, 0, 200);
  cinfo->err->format_message(a1: cinfo, a2: v1);
  idLib::Printf(fmt: "%s\n", v1);
}


// ========================================================================
// ?swf_jpeg_skip_input_data@@YAXPAUjpeg_decompress_struct@@J@Z
// EA  : 0x82771B48
// RVA : 0x00771B48
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall swf_jpeg_skip_input_data(jpeg_decompress_struct *cinfo, int num_bytes)
{
  cinfo->src->next_input_byte += num_bytes;
  cinfo->src->bytes_in_buffer -= num_bytes;
}


// ========================================================================
// ?Load@idDecompressJPEG@idSWF@@QAAPAEPBEHAAH1@Z
// EA  : 0x82771B78
// RVA : 0x00771B78
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

char *__fastcall idSWF::idDecompressJPEG::Load(
        idSWF::idDecompressJPEG *this,
        const unsigned __int8 *input,
        int inputSize,
        J_DITHER_MODE *width,
        int *height)
{
  jpeg_decompress_struct *v5; // r30
  int header; // r3
  unsigned int v9; // r27
  char *v10; // r28
  unsigned int output_components; // r11
  char *v13; // [sp+50h] [-70h] BYREF
  jpeg_decompress_struct *vinfo; // [sp+54h] [-6Ch]
  _DWORD v15[24]; // [sp+60h] [-60h] BYREF

  vinfo = (jpeg_decompress_struct *)this->vinfo;
  v5 = vinfo;
  *width = JDITHER_NONE;
  *height = 0;
  v15[0] = input;
  v15[1] = inputSize;
  v5->src = (jpeg_source_mgr *)v15;
  v15[2] = idPhysics_StaticMulti::UpdateTime;
  v15[3] = XGComparePixelShaders;
  v15[4] = swf_jpeg_skip_input_data;
  v15[5] = jpeg_resync_to_restart;
  v15[6] = idPhysics_StaticMulti::UpdateTime;
  do
    header = jpeg_read_header(cinfo: v5, require_image: 0);
  while ( header == 2 );
  if ( header == 0 )
    return nullptr;
  jpeg_start_decompress(cinfo: v5);
  if ( *(_DWORD *)&v5->enable_1pass_quant != 4 )
  {
    idLib::Warning(fmt: "JPEG output is not 4 components");
    jpeg_abort_decompress(cinfo: v5);
    v5->src = nullptr;
    return nullptr;
  }
  v9 = 4 * *(_DWORD *)&v5->two_pass_quantize * v5->dither_mode;
  v10 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\engine\\guis\\swf\\SWF_Image.cpp(116) : TAG_SWF",
                  size: v9,
                  tag: TAG_SWF,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  memset(Dst: v10, Val: 255, Size: v9);
  while ( 1 )
  {
    output_components = v5->output_components;
    if ( output_components >= *(_DWORD *)&v5->two_pass_quantize )
      break;
    v13 = &v10[output_components * *(_DWORD *)&v5->enable_1pass_quant * v5->dither_mode];
    jpeg_read_scanlines(cinfo: v5, scanlines: (unsigned __int8 **)&v13, max_lines: 1u);
  }
  jpeg_finish_decompress(cinfo: v5);
  *width = v5->dither_mode;
  *height = *(_DWORD *)&v5->two_pass_quantize;
  v5->src = nullptr;
  return v10;
}


// ========================================================================
// $M221471
// EA  : 0x82771D30
// RVA : 0x00771D30
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void *_M221471()
{
  int v0; // r12

  swf_jpeg_output_message(cinfo: *(jpeg_common_struct **)(v0 - 192 + 84));
  return &_LN14;
}


// ========================================================================
// ?swf_jpeg_error_exit@@YAXPAUjpeg_common_struct@@@Z
// EA  : 0x82771DE8
// RVA : 0x00771DE8
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall __noreturn swf_jpeg_error_exit(jpeg_common_struct *cinfo)
{
  _BYTE v1[16]; // [sp+50h] [-F0h] BYREF
  char v2[208]; // [sp+60h] [-E0h] BYREF

  memset(v2, 0, 200);
  cinfo->err->format_message(a1: cinfo, a2: v2);
  strncpy(dest: idException::error, source: v2, count: 0x800u);
  CxxThrowException(pExceptionObject: v1, pThrowInfo: (const _s__ThrowInfo *)&TI1_AVidException__);
}


// ========================================================================
// ??0idDecompressJPEG@idSWF@@QAA@XZ
// EA  : 0x82771E58
// RVA : 0x00771E58
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

idSWF::idDecompressJPEG *__fastcall idSWF::idDecompressJPEG::idDecompressJPEG(idSWF::idDecompressJPEG *this)
{
  jpeg_decompress_struct *v2; // r28
  jpeg_error_mgr *v3; // r3

  v2 = (jpeg_decompress_struct *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                   size: 0x1B0u,
                                   tag: TAG_SWF,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
  memset(Dst: v2, Val: 0, Size: 0x1B0u);
  v3 = (jpeg_error_mgr *)idMem::AllocWithLocation(
                           this: &mem,
                           location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                           size: 0x84u,
                           tag: TAG_SWF,
                           zeroBuffer: false,
                           align: ALIGN_16,
                           heap: HEAP_DEFAULTHEAP);
  v2->err = v3;
  memset(Dst: v3, Val: 0, Size: sizeof(jpeg_error_mgr));
  jpeg_std_error(err: v2->err);
  v2->err->error_exit = (void (__fastcall *)(jpeg_common_struct *))swf_jpeg_error_exit;
  v2->err->output_message = swf_jpeg_output_message;
  jpeg_CreateDecompress(cinfo: v2, version: 62, structsize: 0x1B0u);
  this->vinfo = v2;
  return this;
}


// ========================================================================
// ??1idDecompressJPEG@idSWF@@QAA@XZ
// EA  : 0x82771F20
// RVA : 0x00771F20
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall idSWF::idDecompressJPEG::~idDecompressJPEG(idSWF::idDecompressJPEG *this)
{
  void **vinfo; // r31

  vinfo = (void **)this->vinfo;
  jpeg_destroy_decompress(cinfo: (jpeg_decompress_struct *)this->vinfo);
  idMem::Free(this: &mem, ptr: *vinfo, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: vinfo, align: ALIGN_16);
}


// ========================================================================
// ?JPEGTables@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82771F80
// RVA : 0x00771F80
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall idSWF::JPEGTables(idSWF *this, idSWFBitStream *bitstream, int a3, int a4, int a5, int a6)
{
  const unsigned __int8 *endp; // r11
  unsigned __int64 v8; // r10
  int v9; // r30
  const unsigned __int8 *Data; // r3
  int v11; // [sp+50h] [-20h] BYREF
  int v12; // [sp+54h] [-1Ch] BYREF

  endp = bitstream->endp;
  LODWORD(v8) = bitstream->startp;
  if ( endp != (const unsigned __int8 *)v8 )
  {
    v9 = (int)&endp[-v8];
    HIDWORD(v8) = &endp[-v8];
    Data = idSWFBitStream::ReadData(this: bitstream, size: (int)&endp[-v8], a3, a4, a5, a6, a7: v8);
    idSWF::idDecompressJPEG::Load(
      this: &this->jpeg,
      input: Data,
      inputSize: v9,
      width: (J_DITHER_MODE *)&v11,
      height: &v12);
  }
}


// ========================================================================
// ?WriteSwfImageAtlas@idSWF@@AAAXPBD@Z
// EA  : 0x82771FF8
// RVA : 0x00771FF8
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idSWF::WriteSwfImageAtlas(idSWF *this, const char *filename)
{
  int size; // r11
  int num; // r30
  int v6; // r9
  int v7; // r10
  int v8; // r11
  idSWF::imageToPack_t *v9; // r7
  idSkinMapping *v10; // r8
  int v11; // r10
  int y; // r11
  int v13; // r11
  unsigned int v14; // r8
  unsigned __int8 *v15; // r24
  int v16; // r10
  unsigned __int8 *v17; // r11
  int v18; // r20
  int v19; // r22
  int v20; // r21
  idSWF::imageToPack_t *v21; // r30
  int v22; // r9
  int x; // r4
  int v24; // r11
  int v25; // r8
  int v26; // r3
  int v27; // r27
  int v28; // r29
  int v29; // r6
  unsigned __int8 *imageData; // r7
  int v31; // r5
  int v32; // r11
  int v33; // r10
  __int64 *v34; // r11
  int i; // ctr
  int v36; // r11
  int v37; // r9
  signed int v38; // r6
  unsigned __int8 *v39; // r10
  int v40; // r5
  unsigned int v41; // r10
  int v42; // r5
  int v43; // r11
  int v44; // r29
  int v45; // r25
  bool v46; // zf
  int v47; // r5
  int v48; // ctr
  unsigned int v49; // r4
  int v50; // r11
  int v51; // r7
  int j; // r11
  signed int v53; // r9
  signed int v54; // r10
  int v55; // r9
  unsigned int v56; // r10
  __int64 v57; // r4 OVERLAPPED
  __int64 v58; // r7 OVERLAPPED
  double v59; // fp13
  double v60; // fp9
  double v61; // fp6
  int atlasWidth; // r10
  idImageOpts *atlasHeight; // r9
  double v64; // [sp+18h] [-1F8h]
  _DWORD v65[10]; // [sp+58h] [-1B8h] BYREF
  idList<idSkinMapping,46> v66; // [sp+80h] [-190h] BYREF
  int v67; // [sp+90h] [-180h]
  idList<idVec2i,5> v68; // [sp+A0h] [-170h] BYREF
  idVec2i v69; // [sp+B0h] [-160h] BYREF
  __int64 v70; // [sp+C0h] [-150h] BYREF
  int v71; // [sp+C8h] [-148h]
  int v72; // [sp+CCh] [-144h]
  int v73; // [sp+D0h] [-140h]
  int v74; // [sp+D4h] [-13Ch]
  idImageOpts *v75; // [sp+D8h] [-138h]
  int v76; // [sp+DCh] [-134h]
  int v77; // [sp+E0h] [-130h]
  char v78; // [sp+E4h] [-12Ch]
  char v79; // [sp+E5h] [-12Bh]
  char v80; // [sp+E6h] [-12Ah]
  char v81; // [sp+E7h] [-129h]
  char v82; // [sp+E8h] [-128h]
  char v83; // [sp+E9h] [-127h]
  unsigned __int16 v84; // [sp+EAh] [-126h]
  int v85; // [sp+ECh] [-124h]
  int v86; // [sp+F0h] [-120h]
  int v87; // [sp+F4h] [-11Ch]
  int v88; // [sp+F8h] [-118h]
  float v89; // [sp+FCh] [-114h]
  float v90; // [sp+100h] [-110h]
  float v91; // [sp+104h] [-10Ch]
  float v92[6]; // [sp+108h] [-108h] BYREF
  _DWORD v93[4]; // [sp+120h] [-F0h] BYREF
  __int64 v94; // [sp+130h] [-E0h]
  unsigned __int8 *v95; // [sp+138h] [-D8h]
  unsigned int v96; // [sp+13Ch] [-D4h]
  __int64 v97; // [sp+140h] [-D0h]
  __int64 v98; // [sp+148h] [-C8h]
  __int64 v99; // [sp+150h] [-C0h]
  idStr v100; // [sp+160h] [-B0h] BYREF

  memset(&v66, 0, 14);
  *(_WORD *)&v66.memTag = 18432;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v66);
  size = v66.size;
  num = this->packImages.num;
  if ( num > v66.size )
  {
    if ( !idList<idDeclMD6::includeDecl_t,5>::Resize(this: &v66, newsize: this->packImages.num) )
      goto LABEL_6;
    size = v66.size;
  }
  v66.num = num;
  if ( num >= size )
    v66.num = size;
LABEL_6:
  v6 = 0;
  if ( this->packImages.num > 0 )
  {
    v7 = 0;
    v8 = 0;
    do
    {
      ++v6;
      v9 = &this->packImages.list[v7];
      v10 = &v66.list[v8++];
      ++v7;
      v10->from = (const idMaterial *)v9->allocSize.x;
      v10->to = (const idMaterial *)v9->allocSize.y;
    }
    while ( v6 < this->packImages.num );
  }
  *(_WORD *)&v68.memTag = 18432;
  memset((void *)&v68, 0, 14);
  RectAllocator(inputSizes: (const idList<idVec2i,5> *)&v66, outputPositions: &v68, totalSize: &v69);
  v64 = RectPackingFraction(inputSizes: (const idList<idVec2i,5> *)v69.x, totalSize: (const idVec2i *)v69.y);
  idLib::Printf(fmt: "%5.2f packing fraction in %ix%i image\n", v64, LODWORD(v64), 4 * v69.x);
  v11 = 4 * v69.x;
  if ( 4 * v69.x < 4 )
    v11 = 4;
  y = v69.y;
  this->atlasWidth = v11;
  v13 = 4 * y;
  if ( v13 < 4 )
    v13 = 4;
  this->atlasHeight = v13;
  v14 = (v11 + 127) & 0xFFFFFF80;
  this->atlasWidth = v14;
  v96 = 4 * v14 * v13;
  v15 = (unsigned __int8 *)idMem::AllocWithLocation(
                             this: &mem,
                             location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                             size: v96,
                             tag: TAG_TEMP,
                             zeroBuffer: false,
                             align: ALIGN_16,
                             heap: HEAP_DEFAULTHEAP);
  v95 = v15;
  v16 = 0;
  if ( this->atlasWidth * this->atlasHeight > 0 )
  {
    v17 = v15 - 1;
    do
    {
      v17[1] = -1;
      ++v16;
      v17[2] = 0;
      v17[3] = 0;
      v17 += 4;
      *v17 = -1;
    }
    while ( v16 < this->atlasWidth * this->atlasHeight );
  }
  v18 = 0;
  if ( this->packImages.num > 0 )
  {
    v19 = 0;
    v20 = 0;
    do
    {
      v21 = &this->packImages.list[v20];
      v93[0] = 255;
      v93[1] = 255;
      v93[2] = 255;
      v22 = 0;
      v93[3] = 255;
      x = v68.list[v19].x;
      v25 = v21->trueSize.x;
      v26 = v68.list[v19].y;
      v24 = v21->trueSize.y;
      v27 = v21->allocSize.x;
      v28 = v21->allocSize.y;
      v70 = 0;
      v71 = 0;
      v72 = 0;
      v29 = 4 * v24 * v25;
      if ( v29 > 0 )
      {
        imageData = v21->imageData;
        v31 = 4 * v24 * v25;
        do
        {
          v32 = (4 * v22) & 0xC;
          v33 = imageData[v22];
          v67 = v22 & 3;
          if ( v33 < *(_DWORD *)((char *)v93 + v32) )
            *(_DWORD *)((char *)v93 + v32) = v33;
          if ( v33 > *(_DWORD *)((char *)&v70 + v32) )
            *(_DWORD *)((char *)&v70 + v32) = v33;
          ++v22;
        }
        while ( v22 < v31 );
      }
      v34 = &v70;
      for ( i = 4; i != 0; --i )
      {
        if ( *(_DWORD *)v34 == 0 )
          *(_DWORD *)v34 = 1;
        v34 = (__int64 *)((char *)v34 + 4);
      }
      v36 = 0;
      if ( v29 > 0 )
      {
        v37 = 0;
        do
        {
          v38 = *(_DWORD *)((char *)&v70 + v37);
          v39 = &v21->imageData[v36];
          v67 = v36 & 3;
          __twllei(v38, 0);
          ++v36;
          v37 = (4 * v36) & 0xC;
          v40 = __ROL4__(*v39, 8) - *v39;
          *v39 = v40 / v38;
          v41 = v38 & ~(__ROL4__(v40, 1) - 1);
          v42 = 4 * v21->trueSize.y * v21->trueSize.x;
          __twlgei(v41, 0xFFFFFFFF);
        }
        while ( v36 < v42 );
      }
      v43 = 4 * v28;
      v45 = 4 * v26;
      v46 = 4 * v28 <= 0;
      v44 = 4 * x;
      if ( !v46 )
      {
        v47 = 4 * v27;
        v48 = v43;
        v49 = -1;
        do
        {
          v50 = v21->trueSize.y;
          v67 = v49;
          v51 = ((v49 >> 31) - 1) & v49;
          if ( v51 >= v50 )
            v51 = v50 - 1;
          for ( j = 0; j < v47; *(_DWORD *)&v15[4 * v56] = *(_DWORD *)&v21->imageData[4 * v55] )
          {
            v53 = v21->trueSize.x;
            v67 = j - 1;
            v54 = (((unsigned int)(j - 1) >> 31) - 1) & (j - 1);
            if ( v54 >= v53 )
              v54 = v53 - 1;
            v55 = v53 * v51 + v54;
            v56 = (v45 + 1 + v49) * this->atlasWidth + j++ + v44;
          }
          ++v49;
          --v48;
        }
        while ( v48 != 0 );
      }
      HIDWORD(v57) = idSWF::FindDictionaryEntry(this, characterID: v21->characterID);
      LODWORD(v58) = v72;
      LODWORD(v57) = v71;
      v97 = v58;
      HIDWORD(v58) = HIDWORD(v70);
      v99 = v57;
      v94 = *(__int64 *)((char *)&v58 + 4);
      v98 = v70;
      v59 = (double)v70;
      v60 = (double)v97;
      v61 = (double)*(__int64 *)((char *)&v58 + 4);
      *(_DWORD *)(HIDWORD(v57) + 28) = v21->trueSize.x;
      HIDWORD(v58) = v21->trueSize.y;
      *(_DWORD *)(HIDWORD(v57) + 36) = v44 + 1;
      *(_DWORD *)(HIDWORD(v57) + 40) = v45 + 1;
      *(_DWORD *)(HIDWORD(v57) + 32) = HIDWORD(v58);
      *(float *)(HIDWORD(v57) + 48) = (float)v59 * (float)0.0039215689;
      *(float *)(HIDWORD(v57) + 52) = (float)v57 * (float)0.0039215689;
      *(float *)(HIDWORD(v57) + 56) = (float)v60 * (float)0.0039215689;
      *(float *)(HIDWORD(v57) + 44) = (float)v61 * (float)0.0039215689;
      idMem::Free(this: &mem, ptr: v21->imageData, align: ALIGN_16);
      ++v18;
      v21->imageData = nullptr;
      ++v20;
      ++v19;
    }
    while ( v18 < this->packImages.num );
  }
  R_WriteTGA(
    filename,
    data: v15,
    width: this->atlasWidth,
    height: this->atlasHeight,
    depth: 4,
    flipVertical: false,
    swapRGB: true,
    basePath: FSPATH_BASE);
  idStr::idStr(this: &v100, text: filename);
  idStr::SetFileExtension(this: &v100, extension: ".bimage");
  v81 = 0;
  v76 = 0;
  v73 = 0;
  v78 = 1;
  v79 = 0;
  v80 = 0;
  v89 = 0.0;
  v90 = 0.0;
  v91 = 0.0;
  HIWORD(v92[5]) = 0;
  v92[0] = 0.0;
  v92[1] = 0.0;
  v82 = 0;
  v92[2] = 0.0;
  v92[3] = 13.0;
  v83 = 0;
  v92[4] = 0.0;
  v77 = 1;
  v85 = 11;
  v87 = 0;
  v88 = 1;
  atlasWidth = this->atlasWidth;
  atlasHeight = (idImageOpts *)this->atlasHeight;
  v86 = ((_cntlzw(swf_imageCompressor.valueInteger) & 0x20) == 0) + 4;
  v65[7] = v15;
  v65[9] = 0;
  v74 = atlasWidth;
  v75 = atlasHeight;
  memcpy(Dst: v65, Src: v92, Size: 0x18u);
  idImage::WriteBinaryImage(imageName: v100.data, opts: v75, imageData: (const unsigned __int8 *)1, sourceFileTime: v84);
  idStr::FreeData(this: &v100);
  if ( v15 != nullptr )
    idMem::Free(this: &mem, ptr: v15, align: ALIGN_16);
  if ( v68.listStatic == 0 || v68.listStatic == 2 )
  {
    if ( v68.list != nullptr )
      idMem::Free(this: &mem, ptr: v68.list, align: ALIGN_16);
    v68.list = nullptr;
    v68.size = 0;
  }
  v68.num = 0;
  if ( (v66.listStatic == 0 || v66.listStatic == 2) && v66.list != nullptr )
    idMem::Free(this: &mem, ptr: v66.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$222084
// EA  : 0x82772684
// RVA : 0x00772684
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222084()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 128));
}


// ========================================================================
// __unwind$222085
// EA  : 0x827726AC
// RVA : 0x007726AC
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222085()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 528 + 160));
}


// ========================================================================
// __unwind$222086
// EA  : 0x827726D4
// RVA : 0x007726D4
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222086()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 528 + 312));
}


// ========================================================================
// __unwind$222087
// EA  : 0x827726FC
// RVA : 0x007726FC
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222087()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 528 + 352));
}


// ========================================================================
// ?LoadImageA@idSWF@@AAAXHPBEHH@Z
// EA  : 0x82772728
// RVA : 0x00772728
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall idSWF::LoadImageA(
        idSWF *this,
        int characterID,
        const unsigned __int8 *imageData,
        int width,
        int height)
{
  idSWFDictionaryEntry *v10; // r26
  int v11; // r11
  int v12; // r11
  idSWF::imageToPack_t *list; // r10
  int granularity; // r4
  int size; // r11
  bool v16; // cr58
  signed int v17; // r10
  int v18; // r4
  int v19; // r11
  int num; // r11
  _DWORD *v21; // r7
  int v22; // ctr
  int *p_y; // r11
  _DWORD v24[4]; // [sp+4Ch] [-54h] BYREF
  void *v25; // [sp+5Ch] [-44h]
  int v26; // [sp+60h] [-40h]
  int v27; // [sp+64h] [-3Ch]

  v10 = idSWF::AddDictionaryEntry(this, characterID, type: SWF_DICT_IMAGE);
  if ( v10 != nullptr )
  {
    v24[1] = characterID;
    v25 = idMem::AllocWithLocation(
            this: &mem,
            location: "w:\\tech5\\engine\\guis\\swf\\SWF_Image.cpp(310) : TAG_IMAGE",
            size: 4 * width * height,
            tag: TAG_IMAGE,
            zeroBuffer: false,
            align: ALIGN_16,
            heap: HEAP_DEFAULTHEAP);
    memcpy(Dst: v25, Src: imageData, Size: 4 * width * height);
    v24[2] = width;
    v11 = (width + 3) >> 2;
    v24[3] = height;
    if ( 4 * v11 - width < 2 )
      ++v11;
    v26 = v11;
    v12 = (height + 3) >> 2;
    if ( 4 * v12 - height < 2 )
      ++v12;
    list = this->packImages.list;
    v27 = v12;
    if ( list != nullptr )
      goto LABEL_10;
    granularity = this->packImages.granularity;
    if ( granularity <= 0 )
      granularity = 1;
    if ( idList<HQDXTjob_t,34>::Resize(this: &this->packImages, newsize: granularity) )
    {
LABEL_10:
      size = this->packImages.size;
      if ( this->packImages.num != size )
        goto LABEL_21;
      if ( forceIdListsToReallocateEveryAppend )
      {
        v16 = !idList<HQDXTjob_t,34>::Resize(this: &this->packImages, newsize: size + 1);
      }
      else
      {
        v17 = this->packImages.granularity;
        if ( this->packImages.granularity != 0 )
        {
          v19 = size + v17;
          __twllei(v17, 0);
          __twlgei(v17 & ~(__ROL4__(v19, 1) - 1), 0xFFFFFFFF);
          v16 = !idList<HQDXTjob_t,34>::Resize(this: &this->packImages, newsize: v19 - v19 % v17);
        }
        else
        {
          v18 = 2 * size;
          if ( 2 * size >= size )
          {
            if ( v18 == 0 )
              v18 = 1;
            v16 = !idList<HQDXTjob_t,34>::Resize(this: &this->packImages, newsize: v18);
          }
          else
          {
            v16 = !idList<HQDXTjob_t,34>::Resize(this: &this->packImages, newsize: 0x7FFFFFFF);
          }
        }
      }
      if ( !v16 )
      {
LABEL_21:
        num = this->packImages.num;
        if ( num < this->packImages.size )
        {
          v21 = v24;
          v22 = 6;
          p_y = &this->packImages.list[num - 1].allocSize.y;
          do
          {
            *++p_y = *++v21;
            --v22;
          }
          while ( v22 != 0 );
          ++this->packImages.num;
        }
      }
    }
    v10->material = nullptr;
  }
}


// ========================================================================
// ?DefineBits@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82772950
// RVA : 0x00772950
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall idSWF::DefineBits(idSWF *this, idSWFBitStream *bitstream)
{
  unsigned __int64 v2; // r10
  const unsigned __int8 *v4; // r11
  const unsigned __int8 *startp; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r5
  int v9; // r31
  unsigned __int16 v10; // r29
  const unsigned __int8 *Data; // r3
  char *v12; // r3
  char *v13; // r31
  int v14; // [sp+50h] [-30h] BYREF
  int v15; // [sp+54h] [-2Ch] BYREF

  LODWORD(v2) = 0;
  HIDWORD(v2) = bitstream->endp;
  v4 = bitstream->readp + 2;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  bitstream->readp = v4;
  startp = bitstream->startp;
  v6 = *(v4 - 2);
  LODWORD(v2) = HIDWORD(v2) - (_DWORD)startp;
  v7 = *(v4 - 1);
  v8 = __ROL4__(v7, 8);
  v9 = HIDWORD(v2) - (_DWORD)startp - 2;
  v10 = v8 | v6;
  Data = idSWFBitStream::ReadData(this: bitstream, size: v9, a3: v8, a4: v7, a5: v6, a6: (int)startp, a7: v2);
  v12 = idSWF::idDecompressJPEG::Load(
          this: &this->jpeg,
          input: Data,
          inputSize: v9,
          width: (J_DITHER_MODE *)&v15,
          height: &v14);
  v13 = v12;
  if ( v12 != nullptr )
  {
    idSWF::LoadImageA(this, characterID: v10, imageData: (const unsigned __int8 *)v12, width: v15, height: v14);
    idMem::Free(this: &mem, ptr: v13, align: ALIGN_16);
  }
}


// ========================================================================
// ?DefineBitsJPEG2@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82772A08
// RVA : 0x00772A08
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall idSWF::DefineBitsJPEG2(
        idSWF *this,
        idSWFBitStream *bitstream,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned __int64 a7)
{
  const unsigned __int8 *v8; // r11
  unsigned __int16 v10; // r28
  const unsigned __int8 *endp; // r6
  idSWFBitStream *v12; // r3
  const unsigned __int8 *startp; // r5
  int v14; // r30
  unsigned __int64 v15; // r10
  int v16; // r8
  int v17; // r7
  const unsigned __int8 *Data; // r3
  char *v19; // r3
  char *v20; // r30
  idSWF::idDecompressJPEG v21; // [sp+50h] [-40h] BYREF
  int v22; // [sp+54h] [-3Ch] BYREF
  int v23; // [sp+58h] [-38h] BYREF

  LODWORD(a7) = 0;
  v8 = bitstream->readp + 2;
  bitstream->currentBit = a7;
  bitstream->currentByte = a7;
  bitstream->readp = v8;
  v10 = __ROL4__(*(v8 - 1), 8) | *(v8 - 2);
  idSWF::idDecompressJPEG::idDecompressJPEG(this: &v21);
  endp = bitstream->endp;
  v12 = bitstream;
  startp = bitstream->startp;
  v14 = endp - startp - 2;
  Data = idSWFBitStream::ReadData(this: v12, size: v14, a3: (int)startp, a4: (int)endp, a5: v17, a6: v16, a7: v15);
  v19 = idSWF::idDecompressJPEG::Load(
          this: &v21,
          input: Data,
          inputSize: v14,
          width: (J_DITHER_MODE *)&v23,
          height: &v22);
  v20 = v19;
  if ( v19 != nullptr )
  {
    idSWF::LoadImageA(this, characterID: v10, imageData: (const unsigned __int8 *)v19, width: v23, height: v22);
    idMem::Free(this: &mem, ptr: v20, align: ALIGN_16);
  }
  idSWF::idDecompressJPEG::~idDecompressJPEG(this: &v21);
}


// ========================================================================
// __unwind$222519
// EA  : 0x82772AD4
// RVA : 0x00772AD4
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222519()
{
  int v0; // r12

  idSWF::idDecompressJPEG::~idDecompressJPEG(this: (idSWF::idDecompressJPEG *)(v0 - 144 + 80));
}


// ========================================================================
// ?DefineBitsJPEG3@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82772B08
// RVA : 0x00772B08
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall idSWF::DefineBitsJPEG3(idSWF *this, idSWFBitStream *bitstream)
{
  unsigned __int64 v2; // r27
  const unsigned __int8 *v4; // r11
  __int16 v6; // r7
  __int16 v7; // r8
  unsigned __int16 v8; // r22
  int v9; // r29
  unsigned __int64 v10; // r10
  int v11; // r8
  int v12; // r7
  int v13; // r6
  int v14; // r5
  const unsigned __int8 *Data; // r3
  char *v16; // r26
  char *buffer; // r24
  int v18; // r23
  int v19; // r28
  unsigned __int64 v20; // r10
  idSWFBitStream *v21; // r3
  int v22; // r30
  int v23; // r8
  int v24; // r7
  int v25; // r6
  int v26; // r5
  const unsigned __int8 *v27; // r3
  char *v28; // r29
  int v29; // r11
  char *v30; // r10
  char v31; // r9
  void **vinfo; // r29
  idSWF::idDecompressJPEG v33[2]; // [sp+50h] [-70h] BYREF
  idTempArray<char> v34; // [sp+58h] [-68h] BYREF
  int v35; // [sp+60h] [-60h] BYREF

  LODWORD(v2) = 0;
  v4 = bitstream->readp + 2;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  bitstream->readp = v4;
  v6 = *(v4 - 2);
  v7 = __ROL4__(*(v4 - 1), 8);
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  bitstream->readp = v4 + 4;
  v8 = v7 | v6;
  v9 = ((((__ROL4__(v4[3], 8) | v4[2]) << 8) | v4[1]) << 8) | *v4;
  idSWF::idDecompressJPEG::idDecompressJPEG(this: v33);
  Data = idSWFBitStream::ReadData(this: bitstream, size: v9, a3: v14, a4: v13, a5: v12, a6: v11, a7: v10);
  v16 = idSWF::idDecompressJPEG::Load(this: v33, input: Data, inputSize: v9, width: (J_DITHER_MODE *)&v34, height: &v35);
  if ( v16 == nullptr )
    goto LABEL_2;
  buffer = v34.buffer;
  v18 = v35;
  v19 = (int)v34.buffer * v35;
  idTempArray<char>::idTempArray<char>(this: &v34, num: (int)v34.buffer * v35);
  LODWORD(v20) = bitstream->startp;
  v21 = bitstream;
  HIDWORD(v20) = &bitstream->endp[-v20];
  v22 = HIDWORD(v20) - v9 - 6;
  v27 = idSWFBitStream::ReadData(this: v21, size: v22, a3: v26, a4: v25, a5: v24, a6: v23, a7: v20);
  v28 = v34.buffer;
  if ( !idSWF::Inflate(this, input: v27, inputSize: v22, output: (unsigned __int8 *)v34.buffer, outputSize: v34.num) )
  {
    idLib::Warning(fmt: "DefineBitsJPEG3: Failed to inflate alpha data");
    idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
    if ( v28 != nullptr )
      idMem::Free(this: &mem, ptr: v28, align: ALIGN_16);
LABEL_2:
    idSWF::idDecompressJPEG::~idDecompressJPEG(this: v33);
    return;
  }
  v29 = 0;
  if ( v19 > 0 )
  {
    v30 = v16 - 1;
    do
    {
      v31 = v28[v29++];
      v30 += 4;
      *v30 = v31;
    }
    while ( v29 < v19 );
  }
  if ( v28 != nullptr )
    idMem::Free(this: &mem, ptr: v28, align: ALIGN_16);
  idSWF::LoadImageA(this, characterID: v8, imageData: (const unsigned __int8 *)v16, width: (int)buffer, height: v18);
  idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
  vinfo = (void **)v33[0].vinfo;
  jpeg_destroy_decompress(cinfo: (jpeg_decompress_struct *)v33[0].vinfo);
  idMem::Free(this: &mem, ptr: *vinfo, align: ALIGN_16);
  idMem::Free(this: &mem, ptr: vinfo, align: ALIGN_16);
}


// ========================================================================
// __unwind$222551
// EA  : 0x82772D10
// RVA : 0x00772D10
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222551()
{
  int v0; // r12

  idSWF::idDecompressJPEG::~idDecompressJPEG(this: (idSWF::idDecompressJPEG *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$222552
// EA  : 0x82772D38
// RVA : 0x00772D38
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222552()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 192 + 88));
}


// ========================================================================
// ?DefineBitsLossless@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82772D68
// RVA : 0x00772D68
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall idSWF::DefineBitsLossless(idSWF *this, idSWFBitStream *bitstream)
{
  unsigned __int64 v2; // r25
  const unsigned __int8 *v4; // r11
  unsigned __int16 v5; // r5
  unsigned __int16 v6; // r21
  int v7; // r28
  unsigned __int16 v9; // r5
  int v10; // r29
  unsigned __int16 v11; // r10
  unsigned int v12; // r27
  unsigned __int64 v13; // r25
  char *v14; // r3
  int v15; // r4
  char *v16; // r28
  bool v17; // zf
  const unsigned __int8 *readp; // r11
  const unsigned __int8 *v19; // r9
  unsigned int v20; // r26
  int v21; // r11
  int v22; // r27
  const unsigned __int8 *endp; // r7
  const unsigned __int8 *v24; // r6
  int v25; // r20
  unsigned __int64 v26; // r10
  int v27; // r8
  int v28; // r5
  const unsigned __int8 *Data; // r3
  int *buffer; // r30
  int *v31; // r4
  char *v32; // r6
  int v33; // r5
  int i; // ctr
  int j; // r11
  int v36; // r9
  int v37; // r8
  char *v38; // r10
  char *v39; // r9
  int v40; // r27
  unsigned __int64 v41; // r10
  const unsigned __int8 *v42; // r8
  int v43; // r26
  int v44; // r20
  int v45; // r6
  int v46; // r5
  const unsigned __int8 *v47; // r3
  int v48; // r8
  int v49; // ctr
  int v50; // r9
  int k; // r11
  int v52; // r5
  int v53; // r10
  char *v54; // r10
  unsigned int v55; // r4
  unsigned __int64 v56; // r10
  const unsigned __int8 *v57; // r27
  int v58; // r26
  int v59; // r8
  int v60; // r7
  int v61; // r6
  int v62; // r5
  const unsigned __int8 *v63; // r3
  int v64; // r8
  int m; // ctr
  int n; // r11
  int v67; // r9
  char *v68; // r10
  int v69; // r6
  idTempArray<int> v70[14]; // [sp+50h] [-70h] BYREF

  LODWORD(v2) = 0;
  v4 = bitstream->readp + 2;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  bitstream->readp = v4;
  v5 = __ROL4__(*(v4 - 1), 8) | *(v4 - 2);
  bitstream->currentBit = v2;
  v6 = v5;
  bitstream->currentByte = v2;
  v7 = *v4;
  bitstream->readp = v4 + 3;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  v9 = __ROL4__(v4[2], 8) | v4[1];
  bitstream->readp = v4 + 5;
  v10 = v9;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  v11 = __ROL4__(v4[4], 8) | v4[3];
  v12 = v9 * v11;
  HIDWORD(v13) = v11;
  v14 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\engine\\guis\\swf\\SWF_Image.cpp(443) : TAG_SWF",
                  size: 4 * v12,
                  tag: TAG_SWF,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v15 = v7;
  v17 = v7 != 3;
  v16 = v14;
  if ( !v17 )
  {
    readp = bitstream->readp;
    bitstream->currentBit = v13;
    v19 = readp + 1;
    bitstream->currentByte = v13;
    v20 = (v10 + 3) & 0xFFFFFFFC;
    v21 = *readp + 1;
    bitstream->readp = v19;
    v22 = 3 * v21;
    idTempArray<char>::idTempArray<char>(this: (idTempArray<char> *)v70, num: HIDWORD(v13) * v20 + 3 * v21);
    endp = bitstream->endp;
    v24 = bitstream->readp;
    v25 = endp - v24;
    Data = idSWFBitStream::ReadData(
             this: bitstream,
             size: endp - v24,
             a3: v28,
             a4: (int)v24,
             a5: (int)endp,
             a6: v27,
             a7: v26);
    buffer = v70[0].buffer;
    if ( !idSWF::Inflate(
            this,
            input: Data,
            inputSize: v25,
            output: (unsigned __int8 *)v70[0].buffer,
            outputSize: v70[0].num) )
    {
      idLib::Warning(fmt: "DefineBitsLossless: Failed to inflate color map data");
      idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
      if ( buffer == nullptr )
        return;
      v31 = buffer;
      goto LABEL_36;
    }
    v32 = (char *)buffer + v22;
    if ( SHIDWORD(v13) > 0 )
    {
      v33 = 0;
      for ( i = HIDWORD(v13); i != 0; --i )
      {
        for ( j = 0; j < v10; v38[3] = -1 )
        {
          v36 = (unsigned __int8)v32[j];
          v37 = 4 * (v33 + j++);
          v38 = &v16[v37];
          v39 = (char *)buffer + v36 + __ROL4__(v36, 1);
          v16[v37] = *v39;
          v38[1] = v39[1];
          v38[2] = v39[2];
        }
        v32 += v20;
        v33 += v10;
      }
    }
    if ( buffer != nullptr )
LABEL_33:
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
LABEL_35:
    idSWF::LoadImageA(this, characterID: v6, imageData: (const unsigned __int8 *)v16, width: v10, height: SHIDWORD(v13));
    v31 = (int *)v16;
    goto LABEL_36;
  }
  if ( v15 == 4 )
  {
    v40 = (v10 - 1) & 1;
    idTempArray<unsigned short>::idTempArray<unsigned short>(
      this: (idTempArray<unsigned short> *)v70,
      num: 2 * HIDWORD(v13) * v40);
    HIDWORD(v41) = bitstream->endp;
    v42 = bitstream->readp;
    v43 = HIDWORD(v41) - (_DWORD)v42;
    v44 = 2 * v70[0].num;
    v47 = idSWFBitStream::ReadData(
            this: bitstream,
            size: HIDWORD(v41) - (_DWORD)v42,
            a3: v46,
            a4: v45,
            a5: v70[0].num,
            a6: (int)v42,
            a7: v41);
    buffer = v70[0].buffer;
    if ( !idSWF::Inflate(this, input: v47, inputSize: v43, output: (unsigned __int8 *)v70[0].buffer, outputSize: v44) )
    {
      idLib::Warning(fmt: "DefineBitsLossless: Failed to inflate bitmap data");
      idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
      if ( buffer == nullptr )
        return;
      v31 = buffer;
      goto LABEL_36;
    }
    if ( SHIDWORD(v13) > 0 )
    {
      v48 = 0;
      v49 = HIDWORD(v13);
      v50 = 0;
      do
      {
        for ( k = 0; k < v10; v54[2] = v55 & 0x1F )
        {
          v52 = 2 * (v50 + k);
          v53 = 4 * (v48 + k++);
          v54 = &v16[v53];
          v55 = *(unsigned __int16 *)((char *)buffer + v52);
          v54[3] = -1;
          *v54 = (v55 >> 10) & 0x1F;
          v54[1] = (v55 >> 5) & 0x1F;
        }
        v50 += v40;
        v48 += v10;
        --v49;
      }
      while ( v49 != 0 );
    }
    if ( buffer == nullptr )
      goto LABEL_35;
    goto LABEL_33;
  }
  if ( v15 != 5 )
  {
    idLib::Warning(fmt: "DefineBitsLossless: Unknown image format %d", v15);
    memset(Dst: v16, Val: 255, Size: 4 * v12);
    goto LABEL_35;
  }
  idTempArray<int>::idTempArray<int>(this: v70, num: v12);
  LODWORD(v56) = bitstream->readp;
  HIDWORD(v56) = v70[0].num;
  v57 = &bitstream->endp[-v56];
  v58 = 4 * v70[0].num;
  v63 = idSWFBitStream::ReadData(this: bitstream, size: (int)v57, a3: v62, a4: v61, a5: v60, a6: v59, a7: v56);
  buffer = v70[0].buffer;
  if ( idSWF::Inflate(this, input: v63, inputSize: (int)v57, output: (unsigned __int8 *)v70[0].buffer, outputSize: v58) )
  {
    if ( SHIDWORD(v13) > 0 )
    {
      v64 = 0;
      for ( m = HIDWORD(v13); m != 0; --m )
      {
        for ( n = 0; n < v10; *(_WORD *)(v68 + 1) = v69 )
        {
          v67 = 4 * (n + v64);
          ++n;
          v68 = &v16[v67];
          v69 = buffer[v67 / 4u];
          v68[3] = -1;
          v16[v67] = BYTE1(v69);
        }
        v64 += v10;
      }
    }
    if ( buffer == nullptr )
      goto LABEL_35;
    goto LABEL_33;
  }
  idLib::Warning(fmt: "DefineBitsLossless: Failed to inflate bitmap data");
  idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
  if ( buffer == nullptr )
    return;
  v31 = buffer;
LABEL_36:
  idMem::Free(this: &mem, ptr: v31, align: ALIGN_16);
}


// ========================================================================
// __unwind$222640
// EA  : 0x82773208
// RVA : 0x00773208
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222640()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$222641
// EA  : 0x82773230
// RVA : 0x00773230
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222641()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$222642
// EA  : 0x82773258
// RVA : 0x00773258
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222642()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 192 + 80));
}


// ========================================================================
// ?DefineBitsLossless2@idSWF@@AAAXAAVidSWFBitStream@@@Z
// EA  : 0x82773288
// RVA : 0x00773288
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __fastcall idSWF::DefineBitsLossless2(idSWF *this, idSWFBitStream *bitstream)
{
  unsigned __int64 v2; // r27
  const unsigned __int8 *v4; // r11
  unsigned __int16 v5; // r5
  unsigned __int16 v6; // r21
  int v7; // r28
  unsigned __int16 v9; // r5
  int v10; // r29
  unsigned __int16 v11; // r10
  unsigned __int64 v12; // r27
  int v13; // r24
  char *v14; // r3
  int v15; // r4
  char *v16; // r28
  bool v17; // zf
  const unsigned __int8 *readp; // r11
  unsigned int v19; // r25
  int v20; // r7
  int v21; // r26
  const unsigned __int8 *endp; // r6
  const unsigned __int8 *v23; // r5
  int v24; // r20
  unsigned __int64 v25; // r10
  int v26; // r8
  int v27; // r7
  const unsigned __int8 *Data; // r3
  int *buffer; // r30
  int *v30; // r4
  int *v31; // r8
  int v32; // r7
  int i; // ctr
  int j; // r11
  int v35; // r10
  int v36; // r9
  char *v37; // r10
  char *v38; // r9
  unsigned __int64 v39; // r10
  const unsigned __int8 *v40; // r26
  int v41; // r25
  int v42; // r8
  int v43; // r7
  int v44; // r6
  int v45; // r5
  const unsigned __int8 *v46; // r3
  int v47; // r8
  int k; // ctr
  int m; // r11
  int v50; // r9
  char *v51; // r10
  int v52; // r7
  idTempArray<int> v53[14]; // [sp+50h] [-70h] BYREF

  LODWORD(v2) = 0;
  v4 = bitstream->readp + 2;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  bitstream->readp = v4;
  v5 = __ROL4__(*(v4 - 1), 8) | *(v4 - 2);
  bitstream->currentBit = v2;
  v6 = v5;
  bitstream->currentByte = v2;
  v7 = *v4;
  bitstream->readp = v4 + 3;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  v9 = __ROL4__(v4[2], 8) | v4[1];
  bitstream->readp = v4 + 5;
  v10 = v9;
  bitstream->currentBit = v2;
  bitstream->currentByte = v2;
  v11 = __ROL4__(v4[4], 8) | v4[3];
  HIDWORD(v12) = v9 * v11;
  v13 = v11;
  v14 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\engine\\guis\\swf\\SWF_Image.cpp(525) : TAG_SWF",
                  size: 4 * HIDWORD(v12),
                  tag: TAG_SWF,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v15 = v7;
  v17 = v7 != 3;
  v16 = v14;
  if ( !v17 )
  {
    readp = bitstream->readp;
    bitstream->currentBit = v12;
    bitstream->currentByte = v12;
    v19 = (v10 + 3) & 0xFFFFFFFC;
    v20 = *readp + 1;
    bitstream->readp = readp + 1;
    v21 = v20;
    idTempArray<char>::idTempArray<char>(this: (idTempArray<char> *)v53, num: v13 * v19 + 4 * v20);
    endp = bitstream->endp;
    v23 = bitstream->readp;
    v24 = endp - v23;
    Data = idSWFBitStream::ReadData(
             this: bitstream,
             size: endp - v23,
             a3: (int)v23,
             a4: (int)endp,
             a5: v27,
             a6: v26,
             a7: v25);
    buffer = v53[0].buffer;
    if ( !idSWF::Inflate(
            this,
            input: Data,
            inputSize: v24,
            output: (unsigned __int8 *)v53[0].buffer,
            outputSize: v53[0].num) )
    {
      idLib::Warning(fmt: "DefineBitsLossless2: Failed to inflate color map data");
      idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
      if ( buffer == nullptr )
        return;
      v30 = buffer;
      goto LABEL_25;
    }
    v31 = &buffer[v21];
    if ( v13 > 0 )
    {
      v32 = 0;
      for ( i = v13; i != 0; --i )
      {
        for ( j = 0; j < v10; v38[3] = v37[3] )
        {
          v35 = __ROL4__(*((unsigned __int8 *)v31 + j), 2);
          v36 = 4 * (v32 + j++);
          v37 = (char *)buffer + v35;
          v38 = &v16[v36];
          *v38 = *v37;
          v38[1] = v37[1];
          v38[2] = v37[2];
        }
        v31 = (int *)((char *)v31 + v19);
        v32 += v10;
      }
    }
    if ( buffer != nullptr )
LABEL_11:
      idMem::Free(this: &mem, ptr: buffer, align: ALIGN_16);
LABEL_24:
    idSWF::LoadImageA(this, characterID: v6, imageData: (const unsigned __int8 *)v16, width: v10, height: v13);
    v30 = (int *)v16;
    goto LABEL_25;
  }
  if ( v15 != 5 )
  {
    idLib::Warning(fmt: "DefineBitsLossless2: Unknown image format %d", v15);
    memset(Dst: v16, Val: 255, Size: 4 * HIDWORD(v12));
    goto LABEL_24;
  }
  idTempArray<int>::idTempArray<int>(this: v53, num: HIDWORD(v12));
  LODWORD(v39) = bitstream->readp;
  HIDWORD(v39) = v53[0].num;
  v40 = &bitstream->endp[-v39];
  v41 = 4 * v53[0].num;
  v46 = idSWFBitStream::ReadData(this: bitstream, size: (int)v40, a3: v45, a4: v44, a5: v43, a6: v42, a7: v39);
  buffer = v53[0].buffer;
  if ( idSWF::Inflate(this, input: v46, inputSize: (int)v40, output: (unsigned __int8 *)v53[0].buffer, outputSize: v41) )
  {
    if ( v13 > 0 )
    {
      v47 = 0;
      for ( k = v13; k != 0; --k )
      {
        for ( m = 0; m < v10; v51[3] = HIBYTE(v52) )
        {
          v50 = 4 * (v47 + m++);
          v51 = &v16[v50];
          v52 = buffer[v50 / 4u];
          v16[v50] = BYTE1(v52);
          *(_WORD *)(v51 + 1) = v52;
        }
        v47 += v10;
      }
    }
    if ( buffer == nullptr )
      goto LABEL_24;
    goto LABEL_11;
  }
  idLib::Warning(fmt: "DefineBitsLossless2: Failed to inflate bitmap data");
  idMem::Free(this: &mem, ptr: v16, align: ALIGN_16);
  if ( buffer == nullptr )
    return;
  v30 = buffer;
LABEL_25:
  idMem::Free(this: &mem, ptr: v30, align: ALIGN_16);
}


// ========================================================================
// __unwind$222817_0
// EA  : 0x827735F8
// RVA : 0x007735F8
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222817_0()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$222818
// EA  : 0x82773620
// RVA : 0x00773620
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void _unwind_222818()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 192 + 80));
}


// ========================================================================
// `dynamic initializer for 'swf_imageCompressor''
// EA  : 0x833417A8
// RVA : 0x013417A8
// PDB : w:\tech5\engine\guis\swf\swf_image.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__swf_imageCompressor__()
{
  idCVar::idCVar(
    this: &swf_imageCompressor,
    name: "swf_imageCompressor",
    value: "1",
    flags: 2,
    description: "1 = extremely slow high quality compressor",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__swf_imageCompressor__);
}

