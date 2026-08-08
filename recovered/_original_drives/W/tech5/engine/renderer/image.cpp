
// ========================================================================
// ?BitsForFormat@@YAHW4textureFormat_t@@@Z
// EA  : 0x828C2D30
// RVA : 0x008C2D30
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall BitsForFormat(textureFormat_t format)
{
  switch ( format )
  {
    case FMT_RGBA32F:
    case FMT_RGBA16F:
    case FMT_RGBA8:
    case FMT_ARGB8:
    case FMT_ALPHA:
    case FMT_L8A8:
    case FMT_RG8:
    case FMT_LUM8:
    case FMT_INT8:
    case FMT_DXT1:
    case FMT_DXT5:
    case FMT_DEPTH:
    case FMT_DEPTH_STENCIL:
    case FMT_X32F:
    case FMT_Y16F_X16F:
    case FMT_X16:
    case FMT_Y16_X16:
    case FMT_RGB565:
      return;
    default:
      idLib::Error(fmt: "BitsForInternalFormat: Unknown format: %d\n", format);
      break;
  }
}


// ========================================================================
// ??1idImage@@UAA@XZ
// EA  : 0x828C2DE8
// RVA : 0x008C2DE8
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall idImage::~idImage(idImage *this)
{
  this->__vftable = (idImage_vtbl *)&idImage::`vftable';
  idSWF::RemoveImgFromPurgableList(img: this);
  idImage::PurgeImage(this);
  idResource::~idResource(this: &this->idResource);
}


// ========================================================================
// __unwind$230745
// EA  : 0x828C2E40
// RVA : 0x008C2E40
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void _unwind_230745()
{
  int v0; // r12

  idResource::~idResource(this: *(idResource **)(v0 - 112 + 132));
}


// ========================================================================
// ?BitsForInternalFormat@idImage@@QBAHXZ
// EA  : 0x828C2E78
// RVA : 0x008C2E78
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall idImage::BitsForInternalFormat(idImage *this)
{
  BitsForFormat(format: this->opts.format);
}


// ========================================================================
// ?IsCompressed@idImage@@QBA_NXZ
// EA  : 0x828C2E80
// RVA : 0x008C2E80
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

int __fastcall idImage::IsCompressed(idImage *this)
{
  textureFormat_t format; // r11
  unsigned __int8 v2; // r11
  bool v3; // zf

  format = this->opts.format;
  if ( format == FMT_DXT1 )
    return 1;
  v3 = format != FMT_DXT5;
  v2 = 0;
  if ( !v3 )
    return 1;
  return v2;
}


// ========================================================================
// ?StorageSize@idImage@@QBAHXZ
// EA  : 0x828C2EA8
// RVA : 0x008C2EA8
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

int __fastcall idImage::StorageSize(idImage *this)
{
  textureType_t textureType; // r11
  int v4; // r30
  int v5; // r3
  int v6; // r10
  int numLevels; // r6
  int v8; // r9
  int v9; // r8
  int v10; // r5
  int v11; // r11
  int v12; // r10

  if ( this->d3dTexture == nullptr )
    return 0;
  textureType = this->opts.textureType;
  if ( textureType == TT_3D )
  {
    v4 = this->opts.depth * this->opts.height * this->opts.width;
  }
  else if ( textureType == TT_CUBIC )
  {
    v4 = 6 * this->opts.width * this->opts.width;
  }
  else
  {
    v4 = this->opts.height * this->opts.width;
  }
  BitsForFormat(format: this->opts.format);
  v6 = v5 * v4 / 8;
  numLevels = this->opts.numLevels;
  if ( numLevels <= 0 )
    numLevels = 1;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  if ( numLevels >= 2 )
  {
    do
    {
      v8 += v6;
      v12 = v6 >> 2;
      v11 += 2;
      v9 += v12;
      v6 = v12 >> 2;
    }
    while ( v11 < numLevels - 1 );
  }
  if ( v11 < numLevels )
    v10 = v6;
  return v9 + v8 + v10;
}


// ========================================================================
// ?ImageState@idImage@@QBA?AW4imageState_t@@XZ
// EA  : 0x828C2FB0
// RVA : 0x008C2FB0
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

int __fastcall idImage::ImageState(idImage *this)
{
  if ( this->d3dTexture == nullptr )
    return 0;
  if ( this->backgroundReadData != nullptr && this->backgroundReadComplete )
    this->backgroundReadData = nullptr;
  return ((_cntlzw((unsigned int)this->backgroundReadData) & 0x20) != 0) + 1;
}


// ========================================================================
// ?ComputeNumLevels@@YAXAAVidImageOpts@@PBD@Z
// EA  : 0x828C2FF8
// RVA : 0x008C2FF8
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall ComputeNumLevels(idImageOpts *opts, const char *name)
{
  int width; // r11
  char v3; // r11
  bool v4; // zf
  int height; // r11
  char v6; // r11
  int v7; // r10
  int v8; // r9
  int depth; // r8
  textureFormat_t format; // r11

  if ( opts->numLevels == 0 )
  {
    if ( *name != 95 )
    {
      width = opts->width;
      if ( ((width - 1) & width) != 0 || (v4 = width > 0, v3 = 1, !v4) )
        v3 = 0;
      if ( v3 == 0 )
        goto LABEL_21;
      height = opts->height;
      if ( ((height - 1) & height) != 0 || (v4 = height > 0, v6 = 1, !v4) )
        v6 = 0;
      if ( v6 == 0 )
        goto LABEL_21;
    }
    if ( opts->filter >= (unsigned int)TF_NEAREST_MIPMAP_NEAREST )
    {
      v7 = opts->width;
      v8 = opts->height;
      depth = opts->depth;
      for ( opts->numLevels = 1; v7 > 1 || v8 > 1 || depth > 1; ++opts->numLevels )
      {
        format = opts->format;
        v7 >>= 1;
        v8 >>= 1;
        depth >>= 1;
        if ( (format == FMT_DXT1 || format == FMT_DXT5) && ((v7 & 3) != 0 || (v8 & 3) != 0) )
          break;
      }
    }
    else
    {
LABEL_21:
      opts->numLevels = 1;
    }
  }
}


// ========================================================================
// ??0idImage@@QAA@XZ
// EA  : 0x828C3100
// RVA : 0x008C3100
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

idImage *__fastcall idImage::idImage(idImage *this)
{
  idResource::idResource(this: &this->idResource);
  this->__vftable = (idImage_vtbl *)&idImage::`vftable';
  this->opts.format = FMT_NONE;
  this->opts.colorFormat = CFM_DEFAULT;
  this->opts.filter = TF_DEFAULT;
  this->opts.repeat = TR_REPEAT;
  this->opts.cubeFilter = false;
  this->opts.width = 0;
  this->opts.height = 0;
  this->opts.depth = 0;
  this->opts.numLevels = 0;
  this->opts.textureType = TT_2D;
  this->opts.border.x = 0.0;
  this->opts.border.y = 0.0;
  this->opts.border.z = 0.0;
  this->opts.border.w = 0.0;
  this->opts.packedTail = true;
  this->opts.lodBias = 0.0;
  this->opts.readback = false;
  this->opts.lodMinClamp = 0.0;
  this->opts.linear = false;
  this->opts.lodMaxClamp = 13.0;
  this->opts.forceBias = false;
  this->opts.aniso = 0.0;
  this->opts.depthCompareMode = false;
  this->opts.overlayMemory = false;
  this->opts.startPurged = false;
  this->defaulted = false;
  this->optsHasBeenSet = false;
  this->allocationFailed = false;
  this->binaryFileTime = -1;
  this->sourceFileTime = -1;
  this->frameUsed = 0;
  this->bindCount = 0;
  this->physicalMemoryBytes = 0;
  this->backgroundReadComplete = true;
  this->backgroundReadData = nullptr;
  this->d3dTexture = nullptr;
  this->imageBuffer = nullptr;
  this->allocWidth = 0;
  this->allocHeight = 0;
  return this;
}


