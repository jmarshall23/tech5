
// ========================================================================
// ?Job@HQDXTjob_t@@SAXPAX@Z
// EA  : 0x828A4C78
// RVA : 0x008A4C78
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void __fastcall HQDXTjob_t::Job(_DWORD *parm)
{
  _OWORD *v1; // r30
  int v2; // r31
  int v3; // r10
  unsigned __int8 *v4; // r5
  idDxtEncoder v5; // [sp+50h] [-80h] BYREF
  _QWORD v6[12]; // [sp+70h] [-60h] BYREF

  v1 = (_OWORD *)parm[2];
  *(_OWORD *)v6 = *v1;
  v2 = parm[3];
  *(_OWORD *)&v6[2] = *(_OWORD *)((char *)v1 + v2);
  *(_OWORD *)&v6[4] = *(_OWORD *)((char *)v1 + 2 * v2);
  *(_OWORD *)&v6[6] = *(_OWORD *)((char *)v1 + 3 * v2);
  v3 = *((unsigned __int8 *)parm + 20);
  v4 = (unsigned __int8 *)parm[4];
  v5.dstPadding = 0;
  v5.srcPadding = 0;
  if ( v3 != 0 )
    idDxtEncoder::CompressNormalMapDXT5HQ(
      this: &v5,
      inBuf: (const unsigned __int8 *)v6,
      outBuf: v4,
      width: 4,
      height: 4);
  else
    idDxtEncoder::CompressImageDXT5HQ(this: &v5, inBuf: (const unsigned __int8 *)v6, outBuf: v4, width: 4, height: 4);
}


// ========================================================================
// ?WriteGeneratedFile@idBinaryImage@@QAAXPBD@Z
// EA  : 0x828A4DF8
// RVA : 0x008A4DF8
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void __fastcall idBinaryImage::WriteGeneratedFile(idBinaryImage *this, const char *binaryFileName)
{
  int v4; // r28
  int v5; // r27
  idBinaryImage::idBinaryImageData *v6; // r29
  int v7; // r28
  idImageData *ImageData; // r29
  __int64 v9; // r8
  __int64 v10; // r10
  va *v11; // r3
  unsigned __int8 *data; // r4
  float *floatData; // r4
  int v14; // [sp+8h] [-1208h]
  int v15; // [sp+Ch] [-1204h]
  int v16; // [sp+10h] [-1200h]
  int v17; // [sp+14h] [-11FCh]
  int v18; // [sp+18h] [-11F8h]
  int v19; // [sp+1Ch] [-11F4h]
  idFileLocal v20; // [sp+50h] [-11C0h] BYREF
  _BYTE v21[4]; // [sp+54h] [-11BCh] BYREF
  int v22; // [sp+58h] [-11B8h] BYREF
  idStr v23; // [sp+60h] [-11B0h] BYREF
  idImage v24; // [sp+80h] [-1190h] BYREF
  va v25; // [sp+1D0h] [-1040h] BYREF

  v20.file = (idFile *)((int (__fastcall *)(idFileSystem *))fileSystem->OpenFileWrite)(a1: fileSystem);
  if ( v20.file == nullptr )
    idLib::Warning(fmt: "idBinaryImage: Could not open file '%s'", binaryFileName);
  idLib::Printf(fmt: "Writing %s\n", binaryFileName);
  v21[0] = 0;
  v20.file->Write(this: v20.file, a2: &this->sourceFileTime, a3: 4u);
  v22 = 122505538;
  v20.file->Write(this: v20.file, a2: &v22, a3: 4u);
  v20.file->Write(this: v20.file, a2: &this->opts, a3: 4u);
  v20.file->Write(this: v20.file, a2: &this->opts.width, a3: 4u);
  v20.file->Write(this: v20.file, a2: &this->opts.height, a3: 4u);
  v20.file->Write(this: v20.file, a2: &this->opts.depth, a3: 4u);
  v20.file->Write(this: v20.file, a2: &this->opts.numLevels, a3: 4u);
  v20.file->Write(this: v20.file, a2: &this->opts.cubeFilter, a3: 1u);
  v20.file->Write(this: v20.file, a2: &this->opts.format, a3: 4u);
  v20.file->Write(this: v20.file, a2: &this->opts.filter, a3: 4u);
  v20.file->Write(this: v20.file, a2: &this->opts.repeat, a3: 4u);
  v20.file->Write(this: v20.file, a2: v21, a3: 1u);
  v4 = 0;
  if ( this->images.num > 0 )
  {
    v5 = 0;
    do
    {
      v6 = &this->images.list[v5];
      v20.file->Write(this: v20.file, a2: v6, a3: 4u);
      v20.file->Write(this: v20.file, a2: &v6->destZ, a3: 4u);
      v20.file->Write(this: v20.file, a2: &v6->width, a3: 4u);
      v20.file->Write(this: v20.file, a2: &v6->height, a3: 4u);
      v20.file->Write(this: v20.file, a2: &v6->dataSize, a3: 4u);
      v20.file->Write(this: v20.file, a2: v6->data.list, a3: v6->dataSize);
      ++v4;
      ++v5;
    }
    while ( v4 < this->images.num );
  }
  this->binaryFileTime = fileSystem->GetTimestamp(this: fileSystem, a2: binaryFileName, a3: false);
  if ( image_binaryImageDebugSaveTGA.valueInteger != 0 )
  {
    idStr::idStr(this: &v23, text: binaryFileName);
    idStr::StripFileExtension(this: &v23);
    v7 = 0;
    if ( this->images.num > 0 )
    {
      while ( 1 )
      {
        idImage::idImage(this: &v24);
        idImage::LoadFromBinaryImage(this: &v24, im: this);
        ImageData = idImage::GetImageData(this: &v24, mipLevel: v7, z: 0);
        HIDWORD(v9) = this->images.num;
        v11 = va::va(
                this: &v25,
                fmt: "%s_%d_%d.tga",
                a3: __SPAIR64__((unsigned int)v23.data, v7),
                a4: v9,
                a5: v10,
                a6: v14,
                a7: v15,
                a8: v16,
                a9: v17,
                a10: v18,
                a11: v19);
        idImageData::WriteTGA(this: ImageData, filename: v11->buffer);
        if ( ImageData != nullptr )
        {
          data = ImageData->data;
          if ( data != nullptr )
            idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
          floatData = ImageData->floatData;
          if ( floatData != nullptr )
            idMem::Free(this: &mem, ptr: floatData, align: ALIGN_16);
          idMem::Free(this: &mem, ptr: ImageData, align: ALIGN_16);
        }
        if ( image_binaryImageDebugSaveTGA.valueInteger == 1 )
          break;
        idImage::~idImage(this: &v24);
        if ( ++v7 >= this->images.num )
          goto LABEL_18;
      }
      idImage::~idImage(this: &v24);
    }
LABEL_18:
    idStr::FreeData(this: &v23);
  }
  idFileLocal::~idFileLocal(this: &v20);
}


// ========================================================================
// __unwind$231644
// EA  : 0x828A51DC
// RVA : 0x008A51DC
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void _unwind_231644()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 4624 + 80));
}


