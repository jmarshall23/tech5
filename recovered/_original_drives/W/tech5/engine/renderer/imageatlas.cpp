
// ========================================================================
// ?List@idAtlasResource@@UBAXXZ
// EA  : 0x828C43E0
// RVA : 0x008C43E0
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

void __fastcall idAtlasResource::List(idAtlasResource *this)
{
  idLib::Printf(
    fmt: "%4i , %4i : %4i x %4i %s\n",
    this->img_x * globalImages->transSortImageAtlas->ATLAS_TILE_WIDTH,
    this->img_y * globalImages->transSortImageAtlas->ATLAS_TILE_WIDTH,
    this->img_tiles_wide * globalImages->transSortImageAtlas->ATLAS_TILE_WIDTH,
    this->img_tiles_high * globalImages->transSortImageAtlas->ATLAS_TILE_WIDTH,
    this->name.str);
}


// ========================================================================
// CheckForSpace
// EA  : 0x828C4518
// RVA : 0x008C4518
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

int __fastcall CheckForSpace(const idBitArray *tileAlloc, int x, int y, int w, int h)
{
  int v5; // r29
  int v6; // r8
  unsigned int v7; // r11
  unsigned __int8 *v8; // r11
  char v9; // r10
  char v10; // r9

  v5 = 0;
  if ( w <= 0 )
    return 1;
  while ( 1 )
  {
    v6 = 0;
    if ( h > 0 )
      break;
LABEL_11:
    if ( ++v5 >= w )
      return 1;
  }
  while ( 1 )
  {
    v7 = (v6 + y) * globalImages->transSortImageAtlas->ATLAS_TILES_WIDE + v5 + x;
    if ( v7 >= tileAlloc->bits )
    {
      v8 = nullptr;
      v9 = 0;
      v10 = 0;
    }
    else
    {
      v9 = 1 << (v7 & 7);
      v8 = &tileAlloc->buffer[v7 >> 3];
      v10 = 1;
    }
    if ( v10 != 0 && (unsigned __int8)(*v8 & v9) != 0 )
      return 0;
    if ( ++v6 >= h )
      goto LABEL_11;
  }
}


// ========================================================================
// AllocBlock
// EA  : 0x828C45F0
// RVA : 0x008C45F0
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

int __fastcall AllocBlock(idBitArray *tileAlloc, int *id, int *x, int *y, int w, int h)
{
  idImageManager *v9; // r30
  int v10; // r4
  int i; // r5
  int v13; // r8
  int j; // ctr
  unsigned int v15; // r11
  unsigned __int8 *v16; // r11
  char v17; // r10
  char v18; // r9

  *x = 0;
  if ( globalImages->transSortImageAtlas->ATLAS_TILES_HIGH - w < 0 )
    return 0;
  while ( 1 )
  {
    *id = 0;
    v9 = globalImages;
    if ( globalImages->transSortImageAtlas->ATLAS_TILES_WIDE - (int)y >= 0 )
      break;
LABEL_5:
    if ( ++*x > globalImages->transSortImageAtlas->ATLAS_TILES_HIGH - w )
      return 0;
  }
  while ( (unsigned __int8)CheckForSpace(tileAlloc, x: *id, y: *x, w: (int)y, h: w) == 0 )
  {
    *id = v10 + 1;
    v9 = globalImages;
    if ( v10 + 1 > globalImages->transSortImageAtlas->ATLAS_TILES_WIDE - (int)y )
      goto LABEL_5;
  }
  for ( i = 0; i < (int)y; ++i )
  {
    v13 = 0;
    if ( w > 0 )
    {
      for ( j = w; j != 0; --j )
      {
        v15 = (*x + v13) * v9->transSortImageAtlas->ATLAS_TILES_WIDE + *id + i;
        if ( v15 >= tileAlloc->bits )
        {
          v16 = nullptr;
          v17 = 0;
          v18 = 0;
        }
        else
        {
          v17 = 1 << (v15 & 7);
          v16 = &tileAlloc->buffer[v15 >> 3];
          v18 = 1;
        }
        if ( v18 != 0 )
        {
          *v16 |= v17;
          v9 = globalImages;
        }
        ++v13;
      }
    }
  }
  return 1;
}