// ========================================================================
// ?DeriveNumLevels@idImage@@QAAXXZ
// EA  : 0x828C3258
// RVA : 0x008C3258
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall idImage::DeriveNumLevels(idImage *this)
{
  ComputeNumLevels(opts: &this->opts, name: this->name.str);
}


// ========================================================================
// ?LoadFromBinaryImage@idImage@@QAAXABVidBinaryImage@@@Z
// EA  : 0x828C3268
// RVA : 0x008C3268
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall idImage::LoadFromBinaryImage(idImage *this, const idBinaryImage *im)
{
  int v4; // r30
  int v5; // r29
  int v6; // [sp+8h] [-88h]

  idImage::PurgeImage(this);
  this->sourceFileTime = im->sourceFileTime;
  this->binaryFileTime = im->binaryFileTime;
  idImageOpts::operator=(this: &this->opts, __that: &im->opts);
  idImage::AllocImage(this, imgOpts: &this->opts);
  v4 = 0;
  if ( im->images.num > 0 )
  {
    v5 = 0;
    do
    {
      idImage::SubImageUpload(
        this,
        mipLevel: im->images.list[v5].level,
        destX: 0,
        destY: 0,
        destZ: im->images.list[v5].destZ,
        width: im->images.list[v5].width,
        height: im->images.list[v5].height,
        pic: im->images.list[v5].data.list,
        pixelPitch: v6);
      ++v4;
      ++v5;
    }
    while ( v4 < im->images.num );
  }
}


