
// ========================================================================
// ?BindNull@idImageManager@@QAAXXZ
// EA  : 0x828C5390
// RVA : 0x008C5390
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __fastcall idImageManager::BindNull(idImageManager *this)
{
  idDeclRenderProg::BindTexture(image: this->whiteImage, texUnit: 0);
}


// ========================================================================
// ?CreateTestCube_f@@YAXABVidCmdArgs@@@Z
// EA  : 0x828C53A0
// RVA : 0x008C53A0
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __fastcall CreateTestCube_f(const idCmdArgs *args)
{
  unsigned __int8 v1; // [sp+50h] [-20h] BYREF
  char v2; // [sp+51h] [-1Fh]
  char v3; // [sp+52h] [-1Eh]
  char v4; // [sp+53h] [-1Dh]

  v4 = -1;
  v1 = -1;
  v2 = 0;
  v3 = 0;
  R_WriteTGA(
    filename: "env/primary_px.tga",
    data: &v1,
    width: 1,
    height: 1,
    depth: 4,
    flipVertical: false,
    swapRGB: true,
    basePath: FSPATH_BASE);
  v1 = 0;
  v2 = -1;
  v3 = 0;
  R_WriteTGA(
    filename: "env/primary_nx.tga",
    data: &v1,
    width: 1,
    height: 1,
    depth: 4,
    flipVertical: false,
    swapRGB: true,
    basePath: FSPATH_BASE);
  v1 = 0;
  v2 = 0;
  v3 = -1;
  R_WriteTGA(
    filename: "env/primary_py.tga",
    data: &v1,
    width: 1,
    height: 1,
    depth: 4,
    flipVertical: false,
    swapRGB: true,
    basePath: FSPATH_BASE);
  v1 = -1;
  v2 = -1;
  v3 = 0;
  R_WriteTGA(
    filename: "env/primary_ny.tga",
    data: &v1,
    width: 1,
    height: 1,
    depth: 4,
    flipVertical: false,
    swapRGB: true,
    basePath: FSPATH_BASE);
  v1 = 0;
  v2 = 0;
  v3 = 0;
  R_WriteTGA(
    filename: "env/primary_pz.tga",
    data: &v1,
    width: 1,
    height: 1,
    depth: 4,
    flipVertical: false,
    swapRGB: true,
    basePath: FSPATH_BASE);
  v1 = 0;
  v2 = -1;
  v3 = -1;
  R_WriteTGA(
    filename: "env/primary_nz.tga",
    data: &v1,
    width: 1,
    height: 1,
    depth: 4,
    flipVertical: false,
    swapRGB: true,
    basePath: FSPATH_BASE);
}


// ========================================================================
// ClassifyImage
// EA  : 0x828C5548
// RVA : 0x008C5548
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

int __fastcall ClassifyImage(const char *name)
{
  int v1; // r29
  const imageClassificate_t *v2; // r30
  int type; // r30
  idStr v5[2]; // [sp+50h] [-50h] BYREF

  v1 = 0;
  v5[0].len = 0;
  v5[0].baseBuffer[0] = 0;
  v5[0].allocedAndFlag = 20;
  v5[0].data = v5[0].baseBuffer;
  idStr::operator=(this: v5, text: name);
  v2 = IC_Info;
  while ( idStr::Find(searchIn: v5[0].data, searchFor: v2->rootPath, casesensitive: false, start: 0, end: v5[0].len) != 0 )
  {
    ++v2;
    ++v1;
    if ( (int)v2 >= (int)"env/primary_nz.tga" )
    {
      idStr::FreeData(this: v5);
      return 10;
    }
  }
  type = IC_Info[v1].type;
  idStr::FreeData(this: v5);
  return type;
}


// ========================================================================
// __unwind$230320
// EA  : 0x828C55F8
// RVA : 0x008C55F8
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void _unwind_230320()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?ChangeTextureFilter@idImageManager@@QAAXXZ
// EA  : 0x828C5620
// RVA : 0x008C5620
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __fastcall idImageManager::ChangeTextureFilter(idImageManager *this)
{
  int v2; // r27
  char *data; // r25
  idImageManager::ChangeTextureFilter::__l2::filterName_t *v4; // r29
  double valueFloat; // fp13

  v2 = 0;
  data = idImageManager::image_filter.valueString.data;
  idImageManager::image_lodbias.flags &= ~0x20000u;
  v4 = textureFilters;
  idImageManager::image_filter.flags &= ~0x20000u;
  idImageManager::image_anisotropy.flags &= ~0x20000u;
  do
  {
    if ( idStr::Icmp(s1: v4->name, s2: data) == 0 )
      break;
    ++v4;
    ++v2;
  }
  while ( (int)v4 < (int)&BICUBIC_0 );
  if ( v2 == 6 )
  {
    idLib::Warning(fmt: "bad r_textureFilter: '%s'", data);
    v2 = 2;
  }
  this->textureMinFilter = textureFilters[v2].minimize;
  this->textureMaxFilter = textureFilters[v2].maximize;
  this->textureMipFilter = textureFilters[v2].mipimize;
  valueFloat = idImageManager::image_anisotropy.valueFloat;
  this->textureAnisotropy = idImageManager::image_anisotropy.valueFloat;
  if ( valueFloat < 1.0 )
    this->textureAnisotropy = 1.0;
  this->textureLODBias = idImageManager::image_lodbias.valueFloat;
}