// ========================================================================
// ??0idImageAtlas@@QAA@PBDH@Z
// EA  : 0x828C4778
// RVA : 0x008C4778
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

idImageAtlas *__fastcall idImageAtlas::idImageAtlas(idImageAtlas *this, const char *atlasName, int sizeLog2)
{
  idBitArray *p_tileAlloc; // r27
  int v6; // r9
  unsigned __int8 *buffer; // r3
  unsigned int bits; // r11
  size_t v9; // r5
  int ATLAS_WIDTH; // r10
  int ATLAS_HEIGHT; // r8
  int ATLAS_MIP_LEVELS; // r7
  size_t v13; // r28
  void *v14; // r27
  int i; // r28
  int v17; // [sp+8h] [-F8h]
  idImageOpts v18; // [sp+70h] [-90h] BYREF

  p_tileAlloc = &this->tileAlloc;
  this->tileAlloc.buffer = nullptr;
  this->tileAlloc.bits = 0;
  this->tileAlloc.memTag = 9;
  this->tileAlloc.free = false;
  this->ATLAS_HEIGHT_BITS = sizeLog2;
  this->ATLAS_WIDTH_BITS = sizeLog2;
  v6 = 1 << (sizeLog2 - 3);
  this->ATLAS_MIP_LEVELS = 1;
  this->ATLAS_TILES_WIDE = v6;
  this->ATLAS_TILES_HIGH = v6;
  this->ATLAS_WIDTH = 1 << sizeLog2;
  this->ATLAS_HEIGHT = 1 << sizeLog2;
  this->ATLAS_TILES = v6 * v6;
  this->ATLAS_TILE_WIDTH_BITS = 3;
  this->ATLAS_TILE_HEIGHT_BITS = 3;
  this->ATLAS_TILE_WIDTH = 8;
  this->ATLAS_TILE_HEIGHT = 8;
  idBitArray::Alloc(this: &this->tileAlloc, numBits: v6 * v6);
  buffer = this->tileAlloc.buffer;
  if ( buffer != nullptr )
  {
    bits = p_tileAlloc->bits;
    v9 = bits >> 3;
    if ( (bits & 7) != 0 )
      ++v9;
    memset(Dst: buffer, Val: 0, Size: v9);
  }
  ATLAS_WIDTH = this->ATLAS_WIDTH;
  ATLAS_HEIGHT = this->ATLAS_HEIGHT;
  ATLAS_MIP_LEVELS = this->ATLAS_MIP_LEVELS;
  v18.colorFormat = CFM_DEFAULT;
  v18.repeat = TR_REPEAT;
  v18.width = ATLAS_WIDTH;
  v18.height = ATLAS_HEIGHT;
  v18.border.x = 0.0;
  v18.numLevels = ATLAS_MIP_LEVELS;
  v18.border.y = 0.0;
  v18.cubeFilter = false;
  v18.border.z = 0.0;
  v18.depth = 0;
  v18.border.w = 0.0;
  v18.textureType = TT_2D;
  v18.lodBias = 0.0;
  v18.packedTail = true;
  v18.lodMinClamp = 0.0;
  v18.readback = false;
  v18.lodMaxClamp = 13.0;
  v18.linear = false;
  v18.aniso = 0.0;
  v18.forceBias = false;
  v18.depthCompareMode = false;
  v18.overlayMemory = false;
  v18.startPurged = false;
  v18.format = FMT_DXT5;
  v18.filter = TF_LINEAR_MIPMAP_NEAREST;
  this->atlas = idImageManager::ScratchImage(this: globalImages, _name: atlasName, imgOpts: &v18);
  v13 = v18.height * v18.width;
  v14 = idMem::AllocWithLocation(
          this: &mem,
          location: "w:\\tech5\\shared\\idlib\\Heap.h(149) : TAG_TEMP",
          size: v18.height * v18.width,
          tag: TAG_TEMP,
          zeroBuffer: false,
          align: ALIGN_16,
          heap: HEAP_DEFAULTHEAP);
  memset(Dst: v14, Val: 0, Size: v13);
  for ( i = 0; i < v18.numLevels; ++i )
    idImage::SubImageUpload(
      this: this->atlas,
      mipLevel: i,
      destX: 0,
      destY: 0,
      destZ: 0,
      width: v18.width >> i,
      height: v18.height >> i,
      pic: v14,
      pixelPitch: v17);
  if ( v14 != nullptr )
    idMem::Free(this: &mem, ptr: v14, align: ALIGN_16);
  return this;
}