// ========================================================================
// ?Print@idImage@@UBAXXZ
// EA  : 0x828C3310
// RVA : 0x008C3310
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall idImage::Print(idImage *this)
{
  textureType_t textureType; // r4
  textureFilter_t filter; // r4
  textureFormat_t format; // r4
  textureRepeat_t repeat; // r4
  int v6; // r3

  if ( this->d3dTexture == nullptr )
  {
    if ( this->opts.overlayMemory )
      idLib::Printf(fmt: "<PURGED> %s %s\n", this->name.str, "(OVERLAY)");
    else
      idLib::Printf(fmt: "<PURGED> %s %s\n", this->name.str, &byte_8200D768);
    return;
  }
  if ( (*((_BYTE *)&this->idResource + 32) & 0x80) != 0 )
  {
    if ( this->defaulted )
      idLib::Printf(fmt: "D");
    else
      idLib::Printf(fmt: " ");
  }
  else
  {
    idLib::Printf(fmt: "S");
  }
  textureType = this->opts.textureType;
  if ( textureType != TT_2D )
  {
    if ( textureType == TT_3D )
    {
      idLib::Printf(fmt: "3");
    }
    else if ( (unsigned int)textureType < (TT_CUBIC|TT_3D) )
    {
      idLib::Printf(fmt: "C");
    }
    else
    {
      idLib::Printf(fmt: "<BAD TYPE:%i>", textureType);
    }
  }
  else
  {
    idLib::Printf(fmt: " ");
  }
  idLib::Printf(fmt: "%4i %4i %2i ", this->opts.width, this->opts.height, this->opts.numLevels);
  filter = this->opts.filter;
  if ( (unsigned int)filter > TF_DEFAULT )
  {
    idLib::Printf(fmt: "<BAD FILTER:%i>", filter);
  }
  else if ( filter != TF_LINEAR )
  {
    switch ( filter )
    {
      case TF_NEAREST:
        idLib::Printf(fmt: "nrst ");
        break;
      case TF_NEAREST_MIPMAP_NEAREST:
        idLib::Printf(fmt: "nmn  ");
        break;
      case TF_LINEAR_MIPMAP_NEAREST:
        idLib::Printf(fmt: "lmn  ");
        break;
      case TF_TRILINEAR_NO_ANISO:
        idLib::Printf(fmt: "xani ");
        break;
      default:
        idLib::Printf(fmt: "     ");
        break;
    }
  }
  else
  {
    idLib::Printf(fmt: "linr ");
  }
  format = this->opts.format;
  switch ( format )
  {
    case FMT_RGBA32F:
      idLib::Printf(fmt: "RGBA32   ");
      break;
    case FMT_RGBA16F:
      idLib::Printf(fmt: "RGBA16   ");
      break;
    case FMT_RGBA8:
      idLib::Printf(fmt: "RGBA8    ");
      break;
    case FMT_ARGB8:
      idLib::Printf(fmt: "ARGB8    ");
      break;
    case FMT_ALPHA:
      idLib::Printf(fmt: "A        ");
      break;
    case FMT_L8A8:
      idLib::Printf(fmt: "LA       ");
      break;
    case FMT_RG8:
      idLib::Printf(fmt: "RG       ");
      break;
    case FMT_LUM8:
      idLib::Printf(fmt: "L        ");
      break;
    case FMT_INT8:
      idLib::Printf(fmt: "I        ");
      break;
    case FMT_DXT1:
      idLib::Printf(fmt: "DXT1     ");
      break;
    case FMT_DXT5:
      idLib::Printf(fmt: "DXT5     ");
      break;
    case FMT_DEPTH:
      idLib::Printf(fmt: "D24      ");
      break;
    case FMT_DEPTH_STENCIL:
      idLib::Printf(fmt: "D24S8    ");
      break;
    case FMT_X32F:
      idLib::Printf(fmt: "X32      ");
      break;
    case FMT_Y16F_X16F:
      idLib::Printf(fmt: "Y16F_X16F");
      break;
    case FMT_X16:
      idLib::Printf(fmt: "X16      ");
      break;
    case FMT_Y16_X16:
      idLib::Printf(fmt: "Y16_X16  ");
      break;
    case FMT_RGB565:
      idLib::Printf(fmt: "RGB565   ");
      break;
    default:
      idLib::Printf(fmt: "<BAD FORMAT:%i>", format);
      break;
  }
  repeat = this->opts.repeat;
  if ( (unsigned int)repeat > TR_MIRROR )
  {
LABEL_60:
    idLib::Printf(fmt: "<BAD REPEAT:%i>", repeat);
    goto LABEL_61;
  }
  if ( repeat != TR_CLAMP )
  {
    if ( repeat != TR_CLAMP_S && repeat != TR_CLAMP_T )
    {
      if ( repeat == TR_CLAMP_TO_BORDER )
      {
        idLib::Printf(fmt: "brdr");
      }
      else if ( repeat != TR_REPEAT )
      {
        idLib::Printf(fmt: "mirr");
      }
      else
      {
        idLib::Printf(fmt: "rept");
      }
      goto LABEL_61;
    }
    goto LABEL_60;
  }
  idLib::Printf(fmt: "clmp");
LABEL_61:
  v6 = idImage::StorageSize(this);
  idLib::Printf(fmt: "%6ik ", v6 / 1024);
  idLib::Printf(fmt: "%6ik ", this->physicalMemoryBytes / 1024);
  if ( this->opts.overlayMemory )
    idLib::Printf(fmt: "(OVERLAY)");
  if ( (unsigned __int8)XGComparePixelShaders() != 0 )
    idLib::Printf(fmt: "(DIRECT ACCESS)");
  idLib::Printf(fmt: " %s\n", this->name.str);
}


