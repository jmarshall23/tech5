
// ========================================================================
// ?D3DFMT_FromOpts@@YA?AW4_D3DFORMAT@@ABVidImageOpts@@@Z
// EA  : 0x828CF078
// RVA : 0x008CF078
// PDB : w:\tech5\engine\renderer\image_d3d_360.cpp
// ========================================================================

void __fastcall D3DFMT_FromOpts(const idImageOpts *opts)
{
  textureFormat_t format; // r4

  format = opts->format;
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
      idLib::Error(fmt: "idImage::AllocImage: Unknown format: %d\n", format);
      break;
  }
}


// ========================================================================
// ?Resize@idImage@@QAAXHHH@Z
// EA  : 0x828CF200
// RVA : 0x008CF200
// PDB : w:\tech5\engine\renderer\image_d3d_360.cpp
// ========================================================================

void __fastcall idImage::Resize(idImage *this, unsigned int width, unsigned int height, int depth)
{
  int v7; // r11
  bool v8; // zf
  BOOL readback; // r11
  unsigned int numLevels; // r5
  char v11; // r6
  unsigned int v12; // r9
  unsigned int v13; // [sp+8h] [-98h]
  unsigned int v14; // [sp+Ch] [-94h]
  D3DTexture *v15; // [sp+10h] [-90h]
  unsigned int *v16; // [sp+14h] [-8Ch]
  unsigned int *v17; // [sp+18h] [-88h]

  v7 = this->opts.width;
  v8 = width != v7;
  if ( v8 || height != this->opts.height )
  {
    readback = this->opts.readback;
    numLevels = this->opts.numLevels;
    v11 = _cntlzw(this->opts.packedTail);
    this->opts.width = width;
    this->opts.height = height;
    v12 = (v11 & 0x20) != 0;
    if ( numLevels == 1 )
      v12 = 1;
    XGSetTextureHeaderEx(
      Width: width,
      Height: height,
      Levels: numLevels,
      Usage: !readback ? 0 : 4,
      Format: this->d3dFormat,
      ExpBias: 0,
      Flags: v12,
      BaseOffset: 0,
      MipOffset: v13,
      Pitch: v14,
      pTexture: v15,
      pBaseSize: v16,
      pMipSize: v17);
    XGOffsetResourceAddress(pResource: this->d3dTexture, pBaseAddress: this->imageBuffer);
  }
}


// ========================================================================
// ?DetermineSamplerStateFromOpts@idImage@@QAAXXZ
// EA  : 0x828CF2B0
// RVA : 0x008CF2B0
// PDB : w:\tech5\engine\renderer\image_d3d_360.cpp
// ========================================================================