// ========================================================================
// R_QsortImageSizes
// EA  : 0x828C5718
// RVA : 0x008C5718
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

int __fastcall R_QsortImageSizes(_DWORD *a, _DWORD *b)
{
  int v2; // r11
  int v3; // r10

  v2 = a[1];
  v3 = b[1];
  if ( v2 > v3 )
    return -1;
  if ( v2 >= v3 )
    return idStr::Icmp(s1: *(const char **)(*a + 8), s2: *(const char **)(*b + 8));
  return 1;
}


// ========================================================================
// ?AllocImage@idImageManager@@QAAPAVidImage@@PBD@Z
// EA  : 0x828C5758
// RVA : 0x008C5758
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

idImage *__fastcall idImageManager::AllocImage(idImageManager *this, const char *name)
{
  int v3; // r11
  idImage *v4; // r3
  idImage *v5; // r30

  v3 = 0;
  if ( *name != 0 )
  {
    do
      ++v3;
    while ( name[v3] != 0 );
    if ( v3 >= 1024 )
      idLib::Error(fmt: "idImageManager::AllocImage: \"%s\" is too long\n", name);
  }
  v4 = (idImage *)idMem::AllocWithLocation(
                    this: &mem,
                    location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                    size: 0x144u,
                    tag: TAG_IMAGE,
                    zeroBuffer: false,
                    align: ALIGN_16,
                    heap: HEAP_DEFAULTHEAP);
  if ( v4 != nullptr )
    v5 = idImage::idImage(this: v4);
  else
    v5 = nullptr;
  idResource::SetName(this: &v5->idResource, _name: name);
  idResourceList::Add(this: &idImage::resourceList, ptr: (idResourceList_vtbl *)v5);
  return v5;
}


// ========================================================================
// $LN16_2
// EA  : 0x828C5810
// RVA : 0x008C5810
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void _LN16_2()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 128 + 80), tag: TAG_IMAGE);
}


// ========================================================================
// ?ImageFromFile@idImageManager@@QAAPAVidImage@@PBDPAVidImageOpts@@_N@Z
// EA  : 0x828C5840
// RVA : 0x008C5840
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

idImage *__fastcall idImageManager::ImageFromFile(
        idImageManager *this,
        char *_name,
        idImageOpts *opts_p,
        bool makeDefault)
{
  idImageOpts *p_newImageOpts; // r3
  const idImageOpts *v7; // r4
  _DWORD v9[5]; // [sp+50h] [-70h] BYREF
  char v10; // [sp+64h] [-5Ch]
  char v11; // [sp+65h] [-5Bh]
  char v12; // [sp+66h] [-5Ah]
  char v13; // [sp+67h] [-59h]
  char v14; // [sp+68h] [-58h]
  char v15; // [sp+69h] [-57h]
  int v16; // [sp+6Ch] [-54h]
  int v17; // [sp+70h] [-50h]
  int v18; // [sp+74h] [-4Ch]
  int v19; // [sp+78h] [-48h]
  float v20; // [sp+7Ch] [-44h]
  float v21; // [sp+80h] [-40h]
  float v22; // [sp+84h] [-3Ch]
  float v23; // [sp+88h] [-38h]
  float v24; // [sp+8Ch] [-34h]
  float v25; // [sp+90h] [-30h]
  float v26; // [sp+94h] [-2Ch]
  float v27; // [sp+98h] [-28h]
  char v28; // [sp+9Ch] [-24h]
  char v29; // [sp+9Dh] [-23h]

  p_newImageOpts = &this->newImageOpts;
  if ( opts_p != nullptr )
  {
    v7 = opts_p;
  }
  else
  {
    v16 = 0;
    v17 = 0;
    v18 = 5;
    v20 = 0.0;
    v19 = 0;
    v21 = 0.0;
    v13 = 0;
    v22 = 0.0;
    v23 = 0.0;
    v24 = 0.0;
    v25 = 0.0;
    v26 = 13.0;
    memset(v9, 0, sizeof(v9));
    v27 = 0.0;
    v10 = 1;
    v11 = 0;
    v7 = (const idImageOpts *)v9;
    v12 = 0;
    v28 = 0;
    v29 = 0;
    v14 = 0;
    v15 = 0;
  }
  idImageOpts::operator=(this: p_newImageOpts, __that: v7);
  return (idImage *)idResourceList::Load(this: &idImage::resourceList, name: _name, makeDefault, skipStaleCheck: false);
}