// ========================================================================
// __unwind$231645
// EA  : 0x828A5204
// RVA : 0x008A5204
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void _unwind_231645()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4624 + 96));
}


// ========================================================================
// __unwind$231646
// EA  : 0x828A522C
// RVA : 0x008A522C
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void _unwind_231646()
{
  int v0; // r12

  idImage::~idImage(this: (idImage *)(v0 - 4624 + 128));
}


// ========================================================================
// ?JobParallelHQDXTCompress@@YAXPBXPAXHH_N@Z
// EA  : 0x828A54A8
// RVA : 0x008A54A8
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void __fastcall JobParallelHQDXTCompress(char *src, char *dst, int width, int height, bool normalMap)
{
  int v10; // r30
  idParallelJobList *v11; // r3
  idParallelJobList *v12; // r24
  int size; // r11
  idSWF::imageToPack_t *list; // r20
  int v15; // r29
  int v16; // r25
  int v17; // r27
  int i; // r30
  int v19; // r11
  idSWF::imageToPack_t *v20; // r5
  idList<idSWF::imageToPack_t,72> v21[9]; // [sp+50h] [-90h] BYREF

  v10 = width / 4 * height / 4;
  RegisterJob(function: (void (__fastcall *)(void *))HQDXTjob_t::Job, name: "HQDXTjob");
  v11 = parallelJobManager->AllocJobList(
          this: parallelJobManager,
          a2: 9,
          a3: 2,
          a4: width / 4 * height / 4,
          a5: 1,
          a6: &idColor::colorRed);
  memset(v21, 0, 14);
  v12 = v11;
  v21[0].memTag = 34;
  v21[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v21);
  size = v21[0].size;
  if ( v10 > v21[0].size )
  {
    if ( !idList<HQDXTjob_t,34>::Resize(this: v21, newsize: v10) )
      goto LABEL_6;
    size = v21[0].size;
  }
  v21[0].num = v10;
  if ( v10 >= size )
    v21[0].num = size;
LABEL_6:
  list = v21[0].list;
  v15 = 0;
  if ( height > 0 )
  {
    v16 = 4 * width;
    v17 = 0;
    do
    {
      for ( i = 0; i < width; i += 4 )
      {
        v19 = ((unsigned int)i >> 2) + (int)(((unsigned int)v15 >> 2) * width) / 4;
        v20 = &list[v19];
        v20->characterID = i;
        v20->trueSize.x = v15;
        v20->allocSize.x = (int)&dst[16 * v19];
        v20->trueSize.y = (int)&src[4 * v17 + 4 * i];
        HIBYTE(v20->allocSize.y) = normalMap;
        v20->imageData = (unsigned __int8 *)v16;
        idParallelJobList::AddJob(this: v12, function: (void (__fastcall *)(void *))HQDXTjob_t::Job, data: v20);
      }
      v15 += 4;
      v17 += v16;
    }
    while ( v15 < height );
  }
  idParallelJobList::Submit(this: v12, waitForJobList: nullptr, parallelism: -2);
  idParallelJobList::Wait(this: v12);
  parallelJobManager->FreeJobList(this: parallelJobManager, a2: v12);
  if ( (v21[0].listStatic == 0 || v21[0].listStatic == 2) && list != nullptr )
    idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
}


// ========================================================================
// __unwind$232068_0
// EA  : 0x828A5694
// RVA : 0x008A5694
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void _unwind_232068_0()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 224 + 80));
}


// ========================================================================
// ?TestJobParallelHQDXTCompress_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828A56C8
// RVA : 0x008A56C8
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void __fastcall TestJobParallelHQDXTCompress_f(const idCmdArgs *args)
{
  int argc; // r11
  const char *v3; // r3
  char *v4; // r30
  const char *v5; // r4
  char *v6; // [sp+50h] [-70h] BYREF
  int v7; // [sp+54h] [-6Ch] BYREF
  int v8; // [sp+58h] [-68h] BYREF
  idDxtDecoder v9; // [sp+60h] [-60h] BYREF
  idStr v10[2]; // [sp+70h] [-50h] BYREF

  argc = args->argc;
  v8 = args->argc;
  if ( v8 == 2 )
  {
    if ( argc <= 1 )
      v3 = &byte_8200D768;
    else
      v3 = args->argv[1];
    R_LoadImage(cname: v3, pic: (unsigned __int8 **)&v6, width: &v8, height: &v7, timestamp: nullptr);
    if ( v6 != nullptr )
    {
      v4 = (char *)idMem::AllocWithLocation(
                     this: &mem,
                     location: "w:\\tech5\\engine\\renderer\\BinaryImage.cpp(176) : TAG_IMAGE",
                     size: v8 * v7,
                     tag: TAG_IMAGE,
                     zeroBuffer: false,
                     align: ALIGN_16,
                     heap: HEAP_DEFAULTHEAP);
      JobParallelHQDXTCompress(src: v6, dst: v4, width: v8, height: v7, normalMap: false);
      idDxtDecoder::DecompressImageDXT5(
        this: &v9,
        inBuf: (const unsigned __int8 *)v4,
        outBuf: (unsigned __int8 *)v6,
        width: v8,
        height: v7);
      if ( args->argc <= 1 )
        v5 = &byte_8200D768;
      else
        v5 = args->argv[1];
      idStr::idStr(this: v10, text: v5);
      idStr::StripFileExtension(this: v10);
      idStr::Append(this: v10, text: "_.tga");
      R_WriteTGA(
        filename: v10[0].data,
        data: (const unsigned __int8 *)v6,
        width: v8,
        height: v7,
        depth: 4,
        flipVertical: false,
        swapRGB: true,
        basePath: FSPATH_BASE);
      idMem::Free(this: &mem, ptr: v4, align: ALIGN_16);
      idMem::Free(this: &mem, ptr: v6, align: ALIGN_16);
      idStr::FreeData(this: v10);
    }
  }
  else
  {
    idLib::Printf(fmt: "Usage: TestJobParallelHQDXTCompress <tgafile>\n");
  }
}


// ========================================================================
// __unwind$232152
// EA  : 0x828A582C
// RVA : 0x008A582C
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void _unwind_232152()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 112));
}