void __fastcall idImage::DetermineSamplerStateFromOpts(
        idImage *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  textureFilter_t filter; // r4
  double textureAnisotropy; // fp0
  double aniso; // fp0
  double z; // fp11
  double w; // fp10
  int lodBias_low; // r5
  textureRepeat_t repeat; // r11
  double v16; // fp5
  double lodMaxClamp; // fp6
  double v18; // fp7
  const void *v19; // r10
  int v20; // r9
  int v21; // r8
  int v22; // r7
  int v23; // r6
  int v24; // r5
  int v25; // r4
  idImage *v26; // r3

  filter = this->opts.filter;
  if ( (unsigned int)filter > TF_DEFAULT )
    goto _LN29_0;
  if ( filter == TF_LINEAR )
  {
    this->_D3DSAMP_MIPFILTER = 2;
LABEL_14:
    this->_D3DSAMP_MINFILTER = 1;
    this->_D3DSAMP_MAGFILTER = 1;
    goto LABEL_15;
  }
  if ( filter == TF_NEAREST )
  {
    this->_D3DSAMP_MAGFILTER = 0;
    this->_D3DSAMP_MINFILTER = 0;
    this->_D3DSAMP_MIPFILTER = 2;
  }
  else
  {
    if ( filter != TF_NEAREST_MIPMAP_NEAREST )
    {
      if ( filter != TF_LINEAR_MIPMAP_NEAREST )
      {
        if ( filter == TF_TRILINEAR_NO_ANISO )
        {
          this->_D3DSAMP_MAGFILTER = (_cntlzw(globalImages->textureMaxFilter) & 0x20) != 0;
          this->_D3DSAMP_MINFILTER = (_cntlzw(globalImages->textureMinFilter) & 0x20) != 0;
        }
        else
        {
          this->_D3DSAMP_MAGFILTER = globalImages->textureMaxFilter != TF_LINEAR ? 0 : 4;
          this->_D3DSAMP_MINFILTER = globalImages->textureMinFilter != TF_LINEAR ? 0 : 4;
        }
        this->_D3DSAMP_MIPFILTER = (_cntlzw(globalImages->textureMipFilter) & 0x20) != 0;
        goto LABEL_15;
      }
      this->_D3DSAMP_MIPFILTER = 0;
      goto LABEL_14;
    }
    this->_D3DSAMP_MAGFILTER = 0;
    this->_D3DSAMP_MINFILTER = 0;
    this->_D3DSAMP_MIPFILTER = 0;
  }
LABEL_15:
  if ( filter == TF_DEFAULT && (textureAnisotropy = globalImages->textureAnisotropy) >= 1.0 )
  {
    this->_D3DSAMP_MAXANISOTROPY = (int)textureAnisotropy;
  }
  else
  {
    aniso = this->opts.aniso;
    if ( aniso < 1.0 )
    {
      this->_D3DSAMP_MAXANISOTROPY = 1;
    }
    else
    {
      this->_D3DSAMP_MAGFILTER = 4;
      this->_D3DSAMP_MINFILTER = 4;
      this->_D3DSAMP_MAXANISOTROPY = (int)aniso;
    }
  }
  z = this->opts.border.z;
  w = this->opts.border.w;
  lodBias_low = LODWORD(this->opts.lodBias);
  repeat = this->opts.repeat;
  v16 = (float)(this->opts.border.x * (float)255.0);
  lodMaxClamp = this->opts.lodMaxClamp;
  v18 = (float)(this->opts.border.y * (float)255.0);
  this->_D3DSAMP_MAXMIPLEVEL = (int)this->opts.lodMinClamp;
  this->_D3DSAMP_MIPMAPLODBIAS = lodBias_low;
  this->_D3DSAMP_MINMIPLEVEL = (int)lodMaxClamp;
  this->_D3DSAMP_BORDERCOLOR = ((((__ROL4__((unsigned __int8)(__int64)(float)((float)w * (float)255.0), 8)
                                 | (unsigned __int8)(__int64)v16) << 8)
                               | (unsigned __int8)(__int64)v18) << 8)
                             | (unsigned __int8)(__int64)(float)((float)z * (float)255.0);
  if ( (unsigned int)repeat > TR_MIRROR )
  {
    idLib::FatalError(fmt: "DetermineSamplerStateFromOpts: bad texture repeat");
_LN29_0:
    idLib::FatalError(fmt: "DetermineSamplerStateFromOpts: bad texture filter %d", filter);
    idImage::SubImageUpload(
      this: v26,
      mipLevel: v25,
      destX: v24,
      destY: v23,
      destZ: v22,
      width: v21,
      height: v20,
      pic: v19,
      pixelPitch: a9);
    return;
  }
  switch ( repeat )
  {
    case TR_CLAMP:
      this->_D3DSAMP_ADDRESSU = 2;
      this->_D3DSAMP_ADDRESSV = 2;
      break;
    case TR_CLAMP_S:
      this->_D3DSAMP_ADDRESSU = 2;
      this->_D3DSAMP_ADDRESSV = 0;
      break;
    case TR_CLAMP_T:
      this->_D3DSAMP_ADDRESSU = 0;
      this->_D3DSAMP_ADDRESSV = 2;
      break;
    case TR_CLAMP_TO_BORDER:
      this->_D3DSAMP_ADDRESSU = 6;
      this->_D3DSAMP_ADDRESSV = 6;
      break;
    default:
      if ( repeat != TR_REPEAT )
      {
        this->_D3DSAMP_ADDRESSU = 1;
        this->_D3DSAMP_ADDRESSV = 1;
      }
      else
      {
        this->_D3DSAMP_ADDRESSU = 0;
        this->_D3DSAMP_ADDRESSV = 0;
      }
      break;
  }
  this->_D3DSAMP_TRILINEARTHRESHOLD = 3;
}