// ========================================================================
// ?CheckCvars@idImageManager@@QAAXXZ
// EA  : 0x828C5928
// RVA : 0x008C5928
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __fastcall idImageManager::CheckCvars(idImageManager *this)
{
  if ( (idImageManager::image_filter.flags & 0x20000) != 0
    || (idImageManager::image_anisotropy.flags & 0x20000) != 0
    || (idImageManager::image_lodbias.flags & 0x20000) != 0 )
  {
    idImageManager::ChangeTextureFilter(this);
  }
}


// ========================================================================
// ?UnbindAll@idImageManager@@QAAXXZ
// EA  : 0x828C5978
// RVA : 0x008C5978
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __fastcall idImageManager::UnbindAll(idImageManager *this)
{
  int i; // r31

  if ( !idLib::headless )
  {
    for ( i = 15; i >= 0; --i )
      idDeclRenderProg::BindTexture(image: this->whiteImage, texUnit: i);
  }
}


// ========================================================================
// ?PurgeAllOverlays@idImageManager@@QAAXXZ
// EA  : 0x828C59D0
// RVA : 0x008C59D0
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __fastcall idImageManager::PurgeAllOverlays(idImageManager *this)
{
  int i; // r31
  idImage *v2; // r3

  idLib::Printf(fmt: "Purging Overlays\n");
  renderSystem->SyncRenderThread(this: renderSystem, a2: true);
  for ( i = 0; i < idImage::resourceList.num; ++i )
  {
    v2 = (idImage *)idResourceList::Index(this: &idImage::resourceList, index: i);
    if ( v2->opts.overlayMemory )
      idImage::PurgeImage(this: v2);
  }
}


// ========================================================================
// ?ScratchImage@idImageManager@@QAAPAVidImage@@PBDPAVidImageOpts@@@Z
// EA  : 0x828C5A70
// RVA : 0x008C5A70
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

idImage *__fastcall idImageManager::ScratchImage(idImageManager *this, const char *_name, idImageOpts *imgOpts)
{
  idImageOpts *v4; // r29
  idImage *Existing; // r30
  idStr v7; // [sp+50h] [-A0h] BYREF
  idImageOpts v8; // [sp+70h] [-80h] BYREF

  v4 = imgOpts;
  if ( _name != nullptr && *_name != 0 )
  {
    if ( imgOpts == nullptr )
      idLib::FatalError(fmt: "idImageManager::ScratchImage called with NULL imgOpts");
    idStr::idStr(this: &v7, text: _name);
    Existing = (idImage *)idResourceList::FindExisting(
                            this: &idImage::resourceList,
                            name: v7.data,
                            skipStaleCheck: false);
    idImageOpts::idImageOpts(this: &v8);
    if ( v4->textureType == TT_CUBIC && v4->repeat != TR_CLAMP )
    {
      idImageOpts::operator=(this: &v8, __that: v4);
      v4 = &v8;
      v8.repeat = TR_CLAMP;
    }
    if ( Existing != nullptr )
      idImage::PurgeImage(this: Existing);
    else
      Existing = idImageManager::AllocImage(this, name: v7.data);
    *((_BYTE *)&Existing->idResource + 32) &= ~0x80u;
    if ( v4->startPurged )
      idImageOpts::operator=(this: &Existing->opts, __that: v4);
    else
      idImage::AllocImage(this: Existing, imgOpts: v4);
    idStr::FreeData(this: &v7);
    return Existing;
  }
  else
  {
    idLib::FatalError(fmt: "idImageManager::ScratchImage called with empty name");
    return _LN36_3();
  }
}


// ========================================================================
// $LN36_3
// EA  : 0x828C5B7C
// RVA : 0x008C5B7C
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void _LN36_3()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 240 + 80));
}