// ========================================================================
// ?Load2DFromMemory@idBinaryImage@@QAAXHHPBE@Z
// EA  : 0x828A5C68
// RVA : 0x008A5C68
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void __fastcall idBinaryImage::Load2DFromMemory(
        idBinaryImage *this,
        unsigned int width,
        unsigned int height,
        const unsigned __int8 *pic_const)
{
  int v4; // r31
  unsigned int v6; // r27
  __int64 v7; // r30
  unsigned __int8 *v9; // r19
  textureColor_t colorFormat; // r11
  unsigned __int8 *v11; // r11
  int i; // ctr
  int v13; // r8
  int v14; // r6
  unsigned __int8 v15; // r7
  int v16; // r10
  int v17; // r9
  int v18; // r10
  char v19; // r7
  int v20; // r10
  int v21; // r10
  unsigned __int8 *v22; // r11
  int j; // ctr
  textureFormat_t v24; // r11
  int v25; // r23
  int v26; // r22
  int numLevels; // r31
  int size; // r11
  int k; // r20
  textureFormat_t format; // r11
  unsigned __int8 *v31; // r21
  unsigned int v32; // r25
  idBinaryImage::idBinaryImageData *v33; // r31
  unsigned __int8 *v34; // r3
  unsigned __int8 *v35; // r27
  unsigned __int8 *v36; // r28
  int v37; // r11
  unsigned __int8 *list; // r5
  int v39; // r11
  textureColor_t v40; // r11
  unsigned __int8 *v41; // r5
  int v42; // r11
  int v43; // r11
  unsigned __int8 *v44; // r10
  int v45; // r11
  int v46; // r9
  int v47; // r11
  unsigned __int8 *v48; // r10
  int v49; // r11
  int v50; // r9
  int v51; // r11
  unsigned __int8 *v52; // r10
  int v53; // r6
  int v54; // r3
  int v55; // r11
  __int64 v56; // r8
  int v57; // r10
  int v58; // r10
  int v59; // ctr
  __int64 v60; // r9
  int m; // r11
  int v62; // r11
  int v63; // r11
  unsigned __int8 *v64; // r10
  unsigned __int8 *v65; // r3
  unsigned __int8 *v66; // r4
  int v67; // r11
  bool v68; // zf
  int v69; // r11
  idDxtEncoder v70; // [sp+80h] [-D0h] BYREF
  idDxtEncoder v71[8]; // [sp+A0h] [-B0h] BYREF

  v4 = width * height;
  v6 = 4 * width * height;
  v7 = __PAIR64__(height, width);
  v9 = (unsigned __int8 *)idMem::AllocWithLocation(
                            this: &mem,
                            location: "w:\\tech5\\engine\\renderer\\BinaryImage.cpp(200) : TAG_IMAGE",
                            size: v6,
                            tag: TAG_IMAGE,
                            zeroBuffer: false,
                            align: ALIGN_16,
                            heap: HEAP_DEFAULTHEAP);
  memcpy(Dst: v9, Src: pic_const, Size: v6);
  colorFormat = this->opts.colorFormat;
  if ( colorFormat == CFM_YCOCG_DXT5 )
  {
    idColorSpace::ConvertRGBToCoCg_Y(dst: v9, src: v9, width: v7, height: SHIDWORD(v7));
  }
  else if ( (colorFormat == CFM_YCOCGA_DXT5 || colorFormat == CFM_YCOCGA_HQ_DXT5) && v4 > 0 )
  {
    v11 = v9 - 1;
    for ( i = v4; i != 0; --i )
    {
      v13 = v11[1];
      v14 = v11[3];
      v15 = v11[4];
      v16 = ((2 * (v13 + 1) - __ROL4__(v14, 1)) >> 2) + 132;
      if ( v16 >= 0 )
      {
        if ( v16 > 255 )
          LOBYTE(v16) = -1;
      }
      else
      {
        LOBYTE(v16) = 0;
      }
      v17 = 2 * v11[2];
      v11[1] = v16;
      v11[2] = v15;
      v18 = ((v17 - v14 - v13 + 2) >> 2) + 132;
      if ( v18 >= 0 )
      {
        v19 = -1;
        if ( v18 <= 255 )
          v19 = ((v17 - v14 - v13 + 2) >> 2) - 124;
      }
      else
      {
        v19 = 0;
      }
      v11[3] = v19;
      v20 = (v17 + v14 + v13 + 2) >> 2;
      if ( v20 >= 0 )
      {
        if ( v20 > 255 )
          LOBYTE(v20) = -1;
      }
      else
      {
        LOBYTE(v20) = 0;
      }
      v11 += 4;
      *v11 = v20;
    }
  }
  if ( this->opts.format == FMT_NONE )
  {
    LOBYTE(v21) = -1;
    if ( v4 <= 0 )
      goto LABEL_25;
    v22 = v9 - 1;
    for ( j = v4; j != 0; --j )
    {
      v22 += 4;
      v21 = (unsigned __int8)(*v22 & v21);
    }
    if ( v21 == 255 )
LABEL_25:
      v24 = FMT_DXT1;
    else
      v24 = FMT_DXT5;
    this->opts.format = v24;
  }
  this->opts.width = v7;
  this->opts.height = HIDWORD(v7);
  v25 = HIDWORD(v7);
  v26 = v7;
  ComputeNumLevels(opts: &this->opts, name: this->imgName.data);
  numLevels = this->opts.numLevels;
  if ( numLevels <= this->images.size
    || (unsigned __int8)idList<idBinaryImage::idBinaryImageData,34>::Resize(
                          this: &this->images,
                          newsize: this->opts.numLevels) != 0 )
  {
    size = this->images.size;
    if ( numLevels < size )
      size = numLevels;
    this->images.num = size;
  }
  for ( k = 0; k < this->images.num; ++k )
  {
    format = this->opts.format;
    v31 = v9;
    LODWORD(v7) = 0;
    v32 = 0;
    v33 = &this->images.list[k];
    if ( format != FMT_DXT5 && format != FMT_DXT1 )
      goto LABEL_51;
    if ( (v26 & 3) != 0 || (v25 & 3) != 0 )
    {
      LODWORD(v7) = (v26 + 3) & 0xFFFFFFFC;
      v32 = (v25 + 3) & 0xFFFFFFFC;
      v34 = (unsigned __int8 *)idMem::AllocWithLocation(
                                 this: &mem,
                                 location: "w:\\tech5\\engine\\renderer\\BinaryImage.cpp(283) : TAG_IMAGE",
                                 size: 4 * v32 * v7,
                                 tag: TAG_IMAGE,
                                 zeroBuffer: true,
                                 align: ALIGN_16,
                                 heap: HEAP_DEFAULTHEAP);
      v31 = v34;
      if ( v25 > 0 )
      {
        v35 = v34;
        v36 = v9;
        HIDWORD(v7) = v25;
        do
        {
          memcpy(Dst: v35, Src: v36, Size: 4 * v26);
          --HIDWORD(v7);
          v36 += 4 * v26;
          v35 += 4 * v7;
        }
        while ( HIDWORD(v7) != 0 );
      }
    }
    else
    {
      v31 = v9;
      LODWORD(v7) = v26;
      v32 = v25;
    }
    format = this->opts.format;
    if ( format == FMT_DXT1 )
    {
      v71[0].dstPadding = 0;
      v71[0].srcPadding = 0;
      v33->level = k;
      v33->width = v26;
      v33->height = v25;
      v33->destZ = 0;
      HIDWORD(v7) = (int)(v32 * v7) / 2;
      v33->dataSize = HIDWORD(v7);
      if ( SHIDWORD(v7) <= v33->data.size
        || (unsigned __int8)idList<unsigned char,25>::Resize(
                              this: (idList<unsigned char,37> *)&v33->data,
                              newsize: (int)(v32 * v7) / 2) != 0 )
      {
        v37 = v33->data.size;
        if ( SHIDWORD(v7) < v37 )
          v37 = (int)(v32 * v7) / 2;
        v33->data.num = v37;
      }
      list = v33->data.list;
      if ( this->opts.colorFormat == CFM_HQ_DXT1 )
        idDxtEncoder::CompressImageDXT1HQ(this: v71, inBuf: v31, outBuf: list, width: v7, height: v32);
      else
        idDxtEncoder::CompressImageDXT1Fast_Xenon(this: v71, inBuf: v31, outBuf: list, width: v7, height: v32);
    }
    else
    {
LABEL_51:
      switch ( format )
      {
        case FMT_DXT5:
          v70.dstPadding = 0;
          v70.srcPadding = 0;
          v33->level = k;
          v33->width = v26;
          v33->height = v25;
          v33->dataSize = v32 * v7;
          v33->destZ = 0;
          HIDWORD(v7) = &v33->data;
          if ( (signed int)(v32 * v7) <= v33->data.size
            || (unsigned __int8)idList<unsigned char,25>::Resize(
                                  this: (idList<unsigned char,37> *)&v33->data,
                                  newsize: v32 * v7) != 0 )
          {
            v39 = v33->data.size;
            if ( (int)(v32 * v7) < v39 )
              v39 = v32 * v7;
            v33->data.num = v39;
          }
          v40 = this->opts.colorFormat;
          if ( v40 == CFM_HQ_DXT5 || v40 == CFM_YCOCGA_HQ_DXT5 )
          {
            idLib::Printf(
              fmt: "Image %s uses high quality compression, writing generated will take additional time\n",
              this->imgName.data);
            if ( r_parallelHQDXTEncode.valueInteger != 0 )
              JobParallelHQDXTCompress(
                src: (char *)v31,
                dst: *(char **)HIDWORD(v7),
                width: v7,
                height: v32,
                normalMap: false);
            else
              idDxtEncoder::CompressImageDXT5HQ(
                this: &v70,
                inBuf: v31,
                outBuf: *(unsigned __int8 **)HIDWORD(v7),
                width: v7,
                height: v32);
          }
          else if ( v40 == CFM_HQ_NORMAL_DXT5 )
          {
            idLib::Printf(
              fmt: "Image %s uses high quality compression, writing generated will take additional time\n",
              this->imgName.data);
            if ( r_parallelHQDXTEncode.valueInteger != 0 )
              JobParallelHQDXTCompress(
                src: (char *)v31,
                dst: *(char **)HIDWORD(v7),
                width: v7,
                height: v32,
                normalMap: true);
            else
              idDxtEncoder::CompressNormalMapDXT5HQ(
                this: &v70,
                inBuf: v31,
                outBuf: *(unsigned __int8 **)HIDWORD(v7),
                width: v7,
                height: v32);
          }
          else
          {
            v41 = *(unsigned __int8 **)HIDWORD(v7);
            if ( v40 == CFM_YCOCG_DXT5 )
            {
              idDxtEncoder::CompressYCoCgDXT5Fast_Xenon(this: &v70, inBuf: v31, outBuf: v41, width: v7, height: v32);
            }
            else if ( v40 == CFM_YCOCGA_DXT5 )
            {
              idDxtEncoder::CompressYCoCgAlphaDXT5Fast(this: &v70, inBuf: v31, outBuf: v41, width: v7, height: v32);
            }
            else
            {
              idDxtEncoder::CompressImageDXT5Fast_Xenon(this: &v70, inBuf: v31, outBuf: v41, width: v7, height: v32);
            }
          }
          break;
        case FMT_LUM8:
        case FMT_INT8:
          v33->level = k;
          v33->width = v26;
          v33->dataSize = v25 * v26;
          v33->height = v25;
          v33->destZ = 0;
          HIDWORD(v7) = &v33->data;
          if ( v25 * v26 <= v33->data.size
            || (unsigned __int8)idList<unsigned char,25>::Resize(
                                  this: (idList<unsigned char,37> *)&v33->data,
                                  newsize: v25 * v26) != 0 )
          {
            v62 = v33->data.size;
            if ( v25 * v26 < v62 )
              v62 = v25 * v26;
            v33->data.num = v62;
          }
          v63 = 0;
          if ( v33->data.num > 0 )
          {
            v64 = v9 - 4;
            do
            {
              v64 += 4;
              *(_BYTE *)(*(_DWORD *)HIDWORD(v7) + v63++) = *v64;
            }
            while ( v63 < v33->data.num );
          }
          break;
        case FMT_ALPHA:
          v33->level = k;
          v33->width = v26;
          v33->height = v25;
          v33->dataSize = v25 * v26;
          v33->destZ = 0;
          HIDWORD(v7) = &v33->data;
          if ( v25 * v26 <= v33->data.size
            || (unsigned __int8)idList<unsigned char,25>::Resize(
                                  this: (idList<unsigned char,37> *)&v33->data,
                                  newsize: v25 * v26) != 0 )
          {
            v42 = v33->data.size;
            if ( v25 * v26 < v42 )
              v42 = v25 * v26;
            v33->data.num = v42;
          }
          v43 = 0;
          if ( v33->data.num > 0 )
          {
            v44 = v9 - 1;
            do
            {
              v44 += 4;
              *(_BYTE *)(*(_DWORD *)HIDWORD(v7) + v43++) = *v44;
            }
            while ( v43 < v33->data.num );
          }
          break;
        case FMT_L8A8:
          v33->destZ = 0;
          v33->level = k;
          v33->width = v26;
          v33->height = v25;
          HIDWORD(v7) = 2 * v25 * v26;
          LODWORD(v7) = &v33->data;
          v33->dataSize = HIDWORD(v7);
          if ( SHIDWORD(v7) <= v33->data.size
            || (unsigned __int8)idList<unsigned char,25>::Resize(
                                  this: (idList<unsigned char,37> *)&v33->data,
                                  newsize: 2 * v25 * v26) != 0 )
          {
            v45 = v33->data.size;
            if ( SHIDWORD(v7) < v45 )
              v45 = 2 * v25 * v26;
            v33->data.num = v45;
          }
          v46 = 0;
          if ( v33->data.num / 2 > 0 )
          {
            v47 = 0;
            v48 = v9 - 1;
            do
            {
              ++v46;
              *(_BYTE *)(v47 + *(_DWORD *)v7) = v48[1];
              v48 += 4;
              *(_BYTE *)(v47 + *(_DWORD *)v7 + 1) = *v48;
              v47 += 2;
            }
            while ( v46 < v33->data.num / 2 );
          }
          break;
        case FMT_RG8:
          v33->level = k;
          v33->destZ = 0;
          v33->width = v26;
          v33->height = v25;
          HIDWORD(v7) = 2 * v25 * v26;
          LODWORD(v7) = &v33->data;
          v33->dataSize = HIDWORD(v7);
          if ( SHIDWORD(v7) <= v33->data.size
            || (unsigned __int8)idList<unsigned char,25>::Resize(
                                  this: (idList<unsigned char,37> *)&v33->data,
                                  newsize: 2 * v25 * v26) != 0 )
          {
            v49 = v33->data.size;
            if ( SHIDWORD(v7) < v49 )
              v49 = 2 * v25 * v26;
            v33->data.num = v49;
          }
          v50 = 0;
          if ( v33->data.num / 2 > 0 )
          {
            v51 = 0;
            v52 = v9 - 3;
            do
            {
              ++v50;
              *(_BYTE *)(v51 + *(_DWORD *)v7) = v52[3];
              v53 = v51 + *(_DWORD *)v7;
              v52 += 4;
              v51 += 2;
              *(_BYTE *)(v53 + 1) = *v52;
            }
            while ( v50 < v33->data.num / 2 );
          }
          break;
        case FMT_RGBA32F:
          idBinaryImage::idBinaryImageData::Set(this: v33, l: k, z: 0, w: v26, h: v25, sz: 16 * v25 * v26);
          v54 = 4 * v25 * v26;
          v55 = 0;
          if ( v54 >= 4 )
          {
            HIDWORD(v56) = v9 + 1;
            v57 = 0;
            do
            {
              LODWORD(v56) = v9[v55];
              *(float *)&v33->data.list[v57] = (float)v56;
              LODWORD(v7) = *(unsigned __int8 *)(HIDWORD(v56) + v55);
              *(float *)&v33->data.list[v57 + 4] = (float)v7;
              LODWORD(v7) = v9[v55 + 2];
              *(float *)&v33->data.list[v57 + 8] = (float)v7;
              LODWORD(v7) = v9[v55 + 3];
              v55 += 4;
              *(float *)&v33->data.list[v57 + 12] = (float)v7;
              v57 += 16;
            }
            while ( v55 < v54 - 3 );
          }
          if ( v55 < v54 )
          {
            v58 = 4 * v55;
            v59 = v54 - v55;
            do
            {
              LODWORD(v60) = v9[v55];
              HIDWORD(v60) = v33->data.list;
              ++v55;
              *(float *)(HIDWORD(v60) + v58) = (float)v60;
              v58 += 4;
              --v59;
            }
            while ( v59 != 0 );
          }
          break;
        default:
          idBinaryImage::idBinaryImageData::Set(this: v33, l: k, z: 0, w: v26, h: v25, sz: 4 * v25 * v26);
          for ( m = 0; m < v33->data.num; ++m )
            v33->data.list[m] = v9[m];
          break;
      }
    }
    if ( v9 != v31 )
      idMem::Free(this: &mem, ptr: v31, align: ALIGN_16);
    v65 = R_MipMap(in: v9, width: v26, height: v25);
    v66 = v9;
    v9 = v65;
    idMem::Free(this: &mem, ptr: v66, align: ALIGN_16);
    v67 = v26 >> 1;
    v68 = v26 >> 1 < 1;
    v26 = 1;
    if ( !v68 )
      v26 = v67;
    v69 = v25 >> 1;
    v68 = v25 >> 1 < 1;
    v25 = 1;
    if ( !v68 )
      v25 = v69;
  }
  idMem::Free(this: &mem, ptr: v9, align: ALIGN_16);
}