// ========================================================================
// ?GetImageData@idImage@@QBAPAVidImageData@@HH@Z
// EA  : 0x828C3760
// RVA : 0x008C3760
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

idImageData *__fastcall idImage::GetImageData(idImage *this, char mipLevel, int z)
{
  int v3; // r29
  int v4; // r30
  idImageData *v5; // r3

  v3 = this->opts.width >> mipLevel;
  if ( v3 < 1 )
    v3 = 1;
  v4 = this->opts.height >> mipLevel;
  if ( v4 < 1 )
    v4 = 1;
  v5 = (idImageData *)idMem::AllocWithLocation(
                        this: &mem,
                        location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                        size: 0x10u,
                        tag: TAG_IMAGE,
                        zeroBuffer: false,
                        align: ALIGN_16,
                        heap: HEAP_DEFAULTHEAP);
  if ( v5 != nullptr )
    return idImageData::idImageData(this: v5, w: v3, h: v4);
  else
    return nullptr;
}


// ========================================================================
// __unwind$231204
// EA  : 0x828C37E8
// RVA : 0x008C37E8
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void _unwind_231204()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_IMAGE);
}


// ========================================================================
// ?BackgroundRead@idImage@@QAAXPAVidFile@@I@Z
// EA  : 0x828C3818
// RVA : 0x008C3818
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall idImage::BackgroundRead(idImage *this, idFile *file, unsigned int offset)
{
  int v6; // r3
  void *imageBuffer; // r10

  if ( this->d3dTexture == nullptr )
    idImage::AllocImage(this, imgOpts: &this->opts);
  this->backgroundReadComplete = false;
  v6 = idImage::StorageSize(this);
  imageBuffer = this->imageBuffer;
  this->backgroundReadData = imageBuffer;
  idStreamFileCache::UncachedBackgroundRead(
    this: streamFileCache,
    cacheFile: file,
    ofs: __SPAIR64__(offset, v6),
    length: (int)&this->backgroundReadData,
    dest: (void **)0x22,
    tag: (memTag_t)&this->backgroundReadComplete,
    completionFlag: (volatile bool *)imageBuffer);
  idStreamFileCache::SignalWork(this: streamFileCache);
}


