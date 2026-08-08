
// ========================================================================
// ?uni@@YAMXZ
// EA  : 0x828CFD60
// RVA : 0x008CFD60
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

float __fastcall uni()
{
  __int64 v0; // r11
  double v1; // fp1

  HIDWORD(v0) = 40014 * (s1 % 53668) - 12211 * (s1 / 53668);
  s1 = HIDWORD(v0);
  if ( v0 < 0 )
  {
    HIDWORD(v0) += 2147483563;
    s1 = HIDWORD(v0);
  }
  LODWORD(v0) = 40692 * (s2 % 52774) - 3791 * (s2 / 52774);
  s2 = v0;
  if ( (int)v0 < 0 )
  {
    LODWORD(v0) = v0 + 2147483399;
    s2 = v0;
  }
  LODWORD(v0) = v0 + HIDWORD(v0) - 2147483563;
  if ( (int)v0 < 1 )
    LODWORD(v0) = v0 + 2147483562;
  HIDWORD(v0) = &off_82230000;
  v1 = (float)((float)v0 * (float)4.6566134e-10);
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?WaveImage@idImageIntrinsic@@SAXXZ
// EA  : 0x828CFE70
// RVA : 0x008CFE70
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::WaveImage(long double a1)
{
  __int64 v1; // r11
  int i; // r30
  long double v3; // fp2
  long double v4; // fp4
  idImage *v5; // r3
  int v6; // [sp+8h] [-208h]
  idImageOpts v7; // [sp+60h] [-1B0h] BYREF
  int v9; // [sp+B4h] [-15Ch]
  __int64 v10; // [sp+B8h] [-158h]
  char v11[304]; // [sp+C0h] [-150h] BYREF

  HIDWORD(v1) = byte_821B0000;
  for ( i = 0; i < 256; ++i )
  {
    LODWORD(v1) = i;
    *(double *)&a1 = (float)((float)((float)v1 * (float)0.00390625) * idMath::TWO_PI);
    v10 = v1;
    v3 = cos(x: a1);
    *((double *)&v3 + 1) = 1.0;
    *(double *)&v3 = (float)((float)((float)*(double *)&v3 + (float)1.0) * (float)0.5);
    a1 = pow(x: v3, y: v4);
    v9 = (int)(float)((float)*(double *)&a1 * (float)256.0);
    if ( v9 <= 255 )
      LODWORD(v1) = (((unsigned int)v9 >> 31) - 1) & v9;
    else
      LOBYTE(v1) = -1;
    HIDWORD(v1) = v11;
    v11[i] = v1;
  }
  v7.colorFormat = CFM_DEFAULT;
  v7.repeat = TR_REPEAT;
  v7.cubeFilter = false;
  v7.depth = 0;
  v7.textureType = TT_2D;
  v7.packedTail = true;
  v7.readback = false;
  v7.border.x = 0.0;
  v7.linear = false;
  v7.border.y = 0.0;
  v7.forceBias = false;
  v7.border.z = 0.0;
  v7.depthCompareMode = false;
  v7.border.w = 0.0;
  v7.overlayMemory = false;
  v7.lodBias = 0.0;
  v7.startPurged = false;
  v7.lodMinClamp = 0.0;
  v7.format = FMT_LUM8;
  v7.lodMaxClamp = 13.0;
  v7.width = 256;
  v7.aniso = 0.0;
  v7.height = 1;
  v7.filter = TF_NEAREST;
  v7.numLevels = 1;
  v5 = idImageManager::ScratchImage(this: globalImages, _name: "_wave", imgOpts: &v7);
  idImage::SubImageUpload(
    this: v5,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v7.width,
    height: v7.height,
    pic: v11,
    pixelPitch: v6);
}


// ========================================================================
// ?FresnelImage@idImageIntrinsic@@SAXXZ
// EA  : 0x828D0008
// RVA : 0x008D0008
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::FresnelImage(double a1, double a2, long double a3)
{
  __int64 v3; // r11
  int i; // r30
  long double v5; // fp2
  long double v6; // fp2
  char v7; // r11
  idImage *v8; // r3
  int v9; // [sp+8h] [-1F8h]
  idImageOpts v10; // [sp+60h] [-1A0h] BYREF
  int v12; // [sp+B4h] [-14Ch]
  __int64 v13; // [sp+B8h] [-148h]
  char v14[296]; // [sp+C0h] [-140h] BYREF

  HIDWORD(v3) = &unk_821F0000;
  for ( i = 0; i < 256; ++i )
  {
    LODWORD(v3) = i;
    *((double *)&v5 + 1) = 5.0;
    v13 = v3;
    *(double *)&v5 = (float)-(float)((float)((float)v3 * (float)0.0039215689) - (float)1.0);
    v6 = pow(x: v5, y: a3);
    v12 = (int)(float)((float)*(double *)&v6 * (float)255.5);
    v7 = v12;
    if ( v12 >= 0 )
    {
      if ( v12 > 255 )
        v7 = -1;
    }
    else
    {
      v7 = 0;
    }
    HIDWORD(v3) = v14;
    v14[i] = v7;
  }
  v10.colorFormat = CFM_DEFAULT;
  v10.cubeFilter = false;
  v10.depth = 0;
  v10.textureType = TT_2D;
  v10.packedTail = true;
  v10.readback = false;
  v10.linear = false;
  v10.border.x = 0.0;
  v10.forceBias = false;
  v10.border.y = 0.0;
  v10.depthCompareMode = false;
  v10.border.z = 0.0;
  v10.overlayMemory = false;
  v10.border.w = 0.0;
  v10.startPurged = false;
  v10.lodBias = 0.0;
  v10.format = FMT_LUM8;
  v10.lodMinClamp = 0.0;
  v10.width = 256;
  v10.lodMaxClamp = 13.0;
  v10.height = 1;
  v10.aniso = 0.0;
  v10.repeat = TR_CLAMP;
  v10.filter = TF_NEAREST;
  v10.numLevels = 1;
  v8 = idImageManager::ScratchImage(this: globalImages, _name: "_fresnel", imgOpts: &v10);
  idImage::SubImageUpload(
    this: v8,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v10.width,
    height: v10.height,
    pic: v14,
    pixelPitch: v9);
}


// ========================================================================
// ?SelectBox@idImageIntrinsic@@SAXXZ
// EA  : 0x828D0198
// RVA : 0x008D0198
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::SelectBox()
{
  char *v0; // r9
  int i; // r8
  int v2; // ctr
  int v3; // r11
  float *p_lodMinClamp; // r9
  int v5; // ctr
  int v6; // r10
  char *v7; // r8
  idImage *v8; // r3
  int v9; // [sp+8h] [-1B8h]
  idImageOpts v10; // [sp+60h] [-160h] BYREF
  char v11[256]; // [sp+B0h] [-110h] BYREF

  memset(Dst: v11, Val: 255, Size: sizeof(v11));
  v0 = v11;
  for ( i = 16; i != 0; --i )
  {
    v2 = 16;
    v3 = 0;
    do
    {
      v0[v3++] = 0;
      --v2;
    }
    while ( v2 != 0 );
    v0 += 16;
  }
  p_lodMinClamp = &v10.lodMinClamp;
  v5 = 16;
  v6 = 0;
  do
  {
    *((_BYTE *)p_lodMinClamp + 31) = -1;
    v7 = &v11[v6++];
    v7[240] = -1;
    p_lodMinClamp += 4;
    *(_BYTE *)p_lodMinClamp = -1;
    *v7 = -1;
    --v5;
  }
  while ( v5 != 0 );
  v10.colorFormat = CFM_DEFAULT;
  v10.cubeFilter = false;
  v10.depth = 0;
  v10.textureType = TT_2D;
  v10.packedTail = true;
  v10.filter = TF_NEAREST;
  v10.numLevels = 1;
  v10.border.x = 0.0;
  v10.readback = false;
  v10.border.y = 0.0;
  v10.linear = false;
  v10.border.z = 0.0;
  v10.forceBias = false;
  v10.border.w = 0.0;
  v10.depthCompareMode = false;
  v10.lodBias = 0.0;
  v10.overlayMemory = false;
  v10.lodMinClamp = 0.0;
  v10.startPurged = false;
  v10.lodMaxClamp = 13.0;
  v10.format = FMT_INT8;
  v10.aniso = 0.0;
  v10.width = 16;
  v10.height = 16;
  v10.repeat = TR_CLAMP_TO_BORDER;
  v8 = idImageManager::ScratchImage(this: globalImages, _name: "_selectBox", imgOpts: &v10);
  idImage::SubImageUpload(
    this: v8,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v10.width,
    height: v10.height,
    pic: v11,
    pixelPitch: v9);
}


// ========================================================================
// ?MakeDefault@idImage@@IAAXXZ
// EA  : 0x828D02F0
// RVA : 0x008D02F0
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

void __fastcall idImage::MakeDefault(idImage *this)
{
  char *v2; // r9
  int i; // r7
  int v4; // ctr
  int v5; // r11
  bool *v6; // r9
  int v7; // ctr
  int v8; // r10
  char *v9; // r8
  _D3DCUBEMAP_FACES j; // r30
  int v11; // [sp+8h] [-228h]
  idImageOpts v12; // [sp+60h] [-1D0h] BYREF
  idImageOpts v13; // [sp+B0h] [-180h] BYREF
  char v14[304]; // [sp+100h] [-130h] BYREF

  v2 = v14;
  for ( i = 16; i != 0; --i )
  {
    v4 = 16;
    v5 = 0;
    do
    {
      v2[v5++] = 32;
      --v4;
    }
    while ( v4 != 0 );
    v2 += 16;
  }
  v6 = &v13.depthCompareMode + 2;
  v7 = 16;
  v8 = 0;
  do
  {
    v9 = &v14[v8++ + 240];
    *(v9 - 240) = -1;
    v6[1] = -1;
    *v9 = -1;
    v6 += 16;
    *v6 = -1;
    --v7;
  }
  while ( v7 != 0 );
  if ( this->opts.textureType == TT_CUBIC )
  {
    v13.border.x = 0.0;
    v13.border.y = 0.0;
    v13.border.z = 0.0;
    v13.colorFormat = CFM_DEFAULT;
    v13.border.w = 0.0;
    v13.repeat = TR_REPEAT;
    v13.lodBias = 0.0;
    v13.cubeFilter = false;
    v13.lodMinClamp = 0.0;
    v13.depth = 0;
    v13.lodMaxClamp = 13.0;
    v13.packedTail = true;
    v13.aniso = 0.0;
    v13.filter = TF_DEFAULT;
    v13.readback = false;
    v13.linear = false;
    v13.forceBias = false;
    v13.depthCompareMode = false;
    v13.overlayMemory = false;
    v13.startPurged = false;
    v13.textureType = TT_CUBIC;
    v13.format = FMT_LUM8;
    v13.numLevels = 1;
    v13.width = 16;
    v13.height = 16;
    idImage::AllocImage(this, imgOpts: &v13);
    for ( j = D3DCUBEMAP_FACE_POSITIVE_X; j < (D3DCUBEMAP_FACE_POSITIVE_Z|D3DCUBEMAP_FACE_POSITIVE_Y); ++j )
      idImage::SubImageUpload(
        this,
        mipLevel: 0,
        destX: 0,
        destY: 0,
        destZ: j,
        width: 16,
        height: 16,
        pic: v14,
        pixelPitch: v11);
    this->defaulted = true;
  }
  else
  {
    v12.border.x = 0.0;
    v12.border.y = 0.0;
    v12.colorFormat = CFM_DEFAULT;
    v12.border.z = 0.0;
    v12.repeat = TR_REPEAT;
    v12.border.w = 0.0;
    v12.cubeFilter = false;
    v12.lodBias = 0.0;
    v12.depth = 0;
    v12.lodMinClamp = 0.0;
    v12.textureType = TT_2D;
    v12.lodMaxClamp = 13.0;
    v12.filter = TF_DEFAULT;
    v12.aniso = 0.0;
    v12.packedTail = true;
    v12.readback = false;
    v12.linear = false;
    v12.forceBias = false;
    v12.depthCompareMode = false;
    v12.overlayMemory = false;
    v12.startPurged = false;
    v12.format = FMT_LUM8;
    v12.numLevels = 1;
    v12.width = 16;
    v12.height = 16;
    if ( idImage::ImageState(this) == 0
      || v12.format != this->opts.format
      || v12.width != this->opts.width
      || v12.height != this->opts.height )
    {
      idImage::AllocImage(this, imgOpts: &v12);
    }
    idImage::SubImageUpload(
      this,
      mipLevel: 0,
      destX: 0,
      destY: 0,
      destZ: D3DCUBEMAP_FACE_POSITIVE_X,
      width: 16,
      height: 16,
      pic: v14,
      pixelPitch: v11);
    this->defaulted = true;
  }
}


// ========================================================================
// ?DefaultImage@idImageIntrinsic@@SAXXZ
// EA  : 0x828D0530
// RVA : 0x008D0530
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::DefaultImage()
{
  idImageOpts v0; // [sp+50h] [-60h] BYREF

  v0.colorFormat = CFM_DEFAULT;
  v0.border.x = 0.0;
  v0.filter = TF_DEFAULT;
  v0.format = FMT_LUM8;
  v0.border.y = 0.0;
  v0.border.z = 0.0;
  v0.repeat = TR_REPEAT;
  v0.border.w = 0.0;
  v0.cubeFilter = false;
  v0.lodBias = 0.0;
  v0.depth = 0;
  v0.lodMinClamp = 0.0;
  v0.textureType = TT_2D;
  v0.lodMaxClamp = 13.0;
  v0.packedTail = true;
  v0.aniso = 0.0;
  v0.readback = false;
  v0.linear = false;
  v0.forceBias = false;
  v0.depthCompareMode = false;
  v0.overlayMemory = false;
  v0.startPurged = false;
  v0.width = 16;
  v0.height = 16;
  v0.numLevels = 1;
  globalImages->defaultImage = idImageManager::ScratchImage(this: globalImages, _name: "_default", imgOpts: &v0);
  idImage::MakeDefault(this: globalImages->defaultImage);
}


// ========================================================================
// ?WhiteImage@idImageIntrinsic@@SAXXZ
// EA  : 0x828D0608
// RVA : 0x008D0608
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::WhiteImage()
{
  idImage *v0; // r29
  int v1; // [sp+8h] [-1C8h]
  idImageOpts v2; // [sp+60h] [-170h] BYREF
  char v3[288]; // [sp+B0h] [-120h] BYREF

  memset(Dst: v3, Val: 255, Size: 0x100u);
  v2.colorFormat = CFM_DEFAULT;
  v2.border.x = 0.0;
  v2.filter = TF_DEFAULT;
  v2.border.y = 0.0;
  v2.repeat = TR_REPEAT;
  v2.border.z = 0.0;
  v2.cubeFilter = false;
  v2.border.w = 0.0;
  v2.depth = 0;
  v2.lodBias = 0.0;
  v2.textureType = TT_2D;
  v2.lodMinClamp = 0.0;
  v2.packedTail = true;
  v2.lodMaxClamp = 13.0;
  v2.readback = false;
  v2.aniso = 0.0;
  v2.linear = false;
  v2.forceBias = false;
  v2.depthCompareMode = false;
  v2.overlayMemory = false;
  v2.startPurged = false;
  v2.format = FMT_LUM8;
  v2.width = 16;
  v2.height = 16;
  v2.numLevels = 1;
  v0 = idImageManager::ScratchImage(this: globalImages, _name: "_white", imgOpts: &v2);
  idImage::SubImageUpload(
    this: v0,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v2.width,
    height: v2.height,
    pic: v3,
    pixelPitch: v1);
  globalImages->whiteImage = v0;
}


// ========================================================================
// ?BorderedPointWhiteImage@idImageIntrinsic@@SAXXZ
// EA  : 0x828D0700
// RVA : 0x008D0700
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::BorderedPointWhiteImage()
{
  idImage *v0; // r29
  int v1; // [sp+8h] [-1C8h]
  idImageOpts v2; // [sp+60h] [-170h] BYREF
  char v3[288]; // [sp+B0h] [-120h] BYREF

  memset(Dst: v3, Val: 255, Size: 0x100u);
  v2.colorFormat = CFM_DEFAULT;
  v2.repeat = TR_REPEAT;
  v2.lodBias = 0.0;
  v2.cubeFilter = false;
  v2.lodMinClamp = 0.0;
  v2.depth = 0;
  v2.lodMaxClamp = 13.0;
  v2.textureType = TT_2D;
  v2.aniso = 0.0;
  v2.packedTail = true;
  v2.border.w = 0.0;
  v2.readback = false;
  v2.border.z = 0.0;
  v2.linear = false;
  v2.border.y = 0.0;
  v2.forceBias = false;
  v2.border.x = 0.0;
  v2.depthCompareMode = false;
  v2.overlayMemory = false;
  v2.startPurged = false;
  v2.format = FMT_LUM8;
  v2.width = 16;
  v2.height = 16;
  v2.filter = TF_NEAREST;
  v2.numLevels = 1;
  v0 = idImageManager::ScratchImage(this: globalImages, _name: "_borderedPointWhite", imgOpts: &v2);
  idImage::SubImageUpload(
    this: v0,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v2.width,
    height: v2.height,
    pic: v3,
    pixelPitch: v1);
  globalImages->borderedPointWhiteImage = v0;
}


// ========================================================================
// ?BlackImage@idImageIntrinsic@@SAXXZ
// EA  : 0x828D07F0
// RVA : 0x008D07F0
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::BlackImage()
{
  idImage *v0; // r29
  int v1; // [sp+8h] [-1C8h]
  idImageOpts v2; // [sp+60h] [-170h] BYREF
  char v3[288]; // [sp+B0h] [-120h] BYREF

  memset(Dst: v3, Val: 0, Size: 0x100u);
  v2.colorFormat = CFM_DEFAULT;
  v2.border.x = 0.0;
  v2.filter = TF_DEFAULT;
  v2.border.y = 0.0;
  v2.repeat = TR_REPEAT;
  v2.border.z = 0.0;
  v2.cubeFilter = false;
  v2.border.w = 0.0;
  v2.depth = 0;
  v2.lodBias = 0.0;
  v2.textureType = TT_2D;
  v2.lodMinClamp = 0.0;
  v2.packedTail = true;
  v2.lodMaxClamp = 13.0;
  v2.readback = false;
  v2.aniso = 0.0;
  v2.linear = false;
  v2.forceBias = false;
  v2.depthCompareMode = false;
  v2.overlayMemory = false;
  v2.startPurged = false;
  v2.format = FMT_LUM8;
  v2.width = 16;
  v2.height = 16;
  v2.numLevels = 1;
  v0 = idImageManager::ScratchImage(this: globalImages, _name: "_black", imgOpts: &v2);
  idImage::SubImageUpload(
    this: v0,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v2.width,
    height: v2.height,
    pic: v3,
    pixelPitch: v1);
  globalImages->blackImage = v0;
}


// ========================================================================
// ?FlatNormalImage@idImageIntrinsic@@SAXXZ
// EA  : 0x828D08E8
// RVA : 0x008D08E8
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::FlatNormalImage()
{
  idImage *v0; // r3
  int v1; // [sp+8h] [-4B8h]
  idImageOpts v2; // [sp+60h] [-460h] BYREF
  char v3[1024]; // [sp+B0h] [-410h] BYREF

  v2.colorFormat = CFM_DEFAULT;
  v2.border.x = 0.0;
  v2.border.y = 0.0;
  v2.border.z = 0.0;
  memset(v3, 128, 2);
  v2.format = FMT_RGBA8;
  v2.border.w = 0.0;
  v2.lodBias = 0.0;
  v2.lodMinClamp = 0.0;
  v3[2] = -1;
  v2.lodMaxClamp = 13.0;
  v3[3] = -1;
  v2.aniso = 0.0;
  v3[4] = 0x80;
  v3[5] = 0x80;
  v3[6] = -1;
  v3[7] = -1;
  v3[8] = 0x80;
  v3[9] = 0x80;
  v3[10] = -1;
  v3[11] = -1;
  v3[12] = 0x80;
  v3[13] = 0x80;
  v3[14] = -1;
  v3[15] = -1;
  v2.filter = TF_DEFAULT;
  v2.repeat = TR_REPEAT;
  v2.cubeFilter = false;
  v2.depth = 0;
  v2.textureType = TT_2D;
  v2.packedTail = true;
  v2.readback = false;
  v2.linear = false;
  v2.forceBias = false;
  v2.depthCompareMode = false;
  v2.overlayMemory = false;
  v2.startPurged = false;
  v2.width = 2;
  v2.height = 2;
  v2.numLevels = 1;
  v0 = idImageManager::ScratchImage(this: globalImages, _name: "_flat", imgOpts: &v2);
  idImage::SubImageUpload(
    this: v0,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v2.width,
    height: v2.height,
    pic: v3,
    pixelPitch: v1);
}


// ========================================================================
// ?DefaultCubeImage@idImageIntrinsic@@SAXXZ
// EA  : 0x828D0A18
// RVA : 0x008D0A18
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::DefaultCubeImage()
{
  int v0; // r3
  int v1; // r31
  char **v2; // r30
  int v3; // r29
  __int64 v4; // r5
  __int128 v5; // r8
  char *v6; // r9
  int i; // r8
  char v8; // r6
  double v9; // fp5
  int v10; // ctr
  int v11; // r10
  int v12; // r11
  char *v13; // r11
  idImage *v14; // r29
  _D3DCUBEMAP_FACES v15; // r31
  char **v16; // r30
  int v17; // [sp+8h] [-138h]
  idImageOpts v18; // [sp+70h] [-D0h] BYREF
  __int64 v19; // [sp+C0h] [-80h]
  __int64 v20; // [sp+C8h] [-78h]
  __int64 v21; // [sp+D0h] [-70h]
  int v22; // [sp+DCh] [-64h] BYREF
  char *v23; // [sp+E0h] [-60h] BYREF

  v23 = (char *)idMem::AllocWithLocation(
                  this: &mem,
                  location: "w:\\tech5\\engine\\renderer\\Image_intrinsic.cpp(363) : TAG_IMAGE",
                  size: 0x180u,
                  tag: TAG_IMAGE,
                  zeroBuffer: false,
                  align: ALIGN_16,
                  heap: HEAP_DEFAULTHEAP);
  v0 = 1;
  v1 = 0;
  v2 = &v23;
  v3 = 6;
  HIDWORD(v4) = 255;
  do
  {
    DWORD1(v5) = v0 & 1;
    LODWORD(v4) = 255 * ((v0 >> 2) & 1);
    v20 = v4;
    DWORD2(v5) = 255 * ((v0 >> 1) & 1);
    LODWORD(v5) = ((v0 << 8) & 0x100) - DWORD1(v5);
    v19 = *(_QWORD *)((char *)&v5 + 4);
    v21 = v5;
    v6 = &v23[v1];
    *v2 = &v23[v1];
    v8 = (int)(float)*(__int64 *)((char *)&v5 + 4);
    LOBYTE(v4) = (int)(float)v4;
    v9 = (float)(__int64)v5;
    for ( i = 0; i < 16; i += 4 )
    {
      v10 = 4;
      v11 = 0;
      do
      {
        v12 = 4 * (i + v11++);
        v13 = &v6[v12];
        *v13 = (int)v9;
        v13[1] = v8;
        v13[2] = v4;
        v13[3] = -1;
        --v10;
      }
      while ( v10 != 0 );
    }
    --v3;
    v1 += 64;
    ++v0;
    ++v2;
  }
  while ( v3 != 0 );
  v18.colorFormat = CFM_DEFAULT;
  v18.repeat = TR_REPEAT;
  v18.cubeFilter = false;
  v18.depth = 0;
  v18.filter = TF_DEFAULT;
  v18.packedTail = true;
  v18.readback = false;
  v18.border.x = 0.0;
  v18.linear = false;
  v18.border.y = 0.0;
  v18.forceBias = false;
  v18.border.z = 0.0;
  v18.depthCompareMode = false;
  v18.border.w = 0.0;
  v18.overlayMemory = false;
  v18.lodBias = 0.0;
  v18.startPurged = false;
  v18.lodMinClamp = 0.0;
  v18.format = FMT_DXT1;
  v18.lodMaxClamp = 13.0;
  v18.textureType = TT_CUBIC;
  v18.aniso = 0.0;
  v18.width = 4;
  v18.height = 4;
  v18.numLevels = 1;
  v14 = idImageManager::ScratchImage(this: globalImages, _name: "_defaultCube", imgOpts: &v18);
  v15 = D3DCUBEMAP_FACE_POSITIVE_X;
  v16 = (char **)&v22;
  do
    idImage::SubImageUpload(
      this: v14,
      mipLevel: 0,
      destX: 0,
      destY: 0,
      destZ: v15++,
      width: 4,
      height: 4,
      pic: *++v16,
      pixelPitch: v17);
  while ( v15 < (D3DCUBEMAP_FACE_POSITIVE_Z|D3DCUBEMAP_FACE_POSITIVE_Y) );
  idMem::Free(this: &mem, ptr: v23, align: ALIGN_16);
}


// ========================================================================
// ?NoFalloffImage@idImageIntrinsic@@SAXXZ
// EA  : 0x828D0C60
// RVA : 0x008D0C60
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::NoFalloffImage()
{
  __int64 v0; // r9
  idImage *v1; // r3
  int v2; // [sp+8h] [-C8h]
  char v3[16]; // [sp+60h] [-70h] BYREF
  idImageOpts v4; // [sp+70h] [-60h] BYREF

  HIDWORD(v0) = v3;
  LODWORD(v0) = -1;
  *(_QWORD *)HIDWORD(v0) = v0;
  *(_QWORD *)(HIDWORD(v0) + 8) = v0;
  v4.filter = TF_DEFAULT;
  v4.lodBias = 0.0;
  v4.format = FMT_LUM8;
  v4.lodMinClamp = 0.0;
  v4.lodMaxClamp = 13.0;
  v4.aniso = 0.0;
  v4.colorFormat = CFM_DEFAULT;
  v4.border.w = 0.0;
  v4.cubeFilter = false;
  v4.border.z = 0.0;
  v4.depth = 0;
  v4.border.y = 0.0;
  v4.textureType = TT_2D;
  v4.border.x = 0.0;
  v4.packedTail = true;
  v4.readback = false;
  v4.linear = false;
  v4.forceBias = false;
  v4.depthCompareMode = false;
  v4.overlayMemory = false;
  v4.startPurged = false;
  v4.width = 4;
  v4.height = 4;
  v4.repeat = TR_CLAMP_TO_BORDER;
  v4.numLevels = 1;
  v1 = idImageManager::ScratchImage(this: globalImages, _name: "_noFalloff", imgOpts: &v4);
  idImage::SubImageUpload(
    this: v1,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v4.width,
    height: v4.height,
    pic: v3,
    pixelPitch: v2);
}


// ========================================================================
// ?Dither2Image@idImageIntrinsic@@SAXXZ
// EA  : 0x828D0D58
// RVA : 0x008D0D58
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::Dither2Image()
{
  idImage *v0; // r3
  int v1; // [sp+8h] [-C8h]
  char v2[16]; // [sp+60h] [-70h] BYREF
  idImageOpts v3; // [sp+70h] [-60h] BYREF

  v3.colorFormat = CFM_DEFAULT;
  v3.border.x = 0.0;
  v3.border.y = 0.0;
  v2[3] = 0x80;
  v2[2] = -1;
  v3.border.z = 0.0;
  v3.format = FMT_INT8;
  v3.border.w = 0.0;
  v3.lodBias = 0.0;
  v2[0] = 64;
  v3.lodMinClamp = 0.0;
  v2[1] = -60;
  v3.lodMaxClamp = 13.0;
  v3.repeat = TR_REPEAT;
  v3.aniso = 0.0;
  v3.cubeFilter = false;
  v3.depth = 0;
  v3.textureType = TT_2D;
  v3.packedTail = true;
  v3.readback = false;
  v3.linear = false;
  v3.forceBias = false;
  v3.depthCompareMode = false;
  v3.overlayMemory = false;
  v3.startPurged = false;
  v3.width = 2;
  v3.height = 2;
  v3.filter = TF_NEAREST;
  v3.numLevels = 1;
  v0 = idImageManager::ScratchImage(this: globalImages, _name: "_dither2", imgOpts: &v3);
  idImage::SubImageUpload(
    this: v0,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v3.width,
    height: v3.height,
    pic: v2,
    pixelPitch: v1);
}


// ========================================================================
// ?Dither4Image@idImageIntrinsic@@SAXXZ
// EA  : 0x828D0E60
// RVA : 0x008D0E60
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::Dither4Image()
{
  char v0; // r4
  int v1; // r5
  int v2; // r27
  int v3; // r30
  int v4; // r7
  int v5; // r25
  int v6; // r6
  int i; // r11
  idImage *v8; // r3
  int v9; // [sp+8h] [-118h]
  char v10[16]; // [sp+60h] [-C0h] BYREF
  idImageOpts v11; // [sp+70h] [-B0h] BYREF

  v0 = 16;
  v1 = 2;
  memset(v10, 1, sizeof(v10));
  do
  {
    v2 = 0;
    v3 = 2 * v1;
    v4 = 0;
    v5 = 8 * v1;
    v6 = 4 * v1;
    do
    {
      for ( i = 0; i < 4; i += v3 )
      {
        v10[v6 + i + v1] = v10[v4 + i] + v0;
        v10[v6 + i] = v10[v4 + i] + 2 * v0;
        v10[v1 + v4 + i] = v10[v4 + i] + 3 * v0;
      }
      v2 += v3;
      v4 += v5;
      v6 += v5;
    }
    while ( v2 < 4 );
    v0 *= 4;
    v1 /= 2;
  }
  while ( v1 >= 1 );
  v11.colorFormat = CFM_DEFAULT;
  v11.repeat = TR_REPEAT;
  v11.cubeFilter = false;
  v11.depth = 0;
  v11.textureType = TT_2D;
  v11.packedTail = true;
  v11.readback = false;
  v11.border.x = 0.0;
  v11.linear = false;
  v11.border.y = 0.0;
  v11.forceBias = false;
  v11.border.z = 0.0;
  v11.depthCompareMode = false;
  v11.border.w = 0.0;
  v11.overlayMemory = false;
  v11.lodBias = 0.0;
  v11.startPurged = false;
  v11.lodMinClamp = 0.0;
  v11.format = FMT_INT8;
  v11.lodMaxClamp = 13.0;
  v11.width = 4;
  v11.aniso = 0.0;
  v11.height = 4;
  v11.filter = TF_NEAREST;
  v11.numLevels = 1;
  v8 = idImageManager::ScratchImage(this: globalImages, _name: "_dither4", imgOpts: &v11);
  idImage::SubImageUpload(
    this: v8,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v11.width,
    height: v11.height,
    pic: v10,
    pixelPitch: v9);
}


// ========================================================================
// ?Dither16Image@idImageIntrinsic@@SAXXZ
// EA  : 0x828D1008
// RVA : 0x008D1008
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::Dither16Image()
{
  int v0; // r5
  char v1; // r4
  int v2; // r27
  int v3; // r30
  int v4; // r7
  int v5; // r25
  int v6; // r6
  int i; // r11
  char *v8; // r10
  int j; // r8
  int v10; // r11
  int k; // ctr
  idImage *v12; // r3
  int v13; // [sp+8h] [-208h]
  idImageOpts v14; // [sp+60h] [-1B0h] BYREF
  char v15[352]; // [sp+B0h] [-160h] BYREF

  memset(Dst: v15, Val: 1, Size: 0x100u);
  v0 = 8;
  v1 = 1;
  do
  {
    v2 = 0;
    v3 = 2 * v0;
    v4 = 0;
    v5 = 32 * v0;
    v6 = 16 * v0;
    do
    {
      for ( i = 0; i < 16; i += v3 )
      {
        v15[v6 + i + v0] = v15[v4 + i] + v1;
        v15[v6 + i] = v15[v4 + i] + 2 * v1;
        v15[v0 + v4 + i] = v15[v4 + i] + 3 * v1;
      }
      v2 += v3;
      v4 += v5;
      v6 += v5;
    }
    while ( v2 < 16 );
    v1 *= 4;
    v0 /= 2;
  }
  while ( v0 >= 1 );
  v8 = v15;
  for ( j = 16; j != 0; --j )
  {
    v10 = 0;
    for ( k = 16; k != 0; --k )
    {
      if ( v8[v10] == 0 )
        v8[v10] = 1;
      ++v10;
    }
    v8 += 16;
  }
  v14.colorFormat = CFM_DEFAULT;
  v14.repeat = TR_REPEAT;
  v14.cubeFilter = false;
  v14.depth = 0;
  v14.textureType = TT_2D;
  v14.packedTail = true;
  v14.readback = false;
  v14.border.x = 0.0;
  v14.linear = false;
  v14.border.y = 0.0;
  v14.forceBias = false;
  v14.border.z = 0.0;
  v14.depthCompareMode = false;
  v14.border.w = 0.0;
  v14.overlayMemory = false;
  v14.lodBias = 0.0;
  v14.startPurged = false;
  v14.lodMinClamp = 0.0;
  v14.format = FMT_INT8;
  v14.lodMaxClamp = 13.0;
  v14.width = 16;
  v14.aniso = 0.0;
  v14.height = 16;
  v14.filter = TF_NEAREST;
  v14.numLevels = 1;
  v12 = idImageManager::ScratchImage(this: globalImages, _name: "_dither16", imgOpts: &v14);
  idImage::SubImageUpload(
    this: v12,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v14.width,
    height: v14.height,
    pic: v15,
    pixelPitch: v13);
}


// ========================================================================
// ?Dither256Image@idImageIntrinsic@@SAXXZ
// EA  : 0x828D11D8
// RVA : 0x008D11D8
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

static void __fastcall idImageIntrinsic::Dither256Image()
{
  char *v0; // r24
  char *v1; // r31
  int i; // r25
  int v3; // ctr
  int v4; // r11
  char *v5; // r27
  char *v6; // r29
  int v7; // r30
  double v8; // fp1
  double v9; // fp11
  char v10; // r11
  char *v11; // r8
  char *v12; // r29
  int v13; // r30
  double v14; // fp1
  double v15; // fp11
  char v16; // r10
  char *v17; // r11
  idImage *v18; // r3
  int v19; // [sp+8h] [-108h]
  idImageOpts v20; // [sp+70h] [-A0h] BYREF

  v0 = (char *)idMem::AllocWithLocation(
                 this: &mem,
                 location: "w:\\tech5\\engine\\renderer\\Image_intrinsic.cpp(556) : TAG_IMAGE",
                 size: 0x20000u,
                 tag: TAG_IMAGE,
                 zeroBuffer: false,
                 align: ALIGN_16,
                 heap: HEAP_DEFAULTHEAP);
  v1 = v0;
  for ( i = 256; i != 0; --i )
  {
    v3 = 256;
    v4 = 0;
    v5 = v1;
    do
    {
      *v5 = v4;
      v5[1] = v4++;
      v5 += 2;
      --v3;
    }
    while ( v3 != 0 );
    v6 = v1 - 2;
    v7 = 256;
    do
    {
      v8 = uni();
      v10 = v6[2];
      --v7;
      v11 = &v1[-2 * (int)(float)((float)v8 * (float)v9)];
      v6 += 2;
      *v6 = *v11;
      *v11 = v10;
    }
    while ( v7 != 0 );
    v12 = v1 - 1;
    v13 = 256;
    do
    {
      v14 = uni();
      v16 = v12[2];
      --v13;
      v17 = &v1[-2 * (int)(float)((float)v14 * (float)v15)];
      v12 += 2;
      *v12 = v17[1];
      v17[1] = v16;
    }
    while ( v13 != 0 );
    v1 = v5;
  }
  v20.colorFormat = CFM_DEFAULT;
  v20.repeat = TR_REPEAT;
  v20.cubeFilter = false;
  v20.depth = 0;
  v20.textureType = TT_2D;
  v20.packedTail = true;
  v20.readback = false;
  v20.border.x = 0.0;
  v20.linear = false;
  v20.border.y = 0.0;
  v20.forceBias = false;
  v20.border.z = 0.0;
  v20.depthCompareMode = false;
  v20.border.w = 0.0;
  v20.overlayMemory = false;
  v20.lodBias = 0.0;
  v20.startPurged = false;
  v20.lodMinClamp = 0.0;
  v20.format = FMT_L8A8;
  v20.lodMaxClamp = 13.0;
  v20.width = 256;
  v20.aniso = 0.0;
  v20.height = 256;
  v20.filter = TF_NEAREST;
  v20.numLevels = 1;
  v18 = idImageManager::ScratchImage(this: globalImages, _name: "_dither256", imgOpts: &v20);
  idImage::SubImageUpload(
    this: v18,
    mipLevel: 0,
    destX: 0,
    destY: 0,
    destZ: D3DCUBEMAP_FACE_POSITIVE_X,
    width: v20.width,
    height: v20.height,
    pic: v0,
    pixelPitch: v19);
  idMem::Free(this: &mem, ptr: v0, align: ALIGN_16);
}


// ========================================================================
// ?CreateIntrinsicImages@idImageManager@@QAAXXZ
// EA  : 0x828D13A8
// RVA : 0x008D13A8
// PDB : w:\tech5\engine\renderer\image_intrinsic.cpp
// ========================================================================

void __fastcall idImageManager::CreateIntrinsicImages(idImageManager *this)
{
  long double v1; // fp2
  long double v2; // fp4
  double v3; // fp2
  double v4; // fp1

  idImageIntrinsic::DefaultImage();
  idImageIntrinsic::WhiteImage();
  idImageIntrinsic::BorderedPointWhiteImage();
  idImageIntrinsic::BlackImage();
  idImageIntrinsic::SelectBox();
  idImageIntrinsic::FlatNormalImage();
  idImageIntrinsic::WaveImage(a1: v1);
  idImageIntrinsic::FresnelImage(a1: v4, a2: v3, a3: v2);
  idImageIntrinsic::DefaultCubeImage();
  idImageIntrinsic::NoFalloffImage();
  idImageIntrinsic::Dither2Image();
  idImageIntrinsic::Dither4Image();
  idImageIntrinsic::Dither16Image();
  idImageIntrinsic::Dither256Image();
  globalImages->ps3ReplacementImage = nullptr;
}