// ========================================================================
// ?LoadCubeFromMemory@idBinaryImage@@QAAXHQAPBE@Z
// EA  : 0x828A65F8
// RVA : 0x008A65F8
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void __fastcall idBinaryImage::LoadCubeFromMemory(idBinaryImage *this, int width, const unsigned __int8 **pics)
{
  BOOL cubeFilter; // r11
  int v7; // r25
  int v8; // r31
  int v9; // r29
  unsigned __int8 **v10; // r30
  int i; // r26
  unsigned __int8 *v12; // r3
  idList<idBinaryImage::idBinaryImageData,34> *p_images; // r23
  int size; // r11
  int j; // r26
  int valueInteger; // r5
  textureFormat_t format; // r11
  int v18; // r30
  int v19; // r28
  const unsigned __int8 **v20; // r25
  int v21; // r11
  int v22; // r29
  int v23; // r11
  int v24; // r30
  int v25; // r28
  const unsigned __int8 **v26; // r25
  int v27; // r11
  int v28; // r29
  int v29; // r11
  int v30; // r29
  int v31; // r27
  const void **v32; // r24
  idBinaryImage::idBinaryImageData *v33; // r30
  idList<unsigned char,37> *p_data; // r28
  int v35; // r11
  int v36; // r29
  int *v37; // r30
  unsigned __int8 *v38; // r28
  int v39; // r31
  void **v40; // r30
  const unsigned __int8 **v41; // r19
  int v42; // r23
  int k; // r18
  const unsigned __int8 *v44; // r21
  int v45; // r24
  int v46; // r31
  unsigned __int8 *v47; // r25
  int v48; // r22
  char *v49; // r29
  int m; // r6
  int v51; // r11
  int n; // ctr
  int v53; // r4
  unsigned __int8 *v54; // r10
  unsigned __int8 v55; // r27
  unsigned int v56; // r9
  int v57; // r30
  const unsigned __int8 *v58; // r26
  textureFormat_t v59; // r11
  int v60; // r28
  int v61; // r11
  idList<unsigned char,37> *v62; // r29
  int v63; // r11
  int v64; // r30
  int v65; // r11
  unsigned __int8 *v66; // r30
  int v67; // [sp+4Ch] [-174h] BYREF
  unsigned __int8 *v68[8]; // [sp+50h] [-170h] BYREF
  idDxtEncoder v69; // [sp+70h] [-150h] BYREF
  idDxtEncoder v70; // [sp+90h] [-130h] BYREF
  idDxtEncoder v71; // [sp+B0h] [-110h] BYREF
  idDxtEncoder v72; // [sp+D0h] [-F0h] BYREF
  _BYTE v73[208]; // [sp+F0h] [-D0h] BYREF

  cubeFilter = this->opts.cubeFilter;
  this->opts.height = width;
  this->opts.width = width;
  if ( cubeFilter )
  {
    v7 = ((width >= 0) + ((unsigned int)width >= 0x40)) & 1;
    if ( v7 != 0 )
    {
      this->opts.height = 64;
      this->opts.width = 64;
    }
    v8 = this->opts.width;
    v9 = (char *)pics - (char *)v68;
    v10 = v68;
    for ( i = 6; i != 0; --i )
    {
      if ( v7 != 0 )
      {
        *v10 = R_ResampleTexture(
                 in: *(unsigned __int8 **)((char *)v10 + v9),
                 inwidth: width,
                 inheight: width,
                 outwidth: 64,
                 outheight: 64);
      }
      else
      {
        v12 = (unsigned __int8 *)idMem::AllocWithLocation(
                                   this: &mem,
                                   location: "w:\\tech5\\engine\\renderer\\BinaryImage.cpp(437) : TAG_IMAGE",
                                   size: 4 * v8 * v8,
                                   tag: TAG_IMAGE,
                                   zeroBuffer: false,
                                   align: ALIGN_16,
                                   heap: HEAP_DEFAULTHEAP);
        *v10 = v12;
        memcpy(Dst: v12, Src: *(unsigned __int8 **)((char *)v10 + v9), Size: 4 * v8 * v8);
      }
      ++v10;
    }
    p_images = &this->images;
    if ( this->images.size >= 30
      || (unsigned __int8)idList<idBinaryImage::idBinaryImageData,34>::Resize(this: &this->images, newsize: 30) != 0 )
    {
      size = this->images.size;
      if ( size > 30 )
        size = 30;
      this->images.num = size;
    }
    for ( j = 0; j < 5; ++j )
    {
      if ( j == 4 )
        valueInteger = 2 * r_envBlendPowerFilterSize.valueInteger;
      else
        valueInteger = r_envBlendPowerFilterSize.valueInteger;
      R_FilterCube(size: v8, data: v68, filterSize: valueInteger);
      R_BlendCubeBorders(size: v8, data: v68);
      format = this->opts.format;
      if ( format == FMT_DXT1 )
      {
        v18 = 0;
        v19 = v8 * v8 / 2;
        v20 = (const unsigned __int8 **)&v67;
        do
        {
          v21 = (int)&p_images->list[6 * j + v18];
          v22 = v21 + 20;
          *(_DWORD *)v21 = j;
          *(_DWORD *)(v21 + 4) = v18;
          *(_DWORD *)(v21 + 8) = v8;
          *(_DWORD *)(v21 + 12) = v8;
          *(_DWORD *)(v21 + 16) = v19;
          if ( v19 <= *(_DWORD *)(v21 + 28)
            || (unsigned __int8)idList<unsigned char,25>::Resize(
                                  this: (idList<unsigned char,37> *)(v21 + 20),
                                  newsize: v8 * v8 / 2) != 0 )
          {
            v23 = *(_DWORD *)(v22 + 8);
            if ( v19 < v23 )
              v23 = v8 * v8 / 2;
            *(_DWORD *)(v22 + 4) = v23;
          }
          v72.dstPadding = 0;
          v72.srcPadding = 0;
          idDxtEncoder::CompressImageDXT1Fast_Xenon(
            this: &v72,
            inBuf: *++v20,
            outBuf: *(unsigned __int8 **)v22,
            width: v8,
            height: v8);
          ++v18;
        }
        while ( v18 < 6 );
      }
      else if ( format == FMT_DXT5 )
      {
        v24 = 0;
        v25 = v8 * v8;
        v26 = (const unsigned __int8 **)&v67;
        do
        {
          v27 = (int)&p_images->list[6 * j + v24];
          v28 = v27 + 20;
          *(_DWORD *)v27 = j;
          *(_DWORD *)(v27 + 4) = v24;
          *(_DWORD *)(v27 + 8) = v8;
          *(_DWORD *)(v27 + 12) = v8;
          *(_DWORD *)(v27 + 16) = v25;
          if ( v25 <= *(_DWORD *)(v27 + 28)
            || (unsigned __int8)idList<unsigned char,25>::Resize(
                                  this: (idList<unsigned char,37> *)(v27 + 20),
                                  newsize: v8 * v8) != 0 )
          {
            v29 = *(_DWORD *)(v28 + 8);
            if ( v25 < v29 )
              v29 = v8 * v8;
            *(_DWORD *)(v28 + 4) = v29;
          }
          v71.dstPadding = 0;
          v71.srcPadding = 0;
          idDxtEncoder::CompressImageDXT5Fast_Xenon(
            this: &v71,
            inBuf: *++v26,
            outBuf: *(unsigned __int8 **)v28,
            width: v8,
            height: v8);
          ++v24;
        }
        while ( v24 < 6 );
      }
      else
      {
        v30 = 0;
        v31 = 4 * v8 * v8;
        v32 = (const void **)&v67;
        do
        {
          v33 = &p_images->list[6 * j + v30];
          p_data = (idList<unsigned char,37> *)&v33->data;
          v33->level = j;
          v33->destZ = v30;
          v33->width = v8;
          v33->height = v8;
          v33->dataSize = v31;
          if ( v31 <= v33->data.size
            || (unsigned __int8)idList<unsigned char,25>::Resize(this: p_data, newsize: 4 * v8 * v8) != 0 )
          {
            v35 = v33->data.size;
            if ( v31 < v35 )
              v35 = 4 * v8 * v8;
            v33->data.num = v35;
          }
          memcpy(Dst: p_data->list, Src: *++v32, Size: v33->data.num);
          ++v30;
        }
        while ( v30 < 6 );
      }
      v36 = 6;
      v37 = &v67;
      do
      {
        v38 = (unsigned __int8 *)v37[1];
        *++v37 = (int)R_MipMap(in: v38, width: v8, height: v8);
        idMem::Free(this: &mem, ptr: v38, align: ALIGN_16);
        --v36;
      }
      while ( v36 != 0 );
      v8 >>= 1;
    }
    v39 = 6;
    v40 = (void **)&v67;
    do
    {
      idMem::Free(this: &mem, ptr: *++v40, align: ALIGN_16);
      --v39;
    }
    while ( v39 != 0 );
  }
  else
  {
    ComputeNumLevels(opts: &this->opts, name: this->imgName.data);
    idList<idBinaryImage::idBinaryImageData,34>::SetNum(this: &this->images, newNum: 6 * this->opts.numLevels);
    v41 = pics;
    v42 = 0;
    for ( k = 0; k < 216; k += 36 )
    {
      v44 = *v41;
      v45 = 0;
      v46 = this->opts.width;
      v47 = (unsigned __int8 *)*v41;
      if ( this->opts.numLevels > 0 )
      {
        v48 = k;
        do
        {
          v49 = (char *)this->images.list + v48;
          if ( v46 >= 4 )
          {
            v57 = v46;
            v58 = v47;
          }
          else
          {
            for ( m = 0; m < 4; ++m )
            {
              __twlgei(v46 & ~(__ROL4__(m, 1) - 1), 0xFFFFFFFF);
              __twllei(v46, 0);
              v51 = 0;
              for ( n = 4; n != 0; --n )
              {
                v53 = 4 * (4 * m + v51);
                v54 = &v47[4 * m % v46 * v46 + 4 * (v51 % v46)];
                v55 = *v54;
                v56 = v46 & ~(__ROL4__(v51, 1) - 1);
                __twllei(v46, 0);
                ++v51;
                __twlgei(v56, 0xFFFFFFFF);
                v73[v53] = v55;
                v73[v53 + 1] = v54[1];
                v73[v53 + 2] = v54[2];
                v73[v53 + 3] = v54[3];
              }
            }
            v57 = 4;
            v58 = v73;
          }
          v59 = this->opts.format;
          *(_DWORD *)v49 = v45;
          *((_DWORD *)v49 + 1) = v42;
          if ( v59 == FMT_DXT1 )
          {
            *((_DWORD *)v49 + 2) = v57;
            *((_DWORD *)v49 + 3) = v57;
            v60 = v57 * v57 / 2;
            *((_DWORD *)v49 + 4) = v60;
            if ( v60 <= *((_DWORD *)v49 + 7)
              || (unsigned __int8)idList<unsigned char,25>::Resize(
                                    this: (idList<unsigned char,37> *)(v49 + 20),
                                    newsize: v57 * v57 / 2) != 0 )
            {
              v61 = *((_DWORD *)v49 + 7);
              if ( v60 < v61 )
                v61 = v57 * v57 / 2;
              *((_DWORD *)v49 + 6) = v61;
            }
            v69.dstPadding = 0;
            v69.srcPadding = 0;
            idDxtEncoder::CompressImageDXT1Fast_Xenon(
              this: &v69,
              inBuf: v58,
              outBuf: *((unsigned __int8 **)v49 + 5),
              width: v57,
              height: v57);
          }
          else if ( v59 == FMT_DXT5 )
          {
            *((_DWORD *)v49 + 2) = v57;
            *((_DWORD *)v49 + 3) = v57;
            *((_DWORD *)v49 + 4) = v57 * v57;
            v62 = (idList<unsigned char,37> *)(v49 + 20);
            if ( v57 * v57 <= v62->size
              || (unsigned __int8)idList<unsigned char,25>::Resize(this: v62, newsize: v57 * v57) != 0 )
            {
              v63 = v62->size;
              if ( v57 * v57 < v63 )
                v63 = v57 * v57;
              v62->num = v63;
            }
            v70.dstPadding = 0;
            v70.srcPadding = 0;
            idDxtEncoder::CompressImageDXT5Fast_Xenon(
              this: &v70,
              inBuf: v58,
              outBuf: v62->list,
              width: v57,
              height: v57);
          }
          else
          {
            *((_DWORD *)v49 + 2) = v46;
            *((_DWORD *)v49 + 3) = v46;
            v64 = 4 * v46 * v46;
            *((_DWORD *)v49 + 4) = v64;
            if ( v64 <= *((_DWORD *)v49 + 7)
              || (unsigned __int8)idList<unsigned char,25>::Resize(
                                    this: (idList<unsigned char,37> *)(v49 + 20),
                                    newsize: 4 * v46 * v46) != 0 )
            {
              v65 = *((_DWORD *)v49 + 7);
              if ( v64 < v65 )
                v65 = 4 * v46 * v46;
              *((_DWORD *)v49 + 6) = v65;
            }
            memcpy(Dst: *((void **)v49 + 5), Src: v47, Size: *((_DWORD *)v49 + 6));
          }
          v66 = R_MipMap(in: v47, width: v46, height: v46);
          if ( v47 != v44 )
            idMem::Free(this: &mem, ptr: v47, align: ALIGN_16);
          v46 >>= 1;
          v47 = v66;
          if ( v46 < 1 )
            v46 = 1;
          ++v45;
          v48 += 216;
        }
        while ( v45 < this->opts.numLevels );
        if ( v66 != v44 )
          idMem::Free(this: &mem, ptr: v66, align: ALIGN_16);
      }
      ++v42;
      ++v41;
    }
  }
}