// ========================================================================
// ?TestFMT_X16_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828C3950
// RVA : 0x008C3950
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall TestFMT_X16_f(const idCmdArgs *args)
{
  char *v1; // r21
  char *v2; // r10
  int v3; // r11
  int i; // ctr
  idImage *v5; // r3
  const idMaterial *v6; // r24
  idRenderModelGui *v7; // r29
  int v8; // r26
  int v9; // r25
  int v10; // r7
  unsigned __int64 v11; // r6
  __int64 v12; // r3
  __int64 v13; // r11
  int v14; // r27
  double v15; // fp29
  double v16; // fp28
  unsigned __int64 v17; // r10
  idRenderSystem_vtbl *v18; // r19
  void *v19; // r3
  int v20; // [sp+8h] [-1A8h]
  idRenderModelGui *v21; // [sp+78h] [-138h] BYREF
  idImageOpts v22; // [sp+80h] [-130h] BYREF
  idVec4 v23; // [sp+D0h] [-E0h] BYREF
  idVec4 v24; // [sp+E0h] [-D0h] BYREF
  idVec4 v25; // [sp+F0h] [-C0h] BYREF
  idVec4 v26; // [sp+100h] [-B0h] BYREF
  char *v27; // [sp+110h] [-A0h]
  int v28; // [sp+114h] [-9Ch]

  v28 = 0x10000;
  v1 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
                 size: 0x20000u,
                 tag: TAG_TEMP,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v27 = v1;
  v2 = v1 - 2;
  v3 = 0;
  for ( i = 0x10000; i != 0; --i )
  {
    v2 += 2;
    *(_WORD *)v2 = v3++;
  }
  v22.colorFormat = CFM_DEFAULT;
  v22.cubeFilter = false;
  v22.depth = 0;
  v22.numLevels = 0;
  v22.textureType = TT_2D;
  v22.packedTail = true;
  v22.readback = false;
  v22.border.x = 0.0;
  v22.linear = false;
  v22.border.y = 0.0;
  v22.forceBias = false;
  v22.border.z = 0.0;
  v22.depthCompareMode = false;
  v22.border.w = 0.0;
  v22.overlayMemory = false;
  v22.lodBias = 0.0;
  v22.startPurged = false;
  v22.lodMinClamp = 0.0;
  v22.width = 256;
  v22.lodMaxClamp = 13.0;
  v22.height = 256;
  v22.aniso = 0.0;
  v22.format = FMT_RGB565;
  v22.filter = TF_NEAREST;
  v22.repeat = TR_CLAMP;
  v5 = idImageManager::ScratchImage(this: globalImages, _name: "_testX16", imgOpts: &v22);
  idImage::SubImageUpload(
    this: v5,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: 0,
    width: 256,
    height: 256,
    pic: v1,
    pixelPitch: v20);
  v6 = (const idMaterial *)idDeclInfo::FindWithInheritance(
                             this: &idMaterial::resourceList,
                             name: "TestX16",
                             makeDefault: true);
  v21 = console->Gui(this: console);
  v7 = v21;
  v8 = renderSystem->GetWidth(this: renderSystem);
  v9 = renderSystem->GetHeight(this: renderSystem);
  LODWORD(v13) = v9;
  LODWORD(v12) = v8;
  v14 = 599;
  v15 = (float)v12;
  v16 = (float)v13;
  do
  {
    idRenderModelGui::Clear(
      this: (idRenderModelGui *)HIDWORD(defaultExtraGLState),
      a2: defaultExtraGLState,
      bits: v11,
      a4: v10);
    idRenderModelGui::DrawFilled(this: v7, color: (const idVec4 *)&idColor::colorDkGrey, x: 0.0, y: 0.0, w: v15, h: v16);
    v23.x = 0.0;
    v23.y = v16;
    v23.z = 0.0;
    v23.w = 1.0;
    v26.x = v15;
    v26.y = v16;
    v26.z = 1.0;
    v26.w = 1.0;
    v24.x = v15;
    v24.y = 0.0;
    v24.z = 1.0;
    v24.w = 0.0;
    v25.x = 0.0;
    v25.y = 0.0;
    v25.z = 0.0;
    v25.w = 0.0;
    idRenderModelGui::DrawStretchPic(
      this: v7,
      topLeft: &v25,
      topRight: &v24,
      bottomRight: &v26,
      bottomLeft: &v23,
      material: v6,
      a7: v17);
    v18 = renderSystem->__vftable;
    v19 = renderSystem->GetGameWindow(this: renderSystem);
    ((void (__fastcall *)(idRenderSystem *, void *, int, int, _DWORD, idRenderModelGui **, int, int))v18->EndFrame)(
      a1: renderSystem,
      a2: v19,
      a3: v8,
      a4: v9,
      a5: 0,
      a6: &v21,
      a7: 1,
      a8: 1);
    --v14;
  }
  while ( v14 != 0 );
  mgthread_sleep(ms: 1000);
  if ( v1 != nullptr )
    idMem::Free(this: &mem, ptr: v1, align: ALIGN_16);
}


// ========================================================================
// __unwind$231412
// EA  : 0x828C3C40
// RVA : 0x008C3C40
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void _unwind_231412()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 432 + 272));
}