// ========================================================================
// ?WriteImage_f@idImageManager@@SAXABVidCmdArgs@@@Z
// EA  : 0x828C5BA8
// RVA : 0x008C5BA8
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __fastcall idImageManager::WriteImage_f(const idCmdArgs *args)
{
  char *v2; // r4
  idImage *v3; // r3
  idImageData *ImageData; // r3
  idImageData *v5; // r31
  const char *v6; // r6
  const char *v7; // r3
  unsigned __int8 *data; // r4
  float *floatData; // r4

  if ( args->argc >= 3 )
  {
    if ( args->argc <= 2 )
      v2 = &byte_8200D768;
    else
      v2 = args->argv[2];
    v3 = idImageManager::ImageFromFile(this: globalImages, _name: v2, opts_p: nullptr, makeDefault: true);
    ImageData = idImage::GetImageData(this: v3, mipLevel: 0, z: 0);
    v5 = ImageData;
    if ( args->argc <= 1 )
      v6 = &byte_8200D768;
    else
      v6 = args->argv[1];
    idLib::Printf(fmt: "Writing %ix%i image to %s\n", ImageData->width, ImageData->height, v6);
    if ( args->argc <= 1 )
      v7 = &byte_8200D768;
    else
      v7 = args->argv[1];
    R_WriteTGA(
      filename: v7,
      data: v5->data,
      width: v5->width,
      height: v5->height,
      depth: 4,
      flipVertical: false,
      swapRGB: true,
      basePath: FSPATH_BASE);
    data = v5->data;
    if ( data != nullptr )
      idMem::Free(this: &mem, ptr: data, align: ALIGN_16);
    floatData = v5->floatData;
    if ( floatData != nullptr )
      idMem::Free(this: &mem, ptr: floatData, align: ALIGN_16);
    idMem::Free(this: &mem, ptr: v5, align: ALIGN_16);
  }
  else
  {
    idLib::Printf(fmt: "usage: writeImage <destFile> <imageProgram>\n");
  }
}