// ========================================================================
// ?LoadFromGeneratedFile@idBinaryImage@@AAA_NPAVidFile@@@Z
// EA  : 0x828A6D18
// RVA : 0x008A6D18
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

int __fastcall idBinaryImage::LoadFromGeneratedFile(idBinaryImage *this, idFile *bFile)
{
  int v5; // r27
  idFile_vtbl *v6; // r11
  textureType_t textureType; // r11
  int numLevels; // r29
  idList<idBinaryImage::idBinaryImageData,34> *p_images; // r25
  int i; // r26
  idBinaryImage::idBinaryImageData *v11; // r30
  int *p_dataSize; // r28
  idList<unsigned char,37> *p_data; // r30
  int dataSize; // r29
  int size; // r11
  char v16[4]; // [sp+50h] [-50h] BYREF
  int v17; // [sp+54h] [-4Ch] BYREF

  this->binaryFileTime = bFile->Timestamp(this: bFile);
  bFile->Read(this: bFile, a2: &this->sourceFileTime, a3: 4u);
  bFile->Read(this: bFile, a2: &v17, a3: 4u);
  if ( v17 == 122505538 )
  {
    v5 = 0;
    v6 = bFile->__vftable;
    v16[0] = 0;
    v6->Read(this: bFile, a2: &this->opts, a3: 4u);
    bFile->Read(this: bFile, a2: &this->opts.width, a3: 4u);
    bFile->Read(this: bFile, a2: &this->opts.height, a3: 4u);
    bFile->Read(this: bFile, a2: &this->opts.depth, a3: 4u);
    bFile->Read(this: bFile, a2: &this->opts.numLevels, a3: 4u);
    bFile->Read(this: bFile, a2: &this->opts.cubeFilter, a3: 1u);
    bFile->Read(this: bFile, a2: &this->opts.format, a3: 4u);
    bFile->Read(this: bFile, a2: &this->opts.filter, a3: 4u);
    bFile->Read(this: bFile, a2: &this->opts.repeat, a3: 4u);
    bFile->Read(this: bFile, a2: v16, a3: 1u);
    textureType = this->opts.textureType;
    numLevels = this->opts.numLevels;
    if ( textureType == TT_CUBIC )
    {
      numLevels *= 6;
    }
    else if ( textureType == TT_3D )
    {
      numLevels *= this->opts.depth;
    }
    p_images = &this->images;
    idList<idBinaryImage::idBinaryImageData,34>::SetNum(this: &this->images, newNum: numLevels);
    if ( numLevels > 0 )
    {
      for ( i = numLevels; i != 0; --i )
      {
        v11 = &p_images->list[v5];
        bFile->Read(this: bFile, a2: v11, a3: 4u);
        bFile->Read(this: bFile, a2: &v11->destZ, a3: 4u);
        bFile->Read(this: bFile, a2: &v11->width, a3: 4u);
        bFile->Read(this: bFile, a2: &v11->height, a3: 4u);
        p_dataSize = &v11->dataSize;
        bFile->Read(this: bFile, a2: &v11->dataSize, a3: 4u);
        dataSize = v11->dataSize;
        p_data = (idList<unsigned char,37> *)&v11->data;
        if ( *p_dataSize <= p_data->size
          || (unsigned __int8)idList<unsigned char,25>::Resize(this: p_data, newsize: *p_dataSize) != 0 )
        {
          size = p_data->size;
          if ( dataSize < size )
            size = dataSize;
          p_data->num = size;
        }
        bFile->Read(this: bFile, a2: p_data->list, a3: *p_dataSize);
        ++v5;
      }
    }
    return 1;
  }
  else
  {
    idLib::Warning(fmt: "idBinaryImage::LoadFromGeneratedFile : %s has out of date magic", this->imgName.data);
    return 0;
  }
}