// ========================================================================
// ?MakeGeneratedName@idImage@@SAXPADHPBD@Z
// EA  : 0x828C3C70
// RVA : 0x008C3C70
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall idImage::MakeGeneratedName(char *binaryFileName, int maxLen, const char *imgName)
{
  int v6; // r30
  const char **v7; // r29
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  va *v11; // r3
  int v12; // r11
  char *data; // r3
  char *v14; // r30
  char v15; // r8
  int v16; // r10
  char v17; // r9
  int v18; // r3
  int v19; // [sp+8h] [-11D8h]
  int v20; // [sp+Ch] [-11D4h]
  int v21; // [sp+10h] [-11D0h]
  int v22; // [sp+14h] [-11CCh]
  int v23; // [sp+18h] [-11C8h]
  int v24; // [sp+1Ch] [-11C4h]
  idStr v25; // [sp+50h] [-1190h] BYREF
  idStr v26; // [sp+70h] [-1170h] BYREF
  _BYTE v27[256]; // [sp+90h] [-1150h] BYREF
  va v28; // [sp+190h] [-1050h] BYREF

  if ( strstr(str1: imgName, str2: ".bimage") != nullptr )
  {
    strncpy(dest: binaryFileName, source: imgName, count: maxLen - 1);
    return;
  }
  idStr::idStr(this: &v25, text: imgName);
  idStr::GetFileExtension(this: &v26, result: &v25);
  v6 = 0;
  if ( imageExtensions[0] != nullptr )
  {
    v7 = imageExtensions;
    while ( idStr::Cmp(s1: v26.data, s2: *v7) != 0 )
    {
      v7 = &imageExtensions[++v6];
      if ( *v7 == nullptr )
        goto LABEL_9;
    }
    HIDWORD(v10) = *v7;
    v11 = va::va(
            this: &v28,
            fmt: ".%s",
            a3: v10,
            a4: v9,
            a5: v8,
            a6: v19,
            a7: v20,
            a8: v21,
            a9: v22,
            a10: v23,
            a11: v24);
    idStr::StripTrailingOnce(this: &v25, string: v11->buffer);
  }
LABEL_9:
  if ( idStr::Cmpn(s1: imgName, s2: "generated", n: 9) != 0 )
  {
    v12 = 256;
    if ( maxLen <= 256 )
      v12 = maxLen;
    data = v25.data;
    v14 = v27;
    v15 = 0;
    if ( *v25.data == 0 )
    {
_M231673_0:
      *v14 = 0;
      fileSystem->FixLongFilename(
        this: fileSystem,
        a2: "generated/textures/",
        a3: "bimage",
        a4: v27,
        a5: binaryFileName,
        a6: maxLen);
      idStr::FreeData(this: &v26);
      goto LABEL_32;
    }
    v16 = 0;
    while ( 1 )
    {
      if ( v16 > v12 - 91 )
      {
        v18 = idStr::IHash(string: data);
        v14 += idStr::snPrintf(dest: v14, size: 10, fmt: "_%8x", v18);
        goto _M231673_0;
      }
      v17 = *data;
      if ( *data >= 97 && v17 <= 122 )
        break;
      if ( v17 >= 65 && v17 <= 90 || v17 >= 48 && v17 <= 57 || v17 == 47 || v17 == 92 )
        break;
      ++data;
      if ( v15 == 0 )
      {
        *v14 = 95;
        v15 = 1;
LABEL_27:
        ++v16;
        ++v14;
      }
      if ( *data == 0 )
        goto _M231673_0;
    }
    *v14 = v17;
    v15 = 0;
    ++data;
    goto LABEL_27;
  }
  idStr::Append(this: &v25, text: ".bimage");
  strncpy(dest: binaryFileName, source: v25.data, count: maxLen - 1);
  idStr::FreeData(this: &v26);
LABEL_32:
  idStr::FreeData(this: &v25);
}


// ========================================================================
// __unwind$231616
// EA  : 0x828C3EBC
// RVA : 0x008C3EBC
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void _unwind_231616()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 80));
}


// ========================================================================
// __unwind$231617
// EA  : 0x828C3EE4
// RVA : 0x008C3EE4
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void _unwind_231617()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4576 + 112));
}


// ========================================================================
// ?ReloadIfStale@idImage@@UAA_NXZ
// EA  : 0x828C3F10
// RVA : 0x008C3F10
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