// ========================================================================
// ?ListImages_f@idImageManager@@SAXABVidCmdArgs@@@Z
// EA  : 0x828C5E40
// RVA : 0x008C5E40
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __fastcall idImageManager::ListImages_f(const idCmdArgs *args)
{
  int argc; // r25
  int v3; // r24
  const char **v4; // r21
  const char *v5; // r3
  const char *v6; // r3
  const char *v7; // r3
  const char *v8; // r3
  const char *v9; // r3
  const char *v10; // r3
  const char *v11; // r3
  const char *v12; // r3
  const char *v13; // r3
  const char *v14; // r3
  const char *v15; // r3
  const char *v16; // r3
  const char *v17; // r3
  bool v18; // cr56
  int v19; // r24
  unsigned int v20; // r20
  int num; // r5
  int v22; // r12
  int v23; // r23
  unsigned int v24; // r16
  char v25; // r14
  int v26; // r29
  char *v27; // r28
  idImage *v28; // r3
  idImage *v29; // r30
  int v30; // r25
  unsigned int v31; // r28
  int v32; // r30
  idImage **v33; // r29
  __int64 v34; // r10
  int v35; // r30
  int v36; // r11
  int v37; // r3
  int v38; // r22
  __int64 v39; // r11
  int v40; // r28
  int *p_maxHeight; // r23
  encounterGroupRole_t *list; // r25
  int v43; // r30
  int v44; // r27
  int v45; // r26
  int v46; // r5
  int v47; // r30
  const encounterGroupRole_t *v48; // r4
  const char *v49; // r4
  encounterGroupRole_t *v50; // r29
  _DWORD back_chain[6]; // [sp+0h] [-200h]
  double v52; // [sp+18h] [-1E8h]
  double v53; // [sp+20h] [-1E0h]
  double v54; // [sp+28h] [-1D8h]
  char v55; // [sp+50h] [-1B0h] BYREF
  char v56; // [sp+51h] [-1AFh]
  char v57; // [sp+52h] [-1AEh]
  char v58; // [sp+53h] [-1ADh]
  char v59; // [sp+54h] [-1ACh]
  unsigned __int8 v60; // [sp+55h] [-1ABh]
  char v61; // [sp+56h] [-1AAh]
  char v62; // [sp+57h] [-1A9h]
  char v63; // [sp+58h] [-1A8h]
  char v64; // [sp+59h] [-1A7h]
  unsigned __int8 v65; // [sp+5Ah] [-1A6h]
  char v66; // [sp+5Bh] [-1A5h]
  char v67; // [sp+5Ch] [-1A4h]
  encounterGroupRole_t v68[2]; // [sp+60h] [-1A0h] BYREF
  unsigned __int64 v69; // [sp+68h] [-198h]
  const char *v70; // [sp+70h] [-190h]
  idList<enum encounterGroupRole_t,5> v71; // [sp+80h] [-180h] BYREF
  idList<idVehicleState *,5> v72; // [sp+90h] [-170h] BYREF
  unsigned __int64 v73; // [sp+A0h] [-160h]
  _BYTE v74[176]; // [sp+B0h] [-150h] BYREF

  argc = args->argc;
  v3 = 1;
  v68[0] = ROLE_NONE;
  v62 = 0;
  v61 = 0;
  v59 = 0;
  v55 = 0;
  v57 = 0;
  HIDWORD(v69) = argc;
  v60 = 0;
  v56 = 0;
  v65 = 0;
  v67 = 0;
  v66 = 0;
  v64 = 0;
  v58 = 0;
  v63 = 0;
  if ( argc > 1 )
  {
    v4 = (const char **)&args->argv[1];
    HIDWORD(v73) = "scratch";
    v70 = "unloaded";
    do
    {
      if ( v3 < 0 || v3 >= argc )
        v5 = &byte_8200D768;
      else
        v5 = *v4;
      if ( idStr::Icmp(s1: v5, s2: "uncompressed") != 0 )
      {
        if ( v3 < 0 || v3 >= args->argc )
          v6 = &byte_8200D768;
        else
          v6 = *v4;
        if ( idStr::Icmp(s1: v6, s2: "active") != 0 )
        {
          if ( v3 < 0 || v3 >= args->argc )
            v7 = &byte_8200D768;
          else
            v7 = *v4;
          if ( idStr::Icmp(s1: v7, s2: v70) != 0 )
          {
            if ( v3 < 0 || v3 >= args->argc )
              v8 = &byte_8200D768;
            else
              v8 = *v4;
            if ( idStr::Icmp(s1: v8, s2: (const char *)HIDWORD(v73)) != 0 )
            {
              if ( v3 < 0 || v3 >= args->argc )
                v9 = &byte_8200D768;
              else
                v9 = *v4;
              if ( idStr::Icmp(s1: v9, s2: "files") != 0 )
              {
                if ( v3 < 0 || v3 >= args->argc )
                  v10 = &byte_8200D768;
                else
                  v10 = *v4;
                if ( idStr::Icmp(s1: v10, s2: "sorted") != 0 )
                {
                  if ( v3 < 0 || v3 >= args->argc )
                    v11 = &byte_8200D768;
                  else
                    v11 = *v4;
                  if ( idStr::Icmp(s1: v11, s2: "touched") != 0 )
                  {
                    if ( v3 < 0 || v3 >= args->argc )
                      v12 = &byte_8200D768;
                    else
                      v12 = *v4;
                    if ( idStr::Icmp(s1: v12, s2: "cubes") != 0 )
                    {
                      if ( v3 < 0 || v3 >= args->argc )
                        v13 = &byte_8200D768;
                      else
                        v13 = *v4;
                      if ( idStr::Icmp(s1: v13, s2: "isolated") != 0 )
                      {
                        if ( v3 < 0 || v3 >= args->argc )
                          v14 = &byte_8200D768;
                        else
                          v14 = *v4;
                        if ( idStr::Icmp(s1: v14, s2: "block") != 0 )
                        {
                          if ( v3 < 0 || v3 >= args->argc )
                            v15 = &byte_8200D768;
                          else
                            v15 = *v4;
                          if ( idStr::Icmp(s1: v15, s2: "overlay") != 0 )
                          {
                            if ( v3 < 0 || v3 >= args->argc )
                              v16 = &byte_8200D768;
                            else
                              v16 = *v4;
                            if ( idStr::Icmp(s1: v16, s2: "classify") != 0 )
                            {
                              if ( v3 < 0 || v3 >= args->argc )
                                v17 = &byte_8200D768;
                              else
                                v17 = *v4;
                              if ( idStr::Icmp(s1: v17, s2: "oversized") != 0 )
                              {
                                v62 = 1;
                              }
                              else
                              {
                                v57 = 1;
                                v55 = 1;
                                v60 = 1;
                              }
                            }
                            else
                            {
                              v57 = 1;
                              v55 = 1;
                            }
                          }
                          else
                          {
                            v63 = 1;
                          }
                        }
                        else
                        {
                          v58 = 1;
                        }
                      }
                      else
                      {
                        v64 = 1;
                      }
                    }
                    else
                    {
                      v65 = 1;
                    }
                  }
                  else
                  {
                    v59 = 1;
                  }
                }
                else
                {
                  v55 = 1;
                }
              }
              else
              {
                v66 = 1;
              }
            }
            else
            {
              v67 = 1;
            }
          }
          else
          {
            v56 = 1;
          }
        }
        else
        {
          v56 = 1;
        }
      }
      else
      {
        v61 = 1;
      }
      argc = args->argc;
      ++v3;
      ++v4;
      v18 = v3 < args->argc;
      HIDWORD(v69) = args->argc;
    }
    while ( v18 );
  }
  if ( v62 != 0 )
  {
    idLib::Printf(
      fmt: "usage: listImages [unloaded] [scratch] [files] [cubes] [covers] [isolated] [block] [ active | sorted | touched | c"
      "lassify | oversized ]\n");
    return;
  }
  idLib::Printf(fmt: "\n%s", "       -w-- -h-- lv filt -fmt-- wrap  size- --name-------\n");
  v19 = 0;
  v20 = 0;
  *(_WORD *)&v72.memTag = 8704;
  memset(&v72, 0, 14);
  idResourceList::GetLoadedResources(this: &idImage::resourceList, resourceList: &v72);
  ((void (*)(void))RtlCheckStack12)();
  num = v72.num;
  *(_DWORD *)((char *)back_chain + v22) = back_chain[0];
  if ( num > 0 )
  {
    v23 = v65;
    v24 = v68[0];
    v25 = v55;
    v26 = 0;
    v27 = &v55;
    while ( 1 )
    {
      HIDWORD(v69) = &v72.list[v26];
      v28 = (idImage *)_RTDynamicCast(
                         inptr: v72.list[v26],
                         VfDelta: 0,
                         SrcType: &idResource `RTTI Type Descriptor',
                         TargetType: (void *)&idImage `RTTI Type Descriptor',
                         isReference: 0);
      v29 = v28;
      if ( (v23 == 0 || v28->opts.textureType == TT_CUBIC)
        && (v56 == 0 || v28->frameUsed >= tr.frameCount - 1)
        && (v61 == 0 || (unsigned __int8)idImage::IsCompressed(this: v28) != 0)
        && (v67 == 0 || (*((_BYTE *)&v29->idResource + 32) & 0x80) == 0)
        && (v66 == 0 || (*((_BYTE *)&v29->idResource + 32) & 0x80) != 0)
        && (v64 == 0
         || !idPhysicalMemoryBlock::AddressIsInReservedPhysicalMemoryBlock(
               this: &physicalMemoryBlock,
               pAddress: v29->imageBuffer))
        && (v58 == 0
         || idPhysicalMemoryBlock::AddressIsInReservedPhysicalMemoryBlock(
              this: &physicalMemoryBlock,
              pAddress: v29->imageBuffer))
        && (v63 == 0
         || idPhysicalMemoryBlock::AddressIsInOverlayPhysicalMemoryBlock(
              this: &physicalMemoryBlock,
              pAddress: v29->imageBuffer)) )
      {
        if ( v59 == 0 )
          goto LABEL_106;
        if ( v29->bindCount != 0 )
          break;
      }
LABEL_110:
      ++v19;
      ++v26;
      if ( v19 >= v72.num )
      {
        v68[0] = v24;
        goto LABEL_112;
      }
    }
    v29->bindCount = 0;
LABEL_106:
    if ( v25 != 0 )
    {
      *(_DWORD *)v27 = v29;
      *((_DWORD *)v27 + 1) = v29->physicalMemoryBytes;
    }
    else
    {
      idLib::Printf(fmt: "%4i:", v19);
      v29->Print(this: v29);
    }
    v20 += idImage::StorageSize(this: v29);
    ++v24;
    v27 += 8;
    goto LABEL_110;
  }
LABEL_112:
  v30 = v68[0];
  if ( v55 != 0 )
  {
    qsort(base: &v55, num: v68[0], width: 8u, comp: (int (__fastcall *)(const void *, const void *))R_QsortImageSizes);
    v31 = 0;
    v32 = 0;
    if ( v30 > 0 )
    {
      v33 = (idImage **)&v55;
      do
      {
        idLib::Printf(fmt: "%4i:", v32);
        (*v33)->Print(this: *v33);
        ++v32;
        v31 += idImage::StorageSize(this: *v33);
        if ( v32 == 10 * (v32 / 10) )
        {
          LODWORD(v34) = v31;
          v69 = v34;
          v73 = __PAIR64__(v31, v20);
          v53 = (double)__SPAIR64__(v31, v20) * 0.00000095367431640625;
          v52 = (double)v34 * 0.00000095367431640625;
          idLib::Printf(fmt: (const char *)HIDWORD(v52), LODWORD(v52), LODWORD(v53));
        }
        v33 += 2;
      }
      while ( v32 < v30 );
    }
  }
  idLib::Printf(fmt: "%s", "       -w-- -h-- lv filt -fmt-- wrap  size- --name-------\n");
  idLib::Printf(fmt: " %i images (%i total)\n", v30, idImage::resourceList.num);
  v69 = __PAIR64__(&unk_821C0000, v20);
  v52 = (float)((float)__SPAIR64__(&unk_821C0000, v20) * (float)0.00000095367432);
  idLib::Printf(fmt: (const char *)HIDWORD(v52), LODWORD(v52));
  if ( v57 != 0 )
  {
    `eh vector constructor iterator'(
      ptr: v74,
      size: 0x10u,
      count: 11,
      pCtor: (void (__fastcall *)(void *))idList<int,34>::idList<int,34>,
      pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
    v35 = 0;
    v68[0] = ROLE_NONE;
    if ( v30 > 0 )
    {
      v36 = 0;
      do
      {
        v37 = ClassifyImage(name: *(const char **)(*(_DWORD *)(&v55 + v36) + 8));
        idList<idAnimWebBlendTree *,5>::Append(this: (idList<enum encounterGroupRole_t,5> *)&v74[16 * v37], obj: v68);
        v68[0] = ++v35;
        v36 = 8 * v35;
      }
      while ( v35 < v30 );
    }
    v38 = v60;
    HIDWORD(v39) = &off_82230000;
    v40 = 0;
    p_maxHeight = &IC_Info[0].maxHeight;
    do
    {
      list = nullptr;
      v43 = 0;
      *(_WORD *)&v71.memTag = 8704;
      v44 = 0;
      memset(&v71, 0, 14);
      v45 = 0;
      HIDWORD(v69) = *(_DWORD *)&v74[v40 + 4];
      v46 = HIDWORD(v69);
      if ( SHIDWORD(v69) > 0 )
      {
        v47 = 0;
        do
        {
          v44 += idImage::StorageSize(this: *((idImage **)&v55 + 2 * *(_DWORD *)(v47 + *(_DWORD *)&v74[v40])));
          if ( v38 != 0 )
          {
            HIDWORD(v39) = *(p_maxHeight - 1);
            v48 = (const encounterGroupRole_t *)(v47 + *(_DWORD *)&v74[v40]);
            LODWORD(v39) = *((_DWORD *)&v55 + 2 * *v48);
            if ( *(_DWORD *)(v39 + 64) > SHIDWORD(v39) )
            {
              HIDWORD(v39) = *p_maxHeight;
              if ( *(_DWORD *)(v39 + 68) > *p_maxHeight )
                idList<idAnimWebBlendTree *,5>::Append(this: &v71, obj: v48);
            }
          }
          ++v45;
          v47 += 4;
          HIDWORD(v69) = *(_DWORD *)&v74[v40 + 4];
          v46 = HIDWORD(v69);
        }
        while ( v45 < SHIDWORD(v69) );
        v43 = v71.num;
        list = v71.list;
      }
      LODWORD(v39) = v44;
      v49 = (const char *)*(p_maxHeight - 3);
      HIDWORD(v69) = v46;
      v73 = v39;
      v54 = (double)v39 * 0.00000095367431640625;
      idLib::Printf(fmt: " Classification %s contains %i images using %5.1f megabytes\n", v49, HIDWORD(v54), v54);
      if ( v38 != 0 && v43 != 0 )
      {
        idLib::Printf(fmt: "  The following images may be oversized\n");
        if ( v43 > 0 )
        {
          v50 = list - 1;
          do
          {
            idLib::Printf(fmt: "    ");
            ++v50;
            (*(void (__fastcall **)(_DWORD))(**((_DWORD **)&v55 + 2 * *v50) + 20))(a1: *((_DWORD *)&v55 + 2 * *v50));
            idLib::Printf(fmt: "\n");
            --v43;
          }
          while ( v43 != 0 );
        }
      }
      if ( v71.listStatic == 0 || v71.listStatic == 2 )
      {
        if ( list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        v71.list = nullptr;
        v71.size = 0;
      }
      v71.num = 0;
      p_maxHeight += 5;
      v40 += 16;
    }
    while ( (int)p_maxHeight < (int)"ga" );
    `eh vector destructor iterator'(
      ptr: v74,
      size: 0x10u,
      count: 11,
      pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
  }
  if ( (v72.listStatic == 0 || v72.listStatic == 2) && v72.list != nullptr )
    idMem::Free(this: &mem, ptr: v72.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$230872
// EA  : 0x828C68AC
// RVA : 0x008C68AC
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void _unwind_230872()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 512 + 144));
}