// ========================================================================
// __unwind$222412
// EA  : 0x828C4998
// RVA : 0x008C4998
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

void _unwind_222412()
{
  int v0; // r12

  idBitArray::~idBitArray(this: (idBitArray *)(*(_DWORD *)(v0 - 256 + 276) + 48));
}


// ========================================================================
// __unwind$222413
// EA  : 0x828C49C4
// RVA : 0x008C49C4
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

void _unwind_222413()
{
  int v0; // r12

  idTempArray<idPlane>::~idTempArray<idPlane>(this: (idTempArray<int> *)(v0 - 256 + 96));
}


// ========================================================================
// ?FreeData@idAtlasResource@@AAAXXZ
// EA  : 0x828C49F0
// RVA : 0x008C49F0
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

void __fastcall idAtlasResource::FreeData(idAtlasResource *this)
{
  idImageManager *v1; // r7
  idImageAtlas *transSortImageAtlas; // r11
  int img_tiles_wide; // r30
  int img_tiles_high; // r29
  int v5; // r5
  idBitArray *i; // r8
  int v7; // r6
  int j; // ctr
  unsigned int v9; // r11
  unsigned __int8 *v10; // r11
  char v11; // r10
  char v12; // r9

  v1 = globalImages;
  if ( globalImages != nullptr )
  {
    transSortImageAtlas = globalImages->transSortImageAtlas;
    if ( transSortImageAtlas != nullptr )
    {
      img_tiles_wide = this->img_tiles_wide;
      img_tiles_high = this->img_tiles_high;
      v5 = 0;
      for ( i = &transSortImageAtlas->tileAlloc; v5 < img_tiles_wide; ++v5 )
      {
        v7 = 0;
        if ( img_tiles_high > 0 )
        {
          for ( j = img_tiles_high; j != 0; --j )
          {
            v9 = v1->transSortImageAtlas->ATLAS_TILES_WIDE * (v7 + this->img_y) + v5 + this->img_x;
            if ( v9 >= i->bits )
            {
              v10 = nullptr;
              v11 = 0;
              v12 = 0;
            }
            else
            {
              v11 = 1 << (v9 & 7);
              v10 = &i->buffer[v9 >> 3];
              v12 = 1;
            }
            if ( v12 != 0 )
            {
              *v10 &= ~v11;
              v1 = globalImages;
            }
            ++v7;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?ReloadIfStale@idAtlasResource@@UAA_NXZ
// EA  : 0x828C4AE0
// RVA : 0x008C4AE0
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idAtlasResource::ReloadIfStale(idAtlasResource *this)
{
  BOOL v2; // r30
  __int64 v3; // r10
  __int64 v4; // r8
  int v5; // r29
  const char **v6; // r30
  __int64 v7; // r6
  va *v8; // r3
  __int64 v9; // r6
  va *v10; // r3
  __int64 v11; // r8 OVERLAPPED
  unsigned int v12; // r3
  __int64 v14; // r6
  __int64 v15; // r10
  va *v16; // r3
  int v17; // [sp+8h] [-11E8h]
  int v18; // [sp+Ch] [-11E4h]
  int v19; // [sp+10h] [-11E0h]
  int v20; // [sp+14h] [-11DCh]
  int v21; // [sp+18h] [-11D8h]
  int v22; // [sp+1Ch] [-11D4h]
  idStr v23; // [sp+50h] [-11A0h] BYREF
  idStr v24; // [sp+70h] [-1180h] BYREF
  idStr v25; // [sp+90h] [-1160h] BYREF
  char v26[256]; // [sp+B0h] [-1140h] BYREF
  va v27; // [sp+1B0h] [-1040h] BYREF

  idStr::idStr(this: &v23, text: this->name.str);
  v2 = (_cntlzw(idStr::GetFileExtension(this: &v25, result: &v23)->len) & 0x20) != 0;
  idStr::FreeData(this: &v25);
  if ( v2 )
  {
    v5 = 0;
    if ( imageExtensions[0] != nullptr )
    {
      v6 = imageExtensions;
      while ( 1 )
      {
        HIDWORD(v7) = v23.data;
        LODWORD(v7) = *v6;
        v8 = va::va(
               this: &v27,
               fmt: "%s.%s",
               a3: v7,
               a4: v4,
               a5: v3,
               a6: v17,
               a7: v18,
               a8: v19,
               a9: v20,
               a10: v21,
               a11: v22);
        LODWORD(v4) = fileSystem->FileExists(this: fileSystem, a2: (const char *)v8, a3: false);
        if ( (_DWORD)v4 != 0 )
          break;
        v6 = &imageExtensions[++v5];
        if ( *v6 == nullptr )
          goto LABEL_8;
      }
      LODWORD(v9) = *v6;
      HIDWORD(v9) = v23.data;
      v10 = va::va(
              this: &v27,
              fmt: "%s.%s",
              a3: v9,
              a4: v4,
              a5: v3,
              a6: v17,
              a7: v18,
              a8: v19,
              a9: v20,
              a10: v21,
              a11: v22);
      idStr::operator=(this: &v23, text: v10);
    }
  }
LABEL_8:
  v12 = fileSystem->GetTimestamp(this: fileSystem, a2: v23.data, a3: false);
  if ( v12 == -1 || v12 == this->binaryTimestamp )
  {
    idStr::FreeData(this: &v23);
    return 0;
  }
  else
  {
    HIDWORD(v14) = this->name.str;
    LODWORD(v15) = &off_82230000;
    HIDWORD(v15) = globalImages->transSortImageAtlas;
    *(__int64 *)((char *)&v11 + 4) = *(_QWORD *)(HIDWORD(v15) + 20);
    v16 = va::va(
            this: &v27,
            fmt: "atlasBorder( %s, %d, %d )",
            a3: v14,
            a4: v11,
            a5: v15,
            a6: v17,
            a7: v18,
            a8: v19,
            a9: v20,
            a10: v21,
            a11: v22);
    idStr::idStr(this: &v24, text: v16->buffer);
    idImage::MakeGeneratedName(binaryFileName: v26, maxLen: 256, imgName: v24.data);
    fileSystem->RemoveFile(this: fileSystem, a2: v26, a3: FSPATH_BASE);
    this->LoadResource(this);
    idStr::FreeData(this: &v24);
    idStr::FreeData(this: &v23);
    return 1;
  }
}


// ========================================================================
// __unwind$222766
// EA  : 0x828C4CB4
// RVA : 0x008C4CB4
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

void _unwind_222766()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 80));
}


// ========================================================================
// __unwind$222768
// EA  : 0x828C4CDC
// RVA : 0x008C4CDC
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

void _unwind_222768()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4592 + 112));
}