// ========================================================================
// ?LoadFromSourceFile@idBinaryImage@@QAA_NXZ
// EA  : 0x828A70B8
// RVA : 0x008A70B8
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

int __fastcall idBinaryImage::LoadFromSourceFile(idBinaryImage *this)
{
  unsigned __int8 *v3; // r4
  int v4; // r7
  int v5; // r5
  unsigned __int8 **v6; // r6
  int v7; // r10
  int v8; // r11
  unsigned __int8 *v9; // r8
  void **v10; // r31
  int i; // r30
  unsigned __int8 *v12; // [sp+50h] [-50h] BYREF
  unsigned int v13; // [sp+54h] [-4Ch] BYREF
  unsigned int v14; // [sp+58h] [-48h] BYREF
  unsigned __int8 *v15[16]; // [sp+60h] [-40h] BYREF

  if ( this->opts.textureType == TT_CUBIC )
  {
    if ( this->opts.cubeFilter )
    {
      this->opts.format = FMT_DXT1;
      this->opts.numLevels = 5;
      this->opts.colorFormat = CFM_HQ_DXT1;
    }
    if ( R_LoadCubeImages(
           imgName: this->imgName.data,
           pics: v15,
           outSize: (int *)&v12,
           timestamp: &this->sourceFileTime) )
    {
      v3 = v12;
      if ( this->opts.format == FMT_NONE )
      {
        v4 = (_DWORD)v12 * (_DWORD)v12;
        this->opts.format = FMT_DXT1;
        v5 = 0;
        v6 = v15;
        while ( 1 )
        {
          v7 = 0;
          if ( v4 > 0 )
            break;
LABEL_12:
          if ( this->opts.format != FMT_DXT5 )
          {
            ++v5;
            ++v6;
            if ( v5 < 6 )
              continue;
          }
          goto LABEL_16;
        }
        v8 = 0;
        v9 = *v6;
        while ( v9[3] == 255 )
        {
          ++v7;
          v8 += 4;
          v9 = &(*v6)[v8];
          if ( v7 >= v4 )
            goto LABEL_12;
        }
        this->opts.format = FMT_DXT5;
      }
LABEL_16:
      this->opts.width = (int)v3;
      this->opts.height = (int)v3;
      idBinaryImage::LoadCubeFromMemory(this, width: (int)v3, pics: (const unsigned __int8 **)v15);
      v10 = (void **)v15;
      for ( i = 6; i != 0; --i )
      {
        if ( *v10 != nullptr )
          idMem::Free(this: &mem, ptr: *v10, align: ALIGN_16);
        ++v10;
      }
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "Couldn't load cube image: %s", this->imgName.data);
      return 0;
    }
  }
  else
  {
    R_LoadImageProgram(
      name: this->imgName.data,
      pic: &v12,
      width: (int *)&v14,
      height: (int *)&v13,
      timestamps: &this->sourceFileTime);
    if ( v12 != nullptr )
    {
      idBinaryImage::Load2DFromMemory(this, width: v14, height: v13, pic_const: v12);
      idMem::Free(this: &mem, ptr: v12, align: ALIGN_16);
      return 1;
    }
    else
    {
      idLib::Warning(fmt: "Couldn't load image: %s", this->imgName.data);
      return 0;
    }
  }
}