// ========================================================================
// __unwind$230873
// EA  : 0x828C68D4
// RVA : 0x008C68D4
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void _unwind_230873()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(v0 - 512 + 176),
    size: 0x10u,
    count: 11,
    pDtor: (void (__fastcall *)(void *))idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>);
}


// ========================================================================
// __unwind$230874
// EA  : 0x828C690C
// RVA : 0x008C690C
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void _unwind_230874()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 512 + 128));
}


// ========================================================================
// ?Init@idImageManager@@QAAXXZ
// EA  : 0x828C6940
// RVA : 0x008C6940
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __fastcall idImageManager::Init(idImageManager *this)
{
  idImageAtlas *v2; // r3
  idImageAtlas *v3; // r3

  idImageManager::ChangeTextureFilter(this);
  idImageManager::CreateIntrinsicImages(this);
  v2 = (idImageAtlas *)idMem::AllocWithLocation(
                         this: &mem,
                         location: "w:\\tech5\\shared\\idlib\\Heap.h(64) : tag",
                         size: 0x40u,
                         tag: TAG_IMAGE,
                         zeroBuffer: false,
                         align: ALIGN_16,
                         heap: HEAP_DEFAULTHEAP);
  if ( v2 != nullptr )
    v3 = idImageAtlas::idImageAtlas(this: v2, atlasName: "_transSortImageAtlas", sizeLog2: 12);
  else
    v3 = nullptr;
  this->transSortImageAtlas = v3;
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "listImages",
    a3: idImageManager::ListImages_f,
    a4: "lists images",
    a5: nullptr);
  cmdSystem->AddCommand(
    this: cmdSystem,
    a2: "writeImage",
    a3: idImageManager::WriteImage_f,
    a4: "Writes a tga for a given image",
    a5: idCmdSystem::ArgCompletion_ImageName);
}