int __fastcall idImage::ReloadIfStale(idImage *this)
{
  unsigned int v3; // r3
  unsigned int binaryFileTime; // r9
  const char *str; // r3
  unsigned int v6[4]; // [sp+50h] [-130h] BYREF
  char v7[264]; // [sp+60h] [-120h] BYREF

  if ( (*((_BYTE *)&this->idResource + 32) & 0x80) == 0 )
    return 0;
  idImage::MakeGeneratedName(binaryFileName: v7, maxLen: 256, imgName: this->name.str);
  v3 = fileSystem->GetTimestamp(this: fileSystem, a2: v7, a3: false);
  binaryFileTime = this->binaryFileTime;
  v6[0] = v3;
  if ( v3 == binaryFileTime )
  {
    if ( strstr(str1: this->name.str, str2: ".bimage") != nullptr )
      return 0;
    str = this->name.str;
    if ( this->opts.textureType == TT_CUBIC )
      R_LoadCubeImages(imgName: str, pics: nullptr, outSize: nullptr, timestamp: v6);
    else
      R_LoadImageProgram(name: str, pic: nullptr, width: nullptr, height: nullptr, timestamps: v6);
    if ( v6[0] == this->sourceFileTime || v6[0] == -1 )
      return 0;
    fileSystem->RemoveFile(this: fileSystem, a2: v7, a3: FSPATH_BASE);
  }
  this->LoadResource(this);
  return 1;
}