// ========================================================================
// ?LoadFromGeneratedFile@idBinaryImage@@QAA_NPBD@Z
// EA  : 0x828A7280
// RVA : 0x008A7280
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

int __fastcall idBinaryImage::LoadFromGeneratedFile(idBinaryImage *this, const char *binaryFileName)
{
  idFile *v3; // r4
  int v5; // r30
  idFileLocal v6[2]; // [sp+50h] [-20h] BYREF

  v3 = fileSystem->OpenFileRead(this: fileSystem, a2: binaryFileName, a3: 1, a4: 0);
  v6[0].file = v3;
  if ( v3 != nullptr )
  {
    v5 = idBinaryImage::LoadFromGeneratedFile(this, bFile: v3);
    idFileLocal::~idFileLocal(this: v6);
    return v5;
  }
  else
  {
    idFileLocal::~idFileLocal(this: v6);
    return 0;
  }
}


// ========================================================================
// __unwind$233542
// EA  : 0x828A730C
// RVA : 0x008A730C
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void _unwind_233542()
{
  int v0; // r12

  idFileLocal::~idFileLocal(this: (idFileLocal *)(v0 - 112 + 80));
}


// ========================================================================
// ?WriteBinaryImage@idImage@@SAXPBDVidImageOpts@@PBEI@Z
// EA  : 0x828A7340
// RVA : 0x008A7340
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idImage::WriteBinaryImage(
        __int64 opts,
        __int64 sourceFileTime,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        const unsigned __int8 *a22,
        int a23,
        unsigned int a24)
{
  const char *v24; // r30
  idBinaryImage v25; // [sp+50h] [-1B0h] BYREF
  char v26[264]; // [sp+E0h] [-120h] BYREF

  a8 = opts;
  v24 = (const char *)HIDWORD(opts);
  a9 = *(__int64 *)((char *)&sourceFileTime + 4);
  HIDWORD(sourceFileTime) = HIDWORD(opts);
  a10 = sourceFileTime;
  a11 = *(__int64 *)((char *)&a3 + 4);
  a12 = a3;
  a13 = *(__int64 *)((char *)&a4 + 4);
  a14 = a4;
  idImage::MakeGeneratedName(binaryFileName: v26, maxLen: 256, imgName: (const char *)HIDWORD(opts));
  idBinaryImage::idBinaryImage(this: &v25, name: v24);
  idImageOpts::operator=(this: &v25.opts, __that: (const idImageOpts *)&a8);
  v25.sourceFileTime = a24;
  idBinaryImage::Load2DFromMemory(this: &v25, width: a8, height: HIDWORD(a9), pic_const: a22);
  idBinaryImage::WriteGeneratedFile(this: &v25, binaryFileName: v26);
  idBinaryImage::~idBinaryImage(this: &v25);
}