// ========================================================================
// __unwind$231260
// EA  : 0x828C6A38
// RVA : 0x008C6A38
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void _unwind_231260()
{
  int v0; // r12

  operator delete(p: *(void **)(v0 - 112 + 80), tag: TAG_IMAGE);
}


// ========================================================================
// `dynamic initializer for 'idImageManager::image_useCompression''
// EA  : 0x8334BDA8
// RVA : 0x0134BDA8
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idImageManager::image_useCompression__()
{
  idCVar::idCVar(
    this: &idImageManager::image_useCompression,
    name: "image_useCompression",
    value: "1",
    flags: 1,
    description: "0 = force everything to high quality",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idImageManager::image_useCompression__);
}


// ========================================================================
// `dynamic initializer for 'idImageManager::image_filter''
// EA  : 0x8334BE00
// RVA : 0x0134BE00
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idImageManager::image_filter__()
{
  idCVar::idCVar(
    this: &idImageManager::image_filter,
    name: "image_filter",
    value: imageFilter[1],
    flags: 0x10000,
    description: "changes texture filtering on mipmapped images",
    valueStrings: imageFilter,
    valueCompletion: idCmdSystem::ArgCompletion_String<&char const * * imageFilter>);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idImageManager::image_filter__);
}


// ========================================================================
// `dynamic initializer for 'idImageManager::image_anisotropy''
// EA  : 0x8334BE60
// RVA : 0x0134BE60
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idImageManager::image_anisotropy__()
{
  idCVar::idCVar(
    this: &idImageManager::image_anisotropy,
    name: "image_anisotropy",
    value: "1",
    flags: 0,
    description: "set the maximum texture anisotropy if available",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idImageManager::image_anisotropy__);
}


// ========================================================================
// `dynamic initializer for 'idImageManager::image_lodbias''
// EA  : 0x8334BEB8
// RVA : 0x0134BEB8
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__idImageManager::image_lodbias__()
{
  idCVar::idCVar(
    this: &idImageManager::image_lodbias,
    name: "image_lodbias",
    value: "0",
    flags: 0,
    description: "change lod bias on mipmapped images",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__idImageManager::image_lodbias__);
}


// ========================================================================
// `dynamic initializer for 'CreateTestCube_v''
// EA  : 0x8334BF10
// RVA : 0x0134BF10
// PDB : w:\tech5\engine\renderer\imagemanager.cpp
// ========================================================================

idCommandLink *_dynamic_initializer_for__CreateTestCube_v__()
{
  return idCommandLink::idCommandLink(
           this: &CreateTestCube_v,
           cmdName: "CreateTestCube",
           function: CreateTestCube_f,
           description: "Writes a single pixel sized cube map with different colors on the sides for radiosity validation",
           argCompletion: nullptr);
}