// ========================================================================
// ?LoadResource@idAtlasResource@@UAAXXZ
// EA  : 0x828C4D80
// RVA : 0x008C4D80
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idAtlasResource::LoadResource(idAtlasResource *this)
{
  __int64 v2; // r10
  int v3; // r3
  __int128 v4; // r7 OVERLAPPED
  va *v5; // r3
  int v6; // r2 OVERLAPPED
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r6
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  int width; // r26
  int height; // r25
  idImageManager *v15; // r9
  int img_tiles_wide; // r6
  idImageAtlas *transSortImageAtlas; // r10
  signed int ATLAS_TILE_WIDTH; // r11
  signed int ATLAS_TILE_HEIGHT; // r10
  int v20; // r5
  int v21; // r4
  int v22; // r23
  int v23; // r27
  int img_tiles_high; // r7
  int v25; // r24
  int i; // r29
  signed int v27; // r11
  int v28; // r8
  unsigned int v29; // r3
  int v30; // r6
  signed int v31; // r11
  int v32; // r10
  int v33; // r7
  int v34; // r9
  idImageManager *v35; // r10
  int v36; // r8
  __int64 v37; // r10
  unsigned int v38; // r8
  __int64 v39; // r6
  idImageAtlas *v40; // r10
  __int64 v41; // r8 OVERLAPPED
  int ATLAS_HEIGHT; // r6
  int v43; // r11
  int v44; // r10
  int v45; // r11
  int v46; // r9
  __int128 v47; // r7 OVERLAPPED
  int v48; // r3
  int v49; // r9
  int img_x; // r3
  double v51; // fp6
  int ATLAS_TILES_WIDE; // r9
  idImageAtlas *v53; // r11
  int v54; // r3
  int img_y; // r10
  int v56; // r30
  int v57; // r29
  int v58; // r27
  int v59; // r24
  int v60; // [sp+8h] [-1288h]
  int v61; // [sp+8h] [-1288h]
  int v62; // [sp+Ch] [-1284h]
  int v63; // [sp+Ch] [-1284h]
  int v64; // [sp+10h] [-1280h]
  int v65; // [sp+10h] [-1280h]
  int v66; // [sp+14h] [-127Ch]
  int v67; // [sp+14h] [-127Ch]
  int v68; // [sp+18h] [-1278h]
  int v69; // [sp+18h] [-1278h]
  int v70; // [sp+1Ch] [-1274h]
  int v71; // [sp+1Ch] [-1274h]
  idStr v72; // [sp+80h] [-1210h] BYREF
  idBinaryImage v73; // [sp+A0h] [-11F0h] BYREF
  char v74[256]; // [sp+130h] [-1160h] BYREF
  va v75; // [sp+230h] [-1060h] BYREF

  if ( globalImages != nullptr && globalImages->transSortImageAtlas != nullptr )
  {
    idAtlasResource::FreeData(this);
    LODWORD(v2) = &off_82230000;
    DWORD1(v4) = *(_DWORD *)(v3 + 8);
    HIDWORD(v2) = globalImages->transSortImageAtlas;
    *((_QWORD *)&v4 + 1) = *(_QWORD *)(HIDWORD(v2) + 20);
    v5 = va::va(
           this: &v75,
           fmt: "atlasBorder( %s, %d, %d )",
           a3: *(__int64 *)((char *)&v4 + 4),
           a4: *(__int64 *)((char *)&v4 - 4),
           a5: v2,
           a6: v60,
           a7: v62,
           a8: v64,
           a9: v66,
           a10: v68,
           a11: v70);
    idStr::idStr(this: &v72, text: v5->buffer);
    idImage::MakeGeneratedName(binaryFileName: v74, maxLen: 256, imgName: v72.data);
    idBinaryImage::idBinaryImage(this: &v73, name: v72.data);
    this->binaryTimestamp = -1;
    v73.opts.format = FMT_DXT5;
    this->scaleBias.x = 1.0;
    this->scaleBias.y = 1.0;
    this->scaleBias.z = 0.0;
    this->scaleBias.w = 0.0;
    if ( (unsigned __int8)idBinaryImage::LoadFromGeneratedFile(this: &v73, binaryFileName: v74) == 0
      || v73.opts.format != FMT_DXT5 )
    {
      v73.opts.format = FMT_DXT5;
      if ( (unsigned __int8)idBinaryImage::LoadFromSourceFile(this: &v73) == 0 )
      {
        HIDWORD(v9) = v72.data;
        idResource::SetResourceError(
          this,
          fmt: "ImageAtlas:: Couldn't load image '%s' from source, defaulting atlas mappings",
          a3: v9,
          a4: v8,
          a5: v7,
          a6: v61,
          a7: v63,
          a8: v65,
          a9: v67,
          a10: v69,
          a11: v71);
        this->img_tiles_wide = 0;
        this->img_tiles_high = 0;
        idBinaryImage::~idBinaryImage(this: &v73);
        goto LABEL_7;
      }
      idBinaryImage::WriteGeneratedFile(this: &v73, binaryFileName: v74);
      if ( v73.opts.format != FMT_DXT5 )
      {
        HIDWORD(v12) = v72.data;
        idResource::SetResourceError(
          this,
          fmt: "ImageAtlas:: Image %s has incompatible compression format. Unable to add to ImageAtlas",
          a3: v12,
          a4: v11,
          a5: v10,
          a6: v61,
          a7: v63,
          a8: v65,
          a9: v67,
          a10: v69,
          a11: v71);
        this->img_tiles_wide = 0;
        this->img_tiles_high = 0;
        idBinaryImage::~idBinaryImage(this: &v73);
        goto LABEL_7;
      }
    }
    width = v73.opts.width;
    height = v73.opts.height;
    this->binaryTimestamp = v73.sourceFileTime;
    this->img_w = width;
    this->img_h = height;
    if ( !idLib::headless )
    {
      v15 = globalImages;
      img_tiles_wide = this->img_tiles_wide;
      transSortImageAtlas = globalImages->transSortImageAtlas;
      ATLAS_TILE_WIDTH = transSortImageAtlas->ATLAS_TILE_WIDTH;
      ATLAS_TILE_HEIGHT = transSortImageAtlas->ATLAS_TILE_HEIGHT;
      v20 = ATLAS_TILE_WIDTH + width - 1;
      v21 = ATLAS_TILE_HEIGHT + height - 1;
      v22 = v20 / ATLAS_TILE_WIDTH;
      __twllei(ATLAS_TILE_WIDTH, 0);
      __twlgei(ATLAS_TILE_WIDTH & ~(__ROL4__(v20, 1) - 1), 0xFFFFFFFF);
      v23 = v21 / ATLAS_TILE_HEIGHT;
      __twllei(ATLAS_TILE_HEIGHT, 0);
      __twlgei(ATLAS_TILE_HEIGHT & ~(__ROL4__(v21, 1) - 1), 0xFFFFFFFF);
      if ( v20 / ATLAS_TILE_WIDTH == img_tiles_wide )
      {
        img_tiles_high = this->img_tiles_high;
        if ( v23 == img_tiles_high )
        {
          if ( (unsigned __int8)CheckForSpace(
                                  tileAlloc: &v15->transSortImageAtlas->tileAlloc,
                                  x: this->img_x,
                                  y: this->img_y,
                                  w: img_tiles_wide,
                                  h: img_tiles_high) != 0 )
          {
            v25 = 0;
            if ( v22 > 0 )
            {
              do
              {
                for ( i = 0; i < v23; ++i )
                  idBitArray::Set(
                    this: &globalImages->transSortImageAtlas->tileAlloc,
                    bitNum: (i + this->img_y) * globalImages->transSortImageAtlas->ATLAS_TILES_WIDE + this->img_x + v25);
                ++v25;
              }
              while ( v25 < v22 );
              height = v73.opts.height;
              width = v73.opts.width;
            }
          }
          else
          {
            this->img_tiles_wide = 0;
          }
        }
      }
      if ( this->img_tiles_wide == 0 )
      {
        v27 = globalImages->transSortImageAtlas->ATLAS_TILE_WIDTH;
        __twllei(v27, 0);
        v28 = v27 + width - 1;
        this->img_tiles_wide = v28 / v27;
        v29 = v27 & ~(__ROL4__(v28, 1) - 1);
        v30 = v28 / v27;
        v31 = globalImages->transSortImageAtlas->ATLAS_TILE_HEIGHT;
        v32 = v31 + height - 1;
        __twllei(v31, 0);
        v33 = v32 / v31;
        v34 = __ROL4__(v32, 1);
        this->img_tiles_high = v32 / v31;
        __twlgei(v29, 0xFFFFFFFF);
        v35 = globalImages;
        v36 = v31 & ~(v34 - 1);
        __twlgei(v36, 0xFFFFFFFF);
        if ( (unsigned __int8)AllocBlock(
                                tileAlloc: &v35->transSortImageAtlas->tileAlloc,
                                id: &this->img_x,
                                x: &this->img_y,
                                y: (int *)v30,
                                w: v33,
                                h: v36) == 0 )
        {
          HIDWORD(v39) = v72.data;
          idResource::SetResourceError(
            this,
            fmt: "ImageAtlas:: Unable to alloc space for image %s in ImageAtlas",
            a3: v39,
            a4: v38,
            a5: v37,
            a6: v61,
            a7: v63,
            a8: v65,
            a9: v67,
            a10: v69,
            a11: v71);
          this->img_tiles_wide = 0;
          this->img_tiles_high = 0;
          idBinaryImage::~idBinaryImage(this: &v73);
          goto LABEL_7;
        }
        height = v73.opts.height;
        width = v73.opts.width;
      }
      v40 = globalImages->transSortImageAtlas;
      HIDWORD(v41) = v40->ATLAS_WIDTH;
      ATLAS_HEIGHT = v40->ATLAS_HEIGHT;
      v43 = HIDWORD(v41) - width;
      v44 = HIDWORD(v41) - width;
      if ( HIDWORD(v41) - width >= 4 )
        v44 = 4;
      LODWORD(v41) = v43 - v44;
      if ( v43 - v44 >= 4 )
        LODWORD(v41) = 4;
      v45 = ATLAS_HEIGHT - height;
      if ( ATLAS_HEIGHT - height >= 4 )
        v45 = 4;
      v46 = ATLAS_HEIGHT - height - v45;
      if ( v46 >= 4 )
        v46 = 4;
      DWORD1(v47) = height - v46 - v45;
      LODWORD(v41) = width - v41 - v44;
      v48 = DWORD1(v47);
      v49 = ATLAS_HEIGHT;
      DWORD2(v47) = v45;
      this->scaleBias.y = (float)*(__int64 *)(&v6 - 1) / (float)*(__int64 *)((char *)&v41 - 4);
      this->scaleBias.x = (float)v41 / (float)*(__int64 *)((char *)&v41 + 4);
      img_x = this->img_x;
      v51 = (float)((float)*(__int64 *)((char *)&v47 + 4) / (float)*(__int64 *)((char *)&v41 - 4));
      ATLAS_TILES_WIDE = globalImages->transSortImageAtlas->ATLAS_TILES_WIDE;
      this->scaleBias.z = (float)((float)*(__int64 *)(&v6 - 1) / (float)*(__int64 *)((char *)&v41 - 4))
                        + (float)((float)__SPAIR64__(v41, v44) / (float)*(__int64 *)((char *)&v41 + 4));
      LODWORD(v47) = this->img_y;
      DWORD2(v47) = globalImages->transSortImageAtlas;
      HIDWORD(v47) = *(_DWORD *)(DWORD2(v47) + 40);
      this->scaleBias.w = (float)((float)(__int64)v47 / (float)*(__int64 *)((char *)&v47 + 12)) + (float)v51;
      v53 = globalImages->transSortImageAtlas;
      v54 = this->img_x;
      img_y = this->img_y;
      v56 = 0;
      v57 = v53->ATLAS_TILE_WIDTH * v54;
      v58 = v53->ATLAS_TILE_HEIGHT * img_y;
      if ( v53->ATLAS_MIP_LEVELS > 0 )
      {
        v59 = 0;
        do
        {
          if ( v56 >= v73.images.num )
            break;
          idImage::SubImageUpload(
            this: v53->atlas,
            mipLevel: v56,
            destX: v57,
            destY: v58,
            destZ: 0,
            width,
            height,
            pic: v73.images.list[v59].data.list,
            pixelPitch: v61);
          v57 >>= 1;
          ++v56;
          v58 >>= 1;
          width >>= 1;
          height >>= 1;
          ++v59;
          v53 = globalImages->transSortImageAtlas;
        }
        while ( v56 < v53->ATLAS_MIP_LEVELS );
      }
    }
    idBinaryImage::~idBinaryImage(this: &v73);
LABEL_7:
    idStr::FreeData(this: &v72);
    return;
  }
  idLib::FatalError(fmt: "idAtlasResource::LoadResource atlas not allocated yet");
  _LN147_0();
}


// ========================================================================
// $LN147_0
// EA  : 0x828C5314
// RVA : 0x008C5314
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

void _LN147_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4752 + 128));
}


// ========================================================================
// __unwind$223150_0
// EA  : 0x828C533C
// RVA : 0x008C533C
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

void _unwind_223150_0()
{
  int v0; // r12

  idBinaryImage::~idBinaryImage(this: (idBinaryImage *)(v0 - 4752 + 160));
}


// ========================================================================
// `dynamic initializer for 'idAtlasResource::resourceList''
// EA  : 0x8334BD58
// RVA : 0x0134BD58
// PDB : w:\tech5\engine\renderer\imageatlas.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idAtlasResource::resourceList__()
{
  idResourceList::idResourceList(this: &idAtlasResource::resourceList, typeName: "atlas");
  idAtlasResource::resourceList.__vftable = (idTypedResourceList<idAtlasResource>_vtbl *)&idTypedResourceList<idAtlasResource>::`vftable';
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idAtlasResource::resourceList__);
}