// ========================================================================
// __unwind$233570
// EA  : 0x828A73E8
// RVA : 0x008A73E8
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void _unwind_233570()
{
  int v0; // r12

  idBinaryImage::~idBinaryImage(this: (idBinaryImage *)(v0 - 512 + 80));
}


// ========================================================================
// `dynamic initializer for 'r_envBlendPowerFilterSize''
// EA  : 0x83346268
// RVA : 0x01346268
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_envBlendPowerFilterSize__()
{
  idCVar::idCVar(
    this: &r_envBlendPowerFilterSize,
    name: "r_envBlendPowerFilterSize",
    value: "0",
    flags: 4,
    description: "Radius of specular power bleeding filter",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_envBlendPowerFilterSize__);
}


// ========================================================================
// `dynamic initializer for 'r_parallelHQDXTEncode''
// EA  : 0x833462C0
// RVA : 0x013462C0
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__r_parallelHQDXTEncode__()
{
  idCVar::idCVar(
    this: &r_parallelHQDXTEncode,
    name: "r_parallelHQDXTEncode",
    value: "1",
    flags: 1,
    description: "Use parallel jobs for very slow HQ DXT encoding",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__r_parallelHQDXTEncode__);
}


// ========================================================================
// `dynamic initializer for 'TestJobParallelHQDXTCompress_v''
// EA  : 0x83346318
// RVA : 0x01346318
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestJobParallelHQDXTCompress_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestJobParallelHQDXTCompress_v,
           cmdName: "TestJobParallelHQDXTCompress",
           function: TestJobParallelHQDXTCompress_f,
           description: "compress an image",
           argCompletion: nullptr);
}


// ========================================================================
// `dynamic initializer for 'image_binaryImageDebugSaveTGA''
// EA  : 0x83346340
// RVA : 0x01346340
// PDB : w:\tech5\engine\renderer\binaryimage.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__image_binaryImageDebugSaveTGA__()
{
  idCVar::idCVar(
    this: &image_binaryImageDebugSaveTGA,
    name: "image_binaryImageDebugSaveTGA",
    value: "0",
    flags: 2,
    description: "Write an tga next to the .bimage as debug tool for intermediate results\n"
    "0: disable\n"
    "1:write first mip\n"
    "2: write all mips",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__image_binaryImageDebugSaveTGA__);
}