// ========================================================================
// ?SubImageUpload@idImage@@QBAXHHHHHHPBXH@Z
// EA  : 0x828CF548
// RVA : 0x008CF548
// PDB : w:\tech5\engine\renderer\image_d3d_360.cpp
// ========================================================================

void __fastcall idImage::SubImageUpload(
        idImage *this,
        unsigned int mipLevel,
        int destX,
        int destY,
        _D3DCUBEMAP_FACES destZ,
        int width,
        int height,
        char *pic,
        int pixelPitch)
{
  int v17; // r28
  int v18; // r27
  int v19; // r31
  int v20; // r29
  int v21; // r11
  int v22; // r3
  unsigned int RowPitch; // r25
  size_t v24; // r26
  BOOL v25; // r24
  char *v26; // r31
  char *v27; // r23
  textureFormat_t format; // r11
  char *v29; // r10
  int v30; // ctr
  char *v31; // r11
  unsigned __int8 v32; // r8
  unsigned __int8 v33; // r7
  unsigned __int8 v34; // r6
  int i; // r29
  char *v36; // r10
  int v37; // ctr
  char *v38; // r11
  D3DTexture *d3dTexture; // r3
  unsigned int v40; // r31
  unsigned int v41; // [sp+8h] [-198h]
  const tagRECT *v42; // [sp+Ch] [-194h]
  _D3DLOCKED_RECT v43; // [sp+60h] [-140h] BYREF
  tagPOINT v44; // [sp+68h] [-138h] BYREF
  int v45; // [sp+70h] [-130h]
  int v46; // [sp+74h] [-12Ch]
  int v47; // [sp+78h] [-128h]
  int v48; // [sp+7Ch] [-124h]
  _XGTEXTURE_DESC v49; // [sp+80h] [-120h] BYREF
  _XGTEXTURE_DESC v50; // [sp+C0h] [-E0h] BYREF

  XGGetTextureDesc(pTexture: this->d3dTexture, Level: mipLevel, pDesc: &v50);
  if ( this->opts.textureType == TT_CUBIC )
    D3DCubeTexture_LockRect(
      pTexture: (D3DCubeTexture *)this->d3dTexture,
      Face: destZ,
      Level: mipLevel,
      pLockedRect: &v43,
      pRect: nullptr,
      Flags: 0);
  else
    v43 = this->lockRect[mipLevel];
  v17 = height;
  v18 = width;
  v19 = destX;
  v20 = destY;
  switch ( this->opts.format )
  {
    case FMT_RGBA32F:
      v21 = 16;
      break;
    case FMT_RGBA16F:
      v21 = 8;
      break;
    case FMT_DXT1:
      v19 = destX >> 2;
      v20 = destY >> 2;
      v18 = (width + 3) >> 2;
      v21 = 8;
      v17 = (height + 3) >> 2;
      break;
    case FMT_DXT5:
      v19 = destX >> 2;
      v20 = destY >> 2;
      v18 = (width + 3) >> 2;
      v21 = 16;
      v17 = (height + 3) >> 2;
      break;
    default:
      idImage::BitsForInternalFormat(this);
      v21 = v22 / 8;
      break;
  }
  RowPitch = v50.RowPitch;
  v24 = v21 * v18;
  v25 = (v50.Format & 0x100) != 0;
  v26 = (char *)v43.pBits + v43.Pitch * v20 + v21 * v19;
  v27 = nullptr;
  if ( (v50.Format & 0x100) != 0 )
  {
    v27 = (char *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\engine\\renderer\\Image_D3D_360.cpp(329) : TAG_IMAGE",
                    size: v24 * v17,
                    tag: TAG_IMAGE,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
    RowPitch = v24;
    v26 = v27;
  }
  format = this->opts.format;
  if ( format == FMT_L8A8 || format == FMT_RG8 )
  {
    if ( v17 > 0 )
    {
      do
      {
        if ( v18 > 0 )
        {
          v36 = pic - 2;
          v37 = v18;
          v38 = v26 + 1;
          do
          {
            *(v38 - 1) = v38[pic - v26];
            v36 += 2;
            *v38 = *v36;
            v38 += 2;
            --v37;
          }
          while ( v37 != 0 );
        }
        --v17;
        pic += v24;
        v26 += RowPitch;
      }
      while ( v17 != 0 );
    }
  }
  else if ( format == FMT_RGBA8 )
  {
    if ( v17 > 0 )
    {
      do
      {
        if ( v18 > 0 )
        {
          v29 = v26 - 4;
          v30 = v18;
          v31 = pic - 2;
          do
          {
            v32 = v31[3];
            v33 = v31[5];
            v34 = v31[2];
            v31 += 4;
            v29 += 4;
            *(_DWORD *)v29 = ((((unsigned __int16)(((unsigned __int8)*v31 << 8) | v32) << 8) | v34) << 8) | v33;
            --v30;
          }
          while ( v30 != 0 );
        }
        --v17;
        pic += v24;
        v26 += RowPitch;
      }
      while ( v17 != 0 );
    }
  }
  else if ( v17 > 0 )
  {
    for ( i = v17; i != 0; --i )
    {
      memcpy(Dst: v26, Src: pic, Size: v24);
      pic += v24;
      v26 += RowPitch;
    }
  }
  if ( v25 )
  {
    d3dTexture = this->d3dTexture;
    v44.x = destX;
    v44.y = destY;
    v45 = 0;
    v46 = 0;
    v47 = width;
    v48 = height;
    v40 = (d3dTexture->Format.dword[5] & 0x800) == 0;
    if ( (d3dTexture->Format.dword[3] & 0x80000000) != 0 )
      v40 |= 2u;
    XGGetTextureDesc(pTexture: d3dTexture, Level: 0, pDesc: &v49);
    XGTileTextureLevel(
      Width: v49.Width,
      Height: v49.Height,
      Level: mipLevel,
      GpuFormat: v49.Format & 0x3F,
      Flags: v40,
      pDestination: v43.pBits,
      pPoint: &v44,
      pSource: v27,
      RowPitch: v41,
      pRect: v42);
    idMem::Free(this: &mem, ptr: v27, align: ALIGN_16);
  }
  if ( this->opts.textureType == TT_CUBIC )
    D3DTexture_UnlockRect(pTexture: (D3DCubeTexture *)this->d3dTexture, FaceType: destZ, Level: mipLevel);
}


// ========================================================================
// ?PurgeImage@idImage@@QAAXXZ
// EA  : 0x828CF8A0
// RVA : 0x008CF8A0
// PDB : w:\tech5\engine\renderer\image_d3d_360.cpp
// ========================================================================

void __fastcall idImage::PurgeImage(idImage *this)
{
  D3DTexture *d3dTexture; // r3
  void *imageBuffer; // r3

  while ( this->backgroundReadData != nullptr )
  {
    if ( this->backgroundReadComplete )
      break;
    idLib::Printf(fmt: "Waiting on background complete for purge of %s\n", this->name.str);
    mgthread_sleep(ms: 10);
  }
  if ( this->backgroundReadData != nullptr )
    this->backgroundReadData = nullptr;
  d3dTexture = this->d3dTexture;
  if ( d3dTexture != nullptr )
  {
    if ( D3DResource_IsSet(pResource: d3dTexture, pDevice: d3d) != 0 )
      idImageManager::UnbindAll(this: globalImages);
    idMem::Free(this: &mem, ptr: this->d3dTexture, align: ALIGN_16);
    this->d3dTexture = nullptr;
  }
  imageBuffer = this->imageBuffer;
  if ( imageBuffer != nullptr )
  {
    if ( this->opts.overlayMemory )
    {
      idPhysicalMemoryBlock::OverlayFree(this: &physicalMemoryBlock, buf: this->imageBuffer);
    }
    else if ( this->opts.readback )
    {
      XMemFree(pAddress: imageBuffer, dwAllocAttributes: 0xAC230000);
    }
    else
    {
      XMemFree(pAddress: imageBuffer, dwAllocAttributes: dwAllocAttributes_WriteCombined);
    }
    this->imageBuffer = nullptr;
  }
  this->physicalMemoryBytes = 0;
}


// ========================================================================
// ?AllocImage@idImage@@QAAXABVidImageOpts@@@Z
// EA  : 0x828CF9C0
// RVA : 0x008CF9C0
// PDB : w:\tech5\engine\renderer\image_d3d_360.cpp
// ========================================================================

void __fastcall idImage::AllocImage(idImage *this, const idImageOpts *imgOpts)
{
  idImageOpts *p_opts; // r22
  unsigned int v5; // r24
  unsigned int v6; // r23
  unsigned int v7; // r21
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r5
  int v12; // r4
  int textureType; // r9
  _D3DFORMAT v14; // r3
  volatile int *v15; // r10
  D3DTexture *v16; // r11
  _D3DFORMAT d3dFormat; // r7
  unsigned int numLevels; // r5
  unsigned int height; // r4
  unsigned int width; // r3
  unsigned int v21; // r3
  BOOL overlayMemory; // r10
  void *v23; // r3
  D3DTexture *v24; // r11
  _D3DFORMAT v25; // r7
  unsigned int v26; // r5
  unsigned int v27; // r4
  unsigned int v28; // r3
  int v29; // r3
  void *v30; // r3
  _D3DCUBEMAP_FACES v31; // r28
  _D3DLOCKED_RECT *lockRect; // r25
  unsigned int v33; // r5
  unsigned int v34; // r3
  void *v35; // r10
  D3DTexture *d3dTexture; // r3
  unsigned int v37; // r3
  void *v38; // r10
  D3DTexture *v39; // r3
  D3DCubeTexture *v40; // [sp+8h] [-D8h]
  unsigned int *v41; // [sp+Ch] [-D4h]
  D3DTexture *v42; // [sp+10h] [-D0h]
  unsigned int *v43; // [sp+14h] [-CCh]
  unsigned int *v44; // [sp+18h] [-C8h]

  p_opts = &this->opts;
  idImage::PurgeImage(this);
  idImageOpts::operator=(this: &this->opts, __that: imgOpts);
  idImage::DeriveNumLevels(this);
  v5 = (_cntlzw(this->opts.packedTail) & 0x20) != 0;
  v6 = !this->opts.readback ? 0 : 4;
  if ( this->opts.readback )
    v7 = -1406992384;
  else
    v7 = dwAllocAttributes_WriteCombined;
  if ( this->opts.numLevels == 1 )
    v5 = 1;
  D3DFMT_FromOpts(opts: &this->opts);
  textureType = p_opts->textureType;
  this->d3dFormat = v14;
  v15 = allocationCurrent[242];
  if ( textureType == 0 )
  {
    v16 = (D3DTexture *)idMem::AllocWithLocation(
                          this: &mem,
                          location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                          size: 0x34u,
                          tag: TAG_IMAGE,
                          zeroBuffer: false,
                          align: ALIGN_16,
                          heap: HEAP_DEFAULTHEAP);
    d3dFormat = this->d3dFormat;
    numLevels = this->opts.numLevels;
    height = this->opts.height;
    width = this->opts.width;
    this->d3dTexture = v16;
    v21 = XGSetTextureHeaderEx(
            Width: width,
            Height: height,
            Levels: numLevels,
            Usage: v6,
            Format: d3dFormat,
            ExpBias: 0,
            Flags: v5,
            BaseOffset: 0,
            MipOffset: (unsigned int)v40,
            Pitch: (unsigned int)v41,
            pTexture: v42,
            pBaseSize: v43,
            pMipSize: v44);
    overlayMemory = this->opts.overlayMemory;
    this->physicalMemoryBytes = v21;
    if ( overlayMemory )
    {
      v23 = idPhysicalMemoryBlock::OverlayAlloc(this: &physicalMemoryBlock, bytes: v21, name: this->name.str);
      this->imageBuffer = v23;
      if ( v23 == nullptr )
      {
        idSWF::ForcePurgeImages();
        idImageManager::PurgeAllOverlays(this: globalImages);
        v24 = (D3DTexture *)idMem::AllocWithLocation(
                              this: &mem,
                              location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                              size: 0x34u,
                              tag: TAG_IMAGE,
                              zeroBuffer: false,
                              align: ALIGN_16,
                              heap: HEAP_DEFAULTHEAP);
        v25 = this->d3dFormat;
        v26 = this->opts.numLevels;
        v27 = this->opts.height;
        v28 = this->opts.width;
        this->d3dTexture = v24;
        v29 = XGSetTextureHeaderEx(
                Width: v28,
                Height: v27,
                Levels: v26,
                Usage: v6,
                Format: v25,
                ExpBias: 0,
                Flags: v5,
                BaseOffset: 0,
                MipOffset: (unsigned int)v40,
                Pitch: (unsigned int)v41,
                pTexture: v42,
                pBaseSize: v43,
                pMipSize: v44);
        this->physicalMemoryBytes = v29;
        v30 = idPhysicalMemoryBlock::OverlayAlloc(this: &physicalMemoryBlock, bytes: v29, name: this->name.str);
        this->imageBuffer = v30;
        if ( v30 == nullptr )
          idLib::Error(
            fmt: "Image %s at %d bytes does not fit in physical overlay memory block!!\n",
            this->name.str,
            this->physicalMemoryBytes);
        idLib::Warning(fmt: "Had to force purge overlay images because the physical memory block is FULL!");
      }
    }
    else
    {
      this->imageBuffer = XMemAlloc(dwSize: v21, dwAllocAttributes: v7);
    }
    XGOffsetResourceAddress(pResource: this->d3dTexture, pBaseAddress: this->imageBuffer);
    v31 = D3DCUBEMAP_FACE_POSITIVE_X;
    v15 = (volatile int *)this->opts.height;
    textureType = this->opts.numLevels;
    this->allocWidth = this->opts.width;
    this->allocHeight = (int)v15;
    if ( textureType > 0 )
    {
      lockRect = this->lockRect;
      do
      {
        D3DTexture_LockRect(
          pTexture: this->d3dTexture,
          Level: v31,
          pLockedRect: lockRect,
          pRect: nullptr,
          Flags: 0x1000u);
        D3DTexture_UnlockRect(pTexture: (D3DCubeTexture *)this->d3dTexture, FaceType: v31++, Level: v33);
        ++lockRect;
      }
      while ( v31 < this->opts.numLevels );
    }
  }
  if ( p_opts->textureType == TT_CUBIC )
  {
    this->d3dTexture = (D3DTexture *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x34u,
                                       tag: TAG_IMAGE,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
    v34 = XGSetCubeTextureHeaderEx(
            EdgeLength: this->opts.width,
            Levels: this->opts.numLevels,
            Usage: v6,
            Format: this->d3dFormat,
            ExpBias: 0,
            Flags: v5,
            BaseOffset: 0,
            MipOffset: 0xFFFFFFFF,
            pCubeTexture: v40,
            pBaseSize: v41,
            pMipSize: &v42->Common);
    this->physicalMemoryBytes = v34;
    v35 = XMemAlloc(dwSize: v34, dwAllocAttributes: v7);
    d3dTexture = this->d3dTexture;
    this->imageBuffer = v35;
    XGOffsetResourceAddress(pResource: d3dTexture, pBaseAddress: v35);
  }
  if ( p_opts->textureType == TT_3D )
  {
    this->d3dTexture = (D3DTexture *)idMem::AllocWithLocation(
                                       this: &mem,
                                       location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                                       size: 0x34u,
                                       tag: TAG_IMAGE,
                                       zeroBuffer: false,
                                       align: ALIGN_16,
                                       heap: HEAP_DEFAULTHEAP);
    v37 = XGSetVolumeTextureHeaderEx(
            Width: this->opts.width,
            Height: this->opts.height,
            Depth: this->opts.depth,
            Levels: this->opts.numLevels,
            Usage: v6,
            Format: this->d3dFormat,
            ExpBias: 0,
            Flags: v5,
            BaseOffset: (unsigned int)v40,
            MipOffset: (unsigned int)v41,
            pVolumeTexture: (D3DVolumeTexture *)v42,
            pBaseSize: v43,
            pMipSize: v44);
    this->physicalMemoryBytes = v37;
    v38 = XMemAlloc(dwSize: v37, dwAllocAttributes: v7);
    v39 = this->d3dTexture;
    this->imageBuffer = v38;
    XGOffsetResourceAddress(pResource: v39, pBaseAddress: v38);
  }
  if ( this->d3dTexture == nullptr )
    idLib::FatalError(fmt: "d3dTexture create failed");
  idImage::DetermineSamplerStateFromOpts(
    this,
    a2: v12,
    a3: v11,
    a4: v10,
    a5: v9,
    a6: v8,
    a7: textureType,
    a8: (int)v15,
    a9: (int)v40);
}