// ========================================================================
// ?LoadResource@idImage@@UAAXXZ
// EA  : 0x828C4038
// RVA : 0x008C4038
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __fastcall idImage::LoadResource(idImage *this)
{
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  textureType_t v8; // r11
  __int64 v9; // r10
  __int64 v10; // r8
  __int64 v11; // r6
  __int64 v12; // r10
  __int64 v13; // r8
  __int64 v14; // r6
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  int v18; // [sp+8h] [-258h]
  int v19; // [sp+Ch] [-254h]
  int v20; // [sp+10h] [-250h]
  int v21; // [sp+14h] [-24Ch]
  int v22; // [sp+18h] [-248h]
  int v23; // [sp+1Ch] [-244h]
  idImageOpts v24; // [sp+50h] [-210h] BYREF
  idBinaryImage v25; // [sp+A0h] [-1C0h] BYREF
  char v26[304]; // [sp+130h] [-130h] BYREF

  if ( *this->name.str == 95 )
  {
    v24.colorFormat = CFM_DEFAULT;
    v24.border.x = 0.0;
    v24.filter = TF_DEFAULT;
    v24.border.y = 0.0;
    v24.repeat = TR_REPEAT;
    v24.border.z = 0.0;
    v24.cubeFilter = false;
    v24.border.w = 0.0;
    v24.depth = 0;
    v24.lodBias = 0.0;
    v24.numLevels = 0;
    v24.lodMinClamp = 0.0;
    v24.textureType = TT_2D;
    v24.lodMaxClamp = 13.0;
    v24.packedTail = true;
    v24.aniso = 0.0;
    v24.readback = false;
    v24.linear = false;
    v24.forceBias = false;
    v24.depthCompareMode = false;
    v24.overlayMemory = false;
    v24.startPurged = false;
    v24.format = FMT_RGBA8;
    v24.width = 8;
    v24.height = 8;
    idImage::AllocImage(this, imgOpts: &v24);
    *((_BYTE *)&this->idResource + 32) &= ~0x80u;
  }
  else if ( (*((_BYTE *)&this->idResource + 32) & 0x80) != 0 )
  {
    idImage::PurgeImage(this);
    idImage::MakeGeneratedName(binaryFileName: v26, maxLen: 256, imgName: this->name.str);
    idBinaryImage::idBinaryImage(this: &v25, name: this->name.str);
    if ( (unsigned __int8)idBinaryImage::LoadFromGeneratedFile(this: &v25, binaryFileName: v26) != 0 )
    {
      if ( v25.opts.width <= 4096 )
      {
        if ( v25.opts.height <= 4096 )
        {
          if ( resourceManager->ExcludeImage(this: resourceManager, a2: v26) )
            idImage::MakeDefault(this);
          else
            idImage::LoadFromBinaryImage(this, im: &v25);
        }
        else
        {
          HIDWORD(v4) = this->name.str;
          idResource::SetResourceError(
            this: &this->idResource,
            fmt: "Height > 4096 for idImage '%s'.",
            a3: v4,
            a4: v3,
            a5: v2,
            a6: v18,
            a7: v19,
            a8: v20,
            a9: v21,
            a10: v22,
            a11: v23);
          idImage::MakeDefault(this);
        }
      }
      else
      {
        HIDWORD(v4) = this->name.str;
        idResource::SetResourceError(
          this: &this->idResource,
          fmt: "Width > 4096 for idImage '%s'.",
          a3: v4,
          a4: v3,
          a5: v2,
          a6: v18,
          a7: v19,
          a8: v20,
          a9: v21,
          a10: v22,
          a11: v23);
        idImage::MakeDefault(this);
      }
    }
    else if ( strstr(str1: this->name.str, str2: "bimage") != nullptr )
    {
      HIDWORD(v7) = this->name.str;
      idResource::SetResourceError(
        this: &this->idResource,
        fmt: "Explicit binary file load failed for idImage %s.",
        a3: v7,
        a4: v6,
        a5: v5,
        a6: v18,
        a7: v19,
        a8: v20,
        a9: v21,
        a10: v22,
        a11: v23);
      idImage::MakeDefault(this);
    }
    else
    {
      if ( !this->optsHasBeenSet )
      {
        this->optsHasBeenSet = true;
        idImageOpts::operator=(this: &this->opts, __that: &globalImages->newImageOpts);
        if ( strstr(str1: this->name.str, str2: "_forward") != nullptr
          || strstr(str1: this->name.str, str2: "_px") != nullptr )
        {
          v8 = TT_CUBIC;
          this->opts.repeat = TR_CLAMP;
        }
        else
        {
          v8 = TT_2D;
        }
        this->opts.textureType = v8;
      }
      idImageOpts::operator=(this: &v25.opts, __that: &this->opts);
      if ( (unsigned __int8)idBinaryImage::LoadFromSourceFile(this: &v25) != 0 )
      {
        idBinaryImage::WriteGeneratedFile(this: &v25, binaryFileName: v26);
        if ( (unsigned __int8)idBinaryImage::LoadFromGeneratedFile(this: &v25, binaryFileName: v26) != 0 )
        {
          idImage::LoadFromBinaryImage(this, im: &v25);
          if ( this->opts.width <= 4096 )
          {
            if ( this->opts.height > 4096 )
            {
              HIDWORD(v17) = this->name.str;
              idResource::SetResourceError(
                this: &this->idResource,
                fmt: "Height > 4096 for idImage %s.",
                a3: v17,
                a4: v16,
                a5: v15,
                a6: v18,
                a7: v19,
                a8: v20,
                a9: v21,
                a10: v22,
                a11: v23);
              idImage::MakeDefault(this);
            }
          }
          else
          {
            HIDWORD(v17) = this->name.str;
            idResource::SetResourceError(
              this: &this->idResource,
              fmt: "Width > 4096 for idImage '%s.",
              a3: v17,
              a4: v16,
              a5: v15,
              a6: v18,
              a7: v19,
              a8: v20,
              a9: v21,
              a10: v22,
              a11: v23);
            idImage::MakeDefault(this);
          }
        }
        else
        {
          HIDWORD(v14) = v26;
          idResource::SetResourceError(
            this: &this->idResource,
            fmt: "Failed to load after generating file for idImage '%s'.",
            a3: v14,
            a4: v13,
            a5: v12,
            a6: v18,
            a7: v19,
            a8: v20,
            a9: v21,
            a10: v22,
            a11: v23);
          idImage::MakeDefault(this);
        }
      }
      else
      {
        HIDWORD(v11) = this->name.str;
        idResource::SetResourceError(
          this: &this->idResource,
          fmt: "Image source file load failed for idImage '%s'.",
          a3: v11,
          a4: v10,
          a5: v9,
          a6: v18,
          a7: v19,
          a8: v20,
          a9: v21,
          a10: v22,
          a11: v23);
        idImage::MakeDefault(this);
      }
    }
    idBinaryImage::~idBinaryImage(this: &v25);
  }
}


// ========================================================================
// __unwind$232000
// EA  : 0x828C43A8
// RVA : 0x008C43A8
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void _unwind_232000()
{
  int v0; // r12

  idBinaryImage::~idBinaryImage(this: (idBinaryImage *)(v0 - 608 + 160));
}


// ========================================================================
// `dynamic initializer for 'idImage::resourceList''
// EA  : 0x8334BCE0
// RVA : 0x0134BCE0
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idImage::resourceList__()
{
  idResourceList::idResourceList(this: &idImage::resourceList, typeName: "image");
  idImage::resourceList.__vftable = (idTypedResourceList<idImage>_vtbl *)&idTypedResourceList<idImage>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idImage::resourceList__);
}


// ========================================================================
// `dynamic initializer for 'TestFMT_X16_v''
// EA  : 0x8334BD30
// RVA : 0x0134BD30
// PDB : w:\tech5\engine\renderer\image.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__TestFMT_X16_v__()
{
  return idCommandLink::idCommandLink(
           this: &TestFMT_X16_v,
           cmdName: "TestFMT_X16",
           function: TestFMT_X16_f,
           description: "Tests the X16 texture format to make sure it reads as integers in fragment shaders",
           argCompletion: nullptr);
}

